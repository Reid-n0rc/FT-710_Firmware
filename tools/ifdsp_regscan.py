#!/usr/bin/env python3
"""python3 -I tools/ifdsp_regscan.py <sram_text.bin> <functions.tsv>: heuristic list of shared register-file words each DSP function
reads (L16UI/L16SI) or writes (S16I) through a base register loaded by L32R with 0x2006ff00 (regs 0..0x7f)
or 0x20077f00 (regs 0x4000..0x407f). Base-ISA encodings only; FLIX bundles are not decoded."""
import struct, sys, collections
d = open(sys.argv[1], 'rb').read()
BASE = 0x200000
BASES = {0x2006ff00: 0, 0x20077f00: 0x4000}
ents = sorted(int(l.split('\t')[0], 16) for l in open(sys.argv[2]) if not l.startswith('entry'))
ents = [a for a in ents if 0x207000 <= a < BASE + len(d)]
res = collections.defaultdict(lambda: collections.defaultdict(set))
for i, a in enumerate(ents):
    end = ents[i + 1] if i + 1 < len(ents) else BASE + len(d)
    regs = {}  # address register -> register-file base
    for pc in range(a, end - 2):
        b0, b1, b2 = d[pc - BASE], d[pc - BASE + 1], d[pc - BASE + 2]
        if b0 & 0xF == 1:  # L32R at, label
            imm = b1 | b2 << 8
            tgt = ((pc + 3) & ~3) + (((imm | 0xFFFF0000) - (1 << 32)) << 2)
            if BASE <= tgt < pc:
                v = struct.unpack_from('<I', d, tgt - BASE)[0]
                if v in BASES: regs[b0 >> 4] = BASES[v]
        elif b0 & 0xF == 2 and (b1 & 0xF) in regs:  # LSAI: r field = b1>>4
            r = b1 >> 4
            if r in (1, 9, 5):
                off = b2 * 2
                if off >= 0x100:
                    reg = regs[b1 & 0xF] + (off - 0x100) // 2
                    res[a]['w' if r == 5 else 'r'].add(reg)
allr = collections.defaultdict(lambda: collections.defaultdict(set))
for a, m in sorted(res.items()):
    for k, s in m.items():
        for reg in s: allr[reg][k].add(a)
for reg in sorted(allr):
    m = allr[reg]
    print('0x%04x r:%-3d w:%-3d  w-by %s' % (reg, len(m['r']), len(m['w']),
          ' '.join('%06x' % x for x in sorted(m['w'])[:6])))
