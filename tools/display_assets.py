#!/usr/bin/env python3
"""List the GUI assets of the FT-710 DISPLAY image (T11e). Lists only; extracts nothing.

Usage:  python3 -I tools/display_assets.py build/FT-710_DISPLAY_V0108.bin [sprites|tables|fonts|strings|summary]
                [--render ADDR]   (ASCII preview of one sprite on stdout, for checking; nothing is written to disk)

Formats (docs/code/display/gui.md):
  * Run sprite (16 B descriptor): u16 width, u16 height, u32 nruns, u32 runs_ptr, u32 pix_ptr.
    runs = nruns x {u16 start, u16 count} (linear pixel index = y*width + x); pix = sum(count) RGB565 words, stored right after
    the run list (pix_ptr == runs_ptr + 4*nruns). Pixels not covered by a run are transparent (not written).
    Drawn by gui_draw_runs (0x201358D0). A variant with u32 {start, count} pairs (8 B per run) is drawn by 0x201359BC.
  * Sprite table: an array of pointers to run sprites (fonts are tables indexed by character - 0x20).
  * String table: an array of pointers to NUL-terminated ASCII strings.
The RW regions (.data, .data_nc, .data2) are LZ-compressed in the image (armcc __decompress); this tool unpacks them in memory
so pointer tables that live in RAM (for example the 10x15 hex font at 0x20803738) can be listed.
"""
import struct
import sys

BASE = 0x20100000
RODATA = (0x20165178, 0x204286A8)
REGION_TABLE = 0x204286A8


def lz(img, src, size):
    out = bytearray()
    p = src - BASE
    c = img[p]; p += 1
    while True:
        lit = c & 3
        if lit == 0:
            lit = img[p]; p += 1
        mlen = c >> 4
        if mlen == 0:
            mlen = img[p]; p += 1
        out += img[p:p + lit - 1]; p += lit - 1
        if mlen:
            off = img[p]; p += 1
            if (c & 0xC) == 0xC:
                off += img[p] << 8; p += 1
            else:
                off += (c & 0xC) << 6
            s = len(out) - off
            for i in range(mlen + 2):
                out.append(out[s + i])
        if len(out) >= size:
            break
        c = img[p]; p += 1
    return bytes(out[:size])


class Mem:
    def __init__(self, path):
        self.img = open(path, 'rb').read()
        self.regions = [(BASE, self.img)]
        for i in range(5):
            load, exe, size, handler = struct.unpack_from('<4I', self.img, REGION_TABLE - BASE + 16 * i)
            if handler == 0x20100BFC:  # __decompress
                self.regions.append((exe, lz(self.img, load, size)))

    def find(self, a, n=1):
        for base, data in self.regions:
            if base <= a and a + n <= base + len(data):
                return data, a - base
        return None, None

    def u16(self, a):
        d, o = self.find(a, 2)
        return None if d is None else struct.unpack_from('<H', d, o)[0]

    def u32(self, a):
        d, o = self.find(a, 4)
        return None if d is None else struct.unpack_from('<I', d, o)[0]

    def cstr(self, a, maxlen=200):
        d, o = self.find(a)
        if d is None:
            return None
        e = d.find(b'\0', o, o + maxlen)
        if e < 0:
            return None
        s = d[o:e]
        if not s or any(ch < 0x20 or ch > 0x7E for ch in s):
            return None
        return s.decode('ascii')

    def sprite(self, a):
        """Return (w, h, nruns, runs, pix, npix, variant) if a holds a run-sprite descriptor, else None."""
        d, o = self.find(a, 16)
        if d is None or a & 3:
            return None
        w, h, n, runs, pix = struct.unpack_from('<HHIII', d, o)
        if not (0 < w <= 800 and 0 < h <= 600 and 0 < n <= w * h):
            return None
        for step, fmt in ((4, '<HH'), (8, '<II')):
            if pix != runs + step * n:
                continue
            rd, ro = self.find(runs, step * n)
            if rd is None:
                continue
            total = 0; last = -1; ok = True
            for i in range(n):
                s, c = struct.unpack_from(fmt, rd, ro + step * i)
                if s < last or c == 0 or s + c > w * h:
                    ok = False; break
                last = s + c; total += c
            if ok and self.find(pix, 2 * total)[0] is not None:
                return w, h, n, runs, pix, total, step
        return None


def scan_sprites(m):
    found = {}
    for base, data in m.regions:
        lo, hi = (RODATA if base == BASE else (base, base + len(data)))
        for a in range(lo, hi - 16, 4):
            s = m.sprite(a)
            if s:
                found[a] = s
    return found


def scan_tables(m, sprites, min_len=2):
    """Arrays of >= min_len consecutive pointers to sprite descriptors (NULL entries allowed inside)."""
    tables = []
    for base, data in m.regions:
        lo, hi = (RODATA if base == BASE else (base, base + len(data)))
        a = lo
        while a < hi - 4:
            v = m.u32(a)
            if v in sprites:
                start = a; ents = []
                while a < hi - 4:
                    v = m.u32(a)
                    if v in sprites or (v == 0 and ents and m.u32(a + 4) in sprites):
                        ents.append(v); a += 4
                    else:
                        break
                if len([e for e in ents if e]) >= min_len:
                    tables.append((start, ents))
            else:
                a += 4
    return tables


def scan_strtables(m, min_len=3):
    def text(p):
        if not p or m.sprite(p):  # a sprite descriptor whose width byte happens to be printable
            return None
        s = m.cstr(p)
        return s if s and len(s) >= 2 else None
    tables = []
    for base, data in m.regions:
        lo, hi = (RODATA if base == BASE else (base, base + len(data)))
        a = lo
        while a < hi - 4:
            if text(m.u32(a) or 0):
                start = a; ents = []
                while a < hi - 4 and text(m.u32(a) or 0):
                    ents.append(text(m.u32(a))); a += 4
                if len(ents) >= min_len:
                    tables.append((start, ents))
            else:
                a += 4
    return tables


def region_name(a):
    if RODATA[0] <= a < RODATA[1]:
        return '.rodata'
    if 0x20450000 <= a < 0x20450290:
        return '.data'
    if 0x60500000 <= a < 0x605048A0:
        return '.data_nc'
    if 0x20800000 <= a < 0x20808BD0:
        return '.data2'
    return '?'


def render(m, a):
    s = m.sprite(a)
    if not s:
        print('no sprite at %#x' % a); return
    w, h, n, runs, pix, total, step = s
    grid = [[' '] * w for _ in range(h)]
    k = 0
    fmt = '<HH' if step == 4 else '<II'
    for i in range(n):
        st, c = struct.unpack(fmt, bytes(m.find(runs + step * i, step)[0][m.find(runs + step * i)[1]:][:step]))
        for j in range(c):
            px = m.u16(pix + 2 * k); k += 1
            r, g, b = px >> 11, (px >> 5) & 63, px & 31
            lum = (r * 2 + g + b * 2) / 190.0
            grid[(st + j) // w][(st + j) % w] = ' .:-=+*#%@'[min(9, int(lum * 9.99))]
    for row in grid:
        print(''.join(row))


def main():
    if len(sys.argv) < 2:
        print(__doc__); sys.exit(1)
    m = Mem(sys.argv[1])
    if '--render' in sys.argv:
        render(m, int(sys.argv[sys.argv.index('--render') + 1], 16)); return
    what = sys.argv[2] if len(sys.argv) > 2 else 'summary'
    sprites = scan_sprites(m)
    if what == 'sprites':
        print('addr\tregion\tw\th\truns\trun_bytes\tpixels\tpix_ptr')
        for a, (w, h, n, runs, pix, total, step) in sorted(sprites.items()):
            print('%#010x\t%s\t%d\t%d\t%d\t%d\t%d\t%#010x' % (a, region_name(a), w, h, n, step, total, pix))
        return
    tables = scan_tables(m, sprites)
    if what in ('tables', 'fonts'):
        print('table\tregion\tentries\tsizes (w x h of the entries)')
        for start, ents in tables:
            sizes = sorted(set('%dx%d' % sprites[e][:2] for e in ents if e))
            if what == 'fonts' and len(ents) < 10:
                continue
            print('%#010x\t%s\t%d\t%s' % (start, region_name(start), len(ents), ' '.join(sizes[:8]) + (' ...' if len(sizes) > 8 else '')))
        return
    if what == 'strings':
        for start, ents in scan_strtables(m):
            print('%#010x\t%s\t%d\t%s' % (start, region_name(start), len(ents), ' | '.join(ents[:6])[:150]))
        return
    pixbytes = sum(2 * s[5] for s in sprites.values())
    print('run sprites: %d (%d pixels, %.1f KB of pixel data)' % (len(sprites), pixbytes // 2, pixbytes / 1024))
    for r in ('.rodata', '.data', '.data_nc', '.data2'):
        print('  in %-8s %d' % (r, sum(1 for a in sprites if region_name(a) == r)))
    print('  u32-run variant: %d' % sum(1 for s in sprites.values() if s[6] == 8))
    print('  single-run (full rectangle): %d' % sum(1 for s in sprites.values() if s[2] == 1 and s[5] == s[0] * s[1]))
    print('sprite pointer tables (>=2 entries): %d' % len(tables))
    print('string pointer tables (>=3 entries): %d' % len(scan_strtables(m)))


if __name__ == '__main__':
    main()
