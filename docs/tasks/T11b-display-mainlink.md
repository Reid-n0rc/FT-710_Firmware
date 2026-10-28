# T11b — DISPLAY ↔ MAIN UART link

**Status:** todo · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/mainlink.md`: SCIF5 driver, frame format, the 43-entry command table at 0x20450074, TX queue and RX dispatch, `cmd_interval_sem`/`cmd_waiting_sem` tasks, debug receive log. Figures: sequenceDiagram of one exchange, flowchart of the tasks.

## Plan
Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings

## Status
