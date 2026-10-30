# T11g — DISPLAY misc peripherals and files

**Status:** done · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/peripherals.md`: RTC S-35190A, OSTM, INTC/GIC, GPIO, backlight, DVI/LVDS, SD-card user files (MESSAGE, PlayList, MemList, Menu).

## Plan
Owner: T11g fan-out agent (worktree branch), 2026-10-27. Own Ghidra copy `ghidra/FT710_DISPLAY_T11g` (read/explore only).

1. Peripheral survey: run `PeriphRefs.java` over the RZ/A1H register blocks (CPG, INTC/GIC, GPIO/PFC, OSTM, RTC, SSIF, SCUX, SDHI/MMC,
   USB0/1, WDT, ADC, RIIC, PWM, LVDS, DMAC) to get the function set per block; drop those owned by T11b–T11f.
2. Clocks: decode the 2-entry CPG profile table at 0x2016517C (FRQCR + STBCR1..11) into clock rates and module-stop bits.
3. Pin mux: decode `pinmux_init` (per-pin PFC/PMC/PM calls) into a port/pin → function table, cross-check against docs/hardware.md.
4. Audio: `audio_codec_init` / `task_audio_codec` and helpers (it is a WAV recorder/player on SD, not a codec driver: find the data source/sink).
5. SD/files: FatFs-or-other identification, path strings (`I:\FT-710\...`), file types read/written (MESSAGE, PlayList, MemList, Menu,
   screenshots, settings backups); leave the SFL updater to T11c.
6. RTC S-35190A (3-wire GPIO bit-bang on P1_0..P1_2), WDT, OSTM, backlight PWM, LVDS, USB usage summary (host HID belongs to T11f).
7. GIC table: all `itron_acre_isr` descriptors and direct writes into the handler table 0x208DC1E0 → ID, ISR, source.
8. Write `docs/code/display/peripherals.md` (tables + Mermaid), names in `tools/ghidra/names_display.T11g.tsv`, missed entries in
   `entries_display.T11g.tsv`, shared-file edits proposed below; commit.

## Old plan (T11 template)
Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference] (or an open question; the former guess tag is retired).

## Findings
Page: [docs/code/display/peripherals.md](../code/display/peripherals.md). 125 name proposals in `tools/ghidra/names_display.T11g.tsv`,
36 missed entries in `tools/ghidra/entries_display.T11g.tsv`, pin decoder `tools/t11g_pinmux_decode.py`.
- Kernel identified: **NORTi (MiSPO)**, string `NORTi(c)MiSPO` at 0x20156290 [fact]; FS/USB host are likely MiSPO middleware [inference].
- No audio hardware on DISPLAY. Task `audio_codec` is a WAV recorder/player on SD (16 kHz, 2 ch, 16 bit, mono duplicated). PlayList files
  carry "freq,mode" in ICMT; MESSAGE files are capped at 90 s. Samples travel inside the DSP SPI frames (RSPI4 + DMA, slots at 0x208F4DE0) [fact].
- MemList/Menu `.dat` backups: 9 text lines + 0x7D10-byte block encoded with the SFL key, salted CRC-32 (0x139EECA6), 32000 bytes of MAIN data
  [fact]. `sfl_load_file` (0x2010F81C) is really the .dat loader; rename proposed.
- Clocks: P0 = 32 MHz (from the OSTM periods), CPU 384 MHz [inference]. `cpg_set_clock_profile` writes STBCR2..12, not FRQCR [fact].
- Full pin table decoded and cross-checked against the p62 schematic (all hardware.md pins match), plus new nets: power latch, LEDs, key matrix, SD power.
- GIC: 39 sources tabulated (IRQ3/4/5, DMAC 3/4/5/9/10, USBI0/1, VDC5, OSTM0/1, RIIC0-3, SCIF3/4/5, RSPI0-4, SDHI0, 2 TINT pins for the SPI frames).
- RTC S-35190A bit-bang driver fully named. The on-chip RTC is unused. The WDT is used only as a reset generator (no watchdog supervision). USB is host-only (HID).

## Follow-ups
- Confirm the RZ/A1H STBCR bit map, the TINT numbering and the IDs 78/303 against the hardware manual (tagged [inference] on the page).
- `FUN_2013f984` / `FUN_2013f83c`: format versus mount (T11c).
- Which pin TINT33/TINT119 really are (likely the SS of the DSP/SDR SPI) (T11d).
- The 0x183D0000 settings record (touch calibration?) (T11f).

## Proposed shared-file edits
- `docs/code/display/README.md`: set the peripherals.md row to done. In the RTOS text, replace "vendor not identified" with "NORTi (MiSPO), string at 0x20156290".
- `docs/code/display/boot-rtos.md`: `cpg_set_clock_profile` writes STBCR2 (0xFCFE0024) and STBCR3..12, not "FRQCR + STBCR1..11". `intc_irq_setup`
  (0x201033E8) is the IRQ3 (touch) ISR, not a set-up function. Kernel vendor = NORTi.
- `docs/hardware.md` (DISPLAY section): add the nets from p62: P7_9 RX_PWR_ON, P7_11 RZ_PWR_ON, P7_12 SDPWS, P8_14 5VON, P8_10 USB0_EN,
  P8_11/P8_13 USB0_PG/USB1_PG, P8_12 USB_DET, P4_6 LCD_STBY, P4_7 BLPWM, P10_4 LED_DIMR, P10_14 LCD_PWR_EN, P3_4 LCD_DEN, P11_15 LCD_CLK,
  P6_4..14 LEDs, P8_1/2/7/8 KSCAN0..3, P7_13..15/P8_0/P8_9 KDAT0..4, P5_8/P5_9 DVR1/DVR0, P5_0..7 LVDS, P11_4..11 SD (SDHI0), ADC AN0..AN4 on P1_8..12.
  AUDIO_X1 and RTC_X1 are grounded (no on-chip audio or RTC use).
- `names_display.tsv` / `entries_display.tsv`: merge the T11g files. Note that `sfl_load_file` → `sdmenu_load_file`.
- `docs/memory-maps.md` (DISPLAY): GIC handler table 0x208DC1E0 (587 entries); audio slots 0x208F4DE0 (16 × 0x11F8); settings record 0x183D0000.


## Status
