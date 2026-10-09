#!/usr/bin/env python3
"""Carve the HiFi4 (Xtensa) DSP images out of the decoded IFDSP image.

Usage: python3 -I tools/ifdsp_dsp_images.py build/FT-710_IFDSP_V0101.bin [outdir]

The Cortex-M33 DSP loader (FUN_00084ad8 in the FT710_IFDSP Ghidra project, NXP SDK
DSP_CopyImage pattern) copies three images back to back from flash; their sizes are the three
words at file offset 0x5D41C, right before the .data load image. Destinations are from the loader.
Writes <outdir>/FT-710_IFDSP_V0101_hifi4.bin (all three images, contiguous, as in flash) and one
file per image, and prints a table. Default outdir: build/.
"""
import os
import struct
import sys

FLASH_BASE = 0x08000000
IMAGE0_OFF = 0x1844      # loader literal 0x08001844
SIZES_OFF = 0x5D41C      # dsp_image{0,1,2}_size
DATA_LMA = 0x5D428       # start of the M33 .data load image (copy table at 0x1130)
DESTS = [(0x24000000, "tcm"), (0x00200000, "sram_text"), (0x20040000, "sram_data")]


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    src = sys.argv[1]
    outdir = sys.argv[2] if len(sys.argv) > 2 else "build"
    d = open(src, "rb").read()
    sizes = struct.unpack_from("<3I", d, SIZES_OFF)
    off = IMAGE0_OFF
    rows = []
    for i, (size, (dst, name)) in enumerate(zip(sizes, DESTS)):
        rows.append((i, name, off, size, dst))
        off += size
    if off != SIZES_OFF or SIZES_OFF + 12 != DATA_LMA:
        sys.exit("layout check failed: images end at 0x%X, expected 0x%X" % (off, SIZES_OFF))
    base = os.path.splitext(os.path.basename(src))[0]
    os.makedirs(outdir, exist_ok=True)
    with open(os.path.join(outdir, base + "_hifi4.bin"), "wb") as f:
        f.write(d[IMAGE0_OFF:SIZES_OFF])
    print("img  name        file_off  flash_addr  size      dest")
    for i, name, o, size, dst in rows:
        with open(os.path.join(outdir, "%s_hifi4_%d_%s.bin" % (base, i, name)), "wb") as f:
            f.write(d[o:o + size])
        print("%d    %-10s  0x%06X  0x%08X  0x%06X  0x%08X..0x%08X"
              % (i, name, o, FLASH_BASE + o, size, dst, dst + size))


if __name__ == "__main__":
    main()
