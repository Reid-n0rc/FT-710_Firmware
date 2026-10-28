# T10f — MAIN menu engine (EX) and hidden menu items

**Status:** todo · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): menu.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10f.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
The EX menu table and engine: item descriptors (ranges, defaults, storage), diff against the manual's MENU chart (2306-C Table 2 / EX command, 296 items) to find hidden or undocumented items, and how menu values reach the DSP/SDR/DISPLAY.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
