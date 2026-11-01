#!/usr/bin/env python3
"""Per-function disassembly of the IFDSP HiFi4 SRAM image with a FLIX-aware objdump (T12e).

Ghidra's Xtensa module decodes the base ISA only. The Zephyr SDK toolchain for the NXP RT600 ADSP
(`xtensa-nxp_rt600_adsp_zephyr-elf`, binutils 2.38 built with the RT600 HiFi4 core overlay) decodes the
HiFi4 FLIX bundles and HiFi4 opcodes of this image. A linear sweep desynchronises at literal pools and
padding, so this script disassembles each function separately (entry to next entry). Entries are the
functions.tsv entries that start with an `entry` instruction (Ghidra also made ~57 bogus mid-function
entries, which are dropped) plus every call target that starts with `entry` (functions Ghidra missed),
found by iterating. A candidate entry is rejected when the previous function's sweep ends in an instruction that
starts before the candidate and runs past it (objdump prints it with an empty byte column, cut at --stop-address) and
that instruction is reachable from the previous function's entry by fall-through and branch targets: the 0x36 `entry`
byte is then inside an instruction of the previous function (0x218480 in ifft_cplxf_ie's bundle 0x21847D, 0x233818 in
fft_realf_ie's bundle 0x233815). A crossing instruction reached only after a ret/retw/j, `ill`, `.byte` or a zero run
is a sweep artefact in the alignment bytes before a real entry and does not reject it. It puts names from IfdspHifi4Names.java (if given) on the headers and on call targets, and lists
call targets that are not known function entries.

usage: python3 -I tools/ifdsp_hifi4_dis.py <objdump> <sram_text.bin> <functions.tsv> <out.dis> [IfdspHifi4Names.java]
"""
import re, subprocess, sys

BASE = 0x200000
TEXT_LO, TEXT_HI = 0x207000, 0x236800
INSN = re.compile(r'\s+([0-9a-f]+):\t([0-9a-f]*)\s*\t(.*)')
# Slot mnemonics after which execution does not fall through (break/ill end a reachable run too: conservative).
NOFALL = {'ret', 'ret.n', 'retw', 'retw.n', 'j', 'jx', 'rfe', 'rfi', 'rfde', 'rfwo', 'rfwu', 'rfdo', 'rfdd',
          'ill', 'ill.n', 'break', 'break.n', '.byte'}
BRANCH = re.compile(r'(b[a-z0-9]*|j|loop[a-z]*)(\.[a-z0-9]+)*$')


def slots(text):
    """[(mnemonic, last operand)] of an instruction or a `{ a; b }` bundle (objdump text, `  ; name` comment dropped)."""
    text = text.split('  ; ')[0].strip()
    if text.startswith('{'):
        text = text[1:text.rfind('}')]
    out = []
    for p in text.split(';'):
        sp = p.split(None, 1)
        if sp:
            out.append((sp[0], sp[1].split(',')[-1].strip() if len(sp) > 1 else ''))
    return out


def crossing_reached(lines, start):
    """lines: objdump output for one function region [start, end). Return the address of the region's last
    instruction if objdump cut it at `end` (empty byte column) and it is reachable from `start` by fall-through and
    branch targets inside the region; else None."""
    insns = []   # (addr, bytes, text); None for a `...` zero run
    for ln in lines:
        m = INSN.match(ln)
        if m:
            insns.append((int(m.group(1), 16), m.group(2), m.group(3).strip()))
        elif ln.strip() == '...':
            insns.append(None)
    if not insns or insns[-1] is None or insns[-1][1]:
        return None
    idx = {x[0]: i for i, x in enumerate(insns) if x}
    seen, work = set(), [idx.get(start, 0)]
    while work:
        i = work.pop()
        if i in seen or i >= len(insns) or insns[i] is None:
            continue
        seen.add(i)
        sl = slots(insns[i][2])
        if not any(m in NOFALL for m, _ in sl):
            work.append(i + 1)
        for m, op in sl:
            if not m.startswith('break') and BRANCH.match(m) and re.fullmatch(r'0x[0-9a-f]+', op) and int(op, 16) in idx:
                work.append(idx[int(op, 16)])
    return insns[-1][0] if len(insns) - 1 in seen else None


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

    rejected = {}  # entry -> address of the previous function's instruction that covers it

    def is_entry(a):
        return (a % 4 == 0 and TEXT_LO <= a < min(TEXT_HI, BASE + size) and data[a - BASE] == 0x36
                and a not in rejected)
    dropped = [a for a, _ in ents if not is_entry(a)]
    ents = [(a, n) for a, n in ents if is_entry(a)]
    callre = re.compile(r'(call[x]?\d+|j)\s+0x([0-9a-f]+)')
    added = 0
    while True:  # disassemble; add call targets that are missed `entry` functions; repeat until stable
        ents.sort()
        entset = {a for a, _ in ents}
        nm = dict(ents)
        unknown, listing, new, bad = {}, [], set(), set()
        for i, (a, name) in enumerate(ents):
            end = ents[i + 1][0] if i + 1 < len(ents) else min(TEXT_HI, BASE + size)
            r = subprocess.run([od, '-D', '-b', 'binary', '-m', 'xtensa', '--adjust-vma=0x%x' % BASE,
                                '--start-address=0x%x' % a, '--stop-address=0x%x' % end, binf],
                               capture_output=True, text=True, check=True)
            listing.append('\n;; ---- %08x %s (%d bytes)\n' % (a, name, end - a))
            x = crossing_reached(r.stdout.splitlines(), a) if i + 1 < len(ents) else None
            if x is not None:
                bad.add(end)
                rejected[end] = x
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
        if bad:  # drop entries inside a reachable instruction of the previous function, then disassemble again
            ents = [(a, n) for a, n in ents if a not in bad]
            continue
        if not new:
            break
        added += len(new)
        ents += [(t, names.get(t, 'FUN_%08x' % t)) for t in new]
    with open(out, 'w') as fo:
        fo.writelines(listing)
        fo.write('\n;; functions.tsv entries dropped (no `entry` instruction): %s\n' % ' '.join('%08x' % a for a in dropped))
        fo.write(';; entries rejected (`entry` byte inside a reachable instruction of the previous function): %s\n'
                 % ' '.join('%08x (in %08x)' % (a, rejected[a]) for a in sorted(rejected)))
        fo.write('\n;; call targets that are not function entries in functions.tsv:\n')
        for t in sorted(unknown):
            fo.write(';;   %08x from %s\n' % (t, ' '.join('%08x' % x for x in sorted(unknown[t]))))
    print('%d functions (%d added from call targets, %d dropped, %d rejected inside the previous function: %s), '
          '%d unknown call targets -> %s'
          % (len(ents), added, len(dropped), len(rejected), ' '.join('%08x' % a for a in sorted(rejected)) or '-',
             len(unknown), out))


if __name__ == '__main__':
    main()
