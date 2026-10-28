# T12 — Document IFDSP code

**Status:** in progress (2026-10-27) · **Depends on:** T07

## Goal
Full documentation of the IFDSP (i.MX RT685) firmware per the AGENTS.md documentation standard → `docs/code/ifdsp/`.

## Deliverables
- `docs/code/ifdsp/README.md`: overview, block diagram, boot flow, subsystem index.
- One page per subsystem: boot/FlexSPI layout, Cortex-M33 control code, HiFi4 DSP code (if any), audio/I2S codec path, the MAIN link, filters/NR/NB algorithms as far as identifiable.
- Functions renamed in the Ghidra project and `decomp/ifdsp/` re-exported (where there is CPU code).

## Notes / hints
- If it's too big for one context, split into T12a/T12b/... sub-task files by subsystem first, and do one per session.

## Plan
Inputs: T07 output (`decomp/ifdsp/`, `docs/memory-maps.md` IFDSP), `docs/hardware.md` Q2002, the raw image and the
carved HiFi4 images (`tools/ifdsp_dsp_images.py`). Ghidra project `ghidra/FT710_IFDSP` is rebuilt first with the
T07 commands (it is not in the container yet) and the re-export must reproduce the committed `decomp/ifdsp/` before any
renaming. REA (raw ARM, `ARM:LE:32:v7`) is used only as an xref/string cross-check of the M33; it has no Xtensa lane.

Split by subsystem; each sub-task is finished, documented and committed before the next one:

| Sub-task | Deliverable |
|---|---|
| [T12a](T12a-ifdsp-overview.md) | `docs/code/ifdsp/README.md`: purpose, boot flow, memory map summary, M33 tasks / DSP threads, block diagram, subsystem index; re-export check recorded |
| [T12b](T12b-ifdsp-m33-console.md) | `docs/code/ifdsp/m33-console.md`: FLEXCOMM0 USART driver, Command Task, console grammar; is it the MAIN↔IFDSP control link? |
| [T12c](T12c-ifdsp-ipc.md) | `docs/code/ifdsp/ipc.md`: MU-A boot handshake, rpmsg-lite virtqueues, IpcRecv/IpcSend tasks, message format (categories/commands) |
| [T12d](T12d-ifdsp-m33-platform.md) | `docs/code/ifdsp/m33-platform.md`: reset/copy-down, clocks/pins, DSP loader, FreeRTOS kernel and libc; function renames in `IfdspM33Names.java` + re-export |
| [T12e](T12e-ifdsp-hifi4.md) | `docs/code/ifdsp/hifi4.md` (+ split pages if needed): XOS threads, peripheral usage (FLEXCOMM I2S/SPI, DMA, MU), audio paths, coefficient tables, what the base-ISA decode still yields |

Renames go into `tools/ghidra/IfdspM33Names.java` (M33) or a new HiFi4 names script, followed by a re-export; decomp
commits are kept separate from docs commits.

Page names: T12b writes `control-link.md` (not `m33-console.md`); the README subsystem index links all four pages.

## Findings
- T12a (done): `docs/code/ifdsp/README.md`. The FLEXCOMM0 console is the MAIN↔IFDSP control link: MAIN (SCI4) pokes a 32K × 16-bit
  parameter register file at 0x20070000 with `r`/`w` checksum frames; the DSP reads it. The M33 also owns codec setup (bit-banged SPI)
  and an SCT0 PWM (duty from reg 0x4005). The rpmsg-lite link is initialised but carries no traffic. Details in the sub-task files.
- Rebuild in the Linux container reproduces `decomp/ifdsp/` byte-identical.

## Status
In progress: T12a done; T12b–T12e todo (starting notes in each file).
