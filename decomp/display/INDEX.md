# decomp/display — FT-710 DISPLAY (V01-08) Ghidra export

Source: `build/FT-710_DISPLAY_V0108.bin` (RZ/A1H Cortex-A9, `ARM:LE:32:v7`, base 0x20100000). The memory map is in
`docs/memory-maps.md` (DISPLAY), and the method and findings are in `docs/tasks/T06-decomp-display.md`.

## Export stats
- Ghidra 12.1.4 project `ghidra/FT710_DISPLAY`. Pipeline: `DisplaySetup.java` (preScript) → auto-analysis → `DisplayFindCode.java` (pointer-table,
  prologue and orphan-code passes) → `FixFuncEntries.java tools/ghidra/entries_display.tsv` (T11) → `ApplyNames.java tools/ghidra/names_display.tsv` →
  `ExportDecomp.java decomp/display 50`.
- T11 (2026-10-27): the project was rebuilt on the Linux host and the re-export matched the T06 commit byte for byte. `FixFuncEntries.java` then
  created 14 function entries that analysis had missed (RTOS task entries such as `task_root` 0x201170C8, which start with an `ldr` before the
  `push`, so the prologue pass had started them 4–8 bytes late or the previous function had swallowed them). Detailed docs: `docs/code/display/`.
- T17 (2026-10-27): `entries_display.tsv` and `names_display.tsv` now hold the merged T11a–g proposals (68 entries, 768 names; name conflicts
  resolved in `tools/ghidra/names_display.picks.tsv`, listed in `docs/tasks/T17-integration.md`). FixFuncEntries: 68 entries (re)created,
  8 late starts removed. **2087 functions exported** (thunks are skipped), **0 decompile failures**; 772 carry a name. Output: 42 `.c` files of
  50 functions each, about 81k lines (2.0 MB). Before T17: 2041 exported, 151 named.
- Code coverage of `.text` (0x20100000–0x20165177, 414,072 B): about 95% instructions and 4% data (literal pools, tables). About 2.7 KB of small
  unreferenced fragments remain undefined.
- `functions.tsv` lists entry, name, size, reference count, and file for every exported function.
- File names are `<first entry>_<last entry>.c`. The first file starts with two stub "functions" at 0x18400000/0x18A00000. These are the
  jump targets into the flash banks, not real code in this image.

## Notable functions
Names are **[inference]** unless noted. "File" is the export file that holds the function.

### Startup / runtime
| Address | Name | Notes | File |
|---|---|---|---|
| 0x2010002C | `Reset_Handler` | Vector 0. Relocates the image to 0x20100000 if it runs elsewhere **[fact]** | 18400000_20101ba4.c |
| 0x20100080 | `reset_in_ram` | SPIBSC0 init, bank select, copies the rest of the image **[fact]** | 18400000_20101ba4.c |
| 0x20100ABC | `boot_select_bank` | Flags at 0x183E0000/0x183F0000 → calls 0x18400000 or 0x18A00000. Uses SPIBSC1 reg 0x3FEFB018 as a "stage ran" marker **[fact]** | 18400000_20101ba4.c |
| 0x20100828 | `spibsc0_init` | SPI flash controller setup | 18400000_20101ba4.c |
| 0x20100BC8 / 0x20100BFC / 0x20100C60 | `__scatterload` / `__decompress` / `__scatterload_zeroinit` | armcc runtime **[fact]** | 18400000_20101ba4.c |
| 0x20117294 | `main` | Called from `__rt_entry`. Creates the first task, then loops | 20116ec8_20118598.c |
| 0x201001D8 | `IRQ_Handler` | Calls the GIC dispatcher 0x201176B4 | 18400000_20101ba4.c |

### RTOS (µITRON 4.0-style kernel; the vendor is not identified)
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
| 0x2010F81C | `sfl_load_file` | Reads an SFL file and decodes it |
| 0x2010DDD8 / 0x2010DFD0 | `fwfile_check_versions` / `fwfile_status_text` | Matches `FT-710_{MAIN,DISPLAY,IFDSP,SDR}_V` and shows `Ready` / `(Broken file)` / `(No such file)` |

### Firmware update of the other CPUs and of itself
| Address | Name | Notes |
|---|---|---|
| 0x2010EA90 | `update_main_cpu` | Opens `I:\AH076H_HEW.mot` (or `AH068H_HEW.mot`) and programs the RX651 over the boot-mode UART |
| 0x2010D92C / 0x2010DA78 | `update_dsp` / `dsp_debug_cmd` | `I:\AH076H_IFDSP.dat`, `I:\rom_writer.dat`, `I:\AH068_AFDSP_V0000.dat`. Commands `dsp1up`…`dsp3up/32/9` |
| 0x20110AB8 | `sdr_flash_write` | Writes the SDR (FPGA) image over SPI in 0x2000-byte blocks through `sdr_spi_xfer_block` 0x20110834 |
| 0x20110C3C | `sdr_debug_cmd` | strcmp chain for `sdrup`, `sdr1up`, `sdr2up`, `sdrchk1`, `sdrup/g`, `sdr1up/g`, `sdr2up/g`, `sdrchk1/g`, `sdrchk2/g`, `sdrspi`, `sdrfile`, `delta`. It signals the worker through the event flag held in 0x208001B8 |
| 0x2011249C | `sdr_spi_stats_print` | `CS_POLL`, `MOSI_OK/NG`, `MISO_OK/NG`, `FRAMES`, `msec` |
| 0x2015F62C | `update_display_self` | `I:\AH076H_DISPLAY.bin`, `I:\AH068_DISPLAY_Loader.bin` |
| 0x2015F1F0 | `display_flash_write_bank` | Writes to the bank at 0x18400000 |
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
| 0x20116560 | `mainlink_send_cmd` | Looks up a 43-entry {cmd char, length} table at 0x20450074 (.data) and builds a frame with 0xAA marker + length |
| 0x20115494 | `mainlink_queue_frame` | |
| 0x20134FDC | `debug_recv_cmd_log` | Logs received commands to `I:\FT-710\DEBUG_RECV_CMD\RECV_CMD.TXT` |

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
| 0x201326FC | `fb_get_layer_addr` | 6 frame buffers, 800×480 RGB565, in uncached RAM 0x60000000+ |
| 0x201355BC / 0x20135658 / 0x201358D0 | `fb_copy_rect` / `fb_fill_rect` / `gui_draw_runs` | Most-called GUI primitives (294 callers for `gui_draw_runs`) |
| 0x20133A8C | `gui_update_layers` | Selects the layer buffers and passes them to the VDC5 (0x20117E5C) |
| 0x2011A394 | `vdc5_config` | VDC5 ch0 registers |
| 0x20125E78 | `touch_calibration` | `TOUCH THE CROSS` |
| 0x20134644 / 0x2013059C | `screen_capture_bmp` / `screen_shot_menu` | `I:\FT-710\Capture\20YYMMDD_HHMMSS.bmp` |
| 0x2013B5BC / 0x2013B928 / 0x20107EFC | `usbh_create_objects` / `usbh_hid_init` / `vk_key_name` | USB host stack (`m596*`, `udevtsk%d`, `UHHID`): USB keyboard/mouse support |

### Peripherals
| Address | Name | Notes |
|---|---|---|
| 0x201177E4 | `ostm_init` | OSTM0 0xFCFEC000 (tick) |
| 0x20120224 | `riic_init` | RIIC 0xFCFEE000 (touch controller TSC2003 per hardware.md) |
| 0x201033E8 | `intc_irq_setup` | INTC 0xFCFEF800 |
| 0x2011E1F0–0x2011F230 | (unnamed) | RSPI0–4 drivers (SDR SPI, DSP SPI, FT4222 SPI) |

### Other string-referenced functions (unnamed, good T11 entry points)
- `FUN_201052b0`, `FUN_20105550`, `FUN_201057d8`, `FUN_20106248`: `I:\FT-710\MESSAGE` / `PlayList` voice-message files.
- `FUN_2010f370`: `MemList` export (`%s  %d  %08X`). `FUN_2010f1e0`: `%s\%s.dat`.
- `FUN_2012910c`: `MSG_CH%d`. `FUN_20124c24` / `FUN_2012e744`: clock / timestamp formatting.
- `FUN_201349cc`, `FUN_20134990`, `FUN_2013499c`, `FUN_201349fc`, `FUN_20134a08`, `FUN_20134978`: SAVING / LOADING / PROCESSING / FORMAT SD CARD message boxes.
- `FUN_2015b748` (`UPDATE?`), `FUN_2015c278` (`EXTENSION SETTING`), `FUN_2015c2d4` (`FIRMWARE UPDATE`), `FUN_2015f0ec` (`fw1up`/`fw1chk`), `FUN_201607e8` (`#UP0`).
- `FUN_2015fcc4`: `mouse_cursor_sem` (USB mouse pointer).
- `FUN_20111ab0`: `reset` debug command. `FUN_2011158c`: hex dump (`%-6d: `, `%02X `).
