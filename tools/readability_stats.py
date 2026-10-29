#!/usr/bin/env python3
"""How much of the firmware is decompiled and understood (T23): progress figures from the committed decomp/ export.

Reads only committed files, so anyone can re-run it after a re-export (tools/bootstrap.sh --only export runs it):
  decomp/<image>/functions.tsv   entry, name, size, callers, file (tools/ghidra/ExportDecomp.java)
  decomp/<image>/quality.tsv     decompile failures and warnings (ExportDecomp.java)
  decomp/<image>/*.c             call sites and register references
  docs/code/<dir>/*.md           which function names the subsystem pages mention
  tools/ghidra/sfr_<chip>.tsv    peripheral-register labels (tools/sfr_table.py), for the "registers named" column

Usage:
  python3 -I tools/readability_stats.py            print the table
  python3 -I tools/readability_stats.py readme     rewrite the block between <!-- progress:begin --> and
                                                   <!-- progress:end --> in README.md (site/build.py and
                                                   tools/guide_to_wiki.py copy that block to the website and the wiki)
  python3 -I tools/readability_stats.py check      exit 1 if the README block is out of date
  python3 -I tools/readability_stats.py tsv        the raw numbers, one row per image
  published_block(link_base) is imported by site/build.py and tools/guide_to_wiki.py.

Definitions (also printed under the table):
  Decompiled   share of code bytes in functions that decompile without a failure.
  Named        share of code bytes in functions with a real name (not FUN_/thunk_FUN_). The headline "understood" figure.
  Documented   share of code bytes in named functions whose name appears on the image's docs/code/ pages.
  Calls named  share of call sites in the decompiled C whose callee has a real name.
  Registers    share of peripheral-register references printed with a register name instead of DAT_<address>
               ("not mapped yet" until a register table exists for that chip; T23a MAIN, T23b DISPLAY and IFDSP).
"""
import glob
import os
import re
import sys

BEGIN, END = '<!-- progress:begin -->', '<!-- progress:end -->'
README = 'README.md'

# image dir under decomp/, label, docs/code/ dir, register table and the address ranges it covers (None = no table yet)
IMAGES = [
    ('main', 'MAIN (RX651)', 'main', 'tools/ghidra/sfr_rx651.tsv', [(0x00080000, 0x00100000), (0x007FC000, 0x00800000)]),
    ('display', 'DISPLAY (RZ/A1H)', 'display', 'tools/ghidra/sfr_rza1h.tsv',
     [(0x3FE00000, 0x40000000), (0xE8000000, 0xE8300000), (0xFCFE0000, 0xFD000000)]),
    ('ifdsp/m33', 'IFDSP M33 (RT685)', 'ifdsp', 'tools/ghidra/sfr_rt685.tsv',
     [(0x40000000, 0x40160000), (0x50000000, 0x50160000), (0xE0000000, 0xE0100000)]),
    ('ifdsp/hifi4', 'IFDSP HiFi4 (RT685)', 'ifdsp', 'tools/ghidra/sfr_rt685_hifi4.tsv', [(0x40000000, 0x40160000)]),
]
DEFAULT_NAME = re.compile(r'^(thunk_)?FUN_[0-9a-f]+$')
CALL = re.compile(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\(')
IDENT = re.compile(r'\b[A-Za-z_][A-Za-z0-9_]*\b')
DAT = re.compile(r'\b(?:PTR_)?DAT_([0-9a-f]{8})\b')


def read_tsv(path):
    with open(path, encoding='utf-8') as f:
        rows = [ln.rstrip('\n').split('\t') for ln in f if ln.strip() and not ln.startswith('#')]
    return rows[0], rows[1:]


def quality(path):
    if not os.path.exists(path):
        return {}
    _, rows = read_tsv(path)
    return {r[0]: int(r[1]) for r in rows if len(r) > 1 and r[1].lstrip('-').isdigit()}


def failed_functions(cfiles):
    """Names of functions whose body says the decompile failed (ExportDecomp writes the error into the body)."""
    bad = set()
    for f in cfiles:
        name = None
        for ln in open(f, encoding='utf-8', errors='replace'):
            m = re.match(r'^// ===== (\S+) @', ln)
            if m:
                name = m.group(1)
            elif name and 'decompile failed' in ln.lower():
                bad.add(name)
    return bad


def doc_words(d):
    words = set()
    for f in glob.glob(f'docs/code/{d}/*.md') + ['docs/code/system.md']:
        words |= set(re.findall(r'[A-Za-z_][A-Za-z0-9_]*', open(f, encoding='utf-8').read()))
    return words


def sfr_labels(path):
    if not path or not os.path.exists(path):
        return None
    with open(path, encoding='utf-8') as f:
        return {ln.split('\t')[1] for ln in f if ln.strip() and not ln.startswith('#')}


def image_stats(d, label, docdir, sfr, ranges):
    base = f'decomp/{d}'
    hdr, rows = read_tsv(f'{base}/functions.tsv')
    col = {h: i for i, h in enumerate(hdr)}
    funcs = [(r[col['name']], int(r[col['size']])) for r in rows]
    names = {n for n, _ in funcs}
    real = {n for n in names if not DEFAULT_NAME.match(n)}
    cfiles = sorted(glob.glob(f'{base}/*.c'))
    failed = failed_functions(cfiles)
    words = doc_words(docdir)
    total = sum(s for _, s in funcs) or 1
    s = {
        'image': label,
        'functions': len(funcs),
        'bytes': total,
        'named_functions': len(real),
        'decompiled_bytes': sum(sz for n, sz in funcs if n not in failed),
        'named_bytes': sum(sz for n, sz in funcs if n in real),
        'documented_bytes': sum(sz for n, sz in funcs if n in real and n in words),
        'calls': 0, 'calls_named': 0, 'reg_refs': None, 'reg_named': None,
        'warnings_functions': quality(f'{base}/quality.tsv').get('functions_with_warnings', 0),
    }
    labels = sfr_labels(sfr)
    if labels is not None:
        s['reg_refs'] = s['reg_named'] = 0
    for f in cfiles:
        text = open(f, encoding='utf-8', errors='replace').read()
        body = re.sub(r'^// =====.*$', '', text, flags=re.M)
        for m in CALL.finditer(body):
            if m.group(1) in names:
                s['calls'] += 1
                s['calls_named'] += m.group(1) in real
        if labels is not None:
            unnamed = sum(1 for m in DAT.finditer(body) if any(lo <= int(m.group(1), 16) < hi for lo, hi in ranges))
            named = sum(1 for w in IDENT.findall(body) if w in labels)
            s['reg_refs'] += unnamed + named
            s['reg_named'] += named
    return s


def pct(a, b):
    return '—' if not b else f'{100.0 * a / b:.1f} %'


def table(stats):
    tot = {k: sum(x[k] for x in stats) for k in ('functions', 'bytes', 'named_functions', 'decompiled_bytes', 'named_bytes',
                                                  'documented_bytes', 'calls', 'calls_named')}
    regs = [x for x in stats if x['reg_refs'] is not None]
    out = [
        f"**Understood: {pct(tot['named_bytes'], tot['bytes'])} of the code** (bytes in named functions), "
        f"**{pct(tot['documented_bytes'], tot['bytes'])} documented**, "
        f"**{pct(tot['decompiled_bytes'], tot['bytes'])} decompiled**, across the three CPU images. "
        'The SDR image is an FPGA bitstream: its netlist is fully recovered (see [docs/code/sdr](docs/code/sdr/README.md)).',
        '',
        '| Image | Functions | Code | Decompiled | Named | Documented | Calls named | Registers named |',
        '|---|---:|---:|---:|---:|---:|---:|---:|',
    ]
    for x in stats + [dict(tot, image='**All CPU images**', reg_refs=None, reg_named=None)]:
        reg = 'not mapped yet' if x['reg_refs'] is None else pct(x['reg_named'], x['reg_refs'])
        if x['image'].startswith('**'):
            part = '' if len(regs) == len(stats) else ' (' + ', '.join(r['image'].split(' (')[0] for r in regs) + ')'
            reg = pct(sum(r['reg_named'] for r in regs), sum(r['reg_refs'] for r in regs)) + part if regs else '—'
        out.append(f"| {x['image']} | {x['named_functions']:,} / {x['functions']:,} | {x['bytes'] / 1024:,.0f} KB | "
                   f"{pct(x['decompiled_bytes'], x['bytes'])} | {pct(x['named_bytes'], x['bytes'])} | "
                   f"{pct(x['documented_bytes'], x['bytes'])} | {pct(x['calls_named'], x['calls'])} | {reg} |")
    out += [
        '',
        '*Functions* = named / total. Percentages are of code bytes, except *Calls named* (call sites) and *Registers named* '
        '(peripheral-register references). *Decompiled* = in functions Ghidra decompiles without a failure; *Named* = in '
        'functions with a real name instead of `FUN_<address>`; *Documented* = in named functions that the '
        '`docs/code/` pages mention. Generated by `tools/readability_stats.py` from the committed `decomp/` export; '
        'the plan to raise these numbers is [T23](docs/tasks/T23-readability.md).',
    ]
    return '\n'.join(out)


def block(stats):
    return f'{BEGIN}\n{table(stats)}\n{END}'


def replace_block(text, new):
    if BEGIN in text and END in text:
        return text[:text.index(BEGIN)] + new + text[text.index(END) + len(END):]
    return text.rstrip('\n') + '\n\n' + new + '\n'


def published_block(link_base, readme=README):
    """The README progress block as Markdown with repo-relative links made absolute (for the website and the wiki)."""
    text = open(readme, encoding='utf-8').read()
    if BEGIN not in text or END not in text:
        return ''
    md = text[text.index(BEGIN) + len(BEGIN):text.index(END)].strip()
    return re.sub(r'\]\((?![a-z]+:|#)([^)\s]+)\)', lambda m: f']({link_base}{m.group(1)})', md)


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else 'print'
    stats = [image_stats(*img) for img in IMAGES]
    if cmd == 'tsv':
        keys = list(stats[0])
        print('\t'.join(keys))
        for x in stats:
            print('\t'.join(str(x[k]) for k in keys))
        return 0
    if cmd == 'print':
        print(table(stats))
        return 0
    text = open(README, encoding='utf-8').read()
    new = replace_block(text, block(stats))
    if cmd == 'check':
        if new != text:
            print('readability_stats: README.md progress block is out of date; run python3 -I tools/readability_stats.py readme')
            return 1
        print('readability_stats: README.md progress block is current')
        return 0
    if cmd == 'readme':
        if new != text:
            open(README, 'w', encoding='utf-8').write(new)
        print('readability_stats: README.md progress block ' + ('updated' if new != text else 'unchanged'))
        return 0
    sys.exit(__doc__)


if __name__ == '__main__':
    sys.exit(main())
