#!/usr/bin/env python3
"""T24 MAIN round 5: the RX FPU instructions in the MAIN equivalence engine against the RXv2 software manual
R01US0071EJ0100, with a reference model written here from the manual alone (Python fractions, independent of the
engine's BigInteger code in tools/ghidra/EquivMainEmu.java, RxFpu).

  python3 -I tools/rx_fpu_check.py            the engine (EquivMainEmu.java executes every FPU instruction)
  python3 -I tools/rx_fpu_check.py module     the module's own p-code (what Ghidra's decompiler and a plain p-code
                                              emulator see); prints the classes of disagreement
  python3 -I tools/rx_fpu_check.py -v         every disagreement

Covered: FADD, FSUB, FMUL (#imm, Rs, [Rs].L, dsp[Rs].L and the 3-operand form), FDIV, FCMP (#imm, Rs, [Rs].L,
dsp[Rs].L), FSQRT, FTOI, FTOU, ROUND (Rs), ITOF and UTOF (Rs and every memex). Operands: zeros, denormals, the
normal limits, ones, ties, MAX, infinities, quiet and signalling NaNs with payloads, and random values. FPSW: the
image's 0x100 (RM 0, DN 1) for every case; RM 1..3, DN 0 and the exception enable bits for a subset. Compared: the
destination (or no write), PSW.Z/S/O, FPSW, and whether the floating-point exception starts.

What the manual says that the model follows (pages of R01US0071EJ0100):
  FPSW p. 20/21 (cause flags cleared by each FPU instruction; Fj set with its cause while Ej is 0; FS = FU|FZ|FO|FV;
  DN = 1: a denormal is a zero of its sign); exceptions p. 24..27 (Table 1.1 overflow by RM with inexact; Table 1.2
  underflow: 0 with DN = 1; Table 1.4 division by zero; Table 1.5 invalid operation, integer conversion limits;
  Table 1.6 QNaN rules, 7FFFFFFFh for an invalid operation without a NaN operand; unimplemented processing with
  DN = 0 and a denormal operand or an underflow); each instruction's page (exact-zero sums +0, -0 towards -inf, p. 87
  and p. 100; FCMP O for an unordered pair, p. 90; ITOF / UTOF 0 is +0, p. 110 / p. 201; FTOI / FTOU truncate, ROUND
  by RM, p. 103 / 106 / 171; memex B and W sign-extended, p. 55). Two readings are the model's, each an open point
  also in the engine: underflow is decided on the exact result (before rounding), and "the S and Z flags do not
  change when an exception is generated" covers masked exceptions (the manual uses "generated" for masked causes)."""
import os, random, struct, subprocess, sys, tempfile
from fractions import Fraction

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv_main_emu as E

MODULE = 'module' in sys.argv[1:]
VERBOSE = '-v' in sys.argv[1:]

CV, CO, CZ, CU, CX, CE = 4, 8, 16, 32, 64, 128
DN = 0x100
QNAN = 0x7FFFFFFF


# ---------------------------------------------------------------- the reference model (from the manual)

def fields(b):
    return b >> 31, (b >> 23) & 0xFF, b & 0x7FFFFF


def is_nan(b):
    return fields(b)[1] == 0xFF and fields(b)[2] != 0


def is_snan(b):
    return is_nan(b) and not b & 0x400000


def is_inf(b):
    return fields(b)[1] == 0xFF and fields(b)[2] == 0


def is_zero(b):
    return b & 0x7FFFFFFF == 0


def is_denormal(b):
    return fields(b)[1] == 0 and fields(b)[2] != 0


def value(b):
    s, e, f = fields(b)
    v = Fraction(f | 0x800000, 1 << 23) * Fraction(2) ** (e - 127)
    return -v if s else v


class Ref:
    def __init__(self, fpsw):
        self.fpsw = fpsw
        self.cause = 0

    def operand(self, b):
        if is_denormal(b):
            if self.fpsw & DN:
                return b & 0x80000000            # p. 21 note 2
            self.cause |= CE                     # p. 27
        return b

    def nan_rule(self, d, s):
        """Table 1.6; d is the operand in dest's place."""
        if is_snan(d) or is_snan(s):
            self.cause |= CV
        if is_snan(d):
            return d | 0x400000
        if is_snan(s):
            return s | 0x400000
        return d if is_nan(d) else s

    def invalid(self):
        self.cause |= CV
        return QNAN

    def zero(self, neg):
        return 0x80000000 if neg else 0

    def to_single(self, x):
        """x: an exact nonzero Fraction; rounded by RM."""
        rm = self.fpsw & 3
        neg = x < 0
        a = -x if neg else x
        ex = a.numerator.bit_length() - a.denominator.bit_length()
        while Fraction(2) ** ex > a:
            ex -= 1
        while Fraction(2) ** (ex + 1) <= a:
            ex += 1
        if ex < -126:                            # Table 1.2 (decided before rounding: the model's reading)
            self.cause |= CU | (0 if self.fpsw & DN else CE)
            return self.zero(neg)
        q = a / Fraction(2) ** (ex - 23)
        n = q.numerator // q.denominator
        frac = q - n
        inexact = frac != 0
        if rm == 0:
            up = frac > Fraction(1, 2) or frac == Fraction(1, 2) and n & 1
        elif rm == 1:
            up = False
        elif rm == 2:
            up = inexact and not neg
        else:
            up = inexact and neg
        if up:
            n += 1
        if n == 1 << 24:
            n >>= 1
            ex += 1
        if ex > 127:                             # Table 1.1 with inexact (its note)
            self.cause |= CO | CX
            inf = rm == 0 or rm == 2 and not neg or rm == 3 and neg
            return self.zero(neg) | (0x7F800000 if inf else 0x7F7FFFFF)
        if inexact:
            self.cause |= CX
        return self.zero(neg) | (ex + 127) << 23 | (n - (1 << 23))

    def add(self, d, s, sub=False):
        d, s = self.operand(d), self.operand(s)
        if self.cause & CE:
            return d
        if is_nan(d) or is_nan(s):
            return self.nan_rule(d, s)
        if sub:
            s ^= 0x80000000
        if is_inf(d) and is_inf(s):
            return self.invalid() if (d ^ s) >> 31 else d
        if is_inf(d) or is_inf(s):
            return d if is_inf(d) else s
        if is_zero(d) and is_zero(s) and d == s:
            return d
        x = (0 if is_zero(d) else value(d)) + (0 if is_zero(s) else value(s))
        if x == 0:
            return self.zero((self.fpsw & 3) == 3)   # p. 87 / p. 100
        return self.to_single(x)

    def mul(self, d, s):
        d, s = self.operand(d), self.operand(s)
        if self.cause & CE:
            return d
        if is_nan(d) or is_nan(s):
            return self.nan_rule(d, s)
        neg = bool((d ^ s) >> 31)
        if is_inf(d) or is_inf(s):
            return self.invalid() if is_zero(d) or is_zero(s) else self.zero(neg) | 0x7F800000
        if is_zero(d) or is_zero(s):
            return self.zero(neg)
        return self.to_single(value(d) * value(s))

    def div(self, d, s):
        d, s = self.operand(d), self.operand(s)
        if self.cause & CE:
            return d
        if is_nan(d) or is_nan(s):
            return self.nan_rule(d, s)
        neg = bool((d ^ s) >> 31)
        if is_inf(d) and is_inf(s) or is_zero(d) and is_zero(s):
            return self.invalid()
        if is_inf(d):
            return self.zero(neg) | 0x7F800000
        if is_inf(s):
            return self.zero(neg)
        if is_zero(s):
            self.cause |= CZ                     # Table 1.4
            return self.zero(neg) | 0x7F800000
        if is_zero(d):
            return self.zero(neg)
        return self.to_single(value(d) / value(s))

    def sqrt(self, s):
        s = self.operand(s)
        if self.cause & CE:
            return s
        if is_nan(s):
            if is_snan(s):
                self.cause |= CV
                return s | 0x400000
            return s
        if is_zero(s):
            return s
        if s >> 31:
            return self.invalid()
        if is_inf(s):
            return s
        v = value(s)
        import math
        rn, rd = math.isqrt(v.numerator), math.isqrt(v.denominator)
        if rn * rn == v.numerator and rd * rd == v.denominator:
            return self.to_single(Fraction(rn, rd))          # an exact root
        # otherwise irrational: bisection to 2^-200 of the range, then the midpoint
        lo, hi = Fraction(0), max(v, Fraction(1))
        for _ in range(200):
            mid = (lo + hi) / 2
            if mid * mid <= v:
                lo = mid
            else:
                hi = mid
        if lo * lo == v:
            return self.to_single(lo)
        # lo < sqrt(v) < hi with hi - lo = 2^-200 * range: the rounding of either side is the same unless a
        # rounding boundary lies between them, which the 2^-200 grid excludes for single precision
        return self.to_single((lo + hi) / 2)

    def cmp(self, s2, s):
        s2, s = self.operand(s2), self.operand(s)
        if self.cause & CE:
            return None
        if is_nan(s2) or is_nan(s):
            if is_snan(s2) or is_snan(s):
                self.cause |= CV
            return 0, 0, 1
        a = 0 if is_zero(s2) else value(s2) if not is_inf(s2) else (1 << 200) * (-1 if s2 >> 31 else 1)
        b = 0 if is_zero(s) else value(s) if not is_inf(s) else (1 << 200) * (-1 if s >> 31 else 1)
        return int(a == b), int(a < b), 0

    def itof(self, n):
        if n == 0:
            return 0
        return self.to_single(Fraction(n))

    def to_int(self, kind, s):
        s = self.operand(s)
        if self.cause & CE:
            return s
        neg = bool(s >> 31)
        over = (0 if neg else 0xFFFFFFFF) if kind == 'ftou' else (0x80000000 if neg else 0x7FFFFFFF)
        if is_nan(s) or is_inf(s):
            self.cause |= CV
            return over
        if is_zero(s):
            return 0
        v = value(s)
        t = int(v)                               # towards 0
        if kind == 'round':
            rm, frac = self.fpsw & 3, v - t
            if frac != 0:
                fl = t if v > 0 else t - 1       # floor
                if rm == 0:
                    r = v - fl
                    t = fl + 1 if r > Fraction(1, 2) or r == Fraction(1, 2) and fl & 1 else fl
                elif rm == 2:
                    t = fl + 1
                elif rm == 3:
                    t = fl
        lo, hi = (0, 0xFFFFFFFF) if kind == 'ftou' else (-(1 << 31), (1 << 31) - 1)
        if not lo <= t <= hi:
            self.cause |= CV
            return over
        if t != v:
            self.cause |= CX
        return t & 0xFFFFFFFF

    def trap(self):
        return bool(self.cause & CE or self.cause & (self.fpsw >> 8) & 0x7C)

    def fpsw_after(self):
        f = (self.fpsw & ~0xFC) | self.cause
        f |= (self.cause & 0x7C & ~((self.fpsw >> 8) & 0x7C)) << 24
        f &= 0x7FFFFFFF
        if f & (0xF << 26):
            f |= 0x80000000
        return f


def expect(op, d, s, fpsw):
    """-> (end, dest, Z, S, O or None, fpsw) for dest = d op s (FCMP: s2 = d)."""
    r = Ref(fpsw)
    zso = None
    if op in ('fadd', 'fsub'):
        res = r.add(d, s, op == 'fsub')
    elif op == 'fmul':
        res = r.mul(d, s)
    elif op == 'fdiv':
        res = r.div(d, s)
    elif op == 'fcmp':
        zso = r.cmp(d, s)
        res = d
    elif op == 'fsqrt':
        res = r.sqrt(s)
    elif op in ('ftoi', 'ftou', 'round'):
        res = r.to_int(op, s)
    elif op == 'itof':
        res = r.itof(s - (1 << 32) if s >> 31 else s)
    elif op == 'utof':
        res = r.itof(s)
    if r.trap():
        return 'fault', d, None, None, None, r.fpsw_after()
    keep = r.cause != 0                          # S/Z (and O) unchanged when an exception is generated
    if op == 'fcmp':
        return 'return', d, (None if keep else zso[0]), (None if keep else zso[1]), (None if keep else zso[2]), \
            r.fpsw_after()
    if op in ('fadd', 'fsub', 'fmul', 'fdiv', 'fsqrt'):
        z = res & 0x7FFFFFFF == 0
    else:
        z = res == 0
    return 'return', res, (None if keep else int(z)), (None if keep else res >> 31), None, r.fpsw_after()


# ---------------------------------------------------------------- the cases

f2b = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
SPECIAL = [0x00000000, 0x80000000, 0x00000001, 0x807FFFFF, 0x00800000, 0x80800000, 0x00800001, 0x3F800000, 0xBF800000,
           0x3F800001, 0x3FC00000, 0x40000000, 0x4B000001, 0x7F7FFFFF, 0xFF7FFFFF, 0x7F000000, 0x01000000, 0x00FFFFFF,
           0x7F800000, 0xFF800000, 0x7FC00000, 0xFFC12345, 0x7F800001, 0xFFA00007, f2b(0.1), f2b(-3.0), f2b(255.0),
           f2b(0.5), f2b(2.5), f2b(-2.5), f2b(1e-38), f2b(3.4e38)]
INTS = [0, 1, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000, 0x01000001, 0x00FFFFFF, 0x01000003, 0x80000001, 0xFF000001, 255,
        0x12345678, 0xFFFFFF80, 0x7FFFFFC0, 0x7FFFFFBF]
rng = random.Random(710)


def rand_float():
    k = rng.random()
    if k < 0.6:
        return f2b(rng.choice([1, -1]) * rng.uniform(0, 1000))
    if k < 0.8:
        return rng.getrandbits(32)
    e = rng.choice([1, 2, 0x7D, 0x7E, 0x7F, 0x80, 0x96, 0x97, 0x9E, 0x9F, 0xFD, 0xFE])
    return rng.getrandbits(1) << 31 | e << 23 | rng.getrandbits(23)


FPSWS = [0x100, 0x101, 0x102, 0x103, 0x000, 0x500, 0x900, 0x1100, 0x2100, 0x4100, 0x7D00]

SRC = """
 .text
 .macro bin op
 .global _\\op\\()_r
_\\op\\()_r: \\op r2, r1
 rts
 .global _\\op\\()_m
_\\op\\()_m: \\op [r5].l, r1
 rts
 .global _\\op\\()_d
_\\op\\()_d: \\op 4[r5].l, r1
 rts
 .global _\\op\\()_w
_\\op\\()_w: \\op 1024[r5].l, r1
 rts
 .global _\\op\\()_i
_\\op\\()_i: \\op #0x12345678, r1
 rts
 .endm
 bin fadd
 bin fsub
 bin fmul
 bin fdiv
 bin fcmp
 .macro three op
 .global _\\op\\()_3
_\\op\\()_3: \\op r2, r3, r1
 rts
 .endm
 three fadd
 three fsub
 three fmul
 .macro una op
 .global _\\op\\()_r
_\\op\\()_r: \\op r2, r1
 rts
 .global _\\op\\()_m
_\\op\\()_m: \\op 4[r5].l, r1
 rts
 .endm
 una fsqrt
 una ftoi
 una ftou
 una round
 .macro conv op
 .global _\\op\\()_r
_\\op\\()_r: \\op r2, r1
 rts
 .global _\\op\\()_ub
_\\op\\()_ub: \\op 3[r5].ub, r1
 rts
 .global _\\op\\()_b
_\\op\\()_b: \\op 3[r5].b, r1
 rts
 .global _\\op\\()_w
_\\op\\()_w: \\op 2[r5].w, r1
 rts
 .global _\\op\\()_uw
_\\op\\()_uw: \\op 2[r5].uw, r1
 rts
 .global _\\op\\()_l
_\\op\\()_l: \\op 4[r5].l, r1
 rts
 .endm
 conv itof
 conv utof
"""


def build():
    d = tempfile.mkdtemp(dir=E.scratch_root())
    AS = E.tool('RX_BINUTILS', os.path.join(E.HOME, 'opt/rx-binutils-2.42/bin/rx-elf-'), 'as')
    LD = E.tool('RX_BINUTILS', os.path.join(E.HOME, 'opt/rx-binutils-2.42/bin/rx-elf-'), 'ld')
    open(d + '/t.s', 'w').write(SRC)
    subprocess.run([AS, '-mcpu=rxv2', d + '/t.s', '-o', d + '/t.o'], check=True)
    subprocess.run([LD, '-Ttext=0xFFF00000', '-e', '_fadd_r', d + '/t.o', '-o', d + '/t.elf'], check=True)
    from elftools.elf.elffile import ELFFile
    elf = ELFFile(open(d + '/t.elf', 'rb'))
    txt = elf.get_section_by_name('.text')
    syms = {s.name[1:]: s['st_value'] for s in elf.get_section_by_name('.symtab').iter_symbols()
            if s.name.startswith('_') and s.name[1:].split('_')[0] in
            ('fadd', 'fsub', 'fmul', 'fdiv', 'fcmp', 'fsqrt', 'ftoi', 'ftou', 'round', 'itof', 'utof')}
    return txt['sh_addr'], txt.data(), syms


def cases():
    out = []
    for op in ('fadd', 'fsub', 'fmul', 'fdiv', 'fcmp'):
        for d in SPECIAL:
            for s in SPECIAL:
                out.append((op, 'r', d, s, 0x100))
        for _ in range(400):
            out.append((op, rng.choice('rmdwi'), rand_float(), rand_float(), 0x100))
        for _ in range(250):
            out.append((op, rng.choice('rmi'), rng.choice(SPECIAL + [rand_float()]), rand_float(), rng.choice(FPSWS)))
        for s in SPECIAL:
            out.append((op, 'i', rand_float(), s, 0x100))
    for op in ('fadd', 'fsub', 'fmul'):
        for _ in range(200):
            out.append((op, '3', rng.choice(SPECIAL + [rand_float()]), rand_float(), rng.choice(FPSWS[:4])))
    for op in ('fsqrt', 'ftoi', 'ftou', 'round'):
        for s in SPECIAL + [f2b(x) for x in (0.4, 1.5, 3.5, -0.5, -1.0, -1.5, 50.7, 2147483520.0, 2147483648.0,
                                               4294967040.0, 4294967296.0, -2147483648.0, -2147483904.0)]:
            for fp in (0x100, 0x101, 0x102, 0x103, 0x000):
                out.append((op, 'r', 0x55555555, s, fp))
        for _ in range(300):
            out.append((op, rng.choice('rm'), 0x55555555, rand_float(), rng.choice(FPSWS)))
    for op in ('itof', 'utof'):
        for n in INTS:
            for fp in (0x100, 0x101, 0x102, 0x103):
                out.append((op, 'r', 0x55555555, n, fp))
        for _ in range(300):
            out.append((op, rng.choice(['r', 'ub', 'b', 'w', 'uw', 'l']), 0x55555555, rng.getrandbits(32),
                        rng.choice(FPSWS[:4] + [0x4100])))
    return out


def category(op, d, s, fpsw):
    """What makes a case special, for the module report: the first of NaN, DN (a denormal operand, an underflow or
    DN = 0), RM (FPSW.RM not 0), range (overflow or an integer conversion limit), else 'plain' (MAIN's FPSW, finite
    normal operands and result)."""
    r = Ref(fpsw)
    ops = (s,) if op in ('fsqrt', 'ftoi', 'ftou', 'round', 'itof', 'utof') else (d, s)
    floats = op not in ('itof', 'utof')
    if floats and any(is_nan(x) for x in ops):
        return 'NaN operand'
    if floats and any(is_denormal(x) for x in ops) or not fpsw & DN:
        return 'DN'
    expect(op, d, s, fpsw)
    r = Ref(fpsw)
    {'fadd': lambda: r.add(d, s), 'fsub': lambda: r.add(d, s, True), 'fmul': lambda: r.mul(d, s),
     'fdiv': lambda: r.div(d, s), 'fcmp': lambda: r.cmp(d, s), 'fsqrt': lambda: r.sqrt(s),
     'ftoi': lambda: r.to_int('ftoi', s), 'ftou': lambda: r.to_int('ftou', s), 'round': lambda: r.to_int('round', s),
     'itof': lambda: r.itof(s - (1 << 32) if s >> 31 else s), 'utof': lambda: r.itof(s)}[op]()
    if r.cause & CU:
        return 'DN'
    if r.cause & CV:
        return 'invalid'
    if fpsw & 3:
        return 'RM'
    if r.cause & (CO | CZ):
        return 'range'
    if floats and any(is_inf(x) for x in ops):
        return 'infinity'
    return 'plain'


def main():
    base, code, syms = build()
    img = E.Image()
    eng = E.Engine(img)
    eng.send({'op': 'base', 'name': 'new', 'segs': [[base, code.hex()]]})
    bad, total, classes = 0, 0, {}
    for op, form, d, s, fpsw in cases():
        loads, regs = [], {'R1': d, 'R5': 0x30000}
        src = s
        name = f'{op}_{form}'
        if op in ('itof', 'utof') and form != 'r':
            # the memory forms: s placed at the operand; the instruction sees it extended by memex (p. 55)
            if form in ('ub', 'b'):
                loads = [[0x30003, (s & 0xFF).to_bytes(1, 'little').hex()]]
                src = s & 0xFF
                if form == 'b' and src & 0x80:
                    src |= 0xFFFFFF00
            elif form in ('w', 'uw'):
                loads = [[0x30002, (s & 0xFFFF).to_bytes(2, 'little').hex()]]
                src = s & 0xFFFF
                if form == 'w' and src & 0x8000:
                    src |= 0xFFFF0000
            else:
                loads = [[0x30004, s.to_bytes(4, 'little').hex()]]
        elif form == 'r':
            regs['R2'] = s
        elif form == '3':
            regs['R2'] = s
            regs['R3'] = d
            regs['R1'] = 0x55555555
        elif form == 'm':
            loads = [[0x30000, s.to_bytes(4, 'little').hex()]]
        elif form == 'd':
            loads = [[0x30004, s.to_bytes(4, 'little').hex()]]
        elif form == 'w':
            loads = [[0x30400, s.to_bytes(4, 'little').hex()]]
        elif form == 'i':
            loads = [[syms[name] + 3, s.to_bytes(4, 'little').hex()]]
        if op in ('fsqrt', 'ftoi', 'ftou', 'round') and form == 'm':
            loads = [[0x30004, s.to_bytes(4, 'little').hex()]]
        q = {'op': 'run', 'bases': ['image', 'ram', 'new'], 'entry': syms[name], 'sp': E.STACK, 'seed': 1,
             'budget': 100, 'regs': regs, 'stack': [], 'loads': loads, 'snap': [], 'track': [], 'stubs': {},
             'cover': [], 'fpsw': fpsw, 'psw': 0x00030008}   # O = 1 at entry: FCMP must clear it
        if MODULE:
            q['module_fp'] = True
        r = eng.send(q)
        exp_end, exp_dest, z, sflag, o, exp_fpsw = expect(op, d, src, fpsw)
        psw = r['psw']
        why = []
        if MODULE:
            # the module has no traps and no FPSW: compare the destination and the flags of the cases that return
            if exp_end != 'return':
                continue
        elif r['end'] != exp_end:
            why.append(f'end {r["end"]} ({r["why"]})')
        if exp_end == 'return':
            exp_r1 = exp_dest if op != 'fcmp' else d
            if r['r1'] != exp_r1:
                why.append(f'dest 0x{r["r1"]:08x}')
            for nm, bit, want in (('Z', 1, z), ('S', 2, sflag), ('O', 3, o)):
                have = psw >> bit & 1
                if want is None:
                    if MODULE:
                        continue                      # kept by an exception: the module has none, not compared
                    want = 0x00030008 >> bit & 1      # unchanged
                if have != want:
                    why.append(f'{nm}={have}')
        else:
            if r['r1'] != d:
                why.append(f'dest changed 0x{r["r1"]:08x}')
        if not MODULE and r.get('fpsw', 0) != exp_fpsw:
            why.append(f'FPSW 0x{r.get("fpsw", 0):08x}')
        total += 1
        if why:
            bad += 1
            cls = (op, ' '.join(w.split(' ')[0].split('=')[0] for w in why))
            if MODULE:
                cls = (op, cls[1] + ' / ' + category(op, d, src, fpsw))
            classes[cls] = classes.get(cls, 0) + 1
            if VERBOSE or classes[cls] <= 2:
                print(f'{name:9s} d=0x{d:08x} s=0x{s:08x} fpsw=0x{fpsw:04x}: manual {exp_end} 0x{exp_dest:08x} '
                      f'Z{z} S{sflag} O{o} FPSW 0x{exp_fpsw:08x}; got {"; ".join(why)}')
    eng.close()
    print(f'rx_fpu_check{" (module p-code)" if MODULE else ""}: {total - bad} of {total} agree with the manual')
    for (op, k), n in sorted(classes.items()):
        print(f'  {op:6s} {k:24s} {n}')
    if MODULE:
        cats = {}
        for (op, k), n in classes.items():
            c = k.split(' / ')[1]
            cats[c] = cats.get(c, 0) + n
        print('  by case: ' + ', '.join(f'{c} {n}' for c, n in sorted(cats.items())))
    return 0 if bad == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
