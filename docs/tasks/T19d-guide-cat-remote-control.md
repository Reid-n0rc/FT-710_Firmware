# T19d — Guide: CAT remote control

**Status:** in progress · **Depends on:** T19 (style guide)

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

## Follow-ups
