# T24 — Recreate the source code of every image

**Status:** in progress (2026-11-01; IFDSP M33 started) · **Depends on:** T12, T21, T23 · **Issue:** (created by `tools/issues_sync.py`)

## Goal

The owner's goal (2026-10-30): **fully understand and recreate the source code, so it can be modified to fix problems and
add features.** Readable decompiled code (T23) is a step toward it; T24 is the end goal. For each image, a source tree in
`src/<image>/` that builds with a free toolchain and that is shown, function by function, to do what the shipped
firmware does: byte for byte where we have the same compiler, otherwise by a differential-emulation check.

## Plan

### Approach per image

| Image | Original toolchain and libraries | Route | Check |
|---|---|---|---|
| IFDSP M33 (RT685 Cortex-M33) | GCC 10.2.1 (Arm 10-2020-q4-major) from an MCUXpresso IDE project: MCUXpresso SDK drivers, FreeRTOS 10.3.0, rpmsg-lite, Redlib (found in this task, below) | vendor files unmodified where they match, recreated board/application code, stand-ins for the closed Redlib | byte match (same compiler), else differential emulation in Unicorn |
| IFDSP HiFi4 | Cadence Xtensa compiler (XCC), NatureDSP, XOS, newlib, rpmsg-lite v3.1.1 (`docs/code/ifdsp/hifi4-libraries.md`) | vendor libraries where public (rpmsg-lite, newlib); recreated application; XCC is proprietary, so byte match is out of reach without a licence | differential emulation with Ghidra's p-code emulator on our `Xtensa:LE:32:rt600hifi4` language (T21a); the recreated code built with the Zephyr SDK GCC for Xtensa |
| MAIN (RX651) | Renesas CC-RX (T05, T23d: Code Generator `r_cg_*` modules) | recreated C; CC-RX is free for evaluation, so a byte match may be possible: *Open: which CC-RX version and options; would be settled by compiling the `r_cg_*` modules with candidate versions as done here for the M33* | byte match if CC-RX matches, else p-code emulation on Ghidra's RX language (`rx62t` family, T21c) |
| DISPLAY (RZ/A1H Cortex-A9) | armcc (ARM Compiler 5), NORTi µITRON (T23d) | recreated C on GCC; NORTi is proprietary, so its calls need a stand-in kernel or an RTOS shim | differential emulation (Unicorn ARM, A32/Thumb) |
| SDR (Artix-7) | Vivado design | hand-written RTL in `hdl/sdr/`, verified against the recovered netlist (T15e) | netlist simulation (already in place; its own "Re-implemented" column) |

Byte matching only works with the same compiler. Everywhere else the evidence is **functional equivalence**: the original
function from the image and the recompiled one run on the same inputs and state, and their results and side effects are
compared. Emulator choice, settled by trying (2026-11-01): **Unicorn** for the ARM cores (M33 done; DISPLAY next), because it
runs Thumb-2 with the image's own callees at full speed (a 200-trial check of a 1 KB function takes under a second).
Unicorn has no Xtensa or RX support [fact: `unicorn` 2.1.4 architectures ARM, ARM64, M68K, MIPS, PPC, RISC-V, S390X,
SPARC, TriCore, X86], so the HiFi4 and MAIN harnesses will use Ghidra's p-code emulator. *Open: speed and coverage of the
p-code emulator for these; would be settled by porting `equiv_m33_emu.py`'s run/compare loop to a Ghidra script on one
HiFi4 function.*

Found while building the M33 harness: Unicorn 2.1.4 **mis-executes conditional loads and stores in Thumb IT blocks when a
memory hook is installed** (`UC_HOOK_MEM_READ/WRITE`): the image's `memcpy` ran past its end [fact: same code, same
input, ends correctly without the hook]. The harness therefore uses no memory hooks: peripherals go through `mmio_map`
callbacks, and RAM effects are compared as before/after snapshots.

### Where things go

- **Recreated stock source: `src/<image>/` in this repository** (like `hdl/sdr/`): `src/ifdsp_m33/` now.
  Vendor code is not copied in: `src/<image>/vendor.tsv` pins each file (repository, tag, commit, path, SHA-256) and
  `vendor.sh` fetches it into `vendor/` (ignored). Recreated files carry the vendor's licence header where they are
  derived from a vendor template.
- **Modifications** (fixes, features) go to **Reid-n0rc/FT-710_Custom_Firmware**, which pins this repository as a
  submodule: it builds from `src/<image>/` and keeps its patches there.
- **Never committed:** the original images and anything built from them or containing them: `build/` (decoded images,
  including the three HiFi4 blobs the M33 build links in), `src/*/out/` (objects, `ifdsp_m33.elf`, the flash binary: it
  contains Yaesu's DSP code), `src/*/vendor/`. All are in `.gitignore`.

### Progress metric

**Re-implemented** (README progress block, column of `tools/readability_stats.py`): for a CPU image, the share of code bytes
(the "Code" column: bytes of the functions in `decomp/<image>/functions.tsv`) that lie in functions whose recreated source
compiles to the same bytes or passes the equivalence check. `src/<image>/status.tsv` has one row per Ghidra function with
the bytes covered (`covered`); the column sums them. A recreated function covers original bytes from its address up to
the next original function at most, unless it is byte-identical (then its exact extent counts). Images without a
`status.tsv` show "not started". The SDR table keeps its own "Re-implemented" (netlist cells). `site/build.py` and
`tools/guide_to_wiki.py` copy the block unchanged through `published_block()`.

### Redo (firmware change, new tool version, or more source)

1. Inputs: decode the new firmware (`tools/bootstrap.sh --only inputs,decode`), re-export `decomp/ifdsp/m33/` (T23 redo).
2. Toolchain: unpack the xPack GCC (docs/tooling.md "Source recreation"); confirm with the sweep below that 10.2.1 still
   gives the most identical functions (a new firmware may use a new IDE).
3. Vendor versions: build the SDK driver files of each `mcux-sdk` tag, FreeRTOS-Kernel and rpmsg-lite tags, and keep the
   version with the most identical functions per file (`tools/equiv_m33.py bytes <objects>`); update `vendor.tsv`
   (`sha256sum` of each file) and run `./vendor.sh`.
4. Build and check: `make -C src/ifdsp_m33 CROSS=<prefix> BUILD=<build dir>` then `make -C src/ifdsp_m33 check CROSS=...`
   (= `python3 -I tools/equiv_m33.py status --emu`), then `python3 -I tools/readability_stats.py readme`; commit
   `status.tsv` and the README together.
5. For a function that differs: `python3 -I tools/equiv_m33.py diff <function> $(find src/ifdsp_m33/out/obj -name '*.o')`
   shows both disassemblies side by side; `python3 -I tools/equiv_m33_emu.py <function>` re-runs only the emulation.
   Fix the source, or add a missing original address to `aliases.tsv` (function) or `data_symbols.tsv` (data), each row
   with its evidence.

## IFDSP M33 (2026-11-01)

### Toolchain: GCC 10.2.1, -Os, MCUXpresso IDE project

All evidence is from compiling the same vendor sources with each candidate and counting the functions that come out
byte-identical to the image (relocation-aware: `tools/equiv_m33.py`):

| Sources | 9.2.1 | 9.3.1 | **10.2.1** | 10.3.1 | 11.2.1 | 12.2.1 | 13.2.1 |
|---|---:|---:|---:|---:|---:|---:|---:|
| SDK 2.9 `fsl_clock.c`, `fsl_power.c`, `fsl_reset.c` (32 functions in the image) | 20 | 20 | **27** | 27 | 21 | 20 | 20 |
| FreeRTOS-Kernel MCUX_2.9.0, first config (76 functions) | — | 41 | **55** | 54 | 45 | — | — |

- **GCC 10.2.1 [fact]**: 10.2.1 and 10.3.1 agree everywhere except `pvPortMalloc` (heap_4), where only 10.2.1 folds
  `ucHeap + configTOTAL_HEAP_SIZE` into one literal as the image does (0x81EC8). The compiler used is xPack 10.2.1-1.1
  = Arm GNU Embedded **10-2020-q4-major** ("10.2.1 20201103") [fact: its release notes]. *Open: which MCUXpresso IDE
  version bundled it; would be settled by the IDE release notes (nxp.com, not reachable from the container).*
- **-Os [fact]**: T23d's FreeRTOS match (67 at -Os vs 22 at -O1, 15 at -O2), and every identical function here is -Os.
  Flags that also show in the bytes: `-ffunction-sections` (the linker places single functions, see layout),
  `-fno-builtin` (calls to `memcpy`/`memset`/`strlen` stay calls), hard-float ABI for cortex-m33 (`-mfpu=fpv5-sp-d16`).
- **-fipa-ra** (T23f's finding that callers keep r0..r3 across callees that do not write them) is GCC's default at -O2
  and -Os, so it needs no option [inference: GCC documentation lists -fipa-ra among the -O2 optimisations; nothing in the
  bytes contradicts it].
- **MCUXpresso IDE, not the SDK's armgcc/CMake build [inference]**: the C library is NXP **Redlib** (only shipped with the
  IDE): `__main` → `stdio_init` → `main`, `_Csys_alloc`, `__sys_*` "no host" stubs; the startup is the IDE flavour
  `devices/MIMXRT685S/mcuxpresso/startup_mimxrt685s.c` (weak `X_IRQHandler` stubs calling `X_DriverIRQHandler`, `.after_vectors`,
  section-table copy-down), which byte-matches, and the semihosting `HardFault_Handler` of the IDE's `semihost_hardfault.c`.
- **Link layout [fact]**: in SRAM, every function with a literal pool (4-byte aligned section) of every object comes first,
  then all 2-byte aligned ones, each group in object order: the linker sorted the input sections by alignment.

### Vendor versions (as matched)

| Component | Version | Evidence |
|---|---|---|
| SDK drivers, device files | **mcux-sdk MCUX_2.11.0** (34e07791) | 88 identical functions vs 72 (2.9.0), 83 (2.10.0), 82 (2.12.0), 81 (2.13.0), 75 (2.14.0), 73 (8a289764, the commit the docs cite). `DMA_IRQHandle`, `GPIO_PinInit`, `SCTIMER_*`, `SEMA42_Lock` match only up to 2.11; `POWER_CalculateSafetyCount`, `deinitXip`, `POWER_UpdateOscSettlingTime` only from 2.11: 2.11.0 is the only tag that matches both [fact] |
| MCUXpresso startup | **mcux-sdk MCUX_2.9.0** `mcuxpresso/startup_mimxrt685s.c` | from 2.10.0 `ResetISR` is `naked`; the image's pushes r3-r5, lr like 2.9's [fact: 0x080011A8]; the 2.9 vector names (`SECUREVIOLATION_IRQHandler`, `USB_IRQHandler`, ...) differ from Ghidra's later names (aliases.tsv) |
| FreeRTOS | **FreeRTOS-Kernel MCUX_2.9.0** (NXP fork, 4dc0fb65) = V10.3.0 | identical results to upstream V10.3.0 (T23d's version) on every function; the NXP fork is what the SDK of that time shipped |
| rpmsg-lite | **v3.1.0** (cb56a06c) | `platform_init_interrupt`, `platform_notify` match only v3.1.0; the library files match v3.1.0..v3.2.0 alike. (The HiFi4 side was identified as v3.1.1, docs/code/ifdsp/hifi4-libraries.md; *Open: whether the two cores really use different releases; would be settled by a function that differs between 3.1.0 and 3.1.1 on the HiFi4*) |
| FreeRTOSConfig.h, rpmsg_config.h | recreated | every value marked [fact] in `src/ifdsp_m33/config/` was set by a byte difference (task name length 10, TCB fields, heap 100 KB, timer task priority 2, `configRUN_FREERTOS_SECURE_ONLY 1`, `INCLUDE_vTaskDelete 0`, 2 rpmsg buffers of 496 bytes) |

Deltas from the vendor files: none in the vendor sources themselves. The FT-710 board files are Yaesu's versions of the
SDK templates: `board.c` (empty `BOARD_InitDebugConsole`), `clock_config.c` (CLKIN bypass, SYSPLL 396 MHz, M33 198 MHz),
`dsp_support.c` (no PMIC, three images, DSP PLL /12) — all recreated byte-identical.

### Application code (recreated)

`src/ifdsp_m33/app/`: `codec.c` (AIC3204), `regfile.c`, `uart.c` (link to MAIN, `CommandTask`), `ipc.c`, `main.c`,
`pwm.c`, `console.c` (line editor and both command modes), `console_frame.c`, `semihost_hardfault.c`; `board/dsp_ipc.c`
(rpmsg master). The file split follows the image: functions that call each other across files are calls in the image, not
inlined (for example `get_task_handles` and `uart0_tx_pending`) [inference: GCC -Os inlines such 2-instruction functions
within one file]; the order of files is the order of their functions in SRAM.

### Results (status.tsv, 2026-11-01)

| Verdict | Ghidra functions | Bytes (of 28,424) |
|---|---:|---:|
| identical | 372 | 20,330 |
| equivalent (differential emulation) | 14 | 756 counted (of 1,118) |
| differs | 7 | 1,656 |
| not yet | 34 | 5,320 |

**Re-implemented: 74.2 %.** Plus 38 functions that Ghidra's list lacks (36 identical, 2 equivalent; rows with
`ghidra_name` "-"). Identical: all SDK drivers the image contains, FreeRTOS, rpmsg-lite, the startup, the board files,
the 36 linker veneers, and from the application `uart0_init`, `create_CommandTask`, `console_puts`, `IpcSendTask`,
`IpcRecvTask`, `get_task_handles`, `console_cmd_w`, `regfile_clear`, `regfile_read`, `aic3204_select_right_input`,
`is_hex_string`, `frame_checksum_ok`, `HardFault_Handler`, `ipc_init`, `ipc_recv`, `BOARD_*`, `tolower`.
Equivalent: `aic3204_spi_write`, `aic3204_init`, `regfile_write`, `uart0_write`, `ipc_print_dsp_reply`, `ipc_send`,
`console_cmd_i`/`_d`/`_r`, `strcmp`, `strlen`, `strncmp`, `strncpy`, `sprintf` (and the `memcpy`/`memset` entries).
Differs: `console_rx_char`, `FLEXCOMM0_IRQHandler`, `create_IpcTasks`, `snprintf`, `vsprintf`, `strtoul`, `__main`
(the last one by design: no Redlib stdio). Not yet: the Redlib internals (stdio streams, `malloc`/`free`, the printf
core, `__aeabi_uldivmod`, the `__sys_*` stubs) and `sct0_pwm_callback`/`sct0_pwm_init` (fewer than a quarter of the
emulation trials return normally; *Open: why; would be settled by tracing one trial with `tools/equiv_m33_emu.py`*).

The harness itself was checked both ways (2026-11-01, one-off runs): of three one-line mutations of `regfile.c`,
two (another register number, an extra bit set) were reported as differing; the third (`<=` for `<` in `regfile_read`)
was not, because the one extra register it reads (0x20080000) is 0 in the start state, so both versions return 0: the
check only sees what its inputs exercise. Byte-identical functions relocated to the scratch address (`xQueueGenericReset`, `console_init`) came out equivalent.

### Build

`make -C src/ifdsp_m33 CROSS=<xPack 10.2.1 prefix> BUILD=<dir with the decoded images>` compiles everything and links
`out/ifdsp_m33.elf` with `ifdsp_m33.ld` (flash 0x08001000, SRAM copy-down to 0x80000, MSP 0x200000, MSPLIM 0x1FF000,
boot header fields from the linker). It links and has the image's shape, but **not yet its exact layout**: 1 of 316
functions lands at its original address (the Redlib stand-ins are smaller, the section tables sit elsewhere, and the
2-aligned/4-aligned interleaving of the startup differs). *Open: whether the built image boots; would be settled by
loading it into RAM over SWD (J2009) with the owner's approval, or by a full-system emulation of the reset path.*

### Findings for the Ghidra project (not applied: `ghidra/` and `decomp/` were not changed by T24)

- Names Ghidra has wrong, with the byte evidence in `src/ifdsp_m33/aliases.tsv`: 0x872AE is Redlib's `__main` and 0x8106C
  (`app_main`) is `main`; `POWER_EnterSleep_mode1/2/3` are `POWER_EnterRbb/Fbb/Nbb`; 0x86F52 is `RESET_PeripheralReset`
  and `RESET_ClearPeripheralReset` is 0x84504 (missing); 0x81944 (`xPortIsInsideInterrupt`) is rpmsg-lite's
  `platform_in_isr`; 0x8606A/0x8606C are `platform_vatopa/patova` and the `env_*` names shift by one entry (0x8606E
  `env_allocate_memory` .. 0x8609C `env_map_patova`); 0x85B80 (`sprintf`) is `vsprintf` and 0x85A9C (`siprintf`) is
  `sprintf`; 0x87008 is `SEMA42_ResetGate`; 0x81264 is an application wrapper of `SCTIMER_StartTimer`; 0x8723C is
  `BOARD_InitBootClocks`, 0x87240 (`app_init_nop`) `BOARD_InitBootPeripherals` and 0x87294 `BOARD_InitBootPins`
  [inference for the last two: Config Tools call sequence in main].
- 38 functions are missing from `functions.tsv` (found by byte search or by link order): 13 `CLOCK_Get*Freq`
  (0x832A8..0x837A8), `xPortStartScheduler` 0x82138, `xTimerPendFunctionCallFromISR` 0x82F48, `uart0_printf` 0x80F0C, the
  `memcpy`/`memset` entries 0x872BC/0x872C0, `CTIMER_GenericIRQHandler`, ... (status.tsv rows with `ghidra_name` "-").
- `is_hex_string` (0x86014) checks only about the first half of its string (index and pointer both advance) [fact].

## Open steps

1. M33: make `console_rx_char`, `FLEXCOMM0_IRQHandler`, `create_IpcTasks` byte-identical or equivalent (diff shows the
   remaining scheduling differences); teach the harness to model the SCTimer registers so the PWM functions can be checked.
2. M33: Redlib stand-ins for the rest (stdio, heap, printf core, `__aeabi_uldivmod`), checked by emulation; then the exact
   link layout (object order, Redlib sizes) so the built image can be compared byte for byte as a whole.
3. Apply the Ghidra findings above to the canonical project (rename list, missing functions) and re-export (T23 rules).
4. Next images in this order: DISPLAY (Unicorn, ARM), HiFi4 (Ghidra p-code), MAIN (CC-RX check first).
