#!/usr/bin/env python3
"""Compare tools/arm_recover.py output with rizin and Ghidra results for the DISPLAY image (T22b, #104). Stdlib only.

Inputs (all optional except --own):
  --own DIR          arm_recover.py output directory (jumptables.tsv, starts.tsv, coverage.tsv)
  --rz-bbs FILE      rizin `afbj @@F` output (one JSON array per function)
  --rz-funcs FILE    rizin `aflj` output
  --ghidra NAME=FILE Ghidra functions.tsv (ExportDecomp.java), repeatable (e.g. canonical=decomp/display/functions.tsv)
  --ghidra-jt FILE   T21e jt_check.tsv (site, form, cond, reg, entries, ...)
  --ghidra-map NAME=FILE CodeUnitMap.java output (start, end, kind[, detail]) per Ghidra project, repeatable
  --out DIR          writes jt_compare.tsv, starts_compare.tsv, gaps_compare.tsv, compare.txt

Usage:
  python3 -I tools/arm_recover_compare.py --own OWN --rz-bbs rz_bbs.jsonl --rz-funcs rz_funcs.json \
      --ghidra canonical=decomp/display/functions.tsv --ghidra t21e=EXP/functions.tsv --ghidra-jt jt_check.tsv \
      --ghidra-map canonical=canon_map.tsv --ghidra-map t21e=t21e_map.tsv --out OUT
"""
import argparse
import collections
import json

TEXT = (0x20100000, 0x20165178)


def rd_tsv(path):
    with open(path) as f:
        hdr = f.readline().rstrip('\n').split('\t')
        return [dict(zip(hdr, l.rstrip('\n').split('\t'))) for l in f if l.strip()]


def rz_load(bbs_path):
    """Returns (code byte set as list of ranges, switch sites {opaddr: [case targets]})."""
    ranges, sw = [], {}
    with open(bbs_path) as f:
        for line in f:
            line = line.strip()
            if not line.startswith('['):
                continue
            for bb in json.loads(line):
                ranges.append((bb['addr'], bb['addr'] + bb['size']))
                if 'switch_op' in bb:
                    s = bb['switch_op']
                    # rizin puts the switch on the block that ends with the computed jump
                    site = s['addr']
                    sw[site] = [c['jump'] for c in s['cases']]
    return ranges, sw


def mark(ranges, n0, n1):
    b = bytearray(n1 - n0)
    for s, e in ranges:
        s, e = max(s, n0), min(e, n1)
        if s < e:
            b[s - n0:e - n0] = b'\x01' * (e - s)
    return b


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--own', required=True)
    ap.add_argument('--rz-bbs')
    ap.add_argument('--rz-funcs')
    ap.add_argument('--ghidra', action='append', default=[])
    ap.add_argument('--ghidra-jt')
    ap.add_argument('--ghidra-map', action='append', default=[])
    ap.add_argument('--out', required=True)
    a = ap.parse_args()
    import os
    os.makedirs(a.out, exist_ok=True)
    rep = []
    # ---------------- jump tables
    own_jt = {int(r['site'], 16): r for r in rd_tsv(f'{a.own}/jumptables.tsv')}
    own_tab = {k: v for k, v in own_jt.items() if v['kind'].startswith(('a32_', 't32_tb'))}
    rz_ranges, rz_sw = rz_load(a.rz_bbs) if a.rz_bbs else ([], {})
    g_jt = {int(r['site'], 16): r for r in rd_tsv(a.ghidra_jt)} if a.ghidra_jt else {}
    sites = sorted(set(own_tab) | set(rz_sw) | set(g_jt))
    agree = collections.Counter()
    with open(f'{a.out}/jt_compare.tsv', 'w') as f:
        f.write('site\town_kind\town_bound\town_cases\trizin_cases\tghidra_t21e_entries\tagree\tnote\n')
        for s in sites:
            o = own_tab.get(s)
            oc = int(o['cases']) if o else None
            rc = len(rz_sw[s]) if s in rz_sw else None
            gc = int(g_jt[s]['entries']) if s in g_jt else None
            note = []
            if o and s in rz_sw:
                ot = o['targets'].split(',') if o['targets'] else []
                rt = ['%08x' % t for t in rz_sw[s]]
                if rt != ot[:len(rt)]:
                    note.append('rizin targets differ')
            vals = [x for x in (oc, rc, gc) if x is not None]
            ok = len(vals) == 3 and len(set(vals)) == 1
            key = 'all3' if ok else ('own=ghidra' if oc is not None and oc == gc else
                                     'own=rizin' if oc is not None and oc == rc else
                                     'rizin=ghidra' if rc is not None and rc == gc else 'differ')
            agree[key] += 1
            f.write('%08x\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' % (s, o['kind'] if o else '-', o['bound'] if o else '-',
                    oc if oc is not None else '-', rc if rc is not None else '-', gc if gc is not None else '-', key,
                    ';'.join(note)))
    rep.append(f'jump-table sites: own {len(own_tab)} ({sum(int(v["cases"]) for v in own_tab.values())} cases), '
               f'rizin switch_op {len(rz_sw)} ({sum(len(v) for v in rz_sw.values())} cases), '
               f'ghidra/T21e {len(g_jt)} ({sum(int(v["entries"]) for v in g_jt.values())} entries)')
    rep.append(f'  agreement per site: {dict(agree)}')
    # ---------------- function starts
    own_st = {}
    for r in rd_tsv(f'{a.own}/starts.tsv'):
        own_st[int(r['addr'], 16)] = r
    sets = {'own': {k for k, r in own_st.items() if r['reached'] == 'y' and TEXT[0] <= k < TEXT[1]}}
    if a.rz_funcs:
        rf = json.load(open(a.rz_funcs))
        sets['rizin'] = {x['offset'] for x in rf if TEXT[0] <= x['offset'] < TEXT[1]}
    for g in a.ghidra:
        name, path = g.split('=', 1)
        sets[name] = {int(r['entry'], 16) for r in rd_tsv(path) if TEXT[0] <= int(r['entry'], 16) < TEXT[1]}
    allk = sorted(set().union(*sets.values()))
    names = list(sets)
    pat = collections.Counter()
    with open(f'{a.out}/starts_compare.tsv', 'w') as f:
        f.write('addr\t' + '\t'.join(names) + '\town_sources\n')
        for k in allk:
            row = ['y' if k in sets[n] else '-' for n in names]
            pat[''.join(row)] += 1
            f.write('%08x\t%s\t%s\n' % (k, '\t'.join(row), own_st[k]['sources'] if k in own_st else '-'))
    rep.append('function starts in .text: ' + ', '.join(f'{n} {len(sets[n])}' for n in names))
    rep.append('  membership patterns (' + ''.join(n[0] for n in names) + ', y = present): ' +
               ', '.join(f'{p.replace("-", ".")} {c}' for p, c in pat.most_common()))
    for i, n in enumerate(names):
        for m in names[i + 1:]:
            rep.append(f'  {n} vs {m}: both {len(sets[n] & sets[m])}, only {n} {len(sets[n] - sets[m])}, '
                       f'only {m} {len(sets[m] - sets[n])}')
    # ---------------- classify own-vs-Ghidra start differences
    n0, n1 = TEXT
    own_cov = rd_tsv(f'{a.own}/coverage.tsv')
    cov_at = []
    for r in own_cov:
        cov_at.append((int(r['start'], 16), int(r['end'], 16), r['class']))
    import bisect
    cstarts = [c[0] for c in cov_at]

    def own_class(x):
        i = bisect.bisect_right(cstarts, x) - 1
        return cov_at[i][2] if i >= 0 else '?'
    xin = collections.defaultdict(set)      # own: target -> kinds of references
    for r in rd_tsv(f'{a.own}/xrefs.tsv'):
        xin[int(r['to'], 16)].add(r['kind'])
    gmap_fn = {}
    for g in a.ghidra_map:
        name, path = g.split('=', 1)
        rows = [(int(r['start'], 16), int(r['end'], 16), r.get('function', '-'), r['kind']) for r in rd_tsv(path)]
        gmap_fn[name] = rows

    def g_func_at(name, x):
        rows = gmap_fn.get(name)
        if not rows:
            return None, None
        i = bisect.bisect_right([r[0] for r in rows], x) - 1 if not hasattr(g_func_at, name) else \
            bisect.bisect_right(getattr(g_func_at, name), x) - 1
        return (rows[i][2], rows[i][3]) if i >= 0 and x < rows[i][1] else (None, None)
    for name in gmap_fn:
        setattr(g_func_at, name, [r[0] for r in gmap_fn[name]])
    with open(f'{a.out}/starts_diff.tsv', 'w') as f:
        f.write('ghidra\taddr\tside\tclass\tdetail\n')
        for g in a.ghidra:
            name, path = g.split('=', 1)
            gf = sorted((int(r['entry'], 16), int(r['size'])) for r in rd_tsv(path) if TEXT[0] <= int(r['entry'], 16) < TEXT[1])
            ge = [x[0] for x in gf]
            cls = collections.Counter()
            for k in sorted(sets['own'] - sets[name]):
                i = bisect.bisect_right(ge, k) - 1
                prev = gf[i] if i >= 0 else None
                src = own_st[k]['sources']
                gfn, gk = g_func_at(name, k)
                refs = ','.join(sorted(xin.get(k, ()))) or 'none'
                if prev and k - prev[0] <= 0x20 and prev[0] not in sets['own'] and gfn == '%08x' % prev[0]:
                    c, d = 'own_late_start', f'ghidra entry {prev[0]:08x} is {k - prev[0]} B earlier'
                elif gfn == '%08x' % k:
                    c, d = 'ghidra_function_not_in_tsv', 'a Ghidra function starts here but functions.tsv omits it (thunk)'
                elif gfn and gfn != '-':
                    c, d = 'in_ghidra_body', f'body of {gfn} ({gk})'
                elif gk is not None:
                    c, d = 'ghidra_' + gk + '_no_function', '-'
                else:
                    c, d = 'outside_map', '-'
                if 'jump' in refs and 'call' not in refs:
                    c += '/tail_target'
                elif set(src.split(',')) - {'has_prologue'} == {'prologue'}:
                    c += '/unreferenced_prologue'
                cls[c] += 1
                f.write(f'{name}\t{k:08x}\town_only\t{c}\t{d}; own sources {src}; own refs {refs}\n')
            for k in sorted(sets[name] - sets['own']):
                oc = own_class(k)
                refs = ','.join(sorted(xin.get(k, ()))) or 'none'
                if k in own_st:
                    c = 'own_start_not_reached'
                elif oc.startswith('code'):
                    c = 'inside_own_code' + ('/own_jump_target' if 'jump' in refs or 'cjump' in refs else
                                             '/no_own_ref' if refs == 'none' else '/' + refs)
                else:
                    c = 'own_' + oc
                cls['g:' + c] += 1
                f.write(f'{name}\t{k:08x}\t{name}_only\t{c}\town refs {refs}\n')
            rep.append(f'  own vs {name} differences by class: {dict(sorted(cls.items()))}')
    # ---------------- coverage / gaps
    own_known = mark([(int(r['start'], 16), int(r['end'], 16)) for r in own_cov if r['class'] not in ('unknown',)], n0, n1)
    maps = {}
    for g in a.ghidra_map:
        name, path = g.split('=', 1)
        rows = rd_tsv(path)
        maps[name] = mark([(int(r['start'], 16), int(r['end'], 16)) for r in rows if r['kind'] != 'undefined'], n0, n1)
    rz_code = mark(rz_ranges, n0, n1) if rz_ranges else None
    data = None
    with open(f'{a.out}/gaps_compare.tsv', 'w') as f:
        f.write('start\tend\tbytes\town_class\n')
        own_class = bytearray(n1 - n0)
        cls_names = sorted({r['class'] for r in own_cov})
        for r in own_cov:
            s, e = int(r['start'], 16), int(r['end'], 16)
            own_class[s - n0:e - n0] = bytes([cls_names.index(r['class'])]) * (e - s)
        for mname, gm in maps.items():
            # bytes that neither rizin (code) nor this Ghidra project (code or data) cover
            i = 0
            tot = collections.Counter()
            nb = 0
            while i < n1 - n0:
                if gm[i] or (rz_code is not None and rz_code[i]):
                    i += 1
                    continue
                j = i
                while j < n1 - n0 and not gm[j] and not (rz_code is not None and rz_code[j]):
                    j += 1
                cc = collections.Counter(cls_names[own_class[x]] for x in range(i, j))
                f.write('%08x\t%08x\t%d\t%s\t%s\n' % (n0 + i, n0 + j, j - i, ','.join(f'{k}:{v}' for k, v in cc.items()),
                                                      mname))
                tot.update(cc)
                nb += 1
                i = j
            rep.append(f'bytes neither rizin (code) nor Ghidra {mname} (code/data) cover: {sum(tot.values())} in {nb} '
                       f'ranges; own class of those bytes: {dict(tot)}')
            own_unk = sum(1 for x in range(n1 - n0) if cls_names[own_class[x]] == 'unknown')
            both = sum(1 for x in range(n1 - n0) if cls_names[own_class[x]] == 'unknown' and not gm[x])
            rep.append(f'  own "unknown" {own_unk} B, of which also undefined in Ghidra {mname}: {both} B')
            g_undef = sum(1 for x in range(n1 - n0) if not gm[x])
            rep.append(f'  Ghidra {mname} undefined bytes in .text: {g_undef}')
    if rz_code is not None:
        rep.append(f'rizin code bytes (function basic blocks) in .text: {sum(rz_code)}')
    rep.append(f'own known (code/data/strings/padding) bytes in .text: {sum(own_known)}')
    open(f'{a.out}/compare.txt', 'w').write('\n'.join(rep) + '\n')
    print('\n'.join(rep))


if __name__ == '__main__':
    main()
