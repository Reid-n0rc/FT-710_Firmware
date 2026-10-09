# T13 — Document SDR code

**Status:** todo · **Depends on:** T08

## Goal
Full documentation of the SDR (Xilinx XC7A50T bitstream) firmware per the AGENTS.md documentation standard → `docs/code/sdr/`.

## Deliverables
- `docs/code/sdr/README.md`: overview, block diagram, boot flow, subsystem index.
- One page per subsystem: bitstream layout, configuration path (who loads it, over what bus), the FPGA's register/SPI interface as seen from the CPUs' code, the ADC/DDC data path at block level.
- Functions renamed in the Ghidra project and `decomp/sdr/` re-exported (where there is CPU code).

## Notes / hints
- If it's too big for one context, split into T13a/T13b/... sub-task files by subsystem first, and do one per session.
