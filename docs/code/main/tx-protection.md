# MAIN — PTT, TX sequencing, protection, meters and TX coverage

Back to the [MAIN overview](README.md).

This page covers T10h: how MAIN decides to transmit and how it switches the hardware between RX and TX. It also covers what can
inhibit TX, how the meters are computed, and how the destination code limits TX frequencies. Pins and peripherals are on
[peripherals.md](peripherals.md). Function names are the current Ghidra names. Function names are the names applied in Ghidra (`tools/ghidra/names_main.tsv`, merged by T17) and match `decomp/main/`; a name still in *italics* is a description that was not applied as a Ghidra name. The tags follow AGENTS.md.

> Decompiler caveat: the RX SLEIGH module decodes `MOVU.B/W Rs,Rd` as a memory load (found in T10e). Odd low-address reads in the
> decompile (for example `*(byte *)(0x465B - 0x9AC6)` in `main_dac_update`, or the TX→RX timer table in `trx_sequencer`) are
> probably this bug. They are marked **[decoder?]** below.

## Overview

```mermaid
flowchart TD
  IN["ptt_inputs_read<br/>DATA_PTT P20, RTS PC6, DTR PC5,<br/>EXTPA_TXREQ P15, VOX (DSP)"] --> SEL
  CAT["cat_TX: TX1 → 0x20B28<br/>(no key_event_filter)"] --> SEL
  OTH["other sources 0x20B2A..2E<br/>(DISPLAY link, tuner, PB, ...)"] --> SEL
  SEL["ptt_source_select<br/>→ 0x1204D"] --> ARB
  ALLOW["tx_freq_allowed(freq)<br/>dest-code tables + inhibit flags"] --> ARB
  ARB["ptt_arbiter<br/>TXINH, debounce, hang time"] -->|"trx_state 0 / 4"| SEQ
  SEQ["trx_sequencer<br/>0x20B18: 0..8"] --> HW["DATA_BUSY, AF_MUTE, speakers,<br/>RX PB7, TX P73, SEND_A/B"]
  SEQ --> KEY["pc_keying<br/>(CW from DAKY/RTS/DTR)"]
  MT["meter_task (5/10 ms)<br/>ADC scan"] --> SWR["swr_meter_protect<br/>→ 0x20B6D HI-SWR"]
  MT --> MET["meters 0x12043..0x1204A"]
  MET --> RM["CAT RM / SM / SPM"]
  RF["rf_ctrl_task"] --> SR["shift regs + BU2505 DACs<br/>(PA, BPF, ATU, fan)"]
```

`main_loop` → `io_task` → `meter_task` plus `io_poll`. `io_poll` does nothing until soft timer 0x13 has run out, which
is 2.5 s after power-on (`trx_init`). Each pass it then runs `ptt_inputs_read`, `trx_sequencer` (which calls `ptt_arbiter` first),
`tx_audio_select`, `speaker_route`, `af_mute_update`, `linear_band_data` and `FUN_fffb915e` (PC-keying in RTTY) **[fact]**.
`main_loop` → `rf_ctrl_task` writes the PA/RF registers.

## PTT sources [fact]

`ptt_inputs_read` (0xFFFB7F6F) samples the ports into one flag per source. `ptt_source_select` (0xFFFB85A2) then picks the first active flag in
priority order and returns its number. The result is stored in `ptt_source` 0x1204D. If 0x20B97 is set, every source is ignored. 0x20B97 is UI-state +0x93: set by `FUN_fffe2fa8` (started from the remote keypad,
`ladder_key_task`, and the assignable slots 0xD/0xE), cleared by `cat_ext_EO`, `key_mode_short` (`FUN_fffbf6c8`) and the E7 error path. It is the
PlayList playback flag of `dispreq_e7_task`, so the radio cannot transmit while a recorded receive file plays **[fact for the writers, inference for
"playback"]** (#75).

| Priority | Flag | Source no. | Origin |
|---|---|---|---|
| 1 | 0x20B28 | **5** | **CAT `TX1;`**. `cat_TX` sets it, and `TX0;` clears it |
| 2 | 0x20B25 | 2 | `EXTPA_TXREQ` (P15) low |
| 3 | 0x20B24 | 1 | `DATA_PTT` (P20) low, when PTT select = 3 (DAKY) |
| 4 | 0x20B26 | 3 | USB "Standard" port **RTS** (PC6) low and USB_DET, when select = 1 |
| 5 | 0x20B27 | 4 | USB **DTR** (PC5) low and USB_DET, when select = 2 |
| 6 | 0x20B2A (UI +0x26) | 7 | **CW keyer**: `keyer_task` → `FUN_fffbaa81` sets it while it keys (break-in) and clears it **[fact]** (#75) |
| 7 | 0x20B2B (UI +0x27) | 8 | **MIC PTT**: DISPLAY key code 0x340 (P10_5 on the DISPLAY, [display/input.md](../display/input.md)). Its press handler `FUN_fffc0210` sets it, and `key_cancel_check` clears it on release **[fact]** (#75) |
| 8 | 0x20B2C (UI +0x28) | 9 | **MOX**: holding MOX/VOX (`key_mox_vox_long`, 0x1B4D9 = 2) sets it, and the next press clears it. A short press toggles VOX (0x9C5D), except in modes 2, 3, 0xC and 0xD **[fact]** (#75) |
| 9 | 0x20B2D (UI +0x29) | 10 | **ATU tune**: the tuner code (`FUN_fffec7f9`, `FUN_fffed48f`, `FUN_fffed8ab` set it; the 0xFFFECE.. / 0xFFFED... tuner steps clear it) **[fact]** (#75) |
| 10 | 0x20B2E (UI +0x2A) | 11 | **voice-message playback on the air**: `cat_PB` and the message-play code (`FUN_fffe4211`) set it; the E8 status (`FUN_fffe376a`, [README.md](README.md) task 10) and the MIC PTT release clear it **[fact]** (#75) |
| 11 | 0x20B29 | 6 | **VOX**: setting 0x9C5D on, DSP status bit 0x10 (`dsp_status1_raw`), and VOX holdoff timer 0x2F expired |

- The "PTT select" value is setting 0x9A9F, or a per-mode value from `FUN_fffb50d7`. The code values 1 = RTS, 2 = DTR and 3 = DAKY match the CAT
  manual's `PC KEYING 0 OFF 1 RTS 2 DTR 3 DAKY` **[fact]**.
- Any active source restarts the screen-saver timer (`screensaver_timer_restart` 0xFFFB263D; it was named `cat_apo_reset`, and the committed decompile in `decomp/main/` shows that old name until the next Ghidra re-export, #208). Any source except VOX arms timer 0x2F for 200 ms, which keeps VOX from
  re-triggering **[fact]**.
- 0x12050 (`pc_keying_active`) is 1 when the source is DAKY, RTS, DTR, 8 or 9 and the mode group (`FUN_fffba192`) is CW (1 or 3). The
  line is then a CW key, not a PTT, and `pc_keying` keys SEND and plays a sidetone **[fact for the logic, inference for the naming]**.

### The CAT TX1 path bypasses the key-event filter [fact]

`cat_TX` (0xFFFAF7B8) does not call `key_event_filter` (unlike `cat_KY`, `cat_VS` and others; see [cat.md](cat.md)). It writes the request flag 0x20B28
directly. It refuses (`?;`) only while 0x20F1C == 1 or 0x20F70 == 1. 0x20F1C is UI-state +0x418, **scan running** (`scan_start_up`/`scan_start_down`,
cleared by `scan_stop`). 0x20F70 is +0x46C, set with a mode-dependent timer (0x38/0x40) by the long/repeat handlers of slots 0xD/0xE and the
remote-keypad path, and cleared when the timer runs out **[fact]**; its purpose is not traced (#75). The read form `TX;` answers from `ptt_source_get`: `TX0` when no
source is active, `TX1` when the source is CAT, and `TX2` for any other source. The **only** gates between `TX1;` and the RF are therefore
`ptt_arbiter` and `tx_freq_allowed` (below). This is why CAT TX also works in UI states where front-panel keys are locked.

## TX allow / inhibit (`ptt_arbiter` 0xFFFB86E8, `tx_freq_allowed` 0xFFFB37FE) [fact]

*tx_freq_allowed(freq)* is called with the TX frequency 0x20F50:
1. If `zz_mode0` (0x20BBE, set by `ZZPE071000`) is set, it returns **1 at once, with no band check**.
2. It returns 0 if any of these is set: 0x465C (`cfg105[3]`), 0x9AF5 (**TX INHIBIT**, menu OPERATION SETTING / TX GENERAL, `EX030407`, #75), 0x20B46 (`cat_disabled`,
   set from the DISPLAY link), 0x20B47 (TX time-out tripped, see below).
3. It looks up the range table for the destination code (`dest_code_get`, 0x475E/0x475F). It returns 1 if `lo <= freq < hi` for
   some row ([table below](#destination-code-and-tx-coverage)).
4. If tuning (0x20B8C) or 0x20B9E is active, it clears all PTT request flags.

`ptt_arbiter`:
- **TX refused:** TXINH (PA1) = 1. If the radio was transmitting (0x20B6B), it starts TX→RX (trx_state = 4).
- **TX allowed:** TXINH follows `ETUN_TXINH_REQ` (P14), so an external tuner can still inhibit TX.
- **PTT on:** a source must be seen on 2 consecutive passes before trx_state = 0 (start TX). It also sets `tx_active` 0x20B6B and starts the
  TX time-out timer (`tot_start`: setting 0x9AC3 in minutes; 0 = off).
- **While TX:** if the TOT has expired (`tot_expired`), 0x20B47 = 1, which inhibits TX until PTT is released. A pre-warning
  (`tot_prewarn`) gives beep pattern 7.
- **PTT off:** source-dependent hang. VOX (source 6) waits for timer 0x15 (delay from the ROM table 0xFFF8833C, indexed by 0x9BF4 or 0x9BF5).
  CAT, EXTPA and DATA sources in CW-type modes wait for the break-in delay timer 0x1A (`FUN_fffba35c`, unless 0x9AA0). The arbiter then
  sets trx_state = 4.

## RX↔TX sequencer (`trx_sequencer` 0xFFFB80F9, `trx_state` 0x20B18) [fact]

```mermaid
stateDiagram-v2
  [*] --> S4: trx_init (boot)
  S8: 8 RX
  S8 --> S0: (arbiter: PTT)
  S0: 0 PTT seen
  S0 --> S1: tx_freq_allowed → start timers 0xC..0x11
  S1: 1 switching to TX
  S1 --> S2: speaker off, acks 0x20B19 & 0x20B1A
  S2: 2 TX delay
  S2 --> S3: timer 0x11 (TX delay) → 0x12051=1
  S3: 3 TX (SEND_A/B follow ETUN_TXINH_REQ)
  S3 --> S4: (arbiter: release / refused)
  S4: 4 release
  S4 --> S5
  S5: 5 SEND off, start TX→RX timers
  S5 --> S6
  S6: 6 wait timer 0x12 and 0x20B49
  S6 --> S7: AF_MUTE on
  S7: 7 switching to RX
  S7 --> S8: timer 0xD
```

RX→TX (state 1). The ms values are soft-timer settings started in state 0:

| Step | Timer | Action |
|---|---|---|
| 1 ms | 0x0C | `DATA_BUSY` (P24) = 1 |
| 1 ms | 0x0D | AF_MUTE on (*af_mute_set(1)*) |
| 5 ms | 0x0E | speaker switches P70/PB2/P80 off (except in CW-type modes 1/3). Once both acknowledgements are set (0x20B19 by `sdr_task`, 0x20B1A by `dsp_link_poll` **[fact]**, #75), the speaker route is restored (unless EAR_DET), AF_MUTE is released and the state goes to 2 |
| 1 ms | 0x0F | **RX (PB7) = 0** → the RX8 rail turns off |
| 3 ms | 0x10 | **TX (P73) = 1** → the TX8 rail turns on |
| *tx delay* | 0x11 | value from `FUN_fffb548a` (forced to 0 for source 7, and for 8/9 with the CW key inserted outside CW). Then state 3, and SEND_A (PA2) / SEND_B (PB4) are keyed |

SEND keying (`send_a_set`/`send_b_set`) is forced low whenever `ETUN_TXINH_REQ` (P14) is high or the TX line (P73) is low. SEND
therefore never leads TX **[fact]**. While the internal tuner relays switch (`atu_relay_update`), SEND is dropped for 15 ms (timer 0x30).

TX→RX (states 5..7) runs in the reverse order: SEND off, then AF_MUTE, then TX = 0 (timer 0x10), RX = 1 (timer 0x0F), DATA_BUSY = 0 (0x0C),
speakers back (0x0E), and AF_MUTE released (0x0D). The delays are computed, not read from a table (#205): with *d* = 2·(setting 0x9AA1,
CW WAVE SHAPE, `EX020117`, #74) + 4 ms, state 5 starts timer 0x12 = *d*, 0x0C = *d* + 6, **0x0D = *d* + 0x20B4A**, 0x0E = *d* + 5,
0x0F = *d* + 4 and 0x10 = *d* + 3 **[fact: `trx_sequencer` 0xFFFB80F9]**. 0x20B4A comes from `sdr_upd_r16_filter` (21..84 ms by mode and
filter width, +10 with AESS on; [sdr-link.md](sdr-link.md)), so the audio comes back last, and later for narrow CW filters.

Other TX-related outputs:
- `tx_audio_select` (0xFFFB8A02) sets `TX_SEL_A/B` (P81/P82) from `FUN_fffb3d11(mode)` (0..3). It is forced to 3 in modes 2/3 (CW) and 12/13
  (RTTY) **[fact]**. It drives the SN74LV4052 TX-source mux Q2615 (p20): 0 → front MIC (`1Y0`), 1 → USB (`1Y2`, `USB_AF_MOD` from the
  CM119B), 2 → rear DATA (`1Y1`), 3 → `1Y3` (tone/radio) **[fact: code + schematic, #63]**; see [hardware.md](../../hardware.md#usb--cat-path-main-af-sheet-p20).
- `FSK_SHIFT` (PC4) goes to the SDR module. `FUN_fffb915e` handles RTTY keying from DAKY/RTS/DTR **[inference]**.

## Protection [fact unless tagged]

| Protection | Input | Where | Action |
|---|---|---|---|
| **High SWR** | AN001 `MCUP_RVS`, AN002 `MCUP_FOR` | `swr_meter_protect` 0xFFFB7545, every 5 ms | SWR = (1+ρ)/(1−ρ), ρ = REV/FWD. While transmitting, an SWR outside [1, 5) for 9 consecutive samples sets **0x20B6D** to 1 or 2 (it alternates with the 1 s blink timer). 9 good samples clear it. If REV or FWD ≤ 10 counts or ρ ≥ 1, the meter is pinned (255 if 0x20B41 == 2, else 1) and the flag is cleared. 0x20B6D is read by `cat_RI` and by the AI detector `FUN_fffe057b`. It does **not** drop TX in MAIN. **[inference]** the power fold-back is done by the display/DSP side, or through the ALC |
| **TX inhibit line** | `ETUN_TXINH_REQ` P14 | `ptt_arbiter`, `send_a_set` | TXINH = 1, SEND off |
| **Band / region** | TX frequency | `tx_freq_allowed` | TX refused, TXINH = 1 |
| **TX time-out** | setting 0x9AC3 | *tot_start/expired/prewarn* | 0x20B47 = 1 → TX refused until PTT is released; pre-warning beep |
| **Supply under-voltage** | AN003 `PA_VDD` < 0x7DD | `supply_undervolt_check` 0xFFFB4B28 | `power_off_io`, save settings, shutdown request (0x20B39 = 0x90) |
| **PA temperature / fan** | AN109 `PA_HF_TH` | `pa_dac_update` 0xFFFB5976 | PA DAC channel 6 = 0xAD×4 while the reading is below calibration 0x465A (hot, NTC), 0 above 0x465A+10, unchanged in between (hysteresis). That this channel drives the **fan** is **[inference]** |
| PA "VU" thermistor | AN006 `PA_VU_TH` | – | converted, but no code reads it **[fact]** |
| Current | AN007 `PA_IDD` | `meter_idd` | meter only. No trip threshold was found in MAIN |
| ALC | AN005 `ALCM` | `meter_alc` | meter only. The ALC loop is analog/DSP **[inference]** |

## Meters [fact]

`meter_task` (0xFFFB73DD): timer 0x09 (5 ms) runs the ADC scan and the SWR meter. Timer 0x0A (10 ms) runs VDD, IDD, ALC, PO, COMP, S and the remote keypad.
The raw 12-bit values are shifted right by 4, scaled with factory calibration bytes from the `cfg105` block (RAM 0x4659, EEPROM 0x000A,
CAT `SPN`), clamped to 0..255 and smoothed (`FUN_fffb92e7`, `FUN_fffb9350`, … **[inference: peak hold / smoothing]**).

| Meter byte | Getter | Source | Calibration | CAT RM index |
|---|---|---|---|---|
| 0x1204A S | `meter_get_s` | DSP level (`dsp_signal_level`) vs 0x4681, piecewise table 0xFFF88BFC ([decoded](eeprom.md#cfg105-the-alignment-table-fact), #205). 0 while 0x20B3D (TX) | 0x4681 | RM1, SM0 |
| 0x12049 COMP | `meter_get_comp` | DSP value (`dsp_comp_level`), 3-segment line | – | RM3 |
| 0x12045 ALC | `meter_get_alc` | AN005 | 0x474E | RM4 |
| 0x12048 / 0x1204B PO | `meter_get_po` (0x1204B if 0x9AF6) | AN002 squared-law fit; full scale 50 (band 10) or 100 W; table 0xFFF88C74 ([decoded](eeprom.md#cfg105-the-alignment-table-fact), #205) | 0x20B1E | RM5 |
| 0x12046 SWR (0x12047 raw) | `meter_get_swr` | SWR; points SWR 1.5/2.0/3.0 → 0x4669/0x466A/0x466B | 0x4669..0x466B | RM6 |
| 0x12044 IDD | `meter_get_idd` | AN007 | 0x475D | RM7 |
| 0x12043 VDD | `meter_get_vdd` | AN003 × (0x4659/192)·(0.0718/(13.8/0x4667)) | 0x4659, 0x4667 | RM8 |
| 0x1204C | `remote_key_get` | AN108 ladder → FH-2 key 1..12 (0xF0 bit = long press after 100 passes) | table 0xFFF815AB | – |

- **`RM`** (`cat_RM` 0xFFFADB7D): `RMn;` answers `RMn` + 3 decimal digits + `000;`. `RM0` picks the meter that the panel shows: in TX
  (0x20B3D = 1) it follows setting 0x9C5B (1 COMP, 2 ALC, 3 VDD, 4 ID, 5 SWR, else PO), and in RX it is S. In RX only RM1 and RM8 return
  values (the others read 0). In TX, RM1 reads 0. RM2 and any other index give `?;`.
- **`SM0`** (`cat_SM`) returns the S byte. **`SPM`** (`cat_SP_meters`) returns S, 0, PO, SWR, COMP, ALC, VDD, IDD as binary bytes (see the
  checksum caveat in [cat.md](cat.md)).

## Destination code and TX coverage

The destination code is the 16-bit word at 0x475E:0x475F (EEPROM 0x010F; CAT `JP`). It selects the TX range table in `tx_freq_allowed`.
Codes not listed get **no** rows, so they never transmit (except in `zz_mode0`) **[fact]**. The rows are `[lo, hi)` in Hz, decoded from ROM:

| Code(s) | Table | Rows | TX ranges (kHz) | Region **[inference]** |
|---|---|---|---|---|
| 0x315B | 0xFFF888A4 | 21 | 1800–2000, 3500–4000, 7000–7300, 10100–10150, 14000–14350, 18068–18168, 21000–21450, 24890–24990, 28000–29700, 50000–54000, plus 11 one-hertz channel rows (f to f+1) 5167.5, 5332, 5348, 5358.5, 5373, 5405, 5330.5, 5346.5, 5357, 5371.5, 5403.5 | USA (60 m channels) |
| 0xA983 | 0xFFF889B4 | 11 | 1800–2000, 3500–3800, **5351.5–5366.5**, 7000–7200, 10100–10150, 14000–14350, 18068–18168, 21000–21450, 24890–24990, 28000–29700, 50000–52000 | Europe |
| 0xD950 | 0xFFF88A0C | 12 | as Europe but **5250–5406.5** and **70000–70500** | UK |
| 0x4380, 0x60E6, 0x020B | 0xFFF8884C | 11 | US-style 1.8–54 MHz ham bands without 60 m, plus a one-hertz row at 4630 | ? |
| 0x7753, 0xD32D | 0xFFF88964 | 10 | US-style ham bands, no 60 m | general / Asia |
| 0x306F, 0x50E2, 0x9CF7, 0xA4C5, 0xB5A7 | 0xFFF8894C | 3 | **1800–30000, 50000–54000, 70000–70500** | "wide" (TX-expanded) |
| 0x1CB9 | 0xFFF88A6C | 1 | **30–75000** (all frequencies) | fully open (service?) |

**One-hertz rows [fact].** The 60 m channel rows of 0x315B and the 4630 kHz row of 0x4380/0x60E6/0x020B end one hertz above
their start, for example `5332000–5332001` (ROM 0xFFF888A4, little-endian u32 pairs). The compare at 0xFFFB3950..0xFFFB395C is
`BGTU` (lo > f → no) followed by `BGEU` (f ≥ hi → no), so such a row matches exactly its channel frequency and nothing else. An earlier
version of this page read these rows as lo == hi and concluded that US 60 m TX could never be allowed; that was wrong.

**The 60 m memory condition [fact].** For 0x315B, a match in rows ≥ 10 (the eleven 60 m rows; the test is `9 < row`) is then
accepted only if the **TX side** is in memory mode (state 2 in 0x9DBE/0x9DBF) on a channel 0x75..0x84 (501–515 and EMG, from
0x60C9/0x60CA). The side is chosen by `FUN_fffb32aa(1)`, which uses the split flag 0x9C5E like `vfo_rec_ptr(1)`. So, as V01-12
stands, **US 60 m TX works on the eleven exact channel frequencies, from the 60 m memories only, not from the VFO** **[fact from
code; not tested on air]**. Whether the "locked memory" states 7/8 also pass the `== 2` test is open.

**Split [fact].** `tx_freq_allowed` is called with the TX frequency 0x20F50, which `freq_cache_update` takes from the TX record:
the other VFO while split is on. So split TX is checked like any other TX. For a range row (all bands, and the Europe 5351.5–5366.5
segment) split works from the VFO. For the US 60 m rows, the TX side (VFO-B in A/B split) must itself be on a 60 m memory.
(Open: `split_toggle` leaves memory/QMB mode on entry ([radio-control.md](radio-control.md#split-clarifier-ab)), so US 60 m
split may not be reachable at all; to check in the disassembly.)

**Clarifier: RIT and XIT [fact].** The checked frequency 0x20F50 is `tx_freq_repeater_shift(vfo_freq_clar(1, 2))`: the TX
side's dial frequency plus its **TX clarifier (XIT)** offset when the TX clarifier is on, plus the FM repeater shift. The **RX
clarifier (RIT) is not in it**, so RIT never affects whether TX is allowed. Consequences:
- **US 60 m channel rows:** any non-zero XIT moves the carrier off the `[f, f+1)` row, so TX is refused. XIT on with a 0 Hz
  offset still passes. This keeps the channels exact, as the rules require. Recalling a memory clears both clarifier flags
  (record +0x01 `&= 0xE7`), and so does a band change (`band_select` clears 0x20F29/0x20F2A).
- **Range rows** (every band, the Europe segment, the planned US segment): XIT is allowed as long as dial + XIT stays inside
  the row; XIT cannot carry the checked carrier past an edge. The check is on the carrier only, not the occupied bandwidth,
  and before the PSK and CW-in-SSB offsets that `sdr_upd_r08_tx_freq` adds to the FPGA TX frequency, so the emission can
  reach a few kHz beyond the checked value (see #103 for the US segment edge).
- **Split:** XIT comes from the TX VFO (its offset and its 0x20F29/0x20F2A bit), like the TX frequency.
- **When it is checked:** the call sites in `FUN_fffb8d77` and `FUN_fffbaa81` skip the check while transmitting (0x20B6B = 1),
  so it runs when TX starts **[fact for those sites]**. Whether any path re-checks during TX, so that tuning or changing XIT
  while transmitting is caught, is open.

**2026 US rules.** Since 13 February 2026 the US has a 5351.5–5366.5 kHz segment (9.15 W ERP) and four 100 W channels (5332, 5348,
5373, 5405 kHz). V01-12 predates this: with 0x315B the segment cannot be used from the VFO, and the old 5357.0/5358.5 channels now
fall inside the segment. Issue [FT-710_Custom_Firmware#2](https://github.com/Reid-n0rc/FT-710_Custom_Firmware/issues/2) (formerly #103) plans a MAIN patch. A segment row added
to the US table must not fall at index ≥ 10 unless the `9 < row` memory test is changed with it: inserting it before row 10 would push
the 6 m row to index 10 and put 6 m under the memory condition.

**The tested radio** answers `JP0710;` with code **0x50E2** (2026-10-28) **[fact, radio]**: the wide table (1.8–30, 50–54,
70–70.5 MHz), the strap partner of the US code 0x315B. The 60 m channel rules above do not apply to it: its table covers the whole
of 60 m as one range, from the VFO and in split. Its EEPROM header stamp (2023-06-26 08:56) dates the last `JP` set, and `JP`
cannot store 0x50E2 (it remaps it to 0x315B), so the wide code most likely came from the strap swap below on a later reset
**[inference]**.

### The JP_P51 strap toggles restricted ↔ wide (`dest_jumper_apply` 0xFFFB3BA6) [fact]

| P51 low (strap fitted **[inference]**) | P51 high |
|---|---|
| 0x315B → 0x50E2 | 0x50E2 → 0x315B |
| 0xA983 → 0xB5A7 | 0xB5A7 → 0xA983 |
| 0xD950 → 0xA4C5 | 0xA4C5 → 0xD950 |
| 0xD32D → 0x306F | 0x306F → 0xD32D |
| 0x7753 → 0x9CF7 | 0x9CF7 → 0x7753 |

`dest_code_set` writes EEPROM, reloads defaults and requests a restart. `dest_jumper_apply` runs only from the DISPLAY-link power-up handler
`displink_rx_F0_hello`, and only when the start-mode byte (message +7) is **1** (reset: `settings_defaults(0)` first) or **7**. Mode 7 first swaps
Europe and UK (0xA983/0xB5A7 → 0xD950, 0xD950/0xA4C5 → 0xA983). These start modes come from power-on key combinations on the DISPLAY
side **[inference]**. P52..P54 are never read. So the classic "TX expansion" works by fitting the P51 strap and doing a reset. The wide
tables still exclude 30–50 MHz and 54–70 MHz, except under 0x1CB9 **[inference for the procedure]**.

## PA and RF control registers

`rf_ctrl_task` (0xFFFB55C2, main loop) rewrites a register only when its value changes. Flag 0x12042 forces a full write on the first pass.
The bus is `SDAT0` PA4 / `SCLK0` PA5 with one strobe per device **[fact for the bit-banging; inference for the device roles]**:

| Function | Strobe | Format | Contents |
|---|---|---|---|
| `bu2505_write`(0, ch, v) | SST1 P66 (high pulse) | 4-bit ch + 10-bit value, LSB first | Q1005 BU2505FV on MAIN. ch3 = **FADJ** (reference-oscillator trim, schematic A3 → `FADJ`) from cal 0x465B plus a user offset **[decoder?]**; ch5 from cal 0x466F..0x4673 by RX band (`main_dac_update`) |
| `bu2505_write`(4, ch, v) | SST5 PB6 | same | PA-unit BU2505FV Q4041 (`pa_dac_update`): ch1/ch10 per-band cal 0x4743../0x4693.., ch2 drive level (`FUN_fffb667a`(band, power): the `FALC` alignment items interpolated between 100/50/20/10/5 W, × table 0xFFF88A68), ch3..5 cal 0x468A..0x4692 by band group, **ch6 fan**, ch7 from 0x20B3C (0x60/0x51/0xFF) when 0x9AB8 == 3. **PA nets** (PA schematic p47, #143) **[fact]**: A1 `RALC`, A2 `FALC`, A3 `FBIAS`, A4 `DBIAS`, A5 `PBIAS`, A6 `FAN`, A7 `ANCV`, A8/A9 test points only, A10 `IALC`. So ch1/ch10 are the reflected-power and current ALC thresholds, ch2 the forward ALC (power level), ch3..5 the final/driver/pre-driver bias, ch7 `ANCV` |
| `sst2_write12`(ch, v) | /SST2 P67 | 12 bits MSB first: 4-bit **channel** (1..8), 8-bit value | **8-channel audio level device** on MAIN, written by `FUN_fffb5d68` (audio levels) when a value changes (shadows 0x20FB8..0x20FBF; all re-sent while 0x12042 = 0) **[fact]** (#143): ch2 = USB OUT LEVEL, ch3 = REAR OUT LEVEL (per mode: SSB 0x9A34/35, AM 0x9A49/4A, FM 0x9A5C/5D, DATA 0x9A71/72, RTTY 0x9A88/89, CW 0x9A9B/9C; 0 while 0x20B6B), ch4 = modulation gain of the selected TX audio source (`FUN_fffb3d11`: 0 = MIC GAIN 0x9BEC.., 1 = USB MOD GAIN, 2 = REAR MOD GAIN), ch1 and ch5 = the same AF level (from the AF GAIN value 0x20BA8 = UI +0xA4 through table 0xFFF81362, or 0x9DC1, or a fixed level, by `audio_route_state`), ch6 = 0 or 0xFF (on/off by route state), ch7 = a second source level, ch8 = AF table 0xFFF81348 or 0x20B31. Levels 0..100 go through the curve 0xFFF8117D. The device is **Q2621 R2A20178NP** (`LD`/`CLK`/`DI` on `SST2n_5`/`CK1_/5`/`DT1_5`); its p20 legend: CH1 AF2 MASTER VR, CH2 USB Audio OUT, CH3 DATA conn. OUT, CH4 MOD IN, CH5 AF1 MASTER VR, CH6 CPU DA(TONE), CH7 CPU DA(BEEP), CH8 BOOST LEVEL **[fact: schematic, #63]** |
| `shreg_write24`(2, v) | /SST3 PA0 | 24 bits MSB first | `rf_bpf_update`: one-hot BPF band, preamp bits 0x8000/0x10000/0x18000, ATT bits 0x20000/0x40000, 0x200000 always set |
| `shreg_write24`(3, v) | /SST4 PB5 | 24 bits | `pa_relay_update`: one-hot TX band (LPF), 0x80 internal ATU in line, 0x100 AM, 0x200 RX line, 0x400 band 10 |
| `shreg_write24`(5, v) | /SST6 PA7 | 24 bits | `atu_relay_update`: three internal-tuner relay bytes (`FUN_fffec50f/500/51e`) into PA-unit Q4030 BU2152FS: 0x1B3B1 → `LX0..7` (L bank, set per band), 0x1B3AD → `AC0..7` (capacitor relays C0..C7), 0x1B3AF → `TC0..7` (capacitor relays C8..CF) **[fact: schematic; bit order inference, strong]** (#166, [eeprom.md](eeprom.md#internal-tuner-relay-bytes-166)) |

## Function table

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFFAF7B8 | `cat_TX` | | TX0/TX1 set (flag 0x20B28), read TX0/1/2 |
| 0xFFFADB7D / 0xFFFAE64B | `cat_RM` / `cat_SM` | | meter reads |
| 0xFFFB6CDE | `trx_init` | `trx_init` | trx_state = 4, timer 0x13 = 2.5 s, AF_MUTE on |
| 0xFFFB6D56 | `io_task` | `io_task` | main-loop task: AF mute, meters, I/O, power-fail, restart |
| 0xFFFB7B43 | `io_poll` | `io_poll` | runs the I/O subtasks once timer 0x13 expires |
| 0xFFFB7F6F | `ptt_inputs_read` | `ptt_inputs_read` | ports → 0x20B24..0x20B29 |
| 0xFFFB85A2 | `ptt_source_select` | `ptt_source_select` | priority → 0x1204D, 0x12050 |
| 0xFFFB86E8 | `ptt_arbiter` | `ptt_arbiter` | TXINH, debounce, hang, TOT |
| 0xFFFB80F9 | `trx_sequencer` | `trx_sequencer` | state machine above |
| 0xFFFB9774 | `pc_keying` | `pc_keying` | CW from DAKY/RTS/DTR: SEND + sidetone |
| 0xFFFB37FE | `tx_freq_allowed` | `tx_freq_allowed` | inhibit flags + region tables |
| 0xFFFB3BA6 | `dest_jumper_apply` | `dest_jumper_apply` | P51 strap |
| 0xFFFB3B33 / 0xFFFB3B5D | `dest_code_get` / `dest_code_set` | | 0x475E |
| 0xFFFB6EC5 | `ptt_source_get` | `ptt_source_get` | 0x1204D |
| 0xFFFB8A02 | `tx_audio_select` | `tx_audio_select` | TX_SEL_A/B |
| 0xFFFB7243 / 0xFFFB7B65 / 0xFFFB722B | … | `af_mute_set` / `af_mute_update` / `af_mute_get` | AF_MUTE PB3 |
| 0xFFFB6FD2 / 0xFFFB7011 | … | `send_a_set` / `send_b_set` | SEND_A PA2 / SEND_B PB4 with inhibit gating |
| 0xFFFB6FAC / 0xFFFB721A | … | `tx_line_get` / `rx_line_get` | P73 / PB7 |
| 0xFFFB268E / 0xFFFB26BF / 0xFFFB26E5 | … | `tot_start` / `tot_expired` / `tot_prewarn` | TX time-out |
| 0xFFFB73DD | `meter_task` | `meter_task` | 5 / 10 ms scheduler |
| 0xFFFB7545 | `swr_meter_protect` | `swr_meter_protect` | SWR meter + HI-SWR flag |
| 0xFFFB742B / 0xFFFB747C | … | `vdd_scale_calc` / `meter_vdd` | |
| 0xFFFB74B8 / 0xFFFB74FF / 0xFFFB7772 / 0xFFFB7869 / 0xFFFB7959 | … | `meter_idd` / `meter_alc` / `meter_po` / `meter_comp` / `meter_s` | |
| 0xFFFB7A40 | `remote_keypad_scan` | `remote_keypad_scan` | FH-2 keypad |
| 0xFFFB6E03..0xFFFB6EB6 | … | *meter_get_vdd/idd/alc/swr/swr_raw/po/comp/s*, `remote_key_get` | getters |
| 0xFFFB4B28 | `supply_undervolt_check` | `supply_undervolt_check` | power-fail |
| 0xFFFB55C2 | `rf_ctrl_task` | `rf_ctrl_task` | |
| 0xFFFB55EB / 0xFFFB56A5 / 0xFFFB5786 | … | `pa_relay_update` / `rf_bpf_update` / `atu_relay_update` | 24-bit registers |
| 0xFFFB5874 / 0xFFFB5976 | … | `main_dac_update` / `pa_dac_update` | BU2505 DACs |
| 0xFFFB1F83 / 0xFFFB1FEF / 0xFFFB208D / 0xFFFB214C | … | `shreg_bus_init` / `bu2505_write` / `sst2_write12` / `shreg_write24` | bus primitives |

## Data structures and globals

| Address | Size | Name | Meaning |
|---|---|---|---|
| 0x20B18 | u8 | `trx_state` | 0..8 as above; 8 = RX idle **[fact]** |
| 0x20B19 / 0x20B1A | u8 | TX acks | both must be 1 to leave state 1 **[fact]**. 0x20B19 is set by `sdr_task`, 0x20B1A by `dsp_link_poll`; `trx_sequencer` clears both **[fact]** (#75) |
| 0x20B24..0x20B2E | u8 | `ptt_req[]` | per-source request flags **[fact]** |
| 0x20B28 | u8 | `cat_tx_req` | CAT TX1 **[fact]** |
| 0x1204D | u8 | `ptt_source` | 0 = none, 1..11 **[fact]** |
| 0x12050 / 0x12051 | u8 | PC-keying active / last P14 level | **[fact]** |
| 0x20B6B | u8 | `tx_active` | set by the arbiter at PTT **[fact]** |
| 0x20B3D | u8 | TX flag used by meters, `key_event_filter` and many CAT handlers | **[fact]** for its uses; who sets it: `FUN_fffb8d77` |
| 0x20B47 | u8 | TOT tripped | **[fact]** |
| 0x20B6D | u8 | HI-SWR flag (0/1/2 blinking) | **[fact]** |
| 0x20F50 | u32 | TX frequency (Hz) passed to `tx_freq_allowed` | **[inference: Hz, from the table units]** |
| 0x475E | 2 (+1) | destination code | **[fact]** |
| 0x465C | u8 | `cfg105[3]`: TX disabled when non-zero | **[fact]** for the effect |
| 0x9AF5 | u8 | TX INHIBIT (`EX030407`): TX disabled when non-zero | **[fact]** |
| 0x9A9F, 0x9AA0, 0x9AA1, 0x9AC3, 0x9C5B, 0x9C5D | u8 | settings: PTT select, break-in, TX→RX delay set, TOT minutes, meter select, VOX | **[fact]** for the use, **[inference]** for the menu names |
| 0x12043..0x1204C | u8 | meter bytes | see the meter table **[fact]** |
| 0x4659..0x475D | 0x105 | `cfg105` (CAT `SPN`) = the **factory alignment table**: 261 items named by the firmware's alignment menu (`001 [GN] VDD MTR` … `261 [TX] IDD MTR`), e.g. fan threshold 0x465A `FAN`, FADJ 0x465B `REF FREQ`, TX inhibit 0x465C `TX INH`; map in [eeprom.md](eeprom.md#cfg105-the-alignment-table-fact) | **[fact]** (#203) |
| 0x20F98..0x20FB6 | | shadow copies of every shift-register / DAC value | **[fact]** |

## Further functions (T23g)

Named functions of this subsystem that the tables above did not list yet, one row each (T23g, found with `tools/doc_table_gaps.py`). The purpose is the plate comment of the name in `tools/ghidra/names_*.tsv` (or the `Ifdsp*Names.java` / `*.lib.tsv` entry); rows marked *code shape* have no comment there and give what the decompile shows: the direct callees, the first string, the size and the caller count. Tags as in the names files; a comment without a tag is an inference from the code.

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFFB3371 | `tx_band_of_freq` |  | (f): index 0..10 of the first bound in ROM 0xFFF8870C (2.1 / 4.7 / 7.5 / 11.5 / 14.5 / 20.9 / 22 / 25.5 / 41.5 / 60 / 75 MHz) above f, else 0xFF **[fact]** |
| 0xFFFB6FBF | `send_a_get` |  | no direct calls; 19 B, callers: 1 **[fact]** (code shape) |
| 0xFFFB711C | `gpo_b_dir_out` |  | PDR P12 **[inference]** |
| 0xFFFB730A | `ear_det` |  | PF5 low **[inference]** |
| 0xFFFBA192 | `tx_cw_keying_class` |  | 0 voice, 1 CW mode, 2/3 CW in SSB (CW AUTO MODE 0x9A3C; value 1 only on band 0xB) by PTT source against PC KEYING 0x9A9F / RPTT SELECT; also sets 0x1215D **[fact]** |
| 0xFFFEC578 | `tuner_rearm` |  | TUNER TYPE SELECT 0x9AB8 = 2 path: re-arms the tuner state 0x20B3F after VFO/band changes (cat-commands-primary.md) **[fact]** |
| 0xFFFED206 | `tuner_tune_state_set` |  | (s): 0x20F0C = s; 1 starts (0x1B3BE = 1), 2 swaps the meter (0x9C5B = 5) and CW WAVE SHAPE (0x9AA1 = 0) and opens pop-up 0x49, 0 restores both; a tune cycle **[fact]** |
| 0xFFFEDC27 | `tuner_port_send` |  | SCI2 tuner port: sends 0xFF, after soft timer 0x23 the frame at 0x1B3C4 (sci2_send) and restarts timers 7, 0x25, 0x24 **[fact]** |

<!-- T23e3:begin -->

### More functions (T23e round 3)

Named in the T23e round-3 batch for MAIN (`tools/ghidra/names_main.T23e3.tsv`); they show in `decomp/main` after the next Ghidra apply and re-export.

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFFB548A | `qsk_delay_ticks` |  | Returns EX020119 QSK DELAY TIME x 5 + 15 **[fact: fffb548a]**; callers trx_sequencer, keyer_task |
| 0xFFFB5D68 | `audio_level_update` |  | rf_ctrl_task's sixth sub-task: picks USB/REAR OUT LEVEL and the MOD GAIN (MIC / USB / REAR by tx_mod_source) per RX mode, from the EX items or the active PRESET, and writes the 8-channel audio level device with sst2_write12 when a value changes **[fact: fffb5d68]** (tx-protection.md #143 already describes this function) |
| 0xFFFB667A | `pa_falc_interp` |  | (band, watts) -> PA drive DAC value: picks the band's 100/50/20/10/5 W FALC alignment items (g_cfg105.a070..a082 ...) and interpolates between the two that bracket the power **[fact: fffb667a]**; only caller pa_dac_update (BU2505 ch2) |
| 0xFFFB7CEC | `fm_noise_squelch` |  | FM modes: squelch threshold from the FM SQL alignment items (g_cfg105.a046/a047 THW/THN, a048 TI) and the SQL knob g_ui.rf_gain, with hysteresis; dsp_fm_noise below it opens (squelch_open = 1, AF mute off), above threshold + hysteresis closes **[fact: fffb7cec]**; only caller af_mute_update |
| 0xFFFB7E61 | `signal_level_squelch` |  | SSB/CW/AM/DATA modes: threshold from g_cfg105.a041_rx_s_mtr_40 (+80 / +110) and the SQL knob g_ui.rf_gain; dsp_signal_level below it opens the squelch (squelch_open = 1, AF mute off), above threshold + 6 closes it **[fact: fffb7e61]**; only caller af_mute_update |
| 0xFFFB8D77 | `lamp_map_update` |  | Builds g_ui.lamp_map: 0x10 squelch open, 0x80 VOX, 0x20 TX (blinking when TX is refused out of band), VFO-A/B/memory/clar colour bits from EX040301..EX040304 VMI COLOR, 1 in split, 0x40 FUNC panel; also sets g_ui.tx_lamp 0/1/2 **[fact: fffb8d77]**; only caller io_task |
| 0xFFFB915E | `rtty_fsk_keying` |  | While transmitting RTTY: reads the RPTT SELECT input (1 = PC5, 2 = PC6, 3 = P21; EX010513 or the PRESET), applies EX010517 POLARITY TX and drives FSK_SHIFT PC4 with beep_request 9 / 0xB for the two states; on RX or other modes stops the tone and sets PC4 **[fact: fffb915e]**; only caller io_poll |
| 0xFFFBA336 | `contest_number_set` |  | Stores a u16 big-endian into g_opstate.ex020205_contest_number_be **[fact: fffba336]**; the setter twin of contest_number_get |
| 0xFFFBA377 | `keyer_elekey` |  | Keyer for KEYER TYPE 2..5 (ELEKEY-A, -B, -Y, ACS): keyer_task calls it when the type - 2 < 4; iambic squeeze memory for types 3 and 4 **[fact: fffba377 and the caller's test]** |
| 0xFFFBA840 | `keyer_straight_bug` |  | Keyer for KEYER TYPE 0/1 (OFF = straight key, BUG): keyer_task calls it when the type (0x1215F) < 2; times elements with timer 0x17 and puts them with keyer_elem_put **[fact: fffba840 and the caller's test; type labels from ROM 0xFFF84339 OFF/BUG/ELEKEY-A/-B/-Y/ACS]** |
| 0xFFFBAA81 | `keyer_output_step` |  | Plays the element ring 0x120BC from the read index 0x1FA3A up to the write index 0x1FA38: raises/clears g_ui.ptt_keyer (break-in), keyer_key_out, sidetone in state 6 **[fact: fffbaa81]** |
| 0xFFFBAFF6 | `keyer_state_clear` |  | Clears the keyer bytes 0x12160..0x12164 **[fact: fffbaff6]**; keyer_task states 0 and 2 |
| 0xFFFBB024 | `keyer_elem_put` |  | Appends to the keyer element ring 0x120BC (index 0x1FA38): arg 1 = one mark bit + sidetone on, 0 = one space bit + sidetone off, 2 = three mark bits (dash) **[fact: fffbb024]**; matches eeprom.md's description of the ring |
| 0xFFFBB10B | `keyer_ring_limit` |  | Helper of keyer_elekey: when timer 0x1B expires drops the last 7 elements and returns 1; caps the ring at 0x4B0 elements (returns 1) **[fact: fffbb10b]** |
| 0xFFFBB16B | `keyer_ring_next` |  | Ring index + 1, wraps to 0 above 0x4FF **[fact: fffbb16b]**; the keyer element ring 0x120BC |
| 0xFFFBB185 | `keyer_sidetone_on` |  | When MONITOR (g_opstate.monitor[0] for SSB/AM-type modes, [1] from CW) is on: beep_request(4), flag 0x1215E = 1 **[fact: fffbb185]** |
| 0xFFFBB1C2 | `keyer_sidetone_off` |  | If flag 0x1215E is set: beep_stop, flag = 0 **[fact: fffbb1c2]** |
| 0xFFFBB1DD | `keyer_key_out` |  | (on): sets SEND_A/SEND_B (send_a_set / send_b_set) when the PTT source / CW keying class asks for it, and handles EX020116 CW BK-IN TYPE **[fact: fffbb1dd]**; only caller keyer_output_step |
| 0xFFFBB283 | `keyer_paddles_read` |  | (*dot, *dash): ckey_dot / ckey_dash, swapped when EX020202 KEYER DOT/DASH is reversed **[fact: fffbb283]** |
| 0xFFFBB2BF | `contest_cut_digit` |  | Cut-number substitution by EX020204 NUMBER STYLE: '1' -> 'A', '2' -> 'U', '9' -> 'N', '0' -> 'T' or 'O', others unchanged **[fact: fffbb2bf]** |
| 0xFFFBB338 | `keyer_text_msg_encode` |  | (n): turns keyer memory text n (0x969F + n*0x33: length + 50 chars, eeprom.md) into elements via the Morse table 0xFFF815C3 (2 bytes per char), '#' inserts the contest number **[fact: fffbb338]** |

<!-- T23e3:end -->
