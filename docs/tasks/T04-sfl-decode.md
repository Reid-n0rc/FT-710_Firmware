# T04 — SFL payload decoding

**Status:** done · **Depends on:** T03

## Goal
Recover the payload encoding, and write `tools/sfl_decode.py` to turn each SFL into a raw binary under `build/`.

## Deliverables
- `docs/sfl-format.md` (encoding section) explaining the method and how it was derived.
- `tools/sfl_decode.py` (stdlib only), usage: `python3 -I tools/sfl_decode.py Firmware/X.SFL build/X.bin`.
- Validate: the decoded output must show plausible code (a vector table, readable strings like CAT command mnemonics, version strings).

## Notes / hints
- Repeating 32-byte blocks in long runs suggest a fixed XOR keystream with period 32 (or a per-position substitution). Known-plaintext from erased flash (likely 0xFF or 0x00) should reveal the key. Test both.
- The keystream may differ per image, so check all four.
- Decoded binaries stay in `build/` (gitignored). Never commit them.

## Plan
1. Statistics on each payload: find the most common 32-byte blocks (erased-flash candidates), and check whether the period-32 phase is aligned to the payload start (0x240) or to absolute file offsets.
2. Assume erased = 0xFF or 0x00. Derive the candidate key K[i] = C ^ P (XOR) and C - P (add) for each repeated block. Compare candidates across positions and images to see if the key is fixed, drifts with offset (e.g. a function of offset>>5), or differs per image.
3. Apply the candidate to a whole payload and check the entropy, strings, and vector table.
4. Write tools/sfl_decode.py, decode all four images into build/, validate them (vector table, `strings`, version/CAT/YAESU strings), and then test the checksum family from docs/sfl-format.md over the decoded data.
5. If it resists, record what was ruled out, set the status to partial, and propose follow-ups.
Exploration scripts live in the session scratchpad (not committed).

## Findings
- **Encoding:** `plain[i] = enc[i] - KEY[i % 43]` (mod 256), with phase 0 at payload offset 0 (file 0x240). KEY is a fixed 43-byte permutation of 1..43, the same for all four images, with no positional drift. The "period 32" from T03 was wrong: the period is 43. Derived from IFDSP's leading zero-fill run (ciphertext = key). It also explains SDR's run (plaintext `f` = 0x66). Full details and the key are in docs/sfl-format.md.
- **Confirmed in DISPLAY code:** decoder at VMA 0x2011497C, encoder twin at 0x201149E0, KEY at 0x20428840 (the start of .data; file offset 0x328840). DISPLAY load base is 0x20100000.
- **Checksum solved:** CRC-32/ISO-HDLC (zlib) over the **encoded** payload, then 4 salt bytes `A6 EC 9E 13`, routine at 0x20114A64. Matches all four files. T03 missed it because of the salt, not the CRC variant.
- **Plaintext formats:** MAIN is a Motorola S-record (Renesas RX: reset vector 0xFFF8FBDB, code 0xFFF80000–0xFFFFFFFF, option-setting memory 0xFE7F5D00). DISPLAY is a raw ARM A32 image (base 0x20100000, RZ/A-like 0x18000000 SPI flash window). IFDSP is a raw NXP i.MX RT6xx FlexSPI boot image (FCFB at 0x400, Cortex-M vectors at 0x1000, XIP base 0x08000000, reset 0x080011A9). SDR is ASCII hex of a Xilinx 7-series bitstream (IDCODE 0x0362C093, Artix-7 XC7A50T per the Xilinx IDCODE table).
- **Validation:** every S-record checksum in MAIN is valid. Strings found: MAIN `V01-12`, the menu texts, and the CAT mnemonic table plus answer templates (`FA000000000;`, `IF…;`, `MD00;`). DISPLAY `YAESU FT-710 FIRMWARE UPDATE`, `YAESU FT-710 BOOT LOADER V01-02`, and the SFL filename prefixes. IFDSP `DSP Version %04X`.
- `tools/sfl_decode.py` decodes, verifies the CRC (exits 1 on a mismatch), and converts the output: S-record → flat binary per address cluster, SDR hex → binary. `--raw` writes the plaintext verbatim. Outputs: `build/FT-710_{MAIN_V0112,DISPLAY_V0108,IFDSP_V0101,SDR_V0104}.bin` (+ `FT-710_MAIN_V0112.bin.FE7F5D00.bin`).
- **Cross-check with docs/hardware.md (T02):** everything agrees. MAIN = Renesas RX651 R5F56514 (512 KB code flash = exactly 0xFFF80000–0xFFFFFFFF). DISPLAY = RZ/A1H R7S721001 (Cortex-A9, on-chip SRAM at 0x20000000, SPI flash window at 0x18000000). IFDSP = NXP i.MX RT685 (Cortex-M33 side; FlexSPI XIP 0x08000000). SDR = the FPGA whose vendor T02 could not determine is a **Xilinx 7-series**, IDCODE 0x0362C093 (Artix-7 XC7A50T by the IDCODE table). This is new information for hardware.md, but not edited by T04.

## Follow-ups
- Add the SDR FPGA identification (Xilinx 7-series, IDCODE 0x0362C093 → XC7A50T) to docs/hardware.md, and record the load addresses in docs/memory-maps.md.
- Ghidra import parameters: MAIN = RX (little-endian) @0xFFF80000. DISPLAY = ARM v7 LE @0x20100000. IFDSP = Cortex-M (Thumb) @0x08000000. SDR is an FPGA bitstream, not CPU code (skip decompilation).
- MAIN contains the CAT mnemonic table (`ABACAGAI…`). It includes entries not obviously in the public CAT manual (e.g. `EO E8 E9 FD KT PE ZZ VE JP`). Good starting point for the CAT-discovery task.
- SDR hex text starts with a 32-bit word `993966C2` before the bitstream. Its meaning (a length or CRC used by the loader) is unknown and can be found in the DISPLAY loader.
- ~~AGENTS.md and the T03 alignment note still say "period-32"~~: fixed by the parent.
- The encoder twin (0x201149E0) plus the CRC mean a re-encoder is trivial (for later custom firmware). Don't build or flash anything without the owner's approval.