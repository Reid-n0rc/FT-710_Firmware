# T19b — Guide: A day in the life (power-on, tuning, transmit, scope)

**Status:** in progress · **Depends on:** T19 (style guide)

## Goal
Write the draft chapter `docs/guide/parts/03-a-day-in-the-life.md` with its SVG pictures in `docs/guide/img/`, for the single guide document, following the style guide in [T19](T19-illustrated-guide.md).

## Plan
Agent T19b, 2026-10-28. Sources: docs/code/system.md §4 and §6 (flows), main/{README,radio-control,tx-protection,ui-keys,eeprom,peripherals},
display/{README,boot-rtos,input,gui,mainlink}, ifdsp/{README,hifi4}, sdr/README, and display/spi-links.md for the PC stream.

Chapter `## 3. A day in the life of the radio`, part file `docs/guide/parts/03-a-day-in-the-life.md`:
- 3.1 Switching on — SVG `03-power-on-timeline.svg`: vertical timeline, four chip lanes (DISPLAY, MAIN, SDR FPGA, IFDSP), from mains on
  through standby, power key, F0 hello, FPGA then DSP release, to the running loop.
- 3.2 Switching off — SVG `03-power-off.svg`: three triggers (power key, CAT PS0, low supply) converge on "save EEPROM, tell DISPLAY,
  software reset", back to the radio-off loop.
- 3.3 Turning the knob or pressing a key — SVG `03-knob-to-screen.svg`: knob/key icon → DISPLAY (8 ms / 1 ms scans) → E1/E0 → MAIN
  record + refresh flag → FPGA NCO 0x18/0x19 (two passes) → status frame → screen redraw (33 ms) and CAT AI. Mermaid sequence for the dial.
- 3.4 Changing band or mode; remembering settings — SVG `03-band-stack.svg`: 2 VFOs × 3 levels × 12 bands of 90-byte records, the operating
  record, the RAM mirror of the EEPROM and when it is written (mention only; chapter 6 goes deeper).
- 3.5 Transmitting — SVG `03-tx-gates.svg`: PTT sources in priority order funnel into the arbiter and the band/inhibit gates, then the
  sequencer; Mermaid `stateDiagram-v2` of trx_state 0..8; SVG `03-us-60m-quirk.svg`: `lo <= f < hi` number line showing why a single-point
  60 m row never matches *(inference)*; protections (SWR flag, PA temperature/fan, TOT, supply, TX inhibit line).
- 3.6 The scope and waterfall — SVG `03-scope-path.svg`: antenna → ADC → FPGA FFT → SPI → DISPLAY → scope/waterfall and the FT4222H 4 KiB block
  to the PC; MAIN only sets centre/span/level.
- 3.7 Audio — SVG `03-audio-path.svg`: RX and TX audio through the FPGA, HiFi4 (12 kHz, 24-sample 2 ms blocks) and the codec, the REC/PLAY SPI
  link to the DISPLAY, and the 12 kHz vs 16 kHz WAV open question.
- 3.8 Where to look.

## Findings

## Follow-ups
