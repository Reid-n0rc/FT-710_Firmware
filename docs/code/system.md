# FT-710 system overview: how the four images work together

This page describes the whole radio: which processor runs which image, the buses between them, and the main end-to-end flows
(power-on, firmware update, CAT, tuning, transmit, scope). It is built from the per-image pages and does not repeat their detail.
Every flow links to the page that holds the addresses and the function tables.

| Image | Page |
|---|---|
| MAIN (MC), RX651 | [main/README.md](main/README.md) |
| DISPLAY (PC), RZ/A1H | [display/README.md](display/README.md) |
| IFDSP (ID), i.MX RT685 | [ifdsp/README.md](ifdsp/README.md) |
| SDR (SR), XC7A50T bitstream | [sdr/README.md](sdr/README.md) |

Other references: hardware and schematic facts in [../hardware.md](../hardware.md), memory maps in [../memory-maps.md](../memory-maps.md),
CAT commands in [../cat-commands.md](../cat-commands.md), the SFL container in [../sfl-format.md](../sfl-format.md), and custom-firmware
feasibility in [../custom-firmware.md](../custom-firmware.md).

Tags follow AGENTS.md: **[fact]** = seen in code, data or the service manual (the cited page holds the address), **[inference]**,
**[guess]**. A tag on this page is the tag of the claim on the cited page, unless this page says it settled the claim. Function names are
the current Ghidra names used on the per-image pages. All work here is static; nothing was sent to the radio.

## 1. The radio at a glance

| Image | Device (ref, board) | Code | OS / structure | Main job | Clocks |
|---|---|---|---|---|---|
| MAIN `MC` V01-12 | Renesas RX651 R5F56514 (Q1001, MAIN unit) | 512 KB flash at 0xFFF80000 | no RTOS: 16-task polled super-loop `main_loop` | radio state, CAT, EEPROM, RF/PA control, TX/RX sequencing; master of the SDR and DSP control links | 24 MHz crystal, ICLK 120 MHz, PCLKB 60 MHz **[fact]** |
| DISPLAY `PC` V01-08 | Renesas RZ/A1H R7S721001 (Q6009, DISPLAY unit) | 3.3 MB in 10 MB on-chip SRAM, loaded from a 16 MB SPI flash with two banks | NORTi µITRON 4.0, ~32 tasks, 10 ms tick | touch GUI, keys/encoders, SD card, RTC, all firmware updates, PC scope stream (FT4222H) | 48 MHz, CPU 384 MHz **[inference]** |
| IFDSP `ID` V01-01 | NXP i.MX RT685 (Q2002, MAIN unit) | 415 KB image in 16 MB QSPI (FlexSPI XIP) | M33: FreeRTOS (console, codec set-up); HiFi4: Cadence XOS threads (audio) | IF/AF DSP: demodulation, filters, AGC, NR, TX audio processing, codec I/O | CLKIN 18.432 MHz from the SDR module, M33 198 MHz, DSP 594 MHz **[fact]** |
| SDR `SR` V01-04 | Xilinx Artix-7 XC7A50T on the plug-in SDR module (J2002/J3003) | 2.19 MB bitstream in the module's QSPI flash | no CPU, no soft core **[inference, high]** | ADC capture, RX down-conversion (NCO + FIR), scope/FFT data, TX up-conversion, `DSP_CLK` | 250 MHz sample clock, 125 MHz fabric (p6) **[fact]** |

There is a fifth programmable part, the EPF021M (Q1805) in the DVI/HDMI chain, with no firmware in any SFL file **[guess]**
([hardware.md](../hardware.md#dvihdmi-external-display-main-dvi-sheet-p18)).

**Who is master of what** **[fact for the code paths; the summary is inference]**:

- **DISPLAY** owns the power key, the front panel and the SD card. It switches the MAIN CPU's power and reset lines, wakes MAIN with the
  `F0` hello, and is the only CPU that can update the others.
- **MAIN** owns the radio state. Everything that tunes, keys or configures the RF chain goes through MAIN, and MAIN pushes that state to
  the FPGA (SCI5), the DSP (SCI4) and the DISPLAY (SCI1) by polling for changes.
- **SDR FPGA** and **RT685** are register-file slaves on their control UARTs. They are SPI **masters** on their data links to the DISPLAY.

## 2. Block diagrams

### 2.1 Processors and control/data buses

```mermaid
flowchart LR
  subgraph DISPU["DISPLAY unit"]
    D["RZ/A1H<br/>DISPLAY image"]
    DF[("W25Q128 SPI flash<br/>loader + 2 banks")]
    SD[("SD card I:")]
    FT["FT4222H<br/>USB-SPI bridge"]
  end
  subgraph MAINU["MAIN unit"]
    M["RX651<br/>MAIN image"]
    EE[("BR25G256<br/>SPI EEPROM")]
    R["i.MX RT685<br/>IFDSP image"]
    RF[("W25Q128<br/>QSPI flash")]
    subgraph MOD["SDR module"]
      F["XC7A50T<br/>SDR bitstream"]
      FQ[("QSPI config flash")]
    end
    PA["PA unit<br/>shift regs + DACs"]
  end
  D <-->|"SCIF5 ↔ SCI1, ~345 kbit/s 8N2<br/>+ RX_RESET, RX_UPDATE, RX_PWR_ON"| M
  M <-->|"SCI5, 115200 8N1<br/>+ SDR_RESET, SDR_UPDATE"| F
  M <-->|"SCI4 ↔ FC0, 115200 8N1<br/>+ DSP_RESET, DSP_UPDATE"| R
  F -->|"SPI scope, FPGA master<br/>RSPI2 slave"| D
  R <-->|"SPI FC1 1 MHz, RT685 master<br/>RSPI4 slave"| D
  FT -->|"SPI, FT4222H master<br/>RSPI0 slave"| D
  D --- DF
  D --- SD
  M ---|"bit-banged SPI"| EE
  M ---|"serial shift-register bus"| PA
  R --- RF
  F --- FQ
```

Sources: [hardware.md](../hardware.md#inter-processor-topology) (wiring, service manual p17/p19/p62) **[fact]**,
[display/spi-links.md](display/spi-links.md) (SPI roles) **[fact]**, [main/sci.md](main/sci.md) (UART settings) **[fact]**.
Each link's frame format is in [section 3](#3-inter-cpu-protocol-summary).

### 2.2 USB and PC connections

```mermaid
flowchart LR
  PC["PC"] -->|"USB-B J2602"| HUB["CY7C65631<br/>4-port hub"]
  HUB -->|P1| CP["CP2105<br/>dual USB-UART"]
  HUB -->|P2| CM["CM119B<br/>USB audio codec"]
  HUB -->|P3| FT["FT4222H<br/>(DISPLAY unit)"]
  CP -->|"Enhanced (ECI) port"| S3["RX651 SCI3<br/>CAT port 1"]
  CP -->|"Standard (SCI) port"| S0["RX651 SCI0<br/>CAT port 2"]
  CP -->|"RTS / DTR"| PTT["RX651 PC6 / PC5<br/>PTT or CW/RTTY keying"]
  FT -->|"SPI, 4 KiB frames"| RZ["RZ/A1H RSPI0<br/>scope + AF-FFT + status"]
  JACK["TUNER/LINEAR jack"] -->|"5 V TTL"| S2["RX651 SCI2<br/>CAT port 3 / tuner"]
  RZ -->|"P2_7 FT4222_RESET"| FT
```

- CAT runs on three ports. The reply goes back to the port the command came in on, and the AI broadcast goes to every port with AI on
  ([main/cat.md](main/cat.md)) **[fact]**. Port 1 = SCI3 starts at 38400 baud, port 2 = SCI0 at 4800, both are reprogrammed from the menu
  (`sci3_set_baud`, `sci0_set_baud`) ([main/sci.md](main/sci.md#channels)) **[fact]**.
- RTS/DTR of the Standard port are PTT sources 3/4 when the PC KEYING setting selects them ([main/tx-protection.md](main/tx-protection.md#ptt-sources-fact))
  **[fact]**.
- The FT4222H is held in reset until a MAIN-side setting (bit 2 of the 0x24 settings frame) releases it. The PC then reads the SDR scope,
  the DSP AF-FFT and a 151-byte status block ([display/spi-links.md](display/spi-links.md#link-3-ft4222h-usb-to-spi-bridge-rspi0))
  **[fact for the code; the PC software is unknown]**.
- The CM119B is the USB sound card. Its analog side was not traced in the schematic and no firmware touches it **[inference]**; MAIN's MOD
  SOURCE setting selects USB audio as the TX source (`tx_mod_gain`, [main/dsp-link.md](main/dsp-link.md)) **[fact for the setting]**.
- The RX651 and RZ/A1H on-chip USB ports are not used for the PC: the RX651 USB pins go to test points (p17), and the RZ/A1H USB host
  only serves a USB keyboard/mouse (HID) ([display/input.md](display/input.md)) **[fact]**.

### 2.3 Signal path (receive and transmit)

```mermaid
flowchart LR
  ANT["RF front end<br/>(MAIN RX/PA units)"] -->|"RX_P/N"| ADC["dual 14-bit ADC, likely 125 MSPS (O7)<br/>(SDR module)"]
  ADC -->|LVDS| DDC["FPGA RX DDC<br/>NCO reg 0x18/19, FIR"]
  DDC -->|"I2S RX_IF (FC3)"| RXP["HiFi4 Rx_Path<br/>12 kHz blocks"]
  RXP -->|"I2S FC5"| COD["TLV320AIC3204<br/>codec"]
  COD --> SPK["AF amp, speaker,<br/>phones"]
  MIC["MIC / DATA in"] --> COD
  COD -->|"I2S FC4"| TXP["HiFi4 Tx_Path"]
  TXP -->|"I2S TX_AF (FC2)"| TXF["FPGA TX path<br/>NCO reg 0x08/09, ramp"]
  TXF -->|LVDS| DAC["TX DAC? (module)"]
  DAC -->|"TX1_P/N"| PA["PA unit"]
  F2["FPGA MMCM"] -->|"DSP_CLK 18.432 MHz"| RXP
  DDC -->|"scope SPI"| DISP["DISPLAY scope"]
  RXP -->|"FC1 SPI AF-FFT, REC"| DISP
```

Wiring and I2S/flexcomm assignment are **[fact]** (p6, p19; [ifdsp/README.md](ifdsp/README.md#block-diagram)). The blocks inside the FPGA are
**[inference]** from BRAM tables and DSP48 use ([sdr/README.md](sdr/README.md)). The DSP rate of 12 kHz is **[inference, strong]**
([ifdsp/hifi4.md](ifdsp/hifi4.md)). The RX path is clocked by the codec DAC and the TX path by the codec ADC, with 2-deep FIFOs to the SDR
side **[fact, hifi4.md]**.

### 2.4 Storage and debug access

| Store / header | Owner | Holds | Written by | Page |
|---|---|---|---|---|
| W25Q128 SPI flash | DISPLAY | loader (0), bank flags (0x3E0000/0x3F0000), bank 1 (0x400000), bank 2 (0xA00000) | DISPLAY self-update | [display/update.md](display/update.md#6-display-self-update-spi-flash-banks) |
| SD card `I:\FT-710\` | DISPLAY | `.SFL` update files, MemList/Menu backups, screenshots, WAV recordings | user / DISPLAY | [display/update.md](display/update.md), [display/peripherals.md](display/peripherals.md) |
| RX651 code flash | MAIN | MAIN image | DISPLAY via serial boot mode | [display/update.md](display/update.md#5-main-update-rx651-serial-boot-mode) |
| BR25G256 EEPROM (32 KB) | MAIN | all settings, memories, band stacks, calibration (`cfg105`) | MAIN (`eeprom_*`), CAT `SPW`/`E9` | [main/eeprom.md](main/eeprom.md) |
| RX651 data flash | MAIN | not present on the R5F56514 (T18) | — | [main/README.md](main/README.md#memory-map-summary) |
| RT685 QSPI flash | IFDSP | IFDSP image (FlexSPI XIP) | DISPLAY via MAIN relay + RT685 ROM ISP | [display/update.md](display/update.md#7-ifdsp-update-rt685-rom-isp-through-main) |
| SDR module QSPI flash | SDR | bitstream (boots from 0; update writes 0x240000.. and the header at 0x480000) | the FPGA fabric, fed by DISPLAY + MAIN | [sdr/interfaces.md](sdr/interfaces.md#configuration-and-update-sequence) |
| S-35190A RTC | DISPLAY | date/time, sent to MAIN as `E3` | DISPLAY, or MAIN via `0x65` | [display/peripherals.md](display/peripherals.md) |
| J1004 "RX-CPU DEBUG" | MAIN | FINE debug + SCI1 boot UART | — | [hardware.md](../hardware.md#q1001-main-cpu-renesas-rx651-image-mc) |
| J6003 | DISPLAY | ARM JTAG | — | [hardware.md](../hardware.md#q6009-display-cpu-renesas-rza1h-image-pc) |
| J2009 "DSP_JTAG" | IFDSP | SWD + FC0 UART | — | [hardware.md](../hardware.md#q2002-if-dsp-nxp-imx-rt685-image-id) |
| J2001 "SDR JTAG" | SDR | FPGA JTAG | — | [hardware.md](../hardware.md#sdr-module-image-sr) |

Adapters for each header are listed in [custom-firmware.md](../custom-firmware.md#debug-adapters-per-recovery-path).

## 3. Inter-CPU protocol summary

| Link | Physical | Line | Framing | Check | Ack / retry | Pages |
|---|---|---|---|---|---|---|
| DISPLAY ↔ MAIN (control) | RZ SCIF5 P6_6/P6_7 ↔ RX SCI1 P26/P30 | 8N2; MAIN 340.9 kbit/s, DISPLAY nominal 345600 (see [C1](#8-contradictions-and-open-questions)) | `cmd, payload[n], sum8`, no start byte; `n` from a 43-entry table per command; ACK 0x06 / NAK 0x15 single bytes; `'Z'` tunnel frames with a 16-bit length | 8-bit sum of cmd + payload. MAIN checks it and NAKs; the DISPLAY does not check it, only range-checks fields | stop-and-wait, one frame outstanding each way. MAIN: 30 ms window, 3 retries, then drop. DISPLAY: ~10 ms cyclic timeout, 3 retries, then error box or reset of MAIN and itself | [main/display-link.md](main/display-link.md), [display/mainlink.md](display/mainlink.md) |
| MAIN → SDR FPGA (control) | RX SCI5 → J2002 pin 46/48 | 115200 8N1 | ASCII `rAAAAss\r` (8 B) / `wAAAAVVVVss\r` (12 B); reply 1 B for a write, 7 B for a read | sum8 of the preceding characters as 2 hex digits | reply 0x06 (or `?`) for a write, `r VVVV ss` for a read (MAIN's `sci5_rx_byte_hook` picks the length from byte 0; corrected by T19h, see T15e); 6 ms timeout; no retry counter, the shadow-compare re-sends next pass | [main/sdr-link.md](main/sdr-link.md#frame-format) |
| MAIN → RT685 (control) | RX SCI4 → FLEXCOMM0 | 115200 8N1 | after `i DB00\r`: `rAAAAss\r` → `rDDDDss`; `wAAAADDDDss\r` → 0x06; `?` = invalid | sum8 as 2 hex digits | 6 ms timeout; shadow-compare re-send; no limit, no error report after boot | [main/dsp-link.md](main/dsp-link.md), [ifdsp/control-link.md](ifdsp/control-link.md) |
| SDR FPGA → DISPLAY (scope) | FFT_CLK/FRM/DAT → RZ RSPI2 (P8_3..P8_6) | SPI mode 1, FPGA master | 1700-byte DMA frame per SS edge; the first 850 B are kept: 25-byte header + 800 points + 25 | none | none; DMA re-armed on every SS edge | [display/spi-links.md](display/spi-links.md#link-1-sdr-module-scope-data-rspi2) |
| RT685 ↔ DISPLAY (AF data) | FC1 SPI ↔ RZ RSPI4 (P2_8..P2_11) | SPI 1 MHz, RT685 master, full duplex | 4600 B each way: 600 B AF-FFT record + 4000 B of 16 kHz stereo PCM (REC); playback PCM the other way | none | none; ping-pong buffers | [display/spi-links.md](display/spi-links.md#link-2-if-dsp-fftrecplay-rspi4), [ifdsp/hifi4.md](ifdsp/hifi4.md) |
| PC (FT4222H) ↔ DISPLAY | ACC SPI ↔ RZ RSPI0 (P2_12..P2_15) | SPI, FT4222H master | 4096 B: scope 850 B @0, AF-FFT 600 B @0x6A4, status 151 B @0xB64, trailer `0x01EE01FF`×4 | none (test mode: magic 0xEEAFCCBA) | none | [display/spi-links.md](display/spi-links.md#link-3-ft4222h-usb-to-spi-bridge-rspi0) |
| PC ↔ MAIN (CAT) | CP2105 → SCI3 / SCI0, jack → SCI2 | 4800–38400 at reset, menu-set | ASCII `XX…;`, 104 primary + 10 extended mnemonics; binary `SP`/`E9` sub-frames | binary `SP` sub-commands: sum8 | reply on the same port, `?;` on any error, sets silent; AI broadcasts | [main/cat.md](main/cat.md), [../cat-commands.md](../cat-commands.md) |
| DISPLAY → MAIN → RT685 (update tunnel) | SCI1 + SCI4 | as above | DISPLAY `Z len16 payload sum8` → MAIN forwards the payload (NXP MCUBoot packet `5A …`) | relay sum8; MCUBoot CRC-16 | MCUBoot ACK `5A A1` per packet | [main/dsp-link.md](main/dsp-link.md#dsp-firmware-update-bridge), [display/update.md](display/update.md#7-ifdsp-update-rt685-rom-isp-through-main) |
| DISPLAY → MAIN → FPGA (update bridge) | SCI1 + SCI5 | as above | DISPLAY `FD 00 AAAA VVVV sum` / `FE 00 AAAA sum` (ASCII hex fields) → MAIN `w`/`r` frames | sum8 | MAIN answers 06 / 15 / `7D 00 VVVV sum` | [main/sdr-link.md](main/sdr-link.md#sdr-update-bridge) |
| DISPLAY → MAIN (serial boot) | SCIF5 + RX_RESET/RX_UPDATE | 9600, then 345600 | Renesas RX boot protocol `01 LNH LNL CMD data SUM 03`, replies `81` | packet sum | per-command reply; read-back compare | [display/update.md](display/update.md#5-main-update-rx651-serial-boot-mode) |
| M33 ↔ HiFi4 (on-chip) | shared SRAM 0x20070000 + MU-A, rpmsg-lite | — | 32K × 16-bit register file; rpmsg endpoints 0x28 ↔ 0x1E are set up but idle | — | — | [ifdsp/ipc.md](ifdsp/ipc.md) |
| MAIN SCI7 "C4" | P90/P92 | 9600 at create | — | — | never started in V01-12 | [main/dsp-link.md](main/dsp-link.md#sci7-c4-uart) |
| DISPLAY SCIF4 | `ACC_UMOSI/UMISO`? | 38400 | probe `F0`, then `1E 00 31` / `1F 00 32` | — | `uart4_link_init` has no caller | [display/mainlink.md](display/mainlink.md#10-the-unused-scif4-link-fact) |

All rows are **[fact]** from the cited pages, except where those pages tag a field otherwise.

**Common design.** All three control UARTs use the same "shadow register" idea **[fact for each link; the common pattern is inference]**:
MAIN computes the wanted value of every remote register from its own radio state, sends a write only when it differs from the last
acknowledged value, sends at most one frame per `main_loop` pass per link, and lets a missed ACK fall through to a re-send on a later pass.
The DISPLAY link applies the same rule to whole frames (`displink_copy_if_changed`). There are no unsolicited messages from the FPGA or the
DSP; status is polled (DSP regs 1–4 every 20 ms in steady RX/TX).

## 4. Power on and power off

### 4.1 Power-on of all CPUs

```mermaid
sequenceDiagram
  participant U as user
  participant D as DISPLAY RZ/A1H
  participant M as MAIN RX651
  participant F as SDR FPGA
  participant R as RT685
  Note over D: DC on: loader picks bank 1/2, main sets RX_PWR_ON/RZ_PWR_ON (P7_9/P7_11)
  D->>M: task_root: RX_RESET (P7_10) released
  Note over M: PowerON_Reset, app_main: timers, EEPROM load, SCIs on
  Note over F,R: P77 SDR_RESET = 0 and P71 DSP_RESET = 0 from MAIN port init
  loop radio off
    M->>M: displink_task + cat_parse (only PS1#59;)
  end
  Note over D: standby: mainlink_init + GUI only
  U->>D: hold LOCK/PWR about 1 s (P2_0, IRQ5)
  D->>D: power_on_request, power_on_full_init (all drivers and tasks)
  D->>M: F0 01 08 20 23 06 29 code (opening_screen, up to 30x)
  M-->>D: 06, then 0x60 (versions, status), then 0x24 (settings)
  Note over M: 0x20B3A = 1 (radio on)
  M->>M: shreg_bus_init, trx_init (timer 0x13: 2.5 s)
  M->>F: sdr_init: P77 = 1, wait 1000 ms
  Note over F: master SPI x4 boot from QSPI, DSP_CLK starts
  M->>F: r0000 / r0001 (version 0x0104)
  M->>R: dsp_link_init: P71 = 1, wait 100 ms
  Note over R: ROM boots FlexSPI, M33 starts the HiFi4, sets reg 1 bit 0
  M->>R: "i DB00", r0000 (0x0101), r0001 (ready bit)
  M->>M: main_loop: sdr_task / dsp_link_poll push every register
  M->>D: 0x20 status frames, GUI draws the main screen
```

Sources: [display/boot-rtos.md](display/boot-rtos.md#3-task_root-0x201170c8-boot-modes), [display/input.md](display/input.md#boot-key-combinations),
[main/README.md](main/README.md#reset-and-boot-flow), [main/display-link.md](main/display-link.md#link-control),
[main/sdr-link.md](main/sdr-link.md#boot-sequence-sdr_init-proposed-sdr_init), [main/dsp-link.md](main/dsp-link.md#boot-handshake),
[ifdsp/README.md](ifdsp/README.md#boot-flow), [sdr/README.md](sdr/README.md#boot--configuration-flow). Every step is **[fact]** on those pages
except:

- That MAIN is powered and running while the DISPLAY is in standby: **[inference]** from `RX_PWR_ON` going high in the DISPLAY `main` and
  `RX_RESET` being released in the common part of `task_root`.
- That the DISPLAY sends the `F0` hello only after the power key: **[inference, this page]**. The only callers of `mainlink_hello_poweron`
  are `opening_screen` (reached from `power_on_request`) and `mainlink_wait_status` (decomp/display, checked for this page).
- The order "FPGA first, DSP second" fits the RT685 being clocked by the FPGA's `DSP_CLK` **[inference]**: `sdr_init` waits 1 s for the
  FPGA before `dsp_link_init` releases the DSP.
- **Boot key combinations** travel in the `F0` code byte. Code 1 resets the settings, 7 swaps the region code, 2/4/5 start service screens
  in MAIN, 4 also turns on the FT4222H test overlay in the DISPLAY, and 6 (DNR + A/B + QMB) starts the DISPLAY's maintenance/loader screen
  and tells MAIN to stay off (see [C3](#8-contradictions-and-open-questions)) **[fact for the code paths]**.
- **Boot failures**: if the FPGA or the DSP does not answer, MAIN sets `boot_error` 0x20B36 = 3 or 2 and carries on
  ([main/sdr-link.md](main/sdr-link.md#globals)) **[fact]**; how it is shown is open.

### 4.2 Power-off

```mermaid
sequenceDiagram
  participant U as user / CAT
  participant D as DISPLAY
  participant M as MAIN
  alt power key
    U->>D: hold LOCK/PWR
    D->>M: E0 code 0x300, event 2
    M->>M: 0x20B30 = 2
    M->>M: io_task: eeprom_save_opstate, wait for SCI1 to drain, sw_reset
  else CAT PS0 or supply below threshold
    U->>M: PS0#59; (or ADC 0x20B08 < 0x7DD: power_off_io, save opstate)
    M->>M: 0x20F4B = 1, 0x20B39 = 0x10 (PS0) / 0x90 (low voltage)
    M->>D: power_down_save: 0x7F sub (0x10 / 0x90) + 8-byte key
    D->>D: GUI leaves its loop, link frozen, waits for power-on
    M->>M: eeprom_save_all (0x90: 2 s wait instead), sw_reset
  end
  Note over M: restarts in PowerON_Reset, back in the radio-off loop
```

**[fact]** for each MAIN step ([main/README.md](main/README.md#power-states), [main/display-link.md](main/display-link.md#main--display-frames),
[main/peripherals.md](main/peripherals.md#power-on--off)) and the DISPLAY's handling of a keyed `0x7F`
([display/mainlink.md](display/mainlink.md#8-how-the-gui-is-driven)). T19h traced both exits: 0x20F4B is read only by `displink_tx_schedule`
0xFFF95F58, which calls `power_down_save` 0xFFF98797 (the only builder of `0x7F`); the power key's 0x20B30 = 2 is handled in `io_task`
0xFFFB6D56, which saves and resets without a `0x7F` frame **[fact]**. (This replaces an earlier note that left the power-key order open.)
How the DISPLAY learns about a power-key shutdown is then its own key handling, not a MAIN frame **[inference]**.

## 5. Firmware update

The DISPLAY is the only CPU with the SD card, so every update starts there. The user path is **SD CARD → FIRMWARE UPDATE**; the DISPLAY
checks each `I:\FT-710\FT-710_<IMG>_Vxxxx.sfl` by its salted CRC-32 only (no tag, length, signature or model check) and then runs the
selected writers in the order MAIN, DISPLAY, IFDSP, SDR ([display/update.md](display/update.md#1-summary-for-custom-firmware)) **[fact]**.

```mermaid
flowchart LR
  SD["SD card<br/>FT-710_*.sfl"] --> D["DISPLAY<br/>sfl_read_header + CRC"]
  D -->|"1: RX_UPDATE high, RX_RESET pulse<br/>Renesas boot protocol on SCIF5"| MB["RX651 boot ROM<br/>(MAIN flash)"]
  D -->|"2: decoded 256 B chunks"| DF[("own SPI flash<br/>other bank")]
  D -->|"3: F1 02, Z frames"| MR1["MAIN relay<br/>dsp_isp_bridge"]
  MR1 -->|"SCI4, DSP_UPDATE high"| RI["RT685 ROM ISP<br/>(QSPI flash)"]
  D -->|"4: F1 01, FD/FE frames"| MR2["MAIN bridge<br/>sdr_bridge_mode"]
  MR2 -->|"SCI5, SDR_UPDATE low"| FG["XC7A50T fabric"]
  D -->|"4: 4 KiB blocks, RSPI2 master"| FG
  FG --> FQ[("module QSPI flash")]
  D -->|"done: system_reboot"| RST["MAIN reset + DISPLAY<br/>watchdog reset"]
```

All edges are **[fact]** from [display/update.md](display/update.md), [main/dsp-link.md](main/dsp-link.md#dsp-firmware-update-bridge) and
[main/sdr-link.md](main/sdr-link.md#sdr-update-bridge); that the FPGA fabric writes its own flash is **[inference]**
([custom-firmware.md](../custom-firmware.md#update-and-recovery-paths)).

### 5.1 MAIN: RX651 serial boot mode over the DISPLAY link

```mermaid
sequenceDiagram
  participant D as DISPLAY fwobj_main_run
  participant M as RX651 boot ROM
  D->>D: take over SCIF5 (mainlink_rx_ctrl)
  D->>M: RX_RESET low, RX_UPDATE high (MD_FINE low), 5 ms, RX_RESET high
  D->>M: 9600 baud: 00 until 00, 55 until C2
  D->>M: signature, endian, clock 16/120 MHz, bit rate 345600
  D->>M: ID code 16 x FF, area info
  D->>M: erase, then 512-byte program packets per area
  D->>M: read back each area and compare
  D->>M: RX_UPDATE low, reset pulse, wait 500 ms
  D->>M: F0 hello (code 6) to the new MAIN, wait 06
```

[display/update.md §5](display/update.md#5-main-update-rx651-serial-boot-mode) **[fact]**. The SFL payload of MAIN is Motorola S-records; each
record checksum is checked. The ID code of 16 × 0xFF works because the option-setting memory in the image is all 0xFF **[fact]**. The same
SCI1 pins are on J1004, so an external Renesas Flash Programmer can do the same with the DISPLAY held in reset **[inference]**
([custom-firmware.md](../custom-firmware.md#debug-adapters-per-recovery-path)).

### 5.2 DISPLAY: bank write

```mermaid
sequenceDiagram
  participant D as DISPLAY fwobj_display_run
  participant M as MAIN
  participant F as own SPI flash
  D->>M: F1 03 (CAT off), wait 06
  D->>F: erase the other bank's area and its flag block
  loop 256-byte chunks
    D->>F: write decoded bytes, CRC-32 over plain bytes
  end
  D->>F: flag {0x11111111, len, 0, 0, ~crc}
  D->>F: erase the running bank's flag
  D->>M: F1 83, wait 06
```

[display/update.md §6](display/update.md#6-display-self-update-spi-flash-banks) **[fact]**. The boot loader only checks `flag == 0x11111111` and
`len != 0`, bank 1 first, so an interrupted write leaves the old bank bootable **[inference from the order]**.

### 5.3 IFDSP: RT685 ROM ISP relayed by MAIN

```mermaid
sequenceDiagram
  participant D as DISPLAY dsp_isp_program
  participant M as MAIN dsp_isp_bridge
  participant R as RT685 ROM ISP
  D->>M: F1 02
  M->>R: P71 = 0, P72 DSP_UPDATE = 1, 100 ms, P71 = 1, 100 ms
  M->>R: 5A A6 (ping)
  M-->>D: 06
  D->>M: Z len16 [ping, FillMemory, ConfigureMemory id 9]
  M->>R: payload
  R-->>M: 5A xx response
  M-->>D: Z len16 response sum8
  D->>M: Z [FlashEraseRegion 0x08000000, 0xA0000]
  loop 256-byte chunks
    D->>M: Z [WriteMemory + data packet 5A A5]
    M->>R: payload
    R-->>M: 5A A1 ACK, A0 status 0
    M-->>D: Z response
  end
  D->>M: F1 82
  M-->>D: 06 (P72 stays high)
```

[display/update.md §7](display/update.md#7-ifdsp-update-rt685-rom-isp-through-main) and [main/dsp-link.md](main/dsp-link.md#dsp-firmware-update-bridge)
**[fact]**. After `F1 82` the RT685 stays in ISP mode until the final `system_reboot` **[inference]**. There is no read-back.

### 5.4 SDR: register bridge through MAIN, data over the scope SPI

```mermaid
sequenceDiagram
  participant D as DISPLAY sdr_flash_write
  participant M as MAIN sdr_bridge_mode
  participant F as XC7A50T
  D->>M: F1 01
  M->>F: DSP_RESET = 0, SDR_RESET = 0, SDR_UPDATE = 0, 100 ms, SDR_RESET = 1, 2 s
  M->>F: w0037 BCC5 (unlock)
  M-->>D: 06
  loop 536 blocks of 4 KiB
    D->>M: FD 0030/0031 = 0x240000 + i*0x1000, FD 0032 = 3, 1
    M->>F: relayed w frames
    D->>F: 4 KiB over RSPI2 (DISPLAY is master, ~2 MHz)
    D->>M: FD 0032 = 4, 5, FE 0032 (status), FE 0033 (CRC-16)
    M->>F: relayed r frames
    M-->>D: 7D 00 VVVV sum
  end
  D->>F: 4 KiB header last, at 0x480000
  D->>M: F1 81
  M->>F: SDR_RESET pulse with SDR_UPDATE = 1, then DSP_RESET = 1
```

[display/update.md §8](display/update.md#8-sdr-update-fpga-registers-through-main-data-over-the-sdr-spi),
[main/sdr-link.md](main/sdr-link.md#sdr-update-bridge), [sdr/interfaces.md](sdr/interfaces.md#configuration-and-update-sequence) **[fact]**.
The SFL file must be exactly 0x43075A bytes. The meaning of reg 0x32 commands 3/1/4/5 and the 0x240000/0x480000 slot layout versus a boot from
address 0 are open ([C7](#8-contradictions-and-open-questions)).

## 6. End-to-end flows

### 6.1 CAT command round trip, with AI

```mermaid
sequenceDiagram
  participant PC
  participant CP as CP2105
  participant M as MAIN cat_parse
  participant F as SDR FPGA
  participant R as RT685
  participant D as DISPLAY
  PC->>CP: "MD03#59;" (USB, Enhanced port)
  CP->>M: SCI3 RXI, cat_rx_complete: ring slot (port 1)
  M->>M: next pass: cat_dispatch, cat_MD sets the VFO record mode
  Note over M: a set gives no reply, cat_ai_holdoff 200 ms
  M->>F: later passes: sdr_task writes 0x0A, 0x16, 0x18/19, 0x1E, 0x1F ...
  M->>R: dsp_link_poll writes the demod, filter and AGC registers
  M->>D: displink_task: 0x20 status frame (changed)
  M-->>PC: cat_ai_poll: "MD03#59;" to every port with AI on
  PC->>CP: "SPSR0000#59;" (service read)
  CP->>M: SCI3
  M->>F: sdr_reg_access: wait idle, "r0000" + sum
  F-->>M: 7-byte reply, value 0x0104
  M-->>PC: reply with the value on port 1
```

Sources: [main/cat.md](main/cat.md#request--reply-sequence), [main/sdr-link.md](main/sdr-link.md#sdr-register-map-as-seen-from-main),
[main/dsp-link.md](main/dsp-link.md#registers-written), [../cat-commands.md](../cat-commands.md). The parser, ring, reply port and AI path are
**[fact]**. The register list after a mode change is **[fact]** for the updaters that depend on the mode; the order and the exact set for
`MD03;` are **[inference]**. The `SPSR` reply format is in [cat-commands.md](../cat-commands.md#sp--service--debug-command-family-undocumented-high-risk).
`SPS`/`SPD` are high-risk service commands; never send them without the owner's approval.

- At most one CAT command is parsed and one reply sent per `main_loop` pass, and every downstream link sends at most one frame per pass, so
  a CAT change reaches the FPGA, the DSP and the DISPLAY a few passes later, one register at a time **[inference from the structure]**.
- `cat_parse` drops everything except `PS1;` while the radio is off, and returns at once while the DISPLAY has disabled CAT (`F1 03`, sent
  before a DISPLAY self-update) **[fact]**.
- No DSP or FPGA register is ever read on behalf of normal CAT reads; they answer from MAIN RAM. The exceptions are `SPSR`/`SPDR` and
  values MAIN polls anyway (DSP status regs 1–4) **[inference from the handlers]**.

### 6.2 Frequency change: main dial → SDR NCO and display

```mermaid
sequenceDiagram
  participant E as main dial (ENC0)
  participant D as DISPLAY
  participant M as MAIN
  participant F as SDR FPGA
  E->>D: quadrature edges into MTU2 ch1
  D->>D: task_detect_renc (8 ms): signed delta
  D->>M: E1 01 delta ... sum (coalesced while an ACK is pending)
  M-->>D: 06
  M->>M: displink_rx_E1_encoder: enc_main_dial(step)
  M->>M: VFO record +0x4A = new f, refresh flag 0x20F10
  M->>F: sdr_task pass n: w0018 high word (if changed)
  M->>F: pass n+1: w0019 low word
  M->>F: scope centre 0x20/0x21 (CENTER mode)
  M->>M: displink_task: freq_cache_update (0x20F50..0x20F5C)
  M->>D: 0x20 status frame with the new frequencies
  D->>D: snapshot, gui_screen_update within 33 ms
  Note over M: cat_ai_poll sends "FA...#59;" to AI ports
```

Sources: [display/input.md](display/input.md#rotary-encoders-and-pots), [display/mainlink.md](display/mainlink.md#6-tx-path-ack-and-retries-fact-unless-tagged),
[main/ui-keys.md](main/ui-keys.md#encoders-e1), [main/radio-control.md](main/radio-control.md#frequency-path), [main/sdr-link.md](main/sdr-link.md).
**[fact]** for each hop. That `enc_main_dial` ends in the same record update and refresh flag as `cat_FA_FB` is **[inference]** (the dial
path `FUN_fffc53dc`/`FUN_fffc5a84` is not traced to the byte). Notes:

- The DISPLAY sends raw counter deltas every 8 ms; acceleration, FINE/FAST and step size are applied in MAIN **[inference]**.
- The RX NCO value is the dial frequency plus a mode offset (SSB ±1500 Hz + shift, CW pitch, RTTY mark/shift, DATA offset); the TX NCO
  (0x08/0x09) gets the TX frequency 0x20F50 with clarifier and repeater shift **[fact]** ([main/sdr-link.md](main/sdr-link.md#sdr-register-map-as-seen-from-main)).
- No frequency is sent to the DSP; only register 99 changes with the frequency range **[fact]**.
- The FPGA gets 0x18 and 0x19 in two separate frames, so for one or two passes the NCO can hold a mixed value; the updater re-sends
  the low word whenever the high word was written **[fact for the order; inference for the effect]**.

### 6.3 TX key-down (MIC PTT, MOX or CAT `TX1;`)

```mermaid
sequenceDiagram
  participant S as PTT source
  participant M as MAIN io_poll
  participant F as SDR FPGA
  participant R as RT685
  participant D as DISPLAY
  S->>M: CAT TX1 (0x20B28), DATA/RTS/DTR pin, or E0 key from DISPLAY
  M->>M: ptt_source_select, ptt_arbiter: seen on 2 passes, TOT start
  M->>M: tx_freq_allowed(0x20F50) by region table
  M->>M: trx_state 0 → 1, 0x20B6B = 1
  M->>M: DATA_BUSY, AF_MUTE, speakers off, RX (PB7) = 0, TX (P73) = 1
  M->>F: sdr_task: waits for PB7 low, then TX-side registers (0x08/09, 0x25 drive, 0x20/21, 0x26, 0x27)
  F-->>M: ACKs, 0x20B19 = 1
  M->>R: dsp_link_poll: group A setters (TX), group B skipped
  R-->>M: ACKs, 0x20B1A = 1
  M->>M: trx_state 2: TX delay timer 0x11
  M->>M: trx_state 3: SEND_A (PA2) / SEND_B (PB4) keyed
  M->>D: status frames (TX state)
  Note over R,F: mic → codec ADC → Tx_Path → I2S TX_AF → FPGA TX → DAC → PA
```

Sources: [main/tx-protection.md](main/tx-protection.md) (PTT sources, arbiter, sequencer) **[fact]**, [main/sdr-link.md](main/sdr-link.md#the-sdr-task-sdr_task-proposed-sdr_task)
and [main/dsp-link.md](main/dsp-link.md#poll-loop-once-per-main_loop-pass) (TX/RX hand-over) **[fact]**, signal path from §2.3. That 0x20B19 /
0x20B1A are the "SDR / DSP reconfigured" acknowledgements the sequencer waits for is **[inference]**. The MIC PTT on the DISPLAY (P10_5, key
code 0x340) reaches MAIN as an `E0` frame and then sets one of the sources 0x20B2A.. **[inference for the flag]**. Points worth knowing:

- `TX1;` bypasses `key_event_filter`, so CAT TX works where front-panel keys are locked; only `ptt_arbiter` and `tx_freq_allowed` stand
  between it and the RF **[fact]**.
- SEND never leads TX: SEND_A/B are forced low while `ETUN_TXINH_REQ` is high or the TX line is low **[fact]**.
- TX→RX runs the same steps in reverse; the RX-only SDR registers (filters, NB, notch, RX NCO) are re-sent once the TX line has dropped
  **[fact]**.

### 6.4 Scope and waterfall data

```mermaid
flowchart LR
  M["MAIN sdr_task"] -->|"SCI5: scope centre 0x20/21,<br/>span 0x22, level 0x27"| F["FPGA scope / FFT"]
  F -->|"SPI 1700 B frames<br/>(FPGA master)"| R2["DISPLAY RSPI2 + DMA ch5"]
  R2 -->|"first 850 B"| REC["scope record 0x204832BB<br/>25 B header + 800 points"]
  REC --> WF["scope_history_push<br/>waterfall rows 0x20490894"]
  REC --> GUI["GUI scope + waterfall<br/>(33 ms)"]
  WF --> GUI
  DSP["RT685 Thread_Spi"] -->|"SPI 4600 B, 16 frames/s"| R4["DISPLAY RSPI4 + DMA ch4"]
  R4 -->|"600 B"| AF["AF-FFT record 0x208DD73C"]
  AF --> GUI
  REC -->|"every 4 ms"| PCB["PC TX block 0x60501000"]
  AF --> PCB
  ST["MAIN 0x20 status block"] --> PCB
  PCB -->|"RSPI0 + DMA ch9, 4 KiB"| FT["FT4222H → PC"]
```

Sources: [display/spi-links.md](display/spi-links.md), [main/sdr-link.md](main/sdr-link.md#sdr-register-map-as-seen-from-main),
[ifdsp/hifi4.md](ifdsp/hifi4.md) **[fact]** for the transfers and buffers. That the 800 points are one byte per screen column and that the
history ring is the waterfall/3DSS is **[inference]**. The scope never passes through MAIN: MAIN only programs centre, span and level, and the
spectrum data goes FPGA → DISPLAY directly **[fact]**. The SDR frame rate is not fixed by any DISPLAY code **[fact]**.

## 7. Where to find X

| Topic | MAIN | DISPLAY | IFDSP | SDR / other |
|---|---|---|---|---|
| Reset, boot, init order | [README](main/README.md#reset-and-boot-flow) | [boot-rtos](display/boot-rtos.md) | [README](ifdsp/README.md#boot-flow), [m33-platform](ifdsp/m33-platform.md) | [sdr README](sdr/README.md#boot--configuration-flow) |
| Task / loop structure | [main_loop](main/README.md#main-loop) | [tasks](display/boot-rtos.md#tasks) | [threads](ifdsp/README.md#task--thread-structure), [hifi4](ifdsp/hifi4.md) | — |
| Memory map | [README](main/README.md#memory-map-summary) | [README](display/README.md#memory-map-summary) | [README](ifdsp/README.md#memory-map-summary) | [memory-maps.md](../memory-maps.md) |
| UART drivers, baud rates | [sci](main/sci.md) | [mainlink §3](display/mainlink.md#3-scif-driver-fact) | [control-link](ifdsp/control-link.md) | — |
| DISPLAY ↔ MAIN frames | [display-link](main/display-link.md) | [mainlink](display/mainlink.md) | — | — |
| FPGA register map | [sdr-link](main/sdr-link.md#sdr-register-map-as-seen-from-main) | [update §8](display/update.md#8-sdr-update-fpga-registers-through-main-data-over-the-sdr-spi) (0x30–0x33) | — | [interfaces](sdr/interfaces.md) |
| DSP register map | [dsp-link](main/dsp-link.md#registers-written) | — | [control-link](ifdsp/control-link.md) | — |
| SPI data links (scope, AF-FFT, REC/PLAY, PC) | — | [spi-links](display/spi-links.md) | [hifi4](ifdsp/hifi4.md) | [interfaces](sdr/interfaces.md#j2002-pin-map) |
| CAT parser, AI | [cat](main/cat.md) | — | — | [cat-commands.md](../cat-commands.md) |
| Keys, encoders, touch | [ui-keys](main/ui-keys.md) | [input](display/input.md) | — | — |
| GUI, screens, bitmaps | (screen frames in [display-link](main/display-link.md#main--display-frames)) | [gui](display/gui.md) | — | — |
| Menu (EX settings) | [menu](main/menu.md) | — | — | — |
| VFO, band, memories, scan | [radio-control](main/radio-control.md) | — | — | — |
| PTT, TX sequencing, protection, meters | [tx-protection](main/tx-protection.md) | — | — | — |
| EEPROM / settings image | [eeprom](main/eeprom.md) | MemList/Menu backups: [update §2](display/update.md#2-sd-card-and-file-system-summary) | — | — |
| GPIO / pin maps | [peripherals](main/peripherals.md#gpio-map-fact-unless-tagged) | [peripherals](display/peripherals.md#2-pin-multiplexing) | [m33-platform](ifdsp/m33-platform.md) | [interfaces](sdr/interfaces.md#j2002-pin-map), [hardware.md](../hardware.md) |
| Clocks | [README step 2](main/README.md#steps-in-detail) | [peripherals](display/peripherals.md) | [m33-platform](ifdsp/m33-platform.md) | [resources](sdr/resources.md#clocking) |
| Audio / codec | DAC beep in [peripherals](main/peripherals.md) | WAV REC/PLAY in [spi-links](display/spi-links.md#link-2-if-dsp-fftrecplay-rspi4), [peripherals](display/peripherals.md) | [hifi4](ifdsp/hifi4.md), codec in [m33-platform](ifdsp/m33-platform.md) | — |
| Firmware update | bridges in [sdr-link](main/sdr-link.md#sdr-update-bridge), [dsp-link](main/dsp-link.md#dsp-firmware-update-bridge) | [update](display/update.md) | ROM ISP, [README](ifdsp/README.md) | [interfaces](sdr/interfaces.md#configuration-and-update-sequence), [sfl-format.md](../sfl-format.md) |
| Debug consoles and hidden modes | CAT `SP` service set ([cat](main/cat.md#extended-and-service-commands-summary)) | USB-keyboard console, `debug_enabled` ([input](display/input.md), [boot-rtos](display/boot-rtos.md#usb-keyboard-handler-chains)) | interactive console `i DB01` ([control-link](ifdsp/control-link.md)) | UART_DBG on J2002 ([interfaces](sdr/interfaces.md)) |
| Inter-core IPC | — | — | [ipc](ifdsp/ipc.md) | — |
| FPGA resources, BRAM tables | — | — | — | [resources](sdr/resources.md), [bram-tables](sdr/bram-tables.md), [bitstream](sdr/bitstream.md) |
| Custom firmware, recovery | — | — | — | [custom-firmware.md](../custom-firmware.md) |

## 8. Contradictions and open questions

"Status" says whether this page settled the point, and how. Points still open name the task or the evidence that would settle them.
The page fixes proposed for C1, C2, C3, C5, C8 and C10–C13, and the C9 note in ifdsp/hifi4.md, have been applied to the pages named in each row (T14).

| # | Topic | What the pages say | Status / resolution |
|---|---|---|---|
| C1 | DISPLAY link baud | [main/display-link.md](main/display-link.md) and [main/sci.md](main/sci.md): MAIN SCI1 = 60 MHz / (16 · 11) = **340 909** bit/s. [display/mainlink.md](display/mainlink.md#1-summary): "345600 baud … on both sides" | **Not a fault, page wording.** The nominal rate is 345600 (DISPLAY `scif_open(0x54600)` and the boot-mode bit-rate command); MAIN's BRR gives 340.9 k, 1.4 % low, well inside async tolerance **[inference]**. Proposed: reword mainlink.md "on both sides" (see the task file). |
| C2 | `F0` hello repeat interval | [main/display-link.md](main/display-link.md#link-control): "every ~50 ms". [display/input.md](display/input.md#boot-key-combinations), [display/mainlink.md](display/mainlink.md#8-how-the-gui-is-driven): "5 ms apart" | **Partly settled.** The loop is `mainlink_send_hello(n); itron_dly_tsk(5)`, 30 times (decomp/display `mainlink_hello_poweron` 0x201165F4) **[fact]**. `itron_dly_tsk` takes ms **[inference, boot-rtos.md]** but the kernel tick is 10 ms, so the real gap is 5–10 ms **[inference]**; "~50 ms" is wrong. Proposed fix for main/display-link.md. |
| C3 | `F0` code 6 | [main/display-link.md](main/display-link.md#f0-boot-codes): code 6 = "link down, no power on … the DISPLAY is going down". [display/mainlink.md](display/mainlink.md#display--main) table: "6 = normal" | **Settled (this page, decomp/display).** Code 6 is sent only by `mainlink_hello_key6` 0x2011668C, called only from `logo_fade_in` 0x2012FD94, which `power_on_request` and `gui_main_loop` call when boot combination 6 (DNR + A/B + QMB) is held. So code 6 = "DISPLAY maintenance/loader screen, keep MAIN off" **[fact for the call path]**; it is also sent by the MAIN-update writer to the new MAIN ([display/update.md §5](display/update.md#5-main-update-rx651-serial-boot-mode)). Neither "normal" nor "going down" fits. Proposed fixes for both pages. |
| C4 | DISPLAY encoder pins | [display/input.md](display/input.md#rotary-encoders-and-pots): encoders 1/2 on MTU2 ch1/ch2, encoder 3 on IRQ4 P3_3/P3_5. [display/peripherals.md](display/peripherals.md#2-pin-multiplexing): ENC0..3 on P10_x / P9_0 / P3_x, "MTU2 phase counting? [guess]" | **Settled, page fixed (peripherals.md).** Two layers, no conflict: schematic ENC*n* = firmware id *n*+1. ENC2 (P3_3/P3_5) = id 3 **[fact: `renc_irq4_isr` reads PPR3 bits 3 and 5]**; ENC0 (P10_0/P10_1) and ENC1 (P9_0/P10_3) are the only encoder pins set to a peripheral function in `pinmux_init`, so they are the MTU2 ch1/ch2 TCLK inputs **[inference]**; ENC3 (P3_1/P3_2) has no handler **[inference]**. Which TCLK pin is which needs the RZ/A1H pin table. |
| C5 | Meaning of frames `E2`, `E6`, `0x40` | MAIN: `E2` meaning unknown, `E6` = beep request, `0x40` "probably scope/waterfall or meter data [guess]". DISPLAY: `E2` = SD card present, `E6` unknown, `0x40` = status + menu list with five 45-byte text slots (also the "FIRMWARE UPDATE" entry) | **Resolved by combining the two ends** **[inference]**: `E2` = SD-card state (DISPLAY sender `mainlink_send_sd_state`), `E6` = a beep request (MAIN handler calls `beep_request`), `0x40` = menu list. The scope never goes over SCI1 (§6.4), so MAIN's `0x40` guess is wrong. Proposed edits for both pages. |
| C6 | How `PS1;` powers the radio on | MAIN: `PS1` only sets 0x20B9C / 0x1B3D0 ("power-on request to DISPLAY") and waits for `F0`. DISPLAY: radio-on flag 0x208003A0 is set by the power key, or by a second `0x60` frame with byte 0xB3 = 1 while off | **Resolved (#57).** The request *is* frame `0x60`. `cat_PS` with `1` sets 0x9DC5 = 1 (the EEPROM-backed "radio on" flag) and calls `power_on_request`: +0x98 (0x20B9C) = 1 enables MAIN's link transmitter (`displink_tx_poll` sends nothing while it is 0, which is the power-off state) and 0x1B3D0 = 1 makes `displink_tx_schedule` send `displink_tx_60_hello` first. Byte 0xB3 of that frame is 0x9DC5. The DISPLAY's link task (0x2015FA40 file) copies every `0x60` to 0x2045FB00 and, if the radio is off (`FUN_2011727C` = 0), this is not the first `0x60` since the DISPLAY started (counter +0x81B0) and byte 0xB3 = 1, calls `FUN_20117288(1)`, which sets the radio-on flag 0x208003A0. The DISPLAY then powers up and sends `F0`; MAIN's `displink_rx_F0_hello` sets 0x20B3A **[fact, both images]**. The "first `0x60`" rule keeps the normal boot exchange from switching the radio on. |
| C7 | SDR flash layout | [sdr/bitstream.md](sdr/bitstream.md) / interfaces.md: the FPGA boots master SPI x4 **from flash address 0** (sync at 0x1030). [display/update.md §8](display/update.md#8-sdr-update-fpga-registers-through-main-data-over-the-sdr-spi): the update writes the bitstream to **0x240000** and its header to **0x480000** | **Open (T15).** Either a golden image at 0 multiboots into 0x240000, or the FPGA maps the update slots itself **[guess]**. Reading the module flash over J2001 would settle it (needs approval). |
| C8 | `SDR_UPDATE` vs. module pin `WP` | sdr/README.md (older text): MAIN "lifts WP" / flash write-protect. main/sdr-link.md and custom-firmware.md: `SDR_UPDATE` is **low** during the update, an update-mode input to the FPGA | **Settled by T10c/T11c/T16** (code levels are fact). sdr/README.md "Key findings" still reads as a plain write-protect; proposed wording fix. |
| C9 | DSP sample rate vs. REC/PLAY PCM | [ifdsp/hifi4.md](ifdsp/hifi4.md): audio blocks at **12 kHz** **[inference, strong]**. [display/spi-links.md](display/spi-links.md#link-2-if-dsp-fftrecplay-rspi4): REC WAV is **16 kHz** stereo, 16 frames/s | **Open.** Consistent only if `Thread_Spi` resamples to 16 kHz or the WAV header is nominal. FC1 buffer spacing 0x1200 (0x200607E0 → 0x200619E0) matches the 0x11F8-byte frame **[fact]**, so the link itself agrees. Needs the HiFi4 `Thread_Spi` packing (T12e follow-up). |
| C10 | J1004 vs. J1005 | hardware.md now says J1004 (fixed by T17). custom-firmware.md summary table still says "(hardware.md says J1005, see below)" | **Settled (J1004).** Proposed: drop the stale parenthesis in custom-firmware.md. |
| C11 | DISPLAY bank written | custom-firmware.md: "updates itself by writing bank 1 at 0x18400000". display/update.md §6: writes the **other** bank (running 1 → 2, else 1) | **Settled by update.md [fact].** Proposed wording fix in custom-firmware.md. |
| C12 | IFDSP update, MAIN side | custom-firmware.md and hardware.md: "MAIN sets `DSP_UPDATE` … [inference for MAIN]". main/dsp-link.md: `dsp_isp_bridge` drives P71/P72 and sends `5A A6` **[fact]** | **Settled [fact, T10d].** Proposed: upgrade the tag in custom-firmware.md and hardware.md. |
| C13 | SDR boot version | sdr/README.md boot figure: "UART5: version query, settings [inference]". main/sdr-link.md: MAIN reads reg 0 and reg 1 after a 1 s wait **[fact]** | **Settled by T10c.** Minor; the SDR figure can cite sdr-link.md. |
| O1 | `boot_error` 0x20B36 | how a missing FPGA (3) or DSP (2) is shown | Open: `displink_build_60` reads it; trace the DISPLAY's use of the `0x60` frame. |
| O2 | DISPLAY → MAIN 0x43/0x44/0x45 and C3/C4/C5 | MAIN thinks SD/memory-list operations; DISPLAY has 'D'/'E' block read/write of a 32000-byte buffer | Open: MemList/Menu backup through the DISPLAY's block buffer is likely **[inference]**; trace `sdmenu_*` against MAIN's 0x43 callers. |
| O3 | Scope frame | 25-byte header, second 850 bytes of each SDR frame, frame rate | Open: needs T15 (FPGA netlist) or a capture on a debug-enabled unit (approval needed). |
| O4 | CM119B audio routing | not traced in the schematic | Open (hardware, service manual p20). |
| O5 | RZ/A1H USB0/USB1 lines through J6002 | where they end up | Open (hardware). |
| O6 | MAIN tasks 10, 11, 13 | `dispreq_e8_task`, `dispreq_e7_task`, `FUN_fffd0582` | Open (MAIN). E7/E8 look like SD-file operation status from the DISPLAY **[inference]**. |
| O7 | ADC sample rate (T19h) | §2.3 and [sdr/README.md](sdr/README.md): "~250 MSPS". [main/sdr-link.md](main/sdr-link.md) reg 0x03: "Nyquist zone of a 125 MSPS ADC". [hardware.md](../hardware.md): 250 MHz clock, "Operating clock 125MHz, Divide 250MHz by 2" (p6) | **Partly settled.** The FPGA fabric runs at **125 MHz** **[inference, high: UART divider 1,086, [sdr/netlist.md §3.2](sdr/netlist.md)]**, and the clock off the MAIN unit is 250 MHz **[fact, p6]**. Whether the ADC samples at 250 MSPS (two samples per fabric clock; its 14 LVDS pairs are captured DDR) or at 125 MSPS (the ADC divides its 250 MHz input by 2) is **open**: the ADC part is not in the manual and the IDDR edge mode is not decoded. **Update 2026-10-28 (owner's reading of p6): 125 MSPS is the most likely rate [inference, strong].** The ADC/FPGA box says "Operating clock 125MHz, Divide 250MHz by 2", and MAIN treats 62.5 MHz = fs/2 as a boundary (reg 0x03 bit 5; the TX scope centre is mirrored about 62.5 MHz, which is second-Nyquist-zone folding). Above 62.5 MHz the receiver then uses the second Nyquist zone, with the 56–75 MHz BPF rejecting the image (70 MHz ↔ 55 MHz). DC4KU's test report (`Manuals/FT-710_Test-Report_DC4KU_english.pdf`) adds that the ADC is a **dual-channel 14-bit** part (the FT-DX10's twin ADC) whose channels the FPGA combines; so the 14 DDR pairs are two 14-bit channels on the two clock edges, not 250 MSPS **[inference, strong]**. **Settled as far as possible without the part number: two ADC channels at 125 MSPS.** Confirm the two-channel combine logic in the netlist, and read the ADC marking for the part. |
| O8 | `DSP_CLK` frequency (T19h) | [ifdsp/m33-platform.md](ifdsp/m33-platform.md): CLKIN = 18.432 MHz. [sdr/netlist.md §3.2](sdr/netlist.md): MMCM clock on pin P14 = ~28.17 MHz, maybe `DSP_CLK` [guess]. [sdr/resources.md](sdr/resources.md#clocking): ~16.6 MHz [guess, T13] | **Open.** 18.432 MHz is what the RT685 code is built for **[fact]**. The 16.6 MHz figure assumed one MMCM and is superseded by T15's cascade. 28.17 MHz needs an out-of-range 1,440 MHz VCO, so one MMCM divider is probably misread; a multiplier of 22.25 instead of 34 would give 18.432 MHz **[guess]**. Settle by re-checking MMCM_X0Y0's CLKFBOUT fields or by measuring J2002 pin 22 (passive probe, owner approval). |
| O9 | DISPLAY window 0x60000000 (T19h) | [memory-maps.md](../memory-maps.md) and [display/gui.md](display/gui.md): frame buffers at 0x60000000..0x602FF2FF and 0x605048A0, `.data_nc` at 0x60500000, all called an "uncached mirror" of RAM 0x20000000 | **Resolved (2026-10-28).** R01UH0403EJ0700 Table 5.5/53.1: 0x60000000–0x609FFFFF is the mirror of the 10 MB on-chip RAM, but **page-interleaved**, not a plain offset. The RAM is 5 pages × 2 banks of 1 MB; the mirror lists them page by page (p0b0 0x6000, p0b1 0x6010, p1b0 0x6020, p1b1 0x6030, …), while the normal space at 0x20000000 puts p0b0, p1b1, p2b0, p3b1, p4b0 at 0x2000..0x2040 and p0b1, p1b0, p2b1, p3b0, p4b1 at 0x2050..0x2090 (5 MB-part compatibility). So `fb_clear_all`'s 0x60000000 + 0x2FF300 is RAM 0x20000000–0x200FFFFF, 0x20500000–0x206FF2FF; `.data_nc`/fb1/scope DMA in 0x605… are 0x207…; none of them touches the image, stacks, `.data/.bss`, `.data2/.bss2` or the kernel pool, and they are exactly the RAM that #119 found no direct reference to. The MMU leaves the 0x60… window strongly ordered, so it is the uncached view for DMA and frame buffers **[fact: manual + image]**. |
