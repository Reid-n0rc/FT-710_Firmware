# T19c — Guide: Firmware files and updates

**Status:** in progress · **Depends on:** T19 (style guide)

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

## Follow-ups
