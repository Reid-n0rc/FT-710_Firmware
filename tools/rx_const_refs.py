#!/usr/bin/env python3
"""List the data references of the MAIN (RX) image to an address range, from rx-elf-objdump output (#205).

CC-RX code reaches RAM through a base loaded with `mov.l #imm, rN` (for the EEPROM mirror always #0x464F) and a displacement,
so a byte search for an address finds nothing; this tool does what Ghidra's data-xref listing does, without Ghidra.

  rx-elf-objdump -D -b binary -m rx --adjust-vma=0xFFF80000 build/FT-710_MAIN_V0112.bin > main.dis
  python3 -I tools/rx_const_refs.py main.dis decomp/main/functions.tsv 4659 475d

Linear sweep, state reset at each function entry (decomp/main/functions.tsv). Tracked: mov.l #imm,rN; add #imm,rN[,rM];
mov.l rA,rB; spills mov.l rN,d[r0] and reloads mov.l d[r0],rM; forward conditional branches carry the state to their target
(union, so stale values can add false hits but not hide real ones). add rX,rN on a tracked base gives "base+var".
Output lines: `<ea> item=<ea-0x4659+1>` (exact access), `base+var` (base in [LO-0x200, HI] plus an unknown register) and
`indexed` ([rI,rB] with a tracked base). Not covered: pointers loaded from memory (RAM pointer variables, ROM pointer
tables): search those separately (for cfg105: RAM 0x25D50 and ROM 0xFFF8861C).
"""
import re, sys, bisect
dis, ftsv, LO, HI = sys.argv[1], sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 16)
funcs = []
for line in open(ftsv):
    p = line.rstrip('\n').split('\t')
    if p[0] != 'entry':
        funcs.append((int(p[0], 16), int(p[2]), p[1]))
funcs.sort(); starts = [f[0] for f in funcs]; startset = set(starts)
def fn(a):
    i = bisect.bisect_right(starts, a) - 1
    return funcs[i][2] if i >= 0 and a < funcs[i][0] + funcs[i][1] else '(no function)'
line_re = re.compile(r'^([0-9a-f]{8}):\t([0-9a-f ]+?)\s*\t(\S+)\s*(.*)$')
NUM = r'(-?0x[0-9a-f]+|-?\d+)'
regs, vregs, stack, vstack = {}, {}, {}, {}
pending = {}
out = []
def inrange(b): return LO - 0x200 <= b <= HI
for line in open(dis):
    m = line_re.match(line)
    if not m:
        continue
    addr = int(m.group(1), 16); mn = m.group(3); ops = m.group(4).strip()
    if addr in startset:
        regs.clear(); vregs.clear(); stack.clear(); vstack.clear(); pending.clear()
    if addr in pending:
        pr, pv = pending.pop(addr)
        for k, v in pr.items(): regs.setdefault(k, v)
        for k, v in pv.items(): vregs.setdefault(k, v)
    bm = re.match(r'b\w*\.?\w*$', mn)
    if bm and not mn.startswith('bsr') and re.fullmatch(r'0x[0-9a-f]+', ops or ''):
        t = int(ops, 16)
        if t > addr:
            pr, pv = pending.setdefault(t, ({}, {}))
            for k, v in regs.items(): pr.setdefault(k, v)
            for k, v in vregs.items(): pv.setdefault(k, v)
    opl = [o.strip() for o in re.split(r',\s*(?![^\[]*\])', ops)] if ops else []
    # memory operands
    for dm in re.finditer(r'(-?\d+)?\[(r\d+)\]', ops):
        r = dm.group(2); disp = int(dm.group(1) or 0)
        if r in regs and r != 'r0':
            ea = regs[r] + disp
            if LO <= ea <= HI:
                out.append((ea, addr, mn, ops, ''))
        if r in vregs:
            ea = vregs[r] + disp
            if inrange(vregs[r]):
                out.append((-2, addr, mn, ops, f'{r} = {vregs[r]:#x} + var -> {ea:#x} + var'))
    for im in re.finditer(r'\[(r\d+),\s*(r\d+)\]', ops):
        for r in im.groups():
            if r in regs and inrange(regs[r]):
                out.append((-1, addr, mn, ops, f'{r} = {regs[r]:#x}'))
    # updates
    dst = opl[-1] if opl and re.fullmatch(r'r\d+', opl[-1]) else None
    if mn.startswith(('bsr', 'jsr')):
        for r in ['r1', 'r2', 'r3', 'r4', 'r5', 'r14', 'r15']:
            regs.pop(r, None); vregs.pop(r, None)
        continue
    if mn.startswith(('rts', 'rte')):
        regs.clear(); vregs.clear(); continue
    if mn in ('rtsd',):
        regs.clear(); vregs.clear(); continue
    # spill / reload
    if mn == 'mov.l' and len(opl) == 2:
        s, d = opl
        sm = re.fullmatch(r'(-?\d+)?\[r0\]', d)
        if sm and re.fullmatch(r'r\d+', s):
            k = int(sm.group(1) or 0)
            stack.pop(k, None); vstack.pop(k, None)
            if s in regs: stack[k] = regs[s]
            if s in vregs: vstack[k] = vregs[s]
            continue
        lm = re.fullmatch(r'(-?\d+)?\[r0\]', s)
        if lm and dst:
            k = int(lm.group(1) or 0)
            regs.pop(dst, None); vregs.pop(dst, None)
            if k in stack: regs[dst] = stack[k]
            if k in vstack: vregs[dst] = vstack[k]
            continue
    if dst is None:
        # store to stack slot via other sizes kills it
        sm = re.search(r'(-?\d+)?\[r0\]$', ops)
        if sm:
            k = int(sm.group(1) or 0); stack.pop(k, None); vstack.pop(k, None)
        continue
    imm = re.fullmatch('#' + NUM, opl[0]) if opl else None
    newc, newv = None, None
    if mn in ('mov.l', 'mov') and imm and len(opl) == 2:
        newc = int(imm.group(1), 0) & 0xFFFFFFFF
    elif mn == 'mov.l' and len(opl) == 2 and re.fullmatch(r'r\d+', opl[0]):
        newc = regs.get(opl[0]); newv = vregs.get(opl[0])
    elif mn == 'add' and imm:
        src = opl[1] if len(opl) == 3 else dst
        if src in regs: newc = (regs[src] + int(imm.group(1), 0)) & 0xFFFFFFFF
        if src in vregs: newv = vregs[src] + int(imm.group(1), 0)
    elif mn == 'add' and len(opl) in (2, 3) and all(re.fullmatch(r'r\d+', o) for o in opl):
        a, b = opl[0], opl[1] if len(opl) == 3 else dst
        for x in (a, b):
            if x in regs and inrange(regs[x]): newv = regs[x]
            if x in vregs: newv = vregs[x]
    regs.pop(dst, None); vregs.pop(dst, None)
    if newc is not None: regs[dst] = newc
    if newv is not None: vregs[dst] = newv
for ea, addr, mn, ops, note in sorted(out):
    tag = f'{ea:#06x} item={ea - 0x4659 + 1:3d}' if ea >= 0 else ('indexed     ' if ea == -1 else 'base+var    ')
    print(f'{tag} {addr:#x} {fn(addr):28s} {mn} {ops}   {note}')
