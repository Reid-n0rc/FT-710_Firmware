#!/usr/bin/env python3
"""Compare the UART A console RTL (hdl/sdr/uart_console.v) with the whole recovered netlist, byte by byte (#147).

Written for #147 (FT-710 SDR FPGA). Stdlib only. Plays the same console lines into the Verilator model of the netlist
(tools/sdr_uart_sim.py, derived build in build/sdr/vl/) and into the RTL testbench (Icarus, hdl/sdr/tb_uart_console.v),
and compares the bytes each sends on UART A. Timing is not compared (the RTL is byte-level).

Usage:
    python3 -I tools/sdr_console_check.py [--bin NETLIST_BIN] [--jobs N] [--no-cache] LINES.txt
        One console line per text line (C escapes \\r \\n \\b \\xHH; CR is added; an empty line is an empty command).
        A line "---" starts a new group. Each group runs from reset, in its own netlist process (up to N at once,
        default 12; the model is single-threaded), so keep lines that depend on each other (a write and its
        read-back) in one group. Netlist bytes are cached per group in build/sdr/console_cache/, keyed on the
        group's lines and the netlist binary (size + mtime), so iterating on the RTL only re-runs Icarus.
        Prints both byte streams per group and PASS/FAIL.
"""
import concurrent.futures
import hashlib
import os
import re
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
HDL = os.path.join(REPO, "hdl", "sdr")
CACHE = os.path.join(REPO, "build", "sdr", "console_cache")
TXRE = re.compile(r"\d+ A TX ([0-9A-Fa-f]{2})")


def show(b):
    return "".join(chr(x) if 32 <= x < 127 else "<%02X>" % x for x in b)


def groups_of(text):
    lines = text.split("\n")
    if lines and lines[-1] == "":
        lines.pop()
    groups, cur = [], []
    for l in lines:
        if l.strip() == "---":
            if cur:
                groups.append(cur)
            cur = []
        else:
            cur.append(l)
    if cur:
        groups.append(cur)
    return groups


def netlist(group, binpath, use_cache):
    st = os.stat(binpath) if binpath and os.path.exists(binpath) else None
    key = hashlib.sha256(("\n".join(group) + "|%s|%s|%s" % (
        binpath, st.st_size if st else "", int(st.st_mtime) if st else "")).encode()).hexdigest()[:24]
    path = os.path.join(CACHE, key + ".txt")
    if use_cache and os.path.exists(path):
        return bytes.fromhex(open(path).read().strip())
    args = []
    for l in group:
        args += ["a:=" + l + "\\r", "w:400"]
    cmd = ["python3", "-I", os.path.join(HERE, "sdr_uart_sim.py"), "--gap", "40", "--raw"]
    if binpath:
        cmd[3:3] = ["--bin", binpath]
    p = subprocess.run(cmd + args, capture_output=True, text=True, timeout=7200)
    if p.returncode:
        raise RuntimeError("netlist run failed: " + p.stderr[-500:])
    out = bytes(int(m.group(1), 16) for m in TXRE.finditer(p.stdout))
    os.makedirs(CACHE, exist_ok=True)
    open(path, "w").write(out.hex() + "\n")
    return out


def rtl(groups):
    res = []
    with tempfile.TemporaryDirectory() as d:
        vvp = os.path.join(d, "tbc.vvp")
        subprocess.run(["iverilog", "-g2012", "-I", HDL, "-o", vvp] + [os.path.join(HDL, f) for f in (
            "tb_uart_console.v", "uart_console.v", "uart_rx.v", "uart_tx.v")], check=True)
        for i, g in enumerate(groups):
            lf = os.path.join(d, "g%d.txt" % i)
            open(lf, "w").write("\n".join(g) + "\n")
            out = subprocess.run(["vvp", "-n", vvp, "+lines=" + lf], capture_output=True, text=True,
                                 timeout=7200).stdout
            res.append(bytes(int(m.group(1), 16) for m in TXRE.finditer(out)))
    return res


def main():
    a = sys.argv[1:]
    binpath, jobs, use_cache = None, 12, True
    while a and a[0].startswith("--"):
        if a[0] == "--bin":
            binpath, a = a[1], a[2:]
        elif a[0] == "--jobs":
            jobs, a = int(a[1]), a[2:]
        elif a[0] == "--no-cache":
            use_cache, a = False, a[1:]
        else:
            sys.exit(__doc__)
    if len(a) != 1:
        sys.exit(__doc__)
    if binpath is None:
        binpath = os.path.join(REPO, "build", "sdr", "vl", "obj_full", "Vft710_sdr")
    groups = groups_of(open(a[0]).read())
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as ex:
        nets = list(ex.map(lambda g: netlist(g, binpath, use_cache), groups))
    rts = rtl(groups)
    bad = 0
    for i, (g, n, r) in enumerate(zip(groups, nets, rts)):
        ok = n == r
        bad += not ok
        print("group %d (%d lines) %s" % (i, len(g), "same" if ok else "DIFFERS"))
        print("  netlist: " + show(n))
        if not ok:
            print("  rtl:     " + show(r))
    nl = sum(len(g) for g in groups)
    print("%s: %d groups, %d lines, %d groups differ" % ("FAIL" if bad else "PASS", len(groups), nl, bad))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
