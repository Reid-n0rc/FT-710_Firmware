#!/usr/bin/env python3
"""Readable view of the decompiled code, grouped by subsystem (T23g).

Generates decomp/<image>/readable/<subsystem>.c and decomp/<image>/readable/README.md from committed files only:
  decomp/<image>/*.c            the Ghidra export, split into functions at the `// ===== name @ addr (N bytes)` markers
  decomp/<image>/functions.tsv  entry, name, size, callers, file (tools/ghidra/ExportDecomp.java)
  docs/code/<dir>/*.md          the subsystem pages; their function tables give the subsystem, the inferred name,
                                the purpose and the [fact]/[inference]/[guess] tag of each function

Usage:
  python3 -I tools/readable_view.py [build] [image ...]   (re)write decomp/<image>/readable/ (default: all images)
  python3 -I tools/readable_view.py check [image ...]     regenerate into a temp dir and diff against the committed
                                                          readable/; exit 1 if it is stale
tools/bootstrap.sh --only export runs `build` after a re-export into the repo's decomp/; `verify` runs `check`.

Assignment rules (deterministic):
  - A function table is any Markdown table on a docs/code/<dir>/ page whose header has an address column
    (`Address`, `Entry`, `ISR (entry)`) and/or a name column (`Ghidra name`, `Name`, `Helper`). Tables with a
    `Size` or `Type` column are data tables and are skipped.
  - Hex numbers in the address column are matched against the image's function entries. A row whose address
    column holds an address that is not a function of this image is ignored (it is data, or another image).
  - Rows with no address are matched by name: the backticked identifiers in the name / inferred-name columns
    against the function's current Ghidra name.
  - Pages are searched in name order with README.md last. A function goes to the first page that lists its
    address; if no page lists the address, to the first page that lists its name. Further pages are noted in
    the header comment ("also on").
  - Everything else goes to unassigned.c, in sections by the export file it came from.
  - Function bodies are copied byte for byte from the export (marker line included); only the header comment
    above each marker is added. README.md of a page becomes overview.c.
Output is a pure function of the inputs: no timestamps, sorted everywhere.
"""
import difflib
import os
import re
import shutil
import sys
import tempfile
import textwrap

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMAGES = {  # image dir under decomp/ -> docs/code/ dir
    'main': 'main',
    'display': 'display',
    'ifdsp/m33': 'ifdsp',
    'ifdsp/hifi4': 'ifdsp',
}
MARKER = re.compile(r'^// ===== (\S+) @ ([0-9a-fA-F]+) \((\d+) bytes\)', re.M)
HEX = re.compile(r'0x([0-9A-Fa-f]{4,8})\b')
TICK = re.compile(r'`([A-Za-z_][A-Za-z0-9_]*)')
TAG = re.compile(r'\[(fact|inference|guess)\b', re.I)
WORD_TAG = re.compile(r'\b(fact|inference|guess)\b', re.I)
LINK = re.compile(r'\[([^\]]*)\]\([^)]*\)')
IDENT = re.compile(r'^[A-Za-z_][A-Za-z0-9_]*$')
RANGE = re.compile(r'0x([0-9A-Fa-f]{4,8})\s*(?:\.\.|–|-)\s*0x([0-9A-Fa-f]{4,8})')
MAX_RANGE = 0x400  # a range in a function table covers every entry in it (a row of small helpers); longer = a region

ADDR_COLS = ('address', 'entry', 'isr (entry)')
NAME_COLS = ('ghidra name', 'name', 'helper')
INFER_PREFIX = ('inferred', 'proposed')
SKIP_COLS = ('#', 'step')
DATA_COLS = ('size', 'type')


def clean(text):
    """Markdown cell -> plain text for a C comment."""
    text = LINK.sub(r'\1', text)
    text = text.replace('**', '').replace('<br>', ' ').replace('\\|', '|')
    text = re.sub(r'\s+', ' ', text).strip()
    return text.replace('*/', '* /').replace('/*', '/ *')


def split_row(line):
    line = line.strip()
    if line.startswith('|'):
        line = line[1:]
    if line.endswith('|') and not line.endswith('\\|'):
        line = line[:-1]
    return [c.strip() for c in re.split(r'(?<!\\)\|', line)]


def parse_tables(path):
    """Yield (header, [rows]) for each Markdown table in the file."""
    with open(path, encoding='utf-8') as f:
        lines = f.read().split('\n')
    i = 0
    while i < len(lines):
        if lines[i].lstrip().startswith('|') and i + 1 < len(lines) and re.match(r'^\s*\|[\s:|-]+\|?\s*$', lines[i + 1]) \
                and '-' in lines[i + 1]:
            header = split_row(lines[i])
            rows = []
            i += 2
            while i < len(lines) and lines[i].lstrip().startswith('|'):
                rows.append(split_row(lines[i]))
                i += 1
            yield header, rows
        else:
            i += 1


def page_entries(path):
    """Function rows of one page: list of dicts {addrs, names, label_name, infer (label, text), extra, tags}."""
    out = []
    for header, rows in parse_tables(path):
        low = [h.lower().strip() for h in header]
        if any(h in DATA_COLS for h in low):
            continue
        acol = next((k for k, h in enumerate(low) if h in ADDR_COLS), None)
        ncol = next((k for k, h in enumerate(low) if h in NAME_COLS), None)
        if acol is None and ncol is None:
            continue
        icol = next((k for k, h in enumerate(low) if h.startswith(INFER_PREFIX) and k not in (acol, ncol)), None)
        tcol = next((k for k, h in enumerate(low) if h == 'tag'), None)
        rest = [k for k in range(len(header)) if k not in (acol, ncol, icol, tcol) and low[k] not in SKIP_COLS]
        for row in rows:
            row = row + [''] * (len(header) - len(row))
            acell = row[acol] if acol is not None else ''
            ncell = row[ncol] if ncol is not None else ''
            addrs = [int(m, 16) for m in HEX.findall(acell)]
            rng = RANGE.search(acell)
            if rng and ncol is not None:
                lo, hi = int(rng.group(1), 16), int(rng.group(2), 16)
                if 0 < hi - lo <= MAX_RANGE:
                    addrs = [('range', lo, hi)]
            names = TICK.findall(ncell)
            if not names and IDENT.match(ncell.strip('*_ ')):
                names = [ncell.strip('*_ ')]
            if acol == ncol and acol is not None:
                names = TICK.findall(acell)
            inames = TICK.findall(row[icol]) if icol is not None else []
            tags = []
            for k, cell in enumerate(row):
                for t in TAG.findall(cell):
                    t = t.lower()
                    if t not in tags:
                        tags.append(t)
            if tcol is not None:
                for t in WORD_TAG.findall(row[tcol]):
                    t = t.lower()
                    if t not in tags:
                        tags.append(t)
            extra = [(header[k], clean(row[k])) for k in rest if clean(row[k])]
            infer = (header[icol], clean(row[icol])) if icol is not None and clean(row[icol]) else None
            out.append({'addrs': addrs, 'names': names, 'inames': inames, 'infer': infer, 'extra': extra,
                        'tags': tags})
    return out


def load_export(img_dir):
    """Functions of one export: dict addr -> {name, size, callers, file, text}, plus the file order."""
    meta = {}
    with open(os.path.join(img_dir, 'functions.tsv'), encoding='utf-8') as f:
        head = f.readline().rstrip('\n').split('\t')
        for line in f:
            r = dict(zip(head, line.rstrip('\n').split('\t')))
            meta[int(r['entry'], 16)] = r
    funcs = {}
    files = sorted(n for n in os.listdir(img_dir) if n.endswith('.c'))
    for fn in files:
        with open(os.path.join(img_dir, fn), encoding='utf-8', newline='') as f:
            text = f.read()
        marks = list(MARKER.finditer(text))
        rebuilt = text[:marks[0].start()] if marks else text
        for j, m in enumerate(marks):
            end = marks[j + 1].start() if j + 1 < len(marks) else len(text)
            addr = int(m.group(2), 16)
            r = meta.get(addr, {})
            chunk = text[m.start():end]
            rebuilt += chunk
            if addr in funcs:
                raise SystemExit(f'{fn}: function {addr:08x} exported twice')
            funcs[addr] = {'name': r.get('name', m.group(1)), 'size': int(m.group(3)),
                           'callers': r.get('callers', '?'), 'file': fn, 'text': chunk, 'hex': m.group(2)}
        assert rebuilt == text, fn
    return funcs, files


def assign(funcs, doc_dir):
    """addr -> list of (page, entry) in page order; the first is the subsystem."""
    pages = sorted((p for p in os.listdir(doc_dir) if p.endswith('.md')), key=lambda p: (p == 'README.md', p))
    by_addr, by_name = {}, {}
    for page in pages:
        for e in page_entries(os.path.join(doc_dir, page)):
            if e['addrs'] and isinstance(e['addrs'][0], tuple):
                _, lo, hi = e['addrs'][0]
                e = dict(e, addrs=[a for a in sorted(funcs) if lo <= a <= hi], ranged=(lo, hi))
                if not e['addrs']:
                    continue
            hits = [a for a in e['addrs'] if a in funcs]
            if e['addrs']:
                for a in hits:
                    by_addr.setdefault(a, [])
                    if page not in [p for p, _ in by_addr[a]]:
                        by_addr[a].append((page, dict(e, exact=len(e['addrs']) == len(e['names']),
                                                      pos=e['addrs'].index(a))))
            else:
                for n in e['names'] + e['inames']:
                    by_name.setdefault(n, [])
                    if page not in [p for p, _ in by_name[n]]:
                        by_name[n].append((page, dict(e, exact=False, pos=None)))
    result = {}
    for a, f in funcs.items():
        lst = list(by_addr.get(a, []))
        for p, e in by_name.get(f['name'], []):
            if p not in [q for q, _ in lst]:
                lst.append((p, e))
        if lst:
            result[a] = lst
    return result, pages


def wrap(label, text, width=116):
    lines = textwrap.wrap(f'{label}: {text}', width=width - 3, subsequent_indent='    ',
                          break_long_words=False, break_on_hyphens=False)
    return [' * ' + l for l in lines]


def header(f, hits, link_base):
    if not hits:  # one line: the marker below already gives name, address and size
        return f'/* -- {f["name"]}: {f["callers"]} callers, export file {f["file"]}; not on a subsystem page */\n'
    out = ['/* ' + '-' * 77, f' * {f["name"]} @ {f["hex"]}  ({f["size"]} bytes, {f["callers"]} callers, '
           f'export file {f["file"]})']
    page, e = hits[0]
    if e['exact'] and e['pos'] is not None and e['names'][e['pos']] != f['name']:
        out += wrap('Name on the doc page', e['names'][e['pos']])
    inames, pos = e['inames'], e['pos']
    if len(inames) > 1 and f['name'] in inames:
        pass
    elif len(inames) > 1 and pos is not None and len(inames) == len(e['addrs']) and not e.get('ranged'):
        if inames[pos] != f['name']:
            out += wrap(e['infer'][0], f'`{inames[pos]}`')
    elif e['infer'] and e['infer'][1].strip('`*_ ') != f['name']:
        out += wrap(e['infer'][0], e['infer'][1])
    if e.get('ranged'):
        out.append(f' * (The page describes the range 0x{e["ranged"][0]:X}..0x{e["ranged"][1]:X} in one row.)')
    if len(e['extra']) == 1:
        out += wrap('Purpose', e['extra'][0][1])
    else:
        for lab, txt in e['extra']:
            out += wrap(lab, txt)
    tags = ' '.join(f'[{t}]' for t in e['tags']) or 'none in the table row'
    out.append(f' * Tag: {tags}')
    out.append(f' * Doc: {link_base}/{page}')
    if len(hits) > 1:
        out += wrap('Also on', ', '.join(p for p, _ in hits[1:]))
    out.append(' */')
    return '\n'.join(out) + '\n'


def generate(image, out_dir, repo=REPO):
    img_dir = os.path.join(repo, 'decomp', image)
    doc_rel = IMAGES[image]
    doc_dir = os.path.join(repo, 'docs', 'code', doc_rel)
    funcs, files = load_export(img_dir)
    hits, pages = assign(funcs, doc_dir)
    depth = image.count('/') + 2  # readable/ -> decomp/<image>/ -> decomp/ -> repo
    link_base = '/'.join(['..'] * (depth + 1)) + f'/docs/code/{doc_rel}'
    groups = {}
    for a in sorted(funcs):
        key = hits[a][0][0] if a in hits else None
        groups.setdefault(key, []).append(a)
    if os.path.isdir(out_dir):
        shutil.rmtree(out_dir)
    os.makedirs(out_dir)
    gen = (f'// GENERATED by tools/readable_view.py from decomp/{image}/*.c, functions.tsv and '
           f'docs/code/{doc_rel}/*.md.\n// Do not edit: rerun `python3 -I tools/readable_view.py build {image}`. '
           f'Function bodies are byte-identical to the export.\n')
    index = []
    for page in pages:
        if page not in groups:
            continue
        stem = 'overview' if page == 'README.md' else page[:-3]
        addrs = groups[page]
        body = [gen, f'// Subsystem page: {link_base}/{page}\n// {len(addrs)} functions, address order.\n\n']
        for a in addrs:
            body.append(header(funcs[a], hits[a], link_base))
            body.append(funcs[a]['text'])
        with open(os.path.join(out_dir, stem + '.c'), 'w', encoding='utf-8', newline='') as f:
            f.write(''.join(body))
        index.append((stem + '.c', f'[{page}]({link_base}/{page})', len(addrs), sum(funcs[a]['size'] for a in addrs)))
    un = groups.get(None, [])
    if un:
        body = [gen, f'// Functions not listed on any {link_base}/ page, in sections by export file.\n'
                     f'// {len(un)} functions.\n']
        byfile = {}
        for a in un:
            byfile.setdefault(funcs[a]['file'], []).append(a)
        for fn in files:
            if fn not in byfile:
                continue
            body.append(f'\n// {"#" * 100}\n// ## from {fn}: {len(byfile[fn])} functions\n// {"#" * 100}\n\n')
            for a in byfile[fn]:
                body.append(header(funcs[a], None, link_base))
                body.append(funcs[a]['text'])
        with open(os.path.join(out_dir, 'unassigned.c'), 'w', encoding='utf-8', newline='') as f:
            f.write(''.join(body))
        index.append(('unassigned.c', 'none', len(un), sum(funcs[a]['size'] for a in un)))
    assigned = len(funcs) - len(un)
    md = [f'# Readable view: decomp/{image}', '',
          f'Generated by `tools/readable_view.py` from `decomp/{image}/*.c`, `functions.tsv` and the subsystem pages in',
          f'[docs/code/{doc_rel}/]({link_base}/README.md). Do not edit: rerun `python3 -I tools/readable_view.py build`',
          '(`tools/bootstrap.sh --only export` does it after a re-export). The function bodies are byte-identical to the',
          'export; each one gets a header comment with the name, purpose and [fact]/[inference]/[guess] tag from its doc',
          'page, the page link and the caller count. Assignment rules: see the docstring of `tools/readable_view.py`.', '',
          f'**{len(funcs)} functions: {assigned} on a subsystem page, {len(un)} unassigned.**', '',
          '| File | Subsystem page | Functions | Code bytes |', '|---|---|---:|---:|']
    for fn, link, n, size in index:
        md.append(f'| [{fn}]({fn}) | {link} | {n} | {size:,} |')
    md.append('')
    with open(os.path.join(out_dir, 'README.md'), 'w', encoding='utf-8', newline='') as f:
        f.write('\n'.join(md))
    return len(funcs), assigned, len(un)


def main(argv):
    mode = 'build'
    if argv and argv[0] in ('build', 'check'):
        mode, argv = argv[0], argv[1:]
    images = argv or list(IMAGES)
    for im in images:
        if im not in IMAGES:
            raise SystemExit(f'unknown image {im}; one of {", ".join(IMAGES)}')
    if mode == 'build':
        for im in images:
            n, a, u = generate(im, os.path.join(REPO, 'decomp', im, 'readable'))
            print(f'{im}: {n} functions, {a} assigned to a subsystem page, {u} unassigned -> decomp/{im}/readable/')
        return 0
    rc = 0
    with tempfile.TemporaryDirectory() as tmp:
        for im in images:
            fresh = os.path.join(tmp, im.replace('/', '_'))
            generate(im, fresh)
            old = os.path.join(REPO, 'decomp', im, 'readable')
            names = set(os.listdir(fresh)) | (set(os.listdir(old)) if os.path.isdir(old) else set())
            stale = []
            for n in sorted(names):
                a, b = os.path.join(old, n), os.path.join(fresh, n)
                if not os.path.isfile(a) or not os.path.isfile(b):
                    stale.append(f'{n}: {"missing" if not os.path.isfile(a) else "extra"}')
                    continue
                with open(a, 'rb') as fa, open(b, 'rb') as fb:
                    if fa.read() != fb.read():
                        with open(a, encoding='utf-8') as x, open(b, encoding='utf-8') as y:
                            d = list(difflib.unified_diff(x.readlines(), y.readlines(), n, n + ' (fresh)', n=0))
                        stale.append(f'{n}: differs ({len(d)} diff lines)')
            if stale:
                rc = 1
                print(f'{im}: readable/ is STALE (run python3 -I tools/readable_view.py build)')
                for s in stale[:20]:
                    print(f'   {s}')
            else:
                print(f'{im}: readable/ up to date')
    return rc


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
