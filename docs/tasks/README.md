# Task board

Mirrored to GitHub issues (epic #1; numbers in [issues.json](issues.json)) by `tools/issues_sync.py`. One task per session (see AGENTS.md → Task sizing). Update the status here when you start or finish a task.

| ID | Task | Depends on | Status |
|---|---|---|---|
| T01 | [Tooling: install Ghidra + JDK 21](T01-tooling.md) | — | done |
| T02 | [Hardware survey from service manual](T02-hardware-survey.md) | — | done |
| T03 | [SFL container header format](T03-sfl-container.md) | — | done (checksum → T04) |
| T04 | [SFL payload decoding + `tools/sfl_decode.py`](T04-sfl-decode.md) | T03 | done |
| T05 | [MAIN image: arch/base address, Ghidra import, decomp export](T05-decomp-main.md) | T01 T02 T04 | in progress |
| T06 | [DISPLAY image: same as T05](T06-decomp-display.md) | T01 T02 T04 | done |
| T07 | [IFDSP image: same as T05 (DSP — check Ghidra support)](T07-decomp-ifdsp.md) | T01 T02 T04 | in progress |
| T08 | [SDR image: split code vs FPGA bitstream, decomp code](T08-decomp-sdr.md) | T01 T02 T04 | done |
| T09 | [CAT command table recovery (MAIN)](T09-cat-commands.md) | T05 | todo |
| T10 | [Document MAIN code (split into sub-tasks)](T10-docs-main.md) | T05 | todo |
| T11 | [Document DISPLAY code](T11-docs-display.md) | T06 | todo |
| T12 | [Document IFDSP code](T12-docs-ifdsp.md) | T07 | todo |
| T13 | [Document SDR/FPGA](T13-docs-sdr.md) | T08 | in progress |
| T14 | [System-level documentation + figures](T14-docs-system.md) | T09–T13 | todo |

Later (don't plan these in detail yet): the inter-CPU protocol, the update/flash protocol plus re-encoding, and custom firmware feasibility.
