# T11a — DISPLAY overview, boot and RTOS

**Status:** done (2026-10-27) · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/README.md` (purpose, block diagram, boot flow figure, memory map summary, task/main-loop structure, subsystem index) and `docs/code/display/boot-rtos.md` (reset path, dual-bank loader, scatter-load, MMU, kernel objects, task table).

## Plan
Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference] (or an open question; the former guess tag is retired).

## Findings
- Pages: `docs/code/display/README.md` (overview, block diagram, boot flowchart, memory map summary, subsystem index) and
  `docs/code/display/boot-rtos.md` (reset sequenceDiagram, `main`, `task_root` boot modes stateDiagram, kernel/ISRs, periodic wake-up, task
  table, USB-keyboard handler chains, globals).
- Ghidra project rebuilt on Tower from the T06 recipe; the first re-export matched the committed `decomp/display` exactly (empty diff).
- 14 function entries were missing or mis-bounded (task entries that start with `ldr` before `push`, including `task_root` 0x201170C8). The new
  `tools/ghidra/FixFuncEntries.java` + `tools/ghidra/entries_display.tsv` fix them (run before ApplyNames). 151 names now.
- Boot modes: `task_root` picks a standby or full start from P2_0, a key scan and a force flag; `power_on_full_init` later completes the full start.
- Kernel: T_CTSK and T_CISR layouts, 10 ms OSTM0 tick, 1 ms OSTM1 periodic wake-up service (periods 33/1/8/1/1 ms).
- **Debug console** (`fw1up`/`up0..2`, `uptest`, `cli` memory monitor + `I:\*.txt` scripts, SDR/DSP commands) is reached only from a USB keyboard and
  only when 0x20450000 == 0xA0B9C8E7. `.data` holds 0 and the only writer `debug_unlock` has no caller (also checked with REA): disabled in V01-08.
- `loader_selfinstall` writes the running image to flash 0 (the loader) when 0xFCFF400C == 0xAABBCCDD (T11c should find who sets it).

## Status
Done. Names, decomp re-export and docs are in separate commits on the T11 worktree branch.
