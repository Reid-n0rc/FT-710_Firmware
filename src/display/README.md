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
| `lib/aeabi_div.c` | `__aeabi_uidivmod`, `__aeabi_idivmod`, `__rt_udiv10` (no C division here: GCC would call these very functions) |
| `lib/misc.c` | small helpers: `clamp_add_u8`, `xorshift32_step`, `bcd_to_bin`, `be16_load`/`be16_store`, `u32_decimal_digits`, `str_rtrim`, `copy5`/`copy10`/`copy32`/`copy48`, `fill8`, `copy_inverted_words`(`_b`), `is_decimal_digit` |
| `app/crc.c` | `crc16_xmodem`, `crc16_a001` and its table builder, `crc32_make_table`, `crc32_update` (the two tables share 0x208D9560) |
| `drivers/cp15.c` | MMU and caches, 0x20100D0C..0x20101183: L1 table, MMU on/off, section attributes, SCTLR cache bits, cache maintenance by line and by set/way |
| `drivers/gpio.c` | the GPIO helpers: port set-up through the Pn pointer table 0x20800000, alternative functions, PSR single-pin helpers, pin reads |
| `drivers/riic.c` | the RIIC (I2C) driver, the Renesas sample driver with its per-channel `riic_userdef` functions (83 functions) |
| `drivers/scif.c` | the SCIF UART objects (the image's C++ class as C): rings, interrupts, open, read, write; the PMCCNTR cycle stamp |
| `drivers/sflash.c` | the serial flash on SPIBSC0: SPI-mode transfers, flash commands, the device protocol the update code uses |
| `drivers/rspi.c` | the RSPI driver of the five channels: the per-channel helpers (done flags, receive and transmit ISRs, transmit and TEND waits, delay, the GIC stubs of the generic ISRs) and the core (round 7): `rspi_hw_config` (master/slave), the opens, the read bursts, `rspi_hw_config_master`, start/stop/base, the PIO read and write with their argument checks, FIFO and buffer reset, the generic ISRs and the TEND wait |
| `drivers/dmac.c` | the DMAC channel set-ups of the SPI links (round 7): channels 3, 4, 5, 9, 10 (RSPI4, RSPI2, RSPI0/1), the memory copier on channel 8, their ISRs, enable, disable, stop and callback setters |
| `drivers/sdhi.c` | the SDHI0 target layer under the SD driver: DMA block transfers, card detect, commands, the operation-table slots; round 7 the command layer above it: response copy, CMD16, CMD12, the error reset, the sector read and write commands and ops, the PIO buffer read, the DMA side of the open, `sdhi_open`, the buffer interrupt |
| `drivers/sd_card.c` | the SD card layer's single commands through the operation table (CMD0, CMD2, CMD9, CMD10, CMD13) and the CSD checks and fields (round 7) |
| `drivers/sd_setup.c` | the SD card layer's set-up (round 8): the clock, the initialisation (version 2, version 1 or MMC, the 1.8 V switch), CMD3 and the CID check, the selection (CMD7, the transfer state), the ACMDs (SCR, bus width, SD status), CMD6 and the speed switch (high speed, driver strength, UHS), the identification, the sector and partition access |
| `drivers/sd_drive.c` | the SD card as a drive (round 8): the volume mount, the driver entry `sd_driver_op` and its operations (attach, mount, unmount), the card monitor's poll, remount, unmount and write-protect query, the cluster-map state, the SD mutex, the CPU lock pair |
| `app/fat_format.c` | the SD format code: the MBR helpers (round 7); round 8 the rest: the progress counters, the layout from the CSD, the MBR, boot sector, FSInfo, FAT and root directory writes, the volume format, `sd_fat_format` and `sd_format` |
| `drivers/vdc5_api.c` | the VDC5 driver API (the Renesas r_vdc5 sample driver, built without parameter checks): initialize, terminate, video input, sync, output, write/read layers, start/stop/release, image quality, alpha, chroma key, CLUT, calibration, gamma |
| `drivers/vdc5_shrd.c` | the VDC5 driver's shared parameters: per-channel common, scaler and graphics blocks, resource and layer states, the field getters |
| `drivers/vdc5_int.c` | the VDC5 interrupt part: `r_vdc5_callback_isr` and the 46 per-source handlers |
| `drivers/vdc5_reg.c` | the VDC5 register layer: clocks and LVDS PLL, video input, sync, TCON and output, colour matrices, write data control (scaling down) and its change, the read side's helpers (cascade, VIN layer, scaling up, start pixel, enlargement), layer start/stop/release, noise reduction, image enhancement (sharpness, LTI), black stretch, alpha and alpha rectangle, chroma key, CLUT, calibration, gamma; round 7 the register parts of read data control and of its change (0x2011AF34, 0x2011B498, from the disassembly) and the change path's VIN set-up 0x2011B374 |
| `app/gui_vdc5.c` | the GUI's VDC5 set-up: module clock, TFT and DVI timing tables, LVDS PLL block, sync and output parameters, the graphics-3 line interrupt that paces the GUI, the frame-buffer addresses, the four graphics layers (`vdc5_layers_setup`, the cursor window), layers stop and channel shutdown |
| `include/vdc5.h`, `include/vdc5_regs.h` | the VDC5 parameter structures with armcc's one-byte enums, the shared-parameter tables, the register-address tables |
| `startup/vectors.S` | exception vectors, `Reset_Handler`, `reset_in_ram`, the SVC and IRQ entries (assembly, byte-identical); with `-DRAM2_LOAD` (hybrid link only) `reset_in_ram` also copies RAM2 from flash |
| `startup/rt_entry.S` | `__main`, `__scatterload`, `__decompress`, `__scatterload_zeroinit`, `__rt_lib_init`, `__rt_entry` (assembly) |
| `lib/aeabi_ldiv.S` | `__aeabi_uldivmod` and `__aeabi_ldivmod`: quotient in r0:r1, remainder in r2:r3; `_ll_udiv10`: quotient in r0:r1 and remainder in r2, which the C library's `_fp_digits` uses (assembly) |
| `lib/fplib.S` | the armcc double-precision library: `__aeabi_dadd`, `dsub`, `dmul`, `ddiv`, `d2iz`, `d2uiz`, `i2d`, `ui2d` and their NaN handler (Thumb-2 assembly) |
| `include/` | `display.h` (register helpers), `norti.h` (the service calls with the image's argument shapes), `scif.h`, `sd.h` (the SD driver's card context, handle and operation table, round 7; round 8 the 26 slots by name, the format parameters, the drive record) |
| `rtos/` | a minimal NORTi (uITRON 4.0) stand-in for a future source-only build, with its context switch and a Unicorn test |
| `display.ld` | the image's memory layout and the hybrid link (below) |
| `aliases.tsv`, `data_symbols.tsv` | original addresses of functions whose Ghidra name differs and of the data the recreated code refers to, with evidence |
| `modes.tsv` | instruction set (ARM or Thumb) of every original function, exported by `tools/ghidra/ExportFuncModes.java` |

## Build and check

**Compiler (pinned, round 6): xPack GNU Arm Embedded GCC 10.2.1-1.1** (`10.2.1 20201103`, Arm 10-2020-q4-major). The
Makefile selects it (`XPACK=` its directory, default `/home/user/t24/tc/10.2.1-1.1`, or `CROSS=` its prefix) and stops
when `$(CC) -dumpversion` is another version (`ANY_GCC=1` builds anyway, without the recorded results). Why one
compiler: the check verifies the code GCC emits, and where a trial reads past a table the verdict even depends on how
the compiler lays out `.rodata` (round 5: GCC 13.2.1 and 10.2.1 disagreed on `vdc5_reg_display_output` before its
preset was fixed), so `status.tsv` must come from one known compiler. Why this one: xPack publishes exactly this
version for Linux, macOS and Windows (the `arm-none-eabi-gcc` on a path is whatever the system ships: 13.2.1 in the
T24 container), it is the M33 image's own compiler and that of `src/ifdsp_m33`, and DISPLAY rounds 3 to 5 used it.
Install: docs/tooling.md "Source recreation".

```sh
make                                      # the pinned compiler; XPACK=<dir> or CROSS=<prefix> elsewhere
make check                                # = python3 -I ../../tools/equiv_display_emu.py status -> status.tsv
python3 -I ../../tools/equiv_display_emu.py check strcmp gpio_cfg_alt   # one or more functions
```

```sh
make link        # abicheck, then the hybrid image -> out/FT-710_DISPLAY_hybrid.bin, .elf, .map, patches.tsv, placement.tsv
make linkcheck   # the hybrid image against the original at every patched or in-place entry
make bootcheck   # emulated boot of the original and of the hybrid image (tools/display_boot_emu.py)
make rtos-test   # the NORTi stand-in in Unicorn
```

**Hybrid link.** The recreated tree covers only part of the image, so `tools/display_link.py` links it *into* the
original: `display.ld` places the original image (read from `build/` at link time) unchanged at 0x20100000, and each
recreated function that passed the check (verdict `equivalent`) goes to one of three places (round 6):

1. **in place**, at its original address, when the GCC code fits into the original extent (up to the next original
   function), the original is A32, and nothing outside the extent refers into it past the entry: no branch, no
   literal word and no PC-relative load or ADR (armcc's literal pools are shared by neighbouring functions; the
   emulated boot found one, 0x2013FE68 loading 0x20140118);
2. otherwise into the **gap** 0x2042BC10..0x2043FFFF, which `reset_in_ram` already copies from flash;
3. what does not fit there into **RAM2** 0x20920000..0x2097FFFF (`.recreated2`): its bytes follow the gap in the file
   at offset 0x340000, and the hybrid then uses `startup/vectors.S` built with `-DRAM2_LOAD`, whose `reset_in_ram`
   copies them to 0x20920000 with a loop in the nine words the original branches over (0x20100104..0x20100127) and its literals in the padding words at 0x201000CC. `--gap-limit N` forces RAM2 (used to test
   it: the gap still has room).

A linked function that is not in place gets its original entry patched with a branch to its recreation, so the
image's callers, function pointers and vector tables reach the recreated code. Everything else the recreated code
calls or uses resolves to the image's own addresses (weak absolute symbols from `functions.tsv`, `aliases.tsv`,
`data_symbols.tsv`). Where the recreated code takes the address of a linked recreated function (`R_ARM_ABS32`,
`MOVW`/`MOVT`: a function pointer, not a call), the relocation is retargeted to the function's original entry, as the
image stores and compares its own entries (round 5 needed one alias for this; now it is a rule). Some functions are
**held back** (left original) in the hybrid: those the reset path runs before `reset_in_ram` has copied the gap
(they must be in place within the first copy 0x20100000..0x20100BBF), and those whose original callers rely on a
register the GCC code changes (`equiv_display_emu.py abicheck`: armcc keeps r2, r3, ip across a call of a function it
knows, e.g. `sdhi_error_reset` around `sdhi_soft_reset`), until that caller is linked as well (round 7: its original
code then no longer runs). Byte-identical functions need no patch. The recreated code
keeps no RAM of its own (every global is the image's, declared `extern`): `display.ld` asserts that `.data` and `.bss`
are empty. The result is a complete image of the same layout, never committed and never run on a radio; in
emulation (`make bootcheck`) it boots as far as the original does: the kernel's 33 tasks, the GUI loop, RAM2 intact.

The image is read from `build/FT-710_DISPLAY_V0108.bin` (or `$FT710_BUILD`). Python packages: `pyelftools`, `unicorn`,
`capstone` (docs/tooling.md). The build flags that matter for the check: `-fno-ipa-ra` (every call follows the AAPCS,
because the callees run as the image's own code) and `-fno-tree-loop-distribute-patterns` (the copy loops of
`lib/memory.c` stay loops).

What the check cannot see: cache and TLB maintenance have no effect in Unicorn (the harness compares the set of CP15
operations statically instead), NORTi service calls are stubs (their arguments and order are compared, not what the
kernel would do), a function is only exercised as far as its inputs reach (the block coverage in `status.tsv`), and
registers beyond the C return type (`abicheck` covers the direct calls of the image and, since round 7, its calls
through a register: every `blx rN` counts against each recreated function whose entry the image holds as a word;
none of the 339 such sites reads r1, r2, r3 or ip after the call). Peripherals return seeded values (a preset may
bias chosen registers, pin one for the whole trial, or play a fixed sequence such as a CMD6 status block); the only
interrupts modelled are the RSPI ones (round 8: SPCR with SPTIE raises the transmit interrupt, an SPDR write with
SPRIE the receive one, and the harness sets the ISR's done flag), so other waits for an ISR spin to the budget and
those trials count as inconclusive.
**Never commit `out/`.** Nothing built here has been run on a radio.

## Licences

The recreated files are this project's work from the FT-710 firmware. The assembly files in `startup/` and `lib/*.S`
are transcriptions of the armcc library and start-up routines as the image contains them (like the rest of this
repository, derived from the shipped firmware); NORTi is not included (`rtos/` is an independent stand-in).
