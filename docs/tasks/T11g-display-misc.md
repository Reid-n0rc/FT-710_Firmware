# T11g — DISPLAY misc peripherals and files

**Status:** in progress · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/peripherals.md`: RTC S-35190A, OSTM, INTC/GIC, GPIO, backlight, DVI/LVDS, SD-card user files (MESSAGE, PlayList, MemList, Menu).

## Plan
Owner: T11g fan-out agent (worktree branch), 2026-10-27. Own Ghidra copy `ghidra/FT710_DISPLAY_T11g` (read/explore only).

1. Peripheral survey: run `PeriphRefs.java` over the RZ/A1H register blocks (CPG, INTC/GIC, GPIO/PFC, OSTM, RTC, SSIF, SCUX, SDHI/MMC,
   USB0/1, WDT, ADC, RIIC, PWM, LVDS, DMAC) to get the function set per block; drop those owned by T11b–T11f.
2. Clocks: decode the 2-entry CPG profile table at 0x2016517C (FRQCR + STBCR1..11) into clock rates and module-stop bits.
3. Pin mux: decode `pinmux_init` (per-pin PFC/PMC/PM calls) into a port/pin → function table, cross-check against docs/hardware.md.
4. Audio: `audio_codec_init` / `task_audio_codec` and helpers (it is a WAV recorder/player on SD, not a codec driver: find the data source/sink).
5. SD/files: FatFs-or-other identification, path strings (`I:\FT-710\...`), file types read/written (MESSAGE, PlayList, MemList, Menu,
   screenshots, settings backups); leave the SFL updater to T11c.
6. RTC S-35190A (3-wire GPIO bit-bang on P1_0..P1_2), WDT, OSTM, backlight PWM, LVDS, USB usage summary (host HID belongs to T11f).
7. GIC table: all `itron_acre_isr` descriptors and direct writes into the handler table 0x208DC1E0 → ID, ISR, source.
8. Write `docs/code/display/peripherals.md` (tables + Mermaid), names in `tools/ghidra/names_display.T11g.tsv`, missed entries in
   `entries_display.T11g.tsv`, shared-file edits proposed below; commit.

## Old plan (T11 template)
Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings

## Status
