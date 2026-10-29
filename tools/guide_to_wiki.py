#!/usr/bin/env python3
"""Split the single guide document into GitHub-wiki pages.

Usage: python3 -I tools/guide_to_wiki.py [docs/guide/README.md] [build/wiki]

Input: the guide, with the document title as `# ...`, an intro, a `## Contents` section (skipped: the wiki sidebar replaces it),
and chapters as `## N. Title` (the glossary is the last `##` chapter). Output, in the output directory:
  Home.md         the intro (everything before the first chapter, without the contents list), with the project's progress
                  block from README.md (tools/readability_stats.py) right under the title
  <Chapter>.md    one page per `##` chapter, named after its title (e.g. `1. The radio at a glance` -> `01-The-radio-at-a-glance`)
  _Sidebar.md     table of contents: every chapter with its `###` sections
  img/            copy of docs/guide/img/
Links are rewritten: `#anchor` links go to the page that holds the anchor, and relative links to repo files
(`../code/system.md`) become absolute links to the repo on GitHub, because wiki pages live outside the repo tree.
"""
import importlib.util
import os
import posixpath
import re
import shutil
import sys

REPO_URL = "https://github.com/Reid-n0rc/FT-710_Firmware/blob/main/"
GUIDE_DIR = "docs/guide"


def slug(heading):
    """GitHub's heading-anchor rule: lowercase, drop punctuation except - and _, spaces to -."""
    s = heading.strip().lower()
    s = re.sub(r"[^\w\- ]", "", s)
    return s.replace(" ", "-")


def page_name(title):
    m = re.match(r"(\d+)\.\s*(.*)", title)
    text = m.group(2) if m else title
    name = re.sub(r"[^\w\- ]", "", text).strip().replace(" ", "-")
    return f"{int(m.group(1)):02d}-{name}" if m else name


def split(lines):
    """Return (intro_lines, [(title, lines)]); drops a `## Contents` section."""
    intro, chapters, cur, skipping, in_fence = [], [], None, False, False
    for ln in lines:
        if ln.startswith("```"):
            in_fence = not in_fence
        if not in_fence and ln.startswith("## "):
            title = ln[3:].strip()
            skipping = title.lower() in ("contents", "table of contents")
            cur = None if skipping else (title, [ln])
            if cur:
                chapters.append(cur)
            continue
        if cur:
            cur[1].append(ln)
        elif not skipping and not chapters:
            intro.append(ln)
    return intro, chapters


def progress_md():
    """README.md's progress block with absolute links, as a `## Progress` section ('' if the README has none)."""
    path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "readability_stats.py")
    spec = importlib.util.spec_from_file_location("readability_stats", path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    md = mod.published_block(REPO_URL)
    return f"## Progress\n\n{md}\n" if md else ""


def with_progress(home):
    """Put the progress section right after the page title (the first `# ` line), or first if there is none."""
    block = progress_md()
    if not block:
        return home
    m = re.match(r"(# [^\n]*\n)", home)
    return (m.group(1) + "\n" + block + "\n" + home[m.end():].lstrip("\n")) if m else block + "\n" + home


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else "docs/guide/README.md"
    out = sys.argv[2] if len(sys.argv) > 2 else "build/wiki"
    lines = open(src, encoding="utf-8").read().splitlines()
    intro, chapters = split(lines)

    # anchor -> page, for every heading in every chapter
    where = {}
    for title, body in chapters:
        name = page_name(title)
        in_fence = False
        for ln in body:
            if ln.startswith("```"):
                in_fence = not in_fence
            m = None if in_fence else re.match(r"(#{2,6})\s+(.*)", ln)
            if m:
                where.setdefault(slug(m.group(2)), name)

    def fix_links(text):
        def repl(m):
            label, target = m.group(1), m.group(2)
            if target.startswith("#"):
                page = where.get(target[1:])
                return f"[{label}]({page}{target})" if page else m.group(0)
            if re.match(r"[a-z]+:", target) or target.startswith("img/"):
                return m.group(0)
            return f"[{label}]({REPO_URL}{posixpath.normpath(posixpath.join(GUIDE_DIR, target))})"
        return re.sub(r"(?<!!)\[([^\]]*)\]\(([^)\s]+)\)", repl, text)

    os.makedirs(out, exist_ok=True)
    with open(os.path.join(out, "Home.md"), "w", encoding="utf-8") as f:
        f.write(with_progress(fix_links("\n".join(intro)).strip() + "\n"))
    side = ["**[Home](Home)**", ""]
    for title, body in chapters:
        name = page_name(title)
        with open(os.path.join(out, name + ".md"), "w", encoding="utf-8") as f:
            f.write(fix_links("\n".join(body)).strip() + "\n")
        side.append(f"- **[{title}]({name})**")
        in_fence = False
        for ln in body:
            if ln.startswith("```"):
                in_fence = not in_fence
            m = None if in_fence else re.match(r"###\s+(.*)", ln)
            if m:
                side.append(f"  - [{m.group(1).strip()}]({name}#{slug(m.group(1))})")
    with open(os.path.join(out, "_Sidebar.md"), "w", encoding="utf-8") as f:
        f.write("\n".join(side) + "\n")
    img = os.path.join(os.path.dirname(src), "img")
    if os.path.isdir(img):
        shutil.copytree(img, os.path.join(out, "img"), dirs_exist_ok=True)
    print(f"{len(chapters)} chapter pages + Home + _Sidebar -> {out}")


if __name__ == "__main__":
    main()
