#!/usr/bin/env python3
"""FLIX test oracle: compare a Ghidra instruction export with the objdump listing flix.dis (issue #97, A step 7).

usage:
  python3 -I tools/flix_compare.py addrs [flix.dis] > addrs.txt
      every instruction address in flix.dis (input for ExportListing.java decode mode)
  python3 -I tools/flix_compare.py entries [flix.dis] > tools/ghidra/entries_hifi4.tsv
      the HiFi4 function entry list IfdspHifi4FindFuncs.java uses (B10): every flix.dis function plus the
      EXTRA_ENTRIES below (real code without an `entry` instruction)
  python3 -I tools/flix_compare.py funcs <ghidra_functions.tsv> <out.tsv> [entries_hifi4.tsv] [flix.dis]
      compares Ghidra's function list (tools/ghidra/ExportFuncList.java) in the SRAM image with entries_hifi4.tsv and
      classifies every difference against flix.dis; exit 0 only if they match
  python3 -I tools/flix_compare.py compare <ghidra.tsv> <outdir> [flix.dis]
      writes <outdir>/summary.txt, <outdir>/mismatches.tsv (one row per mismatching instruction, sorted by
      group = reference mnemonic) and <outdir>/by_mnemonic.tsv (counts per reference mnemonic)

<ghidra.tsv> comes from tools/ghidra/ExportListing.java (columns addr, len, mnemonic, operands, bytes), either the
analysed listing (mode listing) or a flow-independent decode at every flix.dis address (mode decode).

Reference: every instruction line of flix.dis (49,389 instructions in 1,065 functions). The 461 `.byte` lines (padding
bytes objdump could not decode) are not instructions and are not compared. An instruction matches when Ghidra has an
instruction at the same address with the same length, the same mnemonic and the same operands after these rules (each
rule is counted in summary.txt, so it is visible how many matches depend on it):

  N1 layout     Case is ignored; whitespace is collapsed; operands are split at commas and trimmed. Ghidra and objdump
                differ only in separator spacing (`a1, 32` vs `a1,0x20`).
  N2 radix      An operand that is a plain integer literal on both sides is compared by value, so `32` == `0x20`.
                objdump prints values in -256..255 in decimal and the rest in hex; Ghidra prints hex. Only whole
                operands are compared this way: `0x20` never matches `a0`, and a non-numeric operand must match as text.
  N3 width      Two integer operands also match when they are equal modulo 2**32 (`0xfffffeff` == `-0x101`): the same
                32-bit value spelt signed on one side and unsigned on the other.
  N4 l32r       objdump appends the literal's value to an l32r target, `0x2064e8 (0x238400)`; the `(...)` part is the
                content of memory, not part of the instruction, and is dropped. The target itself is compared (N2).
  N5 comments   The `  ; FUN_xxx` name comments tools/ifdsp_hifi4_dis.py appends to call lines are dropped.
  N6 bundles    A FLIX bundle in flix.dis is `{ op1 args; op2 args; ... }`. The Ghidra text (mnemonic + operands) is
                parsed the same way: the outer braces are removed, slots are split at `;`, and each slot is compared as
                mnemonic + operands with N1-N3, in slot order. A bundle whose Ghidra text has no braces is compared as a
                one-slot instruction (so Ghidra's stock 3-byte `FLIX` placeholder is a mnemonic mismatch).

  N7 sr form   `rsr.ps a8` (objdump) == `rsr a8, PS` (Ghidra): for rsr/wsr/xsr/rur/wur the dotted form is rewritten to
                the operand form before comparing. The register name itself must still match (case-insensitive), so
                `rsr.interrupt` vs Ghidra's `INTSET` (same SR number 226) stays a mismatch.
  N8 mov alias  `or ar, as, as` == `mov ar, as`: Ghidra prints the MOV assembler alias of OR with equal sources.

Nothing else is normalised: register names (`aed3`, `b8:b9`, `f3`), mnemonic suffixes (`.n`, `.w15`, `.s`), signs and
operand order must be identical.

Mismatch kinds (first failing check wins): missing (Ghidra has no instruction starting at this address; detail says
whether the address is inside another Ghidra instruction or undecoded), error (decode mode: Ghidra could not decode),
length, slots (bundle with a different slot count), mnemonic, operands.
"""
import collections
import os
import re
import sys

LINE = re.compile(r"\s+([0-9a-f]+):\t([0-9a-f]+)\s*\t(.*)")
HEAD = re.compile(r";; ---- ([0-9a-f]{8}) (\S+)")
INT = re.compile(r"[-+]?(0x[0-9a-f]+|\d+)")
DEFAULT_ENTRIES = os.path.join(os.path.dirname(os.path.abspath(__file__)), "ghidra", "entries_hifi4.tsv")
SRAM_LO, SRAM_HI = 0x00200000, 0x00300000   # DSP image 1 and its bss (functions outside: TCM vectors from the setup)
# Real HiFi4 code that does not start with `entry` (so tools/ifdsp_hifi4_dis.py folds it into the previous function).
EXTRA_ENTRIES = [
    (0x002332C4, "call0 target from 0x228aa1, 0x228d18, 0x2333f7; reads WINDOWBASE/WINDOWSTART (window spill helper) [fact: flix.dis]"),
    (0x002354E0, "pointer at DTCM 0x24000004 (handler table); saves a0 in EXCSAVE4 (level-4 interrupt handler) [fact: image bytes]"),
]
DEFAULT_DIS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "decomp", "ifdsp", "hifi4", "flix.dis")


def parse_flix(path):
    """Return ([(addr, length, text, func)], n_byte_lines, [func entries])."""
    out, nbyte, funcs, func = [], 0, [], None
    for ln in open(path):
        h = HEAD.match(ln)
        if h:
            func = h.group(2)
            funcs.append(int(h.group(1), 16))
            continue
        m = LINE.match(ln)
        if not m:
            continue
        text = m.group(3).strip()
        if text.startswith(".byte"):
            nbyte += 1
            continue
        out.append((int(m.group(1), 16), len(m.group(2)) // 2, text, func))
    return out, nbyte, funcs


def strip_ref(text, used):
    """objdump text -> text without the N4/N5 annotations."""
    if text.startswith("{"):
        end = text.rfind("}")
        if end != len(text) - 1:
            used["N5 comments"] += 1
        text = text[:end + 1]
    elif "  ; " in text:
        used["N5 comments"] += 1
        text = text.split("  ; ")[0]
    t2 = re.sub(r"(l32r\s+a\d+,\s*0x[0-9a-f]+)\s*\(0x[0-9a-f]+\)", r"\1", text)
    if t2 != text:
        used["N4 l32r"] += 1
    return t2


def slots(text):
    """Split an instruction or bundle into [(mnemonic, [operands])], lower case, N1 layout."""
    t = " ".join(text.lower().split())
    bundle = t.startswith("{") and t.endswith("}")
    parts = [p.strip() for p in t[1:-1].split(";")] if bundle else [t]
    res = []
    for p in parts:
        if not p:
            continue
        sp = p.split(None, 1)
        ops = [o.strip() for o in sp[1].split(",")] if len(sp) > 1 else []
        res.append((sp[0], ops))
    return res, bundle


SRFORM = re.compile(r"(rsr|wsr|xsr|rur|wur)\.(\S+)$")


def canon(sl, used):
    """N7/N8 on one slot."""
    m, ops = sl
    sm = SRFORM.match(m)
    if sm and len(ops) == 1:
        used["N7 sr form"] += 1
        return sm.group(1), ops + [sm.group(2)]
    if m == "or" and len(ops) == 3 and ops[1] == ops[2]:
        return "mov", ops[:2]
    return m, ops


def int_val(s):
    if not INT.fullmatch(s):
        return None
    return int(s, 0)


def op_equal(a, b, used):
    if a == b:
        return True
    va, vb = int_val(a), int_val(b)
    if va is None or vb is None:
        return False
    if va == vb:
        used["N2 radix"] += 1
        return True
    if (va - vb) % (1 << 32) == 0:
        used["N3 width"] += 1
        return True
    return False


def group_key(ref_slots, bundle, length):
    if not bundle:
        return ref_slots[0][0]
    return "{%d}%s" % (length, "|".join(m for m, _ in ref_slots))


def compare(gtsv, outdir, dis):
    ref, nbyte, funcs = parse_flix(dis)
    g = {}
    for ln in open(gtsv):
        f = ln.rstrip("\n").split("\t")
        if f[0] == "addr" or len(f) < 4:
            continue
        g[int(f[0], 16)] = (int(f[1]), f[2], f[3])
    # coverage map for "inside another Ghidra instruction"
    starts = sorted(a for a, v in g.items() if v[0] > 0)
    import bisect

    def containing(a):
        i = bisect.bisect_right(starts, a) - 1
        if i >= 0 and starts[i] < a < starts[i] + g[starts[i]][0]:
            return starts[i]
        return None
    used = collections.Counter()
    kinds = collections.Counter()
    per = collections.defaultdict(collections.Counter)
    rows = []
    nmatch = 0
    nbundle = nbundle_match = 0
    func_bad = collections.Counter()
    for addr, length, text, func in ref:
        rtext = strip_ref(text, used)
        rs, rb = slots(rtext)
        key = group_key(rs, rb, length)
        nbundle += rb
        per[key]["total"] += 1
        gi = g.get(addr)
        kind = detail = ""
        gtext = ""
        if gi is None:
            kind = "missing"
            c = containing(addr)
            detail = "inside %08x" % c if c is not None else "undecoded"
        elif gi[1] == "!error":
            kind, detail = "error", gi[2]
        else:
            gtext = (gi[1] + " " + gi[2]).strip()
            gs, gb = slots(gtext)
            if gi[0] != length:
                kind, detail = "length", "%d vs %d" % (gi[0], length)
            elif len(gs) != len(rs):
                kind, detail = "slots", "%d vs %d" % (len(gs), len(rs))
            else:
                for i, (r0, g0) in enumerate(zip(rs, gs)):
                    (rm, ro), (gm, go) = canon(r0, used), canon(g0, used)
                    if r0[0] == "or" and g0[0] == "mov" and rm == "mov":
                        used["N8 mov alias"] += 1
                    if rm != gm:
                        kind, detail = "mnemonic", "slot %d: %s vs %s" % (i, gm, rm)
                        break
                    if len(ro) != len(go) or not all(op_equal(x, y, used) for x, y in zip(ro, go)):
                        kind, detail = "operands", "slot %d" % i
                        break
        if kind:
            kinds[kind] += 1
            per[key][kind] += 1
            func_bad[func] += 1
            rows.append((key, kind, "%08x" % addr, func, str(length), str(gi[0]) if gi else "", rtext, gtext, detail))
        else:
            nmatch += 1
            nbundle_match += rb
            per[key]["match"] += 1
    # Ghidra instructions inside flix.dis function ranges that start at no reference boundary (mid-instruction decode)
    refaddr = {a for a, _, _, _ in ref}
    lo, hi = min(refaddr), max(a + n for a, n, _, _ in ref)
    extra = sum(1 for a in g if lo <= a < hi and a not in refaddr and g[a][1] != "!error")
    os.makedirs(outdir, exist_ok=True)
    rows.sort(key=lambda r: (r[0], r[2]))
    with open(os.path.join(outdir, "mismatches.tsv"), "w") as fo:
        fo.write("group\tkind\taddr\tfunction\tlen_ref\tlen_ghidra\tref\tghidra\tdetail\n")
        for r in rows:
            fo.write("\t".join(x.replace("\t", " ") for x in r) + "\n")
    cols = ["total", "match", "missing", "error", "length", "slots", "mnemonic", "operands"]
    with open(os.path.join(outdir, "by_mnemonic.tsv"), "w") as fo:
        fo.write("group\t" + "\t".join(cols) + "\n")
        for k in sorted(per, key=lambda k: (-(per[k]["total"] - per[k]["match"]), k)):
            fo.write(k + "\t" + "\t".join(str(per[k][c]) for c in cols) + "\n")
    n = len(ref)
    nf = len(funcs)
    fully = nf - len(func_bad)
    lines = [
        "reference: %s" % os.path.relpath(dis),
        "ghidra export: %s (%d rows)" % (gtsv, len(g)),
        "reference instructions %d (bundles %d) in %d functions; %d .byte lines not compared" % (n, nbundle, nf, nbyte),
        "MATCH %d / %d = %.2f %%" % (nmatch, n, 100.0 * nmatch / n),
        "bundles matching %d / %d = %.2f %%" % (nbundle_match, nbundle, 100.0 * nbundle_match / max(nbundle, 1)),
        "non-bundle instructions matching %d / %d = %.2f %%" % (
            nmatch - nbundle_match, n - nbundle, 100.0 * (nmatch - nbundle_match) / max(n - nbundle, 1)),
        "functions with every instruction matching %d / %d" % (fully, nf),
        "mismatches by kind: " + ", ".join("%s %d" % kv for kv in kinds.most_common()),
        "Ghidra instructions inside the reference range not at a reference address (mid-instruction decodes): %d" % extra,
        "normalisation rules applied: " + ", ".join("%s %d" % kv for kv in sorted(used.items())),
    ]
    with open(os.path.join(outdir, "summary.txt"), "w") as fo:
        fo.write("\n".join(lines) + "\n")
    print("\n".join(lines))
    return 0 if nmatch == n else 1


def classify(a, ref):
    """Why an address is (not) a flix.dis function entry: rodata, inside bundleN, inside insn, boundary:<mnemonic>, padding."""
    import bisect
    starts = [x for x, _, _, _ in ref]
    if not (starts[0] <= a < ref[-1][0] + ref[-1][1]):
        return "rodata/data" if SRAM_LO <= a < SRAM_HI else "outside SRAM"
    i = bisect.bisect_right(starts, a) - 1
    s, n, t, f = ref[i]
    if s == a:
        return "boundary:%s in %s" % ("bundle" if t.startswith("{") else t.split()[0], f)
    if a < s + n:
        return "inside %s at %08x in %s" % ("bundle%d" % n if t.startswith("{") else "insn", s, f)
    return "padding in %s" % f


def entries(dis):
    _, _, funcs = parse_flix(dis)
    out = ["entry\tsource\tnote"]
    rows = [(a, "flix.dis", "") for a in funcs] + [(a, "extra", n) for a, n in EXTRA_ENTRIES]
    for a, src, note in sorted(rows):
        out.append("%08x\t%s\t%s" % (a, src, note))
    sys.stdout.write("\n".join(out) + "\n")
    return 0


def funcs(gtsv, out, etsv, dis):
    ref, _, ffuncs = parse_flix(dis)
    want = {}
    for ln in open(etsv):
        f = ln.rstrip("\n").split("\t")
        if f[0] != "entry":
            want[int(f[0], 16)] = f[1]
    have, other = {}, []
    for ln in open(gtsv):
        f = ln.rstrip("\n").split("\t")
        if f[0] == "entry":
            continue
        a = int(f[0], 16)
        if SRAM_LO <= a < SRAM_HI:
            have[a] = f[1]
        else:
            other.append(a)
    rows = [("%08x" % a, "extra in Ghidra", have[a], classify(a, ref)) for a in sorted(set(have) - set(want))]
    rows += [("%08x" % a, "missing in Ghidra", want[a], classify(a, ref)) for a in sorted(set(want) - set(have))]
    with open(out, "w") as fo:
        fo.write("entry\tdiff\tname_or_source\tclass\n")
        for r in sorted(rows):
            fo.write("\t".join(r) + "\n")
    cls = collections.Counter((r[1], r[3].split(" ")[0] + (" " + r[3].split(" ")[1] if r[3].startswith("inside") else ""))
                              for r in rows)
    fl = set(ffuncs)
    print("Ghidra functions: %d in SRAM, %d elsewhere (TCM vectors from IfdspHifi4Setup.java)" % (len(have), len(other)))
    print("reference %s: %d entries (%d from flix.dis, %d extra); flix.dis has %d functions"
          % (os.path.relpath(etsv), len(want), sum(1 for v in want.values() if v == "flix.dis"),
             sum(1 for v in want.values() if v != "flix.dis"), len(fl)))
    print("vs flix.dis: %d Ghidra entries not in flix.dis, %d flix.dis entries not in Ghidra"
          % (len(set(have) - fl), len(fl - set(have))))
    print("vs reference: %d extra, %d missing%s" % (len(set(have) - set(want)), len(set(want) - set(have)),
                                                   "" if rows else " -> MATCH"))
    for k, v in sorted(cls.items()):
        print("  %-18s %-22s %d" % (k[0], k[1], v))
    return 0 if not rows else 1


def main():
    if len(sys.argv) >= 2 and sys.argv[1] == "entries":
        return entries(sys.argv[2] if len(sys.argv) > 2 else DEFAULT_DIS)
    if len(sys.argv) >= 4 and sys.argv[1] == "funcs":
        return funcs(sys.argv[2], sys.argv[3], sys.argv[4] if len(sys.argv) > 4 else DEFAULT_ENTRIES,
                     sys.argv[5] if len(sys.argv) > 5 else DEFAULT_DIS)
    if len(sys.argv) >= 2 and sys.argv[1] == "addrs":
        ref, _, _ = parse_flix(sys.argv[2] if len(sys.argv) > 2 else DEFAULT_DIS)
        sys.stdout.write("".join("%08x\n" % a for a, _, _, _ in ref))
        return 0
    if len(sys.argv) >= 4 and sys.argv[1] == "compare":
        return compare(sys.argv[2], sys.argv[3], sys.argv[4] if len(sys.argv) > 4 else DEFAULT_DIS)
    sys.stderr.write(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main())
