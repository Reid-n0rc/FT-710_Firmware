# T10f — MAIN menu engine (EX) and hidden menu items

**Status:** in progress · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

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
1. Start from `cat_EX` (0xFFFA9937) → `FUN_fffe61e7` and follow the chain to the menu item lookup and descriptor table.
2. Decode the descriptor layout (P1P2P3 key, min/max, default, RAM/EEPROM storage address, digit count, type) from the
   code that reads it plus raw bytes in `build/FT-710_MAIN_V0112.bin`.
3. Write `tools/main_menu_table.py` (stdlib, `python3 -I`) to dump the table to stdout/build.
4. Extract the 2306-C MENU chart (Table 2, EX command) with `pdftotext -layout`, parse it, and diff (missing, hidden,
   range/digit differences).
5. Trace the set path: what runs after a value changes (DSP/SDR/DISPLAY notifications).
6. Write `docs/code/main/menu.md` (tables, figures, tags), `names_main.T10f.tsv`, update this file, commit.

## Findings
_(fill in as you go)_

## Follow-ups
