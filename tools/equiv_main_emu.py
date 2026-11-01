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
import atexit
import glob
import json
import os
import random
import re
import shutil
import signal
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'src/main')
FUNCS_TSV = os.path.join(ROOT, 'decomp/main/functions.tsv')
DATA_TSV = os.path.join(SRC, 'data_symbols.tsv')
ALIAS_TSV = os.path.join(SRC, 'aliases.tsv')
STATUS_TSV = os.path.join(SRC, 'status.tsv')
# the objects checked (EQUIV_MAIN_OBJDIR: another build, e.g. make OUT=out2, checked while a status run reads out/obj)
OBJDIR = os.environ.get('EQUIV_MAIN_OBJDIR') or os.path.join(SRC, 'out', 'obj')
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

# Functions called with a stub instead of the image's code: name -> number of arguments to record. The EEPROM
# transfers (T24 MAIN round 2): the settings store moves up to 0x5837 bytes through the bit-banged SPI, millions of
# emulated instructions per call; its callers are compared on the calls (address, buffer, length) instead, and
# eeprom_read/eeprom_write themselves are checked on their own (a function is never stubbed in its own check).
STUBS = {'eeprom_read': 3, 'eeprom_write': 3}
# Width in bytes of each recorded stub argument: only those bits reach the callee (eeprom_read/eeprom_write store
# the 16-bit address and length with MOV.W and reload them with MOVU.W, 0xFFFB14A4/0xFFFB14ED), while CC-RX and GCC
# leave different upper bits in the register (MOVU.W vs MOV.W)
STUB_WIDTHS = {'eeprom_read': (2, 4, 2), 'eeprom_write': (2, 4, 2)}
# eeprom_write's buffer: its bytes are recorded and compared; the buffer address of both only when it is not on the
# stack (a callee's stack buffer moves with the caller's frame, which differs between CC-RX -O0 and GCC; T24 MAIN
# round 3: cat_ext_SP -> cat_SP_eeprom_byte reads and writes a stack byte)
STUB_DATA = {'eeprom_write': (1, 2)}
STUB_BUF = {'eeprom_read': 1, 'eeprom_write': 1}     # the buffer argument, compared as 'stack' when on the stack
STACK_TOP = 0x1004
# RAM words that keep a pointer the function passed to a driver; when both runs leave a stack address there, it is
# compared as 'stack' (T24 MAIN round 4: displink_task -> displink_send_ack hands R_SCI1_Serial_Send a one-byte
# buffer on the stack, and the address follows the caller's frame, 12 bytes under CC-RX, 28 + 4 under GCC; the
# byte itself is compared through the SCI accesses). gp_sci1_tx_address (src/main/data_symbols.tsv).
STACK_PTR_SLOTS = (0x207FC,)
# Extra stubs per checked function: callee -> (number of arguments recorded, the values it returns, drawn per call). For tasks whose gates are
# functions of the whole radio state (T24 MAIN round 4: keyer_task runs only when tx_cw_keying_class() is not 0 and
# soft timer 19 has expired); the calls are compared like the other stubs. A stubbed callee has no side effects, so
# only callees whose effects the function does not read back are stubbed.
# Trials per function as a multiple of --trials, where the cases to reach outnumber the default (round 4: cat_dispatch
# has about 500 (index, length) pairs)
FUNC_TRIALS = {'cat_dispatch': 4, 'trx_sequencer': 2}
FUNC_STUBS = {
    'tuner_atas_task': {'swtimer_expired': (1, [0, 1, 1])},
    # scan_task: the predicates are functions of the receiver state; stubbed with 0 / 1
    'scan_task': {n: (0, [0, 1]) for n in ('FUN_fffe5ee3', 'FUN_fffe5ab2', 'FUN_fffe5acf', 'FUN_fffe5fdd',
                                           'FUN_fffe600f', 'FUN_fffe5ae7', 'FUN_fffe5f18', 'FUN_fffe5f4d')},
    # io_task: the power-off path ends in sw_reset, which does not return
    'io_task': {'swtimer_expired': (1, [0, 1, 1]), 'sw_reset': (0, [0]), 'supply_undervolt_check': (0, [0, 0, 1])},
    # sdr_task: the first updater that writes ends the pass, and sdr_bridge_mode relays until the DISPLAY ends it;
    # the bridge and the first group of updaters are stubbed so that the pass reaches the rest (their calls and the
    # TX argument are compared)
    'sdr_task': {'sdr_bridge_mode': (0, [0]), 'sdr_poll_reply': (1, [0, 1, 1]), 'sdr_upd_r0a_demod': (1, [0]),
                 'sdr_upd_r0b_band': (1, [0]), 'sdr_upd_r0c_rtty_shift': (0, [0]), 'sdr_upd_r0d': (0, [0]),
                 'sdr_upd_r0f_band': (1, [0]), 'sdr_upd_r20_scope_freq': (1, [0]), 'sdr_upd_r22_scope_span': (1, [0]),
                 'sdr_upd_r23': (0, [0]), 'sdr_upd_r25_tx_drive': (1, [0]), 'sdr_upd_r26': (1, [0]),
                 'sdr_upd_r27_scope_level': (1, [0])},
    'displink_task': {'swtimer_expired': (1, [0, 1, 1]), 'FUN_fffc911e': (0, [0, 1])},
    'tuner_rearm': {'FUN_fffed6f5': (0, [0, 1, 1]), 'vfo_tuner_bit_get': (0, [0, 1])},
    # trx_sequencer: its states wait for soft timers 12..17 (round 4: 60 % of the blocks with the timers' own RAM)
    'trx_sequencer': {'swtimer_expired': (1, [0, 1, 1])},
    'keyer_task': {'tx_cw_keying_class': (0, [0, 1, 1, 1, 1, 2]), 'swtimer_expired': (1, [0, 1, 1, 1]),
                   'FUN_fffb2dfe': (0, [0, 0, 1]), 'tx_breakin_on': (0, [0, 1])},
}


_SCRATCH = None


def _pid_alive(pid):
    try:
        os.kill(pid, 0)
    except ProcessLookupError:
        return False
    except PermissionError:
        return True
    return True


def scratch_root():
    """The one temporary directory of this run (EQUIV_MAIN_SCRATCH, default the system's temporary directory):
    the link scripts, the per-worker Ghidra project copies and the Ghidra logs all go below it, and the process that
    made it removes it on exit, also on SIGTERM/SIGHUP/SIGINT (T24 MAIN round 4: killed workers used to leave
    /tmp/equiv_main_* behind). A root left by a run that was killed with SIGKILL is removed by the next run (its
    owner's pid, in the file `pid`, no longer exists)."""
    global _SCRATCH
    if _SCRATCH is None:
        base = os.environ.get('EQUIV_MAIN_SCRATCH') or tempfile.gettempdir()
        os.makedirs(base, exist_ok=True)
        for d in glob.glob(os.path.join(base, 'equiv_main_run_*')):
            try:
                with open(os.path.join(d, 'pid')) as f:
                    pid = int(f.read().strip() or 0)
            except (OSError, ValueError):
                pid = 0
            if not pid or not _pid_alive(pid):
                shutil.rmtree(d, ignore_errors=True)
        _SCRATCH = tempfile.mkdtemp(prefix='equiv_main_run_', dir=base)
        owner = os.getpid()
        with open(os.path.join(_SCRATCH, 'pid'), 'w') as f:
            f.write(str(owner))

        def cleanup(root=_SCRATCH):
            if os.getpid() == owner:          # forked pool workers inherit this; only the owner removes the root
                shutil.rmtree(root, ignore_errors=True)
        atexit.register(cleanup)

        def on_signal(signum, frame):
            sys.exit(128 + signum)            # SystemExit: run_jobs terminates the pool, atexit removes the root
        for sg in (signal.SIGTERM, signal.SIGHUP, signal.SIGINT):
            signal.signal(sg, on_signal)
    return _SCRATCH


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
        # the typed globals of tools/ghidra/structs_main.h (g_ui, g_opstate, ...; tools/main_structs.py), then
        # src/main/data_symbols.tsv
        import importlib.util
        spec = importlib.util.spec_from_file_location('main_structs', os.path.join(ROOT, 'tools/main_structs.py'))
        ms = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(ms)
        self.data = ms.globals_map()
        self.data.update({r[0]: int(r[1], 16) for r in read_tsv(DATA_TSV)[1:]})

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
        with tempfile.NamedTemporaryFile(suffix='.bin', dir=scratch_root()) as f:
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
    return sorted(glob.glob(os.path.join(OBJDIR, '**', '*.o'), recursive=True))


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
        self.tmp = tempfile.mkdtemp(prefix='proj_', dir=scratch_root())
        proj = os.path.join(self.tmp, 'proj')
        os.mkdir(proj)
        shutil.copy(os.path.join(src, 'FT710_MAIN.gpr'), proj)
        shutil.copytree(os.path.join(src, 'FT710_MAIN.rep'), os.path.join(proj, 'FT710_MAIN.rep'),
                        ignore=shutil.ignore_patterns('*.lock*', '*~'))
        env = dict(os.environ)
        env.setdefault('GHIDRA_JAVA_HOME', '/usr/lib/jvm/java-21-openjdk-amd64')
        env.setdefault('MAXMEM', '1500M')
        self.log = tempfile.NamedTemporaryFile('w+', prefix='ghidra_', suffix='.log', delete=False,
                                               dir=os.environ.get('EQUIV_MAIN_KEEP_LOG') and tempfile.gettempdir()
                                               or self.tmp)
        self.p = subprocess.Popen([os.path.join(ROOT, 'tools/ghidra-headless.sh'), proj, 'FT710_MAIN', '-process',
                                   'FT-710_MAIN_V0112.bin', '-noanalysis', '-readOnly',
                                   '-scriptPath', os.path.join(ROOT, 'tools/ghidra'), '-postScript', 'EquivMainEmu.java'],
                                  stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=self.log, text=True, env=env,
                                  start_new_session=True)     # its own process group: close() kills the JVM too
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
            self.p.wait(timeout=10)       # an idle engine quits at once; one still starting or running is killed
        except Exception:
            try:
                os.killpg(self.p.pid, signal.SIGKILL)     # the launcher scripts and the JVM below them
            except OSError:
                pass
            self.p.wait()
        self.log.close()
        if os.path.exists(self.log.name) and not os.environ.get('EQUIV_MAIN_KEEP_LOG'):
            os.unlink(self.log.name)
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


def buffer_args(nptr):
    """(buffer, ..., n) functions whose callers always pass a real buffer: no NULL pointer. A NULL buffer with a
    large n reads RAM 0.. across the stack (0xF00 down), where the original keeps its locals and the recreated
    code does not, so the two would differ on a call that never happens (T24 MAIN round 2: sum8 with n = 0x15AB)."""
    def pre(rng, regs):
        for k in range(nptr):
            if regs[k] == 0:
                regs[k] = ARGBUF + 0x800 * k
        return [], None
    return pre


def save_msg_args(rng, regs):
    """eeprom_save_msg (type, n): the three types, n 1..5, and the rejected values next to them."""
    regs[0] = rng.choice([0, 1, 2, 2, 3, 0xFFFFFFFF])
    regs[1] = rng.choice([0, 1, 2, 3, 4, 5, 6, 0xFFFFFFFF])
    return [], None


def copy_if_changed_args(rng, regs):
    """displink_copy_if_changed (src, dst, n): every caller passes a staging buffer (0x1741 or 0x16A0) and the frame
    buffer 0x1456 with n <= 0x23F (displink_tx_37), so the two never overlap; random draws with n above 0x800 made
    them overlap (trial 45 of round 2 differed there). Settled in round 3 by single runs: SMOVF and the byte loop
    give the same RAM on overlapping buffers (dst - src = 0x10 and 0x800, n up to 0xFFFF, and the same fault at
    0x40000); the two differ only when dst..dst+n covers the original's stack frame, where it keeps its result flag
    (1[r0] = 0xEF1, copied to R1 at 0xFFF9C6A3): dst = 0, n = 0xF00 returns 152 = the copied byte, n = 0xEE0
    returns 1 like the recreated code. No caller passes a stack buffer."""
    regs[0], regs[1] = ARGBUF, ARGBUF + 0x800
    regs[2] = rng.choice([0, 1, 0x36, 0x98, 0xE2, 0x23F, rng.randrange(0, 0x800)])
    return [], None


CAT_RING, CAT_RING_IN, CAT_RING_OUT, CAT_E_SLOT = 0x1E14C, 0x11FEC, 0x11FEB, 0x1B78C   # src/main/data_symbols.tsv
_CAT_LENS = None


def cat_lens():
    """index -> the command lengths cat_dispatch tests for it, with their neighbours (decomp/main/cat_dispatch.tsv)."""
    global _CAT_LENS
    if _CAT_LENS is None:
        _CAT_LENS = {}
        for r in read_tsv(os.path.join(ROOT, 'decomp/main/cat_dispatch.tsv'))[1:]:
            if r[0] != 'primary':
                continue
            ns = {int(x) for x in re.findall(r'len\D{1,2}(\d+)', r[4] if len(r) > 4 else '')}
            _CAT_LENS[int(r[1])] = sorted(ns | {n + 1 for n in ns} | {n - 1 for n in ns if n} | {3})
    return _CAT_LENS


def cat_text(rng, mn, n=0x60):
    """A CAT command text: the mnemonic, then mostly digits (the handlers parse decimal parameters)."""
    body = bytes(rng.choice(b'0000111223456789;+-PWRSE') for _ in range(n - len(mn)))
    return bytes(mn) + body


def cat_mnemonic(rng, img, ext=False):
    tab, cnt = (0xFFF806BC, 10) if ext else (0xFFF805EC, 104)
    k = rng.randrange(cnt)
    mn = bytearray(img.read(tab + 2 * k, 2))
    if rng.random() < 0.3:
        mn = bytearray(c | 0x20 for c in mn)     # lower case: cat_parse upper-cases the mnemonic
    return mn


_TRIAL = 0          # the number of the running trial (Checker.check), for presets that enumerate cases


def cat_dispatch_args(rng, regs):
    """cat_dispatch (slot, index, len): every index of the table with the lengths its case tests (T24 MAIN round 3;
    random indexes and lengths reach only the error path). Round 4: the first trials go through every (index,
    length) pair in turn (random draws gave each index about two trials: 55 % of the blocks), the rest are random."""
    lens = cat_lens()
    pairs = [(i, n) for i in range(104) for n in lens.get(i, [3])]
    regs[0] = ARGBUF
    if _TRIAL < len(pairs):
        idx, regs[2] = pairs[_TRIAL]
    else:
        idx = rng.randrange(104) if rng.random() < 0.95 else rng.randrange(104, 256)
        regs[2] = rng.choice(lens.get(idx, [3])) if rng.random() < 0.9 else rng.randrange(0, 0x40)
    regs[1] = idx
    slot = bytes([rng.randrange(1, 4), 0]) + regs[2].to_bytes(2, 'little') + cat_text(rng, b'XX')
    return [(ARGBUF, slot)], None


def cat_dispatch_ext_args(rng, regs):
    """cat_dispatch_ext (slot, index, len): the ten extended indexes and the lengths their cases test."""
    regs[0] = ARGBUF
    regs[1] = rng.randrange(10) if rng.random() < 0.95 else rng.randrange(10, 256)
    regs[2] = rng.choice([5, 6, 7, 8, 9, 10, 11, 14, 15, 16]) if rng.random() < 0.9 else rng.randrange(0, 0x40)
    slot = bytes([rng.randrange(1, 4), 0]) + regs[2].to_bytes(2, 'little') + cat_text(rng, b'XX')
    return [(ARGBUF, slot)], None


def cat_ext_sp_args(rng, regs):
    """cat_ext_SP (slot): "SP" + the sub-command letters it tests (S D I W R M N A, either case) and a length."""
    text = bytearray(cat_text(rng, b'SP'))
    text[2] = rng.choice(b'SsDdIiWRwrMmNnAaX')
    text[3] = rng.choice(b'WwRrSsX')
    text[4] = rng.choice(b'EeX')
    n = rng.randrange(5, 20)
    if rng.random() < 0.5:                       # a good sum over the first n - 2 bytes (cat_checksum_ok)
        text[n - 2] = sum(text[:n - 2]) & 0xFF
    regs[0] = ARGBUF
    return [(ARGBUF, bytes([rng.randrange(1, 4), 0]) + n.to_bytes(2, 'little') + bytes(text))], None


def cat_parse_args(rng, regs):
    """cat_parse (): a command in the ring slot at the tail (mnemonic from either table, port 1..3), or an E9 frame
    in the E9 slot when the ring is empty."""
    img = _IMG
    out = rng.randrange(60)
    empty = rng.random() < 0.2
    loads = [(CAT_RING_OUT, bytes([out])), (CAT_RING_IN, bytes([out if empty else (out + 1 + rng.randrange(5)) % 60]))]
    ext = rng.random() < 0.15
    mn = cat_mnemonic(rng, img, ext)
    if rng.random() < 0.05:
        mn = bytearray(b'QQ')
    n = rng.randrange(3, 0x20)
    loads.append((CAT_RING + 0x6A * out, bytes([rng.randrange(1, 4), 0]) + n.to_bytes(2, 'little') + cat_text(rng, mn)))
    e9 = b'E9' if rng.random() < 0.7 else bytes(cat_mnemonic(rng, img, True))
    loads.append((CAT_E_SLOT, bytes([1 if rng.random() < 0.8 else 0, rng.randrange(1, 4), 0, 0]) + cat_text(rng, e9, 0x40)))
    return loads, None


def ram_bytes(table):
    """RAM bytes that a function switches on, drawn from the values it tests (random words rarely hit a state
    number): {address: choices}."""
    def pre(rng, regs):
        return [(a, bytes([rng.choice(v)])) for a, v in table.items()], None
    return pre


# trx_sequencer: trx_state 0..8 (0x20B18), the two TX acks, ptt_source (0x1204D), the last P14 level (0x12051),
# pc_keying_active (0x12050), the speaker route (0x20FCC), dsp_route_ready (0x20B49), pb3_last (0x20B44)
TRX_SEQ_BYTES = {0x20B18: range(9), 0x20B19: (0, 1), 0x20B1A: (0, 1), 0x1204D: range(11), 0x12051: (0, 1),
                 0x12050: (0, 1), 0x20FCC: range(5), 0x20B49: (0, 1), 0x20B44: (0, 1)}

def ram_words(addr, choices):
    """A 16-bit RAM word drawn from choices (the register numbers a shadow store compares)."""
    def pre(rng, regs):
        return [(addr, rng.choice(choices).to_bytes(2, 'little'))], None
    return pre


def real_buffer(k):
    """Argument k is a caller's buffer, never in the stack (a random small pointer would read the stack frames,
    which differ between the two builds)."""
    def pre(rng, regs):
        if regs[k] < 0x1004:
            regs[k] = ARGBUF + 0x800 * k
        return [], None
    return pre


# the registers of dsp_shadow_store 0xFFFA037A and sdr_shadow_update 0xFFFA2C9F (src/main/app/dsp_link.c, sdr_link.c)
DSP_SHADOW_REGS = [0, 1, 2, 3, 4, 6, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 0x20, 0x21, 0x22] + list(range(0x25, 0x39)) + \
    [0x3A, 0x3B] + list(range(0x40, 0x59)) + [0x5C, 0x5D] + list(range(0x60, 0x69)) + \
    [0x400B, 0x400D, 0x4020, 0x4022, 0x4023, 0x4025, 0x4026, 0x5, 0x7, 0x39, 0x1234]
SDR_SHADOW_REGS = [0xFFFF, 0, 1, 3, 4, 8, 9, 10, 11, 12, 13, 14, 15] + list(range(0x12, 0x17)) + list(range(0x18, 0x28)) + \
    [0x30, 0x31, 0x32, 0x33, 0x37, 2, 0x17, 0x34, 0x1234]

CAT_HANDLER = re.compile(r'cat_[A-Z][A-Z0-9]$|cat_[A-Z]{2}_[A-Z]{2}$')


def cat_handler_args(rng, regs):
    """A CAT handler (text, set[, len]): a command text whose parameters are mostly digits, read or set form."""
    if regs:
        regs[0] = ARGBUF
    if len(regs) > 1:
        regs[1] = rng.choice([0, 1, 1])
    if len(regs) > 2 and rng.random() < 0.8:
        regs[2] = rng.randrange(3, 0x40)
    t = bytearray(cat_text(rng, b'XX'))
    for k in (2, 3):                 # P1 / P2 = '0' half the time: most handlers refuse anything else there (round 4)
        if rng.random() < 0.5:
            t[k] = ord('0')
    return [(ARGBUF, bytes(t))], None


def cat_ss_args(rng, regs):
    """cat_SS (text, set): "SS0", the item 0..8 (and a bad one), a value digit, P4..P6 mostly '0'; item 4 with a
    sign, two digits, '.', '0'/'5'; item 7 with the four digits 0..2 / 0..5 (T24 MAIN round 4: random digits reach a
    third of the blocks)."""
    item = rng.choice(b'0123456789A')
    t = bytearray(cat_text(rng, b'SS'))
    t[2] = ord('0') if rng.random() < 0.9 else ord('1')
    t[3] = item
    t[4] = rng.choice(b'0123456789AB')
    for k in (5, 6, 7, 8):
        t[k] = ord('0') if rng.random() < 0.85 else rng.choice(b'123.5')
    if item == ord('4'):
        t[4] = rng.choice(b'+-+-0')
        t[5], t[6] = rng.choice(b'0123'), rng.choice(b'0123456789')
        t[7] = ord('.') if rng.random() < 0.9 else ord('0')
        t[8] = rng.choice(b'0505X')
    elif item == ord('7'):
        t[4:8] = bytes(rng.choice(b'0122223') for _ in range(4))
        t[6] = rng.choice(b'0123456')
        t[8] = ord('0') if rng.random() < 0.9 else ord('1')
    regs[0] = ARGBUF
    regs[1] = rng.choice([0, 1, 1])
    return [(ARGBUF, bytes(t))], None


G_UI, G_OP = 0x20B04, 0x9A2A           # g_ui, g_opstate (tools/main_structs.py --globals)


def keyer_task_args(rng, regs):
    """keyer_task: its state 0..7 (and one beyond), the speed in use and the menu speed (often equal), the keyer
    type and on/off, the message slot and CW MEMORY n, a keyer text of the characters it treats specially, element
    counts that are sometimes equal (the end of a send)."""
    sp = rng.choice([0, 4, 20, 31, 36, 41, 60])
    loads = [(G_UI + 0x2B, bytes([rng.choice(range(9))])), (0x1B4D5, bytes([sp if rng.random() < 0.6 else rng.choice([4, 20, 45])])),
             (G_OP + 0x1D9, bytes([sp])), (G_OP + 0x1D8, bytes([rng.choice([0, 1, 1])])),
             (G_OP + 0x7D, bytes([rng.choice(range(7))])), (G_OP + 0x7F, bytes([rng.randrange(21)])),
             (G_UI + 0x93, bytes([rng.choice([0, 0, 0, 1])])), (G_UI + 0x408, bytes([rng.choice([0, 0, 0, 1])])),
             (G_UI + 0x1C8, bytes([rng.choice(range(7))])), (G_UI + 0x1D1, bytes([rng.choice([0, 1])])),
             (0x1215D, bytes([rng.choice([0, 1, 1, 2])])), (0x12166, bytes([rng.choice([0, 1])])),
             (0x12160, bytes(rng.choice([0, 0, 1, 2]) for _ in range(5))),
             (G_OP + 0x83, bytes(rng.choice([0, 1]) for _ in range(5))), (G_OP + 0x88, bytes([rng.randrange(1, 61)])),
             (0x21040, (ARGBUF + 0x400).to_bytes(4, 'little'))]
    n = rng.randrange(0, 0x800)
    loads.append((0x1FA38, rng.randrange(0, 0x600).to_bytes(2, 'little')))
    loads.append((0x1FA3A, n.to_bytes(2, 'little')))
    loads.append((0x1FA3C, (n if rng.random() < 0.5 else rng.randrange(0, 0x800)).to_bytes(2, 'little')))
    for k in range(5):
        text = bytes(rng.choice(b'CQ TEST#<>[]^0123ABK ?') for _ in range(50))
        loads.append((0x969F + 0x33 * k, bytes([rng.randrange(0, 51)]) + text))
        loads.append((0x93A7 + 0x98 * k, rng.randrange(0, 0x500).to_bytes(2, 'big') + bytes(rng.getrandbits(8) for _ in range(150))))
    return loads, None


def memch_text_args(rng, regs):
    """The memory-channel commands (MR, ...): "XX" + a channel 000..120 as three digits or one of the 34 names from
    channel 99 on (cat_pms_names 0xFFF806E9, sometimes lower case), the channel-used flags 0x60CB.. mostly 1."""
    cat_handler_args(rng, regs)                  # the set flag and length as for the other handlers
    t = bytearray(cat_text(rng, b'XX'))
    if rng.random() < 0.6:
        t[2:5] = b'%03d' % rng.choice([0, 1, 2, 50, 98, 99, 100, 117, 120, rng.randrange(1, 100)])
    else:
        nm = _IMG.read(0xFFF806E9 + 3 * rng.randrange(0x23), 3)
        t[2:5] = bytes(c | 0x20 if rng.random() < 0.3 and 0x41 <= c <= 0x5A else c for c in nm)
    used = bytes(1 if rng.random() < 0.8 else rng.choice([0, 2]) for _ in range(117))
    return [(ARGBUF, bytes(t)), (0x60CB, used)], None


def cat_mw_args(rng, regs):
    """cat_MW: memch_text_args, then IF's layout with each field valid most of the time: a frequency in or out of
    the bands, sign and clarifier digits, P4 P5, a mode character (cat_mode_codes 0xFFF806D0), '1', tone, "00",
    shift."""
    loads, _ = memch_text_args(rng, regs)
    t = bytearray(loads[0][1])
    ok = lambda p: rng.random() < p
    t[5:14] = b'%09d' % rng.choice([7074000, 14074000, 50313000, 144000000, 0, 999999999, rng.randrange(10 ** 9)])
    t[14] = rng.choice(b'+-') if ok(0.9) else ord('0')
    t[15:19] = b'%04d' % rng.randrange(10000) if ok(0.9) else b'12A4'
    t[19], t[20] = rng.choice(b'01') if ok(0.95) else ord('2'), rng.choice(b'01') if ok(0.95) else ord('X')
    t[21] = _IMG.read(0xFFF806D0 + rng.randrange(16), 1)[0] if ok(0.9) else ord('Z')
    t[22] = ord('1') if ok(0.9) else ord('0')
    t[23] = rng.choice(b'012') if ok(0.9) else ord('3')
    t[24:26] = b'00' if ok(0.9) else b'01'
    t[26] = rng.choice(b'012') if ok(0.9) else ord('3')
    return [(ARGBUF, bytes(t))] + loads[1:], None


def cat_sf_args(rng, regs):
    """cat_SF: P1 0/1, P2 one of its characters, the FUNC knob and the DSP knob item among the values it maps."""
    loads, _ = cat_handler_args(rng, regs)
    t = bytearray(loads[0][1])
    t[2] = rng.choice(b'0011X')
    t[3] = rng.choice(b'0123456789ABCDEFGHI')
    return [(ARGBUF, bytes(t)), (G_OP + 0x39F, bytes([rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0x12, 0x13, 0x14, 0x15])])),
            (G_UI + 0x7A, bytes([rng.choice(range(0x1C, 0x23))]))], None


def cat_dt_args(rng, regs):
    """cat_DT: DT0 with 20yy and month / day around the limits (February in leap and other years), DT1 with hours
    and minutes around 23 / 59."""
    loads, _ = cat_handler_args(rng, regs)
    t = bytearray(loads[0][1])
    t[2] = rng.choice(b'0011X')
    if t[2] == ord('0'):
        t[3:11] = b'%02d%02d%02d%02d' % (rng.choice([20, 20, 20, 19, 21]), rng.randrange(100), rng.choice(range(14)),
                                         rng.choice([0, 1, 28, 29, 30, 31, 32, rng.randrange(40)]))
    else:
        t[3:9] = b'%02d%02d%02d' % (rng.choice([0, 12, 23, 24, rng.randrange(30)]), rng.choice([0, 59, 60, rng.randrange(70)]),
                                    rng.randrange(60))
    if rng.random() < 0.1:
        t[rng.randrange(3, 11)] = ord('X')
    return [(ARGBUF, bytes(t))], None


def displink_task_args(rng, regs):
    """displink_task: a received frame (ACK, NAK, a DISPLAY frame type or junk) half the time, the link flags
    0x1B3CC..0x1B3D5 and the delayed-0x24 request in all their combinations."""
    t = rng.choice([0x06, 0x15] + list(range(0xE0, 0xF3)) + [rng.getrandbits(8)])
    frame = bytes([t]) + bytes(rng.getrandbits(8) for _ in range(0x40))
    return [(0x25D38, G_UI.to_bytes(4, 'little')), (0xA08A, bytes([rng.choice([0, 1])])), (0x9E86, frame),
            (0x1B3CC, bytes(rng.choice([0, 0, 1]) for _ in range(10))), (G_UI + 0x401, bytes([rng.choice([0, 1])]))], None


def displink_e1_frame(rng, regs):
    """An 0xE1 frame {0xE1, encoder id 0..7, steps} in the argument buffer."""
    regs[0] = ARGBUF
    return [(ARGBUF, bytes([0xE1, rng.randrange(8), rng.getrandbits(8)]))], None


def g_ui_ptr_ok(pre=None):
    """The DISPLAY frame builders read g_ui through the pointer at 0x25D38 (= 0x20B04 after _INITSCT); the RAM fill
    would replace it with a random word, so it is set back (and pre's loads added)."""
    def f(rng, regs):
        loads = pre(rng, regs)[0] if pre else []
        return loads + [(0x25D38, G_UI.to_bytes(4, 'little'))], None
    return f


def both(a, b):
    """Two presets in turn (their loads together)."""
    def pre(rng, regs):
        la, _ = a(rng, regs)
        lb, _ = b(rng, regs)
        return la + lb, None
    return pre


_IMG = None      # the Image of the running Checker (cat_parse_args reads the mnemonic tables from it)

PRESETS = {'eeprom_save_msg': save_msg_args, 'cat_dispatch': cat_dispatch_args, 'cat_dispatch_ext': cat_dispatch_ext_args,
           'cat_ext_SP': cat_ext_sp_args, 'cat_parse': cat_parse_args,
           'trx_sequencer': ram_bytes(TRX_SEQ_BYTES), 'dsp_set_rf_gain': ram_bytes({0x9AB6: (0, 1, 2, 3)}),
           'dsp_shadow_store': ram_words(0x1B6DE, DSP_SHADOW_REGS), 'sdr_shadow_update': ram_words(0x1B784, SDR_SHADOW_REGS),
           'eeprom_write_raw': real_buffer(1), 'eeprom_read_raw': real_buffer(1),
           'tuner_int_task': ram_bytes({0x1B3AC: range(0x17), G_UI + 0x3B: range(7), G_UI + 0x3D: range(3)}),
           'tuner_ext_task': ram_bytes({0x1B3C8: range(0x12), G_UI + 0x3B: range(7), G_UI + 0x3C: range(3),
                                        G_OP + 0x8D: range(4)}),
           'tuner_atas_task': ram_bytes({0x1B3C3: (0, 1), G_UI + 0x408: range(4)}),
           'tuner_rearm': ram_bytes({G_OP + 0x8E: range(5), G_UI + 0x3B: range(8)}),
           'displink_build_30': g_ui_ptr_ok(ram_bytes({G_UI + 0x1C2: list(range(15)) + [0xFF], G_OP + 0x393: (0, 1)})),
           'displink_build_41': g_ui_ptr_ok(ram_bytes({G_UI + 0x439: [0, 1, 50, 98, 99, 110, 116, 117, 125, 131, 132],
                                                     G_UI + 0x1DB: range(5), G_OP + 0x98: (0, 1)})),
           'sdr_task': ram_bytes({0x1C8B: (0, 0, 0, 1), 0x1C8D: (0, 0, 0, 0, 0, 1), 0x1B3DD: (0, 1), 0x1B3DC: (0, 1),
                                  G_UI + 0x67: (0, 1), G_UI + 0x14: range(9)}),
           'dispreq_e7_task': both(ram_bytes({G_UI + 0x488: range(7), G_UI + 0x3F9: range(5), G_UI + 0x3FC: (0, 1, 2),
                                             G_UI + 0x93: (0, 1), G_UI + 0x3FD: range(4), G_UI + 0xAC: range(10)}),
                                  lambda rng, regs: ([(0x25D70, G_UI.to_bytes(4, 'little')),
                                                      (G_UI + 0x489, b'\0\0\0')], None)),
           'io_task': ram_bytes({G_UI + 0x2C: (0, 0, 1, 2), G_UI + 0x82: (0, 1), G_UI + 0xBA: (0, 1),
                                 G_UI + 0x40: (0, 1), G_UI + 0x14: (8, 8, 1, 3)}),
           'rf_ctrl_task': ram_bytes({0x12042: (0, 1)}),
           'scan_task': both(ram_bytes({0x18877: range(9), G_UI + 0x418: (0, 1, 1, 1), G_UI + 0xBA: (0, 0, 0, 1)}),
                             lambda rng, regs: ([(0x25D7C, G_UI.to_bytes(4, 'little'))], None)),
           'displink_build_37': g_ui_ptr_ok(), 'displink_task': displink_task_args, 'displink_build_60': g_ui_ptr_ok(),
           'displink_rx_E1_encoder': g_ui_ptr_ok(both(displink_e1_frame, ram_bytes({G_UI + 0x80: (0, 0, 0, 1), G_UI + 0x70: (0, 1), G_UI + 0x74: (0, 1), G_UI + 0x93: (0, 1), G_UI + 0x3FD: range(5), G_UI + 0x437: (0, 0, 1)}))),
           'displink_build_status': g_ui_ptr_ok(ram_bytes({G_OP + 0x393: (0, 1), G_OP + 0x234: (0, 1), G_UI + 0x437: (0, 0, 1),
                                                         G_UI + 0x483: (0, 1), G_UI + 0x405: (0, 1)})),
           'displink_build_31': g_ui_ptr_ok(ram_bytes({G_UI + 0x1C2: [0x1E, 0x1F, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
                                                                  0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33,
                                                                  0x38, 0x39, 0x3A, 0x43, 0x44, 0x45, 0x46, 0x55, 0x58, 0x5E, 0x60]})),
           'displink_build_70': g_ui_ptr_ok(ram_bytes({G_UI + 0xBB: list(range(28)) + [0xFF]})),
           'displink_build_39': g_ui_ptr_ok(ram_bytes({G_UI + 0x1C7: (0, 1, 2, 3), G_UI + 0x78: range(4),
                                                     G_UI + 0x1D1: (0, 1), G_UI + 0x1CE: range(10)})),
           'cat_SS': cat_ss_args, 'keyer_task': keyer_task_args, 'cat_MR': memch_text_args, 'cat_MW': cat_mw_args,
           'cat_MC': memch_text_args, 'cat_SF': cat_sf_args, 'cat_DT': cat_dt_args,
           'cat_GP': both(cat_handler_args, ram_bytes({0x9AB7: (0, 3, 3, 3)})),   # TUN/LIN PORT SELECT = GPO
           'sum8': buffer_args(1), 'cat_checksum_ok': buffer_args(1), 'displink_put_sum': buffer_args(1),
           'displink_copy_if_changed': copy_if_changed_args, 'dsp_sum8': buffer_args(1), 'sdr_sum8': buffer_args(1),
           'dsp_reply_sum_ok': buffer_args(1), 'sdr_check_hex_sum': buffer_args(1),
           'R_S12AD0_Get_ValueResult': adc_channel_args, 'R_S12AD1_Get_ValueResult': adc_channel_args,
           '__udiv64': udiv64_args, 'eeprom_read': eeprom_args, 'eeprom_write': eeprom_args,
           'strncmp': strncmp_args, 'sbrk': sbrk_args, 'heap_getmem': sbrk_args, 'sci5_rx_byte_hook': sci5_hook_args}


# --- T24 MAIN UI track (BSP, front-panel input, meters, dial steps, beep): presets of the functions in
# src/main/bsp/r_bsp_sys.c, src/main/app/ui_*.c, meters.c ---

SWINT_TASKS, SWINT_NUM, SWINT_TOP, SWINT_BOTTOM = 0x20318, 0x142C, 0x142E, 0x1430   # src/main/data_symbols.tsv
SWINT_ACCESS, SWINT_DUMMY = 0x20310, 0xFFF910BC


def swint_state(rng, unit):
    """A software-interrupt unit with its access word free (1) most of the time, a few queued slots in every status
    and the image's dummy task as the task (a random task address would run anywhere)."""
    loads = [(SWINT_ACCESS + 4 * unit, (1 if rng.random() < 0.85 else 0).to_bytes(4, 'little'))]
    slots = b''.join(rng.choice([0, 1, 1, 2, 3]).to_bytes(4, 'little') + SWINT_DUMMY.to_bytes(4, 'little') +
                     rng.getrandbits(32).to_bytes(4, 'little') for _ in range(9))
    loads.append((SWINT_TASKS + 0x6C * unit, slots))
    loads += [(SWINT_NUM + unit, bytes([rng.choice([0, 1, 3, 7, 8, 9])])),
              (SWINT_TOP + unit, bytes([rng.randrange(10)])), (SWINT_BOTTOM + unit, bytes([rng.randrange(10)]))]
    return loads


def swint_unit_args(cmds=None):
    """(unit 0/1 or a bad one, [cmd], arg): the unit's state, arg a buffer whose first byte is a slot / level."""
    def pre(rng, regs):
        unit = rng.choice([0, 1, 0, 1, 2, 0xFFFFFFFF])
        regs[0] = unit
        k = 1
        if cmds is not None:
            regs[1] = rng.choice(cmds)
            k = 2
        if len(regs) > k:
            regs[k] = ARGBUF + 0x800 * k
        loads = swint_state(rng, unit if unit in (0, 1) else 0)
        if len(regs) > k:
            loads.append((ARGBUF + 0x800 * k, bytes([rng.choice([0, 1, 5, 8, 9, 15, 16, 0xFF])]) +
                          bytes(rng.getrandbits(8) for _ in range(0x80))))
        return loads, None
    return pre


def bsp_group_args(rng, regs):
    """bsp_interrupt_group_enable_disable (vector, enable, ipl): vectors at the ends of the six group ranges and
    outside them, enable 0/1, ipl 0..16."""
    regs[0] = rng.choice([0x10, 0x11, 0x12, 0x13, 0x14, 0x30, 0x31, 0x32, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x56, 0x57,
                          0x58, 0x5C, 0x5D, rng.randrange(0x60)])
    regs[1] = rng.choice([0, 1, 1, 2])
    regs[2] = rng.choice([0, 1, 5, 14, 15, 16, rng.randrange(16)])
    return [], None


def bsp_region_args(rng, regs):
    """R_BSP_RegisterProtect* (region): the four regions (and one past), counters around 0 / 1."""
    regs[0] = rng.choice([0, 1, 2, 3, 3, 4])
    return [(0x1B5FC, b''.join(rng.choice([0, 0, 1, 2]).to_bytes(2, 'little') for _ in range(5)))], None


def bsp_fit_args(rng, regs):
    """bsp_fit_interrupts_control (enable, *ipl): a buffer holding a level 0..16."""
    regs[0] = rng.choice([0, 1, 2])
    regs[1] = rng.choice([ARGBUF + 0x800, ARGBUF + 0x800, 0, 0x10000000])
    return [(ARGBUF + 0x800, rng.choice([0, 3, 14, 15, 16]).to_bytes(4, 'little'))], None


UI_PRESETS = {
    'bsp_interrupt_group_enable_disable': bsp_group_args,
    'R_BSP_RegisterProtectEnable': bsp_region_args, 'R_BSP_RegisterProtectDisable': bsp_region_args,
    'bsp_fit_interrupts_control': bsp_fit_args,
    'bsp_swint_clear_task': swint_unit_args(), 'bsp_swint_clear_all_task': swint_unit_args(),
    'bsp_swint_execute_task': swint_unit_args(), 'R_BSP_SoftwareInterruptSetTask': swint_unit_args(),
    'R_BSP_SoftwareInterruptControl': swint_unit_args(list(range(14))),
    'bsp_swint_set_interrupt_priority': swint_unit_args(),
    # dial steps (src/main/app/ui_dial.c): the request flags of g_ui through the pointer 0x25D58, FINE / FAST, the
    # DIAL STEP menu values, the mode nibble of both VFO records
    'dial_step_hz': both(lambda rng, regs: ([(0x25D58, G_UI.to_bytes(4, 'little'))], None),
                         ram_bytes({G_UI + 0x415: (0, 0, 0, 1), G_UI + 0x416: (0, 1), G_UI + 0x418: (0, 0, 1),
                                    G_UI + 0x46A: (0, 0, 0, 1), G_UI + 0x46B: (0, 0, 1), G_UI + 0x46D: (0, 1),
                                    G_UI + 0x478: (0, 1), G_UI + 0x479: (0, 1), G_OP + 0x237: (0, 1, 2),
                                    0x9D09: range(16), 0x9D63: range(16)})),
    'dial_step_mode_hz': ram_bytes({G_OP + 0x237: (0, 1, 2, 3), G_OP + 0xCF: (0, 1, 2, 3), G_OP + 0xD0: (0, 1, 2, 3)}),
    'ch_step_scale': ram_bytes({G_OP + 0x237: (0, 1, 2, 2), 0x1B4E5: (0, 1)}),
    # key tables (src/main/app/ui_keys.c): the microphone assignments 0..20 and a key code inside the 863-entry
    # tables (a random code read a word past the table that pointed at Undefined_0xD8, whose RTE pops the caller's
    # frame: trial 89 of key_call_press)
    'key_assign_slot': lambda rng, regs: (regs.__setitem__(0, rng.choice([0x348, 0x34E, 0x35B, 0x35C, 0x35D, 0x35E,
                                                                           rng.randrange(0x35F)])) or [], None),
}
for _n in ('key_call_press', 'key_call_short', 'key_call_long', 'key_call_repeat', 'key_call_release'):
    UI_PRESETS[_n] = lambda rng, regs: ([(0x1FA40, rng.choice([0x300, 0x30F, 0x312, rng.randrange(0x35F)]).to_bytes(2, 'little'))], None)
# the frame-0x50 keyboard builders (src/main/app/ui_kbd.c) read g_ui through 0x25D38
for _n in ('dl50_mycall', 'dl50_memory_name', 'dl50_cw_text', 'dl50_rtty_text', 'dl50_psk_text', 'dl50_file_name',
           'dl50_preset_name', 'kbd_fmt_char_pos', 'dl50_slot_label', 'dl50_msg_text'):
    UI_PRESETS[_n] = g_ui_ptr_ok(ram_bytes({G_UI + 0xC0: (0, 1, 2, 3), G_UI + 0xC1: range(50), G_UI + 0xBF: range(5),
                                            G_UI + 0x1BC: (0, 0, 1)}))
UI_PRESETS['kbd_copy_text'] = g_ui_ptr_ok(both(real_buffer(0), real_buffer(1)))
UI_PRESETS['key_class_of'] = both(UI_PRESETS['key_assign_slot'],
                                  ram_bytes({G_OP + 0x9E + k: list(range(21)) for k in range(6)}))
PRESETS.update(UI_PRESETS)
# adc_scan_blocking polls adc_scan_done, which waits on the S12AD scan-end flag; with random peripheral reads both runs
# ran out of budget in every trial, so the two drivers are stubbed (their calls are compared)
FUNC_STUBS.update({'adc_scan_blocking': {'adc_scan_start': (0, [0]), 'adc_scan_done': (0, [0, 0, 1])}})


def norm_stack_ptrs(a, h):
    """A changed-RAM run [addr, hex] with each STACK_PTR_SLOTS word that holds a stack address replaced by a
    marker."""
    b = bytearray.fromhex(h)
    for slot in STACK_PTR_SLOTS:
        k = slot - a                     # the run holds only the changed bytes: often the low half of the word
        if 0 <= k < len(b):
            n = min(4, len(b) - k)
            if int.from_bytes(b[k:k + n], 'little') < STACK_TOP:
                b[k:k + n] = b'\xee' * n
    return [a, b.hex()]


def run(eng, bases, entry, regs, loads, seed, budget, stubs, cover, isr, mmio_fixed=None, trace=False, rets=None):
    q = {'op': 'run', 'bases': bases, 'entry': entry, 'sp': STACK, 'seed': seed, 'budget': budget,
         'regs': {f'R{k + 1}': v for k, v in enumerate(regs[:NREG])},
         'stack': ([0x00030000] if isr else []) + list(regs[NREG:]),
         'loads': [[a, d.hex()] for a, d in loads], 'snap': SNAP, 'track': TRACK,
         'stubs': {str(a): [n, STUBS[n] if n in STUBS else rets[a][0], *STUB_DATA.get(n, ())] for a, n in stubs.items()},
         'cover': sorted(cover)}
    if rets:
        q['stub_rets'] = {str(a): v[1] for a, v in rets.items()}
    if trace:
        q['trace'] = True
    if mmio_fixed:
        q['mmio_fixed'] = {str(a): v for a, v in mmio_fixed.items()}
    r = eng.send(q)
    r['diff'] = [norm_stack_ptrs(a, h) for a, h in r.get('diff', [])]
    for c in r.get('calls', []):
        for i, w in enumerate(STUB_WIDTHS.get(c[0], ())):
            if 1 + i < len(c) and isinstance(c[1 + i], int):
                c[1 + i] &= (1 << (8 * w)) - 1
        k = 1 + STUB_BUF[c[0]] if c[0] in STUB_BUF else None
        if k is not None and k < len(c) and isinstance(c[k], int) and c[k] < STACK_TOP:
            c[k] = 'stack'
    return r


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
        global _IMG
        self.img = _IMG = Image()
        self.orig = Originals()
        self.eng = None
        self.work = tempfile.mkdtemp(prefix='work_', dir=scratch_root())
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
        # JMP, FTOI, ROUND and FTOU are executed by EquivMainEmu.java itself (rounds 1 and 4)
        unverified = sorted(new_forms(path) - main_forms(self.img) - {'jmp r', 'ftoi r, r', 'round r, r', 'ftou r, r'})
        note = f'; instruction forms the MAIN image does not use (semantics not checked by T22a): {", ".join(unverified)}' \
            if unverified else ''
        eng = self.engine()
        eng.send({'op': 'base', 'name': 'new', 'segs': [[a, d.hex()] for a, d in lk.segs]})
        meta = self.blocks([oaddr])[oaddr]
        lead, isr = set(meta['blocks']), meta['isr']
        stubs = {self.orig.addr(n): n for n in STUBS if self.orig.addr(n) and n != fname}
        rets = {self.orig.addr(n): v for n, v in FUNC_STUBS.get(fname, {}).items() if self.orig.addr(n)}
        stubs.update({a: n for n, a in ((n, self.orig.addr(n)) for n in FUNC_STUBS.get(fname, {})) if a})
        rng = random.Random(seed)
        seen_reads = set()
        reached, ok, inconclusive = set(), 0, 0
        global _TRIAL
        for t in range(trials * FUNC_TRIALS.get(fname, 1)):
            _TRIAL = t
            regs, loads = draw_args(rng, lk.params)
            fill = fill_globals(rng, seen_reads)
            pre = PRESETS.get(fname) or (cat_handler_args if CAT_HANDLER.match(fname) else None)
            mfix = None
            if pre:
                extra, mfix = pre(rng, regs)
                loads = loads + extra
            loads = fill + loads
            s = rng.getrandbits(31)
            for budget in (BUDGET, 8 * BUDGET):
                r1 = run(eng, ['image', 'ram'], oaddr, regs, loads, s, budget, stubs, lead, isr, mfix, rets=rets)
                r2 = run(eng, ['image', 'ram', 'new'], lk.entry, regs, loads, s, budget, stubs, (), isr, mfix, rets=rets)
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
        trials *= FUNC_TRIALS.get(fname, 1)
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
        shutil.rmtree(self.work, ignore_errors=True)


_CHK = None


def _init_worker():
    global _CHK
    _CHK = Checker()
    import multiprocessing.util
    atexit.register(_CHK.close)
    # pool workers leave through os._exit, which skips atexit; multiprocessing runs its own finalizers first
    multiprocessing.util.Finalize(_CHK, _CHK.close, exitpriority=10)


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
    scratch_root()            # made before the pool forks, so the workers share it and the owner removes it
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
        pool.close()        # not terminate(): the workers must run their finalizers (Ghidra, temporary copies)
    except BaseException:
        pool.terminate()
        raise
    pool.join()


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
    allf = recreated()
    want = set(args.functions or ())
    part = bool(want or args.object)
    jobs = [(p, f, args.seed, args.trials) for p, f in allf
            if not part or f in want or any(p.endswith(o) for o in args.object or ())]
    results = {}
    if part:
        # a partial run (T24 MAIN round 4: a full run takes about an hour): the other rows of status.tsv stay, as long
        # as their function is still defined in the same object
        rerun = {f for _, f, _, _ in jobs}
        have = {(os.path.relpath(p, OBJDIR), f) for p, f in allf}
        for r in read_tsv(STATUS_TSV)[1:] if os.path.exists(STATUS_TSV) else ():
            a, g, _, src, rel, v, _, d = (r + [''] * 8)[:8]
            if not src or src in rerun or (rel, src) not in have:
                continue
            key = ('-', src) if g == '-' and int(a, 16) == 0 else int(a, 16)
            results[key] = (src, rel, v, d)
    for path, fname, a, v, d in sorted(run_jobs(jobs, args.jobs or 2), key=lambda x: (x[0], x[1])):
        print(f'equiv_main_emu: {fname:32s} {v}: {d}', file=sys.stderr)
        rel = os.path.relpath(path, OBJDIR)
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
    st = sub.add_parser('status', help='every recreated function -> status.tsv; with FUNCTION... or --object only '
                                       'those are rerun and the other rows are kept')
    st.add_argument('functions', nargs='*')
    st.add_argument('--object', action='append', help='rerun every function of this object (e.g. app/keyer.o)')
    for p in (c, st):
        p.add_argument('--trials', type=int, default=200)
        p.add_argument('--seed', type=int, default=1)
        p.add_argument('--jobs', type=int, default=0, help='Ghidra workers (default: check 1, status 2)')
    args = ap.parse_args()
    {'check': cmd_check, 'status': cmd_status}[args.cmd](args)


if __name__ == '__main__':
    main()
