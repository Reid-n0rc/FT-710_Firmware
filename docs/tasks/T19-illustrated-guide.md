# T19 — Illustrated guide for people

**Status:** in progress · **Depends on:** T01–T18

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

| Sub-task | Draft part (chapter) |
|---|---|
| T19a | `parts/01-the-radio.md`, `parts/02-how-the-chips-talk.md` |
| T19b | `parts/03-a-day-in-the-life.md` |
| T19c | `parts/04-firmware-files-and-updates.md` |
| T19d | `parts/05-cat-remote-control.md` |
| T19e | `parts/06-inside-main-and-display.md` |
| T19f | `parts/07-inside-ifdsp-and-sdr.md` |
| T19g | `parts/08-hacking-and-custom-firmware.md` |

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
(filled in at the end)
