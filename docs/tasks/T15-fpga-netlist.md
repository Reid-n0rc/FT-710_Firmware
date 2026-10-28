# T15 — FPGA netlist recovery (SDR)

**Status:** todo · **Depends on:** T13

## Goal
Turn the SDR bitstream (XC7A50T, `build/FT-710_SDR_V0104.bin`) into a gate-level netlist and identify its main blocks, so
the design's interfaces can be re-implemented or extended (see [custom firmware feasibility](../custom-firmware.md)).

## Deliverables
- A tool that converts the bitstream to FASM with prjxray `bit2fasm` (installed in T13 under `~/.local/share/ft710-tools/`),
  plus a FASM summary (feature counts per tile type). FASM output itself stays in `build/` (derived data; not committed).
- A routing walker that builds a cell-level netlist (LUTs with their INIT, FFs, CARRY4, DSP48E1, BRAM, IOB, MMCM) from the
  FASM PIP features, with a self-test on a small known design.
- `docs/code/sdr/netlist.md`: block recognition, starting with the UART link to MAIN (UART5) and the ADC → DDC → filter
  chain (DSP48 cascades, the BRAM tables from `bram-tables.md`), plus the scope/FFT data link to DISPLAY.

## Notes / hints
- Split into sub-tasks (T15a FASM, T15b netlist, T15c block recognition) before starting.
- Open tools for the netlist step on 7-series are research-grade; expect custom code.
- Never commit bitstream bytes or large derived dumps.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
