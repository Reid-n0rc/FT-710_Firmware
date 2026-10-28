#!/usr/bin/env python3
"""Block recognition on a netlist from tools/xc7_netlist.py (T15c). Stdlib only.

Usage:
    python3 -I tools/xc7_blocks.py NETLIST.json clocks          clock buffers, sources, loads per clock
    python3 -I tools/xc7_blocks.py NETLIST.json io [PKG]        used IOBs: pin, bank, standard, direction, first
                                                               fabric load/driver, its clock, sync chain
    python3 -I tools/xc7_blocks.py NETLIST.json package         which XC7A50T packages bond every used IOB
    python3 -I tools/xc7_blocks.py NETLIST.json dsp             DSP48E1 options, cascade chains, A/B/C sources
    python3 -I tools/xc7_blocks.py NETLIST.json bram            RAMB18 halves: widths, what reads/writes them
    python3 -I tools/xc7_blocks.py NETLIST.json cone CELL[.PIN] [DEPTH]   fan-in cone of a pin (cells, types)
    python3 -I tools/xc7_blocks.py NETLIST.json fanout CELL.PIN [DEPTH]   fan-out cone of an output pin
    python3 -I tools/xc7_blocks.py NETLIST.json region SITE-PATTERN       cells and clocks of matching sites
    python3 -I tools/xc7_blocks.py NETLIST.json logic CELL[,CELL] [DEPTH]  equations (LUTs as minimal SOP) of
                                                               the cells within DEPTH steps of the seeds
    python3 -I tools/xc7_blocks.py selftest

PKG is a package name such as xc7a50tcsg324-1 (default) for the pin column.
The database dir defaults to $PRJXRAY_DB or ~/.local/share/ft710-tools/prjxray-db/artix7.
"""
import collections
import csv
import json
import os
import re
import sys

DEFAULT_DB = os.environ.get(
    "PRJXRAY_DB", os.path.expanduser("~/.local/share/ft710-tools/prjxray-db/artix7"))
FF = ("FDRE", "FDSE", "FDCE", "FDPE", "LDCE", "LDPE")
CLKPIN = {"FDRE": "C", "FDSE": "C", "FDCE": "C", "FDPE": "C", "SRLC32E": "CLK", "RAMD64E": "CLK",
          "RAMD32": "CLK", "DSP48E1": "CLK", "RAMB18E1": "CLKARDCLK", "IDDR": "CLK", "ODDR": "CLK"}
BUF_IN = {"BUFHCE": "I", "BUFGCTRL": "I0", "BUFR": "I", "BUFIO": "I"}


class G:
    def __init__(self, nl):
        self.cells = {c["name"]: c for c in nl["cells"]}
        self.nets = nl["nets"]

    def net(self, cell, pin):
        v = self.cells[cell]["pins"].get(pin)
        return v[0] if v else None

    def driver(self, net):
        if net is None or net.startswith("1'b"):
            return None
        d = self.nets.get(net, {}).get("drivers")
        if not d:
            return None
        c, p = d[0].rsplit(".", 1)
        return c, p

    def sinks(self, net):
        if net is None or net.startswith("1'b"):
            return []
        return [tuple(s.rsplit(".", 1)) for s in self.nets.get(net, {}).get("sinks", [])]

    def ctype(self, cell):
        return self.cells[cell]["type"]

    def clock_root(self, net, path=None):
        """Follow a clock net back through BUFHCE/BUFG/BUFR to its source pin."""
        path = path if path is not None else []
        d = self.driver(net)
        while d and self.ctype(d[0]) in BUF_IN:
            path.append(d[0])
            nd = self.driver(self.net(d[0], BUF_IN[self.ctype(d[0])]))
            if nd is None:      # buffer input not decodable (e.g. BUFR fed by a CMT PERF clock)
                return (d[0], "O(input undecoded)")
            d = nd
        return d

    def clk_of(self, cell):
        ty = self.ctype(cell)
        p = CLKPIN.get(ty)
        if not p:
            return None
        n = self.net(cell, p)
        if n is None or n.startswith("1'b"):
            return None
        d = self.driver(n)
        return d[0] if d else n


def load(path):
    return G(json.load(open(path)))


def pin_maps(db, pkg):
    tg = json.load(open(os.path.join(db, "xc7a50t", "tilegrid.json")))
    pf = {}
    for v in tg.values():
        pf.update(v.get("pin_functions", {}))
    pins = {}
    p = os.path.join(db, pkg, "package_pins.csv")
    if os.path.exists(p):
        pins = {r["site"]: r["pin"] for r in csv.DictReader(open(p))}
    return pf, pins


def iostd(params):
    ks = list(params)
    if any("LVDS_25" in k and (k.endswith(".OUT") or k.endswith("IN_DIFF")) for k in ks):
        return "LVDS_25"
    v18 = any("STEPDOWN" in k for k in ks) or any(k.startswith("LVCMOS18.") or
                                                    k.startswith("LVCMOS12_LVCMOS15_LVCMOS18.") for k in ks)
    return "LVCMOS18" if v18 else "LVCMOS33"


def io_rows(g, db, pkg):
    pf, pins = pin_maps(db, pkg)
    rows = []
    for c in g.cells.values():
        if c["type"] != "IOB":
            continue
        site = c["site"]
        p = c["params"]
        diff_in = any(k.endswith("IN_DIFF") for k in p)
        diff_out = any(k.endswith("LVDS_25.OUT") for k in p)
        has_in = any(k.endswith((".IN", ".IN_ONLY", "IN_DIFF")) for k in p)
        has_out = any(".DRIVE." in k for k in p)
        tnet = g.net(c["name"], "T")
        onet = g.net(c["name"], "O")
        inet = g.net(c["name"], "I")
        loads = g.sinks(inet) if inet else []
        drv = g.driver(onet) if onet else None
        tdrv = g.driver(tnet) if tnet else None
        if has_out and tnet == "1'b0" or (has_out and not tnet):
            d = "out"
        elif has_out and tdrv:
            d = "inout"
        elif has_out:
            d = "out"
        else:
            d = "in"
        if not has_out and not loads and not diff_in:
            d = "in (no load)"
        if has_out and onet in ("1'b0", "1'b1"):
            d += " const %s" % onet[-1]
        rows.append({
            "site": site, "pin": pins.get(site, "?"), "func": pf.get(site, "?"),
            "bank": pf.get(site, "_?").rsplit("_", 1)[-1], "std": iostd(p),
            "dir": d, "diff": "in" if diff_in else ("out" if diff_out else ""),
            "loads": sorted(set("%s.%s" % (g.ctype(x), y) for x, y in loads)),
            "load_cells": [x for x, y in loads], "nloads": len(loads),
            "driver": ("%s.%s" % (g.ctype(drv[0]), drv[1])) if drv else onet,
            "driver_cell": drv[0] if drv else None,
            "tdriver": ("%s.%s" % (g.ctype(tdrv[0]), tdrv[1])) if tdrv else tnet,
            "pull": [k.split(".")[-1] for k in p if k.startswith("PULLTYPE.")],
        })
    rows.sort(key=lambda r: (int(r["site"].split("_X")[1].split("Y")[0]), int(r["site"].split("Y")[-1])))
    return rows


def sync_chain(g, cell):
    """Length of a chain of FFs fed directly by the previous one (synchronizer)."""
    n = 1
    cur = cell
    while True:
        q = g.net(cur, "Q")
        nxt = [x for x, y in g.sinks(q) if y == "D" and g.ctype(x) in FF]
        if len(nxt) != 1 or n > 6:
            return n
        if len(g.sinks(q)) > 1:
            return n
        cur = nxt[0]
        n += 1


def clock_name(g, cell):
    """Readable clock source for a cell: root driver pin through the buffers."""
    ty = g.ctype(cell)
    p = CLKPIN.get(ty)
    if not p:
        return "-"
    n = g.net(cell, p)
    if not n or n.startswith("1'b"):
        return n or "-"
    path = []
    r = g.clock_root(n, path)
    root = "%s.%s" % r if r else "undriven"
    return root + (" via " + path[0] if path else "")


def cmd_clocks(g):
    loads = collections.Counter()
    types = collections.defaultdict(collections.Counter)
    for c in g.cells.values():
        p = CLKPIN.get(c["type"])
        if not p:
            continue
        n = c["pins"].get(p, [None])[0]
        if not n or n.startswith("1'b"):
            continue
        r = g.clock_root(n)
        key = "%s.%s" % r if r else "undriven"
        loads[key] += 1
        types[key][c["type"]] += 1
    print("== clock roots (through BUFHCE/BUFG/BUFR) and their loads")
    for k, v in loads.most_common():
        print("%-34s %6d  %s" % (k, v, dict(types[k])))
    print("== buffers")
    for c in sorted(g.cells.values(), key=lambda c: c["name"]):
        if c["type"] in ("BUFGCTRL", "BUFHCE", "BUFR", "MMCME2_ADV"):
            ins = {p: v[0] for p, v in c["pins"].items() if v[1] == "I" and p in (
                "I", "I0", "I1", "CLKIN1", "CLKIN2", "CLKFBIN", "CE", "CE0", "S0", "RST")}
            src = {}
            for p, n in ins.items():
                d = g.driver(n)
                src[p] = ("%s.%s" % d) if d else n
            outs = {p: len(g.sinks(v[0])) for p, v in c["pins"].items() if v[1] == "O" and g.sinks(v[0])}
            print("%-18s %-10s in %s out %s" % (c["name"], c["type"], src, outs))


def cmd_io(g, db, pkg):
    for r in io_rows(g, db, pkg):
        extra = ""
        ffl = [x for x in r["load_cells"] if g.ctype(x) in FF]
        if ffl:
            extra = " sync%d clk=%s" % (sync_chain(g, ffl[0]), clock_name(g, ffl[0]))
        elif r["load_cells"]:
            extra = " clk=%s" % clock_name(g, r["load_cells"][0])
        if r["driver_cell"]:
            extra += " drvclk=%s" % clock_name(g, r["driver_cell"])
        print("%-10s %-4s b%-3s %-8s %-14s %-4s %-30s in:%s(%d) out:%s T:%s%s" % (
            r["site"], r["pin"], r["bank"], r["std"], r["dir"], r["diff"], r["func"],
            ",".join(r["loads"])[:60], r["nloads"], r["driver"], r["tdriver"], extra))


def cmd_package(g, db):
    used = set(c["site"] for c in g.cells.values() if c["type"] == "IOB")
    for d in sorted(os.listdir(db)):
        p = os.path.join(db, d, "package_pins.csv")
        if d.startswith("xc7a50t") and d.endswith("-1") and os.path.exists(p):
            sites = set(r["site"] for r in csv.DictReader(open(p)))
            miss = used - sites
            print("%-18s bonded IOB sites %3d, used sites not bonded: %d" % (d, len(sites), len(miss)))


def bus(c, base):
    """{index: net} of a bus pin group like A0..A29."""
    out = {}
    for p, v in c["pins"].items():
        m = re.match(r"^%s(\d+)$" % base, p)
        if m:
            out[int(m.group(1))] = v[0]
    return out


def bus_sources(g, c, base):
    srcs = collections.Counter()
    for i, n in bus(c, base).items():
        if n.startswith("1'b"):
            srcs["const"] += 1
            continue
        d = g.driver(n)
        srcs[(g.ctype(d[0]) + ":" + d[0].split("/")[0]) if d else "undriven"] += 1
    return srcs


def dsp_params(c):
    p = c["params"]
    reg = lambda n: 0 if ("Z%s" % n) in p else 1  # noqa: E731  (prjxray Z<reg> = register value 0)
    a_cas = bool(p.get("A_INPUT", 0))
    b_cas = bool(p.get("B_INPUT", 0))
    areg = 0 if p.get("AREG_0") else (2 if p.get("AREG_2") else 1)
    breg = 0 if p.get("BREG_0") else (2 if p.get("BREG_2") else 1)
    return {"AREG": areg, "BREG": breg, "A_INPUT": "CASCADE" if a_cas else "DIRECT",
            "B_INPUT": "CASCADE" if b_cas else "DIRECT", "MREG": reg("MREG"), "PREG": reg("PREG"),
            "CREG": reg("CREG"), "ADREG": reg("ADREG"), "DREG": reg("DREG"),
            "OPMODEREG": reg("OPMODEREG"), "ALUMODEREG": reg("ALUMODEREG"),
            "INMODEREG": reg("INMODEREG"), "CARRYINREG": reg("CARRYINREG"),
            "CARRYINSELREG": reg("CARRYINSELREG"), "USE_DPORT": "TRUE" if p.get("USE_DPORT") else "FALSE",
            "MASK": p.get("MASK", 0), "PATTERN": p.get("PATTERN", 0)}


def const_bus(c, base, width):
    """Integer value of a bus whose pins are all tied to constants, else None."""
    v = 0
    for i in range(width):
        n = c["pins"].get("%s%d" % (base, i), ["1'b0"])[0]
        if not n.startswith("1'b"):
            return None
        v |= int(n[-1]) << i
    return v


def dsp_modes(c):
    """Static OPMODE/ALUMODE/INMODE (None = driven by logic) and a constant A or B operand."""
    return {"OPMODE": const_bus(c, "OPMODE", 7), "ALUMODE": const_bus(c, "ALUMODE", 4),
            "INMODE": const_bus(c, "INMODE", 5), "CARRYINSEL": const_bus(c, "CARRYINSEL", 3),
            "A": const_bus(c, "A", 30), "B": const_bus(c, "B", 18)}


def dsp_chains(g):
    dsps = [c for c in g.cells.values() if c["type"] == "DSP48E1"]
    nxt, prv = {}, {}
    for c in dsps:
        p = dsp_params(c)
        op = const_bus(c, "OPMODE", 7)
        zsel = None if op is None else (op >> 4) & 7
        used = {"A": p["A_INPUT"] == "CASCADE", "B": p["B_INPUT"] == "CASCADE",
                # cascade wires are always physically joined; P is used when OPMODE Z selects PCIN
                "P": zsel in (1, 5) or op is None}
        for pin, kind in (("PCIN0", "P"), ("ACIN0", "A"), ("BCIN0", "B")):
            if not used[kind]:
                continue
            n = c["pins"].get(pin, [None])[0]
            d = g.driver(n) if n else None
            if d and g.ctype(d[0]) == "DSP48E1":
                nxt.setdefault(d[0], []).append((c["name"], kind))
                prv.setdefault(c["name"], []).append((d[0], kind))
    chains = []
    for c in dsps:
        if c["name"] in prv:
            continue
        ch = [c["name"]]
        kinds = []
        while ch[-1] in nxt:
            n, k = nxt[ch[-1]][0]
            kinds.append("".join(sorted(x[1] for x in nxt[ch[-1]])))
            ch.append(n)
        chains.append((ch, kinds))
    return chains


def cmd_dsp(g):
    dsps = sorted((c for c in g.cells.values() if c["type"] == "DSP48E1"), key=lambda c: c["name"])
    cfg = collections.Counter()
    for c in dsps:
        p = dsp_params(c)
        cfg[tuple(sorted((k, v) for k, v in p.items() if k not in ("MASK", "PATTERN")))] += 1
    print("== DSP48E1 register configurations")
    for k, v in cfg.most_common():
        print("%3d  %s" % (v, " ".join("%s=%s" % kv for kv in k)))
    print("== static modes (OPMODE as ZYX octal digits; None = from logic)")
    mc = collections.Counter()
    for c in dsps:
        m = dsp_modes(c)
        mc[("OPMODE=%s" % (None if m["OPMODE"] is None else "%03o" % m["OPMODE"]),
            "ALUMODE=%s" % m["ALUMODE"], "INMODE=%s" % (None if m["INMODE"] is None else format(m["INMODE"], "05b")),
            "constA" if m["A"] is not None else "", "constB" if m["B"] is not None else "")] += 1
    for k, v in mc.most_common():
        print("%3d  %s" % (v, " ".join(x for x in k if x)))
    print("== cascade chains (P = PCOUT->PCIN when OPMODE Z = PCIN, A/B = ACOUT/BCOUT when *_INPUT = CASCADE)")
    for ch, kinds in sorted(dsp_chains(g), key=lambda x: -len(x[0])):
        head = g.cells[ch[0]]
        clk = clock_name(g, ch[0])
        a = bus_sources(g, head, "A")
        b = bus_sources(g, head, "B")
        tail = g.cells[ch[-1]]
        pout = collections.Counter()
        for i, n in bus(tail, "P").items():
            for x, y in g.sinks(n):
                pout[g.ctype(x)] += 1
        print("len %2d %s..%s [%s] clk %s | head A<-%s B<-%s | tail P->%s" % (
            len(ch), ch[0], ch[-1], ",".join(kinds), clk, dict(a.most_common(3)), dict(b.most_common(3)),
            dict(pout)))


def cmd_bram(g):
    for c in sorted((c for c in g.cells.values() if c["type"] == "RAMB18E1"), key=lambda c: c["name"]):
        p = c["params"]
        w = {k: v for k, v in p.items() if re.match(r"^(READ|WRITE)_WIDTH_[AB]_\d+$", k) or "SDP" in k}
        widths = " ".join(sorted(k.replace("_WIDTH", "").replace("READ", "R").replace("WRITE", "W") for k in w))
        dout = collections.Counter()
        for pin, v in c["pins"].items():
            if v[1] == "O" and re.match(r"^DO", pin):
                for x, y in g.sinks(v[0]):
                    dout[g.ctype(x) + ("." + y.rstrip("0123456789") if g.ctype(x) == "DSP48E1" else "")] += 1
        din = collections.Counter()
        for pin, v in c["pins"].items():
            if v[1] == "I" and re.match(r"^DI", pin) and not v[0].startswith("1'b"):
                d = g.driver(v[0])
                if d:
                    din[g.ctype(d[0])] += 1
        wen = [pin for pin, v in c["pins"].items() if pin.startswith("WE") and v[0] not in ("1'b0",)]
        init = any(k.startswith("INIT_") and v for k, v in p.items())
        print("%-14s %-34s init=%d we=%-2d DO->%s DI<-%s clk %s" % (
            c["name"], widths, init, len(wen), dict(dout), dict(din), clock_name(g, c["name"])))


def cmd_cone(g, ref, depth, forward=False):
    if "." in ref:
        cell, pin = ref.rsplit(".", 1)
        starts = [(cell, pin)]
    else:
        cell = ref
        c = g.cells[cell]
        starts = [(cell, p) for p, v in c["pins"].items() if v[1] == ("O" if forward else "I")]
    seen = set()
    frontier = []
    for cell, pin in starts:
        n = g.net(cell, pin)
        frontier.append((n, 0, "%s.%s" % (cell, pin)))
    while frontier:
        n, d, via = frontier.pop(0)
        if n is None or n.startswith("1'b"):
            print("  " * d + "%s = %s" % (via, n))
            continue
        nxt = g.sinks(n) if forward else ([g.driver(n)] if g.driver(n) else [])
        for x in nxt:
            if x is None:
                continue
            c = g.cells[x[0]]
            tag = "%s.%s [%s]" % (x[0], x[1], c["type"])
            if c["type"] in ("LUT6", "LUT6_2"):
                tag += " INIT=%016x" % c["params"]["INIT"]
            print("  " * d + "%s <- %s" % (via, tag) if not forward else "  " * d + "%s -> %s" % (via, tag))
            if x[0] in seen or d >= depth:
                continue
            seen.add(x[0])
            if c["type"] in FF and not forward:
                frontier.append((g.net(x[0], "D"), d + 1, x[0] + ".D"))
            elif not forward:
                for p, v in c["pins"].items():
                    if v[1] == "I" and not (p in ("C", "CLK", "CE", "R", "S", "CLR", "PRE")):
                        frontier.append((v[0], d + 1, "%s.%s" % (x[0], p)))
            else:
                for p, v in c["pins"].items():
                    if v[1] == "O":
                        frontier.append((v[0], d + 1, "%s.%s" % (x[0], p)))


# ------------------------------------------------------------------ logic equations

def lut_function(c, out="O"):
    """(list of (pin, net) of real inputs, truth table over them as int) for a LUT
    output, with constant inputs folded and inputs it does not depend on removed."""
    init = c["params"]["INIT"]
    n6 = c["type"] == "LUT6_2" and out == "O5"
    pins = ["I%d" % i for i in range(6)]
    ins = [c["pins"].get(p, ["1'b1"])[0] for p in pins]
    if n6:
        init &= 0xFFFFFFFF
        ins[5] = "1'b0"

    def val(assign):
        idx = 0
        for i in range(6):
            idx |= assign[i] << i
        return (init >> idx) & 1
    free = [i for i in range(6) if not ins[i].startswith("1'b")]
    fixed = {i: int(ins[i][-1]) for i in range(6) if ins[i].startswith("1'b")}
    # drop inputs the function does not depend on
    dep = []
    for i in free:
        others = [j for j in free if j != i]
        d = False
        for m in range(1 << len(others)):
            a = dict(fixed)
            for k, j in enumerate(others):
                a[j] = (m >> k) & 1
            a0, a1 = dict(a), dict(a)
            a0[i], a1[i] = 0, 1
            if val([a0.get(x, 0) for x in range(6)]) != val([a1.get(x, 0) for x in range(6)]):
                d = True
                break
        if d:
            dep.append(i)
    tt = 0
    for m in range(1 << len(dep)):
        a = dict(fixed)
        for j in free:
            a[j] = 0
        for k, j in enumerate(dep):
            a[j] = (m >> k) & 1
        tt |= val([a.get(x, 0) for x in range(6)]) << m
    return [(pins[i], ins[i]) for i in dep], tt


def sop(names, tt):
    """Minimal-ish sum of products (Quine-McCluskey primes + greedy cover)."""
    n = len(names)
    ones = [m for m in range(1 << n) if (tt >> m) & 1]
    if not ones:
        return "0"
    if len(ones) == 1 << n:
        return "1"
    terms = set((m, 0) for m in ones)       # (value, dontcare mask)
    primes = set()
    while terms:
        nxt = set()
        used = set()
        tl = sorted(terms)
        for i, (v1, d1) in enumerate(tl):
            for v2, d2 in tl[i + 1:]:
                if d1 == d2 and bin(v1 ^ v2).count("1") == 1:
                    nxt.add((v1 & v2, d1 | (v1 ^ v2)))
                    used.add((v1, d1))
                    used.add((v2, d2))
        primes |= terms - used
        terms = nxt
    cover, left = [], set(ones)
    while left:
        best = max(primes, key=lambda p: sum(1 for m in left if (m & ~p[1]) == p[0]))
        cover.append(best)
        left -= set(m for m in left if (m & ~best[1]) == best[0])
    out = []
    for v, d in cover:
        lits = [("" if (v >> i) & 1 else "~") + names[i] for i in range(n) if not (d >> i) & 1]
        out.append("&".join(lits) if lits else "1")
    return " | ".join(out)


def short(g, net):
    if net is None:
        return "?"
    if net.startswith("1'b"):
        return net[-1]
    d = g.driver(net)
    if not d:
        return net
    c, p = d
    ty = g.ctype(c)
    if ty == "IOB":
        return "PIN_" + g.cells[c]["site"]
    return c + ("" if p in ("Q", "O") else "." + p)


def equation(g, cname):
    c = g.cells[cname]
    ty = c["type"]
    if ty in ("LUT6", "LUT6_2"):
        res = []
        for o in (("O",) if ty == "LUT6" else ("O6", "O5")):
            if not g.sinks(c["pins"][o][0]):
                continue
            ins, tt = lut_function(c, o)
            names = [short(g, n) for _, n in ins]
            res.append("%s%s = %s" % (cname, "" if o == "O" else "." + o, sop(names, tt)))
        return res
    if ty in FF:
        p = c["pins"]
        rp = [k for k in ("R", "S", "CLR", "PRE") if k in p][0]
        s = "%s <= %s" % (cname, short(g, p["D"][0]))
        ce = short(g, p["CE"][0])
        rs = short(g, p[rp][0])
        if ce != "1":
            s += "  if %s" % ce
        if rs != "0":
            s += "  %s=%s" % (rp, rs)
        return [s + "  (%s INIT=%d)" % (ty, c["params"].get("INIT", 0))]
    if ty == "CARRY4":
        p = c["pins"]
        return ["%s CARRY4 CI=%s CYINIT=%s S=[%s] DI=[%s]" % (
            cname, short(g, p["CI"][0]), short(g, p["CYINIT"][0]),
            ",".join(short(g, p["S[%d]" % i][0]) for i in range(4)),
            ",".join(short(g, p["DI[%d]" % i][0]) for i in range(4)))]
    return ["%s %s" % (cname, ty)]


def cmd_logic(g, seeds, depth):
    """Print equations for the cells within DEPTH steps (both directions, not through
    clocks/resets) of the seed cells."""
    cells = set()
    frontier = []
    for s in seeds:
        if s in g.cells:
            frontier.append(s)
    for _ in range(depth + 1):
        nf = []
        for c in frontier:
            if c in cells:
                continue
            cells.add(c)
            cc = g.cells[c]
            if cc["type"] in ("BUFGCTRL", "BUFHCE", "DSP48E1", "RAMB18E1", "MMCME2_ADV"):
                continue
            for p, v in cc["pins"].items():
                if p in ("C", "CLK", "R", "S", "CLR", "PRE"):
                    continue
                if v[1] == "I":
                    d = g.driver(v[0])
                    if d:
                        nf.append(d[0])
                else:
                    nf += [x for x, y in g.sinks(v[0])]
        frontier = nf
    for c in sorted(cells):
        for line in equation(g, c):
            print(line)


def cmd_region(g, pat):
    rx = re.compile(pat)
    cnt = collections.Counter()
    clk = collections.Counter()
    for c in g.cells.values():
        if rx.search(c["site"]):
            cnt[c["type"]] += 1
            clk[clock_name(g, c["name"])] += 1
    print(dict(cnt))
    print(dict(clk))


def selftest():
    nl = {"cells": [
        {"name": "B", "type": "BUFGCTRL", "site": "BUFGCTRL_X0Y0", "params": {},
         "pins": {"I0": ["n0", "I"], "O": ["n1", "O"]}},
        {"name": "IO", "type": "IOB", "site": "IOB_X0Y1", "params": {"IOB_Y1.LVCMOS25_LVCMOS33_LVTTL.IN": 1},
         "pins": {"I": ["n0", "O"]}},
        {"name": "IN", "type": "IOB", "site": "IOB_X0Y2", "params": {"IOB_Y0.X.IN_ONLY": 1},
         "pins": {"I": ["n2", "O"]}},
        {"name": "F1", "type": "FDRE", "site": "SLICE_X0Y0", "params": {},
         "pins": {"C": ["n1", "I"], "D": ["n2", "I"], "Q": ["n3", "O"]}},
        {"name": "F2", "type": "FDRE", "site": "SLICE_X0Y0", "params": {},
         "pins": {"C": ["n1", "I"], "D": ["n3", "I"], "Q": ["n4", "O"]}},
    ], "nets": {
        "n0": {"drivers": ["IO.I"], "sinks": ["B.I0"]}, "n1": {"drivers": ["B.O"], "sinks": ["F1.C", "F2.C"]},
        "n2": {"drivers": ["IN.I"], "sinks": ["F1.D"]}, "n3": {"drivers": ["F1.Q"], "sinks": ["F2.D"]},
        "n4": {"drivers": ["F2.Q"], "sinks": []}}}
    g = G(nl)
    assert g.clock_root("n1") == ("IO", "I"), g.clock_root("n1")
    assert sync_chain(g, "F1") == 2, sync_chain(g, "F1")
    assert clock_name(g, "F2") == "IO.I via B", clock_name(g, "F2")
    assert iostd({"IOB_Y0.LVDS_25_SSTL135_SSTL15.IN_DIFF": 1}) == "LVDS_25"
    assert iostd({"IOB_Y0.LVCMOS18.DRIVE.I12_I8": 1, "IOB_Y0.STEPDOWN": 1}) == "LVCMOS18"
    print("selftest: clock root through BUFG, 2-FF synchronizer, IOSTANDARD guess: ok")


def main():
    a = sys.argv[1:]
    db = DEFAULT_DB
    if "--db" in a:
        i = a.index("--db")
        db = a[i + 1]
        del a[i:i + 2]
    if a and a[0] == "selftest":
        return selftest()
    if len(a) < 2:
        sys.exit(__doc__)
    g = load(a[0])
    cmd = a[1]
    if cmd == "clocks":
        cmd_clocks(g)
    elif cmd == "io":
        cmd_io(g, db, a[2] if len(a) > 2 else "xc7a50tcsg324-1")
    elif cmd == "package":
        cmd_package(g, db)
    elif cmd == "dsp":
        cmd_dsp(g)
    elif cmd == "bram":
        cmd_bram(g)
    elif cmd in ("cone", "fanout"):
        cmd_cone(g, a[2], int(a[3]) if len(a) > 3 else 3, forward=(cmd == "fanout"))
    elif cmd == "region":
        cmd_region(g, a[2])
    elif cmd == "logic":
        cmd_logic(g, a[2].split(","), int(a[3]) if len(a) > 3 else 1)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
