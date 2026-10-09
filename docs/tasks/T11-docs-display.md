# T11 — Document DISPLAY code

**Status:** todo · **Depends on:** T06

## Goal
Full documentation of the DISPLAY (RZ/A1H) firmware per the AGENTS.md documentation standard → `docs/code/display/`.

## Deliverables
- `docs/code/display/README.md`: overview, block diagram, boot flow, subsystem index.
- One page per subsystem: SD/firmware-update loader (incl. SFL decode+CRC at 0x2011497C/0x20114A64), GUI/screens/touch, the MAIN UART link, the SPI links to SDR and DSP, FT4222H USB, RTC, DVI/HDMI.
- Functions renamed in the Ghidra project and `decomp/display/` re-exported (where there is CPU code).

## Notes / hints
- If it's too big for one context, split into T11a/T11b/... sub-task files by subsystem first, and do one per session.
