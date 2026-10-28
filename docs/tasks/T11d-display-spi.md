# T11d — DISPLAY SPI links (SDR, DSP, FT4222H)

**Status:** in progress · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/spi-links.md`: RSPI0–4 driver, which channel goes where, scope/waterfall data from the SDR, FFT/REC/PLAY data from the DSP, the FT4222H path from the PC.

## Plan
T11d agent, 2026-10-27 (worktree branch). Read-only work on `decomp/display/` plus raw disassembly (`arm-none-eabi-objdump`) where Ghidra lost
jump tables; no Ghidra write needed (the parent applies names).
1. Decode the generic RSPI driver 0x2011D9A8-0x2011F970 (register table 0x20166B4C, per-channel open/ISR/read/write) and the DMAC channel set-ups
   0x20137080-0x20137E88 (CHCFG, DMARS MID/RID, callbacks).
2. Follow each user: `task_spi_slave` (RSPI0 + DMA ch9/ch10), `FUN_20133484`/`FUN_201330d4`/`FUN_201331dc` (RSPI2/RSPI4 + DMA ch3/4/5), the SDR
   update path (`FUN_201107c0`, master mode). Identify channel -> pin group from `pinmux_init`, GPIO reads and the debug-overlay labels.
3. Frame formats, buffers, consumers (scope, AF-FFT, REC/PLAY WAV in `task_audio_codec`, PC TX block).
4. Write `docs/code/display/spi-links.md`, `tools/ghidra/names_display.T11d.tsv`, `tools/ghidra/entries_display.T11d.tsv` (missed ISR stubs and
   late starts); proposed shared-file edits go below. Original plan text follows.

Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings

## Status
