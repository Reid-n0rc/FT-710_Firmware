#!/usr/bin/env python3
"""Find which XC7A50T package(s) bond every IOB site the SDR bitstream uses, and list the pins.

Usage: python3 -I tools/xc7_package_fit.py [--any] build/sdr/FT-710_SDR_V0104.fasm [PACKAGE]

Input: the FASM produced from the SDR bitstream (T15, prjxray bit2fasm). An IOB
site counts as used when it has an input-buffer, drive-strength, IN_DIFF or
output feature (same rule as docs/code/sdr/resources.md); with --any, a site
counts when it has any FASM feature at all. For each package the number of
bonded IOB sites (all user I/O) is printed too. The package pin maps
come from prjxray-db (`<db>/xc7a50t<pkg>-1/package_pins.csv`, env PRJXRAY_DB,
default ~/.local/share/ft710-tools/prjxray-db/artix7). With PACKAGE, the used
pins of that package are listed (ball, bank, site, pin function, IOB features).
"""
import collections
import csv
import json
import os
import re
import sys

DB = os.environ.get("PRJXRAY_DB", os.path.expanduser("~/.local/share/ft710-tools/prjxray-db/artix7"))
PACKAGES = ["cpg236", "csg324", "csg325", "fgg484", "ftg256"]


def used_sites(fasm_path, any_feature=False):
    tg = json.load(open(os.path.join(DB, "xc7a50t", "tilegrid.json")))
    feats = collections.defaultdict(set)
    with open(fasm_path) as fh:
        for line in fh:
            m = re.match(r"([LR]IOB33(?:_SING)?_X\d+Y\d+)\.(IOB_Y[01])\.(\S+)", line)
            if m:
                feats[(m.group(1), m.group(2))].add(m.group(3))
    sites = {}
    for (tile, y), f in feats.items():
        if not any_feature and not any(".IN" in x or "IN_ONLY" in x or "DRIVE" in x or "IN_DIFF" in x or ".OUT" in x for x in f):
            continue
        iobs = sorted((s for s, t in tg[tile]["sites"].items() if t.startswith("IOB")),
                      key=lambda s: int(re.search(r"Y(\d+)$", s).group(1)))
        # prjxray IOB_Y0 is the master (IOB33M, P pin, higher Y; its wires end in 0,
        # tile_type_LIOB33.json) and carries the LVDS .OUT features; IOB_Y1 is the slave.
        site = iobs[0] if len(iobs) == 1 else (iobs[1] if y == "IOB_Y0" else iobs[0])
        sites[site] = (tile, y, f)
    return sites


def main(argv):
    any_feature = "--any" in argv
    argv = [a for a in argv if a != "--any"]
    if not argv:
        sys.exit(__doc__)
    sites = used_sites(argv[0], any_feature)
    print(f"{'IOB sites with any feature' if any_feature else 'used IOB sites'}: {len(sites)}")
    for pkg in PACKAGES:
        path = os.path.join(DB, f"xc7a50t{pkg}-1", "package_pins.csv")
        if not os.path.exists(path):
            print(f"{pkg}: no package_pins.csv")
            continue
        pins = {r["site"]: r for r in csv.DictReader(open(path))}
        unb = sorted(set(sites) - set(pins))
        banks = collections.Counter(pins[s]["bank"] for s in sites if s in pins)
        nbond = sum(1 for k in pins if k.startswith("IOB_"))
        print(f"{pkg} ({nbond} bonded IOB sites): {len(sites) - len(unb)} of {len(sites)} bonded"
              + (f", unbonded e.g. {unb[:6]}" if unb else f", banks {dict(sorted(banks.items()))}"))
        if len(argv) > 1 and argv[1] == pkg:
            for s in sorted(sites, key=lambda s: (pins.get(s, {}).get("bank", ""), pins.get(s, {}).get("pin", ""))):
                r = pins.get(s, {"pin": "-", "bank": "-", "pin_function": "unbonded"})
                f = sorted(x for x in sites[s][2] if "DRIVE" in x or "IN" in x.split(".")[-1] or "DIFF" in x or "OUT" in x
                           or "SLEW" in x)
                print(f"  {r['pin']:5} bank {r['bank']:3} {s:12} {r['pin_function']:22} {' '.join(f)[:140]}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
