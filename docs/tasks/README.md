# Task board

Mirrored to GitHub issues (epic #1; numbers in [issues.json](issues.json)) by `tools/issues_sync.py`. One task per session (see AGENTS.md → Task sizing). Update the status here when you start or finish a task.

| ID | Task | Depends on | Status |
|---|---|---|---|
| T01 | [Tooling: install Ghidra + JDK 21](T01-tooling.md) | — | done |
| T02 | [Hardware survey from service manual](T02-hardware-survey.md) | — | done |
| T03 | [SFL container header format](T03-sfl-container.md) | — | done (checksum → T04) |
| T04 | [SFL payload decoding + `tools/sfl_decode.py`](T04-sfl-decode.md) | T03 | done |
| T05 | [MAIN image: arch/base address, Ghidra import, decomp export](T05-decomp-main.md) | T01 T02 T04 | done |
| T06 | [DISPLAY image: same as T05](T06-decomp-display.md) | T01 T02 T04 | done |
| T07 | [IFDSP image: same as T05 (DSP — check Ghidra support)](T07-decomp-ifdsp.md) | T01 T02 T04 | done |
| T08 | [SDR image: split code vs FPGA bitstream, decomp code](T08-decomp-sdr.md) | T01 T02 T04 | done |
| T09 | [CAT command table recovery (MAIN)](T09-cat-commands.md) | T05 | in progress |
| T10 | [Document MAIN code (split into sub-tasks)](T10-docs-main.md) | T05 | todo |
| T11 | [Document DISPLAY code](T11-docs-display.md) | T06 | in progress |
| T11a | [DISPLAY overview, boot and RTOS](T11a-display-overview.md) | T06 | done |
| T11b | [DISPLAY ↔ MAIN UART link](T11b-display-mainlink.md) | T06 | todo |
| T11c | [DISPLAY SD card and firmware update paths](T11c-display-update.md) | T06 | todo |
| T11d | [DISPLAY SPI links (SDR, DSP, FT4222H)](T11d-display-spi.md) | T06 | todo |
| T11e | [DISPLAY GUI and LCD](T11e-display-gui.md) | T06 | todo |
| T11f | [DISPLAY input (touch, keys, encoders, USB HID)](T11f-display-input.md) | T06 | todo |
| T11g | [DISPLAY misc peripherals and files](T11g-display-misc.md) | T06 | todo |
| T12 | [Document IFDSP code](T12-docs-ifdsp.md) | T07 | in progress |
| T13 | [Document SDR/FPGA](T13-docs-sdr.md) | T08 | in progress |
| T14 | [System-level documentation + figures](T14-docs-system.md) | T09–T13 | todo |

Later (don't plan these in detail yet): the inter-CPU protocol, the update/flash protocol plus re-encoding, and custom firmware feasibility.

## Run plan (2026-10-09)

Parallel agents, each with its own Ghidra project and output dirs; the parent owns this board's top-level rows, `issues_sync.py` and pushes.

1. Wave 1 (parallel): **T13** (SDR, no Ghidra), **T09** (MAIN project), **T11** (DISPLAY project), **T12** (IFDSP project).
2. Wave 2: **T10** (MAIN docs, split into sub-tasks) once T09 has released the MAIN project.
3. Wave 3: **T14** (system docs) once T09–T13 are done.

Agents add their own sub-task rows (`T13a`…) directly under their parent row.
