# T11d — DISPLAY SPI links (SDR, DSP, FT4222H)

**Status:** todo · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/spi-links.md`: RSPI0–4 driver, which channel goes where, scope/waterfall data from the SDR, FFT/REC/PLAY data from the DSP, the FT4222H path from the PC.

## Plan
Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings

## Status
