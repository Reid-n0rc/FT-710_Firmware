# T11c — DISPLAY SD card and firmware update paths

**Status:** in progress · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/update.md`: SD/FAT stack summary, SFL decode/CRC, self-update to the SPI-flash banks, MAIN update over RX boot mode, IFDSP update, SDR flash over SPI, hidden debug commands (`sdrup`, `dsp1up`, `uptest2`, ...) and their entry path. Figures: sequenceDiagram per update target, flash layout.

## Plan
T11c agent (worktree branch), 2026-10-27. Ghidra copy `ghidra/FT710_DISPLAY_T11c` for xrefs/listings only (shared project untouched).

1. Map the GUI update path: the four update objects built by `FUN_2010dd24` (C++ classes, vtables in `.rodata` 0x20428070–0x204280A0),
   their `run(check_only)` methods, the file scan (`fwfile_check_versions`, `fwfile_status_text`), `task_fwupdate` and the screens that drive it.
2. Read every acceptance check: `sfl_read_header` 0x20114CA0 (tag, length, CRC), file-size checks, version text, `#UP0` / `:` handling, the
   0xAA-frame requests to MAIN (`FUN_2010e514`), bank selection.
3. Per target: MAIN (RX boot mode, `FUN_2010d50c` and the GPIOs), IFDSP (`FUN_2010b81c`, RT685 ISP), SDR (`sdr_flash_write` + `sdr_spi_xfer_block`,
   reconcile with T13), DISPLAY (`FUN_201607e8`, `update_display_self`, `display_flash_write_bank`, flags 0x183E0000/0x183F0000, `loader_selfinstall`).
4. Debug paths: chain-1 handlers (`fwdbg_*`, `uptest`, `dspup`, `sdr_debug_cmd`, `FUN_20110da8`, `FUN_2010a8f8`), `task_sdmenu` / `sfl_load_file`.
5. Find who writes 0xFCFF400C (literal/immediate scan + Ghidra xrefs).
6. Write `docs/code/display/update.md` (function tables, globals, structures, sequence diagrams per target, flash layout, failure behaviour);
   names in `tools/ghidra/names_display.T11c.tsv`, missed entries in `tools/ghidra/entries_display.T11c.tsv`; shared-file edits proposed below.

## Findings
WIP notes (2026-10-27, to be moved into docs/code/display/update.md):
- Update objects (C++): `FUN_2010dd24` builds 4 at 0x2081166C: MAIN vtbl 0x20428088 run `FUN_201605ac`, DISPLAY 0x204280A0 `FUN_201607e8`,
  IFDSP 0x20428094 `FUN_201606bc`, SDR 0x20428070 `FUN_201602ac`; base ctor `FUN_201604f4`. run(obj, path, do_write).
- `sfl_read_header`: 9x64 B blocks, tag line strlen must be 64, strtok " " x3, 3rd token hex8 == salted CRC. Tag and length NOT checked.
  Copy of block 3 ([PRODUCT NAME]) used by DISPLAY: " : " then "#UP0    " -> loader write, only if USB-kbd key usage 0x3A (F1) held (DAT_20800181).
- File scan: I:\FT-710, FAT attr ARCHIVE required, name = prefix + 4 chars + ".sfl" (case-insensitive), highest name wins.
- SDR: file size must be 0x43075A exactly. Control via SCIF5 to MAIN (F1 01 / F1 81, ASCII reg frames FD "%04X%04X", FE "%04X"), data over RSPI ch2
  (FUN_2011f718(2,..)), 0x218 blocks of 4 KiB at 0x240000+i*0x1000, header block last at index 0x240, CRC-16 (0xA001) vs reg 0x33.
- IFDSP: F1 02 / F1 82 to MAIN, NXP blhost frames wrapped 5A len16 .. sum8: ping, fill 0x1C000=0xC0000002, configure-memory 9, erase 0x08000000+0xA0000, write 256 B.
- MAIN: RX boot mode at 9600 then 345600 (cmds 00/55, 38, 36, 32 16MHz/120MHz, 34, 00, 2C, 30 ID=FFx16, 53, 54, 50 erase, 13 write, 15/52 read-back verify), then reset, F0 frame.
- DISPLAY: write non-running bank, flag {0x11111111,len,0,0,~crc32(plain)}, erase other flag; F1 03 / F1 83. Boot does not check CRC; bank 1 wins.
- 0xFCFF400C: no writer in image; loader_selfinstall ends in BKPT #0..4 -> JTAG factory script.
- Dead code: dspup_init no caller; SDR debug flag 0x208001B8 no waiter; uptest programmer FUN_2010ea74 is a stub.
- display_flash_write_bank actually verifies bank 1 against a file (fw1chk); FUN_2015f348 = fw1up writer; task entry 0x2015F0E0 missing.

## Status
