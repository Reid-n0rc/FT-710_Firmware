# T19b — Guide: A day in the life (power-on, tuning, transmit, scope)

**Status:** done · **Depends on:** T19 (style guide)

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
Agent T19b, 2026-10-28. Draft chapter `docs/guide/parts/03-a-day-in-the-life.md` (`## 3. A day in the life of the radio`) with 7 sections
plus "Where to look": 3.1 switching on, 3.2 switching off, 3.3 knob and keys, 3.4 band/mode and the EEPROM mirror (mention only),
3.5 transmitting (PTT sources, gates, US 60 m quirk as *(inference)*, sequencer, protections, back to RX), 3.6 scope/waterfall and the
FT4222H PC stream, 3.7 audio with the 12 kHz vs 16 kHz open question. No new findings; every claim is from the reference pages listed in
the plan, with their tags kept.

Figures (8 SVGs in `docs/guide/img/`, each checked with xmllint and rsvg-convert, PNG inspected):
- `03-power-on-timeline.svg` — Figure 3.1, four-lane vertical timeline, five phases.
- `03-power-off.svg` — Figure 3.2, three triggers → save → 0x7F → reset; restart and interrupted-save notes.
- `03-knob-to-screen.svg` — Figure 3.3, knob/key icons → DISPLAY → MAIN → FPGA/PC/screen, with an `E1` byte strip.
- `03-band-stack.svg` — Figure 3.4, 3 × 12 band-stack grid, 90-byte record to scale, RAM mirror ↔ EEPROM chip.
- `03-tx-gates.svg` — Figure 3.5, PTT priority list → selector → arbiter → allowed? → sequencer; four protection boxes.
- `03-us-60m-quirk.svg` — Figure 3.6, number line 5320–5410 kHz, Europe range row vs US single-point rows, worked `lo <= f < hi` test.
- `03-scope-path.svg` — Figure 3.7, antenna → ADC → FPGA → SPI → DISPLAY (scope, waterfall, AF-FFT, screen) → 4 KiB PC block to scale → FT4222H → PC.
- `03-audio-path.svg` — Figure 3.8, RX/TX audio through FPGA, HiFi4 threads and codec, 2 ms block ruler, REC → WAV on SD, open-question box.

Mermaid: one `sequenceDiagram` (knob step, 4 participants) and one `stateDiagram-v2` (RX/TX sequencer, 8 states). Not rendered locally
(no mmdc in the container); both use only basic syntax.

## Glossary terms
- RZ/A1H — the Renesas ARM chip on the DISPLAY board: touch screen, keys, knobs, SD card, firmware updates.
- RX651 — the Renesas RX microcontroller on the MAIN board that owns the radio state, CAT and TX/RX switching.
- XC7A50T — the Xilinx Artix-7 FPGA on the SDR module that digitises, mixes and filters the RF.
- IFDSP / RT685 — the NXP i.MX RT685 (Cortex-M33 + HiFi4 DSP core) that does the audio-frequency signal processing.
- HiFi4 — the Cadence DSP core inside the RT685 that runs the receive and transmit audio threads.
- EEPROM — the 32 KB SPI memory chip on the MAIN board that keeps all settings, memories and calibration.
- RAM mirror — MAIN's byte-for-byte copy of the EEPROM in RAM; all code works on it and writes back selectively.
- Operating record — the 90-byte record per VFO that holds mode, settings, clarifier, frequency and name; memories use the same layout.
- Band stack — per VFO, three stored records for each of the 12 bands, recalled with the band keys.
- QMB — Quick Memory Bank: a small set of quick-store memory slots.
- Bitstream — the configuration file an FPGA loads at power-on to become its circuit.
- NCO — numerically controlled oscillator; the FPGA's digital local oscillator that sets the RX or TX frequency.
- DSP_CLK — the 18.432 MHz clock the FPGA generates for the RT685.
- Codec — the TLV320AIC3204 chip that converts audio between analog (mic, speaker) and digital (I2S).
- I2S — a serial bus for digital audio samples between chips.
- AF-FFT — the audio-frequency spectrum the DSP computes and sends to the DISPLAY.
- Waterfall — the scrolling history display of the spectrum over time.
- FT4222H — FTDI's USB-to-SPI bridge chip that lets a PC read the scope and status data.
- PTT — push to talk: any input that asks the radio to transmit.
- VOX — voice-operated transmit, triggered by a voice-detect bit from the DSP.
- TOT — time-out timer that limits the length of one transmission.
- SWR — standing-wave ratio, computed by MAIN from forward and reflected power.
- ALC — automatic level control of the transmitter drive.
- Destination code / region table — the stored region code and the table of TX frequency ranges it selects.
- AI (Auto Information) — CAT mode in which the radio sends changes to the PC without being asked.
- Soft timer — one of MAIN's software timers, ticked by a hardware timer interrupt, used to pace its loop tasks.

## Reference issues
1. **Supply-voltage ADC channel.** [main/tx-protection.md](../code/main/tx-protection.md) (protection table) and
   [main/peripherals.md](../code/main/peripherals.md) (power state diagram) say the under-voltage check reads AN003 `PA_VDD`.
   [main/eeprom.md](../code/main/eeprom.md) ("Power fail") says the ADC result 0x20B08 is "AN002 in the SPIR order", and tx-protection.md
   itself uses AN002 for `MCUP_FOR` (forward power). The guide avoids naming the channel.
2. **PS0 power-off path.** The power state diagram in [main/peripherals.md](../code/main/peripherals.md#power-on--off) sends the PS0
   request (0x20F4B = 1, 0x20B39 = 0x10) into "io_task: 0x20B30 == 2 → save, sw_reset". [main/eeprom.md](../code/main/eeprom.md) and
   [main/README.md](../code/main/README.md#power-states) say 0x20B30 = 2 is the power key, and PS0 goes through `power_down_save`, run by
   `displink_tx_schedule` on 0x20F4B. The guide follows system.md §4.2 and stays at the level both agree on.
3. **Encoder id 6.** [display/input.md](../code/display/input.md#rotary-encoders-and-pots) says id 6 is the mouse wheel on the main screen;
   [main/ui-keys.md](../code/main/ui-keys.md#encoders-e1) guesses id 6 is the main dial in a high-resolution or alternate mode. Not used in
   the guide. (Settled in T19h b3: id 6 is the USB mouse wheel on the main screen, `mouse_wheel_event` 0x2015FAC4 [fact].)
4. **E1 frame wording (minor).** [display/input.md](../code/display/input.md#rotary-encoders-and-pots) writes the E1 frame as
   `AA 00 | 07 00 | E1 …`, which reads like wire bytes; [display/mainlink.md](../code/display/mainlink.md#1-summary) says the 0xAA marker and
   length are only an in-memory header and never sent. The guide uses the wire form `E1 id step 0 0 0 sum`.

## Follow-ups
- Parent: map the `[term](#glossary)` links to the final glossary anchors and renumber figures 3.1–3.8 if chapters change.
- Render the two Mermaid diagrams once on GitHub (no local renderer here).
