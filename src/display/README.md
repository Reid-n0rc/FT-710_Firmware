# DISPLAY (RZ/A1H Cortex-A9): recreated source (T24)

The source of the FT-710 front-panel program (`FT-710_DISPLAY_V0108`), recreated function by function. The image was
built with **armcc** (ARM Compiler 5) on the **NORTi** µITRON kernel (docs/code/display/README.md). Neither is
available, so nothing here can be byte-identical: the recreated C is built with GCC and each function is checked
against the original by differential emulation (`tools/equiv_display_emu.py`, Unicorn, A32 and Thumb). Plan, method
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
| `aliases.tsv`, `data_symbols.tsv` | original addresses of functions whose Ghidra name differs and of the data the recreated code refers to, with evidence |
| `modes.tsv` | instruction set (ARM or Thumb) of every original function, exported by `tools/ghidra/ExportFuncModes.java` |

## Build and check

```sh
make CROSS=/path/to/arm-none-eabi-        # any arm-none-eabi GCC; T24 used xPack 10.2.1-1.1
make check CROSS=...                      # = python3 -I ../../tools/equiv_display_emu.py status -> status.tsv
python3 -I ../../tools/equiv_display_emu.py check strcmp gpio_cfg_alt   # one or more functions
```

The image is read from `build/FT-710_DISPLAY_V0108.bin` (or `$FT710_BUILD`). Python packages: `pyelftools`, `unicorn`,
`capstone` (docs/tooling.md). The build flags that matter for the check: `-fno-ipa-ra` (every call follows the AAPCS,
because the callees run as the image's own code) and `-fno-tree-loop-distribute-patterns` (the copy loops of
`lib/memory.c` stay loops).

What the check cannot see: cache and TLB maintenance have no effect in Unicorn (the harness compares the set of CP15
operations statically instead), NORTi service calls are stubs (their arguments and order are compared, not what the
kernel would do), and a function is only exercised as far as its inputs reach (the block coverage in `status.tsv`).
**Never commit `out/`.** Nothing built here has been run on a radio.

## Licences

The recreated files are this project's work from the FT-710 firmware. The armcc library and NORTi are not included.
