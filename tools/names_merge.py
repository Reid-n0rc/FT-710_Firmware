#!/usr/bin/env python3
"""Merge per-sub-task Ghidra name/entry TSVs into one shared TSV (T17).

Usage:
  python3 -I tools/names_merge.py report BASE.tsv PROPOSAL.tsv...
      print every address that has more than one distinct name (conflicts) and counts
  python3 -I tools/names_merge.py merge BASE.tsv OUT.tsv [--pick ADDR=NAME]... [--picks FILE] [--drop ADDR]... PROPOSAL.tsv...
      write OUT.tsv: BASE lines first (names replaced where a proposal or --pick says so), then one section per proposal
      file with the addresses it adds. The first comment wins unless the winning name comes from a later file.

TSV format (names_*.tsv / entries_*.tsv): address<TAB>name<TAB>comment; '#' and blank lines are ignored.
For entries files the name column is empty or 'drop'. Addresses are compared case-insensitively without 0x.
Default conflict rule: a proposal overrides BASE (sub-tasks rename T05/T06 names on purpose); between proposals the
later file wins. Every conflict is listed by `report` so it can be resolved explicitly with --pick or --picks (a TSV
address<TAB>name[<TAB>reason], e.g. tools/ghidra/names_main.picks.tsv).
"""
import sys


def norm(a):
    a = a.strip().lower()
    a = a[2:] if a.startswith('0x') else a
    return a.zfill(8)


def read(path):
    rows = []
    for line in open(path, encoding='utf-8'):
        line = line.rstrip('\n')
        if not line.strip() or line.startswith('#'):
            continue
        p = line.split('\t')
        while len(p) < 3:
            p.append('')
        rows.append((norm(p[0]), p[1].strip(), '\t'.join(p[2:]).strip()))
    return rows


def collect(base, props):
    by = {}
    for src in [base] + props:
        for a, n, c in read(src):
            by.setdefault(a, []).append((src, n, c))
    return by


def report(base, props):
    by = collect(base, props)
    nconf = 0
    for a in sorted(by, key=lambda x: int(x, 16)):
        names = []
        for src, n, c in by[a]:
            if n not in names:
                names.append(n)
        if len(names) > 1:
            nconf += 1
            print(a + '\t' + ' | '.join(f'{n} ({src.rsplit("/", 1)[-1]})' for src, n, c in by[a]))
    print(f'# {len(by)} addresses, {nconf} with differing names', file=sys.stderr)


def merge(base, out, props, picks, drops):
    by = collect(base, props)
    final = {}
    for a, entries in by.items():
        if a in picks:
            name = picks[a]
            com = next((c for s, n, c in entries if n == name and c), next((c for s, n, c in entries if c), ''))
        else:
            src, name, com = entries[-1]
            if not com:
                com = next((c for s, n, c in reversed(entries) if c), '')
        final[a] = (name, com)
    lines = []
    seen = set()
    for line in open(base, encoding='utf-8'):
        line = line.rstrip('\n')
        if not line.strip() or line.startswith('#'):
            lines.append(line)
            continue
        a = norm(line.split('\t')[0])
        if a in seen or a in drops:
            continue
        seen.add(a)
        n, c = final[a]
        lines.append(f'{a}\t{n}\t{c}'.rstrip('\t') if c else f'{a}\t{n}')
    for src in props:
        add = [r for r in read(src) if r[0] not in seen and r[0] not in drops]
        if not add:
            continue
        lines.append(f'# --- merged from {src.rsplit("/", 1)[-1]} (T17)')
        for a, _, _ in add:
            if a in seen:
                continue
            seen.add(a)
            n, c = final[a]
            lines.append(f'{a}\t{n}\t{c}' if c else f'{a}\t{n}')
    open(out, 'w', encoding='utf-8').write('\n'.join(lines) + '\n')
    print(f'{out}: {len(seen)} entries', file=sys.stderr)


def main(argv):
    if len(argv) < 3:
        sys.exit(__doc__)
    if argv[1] == 'report':
        report(argv[2], argv[3:])
    elif argv[1] == 'merge':
        base, out = argv[2], argv[3]
        picks, drops, props = {}, set(), []
        it = iter(argv[4:])
        for x in it:
            if x == '--picks':
                for line in open(next(it), encoding='utf-8'):
                    if line.strip() and not line.startswith('#'):
                        a, n = line.split('\t')[:2]
                        picks[norm(a)] = n.strip()
            elif x == '--pick':
                a, n = next(it).split('=', 1)
                picks[norm(a)] = n
            elif x == '--drop':
                drops.add(norm(next(it)))
            else:
                props.append(x)
        merge(base, out, props, picks, drops)
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main(sys.argv)
