#!/usr/bin/env python3
"""Measure how much of the HiFi4 code Ghidra cannot represent (docs/code/ifdsp/ghidra-flix.md).

Usage: python3 -I tools/flix_stats.py [decomp/ifdsp/hifi4/flix.dis] [GHIDRA_XTENSA_LANGUAGES_DIR]

Reads the FLIX-aware objdump listing and prints: functions with bundles, bundle count, sizes and slots, bundles with a branch or
loop in a slot, the operand-heuristic count of bundles where one slot writes a register another slot names, and the operations
Ghidra's Xtensa module does not know (or knows only on the f0..f15 registers, while this core's FPU uses aed0..15). The Ghidra
directory is optional (default: the Homebrew 12.1.4 install); without it the last part is skipped.
"""
import collections
import glob
import os
import re
import sys

LINE = re.compile(r"\s+[0-9a-f]+:\t([0-9a-f]+)\s*\t(.*)")
CTRL = re.compile(r"(b[a-z]*|j|jx|call|callx|ret|retw|loop)")
NODEST = re.compile(r"^(s8i|s16i|s32i|ssi|ssip|ssx|ae_s|b|j|loop|nop|call|ret|wsr|wur|wfr?$|memw|isync)")


def main():
    dis = sys.argv[1] if len(sys.argv) > 1 else "decomp/ifdsp/hifi4/flix.dis"
    gdir = sys.argv[2] if len(sys.argv) > 2 else \
        "/opt/homebrew/opt/ghidra/libexec/Ghidra/Processors/Xtensa/data/languages"
    funcs = with_flix = insns = code = flix_bytes = ctrl = hazard = 0
    in_func_flix = False
    sizes, nslots, ops, ops_aed = collections.Counter(), collections.Counter(), collections.Counter(), collections.Counter()
    for ln in open(dis):
        if ln.startswith(";; ----"):
            funcs += 1
            with_flix += in_func_flix
            in_func_flix = False
            continue
        m = LINE.match(ln)
        if not m or m.group(2).startswith(".byte"):
            continue
        n, text = len(m.group(1)) // 2, m.group(2).strip()
        insns += 1
        code += n
        slots = [s.strip() for s in text.strip("{} ").split(";") if s.strip()] if text.startswith("{") else [text]
        if text.startswith("{"):
            in_func_flix = True
            flix_bytes += n
            sizes[n] += 1
            nslots[len(slots)] += 1
            parsed = []
            for s in slots:
                p = s.split(None, 1)
                args = [a.strip() for a in p[1].split(",")] if len(p) > 1 else []
                parsed.append((None if NODEST.match(p[0]) or not args else args[0], args, p[0]))
            ctrl += any(CTRL.match(op) and not op.startswith("bmov") for _, _, op in parsed)
            hazard += any(d and any(d in a for j, (_, a, _) in enumerate(parsed) if j != i)
                          for i, (d, _, _) in enumerate(parsed))
        for s in slots:
            op = s.split()[0]
            ops[op] += 1
            if "aed" in s:
                ops_aed[op] += 1
    with_flix += in_func_flix
    bundles = sum(sizes.values())
    print(f"functions {funcs}, with FLIX bundles {with_flix} ({100 * with_flix / funcs:.0f} %)")
    print(f"instructions {insns}, bundles {bundles} ({100 * bundles / insns:.0f} %), "
          f"code bytes {code}, in bundles {flix_bytes} ({100 * flix_bytes / code:.0f} %)")
    print(f"bundle sizes {dict(sizes)}, slots per bundle {dict(sorted(nslots.items()))}")
    print(f"bundles with a branch/loop slot {ctrl} ({100 * ctrl / bundles:.0f} %), "
          f"with an intra-bundle register dependency (heuristic) {hazard} ({100 * hazard / bundles:.0f} %)")
    total = sum(ops.values())
    print(f"distinct operations {len(ops)}, occurrences {total}")
    sincs = glob.glob(os.path.join(gdir, "*.sinc"))
    if not sincs:
        print(f"(no Ghidra Xtensa .sinc files in {gdir}; skipping the comparison)")
        return 0
    known = {m.lower() for f in sincs for m in re.findall(r"^:([A-Za-z0-9_.]+)", open(f).read(), re.M)}

    def is_known(op):
        b = op.replace(".w15", "").replace(".n", "")
        return op in known or b in known or bool(re.match(r"(rsr|wsr|xsr|rur|wur)\.", op))
    unknown = {o: c for o, c in ops.items() if not is_known(o)}
    wrong = {o: c for o, c in ops_aed.items() if is_known(o) and not o.startswith("call")}
    ae = sum(o.startswith("ae_") for o in unknown)
    print(f"not in Ghidra: {len(unknown)} ({ae} ae_*, {len(unknown) - ae} other), "
          f"{sum(unknown.values())} occurrences ({100 * sum(unknown.values()) / total:.1f} %)")
    print(f"in Ghidra but on aed registers: {len(wrong)} ops, {sum(wrong.values())} occurrences; "
          f"together {100 * (sum(unknown.values()) + sum(wrong.values())) / total:.1f} % of operations")
    return 0


if __name__ == "__main__":
    sys.exit(main())
