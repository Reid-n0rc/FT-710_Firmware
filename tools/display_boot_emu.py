#!/usr/bin/env python3
"""T24 (DISPLAY): emulated boot of the DISPLAY image from its reset vector, with a write watch on a RAM range.

Round 6 of T24 needs to know whether the image ever writes into 0x2091D570..0x2097FFFF (ram_hi below the NORTi pool,
docs/memory-maps.md) through a computed pointer, before the hybrid link puts recreated code there. A literal scan
cannot see computed pointers, so this runs the image itself in Unicorn, from the reset vector as the CPU sees it
after the boot loader called the bank (application role: SPIBSC1 0x3FEFB018 != 0, so boot_select_bank is skipped),
through Reset_Handler, reset_in_ram (the copy loops, the MMU on), __main, __scatterload, __rt_entry and main into the
kernel and the tasks, and records every access to the watched range.

Machine model:
- the image file in the SPI flash window at the bank address (0x18400000, bank 1), on-chip RAM 0x20000000..0x209FFFFF
  and its page-interleaved mirror 0x60000000..0x609FFFFF (R01UH0403EJ0700 Table 53.1, docs/memory-maps.md: the
  same host memory mapped twice);
- the watched range (default 0x2091D000..0x2097FFFF, whole 4 KiB pages; accesses below 0x2091D570 are .bss2 and
  libspace and are counted separately) and its mirror go through mmio_map callbacks with a backing store, so every
  read and write is seen without a Unicorn memory hook (equiv_m33_emu.py: those break Thumb IT blocks);
- peripherals (0x3FE00000.., 0xE8000000.., 0xFCFE0000..) read as the last value written, XORed with seeded random
  bits on status-looking reads so that polling loops end; 0x3FEFB018 reads 0x20000000 (the boot-info block);
  the GIC CPU interface's ICCIAR (0xE820200C) returns the interrupt being injected;
- interrupts: every --slice instructions, when the CPU has IRQs unmasked, an IRQ exception is entered as the CPU
  would (IRQ mode, SPSR_irq, LR_irq = return address + 4, PC = VBAR + 0x18) with an ID drawn from the GIC handler
  table 0x208DC1E0 (the OSTM0 tick 0x86 most often, then every other registered source);
- SVC: as in equiv_display_emu.py, the image's own SVC_Handler;
- the cycle counter PMCCNTR advances by 256 at every read of it (Unicorn does not count cycles, and the image's
  delay loops poll it).

Usage: python3 -I tools/display_boot_emu.py [--image BIN] [--insns N] [--slice N] [--seed S] [--watch LO HI]
                                             [--compare out/FT-710_DISPLAY_hybrid.bin]
Prints how far the boot got (the kernel's tasks created, the functions reached), and every watched access with the
PC. --compare boots the hybrid image of tools/display_link.py too (from the same bank address, so its own
reset_in_ram loads RAM2 from the file) and checks that it gets as far: no fault, as many tasks, the GUI loop, RAM2
intact, and nothing in the watched range above RAM2's end. Nothing is written anywhere. Nothing here has been run
on a radio.
"""
import argparse
import bisect
import collections
import ctypes
import os
import random
import struct
import sys

from unicorn import Uc, UcError, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_INTR, UC_HOOK_MEM_UNMAPPED, UC_PROT_ALL, \
    UC_HOOK_BLOCK, UC_HOOK_CODE
from unicorn import arm_const as A

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = 0x20100000
BANK = 0x18400000
RAM2, RAM2_FILE_OFF = 0x20920000, 0x340000
TEXT_END = 0x20165178
PMU_STEP = 256
RAM_LO, RAM_SIZE = 0x20000000, 0xA00000
LIBSPACE_END = 0x2091D570           # end of .bss2 (Region$$Table region 5), docs/memory-maps.md
ICCIAR = 0xE820200C
GIC_TABLE, GIC_IDS = 0x208DC1E0, 587
OSTM0_ID = 0x86
MMIO = [(0x3FE00000, 0x40000000), (0xE8000000, 0xE8300000), (0xFCFE0000, 0xFD000000)]
# mirror block (1 MB, top 12 bits) -> normal block (Table 53.1)
MIRROR = {0x600: 0x200, 0x601: 0x205, 0x602: 0x206, 0x603: 0x201, 0x604: 0x202, 0x605: 0x207, 0x606: 0x208,
          0x607: 0x203, 0x608: 0x204, 0x609: 0x209}
HANG = {0x2010021C: 'FIQ_Handler', 0x20100220: 'Undef_Handler', 0x20100224: 'PAbort_Handler',
        0x20100228: 'DAbort_Handler'}


def read_tsv(path):
    with open(path, encoding='utf-8') as f:
        return [ln.rstrip('\n').split('\t') for ln in f if ln.strip() and not ln.startswith('#')]


def image_path():
    for d in (os.environ.get('FT710_BUILD'), os.path.join(ROOT, 'build'), '/home/user/FT-710_Firmware/build'):
        if d and os.path.exists(os.path.join(d, 'FT-710_DISPLAY_V0108.bin')):
            return os.path.join(d, 'FT-710_DISPLAY_V0108.bin')
    sys.exit('display_boot_emu: FT-710_DISPLAY_V0108.bin not found (set FT710_BUILD)')


class Boot:
    def __init__(self, image, seed, watch, slice_, entries=None, ram2=None):
        self.uc = uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        try:
            uc.ctl_set_cpu_model(A.UC_CPU_ARM_CORTEX_A9)
        except Exception:
            pass
        self.rng = random.Random(seed)
        self.slice = slice_
        self.wlo, self.whi = watch
        self.ram = ctypes.create_string_buffer(RAM_SIZE)
        base = ctypes.addressof(self.ram)
        # normal RAM and the mirror share one host buffer; the watched pages are cut out of both
        for lo in range(RAM_LO, RAM_LO + RAM_SIZE, 0x100000):
            self._map_block(lo, lo, base)
        for m, n in MIRROR.items():
            self._map_block(m << 20, n << 20, base)
        uc.mem_map(0x18000000, 0x1000000, UC_PROT_ALL)
        uc.mem_write(BANK, image)
        self.ram2 = ram2
        for lo, hi in MMIO:
            uc.mmio_map(lo, hi - lo, self.on_io_read, lo, self.on_io_write, lo)
        self.io = {}
        self.watched = []           # (kind, address, size, value, pc, lr, mode)
        self.libspace = 0
        self.extra_maps = []
        self.inject = None
        self.irqs = collections.Counter()
        self.svcs = 0
        self.entries = set(entries or ())
        self.reached = set()
        if self.entries:
            uc.hook_add(UC_HOOK_BLOCK, self.on_block)
        uc.hook_add(UC_HOOK_INTR, self.on_intr)
        # PMCCNTR does not count in Unicorn, so the image's cycle-counter delays (cpu_delay_cycles4 & co.) would
        # spin for ever: every A32 "mrc p15, 0, rt, c9, c13, 0" of .text first advances it by PMU_STEP
        self.ccnt = 0
        n = (TEXT_END - BASE) // 4
        for k, w in enumerate(struct.unpack(f'<{n}I', image[:4 * n])):
            if w & 0x0FFF0FFF == 0x0E190F1D:
                a = BASE + 4 * k
                uc.hook_add(UC_HOOK_CODE, self.on_ccnt, begin=a, end=a)
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self.on_unmapped)

    def _map_block(self, va, normal, base):
        """Map one 1 MB block at va onto the host RAM of normal block `normal`, with the watched pages as MMIO."""
        uc = self.uc
        lo, hi = va, va + 0x100000
        wlo = self.wlo - normal + va
        whi = self.whi - normal + va
        cuts = [(lo, hi)]
        if wlo < hi and whi > lo:
            cuts = [(lo, max(lo, wlo)), (min(hi, whi), hi)]
            a, b = max(lo, wlo), min(hi, whi)
            uc.mmio_map(a, b - a, self.on_w_read, a - va + normal, self.on_w_write, a - va + normal)
        for a, b in cuts:
            if b > a:
                uc.mem_map_ptr(a, b - a, UC_PROT_ALL, base + (a - va + normal - RAM_LO))

    def on_ccnt(self, uc, addr, size, _):
        self.ccnt = (self.ccnt + PMU_STEP) & 0xFFFFFFFF
        uc.reg_write(A.UC_ARM_REG_CP_REG, (15, 0, 0, 9, 13, 0, 0, self.ccnt))

    def on_block(self, uc, addr, size, _):
        a = addr & ~1
        if a in self.entries:
            self.reached.add(a)

    # --- watched RAM
    def _ctx(self):
        uc = self.uc
        return uc.reg_read(A.UC_ARM_REG_PC), uc.reg_read(A.UC_ARM_REG_LR), uc.reg_read(A.UC_ARM_REG_CPSR) & 0x1F

    def on_w_read(self, uc, off, size, normal):
        a = normal + off
        v = int.from_bytes(self.ram.raw[a - RAM_LO:a - RAM_LO + size], 'little')
        if a >= LIBSPACE_END:
            self.watched.append(('r', a, size, v) + self._ctx())
        else:
            self.libspace += 1
        return v

    def on_w_write(self, uc, off, size, value, normal):
        a = normal + off
        ctypes.memmove(ctypes.addressof(self.ram) + a - RAM_LO, (value & ((1 << (8 * size)) - 1)).to_bytes(size, 'little'),
                       size)
        if a >= LIBSPACE_END:
            self.watched.append(('w', a, size, value) + self._ctx())
        else:
            self.libspace += 1

    # --- peripherals
    def on_io_read(self, uc, off, size, base):
        a = base + off
        if a == 0x3FEFB018:
            return 0x20000000          # the boot-info block: "the loader already ran" (boot-rtos.md section 1)
        if a == ICCIAR:
            v, self.inject = (self.inject if self.inject is not None else 1023), None
            return v
        v = self.io.get(a, 0)
        return (v ^ self.rng.getrandbits(8 * size)) if self.rng.random() < 0.5 else v

    def on_io_write(self, uc, off, size, value, base):
        self.io[base + off] = value & ((1 << (8 * size)) - 1)

    def on_unmapped(self, uc, access, addr, size, value, _):
        page = addr & ~0xFFF
        if len(self.extra_maps) > 64:
            return False
        uc.mem_map(page, 0x1000, UC_PROT_ALL)
        self.extra_maps.append((page, access, self._ctx()[0]))
        return True

    def on_intr(self, uc, intno, _):
        if intno != 2:
            raise RuntimeError(f'exception {intno} at {uc.reg_read(A.UC_ARM_REG_PC):#x}')
        self.svcs += 1
        cpsr = uc.reg_read(A.UC_ARM_REG_CPSR)
        pc = uc.reg_read(A.UC_ARM_REG_PC)
        uc.reg_write(A.UC_ARM_REG_CPSR, (cpsr & ~0x3F) | 0x93)
        uc.reg_write(A.UC_ARM_REG_SPSR, cpsr)
        uc.reg_write(A.UC_ARM_REG_LR, pc | (1 if cpsr & 0x20 else 0))
        uc.reg_write(A.UC_ARM_REG_PC, self.vbar() + 8)

    def vbar(self):
        try:
            return self.uc.reg_read(A.UC_ARM_REG_CP_REG, (15, 0, 0, 12, 0, 0, 0)) or BASE
        except Exception:
            return BASE

    def irq(self):
        """Enter an IRQ exception if the CPU has IRQs unmasked; True if one was entered."""
        uc = self.uc
        cpsr = uc.reg_read(A.UC_ARM_REG_CPSR)
        if cpsr & 0x80:
            return False
        table = struct.unpack(f'<{GIC_IDS}I', bytes(uc.mem_read(GIC_TABLE, 4 * GIC_IDS)))
        default = collections.Counter(table).most_common(1)[0][0]
        ids = [k for k, h in enumerate(table) if h and h != default]
        if not ids:
            return False
        iid = OSTM0_ID if OSTM0_ID in ids and self.rng.random() < 0.5 else self.rng.choice(ids)
        self.inject = iid
        self.irqs[iid] += 1
        pc = uc.reg_read(A.UC_ARM_REG_PC)
        uc.reg_write(A.UC_ARM_REG_CPSR, (cpsr & ~0x3F) | 0x92 | 0x80)
        uc.reg_write(A.UC_ARM_REG_SPSR, cpsr)
        uc.reg_write(A.UC_ARM_REG_LR, pc + 4)
        uc.reg_write(A.UC_ARM_REG_PC, self.vbar() + 0x18)
        return True

    def run(self, insns):
        """Run (or continue) for about insns instructions."""
        uc = self.uc
        if not hasattr(self, 'pc'):
            self.pc, self.done, self.trace, self.stop = BANK + 0x2C, 0, collections.Counter(), None   # Reset_Handler
            uc.reg_write(A.UC_ARM_REG_CPSR, 0x1D3)
        pc, done, insns = self.pc, self.done, self.done + insns
        while done < insns and self.stop is None:
            try:
                uc.emu_start(pc, 0, count=self.slice)
            except UcError as e:
                self.stop = f'{e} at {uc.reg_read(A.UC_ARM_REG_PC):#x}'
                break
            except RuntimeError as e:
                self.stop = str(e)
                break
            done += self.slice
            pc = uc.reg_read(A.UC_ARM_REG_PC)
            self.trace[pc & ~0xFF] += 1
            if pc in HANG:
                self.stop = f'{HANG[pc]} reached (lr {uc.reg_read(A.UC_ARM_REG_LR):#x})'
                break
            self.irq()
            pc = uc.reg_read(A.UC_ARM_REG_PC)
            if uc.reg_read(A.UC_ARM_REG_CPSR) & 0x20:
                pc |= 1
        self.pc, self.done = pc, done


def report(label, b, watch, funcs, extra=None):
    """Print what the boot reached and what it did in the watched range; return a summary."""
    addrs = [a for a, _ in funcs]

    def name(a):
        a &= ~1
        k = bisect.bisect_right(addrs, a) - 1
        return f'{funcs[k][1]}+{a - funcs[k][0]:#x}' if k >= 0 else f'{a:#x}'
    uc = b.uc
    tcbs = struct.unpack('<64I', bytes(uc.mem_read(0x208DBBA0, 256)))
    pc = uc.reg_read(A.UC_ARM_REG_PC)
    print(f'display_boot_emu: {label}: {b.done:,} instructions in slices of {b.slice:,}; stopped: '
          f'{b.stop or "budget"}; pc {pc:#x} ({name(pc)})')
    print(f'  SVCs {b.svcs:,}; IRQs injected {sum(b.irqs.values()):,} over {len(b.irqs)} sources')
    print(f'  kernel TCB pointers set: {sum(1 for t in tcbs if t)} (table 0x208DBBA0)')
    print(f'  image functions reached: {len(b.reached)} of {len(addrs)}; task_root {0x201170C8 in b.reached}, '
          f'gui_main_loop {0x20130188 in b.reached}' + (f'; {extra}' if extra else ''))
    # task_root's stack is the pool's first block; itron_acre_tsk fills a new stack with the task ID, so the
    # first word above its bottom that differs from the fill is the deepest the stack went (memory-maps.md ram_hi)
    bottom = 0x20980028
    fill = struct.unpack('<I', bytes(uc.mem_read(bottom, 4)))[0]
    k = 0
    while k < 0x2000 and struct.unpack('<I', bytes(uc.mem_read(bottom + k, 4)))[0] == fill:
        k += 4
    print(f'  task_root stack (from {bottom:#x}, fill {fill:#x}): {k} bytes at its bottom never used')
    print(f'  pages mapped on demand: {[(hex(p), a, name(pc)) for p, a, pc in b.extra_maps[:10]]}')
    print('  where the slices ended (most often): ' + ', '.join(f'{name(a)} x{n}' for a, n in b.trace.most_common(6)))
    print(f'  watched {watch[0]:#x}..{watch[1]:#x}: {b.libspace} accesses below {LIBSPACE_END:#x} (.bss2 / libspace), '
          f'{len(b.watched)} at or above it')
    by = collections.Counter((k, name(pc)) for k, a, s, v, pc, lr, m in b.watched)
    for (k, n), c in by.most_common(40):
        ex = next(x for x in b.watched if x[0] == k and name(x[4]) == n)
        print(f'    {k} {c:6d} x by {n} (first {ex[1]:#x}, size {ex[2]}, lr {name(ex[5])}, mode {ex[6]:#x})')
    if b.watched:
        print(f'    span {min(x[1] for x in b.watched):#x}..{max(x[1] + x[2] for x in b.watched):#x}')
    return {'stop': b.stop, 'reached': len(b.reached), 'tasks': sum(1 for t in tcbs if t),
            'gui': 0x20130188 in b.reached, 'watched': len(b.watched)}


def hybrid_code(elf):
    """Start addresses of the recreated functions in a hybrid ELF (display_link.py) and RAM2's end."""
    from elftools.elf.elffile import ELFFile
    out, ram2_end = set(), RAM2
    with open(elf, 'rb') as f:
        e = ELFFile(f)
        secs = [s for s in e.iter_sections()]
        for s in e.get_section_by_name('.symtab').iter_symbols():
            if s.name == '__ram2_end':
                ram2_end = s['st_value']
            sh = s['st_shndx']
            if s['st_info']['type'] == 'STT_FUNC' and isinstance(sh, int) and secs[sh].name != '.image':
                out.add(s['st_value'] & ~1)
    return out, ram2_end


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--image', default=None, help='the image to boot (default: build/FT-710_DISPLAY_V0108.bin)')
    ap.add_argument('--compare', metavar='HYBRID', default=None,
                    help='also boot this hybrid image (display_link.py; its ELF next to it) with the same seed')
    ap.add_argument('--insns', type=int, default=1_500_000_000)
    ap.add_argument('--slice', type=int, default=50_000)
    ap.add_argument('--seed', type=int, default=1)
    ap.add_argument('--watch', nargs=2, default=['0x2091D000', '0x20980000'])
    args = ap.parse_args()
    watch = tuple(int(x, 0) for x in args.watch)
    funcs = sorted((int(r[0], 16), r[1]) for r in read_tsv(os.path.join(ROOT, 'decomp/display/functions.tsv'))[1:]
                   if int(r[0], 16) >= BASE)
    addrs = [a for a, _ in funcs]
    img = open(args.image or image_path(), 'rb').read()
    b = Boot(img, args.seed, watch, args.slice, entries=addrs)
    b.run(args.insns)
    orig = report(f'original, seed {args.seed}', b, watch, funcs)
    if not args.compare:
        return
    hyb = open(args.compare, 'rb').read()
    code, ram2_end = hybrid_code(os.path.join(os.path.dirname(args.compare), 'display_hybrid.elf'))
    hwatch = (max(watch[0], (ram2_end + 0xFFF) & ~0xFFF), watch[1])
    b2 = Boot(hyb, args.seed, hwatch, args.slice, entries=set(addrs) | code)
    b2.run(args.insns)
    ran = len(b2.reached & code)
    ram2 = hyb[RAM2_FILE_OFF:]
    loaded = bytes(b2.uc.mem_read(RAM2, len(ram2))) == ram2 if ram2 else None
    h = report(f'hybrid, seed {args.seed}', b2, hwatch, funcs,
               extra=f'recreated functions executed: {ran} of {len(code)}; RAM2 '
                     + ('empty' if loaded is None else f'{len(ram2)} bytes, loaded intact: {loaded}'))
    ok = (h['stop'] is None and h['tasks'] == orig['tasks'] and h['gui'] == orig['gui'] and loaded is not False
          and h['watched'] == 0)
    print(f'display_boot_emu: hybrid boot {"agrees with" if ok else "DIFFERS from"} the original (no fault, same '
          f'number of tasks, GUI loop reached alike, RAM2 intact, nothing in the watched range)')
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
