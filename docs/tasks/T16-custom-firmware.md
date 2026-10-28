# T16 — Custom-firmware groundwork

**Status:** done · **Depends on:** T04, T11c

## Goal
Prepare everything needed to build and run the owner's own patches safely, without writing to the radio. Background and
evidence: [custom firmware feasibility](../custom-firmware.md).

## Deliverables
- `tools/sfl_encode.py` (stdlib): plaintext → SFL (43-byte key, salted CRC-32, tag line, comment box), with a round-trip
  test against all four shipped images (decode → encode must reproduce the original file byte for byte).
- The update loader's full acceptance rules (tag, length, version, per-image steps), together with T11c.
- A first harmless patch (e.g. a version or banner string in DISPLAY or MAIN), produced as an SFL and verified by
  decode, CRC check and an analysis diff. **Not flashed.**
- A written plan (for owner approval) to enable the DISPLAY USB-keyboard debug console (`debug_unlock` 0x20107E68,
  magic 0xA0B9C8E7 at 0x20450000), via a patch or a JTAG RAM write.
- A JTAG-only (volatile) "hello" bitstream plan for the SDR FPGA: pin and clock constraints from
  `docs/code/sdr/interfaces.md`, what is safe to drive, and the rollback (power cycle).
- The list of debug adapters needed for each recovery path.

## Notes / hints
- **Anything that writes to the radio needs the owner's explicit approval each time.**
- Never publish decoded or patched images.

## Plan
1. **Encoder.** `tools/sfl_encode.py` (stdlib, imports `sfl_decode`/`sfl_header`): `encode(plain)` = per-byte `+KEY[i%43]`;
   header = 8-line comment box (title, FILE NAME, PRODUCT NAME, FIRM VERSION, DATE, copyright) + 64-byte tag line
   (tag at col 0, length at col 16, CRC at col 32). Inputs: either `--raw` decoded payload (exact), or the converted
   binaries from `sfl_decode.py` (MAIN: re-emit S-records in the original record layout taken from a template SFL; SDR:
   lowercase hex + CRLF; DISPLAY/IFDSP: raw). A `--header-from <orig.SFL>` option copies the comment box so the round trip
   is exact; otherwise the box is generated from fields. Learn the exact header column layout from the four shipped files.
2. **Round-trip test** `tools/test_sfl_roundtrip.py` (`python3 -I`, unittest): for each of the four files in `Firmware/`,
   decode → encode (raw path and converted-binary path) → byte compare with the original; outputs in `build/t16/`.
3. **Harmless patch** in DISPLAY: pick a version/banner string (e.g. `YAESU FT-710 FIRMWARE UPDATE` title or a version
   string) with no length change; patch the copy in `build/t16/`, encode, decode again, check CRC and every update.md
   acceptance rule (name pattern, 64-char tag line, CRC, size = payload + 0x240, ≤ 6 MiB bank), byte diff = only the
   patched bytes, and a disassembly diff of `.text` (objdump) = none outside the string. Document in `docs/patches/README.md`.
4. **custom-firmware.md**: replace blocker 4 with the T11c acceptance list; fix the SDR update path (DISPLAY RSPI2 master on
   P8_3..6 + MAIN `FD/FE` bridge, `SDR_UPDATE` low = FPGA update-mode input) in the text and figure; add the 0x201110AC
   debug-gate patch; debug-adapter table per recovery path; link the plans.
5. **Plans** (in `docs/patches/README.md` or `docs/custom-firmware.md`): debug-console enable plan (option A patch,
   produced in build/ only; risks; rollback through dual-bank boot), FPGA JTAG "hello" plan (constraints, unknown package
   = first blocker, safe outputs, rollback = power cycle).
6. **J1004 vs J1005**: check the service manual p17/p35 text and render if needed.
Heartbeat after each step. Nothing is sent to the radio.

## Findings
- **Encoder** `tools/sfl_encode.py` (stdlib, `python3 -I`): `enc = plain + KEY[i % 43]`, tag line `<tag>`/length/CRC at
  columns 0/16/32 padded to 62 + CRLF, comment box 8 × (62 + CRLF) [fact, from the four files]. MAIN S-records are rebuilt
  from the original record layout (S0/S7 and the odd-length records come from the linker sections, so a template is
  needed for a byte-exact file); a generic 16-byte S3 layout is available without a template. `--check` runs the loader's
  acceptance rules. `tools/test_sfl_roundtrip.py`: 6 tests pass; raw, converted and regenerated-header paths reproduce
  all four shipped files byte for byte [fact]. Outputs in `build/t16/` only.
- **Patches** (`tools/t16_patches.py`, `docs/patches/README.md`), built and verified, **not flashed**:
  `banner` = `bootloader_screen` title `V01-02` → `T16-01` at DISPLAY VMA 0x204280D5 (4 bytes differ, CRC A2C6D222,
  listing diff = 2 data words); `debuggate` = 0x201110AC `movne r0,#0` → `#1` (1 byte, CRC D79669B5, 1 instruction).
  Both pass decode, CRC and all loader rules [fact]. `"FIRMWARE UPDATE      "` was rejected because it is `strcmp`-matched.
- **Debug-console plan** (owner approval): step 0 volatile JTAG write of 0xA0B9C8E7 to 0x20450000, step 1 SD update with
  the patched DISPLAY file. Main risk: every chain-1 slot sees every keyboard report, so typing `up0⏎` anywhere rewrites the
  loader region from SD [fact for dispatch]. Correction to the brief: after a *successful* DISPLAY update only the new bank
  has a valid flag, so the old bank is bootable only after an interrupted update [fact, update.md section 6]; rollback is
  the stock SFL via SD, or J6003 flag repair if the new bank crashes early.
- **SDR FPGA package: CSG324 or FGG484** [inference]: `tools/xc7_package_fit.py` maps the 116 used IOB sites of the stock
  bitstream (T15 FASM) onto prjxray-db package pins; only those two bond all of them (CPG236 57, CSG325 82, FTG256 97).
  Banks 14/15 LVCMOS33, bank 34 **18 LVDS output pairs**, bank 35 **16 LVDS input pairs** (resources.md says about 9 each)
  [fact for features per IOB tile]. The QSPI pins D00 (driven), D01–D03 (inputs) and FCS_B (driven) are user I/O, which
  means a fabric SPI-flash master [inference], consistent with T11c.
- **FPGA hello plan** (`docs/patches/fpga-jtag-hello.md`): stage 1 has no I/O at all (BSCANE2 USER1 readout of "HELO" + a
  CFGMCLK counter, USERID 0x7E570001), so it needs no pin constraint; SRAM load only, rollback = power cycle; DSP_CLK and
  all audio/scope links stop during the test. Stage 2 (one UART_DBG_TX output) waits for T15 pin mapping.
- **J1004, not J1005**: parts list p35: J1004 = `08FLT-SM2-TB` P1091201 (the 8-pin debug FFC), J1005 = `SB20-08WS` P0090615
  (a wire-to-board cable connector, p5 exploded view) [fact]. Matches T10c's reading of p17.
- `docs/custom-firmware.md`: blocker 4 replaced by the acceptance list; SDR/IFDSP update paths and figure corrected; gate
  patch added; DISPLAY dual-bank note; debug-adapter table per header.

## Proposed shared-file edits
- `docs/hardware.md`: "Debug header J1005" → **J1004** (lines ~67, 84, 231 and the "Unresolved" item "Pins 7 and 8 of J1005");
  add "J1005 is `SB20-08WS` P0090615, a wire-to-board connector (p35, p5)".
- `docs/code/sdr/resources.md` I/O section: "about 9 LVDS pairs" → 16 LVDS input pairs (bank 35) and 18 LVDS output pairs
  (bank 34), one per IOB tile; package CSG324 or FGG484 (`tools/xc7_package_fit.py`); the QSPI pins D00/FCS_B are driven
  and D01–D03 read as user I/O (fabric flash master), which answers part of "Special blocks" (STARTUPE2 likely used).
- `docs/code/sdr/interfaces.md`: in "What the pin map changes", replace the WP = write-protect reading with "update-mode
  input" (T11c/T10c) and link `docs/patches/fpga-jtag-hello.md`.
- `docs/sfl-format.md`: add "Encoding: `tools/sfl_encode.py` (T16), round trip `tools/test_sfl_roundtrip.py`" and the tag-line
  column layout (0/16/32, padded to 62).
- `docs/tooling.md`: list `tools/sfl_encode.py`, `tools/test_sfl_roundtrip.py`, `tools/t16_patches.py`,
  `tools/xc7_package_fit.py` (no new installs).
- `docs/tasks/README.md`: T16 → done.

## Follow-ups
- Owner: approve (or not) debug-console step 0 / step 1 and FPGA stage 1; read the FPGA package marking on the SDR module;
  measure the FFC pitch of J1004/J6003/J2009/J2001 before buying breakouts.
- T15: map `UART_DBG_TX`, the UART5 pins and the board-clock MRCC input from the IOBs; confirm the fabric flash master
  (STARTUPE2 `USRCCLKO`).
- Optional patch 2b: blank chain-1 slot 0 (`fwdbg_init`) so `up0`/`up1`/`up2`/`fw1up` cannot be typed by accident.
- Find where DISPLAY reports its own version to MAIN (for a visible, normal-mode version marker).
