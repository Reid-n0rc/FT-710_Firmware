#!/usr/bin/env python3
"""Map a 7-series bitstream onto Project X-Ray tiles: BRAM INIT dump and tile usage.

Written for T13 (FT-710 SDR image, XC7A50T). Stdlib only. Needs a local
prjxray-db checkout (https://github.com/f4pga/prjxray-db), see docs/tooling.md.

Usage:
    python3 -I tools/xc7_db.py IMAGE.bin --db DBDIR [--part xc7a50tcpg236-1] CMD [args]

    DBDIR is the prjxray-db family dir, e.g. ~/.local/share/ft710-tools/prjxray-db/artix7
    (default: $PRJXRAY_DB or that path).

Commands:
    frames              check the FDRI frame order against part.json (FAR list)
    bram OUTDIR         decode the INIT/INITP contents of every RAMB18 half and
                        write OUTDIR/<site>.bin (16-bit LE words, 1024 x 16)
                        plus OUTDIR/<site>.par (2-bit parity, 1024 bytes) and
                        OUTDIR/index.json (site, tile, hash, non-zero count)
    usage               coarse resource picture: per tile type, how many tiles
                        have any configuration bit set; DSP48 / BRAM / IOB / CMT /
                        BUFG sites with non-zero bits; used CLB columns
    bramcfg             one line per used RAMB18 half / RAMB36: IN_USE, port
                        widths, SDP/FIFO/ECC/cascade flags, output registers
    sites               finer resource count from positive segbits: LUTs with a
                        non-zero INIT, LUTRAM/SRL, FF muxes, CARRY4, DSP48E1 options,
                        and set-bit counts of the clocking/IO/special tiles
    tilebits TILE       list the set bits of one tile as FF_BB (prjxray style)
    config [TYPE ...]   for every tile of the given types (default BRAM_L BRAM_R),
                        print the non-routing, non-INIT segbits tags whose bits
                        all match (positive bits set, "!" bits clear), skipping
                        tiles with no set bits. Enum values that are all-"!"
                        (e.g. READ_WIDTH_A_1) also match unused sites.

How it works:
  * The FDRI payload (from tools/xbit_parse.py) is split into 101-word frames.
    The FAR sequence is rebuilt from part.json: for each block type (0 =
    CLB_IO_CLK, 1 = BLOCK_RAM), top-half rows then bottom-half rows, every
    configuration column with its frame_count, and 2 pad frames after each row
    (UG470 auto-increment). The total must equal the FDRI frame count.
  * A tile owns `frames` frames from `baseaddr` and `words` words from `offset`
    inside each frame (tilegrid.json). A segbits bit "FF_BB" is frame
    baseaddr+FF, word offset+BB//32, bit BB%32 (LSB = bit 0).
  * BRAM INIT/INITP bit positions come from segbits_bram_{l,r}.block_ram.db
    (tags BRAM_L.RAMB18_Y0.INIT_00[000] ...).
"""
import hashlib
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xbit_parse  # noqa: E402

DEFAULT_DB = os.environ.get(
    "PRJXRAY_DB", os.path.expanduser("~/.local/share/ft710-tools/prjxray-db/artix7"))
BUS = {"CLB_IO_CLK": 0, "BLOCK_RAM": 1, "CFG_CLB": 2}


def make_far(block, top, row, col, minor):
    return (block << 23) | (top << 22) | (row << 17) | (col << 7) | minor


def far_sequence(part):
    """Return list of FAR values (None for pad frames) in bitstream order."""
    seq = []
    g = part["global_clock_regions"]
    for bus, bt in (("CLB_IO_CLK", 0), ("BLOCK_RAM", 1)):
        for half, topbit in (("top", 0), ("bottom", 1)):
            rows = g.get(half, {}).get("rows", {})
            for r in sorted(rows, key=int):
                cb = rows[r]["configuration_buses"].get(bus)
                if not cb:
                    continue
                cols = cb["configuration_columns"]
                for c in sorted(cols, key=int):
                    for m in range(cols[c]["frame_count"]):
                        seq.append(make_far(bt, topbit, int(r), int(c), m))
                seq.extend([None, None])
    return seq


class Bitstream:
    def __init__(self, image, dbdir, partname):
        data = open(image, "rb").read()
        _, pkts = xbit_parse.parse(data)
        fd = xbit_parse.fdri_payload(pkts)
        self.part = json.load(open(os.path.join(dbdir, partname, "part.json")))
        die = partname.split("cpg")[0].split("csg")[0].split("fgg")[0].split("ftg")[0]
        self.tilegrid = json.load(open(os.path.join(dbdir, die, "tilegrid.json")))
        self.dbdir = dbdir
        self.seq = far_sequence(self.part)
        n = len(fd) // 101
        self.nframes = n
        self.frames = {}
        for i, far in enumerate(self.seq[:n]):
            if far is not None:
                self.frames[far] = fd[i * 101:(i + 1) * 101]
        self.pad = [fd[i * 101:(i + 1) * 101] for i, f in enumerate(self.seq[:n]) if f is None]

    def tile_bits(self, tile, bus="CLB_IO_CLK"):
        """Set bits of a tile segment as set of (frame_offset, bit_offset)."""
        info = self.tilegrid[tile]["bits"].get(bus)
        if not info:
            return set()
        base = int(info["baseaddr"], 16)
        out = set()
        for fo in range(info["frames"]):
            fr = self.frames.get(base + fo)
            if fr is None:
                continue
            for wo in range(info["words"]):
                w = fr[info["offset"] + wo]
                if w:
                    for b in range(32):
                        if (w >> b) & 1:
                            out.add((fo, wo * 32 + b))
        return out

    def get_bit(self, info, fo, bo):
        fr = self.frames.get(int(info["baseaddr"], 16) + fo)
        if fr is None:
            return 0
        return (fr[info["offset"] + bo // 32] >> (bo % 32)) & 1


def load_segbits(path):
    out = {}
    for line in open(path):
        p = line.split()
        if len(p) < 2:
            continue
        bits = []
        for b in p[1:]:
            neg = b.startswith("!")
            f, o = b.lstrip("!").split("_")
            bits.append((int(f), int(o), neg))
        out[p[0]] = bits
    return out


def cmd_frames(bs):
    n_far = sum(1 for f in bs.seq if f is not None)
    print("part.json FAR sequence: %d frames + %d pad frames = %d; FDRI frames %d -> %s" % (
        n_far, len(bs.seq) - n_far, len(bs.seq), bs.nframes,
        "MATCH" if len(bs.seq) == bs.nframes else "MISMATCH"))
    print("pad frames all zero: %s" % all(not any(p) for p in bs.pad))
    i = 0
    prev = None
    for k, f in enumerate(bs.seq):
        if f is None:
            continue
        key = (f >> 23, (f >> 22) & 1, (f >> 17) & 0x1F)
        if key != prev:
            print("  frame %5d: block %d %s row %d" % (k, key[0], "bottom" if key[1] else "top", key[2]))
            prev = key
        i += 1


def cmd_bram(bs, outdir):
    os.makedirs(outdir, exist_ok=True)
    seg = {s: load_segbits(os.path.join(bs.dbdir, "segbits_bram_%s.block_ram.db" % s))
           for s in ("l", "r")}
    index = []
    tiles = sorted((t for t, v in bs.tilegrid.items() if v["type"] in ("BRAM_L", "BRAM_R")),
                   key=lambda t: (bs.tilegrid[t]["grid_x"], -bs.tilegrid[t]["grid_y"]))
    for t in tiles:
        tv = bs.tilegrid[t]
        info = tv["bits"]["BLOCK_RAM"]
        sb = seg["l" if tv["type"] == "BRAM_L" else "r"]
        r18 = sorted(s for s, ty in tv["sites"].items() if s.startswith("RAMB18"))
        r36 = [s for s in tv["sites"] if s.startswith("RAMB36")][0]
        for yi, site in enumerate(r18):  # Y0 = lower site, Y1 = upper site
            data = bytearray(2048)
            par = bytearray(1024)
            pref = "%s.RAMB18_Y%d." % (tv["type"], yi)
            for k in range(0x40):
                for b in range(256):
                    (fo, bo, _), = sb["%sINIT_%02X[%03d]" % (pref, k, b)]
                    if bs.get_bit(info, fo, bo):
                        bit = k * 256 + b
                        data[bit // 8] |= 1 << (bit % 8)
            for k in range(8):
                for b in range(256):
                    (fo, bo, _), = sb["%sINITP_%02X[%03d]" % (pref, k, b)]
                    if bs.get_bit(info, fo, bo):
                        bit = k * 256 + b
                        par[bit // 2] |= 1 << (bit % 2)
            nz = sum(1 for i in range(0, 2048, 2) if data[i] or data[i + 1])
            pz = sum(1 for p in par if p)
            h = hashlib.md5(bytes(data) + bytes(par)).hexdigest()[:8] if (nz or pz) else ""
            if nz or pz:
                open(os.path.join(outdir, site + ".bin"), "wb").write(data)
                open(os.path.join(outdir, site + ".par"), "wb").write(par)
            index.append({"tile": t, "ramb36": r36, "site": site, "half": "Y%d" % yi,
                          "clock_region": tv["clock_region"], "nonzero_words": nz,
                          "nonzero_parity": pz, "hash": h})
    json.dump(index, open(os.path.join(outdir, "index.json"), "w"), indent=1)
    used = [e for e in index if e["hash"]]
    groups = {}
    for e in used:
        groups.setdefault(e["hash"], []).append(e["site"])
    print("RAMB18 halves: %d, with non-zero INIT/INITP: %d, distinct contents: %d" % (
        len(index), len(used), len(groups)))
    for e in index:
        if e["hash"]:
            print("  %-14s %-8s %-14s %s words!=0 %4d parity!=0 %4d  %s x%d" % (
                e["tile"], e["ramb36"], e["site"], e["half"], e["nonzero_words"],
                e["nonzero_parity"], e["hash"], len(groups[e["hash"]])))


def cmd_usage(bs):
    from collections import Counter, defaultdict
    total, used = Counter(), Counter()
    usedtiles = defaultdict(list)
    for t, v in bs.tilegrid.items():
        if "CLB_IO_CLK" not in v.get("bits", {}):
            continue
        total[v["type"]] += 1
        if bs.tile_bits(t):
            used[v["type"]] += 1
            usedtiles[v["type"]].append(t)
    print("%-24s %6s %6s" % ("tile type", "tiles", "w/bits"))
    for ty in sorted(total):
        print("%-24s %6d %6d" % (ty, total[ty], used[ty]))
    # DSP48: a DSP tile has DSP_0 and DSP_1; count halves with bits in their own frame range
    seg = {s: load_segbits(os.path.join(bs.dbdir, "segbits_dsp_%s.db" % s)) for s in ("l", "r")}
    ndsp = 0
    for ty in ("DSP_L", "DSP_R"):
        sb = seg[ty[-1].lower()]
        own = {0: set(), 1: set()}
        for tag, bits in sb.items():
            if tag.split(".")[1].startswith("DSP_0"):
                own[0].update((f, o) for f, o, _ in bits)
            elif tag.split(".")[1].startswith("DSP_1"):
                own[1].update((f, o) for f, o, _ in bits)
        for t in usedtiles.get(ty, []):
            b = bs.tile_bits(t)
            for k in (0, 1):
                if b & own[k]:
                    ndsp += 1
    print("DSP48E1 sites with any DSP_0/DSP_1 segbit set: %d of %d" % (
        ndsp, 2 * (total["DSP_L"] + total["DSP_R"])))
    cols = sorted({bs.tilegrid[t]["grid_x"] for ty in ("CLBLL_L", "CLBLL_R", "CLBLM_L", "CLBLM_R")
                   for t in usedtiles.get(ty, [])})
    print("CLB grid columns with used tiles: %d (%s)" % (len(cols), cols))
    return usedtiles


SKIP_PREFIX = ("INIT_", "INITP_", "SRVAL_", "BRAM_ADDR", "ZINV_", "ZIS_", "IS_")


def cmd_config(bs, types):
    cache = {}
    for t in sorted(bs.tilegrid, key=lambda t: (bs.tilegrid[t]["grid_x"], -bs.tilegrid[t]["grid_y"])):
        ty = bs.tilegrid[t]["type"]
        if ty not in types:
            continue
        if ty not in cache:
            cache[ty] = load_segbits(os.path.join(bs.dbdir, "segbits_%s.db" % ty.lower()))
        bits = bs.tile_bits(t)
        if not bits:
            continue
        hits = []
        for tag, tb in cache[ty].items():
            parts = tag.split(".")[1:]
            if any(p.startswith(x) for p in parts for x in SKIP_PREFIX):
                continue
            if all(((f, o) in bits) != neg for f, o, neg in tb) and any(not n for _, _, n in tb):
                hits.append(tag[len(ty) + 1:])
        sites = ",".join(sorted(bs.tilegrid[t]["sites"]))
        print("%s [%s] %d set bits: %s" % (t, sites, len(bits), " ".join(sorted(hits))))


def match(bits, tb):
    return all(((f, o) in bits) != neg for f, o, neg in tb)


def best_enum(sb, prefix, bits):
    """Value of an enum feature PREFIX<value>: the matching value with most positive bits."""
    best, score = None, -1
    for tag, tb in sb.items():
        if tag.startswith(prefix) and match(bits, tb):
            pos = sum(1 for _, _, n in tb if not n)
            if pos > score:
                best, score = tag[len(prefix):], pos
    return best


def bram_config(bs):
    """Per BRAM tile with set bits: dict of decoded config for Y0, Y1 and RAMB36."""
    cache, out = {}, []
    for t in sorted(bs.tilegrid, key=lambda t: (bs.tilegrid[t]["grid_x"], -bs.tilegrid[t]["grid_y"])):
        ty = bs.tilegrid[t]["type"]
        if ty not in ("BRAM_L", "BRAM_R"):
            continue
        if ty not in cache:
            cache[ty] = load_segbits(os.path.join(bs.dbdir, "segbits_%s.db" % ty.lower()))
        sb = cache[ty]
        bits = bs.tile_bits(t)
        if not bits:
            continue
        rec = {"tile": t, "sites": sorted(bs.tilegrid[t]["sites"])}
        for h in ("Y0", "Y1"):
            p = "%s.RAMB18_%s." % (ty, h)
            flag = lambda n: (p + n) in sb and match(bits, sb[p + n])
            rec[h] = {
                "in_use": flag("IN_USE"),
                "rd_a": best_enum(sb, p + "READ_WIDTH_A_", bits),
                "rd_b": best_enum(sb, p + "READ_WIDTH_B_", bits),
                "wr_a": best_enum(sb, p + "WRITE_WIDTH_A_", bits),
                "wr_b": best_enum(sb, p + "WRITE_WIDTH_B_", bits),
                "sdp_rd36": flag("SDP_READ_WIDTH_36"), "sdp_wr36": flag("SDP_WRITE_WIDTH_36"),
                "doa_reg": flag("DOA_REG"), "dob_reg": flag("DOB_REG"),
                "fifo": flag("FIFO_MODE"),
            }
        p = "%s.RAMB36." % ty
        flag = lambda n: (p + n) in sb and match(bits, sb[p + n])
        rec["R36"] = {"ecc_rd": flag("EN_ECC_READ"), "ecc_wr": flag("EN_ECC_WRITE"),
                      "ext_a_lower": flag("RAM_EXTENSION_A_LOWER"),
                      "ext_b_lower": flag("RAM_EXTENSION_B_LOWER"),
                      "w1": [n for n in ("READ_WIDTH_A_1", "READ_WIDTH_B_1", "WRITE_WIDTH_A_1",
                                         "WRITE_WIDTH_B_1") if flag("BRAM36_" + n)]}
        rec["casc_ard"] = ("%s.CASCOUT_ARD_ACTIVE" % ty) in sb and match(bits, sb["%s.CASCOUT_ARD_ACTIVE" % ty])
        rec["en_syn"] = ("%s.EN_SYN" % ty) in sb and match(bits, sb["%s.EN_SYN" % ty])
        out.append(rec)
    return out


def cmd_bramcfg(bs):
    for r in bram_config(bs):
        hs = []
        for h in ("Y0", "Y1"):
            c = r[h]
            if not c["in_use"]:
                hs.append("%s -" % h)
                continue
            w = "rd %s/%s wr %s/%s" % (c["rd_a"], c["rd_b"], c["wr_a"], c["wr_b"])
            fl = [k for k in ("sdp_rd36", "sdp_wr36", "doa_reg", "dob_reg", "fifo") if c[k]]
            hs.append("%s %s %s" % (h, w, ",".join(fl)))
        x = r["R36"]
        fl = [k for k in ("ecc_rd", "ecc_wr", "ext_a_lower", "ext_b_lower") if x[k]] + x["w1"]
        if r["casc_ard"]:
            fl.append("CASCOUT")
        print("%-14s %-13s | %s | R36 %s" % (r["tile"], [s for s in r["sites"] if s.startswith("RAMB36")][0],
                                          " | ".join(hs), ",".join(fl) or "-"))


def cmd_sites(bs):
    from collections import Counter
    cache = {}
    c = Counter()
    for t, v in bs.tilegrid.items():
        ty = v["type"]
        if not ty.startswith(("CLBL", "DSP_")):
            continue
        bits = bs.tile_bits(t)
        if not bits:
            continue
        if ty not in cache:
            cache[ty] = load_segbits(os.path.join(bs.dbdir, "segbits_%s.db" % ty.lower()))
        sb = cache[ty]
        if ty.startswith("CLBL"):
            for sl in ("X0", "X1"):
                used = False
                for l in "ABCD":
                    for kind in ("SLICEL", "SLICEM"):
                        pre = "%s.%s_%s.%sLUT.INIT[" % (ty, kind, sl, l)
                        if any(k.startswith(pre) and match(bits, b) for k, b in sb.items()):
                            c["LUT"] += 1
                            used = True
                            if kind == "SLICEM":
                                c["LUT in SLICEM"] += 1
                        for f in ("RAM", "SRL"):
                            k = "%s.%s_%s.%sLUT.%s" % (ty, kind, sl, l, f)
                            if k in sb and match(bits, sb[k]):
                                c["LUT as " + f] += 1
                    for ff in (l + "FF", l + "5FF"):
                        for kind in ("SLICEL", "SLICEM"):
                            pre = "%s.%s_%s.%sMUX." % (ty, kind, sl, ff)
                            if any(k.startswith(pre) and match(bits, b) and any(not n for _, _, n in b)
                                   for k, b in sb.items()):
                                c["FF (mux set)"] += 1
                for kind in ("SLICEL", "SLICEM"):
                    pre = "%s.%s_%s.PRECYINIT." % (ty, kind, sl)
                    if any(k.startswith(pre) and match(bits, b) and any(not n for _, _, n in b)
                           for k, b in sb.items()):
                        c["CARRY4 (PRECYINIT set)"] += 1
                if used:
                    c["slices with a LUT"] += 1
        else:
            for d in ("DSP_0", "DSP_1"):
                pre = "%s.DSP48.%s." % (ty, d)
                own = {(f, o) for k, b in sb.items() if k.startswith(pre) for f, o, _ in b}
                if not bits & own:
                    continue
                c["DSP48E1 used"] += 1
                for feat in ("USE_DPORT", "ZMREG", "ZPREG", "ZAREG_2_ACASCREG_1", "ZBREG_2_BCASCREG_1",
                             "USE_SIMD_FOUR12", "USE_SIMD_FOUR12_TWO24", "A_INPUT", "B_INPUT",
                             "AREG_0", "BREG_0", "ZCREG", "ZOPMODEREG"):
                    k = pre + feat
                    if k in sb and match(bits, sb[k]):
                        c["DSP48E1 " + feat] += 1
    for k in sorted(c):
        print("%-28s %d" % (k, c[k]))
    print("special tiles (set bits):")
    for t, v in sorted(bs.tilegrid.items()):
        if v["type"].startswith(("CMT_TOP", "CLK_BUFG_", "CLK_HROW", "MONITOR", "PCIE_BOT", "PCIE_TOP",
                                 "GTP_C", "CFG_CENTER")) and "CLK_BUFG_REBUF" not in v["type"]:
            n = len(bs.tile_bits(t))
            if n:
                print("  %-28s %-22s %5d" % (t, v["type"], n))


def cmd_tilebits(bs, tile):
    tv = bs.tilegrid[tile]
    print(json.dumps(tv["bits"]))
    for bus in tv["bits"]:
        b = sorted(bs.tile_bits(tile, bus))
        print("%s: %d set bits" % (bus, len(b)))
        print(" ".join("%02d_%02d" % x for x in b[:400]))


def main():
    a = sys.argv[1:]
    if len(a) < 2 or a[0] in ("-h", "--help"):
        print(__doc__)
        return
    image = a.pop(0)
    db, part = DEFAULT_DB, "xc7a50tcpg236-1"
    if "--db" in a:
        i = a.index("--db"); db = os.path.expanduser(a[i + 1]); del a[i:i + 2]
    if "--part" in a:
        i = a.index("--part"); part = a[i + 1]; del a[i:i + 2]
    bs = Bitstream(image, db, part)
    cmd = a[0]
    if cmd == "frames":
        cmd_frames(bs)
    elif cmd == "bram":
        cmd_bram(bs, a[1])
    elif cmd == "usage":
        cmd_usage(bs)
    elif cmd == "config":
        cmd_config(bs, a[1:] or ["BRAM_L", "BRAM_R"])
    elif cmd == "bramcfg":
        cmd_bramcfg(bs)
    elif cmd == "sites":
        cmd_sites(bs)
    elif cmd == "tilebits":
        cmd_tilebits(bs, a[1])
    else:
        sys.exit("unknown command %s" % cmd)


if __name__ == "__main__":
    main()
