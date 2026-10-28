# T16 — Custom-firmware groundwork

**Status:** in progress · **Depends on:** T04, T11c

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
_(fill in as you go)_

## Follow-ups
