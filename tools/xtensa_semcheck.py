#!/usr/bin/env python3
"""T24 (IFDSP HiFi4): check the p-code semantics of Xtensa:LE:32:rt600hifi4 for the instruction forms the recreated
HiFi4 code uses, against QEMU's Xtensa implementation (the way tools/rx_semcheck_forms.sh checked the RX module).

  python3 -I tools/xtensa_semcheck.py forms                         the forms of src/ifdsp_hifi4/out/obj, and which are templated
  python3 -I tools/xtensa_semcheck.py run <workdir> [--cases N] [--seed S] [--only MN,...]

The recreated code is GCC output for the base ISA plus the core's integer options and the Tensilica assembly of
newlib, so the forms are base Xtensa: their semantics are the ISA's, and QEMU (qemu-system-xtensa 8.2, core de233_fpu,
which has the windowed, loop, MUL32/MUL32_HIGH, DIV32, NSA, MINMAX, SEXT, CLAMPS options) is an independent
implementation of them. The operand fields and encodings of this core are Cadence's xtensa-modules.c (T21a), from which
the module was generated; GNU as with the same overlay encodes the test program, and both emulators run the same bytes.

run: writes a flat program (call0 style, no window rotation) with N random cases per templated mnemonic. A case loads
a0..a14 and SAR from its state block (a15 is the block pointer), executes the instruction (or a zero-overhead loop with
a two-instruction body), stores a0..a14 and SAR and whether a branch was taken, into the block; load/store forms use a
64-byte data block of their own. The program ends with a semihosting write of the whole table and exit. The same ELF
runs in QEMU (-M sim -cpu de233_fpu -semihosting) and in Ghidra's p-code emulator (tools/ghidra/EquivHifi4Emu.java,
which stops at the first SIMCALL); every byte of every block is compared. CALLn/ENTRY/RETW are not in the program:
the harness executes them itself (EquivHifi4Emu.java), and every equivalence trial exercises them.
Environment: HIFI4_CROSS (tool prefix), QEMU (default qemu-system-xtensa), FT710_IFDSP_PROJECT, GHIDRA_JAVA_HOME.
Nothing here reads the firmware.
"""
import argparse
import glob
import os
import random
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
CROSS = os.environ.get('HIFI4_CROSS', '/root/opt/zephyr-sdk-0.17.0/xtensa-nxp_rt600_adsp_zephyr-elf/bin/'
                                      'xtensa-nxp_rt600_adsp_zephyr-elf-')
QEMU = os.environ.get('QEMU', 'qemu-system-xtensa')
QEMU_CPU = os.environ.get('QEMU_CPU', 'de233_fpu')
LIT, CODE, TABLE = 0x080000, 0x090000, 0x300000      # TABLE: up to 1 MB of state blocks, clear of the harness's scratch code
BLOCK = 0x180
OUT, DATA = 0x80, 0x100

B4CONST = [-1, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 16, 32, 64, 128, 256]
B4CONSTU = [32768, 65536, 2, 3, 4, 5, 6, 7, 8, 10, 12, 16, 32, 64, 128, 256]

# mnemonic -> operand template. R = a register a0..a14 (written or read), r = read-only register, B = base register
# (set to the data block), S8 = simm8, ...; T = branch target. Size letters of loads/stores give the alignment.
TEMPLATES = {
    'add': 'R,R,R', 'add.n': 'R,R,R', 'sub': 'R,R,R', 'addx2': 'R,R,R', 'addx4': 'R,R,R', 'addx8': 'R,R,R',
    'subx2': 'R,R,R', 'subx4': 'R,R,R', 'subx8': 'R,R,R', 'and': 'R,R,R', 'or': 'R,R,R', 'xor': 'R,R,R',
    'addi': 'R,R,S8', 'addi.n': 'R,R,AN', 'addmi': 'R,R,S8x256', 'neg': 'R,R', 'abs': 'R,R', 'mov.n': 'R,R',
    'mov': 'R,R', 'movi': 'R,S12', 'movi.n': 'R,MN', 'moveqz': 'R,R,R', 'movnez': 'R,R,R', 'movltz': 'R,R,R',
    'movgez': 'R,R,R', 'min': 'R,R,R', 'max': 'R,R,R', 'minu': 'R,R,R', 'maxu': 'R,R,R', 'mull': 'R,R,R',
    'muluh': 'R,R,R', 'mulsh': 'R,R,R', 'mul16u': 'R,R,R', 'mul16s': 'R,R,R',
    'quos': 'R,R,D', 'quou': 'R,R,D', 'rems': 'R,R,D', 'remu': 'R,R,D',
    'sext': 'R,R,U7_22', 'clamps': 'R,R,U7_22', 'nsa': 'R,R', 'nsau': 'R,R',
    'slli': 'R,R,U1_31', 'srli': 'R,R,U0_15', 'srai': 'R,R,U0_31', 'extui': 'R,R,EXT', 'ssl': 'r', 'ssr': 'r',
    'ssa8l': 'r', 'ssai': 'U0_31', 'sll': 'R,R', 'srl': 'R,R', 'sra': 'R,R', 'src': 'R,R,R',
    'l8ui': 'R,B,O1', 'l16ui': 'R,B,O2', 'l16si': 'R,B,O2', 'l32i': 'R,B,O4', 'l32i.n': 'R,B,O4N',
    's8i': 'r,B,O1', 's16i': 'r,B,O2', 's32i': 'r,B,O4', 's32i.n': 'r,B,O4N',
    'beq': 'r,r,T', 'bne': 'r,r,T', 'blt': 'r,r,T', 'bge': 'r,r,T', 'bltu': 'r,r,T', 'bgeu': 'r,r,T',
    'bany': 'r,r,T', 'bnone': 'r,r,T', 'ball': 'r,r,T', 'bnall': 'r,r,T', 'bbc': 'r,r,T', 'bbs': 'r,r,T',
    'beqz': 'r,T', 'bnez': 'r,T', 'bltz': 'r,T', 'bgez': 'r,T', 'beqz.n': 'r,T', 'bnez.n': 'r,T',
    'beqi': 'r,B4,T', 'bnei': 'r,B4,T', 'blti': 'r,B4,T', 'bgei': 'r,B4,T', 'bltui': 'r,B4U,T', 'bgeui': 'r,B4U,T',
    'bbci': 'r,U0_31,T', 'bbsi': 'r,U0_31,T', 'j': 'T',
    'loop': 'LOOP', 'loopnez': 'LOOP', 'loopgtz': 'LOOP',
    'nop': '', 'nop.n': '', 'memw': '',
    # FPU (the original's code, not GCC's): a3, a4, a5 -> aed1, aed2, aed0 by WFR, the operation into aed0, RFR to a6.
    # This core's FP registers are the AE registers; the encodings are the standard FP option's (WFR = 0xFA..50,
    # MADD.S = 0x4A..), so QEMU runs them on its f0..f15.
    'add.s': 'FP', 'sub.s': 'FP', 'mul.s': 'FP', 'madd.s': 'FP', 'msub.s': 'FP',
}
FLOATS = [0x3F800000, 0x3F800001, 0x3F7FFFFF, 0x33800000, 0xB3800000, 0x4B000000, 0xCB000001, 0x7F7FFFFF, 0x00800000,
          0x00000001, 0x80000000, 0x7F800000, 0x3EAAAAAB, 0x40490FDB]
# executed by the harness itself (EquivHifi4Emu.java), not by the module's p-code, or pseudo forms
HARNESS = {'entry', 'retw', 'retw.n', 'call4', 'call8', 'call12', 'callx4', 'callx8', 'callx12'}
ALIASES = {'bbci.l': 'bbci', 'bbsi.l': 'bbsi'}
NOT_TEMPLATED_WHY = {'l32r': 'PC-relative literal load: every case of the program loads its block pointer with it',
                     'ret': 'call0 return (the program does not test it: CALL0 code is not recreated)',
                     'ret.n': 'call0 return', 'jx': 'indirect jump', 'callx0': 'call0', 'call0': 'call0'}


def tool(n):
    return CROSS + n


def objdump_forms(paths):
    forms = {}
    for p in paths:
        out = subprocess.run([tool('objdump'), '-d', p], capture_output=True, text=True).stdout
        for ln in out.splitlines():
            parts = ln.split('\t')
            if len(parts) < 3 or not re.match(r'^\s*[0-9a-f]+:$', parts[0]):
                continue
            mn = parts[2].split()[0] if parts[2].split() else ''
            if mn and mn not in ('.byte', 'ill', '.word', '.short'):
                forms[mn] = forms.get(mn, 0) + 1
    return forms


def used_forms():
    objs = sorted(glob.glob(os.path.join(ROOT, 'src/ifdsp_hifi4/out/obj/**/*.o'), recursive=True))
    return objdump_forms(objs)


def cmd_forms(args):
    f = used_forms()
    for mn, n in sorted(f.items(), key=lambda kv: -kv[1]):
        m = ALIASES.get(mn, mn)
        state = 'templated' if m in TEMPLATES else ('harness' if m in HARNESS else
                                                    'not templated: ' + NOT_TEMPLATED_WHY.get(m, '?'))
        print(f'{mn:12s} {n:6d}  {state}')


def operand(rng, kind, regs, state, block):
    """Text for one operand; may set the start state of a register it uses."""
    def reg(readonly=False):
        r = rng.randrange(0, 15)
        return r
    if kind in ('R', 'r'):
        r = reg()
        regs.append(r)
        return f'a{r}'
    if kind == 'D':                          # a divisor: non-zero
        r = reg()
        regs.append(r)
        state[r] = rng.choice([1, 2, 3, 7, 0xFFFFFFFF, 0x80000000, rng.getrandbits(32) | 1, rng.getrandbits(8) | 1])
        return f'a{r}'
    if kind == 'B':
        r = reg()
        regs.append(r)
        state[r] = block + DATA
        return f'a{r}'
    if kind == 'S8':
        return str(rng.randrange(-128, 128))
    if kind == 'S8x256':
        return str(256 * rng.randrange(-128, 128))
    if kind == 'AN':
        return str(rng.choice([-1] + list(range(1, 16))))
    if kind == 'S12':
        return str(rng.randrange(-2048, 2048))
    if kind == 'MN':
        return str(rng.randrange(-32, 96))
    if kind == 'U7_22':
        return str(rng.randrange(7, 23))
    if kind == 'U1_31':
        return str(rng.randrange(1, 32))
    if kind == 'U0_15':
        return str(rng.randrange(0, 16))
    if kind == 'U0_31':
        return str(rng.randrange(0, 32))
    if kind == 'EXT':
        sh = rng.randrange(0, 32)
        return f'{sh}, {rng.randrange(1, min(16, 32 - sh) + 1)}'     # the assembler refuses shift + width > 32
    if kind == 'O1':
        return str(rng.randrange(0, 60))
    if kind == 'O2':
        return str(2 * rng.randrange(0, 30))
    if kind == 'O4':
        return str(4 * rng.randrange(0, 15))
    if kind == 'O4N':
        return str(4 * rng.randrange(0, 15))
    if kind == 'B4':
        return str(rng.choice(B4CONST))
    if kind == 'B4U':
        return str(rng.choice(B4CONSTU))
    raise ValueError(kind)


INTERESTING = [0, 1, 2, 0x7F, 0x80, 0xFF, 0x7FFF, 0x8000, 0xFFFF, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, 0xFFFFFFFE,
               0x00010000, 0x1F, 0x20, 0x21, 3, 4, 5]


def gen(rng, mnems, ncases):
    """Assembly text and the list of (mnemonic, instruction text) per case."""
    # QEMU's sim machine starts the core at its reset vector 0xFE000000 (sysrom), not at the ELF entry: a stub there
    # jumps to _start (CODE = 0x90 << 12); Ghidra starts at _start
    lines = ['\t.section .reset, "ax"', f'\tmovi\ta0, {CODE >> 12:#x}', '\tslli\ta0, a0, 12', '\tjx\ta0',
             '\t.text', '\t.global _start', '_start:', '\tmovi\ta2, 0', '\twsr\ta2, ps', '\trsync', '\tmovi\ta2, 0xff', '\twsr\ta2, cpenable', '\trsync']
    cases = []
    k = 0
    for mn in mnems:
        tpl = TEMPLATES[mn]
        for _ in range(ncases):
            block = TABLE + BLOCK * k
            state = {r: (rng.choice(INTERESTING) if rng.random() < 0.4 else rng.getrandbits(32)) for r in range(15)}
            sar = rng.randrange(0, 33)
            regs = []
            if tpl == 'LOOP':
                cnt = rng.randrange(2, 7)
                # LOOP with 0 and LOOPNEZ with a negative count run 2^32 times; LOOPGTZ skips negative counts
                state[cnt] = rng.choice({'loop': [1, 2, 3, 5, 9], 'loopnez': [0, 1, 2, 3, 5, 9],
                                         'loopgtz': [0, 1, 2, 3, 5, 9, 0xFFFFFFFF, 0x80000000]}[mn])
                if rng.random() < 0.5:
                    text = [f'\t{mn}\ta{cnt}, .Ll{k}', '\taddi\ta7, a7, 3', '\taddi\ta8, a8, 1', f'.Ll{k}:']
                    inst = f'{mn} a{cnt} (count {state[cnt]:#x})'
                else:
                    # the body ends in a branch to LEND: taken, it leaves the loop (newlib strncpy.S relies on it)
                    state[8] = rng.choice([1, 2, 3, 4, 7, 20])
                    text = [f'\t{mn}\ta{cnt}, .Ll{k}', '\taddi\ta7, a7, 3', '\taddi\ta8, a8, -1',
                            '\t.begin no-transform', f'\t_beqz\ta8, .Ll{k}', '\t.end no-transform', f'.Ll{k}:']
                    inst = f'{mn} a{cnt} (count {state[cnt]:#x}) with beqz a8 to LEND (a8 {state[8]})'
            elif tpl == 'FP':
                # one register for all three operands: this core's FP operations take their operands from other
                # instruction fields than the standard FP option QEMU implements (mul.s aed2, aed0, aed12 is
                # 0x2AC200: r = 12, s = 2, t = 0, at 0x208878), so only op x, x, x means the same in both
                x = rng.random()
                state[3] = rng.choice(FLOATS) ^ (rng.getrandbits(1) << 31) if x < 0.3 else \
                    (rng.getrandbits(32) & 0x807FFFFF) | (rng.randrange(0x70, 0x90) << 23)
                text = ['\twfr\taed3, a3', f'\t{mn}\taed3, aed3, aed3', '\trfr\ta6, aed3']
                inst = f'{mn} aed3, aed3, aed3 (a3 {state[3]:#x})'
            else:
                ops = [operand(rng, x, regs, state, block) for x in tpl.split(',') if x and x != 'T']
                if tpl.split(',')[-1] == 'T':
                    ops.append(f'.Lt{k}')
                inst = f'{mn}\t' + ', '.join(ops) if ops else mn
                text = ['\t.begin no-transform', f'\t_{inst}' if mn not in ('nop', 'nop.n', 'memw') else f'\t{inst}',
                        '\t.end no-transform']
            data = bytes(rng.getrandbits(8) for _ in range(64))
            cases.append((mn, inst, block, state, sar, data, regs))
            # a15 = this case's block: the table start, then + BLOCK per case (no literal per case: the program is
            # longer than L32R's 256 KB reach)
            step = [f'\tmovi\ta15, {TABLE:#x}'] if k == 0 else ['\taddmi\ta15, a15, 0x100', '\taddi\ta15, a15, 0x80']
            lines += [f'\t# case {k}: {inst}'] + step + [f'\tl32i\ta14, a15, 0x40',
                      '\twsr\ta14, sar'] + [f'\tl32i\ta{r}, a15, {4 * r}' for r in range(15)] + text
            store = [f'\ts32i\ta{r}, a15, {OUT + 4 * r}' for r in range(15)] + \
                    ['\trsr\ta14, sar', f'\ts32i\ta14, a15, {OUT + 0x40}']
            lines += store + ['\tmovi\ta14, 0', f'\ts32i\ta14, a15, {OUT + 0x44}', f'\tj\t.Le{k}', f'.Lt{k}:'] + \
                store + ['\tmovi\ta14, 1', f'\ts32i\ta14, a15, {OUT + 0x44}', f'.Le{k}:']
            k += 1
    size = BLOCK * k
    # write(1, TABLE, size) and exit(0) by semihosting, without literals (L32R would not reach back from here)
    assert TABLE == 3 << 20 and BLOCK == 0x180
    lines += ['\tmovi\ta2, 4', '\tmovi\ta3, 1', '\tmovi\ta4, 3', '\tslli\ta4, a4, 20', '\taddmi\ta5, a15, 0x100',
              '\taddi\ta5, a5, 0x80', '\tsub\ta5, a5, a4', '\tsimcall',
              '\tmovi\ta2, 1', '\tmovi\ta3, 0', '\tsimcall', '1:\tj\t1b']
    return '\n'.join(lines) + '\n', cases


def table_bytes(cases):
    t = bytearray(BLOCK * len(cases))
    for i, (_, _, block, state, sar, data, _) in enumerate(cases):
        o = BLOCK * i
        for r, v in state.items():
            t[o + 4 * r:o + 4 * r + 4] = (v & 0xFFFFFFFF).to_bytes(4, 'little')
        t[o + 0x40:o + 0x44] = sar.to_bytes(4, 'little')
        t[o + DATA:o + DATA + 64] = data
    return bytes(t)


CORES = ['de233_fpu', 'dsp3400', 'test_mmuhifi_c3', 'sample_controller', 'dc233c', 'de212']


def build(w, mnems, ncases, seed):
    os.makedirs(w, exist_ok=True)
    asm, cases = gen(random.Random(seed), mnems, ncases)
    tab = table_bytes(cases)
    with open(os.path.join(w, 'forms.S'), 'w') as f:
        f.write(asm)
    with open(os.path.join(w, 'table.bin'), 'wb') as f:
        f.write(tab)
    elf = os.path.join(w, 'forms.elf')
    subprocess.run([tool('as'), '-o', os.path.join(w, 'forms.o'), os.path.join(w, 'forms.S')], check=True)
    with open(os.path.join(w, 'forms.ld'), 'w') as f:
        f.write(f'ENTRY(_start)\nSECTIONS {{ .reset 0xFE000000 : {{ *(.reset) }} .lit {LIT:#x} : {{ *(.literal) }}\n'
                f'  .text {CODE:#x} : {{ *(.text) }}\n'
                f'  .table {TABLE:#x} : {{ {os.path.join(w, "table.o")}(.data) }} }}\n')
    subprocess.run([tool('objcopy'), '-I', 'binary', '-O', 'elf32-xtensa-le', '-B', 'xtensa',
                    os.path.join(w, 'table.bin'), os.path.join(w, 'table.o')], check=True)
    subprocess.run([tool('ld'), '-T', os.path.join(w, 'forms.ld'), '-o', elf, os.path.join(w, 'forms.o'),
                    os.path.join(w, 'table.o')], check=True)
    return elf, cases, tab


def qemu(elf, core, timeout):
    """The table as QEMU leaves it, or None (a core without the instruction ends in an exception loop)."""
    try:
        q = subprocess.run([QEMU, '-M', 'sim', '-cpu', core, '-semihosting', '-display', 'none', '-monitor', 'none',
                            '-serial', 'none', '-kernel', elf], capture_output=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        return None
    return q.stdout


def _s32(v):
    return v - (1 << 32) if v >> 31 else v


# MUL32_HIGH (MULUH, MULSH) is in no QEMU core: the reference is the ISA's definition, the upper 32 bits of the
# unsigned / signed 64-bit product of as and at (operands: ar, as, at)
MODELS = {'muluh': lambda s, t: (s * t) >> 32, 'mulsh': lambda s, t: (_s32(s) * _s32(t)) >> 32}


def model_table(cases, tab):
    out = bytearray(tab)
    for i, (mn, inst, block, state, sar, data, regs) in enumerate(cases):
        o = BLOCK * i
        res = dict(state)
        res[regs[0]] = MODELS[mn](state[regs[1]], state[regs[2]]) & 0xFFFFFFFF
        for r in range(15):
            out[o + OUT + 4 * r:o + OUT + 4 * r + 4] = res[r].to_bytes(4, 'little')
        out[o + OUT + 0x40:o + OUT + 0x44] = sar.to_bytes(4, 'little')
        out[o + OUT + 0x44:o + OUT + 0x48] = bytes(4)
    return bytes(out)


def probe(w, mnems):
    """mnemonic -> the first core (QEMU_CPU, then CORES) that runs one case of it to the end."""
    out = {}
    for mn in mnems:
        elf, cases, tab = build(os.path.join(w, 'probe'), [mn], 1, 1)
        for core in [QEMU_CPU] + [c for c in CORES if c != QEMU_CPU]:
            r = qemu(elf, core, 4)
            if r is not None and len(r) == len(tab):
                out[mn] = core
                break
    return out


def cmd_run(args):
    w = os.path.abspath(args.workdir)
    used = {ALIASES.get(m, m) for m in used_forms()}
    mnems = sorted(m for m in TEMPLATES if (m in used or args.all) and (not args.only or m in args.only.split(',')))
    cores = probe(w, mnems)
    for mn in mnems:
        if mn not in cores and mn in MODELS:
            cores[mn] = 'model'
        elif mn not in cores:
            print(f'xtensa_semcheck: {mn}: no QEMU core of {CORES} executes it; not checked')
    total_ok = total_bad = 0
    rows = []
    for core in sorted(set(cores.values())):
        group = [m for m in mnems if cores.get(m) == core]
        ok, bad, r = check_group(os.path.join(w, core), group, args.cases, args.seed, core)
        total_ok += ok
        total_bad += bad
        rows += r
    with open(os.path.join(w, 'result.tsv'), 'w') as f:
        f.write('mnemonic\tqemu_core\tok\tfail\tfirst failure\n')
        f.writelines(sorted(rows))
    print(f'xtensa_semcheck: {len(cores)} of {len(mnems)} mnemonics, {total_ok + total_bad} cases: {total_ok} agree, '
          f'{total_bad} differ (QEMU {", ".join(sorted(set(cores.values())))} vs Ghidra Xtensa:LE:32:rt600hifi4); '
          f'{os.path.join(w, "result.tsv")}')
    return 0 if total_bad == 0 and len(cores) == len(mnems) else 1


def check_group(w, mnems, ncases, seed, core):
    elf, cases, tab = build(w, mnems, ncases, seed)
    qres = qemu(elf, core, 120) if core != 'model' else model_table(cases, tab)
    if qres is None or len(qres) != len(tab):
        sys.exit(f'xtensa_semcheck: QEMU ({core}) did not finish the program of {mnems}')
    from elftools.elf.elffile import ELFFile
    segs = []
    text_end = CODE
    with open(elf, 'rb') as f:
        for s in ELFFile(f).iter_sections():
            if s['sh_flags'] & 2 and s['sh_type'] == 'SHT_PROGBITS' and s['sh_size'] and s.name != '.reset':
                segs.append([s['sh_addr'], s.data().hex()])
            if s.name == '.text':
                text_end = s['sh_addr'] + s['sh_size']
    import equiv_hifi4_emu as E
    img = type('I', (), {'segs': []})()
    eng = E.Engine(img)
    try:
        eng.send({'op': 'base', 'name': 'prog', 'segs': segs})
        r = eng.send({'op': 'run', 'bases': ['prog'], 'entry': CODE, 'budget': 60 * len(cases) + 10000,
                      'exec': [[CODE, text_end]], 'snap': [[TABLE, TABLE + len(tab)]]})
    finally:
        eng.close()
    if r['end'] != 'simcall':
        sys.exit(f'xtensa_semcheck: Ghidra run ended {r["end"]}: {r["why"]} after {r["steps"]} steps')
    gres = bytearray(tab)
    for a, h in r['diff']:
        b = bytes.fromhex(h)
        gres[a - TABLE:a - TABLE + len(b)] = b
    bad, nok = {}, {}
    for i, (mn, inst, block, state, sar, data, _) in enumerate(cases):
        o = BLOCK * i
        x, y = qres[o:o + BLOCK], bytes(gres[o:o + BLOCK])
        nok.setdefault(mn, [0, 0])
        if x == y:
            nok[mn][0] += 1
            continue
        nok[mn][1] += 1
        diffs = []
        for off in range(OUT, OUT + 0x48, 4):
            a, b = int.from_bytes(x[off:off + 4], 'little'), int.from_bytes(y[off:off + 4], 'little')
            if a != b:
                nm = f'a{(off - OUT) // 4}' if off < OUT + 0x3C else {OUT + 0x40: 'SAR', OUT + 0x44: 'taken'}.get(off, hex(off))
                diffs.append(f'{nm} qemu {a:#x} ghidra {b:#x}')
        if x[DATA:DATA + 64] != y[DATA:DATA + 64]:
            diffs.append(f'data qemu {x[DATA:DATA + 64].hex()} ghidra {y[DATA:DATA + 64].hex()}')
        bad.setdefault(mn, []).append(f'case {i} `{inst}` in ' + ' '.join(f'a{r}={v:#x}' for r, v in sorted(state.items()))
                                      + f' SAR={sar}: ' + '; '.join(diffs))
    rows = []
    for mn in mnems:
        rows.append(f'{mn}\t{core}\t{nok[mn][0]}\t{nok[mn][1]}\t{bad.get(mn, [""])[0]}\n')
        if mn in bad:
            print(f'{mn}: {nok[mn][1]} of {sum(nok[mn])} differ; {bad[mn][0]}'[:700])
    return sum(v[0] for v in nok.values()), sum(v[1] for v in nok.values()), rows



def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    sub.add_parser('forms')
    r = sub.add_parser('run')
    r.add_argument('workdir')
    r.add_argument('--cases', type=int, default=12)
    r.add_argument('--seed', type=int, default=1)
    r.add_argument('--only')
    r.add_argument('--all', action='store_true', help='every templated mnemonic, not only the used ones')
    args = ap.parse_args()
    sys.exit({'forms': cmd_forms, 'run': cmd_run}[args.cmd](args) or 0)


if __name__ == '__main__':
    main()
