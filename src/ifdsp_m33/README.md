# IFDSP Cortex-M33: recreated source (T24)

The source of the FT-710 IFDSP's Cortex-M33 program (`FT-710_IFDSP_V0101`), recreated so that it can be read, changed
and rebuilt. How it was made, the toolchain evidence and the results: [docs/tasks/T24-source-recreation.md](../../docs/tasks/T24-source-recreation.md).
What the code does: [docs/code/ifdsp/](../../docs/code/ifdsp/README.md).

Per-function status against the original image: [status.tsv](status.tsv) (generated; `identical` = same bytes,
`equivalent` = passes the differential emulation, `differs`, `not yet`).

## Layout

| Path | What |
|---|---|
| `vendor.tsv`, `vendor.sh` | NXP MCUXpresso SDK MCUX_2.11.0 drivers and device files, the SDK MCUX_2.9.0 MCUXpresso startup, CMSIS headers, FreeRTOS-Kernel MCUX_2.9.0 (V10.3.0), rpmsg-lite v3.1.0: pinned by commit and SHA-256, fetched unmodified into `vendor/` (not committed) |
| `config/` | `FreeRTOSConfig.h`, `rpmsg_config.h`, recreated from the image |
| `board/` | board, clock, pin-mux, peripherals, DSP start (`dsp_support.c`, `dsp_image.S`) and the rpmsg master (`dsp_ipc.c`) |
| `app/` | the application: codec, register file, USART link and console, IPC tasks, PWM, `main` |
| `libc/` | stand-ins for the parts of NXP's closed Redlib the application uses (ctype table, string functions, `strtoul`, `sprintf` family, `__main`) |
| `ifdsp_m33.ld`, `Makefile` | build and link (flash at 0x08001000, SRAM copy-down to 0x80000) |
| `aliases.tsv`, `data_symbols.tsv` | original addresses of functions and data the check cannot take from Ghidra's list or learn, with evidence |

## Build and check

```sh
./vendor.sh                                   # once: fetch the vendor sources (needs network)
make CROSS=/path/to/xpack-arm-none-eabi-gcc-10.2.1-1.1/bin/arm-none-eabi- BUILD=../../build
make check CROSS=...                          # byte check + differential emulation -> status.tsv
```

The image was built with GCC 10.2.1 (Arm 10-2020-q4-major); other versions build too, with fewer identical functions.
`BUILD` is the directory with the decoded images (`tools/bootstrap.sh`): the link takes the three HiFi4 images from it,
and `make check` compares against `FT-710_IFDSP_V0101.bin`. Python packages for the check: `pyelftools`, `unicorn`,
`capstone` (docs/tooling.md).

**Never commit `out/`**: the linked ELF and binary contain Yaesu's HiFi4 code. Nothing built here has been run on a
radio; flashing needs the owner's approval each time (AGENTS.md).

## Licences

- Files derived from NXP SDK templates keep NXP's header: `board/board.c`, `board/board.h`, `board/clock_config.c`,
  `board/clock_config.h`, `board/dsp_support.c` — BSD-3-Clause (SPDX `BSD-3-Clause`, Copyright NXP).
- Vendor sources fetched by `vendor.sh` keep their own licences: MCUXpresso SDK BSD-3-Clause (`COPYING-BSD-3`), CMSIS
  Apache-2.0 (`CMSIS/LICENSE.txt`), FreeRTOS MIT (`License/license.txt`), rpmsg-lite BSD-3-Clause (`LICENSE`).
- The rest of this directory is recreated from the FT-710 firmware for this project; the data tables taken from the image
  (codec init sequence, ctype table) are Yaesu's.
