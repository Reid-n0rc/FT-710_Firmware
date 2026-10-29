#!/usr/bin/env python3
"""Decode the DISPLAY's `.data2` screen-layout words (#83).

The GUI places every widget at coordinates that live as initialised u16 words in `.data2` (0x208004A4-0x20800660 and
0x208026DC-0x20802D00), not as immediates. This tool joins the initial values (from the LZ-unpacked image, via
tools/display_assets.py) with the role each word plays in the decompiled draw calls (decomp/display/*.c):

    gui_draw_runs/gui_draw_runs32(fb, y, x, sprite)   fb_clear_rect(fb, y, x, w, h)    fb_fill_rect(fb, color, y, x, w, h)
    fb_fill_box(fb, y, x, w, h, color)               fb_fill_box_t(fb, y, x, h, w, color)
    fb_blit_raw(fb, y, x, src, w, h)                 fb_draw_frame / fb_draw_round_frame(fb, color, y, x, w, h, ...)
    gui_draw_text*(fb, str, y, x, pitch, font)       gui_draw_dec/hex*(fb, value, y, x, digits)

Usage:  python3 -I tools/display_layout.py build/FT-710_DISPLAY_V0108.bin [decomp/display] [--range LO HI] [--md]
Output: one line per word: address, initial value, functions, roles seen ("y", "x+0x2b4", ...). Read-only.
"""
import glob
import os
import re
import sys
from collections import defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import display_assets as da  # noqa: E402

ROLES = {
    'gui_draw_runs': {1: 'y', 2: 'x'},
    'gui_draw_runs32': {1: 'y', 2: 'x'},
    'fb_clear_rect': {1: 'y', 2: 'x', 3: 'w', 4: 'h'},
    'fb_fill_rect': {2: 'y', 3: 'x', 4: 'w', 5: 'h'},
    'fb_fill_box': {1: 'y', 2: 'x', 3: 'w', 4: 'h'},
    'fb_fill_box_t': {1: 'y', 2: 'x', 3: 'h', 4: 'w'},
    'fb_blit_raw': {1: 'y', 2: 'x', 4: 'w', 5: 'h'},
    'fb_draw_frame': {2: 'y', 3: 'x', 4: 'w', 5: 'h'},
    'fb_draw_round_frame': {2: 'y', 3: 'x', 4: 'w', 5: 'h'},
    'gui_draw_text': {2: 'y', 3: 'x', 4: 'pitch'},
    'gui_draw_text_words': {2: 'y', 3: 'x', 4: 'pitch'},
    'gui_draw_text_centered': {2: 'y', 3: 'x(centre)', 4: 'pitch'},
    'gui_draw_dec': {2: 'y', 3: 'x'},
    'gui_draw_hex': {2: 'y', 3: 'x'},
    'gui_draw_hex_color': {2: 'y', 3: 'x'},
}
CALL = re.compile(r'\b(' + '|'.join(sorted(ROLES, key=len, reverse=True)) + r')\s*\(')
DAT = re.compile(r'DAT_(2080[0-9a-f]{4})')


def split_args(s, i):
    """s[i] is just after '('; return (list of arg strings, index after ')')."""
    depth, cur, args = 0, '', []
    while i < len(s):
        c = s[i]
        if c == '(':
            depth += 1
        elif c == ')':
            if depth == 0:
                args.append(cur.strip())
                return args, i + 1
            depth -= 1
        if c == ',' and depth == 0:
            args.append(cur.strip())
            cur = ''
        else:
            cur += c
        i += 1
    return args, i


def scan(decomp_dir, lo, hi):
    uses = defaultdict(set)    # addr -> {(func, role)}
    funcs = defaultdict(set)   # addr -> {func} (any reference)
    for path in sorted(glob.glob(os.path.join(decomp_dir, '*.c'))):
        text = open(path, errors='replace').read()
        # split into functions on the export headers
        parts = re.split(r'^// ===== (\S+) @ ', text, flags=re.M)
        for k in range(1, len(parts), 2):
            fn, body = parts[k], parts[k + 1]
            body1 = re.sub(r'\s+', ' ', body)
            for m in DAT.finditer(body1):
                a = int(m.group(1), 16)
                if lo <= a < hi:
                    funcs[a & ~1].add(fn)
            for m in CALL.finditer(body1):
                args, _ = split_args(body1, m.end())
                for pos, role in ROLES[m.group(1)].items():
                    if pos >= len(args):
                        continue
                    for d in DAT.finditer(args[pos]):
                        a = int(d.group(1), 16)
                        if lo <= a < hi:
                            rest = args[pos].replace(d.group(0), '').strip()
                            rest = re.sub(r'\(u?(int|short|ushort)\)', '', rest).strip()
                            uses[a & ~1].add((fn, role + (rest and ' ' + rest)))
    return uses, funcs


def main():
    a = sys.argv[1:]
    if not a:
        sys.exit(__doc__)
    img = a[0]
    ddir = a[1] if len(a) > 1 and not a[1].startswith('--') else 'decomp/display'
    ranges = [(0x208004A4, 0x20800660), (0x208026DC, 0x20802D00)]
    if '--range' in a:
        i = a.index('--range')
        ranges = [(int(a[i + 1], 16), int(a[i + 2], 16))]
    m = da.Mem(img)
    for lo, hi in ranges:
        uses, funcs = scan(ddir, lo, hi)
        for addr in range(lo, hi, 2):
            v = m.u16(addr)
            fs = sorted(funcs.get(addr, ()))
            roles = sorted({r for _, r in uses.get(addr, ())})
            print('%08X %6s  %-40s %s' % (addr, '-' if v is None else v, ' '.join(fs)[:40], '; '.join(roles)))


if __name__ == '__main__':
    main()
