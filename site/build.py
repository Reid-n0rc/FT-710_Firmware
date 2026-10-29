#!/usr/bin/env python3
"""Assemble the GitHub Pages source in _build/ (run by .github/workflows/pages.yml, then built by Jekyll).

Usage: python3 -I site/build.py [OUTDIR]

- Copies site/ (landing page, layout, stylesheet, Jekyll config) and docs/guide/img/ (figures).
- Puts the progress block of README.md (written by tools/readability_stats.py) into the landing page, as HTML, at the
  `<!-- progress: ... -->` placeholder.
- Turns the CAT documents in PAGES into Jekyll pages: front matter is added, links between them point to the .html pages,
  links to the guide go to the wiki, and every other relative link goes to the file on GitHub.
The Markdown in docs/ stays the single source; nothing here is edited by hand in _build/.
"""
import html
import importlib.util
import os
import re
import shutil
import sys

REPO = "https://github.com/Reid-n0rc/FT-710_Firmware"
WIKI = REPO + "/wiki"
PAGES = {  # docs file -> (page title, short description)
    "cat-undocumented.md": ("Undocumented CAT commands: risks, paths back and backups",
                            "What each undocumented FT-710 CAT command changes, how to undo it, and how to back up first."),
    "cat-commands.md": ("CAT commands: every command in MAIN V01-12",
                        "All 114 CAT commands the FT-710 firmware accepts, with the 22 undocumented ones in detail."),
    "cat-commands-primary.md": ("CAT primary commands: firmware details",
                                "Per-command firmware details of the 104 main-table CAT commands."),
}
WIKI_CHAPTER = {"5": "05-CAT-remote-control", "8": "08-Hacking-and-custom-firmware"}


def fix_link(target):
    if re.match(r"[a-z]+:|#", target):
        return target
    path, _, anchor = target.partition("#")
    if path in PAGES:
        return path[:-3] + ".html" + ("#" + anchor if anchor else "")
    if path == "guide/README.md":
        page = WIKI_CHAPTER.get(anchor[:1]) if anchor else None
        return f"{WIKI}/{page}#{anchor}" if page else WIKI
    full = os.path.normpath(os.path.join("docs", path))
    return f"{REPO}/blob/main/{full}" + ("#" + anchor if anchor else "")


def convert(src, title, desc):
    text = open(src, encoding="utf-8").read()
    text = re.sub(r"\]\(([^)\s]+)\)", lambda m: "](" + fix_link(m.group(1)) + ")", text)
    text = re.sub(r"\A# .*\n", "", text)  # the layout prints the title
    front = f"---\nlayout: doc\ntitle: \"{title}\"\ndescription: \"{desc}\"\nsource: docs/{os.path.basename(src)}\n---\n"
    return front + text


def inline(md):
    """The Markdown inline subset the progress block uses: `code`, **bold**, *italic*, [text](url)."""
    out = html.escape(md, quote=False)
    out = re.sub(r"`([^`]+)`", r"<code>\1</code>", out)
    out = re.sub(r"\*\*(.+?)\*\*", r"<strong>\1</strong>", out)
    out = re.sub(r"(?<![*\w])\*([^*]+)\*(?![*\w])", r"<em>\1</em>", out)
    return re.sub(r"\[([^\]]+)\]\(([^)\s]+)\)", r'<a href="\2">\1</a>', out)


def progress_html():
    spec = importlib.util.spec_from_file_location("readability_stats", "tools/readability_stats.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    md = mod.published_block(REPO + "/blob/main/")
    parts = []
    for para in re.split(r"\n\s*\n", md):
        lines = [ln.strip() for ln in para.strip().splitlines()]
        if lines and lines[0].startswith("|"):
            cells = [[c.strip() for c in ln.strip("|").split("|")] for ln in lines if not re.match(r"^\|[-:| ]+\|$", ln)]
            head = "".join(f"<th>{inline(c)}</th>" for c in cells[0])
            body = "".join("<tr>" + "".join(f"<td>{inline(c)}</td>" for c in r) + "</tr>" for r in cells[1:])
            parts.append(f"<table><thead><tr>{head}</tr></thead><tbody>{body}</tbody></table>")
        elif lines:
            cls = ' class="note"' if lines[0].startswith("*") and not lines[0].startswith("**") else ""
            parts.append(f"<p{cls}>{inline(' '.join(lines))}</p>")
    return "\n        ".join(parts)


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else "_build"
    shutil.rmtree(out, ignore_errors=True)
    shutil.copytree("site", out, ignore=shutil.ignore_patterns("build.py", "__pycache__"))
    shutil.copytree("docs/guide/img", os.path.join(out, "img"))
    index = os.path.join(out, "index.html")
    page = open(index, encoding="utf-8").read()
    page = re.sub(r"<!-- progress:[^>]*-->", lambda m: progress_html(), page, count=1)
    open(index, "w", encoding="utf-8").write(page)
    for name, (title, desc) in PAGES.items():
        with open(os.path.join(out, name), "w", encoding="utf-8") as f:
            f.write(convert(os.path.join("docs", name), title, desc))
    print(f"{len(PAGES)} pages + landing page -> {out}")


if __name__ == "__main__":
    main()
