# T13 — Document SDR code

**Status:** done · **Depends on:** T08

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

Amendment (2026-10-27, Linux container): step 1 was redone on Tower (same commits, `~/.local/share/ft710-tools/`,
recorded in docs/tooling.md). `tools/xc7_db.py` from the Mac session already covered steps 2-3; added `bramcfg`
(per-site BRAM modes) and `sites` (LUT/FF/DSP counts) commands, and a new `tools/xc7_bram_tables.py` for logical
tables (RAMB36 bit interleave, x9 lanes, half-FIR runs, selftest). Step 6 also uses the service manual p19 (J2002 pin
map). The work fit in one session, so no sub-tasks were split off.

## Findings
Pages: [`docs/code/sdr/`](../code/sdr/README.md) (README, bitstream.md, bram-tables.md, resources.md, interfaces.md).
Tools: `tools/xc7_db.py`, `tools/xc7_bram_tables.py` (stdlib, `python3 -I`, need prjxray-db).

- **Frame map verified:** the FAR sequence rebuilt from prjxray `part.json` gives 5,408 frames + 12 zero pad frames =
  5,420 = the FDRI frame count; BRAM content is frames 4390-5419 in 3 rows of 3/2/3 columns **[fact]**.
- **BRAM:** 70 of 75 RAMB36 sites configured; 54 RAMB18 halves initialized (33 distinct), 35 logical memories / 25
  distinct **[fact]**. RAMB36 halves are bit-interleaved (INIT bit j -> half j%2) **[inference, high]**.
- **Tables [fact for shapes]:** exact `32760 cos(2 pi n/720)` x800; exact raised-cosine ramp over 720 steps; a
  36-bit FIR bank (4 x9 lanes) holding six half-symmetric low-pass filters with unity DC gain; a 1024-tap symmetric
  filter (sum 2^16); quadratic/product phase tables (four replicated x4); a step table; constants.
- **No soft CPU** (MicroBlaze) **[inference, high]**: the only 32-bit-shaped lane set is the FIR bank.
- **Resources:** ~26.6k LUTs (82 %), ~31.4k FFs, **119/120 DSP48E1** fully pipelined, 2 MMCMs (DIVCLK 5, FB 34 / 36,
  fractional CLKOUT0 51.125 / 4.25), ~9 LVDS in + ~9 LVDS out pairs, ~66 single-ended I/O **[fact for counts]**.
- **J2002 (p19):** DISPLAY's `SDR_SCLK/SS/MOSI/MISO` land on the module's FFT/FRM scope port; `SDR_UPDATE` goes to
  module pin `WP`; RX I2S shares the TX clock/frame **[fact]**. So the FPGA likely writes its own config flash during an
  update, with MAIN lifting WP **[inference]**.

## Follow-ups
- T06 (DISPLAY): trace `sdrup`/`sdrspi`/`sdrchk*` to see which bus carries the image and who checks the CRC-32/BZIP2.
- T05/T11 (MAIN): `SDR_UPDATE` (= flash WP) / `SDR_RESET` GPIOs and the UART5 protocol.
- docs/hardware.md owner: add the J2002 pin map from interfaces.md and the WP finding; SDR FPGA row -> XC7A50T.
- Optional: decode routing (prjxray `ppips`/`segbits_int_*`) to tie the BRAM tables and LVDS pins to blocks; read
  J2002 pins 14 and 37 from a higher-resolution scan.
