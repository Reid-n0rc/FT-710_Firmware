# T10 — Document MAIN code

**Status:** in progress · **Depends on:** T05

## Goal
Full documentation of the MAIN (RX651) firmware per the AGENTS.md documentation standard → `docs/code/main/`.

## Deliverables
- `docs/code/main/README.md`: overview, a block diagram, boot/reset flow, main loop/scheduler, a subsystem index.
- One page per subsystem: CAT (shared with T09; link, don't duplicate), the DISPLAY link (SCI1), the SDR link (SCI5), the DSP link (SCI7/SPI), the tuner (SCI2), EEPROM/settings (BR25G256 SPI), band/VFO/mode control, TX control/PTT/protection, front-panel input, and any other subsystems you find.
- Functions renamed in the Ghidra project, and `decomp/main/` re-exported.

## Notes / hints
- Too big for one context. Split into T10a/T10b/... sub-task files by subsystem as the first step, and do one per session.

## Plan
Split by the parent (2026-10-27) into T10a–T10h (see the board), run in parallel, one agent per sub-task. Each sub-task
proposes names in `tools/ghidra/names_main.T10x.tsv`; the parent merges them into `names_main.tsv`, applies them with
ApplyNames.java and re-exports `decomp/main` once, then the pages are updated to the final names.
