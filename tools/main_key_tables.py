#!/usr/bin/env python3
"""T10b: dump the MAIN front-panel key handler tables (docs/code/main/ui-keys.md).

Usage: python3 -I tools/main_key_tables.py [out.tsv [entries.tsv]]
Reads build/FT-710_MAIN_V0112.bin (base 0xFFF80000) and decomp/main/functions.tsv (relative to the repo root,
override with FT710_ROOT). Prints a summary; with out.tsv writes one row per key code that has a handler; with entries.tsv
also writes every distinct handler (except key_nop) of these and of the two tables after them (0xFFF8E100, 0xFFF8E1A0) and of the alignment table 0xFFF89910 as a
FixFuncEntries row, commented with its codes (#70).
"""
import os
ROOT = os.environ.get('FT710_ROOT', os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import struct, sys
FT = os.path.join(ROOT, 'decomp/main/functions.tsv')
entries = set(l.split('\t')[0] for l in open(FT))
b = open(os.environ.get('FT710_MAIN_BIN', os.path.join(ROOT, 'build/FT-710_MAIN_V0112.bin')), 'rb').read()
base = 0xFFF80000
def u32(a): return struct.unpack('<I', b[a-base:a-base+4])[0]
tabs = [0xFFF89D94, 0xFFF8AB10, 0xFFF8B88C, 0xFFF8C608, 0xFFF8D384]
names = ['press', 'short', 'long', 'repeat', 'release']
tot = set()
for t, n in zip(tabs, names):
    s = set('%x' % u32(t+4*c) for c in range(863)); tot |= s
    print(n, hex(t), len(s), 'not func:', len([x for x in s if x not in entries]))
print('all', len(tot), 'not func', len([x for x in tot if x not in entries]))
a = 0xFFF8E100; vals = []
while a < 0xFFF8E6A0:
    vals.append(u32(a)); a += 4
print(len(vals), hex(min(vals)), hex(max(vals)), len(set(vals)))
print([hex(v) for v in vals[:8]], [hex(v) for v in vals[-6:]])
if len(sys.argv) > 1:
    # TSV dump of non-null codes
    cls = b[0xFFF83164-base:0xFFF83164-base+863]
    NUL = 0xfffc4a8d
    with open(sys.argv[1], 'w') as f:
        f.write('code\tclass\tpress\tshort\tlong\trepeat\trelease\n')
        for c in range(863):
            h = [u32(t+4*c) for t in tabs]
            if any(x != NUL for x in h):
                f.write('0x%03x\t%d\t' % (c, cls[c]) + '\t'.join('-' if x == NUL else '0x%08X' % x for x in h) + '\n')
if len(sys.argv) > 2:
    users = {}
    for t, n in zip(tabs, names):
        for c in range(863):
            x = u32(t+4*c)
            if x != NUL: users.setdefault(x, []).append('%s 0x%03x' % (n, c))
    # Two more JSR tables right after the key tables (#70/#71): key_call_* use 0xFFF8E100 + 0x20*table for the
    # assignable slots 0xD..0x14 (8 entries per table), and FUN_fffe6d7a calls all 296 entries of 0xFFF8E1A0 in turn.
    for c in range(40):
        x = u32(0xFFF8E100 + 4*c)
        if x != NUL: users.setdefault(x, []).append('%s slot 0x%x' % (names[c // 8], 0xD + c % 8))
    for c in range(296):
        users.setdefault(u32(0xFFF8E1A0 + 4*c), []).append('table 0xFFF8E1A0[%d]' % c)
    # ZZPE071000 alignment mode (#76): the DSP key runs entry [0x20CE2] of this 261-entry table (one per calibration byte)
    for c in range(261):
        users.setdefault(u32(0xFFF89910 + 4*c), []).append('align 0xFFF89910[%d]' % c)
    with open(sys.argv[2], 'w') as f:
        f.write('# MAIN handlers from the five key tables 0xFFF89D94.., the slot tables 0xFFF8E100, the table 0xFFF8E1A0 (#70) and the alignment table 0xFFF89910 (#76) (tools/main_key_tables.py); FixFuncEntries.java nolate\n')
        for x in sorted(users):
            u = users[x]
            f.write('%08x\t\t%s\n' % (x, ', '.join(u[:6]) + (', +%d more' % (len(u) - 6) if len(u) > 6 else '')))
