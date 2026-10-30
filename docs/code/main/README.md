# MAIN image (MC) — code documentation

**Image:** `FT-710_MAIN_V0112.SFL` (tag MC, V01-12, 2024-02-16), decoded to `build/FT-710_MAIN_V0112.bin`, a flat
512 KB code-flash image loaded at **0xFFF80000**. **CPU:** Q1001 Renesas **RX651** R5F56514 (RXv2, little-endian).
Ghidra project `ghidra/FT710_MAIN` (source of truth for names), names file `tools/ghidra/names_main.tsv`, decompiled C
in [`decomp/main/`](../../../decomp/main/INDEX.md). Hardware context: [docs/hardware.md](../../hardware.md#q1001-main-cpu-renesas-rx651-image-mc),
memory map: [docs/memory-maps.md](../../memory-maps.md#main-mc-image-ft-710_main_v0112sfl--t05).

Tags follow AGENTS.md: **[fact]** = seen in code or data at the address given, **[inference]**, **[guess]**.
Names in `code` are the current Ghidra names. Function names are the names applied in Ghidra (`tools/ghidra/names_main.tsv`, merged by T17) and match `decomp/main/`; a name still in *italics* is a description that was not applied as a Ghidra name.

## What the MAIN CPU does

The RX651 is the radio's control processor. It owns no display, no audio DSP and no SD card; it coordinates the
other processors over UARTs and drives the RF hardware through GPIOs, ADCs and a DAC **[fact for the peripheral use,
inference for the role split]**:

- **CAT** remote control on three UARTs (SCI0/SCI3 through the CP2105 USB bridge, SCI2 on the TUNER/LINEAR jack) — [cat.md](cat.md).
- **DISPLAY link** on SCI1 to the RZ/A1H front-panel CPU, which owns the touch screen, keys, encoders and SD card.
  The DISPLAY CPU tells MAIN when to power on and forwards key/encoder events; MAIN sends state for display.
- **SDR link** on SCI5 to the Artix-7 FPGA (register read/write commands, `sdr_reg_access`).
- **DSP link** on SCI4 to the i.MX RT685 IF DSP console (register pokes, `dsp_reg_access`).
- **Settings** in the external BR25G256 SPI EEPROM (bit-banged on port E) and **RF control**: TX/RX sequencing,
  supply and power monitoring (12-bit ADCs), CW keyer, side-tone/beep generator (DAC), band/antenna/tuner lines (GPIO).

There is **no RTOS**: after init the firmware runs a single cooperative super-loop (`main_loop`) that polls 16 tasks.
Time is kept by soft timers ticked from TPU interrupts **[fact]**.

## Block diagram

```mermaid
flowchart LR
  subgraph RX651["MAIN CPU RX651 (MC image)"]
    ML["main_loop<br/>16 polled tasks"]
    CAT["CAT parser<br/>cat_parse"]
    DL["DISPLAY link task"]
    SL["SDR link task"]
    DS["DSP link task"]
    TRX["TX/RX + power task"]
    KEY["keyer / tone / tuner / scan tasks"]
    EE["EEPROM driver<br/>(bit-banged SPI, port E)"]
    TMR["soft timers<br/>TPU0 100 us, TPU3 100 ms"]
  end
  USB["CP2105 USB-UART"] -->|"SCI0 Standard / SCI3 Enhanced"| CAT
  JACK["TUNER/LINEAR jack"] -->|SCI2| CAT
  DISP["DISPLAY CPU RZ/A1H<br/>(touch, keys, SD)"] <-->|SCI1| DL
  FPGA["SDR module XC7A50T"] <-->|SCI5| SL
  DSP["IF DSP RT685"] <-->|"SCI4 console"| DS
  EEP["BR25G256 EEPROM"] <--> EE
  ADC["S12AD0/1 ADC<br/>(supply, FWD/REV, keys)"] --> TRX
  TRX --> GPIO["GPIO: TX/RX, PA, relays"]
  KEY --> DAC["DAC 0x88040<br/>side-tone / beep"]
  ML --> CAT & DL & SL & DS & TRX & KEY
  TMR -.-> ML
```

## Reset and boot flow

`PowerON_Reset` @ 0xFFF8FBDB (fixed reset vector 0xFFFFFFFC) is the Renesas CC-RX/BSP `resetprg` **[fact]**. It sets
USP = 0x1004, ISP = 0x1404, INTB = 0xFFF8E6DC, EXTB = 0xFFFFFF80, FPSW = 0x100 (T05), then:

```mermaid
sequenceDiagram
  participant R as PowerON_Reset 0xFFF8FBDB
  participant B as BSP / R_Systeminit
  participant A as app_main 0xFFF94AFA
  participant D as DISPLAY CPU (SCI1)
  participant M as main_loop 0xFFF94B8B
  R->>B: hw_init_clock (SYSTEM regs, PRCR)
  R->>R: _INITSCT (.bss clear, .data copy), _INIT_IOLIB
  R->>B: `bsp_callbacks_clear` / `bsp_interrupt_open` / FUN_fff8ff3d (BSP callback tables, ICU source select)
  R->>B: `hardware_setup` -> `R_Systeminit` (R_Systeminit: ports, IWDT, DA, ADC, SCI0-7, TPU0-3, group-int callbacks)
  R->>A: main -> app_main (PSW: user mode, I=1)
  A->>A: soft timers + TPU0/TPU3 start, EEPROM WRSR, eeprom_load_all, SCI receive start
  loop radio off (0x20B3A == 0)
    A->>D: displink_task (`displink_task`)
    A->>A: cat_parse (only PS1 accepted), IWDT kick
    D-->>A: frame 0xF0 (power-on, DISPLAY version) sets 0x20B3A = 1
  end
  A->>A: first-boot EEPROM write (if defaults were loaded)
  A->>A: shreg_bus_init, TX/RX init, SDR/DSP link init, keyer/tone/tuner init
  A->>M: screensaver_timer_restart, enter main_loop (never returns)
```

### Steps in detail

| Step | Address | Ghidra name | Inferred name | What it does |
|---|---|---|---|---|
| 1 | 0xFFF8FBDB | `PowerON_Reset` | — | Stack/INTB/EXTB/FPSW set-up, then the calls below; `_CLOSEALL` and an endless `bra` if `main` ever returns **[fact]** |
| 2 | 0xFFF913D7 | `hw_init_clock` | — | clock setup, PLL 240 MHz, ICLK 120 MHz, PCLKB 60 MHz (PLLCR 0x1300, SCKCR 0x21C21222) **[fact: RX651 HWM r01uh0590 §9.2.1, §9.2.5]**. The side-tone code computes TPU periods from **PCLK = 60 MHz** (`6e+07` in `tone_set`) **[fact]** |
| 3 | 0xFFFEDEDA | `_INITSCT` | — | CC-RX section init: BTBL zero-fill, DTBL ROM→RAM copy **[fact]** |
| 4 | 0xFFF8FF5F | `bsp_callbacks_clear` | `bsp_callbacks_clear` | Clears 0x74 words at 0x1FFC4 (BSP interrupt callback table) **[fact; role inference]** |
| 5 | 0xFFF8F8F5 | `_INIT_IOLIB` | — | CC-RX stdio init (FILE table 0x1FF74) **[fact]** |
| 6 | 0xFFF8FFC4 | `bsp_interrupt_open` | `bsp_interrupt_open` | Fills the 0x5F-entry group-interrupt callback table at 0x20194 with 0x10000000 (`FIT_NO_FUNC`), calls `icu_select_init` and `FUN_fff9089e(0/1)` **[fact; FIT naming inference]** |
| 6a | 0xFFF92014 | `icu_select_init` | `icu_select_init` | Writes the ICU selectable-interrupt source registers SLIBXR128.. (0x87780..): e.g. vector 130 ← source 0x0F, 138 ← 0x18, 142 ← 0x1C, 144 ← 0x14, 186 ← 0x40, 189 ← 0x44 **[fact]** |
| 7 | 0xFFF8FF3D | `FUN_fff8ff3d` | — | Clears 4 halfwords at 0x1B5FC **[fact]** |
| 8 | 0xFFF8F7EC | `hardware_setup` | `hardware_setup` | Calls two empty stubs, `R_Systeminit`, port direction init `FUN_fff91608`, `FUN_fff8f809` (PRCR-protected module-stop / ADC register), `FUN_fff8f879` (register 0xC5800) **[fact]** |
| 8a | 0xFFF8F65E | `R_Systeminit` | `R_Systeminit` | Renesas Code Generator init: `R_Pins_Create`-like port set-up, IWDT, DA, S12AD0/1, `R_SCI0..5_Create`, TPU0/1/3 create, `R_SCI6_Create_IIC`, `R_SCI7_Create`, TPU2 create, then registers 17 interrupt callbacks with `R_BSP_InterruptWrite` (ids 7, 10, 0x14–0x20, 0x22, 0x23; the targets sit next to the SCI drivers, so they are the SCI TEI/ERI group callbacks **[inference]**) **[fact for the calls]** |
| 9 | 0xFFF90097 | `R_BSP_InterruptControl` | `R_BSP_InterruptControl` | Called as `(0xB, 1, 0x10000000)` before `main`, and as `(n, 0, 0x10000000)` from the group ISRs (call callback) **[fact for the calls; FIT naming inference]** |
| 10 | 0xFFF8F658 | `main` | — | Calls `app_main` **[fact]** |

### `app_main` @ 0xFFF94AFA **[fact for the call order]**

| Phase | Address | Ghidra name | Inferred name | Role |
|---|---|---|---|---|
| pre-power | 0xFFFB3E6A | `wdt_kick` | `wdt_kick` | → `iwdt_refresh`: writes 0x00 then 0xFF to 0x88030 (IWDTRR, the IWDT refresh sequence) **[fact: code + RX651 HWM r01uh0590 §33.2.1]** |
| pre-power | 0xFFFB2228 | `timers_init` | `timers_init` | Marks the 75 one-shot soft timers (flags 0x11FED) and the 4 slow timers (0x1203A) as expired, sets two periodic on/off timers (450/250 ms, 1000/1000 ms), starts TPU0 (`R_TPU0_Start`) and TPU3 (`R_TPU3_Start`) **[fact]** |
| pre-power | 0xFFFB27DF | `FUN_fffb27df` | — | empty stub **[fact]** |
| pre-power | 0xFFFB01F3 | `eeprom_init` | `eeprom_init` | EEPROM WRSR (0x01) with status 0x80 (bit-banged on port E) **[fact]**. See [eeprom.md](eeprom.md) |
| pre-power | 0xFFFB0229 | `eeprom_load_all` | `eeprom_load_all` | Reads the EEPROM header (0x464F, 10 B) and branches on byte 0x4658: **1** = valid image, read everything from EEPROM 0 and return; **0** = read `cfg105` (0x000A) and the destination code (0x010F), then `settings_defaults(0)`; **other** (blank EEPROM) = clear the header, `settings_defaults(1)`, save `cfg105` and destination. In the last two cases it sets 0x20B45 = 1 (defaults loaded) **[fact]** |
| pre-power | 0xFFFBBD53 | `key_task_init` | — | → `FUN_fffc4d93`: copies a 31-byte per-port config block (index 0x9BC9) to 0x20B4C and reapplies `sci3_set_baud` if it changed **[fact]** |
| pre-power | 0xFFFB1632 | `sci_start_all` | `sci_start_all` | `sci0_set_baud`, SCI1 receive into 0x9E86 (0x204 B), `sci2_configure`, `sci3_set_baud`, SCI4 and SCI5 start **[fact]**. See [sci.md](sci.md) |
| pre-power | 0xFFF94CAB | `qmb_boot_init` | `qmb_boot_init` | Initialises fields of the state block 0x20B04 (see below), checks two settings (0x9DBE/0x9DBF == 5) **[fact]** |
| power-off loop | 0xFFF94D6F | `displink_task` | `displink_task` | Runs while 0x20B3A == 0 **[fact]**; see the main-loop table |
| power-off loop | 0xFFFA347C | `cat_parse` | — | Only `PS1` is accepted while off ([cat.md](cat.md)) **[fact]** |
| post-power | 0xFFFB02AF | `eeprom_save_all` | `eeprom_save_all` | Only if 0x20B45 == 1: writes the RAM image at 0x4761 to EEPROM 0x0112 and sets 0x20F10 = 1 **[fact]** |
| post-power | 0xFFFB1F83 | `shreg_bus_init` | `shreg_bus_init` | Sets the port outputs for the "on" state (P6/PA/PB/…); the counterpart of `power_off_io` 0xFFFB73A6 **[fact for the ports; inference for the pairing]** |
| post-power | 0xFFFB6CDE | `trx_init` | `trx_init` | 0x20B18 = 4, 0x20B6B = 0, starts soft timer 0x13 (2500 ms), sets PB3, builds 0x20F60 from 0x9E82 **[fact]** |
| post-power | 0xFFFA1132 | `sdr_init` | `sdr_init` | Version placeholder `V**-**`, starts timer 0x1F (1000 ms), SDR handshake **[fact for the string/timer]**. See [sdr-link.md](sdr-link.md) |
| post-power | 0xFFF9D06C | `dsp_link_init` | `dsp_link_init` | Same pattern for the DSP (`V**-**`, timer 0x1F 100 ms); sends `i DB00\r` on SCI4 (T12) **[fact]**. See [dsp-link.md](dsp-link.md) |
| post-power | 0xFFFB55B8 | `portctl_init` | `portctl_init` | 0x12042 = 0 **[fact]** |
| post-power | 0xFFFB28D1 | `dac_init_idle` | `dac_init_idle` | DAC output = 0x1FF1C, `R_DA0_Start` (DA control 0x88044) **[fact]** |
| post-power | 0xFFFB98C8 | `keyer_init` | `keyer_init` | Clears 0x20B2F, 0x1215F and 0xA0 bytes at 0x120BC **[fact]** |
| post-power | 0xFFFEC46C | `tuner_init` | `tuner_init` | One `tuner_task` pass, then `FUN_fffec578` **[fact]** |
| post-power | 0xFFFC98AA | `menu_subsys_init` | — | `FUN_fffd405e` + `menu_init` (menu/UI tables) **[fact; role guess]**. See [menu.md](menu.md) |
| post-power | 0xFFFB263D | `screensaver_timer_restart` | — | Starts the screen-saver timer (slow timer 0; was `cat_apo_reset`, see [below](#screen-saver-timer-slow-timer-0)) **[fact]** |

## Main loop

`main_loop` @ 0xFFF94B8B is a `do { … } while (true)` that calls these 16 functions in order and has no other logic
**[fact]**. Every task is non-blocking by design: it checks flags and soft timers and returns **[inference]**. The
exceptions are the power-off path (busy-waits on `sci1_tx_end`) and the EEPROM writes (busy-wait on WIP) **[fact]**.

```mermaid
flowchart TD
  T1["1 wdt_kick"] --> T2["2 io_task"] --> T3["3 sdr_task"] --> T4["4 dsp_link_poll"]
  T4 --> T5["5 rf_ctrl_task"] --> T6["6 beep_task"] --> T7["7 cat_parse"] --> T8["8 ladder_key_task"]
  T8 --> T9["9 scan_task"] --> T10["10 dispreq_e8_task"] --> T11["11 dispreq_e7_task"] --> T12["12 keyer_task"]
  T12 --> T13["13 mode_15de3_task"] --> T14["14 displink_task"] --> T15["15 key_task"] --> T16["16 tuner_task"]
  T16 --> T1
```

| # | Address | Ghidra name | Inferred name | Role | Page |
|---|---|---|---|---|---|
| 1 | 0xFFFB3E6A | `wdt_kick` | `wdt_kick` | Independent-watchdog refresh (IWDTRR 0x88030 ← 0x00, 0xFF) **[fact: code + HWM §33.2.1]**. Also called in the power-off loop | [peripherals.md](peripherals.md) |
| 2 | 0xFFFB6D56 | `io_task` | `io_task` | TX/RX and power supervisor: PB3 vs 0x20B44 with timer 0x2A; screen-saver check (`screensaver_timer_expired` → 0x20B87, [below](#screen-saver-timer-slow-timer-0)); four sub-tasks (`meter_task` ADC/meters, `io_poll` GPIO/TX state machine on 0x20B18, `FUN_fffb8d77`, `FUN_fffb9605`); **supply monitor** `supply_undervolt_check` (if ADC 0x20B08 < 0x7DD: `power_off_io`, save, 0x20B39 = 0x90); **power-off**: when 0x20B30 == 2 it saves the EEPROM (`eeprom_save_opstate`), waits for SCI1 to drain and calls `sw_reset` (software reset) **[fact]** | [tx-protection.md](tx-protection.md), [peripherals.md](peripherals.md) |
| 3 | 0xFFFA11ED | `sdr_task` | `sdr_task` | SCI5 FPGA link: pending `sdr_reg_access` (flag 0x1C8B), `sdr_bridge_mode` (0x1C8D), then ~30 change detectors that push radio state to the FPGA whenever something changes; aborts the pass when a transfer is pending **[fact for the structure]** | [sdr-link.md](sdr-link.md) |
| 4 | 0xFFF9D1B9 | `dsp_link_poll` | `dsp_link_poll` | SCI4 DSP link: pending `dsp_reg_access` (0x1C5E/0x1C5F), a 4-step sequence on timer 0x0B while 0x20B18 is 3 or 8, then ~40 change detectors (DSP register writes) **[fact for the structure]** | [dsp-link.md](dsp-link.md) |
| 5 | 0xFFFB55C2 | `rf_ctrl_task` | `rf_ctrl_task` | Six port-output sub-tasks (`pa_relay_update`, `…56a5`, `…5786`, `…5874`, `…5976`, `…5d68`) on P6/P7/PA/PB, partly region-dependent (`dest_code_get`) **[fact; role guess: relays / band / TX lines]** | [radio-control.md](radio-control.md), [peripherals.md](peripherals.md) |
| 6 | 0xFFFB28E2 | `beep_task` | `beep_task` | Beep / side-tone sequencer: patterns of `tone_set`(freq, ms)` (880 Hz, 1046.5 Hz, …; case 4 uses pitch 0x9C04 × 10 + 300 Hz, the CW pitch from `cat_KP`) on soft timer 0x16 **[fact]**. `tone_set` sets the TPU1 period for 36 samples per cycle and loads a 36-entry table (`tone_play`(0x1FF1C, 36)`); the TPU1 ISR steps through the table at *0x20B00 into the DAC **[fact]** | [peripherals.md](peripherals.md) |
| 7 | 0xFFFA347C | `cat_parse` | — | One CAT command per pass, then `cat_ai_poll` **[fact]** | [cat.md](cat.md) |
| 8 | 0xFFFE3E2A | `ladder_key_task` | `ladder_key_task` | Acts on key code 0x1204C (1..6, 0xF7..0xFA; `remote_keypad_scan` ORs 0xF0 in after the key is held for 100 passes, i.e. a long press **[inference]**), produced by `remote_keypad_scan` from ADC channel 0x20B10 (a 12-level resistor ladder) **[fact for the decode; guess: microphone or remote-keypad keys]** | [ui-keys.md](ui-keys.md) |
| 9 | 0xFFFE587F | `scan_task` | `scan_task` | State machine on 0x18877, gated by 0x20F1C (the flag `cat_SC` reports as "scan on") **[fact; scan inference]** | [radio-control.md](radio-control.md) |
| 10 | 0xFFFE360E | `dispreq_e8_task` | `dispreq_e8_task` | `FUN_fffe376a` acts on the status 1..5 that DISPLAY frame 0xE8 (`displink_rx_E8`) leaves in +0x48C, then `FUN_fffe3615`. E8 is the status of the DISPLAY's audio screens other than the PlayList: the DISPLAY sends E7 when its audio owner flag 0x2080048E is 1 (PlayList recorder/player, `scr_playlist`, `rec_start_stop`) and E8 when it is 2 or 3 (`FUN_201293f8`, `FUN_2012c4a0`) **[fact, both sides]**. The E8 side clears +0x78 and 0x20B2E, the same flags as `key_cancel_check` (key 0x340), so it is most likely **voice-message playback** (`MESSAGE` files) **[inference]**. Status 5 (DISPLAY error, b1 = 0xFF) beeps (`beep_request(3)`) and sets message code 0x10..0x1A in +0xBB from the error code in +0xAC **[fact]** (a pop-up id **[inference]**) (#65) | [display-link.md](display-link.md), [display/peripherals.md](../display/peripherals.md) |
| 11 | 0xFFFE2CD0 | `dispreq_e7_task` | `dispreq_e7_task` | Same for frame 0xE7 (`displink_rx_E7`, status in +0x488): the **PlayList recorder/player** (receive-audio WAV files on the SD card). The DISPLAY sends it from the PlayList code (`FUN_20124744` errors, `FUN_20124848`, `FUN_20124adc` after `wav_delete`, `FUN_20124bc0` after `wav_list_dir`); status 1/2 update the PlayList state +0x3F8..+0x3FE, status 5 is the error case as for E8 **[fact]** (#65) | [display-link.md](display-link.md) |
| 12 | 0xFFFB98E9 | `keyer_task` | `keyer_task` | CW keyer: uses key speed 0x9C03 (also `cat_KS`), 0x20B97 (also `cat_KY`), timer 0x13 **[inference]** | [tx-protection.md](tx-protection.md) |
| 13 | 0xFFFD0582 | `sd_menu_task` | `sd_menu_task` | **SD CARD menu operations.** The `on_enter` callbacks of EXTENSION SETTING / SD CARD start a mode in 0x15DE3: MEM LIST LOAD / MENU LOAD → 1 (`sd_load_start`), MEM LIST SAVE / MENU SAVE → 2 (`sd_save_start`), INFORMATIONS → 3, FORMAT → 4; 0x15DE5 = 1 selects the memory list, 0 the menu settings. While +0x88 (0x20B8C) is set the task runs the mode's step machine (step in +0x3F7), which talks to the DISPLAY with frames 0x43 (command, answered by C3 setting +0x3F6), 0x44 (block read) and 0x45 (block write) of the DISPLAY's 32000-byte buffer. If the SD card goes away (+0xA6 = 0) it stops (`FUN_fffcf4f2`) **[fact]** (#65; payloads: #61) | [display-link.md](display-link.md), [menu.md](menu.md) |
| 14 | 0xFFF94D6F | `displink_task` | `displink_task` | SCI1 DISPLAY link: takes a received frame, validates it (`displink_check_sum`), dispatches by first byte (`displink_rx_dispatch`: 0x06 ACK, 0x15 NAK, 0xB3, 0xC3–0xC5, 0xE0–0xE8, 0xF0, 0xF1…), answers ACK/NAK and sends the next queued frame (`displink_tx_poll`) with retry timers 0x3B/0x3C **[fact]** | [display-link.md](display-link.md) |
| 15 | 0xFFFBBD58 | `key_task` | `key_task` | Key/event dispatcher: a new event (flag 0x20BA4, type 0x20BA1, code 0x20BA2) is latched into 0x1FA40 and is mapped through **five 863-entry key handler tables 0xFFF89D94..0xFFF8E0FF** (`key_call_press`; press … release tables, ending at 0xFFF8E100), with auto-repeat timers 0x3F/0x40; also per-port config refresh (`FUN_fffc4d93`) **[fact]** | [ui-keys.md](ui-keys.md), [menu.md](menu.md) |
| 16 | 0xFFFEC473 | `tuner_task` | `tuner_task` | Antenna tuner: dispatch on tuner-select setting 0x9AB8 (also read by `cat_AC`): 3 → `FUN_fffed165`, 2 → `FUN_fffed62a`, else `FUN_fffec62b` (state machine 0x1B3AC) **[fact; tuner inference]** | [tx-protection.md](tx-protection.md), [peripherals.md](peripherals.md) |

### Power states

```mermaid
stateDiagram-v2
  [*] --> Off: reset (PowerON_Reset)
  Off --> Off: displink_task + cat_parse (PS1 only)
  Off --> On: DISPLAY frame 0xF0 sets 0x20B3A=1
  note right of Off
    PS1 only requests power-on:
    0x20B9C=1, 0x1B3D0=1 (`power_on_request`)
  end note
  On --> On: main_loop
  On --> Saving: power key (code 0x300, event 2) sets 0x20B30=2
  On --> Saving: supply ADC 0x20B08 < 0x7DD
  On --> Saving: CAT PS0 (0x20F4B=1, 0x20B39=0x10)
  Saving --> [*]: EEPROM save, SCI1 drained, software reset
```

- **Power-on is a handshake with DISPLAY.** `cat_PS` with `1` only calls `power_on_request` (0x20B9C = 1, 0x1B3D0 = 1)
  **[fact]**; the flag 0x20B3A is set only in `displink_rx_F0_hello`, the handler of DISPLAY frame 0xF0, which also stores the
  DISPLAY version string (0x1436, `ver_display`) and a power-on reason byte at 0x20B9F **[fact]**. So power-on is triggered
  by the DISPLAY `F0` frame (0x20B3A = global state block +0x36): MAIN asks the DISPLAY CPU and waits for it **[inference]**.
  The request is frame `0x60` (#57): `cat_PS` also sets 0x9DC5 = 1, +0x98 = 1 turns MAIN's link transmitter on (it is silent
  while the radio is off), and 0x1B3D0 = 1 makes the scheduler send `0x60`, whose byte 0xB3 is 0x9DC5. A DISPLAY that is off and
  has already seen one `0x60` switches the radio on when byte 0xB3 = 1 ([system.md](../system.md), item C6) **[fact]**.
  The frame format is in [display-link.md](display-link.md).
- **Power-off ends in a software reset.** `sw_reset` writes PRCR (0x803FE) = 0xA502 and 0x800C2 = 0xA501
  **[fact]**, which is the RX65x software-reset register SWRR **[inference]**. The CPU then restarts in `PowerON_Reset`
  and waits in the power-off loop again **[inference]**. The front-panel power key is key code 0x300 with event type 2
  in `key_event_filter` **[fact for 0x300 → 0x20B30 = 2; inference that it is the power key]**.
- The PS0 path (0x20F4B / 0x20B39 = 0x10) and the low-voltage path (0x20B39 = 0x90) record a reason code. 0x20F4B is read only by
  `displink_tx_schedule` 0xFFF95F58, which calls `power_down_save` 0xFFF98797: `0x7F` frame to the DISPLAY, `eeprom_save_all`
  (for 0x90 a 2 s wait instead), `sw_reset` **[fact, T19h]**. The power-key path is handled in `io_task` and sends no `0x7F`
  ([peripherals.md](peripherals.md#power-on--off)).

## Soft timers and interrupts

### Soft timers **[fact unless marked]**

| Timer set | Storage | API | Tick |
|---|---|---|---|
| 75 one-shot timers, id 0..0x4A | expired flags 0x11FED[id], counters 0x20890[id], limits 0x209BC[id] | `swtimer_start`(id, ms)` `swtimer_start` (limit = ms × 10), `swtimer_expired`(id)` `swtimer_expired` | TPU0 vector 130 ISR → `swtimer_tick` |
| 2 periodic on/off timers | 0x20AE8, 0x20AF0/0x20AF4, state 0x12038 | `blink_set`(id, on_ms, off_ms)` | same ISR (blink cadence, e.g. 450/250 ms) |
| 4 slow timers | flags 0x1203A, counters 0x1FA24, limits 0x1FA2C | `slowtimer_start`(id, s) (limit = s × 10) | TPU3 vector 142 ISR → `slowtimer_tick` |

TPU0 is set up with TCR = 0x2A (PCLK/16, clear on TGRA) and TGRA = 0x176 → (374 + 1) × 16 / 60 MHz = **100 µs**
**[fact; PCLKB = 60 MHz from SCKCR, RX651 HWM §9.2.1]**, which matches `ms × 10` in `swtimer_start`. TPU3
has TGRA = 0x5B8D with TCR = 0x2E; with PCLK/256 that is **100 ms** **[fact: RX651 HWM r01uh0590 §26.2.1 Table 26.7, TPU3 TPSC=110b = PCLK/256]**.
Timer ids seen on this page (the id and its user are **[fact]**, the role words are **[inference]**): 0x0B DSP
sequence, 0x13 power-up settle (2500 ms), 0x16 tone step, 0x1F link init, 0x2A PB3 check, 0x2B/0x3B/0x3C DISPLAY link,
0x2D TPU2 pulse, 0x31 `FUN_fffcdb26` delay (200 ms), 0x32 CAT AI hold-off (200 ms), 0x3F/0x40 event repeat, 0x4A
`displink_task` 100 ms re-check. The decompiler shows the counter compare as `(count & 0xFF) >= limit`; that would
never fire for 200 ms (limit 2000), so it is probably a decompiler artifact **[inference]**.

### Screen-saver timer (slow timer 0)

Slow timer 0 is the **screen-saver** timeout, not an auto-power-off timer (#208). `screensaver_timer_restart`
0xFFFB263D was named `cat_apo_reset` before; the committed decompile in `decomp/main/` shows the old names
(`cat_apo_reset`, `FUN_fffb2604`, `FUN_fffb267f`) until the next Ghidra re-export.

- `slowtimer_start`(id, seconds) 0xFFFB2604: ids 0..3 only; clears counter 0x1FA24[id] and flag 0x1203A[id], sets limit
  0x1FA2C[id] = seconds × 10 **[fact]**. `slowtimer_tick` counts only while the limit is non-zero, so 0 stops the timer **[fact]**.
  At the 100 ms TPU3 tick the argument is in seconds **[inference from the tick; `tot_start` passes minutes × 60, which agrees]**.
  Users: id 0 screen saver, ids 1/2 TX time-out (`tot_start`) **[fact]**.
- `screensaver_timer_restart` 0xFFFB263D: reads 0x9B0F (menu 040104 DISPLAY > SCREEN SAVER, 0..3, clamped to 3) and starts timer 0 with
  0 / 900 / 1800 / 3600 s = **off / 15 / 30 / 60 min** **[fact for the values; minutes from the tick, inference]**.
- `screensaver_timer_expired` 0xFFFB267F returns flag 0x1203A (timer 0). Its only caller is `io_task` 0xFFFB6D56 **[fact]**:
  expired and 0x20B86 (`screensaver_on`, +0x82) clear → 0x20B87 (`screensaver_toggle_req`, +0x83) = 1; not expired and 0x20B86 set
  → 0x20B87 = 1 as well **[fact]**.
- `displink_tx_schedule` 0xFFF95F58 sees +0x83, clears it and calls `displink_tx_7B` 0xFFF9889C, which toggles +0x82 and sends frame
  `0x7B` with b1 = the new value **[fact]**. While +0x82 = 1 the scheduler sends none of the lower-priority frames after it **[fact]**.
  The DISPLAY shows its screen saver for `0x7B` with b1 = 1 ([display/mainlink.md](../display/mainlink.md)) **[inference there]**.
- The DISPLAY answers a key, touch or encoder action with `E4`; `displink_rx_dispatch` 0xFFF95331 then clears +0x82 and, as for every
  frame but 06/15/E3, restarts the timer **[fact]**. `remote_keypad_scan` restarts the timer on a key and drops that key while 0x20B86
  is set **[fact]**.

Callers of `screensaver_timer_restart` (the calling functions are **[fact]** from `decomp/main/`; the call-site addresses come
from the #208 cross-reference list and lie inside each function): `app_main` (call 0xFFF94B83, before `main_loop`),
`displink_rx_dispatch` (0xFFF95416, every received frame but 06/15/E3), `cat_parse` (0xFFFA34B6, every CAT command),
`remote_keypad_scan` (0xFFFB7AEB), `ptt_source_select` (0xFFFB8689, any active PTT source), `FUN_fffbb024` (0xFFFBB02F, keyer element
input, see [eeprom.md](eeprom.md)) and the menu step handler `menu_ex040104_step` (function 0xFFFCF123, when SCREEN SAVER is changed;
already a Ghidra function from the #74 menu entries in `tools/ghidra/entries_main_menu.tsv`). Taken together: the screen saver starts after
the chosen time with no key, knob, touch, PTT, keyer or CAT activity **[inference]**.

### Vector table

The relocatable vector table at INTB = **0xFFF8E6DC** has 256 entries: **31 populated**, the other 225 point to
`Undefined_0xD8` @ 0xFFF90802 **[fact]**. Vectors 128–207 are software-configurable interrupt B (ICU SLIBXR128–143 / SLIBR144–207, set in `icu_select_init`); 208–255 are interrupt A (SLIARn) **[fact: RX651 HWM §15.2.25–15.2.27, Table 15.5]**.

| Vector | Handler | Source | Role |
|---|---|---|---|
| 16 | `vec016_BSC_BUSERR` 0xFFF90819 | bus error | BSP stub **[fact]** |
| 26 / 27 | `vec026_ICU_SWINT2` / `vec027_ICU_SWINT` | software interrupts | → `FUN_fff910c3(1/0)`, BSP software-interrupt task queue at 0x20318 **[fact; FIT naming inference]** |
| 58–63, 80–85 | `r_sci0..5_receive/transmit_interrupt` | SCI0–SCI5 RXI/TXI | UART drivers ([sci.md](sci.md)) **[fact]** |
| 86 / 87 | `r_sci6_iic_rxi` / `r_sci6_iic_txi` | SCI6 (simple I2C) | [peripherals.md](peripherals.md) **[fact]** |
| 98 / 99 | `r_sci7_receive/transmit_interrupt` | SCI7 | configured but never started in V01-12 ([dsp-link.md](dsp-link.md)) **[fact]** |
| 106, 107, 110–113 | `vec106_GROUPBE0`, `vec107_GROUPBL2`, `vec110_GROUPBL0`, `vec111_GROUPBL1`, `vec112_GROUPAL0`, `vec113_GROUPAL1` | group interrupts | SCI TEI/ERI and others, dispatched to the callbacks registered by `R_BSP_InterruptWrite` in `R_Systeminit` **[fact]** |
| 130 | `r_tpu0_tgia_isr` 0xFFF94A57 | source 0x0F = TPU0 TGI0A **[fact: icu_select_init write; RX651 HWM r01uh0590 Table 15.3 p452–453]** | 100 µs soft-timer tick `swtimer_tick` **[fact]** |
| 138 | `r_tpu2_tgia_isr` 0xFFFEDD8C | source 0x18 = TPU2 TGI2A **[fact: icu_select_init write; RX651 HWM r01uh0590 Table 15.3 p452–453]** | `spk_softstart_isr`: pulse train on a port bit chosen by 0x20FCC (P7/P8/PB), stops itself via `R_TPU2_Stop` when timer 0x2D expires **[fact; purpose unknown]** |
| 142 | `r_tpu3_tgia_isr` 0xFFFB27D1 | source 0x1C = TPU3 TGI3A **[fact: icu_select_init write; RX651 HWM r01uh0590 Table 15.3 p452–453]** | 100 ms slow timers `slowtimer_tick` **[fact]** |
| 144 | `r_tpu1_tgia_isr` 0xFFF94AEC | source 0x14 = TPU1 TGI1A **[fact: icu_select_init write; RX651 HWM r01uh0590 Table 15.3 p452–453]** | Tone DAC: next sample of the table at 0x20B00 → DAC 0x88040 (`dac0_write`); TGRA 0x88128 sets the pitch **[fact]** |
| 186 | `r_s12ad0_scan_end_isr` 0xFFF92B01 | source 0x40 = S12ADI (S12AD unit 0) **[fact: icu_select_init write; RX651 HWM r01uh0590 Table 15.3 p452–453]** | Stores ADC0 channels 1,2,3,5,6,7 to 0x20B04..0x20B0E, sets 0x1203E **[fact]** |
| 189 | `r_s12ad1_scan_end_isr` 0xFFF92E0F | source 0x44 = S12ADI1 **[fact: icu_select_init write; RX651 HWM r01uh0590 Table 15.3 p452–453]** | Stores ADC1 channels 8,9,15,17 to 0x20B10..0x20B16, sets 0x1203F **[fact]** |

Fixed vectors (0xFFFFFFD0..FC): `SuperVisorInst`, `AccessExc`, `UndefinedInst`, `FloatingPoint`, `NMI` 0xFFF9061B,
reset `PowerON_Reset`; the remaining slots use `Undefined_0xD8` **[fact]**.

## Memory map summary

Full table: [docs/memory-maps.md](../../memory-maps.md#main-mc-image-ft-710_main_v0112sfl--t05). In short **[fact, T05]**:

| Range | Contents |
|---|---|
| 0x00000000..0x00001403 | user stack (top 0x1004), interrupt stack (top 0x1404) |
| 0x00001404..0x00025E5F | .bss / .data (three DTBL copies); highest used RAM ~0x25E60 of 256 KB |
| 0x00080000..0x000FFFFF | peripheral I/O (SYSTEM, ICU 0x87000, IWDT 0x88030, DA 0x88040, TPU 0x88100, S12AD 0x89000/0x89100, SCI 0x8A000.., ports 0x8C000..) |
| 0x00100000..0x00107FFF | E2 data flash: **not present** on the R5F56514 (512 KB parts have none) **[fact: datasheet Table 1.3, T18]**; nothing references it, and settings live in the SPI EEPROM ([eeprom.md](eeprom.md)) **[fact, T10e]** |
| 0xFFF80000..0xFFF8FFFF | constants: CAT tables (0xFFF805EC), menu strings, **key handler tables 0xFFF89D94..0xFFF8E0FF** (5 × 863, [ui-keys.md](ui-keys.md)), vector table 0xFFF8E6DC, DTBL/BTBL, .data images, CAT switch/reply tables (0xFFF8F014, 0xFFF8F480) |
| 0xFFF8FBDB..0xFFFEE2B7 | code (2252 functions in T05; 2328 after T21; 3161 after #70 added the table-called handlers); 0xFFFEDD9A..0xFFFEE2B7 is CC-RX C library stdio and `malloc`/`free` (#78) |
| 0xFFFFFF00 / 0xFFFFFF80 | version string `V01-12` / fixed vectors |

### Global state block 0x20B04 **[fact]**

Most radio state lives in one RAM block that starts at **0x20B04**. The compiler reaches it through eleven
per-module pointer constants in `.data` (0x25D38, 0x25D4C, 0x25D54, 0x25D58, 0x25D5C, 0x25D60, 0x25D6C, 0x25D70,
0x25D74, 0x25D78, 0x25D7C, all = 0x20B04), so `PTR_DAT_00025d38[0x36]` in the decomp is the same byte as `DAT_00020b3a`.
To find all users of a field, search for both forms. Other pointers there: 0x25D34 → 0x203F4, 0x25D50 → 0x4659
(`cfg105`), 0x25D3C = 7,000,000 (a 7 MHz default frequency) **[fact]**.

| Address | Offset | Meaning |
|---|---|---|
| 0x20B04..0x20B16 | +0x00 | ADC results written by the S12AD ISRs (0x20B08 = AN003 `PA_VDD` supply voltage, stored by `adc0_store` 0xFFFB27FB; 0x20B10 = key ladder) **[fact]** |
| 0x20B18 | +0x14 | TX/RX sequencer state (0..8) **[fact; meaning in tx-protection.md]** |
| 0x20B20..0x20B22 | +0x1C | CAT AI flags per port **[fact]** |
| 0x20B30 | +0x2C | 2 = power-off requested by the power key **[fact]** |
| 0x20B39 | +0x35 | power-off reason (0x10 = CAT PS0, 0x90 = low supply) **[fact]** |
| 0x20B3A | +0x36 | radio on (0 = power-off loop) **[fact]** |
| 0x20B45 | +0x41 | settings defaults were loaded at boot **[fact]** |
| 0x20B46 | +0x42 | CAT disabled (set by DISPLAY) **[fact]** |
| 0x20B6B | +0x67 | RX/TX or VFO selector watched by the SDR and DSP link tasks **[fact for the use; meaning guess]** |
| 0x20B86 | +0x82 | `screensaver_on`: toggled by `displink_tx_7B`, cleared on `E4` ([screen saver](#screen-saver-timer-slow-timer-0)) **[fact]** |
| 0x20B87 | +0x83 | `screensaver_toggle_req`: set by `io_task`, sends `0x7B` **[fact]** |
| 0x20B9C | +0x98 | link transmitter enabled: `displink_tx_poll` sends only while it is 1; set by `PS1` (`power_on_request`) and the `F0` hello **[fact]** (#57) |
| 0x20F1C | +0x418 | scan running (`cat_SC`) **[fact]** |
| 0x20F8C / 0x20F90 | +0x488 / +0x48C | command words from DISPLAY frames 0xE7 / 0xE8 **[fact]** |

## Subsystem index

| Page | Task | Contents |
|---|---|---|
| [cat.md](cat.md) | T09 | CAT receive ring, parser, dispatch, AI broadcaster, all handlers. Command reference [docs/cat-commands.md](../../cat-commands.md) |
| [sci.md](sci.md) | T10b | SCI0–SCI7 driver layer: create/start/stop, ISRs, buffers, baud tables |
| [display-link.md](display-link.md) | T10b | SCI1 protocol to the DISPLAY CPU (frames, ACK/NAK, power-on handshake) |
| [ui-keys.md](ui-keys.md) | T10b | Key/encoder/touch events → radio actions, five 863-entry key handler tables 0xFFF89D94..0xFFF8E0FF |
| [sdr-link.md](sdr-link.md) | T10c | SCI5 FPGA register protocol, SDR_UPDATE/SDR_RESET |
| [dsp-link.md](dsp-link.md) | T10d | SCI4 link to the RT685 IF-DSP (register protocol, `dsp_link_poll` task, ISP bridge); SCI7 configured but unused |
| [eeprom.md](eeprom.md) | T10e | BR25G256 driver, EEPROM map, settings image, defaults and factory reset |
| [menu.md](menu.md) | T10f | EX menu table and engine |
| [radio-control.md](radio-control.md) | T10g | VFO/band/mode, memories, scan, frequency programming |
| [tx-protection.md](tx-protection.md) | T10h | PTT/TX sequencing, protection, keyer, tuner |
| [peripherals.md](peripherals.md) | T10h | ADC channels, DAC/tone, timers, SCI2 tuner port, SCI6 (simple I2C, pins not connected), GPIO map, power on/off |
| [bsp.md](bsp.md) | T23g | BSP around the reset path: exception vectors, ICU group/software-interrupt helpers, CC-RX intrinsics and C library (lowsrc, stdio, heap) |
| [cat-ai.md](cat-ai.md) | T23g | Catalogue of the 296 CAT AI change detectors for the EX menu (table 0xFFF8E1A0) and their formatters |
| [menu-items.md](menu-items.md) | T23g | Catalogue of the 314 `menuitem_*` builders and the 624 `on_draw` / `on_step` / `on_enter` callbacks |

Related: [DISPLAY overview](../display/README.md), [IFDSP overview](../ifdsp/README.md), [SDR overview](../sdr/README.md),
custom-firmware feasibility [docs/custom-firmware.md](../../custom-firmware.md).

## Function table (boot, scheduler, timers, interrupts)

Functions owned by a subsystem page are listed there; this table covers the ones documented on this page.

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFF8FBDB | `PowerON_Reset` | — | Reset entry |
| 0xFFF8F658 | `main` | — | → `app_main` |
| 0xFFF94AFA | `app_main` | — | Init, power-off loop, post-power init, `main_loop` |
| 0xFFF94B8B | `main_loop` | — | 16-task super-loop |
| 0xFFF8F7EC | `hardware_setup` | `hardware_setup` | BSP hardware set-up wrapper |
| 0xFFF8F65E | `R_Systeminit` | `R_Systeminit` | Peripheral create calls + group-interrupt callback registration |
| 0xFFF8FFFB | `R_BSP_InterruptWrite` | `R_BSP_InterruptWrite` | Registers a callback (id, function) **[inference]** |
| 0xFFF90097 | `R_BSP_InterruptControl` | `R_BSP_InterruptControl` | BSP interrupt control / callback call **[inference]** |
| 0xFFF8FF5F | `bsp_callbacks_clear` | `bsp_callbacks_clear` | Clears the callback table 0x1FFC4 |
| 0xFFF8FFC4 | `bsp_interrupt_open` | `bsp_interrupt_open` | Group callback table = FIT_NO_FUNC, ICU source select |
| 0xFFF92014 | `icu_select_init` | `icu_select_init` | SLIBXR128.. source mapping |
| 0xFFF92E49 | `R_Pins_Create` | `R_Pins_Create` | Port PDR/PODR/PMR set-up **[inference]** |
| 0xFFF927A9 | `R_IWDT_Create` | `R_IWDT_Create` | IWDTCR 0x88032 = 0x3350, IWDTRCR = 0 (NMI), IWDTCSTPR = 0x80; timeout ≈2.2 s ([peripherals.md](peripherals.md)) **[fact: HWM §33.2]** |
| 0xFFF927CE | `iwdt_refresh` | `iwdt_refresh` | Refresh 0x88030 |
| 0xFFF927E5 | `R_DA_Create` | `R_DA_Create` | DAC registers 0x88044.. |
| 0xFFF92851 | `R_S12AD0_Create` | `R_S12AD0_Create` | ADC0 (0x89000) and vector 186 |
| 0xFFF92B17 | `R_S12AD1_Create` | `R_S12AD1_Create` | ADC1 (0x89100) and vector 189 |
| 0xFFF949B4 | `R_TPU0_Create` | `R_TPU0_Create` | TCR 0x2A, TGRA 0x176 |
| 0xFFF94A38 | `R_TPU0_Start` | `R_TPU0_Start` | IER bit + TSTR bit 0 |
| 0xFFF94A65 | `R_TPU1_Create` | `R_TPU1_Create` | TCR 0x20, TGRA 0x270 |
| 0xFFF94ACD | `R_TPU1_Start` | `R_TPU1_Start` | TSTR bit 1 |
| 0xFFF94ADC | `R_TPU1_Stop` | `R_TPU1_Stop` | |
| 0xFFFEDD07 | `R_TPU2_Create` | `R_TPU2_Create` | TCR 0x29, TGRA 0x4A |
| 0xFFFEDD7C | `R_TPU2_Stop` | `R_TPU2_Stop` | |
| 0xFFFB2734 | `R_TPU3_Create` | `R_TPU3_Create` | TCR 0x2E, TGRA 0x5B8D |
| 0xFFFB27B2 | `R_TPU3_Start` | `R_TPU3_Start` | TSTR bit 3 |
| 0xFFFB3E6A | `wdt_kick` | `wdt_kick` | Task 1 |
| 0xFFFB3E55 | `sw_reset` | `sw_reset` | PRCR + SWRR = 0xA501 |
| 0xFFFB2228 | `timers_init` | `timers_init` | Soft timers, TPU0/TPU3 start |
| 0xFFFB2288 | `swtimer_tick` | `swtimer_tick` | 100 µs tick body |
| 0xFFFB237A | `swtimer_start` | `swtimer_start` | (id, ms) |
| 0xFFFB23F3 | `swtimer_expired` | `swtimer_expired` | (id) → flag |
| 0xFFFB2419 | `blink_set` | `blink_set` | (id, on_ms, off_ms) |
| 0xFFFB259C | `slowtimer_tick` | `slowtimer_tick` | 100 ms tick body |
| 0xFFFB2604 | `slowtimer_start` (decompile: `FUN_fffb2604`) | `slowtimer_start` | (id 0..3, seconds) |
| 0xFFFB263D | `screensaver_timer_restart` (decompile: `cat_apo_reset`) | `screensaver_timer_restart` | slow timer 0 from 0x9B0F |
| 0xFFFB267F | `screensaver_timer_expired` (decompile: `FUN_fffb267f`) | `screensaver_timer_expired` | → flag 0x1203A |
| 0xFFFB2469 | `tone_sample_isr` | `tone_sample_isr` | TPU1 ISR body |
| 0xFFF9283D | `dac0_write` | `dac0_write` | DADR0 0x88040 = value & 0xFFF |
| 0xFFFB27FB | `adc0_store` | `adc0_store` | ADC0 ISR body |
| 0xFFFB2858 | `adc1_store` | `adc1_store` | ADC1 ISR body |
| 0xFFFB0229 | `eeprom_load_all` | `eeprom_load_all` | Boot settings load |
| 0xFFFB02AF | `eeprom_save_all` | `eeprom_save_all` | First-boot full save |
| 0xFFFB02CF | `eeprom_save_opstate` | `eeprom_save_opstate` | Power-off save (0x9A2A 0x45C B → EEPROM 0x53DB; 0x60B1 0x18 B → 0x1A62) |
| 0xFFFB01F3 | `eeprom_init` | `eeprom_init` | EEPROM status register write |
| 0xFFFB1632 | `sci_start_all` | `sci_start_all` | UART start-up |
| 0xFFF94CAB | `qmb_boot_init` | `qmb_boot_init` | State block init |
| 0xFFFB1F83 | `shreg_bus_init` | `shreg_bus_init` | GPIO "on" state |
| 0xFFFB6CDE / 0xFFFB6D56 | `trx_init` / `io_task` | `trx_init` / `io_task` | Task 2 |
| 0xFFFB4B28 | `supply_undervolt_check` | `supply_undervolt_check` | Low-voltage shutdown |
| 0xFFFA1132 / 0xFFFA11ED | `sdr_init` / `sdr_task` | `sdr_init` / `sdr_task` | Task 3 |
| 0xFFF9D06C / 0xFFF9D1B9 | `dsp_link_init` / `dsp_link_poll` | `dsp_link_init` / `dsp_link_poll` | Task 4 |
| 0xFFFB55B8 / 0xFFFB55C2 | `portctl_init` / `rf_ctrl_task` | `portctl_init` / `rf_ctrl_task` | Task 5 |
| 0xFFFB28D1 / 0xFFFB28E2 | `dac_init_idle` / `beep_task` | `dac_init_idle` / `beep_task` | Task 6 |
| 0xFFFB2E1E | `tone_set` | `tone_set` | (freq Hz, ms); 30..20000 Hz, TPU1 TGRA = 60e6/(36 f) − 1 |
| 0xFFFE3E2A | `ladder_key_task` | `ladder_key_task` | Task 8 |
| 0xFFFB7A40 | `remote_keypad_scan` | `remote_keypad_scan` | ADC 0x20B10 → key code 0x1204C |
| 0xFFFE587F | `scan_task` | `scan_task` | Task 9 |
| 0xFFFE360E | `dispreq_e8_task` | `dispreq_e8_task` | Task 10 |
| 0xFFFE2CD0 | `dispreq_e7_task` | `dispreq_e7_task` | Task 11 |
| 0xFFFB98C8 / 0xFFFB98E9 | `keyer_init` / `keyer_task` | `keyer_init` / `keyer_task` | Task 12 |
| 0xFFFD0582 | `sd_menu_task` | `sd_menu_task` | Task 13 |
| 0xFFF94D6F | `displink_task` | `displink_task` | Task 14 |
| 0xFFF95331 | `displink_rx_dispatch` | `displink_rx_dispatch` | DISPLAY frame dispatch by first byte |
| 0xFFF9546A | `displink_rx_F0_hello` | `displink_rx_F0_hello` | Frame 0xF0: DISPLAY version, radio on |
| 0xFFF9CB8E | `power_on_request` | `power_on_request` | `PS1` path |
| 0xFFFBBD58 | `key_task` | `key_task` | Task 15 |
| 0xFFFBC35F | `key_call_press` | `key_call_press` | Table 0xFFF89D94[event] |
| 0xFFFEC46C / 0xFFFEC473 | `tuner_init` / `tuner_task` | `tuner_init` / `tuner_task` | Task 16 |
| 0xFFFB24D8 | `spk_softstart_isr` | `spk_softstart_isr` | Vector 138 body |

## Open questions

- Tasks 10, 11 and 13 (answered, #65): E8/E7 audio status from the DISPLAY and the SD CARD menu operations. Open: the 0x43/0x44/0x45 payloads (#61).
- The role of TPU2 (5 µs period with PCLK/4, port pulse train on vector 138) is unknown.
- The power-on handshake frames should be cross-checked against the DISPLAY side (T11b `mainlink_*`).
- SCI4 vs SCI7 for the DSP: the code talks to the DSP console on SCI4; what SCI7 ("C4") carries is open (T10d).
