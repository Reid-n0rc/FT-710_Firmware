# T11f — DISPLAY input (touch, keys, encoders, USB HID)

**Status:** in progress · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

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
6. Write `docs/code/display/input.md` (tables, globals, Mermaid figures, [fact]/[inference]/[guess]); propose names; commit.

## Findings

## Status
