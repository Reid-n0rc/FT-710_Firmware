# DISPLAY (RZ/A1H Cortex-A9): recreated source (T24)

The source of the FT-710 front-panel program (`FT-710_DISPLAY_V0108`), recreated function by function. The image was
built with **armcc** (ARM Compiler 5) on the **NORTi** µITRON kernel (docs/code/display/README.md). Neither is
available, so the recreated C cannot be byte-identical: it is built with GCC and each function is checked against
the original by differential emulation (`tools/equiv_display_emu.py`, Unicorn, A32 and Thumb). The hand-written
run-time routines (vectors and start-up, the 64-bit divisions, the soft-float library) are assembly transcribed from
the image and are byte-identical at their original addresses. Plan, method
and results: [docs/tasks/T24-source-recreation.md](../../docs/tasks/T24-source-recreation.md). What the code does:
[docs/code/display/](../../docs/code/display/README.md). Per-function status: [status.tsv](status.tsv) (generated).

| Path | What |
|---|---|
| `lib/string.c` | the armcc C library string functions: `strcmp` (with the word path's `rrx` result), `strncmp`, `strcpy`, `strlen`, `strcat`, `strstr`, `strncpy`, `strcasecmp`, `strncasecmp`, `strtok_r`, `memcmp`, `tolower` |
| `lib/memory.c` | the run-time ABI copy and fill entries `__aeabi_memcpy` (Ghidra: `memcpy`), `__aeabi_memcpy4`, `__aeabi_memset`, `__aeabi_memclr`, `__aeabi_memclr4` |
| `lib/aeabi_div.c` | `__aeabi_uidivmod`, `__aeabi_idivmod`, `__rt_udiv10`, `_ll_udiv10` (no C division: GCC would call these very functions) |
| `lib/misc.c` | small helpers: `clamp_add_u8`, `xorshift32_step`, `bcd_to_bin`, `be16_load`/`be16_store`, `u32_decimal_digits`, `str_rtrim`, `copy5`/`copy10`/`copy32`/`copy48`, `fill8`, `copy_inverted_words`(`_b`), `is_decimal_digit` |
| `app/crc.c` | `crc16_xmodem`, `crc16_a001` and its table builder, `crc32_make_table`, `crc32_update` (the two tables share 0x208D9560) |
| `drivers/cp15.c` | MMU and caches, 0x20100D0C..0x20101183: L1 table, MMU on/off, section attributes, SCTLR cache bits, cache maintenance by line and by set/way |
| `drivers/gpio.c` | the GPIO helpers: port set-up through the Pn pointer table 0x20800000, alternative functions, PSR single-pin helpers, pin reads |
| `drivers/riic.c` | the RIIC (I2C) driver, the Renesas sample driver with its per-channel `riic_userdef` functions (83 functions) |
| `drivers/scif.c` | the SCIF UART objects (the image's C++ class as C): rings, interrupts, open, read, write; the PMCCNTR cycle stamp |
| `drivers/sflash.c` | the serial flash on SPIBSC0: SPI-mode transfers, flash commands, the device protocol the update code uses |
| `drivers/sdhi.c` | the SDHI0 target layer under the SD driver: DMA block transfers, card detect, commands, the operation-table slots |
| `drivers/vdc5_api.c` | the VDC5 driver API (the Renesas r_vdc5 sample driver, built without parameter checks): initialize, terminate, video input, sync, output, write/read layers, start/stop/release, image quality, alpha, chroma key, CLUT, calibration, gamma |
| `drivers/vdc5_shrd.c` | the VDC5 driver's shared parameters: per-channel common, scaler and graphics blocks, resource and layer states, the field getters |
| `drivers/vdc5_int.c` | the VDC5 interrupt part: `r_vdc5_callback_isr` and the 46 per-source handlers |
| `drivers/vdc5_reg.c` | the VDC5 register layer (part): clocks and LVDS PLL, video input, sync, TCON and output, colour matrices, layer start/stop/release, noise reduction, black stretch, alpha, calibration |
| `app/gui_vdc5.c` | the GUI's VDC5 set-up helpers: module clock, TFT and DVI timing tables, LVDS PLL block, sync and output parameters, the graphics-3 line interrupt that paces the GUI |
| `include/vdc5.h`, `include/vdc5_regs.h` | the VDC5 parameter structures with armcc's one-byte enums, the shared-parameter tables, the register-address tables |
| `startup/vectors.S` | exception vectors, `Reset_Handler`, `reset_in_ram`, the SVC and IRQ entries (assembly, byte-identical) |
| `startup/rt_entry.S` | `__main`, `__scatterload`, `__decompress`, `__scatterload_zeroinit`, `__rt_lib_init`, `__rt_entry` (assembly) |
| `lib/aeabi_ldiv.S` | `__aeabi_uldivmod` and `__aeabi_ldivmod`: quotient in r0:r1, remainder in r2:r3 (assembly) |
| `lib/fplib.S` | the armcc double-precision library: `__aeabi_dadd`, `dsub`, `dmul`, `ddiv`, `d2iz`, `d2uiz`, `i2d`, `ui2d` and their NaN handler (Thumb-2 assembly) |
| `include/` | `display.h` (register helpers), `norti.h` (the service calls with the image's argument shapes), `scif.h` |
| `rtos/` | a minimal NORTi (uITRON 4.0) stand-in for a future source-only build, with its context switch and a Unicorn test |
| `display.ld` | the image's memory layout and the hybrid link (below) |
| `aliases.tsv`, `data_symbols.tsv` | original addresses of functions whose Ghidra name differs and of the data the recreated code refers to, with evidence |
| `modes.tsv` | instruction set (ARM or Thumb) of every original function, exported by `tools/ghidra/ExportFuncModes.java` |

## Build and check

```sh
make CROSS=/path/to/arm-none-eabi-        # any arm-none-eabi GCC; T24 used xPack 10.2.1-1.1
make check CROSS=...                      # = python3 -I ../../tools/equiv_display_emu.py status -> status.tsv
python3 -I ../../tools/equiv_display_emu.py check strcmp gpio_cfg_alt   # one or more functions
```

```sh
make link CROSS=...                       # hybrid image -> out/FT-710_DISPLAY_hybrid.bin, .elf, .map, patches.tsv
make linkcheck CROSS=...                  # the hybrid image against the original at every patched entry
make rtos-test CROSS=...                  # the NORTi stand-in in Unicorn
```

**Hybrid link.** The recreated tree covers only part of the image, so `tools/display_link.py` links it *into* the
original: `display.ld` places the original image (read from `build/` at link time) unchanged at 0x20100000 and the
recreated functions that passed the check (verdict `equivalent`) in the gap 0x2042BC10..0x2043FFFF, which
`reset_in_ram` already copies from flash (it copies up to 0x2043FFFF, past the end of the file); everything else the
recreated code calls or uses resolves to the image's own addresses (weak absolute symbols from `functions.tsv`,
`aliases.tsv`, `data_symbols.tsv`). Each linked function's original entry is then patched with a branch to its
recreation, so the image's callers, function pointers and vector tables reach the recreated code. Recreated functions
that did not pass are left out, and byte-identical ones need no patch. The recreated code keeps no RAM of its own
(every global is the image's, declared `extern`): `display.ld` asserts that `.data` and `.bss` are empty. The result
is a complete image of the same layout, never committed and never run on a radio.

The image is read from `build/FT-710_DISPLAY_V0108.bin` (or `$FT710_BUILD`). Python packages: `pyelftools`, `unicorn`,
`capstone` (docs/tooling.md). The build flags that matter for the check: `-fno-ipa-ra` (every call follows the AAPCS,
because the callees run as the image's own code) and `-fno-tree-loop-distribute-patterns` (the copy loops of
`lib/memory.c` stay loops).

What the check cannot see: cache and TLB maintenance have no effect in Unicorn (the harness compares the set of CP15
operations statically instead), NORTi service calls are stubs (their arguments and order are compared, not what the
kernel would do), and a function is only exercised as far as its inputs reach (the block coverage in `status.tsv`).
**Never commit `out/`.** Nothing built here has been run on a radio.

## Licences

The recreated files are this project's work from the FT-710 firmware. The assembly files in `startup/` and `lib/*.S`
are transcriptions of the armcc library and start-up routines as the image contains them (like the rest of this
repository, derived from the shipped firmware); NORTi is not included (`rtos/` is an independent stand-in).
