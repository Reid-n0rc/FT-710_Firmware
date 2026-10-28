#!/usr/bin/env python3
"""Compare the non-FLIX HiFi4 instructions in flix.dis with rizin's Xtensa decoder (T22c, #104).

flix.dis comes from the Zephyr SDK RT600 objdump (GNU libisa + the core's xtensa-modules.c). rizin 0.9 decodes Xtensa
with Capstone (an LLVM-derived table), so the two decoders share no code. The script drives rizin from flix.dis's own
instruction addresses (one `pdj 1 @ addr` per instruction), so FLIX bundles never desynchronise it, and compares the
mnemonic and every operand value.

usage: python3 -I tools/hifi4_rizin_compare.py RIZIN SRAM_TEXT_BIN FLIX_DIS OUT_TSV [--base 0x200000] [--cpu xtensa]

OUT_TSV gets one row per compared instruction: addr, bytes, class, flix text, rizin text. Classes:
  agree         same mnemonic and operand values (after the normalisation rules below)
  rz_illegal    rizin returns "illegal"/"invalid" (rizin cannot decode it)
  mnem          mnemonics differ
  operands      same mnemonic, operand values differ
  fpu_cfg       same mnemonic, rizin uses the standard FP option (f0..f15, standard field layout), the core's FPU does not
  bytes         the bytes in the image differ from the ones flix.dis prints (should never happen)
Normalisation: lower case; flix.dis's l32r value comment `(0x...)` dropped; numbers compared as integers (decimal or hex);
rizin's `rsr a, sr` form written as `rsr.sr a` (also wsr/xsr/rur/wur); immediates compared modulo 2^32;
flix.dis's `; name` comments dropped; rizin's PC-relative `. +-N` operand replaced by its absolute target (the `jump` field of pdj, or addr+N); `ae_*`
instructions are counted separately (HiFi4 extension, not base ISA).
"""
import json
import re
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict

LINE = re.compile(r'^\s+([0-9a-f]+):\t([0-9a-f]+)\s*\t(\S+)(?:\t(.*))?$')
NUM = re.compile(r'^-?(0x[0-9a-f]+|\d+)$')


def parse_flix(path):
    out = []
    for ln in open(path, encoding='utf-8'):
        m = LINE.match(ln.rstrip('\n'))
        if not m:
            continue
        addr, hx, mnem, ops = int(m.group(1), 16), m.group(2), m.group(3), (m.group(4) or '')
        if mnem.startswith('{') or mnem == '.byte':
            continue
        ops = re.sub(r'\s*;.*$', '', ops)
        ops = re.sub(r'\s*\(0x[0-9a-f]+\)\s*$', '', ops.strip())
        out.append((addr, hx, mnem.lower(), ops.lower()))
    return out


def toks(ops):
    return [t.strip() for t in ops.split(',')] if ops.strip() else []


def norm_tok(t):
    t = t.strip()
    if NUM.match(t):
        return int(t, 0) & 0xffffffff
    return t


def run_rizin(rizin, binf, base, cpu, insns):
    with tempfile.NamedTemporaryFile('w', suffix='.rz', delete=False) as f:
        f.write('e scr.color=0\ne asm.cpu=%s\n' % cpu)
        for a, *_ in insns:
            f.write('pdj 1 @ 0x%x\n' % a)
        script = f.name
    p = subprocess.run([rizin, '-q', '-a', 'xtensa', '-b', '32', '-m', hex(base), '-i', script, binf],
                       capture_output=True, text=True, timeout=1800)
    res = {}
    for ln in p.stdout.splitlines():
        ln = ln.strip()
        if not ln.startswith('['):
            continue
        for o in json.loads(ln):
            res[o['offset']] = o
    return res


def rz_split(o, addr):
    text = (o.get('disasm') or o.get('opcode') or '').lower().strip()
    parts = text.split(None, 1)
    mnem = parts[0] if parts else ''
    rest = toks(parts[1] if len(parts) > 1 else '')
    if mnem in SRFORM and len(rest) == 2:  # rizin "rsr a3, ps" = binutils "rsr.ps a3"
        mnem, rest = mnem + '.' + rest[1], rest[:1]
    ops = []
    for t in rest:
        m = re.match(r'^\.\s*([+-]?\s*(0x[0-9a-f]+|\d+))$', t)
        if m:  # ". N": PC-relative for branches/jumps/calls, absolute for l32r
            n = int(m.group(1).replace(' ', ''), 0)
            if o.get('jump') is not None and mnem != 'l32r':
                ops.append(o['jump'])
            elif mnem == 'l32r':
                ops.append(n)
            else:
                ops.append(addr + n)
        else:
            ops.append(norm_tok(t))
    return mnem, ops, text


SRFORM = ('rsr', 'wsr', 'xsr', 'rur', 'wur')
FREG = re.compile(r'^f\d+$')


def main(argv):
    opt = dict(zip(argv[1:], argv[2:]))
    base = int(opt.get('--base', '0x200000'), 0)
    cpu = opt.get('--cpu', 'xtensa')
    args = [a for i, a in enumerate(argv[1:], 1) if not a.startswith('--') and not argv[i - 1].startswith('--')]
    rizin, binf, flix, outp = args[:4]
    img = open(binf, 'rb').read()
    insns = parse_flix(flix)
    rz = run_rizin(rizin, binf, base, cpu, insns)
    cnt = Counter()
    cnt_ae = Counter()
    by_mnem = defaultdict(Counter)
    with open(outp, 'w', encoding='utf-8') as out:
        out.write('addr\tbytes\tclass\tflix\trizin\n')
        for addr, hx, mnem, ops in insns:
            b = img[addr - base: addr - base + len(hx) // 2].hex()
            o = rz.get(addr, {})
            rm, rops, rtext = rz_split(o, addr)
            fops = [norm_tok(t) for t in toks(ops)]
            if b != hx:
                c = 'bytes'
            elif rm in ('illegal', 'invalid', ''):
                c = 'rz_illegal'
            elif rm != mnem:
                c = 'mnem'
            elif rops != fops and any(isinstance(t, str) and FREG.match(t) for t in rops):
                c = 'fpu_cfg'
            elif rops != fops:
                c = 'operands'
            else:
                c = 'agree'
            (cnt_ae if mnem.startswith('ae_') else cnt)[c] += 1
            by_mnem[mnem][c] += 1
            out.write('%x\t%s\t%s\t%s %s\t%s\n' % (addr, hx, c, mnem, ops, rtext))
    tot = sum(cnt.values())
    print('non-FLIX instructions compared: %d (+ %d ae_* outside bundles)' % (tot, sum(cnt_ae.values())))
    for k in ('agree', 'rz_illegal', 'mnem', 'operands', 'fpu_cfg', 'bytes'):
        print('  %-11s %6d   ae_*: %d' % (k, cnt[k], cnt_ae[k]))
    print('per mnemonic (non-agree):')
    for m, c in sorted(by_mnem.items(), key=lambda kv: -sum(v for k, v in kv[1].items() if k != 'agree')):
        bad = {k: v for k, v in c.items() if k != 'agree'}
        if bad:
            print('  %-18s agree=%d %s' % (m, c['agree'], ' '.join('%s=%d' % kv for kv in sorted(bad.items()))))


if __name__ == '__main__':
    main(sys.argv)
