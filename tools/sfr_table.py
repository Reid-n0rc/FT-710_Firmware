#!/usr/bin/env python3
"""Peripheral-register tables (T23a, T23b): turn the chip vendors' register lists into tools/ghidra/sfr_<chip>.tsv.

Chips (--chip, default rx651):
  rx651   MAIN. Table 5.1 "List of I/O Registers (Address Order)" of the committed RX65N/RX651 hardware manual
          `Manuals/Renesas/r01uh0590ej0240-rx651.pdf` (Rev.2.40, 53 table pages) -> tools/ghidra/sfr_rx651.tsv (T23a).
  rza1h   DISPLAY. Table 58.1 "Register Addresses" (section 58, "List of Registers", 89 pages) of the committed RZ/A1H
          hardware manual `Manuals/Renesas/r01uh0403ej0700-rza1h.pdf` (Rev.7.00) -> tools/ghidra/sfr_rza1h.tsv (T23b).
          That one table lists every module's registers, per channel, so the chapters' "Register Configuration"
          tables are not needed. Module symbols come from RZA_MODULES below.
  rt685   IFDSP. NXP's CMSIS SVD `MIMXRT685S_cm33.xml` (github.com/nxp-mcuxpresso/mcux-soc-svd, pinned in RT_SOURCES)
          plus the DSP device header `MIMXRT685S_dsp.h` (github.com/nxp-mcuxpresso/mcux-sdk) for the HiFi4 view.
          Writes two tables (T23b):
            tools/ghidra/sfr_rt685.tsv        Cortex-M33: every SVD register at its non-secure address (0x4xxxxxxx, the
                                              alias the firmware uses), again at the secure alias (0x5xxxxxxx, module
                                              <P>_S), and the Armv8-M system control space (SCB, NVIC, SysTick; RT_SCS).
            tools/ghidra/sfr_rt685_hifi4.tsv  HiFi4: the peripherals the DSP header lists, at the same 0x4xxxxxxx
                                              addresses (the DSP has no secure alias and no Arm SCS).
          The downloaded files are not committed; their URL, commit and SHA-256 are in RT_SOURCES and the TSV header,
          and the build refuses files with another hash (pass --any-hash to try a newer file, then update RT_SOURCES).
  rt685_hifi4  only for `check` and `coverage` (the second table above; `build --chip rt685` writes it).

Usage:
  python3 -I tools/sfr_table.py build [--chip C] [--pdf PDF] [--svd XML --dsp-header H] [--out TSV] [--first N --last N]
      Find the table pages (unless --first/--last are given), parse, check, write the TSV. Exit 1 if a check fails.
  python3 -I tools/sfr_table.py check [--chip C] [--tsv TSV]
      Re-run the checks on a committed TSV (no PDF or SVD needed).
  python3 -I tools/sfr_table.py coverage [decomp/<image>] [--chip C] [--tsv TSV]
      How many DAT_<address> references in the decompiled C fall on a register in the TSV, before or without Ghidra;
      lists the I/O addresses the TSV lacks (new firmware, or a register for the EXTRA lists). Text only, no Ghidra.
  python3 -I tools/sfr_table.py text <layout.txt> [--chip rx651|rza1h] [--out ...]
      Parse a text file made earlier with `pdftotext -layout` (for debugging the parser).

TSV columns (tab separated, '#' lines are comments; read by tools/ghidra/ApplySfr.java):
  address   8 hex digits, no 0x
  label     MODULE_SYMBOL (e.g. IWDT_IWDTCR, SCIF_SCSMR_2, USART0_FIFOWR): the Ghidra label
  module    module symbol (SYSTEM, ICU, SCI0 / CPG, SCIF, VDC50 / FLEXCOMM0, USART0_S, SCB, ...)
  symbol    register symbol from the manual or SVD
  bits      register width in bits (8, 16, 32, 64, 128; RZ/A1H memory tables such as JCU_JCQTBL0 are wider)
  access    access sizes ("8", "8, 16", ...)
  primary   1 = first register listed at this address (gets the type and the primary label); 0 = alias
            (another mode of the same register, e.g. SMCI0_SMR next to SCI0_SMR, or I2C2_CFG under I2S2_CFG1)
  overlap   1 = another register overlaps these bytes with a different start or size; ApplySfr.java then only labels it
  section   manual section number ('-' for rows that are not from a manual section: EXTRA rows, SVD rows)
  name      register name from the manual (or the SVD description)

To redo after a new manual or SVD revision: run `build` with the new input, review the diff of the TSV (the checks must
pass), commit it, then re-apply it in Ghidra (docs/tasks/T23-readability.md, T23a and T23b).
"""
import argparse
import glob
import hashlib
import re
import subprocess
import sys
from collections import defaultdict

# ---------------------------------------------------------------------------------------------------------------------
# RX651 (MAIN, T23a)

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


def rx_build(a):
    if a.cmd == 'text':
        text, src, pages = open(a.input).read(), a.input, '?'
    else:
        first, last = (a.first, a.last) if a.first and a.last else find_pages(a.pdf)
        text, src, pages = pdf_text(a.pdf, first, last), a.pdf, f'{first}-{last}'
    rows, bad = parse(text)
    have = {r['address'] for r in rows}
    rows += [dict(address=ad, module=m, symbol=y, bits=b, access=acc, section='-', name=n)
             for ad, m, y, b, acc, n in EXTRA if ad not in have]
    return [(a.out, finish(rows), bad, HEADER.format(src=src, pages=pages))]


HEADER = """# RX651 peripheral registers (T23a), generated by tools/sfr_table.py from {src}
# Table 5.1 "List of I/O Registers (Address Order)", PDF pages {pages}. Do not edit by hand: fix the parser and rebuild.
# Applied to FT710_MAIN with tools/ghidra/ApplySfr.java. Columns: see tools/sfr_table.py.
# address\tlabel\tmodule\tsymbol\tbits\taccess\tprimary\toverlap\tsection\tname
"""

# ---------------------------------------------------------------------------------------------------------------------
# RZ/A1H (DISPLAY, T23b): Table 58.1 "Register Addresses"

RZA_PDF = 'Manuals/Renesas/r01uh0403ej0700-rza1h.pdf'
RZA_TSV = 'tools/ghidra/sfr_rza1h.tsv'
RZA_TITLE = re.compile(r'Table (\d+)\.1\s+Register Addresses')

# Module column of Table 58.1 (first line of the wrapped text) -> module symbol and the manual section that describes
# it. The symbols follow Renesas' iodefine.h names where they exist. A module text missing here fails the build.
# Power-down modes (STBCR*, SYSCR*) go under CPG, as in Renesas' cpg_iodefine.h.
RZA_MODULES = {
    'Secondary cache': ('L2C', 4), 'LSI internal bus': ('INB', 5), 'Clock pulse generator': ('CPG', 6),
    'Interrupt controller': ('INTC', 7), 'Bus state controller': ('BSC', 8), 'Direct memory access': ('DMAC', 9),
    'Multi-function timer pulse': ('MTU2', 10), 'OS timer': ('OSTM', 11), 'Watchdog timer': ('WDT', 12),
    'Realtime clock': ('RTC', 13), 'Serial communication': ('SCIF', 14), 'Serial communications': ('SCIM', 15),
    'Renesas serial peripheral': ('RSPI', 16), 'SPI multi I/O bus controller': ('SPIBSC', 17),
    'I2C bus interface': ('RIIC', 18), 'Serial sound interface': ('SSIF', 19), 'Media local bus': ('MLB', 20),
    'CAN interface': ('RSCAN', 21), 'IEBus controller': ('IEB', 22), 'Renesas SPDIF interface': ('SPDIF', 23),
    'CD-ROM decoder': ('ROMDEC', 24), 'LIN interface channel 0': ('LIN0', 25), 'LIN interface channel 1': ('LIN1', 25),
    'Ethernet controller': ('ETHER', 26), 'A/D converter': ('ADC', 27), 'NAND flash memory': ('FLCTL', 28),
    'USB2.0 host/function': ('USB', 29), 'Digital video decoder': ('DVDEC', 30), 'Video display controller 5': ('VDC5', 31),
    'LVDS output interface': ('LVDS', 40), 'Image renderer channel 0': ('IMRLS20', 41),
    'Image renderer channel 1': ('IMRLS21', 41), 'Image renderer for display': ('IMRLSD', 42),
    'Display out comparison unit': ('DISC', 43), 'JPEG codec unit': ('JCU', 45), 'Capture engine unit': ('CEU', 46),
    'Pixel format converter': ('PFV', 47), 'SCUX': ('SCUX', 48), 'Sound generator': ('SNDG', 49),
    'SD host interface': ('SDHI', 50), 'MMC host interface': ('MMC', 51), 'Motor control PWM timer': ('PWM', 52),
    'Ports': ('PORT', 54), 'Power-down modes': ('CPG', 55), 'Debugger interface': ('DBG', 56), 'EthernetAVB': ('AVB', 57),
}
# Modules that Table 58.1 lists once per channel under the same symbols; the generator numbers the instances in table
# order (VDC5 channel 0 at 0xFCFF7400 -> VDC50, channel 1 at 0xFCFF9400 -> VDC51).
RZA_CHANNELLED = {'VDC5', 'PFV', 'DISC'}

# Known registers (address, label), from the module chapters and docs/code/display/*.md.
RZA_KNOWN = [
    (0x3FFFFF80, 'L2C_REG15_POWER_CTRL'),   # peripherals.md: PL310 power control in cpg_early_init
    (0x3FEFA000, 'SPIBSC_CMNCR_0'),         # SPIBSC0 common control (s17)
    (0xFCFE0010, 'CPG_FRQCR'), (0xFCFE0014, 'CPG_FRQCR2'),                     # peripherals.md s1
    (0xFCFE0024, 'CPG_STBCR2'), (0xFCFE0420, 'CPG_STBCR3'), (0xFCFE0444, 'CPG_STBCR12'),
    (0xFCFE0034, 'CPG_STBREQ2'), (0xFCFE0044, 'CPG_STBACK2'), (0xFCFE0408, 'CPG_SYSCR3'),
    (0xE8201000, 'INTC_ICDDCR'), (0xE8201100, 'INTC_ICDISER0'), (0xE8201400, 'INTC_ICDIPR0'),  # gic_init
    (0xE8202000, 'INTC_ICCICR'), (0xFCFEF802, 'INTC_ICR1'), (0xFCFEF804, 'INTC_IRQRR'),
    (0xFCFEC000, 'OSTM_OSTM0CMP'), (0xFCFEC400, 'OSTM_OSTM1CMP'),                # ostm_init
    (0xFCFE0000, 'WDT_WTCSR'), (0xE8007000, 'SCIF_SCSMR_0'), (0xE8009800, 'SCIF_SCSMR_5'),  # MAIN link SCIF5
    (0xE800C800, 'RSPI_SPCR_0'), (0xE800E800, 'RSPI_SPCR_4'),                    # DSP link RSPI4 (spi-links.md)
    (0xFCFE3004, 'PORT_P1'), (0xFCFE3404, 'PORT_PMC1'), (0xFCFE7204, 'PORT_PIPC1'),
    (0xFCFF7400, 'VDC50_INP_UPDATE'), (0xFCFF9400, 'VDC51_INP_UPDATE'),
    (0xE8210010, 'CEU_CAMOR_A'), (0xE8212010, 'CEU_CAMOR_M'),
    (0xE803A000, 'RSCAN_RSCAN0C0CFG'), (0xE803A040, 'RSCAN_RSCAN0C4CFG'),        # "+ m * H'0010" rows
    (0xE8017100, 'JCU_JCQTBL0'),
]

# Misprints in Table 58.1, corrected from the module chapter's "Register Configuration" table (the build reports each
# one it applies; any other address that two registers share fails the check in rza_check).
#   range ends: the PFV output-buffer windows end 32 bytes after their start, like the input-buffer windows (s47); the
#     table prints H'E840505C / H'E840585C, which would span 2 MB.
RZA_ERRATA_END = {0xE840505C: 0xE820505C, 0xE840585C: 0xE820585C}
#   symbol -> start address: SPIBSC channel 1 (Table 17.2: CKDLY_1 H'3FEFB050, SPODLY_1 H'3FEFB068; Table 58.1 prints
#     channel 0's H'3FEFA050 / H'3FEFA068).
RZA_ERRATA_ADDR = {'CKDLY_1': 0x3FEFB050, 'SPODLY_1': 0x3FEFB068}
#   symbol -> index stride: RSCAN0TXQCCm is <RSCAN0_base> + 03A0H + 4 m (Table 21.10 lists TXQCC0..4 at 03A0H..03B0H;
#     Table 58.1 prints "* H'0010", which would run into TXQSTSm and TXQPCTRm).
RZA_ERRATA_STRIDE = {'RSCAN0TXQCCm': 4}
#   (symbol prefix, printed 4 KB block) -> block used: the PTM-A9 CoreSight management registers (CLAIMSET..COMPID3,
#     offsets 0xFA0-0xFFC) are printed in the CA9-PMU block H'FC031000 (where CA9_PMU_CLAIMSET.. already are); the
#     other PTM-A9 registers are in H'FC03C000. Section 56 has no address table to confirm it [inference].
RZA_ERRATA_BLOCK = {('PTM_A9_', 0xFC031000): 0xFC03C000}

RZA_ROW = re.compile(
    r"^(?P<left>.*?\S)\s+(?P<bits>\d+)\s+"
    r"(?:H['’]\s?(?P<addr>[0-9A-F]{4} ?[0-9A-F]{4})(?P<formula>\s*\+[^H]*?(?:H['’]\s?[0-9A-F]+)?)?(?P<to>\s+to)?"
    r"|(?P<plane>Plane A:))"
    r"\s+(?P<acc>\d+(?:\s*\([RW/]+\))?(?:\s*,\s*\d+(?:\s*\([RW/]+\))?)*,?)\s*$")
RZA_ADDR_ONLY = re.compile(r"^\s*H['’]\s?([0-9A-F]{4}) ?([0-9A-F]{4})(?:\s+\d+)?\s*$")
RZA_PLANE = re.compile(r'^\s*(Plane [A-C]|Mirror):\s*$')
RZA_SKIP = re.compile(r"RZ/A1H Group|Table \d+\.1\s|^\s*Number\s*$|Module\s+Register Name|R01UH0403|^\s*\w{3}\. \d+, \d{4}|"
                      r"List of Registers|Register Addresses\s*$")
RZA_FORMULA = re.compile(r"\+\s*([a-z])\s*\*?\s*H['’]\s?([0-9A-F]+)")
RZA_PARAM = re.compile(r'\(\s*([a-z])\s*=\s*(\d+)\s*to\s*(\d+)\s*\)')


def rza_find_pages(pdf):
    """Table 58.1: the pages of the last 20 % of the manual whose text carries the table title."""
    info = subprocess.run(['pdfinfo', pdf], check=True, capture_output=True, text=True).stdout
    n = int(re.search(r'^Pages:\s+(\d+)', info, re.M).group(1))
    first = int(n * 0.8)
    pages = pdf_text(pdf, first, n).split('\f')
    hits = [first + i for i, p in enumerate(pages) if RZA_TITLE.search(p)]
    if not hits:
        sys.exit(f'sfr_table: no "Table N.1 Register Addresses" in {pdf} pages {first}-{n}; pass --first/--last')
    last = hits[0]
    while last + 1 in hits:      # the consecutive run (the revision history names the table again)
        last += 1
    return hits[0], last


def rza_records(text):
    """Rows of Table 58.1 with their continuation lines (wrapped names and symbols, '* H'0010', ranges, planes)."""
    recs, mod = [], None
    for line in text.split('\n'):
        if not line.strip() or RZA_SKIP.search(line):
            continue
        m = RZA_ROW.match(line)
        if m:
            cs = chunks(m.group('left'))
            if cs and cs[0][0] <= 3:
                mod, cs = cs[0][1], cs[1:]
            if len(cs) == 1:       # one space between name and symbol
                words = cs[0][1].rsplit(' ', 1)
                cs = [(cs[0][0], words[0]), (cs[0][0] + len(words[0]) + 1, words[1])] if len(words) == 2 else cs
            recs.append(dict(module=mod, cs=cs, bits=int(m.group('bits')), acc=m.group('acc'),
                             addr=int(m.group('addr').replace(' ', ''), 16) if m.group('addr') else None,
                             formula=(m.group('formula') or '').strip(), to=bool(m.group('to')), end=None,
                             planes=[], tag='A' if m.group('plane') else None, addrcol=m.start('bits') + 4,
                             extra=0))
            continue
        if not recs:
            continue
        r = recs[-1]
        a = RZA_ADDR_ONLY.match(line)
        if a:
            addr = int(a.group(1) + a.group(2), 16)
            if r['tag']:
                r['planes'].append((r['tag'], addr))
                r['tag'] = None
            elif r['to'] and r['end'] is None:
                r['end'] = addr
            else:
                r['extra'] += 1     # MMC CE_CMD_SET lists its upper half again (H'E804C802): same register
            continue
        p = RZA_PLANE.match(line)
        if p:
            r['tag'] = 'M' if p.group(1) == 'Mirror' else p.group(1)[-1]
            continue
        if line.strip() == 'to':
            r['to'] = True
            continue
        symcol = r['cs'][-1][0] if r['cs'] else 999
        for c, txt in chunks(line):
            if c <= 3:
                continue                                    # wrapped module text ("controller", "unit 2")
            if c >= r['addrcol'] - 2 or txt.startswith('*') or txt.startswith("H'"):
                # "* H'0010" completes an "H'E803A000 + m" address; other text there wraps the access size ("32 (W)")
                if r['formula'] and "H'" not in r['formula'] and "H’" not in r['formula']:
                    r['formula'] += ' ' + txt
            elif c >= symcol - 3:
                sym = r['cs'][-1][1]
                if sym.count('(') > sym.count(')') or re.search(r' (and|to)$', sym):
                    r['cs'][-1] = (symcol, sym + ' ' + txt)             # "RSCAN0CFPCTRk (k = 0 to" + "14)"
                elif not txt.startswith('('):                           # (a repeated "(m = 0 to 4)" is dropped)
                    r['cs'][-1] = (symcol, sym + txt)                   # "CPU_CTICS_" + "CTITRIGINSTATUS"
            elif r['cs']:
                r['cs'][0] = (r['cs'][0][0], ' '.join(t for _, t in r['cs'][:-1]) + ' ' + txt)
                r['cs'][1:-1] = []
    return recs


def rza_symbol(s):
    """Ghidra-safe symbol: reg15_power_ctrl -> REG15_POWER_CTRL, 'CPU_TPIU_Formatter and flush status' -> ..._AND_...
    (labels take [A-Za-z0-9_]; the L2C and debug symbols are lower case in the manual)."""
    return re.sub(r'_+', '_', re.sub(r'[^A-Za-z0-9_]', '_', s.strip())).strip('_').upper()


def rza_parse(text):
    rows, bad, inst = [], [], {}
    seen = defaultdict(dict)     # module symbol -> {register symbol: address} of its current instance
    for r in rza_records(text):
        if not r['module'] or len(r['cs']) < 2:
            bad.append(f"{r['addr'] or 0:08X}: no module or symbol: {r['cs']}")
            continue
        long = next((k for k in sorted(RZA_MODULES, key=len, reverse=True) if r['module'].startswith(k)), None)
        if long is None:
            bad.append(f"{r['addr'] or 0:08X}: unknown module {r['module']!r} (add it to RZA_MODULES)")
            continue
        mod, section = RZA_MODULES[long]      # longest match: 'Serial communications' (SCIM) before SCIF
        name = re.sub(r'\s+', ' ', ' '.join(t for _, t in r['cs'][:-1])).strip()
        sym = re.sub(r'\s+', ' ', r['cs'][-1][1]).strip()
        acc = ', '.join(re.findall(r'\d+', r['acc']))
        base = dict(bits=r['bits'], access=acc, section=str(section), name=name)
        start = r['addr'] if r['addr'] is not None else (r['planes'][0][1] if r['planes'] else None)
        start = RZA_ERRATA_ADDR.get(sym, start)
        for (pre, blk), to in RZA_ERRATA_BLOCK.items():
            if sym.startswith(pre) and blk <= start < blk + 0x1000:
                start += to - blk
        if start is None:
            bad.append(f"{mod}: {sym}: no address")
            continue
        key = RZA_PARAM.sub('', sym).strip()
        if mod in RZA_CHANNELLED:
            if key in seen[mod] and seen[mod][key] != start:
                inst[mod] = inst.get(mod, 0) + 1
                seen[mod] = {}
            seen[mod][key] = start
            base['inst'] = inst.get(mod, 0)
        base['module'] = mod
        out = []
        if r['formula']:
            f, p = RZA_FORMULA.search(r['formula']), RZA_PARAM.search(sym) or RZA_PARAM.search(name)
            if not f or not p or f.group(1) != p.group(1):
                bad.append(f"{start:08X}: {sym}: formula {r['formula']!r}")
                continue
            var, stride = f.group(1), int(f.group(2), 16)
            core = RZA_PARAM.sub('', sym).strip()
            stride = RZA_ERRATA_STRIDE.get(core, stride)
            if core.count(var) != 1:
                bad.append(f"{start:08X}: {sym}: index letter {var!r} not once in the symbol")
                continue
            nm = re.sub(r'\s+', ' ', RZA_PARAM.sub('', name)).strip()
            for i in range(int(p.group(2)), int(p.group(3)) + 1):
                out.append(dict(base, address=start + i * stride, symbol=core.replace(var, str(i)),
                                name=re.sub(rf'\b{var}\b', str(i), nm)))
        elif r['planes']:
            out = [dict(base, address=ad, symbol=f'{sym}_{tag}', name=f'{name} (plane {tag})' if tag != 'M'
                        else f'{name} (mirror)') for tag, ad in r['planes']]
        elif r['to']:
            if r['end'] is None:
                bad.append(f"{start:08X}: {sym}: range without end")
                continue
            r['end'] = RZA_ERRATA_END.get(r['end'], r['end'])
            span = r['end'] - start + 1
            if span * 8 == r['bits'] or r['bits'] > 128:
                # A memory table (JCU_JCQTBL0); its width is the span (JCHTBA0 prints 1416 bits over 178 bytes).
                out = [dict(base, address=start, symbol=sym, bits=span * 8)]
            else:
                stride = r['bits'] // 8
                n = (r['end'] - start) // stride + 1
                out = [dict(base, address=start + i * stride, symbol=f'{sym}_{i}') for i in range(n)]   # FIFO window
        else:
            out = [dict(base, address=start, symbol=sym)]
        for x in out:
            x['symbol'] = rza_symbol(x['symbol'])
        rows += out
    for x in rows:
        if x['module'] in inst:
            x['module'] += str(x['inst'])
        x.pop('inst', None)
    return rows, bad


def rza_build(a):
    pdf = a.pdf if a.pdf != PDF else RZA_PDF
    if a.cmd == 'text':
        text, src, pages = open(a.input).read(), a.input, '?'
    else:
        first, last = (a.first, a.last) if a.first and a.last else rza_find_pages(pdf)
        text, src, pages = pdf_text(pdf, first, last), pdf, f'{first}-{last}'
    rows, bad = rza_parse(text)
    out = a.out if a.out != TSV else RZA_TSV
    return [(out, finish(rows), bad, RZA_HEADER.format(src=src, pages=pages))]


RZA_HEADER = """# RZ/A1H peripheral registers (T23b), generated by tools/sfr_table.py --chip rza1h from {src}
# Table 58.1 "Register Addresses" (section 58 "List of Registers"), PDF pages {pages}; section = the module's chapter.
# Do not edit by hand: fix the parser and rebuild. Applied to FT710_DISPLAY with tools/ghidra/ApplySfr.java.
# address\tlabel\tmodule\tsymbol\tbits\taccess\tprimary\toverlap\tsection\tname
"""

# ---------------------------------------------------------------------------------------------------------------------
# i.MX RT685 (IFDSP, T23b): CMSIS SVD + DSP device header

RT_TSV = 'tools/ghidra/sfr_rt685.tsv'
RT_HIFI4_TSV = 'tools/ghidra/sfr_rt685_hifi4.tsv'
RT_SOURCES = {
    'svd': dict(url='https://github.com/nxp-mcuxpresso/mcux-soc-svd/blob/7c1f00bdd6263f0b93466f5e73e5fc55a744b879/'
                    'MIMXRT685S/MIMXRT685S_cm33.xml',
                sha256='751c25d4fcf4986825ff8e3a1d399b43012ccd9fb6035d9e3529ced68d9bff1b'),
    'dsp': dict(url='https://github.com/nxp-mcuxpresso/mcux-sdk/blob/8a289764d763ad06e0c3a05c885644ed98b970af/'
                    'devices/MIMXRT685S/MIMXRT685S_dsp.h',
                sha256='903348aa34ad7e7ea27d4b32530fc341f67aeffc9ee9e2c6879c921a88775439'),
}
RT_SECURE_OFFSET = 0x10000000        # secure alias of the 0x4xxxxxxx peripherals (RT600 UM, memory map; MIMXRT685S_cm33.h)
# FLEXCOMM n is one block with USART/SPI/I2C/I2S views at the same address. These views come first at their address
# (primary label and type) because the firmware uses them [fact: docs/code/ifdsp/m33-platform.md and hifi4.md]:
# FC0 = USART0 (MAIN console), FC1 = SPI1 (DISPLAY link), FC2..FC5 = I2S2..I2S5 (SDR and codec audio).
RT_PREFER = ['USART0', 'SPI1', 'I2S2', 'I2S3', 'I2S4', 'I2S5']
# Armv8-M system control space (Arm v8-M ARM, B3.x "System Control Space"; CMSIS core_cm33.h names), for the addresses
# the SVD's own SCnSCB/NVIC/SCB/MPU/SAU peripherals do not cover (SysTick, FPU, CoreDebug); rows at an address the SVD
# has are dropped. (address, module, symbol, bits, name).
RT_SCS = [
    (0xE000E004, 'SCnSCB', 'ICTR', 32, 'Interrupt Controller Type Register'),
    (0xE000E008, 'SCnSCB', 'ACTLR', 32, 'Auxiliary Control Register'),
    (0xE000E010, 'SysTick', 'CTRL', 32, 'SysTick Control and Status Register'),
    (0xE000E014, 'SysTick', 'LOAD', 32, 'SysTick Reload Value Register'),
    (0xE000E018, 'SysTick', 'VAL', 32, 'SysTick Current Value Register'),
    (0xE000E01C, 'SysTick', 'CALIB', 32, 'SysTick Calibration Value Register'),
    (0xE000EF00, 'NVIC', 'STIR', 32, 'Software Triggered Interrupt Register'),
    (0xE000ED00, 'SCB', 'CPUID', 32, 'CPUID Base Register'),
    (0xE000ED04, 'SCB', 'ICSR', 32, 'Interrupt Control and State Register'),
    (0xE000ED08, 'SCB', 'VTOR', 32, 'Vector Table Offset Register'),
    (0xE000ED0C, 'SCB', 'AIRCR', 32, 'Application Interrupt and Reset Control Register'),
    (0xE000ED10, 'SCB', 'SCR', 32, 'System Control Register'),
    (0xE000ED14, 'SCB', 'CCR', 32, 'Configuration and Control Register'),
    (0xE000ED18, 'SCB', 'SHPR1', 32, 'System Handler Priority Register 1'),
    (0xE000ED1C, 'SCB', 'SHPR2', 32, 'System Handler Priority Register 2'),
    (0xE000ED20, 'SCB', 'SHPR3', 32, 'System Handler Priority Register 3'),
    (0xE000ED24, 'SCB', 'SHCSR', 32, 'System Handler Control and State Register'),
    (0xE000ED28, 'SCB', 'CFSR', 32, 'Configurable Fault Status Register'),
    (0xE000ED2C, 'SCB', 'HFSR', 32, 'HardFault Status Register'),
    (0xE000ED30, 'SCB', 'DFSR', 32, 'Debug Fault Status Register'),
    (0xE000ED34, 'SCB', 'MMFAR', 32, 'MemManage Fault Address Register'),
    (0xE000ED38, 'SCB', 'BFAR', 32, 'BusFault Address Register'),
    (0xE000ED3C, 'SCB', 'AFSR', 32, 'Auxiliary Fault Status Register'),
    (0xE000ED88, 'SCB', 'CPACR', 32, 'Coprocessor Access Control Register'),
    (0xE000ED8C, 'SCB', 'NSACR', 32, 'Non-secure Access Control Register'),
    (0xE000EDF0, 'CoreDebug', 'DHCSR', 32, 'Debug Halting Control and Status Register'),
    (0xE000EDFC, 'CoreDebug', 'DEMCR', 32, 'Debug Exception and Monitor Control Register'),
    (0xE000EF34, 'FPU', 'FPCCR', 32, 'Floating-point Context Control Register'),
    (0xE000EF38, 'FPU', 'FPCAR', 32, 'Floating-point Context Address Register'),
    (0xE000EF3C, 'FPU', 'FPDSCR', 32, 'Floating-point Default Status Control Register'),
]
# Registers the firmware uses that the SVD does not list (address, module, symbol, bits, name); also added at the secure
# alias (module <P>_S). Each name says where it comes from; keep them few and sourced. fsl_power.c: https://github.com/
# nxp-mcuxpresso/mcux-sdk/blob/8a289764d763ad06e0c3a05c885644ed98b970af/devices/MIMXRT685S/drivers/fsl_power.c,
# SHA-256 99f490d627629e283ebc112d23ce7fcb30b402953885bc910f865bcef1f63914 (lines 183-196).
RT_EXTRA = [
    (0x40135020, 'PMC', 'BIASCFG', 32, 'PMC +0x20: body-bias (RBB/FBB) voltage level and RBB pull-down [not in the SVD; '
     'symbol ours. NXP SDK fsl_power.c POWER_SetBiasConfig() writes PMC_REG(0x20) = 0x04040808 if it differs '
     '(mcux-sdk 8a289764)]'),
]
# Not added: DISPLAY 0xE8205580 (read in ostm_time_us, bit 6). The RZ/A1H manual (Rev.7.00) has no register there: it
# is offset 0x580 of the PFV0 window (PFV0 ends at 0xE820508C, PFV1 starts at 0xE8205800; Table 5.5 says only "I/O
# area"). Bit 6 is OSTM0TINT (interrupt ID 134 = ICDISPR4 bit 6 at 0xE8201210), so the code most likely means "OSTM0
# tick pending" [inference]; see docs/code/display/peripherals.md (OSTM).
# Known registers (address, label), from docs/code/ifdsp/*.md (register names there are from the RT600 SDK).
RT_KNOWN = [
    (0x4000200C, 'SYSCTL0_DSPSTALL'), (0x40033014, 'CACHE64_POLSEL_REG0_TOP'), (0x40033800, 'CACHE64_CCR'),
    (0x40106E04, 'USART0_FIFOSTAT'), (0x40106E10, 'USART0_FIFOINTENSET'), (0x40106E14, 'USART0_FIFOINTENCLR'),
    (0x40106E20, 'USART0_FIFOWR'), (0x40106E30, 'USART0_FIFORD'), (0x40022010, 'SYSCTL1_MCLKPINDIR'),
    (0x40004004, 'IOPCTL_PIO0_1'), (0x40108C00, 'I2S2_CFG1'), (0x40107400, 'SPI1_CFG'), (0x40108E00, 'I2S2_FIFOCFG'),
    (0x40106E00, 'USART0_FIFOCFG'), (0x40107E00, 'SPI1_FIFOCFG'), (0x40106FF8, 'FLEXCOMM0_PSELID'),
    (0x5000200C, 'SYSCTL0_S_DSPSTALL'), (0xE000ED08, 'SCB_VTOR'), (0xE000E100, 'NVIC_ISER0'),
]
RT_HIFI4_KNOWN = [k for k in RT_KNOWN if k[0] < 0x50000000]


def sha256(path):
    return hashlib.sha256(open(path, 'rb').read()).hexdigest()


def svd_int(s):
    s = s.strip().lower()
    return int(s, 16) if s.startswith('0x') else int(s, 2) if s.startswith('#') else int(s)


def svd_dims(el):
    """Index strings of a dim array (['0', '1', ...] or the dimIndex list), or [None] when the element is no array."""
    dim = el.findtext('dim')
    if dim is None:
        return [None], 0
    n, inc = svd_int(dim), svd_int(el.findtext('dimIncrement') or '0')
    idx = el.findtext('dimIndex')
    if idx:
        if '-' in idx and ',' not in idx:
            lo, hi = idx.split('-')
            idx = [str(i) for i in range(int(lo), int(hi) + 1)] if lo.isdigit() else \
                [chr(c) for c in range(ord(lo), ord(hi) + 1)]
        else:
            idx = [i.strip() for i in idx.split(',')]
    else:
        idx = [str(i) for i in range(n)]
    return idx[:n], inc


def svd_name(name, i):
    return name if i is None else name.replace('[%s]', i).replace('%s', i)


def svd_desc(text):
    """First sentence of an SVD description, at most 100 characters (the EOL comment in Ghidra)."""
    d = re.sub(r'\s+', ' ', text or '').strip()
    d = re.split(r'(?<=[a-z0-9)])\. ', d)[0].rstrip('.')
    return d if len(d) <= 100 else d[:97].rstrip() + '...'


def svd_registers(el, base, prefix, size, access, out, cluster=''):
    """Walk <register> and <cluster> children of el (offsets relative to base), appending
    (address, symbol, bits, access, description, alternate). Symbols join cluster and register names with '_'
    (CLKCTL1 FLEXCOMM[%s] / FRGCLKSEL -> FLEXCOMM0_FRGCLKSEL); a register named after its cluster drops the repeat
    (GPIO B[%s] / B_[%s] -> B0_5, NXP's GPIO->B[0][5])."""
    for child in el:
        if child.tag not in ('register', 'cluster'):
            continue
        idx, inc = svd_dims(child)
        csize = svd_int(child.findtext('size')) if child.findtext('size') else size
        cacc = child.findtext('access') or access
        off = svd_int(child.findtext('addressOffset') or '0')
        for k, i in enumerate(idx):
            raw = child.findtext('name').strip()
            nm = svd_name(raw, i)
            addr = base + off + k * inc
            if child.tag == 'cluster':
                svd_registers(child, addr, prefix + nm + '_', csize, cacc, out, raw.split('[')[0].replace('%s', ''))
            else:
                if cluster and nm.startswith(cluster + '_') and len(nm) > len(cluster) + 1:
                    nm = nm[len(cluster) + 1:]
                alt = child.findtext('alternateRegister') or child.findtext('alternateGroup')
                out.append((addr, prefix + nm, csize, cacc, svd_desc(child.findtext('description')), alt))


def svd_peripherals(svd):
    import xml.etree.ElementTree as ET
    dev = ET.parse(svd).getroot()
    dsize = svd_int(dev.findtext('size') or '32')
    periphs = {}
    for p in dev.find('peripherals'):
        periphs[p.findtext('name').strip()] = p
    result = []
    for name, p in periphs.items():
        src = p
        if p.find('registers') is None and p.get('derivedFrom'):
            src = periphs[p.get('derivedFrom')]
        base = svd_int(p.findtext('baseAddress'))
        regs = []
        svd_registers(src.find('registers'), base, '', svd_int(src.findtext('size') or str(dsize)), None, regs)
        if regs and base < 0xE0000000 and not any(r[0] == base for r in regs):
            # No register at offset 0 (CLKCTL0, FLEXCOMM14, ...): label the block base, which the SDK drivers pass
            # around as the peripheral pointer (NXP's <P>_BASE). An alias wherever another view has a register there.
            regs.insert(0, (base, 'BASE', 32, None, f'base of the {name} register block (no register at offset 0)', 'base'))
        struct = (p.findtext('headerStructName') or src.findtext('headerStructName') or p.findtext('groupName') or
                  name).strip()
        result.append((name, base, regs, struct))
    return result


def rebase(periph, name, base):
    """An SVD peripheral's registers at another base (a DSP-side instance of the same register block)."""
    return (name, base, [(a - periph[1] + base,) + r[1:] for r in periph[2] for a in [r[0]]], periph[3])


def dsp_header_bases(path):
    """Peripherals of the DSP device header: {name: (base, struct)} from '#define NAME_BASE (0x...u)' and
    '#define NAME ((STRUCT_Type *)NAME_BASE)'."""
    text = open(path, encoding='utf-8', errors='replace').read()
    types = dict(re.findall(r'^#define (\w+)\s+\(\((\w+)_Type \*\)\1_BASE\)', text, re.M))
    return {m.group(1): (int(m.group(2), 16), types.get(m.group(1)))
            for m in re.finditer(r'^#define (\w+)_BASE\s+\(0x([0-9A-Fa-f]+)u\)', text, re.M)}


def rt_rows(periphs, secure):
    rows = []
    prefer = {m: i for i, m in enumerate(RT_PREFER)}
    for name, base, regs, _ in periphs:
        for addr, sym, bits, acc, desc, alt in regs:
            mod = name + '_S' if secure else name
            rows.append(dict(address=addr + (RT_SECURE_OFFSET if secure else 0), module=mod, symbol=sym, bits=bits,
                             access=str(bits), section='-', name=desc or sym, rank=(prefer.get(name, 99), alt is not None)))
    # Rows at one address: the preferred FLEXCOMM view first, then registers before their SVD alternates; finish()
    # sorts by address and keeps this order for ties.
    rows.sort(key=lambda x: x['rank'])
    for x in rows:
        del x['rank']
    return rows


def rt_build(a):
    svd, dsp = a.svd, a.dsp_header
    if not svd or not dsp:
        sys.exit('sfr_table: --chip rt685 needs --svd MIMXRT685S_cm33.xml and --dsp-header MIMXRT685S_dsp.h '
                 f"(download them from {RT_SOURCES['svd']['url']} and {RT_SOURCES['dsp']['url']})")
    hashes = {'svd': sha256(svd), 'dsp': sha256(dsp)}
    for k, h in hashes.items():
        if h != RT_SOURCES[k]['sha256'] and not a.any_hash:
            sys.exit(f"sfr_table: {k} file has SHA-256 {h}, expected {RT_SOURCES[k]['sha256']} "
                     f"({RT_SOURCES[k]['url']}); pass --any-hash to build from it, then update RT_SOURCES")
    periphs = svd_peripherals(svd)
    bad = []
    # HiFi4 view: the peripherals in the DSP header, which must sit at the SVD's addresses.
    dsp_bases = dsp_header_bases(dsp)
    svd_bases = {p[0]: p[1] for p in periphs}
    for n, (b, _) in sorted(dsp_bases.items()):
        if n in svd_bases and svd_bases[n] != b:
            bad.append(f'{n}: DSP header base {b:08X} differs from the SVD base {svd_bases[n]:08X}')
    hifi = [p for p in periphs if p[0] in dsp_bases]
    # DSP-side instances the SVD lacks (MUB, OSTIMER1): the SVD peripheral with the same register struct, rebased.
    by_struct = {}
    for p in periphs:
        by_struct.setdefault(p[3], p)
    cloned = []
    for n, (b, struct) in sorted(dsp_bases.items()):
        if n not in svd_bases:
            if struct in by_struct:
                hifi.append(rebase(by_struct[struct], n, b))
                cloned.append(f'{n} (as {by_struct[struct][0]}, {struct}_Type)')
            else:
                bad.append(f'{n}: in the DSP header ({struct}_Type at {b:08X}) but no SVD peripheral has that struct')
    ns = rt_rows(periphs, False)
    have = {x['address'] for x in ns}
    m33 = ns + rt_rows([p for p in periphs if p[1] < 0x50000000], True) + [
        dict(address=ad, module=m, symbol=s, bits=b, access=str(b), section='-',
             name=n + ' [Armv8-M system control space; not in the SVD]') for ad, m, s, b, n in RT_SCS if ad not in have]
    m33 += [dict(address=ad + off, module=m + sfx, symbol=y, bits=b, access=str(b), section='-', name=n)
            for ad, m, y, b, n in RT_EXTRA for off, sfx in ((0, ''), (RT_SECURE_OFFSET, '_S')) if ad not in have]
    only_m33 = sorted(set(svd_bases) - set(dsp_bases))
    only_dsp = cloned
    src = (f"# Sources: {RT_SOURCES['svd']['url']}\n#   SHA-256 {hashes['svd']}\n"
           f"# DSP view: {RT_SOURCES['dsp']['url']}\n#   SHA-256 {hashes['dsp']}\n")
    note_m33 = (f'# Cortex-M33 view: {len(periphs)} SVD peripherals at their non-secure addresses (0x4xxxxxxx, used by the '
                f'firmware) and again at the\n# secure alias (+0x10000000, module <P>_S), plus the Armv8-M system control '
                f'space (SCB/NVIC/SysTick/MPU/SAU/FPU).\n')
    note_dsp = (f'# HiFi4 view: the {len(hifi)} peripherals the DSP device header lists, at the same non-secure '
                f'addresses. Not in the DSP header\n# (M33 only): {", ".join(only_m33)}.'
                + (f'\n# DSP-side blocks the SVD lacks, laid out like the M33 block of the same struct: {", ".join(only_dsp)}.'
                   if only_dsp else '') + '\n')
    out = a.out if a.out != TSV else RT_TSV
    return [(out, finish(m33), bad, RT_HEADER.format(view='Cortex-M33', src=src, note=note_m33)),
            (RT_HIFI4_TSV, finish(rt_rows(hifi, False)), [], RT_HEADER.format(view='HiFi4 DSP', src=src, note=note_dsp))]


RT_HEADER = """# i.MX RT685 peripheral registers, {view} view (T23b), generated by tools/sfr_table.py --chip rt685 from NXP's
# CMSIS SVD (register = SVD register; module = SVD peripheral; clusters and dim arrays expanded). Do not edit by hand.
{src}{note}# Applied to FT710_IFDSP with tools/ghidra/ApplySfr.java. Columns: see tools/sfr_table.py.
# address\tlabel\tmodule\tsymbol\tbits\taccess\tprimary\toverlap\tsection\tname
"""

# ---------------------------------------------------------------------------------------------------------------------
# Common: flags, checks, TSV I/O, coverage

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


def check(rows, known=KNOWN, min_rows=2000):
    errs = []
    by_label = defaultdict(list)
    for x in rows:
        by_label[x['label']].append(x['address'])
    for addr, label in known:
        if addr not in by_label.get(label, []):
            errs.append(f'known register {label} not at {addr:08X} (found {[hex(a) for a in by_label.get(label, [])]})')
    for label, addrs in by_label.items():
        if len(addrs) > 1:
            errs.append(f'label {label} at {len(addrs)} addresses: {[hex(a) for a in addrs[:4]]}')
        if not re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', label):
            errs.append(f'label {label!r} is not a valid Ghidra/C name')
    for x in rows:
        # Memory tables wider than 128 bits (RZ/A1H JCU quantisation tables) are byte arrays.
        if x['bits'] not in (8, 16, 32, 64, 128) and not (x['bits'] > 128 and x['bits'] % 8 == 0):
            errs.append(f"{x['label']}: odd width {x['bits']}")
        if x['bits'] in (16, 32) and x['address'] % (x['bits'] // 8) and x['primary']:
            errs.append(f"{x['label']}: {x['bits']}-bit register at unaligned {x['address']:08X}")
    if len(rows) < min_rows:
        errs.append(f'only {len(rows)} registers (expected well over {min_rows})')
    return errs


COLS = ['address', 'label', 'module', 'symbol', 'bits', 'access', 'primary', 'overlap', 'section', 'name']


def write(rows, out, header):
    with open(out, 'w') as f:
        f.write(header)
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


def report(rows, bad, errs, out=''):
    mods = len({x['module'] for x in rows})
    print(f"sfr_table: {out + ': ' if out else ''}{len(rows)} registers, {sum(x['primary'] for x in rows)} addresses, "
          f"{mods} modules, {sum(x['overlap'] for x in rows)} overlapping, {len(bad)} unparsed rows")
    for b in bad:
        print('  unparsed:', b)
    for e in errs:
        print('  CHECK FAILED:', e)
    return 1 if (errs or bad) else 0


IO_RANGES = [(0x00080000, 0x00100000), (0x007FC000, 0x00800000), (0xFE7F5000, 0xFE7F8000)]
# The I/O blocks that tools/ghidra/DisplaySetup.java, IfdspM33Setup.java and IfdspHifi4Setup.java map (volatile).
RZA_RANGES = [(0x3FE00000, 0x40000000), (0xE8000000, 0xE8300000), (0xFCFE0000, 0xFD000000)]
RT_RANGES = [(0x40000000, 0x40160000), (0x50000000, 0x50160000), (0xE0000000, 0xE0100000)]
RT_HIFI4_RANGES = [(0x40000000, 0x40160000)]

CHIPS = {
    'rx651': dict(tsv=TSV, ranges=IO_RANGES, decomp='decomp/main', known=KNOWN, min_rows=2000, build=rx_build),
    'rza1h': dict(tsv=RZA_TSV, ranges=RZA_RANGES, decomp='decomp/display', known=RZA_KNOWN, min_rows=5000,
                  build=rza_build),
    'rt685': dict(tsv=RT_TSV, ranges=RT_RANGES, decomp='decomp/ifdsp/m33', known=RT_KNOWN, min_rows=5000,
                  build=rt_build),
    'rt685_hifi4': dict(tsv=RT_HIFI4_TSV, ranges=RT_HIFI4_RANGES, decomp='decomp/ifdsp/hifi4', known=RT_HIFI4_KNOWN,
                        min_rows=2000, build=None),
}


def coverage(decomp, tsv, ranges):
    rows = read(tsv)
    cover = {}
    for x in rows:
        for o in range(max(1, x['bits'] // 8)):
            cover.setdefault(x['address'] + o, x['label'])
    refs = defaultdict(int)
    for f in glob.glob(f'{decomp}/*.c'):
        for m in re.finditer(r'\b(?:PTR_)?DAT_([0-9a-f]{8})\b', open(f, encoding='utf-8', errors='replace').read()):
            a = int(m.group(1), 16)
            if any(lo <= a < hi for lo, hi in ranges):
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
    ap.add_argument('--chip', choices=sorted(CHIPS), default='rx651')
    ap.add_argument('--pdf', default=PDF)
    ap.add_argument('--svd')
    ap.add_argument('--dsp-header')
    ap.add_argument('--any-hash', action='store_true')
    ap.add_argument('--out', default=TSV)
    ap.add_argument('--tsv')
    ap.add_argument('--first', type=int)
    ap.add_argument('--last', type=int)
    a = ap.parse_args()
    chip = CHIPS[a.chip]
    tsv = a.tsv or chip['tsv']
    if a.cmd == 'coverage':
        return coverage(a.input or chip['decomp'], tsv, chip['ranges'])
    if a.cmd == 'check':
        rows = read(tsv)
        return report(rows, [], check(rows, chip['known'], chip['min_rows']))
    if not chip['build']:
        sys.exit(f'sfr_table: {a.chip} is built by --chip rt685')
    rc = 0
    for out, rows, bad, header in chip['build'](a):
        c = CHIPS['rt685_hifi4'] if out == RT_HIFI4_TSV else chip
        rc |= report(rows, bad, check(rows, c['known'], c['min_rows']), out)
        write(rows, out, header)
        print(f'sfr_table: wrote {out}')
    return rc


if __name__ == '__main__':
    sys.exit(main())
