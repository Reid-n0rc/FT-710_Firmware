# T11e — DISPLAY GUI and LCD

**Status:** done · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/gui.md`: VDC5 setup, frame-buffer layers, drawing primitives, sprite descriptors and fonts in `.rodata`, screen/menu framework and screen table, screen capture.

## Plan
T11e agent, 2026-10-27 (worktree branch). Approach:
1. Start from `gui_start` 0x20132CCC, `fb_clear_all`, `gui_update_layers`, `vdc5_config`, `test_disp_init`/`task_test_disp` and the T06 GUI names;
   walk callers/callees in `decomp/display/` and with a private Ghidra copy `FT710_DISPLAY_T11e` (xrefs, listings).
2. VDC5: decode the register writes (ch0 0xFCFF7400.., ch1 0xFCFF9400..), layer/frame-buffer assignment, LVDS and the DVI/external output path.
3. Drawing primitives and widget/toolkit: classify the most-called GUI functions (rect fill/copy, runs, text, bitmap blit).
4. Screens: find the screen/page dispatcher (state variable, screen table, menu tree), draw a `stateDiagram-v2`; hunt hidden/service screens
   (test display, touch calibration, version/serial, factory screens).
5. Assets: characterise the `.rodata` bitmap/sprite descriptors, fonts and string tables; if regular, write `tools/display_assets.py`
   (stdlib, lists assets only, extracts nothing into the repo).
6. Write `docs/code/display/gui.md` (T11a conventions), propose names in `tools/ghidra/names_display.T11e.tsv` (and missed entries in
   `entries_display.T11e.tsv`), list shared-file edits below, commit.

Original plan text: find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings
Page: [docs/code/display/gui.md](../code/display/gui.md). Tool: `tools/display_assets.py` (stdlib, lists sprites/tables/fonts/strings, extracts nothing).
Names: `tools/ghidra/names_display.T11e.tsv` (105 proposals). No missed function entries were needed.
- The GUI is a thin renderer: MAIN sends screen packets (byte 0 = screen ID, lengths in the 26-entry table 0x2080893C); `FUN_2012EBB8`
  diffs them against 0x208F0B2A and dispatches. 25 IDs identified (main, popups, FUNC, VFO, play list, menu, memory list, SD, keyboard, info,
  confirm, screen saver, capture, touch calibration, RTC set, display settings) [fact for dispatch, inference for names].
- Renesas `r_vdc5` driver. ch0 = TFT (P1φ/2, 1016×525), ch1 = LVDS → DVI (LVDS PLL from 27 MHz, 800×480 1088×517 or 800×600 1056×628, ~60 Hz),
  both reading the same 4 layers: background, two double-buffered blend layers with black chroma key, 12×21 cursor [fact].
- Assets: 2243 run sprites (u16 w, u16 h, u32 nruns, runs*, pix*), 2 MB of RGB565; fonts are per-colour sprite tables through the char map
  0x2080173C [fact].
- Hidden/service: packet 0x64 LCD test patterns; power-on key combo 6 → boot-loader screen, combo 4 → SDR SPI testmode counters (no unlock);
  F1–F12 debug overlays and the `test_disp` replay of `I:\FT-710\DEBUG_RECV_CMD\SEND_CMD.TXT` (both need the debug unlock) [fact].
- Screen capture writes a 24-bit bottom-up BMP merged from graphics 0–2 front buffers [fact].

## Follow-ups
- T11f: name the key codes 0x303–0x311 so the power-on combos 4 and 6 get physical key names.
- T10 (MAIN): find what sends DISPLAY packets 0x64 (LCD test) and 0x34 (info/certifications).
- T11c: `fwupdate_screen` (0x201322B4) and `FUN_201322AC`…0x201322F0 are tail-call thunks into an update-UI object at 0x208F4BF4
  (targets 0x20159714, 0x2015AFB0, 0x201595F0, 0x2015A500, 0x2015A8DC, 0x20159058, 0x20159D98); Ghidra shows the target bodies under the
  thunk names. The real `fwupdate_screen` is 0x20159714.
- Decode the `.data2` coordinate tables into a full screen layout.

## Proposed shared-file edits
- `tools/ghidra/names_display.tsv`: merge `names_display.T11e.tsv`; it renames `fb_copy_rect` → `fb_clear_rect`, `screen_shot_menu` →
  `screenshot_popup`, `debug_recv_cmd_log` → `test_disp_replay`. Then re-apply and re-export `decomp/display/`, and switch the italic names in gui.md.
- `docs/code/display/README.md`: GUI row status → done; block diagram "6 RGB565 layers" → "6 RGB565 buffers, 4 VDC5 layers"; add key finding
  "GUI is driven by MAIN screen packets; LCD test packet 0x64; power-on key combos 4/6".
- `docs/memory-maps.md` (DISPLAY, GUI assets): replace the descriptor guess with the run-sprite format (16-byte descriptor
  {u16 w, u16 h, u32 nruns, runs*, pix*}, pixels follow the runs), 2243 sprites, fonts via char map 0x2080173C, and point to `tools/display_assets.py`.
  Frame buffer list: fb5 is 0x602EE000 (cursor), the 6 buffers are fb0 0x600BB800, fb1 0x605048A0, fb2 0x60177000, fb3 0x60000000, fb4 0x60232800.
- `decomp/display/INDEX.md`: `fb_copy_rect` note → clears to 0; `screen_shot_menu` → popup.
- `docs/tooling.md`: add `tools/display_assets.py`.

## Status
- 2026-10-27: T11e done (gui.md, display_assets.py, 105 name proposals).
