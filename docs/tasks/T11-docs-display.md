# T11 — Document DISPLAY code

**Status:** in progress · **Depends on:** T06

## Goal
Full documentation of the DISPLAY (RZ/A1H) firmware per the AGENTS.md documentation standard → `docs/code/display/`.

## Deliverables
- `docs/code/display/README.md`: overview, block diagram, boot flow, subsystem index.
- One page per subsystem: SD/firmware-update loader (incl. SFL decode+CRC at 0x2011497C/0x20114A64), GUI/screens/touch, the MAIN UART link, the SPI links to SDR and DSP, FT4222H USB, RTC, DVI/HDMI.
- Functions renamed in the Ghidra project and `decomp/display/` re-exported (where there is CPU code).

## Notes / hints
- If it's too big for one context, split into T11a/T11b/... sub-task files by subsystem first, and do one per session.

## Plan
Owner: T11 agent (worktree branch), 2026-10-27. Ghidra project `ghidra/FT710_DISPLAY` (rebuilt on Tower from the T06 recipe; the re-export must
match the committed `decomp/display` before any rename). REA (`rea` CLI, raw ARM, base 0x20100000, entry 0x2010002C) is a cross-check for
xrefs/call paths only; names live in `tools/ghidra/names_display.tsv`.

The image is ~2000 functions, too much for one context, so it is split by subsystem. Each sub-task: read the decomp for its functions (grep, targeted
reads), rename in `names_display.tsv`, re-apply + re-export (`decomp/display/` in its own commit), write its page in `docs/code/display/`, update
INDEX.md if names change, commit. Order:

| Sub-task | Page(s) | Scope |
|---|---|---|
| [T11a](T11a-display-overview.md) | `README.md`, `boot-rtos.md` | Purpose, block diagram, boot flow (Reset → bank select → scatterload → main), memory map summary, RTOS objects and the task list, subsystem index |
| [T11b](T11b-display-mainlink.md) | `mainlink.md` | SCIF5 UART link to the MAIN RX651: driver, frame format (0xAA marker), 43-entry command table at 0x20450074, TX/RX tasks, RX dispatch, debug log |
| [T11c](T11c-display-update.md) | `update.md` | SD/FAT stack summary, SFL decode/CRC, update of DISPLAY itself (SPI-flash banks), MAIN (RX boot mode), IFDSP and SDR (SPI flash), hidden debug commands and how they are entered |
| [T11d](T11d-display-spi.md) | `spi-links.md` | RSPI0–4 drivers, SDR SPI (scope/waterfall data), DSP SPI (FFT/REC/PLAY data), FT4222H SPI from the USB hub |
| [T11e](T11e-display-gui.md) | `gui.md` | VDC5, frame-buffer layers, draw primitives, sprite/bitmap descriptors and fonts in `.rodata`, screen/menu framework, screen capture |
| [T11f](T11f-display-input.md) | `input.md` | Touch (TSC2003 over RIIC), front-panel keys/encoders, USB-host HID keyboard/mouse |
| [T11g](T11g-display-misc.md) | `peripherals.md` | RTC S-35190A, OSTM tick, INTC/GIC, GPIO, backlight, DVI/LVDS, voice-message / play-list / MemList files |
