# T10a — MAIN overview, boot, main loop and memory map

**Status:** todo · **Depends on:** T05 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): README.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10a.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
Overview per the documentation standard: purpose, reset/boot flow (reset handler 0xFFF8FBDB, `app_main` 0xFFF94AFA, power-off CAT loop), `main_loop` 0xFFF94B8B task list (~16 polled tasks), memory map summary, block diagram, interrupt/vector summary, subsystem index linking every T10 page and `cat.md`.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
