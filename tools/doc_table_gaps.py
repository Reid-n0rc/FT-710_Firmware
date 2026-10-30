#!/usr/bin/env python3
"""Named functions that no function table on docs/code/<dir>/ lists, with the page they most likely belong to (T23g).

tools/readable_view.py assigns a function to a subsystem only when a function table on a docs/code/<dir>/*.md page
lists it. This script finds the named functions (not FUN_*) that no table lists yet and proposes a page for each,
from committed files only:
  decomp/<image>/functions.tsv and *.c   entries, names, sizes, export files; the call graph from the bodies
  docs/code/<dir>/*.md                   the function tables (parsed with readable_view.py) and the prose
  tools/ghidra/names_*.tsv, Ifdsp*Names.java   the plate comment of each name and the "# --- section" it sits in

Votes for a page (weights in WEIGHTS):
  hint     the names-file section header names the page (`docs/code/main/sci.md`) or a keyword table maps it (SECTION_HINTS)
  prose    the page mentions the name (backticked) or the address outside its function tables
  calls    callers and callees that a table already assigns to the page
  near     the nearest assigned functions below and above in address order (same export file counts double)
  prefix   the name prefix (`menu_`, `dsp_link_`, `R_SCI`) of assigned functions mostly goes to the page
The page with the most votes wins; ties go to the page name order. `score` is the winner's share of all votes.

Usage:
  python3 -I tools/doc_table_gaps.py [list] [image ...]        TSV on stdout: image, address, name, size, callers,
                                                               page, score, reasons, comment
  python3 -I tools/doc_table_gaps.py summary [image ...]       counts per image and proposed page
  python3 -I tools/doc_table_gaps.py rows IMAGE PAGE [--min S] [--all] [--no-header]
                                                               Markdown table for PAGE in the column layout of the
                                                               page's largest function table (address, Ghidra name,
                                                               [inferred name], purpose with tag); the purpose is the
                                                               names-file comment, or a line built from the code
                                                               (direct callees, first string, size, callers; tagged
                                                               "code shape") when there is none. --all also lists
                                                               FUN_* functions; --min drops proposals below score S.
                                                               Paste the rows into the page and review them
Images: main, display, ifdsp/m33, ifdsp/hifi4 (default: all). Redo after a rename pass or new doc pages.
"""
import os
import re
import sys

TOOLS = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, TOOLS)
import readable_view as rv  # noqa: E402

REPO = rv.REPO
WEIGHTS = {'hint': 6, 'prose': 5, 'calls': 1, 'near': 2, 'prefix': 3}

NAME_FILES = {
    'main': ['names_main.tsv', 'names_main.T10a.tsv', 'names_main.T10b.tsv', 'names_main.T10c.tsv',
             'names_main.T10d.tsv', 'names_main.T10e.tsv', 'names_main.T10f.tsv', 'names_main.T10g.tsv',
             'names_main.T10h.tsv', 'names_main.T23e.tsv', 'names_main.T23d.tsv', 'names_main.lib.tsv'],
    'display': ['names_display.tsv', 'names_display.T11b.tsv', 'names_display.T11c.tsv', 'names_display.T11d.tsv',
                'names_display.T11e.tsv', 'names_display.T11f.tsv', 'names_display.T11g.tsv',
                'names_display.T23e.tsv', 'names_display.T23d.tsv', 'names_display.lib.tsv'],
    'ifdsp/m33': ['IfdspM33Names.java', 'names_ifdsp.T12b.tsv', 'names_ifdsp.T12c.tsv', 'names_ifdsp.T12d.tsv',
                  'names_ifdsp.T23d.tsv', 'names_ifdsp.lib.tsv'],
    'ifdsp/hifi4': ['IfdspHifi4Names.java', 'names_ifdsp.T12b.tsv', 'names_ifdsp.T12c.tsv'],
}
# names-file section header (regex, case-insensitive) or file name -> page; first match wins
SECTION_HINTS = {
    'main': [(r'docs/code/main/([a-z-]+\.md)', None), (r'\bCAT\b|T09', 'cat.md'), (r'T10c|\bSDR\b', 'sdr-link.md'),
             (r'T10d|\bDSP link|IFDSP', 'dsp-link.md'), (r'T10e|EEPROM', 'eeprom.md'),
             (r'T10f|menu', 'menu.md'), (r'T10g|band|VFO', 'radio-control.md'),
             (r'key handler|front-panel key', 'ui-keys.md'), (r'\bSCI\b', 'sci.md'),
             (r'T10h|\bTX\b|protection|meter', 'tx-protection.md'), (r'BSP|boot|runtime|CC-RX|intrinsic', 'bsp.md'),
             (r'SD CARD', 'sd-card.md')],
    'display': [(r'docs/code/display/([a-z-]+\.md)', None), (r'T11b|MAIN link|SCIF5', 'mainlink.md'),
                (r'T11c|update', 'update.md'), (r'T11d|SPI|RSPI', 'spi-links.md'), (r'T11e|GUI|VDC5|draw|font', 'gui.md'),
                (r'T11f|key|encoder|touch|USB|HID|console', 'input.md'),
                (r'FatFs|file system|\bFAT\b|\bSD\b|SDHI|sd_', 'filesystem.md'),
                (r'T11g|GPIO|PFC|GIC|RTC|WAV|audio|LED', 'peripherals.md'),
                (r'NORTi|uITRON|RTOS|startup|armcc|runtime|C library', 'boot-rtos.md')],
    'ifdsp/m33': [(r'docs/code/ifdsp/([a-z-]+\.md)', None), (r'T12b|console|regfile|codec|aic3204', 'control-link.md'),
                  (r'T12c|IPC|rpmsg|MU\b|SEMA', 'ipc.md'), (r'.', 'm33-platform.md')],
    'ifdsp/hifi4': [(r'docs/code/ifdsp/([a-z-]+\.md)', None), (r'T12c|IPC|rpmsg|MU\b|SEMA|srtm', 'ipc.md')],
}
# Curated rules (name regex -> page), checked before the votes: families whose page the votes cannot see, such as a new
# page that has no table yet. Keep them short; a rule only says where a function is described, not what it does.
RULES = {
    'main': [
        (r'^ai_ex', 'cat-ai.md'),
        (r'^menuitem_|^menu_(ex|m|int)\d', 'menu-items.md'),
        (r'^(vec\d+_\w+|R_BSP_\w+|bsp_\w+|charput|charget|_CLOSEALL|_INIT\w*|open|close|write|read|lseek|sbrk|'
         r'get_(bpsw|bpc|extb|acc_\w+|psw|usp|isp|intb|fintv|fpsw)|SuperVisorInst|AccessExc|UndefinedInst|FloatingPoint|'
         r'NMI|Undefined_\w+|freopen|fclose|fflush|_freopen_core|_file_\w+|free|malloc|_fopen_open|_heap_find|heap_getmem|'
         r'strncmp|__\w+|hardware_setup|bsp_\w+)$', 'bsp.md'),
        (r'^(R_SCI6_\w+|r_sci6_\w+)$', 'peripherals.md'),
        (r'^(R_SCI\d_\w+|r_sci\d_\w+)$', 'sci.md'),
        (r'^(sd_\w+_(start|step)|sd_op_clear|sd_step_reset|sd_abort_no_card|sd_(save|load)_xfer_id|sd_menu_enter_check|'
         r'menu_\w+)$', 'menu.md'),
        (r'^key_\w+_(press|short|long|release|repeat)$', 'ui-keys.md'),
        (r'^displink_', 'display-link.md'),
        (r'^dsp_set_', 'dsp-link.md'),
        (r'^sdr_(upd|init)_', 'sdr-link.md'),
        (r'^cat_[A-Z0-9]{2}$', 'cat.md'),
    ],
    'display': [
        (r'^\w+_Handler$', 'boot-rtos.md'),
        (r'^(sd_(fs_init|task_create|card_identify|read_sectors|write_sectors|fat_format|format|make_dirs|state_bit\d)|sdhi\w*|'
         r'fs_\w+|fat_\w+|fsys_\w+|sjis_is_lead|sd_info_screen|fmt_size_str)$', 'filesystem.md'),
        (r'^(itron_\w+|os_create_\w+|knl_\w+)$', 'boot-rtos.md'),
        (r'^(__\w+|_printf\w*|_sputc|_snputc|_ttywrch|_sys_exit|exit|str(cpy|cat|cmp|ncmp|len|str)(_veneer)?|'
         r'mem(cpy|cmp|set)(_veneer)?|s?n?printf(_veneer)?|tolower)$', 'boot-rtos.md'),
    ],
    'ifdsp/m33': [  # FreeRTOS kernel/port and the Redlib C library are described on m33-platform.md (sections 6, 9)
        (r'^((x|v|pv|ux|ul|prv|pc)[A-Z]\w+|str\w+|mem\w+|_C\w+|__sys_\w+|s?n?i?printf|tolower)$', 'm33-platform.md'),
    ],
    'ifdsp/hifi4': [],
}
JAVA_ROW = re.compile(r'\{\s*0x([0-9A-Fa-f]+)L?\s*,\s*"([A-Za-z_][A-Za-z0-9_]*)"\s*(?:,\s*"((?:[^"\\]|\\.)*)")?\s*\}')
CALL = re.compile(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\(')
STRING = re.compile(r'"((?:[^"\\]|\\.){3,40})"')
TABLE_LINE = re.compile(r'^\s*\|')
PREFIX = re.compile(r'^(_*[A-Za-z][A-Za-z0-9]*_(?:[A-Za-z0-9]+_)?)')


def load_comments(image):
    """addr -> list of (name, comment, section, file): every names-file row for this program."""
    out = {}
    want_prog = image.split('/')[-1] if image.startswith('ifdsp') else None
    for fn in NAME_FILES[image]:
        path = os.path.join(TOOLS, 'ghidra', fn)
        if not os.path.exists(path):
            continue
        with open(path, encoding='utf-8') as f:
            text = f.read()
        if fn.endswith('.java'):
            section = fn
            for line in text.split('\n'):
                c = re.match(r'\s*//\s*-*\s*([^{}]+?)\s*$', line)
                if c and not line.lstrip().startswith('// @') and line.startswith('        //'):
                    section = c.group(1) + ' | ' + fn
                for m in JAVA_ROW.finditer(line):
                    out.setdefault(int(m.group(1), 16), []).append(
                        (m.group(2), (m.group(3) or '').replace('\\"', '"'), section, fn))
            continue
        section, prog = fn, want_prog
        for line in text.split('\n'):
            if line.startswith('#'):
                p = re.match(r'#\s*program:\s*(\w+)', line)
                if p:
                    prog = 'm33' if 'm33' in p.group(1).lower() or p.group(1).lower().startswith('ft') else p.group(1)
                    prog = 'hifi4' if 'hifi' in p.group(1).lower() else prog
                    continue
                if line.startswith('# ---'):
                    section = line[5:].strip()
                continue
            cols = line.split('\t')
            if len(cols) < 2 or not re.match(r'^(0x)?[0-9A-Fa-f]{5,8}$', cols[0].strip()):
                continue
            if want_prog and prog and prog != want_prog:
                continue
            if fn.endswith('.lib.tsv'):
                if len(cols) >= 8:
                    ev = cols[7].strip()
                    ev = '' if re.match(r'(same|was|new)?;?\s*size \d', ev) or ev.startswith('same;') else ev
                    ev = re.sub(r'^(new|same|was \S+);\s*', '', ev)
                    ev = f': {ev}' if ev else ''
                    lib = cols[2] + (' ' + cols[3] if len(cols[3]) < 12 else '')  # long version strings repeat the name
                    lib += ' function' if lib.endswith('library') else ' library function'
                    out.setdefault(int(cols[0], 16), []).append(
                        (cols[1].strip(), f'{lib}, matched by {cols[4]} (score {cols[5]}, T23d){ev} [inference]',
                         section + ' | ' + fn, fn))
                continue
            out.setdefault(int(cols[0], 16), []).append(
                (cols[1].strip(), cols[2].strip() if len(cols) > 2 else '', section + ' | ' + fn, fn))
    return out


def best_comment(rows, name):
    """The longest comment of a row with the current name, else of any row."""
    same = [r for r in rows if r[0] == name and r[1]]
    pool = same or [r for r in rows if r[1]]
    if not pool:
        return '', rows[0][2] if rows else ''
    r = max(pool, key=lambda r: (r[0] == name, len(r[1])))
    return r[1], r[2]


def page_hint(image, section):
    for rx, page in SECTION_HINTS[image]:
        m = re.search(rx, section, re.I)
        if m:
            return page or m.group(1)
    return None


def prose_mentions(doc_dir, pages):
    """page -> (set of backticked names, set of hex ints) outside table rows."""
    out = {}
    for page in pages:
        with open(os.path.join(doc_dir, page), encoding='utf-8') as f:
            lines = f.read().split('\n')
        names, addrs = set(), set()
        for line in lines:
            if TABLE_LINE.match(line):
                cells = rv.split_row(line)
                # a non-function table row (data, steps) still counts as prose for names in later cells
                line = ' '.join(cells[1:]) if len(cells) > 1 else ''
            names.update(rv.TICK.findall(line))
            names.update(re.findall(r'\b([a-z][a-z0-9]*_[A-Za-z0-9_]+)\b', line))
            addrs.update(int(h, 16) for h in rv.HEX.findall(line))
        out[page] = (names, addrs)
    return out


def call_graph(funcs):
    byname = {f['name']: a for a, f in funcs.items()}
    callees = {}
    for a, f in funcs.items():
        body = f['text'].split('\n', 1)[1] if '\n' in f['text'] else ''
        s = set()
        for n in CALL.findall(body):
            b = byname.get(n)
            if b is not None and b != a:
                s.add(b)
        callees[a] = s
    callers = {a: set() for a in funcs}
    for a, s in callees.items():
        for b in s:
            callers[b].add(a)
    return callees, callers


def prefix_of(name):
    m = PREFIX.match(name)
    return m.group(1) if m else None


def analyse(image):
    img_dir = os.path.join(REPO, 'decomp', image)
    doc_dir = os.path.join(REPO, 'docs', 'code', rv.IMAGES[image])
    funcs, files = rv.load_export(img_dir)
    hits, pages = rv.assign(funcs, doc_dir)
    home = {a: h[0][0] for a, h in hits.items()}
    comments = load_comments(image)
    prose = prose_mentions(doc_dir, pages)
    callees, callers = call_graph(funcs)
    pref = {}
    for a, p in home.items():
        k = prefix_of(funcs[a]['name'])
        if k:
            pref.setdefault(k, {}).setdefault(p, 0)
            pref[k][p] += 1
    order = sorted(funcs)
    pos = {a: i for i, a in enumerate(order)}
    res = []
    for a in order:
        if a in home:
            continue
        f = funcs[a]
        votes, why = {}, {}

        def vote(page, w, kind):
            votes[page] = votes.get(page, 0) + w
            why.setdefault(page, set()).add(kind)

        comment, section = best_comment(comments.get(a, []), f['name'])
        rule = next((p for rx, p in RULES[image] if re.search(rx, f['name'])), None)
        if rule:
            vote(rule, 100, 'rule')
        hp = page_hint(image, section) if section else None
        if hp:
            vote(hp, WEIGHTS['hint'], 'hint')
        for p, (names, addrs) in prose.items():
            if f['name'] in names or (a in addrs and a > 0xFFFF):
                vote(p, WEIGHTS['prose'] * (0.6 if p == 'README.md' else 1), 'prose')
        nb = {}
        for b in callees[a] | callers[a]:
            if b in home:
                nb[home[b]] = nb.get(home[b], 0) + 1
        tot = sum(nb.values())
        for p, n in nb.items():
            vote(p, WEIGHTS['calls'] * 4 * n / max(tot, 1) * (0.4 if p == 'README.md' else 1), 'calls')
        i = pos[a]
        for step in (-1, 1):
            j = i + step
            while 0 <= j < len(order) and order[j] not in home:
                j += step
            if 0 <= j < len(order):
                b = order[j]
                dist = abs(j - i)
                w = WEIGHTS['near'] * (1 if funcs[b]['file'] == f['file'] else 0.5) / (1 + dist / 8)
                vote(home[b], w * (0.4 if home[b] == 'README.md' else 1), 'near')
        k = prefix_of(f['name'])
        if k and k in pref:
            n = sum(pref[k].values())
            p, c = max(pref[k].items(), key=lambda x: x[1])
            if n >= 2 and c / n >= 0.6:
                vote(p, WEIGHTS['prefix'] * min(1, n / 4), 'prefix')
        if votes:
            page = max(sorted(votes), key=lambda p: votes[p])
            score = votes[page] / sum(votes.values())
            reasons = ','.join(sorted(why[page]))
        else:
            page, score, reasons = '', 0.0, ''
        res.append({'addr': a, 'name': f['name'], 'size': f['size'], 'callers': f['callers'], 'file': f['file'],
                    'page': page, 'score': score, 'reasons': reasons, 'comment': comment, 'section': section,
                    'callees': sorted(funcs[b]['name'] for b in callees[a]),
                    'ncallers': len(callers[a]), 'text': f['text']})
    return res, pages, funcs


TAG_IN = re.compile(r'\*?\*?\[(fact|inference|guess)[^\]]*\]\*?\*?', re.I)


def purpose(r):
    """Short purpose with a tag: the names-file comment, or a line from the code."""
    c = r['comment']
    m = re.match(r'^T23[de] (.*?) \((\w+) ([0-9.]+)\):\s*', c)  # lib_match provenance prefix -> library name
    if m:
        c = f'{m.group(1)}: ' + c[m.end():]
    cat = re.match(r'^cat_([A-Z0-9]{2})$', r['name'])
    if not c and cat:
        c = (f'Handler of CAT command `{cat.group(1)}`: entry of the command dispatch table (CatDispatch.java); '
             f'{r["size"]} B [fact]')
    c = re.sub(r'^(NEW( ENTRY)?|create|rename)\b\s*[:;,-]?\s*', '', c)
    tag = None
    m = TAG_IN.search(c)
    if m:
        tag = m.group(1).lower()
        c = TAG_IN.sub('', c).strip(' ;,.')
    c = c.replace('|', '\\|').strip()
    if len(c) > 230:
        cut = c[:230]
        c = cut[:cut.rfind(' ')] + ' …'
    if c:
        return f'{c} **[{tag or "inference"}]**'
    calls = r['callees']
    body = r['text']
    strs = STRING.findall(body)
    sec = (r.get('section') or '').split(' | ')[0].strip()
    lead = ''
    if sec and not re.match(r'(merged|T\d\d|names_|Ifdsp|FT-710|#)', sec) and not sec.endswith(('.tsv', '.java')):
        lead = f'names-file group "{sec.rstrip(":. ")}"; '
    bits = []
    if calls:
        shown = ', '.join(f'`{n}`' for n in calls[:4]) + (f' and {len(calls) - 4} more' if len(calls) > 4 else '')
        bits.append(f'calls {shown}')
    else:
        bits.append('no direct calls')
    if strs:
        bits.append(f'string "{strs[0][:30]}"')
    bits.append(f'{r["size"]} B, callers: {r["callers"]}')
    return (lead + '; '.join(bits)).replace('|', '\\|') + ' **[fact]** (code shape)'


DEFAULT_HEADER = ['Address', 'Ghidra name', 'Inferred name', 'Purpose']


def page_format(doc_dir, page):
    """Header of the page's largest `Address | Ghidra name | ...` table (DEFAULT_HEADER for a new page)."""
    path = os.path.join(doc_dir, page)
    if not os.path.exists(path):
        return DEFAULT_HEADER
    best, n = DEFAULT_HEADER, -1
    for header, rows in rv.parse_tables(path):
        low = [h.lower() for h in header]
        if 'ghidra name' in low and 'address' in low and len(rows) > n:
            best, n = header, len(rows)
    return best


def format_row(header, r):
    """One Markdown row in the column layout of `header`."""
    text = purpose(r)
    tagm = re.search(r'\*\*\[(fact|inference|guess)\]\*\*', text)
    low = [h.lower() for h in header]
    has_tag = 'tag' in low
    if has_tag and tagm:
        text = (text[:tagm.start()] + text[tagm.end():]).replace('  ', ' ').strip()
    cells, used = [], False
    for h in low:
        if h == 'address':
            cells.append(f'0x{r["addr"]:08X}')
        elif h == 'ghidra name':
            cells.append(f'`{r["name"]}`')
        elif h == 'tag':
            cells.append(tagm.group(1) if tagm else 'inference')
        elif h.startswith(rv.INFER_PREFIX):
            cells.append('')
        elif not used:
            cells.append(text)
            used = True
        else:
            cells.append('')
    return '| ' + ' | '.join(cells) + ' |'


def rows_md(image, page, min_score=0.0, include_fun=False, res=None):
    if res is None:
        res = analyse(image)[0]
    doc_dir = os.path.join(REPO, 'docs', 'code', rv.IMAGES[image])
    header = page_format(doc_dir, page)
    out = []
    for r in res:
        if r['page'] != page or r['score'] < min_score:
            continue
        if r['name'].startswith('FUN_') and not include_fun:
            continue
        out.append(format_row(header, r))
    return header, out


def main(argv):
    mode = 'list'
    if argv and argv[0] in ('list', 'summary', 'rows'):
        mode, argv = argv[0], argv[1:]
    if mode == 'rows':
        if len(argv) < 2:
            raise SystemExit(__doc__)
        image, page = argv[0], argv[1]
        ms = float(argv[argv.index('--min') + 1]) if '--min' in argv else 0.0
        header, rows = rows_md(image, page, ms, '--all' in argv)
        if '--no-header' not in argv:
            print('| ' + ' | '.join(header) + ' |')
            print('|' + '---|' * len(header))
        print('\n'.join(rows))
        return 0
    images = argv or list(rv.IMAGES)
    for im in images:
        if im not in rv.IMAGES:
            raise SystemExit(f'unknown image {im}; one of {", ".join(rv.IMAGES)}')
    if mode == 'list':
        print('image\taddress\tname\tsize\tcallers\tpage\tscore\treasons\tcomment')
    for im in images:
        res, pages, funcs = analyse(im)
        named = [r for r in res if not r['name'].startswith('FUN_')]
        if mode == 'list':
            for r in named:
                print(f'{im}\t0x{r["addr"]:08X}\t{r["name"]}\t{r["size"]}\t{r["callers"]}\t{r["page"]}\t'
                      f'{r["score"]:.2f}\t{r["reasons"]}\t{r["comment"][:200]}')
        else:
            by = {}
            for r in named:
                by.setdefault(r['page'] or '(none)', []).append(r)
            nf = sum(1 for f in funcs.values() if not f['name'].startswith('FUN_'))
            print(f'{im}: {len(funcs)} functions, {nf} named, {len(named)} named not in any function table')
            for p in sorted(by, key=lambda p: -len(by[p])):
                strong = sum(1 for r in by[p] if r['score'] >= 0.5)
                exists = 'new page' if p != '(none)' and p not in pages else ''
                print(f'   {p:24s} {len(by[p]):5d}  (score >= 0.5: {strong}) {exists}')
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
