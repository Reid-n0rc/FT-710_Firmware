#!/usr/bin/env python3
"""T24 (DISPLAY): differential emulation of recreated DISPLAY functions (RZ/A1H Cortex-A9) with Unicorn.

The DISPLAY image was built with armcc (ARM Compiler 5) on the NORTi kernel; neither is available, so the recreated C
cannot be byte-identical: each recreated function is compiled with GCC (src/display/Makefile, A32) and checked against
the original by running both from the same start state on the same inputs (the method of tools/equiv_m33_emu.py,
ported to A32 in T24 round 3). A function whose section, linked so that it lands at its original address, gives the
image's own bytes is "identical" (the assembly transcriptions of the hand-written run-time routines, T24 round 4).

Start state (built once): the image at 0x20100000, the three LZ-compressed RW regions of its Region$$Table
(0x204286A8) decompressed by the image's own __decompress (0x20100BFC, run in Unicorn), the two zero-init regions
zero; that is the memory after __scatterload. The CPU is in SYS mode (as main and the tasks) with IRQ and FIQ masked
and the MMU off; SVC mode has its own stack, and an svc instruction enters the image's SVC_Handler (round 4).

Per function: the recompiled section is placed at a scratch address and its relocations are resolved against the
original addresses of the same symbols: functions by name from decomp/display/functions.tsv (or
src/display/aliases.tsv), data from src/display/data_symbols.tsv; sections without an original address (string
literals, constant tables of the recreated file) are placed next to it. A call to a Thumb function of the image
becomes BLX, a tail branch to one goes through a small veneer (the instruction set of every original function is in
src/display/modes.tsv, from tools/ghidra/ExportFuncModes.java). Callees are the image's own functions and run
natively, except the NORTi service calls (STUBS: itron_*): they return a value from a seeded sequence, write a seeded
word through their output pointer, and are recorded with their arguments. Peripheral reads (0x3FE00000..,
0xE8000000.., 0xFCFE0000..) return values from a seeded sequence and every access is recorded (mmio_map callbacks; no
memory hooks, see equiv_m33_emu.py on the Unicorn bug they trigger).

Inputs: r0..r3 and the first four stack slots drawn like equiv_m33_emu.py (small integers, 32-bit values, pointers
to random buffers or strings); the data words the function refers to filled with the same random bytes (except those
src/display/data_symbols.tsv marks keep, such as the GPIO port table); PRESETS
build valid structures where a function walks one.

Equivalent when the original and the recompiled function issue the same set of CP15 operations (a static comparison:
Unicorn executes cache and TLB maintenance as no-ops) and every trial agrees on: the way it ended (return, fault, budget), r0 (r0:r1 for 8-byte returns, none
for void, from the object's DWARF), the RW memory after the run (SNAP), the CP15 SCTLR, the sequence of peripheral
accesses and of stubbed calls; at least one trial returned normally; and the trials together reached at least half
of the original's basic blocks (block hook against a static leader scan). armcc and GCC code differ in length, so a
trial where one run exhausts the instruction budget is run again with 8 times the budget; a trial where both runs
exhaust the budget is inconclusive (not compared, and reported).

Usage:
  python3 -I tools/equiv_display_emu.py check FUNCTION... [--object OBJ] [--trials N] [--seed S]
                                        the named functions, or all of an object (src/display/out/obj)
  python3 -I tools/equiv_display_emu.py status [--trials N]   every recreated function -> src/display/status.tsv
  python3 -I tools/equiv_display_emu.py linkcheck      the hybrid image (tools/display_link.py) against the original
  python3 -I tools/equiv_display_emu.py abicheck       call sites that rely on registers a recreated callee does not return
The image is read from build/FT-710_DISPLAY_V0108.bin (or $FT710_BUILD/...); it is never written anywhere.
"""
import argparse
import bisect
import ctypes
import mmap
import glob
import os
import random
import struct
import sys
import time

from unicorn import Uc, UcError, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED, UC_HOOK_INTR, \
    UC_PROT_ALL
from unicorn import arm_const as A

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv_m33 as E  # noqa: E402  (ELF object reader)

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'src/display')
FUNCS_TSV = os.path.join(ROOT, 'decomp/display/functions.tsv')
MODES_TSV = os.path.join(SRC, 'modes.tsv')
DATA_TSV = os.path.join(SRC, 'data_symbols.tsv')
ALIAS_TSV = os.path.join(SRC, 'aliases.tsv')
STATUS_TSV = os.path.join(SRC, 'status.tsv')

BASE = 0x20100000                  # load address of the image (docs/memory-maps.md, DISPLAY)
REGION_TABLE = 0x204286A8          # Region$$Table: 5 x {load, exec, size, handler}
DECOMPRESS = 0x20100BFC            # __decompress (Thumb)
LIBINIT_THUMB = {0x20163874: 1, 0x201638A0: 1}   # both locale initialisers are Thumb [fact: modes.tsv]
RAM = [(0x20000000, 0x20A00000), (0x60000000, 0x60A00000), (0x18000000, 0x19000000)]
MMIO = [(0x3FE00000, 0x40000000), (0xE8000000, 0xE8300000), (0xFCFE0000, 0xFD000000)]
SCRATCH_CODE = 0x21000000          # recompiled function and the sections it needs (BL reach of .text: +-32 MB)
SCRATCH_ARGS = 0x21200000          # argument buffers
STOP = 0x3F000000                  # return address
STACK_TOP, STACK_SIZE = 0x3E000000, 0x10000
BUDGET = 1000000
FULL_COMPARE = os.environ.get('EQUIV_FULL_COMPARE') == '1'
NARGS = 8
MIN_COVER = 0.5
# compared after each run: the RW data of the image (.data .bss, .data2 .bss2, the boot-info block, the uncached
# mirror with the frame buffers and .data_nc) and the argument buffers. RAM from 0x20440000: below it the hybrid
# image (tools/display_link.py) has its recreated code (0x2042BC10..0x2043FFFF), which linkcheck must not compare.
SNAP = [(0x20000000, 0x20000100), (0x20440000, 0x20A00000), (0x60000000, 0x60A00000), (SCRATCH_ARGS, SCRATCH_ARGS + 0x20000)]
# linkcheck (round 6): the hybrid image may have code in RAM2 0x20920000..0x2097FFFF (tools/display_link.py), where
# the original has nothing; RAM2 is left out of the comparison and checked to be unchanged in the hybrid run instead
RAM2, RAM2_END, RAM2_FILE_OFF = 0x20920000, 0x20980000, 0x340000
SNAP_LINK = [(0x20000000, 0x20000100), (0x20440000, RAM2), (RAM2_END, 0x20A00000), (0x60000000, 0x60A00000),
             (SCRATCH_ARGS, SCRATCH_ARGS + 0x20000)]

R_ARM_NONE, R_ARM_ABS32, R_ARM_REL32, R_ARM_CALL, R_ARM_JUMP24 = 0, 2, 3, 28, 29
R_ARM_V4BX, R_ARM_PREL31, R_ARM_MOVW_ABS_NC, R_ARM_MOVT_ABS = 40, 42, 43, 44
R_ARM_THM_CALL, R_ARM_THM_JUMP24, R_ARM_THM_JUMP19 = 10, 30, 51


def thm_branch_get(hw1, hw2, cond):
    """Offset of a 32-bit Thumb B/BL (T4) or conditional B (T3, cond=True)."""
    s_ = (hw1 >> 10) & 1
    j1, j2 = (hw2 >> 13) & 1, (hw2 >> 11) & 1
    if cond:
        v = (s_ << 20) | (j2 << 19) | (j1 << 18) | ((hw1 & 0x3F) << 12) | ((hw2 & 0x7FF) << 1)
        return v - (1 << 21) if s_ else v
    i1, i2 = 1 - (j1 ^ s_), 1 - (j2 ^ s_)
    v = (s_ << 24) | (i1 << 23) | (i2 << 22) | ((hw1 & 0x3FF) << 12) | ((hw2 & 0x7FF) << 1)
    return v - (1 << 25) if s_ else v


def thm_branch_set(hw1, hw2, d, cond):
    s_ = 1 if d < 0 else 0
    if cond:
        if not -(1 << 20) <= d < (1 << 20):
            raise ValueError('Thumb conditional branch out of range')
        hw1 = (hw1 & 0xFBC0) | (s_ << 10) | ((d >> 12) & 0x3F)
        hw2 = (hw2 & 0xD000) | (((d >> 18) & 1) << 13) | (((d >> 19) & 1) << 11) | ((d >> 1) & 0x7FF)
        return hw1, hw2
    if not -(1 << 24) <= d < (1 << 24):
        raise ValueError('Thumb branch out of range')
    i1, i2 = (d >> 23) & 1, (d >> 22) & 1
    j1, j2 = 1 - (i1 ^ s_), 1 - (i2 ^ s_)
    hw1 = (hw1 & 0xF800) | (s_ << 10) | ((d >> 12) & 0x3FF)
    hw2 = (hw2 & 0xD000) | (j1 << 13) | (j2 << 11) | ((d >> 1) & 0x7FF)
    return hw1, hw2

# NORTi service calls (uITRON 4.0, docs/code/display/boot-rtos.md section 4): number of arguments, and the index of an
# output-pointer argument the stub writes a seeded word through (None: no output). The acre_* calls take (id,
# descriptor), id 0 = choose one [fact: itron_acre_isr 0x2014F1A8 tests r0 == 0; call sites pass r0 = 0, r1 = T_CISR]
# (round 3 listed them with one argument, so the descriptor was not compared).
STUBS = {
    'itron_dly_tsk': (1, None), 'itron_tslp_tsk': (1, None), 'itron_sig_sem': (1, None), 'itron_twai_sem': (2, None),
    'itron_set_flg': (2, None), 'itron_clr_flg': (2, None), 'itron_twai_flg': (5, 3), 'itron_tloc_mtx': (2, None),
    'itron_unl_mtx': (1, None), 'itron_snd_mbx': (2, None), 'itron_trcv_mbx': (3, 1), 'itron_tsnd_mbf': (4, None),
    'itron_trcv_mbf': (3, None), 'itron_tsnd_dtq': (3, None), 'itron_trcv_dtq': (3, 1), 'itron_tget_mpf': (3, 1),
    'itron_rel_mpf': (2, None), 'itron_sta_tsk': (2, None), 'itron_act_tsk': (1, None), 'itron_iwup_tsk': (1, None),
    'itron_get_tid': (1, 0), 'itron_loc_cpu': (0, None), 'itron_unl_cpu': (0, None), 'itron_dis_dsp': (0, None),
    'itron_ena_dsp': (0, None), 'itron_get_tim': (1, None), 'itron_rot_rdq': (1, None), 'itron_chg_pri': (2, None),
    'itron_get_pri': (2, 1), 'itron_sus_tsk': (1, None), 'itron_ext_tsk': (0, None), 'itron_sta_cyc': (1, None),
    'itron_stp_cyc': (1, None), 'itron_acre_tsk': (2, None), 'itron_acre_sem': (2, None), 'itron_acre_flg': (2, None),
    'itron_acre_mbx': (2, None), 'itron_acre_mbf': (2, None), 'itron_acre_mpf': (2, None), 'itron_acre_mpl': (2, None),
    'itron_acre_mtx': (2, None), 'itron_acre_dtq': (2, None), 'itron_acre_cyc': (2, None), 'itron_acre_isr': (2, None),
    'itron_del_sem': (1, None), 'itron_del_mpf': (1, None),
}
STACK_ARG_BYTES = {}


def read_tsv(path):
    if not os.path.exists(path):
        return []
    with open(path, encoding='utf-8') as f:
        return [ln.rstrip('\n').split('\t') for ln in f if ln.strip() and not ln.startswith('#')]


def image_path():
    for d in (os.environ.get('FT710_BUILD'), os.path.join(ROOT, 'build'), '/home/user/FT-710_Firmware/build'):
        if d and os.path.exists(os.path.join(d, 'FT-710_DISPLAY_V0108.bin')):
            return os.path.join(d, 'FT-710_DISPLAY_V0108.bin')
    sys.exit('equiv_display_emu: FT-710_DISPLAY_V0108.bin not found (set FT710_BUILD to the build/ directory)')


def orig_functions():
    """Ghidra name -> (address, size, thumb) from the committed export and modes.tsv."""
    modes = {int(r[0], 16): r[3] == 'thumb' for r in read_tsv(MODES_TSV)[1:]}
    return {r[1]: (int(r[0], 16), int(r[2]), modes.get(int(r[0], 16), False)) for r in read_tsv(FUNCS_TSV)[1:]}


class Image:
    """The DISPLAY memory after __scatterload: the file at 0x20100000 and the decompressed RW regions."""

    def __init__(self, path=None):
        self.file = open(path or image_path(), 'rb').read()
        # a hybrid image with RAM2 (display_link.py): its bytes from file offset 0x340000 are what the hybrid's
        # reset_in_ram copies to 0x20920000 (startup/vectors.S, RAM2_LOAD)
        self.regions = [(BASE, self.file[:RAM2_FILE_OFF])]
        if len(self.file) > RAM2_FILE_OFF:
            self.regions.append((RAM2, self.file[RAM2_FILE_OFF:]))
        uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        for lo, hi in RAM:
            uc.mem_map(lo, hi - lo, UC_PROT_ALL)
        uc.mem_map(STOP, 0x1000, UC_PROT_ALL)
        uc.mem_map(STACK_TOP - STACK_SIZE, STACK_SIZE, UC_PROT_ALL)
        uc.mem_write(BASE, self.file)
        uc.mem_write(STOP, struct.pack('<I', 0xE320F000) * 4)   # nop
        for k in range(5):
            load, exe, size, handler = struct.unpack_from('<4I', self.file, REGION_TABLE - BASE + 16 * k)
            if handler != DECOMPRESS:
                continue     # zero-init: RAM is zero already
            for r, v in zip((A.UC_ARM_REG_R0, A.UC_ARM_REG_R1, A.UC_ARM_REG_R2), (load, exe, size)):
                uc.reg_write(r, v)
            uc.reg_write(A.UC_ARM_REG_SP, STACK_TOP - 0x100)
            uc.reg_write(A.UC_ARM_REG_LR, STOP)
            uc.emu_start(DECOMPRESS | 1, STOP, count=50000000)
            self.regions.append((exe, bytes(uc.mem_read(exe, size))))
        # the C library's locale set-up of __rt_lib_init (0x20100CB4): libspace 0x2091D530 (__rt_locale) +4 = the
        # ctype table from 0x20163874(0, 0) + 1, +0xC = 0x201638A0(0, 0) [fact: 0x20100CB4]; without it tolower and
        # everything using the ctype table read through a NULL pointer. (The C++ constructors __rt_lib_init runs next
        # are not run: they touch peripherals.)
        locale = 0x2091D530
        words = []
        for fn in (0x20163874, 0x201638A0):
            for r in (A.UC_ARM_REG_R0, A.UC_ARM_REG_R1):
                uc.reg_write(r, 0)
            uc.reg_write(A.UC_ARM_REG_SP, STACK_TOP - 0x100)
            uc.reg_write(A.UC_ARM_REG_LR, STOP)
            uc.emu_start(fn | LIBINIT_THUMB.get(fn, 0), STOP, count=100000)
            words.append(uc.reg_read(A.UC_ARM_REG_R0))
        self.regions.append((locale + 4, struct.pack('<I', (words[0] + 1) & 0xFFFFFFFF)))
        self.regions.append((locale + 0xC, struct.pack('<I', words[1])))

    def read(self, addr, n):
        for lo, data in self.regions:
            if lo <= addr and addr + n <= lo + len(data):
                return data[addr - lo:addr - lo + n]
        return None


class Resolver:
    def __init__(self, img):
        self.img = img
        self.funcs = orig_functions()
        self.alias = {r[0]: r[1] for r in read_tsv(ALIAS_TSV)[1:]}
        rows = read_tsv(DATA_TSV)[1:]
        self.data = {r[0]: int(r[1], 16) for r in rows}
        # data the trials do not randomise: tables the image sets up before main (column fill = keep)
        self.keep = {int(r[1], 16) for r in rows if len(r) > 3 and r[3] == 'keep'}
        self.by_addr = {a: (n, s, t) for n, (a, s, t) in self.funcs.items()}

    def func(self, name):
        """(address, thumb) of the original function a recreated name stands for, or None."""
        n = self.alias.get(name, name)
        if n == '-':
            return None
        if n.startswith('0x'):
            a = int(n, 16)
            return a, self.by_addr.get(a, (None, 0, False))[2]
        if n not in self.funcs and n != name:
            n = name         # an alias to a Ghidra name a re-export renamed (round 7: vdc5_config): the name itself
        if n in self.funcs:
            a, _, t = self.funcs[n]
            return a, t
        return None


def sext(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


class Linker:
    """Place a function section and the sections of its object it needs at scratch addresses; resolve relocations."""

    def __init__(self, res):
        self.res = res
        self.next = SCRATCH_CODE
        self.placed = {}
        self.blobs = []

    def alloc(self, n, align=4):
        addr = (self.next + align - 1) & ~(align - 1)
        self.next = addr + n + 4
        return addr

    def veneer(self, target):
        """ARM veneer for a tail branch to a Thumb function: ldr pc, [pc, #-4]; .word target (interworking load)."""
        a = self.alloc(8)
        self.blobs.append([a, bytearray(struct.pack('<II', 0xE51FF004, target))])
        return a

    def place(self, obj, shndx, at=None):
        """Place a section (at a given address, or at the next free scratch address) and resolve its relocations."""
        key = (obj.path, shndx)
        if key in self.placed:
            return self.placed[key]
        sec = obj.secs[shndx]
        data = bytearray(obj.section_data(shndx))
        addr = at if at is not None else self.alloc(len(data), max(4, sec['sh_addralign']))
        self.placed[key] = addr
        blob = [addr, data]
        self.blobs.append(blob)
        for r in obj.relocs.get(shndx, []):
            self.apply(obj, addr, data, r)
        return addr

    def target(self, obj, r, at=0):
        """(address with the Thumb bit for Thumb functions, is_function) of a relocation's symbol (+ at for section
        symbols)."""
        name, styp, ssec, sval, sshndx = obj.sym_info(r['r_info_sym'])
        res = self.res
        if styp == 'STT_SECTION':
            fn = E.section_function_name(obj, sshndx, at)
            if fn and ssec.startswith('.text'):
                f = res.func(fn)
                if f:
                    return f[0] | f[1], True
                return self.place(obj, sshndx) + at, True
            key = f'{os.path.basename(obj.path)}:{ssec}'
            if key in res.data:
                return res.data[key] + at, False
            return self.place(obj, sshndx) + at, False
        if styp == 'STT_FUNC' or (styp == 'STT_NOTYPE' and not isinstance(sshndx, int)):
            f = res.func(name)
            if f:
                return f[0] | f[1], True
            if isinstance(sshndx, int):
                return self.place(obj, sshndx) + sval, True
            if styp == 'STT_FUNC' or name not in res.data:
                raise KeyError(f'no address for {name} (add it to src/display/aliases.tsv or data_symbols.tsv)')
        if name in res.data:
            return res.data[name], False
        if isinstance(sshndx, int):
            return self.place(obj, sshndx) + sval, False
        raise KeyError(f'no address for data symbol {name} (add it to src/display/data_symbols.tsv)')

    @staticmethod
    def is_text(obj, r):
        _, _, ssec, _, _ = obj.sym_info(r['r_info_sym'])
        return bool(ssec) and ssec.startswith('.text')

    def apply(self, obj, base, data, r):
        o, typ = r['r_offset'], r['r_info_type']
        pc = base + o
        _, styp, *_ = obj.sym_info(r['r_info_sym'])
        if typ in (R_ARM_CALL, R_ARM_JUMP24):
            ins = struct.unpack_from('<I', data, o)[0]
            addend = sext(ins & 0xFFFFFF, 24) << 2
            t, _ = self.target(obj, r, addend + 8 if styp == 'STT_SECTION' else 0)
            cond = ins >> 28
            if t & 1 and typ == R_ARM_CALL and cond in (0xE, 0xF):      # bl or blx to Thumb: blx
                d = (t & ~1) - (pc + 8)
                ins = 0xFA000000 | (((d >> 1) & 1) << 24) | ((d >> 2) & 0xFFFFFF)
            elif cond == 0xF:                                           # blx to A32: bl
                d = t - (pc + 8)
                ins = 0xEB000000 | ((d >> 2) & 0xFFFFFF)
            else:
                if t & 1:
                    t = self.veneer(t)
                d = t - (pc + 8)
                ins = (ins & 0xFF000000) | ((d >> 2) & 0xFFFFFF)
                if (ins & 0x0F000000) == 0x0A000000 and typ == R_ARM_CALL:   # bl
                    ins |= 0x01000000
            struct.pack_into('<I', data, o, ins)
        elif typ in (R_ARM_ABS32, R_ARM_REL32):
            addend = sext(struct.unpack_from('<I', data, o)[0], 32)
            if styp == 'STT_SECTION':
                v, _ = self.target(obj, r, addend & ~1 if self.is_text(obj, r) else addend)
            else:
                t, _ = self.target(obj, r)
                v = t + addend
            if typ == R_ARM_REL32:
                v -= pc
            struct.pack_into('<I', data, o, v & 0xFFFFFFFF)
        elif typ in (R_ARM_MOVW_ABS_NC, R_ARM_MOVT_ABS):
            ins = struct.unpack_from('<I', data, o)[0]
            addend = sext(((ins >> 4) & 0xF000) | (ins & 0xFFF), 16)
            if styp == 'STT_SECTION':
                v, _ = self.target(obj, r, addend)
            else:
                t, _ = self.target(obj, r)
                v = t + addend
            v = (v >> 16) if typ == R_ARM_MOVT_ABS else v
            v &= 0xFFFF
            ins = (ins & 0xFFF0F000) | ((v & 0xF000) << 4) | (v & 0xFFF)
            struct.pack_into('<I', data, o, ins)
        elif typ in (R_ARM_THM_CALL, R_ARM_THM_JUMP24, R_ARM_THM_JUMP19):
            hw1, hw2 = struct.unpack_from('<HH', data, o)
            cond = typ == R_ARM_THM_JUMP19
            addend = thm_branch_get(hw1, hw2, cond)
            t, _ = self.target(obj, r, addend + 4 if styp == 'STT_SECTION' else 0)
            if not t & 1 and typ == R_ARM_THM_CALL:           # to A32: BLX, offset from Align(PC, 4)
                d = t - ((pc + 4) & ~3)
                hw1, hw2 = thm_branch_set(hw1, hw2, d, False)
                hw2 &= ~0x1000
            elif not t & 1:
                raise ValueError('Thumb tail branch to an A32 function (needs a veneer)')
            else:
                d = (t & ~1) - (pc + 4)
                hw1, hw2 = thm_branch_set(hw1, hw2, d, cond)
                if typ == R_ARM_THM_CALL:
                    hw2 |= 0x1000
            struct.pack_into('<HH', data, o, hw1, hw2)
        elif typ in (R_ARM_NONE, R_ARM_V4BX, R_ARM_PREL31):
            pass
        else:
            raise ValueError(f'relocation type {typ} not supported by the DISPLAY emulation linker')


def in_ranges(a, ranges):
    return any(lo <= a < hi for lo, hi in ranges)


SCTLR = (15, 0, 0, 1, 0, 0, 0)   # cp, is64, sec, crn, crm, opc1, opc2
RSPI_FLAGS = 0x20800418     # rspi_rx_done[5], rspi_tx_done[5] (src/display/data_symbols.tsv)
RSPI_BASE, RSPI_STRIDE = 0xE800C800, 0x800      # RSPI0..4 (drivers/rspi.c RSPI_BASE)


# Start memory, copy-on-write (round 8). Each trial used to map 36 MB of RAM, write the image's regions into it and
# read the compared ranges back through mem_read: about 15 ms per run, 70 % of a check's time. Now every worker
# builds the start contents of each RAM range once per image (a memfd), and each run maps it MAP_PRIVATE and hands
# the pages to Unicorn (mem_map_ptr): only the pages a trial writes are copied, and the snapshots are slices of the
# mapping. The memory each run starts from and what is compared are unchanged.
_TEMPLATES = {}


def ram_template(img):
    """[(lo, hi, fd)] for the RAM ranges, holding img's regions (cached per image object)."""
    key = id(img)
    if key not in _TEMPLATES:
        out = []
        for lo, hi in RAM:
            fd = os.memfd_create(f'equiv_display_{lo:08x}')
            os.ftruncate(fd, hi - lo)
            for a, data in img.regions:
                if lo <= a < hi:
                    os.pwrite(fd, data[:hi - a], a - lo)
            out.append((lo, hi, fd))
        _TEMPLATES[key] = (img, out)   # img kept alive, so that its id stays unique
    return _TEMPLATES[key][1]


PAGE = 0x1000
_PAGEMAP = None


def dirty_pages(ptr, mlo, lo, hi):
    """Page addresses in lo..hi (inside the mapping of mlo at host address ptr) that the run wrote: present and
    anonymous, or swapped out, in /proc/self/pagemap (bit 63 present, 62 swapped, 61 file page or shared). A page of
    a MAP_PRIVATE memfd mapping is a file page until its first write copies it (copy-on-write), so every written page
    is listed. A page that was only read can be listed too (the shared zero page reads as not a file page): it is
    then compared like a written one, so a false entry costs time, never a missed difference."""
    global _PAGEMAP
    if _PAGEMAP is None:
        _PAGEMAP = open('/proc/self/pagemap', 'rb', buffering=0)
    first = (ptr + lo - mlo) // PAGE
    n = (hi - lo + PAGE - 1) // PAGE
    ent = os.pread(_PAGEMAP.fileno(), 8 * n, 8 * first)
    out = []
    for k, e in enumerate(struct.unpack(f'<{n}Q', ent)):
        if e >> 62 & 1 or (e >> 63 & 1 and not e >> 61 & 1):
            out.append(lo + k * PAGE)
    return out


class WrittenPages:
    """A compared range after a run (round 9): the pages written in it ({page address: bytes}) and the template it
    started from (memfd, at address mlo), which holds every other page."""
    __slots__ = ('lo', 'hi', 'pages', 'fd', 'mlo')

    def __init__(self, lo, hi, pages, fd, mlo):
        self.lo, self.hi, self.pages, self.fd, self.mlo = lo, hi, pages, fd, mlo

    def page(self, p):
        got = self.pages.get(p)
        if got is None:
            got = os.pread(self.fd, PAGE, p - self.mlo)
        return got[:min(PAGE, self.hi - p)]

    def full(self):
        return b''.join(self.page(p) for p in range(self.lo, self.hi, PAGE))


_TDIFF = {}


def template_differences(x, y):
    """Pages of x's range where the two runs' start templates differ (none for two runs of one image; for
    linkcheck the hybrid's own bytes, e.g. RAM2 when it is compared), computed once per worker."""
    if x.fd == y.fd:
        return set()
    key = (x.fd, y.fd, x.lo, x.hi)
    if key not in _TDIFF:
        a = os.pread(x.fd, x.hi - x.lo, x.lo - x.mlo)
        b = os.pread(y.fd, y.hi - y.lo, y.lo - y.mlo)
        _TDIFF[key] = {x.lo + k for k in range(0, len(a), PAGE) if a[k:k + PAGE] != b[k:k + PAGE]}
    return _TDIFF[key]


def first_difference(x, y):
    """Address of the first byte in which two compared ranges differ, or None. Bytes or WrittenPages: a page that
    neither run wrote holds its template on both sides (for linkcheck the two images' templates, which are equal
    outside the hybrid's code), so it is compared only when the templates differ there; pages written by either
    run are compared byte for byte."""
    if not isinstance(x, WrittenPages) or not isinstance(y, WrittenPages):
        x = x.full() if isinstance(x, WrittenPages) else x
        y = y.full() if isinstance(y, WrittenPages) else y
        if x == y:
            return None
        return next(k for k in range(len(x)) if x[k] != y[k])
    pages = sorted(set(x.pages) | set(y.pages) | template_differences(x, y))
    for p in pages:
        a, b = x.page(p), y.page(p)
        if a != b:
            return p - x.lo + next(k for k in range(len(a)) if a[k] != b[k])
    return None


class Run:
    def __init__(self, img, blobs, stub_addrs, seed, fill, args, cover=None):
        self.img = img
        self.maps = []
        for lo, hi, fd in ram_template(img):
            mm = mmap.mmap(fd, hi - lo, flags=mmap.MAP_PRIVATE, prot=mmap.PROT_READ | mmap.PROT_WRITE)
            self.maps.append((lo, hi, mm, ctypes.addressof(ctypes.c_char.from_buffer(mm))))
        self.uc = uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        try:
            uc.ctl_set_cpu_model(A.UC_CPU_ARM_CORTEX_A9)
        except Exception:
            pass
        for lo, hi, mm, ptr in self.maps:
            uc.mem_map_ptr(lo, hi - lo, UC_PROT_ALL, ptr)
        for lo, hi in [(SCRATCH_CODE, SCRATCH_CODE + 0x400000), (STOP, STOP + 0x1000), (STACK_TOP - STACK_SIZE, STACK_TOP)]:
            uc.mem_map(lo, hi - lo, UC_PROT_ALL)
        for lo, hi in MMIO:
            uc.mmio_map(lo, hi - lo, self.on_mmio_read, lo, self.on_mmio_write, lo)
        uc.mem_write(STOP, struct.pack('<I', 0xE320F000) * 4)
        for a, data in blobs:
            uc.mem_write(a, bytes(data))
        for a, data in fill:
            uc.mem_write(a, data)
        for a, data in args.get('buffers', []):
            uc.mem_write(a, data)
        self.rng = random.Random(seed)
        self.stub_addrs = stub_addrs
        self.mmio, self.calls, self.end = [], [], None
        self.rspi_sprie = {}
        for a in list(stub_addrs) + [STOP]:
            uc.hook_add(UC_HOOK_CODE, self.on_code, begin=a, end=a)
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self.on_unmapped)
        uc.hook_add(UC_HOOK_INTR, self.on_intr)
        # coverage: one code hook per static block leader of the original, removed at its first hit (a block hook
        # would call back into Python on every loop iteration)
        self.blocks = set()
        self.cover_hooks = {}
        for a in cover or ():
            self.cover_hooks[a] = uc.hook_add(UC_HOOK_CODE, self.on_leader, begin=a, end=a)
        self.regs = args['regs']
        # a preset may bias chosen registers (round 7): address -> values a read returns, drawn from the run's rng
        self.mmio_pick = args.get('mmio', {})
        # or return a fixed sequence, cyclically (round 8: a whole CMD6 status block through SD_BUF0)
        self.mmio_seq = {a: [v, 0] for a, v in args.get('mmio_seq', {}).items()}
        self.snap = SNAP

    def on_code(self, uc, addr, size, _):
        if addr == STOP:
            self.end = ('return',)
            uc.emu_stop()
            return
        name = self.stub_addrs.get(addr)
        if not name:
            return
        n, out = STUBS[name]
        r = [uc.reg_read(x) for x in (A.UC_ARM_REG_R0, A.UC_ARM_REG_R1, A.UC_ARM_REG_R2, A.UC_ARM_REG_R3)][:n]
        sp = uc.reg_read(A.UC_ARM_REG_SP)
        r += [struct.unpack('<I', uc.mem_read(sp + 4 * k, 4))[0] for k in range(max(0, n - 4))]
        norm = []
        for k, v in enumerate(r):
            if STACK_TOP - STACK_SIZE <= v < STACK_TOP and k == out:
                norm.append(('stack', 'out'))   # what the kernel writes there: its prior contents are not an input
            elif STACK_TOP - STACK_SIZE <= v < STACK_TOP:      # (round 7: stack garbage differed in sdhi_flag_wait)
                norm.append(('stack', bytes(uc.mem_read(v, min(STACK_ARG_BYTES.get((name, k), 4), STACK_TOP - v)))))
            else:
                norm.append(v)
        self.calls.append((name, tuple(norm)))
        if out is not None and out < len(r):
            try:
                uc.mem_write(r[out], struct.pack('<I', self.rng.getrandbits(32)))
            except UcError:
                pass
        ret = self.rng.choice([0, 0, 0, 1, 0xFFFFFFFF, 0xFFFFFFCE, 0xFFFFFFE7, self.rng.getrandbits(32)])  # E_OK, E_TMOUT (-50), E_PAR (-17)
        uc.reg_write(A.UC_ARM_REG_R0, ret)
        lr = uc.reg_read(A.UC_ARM_REG_LR)
        if lr & 1:
            uc.reg_write(A.UC_ARM_REG_CPSR, uc.reg_read(A.UC_ARM_REG_CPSR) | 0x20)
        else:
            uc.reg_write(A.UC_ARM_REG_CPSR, uc.reg_read(A.UC_ARM_REG_CPSR) & ~0x20)
        uc.reg_write(A.UC_ARM_REG_PC, lr & ~1)

    def on_leader(self, uc, addr, size, _):
        self.blocks.add(addr)
        h = self.cover_hooks.pop(addr, None)
        if h is not None:
            uc.hook_del(h)

    def on_mmio_read(self, uc, offset, size, base):
        seq = self.mmio_seq.get(base + offset)
        if seq:
            v = seq[0][seq[1] % len(seq[0])]
            seq[1] += 1
            self.mmio.append(('r', base + offset, size, v))
            return v
        pick = self.mmio_pick.get(base + offset)
        v = self.rng.choice(pick) if pick else self.rng.getrandbits(8 * size)
        self.mmio.append(('r', base + offset, size, v))
        return v

    def on_mmio_write(self, uc, offset, size, value, base):
        value &= (1 << (8 * size)) - 1
        self.mmio.append(('w', base + offset, size, value))
        a = base + offset
        if RSPI_BASE <= a < RSPI_BASE + 5 * RSPI_STRIDE:
            self.rspi_irq(uc, (a - RSPI_BASE) // RSPI_STRIDE, (a - RSPI_BASE) % RSPI_STRIDE, value)

    def rspi_irq(self, uc, ch, reg, value):
        """The RSPI interrupts as the ISRs see them (round 8). Nothing raised them before, so every wait for an ISR's
        flag spun until the budget ran out (the read bursts: 120 of 200 trials inconclusive, half of a status run's
        time). Model, from the hardware's side: the transmit buffer is always empty, so SPCR written with SPTIE
        (bit 5) raises SPTI at once and its ISR sets rspi_tx_done[ch] (0x2080041D + ch); a write of SPDR while SPRIE
        (bit 7) was last written set clocks a frame in, raises SPRI and its ISR sets rspi_rx_done[ch] (0x20800418 +
        ch) [fact: the ISRs of drivers/rspi.c, the flag addresses in data_symbols.tsv]. Only the flags are modelled:
        the ISRs' own register writes (SPTIE/SPRIE off, RXRST) and rspi_rx_count are left out, the same for both
        runs. Open: the receive trigger level (the ISR fires after SPBFCR.RXTRG bytes, not after the first); would be
        settled by counting the clocked bytes against the trigger table 0x20800434."""
        if reg == 0:                  # SPCR
            self.rspi_sprie[ch] = bool(value & 0x80)
            if value & 0x20:
                uc.mem_write(RSPI_FLAGS + 5 + ch, b'\x01')
        elif reg == 4 and self.rspi_sprie.get(ch):      # SPDR
            uc.mem_write(RSPI_FLAGS + ch, b'\x01')

    def on_intr(self, uc, intno, _):
        """An SVC enters the image's own SVC_Handler as the CPU would: SVC mode with IRQs masked, LR_svc = the return
        address, SPSR_svc = the caller's CPSR, PC = vector 0x20100008. The kernel's interrupt masking
        (knl_int_disable: svc #0 with r0 = knl_psr_set_i) works only this way. Any other exception ends the run."""
        if intno != 2:
            self.end = ('fault', f'exception {intno}')
            uc.emu_stop()
            return
        cpsr = uc.reg_read(A.UC_ARM_REG_CPSR)
        pc = uc.reg_read(A.UC_ARM_REG_PC)
        uc.reg_write(A.UC_ARM_REG_CPSR, (cpsr & ~0x3F) | 0x93)
        uc.reg_write(A.UC_ARM_REG_SPSR, cpsr)
        uc.reg_write(A.UC_ARM_REG_LR, pc | (1 if cpsr & 0x20 else 0))
        uc.reg_write(A.UC_ARM_REG_PC, BASE + 8)

    def on_unmapped(self, uc, access, addr, size, value, _):
        self.end = ('fault', access)
        return False

    def go(self, entry, thumb, ret_size=4, budget=BUDGET):
        """Run from entry; ret_size 1/2/4 (r0), 8 (r0:r1), 16 (r0..r3, the 64-bit divisions) or None (void)."""
        uc = self.uc
        uc.reg_write(A.UC_ARM_REG_CPSR, 0x1D3)    # SVC mode: its own stack for the SVC entries
        uc.reg_write(A.UC_ARM_REG_SP, STACK_TOP - 0x8000)
        uc.reg_write(A.UC_ARM_REG_CPSR, 0x1DF)    # SYS mode (as main and the tasks), IRQ and FIQ masked, ARM state
        for reg, v in zip((A.UC_ARM_REG_R0, A.UC_ARM_REG_R1, A.UC_ARM_REG_R2, A.UC_ARM_REG_R3), self.regs):
            uc.reg_write(reg, v & 0xFFFFFFFF)
        uc.reg_write(A.UC_ARM_REG_SP, STACK_TOP - 0x100)
        uc.mem_write(STACK_TOP - 0x100, struct.pack('<4I', *[v & 0xFFFFFFFF for v in self.regs[4:8]]))
        uc.reg_write(A.UC_ARM_REG_LR, STOP)
        try:
            uc.emu_start(entry | (1 if thumb else 0), 0, count=budget)
        except UcError as e:
            if self.end is None:
                self.end = ('fault', str(e))
        if self.end is None:
            self.end = ('budget',)
        ret = None
        if self.end[0] == 'return' and ret_size:
            regs = (A.UC_ARM_REG_R0, A.UC_ARM_REG_R1, A.UC_ARM_REG_R2, A.UC_ARM_REG_R3)[:max(1, ret_size // 4)]
            ret = tuple(uc.reg_read(x) for x in regs)
            if ret_size < 4:
                ret = (ret[0] & ((1 << (8 * ret_size)) - 1),)
        try:
            sctlr = uc.reg_read(A.UC_ARM_REG_CP_REG, SCTLR)
        except Exception:
            sctlr = None
        snap = tuple(self.written(lo, hi) for lo, hi in self.snap)
        return {'end': self.end[0], 'ret': ret, 'mmio': self.mmio, 'calls': self.calls, 'writes': snap,
                'sctlr': sctlr, 'ram2': self.written(RAM2, RAM2_END) if self.snap is SNAP_LINK else None}

    def written(self, lo, hi):
        """The contents of lo..hi after the run (round 9): inside a copy-on-write RAM mapping a WrittenPages, the
        pages the run wrote (the anonymous pages of the private mapping, /proc/self/pagemap) with the start
        template for the rest; elsewhere (argument buffers) the bytes themselves. Round 8 copied every compared range
        whole (16 MB per run); the comparison is the same, see compare()."""
        for mlo, mhi, mm, ptr in self.maps:
            if mlo <= lo and hi <= mhi:
                fd = next(f for a, b, f in ram_template(self.img) if a == mlo)
                return WrittenPages(lo, hi, {p: mm[p - mlo:p - mlo + PAGE] for p in dirty_pages(ptr, mlo, lo, hi)},
                                    fd, mlo)
        return self.read(lo, hi - lo)

    def read(self, a, n):
        """n bytes at a: a slice of the copy-on-write mapping, or through Unicorn outside it."""
        for lo, hi, mm, _ in self.maps:
            if lo <= a and a + n <= hi:
                return mm[a - lo:a - lo + n]
        return bytes(self.uc.mem_read(a, n))

    def close(self):
        """Unicorn first, then the mappings it points into."""
        self.uc = None
        for _, _, mm, _ in self.maps:
            try:
                mm.close()
            except BufferError:
                pass       # an exported pointer still alive (ctypes): the mapping goes with the object
        self.maps = []

    def __del__(self):
        self.close()


def printf_like(rng):
    out = []
    for _ in range(rng.randrange(1, 6)):
        if rng.random() < 0.3:
            out.append(rng.choice('ab Z\r\n:'))
            continue
        c = '%' + ''.join(rng.choice('-+ #0') for _ in range(rng.randrange(0, 3)))
        c += rng.choice(['', '', str(rng.randrange(0, 20))])
        c += rng.choice(['', '', '.' + str(rng.randrange(0, 12))])
        c += rng.choice(['', '', '', 'l', 'h'])
        c += rng.choice('diuxXcd%')
        out.append(c)
    return ''.join(out)


def draw_args(rng):
    regs, bufs = [], []
    for k in range(NARGS):
        kind = rng.random()
        if kind < 0.35:
            regs.append(rng.choice([0, 1, 2, 3, 4, 7, 8, 10, 11, 16, 0x40, 0xFF, 0x100, 0x4005, 0x7FFF, 0x8000]))
        elif kind < 0.55:
            regs.append(rng.getrandbits(rng.choice([8, 16, 32])))
        else:
            a = SCRATCH_ARGS + 0x2000 * k
            x = rng.random()
            if x < 0.1:
                data = printf_like(rng).encode() + b'\0' + bytes(rng.getrandbits(8) for _ in range(64))
            elif x < 0.5:
                s = ''.join(rng.choice('abcdefXYZ0123456789 ._-/\\:') for _ in range(rng.randrange(0, 24)))
                data = s.encode() + b'\0' + bytes(rng.getrandbits(8) for _ in range(64))
            else:
                data = bytes(rng.getrandbits(8) for _ in range(0x400))
            bufs.append((a, data))
            regs.append(a)
    return {'regs': regs, 'buffers': bufs}


def compare(a, b, snap=SNAP):
    for k in ('end', 'ret', 'mmio', 'calls', 'sctlr'):
        if a[k] != b[k]:
            return k
    for (lo, hi), x, y in zip(snap, a['writes'], b['writes']):    # written pages per range (round 9)
        i = first_difference(x, y)
        if i is not None:
            return f'memory at {lo + i:#x}'
    if FULL_COMPARE:      # EQUIV_FULL_COMPARE=1: the round-8 comparison of the whole ranges as well, which must agree
        for (lo, hi), x, y in zip(snap, a['writes'], b['writes']):
            fx = x.full() if isinstance(x, WrittenPages) else x
            fy = y.full() if isinstance(y, WrittenPages) else y
            assert fx == fy, f'written-page comparison missed a difference in {lo:#x}..{hi:#x}'
    return None


_BLOCKS = {}
CONDS = {'eq', 'ne', 'cs', 'hs', 'cc', 'lo', 'mi', 'pl', 'vs', 'vc', 'hi', 'ls', 'ge', 'lt', 'gt', 'le'}


def block_starts(img, addr, size, thumb):
    """Basic-block leaders of the original function: entry, branch targets inside it, the instruction after a
    conditional branch (static scan)."""
    import capstone
    key = (addr, size, thumb)
    if key in _BLOCKS:
        return _BLOCKS[key]
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    code = img.read(addr, size) or b''
    leaders, pc, end = {addr}, addr, addr + len(code)
    step = 2 if thumb else 4
    while pc < end:
        ins = next(md.disasm(code[pc - addr:pc - addr + 4], pc), None)
        if ins is None:
            pc += step
            continue
        m = ins.mnemonic.split('.')[0]
        isb = m == 'b' or (m[0] == 'b' and m[1:] in CONDS)      # b, b<cond> (not bl<cond>, bic, bx...)
        cond = (isb and m != 'b') or m in ('cbz', 'cbnz') or (m.startswith('bx') and m[2:] in CONDS) or \
            (m[:3] in ('pop', 'ldm') and m[3:5] in CONDS and 'pc' in ins.op_str)
        if (isb or m in ('cbz', 'cbnz')) and '#0x' in ins.op_str:
            t = int(ins.op_str.split('#')[-1], 16)
            if addr <= t < end:
                leaders.add(t)
        if cond:
            leaders.add(pc + ins.size)
        pc += ins.size
    _BLOCKS[key] = leaders
    return leaders


def cp15_ops(code, addr, thumb):
    """Set of the coprocessor operations (mcr/mrc with coprocessor, opc1, CRn, CRm, opc2; the register left out) in
    code. Unicorn executes cache and TLB maintenance as no-ops, so the emulation cannot tell DCIMVAC from DCCIMVAC; this
    static comparison does (T24 round 3)."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    md.skipdata = True
    ops = set()
    for ins in md.disasm(code, addr):
        m = ins.mnemonic.split('.')[0]
        if m[:3] in ('mcr', 'mrc'):
            f = [x.strip() for x in ins.op_str.split(',')]
            ops.add((m[:3], f[0], f[1], f[3], f[4], f[5] if len(f) > 5 else '0'))
    return ops


_RETURNS = {}


def returns_value(obj, fname):
    """Return size of fname from its object's DWARF (equiv_m33_emu.returns_value's rule: None for void, else the
    size in bytes, 4 without DWARF or a size). Round 9: one walk of the DIEs per object, cached; the per-function
    walk made linkcheck's start-up take 80 s in every worker (_ret_sizes over 640 functions)."""
    if obj.path not in _RETURNS:
        out = {}
        if obj.elf.has_dwarf_info():
            for cu in obj.elf.get_dwarf_info().iter_CUs():
                for die in cu.iter_DIEs():
                    if die.tag != 'DW_TAG_subprogram' or 'DW_AT_name' not in die.attributes or \
                            'DW_AT_declaration' in die.attributes:
                        continue
                    name = die.attributes['DW_AT_name'].value.decode()
                    if name in out:
                        continue
                    if 'DW_AT_type' not in die.attributes:
                        out[name] = None
                        continue
                    t = die.get_DIE_from_attribute('DW_AT_type')
                    while 'DW_AT_byte_size' not in t.attributes and 'DW_AT_type' in t.attributes:
                        t = t.get_DIE_from_attribute('DW_AT_type')
                    out[name] = t.attributes['DW_AT_byte_size'].value if 'DW_AT_byte_size' in t.attributes else 4
        _RETURNS[obj.path] = out
    return _RETURNS[obj.path].get(fname, 4)


def two_strings(rng, args, sized=False):
    """r0, r1 point at two related strings of ASCII and bytes >= 0x80 (the second a copy of the first with a changed, upper-cased or cut tail, or
    the first's prefix), in buffers at any alignment, so that the compare functions run their equal and unequal paths
    and the word loops of the armcc versions; r2 a count for the n-variants."""
    base = ''.join(rng.choice('abcxyzABCXYZ019 _.\x81\xe9\xff') for _ in range(rng.randrange(0, 40)))
    k = rng.random()
    if k < 0.25:
        other = base
    elif k < 0.5:
        other = base.upper() if rng.random() < 0.5 else base.lower()
    elif k < 0.75:
        cut = rng.randrange(0, len(base) + 1)
        other = base[:cut] + ''.join(rng.choice('abcXYZ0') for _ in range(rng.randrange(0, 5)))
    else:
        other = base[:rng.randrange(0, len(base) + 1)]
    if rng.random() < 0.5:
        base, other = other, base
    bufs = []
    for i, txt in enumerate((base, other)):
        a = SCRATCH_ARGS + 0x2000 * i + rng.choice([0, 0, 1, 2, 3])
        bufs.append((a, txt.encode('latin-1', 'replace') + b'\0' + bytes(rng.getrandbits(8) for _ in range(16))))
        args['regs'][i] = a
    if sized:
        args['regs'][2] = rng.choice([0, 1, 3, 4, 5, 8, len(base), len(base) + 1, 100])
    args['buffers'] = [b for b in args['buffers'] if not (SCRATCH_ARGS <= b[0] < SCRATCH_ARGS + 0x4000)] + bufs
    return []


def copy_fill(rng, args, kind):
    """The AEABI copy and fill entries: r0 a destination and (copies) r1 a source buffer of 0x400 random bytes, at any
    alignment (word-aligned for the ...4 variants), a size of 0..300 bytes; memset gets (dst, n, c)."""
    aligned = kind.endswith('4')
    dst = SCRATCH_ARGS + (0 if aligned else rng.randrange(4))
    src = SCRATCH_ARGS + 0x2000 + (0 if aligned else rng.randrange(4))
    n = rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 15, 16, 31, 32, 33, 63, 64, 127, 128, 129, 200, 300])
    if aligned:
        n &= ~3
    args['buffers'] = [(SCRATCH_ARGS, bytes(rng.getrandbits(8) for _ in range(0x400))),
                       (SCRATCH_ARGS + 0x2000, bytes(rng.getrandbits(8) for _ in range(0x400)))]
    regs = args['regs']
    if kind.startswith('memcpy'):
        regs[0], regs[1], regs[2] = dst, src, n
    elif kind == 'memset':
        regs[0], regs[1], regs[2] = dst, n, rng.getrandbits(32)
    else:
        regs[0], regs[1] = dst, n
    return []


def flat_l1(rng, args):
    """The L1 table 0x2044C000 as mmu_l1_table_init leaves it (flat 1-MB sections, 0x10C02 + i << 20), so that the
    MMU that mmu_enable turns on translates VA = PA and the run can return."""
    return [(0x2044C000, b''.join(struct.pack('<I', 0x10C02 + (i << 20)) for i in range(4096)))]


def gpio_args(rng, args, ptr=False):
    """(port, pin, func, mode) as the GPIO helpers take them: port 0..11 (sometimes 12..15), pin 0..15, alternative
    function 0..9, mode 0..4; gpio_cfg_mask takes (Pn address or 0, mask | value << 16, flag)."""
    regs = args['regs']
    port = rng.choice(list(range(12)) * 3 + [12, 15])
    if ptr:
        regs[0] = rng.choice([0, 0xFCFE3000 + 4 * min(port, 11)])
        regs[1] = rng.getrandbits(16) | (rng.choice([0, 0, 1, rng.getrandbits(16)]) << 16)
        regs[2] = rng.choice([0, 1])
    else:
        regs[0], regs[1], regs[2], regs[3] = port, rng.randrange(16), rng.randrange(10), rng.randrange(5)
    return []


def u64(rng):
    """A 64-bit operand of random length (0..64 significant bits), sometimes a power of two or all ones."""
    k = rng.random()
    if k < 0.1:
        return rng.choice([0, 1, 2, 3, 10, 0xFFFFFFFF, 1 << 32, (1 << 64) - 1, 1 << 63])
    if k < 0.2:
        return 1 << rng.randrange(64)
    return rng.getrandbits(rng.randrange(1, 65))


def div64_args(rng, args):
    """(numerator r0:r1, denominator r2:r3) for __aeabi_uldivmod / __aeabi_ldivmod: lengths drawn independently, so
    that every path (denominator 0, longer than the numerator, 32-bit, the reciprocal paths) is reached."""
    n, d = u64(rng), u64(rng)
    if rng.random() < 0.2:
        d = rng.getrandbits(rng.randrange(1, 9)) or 1
    regs = args['regs']
    regs[0], regs[1], regs[2], regs[3] = n & 0xFFFFFFFF, n >> 32, d & 0xFFFFFFFF, d >> 32
    return []


def riic_args(rng, args, shape):
    """The RIIC driver's arguments by shape: ch 0..3 (sometimes out of range), then 'bn' (64-byte buffer, count
    0..6: R_RIIC_Read/Write), 'vm' (byte, mode 0..2), 'c' (condition 0..3), 'mb' (mode 0..5, out buffer), 'v' (byte).
    The interrupt flags 0x20800454..0x2080045F are set non-zero (the transfer functions spin on them; the interrupts
    are not emulated), with the transmit counter after them random."""
    regs = args['regs']
    regs[0] = rng.choice([0, 1, 2, 3] * 4 + [4, 0xFFFFFFFF])
    buf = SCRATCH_ARGS + 0x2000
    args['buffers'] = [b for b in args['buffers'] if b[0] != buf] + [(buf, bytes(rng.getrandbits(8) for _ in range(64)))]
    if shape == 'bn':
        regs[1], regs[2] = buf, rng.choice([0, 1, 2, 3, 4, 5, 6, rng.randrange(8)])
    elif shape == 'vm':
        regs[1], regs[2] = rng.getrandbits(8), rng.choice([0, 1, 1, 0, 2])
    elif shape == 'c':
        regs[1] = rng.choice([0, 1, 2, 3])
    elif shape == 'mb':
        regs[1], regs[2] = rng.choice([0, 1, 2, 3, 4, 5]), buf
    elif shape == 'v':
        regs[1] = rng.getrandbits(8)
    return [(0x20800454, bytes(rng.randrange(1, 256) for _ in range(12)) + bytes(rng.getrandbits(8) for _ in range(16)))]


SCIF_OBJS = {0x208DA1E0: (0xE8008800, 0x20165764), 0x208DAA30: (0xE8009000, 0x2016578C),
             0x208DB280: (0xE8009800, 0x201657B4)}   # object: (registers, TXI descriptor; RXI = TXI + 0x14) [fact: scifN_get]


def scif_obj(rng, regs_blk=None, txi=None):
    """A valid SCIF UART object (src/display/include/scif.h): the vtable 0x2042803C, a register block (or, rarely,
    none yet), ring indices that are equal, adjacent, wrapped or random (so the full and empty cases run), random
    ring bytes and counters, the TXI/RXI descriptors, an event flag id or 0."""
    if regs_blk is None:
        regs_blk, txi = SCIF_OBJS[rng.choice(list(SCIF_OBJS))]
    o = bytearray(rng.getrandbits(8) for _ in range(0x850))

    def idx_pair():
        a = rng.randrange(0x400)
        k = rng.random()
        b = a if k < 0.25 else (a + 1) & 0x3FF if k < 0.4 else (a - 1) & 0x3FF if k < 0.55 else \
            (a + 0x3FE) & 0x3FF if k < 0.65 else rng.randrange(0x400)
        return a, b
    rd, wr = idx_pair()
    trd, twr = idx_pair()
    struct.pack_into('<IIHH', o, 0, 0x2042803C, 0 if rng.random() < 0.1 else regs_blk, rd, wr)
    struct.pack_into('<HH', o, 0x40C, trd, twr)
    struct.pack_into('<III', o, 0x810, txi + 0x14, txi, rng.choice([0, 0, 1, 3, 7]))
    return bytes(o)


def scif_args(rng, args, kind):
    """kind 'obj': r0 = a SCIF object in the argument area (and a 64-byte buffer in r1, a count 0..40 in r2, a
    retry count in r3, baud / bits / parity / stop for scif_open); 'glob': the three global objects valid."""
    regs = args['regs']
    fill = []
    if kind == 'obj':
        a = SCRATCH_ARGS
        args['buffers'] = [b for b in args['buffers'] if not (SCRATCH_ARGS <= b[0] < SCRATCH_ARGS + 0x4000)]
        args['buffers'] += [(a, scif_obj(rng)), (a + 0x2000, bytes(rng.getrandbits(8) for _ in range(64)))]
        regs[0], regs[1], regs[2] = a, a + 0x2000, rng.choice([0, 1, 2, 5, 16, 40, rng.randrange(1100)])
        regs[3] = rng.choice([0, 1, 2, 5])
        if rng.random() < 0.5:     # scif_open / scif_start: (baud, bits, parity, stop)
            regs[1] = rng.choice([9600, 38400, 115200, 345600, 460800, 1200])
            regs[2], regs[3] = rng.choice([7, 8]), rng.choice([0, 1, 2, 3])
            regs[4] = rng.choice([1, 2, 0x81, 0x80, 0])
    for o, (rb, txi) in SCIF_OBJS.items():
        fill.append((o, scif_obj(rng, rb, txi)))
    return fill


SFLASH_DEV = 0x20810D90


def sflash_args(rng, args, kind):
    """The serial-flash driver (src/display/drivers/sflash.c): the device object 0x20810D90 valid (SPIBSC0 base, one or
    two chips, a state 0..3, mostly no error, a last command among RDSR/RDID/0x70/other), the partial-page count
    0x208000A0 below a page; arguments by kind: 'obj' (object, 64-byte buffer, count 0..20, keep), 'dev' (a device
    command 'r'/'e'/'p'/'d'/'b' or data, length 0..12), 'xip' (flash offset, buffer, count 0..40), 'bar' (no
    progress bar, offset, size up to 3 blocks), 'id' (a block index)."""
    regs = args['regs']
    dual = rng.choice([0, 0, 1])
    o = bytearray(rng.getrandbits(8) for _ in range(0x2C))
    struct.pack_into('<IIIIIII', o, 0, 0x3FEFA000, dual, rng.choice([0, 0, 1, 2, 3, 4]), rng.getrandbits(20),
                     rng.choice([0] * 6 + [1]), rng.choice([0, 1]), rng.choice([0, 1]))
    o[0x28] = rng.choice([0x05, 0x9F, 0x70, 0x02, 0x0B])
    fill = [(SFLASH_DEV, bytes(o)), (0x208000A0, struct.pack('<I', rng.choice([0, 0, 1, 100, 255]))),
            (0x20810DBC, bytes(rng.getrandbits(8) for _ in range(512)))]
    buf = SCRATCH_ARGS + 0x2000
    args['buffers'] = [b for b in args['buffers'] if b[0] != buf] + [(buf, bytes(rng.getrandbits(8) for _ in range(64)))]
    if kind == 'obj':
        regs[0], regs[1], regs[2], regs[3] = SFLASH_DEV, buf, rng.choice([0, 1, 2, 3, 4, 5, 6, 8, 9, 13, 20]), rng.choice([0, 1])
    elif kind == 'reg':           # (object, offset) or (object, value, offset)
        regs[0], regs[1], regs[2] = SFLASH_DEV, rng.choice(range(0, 0x4C, 4)), rng.choice(range(0, 0x4C, 4))
    elif kind == 'dev':
        c = bytes([rng.choice(b'repdbx'), rng.choice(b'01pr')]) + bytes(rng.getrandbits(8) for _ in range(30))
        args['buffers'] = [b for b in args['buffers'] if b[0] != buf] + [(buf, c)]
        regs[0], regs[1] = buf, rng.choice([0, 1, 2, 5, 6, 7, 8, 12])
    elif kind == 'xip':
        regs[0], regs[1], regs[2] = rng.getrandbits(16), buf, rng.choice([0, 1, 2, 7, 40])
    elif kind == 'bar':
        regs[0], regs[1], regs[2] = 0, rng.getrandbits(20), rng.choice([0, 1, 0x10000, 0x10001, 0x30000])
    elif kind == 'id':
        regs[0] = rng.choice(list(range(8)) + [0x83, 0x84, 0x87, 0x88, 200])
    return fill


VDC5_STUB_FN = 0x2013FDE4      # sdhi_stub_2013fde4: an empty A32 function (bx lr), a harmless callback


def vdc5_param(rng, a, b):
    """A VDC5 parameter block at a (0x80 bytes): bytes 0..3 (the enum fields stay in range: the driver indexes tables
    with them, and an out-of-range index reads whatever lies next to the table, which differs between the two builds), each aligned word of the first 0x30
    bytes NULL or a pointer to the second block b (itself bytes 0..3 in its lower half, NULL or pointers back into it in its upper half), so that the nested parameter pointers of the r_vdc5 structures (lvds, dly, ext_sig, outctrl[], width_read_fb,
    gr_grc, alpha and calibration blocks) are valid or NULL."""
    p = bytearray(rng.choice([0, 0, 1, 1, 2, 3]) for _ in range(0x80))
    for o in range(0, 0x30, 4):
        k = rng.random()
        if k < 0.4:
            struct.pack_into('<I', p, o, 0)
        else:
            struct.pack_into('<I', p, o, b + rng.choice([0, 0, 0x10, 0x20, 0x40]))
    q = bytearray(rng.choice([0, 0, 1, 1, 2, 3]) for _ in range(0x100))
    for o in range(0x80, 0x100, 4):     # second-level pointers only in the upper half: the blocks the first level
        if rng.random() < 0.4:          # points at (b + 0..0x7F) keep small bytes in their fields
            struct.pack_into('<I', q, o, rng.choice([0, b + 0x40, b + 0x60]))
    return [(a, bytes(p)), (b, bytes(q))]


def vdc5_args(rng, args):
    """The VDC5 driver (src/display/drivers/vdc5_*.c): r0 a channel 0/1, r1..r3 and two stack words each a small value
    (layer ids -1..9, types 0..22, on/off) or a parameter block (vdc5_param); the shared resource and layer states 0
    or 1 (the API checks them against 1), the callbacks NULL or an empty function."""
    regs = args['regs']
    regs[0] = rng.choice([0, 1])
    bufs = []
    for k in range(1, 6):
        if rng.random() < 0.45:
            regs[k] = rng.choice([0xFFFFFFFF, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 16, 19, 22])
        else:
            a = SCRATCH_ARGS + 0x2000 * k
            bufs += vdc5_param(rng, a, a + 0x1000)
    args['buffers'] = bufs
    bit = lambda n: bytes(rng.choice([0, 1, 1]) for _ in range(n))
    cbs = b''.join(struct.pack('<I', rng.choice([0, VDC5_STUB_FN])) for _ in range(46))
    return [(0x2080040C, bit(12)), (0x208DCE04, bit(36)), (0x208DCC0C, cbs)]


def vdc5_regs_args(rng, args, table, stride):
    """(parameter block, register-address block of channel 0 or 1): the TCON helpers (output control 0x20166710) and
    the external-input helper (input control 0x20165CA0) take the driver's register table as second argument."""
    fill = vdc5_args(rng, args)
    args['regs'][0] = SCRATCH_ARGS + 0x2000
    args['buffers'] += vdc5_param(rng, SCRATCH_ARGS + 0x2000, SCRATCH_ARGS + 0x3000)
    args['regs'][1] = table + stride * rng.choice([0, 1])
    return fill


def vdc5_table_args(rng, args, k, tables, on_arg=None):
    """VDC5 helpers that take one entry of a register-address table (round 6): argument k is one of the given
    addresses (an entry of the image's table, as the callers pass), the other pointer arguments parameter blocks;
    argument on_arg, if any, 0 or 1."""
    fill = vdc5_args(rng, args)
    for j in range(k):
        if j != on_arg:
            at = SCRATCH_ARGS + 0x2000 * (j + 1)
            args['buffers'] = [b for b in args['buffers'] if not at <= b[0] < at + 0x2000]
            args['buffers'] += vdc5_param(rng, at, at + 0x1000)
            args['regs'][j] = at
    if on_arg is not None:
        args['regs'][on_arg] = rng.choice([0, 1])
    args['regs'][k] = rng.choice(tables)
    return fill


def vdc5_formats(rng):
    """The graphics format of every layer in the shared parameters (vdc5_shrd_graphics 0x208DCD2C, 12 x 0x12 bytes,
    gr_format at +2), drawn from the formats the driver knows, so that the format switches are reached."""
    blk = bytearray(rng.getrandbits(8) for _ in range(12 * 0x12))
    for k in range(12):
        blk[0x12 * k + 2] = rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 10, 11])
    return [(0x208DCD2C, bytes(blk))]


def vdc5_clut_args(rng, args, k):
    """(..., vdc5_clut_t at argument k): color_num 1..16 and a table of random colours (the generic block would put
    a pointer into color_num and copy for ever), the layer formats drawn."""
    fill = vdc5_args(rng, args) + vdc5_formats(rng)
    at = SCRATCH_ARGS + 0x2000 * (k + 1)
    args['buffers'] = [b for b in args['buffers'] if not at <= b[0] < at + 0x2000]
    args['buffers'] += [(at, struct.pack('<II', rng.choice([1, 1, 2, 2, 3, 16]), at + 0x100)),
                        (at + 0x100, bytes(rng.getrandbits(8) for _ in range(64)))]
    args['regs'][k] = at
    if k == 2:
        args['regs'][1] = rng.randrange(6)
    return fill


# helper -> (argument index of the register table, the addresses it is called with, on/off argument)
_QLTY = [0x20166130 + 0x34 * i for i in range(4)]
_SYNTH = [0x201662C0 + 0x58 * i for i in range(12)]
_GAMMA = [0x201667D0 + 0x130 * c + o for c in range(2) for o in (0x8, 0x48, 0x6C, 0xAC, 0xD0, 0x110)]
VDC5_TABLE_ARGS = {
    'vdc5_set_enhancement_sharpness': (2, _QLTY, 0), 'vdc5_set_enhancement_lti': (2, _QLTY, 0),
    'vdc5_set_alpha_rect_area': (1, _SYNTH, None),
    'vdc5_set_clut': (1, [0xFCFF6000, 0xFCFF6400, 0xFCFF6800, 0xFCFF6C00, 0xFCFF7000, 0xFCFF8000, 0xFCFF8400,
                          0xFCFF8800, 0xFCFF8C00, 0xFCFF9000], None),
    'vdc5_set_gamma_gain': (1, _GAMMA, None), 'vdc5_set_gamma_threshold': (1, _GAMMA, None),
    'vdc5_set_scaling_down': (2, [0x20165CE0 + 0xB8 * i for i in range(6)], 1),
    'vdc5_set_scaling_up': (6, [0x20165CE0 + 0xB8 * i for i in range(6)], None),
}


def vdc5_shrd_blocks(rng):
    """The shared parameters (include/vdc5.h) with their enum fields in range: common 0x208DCCC4 (2 x 0x10: clock
    selects, colour space, input and sync selects, cascade, und_sel 0/1), scaling 0x208DCCE4 (6 x 0xC: writing mode
    0..5, interlace and colour space 0/1, buffer size), graphics 0x208DCD2C (12 x 0x12: line direction 0/1, frame
    select 0..3, format 0..11, colour space and adj_sel 0/1, area and buffer size random halfwords)."""
    small = lambda n: rng.randrange(n)
    com = bytearray(rng.getrandbits(8) for _ in range(0x20))
    for c in range(2):
        for o in range(7):
            com[0x10 * c + o] = small(2)
    sca = bytearray(rng.getrandbits(8) for _ in range(6 * 0xC))
    for k in range(6):
        sca[0xC * k], sca[0xC * k + 1], sca[0xC * k + 2] = small(6), small(2), small(2)
    gra = bytearray(rng.getrandbits(8) for _ in range(12 * 0x12))
    for k in range(12):
        o = 0x12 * k
        gra[o:o + 5] = bytes([small(2), small(4), rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]), small(2), small(2)])
    return [(0x208DCCC4, bytes(com)), (0x208DCCE4, bytes(sca)), (0x208DCD2C, bytes(gra))]


def vdc5_read_args(rng, args, kind):
    """(ch, graphics 0..5, parameter) of the read side (round 7): vdc5_read_t (line direction, IMR inversion, burst
    0/1, frame select 0..3, address and line offset random, format 0..11 with 8 = YCbCr422 often, swaps 0..7, area
    random halfwords) for vdc5_reg_read_data_control; vdc5_read_chg_t (each pointer NULL or a block; display select int8
    -1..3 and a few other negatives) for the change; (ch, graphics 0/1, frame select 0..3, enlargement 0/1) for vdc5_change_graphics_vin; the
    shared parameters in range."""
    fill = vdc5_args(rng, args) + vdc5_shrd_blocks(rng)
    regs = args['regs']
    regs[1] = rng.randrange(6)
    a = SCRATCH_ARGS + 0x4000
    r = bytearray(rng.getrandbits(8) for _ in range(0x40))
    r[0:4] = bytes([rng.randrange(2), rng.randrange(4), rng.randrange(2), rng.randrange(2)])
    r[0x10:0x14] = bytes([rng.randrange(2), rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10, 11]), rng.randrange(8),
                          rng.randrange(8)])
    for k in range(4):              # the change block: four pointers, NULL or into the block's upper half
        if rng.random() < 0.3:
            struct.pack_into('<I', r, 0x20 + 4 * k, 0)
        else:
            struct.pack_into('<I', r, 0x20 + 4 * k, rng.getrandbits(32) if k == 0 else a + 0x30)
    r[0x30] = rng.choice([0xFF, 0, 1, 2, 3, 0xFE, 0x85])     # -1 = keep; other negative values sign-extend
    args['buffers'] = [b for b in args['buffers'] if not a <= b[0] < a + 0x2000] + [(a, bytes(r))]
    regs[2] = a + 0x20 if kind == 'chg' else a
    if kind == 'vin':
        regs[1], regs[2], regs[3] = rng.randrange(2), rng.randrange(4), rng.randrange(2)
    return fill




def rspi_args(rng, args, kind):
    """The RSPI driver core (round 7). The flags start set (1, sometimes 0); since round 8 Run.rspi_irq raises the
    interrupts the waits are for, so a transfer runs on past its first access. The arguments: ch
    0..4 (5 now and then: the checks), a buffer, an access count 0..2, a trigger 0..7 or 0xFF (keep); the bursts
    (bytes 0, 1, 2, 4, fewer-than-trigger 0/1); rspi_hw_config's mode 0..2, rspi_hw_config_master's SPBR, BRDV 0..3
    and loopback 0/1; rspi_fifo_reset a channel base."""
    regs = args['regs']
    regs[0] = rng.choice([0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 7])
    flags = bytes(rng.choice([1, 1, 1, 1, 0]) for _ in range(10))
    if kind == 'xfer':
        regs[2] = rng.choice([0, 1, 1, 1, 2])
        regs[3] = rng.choice([0, 1, 2, 3, 4, 7, 8, 0xFF, 0xFF, 0x100, 0xFFFFFFFF])
    elif kind == 'burst':
        regs[0], regs[1] = rng.choice([0, 1, 1, 2, 4, 4]), rng.choice([0, 1, 1, 2])
    elif kind == 'config':
        regs[1] = rng.choice([0, 0, 1, 1, 2])
        regs[0] = rng.choice([0, 1, 2, 3, 4, 4, 5, 6])
    elif kind == 'master':
        regs[0], regs[2], regs[3] = rng.randrange(5), rng.randrange(4), rng.randrange(2)
    elif kind == 'base':
        regs[0] = 0xE800C800 + 0x800 * rng.randrange(5)
    # SPDCR keeps its value for the whole trial (round 8): nothing in these functions writes it, and a fresh random
    # SPLW at every read gave a burst another access size than rspi_read_pio had chosen, so `left -= 4` passed
    # zero and the loop ran to the budget. A burst gets an access size that divides its byte count (its callers'
    # contract: rspi_read_pio checks the trigger against the size); its other trials were inconclusive anyway.
    args.setdefault('mmio', {})
    for ch in range(5):
        v = rng.getrandbits(8)
        if kind == 'burst':
            n = regs[0]
            sizes = [0, 1, 2, 3] if n % 4 == 0 else [0, 1, 2] if n % 2 == 0 else [0, 1]
            v = v & 0x9F | rng.choice(sizes) << 5
        args['mmio'][RSPI_BASE + RSPI_STRIDE * ch + 0xB] = [v]
    return [(RSPI_FLAGS, flags)]


def dmac_args(rng, args):
    """The DMAC set-ups (round 7): the five end callbacks (0x20808AA0) an empty function, so that the ISRs that call
    them return; the arguments as drawn (addresses and counts only go to registers)."""
    return [(0x20808AA0, struct.pack('<5I', *[VDC5_STUB_FN] * 5))]


def sd_card_args(rng, args, kind):
    """The SDHI command layer (round 7): the card context (0x300 bytes: card type +0x2C6 0 or 1, addressing +0x2C0 2
    or 0) last, after (card address, buffer, blocks 0..3) for the sector transfers and ops, (length, blocks) for
    CMD16, (response type 0..8) for the response copy, (buffer, length) for the PIO read; the DMA interrupt states
    of sdhi_dma_open (0x20808B78: registered -1 or 1, a GIC id 0..0x25F)."""
    regs = args['regs']
    ctx = SCRATCH_ARGS + 0xC000
    c = bytearray(rng.getrandbits(8) for _ in range(0x300))
    struct.pack_into('<HH', c, 0x2C0, rng.choice([0, 2, 2]), 0)
    struct.pack_into('<H', c, 0x2C6, rng.choice([0, 0, 1]))
    buf = SCRATCH_ARGS + 0xE000
    args['buffers'] = [b for b in args['buffers'] if not ctx <= b[0] < ctx + 0x4000]
    args['buffers'] += [(ctx, bytes(c)), (buf, bytes(rng.getrandbits(8) for _ in range(0x800)))]
    n = rng.choice([0, 1, 1, 2, 2, 3])
    if kind == 'xfer':
        regs[0], regs[1], regs[2], regs[3] = rng.getrandbits(32), buf, n, ctx
    elif kind == 'cmd16':
        regs[0], regs[1], regs[2] = rng.choice([0x200, 8, 64]), n, ctx
    elif kind == 'rsp':
        regs[0], regs[1] = rng.randrange(9), ctx
    elif kind == 'ctx':
        regs[0] = ctx
    elif kind == 'pio':
        regs[0], regs[1] = buf, rng.choice([0, 3, 4, 16, 512])
    # SD_INFO1 with the response and access end bits, SD_INFO2 without error bits now and then, so that commands
    # complete and the transfers run on (with random status they almost never got past CMD16); R1 (RSP01:RSP00)
    # mostly without error bits
    args["mmio"] = {0xE804E01C: [0xFFFF, 0x0005, rng.getrandbits(16)], 0xE804E01E: [0x0000, 0x0300, 0x2000, 0x0040],
                    0xE804E00C: [0x0900, 0, rng.getrandbits(16)], 0xE804E00E: [0, 0, rng.getrandbits(16)]}
    irq = b''.join(struct.pack('<IIbxH', VDC5_STUB_FN, rng.randrange(0x260), rng.choice([-1, 1]), rng.getrandbits(16))
                   for _ in range(2))
    return [(0x20808B78, irq)]


SDHI_OPS = 0x20420564       # the SDHI operation table (src/display/drivers/sdhi.c)
_FILE = None


def _image_bytes(addr, n):
    """n bytes of the original image file at addr (constant data a preset copies, e.g. an operation table)."""
    global _FILE
    if _FILE is None:
        _FILE = open(image_path(), 'rb').read()
    return _FILE[addr - BASE:addr - BASE + n]


def switch_status_words(rng):
    """A CMD6 status block (64 bytes, byte 0 the most significant) as the 16 SD_BUF0 words the PIO read stores low
    byte first (round 8): the maximum current mostly at most 800 mA, group 1 and 3 support bits, the selected
    functions of groups 1, 3, 4 among the ones the switches ask for (and 0xF), version 0 or 1, busy bits rarely."""
    b = bytearray(rng.getrandbits(8) for _ in range(64))
    ma = rng.choice([100, 200, 800, 801, 0x0320, rng.getrandbits(16)])
    b[0], b[1] = ma >> 8, ma & 0xFF
    b[9] |= rng.choice([0, 1, 1])
    b[13] = rng.choice([0, 2, 6, 0x0E, 0x1E, 0x16, rng.getrandbits(8)])
    b[15] = rng.choice([0, 3, 3, 0xF, rng.getrandbits(4)]) << 4 | rng.choice([0, 0, 0xF, rng.getrandbits(4)])
    b[16] = b[16] & 0xF0 | rng.choice([1, 2, 3, 4, 3, 4, 0xF, rng.getrandbits(4)])
    b[17] = rng.choice([0, 1, 1])
    for k in (23, 25, 29):
        b[k] = rng.choice([0, 0, 0, rng.getrandbits(8)])
    return [struct.unpack_from('<I', b, 4 * k)[0] for k in range(16)]


def sd_handle_args(rng, args, kind, fname_kind=None):
    """The SD card layer (round 7): a handle {card context, the image's SDHI operation table} with the context's RCA,
    addressing and card type (0 or 1) set, the SDHI status registers biased as for sd_card_args; (status out,
    handle) for CMD13; a 16-byte CSD for the checks; an MBR geometry block (sectors per track 0/32/63, heads
    0/16/255, start and count small or past the CHS limit, FAT type 12/16/32/other) for the partition helpers."""
    fill = sd_card_args(rng, args, 'none')
    regs = args['regs']
    ctx, h = SCRATCH_ARGS + 0xC000, SCRATCH_ARGS + 0xB000
    out = SCRATCH_ARGS + 0xB100
    ops = SDHI_OPS
    if kind in ('handle', 'arg', 'sect') and rng.random() < 0.6:
        # a target that offers what this host's table refuses (round 8): slots 6 (driver strength) and 7 (UHS
        # function) answer 0 through sdhi_soft_reset 0x20140440 (SOFT_RST off/on, returns 0), so that the switch
        # functions' accepting paths run; the card layer takes the table from the handle, so it is an input
        ops = SCRATCH_ARGS + 0xB300
        tbl = bytearray(_image_bytes(SDHI_OPS, 26 * 4))
        for slot in (6, 7):
            if rng.random() < 0.9:
                struct.pack_into('<I', tbl, 4 * slot, 0x20140440)
        args['buffers'] += [(ops, bytes(tbl))]
    args['buffers'] += [(h, struct.pack('<II', ctx, ops)), (out, bytes(16))]
    if kind == 'handle':
        regs[0] = h
    elif kind == 'status':
        regs[0], regs[1] = out, h
    elif kind == 'csd':
        csd = bytearray(rng.getrandbits(8) for _ in range(16))
        if rng.random() < 0.5:      # often a plausible CSD, so that the later tests are reached
            csd[0] &= 0x4F
            csd[1] &= 0x7F
            csd[3] &= 0x7F
            csd[5] = (csd[5] & 0xF0) | rng.choice([9, 10, 11, 12])
            csd[12] &= 0xE3 | (rng.randrange(8) << 2)
        args['buffers'] += [(out, bytes(csd))]
        regs[0] = out
    elif kind in ('rca', 'arg', 'on'):     # (RCA / CMD6 argument / clock on, handle) (round 8)
        regs[0] = {'rca': rng.choice([0, 0, 1, rng.getrandbits(16)]),
                   'arg': rng.choice([0x00FFFFFF, 0x00FFFFF1, 0x80FFFFF1, rng.getrandbits(32)]),
                   'on': rng.choice([0, 1, 1, 2])}[kind]
        regs[1] = h
    elif kind == 'sel':                    # (RCA, block length, blocks, handle)
        regs[0], regs[1], regs[2], regs[3] = rng.choice([0, 1, rng.getrandbits(16)]), rng.choice([8, 64, 512]), \
            rng.choice([1, 2]), h
    elif kind == 'sect':                   # (sector, buffer, count, handle)
        regs[0], regs[1], regs[2], regs[3] = rng.getrandbits(rng.choice([8, 32])), SCRATCH_ARGS + 0xE000, \
            rng.choice([0, 1, 1, 2]), h
    elif kind == 'vol':                    # (volume {+0x14 sectors, +0x30 first}, sector, buffer, count, handle)
        vol = SCRATCH_ARGS + 0xB200
        size = rng.choice([0, 1, 100, rng.getrandbits(32)])
        args['buffers'] += [(vol, bytes(0x14) + struct.pack('<I', size) + bytes(0x18) +
                             struct.pack('<I', rng.getrandbits(rng.choice([8, 32]))))]
        regs[0], regs[1], regs[2], regs[3] = vol, rng.choice([0, 1, 99, rng.getrandbits(32)]), \
            SCRATCH_ARGS + 0xE000, rng.choice([0, 1, 2])
        regs[4] = h
    elif kind == 'cid':                    # a 16-byte CID: random, or zero runs that the check looks for
        cid = bytearray(rng.getrandbits(8) for _ in range(16))
        for k in range(rng.choice([0, 0, 3, 3, 15, 16])):
            cid[k] = 0
        if rng.random() < 0.3:
            cid[0] = rng.getrandbits(8)
        args['buffers'] += [(out, bytes(cid))]
        regs[0] = out
    elif kind in ('fmt', 'card', 'nset'):    # the format code (round 8): the context's format parameters and CSD
        c = bytearray(dict(args['buffers'])[ctx])
        csd = bytearray(rng.getrandbits(8) for _ in range(16))
        csd[0] = rng.choice([0x00, 0x40, 0x40, 0x80]) | csd[0] & 0x3F
        if rng.random() < 0.5:
            csd[7], csd[8], csd[9] = 0, rng.choice([0x0F, 0x3B, 0xED]), rng.getrandbits(8)   # 2..32 GB
        c[0x201:0x211] = csd
        typ = rng.choice([12, 16, 32, 32, 0, 0x40])
        struct.pack_into('<HHIIIHHbxxxIHxxIII', c, 0x2C8, rng.choice([0, 63]), rng.choice([0, 255]),
                         rng.choice([0x2000, 0x8000, 1, 0]), rng.getrandbits(rng.choice([8, 16])),
                         rng.getrandbits(rng.choice([16, 24, 32])), rng.choice([1, 2, 8, 64]), rng.choice([512, 512, 0x400]),
                         typ, rng.choice([1, 2, 3]), rng.choice([1, 32, 0x2000]), rng.getrandbits(16), 0, 0)
        struct.pack_into('<II', c, 0x2F4, rng.choice([0, 1, 100]), 0)
        args['buffers'] = [b for b in args['buffers'] if b[0] != ctx] + [(ctx, bytes(c))]
        regs[0] = {'fmt': h, 'card': ctx, 'nset': rng.getrandbits(16)}[kind]
        regs[1] = ctx
    elif kind in ('drv', 'drvop', 'idx', 'task'):   # the drive code (round 8): a drive record that points to the handle
        drv = SCRATCH_ARGS + 0xA000
        d = bytearray(rng.getrandbits(8) for _ in range(0x74))
        d[0x10] = rng.choice([0x20, 0x10, 0x0C])
        struct.pack_into('<I', d, 0x14, rng.choice([0, 100, rng.getrandbits(32)]))
        struct.pack_into('<I', d, 0x24, h if rng.random() < 0.85 else 0)
        struct.pack_into('<I', d, 0x30, rng.getrandbits(rng.choice([8, 20])))
        struct.pack_into('<H', d, 0x3A, rng.choice([1, 6]))
        d[0x68] = rng.getrandbits(8)
        args['buffers'] += [(drv, bytes(d))]
        if kind == 'drv':
            regs[0], regs[1] = drv, h
        elif kind == 'drvop':          # (drive, op, sector, buffer, [count, handle])
            regs[0], regs[1], regs[2], regs[3] = drv, rng.randrange(11), rng.getrandbits(rng.choice([4, 32])), \
                SCRATCH_ARGS + 0xE000
            regs[4], regs[5] = rng.choice([0, 1, 2]), h
        elif kind == 'task':           # (drive, index 0)
            regs[0], regs[1] = drv, 0
            fill.append((0x20808B58, struct.pack('<I', rng.choice([0, 0, 5]))))
        else:                          # (index 0, monitor state)
            regs[0], regs[1] = 0, rng.choice([0, 0x40, 0xC0, rng.getrandbits(8)])
        fill.append((0x20808B60, struct.pack('<III', drv, rng.choice([0, 1]), rng.choice([0, 1]))))
    if kind in ('handle', 'rca', 'arg', 'on', 'sel', 'sect', 'vol', 'fmt', 'drv', 'drvop', 'idx', 'task'):
        # the card set-up (round 8). The responses (RSP00, RSP01): R1 in the transfer state (0x0900) or standby, few
        # error bits; for the initialisation also CMD8's echo 0x1AA and the OCR busy, CCS and S18A bits (bit 31 is
        # OUT_OF_RANGE in R1, so the two cannot share one list)
        if fname_kind == 'init':
            args['mmio'][0xE804E00C] = [0x01AA, 0x01AA, 0x0900, 0, rng.getrandbits(16)]
            args['mmio'][0xE804E00E] = [0, 0, 0x8000, 0xC000, 0xC100]
        else:
            args["mmio"][0xE804E00C] = [0x0900] * 20 + [0x0600, 0x0B00, 0x0C00, rng.getrandbits(16)]
            args["mmio"][0xE804E00E] = [0] * 30 + [rng.getrandbits(16)]
        # SD_INFO2: buffer ready (0x300) more often than the timeout error 0x40, which ends a command layer call
        # after a few register reads otherwise
        args['mmio'][0xE804E01E] = [0x0300, 0x0300, 0x0300, 0x2000, 0x0000, 0x0040]
        # SD_BUF0: four CMD6 status blocks in turn (switch_status_words), or random words
        if rng.random() < 0.7:
            args['mmio_seq'] = {0xE804E030: sum((switch_status_words(rng) for _ in range(4)), [])}
        else:
            args['mmio'][0xE804E030] = [rng.getrandbits(32) for _ in range(4)]
        # SD_CD (PPR11 bit 4, sd_card_detect 0x20101D94): a card in for the whole trial most of the time; the card
        # check takes 32 samples, so random bits made every trial "no card"
        pin = rng.getrandbits(16)
        args['mmio'][0xFCFE322C] = [pin & ~0x10] if rng.random() < 0.8 else [pin & ~0x10, pin | 0x10]
    elif kind == 'geom':
        g = bytearray(0x18)
        lim = 0xFB0400
        struct.pack_into('<HHIIIIB', g, 0, rng.choice([0, 32, 63, 63]), rng.choice([0, 16, 255, 255]), 0,
                         rng.choice([0, 63, rng.getrandbits(20), lim - 1, lim, rng.getrandbits(32)]),
                         rng.choice([1, 0x7FA7, 0x7FA8, 0xFFFF, 0x10000, rng.getrandbits(24), lim, rng.getrandbits(32)]),
                         0, rng.choice([12, 16, 32, 32, 0, 33]))
        args['buffers'] += [(out, bytes(g))]
        regs[0], regs[1] = out, out + 0x80
    return fill


def mode_args(rng, args, k):
    """vdc5_args with argument k a display mode 0/1 (the GUI's timing tables have two entries)."""
    fill = vdc5_args(rng, args)
    args['regs'][k] = rng.choice([0, 1])
    return fill


def ctype_arg(rng, args):
    """tolower: c in the C library's domain, EOF or an unsigned char (outside it the table read lands anywhere, e.g.
    in the hybrid image's recreated code, which differs from the image's bytes)."""
    args['regs'][0] = rng.choice([0xFFFFFFFF, rng.randrange(256), rng.randrange(0x41, 0x5B), rng.randrange(0x61, 0x7B)])
    return []


def vdc5_output_args(rng, args):
    """(ch, vdc5_output_t) for the display-output calls: TCON half/offset, outctrl[8] each NULL or a 10-byte timing
    (start, width, mode 0..3, reference 0/1, polarity 0/1, pin -1..6, edge 0/1), and the enum bytes at +0x24..+0x2A
    in range (edge, endian, swap 0/1; format 0..3; clock 0..2; scan 0/1; phase 0..3), a random background colour.
    The generic block (vdc5_param) puts pointers into the word at +0x24, i.e. out_format 0x21, and the driver then
    indexes its 4-entry dither table with it: past the table the image reads its stack and the GCC build whatever
    follows its .rodata (T24 round 5 follow-up, seen with GCC 13)."""
    fill = vdc5_args(rng, args)
    a, t = SCRATCH_ARGS + 0x2000, SCRATCH_ARGS + 0x3000
    o = bytearray(0x34)
    struct.pack_into('<HH', o, 0, rng.getrandbits(11), rng.getrandbits(11))
    timings = bytearray()
    for k in range(8):
        tim = struct.pack('<HHBBBbB', rng.getrandbits(11), rng.getrandbits(11), rng.randrange(4), rng.randrange(2),
                          rng.randrange(2), rng.choice([-1, 0, 1, 2, 3, 4, 5, 6]), rng.randrange(2)) + b'\0'
        timings += tim + bytes(6)
        struct.pack_into('<I', o, 4 + 4 * k, 0 if rng.random() < 0.3 else t + 0x10 * k)
    o[0x24:0x2B] = bytes([rng.randrange(2), rng.randrange(2), rng.randrange(2), rng.randrange(4), rng.randrange(3),
                          rng.randrange(2), rng.randrange(4)])
    struct.pack_into('<I', o, 0x2C, rng.getrandbits(32))
    args['buffers'] = [b for b in args['buffers'] if not a <= b[0] < a + 0x2000] + [(a, bytes(o)), (t, bytes(timings))]
    args['regs'][1] = a
    return fill


def preset_for(fname):
    if fname in PRESETS:
        return PRESETS[fname]
    if fname in ('vdc5_reg_display_output', 'r_vdc5_display_output'):
        return vdc5_output_args
    if fname == 'tolower':
        return ctype_arg
    if fname in ('vdc5_sync_setup', 'vdc5_output_setup', 'lvds_pll_cfg'):
        return lambda rng, args: mode_args(rng, args, 1)
    if fname == 'dvi_tcon_cfg_ch1':
        return lambda rng, args: mode_args(rng, args, 0)
    if fname.startswith('vdc5_tcon_'):
        return lambda rng, args: vdc5_regs_args(rng, args, 0x20166710, 0x60)
    if fname == 'vdc5_set_color_matrix':      # (mode, offsets, gains, matrix registers 0x20166200 [ch][module])
        def f(rng, args):
            fill = vdc5_args(rng, args)
            for k, at in ((1, SCRATCH_ARGS + 0x2000), (2, SCRATCH_ARGS + 0x4000)):
                args['buffers'] += vdc5_param(rng, at, at + 0x1000)
                args['regs'][k] = at
            args['regs'][0] = rng.randrange(4)
            args['regs'][3] = 0x20166200 + 0x60 * rng.randrange(2) + 0x20 * rng.randrange(3)
            return fill
        return f
    if fname == 'vdc5_set_video_external_input':
        return lambda rng, args: vdc5_regs_args(rng, args, 0x20165CA0, 0x20)
    if fname == 'vdc5_set_clut':
        def c(rng, args):
            fill = vdc5_clut_args(rng, args, 0)
            args['regs'][1] = rng.choice(VDC5_TABLE_ARGS['vdc5_set_clut'][1])
            return fill
        return c
    if fname == 'vdc5_reg_image_enhancement':   # (ch, block 0/1, on, sharp, on, lti, area): blocks or NULL
        def e(rng, args):
            fill = vdc5_args(rng, args)
            regs = args['regs']
            regs[1], regs[2], regs[4] = rng.randrange(2), rng.randrange(2), rng.randrange(2)
            for k in (3, 5, 6):
                at = SCRATCH_ARGS + 0x2000 * k
                args['buffers'] = [b for b in args['buffers'] if not at <= b[0] < at + 0x2000]
                if rng.random() < 0.25:
                    regs[k] = 0
                else:
                    args['buffers'] += vdc5_param(rng, at, at + 0x1000)
                    regs[k] = at
            return fill
        return e
    if fname == 'vdc5_reg_clut':
        return lambda rng, args: vdc5_clut_args(rng, args, 2)
    if fname in ('vdc5_reg_chromakey', 'vdc5_reg_alpha_blending_rect'):
        return lambda rng, args: vdc5_args(rng, args) + vdc5_formats(rng)
    if fname == 'vdc5_set_scaling_up':     # (fb, area, folding, interlace, writing mode 0..5, direction, scaler)
        def u(rng, args):
            fill = vdc5_table_args(rng, args, 6, VDC5_TABLE_ARGS[fname][1])
            regs = args['regs']
            regs[2], regs[3], regs[4], regs[5] = rng.randrange(2), rng.randrange(2), rng.randrange(6), rng.randrange(2)
            return fill
        return u
    if fname == 'vdc5_display_start_pixel':     # (address, graphics format 0..11)
        def sp(rng, args):
            args['regs'][1] = rng.randrange(12)
            return []
        return sp
    if fname.startswith('vdc5_shrd_get_'):   # (ch, scaler or graphics index): an index of the tables, not a pointer
        def sh(rng, args):                    # (a pointer index reads anywhere, e.g. the hybrid's RAM2 code: round 6)
            fill = vdc5_args(rng, args)
            args['regs'][1] = rng.randrange(6)
            return fill
        return sh
    if fname in ('vdc5_reg_read_data_control', 'vdc5_reg_change_read_process', 'vdc5_change_graphics_vin'):
        kind = {'vdc5_reg_change_read_process': 'chg', 'vdc5_change_graphics_vin': 'vin'}.get(fname, 'read')
        return lambda rng, args: vdc5_read_args(rng, args, kind)
    if fname.startswith('dmac'):
        return dmac_args
    sd = {'sdhi_read_sectors_cmd': 'xfer', 'sdhi_write_sectors_cmd': 'xfer', 'sdhi_read_op': 'xfer',
          'sdhi_write_op': 'xfer', 'sd_cmd16_set_blocklen': 'cmd16', 'sdhi_read_response': 'rsp', 'sd_cmd12_stop': 'ctx',
          'sdhi_read_buf_pio': 'pio', 'sdhi_dma_open': 'irq', 'sdhi_open': 'irq'}.get(fname)
    if sd:
        return lambda rng, args: sd_card_args(rng, args, sd)
    sd = {'sd_cmd0_go_idle': 'handle', 'sd_cmd2_all_send_cid': 'handle', 'sd_cmd9_send_csd': 'handle',
          'sd_cmd10_send_cid': 'handle', 'sd_cmd13_send_status': 'status', 'sd_csd_check': 'csd', 'mmc_csd_check': 'csd',
          'csd_read_bl_len': 'csd', 'csd_c_size': 'csd', 'csd_c_size_mult': 'csd',
          # round 8 (drivers/sd_setup.c)
          'sd_init_v1_or_mmc': 'handle', 'sd_init_v2': 'handle', 'sd_cmd11_voltage_switch': 'handle',
          'sd_cmd3_relative_addr': 'handle', 'sd_select_card': 'handle', 'sd_acmd51_read_scr': 'handle',
          'sd_acmd6_set_bus_width': 'handle', 'sd_acmd13_read_status': 'handle', 'sd_switch_high_speed': 'handle',
          'sd_switch_uhs_speed': 'handle', 'sd_set_driver_strength': 'handle', 'sd_select_bus_speed': 'handle',
          'sd_card_identify': 'handle', 'sd_read_csd_cid': 'handle', 'sd_scr_bus_width': 'handle',
          'sd_check_card': 'handle', 'sd_cmd7_select': 'rca', 'sd_cmd6_switch_func': 'arg', 'sd_card_clock': 'on',
          'sd_selected_op': 'sel', 'sd_read_sectors': 'sect', 'sd_write_sectors': 'sect', 'sd_vol_read': 'vol',
          'sd_vol_write': 'vol', 'sd_cid_check': 'cid',
          'fat_format_clear_root': 'fmt', 'fat_format_write_fats': 'fmt', 'fat32_format_write_fsinfo': 'fmt',
          'fat_format_write_boot': 'fmt', 'fat_format_write_mbr': 'fmt', 'fat_format_volume': 'fmt',
          'fat_format_layout': 'fmt', 'sd_fat_format': 'fmt', 'sd_format_progress_dec': 'card',
          'sd_format_progress_set': 'nset', 'sd_mount_volume': 'drv', 'sd_drive_mount': 'drv',
          'sd_drive_unmount': 'drv', 'sd_drive_attach': 'drv', 'sd_driver_op': 'drvop', 'sd_card_task_start': 'task',
          'sd_card_remount': 'idx', 'sd_card_poll': 'idx', 'sd_card_unmount': 'idx',
          'sd_card_write_protected': 'idx', 'sd_clmap_prepare': 'idx'}.get(fname)
    if sd or fname.startswith('mbr_'):
        init = 'init' if fname in ('sd_init_v1_or_mmc', 'sd_init_v2', 'sd_cmd11_voltage_switch', 'sd_card_identify',
                                   'sd_cmd3_relative_addr') else None
        return lambda rng, args: sd_handle_args(rng, args, sd or 'geom', init)
    if fname.startswith('rspi'):
        kind = ('xfer' if fname in ('rspi_read', 'rspi_read_pio', 'rspi_write', 'rspi_write_pio') else
                'burst' if fname.endswith('_read_burst') else 'config' if fname == 'rspi_hw_config' else
                'master' if fname == 'rspi_hw_config_master' else 'base' if fname == 'rspi_fifo_reset' else 'ch')
        return lambda rng, args: rspi_args(rng, args, kind)
    if fname in VDC5_TABLE_ARGS:
        return lambda rng, args: vdc5_table_args(rng, args, *VDC5_TABLE_ARGS[fname])
    if fname == 'vdc5_color_conversion':      # (graphics format, colour): every case of the switch and past it
        def g(rng, args):
            args['regs'][0] = rng.randrange(13)
            return []
        return g
    if fname.startswith(('vdc5_', 'r_vdc5_')):
        return vdc5_args
    return None


# return registers the DWARF cannot tell (assembly): the 64-bit divisions return quotient r0:r1 and remainder r2:r3
RET_SIZE = {'__aeabi_uldivmod': 16, '__aeabi_ldivmod': 16, '_ll_udiv10': 16, '__rt_udiv10': 8}

PRESETS = {'mmu_enable': flat_l1, '__aeabi_uldivmod': div64_args, '__aeabi_ldivmod': div64_args, '__aeabi_memcpy': lambda r, a: copy_fill(r, a, 'memcpy'), '__aeabi_memcpy4': lambda r, a: copy_fill(r, a, 'memcpy4'),
           '__aeabi_memset': lambda r, a: copy_fill(r, a, 'memset'), '__aeabi_memclr': lambda r, a: copy_fill(r, a, 'memclr'),
           '__aeabi_memclr4': lambda r, a: copy_fill(r, a, 'memclr4')}
PRESETS.update({n: gpio_args for n in ('gpio_cfg_reset', 'gpio_cfg_out_low', 'gpio_cfg_out_high', 'gpio_cfg_input',
                                     'gpio_set_alt_func', 'gpio_cfg_alt', 'gpio_read_bit', 'gpio_read_port_bit')})
PRESETS['gpio_cfg_mask'] = lambda rng, args: gpio_args(rng, args, True)
PRESETS.update({n: (lambda rng, args: scif_args(rng, args, 'obj')) for n in (
    'scif_rxi_isr', 'scif_txi_isr', 'uart_obj_init', 'scif_irq_off', 'scif_read', 'scif_start', 'scif_open',
    'scif_read_timeout', 'scif_flush', 'scif_write', 'uart_obj_ctor', 'scif_has_flag')})
PRESETS.update({n: (lambda rng, args: scif_args(rng, args, 'glob')) for n in (
    'scif3_rxi_isr', 'scif3_txi_isr', 'scif4_rxi_isr', 'scif4_txi_isr', 'scif5_rxi_isr', 'scif5_txi_isr',
    'scif5_get', 'scif4_get', 'scif3_get', 'scif5_rxi_count_get', 'scif4_rxi_count_get', 'scif_uarts_ctor')})
def range_args(rng, args, k_len, k_buf=None):
    """A length its callers could pass (round 8): the cache maintenance ranges and the CRCs got a random 32-bit
    length, so half of their trials ran to the budget (inconclusive, never compared) and they took 15..25 s each.
    The length now stays within what a loop finishes in the budget, from 0 over the line and word boundaries to
    64 KB; a CRC's pointer is an argument buffer (1 KB) with a length within it or past it."""
    regs = args['regs']
    if k_buf is None:
        regs[k_len] = rng.choice([0, 1, 31, 32, 33, 0x40, 0x1000, 0x10000, rng.getrandbits(16)])
    else:
        a = SCRATCH_ARGS + 0x2000 * k_buf
        args['buffers'] = [b for b in args['buffers'] if b[0] != a] + [(a, bytes(rng.getrandbits(8) for _ in range(0x400)))]
        regs[k_buf] = a
        regs[k_len] = rng.choice([0, 1, 2, 3, 7, 64, 0x3FF, 0x400, rng.randrange(0x400)])
    return []


PRESETS.update({n: (lambda rng, args: range_args(rng, args, 1)) for n in (
    'icache_invalidate_range', 'dcache_clean_invalidate_range', 'dcache_clean_range', 'dcache_invalidate_range')})
PRESETS['crc16_xmodem'] = lambda rng, args: range_args(rng, args, 1, 0)
PRESETS.update({n: (lambda rng, args: range_args(rng, args, 1, 2)) for n in ('crc16_a001', 'crc32_update')})


def small_args(rng, args):
    """r0 a small selector (-1..63: command index, mode, wait kind), r1 0 or 1, r2 a random word (an argument)."""
    regs = args['regs']
    regs[0] = rng.choice([0xFFFFFFFF, 0, 1, 2, 3, 4, 5, 7, 7, 12, 17, 41, 55, 63])
    regs[1] = rng.choice([0, 1])
    regs[2] = rng.choice([0, rng.getrandbits(32)])
    return []


PRESETS.update({n: small_args for n in ('sdhi_send_cmd', 'sdhi_cmd', 'sdhi_wait_idle', 'sdhi_wait_info',
                                        'sdhi_set_bus_width')})
for _kind, _names in (
        ('reg', ('spibsc_reg_read32', 'spibsc_reg_write32', 'spibsc_reg_write16', 'spibsc_reg_write8')),
        ('obj', ('spibsc_ssl_negated',
                 'spibsc_wait_tend', 'spibsc_ensure_idle', 'spibsc_xfer', 'sflash_cmd_read', 'sflash_cmd_write',
                 'sflash_wait_ready', 'sflash_wait_wel', 'sflash_read_sr2', 'spibsc_cmncr_set', 'spibsc_enter_spi_mode',
                 'spibsc_exit_spi_mode', 'sflash_fast_read', 'sflash_erase_block', 'sflash_page_program',
                 'sflash_global_unlock', 'sflash_cmd_bp', 'sflash_dev_open', 'sflash_read_mfr_id')),
        ('dev', ('sflash_dev_write', 'sflash_dev_read', 'sflash_checksum')), ('xip', ('spiflash_write', 'spiflash_read')),
        ('bar', ('spiflash_erase', 'sflash_erase_chip_sst', 'sflash_erase_chip_uniform', 'sflash_erase_chip', 'sflash_cmd_erase')),
        ('id', ('sflash_sst_block_size',))):
    PRESETS.update({n: (lambda rng, args, k=_kind: sflash_args(rng, args, k)) for n in _names})
for _shape, _names in (('bn', ('R_RIIC_Write', 'R_RIIC_Read')), ('vm', ('R_RIIC_WriteSlaveAddr',)),
                       ('c', ('R_RIIC_SendCond',)), ('mb', ('riic_receive',)), ('v', ('riic_transmit',)),
                       ('', ('R_RIIC_Init', 'R_RIIC_ReadDummy', 'R_RIIC_DetectStop', 'R_RIIC_ClearNack',
                             'riic_transmit_start', 'riic_transmit_restart', 'riic_transmit_stop', 'riic_detect_stop',
                             'riic_regs_init', 'riic_port_init'))):
    PRESETS.update({n: (lambda rng, args, sh=_shape: riic_args(rng, args, sh)) for n in _names})
PRESETS.update({n: two_strings for n in ('strcmp', 'strcasecmp', 'strstr', 'strcat', 'strcpy')})
PRESETS.update({n: (lambda rng, args: two_strings(rng, args, True)) for n in ('strncmp', 'strncasecmp', 'memcmp',
                                                                             'strncpy')})


def wide_strings(rng, args, sized=False):
    """two_strings for the file system's UTF-16 compares (round 9): the same related pairs as 16-bit characters, the
    high byte mostly 0 (so the case folding of the low byte runs) and now and then 0x30 or 0xFF (code differences);
    the second string's characters are a mixture of the first's and others."""
    two_strings(rng, args, sized)
    bufs = []
    for i, (a, data) in enumerate(args['buffers'][-2:]):
        txt = data[:data.index(0)]
        hi = rng.choice([0, 0, 0, 0x30, 0xFF])
        w = b''.join(bytes([c, hi if rng.random() < 0.3 else 0]) for c in txt) + b'\0\0' + data[len(txt) + 1:]
        bufs.append((a & ~1, w))
        args['regs'][i] = a & ~1
    args['buffers'] = args['buffers'][:-2] + bufs
    return []


def fs_len_args(rng, args, k_len, k_eq=None):
    """A length for the file system's copy and fill loops (round 9): 0..0x400 bytes over word and 32-byte steps, or
    a random 16-bit one; for fs_memset the block size argument k_eq is the length (word fill) or 0x200 (byte fill)
    on 32-byte aligned buffers. A random 32-bit length ran past the 1M budget in a quarter of the trials."""
    regs = args['regs']
    regs[k_len] = rng.choice([0, 1, 3, 4, 31, 32, 33, 64, 0x200, 0x200, rng.randrange(0x400), rng.getrandbits(12)])
    if k_eq is not None:
        regs[k_eq] = regs[k_len] if rng.random() < 0.6 else 0x200
        regs[0] = SCRATCH_ARGS + rng.choice([0, 0, 0, 1, 2, 4])
    return []


PRESETS.update({n: two_strings for n in ('fs_stricmp', 'fs_stricmp_sjis')})
PRESETS.update({n: (lambda rng, args: two_strings(rng, args, True)) for n in ('fs_strnicmp', 'fs_strnicmp_sjis')})
PRESETS['fs_wstricmp'] = wide_strings
PRESETS['fs_wstrnicmp'] = lambda rng, args: wide_strings(rng, args, True)
PRESETS.update({n: (lambda rng, args: fs_len_args(rng, args, 2)) for n in ('fs_memcpy', 'fs_strncpy', 'fs_wstrncpy')})


def fs_move_args(rng, args):
    """fs_memmove: overlapping areas in one 1 KB buffer half of the time (dst a few bytes above or below src), so
    that its backward copy runs with a length (a mutation of it passed before this preset)."""
    fs_len_args(rng, args, 2)
    if rng.random() < 0.5:
        a = SCRATCH_ARGS + 0x200
        args['buffers'] = [b for b in args['buffers'] if b[0] != SCRATCH_ARGS] + \
            [(SCRATCH_ARGS, bytes(rng.getrandbits(8) for _ in range(0x800)))]
        args['regs'][1] = a
        args['regs'][0] = a + rng.choice([-16, -1, 1, 2, 7, 64])
        args['regs'][2] = rng.choice([0, 1, 2, 8, 100, 0x100])
    return []


PRESETS['fs_memmove'] = fs_move_args
PRESETS['fs_memset'] = lambda rng, args: fs_len_args(rng, args, 2, 3)


def byte_check(res, obj, fname, shndx, off, oaddr):
    """identical: the section linked so that the function lands at its original address gives the image's bytes over
    the whole function symbol (code and its literals), which must cover at least the Ghidra function. In practice
    only the assembly transcriptions of hand-written routines get there (armcc is not available for the C)."""
    size = next((sz for n, i, o, sz in obj.functions() if n == fname and i == shndx), 0)
    gsize = res.by_addr.get(oaddr, (None, 0, False))[1]
    if not size or size < gsize:
        return None
    lk = Linker(res)
    try:
        base = lk.place(obj, shndx, at=oaddr - off)
    except (KeyError, ValueError):
        return None
    data = next(d for a, d in lk.blobs if a == base)
    if bytes(data[off:off + size]) == res.img.read(oaddr, size):
        return f'byte-identical at the original address ({size} bytes)'
    return None


def ref_span(res, a):
    """Bytes of random fill at a data symbol the recreated code refers to: 64, but not into the next table that the
    trials keep (round 7: the fill of rspi_rx_done 0x20800418 ran over the RSPI trigger tables 0x20800424/34, so
    nearly every rspi_read trial failed its trigger check and a mutation passed)."""
    nxt = [k for k in res.keep if a < k < a + 64]
    return min(nxt) - a if nxt else 64


def check(res, obj, fname, shndx, off, seed=1, trials=200):
    img = res.img
    f = res.func(fname)
    if f is None:
        return None, 'not yet', f'no original address for {fname} (decomp/display/functions.tsv or aliases.tsv)'
    oaddr, othumb = f
    same = byte_check(res, obj, fname, shndx, off, oaddr)
    if same:
        return oaddr, 'identical', same
    lk = Linker(res)
    try:
        if off != 0:
            return oaddr, 'not yet', 'emulation needs the function at the start of its section'
        new = lk.place(obj, shndx)
    except (KeyError, ValueError) as e:
        return oaddr, 'not yet', f'emulation: {e}'
    sym = next(s for s in obj.syms if s.name == fname and s['st_info']['type'] == 'STT_FUNC')
    nthumb = bool(sym['st_value'] & 1)
    stub_addrs = {}
    for name in STUBS:
        g = res.func(name)
        if g and g[0] != oaddr:
            stub_addrs[g[0]] = name
    refs = set()
    for r in obj.relocs.get(shndx, []):
        if r['r_info_type'] in (R_ARM_ABS32, R_ARM_MOVW_ABS_NC):
            name, styp, ssec, _, _ = obj.sym_info(r['r_info_sym'])
            key = name if styp != 'STT_SECTION' else f'{os.path.basename(obj.path)}:{ssec}'
            a = res.data.get(key)
            if a is not None and not (BASE <= a < 0x2042C000) and a not in res.keep:
                refs.add(a)
    rsize = RET_SIZE.get(fname, returns_value(obj, fname))
    # the extent ends at the next known entry: Ghidra's, or an entry aliases.tsv gives for a function Ghidra's list
    # lacks (round 8: 0x2013DA6C's extent ran over 0x2013DB74, so coverage counted both functions' blocks)
    starts = sorted({a for a, _, _ in res.funcs.values()} |
                    {int(v, 16) for v in res.alias.values() if v.startswith('0x')})
    i = bisect.bisect_right(starts, oaddr)
    osize = min(starts[i] - oaddr, 0x4000) if i < len(starts) else 0x100
    gsize = res.by_addr.get(oaddr, (None, osize, False))[1]
    osize = min(osize, gsize) if gsize else osize
    sec_code = bytes(next(d for a, d in lk.blobs if a == (new & ~1)))
    o_ops = cp15_ops(img.read(oaddr, osize) or b'', oaddr, othumb)
    n_ops = cp15_ops(sec_code, new & ~1, nthumb)
    if o_ops != n_ops:
        return oaddr, 'differs', f'CP15 operations differ: original only {sorted(o_ops - n_ops)}, new only {sorted(n_ops - o_ops)}'
    reached, ok, inconclusive = set(), 0, 0
    lead = block_starts(img, oaddr, osize, othumb)
    rng = random.Random(seed)
    for t in range(trials):
        args = draw_args(rng)
        fill = [(a, bytes(rng.getrandbits(8) for _ in range(ref_span(res, a)))) for a in sorted(refs)]
        pre = preset_for(fname)
        if pre:
            fill += pre(rng, args)
        s = rng.getrandbits(32)
        for budget in (BUDGET, 8 * BUDGET):
            run1 = Run(img, [], stub_addrs, s, fill, args, cover=lead)
            r1 = run1.go(oaddr, othumb, rsize, budget)
            reached |= run1.blocks
            r2 = Run(img, lk.blobs, stub_addrs, s, fill, args).go(new & ~1, nthumb, rsize, budget)
            if 'budget' not in (r1['end'], r2['end']) or r1['end'] == r2['end']:
                break
        if r1['end'] == r2['end'] == 'budget':
            inconclusive += 1
            continue
        d = compare(r1, r2)
        if d:
            return oaddr, 'differs', f'emulation trial {t}: {d} differs (orig ended {r1["end"]}, new {r2["end"]})'
        ok += r1['end'] == 'return'
    cov = len(reached & lead) / max(1, len(lead))
    covtxt = f'{cov:.0%} of {len(lead)} blocks reached' + (f', {inconclusive} trials inconclusive' if inconclusive else '')
    if ok == 0:
        return oaddr, 'not yet', f'emulation: no trial of {trials} returned normally ({covtxt})'
    if cov < MIN_COVER:
        return oaddr, 'not yet', f'emulation: {trials} trials agree but reach only {covtxt} of the original'
    return oaddr, 'equivalent', f'differential emulation: {trials} trials agree ({ok} returned normally, {covtxt})'


def objects():
    return sorted(glob.glob(os.path.join(SRC, 'out', 'obj', '**', '*.o'), recursive=True))


def recreated():
    """(obj, function name, section index, offset) of every function defined in the built objects."""
    out = []
    for p in objects():
        obj = E.Obj(p)
        for fname, shndx, off, size in obj.functions():
            if '.' in fname:
                continue     # a compiler clone (riic_port_init.part.0): checked through the function that calls it
            out.append((obj, fname, shndx, off))
    return out


def cmd_check(args):
    """The named functions (or every function of the objects named with --object), in parallel."""
    import multiprocessing
    require_objects()
    want = set(args.functions)
    jobs = [(obj.path, fname, args.seed, args.trials) for obj, fname, shndx, off in recreated()
            if fname in want or any(obj.path.endswith(o) for o in args.object or ())]
    with multiprocessing.Pool(args.jobs or os.cpu_count()) as pool:
        for path, fname, a, v, d in pool.imap_unordered(_check_one, jobs):
            print(f'equiv_display_emu: {fname:28s} {v}: {d}', file=sys.stderr)


RANK = {'identical': -1, 'equivalent': 0, 'differs': 1, 'not yet': 2}


_RES = None


def _check_one(job):
    """Worker of cmd_status: (object path, function name, seed, trials) -> (path, name, address, verdict, detail)."""
    global _RES
    if _RES is None:
        _RES = Resolver(Image())
    path, fname, seed, trials = job
    obj = E.Obj(path)
    for fn, shndx, off, size in obj.functions():
        if fn == fname:
            a, v, d = check(_RES, obj, fname, shndx, off, seed, trials)
            return path, fname, a, v, d
    return path, fname, None, 'not yet', 'not in the object'


def _link_one(job):
    """Worker of cmd_linkcheck: (function, address, thumb, seed, trials) -> (function, verdict, detail)."""
    global _RES, _HYB
    if _RES is None:
        _RES = Resolver(Image())
    if _HYB is None:
        _HYB = Image(os.path.join(SRC, 'out', 'FT-710_DISPLAY_hybrid.bin'))
    fname, oaddr, thumb, seed, trials = job
    t0 = time.monotonic()
    v, d, ok, inconclusive = _link_trials(fname, oaddr, thumb, seed, trials)
    return fname, v, d, time.monotonic() - t0, inconclusive


def _link_trials(fname, oaddr, thumb, seed, trials):
    res = _RES
    stub_addrs = {res.func(n)[0]: n for n in STUBS if res.func(n)}
    rng = random.Random(seed)
    ok = inconclusive = 0
    for t in range(trials):
        args = draw_args(rng)
        pre = preset_for(fname)
        fill = pre(rng, args) if pre else []
        sd = rng.getrandbits(32)
        size = RET_SIZE.get(fname, _ret_sizes().get(fname, 4))
        for budget in (BUDGET, 8 * BUDGET):
            runs = [Run(res.img, [], stub_addrs, sd, fill, args), Run(_HYB, [], stub_addrs, sd, fill, args)]
            for r in runs:
                r.snap = SNAP_LINK
            before = [r.written(RAM2, RAM2_END) for r in runs]
            r1, r2 = (r.go(oaddr, thumb, size, budget) for r in runs)
            if 'budget' not in (r1['end'], r2['end']) or r1['end'] == r2['end']:
                break
        if r1['end'] == r2['end'] == 'budget':
            inconclusive += 1
            continue
        # RAM2 holds code in the hybrid only: both runs must change it alike (an argument pointer may point there)
        d = compare(r1, r2, SNAP_LINK) or ('RAM2' if ram2_changes(r1['ram2'], before[0]) !=
                                           ram2_changes(r2['ram2'], before[1]) else None)
        if d:
            return 'differs', f'trial {t}: {d} differs (image ended {r1["end"]}, hybrid {r2["end"]})', ok, inconclusive
        ok += r1['end'] == 'return'
    return 'same', f'{trials} trials agree ({ok} returned normally, {inconclusive} inconclusive)', ok, inconclusive


_HYB = None
_RETS = None


def ram2_changes(after, before):
    """{page: after XOR before} of the RAM2 pages a run changed (round 9: from the written pages; round 8 XORed the
    whole 384 KB twice per trial in Python, most of a linkcheck entry's time)."""
    out = {}
    for p in sorted(set(after.pages) | set(before.pages)):
        a, b = after.page(p), before.page(p)
        if a != b:
            out[p] = bytes(u ^ v for u, v in zip(a, b))
    return out


def _ret_sizes():
    """Return size (DWARF) of every recreated function, so that linkcheck compares r0 only where there is a result."""
    global _RETS
    if _RETS is None:
        _RETS = {}
        for obj, fname, shndx, off in recreated():
            _RETS[fname] = returns_value(obj, fname)
    return _RETS


def clobbers(obj, shndx, off, size, md):
    """Registers among r1, r2, r3, ip that the recreated code may change: every register an instruction of it writes,
    and all four when it calls anything."""
    import capstone
    out = set()
    code = obj.section_data(shndx)[off:off + size]
    for i in md.disasm(code, off):
        if i.mnemonic in ('bl', 'blx', 'b', 'bx') and i.op_str not in ('lr',):
            out |= {capstone.arm.ARM_REG_R1, capstone.arm.ARM_REG_R2, capstone.arm.ARM_REG_R3, capstone.arm.ARM_REG_R12}
        out |= set(i.regs_access()[1])
    return out


def _reads_after(insns, k, names, clob, returned):
    """The first instruction among the 12 after the call insns[k] (up to the first branch or return) that reads a
    register of names that clob holds, returned does not, and nothing has written since: (address, registers) or
    None. Pushes and stores to sp! do not count as reads."""
    import capstone
    written = set()
    for j in insns[k + 1:k + 13]:
        rd, wr = j.regs_access()
        if j.mnemonic.startswith('push') or (j.mnemonic.startswith('stm') and j.op_str.startswith('sp!')):
            rd = []
        bad = [r for r in rd if r in names and r in clob and r not in written and r not in returned]
        if bad:
            return j.address, ', '.join(names[r] for r in bad)
        written |= set(wr)
        if (j.group(capstone.CS_GRP_JUMP) or j.group(capstone.CS_GRP_CALL) or j.group(capstone.CS_GRP_RET)
                or capstone.arm.ARM_REG_PC in wr):
            return None
    return None


def _indirect_call(insns, k):
    """True when insns[k] calls through a register: blx rN, or the pre-v5 pair mov lr, pc + a write of pc
    (bx rN, ldr pc, mov pc) with insns[k] the second."""
    import capstone
    i = insns[k]
    if i.mnemonic == 'blx' and not i.op_str.startswith('#'):
        return True
    if k and insns[k - 1].mnemonic == 'mov' and insns[k - 1].op_str == 'lr, pc':
        return capstone.arm.ARM_REG_PC in i.regs_access()[1]
    return False


def address_taken(res, entries):
    """The entries (original addresses) that the image holds as a word anywhere in memory after __scatterload: in a
    literal pool, a function table, initialised data (with the Thumb bit as stored): the possible targets of its
    calls through a register. armcc's A32 code loads addresses from literal pools, not with movw/movt [fact: the
    function pointers of the round-6 TCON table and line callback are pool words]."""
    want = {}
    for a, thumb in entries:
        want[a | (1 if thumb else 0)] = a
    out = set()
    for lo, data in res.img.regions:
        for o in range(0, len(data) - 3, 4):
            w = struct.unpack_from('<I', data, o)[0]
            if w in want:
                out.add(want[w])
    return out


def abi_hazards():
    """[(function, caller, address, registers, call)]: call sites in the image that read r1, r2, r3 or ip after
    calling a recreated function that may change that register and does not return it (_reads_after). armcc keeps
    registers across calls it knows do not touch them (sdhi_error_reset keeps r2, r3, ip across sdhi_soft_reset) and
    its library returns more than the AAPCS says (_ll_udiv10: the remainder in r2): neither shows in the
    differential check, which compares the registers of the C return type, but the image's own callers break in the
    hybrid. Direct calls (bl/blx #imm) name their callee; a call through a register (round 7) can reach every
    recreated function whose entry the image holds as data (address_taken), so a read there counts against each
    of them. Returns (rows, recreated functions checked, indirect call sites, of them reading a scratch register,
    address-taken recreated functions)."""
    import capstone
    res = Resolver(Image())
    img = res.img.file
    md = {False: capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM),
          True: capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)}
    for m in md.values():
        m.detail = True
    ident = {r[3] for r in read_tsv(STATUS_TSV)[1:] if len(r) > 5 and r[5] == 'identical'}
    targets = {}
    for obj, fname, shndx, off in recreated():
        o = res.func(fname)
        if o and fname not in ident:          # byte-identical code behaves as the original at every call site
            targets[o[0]] = (fname, clobbers(obj, shndx, off, obj.extent(shndx, off), md[False]), o[1])
    taken = address_taken(res, [(a, t[2]) for a, t in targets.items()])
    rets = _ret_sizes()
    names = {capstone.arm.ARM_REG_R1: 'r1', capstone.arm.ARM_REG_R2: 'r2', capstone.arm.ARM_REG_R3: 'r3',
             capstone.arm.ARM_REG_R12: 'ip'}
    scratch = set(names)

    def returned(fname):
        size_ret = RET_SIZE.get(fname, rets.get(fname, 4)) or 0
        r = {capstone.arm.ARM_REG_R1} if size_ret >= 8 else set()
        if size_ret >= 16:
            r |= {capstone.arm.ARM_REG_R2, capstone.arm.ARM_REG_R3}
        return r

    out, n_ind, n_ind_read = [], 0, 0
    for g, (a, size, thumb) in sorted(res.funcs.items(), key=lambda kv: kv[1][0]):
        if not BASE <= a < 0x20165178 or size <= 0:
            continue
        insns = list(md[thumb].disasm(img[a - BASE:a - BASE + size], a))
        for k, i in enumerate(insns):
            if i.mnemonic in ('bl', 'blx') and i.op_str.startswith('#'):
                t = targets.get(int(i.op_str.lstrip('#'), 16) & ~1)
                if t:
                    hit = _reads_after(insns, k, names, t[1], returned(t[0]))
                    if hit:
                        out.append((t[0], g, hit[0], hit[1], i.address))
                continue
            if not _indirect_call(insns, k):
                continue
            n_ind += 1
            if _reads_after(insns, k, names, scratch, set()):
                n_ind_read += 1
                for ta in sorted(taken):
                    fname, clob, _ = targets[ta]
                    hit = _reads_after(insns, k, names, clob, returned(fname))
                    if hit:
                        out.append((fname, g, hit[0], hit[1], i.address))
    return out, len(targets), n_ind, n_ind_read, len(taken)


def cmd_abicheck(args):
    """abi_hazards() -> src/display/out/abi_hazards.tsv, which tools/display_link.py reads: it holds back (does not
    link) a recreated function that an original caller relies on in this way, until that caller is recreated too."""
    rows, n, n_ind, n_ind_read, n_taken = abi_hazards()
    os.makedirs(os.path.join(SRC, 'out'), exist_ok=True)
    with open(os.path.join(SRC, 'out', 'abi_hazards.tsv'), 'w') as f:
        f.write('function\tcaller\tcall\tread_at\tregisters\n')
        for fname, g, at, regs, call in rows:
            f.write(f'{fname}\t{g}\t{call:08x}\t{at:08x}\t{regs}\n')
            print(f'equiv_display_emu: abicheck {fname}: {g} reads {regs} at {at:#x} after the call at {call:#x}')
    print(f'equiv_display_emu: abicheck: {len(rows)} call sites rely on a register a recreated callee may change '
          f'({len({r[0] for r in rows})} functions, of {n} not byte-identical); calls through a register: {n_ind} '
          f'sites, {n_ind_read} of them read r1, r2, r3 or ip after the call, {n_taken} recreated functions are '
          f'address-taken; wrote src/display/out/abi_hazards.tsv')


def cmd_linkcheck(args):
    """Every patched or in-place entry of the hybrid image (tools/display_link.py): the original image and the hybrid
    one, both called at the original address, on the same inputs. This checks the link itself (relocations, patches) and the
    recreated functions composed with each other, since in the hybrid image they call one another."""
    import multiprocessing
    rows = read_tsv(os.path.join(SRC, 'out', 'patches.tsv'))[1:]
    modes = {int(r[0], 16): r[3] == 'thumb' for r in read_tsv(MODES_TSV)[1:]}
    jobs = [(r[1], int(r[0], 16), modes.get(int(r[0], 16), False), args.seed, args.trials) for r in rows
            if r[0] != '-' and (not args.functions or r[1] in args.functions)]
    cnt = {}
    times = []
    t0 = time.monotonic()
    with multiprocessing.Pool(args.jobs or os.cpu_count()) as pool:
        for fname, v, d, sec, inc in pool.imap_unordered(_link_one, jobs):
            cnt[v] = cnt.get(v, 0) + 1
            times.append((sec, fname, v, inc))
            if v != 'same' or args.verbose:
                print(f'equiv_display_emu: linkcheck {fname:28s} {v}: {d} ({sec:.1f} s)', file=sys.stderr)
    # per-entry times (round 9; round 8 had none, so the slow entries were unknown): out/linkcheck_times.tsv
    with open(os.path.join(SRC, 'out', 'linkcheck_times.tsv'), 'w') as f:
        f.write('seconds\tfunction\tverdict\tinconclusive\n')
        for sec, fname, v, inc in sorted(times, reverse=True):
            f.write(f'{sec:.2f}\t{fname}\t{v}\t{inc}\n')
    total = sum(t[0] for t in times)
    slow = ', '.join(f'{n} {sec:.1f} s' for sec, n, _, _ in sorted(times, reverse=True)[:5])
    print('equiv_display_emu: linkcheck: ' + ', '.join(f'{k} {v}' for k, v in sorted(cnt.items())) +
          f' (of {len(jobs)} patched or in-place entries); {time.monotonic() - t0:.0f} s wall, {total:.0f} s in the '
          f'entries (slowest: {slow}); wrote src/display/out/linkcheck_times.tsv')


def require_objects():
    """Stop with a clear message when the recreated objects are missing: without them status would write a table
    with every function "not yet" (seen in the T24 round-5 follow-up)."""
    if not objects():
        sys.exit(f'equiv_display_emu: no objects in {os.path.relpath(os.path.join(SRC, "out", "obj"), ROOT)}; '
                 f'build them first (make -C src/display CROSS=...); status.tsv not written')


def cmd_status(args):
    import multiprocessing
    require_objects()
    res = Resolver(Image())
    results = {}
    jobs = [(obj.path, fname, args.seed, args.trials) for obj, fname, shndx, off in recreated()]
    with multiprocessing.Pool(args.jobs or os.cpu_count()) as pool:
        done = list(pool.imap_unordered(_check_one, jobs))
    for path, fname, a, v, d in sorted(done, key=lambda x: (x[0], x[1])):
        print(f'equiv_display_emu: {fname:28s} {v}: {d}', file=sys.stderr)
        rel = os.path.relpath(path, os.path.join(SRC, 'out', 'obj'))
        if a is None:
            results.setdefault(('-', fname), (fname, rel, v, d))
            continue
        cur = results.get(a)
        if cur is None or RANK[v] < RANK[cur[2]]:
            results[a] = (fname, rel, v, d)
    rows = []
    for g, (a, n, _) in sorted(res.funcs.items(), key=lambda kv: kv[1][0]):
        if a in results:
            fname, rel, v, d = results[a]
            rows.append((a, g, n, fname, rel, v, n if v in ('identical', 'equivalent') else 0, d[:300]))
        else:
            rows.append((a, g, n, '', '', 'not yet', 0, ''))
    listed = {a for a, _, _ in res.funcs.values()}
    for k, (fname, rel, v, d) in results.items():
        if isinstance(k, tuple):
            rows.append((0, '-', 0, fname, rel, v, 0, d[:300]))
        elif k not in listed:      # an original address (aliases.tsv) that Ghidra's list lacks: linked, no bytes counted
            rows.append((k, '-', 0, fname, rel, v, 0, d[:300]))
    with open(STATUS_TSV, 'w', encoding='utf-8') as f:
        f.write('# DISPLAY: recreated source vs the original image, per function (T24). Generated by\n')
        f.write('# tools/equiv_display_emu.py status; do not edit. identical = the bytes linked at the original address are the\n')
        f.write("# image's (assembly transcriptions; armcc is not available for the C); equivalent = passes the differential\n")
        f.write('# emulation (Unicorn, A32/Thumb). covered = bytes of the Ghidra function\n')
        f.write('# counted as re-implemented; tools/readability_stats.py sums it. Rows with ghidra_name "-" have no original\n')
        f.write('# function in decomp/display/functions.tsv (address 0: none at all; otherwise one Ghidra\'s list lacks).\n')
        f.write('address\tghidra_name\tsize\tsource\tfile\tverdict\tcovered\tdetail\n')
        for a, g, n, src, fl, v, cov, det in sorted(rows):
            f.write(f'{a:08x}\t{g}\t{n}\t{src}\t{fl}\t{v}\t{cov}\t{det}\n')
    listed = [r for r in rows if r[1] != '-']
    tot = sum(r[2] for r in listed)
    cov = sum(r[6] for r in listed)
    cnt = {}
    for r in listed:
        cnt[r[5]] = cnt.get(r[5], 0) + 1
    id_b = sum(r[2] for r in listed if r[5] == 'identical')
    eq_b = sum(r[2] for r in listed if r[5] == 'equivalent')
    df_b = sum(r[2] for r in listed if r[5] == 'differs')
    print(f'equiv_display_emu: ' + ', '.join(f'{k} {v}' for k, v in sorted(cnt.items(), key=lambda kv: RANK[kv[0]])) +
          f' (of {len(listed)} Ghidra functions); identical {id_b} bytes, equivalent {eq_b} bytes, differs {df_b} bytes; re-implemented {cov} '
          f'of {tot} bytes ({100.0 * cov / tot:.2f} %); wrote {os.path.relpath(STATUS_TSV, ROOT)}')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    c = sub.add_parser('check')
    c.add_argument('functions', nargs='*')
    c.add_argument('--object', action='append', help='check every function of this object (e.g. drivers/riic.o)')
    c.add_argument('--jobs', type=int, default=0)
    lc = sub.add_parser('linkcheck', help='the hybrid image against the original at every patched entry')
    lc.add_argument('functions', nargs='*', help='only these entries (default: all)')
    lc.add_argument('--jobs', type=int, default=0)
    lc.add_argument('--verbose', action='store_true')
    lc.add_argument('--trials', type=int, default=100)
    lc.add_argument('--seed', type=int, default=3)
    st = sub.add_parser('status')
    st.add_argument('--jobs', type=int, default=0, help='worker processes (default: all cores)')
    for p in (c, st):
        p.add_argument('--trials', type=int, default=200)
        p.add_argument('--seed', type=int, default=1)
    sub.add_parser('abicheck', help='call sites that read registers a recreated callee does not return')
    args = ap.parse_args()
    {'check': cmd_check, 'status': cmd_status, 'linkcheck': cmd_linkcheck, 'abicheck': cmd_abicheck}[args.cmd](args)


if __name__ == '__main__':
    main()
