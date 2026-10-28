#!/usr/bin/env python3
"""Compare Ghidra's RX listing of the MAIN image with GNU binutils rx-elf-objdump and/or rizin, instruction by instruction
(T21c, #97 B1; rizin lane and three-way mode T22a, #104).

Usage (stdlib only; run with python3 -I):
  python3 -I tools/rx_compare.py <ghidra.tsv> <image.bin> [--base 0xFFF80000] [--objdump PATH]
                                 [--ref objdump|rizin|both] [--rizin PATH]
                                 [--all] [--diffs out.tsv] [--jobs N]

--ref objdump (default) is the T21c check. --ref rizin uses rizin's `rx` disassembler plugin (`pD len @ addr` per run,
see R1-R8 below) instead. --ref both runs the two and also prints a three-way table per instruction: all agree,
only objdump differs, only rizin differs, both differ (then objdump and rizin are compared with each other too).

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

rizin (0.9.1 `rx` plugin) prints the encoded fields rather than assembler syntax. Its text is first rewritten into the
objdump form above (rizin_to_od), then compared with the same rules. Each rewrite only undoes a printing convention:
  R1  the trailing ", " after the last operand is dropped; "[r1,r2]" spacing as N1.
  R2  a size-less "mov" (MOV #imm,Rd and MOV #uimm4,Rd forms) is "mov.l" (manual: .L is the only size of those forms).
  R3  ".UB" on the mnemonic ("add.UB 0x3[r0], r14") belongs to the memory operand ("0x3[r0].ub"); on a register-register
      form (ld = 11) it carries no meaning and is dropped.
  R4  displacements are printed as the encoded dsp field; the manual scales dsp:5/dsp:8/dsp:16 by the operand size
      (x2 for .W/.UW, x4 for .L), so the printed value is multiplied by the size (operand memex, else the mnemonic
      size, else .B for the bit ops BSET/BCLR/BTST/BNOT, else .L). Bit ops on memory get the implied ".b".
  R5  branch operands are the displacement ("bra.S #0x4", "bsr.A #0x301"); the target is addr + dsp, with dsp signed
      for .B/.W/.A (8/16/24 bits) and unsigned 3..10 for .S.
  R6  RTSD's immediate is the encoded field (bytes/4); it is multiplied by 4.
  R7  "invalid" is class 'bad' (rizin cannot decode the bytes).
  R8  a rizin length that differs from Ghidra's is class 'different' (as for objdump); the run then resyncs.
Not normalised (reported as differences, settled in docs/tasks/T22-rea-verification.md, T22a): rizin's RTSD #imm,Rd-Rd2
shows only Rd2, and the RXv2 encodings rizin lacks.
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


DEF_RIZIN = os.path.expanduser("~/opt/rizin-0.9.1/bin/rizin")
RZ_LINE = re.compile(r"^\s*0x([0-9a-f]+)\s+([0-9a-f]+)\s+(.*)$")
SIZE_BYTES = {"b": 1, "ub": 1, "w": 2, "uw": 2, "l": 4}
BIT_OPS = ("bset", "bclr", "btst", "bnot")


def rizin_runs(rizin, image, base, runs, tmpdir, jobs):
    """Disassemble every run with one rizin process per chunk of runs; returns {addr: (len, mnem, ops)} in objdump form."""
    os.makedirs(tmpdir, exist_ok=True)
    chunks = [runs[i::jobs] for i in range(jobs) if runs[i::jobs]]

    def job(arg):
        i, chunk = arg
        cf = os.path.join(tmpdir, "rz%d.cmd" % i)
        with open(cf, "w", encoding="utf-8") as f:
            f.write("".join("pD %d @ 0x%x\n" % (b - a, a) for a, b in chunk))
        cmd = [rizin, "-q", "-N", "-a", "rx", "-b", "32", "-m", "0x%x" % base, "-i", cf]
        for e in ("scr.color=0", "asm.lines=false", "asm.xrefs=false", "asm.comments=false", "asm.bytes=true",
                  "asm.nbytes=16", "asm.flags=false"):
            cmd[1:1] = ["-e", e]
        return subprocess.run(cmd + [image], capture_output=True, text=True, check=True).stdout

    ins = {}
    with concurrent.futures.ThreadPoolExecutor(len(chunks) or 1) as ex:
        for out in ex.map(job, enumerate(chunks)):
            for line in out.splitlines():
                m = RZ_LINE.match(line)
                if m:
                    a = int(m.group(1), 16)
                    ins[a] = (len(m.group(2)) // 2,) + rizin_to_od(a, m.group(3))
    return ins


def _sext(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def rizin_to_od(addr, text):
    """Rewrite one rizin rx instruction into objdump notation (rules R1-R7)."""
    text = text.strip().rstrip(",").strip()                                  # R1
    if not text or text.split()[0] == "invalid":
        return ("(bad)", "")                                                 # R7
    parts = text.split(None, 1)
    mn, ops = parts[0].lower(), (parts[1] if len(parts) > 1 else "")
    ol = [o.strip() for o in split_ops(ops)]
    if mn == "mov":                                                          # R2
        mn = "mov.l"
    memex = None
    if mn.endswith(".ub") and not mn.startswith("b"):                       # R3
        mn, memex = mn[:-3], "ub"
    base_mn, _, sfx = mn.partition(".")
    if re.fullmatch(r"b(ra|sr|eq|ne|ge|gt|le|lt|geu|gtu|leu|ltu|pz|n|c|nc|o|no)", base_mn) and ol and ol[0].startswith("#"):
        d = int(ol[0][1:], 0)                                                # R5
        bits = {"b": 8, "w": 16, "a": 24}.get(sfx)
        if bits:
            d = _sext(d, bits)
        return (mn, "0x%x" % ((addr + d) & 0xFFFFFFFF))
    if base_mn == "rtsd" and ol:                                             # R6
        ol[0] = "#%d" % (int(ol[0].lstrip("#"), 0) * 4)
    out = []
    for o in ol:
        m = re.fullmatch(r"(0x[0-9a-f]+|\d+)\[(\w+)\](?:\.(\w+))?", o, re.I)
        if m:                                                                # R4
            ex_ = (m.group(3) or memex or "").lower()
            if ex_:
                size = SIZE_BYTES[ex_]
            elif sfx in SIZE_BYTES:
                size = SIZE_BYTES[sfx]
            elif base_mn in BIT_OPS:
                size = 1
            else:
                size = 4
            o = "%d[%s]" % (int(m.group(1), 0) * size, m.group(2))
            if ex_:
                o += "." + ex_
            elif base_mn in BIT_OPS:
                o += ".b"
        elif memex and "[" in o:
            o += "." + memex
        elif base_mn in BIT_OPS and o.startswith("["):
            o += ".b"
        out.append(o)
    return (mn, ", ".join(out))


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




def classify(ln, mn, ops, o):
    if o is None:
        return "missing"
    if o[1] in ("(bad)", ".byte", ".word") or o[1].startswith("."):
        return "bad"
    if o[0] == ln and norm_mnem(o[1]) == mn.lower() and ops_equal(ops, o[2]):
        return "same"
    return "different"


def refs_equal(x, y):
    """objdump vs rizin, both already in objdump notation."""
    if x is None or y is None or x[0] != y[0] or norm_mnem(x[1]) != norm_mnem(y[1]):
        return False
    a = [norm_op(v) for v in expand_ranges(split_ops(x[2]))]
    b = [norm_op(v) for v in expand_ranges(split_ops(y[2]))]
    a = a[:2] if len(a) == 3 and a[1] == a[2] else a
    b = b[:2] if len(b) == 3 and b[1] == b[2] else b
    return len(a) == len(b) and all(p[0] == q[0] and len(p[1]) == len(q[1]) and all(nums_equal(m, n) for m, n in
                                                                                   zip(p[1], q[1])) for p, q in zip(a, b))


def report(name, path, rows, ref, nruns, diffs_path):
    counts, kinds, examples, diffs, nbytes = collections.Counter(), collections.Counter(), {}, [], 0
    classes = {}
    for addr, ln, by, mn, ops, fn in rows:
        if mn == "?UNDEF":
            cls, o = "undefined", None
        else:
            nbytes += ln
            o = ref.get(addr)
            cls = classify(ln, mn, ops, o)
        classes[addr] = cls
        counts[cls] += 1
        if cls != "same":
            key = (cls, mn, o[1] if o else "-")
            kinds[key] += 1
            examples.setdefault(key, (addr, by, mn, ops, o))
            diffs.append((addr, ln, by, mn, ops, fn, cls, o))
    total = sum(counts.values())
    print("compared %d Ghidra entries (%d code bytes) in %d runs; %s %s" % (total, nbytes, nruns, name, path))
    for c in ("same", "different", "missing", "bad", "undefined"):
        print("  %-10s %7d" % (c, counts[c]))
    if kinds:
        print("difference classes (class, Ghidra mnemonic, %s mnemonic: count, first example):" % name)
        for key, n in kinds.most_common():
            ad, by, mn, ops, o = examples[key]
            print("  %-9s %-10s %-10s %6d  %08x %s  ghidra '%s %s'  %s %s" %
                  (key[0], key[1], key[2], n, ad, by, mn, ops, name,
                   "'%s %s' len %d" % (o[1], o[2], o[0]) if o else "-"))
    if diffs_path:
        with open(diffs_path, "w", encoding="utf-8") as f:
            f.write("addr\tlen\tbytes\tghidra_mnem\tghidra_ops\tfunction\tclass\t%s_len\t%s_mnem\t%s_ops\n" % ((name,) * 3))
            for addr, ln, by, mn, ops, fn, cls, o in diffs:
                f.write("%08x\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n" % (addr, ln, by, mn, ops, fn, cls,
                                                            "\t".join(map(str, o)) if o else "\t\t"))
    return classes, counts["same"] == total


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("ghidra")
    ap.add_argument("image")
    ap.add_argument("--base", default="0xFFF80000")
    ap.add_argument("--objdump", default=DEF_OBJDUMP)
    ap.add_argument("--rizin", default=DEF_RIZIN)
    ap.add_argument("--ref", choices=("objdump", "rizin", "both"), default="objdump")
    ap.add_argument("--all", action="store_true", help="also compare instructions outside functions")
    ap.add_argument("--diffs", help="write every non-'same' instruction to this TSV (--ref both: <name>.objdump.tsv, "
                                    "<name>.rizin.tsv and <name>.3way.tsv)")
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    ap.add_argument("--tmpdir", default=None, help="rizin command files (default: a new temporary directory)")
    a = ap.parse_args()
    base = int(a.base, 0)

    rows = load_ghidra(a.ghidra, a.all)
    runs = runs_of(rows)
    refs = {}
    if a.ref in ("objdump", "both"):
        od = {}
        with concurrent.futures.ThreadPoolExecutor(a.jobs) as ex:
            for part in ex.map(lambda r: objdump_run(a.objdump, a.image, base, r[0], r[1]), runs):
                od.update(part)
        refs["objdump"] = (a.objdump, od)
    if a.ref in ("rizin", "both"):
        import tempfile
        tmp = a.tmpdir or tempfile.mkdtemp(prefix="rx_compare_rz_")
        refs["rizin"] = (a.rizin, rizin_runs(a.rizin, a.image, base, runs, tmp, a.jobs))

    def dpath(name):
        if not a.diffs:
            return None
        return a.diffs if a.ref != "both" else "%s.%s.tsv" % (a.diffs.rsplit(".tsv", 1)[0], name)

    classes, ok = {}, True
    for name, (path, ref) in refs.items():
        classes[name], same = report(name, path, rows, ref, len(runs), dpath(name))
        ok = ok and same

    if a.ref == "both":
        od, rz = refs["objdump"][1], refs["rizin"][1]
        tab, ex3 = collections.Counter(), {}
        out3 = []
        for addr, ln, by, mn, ops, fn in rows:
            co, cr = classes["objdump"][addr], classes["rizin"][addr]
            if co == "same" and cr == "same":
                k = "all three agree"
            elif co == "same":
                k = "Ghidra = objdump, rizin %s" % cr
            elif cr == "same":
                k = "Ghidra = rizin, objdump %s" % co
            elif refs_equal(od.get(addr), rz.get(addr)):
                k = "objdump = rizin, Ghidra differs"
            else:
                k = "all differ (objdump %s, rizin %s)" % (co, cr)
            tab[k] += 1
            if k != "all three agree":
                ex3.setdefault((k, mn), (addr, by, mn, ops, od.get(addr), rz.get(addr)))
                out3.append((addr, ln, by, mn, ops, fn, k, od.get(addr), rz.get(addr)))
        print("three-way (Ghidra / objdump / rizin), %d instructions:" % len(rows))
        for k, n in tab.most_common():
            print("  %-45s %7d" % (k, n))
        if a.diffs:
            with open(dpath("3way"), "w", encoding="utf-8") as f:
                f.write("addr\tlen\tbytes\tghidra_mnem\tghidra_ops\tfunction\tclass\tobjdump\trizin\n")
                for addr, ln, by, mn, ops, fn, k, o, r in out3:
                    f.write("%08x\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" % (
                        addr, ln, by, mn, ops, fn, k, "%s %s (%d)" % (o[1], o[2], o[0]) if o else "-",
                        "%s %s (%d)" % (r[1], r[2], r[0]) if r else "-"))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
