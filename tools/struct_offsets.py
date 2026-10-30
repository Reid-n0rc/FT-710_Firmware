#!/usr/bin/env python3
"""List every field offset and access width of MAIN's big state blocks in the decompile (T23c).

The MAIN decompile reaches its state blocks in two ways:
  * through the eleven `.data` pointer constants 0x25D38..0x25D7C (all = 0x20B04, the UI-state block) and
    0x25D50 (= 0x4659, cfg105): `PTR_DAT_00025d54[0x86]`, `*(undefined2 *)(PTR_DAT_00025d60 + 0x1c0)`,
    `PTR_DAT_00025d38 + 0x36` (an address), `PTR_DAT_00025d6c[uVar8 + 0x40f]` (indexed);
  * by absolute address: `DAT_00020b3a`, `_DAT_00009d53` (wider than a byte), `&DAT_00009d09` (an address),
    `*(ushort *)&DAT_0000xxxx`.
After `ApplyStructs.java` the same accesses print as fields (`PTR_g_ui_00025d54->screensaver_on`, `g_ui.radio_on`); the
`fields` form below counts those.

For every block in BLOCKS this script prints one row per offset: the access widths seen (1/2/4/8, `a` = address taken,
`?` = a wide `_DAT_` access whose width the text does not show), the number of references per form, and the functions
that use it. Record arrays (band stacks, memory channels, QMB) are folded to the offset inside the 0x5A-byte record.

With `--access <tsv>` (the output of `tools/ghidra/StructAccessDump.java`, which reads the widths from the
decompiler's p-code) the rows also get the exact widths (`pcode` column, `size:count`), including the offsets that only
appear inside a wider access.

Usage (python3 -I):
  tools/struct_offsets.py scan <decomp/main> <outdir> [--access access.tsv]
      one TSV per block + summary.tsv (outdir: build/ or scratch)
  tools/struct_offsets.py fields <decomp/main> [header.h]
      count the accesses that print as struct fields (named / neutral f_0x.. / Ghidra field_0x.. or partial) and the
      raw block accesses left (header default: tools/ghidra/structs_main.h)
The output is derived from the firmware decompile and is not committed.
"""
import collections
import glob
import os
import re
import sys

# name, base, size, pointer globals, record size (0 = plain block)
BLOCKS = [
    ('ui_state', 0x20B04, 0x494, [0x25D38, 0x25D4C, 0x25D54, 0x25D58, 0x25D5C, 0x25D60, 0x25D6C, 0x25D70, 0x25D74,
                                  0x25D78, 0x25D7C], 0),
    ('cat_flags', 0x464A, 5, [], 0),
    ('ee_hdr', 0x464F, 10, [], 0),
    ('cfg105', 0x4659, 0x105, [0x25D50], 0),
    ('bandstack_a', 0x4761, 0x438 * 3, [], 0x5A),
    ('bandstack_b', 0x5409, 0x438 * 3, [], 0x5A),
    ('memch', 0x6150, 133 * 0x5A, [], 0x5A),
    ('qmb_hdr', 0x9012, 0x11, [], 0),
    ('qmb', 0x9023, 10 * 0x5A, [], 0x5A),
    ('opstate', 0x9A2A, 0x45C, [], 0),
]

WIDTH = {}
for t in ('undefined1', 'undefined', 'byte', 'char', 'uchar', 'bool', 'int1', 'uint1', 'sbyte', 'int8_t', 'uint8_t'):
    WIDTH[t] = 1
for t in ('undefined2', 'short', 'ushort', 'word', 'int2', 'uint2', 'int16_t', 'uint16_t'):
    WIDTH[t] = 2
for t in ('undefined4', 'int', 'uint', 'long', 'ulong', 'float', 'dword', 'int4', 'uint4', 'int32_t', 'uint32_t',
          'code'):
    WIDTH[t] = 4
for t in ('undefined8', 'longlong', 'ulonglong', 'double', 'qword', 'int8', 'uint8'):
    WIDTH[t] = 8

FUNC_RE = re.compile(r'^// ===== (\S+) @ ([0-9a-f]+)', re.M)
DECL_RE = re.compile(r'^\s+([A-Za-z_]\w*)\s*(\*?)\s*([A-Za-z_]\w*)(?:\s*\[\w*\])?;', re.M)
NUM = r'(0x[0-9a-fA-F]+|\d+)'
PTRNAME = r'PTR_DAT_000([0-9a-f]{5})'


def width_of(t):
    t = t.strip()
    if t.endswith('*'):
        return 4
    return WIDTH.get(t)


def block_of(addr):
    for b in BLOCKS:
        if b[1] <= addr < b[1] + b[2]:
            return b
    return None


def ptr_block(paddr):
    for b in BLOCKS:
        if paddr in b[3]:
            return b
    return None


def split_functions(text):
    ms = list(FUNC_RE.finditer(text))
    for i, m in enumerate(ms):
        end = ms[i + 1].start() if i + 1 < len(ms) else len(text)
        yield m.group(1), int(m.group(2), 16), text[m.end():end]


class Acc:
    def __init__(self):
        self.rows = collections.defaultdict(lambda: {'w': collections.Counter(), 'forms': collections.Counter(),
                                                     'funcs': collections.Counter()})

    def add(self, block, off, width, form, func):
        name, base, size, ptrs, rec = block
        key = (name, off % rec if rec else off)
        r = self.rows[key]
        r['w'][width] += 1
        r['forms'][form] += 1
        r['funcs'][func] += 1


def scan_function(name, body, acc):
    decls = {}
    for m in DECL_RE.finditer(body):
        w = 4 if m.group(2) else width_of(m.group(1))
        if w:
            decls[m.group(3)] = w
    taken = set()

    # 1. *(type *)(PTR + off)
    for m in re.finditer(r'\*\((\w+) \*\)\(' + PTRNAME + r' \+ ' + NUM + r'\)', body):
        b = ptr_block(int(m.group(2), 16))
        if not b:
            continue
        taken.add(m.start(2) - 8)
        acc.add(b, int(m.group(3), 0), width_of(m.group(1)) or '?', 'ptr_cast', name)
    # 2. PTR[off] and PTR[var + off] (byte), *PTR (byte at 0)
    for m in re.finditer(PTRNAME + r'\[(?:(\w+) \+ )?' + NUM + r'\]', body):
        b = ptr_block(int(m.group(1), 16))
        if not b:
            continue
        taken.add(m.start())
        acc.add(b, int(m.group(3), 0), 1, 'ptr_index_var' if m.group(2) else 'ptr_index', name)
    for m in re.finditer(r'(?<![\w)\]])\*' + PTRNAME + r'(?![\w\[])', body):
        b = ptr_block(int(m.group(1), 16))
        if b:
            taken.add(m.start() + 1)
            acc.add(b, 0, 1, 'ptr_deref', name)
    # 3. PTR + off without a cast in front (address taken)
    for m in re.finditer(PTRNAME + r' \+ ' + NUM + r'(?!\w)', body):
        if m.start() in taken:
            continue
        b = ptr_block(int(m.group(1), 16))
        if b:
            acc.add(b, int(m.group(2), 0), 'a', 'ptr_addr', name)
    # 4. absolute DAT_ inside a block
    for m in re.finditer(r'(\*\((\w+) \*\)\s*)?(&)?(_?)DAT_([0-9a-f]{8})(?!\w)', body):
        addr = int(m.group(5), 16)
        b = block_of(addr)
        if not b:
            continue
        off = addr - b[1]
        if m.group(1) and m.group(3):
            w, form = width_of(m.group(2)) or '?', 'abs_cast'
        elif m.group(3):
            w, form = 'a', 'abs_addr'
        elif not m.group(4):
            w, form = 1, 'abs'
        else:
            w, form = guess_width(body, m, decls), 'abs_wide'
        acc.add(b, off, w, form, name)


def guess_width(body, m, decls):
    """Width of a `_DAT_x` access from the statement around it (a cast, a typed variable, a big constant)."""
    s = body.rfind('\n', 0, m.start()) + 1
    e = body.find('\n', m.end())
    line = body[s:e]
    tok = re.escape(m.group(0))
    for pat in (tok + r'\s*=\s*\((\w+)\)', r'\((\w+)\)\s*' + tok):
        mm = re.search(pat, line)
        if mm and width_of(mm.group(1)):
            return width_of(mm.group(1))
    for pat in (tok + r'\s*=\s*(\w+);', r'(\w+)\s*=\s*' + tok + r';', tok + r'\s*[=!<>]=?\s*(\w+)\b'):
        mm = re.search(pat, line)
        if mm:
            v = mm.group(1)
            if v in decls:
                return decls[v]
            if re.fullmatch(r'0x[0-9a-f]+|\d+', v) and int(v, 0) > 0xFFFF:
                return 4
    return '?'


def load_access(path):
    """StructAccessDump rows -> {(block, offset): Counter(size)} and {(block, offset): Counter(function)}."""
    widths = collections.defaultdict(collections.Counter)
    funcs = collections.defaultdict(collections.Counter)
    with open(path, encoding='utf-8') as f:
        for line in f:
            p = line.rstrip('\n').split('\t')
            if len(p) < 6 or p[0] == 'function':
                continue
            if p[1] == 'ptr':
                b = ptr_block(int(p[2], 16))
            else:
                b = block_of(int(p[3], 16))
            addr = int(p[3], 16)
            if not b or not b[1] <= addr < b[1] + b[2]:
                continue
            off = addr - b[1]
            key = (b[0], off % b[4] if b[4] else off)
            widths[key][int(p[4])] += 1
            funcs[key][p[0].split('@')[0]] += 1
    return widths, funcs


def scan(src, outdir, access=None):
    acc = Acc()
    pw, pf = load_access(access) if access else ({}, {})
    for path in sorted(glob.glob(os.path.join(src, '*.c'))):
        with open(path, encoding='utf-8', errors='replace') as f:
            text = f.read()
        for name, addr, body in split_functions(text):
            scan_function(name, body, acc)
    os.makedirs(outdir, exist_ok=True)
    summary = []
    for b in BLOCKS:
        keys = sorted(set(k for k in acc.rows if k[0] == b[0]) | set(k for k in pw if k[0] == b[0]))
        path = os.path.join(outdir, b[0] + '.tsv')
        nref = 0
        with open(path, 'w', encoding='utf-8') as f:
            f.write('# made by tools/struct_offsets.py scan from %s; block %s base 0x%X size 0x%X%s\n'
                    % (src, b[0], b[1], b[2], ' record 0x%X' % b[4] if b[4] else ''))
            f.write('offset\taddress\tpcode\twidths\trefs\tforms\tnfuncs\tfunctions\n')
            for k in keys:
                r = acc.rows[k] if k in acc.rows else {'w': collections.Counter(), 'forms': collections.Counter(),
                                                       'funcs': pf.get(k, collections.Counter())}
                pc = ','.join('%d:%d' % x for x in sorted(pw.get(k, {}).items()))
                n = sum(r['w'].values())
                nref += n
                ws = ','.join('%s:%d' % (w, c) for w, c in sorted(r['w'].items(), key=lambda x: str(x[0])))
                fs = ','.join('%s:%d' % (w, c) for w, c in sorted(r['forms'].items()))
                funcs = ' '.join(fn for fn, _ in r['funcs'].most_common(8))
                f.write('0x%03X\t0x%05X\t%s\t%s\t%d\t%s\t%d\t%s\n'
                        % (k[1], b[1] + k[1], pc or '-', ws or '-', n, fs or '-', len(r['funcs']), funcs))
        summary.append((b[0], len(keys), nref))
    with open(os.path.join(outdir, 'summary.tsv'), 'w', encoding='utf-8') as f:
        f.write('block\toffsets\trefs\n')
        for row in summary:
            f.write('%s\t%d\t%d\n' % row)
    for row in summary:
        print('%-12s %4d offsets %6d refs' % row)


def header_names(path):
    """Field names declared in structs_main.h: named ones and neutral f_0x.. ones."""
    named, neutral = set(), set()
    for line in open(path, encoding='utf-8'):
        m = re.match(r'\s+(?:(?:struct|enum) \w+|\w+)\s*\*?\s*(\w+)(?:\[\d+\])*;\s*/\*\s*\+0x', line)
        if m:
            (neutral if m.group(1).startswith('f_0x') else named).add(m.group(1))
    return named, neutral


def fields(src, header):
    """After ApplyStructs: how many accesses print as struct fields, and how many raw block accesses are left."""
    named, neutral = header_names(header)
    cnt = collections.Counter()
    acc = Acc()
    for path in sorted(glob.glob(os.path.join(src, '*.c'))):
        with open(path, encoding='utf-8', errors='replace') as f:
            text = f.read()
        for name, addr, body in split_functions(text):
            scan_function(name, body, acc)
            # one count per access chain (g_opstate.vfo_a.freq_be[0] counts once), classified by its last member
            for m in re.finditer(r'(?:(?:->|\.)[A-Za-z_]\w*(?:\[[^\]\[]*\])*)+', body):
                n = re.findall(r'(?:->|\.)([A-Za-z_]\w*)', m.group(0))[-1]
                if n in named:
                    cnt['named'] += 1
                elif n in neutral:
                    cnt['neutral'] += 1
                elif n.startswith('field_0x') or re.fullmatch(r'_\d+_\d+_', n):
                    cnt['undefined/partial'] += 1
    raw = collections.Counter()
    for k, r in acc.rows.items():
        raw[k[0]] += sum(r['w'].values())
    print('header %s: %d named fields, %d neutral fields' % (header, len(named), len(neutral)))
    for k in ('named', 'neutral', 'undefined/partial'):
        print('accesses printed as %-18s %6d' % (k + ':', cnt[k]))
    for blk in BLOCKS:
        print('raw accesses left in %-12s %6d' % (blk[0], raw[blk[0]]))
    print('raw accesses left in total        %6d' % sum(raw.values()))


def main(argv):
    if len(argv) >= 4 and argv[1] == 'scan':
        access = argv[argv.index('--access') + 1] if '--access' in argv else None
        scan(argv[2], argv[3], access)
    elif len(argv) >= 3 and argv[1] == 'fields':
        fields(argv[2], argv[3] if len(argv) > 3 else os.path.join(os.path.dirname(__file__), 'ghidra', 'structs_main.h'))
    else:
        print(__doc__)
        return 2
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
