# T11a — DISPLAY overview, boot and RTOS

**Status:** todo · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/README.md` (purpose, block diagram, boot flow figure, memory map summary, task/main-loop structure, subsystem index) and `docs/code/display/boot-rtos.md` (reset path, dual-bank loader, scatter-load, MMU, kernel objects, task table).

## Plan
Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings

## Status
