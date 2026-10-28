# FT-710 hardware survey

Source: `Manuals/FT-710_serv_2022.pdf` ("FT-710 Technical Supplement", ©2022, EH080H90A, 75 pages).
Page numbers below are **PDF page numbers** (1-based). The manual's own labels are in brackets, for example p17 [MAIN-1].

The schematic, block diagram and layout pages are vector drawings with no extractable text. They were read from
cropped renders (`pdftoppm`). The parts lists (p24–46, p50–61, p64–71, p74) are text.

Confidence tags: **[fact]** = printed in the manual; **[inference]** = follows from what is printed;
**[guess]** = from outside knowledge or weak evidence, so verify it.

## Manual layout (p1)

| Pages | Content |
|---|---|
| 2–3 | Specifications |
| 4–5 | Exploded view |
| 6 | Block diagram (whole radio, including the "SDR MODULE" box) |
| 7 | Connection diagram |
| 8–16 | Alignment |
| 17–21 | MAIN unit schematics: CNTL (p17), DVI (p18), DSP, titled "SDR-DSP" (p19), AF (p20), RX (p21) |
| 22–23 | MAIN parts layout, sides A and B |
| 24–46 | MAIN parts list |
| 47–49 | PA unit schematic and layout |
| 50–61 | PA parts list |
| 62–63 | DISPLAY unit schematic and layout |
| 64–71 | DISPLAY parts list |
| 72–74 | JACK unit schematic, layout and parts list |

The manual lists four boards: **MAIN, PA, DISPLAY, JACK** (p1). There is no separate IF-DSP board: the IF DSP is
on the MAIN unit. The **SDR module** (ADC + FPGA) is a plug-in module on the MAIN unit. Its internals are **not**
documented anywhere in the manual (p6: it appears only as a box; none of its parts are in the MAIN parts list).

## Summary: programmable devices

| Ref | Part | Board | Role (manual label) | Architecture | SFL image |
|---|---|---|---|---|---|
| Q1001 | Renesas **R5F56514ADFB** (block diagram: "R5F56514AFFB") | MAIN | "MAIN CPU" (p6) | Renesas **RX651** (RXv2 core with FPU, 144-pin LFQFP) | **MC** (MAIN) |
| Q6009 | Renesas **R7S721001VCBG** | DISPLAY | "CPU" (p6) | Renesas **RZ/A1H**: ARM **Cortex-A9** (ARMv7-A) with 10 MB on-chip SRAM [guess for the specs] | **PC** (DISPLAY) |
| Q2002 | NXP **MIMXRT685SFVKB** | MAIN | "DSP MAIN/TX" (p6) | NXP **i.MX RT685**: ARM **Cortex-M33** (ARMv8-M) + Cadence **Tensilica HiFi 4** DSP (Xtensa) [core types are a guess from the part number] | **ID** (IFDSP) |
| (none) | ADC + FPGA, part numbers not given | SDR module (plugs into MAIN J2002/J3003) | "ADC/FPGA, Operating clock 125MHz, Divide 250MHz by 2" (p6) | Xilinx Artix-7 **XC7A50T** (IDCODE 0x0362C093, from bitstream, T08) | **SR** (SDR) |
| Q1805 | Explore **EPF021M-YM** | MAIN | "MICRO CNTL" in the DVI/HDMI chain (p6) | small MCU of unknown core [guess] | none known (probably mask/OTP) |

No processors were found on the PA or JACK units (their IC lists contain only regulators, op-amps, a DAC and shift
registers: p56–57, p74).

---

## MAIN unit

### Q1001: main CPU, Renesas RX651 (image MC)
- Part: **R5F56514ADFB** in the parts list, Yaesu P/N G1095803, side A, D3 (p36). The schematic also says R5F56514ADFB (p17).
  The block diagram prints "R5F56514AFFB" (p6), which is probably a drawing typo or a variant. **[fact]**
- Package: 144-pin, with pin numbers up to 144 on the schematic (p17) **[fact]**. "FB" = 144-pin LFQFP **[guess, Renesas naming]**.
- Memory: R5F56514**ADFB** = 512 KB code flash, 256 KB RAM, **no data flash**, no encryption (TSIP), no SDHI/SDSI, no dual bank, PLQP0144KA-B (144-pin LFQFP), −40 to +85 °C **[fact: datasheet R01DS0276EJ0240 Table 1.3 p19, Table 1.2 p12; T18]**. Data flash and the dual bank exist only on the 1.5/2 MB parts.
- Clock: X1001 **24.000 MHz** crystal DSX321G, connected to P37/XTAL and P36/EXTAL (pins 20/22) (p46, p6, p17). **[fact]**
- External EEPROM: Q1008 **ROHM BR25G256FVT-3GE2**, a 256 Kbit SPI EEPROM (p36, labelled "EEPROM" on p6) **[fact]**. It has its own
  nets `E2P_SS/CLK/MOSI/MISO` on **PE0/PE5/PE6/PE7** (pins 111/106/102/101), separate from the C4 SPI on PE1..PE4, and the firmware
  **bit-bangs** it (`eeprom_spi_tx`/`eeprom_spi_rx`, no RSPI/SCI) **[fact: code, docs/code/main/eeprom.md]**. P65 (pin 100, net `E2P_WP`)
  is driven high only around the status-register write in `eeprom_init`, so it is probably the chip's /WP **[inference]**.
- Other peripherals: Q1005 BU2505FV 10-bit DAC on `SDATA`, used for `FADJ` (reference oscillator trim) (p6, p17). PA-unit control goes
  through serial shift registers (`SCLK`/`SDAT`/`/SST4`/`/STT6`/`SST5` on J1002) (p17). The on-chip **DA0** (P03) drives `DA_OUT` →
  `TONE_BEEP`, the beep tone into the AF path (`dac0_write`) **[fact]**. The full pin-by-pin GPIO, ADC and DAC map with the functions
  that use each pin is in [code/main/peripherals.md#gpio-map](code/main/peripherals.md#gpio-map-fact-unless-tagged) (T10h). Pins that matter for the other
  boards **[fact: code + p17]**: P71 `DSP_RESET` (pin 86) / P72 `DSP_UPDATE` (pin 85, ISP select **[inference]**), P74 `AF_RESET` (pin 72),
  P75 `USB_DET` (pin 71), P76 `SDR_UPDATE` (pin 69) / P77 `SDR_RESET` (pin 68, R1133 10k pull), PC0 `PA_PON` (pin 75).
- **UARTs (SCI)** on Q1001 (p17, pin labels read from the schematic; port pins and line formats from the firmware, see
  [code/main/sci.md](code/main/sci.md)):

  | Q1001 pins | SCI | Net | Goes to | Firmware (V01-12) |
  |---|---|---|---|---|
  | 26 UART0_MI / 27 UART0_MO | SCI0 | `USBSS_UMISO/UMOSI` | CP2105 **SCI** port ("Standard" CAT COM port) (p20) | CAT port id 2, baud set by `sci0_set_baud` |
  | 32 UART3_MI / 34 UART3_MO | SCI3 | `USBSE_UMISO/UMOSI` | CP2105 **ECI** port ("Enhanced" CAT COM port) (p20) | CAT port id 1, baud set by `sci3_set_baud` |
  | 29 P30/RXD1 / 31 P26/TXD1 | SCI1 | `DISP_UMISO/UMOSI` | DISPLAY CPU (J1009 pins 10–11 → J6001 20–21) **and** the debug header J1004 (p17, p62) | DISPLAY link, **≈340.9 kbit/s 8N2** ([display-link.md](code/main/display-link.md)) |
  | 87 PB0/RXD4 / 84 PB1/TXD4 | SCI4 | `DSP_UMISO/UMOSI` | RT685 **FLEXCOMM0** console UART (p19) | 115200 8N1, register access `dsp_reg_access` ([dsp-link.md](code/main/dsp-link.md)) **[fact: `R_SCI4_Create` PFS 0x8C198/0x8C199]** |
  | ~70 UART5_MI / 67 UART5_MO | SCI5 | `SDR_UMISO/UMOSI` | SDR module (J2002) (p17, p19) | **115200 8N1** register frames ([sdr-link.md](code/main/sdr-link.md)) |
  | 45 UART2_MI / 44 UART2_MO | SCI2 | `ETUN_UMISO/UMOSI` | external tuner (ATAS/FC-40 type), DIN on the rear panel (p17) | tuner / linear / CAT-3 / GPO, selected by `tunlin_port_mode` |
  | 8 P00 / 7 P01 (`UART6_MO/MI`) | SCI6 | – | **not connected** on p17 | simple-I2C set-up only, never used |
  | 131 P90/TXD7 / 128 P92/RXD7 | SCI7 | `C4_UMOSI/C4_UMISO` | the "C4" peripheral, see below | **never started** (no Send/Receive caller) |

- **"C4" bus** (p17): `C4_SPI_MISO/CLK`, `C4_SS1..SS5`, `C4_RQST`, `C4_BUSY_DSP`, `C4_TRX`, `C4_RESET`, `C4_BOOT`, `C4_PON`,
  plus UART7. The name `C4_BUSY_DSP` and the `C4_BOOT`/`C4_RESET` lines suggest that "C4" is the RT685 DSP
  (whose page has `DSP_UPDATE`, `DSP_RESET18`, `DSP_UMISO/UMOSI` on FC0 UART, p19) **[inference, medium]**. I could not
  trace the C4 nets to the DSP page in the renders, so this pairing is not confirmed.
  T12 (firmware): MAIN talks to the RT685 console on FC0 through **SCI4** on PB0/PB1 (`DSP_UMISO/UMOSI`, row above;
  `dsp_link_init` sends `i DB00\r` with `R_SCI4_Serial_Send`), not SCI7; SCI7 is configured but never started in V01-12
  (docs/code/main/dsp-link.md, docs/code/ifdsp/README.md) **[fact: code]**. The C4 GPIO/SPI pins are listed in the GPIO map.
- On-chip USB (pins 47/48 USB_DM/DP) goes only to test points TP1053/TP1054 (p17). The RX USB port is not used for CAT. **[fact]**
- Boot / update: MD pin 16 is labelled `MD/FINED`, net `MD_FINE`. Transistor Q1012 (DTC114YUA) pulls MD_FINE low when
  `RX_UPDATE` is high, and the drawing is annotated "RX_UPDATE: Update is High" (p17). `RX_UPDATE` and `RX_RESET` are driven by the
  DISPLAY CPU (J1009 pins 12–13 → RZ/A1H P4_3 and P7_10) (p17, p62). SCI1 (P30/P26) is the RX boot-mode SCI.
  **So the DISPLAY CPU reflashes the MAIN CPU through the Renesas serial boot mode over the DISP UART** **[fact: DISPLAY code (display/update.md §5) +
  HWM r01uh0590 Table 3.1 p180, Table 59.7 p2564: MD low + PC7/UB low at reset = SCI boot on SCI1 P30/P26; T18]**. MAIN never drives PC7 (`UB`, J1004 pin 4),
  so it must be held low on the board **[inference]**. MD low, then high 20–100 ms after reset, selects the FINE interface instead (Table 3.1 note 3).
  This matches the update manual: firmware comes from the SD card, which is on the DISPLAY CPU, and "update DISPLAY first".
- **Debug header J1004, "RX-CPU DEBUG"** (P1091201, an 8-pin 08FLT-SM2 FFC, p35, p17). Earlier versions of this page called it J1005; the
  p17 symbol reads J1004 (T10c) and the p35 parts list gives J1004 = 08FLT-SM2-TB P1091201 (side A, D3). **J1005 is `SB20-08WS` P0090615**,
  an 8-pin wire-to-board connector (side A, A1); the exploded view (p5) has a wire assembly that "Connect[s] to J1005 on the MAIN-Unit" **[fact]**.
  J1004 pinout:
  pin 1 GND, 2 `MD_FINE`, 3 `E1_RESET`, 4 `UB`, 5 `DISP_UMOSI` (TXD1), 6 `DISP_UMISO` (RXD1), 7 → TP1029, 8 → TP1030
  (pins 7 and 8 are not labelled; one probably carries the 3.3 V reference) **[fact for pins 1–6]**.
  This header gives both the Renesas **FINE** single-wire debug (E1/E2 emulator) and SCI1 boot-mode programming
  (Renesas Flash Programmer over UART) **[inference]**.
- Test points: TP1002, TP1004, TP1006, TP1024, TP1028 on CPU pins (p17). TP1005 is the reference-oscillator check point (p9, p46).

### Q2002: IF DSP, NXP i.MX RT685 (image ID)
- Part: **MIMXRT685SFVKB**, Yaesu P/N G1095805, side A, F3 (p37). The block diagram labels it "DSP MAIN/TX" (p6), and the schematic sheet is "MAIN-UNIT/SDR-DSP" (p19). **[fact]**
- Flash: Q2008 **Winbond W25Q128JVSIM**, 128 Mbit (16 MB) QSPI NOR (parts list p37 and schematic p19). The block diagram instead
  shows "MT25QL128ABA1ESE" (Micron, also 128 Mbit) (p6), so the two are probably alternate parts. It connects to **FlexSPI A** (PIO1_18 SCLK, PIO1_19 SS0_N,
  PIO1_20..23 DATA0..3; nets `QFLS_*`) (p19). **[fact]**
- No external RAM. The RT685 has 4.5 MB of on-chip SRAM **[guess]**.
- Boot configuration (p19, printed note): `BootConf_ISP[2:0]` on PIO1_15..17 (pins N3/M4/N4): "111 Serial Master Boot,
  110 Serial ISP, **011 FlexSPI A**". The `DSP_UPDATE` signal (through Q2010/Q2006) selects "L: Normal (FlexSPI) / H: Update (Serial ISP)". **[fact]**
  So in normal operation the code runs from the QSPI flash. For an update, the RT685 ROM serial ISP is used (UART on FC0): DISPLAY sends NXP
  bootloader packets that MAIN relays over SCI4 while it drives `DSP_UPDATE`/`DSP_RESET` (P72/P71) **[fact, both sides]** ([code/display/update.md](code/display/update.md#7-ifdsp-update-rt685-rom-isp-through-main),
  [code/main/dsp-link.md](code/main/dsp-link.md#dsp-firmware-update-bridge)).
- Flash config (FCFB at 0x08000400 in the IFDSP image) **[fact]**: serial NOR, quad pads, `serialClkFreq` 7 (120 MHz **[inference]**), 16 MB,
  256 B pages, 4 KB sectors, 64 KB blocks; LUT read `0xEB` (quad I/O, 6 dummy cycles), status 0x05, WREN 0x06, erase 0x20/0xD8/0x60,
  program 0x02. This matches the W25Q128JV. The firmware has no FlexSPI program/erase code ([code/ifdsp/m33-platform.md](code/ifdsp/m33-platform.md)).
- Clock: `DSP_CLK` from the SDR module (J2002 pin 22) into PIO2_30/CLKIN (p19). The X2002 crystal footprint is marked "***" and
  does not appear in the parts list (p46), so it is not fitted **[fact/inference]**.
- Flexcomm assignment (printed on p19): **FC0: UART** (`DSP_UMISO/DSP_UMOSI`, also brought out to J2009),
  **FC1: FFT/REC/PLAY data** (SPI, probably the display's `DSP_SCLK/SS/MOSI/MISO` link), **FC2: TX AF I2S** (to the SDR module),
  **FC3: RX IF I2S** (`RX_IF_DAT` from the SDR module), **FC4: codec I2S out**, **FC5: codec I2S in**, GPIO: AIC (codec) setting. **[fact]**
- Codec: Q2001 **TI TLV320AIC3204** (I2S + SPI control) (p37, p19).
- USB1 pins go only to test points TP2069–2072 (p19).
- **Debug header J2009, "DSP_JTAG"** (P1091201, 8-pin, p35, p19): 1 RESETn (`JTAG_RESET`), 2 SWO, 3 SWCLK, 4 SWDIO,
  5 UART TX (`JLINK_OUT`), 6 UART RX (`DSP_UMISO`), 7 VCC 3.3 V OUT, 8 GND. This is **ARM SWD + UART** (J-Link). **[fact]**
- Test points: TP2005, TP2017–2021, TP2030, TP2043–2048, TP2074 (p19). The firmware sets **PIO2_4/5/6** (`SCT0_OUT2/OUT3/GPI4` →
  TP2007/2008/2009, marked "for DEBUG") and **PIO0_28/29/31** (→ TP2043/2046/2044) as GPIO outputs, low. PIO2_5 goes high when the M33
  `CommandTask` starts **[fact: code]**. Full pin table: [code/ifdsp/m33-platform.md](code/ifdsp/m33-platform.md).

### SDR module (image SR)
- Shown only as the "SDR MODULE" box on the block diagram, containing "ADC/FPGA, Operating clock 125MHz, Divide 250MHz by 2" (p6). The module's parts are **not in the
  parts list**, so the FPGA and ADC part numbers are **unknown** from this manual. **[fact]**
- Clock: X1002 **35.7142 MHz VCTCXO** (DSA211SDN) → Q1011/Q1010 oscillator/buffer → **250 MHz** sampling clock into the module.
  The FPGA runs at 125 MHz (p6, p46). **[fact]** Whether the ADC then samples at 250 MSPS or at 125 MSPS ("Divide 250MHz by 2")
  is open ([code/system.md O7](code/system.md#8-contradictions-and-open-questions), T19h).
- **RX front end: direct sampling, no mixer or LO** (block diagram p6) **[fact]**. On the MAIN unit: J3001 RX → D3001 protection →
  RL3001 ATT 6 dB → RL3002 ATT 12 dB → RL3003 IPO → D3031/32 THRU or HPF 1.7 MHz → D3003–15 band-pass switch (LPF 0.03–1.7 MHz, BPFs
  1.7–48 MHz, 48–75 MHz; 15 ranges 0.3–1.7 … 56–75 MHz) → Q3020 RF amp (48–75 MHz path) → LPF → D3036/37 TRX switch → Q3025 RFAMP1 →
  RL3004 AMP2 select (Q3027 RFAMP2) → Q3028 MMG3H21N RFAMP → LPF → T3006 balun → J3003 `RX-IN 0.03-75MHz` to the ADC. A separate
  `SCOPE-IN 0.03-75MHz` (T3004) taps the same point, and `DITHER` from the module (T3005) goes through an HPF into it. The switches are
  driven by Q3022 BU2152FS (serial-to-parallel: BPFDT, RFDT, ATTDT). The FPGA tunes digitally: MAIN writes the dial frequency in Hz into
  the RX NCO registers 0x18/0x19 ([code/main/sdr-link.md](code/main/sdr-link.md)) **[fact]**. Sample rate (O7): **125 MSPS is the most
  likely** **[inference, strong]**: the module box reads "Operating clock 125MHz, Divide 250MHz by 2" (p6), and MAIN treats **62.5 MHz =
  fs/2** as a boundary (SDR reg 0x03 bit 5 flips there; the TX scope centre is mirrored about 62.5 MHz, [code/main/sdr-link.md](code/main/sdr-link.md)).
  Above 62.5 MHz the receiver then works in the **second Nyquist zone**; the 56–75 MHz BPF rejects the image of the 70 MHz band
  (125 − 70 = 55 MHz) **[inference]**. **DC4KU's test report** (`Manuals/FT-710_Test-Report_DC4KU_english.pdf`, p1) says the ADC is a
  **dual-channel 14-bit** part, "the same twin ADC as in the FT-DX10", and that the FPGA combines the two channels so that overload
  comes late, with dither fed into both inputs **[fact: third-party report]**. That explains the 14 DDR-captured LVDS pairs as two
  14-bit channels multiplexed on the two clock edges (channel A on one edge, B on the other) at 125 MSPS each **[inference, strong]**,
  which removes the last argument for 250 MSPS. The ADC part number is still unknown (read its marking).
- **Physical form (exploded view, p5):** a separate small PCB mounted **under the MAIN unit**, screwed down (screw ⑨) with thermal
  pads RA6334400/RA6334500 and gaskets RA6119900/RA6143800 against the chassis floor, which acts as its heat sink **[fact for the
  drawing]**. It is drawn without its own part number, so it appears to come with the MAIN assembly CS2712704 (USA) / CS2712705 (EU)
  **[inference]**. It mates with the MAIN board through a board-to-board connector, and a short wire assembly **TT9207967** runs
  between the two boards **[fact for the drawing]**. That this board is the SDR module is an **[inference, strong]**: it is the only
  separate board under MAIN, J2002 is labelled "SDR MODULE", and it is cooled the way an FPGA/ADC board would be. That TT9207967
  carries the J3003 RF/analog lines (RX, TX, DITHER, SCOPE) while J2002 carries power, clocks and logic is a **[guess]**.
- Connections: J2002 = **Panasonic AXK6S60647YG, 60-pin board-to-board**, labelled "SDR MODULE" (p35, p19). J3003 (SSL00-10S,
  TX1_P/N, RX_P/N, DITHER, SCOPE_IN) carries the RF and analog lines (p6, p35). J2002 signals (p19):
  `SDR_SCLK/SS/MOSI/MISO` (SPI from the DISPLAY CPU), `SDR_UMOSI/UMISO` (UART to the MAIN CPU SCI5), `SDR_DBG_IN/OUT` ("UART DBG RX/TX"),
  `SDR_RESET`, `SDR_UPDATE`, `SDR_PGD`, `SDR_DET`, `SDR_OVF`, `DSP_CLK`, `TX_AF_CLK/FRM/DAT`, `RX_IF_CLK/FRM/DAT`,
  `FRM_CLK/FRM/DAT` ("FFT/FRM" data), `FADC0/1`, `FSK_SHIFT`, `SEND_A`, `TX`, plus JTAG `SDR_TDI/TDO/TMS/TCK/VDD`.
- **JTAG header J2001, "SDR JTAG"** (P1091255, 6-pin 06FLT-SM2, p35, p19): 1 GND, 2 VDD, 3 TCK, 4 TDO, 5 TMS, 6 TDI. This is plain FPGA JTAG. **[fact]**
- **FPGA identified (T08):** Xilinx Artix-7 **XC7A50T**: IDCODE 0x0362C093 in the bitstream, and the length matches the 7A35T/50T die **[fact]**. The bitstream sets BSPI 0x26B, so the FPGA **self-boots in master-SPI x4 mode from a QSPI flash on the module** (read opcode 0x6B) **[fact]**. The package and speed grade are not in the bitstream.
- J2002 pin map (all 60 pins, read from p19) and what it implies: [code/sdr/interfaces.md](code/sdr/interfaces.md#j2002-pin-map) (T13).
  The DISPLAY's `SDR_SCLK/SS/MOSI` land on the module's `FFT_CLK/FRM/DAT` pins (FPGA fabric), and `SDR_UPDATE` goes to the module pin labelled
  `WP` (pin 53) **[fact]**.
- **Update path (resolved by T10c/T11c/T11d):** DISPLAY sends the SDR image in 4 KiB blocks over **RSPI2 switched to master mode** on the
  FFT pins P8_3..P8_6 (`sdr_spi_master_write`), while **MAIN bridges the register frames** (flash address regs 0x30/0x31, command 0x32,
  CRC-16 0x33) between DISPLAY (SCI1) and the FPGA (SCI5) **[fact: code]**. MAIN holds `SDR_UPDATE` (P76) **low** during the update and pulses
  `SDR_RESET` (P77) with `SDR_UPDATE` high at the end. So the module pin `WP` acts as an "update mode" input to the FPGA rather than a plain
  flash write-protect, and the FPGA fabric writes its own config flash **[inference]**. Details: [code/main/sdr-link.md](code/main/sdr-link.md),
  [code/display/update.md](code/display/update.md#8-sdr-update-fpga-registers-through-main-data-over-the-sdr-spi).

### USB / CAT path (MAIN, AF sheet p20)
- J2602: USB **Type-B** jack (SUB-110HB-B2N, p35) → Q2607 **Cypress/Infineon CY7C65631-56LTXIT** USB 2.0 4-port hub (HX2VL),
  with its own X2601 24 MHz crystal (p37, p46, p20). The printed port map (p20) is:
  **PORT1: CP2105, PORT2: CM119B, PORT3: FT4222, PORT4: N/A**. **[fact]**
- Q2614 **Silicon Labs CP2105-F01-GMR**, a dual USB-UART bridge (p37). Its **SCI ("Standard") port → `USBSS_*` → RX SCI0**, and its
  **ECI ("Enhanced") port → `USBSE_*` → RX SCI3**. RTS/DTR are routed to the CPU through UMD5N buffers (`USBSS_RTS/DTR`, `USBSE_RTS`; used
  for PTT/keying) (p20, p17). The note on p20 reads: "SCI(Standard)=SS, ECI(Extend)=SE". **So CAT goes from the PC through CP2105 to the RX651 SCI0/SCI3.** **[fact]**
- Q2624 **C-Media CM119B**, the USB audio codec (p37, p6).
- Hub PORT3 goes over J1801 → J6002 (`FT4222_DP/DM`) to the **FTDI FT4222HQ** on the DISPLAY unit (p20, p62).
- The 8-pin mini-DIN/RTTY and other rear-panel data lines are not covered here. No RS-232 level shifter (MAX232-type) is in the parts list, so the radio has
  **no DB-9 RS-232 port**: CAT is USB only, plus the ACC/DATA connectors at logic level. **[inference]**

### DVI/HDMI external display (MAIN, DVI sheet p18)
- Q1801 **EP102C** ("LVDS RCV"), Q1803 **EP952** ("HDMI TRX"), Q1805 **EPF021M-YM** ("MICRO CNTL") with X1801 24 MHz (p37, p46, p6).
  The output connector is J1803 DVIR-25SIAAABH0, the "DISPLAY" DVI-type jack (p35, p6). LVDS from the DISPLAY CPU arrives over J6002/J1801 (p62). **[fact]**
- The EPF021M is a small controller with its own firmware, which is not in any SFL image as far as we know **[guess]**.

### MAIN power / reset
- Q2013 BU4228FVE reset IC for the DSP (p6, p37). Q2011 MP5470GL PMIC for the DSP rails: 1.1 V VCORE, D1.8 V, D3.3 V, D5 V (p6). Q1028 NJM2835 → CPU3.3V (p6).

---

## DISPLAY unit (p62; parts p64–71)

### Q6009: display CPU, Renesas RZ/A1H (image PC)
- Part: **R7S721001VCBG** (Yaesu P/N G1095582, side B, f2) (p67). The block diagram labels it "CPU" (p6). R7S7210**01** = RZ/A1H, "BG" = BGA (324-pin) **[guess for the decode]**.
- External memory: **no SDRAM is in the parts list**, so the CPU runs from on-chip SRAM (10 MB on RZ/A1H) **[inference + guess]**.
- Flash: Q6018 **Winbond W25Q128JVFIQ**, 128 Mbit (16 MB) SPI NOR (two lot codes listed, -YR2340 / -YR2513) (p67). It connects to the
  SPI multi-I/O bus controller (SPIBSC0) pins P9_2..P9_7 (`QF_CLK`, `QF_CSn`, `QF_DAT0..3`), plus `QF_RESETn` on P11_2 (p62). **[fact]**
- Boot pins: `BOOT0`/`BOOT1` (P0_0/P0_1), `BOOT2`, `MD_CLK`, `MD_CLKS` set by resistor straps R6084–R6104. Some of these are marked
  "***" (not fitted), and the drawing notes "MD_CLK:1" (p62). I could not resolve exactly which straps are fitted. Because the flash is on SPIBSC0, the board most likely uses
  **RZ/A1 boot mode 1, serial flash boot**, which maps the flash at 0x18000000 **[inference/guess]**.
- Clocks: X6001 **48 MHz** on USB_X1/X2 (also the CPU clock source in clock mode MD_CLK=1), X6002 **27 MHz** on VIDEO_X1/X2,
  X6003 **32.768 kHz** for the RTC, X6004 **12 MHz** for the FT4222H (p71, p62). EXTAL is not connected (p62). **[fact]**
  `AUDIO_X1` and `RTC_X1` of the RZ/A1H are grounded, so the on-chip audio clock and RTC are not used (the S-35190A is the RTC) (p62) **[fact]**.
- Peripherals: Q6015 **ABLIC S-35190A** RTC (3-wire `RTC_DT/CK/CS` on P1_0..P1_2) with BT6001 ML614 lithium cell. Q6008 **TI TSC2003**
  touch-screen controller (I2C `TSCL/TSDA`, `TINT` on P1_3..P1_5). Q6010 MP3301 backlight driver. SD card (`SD_*` on P11_x, the SDHI) and
  rotary encoders/keys (p62, p67). The TFT is driven over the parallel RGB pins (R/G/B on P3/P4). LVDS output goes to the MAIN DVI chain (p62).
- **Other DISPLAY nets** (p62, with the firmware's pin set-up; full table in
  [code/display/peripherals.md](code/display/peripherals.md#2-pin-multiplexing), T11g) **[fact]**: P7_9 `RX_PWR_ON` / P7_11 `RZ_PWR_ON`
  (power latch, driven high in `main`), P8_14 `5VON`, P7_12 `SDPWS` (SD power), P8_10 `USB0_EN`, P8_11/P8_13 `USB0_PG`/`USB1_PG`,
  P8_12 `USB_DET`, P4_6 `LCD_STBY`, P4_7 `BLPWM`, P10_4 `LED_DIMR`, P10_14 `LCD_PWR_EN`, P3_4 `LCD_DEN`, P11_15 `LCD_CLK`,
  P6_4..P6_14 the panel LEDs (`LED_D_*`, `LED_POWER`, `LED_TX`, ...), P5_8/P5_9 `DVR1`/`DVR0`, P5_0..P5_7 LVDS, P11_4..P11_11 SD card (**SDHI0**),
  ADC AN0..AN4 on P1_8..P1_12.
- **Front-panel input** (T11f, [code/display/input.md](code/display/input.md)) **[fact: code]**: a 4×4 key matrix with rows (`KDAT0..3`)
  P7_13, P7_14, P7_15, P8_0 and scan columns (`KSCAN0..3`) P8_1, P8_2, P8_7, P8_8 (`KDAT4` on P8_9); direct keys P2_0 (power, IRQ5), P3_0,
  P3_6, P8_15, P9_1, P10_5 (MIC PTT), P10_6; ADC AN0/AN1 = the two pots, AN3/AN4 = mic key ladders; encoders 1/2 on MTU2 ch1/ch2 (phase
  counting), encoder 3 on IRQ4 with P3_3/P3_5. The TSC2003 touch controller is on **RIIC2**, slave **0x48**, pen IRQ `TINT` = IRQ3.
- **Buses to the rest of the radio** (J6001, 30-pin, to MAIN J1009) (p62, p17):
  - `SDR_SCLK/SS/MOSI/MISO` (RZ P8_3..P8_6): **SPI to the SDR module**. RSPI2, DISPLAY is the slave receiving the scope stream; it switches
    to master only to send an SDR update ([code/display/spi-links.md](code/display/spi-links.md)) **[fact: code]**
  - `DSP_SCLK/SS/MOSI/MISO` (RZ P2_8..P2_11): **SPI to the RT685** FC1 ("FFT/REC/PLAY data"). RSPI4, DISPLAY is the slave: AF-FFT plus
    16 kHz stereo PCM for the voice recorder each way **[fact: code]**
  - `DISP_UMOSI/UMISO` (RZ P6_6/P6_7): **UART to the RX651 SCI1** (SCIF5, 345600 8N2 by DISPLAY's clock), the main command link and also the
    RX boot-mode programming link ([code/display/mainlink.md](code/display/mainlink.md))
  - `RX_UPDATE` (P4_3) and `RX_RESET` (P7_10): **control the MAIN CPU's boot mode and reset**
  - `PWR_SW`, `RX_PWR_ON`, `USB_DET`
  - `ACC_CLK/FS/MISO/MOSI/UMOSI/UMISO`: an accessory bus, unpopulated on the DISPLAY side (resistors marked "***")
- **USB on DISPLAY**: Q6020 **FTDI FT4222HQ** (USB 2.0 → SPI/I2C/GPIO bridge, p67). Its USB comes from hub PORT3. Its SPI master pins
  (`ACC_MOSI/MISO/SCLK`, `ACC_FS`) go to the RZ/A1H SPI on P2_12..P2_15, and the RZ drives `FT4222_RESET` (P2_7) (p62) **[fact]**.
  **Purpose (T11d):** RSPI0 with DISPLAY as the **slave** streams 4 KB SPI frames to the PC, each holding the SDR scope record (850 B), the
  AF-FFT record (600 B) and a 151-byte status block from the MAIN link; PC → DISPLAY data is only parsed in a test mode. A MAIN-side setting
  switches the bridge on through `FT4222_RESET` ([code/display/spi-links.md](code/display/spi-links.md#link-3-ft4222h-usb-to-spi-bridge-rspi0))
  **[fact for the code]**. The PC software that reads it is not known.
  The RZ/A1H's own USB0/USB1 (`USB0_DP/DM`, `D+1/D-1`) also run through J6002 to the MAIN unit (p62). Where they end up is not resolved.
- **JTAG header J6003** (P1091201, 8-pin, p66, p62): 1 3.3 V, 2 TMS, 3 TCK, 4 TDO, 5 TDI, 6 TRST, 7 nRZRST, 8 GND.
  This is plain ARM JTAG for the Cortex-A9 (`JT_*` nets on the RZ TCK/TMS/TDI/TDO/TRST pins). **[fact]**

---

## PA unit (p47–61) and JACK unit (p72–74)
- PA: no programmable devices. It holds regulators (NJM7808/7805, TAR5S30), an LM2902/2904 op-amp, BU2505FV DAC, BU2152FS serial-in shift registers (×2),
  INA180 current sense, and an F2255 RF attenuator (p56–57). It is controlled by the MAIN CPU's serial shift-register bus over J1002/J4002 (p17).
- JACK: front-panel phones/mic jacks only. No ICs except a 2SC4116 mic amplifier (p6, p74).

---

## Inter-processor topology

```
 PC (USB-B) ── CY7C65631 hub ─┬─ P1: CP2105 ─ SCI port ─ RX651 SCI0   ("Standard" CAT)
                              │              └ ECI port ─ RX651 SCI3   ("Enhanced" CAT)
                              ├─ P2: CM119B (USB audio)
                              └─ P3: FT4222H ─ SPI ─ RZ/A1H (DISPLAY)

 RZ/A1H (DISPLAY, PC image) ── UART ── RX651 SCI1 (MAIN, MC image)   + RX_UPDATE/RX_RESET (RZ flashes RX)
        │  SD card (firmware files)
        ├── SPI (RSPI2) ── SDR module (FPGA, SR image): scope in; image out during an update
        └── SPI (RSPI4) ── RT685 FC1 (IF DSP, ID image): AF-FFT + REC/PLAY PCM

 RX651 ── SCI5 + SDR_UPDATE/RESET ── SDR module    (register frames; bridges DISPLAY during an SDR update)
 RX651 ── SCI4 + DSP_UPDATE/RESET ── RT685 FC0     (console/register file; relays ISP during an IFDSP update)
 RX651 ── SCI7 + SPI + C4_* ── "C4" bus (SCI7 never started in V01-12)
 SDR module ── I2S RX_IF / TX_AF + DSP_CLK ── RT685 ── I2S ── TLV320AIC3204 codec
 RX651 ── SPI ── BR25G256 EEPROM;  ── shift registers ── PA unit
```

## Image → processor mapping

| Image | Tag | Processor | Evidence | Confidence |
|---|---|---|---|---|
| FT-710_MAIN | MC | Q1001 RX651 R5F56514ADFB | Labelled "MAIN CPU" (p6). It is the only CPU with the CAT UARTs (p17, p20). The update manual calls it "MAIN". The RX boot-mode-over-display-UART wiring (p17, p62) explains why the update manual says to update DISPLAY first. | High |
| FT-710_DISPLAY | PC | Q6009 RZ/A1H R7S721001VCBG | It is the only processor on the DISPLAY unit (p67). It owns the SD card that the update reads from. | High |
| FT-710_IFDSP | ID | Q2002 i.MX RT685 | Labelled "DSP MAIN/TX". It takes the RX_IF / TX_AF I2S streams (p6, p19). It is the only DSP. Its 16 MB QSPI flash and FlexSPI boot need an image. | High |
| FT-710_SDR | SR | FPGA in the SDR module | Labelled "SDR MODULE ADC/FPGA" (p6). It has `SDR_UPDATE` and its own JTAG (p19). Decoded as a Xilinx XC7A50T bitstream (T08). | High |

Side note for T03/T04 **[guess]**: each SFL header's length field equals the file size. MAIN is 1,355,160 bytes, about 2.6× the guessed
512 KB code flash. That ratio fits a text encoding (for example Motorola S-records with 32-byte data lines, about 2.4×) better than raw binary.

## Implications for Ghidra (T05–T08)

Ghidra 12.1.4 as installed (Homebrew) ships **ARM, Xtensa**, M16C, SuperH, V850, and other processors, but **no Renesas RX processor module**
(checked under `Ghidra/Processors/`).

| Task | Image | Language ID | Probable load / flash base | Notes |
|---|---|---|---|---|
| T05 | MAIN (MC) | **none in stock Ghidra.** RX needs a third-party SLEIGH module (community "RX" / RXv2 extensions exist) **[guess]** | RX651 code flash is mapped at the top of the 32-bit space. For 512 KB that is **0xFFF80000–0xFFFFFFFF**, with the reset vector at 0xFFFFFFFC and the data flash at 0x00100000 **[guess, from the RX65N/651 memory map]** | Little-endian instructions. Get an RX module first (follow-up). Fallback: the RX disassembler in Renesas CC-RX/GNU binutils `rx-elf-objdump`. |
| T06 | DISPLAY (PC) | **`ARM:LE:32:v7`** (ARM + Thumb-2, Cortex-A9) | If the image is a raw flash dump: the SPI XIP window at **0x18000000** (RZ/A1 boot mode 1). The application is probably copied into on-chip SRAM at **0x20000000** (10 MB) by a loader **[guess]** | Look for an ARM vector table / `LDR PC` branches at offset 0, and a loader at the start of the flash. |
| T07 | IFDSP (ID) | **`ARM:LE:32:v8-m`** (Cortex-M33) for the M33 code. Any HiFi4 DSP code inside is **`Xtensa:LE:32:default`** | FlexSPI A XIP: **0x08000000** (non-secure alias; secure alias 0x18000000). The RT600 boot ROM expects the FCB at flash offset 0x400 and the image vector table at the start of the image **[guess, from the RT600 boot ROM docs]** | The file is small (415 KB), so it may be just the application. Check for an initial SP/reset vector pair in the first 8 bytes. |
| T08 | SDR (SR) | FPGA bitstream, probably **not CPU code**. If there is a soft core (Nios II / MicroBlaze / RISC-V), use the matching language later. | Not applicable | First identify the FPGA vendor from bitstream sync words (Xilinx `AA 99 55 66`, Intel/Altera, Lattice `FF FF BD B3`, and so on) after decoding. |

## Unresolved / not in the manual
- The SDR module's FPGA, ADC and config-flash part numbers (the module is undocumented). The FPGA is now known: **XC7A50T** (T04/T08). The ADC and flash parts are still unknown.
- Exactly which RZ/A1H boot-mode straps are fitted (BOOT0..2 resistors marked "***") (p62).
- Pins 7 and 8 of J1004 (TP1029/TP1030).
- The C4 bus endpoint: the mapping C4 = RT685 is an inference. The firmware does not use SCI7, and the DSP traffic goes over SCI4.
- Where the RZ USB0/USB1 lines finally go. (The FT4222H purpose is resolved above, T11d.)
- The exact flash/RAM sizes are decoded from part numbers, not printed in the manual.
