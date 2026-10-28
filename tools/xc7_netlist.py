#!/usr/bin/env python3
"""FASM -> cell-level netlist for 7-series (T15b). Stdlib only.

Written for T15 (FT-710 SDR image, XC7A50T). Reads a FASM file produced by
tools/xc7_fasm.py and the prjxray-db (tilegrid, tileconn, tile_type_*.json,
site_type_*.json, ppips_*.db) and writes a JSON netlist of UNISIM-level cells
(LUT6/LUT6_2, FDRE/FDSE/FDCE/FDPE/LDCE/LDPE, CARRY4, MUXF7/MUXF8, SRLC32E,
RAMD64E, DSP48E1, RAMB18E1/RAMB36E1, IOB/ILOGIC/OLOGIC/IDELAY, MMCME2_ADV,
BUFGCTRL, BUFHCE, BUFR, ...) with their recovered parameters and nets.

Usage:
    python3 -I tools/xc7_netlist.py build IN.fasm OUT.json [--db DBDIR]
    python3 -I tools/xc7_netlist.py stats OUT.json
    python3 -I tools/xc7_netlist.py net OUT.json NETNAME|CELLNAME     (show a net / a cell)
    python3 -I tools/xc7_netlist.py selftest [--db DBDIR]

How it works:
  * Routing. A node is a set of (tile, wire) joined by tileconn.json wire
    pairs (prjxray's definition). Nodes are built lazily, only for wires that an
    active PIP or a site pin touches. Active PIPs are FASM features TILE.DST.SRC
    (any tile type; also INT long-line features LVx.LVy), plus the "always"
    pseudo-PIPs of ppips_*.db. A net is a union of nodes joined by active PIPs.
    Wires named VCC_WIRE/GND_WIRE and tile-local *_VCC_*/*_GND_* tie-offs make a
    net constant.
  * Sites. FASM site features (SLICEL_X0.*, DSP48.DSP_0.*, RAMB18_Y1.*,
    IOB_Y0.*, BUFGCTRL.BUFGCTRL_X0Y3.*, ...) are mapped to real site names via
    tile_type_*.json site coordinates. Site pins and their direction come from
    tile_type_*.json and site_type_*.json.
  * SLICE model (UG474): per BEL letter, LUT6 (or LUT6_2 when O5 is used), the
    FF and 5FF with their D muxes (xFFMUX, x5FFMUX), CARRY4 (PRECYINIT, xCY0),
    MUXF7/MUXF8, output muxes (xOUTMUX), SLICEM LUT RAM (RAMD64E) and SRL
    (SRLC32E). FF type from FFSYNC/LATCH/ZRST, INIT from ZINI (Z = inverted).
  * Hard blocks keep all routed site pins (grouped into buses) and their FASM
    features as parameters; tools/xc7_netlist_verilog.py turns those into UNISIM
    parameters.

Not modelled / approximations (flagged in the JSON as "approx"): 32-deep
(SMALL) LUT RAM/SRL16 halves, LUT RAM wider than 64 (WA7/WA8 are connected but
not merged into RAM128/256), IDELAY taps, ISERDES modes other than the default
pass-through, and DSP48E1 USE_MULT (not in prjxray-db).
"""
import collections
import json
import os
import re
import sys

DEFAULT_DB = os.environ.get(
    "PRJXRAY_DB", os.path.expanduser("~/.local/share/ft710-tools/prjxray-db/artix7"))
FEAT = re.compile(r"^([A-Za-z0-9_]+?_X\d+Y\d+)\.(.+)$")
VAL = re.compile(r"^(\d+)'([bh])([0-9a-fA-F_]+)$")
RANGE = re.compile(r"^(.*)\[(\d+)(?::(\d+))?\]$")
CONST_WIRE = re.compile(r"(^|_)(VCC|GND)(_|$)")


# ------------------------------------------------------------------ FASM

def read_fasm(lines):
    """-> {tile: {feature: int}}; multi-bit features are merged into one int
    under the base name (e.g. 'SLICEL_X0.ALUT.INIT' -> 64-bit int), plain
    features map to 1."""
    out = collections.defaultdict(dict)
    for line in lines:
        line = line.split("#", 1)[0].split("{", 1)[0].strip()
        if not line:
            continue
        val = 1
        if "=" in line:
            line, v = (x.strip() for x in line.split("=", 1))
            m = VAL.match(v)
            if not m:
                continue
            val = int(m.group(3).replace("_", ""), 2 if m.group(2) == "b" else 16)
        m = FEAT.match(line)
        if not m:
            continue
        tile, feat = m.group(1), m.group(2)
        r = RANGE.match(feat)
        d = out[tile]
        if r:
            base, hi, lo = r.group(1), int(r.group(2)), r.group(3)
            lo = int(lo) if lo is not None else hi
            d[base] = d.get(base, 0) | (val << lo)
            d.setdefault("#w:" + base, 0)
            d["#w:" + base] = max(d["#w:" + base], hi + 1)
        else:
            d[feat] = val
    return out


# ------------------------------------------------------------------ database

class DB:
    def __init__(self, db):
        self.db = db
        self.tg = json.load(open(os.path.join(db, "xc7a50t", "tilegrid.json")))
        self.tiles = sorted(self.tg)
        self.tidx = {t: i for i, t in enumerate(self.tiles)}
        self.ttype = [self.tg[t]["type"] for t in self.tiles]
        self.grid = {}
        for i, t in enumerate(self.tiles):
            self.grid[(self.tg[t]["grid_x"], self.tg[t]["grid_y"])] = i
        self.xy = [(self.tg[t]["grid_x"], self.tg[t]["grid_y"]) for t in self.tiles]
        self.conn = collections.defaultdict(list)
        for r in json.load(open(os.path.join(db, "xc7a50t", "tileconn.json"))):
            (dx, dy), (ta, tb) = r["grid_deltas"], r["tile_types"]
            for wa, wb in r["wire_pairs"]:
                self.conn[(ta, wa)].append((dx, dy, tb, wb))
                self.conn[(tb, wb)].append((-dx, -dy, ta, wa))
        self._tt = {}
        self._st = {}
        self._always = {}

    def tile_type(self, ty):
        if ty not in self._tt:
            p = os.path.join(self.db, "tile_type_%s.json" % ty)
            if os.path.exists(p):
                j = json.load(open(p))
                pips = set()
                for k in j["pips"]:
                    src, dst = re.split(r"<?->>?", k.split(".", 1)[1])
                    pips.add((dst, src))
                j = {"wires": set(j["wires"]), "pips": pips, "sites": j["sites"]}
            else:
                j = {"wires": set(), "pips": set(), "sites": []}
            self._tt[ty] = j
        return self._tt[ty]

    def site_type(self, st):
        if st not in self._st:
            p = os.path.join(self.db, "site_type_%s.json" % st)
            self._st[st] = json.load(open(p))["site_pins"] if os.path.exists(p) else {}
        return self._st[st]

    def always(self, ty):
        """{wire: [other wires]} of 'always' pseudo-PIPs of a tile type."""
        if ty not in self._always:
            m = collections.defaultdict(list)
            p = os.path.join(self.db, "ppips_%s.db" % ty.lower())
            if os.path.exists(p):
                for line in open(p):
                    f = line.split()
                    if len(f) == 2 and f[1] == "always":
                        _, dst, src = f[0].split(".", 2)
                        m[dst].append(src)
                        m[src].append(dst)
            self._always[ty] = m
        return self._always[ty]

    def sites_of(self, tile):
        """[(tile_type site dict, real site name, real site type)] for a tile."""
        tv = self.tg[tile]
        real = tv["sites"]
        byprefix = collections.defaultdict(list)
        for s in real:
            m = re.match(r"^(.*)_X(\d+)Y(\d+)$", s)
            byprefix[m.group(1)].append((int(m.group(2)), int(m.group(3)), s))
        out = []
        for st in self.tile_type(tv["type"])["sites"]:
            cand = byprefix.get(st["prefix"], [])
            if not cand:
                continue
            mx = min(c[0] for c in cand)
            my = min(c[1] for c in cand)
            name = "%s_X%dY%d" % (st["prefix"], mx + st["x_coord"], my + st["y_coord"])
            if name in real:
                out.append((st, name, real[name]))
        return out


def fasm_site_prefix(st, name):
    """FASM feature prefix for a site (prjxray naming)."""
    pre, ty = st["prefix"], st["type"]
    y = int(name.rsplit("Y", 1)[1])
    if pre == "SLICE":
        return "%s_X%d" % (ty, st["x_coord"])
    if pre == "DSP48":
        return "DSP48.DSP_%d" % (y % 2)
    if pre == "RAMB18":
        return "RAMB18_Y%d" % (y % 2)
    if pre == "RAMB36":
        return "RAMB36"
    if pre in ("IOB", "ILOGIC", "OLOGIC", "IDELAY"):
        return "%s_Y%d" % (pre, y % 2)
    if pre in ("BUFGCTRL", "BUFHCE"):
        return "%s.%s_X%dY%d" % (pre, pre, st["x_coord"], st["y_coord"])
    if pre == "BUFR":
        return "BUFR_Y%d" % st["y_coord"]
    return pre if pre in ("MMCME2_ADV", "PLLE2_ADV") else ty


# ------------------------------------------------------------------ routing

class Router:
    def __init__(self, db):
        self.db = db
        self.node_of = {}       # (tile_idx, wire) -> node id
        self.nodes = []         # node id -> list of (tile_idx, wire)
        self.parent = []        # union-find over node ids
        self.npips = 0
        self.const = {}         # node id -> 0/1

    def node(self, ti, wire):
        k = (ti, wire)
        n = self.node_of.get(k)
        if n is not None:
            return n
        n = len(self.nodes)
        members = [k]
        self.node_of[k] = n
        stack = [k]
        db = self.db
        while stack:
            t, w = stack.pop()
            ty = db.ttype[t]
            x, y = db.xy[t]
            for dx, dy, oty, ow in db.conn.get((ty, w), ()):
                o = db.grid.get((x + dx, y + dy))
                if o is None or db.ttype[o] != oty:
                    continue
                kk = (o, ow)
                if kk not in self.node_of:
                    self.node_of[kk] = n
                    members.append(kk)
                    stack.append(kk)
        self.nodes.append(members)
        self.parent.append(n)
        for t, w in members:
            m = CONST_WIRE.search(w)
            if m and not w.startswith(("CLK", "GCLK")):
                self.const[n] = 1 if m.group(2) == "VCC" else 0
        # always-on pseudo PIPs reachable from this node
        for t, w in members:
            for ow in db.always(db.ttype[t]).get(w, ()):
                self.union(n, self.node(t, ow))
        return n

    def find(self, a):
        p = self.parent
        while p[a] != a:
            p[a] = p[p[a]]
            a = p[a]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if a < b:
                a, b = b, a
            self.parent[a] = b

    def add_pip(self, ti, dst, src):
        self.npips += 1
        self.union(self.node(ti, src), self.node(ti, dst))


# ------------------------------------------------------------------ netlist

class Netlist:
    """Union-find over arbitrary keys: ('n', node), ('i', internal name), ('c', 0/1)."""

    def __init__(self, router):
        self.r = router
        self.parent = {}
        self.cells = []

    def find(self, k):
        if k[0] == "n":
            return ("n", self.r.find(k[1]))
        p = self.parent
        if k not in p:
            return k
        root = k
        while root in p and p[root] != root:
            root = p[root]
        while k != root:
            nxt = p[k]
            p[k] = root
            k = nxt
        return root

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return
        if a[0] == "c":
            a, b = b, a
        if a[0] == "n" and b[0] == "n":
            self.r.union(a[1], b[1])
        elif a[0] == "n":           # keep node as representative
            self.parent[b] = a
        else:
            self.parent[a] = b

    def cell(self, name, ctype, site, params=None, pins=None, approx=None):
        c = {"name": name, "type": ctype, "site": site, "params": params or {}, "pins": pins or {}}
        if approx:
            c["approx"] = approx
        self.cells.append(c)
        return c


VCC, GND = ("c", 1), ("c", 0)


def build(fasm_lines, db, progress=False):
    feats = read_fasm(fasm_lines)
    r = Router(db)
    nl = Netlist(r)
    site_feats = {}
    # 1. PIPs
    for tile, fs in feats.items():
        if tile not in db.tidx:
            continue
        ti = db.tidx[tile]
        tt = db.tile_type(db.ttype[ti])
        rest = {}
        for f, v in fs.items():
            parts = f.split(".")
            if len(parts) == 2 and ((parts[0], parts[1]) in tt["pips"]
                                    or (parts[0] in tt["wires"] and parts[1] in tt["wires"])):
                r.add_pip(ti, parts[0], parts[1])
            else:
                rest[f] = v
        site_feats[tile] = rest
    if progress:
        print("pips: %d, nodes: %d" % (r.npips, len(r.nodes)), file=sys.stderr)
    # 2. sites
    nsites = collections.Counter()
    for tile in sorted(site_feats):
        fs = site_feats[tile]
        if not fs:
            continue
        ti = db.tidx[tile]
        for st, name, sty in db.sites_of(tile):
            pre = fasm_site_prefix(st, name) + "."
            sf = {k[len(pre):]: v for k, v in fs.items() if k.startswith(pre)}
            sfw = {k[len("#w:") + len(pre):]: v for k, v in fs.items() if k.startswith("#w:" + pre)}
            pinkey = {}
            for pin, pv in st["site_pins"].items():
                w = pv.get("wire") if isinstance(pv, dict) else pv
                if w:
                    pinkey[pin] = ("n", r.node(ti, w))
            dirs = {p: v.get("direction") for p, v in db.site_type(sty).items()}
            fn = SITE_HANDLERS.get(st["prefix"])
            if fn and sf:
                fn(nl, name, sty, sf, sfw, pinkey, dirs, tile, fs)
                nsites[sty] += 1
    if progress:
        print("sites: %s" % dict(nsites), file=sys.stderr)
    return finish(nl, db)


def finish(nl, db):
    r = nl.r
    # resolve pin keys to net ids, name nets, mark constants and drivers
    names = {}
    nets = collections.defaultdict(lambda: {"drivers": [], "sinks": []})
    cells = []
    for c in nl.cells:
        pins = {}
        for p, (k, d) in c["pins"].items():
            root = nl.find(k)
            if root[0] == "n" and root[1] in const_roots(r):
                root = ("c", const_roots(r)[root[1]])
            if root[0] == "c":
                pins[p] = ["1'b%d" % root[1], d]
                continue
            if root not in names:
                names[root] = "n%d" % len(names)
            nm = names[root]
            pins[p] = [nm, d]
            nets[nm]["drivers" if d == "O" else "sinks"].append("%s.%s" % (c["name"], p))
        c = dict(c, pins=pins)
        cells.append(c)
    # drop nets with no driver and a single sink? keep: they show up as undriven
    for nm, v in nets.items():
        if len(v["drivers"]) == 1:
            v["name"] = v["drivers"][0]
    return {"cells": cells, "nets": nets, "stats": {"pips": r.npips, "nodes": len(r.nodes)}}


_CR = {}


def const_roots(r):
    if r not in _CR:
        m = {}
        for n, v in r.const.items():
            m[r.find(n)] = v
        _CR.clear()
        _CR[r] = m
    return _CR[r]


def bus_pins(pinkey, dirs, skip=()):
    """Site pins -> {pin: (key, 'I'/'O')} for every pin with a routed wire."""
    out = {}
    for p, k in pinkey.items():
        if p in skip:
            continue
        out[p] = (k, "O" if dirs.get(p) == "OUT" else "I")
    return out


# ------------------------------------------------------------------ SLICE

def slice_handler(nl, site, sty, f, fw, pk, dirs, tile, tfs):
    S = site + "/"
    I = lambda n: ("i", S + n)  # noqa: E731
    P = lambda n: pk[n]  # noqa: E731
    m = sty == "SLICEM"
    clk = P("CLK")
    ce = P("CE") if f.get("CEUSEDMUX") else VCC
    sr = P("SR") if f.get("SRUSEDMUX") else GND
    clkinv = 0 if f.get("NOCLKINV") else 1
    o6, o5, xor, cy = {}, {}, {}, {}
    used_o5 = set()
    mc31 = {}
    for L in "ABCD":
        o6[L] = P(L)            # pin X is O6 directly
        o5[L] = I(L + "5")
        xor[L] = I(L + "_XOR")
        cy[L] = I(L + "_CY")
        mc31[L] = I(L + "_MC31")
    for L in "ABCD":
        sel = [k.split(".")[1] for k in f if k.startswith(L + "FFMUX.") or k.startswith(L + "OUTMUX.")
               or k.startswith(L + "5FFMUX.")]
        if "O5" in sel or "IN_A" in sel:
            used_o5.add(L)
        if ("CARRY4.%sCY0" % L) in f:
            used_o5.add(L)
    # carry
    carry_used = any(k.startswith("PRECYINIT.") for k in f) or any(
        k.endswith((".XOR", ".CY")) for k in f)
    if carry_used:
        if f.get("PRECYINIT.CIN"):
            ci, cyinit = P("CIN"), GND
        elif f.get("PRECYINIT.AX"):
            ci, cyinit = GND, P("AX")
        elif f.get("PRECYINIT.C1"):
            ci, cyinit = GND, VCC
        else:
            ci, cyinit = GND, GND
        pins = {"CI": (ci, "I"), "CYINIT": (cyinit, "I")}
        for i, L in enumerate("ABCD"):
            pins["S[%d]" % i] = (o6[L], "I")
            pins["DI[%d]" % i] = (o5[L] if f.get("CARRY4.%sCY0" % L) else P(L + "X"), "I")
            pins["O[%d]" % i] = (xor[L], "O")
            pins["CO[%d]" % i] = (P("COUT") if L == "D" else cy[L], "O")
        nl.union(cy["D"], P("COUT"))
        nl.cell(S + "CARRY4", "CARRY4", site, {}, pins)
    # F7/F8
    f7a = any(k in f for k in ("AFFMUX.F7", "AOUTMUX.F7"))
    f7b = any(k in f for k in ("CFFMUX.F7", "COUTMUX.F7"))
    f8 = any(k in f for k in ("BFFMUX.F8", "BOUTMUX.F8"))
    if f7a or f8:
        nl.cell(S + "F7AMUX", "MUXF7", site, {}, {"I0": (o6["B"], "I"), "I1": (o6["A"], "I"),
                                                   "S": (P("AX"), "I"), "O": (I("F7A"), "O")})
    if f7b or f8:
        nl.cell(S + "F7BMUX", "MUXF7", site, {}, {"I0": (o6["D"], "I"), "I1": (o6["C"], "I"),
                                                   "S": (P("CX"), "I"), "O": (I("F7B"), "O")})
    if f8:
        nl.cell(S + "F8MUX", "MUXF8", site, {}, {"I0": (I("F7B"), "I"), "I1": (I("F7A"), "I"),
                                                  "S": (P("BX"), "I"), "O": (I("F8"), "O")})
    fsrc = {"F7": {"A": I("F7A"), "C": I("F7B")}, "F8": {"B": I("F8")}}

    def src(L, sel):
        if sel == "O6":
            return o6[L]
        if sel == "O5":
            return o5[L]
        if sel == "XOR":
            return xor[L]
        if sel == "CY":
            return cy[L]
        if sel in ("F7", "F8"):
            return fsrc[sel][L]
        if sel == "MC31":
            return mc31[L]
        if sel == L + "X" or sel == "IN_B":
            return P(L + "X")
        if sel == "IN_A":
            return o5[L]
        if sel == L + "5Q":
            return I(L + "5Q")
        return None
    # LUTs
    for L in "ABCD":
        init = f.get(L + "LUT.INIT")
        is_ram = f.get(L + "LUT.RAM")
        is_srl = f.get(L + "LUT.SRL")
        small = f.get(L + "LUT.SMALL")
        ins = {"I%d" % i: (P("%s%d" % (L, i + 1)), "I") for i in range(6)}
        if init is None and not (is_ram or is_srl):
            # LUT may still be a route-through (no INIT) - nothing to emit
            continue
        init = init or 0
        approx = []
        if m and (is_ram or is_srl):
            di1 = [k.split(".")[2] for k in f if k.startswith(L + "LUT.DI1MUX.")]
            if L == "D" or not di1:
                d = P("DI") if L == "D" else P(L + "I")
            elif di1[0] in ("AI", "BI", "CI"):
                d = P(di1[0])
            else:
                nxt = {"A": "B", "B": "C", "C": "D"}[L]
                d = mc31[nxt] if is_srl else I(nxt + "_DI1")
            nl.union(I(L + "_DI1"), d)
            we = P("CE") if f.get("WEMUX.CE") else P("WE")
            if small:
                approx.append("SMALL (32-deep / dual 32) mode modelled as one 64/32-deep cell")
            if is_srl:
                pins = {"A[%d]" % i: (P("%s%d" % (L, i + 2)), "I") for i in range(5)}
                pins.update({"D": (d, "I"), "CE": (we, "I"), "CLK": (clk, "I"),
                             "Q": (o6[L], "O"), "Q31": (mc31[L], "O")})
                nl.cell(S + L + "LUT", "SRLC32E", site, {"INIT": init & 0xFFFFFFFF, "#w:INIT": 32,
                                                         "IS_CLK_INVERTED": clkinv}, pins, approx)
            else:
                pins = {"RADR%d" % i: (P("%s%d" % (L, i + 1)), "I") for i in range(6)}
                pins.update({"WADR%d" % i: (P("D%d" % (i + 1)), "I") for i in range(6)})
                if f.get("WA7USED"):
                    pins["WADR6"] = (P("CX"), "I")
                if f.get("WA8USED"):
                    pins["WADR7"] = (P("BX"), "I")
                pins.update({"I": (d, "I"), "WE": (we, "I"), "CLK": (clk, "I"), "O": (o6[L], "O")})
                nl.cell(S + L + "LUT", "RAMD64E", site, {"INIT": init, "#w:INIT": 64,
                                                         "IS_CLK_INVERTED": clkinv}, pins, approx)
            continue
        if L in used_o5:
            pins = dict(ins, O6=(o6[L], "O"), O5=(o5[L], "O"))
            nl.cell(S + L + "LUT", "LUT6_2", site, {"INIT": init, "#w:INIT": 64}, pins)
        else:
            pins = dict(ins, O=(o6[L], "O"))
            nl.cell(S + L + "LUT", "LUT6", site, {"INIT": init, "#w:INIT": 64}, pins)
    # FFs
    sync = bool(f.get("FFSYNC"))
    latch = bool(f.get("LATCH"))
    for L in "ABCD":
        for ff, mux, q in ((L + "FF", L + "FFMUX.", P(L + "Q")), (L + "5FF", L + "5FFMUX.", I(L + "5Q"))):
            sel = [k[len(mux):] for k in f if k.startswith(mux)]
            if not sel:
                continue
            d = src(L, sel[0])
            zrst = bool(f.get(ff + ".ZRST"))
            init = 0 if f.get(ff + ".ZINI") else 1
            if latch and ff == L + "FF":
                ty, rp = ("LDCE", "CLR") if zrst else ("LDPE", "PRE")
                pins = {"D": (d, "I"), "G": (clk, "I"), "GE": (ce, "I"), rp: (sr, "I"), "Q": (q, "O")}
                params = {"INIT": init, "IS_G_INVERTED": clkinv}
            else:
                if sync:
                    ty, rp = ("FDRE", "R") if zrst else ("FDSE", "S")
                else:
                    ty, rp = ("FDCE", "CLR") if zrst else ("FDPE", "PRE")
                pins = {"D": (d, "I"), "C": (clk, "I"), "CE": (ce, "I"), rp: (sr, "I"), "Q": (q, "O")}
                params = {"INIT": init, "IS_C_INVERTED": clkinv}
            nl.cell(S + ff, ty, site, params, pins)
    # output muxes: XMUX pin = selected source
    for L in "ABCD":
        sel = [k.split(".")[1] for k in f if k.startswith(L + "OUTMUX.")]
        if sel and (L + "MUX") in pk:
            s = src(L, sel[0])
            if s is not None:
                nl.union(P(L + "MUX"), s)


# ------------------------------------------------------------------ hard sites

def generic_handler(ctype, in_use=None):
    def h(nl, site, sty, f, fw, pk, dirs, tile, tfs):
        if in_use and not any(k.startswith(in_use) for k in f):
            return
        params = dict(f)
        params.update({"#w:" + k: v for k, v in fw.items()})
        nl.cell(site, ctype or sty, site, params, bus_pins(pk, dirs))
    return h


def bram18_handler(nl, site, sty, f, fw, pk, dirs, tile, tfs):
    if not f.get("IN_USE"):
        return
    params = dict(f)
    params.update({"#w:" + k: v for k, v in fw.items()})
    nl.cell(site, "RAMB18E1", site, params, bus_pins(pk, dirs))


def bram36_handler(nl, site, sty, f, fw, pk, dirs, tile, tfs):
    # recorded as tile-level RAMB36 options; the RAMB18 halves carry the cells
    pass


def iob_handler(nl, site, sty, f, fw, pk, dirs, tile, tfs):
    keys = list(f)
    if not any(("IN" in k or "DRIVE" in k or "OUT" in k) for k in keys):
        return
    params = dict(f)
    nl.cell(site, "IOB", site, params, bus_pins(pk, dirs))


def ilogic_handler(nl, site, sty, f, fw, pk, dirs, tile, tfs):
    params = dict(f)
    pins = bus_pins(pk, dirs)
    if f.get("IDDR.IN_USE"):
        nl.cell(site, "IDDR", site, params, pins)
    else:
        # default pass-through: D -> O (ILOGIC combinatorial path)
        if "D" in pk and "O" in pk:
            nl.union(pk["O"], pk["D"])
        nl.cell(site, "ILOGIC_BYPASS", site, params, pins, ["pass-through D->O assumed"])


def ologic_handler(nl, site, sty, f, fw, pk, dirs, tile, tfs):
    params = dict(f)
    pins = bus_pins(pk, dirs)
    if f.get("ODDR_TDDR.IN_USE") or f.get("OSERDES.DATA_RATE_OQ.DDR"):
        nl.cell(site, "ODDR", site, params, pins)
    else:
        if f.get("OMUX.D1") and "D1" in pk and "OQ" in pk:
            nl.union(pk["OQ"], pk["D1"])
        if "T1" in pk and "TQ" in pk and f.get("OSERDES.DATA_RATE_TQ.BUF"):
            nl.union(pk["TQ"], pk["T1"])
        nl.cell(site, "OLOGIC_BYPASS", site, params, pins, ["pass-through D1->OQ, T1->TQ assumed"])


def idelay_handler(nl, site, sty, f, fw, pk, dirs, tile, tfs):
    if not any(k != "IDELAY_TYPE_FIXED" for k in f) and not f:
        return
    params = dict(f)
    params.update({"#w:" + k: v for k, v in fw.items()})
    nl.cell(site, "IDELAYE2", site, params, bus_pins(pk, dirs), ["taps not decoded"])


SITE_HANDLERS = {
    "SLICE": slice_handler,
    "DSP48": generic_handler("DSP48E1"),
    "RAMB18": bram18_handler,
    "RAMB36": bram36_handler,
    "IOB": iob_handler,
    "ILOGIC": ilogic_handler,
    "OLOGIC": ologic_handler,
    "IDELAY": idelay_handler,
    "MMCME2_ADV": generic_handler("MMCME2_ADV", "IN_USE"),
    "PLLE2_ADV": generic_handler("PLLE2_ADV", "IN_USE"),
    "BUFGCTRL": generic_handler("BUFGCTRL", "IN_USE"),
    "BUFHCE": generic_handler("BUFHCE", "IN_USE"),
    "BUFR": generic_handler("BUFR"),
}


# ------------------------------------------------------------------ commands

def cmd_build(fasm, out, db):
    d = DB(db)
    nl = build(open(fasm), d, progress=True)
    with open(out, "w") as fo:
        json.dump(nl, fo)
    print_stats(nl)


def print_stats(nl):
    c = collections.Counter(x["type"] for x in nl["cells"])
    print("cells: %d  %s" % (len(nl["cells"]), " ".join("%s=%d" % kv for kv in sorted(c.items()))))
    nets = nl["nets"]
    nd = collections.Counter(min(len(v["drivers"]), 2) for v in nets.values())
    print("nets: %d (no driver %d, one driver %d, >1 driver %d); pips %d, nodes %d" % (
        len(nets), nd[0], nd[1], nd[2], nl["stats"]["pips"], nl["stats"]["nodes"]))


def cmd_net(path, name):
    nl = json.load(open(path))
    if name in nl["nets"]:
        print(json.dumps(nl["nets"][name], indent=1))
        return
    for c in nl["cells"]:
        if c["name"] == name or c["site"] == name:
            print(json.dumps(c, indent=1))


# ------------------------------------------------------------------ selftest

def selftest(db):
    """Hand-built FASM: two CLBs joined by INT PIPs, checked against an expected
    netlist (cell types, params, connectivity)."""
    d = DB(db)
    # find a CLBLL_L tile whose INT_L neighbour is at grid_x+1
    t0 = "CLBLL_L_X2Y100"
    tg = d.tg
    x, y = tg[t0]["grid_x"], tg[t0]["grid_y"]
    it = d.tiles[d.grid[(x + 1, y)]]
    assert d.ttype[d.grid[(x + 1, y)]] == "INT_L", it
    # LUT A of SLICEL_X0 (X2Y100 -> SLICE_X2Y100?) drives AFF D (AFFMUX.O6), AQ routed back to A1
    # of the same slice via INT: LOGIC_OUTS_L4 (AQ) -> ... we use the PIP IMUX_L1 <- LOGIC_OUTS_L4? not
    # a real PIP, so pick a real one from the tile type.
    tt = d.tile_type("INT_L")
    # site pin wires
    sites = d.sites_of(t0)
    s0 = [s for s in sites if s[0]["x_coord"] == 0][0]
    pinw = {p: v["wire"] for p, v in s0[0]["site_pins"].items()}
    nAQ = d.conn[("CLBLL_L", pinw["AQ"])]
    nA1 = d.conn[("CLBLL_L", pinw["A1"])]
    aq_int = [ow for dx, dy, oty, ow in nAQ if oty == "INT_L"][0]
    a1_int = [ow for dx, dy, oty, ow in nA1 if oty == "INT_L"][0]
    # find a two-PIP path aq_int -> X -> a1_int inside the INT tile
    srcs = {}
    for dst, src in tt["pips"]:
        srcs.setdefault(dst, set()).add(src)
    mid = [w for w in srcs.get(a1_int, ()) if aq_int in srcs.get(w, ())]
    assert mid, (aq_int, a1_int)
    mid = sorted(mid)[0]
    pre = "%s.SLICEL_X0." % t0
    lines = [
        pre + "ALUT.INIT[63:0] = 64'h5555555555555555",   # O6 = !A1
        pre + "AFFMUX.O6", pre + "AFF.ZINI", pre + "AFF.ZRST", pre + "FFSYNC", pre + "NOCLKINV",
        "%s.%s.%s" % (it, mid, aq_int), "%s.%s.%s" % (it, a1_int, mid),
    ]
    nl = build(lines, d)
    cells = {c["name"]: c for c in nl["cells"]}
    sname = s0[1]
    lut = cells[sname + "/ALUT"]
    ff = cells[sname + "/AFF"]
    assert lut["type"] == "LUT6" and lut["params"]["INIT"] == 0x5555555555555555, lut
    assert ff["type"] == "FDRE" and ff["params"]["INIT"] == 0 and ff["params"]["IS_C_INVERTED"] == 0, ff
    assert ff["pins"]["D"][0] == lut["pins"]["O"][0], (ff["pins"]["D"], lut["pins"]["O"])
    assert ff["pins"]["Q"][0] == lut["pins"]["I0"][0], (ff["pins"]["Q"], lut["pins"]["I0"])
    assert ff["pins"]["CE"][0] == "1'b1" and ff["pins"]["R"][0] == "1'b0", ff["pins"]
    q = nl["nets"][ff["pins"]["Q"][0]]
    assert q["drivers"] == [sname + "/AFF.Q"] and sname + "/ALUT.I0" in q["sinks"], q
    print("selftest: toggle flop %s (LUT6 !A1 -> FDRE -> INT %s -> %s -> %s -> A1): ok" % (
        sname, aq_int, mid, a1_int))
    # read_fasm merge
    f = read_fasm(["T_X1Y1.A.B[3:0] = 4'b1010", "T_X1Y1.A.B[5]", "T_X1Y1.C"])
    assert f["T_X1Y1"]["A.B"] == 0b101010 and f["T_X1Y1"]["C"] == 1, f
    print("selftest: FASM value merge: ok")


def main():
    a = sys.argv[1:]
    db = DEFAULT_DB
    if "--db" in a:
        i = a.index("--db")
        db = a[i + 1]
        del a[i:i + 2]
    if not a:
        sys.exit(__doc__)
    if a[0] == "build" and len(a) == 3:
        cmd_build(a[1], a[2], db)
    elif a[0] == "stats" and len(a) == 2:
        print_stats(json.load(open(a[1])))
    elif a[0] == "net" and len(a) == 3:
        cmd_net(a[1], a[2])
    elif a[0] == "selftest":
        selftest(db)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
