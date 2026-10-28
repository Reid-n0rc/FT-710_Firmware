#!/usr/bin/env python3
"""Independent code recovery for the DISPLAY image (ARMv7-A, A32 + Thumb-2), T22b (#104).

Stdlib only. It decodes the control-flow relevant ARM/Thumb encodings itself (ARM ARM DDI 0406C:
A5 for A32, A6 for Thumb) and runs a recursive descent from the exception vectors, from every
BL/BLX target, and from code pointers found in data. It does not use Ghidra, rizin or T21e output.

Outputs (in OUTDIR):
  jumptables.tsv  every computed-PC site: site, mode, kind, index reg, bound source, cases, table range, targets
  starts.tsv      function starts: addr, mode, sources (vector, call, prologue, dataptr, tailcall), reached
  coverage.tsv    byte classes as ranges: start, end(excl), class (code_a32/code_t32/literal/jumptable/
                  ref_data/string/zero/ff/pad/unknown), note
  conflicts.tsv   places where two decodings or code and literal data overlap
  summary.txt     counts

Usage:
  python3 -I tools/arm_recover.py build/FT-710_DISPLAY_V0108.bin OUTDIR [--base 0x20100000] [--text-end 0x20165178]
          [--objdump arm-none-eabi-objdump]   (optional cross-check: instructions objdump calls UNDEFINED)

Limits: calls are assumed to return (no no-return analysis), except to functions listed by --noreturn;
computed jumps other than the four table idioms (A32 LDR PC,[PC,Rm,LSL #2]; A32 ADD PC,PC,Rm,LSL #2;
Thumb TBB/TBH [PC,Rm]; Thumb ADD PC,Rm after an ADR) are listed but not followed.
"""
import argparse
import collections
import struct
import subprocess
import sys

COND_NAMES = ['EQ', 'NE', 'CS', 'CC', 'MI', 'PL', 'VS', 'VC', 'HI', 'LS', 'GE', 'LT', 'GT', 'LE', 'AL', 'NV']


def sext(v, bits):
    m = 1 << (bits - 1)
    return (v & (m - 1)) - (v & m)


def ror(v, n):
    n &= 31
    return ((v >> n) | (v << (32 - n))) & 0xFFFFFFFF


class Img:
    def __init__(self, data, base, text_end):
        self.d = data
        self.base = base
        self.end = base + len(data)
        self.text_end = text_end

    def in_text(self, a):
        return self.base <= a < self.text_end

    def u32(self, a):
        return struct.unpack_from('<I', self.d, a - self.base)[0]

    def u16(self, a):
        return struct.unpack_from('<H', self.d, a - self.base)[0]

    def u8(self, a):
        return self.d[a - self.base]


# ---------------------------------------------------------------- instruction model
# Each decode returns a dict: len, flow, targets, cond, extra.
# flow: 'seq' (falls through), 'jump' (unconditional, no fall-through), 'cjump' (conditional), 'call',
#       'ret', 'ijump' (computed, no fall-through), 'icall', 'stop' (invalid / undefined), 'table'.

def dec_a32(img, a):
    w = img.u32(a)
    cond = w >> 28
    r = {'len': 4, 'flow': 'seq', 't': [], 'cond': cond, 'lit': [], 'w': w, 'ref': []}
    cc = cond != 14
    pc = a + 8
    if cond == 15:
        if (w >> 25) & 7 == 5:                        # BLX imm (A2)
            h = (w >> 24) & 1
            r['flow'] = 'call'
            r['t'] = [((pc + (sext(w & 0xFFFFFF, 24) << 2) + (h << 1)) | 1)]
            return r
        # PLD/PLI (F5xx/F7xx...), barriers F57FF0xx, CPS F10xxxxx, SRS/RFE, CLREX: harmless
        if (w & 0xFD70F000) == 0xF550F000 or (w & 0xFFFFFF00) == 0xF57FF000 or (w & 0xFFF1FE20) == 0xF1000000 \
                or (w & 0xFE5FFFE0) == 0xF84D0500 or (w & 0xFE50FFFF) == 0xF8100A00 or (w & 0xFD70F010) == 0xF750F000 \
                or (w & 0xFF000000) in (0xF4000000, 0xF2000000, 0xF3000000) or (w & 0xFE000000) == 0xF2000000:
            return r                                  # incl. Advanced SIMD (F2/F3/F4)
        r['flow'] = 'stop'
        return r
    op1 = (w >> 25) & 7
    if op1 == 5:                                      # B / BL
        tgt = (pc + (sext(w & 0xFFFFFF, 24) << 2)) & 0xFFFFFFFF
        if (w >> 24) & 1:
            r['flow'] = 'call'
        else:
            r['flow'] = 'cjump' if cc else 'jump'
        r['t'] = [tgt]
        return r
    if (w & 0x0FFFFFF0) == 0x012FFF10:                # BX Rm
        rm = w & 15
        r['rm'] = rm
        r['flow'] = ('cret' if cc else 'ret') if rm == 14 else ('cijump' if cc else 'ijump')
        r['kind'] = 'bx'
        return r
    if (w & 0x0FFFFFF0) == 0x012FFF30:                # BLX Rm
        r['flow'] = 'icall'
        r['rm'] = w & 15
        return r
    if (w & 0x0FF000F0) == 0x07F000F0:                # UDF (permanently undefined)
        r['flow'] = 'stop'
        return r
    if op1 in (2, 3):                                 # LDR/STR (word/byte)
        if op1 == 3 and (w >> 4) & 1:
            return r                                  # media instructions
        L = (w >> 20) & 1
        rn = (w >> 16) & 15
        rt = (w >> 12) & 15
        B = (w >> 22) & 1
        U = (w >> 23) & 1
        P = (w >> 24) & 1
        if L and rn == 15 and op1 == 2:               # literal
            ad = pc + (w & 0xFFF if U else -(w & 0xFFF))
            sz = 1 if B else 4
            r['lit'] = [(ad, sz)]
            if rt == 15 and not B:
                r['flow'] = 'cijump' if cc else 'ijump'
                r['kind'] = 'ldr_pc_lit'
                if img.base <= ad < img.end - 3:
                    v = img.u32(ad)
                    r['t'] = [v]
                    r['flow'] = 'cjump' if cc else 'jump'
                    r['tailvia'] = True
            else:
                r['ldlit'] = (rt, ad, sz)
            return r
        if L and rt == 15 and not B:
            if rn == 13 and P == 0 and U == 1 and (w & 0xFFF) == 4 and op1 == 2:
                r['flow'] = 'cret' if cc else 'ret'    # POP {pc}
                return r
            if op1 == 3 and rn == 15 and ((w >> 7) & 31) == 2 and ((w >> 5) & 3) == 0 and P and U:
                r['flow'] = 'table'
                r['kind'] = 'a32_ldr_pc_pc_rm_lsl2'
                r['rm'] = w & 15
                return r
            r['flow'] = 'cijump' if cc else 'ijump'
            r['kind'] = 'ldr_pc_other'
            r['rn'] = rn
            r['rm'] = w & 15 if op1 == 3 else None
            return r
        return r
    if op1 == 4:                                      # LDM/STM
        L = (w >> 20) & 1
        rn = (w >> 16) & 15
        if L and (w >> 15) & 1:
            if rn == 13:
                r['flow'] = 'cret' if cc else 'ret'
            else:
                r['flow'] = 'cijump' if cc else 'ijump'
                r['kind'] = 'ldm_pc'
                r['rn'] = rn
        return r
    if op1 == 6:                                      # coprocessor: VLDR literal
        if (w & 0x0F300E00) == 0x0D100A00 and ((w >> 16) & 15) == 15:
            U = (w >> 23) & 1
            off = (w & 0xFF) * 4
            ad = (pc & ~3) + (off if U else -off)
            r['lit'] = [(ad, 8 if (w >> 8) & 1 else 4)]
        return r
    if op1 == 7:
        if (w >> 24) & 1:
            r['flow'] = 'seq'                         # SVC
        return r
    # op1 0/1: data processing, misc, multiply, extra load/store
    if op1 == 0 and (w & 0x90) == 0x90:               # multiply / extra load-store
        rn = (w >> 16) & 15
        L = (w >> 20) & 1
        op2 = (w >> 5) & 3
        if rn == 15 and (w >> 22) & 1 and (w >> 24) & 1 and op2:      # imm, pre-indexed, literal
            imm = ((w >> 4) & 0xF0) | (w & 15)
            ad = pc + (imm if (w >> 23) & 1 else -imm)
            if L:
                r['lit'] = [(ad, {1: 2, 2: 1, 3: 2}[op2])]
            elif op2 == 2:
                r['lit'] = [(ad, 8)]                  # LDRD
        return r
    opc = (w >> 21) & 15
    S = (w >> 20) & 1
    if op1 == 0 and (opc >> 2) == 2 and not S:        # misc (MRS/MSR/CLZ/BKPT...)
        return r
    if op1 == 1 and (opc >> 2) == 2 and not S:        # MOVW/MOVT/MSR imm
        return r
    rd = (w >> 12) & 15
    rn = (w >> 16) & 15
    imm = ror(w & 0xFF, ((w >> 8) & 15) * 2) if op1 == 1 else None
    if op1 == 1 and rn == 15 and rd != 15 and opc in (2, 4):          # ADR
        ad = pc - imm if opc == 2 else pc + imm
        r['ref'] = [ad]
        r['adr'] = (rd, ad)
    if opc in (8, 9, 10, 11):                         # TST TEQ CMP CMN
        if opc == 10 and op1 == 1:
            r['cmp'] = (rn, imm)
        return r
    if rd != 15:
        return r
    # PC written by data processing
    if opc == 13 and op1 == 0 and (w & 0xFF0) == 0 and (w & 15) == 14:
        r['flow'] = 'cret' if cc else 'ret'          # MOV(S) pc, lr
        return r
    if S and opc in (2, 13) and rn in (14, 0):
        r['flow'] = 'cret' if cc else 'ret'          # SUBS pc, lr, #n / MOVS pc, lr (exception return)
        return r
    if opc == 4 and op1 == 0 and rn == 15 and ((w >> 4) & 0xFF) == 0x10:
        r['flow'] = 'table'
        r['kind'] = 'a32_add_pc_pc_rm_lsl2'
        r['rm'] = w & 15
        return r
    r['flow'] = 'cijump' if cc else 'ijump'
    r['kind'] = 'dp_pc_' + ['and', 'eor', 'sub', 'rsb', 'add', 'adc', 'sbc', 'rsc', '', '', '', '', 'orr', 'mov', 'bic', 'mvn'][opc]
    r['rm'] = w & 15 if op1 == 0 else None
    r['rn'] = rn
    return r


def t32_bl_imm(h1, h2):
    S = (h1 >> 10) & 1
    j1 = (h2 >> 13) & 1
    j2 = (h2 >> 11) & 1
    i1 = 1 - (j1 ^ S)
    i2 = 1 - (j2 ^ S)
    v = (S << 24) | (i1 << 23) | (i2 << 22) | ((h1 & 0x3FF) << 12) | ((h2 & 0x7FF) << 1)
    return sext(v, 25)


def dec_t(img, a, itcond):
    """Thumb decode. itcond: True when the instruction is inside an IT block (conditional)."""
    h1 = img.u16(a)
    r = {'len': 2, 'flow': 'seq', 't': [], 'lit': [], 'ref': [], 'h1': h1}
    cc = itcond
    pc = a + 4
    top5 = h1 >> 11
    if top5 in (0x1D, 0x1E, 0x1F):
        if a + 2 >= img.text_end:
            r['flow'] = 'stop'
            return r
        h2 = img.u16(a + 2)
        r['len'] = 4
        r['h2'] = h2
        if top5 == 0x1E and (h2 & 0x8000):           # branches and misc control
            op = (h2 >> 12) & 7
            if op in (5, 7):                         # BL (T1)
                r['flow'] = 'call'
                r['t'] = [((pc + t32_bl_imm(h1, h2)) & 0xFFFFFFFF) | 1]
                return r
            if op in (4, 6):                         # BLX imm (T2): ARM target
                if h2 & 1:
                    r['flow'] = 'stop'
                    return r
                r['flow'] = 'call'
                r['t'] = [((pc & ~3) + t32_bl_imm(h1, h2)) & 0xFFFFFFFC]
                return r
            if op in (1, 3):                         # B.W (T4)
                r['flow'] = 'cjump' if cc else 'jump'
                r['t'] = [((pc + t32_bl_imm(h1, h2)) & 0xFFFFFFFF) | 1]
                return r
            if op in (0, 2):                         # B<c>.W (T3) or misc
                cond = (h1 >> 6) & 15
                if (cond >> 1) != 7:
                    S = (h1 >> 10) & 1
                    j1 = (h2 >> 13) & 1
                    j2 = (h2 >> 11) & 1
                    v = (S << 20) | (j2 << 19) | (j1 << 18) | ((h1 & 0x3F) << 12) | ((h2 & 0x7FF) << 1)
                    r['flow'] = 'cjump'
                    r['t'] = [((pc + sext(v, 21)) & 0xFFFFFFFF) | 1]
                    return r
                # MSR/MRS/hints/barriers; SUBS PC,LR (F3DE 8F00)
                if h1 == 0xF3DE and (h2 & 0xFF00) == 0x8F00:
                    r['flow'] = 'cret' if cc else 'ret'
                if (h1 & 0xFFF0) == 0xF7F0 and (h2 & 0xF000) == 0xA000:
                    r['flow'] = 'stop'               # UDF.W
                return r
        if (h1 & 0xFFF0) == 0xE8D0 and (h2 & 0xFFE0) == 0xF000:   # TBB/TBH
            r['flow'] = 'table'
            r['kind'] = 't32_tbh' if h2 & 0x10 else 't32_tbb'
            r['rn'] = h1 & 15
            r['rm'] = h2 & 15
            return r
        if (h1 & 0xFFD0) in (0xE890, 0xE910) and (h2 & 0x8000):      # LDM.W with pc
            rn = h1 & 15
            r['flow'] = ('cret' if cc else 'ret') if rn == 13 else ('cijump' if cc else 'ijump')
            r['kind'] = 'ldm_pc'
            return r
        if (h1 & 0xFE00) == 0xF800 and ((h1 >> 4) & 1) == 1 and top5 == 0x1F:   # loads
            rn = h1 & 15
            rt = h2 >> 12
            size = (h1 >> 5) & 3
            sgn = (h1 >> 8) & 1
            if rn == 15:
                U = (h1 >> 7) & 1
                off = h2 & 0xFFF
                ad = (pc & ~3) + (off if U else -off)
                if size == 2 and not sgn and rt == 15:
                    r['lit'] = [(ad, 4)]
                    r['kind'] = 'ldr_pc_lit'
                    r['flow'] = 'cjump' if cc else 'jump'
                    if img.base <= ad < img.end - 3:
                        r['t'] = [img.u32(ad)]
                        r['tailvia'] = True
                    return r
                if rt != 15:
                    r['lit'] = [(ad, [1, 2, 4, 4][size])]
                    if size == 2:
                        r['ldlit'] = (rt, ad, 4)
                return r
            if rt == 15 and size == 2 and not sgn:
                if rn == 13 and (h2 & 0xFFF) == 0xB04:
                    r['flow'] = 'cret' if cc else 'ret'
                    return r
                if (h2 & 0xFC0) == 0x080 and False:
                    pass
                r['flow'] = 'cijump' if cc else 'ijump'
                r['kind'] = 't32_ldr_pc_reg' if ((h1 >> 7) & 1) == 0 and (h2 & 0xFC0) == 0 else 't32_ldr_pc_other'
                r['rn'] = rn
                r['rm'] = h2 & 15 if r['kind'] == 't32_ldr_pc_reg' else None
                return r
            return r
        if (h1 & 0xFE5F) == 0xE85F:                  # LDRD literal
            U = (h1 >> 7) & 1
            off = (h2 & 0xFF) * 4
            r['lit'] = [((pc & ~3) + (off if U else -off), 8)]
            return r
        if (h1 & 0xFF3F) == 0xED1F and (h2 & 0x0E00) == 0x0A00:   # VLDR literal
            U = (h1 >> 7) & 1
            off = (h2 & 0xFF) * 4
            r['lit'] = [((pc & ~3) + (off if U else -off), 8 if (h2 >> 8) & 1 else 4)]
            return r
        if (h1 & 0xFBFF) in (0xF20F, 0xF2AF) and not (h2 & 0x8000):  # ADR.W
            i = (h1 >> 10) & 1
            imm = (i << 11) | (((h2 >> 12) & 7) << 8) | (h2 & 0xFF)
            ad = (pc & ~3) + (imm if (h1 & 0xFBFF) == 0xF20F else -imm)
            r['ref'] = [ad]
            r['adr'] = ((h2 >> 8) & 15, ad)
            return r
        if (h1 & 0xFBF0) == 0xF1B0 and (h2 & 0x8F00) == 0x0F00:   # CMP.W Rn,#imm (T2)
            i = (h1 >> 10) & 1
            imm12 = (i << 11) | (((h2 >> 12) & 7) << 8) | (h2 & 0xFF)
            r['cmp'] = (h1 & 15, t32_expand_imm(imm12))
            return r
        return r
    # 16-bit
    if (h1 & 0xF000) == 0xD000:
        cond = (h1 >> 8) & 15
        if cond == 15:
            return r                                 # SVC
        if cond == 14:
            r['flow'] = 'stop'                       # UDF
            return r
        r['flow'] = 'cjump'
        r['t'] = [((pc + sext(h1 & 0xFF, 8) * 2) & 0xFFFFFFFF) | 1]
        r['bcond'] = cond
        return r
    if (h1 & 0xF800) == 0xE000:
        r['flow'] = 'cjump' if cc else 'jump'
        r['t'] = [((pc + sext(h1 & 0x7FF, 11) * 2) & 0xFFFFFFFF) | 1]
        return r
    if (h1 & 0xF500) == 0xB100:                      # CBZ/CBNZ
        imm = (((h1 >> 9) & 1) << 6) | (((h1 >> 3) & 31) << 1)
        r['flow'] = 'cjump'
        r['t'] = [(pc + imm) | 1]
        return r
    if (h1 & 0xFF00) == 0xBF00 and (h1 & 15):        # IT
        mask = h1 & 15
        n = 4 - (mask & -mask).bit_length() + 1
        r['it'] = n
        return r
    if (h1 & 0xFF87) == 0x4700:                      # BX
        rm = (h1 >> 3) & 15
        r['rm'] = rm
        r['kind'] = 'bx'
        r['flow'] = ('cret' if cc else 'ret') if rm == 14 else ('cijump' if cc else 'ijump')
        return r
    if (h1 & 0xFF87) == 0x4780:                      # BLX Rm
        r['flow'] = 'icall'
        r['rm'] = (h1 >> 3) & 15
        return r
    if (h1 & 0xFE00) == 0xBC00 and (h1 & 0x100):     # POP {..,pc}
        r['flow'] = 'cret' if cc else 'ret'
        return r
    if (h1 & 0xFF00) in (0x4600, 0x4400) and (h1 & 0x87) == 0x87:   # MOV/ADD pc, Rm
        rm = (h1 >> 3) & 15
        if (h1 & 0xFF00) == 0x4600 and rm == 14:
            r['flow'] = 'cret' if cc else 'ret'
            return r
        r['flow'] = 'cijump' if cc else 'ijump'
        r['kind'] = 't16_mov_pc' if (h1 & 0xFF00) == 0x4600 else 't16_add_pc'
        r['rm'] = rm
        return r
    if (h1 & 0xF800) == 0x4800:                      # LDR literal
        ad = (pc & ~3) + (h1 & 0xFF) * 4
        r['lit'] = [(ad, 4)]
        r['ldlit'] = ((h1 >> 8) & 7, ad, 4)
        return r
    if (h1 & 0xF800) == 0xA000:                      # ADR
        ad = (pc & ~3) + (h1 & 0xFF) * 4
        r['ref'] = [ad]
        r['adr'] = ((h1 >> 8) & 7, ad)
        return r
    if (h1 & 0xF800) == 0x2800:                      # CMP Rn,#imm8
        r['cmp'] = ((h1 >> 8) & 7, h1 & 0xFF)
        return r
    if (h1 & 0xFF00) == 0xBE00:                      # BKPT
        r['flow'] = 'stop'
        return r
    return r


def t32_expand_imm(imm12):
    if (imm12 >> 10) == 0:
        v = imm12 & 0xFF
        t = (imm12 >> 8) & 3
        return [v, v | (v << 16), (v << 8) | (v << 24), v * 0x01010101][t]
    return ror(0x80 | (imm12 & 0x7F), imm12 >> 7)


def dec(img, a, mode, itc=False):
    return dec_a32(img, a) if mode == 'A' else dec_t(img, a, itc)


# ---------------------------------------------------------------- recovery
class Recover:
    def __init__(self, img, noreturn=()):
        self.img = img
        self.code = {}          # addr -> (mode, len)
        self.owner = bytearray(len(img.d))   # 0 none, 1 A32, 2 T32 (per byte)
        self.lit = {}           # addr -> size (literal-pool loads)
        self.tables = []        # computed-PC site records
        self.tbytes = {}        # table byte ranges: start -> (end, site)
        self.starts = collections.defaultdict(set)   # addr|mode -> sources
        self.conflicts = []
        self.refs = set()       # ADR targets and literal values pointing into the image
        self.bad = []           # paths that ran into undefined encodings
        self.noreturn = set(noreturn)
        self.history = {}       # addr -> previous instruction addr on the linear path (for CMP lookup)
        self.lits_val = {}      # literal address -> value
        self.pending = []       # (callee, fall-through addr, mode, call site) waiting for the callee to return
        self.table_targets = {} # table site -> targets
        self._fs = None
        self.bound_override = {}  # site -> entries (settled by hand, --bound)

    def key(self, a, mode):
        return (a & ~1, mode)

    def add_start(self, a, mode, src):
        self.starts[(a & ~1, mode)].add(src)

    def run(self, seeds):
        """Recursive descent to a fixpoint: call fall-throughs wait until the callee is shown to return."""
        self._run(seeds)
        while True:
            memo = {}
            self._fs = None
            rel, keep = [], []
            for p in self.pending:
                (rel if self.returns(p[0], memo, set()) else keep).append(p)
            self.pending = keep
            if not rel:
                break
            self._run([(nxt, mode, a) for _, nxt, mode, a in rel])

    def returns(self, f, memo, stack):
        """True when a return (or an unresolved indirect jump) is reachable from f without leaving it."""
        if f in memo:
            return memo[f]
        if f in stack or f in self.noreturn:
            return False
        stack.add(f)
        seen = set()
        todo = [f]
        res = False
        fstarts = self.fstart_addrs
        while todo and not res:
            a = todo.pop()
            if a in seen or a not in self.code:
                continue
            seen.add(a)
            mode, ln, r = self.code[a]
            fl = r['flow']
            if fl in ('ret', 'cret', 'ijump', 'cijump'):
                if fl in ('ijump', 'cijump') and r.get('kind', '').endswith('_const'):
                    pass
                else:
                    res = True
                    break
            if fl == 'call':
                if a + ln in self.code or self.returns(r['t'][0] & ~1, memo, stack):
                    todo.append(a + ln)
                continue
            if fl in ('jump', 'cjump'):
                for t in r['t']:
                    t &= ~1
                    if t in fstarts and t != f:
                        if self.returns(t, memo, stack):
                            res = True
                    else:
                        todo.append(t)
                if fl == 'jump':
                    continue
            if fl == 'table':
                todo.extend(x & ~1 for x in self.table_targets.get(a, ()))
            if fl not in ('jump', 'ijump', 'ret'):
                todo.append(a + ln)
        stack.discard(f)
        memo[f] = res
        return res

    @property
    def fstart_addrs(self):
        if self._fs is None:
            self._fs = {k[0] for k in self.starts}
        return self._fs

    def _run(self, seeds):
        img = self.img
        work = list(seeds)
        while work:
            a, mode, prev = work.pop()
            head = (a, prev)
            it = 0
            while True:
                if not img.in_text(a) or (mode == 'A' and a & 3) or (mode == 'T' and a & 1):
                    break
                other = 'T' if mode == 'A' else 'A'
                if 'call' in self.starts.get((a, other), ()) and (a, mode) not in self.starts:
                    self.conflicts.append((a, 'mode', f'{mode} path runs into a {other} call target'))
                    break
                if a in self.code:
                    if self.code[a][0] != mode:
                        self.conflicts.append((a, 'mode', f'{mode} path (head {head[0]:08x} from '
                                               f'{head[1] or 0:08x}) meets {self.code[a][0]} code'))
                    break
                o = a - img.base
                r = dec(img, a, mode, it > 0)
                ln = r['len']
                if a + ln > img.text_end:
                    break
                clash = [b for b in range(o, o + ln) if self.owner[b]]
                if clash:
                    self.conflicts.append((a, 'overlap', f'{mode} instruction (path head {head[0]:08x} from '
                                           f'{head[1] or 0:08x}) overlaps code at {img.base + clash[0]:08x}'))
                    break
                if r['flow'] == 'stop':
                    self.bad.append((a, mode, prev))
                    break
                r['head'] = head
                self.code[a] = (mode, ln, r)
                if prev is not None:
                    self.history[a] = prev
                for b in range(o, o + ln):
                    self.owner[b] = 1 if mode == 'A' else 2
                for ad, sz in r['lit']:
                    self.lit[ad] = max(self.lit.get(ad, 0), sz)
                    if img.base <= ad <= img.end - 4 and sz == 4:
                        v = img.u32(ad)
                        self.lits_val[ad] = v
                        if img.base <= v < img.end:
                            self.refs.add(v)
                for ad in r['ref']:
                    self.refs.add(ad)
                fl = r['flow']
                cond_now = it > 0 or (mode == 'A' and r.get('cond', 14) != 14)
                if it > 0:
                    it -= 1
                if 'it' in r:
                    it = r['it']
                nxt = a + ln
                if fl in ('call',):
                    for t in r['t']:
                        tm = 'T' if t & 1 else 'A'
                        self.add_start(t, tm, 'call')
                        work.append((t & ~1, tm, None))
                    if not cond_now:
                        # the fall-through is released only once the callee is known to return
                        self.pending.append(((r['t'][0] & ~1), nxt, mode, a))
                        break
                elif fl in ('jump', 'cjump'):
                    for t in r['t']:
                        if mode == 'A' and not r.get('tailvia'):
                            tm = 'A'
                        else:
                            tm = 'T' if t & 1 else 'A'
                        if r.get('tailvia'):
                            self.add_start(t, tm, 'tailvia')
                        work.append((t & ~1, tm, a))
                    if fl == 'jump':
                        break
                elif fl == 'table':
                    self.table(a, mode, r, work)
                    if not cond_now:
                        break
                elif fl in ('ijump', 'cijump'):
                    self.indirect(a, mode, r, work)
                    if fl == 'ijump':
                        break
                elif fl == 'ret':
                    break
                elif fl == 'icall':
                    self.indirect_call(a, mode, r, work)
                prev = a
                a = nxt

    # -- helpers for the computed jumps
    def back(self, a, n):
        """Up to n previous instructions on the linear path (fall-through predecessor chain)."""
        out = []
        cur = a
        for _ in range(n):
            mode = self.code.get(cur, ('A', 4))[0]
            p = cur - (4 if mode == 'A' else 2)
            cand = None
            for q in ((cur - 4, cur - 2) if mode == 'T' else (cur - 4,)):
                if q in self.code and self.code[q][1] == cur - q:
                    cand = q
                    break
            if cand is None:
                break
            out.append(cand)
            cur = cand
        return out

    def bound(self, a, rm):
        """Find CMP rm,#imm and the guard condition before a table jump. Returns (n_entries, how)."""
        mode = self.code[a][0]
        r0 = self.code[a][2]
        guard = None
        if mode == 'A' and r0['cond'] != 14:
            guard = r0['cond']
        if a in self.bound_override:
            return self.bound_override[a], 'manual'
        prevs = self.back(a, 32 if mode == 'A' else 8)
        for q in prevs:
            r = self.code[q][2]
            if mode == 'A' and 'cmp' not in r and r['flow'] == 'seq' and (r['w'] >> 26) & 3 == 0 \
                    and (r['w'] >> 20) & 1 and not ((r['w'] & 0x0F900000) == 0x01000000):
                break                    # a flag-setting instruction between the CMP and the jump
            if guard is None and r['flow'] in ('cjump',) and q != a:
                c = r['cond'] if mode == 'A' else r.get('bcond')
                if c is None and 'h2' in r:
                    c = (r['h1'] >> 6) & 15
                if c in (8, 2):          # BHI / BCS skips the table: in-range = LS / CC
                    guard = 9 if c == 8 else 3
            if 'cmp' in r and r['cmp'][0] == rm:
                imm = r['cmp'][1]
                if guard in (9,):
                    return imm + 1, f'cmp#{imm}+LS'
                if guard in (3,):
                    return imm, f'cmp#{imm}+CC'
                return None, f'cmp#{imm} no-guard'
            if 'w' in r and ((r['w'] >> 12) & 15) == rm and mode == 'A' and r['flow'] == 'seq' and not r.get('cmp'):
                # rm rewritten before the compare we are looking for: stop
                pass
        return None, 'none'

    def table(self, a, mode, r, work):
        img = self.img
        kind = r['kind']
        rm = r['rm']
        n, how = self.bound(a, rm)
        rec = {'site': a, 'mode': mode, 'kind': kind, 'rm': rm, 'bound': how, 'targets': [], 'cases': 0}
        if kind == 'a32_ldr_pc_pc_rm_lsl2':
            t0 = a + 8
            ents = []
            limit = n if n is not None else 1024
            for i in range(limit):
                ad = t0 + 4 * i
                if ad + 4 > img.text_end:
                    break
                v = img.u32(ad)
                if n is None and not (img.in_text(v) and abs(v - a) < 0x10000 and v & 3 == 0):
                    break
                ents.append(v)
            rec['tstart'], rec['tend'] = t0, t0 + 4 * len(ents)
            tg = [(v, 'A' if v & 1 == 0 else 'T') for v in ents]
            if n is None:
                rec['bound'] = 'scan'
        elif kind == 'a32_add_pc_pc_rm_lsl2':
            t0 = a + 8
            tg = []
            limit = n if n is not None else 1024
            for i in range(limit):
                ad = t0 + 4 * i
                if ad + 4 > img.text_end:
                    break
                if n is None:
                    w = img.u32(ad)
                    if (w >> 24) != 0xEA and not (i == 0):
                        break
                tg.append((ad, 'A'))
            rec['tstart'], rec['tend'] = t0, t0   # entries are instructions, decoded as code
            if n is None:
                rec['bound'] = 'scan'
        elif kind in ('t32_tbb', 't32_tbh'):
            if r['rn'] != 15:
                rec['bound'] += ' rn!=pc'
                self.tables.append(rec)
                return
            t0 = a + 4
            esz = 1 if kind == 't32_tbb' else 2
            tg = []
            limit = n if n is not None else 256
            vals = []
            for i in range(limit):
                ad = t0 + esz * i
                v = img.u8(ad) if esz == 1 else img.u16(ad)
                tgt = t0 + 2 * v
                if n is None:
                    end_tab = t0 + esz * (i + 1)
                    if tgt < end_tab or (vals and tgt > t0 + 0x1000):
                        break
                vals.append(v)
                tg.append((tgt, 'T'))
            rec['tstart'], rec['tend'] = t0, t0 + esz * len(vals)
            if rec['tend'] & 1:
                rec['tend'] += 1            # pad byte to the halfword boundary
            if n is None:
                rec['bound'] = 'scan'
        else:
            tg = []
        rec['cases'] = len(tg)
        rec['targets'] = [t for t, _ in tg]
        self.table_targets[a] = rec['targets']
        if rec.get('tend', 0) > rec.get('tstart', 0):
            self.tbytes[rec['tstart']] = (rec['tend'], a)
            o0, o1 = rec['tstart'] - img.base, rec['tend'] - img.base
            for b in range(o0, o1):
                if self.owner[b]:
                    self.conflicts.append((img.base + b, 'table', f'table of {a:08x} overlaps code'))
                    break
            for b in range(o0, o1):
                if not self.owner[b]:
                    self.owner[b] = 3
        self.tables.append(rec)
        for t, m in tg:
            work.append((t & ~1, m, None))

    def const_reg(self, a, reg, depth=6):
        """Value of reg if it was loaded from a literal (or by ADR) on the linear path just before a."""
        for q in self.back(a, depth):
            r = self.code[q][2]
            if 'ldlit' in r and r['ldlit'][0] == reg and r['ldlit'][2] == 4:
                ad = r['ldlit'][1]
                if self.img.base <= ad <= self.img.end - 4:
                    return self.img.u32(ad), 'lit'
                return None, None
            if 'adr' in r and r['adr'][0] == reg:
                return r['adr'][1], 'adr'
        return None, None

    def indirect(self, a, mode, r, work):
        rec = {'site': a, 'mode': mode, 'kind': r.get('kind', '?'), 'rm': r.get('rm'), 'bound': '-',
               'targets': [], 'cases': 0}
        rm = r.get('rm')
        if rec['kind'] in ('bx', 't16_mov_pc') and rm is not None:
            v, how = self.const_reg(a, rm)
            if v is not None:
                rec['kind'] += '_const'
                rec['bound'] = how
                rec['targets'] = [v]
                rec['cases'] = 1
                tm = 'T' if (v & 1) else 'A'
                if rec['kind'].startswith('bx'):
                    self.add_start(v, tm, 'tailvia')
                else:
                    tm = 'T' if mode == 'T' else 'A'
                work.append((v & ~1, tm, None))
        elif rec['kind'] == 't16_add_pc':
            # ADD PC,Rm: Rm holds an offset; armcc/gcc idiom ADR+LDR/ADD tables are rare. Not followed.
            pass
        if rec['kind'] in ('ret',):
            return
        self.tables.append(rec)

    def indirect_call(self, a, mode, r, work):
        rm = r.get('rm')
        if rm is None:
            return
        v, how = self.const_reg(a, rm)
        if v is not None and self.img.in_text(v & ~1):
            tm = 'T' if v & 1 else 'A'
            self.add_start(v, tm, 'icall_const')
            work.append((v & ~1, tm, None))


def is_prologue(img, a, mode):
    if mode == 'A':
        if a & 3 or a + 4 > img.text_end:
            return False
        w = img.u32(a)
        return (w & 0xFFFF4000) == 0xE92D4000 or w == 0xE52DE004
    if a & 1 or a + 2 > img.text_end:
        return False
    h = img.u16(a)
    if (h & 0xFF00) == 0xB500:
        return True
    if h == 0xE92D and a + 4 <= img.text_end and (img.u16(a + 2) & 0x4000):
        return True
    return False


def plausible(R, t, mode, limit=64):
    """Straight-line decode from t: no undefined encoding, no overlap with known code or literals, at least two
    instructions, and it ends in a return/branch/computed jump within `limit` instructions (calls are passed)."""
    img = R.img
    if mode == 'A' and (img.u32(t) >> 28) != 14:
        return False
    a, n, it = t, 0, 0
    while n < limit:
        if not img.in_text(a) or R.owner[a - img.base] or a in R.lit:
            return False
        r = dec(img, a, mode, it > 0)
        if r['flow'] == 'stop' or a + r['len'] > img.text_end:
            return False
        if it > 0:
            it -= 1
        if 'it' in r:
            it = r['it']
        n += 1
        if r['flow'] in ('ret', 'jump', 'ijump') or (r['flow'] == 'table' and r.get('cond', 14) == 14):
            return n >= 2 or (mode == 'A' and r['flow'] == 'jump')
        a += r['len']
    return False


def a32_like(img, t):
    """True when >= 4 of the 8 aligned words around t have condition AL (top nibble 0xE): A32 code, not Thumb."""
    w0 = (t & ~3) - 16
    n = 0
    for k in range(8):
        ad = w0 + 4 * k
        if img.base <= ad and ad + 4 <= img.text_end and (img.u32(ad) >> 28) == 14:
            n += 1
    return n >= 4


def lz_decompress(img, src, size):
    """armcc __decompress (the LZ variant used by Region$$Table handler 0x20100BFC)."""
    out = bytearray()
    p = src
    c = img.u8(p); p += 1
    while True:
        lit = c & 3
        if lit == 0:
            lit = img.u8(p); p += 1
        mlen = c >> 4
        if mlen == 0:
            mlen = img.u8(p); p += 1
        for _ in range(lit - 1):
            out.append(img.u8(p)); p += 1
        if mlen:
            off = img.u8(p); p += 1
            if (c & 0xC) == 0xC:
                off += img.u8(p) << 8; p += 1
            else:
                off += (c & 0xC) << 6
            s = len(out) - off
            for i in range(mlen + 2):
                out.append(out[s + i])
        if len(out) >= size:
            break
        c = img.u8(p); p += 1
    return bytes(out[:size]), p


def data_regions(img, region_table):
    regs = []
    if region_table is None:
        return regs
    for i in range(5):
        ld, ex, sz, fn = struct.unpack_from('<4I', img.d, region_table - img.base + 16 * i)
        if fn == 0x20100BFC:
            data, end = lz_decompress(img, ld, sz)
            regs.append((ex, data, ld, end))
    return regs


def classify_gap(img, s, e, refs):
    b = img.d[s - img.base:e - img.base]
    if all(x == 0 for x in b):
        return 'zero'
    if all(x == 0xFF for x in b):
        return 'ff'
    if e - s < 4 and all(x == 0 for x in b[: e - s]):
        return 'pad'
    pr = sum(1 for x in b if 32 <= x < 127 or x in (0, 9, 10, 13))
    if pr == len(b) and any(32 <= x < 127 for x in b) and b.rstrip(b'\0').find(b'\0') < 0 and len(b) >= 4:
        return 'string'
    if any(s <= r < e for r in refs):
        return 'ref_data'
    return 'unknown'


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('image')
    ap.add_argument('outdir')
    ap.add_argument('--base', type=lambda s: int(s, 0), default=0x20100000)
    ap.add_argument('--text-end', type=lambda s: int(s, 0), default=0x20165178)
    ap.add_argument('--region-table', type=lambda s: int(s, 0), default=0x204286A8)
    ap.add_argument('--vectors', type=int, default=8)
    ap.add_argument('--noreturn', default='', help='comma-separated addresses of functions that never return')
    ap.add_argument('--objdump', default=None, help='cross-check every recovered instruction with this objdump')
    ap.add_argument('--no-prologue-seeds', action='store_true')
    ap.add_argument('--bound', action='append', default=[],
                    help='SITE=N: table entry count settled by hand (guards the generic CMP search cannot read)')
    a = ap.parse_args()
    import os
    os.makedirs(a.outdir, exist_ok=True)
    data = open(a.image, 'rb').read()
    img = Img(data, a.base, a.text_end)
    nr = [int(x, 0) for x in a.noreturn.split(',') if x]
    R = Recover(img, nr)
    for x in a.bound:
        k, v = x.split('=')
        R.bound_override[int(k, 16)] = int(v, 0)

    # 1. vectors
    seeds = []
    for i in range(a.vectors):
        va = a.base + 4 * i
        R.add_start(va, 'A', 'vector')
        seeds.append((va, 'A', None))
        vr = dec_a32(img, va)
        if vr['flow'] == 'jump' and vr['t']:
            R.add_start(vr['t'][0], 'A', 'vector_target')
    R.run(seeds)

    # 2. data pointers to code: literal values, .rodata words, decompressed RW data words
    def ptr_sources():
        for ad, v in R.lits_val.items():
            yield ad, v, 'literal'
        o = a.text_end
        while o + 4 <= img.end:
            yield o, img.u32(o), 'rodata'
            o += 4
        for ex, d, ld, end in data_regions(img, a.region_table):
            for k in range(0, len(d) - 3, 4):
                yield ex + k, struct.unpack_from('<I', d, k)[0], 'rwdata'
    # 3. iterate: data pointers whose target is a prologue, a call target, or in a table of >= 2 pointers
    ptr_hits = collections.defaultdict(set)   # target key -> set of (where, kind)
    rounds = 0

    def dataptr_pass():
      nonlocal rounds
      added = 0
      while True:
        rounds += 1
        new = []
        cand = collections.defaultdict(set)
        seq = []
        for where, v, kind in ptr_sources():
            if not img.in_text(v & ~1):
                seq.append(None)
                continue
            mode = 'T' if v & 1 else 'A'
            t = v & ~1
            if mode == 'A' and t & 3:
                seq.append(None)
                continue
            cand[(t, mode)].add((where, kind))
            seq.append((where, t, mode))
        # adjacency: runs of >= 2 consecutive code-pointer words in rodata / rwdata
        intable = set()
        prevw = None
        run = []
        for x in seq + [None]:
            if x is not None and prevw is not None and x[0] == prevw + 4:
                run.append(x)
            else:
                if len(run) >= 2:
                    for y in run:
                        intable.add((y[1], y[2]))
                run = [x] if x is not None else []
            prevw = x[0] if x is not None else None
        for k, wh in cand.items():
            t, mode = k
            # accepted: the target is a prologue or a known start, or the pointer sits in a table of >= 2 code
            # pointers in .rodata/RW data, or (literal only) the target is already code of the same mode.
            o = t - img.base
            at_code = t in R.code and R.code[t][0] == mode
            gap_start = (not R.owner[o] and t not in R.lit and (o == 0 or R.owner[o - 1] or (t - 1) in R.lit
                         or any((t - k2) in R.lit for k2 in (1, 2, 4, 8)))
                         and ((mode == 'A' and img.u32(t) >> 28 == 14) or (mode == 'T' and not a32_like(img, t))))
            # a pointer to the start of an undecoded gap counts only if a straight-line decode from it is plausible
            gap_start = (gap_start or (not R.owner[o] and t not in R.lit)) and plausible(R, t, mode)
            ok = is_prologue(img, t, mode) or k in R.starts or (k in intable and any(w[1] != 'literal' for w in wh)) \
                or (any(w[1] == 'literal' for w in wh) and at_code) or gap_start
            if not ok:
                continue
            # the target must not be in the middle of an existing instruction / data
            if R.owner[o] and not at_code:
                continue
            if t in R.lit:
                continue
            ptr_hits[k] |= wh
            if 'dataptr' not in R.starts.get(k, ()):
                R.add_start(t, mode, 'dataptr')
                if t not in R.code:
                    new.append((t, mode, None))
        if not new:
            break
        added += len(new)
        R.run(new)
      return added
    # 4. prologues in the bytes not reached yet
    pro = []

    def prologue_pass():
        added = 0
        if a.no_prologue_seeds:
            return 0
        for mode in ('A', 'T'):          # A32 first; Thumb seeds only where the bytes do not look like A32
            while True:
                batch = []
                for o in range(0, a.text_end - a.base, 2):
                    t = a.base + o
                    if R.owner[o] or t in R.lit or (t, mode) in R.starts or not is_prologue(img, t, mode):
                        continue
                    if (mode == 'T') == a32_like(img, t):
                        continue
                    R.add_start(t, mode, 'prologue')
                    batch.append((t, mode, None))
                if not batch:
                    break
                pro.extend(batch)
                added += len(batch)
                R.run(batch)
        return added

    while dataptr_pass() + prologue_pass():
        pass
    # a prologue that the previous instruction falls into is a mid-function push (e.g. after `ldr`/`add ip,pc`
    # set-up instructions), not a start: drop it unless something else points at it
    nr_callees = {p[0] for p in R.pending}
    dropped = 0
    for (t, mode) in list(R.starts):
        src = R.starts[(t, mode)]
        if src - {'prologue', 'has_prologue'}:
            continue
        for q in (t - 4, t - 2) if mode == 'T' else (t - 4,):
            if q in R.code and R.code[q][0] == mode and q + R.code[q][1] == t:
                r = R.code[q][2]
                fl = r['flow']
                if fl in ('seq', 'cjump', 'cret', 'cijump', 'icall') or (fl == 'call' and (r['t'][0] & ~1) not in nr_callees) \
                        or (fl == 'table' and r.get('cond', 14) != 14):
                    del R.starts[(t, mode)]
                    dropped += 1
                break
    R.dropped_prologues = dropped
    # prologue flags for all starts reached by other means
    for (t, mode), src in list(R.starts.items()):
        if is_prologue(img, t, mode):
            src.add('has_prologue')

    # ---------------- outputs
    out = a.outdir
    with open(f'{out}/jumptables.tsv', 'w') as f:
        f.write('site\tmode\tkind\tindex_reg\tbound\tcases\ttable_start\ttable_end\tdistinct_targets\ttargets\n')
        for t in sorted(R.tables, key=lambda x: x['site']):
            f.write('%08x\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%d\t%s\n' % (
                t['site'], t['mode'], t['kind'], 'r%d' % t['rm'] if t['rm'] is not None else '-', t['bound'],
                t['cases'], '%08x' % t['tstart'] if 'tstart' in t else '-', '%08x' % t['tend'] if 'tend' in t else '-',
                len(set(t['targets'])), ','.join('%08x' % x for x in t['targets'])))
    with open(f'{out}/starts.tsv', 'w') as f:
        f.write('addr\tmode\tsources\treached\n')
        for (t, mode) in sorted(R.starts):
            f.write('%08x\t%s\t%s\t%s\n' % (t, mode, ','.join(sorted(R.starts[(t, mode)])), 'y' if t in R.code else 'n'))
    # coverage ranges
    cls = []
    n = a.text_end - a.base
    lit_b = bytearray(n)
    for ad, sz in R.lit.items():
        for b in range(ad - a.base, min(ad - a.base + sz, n)):
            if 0 <= b < n:
                lit_b[b] = 1
    lit_conf = 0
    for o in range(n):
        own = R.owner[o]
        if own and lit_b[o] and own in (1, 2):
            lit_conf += 1
    i = 0
    while i < n:
        own = R.owner[i]
        if own in (1, 2, 3):
            c = {1: 'code_a32', 2: 'code_t32', 3: 'jumptable'}[own]
            j = i
            while j < n and R.owner[j] == own:
                j += 1
        elif lit_b[i]:
            c = 'literal'
            j = i
            while j < n and lit_b[j] and not R.owner[j]:
                j += 1
        else:
            j = i
            while j < n and not R.owner[j] and not lit_b[j]:
                j += 1
            c = classify_gap(img, a.base + i, a.base + j, R.refs)
        cls.append((a.base + i, a.base + j, c))
        i = j
    with open(f'{out}/coverage.tsv', 'w') as f:
        f.write('start\tend\tclass\tbytes\n')
        for s, e, c in cls:
            f.write('%08x\t%08x\t%s\t%d\n' % (s, e, c, e - s))
    with open(f'{out}/xrefs.tsv', 'w') as f:
        f.write('from\tto\tkind\n')
        for ad in sorted(R.code):
            m, ln, r = R.code[ad]
            if r['flow'] in ('call', 'jump', 'cjump'):
                for t in r['t']:
                    f.write('%08x\t%08x\t%s\n' % (ad, t & ~1, r['flow'] + ('_via_literal' if r.get('tailvia') else '')))
        for t in R.tables:
            for x in t['targets']:
                f.write('%08x\t%08x\t%s\n' % (t['site'], x & ~1, 'table' if t['kind'].startswith(('a32_', 't32_tb'))
                                              else 'indirect_const'))
        for (t, mode), wh in sorted(ptr_hits.items()):
            for where, kind in sorted(wh):
                f.write('%08x\t%08x\tdataptr_%s\n' % (where, t, kind))
    with open(f'{out}/conflicts.tsv', 'w') as f:
        f.write('addr\tkind\tnote\n')
        for ad, k, note in sorted(set(R.conflicts)):
            f.write('%08x\t%s\t%s\n' % (ad, k, note))
        for ad, mode, prev in sorted(R.bad):
            f.write('%08x\tundefined\t%s path reached an undefined encoding (from %s)\n' % (
                ad, mode, '%08x' % prev if prev else '-'))
    tot = collections.Counter()
    for s, e, c in cls:
        tot[c] += e - s
    kinds = collections.Counter(t['kind'] for t in R.tables)
    src = collections.Counter()
    for k, v in R.starts.items():
        for x in v:
            src[x] += 1
    with open(f'{out}/summary.txt', 'w') as f:
        f.write(f'instructions {len(R.code)} (A32 {sum(1 for v in R.code.values() if v[0]=="A")}, '
                f'T32 {sum(1 for v in R.code.values() if v[0]=="T")})\n')
        f.write(f'function starts {len(R.starts)}; by source {dict(sorted(src.items()))}\n')
        f.write(f'computed-PC sites {len(R.tables)}: {dict(sorted(kinds.items()))}\n')
        f.write(f'table cases {sum(t["cases"] for t in R.tables if t["kind"].startswith(("a32_", "t32_tb")))}\n')
        f.write(f'bytes by class {dict(sorted(tot.items()))}\n')
        f.write(f'code bytes also loaded as literal {lit_conf}\n')
        f.write(f'conflicts {len(set(R.conflicts))}, undefined-encoding stops {len(R.bad)}\n')
        f.write(f'data-pointer rounds {rounds}; mid-function prologues dropped {R.dropped_prologues}\n')
        nrf = sorted({p[0] for p in R.pending})
        f.write(f'no-return callees (call fall-throughs not followed) {len(nrf)}: {" ".join("%08x" % x for x in nrf)}\n')
    if a.objdump:
        objdump_check(img, R, a.objdump, out)
    sys.stdout.write(open(f'{out}/summary.txt').read())


def objdump_check(img, R, objdump, out):
    """Re-disassemble every recovered run with objdump and list instructions it calls undefined/unpredictable."""
    import tempfile, os
    runs = []
    for a in sorted(R.code):
        m, ln, _ = R.code[a]
        if runs and runs[-1][2] == m and runs[-1][1] == a:
            runs[-1][1] = a + ln
        else:
            runs.append([a, a + ln, m])
    tmp = tempfile.NamedTemporaryFile(delete=False, suffix='.bin')
    tmp.write(img.d[: img.text_end - img.base])
    tmp.close()
    bad = []
    for m in ('A', 'T'):
        rr = [r for r in runs if r[2] == m]
        # one objdump call per mode over the whole text; filter to the recovered starts
        args = [objdump, '-D', '-b', 'binary', '-m', 'arm', f'--adjust-vma=0x{img.base:x}']
        if m == 'T':
            args += ['-M', 'force-thumb']
        args.append(tmp.name)
        txt = subprocess.run(args, capture_output=True, text=True).stdout
        want = {a for a, v in R.code.items() if v[0] == m}
        for line in txt.splitlines():
            ad, _, rest = line.strip().partition(':')
            if not rest:
                continue
            try:
                x = int(ad, 16)
            except ValueError:
                continue
            if x in want and ('UNDEFINED' in rest or 'UNPREDICTABLE' in rest or 'undefined' in rest):
                bad.append((x, m, rest.strip()))
    os.unlink(tmp.name)
    with open(f'{out}/objdump_flags.tsv', 'w') as f:
        f.write('addr\tmode\tobjdump\n')
        for x, m, s in sorted(bad):
            f.write('%08x\t%s\t%s\n' % (x, m, s.replace('\t', ' ')))
    with open(f'{out}/summary.txt', 'a') as f:
        f.write(f'objdump flags undefined/unpredictable on {len(bad)} recovered instructions '
                f'(Thumb positions are only checked where objdump\'s linear pass is in sync)\n')


if __name__ == '__main__':
    main()
