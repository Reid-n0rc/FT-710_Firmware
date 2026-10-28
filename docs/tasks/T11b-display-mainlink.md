# T11b — DISPLAY ↔ MAIN UART link

**Status:** in progress · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/mainlink.md`: SCIF5 driver, frame format, the 43-entry command table at 0x20450074, TX queue and RX dispatch, `cmd_interval_sem`/`cmd_waiting_sem` tasks, debug receive log. Figures: sequenceDiagram of one exchange, flowchart of the tasks.

## Plan
T11b agent (worktree branch), 2026-10-27. Per the fan-out rules the agent does not touch `decomp/` or the shared names file; it proposes names in
`tools/ghidra/names_display.T11b.tsv` (and missed entries in `entries_display.T11b.tsv`) and uses a private project copy `FT710_DISPLAY_T11b`.
1. Read the named starting points in `decomp/display/` (`mainlink_init`, `mainlink_send_cmd`, `mainlink_queue_frame`, `task_cmd_interval`,
   `task_mainlink_retry`, `debug_recv_cmd_log`, `scif5_get`, `uart_obj_init`, the three UART-object task creators) and follow calls/vtables.
2. Dump `.data` around the command table 0x20450074 from the project (LZ-decompressed) and decode all entries.
3. Find RX parse / dispatch and the handlers that drive GUI state; list every command both directions.
4. Cross-read MAIN's SCI1 side in `decomp/main/` (and T10b's page if present) so frame format/commands agree.
5. Write `docs/code/display/mainlink.md` (tables, globals, sequenceDiagram + task flowchart), TSVs, findings; commit.

Original plan text:
Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings

## Status
