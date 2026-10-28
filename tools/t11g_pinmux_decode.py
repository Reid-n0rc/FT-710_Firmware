#!/usr/bin/env python3
"""T11g: decode DISPLAY pinmux_init (0x20101190) into a port/pin -> mode table.

Reads the decoded DISPLAY image, disassembles the given range with arm-none-eabi-objdump,
tracks the immediates loaded into r0-r3 before each BL to the per-pin helpers, and prints
one TSV row per call: port, pin, helper, function number, mode.

Usage: python3 -I tools/t11g_pinmux_decode.py build/FT-710_DISPLAY_V0108.bin [start end]
"""
import re
import subprocess
import sys

HELPERS = {
    0x2010087C: "input",          # PIBC=1 (port input, buffer on)
    0x20100414: "out_low",        # P=0, PM=0 (port output, low)
    0x20100838: "out_high",       # P=1, PM=0 (port output, high)
    0x20100658: "alt",            # PMC=1, alt function r2 via PFC/PFCE/PFCAE, r3 = I/O mode
    0x201003A0: "reset",          # PIBC/PBDC/PIPC/PMC=0, PM=1
}
MODES = {0: "PIPC (peripheral-controlled dir)", 1: "alt in (PM=1)", 2: "alt out (PM=0)", 3: "bidir (PBDC)"}


def main():
    img = sys.argv[1]
    start = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x20101190
    end = int(sys.argv[3], 0) if len(sys.argv) > 3 else 0x20101B60
    out = subprocess.run(
        ["arm-none-eabi-objdump", "-D", "-b", "binary", "-marm", "--adjust-vma=0x20100000",
         f"--start-address={start:#x}", f"--stop-address={end:#x}", img],
        capture_output=True, text=True, check=True).stdout
    regs = {}
    rx = re.compile(r"^\s*([0-9a-f]+):\s+[0-9a-f]+\s+(\w+)\s*(.*)$")
    print("addr\tport\tpin\thelper\tfunc\tmode")
    for line in out.splitlines():
        m = rx.match(line)
        if not m:
            continue
        addr, op, args = int(m.group(1), 16), m.group(2), m.group(3)
        if op == "mov":
            a = [x.strip() for x in args.split(",")]
            if a[1].startswith("#"):
                regs[a[0]] = int(a[1][1:], 0)
            elif a[1] in regs:
                regs[a[0]] = regs[a[1]]
            else:
                regs.pop(a[0], None)
        elif op == "bl":
            tgt = int(args.split()[0], 16)
            h = HELPERS.get(tgt, f"{tgt:#x}")
            r = [regs.get(f"r{i}") for i in range(4)]
            if h == "alt":
                print(f"{addr:#x}\t{r[0]}\t{r[1]}\t{h}\t{r[2]}\t{MODES.get(r[3], r[3])}")
            else:
                print(f"{addr:#x}\t{r[0]}\t{r[1]}\t{h}\t\t")
            for i in range(4):
                regs.pop(f"r{i}", None)
        elif op.startswith("pop") or op.startswith("b"):
            pass


if __name__ == "__main__":
    main()
