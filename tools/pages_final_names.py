#!/usr/bin/env python3
"""Switch the code pages from proposed (italic) names to the names applied in Ghidra (T17).

Usage: python3 -I tools/pages_final_names.py CONFIG.json [--dry]

CONFIG.json: {"images": [{"pages": [md files], "functions": [functions.tsv...], "names": [applied TSVs (for @labels)],
                          "renames": {loser: winner}, "protect": [names never auto-renamed]}]}
Per page, in one pass each:
  1. loser -> winner (whole words, simultaneous, so rename chains do not cascade). A loser that is also the final name
     of another function, or in "protect", is skipped and reported for manual review.
  2. `FUN_<addr>` / FUN_<addr> -> the function's final name when it has one.
  3. *name* / *`name`* -> `name` when name is a final (applied) name.
  4. clean-ups: "`x` (`x`)" -> "`x`".
"""
import json
import re
import sys


def load_final(cfg):
    final, byaddr = set(), {}
    for t in cfg.get('functions', []):
        for line in open(t, encoding='utf-8'):
            p = line.rstrip('\n').split('\t')
            if len(p) >= 2 and re.fullmatch(r'[0-9a-fA-F]+', p[0]) and not p[1].startswith('FUN_'):
                final.add(p[1])
                byaddr[int(p[0], 16)] = p[1]
    for t in cfg.get('names', []):
        for line in open(t, encoding='utf-8'):
            if line.startswith('#') or not line.strip():
                continue
            p = line.rstrip('\n').split('\t')
            if len(p) > 1 and p[1].startswith('@'):
                final.add(p[1][1:])
    return final, byaddr


def process(cfg, dry):
    final, byaddr = load_final(cfg)
    protect = set(cfg.get('protect', []))
    ren = {}
    skipped = set()
    for lo, wi in cfg.get('renames', {}).items():
        if lo in final or lo in protect:
            skipped.add(lo)
        else:
            ren[lo] = wi
    ren_re = re.compile(r'(?<![\w@])(' + '|'.join(sorted(map(re.escape, ren), key=len, reverse=True)) + r')(?!\w)') if ren else None
    fun_re = re.compile(r'`?FUN_([0-9a-fA-F]{8})`?')
    ital_re = re.compile(r'(?<![*\w])\*`?([A-Za-z_][A-Za-z0-9_]*)`?\*(?![*\w])')
    dup_re = re.compile(r'`([A-Za-z_]\w*)` \(`\1`\)')
    total = {}
    for page in cfg['pages']:
        s = open(page, encoding='utf-8').read()
        o = s
        c = [0, 0, 0]
        if ren_re:
            s, c[0] = ren_re.subn(lambda m: ren[m.group(1)], s)

        def fun(m):
            a = int(m.group(1), 16)
            if a in byaddr:
                c[1] += 1
                return '`' + byaddr[a] + '`'
            return m.group(0)
        s = fun_re.sub(fun, s)

        def ital(m):
            if m.group(1) in final:
                c[2] += 1
                return '`' + m.group(1) + '`'
            return m.group(0)
        s = ital_re.sub(ital, s)
        s = dup_re.sub(r'`\1`', s)
        s = s.replace('``', '`') if False else s
        if s != o and not dry:
            open(page, 'w', encoding='utf-8').write(s)
        total[page] = c
        print(f'{page}: renames {c[0]}, FUN_ {c[1]}, italic {c[2]}')
    hits = {lo: [p for p in cfg['pages'] if re.search(r'(?<![\w@])' + re.escape(lo) + r'(?!\w)', open(p).read())]
            for lo in sorted(skipped)}
    for lo, ps in hits.items():
        if ps:
            print(f'  manual: {lo} -> {cfg["renames"][lo]} in {", ".join(ps)}')


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    conf = json.load(open(sys.argv[1]))
    for img in conf['images']:
        process(img, '--dry' in sys.argv)


if __name__ == '__main__':
    main()
