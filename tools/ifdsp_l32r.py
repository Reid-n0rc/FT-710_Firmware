#!/usr/bin/env python3
"""Heuristic L32R scan of the HiFi4 SRAM image: per function, list literal values loaded.
usage: python3 -I tools/ifdsp_l32r.py <sram_text.bin> <functions.tsv> [filter-substr]"""
import struct, sys, collections
d = open(sys.argv[1], 'rb').read()
BASE = 0x200000
LIT_LO, LIT_HI = 0x206498, 0x236800
ents = []
for line in open(sys.argv[2]):
    f = line.rstrip('\n').split('\t')
    if f[0] == 'entry': continue
    a = int(f[0], 16)
    if BASE <= a < BASE + len(d): ents.append((a, f[1]))
ents.sort()
def lit(a): return struct.unpack_from('<I', d, a - BASE)[0]
out = collections.defaultdict(list)
for i, (a, name) in enumerate(ents):
    end = ents[i + 1][0] if i + 1 < len(ents) else BASE + len(d)
    if a < 0x207000: continue
    for pc in range(a, end - 2):
        b0 = d[pc - BASE]
        if b0 & 0xF != 1: continue
        imm = d[pc - BASE + 1] | d[pc - BASE + 2] << 8
        tgt = ((pc + 3) & ~3) + (((imm | 0xFFFF0000) - (1 << 32)) << 2)
        if LIT_LO <= tgt < LIT_HI:
            out[(a, name)].append((pc, tgt, lit(tgt)))
flt = sys.argv[3] if len(sys.argv) > 3 else None
for (a, name), L in sorted(out.items()):
    vals = sorted(set(v for _, _, v in L))
    s = ' '.join('%08x' % v for v in vals)
    if flt and flt not in s: continue
    print('%08x %-14s %s' % (a, name, s))
