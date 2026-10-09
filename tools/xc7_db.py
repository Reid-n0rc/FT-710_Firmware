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
    elif cmd == "tilebits":
        cmd_tilebits(bs, a[1])
    else:
        sys.exit("unknown command %s" % cmd)


if __name__ == "__main__":
    main()
