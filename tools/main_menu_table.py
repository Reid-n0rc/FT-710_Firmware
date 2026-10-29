#!/usr/bin/env python3
"""Dump the EX/setup-menu item table of the FT-710 MAIN firmware (V01-12) and optionally diff it
against the CAT manual's MENU chart (Table 2).

The MAIN CPU builds its menu table at run time: `menu_build_all` (FUN_fffd4c30) is a straight list
of BSR calls, one per item. Each callee (`menu_item_<P1>_<P2>_<P3>`) fills a 0x38-byte descriptor on
the stack and passes it to `menu_register` (FUN_fffd442f), which copies it into the RAM table at
0x2105C (350 slots). This tool walks the BSR list and runs a tiny RX emulator over each callee to
recover the descriptor, so nothing is hard-coded per item. See docs/code/main/menu.md.

Defaults: the menu value block (RAM 0x9A2A.., EEPROM 0x53DB.., RAM = EEPROM + 0x464F) is reset from
ROM by FUN_fffb1168's callees. 0x9A2A..0x9BC9 is a linear copy of ROM 0xFFF80E4A.. (preset blocks
are 5 copies of ROM 0xFFF80F4E), with a few destination-dependent overrides that are listed in the
doc, not computed here (MAX POWER, KEYBOARD LANGUAGE, TX TIME OUT TIMER, preset names).

Usage (run with python3 -I):
  python3 -I tools/main_menu_table.py [--image build/FT-710_MAIN_V0112.bin] [--format tsv|md]
          [--diff manual.txt] [--entries entries.tsv] [--names names.tsv]
  --entries writes every distinct on_draw/on_step/on_enter callback as a FixFuncEntries row (none of them is a function
  after analysis: they are only stored in descriptors; #74), --names a names_main.tsv section for them.
  manual.txt = pdftotext -layout -f 10 -l 12 Manuals/FT-710_CAT_OM_ENG_2306-C.pdf manual.txt
Output goes to stdout. Do not commit the output for the raw table; it is derived from firmware.
"""
import argparse
import re
import struct
import sys

BASE = 0xFFF80000
MENU_BUILD_ALL = 0xFFFD4C30   # list of BSRs, one per item
MENU_REGISTER = 0xFFFD442F    # menu_register(desc *)
P1_TITLES = 0xFFF83514        # 6 x 20 chars
P2_TITLES = 0xFFF8358C        # 27 x 13 chars
DEF_RAM, DEF_ROM, DEF_LEN = 0x9A2A, 0xFFF80E4A, 0x1A0
PRESET_RAM, PRESET_ROM, PRESET_LEN = 0x9B2E, 0xFFF80F4E, 0x1F
EEPROM_RAM_OFFSET = 0x464F
# CAT P1 (01..06) -> offset added to CAT P2-1 to get the internal (global) P2 index; see
# FUN_fffe6c27. CAT P1 05 (internal 4) is rejected.
CAT_P2_BASE = {0: 0, 1: 5, 2: 7, 3: 12, 5: 22}
SCALE = {0: '', 1: 'x10', 2: 'x20+20'}
ACCESSOR = {0: 'direct', 1: 'FM RPT SHIFT (VFO)', 2: 'FM ENC/DEC (VFO)', 3: 'FM TONE (VFO)'}


class Image:
    def __init__(self, path):
        self.d = open(path, 'rb').read()

    def u(self, a, n, signed=False):
        o = a - BASE
        return int.from_bytes(self.d[o:o + n], 'little', signed=signed)

    def raw(self, a, n):
        o = a - BASE
        return self.d[o:o + n]


def bsr_list(img, start):
    """Targets of the BSR.W/BSR.A sequence that makes up menu_build_all."""
    a, out = start, []
    while True:
        op = img.u(a, 1)
        if op == 0x39:
            out.append(a + img.u(a + 1, 2, True)); a += 3
        elif op == 0x05:
            out.append(a + img.u(a + 1, 3, True)); a += 4
        elif op == 0x02:      # RTS
            return out
        else:
            raise ValueError(f'unexpected opcode {op:02x} at {a:08x} in menu_build_all')


def emulate_item(img, start, limit=0x200):
    """Run the RX subset used by the item functions until BSR menu_register; return the descriptor."""
    R = [0] * 16
    R[0] = 0x10000
    mem = {}

    def imm(a, li):
        n = (4, 1, 2, 3)[li]
        return img.u(a, n, True), n

    def st(addr, val, n):
        for i in range(n):
            mem[addr + i] = (val >> (8 * i)) & 0xFF

    a = start
    while a < start + limit:
        b, b2 = img.u(a, 1), img.u(a + 1, 1)
        if b in (0x70, 0x71, 0x72, 0x73):                       # ADD #imm, Rs, Rd
            v, n = imm(a + 2, b & 3); R[b2 & 15] = (R[b2 >> 4] + v) & 0xFFFFFFFF; a += 2 + n
        elif b in (0xF8, 0xF9, 0xFA):                            # MOV #imm, dsp[Rd]
            ld, rd, li, sz = b & 3, b2 >> 4, (b2 >> 2) & 3, b2 & 3
            sc, p, dsp = (1, 2, 4)[sz], a + 2, 0
            if ld == 1:
                dsp = img.u(p, 1) * sc; p += 1
            elif ld == 2:
                dsp = img.u(p, 2) * sc; p += 2
            v, n = imm(p, li); st(R[rd] + dsp, v, sc); a = p + n
        elif b in (0x3C, 0x3D, 0x3E):                            # MOV #uimm8, dsp5[Rd]
            sc = (1, 2, 4)[b & 3]
            dsp = (((b2 >> 7) << 4) | (b2 & 15)) * sc
            st(R[(b2 >> 4) & 7] + dsp, img.u(a + 2, 1), sc); a += 3
        elif b == 0x75 and (b2 >> 4) == 4:                       # MOV.L #uimm8, Rd
            R[b2 & 15] = img.u(a + 2, 1); a += 3
        elif b == 0x66:                                          # MOV.L #uimm4, Rd
            R[b2 & 15] = b2 >> 4; a += 2
        elif b == 0xFB:                                          # MOV.L #imm, Rd
            v, n = imm(a + 2, (b2 >> 2) & 3); R[b2 >> 4] = v & 0xFFFFFFFF; a += 2 + n
        elif b == 0x7F and b2 == 0x8F:                           # SMOVF
            for i in range(R[3]):
                mem[R[1] + i] = img.u(R[2] + i, 1) if R[2] >= BASE else 0
            R[1] += R[3]; R[2] += R[3]; R[3] = 0; a += 2
        elif 0x80 <= b <= 0xBF and not (b & 8):                  # MOV.size Rs, dsp5[Rd]
            sc = (1, 2, 4)[(b >> 4) & 3]
            dsp = (((b & 7) << 2) | ((b2 >> 6) & 2) | ((b2 >> 3) & 1)) * sc
            st(R[(b2 >> 4) & 7] + dsp, R[b2 & 7], sc); a += 2
        elif b == 0xEF:                                          # MOV.L Rs, Rd
            R[b2 & 15] = R[b2 >> 4]; a += 2
        elif (b == 0x39 and a + img.u(a + 1, 2, True) == MENU_REGISTER) or \
                (b == 0x05 and a + img.u(a + 1, 3, True) == MENU_REGISTER):   # BSR menu_register
            base = R[1]
            return bytes(mem.get(base + i, 0) for i in range(0x38))
        else:
            raise ValueError(f'unsupported opcode {b:02x} {b2:02x} at {a:08x} (item fn {start:08x})')
    raise ValueError(f'no menu_register call in item fn {start:08x}')


def decode(desc):
    name = desc[6:6 + 21].decode('latin-1').rstrip(' \x00')
    on_draw, on_step, on_enter = struct.unpack_from('<III', desc, 0x1C)
    vmin, vmax = struct.unpack_from('<hh', desc, 0x28)
    store, = struct.unpack_from('<I', desc, 0x2C)
    is_str, is_word, signed, digits, scale, accessor = desc[0x30:0x36]
    return dict(valid=desc[0], dest_mask=desc[1], p1=desc[3], p2=desc[4], p3=desc[5], name=name,
                on_draw=on_draw, on_step=on_step, on_enter=on_enter, min=vmin, max=vmax,
                store=store, is_str=is_str, is_word=is_word, signed=signed, digits=digits,
                scale=scale, accessor=accessor)


def titles(img):
    p1 = [img.raw(P1_TITLES + 20 * i, 20).decode('latin-1').strip() for i in range(6)]
    p2 = [img.raw(P2_TITLES + 13 * i, 13).decode('latin-1').strip() for i in range(27)]
    return p1, p2


def default_of(img, it):
    s = it['store']
    if not s or it['is_str']:
        return None
    if DEF_RAM <= s < DEF_RAM + DEF_LEN:
        rom = DEF_ROM + (s - DEF_RAM)
        if s >= PRESET_RAM:
            rom = PRESET_ROM + (s - PRESET_RAM) % PRESET_LEN
        if it['is_word']:
            return (img.u(rom, 1) << 8) | img.u(rom + 1, 1)     # stored big-endian
        v = img.u(rom, 1)
        return v - 256 if it['signed'] and v >= 128 else v
    return None


def cat_key(it):
    if it['p1'] not in CAT_P2_BASE:
        return None
    return f"{it['p1'] + 1:02d}{it['p2'] - CAT_P2_BASE[it['p1']] + 1:02d}{it['p3'] + 1:02d}"


def cat_value(it, raw):
    if raw is None:
        return None
    return raw * 10 if it['scale'] == 1 else raw * 20 + 20 if it['scale'] == 2 else raw


def cat_digits(it):
    if it['is_str']:
        return 12
    return it['digits'] + (1 if it['signed'] else 0)


def load(img):
    items = []
    for idx, fn in enumerate(bsr_list(img, MENU_BUILD_ALL)):
        it = decode(emulate_item(img, fn))
        it['index'], it['fn'] = idx, fn
        it['default'] = default_of(img, it)
        it['cat'] = cat_key(it)
        items.append(it)
    return items


# ---------------------------------------------------------------- manual (Table 2) parsing
P3_COL = re.compile(r'(?<!\S)(\d\d) {2,4}(?=[A-Z0-9])')


def norm(s):
    return re.sub(r'[^A-Z0-9]', '', s.upper())


def parse_manual(path, fw_names):
    """Return a list of groups; each group is a list of [p3, text, digits] in chart order.

    The chart's P3 column starts at text column ~36 in `pdftotext -layout` output; P1/P2 labels
    sit to the left of it on arbitrary lines, so groups are split where P3 restarts at 01."""
    groups, cur, inside = [], None, False
    for line in open(path, encoding='utf-8', errors='replace'):
        line = line.rstrip('\n')
        if 'Table 2 (MENU Chart)' in line:
            inside = True
            continue
        if inside and re.match(r'^[A-Z]{2}\s{3,}\S', line):    # next command (FA ...) ends the chart
            break
        if not inside:
            continue
        m = None
        for mm in P3_COL.finditer(line):
            if 32 <= mm.start() <= 42:
                m = mm
                break
        if not m:
            # continuation lines may carry the Digits column (e.g. MIC P1..MIC DOWN share one "2")
            mm = re.search(r'\s{3,}(\d{1,2})\s*$', line)
            if mm and cur and cur[-1][2] is None:
                cur[-1][2] = int(mm.group(1))
            continue
        p3, rest = int(m.group(1)), line[m.end():].strip()
        dg = re.search(r'\s{3,}(\d{1,2})$', rest)
        digits = int(dg.group(1)) if dg else None
        if dg:
            rest = rest[:dg.start()]
        if p3 == 1 or cur is None:
            cur = []
            groups.append(cur)
        cur.append([p3, rest.strip(), digits])
    # MIC P1..MIC DOWN rows: one shared "2" in the chart
    for g in groups:
        for r in g:
            if r[2] is None and norm(r[1]).startswith('MIC'):
                r[2] = 2
    return groups


def split_name(text, fw_name):
    """Split a manual row into (function name, P4 text) using the firmware name as a hint."""
    n = norm(fw_name)
    acc = ''
    for i, ch in enumerate(text):
        acc += re.sub(r'[^A-Z0-9]', '', ch.upper())
        if acc == n:
            return text[:i + 1].strip(), text[i + 1:].strip()
    m = re.match(r'(.*?)\s{2,}(.*)$', text)
    return (m.group(1), m.group(2)) if m else (text, '')


def manual_range(p4):
    """Best-effort numeric range of the CAT P4 value from the chart text."""
    m = re.search(r'P4\s*=\s*([-+]?\d+)\s*-\s*(?:[-+]00 or [-+]00 - )?([-+]?\d+)', p4)
    if m:
        return int(m.group(1)), int(m.group(2))
    codes = [int(x) for x in re.findall(r'(?:^|\s)(\d{1,2})\s?:', p4)]
    if codes:
        return min(codes), max(codes)
    m = re.match(r'\s*(\d+)\s*-\s*(\d+)', p4)
    if m:
        return int(m.group(1)), int(m.group(2))
    return None


def diff(items, path, out):
    vis = [it for it in items if it['cat']]
    fw_groups = []
    for it in vis:
        if not fw_groups or (fw_groups[-1][0]['p1'], fw_groups[-1][0]['p2']) != (it['p1'], it['p2']):
            fw_groups.append([])
        fw_groups[-1].append(it)
    man = parse_manual(path, [it['name'] for it in vis])
    # The chart prints the PRESET table once for P2 = 01..05
    if len(man) == len(fw_groups) - 4:
        man = man + [man[-1]] * 4
    out.write('# key\tfirmware name\tmanual name\tfw CAT range\tmanual range\tfw digits\tmanual digits\tnote\n')
    for fg, mg in zip(fw_groups, man):
        for i in range(max(len(fg), len(mg))):
            it = fg[i] if i < len(fg) else None
            row = mg[i] if i < len(mg) else None
            if it is None:
                out.write(f'-\t-\t{row[1]}\t-\t-\t-\t{row[2]}\tMANUAL ONLY\n'); continue
            if row is None:
                out.write(f"{it['cat']}\t{it['name']}\t-\t-\t-\t{cat_digits(it)}\t-\tFIRMWARE ONLY\n"); continue
            mname, p4 = split_name(row[1], it['name'])
            fr = None if it['is_str'] else (cat_value(it, it['min']), cat_value(it, it['max']))
            mr = None if it['is_str'] else manual_range(p4)
            notes = []
            if norm(mname) != norm(it['name']):
                notes.append('name')
            if fr and mr and fr != mr:
                notes.append('range')
            if row[2] is not None and row[2] != cat_digits(it):
                notes.append('digits')
            out.write(f"{it['cat']}\t{it['name']}\t{mname}\t{fr}\t{mr}\t{cat_digits(it)}\t{row[2]}\t{','.join(notes)}\n")
    if len(man) != len(fw_groups):
        out.write(f'# group count differs: firmware {len(fw_groups)}, manual {len(man)}\n')
    hidden = [it for it in items if not it['cat']]
    out.write(f'# {len(hidden)} items not reachable by EX (internal P1 4 = CAT 05):\n')
    for it in hidden:
        out.write(f"#   {it['p1']}.{it['p2']}.{it['p3']} {it['name']} dest_mask={it['dest_mask']:#x} on_enter={it['on_enter']:08x}\n")


def callbacks(img, items, entries, names):
    """Each callback address with its users; named after the first item that uses it, or menu_<role>_nop for a bare RTS (#74)."""
    users = {}
    for it in items:
        key = f"ex{it['cat']}" if it['cat'] else f"m{it['p1']}_{it['p2']}_{it['p3']}"
        for role in ('draw', 'step', 'enter'):
            users.setdefault(it['on_' + role], []).append((role, key, it['name'].strip()))
    if entries:
        with open(entries, 'w') as f:
            f.write('# MAIN menu item callbacks on_draw/on_step/on_enter from the 314 descriptors '
                    '(tools/main_menu_table.py --entries, #74); FixFuncEntries.java nolate\n')
            for x in sorted(users):
                u = users[x]
                f.write(f"{x:08x}\t\t" + ', '.join(f'{r} {k}' for r, k, _ in u[:4])
                        + (f', +{len(u) - 4} more' if len(u) > 4 else '') + '\n')
    if names:
        with open(names, 'w') as f:
            for x in sorted(users):
                u = users[x]
                role, key, name = u[0]
                if img.u(x, 1) == 0x02 and len(u) > 1:   # a bare RTS shared by several items
                    f.write(f"{x:08x}\tmenu_{role}_nop\tEmpty menu on_{role} (RTS), shared by {len(u)} items (#74)\n")
                    continue
                more = f"; also {', '.join(k for _, k, _ in u[1:])}" if len(u) > 1 else ''
                f.write(f"{x:08x}\tmenu_{key}_{role}\tMenu item {key} {name}: on_{role}{more} (#74)\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--image', default='build/FT-710_MAIN_V0112.bin')
    ap.add_argument('--format', choices=('tsv', 'md'), default='tsv')
    ap.add_argument('--diff', metavar='MANUAL_TXT', help='pdftotext -layout output of Table 2')
    ap.add_argument('--entries', metavar='TSV', help='write the callbacks as FixFuncEntries rows')
    ap.add_argument('--names', metavar='TSV', help='write names for the callbacks (names_main.tsv rows)')
    a = ap.parse_args()
    img = Image(a.image)
    items = load(img)
    if a.entries or a.names:
        callbacks(img, items, a.entries, a.names)
        return
    if a.diff:
        diff(items, a.diff, sys.stdout)
        return
    p1t, p2t = titles(img)
    cols = ['idx', 'P1.P2.P3', 'EX key', 'group', 'name', 'min', 'max', 'default', 'CAT min..max',
            'CAT digits', 'kind', 'RAM', 'EEPROM', 'dest_mask', 'on_draw', 'on_step', 'on_enter', 'item fn']
    if a.format == 'md':
        print('| ' + ' | '.join(cols) + ' |')
        print('|' + '---|' * len(cols))
    else:
        print('\t'.join(cols))
    for it in items:
        kind = 'string12' if it['is_str'] else ('u16' if it['is_word'] else ('s8' if it['signed'] else 'u8'))
        if it['scale']:
            kind += ' ' + SCALE.get(it['scale'], f"scale{it['scale']}")
        if it['accessor']:
            kind += ' via ' + ACCESSOR.get(it['accessor'], str(it['accessor']))
        rng = '' if it['is_str'] else f"{cat_value(it, it['min'])}..{cat_value(it, it['max'])}"
        row = [it['index'], f"{it['p1']}.{it['p2']}.{it['p3']}", it['cat'] or '-',
               f"{p1t[it['p1']]} / {p2t[it['p2']]}", it['name'], it['min'], it['max'],
               '' if it['default'] is None else it['default'], rng if it['cat'] else '-',
               cat_digits(it) if it['cat'] else '-', kind,
               f"{it['store']:#06x}" if it['store'] else '-',
               f"{it['store'] - EEPROM_RAM_OFFSET:#06x}" if it['store'] else '-',
               f"{it['dest_mask']:#x}", f"{it['on_draw']:08x}", f"{it['on_step']:08x}",
               f"{it['on_enter']:08x}", f"{it['fn']:08x}"]
        row = [str(x) for x in row]
        print(('| ' + ' | '.join(row) + ' |') if a.format == 'md' else '\t'.join(row))


if __name__ == '__main__':
    main()
