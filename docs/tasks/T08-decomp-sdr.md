# T08 — Decompile SDR

**Status:** todo · **Depends on:** T01 T02 T04

## Goal
Analyze the SDR image: separate the FPGA bitstream from any processor code, and decompile the code → `decomp/sdr/`.

## Deliverables
- `docs/memory-maps.md` (SDR section) with the image's internal layout.
- `decomp/sdr/` for any CPU code. Don't decompile the bitstream; just document its offset, size, and FPGA family.

## Notes / hints
- Look for FPGA sync words (Xilinx `AA 99 55 66`, Intel/Altera, Lattice) in the decoded image.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
