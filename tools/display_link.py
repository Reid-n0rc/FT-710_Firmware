#!/usr/bin/env python3
"""T24 (DISPLAY): hybrid link of the recreated DISPLAY source into a complete image.

The recreated tree covers only part of the image, so it is linked *into* the original: src/display/display.ld puts
the original image (build/FT-710_DISPLAY_V0108.bin, as input section .image) at 0x20100000 unchanged, and each
recreated function that passed the check (src/display/status.tsv verdict "equivalent") goes to one of three places
(round 6, the plan of round 5 "the gap and the second region"):

1. **in place**, at its original address, when the GCC code fits into the original extent (the Ghidra function up to
   the next original function, the rule `covered` uses), the original is A32 (the GCC code is A32), and no code or
   literal outside that extent refers into it past its entry (a scan of the image's branches and literal words);
2. otherwise into the **gap** 0x2042BC10..0x2043FFFF, which reset_in_ram already copies from flash;
3. what does not fit there into **RAM2** 0x20920000..0x2097FFFF (ram_hi; the emulated boot of round 6,
   tools/display_boot_emu.py, saw no access to it). RAM2's bytes follow the gap in the file at offset 0x340000, and the
   hybrid then uses startup/vectors.S assembled with -DRAM2_LOAD (out/obj_ram2/): reset_in_ram copies them from
   flash to 0x20920000 after its own copy loops, in the slot its branched-over code leaves (vectors.S).

Every symbol the recreated code uses that is not one of those functions resolves to the image's own address (weak
absolute symbols generated from decomp/display/functions.tsv, src/display/aliases.tsv and data_symbols.tsv).
Recreated functions that did not pass, and the byte-identical ones (their bytes are already in the image), are made
undefined in a copy of their object, so that calls to them go to the original. A linked function that is not in
place gets its original entry patched with a branch to its recreation (A32: B; Thumb: LDR.W PC, [PC, #imm] with the
address after it), so that the image's own callers, function pointers and vector tables reach the recreated code.

**Function addresses as data** (round 6): where the recreated code takes the address of a linked recreated function
(R_ARM_ABS32, R_ARM_MOVW_ABS_NC, R_ARM_MOVT_ABS: a function pointer stored in a structure or a table, not a call),
the relocation is retargeted, in the object copy, to the function's original entry (with the Thumb bit of the
original). The image compares and stores such pointers as its own entries (round 5: vdc5_vline_cb_enable), the
entry forwards to the recreation, and it is also what the per-function check does (equiv_display_emu.py resolves
every symbol to the original).

Output (src/display/out/, never committed: it contains the image): display_hybrid.elf, display_hybrid.map,
FT-710_DISPLAY_hybrid.bin (the bytes from 0x20100000; with RAM2, its bytes from file offset 0x340000), patches.tsv
(address, function, target, kind: arm b / arm ldr pc / thumb ldr.w pc / in place). Nothing here has been run on a
radio.

Usage: python3 -I tools/display_link.py [--cross PREFIX] [--no-inplace] [--gap-limit BYTES]   (after make)
"""
import argparse
import bisect
import glob
import os
import re
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, 'src/display')
OUT = os.path.join(SRC, 'out')
LINK = os.path.join(OUT, 'link')
BASE = 0x20100000
TEXT_END = 0x20165178               # end of .text (display.ld)
FILE_END = 0x2042BC10               # end of the image file = start of the gap
GAP_END = 0x20440000                # reset_in_ram copies up to 0x2043FFFF
RAM2, RAM2_END = 0x20920000, 0x20980000
RAM2_FILE_OFF = GAP_END - BASE      # 0x340000: RAM2's bytes in the hybrid file (vectors.S, RAM2_LOAD)
IDENT = re.compile(r'^[A-Za-z_][A-Za-z0-9_$]*$')
R_ARM_ABS32, R_ARM_MOVW_ABS_NC, R_ARM_MOVT_ABS = 2, 43, 44
ADDR_RELOCS = {R_ARM_ABS32, R_ARM_MOVW_ABS_NC, R_ARM_MOVT_ABS}


def read_tsv(path):
    with open(path, encoding='utf-8') as f:
        return [ln.rstrip('\n').split('\t') for ln in f if ln.strip() and not ln.startswith('#')]


def image_path():
    for d in (os.environ.get('FT710_BUILD'), os.path.join(ROOT, 'build'), '/home/user/FT-710_Firmware/build'):
        if d and os.path.exists(os.path.join(d, 'FT-710_DISPLAY_V0108.bin')):
            return os.path.join(d, 'FT-710_DISPLAY_V0108.bin')
    sys.exit('display_link: FT-710_DISPLAY_V0108.bin not found (set FT710_BUILD to the build/ directory)')


def originals():
    """name -> (address, thumb, size) of the image's functions, plus the aliases and data symbols."""
    modes = {int(r[0], 16): r[3] == 'thumb' for r in read_tsv(os.path.join(SRC, 'modes.tsv'))[1:]}
    funcs = {}
    for r in read_tsv(os.path.join(ROOT, 'decomp/display/functions.tsv'))[1:]:
        a = int(r[0], 16)
        funcs.setdefault(r[1], (a, modes.get(a, False), int(r[2])))
    by_addr = {a: (n, t, s) for n, (a, t, s) in funcs.items()}
    alias = {}
    for r in read_tsv(os.path.join(SRC, 'aliases.tsv'))[1:]:
        src, orig = r[0], r[1]
        if orig == '-':
            continue
        if orig.startswith('0x'):
            a = int(orig, 16)
            alias[src] = (a, by_addr.get(a, (None, False, 0))[1], by_addr.get(a, (None, False, 0))[2])
        elif orig in funcs:
            alias[src] = funcs[orig]
    data = {r[0]: int(r[1], 16) for r in read_tsv(os.path.join(SRC, 'data_symbols.tsv'))[1:]}
    return funcs, alias, data


def status():
    """(linked, identical, other): recreated function names by verdict, from status.tsv."""
    linked, ident, other = set(), set(), set()
    for r in read_tsv(os.path.join(SRC, 'status.tsv'))[1:]:
        if len(r) < 6 or not r[3]:
            continue
        {'equivalent': linked, 'identical': ident}.get(r[5], other).add(r[3])
    return linked, ident, other


# --- ELF32 object editing (raw, little-endian)

def _sections(data):
    shoff, = struct.unpack_from('<I', data, 0x20)
    shentsize, shnum = struct.unpack_from('<HH', data, 0x2E)
    return [struct.unpack_from('<10I', data, shoff + i * shentsize) for i in range(shnum)]


def _symbols(data, secs):
    """[(offset of the entry, name, value, size, info, shndx)] of the .symtab."""
    out = []
    for sh in secs:
        if sh[1] != 2:          # SHT_SYMTAB
            continue
        strtab = secs[sh[6]]
        for k in range(sh[5] // 16):
            off = sh[4] + 16 * k
            st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from('<IIIBBH', data, off)
            end = data.index(0, strtab[4] + st_name)
            out.append((off, data[strtab[4] + st_name:end].decode(), st_value, st_size, st_info, st_shndx))
    return out


def undefine(data, names):
    """Make the given global symbols undefined (references to them stay, and then resolve to the image's
    addresses)."""
    done = 0
    for off, name, value, size, info, shndx in _symbols(data, _sections(data)):
        if name in names and shndx != 0 and info >> 4 == 1:
            struct.pack_into('<IIIBBH', data, off, struct.unpack_from('<I', data, off)[0], 0, 0, (1 << 4) | 0,
                             data[off + 13], 0)
            done += 1
    return done


def address_refs(data, entries):
    """Relocations that take the address of a function with an original entry (ABS32, MOVW/MOVT; not calls):
    [(reloc entry offset, function name)]. The target is a function symbol (global or local) or the section symbol
    of a function's own section (.text.<name>) with addend 0, the form gas gives references to local symbols."""
    secs = _sections(data)
    shstr = secs[struct.unpack_from('<H', data, 0x32)[0]]

    def secname(sh):
        return data[shstr[4] + sh[0]:data.index(0, shstr[4] + sh[0])].decode()
    syms = _symbols(data, secs)
    out = []
    for sh in secs:
        if sh[1] != 9:          # SHT_REL
            continue
        target = secs[sh[7]]
        if not target[2] & 2:   # SHF_ALLOC: not the debug sections
            continue
        for k in range(sh[5] // 8):
            off = sh[4] + 8 * k
            r_offset, r_info = struct.unpack_from('<II', data, off)
            typ, si = r_info & 0xFF, r_info >> 8
            if typ not in ADDR_RELOCS or si >= len(syms):
                continue
            _, name, value, size, info, shndx = syms[si]
            fn = None
            if info & 0xF == 2 or (shndx == 0 and info >> 4 in (1, 2)):  # a function, or an undefined global
                fn = name
            elif info & 0xF == 3 and 0 < shndx < len(secs):          # STT_SECTION
                sname = secname(secs[shndx])
                if sname.startswith('.text.'):
                    word = data[target[4] + r_offset:target[4] + r_offset + 4]
                    if typ == R_ARM_ABS32 and struct.unpack('<I', word)[0] == 0:
                        fn = sname[len('.text.'):]
            if fn in entries:
                out.append((off, fn))
    return out


def retarget(path, out, drop, entries):
    """Copy an object: drop = names to make undefined; every address-of reference to a function of `entries`
    (name -> original entry, Thumb bit included) goes to an absolute symbol __entry_<name> at that address."""
    data = bytearray(open(path, 'rb').read())
    refs = address_refs(data, entries)
    tmp = out + '.tmp'
    open(tmp, 'wb').write(data)
    if refs:
        cmd = [CROSS + 'objcopy']
        for fn in sorted({fn for _, fn in refs}):
            cmd += ['--add-symbol', f'__entry_{fn}={entries[fn]:#x},global']
        subprocess.run(cmd + [tmp, tmp], check=True)
        data = bytearray(open(tmp, 'rb').read())
        refs = address_refs(data, entries)        # objcopy renumbers the symbols: find the relocations again
        index = {name: k for k, (_, name, *_r) in enumerate(_symbols(data, _sections(data)))}
        for off, fn in refs:
            r_offset, r_info = struct.unpack_from('<II', data, off)
            struct.pack_into('<II', data, off, r_offset, (index[f'__entry_{fn}'] << 8) | (r_info & 0xFF))
    n = undefine(data, drop)
    open(out, 'wb').write(data)
    os.remove(tmp)
    return n, len(refs)


# --- the image: who refers into its code

def inbound_refs(img, thumb_ranges=()):
    """Targets in .text that code or data of the image refers to, with the referring address: A32 B/BL/BLX
    immediates, Thumb BL/BLX, and every aligned word whose value lies in .text (a conservative scan: data that only
    looks like a pointer also counts)."""
    refs = []
    n = len(img) // 4
    words = struct.unpack(f'<{n}I', img[:4 * n])
    for k, w in enumerate(words):
        a = BASE + 4 * k
        if BASE <= (w & ~1) < TEXT_END:
            refs.append((w & ~1, a))
        if a < TEXT_END and (w >> 25) & 7 == 5:
            d = ((w & 0xFFFFFF) ^ 0x800000) - 0x800000
            t = a + 8 + 4 * d + (2 if w >> 28 == 0xF and w & (1 << 24) else 0)
            if BASE <= t < TEXT_END:
                refs.append((t, a))
        if a < TEXT_END and w >> 28 != 0xF:
            # PC-relative loads (LDR/LDRB literal, LDRH/LDRD literal) and ADR: armcc's literal pools are shared by
            # neighbouring functions (seen in round 6: the unlisted function at 0x2013FE68 loads 0x20140118)
            t = None
            if w & 0x0E5F0000 == 0x041F0000:                       # LDR/LDRB (immediate, literal)
                t = a + 8 + ((w & 0xFFF) if w & (1 << 23) else -(w & 0xFFF))
            elif w & 0x0E5F0090 == 0x004F0090 and w & 0x60:          # LDRH/LDRSB/LDRSH/LDRD (literal)
                imm = (w >> 4) & 0xF0 | w & 0xF
                t = a + 8 + (imm if w & (1 << 23) else -imm)
            elif w & 0x0FFF0000 in (0x028F0000, 0x024F0000):          # ADR (add/sub rd, pc, #imm)
                rot = (w >> 8 & 0xF) * 2
                imm = ((w & 0xFF) >> rot | (w & 0xFF) << (32 - rot)) & 0xFFFFFFFF if rot else w & 0xFF
                t = a + 8 + (imm if w & 0x00800000 else -imm)
            elif w & 0x0F7F0F00 == 0x0D1F0B00:                       # VLDR (literal)
                t = a + 8 + (4 * (w & 0xFF) if w & (1 << 23) else -4 * (w & 0xFF))
            if t is not None and BASE <= t < TEXT_END:
                refs.append((t, a))
    for k in range(0, TEXT_END - BASE - 4, 2):
        hw1, hw2 = struct.unpack_from('<HH', img, k)
        if hw1 >> 11 == 0x1E and hw2 >> 14 == 3 and (hw2 >> 12) & 1 in (0, 1):
            s = (hw1 >> 10) & 1
            j1, j2 = (hw2 >> 13) & 1, (hw2 >> 11) & 1
            i1, i2 = 1 - (j1 ^ s), 1 - (j2 ^ s)
            d = (s << 24) | (i1 << 23) | (i2 << 22) | ((hw1 & 0x3FF) << 12) | ((hw2 & 0x7FF) << 1)
            d -= (1 << 25) if s else 0
            t = BASE + k + 4 + d
            if not (hw2 >> 12) & 1:
                t &= ~3
            if BASE <= t < TEXT_END:
                refs.append((t, BASE + k))
    for lo, hi in thumb_ranges:             # Thumb literal loads (LDR T1/T2, ADR T1) inside the Thumb functions
        for k in range(lo - BASE, hi - BASE - 1, 2):
            hw1, = struct.unpack_from('<H', img, k)
            pc4 = (BASE + k + 4) & ~3
            t = None
            if hw1 & 0xF800 in (0x4800, 0xA000):
                t = pc4 + 4 * (hw1 & 0xFF)
            elif hw1 & 0xFF7F == 0xF85F and k + 4 <= len(img):
                imm = struct.unpack_from('<H', img, k + 2)[0] & 0xFFF
                t = pc4 + (imm if hw1 & 0x80 else -imm)
            if t is not None and BASE <= t < TEXT_END:
                refs.append((t, BASE + k))
    refs.sort()
    return refs


FIRST_COPY_END = 0x20100BC0     # Reset_Handler's first copy: 0x20100000..0x20100BBF (vectors.S, L_20100238)


def calls_in(img, a, end, thumb):
    """Direct call and branch targets in [a, end) (A32 B/BL/BLX, Thumb BL/BLX)."""
    out = set()
    if not thumb:
        for k in range(a, end, 4):
            w, = struct.unpack_from('<I', img, k - BASE)
            if (w >> 25) & 7 == 5:
                d = ((w & 0xFFFFFF) ^ 0x800000) - 0x800000
                out.add(k + 8 + 4 * d + (2 if w >> 28 == 0xF and w & (1 << 24) else 0))
        return out
    for k in range(a, end - 2, 2):
        hw1, hw2 = struct.unpack_from('<HH', img, k - BASE)
        if hw1 >> 11 == 0x1E and hw2 >> 14 == 3:
            s_ = (hw1 >> 10) & 1
            i1, i2 = 1 - (((hw2 >> 13) & 1) ^ s_), 1 - (((hw2 >> 11) & 1) ^ s_)
            d = (s_ << 24) | (i1 << 23) | (i2 << 22) | ((hw1 & 0x3FF) << 12) | ((hw2 & 0x7FF) << 1)
            t = k + 4 + d - ((1 << 25) if s_ else 0)
            out.add(t if (hw2 >> 12) & 1 else t & ~3)
    return out


def boot_path(img, starts, by_addr):
    """(flash phase, RAM phase): names of the functions the reset path runs before reset_in_ram has copied the
    image, by the image's static call graph. Reset_Handler runs from the flash bank and calls its callees there
    (0x2010002C..0x20100047), before any copy: their code is read from flash, where the gap follows the image but
    RAM2 does not. reset_in_ram runs from RAM after the first copy (0x20100000..0x20100BBF) and calls
    spibsc0_init and boot_select_bank (0x20100080..0x20100093) before it copies the rest: those must run from the
    first copy. [fact: startup/vectors.S]"""
    modes = {int(r[0], 16): r[3] == 'thumb' for r in read_tsv(os.path.join(SRC, 'modes.tsv'))[1:]}

    def closure(roots):
        seen, todo = set(), list(roots)
        while todo:
            a = todo.pop()
            if a in seen or a not in by_addr:
                continue
            seen.add(a)
            end = starts[bisect.bisect_right(starts, a)]
            todo += [t for t in calls_in(img, a, end, modes.get(a, False)) if t in by_addr]
        return {by_addr[a] for a in seen}
    flash = closure(calls_in(img, 0x2010002C, 0x20100048, False))
    ram = closure(calls_in(img, 0x20100080, 0x20100098, False))
    return flash, ram


def orig_asm(funcs, alias, data, defined):
    """Weak absolute symbols for every original function, alias and data symbol not defined by a linked object."""
    lines = ['@ generated by tools/display_link.py: the image\'s own symbols (weak, absolute)', '.syntax unified']
    seen = set()

    def fn(name, a, thumb):
        if name in seen or name in defined or not IDENT.match(name):
            return
        seen.add(name)
        lines.append(f'.weak {name}\n.type {name}, %function\n.set {name}, {a | (1 if thumb else 0):#010x}')
    for name, (a, t, _) in alias.items():
        fn(name, a, t)
    for name, (a, t, _) in funcs.items():
        fn(name, a, t)
    for name, a in data.items():
        if name not in seen and name not in defined and IDENT.match(name):
            seen.add(name)
            lines.append(f'.weak {name}\n.set {name}, {a:#010x}')
    return '\n'.join(lines) + '\n'


def thumb_patch(at, target, room):
    """ldr.w pc, [pc, #imm] + the target word, at a Thumb entry; None if the function is too short."""
    lit = ((at + 4) & ~3)
    if lit < at + 4:
        lit += 4
    if lit + 4 - at > room:
        return None
    imm = lit - ((at + 4) & ~3)
    code = struct.pack('<HH', 0xF8DF, 0xF000 | imm)
    pad = b'\x00\xbf' * ((lit - (at + 4)) // 2)          # nop.n
    return code + pad + struct.pack('<I', target)


def link(args, link_objs, sections_ld):
    with open(os.path.join(LINK, 'sections.ld'), 'w') as f:
        f.write('/* generated by tools/display_link.py: in-place functions and RAM2 */\n' + sections_ld)
    elf = os.path.join(OUT, 'display_hybrid.elf')
    cmd = [CROSS + 'ld', '-L', LINK, '-T', os.path.join(SRC, 'display.ld'), '-T', os.path.join(LINK, 'roots.ld'),
           '--gc-sections', '--no-check-sections', '-Map', os.path.join(OUT, 'display_hybrid.map'), '-o', elf,
           os.path.join(LINK, 'image.o'), os.path.join(LINK, 'orig.o')] + link_objs
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        return None, r.stderr
    return elf, None


def elf_sections(elf):
    from elftools.elf.elffile import ELFFile
    with open(elf, 'rb') as f:
        e = ELFFile(f)
        secs = {s.name: (s['sh_addr'], s.data() if s['sh_type'] != 'SHT_NOBITS' else b'')
                for s in e.iter_sections() if s['sh_flags'] & 2}       # SHF_ALLOC
        syms = {}
        for s in e.get_section_by_name('.symtab').iter_symbols():
            syms.setdefault(s.name, s['st_value'])
        sizes = {s.name: s['st_size'] for s in e.get_section_by_name('.symtab').iter_symbols()
                 if s['st_info']['type'] == 'STT_FUNC'}
    return secs, syms, sizes


CROSS = 'arm-none-eabi-'


def main():
    global CROSS
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--cross', default=os.environ.get('CROSS', 'arm-none-eabi-'))
    ap.add_argument('--no-inplace', action='store_true', help='link every function into the gap or RAM2')
    ap.add_argument('--gap-limit', type=int, default=None, help='bytes of function code to put into the gap at most '
                    '(the rest goes to RAM2; default: as much as fits)')
    args = ap.parse_args()
    CROSS = args.cross
    funcs, alias, data = originals()
    linked, ident, other = status()
    os.makedirs(LINK, exist_ok=True)
    objs = sorted(glob.glob(os.path.join(OUT, 'obj', '**', '*.o'), recursive=True))
    if not objs:
        sys.exit('display_link: no objects in src/display/out/obj (run make first)')
    import equiv_m33 as E
    img = open(image_path(), 'rb').read()

    # the original entry (Thumb bit included) of every recreated function that will be linked
    def orig_of(n):
        return alias.get(n) or funcs.get(n)
    entries = {n: o[0] | (1 if o[1] else 0) for n in linked if (o := orig_of(n))}
    starts = sorted({a for a, _, _ in funcs.values()} | {a for a, _, _ in alias.values()} | {TEXT_END})
    modes = {int(r[0], 16): r[3] == 'thumb' for r in read_tsv(os.path.join(SRC, 'modes.tsv'))[1:]}
    refs = inbound_refs(img, [(a, starts[bisect.bisect_right(starts, a)]) for a, t in modes.items() if t])
    ref_t = [t for t, _ in refs]

    def extent(a):
        return starts[bisect.bisect_right(starts, a)] - a

    def foreign_ref_inside(a, e):
        lo, hi = bisect.bisect_right(ref_t, a), bisect.bisect_left(ref_t, a + e)
        return [(t, s) for t, s in refs[lo:hi] if not a <= s < a + e]

    # pass 1: the recreated functions that passed, their GCC sizes and sections
    cand, fsizes, sec_of = [], {}, {}
    for p in objs:
        o = E.Obj(p)
        for n, shndx, off, size in o.functions():
            if n in linked and '.' not in n:
                cand.append(n)
                fsizes[n] = o.extent(shndx, off)
                sec_of[n] = (p, o.secs[shndx].name, len([1 for m, i, _, _ in o.functions() if i == shndx]))

    # in place: fits, A32, nothing from outside refers into the extent past the entry
    inplace, why_not = {}, {}
    for n in cand:
        o = orig_of(n)
        if o is None:
            continue
        a, thumb, _ = o
        _, sec, nfun = sec_of[n]
        e = extent(a)
        if args.no_inplace:
            why_not[n] = 'disabled'
        elif thumb:
            why_not[n] = 'Thumb original'
        elif nfun != 1 or not sec.startswith('.text.'):
            why_not[n] = 'section holds more than the function'
        elif fsizes[n] > e:
            why_not[n] = f'{fsizes[n]} > {e} bytes'
        elif foreign_ref_inside(a, e):
            why_not[n] = 'referred to inside its extent'
        else:
            inplace[n] = (a, e)

    # the reset path: what runs before reset_in_ram has copied the image (boot_path)
    by_addr = {}
    for n, (a, t, _) in list(funcs.items()) + list(alias.items()):
        by_addr.setdefault(a, n)
    flash_phase, ram_phase = boot_path(img, starts, by_addr)
    held = {}
    for n in cand:
        if n in ram_phase and not (n in inplace and inplace[n][0] + inplace[n][1] <= FIRST_COPY_END):
            held[n] = 'runs before the gap is loaded (reset_in_ram), not in place in the first copy'
    # the image's callers that keep registers across a call of the function (equiv_display_emu.py abicheck)
    hz = os.path.join(OUT, 'abi_hazards.tsv')
    if not os.path.exists(hz):
        sys.exit('display_link: out/abi_hazards.tsv missing: run python3 -I tools/equiv_display_emu.py abicheck '
                 '(make link does)')
    # a caller that is itself linked no longer runs its original code (its entry is patched or overwritten), so
    # its hazard lapses (round 7: sdhi_error_reset recreated releases sdhi_soft_reset); to a fixed point, since a
    # caller held back for another reason runs as the original again
    src_at = {}
    for n in cand:
        o = orig_of(n)
        if o is not None:
            src_at[o[0]] = n
    hz_rows = [r for r in read_tsv(hz)[1:] if r[0] in cand]
    while True:
        new = {}
        for r in hz_rows:
            caller = src_at.get(funcs[r[1]][0]) if r[1] in funcs else None
            if r[0] not in held and (caller is None or caller in held):
                new.setdefault(r[0], f'{r[1]} reads {r[4]} after calling it ({r[2]}; abicheck)')
        if not new:
            break
        held.update(new)
    for n in held:
        inplace.pop(n, None)
    gap_only = {n for n in cand if n in flash_phase and n not in inplace}

    # pass 2: the object copies: what is not linked becomes undefined, address-of references go to the entries
    linked_now = set(cand) - set(held)
    entries = {n: e for n, e in entries.items() if n in linked_now}
    defined, link_objs, roots, where = set(), [], [], {}
    nref = 0
    for p in objs:
        o = E.Obj(p)
        names = {n for n, _, _, _ in o.functions()}
        drop = {n for n in names if n not in linked_now and '.' not in n}
        q = os.path.join(LINK, os.path.relpath(p, os.path.join(OUT, 'obj')).replace('/', '_'))
        nref += retarget(p, q, drop, entries)[1]
        link_objs.append(q)
        keep = names - drop
        defined |= keep
        for n in keep:
            if '.' not in n:
                roots.append(n)
                where[n] = (q,) + sec_of[n][1:]
    roots.sort()
    inplace = {n: (a, e, where[n][0], where[n][1]) for n, (a, e) in inplace.items()}
    with open(os.path.join(LINK, 'orig.S'), 'w') as f:
        f.write(orig_asm(funcs, alias, data, defined))
    subprocess.run([CROSS + 'as', '-o', os.path.join(LINK, 'orig.o'), os.path.join(LINK, 'orig.S')], check=True)
    shutil.copyfile(image_path(), os.path.join(LINK, 'image.bin'))
    with open(os.path.join(LINK, 'image.S'), 'w') as f:
        f.write('@ generated: the original image as one input section\n.section .image,"ax",%progbits\n'
                '.incbin "image.bin"\n')
    subprocess.run([CROSS + 'as', '-o', 'image.o', 'image.S'], check=True, cwd=LINK)
    with open(os.path.join(LINK, 'roots.ld'), 'w') as f:
        f.write('/* generated: the linked recreated functions are GC roots */\n')
        f.write(''.join(f'EXTERN({n})\n' for n in roots))

    # 2./3. the gap, then RAM2 (in address order of the originals, so that a file's functions stay together)
    rest = [n for n in roots if n not in inplace]
    # the functions of the flash phase first, so that they stay in the gap (RAM2 is not in flash where a
    # PC-relative branch from the flash copy would look for it)
    rest.sort(key=lambda n: (n not in gap_only, (orig_of(n) or (1 << 33,))[0]))
    limit = args.gap_limit
    for attempt in range(8):
        ram2, used = [], 0
        for n in rest:
            if limit is not None and used + fsizes[n] > limit and n not in gap_only:
                ram2.append(n)
            else:
                used += fsizes[n]
        ld = ''.join(f'    .inplace.{n} {a:#010x} : {{ KEEP({q}({sec})) }}\n' for n, (a, e, q, sec) in
                     sorted(inplace.items(), key=lambda kv: kv[1][0]))
        if ram2:
            ld += f'    .recreated2 {RAM2:#010x} : {{\n        __ram2_start = .;\n'
            ld += ''.join(f'        {where[n][0]}({where[n][1]})\n' for n in ram2)
            ld += '        . = ALIGN(32);\n        __ram2_end = .;\n    } > RAM2\n'
        else:
            ld += '    __ram2_start = 0x20920000;\n    __ram2_end = 0x20920000;\n'
        objs_now = list(link_objs)
        if ram2:
            v2 = glob.glob(os.path.join(OUT, 'obj_ram2', 'startup', 'vectors.o'))
            if not v2:
                sys.exit('display_link: RAM2 is needed but out/obj_ram2/startup/vectors.o is missing (make link builds it)')
            vq = os.path.join(LINK, 'vectors_ram2.o')
            shutil.copyfile(v2[0], vq)
            objs_now = [x for x in objs_now if not x.endswith('startup_vectors.o')] + [vq]
            ld = f'    .inplace.vectors {BASE:#010x} : {{ KEEP({vq}(.text.vectors)) }}\n' + ld
        elf, err = link(args, objs_now, ld)
        if elf:
            secs, syms, sizes = elf_sections(elf)
            end = syms.get('__recreated_end', FILE_END)
            if end <= GAP_END:
                break
            over = end - GAP_END
            limit = (used if limit is None else limit) - over - 256
            continue
        m = re.search(r"region `GAP' overflowed by (\d+) bytes", err or '')
        if not m:
            sys.exit('display_link: ld failed:\n' + err[-4000:])
        limit = (used if limit is None else limit) - int(m.group(1)) - 256
    else:
        sys.exit('display_link: the recreated code does not fit into the gap and RAM2')

    # the image file with the recreated code: the gap after the file, the in-place functions at their addresses,
    # RAM2 at file offset 0x340000
    out = bytearray(img)
    for name, (addr, blob) in secs.items():
        if name in ('.image', '.data', '.bss') or not blob:
            continue
        if name == '.recreated2':
            off = RAM2_FILE_OFF + addr - RAM2
        else:
            off = addr - BASE
        if len(out) < off + len(blob):
            out += bytes(off + len(blob) - len(out))
        out[off:off + len(blob)] = blob
    for n, (a, e, q, sec) in inplace.items():
        if syms[n] != a or sizes.get(n, 0) > e:
            sys.exit(f'display_link: {n} did not land in place at {a:#x}')
    # the reset path's RAM phase as linked: everything it calls must lie in the first copy
    for n in sorted(ram_phase & set(inplace)):
        a, e = inplace[n][0], sizes.get(n, 0)
        bad = [t for t in calls_in(out, a, a + e, False) if not BASE <= t < FIRST_COPY_END]
        if bad:
            sys.exit(f'display_link: {n} (reset path, before the gap is loaded) calls {", ".join(map(hex, bad))}')
    rows, skipped = [], []
    for n in roots:
        o = orig_of(n)
        if o is None:
            skipped.append((n, 'no original address'))
            continue
        a, thumb, size = o
        t = syms[n]
        if n in inplace:
            rows.append((a, n, t, 'in place'))
            continue
        if thumb:
            p = thumb_patch(a, t, size)
            kind = 'thumb ldr.w pc'
        elif t & 1:
            p = struct.pack('<II', 0xE51FF004, t) if size >= 8 else None     # ldr pc, [pc, #-4]
            kind = 'arm ldr pc'
        else:
            d = (t - (a + 8)) >> 2
            p = struct.pack('<I', 0xEA000000 | (d & 0xFFFFFF))
            kind = 'arm b'
        if p is None:
            skipped.append((n, f'original too short for the patch ({size} bytes)'))
            continue
        out[a - BASE:a - BASE + len(p)] = p
        rows.append((a, n, t, kind))
    binf = os.path.join(OUT, 'FT-710_DISPLAY_hybrid.bin')
    open(binf, 'wb').write(out)
    with open(os.path.join(OUT, 'patches.tsv'), 'w') as f:
        f.write('address\tfunction\ttarget\tkind\n')
        for a, n, t, k in sorted(rows):
            f.write(f'{a:08x}\t{n}\t{t:08x}\t{k}\n')
        for n, why in skipped:
            f.write(f'-\t{n}\t-\tnot patched: {why}\n')
    with open(os.path.join(OUT, 'placement.tsv'), 'w') as f:
        f.write('function\tplace\tgcc_bytes\toriginal_extent\treason\n')
        for n in sorted(cand):
            o = orig_of(n)
            pl = 'not linked' if n in held else 'in place' if n in inplace else 'ram2' if n in ram2 else 'gap'
            why = held.get(n) or why_not.get(n, '') + ('; flash phase of the reset path' if n in gap_only else '')
            f.write(f'{n}\t{pl}\t{fsizes[n]}\t{extent(o[0]) if o else "-"}\t{why.lstrip("; ")}\n')
    ram2_end = syms.get('__ram2_end', RAM2)
    changed = sum(1 for i in range(len(img)) if out[i] != img[i])
    used_gap = end - FILE_END
    print(f'display_link: {len(roots)} recreated functions linked: {len(inplace)} in place '
          f'({sum(fsizes[n] for n in inplace)} bytes), {len(rest) - len(ram2)} in the gap 0x2042BC10..{end:#x} '
          f'({used_gap} of {GAP_END - FILE_END} bytes), {len(ram2)} in RAM2 0x20920000..{ram2_end:#x} '
          f'({ram2_end - RAM2} of {RAM2_END - RAM2} bytes); {nref} function addresses taken as data resolved to '
          f'original entries; {sum(1 for r in rows if r[3] != "in place")} original entries patched ({changed} '
          f'bytes of the image changed), {len(skipped)} not patched; {len(ident)} byte-identical functions left as '
          f'they are; {len(other)} recreated functions not linked (not verified), {len(held)} held back (reset path or abicheck: '
          f'{", ".join(sorted(held)) or "none"}). Wrote {os.path.relpath(binf, ROOT)} '
          f'({len(out)} bytes), display_hybrid.elf, .map, patches.tsv, placement.tsv')


if __name__ == '__main__':
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main()
