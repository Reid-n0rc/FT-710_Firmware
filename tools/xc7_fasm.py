#!/usr/bin/env python3
"""7-series bitstream -> prjxray .bits -> FASM, plus a FASM summary (T15a).

Written for T15 (FT-710 SDR image, XC7A50T). The `bits` and `summary` commands
are stdlib only. The `fasm` command needs prjxray's Python package and its
dependencies (fasm, simplejson, intervaltree, pyyaml); when they are not
importable the script re-runs itself under the venv python
(~/.local/share/ft710-tools/venv, see docs/tooling.md).

Usage:
    python3 -I tools/xc7_fasm.py bits    IMAGE.bin OUT.bits
    python3 -I tools/xc7_fasm.py fasm    IMAGE.bin OUT.fasm [--bits OUT.bits] [--unknown OUT.txt]
    python3 -I tools/xc7_fasm.py summary IN.fasm [--json OUT.json]
    python3 -I tools/xc7_fasm.py selftest

Options (all commands): --db DBDIR (default $PRJXRAY_DB or
~/.local/share/ft710-tools/prjxray-db/artix7), --part PART (default
xc7a50tcpg236-1; the frame layout is the same for every XC7A50T package).

How it works:
  * Frames are taken from tools/xc7_db.py (FDRI payload split into 101-word
    frames, FAR sequence rebuilt from part.json). This replaces prjxray's C++
    `bitread`: every set bit becomes one line `bit_FFFFFFFF_WWW_BB` (frame
    address hex, word 0..100, bit 0..31), the format of `bitread -z -y`.
  * `fasm` hands those bits to prjxray's own FasmDisassembler (the code behind
    utils/bit2fasm.py) and writes the merged, sorted FASM. Bits that no segbits
    entry explains are counted per tile type (prjxray `--verbose` style) and can
    be listed with --unknown. Word 50 bits 0-12 of each frame are the frame ECC
    (UG470) and are counted separately.
  * `summary` counts features per tile type and splits them into PIPs
    (TILE.DST.SRC in an interconnect/switch tile), LUT INIT, other site
    features.
"""
import collections
import json
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

DEFAULT_DB = os.environ.get(
    "PRJXRAY_DB", os.path.expanduser("~/.local/share/ft710-tools/prjxray-db/artix7"))
PRJXRAY = os.environ.get("PRJXRAY", os.path.expanduser("~/.local/share/ft710-tools/prjxray"))
VENV_PY = os.path.join(os.environ.get("FT710_VENV", os.path.expanduser("~/.local/share/ft710-tools/venv")), "bin", "python")
DEFAULT_PART = "xc7a50tcpg236-1"


def frames_of(image, db, part):
    import xc7_db
    bs = xc7_db.Bitstream(image, db, part)
    return bs.frames


def bitdata_of(frames):
    """prjxray bitdata: {frame: (set(word idx), set(word*32+bit))}."""
    out = {}
    for far, words in frames.items():
        wset, bset = set(), set()
        for wi, w in enumerate(words):
            if w:
                wset.add(wi)
                b = 0
                while w:
                    if w & 1:
                        bset.add(wi * 32 + b)
                    w >>= 1
                    b += 1
        if wset:
            out[far] = (wset, bset)
    return out


def bits_lines(frames):
    for far in sorted(frames):
        for wi, w in enumerate(frames[far]):
            for b in range(32):
                if (w >> b) & 1:
                    yield "bit_%08x_%03d_%02d" % (far, wi, b)


def cmd_bits(image, out, db, part):
    n = 0
    with open(out, "w") as f:
        for line in bits_lines(frames_of(image, db, part)):
            f.write(line + "\n")
            n += 1
    print("%s: %d set bits" % (out, n))


def have_prjxray():
    import warnings
    warnings.filterwarnings("ignore", message=".*Antlr4.*")  # textX fallback parser is fine here
    try:
        import fasm  # noqa: F401
        import simplejson  # noqa: F401
        import intervaltree  # noqa: F401
        import yaml  # noqa: F401
    except ImportError:
        return False
    if PRJXRAY not in sys.path:
        sys.path.insert(0, PRJXRAY)
    return True


def reexec_in_venv():
    if not os.path.exists(VENV_PY):
        sys.exit("prjxray Python deps missing and no venv at %s (see docs/tooling.md)" % VENV_PY)
    if os.environ.get("XC7_FASM_REEXEC"):
        sys.exit("prjxray Python deps missing even under %s" % VENV_PY)
    env = dict(os.environ, XC7_FASM_REEXEC="1")
    sys.exit(subprocess.call([VENV_PY, "-I", os.path.abspath(__file__)] + sys.argv[1:], env=env))


def disassemble(bitdata, db, part):
    """Return (list of FASM feature strings, unknown-bit count, unknown per tile-type-ish segment)."""
    import fasm
    import fasm.output
    from prjxray import fasm_disassembler
    from prjxray.db import Database
    d = Database(db, part)
    grid = d.grid()
    dis = fasm_disassembler.FasmDisassembler(d)
    lines = []
    unknown = []
    for ln in dis.find_features_in_bitstream(bitdata, verbose=True):
        if ln.set_feature is not None:
            lines.append(ln)
        elif ln.annotations:
            for a in ln.annotations:
                if a.name == "unknown_bit":
                    f, w, b = a.value.split("_")
                    unknown.append((int(f, 16), int(w), int(b)))
    model = fasm.output.merge_and_sort(lines, zero_function=dis.is_zero_feature,
                                       sort_key=grid.tile_key)
    text = fasm.fasm_tuple_to_string(model, canonical=False)
    return text, unknown, sorted(dis.decode_warnings)


def unknown_by_tiletype(unknown, db):
    """Attribute unexplained bits to tile types via tilegrid (frame/word ranges)."""
    tg = json.load(open(os.path.join(db, "xc7a50t", "tilegrid.json")))
    idx = collections.defaultdict(list)
    for t, v in tg.items():
        for bus, info in v["bits"].items():
            base = int(info["baseaddr"], 16)
            idx[base].append((info["offset"], info["offset"] + info["words"], info["frames"], v["type"]))
    out = collections.Counter()
    for f, w, _ in unknown:
        base = f & ~0x7F
        hit = "?"
        for lo, hi, nfr, ty in idx.get(base, ()):
            if lo <= w < hi and f - base < nfr:
                hit = ty
                break
        out[hit] += 1
    return out


def cmd_fasm(image, out, db, part, bits_out=None, unknown_out=None):
    frames = frames_of(image, db, part)
    if bits_out:
        with open(bits_out, "w") as f:
            for line in bits_lines(frames):
                f.write(line + "\n")
    bitdata = bitdata_of(frames)
    nbits = sum(len(v[1]) for v in bitdata.values())
    text, unknown, warn = disassemble(bitdata, db, part)
    with open(out, "w") as f:
        f.write(text)
    if unknown_out:
        with open(unknown_out, "w") as f:
            for fr, w, b in sorted(unknown):
                if not (w == 50 and b < 13):
                    f.write("bit_%08x_%03d_%02d\n" % (fr, w, b))
    nfeat = sum(1 for ln in text.splitlines() if ln and not ln.startswith("#"))
    ecc = [u for u in unknown if u[1] == 50 and u[2] < 13]
    unknown = [u for u in unknown if not (u[1] == 50 and u[2] < 13)]
    print("%s: %d set bits, %d FASM lines, %d frame-ECC bits (word 50 bits 0-12), "
          "%d other bits not explained by segbits (%.3f %%)" % (
              out, nbits, nfeat, len(ecc), len(unknown), 100.0 * len(unknown) / max(1, nbits)))
    if warn:
        print("tile types without segbits: %s" % " ".join(warn))
    for ty, n in unknown_by_tiletype(unknown, db).most_common():
        print("  unexplained bits in %-22s %6d" % (ty, n))


# ---------------------------------------------------------------- summary

FEAT = re.compile(r"^([A-Za-z0-9_]+?_X\d+Y\d+)\.(.+)$")


def parse_fasm(path):
    """Yield (tile, feature, value-str or None) per FASM line (comments and annotations removed)."""
    for line in open(path):
        line = line.split("#", 1)[0].split("{", 1)[0].strip()
        if not line:
            continue
        val = None
        if "=" in line:
            line, val = (x.strip() for x in line.split("=", 1))
        m = FEAT.match(line)
        if not m:
            continue
        yield m.group(1), m.group(2), val


_PIPS = {}


def pip_set(db, ttype):
    """{(dst, src)} of the tile type's PIPs (tile_type_*.json keys are TYPE.SRC->DST)."""
    if ttype not in _PIPS:
        p = os.path.join(db, "tile_type_%s.json" % ttype)
        out = set()
        if os.path.exists(p):
            for k in json.load(open(p))["pips"]:
                src, dst = re.split(r"<?->>?", k.split(".", 1)[1])
                out.add((dst, src))
        _PIPS[ttype] = out
    return _PIPS[ttype]


def classify(db, ttype, feat):
    parts = feat.split(".")
    if len(parts) == 2 and (parts[0], parts[1]) in pip_set(db, ttype):
        return "pip"
    if "LUT.INIT[" in feat:
        return "lut_init"
    if ttype.startswith("BRAM") and re.search(r"\.INITP?_[0-9A-F]{2}", feat):
        return "bram_init"
    return "site"


def tile_types(db):
    tg = json.load(open(os.path.join(db, "xc7a50t", "tilegrid.json")))
    return {t: v["type"] for t, v in tg.items()}


def cmd_summary(path, db, json_out=None):
    tt = tile_types(db)
    per = collections.defaultdict(lambda: collections.Counter())
    tiles = collections.defaultdict(set)
    for tile, feat, _ in parse_fasm(path):
        ty = tt.get(tile, "?")
        per[ty][classify(db, ty, feat)] += 1
        tiles[ty].add(tile)
    cols = ["pip", "lut_init", "bram_init", "site"]
    print("%-24s %6s %8s %8s %9s %8s" % ("tile type", "tiles", "pips", "lut_init", "bram_init", "site"))
    tot = collections.Counter()
    for ty in sorted(per, key=lambda t: -sum(per[t].values())):
        c = per[ty]
        tot.update(c)
        print("%-24s %6d %8d %8d %9d %8d" % ((ty, len(tiles[ty])) + tuple(c[k] for k in cols)))
    print("%-24s %6d %8d %8d %9d %8d" % (("total", sum(len(v) for v in tiles.values()))
                                          + tuple(tot[k] for k in cols)))
    if json_out:
        json.dump({ty: dict(per[ty], tiles=len(tiles[ty])) for ty in per}, open(json_out, "w"), indent=1)


# ---------------------------------------------------------------- selftest

def selftest(db, part):
    """Hand-built cases: (1) the .bits line format; (2) round trip of chosen
    segbits through our frame addressing and prjxray's disassembler."""
    fr = {0x00400102: [0] * 101}
    fr[0x00400102][7] = (1 << 0) | (1 << 31)
    got = list(bits_lines(fr))
    assert got == ["bit_00400102_007_00", "bit_00400102_007_31"], got
    bd = bitdata_of(fr)
    assert bd == {0x00400102: ({7}, {224, 255})}, bd
    print("bits format: ok")
    if not have_prjxray():
        print("prjxray deps not importable here; rerun via the venv for the disassembler round trip")
        return
    import xc7_db
    tg = json.load(open(os.path.join(db, "xc7a50t", "tilegrid.json")))
    cases = [
        ("CLBLL_L", "CLB_IO_CLK", "segbits_clbll_l.db", "SLICEL_X0.ALUT.INIT[00]"),
        ("CLBLM_R", "CLB_IO_CLK", "segbits_clblm_r.db", "SLICEM_X0.AFF.ZINI"),
        ("INT_L", "CLB_IO_CLK", "segbits_int_l.db", None),       # first 2-bit PIP in the file
        ("DSP_R", "CLB_IO_CLK", "segbits_dsp_r.db", "DSP48.DSP_0.AREG_2"),
        ("BRAM_L", "BLOCK_RAM", "segbits_bram_l.block_ram.db", "RAMB18_Y0.INIT_00[000]"),
    ]
    frames = {}
    want = []
    for ttype, bus, segf, feat in cases:
        sb = xc7_db.load_segbits(os.path.join(db, segf))
        if feat is None:
            feat = next(k for k, v in sorted(sb.items()) if len(v) == 2 and not any(n for _, _, n in v)
                        and k.count(".") == 2)
            feat = feat.split(".", 1)[1]
        key = ttype + "." + feat
        if key not in sb:
            alt = [k for k in sb if k.startswith(ttype + "." + feat.split(".")[0])]
            sys.exit("selftest: %s not in %s (e.g. %s)" % (key, segf, alt[:3]))
        tile = sorted(t for t, v in tg.items() if v["type"] == ttype and bus in v["bits"])[3]
        info = tg[tile]["bits"][bus]
        base = int(info["baseaddr"], 16)
        for f, b, neg in sb[key]:
            if neg:
                continue
            words = frames.setdefault(base + f, [0] * 101)
            words[info["offset"] + b // 32] |= 1 << (b % 32)
        want.append("%s.%s" % (tile, feat))
    text, unknown, _ = disassemble(bitdata_of(frames), db, part)
    got = set()
    for ln in text.splitlines():
        ln = ln.strip()
        if ln:
            got.add(ln.split("=")[0].strip())
    for w in want:
        base = w.split("[")[0]
        ok = w in got or any(g.startswith(base) for g in got)
        print("  %-60s %s" % (w, "ok" if ok else "MISSING"))
        assert ok, (w, sorted(got)[:20])
    assert not unknown, unknown
    print("disassembler round trip: ok (%d features, 0 unexplained bits)" % len(want))


def main():
    a = sys.argv[1:]
    db, part, jout, bits = DEFAULT_DB, DEFAULT_PART, None, None
    unk = None
    for opt in ("--db", "--part", "--json", "--bits", "--unknown"):
        if opt in a:
            i = a.index(opt)
            v = a[i + 1]
            del a[i:i + 2]
            if opt == "--db":
                db = v
            elif opt == "--part":
                part = v
            elif opt == "--unknown":
                unk = v
            elif opt == "--json":
                jout = v
            else:
                bits = v
    if not a:
        sys.exit(__doc__)
    cmd = a[0]
    if cmd == "bits" and len(a) == 3:
        cmd_bits(a[1], a[2], db, part)
    elif cmd == "fasm" and len(a) == 3:
        if not have_prjxray():
            reexec_in_venv()
        cmd_fasm(a[1], a[2], db, part, bits, unk)
    elif cmd == "summary" and len(a) == 2:
        cmd_summary(a[1], db, jout)
    elif cmd == "selftest":
        if not have_prjxray() and os.path.exists(VENV_PY) and not os.environ.get("XC7_FASM_REEXEC"):
            reexec_in_venv()
        selftest(db, part)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
