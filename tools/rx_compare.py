#!/usr/bin/env python3
"""Compare Ghidra's RX listing of the MAIN image with GNU binutils rx-elf-objdump, instruction by instruction (T21c, #97 B1).

Usage (stdlib only; run with python3 -I):
  python3 -I tools/rx_compare.py <ghidra.tsv> <image.bin> [--base 0xFFF80000] [--objdump PATH]
                                 [--all] [--diffs out.tsv] [--jobs N]

<ghidra.tsv> comes from tools/ghidra/ListingExport.java (addr, len, bytes, mnemonic, operands, function entry).
By default only instructions inside a function body are compared; --all adds the instructions outside every function.

Method: the Ghidra instructions are grouped into runs of back-to-back instructions; every run is disassembled by
objdump from its first address to its end (`-D -b binary -m rx --adjust-vma=BASE --start-address --stop-address`),
so objdump starts on the same instruction boundary as Ghidra. Each Ghidra instruction is then matched with the objdump
instruction at the same address and compared on length, mnemonic and operands.

Result classes:
  same       length, mnemonic and operands agree after normalisation
  different  objdump decodes an instruction at the same address but length, mnemonic or operands differ
  missing    objdump has no instruction starting at this address (it decoded a different length earlier in the run)
  bad        objdump prints "(bad)" or ".byte" there (objdump cannot decode the bytes)
  undefined  ?UNDEF holes inside function bodies (bytes Ghidra did not disassemble)

Normalisation rules (each one is a pure notation difference between the two disassemblers):
  N1  case and blanks are ignored; mnemonic and operands are lower-cased.
  N2  SP is R0 (objdump always prints r0).
  N3  the immediate marker '#' is dropped (Ghidra prints some immediates without it, e.g. CMP 0x1,R14).
  N4  numbers are compared as integers, hex or decimal; a negative number also equals its two's-complement value modulo
      2^8, 2^16, 2^24 or 2^32 (Ghidra prints a sign-extended byte immediate as -0x1 where objdump prints #255).
  N5  objdump's three-operand form "OP src, Rn, Rn" (src2 == dest) equals Ghidra's two-operand "OP src, Rn".
  N6  a zero displacement is dropped: 0x0[Rn] == [Rn].
  N7  memory-extension suffixes: objdump ".l" on a memory operand ("4[r1].l") is optional; Ghidra prints none for L.
  N8  condition-code synonyms: objdump uses the C/NC spellings, Ghidra the GEU/LTU ones (BC = BGEU, BNC = BLTU,
      SCC = SCGEU, SCNC = SCLTU, BMC = BMGEU, BMNC = BMLTU; RXv2 manual, condition table), see MNEM_ALIASES.
  N9  register ranges: objdump's "r1-r5" (PUSHM/POPM/RTSD) is Ghidra's two operands "R1,R5".
  N10 Ghidra puts the flag operand of SETPSW/CLRPSW into the mnemonic ("SETPSW I "); it is split off as an operand.
Everything else is reported as a difference.
"""
import argparse
import collections
import concurrent.futures
import os
import re
import subprocess
import sys

DEF_OBJDUMP = os.path.expanduser("~/opt/rx-binutils-2.47/bin/rx-elf-objdump")
LINE = re.compile(r"^\s*([0-9a-f]+):\t((?:[0-9a-f]{2} )+)\s*\t(\S+)(?:\s+(.*))?$")
NUM = re.compile(r"-?0x[0-9a-f]+|-?\d+")

# N8: mnemonic spellings that mean the same instruction (objdump name -> Ghidra name), filled from the diff review.
MNEM_ALIASES = {}
for _sfx in ("", ".s", ".b", ".w", ".l"):
    for _od, _gh in (("bc", "bgeu"), ("bnc", "bltu"), ("scc", "scgeu"), ("scnc", "scltu"), ("bmc", "bmgeu"),
                     ("bmnc", "bmltu")):
        MNEM_ALIASES[_od + _sfx] = _gh + _sfx


def load_ghidra(path, include_all):
    rows = []
    with open(path, encoding="utf-8") as f:
        for line in f:
            p = line.rstrip("\n").split("\t")
            if len(p) < 6:
                continue
            addr, ln, by, mn, ops, fn = int(p[0], 16), int(p[1]), p[2], p[3], p[4], p[5]
            if " " in mn.strip():                                        # N10
                mn, extra = mn.strip().split(None, 1)
                ops = extra + ("," + ops if ops else "")
            if fn == "-" and not include_all:
                continue
            rows.append((addr, ln, by, mn, ops, fn))
    rows.sort()
    return rows


def runs_of(rows):
    out, cur = [], None
    for r in rows:
        if r[3] == "?UNDEF":
            continue
        if cur and cur[1] == r[0]:
            cur[1] = r[0] + r[1]
        else:
            cur = [r[0], r[0] + r[1]]
            out.append(cur)
    return out


def objdump_run(objdump, image, base, start, stop):
    cmd = [objdump, "-D", "-b", "binary", "-m", "rx", "--adjust-vma=0x%x" % base, "--insn-width=12",
           "--start-address=0x%x" % start, "--stop-address=0x%x" % stop, image]
    res = subprocess.run(cmd, capture_output=True, text=True, check=True).stdout
    ins = {}
    for line in res.splitlines():
        m = LINE.match(line)
        if m:
            a = int(m.group(1), 16)
            ins[a] = (len(m.group(2).split()), m.group(3), (m.group(4) or "").strip())
    return ins


def split_ops(s):
    """Split at top-level commas (none of the RX operand syntaxes nests commas inside brackets)."""
    s = s.strip()
    if not s:
        return []
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "[(":
            depth += 1
        elif ch in "])":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    out.append(cur)
    return out


def norm_op(op):
    op = op.lower().replace(" ", "")            # N1
    op = re.sub(r"\bsp\b", "r0", op)           # N2
    op = op.replace("#", "")                    # N3
    op = re.sub(r"^(?:0x0|0)\[", "[", op)       # N6
    if "[" in op and op.endswith(".l"):         # N7
        op = op[:-2]
    nums = [int(n, 0) if not n.startswith("-") else -int(n[1:], 0) for n in NUM.findall(op)]
    shape = NUM.sub("N", op)
    return shape, nums


def nums_equal(a, b):
    if a == b:
        return True
    if min(a, b) >= 0:
        return False
    return any((a - b) % (1 << k) == 0 for k in (8, 16, 24, 32))  # N4


def expand_ranges(ops):
    out = []
    for x in ops:
        m = re.fullmatch(r"\s*(r\d+)-(r\d+)\s*", x, re.I)            # N9
        out.extend([m.group(1), m.group(2)] if m else [x])
    return out


def ops_equal(gops, oops):
    g = [norm_op(x) for x in split_ops(gops)]
    o = [norm_op(x) for x in expand_ranges(split_ops(oops))]
    if len(o) == 3 and len(g) == 2 and o[1] == o[2]:     # N5
        o = o[:2]
    if len(g) != len(o):
        return False
    for (gs, gn), (os_, on) in zip(g, o):
        if gs != os_ or len(gn) != len(on):
            return False
        if not all(nums_equal(x, y) for x, y in zip(gn, on)):
            return False
    return True


def norm_mnem(m):
    m = m.lower()
    return MNEM_ALIASES.get(m, m)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("ghidra")
    ap.add_argument("image")
    ap.add_argument("--base", default="0xFFF80000")
    ap.add_argument("--objdump", default=DEF_OBJDUMP)
    ap.add_argument("--all", action="store_true", help="also compare instructions outside functions")
    ap.add_argument("--diffs", help="write every non-'same' instruction to this TSV")
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    a = ap.parse_args()
    base = int(a.base, 0)

    rows = load_ghidra(a.ghidra, a.all)
    runs = runs_of(rows)
    od = {}
    with concurrent.futures.ThreadPoolExecutor(a.jobs) as ex:
        for part in ex.map(lambda r: objdump_run(a.objdump, a.image, base, r[0], r[1]), runs):
            od.update(part)

    counts = collections.Counter()
    kinds = collections.Counter()
    examples = {}
    diffs = []
    nbytes = 0
    for addr, ln, by, mn, ops, fn in rows:
        if mn == "?UNDEF":
            cls, o = "undefined", None
        else:
            nbytes += ln
            o = od.get(addr)
            if o is None:
                cls = "missing"
            elif o[1] in ("(bad)", ".byte", ".word") or o[1].startswith("."):
                cls = "bad"
            elif o[0] == ln and norm_mnem(o[1]) == mn.lower() and ops_equal(ops, o[2]):
                cls = "same"
            else:
                cls = "different"
        counts[cls] += 1
        if cls != "same":
            key = (cls, mn, o[1] if o else "-")
            kinds[key] += 1
            examples.setdefault(key, (addr, by, mn, ops, o))
            diffs.append((addr, ln, by, mn, ops, fn, cls, o))

    total = sum(counts.values())
    print("compared %d Ghidra entries (%d code bytes) in %d runs; objdump %s" % (total, nbytes, len(runs), a.objdump))
    for c in ("same", "different", "missing", "bad", "undefined"):
        print("  %-10s %7d" % (c, counts[c]))
    if kinds:
        print("difference classes (class, Ghidra mnemonic, objdump mnemonic: count, first example):")
        for key, n in kinds.most_common():
            ad, by, mn, ops, o = examples[key]
            print("  %-9s %-10s %-10s %6d  %08x %s  ghidra '%s %s'  objdump %s" %
                  (key[0], key[1], key[2], n, ad, by, mn, ops, "'%s %s' len %d" % (o[1], o[2], o[0]) if o else "-"))
    if a.diffs:
        with open(a.diffs, "w", encoding="utf-8") as f:
            f.write("addr\tlen\tbytes\tghidra_mnem\tghidra_ops\tfunction\tclass\tobjdump_len\tobjdump_mnem\tobjdump_ops\n")
            for addr, ln, by, mn, ops, fn, cls, o in diffs:
                f.write("%08x\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n" % (addr, ln, by, mn, ops, fn, cls,
                                                            "\t".join(map(str, o)) if o else "\t\t"))
    return 0 if counts["same"] == total else 1


if __name__ == "__main__":
    sys.exit(main())
