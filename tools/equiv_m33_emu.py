#!/usr/bin/env python3
"""T24: differential emulation of the IFDSP M33 (Cortex-M33, Thumb-2) with Unicorn, for functions whose recreated
source does not compile to the original bytes.

For one function, the original (from the image, at its address) and the recompiled one (its section from the object,
relocated by this tool to a scratch address, every reference resolved to the original address of the same symbol by
tools/equiv_m33.py's Resolver) run from the same start state:
  memory    the image's SRAM copy (0x80000..), .bss zero, the flash image at 0x08000000, the shared SRAM at 0x20000000;
            the data objects the function refers to are filled with the same random bytes for both runs;
  registers r0..r3 from the same random draw: small integers, 32-bit values, or pointers to a scratch buffer of random
            bytes or a random ASCII string (so string and buffer arguments get exercised).
Callees are the original functions of the image and run natively, except blocking or slow ones (FreeRTOS waits,
task creation, rpmsg, delay_us, ...): those are stubbed, return a value from a seeded sequence, and are recorded with
their arguments. Peripheral reads (0x40000000.., 0x50000000.., 0xE0000000..) return values from a seeded sequence
and every peripheral access is recorded.

The two runs are equivalent for an input when they give the same: return registers r0/r1, final contents of all
memory outside the stack, sequence of peripheral accesses, sequence of stubbed calls (pointer arguments into the
stack are compared by the bytes they point to), and the same way of ending (return, fault at the same kind of
access, or instruction budget). A function is "equivalent" when every trial agrees, at least one returned normally,
and the trials together reached at least half of the original function's basic blocks (MIN_COVER; block coverage is
recorded with a block hook on the original's range, and printed); otherwise "differs" with the first difference, or
"not yet". (Until 2026-11-01 round 2 the rule was "a quarter of the trials return": it let a function whose stack
arguments were never drawn pass with no coverage, the printf core.)

Inputs beyond the random registers: the first four stack argument slots are drawn like r0..r3 (NARGS); some string
buffers are printf-like format strings; PRESETS build a valid structure for functions that walk one (the C library's
heap list, a stream, a DSP message); STUBS also cover the C library's "no host" __sys_* calls, with random returns, so
the stream code is checked on the paths a host would take.

Used by `tools/equiv_m33.py status --emu`; standalone: python3 -I tools/equiv_m33_emu.py FUNCTION [--trials N].
"""
import os
import random
import struct
import sys

from unicorn import Uc, UcError, UC_ARCH_ARM, UC_MODE_THUMB, UC_MODE_MCLASS, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED, \
    UC_HOOK_BLOCK, \
    UC_PROT_ALL
from unicorn import arm_const as A

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv_m33 as E  # noqa: E402

SCRATCH_CODE = 0x00300000   # recompiled function and the helper sections it needs (BL range of the SRAM code)
SCRATCH_ARGS = 0x00380000   # argument buffers
STOP = 0x3F000000           # return address; reaching it ends the run
STACK_TOP, STACK_SIZE = 0x3E000000, 0x10000
BUDGET = 400000             # instructions per run
MMIO = [(0x40000000, 0x40200000), (0x50000000, 0x50200000), (0xE0000000, 0xE0100000)]
RAM = [(0x00000000, 0x00500000), (0x20000000, 0x20500000)]
# compared after each run: the image's SRAM with .bss and heap, the argument buffers, the shared SRAM (rpmsg, registers)
SNAP = [(0x00080000, 0x000A3000), (0x00380000, 0x00388000), (0x20000000, 0x20080000)]
NARGS = 8                   # argument words drawn per trial: r0..r3, then the first four stack slots
MIN_COVER = 0.5             # share of the original's basic blocks the trials must reach together
FLASH = (0x08000000, 0x09000000)

# Callees that block, start tasks or take long: stubbed, with the number of arguments they take (only those are
# compared: the other argument registers hold whatever the caller left there)
STUBS = {
    'xEventGroupWaitBits': 5, 'xEventGroupSetBitsFromISR': 3, 'xEventGroupCreate': 0, 'vTaskDelay': 1,
    'xQueueReceive': 3, 'xQueueGenericSend': 4, 'xQueueGenericCreate': 3, 'ulTaskNotifyTake': 2,
    'xTaskGenericNotify': 4, 'xTaskCreate': 6, 'vTaskStartScheduler': 0, 'rpmsg_lite_send': 6, 'rpmsg_queue_recv': 7,
    'rpmsg_lite_master_init': 4, 'rpmsg_queue_create': 1, 'rpmsg_lite_create_ept': 4, 'delay_us': 1,
    'DSP_CopyImage': 1, 'DSP_Init': 0, 'BOARD_DSP_Init': 0, 'SDK_DelayAtLeastUs': 2, 'CLOCK_EnableFfroClk': 1,
    'CLOCK_EnableSfroClk': 0, 'CLOCK_InitSysPll': 1, 'CLOCK_InitAudioPll': 1, 'CLOCK_EnableSysOscClk': 3,
}
# Pointer arguments into the stack are compared by the bytes they point to: 16 by default, or the size of the
# pointed-to object where the stub's prototype says it (the bytes after it are other locals of the caller)
STACK_ARG_BYTES = {('xEventGroupSetBitsFromISR', 2): 4}   # BaseType_t *pxHigherPriorityTaskWoken
# The C library's "no host" stubs always fail in the image, which leaves most of stdio unreachable there; stubbed
# with random returns, the stream functions are checked on the paths a host (or a later firmware) would take.
STUBS.update({'__sys_istty': 1, '__sys_flen': 1, '__sys_seek': 2, '__sys_write': 3, '__sys_close': 1,
              '__sys_tmpnam': 3, '__sys_remove': 2})


def heap_preset(rng, args, free_arg=False):
    """A valid C-library heap (Redlib malloc's block list {tag, words, next}) in the argument area, with the list
    head (0x88B70) and the heap end (0x88B6C) pointing into it. For free, r0 points at one block's payload."""
    base = 0x386000
    blocks, a = [], base
    for _ in range(rng.randrange(0, 6)):
        n = rng.choice([0, 1, 2, 3, 4, 5, 8, 12, 16, 20, 40])
        blocks.append((a, rng.choice([0x10000000, 0x20000000]), n))
        a += 12 + 4 * n
    data = b''.join(struct.pack('<3I', t, n, blocks[i + 1][0] if i + 1 < len(blocks) else 0)
                    for i, (_, t, n) in enumerate(blocks))
    fill = [(base, data + bytes(rng.getrandbits(8) for _ in range(64))),
            (0x88B70, struct.pack('<I', blocks[0][0] if blocks else 0)),
            (0x88B6C, struct.pack('<I', rng.choice([0, a, 0xA1EF8, 0xA2EF0])))]
    if free_arg:
        args['regs'][0] = rng.choice([0] + [b[0] + 12 for b in blocks])
    return fill


def stream_preset(rng, args, reg=1):
    """A plausible C-library stream (Redlib FILE, 0x3C bytes) at 0x385000 with a 256-byte buffer after it: flags
    from the bits the stream code tests, pointers inside the buffer, small counts; argument register reg points at it."""
    f, buf = 0x385000, 0x385100
    bits = [1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x8000, 0x10000, 0x80000,
            0x100000]
    flags = 0
    for b in bits:
        if rng.random() < 0.3:
            flags |= b
    size = rng.choice([1, 16, 256])
    base = rng.choice([buf, buf, f + 0x24, 0])
    w = [0] * 15
    w[0] = base + rng.randrange(0, size + 1) if base else 0
    w[1] = rng.choice([0, 1, 5, 0xFFFFFFFF])
    w[2] = rng.choice([0, 1, 5, 0x7FFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFF0])
    w[3] = flags
    w[4] = base
    w[5] = rng.randrange(0, 4)
    w[6] = rng.choice([0, 10, 0x100])
    w[7] = size
    w[8] = rng.randrange(0, 4)
    w[10] = rng.choice([0, 10, 0x100, 0x180])
    w[11] = base + rng.randrange(0, size + 1) if base else 0
    w[12] = size
    args['regs'][reg] = f
    return [(f, struct.pack('<15I', *w)), (buf, bytes(rng.getrandbits(8) for _ in range(256)))]


def dsp_message_preset(rng, args):
    """A DSP reply (src/ifdsp_m33/app/ipc.h dsp_message_t) at 0x384800: category (+8) 0..4, command (+0xC) 0..2,
    parameters 0, 1 or random; r0 points at it."""
    m = bytearray(rng.getrandbits(8) for _ in range(0x98))
    m[8] = rng.randrange(0, 5)
    m[0xC] = rng.choice([0, 0, 1, 2])
    for k in range(0x10, 0x40, 4):
        m[k:k + 4] = struct.pack('<I', rng.choice([0, 0, 1, rng.getrandbits(32)]))
    args['regs'][0] = 0x384800
    return [(0x384800, bytes(m))]


def pwm_preset(rng, args):
    """The SCT0 PWM state (src/ifdsp_m33/app/pwm.c): an event number SCTIMER_SetupPwm could have returned (0..15) at
    0x886F0, the tick count near its reload (400) at 0x886F4. With random .bss the event index runs past SCT0's EV[]
    and the SDK's SCTIMER_UpdatePwmDutycycle faults [fact: trials of round 1 ended reading unmapped memory]."""
    return [(0x886F0, struct.pack('<I', rng.randrange(0, 16))),
            (0x886F4, struct.pack('<I', rng.choice([0, 1, 398, 399, 399, 400, 401, rng.getrandbits(32)])))]


PRESETS = {'sct0_pwm_callback': pwm_preset, 'ipc_print_dsp_reply': dsp_message_preset, 'malloc': heap_preset, 'free': lambda rng, args: heap_preset(rng, args, True), 'fputc': stream_preset}


def returns_value(obj, fname):
    """From the object's DWARF (the Makefile builds with -g): None for a void function, else the return size in bytes
    (None as well when there is no DWARF: then r0 is compared)."""
    if not obj.elf.has_dwarf_info():
        return 4
    for cu in obj.elf.get_dwarf_info().iter_CUs():
        for die in cu.iter_DIEs():
            if die.tag == 'DW_TAG_subprogram' and 'DW_AT_name' in die.attributes and \
                    die.attributes['DW_AT_name'].value.decode() == fname and 'DW_AT_declaration' not in die.attributes:
                if 'DW_AT_type' not in die.attributes:
                    return None
                t = die.get_DIE_from_attribute('DW_AT_type')
                while 'DW_AT_byte_size' not in t.attributes and 'DW_AT_type' in t.attributes:
                    t = t.get_DIE_from_attribute('DW_AT_type')
                return t.attributes['DW_AT_byte_size'].value if 'DW_AT_byte_size' in t.attributes else 4
    return 4


class Linker:
    """Place a function section (and the sections of its own object it needs that have no original address) at
    scratch addresses, and apply its relocations against the original addresses."""

    def __init__(self, res):
        self.res = res
        self.next = SCRATCH_CODE
        self.placed = {}   # (obj path, shndx) -> address
        self.blobs = []    # (address, bytes)

    def place(self, obj, shndx):
        key = (obj.path, shndx)
        if key in self.placed:
            return self.placed[key]
        sec = obj.secs[shndx]
        align = max(4, sec['sh_addralign'])
        addr = (self.next + align - 1) & ~(align - 1)
        data = bytearray(obj.section_data(shndx))
        self.placed[key] = addr
        self.next = addr + len(data) + 4
        self.blobs.append([addr, data])
        idx = len(self.blobs) - 1
        for r in obj.relocs.get(shndx, []):
            self.apply(obj, shndx, addr, data, r)
        self.blobs[idx][1] = data
        return addr

    def target(self, obj, r, at_addend=0):
        name, styp, ssec, sval, sshndx = obj.sym_info(r['r_info_sym'])
        res = self.res
        if styp == 'STT_SECTION':
            fn = E.section_function_name(obj, sshndx, at_addend)
            if fn and ssec.startswith(('.text', 'CodeQuickAccess')):
                a = res.func_addr(res.weak_alias.get(fn, fn))
                return (a | 1) if a is not None else self.place(obj, sshndx) + at_addend + 1, True
            key = f'{os.path.basename(obj.path)}:{ssec}'
            a = res.data.get(key, res.learned.get(key))
            if a is not None:
                return a, False
            return self.place(obj, sshndx), False
        if styp == 'STT_FUNC' or (styp == 'STT_NOTYPE' and res.func_addr(res.weak_alias.get(name, name)) is not None):
            a = res.func_addr(res.weak_alias.get(name, name))
            if a is None and isinstance(sshndx, int):
                return self.place(obj, sshndx) + (sval & ~1) + 1, True
            if a is None:
                raise KeyError(f'no address for function {name}')
            return a | 1, True
        a = res.data.get(name, res.learned.get(name))
        if a is None and isinstance(sshndx, int):
            return self.place(obj, sshndx) + sval, False
        if a is None:
            raise KeyError(f'no address for data symbol {name} (add it to src/ifdsp_m33/data_symbols.tsv)')
        return a, False

    def apply(self, obj, shndx, base, data, r):
        o, typ = r['r_offset'], r['r_info_type']
        if typ in (E.R_ARM_THM_CALL, E.R_ARM_THM_JUMP24):
            hw1, hw2 = struct.unpack_from('<HH', data, o)
            name, styp, *_ = obj.sym_info(r['r_info_sym'])
            off = ((E.thumb_bl_target(0, hw1, hw2) or 0) + 4) if styp == 'STT_SECTION' else 0
            t, _ = self.target(obj, r, off)
            pc = base + o
            d = (t & ~1) - (pc + 4)
            s = (d >> 24) & 1
            i1, i2 = (d >> 23) & 1, (d >> 22) & 1
            j1, j2 = (1 - i1) ^ s, (1 - i2) ^ s
            hw1 = 0xF000 | (s << 10) | ((d >> 12) & 0x3FF)
            hw2 = (hw2 & 0xD000) | (j1 << 13) | (j2 << 11) | ((d >> 1) & 0x7FF)
            if (hw2 & 0xD000) == 0xC000:  # BLX to ARM is never used here: make it BL
                hw2 |= 0x1000
            struct.pack_into('<HH', data, o, hw1, hw2)
        elif typ == E.R_ARM_ABS32:
            addend = struct.unpack_from('<I', data, o)[0]
            name, styp, *_ = obj.sym_info(r['r_info_sym'])
            if styp == 'STT_SECTION':
                t, is_fn = self.target(obj, r, addend & ~1)
                v = t if is_fn else t + addend
            else:
                t, is_fn = self.target(obj, r)
                v = t + addend
            struct.pack_into('<I', data, o, v & 0xFFFFFFFF)
        elif typ in (E.R_ARM_NONE, E.R_ARM_V4BX):
            pass
        else:
            raise ValueError(f'relocation type {typ} not supported by the emulation linker')


def in_ranges(a, ranges):
    return any(lo <= a < hi for lo, hi in ranges)


class Run:
    """One emulation run; returns its trace."""

    def __init__(self, img, blobs, stub_addrs, seed, data_fill, args, cover=None):
        self.uc = uc = Uc(UC_ARCH_ARM, UC_MODE_THUMB | UC_MODE_MCLASS)
        try:
            uc.ctl_set_cpu_model(A.UC_CPU_ARM_CORTEX_M33)
        except Exception:
            pass
        for lo, hi in RAM + [FLASH, (STOP, STOP + 0x1000), (STACK_TOP - STACK_SIZE, STACK_TOP)]:
            uc.mem_map(lo, hi - lo, UC_PROT_ALL)
        # Peripherals through mmio_map callbacks. (Unicorn's UC_HOOK_MEM_READ/WRITE hooks break conditional loads and
        # stores in Thumb IT blocks: a memcpy loop ran past its end. So no memory hooks at all; RAM effects are
        # compared as before/after snapshots of the regions in SNAP.)
        for lo, hi in MMIO:
            uc.mmio_map(lo, hi - lo, self.on_mmio_read, lo, self.on_mmio_write, lo)
        uc.mem_write(E.RAM_BASE, img.ram)
        uc.mem_write(FLASH[0], img.flash)
        uc.mem_write(STOP, b'\x00\xbf' * 8)
        for addr, data in blobs:
            uc.mem_write(addr, bytes(data))
        for addr, data in data_fill:
            uc.mem_write(addr, data)
        for addr, data in args.get('buffers', []):
            uc.mem_write(addr, data)
        self.rng = random.Random(seed)
        self.stub_addrs = stub_addrs
        self.mmio = []
        self.calls = []
        self.end = None
        self.count = 0
        # code hooks only on the stub entries and the return address: a hook on every instruction breaks Thumb IT
        # blocks in Unicorn (conditional loops never ended); the instruction budget is emu_start's count instead
        for a in list(stub_addrs) + [STOP]:
            uc.hook_add(UC_HOOK_CODE, self.on_code, begin=a, end=a)
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self.on_unmapped)
        # basic blocks reached inside the original function (a block hook leaves IT blocks alone, unlike a code
        # hook on every instruction)
        self.blocks = set()
        if cover:
            uc.hook_add(UC_HOOK_BLOCK, lambda u, a, n, _: self.blocks.add(a), begin=cover[0], end=cover[1] - 1)
        self.regs = args['regs']

    def on_code(self, uc, addr, size, _):
        self.count += 1
        if addr == STOP:
            self.end = ('return',)
            uc.emu_stop()
            return
        name = self.stub_addrs.get(addr)
        if name:
            n = STUBS[name]
            r = [uc.reg_read(x) for x in (A.UC_ARM_REG_R0, A.UC_ARM_REG_R1, A.UC_ARM_REG_R2, A.UC_ARM_REG_R3)][:n]
            sp = uc.reg_read(A.UC_ARM_REG_SP)
            r += [struct.unpack('<I', uc.mem_read(sp + 4 * k, 4))[0] for k in range(max(0, n - 4))]
            norm = []
            for k, v in enumerate(r):
                if STACK_TOP - STACK_SIZE <= v < STACK_TOP:
                    n = STACK_ARG_BYTES.get((name, k), 16)
                    norm.append(('stack', bytes(uc.mem_read(v, min(n, STACK_TOP - v)))))
                else:
                    norm.append(v)
            self.calls.append((name, tuple(norm)))
            ret = self.rng.choice([0, 1, 1, 0xFFFFFFFF, self.rng.getrandbits(32)])
            uc.reg_write(A.UC_ARM_REG_R0, ret)
            uc.reg_write(A.UC_ARM_REG_PC, uc.reg_read(A.UC_ARM_REG_LR) | 1)

    def on_mmio_read(self, uc, offset, size, base):
        v = self.rng.getrandbits(8 * size)
        self.mmio.append(('r', base + offset, size, v))
        return v

    def on_mmio_write(self, uc, offset, size, value, base):
        self.mmio.append(('w', base + offset, size, value & ((1 << (8 * size)) - 1)))

    def on_unmapped(self, uc, access, addr, size, value, _):
        self.end = ('fault', access)
        return False

    def go(self, entry, ret_size=4):
        uc = self.uc
        regs = [A.UC_ARM_REG_R0, A.UC_ARM_REG_R1, A.UC_ARM_REG_R2, A.UC_ARM_REG_R3]
        for reg, v in zip(regs, self.regs):
            uc.reg_write(reg, v)
        uc.reg_write(A.UC_ARM_REG_SP, STACK_TOP - 0x100)
        # arguments 5..8 on the stack (AAPCS), so functions with more than four arguments get inputs too
        uc.mem_write(STACK_TOP - 0x100, struct.pack('<4I', *[v & 0xFFFFFFFF for v in self.regs[4:8]]))
        uc.reg_write(A.UC_ARM_REG_LR, STOP | 1)
        try:
            uc.emu_start(entry | 1, 0, count=BUDGET)
        except UcError as e:
            if self.end is None:
                self.end = ('fault', str(e))
        if self.end is None:
            self.end = ('budget',)
        ret = None
        if self.end[0] == 'return' and ret_size:
            ret = (uc.reg_read(A.UC_ARM_REG_R0),) + ((uc.reg_read(A.UC_ARM_REG_R1),) if ret_size > 4 else ())
            if ret_size < 4:
                ret = (ret[0] & ((1 << (8 * ret_size)) - 1),)
        snap = b''.join(bytes(uc.mem_read(lo, hi - lo)) for lo, hi in SNAP)
        return {'end': self.end[0], 'ret': ret, 'mmio': self.mmio, 'calls': self.calls, 'writes': snap}


def printf_like(rng):
    """A random format string: literal characters and conversions with flags, width, precision and length."""
    out = []
    for _ in range(rng.randrange(1, 6)):
        if rng.random() < 0.3:
            out.append(rng.choice('ab Z\r\n:'))
            continue
        c = '%' + ''.join(rng.choice('-+ #0') for _ in range(rng.randrange(0, 3)))
        c += rng.choice(['', '', str(rng.randrange(0, 20)), '*'])
        c += rng.choice(['', '', '.' + str(rng.randrange(0, 12)), '.*', '.'])
        c += rng.choice(['', '', '', 'l', 'll', 'h', 'hh', 'j', 'z', 't', 'L', 'q'])
        c += rng.choice('diuxXoscpn%cdduxsk')
        out.append(c)
    return ''.join(out)


def draw_args(rng):
    regs, bufs = [], []
    for k in range(NARGS):
        kind = rng.random()
        if kind < 0.35:
            regs.append(rng.choice([0, 1, 2, 3, 4, 7, 10, 11, 0x40, 0xFF, 0x4005, 0x7FFF, 0x8000]))
        elif kind < 0.55:
            regs.append(rng.getrandbits(rng.choice([8, 16, 32])))
        else:
            a = SCRATCH_ARGS + 0x1000 * k
            if rng.random() < 0.15:
                s = printf_like(rng)
                data = s.encode() + b'\0' + bytes(rng.getrandbits(8) for _ in range(64))
            elif rng.random() < 0.5:
                s = ''.join(rng.choice('rwdiRWDI0123456789abcdefABCDEF \r\n') for _ in range(rng.randrange(0, 14)))
                data = s.encode() + b'\0' + bytes(rng.getrandbits(8) for _ in range(64))
            else:
                data = bytes(rng.getrandbits(8) for _ in range(0x200))
            bufs.append((a, data))
            regs.append(a)
    return {'regs': regs, 'buffers': bufs}


def compare(a, b):
    for k in ('end', 'ret', 'mmio', 'calls'):
        if a[k] != b[k]:
            return k
    if a['writes'] != b['writes']:
        i = next(k for k in range(len(a['writes'])) if a['writes'][k] != b['writes'][k])
        for lo, hi in SNAP:
            if i < hi - lo:
                return f'memory at {lo + i:#x}'
            i -= hi - lo
    return None


def block_starts(img, addr, size):
    """Basic-block leaders of the original function [addr, addr + size): the entry, every branch target inside it
    and every instruction after a branch (static scan, literal pools after an unconditional end are skipped)."""
    import capstone
    key = (addr, size)
    if key in _BLOCKS:
        return _BLOCKS[key]
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB | capstone.CS_MODE_MCLASS)
    code = img.read(addr, size)
    leaders, pc, end = {addr}, addr, addr + size
    while pc < end:
        ins = next(md.disasm(code[pc - addr:pc - addr + 4], pc), None)
        if ins is None:
            pc += 2
            continue
        m = ins.mnemonic.split('.')[0]
        call = m in ('bl', 'blx')
        # conditional: b<cc>, cbz/cbnz, and bx/pop pc inside an IT block (bxeq, popne)
        cond = m in ('cbz', 'cbnz') or (len(m) == 3 and m[0] == 'b' and m not in ('bic', 'bfi', 'bfc', 'bkp', 'blx')) or \
            (m.startswith('bx') and len(m) > 2) or (m.startswith('pop') and len(m) > 3 and 'pc' in ins.op_str)
        if m in ('b', 'cbz', 'cbnz') or (cond and m[0] == 'b' and not m.startswith('bx')):
            if '#0x' in ins.op_str:
                t = int(ins.op_str.split('#')[-1], 16)
                if addr <= t < end:
                    leaders.add(t)
        if cond and not call:
            leaders.add(pc + ins.size)   # the fall-through of a conditional branch starts a block
        pc += ins.size
    reached_code = {a for a in leaders if a < end}
    _BLOCKS[key] = reached_code
    return reached_code


_BLOCKS = {}


def check(res, obj, fname, shndx, off, oaddr, seed=1, trials=200, osize=None):
    """Differential emulation of one function. Returns (verdict, detail). osize: extent of the original (for the
    block coverage); default up to the next original function."""
    img = res.img
    lk = Linker(res)
    try:
        if off != 0:
            return 'not yet', 'emulation needs the function at the start of its section'
        new = lk.place(obj, shndx)
    except (KeyError, ValueError) as e:
        return 'not yet', f'emulation: {e}'
    stub_addrs = {}
    for name in STUBS:
        a = res.func_addr(name)
        if a is not None and a != oaddr:
            stub_addrs[a & ~1] = name
    # data the function refers to (learned or known original addresses), filled with the same random bytes
    refs = set()
    for r in obj.relocs.get(shndx, []):
        if r['r_info_type'] == E.R_ARM_ABS32:
            name, styp, ssec, _, _ = obj.sym_info(r['r_info_sym'])
            key = name if styp != 'STT_SECTION' else f'{os.path.basename(obj.path)}:{ssec}'
            a = res.data.get(key, res.learned.get(key))
            if a is not None and in_ranges(a, [(E.RAM_BASE + E.RAM_LEN, 0x00500000), (0x20000000, 0x20500000)]):
                refs.add(a)
    rsize = returns_value(obj, fname)
    if osize is None:
        starts = sorted(a for a, _ in E.orig_functions().values())
        nxt = [a for a in starts if a > oaddr]
        osize = min(nxt[0] - oaddr, 0x2000) if nxt else 0x100
        sizes = {a: n for a, n in E.orig_functions().values()}
        if oaddr in sizes:
            osize = min(osize, sizes[oaddr])
    reached = set()
    rng = random.Random(seed)
    ok = 0
    for t in range(trials):
        args = draw_args(rng)
        fill = [(a, bytes(rng.getrandbits(8) for _ in range(64))) for a in sorted(refs)]
        if fname in PRESETS:
            fill += PRESETS[fname](rng, args)
        s = rng.getrandbits(32)
        run1 = Run(img, [], stub_addrs, s, fill, args, cover=(oaddr, oaddr + osize))
        r1 = run1.go(oaddr, rsize)
        reached |= run1.blocks
        r2 = Run(img, lk.blobs, stub_addrs, s, fill, args).go(new, rsize)
        d = compare(r1, r2)
        if d:
            return 'differs', f'emulation trial {t}: {d} differs (orig ended {r1["end"]}, new {r2["end"]})'
        ok += r1['end'] == 'return'
    nblocks = len(block_starts(img, oaddr, osize))
    cov = len(reached & block_starts(img, oaddr, osize)) / max(1, nblocks)
    covtxt = f'{cov:.0%} of {nblocks} blocks reached'
    if ok == 0:
        return 'not yet', f'emulation: no trial of {trials} returned normally ({covtxt})'
    if cov < MIN_COVER:
        return 'not yet', f'emulation: {trials} trials agree but reach only {covtxt} of the original'
    return 'equivalent', f'differential emulation: {trials} trials agree ({ok} returned normally, {covtxt})'


def run(res, rows, seed=1, trials=200):
    """Emulate every function in rows (equiv_m33 byte-check rows that differ). Returns {(addr, name): (verdict, detail)}."""
    out = {}
    objs = {}
    for fname, oaddr, size, verdict, objname, detail in rows:
        path = os.path.join(E.SRC, 'out', 'obj', objname)
        if not os.path.exists(path):
            continue
        obj = objs.setdefault(path, E.Obj(path))
        for f, shndx, off, sz in obj.functions():
            if f == fname:
                v, d = check(res, obj, fname, shndx, off, oaddr, seed, trials)
                out[(oaddr, fname)] = (v, f'{d}; bytes: {detail}' if v != 'equivalent' else f'{d}; bytes: {detail}')
                print(f'equiv_m33_emu: {fname:32s} {v}: {d}', file=sys.stderr)
                break
    return out


def main():
    import argparse
    import glob
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('functions', nargs='+')
    ap.add_argument('--trials', type=int, default=200)
    ap.add_argument('--seed', type=int, default=1)
    args = ap.parse_args()
    objs = sorted(glob.glob(os.path.join(E.SRC, 'out', 'obj', '**', '*.o'), recursive=True))
    rows, res = E.check_objects(objs)
    sel = [r for r in rows if r[0] in args.functions and r[1] is not None]
    run(res, sel, args.seed, args.trials)


if __name__ == '__main__':
    main()
