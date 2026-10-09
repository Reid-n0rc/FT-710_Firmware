# T08 — Decompile SDR

**Status:** done (no CPU code; bitstream analyzed, nothing to decompile) · **Depends on:** T01 T02 T04

## Goal
Analyze the SDR image: separate the FPGA bitstream from any processor code, and decompile the code → `decomp/sdr/`.

## Deliverables
- `docs/memory-maps.md` (SDR section) with the image's internal layout.
- `decomp/sdr/` for any CPU code. Don't decompile the bitstream; just document its offset, size, and FPGA family.

## Notes / hints
- Look for FPGA sync words (Xilinx `AA 99 55 66`, Intel/Altera, Lattice) in the decoded image.

## Plan
1. Write `tools/xbit_parse.py` (stdlib): walk the Xilinx 7-series packet stream after the sync word, decode type-1/type-2
   packets and register writes (CMD, IDCODE, COR0/1, CTL0/1, MASK, FAR, FDRI, CRC, WBSTAR, ...), report compression
   (multi-frame writes, MFWR) and encryption (CTL0 DEC bit, CBC/DWC/KEY writes).
2. Confirm the device: IDCODE vs Xilinx table, and FDRI word count vs the XC7A50T frame count (101 words/frame).
3. Explain the leading word `0x993966C2`: test CRC-32 variants, sums, lengths and the byte/bit-reversed sync word.
4. Walk the FDRI frames by FAR address (block type 0 = CLB/IO/CLK, 1 = BRAM content) and look for non-zero BRAM content
   and strings (soft-CPU / MicroBlaze evidence). No fabric disassembly.
5. Config path: docs/hardware.md signals plus `strings`/grep of the decoded DISPLAY (and MAIN) images for SDR-related
   text. No Ghidra (another agent is decompiling DISPLAY).
6. Write the docs: `docs/memory-maps.md` SDR section, `decomp/sdr/README.md`, this file, with Mermaid figures.

## Findings
Full write-up: [`decomp/sdr/README.md`](../../decomp/sdr/README.md). Layout table: [`docs/memory-maps.md`](../memory-maps.md) (SDR section).
Tool: `tools/xbit_parse.py`.

- **Device:** IDCODE write 0x0362C093 = **XC7A50T** **[fact]**. The length from 0x1000 to EOF is 2,192,012 B = 17,536,096 bits, exactly the UG470
  length for the 7A35T/7A50T die **[fact]**. FDRI = 547,420 words = 5,420 frames x 101 **[fact]**. Confidence: high.
- **Packets:** a standard Vivado stream. BSPI 0x26B + BSPI_READ (master SPI x4, read opcode 0x6B), TIMER/WBSTAR 0 (no MultiBoot),
  COR0 0x02423FE5, COR1 0, CTL0 0x501 (DEC = 0), FAR 0, WCFG, one type-2 FDRI of the whole device, CRC, GRESTORE, DGHIGH,
  START, CRC, DESYNC. **Not compressed** (no MFWR), **not encrypted** (no DEC, no CBC). Both CRC writes verify **[fact]**.
- **Leading word 0x993966C2** = big-endian **CRC-32/BZIP2** of file[0x1000:EOF] (the Vivado `.bin`). Then FF fill to 0x1000
  (one 4 KiB sector) **[fact]**. No CPU image has an MSB-first CRC-32 table or 0x04C11DB7 literal, so the checker is unknown.
- **Frames:** 0-4389 are block 0 (logic) and 4390-5419 are block 1 (BRAM content). That is 3 FAR rows of 3/2/3 BRAM columns x 128 frames, each with 2 zero
  pad frames **[inference, high]**. 30 of 80 RAMB36-sized slots are non-zero, with 20 distinct contents (three contents x4, one x2). No strings.
- **Soft CPU:** not evident. The replication pattern fits DSP ROM tables. MicroBlaze is not ruled out **[inference, medium]**.
- **Config path:** the FPGA boots from its own QSPI flash, so an update rewrites that flash. DISPLAY has `sdrup`, `sdr1up`, `sdr2up`,
  `sdrchk1/2`, `sdrspi` and `sdrfile` (VMA 0x20110DEC..) plus SPI link counters. The SDR SPI bus belongs to DISPLAY, and SDR_UPDATE/RESET to MAIN.
  Leading hypothesis: DISPLAY writes the flash over SDR SPI while MAIN holds the FPGA in update/reset **[inference, medium]**.

## Follow-ups
- T06 (DISPLAY): trace the `sdrup`/`sdr1up`/`sdr2up`/`sdrchk1`/`sdrchk2`/`sdrspi` handlers (strings at VMA 0x20110DEC-0x20110E4C,
  not referenced by literal pools) and the SFL-SR update path. Find out who computes CRC-32/BZIP2, what the flash commands and addresses are,
  and whether the 4 KiB header lands at flash 0.
- T05/MAIN: find the SDR_UPDATE/SDR_RESET GPIO handling and the UART5 (SCI5) protocol to the FPGA (version readout "SDR : V..").
- docs/hardware.md (owner of that file): change the SDR FPGA row from "unknown vendor" to XC7A50T (IDCODE), add "master SPI x4 boot
  from on-module QSPI flash (BSPI 0x26B)", and note that the SDR SPI bus is DISPLAY-side while SDR_UPDATE/RESET are MAIN-side.
- Optional: confirming the BRAM slot mapping and decoding the BRAM INIT tables (NCO/FIR coefficients) needs the prjxray
  xc7a50t database (network). That would settle the MicroBlaze question.
