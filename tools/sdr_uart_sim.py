#!/usr/bin/env python3
"""Drive the Verilator model of the whole recovered SDR netlist with MAIN-style UART frames (T15e).

Written for T15e (FT-710 SDR FPGA). Stdlib only. Runs build/sdr/vl/obj_full/Vft710_sdr (built by
hdl/sdr/sim/build_full.sh from the derived netlist; nothing derived is committed) and prints each reply.

Usage:
    python3 -I tools/sdr_uart_sim.py [--bin PATH] [--gap BITS] LINE:FRAME [LINE:FRAME ...]
        LINE is a or b. FRAME is
          rAAAA        read frame, checksum and CR added   (MAIN: r + 4 hex + 2 hex sum + CR)
          wAAAAVVVV    write frame, checksum and CR added
          =TEXT        TEXT sent as is (C escapes \\r \\n \\b \\xHH)
        Frames are sent one after another with GAP bit times (default 300) of idle in between.
    python3 -I tools/sdr_uart_sim.py selftest
"""
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DEF_BIN = os.path.join(HERE, "..", "build", "sdr", "vl", "obj_full", "Vft710_sdr")
if not os.path.exists(DEF_BIN):
    DEF_BIN = "/workspace/FT-710_Firmware/build/sdr/vl/obj_full/Vft710_sdr"


def sum8hex(s):
    return "%02X" % (sum(s.encode("latin-1")) & 0xFF)


def frame(f):
    if f.startswith("="):
        return f[1:]
    if re.fullmatch(r"[a-z][0-9A-Fa-f]*", f):
        return f + sum8hex(f) + "\\r"
    raise ValueError("bad frame %r" % f)


def run(args, binpath=DEF_BIN, gap=300):
    argv = [binpath, "w:100"]      # let the console banner/prompt (UART A, ~55k clocks after reset) finish
    for a in args:
        line, f = a.split(":", 1)
        if line in ("s", "w"):            # probe snapshot clock / extra idle: passed through
            argv.append(a)
            continue
        argv.append("%s:%s" % (line, frame(f)))
        argv.append("w:%d" % gap)
    out = subprocess.run(argv, capture_output=True, text=True, timeout=3600).stdout
    return out


def group(out):
    """Group TX bytes per line into bursts (bytes closer than 30 bit times)."""
    bursts = {"A": [], "B": []}
    last = {"A": -10**9, "B": -10**9}
    for ln in out.splitlines():
        m = re.match(r"\s*(\d+) ([AB]) TX ([0-9A-F]{2})", ln)
        if not m:
            continue
        t, l, b = int(m.group(1)), m.group(2), int(m.group(3), 16)
        if t - last[l] > 30 * 1086:
            bursts[l].append((t, []))
        bursts[l][-1][1].append(b)
        last[l] = t
    return bursts


def show(b):
    return "".join(chr(x) if 32 <= x < 127 else "<%02X>" % x for x in b)


def selftest():
    assert frame("r0000") == "r000032\\r"
    assert sum8hex("w0037BCC5") == "%02X" % (sum(b"w0037BCC5") & 0xFF)
    print("selftest OK")


def main():
    a = sys.argv[1:]
    if a and a[0] == "selftest":
        return selftest()
    binpath, gap = DEF_BIN, 300
    while a and a[0].startswith("--"):
        if a[0] == "--bin":
            binpath = a[1]; a = a[2:]
        elif a[0] == "--gap":
            gap = int(a[1]); a = a[2:]
        elif a[0] == "--raw":
            print(run(a[1:], binpath, gap)); return
        else:
            sys.exit(__doc__)
    out = run(a, binpath, gap)
    for l, bl in group(out).items():
        for t, b in bl:
            print("%s @%9d  %2d bytes  %s   [%s]" % (l, t, len(b), show(b), " ".join("%02X" % x for x in b)))
    print(out.splitlines()[-1] if out else "(no output)")


if __name__ == "__main__":
    main()
