# T12a — IFDSP overview + boot/memory map

**Status:** done (2026-10-27) · **Parent:** T12 · **Depends on:** T07

## Goal
docs/code/ifdsp/README.md: purpose, boot flow, memory map summary, M33 task and DSP thread structure, block diagram, subsystem index. Record the Ghidra rebuild/re-export check.

## Plan
1. Rebuild `ghidra/FT710_IFDSP` in the Linux container with the T07 commands (`decomp/ifdsp/INDEX.md`) and check that the re-export reproduces the committed `decomp/ifdsp/`.
2. Read the M33 decompile (console, IPC, main, DSP loader), cross-check with objdump and the MAIN decompile, and scan the HiFi4 literal pools.
3. Rename the M33 functions found on the way (`IfdspM33Names.java`), re-export, commit separately.
4. Write the README with block diagram, boot sequence and task/thread figure; add the shared SRAM areas to `docs/memory-maps.md`.

## Findings
- **Rebuild check:** on the Linux container (Ghidra 12.1.4, JDK 21.0.13, `-max-cpu 5`, 3 GB heap) the T07 commands reproduce `decomp/ifdsp/m33` and `decomp/ifdsp/hifi4` **byte-identical** (`git status` clean after the export). Both imports take about a minute.
- **The FLEXCOMM0 console is the MAIN↔IFDSP control link** **[fact]**: MAIN sends `i DB00\r` over SCI4 (`FUN_fff9d06c` → `FUN_fffb1ab4` → `R_SCI4_Serial_Send`) and then `r`/`w` frames built by `FUN_fffa0b4c`; the M33 console's machine mode parses exactly that format and reads/writes a 32K × 16-bit register file at 0x20070000 that the DSP reads.
- **Correction to T07:** the M33 *does* control the codec (TLV320AIC3204, 67-entry init table at 0x87A1C, bit-banged SPI on PIO1_0/1_1/1_7/2_28/2_29 = `AIC_RESET/MOSI/SS/MISO/SCLK`, p19) and drives SCT0_OUT0 (PWM, duty = reg 0x4005, into an RC filter to TP2005, p19).
- **`main` at 0x000872AE is a wrapper** (`stdio_init`, then tail-jump); the real init code is `app_main` 0x0008106C.
- rpmsg-lite is initialised but `IpcSendTask`'s queue has no writer, so the rpmsg path is dormant **[fact]**.
- REA (raw ARM, `ARM:LE:32:v7`) on the carved SRAM image found only 1 of the ≥4 callers of `regfile_write` (it decodes from the entry without Thumb context); not useful for the M33 beyond a sanity check.

## Status
Done 2026-10-27: `docs/code/ifdsp/README.md`, `docs/memory-maps.md` (shared SRAM areas), M33 renames + re-export (commit "T12: IFDSP M33 names …").
