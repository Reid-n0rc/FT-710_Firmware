# src/ifdsp_hifi4: recreated source of the IFDSP HiFi4 DSP image (T24)

The HiFi4 image (`FT-710_IFDSP_V0101_hifi4.bin`, three parts the M33 loads: TCM 0x24000000, SRAM 0x200000, shared
0x20040000) was built with Cadence XCC, which is proprietary, so nothing here can be byte-identical. Each recreated
function is checked against the original by differential emulation in Ghidra's p-code emulator
(`tools/equiv_hifi4_emu.py`, `tools/ghidra/EquivHifi4Emu.java`); results per Ghidra function in `status.tsv`, the
toolchain findings and the plan in [docs/tasks/T24-source-recreation.md](../../docs/tasks/T24-source-recreation.md)
("IFDSP HiFi4").

| Path | What | Origin |
|---|---|---|
| `vendor/newlib-cygwin/newlib/libc/machine/xtensa/` | `memcpy.S`, `memset.S`, `strlen.S`, `strcmp.S`, `strncpy.S` (Tensilica) | newlib-4.4.0, unmodified (`vendor.tsv`) |
| `vendor/newlib-cygwin/newlib/libc/`, `libm/` | `strncmp.c`, `memchr.c`, `memmove.c`, `rand.c` (`rand`, `srand`), `errno.c`, `s_matherr.c`, `sf_fabs.c`, `sf_copysign.c`, `sf_nan.c`, `sf_finite.c`, `sf_fpclassify.c`, `sf_scalbn.c` | newlib-3.1.0, unmodified |
| `vendor/rpmsg-lite/lib/` | `rpmsg_env_bm.c`, `rpmsg_lite.c`, `rpmsg_ns.c`, `virtqueue.c`, `llist.c` | rpmsg-lite v3.1.1, unmodified |
| `include/rpmsg_config.h` | rpmsg-lite configuration (static API, 496-byte payload) | recreated |
| `include/xos_api.h`, `include/hifi4_hal.h` | prototypes of the XOS and Xtensa HAL calls (Cadence's code stays the image's) | recreated |
| `app/regfile.c`, `include/regfile.h` | register file defaults, the two capture blocks, `regfile_gpio_sel` | recreated |
| `app/dsp_blocks.c`, `include/dsp_blocks.h` | chain state resets, (de)interleaving, VOX state, FM TX filter set-up, noise generator seed, SPI buffer pointers | recreated |
| `libc/xos_clib.c` | XOS C-library glue: malloc lock, `_sbrk_r`, stdio lock hooks, `_close_r`, `_lseek_r` | recreated |
| `data_symbols.tsv` | image addresses of the variables the recreated code names, with evidence | |

```sh
cd src/ifdsp_hifi4 && ./vendor.sh && make          # Zephyr SDK 0.17.0 RT600 GCC (CROSS=... to change)
cd ../.. && GHIDRA_HEADLESS=<Ghidra with this branch's xtensa_rt600hifi4 language>/support/analyzeHeadless \
  python3 -I tools/equiv_hifi4_emu.py status       # needs build/ and the Ghidra copy in FT710_IFDSP_PROJECT
python3 -I tools/readability_stats.py readme
```

Floats: XCC passes float arguments and results in the FP/AE registers (aed0..); GCC for this core has no FPU support
and passes them in address registers. The recreated float functions are therefore equivalent in value, not in their
register interface; a recreated function must not call an image function that takes or returns a float (the harness
cannot bridge that call), see the task file.
