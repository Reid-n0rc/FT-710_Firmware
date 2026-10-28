"""Scan a HiFi4 objdump (RT600 core config) for register-file accesses.

T12b helper. Produce the input with the Zephyr SDK RT600 HiFi4 objdump (decodes FLIX bundles):
  xtensa-nxp_rt600_adsp_zephyr-elf-objdump -D -b binary -m xtensa --adjust-vma=0x200000 \
    --start-address=0x207220 --stop-address=0x236800 build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin > hifi4_text.dis
usage: python3 -I tools/ifdsp_hifi4_regscan.py hifi4_text.dis decomp/ifdsp/hifi4/functions.tsv 21be80
Output: one line per register: def=<value stored by the defaults function>, then R/W/R8/P (pointer taken)
with the function entries.
Tracks per function the constant held in each aN register (l32r literal, movi, mov),
and reports l16ui/l16si/s16i/l32i/s32i/l8ui/s8i with a base register whose value is in
0x2006FF00..0x2007FFFF. Register index = (base+off-0x20070000)/2 (16-bit words).
Approximate: no control flow, last write wins.
"""
import re, sys
from collections import defaultdict

dis, ftsv = sys.argv[1], sys.argv[2]
deff = int(sys.argv[3], 16) if len(sys.argv) > 3 else None
entries = []
for l in open(ftsv):
    p = l.split('\t')
    if p[0] == 'entry':
        continue
    entries.append(int(p[0], 16))
entries.sort()
import bisect

def func_of(a):
    i = bisect.bisect_right(entries, a) - 1
    return entries[i] if i >= 0 else None

line_re = re.compile(r'^\s*([0-9a-f]+):\s+[0-9a-f]+\s+(.*)$')
ops = []
for l in open(dis):
    m = line_re.match(l)
    if not m:
        continue
    a = int(m.group(1), 16)
    txt = m.group(2).strip()
    if txt.startswith('{'):
        txt = txt.strip('{} ')
    for ins in txt.split(';'):
        ops.append((a, ins.strip()))

LO, HI = 0x2006FF00, 0x20080000
val = {}
cur = None
acc = defaultdict(lambda: defaultdict(set))  # reg -> kind -> set(func)
defaults = {}
for a, ins in ops:
    f = func_of(a)
    if f != cur:
        cur = f
        val = {}
    parts = ins.split(None, 1)
    if not parts:
        continue
    mn = parts[0]
    args = [x.strip() for x in parts[1].split(',')] if len(parts) > 1 else []
    if mn == 'l32r' and len(args) >= 2:
        m = re.search(r'\((0x[0-9a-f]+)\)', parts[1])
        if m:
            val[args[0]] = int(m.group(1), 16)
        continue
    if mn in ('movi', 'movi.n') and len(args) == 2:
        try:
            val[args[0]] = int(args[1], 0) & 0xffffffff
        except ValueError:
            val.pop(args[0], None)
        continue
    if mn in ('mov', 'mov.n') and len(args) == 2:
        if args[1] in val:
            val[args[0]] = val[args[1]]
        else:
            val.pop(args[0], None)
        continue
    if mn in ('addi', 'addi.n', 'addmi') and len(args) == 3 and args[1] in val:
        val[args[0]] = (val[args[1]] + int(args[2], 0)) & 0xffffffff
        continue
    if re.match(r'^(ae_)?[ls](8|16|32)(ui|si|i|ri)?(\.n)?$', mn) and len(args) == 3 and re.match(r'^a\d+$', args[0]):
        if mn.startswith('s') or mn.startswith('ae_s'):
            v = val.get(args[0])
            if v is not None and LO <= v < HI:
                r = (v - 0x20070000) // 2
                acc[r]['P'].add(f)
        base = args[1]
        if base in val and LO <= val[base] < HI:
            addr = val[base] + int(args[2], 0)
            if LO <= addr < HI:
                reg = (addr - 0x20070000) // 2 if addr >= 0x20070000 else None
                kind = 'W' if (mn.startswith('s') or mn.startswith('ae_s')) else 'R'
                key = reg if reg is not None else ('addr', hex(addr))
                acc[key][kind + ('32' if '32' in mn else '8' if '8' in mn else '')].add(f)
                if deff is not None and f == deff and kind == 'W' and reg is not None:
                    defaults[reg] = val.get(args[0])
        if mn.startswith('l') or mn.startswith('ae_l'):
            val.pop(args[0], None)
        continue
    # any other op writing to its first arg: invalidate
    if args and re.match(r'^a\d+$', args[0]):
        val.pop(args[0], None)

def fmt(r):
    return f'0x{r:04X}' if isinstance(r, int) else str(r)

for r in sorted(acc, key=lambda k: (0, k) if isinstance(k, int) else (1, 0)):
    s = []
    for k in sorted(acc[r]):
        s.append(k + ':' + ','.join(f'{x:08X}' for x in sorted(acc[r][k])))
    d = defaults.get(r) if isinstance(r, int) else None
    print(f"{fmt(r)}\tdef={'' if d is None else hex(d)}\t" + '  '.join(s))
