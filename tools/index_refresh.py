#!/usr/bin/env python3
"""Refresh the export file names and function names in a decomp INDEX.md from functions.tsv (T17).

Usage: python3 -I tools/index_refresh.py decomp/<image>/INDEX.md decomp/<image>[/sub]/functions.tsv [...more functions.tsv]

For every Markdown table row whose first cell starts with an address (0x...), the `<first>_<last>.c` token in the row is
replaced by the file that now holds that address (ExportDecomp re-buckets the 50-function files on every export), and a
backticked `FUN_<addr>` for that address is replaced by the function's current name. Prints a count of changed rows.
"""
import re
import sys


def main(index, tsvs):
    funcs = {}
    for t in tsvs:
        for line in open(t, encoding='utf-8'):
            p = line.rstrip('\n').split('\t')
            if len(p) >= 5 and re.fullmatch(r'[0-9a-fA-F]+', p[0]):
                funcs[int(p[0], 16)] = (p[1], p[4])
    out, changed = [], 0
    for line in open(index, encoding='utf-8'):
        m = re.match(r'\|\s*`?0x([0-9A-Fa-f]+)', line)
        if m:
            a = int(m.group(1), 16)
            new = line
            if a in funcs:
                name, file = funcs[a]
                new = re.sub(r'\b[0-9a-f]{8}_[0-9a-f]{8}\.c\b', file, new, count=1)
                new = new.replace(f'`FUN_{a:08x}`', f'`{name}`') if not name.startswith('FUN_') else new
            if new != line:
                changed += 1
            line = new
        out.append(line)
    open(index, 'w', encoding='utf-8').write(''.join(out))
    print(f'{index}: {changed} rows updated', file=sys.stderr)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    main(sys.argv[1], sys.argv[2:])
