# decomp/display — FT-710 DISPLAY (V01-08) Ghidra export

Source: `build/FT-710_DISPLAY_V0108.bin` (RZ/A1H Cortex-A9, `ARM:LE:32:v7`, base 0x20100000). The memory map is in
`docs/memory-maps.md` (DISPLAY), and the method and findings are in `docs/tasks/T06-decomp-display.md`.

## Export stats
- Ghidra 12.1.4 project `ghidra/FT710_DISPLAY`. Pipeline: `DisplaySetup.java` (preScript) → auto-analysis → `DisplayFindCode.java` (pointer-table,
  prologue and orphan-code passes) → `FixFuncEntries.java tools/ghidra/entries_display.tsv` (T11) → `DisplayJumpTables.java apply` → `DisplayGaps.java <starts.tsv> <fragments.tsv> .text define`
  (T21e) → `ApplyNames.java tools/ghidra/names_display.tsv` → `ExportDecomp.java decomp/display 50`. `tools/bootstrap.sh` runs these steps; the commands are below.
- T11 (2026-10-27): the project was rebuilt on the Linux host and the re-export matched the T06 commit byte for byte. `FixFuncEntries.java` then
  created 14 function entries that analysis had missed (RTOS task entries such as `task_root` 0x201170C8, which start with an `ldr` before the
  `push`, so the prologue pass had started them 4–8 bytes late or the previous function had swallowed them). Detailed docs: `docs/code/display/`.
- T17 (2026-10-27): `entries_display.tsv` and `names_display.tsv` now hold the merged T11a–g proposals (68 entries, 768 names; name conflicts
  resolved in `tools/ghidra/names_display.picks.tsv`, listed in `docs/tasks/T17-integration.md`). FixFuncEntries: 68 entries (re)created,
  8 late starts removed. **2087 functions exported** (thunks are skipped), **0 decompile failures**; 772 carry a name. Output: 42 `.c` files of
  50 functions each, about 81k lines (2.0 MB). Before T17: 2041 exported, 151 named.
- Code coverage of `.text` (0x20100000–0x20165177, 414,072 B): about 95% instructions and 4% data (literal pools, tables). About 2.7 KB of small
  unreferenced fragments remain undefined.
- T21e (#97 B6–B8; measured on a scratch rebuild; T21g rebuilt the canonical project with these steps and re-exported, identical to T21e's fresh rebuild, all 772 names kept): 86 ARM jump-table sites, all
  switches with every case (before: 80 of the 85 then disassembled; the five RSPI helpers `rspi_open/start/stop/reset_buffers/wait_tx_end` were not: they
  carried a RETURN flow override and stray references from a table guessed one word early). 137 new entries in
  `entries_display.tsv` (dead helpers after a return, tail-branch targets that analysis had merged into another function, one
  Thumb function reached from a .data table): 2210 functions exported (was 2087), 0 decompile failures, no call target inside a
  function body. Undefined non-0xFF bytes in `.text`: 4,258 → 242 (15 fragments, all in the armcc Thumb library: fplib code
  reached through inline-parameter calls, lookup tables). The other fragments are defined as data (`T21e B8:` EOL comments).
  Warning counts of the 2076 functions that exist before and after are unchanged; the 134 new functions add 46 warnings.
- T21j (#97, from T22d): the Thumb function in the `.data` table 0x2042807C starts at 0x2016385A (`movs r0, #0` first; T21e's
  0x2016385C lost that argument); `data_display.tsv` types the printf sign-prefix tables 0x20154B64/0x20154BE0 as `char[4][4]`
  (`""`, `"-"`, `"+"`, `" "`) and the fplib reciprocal seed table 0x20164C00 as `byte[128]`. Undefined non-0xFF bytes 242 → 86.
- #81 (2026-10-28): the update-UI thunks 0x201322AC..0x201322F0 (`ldr r0, =0x208F4BF4; b method`) had swallowed their targets,
  which were no functions: entries 0x2015AFB0, 0x20159714, 0x201595F0 added, `fwupdate_screen` / `fw_installed_versions_set` /
  `fwupdate_insert_sd_screen` moved to the real bodies (thunks named `*_thunk`); `mouse_cursor_run` starts at 0x2015FD60 (was a
  4-byte late start). `FixFuncEntries.java` now marks every unconditional branch from another function to a fixed entry as a tail
  call (145 branches): their targets are no longer inlined into the branching function. Functions 2,210 → 2,212, warnings 393 → 212
  (unreachable-block 267 → 147, both switch-labelling warnings 60 → 0); all 86 jump-table functions still decompile to a `switch`
  (the C has 89 `switch(` instead of 99: 10 were inlined copies).
- Rebuild commands (from the repo root; `tools/bootstrap.sh --only ghidra` runs the same steps):
  ```sh
  H="tools/ghidra-headless.sh $PWD/ghidra FT710_DISPLAY"; P="-process FT-710_DISPLAY_V0108.bin -noanalysis -scriptPath tools/ghidra"
  $H -import build/FT-710_DISPLAY_V0108.bin -overwrite -processor ARM:LE:32:v7 -loader BinaryLoader -loader-baseAddr 0x20100000 \
     -scriptPath tools/ghidra -preScript DisplaySetup.java -analysisTimeoutPerFile 3600
  $H $P -analysisTimeoutPerFile 3600 -postScript DisplayFindCode.java      # twice
  $H $P -postScript FixFuncEntries.java tools/ghidra/entries_display.tsv
  $H $P -postScript DisplayJumpTables.java apply /tmp/jumptables.tsv
  $H $P -postScript DisplayGaps.java /tmp/gaps_starts.tsv /tmp/gaps_fragments.tsv .text define
  $H $P -postScript ApplyNames.java tools/ghidra/names_display.tsv
  $H $P -readOnly -postScript ExportDecomp.java decomp/display 50
  # tests (read only): every jump-table site a full switch; no call target inside a body; remaining fragments
  $H $P -readOnly -postScript DisplayJumpTables.java check -postScript DisplayGaps.java /tmp/starts.tsv /tmp/fragments.tsv
  ```
- `functions.tsv` lists entry, name, size, reference count, and file for every exported function.
- [`readable/`](readable/README.md): the same functions grouped by subsystem page, with the docs' name, purpose and tag per function (generated by `tools/readable_view.py`, T23g; never edit by hand).
- File names are `<first entry>_<last entry>.c`. The first file starts with two stub "functions" at 0x18400000/0x18A00000. These are the
  jump targets into the flash banks, not real code in this image.

## Decompile quality (`quality.tsv`)
Counts that `tools/ghidra/ExportDecomp.java` writes to `quality.tsv` in the same decompile pass as the `.c` files (T21f, #97 B11). `tools/bootstrap.sh verify` fails if any count is higher than in the committed file, so a gap cannot come back unnoticed after a re-import. Lower is better for every row except the function count. Warning kinds are the decompiler's `WARNING:` comments with addresses and numbers replaced by `#`. Regenerate the table with
`python3 -I tools/decomp_quality.py index decomp/display/INDEX.md DISPLAY=decomp/display/quality.tsv`.

<!-- quality:begin -->
<!-- generated by tools/decomp_quality.py index from quality.tsv (ExportDecomp.java); do not edit by hand -->

| Metric | DISPLAY |
|---|---:|
| Functions exported (non-thunk) | 2,212 |
| Decompile failures | 0 |
| Decompiler warnings (all kinds) | 212 |
| Functions with a warning | 68 |
| "Unable to track spacebase" | 0 |
| "Removing unreachable block" | 147 |
| `halt_baddata()` calls | 4 |
| Functions with `halt_baddata()` | 4 |
| Functions with `in_*` variables | 62 |
| Functions with `unaff_*` variables | 44 |
| Functions with `extraout_*` variables | 78 |
| Functions with any of `in_`/`unaff_`/`extraout_` | 166 |
| Undefined non-0xFF bytes in executable blocks | 86 |
| … in block `.text` | 86 |
| Error bookmarks | 1 |
| "Bad Instruction" bookmarks | 1 |
| warning: Bad instruction - Truncating control flow here | 4 |
| warning: Control flow encountered bad instruction data | 4 |
| warning: Could not recover jumptable at #. Too many branches | 17 |
| warning: Do nothing block with infinite loop | 6 |
| warning: Globals starting with '_' overlap smaller symbols at the same address | 12 |
| warning: Removing unreachable block (#) | 147 |
| warning: Treating indirect jump as call | 17 |
| warning: Type propagation algorithm not settling | 5 |
<!-- quality:end -->

## Notable functions
Names are **[inference]** unless noted. "File" is the export file that holds the function.

### Startup / runtime
| Address | Name | Notes | File |
|---|---|---|---|
| 0x2010002C | `Reset_Handler` | Vector 0. Relocates the image to 0x20100000 if it runs elsewhere **[fact]** | 18400000_20100f64.c |
| 0x20100080 | `reset_in_ram` | SPIBSC0 init, bank select, copies the rest of the image **[fact]** | 18400000_20100f64.c |
| 0x20100ABC | `boot_select_bank` | Flags at 0x183E0000/0x183F0000 → calls 0x18400000 or 0x18A00000. Uses SPIBSC1 reg 0x3FEFB018 as a "stage ran" marker **[fact]** | 18400000_20100f64.c |
| 0x20100828 | `spibsc0_init` | SPI flash controller setup | 18400000_20100f64.c |
| 0x20100BC8 / 0x20100BFC / 0x20100C60 | `__scatterload` / `__decompress` / `__scatterload_zeroinit` | armcc runtime **[fact]** | 18400000_20100f64.c |
| 0x20117294 | `main` | Called from `__rt_entry`. Creates the first task, then loops | 20116368_20117728.c |
| 0x201001D8 | `IRQ_Handler` | Calls the GIC dispatcher 0x201176B4 | 18400000_20100f64.c |

### RTOS (NORTi µITRON 4.0 kernel from MiSPO; string `NORTi(c)MiSPO` at 0x20156290 **[fact]**)
| Address | Name | Notes |
|---|---|---|
| 0x201500F4 | `itron_acre_tsk` | ITRON error codes (E_ID −18, E_NOID −34, E_NOEXS −42). TCB table at 0x208DBBA0 |
| 0x20151768 | `itron_sta_tsk` | |
| 0x20150740 | `itron_dly_tsk` | 163 callers |
| 0x2014FF2C / 0x2014E584 | `itron_acre_sem` / `os_create_sem_named` | Semaphores: `cmd_interval_sem`, `fat_sem`, `fsys_sem`, `mouse_cursor_sem`, … |
| 0x2014EFFC / 0x20150F00 / 0x20152988 | `itron_acre_flg` / `itron_set_flg` / `itron_twai_flg` | Event flags |

### SFL loader and CRC (firmware files on the SD card)
| Address | Name | Notes |
|---|---|---|
| 0x2011497C | `sfl_decode` | Byte-wise key subtraction (docs/sfl-format.md) **[fact, T04]** |
| 0x20114A64 | `sfl_crc` | Salted CRC-32 over the file. It uses `crc32_make_table` 0x20100A14 (reflected poly 0xEDB88320) and `crc32_update` 0x20100A5C **[fact]** |
| 0x20114A44 / 0x20114CA0 | `sfl_stream_init` / `sfl_read_header` | Reads the 0x40-byte header block. 0x20114AE0–0x20114C44 are the decoding read/write wrappers |
| 0x2010F81C | `sdmenu_load_file` | Reads an SFL file and decodes it |
| 0x2010DDD8 / 0x2010DFD0 | `fwfile_check_versions` / `fwfile_status_text` | Matches `FT-710_{MAIN,DISPLAY,IFDSP,SDR}_V` and shows `Ready` / `(Broken file)` / `(No such file)` |

### Firmware update of the other CPUs and of itself
| Address | Name | Notes |
|---|---|---|
| 0x2010EA90 | `update_main_cpu` | Opens `I:\AH076H_HEW.mot` (or `AH068H_HEW.mot`) and programs the RX651 over the boot-mode UART |
| 0x2010D92C / 0x2010DA78 | `update_dsp` / `dsp_debug_cmd` | `I:\AH076H_IFDSP.dat`, `I:\rom_writer.dat`, `I:\AH068_AFDSP_V0000.dat`. Commands `dsp1up`…`dsp3up/32/9` |
| 0x20110AB8 | `sdr_flash_write` | Writes the SDR (FPGA) image in 4 KiB blocks over RSPI2 (master) through `sdr_spi_xfer_block` 0x20110834, with FPGA regs 0x30–0x33 driven through the MAIN bridge (`docs/code/display/update.md`) |
| 0x20110C3C | `sdr_debug_cmd` | strcmp chain for `sdrup`, `sdr1up`, `sdr2up`, `sdrchk1`, `sdrup/g`, `sdr1up/g`, `sdr2up/g`, `sdrchk1/g`, `sdrchk2/g`, `sdrspi`, `sdrfile`, `delta`. It signals the worker through the event flag held in 0x208001B8 |
| 0x2015F62C | `update_display_self` | `I:\AH076H_DISPLAY.bin`, `I:\AH068_DISPLAY_Loader.bin` |
| 0x2015F1F0 | `fwdbg_verify_bank1` | Compares bank 1 (0x18400000) with the file; it never writes **[fact]** |
| 0x201322B4 / 0x2015938C | `fwupdate_screen` / `bootloader_screen` | Update UI (`STEP 1 of 2`, `DO NOT TURN OFF POWER`, `BOOT LOADER V01-02`) |

No MSB-first CRC-32 (poly 0x04C11DB7) constant or table is in the image. The only CRC-32 is the reflected 0xEDB88320 table generator. A bitwise
MSB-first CRC with the polynomial built from shifts cannot be ruled out (follow-up).

### UART link to MAIN (and other SCIFs)
| Address | Name | Notes |
|---|---|---|
| 0x201148B4 | `scif5_get` | UART object 0x208DB280 bound to **SCIF5 (0xE8009800)**. This is the MAIN link **[inference: the command task uses it; the pins match DISP_UMOSI/UMISO on P6_6/P6_7]** |
| 0x201148D8 / 0x201148FC | `scif4_get` / `scif3_get` | UART objects on SCIF4 0xE8009000 and SCIF3 0xE8008800 |
| 0x20162FAC | `uart_obj_init` | Stores the base address, buffers and mailboxes |
| 0x201163A0 | `mainlink_init` | Creates `cmd_interval_sem`, `cmd_waiting_sem` and tasks, and allocates a 0x103C0-byte context at 0x2045FD40 |
| 0x20116560 | `mainlink_inject_rx` | Looks up the length in the 43-entry {cmd, length} table at 0x20450074 (.data) and posts a saved frame to the RX dispatcher as if MAIN had sent it (redraws the previous screen) **[fact]** |
| 0x20115494 | `mainlink_queue_frame` | |
| 0x20134FDC | `debug_replay_send_cmd` | Task `test_disp`: replays `I:\FT-710\DEBUG_RECV_CMD\SEND_CMD.TXT` into the GUI snapshot ("fake MAIN"). The `RECV_CMD.TXT` writer `debug_log_recv_cmd` 0x201352E8 has no caller **[fact]** |

### SD card / FAT
| Address | Name | Notes |
|---|---|---|
| 0x201400D4 | `sdhi_init` | `SDINT_INI`. SDHI driver is at 0x201401DC–0x20140B9C (0xE804E000) |
| 0x20103B68 | `sd_task_create` | `sdTask` |
| 0x20148FCC | `fat_mount` | FAT12/16/32/exFAT detection. File system 0x20140998–0x2014E100 (`fat_sem`, `dir_sem`, `fsys_sem`, `FSYS Work`) |
| 0x20141ABC / 0x20142A58 / 0x2014367C / 0x20143750 | `fs_fopen` / `fs_fread` / `fs_fwrite` / `fs_fseek` | stdio-like API, drive `I:` |
| 0x2010FB90 / 0x20110034 | `sd_make_dirs` / `sd_info_screen` | `I:\FT-710\{Capture,MemList,Menu,PlayList,MESSAGE}`, FREE SPACE / CAPACITY |

### GUI framework / display
| Address | Name | Notes |
|---|---|---|
| 0x201326FC | `fb_get_layer_addr` | 6 frame buffers, 800×480 RGB565, in uncached RAM 0x60000000+, shown on 4 VDC5 graphics layers |
| 0x201355BC / 0x20135658 / 0x201358D0 | `fb_clear_rect` / `fb_fill_rect` / `gui_draw_runs` | Most-called GUI primitives (294 callers for `gui_draw_runs`). `fb_clear_rect` clears a rectangle to 0 (transparent, the chroma key) **[fact]** |
| 0x20133A8C | `gui_update_layers` | Selects the layer buffers and passes them to the VDC5 (0x20117E5C) |
| 0x2011A394 | `vdc5_config` | VDC5 ch0 registers |
| 0x20125E78 | `touch_calibration` | `TOUCH THE CROSS` |
| 0x20134644 / 0x2013059C | `screen_capture_bmp` / `screenshot_popup` | BMP writer (`I:\FT-710\Capture\20YYMMDD_HHMMSS.bmp`) / the capture popup (popup slot 44) that calls it |
| 0x2013B5BC / 0x2013B928 / 0x20107EFC | `usbh_create_objects` / `usbh_hid_init` / `vk_key_name` | USB host stack (`m596*`, `udevtsk%d`, `UHHID`): USB keyboard/mouse support |

### Peripherals
| Address | Name | Notes |
|---|---|---|
| 0x201177E4 | `ostm_init` | OSTM0 0xFCFEC000 (tick) |
| 0x20120224 | `riic_init` | RIIC 0xFCFEE000 (touch controller TSC2003 per hardware.md) |
| 0x201033E8 | `tsc2007_tint_isr` | IRQ3 ISR (touch TINT on P1_3, GIC 35): wakes the `tsc2007` IRQ task. Earlier named `intc_irq_setup` **[fact]** |
| 0x2011D9A8–0x2011F230 | `rspi_*` | RSPI0–4 driver, see "SPI links" below |

### SPI links (T11d, `docs/code/display/spi-links.md`)
The DISPLAY is the SPI slave on all three links (8-bit, SPI mode 1), each frame moved by DMA **[fact]**.

| Address | Name | Notes |
|---|---|---|
| 0x2011D9A8 / 0x2011F0CC / 0x2011F138 | `rspi_hw_config` / `rspi_open` / `rspi_start` | Table-driven RSPI driver (register table 0x20166B4C + n·0x2C). Master mode ≈ 2 MHz, slave otherwise |
| 0x20133484 / 0x20133440 | `sdr_dsp_link_init` / `link_ss_irq_init` | RSPI2 + DMA ch5 (SDR scope, 1700 B) and RSPI4 + DMA ch3/ch4 (IF DSP, 4600 B); frame-select ISRs on GIC 535 / 449 |
| 0x201330D4 / 0x201331DC | `sdr_rx_done_cb` / `dsp_rx_done_cb` | Frame complete: scope record / AF-FFT + 16 kHz stereo REC/PLAY PCM |
| 0x201342EC / 0x20120D40 | `scope_store_frame` / `afscope_store_frame` | 850-byte scope record 0x204832BB, 600-byte AF-FFT record 0x208DD73C |
| 0x20112450 / 0x20112288 | `spi_slave_init` / `task_spi_slave` | PC link over the FT4222H (RSPI0, DMA ch9 TX / ch10 RX, 4 KiB frames from 0x60501000) |
| 0x2011249C | `pclink_stats_print` | Test-mode statistics box (`CS_POLL`, `MOSI_OK/NG`, `FRAMES`), boot key combination 4 |
| 0x201107C0 | `sdr_spi_master_write` | RSPI2 switched to master for the SDR image (update) |
| 0x201376D0 / 0x201378B0 | `dmac8_m2m_init` / `dmac8_m2m_start` | DMAC **channel 8** (0xE8200400), memory-to-memory frame-buffer copy for the GUI, not SPI |

### Other string-referenced functions (unnamed, good T11 entry points)
- `wav_open_read`, `wav_list_dir`, `wav_delete`, `rec_open_wav`: `I:\FT-710\MESSAGE` / `PlayList` voice-message files.
- `sdmenu_write_dat`: `MemList` export (`%s  %d  %08X`). `sdmenu_file_exists`: `%s\%s.dat`.
- `FUN_2012910c`: `MSG_CH%d`. `scr_playlist` / `rec_start_stop`: clock / timestamp formatting.
- `FUN_201349cc`, `FUN_20134990`, `FUN_2013499c`, `FUN_201349fc`, `FUN_20134a08`, `FUN_20134978`: SAVING / LOADING / PROCESSING / FORMAT SD CARD message boxes.
- `FUN_2015b748` (`UPDATE?`), `FUN_2015c278` (`EXTENSION SETTING`), `FUN_2015c2d4` (`FIRMWARE UPDATE`), `fwdbg_cmd` (`fw1up`/`fw1chk`), `fwobj_display_run` (`#UP0`).
- `mouse_cursor_obj_init`: `mouse_cursor_sem` (USB mouse pointer).
- `keycode_line`: `reset` debug command. `mainlink_trace_dump`: hex dump (`%-6d: `, `%02X `).
