#!/usr/bin/env python3
"""T24 (DISPLAY): smoke test of the NORTi stand-in (src/display/rtos/) in Unicorn.

Builds rtos/norti.c, rtos/norti_port.S and rtos/test/norti_test.c at 0x10000000, runs test_main (the start-up
context, which then drives the ticks as the idle loop) and compares the event log with the sequence the uITRON
semantics give (comments in norti_test.c): semaphore hand-off with preemption by the higher-priority task, an AND
event flag, a mailbox, a message buffer, a timeout, a mutex held across a delay, a cyclic handler.

Usage: python3 -I tools/test_norti_standin.py [--cross PREFIX]
"""
import argparse
import os
import struct
import subprocess
import sys
import tempfile

from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM
from unicorn import arm_const as A

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RT = os.path.join(ROOT, 'src/display/rtos')
EXPECT = 'abA12F3m42h5LTUMxyc'
BASE, SIZE, STOP = 0x10000000, 0x200000, 0x10300000


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--cross', default=os.environ.get('CROSS', 'arm-none-eabi-'))
    a = ap.parse_args()
    with tempfile.TemporaryDirectory() as d:
        ld = os.path.join(d, 't.ld')
        with open(ld, 'w') as f:
            f.write(f'ENTRY(test_main)\nSECTIONS {{ . = {BASE:#x}; .text : {{ *(.text*) *(.rodata*) }} '
                    '.data : { *(.data*) } .bss : { *(.bss* COMMON) } /DISCARD/ : { *(.ARM.exidx*) } }\n')
        elf = os.path.join(d, 't.elf')
        cflags = ['-O2', '-marm', '-mcpu=cortex-a9', '-mfloat-abi=soft', '-ffreestanding', '-fno-builtin', '-nostdlib',
                  '-Wall', '-I' + os.path.join(ROOT, 'src/display/include')]
        subprocess.run([a.cross + 'gcc'] + cflags + ['-T', ld, '-o', elf, os.path.join(RT, 'norti.c'),
                        os.path.join(RT, 'norti_port.S'), os.path.join(RT, 'test', 'norti_test.c'), '-lgcc'],
                       check=True)
        bin_ = os.path.join(d, 't.bin')
        subprocess.run([a.cross + 'objcopy', '-O', 'binary', elf, bin_], check=True)
        syms = {}
        for ln in subprocess.run([a.cross + 'nm', elf], capture_output=True, text=True, check=True).stdout.split('\n'):
            f = ln.split()
            if len(f) == 3:
                syms[f[2]] = int(f[0], 16)
        code = open(bin_, 'rb').read()
    uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    uc.mem_map(BASE, SIZE)
    uc.mem_map(STOP, 0x1000)
    uc.mem_write(BASE, code)
    uc.reg_write(A.UC_ARM_REG_SP, BASE + SIZE - 0x100)
    uc.reg_write(A.UC_ARM_REG_LR, STOP)
    uc.emu_start(syms['test_main'], STOP, count=20000000)
    n = uc.reg_read(A.UC_ARM_REG_R0)
    log = bytes(uc.mem_read(syms['test_log'], n)).decode('latin-1')
    ok = log == EXPECT
    print(f'test_norti_standin: log {log!r}, expected {EXPECT!r}: {"pass" if ok else "FAIL"}')
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
