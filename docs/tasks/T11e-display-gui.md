# T11e — DISPLAY GUI and LCD

**Status:** in progress · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

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

## Status
