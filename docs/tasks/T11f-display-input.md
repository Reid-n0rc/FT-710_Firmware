# T11f — DISPLAY input (touch, keys, encoders, USB HID)

**Status:** done · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/input.md`: TSC2003 touch over RIIC and calibration, front-panel keys and encoders, USB-host keyboard/mouse, how input events reach the GUI and MAIN.

## Plan
2026-10-27, T11f agent (worktree branch). Ghidra copy `ghidra/FT710_DISPLAY_T11f` (exploration only); names proposed in
`tools/ghidra/names_display.T11f.tsv` (missed entries in `entries_display.T11f.tsv`), the parent applies them and re-exports `decomp/display/`.

1. Read the decomp (`decomp/display/*.c`) of the named starting points: `key_init`/`task_key`/`key_scan_first`, `FUN_201131a8`, `renc_init` and the
   three encoder tasks, `touch_init`/`task_tsc2007*`, `touch_calibration`, `riic_init`, `keycode_init`/`task_keycode`, `mouse_cursor_init`,
   `usbkbd_report`, `hid_line_edit`, `powon_*`, the debug gate. Follow callees/callers one or two levels.
2. Keys: GPIO/ADC lines per scan, debounce, key → code table (dump `.rodata` tables with python), how a code is sent (MAIN-link command id, cross-ref
   T11b `mainlink.md` / MAIN T10b).
3. Encoders: GPIO phase decode, ADC "ad renc", "detect renc", step/acceleration constants, the event sent to MAIN.
4. Touch: RIIC/TSC2003 commands, IRQ (TINT), filtering, calibration math and where the constants are stored; the GUI hand-off.
5. USB HID: keyboard report path, VK names, the mouse cursor task; full debug console: both chains, every registered handler, every
   `fwdbg_cmd`/`cli`/`keycode` command, unlock condition, what T16 must patch.
6. Write `docs/code/display/input.md` (tables, globals, Mermaid figures, [fact]/[inference] (or an open question; the former guess tag is retired)); propose names; commit.

## Findings
Page: [docs/code/display/input.md](../code/display/input.md). 111 name proposals in `tools/ghidra/names_display.T11f.tsv`, 3 missed entries in
`tools/ghidra/entries_display.T11f.tsv` (0x201127D4, 0x20112830, 0x2015F0E0). The names were not applied to a Ghidra project (only the decomp and
raw image were used).

- **Key codes are MAIN's key codes** [fact]: MAIN has a name table at 0xFFF883C4 (`{u16 code, char[10]}`). The DISPLAY keys map 1:1. 6 direct
  GPIO keys (LOCK/PWR 0x300 on P2_0/IRQ5, TUNE, MOX/VOX, FUNC, DSP, MIC FAST), MIC PTT (P10_5, handled separately), a 4x4 matrix (13 keys) and a
  2-channel ADC ladder on AN3/AN4 (MIC UP/DOWN/MUTE/P1-P4 plus 16 unnamed codes 0x343-0x358, whose source is open: no MAIN code references 0x343-0x358 [fact, grep of decomp/main]; would be settled by the schematic of a 16-key keypad microphone, or by logging E0 frames while pressing such a mic's keys with the owner's approval).
- Key frame `E0 state hi lo 00` (1 press, 0 release, 2 held 1 s); one key at a time; 3-sample debounce at 1 ms [fact]. Holding LOCK/PWR 1 s
  switches standby to full or sets the shutdown flag 0x20800493 [fact].
- **Boot key combinations** 1-7 (table 0x20165678) go to MAIN in the power-up frame `F0 01 08 20 23 06 29 n 00` [fact]. Combo 4 (MODE+SPLIT)
  turns on an on-screen SDR-SPI test mode, combo 6 (DNR+A/B+QMB) a special boot-info state 2 mode [fact for the code].
- Encoders: MTU2 ch1 (phase mode 1) and ch2 (mode 4) polled every 8 ms, a third on IRQ4 (+-1 per edge), 2 pots on AN0/AN1. Raw deltas in E1
  frames, no acceleration on DISPLAY [fact]; knob identity is an inference.
- Touch: TSC2003 at 0x48 on RIIC2, TINT = IRQ3, fixed raw→pixel mapping plus an affine correction from a least-squares 5-point calibration (screen
  0x7C) stored at SPI flash 0x3D0000 (magic 0xA5C30001, CRC-32) [fact]; pressure gate R < 1300 Ω.
- USB: keyboard text entry with 11 layouts (KEYBOARD LANGUAGE), mouse cursor task, wheel → encoder ids 6/2/3 by screen [fact].
- **Debug console** fully documented: slots 0/1/3/5/7/8 of chain 1, every command (up0/up1/up2/fw1up/fw1chk, uptest/uptest2/mrst/rf0/rf1, cli,
  F1-F12 + date/time/dsp/reset/wdr/sndc, the SDR commands, the keyboard test). Output is only the keyboard LEDs. `dspup_init` has no caller, so
  `dsp1up`... are unreachable even with the gate open. The gate patch for T16 is 1 byte: 0x201110AC `movne r0,#0` → `#1` (file offset 0x110AC).

## Proposed shared-file edits
- `tools/ghidra/names_display.tsv`: merge `names_display.T11f.tsv`. It renames two existing entries: 0x201033E8 `intc_irq_setup` →
  `tsc2007_tint_isr` (it is the IRQ3 ISR of the touch task) and 0x2015F1F0 `display_flash_write_bank` → `display_flash_verify_bank1` (it compares,
  it does not write). Coordinate with T11c, which may name the same update functions.
- `tools/ghidra/entries_display.tsv`: append the 3 lines of `entries_display.T11f.tsv`.
- `docs/code/display/README.md`: set the input.md row to done. Correct the key finding: the chain has 6 registered handlers (slots 0, 1, 3, 5, 7, 8),
  the DSP commands are not registered (`dspup_init` has no caller), and the console output is the keyboard LEDs.
- `docs/code/display/boot-rtos.md`: in the chain figure, H7 is `sdr_debug_cmd` (SDR commands, not a guess) and H8 is the keyboard-test handler.
  `boot_mode_full`'s "key line 6" is boot key combination 6 = DNR + A/B + QMB.
- `docs/hardware.md` (DISPLAY): key matrix rows P7_13–P8_0, columns P8_1/P8_2/P8_7/P8_8; direct keys P2_0, P3_0, P3_6, P8_15, P9_1, P10_5, P10_6;
  ADC AN0/AN1 pots, AN3/AN4 mic keys; MTU2 ch1/ch2 encoders, IRQ4 encoder on P3_3/P3_5; TSC2003 at I2C 0x48 on RIIC2.
- `docs/custom-firmware.md` / T16: the 1-byte gate patch and the options table in input.md ("Enabling it").

## Follow-ups
- T10b: the MAIN handlers of E0/E1/E4/E5/F0 and the boot combinations; which encoder id is which knob, which pot is AF.
- T11b: the E1 ack that clears 0x2045002A, the queue used by `dsp_queue_frame`, the `sndc` replay.
- T11c: `rf0`/`rf1` and the uptest flags; boot combination 6 mode.

## Status
- 2026-10-27: done (page, 111 names, 3 entries).
