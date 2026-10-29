#!/usr/bin/env python3
"""Ranked naming work list for one decompiled image (T23e).

Usage:
  python3 -I tools/naming_worklist.py IMAGE [--top N] [--format md|tsv] [--out FILE] [--all] [--min-callers K]
      IMAGE is main or display (any decomp/<image>/ with functions.tsv works; register and memory-map clues are
      MAIN/DISPLAY specific). Ranks the unnamed FUN_ functions by distinct callers, then by call sites, and prints per
      function the clues a reviewer needs to name it: strings, globals and registers it touches (named from
      tools/ghidra/sfr_rx651.tsv for MAIN, docs/memory-maps.md and the docs/code/<image>/ tables), named callers and
      callees, the CAT commands whose handlers reach it (decomp/main/cat_dispatch.tsv, up to 3 call levels), menu
      items whose callbacks reach it, and the first lines of the body.
  python3 -I tools/naming_worklist.py IMAGE --coverage NAMES.tsv
      how many functions and call sites the addresses in NAMES.tsv cover (for the task file).

"Unnamed" = the decomp shows FUN_<addr> AND tools/ghidra/names_<image>.tsv has no row for the address (names added
after the last export count as named). Output is derived from the firmware: write it to build/ or a scratch dir, never
commit it. Standard library only.
"""
import argparse
import collections
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HDR = re.compile(r'^// ===== (\S+) @ ([0-9a-f]+) \((\d+) bytes\)')
IDENT_CALL = re.compile(r'\b([A-Za-z_@][\w@]*)\s*\(')
IDENT = re.compile(r'\b([A-Za-z_][\w]*)\b')
DAT = re.compile(r'\b(?:PTR_)?DAT_([0-9a-f]{8})\b')
PTRIDX = re.compile(r'\bPTR_DAT_(0002[0-9a-f]{4})\[(0x[0-9a-f]+|\d+)\]')
STR = re.compile(r'\bs_[A-Za-z0-9_]+|"(?:[^"\\]|\\.)*"')
# MAIN: the eleven pointer constants to the state block 0x20B04 (docs/memory-maps.md)
MAIN_STATE_PTRS = {0x25D38, 0x25D4C, 0x25D54, 0x25D58, 0x25D5C, 0x25D60, 0x25D6C, 0x25D70, 0x25D74, 0x25D78, 0x25D7C}


def norm(a):
    a = a.strip().lower()
    return (a[2:] if a.startswith('0x') else a).zfill(8)


def read_names(path):
    out = {}
    if not os.path.exists(path):
        return out
    for line in open(path, encoding='utf-8'):
        if not line.strip() or line.startswith('#'):
            continue
        p = line.rstrip('\n').split('\t')
        if len(p) >= 2 and p[1].strip():
            out[norm(p[0])] = (p[1].strip(), p[2].strip() if len(p) > 2 else '')
    return out


def parse_decomp(d):
    funcs = collections.OrderedDict()
    for line in open(os.path.join(d, 'functions.tsv'), encoding='utf-8'):
        p = line.rstrip('\n').split('\t')
        if p[0] == 'entry':
            continue
        funcs[p[0]] = {'name': p[1], 'size': int(p[2]), 'refs': int(p[3]), 'file': p[4], 'body': '', 'comment': ''}
    for f in sorted(glob.glob(os.path.join(d, '*.c'))):
        cur = None
        buf = []

        def flush():
            if cur and cur in funcs:
                txt = ''.join(buf)
                m = re.match(r'\s*/\*(.*?)\*/', txt, re.S)
                funcs[cur]['comment'] = ' '.join(m.group(1).split()) if m else ''
                funcs[cur]['body'] = txt
        for line in open(f, encoding='utf-8', errors='replace'):
            m = HDR.match(line)
            if m:
                flush()
                cur, buf = m.group(2), []
                continue
            buf.append(line)
        flush()
    return funcs


def range_labels_from_md(paths):
    """Markdown table rows whose first cell starts with an address: [(lo, hi, text)]."""
    rows = []
    cell = re.compile(r'^\|\s*`?(0x[0-9A-Fa-f]{3,8})(?:\s*(?:\.\.|–|-)\s*`?(0x[0-9A-Fa-f]{3,8}))?')
    for p in paths:
        for line in open(p, encoding='utf-8'):
            m = cell.match(line)
            if not m:
                continue
            lo = int(m.group(1), 16)
            hi = int(m.group(2), 16) if m.group(2) else lo
            parts = [c.strip() for c in line.strip().strip('|').split('|')]
            text = ' | '.join(parts[1:])[:110]
            rows.append((lo, hi, text, os.path.relpath(p, ROOT)))
    return rows


def sfr_labels(path):
    out = {}
    if not os.path.exists(path):
        return out
    for line in open(path, encoding='utf-8'):
        if line.startswith('#'):
            continue
        p = line.rstrip('\n').split('\t')
        if len(p) > 6 and (p[6] == '1' or int(p[0], 16) not in out):
            out[int(p[0], 16)] = p[1]
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('image')
    ap.add_argument('--top', type=int, default=100)
    ap.add_argument('--format', choices=['md', 'tsv'], default='md')
    ap.add_argument('--out')
    ap.add_argument('--all', action='store_true', help='rank named functions too')
    ap.add_argument('--min-callers', type=int, default=1)
    ap.add_argument('--excerpt', type=int, default=14, help='body lines to show')
    ap.add_argument('--coverage')
    a = ap.parse_args()

    d = os.path.join(ROOT, 'decomp', a.image)
    funcs = parse_decomp(d)
    names = read_names(os.path.join(ROOT, 'tools', 'ghidra', 'names_%s.tsv' % a.image))
    by_name = {f['name']: e for e, f in funcs.items()}

    def cur_name(e):
        if e in names:
            return names[e][0]
        return funcs[e]['name'] if e in funcs else e

    # call graph from the C text
    callers = collections.defaultdict(set)
    sites = collections.Counter()
    callees = collections.defaultdict(collections.Counter)
    ptr_refs = collections.defaultdict(set)
    for e, f in funcs.items():
        body = f['body']
        # drop the leading comment and the signature line so the function's own name is not counted
        i = body.find('{')
        code = body[i:] if i >= 0 else body
        for m in IDENT_CALL.finditer(code):
            t = by_name.get(m.group(1))
            if t is None or t == e:
                continue
            callers[t].add(e)
            sites[t] += 1
            callees[e][t] += 1
        for m in IDENT.finditer(code):
            t = by_name.get(m.group(1))
            if t and t != e and t not in callees[e]:
                ptr_refs[t].add(e)

    if a.coverage:
        cov = read_names(a.coverage)
        n = sum(1 for x in cov if x in funcs)
        s = sum(sites[x] for x in cov if x in funcs)
        c = sum(len(callers[x]) for x in cov if x in funcs)
        tot = sum(sites.values())
        print('%s: %d of %d rows are functions in decomp/%s; %d call sites (%.1f %% of %d), %d caller edges' % (
            a.coverage, n, len(cov), a.image, s, 100.0 * s / max(tot, 1), tot, c))
        return

    labels_extra = []
    # CAT and menu reach (callers up to 3 levels)
    cat_of = collections.defaultdict(set)
    cd = os.path.join(d, 'cat_dispatch.tsv')
    if os.path.exists(cd):
        for line in open(cd, encoding='utf-8'):
            p = line.rstrip('\n').split('\t')
            if len(p) < 5 or p[0] == 'table':
                continue
            for h in re.findall(r'@([0-9a-f]{8})', p[4]):
                cat_of[h].add(p[2])
    menu_of = collections.defaultdict(set)
    mf = os.path.join(ROOT, 'tools', 'ghidra', 'entries_%s_menu.tsv' % a.image)
    if os.path.exists(mf):
        for line in open(mf, encoding='utf-8'):
            if line.startswith('#') or not line.strip():
                continue
            p = line.rstrip('\n').split('\t')
            if len(p) > 2:
                menu_of[norm(p[0])].add(p[2].split()[-1])

    # EX item names and RAM addresses from the item list in docs/code/main/menu.md (MAIN only)
    ex_name = {}
    mm = os.path.join(ROOT, 'docs', 'code', a.image, 'menu.md')
    if os.path.exists(mm):
        for line in open(mm, encoding='utf-8'):
            if not re.match(r'^\| `\d{6}` \|', line):
                continue
            c = [x.strip() for x in line.strip().strip('|').split('|')]
            key = c[0].strip('`')
            if len(c) == 8 and re.match(r'0x[0-9a-fA-F]+$', c[6]):
                ex_name['ex' + key] = c[2]
                labels_extra.append((int(c[6], 16), 'EX%s %s' % (key, c[2])))
            elif len(c) == 7 and re.match(r'0x[0-9a-fA-F]+$', c[5]) and key.startswith('06'):
                # PRESET items: one row for PRESET1, RAM = PRESET1 RAM + 0x1F * (P2 - 1)
                for pp in range(1, 6):
                    k = '06%02d%s' % (pp, key[4:])
                    ex_name['ex' + k] = c[1]
                    labels_extra.append((int(c[5], 16) + 0x1F * (pp - 1), 'EX%s %s' % (k, c[1])))

    def reach(e, table, depth=3):
        out, seen, front = set(), {e}, {e}
        for _ in range(depth):
            nxt = set()
            for x in front:
                for c in callers[x] | ptr_refs[x]:
                    if c not in seen:
                        seen.add(c)
                        nxt.add(c)
                        out |= table.get(c, set())
            front = nxt
        out |= table.get(e, set())
        return out

    # address clues
    labels = []
    mdpaths = [os.path.join(ROOT, 'docs', 'memory-maps.md')] + sorted(
        glob.glob(os.path.join(ROOT, 'docs', 'code', a.image, '*.md')))
    labels = range_labels_from_md(mdpaths)
    sfr = sfr_labels(os.path.join(ROOT, 'tools', 'ghidra', 'sfr_rx651.tsv')) if a.image == 'main' else {}

    def addr_clue(x):
        if x in sfr:
            return sfr[x]
        for ax, t in labels_extra:
            if ax == x:
                return t
        pre = ''
        if a.image == 'main' and 0x20B04 <= x < 0x20B04 + 0x500:
            pre = 'state+0x%X ' % (x - 0x20B04)
        best = None
        for lo, hi, text, src in labels:
            if hi - lo > 0x800:
                continue
            if lo <= x <= hi and (best is None or hi - lo < best[1] - best[0]):
                best = (lo, hi, text)
        if best:
            return pre + best[2][:70]
        return pre.strip()

    def globals_of(e):
        code = funcs[e]['body']
        cnt = collections.Counter()
        for m in PTRIDX.finditer(code):
            base = int(m.group(1), 16)
            if a.image == 'main' and base in MAIN_STATE_PTRS:
                cnt[0x20B04 + int(m.group(2), 0)] += 1
        for m in DAT.finditer(code):
            x = int(m.group(1), 16)
            if a.image == 'main' and x in MAIN_STATE_PTRS:
                continue
            cnt[x] += 1
        out = []
        for x, n in cnt.most_common(12):
            c = addr_clue(x)
            out.append('0x%X%s%s' % (x, ' x%d' % n if n > 1 else '', ' (' + c + ')' if c else ''))
        return out

    # what the docs already say about a function (FUN_<addr> or 0x<ADDR>)
    docs_text = []
    for p in sorted(glob.glob(os.path.join(ROOT, 'docs', '**', '*.md'), recursive=True)):
        if '/tasks/' in p:
            continue
        for ln in open(p, encoding='utf-8', errors='replace'):
            docs_text.append((os.path.relpath(p, ROOT), ln))

    def doc_mentions(e, k=3):
        pat = re.compile(r'FUN_%s\b|0x%s\b' % (e, e.upper()), re.I)
        out = []
        for path, ln in docs_text:
            m = pat.search(ln)
            if m:
                lo = max(0, m.start() - 90)
                out.append('%s: …%s…' % (path, ' '.join(ln[lo:m.end() + 160].split())))
                if len(out) >= k:
                    break
        return out

    cand = []
    for e, f in funcs.items():
        if not a.all and (not f['name'].startswith('FUN_') or e in names):
            continue
        if len(callers[e]) < a.min_callers:
            continue
        cand.append((-len(callers[e]), -sites[e], e))
    cand.sort()
    cand = cand[:a.top]

    out = open(a.out, 'w', encoding='utf-8') if a.out else sys.stdout
    if a.format == 'tsv':
        out.write('# naming work list for decomp/%s, made by tools/naming_worklist.py (not committed)\n' % a.image)
        out.write('rank\taddress\tcallers\tsites\tsize\tstrings\tglobals\tcat\tmenu\tnamed_callers\tnamed_callees\n')
    else:
        out.write('# Naming work list: decomp/%s (tools/naming_worklist.py)\n\n' % a.image)
        out.write('Ranked by distinct callers, then call sites. %d candidates shown.\n\n' % len(cand))
    for rank, (_, _, e) in enumerate(cand, 1):
        f = funcs[e]
        strs = sorted({x[:60] + ('…' if len(x) > 60 else '') for x in STR.findall(f['body'])})[:10]
        nc = sorted({cur_name(c) for c in callers[e] if not cur_name(c).startswith('FUN_')})
        unc = len([c for c in callers[e] if cur_name(c).startswith('FUN_')])
        ce = [(cur_name(c), n) for c, n in callees[e].most_common()]
        cats = sorted(reach(e, cat_of))
        menus = sorted(reach(e, menu_of))
        gl = globals_of(e)
        if a.format == 'tsv':
            out.write('\t'.join(str(v) for v in [
                rank, e, len(callers[e]), sites[e], f['size'], ' '.join(strs), '; '.join(gl), ' '.join(cats),
                ' '.join(menus[:20]), ' '.join(nc[:20]), ' '.join('%s' % n for n, _ in ce[:20])]) + '\n')
            continue
        out.write('## %d. %s @ %s — %d callers, %d call sites, %d bytes\n\n' % (
            rank, cur_name(e), e, len(callers[e]), sites[e], f['size']))
        if f['comment']:
            out.write('- comment: %s\n' % f['comment'][:300])
        if strs:
            out.write('- strings: %s\n' % ', '.join(strs))
        if gl:
            out.write('- globals: %s\n' % '; '.join(gl))
        if cats:
            out.write('- CAT: %s\n' % ' '.join(cats))
        if menus:
            out.write('- menu: %s%s\n' % (', '.join(m + (' ' + ex_name[m] if m in ex_name else '') for m in menus[:25]),
                                           ' …' if len(menus) > 25 else ''))
        out.write('- named callers (%d, +%d unnamed): %s\n' % (len(nc), unc, ', '.join(nc[:30])))
        if ptr_refs[e]:
            out.write('- referenced (not called) by: %s\n' % ', '.join(sorted(cur_name(c) for c in ptr_refs[e])[:10]))
        for dm in doc_mentions(e):
            out.write('- docs: %s\n' % dm)
        if ce:
            out.write('- callees: %s\n' % ', '.join('%s%s' % (n, '' if k == 1 else ' x%d' % k) for n, k in ce[:25]))
        body = f['body']
        i = body.find('{')
        lines = [l.rstrip() for l in (body[:i].strip().splitlines()[-1:] + body[i:].splitlines()) if l.strip()]
        out.write('\n```c\n%s\n```\n\n' % '\n'.join(l[:160] for l in lines[:a.excerpt]))
    if a.out:
        out.close()


if __name__ == '__main__':
    main()
