# T05 — Decompile MAIN

**Status:** todo · **Depends on:** T01 T02 T04

## Goal
Import the decoded MAIN image into Ghidra with the correct language and base address, auto-analyze it, and export the decompiled C to `decomp/main/`.

## Deliverables
- `docs/memory-maps.md` (MAIN section): language ID, base address, RAM/peripheral ranges, and how they were derived.
- `tools/ghidra/` headless scripts (import + export), reusable for T06–T08.
- `decomp/main/`: decompiled C split into files of a manageable size (e.g. per function or per address range), plus `INDEX.md` listing the notable functions found (CAT parser, string tables).

## Notes / hints
- Derive the base address from the vector table (reset/SP values) and absolute string pointers.
- Use a Ghidra script (e.g. Python/Java DecompInterface) to export. Keep each output file small so later agents can grep and read in pieces.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
