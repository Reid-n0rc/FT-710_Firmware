# T19 — Illustrated guide for people

**Status:** done · **Depends on:** T01–T18

## Goal
The reference pages (`docs/code/**`, `docs/*.md`) are complete but written for reverse engineers: dense, address-heavy, no pictures. Write
**one document**, `docs/guide/README.md` (GitHub shows it when the folder is opened), a plain-language, illustrated walk-through of the whole radio that a technically curious owner can read front to back,
with many pictures (hand-drawn SVG) and diagrams (Mermaid). The guide adds no new findings: every statement comes from the reference
pages, and each chapter ends with links to them.

## Plan
Parent, 2026-10-28. Owner: "Make it one document well organized. Include table of contents."
One sub-task per chapter, run as parallel agents in worktrees. Each agent writes a draft part `docs/guide/parts/NN-name.md` plus its
SVGs, and nothing else, so the merges are trivial. The parent then assembles **one document**, `docs/guide/README.md`: a title, a
how-to-read note, a table of contents with links to every chapter and section, an overview picture, chapters 1–8, and a glossary as
the last chapter. The parent renumbers the figures, checks every link and anchor, renders every SVG, deletes `parts/`, and links the
guide from the top-level README.

**Wiki too** (owner: "Or even a wiki would work. Or both"). The document stays the single source. `tools/guide_to_wiki.py` splits it
into GitHub-wiki pages: `Home.md` (intro + overview), one page per chapter, `Glossary.md`, and `_Sidebar.md` (the table of contents).
It also copies the images and rewrites links and anchors. The output goes to `build/wiki/` (gitignored). Blocker, 2026-10-28: the
repo's wiki is disabled (`hasWikiEnabled: false`). Wikis on private repos need a paid GitHub plan, and the wiki's git repo only exists
after the first page is created in the web UI. The owner enables it, then the parent pushes `build/wiki/` to
`FT-710_Firmware.wiki.git`, which stays private with the repo. That push is owner-approved; it is the only remote besides `origin`.

| Sub-task | Draft part (chapter) |
|---|---|
| T19a | `parts/01-the-radio.md`, `parts/02-how-the-chips-talk.md` |
| T19b | `parts/03-a-day-in-the-life.md` |
| T19c | `parts/04-firmware-files-and-updates.md` |
| T19d | `parts/05-cat-remote-control.md` |
| T19e | `parts/06-inside-main-and-display.md` |
| T19f | `parts/07-inside-ifdsp-and-sdr.md` |
| T19g | `parts/08-hacking-and-custom-firmware.md` |
| T19h | fix the reference-page issues the writers found |

### Style guide (all chapters)
- **Reader:** a radio amateur who knows what a CPU, UART and FPGA are, but has not read the reference pages. Short sentences. Explain each
  term the first time it appears and link it to `glossary.md`. Round numbers where precision doesn't matter. Addresses and function names
  only in a closing "Where to look" section that links to the reference pages.
- **Shape of a chapter (one part file = one chapter):** `## N. Title` (level 2), a one-paragraph "In short", then 4–8 sections as
  `### N.M Title` (level 3, no deeper than `####`). Each section opens with a figure. End with `### N.x Where to look`. Don't write
  a document title, table of contents or glossary; the parent does. Instead, list the terms you use that need a glossary entry, with a
  one-line definition each, under `## Glossary terms` in your sub-task file.
- **Evidence:** plain statements are established facts in the reference pages. Mark anything weaker inline as *(inference)* or *(guess)*.
  Never add a claim that isn't in the reference pages; if you find a contradiction, report it, don't resolve it in the guide.
- **Pictures:** at least 3 hand-written SVGs per chapter in `docs/guide/img/NN-name.svg` (NN = chapter number), embedded as
  `![alt](img/NN-name.svg)` (the path is relative to `docs/guide/`, where the final document lives) followed by an italic caption line `*Figure N.M — ...*` (N = chapter). SVG rules:
  - `viewBox="0 0 960 H"` with `width="960"`, a full white background `<rect>` (so it reads in GitHub dark mode), a `<title>`.
  - Font `font-family="DejaVu Sans, Helvetica, Arial, sans-serif"`, text 14 px or larger (titles 20 px), dark ink `#1F2937`.
  - Colour per chip, everywhere: MAIN `#2563EB` (tint `#DBEAFE`), DISPLAY `#16A34A` (`#DCFCE7`), IFDSP `#9333EA` (`#F3E8FF`),
    SDR/FPGA `#EA580C` (`#FFEDD5`), other hardware grey `#6B7280` (`#F3F4F6`), danger `#DC2626` (`#FEE2E2`), caution `#D97706` (`#FEF3C7`).
  - Rounded boxes (`rx="8"`, stroke width 2), arrows with an arrowhead `<marker>`, a legend where colours carry meaning.
  - No scripts, external references, embedded raster images or `foreignObject`.
  - Check every SVG: `xmllint --noout`, then `rsvg-convert -w 960` to a PNG in the scratchpad and look at it. Fix overlaps, clipped
    text and crossing arrows before committing.
- **Mermaid** where a flow or sequence is clearer than a drawing: 20 nodes or fewer, the same chip colours via `classDef`.
- **No raw decompiled code** in the guide. Short byte examples of protocol frames are fine.

## Findings
- **Deliverable:** [`docs/guide/README.md`](../guide/README.md), one document of about 2,500 lines. It has a title and how-to-read
  note, a table of contents linking every chapter and section, an overview picture, chapters 1–8, and a glossary of 109 terms. It
  contains **74 figures**: 59 hand-drawn SVGs in `docs/guide/img/` and 15 Mermaid diagrams. It is linked from the top-level README.
- **Checks (2026-10-28):**
  - All 59 SVGs pass `xmllint` and render with `rsvg-convert`, and each chapter's writer looked at every figure. The parent spot-checked
    several and fixed the overview picture.
  - All 15 Mermaid blocks render with mermaid-cli 11.4.2 (installed in T19, see docs/tooling.md).
  - Every in-document anchor, image path and relative link resolves. Figure captions run in sequence within each chapter.
  - Glossary duplicates written by different chapters were merged. `DSP_CLK` is worded as open, because the reference pages disagree.
- The draft parts and the one-shot assembler were removed after assembly. From now on, edit `docs/guide/README.md` directly.
- **Wiki:** `tools/guide_to_wiki.py` produces `build/wiki/` (Home, 9 chapter pages, `_Sidebar` table of contents, images); tested.
- **T19h (done):** of the 26 reference issues, 21 are settled, 3 are left open as O7–O9 in `docs/code/system.md` §8, and 2 needed no
  change. The guide was corrected where it was affected (for example, the power key skips the 0x7F frame).
- **All Mermaid diagrams in the repository render** (115 blocks, checked with mmdc on 2026-10-28). 10 older blocks in the reference
  pages failed on GitHub's parser and were fixed: backticks inside node labels, and `;` / `->` inside sequence message text.
- **The chapter writers found 26 issues in the reference pages** (stale text, two pages disagreeing, small slips). They are listed
  under "Reference issues" in T19a–T19g and are fixed in T19h.

## Follow-ups
- **Blocked (2026-10-28):** the owner enabled the wiki, and the repository is now **public** (it was private at every earlier push).
  Pushing `main`, running `issues_sync.py` (which posts issue bodies) and pushing the wiki are all paused until the owner restores
  private visibility, per AGENTS.md. The wiki also needs a first page created in the web UI before its git repo exists.
- **Wiki published (2026-10-28):** https://github.com/Reid-n0rc/FT-710_Firmware/wiki (wiki commit 59c8ea1): Home, 8 chapter pages,
  Glossary, `_Sidebar` table of contents, 59 images (checked: the pages serve and the SVGs load). To update it, edit
  `docs/guide/README.md`, run `python3 -I tools/guide_to_wiki.py`, copy `build/wiki/` into a clone of the wiki repo, and push.
- **Unblocked (2026-10-28):** the owner said "Leave it public". Pushes, the issue sync and the wiki are allowed again (AGENTS.md updated).
