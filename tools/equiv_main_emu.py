#!/usr/bin/env python3
"""T24 (MAIN): differential emulation of recreated MAIN functions (RX651) in Ghidra's p-code emulator.

The MAIN image was built with Renesas CC-RX, which is not available here (docs/tasks/T24-source-recreation.md,
"MAIN"), so the recreated C (src/main/, GCC 13.3.0 for RX) cannot be byte-identical except for trivial functions; it
is checked like the DISPLAY and M33 code: the original function and the recompiled one run from the same start
state on the same inputs, and their results and side effects are compared. Unicorn has no RX, so the runs happen in
Ghidra's p-code emulator on the rx62t SLEIGH module (the language the MAIN project uses), driven by the server
script tools/ghidra/EquivMainEmu.java: one headless Ghidra process per worker answers JSON requests on stdin.

Linking: each recreated function is linked on its own with rx-elf-ld at the scratch address 0xFFF00000 (inside the
+-8 MB reach of BSR.A/BRA.A from the image at 0xFFF80000). The linker script defines every other function name of
decomp/main/functions.tsv (and src/main/aliases.tsv) at its original address and every RAM variable of
src/main/data_symbols.tsv at its address, so the recreated function calls the image's own callees and uses the
image's own variables; --gc-sections keeps only the function, the static helpers and constants it needs, and libgcc.
Recreated .data/.bss must be empty (the variables are the image's). A function whose bytes, linked at its original
address, are the image's own is "identical".

Start state (both runs): the image at 0xFFF80000; RAM as after _INITSCT (the three DTBL copies of 0xFFF8E6A0, the
rest zero); SP = 0xF00 in the user stack with [SP] = a stop address (the return address of the call); PSW = 0x30000.
Inputs per trial: R1..R4 and stack arguments drawn by the recreated function's DWARF parameter types (CC-RX callers
extend char and short arguments: eeprom_read 0xFFFB14BA); pointers point to random buffers or strings at 0x30000..;
the RAM bytes the functions read before writing them (collected over the earlier trials of the same function) are
filled with random words, small values or pointers into a RAM buffer at 0x38000; PRESETS build valid state where a
function needs one. Peripheral reads (0x80000..0xFFFFF, 0x7FC000..) return values from a seeded sequence and every
peripheral access is recorded; any access outside RAM, I/O and ROM ends the run as a fault. Interrupt handlers
(the original ends in RTE) get the PSW on the stack and must restore R1..R15.

Equivalent when every trial agrees on: the way it ended (return, fault and its address, budget), R1 (R1:R2 for an
8-byte result, nothing for void; masked to the DWARF return size), R6..R13 (R1..R15 for an interrupt handler), the
PSW I bit and IPL, RAM 0x1404..0x3FFFF after the run, the sequence of peripheral accesses, and the stubbed calls;
at least one trial returned normally; and the trials together reached at least half of the original's basic blocks
(Ghidra's SimpleBlockModel). A trial where only one run exhausts the budget is re-run with 8 times the budget; one
where both do is inconclusive (not compared, and reported).

Usage:
  python3 -I tools/equiv_main_emu.py check FUNCTION... [--trials N] [--seed S]
  python3 -I tools/equiv_main_emu.py status [--trials N] [--jobs J]   every recreated function -> src/main/status.tsv
Environment: FT710_MAIN_PROJECT (Ghidra project directory holding FT710_MAIN; default /home/user/ghidra_tasks/
t24main/proj, a copy of ghidra/; every worker copies it again to a temporary directory, since Ghidra locks an open
project, and opens that read-only), GHIDRA_JAVA_HOME, RX_BINUTILS (prefix, default
~/opt/rx-binutils-2.42/bin/rx-elf-), RX_GCC (prefix, default ~/opt/rx-gcc-13.3.0/bin/rx-elf-), FT710_BUILD.
The image is read from build/FT-710_MAIN_V0112.bin; it is never written anywhere.
"""
import argparse
import glob
import json
import os
import random
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'src/main')
FUNCS_TSV = os.path.join(ROOT, 'decomp/main/functions.tsv')
DATA_TSV = os.path.join(SRC, 'data_symbols.tsv')
ALIAS_TSV = os.path.join(SRC, 'aliases.tsv')
STATUS_TSV = os.path.join(SRC, 'status.tsv')
HOME = os.path.expanduser('~')

ROM = 0xFFF80000
DTBL = 0xFFF8E6A0                  # 3 x {src, end, dst} (docs/memory-maps.md, MAIN)
SCRATCH = 0xFFF00000               # recreated code
STACK = 0xF00                      # SP at entry (user stack, USP top 0x1004)
ARGBUF = 0x30000                   # argument buffers, 0x800 apart (unused RAM 0x25E60..0x3FFFF)
FILLBUF = 0x38000                  # target of pointer-valued globals
SNAP = [(0x1404, 0x40000)]         # compared RAM: everything above the two stacks
TRACK = [(0x1404, 0x26000)]        # .data/.bss: bytes read before written are filled with random values
BUDGET = 300000
MIN_COVER = 0.5
NREG = 4

# Functions called with a stub instead of the image's code: name -> number of arguments to record
STUBS = {}


def read_tsv(path):
    rows = []
    with open(path, encoding='utf-8') as f:
        for ln in f:
            if ln.startswith('#') or not ln.strip():
                continue
            rows.append(ln.rstrip('\n').split('\t'))
    return rows


def image_path():
    p = os.path.join(os.environ.get('FT710_BUILD', os.path.join(ROOT, 'build')), 'FT-710_MAIN_V0112.bin')
    if not os.path.exists(p):
        sys.exit(f'equiv_main_emu: {p} not found (decode the firmware, or set FT710_BUILD)')
    return p


class Image:
    def __init__(self):
        with open(image_path(), 'rb') as f:
            self.rom = f.read()
        self.ram = bytearray(0x40000)
        for k in range(3):
            src, end, dst = (self.u32(DTBL + 12 * k + 4 * i) for i in range(3))
            self.ram[dst:dst + end - src] = self.read(src, end - src)

    def read(self, a, n):
        return self.rom[a - ROM:a - ROM + n]

    def u32(self, a):
        return int.from_bytes(self.read(a, 4), 'little')


class Originals:
    """Original functions (decomp/main/functions.tsv, src/main/aliases.tsv) and data (src/main/data_symbols.tsv)."""

    def __init__(self):
        rows = read_tsv(FUNCS_TSV)[1:]
        self.funcs = {r[1]: (int(r[0], 16), int(r[2])) for r in rows}
        self.entries = sorted(a for a, _ in self.funcs.values())
        self.alias = {}
        if os.path.exists(ALIAS_TSV):
            for r in read_tsv(ALIAS_TSV)[1:]:
                self.alias[r[0]] = int(r[1], 16)
        self.data = {r[0]: int(r[1], 16) for r in read_tsv(DATA_TSV)[1:]}

    def addr(self, name):
        if name in self.alias:
            return self.alias[name]
        f = self.funcs.get(name)
        return f[0] if f else None

    def extent(self, a):
        """Bytes from a to the next original function (the metric's rule for an equivalent function)."""
        import bisect
        i = bisect.bisect_right(self.entries, a)
        return (self.entries[i] - a) if i < len(self.entries) else 0x100


FORM_NUM = re.compile(r'#?-?(0x[0-9a-f]+|\d+)')


def forms(dis):
    """Instruction forms of an objdump listing: the mnemonic and the operand shape, with registers, numbers and
    addresses abstracted (r, n). T22a checked the module's semantics on the forms the MAIN image uses; a form only
    the GCC code uses was not checked (JMP Rs was wrong; EquivMainEmu.java executes it itself)."""
    out = set()
    for ln in dis.splitlines():
        p = ln.split('\t')
        if len(p) < 3 or not p[2].strip():
            continue
        mn, _, ops = ' '.join(x.strip() for x in p[2:]).split(';')[0].strip().partition(' ')
        ops = re.sub(r'\br([0-9]|1[0-5])\b', 'r', ops.split('<')[0].strip())
        ops = re.sub(r'^[0-9a-f]{5,8}$', 'n', ops)          # branch target (the image listing prints it with 0x)
        out.add((mn + ' ' + FORM_NUM.sub('n', ops)).strip())
    return out


_MAIN_FORMS = None


def main_forms(img):
    global _MAIN_FORMS
    if _MAIN_FORMS is None:
        od = tool('RX_BINUTILS', os.path.join(HOME, 'opt/rx-binutils-2.42/bin/rx-elf-'), 'objdump')
        with tempfile.NamedTemporaryFile(suffix='.bin') as f:
            f.write(img.rom)
            f.flush()
            dis = subprocess.run([od, '-D', '-b', 'binary', '-m', 'rx', f'--adjust-vma=0x{ROM:08X}',
                                  '--start-address=0xFFF8FBDB', '--stop-address=0xFFFEE2B8', f.name],
                                 capture_output=True, text=True).stdout
        _MAIN_FORMS = forms(dis)
    return _MAIN_FORMS


def new_forms(path):
    od = tool('RX_BINUTILS', os.path.join(HOME, 'opt/rx-binutils-2.42/bin/rx-elf-'), 'objdump')
    return forms(subprocess.run([od, '-d', path], capture_output=True, text=True).stdout)


def tool(prefix_env, default, name):
    return os.environ.get(prefix_env, default) + name


def libgcc():
    gcc = tool('RX_GCC', os.path.join(HOME, 'opt/rx-gcc-13.3.0/bin/rx-elf-'), 'gcc')
    return subprocess.run([gcc, '-print-libgcc-file-name'], capture_output=True, text=True, check=True).stdout.strip()


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
                        isinstance(s['st_shndx'], int) and s.name.startswith('_'):
                    out.append((p, s.name[1:]))
    return out


def link(orig, fname, at=None, workdir=None):
    """Link fname alone (with every object for its static helpers): at the scratch address, or with its own section
    at address `at` (the identical-bytes test). Returns (elf path, error)."""
    names = {}
    for n, (a, _) in orig.funcs.items():
        names[n] = a
    names.update(orig.alias)
    names.update(orig.data)
    lines = [f'ENTRY(_{fname})', 'SECTIONS {']
    if at is not None:
        lines.append(f'  .ftext 0x{at:08X} : {{ *(.text.{fname}) }}')
    lines += [f'  .text 0x{SCRATCH:08X} : {{ *(.text .text.*) }}', '  .rodata : { *(.rodata .rodata.*) }',
              '  .data : { *(.data .data.*) }', '  .bss : { *(.bss .bss.* COMMON) }',
              '  /DISCARD/ : { *(.comment) }', '}']
    for n, a in sorted(names.items()):
        if n == fname or not all(c.isalnum() or c in '_$.' for c in n):
            continue
        lines.append(f'"_{n}" = 0x{a:08X};')
    script = os.path.join(workdir, f'{fname}.{"at" if at is not None else "s"}.ld')
    out = os.path.join(workdir, f'{fname}.{"at" if at is not None else "s"}.elf')
    with open(script, 'w') as f:
        f.write('\n'.join(lines) + '\n')
    ld = tool('RX_BINUTILS', os.path.join(HOME, 'opt/rx-binutils-2.42/bin/rx-elf-'), 'ld')
    r = subprocess.run([ld, '-T', script, '--gc-sections', '-o', out] + objects() + [libgcc()],
                       capture_output=True, text=True)
    if r.returncode != 0:
        return None, r.stderr.strip().splitlines()[-1] if r.stderr.strip() else 'ld failed'
    return out, None


class Linked:
    """The loadable bytes, the entry and the DWARF signature of a linked function."""

    def __init__(self, path, fname):
        from elftools.elf.elffile import ELFFile
        with open(path, 'rb') as f:
            elf = ELFFile(f)
            self.segs = []
            self.rw = 0
            for s in elf.iter_sections():
                if s['sh_flags'] & 2 and s['sh_size']:          # SHF_ALLOC
                    if s.name.startswith('.data') or s.name.startswith('.bss'):
                        self.rw += s['sh_size']
                    elif s['sh_type'] == 'SHT_PROGBITS':
                        self.segs.append((s['sh_addr'], s.data()))
            sym = next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name == '_' + fname)
            self.entry, self.size = sym['st_value'], sym['st_size']
            self.ret, self.params = dwarf_signature(elf, fname)

    def code(self):
        for a, d in self.segs:
            if a <= self.entry < a + len(d):
                return d[self.entry - a:self.entry - a + self.size]
        return b''


def dwarf_signature(elf, fname):
    """(return (size, signed) or None for void, [(kind, size, signed)] per parameter) from DWARF; kind is 'ptr' or
    'int'."""
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
        return ('int', size, enc in (5, 6))            # DW_ATE_signed, DW_ATE_signed_char

    if not elf.has_dwarf_info():
        return (4, False), [('int', 4, False)] * NREG
    for cu in elf.get_dwarf_info().iter_CUs():
        for die in cu.iter_DIEs():
            if die.tag != 'DW_TAG_subprogram' or 'DW_AT_name' not in die.attributes:
                continue
            if die.attributes['DW_AT_name'].value.decode() != fname or 'DW_AT_declaration' in die.attributes:
                continue
            ret = None
            if 'DW_AT_type' in die.attributes:
                k, s, sg = desc(die.get_DIE_from_attribute('DW_AT_type'))
                ret = (s, sg)
            params = [desc(c.get_DIE_from_attribute('DW_AT_type')) for c in die.iter_children()
                      if c.tag == 'DW_TAG_formal_parameter' and 'DW_AT_type' in c.attributes]
            return ret, params
    return (4, False), [('int', 4, False)] * NREG


class Engine:
    """One headless Ghidra running tools/ghidra/EquivMainEmu.java."""

    def __init__(self, img):
        # each engine opens its own copy: Ghidra locks a project while it is open, also read-only
        src = os.environ.get('FT710_MAIN_PROJECT', '/home/user/ghidra_tasks/t24main/proj')
        import shutil
        self.tmp = tempfile.mkdtemp(prefix='equiv_main_proj_')
        proj = os.path.join(self.tmp, 'proj')
        os.mkdir(proj)
        shutil.copy(os.path.join(src, 'FT710_MAIN.gpr'), proj)
        shutil.copytree(os.path.join(src, 'FT710_MAIN.rep'), os.path.join(proj, 'FT710_MAIN.rep'),
                        ignore=shutil.ignore_patterns('*.lock*', '*~'))
        env = dict(os.environ)
        env.setdefault('GHIDRA_JAVA_HOME', '/usr/lib/jvm/java-21-openjdk-amd64')
        env.setdefault('MAXMEM', '1500M')
        self.log = tempfile.NamedTemporaryFile('w+', prefix='equiv_main_emu_', suffix='.log', delete=False)
        self.p = subprocess.Popen([os.path.join(ROOT, 'tools/ghidra-headless.sh'), proj, 'FT710_MAIN', '-process',
                                   'FT-710_MAIN_V0112.bin', '-noanalysis', '-readOnly',
                                   '-scriptPath', os.path.join(ROOT, 'tools/ghidra'), '-postScript', 'EquivMainEmu.java'],
                                  stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=self.log, text=True, env=env)
        self.recv()
        self.send({'op': 'base', 'name': 'image', 'segs': [[ROM, img.rom.hex()]]})
        self.send({'op': 'base', 'name': 'ram', 'segs': [[0, bytes(img.ram).hex()]]})

    def recv(self):
        for line in self.p.stdout:
            if line.startswith('@@EQ '):
                return json.loads(line[5:])
            self.log.write(line)
        raise RuntimeError(f'equiv_main_emu: Ghidra ended (log {self.log.name})')

    def send(self, q):
        self.p.stdin.write(json.dumps(q) + '\n')
        self.p.stdin.flush()
        r = self.recv()
        if 'error' in r:
            raise RuntimeError(f'equiv_main_emu: {r["error"]}')
        return r

    def close(self):
        try:
            self.p.stdin.write('{"op":"quit"}\n')
            self.p.stdin.flush()
            self.p.wait(timeout=60)
        except Exception:
            self.p.kill()
        self.log.close()
        if os.path.exists(self.log.name) and not os.environ.get('EQUIV_MAIN_KEEP_LOG'):
            os.unlink(self.log.name)
        import shutil
        shutil.rmtree(self.tmp, ignore_errors=True)


def draw_value(rng, size, signed):
    v = rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 0x0F, 0x10, 0x3F, 0x40, 0x41, 0x7F, 0x80, 0xFF, 0x100, 0x1FF, 0x7FFF,
                    0x8000, 0xFFFF]) if rng.random() < 0.5 else rng.getrandbits(8 * size)
    v &= (1 << (8 * size)) - 1
    if signed and v >> (8 * size - 1):
        v -= 1 << (8 * size)
    return v & 0xFFFFFFFF


def draw_args(rng, params):
    regs, loads = [], []
    for k, (kind, size, signed) in enumerate(params or [('int', 4, False)] * NREG):
        if kind == 'ptr':
            if rng.random() < 0.03:
                regs.append(0)
                continue
            a = ARGBUF + 0x800 * k
            x = rng.random()
            if x < 0.4:
                s = ''.join(rng.choice('ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789;') for _ in range(rng.randrange(0, 24)))
                data = s.encode() + b'\0' + bytes(rng.getrandbits(8) for _ in range(64))
            else:
                data = bytes(rng.getrandbits(8) for _ in range(0x400))
            loads.append((a, data))
            regs.append(a)
        elif size == 8:                       # a 64-bit argument takes a register pair, low word first
            v = draw_u64(rng)
            regs += [v & 0xFFFFFFFF, v >> 32]
        else:
            regs.append(draw_value(rng, size, signed))
    return regs, loads


def draw_u64(rng):
    bits = rng.choice([8, 16, 17, 31, 32, 33, 48, 63, 64])
    return rng.getrandbits(bits) if rng.random() < 0.8 else rng.choice([0, 1, (1 << 32) - 1, 1 << 32, (1 << 64) - 1])


def fill_globals(rng, addrs):
    """Random contents for the RAM words that hold the bytes in addrs."""
    words = sorted({a & ~3 for a in addrs})
    out = []
    for w in words:
        x = rng.random()
        if x < 0.4:
            v = rng.choice([0, 0, 1, 2, 3, 0xFF, 0xFFFF])
        elif x < 0.7:
            v = rng.getrandbits(32)
        else:
            v = FILLBUF + rng.randrange(0, 0x400)
        out.append((w, v.to_bytes(4, 'little')))
    out.append((FILLBUF, bytes(rng.getrandbits(8) for _ in range(0x800))))
    return out


def udiv64_args(rng, regs):
    """A non-zero divisor (DIVU by zero is undefined on the RX), and each of the image's paths: divisor below 2^16,
    below 2^32, above."""
    d = 0
    while d == 0:
        d = rng.getrandbits(rng.choice([4, 16, 24, 32, 40, 64]))
    regs[2:4] = [d & 0xFFFFFFFF, d >> 32]
    return [], None


def eeprom_args(rng, regs):
    """eeprom_read/eeprom_write (addr, buf, n): n up to a few pages, so that a trial ends within the budget."""
    regs[2] = rng.choice([0, 1, 2, 63, 64, 65, rng.randrange(0, 200)])
    return [], None


def strncmp_args(rng, regs):
    """Two strings that share a prefix (often all of it, NUL included, with different bytes after the NUL), and n
    around their length: random buffers almost never compare equal, so the end tests would go unexercised."""
    s = bytes(rng.choice(b'ABCDEF;0123') for _ in range(rng.randrange(0, 12)))
    a = s + b'\0' + bytes(rng.getrandbits(8) for _ in range(8))
    b = bytearray(a)
    x = rng.random()
    if x < 0.4:
        b[len(s) + 1 + rng.randrange(0, 8)] ^= 1 + rng.randrange(255)     # differs only after the shared NUL
    elif x < 0.8 and s:
        b[rng.randrange(0, len(s))] = rng.choice(b'ABCDEFXYZ\0\xff')
    regs[0], regs[1] = ARGBUF, ARGBUF + 0x800
    regs[2] = rng.choice([0, 1, len(s), len(s) + 1, len(s) + 2, len(s) + 9, rng.randrange(0, 24)])
    return [(ARGBUF, a), (ARGBUF + 0x800, bytes(b))], None


HEAP_BREAK, HEAP_END = 0x25D34, 0x207F4     # sbrk's pointer and its limit (docs/code/main/bsp.md)


def sbrk_args(rng, regs):
    """The heap pointer anywhere in its area and sizes that end just below, at and just above the limit."""
    brk = rng.randrange(0x203F4, HEAP_END + 1)
    left = HEAP_END - brk
    regs[0] = max(0, left + rng.choice([-2, -1, 0, 0, 1, 2, rng.randrange(-left, 0x40) if left else 3])) & 0xFFFFFFFF
    return [(HEAP_BREAK, brk.to_bytes(4, 'little'))], None


def sci5_hook_args(rng, regs):
    """sci5_rx_byte_hook: the first byte of a frame (count 0, sometimes not) is one of the replies it knows."""
    buf = ARGBUF + 0x3000
    first = rng.choice([0x06, ord('?'), ord('r'), 0x00, rng.getrandbits(8)])
    cnt = 0 if rng.random() < 0.8 else rng.randrange(1, 8)
    return [(buf, bytes([first]) + bytes(rng.getrandbits(8) for _ in range(15))),
            (0x20820, buf.to_bytes(4, 'little')), (0x1B624, cnt.to_bytes(2, 'little'))], None


def adc_channel_args(rng, regs):
    """R_S12ADn_Get_ValueResult (channel, buffer): channel numbers around the 27 the drivers know."""
    regs[0] = rng.randrange(0, 32)
    return [], None


PRESETS = {'R_S12AD0_Get_ValueResult': adc_channel_args, 'R_S12AD1_Get_ValueResult': adc_channel_args,
           '__udiv64': udiv64_args, 'eeprom_read': eeprom_args, 'eeprom_write': eeprom_args,
           'strncmp': strncmp_args, 'sbrk': sbrk_args, 'heap_getmem': sbrk_args, 'sci5_rx_byte_hook': sci5_hook_args}


def run(eng, bases, entry, regs, loads, seed, budget, stubs, cover, isr, mmio_fixed=None, trace=False):
    q = {'op': 'run', 'bases': bases, 'entry': entry, 'sp': STACK, 'seed': seed, 'budget': budget,
         'regs': {f'R{k + 1}': v for k, v in enumerate(regs[:NREG])},
         'stack': ([0x00030000] if isr else []) + list(regs[NREG:]),
         'loads': [[a, d.hex()] for a, d in loads], 'snap': SNAP, 'track': TRACK,
         'stubs': {str(a): [n, STUBS[n]] for a, n in stubs.items()}, 'cover': sorted(cover)}
    if trace:
        q['trace'] = True
    if mmio_fixed:
        q['mmio_fixed'] = {str(a): v for a, v in mmio_fixed.items()}
    return eng.send(q)


def compare(a, b, ret, isr, init_regs):
    if a['end'] != b['end']:
        return 'end'
    if a['end'] == 'fault' and a['why'] != b['why']:
        return 'fault'
    if a['end'] == 'return' and ret:
        size = ret[0]
        if size == 8:
            if (a['r1'], a['r2']) != (b['r1'], b['r2']):
                return 'R1:R2'
        elif (a['r1'] ^ b['r1']) & ((1 << (8 * size)) - 1):
            return 'R1'
    if a['end'] == 'return':
        idx = range(15) if isr else range(5, 13)
        for i in idx:
            if a['regs'][i] != b['regs'][i]:
                return f'R{i + 1}'
        if (a['psw'] ^ b['psw']) & 0x0F010000:
            return 'PSW'
    for k in ('mmio', 'calls', 'diff'):
        if a[k] != b[k]:
            return {'mmio': 'peripheral accesses', 'calls': 'stub calls', 'diff': 'RAM'}[k]
    return None


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
        self.work = tempfile.mkdtemp(prefix='equiv_main_')
        self.meta = {}

    def engine(self):
        if self.eng is None:
            self.eng = Engine(self.img)
        return self.eng

    def blocks(self, addrs):
        need = [a for a in addrs if a not in self.meta]
        if need:
            r = self.engine().send({'op': 'blocks', 'entries': need})['blocks']
            for a in need:
                self.meta[a] = r[str(a)]
        return {a: self.meta[a] for a in addrs}

    def byte_check(self, fname, oaddr, osize):
        path, err = link(self.orig, fname, at=oaddr, workdir=self.work)
        if err:
            return None
        lk = Linked(path, fname)
        code = lk.code()
        if code and len(code) == osize and code == self.img.read(oaddr, osize):
            return f'byte-identical at the original address ({osize} bytes)'
        return None

    def check(self, fname, seed=1, trials=200):
        oaddr = self.orig.addr(fname)
        if oaddr is None:
            return None, 'not yet', f'no original address for {fname} (decomp/main/functions.tsv or aliases.tsv)'
        osize = self.orig.funcs.get(fname, (oaddr, 0))[1]
        same = self.byte_check(fname, oaddr, osize) if osize else None
        if same:
            return oaddr, 'identical', same
        path, err = link(self.orig, fname, workdir=self.work)
        if err:
            return oaddr, 'not yet', f'link: {err}'
        lk = Linked(path, fname)
        if lk.rw:
            return oaddr, 'not yet', f'the recreated code has {lk.rw} bytes of .data/.bss (must use the image\'s RAM)'
        unverified = sorted(new_forms(path) - main_forms(self.img) - {'jmp r'})
        note = f'; instruction forms the MAIN image does not use (semantics not checked by T22a): {", ".join(unverified)}' \
            if unverified else ''
        eng = self.engine()
        eng.send({'op': 'base', 'name': 'new', 'segs': [[a, d.hex()] for a, d in lk.segs]})
        meta = self.blocks([oaddr])[oaddr]
        lead, isr = set(meta['blocks']), meta['isr']
        stubs = {self.orig.addr(n): n for n in STUBS if self.orig.addr(n) and n != fname}
        rng = random.Random(seed)
        seen_reads = set()
        reached, ok, inconclusive = set(), 0, 0
        for t in range(trials):
            regs, loads = draw_args(rng, lk.params)
            fill = fill_globals(rng, seen_reads)
            pre = PRESETS.get(fname)
            mfix = None
            if pre:
                extra, mfix = pre(rng, regs)
                loads = loads + extra
            loads = fill + loads
            s = rng.getrandbits(31)
            for budget in (BUDGET, 8 * BUDGET):
                r1 = run(eng, ['image', 'ram'], oaddr, regs, loads, s, budget, stubs, lead, isr, mfix)
                r2 = run(eng, ['image', 'ram', 'new'], lk.entry, regs, loads, s, budget, stubs, (), isr, mfix)
                if 'budget' not in (r1['end'], r2['end']) or r1['end'] == r2['end']:
                    break
            seen_reads |= set(r1['reads']) | set(r2['reads'])
            reached |= set(r1['hits'])
            if r1['end'] == r2['end'] == 'budget':
                inconclusive += 1
                continue
            d = compare(r1, r2, lk.ret, isr, regs)
            if d:
                key = {'peripheral accesses': 'mmio', 'RAM': 'diff', 'stub calls': 'calls'}.get(d)
                if key:
                    extra = first_diff(r1, r2, key)
                elif d == 'fault':
                    extra = f' ({r1["why"]} vs {r2["why"]})'
                elif d.startswith('R') or d == 'PSW':
                    extra = f' (orig {[hex(x) for x in r1["regs"]]}, new {[hex(x) for x in r2["regs"]]})'
                else:
                    extra = ''
                return oaddr, 'differs', (f'emulation trial {t}: {d} differs{extra} '
                                          f'(orig ended {r1["end"]}, new {r2["end"]})')[:600]
            ok += r1['end'] == 'return'
        cov = len(reached & lead) / max(1, len(lead))
        covtxt = f'{cov:.0%} of {len(lead)} blocks reached' + (f', {inconclusive} trials inconclusive' if inconclusive else '')
        if ok == 0:
            return oaddr, 'not yet', f'emulation: no trial of {trials} returned normally ({covtxt})'
        if cov < MIN_COVER:
            return oaddr, 'not yet', f'emulation: {trials} trials agree but reach only {covtxt} of the original'
        return oaddr, 'equivalent', f'differential emulation (Ghidra p-code): {trials} trials agree ({ok} returned normally, {covtxt}){note}'

    def close(self):
        if self.eng:
            self.eng.close()
            self.eng = None
        import shutil
        shutil.rmtree(self.work, ignore_errors=True)


_CHK = None


def _init_worker():
    global _CHK
    _CHK = Checker()
    import atexit
    atexit.register(_CHK.close)


def _check_one(job):
    path, fname, seed, trials = job
    try:
        a, v, d = _CHK.check(fname, seed, trials)
    except Exception as e:      # an engine failure is a result, not a crash of the whole status run
        a, v, d = _CHK.orig.addr(fname), 'not yet', f'harness error: {e}'
        if _CHK.eng is not None and _CHK.eng.p.poll() is not None:
            _CHK.eng = None     # Ghidra died: the next function starts a new one
    return path, fname, a, v, d


def require_objects():
    if not objects():
        sys.exit('equiv_main_emu: no objects in src/main/out/obj; build them first (make -C src/main CROSS=...); '
                 'status.tsv not written')


def run_jobs(jobs, n):
    import multiprocessing
    if n <= 1:
        _init_worker()
        for j in jobs:
            yield _check_one(j)
        _CHK.close()
        return
    with multiprocessing.Pool(n, initializer=_init_worker) as pool:
        for r in pool.imap_unordered(_check_one, jobs):
            yield r


def cmd_check(args):
    require_objects()
    want = set(args.functions)
    jobs = [(p, f, args.seed, args.trials) for p, f in recreated() if f in want or any(p.endswith(o) for o in args.object or ())]
    missing = want - {f for _, f, _, _ in jobs}
    for m in sorted(missing):
        print(f'equiv_main_emu: {m}: not defined in src/main/out/obj', file=sys.stderr)
    for path, fname, a, v, d in run_jobs(jobs, args.jobs or 1):
        print(f'equiv_main_emu: {fname:32s} {v}: {d}', file=sys.stderr)


RANK = {'identical': -1, 'equivalent': 0, 'differs': 1, 'not yet': 2}


def cmd_status(args):
    require_objects()
    orig = Originals()
    jobs = [(p, f, args.seed, args.trials) for p, f in recreated()]
    results = {}
    for path, fname, a, v, d in sorted(run_jobs(jobs, args.jobs or 2), key=lambda x: (x[0], x[1])):
        print(f'equiv_main_emu: {fname:32s} {v}: {d}', file=sys.stderr)
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
        f.write('# MAIN: recreated source vs the original image, per function (T24). Generated by\n')
        f.write('# tools/equiv_main_emu.py status; do not edit. identical = the bytes linked at the original address are the\n')
        f.write("# image's (CC-RX is not available, so only trivial functions); equivalent = passes the differential emulation\n")
        f.write("# (Ghidra p-code, rx62t). covered = bytes counted as re-implemented (the function's bytes up to the next\n")
        f.write('# original function); tools/readability_stats.py sums it. Rows with ghidra_name "-" have no original\n')
        f.write("# function in decomp/main/functions.tsv (address 0: none at all; otherwise one Ghidra's list lacks).\n")
        f.write('address\tghidra_name\tsize\tsource\tfile\tverdict\tcovered\tdetail\n')
        for a, g, n, src, fl, v, cov, det in sorted(rows):
            f.write(f'{a:08x}\t{g}\t{n}\t{src}\t{fl}\t{v}\t{cov}\t{det}\n')
    listed = [r for r in rows if r[1] != '-']
    tot = sum(r[2] for r in listed)
    cov = sum(r[6] for r in listed)
    cnt = {}
    for r in listed:
        cnt[r[5]] = cnt.get(r[5], 0) + 1
    print('equiv_main_emu: ' + ', '.join(f'{k} {v}' for k, v in sorted(cnt.items(), key=lambda kv: RANK[kv[0]])) +
          f' (of {len(listed)} Ghidra functions); re-implemented {cov} of {tot} bytes ({100.0 * cov / tot:.2f} %); '
          f'wrote {os.path.relpath(STATUS_TSV, ROOT)}')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    c = sub.add_parser('check')
    c.add_argument('functions', nargs='*')
    c.add_argument('--object', action='append', help='every function of this object (e.g. drivers/eeprom.o)')
    st = sub.add_parser('status')
    for p in (c, st):
        p.add_argument('--trials', type=int, default=200)
        p.add_argument('--seed', type=int, default=1)
        p.add_argument('--jobs', type=int, default=0, help='Ghidra workers (default: check 1, status 2)')
    args = ap.parse_args()
    {'check': cmd_check, 'status': cmd_status}[args.cmd](args)


if __name__ == '__main__':
    main()
