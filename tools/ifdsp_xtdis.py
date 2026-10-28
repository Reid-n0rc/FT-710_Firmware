#!/usr/bin/env python3
"""Minimal Xtensa base-ISA linear disassembler for the IFDSP HiFi4 SRAM image (T12c).

usage: python3 -I tools/ifdsp_xtdis.py <sram_text.bin> <start_hex> [end_hex | +count] [--flixE N] [--flixF N]

Decodes the core/density/windowed/loop/MUL instructions that control code uses (entry, l32r, callN/callxN,
retw, loads/stores, moves, ALU, branches, extui, shifts, memw, loop). Anything else is printed as `.?`.
HiFi4 FLIX bundles (op0 = 0xE / 0xF) are NOT decoded; they are skipped as raw bytes. Their lengths are a
heuristic: op0 = 0xE is taken as a 6-byte bundle and op0 = 0xF as 11 bytes (chosen because a sweep over all
function entries then ends on a return before the next entry most often: 0xE=6 gives ~1005-1025 of 1120
functions, 0xE=3 ~856, 0xE=8 ~735). Treat output after a FLIX bundle as unverified until it re-syncs on a
known instruction. L32R operands are annotated with the literal value. Image base 0x200000.
"""
import struct
import sys

B = 0x200000
B4C = [-1, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 16, 32, 64, 128, 256]
B4CU = [32768, 65536, 2, 3, 4, 5, 6, 7, 8, 10, 12, 16, 32, 64, 128, 256]


def sx(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def dis(d, pc, flixE=6, flixF=11):
    o = pc - B
    b0 = d[o]
    op0 = b0 & 0xF
    if op0 >= 0xE:
        n = flixE if op0 == 0xE else flixF
        return n, 'FLIX[%d] %s' % (n, d[o:o + n].hex())
    if op0 >= 8:
        w = d[o] | d[o + 1] << 8
        t, s, r = (w >> 4) & 0xF, (w >> 8) & 0xF, (w >> 12) & 0xF
        if op0 == 8:
            return 2, 'l32i.n a%d, a%d, %d' % (t, s, r * 4)
        if op0 == 9:
            return 2, 's32i.n a%d, a%d, %d' % (t, s, r * 4)
        if op0 == 0xA:
            return 2, 'add.n a%d, a%d, a%d' % (r, s, t)
        if op0 == 0xB:
            return 2, 'addi.n a%d, a%d, %d' % (r, s, -1 if t == 0 else t)
        if op0 == 0xC:
            if t < 8:
                imm = (t & 7) << 4 | r
                if imm >= 96:
                    imm -= 128
                return 2, 'movi.n a%d, %d' % (s, imm)
            imm6 = (t & 3) << 4 | r
            return 2, '%s a%d, 0x%06x' % ('bnez.n' if t & 4 else 'beqz.n', s, pc + 4 + imm6)
        if op0 == 0xD:
            if r == 0:
                return 2, 'mov.n a%d, a%d' % (t, s)
            if r == 0xF:
                return 2, {0: 'ret.n', 1: 'retw.n', 2: 'break.n', 3: 'nop.n', 6: 'ill.n'}.get(t, '.?n')
        return 2, '.?n %04x' % w
    w = d[o] | d[o + 1] << 8 | d[o + 2] << 16
    t, s, r = (w >> 4) & 0xF, (w >> 8) & 0xF, (w >> 12) & 0xF
    op1, op2 = (w >> 16) & 0xF, (w >> 20) & 0xF
    imm8 = w >> 16
    if op0 == 0:
        if op1 == 0:
            if op2 == 0:
                if r == 0:
                    m, n = t >> 2, t & 3
                    if m == 2:
                        return 3, ['ret', 'retw', 'jx a%d' % s, '.?'][n]
                    if m == 3:
                        return 3, 'callx%d a%d' % (n * 4, s)
                if r == 1:
                    return 3, 'movsp a%d, a%d' % (t, s)
                if r == 2:
                    return 3, {0: 'isync', 1: 'rsync', 2: 'esync', 3: 'dsync', 8: 'excw', 0xC: 'memw', 0xD: 'extw', 0xF: 'nop'}.get(t, 'sync?')
                if r == 3:
                    return 3, 'rfe/rfi'
                if r == 6:
                    return 3, 'rsil a%d, %d' % (t, s)
                if r == 7:
                    return 3, 'waiti %d' % s
            names = {1: 'and', 2: 'or', 3: 'xor', 8: 'add', 9: 'addx2', 0xA: 'addx4', 0xB: 'addx8', 0xC: 'sub', 0xD: 'subx2', 0xE: 'subx4', 0xF: 'subx8'}
            if op2 == 2 and s == t:
                return 3, 'mov a%d, a%d' % (r, s)
            if op2 in names:
                return 3, '%s a%d, a%d, a%d' % (names[op2], r, s, t)
            if op2 == 4:
                return 3, {0: 'ssr a%d' % s, 1: 'ssl a%d' % s, 2: 'ssa8l a%d' % s, 3: 'ssa8b a%d' % s, 4: 'ssai %d' % (s | (t & 1) << 4),
                           8: 'rotw %d' % sx(t, 4), 0xE: 'nsa a%d, a%d' % (t, s), 0xF: 'nsau a%d, a%d' % (t, s)}.get(r, '.? st1')
            if op2 == 6:
                return 3, ('neg' if s == 0 else 'abs') + ' a%d, a%d' % (r, t)
        if op1 == 1:
            if op2 in (0, 1):
                return 3, 'slli a%d, a%d, %d' % (r, s, 32 - ((op2 & 1) << 4 | t))
            if op2 in (2, 3):
                return 3, 'srai a%d, a%d, %d' % (r, t, (op2 & 1) << 4 | s)
            if op2 == 4:
                return 3, 'srli a%d, a%d, %d' % (r, t, s)
            if op2 == 6:
                return 3, 'xsr a%d, sr%d' % (t, r << 4 | s)
            if op2 in (8, 9, 0xA, 0xB):
                return 3, ['src a%d, a%d, a%d' % (r, s, t), 'srl a%d, a%d' % (r, t), 'sll a%d, a%d' % (r, s), 'sra a%d, a%d' % (r, t)][op2 - 8]
            if op2 in (0xC, 0xD):
                return 3, '%s a%d, a%d, a%d' % ('mul16u' if op2 == 0xC else 'mul16s', r, s, t)
        if op1 == 2:
            nm = {8: 'mull', 0xA: 'muluh', 0xB: 'mulsh', 0xC: 'quou', 0xD: 'quos', 0xE: 'remu', 0xF: 'rems'}
            if op2 in nm:
                return 3, '%s a%d, a%d, a%d' % (nm[op2], r, s, t)
        if op1 == 3:
            if op2 == 0:
                return 3, 'rsr a%d, sr%d' % (t, r << 4 | s)
            if op2 == 1:
                return 3, 'wsr a%d, sr%d' % (t, r << 4 | s)
            nm = {2: 'sext', 3: 'clamps', 4: 'min', 5: 'max', 6: 'minu', 7: 'maxu', 8: 'moveqz', 9: 'movnez', 0xA: 'movltz', 0xB: 'movgez'}
            if op2 in nm:
                return 3, '%s a%d, a%d, a%d' % (nm[op2], r, s, t)
            if op2 == 0xE:
                return 3, 'rur a%d, ur%d' % (r, s << 4 | t)
            if op2 == 0xF:
                return 3, 'wur a%d, ur%d' % (t, r << 4 | s)
        if op1 in (4, 5):
            return 3, 'extui a%d, a%d, %d, %d' % (r, t, (op1 & 1) << 4 | s, op2 + 1)
        return 3, '.? qrst %06x' % w
    if op0 == 1:
        imm = w >> 8
        tgt = ((pc + 3) & ~3) + ((imm - 0x10000) << 2)
        v = struct.unpack_from('<I', d, tgt - B)[0] if B <= tgt < B + len(d) - 3 else None
        return 3, 'l32r a%d, [%06x] = %s' % (t, tgt, '0x%08x' % v if v is not None else '?')
    if op0 == 2:
        if r == 0:
            return 3, 'l8ui a%d, a%d, %d' % (t, s, imm8)
        if r == 1:
            return 3, 'l16ui a%d, a%d, %d' % (t, s, imm8 * 2)
        if r == 2:
            return 3, 'l32i a%d, a%d, %d' % (t, s, imm8 * 4)
        if r == 4:
            return 3, 's8i a%d, a%d, %d' % (t, s, imm8)
        if r == 5:
            return 3, 's16i a%d, a%d, %d' % (t, s, imm8 * 2)
        if r == 6:
            return 3, 's32i a%d, a%d, %d' % (t, s, imm8 * 4)
        if r == 9:
            return 3, 'l16si a%d, a%d, %d' % (t, s, imm8 * 2)
        if r == 0xA:
            return 3, 'movi a%d, %d' % (t, sx(s << 8 | imm8, 12))
        if r == 0xB:
            return 3, 'l32ai a%d, a%d, %d' % (t, s, imm8 * 4)
        if r == 0xC:
            return 3, 'addi a%d, a%d, %d' % (t, s, sx(imm8, 8))
        if r == 0xD:
            return 3, 'addmi a%d, a%d, %d' % (t, s, sx(imm8, 8) << 8)
        if r == 0xE:
            return 3, 's32c1i a%d, a%d, %d' % (t, s, imm8 * 4)
        if r == 0xF:
            return 3, 's32ri a%d, a%d, %d' % (t, s, imm8 * 4)
        return 3, '.? lsai %06x' % w
    if op0 == 3:
        return 3, '.? lsci(fp) %06x' % w
    if op0 == 4:
        return 3, '.? mac16 %06x' % w
    if op0 == 5:
        n = (w >> 4) & 3
        off = sx(w >> 6, 18)
        return 3, 'call%d 0x%06x' % (n * 4, (pc & ~3) + (off << 2) + 4)
    if op0 == 6:
        n, m = (w >> 4) & 3, (w >> 6) & 3
        if n == 0:
            return 3, 'j 0x%06x' % (pc + 4 + sx(w >> 6, 18))
        if n == 1:
            return 3, '%s a%d, 0x%06x' % (['beqz', 'bnez', 'bltz', 'bgez'][m], s, pc + 4 + sx(w >> 12, 12))
        if n == 2:
            return 3, '%s a%d, %d, 0x%06x' % (['beqi', 'bnei', 'blti', 'bgei'][m], s, B4C[r], pc + 4 + sx(imm8, 8))
        if m == 0:
            return 3, 'entry a%d, %d' % (s, (w >> 12) * 8)
        if m == 1:
            nm = {0: 'bf', 1: 'bt', 8: 'loop', 9: 'loopnez', 0xA: 'loopgtz'}.get(r, '.?b1')
            if r >= 8:
                return 3, '%s a%d, 0x%06x' % (nm, s, pc + 4 + imm8)
            return 3, '%s b%d, 0x%06x' % (nm, s, pc + 4 + sx(imm8, 8))
        return 3, '%s a%d, %d, 0x%06x' % ('bltui' if m == 2 else 'bgeui', s, B4CU[r], pc + 4 + sx(imm8, 8))
    if op0 == 7:
        tgt = pc + 4 + sx(imm8, 8)
        if r in (6, 7, 0xE, 0xF):
            return 3, '%s a%d, %d, 0x%06x' % ('bbci' if r < 8 else 'bbsi', s, (r & 1) << 4 | t, tgt)
        nm = ['bnone', 'beq', 'blt', 'bltu', 'ball', 'bbc', '', '', 'bany', 'bne', 'bge', 'bgeu', 'bnall', 'bbs'][r]
        return 3, '%s a%d, a%d, 0x%06x' % (nm, s, t, tgt)
    return 3, '.?'


def main():
    a = sys.argv[1:]
    flixE, flixF = 6, 11
    if '--flixE' in a:
        i = a.index('--flixE'); flixE = int(a[i + 1]); del a[i:i + 2]
    if '--flixF' in a:
        i = a.index('--flixF'); flixF = int(a[i + 1]); del a[i:i + 2]
    d = open(a[0], 'rb').read()
    pc = int(a[1], 16)
    end, count = None, 64
    if len(a) > 2:
        if a[2].startswith('+'):
            count = int(a[2][1:])
        else:
            end = int(a[2], 16)
    i = 0
    while (end is None and i < count) or (end is not None and pc < end):
        n, txt = dis(d, pc, flixE, flixF)
        print('%06x  %-22s %s' % (pc, d[pc - B:pc - B + min(n, 8)].hex(), txt))
        pc += n
        i += 1


if __name__ == '__main__':
    main()
