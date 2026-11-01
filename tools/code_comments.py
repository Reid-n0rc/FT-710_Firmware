#!/usr/bin/env python3
"""Inputs and checks for the inline comments in the decompiled code (T23i; applied by tools/ghidra/CommentCode.java).

Usage:
  python3 -I tools/code_comments.py purposes [image ...]   (re)write tools/ghidra/purposes_<image>.tsv
  python3 -I tools/code_comments.py check [image ...]      purposes_<image>.tsv up to date, comments_<image>.tsv well formed;
                                                           exit 1 otherwise
  python3 -I tools/code_comments.py stats [image ...]      comments printed in the committed export, by kind

Images: main, display, m33, hifi4 (decomp/main, decomp/display, decomp/ifdsp/m33, decomp/ifdsp/hifi4).

purposes_<image>.tsv (generated, never edit): address, name, short purpose, tag. One row per function whose row in a
docs/code/ function table (found the way tools/readable_view.py assigns them) has a purpose that shortens well:
  - the first purpose-like column (Purpose, What it computes, Role, Notes, ...), without tags, issue numbers, links,
    backticks and a leading "(args):" or "Name:" ;
  - cut at the first clause break ("; ", ": ", " — ", ". ", " (", ", then ");
  - kept only when it has 3..9 words and at most 56 characters, is not boilerplate (library matches, "code shape" rows,
    menu-item rows, CAT handler rows) and says more than the function's name (under half of its words in the name);
  - kept only when the table row carries [fact] or [inference] (an untagged row is not evidence; a [guess] row neither).
    tag = fact when the row has only [fact], else inference (CommentCode.java prints "[doc]" / "[doc, inference]").
CommentCode.java comments the first call of each such function in every caller.

comments_<image>.tsv (curated, by hand): address<TAB>comment<TAB>evidence, '#' lines are comments. The address is an
instruction inside a function (not its entry); the comment is one short line; evidence is "[fact: <address or doc>]" or
"[inference: <reason>]" / "[inference]". `check` tests the form; CommentCode.java tests the address against the program.
"""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, 'tools'))
import readable_view as rv  # noqa: E402

IMAGES = {'main': 'main', 'display': 'display', 'm33': 'ifdsp/m33', 'hifi4': 'ifdsp/hifi4'}
GHIDRA = os.path.join(REPO, 'tools', 'ghidra')
PURPOSE_COLS = ('purpose', 'what it computes', 'role', 'notes', 'payload and effect', 'function', 'what it does')
BOILER = re.compile(r'library function|matched by|code shape|^menu item|handler of cat command|^calls \w+$|callers?:|'
                    r'^frame 0x|^see |^same as|^as |^no direct calls|^\W*$|^entry of|names-file group|entry \d+ of 0x|'
                    r'code generator|smart configurator|^EX\d{6}\b|unused$|wrappers?$|helpers?$|^getters|^setters|'
                    r'^calls |^same\b|constants equal|^body is|^answer to|^0x|\w\(', re.I)
FRAGMENT = re.compile(r'^(\(|in |when |if |for |at |with |which\b|side\b|param|p\d\b|[0-9]+ (when|if|voice)\b)|'
                      r'\b(the|of|a|an|to|when|if|and|or|with|by|at)$|[A-Za-z]+_\w+ when |^called\b|^while\b|^accessors\b|^\d+ for\b|\bsame\b|param_\d|'
                      r'^tail call|^\{|[+=]$', re.I)
STOP = {'the', 'a', 'an', 'of', 'to', 'and', 'or', 'in', 'on', 'for', 'by', 'with', 'from', 'at', 'is', 'it', 'its',
        'into', 'per', 'as', 'when', 'if', 'then', 'one', 'all', 'set', 'get', 'sets', 'gets'}
MAX_WORDS, MIN_WORDS, MAX_CHARS = 9, 3, 56
CURATED_EVIDENCE = re.compile(r'^\[(fact:\s[^\]]+|inference(:\s[^\]]+)?)\]$')
MAX_COMMENT = 74  # Ghidra wraps a PRE comment longer than this (line width 100, comment indent 20)


def name_words(name):
    s = re.sub(r'([a-z0-9])([A-Z])', r'\1_\2', name)
    return {w.lower() for w in re.split(r'[_\W]+', s) if w}


def shorten(text):
    t = re.sub(r'\[(fact|inference|guess)[^\]]*\]', '', text, flags=re.I)
    t = re.sub(r'\((?:#\d+|T\d+[a-z]?\d*)(?:[,;][^)]*)?\)', '', t)
    t = re.sub(r'#\d+', '', t)
    t = t.replace('`', '').replace('**', '').replace('*', '')
    t = re.sub(r'^\s*\([^)]*\)\s*:\s*', '', t)          # "(dir): next entry" -> "next entry"
    t = re.sub(r'^\s*[A-Za-z_][\w.]*\s*:\s+', '', t)     # "XOS: as ..." / "fsl_crc.c: ..." -> rest
    t = re.sub(r'\s+', ' ', t).strip()
    cut = re.split(r'; |: | — | – |\. | \(|, then | -> | → ', t, maxsplit=1)[0]
    cut = cut.strip(' ,.;:-')
    return cut


def accept(short, fname):
    if not short or BOILER.search(short):
        return False
    words = short.split()
    if not MIN_WORDS <= len(words) <= MAX_WORDS or len(short) > MAX_CHARS:
        return False
    if not re.search(r'[a-z]{3}', short):  # needs prose, not just registers/numbers
        return False
    if FRAGMENT.search(short) or (' = ' in short and len(words) < 5):  # a clause that needs its context
        return False
    content = [w.lower().strip('(),.;:') for w in words]
    content = [w for w in content if len(w) >= 2 and w not in STOP and not w.isdigit()]
    if not content:
        return False
    nw = name_words(fname)
    overlap = sum(1 for w in content if w in nw or w.rstrip('s') in nw)
    return overlap / len(content) < 0.5


def purposes(image):
    img = IMAGES[image]
    funcs, _ = rv.load_export(os.path.join(REPO, 'decomp', img))
    hits, _ = rv.assign(funcs, os.path.join(REPO, 'docs', 'code', rv.IMAGES[img]))
    rows = []
    for a in sorted(hits):
        page, e = hits[a][0]
        if len(e['addrs']) != 1 or e.get('ranged'):  # a row for several functions describes the group
            continue
        tags = e['tags']
        if not tags or 'guess' in tags:
            continue
        tag = 'fact' if tags == ['fact'] else 'inference'
        text = None
        for lab, txt in e['extra']:
            if lab.lower().strip() in PURPOSE_COLS:
                text = txt
                break
        if text is None and len(e['extra']) == 1:
            text = e['extra'][0][1]
        if not text:
            continue
        short = shorten(text)
        if not accept(short, funcs[a]['name']):
            continue
        rows.append((a, funcs[a]['name'], short, tag, page))
    return rows


def purposes_text(image):
    rows = purposes(image)
    out = [f'# Short purposes of documented functions, image {image} (T23i). GENERATED by tools/code_comments.py purposes',
           f'# from docs/code/{rv.IMAGES[IMAGES[image]]}/*.md function tables and decomp/{IMAGES[image]}/functions.tsv. '
           'Do not edit: fix the doc row, rerun.',
           '# Applied by tools/ghidra/CommentCode.java as a comment above the first call of each function in every caller.',
           '# address\tname\tpurpose\ttag (fact / inference, from the doc row)\tdoc page']
    out += [f'{a:08x}\t{n}\t{s}\t{t}\t{p}' for a, n, s, t, p in rows]
    return '\n'.join(out) + '\n', len(rows)


def check_curated(image):
    path = os.path.join(GHIDRA, f'comments_{image}.tsv')
    if not os.path.exists(path):
        return []
    errs, seen = [], set()
    with open(path, encoding='utf-8') as f:
        for n, line in enumerate(f, 1):
            line = line.rstrip('\n')
            if not line.strip() or line.startswith('#'):
                continue
            p = line.split('\t')
            where = f'{os.path.relpath(path, REPO)}:{n}'
            if len(p) != 3:
                errs.append(f'{where}: need 3 columns, got {len(p)}')
                continue
            if not re.fullmatch(r'(0x)?[0-9a-fA-F]{1,8}', p[0]):
                errs.append(f'{where}: bad address {p[0]!r}')
            if p[0].lower() in seen:
                errs.append(f'{where}: address {p[0]} twice (put both steps in one comment)')
            seen.add(p[0].lower())
            if not CURATED_EVIDENCE.match(p[2].strip()):
                errs.append(f'{where}: evidence must be [fact: ...] or [inference] / [inference: ...]')
            if '[guess' in line.lower():
                errs.append(f'{where}: no [guess] (AGENTS.md)')
            if len(p[1]) + 1 + len(p[2]) > MAX_COMMENT:
                errs.append(f'{where}: comment + evidence longer than {MAX_COMMENT} characters')
            if re.search(r'\[(fact|inference|sfr|doc|enum)', p[1]):
                errs.append(f'{where}: the comment column must not carry a tag (it goes in column 3)')
    return errs


INLINE = re.compile(r'^\s*/\* (.*?) \*/\s*$')
TAGGED = re.compile(r'\[(sfr|enum|doc|doc, inference|fact:\s[^\]]+|inference(:\s[^\]]+)?)\]$')


def export_comments(img_dir):
    """Per function (addr): list of the inline comments printed inside its body (after the opening brace),
    not counting decompiler warnings."""
    funcs, _ = rv.load_export(img_dir)
    out = {}
    for a, f in funcs.items():
        body = f['text']
        i = body.find('\n{\n')
        if i < 0:
            continue
        lst = []
        for line in body[i:].split('\n'):
            m = INLINE.match(line)
            if m and not m.group(1).startswith('WARNING'):
                lst.append(m.group(1))
        out[a] = lst
    return funcs, out


def stats(image):
    funcs, com = export_comments(os.path.join(REPO, 'decomp', IMAGES[image]))
    kinds = {}
    for lst in com.values():
        for c in lst:
            m = TAGGED.search(c)
            k = m.group(1) if m else 'other'
            k = 'fact' if k.startswith('fact') else 'inference' if k.startswith('inference') else k
            kinds[k] = kinds.get(k, 0) + 1
    with_c = sum(1 for lst in com.values() if lst)
    return len(funcs), with_c, kinds


def main(argv):
    mode = argv[0] if argv else 'check'
    images = argv[1:] or list(IMAGES)
    for im in images:
        if im not in IMAGES:
            raise SystemExit(f'unknown image {im}; one of {", ".join(IMAGES)}')
    rc = 0
    for im in images:
        if mode == 'purposes':
            text, n = purposes_text(im)
            with open(os.path.join(GHIDRA, f'purposes_{im}.tsv'), 'w', encoding='utf-8') as f:
                f.write(text)
            print(f'{im}: {n} short purposes -> tools/ghidra/purposes_{im}.tsv')
        elif mode == 'check':
            text, _ = purposes_text(im)
            path = os.path.join(GHIDRA, f'purposes_{im}.tsv')
            cur = open(path, encoding='utf-8').read() if os.path.exists(path) else ''
            if cur != text:
                print(f'{im}: tools/ghidra/purposes_{im}.tsv is stale (rerun `python3 -I tools/code_comments.py purposes {im}`)')
                rc = 1
            errs = check_curated(im)
            for e in errs:
                print(e)
            rc |= 1 if errs else 0
            if not errs and cur == text:
                print(f'{im}: ok')
        elif mode == 'stats':
            n, w, kinds = stats(im)
            print(f'{im}: {w} of {n} functions with an inline comment; ' +
                  ', '.join(f'{k} {v}' for k, v in sorted(kinds.items())))
        else:
            raise SystemExit(__doc__)
    return rc


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
