#!/usr/bin/env python3
"""T24 (DISPLAY, started): differential emulation of recreated DISPLAY functions (RZ/A1H Cortex-A9, A32) with Unicorn.

The DISPLAY image was built with armcc (ARM Compiler 5), which is not available, so no byte match is possible: each
recreated function is compiled with GCC and checked against the original by running both on the same inputs.
This first version handles leaf functions without data references (no relocations in their section): the recompiled
section is placed at a scratch address; r0..r3 get random draws (small integers, 32-bit values, or pointers to random
buffers); a run ends at the return address. Equivalent when every trial gives the same r0 and the same buffers and
ends the same way. Callees, globals and NORTi calls (the next step) need the relocation and stub machinery of
tools/equiv_m33_emu.py ported to A32.

Usage: python3 -I tools/equiv_display_emu.py <object.o> <function>=<hex address> [...] [--trials N]
"""
import os
import random
import struct
import sys

from elftools.elf.elffile import ELFFile
from unicorn import Uc, UcError, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE, UC_PROT_ALL
from unicorn import arm_const as A

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMAGE = os.path.join(os.environ.get('FT710_BUILD', os.path.join(ROOT, 'build')), 'FT-710_DISPLAY_V0108.bin')
BASE = 0x20100000                  # load address of the image (docs/code/display/README.md)
RAM = (0x20000000, 0x20A00000)     # RZ/A1H on-chip RAM, 10 MB
SCRATCH, ARGS, STOP = 0x30000000, 0x30100000, 0x3F000000
STACK_TOP = 0x3E000000
BUDGET = 2000000


def section_of(obj, fname):
    elf = ELFFile(open(obj, 'rb'))
    sec = elf.get_section_by_name(f'.text.{fname}')
    if sec is None:
        raise SystemExit(f'{obj}: no section .text.{fname} (build with -ffunction-sections)')
    if elf.get_section_by_name(f'.rel.text.{fname}') is not None:
        raise SystemExit(f'{fname}: has relocations; this first version takes leaf functions only')
    return sec.data()


def run(img, code_at, code, regs, bufs):
    uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    uc.mem_map(RAM[0], RAM[1] - RAM[0], UC_PROT_ALL)
    uc.mem_write(BASE, img)
    for lo in (SCRATCH, ARGS, STOP, STACK_TOP - 0x10000):
        uc.mem_map(lo, 0x100000 if lo != STACK_TOP - 0x10000 else 0x10000, UC_PROT_ALL)
    if code:
        uc.mem_write(code_at, code)
    for a, d in bufs:
        uc.mem_write(a, d)
    end = []
    uc.hook_add(UC_HOOK_CODE, lambda u, a, n, _: (end.append('return'), u.emu_stop()), begin=STOP, end=STOP)
    for r, v in zip((A.UC_ARM_REG_R0, A.UC_ARM_REG_R1, A.UC_ARM_REG_R2, A.UC_ARM_REG_R3), regs):
        uc.reg_write(r, v)
    uc.reg_write(A.UC_ARM_REG_SP, STACK_TOP - 0x100)
    uc.reg_write(A.UC_ARM_REG_LR, STOP)
    try:
        uc.emu_start(code_at, 0, count=BUDGET)
    except UcError as e:
        end.append(f'fault {e}')
    if not end:
        end.append('budget')
    snap = b''.join(bytes(uc.mem_read(a, len(d))) for a, d in bufs)
    if not end[0].startswith('return'):
        return end[0].split(' (')[0], None, snap   # r0 means nothing after a fault (as in equiv_m33_emu.py)
    return end[0], uc.reg_read(A.UC_ARM_REG_R0), snap


def check(img, code, addr, trials, seed=1):
    rng = random.Random(seed)
    ok = 0
    for t in range(trials):
        regs, bufs = [], []
        for k in range(4):
            x = rng.random()
            if x < 0.4:
                regs.append(rng.choice([0, 1, 2, 3, 7, 8, 16, 100, 255, 256, 1000]))
            elif x < 0.6:
                regs.append(rng.getrandbits(32))
            else:
                a = ARGS + 0x4000 * k
                bufs.append((a, bytes(rng.getrandbits(8) for _ in range(0x4000))))
                regs.append(a)
        r1 = run(img, addr, None, regs, bufs)
        r2 = run(img, SCRATCH, code, regs, bufs)
        if r1 != r2:
            return 'differs', f'trial {t}: orig {r1[0]} r0={r1[1]}, new {r2[0]} r0={r2[1]}'
        ok += r1[0] == 'return'
    if ok == 0:
        return 'not yet', f'no trial of {trials} returned normally'
    return 'equivalent', f'differential emulation: {trials} trials agree ({ok} returned normally)'


def main():
    args = sys.argv[1:]
    trials = 200
    if '--trials' in args:
        i = args.index('--trials')
        trials = int(args[i + 1])
        del args[i:i + 2]
    obj, funcs = args[0], args[1:]
    img = open(IMAGE, 'rb').read()
    for f in funcs:
        name, addr = f.split('=')
        v, d = check(img, section_of(obj, name), int(addr, 16), trials)
        print(f'equiv_display_emu: {name:24s} {v}: {d}')


if __name__ == '__main__':
    main()
