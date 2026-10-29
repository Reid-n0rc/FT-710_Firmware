#!/usr/bin/env python3
"""Draft tools/ghidra/signatures_<image>.tsv from CallArgCheck.java's protos.tsv (T21d, #97 B3; ARM images T23f).

Usage: python3 -I tools/signatures_draft.py <protos.tsv> tools/ghidra/names_main.tsv tools/ghidra/signatures_main.tsv \
           [<mismatch.tsv>]
       python3 -I tools/signatures_draft.py <protos.tsv> - tools/ghidra/signatures_display.tsv <mismatch.tsv> display
       python3 -I tools/signatures_draft.py <protos.tsv> - tools/ghidra/signatures_m33.tsv <mismatch.tsv> m33
With a CallArgCheck mismatch.tsv, the unnamed (FUN_) callees and callers it lists get a row as well. For the ARM images
the names argument may be "-": the named functions are then the protos.tsv rows whose name does not start with FUN_.

MAIN (CC-RX, the default image) gets a row for every named function, by the rules below. The ARM images (DISPLAY armcc
A32, IFDSP M33 gcc Thumb-2) get a row only when the evidence is clear, see draft_arm().

Rows of the existing signatures file whose source column is not "asm" (hand-reviewed: "doc") are kept as they are;
every other named function (names_main.tsv, function entries only) gets a row derived from the disassembly:

- parameters: R1..R4 live at the entry (CallArgCheck block liveness), sized by the first spill of each register
  (MOV.B/W/L Rk,dsp[SP] in CC-RX -O0 code; L otherwise). A gap (R1, R3 live but not R2) is filled with uint32.
  The decompiler's type is kept when its size matches and it is not undefinedN (so pointers and signedness survive).
- return: if every RTS/RTSD is preceded by an -O0 return idiom (MOVU.B/MOVU.W/MOV.B/MOV.W/MOV.L dsp[SP],R1, or
  MOV.B/W/L R1,dsp[SP] not right after a call), the
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
        params.append(t)  # unnamed: Ghidra shows param_N and does not carry a made-up name into the callers
    sites, rd1, rd12 = int(r["sites"]), int(r["sites_read_R1"]), int(r["sites_read_R1R2"])
    ct, csz = ctype(cret) if cret and cret != "void" else (None, 0)
    ub, uw, _ul = (int(x) for x in r.get("ret_use_B_W_L", "0/0/0").split("/"))
    esz = 2 if uw else 1 if ub else 0  # size evidence from MOV.B/MOV.W R1,... right after the call
    epi = r.get("ret_epilogue", "-")
    EPI = {"UB": ("uint8", 1), "UW": ("uint16", 2), "B": ("int8", 1), "W": ("int16", 2), "L": ("uint32", 4),
           "SB": ("uint8", 1), "SW": ("uint16", 2), "SL": ("uint32", 4)}
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


def arm_regs(asm_params):
    """{slot: size} from CallArgCheck's ARM asm_params ("r0:L,r2:B"); slot = register number + 1."""
    live = {}
    if asm_params != "-":
        for p in asm_params.split(","):
            reg, sz = p.split(":")
            live[int(reg[1:]) + 1] = SIZE[sz]
    return live


def draft_arm(r, dropped):
    """AAPCS (r0..r3, return r0 / r0:r1). Returns (ret, params, note) or None when the evidence is not clear.

    left out: functions whose callers read r2/r3/r12 right after the call (they rely on the callee keeping them: gcc
      -fipa-ra on the M33, the same pattern in armcc code; a locked AAPCS prototype would turn those reads into
      extraout_ variables), live-in sets with a gap, and functions where only a few callers read r1.
    parameters: n = highest live-in slot (CallArgCheck block liveness; a call reads what its callee reads, PUSH is
      no use). Clear when n equals the decompiler's count, or n is larger and a call site sets n registers (or
      CallArgCheck reports a dropped argument). Fewer than the decompiler is not clear: its extra parameters are
      mostly reads the block liveness misses (an uninitialised r3 that a PUSH saves as a local, code outside the
      body). When the decompiler shows more than 4 parameters the 5th and later are stack arguments, which the
      register liveness cannot see: its count and stack types are kept.
    A row the export check shows to make the output worse becomes a reviewed "skip" row (kept on redraft).
      Types: the decompiler's when its size matches the first use (UXTB/UXTH/STRB/STRH) or there is no size evidence;
      undefinedN becomes uintN.
    return: 64-bit if most reading call sites read r1 too; a value if a call site reads r0 after the call and the
      function writes r0 (a function that never writes r0
      only looks like it returns because gcc's -fipa-ra lets callers keep r0 across it); void if no call site reads r0
      and the decompiler also says void, or the function never writes r0 and no site reads it. Otherwise unclear: the
      row is kept only to fix the parameter count, with the decompiler's return type (not when that is 8 bytes).
    """
    if r["entry_insn"] == "-" or r["c_proto"] == "?":
        return None
    if int(r.get("sites_keep_scratch", "0")):  # callers rely on the callee leaving r2/r3/r12 alone (inter-procedural
        return None                            # register allocation); a locked AAPCS prototype would kill them
    cret, cps = parse_cproto(r["c_proto"])
    live = arm_regs(r["asm_params"])
    n = max(live) if live else 0
    nc = len(cps)
    if live and sorted(live) != list(range(1, n + 1)):
        return None  # a gap (r1 read, r0 not): the decompiler's guess and the liveness disagree on what r0 is
    if nc > 4 and n >= 1:
        # arguments 5.. are on the stack, which the register liveness cannot see: keep the decompiler's count (the
        # register part is then r0..r3, gaps filled)
        n, pk = nc, "stack"
    elif n == nc:
        pk = "="
    elif n > nc:
        if not (int(r["max_site_args"]) >= n or r["entry"] in dropped):
            return None
        pk = ">"
    else:
        # fewer than the decompiler: its extra parameters are mostly real reads the block liveness misses (an
        # uninitialised r3 that a PUSH saves as a local, code outside the function body; 17 functions got in_
        # variables when these rows were applied), so it is not clear
        return None
    params = []
    for i in range(1, n + 1):
        sz = live.get(i, 4)
        t = UINT[sz]
        if i > 4 and i - 1 < len(cps):  # stack argument: the decompiler's type
            ct, csz = ctype(cps[i - 1])
            t = ct or UINT.get(csz, "uint32")
        elif i - 1 < len(cps):
            ct, csz = ctype(cps[i - 1])
            if ct and (csz == sz or sz == 4):
                t = ct
            elif not ct and csz and sz == 4:
                t = UINT.get(csz, t)
        params.append(t)
    sites, rd1, rd12 = int(r["sites"]), int(r["sites_read_R1"]), int(r["sites_read_R1R2"])
    rdr1 = int(r.get("sites_read_R2", "0"))  # sites that read r1 after the call
    if rdr1 and rdr1 * 2 <= max(rd1, 1):
        return None  # a few callers read r1: a 64-bit return or a kept register, not clear
    writes = r.get("writes_ret", "1") == "1"
    ct, csz = ctype(cret) if cret and cret != "void" else (None, 0)
    ub, uw, _ul = (int(x) for x in r.get("ret_use_B_W_L", "0/0/0").split("/"))
    if rd1 and writes:
        if rdr1 * 2 > rd1:
            ret = "uint64"
        else:
            esz = 2 if uw else 1 if ub else 0
            if esz:
                ret = ct if ct and csz == esz else UINT[esz]
            elif ct and csz <= 4:
                ret = ct
            elif not ct and csz in (1, 2, 4):
                ret = UINT[csz]
            else:
                ret = "uint32"
        rk = "value"
    elif not rd1 and ((sites and cret == "void") or not writes):
        ret, rk = "void", "void"
    else:
        if pk in ("=", "stack") or csz == 8:
            return None
        ret = ct if ct else ("void" if cret == "void" else UINT.get(csz, "uint32"))
        rk = "kept"
    note = (f"asm: live-in {r['asm_params']} ({pk} decompiler {nc}), {rd1}/{sites} call sites read r0, "
            f"writes r0 {int(writes)}, return {rk}")
    return ret, ", ".join(params) if params else "void", note


HEADER = {
    "main": ("# FT-710 MAIN V01-12 function signatures (T21d, #97 B3), applied with ApplySignatures.java after ApplyNames.java.\n",
             "# CC-RX: parameters R1..R4 in order, return R1 (64-bit R1:R2, low word in R1).\n"),
    "display": ("# FT-710 DISPLAY V01-08 function signatures (T23f), applied with ApplySignatures.java after ApplyNames.java/ApplyData.java.\n",
                "# AAPCS (armcc, A32/Thumb): parameters r0..r3 in order, return r0 (64-bit r0:r1). Rows only where the evidence is clear.\n"),
    "m33": ("# FT-710 IFDSP V01-01 M33 function signatures (T23f), applied with ApplySignatures.java after IfdspM33Names.java/ApplyData.java.\n",
            "# AAPCS (gcc, Thumb-2): parameters r0..r3 in order, return r0 (64-bit r0:r1). Rows only where the evidence is clear.\n"),
}


def main(protos, names, out, mismatch=None, image="main"):
    arm = image != "main"
    if mismatch == "-":
        mismatch = None
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
    if names == "-":
        named = [(a, r["name"]) for a, r in rows.items() if not r["name"].startswith("FUN_")]
    else:
        with open(names) as f:
            for line in f:
                if line.startswith("#") or not line.strip():
                    continue
                p = line.rstrip("\n").split("\t")
                if p[1].startswith("@"):
                    continue
                named.append((int(p[0], 16), p[1]))
    dropped = set()
    if mismatch:  # also unnamed callees (and callers) that CallArgCheck lists
        with open(mismatch) as f:
            for line in f:
                p = line.rstrip("\n").split("\t")
                if line.startswith("#") or p[0] == "kind" or len(p) < 6:
                    continue
                if p[0] == "dropped_arg":
                    dropped.add(p[4])
                for a, n in ((p[4], p[5]), (p[2], p[3])):
                    if n.startswith("FUN_"):
                        named.append((int(a, 16), n))
    lines, nd, na, miss, unclear = [], 0, 0, 0, 0
    for a, name in sorted(set(named)):
        if a in keep:
            lines.append(keep[a]); nd += 1
            continue
        r = rows.get(a)
        if r is None:
            miss += 1
            continue
        if arm:
            d = draft_arm(r, dropped)
            if d is None:
                unclear += 1
                continue
            ret, ps, note = d
        else:
            ret, ps, note = draft(r)
        lines.append(f"{a:08x}\t{name}\t{ret}\t{ps}\tasm\t{note}")
        na += 1
    with open(out, "w") as f:
        f.write(HEADER[image][0])
        f.write("# address<TAB>name<TAB>return type<TAB>parameters (\"type [name][@stack:N], ...\" or void; unnamed = param_N)<TAB>source<TAB>note\n")
        f.write("# source: doc = reviewed against the disassembly and docs/code/%s (kept by tools/signatures_draft.py);\n"
                % {"main": "main", "display": "display", "m33": "ifdsp"}[image])
        f.write("#         asm = drafted by tools/signatures_draft.py from CallArgCheck.java protos (overwritten on redraft).\n")
        if arm:
            f.write("#         skip = reviewed: not applied, the decompiler's own prototype stays (locking it made the export worse; kept on redraft).\n")
        f.write("# Types: void bool char int8 uint8 int16 uint16 int32 uint32 int64 uint64 float double, '*' for pointers.\n")
        f.write(HEADER[image][1])
        for l in lines:
            f.write(l + "\n")
    print(f"signatures_draft: {nd} kept (doc), {na} drafted (asm), {miss} named addresses without a function"
          + (f", {unclear} left out (evidence not clear)" if arm else ""))


if __name__ == "__main__":
    main(*sys.argv[1:6])
