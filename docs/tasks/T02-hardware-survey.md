# T02 — Hardware survey

**Status:** todo · **Depends on:** —

## Goal
Identify every processor and programmable device in the FT-710 and which SFL image runs on each one.

## Deliverables
- `docs/hardware.md`: per board, the CPU/DSP/FPGA part numbers, architecture, external flash/RAM, the buses between CPUs (UART/SPI/etc.), the CAT/USB path, and the debug headers (JTAG/SWD/UART test points).

## Notes / hints
- Source: `Manuals/FT-710_serv_2022.pdf`. Use `pdftotext -f N -l M` on small page ranges, and find the block diagram and parts lists first.
- Architecture plus flash part determine the Ghidra language and load address in T05–T08.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
