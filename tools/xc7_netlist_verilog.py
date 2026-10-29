#!/usr/bin/env python3
"""Recovered 7-series netlist (tools/xc7_netlist.py JSON) -> structural Verilog + XDC (T15d).

Written for T15 (FT-710 SDR image, XC7A50T). Stdlib only. The output is
derived from Yaesu's bitstream: write it to build/ and never commit it.

Usage:
    python3 -I tools/xc7_netlist_verilog.py verilog NETLIST.json OUT.v [--xdc OUT.xdc] [--pkg PKG] [--ramb18]
        whole design as one module `ft710_sdr` of UNISIM primitives, top ports named
        after package pins (and J2002 / block names where T15c identified them); --ramb18 writes
        the RAMB36 x9/x1 pairs as two RAMB18E1 halves (the pre-#164 reading) instead of one RAMB36E1
    python3 -I tools/xc7_netlist_verilog.py slice NETLIST.json OUT.v --seeds CELL[,CELL...] [--depth N] [--stop CELL,...]
        a sub-netlist: the seeds plus their fan-in cones (through LUT/CARRY/MUX/FF,
        N register stages deep); nets entering from outside become input ports
        `in_<net>`, the seeds' outputs and every IOB pad become ports; --stop cells are cut off
        (their outputs become input ports), to put the slice boundary on a chosen bus (T15e)
    python3 -I tools/xc7_netlist_verilog.py prims OUT.v
        behavioural models for primitives that Yosys' cells_sim.v lacks (RAMD64E, RAMD32)
    python3 -I tools/xc7_netlist_verilog.py simprims OUT.v
        the same plus functional models of IBUFDS/OBUFDS/OBUFTDS/BUFIO/BUFR/IDDR/ODDR/MMCME2_ADV
        (Yosys' cells_xtra.v only declares them) for Icarus simulation with cells_sim.v
    python3 -I tools/xc7_netlist_verilog.py selftest

Smoke test (Yosys 0.23, see docs/code/sdr/netlist.md):
    yosys -q -p "read_verilog -lib +/xilinx/cells_sim.v +/xilinx/cells_xtra.v build/sdr/prims.v;
                 read_verilog build/sdr/ft710_sdr.v; hierarchy -check -top ft710_sdr; stat"

Primitive mapping: LUT6/LUT6_2 #(INIT), FDRE/FDSE/FDCE/FDPE #(INIT, IS_C_INVERTED), CARRY4,
MUXF7/MUXF8, SRLC32E, RAMD64E/RAMD32, DSP48E1 (register attributes, A/B_INPUT, USE_DPORT,
MASK/PATTERN, USE_MULT assumed MULTIPLY), RAMB18E1 (INIT_xx/INITP_xx, widths, DOx_REG,
WRITE_MODE, RSTREG_PRIORITY, IS_*_INVERTED from ZINV_*), RAMB36E1 for the halves that carry the
RAMB36 BRAM36_*_WIDTH_1 flag (x9/x1, INIT interleaved, #164), IDDR/ODDR, BUFGCTRL/BUFHCE/BUFR/BUFIO, MMCME2_ADV (dividers from the
DRP counter fields, XAPP888 encoding), IBUF/IBUFDS/OBUF/OBUFDS/OBUFT/IOBUF with IOSTANDARD.
"""
import collections
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import xc7_blocks  # noqa: E402

# Port names for pins whose function T15c identified ([inference]; see docs/code/sdr/netlist.md).
PORT_NAMES = {
    "IOB_X1Y74": "adc_clk_p", "IOB_X1Y73": "adc_clk_n",          # global fabric clock (125 MHz)
    "IOB_X1Y76": "adc_dco_p", "IOB_X1Y75": "adc_dco_n",          # BUFIO capture clock for the IDDRs
    "IOB_X0Y41": "uart_a_rx", "IOB_X0Y42": "uart_a_tx",
    "IOB_X0Y9": "uart_b_rx", "IOB_X0Y10": "uart_b_tx",
    "IOB_X0Y38": "flash_cs_n", "IOB_X0Y48": "flash_d0", "IOB_X0Y47": "flash_d1",
    "IOB_X0Y46": "flash_d2", "IOB_X0Y45": "flash_d3",
    "IOB_X0Y33": "dsp_clk",
}


def interleave_bits(a, b, n):
    """RAMB36 INIT from its halves (#92/#164): bit j of the result is bit j//2 of a (j even) or b (j odd)."""
    v = 0
    for j in range(n):
        v |= ((a >> j) & 1) << (2 * j) | ((b >> j) & 1) << (2 * j + 1)
    return v


def vname(s):
    return re.sub(r"[^A-Za-z0-9_]", "_", s)


def lit(width, v):
    return "%d'h%x" % (width, v)


class Writer:
    def __init__(self, nl, pkg, db):
        self.nl = nl
        self.g = xc7_blocks.G(nl)
        self.lines = []
        self.wires = set()
        self.ports = []          # (dir, name)
        self.xdc = []
        self.pkg = pkg
        self.db = db
        self.counts = collections.Counter()
        self.notes = collections.Counter()
        self.ramb36 = True          # merge flagged RAMB18 pairs into RAMB36E1 (#164); --ramb18 turns it off
        self.r36_pairs = {}

    rename = {}

    def w(self, net):
        if net is None:
            return "1'bz"
        if net.startswith("1'b"):
            return net
        net = self.rename.get(net, net)
        self.wires.add(net)
        return net

    def pin(self, c, p, default=None):
        v = c["pins"].get(p)
        if v is None:
            return default if default is not None else "1'b0"
        return self.w(v[0])

    def outpin(self, c, p):
        v = c["pins"].get(p)
        return self.w(v[0]) if v else ""

    def bus(self, c, base, width, default="1'b0", out=False, rename=None):
        bits = []
        for i in reversed(range(width)):
            name = (rename or base) + str(i)
            v = c["pins"].get(name)
            if v is None:
                bits.append("" if out else default)
            else:
                bits.append(self.w(v[0]))
        if out:
            # unconnected outputs need a dummy wire to keep the concatenation legal
            res = []
            for i, b in zip(reversed(range(width)), bits):
                if b == "":
                    d = "nc_%s_%s%d" % (vname(c["name"]), base, i)
                    self.wires.add(d)
                    res.append(d)
                else:
                    res.append(b)
            bits = res
        return "{" + ", ".join(bits) + "}"

    def inst(self, ty, name, params, conns, comment=None):
        self.counts[ty] += 1
        ps = ""
        if params:
            ps = " #(\n" + ",\n".join("    .%s(%s)" % kv for kv in params) + "\n  )"
        cs = ",\n".join("    .%s(%s)" % (k, v) for k, v in conns if v != "")
        if comment:
            self.lines.append("  // " + comment)
        self.lines.append("  %s%s %s (\n%s\n  );" % (ty, ps, "\\" + name + " " if not re.match(
            r"^[A-Za-z_][A-Za-z0-9_]*$", name) else name, cs))

    # ---------------------------------------------------------------- cells
    def cell(self, c):
        ty = c["type"]
        n = c["name"]
        p = c["params"]
        if ty == "LUT6":
            self.inst("LUT6", n, [("INIT", lit(64, p["INIT"]))],
                      [("I%d" % i, self.pin(c, "I%d" % i, "1'b1")) for i in range(6)] + [("O", self.outpin(c, "O"))])
        elif ty == "LUT6_2":
            self.inst("LUT6_2", n, [("INIT", lit(64, p["INIT"]))],
                      [("I%d" % i, self.pin(c, "I%d" % i, "1'b1")) for i in range(6)] +
                      [("O6", self.outpin(c, "O6")), ("O5", self.outpin(c, "O5"))])
        elif ty in ("FDRE", "FDSE", "FDCE", "FDPE"):
            rp = {"FDRE": "R", "FDSE": "S", "FDCE": "CLR", "FDPE": "PRE"}[ty]
            self.inst(ty, n, [("INIT", "1'b%d" % p.get("INIT", 0)),
                              ("IS_C_INVERTED", "1'b%d" % p.get("IS_C_INVERTED", 0))],
                      [("C", self.pin(c, "C")), ("CE", self.pin(c, "CE", "1'b1")), (rp, self.pin(c, rp)),
                       ("D", self.pin(c, "D")), ("Q", self.outpin(c, "Q"))])
        elif ty == "CARRY4":
            def b(base, out):
                bits = []
                for i in reversed(range(4)):
                    v = c["pins"].get("%s[%d]" % (base, i))
                    if v is None or (out and not self.g.sinks(v[0]) and v[0] not in self.wires):
                        if out:
                            d = "nc_%s_%s%d" % (vname(n), base, i)
                            self.wires.add(d)
                            bits.append(d)
                        else:
                            bits.append("1'b0")
                    else:
                        bits.append(self.w(v[0]))
                return "{" + ", ".join(bits) + "}"
            self.inst("CARRY4", n, [], [("CI", self.pin(c, "CI")), ("CYINIT", self.pin(c, "CYINIT")),
                                        ("DI", b("DI", False)), ("S", b("S", False)),
                                        ("O", b("O", True)), ("CO", b("CO", True))])
        elif ty in ("MUXF7", "MUXF8"):
            self.inst(ty, n, [], [("I0", self.pin(c, "I0")), ("I1", self.pin(c, "I1")),
                                  ("S", self.pin(c, "S")), ("O", self.outpin(c, "O"))])
        elif ty == "SRLC32E":
            self.inst("SRLC32E", n, [("INIT", lit(32, p["INIT"])),
                                     ("IS_CLK_INVERTED", "1'b%d" % p.get("IS_CLK_INVERTED", 0))],
                      [("A", "{" + ", ".join(self.pin(c, "A[%d]" % i) for i in reversed(range(5))) + "}"),
                       ("CE", self.pin(c, "CE")), ("CLK", self.pin(c, "CLK")), ("D", self.pin(c, "D")),
                       ("Q", self.outpin(c, "Q")), ("Q31", self.outpin(c, "Q31"))])
        elif ty in ("RAMD64E", "RAMD32"):
            na = 6 if ty == "RAMD64E" else 5
            conns = [("CLK", self.pin(c, "CLK")), ("I", self.pin(c, "I")), ("WE", self.pin(c, "WE")),
                     ("O", self.outpin(c, "O"))]
            conns += [("RADR%d" % i, self.pin(c, "RADR%d" % i, "1'b1")) for i in range(na)]
            conns += [("WADR%d" % i, self.pin(c, "WADR%d" % i, "1'b1")) for i in range(na)]
            if ty == "RAMD64E":
                conns += [("WADR6", self.pin(c, "WADR6")), ("WADR7", self.pin(c, "WADR7"))]
            self.inst(ty, n, [("INIT", lit(64 if na == 6 else 32, p["INIT"])),
                              ("IS_CLK_INVERTED", "1'b%d" % p.get("IS_CLK_INVERTED", 0))], conns)
        elif ty == "DSP48E1":
            self.dsp(c)
        elif ty == "RAMB18E1":
            if self.ramb36 and self.is_ramb36(c):
                site, half = self.ramb36_site(c)
                pair = self.r36_pairs.get(site)
                if pair and half == 0:
                    self.bram36(*pair)
                elif not pair:
                    self.bram(c)       # the other half is not in use: keep the RAMB18 reading
            else:
                self.bram(c)
        elif ty == "IDDR":
            self.inst("IDDR", n, [("DDR_CLK_EDGE", '"OPPOSITE_EDGE"'), ("SRTYPE", '"ASYNC"')],
                      [("C", self.pin(c, "CLK")), ("CE", "1'b1"), ("D", self.pin(c, "D")),
                       ("R", "1'b0"), ("S", "1'b0"), ("Q1", self.outpin(c, "Q1")), ("Q2", self.outpin(c, "Q2"))],
                      "DDR_CLK_EDGE not decoded (prjxray has no IDDR edge bits) [approx]")
        elif ty == "ODDR":
            self.inst("ODDR", n, [("DDR_CLK_EDGE", '"SAME_EDGE"' if "ODDR.DDR_CLK_EDGE.SAME_EDGE" in p
                                   else '"OPPOSITE_EDGE"'), ("SRTYPE", '"ASYNC"')],
                      [("C", self.pin(c, "CLK")), ("CE", "1'b1"), ("D1", self.pin(c, "D1")),
                       ("D2", self.pin(c, "D2")), ("R", "1'b0"), ("S", "1'b0"), ("Q", self.outpin(c, "OQ"))])
            # T path: pass-through (TQ = T1)
            tq = c["pins"].get("TQ")
            t1 = c["pins"].get("T1")
            if tq and t1 and not tq[0].startswith("1'b"):
                self.lines.append("  assign %s = %s;" % (self.w(tq[0]), self.w(t1[0])))
        elif ty == "BUFGCTRL":
            self.inst("BUFGCTRL", n, [], [(k, self.pin(c, k)) for k in
                                          ("I0", "I1", "S0", "S1", "CE0", "CE1", "IGNORE0", "IGNORE1")] +
                      [("O", self.outpin(c, "O"))])
        elif ty == "BUFHCE":
            self.inst("BUFHCE", n, [], [("I", self.pin(c, "I")), ("CE", self.pin(c, "CE", "1'b1")),
                                        ("O", self.outpin(c, "O"))])
        elif ty == "BUFR":
            self.inst("BUFR", n, [("BUFR_DIVIDE", '"BYPASS"')],
                      [("I", self.pin(c, "I")), ("CE", "1'b1"), ("CLR", "1'b0"), ("O", self.outpin(c, "O"))],
                      "input comes from a CMT PERF clock that prjxray cannot decode")
        elif ty == "BUFIO":
            self.inst("BUFIO", n, [], [("I", self.pin(c, "I")), ("O", self.outpin(c, "O"))])
        elif ty == "MMCME2_ADV":
            self.mmcm(c)
        elif ty in ("ILOGIC_BYPASS", "OLOGIC_BYPASS", "IOB"):
            pass
        else:
            self.notes["unhandled " + ty] += 1

    def dsp(self, c):
        p = xc7_blocks.dsp_params(c)
        params = [("AREG", p["AREG"]), ("BREG", p["BREG"]),
                  ("ACASCREG", p["AREG"] if p["AREG"] < 2 else 2),
                  ("BCASCREG", p["BREG"] if p["BREG"] < 2 else 2),
                  ("A_INPUT", '"%s"' % p["A_INPUT"]), ("B_INPUT", '"%s"' % p["B_INPUT"]),
                  ("MREG", p["MREG"]), ("PREG", p["PREG"]), ("CREG", p["CREG"]), ("ADREG", p["ADREG"]),
                  ("DREG", p["DREG"]), ("OPMODEREG", p["OPMODEREG"]), ("ALUMODEREG", p["ALUMODEREG"]),
                  ("INMODEREG", p["INMODEREG"]), ("CARRYINREG", p["CARRYINREG"]),
                  ("CARRYINSELREG", p["CARRYINSELREG"]), ("USE_DPORT", '"%s"' % p["USE_DPORT"]),
                  ("USE_MULT", '"MULTIPLY"'), ("MASK", lit(48, p["MASK"])), ("PATTERN", lit(48, p["PATTERN"]))]
        inv = xc7_blocks.dsp_inversions(c)        # ZIS_*_INVERTED = 1: not inverted (#91)
        params += [("IS_OPMODE_INVERTED", lit(7, inv["OPMODE"])), ("IS_ALUMODE_INVERTED", lit(4, inv["ALUMODE"])),
                   ("IS_INMODE_INVERTED", lit(5, inv["INMODE"])), ("IS_CARRYIN_INVERTED", lit(1, inv["CARRYIN"])),
                   ("IS_CLK_INVERTED", lit(1, inv["CLK"]))]
        conns = []
        for base, wdt in (("A", 30), ("B", 18), ("C", 48), ("D", 25), ("ACIN", 30), ("BCIN", 18),
                          ("PCIN", 48), ("OPMODE", 7), ("ALUMODE", 4), ("INMODE", 5), ("CARRYINSEL", 3)):
            conns.append((base, self.bus(c, base, wdt)))
        for base, wdt in (("P", 48), ("ACOUT", 30), ("BCOUT", 18), ("PCOUT", 48), ("CARRYOUT", 4)):
            conns.append((base, self.bus(c, base, wdt, out=True)))
        for s in ("CLK", "CARRYIN", "CARRYCASCIN", "MULTSIGNIN", "CEA1", "CEA2", "CEB1", "CEB2", "CEC", "CED",
                  "CEM", "CEP", "CEAD", "CEALUMODE", "CECTRL", "CECARRYIN", "CEINMODE", "RSTA", "RSTB",
                  "RSTC", "RSTD", "RSTM", "RSTP", "RSTALLCARRYIN", "RSTALUMODE", "RSTCTRL", "RSTINMODE"):
            conns.append((s, self.pin(c, s)))
        for s in ("CARRYCASCOUT", "MULTSIGNOUT", "OVERFLOW", "UNDERFLOW", "PATTERNDETECT", "PATTERNBDETECT"):
            conns.append((s, self.outpin(c, s)))
        self.inst("DSP48E1", c["name"], [(k, v if isinstance(v, str) else str(v)) for k, v in params], conns,
                  "USE_MULT has no prjxray segbits; MULTIPLY (every static OPMODE selects M, #91)")

    # FIFO18E1-type site (the Y0 half of a BRAM tile) names its pins after the FIFO; the tile wires show
    # DO[15:0] = DOADO, DO[31:16] = DOBDO, DOP[1:0] = DOPADOP, DOP[3:2] = DOPBDOP (tile_type_BRAM_*.json)
    FIFO_PINS = dict([("CLKARDCLK", "RDCLK"), ("CLKBWRCLK", "WRCLK"), ("ENARDEN", "RDEN"), ("ENBWREN", "WREN"),
                      ("REGCEAREGCE", "REGCE"), ("RSTRAMARSTRAM", "RST"), ("RSTREGARSTREG", "RSTREG")]
                     + [("DOADO%d" % i, "DO%d" % i) for i in range(16)]
                     + [("DOBDO%d" % i, "DO%d" % (16 + i)) for i in range(16)]
                     + [("DOPADOP%d" % i, "DOP%d" % i) for i in range(2)]
                     + [("DOPBDOP%d" % i, "DOP%d" % (2 + i)) for i in range(2)])

    @staticmethod
    def bram_width(p, prefix):
        for k in p:
            m = re.match(r"^%s_(\d+)$" % prefix, k)
            if m:
                return int(m.group(1))
        return 1

    def bram_params(self, p):
        """Mode parameters shared by RAMB18E1 and RAMB36E1 (without widths and INIT)."""
        params = [("DOA_REG", 1 if p.get("DOA_REG") else 0), ("DOB_REG", 1 if p.get("DOB_REG") else 0),
                  ("WRITE_MODE_A", '"%s"' % ("NO_CHANGE" if p.get("WRITE_MODE_A_NO_CHANGE") else
                                             "READ_FIRST" if p.get("WRITE_MODE_A_READ_FIRST") else "WRITE_FIRST")),
                  ("WRITE_MODE_B", '"%s"' % ("NO_CHANGE" if p.get("WRITE_MODE_B_NO_CHANGE") else
                                             "READ_FIRST" if p.get("WRITE_MODE_B_READ_FIRST") else "WRITE_FIRST")),
                  ("RSTREG_PRIORITY_A", '"%s"' % ("REGCE" if p.get("RSTREG_PRIORITY_A_REGCE") else "RSTREG")),
                  ("RSTREG_PRIORITY_B", '"%s"' % ("REGCE" if p.get("RSTREG_PRIORITY_B_REGCE") else "RSTREG"))]
        # prjxray ZINV_<pin> = 1 means the pin is NOT inverted (#164). Unrouted RST pins sit at VCC
        # with ZINV clear, i.e. inverted to an inactive 0.
        for s in ("CLKARDCLK", "CLKBWRCLK", "ENARDEN", "ENBWREN", "RSTRAMARSTRAM", "RSTRAMB", "RSTREGARSTREG",
                  "RSTREGB"):
            params.append(("IS_%s_INVERTED" % s, "1'b%d" % (0 if p.get("ZINV_" + s) else 1)))
        return params

    def bpin(self, c, logical, default="1'b0"):
        """Pin of a RAMB18 half by its RAMB18E1 port name (FIFO18 sites use other pin names)."""
        fifo = "RDCLK" in c["pins"] or "WRCLK" in c["pins"] or "DO0" in c["pins"]
        name = self.FIFO_PINS.get(logical, logical) if fifo else logical
        v = c["pins"].get(name)
        if v is None:
            return default
        return self.w(v[0])

    def bram(self, c):
        p = c["params"]
        width = lambda pre: self.bram_width(p, pre)  # noqa: E731
        rda, rdb, wra, wrb = width("READ_WIDTH_A"), width("READ_WIDTH_B"), width("WRITE_WIDTH_A"), width("WRITE_WIDTH_B")
        if p.get("SDP_READ_WIDTH_36"):
            rda = 36
        if p.get("SDP_WRITE_WIDTH_36"):
            wrb = 36
        params = [("READ_WIDTH_A", rda), ("READ_WIDTH_B", rdb), ("WRITE_WIDTH_A", wra), ("WRITE_WIDTH_B", wrb),
                  ("RAM_MODE", '"SDP"' if rda == 36 or wrb == 36 else '"TDP"')] + self.bram_params(p)
        for k in range(0x40):
            v = p.get("INIT_%02X" % k, 0)
            if v:
                params.append(("INIT_%02X" % k, lit(256, v)))
        for k in range(8):
            v = p.get("INITP_%02X" % k, 0)
            if v:
                params.append(("INITP_%02X" % k, lit(256, v)))

        def bus(base, n, out=False):
            bits = []
            for i in reversed(range(n)):
                b = self.bpin(c, "%s%d" % (base, i), "" if out else "1'b0")
                if out and b == "":
                    b = "nc_%s_%s%d" % (vname(c["name"]), base, i)
                    self.wires.add(b)
                bits.append(b)
            return "{" + ", ".join(bits) + "}"
        conns = [(s, self.bpin(c, s)) for s in
                 ("CLKARDCLK", "CLKBWRCLK", "ENARDEN", "ENBWREN", "REGCEAREGCE", "REGCEB", "RSTRAMARSTRAM",
                  "RSTRAMB", "RSTREGARSTREG", "RSTREGB")]
        conns += [("ADDRARDADDR", bus("ADDRARDADDR", 14)), ("ADDRBWRADDR", bus("ADDRBWRADDR", 14)),
                  ("DIADI", bus("DIADI", 16)), ("DIBDI", bus("DIBDI", 16)),
                  ("DIPADIP", bus("DIPADIP", 2)), ("DIPBDIP", bus("DIPBDIP", 2)),
                  ("WEA", bus("WEA", 2)), ("WEBWE", bus("WEBWE", 4)),
                  ("DOADO", bus("DOADO", 16, True)), ("DOBDO", bus("DOBDO", 16, True)),
                  ("DOPADOP", bus("DOPADOP", 2, True)), ("DOPBDOP", bus("DOPBDOP", 2, True))]
        self.inst("RAMB18E1", c["name"], [(k, str(v)) for k, v in params], conns)

    @staticmethod
    def ramb36_site(c):
        m = re.match(r"^RAMB18_X(\d+)Y(\d+)$", c["site"])
        return "RAMB36_X%sY%d" % (m.group(1), int(m.group(2)) // 2), int(m.group(2)) % 2

    @staticmethod
    def is_ramb36(c):
        """True RAMB36E1 (#164): RAMB36.BRAM36_*_WIDTH_1 exists only on a RAMB36 in x1 (halves x1) or
        x9 (halves x4) mode (prjxray fuzzer 027-bram36-config, docs/code/sdr/bram-tables.md)."""
        p = c["params"]
        return bool(c["type"] == "RAMB18E1" and p.get("RAMB36.BRAM36_READ_WIDTH_A_1")
                    and all(Writer.bram_width(p, w) in (1, 4) for w in
                            ("READ_WIDTH_A", "READ_WIDTH_B", "WRITE_WIDTH_A", "WRITE_WIDTH_B")))

    def bram36(self, lo, hi):
        """One RAMB36E1 from its two RAMB18 halves (lo = Y0 = the L pins, hi = Y1 = the U pins).

        Pin map (tile_type_BRAM_*.json, RAMBFIFO36E1 site): data/parity bit 2k is the lower half's pin k and
        bit 2k+1 the upper half's (DOADO1 = BRAM_FIFO36_DOADOU0, DIPADIP1 = ...DIPADIPU0); RAMB18 address pin k is
        RAMB36 address bit k+1 (BRAM_ADDRARDADDRL<k+1> -> FIFO18 ADDRARDADDR<k>); bit 0 and the cascade bit 15
        are not on the RAMB18 pins (unused in x9/x1, tied 1). INIT/INITP: RAMB36 bit j = bit j/2 of half Y(j mod 2)."""
        p = lo["params"]
        w36 = {1: 1, 4: 9}
        params = [(k, w36[self.bram_width(p, k)]) for k in
                  ("READ_WIDTH_A", "READ_WIDTH_B", "WRITE_WIDTH_A", "WRITE_WIDTH_B")]
        params += [("RAM_MODE", '"TDP"')] + self.bram_params(p)
        for kind, n, nw in (("INIT", 0x40, 0x80), ("INITP", 8, 16)):
            h = []
            for c in (lo, hi):
                v = 0
                for k in range(n):
                    v |= c["params"].get("%s_%02X" % (kind, k), 0) << (256 * k)
                h.append(v)
            v = interleave_bits(h[0], h[1], n * 256)
            for k in range(nw):
                word = (v >> (256 * k)) & ((1 << 256) - 1)
                if word:
                    params.append(("%s_%02X" % (kind, k), lit(256, word)))

        def ilv(base, n, out=False):
            bits = []
            for i in reversed(range(2 * n)):
                b = self.bpin((lo, hi)[i % 2], "%s%d" % (base, i // 2), "" if out else "1'b0")
                if out and b == "":
                    b = "nc_%s_%s%d" % (vname(lo["name"]), base, i)
                    self.wires.add(b)
                bits.append(b)
            return "{" + ", ".join(bits) + "}"

        def addr(base):
            return "{1'b1, " + ", ".join(self.bpin(lo, "%s%d" % (base, i), "1'b1") for i in reversed(range(14))) \
                + ", 1'b1}"
        ctl = ("CLKARDCLK", "CLKBWRCLK", "ENARDEN", "ENBWREN", "REGCEAREGCE", "REGCEB", "RSTRAMARSTRAM",
               "RSTRAMB", "RSTREGARSTREG", "RSTREGB")
        for s in ctl + tuple("ADDRARDADDR%d" % i for i in range(14)) + tuple("ADDRBWRADDR%d" % i for i in range(14)) \
                + tuple("WEA%d" % i for i in range(4)) + tuple("WEBWE%d" % i for i in range(4)):
            if self.bpin(lo, s) != self.bpin(hi, s):
                self.notes["RAMB36 halves differ on " + s.rstrip("0123456789")] += 1
        conns = [(s, self.bpin(lo, s)) for s in ctl]
        conns += [("CASCADEINA", "1'b0"), ("CASCADEINB", "1'b0"), ("INJECTDBITERR", "1'b0"),
                  ("INJECTSBITERR", "1'b0"),
                  ("ADDRARDADDR", addr("ADDRARDADDR")), ("ADDRBWRADDR", addr("ADDRBWRADDR")),
                  ("DIADI", ilv("DIADI", 16)), ("DIBDI", ilv("DIBDI", 16)),
                  ("DIPADIP", ilv("DIPADIP", 2)), ("DIPBDIP", ilv("DIPBDIP", 2)),
                  ("WEA", "{" + ", ".join(self.bpin(lo, "WEA%d" % i) for i in reversed(range(4))) + "}"),
                  ("WEBWE", "{" + ", ".join(self.bpin(lo, "WEBWE%d" % (i % 4)) for i in reversed(range(8))) + "}"),
                  ("DOADO", ilv("DOADO", 16, True)), ("DOBDO", ilv("DOBDO", 16, True)),
                  ("DOPADOP", ilv("DOPADOP", 2, True)), ("DOPBDOP", ilv("DOPBDOP", 2, True))]
        name = self.ramb36_site(lo)[0]
        self.inst("RAMB36E1", name, [(k, str(v)) for k, v in params], conns,
                  "true RAMB36E1 from %s + %s (BRAM36 width flag, #164)" % (lo["site"], hi["site"]))

    def mmcm(self, c):
        p = c["params"]

        def cnt(prefix):
            hi = p.get(prefix + "_CLKOUT1_HIGH_TIME", 0)
            lo = p.get(prefix + "_CLKOUT1_LOW_TIME", 0)
            frac = p.get(prefix + "_CLKOUT2_FRAC", 0) if p.get(prefix + "_CLKOUT2_FRAC_EN") else 0
            return hi + lo + frac / 8.0
        div = p.get("DIVCLK_DIVCLK_HIGH_TIME", 0) + p.get("DIVCLK_DIVCLK_LOW_TIME", 0)
        params = [("DIVCLK_DIVIDE", div or 1), ("CLKFBOUT_MULT_F", "%.3f" % cnt("CLKFBOUT")),
                  ("CLKOUT0_DIVIDE_F", "%.3f" % cnt("CLKOUT0")), ("CLKIN1_PERIOD", "8.0")]
        conns = [(s, self.pin(c, s)) for s in ("CLKIN1", "CLKIN2", "CLKFBIN", "RST", "PWRDWN", "CLKINSEL",
                                               "DCLK", "DEN", "DWE", "PSCLK", "PSEN", "PSINCDEC")]
        conns += [("DADDR", self.bus(c, "DADDR", 7)), ("DI", self.bus(c, "DI", 16))]
        conns += [(s, self.outpin(c, s)) for s in ("CLKOUT0", "CLKOUT1", "CLKOUT2", "CLKOUT3", "CLKOUT4",
                                                   "CLKOUT5", "CLKOUT6", "CLKFBOUT", "LOCKED")]
        self.inst("MMCME2_ADV", c["name"], [(k, str(v)) for k, v in params], conns,
                  "CLKIN1_PERIOD 8 ns assumes the 125 MHz ADC clock [inference]")

    # ---------------------------------------------------------------- IO
    def iobs(self):
        pf, pins = xc7_blocks.pin_maps(self.db, self.pkg)
        rows = {r["site"]: r for r in xc7_blocks.io_rows(self.g, self.db, self.pkg)}
        cells = {c["site"]: c for c in self.nl["cells"] if c["type"] == "IOB"}
        done = set()
        # N sites of differential pairs are emitted together with their P site
        for site, r in rows.items():
            if r["diff"] and "P_" in (pf.get(site, "").split("_T")[0] + "_"):
                x, y = site.split("_X")[1].split("Y")
                done.add("IOB_X%sY%d" % (x, int(y) - 1))
        for site in sorted(cells, key=lambda s: (s.split("Y")[0], int(s.split("Y")[1]))):
            if site in done and not rows[site]["diff"]:
                continue
            if site in done and rows[site]["diff"] and "N_" in (pf.get(site, "").split("_T")[0] + "_"):
                continue
            c = cells[site]
            r = rows[site]
            x, y = site.split("_X")[1].split("Y")
            mate = "IOB_X%sY%d" % (x, int(y) + (1 if int(y) % 2 == 1 else -1))
            func = pf.get(site, "")
            is_p = "P_" in func.split("_T")[0] + "_"
            diff = r["diff"]
            base = PORT_NAMES.get(site) or ("io_" + vname(pins.get(site, site)))
            std = r["std"]
            i = c["pins"].get("I")
            o = c["pins"].get("O")
            t = c["pins"].get("T")
            if diff == "in" and is_p and mate in cells:
                done.update((site, mate))
                pn, nn = PORT_NAMES.get(site) or base + "_p", PORT_NAMES.get(mate) or "io_" + vname(pins.get(mate, mate)) + "_n"
                self.ports += [("input", pn), ("input", nn)]
                self.inst("IBUFDS", "ibufds_" + vname(site), [("IOSTANDARD", '"LVDS_25"'), ("DIFF_TERM", '"FALSE"')],
                          [("I", pn), ("IB", nn), ("O", self.w(i[0]) if i else "")])
                self.xdc_pin(site, pn, "LVDS_25", pins)
                self.xdc_pin(mate, nn, "LVDS_25", pins)
                continue
            def enabled(tnet):    # unrouted T (OLOGIC T1 left at its IMUX default) = always driving
                return tnet is None or tnet.startswith("1'b") or not self.g.driver(tnet)
            if diff == "out" and mate in cells:
                done.update((site, mate))
                pn, nn = base + ("" if base.endswith("_p") else "_p"), "io_" + vname(pins.get(mate, mate)) + "_n"
                self.ports += [("output", pn), ("output", nn)]
                tn = t[0] if t else None
                if enabled(tn):
                    self.inst("OBUFDS", "obufds_" + vname(site), [("IOSTANDARD", '"LVDS_25"')],
                              [("I", self.w(o[0]) if o else "1'b0"), ("O", pn), ("OB", nn)])
                else:
                    self.inst("OBUFTDS", "obuftds_" + vname(site), [("IOSTANDARD", '"LVDS_25"')],
                              [("I", self.w(o[0]) if o else "1'b0"), ("T", self.w(tn)), ("O", pn), ("OB", nn)],
                              "T polarity as routed; OLOGIC T inversion not decoded [approx]")
                self.xdc_pin(site, pn, "LVDS_25", pins)
                self.xdc_pin(mate, nn, "LVDS_25", pins)
                continue
            done.add(site)
            d = r["dir"]
            if d.startswith("in") and not d.startswith("inout"):
                self.ports.append(("input", base))
                self.inst("IBUF", "ibuf_" + vname(site), [("IOSTANDARD", '"%s"' % std)],
                          [("I", base), ("O", self.w(i[0]) if i else "")])
            elif d.startswith("inout") and not enabled(t[0] if t else None):
                self.ports.append(("inout", base))
                self.inst("IOBUF", "iobuf_" + vname(site), [("IOSTANDARD", '"%s"' % std)],
                          [("I", self.w(o[0])), ("T", self.w(t[0])), ("O", self.w(i[0]) if i else ""), ("IO", base)],
                          "T polarity as routed; OLOGIC T inversion not decoded [approx]")
            else:
                self.ports.append(("output", base))
                self.inst("OBUF", "obuf_" + vname(site), [("IOSTANDARD", '"%s"' % std)],
                          [("I", self.w(o[0]) if o else "1'b0"), ("O", base)])
            self.xdc_pin(site, base, std, pins)

    def xdc_pin(self, site, port, std, pins):
        if site in pins:
            self.xdc.append("set_property -dict {PACKAGE_PIN %s IOSTANDARD %s} [get_ports %s]" % (
                pins[site], std, port))
        else:
            self.xdc.append("# %s: site %s is not bonded in %s" % (port, site, self.pkg))

    def emit(self, name="ft710_sdr", cells=None, extra_ports=()):
        cells = self.nl["cells"] if cells is None else cells
        halves = collections.defaultdict(dict)
        for c in cells:
            if self.ramb36 and self.is_ramb36(c):
                site, half = self.ramb36_site(c)
                halves[site][half] = c
        self.r36_pairs = {s: (h[0], h[1]) for s, h in halves.items() if len(h) == 2}
        for c in cells:
            self.cell(c)
        body = self.lines
        self.lines = []
        out = ["// Structural netlist recovered from FT-710_SDR_V0104 (XC7A50T) by tools/xc7_netlist_verilog.py.",
               "// Derived from Yaesu's bitstream: private, never commit or publish.",
               "`default_nettype none", "module %s (" % name]
        ports = list(self.ports) + list(extra_ports)
        out.append(",\n".join("  %s wire %s" % (d, n) for d, n in ports))
        out.append(");")
        for wn in sorted(self.wires - set(n for _, n in ports)):
            out.append("  wire %s;" % wn)
        out += body
        out.append("endmodule")
        out.append("`default_nettype wire")
        return "\n".join(out) + "\n"


PRIMS = r"""// Behavioural models of UNISIM primitives missing from Yosys' cells_sim.v (T15d).
module RAMD64E #(parameter [63:0] INIT = 64'h0, parameter [0:0] IS_CLK_INVERTED = 1'b0,
                 parameter [1:0] RAM_ADDRESS_MASK = 2'b00, parameter [1:0] RAM_ADDRESS_SPACE = 2'b00)
  (output O, input CLK, input I, input WE, input RADR0, RADR1, RADR2, RADR3, RADR4, RADR5,
   input WADR0, WADR1, WADR2, WADR3, WADR4, WADR5, WADR6, WADR7);
  reg [63:0] mem = INIT;
  wire clk = CLK ^ IS_CLK_INVERTED;
  assign O = mem[{RADR5, RADR4, RADR3, RADR2, RADR1, RADR0}];
  always @(posedge clk) if (WE) mem[{WADR5, WADR4, WADR3, WADR2, WADR1, WADR0}] <= I;
endmodule
module RAMD32 #(parameter [31:0] INIT = 32'h0, parameter [0:0] IS_CLK_INVERTED = 1'b0)
  (output O, input CLK, input I, input WE, input RADR0, RADR1, RADR2, RADR3, RADR4,
   input WADR0, WADR1, WADR2, WADR3, WADR4);
  reg [31:0] mem = INIT;
  wire clk = CLK ^ IS_CLK_INVERTED;
  assign O = mem[{RADR4, RADR3, RADR2, RADR1, RADR0}];
  always @(posedge clk) if (WE) mem[{WADR4, WADR3, WADR2, WADR1, WADR0}] <= I;
endmodule
"""

# Simple simulation models for primitives that Yosys' cells_xtra.v only declares (ports, no
# behaviour). Enough for functional simulation of the recovered netlist, not timing-accurate.
SIM_PRIMS = r"""// Functional sim models (T15d) for primitives stubbed in Yosys' cells_xtra.v. Not for synthesis.
module IBUFDS #(parameter IOSTANDARD = "DEFAULT", parameter DIFF_TERM = "FALSE") (output O, input I, input IB);
  assign O = I;
endmodule
module OBUFDS #(parameter IOSTANDARD = "DEFAULT") (output O, output OB, input I);
  assign O = I; assign OB = ~I;
endmodule
module OBUFTDS #(parameter IOSTANDARD = "DEFAULT") (output O, output OB, input I, input T);
  assign O = T ? 1'bz : I; assign OB = T ? 1'bz : ~I;
endmodule
module BUFIO (output O, input I); assign O = I; endmodule
module BUFR #(parameter BUFR_DIVIDE = "BYPASS", parameter SIM_DEVICE = "7SERIES")
  (output O, input CE, input CLR, input I); assign O = I; endmodule
module IDDR #(parameter DDR_CLK_EDGE = "OPPOSITE_EDGE", parameter SRTYPE = "SYNC",
              parameter INIT_Q1 = 1'b0, parameter INIT_Q2 = 1'b0)
  (output reg Q1 = INIT_Q1, output reg Q2 = INIT_Q2, input C, input CE, input D, input R, input S);
  always @(posedge C) if (CE) Q1 <= D;
  always @(negedge C) if (CE) Q2 <= D;
endmodule
module ODDR #(parameter DDR_CLK_EDGE = "OPPOSITE_EDGE", parameter SRTYPE = "SYNC", parameter INIT = 1'b0)
  (output Q, input C, input CE, input D1, input D2, input R, input S);
  assign Q = C ? D1 : D2;
endmodule
module MMCME2_ADV #(parameter DIVCLK_DIVIDE = 1, parameter CLKFBOUT_MULT_F = 5.0,
                    parameter CLKOUT0_DIVIDE_F = 1.0, parameter CLKIN1_PERIOD = 0.0)
  (input CLKIN1, CLKIN2, CLKFBIN, RST, PWRDWN, CLKINSEL, DCLK, DEN, DWE, PSCLK, PSEN, PSINCDEC,
   input [6:0] DADDR, input [15:0] DI,
   output CLKOUT0, CLKOUT1, CLKOUT2, CLKOUT3, CLKOUT4, CLKOUT5, CLKOUT6, CLKFBOUT, LOCKED);
  // functional stand-in: output = input clock (frequency not modelled), always locked
  assign CLKOUT0 = CLKIN1; assign CLKFBOUT = CLKIN1; assign LOCKED = 1'b1;
  assign {CLKOUT1, CLKOUT2, CLKOUT3, CLKOUT4, CLKOUT5, CLKOUT6} = 6'b0;
endmodule
"""


def cmd_verilog(path, out, xdc, pkg, db, ramb18=False):
    nl = json.load(open(path))
    w = Writer(nl, pkg, db)
    w.ramb36 = not ramb18
    w.iobs()
    text = w.emit()
    open(out, "w").write(text)
    if xdc:
        open(xdc, "w").write("# Pin constraints recovered from the FT-710 SDR bitstream (package %s assumed)\n" % pkg
                             + "\n".join(w.xdc) + "\n")
    print("%s: %d ports, %d wires; %s" % (out, len(w.ports), len(w.wires),
                                         " ".join("%s=%d" % kv for kv in sorted(w.counts.items()))))
    if w.notes:
        print("notes: %s" % dict(w.notes))
    return w


def slice_cells(nl, seeds, depth, stopcells=()):
    """Seeds + fan-in cones (stop at clocks/resets, IOB, BUF*, hard blocks), DEPTH FF stages.
    Cells in STOPCELLS are left out: their outputs become input ports of the slice."""
    stopcells = set(stopcells)
    g = xc7_blocks.G(nl)
    keep = set()
    seen = set()
    frontier = [(s, 0, None) for s in seeds]
    stop = ("BUFGCTRL", "BUFHCE", "BUFR", "BUFIO", "MMCME2_ADV", "IOB", "DSP48E1", "RAMB18E1")
    while frontier:
        c, d, via = frontier.pop()
        if (c, via) in seen:
            continue
        seen.add((c, via))
        keep.add(c)
        cc = g.cells[c]
        if cc["type"] in stop:
            continue
        isff = cc["type"] in xc7_blocks.FF
        if isff and d >= depth:
            continue
        deps = None
        if cc["type"] == "LUT6_2" and via in ("O5", "O6"):   # only the inputs the used output depends on
            deps = set(p for p, _ in xc7_blocks.lut_function(cc, via)[0])
        for p, v in cc["pins"].items():
            if v[1] != "I" or p in ("C", "CLK") or (deps is not None and p not in deps):
                continue
            dr = g.driver(v[0])
            # resets: follow local reset logic (LUTs), stop at register-driven global resets
            if p in ("R", "S", "CLR", "PRE") and dr and g.ctype(dr[0]) in xc7_blocks.FF:
                continue
            if dr and g.ctype(dr[0]) not in stop and dr[0] not in stopcells:
                frontier.append((dr[0], d + (1 if isff else 0), dr[1]))
    return keep


def cmd_slice(path, out, seeds, depth, pkg, db, stopcells=()):
    nl = json.load(open(path))
    keep = slice_cells(nl, seeds, depth, stopcells)
    cells = [c for c in nl["cells"] if c["name"] in keep]
    g = xc7_blocks.G(nl)
    driven = set()
    for c in cells:
        for p, v in c["pins"].items():
            if v[1] == "O":
                driven.add(v[0])
    w = Writer(nl, pkg, db)
    ext = []
    for c in cells:
        for p, v in c["pins"].items():
            n = v[0]
            if v[1] == "I" and not n.startswith("1'b") and n not in driven:
                d = g.driver(n)
                ext.append(n)
    ext = sorted(set(ext))
    # boundary nets become input ports; seeds' outputs become output ports
    outs = []
    for s in seeds:
        for p, v in g.cells[s]["pins"].items():
            if v[1] == "O" and not v[0].startswith("1'b"):
                outs.append(v[0])
    # ports are named after the driving pin (stable across netlist rebuilds): i_<cell>_<pin> / o_<cell>_<pin>
    rename = {}
    for n in ext:
        d = g.driver(n)
        rename[n] = "i_" + vname("%s_%s" % d if d else "undriven_" + n)
    for n in outs:
        if n not in rename:
            d = g.driver(n)
            rename[n] = "o_" + vname("%s_%s" % d)
    for c in cells:     # internal nets: w_<driver cell>_<pin>
        for p, v in c["pins"].items():
            if v[1] == "O" and not v[0].startswith("1'b") and v[0] not in rename:
                rename[v[0]] = "w_" + vname("%s_%s" % (c["name"], p))
    w.rename = rename
    w.lines = []
    for c in cells:
        w.cell(c)
    body = w.lines
    w.lines = []
    ext = [rename[n] for n in ext]
    outs = [rename[n] for n in outs]
    portset = set(ext) | set(outs)
    lines = ["// Slice of the recovered FT-710 SDR netlist (tools/xc7_netlist_verilog.py slice). Private.",
             "// seeds: %s, depth %d, %d cells" % (",".join(seeds), depth, len(cells)),
             "`default_nettype none", "module ft710_slice ("]
    pl = ["  input wire %s" % n for n in ext] + ["  output wire %s" % n for n in sorted(set(outs) - set(ext))]
    lines.append(",\n".join(pl))
    lines.append(");")
    for wn in sorted(w.wires - portset):
        lines.append("  wire %s;" % wn)
    lines += body
    lines += ["endmodule", "`default_nettype wire"]
    # boundary description for testbenches
    open(out, "w").write("\n".join(lines) + "\n")
    json.dump({"inputs": ext, "outputs": outs}, open(out + ".ports.json", "w"), indent=1)
    print("%s: %d cells, %d input ports, %d output ports; %s" % (
        out, len(cells), len(ext), len(set(outs) - set(ext)),
        " ".join("%s=%d" % kv for kv in sorted(w.counts.items()))))


def selftest():
    nl = {"cells": [
        {"name": "IOB_X0Y41", "type": "IOB", "site": "IOB_X0Y41",
         "params": {"IOB_Y1.LVCMOS25_LVCMOS33_LVTTL.IN": 1}, "pins": {"I": ["n0", "O"]}},
        {"name": "IOB_X0Y42", "type": "IOB", "site": "IOB_X0Y42",
         "params": {"IOB_Y0.LVCMOS33_LVTTL.DRIVE.I12_I16": 1}, "pins": {"O": ["n2", "I"], "T": ["1'b1", "I"]}},
        {"name": "S/ALUT", "type": "LUT6", "site": "SLICE_X0Y0", "params": {"INIT": 0x5555555555555555},
         "pins": {"I0": ["n0", "I"], "I1": ["1'b1", "I"], "O": ["n1", "O"]}},
        {"name": "S/AFF", "type": "FDRE", "site": "SLICE_X0Y0", "params": {"INIT": 0, "IS_C_INVERTED": 0},
         "pins": {"C": ["n0", "I"], "CE": ["1'b1", "I"], "R": ["1'b0", "I"], "D": ["n1", "I"], "Q": ["n2", "O"]}},
    ], "nets": {"n0": {"drivers": ["IOB_X0Y41.I"], "sinks": ["S/ALUT.I0", "S/AFF.C"]},
                "n1": {"drivers": ["S/ALUT.O"], "sinks": ["S/AFF.D"]},
                "n2": {"drivers": ["S/AFF.Q"], "sinks": ["IOB_X0Y42.O"]}}}
    w = Writer(nl, "xc7a50tcsg324-1", xc7_blocks.DEFAULT_DB)
    w.iobs()
    v = w.emit()
    for frag in ("input wire uart_a_rx", "output wire uart_a_tx", "LUT6 #(\n    .INIT(64'h5555555555555555)",
                 ".D(n1)", ".Q(n2)", "IBUF #(", "OBUF #("):
        assert frag in v, (frag, v)
    assert any("PACKAGE_PIN M18" in x and "uart_a_rx" in x for x in w.xdc), w.xdc
    print("selftest: 2 IOBs + LUT6 + FDRE -> Verilog ports, INIT, nets and XDC pin M18: ok")


def main():
    a = sys.argv[1:]
    opts = {}
    for k in ("--xdc", "--pkg", "--db", "--seeds", "--depth", "--stop"):
        if k in a:
            i = a.index(k)
            opts[k] = a[i + 1]
            del a[i:i + 2]
    pkg = opts.get("--pkg", "xc7a50tcsg324-1")
    db = opts.get("--db", xc7_blocks.DEFAULT_DB)
    if not a:
        sys.exit(__doc__)
    ramb18 = "--ramb18" in a
    if ramb18:
        a.remove("--ramb18")
    if a[0] == "verilog" and len(a) == 3:
        cmd_verilog(a[1], a[2], opts.get("--xdc"), pkg, db, ramb18)
    elif a[0] == "slice" and len(a) == 3 and "--seeds" in opts:
        cmd_slice(a[1], a[2], opts["--seeds"].split(","), int(opts.get("--depth", 4)), pkg, db,
                  opts["--stop"].split(",") if opts.get("--stop") else ())
    elif a[0] == "prims" and len(a) == 2:
        open(a[1], "w").write(PRIMS)
    elif a[0] == "simprims" and len(a) == 2:
        open(a[1], "w").write(PRIMS + SIM_PRIMS)
    elif a[0] == "selftest":
        selftest()
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
