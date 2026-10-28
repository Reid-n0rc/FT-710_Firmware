#!/usr/bin/env python3
"""Check the RX SLEIGH p-code semantics of MAIN instructions against a reference model written from the RXv2 software
manual R01US0071EJ0100 (T22a, #104).

  python3 -I tools/rx_semcheck.py gen   <listing.tsv> <cases.tsv> [--per-shape N] [--trials K] [--seed S]
  (Ghidra) tools/ghidra/RxEmuStep.java  <cases.tsv> <emu_out.tsv>
  python3 -I tools/rx_semcheck.py check <cases.tsv> <emu_out.tsv> [--fails out.tsv]

gen picks real instruction sites from the ListingExport.java TSV (up to N sites per mnemonic + operand shape, all
shapes of the modelled mnemonics), builds K random start states per site (registers, PSW flags, the memory the
instruction reads) and writes the expected end state from the model into the case file. RxEmuStep.java executes each
case once with Ghidra's p-code emulator; check compares registers R0-R15, PC, the four PSW flags and the exact set of
bytes written. User pcodeops (scmpu, smovf, sstr, suntil, ...) are not executed: the emulator records their arguments
and returns the case's "uop" value, and the model checks the arguments and the register/flag effects around them.

The model takes operands from Ghidra's operand text (decoding was checked against binutils and rizin, rx_compare.py);
the semantics (what each operand form reads or writes, extension, flags, stack effects) come from the manual.
Registers or flags the manual leaves undefined are not compared (DONT_CARE).
"""
import argparse
import collections
import random
import struct
import re
import sys

M32 = 0xFFFFFFFF
FLAGS = {"C": 0, "Z": 1, "S": 2, "O": 3}
REGS = ["SP"] + ["R%d" % i for i in range(1, 16)]
SIZE = {"B": 1, "UB": 1, "W": 2, "UW": 2, "L": 4}
SIGNED = {"B": True, "W": True, "UB": False, "UW": False, "L": False}
CONDS = {"EQ": lambda f: f["Z"], "NE": lambda f: not f["Z"], "GEU": lambda f: f["C"], "LTU": lambda f: not f["C"],
         "GTU": lambda f: f["C"] and not f["Z"], "LEU": lambda f: not (f["C"] and not f["Z"]),
         "PZ": lambda f: not f["S"], "N": lambda f: f["S"], "GE": lambda f: not (f["S"] ^ f["O"]),
         "LT": lambda f: f["S"] ^ f["O"], "GT": lambda f: not ((f["S"] ^ f["O"]) or f["Z"]),
         "LE": lambda f: (f["S"] ^ f["O"]) or f["Z"], "O": lambda f: f["O"], "NO": lambda f: not f["O"]}
ALU2 = ("ADD", "SUB", "CMP", "AND", "OR", "MUL", "DIVU", "DIV", "TST")
MODELLED = set(ALU2) | {"MOV.B", "MOV.W", "MOV.L", "MOVU.B", "MOVU.W", "SHLL", "SHLR", "SHAR", "BSET", "BCLR", "BTST",
                        "NOT", "NEG", "RTS", "RTSD", "JSR", "BRA.L", "PUSH.L", "PUSHM", "POPM", "XCHG", "SMOVF",
                        "SSTR.B", "SCMPU", "SUNTIL.B", "NOP", "ADC", "SBB", "ROLC", "RORC", "STZ", "STNZ", "ITOF"}


class Unmodelled(Exception):
    pass


def sext(v, bits):
    v &= (1 << bits) - 1
    return v - (1 << bits) if v >> (bits - 1) else v


def parse_num(s):
    s = s.strip().lstrip("#")
    neg = s.startswith("-")
    v = int(s[1:] if neg else s, 0)
    return -v if neg else v


def parse_op(s):
    """-> ('reg', name) | ('imm', value) | ('mem', base, dsp, memex) | ('idx', ri, rb) | ('post', r) | ('pre', r)"""
    s = s.strip()
    m = re.fullmatch(r"(SP|R\d+)", s)
    if m:
        return ("reg", s)
    m = re.fullmatch(r"(-?0x[0-9a-f]+|-?\d+)?\[(SP|R\d+)\](?:\.(UB|UW|B|W|L))?", s)
    if m:
        return ("mem", m.group(2), parse_num(m.group(1)) if m.group(1) else 0, m.group(3))
    m = re.fullmatch(r"\[(SP|R\d+), ?(SP|R\d+)\]", s)
    if m:
        return ("idx", m.group(1), m.group(2))
    m = re.fullmatch(r"\[(SP|R\d+)\+\]", s)
    if m:
        return ("post", m.group(1))
    m = re.fullmatch(r"\[-(SP|R\d+)\]", s)
    if m:
        return ("pre", m.group(1))
    m = re.fullmatch(r"#?(-?0x[0-9a-f]+|-?\d+)", s)
    if m:
        return ("imm", parse_num(s))
    raise Unmodelled("operand " + s)


def shape(ops):
    return ",".join(re.sub(r"-?0x[0-9a-f]+|-?\d+", "N", o) for o in ops)


class State:
    def __init__(self, regs, flags, mem):
        self.r = dict(regs)
        self.f = dict(flags)
        self.mem = dict(mem)       # addr -> byte (what the start state provides)
        self.writes = {}           # addr -> byte
        self.calls = []            # expected user-op calls (name, [args]) ; args None = not checked
        self.dont_care = set()

    def rd(self, a, n):
        v = 0
        for i in range(n):
            a_i = (a + i) & M32
            b = self.writes.get(a_i, self.mem.get(a_i))
            if b is None:
                raise KeyError(a_i)
            v |= b << (8 * i)
        return v

    def wr(self, a, n, v):
        for i in range(n):
            self.writes[(a + i) & M32] = (v >> (8 * i)) & 0xFF


def mem_addr(st, op, size):
    k = op[0]
    if k == "mem":
        return (st.r[op[1]] + op[2]) & M32
    if k == "idx":                              # [Ri, Rb]: Rb + Ri * size
        return (st.r[op[2]] + st.r[op[1]] * size) & M32
    if k in ("post", "pre"):
        return (st.r[op[1]] - (size if k == "pre" else 0)) & M32
    raise Unmodelled(k)


def reads_of(op, size, regs):
    """Addresses an operand reads (for building the start state)."""
    if op[0] in ("mem", "idx", "post", "pre"):
        sz = SIZE[op[3]] if op[0] == "mem" and op[3] else size
        st = State(regs, {}, {})
        a = mem_addr(st, op, sz)
        return [(a + i) & M32 for i in range(sz)]
    return []


def get_src(st, op, size, memex_default="L"):
    """Read a source operand; returns a 32-bit value (extended as the manual says)."""
    if op[0] == "reg":
        return st.r[op[1]]
    if op[0] == "imm":
        return op[1] & M32
    ex = op[3] if op[0] == "mem" and op[3] else memex_default
    n = SIZE[ex]
    a = mem_addr(st, op, n)
    v = st.rd(a, n)
    if op[0] == "post":
        st.r[op[1]] = (st.r[op[1]] + n) & M32
    return (sext(v, 8 * n) & M32) if SIGNED[ex] else v


def set_zs(st, v, bits=32):
    st.f["Z"] = int(v & ((1 << bits) - 1) == 0)
    st.f["S"] = int(v >> (bits - 1) & 1)


def add_flags(st, a, b, res):
    st.f["C"] = int(a + b > M32)
    set_zs(st, res)
    st.f["O"] = int(((a ^ res) & (b ^ res)) >> 31 & 1)


def sub_flags(st, a, b, res):            # a - b
    st.f["C"] = int(a >= b)
    set_zs(st, res)
    st.f["O"] = int(((a ^ b) & (a ^ res)) >> 31 & 1)


def model(st, addr, ln, mn, ops_txt):
    ops = [parse_op(o) for o in split_ops(ops_txt)] if ops_txt else []
    base, _, sz = mn.partition(".")
    nxt = (addr + ln) & M32
    st.r["PC"] = nxt
    if base in ("MOV", "MOVU"):
        n = SIZE[sz]
        src, dst = ops
        if src[0] == "imm":
            v = src[1] & ((1 << 8 * n) - 1)
        elif src[0] == "reg":
            v = st.r[src[1]] & ((1 << 8 * n) - 1)
        else:
            a = mem_addr(st, src, n)
            v = st.rd(a, n)
            if src[0] == "post":
                st.r[src[1]] = (st.r[src[1]] + n) & M32
            if src[0] == "pre":
                st.r[src[1]] = a
        if dst[0] == "reg":
            st.r[dst[1]] = v if base == "MOVU" or n == 4 else sext(v, 8 * n) & M32
        else:
            if base == "MOVU":
                raise Unmodelled("movu store")
            a = mem_addr(st, dst, n)
            st.wr(a, n, v)
            if dst[0] == "post":
                st.r[dst[1]] = (st.r[dst[1]] + n) & M32
            if dst[0] == "pre":
                st.r[dst[1]] = a
        return
    if base in ALU2:
        if len(ops) == 3:                   # src, src2, dest
            a, b = get_src(st, ops[1], 4), get_src(st, ops[0], 4)
            dst = ops[2][1]
        else:
            src, d = ops
            b = get_src(st, src, 4)
            a = st.r[d[1]]
            dst = d[1]
        if base == "ADD":
            res = (a + b) & M32
            add_flags(st, a, b, res)
        elif base in ("SUB", "CMP"):
            res = (a - b) & M32
            sub_flags(st, a, b, res)
        elif base in ("AND", "TST"):
            res = a & b
            set_zs(st, res)
        elif base == "OR":
            res = a | b
            set_zs(st, res)
        elif base == "MUL":
            res = (a * b) & M32
        elif base == "DIVU":
            if b == 0:
                st.f["O"] = 1
                st.dont_care.add(dst)
                return
            res = a // b
            st.f["O"] = 0
        elif base == "DIV":
            sa, sb = sext(a, 32), sext(b, 32)
            if sb == 0 or (sa == -(1 << 31) and sb == -1):
                st.f["O"] = 1
                st.dont_care.add(dst)
                return
            q = abs(sa) // abs(sb)
            res = (q if (sa < 0) == (sb < 0) else -q) & M32
            st.f["O"] = 0
        if base not in ("CMP", "TST"):
            st.r[dst] = res
        return
    if base in ("SHLL", "SHLR", "SHAR"):
        if len(ops) == 3:
            n, v, dst = get_src(st, ops[0], 4) & 31, st.r[ops[1][1]], ops[2][1]
        else:
            n, v, dst = get_src(st, ops[0], 4) & 31, st.r[ops[1][1]], ops[1][1]
        if base == "SHLL":
            res = (v << n) & M32
            st.f["C"] = (v >> (32 - n)) & 1 if n else 0
            top = v >> (31 - n)                         # MSB plus the n shifted-out bits
            st.f["O"] = 0 if n == 0 or top in (0, (1 << (n + 1)) - 1) else 1
        elif base == "SHLR":
            res = v >> n
            st.f["C"] = (v >> (n - 1)) & 1 if n else 0
        else:
            res = (sext(v, 32) >> n) & M32
            st.f["C"] = (v >> (n - 1)) & 1 if n else 0
            st.f["O"] = 0
        set_zs(st, res)
        st.r[dst] = res
        return
    if base in ("BSET", "BCLR", "BTST"):
        bit, dst = ops
        if dst[0] == "reg":
            b = get_src(st, bit, 4) & 31
            v = st.r[dst[1]]
        else:
            b = get_src(st, bit, 4) & 7
            a = mem_addr(st, dst, 1)
            v = st.rd(a, 1)
        if base == "BTST":
            st.f["C"] = (v >> b) & 1
            st.f["Z"] = 1 - st.f["C"]
            return
        v = v | (1 << b) if base == "BSET" else v & ~(1 << b)
        if dst[0] == "reg":
            st.r[dst[1]] = v & M32
        else:
            st.wr(a, 1, v)
        return
    if base == "NOT" and len(ops) == 1:
        st.r[ops[0][1]] = res = ~st.r[ops[0][1]] & M32
        set_zs(st, res)
        return
    if base == "NEG" and len(ops) == 1:
        v = st.r[ops[0][1]]
        res = -v & M32
        st.f["C"] = int(res == 0)
        st.f["O"] = int(v == 0x80000000)
        set_zs(st, res)
        st.r[ops[0][1]] = res
        return
    if base == "NOP":
        return
    if base in ("ADC", "SBB"):
        b = get_src(st, ops[0], 4)
        a = st.r[ops[1][1]]
        if base == "ADC":
            res = (a + b + st.f["C"]) & M32
            st.f["C"] = int(a + b + st.f["C"] > M32)
            st.f["O"] = int(((a ^ res) & (b ^ res)) >> 31 & 1)
        else:                                   # dest = dest - src - !C
            borrow = 1 - st.f["C"]
            res = (a - b - borrow) & M32
            st.f["C"] = int(a >= b + borrow)
            st.f["O"] = int(((a ^ b) & (a ^ res)) >> 31 & 1)
        set_zs(st, res)
        st.r[ops[1][1]] = res
        return
    if base in ("ROLC", "RORC"):
        r = ops[0][1]
        v = st.r[r]
        if base == "ROLC":
            res = ((v << 1) | st.f["C"]) & M32
            st.f["C"] = v >> 31
        else:
            res = (v >> 1) | (st.f["C"] << 31)
            st.f["C"] = v & 1
        set_zs(st, res)
        st.r[r] = res
        return
    if base in ("STZ", "STNZ"):
        if bool(st.f["Z"]) == (base == "STZ"):
            st.r[ops[1][1]] = ops[0][1] & M32
        return
    if base == "ITOF":
        v = sext(get_src(st, ops[0], 4, "L"), 32)
        res = struct.unpack("<I", struct.pack("<f", float(v)))[0]   # round to nearest (FPSW.RM = 0)
        st.r[ops[1][1]] = res
        st.f["Z"] = int(v == 0)
        st.f["S"] = int(v < 0)
        return
    if base == "PUSH" and sz == "L":
        v = st.r[ops[0][1]]
        st.r["SP"] = (st.r["SP"] - 4) & M32
        st.wr(st.r["SP"], 4, v)
        return
    if base == "PUSHM":
        lo, hi = int(ops[0][1][1:]), int(ops[1][1][1:])
        for i in range(hi, lo - 1, -1):
            st.r["SP"] = (st.r["SP"] - 4) & M32
            st.wr(st.r["SP"], 4, st.r["R%d" % i])
        return
    if base == "POPM":
        lo, hi = int(ops[0][1][1:]), int(ops[1][1][1:])
        for i in range(lo, hi + 1):
            st.r["R%d" % i] = st.rd(st.r["SP"], 4)
            st.r["SP"] = (st.r["SP"] + 4) & M32
        return
    if base == "RTS":
        st.r["PC"] = st.rd(st.r["SP"], 4)
        st.r["SP"] = (st.r["SP"] + 4) & M32
        return
    if base == "RTSD":
        imm = ops[0][1]
        if len(ops) == 3:
            lo, hi = int(ops[1][1][1:]), int(ops[2][1][1:])
            st.r["SP"] = (st.r["SP"] + imm - (hi - lo + 1) * 4) & M32
            for i in range(lo, hi + 1):
                st.r["R%d" % i] = st.rd(st.r["SP"], 4)
                st.r["SP"] = (st.r["SP"] + 4) & M32
        else:
            st.r["SP"] = (st.r["SP"] + imm) & M32
        st.r["PC"] = st.rd(st.r["SP"], 4)
        st.r["SP"] = (st.r["SP"] + 4) & M32
        return
    if base in ("BSR", "JSR"):
        tgt = st.r[ops[0][1]] if ops[0][0] == "reg" and base == "JSR" else None
        if base == "BSR":
            tgt = (addr + st.r[ops[0][1]]) & M32 if sz == "L" else int(ops_txt, 16)
        st.r["SP"] = (st.r["SP"] - 4) & M32
        st.wr(st.r["SP"], 4, nxt)
        st.r["PC"] = tgt
        return
    if base == "BRA":
        st.r["PC"] = (addr + st.r[ops[0][1]]) & M32 if sz == "L" else int(ops_txt, 16)
        return
    if base.startswith("B") and base[1:] in CONDS:
        if CONDS[base[1:]](st.f):
            st.r["PC"] = int(ops_txt, 16)
        return
    if base.startswith("SC") and base[2:] in CONDS and sz == "L" and ops[0][0] == "reg":
        st.r[ops[0][1]] = int(bool(CONDS[base[2:]](st.f)))
        return
    if base == "XCHG" and ops[0][0] == "mem":
        ex = ops[0][3] or "L"
        n = SIZE[ex]
        a = mem_addr(st, ops[0], n)
        v = st.rd(a, n)
        rd = ops[1][1]
        st.wr(a, n, st.r[rd])
        st.r[rd] = (sext(v, 8 * n) & M32) if SIGNED[ex] else v
        return
    if base == "SMOVF":
        st.calls.append(("smovf", [st.r["R1"], st.r["R2"], st.r["R3"]]))
        st.r["R1"] = (st.r["R1"] + st.r["R3"]) & M32
        st.r["R2"] = (st.r["R2"] + st.r["R3"]) & M32
        st.r["R3"] = 0
        return
    if base == "SSTR" and sz == "B":
        st.calls.append(("sstr", [st.r["R1"], st.r["R2"] & 0xFF, st.r["R3"]]))
        st.r["R1"] = (st.r["R1"] + st.r["R3"]) & M32
        st.r["R3"] = 0
        return
    if base == "SCMPU":
        if st.r["R3"] == 0:
            return
        st.calls.append(("scmpu", [st.r["R1"], st.r["R2"], st.r["R3"]]))
        d = sext(st.uop, 32)
        st.f["Z"] = int(d == 0)
        st.f["C"] = int(d >= 0)
        st.dont_care |= {"R1", "R2", "R3"}       # manual: undefined after SCMPU
        return
    if base == "SUNTIL" and sz == "B":
        if st.r["R3"] == 0:
            return
        st.calls.append(("suntil", None))
        p = st.uop
        last = st.rd((p - 1) & M32, 1)
        st.r["R3"] = (st.r["R3"] - (p - st.r["R1"])) & M32
        st.r["R1"] = p
        st.f["Z"] = int(last == st.r["R2"])
        st.f["C"] = int(last >= st.r["R2"])
        return
    raise Unmodelled(mn)


def split_ops(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "[":
            depth += 1
        elif ch == "]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    out.append(cur)
    return [o.strip() for o in out if o.strip()]


def kind_of(mn):
    base = mn.split(".")[0]
    if mn in MODELLED or base in MODELLED:
        return True
    if base in ("BSR", "BRA"):
        return True
    if base.startswith("B") and base[1:] in CONDS:
        return True
    if base.startswith("SC") and base[2:] in CONDS:
        return True
    return False


def rand_regs(rng):
    regs = {r: rng.choice([rng.getrandbits(32), rng.randrange(0x1000, 0x3F000), rng.randrange(0, 64),
                           0xFFFFFFFF - rng.randrange(0, 64), 0x80000000, 0x7FFFFFFF]) for r in REGS[1:]}
    regs["SP"] = rng.randrange(0x8000, 0x10000) & ~3
    return regs


def gen(a):
    rng = random.Random(a.seed)
    sites = collections.defaultdict(list)
    for line in open(a.listing, encoding="utf-8"):
        p = line.rstrip("\n").split("\t")
        if len(p) < 6 or p[3] == "?UNDEF":
            continue
        mn = p[3].strip()
        if " " in mn or not kind_of(mn):
            continue
        sites[(mn, shape(split_ops(p[4]) if p[4] else []))].append((int(p[0], 16), int(p[1]), mn, p[4]))
    n = 0
    skipped = collections.Counter()
    with open(a.cases, "w", encoding="utf-8") as out:
        out.write("#id\taddr\tregs\tmem\tuop\tmnem\tops\texpected_regs\texpected_writes\texpected_calls\tdont_care\n")
        for key in sorted(sites):
            lst = sites[key]
            pick = lst if len(lst) <= a.per_shape else rng.sample(lst, a.per_shape)
            for addr, ln, mn, ops in pick:
                for t in range(a.trials):
                    regs = rand_regs(rng)
                    try:
                        oplist = [parse_op(o) for o in split_ops(ops)] if ops else []
                    except Unmodelled:
                        oplist = []
                    for _ in range(200):                   # no memory operand may wrap around 2^32 (Ghidra cannot)
                        addrs = [x for o in oplist for x in reads_of(o, 4, regs)] if oplist else []
                        if all(0x100 <= x <= 0xFFFFFF00 for x in addrs):
                            break
                        regs = rand_regs(rng)
                    flags = {f: rng.getrandbits(1) for f in FLAGS}
                    if mn.startswith(("DIVU", "DIV")) and t == 0 and ops.split(",")[0].startswith("R"):
                        pass
                    # memory: give every byte the instruction may read a random value
                    mem = {}
                    try:
                        oplist = [parse_op(o) for o in split_ops(ops)] if ops else []
                    except Unmodelled as e:
                        skipped[str(e)] += 1
                        break
                    base, _, sz = mn.partition(".")
                    size = SIZE.get(sz, 4)
                    for o in oplist:
                        for x in reads_of(o, size, regs):
                            mem[x] = rng.getrandbits(8)
                    for i in range(0, 64):                     # stack (RTS/RTSD/POPM read it)
                        mem[(regs["SP"] + i) & M32] = rng.getrandbits(8)
                    uop = 0
                    if base == "SCMPU":
                        uop = rng.choice([0, 1, 5, -1 & M32, -7 & M32])
                    if base == "SUNTIL":
                        k = rng.randrange(1, 9)
                        regs["R3"] = rng.choice([0, k, k + rng.randrange(0, 5)])
                        uop = (regs["R1"] + k) & M32
                        mem[(uop - 1) & M32] = rng.choice([regs["R2"] & 0xFF, rng.getrandbits(8)])
                        regs["R2"] = rng.choice([regs["R2"] & 0xFF, regs["R2"]])
                    if base in ("SMOVF", "SSTR") and t == 0:
                        regs["R3"] = rng.randrange(0, 40)
                    if base == "BRA" and sz == "L" or base == "BSR" and sz == "L":
                        regs[oplist[0][1]] = rng.randrange(-0x400, 0x400) & M32
                    st = State(regs, flags, mem)
                    st.uop = uop
                    try:
                        model(st, addr, ln, mn, ops)
                    except Unmodelled as e:
                        skipped[str(e)] += 1
                        break
                    except KeyError as e:
                        skipped["read outside start state " + mn] += 1
                        break
                    psw = sum(flags[f] << b for f, b in FLAGS.items())
                    exp_psw = sum(st.f[f] << b for f, b in FLAGS.items())
                    rs = ";".join("%s=0x%x" % (r, v) for r, v in regs.items()) + ";PSW=0x%x" % psw
                    ms = ";".join("%08x:%02x" % (k, v) for k, v in sorted(mem.items())) or "-"
                    er = ";".join("%s=0x%x" % (r, st.r[r]) for r in REGS + ["PC"]) + ";PSW=0x%x" % exp_psw
                    ew = ";".join("%08x:%02x" % (k, v) for k, v in sorted(st.writes.items())) or "-"
                    ec = ";".join("%s(%s)" % (c, "*" if args is None else ",".join("0x%x" % x for x in args))
                                  for c, args in st.calls) or "-"
                    out.write("%s:%d\t%08x\t%s\t%s\t%x\t%s\t%s\t%s\t%s\t%s\t%s\n" % (
                        "%08x" % addr, t, addr, rs, ms, uop, mn, ops, er, ew, ec, ",".join(sorted(st.dont_care)) or "-"))
                    n += 1
    print("%d cases from %d shapes (%d sites)" % (n, len(sites), sum(min(len(v), a.per_shape) for v in sites.values())))
    for k, v in skipped.most_common():
        print("  skipped %-40s %d" % (k, v))


def parse_kv(s):
    d = {}
    for kv in s.split(";"):
        if kv and kv != "-":
            k, v = kv.split("=")
            d[k] = int(v, 16)
    return d


def parse_bytes(s):
    d = {}
    if s == "-":
        return d
    for part in s.split(";"):
        if part:
            ad, hx = part.split(":")
            ad = int(ad, 16)
            for i in range(len(hx) // 2):
                d[(ad + i) & M32] = int(hx[2 * i:2 * i + 2], 16)
    return d


def check(a):
    cases = {}
    for line in open(a.cases, encoding="utf-8"):
        if line.startswith("#"):
            continue
        p = line.rstrip("\n").split("\t")
        cases[p[0]] = p
    res = collections.Counter()
    by_mn = collections.defaultdict(collections.Counter)
    fails = []
    for line in open(a.emu, encoding="utf-8"):
        e = line.rstrip("\n").split("\t")
        c = cases[e[0]]
        mn = c[5]
        probs = []
        if e[1] != "ok":
            probs.append(e[1])
        got, exp = parse_kv(e[2]), parse_kv(c[7])
        dc = set(c[10].split(",")) - {"-"}
        for r in REGS + ["PC"]:
            if r not in dc and got.get(r) != exp[r]:
                probs.append("%s=0x%x (model 0x%x)" % (r, got.get(r, -1), exp[r]))
        for f, b in FLAGS.items():
            if (got["PSW"] >> b & 1) != (exp["PSW"] >> b & 1):
                probs.append("%s=%d (model %d)" % (f, got["PSW"] >> b & 1, exp["PSW"] >> b & 1))
        gw, ew = parse_bytes(e[3]), parse_bytes(c[8])
        if gw != ew:
            extra = sorted(set(gw) - set(ew))
            miss = sorted(set(ew) - set(gw))
            wrong = sorted(k for k in set(gw) & set(ew) if gw[k] != ew[k])
            probs.append("writes: extra %s missing %s wrong %s" % (
                ",".join("%08x" % x for x in extra[:4]), ",".join("%08x" % x for x in miss[:4]),
                ",".join("%08x=%02x(model %02x)" % (x, gw[x], ew[x]) for x in wrong[:4])))
        if c[9] != "-":
            gc, ec = e[4].split(";") if e[4] != "-" else [], c[9].split(";")
            for x, y in zip(gc, ec):
                nm = y.split("(")[0]
                if not x.startswith(nm + "(") or ("*" not in y and not x.startswith(y[:-1])):
                    probs.append("call %s (model %s)" % (x, y))
            if len(gc) != len(ec):
                probs.append("calls %s (model %s)" % (e[4], c[9]))
        cls = "ok" if not probs else "FAIL"
        res[cls] += 1
        by_mn[mn.split(".")[0] if not mn.startswith(("MOV", "B", "SC")) else mn][cls] += 1
        if probs:
            fails.append((c[0], mn, c[6], "; ".join(probs), c[2], c[3][:200]))
    print("cases: %d ok, %d FAIL" % (res["ok"], res["FAIL"]))
    for mn in sorted(by_mn):
        print("  %-10s %6d ok %6d FAIL" % (mn, by_mn[mn]["ok"], by_mn[mn]["FAIL"]))
    kinds = collections.Counter((f[1], re.sub(r"0x[0-9a-f]+", "#", f[3])[:90]) for f in fails)
    if kinds:
        print("failure kinds (mnemonic, problem with values masked):")
        for (mn, pr), k in kinds.most_common(60):
            ex = next(f for f in fails if f[1] == mn and re.sub(r"0x[0-9a-f]+", "#", f[3])[:90] == pr)
            print("  %5d %-9s %s\n        e.g. %s %s %s" % (k, mn, pr, ex[0], ex[1], ex[2]))
    if a.fails:
        with open(a.fails, "w", encoding="utf-8") as f:
            for x in fails:
                f.write("\t".join(x) + "\n")
    return 0 if not fails else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    sp = ap.add_subparsers(dest="cmd", required=True)
    g = sp.add_parser("gen")
    g.add_argument("listing")
    g.add_argument("cases")
    g.add_argument("--per-shape", type=int, default=40)
    g.add_argument("--trials", type=int, default=4)
    g.add_argument("--seed", type=int, default=22)
    c = sp.add_parser("check")
    c.add_argument("cases")
    c.add_argument("emu")
    c.add_argument("--fails")
    a = ap.parse_args()
    return gen(a) or 0 if a.cmd == "gen" else check(a)


if __name__ == "__main__":
    sys.exit(main())
