#!/usr/bin/env python3
"""RX651 peripheral-register table (T23a): parse Table 5.1 of the hardware manual into tools/ghidra/sfr_rx651.tsv.

The source is the committed manual `Manuals/Renesas/r01uh0590ej0240-rx651.pdf` (RX65N/RX651 HWM Rev.2.40), chapter 5,
"Table 5.1 List of I/O Registers (Address Order)" (53 table pages). `pdftotext -layout` (poppler-utils) turns it into text;
this script rebuilds the rows (register names and symbols wrap onto a second line, ranges such as `IR016 to IR255` span
two or three lines), expands every range into one row per register, and marks registers that share an address.

Usage:
  python3 -I tools/sfr_table.py build [--pdf PDF] [--out tools/ghidra/sfr_rx651.tsv] [--first N --last N]
      Find the table pages (unless --first/--last are given), parse, check, write the TSV. Exit 1 if a check fails.
  python3 -I tools/sfr_table.py check [--tsv tools/ghidra/sfr_rx651.tsv]
      Re-run the checks on a committed TSV (no PDF needed).
  python3 -I tools/sfr_table.py coverage [decomp/main] [--tsv ...]
      How many DAT_<address> references in the decompiled C fall on a register in the TSV, before or without Ghidra;
      lists the I/O addresses the TSV lacks (new firmware, or a register for the EXTRA list). Text only, no Ghidra.
  python3 -I tools/sfr_table.py text <layout.txt> [--out ...]
      Parse a text file made earlier with `pdftotext -layout` (for debugging the parser).

TSV columns (tab separated, '#' lines are comments; read by tools/ghidra/ApplySfr.java):
  address   8 hex digits, no 0x
  label     MODULE_SYMBOL (e.g. IWDT_IWDTCR, SCI0_SMR, ICU_IR016): the Ghidra label
  module    module symbol from the manual (SYSTEM, ICU, SCI0, PORT3, ...)
  symbol    register symbol from the manual
  bits      register width in bits (8, 16, 32, 64, 128)
  access    access sizes from the manual ("8", "8, 16", ...)
  primary   1 = first register listed at this address (gets the type and the primary label); 0 = alias
            (another mode of the same register, e.g. SMCI0_SMR next to SCI0_SMR, or TDRL inside TDRHL)
  overlap   1 = another register overlaps these bytes with a different start or size; ApplySfr.java then only labels it
  section   manual section number ('-' for the EXTRA rows below, which are not in Table 5.1)
  name      register name from the manual

To redo after a new manual revision: drop the new PDF into Manuals/Renesas/, run `build --pdf <it>`, review the diff of
the TSV (the checks below must pass), commit it, then re-apply it in Ghidra (docs/tasks/T23-readability.md, T23a).
"""
import argparse
import re
import subprocess
import sys
from collections import defaultdict

PDF = 'Manuals/Renesas/r01uh0590ej0240-rx651.pdf'
TSV = 'tools/ghidra/sfr_rx651.tsv'
TITLE = 'List of I/O Registers (Address Order)'

ADDR = re.compile(r'^ ?([0-9A-F]{4}) ([0-9A-F]{4})h\b(\s+to\b)?(.*)$')
TO_ONLY = re.compile(r'^ ?to\b(.*)$')
# module, then name/symbol text, then bits and access size, then the access-cycle and section columns
ROW = re.compile(r'^\s*(\S+)\s+(.*?)\s+(\d+)\s+(\d+(?:,\s*\d+)*,?)\s+.*?section\s+(\d+)\s*$')
SKIP = re.compile(r'Table 5\.1|Number of Access|Module\s+Register|Address\s+Symbol|^R01UH|^\S.* Group, |^[A-Z][a-z]{2} \d+, \d{4}$|^\s*Note')
SYM = re.compile(r'^[A-Z][A-Z0-9_]*$')

# Known registers (address, label): from the manual's own chapters and docs/code/main/*.md. A parse that loses or moves
# any of them fails the build.
KNOWN = [
    (0x00080000, 'SYSTEM_MDMONR'), (0x000803FE, 'SYSTEM_PRCR'), (0x00087010, 'ICU_IR016'), (0x000870FF, 'ICU_IR255'),
    (0x0008711A, 'ICU_DTCER026'), (0x00087202, 'ICU_IER02'), (0x0008721F, 'ICU_IER1F'), (0x000873FF, 'ICU_IPR255'),
    (0x0008750F, 'ICU_IRQCR15'), (0x00087780, 'ICU_SLIBXR128'), (0x00088030, 'IWDT_IWDTRR'), (0x00088032, 'IWDT_IWDTCR'),
    (0x0008A000, 'SCI0_SMR'), (0x0008A0E0, 'SCI7_SMR'), (0x0008C29A, 'SYSTEM_LVD1CR0'), (0x0008C2BF, 'SYSTEM_DPSBKR31'),
    (0x000903F0, 'CAN0_MB31'), (0x00095AFC, 'SDSI_FN1DATAR363'),
]

# Registers the firmware uses that Table 5.1 does not list (address, module, symbol, bits, access, name). Each name says
# where it comes from; keep them few and sourced.
EXTRA = [
    (0x00087200, 'ICU', 'IER00', 8, '8', 'Interrupt Request Enable Register 00 [not in Table 5.1 (reserved); the base of '
     'IER[vector >> 3], which MAIN indexes from 0x87200, HWM s15.2.2]'),
    (0x00087201, 'ICU', 'IER01', 8, '8', 'Interrupt Request Enable Register 01 [not in Table 5.1 (reserved), see IER00]'),
    (0x00084080, 'DBG', 'C2E0', 32, '32', 'Debug console CPU-to-emulator data [not in Table 5.1; inference: the E1/E2 '
     'emulator virtual-console port of the Renesas BSP low-level I/O (lowlvl.c)]'),
    (0x00084090, 'DBG', 'E2C0', 32, '32', 'Debug console emulator-to-CPU data [not in Table 5.1; inference, see DBG_C2E0]'),
    (0x000840C0, 'DBG', 'DBGSTAT', 32, '32', 'Debug console status (bit 8 TX full, bit 12 RX ready) [not in Table 5.1; '
     'inference, see DBG_C2E0]'),
]


def pdf_text(pdf, first, last):
    return subprocess.run(['pdftotext', '-layout', '-f', str(first), '-l', str(last), pdf, '-'],
                          check=True, capture_output=True, text=True).stdout


def find_pages(pdf):
    """Table pages: the first page whose text has the table title, through the last consecutive one."""
    pages = pdf_text(pdf, 150, 450).split('\f')
    hits = [150 + i for i, p in enumerate(pages) if TITLE in p and re.search(r'^ ?[0-9A-F]{4} [0-9A-F]{4}h', p, re.M)]
    if not hits:
        sys.exit(f'sfr_table: no page with "{TITLE}" in {pdf} pages 150-450; pass --first/--last')
    return hits[0], hits[-1]


def records(text):
    """Group the layout lines into rows: [(start, end or None, first line text, [(col, continuation text)])]."""
    recs = []
    for line in text.split('\n'):
        if not line.strip() or SKIP.search(line.strip()) or line.strip().startswith('Page '):
            continue
        m = ADDR.match(line)
        if m:
            addr = int(m.group(1) + m.group(2), 16)
            rest = m.group(4)
            cur = recs[-1] if recs else None
            # The end address of a range row: the previous row is a range without an end, and this line is not a row.
            if cur and cur['range'] and cur['end'] is None and not ROW.match(rest):
                cur['end'] = addr
                cur['cont'].append((m.start(4), rest))
                continue
            off = m.start(4)
            recs.append({'start': addr, 'end': None, 'range': bool(m.group(3)), 'first': rest, 'off': off, 'cont': []})
            continue
        t = TO_ONLY.match(line)
        if recs and t:
            recs[-1]['range'] = True
            recs[-1]['cont'].append((t.start(1), t.group(1)))
            continue
        if recs:
            recs[-1]['cont'].append((0, line))
    return recs


def chunks(s, base=0):
    """Text chunks separated by 2+ spaces, with their column."""
    return [(base + m.start(), m.group(0)) for m in re.finditer(r'\S+(?: \S+)*', s)]


def parse(text):
    rows, bad = [], []
    for r in records(text):
        m = ROW.match(r['first'])
        if not m:
            bad.append(f"{r['start']:08X}: {r['first'].strip()}")
            continue
        module, mid, bits, access, section = m.groups()
        # FTDR.H -> FTDR_H, GR1CLUT0[0] -> GR1CLUT0_0 (Ghidra labels take [A-Za-z0-9_]).
        mid = re.sub(r'(?<=[A-Z0-9])\.(?=[A-Z])', '_', re.sub(r'(?<=[A-Z0-9])\[(\d+)\]', r'_\1', mid))
        # Split the middle text into register name and symbol: the symbol is the last chunk (2+ spaces before it),
        # or the last word when only one space separates it ("... Setting Register SPBMUL0").
        cs = chunks(mid, r['off'] + m.start(2))
        if len(cs) >= 2:
            name, (symcol, sym) = ' '.join(c for _, c in cs[:-1]), cs[-1]
        else:
            words = cs[0][1].rsplit(' ', 1) if cs else ['']
            if len(words) == 2 and words[1] == 'to':
                w2 = words[0].rsplit(' ', 1)
                words = [w2[0], w2[1] + ' to'] if len(w2) == 2 else words
            if len(words) == 2 and SYM.match(words[1].split(' ')[0]):
                name, sym, symcol = words[0], words[1], cs[0][0] + len(words[0]) + 1
            else:
                bad.append(f"{r['start']:08X}: no symbol in {mid!r}")
                continue
        if sym.endswith(' to'):
            r['range'] = True
        elif ' to ' in sym:
            r['range'] = True
        # Continuation lines: text left of the symbol column continues the name, text at it continues the symbol.
        for col, line in r['cont']:
            line = re.sub(r'(?<=[A-Z0-9])\[(\d+)\]', r'_\1', line)
            for c, txt in chunks(line, col):
                if c < symcol - 2:
                    name += ' ' + txt
                elif c < symcol + 16 and SYM.match(txt.split(' ')[0]):
                    sym += ' ' + txt
        name = re.sub(r'\s+', ' ', name).strip()
        sym = re.sub(r'\s+', ' ', sym).strip()
        bits = int(bits)
        access = re.sub(r',\s*$', '', re.sub(r',\s*', ', ', access))
        base = dict(module=module, bits=bits, access=access, section=section, name=name)
        if r['range'] or ' to' in sym:
            rows.extend(expand(r, sym, base, bad))
        else:
            if not SYM.match(sym):
                bad.append(f"{r['start']:08X}: odd symbol {sym!r}")
                continue
            rows.append(dict(base, address=r['start'], symbol=sym))
    return rows, bad


def expand(r, sym, base, bad):
    """IR016 to IR255 -> IR016, IR017, ... at stride bits/8, choosing the prefix/number split that fits the span."""
    parts = sym.replace(' to ', ' to ').split(' to ')
    if len(parts) != 2 or r['end'] is None:
        bad.append(f"{r['start']:08X}: range without end ({sym!r}, end {r['end']})")
        return []
    a, b = parts[0].strip(), parts[1].strip()
    stride = max(1, base['bits'] // 8)
    # The end address is usually the range's last byte, but some rows (GLCDC CLUTs) give the last register's start.
    wants = {(r['end'] + 1 - r['start']) // stride, (r['end'] - r['start']) // stride + 1}
    for k in range(len(a) - 1, 0, -1):
        pa, sa, sb = a[:k], a[k:], b[k:] if b[:k] == a[:k] else None
        if sb is None or not sa or not sb:
            continue
        for radix in (10, 16):
            try:
                na, nb = int(sa, radix), int(sb, radix)
            except ValueError:
                continue
            want = nb - na + 1
            if want not in wants:
                continue
            width = len(sa) if len(sa) == len(sb) else 0
            fmt = (lambda n: f'{n:0{width}X}') if radix == 16 else (lambda n: f'{n:0{width}d}')
            return [dict(base, address=r['start'] + i * stride, symbol=pa + fmt(na + i)) for i in range(want)]
    bad.append(f"{r['start']:08X}: cannot expand {sym!r} over {sorted(wants)} registers")
    return []


def finish(rows):
    """Labels, primary/alias and overlap flags; rows in address order (stable, so the manual's order breaks ties)."""
    rows.sort(key=lambda x: x['address'])
    seen = set()
    for x in rows:
        x['label'] = f"{x['module']}_{x['symbol']}"
        x['primary'] = 0 if x['address'] in seen else 1
        seen.add(x['address'])
    byte_owner = defaultdict(set)
    for i, x in enumerate(rows):
        for o in range(max(1, x['bits'] // 8)):
            byte_owner[x['address'] + o].add((x['address'], x['bits']))
    for x in rows:
        shapes = set()
        for o in range(max(1, x['bits'] // 8)):
            shapes |= byte_owner[x['address'] + o]
        x['overlap'] = 1 if len(shapes) > 1 else 0
    return rows


def check(rows):
    errs = []
    by_label = defaultdict(list)
    for x in rows:
        by_label[x['label']].append(x['address'])
    for addr, label in KNOWN:
        if addr not in by_label.get(label, []):
            errs.append(f'known register {label} not at {addr:08X} (found {[hex(a) for a in by_label.get(label, [])]})')
    for label, addrs in by_label.items():
        if len(addrs) > 1:
            errs.append(f'label {label} at {len(addrs)} addresses: {[hex(a) for a in addrs[:4]]}')
    for x in rows:
        if x['bits'] not in (8, 16, 32, 64, 128):
            errs.append(f"{x['label']}: odd width {x['bits']}")
        if x['bits'] in (16, 32) and x['address'] % (x['bits'] // 8) and x['primary']:
            errs.append(f"{x['label']}: {x['bits']}-bit register at unaligned {x['address']:08X}")
    if len(rows) < 2000:
        errs.append(f'only {len(rows)} registers (expected well over 2000)')
    return errs


HEADER = """# RX651 peripheral registers (T23a), generated by tools/sfr_table.py from {src}
# Table 5.1 "List of I/O Registers (Address Order)", PDF pages {pages}. Do not edit by hand: fix the parser and rebuild.
# Applied to FT710_MAIN with tools/ghidra/ApplySfr.java. Columns: see tools/sfr_table.py.
# address\tlabel\tmodule\tsymbol\tbits\taccess\tprimary\toverlap\tsection\tname
"""
COLS = ['address', 'label', 'module', 'symbol', 'bits', 'access', 'primary', 'overlap', 'section', 'name']


def write(rows, out, src, pages):
    with open(out, 'w') as f:
        f.write(HEADER.format(src=src, pages=pages))
        for x in rows:
            f.write('\t'.join(f"{x['address']:08X}" if c == 'address' else str(x[c]) for c in COLS) + '\n')


def read(tsv):
    rows = []
    for line in open(tsv):
        if line.startswith('#') or not line.strip():
            continue
        v = line.rstrip('\n').split('\t')
        x = dict(zip(COLS, v))
        x['address'] = int(x['address'], 16)
        for k in ('bits', 'primary', 'overlap'):
            x[k] = int(x[k])
        rows.append(x)
    return rows


def report(rows, bad, errs):
    mods = len({x['module'] for x in rows})
    print(f"sfr_table: {len(rows)} registers, {sum(x['primary'] for x in rows)} addresses, {mods} modules, "
          f"{sum(x['overlap'] for x in rows)} overlapping, {len(bad)} unparsed rows")
    for b in bad:
        print('  unparsed:', b)
    for e in errs:
        print('  CHECK FAILED:', e)
    return 1 if (errs or bad) else 0


IO_RANGES = [(0x00080000, 0x00100000), (0x007FC000, 0x00800000), (0xFE7F5000, 0xFE7F8000)]


def coverage(decomp, tsv):
    import glob
    rows = read(tsv)
    cover = {}
    for x in rows:
        for o in range(max(1, x['bits'] // 8)):
            cover.setdefault(x['address'] + o, x['label'])
    refs = defaultdict(int)
    for f in glob.glob(f'{decomp}/*.c'):
        for m in re.finditer(r'\b(?:PTR_)?DAT_([0-9a-f]{8})\b', open(f, encoding='utf-8', errors='replace').read()):
            a = int(m.group(1), 16)
            if any(lo <= a < hi for lo, hi in IO_RANGES):
                refs[a] += 1
    hit = sum(n for a, n in refs.items() if a in cover)
    total = sum(refs.values())
    print(f'sfr_table: {total} unnamed I/O references at {len(refs)} addresses in {decomp}; '
          f'{hit} ({100.0 * hit / max(total, 1):.1f} %) fall on a register in {tsv}')
    for a, n in sorted(((a, n) for a, n in refs.items() if a not in cover), key=lambda t: -t[1]):
        print(f'  missing: {a:08X}  {n} references')
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('cmd', choices=['build', 'check', 'coverage', 'text'])
    ap.add_argument('input', nargs='?')
    ap.add_argument('--pdf', default=PDF)
    ap.add_argument('--out', default=TSV)
    ap.add_argument('--tsv', default=TSV)
    ap.add_argument('--first', type=int)
    ap.add_argument('--last', type=int)
    a = ap.parse_args()
    if a.cmd == 'coverage':
        return coverage(a.input or 'decomp/main', a.tsv)
    if a.cmd == 'check':
        rows = read(a.tsv)
        return report(rows, [], check(rows))
    if a.cmd == 'text':
        text, src, pages = open(a.input).read(), a.input, '?'
    else:
        first, last = (a.first, a.last) if a.first and a.last else find_pages(a.pdf)
        text, src, pages = pdf_text(a.pdf, first, last), a.pdf, f'{first}-{last}'
    rows, bad = parse(text)
    have = {r['address'] for r in rows}
    rows += [dict(address=a, module=m, symbol=y, bits=b, access=acc, section='-', name=n)
             for a, m, y, b, acc, n in EXTRA if a not in have]
    rows = finish(rows)
    errs = check(rows)
    rc = report(rows, bad, errs)
    write(rows, a.out, src, pages)
    print(f'sfr_table: wrote {a.out}')
    return rc


if __name__ == '__main__':
    sys.exit(main())
