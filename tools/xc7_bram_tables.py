#!/usr/bin/env python3
"""Rebuild and characterize the logical BRAM tables of a 7-series bitstream.

Written for T13 (FT-710 SDR image, XC7A50T). Stdlib only. Builds on
tools/xc7_db.py (prjxray-db mapping) and prints summaries only: no table
contents are written unless you ask for one table with `show`.

Usage:
    python3 -I tools/xc7_bram_tables.py IMAGE.bin [--db DBDIR] CMD [args]

Commands:
    tables              one line per logical memory (RAMB36 pair or RAMB18 half):
                        width, used entries, value range, entropy, smoothness,
                        replication group, and a heuristic class
    show NAME [STEP]    print every STEP-th entry of one logical memory
                        (NAME = RAMB36_XnYm or RAMB18_XnYm, as printed by `tables`)
    lanes SITE...       join x9 RAMB18 lanes (LSB lane first) into one wide word
                        and characterize it (e.g. lanes RAMB18_X1Y11 RAMB18_X1Y17)
    halfsym NAME|lanes  split a table into its non-zero runs and report, per run,
                        length, sum, peak and whether it ends at its peak (half of
                        a symmetric FIR)
    selftest            check the bit-to-word and RAMB36 interleave helpers

Bit order (prjxray segbits_bram_*.block_ram.db, see docs/code/sdr/bram-tables.md):
  * A RAMB18 holds INIT bits 0..16383 and INITP bits 0..2047. At port width W
    (1, 2, 4, 9, 18) entry i is data bits [i*d, i*d+d) with d = W rounded down to
    a power of two, plus parity bits [i*p, i*p+p) (p = 1 for x9, 2 for x18) as
    the MSBs.
  * A RAMB36 interleaves its two halves bit by bit: RAMB36 INIT bit j is bit j//2
    of half Y(j%2); same for INITP. [inference from smoothness, see the doc]
"""
import collections
import hashlib
import math
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xc7_db  # noqa: E402

DW = {1: 1, 2: 2, 4: 4, 9: 8, 18: 16, 36: 32}
PW = {9: 1, 18: 2, 36: 4}


def sx(v, n):
    return v - (1 << n) if v >> (n - 1) & 1 else v


def entries(bits, pbits, width):
    d, p = DW[width], PW.get(width, 0)
    out = []
    for i in range(len(bits) // d):
        v = 0
        for k in range(d):
            v |= bits[i * d + k] << k
        for k in range(p):
            v |= pbits[i * p + k] << (d + k)
        out.append(v)
    return out


def interleave(a, b):
    out = [0] * (len(a) + len(b))
    out[0::2] = a
    out[1::2] = b
    return out


def half_bits(bs, seg, tile, yi):
    """INIT and INITP bit lists of one RAMB18 half."""
    tv = bs.tilegrid[tile]
    info = tv["bits"]["BLOCK_RAM"]
    sb = seg[tv["type"]]
    pref = "%s.RAMB18_Y%d." % (tv["type"], yi)
    data, par = [], []
    for k in range(0x40):
        for b in range(256):
            (fo, bo, _), = sb["%sINIT_%02X[%03d]" % (pref, k, b)]
            data.append(bs.get_bit(info, fo, bo))
    for k in range(8):
        for b in range(256):
            (fo, bo, _), = sb["%sINITP_%02X[%03d]" % (pref, k, b)]
            par.append(bs.get_bit(info, fo, bo))
    return data, par


WCODE = {"1": 1, "2": 2, "4": 4, "9": 9, "18": 18}
R36_FROM_HALF = {1: 2, 2: 4, 4: 9, 9: 18, 18: 36}


def memories(bs):
    """List of logical memories: dict(name, sites, width, values, kind)."""
    seg = {t: xc7_db.load_segbits(os.path.join(bs.dbdir, "segbits_%s.block_ram.db" % t.lower()))
           for t in ("BRAM_L", "BRAM_R")}
    out = []
    for r in xc7_db.bram_config(bs):
        t = r["tile"]
        sites = r["sites"]
        r36 = [s for s in sites if s.startswith("RAMB36")][0]
        r18 = sorted(s for s in sites if s.startswith("RAMB18"))
        halves = [half_bits(bs, seg, t, 0), half_bits(bs, seg, t, 1)]
        if not any(any(d) or any(p) for d, p in halves):
            continue
        c0, c1 = r["Y0"], r["Y1"]

        def hw(c):
            if c["sdp_rd36"] or c["sdp_wr36"]:
                return 18  # SDP x36 is two x18 lanes
            return WCODE.get(c["rd_a"] or "1", 1)
        same = (c0["in_use"] and c1["in_use"] and not (c0["sdp_rd36"] or c1["sdp_rd36"])
                and c0["rd_a"] == c1["rd_a"])
        if same:
            # Two halves with the same port width are either one RAMB36 or two
            # independent RAMB18s; the bitstream has no bit that tells them
            # apart, so keep the reading with the smoother contents.
            w = R36_FROM_HALF[hw(c0)]
            bits = interleave(halves[0][0], halves[1][0])
            pb = interleave(halves[0][1], halves[1][1])
            pv = entries(bits, pb, w)
            sv = [entries(d, p, hw(c0)) for d, p in halves]
            sp = smoothness(pv, w)
            ss = [smoothness(v, hw(c0)) for v in sv]
            if sp <= max(ss):
                out.append({"name": r36, "sites": r18, "tile": t, "width": w, "kind": "RAMB36",
                            "values": pv, "alt": "%.4f vs halves %.4f/%.4f" % (sp, ss[0], ss[1])})
                continue
            for s, v, x in zip(r18, sv, ss):
                out.append({"name": s, "sites": [s], "tile": t, "width": hw(c0), "kind": "RAMB18",
                            "values": v, "alt": "halves %.4f vs RAMB36 %.4f" % (x, sp)})
        else:
            for yi, (c, s) in enumerate(zip((c0, c1), r18)):
                d, p = halves[yi]
                if not (any(d) or any(p)):
                    continue
                w = hw(c) if c["in_use"] else 18
                out.append({"name": s, "sites": [s], "tile": t, "width": w, "kind": "RAMB18",
                            "values": entries(d, p, w)})
    return out


def nbits_of(vals, width):
    """Value width: data bits, plus the parity bits only if any is set."""
    d = DW[width]
    return d + (PW.get(width, 0) if any(v >> d for v in vals) else 0)


def smoothness(vals, width):
    st = stats(vals, nbits_of(vals, width))
    return st["smooth"] if st else 0.0


def stats(vals, nbits):
    n = len(vals)
    while n and vals[n - 1] == 0:
        n -= 1
    s = [sx(v, nbits) for v in vals[:n]]
    u = vals[:n]
    if not n:
        return None
    cnt = collections.Counter(u)
    ent = -sum(c / n * math.log2(c / n) for c in cnt.values())
    rng_s = (min(s), max(s))
    rng_u = (min(u), max(u))
    # choose signed or unsigned view by smaller total variation
    tv_s = sum(abs(a - b) for a, b in zip(s, s[1:])) / max(1, n - 1)
    tv_u = sum(abs(a - b) for a, b in zip(u, u[1:])) / max(1, n - 1)
    signed = tv_s <= tv_u
    view = s if signed else u
    span = max(view) - min(view) or 1
    smooth = min(tv_s, tv_u) / span  # ~0.33 for random data, << 0.01 for smooth curves
    return {"used": n, "distinct": len(cnt), "entropy": ent, "signed": signed,
            "range": rng_s if signed else rng_u, "smooth": smooth, "view": view}


def classify(st, width):
    if st is None:
        return "empty"
    if st["distinct"] == 1:
        return "constant"
    if st["smooth"] < 0.002:
        v = st["view"]
        inc = sum(1 for a, b in zip(v, v[1:]) if b >= a) / max(1, len(v) - 1)
        if inc > 0.99 or inc < 0.01:
            return "monotonic curve"
        return "smooth curve"
    if st["smooth"] < 0.05:
        return "piecewise smooth"
    return "high entropy"


def cosine_check(view, period, amp=None):
    """Max |v[n] - round(A cos(2 pi n / period))| with A = view[0] if not given."""
    a = amp if amp is not None else view[0]
    return max(abs(x - round(a * math.cos(2 * math.pi * i / period))) for i, x in enumerate(view))


def local_period(view, k=20):
    ps = []
    for i in range(k, len(view) - k):
        if abs(view[i]) > 0.3 * max(map(abs, view)):
            c = (view[i - k] + view[i + k]) / (2 * view[i])
            if -1 < c < 1:
                ps.append(2 * math.pi * k / math.acos(c))
    ps.sort()
    return ps[len(ps) // 2] if ps else None


def cmd_tables(bs):
    mems = memories(bs)
    groups = collections.defaultdict(list)
    for m in mems:
        h = hashlib.md5(repr((m["width"], m["values"])).encode()).hexdigest()[:8]
        m["hash"] = h
        groups[h].append(m["name"])
    print("%-14s %-6s %-5s %5s/%-5s %-22s %5s %7s %-6s %s" % (
        "memory", "kind", "width", "used", "size", "range", "H", "smooth", "group", "class"))
    for m in mems:
        nb = nbits_of(m["values"], m["width"])
        st = stats(m["values"], nb)
        cl = classify(st, m["width"])
        g = "%s x%d" % (m["hash"][:4], len(groups[m["hash"]]))
        if st is None:
            print("%-14s %-6s x%-4d %5d/%-5d" % (m["name"], m["kind"], m["width"], 0, len(m["values"])))
            continue
        print("%-14s %-6s x%-4d %5d/%-5d %-22s %5.2f %7.4f %-6s %s" % (
            m["name"], m["kind"], m["width"], st["used"], len(m["values"]),
            "%s%d..%d" % ("s" if st["signed"] else "u", st["range"][0], st["range"][1]),
            st["entropy"], st["smooth"], g, cl + (" (%d-bit)" % nb if nb != DW[m["width"]] + PW.get(m["width"], 0) else "")))
    print("distinct contents: %d of %d logical memories" % (len(groups), len(mems)))


def find(bs, name):
    for m in memories(bs):
        if m["name"] == name:
            return m
    sys.exit("no logical memory %s (see `tables`)" % name)


def lanes_values(bs, sites):
    seg = {t: xc7_db.load_segbits(os.path.join(bs.dbdir, "segbits_%s.block_ram.db" % t.lower()))
           for t in ("BRAM_L", "BRAM_R")}
    cols = []
    for s in sites:
        tile = [t for t, v in bs.tilegrid.items() if s in v.get("sites", {})][0]
        yi = sorted(x for x in bs.tilegrid[tile]["sites"] if x.startswith("RAMB18")).index(s)
        d, p = half_bits(bs, seg, tile, yi)
        cols.append(entries(d, p, 9))
    vals = []
    for i in range(len(cols[0])):
        v = 0
        for k, c in enumerate(cols):
            v |= c[i] << (9 * k)
        vals.append(v)
    return vals, 9 * len(cols)


def runs(view):
    out, i, n = [], 0, len(view)
    while i < n:
        if view[i] == 0:
            i += 1
            continue
        j = i
        while j < n and not (all(x == 0 for x in view[j:j + 8])):
            j += 1
        out.append((i, view[i:j]))
        i = j
    return out


def cmd_halfsym(view, block=None):
    rs = runs(view) if block is None else [(b, view[b:b + block]) for b in range(0, len(view), block)]
    for start, r in rs:
        while r and r[-1] == 0:
            r = r[:-1]
        if not r:
            continue
        pk = max(range(len(r)), key=lambda i: abs(r[i]))
        print("  @%5d len %4d sum %8d peak@+%d %7d %s" % (
            start, len(r), sum(r), pk, r[pk], "ends at peak" if pk == len(r) - 1 else ""))


def selftest():
    # x18: entry 0 = 0x2ABCD (data 0xABCD, parity 2), entry 1 = 0x00001
    bits = [0] * 16384
    pb = [0] * 2048
    for k in range(16):
        bits[k] = (0xABCD >> k) & 1
    bits[16] = 1
    pb[1] = 1
    e = entries(bits, pb, 18)
    assert e[0] == 0x2ABCD and e[1] == 1, e[:2]
    assert entries(bits, pb, 9)[0] == 0xCD and entries(bits, pb, 9)[1] == 0x1AB
    assert entries(bits, pb, 4)[:4] == [0xD, 0xC, 0xB, 0xA]
    assert interleave([1, 0], [0, 1]) == [1, 0, 0, 1]
    assert sx(0x3FFFF, 18) == -1 and sx(0x1FFFF, 18) == 0x1FFFF
    v = [round(30000 * math.cos(2 * math.pi * i / 720)) for i in range(800)]
    assert cosine_check(v, 720) == 0 and abs(local_period(v) - 720) < 5
    print("selftest ok")


def main():
    a = sys.argv[1:]
    if a and a[0] == "selftest":
        return selftest()
    if len(a) < 2 or a[0] in ("-h", "--help"):
        print(__doc__)
        return
    image = a.pop(0)
    db, part = xc7_db.DEFAULT_DB, "xc7a50tcpg236-1"
    if "--db" in a:
        i = a.index("--db"); db = os.path.expanduser(a[i + 1]); del a[i:i + 2]
    bs = xc7_db.Bitstream(image, db, part)
    cmd = a[0]
    if cmd == "tables":
        cmd_tables(bs)
    elif cmd in ("show", "halfsym") and a[1].startswith("RAMB"):
        if a[1] == "lanes":
            pass
        m = find(bs, a[1])
        nb = nbits_of(m["values"], m["width"])
        st = stats(m["values"], nb)
        if "alt" in m:
            print("pairing: %s" % m["alt"])
        if cmd == "halfsym":
            cmd_halfsym(st["view"], int(a[2]) if len(a) > 2 else None)
            return
        step = int(a[2]) if len(a) > 2 else 64
        for i in range(0, st["used"], step):
            print("%5d %s" % (i, st["view"][i:i + min(step, 8)]))
        p = local_period(st["view"])
        if p:
            print("local period %.2f, max |err| vs round(v[0] cos(2 pi n/%d)): %d" % (
                p, round(p), cosine_check(st["view"], round(p))))
    elif cmd in ("lanes", "halfsym"):
        sites = a[1:] if cmd == "lanes" else a[2:]
        vals, nb = lanes_values(bs, sites)
        st = stats(vals, nb)
        print("%s: %d-bit, used %d, range %s, entropy %.2f, smooth %.4f, class %s" % (
            "+".join(sites), nb, st["used"], st["range"], st["entropy"], st["smooth"], classify(st, 0)))
        cmd_halfsym(st["view"])
    else:
        sys.exit("unknown command %s" % cmd)


if __name__ == "__main__":
    main()
