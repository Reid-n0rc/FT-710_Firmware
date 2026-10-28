#!/usr/bin/env python3
"""Function-level before/after diff of two decomp/<image> exports (T22e, #104).

Usage:
  python3 -I tools/decomp_behavior_diff.py BEFORE_DIR AFTER_DIR OUT.tsv [--marked FILE] [--locked TSV] [--label NAME]

BEFORE_DIR / AFTER_DIR hold an ExportDecomp.java export (`*.c` chunks + `functions.tsv`), e.g. extracted from git with
`git archive <commit> decomp/main | tar -x -C <dir>`. Functions are split at the `// ===== name @ addr (N bytes)` markers
and keyed by entry address, so renamed chunk files do not matter.

--marked FILE: entry addresses (one hex per line) of functions that contain an instruction whose SLEIGH decoding was
fixed (for MAIN: XCHG, SCcnd, MUL dsp[].UB and the string ops, from rx-elf-objdump).

--locked TSV: functions whose prototype was locked (first column = hex entry, `#` comments), e.g.
tools/ghidra/signatures_main.tsv; a caller of one counts as `signature` even when the callee's text did not change.

Each changed function gets one primary class, tested in this order (the first that applies wins):
  renamed_moved  identical after mapping every function name to its entry address, auto labels (DAT_x, s_.._x, PTR_..)
                 to their address, and dropping comments and blank space
  bundles        the before side had halt_baddata() / a bad-instruction warning and the after side has fewer (HiFi4)
  insn           a fixed instruction is in the function (--marked) or the before side had an unimplemented instruction
  jumptable      more `switch` statements, or a "Could not recover jumptable" warning went away
  stack          a spacebase warning went away or fewer distinct in_/unaff_/extraout_ variables
  boundary       the function size changed
  signature      the function's own prototype or the prototype of one of its callees changed or is --locked
  callee_new     it calls a function that exists only on the after side
  data           string literals or labels it refers to changed (DefineRomData)
  other          none of the above: needs a look
Review flags (any class): lost_call=<callees called before but not after, by entry address>, dropped_result=<callees
whose result is used before but whose call became a bare statement after>, fewer_args=<callees passed fewer
arguments after than before (largest count over the call sites)>, lost_strings=<n> (string literals no longer
shown; string_as_int when the after side has address-sized constants instead), new_calls=<n>. Only calls to functions
count (names mapped to F_<entry>, `func_0x...` too); pcodeops such as flix(), memw(), smovf() do not.
Also writes a summary to stdout. Stdlib only.
"""
import collections
import os
import re
import sys

MARK = re.compile(r'^// ===== (\S+) @ ([0-9a-f]+) \((\d+) bytes\)', re.M)
KEYWORDS = {'if', 'while', 'for', 'do', 'switch', 'case', 'return', 'break', 'goto', 'default', 'else', 'sizeof',
            'continue'}
AUTO = re.compile(r'\b(?:[A-Za-z_]\w*?_|[a-z]{1,3}Ram)([0-9a-f]{8})\b')
IDENT = re.compile(r'\b[A-Za-z_]\w*\b')
CALL = re.compile(r'\b([A-Za-z_]\w*)\s*\(')
STRLIT = re.compile(r'"(?:[^"\\]|\\.)*"')


def load(d):
    funcs = {}
    for fn in sorted(os.listdir(d)):
        if not fn.endswith('.c'):
            continue
        text = open(os.path.join(d, fn), encoding='utf-8', errors='replace').read()
        ms = list(MARK.finditer(text))
        for i, m in enumerate(ms):
            end = ms[i + 1].start() if i + 1 < len(ms) else len(text)
            funcs[int(m.group(2), 16)] = (m.group(1), int(m.group(3)), text[m.end():end], fn)
    return funcs


def strip_comments(t):
    t = re.sub(r'/\*.*?\*/', ' ', t, flags=re.S)
    return re.sub(r'//[^\n]*', ' ', t)


class Norm:
    def __init__(self, funcs):
        self.name2addr = {v[0]: a for a, v in funcs.items()}
        self.entries = set(funcs)

    def sub_names(self, t, all_entries):
        def auto(m):
            a = int(m.group(1), 16)
            return ('F_%x' % a) if a in all_entries else ('G_%x' % a)

        t = AUTO.sub(auto, t)
        t = re.sub(r'\bfunc_0x([0-9a-f]+)\b', lambda m: 'F_%x' % int(m.group(1), 16), t)

        def nm(m):
            w = m.group(0)
            a = self.name2addr.get(w)
            return ('F_%x' % a) if a is not None else w

        return IDENT.sub(nm, t)


def compact(t):
    return re.sub(r'\s+', '', t)


def prototype(body):
    """first declaration line: text up to the first '{' after comments removed"""
    b = strip_comments(body)
    i = b.find('{')
    return b[:i] if i >= 0 else b


def calls(t):
    return [c for c in CALL.findall(t) if c not in KEYWORDS]


def arities(t):
    """callee -> set of argument counts over all its call sites in t"""
    out = collections.defaultdict(set)
    for m in CALL.finditer(t):
        k = m.group(1)
        if not k.startswith('F_'):
            continue
        depth, n, i, empty = 1, 0, m.end(), True
        while i < len(t) and depth:
            c = t[i]
            if c in '([{':
                depth += 1
            elif c in ')]}':
                depth -= 1
            elif c == ',' and depth == 1:
                n += 1
            elif not c.isspace() and depth == 1:
                empty = False
            i += 1
        out[k].add(0 if empty and n == 0 else n + 1)
    return out


def stmt_calls(t):
    return re.findall(r'^\s*([A-Za-z_]\w*)\s*\([^;]*\);\s*$', t, re.M)


def warn(body, pat):
    return len(re.findall(pat, body))


def unaff(body):
    return len(set(re.findall(r'\b(?:in|unaff|extraout)_\w+', body)))


def main(argv):
    args = [a for a in argv[1:]]
    marked, label = set(), ''
    if '--marked' in args:
        i = args.index('--marked')
        marked = {int(x, 16) for x in open(args[i + 1]).read().split()}
        del args[i:i + 2]
    locked = set()
    if '--locked' in args:
        i = args.index('--locked')
        locked = {int(l.split('\t')[0], 16) for l in open(args[i + 1]) if l.strip() and not l.startswith('#')}
        del args[i:i + 2]
    if '--label' in args:
        i = args.index('--label')
        label = args[i + 1]
        del args[i:i + 2]
    if len(args) != 3:
        sys.exit(__doc__)
    before, after = load(args[0]), load(args[1])
    nb, na = Norm(before), Norm(after)
    all_entries = set(before) | set(after)

    def n1(norm, body):
        return norm.sub_names(strip_comments(body), all_entries)

    protos_b = {a: compact(n1(nb, prototype(v[2]))) for a, v in before.items()}
    protos_a = {a: compact(n1(na, prototype(v[2]))) for a, v in after.items()}
    rows, counts = [], collections.Counter()
    flagcount = collections.Counter()
    for a in sorted(all_entries):
        if a not in after:
            rows.append((a, before[a][0], '', before[a][1], '', 'removed', ''))
            counts['removed'] += 1
            continue
        if a not in before:
            rows.append((a, '', after[a][0], '', after[a][1], 'added', ''))
            counts['added'] += 1
            continue
        (nmb, szb, bb, _), (nma, sza, ba, _) = before[a], after[a]
        if bb == ba:
            counts['unchanged'] += 1
            continue
        tb, ta = n1(nb, bb), n1(na, ba)
        flags = []
        cb, ca = collections.Counter(calls(tb)), collections.Counter(calls(ta))
        lost = sorted(k for k in cb if k not in ca and k.startswith('F_'))
        if lost:
            flags.append('lost_call=' + ','.join(lost))
        newc = sum(1 for k in ca if k not in cb)
        if newc:
            flags.append('new_calls=%d' % newc)
        arb, ara = arities(tb), arities(ta)
        fewer = sorted(k for k in arb if k in ara and max(ara[k]) < max(arb[k]))
        if fewer:
            flags.append('fewer_args=' + ','.join(fewer))
        sb, sa = collections.Counter(stmt_calls(tb)), collections.Counter(stmt_calls(ta))
        dropped = sorted(k for k in sa if k in cb and k.startswith('F_') and sa[k] > sb.get(k, 0)
                         and cb[k] - sb.get(k, 0) > ca[k] - sa[k])
        if dropped:
            flags.append('dropped_result=' + ','.join(dropped))
        strb, stra = set(STRLIT.findall(tb)), set(STRLIT.findall(ta))
        if strb - stra:
            flags.append('lost_strings=%d' % len(strb - stra))
            if re.search(r'\b0x[0-9a-f]{6,8}\b', ta):
                flags.append('string_as_int')
        if compact(tb) == compact(ta):
            cls = 'renamed_moved'
        else:
            bad_b = warn(bb, r'halt_baddata\(') + warn(bb, r'Bad instruction')
            bad_a = warn(ba, r'halt_baddata\(') + warn(ba, r'Bad instruction')
            callee_protos = any(protos_b.get(int(k[2:], 16)) != protos_a.get(int(k[2:], 16))
                                or int(k[2:], 16) in locked
                                for k in set(cb) | set(ca) if k.startswith('F_') and int(k[2:], 16) in before
                                and int(k[2:], 16) in after)
            if bad_b > bad_a:
                cls = 'bundles'
            elif a in marked or warn(bb, r'[Uu]nimplemented instruction') > warn(ba, r'[Uu]nimplemented instruction'):
                cls = 'insn'
            elif ba.count('switch') > bb.count('switch') or \
                    warn(bb, 'Could not recover jumptable') > warn(ba, 'Could not recover jumptable'):
                cls = 'jumptable'
            elif warn(bb, 'spacebase') > warn(ba, 'spacebase') or unaff(bb) > unaff(ba):
                cls = 'stack'
            elif szb != sza:
                cls = 'boundary'
            elif protos_b[a] != protos_a[a] or a in locked or callee_protos:
                cls = 'signature'
            elif any(k.startswith('F_') and int(k[2:], 16) not in before for k in ca):
                cls = 'callee_new'
            elif strb != stra or set(re.findall(r'G_[0-9a-f]+', tb)) != set(re.findall(r'G_[0-9a-f]+', ta)):
                cls = 'data'
            else:
                cls = 'other'
        counts[cls] += 1
        for f in flags:
            flagcount[f.split('=')[0]] += 1
        rows.append((a, nmb, nma, szb, sza, cls, ';'.join(flags)))
    with open(args[2], 'w') as f:
        f.write('entry\tname_before\tname_after\tsize_before\tsize_after\tclass\tflags\n')
        for r in rows:
            f.write('%08x\t%s\t%s\t%s\t%s\t%s\t%s\n' % r)
    print('%s: before %d, after %d functions' % (label or args[1], len(before), len(after)))
    for k in ('unchanged', 'renamed_moved', 'bundles', 'insn', 'jumptable', 'stack', 'boundary', 'signature',
              'callee_new', 'data', 'other', 'added', 'removed'):
        print('  %-14s %6d' % (k, counts[k]))
    print('  flags: ' + ', '.join('%s %d' % kv for kv in sorted(flagcount.items())))


if __name__ == '__main__':
    main(sys.argv)
