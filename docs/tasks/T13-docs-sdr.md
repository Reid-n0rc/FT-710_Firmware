# T13 — Document SDR code

**Status:** in progress · **Depends on:** T08

## Goal
Full documentation of the SDR (Xilinx XC7A50T bitstream) firmware per the AGENTS.md documentation standard → `docs/code/sdr/`.

## Deliverables
- `docs/code/sdr/README.md`: overview, block diagram, boot flow, subsystem index.
- One page per subsystem: bitstream layout, configuration path (who loads it, over what bus), the FPGA's register/SPI interface as seen from the CPUs' code, the ADC/DDC data path at block level.
- Functions renamed in the Ghidra project and `decomp/sdr/` re-exported (where there is CPU code).

## Notes / hints
- If it's too big for one context, split into T13a/T13b/... sub-task files by subsystem first, and do one per session.

## Plan
1. Install Project X-Ray (f4pga/prjxray, Python utilities only, no C++ build needed for frame/segbits work) and a sparse
   checkout of prjxray-db `artix7/` (xc7a50t part files + tile segbits) under `~/.local/share/ft710-tools/`.
   Record both in `docs/tooling.md` (append only). *Done: both are plain git checkouts; no venv was needed because
   `tools/xc7_db.py` reads the database files directly (stdlib only).*
2. Convert the FDRI payload to per-frame form keyed by real FAR addresses (walk the FAR sequence with the prjxray
   part.yaml/tilegrid frame counts rather than T08's empirical layout), and verify the BRAM layout guess.
3. Map BRAM_L/BRAM_R tile segments to RAMB36/RAMB18 sites using the prjxray `segbits_bram_*.block_ram.db` INIT/INITP bit
   positions; decode each block's INIT data to 16k x 2 bit-ordered words; group identical contents.
4. Characterize every distinct table: sine/cosine fit at several widths/phases, FIR symmetry and DC sum, window shape,
   ramps/counters, MicroBlaze opcode statistics (big-endian 32-bit, opcode field histogram, imm/branch targets).
   Settle the MicroBlaze question.
5. Coarse resource picture: which tiles have non-zero config bits (CLBs per column, DSP48 tiles, BRAM, IOB, clocking),
   via prjxray tilegrid + segbits (`bitread`/`segprint` if feasible in pure Python, else own stdlib tool).
6. Write `docs/code/sdr/` pages: README (overview, block diagram, boot/config flow, subsystem index), bitstream.md,
   bram-tables.md, interfaces.md (J2002 map, data-path figure, TX path, config/update sequenceDiagram with a "to confirm"
   list), resources.md. New tool(s) in `tools/` (stdlib, `python3 -I`).
7. Update this file: Findings, Follow-ups, Status. If it grows, split into T13a/T13b.
