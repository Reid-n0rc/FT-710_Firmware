#!/usr/bin/env python3
"""Add a probe output port to the structural netlist, for watching internal nets in Verilator (T15e).

Written for T15e (FT-710 SDR FPGA). Stdlib only. Input and output are derived files (build/, never commit).

Usage:
    python3 -I tools/xc7_probe_netlist.py NETLIST.json IN.v OUT.v OUT.names CELLPIN [CELLPIN ...]
        CELLPIN is CELL (all output pins of the cell, e.g. SLICE_X2Y101/AFF -> Q) or CELL.PIN, or @FILE with one
        per line. OUT.v is IN.v with `output wire [N-1:0] probe` on module ft710_sdr and
        `assign probe[i] = <net of CELLPIN i>;`. OUT.names lists index, cell.pin, net.
        hdl/sdr/sim/full_main.cpp prints probe changes when built with -DPROBE_W=<words>.
"""
import json
import sys


def main():
    if len(sys.argv) < 6:
        sys.exit(__doc__)
    nlp, inp, outp, namesp = sys.argv[1:5]
    refs = []
    for a in sys.argv[5:]:
        if a.startswith("@"):
            refs += [x.strip() for x in open(a[1:]) if x.strip() and not x.startswith("#")]
        else:
            refs.append(a)
    nl = json.load(open(nlp))
    cells = {c["name"]: c for c in nl["cells"]}
    probes = []
    for r in refs:
        if r in cells:
            pins = [(p, v[0]) for p, v in sorted(cells[r]["pins"].items()) if v[1] == "O"]
        else:
            c, p = r.rsplit(".", 1)
            pins = [(p, cells[c]["pins"][p][0])]
        for p, n in pins:
            if n.startswith("1'b"):
                continue
            probes.append(("%s.%s" % (r.split(".")[0] if r in cells else c, p), n))
    src = open(inp).read()
    head, sep, rest = src.partition("module ft710_sdr (\n")
    assert sep, "module header not found"
    n = len(probes)
    src = head + sep + "  output wire [%d:0] probe,\n" % (n - 1) + rest
    i = src.rindex("endmodule")
    body = "".join("  assign probe[%d] = %s;\n" % (k, net) for k, (_, net) in enumerate(probes))
    src = src[:i] + body + src[i:]
    open(outp, "w").write(src)
    with open(namesp, "w") as f:
        for k, (cp, net) in enumerate(probes):
            f.write("%d\t%s\t%s\n" % (k, cp, net))
    print("%d probes, %d words" % (n, (n + 31) // 32))


if __name__ == "__main__":
    main()
