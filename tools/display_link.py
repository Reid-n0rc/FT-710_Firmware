#!/usr/bin/env python3
"""T24 (DISPLAY): hybrid link of the recreated DISPLAY source into a complete image.

The recreated tree covers only part of the image, so it is linked *into* the original: src/display/display.ld puts
the original image (build/FT-710_DISPLAY_V0108.bin, as input section .image) at 0x20100000 unchanged and the
recreated functions that passed the check (src/display/status.tsv verdict "equivalent") into the gap
0x2042BC10..0x2043FFFF, which reset_in_ram already copies from flash. Every symbol the recreated code uses that
is not one of those functions resolves to the image's own address (weak absolute symbols generated from
decomp/display/functions.tsv, src/display/aliases.tsv and src/display/data_symbols.tsv). Recreated functions that
did not pass, and the byte-identical ones (their bytes are already in the image), are made undefined in a copy of
their object, so that calls to them go to the original. Then each linked function's original entry is patched with a
branch to its recreation (A32: B; Thumb: LDR.W PC, [PC, #imm] with the address after it), so that the image's
own callers, function pointers and vector tables reach the recreated code.

Output (src/display/out/, never committed: it contains the image): display_hybrid.elf, display_hybrid.map,
FT-710_DISPLAY_hybrid.bin (the bytes from 0x20100000), patches.tsv (address, function, target, kind). Nothing here
has been run on a radio.

Usage: python3 -I tools/display_link.py [--cross PREFIX]      (after `make -C src/display`)
"""
import argparse
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
GAP_END = 0x20440000
IDENT = re.compile(r'^[A-Za-z_][A-Za-z0-9_$]*$')


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


def undefine(path, out, names):
    """Copy an ELF32 object, making the given global symbols undefined (references to them stay, and then resolve
    to the image's addresses)."""
    data = bytearray(open(path, 'rb').read())
    shoff, = struct.unpack_from('<I', data, 0x20)
    shentsize, shnum = struct.unpack_from('<HH', data, 0x2E)
    secs = [struct.unpack_from('<10I', data, shoff + i * shentsize) for i in range(shnum)]
    done = 0
    for sh in secs:
        if sh[1] != 2:          # SHT_SYMTAB
            continue
        strtab = secs[sh[6]]
        for k in range(sh[5] // 16):
            off = sh[4] + 16 * k
            st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from('<IIIBBH', data, off)
            end = data.index(0, strtab[4] + st_name)
            name = data[strtab[4] + st_name:end].decode()
            if name in names and st_shndx != 0 and st_info >> 4 == 1:
                struct.pack_into('<IIIBBH', data, off, st_name, 0, 0, (1 << 4) | 0, st_other, 0)
                done += 1
    open(out, 'wb').write(data)
    return done


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


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--cross', default=os.environ.get('CROSS', 'arm-none-eabi-'))
    args = ap.parse_args()
    funcs, alias, data = originals()
    linked, ident, other = status()
    os.makedirs(LINK, exist_ok=True)
    objs = sorted(glob.glob(os.path.join(OUT, 'obj', '**', '*.o'), recursive=True))
    if not objs:
        sys.exit('display_link: no objects in src/display/out/obj (run make first)')
    import equiv_m33 as E
    defined, link_objs, roots = set(), [], []
    for p in objs:
        o = E.Obj(p)
        names = {n for n, _, _, _ in o.functions()}
        drop = {n for n in names if n not in linked and '.' not in n}
        q = os.path.join(LINK, os.path.relpath(p, os.path.join(OUT, 'obj')).replace('/', '_'))
        undefine(p, q, drop)
        link_objs.append(q)
        keep = names - drop
        defined |= keep
        roots += sorted(n for n in keep if '.' not in n)
    with open(os.path.join(LINK, 'orig.S'), 'w') as f:
        f.write(orig_asm(funcs, alias, data, defined))
    subprocess.run([args.cross + 'as', '-o', os.path.join(LINK, 'orig.o'), os.path.join(LINK, 'orig.S')], check=True)
    img = open(image_path(), 'rb').read()
    shutil.copyfile(image_path(), os.path.join(LINK, 'image.bin'))
    with open(os.path.join(LINK, 'image.S'), 'w') as f:
        f.write('@ generated: the original image as one input section\n.section .image,"ax",%progbits\n'
                '.incbin "image.bin"\n')
    subprocess.run([args.cross + 'as', '-o', 'image.o', 'image.S'], check=True, cwd=LINK)
    with open(os.path.join(LINK, 'roots.ld'), 'w') as f:
        f.write('/* generated: the linked recreated functions are GC roots */\n')
        f.write(''.join(f'EXTERN({n})\n' for n in roots))
    elf = os.path.join(OUT, 'display_hybrid.elf')
    cmd = [args.cross + 'ld', '-T', os.path.join(SRC, 'display.ld'), '-T', os.path.join(LINK, 'roots.ld'),
           '--gc-sections', '-Map', os.path.join(OUT, 'display_hybrid.map'), '-o', elf,
           os.path.join(LINK, 'image.o'), os.path.join(LINK, 'orig.o')] + link_objs
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        sys.exit('display_link: ld failed:\n' + r.stderr[-4000:])
    syms = {}
    nm = subprocess.run([args.cross + 'nm', elf], capture_output=True, text=True, check=True).stdout
    for ln in nm.split('\n'):
        f = ln.split()
        if len(f) == 3:
            syms[f[2]] = int(f[0], 16)
    binf = os.path.join(OUT, 'FT-710_DISPLAY_hybrid.bin')
    subprocess.run([args.cross + 'objcopy', '-O', 'binary', '--only-section=.image', '--only-section=.recreated',
                    elf, binf], check=True)
    out = bytearray(open(binf, 'rb').read())
    if bytes(out[:len(img)]) != img:
        sys.exit('display_link: the linked .image differs from the original image')
    end = syms.get('__recreated_end', BASE + len(out))
    rows, skipped = [], []
    for n in roots:
        o = alias.get(n) or funcs.get(n)
        if o is None:
            skipped.append((n, 'no original address'))
            continue
        a, thumb, size = o
        t = syms[n]
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
    open(binf, 'wb').write(out)
    with open(os.path.join(OUT, 'patches.tsv'), 'w') as f:
        f.write('address\tfunction\ttarget\tkind\n')
        for a, n, t, k in sorted(rows):
            f.write(f'{a:08x}\t{n}\t{t:08x}\t{k}\n')
        for n, why in skipped:
            f.write(f'-\t{n}\t-\tnot patched: {why}\n')
    used = end - 0x2042BC10
    changed = sum(1 for i in range(len(img)) if out[i] != img[i])
    print(f'display_link: {len(roots)} recreated functions linked at 0x2042BC10..{end:#x} ({used} of '
          f'{GAP_END - 0x2042BC10} bytes of the gap), {len(rows)} original entries patched ({changed} bytes changed), '
          f'{len(skipped)} not patched; {len(ident)} byte-identical functions left as they are; '
          f'{len(other)} recreated functions not linked (not verified). Wrote {os.path.relpath(binf, ROOT)} '
          f'({len(out)} bytes), display_hybrid.elf, .map, patches.tsv')
    if end > GAP_END:
        sys.exit('display_link: the recreated code does not fit into the gap')


if __name__ == '__main__':
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main()
