#!/usr/bin/env python3
"""Per-function disassembly of the IFDSP HiFi4 SRAM image with a FLIX-aware objdump (T12e).

Ghidra's Xtensa module decodes the base ISA only. The Zephyr SDK toolchain for the NXP RT600 ADSP
(`xtensa-nxp_rt600_adsp_zephyr-elf`, binutils 2.38 built with the RT600 HiFi4 core overlay) decodes the
HiFi4 FLIX bundles and HiFi4 opcodes of this image. A linear sweep desynchronises at literal pools and
padding, so this script disassembles each function separately (entry to next entry). Entries are the
functions.tsv entries that start with an `entry` instruction (Ghidra also made ~57 bogus mid-function
entries, which are dropped) plus every call target that starts with `entry` (functions Ghidra missed),
found by iterating. It puts names from IfdspHifi4Names.java (if given) on the headers and on call targets, and lists
call targets that are not known function entries.

usage: python3 -I tools/ifdsp_hifi4_dis.py <objdump> <sram_text.bin> <functions.tsv> <out.dis> [IfdspHifi4Names.java]
"""
import re, subprocess, sys

BASE = 0x200000
TEXT_LO, TEXT_HI = 0x207000, 0x236800


def main():
    od, binf, tsv, out = sys.argv[1:5]
    names = {}
    if len(sys.argv) > 5:
        for m in re.finditer(r'\{0x([0-9A-Fa-f]+)L,\s*"([^"]+)"', open(sys.argv[5]).read()):
            names[int(m.group(1), 16)] = m.group(2)
    size = len(open(binf, 'rb').read())
    ents = []
    for line in open(tsv):
        f = line.rstrip('\n').split('\t')
        if f[0] == 'entry':
            continue
        a = int(f[0], 16)
        if TEXT_LO <= a < TEXT_HI:
            ents.append((a, names.get(a, f[1])))
    data = open(binf, 'rb').read()

    def is_entry(a):
        return a % 4 == 0 and TEXT_LO <= a < min(TEXT_HI, BASE + size) and data[a - BASE] == 0x36
    dropped = [a for a, _ in ents if not is_entry(a)]
    ents = [(a, n) for a, n in ents if is_entry(a)]
    callre = re.compile(r'(call[x]?\d+|j)\s+0x([0-9a-f]+)')
    added = 0
    while True:  # disassemble; add call targets that are missed `entry` functions; repeat until stable
        ents.sort()
        entset = {a for a, _ in ents}
        nm = dict(ents)
        unknown, listing, new = {}, [], set()
        for i, (a, name) in enumerate(ents):
            end = ents[i + 1][0] if i + 1 < len(ents) else min(TEXT_HI, BASE + size)
            r = subprocess.run([od, '-D', '-b', 'binary', '-m', 'xtensa', '--adjust-vma=0x%x' % BASE,
                                '--start-address=0x%x' % a, '--stop-address=0x%x' % end, binf],
                               capture_output=True, text=True, check=True)
            listing.append('\n;; ---- %08x %s (%d bytes)\n' % (a, name, end - a))
            for ln in r.stdout.splitlines():
                if not re.match(r'\s+[0-9a-f]+:', ln):
                    continue
                for m in callre.finditer(ln):
                    t = int(m.group(2), 16)
                    if m.group(1).startswith('call'):
                        if t in nm:
                            ln += '  ; ' + nm[t]
                        elif is_entry(t):
                            new.add(t)
                        else:
                            unknown.setdefault(t, set()).add(a)
                listing.append(ln + '\n')
        if not new:
            break
        added += len(new)
        ents += [(t, names.get(t, 'FUN_%08x' % t)) for t in new]
    with open(out, 'w') as fo:
        fo.writelines(listing)
        fo.write('\n;; functions.tsv entries dropped (no `entry` instruction): %s\n' % ' '.join('%08x' % a for a in dropped))
        fo.write('\n;; call targets that are not function entries in functions.tsv:\n')
        for t in sorted(unknown):
            fo.write(';;   %08x from %s\n' % (t, ' '.join('%08x' % x for x in sorted(unknown[t]))))
    print('%d functions (%d added from call targets, %d dropped), %d unknown call targets -> %s'
          % (len(ents), added, len(dropped), len(unknown), out))


if __name__ == '__main__':
    main()
