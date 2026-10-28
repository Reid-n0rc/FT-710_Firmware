# T19e — Guide: Inside MAIN and DISPLAY

**Status:** done · **Depends on:** T19 (style guide)

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
Chapter written: `docs/guide/parts/06-inside-main-and-display.md`, `## 6. Inside MAIN and DISPLAY`, sections 6.1–6.8:
6.1 two CPUs, two styles; 6.2 MAIN's 16-job super-loop, timers, watchdog, power handshake; 6.3 MAIN memory map, the SPI EEPROM and its RAM
mirror, save triggers and the boot-load decision; 6.4 MAIN peripherals (UART map, ADC, DAC, GPIO, shift-register bus); 6.5 keys (five
handler tables) and the menu engine; 6.6 DISPLAY boot from the flash banks, standby/full start, task picture; 6.7 GUI, touch, knobs, SD
files and a pointer to the hidden debug console (chapter 8); 6.8 Where to look (table of reference pages, names, addresses).

Figures (7 SVGs, all checked with xmllint + rsvg-convert and viewed):
- `img/06-two-cpus.svg` — Fig 6.1, MAIN vs DISPLAY cards with the UART between them
- `img/06-main-loop.svg` — Fig 6.2, the 16 loop jobs as a clock face, interrupts and watchdog beside it
- `img/06-main-memory.svg` — Fig 6.4, flash / RAM / EEPROM columns, roughly to scale, with the mirror band
- `img/06-main-peripherals.svg` — Fig 6.6, RX651 with each UART partner, ADC/DAC/GPIO/shift-register/EEPROM/reset lines
- `img/06-display-boot.svg` — Fig 6.8, 16 MB SPI flash to scale, four boot steps, 10 MB on-chip RAM to scale
- `img/06-display-tasks.svg` — Fig 6.9, tasks grouped by job with priority badges, kernel strip
- `img/06-display-gui.svg` — Fig 6.10, screen packet → 33 ms GUI loop → four layers → TFT + DVI; input, SD, debug console boxes

Mermaid (3): Fig 6.3 MAIN power states (stateDiagram), Fig 6.5 EEPROM boot-load decision (flowchart), Fig 6.7 key path (flowchart).
Figure numbers are chapter-local; the parent renumbers.

## Glossary terms
- super-loop — a program with no operating system that calls the same list of functions over and over in an endless loop
- interrupt — a hardware signal that briefly stops the running code to run a short handler (for example a timer tick)
- soft timer — a counter in RAM, advanced by a timer interrupt, that code can start and later check for expiry without waiting
- watchdog — a hardware timer that must be refreshed regularly; if the program hangs, it fires and forces a recovery action
- NMI — non-maskable interrupt, an interrupt that software cannot switch off; MAIN's watchdog raises one instead of resetting
- RTOS — real-time operating system: a small kernel that switches between tasks and wakes them on events or timers
- µITRON — a Japanese standard API for small real-time kernels; NORTi (from MiSPO) is the implementation used on DISPLAY
- task — one independent thread of work under an RTOS, with its own stack and priority
- thin renderer — a display processor that only draws what another processor describes and holds no logic of its own
- SPI — a simple synchronous serial bus (clock, data out, data in, chip select) used for flash, EEPROM and fast links
- EEPROM — electrically erasable memory that keeps data without power; MAIN keeps all settings in a 32 KB SPI EEPROM
- bit-banging — driving a serial bus by toggling GPIO pins in software instead of using a hardware peripheral
- RAM mirror — a copy of the EEPROM contents kept in RAM; the program works on the copy and writes changes back
- destination code — the region code stored in the EEPROM that selects bands, TX coverage and defaults per market
- SPI flash — a serial NOR flash chip; DISPLAY boots from a 16 MB Winbond W25Q128
- bank — one of two application slots in DISPLAY's SPI flash; an update writes the bank that is not running
- screen packet — a frame from MAIN whose first byte names the screen and whose rest carries the content to draw
- double buffering — drawing into a hidden copy of a frame buffer and then swapping it with the visible one, to avoid flicker
- SCI — Renesas name for the RX651's serial interface (UART); SCIF is the RZ/A1H's FIFO UART
- CP2105 — Silicon Labs dual USB-to-UART bridge that gives the PC its two CAT COM ports
- ADC / DAC — analogue-to-digital / digital-to-analogue converter
- GPIO — general-purpose input/output pin controlled directly by software
- shift register — a chip that takes bits in serially and presents them on parallel outputs; MAIN uses a chain of them to reach the PA board
- FPGA — field-programmable gate array; the SDR module's Artix-7 chip

## Reference issues
1. `docs/code/main/eeprom.md` (Power fail bullet) says the supply ADC result 0x20B08 is "AN002 in the `SPIR` order". `docs/code/main/peripherals.md`
   (ADC table, SPIR field 4, GPIO map) and `docs/memory-maps.md` give 0x20B08 = **AN003** `PA_VDD`; AN002 is `MCUP_FOR` at 0x20B06. The guide only says "supply voltage".
2. Frame buffers vs the "uncached mirror": `docs/memory-maps.md` (`ram_nc_lo`) and `docs/code/display/gui.md` place frame buffers at 0x60000000,
   0x600BB800, 0x60177000, 0x60232800, 0x602EE000 and call 0x60000000+ an uncached mirror of RAM, and `fb_clear_all` clears 0x60000000 + 0x2FF300.
   If the window were a plain mirror of 0x20000000, those buffers would overlap the running image's `.text`/`.rodata` (0x20100000–0x2042BC0F) and the
   clear would wipe the code. Either the window is not a plain alias of 0x20000000 or the description is off. The guide does not place the frame buffers.
3. Not a reference error, but the T19e prompt said the debug console is "gated off by one byte"; the reference (`boot-rtos.md`) says a 32-bit word at
   0x20450000 compared with 0xA0B9C8E7. The guide follows the reference.

## Follow-ups
- Parent: renumber figures 6.1–6.10 and fix the chapter/glossary anchors (`#2-how-the-chips-talk`, `#4-firmware-files-and-updates`,
  `#5-cat-remote-control`, `#8-hacking-and-custom-firmware`, `#glossary`).
- Mermaid blocks were not rendered locally (no mermaid CLI); they use only basic syntax.
- Reference issues 1 and 2 above need a fix in the reference pages.
