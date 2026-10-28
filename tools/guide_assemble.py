#!/usr/bin/env python3
"""Assemble the illustrated guide (T19) into one document.

Usage: python3 -I tools/guide_assemble.py [--check]

Reads docs/guide/intro.md (title, how-to-read, overview), the chapter drafts docs/guide/parts/NN-*.md and the
`## Glossary terms` lists in docs/tasks/T19?-*.md, and writes docs/guide/README.md:
title + intro, a generated table of contents, the chapters in number order, and an alphabetical glossary.
It also rewrites links to chapter anchors that a chapter guessed (for example `#4-firmware-files-and-updates`) to the
real heading anchor with the same chapter number, and reports links, images and figure numbers it cannot resolve.
With --check it only reports.
"""
import glob
import os
import re
import sys

GUIDE = "docs/guide"


def slug(heading):
    """GitHub's heading-anchor rule."""
    s = re.sub(r"[^\w\- ]", "", heading.strip().lower())
    return s.replace(" ", "-")


def headings(text):
    out, fence = [], False
    for ln in text.splitlines():
        if ln.startswith("```"):
            fence = not fence
        m = None if fence else re.match(r"(#{2,4})\s+(.*)", ln)
        if m:
            out.append((len(m.group(1)), m.group(2).strip()))
    return out


def glossary():
    terms = {}
    for f in sorted(glob.glob("docs/tasks/T19?-*.md")):
        on = False
        for ln in open(f, encoding="utf-8"):
            if ln.startswith("## "):
                on = ln.strip().lower() == "## glossary terms"
                continue
            m = re.match(r"\s*[-*]\s+\**(.+?)\**\s+[—–-]{1,2}\s+(.+)", ln) if on else None
            if m:
                term, text = m.group(1).strip(" `"), m.group(2).strip()
                text = text[0].upper() + text[1:]
                if not text.endswith("."):
                    text += "."
                key = term.lower()
                if key not in terms or len(text) > len(terms[key][1]):
                    terms[key] = (term, text)
    return [terms[k] for k in sorted(terms, key=lambda k: re.sub(r"[^a-z0-9]", "", k))]


def main():
    check = "--check" in sys.argv
    parts = sorted(glob.glob(f"{GUIDE}/parts/[0-9][0-9]-*.md"))
    chapters = [open(p, encoding="utf-8").read().strip() + "\n" for p in parts]
    intro = open(f"{GUIDE}/intro.md", encoding="utf-8").read().strip() + "\n"
    gloss = glossary()

    toc = ["## Contents", ""]
    for text in chapters:
        for level, h in headings(text):
            if level == 2:
                toc.append(f"- **[{h}](#{slug(h)})**")
            elif level == 3:
                toc.append(f"  - [{h}](#{slug(h)})")
    toc.append("- **[Glossary](#glossary)**")
    gl = ["## Glossary", "",
          "Short definitions of the terms used in this guide, in alphabetical order.", ""]
    gl += [f"- **{t}**: {d}" for t, d in gloss]
    doc = "\n".join([intro, "\n".join(toc), ""] + chapters + ["\n".join(gl) + "\n"])

    # anchors present in the document
    anchors = {slug(h) for _, h in headings(doc)} | {"contents", "glossary"}
    chap = {}
    for _, h in headings(doc):
        m = re.match(r"(\d+)\.\s", h)
        if m:
            chap.setdefault(m.group(1), slug(h))
    problems = []

    def fix(m):
        label, a = m.group(1), m.group(2)
        if a in anchors:
            return m.group(0)
        n = re.match(r"(\d+)-", a)
        if n and n.group(1) in chap:
            return f"[{label}](#{chap[n.group(1)]})"
        problems.append(f"unresolved anchor #{a} ({label})")
        return m.group(0)

    doc = re.sub(r"\[([^\]]*)\]\(#([^)\s]+)\)", fix, doc)
    for img in re.findall(r"!\[[^\]]*\]\(([^)\s]+)\)", doc):
        if not os.path.exists(os.path.join(GUIDE, img)):
            problems.append(f"missing image {img}")
    for target in re.findall(r"(?<!!)\[[^\]]*\]\(((?:\.\./|\./)[^)#\s]+)", doc):
        if not os.path.exists(os.path.normpath(os.path.join(GUIDE, target))):
            problems.append(f"broken link {target}")
    # figure captions must run 1, 2, 3 ... within each chapter
    last = {}
    for n, k in re.findall(r"^\*Figure (\d+)\.(\d+)\b", doc, re.M):
        if int(k) != last.get(n, 0) + 1:
            problems.append(f"figure {n}.{k} out of sequence (after {n}.{last.get(n, 0)})")
        last[n] = int(k)
    if not check:
        open(f"{GUIDE}/README.md", "w", encoding="utf-8").write(doc)
    figs = len(re.findall(r"!\[", doc)) + doc.count("```mermaid")
    print(f"{len(chapters)} chapters, {len(gloss)} glossary terms, {figs} figures, {len(doc.splitlines())} lines")
    for p in problems:
        print("  " + p)
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
