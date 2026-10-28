#!/usr/bin/env python3
"""Independent HiFi4 decoder checks (T22c, #104): flix.dis and Ghidra's Xtensa:LE:32:rt600hifi4 against a third decoder.

The decoder is tools/hifi4_isa_decode.c, compiled with Cadence's xtensa-modules.c (the RT600 HiFi4 tables). It uses the
tables and generated functions of that file only (format_decoder, slot get, opcode decode, field get, operand
decode/undo_reloc, iclass in/out); the driver code is written here, not GNU libisa, and nothing is shared with T21a's
SLEIGH generator. So it checks objdump's libisa driver and Ghidra's generated SLEIGH against the tables.

usage: python3 -I tools/hifi4_hand_decode.py <command> [args]   (env: see DEFAULTS below)
  build                           compile tools/hifi4_isa_decode.c into $HD_BIN
  flix                            decode every flix.dis address and compare with flix.dis (tests this decoder)
  ghidra EXPORT.tsv               compare an ExportListing.java TSV (addr len mnemonic operands bytes) with this decoder
  sample N EXPORT.tsv OUT.tsv     N bundles with different format / slot-opcode mixes, field by field, vs flix.dis and
                                  Ghidra; OUT.tsv gets the full slot breakdown
  parallel N OUT.tsv              N bundles in which one slot writes a register that another slot reads
  regions MISMATCHES LISTING OUT  settle the listing-mode conflict regions of tools/flix_compare.py (rows "missing ...
                                  inside", grouped with an 8-byte gap) with an own recursive-descent flow decode and with
                                  objdump run at Ghidra's instruction starts; one verdict row per region in OUT
Normalisation for comparisons: case; `(0x...)` literal comments and `; name` call comments dropped; integers by value
modulo 2^32; bundles split into slots at `;`; `rsr.X a` == `rsr a, X` (also wsr/xsr/rur/wur); `mov a, b` == `or a, b, b`.
"""
import os
import re
import subprocess
import sys
from collections import Counter, defaultdict

SP = '/tmp/claude-1100/-workspace-FT-710-Firmware/8424cd5a-b034-46b5-9643-3a02b2614deb/scratchpad/t22c'
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULTS = {
    'HD_BIN': os.path.join(SP, 'hifi4_isa_decode'),
    'HD_MODULES': os.path.expanduser('~/opt/dl/xtensa-modules.c'),
    'HD_INCLUDE': os.path.join(SP, 'hdr/binutils-2.47/include'),  # xtensa-isa.h, xtensa-isa-internal.h, ansidecl.h
    'HD_IMAGE': '/workspace/FT-710_Firmware/build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin',
    'HD_OBJDUMP': os.path.expanduser('~/opt/zephyr-sdk-0.17.0/xtensa-nxp_rt600_adsp_zephyr-elf/bin/'
                                     'xtensa-nxp_rt600_adsp_zephyr-elf-objdump'),
    'HD_FLIX': os.path.join(ROOT, 'decomp/ifdsp/hifi4/flix.dis'),
    'HD_ENTRIES': os.path.join(ROOT, 'tools/ghidra/entries_hifi4.tsv'),
}
ENV = {k: os.environ.get(k, v) for k, v in DEFAULTS.items()}
BASE = 0x200000
LINE = re.compile(r'^\s+([0-9a-f]+):\t([0-9a-f]+)\s*\t(.*)$')
NUM = re.compile(r'^[-+]?(0x[0-9a-f]+|\d+)$')
NOFALL = {'j', 'jx', 'ret', 'retw', 'ret.n', 'retw.n', 'rfe', 'rfi', 'rfde', 'rfwo', 'rfwu', 'rfdo', 'rfdd', 'rfme',
          'ill', 'ill.n'}


# ---------------------------------------------------------------- decoder
def build():
    cmd = ['gcc', '-O1', '-w', '-I' + ENV['HD_INCLUDE'], '-DXTENSA_MODULES_C="%s"' % ENV['HD_MODULES'],
           '-o', ENV['HD_BIN'], os.path.join(ROOT, 'tools/hifi4_isa_decode.c')]
    subprocess.run(cmd, check=True)


def decode(addrs=None):
    """addr -> dict(len, fmt, flags, targets, text, slots); addrs=None decodes at every byte offset."""
    if not os.path.exists(ENV['HD_BIN']):
        build()
    args = [ENV['HD_BIN'], ENV['HD_IMAGE'], hex(BASE)] + (['all'] if addrs is None else [])
    inp = None if addrs is None else ''.join('%x\n' % a for a in addrs)
    p = subprocess.run(args, input=inp, capture_output=True, text=True, check=True)
    out = {}
    for ln in p.stdout.splitlines():
        f = ln.split('\t')
        a = int(f[0], 16)
        slots = []
        for s in f[6].split(' ;; ') if f[6] else []:
            parts = s.split(' ')
            sname, opc, word = parts[0].split('|')[:3]
            ops = []
            for t in parts[1:]:
                if not t:
                    continue
                if t.startswith('state:'):
                    _, st, io = t.split(':')
                    ops.append(('state', st, None, st, io))
                    continue
                name, rest = t.split('=', 1)
                bits = rest.split(':')
                if bits[0] == 'implicit':
                    ops.append((name, None, None, None, bits[1]))
                else:
                    ops.append((name, int(bits[0]), bits[1], bits[1], bits[2]))
            slots.append({'slot': sname, 'op': opc, 'word': word, 'ops': ops})
        out[a] = {'len': int(f[1]), 'fmt': f[2], 'flags': f[3],
                  'targets': [int(x, 16) for x in f[4].split(',') if x], 'text': f[5], 'slots': slots}
    return out


# ---------------------------------------------------------------- text normalisation
def num(t):
    t = t.strip()
    if NUM.match(t):
        return int(t, 0) & 0xffffffff
    return t


def norm_slot(s):
    s = re.sub(r'\s*\(0x[0-9a-f]+\)', '', s.strip().lower())
    parts = s.split(None, 1)
    if not parts:
        return ('',)
    m, ops = parts[0], [num(x) for x in parts[1].split(',')] if len(parts) > 1 else []
    ops = [o for o in ops if o != '']
    if m in ('rsr', 'wsr', 'xsr', 'rur', 'wur') and len(ops) == 2 and isinstance(ops[1], str):
        m, ops = m + '.' + ops[1], ops[:1]
    if m == 'or' and len(ops) == 3 and ops[1] == ops[2]:
        m, ops = 'mov', ops[:2]
    return (m,) + tuple(ops)


def norm(text):
    t = text.strip().lower()
    if t.startswith('{'):
        t = t.strip('{} ')
        return tuple(norm_slot(s) for s in t.split(';'))
    t = re.sub(r'\s+;.*$', '', t)
    return (norm_slot(t),)


def parse_flix():
    ins, pad, funcs = [], set(), []
    for ln in open(ENV['HD_FLIX'], encoding='utf-8'):
        if ln.startswith(';; ----'):
            funcs.append(int(ln.split()[2], 16))
            continue
        m = LINE.match(ln.rstrip('\n'))
        if not m:
            continue
        a, hx, text = int(m.group(1), 16), m.group(2), m.group(3).replace('\t', ' ').strip()
        if text.startswith('.byte'):
            pad.add(a)
            continue
        ins.append((a, len(hx) // 2, hx, text))
    return ins, pad, funcs


def read_export(path):
    rows = {}
    for ln in open(path, encoding='utf-8'):
        f = ln.rstrip('\n').split('\t')
        if f[0] == 'addr' or len(f) < 4:
            continue
        rows[int(f[0], 16)] = (int(f[1]), (f[2] + ' ' + f[3]).strip(), f[4] if len(f) > 4 else '')
    return rows


# ---------------------------------------------------------------- commands
def cmd_flix():
    ins, _, _ = parse_flix()
    d = decode([a for a, *_ in ins])
    c, bad = Counter(), []
    for a, n, hx, text in ins:
        r = d.get(a)
        if r is None or abs(r['len']) != n:
            c['length'] += 1
            bad.append((a, text, r and r['text']))
        elif norm(r['text']) != norm(text):
            c['text'] += 1
            bad.append((a, text, r['text']))
        else:
            c['agree'] += 1
    print('flix.dis instructions: %d; agree %d, length %d, text %d' % (len(ins), c['agree'], c['length'], c['text']))
    for b in bad[:40]:
        print('  %x\n    flix  %s\n    hand  %s' % b)
    return 0 if not bad else 1


def cmd_ghidra(path):
    g = read_export(path)
    addrs = [a for a in g if BASE <= a < BASE + os.path.getsize(ENV['HD_IMAGE'])]
    d = decode(addrs)
    c, bad = Counter(), defaultdict(list)
    for a in sorted(addrs):
        n, text, _ = g[a]
        r = d[a]
        if abs(r['len']) != n:
            k = 'length'
        elif norm(r['text']) != norm(text):
            k = 'text'
        else:
            k = 'agree'
        c[k] += 1
        if k != 'agree':
            key = norm(r['text'])[0][0] if norm(r['text']) else '?'
            bad[key].append((a, text, r['text']))
    print('Ghidra instructions in the SRAM image: %d; agree %d, length %d, text %d'
          % (len(addrs), c['agree'], c['length'], c['text']))
    for k, v in sorted(bad.items(), key=lambda kv: -len(kv[1])):
        print('  %-20s %5d  e.g. %x  ghidra: %s  |  hand: %s' % (k, len(v), v[0][0], v[0][1], v[0][2]))
    return c


def slot_regs(slot):
    """(reads, writes) as sets of register names, from the iclass in/out of each operand (register operands only)."""
    rd, wr = set(), set()
    for name, raw, val, txt, io in slot['ops']:
        if name == 'state':
            (rd if io in 'im' else set()).add('state:' + txt)
            if io in 'om':
                wr.add('state:' + txt)
            continue
        if txt is None or not re.match(r'^(a|aed|b|u|aep|m)\d', txt):
            continue
        regs = txt.split(':')
        if io in 'im':
            rd.update(regs)
        if io in 'om':
            wr.update(regs)
    return rd, wr


def cmd_sample(n, path, outp):
    ins, _, _ = parse_flix()
    flix = {a: (ln, text) for a, ln, hx, text in ins}
    bund = [a for a, ln, hx, text in ins if text.startswith('{')]
    d = decode(bund)
    g = read_export(path) if path != '-' else {}
    # greedy: cover every (format, slot-opcode tuple) class, preferring new formats, then new opcodes
    seen_fmt, seen_op, seen_mix, pick = Counter(), set(), set(), []
    cands = sorted(bund, key=lambda a: (a * 2654435761) & 0xffffffff)  # deterministic shuffle
    while len(pick) < n:
        best, bs = None, None
        for a in cands:
            if a in pick:
                continue
            r = d[a]
            mix = (r['fmt'],) + tuple(s['op'] for s in r['slots'])
            if mix in seen_mix:
                continue
            score = (-seen_fmt[r['fmt']], sum(1 for s in r['slots'] if s['op'] not in seen_op),
                     sum(1 for s in r['slots'] if s['op'] != 'nop'))
            if bs is None or score > bs:
                best, bs = a, score
        if best is None:
            break
        r = d[best]
        pick.append(best)
        seen_fmt[r['fmt']] += 1
        seen_op.update(s['op'] for s in r['slots'])
        seen_mix.add((r['fmt'],) + tuple(s['op'] for s in r['slots']))
    img = open(ENV['HD_IMAGE'], 'rb').read()
    c = Counter()
    with open(outp, 'w', encoding='utf-8') as out:
        out.write('addr\tbytes\tformat\tslot\tslot_bits\topcode\toperands(name=field:value:io)\thand\tflix\tghidra\tverdict\n')
        for a in sorted(pick):
            r = d[a]
            ln = abs(r['len'])
            hx = img[a - BASE:a - BASE + ln].hex()
            ft = flix[a][1]
            gt = g.get(a, (0, '(none)', ''))[1]
            vf = norm(r['text']) == norm(ft)
            vg = norm(r['text']) == norm(gt) and g.get(a, (0,))[0] == ln
            v = 'both' if vf and vg else 'flix-only' if vf else 'ghidra-only' if vg else 'neither'
            c[v] += 1
            for i, s in enumerate(r['slots']):
                ops = ' '.join('%s=%s:%s:%s' % (o[0], o[1], o[2], o[4]) for o in s['ops'] if o[0] != 'state')
                out.write('%x\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' % (
                    a, hx if i == 0 else '', r['fmt'] if i == 0 else '', s['slot'], s['word'], s['op'], ops,
                    r['text'] if i == 0 else '', ft if i == 0 else '', gt if i == 0 else '', v if i == 0 else ''))
            print('%x %-14s %-4s %s\n      ghidra %s' % (a, r['fmt'], v, r['text'], gt))
    fm = Counter(d[a]['fmt'] for a in pick)
    print('picked %d bundles; formats %s; distinct slot opcodes %d; verdicts %s'
          % (len(pick), dict(fm), len({s['op'] for a in pick for s in d[a]['slots']}), dict(c)))


def cmd_parallel(n, outp):
    ins, _, _ = parse_flix()
    bund = [a for a, ln, hx, text in ins if text.startswith('{')]
    d = decode(bund)
    hits = []
    for a in bund:
        r = d[a]
        rw = [slot_regs(s) for s in r['slots']]
        dep = []
        for i, (_, wi) in enumerate(rw):
            for j, (rj, _) in enumerate(rw):
                if i != j:
                    for reg in sorted((wi & rj) - {x for x in wi if x.startswith('state:')}):
                        dep.append((i, j, reg))
        if dep:
            hits.append((a, dep))
    # prefer variety: different (writer opcode, reader opcode) pairs, and some where the writer is the earlier slot
    kinds, pick = set(), []
    for a, dep in sorted(hits, key=lambda h: (h[0] * 2654435761) & 0xffffffff):
        r = d[a]
        k = tuple(sorted((r['slots'][i]['op'], r['slots'][j]['op']) for i, j, _ in dep))
        if k in kinds:
            continue
        kinds.add(k)
        pick.append((a, dep))
        if len(pick) >= n:
            break
    with open(outp, 'w', encoding='utf-8') as out:
        out.write('addr\tformat\ttext\twriter_slot\treader_slot\tregister\n')
        for a, dep in sorted(pick):
            r = d[a]
            for i, j, reg in dep:
                out.write('%x\t%s\t%s\t%d:%s\t%d:%s\t%s\n' % (a, r['fmt'], r['text'], i, r['slots'][i]['op'],
                                                             j, r['slots'][j]['op'], reg))
            print('%x %s  %s' % (a, r['text'], ', '.join('slot%d(%s) writes %s read by slot%d(%s)' % (
                i, r['slots'][i]['op'], reg, j, r['slots'][j]['op']) for i, j, reg in dep)))
    print('bundles with a cross-slot write->read: %d of %d' % (len(hits), len(bund)))


def flow(dec, roots):
    """Recursive descent over the hand decoder's table: instruction starts reached from roots."""
    seen, work = set(), list(roots)
    lo, hi = BASE, BASE + os.path.getsize(ENV['HD_IMAGE'])
    while work:
        a = work.pop()
        while lo <= a < hi and a not in seen:
            r = dec.get(a)
            if r is None or r['len'] <= 0:
                break
            seen.add(a)
            ops = {s['op'] for s in r['slots']}
            for s in r['slots']:  # PC-relative operands are printed 0x...; l32r's is a literal address, not code
                if s['op'] != 'l32r':
                    work.extend(int(o[2], 16) for o in s['ops'] if o[2] and o[2].startswith('0x'))
            if ops & NOFALL:
                break
            a += r['len']
    return seen


def objdump_at(addrs, lens):
    out = {}
    od = ENV['HD_OBJDUMP']
    for a in addrs:
        p = subprocess.run([od, '-D', '-b', 'binary', '-m', 'xtensa', '--adjust-vma=0x%x' % BASE,
                            '--start-address=0x%x' % a, '--stop-address=0x%x' % (a + lens[a]), ENV['HD_IMAGE']],
                           capture_output=True, text=True)
        for ln in p.stdout.splitlines():
            m = LINE.match(ln)
            if m and int(m.group(1), 16) == a:
                out[a] = m.group(3).replace('\t', ' ').strip()
    return out


def cmd_regions(mism, listing, outp):
    ins, pad, funcs = parse_flix()
    F = {a: (n, t) for a, n, hx, t in ins}
    G = read_export(listing)
    rows = [l.rstrip('\n').split('\t') for l in open(mism, encoding='utf-8')][1:]
    inside = sorted(int(r[2], 16) for r in rows if r[1] == 'missing' and 'inside' in r[8])
    regs = []
    for a in inside:
        if regs and a - regs[-1][1] <= 8:
            regs[-1][1] = a
        else:
            regs.append([a, a])
    dec = decode()
    roots = set(funcs)
    for ln in open(ENV['HD_ENTRIES'], encoding='utf-8'):
        f = ln.split('\t')
        if f[0] != 'entry':
            roots.add(int(f[0], 16))
    reach = flow(dec, roots)
    gstarts = sorted(a for a in G if BASE <= a < BASE + os.path.getsize(ENV['HD_IMAGE']))
    need_od = set()
    for lo, hi in regs:
        for a in gstarts:
            if lo - 12 <= a <= hi + 12 and a not in F:
                need_od.add(a)
    od = objdump_at(sorted(need_od), {a: G[a][0] for a in need_od})
    verdicts = Counter()
    nrow = Counter()
    with open(outp, 'w', encoding='utf-8') as out:
        out.write('region_lo\tregion_hi\tflix_rows\tverdict\tnear_padding\tflix_only_starts\tghidra_only_starts\t'
                  'reached_flix_only\treached_ghidra_only\tghidra_decode_check\tdetail\n')
        for lo, hi in regs:
            w0, w1 = lo - 12, hi + 12
            fs = {a for a in F if w0 <= a <= w1}
            gs = {a for a in gstarts if w0 <= a <= w1}
            fo, go = sorted(fs - gs), sorted(gs - fs)
            rf = [a for a in fo if a in reach]
            rg = [a for a in go if a in reach]
            if rg and not rf:
                v = 'ghidra'
            elif rf and not rg:
                v = 'flix'
            elif not rf and not rg:
                v = 'unreached'
            else:
                v = 'mixed'
            # does Ghidra decode its own starts like objdump and the hand decoder?
            chk = Counter()
            ex = ''
            for a in go:
                gn, gt, _ = G[a]
                h = dec.get(a)
                okh = h is not None and abs(h['len']) == gn and norm(h['text']) == norm(gt)
                oko = a in od and norm(od[a]) == norm(gt)
                chk['ok' if okh and oko else 'hand' if okh else 'objdump' if oko else 'bad'] += 1
                if not (okh and oko) and not ex:
                    ex = '%x ghidra "%s" hand "%s" objdump "%s"' % (a, gt, h and h['text'], od.get(a))
            near = any(lo - 8 <= p <= hi + 8 for p in pad) or any(
                F[a][1].strip() in ('ill',) for a in fs)
            n = sum(1 for a in inside if lo <= a <= hi)
            verdicts[v] += 1
            nrow[v] += n
            out.write('%x\t%x\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' % (
                lo, hi, n, v, 'yes' if near else 'no', ','.join('%x' % a for a in fo), ','.join('%x' % a for a in go),
                ','.join('%x' % a for a in rf), ','.join('%x' % a for a in rg),
                ' '.join('%s=%d' % kv for kv in sorted(chk.items())), ex))
    print('regions %d (%d flix rows): %s; rows %s' % (len(regs), len(inside), dict(verdicts), dict(nrow)))
    print('hand-decoder flow reaches %d instruction starts' % len(reach))


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    c = argv[1]
    if c == 'build':
        build()
    elif c == 'flix':
        return cmd_flix()
    elif c == 'ghidra':
        cmd_ghidra(argv[2])
    elif c == 'sample':
        cmd_sample(int(argv[2]), argv[3], argv[4])
    elif c == 'parallel':
        cmd_parallel(int(argv[2]), argv[3])
    elif c == 'regions':
        cmd_regions(argv[2], argv[3], argv[4])
    else:
        print(__doc__)
        return 2
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
