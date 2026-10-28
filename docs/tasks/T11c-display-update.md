# T11c — DISPLAY SD card and firmware update paths

**Status:** done · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

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
Deliverable: [docs/code/display/update.md](../code/display/update.md). Names: `tools/ghidra/names_display.T11c.tsv` (99 proposals),
missed entry: `tools/ghidra/entries_display.T11c.tsv` (task entry 0x2015F0E0). Helper: `tools/ghidra/XrefsList.java` (read-only xref dump).

- **Acceptance checks** [fact]: only the salted CRC in the tag line (3rd space-separated token, line must be 64 chars). Tag and length fields are
  not checked. File name `FT-710_<IMG>_V` + 4 chars + `.sfl`, case-insensitive, ARCHIVE attribute, highest name wins. SDR needs file size exactly
  0x43075A. DISPLAY needs size >= 0x242. No signature/model/destination checks. Boot needs only `{0x11111111, len != 0}` in a bank flag.
- **MAIN**: RX boot mode on SCIF5 (9600 → 345600), ID code 16 × FF, erase, write 512 B blocks, full read-back compare, reset, `F0` hello frame.
- **IFDSP**: `F1 02` to MAIN, then NXP blhost packets through a `5A len sum` relay: fill 0x1C000 = 0xC0000002, configure-memory 9, erase
  0x08000000 + 0xA0000, write 256 B; no read-back.
- **SDR**: `F1 01` starts MAIN's bridge; FPGA regs 0x30/0x31 (address), 0x32 (cmd/status), 0x33 (CRC-16 0xA001) via `FD 00`/`FE 00` frames;
  the 4 KiB data blocks go over **RSPI2 (SDR SPI / FFT pins)**; body at 0x240000.., header block last at 0x480000. Resolves T13; `SDR_UPDATE`
  acts as an FPGA update-mode input rather than a plain flash WP [inference].
- **DISPLAY**: writes the non-running bank, flag `{11111111, len, 0, 0, ~CRC-32(decoded)}`, then erases the other flag; `F1 03` / `F1 83` to MAIN.
  Loader-region write (offset 0, flag 0x3C0000) when the product field is `#UP0` and F1 is held on a USB keyboard, or in key-6 power-on mode
  after > 4 encoder steps ("BOOT LOADER V01-02").
- **0xFCFF400C**: no writer in the image; `loader_selfinstall` ends in `BKPT #0..4` → set by a JTAG factory script [inference, high].
- **Dead debug paths** [fact]: `dspup_init` has no caller; SDR debug flag 0x208001B8 has no waiter; the uptest programmer `FUN_2010ea74` is a stub.
  `display_flash_write_bank` is really the `fw1chk` verify loop; `FUN_2015f348` is the `fw1up` writer. Chain-1 handler 8 (`FUN_2010a8f8`) is a
  keyboard-layout translator.
- The radio has its own SFL writer/encoder for MemList/Menu backups (`FUN_2010f370`, `FUN_201149e0`), a reference for the T16 encoder.

## Proposed shared-file edits
- `tools/ghidra/names_display.tsv`: merge `names_display.T11c.tsv`; **rename** `display_flash_write_bank` 0x2015F1F0 → `fwdbg_verify_bank1`
  (it compares, never writes). Also apply `entries_display.T11c.tsv` (0x2015F0E0) with `FixFuncEntries.java`, then re-export `decomp/display/`.
- `docs/code/display/README.md`: mark update.md done; Key findings: add "SFL acceptance = CRC only; SDR data over RSPI2 with control through
  MAIN; loader_selfinstall is a JTAG/BKPT factory path".
- `docs/code/display/boot-rtos.md`: chain-1 H7 = `FUN_20110da8` SDR commands (dead, no waiter), H8 = keyboard layout translator; the
  self-update task entry is 0x2015F0E0; who sets 0xFCFF400C → JTAG (see update.md §6).
- `docs/custom-firmware.md`: replace blocker 4 with the check list from update.md §1; SDR row of "Update and recovery paths": DISPLAY sends the
  bitstream over the SDR SPI (RSPI2) while MAIN bridges register commands; DISPLAY: no CRC check at boot; recovery via key-6 maintenance mode and
  the JTAG `loader_selfinstall` path.
- `docs/code/sdr/interfaces.md`: update the configuration/update sequence diagram with regs 0x30–0x33, the 0x240000 / 0x480000 addresses and
  the SPI data path; reword the `WP` inference.
- `docs/sfl-format.md`: note that the radio checks only the CRC token (not tag/length) and that backups (MemList/Menu) use the same container
  with a blank comment box.

## Follow-ups
- MAIN side of `F1 02` (IFDSP relay) and of the 0xC3/0xE2 UI frames.
- FPGA reg 0x32 command meanings and slot layout (T15).
- Key line 6 and the P3_3/P3_5 encoder identity (T11f).

## Status
- 2026-10-27: T11c done.
