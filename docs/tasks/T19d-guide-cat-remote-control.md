# T19d — Guide: CAT remote control

**Status:** done · **Depends on:** T19 (style guide)

## Goal
Write the draft chapter `docs/guide/parts/05-cat-remote-control.md` with its SVG pictures in `docs/guide/img/`, for the single guide document, following the style guide in [T19](T19-illustrated-guide.md).

## Plan
Chapter `## 5. CAT remote control` in `docs/guide/parts/05-cat-remote-control.md`. Sources: `docs/cat-commands.md`,
`docs/cat-commands-primary.md` (grep only), `docs/code/main/{cat,menu,sci,peripherals}.md`, `docs/code/system.md` §2.2/§6.1,
`docs/custom-firmware.md`, `docs/tasks/T09-cat-commands.md` (proposed read-only tests).

Sections and figures:
- 5.1 What CAT is and where you plug in: `img/05-cat-ports.svg` (PC, USB hub, CP2105 two COM ports, TUNER/LINEAR jack, SCI3/SCI0/SCI2 into MAIN, port ids, start baud rates).
- 5.2 Anatomy of a command: `img/05-command-anatomy.svg` (byte boxes for `FA;`, `FA014074000;`, the answer, `?;`; read / set / answer).
- 5.3 The journey of `FA014074000;`: `img/05-command-journey.svg` (PC → CP2105 → UART → ring of 60 slots → main-loop parser → table lookup → handler → VFO record → FPGA NCO; reply / AI back) plus a Mermaid sequence diagram (read, set, AI broadcast).
- 5.4 The command map: `img/05-command-map.svg` (all 114 mnemonics as tiles: 92 documented, 22 undocumented coloured by risk; XT and VE marked).
- 5.5 The 22 undocumented commands by risk: `img/05-undocumented-risk.svg` (risk ladder: does nothing / read-only / changes settings / dangerous).
- 5.6 The SP service family: `img/05-sp-family.svg` (sub-letters → SDR FPGA, IF-DSP, ADC, EEPROM, cfg105, meters; ASCII vs binary-with-checksum frame).
- 5.7 Tests waiting for the owner: `img/05-pending-tests.svg` (test card, "not yet tested on the radio").
- 5.8 Menu settings over CAT (EX): short text + Mermaid flowchart (EX key → menu engine → RAM → sync loops).
- 5.9 Where to look.

## Findings
Draft chapter `docs/guide/parts/05-cat-remote-control.md` (`## 5. CAT remote control`): In short, then 5.1 the three CAT ports,
5.2 anatomy of a command (set / read / answer / `?;`), 5.3 the journey of `FA014074000;` (queue, one command per main-loop pass,
handler checks, VFO record, spread to FPGA / DISPLAY / AI), 5.4 the command map (114 = 104 + 10; 92 documented; `XT` not implemented;
`VE` needs P1), 5.5 the 22 undocumented commands by risk, 5.6 the `SP` service family (targets, ASCII vs binary checksummed frames,
the fixed "checksum bug"), 5.7 read-only tests waiting for approval (none tested), 5.8 `EX` menu access, 5.9 Where to look.
Neighbours are pointed to: chapter 2 (chip colours), 3 (normal operation), 4 (DISPLAY self-update stops CAT), 6 (menu engine), 8 (hacking).

Figures (7 SVG + 2 Mermaid), all checked with `xmllint` and `rsvg-convert -w 960`:
- `img/05-cat-ports.svg`: PC, USB hub, CP2105 Enhanced/Standard ports, TUNER/LINEAR jack, SCI3/SCI0/SCI2 into MAIN.
- `img/05-command-anatomy.svg`: byte boxes for `FA014074000;`, `FA;`, the answer and `?;`.
- `img/05-command-journey.svg`: the path of `FA014074000;` through MAIN and out to the FPGA, DISPLAY and AI.
- Mermaid sequence (Figure 5.4): read, set and AI broadcast.
- `img/05-command-map.svg`: all 114 mnemonics as tiles, coloured documented / does nothing / read-only / changes settings / dangerous.
- `img/05-undocumented-risk.svg`: risk ladder of the 22 undocumented commands.
- `img/05-sp-family.svg`: SP sub-commands → SDR FPGA / IF-DSP / ADC / meters / EEPROM / calibration table, plus both frame styles.
- `img/05-pending-tests.svg`: proposed read-only tests, each "not yet tested", plus the never-send list.
- Mermaid flowchart (Figure 5.9): `EX` → menu engine → RAM → DSP / FPGA / EEPROM.

## Glossary terms
- CAT — Computer Aided Transceiver: Yaesu's ASCII command protocol for controlling the radio from a PC.
- Mnemonic — the two-letter name at the start of every CAT command, such as `FA` or `MD`.
- Handler — the firmware function that carries out one CAT command after the parser has found it.
- Auto information (AI) — CAT mode in which the radio sends changed values to the PC without being asked; switched on per port with `AI1;`.
- Hold-off — a short wait (200 ms for CAT AI) before the next automatic message is sent.
- CP2105 — Silicon Labs USB-to-dual-UART bridge; gives the PC the two FT-710 COM ports.
- COM port — the PC's name for a serial port, here a virtual one provided over USB.
- UART — a serial port in hardware; on the RX651 MAIN CPU they are called SCI channels.
- TTL — logic-level serial signalling (0/5 V here) rather than RS-232 voltage levels.
- Ring buffer — a fixed set of slots used as a queue that wraps around; MAIN's CAT queue has 60 slots.
- Main loop — MAIN's single endless loop that runs every task in turn; MAIN has no operating system.
- NCO — numerically controlled oscillator: the digital local oscillator inside the FPGA that sets the receive or transmit frequency.
- EEPROM — the small non-volatile memory on MAIN that holds all settings, memory channels and calibration.
- Destination code — the region / market code stored in EEPROM that selects the market version (read and written by `JP`).
- Calibration table (`cfg105`) — 261-byte factory alignment table in EEPROM, reached by `SPN` (inference for its meaning).
- Settings image — the 10 665-byte block of settings and memory channels dumped by `E8` and restored by `E9`.
- Checksum — here an 8-bit sum of the frame bytes, used by the binary `SP` sub-commands.
- ADC — analog-to-digital converter; MAIN's ADCs measure power, voltages, current and temperature (`SPIR` reads them).
- FPGA — the programmable logic chip on the SDR board that does the digital radio signal processing.
- EX command — the CAT command that reads and writes setup-menu items by group, sub-group and item number.

## Reference issues
- `docs/cat-commands.md` "Counts" (and the T09 findings) say "12 of them do nothing", but the list right after it names 13
  (`BY ED EK EU RC RD RS RT RU` + `EN FS QS` + `KT`), and 22 − 9 real functions = 13. The guide names all 13 and calls them 13.
- `docs/code/main/menu.md` "EX set: control flow": the host sends `EX010104300;` (12 characters, a 3-digit value), but the next step
  says "length 9+4, 0300" and the item has 4 digits, so the frame should be `EX0101040300;`. The guide uses only the read example
  `EX010104;` → `EX0101040300;`, which the same page states.
- `docs/cat-commands-primary.md` `EX`: "length tests `len==9 | len==8`" while `docs/cat-commands.md` says read 9, set ≥ 10. The guide
  does not quote lengths for EX.
- `docs/code/main/cat.md` says `XT` is "documented in manual rev 2211-A"; `docs/cat-commands.md` lists it as documented in 2306-C.
  Not a contradiction (probably in both), but the two pages cite different revisions.

## Follow-ups
- Parent: fix the cross-chapter anchors (`#3-a-day-in-the-life`, `#4-firmware-files-and-updates`, `#8-hacking-and-custom-firmware`)
  and the `#glossary` links when assembling.
- The two Mermaid diagrams use `#59;` for `;` inside labels (as `docs/code/system.md` does); check they render on GitHub.
