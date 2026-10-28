# T19a — Guide: The radio and how the chips talk

**Status:** done · **Depends on:** T19 (style guide)

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
Agent T19a, 2026-10-28. Both draft chapters are written; every figure was checked with `xmllint` and rendered with `rsvg-convert -w 960`.

**Chapter 1, [`parts/01-the-radio.md`](../guide/parts/01-the-radio.md)** (7 sections): boards and chip placement, the four brains (role,
core, OS), the four SFL files and where each one lives, the receive path, the transmit path, the USB side, and where to look.
Figures (6 SVG):
- `img/01-units.svg` — sketch of the DISPLAY, MAIN, PA and JACK units and the plug-in SDR module, with chips in place
- `img/01-four-brains.svg` — one card per chip: core, OS, job, firmware file
- `img/01-firmware-files.svg` — SD card → DISPLAY → each chip's flash (via MAIN for DSP/FPGA)
- `img/01-rx-path.svg` — antenna → front end → ADC → FPGA tuner → HiFi4 → codec → AF amp → speaker, with icons and scope branches
- `img/01-tx-path.svg` — mic → codec → HiFi4 → FPGA up-converter → DAC (inference) → PA → antenna
- `img/01-usb-tree.svg` — PC → hub → CP2105 (two COM ports, RTS/DTR), CM119B, FT4222H

**Chapter 2, [`parts/02-how-the-chips-talk.md`](../guide/parts/02-how-the-chips-talk.md)** (8 sections): who is the boss, the
DISPLAY ↔ MAIN link (frame anatomy, stop-and-wait, encoder merging), the r/w register frames with worked examples (`r000032` →
`r010437` = 0x0104; `w0022006405` → `06`), the shadow-register idea, the three SPI data links, the reset/boot-mode wires, and what
happens when a link is down.
Figures (6 SVG + 2 Mermaid):
- `img/02-link-map.svg` — every link, master/slave direction and speed
- `img/02-display-frame.svg` — byte-by-byte `F0 01 08 20 23 06 29 00 6B` hello, ACK, 0x60 reply, line timing
- `img/02-register-frame.svg` — character boxes with hex codes for a read, its reply, a write and the ACK
- `img/02-shadow.svg` — wanted vs shadow table and the one-write-per-pass retry loop
- `img/02-spi-links.svg` — scope (1700 B), DSP (4600 B each way) and PC (4096 B) frames drawn to one byte scale
- `img/02-control-wires.svg` — RX_PWR_ON/RX_RESET/RX_UPDATE, SDR_RESET/SDR_UPDATE, DSP_RESET/DSP_UPDATE with normal and update levels
- Mermaid sequence (figure 2.3): one DISPLAY ↔ MAIN exchange with a lost frame and resend
- Mermaid flowchart (figure 2.8): the DISPLAY's reaction when MAIN stops answering

Figure captions are numbered 1.1–1.6 and 2.1–2.8 (the Mermaid figures count). Time-ordered flows are left to chapter 3 and updates to
chapter 4, with pointers only. Two small generator scripts (byte boxes, to-scale frames) were used for three SVGs; only the SVG output is
committed.

## Glossary terms
- ACK / NAK — single-byte "received OK" (0x06) and "received bad" (0x15) answers on the serial links.
- AGC — automatic gain control: keeps the audio level steady as the signal strength changes.
- bitstream — the configuration file that wires up an FPGA's logic at power-on; the FPGA's "firmware".
- CAT — Computer Aided Transceiver: Yaesu's text command protocol for controlling the radio from a PC (`FA…;`, `MD…;`).
- codec — a chip with both an ADC and a DAC for audio; here the TI TLV320AIC3204 between the DSP and the speaker/mic.
- CP2105 — Silicon Labs USB-to-dual-UART bridge; gives the PC two COM ports to MAIN.
- DDC — digital down-converter: mixes a sampled RF signal down to near zero and filters it to a narrow, slower stream.
- DMA — direct memory access: hardware that copies data between a peripheral and memory without the CPU.
- DSP — digital signal processor; here the HiFi4 core in the i.MX RT685 (the "IFDSP").
- EEPROM — small non-volatile memory for settings; MAIN's is a 32 KB SPI part.
- 8N2 — UART line format: 8 data bits, no parity, 2 stop bits.
- FPGA — field-programmable gate array: a chip of configurable logic; here a Xilinx Artix-7 XC7A50T.
- FT4222H — FTDI USB-to-SPI bridge on the DISPLAY unit; streams scope data to a PC.
- I2S — a standard serial bus for digital audio samples between chips.
- LVDS — low-voltage differential signalling: fast pairs of wires used between the ADC/DAC and the FPGA.
- machine mode — the RT685 console mode (entered with `i DB00`) without echo or prompts, used by MAIN.
- MOX — manual transmit: a front-panel button that keys the transmitter.
- NCO — numerically controlled oscillator: a digital sine generator whose frequency is set by a register.
- PTT — push-to-talk: any input that puts the radio into transmit.
- QSPI — quad SPI: a 4-bit-wide SPI bus used for fast flash chips.
- real-time OS — a small operating system that schedules tasks with fixed timing (µITRON on the DISPLAY, FreeRTOS on the M33).
- register file — a block of numbered 16-bit values in the FPGA or DSP that MAIN reads and writes over its UART.
- SDR — software-defined radio: a radio that digitises the RF early and does mixing and filtering in logic or software.
- serial boot mode — a mode built into a chip's ROM that accepts new firmware over a UART; selected by a pin at reset.
- service CAT commands — the undocumented `SP…` CAT family (`SPSR/SPSW`, `SPDR/SPDW`) that reads and writes FPGA/DSP registers directly.
- SFL — Yaesu's firmware file format: a text header plus a scrambled, CRC-checked payload.
- shadow register — MAIN's copy of the last value a remote register acknowledged; a write is sent only when the wanted value differs.
- SPI — serial peripheral interface: a clocked serial bus with one master and one or more slaves.
- sum8 — checksum = low byte of the sum of all bytes before it.
- UART — asynchronous serial port (start bit, data bits, stop bits), the RX651 calls them SCI.
- VFO — variable frequency oscillator: the radio's tuning "slot" (VFO A/B) holding frequency and mode.

## Reference issues
1. **FPGA reply format and length.** [system.md §3](../code/system.md#3-inter-cpu-protocol-summary), row MAIN → SDR, says "reply always
   7 B" and "reply 0x06 for a write, `x VVVV ss` for a read". [main/sdr-link.md](../code/main/sdr-link.md) Overview and "Reply" table
   also say the FPGA "always answers with 7 bytes" and call reply byte 0 "probably an echo [guess]". The T15e note at the end of
   sdr-link.md and [sdr/netlist.md §5.2](../code/sdr/netlist.md) show (simulation fact) that the FPGA answers a write with **one** byte
   0x06 and a read with `r` + value + sum (byte 0 is `r`, e.g. `r010437`). The guide follows T15e. The older text should be updated.
2. **ADC sample rate.** [system.md §2.3](../code/system.md#23-signal-path-receive-and-transmit) and [sdr/README.md](../code/sdr/README.md)
   say "ADC ~250 MSPS"; [main/sdr-link.md](../code/main/sdr-link.md) reg 0x03 reasons "fs/2 = 62.5 MHz, the Nyquist zone of a 125 MSPS ADC
   [inference]"; [hardware.md](../hardware.md) gives a 250 MHz sampling clock, "Divide 250MHz by 2" and a 125 MHz FPGA. The pages do not agree
   whether the ADC samples at 250 or 125 MSPS. The guide only says "250 MHz sampling clock, FPGA at 125 MHz".
3. **DSP boot retry.** [main/dsp-link.md](../code/main/dsp-link.md#boot-handshake) says each boot read is tried once and a clear "ready"
   bit fails the boot (no re-poll) **[fact]**; the sequence diagram in [ifdsp/control-link.md](../code/ifdsp/control-link.md#machine-mode-the-main-link)
   shows "loop until reg 1 bit 0 = 1". The guide follows dsp-link.md (MAIN's code).

## Follow-ups
- Parent: renumber figures when assembling, point the `#glossary` links at real anchors, and merge the glossary terms above.
- Fix the three reference issues in system.md, sdr-link.md and control-link.md (and settle the ADC rate, issue 2).
