#!/usr/bin/env python3
"""Assemble the GitHub Pages source in _build/ (run by .github/workflows/pages.yml, then built by Jekyll).

Usage: python3 -I site/build.py [OUTDIR]

- Copies site/ (landing page, layout, stylesheet, Jekyll config) and docs/guide/img/ (figures).
- Turns the CAT documents in PAGES into Jekyll pages: front matter is added, links between them point to the .html pages,
  links to the guide go to the wiki, and every other relative link goes to the file on GitHub.
The Markdown in docs/ stays the single source; nothing here is edited by hand in _build/.
"""
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


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else "_build"
    shutil.rmtree(out, ignore_errors=True)
    shutil.copytree("site", out, ignore=shutil.ignore_patterns("build.py", "__pycache__"))
    shutil.copytree("docs/guide/img", os.path.join(out, "img"))
    for name, (title, desc) in PAGES.items():
        with open(os.path.join(out, name), "w", encoding="utf-8") as f:
            f.write(convert(os.path.join("docs", name), title, desc))
    print(f"{len(PAGES)} pages + landing page -> {out}")


if __name__ == "__main__":
    main()
