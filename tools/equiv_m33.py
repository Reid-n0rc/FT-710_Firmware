#!/usr/bin/env python3
"""T24: check recreated IFDSP M33 source against the original image, function by function.

Two checks, in this order:
  1. byte match, relocation aware: the function's section in the compiled object (-ffunction-sections) must equal the
     bytes at the function's original address, except for relocated fields; each relocated field must resolve to the
     original address of the same symbol (functions: decomp/ifdsp/m33/functions.tsv; data: src/ifdsp_m33/data_symbols.tsv,
     or learned from the first reference and then held to it; string and constant data: same bytes at the original
     address).
  2. differential emulation (Unicorn, Thumb-2): for a function that does not match byte for byte, the original function
     (from the image) and the recompiled one (linked to the original addresses of everything it references) are run on the
     same random register inputs and the same memory; return registers, every memory write and every peripheral access
     must agree. See tools/equiv_m33_emu.py.

Verdicts (status.tsv): identical, equivalent, differs, not yet (no recreated source for the function).

Usage:
  python3 -I tools/equiv_m33.py bytes OBJ...                  byte check of every function in the objects
  python3 -I tools/equiv_m33.py status [--build DIR] [--emu]  run both checks over src/ifdsp_m33 (built by its Makefile)
                                                              and write src/ifdsp_m33/status.tsv
The image is read from build/FT-710_IFDSP_V0101.bin (or $FT710_BUILD/...); it is never written anywhere.
"""
import argparse
import glob
import os
import struct
import sys

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FUNCS_TSV = os.path.join(ROOT, 'decomp/ifdsp/m33/functions.tsv')
SRC = os.path.join(ROOT, 'src/ifdsp_m33')
DATA_TSV = os.path.join(SRC, 'data_symbols.tsv')
ALIAS_TSV = os.path.join(SRC, 'aliases.tsv')

# M33 image layout (docs/code/ifdsp/m33-platform.md sections 1-2)
FLASH_BASE = 0x08000000
RAM_BASE, RAM_FILE_OFF, RAM_LEN = 0x00080000, 0x5D428, 0x7EC4

R_ARM_ABS32, R_ARM_REL32, R_ARM_THM_CALL, R_ARM_THM_JUMP24 = 2, 3, 10, 30
R_ARM_THM_JUMP19, R_ARM_THM_MOVW_ABS_NC, R_ARM_THM_MOVT_ABS = 51, 47, 48
R_ARM_V4BX, R_ARM_PREL31, R_ARM_NONE = 40, 42, 0


def image_path():
    for d in (os.environ.get('FT710_BUILD'), os.path.join(ROOT, 'build'), '/home/user/FT-710_Firmware/build'):
        if d and os.path.exists(os.path.join(d, 'FT-710_IFDSP_V0101.bin')):
            return os.path.join(d, 'FT-710_IFDSP_V0101.bin')
    sys.exit('equiv_m33: FT-710_IFDSP_V0101.bin not found (set FT710_BUILD to the build/ directory)')


class Image:
    """The original M33 memory: flash as stored, plus the SRAM copy made by ResetISR's data_init."""

    def __init__(self, path=None):
        self.flash = open(path or image_path(), 'rb').read()
        self.ram = self.flash[RAM_FILE_OFF:RAM_FILE_OFF + RAM_LEN]

    def read(self, addr, n):
        if RAM_BASE <= addr and addr + n <= RAM_BASE + RAM_LEN:
            return self.ram[addr - RAM_BASE:addr - RAM_BASE + n]
        if FLASH_BASE <= addr and addr + n <= FLASH_BASE + len(self.flash):
            return self.flash[addr - FLASH_BASE:addr - FLASH_BASE + n]
        return None

    def u32(self, addr):
        b = self.read(addr, 4)
        return None if b is None else struct.unpack('<I', b)[0]


def read_tsv(path):
    if not os.path.exists(path):
        return []
    with open(path, encoding='utf-8') as f:
        return [ln.rstrip('\n').split('\t') for ln in f if ln.strip() and not ln.startswith('#')]


def orig_functions():
    """name -> (addr, size) from the committed decomp export."""
    rows = read_tsv(FUNCS_TSV)
    return {r[1]: (int(r[0], 16), int(r[2])) for r in rows[1:]}


def aliases():
    """recreated-source name -> Ghidra name, where the two differ (src/ifdsp_m33/aliases.tsv)."""
    return {r[0]: r[1] for r in read_tsv(ALIAS_TSV)[1:]}


def data_symbols():
    return {r[0]: int(r[1], 16) for r in read_tsv(DATA_TSV)[1:]}


def sext(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def thumb_bl_target(pc, hw1, hw2):
    """Target of a Thumb-2 BL/BLX/B.W (T4) at pc; None if the halfwords are not one of them."""
    if (hw1 & 0xF800) != 0xF000 or (hw2 & 0xC000) != 0xC000 and (hw2 & 0xD000) != 0x9000:
        return None
    s = (hw1 >> 10) & 1
    j1, j2 = (hw2 >> 13) & 1, (hw2 >> 11) & 1
    i1, i2 = 1 - (j1 ^ s), 1 - (j2 ^ s)
    imm = (s << 24) | (i1 << 23) | (i2 << 22) | ((hw1 & 0x3FF) << 12) | ((hw2 & 0x7FF) << 1)
    t = pc + 4 + sext(imm, 25)
    if (hw2 & 0xD000) == 0xC000:  # BLX: to ARM, word aligned
        t &= ~3
    return t


def thumb_b_cond_target(pc, hw1, hw2):
    """Target of a Thumb-2 conditional B.W (T3)."""
    s = (hw1 >> 10) & 1
    j1, j2 = (hw2 >> 13) & 1, (hw2 >> 11) & 1
    imm = (s << 20) | (j2 << 19) | (j1 << 18) | ((hw1 & 0x3F) << 12) | ((hw2 & 0x7FF) << 1)
    return pc + 4 + sext(imm, 21)


def movw_imm(hw1, hw2):
    return ((hw1 & 0xF) << 12) | (((hw1 >> 10) & 1) << 11) | (((hw2 >> 12) & 7) << 8) | (hw2 & 0xFF)


class Obj:
    """One compiled object: its function sections, relocations and symbols."""

    def __init__(self, path):
        self.path = path
        f = open(path, 'rb')
        self.elf = ELFFile(f)
        self.secs = [s for s in self.elf.iter_sections()]
        self.symtab = self.elf.get_section_by_name('.symtab')
        self.syms = list(self.symtab.iter_symbols())
        self.relocs = {}
        for s in self.secs:
            if isinstance(s, RelocationSection):
                self.relocs[s['sh_info']] = list(s.iter_relocations())

    def functions(self):
        """(name, section index, offset, size) of every function defined in the object. Symbols that alias another
        function (same section and offset, e.g. the startup's weak X_DriverIRQHandler = IntDefaultHandler) are left
        out; aliases() lists them."""
        if not hasattr(self, '_funcs'):
            seen, self._funcs, self._alias, self.weak = {}, [], {}, set()
            for sym in self.syms:
                if sym['st_info']['type'] == 'STT_FUNC' and isinstance(sym['st_shndx'], int):
                    key = (sym['st_shndx'], sym['st_value'] & ~1)
                    if sym['st_info']['bind'] == 'STB_WEAK':
                        self.weak.add(sym.name)
                    if key in seen:
                        self._alias[sym.name] = seen[key]
                        continue
                    seen[key] = sym.name
                    self._funcs.append((sym.name, key[0], key[1], sym['st_size']))
        return self._funcs

    def aliases(self):
        self.functions()
        return self._alias

    def extent(self, shndx, off):
        """Bytes of the function at off: up to the next function in its section, or the section end (so a
        function's literal pool and padding belong to it). With -ffunction-sections that is the whole section,
        except for sections that hold several functions (section attributes such as CodeQuickAccess)."""
        nxt = [o for _, i, o, _ in self.functions() if i == shndx and o > off]
        return (min(nxt) if nxt else len(self.section_data(shndx))) - off

    def section_data(self, idx):
        s = self.secs[idx]
        return b'\0' * s['sh_size'] if s['sh_type'] == 'SHT_NOBITS' else s.data()

    def sym_info(self, i):
        sym = self.syms[i]
        typ = sym['st_info']['type']
        shndx = sym['st_shndx']
        sec = self.secs[shndx].name if isinstance(shndx, int) else None
        return sym.name, typ, sec, sym['st_value'], shndx


class Resolver:
    """Original addresses of the symbols a recompiled object refers to."""

    def __init__(self, img, funcs=None):
        self.img = img
        self.funcs = funcs or orig_functions()
        self.alias = aliases()
        self.data = data_symbols()
        self.weak_alias = {}  # weak alias with no strong definition -> the function it aliases
        self.located = {}   # function name -> address found by byte search (locate)
        self.learned = {}   # data symbol -> address learned from a literal of a byte-identical function
        self.pending = {}   # learned while checking the current function; kept only if its bytes match
        self.conflicts = []

    def func_addr(self, name):
        n = self.alias.get(name, name)
        if n == '-':
            return None
        if n.startswith('0x'):
            return int(n, 16)
        if n in self.funcs:
            return self.funcs[n][0]
        return self.located.get(name)

    def data_addr(self, key, value, where):
        if key in self.data:
            return self.data[key]
        if key in self.learned:
            return self.learned[key]
        return self.pending.setdefault(key, value)

    def veneer_ok(self, target, callee):
        """A call from flash reaches SRAM code through a GNU ld long-branch veneer (__<callee>_veneer)."""
        v = self.funcs.get(f'__{self.alias.get(callee, callee)}_veneer') or (
            self.funcs.get('call_main') if callee in ('main', '__main') else None)
        return v is not None and v[0] == target & ~1


def data_match(obj, shndx, start, n, addr, res):
    """Constant data (a .rodata section from start, n bytes) is at addr in the image. Pointers in it (relocations)
    must point to the original address of their function or to the same constant data."""
    ref = obj.section_data(shndx)
    got = res.img.read(addr, n)
    if got is None:
        return False
    mask = bytearray(len(ref))
    for r in obj.relocs.get(shndx, []):
        o = r['r_offset']
        if r['r_info_type'] != R_ARM_ABS32 or not start <= o < start + n:
            continue
        mask[o:o + 4] = b'\1' * 4
        ov = struct.unpack_from('<I', got, o - start)[0]
        name, styp, ssec, _, sshndx = obj.sym_info(r['r_info_sym'])
        addend = struct.unpack_from('<I', ref, o)[0]
        fn = name if styp != 'STT_SECTION' else section_function_name(obj, sshndx, addend & ~1)
        want = res.func_addr(res.weak_alias.get(fn, fn)) if fn else None
        if want is not None and (styp == 'STT_SECTION' or addend == 0):
            if (ov & ~1) != (want & ~1):
                return False
    return all(mask[k] or got[k - start] == ref[k] for k in range(start, start + n))


def section_function_name(obj, shndx, at=0):
    """The function at offset `at` of a section (for references through the section symbol)."""
    for name, idx, off, size in obj.functions():
        if idx == shndx and off == at:
            return name
    return None


def check_function(obj, res, fname, shndx, off, size, oaddr, osize):
    """Byte check of one function. Returns (verdict, detail)."""
    res.pending = {}
    data = obj.section_data(shndx)
    # the function's bytes are the whole section with -ffunction-sections (code + literal pool)
    body = data[off:off + obj.extent(shndx, off)]
    orig = res.img.read(oaddr, len(body))
    if orig is None:
        return 'differs', 'original address outside the image'
    relocs = [r for r in obj.relocs.get(shndx, []) if off <= r['r_offset'] < off + len(body)]
    mask = bytearray(len(body))
    problems = []
    for r in relocs:
        o = r['r_offset'] - off
        typ = r['r_info_type']
        name, styp, ssec, sval, sshndx = obj.sym_info(r['r_info_sym'])
        if typ in (R_ARM_NONE, R_ARM_V4BX):
            continue
        if typ in (R_ARM_THM_CALL, R_ARM_THM_JUMP24, R_ARM_THM_JUMP19):
            mask[o:o + 4] = b'\1' * 4
            hw1, hw2 = struct.unpack_from('<HH', orig, o)
            pc = oaddr + o
            t = thumb_b_cond_target(pc, hw1, hw2) if typ == R_ARM_THM_JUMP19 else thumb_bl_target(pc, hw1, hw2)
            if t is None:
                problems.append(f'+{o:#x} not a branch in the original')
                continue
            # the callee: a function symbol, or a section symbol of a .text.<fn> section
            callee = name if styp in ('STT_FUNC', 'STT_NOTYPE') else None
            callee = res.weak_alias.get(callee, callee)
            target_off = 0
            if styp == 'STT_SECTION':
                ib1, ib2 = struct.unpack_from('<HH', body, o)
                target_off = (thumb_bl_target(0, ib1, ib2) or 0) + 4  # implicit addend (REL) is target - 4
                callee = section_function_name(obj, sshndx, target_off)
                if callee is None and sshndx == shndx:  # call into the same section
                    want = oaddr - off + target_off
                    if t != want:
                        problems.append(f'+{o:#x} local call to {t:#x}, expected {want:#x}')
                    continue
            want = res.func_addr(callee) if callee else None
            if want is None:
                problems.append(f'+{o:#x} call to {callee or name}: no original address')
            elif t & ~1 != want & ~1 and not res.veneer_ok(t, callee):
                problems.append(f'+{o:#x} calls {t:#x}, {callee} is at {want:#x}')
            continue
        if typ == R_ARM_ABS32:
            mask[o:o + 4] = b'\1' * 4
            ov = struct.unpack_from('<I', orig, o)[0]
            addend = struct.unpack_from('<I', body, o)[0]
            if styp == 'STT_FUNC' or (styp == 'STT_NOTYPE' and res.func_addr(name) is not None) or (styp == 'STT_SECTION' and ssec and ssec.startswith('.text')
                                      and section_function_name(obj, sshndx) and addend == 0):
                fn = name if styp != 'STT_SECTION' else section_function_name(obj, sshndx)
                want = res.func_addr(fn)
                if want is None:
                    problems.append(f'+{o:#x} literal &{fn}: no original address')
                elif (ov & ~1) != ((want + addend) & ~1):
                    problems.append(f'+{o:#x} literal {ov:#x}, &{fn} is {want:#x}')
                continue
            if styp == 'STT_SECTION' and ssec and (ssec.startswith('.rodata') or ssec.startswith('.text')):
                # constant data (strings, tables) or code in this object: compare the bytes it points to
                ref = obj.section_data(sshndx)
                if sshndx == shndx:
                    want = oaddr - off + addend
                    if ov != want:
                        problems.append(f'+{o:#x} literal {ov:#x}, expected {want:#x} (same section)')
                    continue
                n = min(len(ref) - addend, 64) if ssec.startswith('.rodata.str') else len(ref) - addend
                if ssec.startswith('.rodata.str'):
                    end = ref.find(b'\0', addend)
                    n = (end - addend + 1) if end >= 0 else n
                if not data_match(obj, sshndx, addend, n, ov, res):
                    problems.append(f'+{o:#x} literal {ov:#x}: bytes differ from {ssec}+{addend:#x}')
                else:
                    res.data_addr(f'{os.path.basename(obj.path)}:{ssec}', ov - addend, fname)
                continue
            # writable data: global object by name, or a section of static data
            key = name if styp != 'STT_SECTION' else f'{os.path.basename(obj.path)}:{ssec}'
            base = res.data_addr(key, (ov - addend) & 0xFFFFFFFF, fname)
            if (base + addend) & 0xFFFFFFFF != ov:
                problems.append(f'+{o:#x} literal {ov:#x}, {key} is at {base:#x}+{addend:#x}')
                res.conflicts.append((fname, key, ov, base))
            continue
        if typ in (R_ARM_THM_MOVW_ABS_NC, R_ARM_THM_MOVT_ABS):
            mask[o:o + 4] = b'\1' * 4
            problems.append(f'+{o:#x} movw/movt relocation not supported')
            continue
        problems.append(f'+{o:#x} relocation type {typ} not supported')
    diff = [i for i in range(len(body)) if not mask[i] and body[i] != orig[i]]
    if diff:
        problems.insert(0, f'{len(diff)} bytes differ, first at +{diff[0]:#x}')
    if not diff and not problems:
        res.learned.update(res.pending)
    if not problems:
        tail = '' if len(body) == osize else f' (size {len(body)}, Ghidra size {osize})'
        return 'identical', 'bytes and relocations match' + tail
    return 'differs', '; '.join(problems[:4])


def locate(obj, shndx, img, off=0):
    """Addresses where a function's bytes (at off in its section) occur in the image, relocated fields masked (for
    functions that Ghidra's list lacks, e.g. bodies it merged into a neighbour)."""
    n = obj.extent(shndx, off)
    body = obj.section_data(shndx)[off:off + n]
    mask = bytearray(len(body))
    for r in obj.relocs.get(shndx, []):
        o = r['r_offset'] - off
        if 0 <= o < len(body):
            mask[o:o + 4] = b'\1' * 4
    mask = mask[:len(body)]
    # anchor on the longest unmasked run
    best, start, i = (0, 0), None, 0
    for i in range(len(body) + 1):
        if i < len(body) and not mask[i]:
            start = i if start is None else start
        elif start is not None:
            best = max(best, (i - start, start))
            start = None
    n, s = best
    if n < 4 or len(body) < 16:
        return []
    hits = []
    for base, mem in ((RAM_BASE, img.ram), (FLASH_BASE, img.flash[:RAM_FILE_OFF])):  # not the flash copy of SRAM
        j = mem.find(body[s:s + n])
        while j >= 0:
            a = j - s
            if a >= 0 and a % 2 == 0 and a + len(body) <= len(mem) and all(
                    mask[k] or mem[a + k] == body[k] for k in range(len(body))):
                hits.append(base + a)
            j = mem.find(body[s:s + n], j + 1)
    return hits if len(hits) == 1 else []


def check_objects(paths, img=None, res=None):
    """Byte check of every function in the objects. A pre-pass finds the original address of functions whose name is
    not in Ghidra's list (bodies Ghidra merged into a neighbour, or named differently) by a masked byte search; then two
    passes: the first learns data-symbol addresses from functions whose bytes match, the second checks everything."""
    img = img or Image()
    res = res or Resolver(img)
    objs = [Obj(p) for p in paths]
    strong = {f[0] for o in objs for f in o.functions() if f[0] not in o.weak}
    for o in objs:
        o._funcs = [f for f in o.functions() if f[0] not in o.weak or f[0] not in strong]
        for a, c in o.aliases().items():
            if a not in strong:
                res.weak_alias[a] = c
    for obj in objs:
        for fname, shndx, off, size in obj.functions():
            if res.func_addr(fname) is None and res.alias.get(fname) != '-':
                hits = locate(obj, shndx, img, off)
                if hits:
                    res.located[fname] = hits[0]
    infer_neighbours(objs, res)
    _check_pass(objs, res)
    return _check_pass(objs, res) + check_veneers(res), res


VENEER = bytes.fromhex('01b4024884460 1bc6047 00bf'.replace(' ', ''))  # push {r0}; ldr r0,[pc,#8]; mov ip,r0; pop {r0}; bx ip; nop


def check_veneers(res):
    """GNU ld's long-branch veneers (flash -> SRAM): no source of their own, the linker makes them. One passes when it
    has ld's code and its literal is the original address of the function it is named after (call_main: __main)."""
    out = []
    for gname, (a, n) in res.funcs.items():
        if not (gname.startswith('__') and gname.endswith('_veneer')) and gname != 'call_main':
            continue
        target = '__main' if gname == 'call_main' else gname[2:-len('_veneer')]
        code, lit = res.img.read(a, 12), res.img.u32(a + 12)
        want = res.func_addr(target)
        if code != VENEER:
            out.append((gname, a, 16, 'differs', 'linker', 'not the GNU ld veneer code'))
        elif want is None:
            out.append((gname, a, 16, 'not yet', 'linker', f'veneer to {lit:#x}; {target} not recreated yet'))
        elif lit != (want | 1):
            out.append((gname, a, 16, 'differs', 'linker', f'veneer to {lit:#x}, {target} is at {want:#x}'))
        else:
            out.append((gname, a, 16, 'identical', 'linker', f'GNU ld long-branch veneer to {target}'))
    return out


def masked_match(obj, shndx, img, addr, res=None):
    """True if the section's bytes are at addr, relocated fields aside. A relocated branch must still be a branch of
    the same kind there, and must reach its callee when the callee's address is already known."""
    body = obj.section_data(shndx)
    mem = img.read(addr, len(body))
    if mem is None:
        return False
    mask = bytearray(len(body))
    for r in obj.relocs.get(shndx, []):
        o, typ = r['r_offset'], r['r_info_type']
        mask[o:o + 4] = b'\1' * 4
        if typ in (R_ARM_THM_CALL, R_ARM_THM_JUMP24):
            b1, b2 = struct.unpack_from('<HH', body, o)
            m1, m2 = struct.unpack_from('<HH', mem, o)
            if (b1 & 0xF800) != (m1 & 0xF800) or (b2 & 0xD000) != (m2 & 0xD000):
                return False
            if res is not None:
                name, styp, _, _, sshndx = obj.sym_info(r['r_info_sym'])
                callee = name if styp != 'STT_SECTION' else section_function_name(obj, sshndx)
                want = res.func_addr(res.weak_alias.get(callee, callee)) if callee else None
                if want is not None and thumb_bl_target(addr + o, m1, m2) not in (want & ~1, None):
                    return False
    return all(mask[k] or mem[k] == body[k] for k in range(len(body)))


def infer_neighbours(objs, res):
    """Place small functions that the byte search cannot place uniquely: the linker lays out the kept sections of one
    object in file order within each alignment class, so a function whose section starts where the previous kept
    section of its object (same alignment) ends, and whose bytes match there, is at that address."""
    for _ in range(4):
        changed = False
        for obj in objs:
            secs = []
            for fname, shndx, off, size in obj.functions():
                if off == 0:
                    sec = obj.secs[shndx]
                    secs.append((shndx, fname, sec['sh_addralign'], len(obj.section_data(shndx))))
            secs.sort()
            for align in {a for _, _, a, _ in secs}:
                cls = [x for x in secs if x[2] == align]
                for i, (shndx, fname, a, n) in enumerate(cls):
                    if res.func_addr(fname) is not None or res.alias.get(fname) == '-':
                        continue
                    # nearest placed neighbour on each side; sections in between were dropped by --gc-sections
                    prev = [k for k in range(i - 1, -1, -1) if res.func_addr(cls[k][1]) is not None][:1]
                    nxt = [k for k in range(i + 1, len(cls)) if res.func_addr(cls[k][1]) is not None][:1]
                    for j in prev + nxt:
                        nb = res.func_addr(cls[j][1])
                        if j < i:
                            cand = (nb + cls[j][3] + a - 1) & ~(a - 1)
                        else:
                            cand = (nb - n) & ~(a - 1)
                        claimed = {a for a, _ in res.funcs.values() if res.alias.get(fname) is None} | set(
                            res.located.values())
                        if cand in claimed:
                            continue
                        if masked_match(obj, shndx, res.img, cand, res):
                            res.located[fname] = cand
                            changed = True
                            break
        if not changed:
            break


def _check_pass(objs, res):
    out = []
    for obj in objs:
        ap = os.path.abspath(obj.path)
        base = os.path.relpath(ap, os.path.join(SRC, 'out', 'obj')) if ap.startswith(SRC) else os.path.basename(ap)
        for fname, shndx, off, size in obj.functions():
            oaddr = None if res.alias.get(fname) == '-' else res.func_addr(fname)
            if oaddr is None:
                out.append((fname, None, size, 'not in image', base, ''))
                continue
            gname = res.alias.get(fname, fname)
            osize = res.funcs[gname][1] if gname in res.funcs else size
            verdict, detail = check_function(obj, res, fname, shndx, off, size, oaddr, osize)
            if fname in res.located:
                detail += f' (found by byte search; not a function in decomp/ifdsp/m33/functions.tsv)'
            out.append((fname, oaddr, obj.extent(shndx, off), verdict, base, detail))
    return out


def cmd_bytes(args):
    rows, res = check_objects(args.objs)
    n = {}
    for fname, oaddr, size, verdict, obj, detail in rows:
        n[verdict] = n.get(verdict, 0) + 1
        if not args.quiet or verdict != 'identical':
            print(f"{oaddr or 0:08x}\t{fname}\t{size}\t{verdict}\t{obj}\t{detail}")
    print('#', ', '.join(f'{k} {v}' for k, v in sorted(n.items())), file=sys.stderr)


def cmd_diff(args):
    """Side-by-side disassembly of one function: recompiled (left) and original (right)."""
    import capstone
    img, res = Image(), None
    _, res = check_objects(args.objs, img)
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB | capstone.CS_MODE_MCLASS)
    for p in args.objs:
        obj = Obj(p)
        for fname, shndx, off, size in obj.functions():
            if fname != args.function:
                continue
            body = obj.section_data(shndx)
            oaddr = res.func_addr(fname)
            orig = img.read(oaddr, max(len(body), res.funcs.get(res.alias.get(fname, fname), (0, 0))[1]))
            relocs = {r['r_offset']: obj.sym_info(r['r_info_sym'])[0] or obj.sym_info(r['r_info_sym'])[2]
                      for r in obj.relocs.get(shndx, [])}
            left = [(i.address, f'{i.mnemonic} {i.op_str}') for i in md.disasm(body, 0)]
            right = [(i.address, f'{i.mnemonic} {i.op_str}') for i in md.disasm(orig, oaddr)]
            for k in range(max(len(left), len(right))):
                a = left[k] if k < len(left) else (0, '')
                b = right[k] if k < len(right) else (0, '')
                mark = ' ' if a[1].split(' ')[0] == b[1].split(' ')[0] else '*'
                rel = f'  <{relocs[a[0]]}>' if a[0] in relocs else ''
                print(f'{mark} {a[0]:4x} {a[1][:38]:38s} | {b[0]:x} {b[1][:38]}{rel}')


STATUS_TSV = os.path.join(SRC, 'status.tsv')
RANK = {'identical': 0, 'equivalent': 1, 'differs': 2, 'not yet': 3, 'not in image': 4}


def build_status(rows, emu=None):
    """One row per function of decomp/ifdsp/m33/functions.tsv (the denominator of the README's Re-implemented column),
    then one row per recreated function the list lacks. `covered` = bytes of the Ghidra function that lie inside
    recreated functions whose check passed (identical or equivalent)."""
    emu = emu or {}
    funcs = orig_functions()
    best = {}
    for fname, oaddr, size, verdict, obj, detail in rows:
        if oaddr is None:
            continue
        if verdict == 'differs' and (oaddr, fname) in emu:
            verdict, detail = emu[(oaddr, fname)]
        cur = best.get(oaddr)
        if cur is None or RANK[verdict] < RANK[cur[4]]:
            best[oaddr] = (oaddr, oaddr + size, fname, obj, verdict, detail)
    # a recreated function covers the original bytes from its address up to the next original function at most
    # (a longer recompiled body must not count as covering its neighbour)
    starts = sorted({a for a, _ in funcs.values()} | set(best))
    import bisect
    capped = []
    for c in sorted(best.values()):
        i = bisect.bisect_right(starts, c[0])
        # (an identical function's extent is exact, even where Ghidra put a function start inside it)
        end = min(c[1], starts[i]) if i < len(starts) and c[4] != 'identical' else c[1]
        capped.append((c[0], end) + c[2:])
    checked = capped
    out = []
    for gname, (a, n) in sorted(funcs.items(), key=lambda kv: kv[1][0]):
        over = [c for c in checked if c[0] < a + n and c[1] > a]
        ok = [c for c in over if c[4] in ('identical', 'equivalent')]
        covered = sum(min(c[1], a + n) - max(c[0], a) for c in ok)
        if not over:
            verdict, src, f, detail = 'not yet', '', '', ''
        else:
            verdict = max((c[4] for c in over), key=lambda v: RANK[v])
            src = ','.join(c[2] for c in over)
            f = ','.join(sorted({c[3] for c in over}))
            detail = '; '.join(c[5] for c in over if c[4] == verdict)
            if covered < n:
                detail = f'{covered} of {n} bytes covered; ' + detail
        out.append((a, gname, n, src, f, verdict, covered, detail[:300]))
    for c in checked:
        if not any(a <= c[0] < a + n for a, n in funcs.values()):
            out.append((c[0], '-', c[1] - c[0], c[2], c[3], c[4], 0, c[5][:300]))
    return sorted(out)


def write_status(table, path=STATUS_TSV):
    with open(path, 'w', encoding='utf-8') as f:
        f.write('# IFDSP M33: recreated source vs the original image, per function (T24). Generated by\n')
        f.write('# tools/equiv_m33.py status; do not edit. Rows with ghidra_name "-" are recreated functions that\n')
        f.write('# decomp/ifdsp/m33/functions.tsv lacks. covered = bytes of the Ghidra function inside recreated\n')
        f.write('# functions that passed (identical or equivalent); tools/readability_stats.py sums it.\n')
        f.write('address\tghidra_name\tsize\tsource\tfile\tverdict\tcovered\tdetail\n')
        for a, g, n, src, fl, v, cov, det in table:
            f.write(f'{a:08x}\t{g}\t{n}\t{src}\t{fl}\t{v}\t{cov}\t{det}\n')


def cmd_status(args):
    objs = sorted(glob.glob(os.path.join(args.objs, '**', '*.o'), recursive=True))
    if not objs:
        sys.exit(f'equiv_m33: no objects under {args.objs}; run make in src/ifdsp_m33 first')
    rows, res = check_objects(objs)
    emu = {}
    if args.emu:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import equiv_m33_emu
        emu = equiv_m33_emu.run(res, [r for r in rows if r[3] == 'differs'], seed=args.seed, trials=args.trials)
    table = build_status(rows, emu)
    write_status(table)
    listed = [r for r in table if r[1] != '-']
    tot = sum(r[2] for r in listed)
    cov = sum(r[6] for r in listed)
    cnt = {}
    for r in listed:
        cnt[r[5]] = cnt.get(r[5], 0) + 1
    print('equiv_m33: ' + ', '.join(f'{k} {v}' for k, v in sorted(cnt.items(), key=lambda kv: RANK[kv[0]])) +
          f' (of {len(listed)} Ghidra functions; {len(table) - len(listed)} more not in its list); '
          f're-implemented {cov} of {tot} bytes ({100.0 * cov / tot:.1f} %); wrote {os.path.relpath(STATUS_TSV, ROOT)}')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    b = sub.add_parser('bytes')
    b.add_argument('objs', nargs='+')
    b.add_argument('-q', '--quiet', action='store_true', help='print only functions that do not match')
    d = sub.add_parser('diff')
    d.add_argument('function')
    d.add_argument('objs', nargs='+')
    st = sub.add_parser('status')
    st.add_argument('--objs', default=os.path.join(SRC, 'out', 'obj'))
    st.add_argument('--emu', action='store_true', help='run the differential emulation on functions that differ')
    st.add_argument('--seed', type=int, default=1)
    st.add_argument('--trials', type=int, default=200)
    args = ap.parse_args()
    if args.cmd == 'status':
        cmd_status(args)
    elif args.cmd == 'bytes':
        cmd_bytes(args)
    elif args.cmd == 'diff':
        cmd_diff(args)


if __name__ == '__main__':
    main()
