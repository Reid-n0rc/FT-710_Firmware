#!/usr/bin/env python3
"""T24 (DISPLAY): differential emulation of recreated DISPLAY functions (RZ/A1H Cortex-A9) with Unicorn.

The DISPLAY image was built with armcc (ARM Compiler 5) on the NORTi kernel; neither is available, so nothing can be
byte-identical: each recreated function is compiled with GCC (src/display/Makefile, A32) and checked against the
original by running both from the same start state on the same inputs (the method of tools/equiv_m33_emu.py, ported
to A32 in T24 round 3).

Start state (built once): the image at 0x20100000, the three LZ-compressed RW regions of its Region$$Table
(0x204286A8) decompressed by the image's own __decompress (0x20100BFC, run in Unicorn), the two zero-init regions
zero; that is the memory after __scatterload. The CPU is in SVC mode with IRQ and FIQ masked and the MMU off.

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
The image is read from build/FT-710_DISPLAY_V0108.bin (or $FT710_BUILD/...); it is never written anywhere.
"""
import argparse
import bisect
import glob
import os
import random
import struct
import sys

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
NARGS = 8
MIN_COVER = 0.5
# compared after each run: the RW data of the image (.data .bss, .data2 .bss2, the boot-info block, the uncached
# mirror with the frame buffers and .data_nc) and the argument buffers. RAM from 0x20440000: below it the hybrid
# image (tools/display_link.py) has its recreated code (0x2042BC10..0x2043FFFF), which linkcheck must not compare.
SNAP = [(0x20000000, 0x20000100), (0x20440000, 0x20A00000), (0x60000000, 0x60A00000), (SCRATCH_ARGS, SCRATCH_ARGS + 0x20000)]

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
        self.regions = [(BASE, self.file)]
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


class Run:
    def __init__(self, img, blobs, stub_addrs, seed, fill, args, cover=None):
        self.uc = uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        try:
            uc.ctl_set_cpu_model(A.UC_CPU_ARM_CORTEX_A9)
        except Exception:
            pass
        for lo, hi in RAM + [(SCRATCH_CODE, SCRATCH_CODE + 0x400000), (STOP, STOP + 0x1000),
                             (STACK_TOP - STACK_SIZE, STACK_TOP)]:
            uc.mem_map(lo, hi - lo, UC_PROT_ALL)
        for lo, hi in MMIO:
            uc.mmio_map(lo, hi - lo, self.on_mmio_read, lo, self.on_mmio_write, lo)
        for lo, data in img.regions:
            uc.mem_write(lo, data)
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
            if STACK_TOP - STACK_SIZE <= v < STACK_TOP:
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
        v = self.rng.getrandbits(8 * size)
        self.mmio.append(('r', base + offset, size, v))
        return v

    def on_mmio_write(self, uc, offset, size, value, base):
        self.mmio.append(('w', base + offset, size, value & ((1 << (8 * size)) - 1)))

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
        snap = b''.join(bytes(uc.mem_read(lo, hi - lo)) for lo, hi in SNAP)
        return {'end': self.end[0], 'ret': ret, 'mmio': self.mmio, 'calls': self.calls, 'writes': snap,
                'sctlr': sctlr}


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


def compare(a, b):
    for k in ('end', 'ret', 'mmio', 'calls', 'sctlr'):
        if a[k] != b[k]:
            return k
    if a['writes'] != b['writes']:
        i = next(k for k in range(len(a['writes'])) if a['writes'][k] != b['writes'][k])
        for lo, hi in SNAP:
            if i < hi - lo:
                return f'memory at {lo + i:#x}'
            i -= hi - lo
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


def returns_value(obj, fname):
    import equiv_m33_emu as M
    return M.returns_value(obj, fname)


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


# return registers the DWARF cannot tell (assembly): the 64-bit divisions return quotient r0:r1 and remainder r2:r3
RET_SIZE = {'__aeabi_uldivmod': 16, '__aeabi_ldivmod': 16}

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
for _shape, _names in (('bn', ('R_RIIC_Write', 'R_RIIC_Read')), ('vm', ('R_RIIC_WriteSlaveAddr',)),
                       ('c', ('R_RIIC_SendCond',)), ('mb', ('riic_receive',)), ('v', ('riic_transmit',)),
                       ('', ('R_RIIC_Init', 'R_RIIC_ReadDummy', 'R_RIIC_DetectStop', 'R_RIIC_ClearNack',
                             'riic_transmit_start', 'riic_transmit_restart', 'riic_transmit_stop', 'riic_detect_stop',
                             'riic_regs_init', 'riic_port_init'))):
    PRESETS.update({n: (lambda rng, args, sh=_shape: riic_args(rng, args, sh)) for n in _names})
PRESETS.update({n: two_strings for n in ('strcmp', 'strcasecmp', 'strstr', 'strcat', 'strcpy')})
PRESETS.update({n: (lambda rng, args: two_strings(rng, args, True)) for n in ('strncmp', 'strncasecmp', 'memcmp',
                                                                             'strncpy')})


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
    starts = sorted(a for a, _, _ in res.funcs.values())
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
        fill = [(a, bytes(rng.getrandbits(8) for _ in range(64))) for a in sorted(refs)]
        if fname in PRESETS:
            fill += PRESETS[fname](rng, args)
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
    res = _RES
    stub_addrs = {res.func(n)[0]: n for n in STUBS if res.func(n)}
    rng = random.Random(seed)
    ok = inconclusive = 0
    for t in range(trials):
        args = draw_args(rng)
        fill = PRESETS[fname](rng, args) if fname in PRESETS else []
        sd = rng.getrandbits(32)
        size = RET_SIZE.get(fname, 4)
        for budget in (BUDGET, 8 * BUDGET):
            r1 = Run(res.img, [], stub_addrs, sd, fill, args).go(oaddr, thumb, size, budget)
            r2 = Run(_HYB, [], stub_addrs, sd, fill, args).go(oaddr, thumb, size, budget)
            if 'budget' not in (r1['end'], r2['end']) or r1['end'] == r2['end']:
                break
        if r1['end'] == r2['end'] == 'budget':
            inconclusive += 1
            continue
        d = compare(r1, r2)
        if d:
            return fname, 'differs', f'trial {t}: {d} differs (image ended {r1["end"]}, hybrid {r2["end"]})'
        ok += r1['end'] == 'return'
    return fname, 'same', f'{trials} trials agree ({ok} returned normally, {inconclusive} inconclusive)'


_HYB = None


def cmd_linkcheck(args):
    """Every patched entry of the hybrid image (tools/display_link.py): the original image and the hybrid one, both
    called at the original address, on the same inputs. This checks the link itself (relocations, patches) and the
    recreated functions composed with each other, since in the hybrid image they call one another."""
    import multiprocessing
    rows = read_tsv(os.path.join(SRC, 'out', 'patches.tsv'))[1:]
    modes = {int(r[0], 16): r[3] == 'thumb' for r in read_tsv(MODES_TSV)[1:]}
    jobs = [(r[1], int(r[0], 16), modes.get(int(r[0], 16), False), args.seed, args.trials) for r in rows if r[0] != '-']
    cnt = {}
    with multiprocessing.Pool(args.jobs or os.cpu_count()) as pool:
        for fname, v, d in pool.imap_unordered(_link_one, jobs):
            cnt[v] = cnt.get(v, 0) + 1
            if v != 'same' or args.verbose:
                print(f'equiv_display_emu: linkcheck {fname:28s} {v}: {d}', file=sys.stderr)
    print('equiv_display_emu: linkcheck: ' + ', '.join(f'{k} {v}' for k, v in sorted(cnt.items())) +
          f' (of {len(jobs)} patched entries)')


def cmd_status(args):
    import multiprocessing
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
    for k, (fname, rel, v, d) in results.items():
        if isinstance(k, tuple):
            rows.append((0, '-', 0, fname, rel, v, 0, d[:300]))
    with open(STATUS_TSV, 'w', encoding='utf-8') as f:
        f.write('# DISPLAY: recreated source vs the original image, per function (T24). Generated by\n')
        f.write('# tools/equiv_display_emu.py status; do not edit. identical = the bytes linked at the original address are the\n')
        f.write("# image's (assembly transcriptions; armcc is not available for the C); equivalent = passes the differential\n")
        f.write('# emulation (Unicorn, A32/Thumb). covered = bytes of the Ghidra function\n')
        f.write('# counted as re-implemented; tools/readability_stats.py sums it. Rows with ghidra_name "-" have no original.\n')
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
    lc.add_argument('--jobs', type=int, default=0)
    lc.add_argument('--verbose', action='store_true')
    lc.add_argument('--trials', type=int, default=100)
    lc.add_argument('--seed', type=int, default=3)
    st = sub.add_parser('status')
    st.add_argument('--jobs', type=int, default=0, help='worker processes (default: all cores)')
    for p in (c, st):
        p.add_argument('--trials', type=int, default=200)
        p.add_argument('--seed', type=int, default=1)
    args = ap.parse_args()
    {'check': cmd_check, 'status': cmd_status, 'linkcheck': cmd_linkcheck}[args.cmd](args)


if __name__ == '__main__':
    main()
