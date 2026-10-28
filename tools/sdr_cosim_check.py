#!/usr/bin/env python3
"""Compare netlist and RTL in the T15e co-simulation (hdl/sdr/sim/cosim_top.v): TX edges and mismatch clocks.

Written for T15e (FT-710 SDR FPGA). Stdlib only. Reads the "<clock> P <bit> <value>" lines that
build/sdr/vl/obj_cosim/Vft710_sdr prints (via tools/sdr_uart_sim.py --raw) for probe bits 0 (netlist uart_b_tx),
1 (RTL tx) and 2 (mismatch).

Usage:
    python3 -I tools/sdr_cosim_check.py LOG          summary: edges per side, mismatching clocks, first differences
    python3 -I tools/sdr_cosim_check.py LOG --edges  list the TX edges of both sides
    python3 -I tools/sdr_cosim_check.py gen SEED N   N random lines (reads, writes, corrupted frames, junk) as
                                                     arguments for tools/sdr_uart_sim.py --gap 0
"""
import sys


def gen(seed, n):
    """Random MAIN-style and malformed traffic for UART B as tools/sdr_uart_sim.py arguments (use --gap 0)."""
    import random
    r = random.Random(seed)
    hx = "0123456789ABCDEF"

    def h(k, lower=False):
        s = "".join(r.choice(hx) for _ in range(k))
        return s.lower() if lower else s

    def summed(body):
        return body + "%02X" % (sum(body.encode()) & 0xFF)
    out = []
    for _ in range(n):
        x = r.random()
        addr = r.choice(["0000", "0001", "0003", "0004", "0015", "0030", "0031", "00FF", h(4), "%04X" % r.randrange(64)])
        if x < 0.35:
            line = summed("r" + (addr.lower() if r.random() < 0.2 else addr))
        elif x < 0.6:
            a = r.choice(["0015", "0030", "0031", "0003", "%04X" % r.randrange(0x38, 0x100)])
            line = summed("w" + a + h(4, r.random() < 0.2))
        elif x < 0.72:                                   # corrupted checksum / lower-case checksum / length
            b = summed(r.choice(["r", "w"]) + h(r.choice([3, 4, 5, 8])))
            k = r.randrange(3)
            line = b[:-1] + r.choice(hx) if k == 0 else (b.lower() if k == 1 else b + "0")
        elif x < 0.86:                                   # junk in front of a good frame
            line = "".join(r.choice("rwx0123 ,\n\x08zq") for _ in range(r.randrange(1, 6))) + summed("r" + addr)
        else:                                            # random printable junk
            line = "".join(chr(r.randrange(32, 127)) for _ in range(r.randrange(0, 12)))
        line += "\r"
        esc = "".join("\\x%02x" % ord(c) if c in "\r\n\x08\\" or ord(c) < 32 else c for c in line)
        if r.random() < 0.2 and len(line) > 3:          # split the line with an idle gap
            k = r.randrange(1, len(line) - 1)
            e1 = "".join("\\x%02x" % ord(c) if c in "\r\n\x08\\" or ord(c) < 32 else c for c in line[:k])
            e2 = "".join("\\x%02x" % ord(c) if c in "\r\n\x08\\" or ord(c) < 32 else c for c in line[k:])
            out += ["b:=" + e1, "w:%d" % r.randrange(1, 40), "b:=" + e2]
        else:
            out.append("b:=" + esc)
        out.append("w:%d" % r.randrange(95, 400))
    return out


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    if sys.argv[1] == "gen":
        print("\n".join(gen(int(sys.argv[2]), int(sys.argv[3]))))
        return
    edges = {0: [], 1: []}
    mism = 0
    mstart = None
    first = []
    last_clk = 0
    for ln in open(sys.argv[1]):
        p = ln.split()
        if len(p) == 4 and p[1] == "P":
            t, b, v = int(p[0]), int(p[2]), int(p[3])
            if t <= 1:
                continue
            if b in edges:
                edges[b].append((t, v))
            if b == 2:
                if v == 1:
                    mstart = t
                elif mstart is not None:
                    mism += t - mstart
                    if len(first) < 10:
                        first.append((mstart, t - mstart))
                    mstart = None
        elif ln.startswith("end at clock"):
            last_clk = int(p[3].rstrip(";"))
    if mstart is not None:
        mism += last_clk - mstart
        first.append((mstart, last_clk - mstart))
    if "--edges" in sys.argv:
        for side in (0, 1):
            print(("netlist" if side == 0 else "rtl    "), " ".join("%d:%d" % e for e in edges[side]))
    print("netlist tx edges %d, rtl tx edges %d, mismatching clocks %d of %d" % (
        len(edges[0]), len(edges[1]), mism, last_clk))
    for t, n in first:
        print("  mismatch from clock %d for %d clocks" % (t, n))
    print("PASS" if mism == 0 and edges[0] else "FAIL")


if __name__ == "__main__":
    main()
