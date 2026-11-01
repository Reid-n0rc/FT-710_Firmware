#!/usr/bin/env python3
"""Check that two decomp exports differ only by renamed identifiers (T23h, tools/ghidra/NameVariables.java).

Usage: python3 -I tools/rename_check.py OLD_DIR NEW_DIR [--show N]
OLD_DIR / NEW_DIR are export directories of one image (decomp/<image>/ or a scratch export). Every function chunk
(split at the `// ===== name @ addr` markers) is tokenized; the two token streams must have the same length and the
same non-identifier tokens, and the identifiers that differ must map one to one inside the function (old -> new and
new -> old both consistent; Ghidra renumbers the default names that are left, uVar2 -> uVar1, which counts as a rename).
The declaration lines at the top of the body are compared as a set after the renames (Ghidra sorts them by name). Anything else (a changed cast, a changed statement, a moved line) is reported as a
structural change. Prints the counts; exits 1 if any function changed structure.
"""
import glob
import os
import re
import sys

TOKEN = re.compile(r'[A-Za-z_][A-Za-z0-9_]*|0x[0-9A-Fa-f]+|\d+|\S')
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*$')
AUTO = re.compile(r"(param_\d+|[a-z]*Var\d+|local_(res)?[0-9a-f]+|[a-z]*StackX?_[0-9a-f]+|stack0x[0-9a-f]+)(_[0-9a-f]+)?$")
MARK = re.compile(r'^// ===== (\S+) @ (\S+)', re.M)


def chunks(d):
    out = {}
    for f in sorted(glob.glob(os.path.join(d, '*.c'))):
        text = open(f, encoding='utf-8', errors='replace').read()
        ms = list(MARK.finditer(text))
        for i, m in enumerate(ms):
            end = ms[i + 1].start() if i + 1 < len(ms) else len(text)
            out[m.group(2)] = (m.group(1), text[m.end():end])
    return out


DECL = re.compile(r'^  (\S.*?)\s*;\s*$')


def split(c):
    """header (signature and comments), declaration lines, body. Ghidra declares every local at the top of the body,
    one per line, sorted by name, so a rename may reorder them: they are compared as a set."""
    lines = c.split('\n')
    try:
        i = lines.index('{')
    except ValueError:
        return c, [], ''
    j = i + 1
    while j < len(lines) and lines[j].strip() and DECL.match(lines[j]):
        j += 1
    if j >= len(lines) or lines[j].strip():  # the declarations end at a blank line; none without one
        j = i + 1
    return '\n'.join(lines[:i + 1]), lines[i + 1:j], '\n'.join(lines[j:])


def compare(a, b):
    """None if b is a consistent renaming of a, else a reason; also returns the rename map."""
    ha, da, ba = split(a)
    hb, db, bb = split(b)
    ta, tb = TOKEN.findall(ha + '\n' + ba), TOKEN.findall(hb + '\n' + bb)
    if len(ta) != len(tb) or len(da) != len(db):
        return f'token count {len(ta)} -> {len(tb)}, declarations {len(da)} -> {len(db)}', {}
    fwd, back = {}, {}
    for x, y in zip(ta, tb):
        if x == y and x not in fwd and y not in back:
            continue
        if not (AUTO.match(x) and IDENT.match(y)):  # only default variable names may change
            return f'{x!r} -> {y!r}', fwd
        if fwd.setdefault(x, y) != y or back.setdefault(y, x) != x:
            return f'inconsistent rename {x!r} -> {y!r}', fwd
    # declarations: the same lines once the body's renames are applied (a declared but unused name maps to itself)
    sa = sorted(' '.join(fwd.get(t, t) for t in TOKEN.findall(x)) for x in da)
    sb = sorted(' '.join(TOKEN.findall(x)) for x in db)
    if sa != sb:
        diff = sorted(set(sa) ^ set(sb))[:2]
        return f'declarations differ: {diff}', fwd
    return None, {k: v for k, v in fwd.items() if k != v}


def main():
    args = sys.argv[1:]
    show = 5
    if '--show' in args:
        i = args.index('--show')
        show = int(args[i + 1])
        del args[i:i + 2]
    if len(args) != 2:
        sys.exit(__doc__)
    old, new = chunks(args[0]), chunks(args[1])
    same = renamed = 0
    bad = []
    for addr in sorted(set(old) | set(new)):
        if addr not in old or addr not in new:
            bad.append((addr, 'function only in one export'))
            continue
        why, ren = compare(old[addr][1], new[addr][1])
        if why:
            bad.append((addr, f'{new[addr][0]}: {why}'))
        elif ren:
            renamed += 1
        else:
            same += 1
    print(f'rename_check: {len(old)} functions: {same} unchanged, {renamed} renamed only, {len(bad)} structural changes')
    for addr, why in bad[:show]:
        print(f'  {addr} {why}')
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
