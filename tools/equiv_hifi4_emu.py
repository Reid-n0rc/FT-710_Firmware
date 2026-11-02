#!/usr/bin/env python3
"""T24 (IFDSP HiFi4): differential emulation of recreated HiFi4 functions in Ghidra's p-code emulator.

The HiFi4 image was built with Cadence XCC, which is proprietary (docs/tasks/T24-source-recreation.md, "IFDSP HiFi4"),
so the recreated source (src/ifdsp_hifi4/, built with the Zephyr SDK 0.17.0 GCC 12.2 for the RT600 HiFi4 core) cannot
be byte-identical; it is checked like the MAIN code: the original function and the recompiled one run from the same
start state on the same inputs, and their results and side effects are compared. Unicorn has no Xtensa, so the runs
happen in Ghidra's p-code emulator on the generated language Xtensa:LE:32:rt600hifi4 (T21a), driven by the server
script tools/ghidra/EquivHifi4Emu.java (one headless Ghidra per worker), which also executes the windowed ABI
(CALLn, ENTRY, RETW) and the zero-overhead loop end itself (its header says why).

Linking: each recreated function is linked on its own with the Zephyr SDK ld: its literals at 0x1B0000, code at
0x1B8000, read-only data at 0x1C8000 (the scratch area: SRAM that the DSP image never uses, inside CALL8's +-512 KB of
the image's .text 0x207000..0x2367FF). The linker script defines every other function name of
decomp/ifdsp/hifi4/functions.tsv (and src/ifdsp_hifi4/aliases.tsv) at its original address, so the recreated function
calls the image's own callees; every variable the recreated objects define (.data/.bss sections, one per variable with
-fdata-sections) is placed at its address in the image from src/ifdsp_hifi4/data_symbols.tsv, and is not loaded: the
image's own state is used. A variable without a row there makes the function "not yet".

Start state (both runs): the three DSP images where the M33 loader puts them (TCM 0x24000000, SRAM 0x200000 with
.data at 0x236800, the zero image at 0x20040000), .bss zero; the caller's window holds SP = 0x1E0000, a8 = the
return address of a CALL8 and the arguments in a10..a15 (the callee's a2..a7). Inputs per trial: the arguments drawn
by the recreated function's DWARF parameter types (a 64-bit argument takes an even/odd register pair, a float its bit
pattern, a pointer a random buffer or string at 0x180000..); the bytes of .data/.bss/heap that the functions read
before writing them (collected over the earlier trials) filled with random words, small values or pointers into a
buffer at 0x1A8000; PRESETS build valid state where a function needs one. Peripheral reads (0x40000000..) return
values from a seeded sequence; every peripheral access is recorded; any access outside SRAM, its alias, the TCM and
the peripherals ends the run as a fault. Calls to the functions in STUBS are recorded instead of run.

Equivalent when every compared trial agrees on: the way it ended (return, fault and its address, budget, "hang" = a
jump to itself), the return value (a2, a2:a3 for 8 bytes, masked to the DWARF size; a float result is aed0 for the
original and a2 for the recreated code, and two NaNs agree), the window and SP after the return, the argument
buffers, .data/.bss/heap 0x236800..0x2FFFFF and the shared SRAM 0x20000000..0x2007FFFF after the run (an address of a
recreated function stored as data counts as its original's address: a static callback cannot be linked to the
image's), the sequence of peripheral accesses, the stub calls, and for the functions in AE_STATE the AE/FP registers
(the Xtensa windowed ABI keeps them caller-saved, so the others may leave scratch values there); and at least a tenth
of the trials returned normally (MIN_RETURNS); and the trials together reached at least half of the original's basic
blocks (Ghidra's SimpleBlockModel). Not compared, and counted in the detail: trials where both runs exhaust the budget
and trials where both fault (random pointers into unmapped memory, which the two builds dereference in another order).
A recreated function that takes or returns a float is linked as the callee of the other recreated functions (the
image's version takes its floats in aed0..); one that calls an image function with a float argument cannot be
checked. A trial where only the original stops at an operation the harness does not model makes the function
"not yet".

Usage:
  python3 -I tools/equiv_hifi4_emu.py check FUNCTION... [--trials N] [--seed S] [--jobs J]
  python3 -I tools/equiv_hifi4_emu.py status [--trials N] [--jobs J]   every recreated function -> src/ifdsp_hifi4/status.tsv
  python3 -I tools/equiv_hifi4_emu.py trace FUNCTION [--seed S] [--orig]   one trial with a register trace
Environment: FT710_IFDSP_PROJECT (Ghidra project directory holding FT710_IFDSP; default /home/user/ghidra_tasks/
t24hifi4/proj, a copy of ghidra/; every worker copies it again to a temporary directory, since Ghidra locks an open
project), GHIDRA_JAVA_HOME, HIFI4_CROSS (tool prefix, default the Zephyr SDK 0.17.0 RT600 toolchain under /root/opt),
FT710_BUILD. The images are read from build/; they are never written anywhere.
"""
import argparse
import bisect
import glob
import json
import math
import os
import random
import re
import shutil
import struct
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'src/ifdsp_hifi4')
FUNCS_TSV = os.path.join(ROOT, 'decomp/ifdsp/hifi4/functions.tsv')
DATA_TSV = os.path.join(SRC, 'data_symbols.tsv')
ALIAS_TSV = os.path.join(SRC, 'aliases.tsv')
STATUS_TSV = os.path.join(SRC, 'status.tsv')
CROSS = os.environ.get('HIFI4_CROSS', '/root/opt/zephyr-sdk-0.17.0/xtensa-nxp_rt600_adsp_zephyr-elf/bin/'
                                      'xtensa-nxp_rt600_adsp_zephyr-elf-')

IMG0_LEN, IMG1_LEN, IMG2_LEN = 0x20644, 0x383B4, 0x31E0      # tools/ghidra/IfdspHifi4Setup.java
LIT, SCRATCH, RODATA = 0x1B0000, 0x1B8000, 0x1C8000
STACK = 0x1E0000
ARGBUF = 0x180000                  # argument buffers, 0x2000 apart
FILLBUF = 0x1A8000                 # target of pointer-valued globals
SNAP = [(ARGBUF, ARGBUF + 0x10000), (0x236800, 0x300000), (0x20000000, 0x20080000)]
TRACK = [(0x236800, 0x2D0000),      # .data/.bss/heap: bytes read before written get random values
         (0x20070000, 0x20080000)]   # the shared register file
BUDGET = 400000
MIN_COVER = 0.5
MIN_RETURNS = 0.1               # equivalent needs a tenth of the trials to return normally (the rest may fault)
NREG = 6

# Functions run as stubs (recorded, return a seeded value) instead of the image's code: the XOS kernel calls (they
# switch threads and raise the interrupt level, which a single-function run cannot model). name -> arguments recorded.
STUBS = {'xos_mutex_lock': 1, 'xos_mutex_unlock': 1, 'xos_mutex_create': 3, 'xos_mutex_delete': 1,
         'xos_mutex_lock_timeout': 2, 'xos_mutex_trylock': 1,
         'xos_msgq_put': 2, 'xos_msgq_get': 2, 'xos_msgq_put_timeout': 3, 'xos_msgq_get_timeout': 3,
         'xos_thread_sleep': 1, 'xos_register_interrupt_handler': 3, 'xos_interrupt_enable': 1,
         'xos_interrupt_disable': 1, 'xos_thread_create': 6,
         # the Xtensa HAL's cache-attribute and TLB writes (wdtlb/witlb, cache loops) are not modelled
         'xthal_set_region_attribute': 4,
         # rpmsg-lite's busy wait on CCOUNT (env_sleep_msec): the cycle counter is a seeded random value here
         'platform_time_delay': 1}
AE_STATE = set()                   # functions whose AE/FP register state after the return is compared


def read_tsv(path):
    rows = []
    with open(path, encoding='utf-8') as f:
        for ln in f:
            if ln.startswith('#') or not ln.strip():
                continue
            rows.append(ln.rstrip('\n').split('\t'))
    return rows


def tool(name):
    return CROSS + name


class Image:
    def __init__(self):
        p = os.path.join(os.environ.get('FT710_BUILD', os.path.join(ROOT, 'build')), 'FT-710_IFDSP_V0101_hifi4.bin')
        if not os.path.exists(p):
            sys.exit(f'equiv_hifi4_emu: {p} not found (decode the firmware, or set FT710_BUILD)')
        with open(p, 'rb') as f:
            d = f.read()
        self.segs = [(0x24000000, d[0:0x10000]), (0x24020000, d[0x20000:IMG0_LEN]),
                     (0x200000, d[IMG0_LEN:IMG0_LEN + IMG1_LEN]),
                     (0x20040000, d[IMG0_LEN + IMG1_LEN:IMG0_LEN + IMG1_LEN + IMG2_LEN])]
        self.sram = d[IMG0_LEN:IMG0_LEN + IMG1_LEN]

    def read(self, a, n):
        return self.sram[a - 0x200000:a - 0x200000 + n]


class Originals:
    def __init__(self):
        rows = read_tsv(FUNCS_TSV)[1:]
        self.funcs = {r[1]: (int(r[0], 16), int(r[2])) for r in rows}
        self.entries = sorted(a for a, _ in self.funcs.values())
        self.alias = {r[0]: int(r[1], 16) for r in read_tsv(ALIAS_TSV)[1:]} if os.path.exists(ALIAS_TSV) else {}
        self.data = {r[0]: int(r[1], 16) for r in read_tsv(DATA_TSV)[1:]} if os.path.exists(DATA_TSV) else {}
        clash = sorted(set(self.data) & (set(self.funcs) | set(self.alias)))
        if clash:      # the link script defines function names hard, so the variable would get the function's address
            sys.exit(f'equiv_hifi4_emu: data_symbols.tsv names that are also function names: {", ".join(clash)}')

    def addr(self, name):
        if name in self.alias:
            return self.alias[name]
        f = self.funcs.get(name)
        return f[0] if f else None

    def extent(self, a):
        i = bisect.bisect_right(self.entries, a)
        return (self.entries[i] - a) if i < len(self.entries) else 0x100


def objects():
    return sorted(glob.glob(os.path.join(SRC, 'out', 'obj', '**', '*.o'), recursive=True))


def recreated():
    """(object path, function name) of every global function defined in the built objects."""
    from elftools.elf.elffile import ELFFile
    out = []
    for p in objects():
        with open(p, 'rb') as f:
            elf = ELFFile(f)
            for s in elf.get_section_by_name('.symtab').iter_symbols():
                if s['st_info']['type'] == 'STT_FUNC' and s['st_info']['bind'] == 'STB_GLOBAL' and \
                        isinstance(s['st_shndx'], int):
                    out.append((p, s.name))
    return out


def data_sections():
    """{input section name: (variable, writable)} of every .data/.bss/.rodata section of the objects that holds one
    variable (-fdata-sections)."""
    from elftools.elf.elffile import ELFFile
    out = {}
    for p in objects():
        with open(p, 'rb') as f:
            for s in ELFFile(f).iter_sections():
                m = re.match(r'\.(s?bss|s?data|rodata)\.(.+)$', s.name)
                if m and s['sh_size'] and not re.search(r'\.(str|cst)\d', m.group(2)):
                    out[s.name] = (m.group(2), m.group(1) != 'rodata')
    return out


def link(orig, fname, workdir):
    """Link fname alone at the scratch address. Returns (elf path, error)."""
    names = dict((n, a) for n, (a, _) in orig.funcs.items())
    names.update(orig.alias)
    lines = [f'ENTRY({fname})', 'SECTIONS {']
    # a variable of data_symbols.tsv sits at its image address: .data/.bss not loaded (the image's own state is
    # used), a constant table loaded over the image's copy (the same bytes unless it points to the function under
    # test); these come first, so that the wildcards below do not take their sections
    for sec, (var, writable) in sorted(data_sections().items()):
        if var in orig.data:
            lines.append(f'  "{sec}" 0x{orig.data[var]:08X}{" (NOLOAD)" if writable else ""} : {{ *("{sec}") }}')
    lines += [f'  .lit 0x{LIT:08X} : {{ *(.literal .literal.*) }}',
              f'  .text 0x{SCRATCH:08X} : {{ *(.text .text.*) }}',
              f'  .rodata 0x{RODATA:08X} : {{ *(.rodata .rodata.* .srodata*) }}',
              '  .data : { *(.data .data.* .sdata*) }', '  .bss : { *(.bss .bss.* .sbss* COMMON) }',
              '  /DISCARD/ : { *(.comment) *(.xt.prop*) *(.xtensa.info) }', '}']
    # a recreated function with a float in its signature is called as recreated, not as the image's: the image's
    # takes its floats in aed0.. (XCC), GCC passes them in address registers
    soft = soft_float_functions()
    for n, a in sorted(names.items()):
        if n == fname or n in soft or not re.match(r'^[A-Za-z_][A-Za-z0-9_.$]*$', n):
            continue
        lines.append(f'"{n}" = 0x{a:08X};')
    for n, a in sorted(orig.data.items()):
        lines.append(f'PROVIDE("{n}" = 0x{a:08X});')
    script = os.path.join(workdir, f'{fname}.ld')
    out = os.path.join(workdir, f'{fname}.elf')
    with open(script, 'w') as f:
        f.write('\n'.join(lines) + '\n')
    r = subprocess.run([tool('ld'), '-T', script, '--gc-sections', '-o', out] + objects() + [libgcc()],
                       capture_output=True, text=True)
    if r.returncode != 0:
        err = [x for x in r.stderr.strip().splitlines() if 'warning' not in x]
        return None, (err[-1] if err else 'ld failed')
    return out, None


_SOFT = None


def soft_float_functions():
    """Names of the recreated functions (defined in the objects) that take or return a float. Read from one link of
    all objects (pyelftools cannot apply the Xtensa relocations of the objects' DWARF)."""
    global _SOFT
    if _SOFT is None:
        from elftools.elf.elffile import ELFFile
        _SOFT = set()
        with tempfile.TemporaryDirectory(prefix='equiv_hifi4_all_') as d:
            out = os.path.join(d, 'all.elf')
            subprocess.run([tool('ld'), '-e', '0', '--unresolved-symbols=ignore-all', '-Ttext', f'0x{SCRATCH:X}',
                            '-o', out] + objects(), capture_output=True, check=True)
            with open(out, 'rb') as f:
                elf = ELFFile(f)
                defined = {sy.name for sy in elf.get_section_by_name('.symtab').iter_symbols()
                           if sy['st_info']['type'] == 'STT_FUNC' and sy['st_shndx'] != 'SHN_UNDEF'}
                for cu in elf.get_dwarf_info().iter_CUs():
                    for die in cu.iter_DIEs():
                        if die.tag != 'DW_TAG_subprogram' or 'DW_AT_name' not in die.attributes:
                            continue
                        n = die.attributes['DW_AT_name'].value.decode()
                        if n not in defined or n in _SOFT:
                            continue
                        ret, params = dwarf_signature(elf, n)
                        if (ret and ret[1] == 'float') or any(k == 'float' for k, _, _ in params):
                            _SOFT.add(n)
    return _SOFT


_LIBGCC = None


def libgcc():
    global _LIBGCC
    if _LIBGCC is None:
        _LIBGCC = subprocess.run([tool('gcc'), '-print-libgcc-file-name'], capture_output=True, text=True,
                                 check=True).stdout.strip()
    return _LIBGCC


class Linked:
    def __init__(self, path, fname, orig):
        from elftools.elf.elffile import ELFFile
        with open(path, 'rb') as f:
            elf = ELFFile(f)
            self.segs, self.rw = [], []
            for s in elf.iter_sections():
                if not (s['sh_flags'] & 2) or not s['sh_size']:          # SHF_ALLOC
                    continue
                a = s['sh_addr']
                if s['sh_flags'] & 1 and not (s['sh_flags'] & 4):          # SHF_WRITE, not code
                    if not any(a == v for v in orig.data.values()):
                        self.rw.append(s.name)
                elif s['sh_type'] == 'SHT_PROGBITS' and s.name not in ('.data', '.bss'):
                    self.segs.append((a, s.data()))
            syms = list(elf.get_section_by_name('.symtab').iter_symbols())
            # recreated functions that have an original: a pointer to one stored as data is compared as the
            # original's address (static callbacks such as rpmsg_ns_rx_cb cannot be linked to the image's)
            self.funcmap = {s['st_value']: orig.addr(s.name) for s in syms
                            if s['st_info']['type'] == 'STT_FUNC' and orig.addr(s.name) is not None
                            and SCRATCH <= s['st_value'] < RODATA}
            sym = next(s for s in syms if s.name == fname)
            self.entry, self.size = sym['st_value'], sym['st_size']
            self.ret, self.params = dwarf_signature(elf, fname)


def dwarf_signature(elf, fname):
    """(return (size, kind) or None for void, [(kind, size, signed)]): kind 'ptr', 'int' or 'float'."""
    def base(die):
        while die is not None and die.tag in ('DW_TAG_typedef', 'DW_TAG_const_type', 'DW_TAG_volatile_type'):
            die = die.get_DIE_from_attribute('DW_AT_type') if 'DW_AT_type' in die.attributes else None
        return die

    def desc(die):
        t = base(die)
        if t is None:
            return ('int', 4, False)
        if t.tag == 'DW_TAG_pointer_type':
            return ('ptr', 4, False)
        size = t.attributes['DW_AT_byte_size'].value if 'DW_AT_byte_size' in t.attributes else 4
        enc = t.attributes['DW_AT_encoding'].value if 'DW_AT_encoding' in t.attributes else 7
        if enc == 4:
            return ('float', size, True)
        return ('int', size, enc in (5, 6))

    if not elf.has_dwarf_info():
        return (4, 'int'), [('int', 4, False)] * NREG
    for cu in elf.get_dwarf_info().iter_CUs():
        for die in cu.iter_DIEs():
            if die.tag != 'DW_TAG_subprogram' or 'DW_AT_name' not in die.attributes:
                continue
            if die.attributes['DW_AT_name'].value.decode() != fname or 'DW_AT_declaration' in die.attributes:
                continue
            ret = None
            if 'DW_AT_type' in die.attributes:
                k, s, _ = desc(die.get_DIE_from_attribute('DW_AT_type'))
                ret = (s, k)
            params = [desc(c.get_DIE_from_attribute('DW_AT_type')) for c in die.iter_children()
                      if c.tag == 'DW_TAG_formal_parameter' and 'DW_AT_type' in c.attributes]
            return ret, params
    return (4, 'int'), [('int', 4, False)] * NREG


class Engine:
    """One headless Ghidra running tools/ghidra/EquivHifi4Emu.java."""

    def __init__(self, img):
        src = os.environ.get('FT710_IFDSP_PROJECT', '/home/user/ghidra_tasks/t24hifi4/proj')
        self.tmp = tempfile.mkdtemp(prefix='equiv_hifi4_proj_')
        proj = os.path.join(self.tmp, 'proj')
        os.mkdir(proj)
        shutil.copy(os.path.join(src, 'FT710_IFDSP.gpr'), proj)
        shutil.copytree(os.path.join(src, 'FT710_IFDSP.rep'), os.path.join(proj, 'FT710_IFDSP.rep'),
                        ignore=shutil.ignore_patterns('*.lock*', '*~'))
        env = dict(os.environ)
        env.setdefault('GHIDRA_JAVA_HOME', '/usr/lib/jvm/java-21-openjdk-amd64')
        env.setdefault('MAXMEM', '1500M')
        self.log = tempfile.NamedTemporaryFile('w+', prefix='equiv_hifi4_emu_', suffix='.log', delete=False)
        self.p = subprocess.Popen([os.path.join(ROOT, 'tools/ghidra-headless.sh'), proj, 'FT710_IFDSP', '-process',
                                   'FT-710_IFDSP_V0101_hifi4.bin', '-noanalysis', '-readOnly',
                                   '-scriptPath', os.path.join(ROOT, 'tools/ghidra'), '-postScript', 'EquivHifi4Emu.java'],
                                  stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=self.log, text=True, env=env)
        self.recv()
        self.send({'op': 'base', 'name': 'image', 'segs': [[a, d.hex()] for a, d in img.segs]})

    def recv(self):
        for line in self.p.stdout:
            if line.startswith('@@EQ '):
                return json.loads(line[5:])
            self.log.write(line)
        raise RuntimeError(f'equiv_hifi4_emu: Ghidra ended (log {self.log.name})')

    def send(self, q):
        self.p.stdin.write(json.dumps(q) + '\n')
        self.p.stdin.flush()
        r = self.recv()
        if 'error' in r:
            raise RuntimeError(f'equiv_hifi4_emu: {r["error"]}')
        return r

    def close(self):
        try:
            self.p.stdin.write('{"op":"quit"}\n')
            self.p.stdin.flush()
            self.p.wait(timeout=60)
        except Exception:
            self.p.kill()
        self.log.close()
        if os.path.exists(self.log.name) and not os.environ.get('EQUIV_HIFI4_KEEP_LOG'):
            os.unlink(self.log.name)
        shutil.rmtree(self.tmp, ignore_errors=True)


SPECIAL_FLOATS = [0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 1e-3, 1e3, 3.4e38, 1e-38, 1e-45, float('inf'), float('-inf'),
                  float('nan'), 0.70710678, 32767.0, 32768.0, -32768.0, 2147483648.0, -2147483904.0, 0.999999]


def f2u(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def u2f(u):
    return struct.unpack('<f', struct.pack('<I', u & 0xFFFFFFFF))[0]


def draw_float(rng):
    x = rng.random()
    if x < 0.3:
        return f2u(rng.choice(SPECIAL_FLOATS))
    if x < 0.8:
        return f2u(rng.uniform(-2.0, 2.0) * 10 ** rng.randrange(-3, 4))
    return rng.getrandbits(32)


def draw_value(rng, size, signed):
    v = rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 0x0F, 0x10, 0x3F, 0x40, 0x41, 0x7F, 0x80, 0xFF, 0x100, 0x1FF, 0x7FFF,
                    0x8000, 0xFFFF, 0x10000, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF]) if rng.random() < 0.5 \
        else rng.getrandbits(8 * size)
    v &= (1 << (8 * size)) - 1
    if signed and v >> (8 * size - 1):
        v -= 1 << (8 * size)
    return v & 0xFFFFFFFF


def draw_args(rng, params):
    """Per parameter: a list of 32-bit words (two for 8 bytes), and the buffers to load."""
    vals, loads = [], []
    for k, (kind, size, signed) in enumerate(params or [('int', 4, False)] * NREG):
        if kind == 'ptr':
            if rng.random() < 0.03:
                vals.append([0])
                continue
            a = ARGBUF + 0x2000 * (k % 8) + rng.choice([0, 0, 0, 1, 2, 3])
            x = rng.random()
            if x < 0.4:
                s = ''.join(rng.choice('ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789; ') for _ in range(rng.randrange(0, 40)))
                data = s.encode() + b'\0' + bytes(rng.getrandbits(8) for _ in range(64))
            elif x < 0.6:
                data = b''.join(struct.pack('<I', draw_float(rng)) for _ in range(256))
            else:
                data = bytes(rng.getrandbits(8) for _ in range(0x800))
            loads.append((a, data))
            vals.append([a])
        elif size == 8:
            v = rng.getrandbits(rng.choice([8, 16, 31, 32, 33, 48, 63, 64]))
            vals.append([v & 0xFFFFFFFF, v >> 32])
        elif kind == 'float':
            vals.append([draw_float(rng)])
        else:
            vals.append([draw_value(rng, size, signed)])
    return vals, loads


def gcc_regs(vals):
    """GCC's windowed ABI (soft float): every argument in a2..a7 in order, 8-byte ones in an even/odd pair."""
    regs = []
    for v in vals:
        if len(v) == 2 and len(regs) % 2:
            regs.append(0)
        regs += v
    return regs


def xcc_regs(vals, params):
    """XCC's convention on this core: integers and pointers as GCC's, floats in aed0.. (EquivHifi4Emu.java)."""
    regs, fregs = [], []
    for v, (kind, _, _) in zip(vals, params or [('int', 4, False)] * len(vals)):
        if kind == 'float':
            fregs += v
            continue
        if len(v) == 2 and len(regs) % 2:
            regs.append(0)
        regs += v
    return regs, fregs


def fill_globals(rng, addrs):
    words = sorted({a & ~3 for a in addrs})
    out = []
    for w in words:
        x = rng.random()
        if x < 0.4:
            v = rng.choice([0, 0, 1, 2, 3, 0xFF, 0xFFFF])
        elif x < 0.7:
            v = rng.getrandbits(32)
        else:
            v = FILLBUF + 4 * rng.randrange(0, 0x100)
        out.append((w, v.to_bytes(4, 'little')))
    out.append((FILLBUF, bytes(rng.getrandbits(8) for _ in range(0x800))))
    return out


# ---------------------------------------------------------------- presets (valid inputs where random ones miss)

def strn_args(rng, vals):
    """Two strings with a shared prefix (often all of it, NUL included) and n around their length, at any alignment."""
    s = bytes(rng.choice(b'ABCDEF;0123') for _ in range(rng.randrange(0, 24)))
    a = s + b'\0' + bytes(rng.getrandbits(8) for _ in range(16))
    b = bytearray(a)
    x = rng.random()
    if x < 0.4:
        b[len(s) + 1 + rng.randrange(0, 16)] ^= 1 + rng.randrange(255)
    elif x < 0.8 and s:
        b[rng.randrange(0, len(s))] = rng.choice(b'ABCDEFXYZ\0\xff\x80')
    pa, pb = ARGBUF + rng.randrange(4), ARGBUF + 0x2000 + rng.randrange(4)
    vals[0], vals[1] = [pa], [pb]
    if len(vals) > 2:
        vals[2] = [(rng.choice([0, 1, 2, 3, 4, 5, 8, len(s), len(s) + 1, len(s) + 2, len(s) + 9, rng.randrange(0, 40)])) & 0xFFFFFFFF]
    return [(pa, a), (pb, bytes(b))], None


def mem_args(rng, vals):
    """(dst, src|value, n): buffers at every alignment, n over the head/word/tail paths of the copy loops."""
    vals[0] = [(ARGBUF + rng.randrange(8)) & 0xFFFFFFFF]
    vals[1] = [((ARGBUF + 0x4000 + rng.randrange(8)) if rng.random() < 0.8 else rng.getrandbits(32)) & 0xFFFFFFFF]
    vals[2] = [(rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 17, 31, 32, 33, 63, 64, 100, rng.randrange(0, 600)])) & 0xFFFFFFFF]
    return [(ARGBUF + 0x4000, bytes(rng.getrandbits(8) for _ in range(0x800)))], None


def memmove_args(rng, vals):
    """memmove (dst, src, n): overlapping buffers both ways as well as apart."""
    base = ARGBUF + 0x100
    src = base + rng.randrange(0, 64)
    dst = src + rng.choice([-17, -8, -4, -3, -1, 0, 1, 3, 4, 8, 17, 0x400])
    vals[0], vals[1] = [dst], [src]
    vals[2] = [(rng.choice([0, 1, 3, 4, 7, 8, 15, 16, 33, rng.randrange(0, 300)])) & 0xFFFFFFFF]
    return [(ARGBUF, bytes(rng.getrandbits(8) for _ in range(0x800)))], None


def memchr_args(rng, vals):
    s = bytes(rng.getrandbits(8) for _ in range(rng.randrange(0, 80)))
    p = ARGBUF + rng.randrange(8)
    vals[0] = [(p) & 0xFFFFFFFF]
    vals[1] = [(rng.choice(list(s[:10]) + [0, 0x41, rng.getrandbits(32)]) if s else rng.getrandbits(8)) & 0xFFFFFFFF]
    vals[2] = [(rng.choice([0, 1, 3, 4, 7, 8, 9, len(s), rng.randrange(0, 90)])) & 0xFFFFFFFF]
    return [(p, s + bytes(64))], None


def strlen_args(rng, vals):
    p = ARGBUF + rng.randrange(8)
    s = bytes(rng.randrange(1, 256) for _ in range(rng.randrange(0, 70)))
    vals[0] = [(p) & 0xFFFFFFFF]
    return [(p, s + b'\0' + bytes(rng.getrandbits(8) for _ in range(8)))], None


CAPTURE_TABLE, CAPTURE_BLOCKS = 0x2390E0, (0x2007E000, 0x2007F000)    # src/ifdsp_hifi4/data_symbols.tsv


def capture_args(rng, vals):
    """regfile_capture_* (ch[, value]): channel 0..1 and the refused ones, the block table set up as
    regfile_capture_init leaves it, each block's control word with and without the enable and wrap bits and its count
    around the end (0x3FE, 0x3FF)."""
    vals[0] = [rng.choice([0, 1, 0, 1, 2, 0xFFFFFFFF])]
    loads = [(CAPTURE_TABLE, b''.join(a.to_bytes(4, 'little') for a in CAPTURE_BLOCKS))]
    for a in CAPTURE_BLOCKS:
        ctrl = rng.choice([0, 1, 2, 3, rng.getrandbits(16)])
        count = rng.choice([0, 1, 5, 0x3FD, 0x3FE, 0x3FF, 0x400, rng.getrandbits(16)])
        loads.append((a, ctrl.to_bytes(2, 'little') + count.to_bytes(2, 'little')))
    return loads, None


def gpio_sel_args(rng, vals):
    """regfile_gpio_sel (): reg 0xC with its top nibble 1 (P0_5) or not."""
    v = (rng.choice([0, 1, 1, 2, 0xF]) << 12) | rng.getrandbits(12)
    return [(0x20070018, v.to_bytes(2, 'little'))], None


def interleave_args(rng, vals):
    """(de)interleave2_u32 (a, b, c, n): the callers' block of 24 frames and others up to 512, in separate buffers
    (a random n up to 0xFFFF writes over the code)."""
    vals[3] = [rng.choice([0, 1, 2, 3, 24, 24, 48, rng.randrange(0, 512)])]
    for k in range(3):
        if vals[k] == [0]:
            vals[k] = [ARGBUF + 0x2000 * k]
    return [], None


PRESETS = {'deinterleave2_u32': interleave_args, 'interleave2_u32': interleave_args,
           'strcmp': strn_args, 'strncmp': strn_args, 'env_strcmp': strn_args, 'env_strncmp': strn_args,
           'strncpy': strn_args, 'env_strncpy': strn_args, 'strcpy': strn_args,
           'memcpy': mem_args, 'memset': mem_args, 'env_memset': mem_args, 'env_memcpy': mem_args,
           'memmove': memmove_args, 'memchr': memchr_args, 'strlen': strlen_args,
           'regfile_capture_append': capture_args, 'regfile_capture_clear': capture_args,
           'regfile_capture_set_ctrl': capture_args, 'regfile_gpio_sel': gpio_sel_args}


def run(eng, bases, entry, regs, loads, seed, budget, stubs, cover, mmio_fixed=None, trace=False, fregs=()):
    q = {'op': 'run', 'bases': bases, 'entry': entry, 'sp': STACK, 'seed': seed, 'budget': budget,
         'args': regs[:NREG], 'stack': list(regs[NREG:]), 'fargs': list(fregs),
         'loads': [[a, d.hex()] for a, d in loads], 'snap': SNAP, 'track': TRACK,
         'stubs': {str(a): [n, str(STUBS[n])] for a, n in stubs.items()}, 'cover': sorted(cover)}
    if trace:
        q['trace'] = True
    if mmio_fixed:
        q['mmio_fixed'] = {str(a): v for a, v in mmio_fixed.items()}
    return eng.send(q)


def aed0(r):
    return int.from_bytes(bytes.fromhex(r['ae']['aed0'])[:4], 'little')


def compare(a, b, ret, ae):
    if a['end'] != b['end']:
        return 'end'
    if a['end'] == 'fault' and a['why'] != b['why']:
        return 'fault'
    if a['end'] == 'return':
        if ret:
            size, kind = ret
            if size == 8:
                if a['ret'] != b['ret']:
                    return 'a2:a3'
            elif kind == 'float':
                x, y = aed0(a), b['ret'][0]
                if x != y and not (math.isnan(u2f(x)) and math.isnan(u2f(y))):
                    return 'a2 (float)'
            elif (a['ret'][0] ^ b['ret'][0]) & ((1 << (8 * size)) - 1):
                return 'a2'
        if a['wb'] != 0 or b['wb'] != 0 or a['sp'] != b['sp']:
            return 'window/SP'
        if ae and a['ae'] != b['ae']:
            return 'AE/FP state'
    for k in ('mmio', 'calls', 'diff'):
        if a[k] != b[k]:
            return {'mmio': 'peripheral accesses', 'calls': 'stub calls', 'diff': 'RAM'}[k]
    return None


def initial_bytes(img, loads):
    """address -> the byte at the start of a run (the trial's loads over the image, else 0)."""
    def get(a):
        for la, d in reversed(loads):
            if la <= a < la + len(d):
                return d[a - la]
        for sa, d in img.segs:
            if sa <= a < sa + len(d):
                return d[a - sa]
        return 0
    return get


def normalize_pointers(r, funcmap, initial):
    """The RAM a run leaves, as {address: byte}, with every stored address of a recreated function (scratch code)
    replaced by its original's address; a byte that ends equal to its start value is left out."""
    mem = {}
    for a, h in r['diff']:
        for i, b in enumerate(bytes.fromhex(h)):
            mem[a + i] = b
    for a in sorted({m - k for m in mem for k in range(4)}):
        v = int.from_bytes(bytes(mem.get(a + i, initial(a + i)) for i in range(4)), 'little')
        if v in funcmap:
            for i, b in enumerate(funcmap[v].to_bytes(4, 'little')):
                mem[a + i] = b
    return {a: b for a, b in mem.items() if b != initial(a)}


def first_diff(a, b, k):
    for i, (x, y) in enumerate(zip(a[k], b[k])):
        if x != y:
            return f' (#{i}: {x} vs {y})'
    return f' (lengths {len(a[k])} vs {len(b[k])})'


class Checker:
    def __init__(self):
        self.img = Image()
        self.orig = Originals()
        self.eng = None
        self.work = tempfile.mkdtemp(prefix='equiv_hifi4_')
        self.meta = {}

    def engine(self):
        if self.eng is None:
            self.eng = Engine(self.img)
        return self.eng

    def blocks(self, a):
        if a not in self.meta:
            self.meta[a] = self.engine().send({'op': 'blocks', 'entries': [a]})['blocks'][str(a)]
        return self.meta[a]

    def prepare(self, fname):
        oaddr = self.orig.addr(fname)
        if oaddr is None:
            return None, None, f'no original address for {fname} (decomp/ifdsp/hifi4/functions.tsv or aliases.tsv)'
        path, err = link(self.orig, fname, self.work)
        if err:
            return oaddr, None, f'link: {err}'
        lk = Linked(path, fname, self.orig)
        if lk.rw:
            return oaddr, None, f'the recreated code defines variables without an image address: {", ".join(lk.rw)}'
        return oaddr, lk, None

    def stubs_for(self, fname):
        return {self.orig.addr(n): n for n in STUBS if self.orig.addr(n) is not None and n != fname}

    def check(self, fname, seed=1, trials=200):
        oaddr, lk, err = self.prepare(fname)
        if err:
            return oaddr, 'not yet', err
        eng = self.engine()
        eng.send({'op': 'base', 'name': 'new', 'segs': [[a, d.hex()] for a, d in lk.segs]})
        meta = self.blocks(oaddr)
        lead = set(meta['blocks'])
        stubs = self.stubs_for(fname)
        rng = random.Random(seed)
        seen_reads = set()
        reached, ok, inconclusive, userops, bothfault = set(), 0, 0, set(), 0
        for t in range(trials):
            vals, loads = draw_args(rng, lk.params)
            fill = fill_globals(rng, seen_reads)
            mfix = None
            pre = PRESETS.get(fname)
            if pre:
                extra, mfix = pre(rng, vals)
                loads = loads + extra
            loads = fill + loads
            regs = gcc_regs(vals)
            oregs, ofregs = xcc_regs(vals, lk.params)
            s = rng.getrandbits(31)
            for budget in (BUDGET, 8 * BUDGET):
                r1 = run(eng, ['image'], oaddr, oregs, loads, s, budget, stubs, lead, mfix, fregs=ofregs)
                r2 = run(eng, ['image', 'new'], lk.entry, regs, loads, s, budget, stubs, (), mfix)
                if 'budget' not in (r1['end'], r2['end']) or r1['end'] == r2['end']:
                    break
            seen_reads |= set(r1['reads']) | set(r2['reads'])
            reached |= set(r1['hits'])
            userops |= set(r1['userops']) | set(r2['userops'])
            if r1['end'] == r2['end'] == 'budget':
                inconclusive += 1
                continue
            if r1['end'] == 'fault' and r1['why'].startswith('unimplemented pcodeop') and r2['end'] != 'fault':
                return oaddr, 'not yet', (f'emulation trial {t}: the original uses an operation the harness does not '
                                          f'model ({r1["why"]})')
            if r1['end'] == r2['end'] == 'fault':
                # both fault: a random pointer into unmapped memory or the code, which the two builds dereference in
                # another order (and with other peripheral reads before); not compared, counted
                bothfault += 1
                continue
            if r1['diff'] != r2['diff'] and lk.funcmap:
                ini = initial_bytes(self.img, loads)
                m1 = normalize_pointers(r1, {}, ini)
                m2 = normalize_pointers(r2, lk.funcmap, ini)
                if m1 == m2:
                    r2 = dict(r2, diff=r1['diff'])
            d = compare(r1, r2, lk.ret, fname in AE_STATE)
            if d:
                key = {'peripheral accesses': 'mmio', 'RAM': 'diff', 'stub calls': 'calls'}.get(d)
                if key == 'diff':
                    ini = initial_bytes(self.img, loads)
                    m1 = normalize_pointers(r1, {}, ini)
                    m2 = normalize_pointers(r2, lk.funcmap, ini)
                    bad = sorted(a for a in set(m1) | set(m2) if m1.get(a) != m2.get(a))
                    extra = ' (' + ', '.join(f'{a:#x}: {m1.get(a, ini(a)):02x} vs {m2.get(a, ini(a)):02x}'
                                             for a in bad[:12]) + f'; {len(bad)} bytes)'
                elif key:
                    extra = first_diff(r1, r2, key)
                elif d == 'fault':
                    extra = f' ({r1["why"]} vs {r2["why"]})'
                elif d.startswith('a2'):
                    extra = f' (orig {[hex(x) for x in r1["ret"]]} aed0 {hex(aed0(r1))}, new {[hex(x) for x in r2["ret"]]})'
                else:
                    extra = f' (orig {r1["why"]} wb {r1["wb"]}, new {r2["why"]} wb {r2["wb"]})'
                return oaddr, 'differs', (f'emulation trial {t}: {d} differs{extra} '
                                          f'(args {[hex(x) for x in regs]}; orig ended {r1["end"]}, new {r2["end"]})')[:600]
            ok += r1['end'] == 'return'
        if not meta['found']:
            cov, covtxt = 1.0, 'no Ghidra function at the address: coverage not measured'
        else:
            cov = len(reached & lead) / max(1, len(lead))
            covtxt = f'{cov:.0%} of {len(lead)} blocks reached'
        covtxt += (f', {inconclusive} trials inconclusive' if inconclusive else '') + \
            (f', {bothfault} trials where both fault' if bothfault else '')
        uo = f'; modelled pcodeops used: {", ".join(sorted(userops))}' if userops else ''
        if ok < MIN_RETURNS * trials:
            return oaddr, 'not yet', (f'emulation: {ok} of {trials} trials returned normally, fewer than '
                                      f'{MIN_RETURNS:.0%} ({covtxt}){uo}')
        if cov < MIN_COVER:
            return oaddr, 'not yet', f'emulation: {trials} trials agree but reach only {covtxt} of the original{uo}'
        return oaddr, 'equivalent', (f'differential emulation (Ghidra p-code, rt600hifi4): {trials} trials agree '
                                     f'({ok} returned normally, {covtxt}){uo}')

    def trace(self, fname, seed, orig_side):
        oaddr, lk, err = self.prepare(fname)
        if err:
            sys.exit(err)
        eng = self.engine()
        eng.send({'op': 'base', 'name': 'new', 'segs': [[a, d.hex()] for a, d in lk.segs]})
        rng = random.Random(seed)
        vals, loads = draw_args(rng, lk.params)
        pre = PRESETS.get(fname)
        if pre:
            extra, _ = pre(rng, vals)
            loads = loads + extra
        regs = gcc_regs(vals)
        oregs, ofregs = xcc_regs(vals, lk.params)
        if orig_side:
            regs = oregs
        r = run(eng, ['image'] + ([] if orig_side else ['new']), oaddr if orig_side else lk.entry, regs, loads,
                rng.getrandbits(31), BUDGET, self.stubs_for(fname), (), trace=True, fregs=ofregs if orig_side else ())
        for st in r.get('trace', []):
            print(f'{st[0]:08x}  ' + ' '.join(f'{x:08x}' for x in st[1:]))
        print(json.dumps({k: v for k, v in r.items() if k not in ('trace', 'diff', 'reads', 'hits')})[:3000])
        print('args', [hex(x) for x in regs], 'diff', r['diff'][:8])

    def close(self):
        if self.eng:
            self.eng.close()
            self.eng = None
        shutil.rmtree(self.work, ignore_errors=True)


_CHK = None


def _init_worker():
    global _CHK
    _CHK = Checker()
    import atexit
    import multiprocessing.util
    atexit.register(_CHK.close)
    multiprocessing.util.Finalize(_CHK, _CHK.close, exitpriority=10)


def _check_one(job):
    path, fname, seed, trials = job
    try:
        a, v, d = _CHK.check(fname, seed, trials)
    except Exception as e:
        a, v, d = _CHK.orig.addr(fname), 'not yet', f'harness error: {e}'
        if _CHK.eng is not None and _CHK.eng.p.poll() is not None:
            _CHK.eng = None
    return path, fname, a, v, d


def require_objects():
    if not objects():
        sys.exit('equiv_hifi4_emu: no objects in src/ifdsp_hifi4/out/obj; build them first (make -C src/ifdsp_hifi4); '
                 'status.tsv not written')


def run_jobs(jobs, n):
    import multiprocessing
    if n <= 1:
        _init_worker()
        for j in jobs:
            yield _check_one(j)
        _CHK.close()
        return
    pool = multiprocessing.Pool(n, initializer=_init_worker)
    try:
        for r in pool.imap_unordered(_check_one, jobs):
            yield r
        pool.close()
    except BaseException:
        pool.terminate()
        raise
    pool.join()


def cmd_check(args):
    require_objects()
    want = set(args.functions)
    jobs = [(p, f, args.seed, args.trials) for p, f in recreated()
            if f in want or any(p.endswith(o) for o in args.object or ())]
    for m in sorted(want - {f for _, f, _, _ in jobs}):
        print(f'equiv_hifi4_emu: {m}: not defined in src/ifdsp_hifi4/out/obj', file=sys.stderr)
    for path, fname, a, v, d in run_jobs(jobs, args.jobs or 1):
        print(f'equiv_hifi4_emu: {fname:32s} {v}: {d}', file=sys.stderr)


RANK = {'identical': -1, 'equivalent': 0, 'differs': 1, 'not yet': 2}


def cmd_status(args):
    require_objects()
    orig = Originals()
    jobs = [(p, f, args.seed, args.trials) for p, f in recreated()]
    results = {}
    for path, fname, a, v, d in sorted(run_jobs(jobs, args.jobs or 1), key=lambda x: (x[0], x[1])):
        print(f'equiv_hifi4_emu: {fname:32s} {v}: {d}', file=sys.stderr)
        rel = os.path.relpath(path, os.path.join(SRC, 'out', 'obj'))
        key = a if a is not None else ('-', fname)
        cur = results.get(key)
        if cur is None or RANK[v] < RANK[cur[2]]:
            results[key] = (fname, rel, v, d)
    rows = []
    by_addr = {a: (n, s) for n, (a, s) in orig.funcs.items()}
    for a, (g, n) in sorted(by_addr.items()):
        if a in results:
            fname, rel, v, d = results[a]
            cov = n if v == 'identical' else (orig.extent(a) if v == 'equivalent' else 0)
            rows.append((a, g, n, fname, rel, v, cov, d[:300]))
        else:
            rows.append((a, g, n, '', '', 'not yet', 0, ''))
    for k, (fname, rel, v, d) in results.items():
        if isinstance(k, tuple):
            rows.append((0, '-', 0, fname, rel, v, 0, d[:300]))
        elif k not in by_addr:
            rows.append((k, '-', 0, fname, rel, v, 0, d[:300]))
    with open(STATUS_TSV, 'w', encoding='utf-8') as f:
        f.write('# IFDSP HiFi4: recreated source vs the original image, per function (T24). Generated by\n')
        f.write('# tools/equiv_hifi4_emu.py status; do not edit. The image was built with Cadence XCC (proprietary), so\n')
        f.write('# nothing is byte-identical; equivalent = passes the differential emulation (Ghidra p-code, rt600hifi4).\n')
        f.write("# covered = bytes counted as re-implemented (the function's bytes up to the next original function);\n")
        f.write('# tools/readability_stats.py sums it. Rows with ghidra_name "-" have no original function in\n')
        f.write('# decomp/ifdsp/hifi4/functions.tsv.\n')
        f.write('address\tghidra_name\tsize\tsource\tfile\tverdict\tcovered\tdetail\n')
        for a, g, n, src, fl, v, cov, det in sorted(rows):
            f.write(f'{a:08x}\t{g}\t{n}\t{src}\t{fl}\t{v}\t{cov}\t{det}\n')
    listed = [r for r in rows if r[1] != '-']
    tot = sum(r[2] for r in listed)
    cov = sum(r[6] for r in listed)
    cnt = {}
    for r in listed:
        cnt[r[5]] = cnt.get(r[5], 0) + 1
    print('equiv_hifi4_emu: ' + ', '.join(f'{k} {v}' for k, v in sorted(cnt.items(), key=lambda kv: RANK[kv[0]])) +
          f' (of {len(listed)} Ghidra functions); re-implemented {cov} of {tot} bytes ({100.0 * cov / tot:.2f} %); '
          f'wrote {os.path.relpath(STATUS_TSV, ROOT)}')


def cmd_trace(args):
    require_objects()
    c = Checker()
    try:
        c.trace(args.function, args.seed, args.orig)
    finally:
        c.close()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    c = sub.add_parser('check')
    c.add_argument('functions', nargs='*')
    c.add_argument('--object', action='append', help='every function of this object (e.g. libc/strlen.o)')
    st = sub.add_parser('status')
    for p in (c, st):
        p.add_argument('--trials', type=int, default=200)
        p.add_argument('--seed', type=int, default=1)
        p.add_argument('--jobs', type=int, default=0, help='Ghidra workers (default 1)')
    tr = sub.add_parser('trace')
    tr.add_argument('function')
    tr.add_argument('--seed', type=int, default=1)
    tr.add_argument('--orig', action='store_true', help='trace the original instead of the recreated function')
    args = ap.parse_args()
    {'check': cmd_check, 'status': cmd_status, 'trace': cmd_trace}[args.cmd](args)


if __name__ == '__main__':
    main()
