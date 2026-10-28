# DISPLAY: clocks, pins, interrupts, RTC, recorder and other peripherals (T11g)

Back to the [DISPLAY overview](README.md). Addresses are CPU addresses (image base 0x20100000). Names in backticks are current Ghidra names.
Function names are the names applied in Ghidra (`tools/ghidra/names_display.tsv`, merged by T17) and match `decomp/display/`; a name still in *italics* is a description that was not applied as a Ghidra name. Function entries the project
is missing are listed in `tools/ghidra/entries_display.T11g.tsv`. Register names are from the RZ/A1H hardware manual. Where a bit or ID meaning
comes from that manual and was not checked against a printed copy, the tag is **[inference]**.

## Summary

| Area | What the firmware does | Key functions |
|---|---|---|
| Kernel | **NORTi** µITRON 4.0 kernel from MiSPO: the string `NORTi(c)MiSPO` is at 0x20156290 **[fact]**. The file system (`fsys_sem`, `fsys_mpf`, `FSYS Work`, `fat_sem`) and the USB host (`udevtsk%d`, `UHHID`) look like the matching MiSPO middleware **[inference]** | see [boot-rtos.md](boot-rtos.md) |
| Clocks | Clock mode 1 from the 48 MHz USB_X1 crystal. FRQCR 0x0035; P0φ = 32 MHz (the OSTM periods prove this); two module-stop profiles (standby / full) | `cpg_set_clock_profile`, `cpg_early_init` |
| Pins | `pinmux_init` sets up 159 pins. The decoded table and schematic nets are below | `pinmux_init`, `gpio_cfg_alt` |
| Interrupts | GIC with 587 IDs, a handler table at 0x208DC1E0 and 39 registered sources | `gic_init`, `gic_dispatch` |
| RTC | External ABLIC **S-35190A**, bit-banged over P1_0..P1_2. The on-chip RTC is unused (RTC_X1 is grounded) | `rtc_init`, `rtc_get_datetime` |
| "audio_codec" | **No codec on DISPLAY** (AUDIO_X1 grounded, no SSIF/SCUX register access). The task is a **WAV recorder/player** for SD files. Audio samples travel inside the DSP SPI frames | `task_audio_codec`, `rec_start`, `play_start` |
| SD user files | `I:\FT-710\{Capture, MemList, Menu, PlayList, MESSAGE}`: BMP screenshots, memory-channel and menu backups (`.dat`), WAV recordings | `task_sdmenu`, `sdmenu_save_file` |
| Backlight / LEDs | MTU2 PWM for the TFT backlight (BLPWM) and the LED dimmer, 9 front-panel LEDs on P6 | `backlight_set`, `dimmer_set`, `led_set_mask` |
| Watchdog | Not used as a watchdog. The WDT is only used to **reset the chip** (WTCNT = 0xFF in reset mode) | `wdt_system_reset` |
| USB | USB0 and USB1 in **host** mode only. The only class driver is HID (`UHHID`); details are in [input.md](input.md) | `FUN_2013b4cc` |

```mermaid
flowchart LR
  subgraph RZ["RZ/A1H"]
    CPG["CPG<br/>2 STBCR profiles"]
    GIC["GIC 0xE8201000<br/>table 0x208DC1E0"]
    OSTM["OSTM0 10 ms tick<br/>OSTM1 1 ms wake-up"]
    MTU["MTU2 ch0, ch3/4 PWM"]
    GPIO["GPIO / PFC"]
    SDHI["SDHI0"]
    ADC["ADC AN0..AN4"]
    WDT["WDT (reset only)"]
  end
  RTC["S-35190A RTC"] ---|"P1_0..2 bit-bang"| GPIO
  LED["9 front LEDs P6"] --- GPIO
  BL["MP3301 backlight"] ---|"BLPWM P4_7"| MTU
  DIM["LED_DIMR P10_4"] --- MTU
  SD["SD card I:"] ---|"P11_4..11"| SDHI
  PWR["PWR_SW P2_0 (IRQ5)"] --- GIC
  PL["RX_PWR_ON, RZ_PWR_ON, 5VON"] --- GPIO
  ENC["encoders / keys"] --- ADC
```

## 1. Clocks (CPG)

`cpg_early_init` (0x20116CCC) runs from `Reset_Handler`, before `main` **[fact]**. It writes:

| Register | Value | Meaning |
|---|---|---|
| PL310 0x3FFFFF80 | 1 | L2 cache power control (standby enable) **[inference]** |
| FRQCR 0xFCFE0010 | 0x0035 | Same divider field as Renesas' reference value 0x1035, without CKOEN. Gives I : G : B : P1 : P0 = 1 : 2/3 : 1/3 : 1/6 : 1/12 **[inference]** |
| FRQCR2 0xFCFE0014 | 0x0001 | |
| SYSCR3 0xFCFE0408 | 0x0F | on-chip RAM pages 0–3 writable **[inference]** |
| STBCR2..STBCR12 | as profile 1 below | |

OSTM0 counts 320000 per 10 ms and OSTM1 32000 per 1 ms (`ostm_init`, `periodic_wakeup_start`), so **P0φ = 32 MHz** **[fact from the code]**. With the
1/12 ratio this gives a PLL of 384 MHz = 48 MHz × 8, a CPU clock of **384 MHz**, B = 128 MHz and P1 = 64 MHz **[inference]**. The hardware strap note
"MD_CLK:1" (USB_X1 as source) fits this (docs/hardware.md).

`cpg_set_clock_profile(n)` (0x201020A0) writes **STBCR2 (0xFCFE0024) and STBCR3..STBCR12 (0xFCFE0420–0xFCFE0444)** from a byte-pair table at
0x2016517C. Each register has two entries, one for profile 0 and one for profile 1 **[fact]**. (boot-rtos.md calls the first one FRQCR. It is STBCR2.) A 1 bit stops a module.

| Register | Profile 0 (standby, `task_root`) | Profile 1 (full, `power_on_full_init`, also `cpg_early_init`) | Running in profile 0 **[inference: RZ/A1H bit map]** |
|---|---|---|---|
| STBCR2 | 0x6A | 0x6A | |
| STBCR3 | 0xF4 | 0x00 | MTU2 (bit 3) and bits 1–0 |
| STBCR4 | 0xDB | 0x00 | SCIF2, **SCIF5** (MAIN link) |
| STBCR5 | 0xFC | 0x00 | **OSTM0, OSTM1** |
| STBCR6 | 0x7E | 0x00 | ADC (bit 7), RTC (bit 0) |
| STBCR7 | 0xFC | 0x24 | USB0, USB1 (bits 1–0) |
| STBCR8 | 0xFF | 0x05 | none |
| STBCR9 | 0xFF | 0x00 | none (RIIC0–3, SPIBSC, VDC5 stopped) |
| STBCR10 | 0x57 | 0x00 | RSPI0, RSPI2, RSPI4 |
| STBCR11 | 0xFF | 0xC0 | none |
| STBCR12 | 0xF7 | 0xF0 | SDHI00 (bit 3) |

Other CPG users: `FUN_2011fc8c`/`fd1c`/`fdac`/`fe34` clear the RIIC0..3 bits in STBCR9 (bits 7..4) before they open the bus. `vdc5_module_start` /
`vdc5_module_stop` (0x20132320 / 0x20132398) use STBREQ2 (0xFCFE0034) / STBACK2 (0xFCFE0044) and STBCR9 bits 1–0 for the VDC5. `sdhi0_clock_on`
(0x2013FE50) clears STBCR12 bits 3–2 **[fact for the register writes]**.

## 2. Pin multiplexing

`pinmux_init` (0x20101190) is a flat list of calls to five per-pin helpers. Ghidra drops the repeated register arguments, so the table was decoded from the
instructions with `tools/t11g_pinmux_decode.py` **[fact]**. The helpers use a table of port base pointers at 0x20800000 (Pn); the other registers sit
at fixed offsets from it: PM +0x300, PMC +0x400, PFC +0x500, PFCE +0x600, PFCAE +0xA00, PIBC +0x4000, PBDC +0x4100, PIPC +0x4200.

| Helper | Effect |
|---|---|
| `gpio_cfg_input` `gpio_cfg_input` | port mode, input buffer on |
| `gpio_cfg_out_low` `gpio_cfg_out_low` / `gpio_cfg_out_high` `gpio_cfg_out_high` | port mode, output, initial level |
| `gpio_cfg_alt` `gpio_cfg_alt`(port, pin, func, mode)` | PMC = 1, alternative function `func` (PFCAE:PFCE:PFC = func−1); mode 0 = PIPC (peripheral sets the direction), 1 = in, 2 = out, 3 = bidirectional |
| `gpio_cfg_reset` `gpio_cfg_reset` | back to the reset state |

Nets are from the DISPLAY schematic (service manual p62, read at 500 dpi). "alt n" is the PFC function number. The peripheral column is **[inference]**
when it comes from the alt number, and **[fact]** when the driver code uses that block.

| Port.pin | Setting | Net (p62) | Peripheral / use |
|---|---|---|---|
| P0_0..P0_5 | in, in, out, out, in, in | BOOT0, BOOT1, MD_CLK, MD_CLKS, GND, GND | mode straps |
| P1_0 / P1_1 / P1_2 | out low | RTC_DT / RTC_CK / RTC_CS | S-35190A bit-bang **[fact]** |
| P1_3 | alt 4 | TINT | IRQ3 = GIC 35 (touch) **[inference]** |
| P1_4 / P1_5 | alt 1 bidir | TSCL / TSDA | RIIC (TSC2003), see [input.md](input.md) |
| P1_8, P1_9, P1_11, P1_12, P1_14 | alt 1 | AN0, AN1, AN3, AN4, AN6 (TP6009) | ADC **[fact: `adc_read_all`]** |
| P1_10, P1_13, P1_15 | in | AN2, –, – | |
| P2_0 | alt 6 | PWR_SW | **IRQ5** = GIC 37, `powon_isr` **[fact]** |
| P2_1..P2_6 | in | – | |
| P2_7 | out low | FT4222_RESET | `gpio_ft4222_reset` |
| P2_8..P2_11 | alt 8 | DSP_SCLK / SS / MOSI / MISO | RSPI (DSP link), see [spi-links.md](spi-links.md) |
| P2_12..P2_15 | alt 2 | ACC_FS / SCLK / MISO / MOSI | RSPI from the FT4222H |
| P3_0, P3_6 | in | KEY1, KEY2 | keys |
| P3_1 / P3_3 | alt 3 | ENC3_A / ENC2_A | encoder (IRQ or MTU input) |
| P3_2 / P3_5 | in | ENC3_B / ENC2_B | |
| P3_4 | alt 1 | LCD_DEN | VDC5 (`lcd_pins_enable`) |
| P3_8..P3_15 | alt 1 | R0..R7 | VDC5 RGB |
| P4_0 / P4_1 | alt 1 | G0 / G1 | VDC5 RGB |
| P4_2, P4_4, P4_5 | in | – | |
| P4_3 | out low | RX_UPDATE | MAIN boot mode (`gpio_rx_update`) |
| P4_6 | out low | LCD_STBY | `lcd_power` |
| P4_7 | alt 3, out | BLPWM | MTU2 TIOC4D backlight PWM **[inference]** |
| P4_8..P4_15 | alt 1 | B0..B7 | VDC5 RGB |
| P5_0..P5_7 | (not in `pinmux_init`) | RA±, RB±, RC±, RCK± | LVDS, `lvds_pins_enable` sets alt 1 |
| P5_8 / P5_9 | out low | DVR1 / DVR0 | `gpio_dvr`, to the MAIN DVI chain |
| P5_10 | in | – | |
| P6_0 / P6_1 | in | – | |
| P6_2 / P6_3 | alt 7 | ACC_UMISO / ACC_UMOSI | SCIF (accessory UART, test points) |
| P6_4, P6_5, P6_8, P6_9 | out low | LED_D_BLUE, LED_D_GREEN, LED_D_RED, LED_D_WHITE | LEDs |
| P6_6 / P6_7 | alt 5 | DISP_UMISO / DISP_UMOSI | **SCIF5** MAIN link **[fact]** |
| P6_10..P6_14 | out low | LED_POWER, LED_STEPCH, LED_TX, LED_VOX, LED_RXBUSY | LEDs |
| P6_15 | in | – | |
| P7_0..P7_8 | in | BOOT2, – | |
| P7_9 / P7_11 | out low, then high in `main` | RX_PWR_ON / RZ_PWR_ON | power latch (`gpio_p7_9_11`) **[inference]** |
| P7_10 | out low | RX_RESET | `gpio_rx_reset` |
| P7_12 | out low | SDPWS | SD power switch, `sd_power` |
| P7_13..P7_15, P8_0, P8_9 | in | KDAT0..KDAT3, KDAT4 | key matrix inputs |
| P8_1, P8_2, P8_7, P8_8 | out low | KSCAN0..KSCAN3 | key matrix scan |
| P8_3..P8_6 | alt 3 | SDR_SCLK / SS / MOSI / MISO | RSPI (SDR link) |
| P8_10 | out low | USB0_EN | `gpio_usb0_en` (0x20101DA4) |
| P8_11 / P8_12 / P8_13 | in | USB0_PG / USB_DET / USB1_PG | |
| P8_14 | out low | 5VON | `gpio_p8_14` (1 on the full path) |
| P8_15, P9_1 | in | ENC1_S, ENC2_S | encoder push switches |
| P9_0 | alt 4 | ENC1_A | encoder |
| P9_2..P9_7 | alt 2 | QF_CLK, QF_CSn, QF_DAT0..3 | SPIBSC0 (`spibsc0_pins_init` does them again) |
| P10_0 / P10_1 / P10_3 | alt 2 | ENC0_A / ENC0_B / ENC1_B | encoder (MTU2 phase counting?) **[guess]** |
| P10_4 | alt 2, out | LED_DIMR | MTU2 TIOC0A dimmer PWM **[inference]** |
| P10_5 / P10_6 | in | KEY_PTT / KEY_FAST | |
| P10_8..P10_13 | alt 5 | G7..G2 | VDC5 RGB |
| P10_14 | out low | LCD_PWR_EN | `lcd_power` |
| P11_2 | out high | QF_RESETn | `gpio_qf_reset` |
| P11_4..P11_11 | alt 2 | SD_CD, SD_WP, SD_DAT1, SD_DAT0, SD_CLK, SD_CMD, SD_DAT3, SD_DAT2 | **SDHI0** **[fact: driver uses 0xE804E000]** |
| P11_13 / P11_14 | in | VSYNC / HSYNC (pulled down) | unused |
| P11_15 | (not in `pinmux_init`) | LCD_CLK | `lcd_pins_enable` sets alt 5 |

Cross-check against docs/hardware.md: everything listed there matches (RTC P1_0..2, TINT/TSCL/TSDA P1_3..5, DSP P2_8..11, ACC P2_12..15, FT4222_RESET
P2_7, RX_UPDATE P4_3, DISP UART P6_6/7, RX_RESET P7_10, SDR P8_3..6, QF P9_2..7, QF_RESETn P11_2). The power latch nets RX_PWR_ON / RZ_PWR_ON on P7_9 / P7_11, 5VON on P8_14,
SDPWS, the LED pins and the key matrix are new and could go into hardware.md (see the T11g task file).

### GPIO wrappers used at run time
| Address | Ghidra name | Purpose |
|---|---|---|
| 0x20101C10 | `lcd_power` | LCD_DEN/LCD_CLK alt, LCD_STBY, LCD_PWR_EN |
| 0x20101DEC | `lvds_pins_enable` | P5_0..7 LVDS on/off |
| 0x20101B60 | `backlight_enable` | P4_7 BLPWM alt 3 + P10_4 |
| 0x20101FA4 / 0x20102040 | `led_set_one` / `led_set_mask` (`led_set_one` / `led_set_mask`) | front LEDs. Mask bit 0..7 = D_RED, D_GREEN, D_WHITE, D_BLUE, RXBUSY, TX, STEPCH, VOX **[fact for the pin table, schematic for the names]** |
| 0x20101D70 / 0x20101D94 | `sd_power` / `sd_card_detect` (`sd_power` / `sd_card_detect`) | P7_12 / P11_4 |
| 0x20101DC4 | `gpio_dvr` | DVR0/DVR1 |
| 0x20101C74, 0x20101CA4, 0x20101CBC, 0x20101F8C | `gpio_rx_update`, `gpio_rx_update_b`, `gpio_qf_reset`, `gpio_ft4222_reset` | single pins |
| 0x20114DF4 | `system_reboot` | FS off, LCD/LVDS off, RX_RESET pulse, QF reset, then `wdt_system_reset` |

## 3. Interrupts (GIC)

`gic_init` disables everything, sets ICFGR (edge/level) from constants, gives IDs 0–15 their own priorities and every other ID
0xF8, targets CPU 0, fills the 587-entry handler table 0x208DC1E0 with `gic_default_handler`, sets PMR = 0xF8 and enables the
distributor **[fact]**. `IRQ_Handler` → `gic_dispatch` reads IAR, pushes ID and running priority on a 32-deep nesting stack (0x208DCB8C / 0x208DCB0C),
raises PMR and returns the handler. `gic_irq_exit` writes EOIR and restores PMR **[fact]**.

There are two ways to register a handler:
- `itron_acre_isr(T_CISR {attr, exinf, intno, isr, prio})`: copies a 0x58-byte stub (`gic_install_isr_stub` `gic_install_isr_stub`) into the handler
  slot and sets GICD_IPRIORITYR = prio << 3 **[fact]**.
- `gic_def_inh` (`gic_def_inh`(intno, {attr, handler, prio})`): stores the handler directly **[fact]**.

Then `gic_enable_irq` sets the enable bit, and `gic_disable_irq` clears it.

The complete set of sources found (all static descriptors, the three SCIF objects of `uart_obj_init`, and the three `def_inh` calls). The ID → source
mapping is from the RZ/A1H interrupt table **[inference]**. It is consistent with OSTM0/1 = 134/135, IRQ5 = 37 on P2_0 and the RIIC/RSPI channel
order in the code.

| GIC ID | Source | ISR (entry) | Pri | Registered by | Page |
|---|---|---|---|---|---|
| 35 (0x23) | IRQ3, touch TINT P1_3 | `tsc2007_tint_isr` 0x201033E8 (it is the ISR, not a set-up function) | 5 | `touch_init` | [input.md](input.md) |
| 36 (0x24) | IRQ4, encoder pin | `renc_irq4_isr` | 5 | `renc_init` | [input.md](input.md) |
| 37 (0x25) | IRQ5, PWR_SW P2_0 | `powon_isr` 0x20113FDC | 5 | `powon_init` | [boot-rtos.md](boot-rtos.md) |
| 44 / 45 / 46 (0x2C–0x2E) | DMAC ch3 / ch4 / ch5 end | 0x20137490 (sets a flag) / 0x201376C4 / 0x201374A0 (callback pointers) | 5 | `dmac4_rspi4_rx_setup`… (DMA set-up) | [spi-links.md](spi-links.md) |
| 50 / 51 (0x32, 0x33) | DMAC ch9 / ch10 end | 0x20137AEC / 0x20137D1C (callbacks) | 5 | `dmac9_rspi_tx_setup` | [spi-links.md](spi-links.md) |
| 73 / 74 (0x49, 0x4A) | USBI0 / USBI1 | 0x2013B58C / 0x2013B598 → `FUN_201396b0(port)` | 8 | `gic_def_inh` in `FUN_2013a394` area | [input.md](input.md) |
| 78 (0x4E) | VDC5 ch0 (line/vsync) | `FUN_20118638` | 5 | `FUN_20130c70` area | [gui.md](gui.md) |
| 134 (0x86) | OSTM0 | `ostm0_tick_isr` (10 ms tick) | 5 | `ostm_init` | [boot-rtos.md](boot-rtos.md) |
| 135 (0x87) | OSTM1 | `periodic_wakeup_isr` (1 ms) | 5 | `periodic_wakeup_start` | [boot-rtos.md](boot-rtos.md) |
| 189 / 190 / 191 | RIIC0 TEI / RI / TI | 0x201203E4 / 0x201203D4 / 0x201203DC → 0x20120CB0 / 0x20120C04 / 0x20120C54 (ch 0) | 9 | `FUN_2011fc8c` | [input.md](input.md) |
| 197 / 198 / 199 | RIIC1 TEI / RI / TI | 0x201203FC / 0x201203EC / 0x201203F4 (ch 1) | 9 | `FUN_2011fd1c` | |
| 205 / 206 / 207 | RIIC2 TEI / RI / TI | 0x20120414 / 0x20120404 / 0x2012040C (ch 2) | 9 | `FUN_2011fdac` | |
| 213 / 214 / 215 | RIIC3 TEI / RI / TI | 0x2012042C / 0x2012041C / 0x20120424 (ch 3) | 9 | `FUN_2011fe34` | |
| 235 / 236 | SCIF3 RXI / TXI | 0x20114884 / 0x2011488C | 10 | `uart_obj_init` (0x208DA1E0) | [mainlink.md](mainlink.md) |
| 239 / 240 | SCIF4 RXI / TXI | 0x20114894 / 0x2011489C | 10 | `uart_obj_init` (0x208DAA30) | [mainlink.md](mainlink.md) |
| 243 / 244 | SCIF5 RXI / TXI (MAIN link) | 0x201148A4 / 0x201148AC | 10 | `uart_obj_init` (0x208DB280) | [mainlink.md](mainlink.md) |
| 271 / 272 | RSPI0 SPRI / SPTI | 0x2011ECDC / 0x2011ECD4 → 0x2011F840 / 0x2011F89C (ch 0) | 10 | RSPI open (`FUN_2011d25c` file) | [spi-links.md](spi-links.md) |
| 274 / 275 | RSPI1 SPRI / SPTI | 0x2011ECEC / 0x2011ECE4 | 10 | | |
| 277 / 278 | RSPI2 SPRI / SPTI | 0x2011ECFC / 0x2011ECF4 | 10 | | |
| 279 / 280 / 281 | RSPI3 SPEI / SPRI / SPTI | 0x2011ED0C (SPRI) / 0x2011ED04 (SPTI); 279 is enabled with no handler of its own | 10 | | |
| 283 / 284 | RSPI4 SPRI / SPTI | 0x2011ED1C / 0x2011ED14 | 10 | | |
| 303 (0x12F) | SDHI0 | 0x2013FDE0 → `FUN_20140b9c` | 7 | `gic_def_inh` in `FUN_2013fde8` area | [update.md](update.md) |
| 449 (0x1C1) | TINT33 (pin of the DSP SPI group P2_8..11) | 0x20133418 → `rspi_start`(4)`, frame counter 0x208085AC | 5 | `link_ss_irq_init` | [spi-links.md](spi-links.md) |
| 535 (0x217) | TINT119 (pin of the SDR SPI group P8_3..6) | 0x201333F0 → `rspi_start`(2)`, frame counter 0x208085A8 | 5 | `link_ss_irq_init` | [spi-links.md](spi-links.md) |

The two TINT rows: the TINT numbers follow from IDs 416 + n **[inference]**. The DSP/SDR assignment rests on the RSPI channel the ISR serves: RSPI4 carries
the DSP audio frames (DMA to/from 0xE800E804, section 5) and RSPI2 is then the SDR link **[inference]**. Which pin of the group it is (most likely SS, the end-of-frame
edge) is **[guess]**. Most ISR entries above are not functions in the current project; `entries_display.T11g.tsv` adds them.

## 4. RTC: S-35190A on P1_0..P1_2

The chip is driven by bit-banging PSR1 (0xFCFE3104): P1_0 = DT, P1_1 = CK, P1_2 = CS. Data goes LSB first, about 20 spin loops per half-clock (`rtc_delay`), and the
DT pin is switched to input for reads (`rtc_dt_input` / `rtc_dt_output`) **[fact]**. Every transfer holds the mutex created by `rtc_init`
(0x20800368) **[fact]**. The command byte is `0110 C2 C1 C0 R/W` sent LSB first, so the code's constants are bit-reversed: 0x26/0xA6 = real-time data 1 write/read
(7 BCD bytes y m d w h m s), 0x66/0xE6 = real-time data 2 (h m s), 0x86|reg / 0x06|reg = status 1, status 2, INT1, INT2 **[inference from the
datasheet layout, fits the byte counts]**.

| Address | Ghidra name | Purpose |
|---|---|---|
| 0x201147D4 | `rtc_init` | idle port, status1 = 2 (24-hour), status2 = 0; called in `task_root` common part (step 3 in boot-rtos.md) |
| 0x20114400 / 0x20114340 | `rtc_read_datetime_raw` / `rtc_write_datetime_raw` | 7 BCD bytes; hour bit 6 (AM/PM) masked on read |
| 0x2011446C / 0x201143A0 | `rtc_read_time_raw` / `rtc_write_time_raw` | 3 bytes |
| 0x20114658 / 0x20114608 | `rtc_get_datetime` / `rtc_set_datetime` | GUI clock and MAIN messages |
| 0x20114528 / 0x20114564, 0x2011459C / 0x201145D8 | `rtc_get_date` / `rtc_set_date`, `rtc_get_time` / `rtc_set_time` | BCD fields; used by the GUI, screen-capture and backup file names, and the debug `date` command |
| 0x201146B4 | `rtc_get_tm` | `struct tm` for FAT time stamps (called from the FS layer at 0x2014E14C..) |
| 0x201144D8 | `rtc_minutes_of_day` | h·60 + m |
| 0x20114778 / 0x201147B4 | `rtc_read_status` / `rtc_int_setup` | status/INT registers; `rtc_int_setup` runs on MAIN message 0x62 |
| 0x20114168 / 0x201141E4 / 0x20114268 / 0x201142CC | `rtc_send_byte` / `rtc_recv_byte` / `rtc_read_reg` / `rtc_write_reg` | low level |

## 5. Voice recorder / player (task "audio_codec")

The DISPLAY board has no audio hardware (AUDIO_X1 is grounded on p62; no SSIF, SCUX or SPDIF register is touched). The `audio_codec` task (`task_audio_codec`
0x201065C4, pri 5, created by `audio_codec_init` with event flag 0x208000C8 and mailbox 0x208000C4) records and plays **WAV files on the SD card**. The audio
samples travel inside the **DSP SPI frames** **[fact]**:

```mermaid
sequenceDiagram
  participant GUI as GUI (REC/PLAY screens)
  participant T as task_audio_codec
  participant ISR as DSP SPI frame handler `dsp_rx_done_cb`
  participant SD as SD card (FAT)
  participant DSP as IF DSP over RSPI4 + DMA
  GUI->>T: rec_start(name, freq, mode, kind) -> flag 2
  T->>SD: rec_open_wav: I:\FT-710\{PlayList|MESSAGE}\name.wav, 0x5C-byte header
  loop every DSP frame (0x11F8 bytes)
    DSP->>ISR: RX frame (DMA into 0x60502000 / 0x60503450)
    ISR->>T: copy 4000 bytes from frame+600 into slot n (16 x 0x11F8 at 0x208F4DE0), audio_codec_post(1)
    T->>SD: mono -> L=R 16-bit, rec_write
  end
  GUI->>T: rec_stop -> rec_finish (fix RIFF sizes)
  GUI->>T: play_start(name, kind) -> flag 4
  loop while playing
    T->>SD: play_read_block: 0xC80 bytes, keep left channel
    T->>ISR: slot n = {count/2, 0x1234, samples}
    ISR->>DSP: next TX frame DMA from slot n (else silence 0x20906D60)
  end
```

- **File format** **[fact]** (`rec_open_wav` 0x20106248): RIFF/WAVE, `fmt ` PCM, **2 channels, 16000 Hz, 16 bit** (64000 B/s), a `LIST` chunk of 0x28 bytes
  with an `ICMT` comment of 0x20 bytes, then `data`. The recorder writes each mono sample twice, so L = R. `rec_finish` pads to 4 bytes and rewrites the sizes.
- **Two kinds** **[fact]**. Kind 1 = `I:\FT-710\PlayList` (receive-audio recordings). Their comment is "`<frequency>,<mode>`": the frequency comes from 8 digits
  formatted `%c%c.%c%c%c.%c%c%c`, the mode from the table at 0x20165274 (LSB, USB, CW-L, CW-U, AM, AM-N, FM, FM-N, DATA-L, DATA-U, DATA-FM, D-FM-N, RTTY-L,
  RTTY-U, PSK). Kind 2 = `I:\FT-710\MESSAGE` (voice messages), named after the file. They stop at **0x57E400 bytes = 90 s**, both when recording and when
  playing. A new MESSAGE file first deletes the old file of the same name.
- **Playback**: 0xC80-byte blocks (25 ms), fast forward / rewind ±320000 bytes = **5 s**, progress text `%02d:%02d:%02d` + percent (`play_progress`) **[fact]**.
- **Guards**: recording is refused when drive I: has no free space (`sd_is_full`, error −2) or the card is missing (`FUN_20103ba0`, error −1) **[fact]**. The
  flags 0x208000B1 (playing) and 0x208000B2 (recording) are read by the GUI (0x20129F64 file) and by two other checks (0x2011446C and
  0x201587FC files), which skip an action while recording **[fact for the reads, inference for the purpose]**.

| Address | Ghidra name | Purpose |
|---|---|---|
| 0x20105C78 / 0x201065C4 | `audio_codec_init` / `task_audio_codec` | task; flag 2 = record, flag 4 = play |
| 0x201058DC / 0x20105A20 | `rec_start` / `rec_stop` | GUI API |
| 0x20105A54, 0x20105AE8, 0x20105B28, 0x20105B68, 0x20105BA8, 0x2010579C | `play_start`, `play_resume`, `play_pause`, `play_ffwd`, `play_rewind`, `play_stop` | GUI API (set 0x208000D4 = 1..4 and wait for the state) |
| 0x20105790 / 0x201058C0 | `audio_state` / `audio_error` | state 0/2/4/8/0x10/0x20, error code |
| 0x20105550 / 0x201057D8 | `wav_list_dir` / `wav_delete` | ≤ 255 files, name ≤ 20 chars, 0x34-byte entries, sorted |
| 0x20106248, 0x201061C8, 0x20106060, 0x20106018 | `rec_open_wav`, `rec_write`, `rec_finish`, `rec_close_abort` | writer |
| 0x201052B0, 0x20105158, 0x20105D24, 0x20105F2C, 0x2010508C | `wav_open_read`, `wav_check_header`, `play_read_block`, `play_seek`, `play_close` | reader |
| 0x20106DC8 | `audio_codec_post` | mailbox send from the frame handler |
| 0x201331DC | `dsp_rx_done_cb` | DSP SPI DMA frame-end handler: swaps RX buffers, feeds recorder/player (owned by T11d) |

## 6. SD card user files

Drive `I:` is the SD card on SDHI0 (driver `FUN_201401dc`–`FUN_20140b9c`, power `sd_power`, detect `sd_card_detect`). The FAT layer (FAT12/16/32
and exFAT names at 0x20148F20, the `fsys_*` semaphores and `fs_fopen`/`fs_fread`/`fs_fwrite`/`fs_fseek`) is summarised in [update.md](update.md) **[fact for the
strings]**. Files and folders the DISPLAY reads or writes:

| Path | Written by | Format |
|---|---|---|
| `I:\FT-710\` + `Capture`, `MemList`, `Menu`, `PlayList` | `sd_make_dirs` 0x2010FB90 | created after `FUN_2013f984('I')` (probably the SD **format** command: it runs from `sd_format_request` with a progress percent) **[inference]** |
| `I:\FT-710\Capture\20YYMMDD_HHMMSS.bmp` (fallback `I:\20YYMMDD_HHMMSS.bmp`) | `screen_capture_bmp` (MAIN message 0x7A) | BMP screenshot, see [gui.md](gui.md) |
| `I:\FT-710\MemList\<name>.dat`, `I:\FT-710\Menu\<name>.dat` | `sdmenu_save_file` 0x2010F60C, read by `sdmenu_load_file` 0x2010F81C (now `sdmenu_load_file`) | below |
| `I:\FT-710\PlayList\*.wav`, `I:\FT-710\MESSAGE\*.wav` | recorder | section 5 |
| `I:\FT-710\DEBUG_RECV_CMD\RECV_CMD.TXT`, `SEND_CMD.TXT` | MAIN-link debug log | see [mainlink.md](mainlink.md) |
| `I:\debug_1.log` | debug console | |
| `I:\*.SFL`, `I:\rom_writer.dat`, `I:\AH076H_*.dat/.mot`, `I:\AH068_*.dat`, `I:\AH076H_DISPLAY.bin` | updater | see [update.md](update.md) |
| `I:\<NAME>.txt` | `cli` scripts | see [boot-rtos.md](boot-rtos.md) |

### MemList / Menu backup (`.dat`, 0x7F50 = 32592 bytes) **[fact]**
The default name is `20YY_MM_DD_NN` (date from the RTC, NN = next free number, max 99; `sdmenu_default_name`).

| Offset | Size | Content |
|---|---|---|
| 0x000 | 8 × 64 | blank lines (62 spaces + CR LF) |
| 0x200 | 64 | `MemList  <n>  <CRC>` or `Menu  <n>  <CRC>`, padded, CR LF. `<n>` is a model/format word that must match on load; `<CRC>` = `~CRC-32(encoded block ‖ 0x139EECA6 LE)` in %08X |
| 0x240 | 0x7D10 | block encoded with `sfl_encode` (the SFL 43-byte key, added): u32 type (0 MemList, 1 Menu), u32 `<n>`, 8 bytes 0, **32000 bytes** of radio data |

Load checks size, CRC, type and `<n>`. Errors: 1 = bad file/CRC, 2 = `<n>` mismatch, 4 = no file. The 32000 bytes are copied to 0x208116A6 and
exchanged with MAIN over the link with transfer codes 0x41/0x43 (save MemList/Menu) and 0x42/0x44 (load) (`sdmenu_req_save` / `sdmenu_req_load`)
**[fact for the codes, inference for the direction]**. So a memory or menu backup is the MAIN CPU's settings block, obfuscated the same way as the
firmware files. It is not a plain-text format.

The `sdmenu` task (`task_sdmenu`) serves three event-flag requests: 1 = save, 2 = load, 3 = format + make folders **[fact]**.

## 7. Backlight, LED dimmer, settings sector

| Address | Ghidra name | Purpose |
|---|---|---|
| 0x2010261C | `backlight_pwm_init` | MTU2 ch3/ch4 reset-synchronised PWM (TMDR_3 = 0x38), period 320 counts, output enable TOER bit 5 (TIOC4D on P4_7 BLPWM) **[fact for the registers, inference for the pin]** |
| 0x20102698 | (`backlight_set_pct`, new entry) | TGRD_4 = pct × 320 / 100 − 1 |
| 0x201026E0 / 0x201026E8 | `backlight_set` / `backlight_init` | brightness from MAIN message 0x24 byte & 0x7F; 60 % at start-up, 100 % on some screens |
| 0x20113D20 | `dimmer_pwm_init` | MTU2 ch0 PWM mode 1, P0φ/16, period 20000 = **100 Hz**, TIOC0A (P10_4 LED_DIMR) |
| 0x20113D6C / 0x20113DB8 / 0x20113DC0 | `dimmer_set_pct` (new entry) / `dimmer_set` / `dimmer_init` | LED/key dimmer from message 0x24 (second byte & 0x7F); 60 % at start-up |
| 0x20102708 / 0x20102774 | `touch_cal_load` / `touch_cal_save` | 48-byte record in SPI flash at 0x183D0000 (magic 0xA5C30001, CRC-32), probably the touch calibration **[guess]** |

MAIN message 0x24 also carries the LED bits (`led_set_mask`) and the FT4222 reset bit (bit 2 of its first byte) **[fact]**.

## 8. Other blocks

- **OSTM** **[fact]**: OSTM0 is the 10 ms kernel tick and OSTM1 the 1 ms periodic wake-up (boot-rtos.md). `ostm_time_us` (0x20117860) interpolates the system time
  from the OSTM0 counter (320000 counts per tick). `delay_us` busy-waits on it.
- **WDT** **[fact]**: the only access is `wdt_system_reset` (0x20100268): WRCSR = 0xA500, 0x5A5F (reset enable), WTCNT = 0x5AFF, WTCSR = 0xA578
  (watchdog mode, start). It resets the chip within a few counts. Callers: `system_reboot` and the debug `reset` command (`keycode_line`). Nothing
  refreshes the WDT, so there is no watchdog supervision.
- **ADC** **[fact]**: `adc_start_scan` (ADCSR 0xE8005860 = 0x20FF) and `adc_read_all` (ADDRA..H >> 4, 12-bit). Used by the `ad renc` task and a GUI test
  screen ([input.md](input.md)).
- **USB**: `FUN_2013b4cc` touches both USB0 (0xE8010000) and USB1 (0xE8207000), and the ISRs for IDs 73/74 go to one host-controller handler. The only class string is `UHHID`, so there is **no USB device mode and no mass-storage host** **[inference]**.
  USB0 VBUS is switched by `gpio_usb0_en` (P8_10) **[fact for the pin write]**.
- **LVDS / DVI**: `FUN_201193ec` programs the LVDS PLL (LCLKSELR/LPLLSETR 0xFCFF7A50/54). `lvds_pins_enable` switches P5_0..7, and `gpio_dvr` drives DVR0/DVR1
  towards the DVI encoder on MAIN. The VDC5 side is in [gui.md](gui.md).
- **System control** 0xFCFF400C: used only by `loader_selfinstall` (magic 0xAABBCCDD, see [update.md](update.md)).
- **Not used** **[fact: no register references]**: on-chip RTC (RTC_X1 grounded), SSIF, SCUX, SPDIF, CEU, JCU, Ethernet, MMC, PWM (0xFCFF50xx), deep standby.

## Globals

| Address | Meaning |
|---|---|
| 0x2016517C | CPG profile table (11 byte pairs) |
| 0x20800000 | GPIO port base pointer table (Pn) |
| 0x208DC1E0 | GIC handler table, 587 entries |
| 0x208DCB0C / 0x208DCB8C | GIC nesting stack: saved PMR / interrupt ID; depth in 0x20800404 |
| 0x20800368 | RTC mutex (from `rtc_init`) |
| 0x208000C4 / 0x208000C8 | audio mailbox / audio event flag |
| 0x208000B0 | audio slot index (0..15); slots at 0x208F4DE0, 0x11F8 bytes each |
| 0x208000B1 / B2 / B3 | playing / recording / kind (1 PlayList, 2 MESSAGE) |
| 0x208000CC / D0 / D4 / D8 | audio state / record request / play command / error |
| 0x208000DC / E0 | WAV write / read file handle |
| 0x208000E4 / EC / F0 | data length / read position / play position (bytes) |
| 0x20810FCC | current WAV path (0x80 bytes) |
| 0x2081104C / 5C / 67 | record name (16) / frequency text / mode text |
| 0x208116A6 | 32000-byte MemList/Menu data exchanged with MAIN |
| 0x208001A8 | sdmenu event flag; results 0x2080019F–0x208001A2 |
| 0x208001AC | folder pointer table for the sdmenu kinds (MemList, Menu) |
| 0x20819524..40 | last ADC results AN0..AN7 |
