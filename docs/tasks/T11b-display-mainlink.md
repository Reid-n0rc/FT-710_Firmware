# T11b — DISPLAY ↔ MAIN UART link

**Status:** done · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

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
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference] (or an open question; the former guess tag is retired).

## Findings
Page: [docs/code/display/mainlink.md](../code/display/mainlink.md). Names: `tools/ghidra/names_display.T11b.tsv` (110), entries:
`tools/ghidra/entries_display.T11b.tsv` (14). Checked on the private copy `FT710_DISPLAY_T11b`: 13 created + 1 late start fixed, 110 names applied, 0 failures.
- Wire format **[fact]**: `cmd, payload[n], sum8`, no start byte or length on the wire. `n` comes from the 43-entry table at 0x20450074
  (`{u16 cmd, u16 n, u8 no_ack, pad, u32 rx_count}`). 0x06/0x15/0x1B are 1-byte frames. The 0xAA is only an in-memory buffer tag.
  345600 baud 8N2 on both sides (DISPLAY `scif_open(0x54600,8,0,2)`, MAIN SCI1 SMR 0x08 BRR 10).
- MAIN checks the checksum (`FUN_fff9c60f`), the DISPLAY only range-checks fields (`mainlink_rx_validate` 0x2015E6F4) **[fact]**.
- Stop-and-wait: every table frame is ACKed. DISPLAY parks one frame per type plus an E0 ring and a coalescing encoder queue while waiting, paces
  frames ≥3 ms apart (cmd_interval), retries 3× (NAK or cyclic timeout), then resets MAIN and itself via the WDT (`FUN_20114df4`, 0x20100268).
- All commands both directions are tabled with sender/handler on both CPUs. Notable: 0x64 LCD test pattern, 0x65 set RTC, 0x7A screenshot,
  0x7B screen saver (E4 exits), 0x7C touch calibration (E5 exits), 0x7F keyed power-down/restart (key `9B BA F6 38 FF 25 73 1F`), 'D'/'E' 32000-byte
  block transfer (SD save/load of MAIN data), F0 hello with power-up key code (MAIN: 1 = settings reset, 7 = destination-code swap).
- `mainlink_send_cmd` does not transmit: it re-injects a saved frame into the RX dispatcher (proposed `mainlink_inject_rx`).
  `debug_recv_cmd_log` replays `SEND_CMD.TXT` into the GUI snapshot (proposed `debug_replay_send_cmd`).
- The SCIF4 "uart4" link object (`FUN_20114f4c`) has no caller in V01-08.
- The GUI is driven by snapshots: dispatcher → 0x2045F8C0; `gui_main_loop` (33 ms) → `gui_apply_frame` 0x2012EBB8 compares with 0x208F0B2A.

## Follow-ups
- T10b: confirm the MAIN-side semantics of E6, E7/E8, C3 and 0x21/0x42/0x43/0x71 (no MAIN sender found for 0x21, 0x42, 0x71), and MAIN's retry timer units.
- T11c: the 'Z' tunnel / F1 bridge used by the SDR/DSP update code, `mainlink_rx_ctrl` users, and the 'D'/'E' block ids 'A'..'D' (`FUN_2010f240`..`FUN_2010f300`).
- T11f: `task_keycode` trace/replay keys and whether they are gated by `debug_enabled`; mouse task entry 0x2015FD60 is a late start (FUN_2015fd64).
- T11e: the per-command screen functions called by `gui_apply_frame`.
- The meaning of the 0x97-byte radio status block fields (ranges are in `mainlink_status_valid` 0x2015E354).

## Proposed shared-file edits
- `tools/ghidra/names_display.tsv`: append `names_display.T11b.tsv`; it renames `mainlink_send_cmd` → `mainlink_inject_rx` and
  `debug_recv_cmd_log` → `debug_replay_send_cmd`.
- `tools/ghidra/entries_display.tsv`: append `entries_display.T11b.tsv`; then re-apply and re-export `decomp/display/`.
- `docs/code/display/README.md`: mark mainlink.md done; key finding: "MAIN link is stop-and-wait over SCIF5 at 345600 8N2, frames `cmd+payload+sum8`
  with lengths from the 0x20450074 table; 3 failed retries reset MAIN and the DISPLAY".
- `docs/code/display/boot-rtos.md` task table: the uart sub-tasks are TX 0x20165938 (`task_mainlink_tx`), dispatcher 0x2016591C
  (`task_mainlink_dispatch`), RX 0x20165900 (`task_mainlink_rx`); `FUN_20114f4c` (uart4) has no caller.
- `docs/memory-maps.md`: SCIF5 RXI/TXI = GIC 0xF3/0xF4, SCIF4 0xEF/0xF0.

## Status
