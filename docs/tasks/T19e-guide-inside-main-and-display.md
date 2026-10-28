# T19e — Guide: Inside MAIN and DISPLAY

**Status:** in progress · **Depends on:** T19 (style guide)

## Goal
Write the draft chapter `docs/guide/parts/06-inside-main-and-display.md` with its SVG pictures in `docs/guide/img/`, for the single guide document, following the style guide in [T19](T19-illustrated-guide.md).

## Plan
Agent, 2026-10-28. Chapter `## 6. Inside MAIN and DISPLAY`, sources: docs/code/main/{README,peripherals,eeprom,menu,ui-keys,sci,radio-control}.md,
docs/code/display/{README,boot-rtos,gui,input,peripherals,mainlink}.md, docs/memory-maps.md, docs/hardware.md. Links, updates and CAT only get pointers
(chapters 2, 4, 5); the debug console is only mentioned (chapter 8).

Sections and figures (7 SVGs in `docs/guide/img/06-*.svg`, 2 Mermaid):
- 6.1 Two CPUs, two styles: `06-two-cpus.svg` (side-by-side cards: RX651 super-loop vs RZ/A1H RTOS, who owns what).
- 6.2 MAIN: one loop, sixteen jobs: `06-main-loop.svg` (clock face of the 16 tasks, TPU/ADC/watchdog interrupts around it);
  Mermaid power states (off loop, on, save + software reset).
- 6.3 MAIN's memory and settings: `06-main-memory.svg` (flash 512 KB and RAM 256 KB bars, roughly to scale, plus the EEPROM chip and its
  RAM mirror); Mermaid boot-load decision on the EEPROM header flag.
- 6.4 MAIN's pins: `06-main-peripherals.svg` (chip with UARTs to each neighbour, ADC inputs, DAC beep, shift-register bus, watchdog → NMI).
- 6.5 Keys and menus: Mermaid sequence (key press → DISPLAY → E0 frame → filter → mailbox → key_task → 5 tables); menu built at boot.
- 6.6 DISPLAY: boot and tasks: `06-display-boot.svg` (16 MB SPI flash: loader, flags, bank 1/2 → 10 MB on-chip RAM),
  `06-display-tasks.svg` (tasks grouped by job and priority).
- 6.7 DISPLAY: screens, touch, knobs, SD card and the hidden console: `06-display-gui.svg` (MAIN screen packet → snapshot compare →
  4 layers → TFT + DVI).
- 6.8 Where to look.

## Findings

## Follow-ups
