#!/usr/bin/env python3
"""Convert between the IFDSP Ghidra name scripts (IfdspM33Names.java / IfdspHifi4Names.java) and TSV (T17).

  python3 -I tools/ifdsp_names_java.py totsv  Script.java out.tsv
      NAMES = {...} entries -> address<TAB>name<TAB>comment ('// section' lines become '# --- section')
  python3 -I tools/ifdsp_names_java.py split  names_ifdsp.T12x.tsv out_m33.tsv out_hifi4.tsv
      split a proposal TSV by program: '# program: m33|hifi4' markers if present, else by address
      (M33: < 0x00100000 or >= 0x08000000; HiFi4: everything else)
  python3 -I tools/ifdsp_names_java.py tojava Script.java names.tsv
      rewrite the NAMES array of Script.java from names.tsv (comments become the plate comment, 3rd element)
"""
import re
import sys

ENTRY = re.compile(r'^\s*\{0x([0-9A-Fa-f]+)L,\s*"([^"]+)"(?:,\s*"((?:[^"\\]|\\.)*)")?\},?\s*(?://\s*(.*))?$')


def names_block(src):
    i = src.index('static final Object[][] NAMES = {')
    j = src.index('\n    };', i)
    return i, j


def totsv(java, out):
    src = open(java, encoding='utf-8').read()
    i, j = names_block(src)
    lines = []
    for line in src[i:j].splitlines()[1:]:
        m = ENTRY.match(line)
        if m:
            com = (m.group(3) or '').replace('\\"', '"').replace('\\\\', '\\')
            lines.append(f'{m.group(1).lower().zfill(8)}\t{m.group(2)}\t{com}'.rstrip('\t'))
        elif line.strip().startswith('//'):
            lines.append('# --- ' + line.strip()[2:].strip())
    open(out, 'w', encoding='utf-8').write('\n'.join(lines) + '\n')


def split(tsv, m33, hifi):
    prog = None
    o = {'m33': [], 'hifi4': []}
    for line in open(tsv, encoding='utf-8'):
        line = line.rstrip('\n')
        mk = re.match(r'#\s*program:\s*(m33|hifi4)', line)
        if mk:
            prog = mk.group(1)
            continue
        if not line.strip() or line.startswith('#'):
            continue
        a = int(line.split('\t')[0], 16)
        p = prog or ('m33' if a < 0x00100000 or a >= 0x08000000 else 'hifi4')
        o[p].append(line)
    open(m33, 'w', encoding='utf-8').write('\n'.join(o['m33']) + ('\n' if o['m33'] else ''))
    open(hifi, 'w', encoding='utf-8').write('\n'.join(o['hifi4']) + ('\n' if o['hifi4'] else ''))


def jstr(s):
    return '"' + s.replace('\\', '\\\\').replace('"', '\\"') + '"'


def tojava(java, tsv):
    src = open(java, encoding='utf-8').read()
    i, j = names_block(src)
    body = ['    static final Object[][] NAMES = {']
    for line in open(tsv, encoding='utf-8'):
        line = line.rstrip('\n')
        if not line.strip():
            continue
        if line.startswith('#'):
            t = re.sub(r'^#\s*(---\s*)?', '', line)
            body.append('        // ' + t)
            continue
        p = line.split('\t')
        a = int(p[0], 16)
        com = '\t'.join(p[2:]).strip() if len(p) > 2 else ''
        if com:
            body.append(f'        {{0x{a:08X}L, {jstr(p[1])}, {jstr(com)}}},')
        else:
            body.append(f'        {{0x{a:08X}L, {jstr(p[1])}}},')
    src = src[:i] + '\n'.join(body).lstrip() + src[j:]
    open(java, 'w', encoding='utf-8').write(src)


if __name__ == '__main__':
    a = sys.argv
    if len(a) == 4 and a[1] == 'totsv':
        totsv(a[2], a[3])
    elif len(a) == 5 and a[1] == 'split':
        split(a[2], a[3], a[4])
    elif len(a) == 4 and a[1] == 'tojava':
        tojava(a[2], a[3])
    else:
        sys.exit(__doc__)
