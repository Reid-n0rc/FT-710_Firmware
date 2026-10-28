# T10e — MAIN EEPROM, data flash and settings persistence

**Status:** todo · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): eeprom.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10e.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
The EEPROM driver (BR25G256 SPI or bit-banged; locate it), data flash use (0x100000), the settings/memory image at 0x60C9 (E8/E9 dump, 10665 bytes) and its layout, EEPROM address map (e.g. 0x000A table, 0x010F destination code), save/restore and factory-reset paths (ZZ).

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
