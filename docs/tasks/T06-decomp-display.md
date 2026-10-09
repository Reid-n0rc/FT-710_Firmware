# T06 — Decompile DISPLAY

**Status:** done (2026-10-09) · **Depends on:** T01 T02 T04

## Goal
Same as T05 for the PANEL/DISPLAY image → `decomp/display/`.

## Deliverables
Same as T05 (memory-maps DISPLAY section, `decomp/display/` + INDEX.md).

## Notes / hints
- Reuse the T05 scripts. At 3.3 MB this image probably contains GUI assets (fonts/bitmaps), so map them in docs rather than decompiling them.

## Plan
1. Survey the raw image (vector table, startup, code/data split) with `llvm-objdump` on an ELF wrapper and small Python scans. Do not read whole dumps.
2. Decode the armcc scatter-load table to get the real .data/.bss layout, and re-implement `__decompress` so the RW regions are initialized in Ghidra.
3. `tools/ghidra/DisplaySetup.java` (preScript at import): split the image into `.text` / `.rodata` (not exec, holds the GUI assets) / `scatter_init`,
   create the RW/ZI blocks, the rest of RAM, the RAM mirror, the SPI-flash window and the RZ/A1H I/O blocks (volatile), and seed the vectors and startup functions.
4. Auto-analysis (`-analysisTimeoutPerFile 3600`), then `tools/ghidra/DisplayFindCode.java` for missed code (pointer tables, prologues, orphan runs).
5. Name the notable functions (`tools/ghidra/names_display.tsv` via the shared `ApplyNames.java`), export with `ExportDecomp.java decomp/display 50`, and write
   `decomp/display/INDEX.md`, the DISPLAY section of `docs/memory-maps.md`, and this file.

### Reproduce
```sh
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -import build/FT-710_DISPLAY_V0108.bin -overwrite \
  -processor ARM:LE:32:v7 -loader BinaryLoader -loader-baseAddr 0x20100000 \
  -scriptPath tools/ghidra -preScript DisplaySetup.java -analysisTimeoutPerFile 3600
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis \
  -analysisTimeoutPerFile 3600 -scriptPath tools/ghidra -postScript DisplayFindCode.java      # run twice; 2nd run finds 0 new
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis \
  -scriptPath tools/ghidra -postScript ApplyNames.java tools/ghidra/names_display.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly \
  -analysisTimeoutPerFile 3600 -scriptPath tools/ghidra -postScript ExportDecomp.java decomp/display 50
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly \
  -scriptPath tools/ghidra -postScript DisplayReport.java <outdir>     # blocks/strings/io_refs TSVs
```
Each step takes under 1 minute on the M-series host. Auto-analysis took about 17 s.

## Findings
- **Language `ARM:LE:32:v7`, base 0x20100000** **[fact]**. Toolchain: **armcc (ARM Compiler 5) with C++** (`__scatterload`, `Region$$Table`, LZ `__decompress`,
  `SIGPVFN: Pure virtual fn called`). The code is mostly A32. Thumb-2 appears only in the armcc runtime, libc and fplib.
- **Layout** **[fact]**: `.text` 0x20100000–0x20165177 (≈405 KB), `.rodata` 0x20165178–0x204286A7 (≈2.8 MB, almost all GUI bitmaps), Region$$Table 0x204286A8 plus
  three LZ streams up to the file end. RW/ZI: `.data` 0x20450000 (0x290), `.data_nc` 0x60500000 (0x48A0, uncached mirror), `.data2` 0x20800000 (0x8BD0),
  `.bss` 0x20450290 (0xAC364), `.bss2` 0x20808BD0 (0x1149A0). Stacks below SP 0x2044C000. The full table is in docs/memory-maps.md.
- **The image is both the boot loader and the application** **[fact for code, inference for purpose]**. `boot_select_bank` (0x20100ABC) runs on the first stage only
  (marker in SPIBSC1 register 0x3FEFB018), reads bank flags at flash 0x183E0000/0x183F0000 (0x11111111 + valid word), and jumps to
  bank 1 at 0x18400000 or bank 2 at 0x18A00000. A boot-info block is kept at 0x20000000. Self-update writes `I:\AH076H_DISPLAY.bin` to a bank
  (`update_display_self`, `display_flash_write_bank`). The flash layout (loader at 0x18000000, flags at 0x3E0000/0x3F0000, banks at 0x400000/0xA00000 of the
  16 MB W25Q128) is worth confirming in T11.
- **RTOS:** a µITRON 4.0-style kernel (acre_tsk/sta_tsk/dly_tsk/acre_sem/acre_flg/set_flg/twai_flg, standard ITRON error codes). The vendor is not identified.
- **MAIN link:** UART objects for SCIF3/4/5. The command task (`mainlink_init`, `cmd_interval_sem`) uses **SCIF5 (0xE8009800)**, and `mainlink_send_cmd`
  frames commands from a 43-entry table at 0x20450074. Received commands can be logged to `I:\FT-710\DEBUG_RECV_CMD\RECV_CMD.TXT`.
- **The DISPLAY CPU updates the other CPUs** **[inference from strings and code]**: MAIN RX651 from `I:\AH076H_HEW.mot` (`update_main_cpu`), DSP from `I:\AH076H_IFDSP.dat` /
  `rom_writer.dat` (`update_dsp`), and SDR FPGA flash over SPI (`sdr_flash_write`, debug commands `sdrup`…`sdrfile` in `sdr_debug_cmd` 0x20110C3C, which
  answers the T08 lead). It also has hidden debug commands (`dsp1up`…, `uptest2`, `reset`, `delta`). How they are entered (USB keyboard? FT4222 SPI?) is open.
- **CRC:** `sfl_crc` uses a standard reflected CRC-32 (table built by 0x20100A14, poly 0xEDB88320). No 0x04C11DB7 (MSB-first) constant or table is in the image.
- **GUI:** six 800×480 RGB565 frame buffers in the uncached mirror (0x60000000 + n·0xBB800, plus 0x605048A0), VDC5 output, TSC2003 touch with calibration,
  BMP screen capture to SD, and USB-host HID (keyboard VK_ names, mouse cursor). Assets are mapped in docs/memory-maps.md (`.rodata` is a
  non-exec block, so it is not disassembled; one stray instruction at 0x20165178).
- **Export:** 2077 functions (2041 exported, the remainder are thunks), **0 decompile failures**. 79 named. `.text` coverage is about 95% instructions. 304 strings are defined by Ghidra
  (many UI strings in `.rodata` are not yet defined as strings).

## Follow-ups
- T11: trace the MAIN-link protocol (SCIF5 frame format, the 43-entry command table at 0x20450074, the RX side) and the RSPI users (SDR, DSP, FT4222).
- T11: decode the sprite/descriptor format and find the font tables in `.rodata`. Consider defining the `.rodata` UI strings and the bitmap descriptor structs.
- T11: confirm the SPI-flash layout (loader, bank flags, banks) and how the SFL DISPLAY image maps onto `AH076H_DISPLAY.bin` / `AH068_DISPLAY_Loader.bin`.
- Identify the RTOS vendor (task/semaphore control-block layout) and apply the ITRON names project-wide.
- Find how the debug commands (`sdrup`, `dsp1up`, …) are entered. An MSB-first CRC for the SDR header was not found; recheck bitwise CRC loops in `sdr_*`.
- About 2.7 KB of unreferenced code fragments in `.text` (switch-case targets reached through computed branches) remain undefined.

## Status
Done on 2026-10-09. Deliverables: `decomp/display/` (41 `.c` files + `functions.tsv` + `INDEX.md`), the DISPLAY section in `docs/memory-maps.md`, and the scripts
`tools/ghidra/DisplaySetup.java`, `DisplayFindCode.java`, `DisplayReport.java` and `names_display.tsv`. The Ghidra project is `ghidra/FT710_DISPLAY` (gitignored).
Not committed by this agent (the parent commits).
