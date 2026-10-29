# MAIN — DISPLAY link (SCI1)

Back to the [MAIN overview](README.md).

Part of T10b. The UART driver is on [sci.md](sci.md), and what the key/encoder/touch frames do is on [ui-keys.md](ui-keys.md). The DISPLAY
(RZ/A1H) side is `docs/code/display/mainlink.md` (T11b). Function names are the names applied in Ghidra (`tools/ghidra/names_main.tsv`, merged by T17) and match `decomp/main/`; a name still in *italics* is a description that was not applied as a Ghidra name. Tags follow AGENTS.md.

## Overview

- **Physical link.** RX651 SCI1 (P26 TXD1 / P30 RXD1) ↔ RZ/A1H SCIF5 (P6_6/P6_7), nets `DISP_UMOSI/UMISO` (docs/hardware.md). About
  **340.9 kbit/s, 8 data bits, no parity, 2 stop bits** at PCLKB = 60 MHz ([sci.md](sci.md#channels)) **[fact: registers, PCLKB from SCKCR/PLLCR and the
  BRR formula, RX651 HWM r01uh0590 §9.2.1, §9.2.5, §37.2.13 Table 37.11]**. The same UART is the RX651 serial-boot port that DISPLAY uses to reflash MAIN.
- **Binary frames:** `type, payload…, sum`, where `sum` is the 8-bit sum of every byte before it, type byte included. Exceptions: `0x06` ACK and
  `0x15` NAK are single bytes, and the tunnel frames `'Z'` (0x5A) carry a 16-bit length. **[fact]** `displink_check_sum` 0xFFF9C60F,
  `displink_put_sum` 0xFFF9C5D8; the DISPLAY sender `FUN_201150f8` computes the same sum **[fact]**.
- **Type ranges.** MAIN → DISPLAY types are 0x20..0x7F; DISPLAY → MAIN types are 0xC3..0xC5 and 0xE0..0xF1. The DISPLAY's own 43-entry
  table at 0x20450074 lists both groups (see [cross-image notes](#cross-image-notes)). **[fact]**
- **Stop-and-wait with ACK/NAK.** Each side sends one data frame and waits for `0x06`. MAIN retries an unacknowledged frame every 30 ms up to 3 times,
  then drops it. MAIN answers every valid DISPLAY frame with ACK, and a bad length or checksum with NAK. **[fact]**
- **Change-driven traffic.** MAIN builds each data frame in a staging buffer and only sends it when it differs from the last frame sent
  (`displink_copy_if_changed` 0xFFF9C667). The default frame is the 0x99-byte status frame `0x20`, so in steady state the link is quiet until
  something on the radio changes. **[fact]**
- **Polled, no RTOS.** Everything above the ISR runs in `displink_task` 0xFFF94D6F, called once per `main_loop` pass and from the power-off loop
  in `app_main`. **[fact]**
- **Power on comes from the DISPLAY.** The DISPLAY's `0xF0` hello sets UI state +0x36 = 0x20B3A, which is the flag `app_main` waits on while the
  radio is off. So pressing POWER is seen by the DISPLAY, which wakes MAIN through this link. **[fact for the code path; inference that this is the
  POWER key]**

## Framing

### Receive side (ISR level)

`displink_rx_frame_len` 0xFFF9384C runs for every byte in `r_sci1_receive_interrupt` **[fact]**:

1. If a byte arrives more than 10 timer units (soft timer 1, about 10 ms) after the previous one, the frame restarts with this byte.
2. On the first byte it sets the expected length from the table below. An unknown first byte is dropped.
3. For `'Z'`, at byte index 2 it sets the length to `(b2 << 8 | b1) + 4`.
4. When the count is reached, the receive-end callback sets 0xA08A (`displink_rx_done`). The buffer is 0x9E86 (0x204 bytes).

`displink_task` then copies the frame to 0x198F, re-arms the receive (`displink_rx_rearm` 0xFFFB172D), checks the length again with
`displink_rx_len_of` 0xFFF95277 and the checksum, and dispatches it (`displink_rx_dispatch` 0xFFF95331). **[fact]**

The two length tables differ **[fact]**:

| First byte | ISR length | Task length | Note |
|---|---|---|---|
| 0x06, 0x15 | 1 | 1 | ACK / NAK |
| 0x5A `'Z'` | b1..b2 + 4 | 0 → NAK | only consumed by the DSP tunnel loop |
| 0x65 `'e'` | 9 | 0 → NAK | accepted by the ISR, never consumed (it is a MAIN→DISPLAY type) |
| 0xFD | 11 | 0 → NAK | only consumed by the SDR bridge loop |
| 0xFE | 7 | 0 → NAK | only consumed by the SDR bridge loop |
| 0xC3 / 0xC4 / 0xC5 | 35 / 263 / 7 | same | |
| 0xE0 / 0xE1 / 0xE2 / 0xE3 | 6 / 7 / 7 / 9 | same | |
| 0xE4 / 0xE5 / 0xE6 | 5 / 5 / 5 | same | |
| 0xE7 / 0xE8 | 10 / 10 | same | |
| 0xF0 / 0xF1 | 10 / 8 | same | |
| other | dropped (resync) | — | e.g. DISPLAY's `0xFA` (3 bytes) is never accepted |

### Transmit side

All MAIN data frames go out of one buffer at **0x1456** with the length in 0x1B628. `displink_tx_start` 0xFFF9C5B2 appends the sum, marks the frame
outstanding (0x1B3CE = 1, retry count 0x1B3CF = 0) and sends it with `displink_uart_send` 0xFFFB175B → `R_SCI1_Serial_Send`. Most builders first fill
a staging buffer at 0x1741 (0x24A bytes; 0x16A0 for the status frame) and copy it to 0x1456 only if it changed. **[fact]**

## Link control

```mermaid
sequenceDiagram
  participant D as DISPLAY (SCIF5)
  participant M as MAIN displink_task
  Note over D,M: radio off: app_main loops displink_task + cat_parse
  D->>M: F0 01 08 20 23 06 29 code sum (hello, every 5 ms = itron_dly_tsk(5), about one 10 ms tick, up to 30x)
  M->>D: 06 (ACK)
  Note over M: state+0x98 = 1 (link up), +0x36 = 1 (power on), 0x1B3D0 = 1
  M->>D: 60 (0xB6 bytes: MAIN/DISPLAY/DSP/SDR versions + status)
  D->>M: 06
  Note over M: +0x400 = 1
  M->>D: 24 (0x9F bytes: settings)
  D->>M: 06
  loop each change (scheduler priority order)
    M->>D: 20 / 30 / 31 / 37 / ... frame
    alt ACK within 30 ms
      D->>M: 06
    else no ACK or NAK
      M->>D: same frame again (max 3 retries, then dropped)
    end
  end
  D->>M: E0 / E1 / ... (key, encoder, touch, clock)
  M->>D: 06, or 15 on bad length/sum
```

Each step is in the code **[fact]**: the hello handler `displink_rx_F0_hello` 0xFFF9546A, the reply `displink_tx_60_hello` 0xFFF96225, the ACK handler
`displink_rx_ack` 0xFFF9541E (which sets +0x400 when the hello was the outstanding frame) and the scheduler `displink_tx_schedule` 0xFFF95F58.
The DISPLAY's hello loop (30 tries, `itron_dly_tsk(5)` apart, until MAIN answers) is the caller of the F0 builder `FUN_201162a4`; the F1 builder is `FUN_20116334` **[fact, DISPLAY image]**.

### `displink_task` timing

```mermaid
stateDiagram-v2
  [*] --> Idle
  Idle --> Sending: ACK/NAK pending, or scheduler built a frame
  Sending --> Gap: SSR.TEND (sci1_tx_end)
  Gap --> Idle: timer 0x3B, 2 units
  Idle --> AckWait: a data frame was sent (0x1B3D5)
  AckWait --> AckWait: send our own ACK/NAK if pending
  AckWait --> Poll: timer 0x3C, 30 units
  Poll --> Sending: nothing outstanding, next frame from scheduler
  Poll --> Sending: outstanding and retries < 4, resend (displink_tx_resend)
  Poll --> Idle: outstanding and 3 retries done, drop, if it was the hello, link down (+0x98 = 0)
```

- 0x1B3D2 = TX busy, 0x1B3D3 = inter-frame gap running, 0x1B3D4/0x1B3D5 = ACK-wait window, 0x1B3CC = send ACK, 0x1B3CD = send NAK,
  0x1B3CE = data frame outstanding, 0x1B3CF = retry count, 0x1B3D0 = send the hello reply, 0x1B3D1 = hello reply outstanding. **[fact]**
- A received NAK does nothing (`displink_rx_nak` 0xFFF95469 is empty); the frame is simply resent when the 30-unit window ends. **[fact]**
- Every received data frame except `E3` restarts the auto-power-off timer (`cat_apo_reset`). **[fact]**

## DISPLAY → MAIN frames

Offsets are into the frame (byte 0 = type). "UI state" is the struct at **0x20B04** that every module reaches through a pointer (0x25D38, 0x25D4C,
0x25D54, 0x25D58, 0x25D5C, 0x25D60, 0x25D6C..0x25D7C all hold 0x20B04 after `_INITSCT`) **[fact]**. Offsets like "+0x9C" are into that struct.

| Type | Len | Handler | Payload and effect | Reply |
|---|---|---|---|---|
| 0x06 | 1 | `displink_rx_ack` 0xFFF9541E | clears the outstanding frame; after the hello: +0x400 = 1 (send `0x24`) **[fact]** | — |
| 0x15 | 1 | `displink_rx_nak` 0xFFF95469 | nothing **[fact]** | — |
| 0xF0 | 10 | `displink_rx_F0_hello` 0xFFF9546A | b1,b2 → DISPLAY version string `"Vxx-yy"`, b4..b6 → date `"yy-mm-dd"` (stored by 0xFFF94BFD/0xFFF94C1B, read back by `ver_display`), b3 unused (DISPLAY sends 0x20), **b7 = boot code**. Sets link up (+0x98), power on (+0x36), hello reply pending. Boot codes: see below **[fact]** | ACK, then `0x60` |
| 0xF1 | 8 | `displink_rx_F1_sys` 0xFFF957E6 | b1 = sub-command: 0x01 enter SDR bridge (0x1C8D), 0x02 enter DSP ISP tunnel (0x1C63), 0x03 **disable CAT** (0x20B46 = 1), 0x83 no-op; others → NAK. 0x81 / 0x82 leave the SDR / DSP tunnel (handled inside the tunnel loops) **[fact]** | ACK (0x03, 0x83), none for 0x01/0x02 (the tunnel loop ACKs), NAK otherwise |
| 0xE0 | 6 | `displink_rx_E0_key` 0xFFF95829 | **key / touch event**: b1 = source (high nibble) and action (low nibble), b2..b3 = key code (big-endian). Passed through `key_event_filter`, then queued at +0x9C..+0xA0 for `key_task` ([ui-keys.md](ui-keys.md)) **[fact]** | ACK (always) |
| 0xE1 | 7 | `displink_rx_E1_encoder` 0xFFF9588B | **encoder step**: b1 = encoder id, b2 = signed step count ([ui-keys.md](ui-keys.md#encoders-e1)); ignored while +0x80 = 1 **[fact]** | ACK |
| 0xE2 | 7 | `displink_rx_E2` 0xFFF95BF4 | b1 ≠ 0 → +0xA6 = 1 (first frame also sets +0xA7 and +0xA5). Read by 0xFFFCFxxx/0xFFFD3xxx UI code **[fact for the fields]**. **SD-card state**: the DISPLAY sender is `mainlink_send_sd_state` **[inference, T14]** | ACK |
| 0xE3 | 9 | `displink_rx_E3_clock` 0xFFF95ED3 | b1..b5 → +0xAD..+0xB1. **Date/time from the DISPLAY RTC** **[inference]**: the clock-set code (0xFFFCD7xx, 0xFFFCDBB8) copies these to +0xB2..+0xB6 and forces fields 2 and 3 (month, day) to ≥ 1, and `0x65` sends +0xB2..+0xB6 back. No APO reset (periodic) | ACK |
| 0xE4 | 5 | `displink_rx_E4` 0xFFF95C6A | clears +0x82: the DISPLAY's answer to `0x7B` **[fact]** | ACK |
| 0xE5 | 5 | `displink_rx_E5` 0xFFF95C74 | clears +0x80 (unblocks the scheduler and encoders) **[fact]** | ACK |
| 0xE6 | 5 | `displink_rx_E6_beep` 0xFFF95C8A | b1 = 0/1/2 → `beep_request`(1/2/3) 0xFFFB2DA6 (code 3 is also used when `key_event_filter` rejects a key) **[fact; "beep" is inference]** | ACK |
| 0xE7 | 10 | `displink_rx_E7` 0xFFF95CBC | b1 = 0 / 1 / 0xFF, b5 = value → +0xA8, +0xAA/+0xAB/+0xAC and a result code 1..5 in +0x488 (0xFF: also `beep_stop`). Consumed by `dispreq_e7_task`. Status of the DISPLAY's **PlayList recorder/player** (sent while its audio owner flag 0x2080048E = 1); b1 = 0xFF is an error with code b5 **[fact, DISPLAY side: `FUN_20124744`]** (#65) | ACK |
| 0xE8 | 10 | `displink_rx_E8` 0xFFF95DAD | as E7, result in +0x48C **[fact]**; sent for the other audio screens (0x2080048E = 2/3), most likely voice messages **[inference]** (#65) | ACK |
| 0xC3 | 35 | `displink_rx_C3` 0xFFF95E65 | copies the payload to +0x2ED (0x109 bytes are copied whatever the frame length), sets +0x3F6: the answer to MAIN's `0x43` **[fact]** | ACK |
| 0xC4 / 0xC5 | 263 / 7 | `displink_rx_C4_C5` 0xFFF95E97 | same as C3: C4 answers `0x44` (block read, carries the data), C5 answers `0x45` (block write, echo only) **[fact, DISPLAY side: `mainlink_rx_block_read` / `mainlink_rx_block_write`]** (corrected in #61; this row used to pair them the other way round). Layout in [SD CARD transfers](#sd-card-transfers-0x43--0x44--0x45) | ACK |
| 0xB3 | — | 0xFFF95EC9 | has a case in the dispatcher (sets ACK) but no length entry, so it can never arrive **[fact]** | — |

### F0 boot codes

The DISPLAY puts the result of `key_scan_first` (which of its 8 key lines is held at power-on) in b7, or 0x10 on a later hello without a key, and sends
code 6 from `FUN_2011668c` **[fact, DISPLAY side]**. MAIN acts on them in `displink_rx_F0_hello` **[fact]**:

| b7 | MAIN action | Meaning |
|---|---|---|
| 0x00 | power on | normal power-on **[inference]** |
| 0x01 | `settings_defaults(0)`, 0x20B45 = 1, `dest_jumper_apply` | **full reset** of the settings **[fact]** |
| 0x02 | +0xBA = 1 (0x20BBE), `align_load_preset` | **factory alignment mode**, the same as `ZZPE071000` (TX band limits off, DSP key stores calibration items; [cat-commands.md](../../cat-commands.md#ext-zz)); the scheduler also sends `0x62`/`0x30`/`0x31` **[fact]** (#75). The service manual enters alignment mode by holding **[BAND] + [QMB] + [NAR]** at power-on, so that is this code **[inference]**; frame `0x62` (`displink_build_62`) carries nine lines of the alignment menu (labels from ROM 0xFFF817C3 plus each item's value), see [eeprom.md](eeprom.md#cfg105-the-alignment-table-fact) (#203) |
| 0x04 | +0x437 = 1, +0x34 = 0 | a numeric-entry/adjust mode: encoders 2/3/4/5 and the main dial go to the 0x25D3C counter (0..99,999,999); encoder 3 also steps the `0x64` LCD test patterns (#72) **[fact; purpose: service mode, inference]** |
| 0x05 | toggles 0x4760; when it turns it off, TX BPF SEL (0x9A36, `EX010113`) above 4 is set back to 1 | **TTBF unlock**: 0x4760 is the hidden flag that lets TX BPF SEL reach value 6 (TTBF) on the front panel ([menu.md](menu.md)) **[fact]** (#75) |
| 0x06 | link down (+0x98 = 0), no power on | the DISPLAY is in its maintenance/loader screen (boot combination 6, `mainlink_hello_key6` from `logo_fade_in`), or this is the first hello after a MAIN update **[fact for the DISPLAY call path, T14]** |
| 0x07 | swaps the destination code: 0xA983 / 0xB5A7 → 0xD950, 0xD950 / 0xA4C5 → 0xA983 (`dest_code_set`, which also resets settings and restarts) | **region change** at power-on **[fact for the values]** |
| 0x10 | power on only if 0x9DC5 ≠ 0 | 0x9DC5 is set by `PS1;`, by a low-voltage power-down and by the `0x7F` power frame, so a DISPLAY restart only powers the radio up if it was on **[inference]** |

## MAIN → DISPLAY frames

Listed in the scheduler's priority order (`displink_tx_schedule`, one frame per call). "Trigger" is the UI-state flag that requests it. Lengths
include type and sum and match the DISPLAY's table **[fact]**. Payload meanings are given only where the builder makes them clear.

| # | Type | Len | Trigger | Builder (send / fill) | Payload |
|---|---|---|---|---|---|
| 1 | 0x60 | 0xB6 | 0x1B3D0 (after F0) | `displink_tx_60_hello` 0xFFF96225 / 0xFFF96241 | b1..b8: MAIN, DISPLAY, DSP, SDR versions as BCD pairs (from `ver_main`, `ver_display`, `ver_dsp`, `ver_sdr`); b13..b14 = +0x32 (0xDB when 0x4660 set); then the 0x97-byte status block (same as `0x20`) and a few settings (0x9B0D, 0x9B09, 0x9B05, 0x9B01, 0x9DC5) **[fact]** |
| 2 | 0x64 | 3 | +0xB7 | 0xFFF986E0 | b1 = +0xB8, sent only when it changed **[fact]** |
| 3 | 0x24 | 0x9F | +0x400 (after the hello ACK; again 0x2B timer after +0x401) | 0xFFF9A17D / 0xFFF9A1A7 | settings block (0x9ACE, 0x9B20/21, 0x9AC7, 0x9B11, 0x9BEA, 0x9B10, 0x9BE9 …) **[fact]** |
| 4 | 0x7F | 0x0B | +0x447 | `power_down_save` 0xFFF98797 | b1 = +0x35 & 0x7F, then the constant `9B BA F6 38 FF 25 73 1F`. +0x35 (= 0x20B39) is the power command: 0x10 power off (`PS0;`), 0x11 restart (`dest_code_set`, resets), 0x90 low-voltage off (also waits 2000 units) **[fact for the values; the constant looks like a guard against accidental matches, guess]** |
| 5 | 0x62 / 0x30 / 0x31 | 0x197 / 0xA0 / 0xA3 | +0xBA (boot code 2) | 0xFFF9C46D / 0xFFF98ECB | |
| 6 | 0x7C | 5 | +0x81 | 0xFFF98869 | zeros; +0x80 then blocks until `E5` **[fact]** |
| 7 | 0x7B | 5 | +0x83 | 0xFFF9889C | b1 = toggled +0x82; blocks until `E4` **[fact]** |
| 8 | 0x7A | 5 | +0x85 | 0xFFF988F2 | zeros; +0x84 blocks **[fact]** |
| 9 | 0x70 | 0xE3 | +0x86 | 0xFFF98925 / 0xFFF9894F | |
| 10 | 0x43 / 0x44 / 0x45 | 0x23 / 7 / 0x107 | +0x87, type in +0x1E0, length in +0x1E2 | 0xFFF98BCD / 0xFFF98C1F | requests answered by `C3` / `C5` / `C4`; set by the SD CARD menu operations (`sd_menu_task`, task 13: MEM LIST / MENU load and save, INFORMATIONS, FORMAT) **[fact]** (#65) |
| 11 | 0x50 | 0xF5 | +0x88 and +0x90 | 0xFFF9A2D1 / 0xFFF9A2FB | |
| 12 | 0x23 | 0x37 | +0x89 / +0x8A / +0x8B | 0xFFF98E39 / 0xFFF98E96 | b1 = high byte of +0x1BE plus 1. **The +0x8A/+0x8B variants call empty fill functions** (0xFFF98EC9, 0xFFF98ECA) and resend whatever is in 0x1456 with length 0x37 **[fact]** |
| 13 | 0x30 / 0x31 | 0xA0 / 0xA3 | +0x8C | `displink_tx_30_31` 0xFFF98ECB | 0x30 when +0x1C2 < 0x1E or 0xFF, 0x31 when < 0x5F **[fact]** |
| 14 | 0x65 | 9 | +0x8D | 0xFFF9A0CC / 0xFFF9A100 | +0xB2..+0xB6: the clock to set on the DISPLAY RTC **[inference]** |
| 15 | 0x34 | 0xA3 | +0x99 (then +0x9A blocks) | 0xFFF98F7C / 0xFFF9A06E | |
| 16 | 0x30 / 0x31 | | +0x1C0 or +0x1C1 (when +0x8F = 0) | 0xFFF98ECB | |
| 17 | 0x50 | 0xF5 | +0x90 | 0xFFF9A2D1 | |
| 18 | 0x3A | 0xA2 | +0x93 | 0xFFF9A8E3 / 0xFFF9A925 | |
| 19 | 0x39 | 0xE9 | +0x94 | 0xFFF9B69E / 0xFFF9B6C8 | |
| 20 | 0x3F | 5 | +0x91 | 0xFFF9A89B | b1 = +0x92 **[fact]** |
| 21 | 0x40 | 0x1FB | +0x95, at most every 100 units (timer 0x29) | 0xFFF9AAAD / 0xFFF9AAF7 | the only rate-limited frame. Status + menu list (five 0x2D-byte text slots, also the "FIRMWARE UPDATE" entry) **[fact on the DISPLAY side, display/mainlink.md]**; the scope does not use this link ([system.md §6.4](../system.md#64-scope-and-waterfall-data)) |
| 22 | 0x37 | 0x240 | +0x96 | 0xFFF9AB2A / 0xFFF9AB57 | the largest frame **[fact]** |
| 23 | 0x41 | 0x146 | +0x97 | 0xFFF9BB23 / 0xFFF9BB50 | |
| 24 | 0x20 | 0x99 | default | `displink_tx_20_status` 0xFFF9C42A / 0xFFF9C454 → `displink_build_status` | the main status block: VFO A/B record (0x9D09 or 0x9D63 by 0x9DBD), mode, etc. Sent only when changed **[fact]** |

Types in the DISPLAY table that MAIN V01-12 never sends: **0x21, 0x42, 0x71** (no builder writes them) **[fact: none of the type stores in the
image use these values]**.

The payload layouts of the frames that carry their own data after the status block (0x24, 0x30/0x31, 0x37, 0x39, 0x3A, 0x40, 0x41,
0x50, 0x62, 0x70) are still open (#179). The status block itself is mapped below (#72).

### The 0x97-byte radio status block (`0x20`, #72)

`displink_build_status` (0xFFF96455) fills the frame buffer 0x16A0 (byte 0 = type) and returns 0x98, the index of the checksum. The
same block follows the header in `0x60` and starts every "status + …" frame **[fact]**. Indexes are frame bytes (the DISPLAY's
`mainlink_status_valid` 0x2015E354 range-checks the same bytes). "rec" = the **active** VFO record (0x9D09, or 0x9D63 when 0x9DBD = 1);
"UI" = the UI-state struct 0x20B04; per-mode values come from rec's per-mode block ([radio-control.md](radio-control.md#per-mode-block-layout)).
Sources are **[fact]**; names in *italics* are **[inference]**.

| Byte | Source | Content |
|---|---|---|
| 1 | 0x9C37 | *scope flag* (also drives byte 39) |
| 2 | `FUN_fff96dde` | scope mode 0..B, the `SS` sel-6 coding ([cat-commands-primary.md](../../cat-commands-primary.md#ss)) |
| 3 | `FUN_fff96f3e` | bit 7 = active VFO is B (inverted while UI +0x405), bit 5 = split 0x9C5E, else bit 4/bit 6 from UI +0x425/+0x426 (side flag) |
| 4 | `FUN_fff96fb7` | bit 5 when UI +0x95, +0x96 or +0x97 is set |
| 5 | `FUN_fff9700b` | split 0x9C5E \| waterfall EXPAND 0x9C3D << 5 \| 0x9DC6 << 6 |
| 6 | `FUN_fff97049` | 0x9B17 bit 0 << 6 \| 0x9B16 << 7 (menu settings) |
| 7 | `FUN_fff97075` | UI +0x69 (2 bits) << 4 \| +0x68 << 6 \| **TX** (+0x67 = 0x20B6B) << 7 |
| 8 | `FUN_fff970b8` | UI +0x34, high nibble only when 0x9B10 (or +0x480 in numeric-entry mode) is 0 |
| 9 | `FUN_fff97105` | 0x9C5C << 3 \| UI +0x6C/+0x6B/+0x6A << 4/5/6 (+0x6A/+0x6B = *frequency settled*, `FUN_fff9ccd3`) \| marker 0x9BE7 << 7 |
| 10 | `FUN_fff9716f` | TX BPF SEL of the mode (0x9A36 SSB, 0x9A4B AM, 0x9A73 DATA/PSK) \| 0x80; 0 in other modes; value 6 without bit 7 |
| 11 | 0x9C5B & 7 | meter selection (0 PO, 1 COMP, 2 ALC, 3 VDD, 4 IDD, 5 SWR; see byte 95) |
| 12 | `FUN_fff971fc` | rec+3 bits 0–1 \| (rec+5 bits 0–1, minus 1) << 2 \| {2 in FM modes, else `FUN_fff9921f` bit 7} << 4 |
| 13 | `FUN_fff9728c` | 0x80 = 0x9AA4 in CW, 0x40 = APF on (CW block bit 5), bits 4–5 from `FUN_fff973bc`, bits 0–2 = AGC (`GT`) speed + 1, 0 = AUTO/off |
| 14 | `FUN_fff97430` | TX-VFO flags: bit 6 `FUN_fff9752b`, bit 5 keyer on (0x9C02) with `FUN_fffc3e3c`, bit 4 `FUN_fff99669`, bit 2 `FUN_fff973bc` bit 1; FM modes: repeater shift + 1 in bits 0–1 |
| 15 | `FUN_fff97567` | UI +0x6E (2 bits) \| +0x6D << 3 \| message/keyer state << 6 (1 recording, 2 playing, 3 +0x92) |
| 16 | `FUN_fff976d2` | PEAK 0x9BE6 & 7 (`SS01`) \| (UI +0x6F << 4, or 0x40 while timer 0x2A runs) |
| 17 | `FUN_fff9770b` | span index (`scope_span_index`) \| CENTER/CURSOR/FIX 0x9C35 << 6 |
| 18 | 0x9C5A, 0x9BE8 | scope speed << 4 \| colour; with speed STOP (`FUN_fffc4f8f`) 0x50 \| colour |
| 19–20 | `FUN_fff977b3` | default WIDTH of the mode (3000, 500, 9000, 16000, 3200 Hz) |
| 21–24 | `FUN_fff9782b` | CW only: zero-in indicator, 4 bytes from table 0xFFF804DE by `dsp_tune_offset` (±99 → 0..24), refreshed every 100 units |
| 25–26 | `FUN_fff978eb` | CONTOUR frequency/10 (block +2); bit 7 of byte 25 = CONTOUR LEVEL 0x9AD5 negative |
| 27–28 | `FUN_fff9795f` | NOTCH frequency/10 (block +4) |
| 29–30 | `FUN_fff979d3` | WIDTH (block +6; fixed 6000 AM-N, 16000 FM-N/DATA-FM-N) |
| 31–32 | `FUN_fff97a44` | IF SHIFT (block +8) |
| 33 | 0x9C5F | APF offset (`CO03`) |
| 34 | 0x9C04 + 30 | CW pitch / 10 Hz |
| 35 | `FUN_fff97abc` | bit 7 UI +0x70 (FUNC panel open), bit 6 +0x71, bit 5 shift ≠ 0, bit 4 width ≠ default, bit 2 +0x47A, bits 0–1 +0x73 |
| 36 | `FUN_fff97b7b` | UI +0x79 & 0xF \| DVS state +0x78 << 4 (0x20B7C: 1 play, 2 record) |
| 37–42 | `FUN_fff97ba6` | scope: CENTER/CURSOR/FIX (0 in TX), 0x84/3 (3DSS 0x9C36), 0x86/5 (0x9C37), 0x88/7 (EXPAND 0x9C3D), 9, 10; skipped while UI +0x41A |
| 43 | 0xFF | |
| 44 | `FUN_fff97c74` | FUNC-knob function (0x9DC9, or a code for the open setting +0x1C2: 0x0B→3, '&'→8, '/'→0x11, 'T'→0x36, '9' DNR→0x1B, 'F'→0x10, '8'→0x1A); 0x2D while TXW (UI +0x483) |
| 45–69 | VFO block, **main side** | 45 mode (rec+0 & 0xF); 46 VFO state code (`FUN_fff97cf7`: 1 VFO, 0 state 0, 2 memory, 3 memory tune, 4 PMS, 5 QMB, 7 60 m, 8 EMG; 9 = split RX); 47 channel number; 48 `FUN_fff97e1d` flags; 49–53 frequency digits (`FUN_fff982bb`, or the numeric-entry BCD at UI +0x7B in mode +0x437); 54–65 memory tag (rec+0x4E); 66 UI +0x425; 67–68 clarifier offset (rec+0x48) |
| 70–94 | VFO block, **sub side** | same layout for the other VFO (state 10 = split TX). The two blocks are built for A then B and swapped when B is active |
| 95 | `FUN_fff9849e` | meter value: S-meter in RX, else PO/COMP/ALC/VDD/IDD/SWR by byte 11 |
| 96 | `FUN_fff98526` | 0x9C61 \| 0x9C62 << 2 \| rec+2 bit 1 << 3 \| DNR on (rec+6 bit 4) << 4 |
| 103 | 0 | |
| 104 | 0x9A8D, 0x9A8C | RTTY shift (2 bits) \| polarity << 7 |
| 105 | 0x9A79 | (2 bits) << 4 (PSK/DATA setting) |
| 106 | 0x9C03 | key speed (`KS`) |
| 107–112 | 0 | |
| 113 | 0x9C3C, 0x9C39 | OSC time (3 bits) \| AF-FFT att << 5 \| 0x18 (`SS07`) |
| 115–116 | 0x9A7A:7B × 10 | DATA offset in Hz |
| 117–120 | `disp_put_op_freq` | operating frequency (UI +0x458 while TX, else +0x450/+0x454), u32 BE |
| 121–124 | `disp_put_tx_freq` | TX frequency 0x20F50 |
| 125–128 | `disp_put_dial_freq` | dial frequency |
| 129–132 | `disp_put_scope_start` | scope start frequency (0x20F60, or the FIX band memory) |

Bytes 97–102, 114 and 133–151 are not written by this builder (they keep whatever the buffer holds) **[fact]**. The exact
meaning of several single bits above (UI +0x34, +0x68, +0x69, +0x6D..+0x6F, +0x73, +0x79, 0x9B16/0x9B17, 0x9C5C/0x9C61/0x9C62) is open
(#179).

### Small frames and mode flags (#72)

- **`0x64` LCD test** **[fact]**: `displink_tx_64` (0xFFF986E0, from the scheduler) sends UI +0xB8 when it changes. +0xB8 is set by
  `FUN_fffc82b7`, which `enc3_step` calls while UI +0x437 = 1, i.e. in **boot mode 4**: the knob steps 0x1B4EC through the test
  patterns and the first position sends 0xFF (off). So boot code 4 is the service mode that holds the LCD test as well as the numeric
  entry **[inference]**.
- **`0x34` info** **[fact]**: `displink_tx_34` (0xFFF98F7C, `displink_build_34(1, 0x1B3D6)`) runs when UI +0x99 is set, by the
  menu item **CERTIFICATION** (`menu_m4_21_0_enter`) and by `FUN_fffbe4e8` (a page step).
- **Mode flags**: 0x20BBE = UI +0xBA, factory alignment mode (boot code 2); 0x20B8A = +0x86, a message pop-up is shown (`FUN_fffcfa3d`) and frame `0x70` is due;
  0x20B7C = +0x78, DVS state (0 idle, 1 play, 2 record; [cat-commands-primary.md](../../cat-commands-primary.md#pb)); 0x20B98 = +0x94,
  the request flag of frame `0x39` **[fact for the writers/readers]**.
- **E2, E7/E8 result codes, boot code 5**: as in the tables above; E7/E8 codes 1..5 in +0x488/+0x48C are consumed by `dispreq_e7_task`,
  whose per-code actions are open (#179).


## Boot error report

Bytes 13..14 of frame `0x60` (frame offsets +0xD/+0xE) are the u16 UI-state field +0x32 (0x20B36/0x20B37), big-endian, cleared after
each `0x60` **[fact]** (#60):

| Value | Set by | DISPLAY reaction |
|---|---|---|
| 0 | normal | power-up continues; with an opening-message time (`0x20800481`) it first shows the 12-character text from the frame |
| 2 | the DSP did not answer at boot ([dsp-link.md](dsp-link.md)) | error screen, `ERROR CODE : 002` |
| 3 | the SDR did not answer register 1 at boot (`sdr_init`, [sdr-link.md](sdr-link.md)) | error screen, `ERROR CODE : 003` |
| 0xDB | `displink_build_60` when +0x32 is 0 and the flag 0x4660 is set | as 0, and the DISPLAY sets 0x20450029, which makes its link-error handler (`mainlink_on_nak`) show an error box instead of resetting |

- **DISPLAY side** **[fact]**: `mainlink_rx_validate` accepts `0x60` only if the u16 is 0..4, 0xDB or 0xFF. `opening_screen` calls
  `FUN_201322AC` when byte 0xE is 1, 2 or 3, or when no `0x60` arrives within about 5 s. That screen draws three text lines from the
  table at 0x20808558 (`INSERT FIRMWARE SD CARD.`, `TOUCH THE SCREEN TO CONTINUE.`, see [display/gui.md](../display/gui.md)) and
  `ERROR CODE : %03d` with byte 0xE (any other value is shown as 1). It then waits for a touch or key and opens the boot-loader
  (firmware update) screen. So **001 = MAIN did not answer, 002 = DSP, 003 = SDR (FPGA)**. Value 1 is never set by MAIN; it is the
  DISPLAY's own default **[fact]**.
- **0x4660** is the RAM copy of EEPROM byte 0x0011 (RAM = EEPROM + 0x464F), alignment item 008 `DBG MODE ENABLE`; only `SPN`, the
  alignment menu and the defaults write it. When it is set, the SOFT VERSION rows (`menu_m4_18_0_draw`) also show `-` + 4 + 8
  characters from ROM 0xFFFFFF10/0xFFFFFF20 after the MAIN version and the DISPLAY's hello date (`yy-mm-dd`) after the DISPLAY
  version (#205, [eeprom.md](eeprom.md#cfg105-the-alignment-table-fact)). A factory/debug display flag **[inference]**.

## SD CARD transfers (0x43 / 0x44 / 0x45)

The SD card is on the DISPLAY, so MEM LIST LOAD/SAVE and MENU LOAD/SAVE move the data through the DISPLAY's 32000-byte transfer buffer
0x208116A6 (#61). `sd_menu_task` (task 13, [README.md](README.md)) drives it; `displink_build_req` builds every request as
`type, +0x1E4, +0x1E5…` with the length in +0x1E2 **[fact]**.

| Frame | Bytes after the type | Built by | Answer (stored at +0x2ED by `displink_rx_C3` / `displink_rx_C4_C5`, flag +0x3F6) |
|---|---|---|---|
| `0x43` (0x23 bytes) | op, 4 bytes | the `sd_*_start` functions (op 1 MEM LIST LOAD, 2 MEM LIST SAVE, 3 MENU LOAD, 4 MENU SAVE, 5 INFORMATIONS, 8 FORMAT; bytes 0) and, with op = transfer id, three steps: `FUN_fffd0902` sub 1 (`1, 0x15DE7, 0x15DE8, 0`), `FUN_fffd04dd` sub 0x10 (`0x10, 0x15DE7 + 0x15DE8, 0x50, 0`) and, for a save, `FUN_fffd041e` sub 4 (`4`, then a 16-bit value) | `C3`, 0x23 bytes |
| `0x44` (7 bytes) | id, offset u16 BE, length u16 BE | `FUN_fffd0980` | `C4`: id, offset, length, then the data (frame 0x106 bytes) |
| `0x45` (0x107 bytes) | id, offset u16 BE, length u16 BE, 0x100 data bytes | `FUN_fffd0fde` (data from `FUN_fffd1078`) | `C5`: id, offset, length |

All facts are from both images **[fact]**, except where noted:

- **Transfer id.** Load uses `0x41` (memory list) / `0x43` (menu), from `FUN_fffd0566`. Save uses `0x42` / `0x44`, from `FUN_fffd04c1`.
  The DISPLAY accepts a block frame only if its id equals the id it armed in 0x208116A0. Its names `sdmenu_req_save` (0x41/0x43) and
  `sdmenu_req_load` (0x42/0x44) have the directions the wrong way round: 0x41/0x43 is the buffer that MAIN *reads* after the DISPLAY
  loaded a file.
- **Data.** The image is a 2-byte destination code (`dest_code_get`) followed by the RAM block: the **menu settings 0x9012..0x9C34**
  (0xC23 bytes, 0x15DE5 = 0; staged at 0x12273, total 0xC25) or the **memory list 0x60C9..0x9011** (0x2F49 bytes, 0x15DE5 = 1; staged at
  0x12E98, total 0x2F4B). It moves in **0x100-byte blocks**: 13 for the menu, 0x30 for the memory list, the last one shorter (offset
  0x1FF02, length 0x1FF04, count 0x15DE4).
- **Load.** MAIN reads every block and checks the echoed offset and length (+0x2EE..+0x2F1). Data starts at +0x2F2. At the end it
  compares the destination code with its own, and copies the staged image over the live RAM only if they match; otherwise
  `beep_request(3)`. So a file from a radio with a different destination code is refused.
- **Save.** MAIN copies the live RAM into the staging area on the first block (offset 0) and writes it block by block with 0x45.
- **0x43 payload.** `0x15DE7` / `0x15DE8` are set by the file-list stepping code 0xFFFCFB26..0xFFFCFFD6 (values 0xFE/0xFF at the ends),
  so they are a page and a row in the DISPLAY's file list, sub 1 asks for a list page and sub 0x10 opens the file at page + row
  **[inference for the meanings; the bytes are fact]**.
- **Not traced.** The meaning of the C3 answer bytes beyond the echo, and the INFORMATIONS (op 5) and FORMAT (op 8) exchanges.

## Tunnel modes

Two DISPLAY-driven maintenance modes take over the link. Each runs as a blocking loop inside a `main_loop` task and talks to SCI1 directly with
`displink_rx_ready` / `displink_rx_buf` / `displink_rx_rearm` / `displink_uart_send` **[fact]**:

- **SDR bridge** — `F1 01` → 0x1C8D → `sdr_bridge_mode` 0xFFFA3226 (from `sdr_task`'s task). It resets the SDR module (P71 via 0xFFFB7080 and the
  0xFFFB7051/0xFFFB7067 pins), then serves `FD 00 …` (write a register: two `hex2word` fields, 11 bytes) and `FE 00 …` (read register 0x32 or 0x33,
  7 bytes), answering `06`/`15` or `7D 00 <4 hex> sum`. `F1 81` leaves. **[fact]** Details: T10c.
- **DSP ISP tunnel** — `F1 02` → 0x1C63 → `dsp_isp_bridge` 0xFFFA0C79 (from `dsp_link_poll`'s task). It toggles P71/P72 (PORT7 PODR bits 1/2 via 0xFFFB7080/0xFFFB7098; RT685 reset/ISP pins
  **[inference]**), sends `5A A6` (NXP ISP ping) on SCI4, ACKs the DISPLAY, then forwards: DISPLAY `Z len16 data… sum` → payload to SCI4; every
  SCI4 packet → `Z len16 packet sum` to the DISPLAY. `F1 82` leaves. **[fact]** So the DISPLAY updates the IF-DSP flash **through MAIN**, with
  MAIN as a transparent UART bridge to the RT685 boot ROM **[inference, high]**. Details: T10d.
- `F1 03` sets 0x20B46, which makes `cat_parse` return at once (CAT disabled) **[fact]**; it is probably sent before a firmware update **[guess]**.

## Cross-image notes

- **Command table.** The DISPLAY table at 0x20450074 (`.data`, 43 × 12 bytes: u16 type, u16 payload length, 8 bytes that are 0 at init) has
  these lengths (payload + 2 = frame length) **[fact, read from the decompressed `.data` in the DISPLAY Ghidra project]**:
  `20:97 23:35 30:9E 31:A1 37:23E 39:E7 3A:A0 3F:03 40:1F9 41:144 43:21 44:05 45:105 42:FD 50:F3 60:B4 62:195 64:01 65:07 70:E1 7A:03 24:9D 21:03
  7B:03 7C:03 71:06 7F:09 34:A1 F0:08 E0:04 E2:05 E4:03 E5:03 E6:03 E7:08 E8:08 E1:05 E3:07 FA:01 F1:06 C3:21 C4:105 C5:05`.
  Every length agrees with MAIN's builders and with MAIN's receive tables **[fact]**.
- `0xFA` (3 bytes) is in the DISPLAY table but MAIN's receiver drops it as unknown **[fact]**.
- **Wire format vs queue element.** `mainlink_send_cmd` / `FUN_201150f8` put `0xAA, length` in front of the frame in the DISPLAY's TX mailbox
  element (+4, +6), and the frame itself starts at +8. MAIN never sees an 0xAA byte, so the header is internal to the DISPLAY **[inference: MAIN
  receive tables have no 0xAA entry]**. T11b should confirm in the DISPLAY TX task.
- **ACK discipline on the DISPLAY side.** `FUN_201150f8` sends `F0`/`F1` at once, and queues the other types behind a "waiting for ACK" flag
  (0x2045002A); `E1` encoder frames are built by `FUN_20115c74` straight into the mailbox **[fact, DISPLAY]**.
- **F0 contents.** The DISPLAY builds `F0 01 08 20 23 06 29 <code>`: version 01-08, date 2023-06-29 (matching the DISPLAY V01-08 package date)
  **[fact]**.
- **Baud.** MAIN uses ≈340.9 kbit/s 8N2. The DISPLAY SCIF5 SCSMR/SCBRR setting was not checked here (T11b).

## Functions

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFF94D6F | `displink_task` | `displink_task` | RX → validate → dispatch; ACK/NAK; gap/ACK-wait timers; scheduler; also a 100-unit periodic job (timer 0x4A) at the end |
| 0xFFF94CAB | `qmb_boot_init` | `qmb_boot_init` | UI/link state init in `app_main` before the power-off loop (+0xB8/+0xB9 = 0xFF, …) |
| 0xFFFB1702 | `displink_uart_start` | `displink_uart_start` | R_SCI1_Start + arm receive (0x9E86, 0x204) |
| 0xFFFB171E / 0xFFFB172D / 0xFFFB1745 / 0xFFFB174F | `displink_rx_ready` / `displink_rx_rearm` / `displink_rx_done` / `displink_rx_buf` | `displink_rx_ready` / `displink_rx_rearm` / `displink_rx_done` / `displink_rx_buf` | flag 0xA08A; `rx_buf` returns 0x9E86 (the decompiler shows `void`) |
| 0xFFFB175B | `displink_uart_send` | `displink_uart_send` | `R_SCI1_Serial_Send(buf, len)` |
| 0xFFFB176B | `sci1_tx_end` | | SSR.TEND |
| 0xFFF95277 | `displink_rx_len_of` | `displink_rx_len_of` | task-level length table |
| 0xFFF95331 | `displink_rx_dispatch` | `displink_rx_dispatch` | switch on byte 0 |
| 0xFFF951FF | `displink_tx_poll` | `displink_tx_poll` | next frame or retry, link-down on hello timeout |
| 0xFFF95F26 / 0xFFF95F3F | `displink_send_ack` / `displink_send_nak` | `displink_send_ack` / `displink_send_nak` | |
| 0xFFF95F58 | `displink_tx_schedule` | `displink_tx_schedule` | priority list above |
| 0xFFF96209 | `displink_tx_resend` | `displink_tx_resend` | send 0x1456 again |
| 0xFFF9C5B2 / 0xFFF9C5D8 / 0xFFF9C60F | `displink_tx_start` / `displink_put_sum` / `displink_check_sum` | `displink_tx_start` / `displink_put_sum` / `displink_check_sum` | |
| 0xFFF9C655 / 0xFFF9C667 | `mem_zero` / `displink_copy_if_changed` | `mem_zero` / `displink_copy_if_changed` | |
| 0xFFF96455 | `displink_build_status` | `displink_build_status` | fills the 0x97-byte status block at 0x16A1 |
| others | | `displink_rx_*`, `displink_tx_*`, `displink_build_*` | one per frame type, see the two frame tables (all proposed in the TSV) |
| 0xFFF9D94D / 0xFFFA1576 | `dsp_isp_request` / `sdr_bridge_request` | `dsp_isp_request` / `sdr_bridge_request` | set 0x1C63 / 0x1C8D |
| 0xFFFA0C79 | `dsp_isp_bridge` | `dsp_isp_bridge` | see above |
| 0xFFF95A64 / 0xFFF95ACE | `ui_numentry_step` / `ui_numentry_to_bcd` | `ui_numentry_step` / `ui_numentry_to_bcd` | ±step on 0x25D3C (0..99,999,999) and BCD copy to +0x7C..+0x7F |
| 0xFFFB2DA6 | `beep_request` | `beep_request` | 0x12041 = code, 0x12040 = pending **[inference]** |

Decompiler note: `displink_tx_req` shows `*(undefined2 *)(*(ushort *)(state+0x1E2) - 1)` and `dsp_isp_bridge` shows `*(undefined1 *)(len + 3)` as
memory loads. They are the known RX SLEIGH `MOVU.B/W Rs,Rd` bug (a register zero-extend shown as a load), so read them as `len - 1` and `len + 3`
**[inference: matches the frame lengths]**.

## Globals

| Address | Size | Meaning |
|---|---|---|
| 0x20B04 | ~0x490 B | **UI state struct** shared by the link, keys and UI (reached through the pointers at 0x25D38…0x25D7C) **[fact]** |
| 0x20B04+0x36 = 0x20B3A | u8 | power-on flag (`app_main` waits for it) |
| 0x20B04+0x35 = 0x20B39 | u8 | power command sent in `0x7F` |
| 0x20B04+0x98 | u8 | link up |
| 0x20B46 | u8 | CAT disabled (F1 03) |
| 0x9E86 / 0xA08A | 0x204 B / u8 | SCI1 receive buffer / complete flag |
| 0x198F | ≤0x204 B | copy of the received frame being handled |
| 0x1456 / 0x1B628 | 0x24A B / u16 | TX frame / length (last frame sent, also the retry copy) |
| 0x1741 / 0x16A0 | 0x24A B / 0x98 B | staging buffers |
| 0x1B3CC..0x1B3D5 | u8 each | link flags (see the state diagram) |
| 0x1C63 / 0x1C8D | u8 | DSP-tunnel / SDR-bridge request |
| 0x25D3C | u32 | numeric-entry counter (boot code 4 mode) |
| 0x9DC5 | u8 | "power-up allowed after a DISPLAY restart" (see boot code 0x10) **[inference]** |
