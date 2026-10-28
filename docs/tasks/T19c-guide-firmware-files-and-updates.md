# T19c — Guide: Firmware files and updates

**Status:** done · **Depends on:** T19 (style guide)

## Goal
Write the draft chapter `docs/guide/parts/04-firmware-files-and-updates.md` with its SVG pictures in `docs/guide/img/`, for the single guide document, following the style guide in [T19](T19-illustrated-guide.md).

## Plan
Agent T19c, 2026-10-28. Sources: docs/sfl-format.md, docs/code/display/update.md, docs/memory-maps.md, docs/custom-firmware.md,
docs/tasks/T18-renesas-docs-check.md, docs/code/main/dsp-link.md (ISP bridge), docs/code/sdr/bitstream.md, docs/patches/README.md,
docs/code/system.md §5. Chapter `## 4. Firmware files and how updates work`:

- 4.1 What Yaesu ships: the zip (4 SFL files + update manual). Fig `04-update-zip.svg`.
- 4.2 Anatomy of an SFL file: comment box / tag line / encoded payload, byte offsets, key + salted CRC. Fig `04-sfl-anatomy.svg`.
- 4.3 Cracking the code: the IFDSP zero run gives away the 43-byte key; SDR = key + 0x66; MAIN turns into S-records; CRC salt
  found in the DISPLAY loader. Fig `04-key-trick.svg`; Mermaid flow of the tools (decode, encode, round trip).
- 4.4 What is inside each payload: MAIN S-records, DISPLAY raw ARM image, IFDSP FlexSPI image, SDR hex -> header + Vivado bitstream.
  Fig `04-payloads.svg`.
- 4.5 Updating, from the front panel: SD card folder, menu, DISPLAY first, reboot. Mermaid flowchart.
- 4.6 Behind the screen: DISPLAY updates every chip. Board sketch `04-update-paths.svg`, then
  4.6.1 DISPLAY itself (flash map + flags) `04-display-banks.svg`; 4.6.2 MAIN serial boot command ladder `04-rx-boot.svg`;
  4.6.3 IFDSP through MAIN (Mermaid sequence); 4.6.4 SDR blocks into the FPGA flash `04-sdr-flash.svg`.
- 4.7 What the loader really checks: checked / not checked `04-checks.svg`; MAIN option-setting memory danger box
  `04-osm-danger.svg`; ~1000-update limit *(inference)*; pointer to chapter 8.
- 4.8 Where to look.

## Findings
Draft chapter `docs/guide/parts/04-firmware-files-and-updates.md` (`## 4. Firmware files and how updates work`), sections 4.1–4.8
as planned, with 4.6.1–4.6.4 as `####` subsections. It covers: the update zip; SFL byte layout (comment box, tag line with
tag/length/CRC, payload); the 43-byte additive key and the salted CRC-32; the key-recovery story (IFDSP zeros, SDR +0x66, MAIN
`S00E…`, salt found in the DISPLAY loader); the tools (`sfl_decode.py`, `sfl_encode.py --check`, `test_sfl_roundtrip.py`); the
four decoded payload formats; the user's update flow (SD folder, menu, DISPLAY first, Ready/Broken file, writer order, reset,
recovery screens); the four writers (DISPLAY banks and flags, MAIN Renesas serial boot command sequence, IFDSP NXP ISP relayed
by MAIN, SDR 4 KiB blocks via MAIN + RSPI2, exact size 0x43075A, header last); what the loader checks and does not check;
the option-setting-memory danger box (FSPR, SPE, 0x45) and the ~1000-update limit *(inference)*; Where to look.
Chapter 8 gets only pointers (patches, `#UP0`, maintenance screen, JTAG recovery).

Figures (13): 10 SVGs in `docs/guide/img/`, each checked with xmllint + rsvg-convert and viewed:
`04-update-zip.svg` (4.1), `04-sfl-anatomy.svg` (4.2), `04-key-trick.svg` (4.3), `04-payloads.svg` (4.5),
`04-update-paths.svg` (4.7), `04-display-banks.svg` (4.8), `04-rx-boot.svg` (4.9), `04-sdr-flash.svg` (4.11),
`04-checks.svg` (4.12), `04-osm-danger.svg` (4.13); and 3 Mermaid figures: tools flow (4.4), user update flow (4.6), IFDSP
relay sequence (4.10).

## Glossary terms
- SFL — Yaesu's firmware file container: 512-byte comment box, 64-byte tag line, payload scrambled with a 43-byte additive key.
- Salt — extra bytes mixed into a checksum so that a standard algorithm on the data alone does not reproduce it (here `A6 EC 9E 13`).
- CRC-32 — 32-bit cyclic redundancy check used to detect corrupted data (zlib variant here).
- S-record (Motorola) — text format for firmware: each line holds an address, data bytes and a checksum.
- Bitstream — the configuration file that defines an FPGA's logic and wiring, loaded at power-up.
- Boot ROM — fixed code inside a chip that runs at reset and can program the chip's flash over a serial port.
- Serial boot mode — RX651 start-up mode, selected by a pin at reset, in which the boot ROM accepts programming commands over SCI1.
- ISP (in-system programming) — programming a chip's flash in the finished product through its boot ROM, here NXP's serial ISP on the RT685.
- Option-setting memory — a small flash area in the RX651 holding start-up and security settings (watchdog, ID code, protections).
- XIP (execute in place) — running code directly from external flash instead of copying it to RAM first.
- Flash bank / bank flag — one of two firmware copies in the DISPLAY's SPI flash, and the 20-byte record that marks a copy as valid.
- QSPI flash — serial NOR flash on a 4-bit SPI bus, used to store firmware or an FPGA bitstream.
- UART — asynchronous serial port; the DISPLAY–MAIN link and the update paths run over UARTs.
- Archive attribute — FAT file flag set when a file is written; the update loader requires it.

## Reference issues
1. `docs/custom-firmware.md` ("Update and recovery paths", DISPLAY bullet) names the bank writer `display_flash_write_bank`
   0x2015F1F0. `docs/code/display/update.md` §9/§10 names 0x2015F1F0 `fwdbg_verify_bank1` (the `fw1chk` debug verifier); the
   user-path writer there is `fwobj_display_run` 0x201607E8. The guide uses the update.md names.
2. `docs/code/display/update.md` §8 sequence diagram: "header block last, at block 0x240 (address 0x480000)". With 4 KiB blocks
   0x240 is address 0x240000, so the block number or the unit is off. Related: §1 and custom-firmware.md say "536 blocks of
   4 KiB are written", while the §8 loop is i = 0..535 plus a separate header block (537 writes). The guide says "blocks 0…535,
   then the header block" and avoids a total.
3. `docs/sfl-format.md` "How it was derived" step 1 says the repeating run sits "at the start of IFDSP and SDR" and SDR's run is
   key + 0x66. SDR's payload actually starts with the text `993966c2`; the key + 0x66 run comes from the `ffff…` padding that
   follows. The guide says "the SDR file had the same run, shifted by 0x66" without "at the start".
4. Cosmetic: `docs/code/display/update.md` repeats names in a few places (heading "Write sequence (`fwobj_display_run`,
   `fwobj_display_run`)", "`gpio_rx_update_b` `gpio_rx_update_b`", "`fwobj_ifdsp_ctor`(…,1)`" with a stray backtick).

## Follow-ups
- Parent: renumber figures, fix `#glossary` anchors, check the Mermaid blocks render on GitHub (not rendered locally: no
  mermaid-cli in the container).
- Reference issues 1–3 above need a fix in the reference pages (not done here, per the T19 rules).
