# T19a — Guide: The radio and how the chips talk

**Status:** in progress · **Depends on:** T19 (style guide)

## Goal
Write the draft chapter `docs/guide/parts/01-the-radio.md` and `docs/guide/parts/02-how-the-chips-talk.md` with its SVG pictures in `docs/guide/img/`, for the single guide document, following the style guide in [T19](T19-illustrated-guide.md).

## Plan
Agent T19a, 2026-10-28. Two draft chapters, each opening every section with a figure.

**Chapter 1, `parts/01-the-radio.md` ("## 1. The radio at a glance").** Sections:
1.1 The boards and where the chips sit — fig `01-units.svg` (sketch of MAIN, DISPLAY, PA, JACK units and the plug-in SDR module, chips in place; not to scale).
1.2 Four brains — fig `01-four-brains.svg` (one card per chip: core, OS, job, firmware file).
1.3 Four firmware files — fig `01-firmware-files.svg` (SFL file → storage → chip; pointer to chapter 4).
1.4 The receive path — fig `01-rx-path.svg` (antenna → filters → ADC → FPGA DDC → HiFi4 → codec → speaker, with icons; scope branch).
1.5 The transmit path — fig `01-tx-path.svg` (mic → codec → HiFi4 → FPGA up-conversion → DAC? → PA → antenna).
1.6 The USB side — fig `01-usb-tree.svg` (hub, CP2105 COM ports, CM119B, FT4222H).
1.7 Where to look.

**Chapter 2, `parts/02-how-the-chips-talk.md` ("## 2. How the chips talk").** Sections:
2.1 Who is the boss — fig `02-link-map.svg` (every inter-chip link, master/slave, speed).
2.2 DISPLAY ↔ MAIN — fig `02-display-frame.svg` (byte anatomy of the `F0` hello + ACK, stop-and-wait) + Mermaid sequence of one exchange with a retry.
2.3 MAIN → SDR and MAIN → DSP register frames — fig `02-register-frame.svg` (worked example `r000032` → `r010437` = 0x0104, and a write → 06).
2.4 The shadow-register idea — fig `02-shadow.svg` (wanted vs shadow table, one write per pass, ACK updates shadow).
2.5 The DISPLAY's SPI data links — fig `02-spi-links.svg` (scope 1700 B, DSP 4600 B, PC 4096 B frame layouts drawn to scale).
2.6 Reset and update wires — fig `02-control-wires.svg` (RX_RESET/RX_UPDATE/RX_PWR_ON, SDR_RESET/SDR_UPDATE, DSP_RESET/DSP_UPDATE, normal levels).
2.7 When a link is down — Mermaid flowchart (per link: retries, timeouts, boot errors, reset).
2.8 Where to look.

Time-ordered flows (power-on, tuning, TX, scope) are left to chapter 3 and updates to chapter 4, with pointers only.

## Findings

## Follow-ups
