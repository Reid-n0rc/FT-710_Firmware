# T12 — Document IFDSP code

**Status:** todo · **Depends on:** T07

## Goal
Full documentation of the IFDSP (i.MX RT685) firmware per the AGENTS.md documentation standard → `docs/code/ifdsp/`.

## Deliverables
- `docs/code/ifdsp/README.md`: overview, block diagram, boot flow, subsystem index.
- One page per subsystem: boot/FlexSPI layout, Cortex-M33 control code, HiFi4 DSP code (if any), audio/I2S codec path, the MAIN link, filters/NR/NB algorithms as far as identifiable.
- Functions renamed in the Ghidra project and `decomp/ifdsp/` re-exported (where there is CPU code).

## Notes / hints
- If it's too big for one context, split into T12a/T12b/... sub-task files by subsystem first, and do one per session.
