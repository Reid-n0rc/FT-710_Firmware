#!/usr/bin/env python3
"""Structural library matcher for ARM/Thumb images (T23d).

Matches functions compiled from known library sources (ELF .o files) against the functions of a decoded image, without
Ghidra: both sides are disassembled with GNU objdump and compared by

  * the mnemonic sequence (difflib ratio; registers and offsets are ignored, so another compiler version or register
    allocation still matches),
  * the call graph (callees of a reference function vs. the reference names already matched at the image's callees;
    iterated until stable),
  * small immediate constants and the size.

Usage:
  python3 -I tools/lib_match.py match --bin IMAGE.bin --file-off 0x5D428 --vma 0x80000 --end 0x87EBC \
      --funcs decomp/ifdsp/m33/functions.tsv [--arm] --lib "FreeRTOS" --version "V10.3.0" OBJ.o... > out.tsv

  python3 -I tools/lib_match.py veneers --bin IMAGE.bin --file-off 0 --vma 0x08000000 --funcs functions.tsv

  python3 -I tools/lib_match.py totsv [--skip ADDR...] names_IMAGE.lib.tsv > proposal.tsv

Output (names_<image>.lib.tsv): address, name, library, version, method, score, previous, evidence.
`score` is in 0..1; a row is printed when score >= --min (default 0.80) and the match is unique both ways
(no other reference within --margin of the best image function and vice versa). `previous` is the name in
functions.tsv; `evidence` starts with same (agrees), new (was FUN_) or renamed, then sizes, sequence ratio, margin.
`totsv` turns lib TSVs into a names_merge.py proposal (address, name, comment) of the rows that change a name.
Objdump: arm-none-eabi-objdump (apt gcc-arm-none-eabi / binutils-arm-none-eabi) or $OBJDUMP.
"""
import argparse
import difflib
import os
import re
import subprocess
import sys

OBJDUMP = os.environ.get('OBJDUMP', 'arm-none-eabi-objdump')
INS = re.compile(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{4}\s?){1,2}|(?:[0-9a-f]{8}))\s+(\S+)\s*(.*)$')
CALLS = ('bl', 'blx', 'b', 'b.w')


HEADER = '# address\tname\tlibrary\tversion\tmethod\tscore\tprevious\tevidence'


def status(cur, n):
    return 'same' if cur == n else ('new' if cur.startswith('FUN_') or not cur else 'renamed')


def norm_mn(m):
    m = m.lower()
    for s in ('.w', '.n'):
        if m.endswith(s):
            m = m[:-2]
    return m


def imms(ops):
    out = []
    for v in re.findall(r'#(-?(?:0x[0-9a-f]+|\d+))', ops.split('@')[0]):
        try:
            x = int(v, 0)
        except ValueError:
            continue
        if 1 < abs(x) < 0x10000:
            out.append(x)
    return out


def parse_obj(path):
    """Reference functions from an ELF object: name -> dict(mn, calls, imms, size)."""
    out = subprocess.run([OBJDUMP, '-d', '-r', path], capture_output=True, text=True, check=True).stdout
    funcs = {}
    cur = None
    for line in out.splitlines():
        m = re.match(r'^[0-9a-f]+ <([^>]+)>:$', line)
        if m:
            cur = {'mn': [], 'calls': [], 'imms': [], 'size': 0, 'end': 0}
            funcs[m.group(1)] = cur
            continue
        if cur is None:
            continue
        r = re.match(r'^\s*([0-9a-f]+):\s+R_ARM_(THM_CALL|THM_JUMP24|CALL|JUMP24|PC24)\s+(\S+)', line)
        if r:
            cur['calls'].append(re.sub(r'^\.text\.', '', r.group(3).split('+')[0]))
            continue
        m = INS.match(line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        nbytes = len(m.group(2).replace(' ', '')) // 2
        cur['end'] = max(cur['end'], addr + nbytes)
        mn = m.group(3)
        if mn.startswith('.'):          # .word literal
            continue
        cur['mn'].append(norm_mn(mn))
        cur['imms'] += imms(m.group(4))
    for f in funcs.values():
        f['size'] = f.pop('end')
    return funcs


def parse_image(binf, off, vma, end, funcs_tsv, arm):
    data = open(binf, 'rb').read()[off:off + (end - vma)]
    tmp = os.path.join(os.environ.get('TMPDIR', '/tmp'), 'lib_match_%d.bin' % os.getpid())
    open(tmp, 'wb').write(data)
    args = [OBJDUMP, '-D', '-b', 'binary', '-m', 'arm', '--adjust-vma=0x%x' % vma, tmp]
    if not arm:
        args[6:6] = ['-M', 'force-thumb']
    out = subprocess.run(args, capture_output=True, text=True, check=True).stdout
    os.unlink(tmp)
    ins = []
    for line in out.splitlines():
        m = INS.match(line)
        if m:
            a = int(m.group(1), 16)
            ins.append((a, len(m.group(2).replace(' ', '')) // 2, m.group(3), m.group(4)))
    entries = []
    for line in open(funcs_tsv, encoding='utf-8'):
        p = line.rstrip('\n').split('\t')
        if p[0] == 'entry' or len(p) < 3:
            continue
        a, size = int(p[0], 16), int(p[2])
        if vma <= a < end:
            entries.append((a, p[1], size))
    names = {a: n for a, n, s in entries}
    funcs = {}
    j = 0
    ins.sort()
    for a, n, size in sorted(entries):
        while j < len(ins) and ins[j][0] < a:
            j += 1
        body = []
        k = j
        while k < len(ins) and ins[k][0] < a + size:
            body.append(ins[k])
            k += 1
        # literal-pool words referenced by pc-relative loads are data
        lit = set()
        for ia, n_, mn, ops in body:
            lm = re.search(r'@ \(0x([0-9a-f]+)\)', ops)
            if lm and norm_mn(mn).startswith('ldr'):
                la = int(lm.group(1), 16)
                lit.update(range(la, la + (8 if norm_mn(mn) == 'ldrd' else 4)))
        f = {'mn': [], 'calls': [], 'imms': [], 'size': size}
        for ia, nb, mn, ops in body:
            if ia in lit or (ia + nb - 1) in lit:
                continue
            nm = norm_mn(mn)
            if 'UNDEFINED' in ops or nm.startswith('.'):
                continue
            f['mn'].append(nm)
            f['imms'] += imms(ops)
            if nm in ('bl', 'blx') or (nm == 'b' and re.match(r'0x[0-9a-f]+$', ops.strip())):
                tm = re.match(r'(0x[0-9a-f]+)', ops.strip())
                if tm:
                    t = int(tm.group(1), 16)
                    if nm != 'b' or not (a <= t < a + size):
                        f['calls'].append(t)
        funcs[a] = f
    return funcs, names


def score(r, t, cmap):
    if not r['mn'] or not t['mn']:
        return 0.0, 0.0
    lr, lt = len(r['mn']), len(t['mn'])
    if min(lr, lt) / max(lr, lt) < 0.5:
        return 0.0, 0.0
    sm = difflib.SequenceMatcher(None, r['mn'], t['mn'], autojunk=False)
    seq = sm.ratio()
    # callees: reference names vs names already matched at the image callees
    rc = sorted(set(r['calls']))
    tc = sorted(set(cmap.get(x, '?%x' % x) for x in t['calls']))
    if rc or tc:
        calls = len(set(rc) & set(tc)) / max(len(rc), len(tc))
        ncall = 1 - abs(len(r['calls']) - len(t['calls'])) / max(len(r['calls']), len(t['calls']))
    else:
        calls = ncall = 1.0
    ri, ti = set(r['imms']), set(t['imms'])
    imm = len(ri & ti) / max(len(ri | ti), 1) if (ri or ti) else 1.0
    s = 0.55 * seq + 0.2 * calls + 0.1 * ncall + 0.15 * imm
    return s, seq


def match(args):
    ref = {}
    for o in args.objs:
        for n, f in parse_obj(o).items():
            ref.setdefault(n, f)
    img, names = parse_image(args.bin, int(args.file_off, 0), int(args.vma, 0), int(args.end, 0), args.funcs, args.arm)
    # tiny functions (<= 2 instructions) are not distinctive: skip them unless their callers decide
    refn = [n for n, f in ref.items() if len(f['mn']) >= args.min_ins]
    cmap = {}
    accepted = {}
    for it in range(4):
        sc = {}
        for n in refn:
            for a, f in img.items():
                s, seq = score(ref[n], f, cmap)
                if s > 0.5:
                    sc[(n, a)] = (s, seq)
        best_r, best_t = {}, {}
        for (n, a), (s, seq) in sc.items():
            best_r.setdefault(n, []).append((s, a))
            best_t.setdefault(a, []).append((s, n))
        new = {}
        for n, lst in best_r.items():
            lst.sort(reverse=True)
            s, a = lst[0]
            second = lst[1][0] if len(lst) > 1 else 0
            tl = sorted(best_t[a], reverse=True)
            second_t = tl[1][0] if len(tl) > 1 else 0
            if tl[0][1] != n or s < args.min or s - second < args.margin or s - second_t < args.margin:
                continue
            new[a] = (n, s, sc[(n, a)][1], second, second_t)
        accepted = new
        newmap = {a: v[0] for a, v in new.items()}
        if newmap == cmap:
            break
        cmap = newmap
    print('# lib_match.py: %s %s vs %s (%d reference functions, %d image functions, %d matched)'
          % (args.lib, args.version, os.path.basename(args.bin), len(refn), len(img), len(accepted)))
    print(HEADER)
    for a in sorted(accepted):
        n, s, seq, s2, s3 = accepted[a]
        cur = names.get(a, '')
        print('%08x\t%s\t%s\t%s\t%s\t%.3f\t%s\t%s; size %d/%d; seq %.3f; margin %.3f' % (
            a, n, args.lib, args.version, args.method, s, cur, status(cur, n), img[a]['size'], ref[n]['size'], seq,
            s - max(s2, s3)))


VENEER = bytes.fromhex('01b40248844601bc6047')   # push {r0}; ldr r0,[pc,#8]; mov ip,r0; pop {r0}; bx ip


def veneers(args):
    """GNU ld Thumb long-branch stubs (`__<target>_veneer`): the target is the word at entry+12."""
    data = open(args.bin, 'rb').read()
    off, vma = int(args.file_off, 0), int(args.vma, 0)
    names = {}
    rows = []
    for line in open(args.funcs, encoding='utf-8'):
        p = line.rstrip('\n').split('\t')
        if p[0] == 'entry' or len(p) < 3:
            continue
        names[int(p[0], 16)] = p[1]
        rows.append(int(p[0], 16))
    print('# lib_match.py veneers: GNU ld long-branch stubs in %s' % os.path.basename(args.bin))
    print(HEADER)
    for a in rows:
        o = a - vma + off
        if 0 <= o and data[o:o + 10] == VENEER:
            t = int.from_bytes(data[o + 12:o + 16], 'little') & ~1
            tn = names.get(t)
            if tn and not tn.startswith('FUN_'):
                n = '__%s_veneer' % tn
                print('%08x\t%s\tGNU ld\t-\tveneer_pattern\t1.000\t%s\t%s; push {r0}; ldr r0,=0x%08x; mov ip,r0; pop {r0}; bx ip'
                      % (a, n, names[a], status(names[a], n), t | 1))


def totsv(args):
    """names proposal (address, name, comment) from lib TSVs: rows whose name differs from `previous`"""
    print('# T23d library names (generated by tools/lib_match.py totsv from %s); do not edit'
          % ', '.join(os.path.basename(x) for x in args.libs))
    seen = set()
    for f in args.libs:
        for line in open(f, encoding='utf-8'):
            if line.startswith('#') or not line.strip():
                continue
            p = line.rstrip('\n').split('\t')
            a, n, lib, ver, meth, sc, prev = p[:7]
            ev = p[7].split('; ', 1)[1] if len(p) > 7 and '; ' in p[7] else ''
            if n == prev or a in seen or (args.skip and a in args.skip):
                continue
            seen.add(a)
            was = '' if prev.startswith('FUN_') or not prev else '; was %s' % prev
            lv = lib if ver in ('-', '?', '') else '%s %s' % (lib, ver)
            print('%s\t%s\tT23d %s (%s %s): %s%s [%s]' % (a, n, lv, meth, sc, ev, was,
                                                     'fact' if float(sc) >= 0.999 else 'inference'))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    m = sub.add_parser('match')
    m.add_argument('--bin', required=True)
    m.add_argument('--file-off', required=True)
    m.add_argument('--vma', required=True)
    m.add_argument('--end', required=True)
    m.add_argument('--funcs', required=True)
    m.add_argument('--arm', action='store_true', help='A32 instead of Thumb')
    m.add_argument('--lib', default='?')
    m.add_argument('--version', default='?')
    m.add_argument('--method', default='lib_match')
    m.add_argument('--min', type=float, default=0.80)
    m.add_argument('--margin', type=float, default=0.05)
    m.add_argument('--min-ins', type=int, default=3)
    m.add_argument('objs', nargs='+')
    v = sub.add_parser('veneers')
    for k in ('--bin', '--file-off', '--vma', '--funcs'):
        v.add_argument(k, required=True)
    t = sub.add_parser('totsv')
    t.add_argument('--skip', action='append', default=[], help='address to leave out (keeps the existing hand name); repeatable')
    t.add_argument('libs', nargs='+')
    a = ap.parse_args()
    if a.cmd == 'totsv':
        totsv(a)
    elif a.cmd == 'match':
        match(a)
    else:
        veneers(a)


if __name__ == '__main__':
    sys.exit(main())
