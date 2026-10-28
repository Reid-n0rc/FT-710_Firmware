#!/usr/bin/env python3
"""Draft tools/ghidra/signatures_main.tsv from CallArgCheck.java's protos.tsv (T21d, #97 B3).

Usage: python3 -I tools/signatures_draft.py <protos.tsv> tools/ghidra/names_main.tsv tools/ghidra/signatures_main.tsv

Rows of the existing signatures file whose source column is not "asm" (hand-reviewed: "doc") are kept as they are;
every other named function (names_main.tsv, function entries only) gets a row derived from the disassembly:

- parameters: R1..R4 live at the entry (CallArgCheck block liveness), sized by the first spill of each register
  (MOV.B/W/L Rk,dsp[SP] in CC-RX -O0 code; L otherwise). A gap (R1, R3 live but not R2) is filled with uint32.
  The decompiler's type is kept when its size matches and it is not undefinedN (so pointers and signedness survive).
- return: if every RTS/RTSD is preceded by the -O0 return idiom (MOVU.B/MOVU.W/MOV.B/MOV.W/MOV.L dsp[SP],R1), the
  function returns that type (the decompiler's type is kept when its size matches, e.g. bool, char, pointers).
  Otherwise, if any direct call site reads R1 before writing it after the call, it returns a value sized by the
  callers' first use (MOV.B/MOV.W R1,... gives 1/2 bytes), else the decompiler's type if it has one, else uint32
  (uint64 if most sites also read R2). Everything else returns void.
- interrupt handlers (entry PUSHM R1-.. or R14-.., which a CC-RX normal function never saves) are void(void).
"""
import re
import sys

SIZE = {"B": 1, "W": 2, "L": 4}
UINT = {1: "uint8", 2: "uint16", 4: "uint32", 8: "uint64"}
# Ghidra display names -> (signatures_main.tsv type, size)
CTYPE = {"byte": ("uint8", 1), "char": ("char", 1), "bool": ("bool", 1), "ushort": ("uint16", 2),
         "short": ("int16", 2), "uint": ("uint32", 4), "int": ("int32", 4), "float": ("float", 4),
         "ulonglong": ("uint64", 8), "longlong": ("int64", 8)}


def ctype(t):
    t = t.strip()
    if t.endswith("*"):
        base = t[:-1].strip()
        b = CTYPE.get(base, ("void", 0))[0] if not base.startswith("undefined") else "void"
        return (b + " *", 4)
    if t in CTYPE:
        return CTYPE[t]
    m = re.fullmatch(r"undefined(\d)?", t)
    if m:
        return (None, int(m.group(1) or 1))
    return (None, 0)


def parse_cproto(s):
    m = re.fullmatch(r"(.*?) \((.*)\)", s)
    if not m:
        return None, []
    ps = [p for p in m.group(2).split(", ") if p]
    return m.group(1), ps


def draft(r):
    entry = r["entry_insn"]
    m = re.match(r"PUSHM R(\d+)-R(\d+)", entry)
    if m and (int(m.group(1)) <= 5 or int(m.group(1)) >= 14):
        return "void", "void", "interrupt handler (entry " + entry + ")"
    cret, cps = parse_cproto(r["c_proto"])
    live = {}
    if r["asm_params"] != "-":
        for p in r["asm_params"].split(","):
            reg, sz = p.split(":")
            live[int(reg[1:])] = SIZE[sz]
    n = max(live) if live else 0
    params = []
    for i in range(1, n + 1):
        sz = live.get(i, 4)
        t = UINT[sz]
        if i - 1 < len(cps):
            ct, csz = ctype(cps[i - 1])
            if ct and csz == sz:
                t = ct
        params.append(f"{t} p{i}")
    sites, rd1, rd12 = int(r["sites"]), int(r["sites_read_R1"]), int(r["sites_read_R1R2"])
    ct, csz = ctype(cret) if cret and cret != "void" else (None, 0)
    ub, uw, _ul = (int(x) for x in r.get("ret_use_B_W_L", "0/0/0").split("/"))
    esz = 2 if uw else 1 if ub else 0  # size evidence from MOV.B/MOV.W R1,... right after the call
    epi = r.get("ret_epilogue", "-")
    EPI = {"UB": ("uint8", 1), "UW": ("uint16", 2), "B": ("int8", 1), "W": ("int16", 2), "L": ("uint32", 4)}
    if epi in EPI:  # every return loads R1 from the frame right before RTS/RTSD: the function returns that
        et, esz2 = EPI[epi]
        ret = ct if ct and csz == esz2 else et
    elif sites and rd1:
        if rd12 * 2 > rd1:
            ret = "uint64"
        elif esz:
            ret = ct if ct and csz == esz else UINT[esz]
        else:
            ret = ct if ct and csz <= 4 else "uint32"
    else:
        ret = "void"
    note = f"asm: live-in {r['asm_params']}, {rd1}/{sites} call sites read R1, return load {epi}"
    return ret, ", ".join(params) if params else "void", note


def main(protos, names, out):
    rows = {}
    with open(protos) as f:
        hdr = f.readline().rstrip("\n").split("\t")
        for line in f:
            r = dict(zip(hdr, line.rstrip("\n").split("\t")))
            rows[int(r["entry"], 16)] = r
    keep = {}
    try:
        with open(out) as f:
            for line in f:
                if line.startswith("#") or not line.strip():
                    continue
                p = line.rstrip("\n").split("\t")
                if len(p) > 4 and p[4] != "asm":
                    keep[int(p[0], 16)] = line.rstrip("\n")
    except FileNotFoundError:
        pass
    named = []
    with open(names) as f:
        for line in f:
            if line.startswith("#") or not line.strip():
                continue
            p = line.rstrip("\n").split("\t")
            if p[1].startswith("@"):
                continue
            named.append((int(p[0], 16), p[1]))
    lines, nd, na, miss = [], 0, 0, 0
    for a, name in sorted(set(named)):
        if a in keep:
            lines.append(keep[a]); nd += 1
            continue
        r = rows.get(a)
        if r is None:
            miss += 1
            continue
        ret, ps, note = draft(r)
        lines.append(f"{a:08x}\t{name}\t{ret}\t{ps}\tasm\t{note}")
        na += 1
    with open(out, "w") as f:
        f.write("# FT-710 MAIN V01-12 function signatures (T21d, #97 B3), applied with ApplySignatures.java after ApplyNames.java.\n")
        f.write("# address<TAB>name<TAB>return type<TAB>parameters (\"type name, ...\" or void)<TAB>source<TAB>note\n")
        f.write("# source: doc = reviewed against the disassembly and docs/code/main (kept by tools/signatures_draft.py);\n")
        f.write("#         asm = drafted by tools/signatures_draft.py from CallArgCheck.java protos (overwritten on redraft).\n")
        f.write("# Types: void bool char int8 uint8 int16 uint16 int32 uint32 int64 uint64 float double, '*' for pointers.\n")
        f.write("# CC-RX: parameters R1..R4 in order, return R1 (64-bit R1:R2, low word in R1).\n")
        for l in lines:
            f.write(l + "\n")
    print(f"signatures_draft: {nd} kept (doc), {na} drafted (asm), {miss} named addresses without a function")


if __name__ == "__main__":
    main(*sys.argv[1:4])
