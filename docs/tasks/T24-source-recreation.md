# T24 — Recreate the source code of every image

**Status:** in progress (2026-11-01; IFDSP M33 100.0 % re-implemented, round 3; DISPLAY 10.31 % re-implemented, round 5, and links into a complete hybrid image that passes linkcheck; MAIN 2.82 % re-implemented, round 1, GCC for RX and Ghidra p-code emulation: CC-RX not obtainable) · **Depends on:** T12, T21, T23 · **Issue:** (created by `tools/issues_sync.py`)

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
| MAIN (RX651) | Renesas CC-RX, optimization level 0, RXv2 with FPU, 32-bit double; Code Generator `r_cg_*` drivers ("MAIN, round 1" below) | recreated C built with GCC 13.3.0 for RX: CC-RX could not be obtained (renesas.com refused by the proxy), *Open: the CC-RX version; would be settled by compiling the `r_cg_*` modules with candidate versions as done here for the M33* | p-code emulation on Ghidra's RX language (`tools/equiv_main_emu.py`); byte match only for trivial functions |
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

### Findings for the Ghidra project (round 1; put into the Ghidra scripts in round 2, below)

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

## IFDSP M33, round 2 (2026-11-01)

### Plan (round 2)

1. Ghidra side from the round-1 findings: names, the functions Ghidra lacks (FixFuncEntries entries), signatures,
   docs; prove the update on a copy of the canonical project and compare the export quality.
2. Redlib stand-ins (one file per original member), checked by bytes or emulation; the three app functions that
   differ; the PWM functions; the link layout.
3. Start the next image (DISPLAY) as far as the budget goes.

### Ghidra corrections (applied to the scripts, proved on a copy; `ghidra/` and `decomp/` unchanged)

The byte check names a function as a **[fact]** where it is byte-identical to a known source function; the full list
with evidence is `docs/code/ifdsp/m33-platform.md` section 11. Renamed in `tools/ghidra/IfdspM33Names.java`,
`names_ifdsp.T12d.tsv`, `signatures_m33.tsv` and `docs/code/ifdsp/*.md`: 0x872AE `main` → `__main`, 0x8106C `app_main`
→ `main`, `POWER_EnterSleep_mode1/2/3` → `POWER_EnterRbb/Fbb/Nbb`, 0x81944 `xPortIsInsideInterrupt` → `platform_in_isr`,
0x8606A `env_map_vatopa` → `platform_vatopa`, 0x85B80 `sprintf` → `vsprintf`, 0x85A9C `siprintf` → `sprintf`, 0x86F52
`RESET_ClearPeripheralReset` → `RESET_PeripheralReset`, 0x87008 `SEMA42_ResetAllGates` → `SEMA42_ResetGate`, 0x81BE8
`rpmsg_queue_nocopy_free` → `rpmsg_lite_release_rx_buffer`, 0x81264 `SCTIMER_StartTimer` → `sct0_pwm_start`, 0x878CC /
0x87900 `memcpy`/`memset` → `memcpy_body`/`memset_body` (the linked `memcpy`/`memset` are the `b.w` entries 0x872BC /
0x872C0), `DefaultHandler` → `IntDefaultHandler`, five vector handlers to their SDK 2.9 startup names; **[inference]**:
0x87240 `app_init_nop` → `BOARD_InitBootPeripherals`, 0x87294 `BOARD_InitPins` → `BOARD_InitBootPins`. Correction of
round 1's finding: of the `env_*` names only 0x8606A was wrong; the others Ghidra had were right, and ten more were
missing. `tools/ghidra/entries_m33.tsv` gains 40 entries (the 38 functions outside any Ghidra function, two bodies
merged into `CLOCK_GetFlexCommClkFreq`), and `initFlexSPI` moves to 0x802A8 (the `ldr` before its `push`).
`is_hex_string`'s bug is documented in `docs/code/ifdsp/control-link.md` (it checks only the first half of the string).

**Commands for the canonical project** (repository root; `GHIDRA_JAVA_HOME` only where the default JDK is not 21):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/ifdsp/m33/quality.tsv /tmp/quality_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis -scriptPath tools/ghidra \
  -postScript FixFuncEntries.java tools/ghidra/entries_m33.tsv \
  -postScript IfdspM33Names.java \
  -postScript ApplySignatures.java tools/ghidra/signatures_m33.tsv \
  -postScript NameVariables.java log=/tmp/namevars_ifdsp_m33.tsv sfr=tools/ghidra/sfr_rt685.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis -scriptPath tools/ghidra \
  -postScript CommentCode.java tools/ghidra/sfr_rt685.tsv tools/ghidra/purposes_m33.tsv tools/ghidra/comments_m33.tsv /tmp/comments_m33.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/ifdsp/m33" 50
# the purposes follow the exported names: derive them again, comment again, export again (converges here)
python3 -I tools/code_comments.py purposes m33
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis -scriptPath tools/ghidra \
  -postScript CommentCode.java tools/ghidra/sfr_rt685.tsv tools/ghidra/purposes_m33.tsv tools/ghidra/comments_m33.tsv /tmp/comments_m33.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/ifdsp/m33" 50
python3 -I tools/decomp_quality.py compare /tmp/quality_before.tsv decomp/ifdsp/m33/quality.tsv m33
python3 -I tools/code_comments.py check m33 && python3 -I tools/readable_view.py build ifdsp/m33
python3 -I tools/readability_stats.py readme
```

Proof on a copy (`/home/user/ghidra_tasks/t24r2/proj`, OWNER root, 2026-11-01) [fact: logs there]: FixFuncEntries 42
created, 1 late start removed, 0 failed, 30 branches marked as tail calls; IfdspM33Names 406 named; ApplySignatures 256
applied, 0 failed; NameVariables 34 renamed, 0 failed; ExportDecomp 449 functions (was 427; the new thunks are not
exported), 0 failed. `decomp_quality.py compare` against the committed export: **no metric worse, 9 better** (warnings
179 → 150, functions with warnings 92 → 87, unreachable-block warnings 37 → 16, functions with `in_` 9 → 8, `extraout_`
16 → 13). The second CommentCode pass gives the same quality, and a third `purposes` run changes nothing. Until the
re-export, the README shows the M33 "documented" figure at 98.6 % (the docs use the new names, `decomp/` the old ones).

### Harness (tools/equiv_m33_emu.py)

Round 1's rule ("a quarter of the trials return") let the printf core pass although its format argument (on the stack)
was never drawn: every trial formatted an empty string [fact: the reduced stand-in passed]. Round 2 adds: four stack
argument slots; printf-like format strings; **block coverage** of the original (block hook, which leaves Thumb IT blocks
alone, against a static leader scan); `equivalent` needs every trial to agree, one normal return and at least half of
the original's blocks reached. PRESETS build valid state where a function walks a structure (heap list, stream, DSP
message, PWM event/ticks); the `__sys_*` calls are stubbed with random returns, because in the image they always fail
and leave most stdio unreachable. `equiv_m33.py`: an equivalent function covers the original up to the next original
function, as the metric above defines (round 1 counted only its own recompiled size).

The PWM functions: their round-1 trials did not hang in a poll loop; they faulted in `SCTIMER_UpdatePwmDutycycle`
reading `EV[event]` with the random `.bss` event number [fact: trial trace]. With a valid event number both pass
(`sct0_pwm_init` byte-identical, `sct0_pwm_callback` equivalent, 200 of 200 trials return, all blocks reached).

### Redlib stand-ins (src/ifdsp_m33/libc/redlib/)

One file per original member. Byte-identical: `_Csys_alloc`, `free`, `__check_heap_overflow`, `ftell`, `remove`,
`file_clear_flag20`, `_Cfclose`, the eight `__sys_*` stubs, `memcpy`/`memset` entries, and as **hand-written assembly**
(`.S`, the image's instructions, labels by original address) `__aeabi_uldivmod` with its helper and the copy/fill loops
[inference for "hand-written": flag-setting instructions inside IT blocks and carry tricks no compiler emits].
Equivalent (with coverage): `malloc` (100 % of 23 blocks), `fputc` (93 %), `fseek`, `_Cfdopen`, `_Cfflush1`,
`_Cwrite_buffer`, `fflush`, `file_flush_write_buffer`, `setvbuf`, `stdio_init`, `_sbrk`, `sprintf`, `snprintf`,
`vsprintf`, `strtoul`, `_strtoul_core`, `_Cdigit_value`. `malloc` does not byte-match with any GCC 9.2..12.2 or -O1/-O2/-Os
(its loop is laid out test-at-bottom with the preheader at the end); *Open: Redlib's compiler and options; would be
settled by the MCUXpresso IDE release that bundled 10-2020-q4 and its Redlib build notes*. The printf core
`vsnprintf_core` (2,778 bytes) is a **reduced stand-in** with the original interface `(stream, 64-bit limit in r2:r3,
format, va_list, hook)`; it differs (open below).

### Link layout

The image's order is reproduced by: object order application, rpmsg-lite (platform, env, queue, llist, lite,
virtqueue), FreeRTOS (heap_4, port, portasm, event_groups, list, queue, tasks, timers), SDK drivers by file name, board
files, C library members; input sections sorted by alignment (16, 4, 2) **including CodeQuickAccess**, which is also
kept although unreferenced [fact: IAP_FlexspiNorAutoConfig, POWER_EnterDeepSleep and OTFAD_Init have no callers but are
in the image, ordered fsl_iap, fsl_power, board (4-byte aligned), fsl_otfad (2)]. Result: 23 of 431 functions at their
original address (round 1: 1), **402 of 430 consecutive pairs with the original spacing, 428 in the original order**;
every address difference follows a function whose recreated size differs (the first: `aic3204_spi_write`, 96 vs 100
bytes). The remaining order difference is in console.c (GCC emits `console_cmd_d` before `console_cmd_w`); *Open:
whether the IDE build used -fno-toplevel-reorder; would be settled by building console.c with it and comparing the
order of every other file*. `console_dump` is now inlined into both callers (the image has no separate dump function:
`console_cmd_d` is 128 bytes) [inference].

### Results (status.tsv, round 2)

| Verdict | Ghidra functions | Bytes (of 28,424) |
|---|---:|---:|
| identical | 392 | 21,182 |
| equivalent (with coverage) | 33 | 3,398 |
| differs | 2 (`console_rx_char`, `vsnprintf_core`) | 3,836 |
| not yet | 0 | |

**Re-implemented: 86.5 %** (24,580 of 28,416 bytes; round 1: 74.2 %).

### DISPLAY (started 2026-11-01)

`src/display/app/crc.c` (`crc16_xmodem` 0x2010AA30) and `tools/equiv_display_emu.py` (Unicorn, A32): **equivalent**,
200 trials; the mutation 0x1021 → 0x1023 is reported as differing. The harness handles leaf functions without
relocations. Blockers and next steps: armcc 5 is not available (no byte match, as planned); the A32 harness needs the
relocation/stub machinery of `equiv_m33_emu.py` (callees at original addresses, NORTi service calls stubbed:
`docs/code/display/boot-rtos.md` lists them) before functions with callees or globals can be checked; no
`status.tsv` for DISPLAY yet (the README column stays "not started" until one exists). Also seen: Ghidra types
`crc16_xmodem`'s return as `byte`, but the code returns 16 bits (`uxth r0`) [fact: 0x2010AA4C].

## IFDSP M33 and DISPLAY, round 3 (2026-11-01)

### Plan (round 3)

1. M33: translate the printf core `vsnprintf_core` in full; give `console_rx_char` a console-state preset and fix its
   differences; add 0x872F4 `printf_float_none` to the Ghidra entries; make `status.tsv` cover the re-exported
   449-function list, so that the README figure and the status table agree; push the link layout further
   (`console_cmd_d`/`_w` order, `-fno-toplevel-reorder` or the source order).
2. DISPLAY: port the relocation and stub machinery of `equiv_m33_emu.py` to `equiv_display_emu.py` (NORTi service
   calls as stubs); recreate the library functions and the drivers, biggest self-contained ones first; track them in
   `src/display/status.tsv`, wired into the "Re-implemented" column like the M33.

### M33: status after the re-export

The re-export after round 2 carries the corrected Ghidra names (`main`, `__main`, `vsprintf`, `sprintf`, the SDK 2.9
vector names, ...). `aliases.tsv` still mapped the source names to the *old* Ghidra names, which no longer existed:
that alone made 29 functions "not yet" and 6 "differs" in the first run of round 3 (84.5 %) [fact: the run before the
alias fix]. Only the rows for addresses Ghidra's list still lacks are left.

### M33: the printf core (`libc/redlib/vsnprintf_core.c`)

Translated from 0x84EB0..0x85989: flags `- + space # 0`; width and precision as digits or `*` (a negative `*` width
toggles `-`, a negative precision means none); length `l ll L q h hh j z t`; conversions `d i o u x X p c s n`; every
other character after `%` (and `%`, and `F`) printed as itself, padded; `a A e E f g G` through the hook
hook(conv, &arg, buf, flags, &prefix, &zeros, &lead, &trail). Integer digits come from an open-coded 64-bit division by
10 (the shift-and-add `divu10`), so the core never calls `__aeabi_uldivmod` [fact: 0x85770..0x857FA]. Two traps found
on the way: GCC drops a `width < 0` test after `width = -width` (signed overflow), so the negation is unsigned; and a
macro argument with a side effect (`*prefix++`) must not sit inside the conditional store.

Check: a printf-core preset (string stream, 64-bit limit including LLONG_MAX, 0, negative and 2^32, a format with
every conversion, and a va_list built to match it: random words as `*` widths made both versions run out of the
budget in the padding loops). **Equivalent**: 200 trials (94 % of 218 blocks) and 2,000 trials with seed 7. Mutations
of the divu10 constant, of "(null)" and of the `ll` flag are reported as differing; a mutation of the hook's `lead`
zeros is not, because the image's hook never sets lead or trail. *Open: the floating-point path with a hook that
fills buf; would be settled by a preset hook (a small Thumb routine in the scratch area) that writes digits, '<', '>'
and the prefix.* `printf_float_none` leaves the prefix NULL, so on the radio a `%f` would print the string at address
0 as its prefix [inference: the core sets prefix 0 for these conversions, 0x851A0..0x851B2, and reads it unchecked];
no format string of the application has a floating-point conversion [fact].

### M33: the console (`app/console.c`)

`console_rx_char` (1,058 bytes): the line state 0x88DEF is compared with 0 and 1, and any other value ignores the
character (0x814BA..0x814C2); in machine mode with four tokens the image goes on to the "?" reply, which it prints if
the frame was "iDB01" (0x81716). Console preset: token pointers as `console_init` sets them, a line of machine frames
(checksum right or wrong) or interactive commands, length, state 0/1/other, echo and mode. **Equivalent**: 200 trials
(95 % of 102 blocks), 2,000 trials with seed 7 (98 %).

`console_cmd_d` is now **byte-identical**: the dump helper prints its trailer itself, so the dump buffer is still in
scope at that call and GCC does not turn it into a tail call, as in the image [fact: 0x81364 bl console_puts, then the
epilogue]. The `d`/`w` order: GCC 10.2.1 emits `console_cmd_i, _d, _w`, the image has `i, w, d`; neither the
declaration order, the table position, global handlers nor the dump as a macro changes that [fact: compiled variants],
and `-fno-toplevel-reorder` does not fit the image (it stops GCC from inlining the line executor into
`console_rx_char`, which the image has inlined) [fact]. `__attribute__((noinline))` on `console_cmd_i` and `_w` (no
code effect: they are reached only through the command table) gives the image's order. *Open: which form of Yaesu's
source gives that order without an attribute; would be settled by GCC's -fdump-ipa-cgraph order for candidate
sources.*

### M33: link layout (`tools/equiv_m33.py layout -v`, new)

23 of 430 functions at their original address, **405 of 429 consecutive pairs with the original spacing** (round 2:
402), **428 in the original order** (round 2: 427). The remaining spacing differences all follow a function that is
equivalent but not byte-identical (the first: `aic3204_spi_write`, 96 vs 104 bytes), so every address after it moves.
*Open: byte matches for the remaining 34 equivalent functions (or padding); would be settled per function with
`equiv_m33.py diff`.*

### M33: results (status.tsv, round 3)

| Verdict | Ghidra functions | Bytes (of 29,282) |
|---|---:|---:|
| identical | 415 | 22,220 |
| equivalent | 34 | 7,062 |
| differs | 0 | 0 |
| not yet | 0 | 0 |

**Re-implemented: 100.0 %** of the 449 functions of the re-export, the same figure as the README (plus 18 identical
functions Ghidra's list lacks). Round 2 measured 86.5 % against the old 427-function list.

### M33: Ghidra (round 3)

0x872F4 `printf_float_none` (the hook the sprintf family passes to the core: literal 0x872F5 at 0x85B04, 0x85B7C,
0x85BD8; `movs r0, #0; bx lr`) is added to `tools/ghidra/entries_m33.tsv`, `IfdspM33Names.java`,
`names_ifdsp.T12d.tsv` and `signatures_m33.tsv` (int32 (void)). Proved on a copy (`/home/user/ghidra_tasks/t24r3/proj`,
OWNER root) [fact: logs there]: FixFuncEntries 43 created, 0 failed; IfdspM33Names 407 named; ApplySignatures 257
applied, 0 failed; ExportDecomp **450 functions**, 0 failed, 150 warnings (the re-export has 449). Apply to the
canonical project with the round-2 command block above (the first three tools, then CommentCode, ExportDecomp, the
purposes pass and the readability stats exactly as listed there); afterwards `src/ifdsp_m33/aliases.tsv` can drop its
`printf_float_none` row.

### DISPLAY: harness (`tools/equiv_display_emu.py`)

The A32/Thumb counterpart of `equiv_m33_emu.py`:

- **Start state** = the memory after `__scatterload`: the image at 0x20100000, the three LZ regions of the
  Region$$Table (0x204286A8) decompressed by the image's own `__decompress` (0x20100BFC, run in Unicorn), plus the
  locale set-up of `__rt_lib_init` (libspace 0x2091D530 +4 and +0xC from 0x20163874 / 0x201638A0): without it
  `tolower` and everything else using the ctype table read through a NULL pointer [fact: trials faulted at
  0x201549EE]. The C++ constructors that `__rt_lib_init` runs next are not run (they touch peripherals).
- **Linking**: R_ARM_CALL/JUMP24 (BLX to Thumb functions, a veneer for a tail branch to one), ABS32, MOVW/MOVT; the
  scratch area is at 0x21000000, inside the ±32 MB reach of BL from `.text` (a first try at 0x30000000 jumped into
  nowhere). The instruction set of every original function is in `src/display/modes.tsv` (64 of 2,251 are Thumb),
  exported by the new `tools/ghidra/ExportFuncModes.java`.
- **Stubs**: the NORTi service calls `itron_*` (argument counts from µITRON 4.0; seeded returns among E_OK, E_TMOUT,
  E_PAR; a seeded word through output pointers); MMIO 0x3FE00000.., 0xE8000000.., 0xFCFE0000.. through `mmio_map`.
- **Compared**: end, r0 (r0:r1 for 8-byte returns), RW memory (boot-info block, `.data` .. end of RAM, the uncached
  mirror, the argument buffers), SCTLR, MMIO and stub-call sequences; plus a **static comparison of the CP15
  operations**, because Unicorn executes cache and TLB maintenance as no-ops [fact: the mutation DCCIMVAC → DCIMVAC
  passed the emulation and is caught by the static comparison].
- **Budget**: armcc and GCC code differ in length, so a trial where only one side runs out of the 1M-instruction
  budget is re-run with 8M; one where both run out is inconclusive (not compared; counted in the detail). Coverage
  uses one self-removing code hook per static block leader (a block hook made a CRC check take 7 minutes).
- **Build flags that the check needs**: `-fno-ipa-ra` (GCC otherwise keeps r0 across a call to a function of the same
  file, which the check replaces by the image's own: `gpio_cfg_out_low` faulted) and
  `-fno-tree-loop-distribute-patterns` (the copy loops of `lib/memory.c` would become calls of themselves).
- `status` runs the functions in parallel and writes `src/display/status.tsv` (one row per Ghidra function, as the
  M33); `tools/readability_stats.py` reads it for the "Re-implemented" column.

### DISPLAY: recreated (src/display, round 3)

`lib/string.c`, `lib/memory.c`, `lib/aeabi_div.c`, `lib/misc.c`, `app/crc.c`, `drivers/cp15.c`, `drivers/gpio.c`
(src/display/README.md lists the functions). Findings on the way:

- armcc's `strcmp` returns `rrx(b' - a')` from its word loop, not a byte difference; `memcmp` returns -1/1 from its
  word loop and the difference from its byte loop [fact: 0x201553EC..0x20155448, 0x2015507C].
- 0x20155180 (Ghidra: `memcpy`) returns with r0 at the end of the destination, so it is the void `__aeabi_memcpy`, not
  C `memcpy` [fact: its exits]; `__aeabi_idivmod` by zero returns quotient 0 and the dividend as passed, also when
  negative [fact: emulation]; the `__aeabi_idiv0` hook is a nop (0x2015569C).
- Ghidra's decompiled C of `gpio_cfg_out_low`, `gpio_cfg_out_high` and `gpio_cfg_input` leaves out their first call,
  `gpio_cfg_reset` [fact: bl 0x201003A0 at 0x20100428, 0x2010084C, 0x2010088C].
- **Two Ghidra names were swapped**: 0x20100FD8 issues DCCIMVAC (clean and invalidate) and 0x20101088 DCIMVAC
  (invalidate); `dcache_setway_all` op 0 is DCISW and op 2 DCCISW; the TLB helpers flush the branch predictor
  (BPIALL), not the I-cache [fact: the mcr encodings, ARMv7-A ARM B4.2.1]. Corrected in
  `docs/code/display/boot-rtos.md` and the names files (below).

### DISPLAY: results (status.tsv, round 3)

| Verdict | Ghidra functions | Bytes (of 396,272) |
|---|---:|---:|
| equivalent | 88 | 6,250 |
| differs | 0 | 0 |
| not yet | 2,125 | 390,022 |

**Re-implemented: 1.58 %** (README column "Re-implemented" of the DISPLAY row, from `src/display/status.tsv`). By
group: string 12, memory 5, division 4, small helpers 15, CRC 5, CP15/MMU 16, GPIO 31. Mutations reported as differing:
the CRC polynomial, strcmp's zero-byte test (once the string preset had bytes >= 0x80; with ASCII only it passed),
DCCIMVAC → DCIMVAC (by the CP15 comparison); a carry mutation inside `x != y` of strcmp is semantically equivalent and
passes.

### DISPLAY: Ghidra (round 3)

`tools/ghidra/names_display.tsv` (and `names_display.T23e3.tsv`): 0x20100FD8 `dcache_invalidate_range` →
`dcache_clean_invalidate_range`, 0x20101088 `dcache_clean_invalidate_range` → `dcache_invalidate_range`, 0x2010101C
`dcache_invalidate_all` → `dcache_clean_invalidate_all`, corrected comment of `dcache_setway_all`, and four new names
**[inference from their CP15 operations]**: 0x20100D0C `mmu_disable`, 0x20100D6C `mmu_enable`, 0x20100DC0
`mmu_set_cacheable_ro`, 0x20100F84 `icache_invalidate_range`. New script `tools/ghidra/ExportFuncModes.java`
(read-only). Proved on a copy (`/home/user/ghidra_tasks/t24r3/disp`): ApplyNames 1,823 applied, 0 failed, the swap
included [fact: the function list after it]. Commands for the canonical project (repository root):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/display/quality.tsv /tmp/quality_display_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -scriptPath tools/ghidra \
  -postScript ApplyNames.java tools/ghidra/names_display.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/display" 50 \
  -postScript ExportFuncModes.java "$PWD/src/display/modes.tsv"
python3 -I tools/decomp_quality.py compare /tmp/quality_display_before.tsv decomp/display/quality.tsv display
python3 -I tools/readability_stats.py readme
```

After the re-export the alias rows of the three renamed functions in `src/display/aliases.tsv` are redundant (they
name the same addresses) and can go.

## DISPLAY, round 4 (2026-11-01)

### Plan (round 4)

1. Run-time helpers C cannot express, as assembly: `__aeabi_uldivmod` and `__aeabi_ldivmod` (quotient r0:r1,
   remainder r2:r3) and the hand-written Thumb fplib routines; the harness learns to compare r2:r3 and to report a
   function as **identical** when its bytes, linked at the original address, are the image's.
2. Drivers in C from `decomp/display` and `docs/code/display`, biggest self-contained first: RIIC, SCIF, SPI flash /
   SPIBSC, SDHI, VDC5, then the file system, the MAIN link and the update code, as far as the round goes; presets
   where a function walks a structure.
3. Linker script: a **hybrid link** that makes a complete image now: the original image (read from `build/` at link
   time, never committed) at 0x20100000 with its Region$$Table and RW regions untouched, the recreated code in the
   gap 0x2042BC10..0x2043FFFF that `reset_in_ram` already copies from flash, and each recreated function's original
   entry patched with a branch to its recreation; the original addresses of everything else come from a generated
   symbol file. Plus a minimal NORTi stand-in (`rtos/`) with the `itron_*` services the code uses, for a later
   source-only build (the hybrid keeps the original kernel, whose internals the rest of the image touches).
4. `status.tsv`, task file, READMEs, readability stats; Ghidra names with evidence, proved on a copy.

### DISPLAY: run-time helpers as assembly (round 4)

`lib/aeabi_ldiv.S` (`__aeabi_uldivmod`, `__aeabi_ldivmod`: quotient r0:r1, remainder r2:r3), `lib/fplib.S` (the armcc
double routines 0x20164888..0x20165177), `startup/vectors.S` (vectors, `Reset_Handler`, `reset_in_ram`, SVC/IRQ
entries) and `startup/rt_entry.S` (`__main` .. `__rt_entry`) are the image's own instructions with labels by
original address, drafted from a capstone listing and checked byte for byte. The harness's new verdict **identical**
links the section so that the function lands at its original address and compares the bytes; all 41 such functions
are identical (and one C function, `xorshift32_step`, came out byte-identical from GCC). Found on the way **[fact]**:
GNU as encodes `adds rd, rn, #imm3` and `subs rd, rn, #imm3` (rd = rn) as the 8-bit-immediate form, so 12 Thumb
instructions are written as `.inst.n`; capstone prints 16-bit data instructions inside IT blocks with an `s` they do
not have; two A32 entry veneers sit inside fplib (0x20164C88 for `__aeabi_d2iz`, called from 0x2011413C; 0x20164D4C
for `__aeabi_i2d`, from 0x201128D4) and Ghidra's list lacks them (*Open: their Ghidra entries; would be settled by
creating A32 functions there with TMode 0, which ApplyNames cannot do in a Thumb range*); every call of
`fp_nan_handler` is followed by a data word it reads through lr; `reset_in_ram` copies the image up to 0x2043FFFF,
past the end of the file.

### DISPLAY: drivers (round 4)

| File | Functions | Bytes | Notes |
|---|---:|---:|---|
| `drivers/riic.c` | 83 | 4,924 | Renesas sample driver; the STBCR9 dummy read Ghidra drops; GCC's `.part.0` clones are checked through their callers |
| `drivers/scif.c` | 25 | 1,696 | the C++ uart class as C; `pmu_cycle_stamp` kept out of line (the static CP15 comparison caught the inlined `mrc`) |
| `drivers/sflash.c` | 36 | 5,236 | SPIBSC transfers, flash commands, the device protocol; the state at +8 is 16 bits (strh) |
| `drivers/sdhi.c` | 39 | 1,668 | SDHI0 target layer, DMA block transfers, the operation-table slots |

Findings **[fact]**: `spibsc_ensure_idle` passes value and offset the other way round and writes 0x20 to CMNCR + 1 and
CMNCR instead of SMCR = 1, 0 (0x20104230; update.md); the SCIF RXI handler drops a byte with a dummy SCFRDR read when
the ring is full and `scif_open` reads SCLSR before clearing it (mainlink.md); `sdhi_drv_init` forwards its five
arguments to `sd_driver_op` with the hook block as sixth; `itron_acre_*` take (id, descriptor), id 0 = choose
(round 3's stubs had one argument, so the descriptor was not compared). Not done this round: VDC5, RSPI, DMAC, USB,
the file system, the MAIN link and the update code, and the large SDHI functions (`sdhi_read_response`,
`sdhi_read/write_sectors_cmd`, `sdhi_read_op`, `sdhi_open`, `sdhi0_buf_isr`).

Harness changes: runs start in SYS mode with an SVC stack, and an svc enters the image's `SVC_Handler` (the kernel's
interrupt masking `knl_int_disable` works only this way; Unicorn reports the SVC through an interrupt hook, and the
banked SP/LR follow CPSR writes [fact: a one-off test]); Thumb branch relocations and A32 BLX; presets for 64-bit
divisions, the RIIC flags, SCIF objects, the flash device object and small selectors; `check --object`; RAM
compared from 0x20440000 (below it is the hybrid image's code).

### DISPLAY: linker script, hybrid image and NORTi stand-in (round 4)

`src/display/display.ld` describes the image's layout and `tools/display_link.py` links the tree into a **complete
image**: the original (from `build/`, unchanged) at 0x20100000, the 257 functions with verdict equivalent in the gap
0x2042BC10..0x20432040 (25,648 of 82,928 bytes), the 41 identical ones left in place, everything else resolved to
the image's addresses, and 257 original entries patched with a branch (1,063 bytes changed; none too short to
patch). `.data` and `.bss` of the recreated code are empty (asserted). `equiv_display_emu.py linkcheck` runs the
hybrid image against the original at every patched entry, so the recreated functions call each other there:
**257 of 257 agree** (50 trials each). Output stays in `src/display/out/` (ignored). *Open: whether the hybrid image
boots; would be settled by packing it into an SFL (the payload is 25,648 bytes longer) and loading it on a radio with
the owner's approval, or by a whole-system emulation of the reset path.* *Open: room once the recreated code
outgrows the gap; would be settled by a second region in RAM 0x2091D570..0x2097FFFF (no reference, #119) loaded by
a recreated `reset_in_ram`.*

`src/display/rtos/` is a minimal uITRON 4.0 stand-in with the `itron_*` interface of `include/norti.h` (tasks,
semaphores, event flags, mailboxes, message buffers, mutexes, cyclic handlers, ISRs; A32 context switch), for a later
source-only build; the hybrid keeps the original kernel, whose internals other code of the image uses directly.
`tools/test_norti_standin.py` runs a two-task test of every object type in Unicorn: **passes**.

### DISPLAY: results (status.tsv, round 4)

| Verdict | Ghidra functions | Bytes (of 396,272) |
|---|---:|---:|
| identical | 41 | 3,722 |
| equivalent | 257 | 19,666 |
| differs | 0 | 0 |
| not yet | 1,915 | 372,884 |

**Re-implemented: 5.90 %** (round 3: 1.58 %).

### DISPLAY: Ghidra (round 4)

`tools/ghidra/names_display.tsv` gains 16 names with evidence: `pmu_cycle_stamp` 0x20114850, `sflash_checksum`
0x20103CC8, `spiflash_read` 0x20104078, `pmu_ccnt_read` 0x2010414C, `sflash_cycle_stamp` 0x20104154,
`sdhi_stub_2013fde4`, `sdhi_stub_2013ffdc`, `sdhi_op4`..`sdhi_op7`, `sdhi_op12`..`sdhi_op16` (operation-table
slots). Proved on a copy (`/home/user/ghidra_tasks/t24r4/disp`, OWNER root): ApplyNames 1,839 applied, 0 failed
[fact: names.log there]. Apply to the canonical project with the round-3 command block above (ApplyNames, then
ExportDecomp and ExportFuncModes, the quality comparison, the readability stats); afterwards the alias rows of these
names in `src/display/aliases.tsv` are redundant.

## DISPLAY, round 5 (2026-11-01)

### Plan (round 5)

1. Biggest self-contained parts first: VDC5 (driver 0x201179C0..0x2011D9A7, about 19 KB with the GUI helpers), then
   RSPI, DMAC, the large SDHI functions, the file system, the MAIN link, the update code, the GUI building blocks,
   as far as the round goes.
2. Ghidra: the two fplib A32 veneers as functions with TMode 0 (a FixFuncEntries mode), the functions the VDC5 work
   finds missing, the names with evidence; proved on a copy, commands for the canonical project.
3. The gap: measure it after the link; write down the second region before it overflows.
4. `status.tsv`, task file, READMEs, readability stats.

### DISPLAY: the VDC5 driver (round 5)

The image links the Renesas r_vdc5 sample driver, without its parameter checks, in four layers
(docs/code/display/gui.md "VDC5 driver structure, recreated"): the API (`drivers/vdc5_api.c`), the shared
parameters (`drivers/vdc5_shrd.c`), the interrupt part (`drivers/vdc5_int.c`) and the register layer
(`drivers/vdc5_reg.c`, part); `app/gui_vdc5.c` has the GUI's set-up helpers. The public driver (GR-PEACH_video
drivers/vdc5, 2014, read from github.com/d-kato/mbed-gr-libs into a scratch directory; Renesas licence, not
committed and not fetched by any script) was a reference for the structure and the field names; the C is written from the
image's disassembly, and where the two differ the image wins (it is an older version: `vdc5_sync_delay_t` starts
with a byte) **[fact: the ldrb at 0x20119824]**. armcc stores the driver's enums in one byte, so the parameter
structures keep the public field order with uint8_t enum fields **[fact: the ldrb/strb offsets]**; the function
arguments stay words (armcc does not narrow them).

| File | Functions | Bytes (Ghidra) | Notes |
|---|---:|---:|---|
| `drivers/vdc5_api.c` | 25 | 2,236 | 23 API calls and the two layer-id maps (2 of them not in Ghidra's list, 0 bytes counted yet) |
| `drivers/vdc5_shrd.c` | 41 | 2,124 | every shared-parameter function |
| `drivers/vdc5_int.c` | 49 | 4,188 | callbacks, `r_vdc5_get_isr`, the 46 handlers (one inline pattern) |
| `drivers/vdc5_reg.c` | 40 | 7,544 | (1 unlisted) initialize, terminate, video input, sync, output and TCON, colour matrices, start/stop/release, noise reduction, black stretch, alpha, calibration |
| `app/gui_vdc5.c` | 13 | 1,056 | module clock, TCON tables, LVDS PLL block, sync/output set-up, the line interrupt |

Findings **[fact]**:

- **0x20117AD4 is R_VDC5_VideoInput** (Ghidra: `r_vdc5_terminate`): it records the input (0x2011D1F4, Ghidra
  `vdc5_shrd_terminate`), programs it (0x201197C0, Ghidra `vdc5_reg_terminate`) and sets resource 1, "video in".
  R_VDC5_Terminate is the unlisted function **0x20117A68** (its register part 0x201195E8);
  R_VDC5_ReleaseDataControl **0x20117F3C** and SetInputCntrlColorMtx **0x2011A20C** are unlisted too.
- `vdc5_reg_initialize` sets LPHYACC (&= ~3, |= 1) between the two LVDS PLL waits (0x20119464); the first draft
  lacked it and the check reported the MMIO sequence as differing.
- `vdc5_isr_create` returns the kernel's error code when `itron_acre_isr` fails (its `ble` jumps past `mov r0, #0`).
- The 46 VDC5 handlers are one pattern (type t: SYSCNT_INT(1 + t / 8), enable INT(4 + t / 8), bit 1 << 4 (t % 8),
  callback 0x208DCC0C[23 ch + t]); in C they are one inline function and a macro, checked one by one.

Harness (`tools/equiv_display_emu.py`): a VDC5 preset for every `vdc5_*` / `r_vdc5_*` function: channel 0 or 1;
r1..r3 and two stack words small values (layer ids -1..9, interrupt types) or parameter blocks whose words are NULL
or valid pointers and whose bytes are 0..3; resource and layer states 0/1; callbacks NULL or an empty function
(0x2013FDE4). Out-of-range enum bytes and channel 2 were dropped after two "differs" verdicts that were not
differences of the code: the driver indexes tables (`dither_format`, `output_pin_regaddr`, the register tables) with
them, and an index past the end reads whatever lies next to the table, which is the stack in the image and
.rodata in the GCC build. Presets for the helpers that take a register-address table (`vdc5_tcon_*`,
`vdc5_set_video_external_input`, `vdc5_set_color_matrix`). `status` keeps rows for recreated functions whose
address Ghidra's list lacks (ghidra_name "-", the address, 0 bytes counted), so that they are linked too.

Not done this round: the rest of the VDC5 register layer (write/read data control and their changes: scaling,
cascade, VIN; image enhancement, alpha rectangle, chroma key, CLUT, gamma; about 6.5 KB), `vdc5_layers_setup`,
`vdc5_layers_stop`, `vdc5_channel_shutdown`, and RSPI, DMAC, the large SDHI functions, the file system, the MAIN
link, the update code and the GUI building blocks. Blocker for the pace: the container is shared with other
sessions' SDR simulations (load 8..10 on 4 cores), so checks ran slowly; the final 200-trial status run of all 466 recreated functions took 27 minutes.

### DISPLAY: Ghidra (round 5)

`tools/ghidra/FixFuncEntries.java` learns column 2 **`arm`**: it clears the 8 bytes at the entry, sets TMode 0 there,
disassembles them as A32 and re-creates the function around them at its own entry. `entries_display.T24r5.tsv`
has this round's five entries alone (also appended to `entries_display.tsv`): 0x20117A68, 0x20117F3C, 0x2011A20C
and the veneers 0x20164C88 / 0x20164D4C (`arm`). `names_display.tsv` gains 61 names with evidence, among them the
three renames above and `__aeabi_d2iz_a32` / `__aeabi_i2d_a32`. Proved on a copy
(`/home/user/ghidra_tasks/t24r5/disp`, OWNER root) [fact: apply.log, modes.tsv there]: FixFuncEntries 5 created,
0 failed, 5 branches marked as tail calls; ApplyNames 1,899 applied, 0 failed; ExportFuncModes: the veneers are
8-byte **arm** functions, `__aeabi_d2iz` and `__aeabi_i2d` keep their sizes (thumb); the other changes are the
consequences: the two veneer callers 0x20112894 / 0x201140F4 lose the 8 bytes Ghidra had folded in, and
`vdc5_layers_stop` / `vdc5_channel_shutdown` end in tail calls of the new terminate and release functions. (Running
the whole `entries_display.tsv` again instead also swaps the known one-instruction entries 0x20139654 /
0x2013FE64, T22; hence the separate file.) Commands for the canonical project (repository root):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/display/quality.tsv /tmp/quality_display_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -scriptPath tools/ghidra \
  -postScript FixFuncEntries.java tools/ghidra/entries_display.T24r5.tsv \
  -postScript ApplyNames.java tools/ghidra/names_display.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/display" 50 \
  -postScript ExportFuncModes.java "$PWD/src/display/modes.tsv"
python3 -I tools/decomp_quality.py compare /tmp/quality_display_before.tsv decomp/display/quality.tsv display
python3 -I tools/equiv_display_emu.py status
python3 -I tools/readability_stats.py readme
```

After the re-export the alias rows of the renamed and newly listed functions in `src/display/aliases.tsv` are
redundant, and the three unlisted VDC5 functions start to count in "Re-implemented".

### DISPLAY: the gap and the second region (round 5)

Measured on the hybrid link **[fact: display_link.py, nm of display_hybrid.elf]**: 425 functions in the gap
0x2042BC10..0x204368AB, **44,188 of 82,928 bytes** (round 4: 25,648). Over the 422 equivalent functions GCC's code
is 1.17 times armcc's (42,956 against 36,814 bytes). The gap has 38,740 bytes left, about 33 KB of original code at
that ratio, while 355,736 bytes are not recreated yet (about 416 KB of GCC code): **the gap overflows in the next
round**, so the plan is written down here.

1. **In place first.** A recreated function whose code fits into its original extent is linked at its original
   address (no patch, no gap): 111 of the 422 fit today (10,492 bytes) **[fact: same measurement]**. The extent
   is the Ghidra function up to the next original function, the rule `covered` already uses; display.ld gets one
   output section per such function at its address, and display_link.py checks that it stays inside.
2. **Second region RAM2 = 0x20920000..0x2097FFFF (384 KiB)**, in `ram_hi` above `.bss2` (ends 0x2091D56F) and
   below the NORTi pool base 0x20980000, which no literal or MOVW/MOVT pair of the image points into
   **[fact: docs/memory-maps.md `ram_hi`, #119]**. Gap + RAM2 = 432 KB for the remaining about 416 KB, before step 1
   and before trying `-Os` (not measured yet).
3. **Loading.** `reset_in_ram` copies the bank image to RAM up to 0x2043FFFF **[fact: 0x20100244/0x20100248]**;
   the hybrid image appends RAM2's bytes at file offset 0x340000 (= 0x20440000 - 0x20100000), and a second copy
   loop (the recreated `reset_in_ram`, which then is no longer byte-identical) copies them from the bank to
   0x20920000, then cleans the D-cache and invalidates the I-cache over the range before anything jumps there.
   A bank holds 6 MiB **[fact: docs/code/display/update.md section 6]**, the image 3.3 MB, so the file still fits.
   display.ld gets `RAM2 (rx) : ORIGIN = 0x20920000, LENGTH = 0x60000` and a `.recreated2` section that takes
   what does not fit into the gap.
4. Open: whether anything writes into 0x2091D570..0x2097FFFF at run time through a computed pointer (the scan of #119
   finds only literal and MOVW/MOVT references); would be settled by an emulated boot of the original image with a
   write watch on that range, or a store-target scan of the decompiled code. Open: the MMU attributes of RAM2 (the
   flat L1 table makes it executable, XN = 0 in 0x10C02 **[fact: mmu_l1_table_init]**; whether `mmu_set_cacheable`
   covers it decides only the speed); would be settled by reading the `mmu_set_cacheable` calls of `Reset_Handler`.

### DISPLAY: hybrid image (round 5)

`tools/display_link.py`: 425 recreated functions in the gap (the 422 equivalent ones and the three VDC5 functions
Ghidra's list lacks), 425 original entries patched (1,732 bytes changed), none too short to patch.
`equiv_display_emu.py linkcheck` (100 trials per entry): **425 of 425 agree**. The first run had three "differs",
none a difference of the code: `tolower` with c outside EOF..255 (the table read lands in the hybrid's recreated
code), `vdc5_output_setup` with a display mode other than 0/1 (past the two-entry timing tables), and
`vdc5_vline_cb_enable`, which stored the recreation's address of `vdc5_vline_cb` where the image stores its own entry
0x20133014. The first two got presets for their domain; the third now stores the image's entry
(`vdc5_vline_cb_entry` in aliases.tsv), which the hybrid's patch forwards to the recreation.

### DISPLAY: results (status.tsv, round 5)

| Verdict | Ghidra functions | Bytes (of 396,272) |
|---|---:|---:|
| identical | 41 | 3,722 |
| equivalent | 422 | 36,814 |
| differs | 0 | 0 |
| not yet | 1,750 | 355,736 |

Plus three equivalent functions at addresses Ghidra's list lacks (0x20117A68, 0x20117F3C, 0x2011A20C; rows with
ghidra_name "-", 0 bytes counted until the re-export). **Re-implemented: 10.23 %** (round 4: 5.90 %); the VDC5 work
is 165 of the new functions and 17,148 bytes.

### DISPLAY: follow-up after the re-export (round 5)

After the round-5 Ghidra changes were applied to the canonical project and `decomp/display` re-exported, a status
run in the main checkout gave `vdc5_reg_display_output` "differs" (MMIO, at trials 4/8/7 with seeds 1/2/3). Cause
**[fact]**: that build used the default `arm-none-eabi-gcc` (GCC 13.2.1), and the generic VDC5 preset puts a
pointer into the word at +0x24 of `vdc5_output_t`, so `out_format` (+0x27) is 0x21; the driver indexes its 4-entry
dither table with it, and past the table the image reads its stack (the table is a local array there) while the
GCC build reads whatever follows the table in its .rodata. GCC 13 lays .rodata out differently from GCC 10.2.1, so
the GCC 10 runs happened to read equal words. Not a code difference: the input is outside the driver's domain.
Fix: a preset for the display-output calls that builds a valid `vdc5_output_t` (TCON timings with pin -1..6, the
enum bytes in range). With it the function is equivalent at seeds 1, 2 and 3 with 100 % block coverage (60 % to 80 %
before), and the mutation dither 0x10000 → 0x10001 is reported as differing. `equiv_display_emu.py status` and
`check` now stop with a message and exit 1 when `src/display/out/obj` has no objects (they used to write an
all-"not yet" table). The recreated code passes with either compiler; the Makefile's default `CROSS` is whatever
`arm-none-eabi-gcc` is on the path, and the status run after this fix (GCC 13.2.1, 200 trials) gives identical 41, equivalent 425, differs 0, **10.31 %** (40,844 of 396,256 bytes; the three formerly unlisted VDC5 functions count now). The display-output functions also pass with xPack GCC 10.2.1.

## MAIN, round 1 (2026-11-01)

### Plan (MAIN round 1)

1. Identify the compiler and options from the image (strings, run-time library, code shapes); find out whether CC-RX
   can be obtained and installed here; otherwise build GCC for RX and plan equivalence checking.
2. An equivalence harness for RX on Ghidra's p-code emulator (Unicorn has no RX), modelled on `equiv_m33_emu.py` and
   `equiv_display_emu.py`: link each recreated function alone against the image's addresses, run both on the same
   inputs, compare return, registers, RAM and the peripheral sequence; presets, block coverage, a mutation test.
3. First functions in `src/main/`: run-time and library helpers, then the self-contained Code Generator drivers (SCI,
   EEPROM, timers, A/D, DA, IWDT, pins); `src/main/status.tsv` wired into the "Re-implemented" column.

### MAIN: compiler and options

No string in the image names a compiler, library or version [fact: `strings` of the whole image; the only
library string is lowsrc's `C:\stdin`/`C:\stdout`/`C:\stderr` at 0xFFF8F2E9..0xFFF8F300]. What the code shows:

| Item | Finding | Evidence |
|---|---|---|
| Compiler | **Renesas CC-RX** **[inference]** | the CC-RX start-up and library structure: `_INITSCT` driven by the section tables DTBL {src, end, dst} and BTBL {start, end} (0xFFFEDEDA, tables 0xFFF8E6A0/0xFFF8E6C4), `_INIT_IOLIB`/`_CLOSEALL` and the lowsrc console on the E1/E2 debug registers (docs/code/main/bsp.md); two code shapes that **GCC 13.3.0 for RX does not produce at -O0, -O2 or -Os [fact: compiled here]**: the switch as `MOV.W [Ri, table], R14; BRA.L R14` over a table of 16-bit offsets (`cat_dispatch` 0xFFFA3B8A, `R_S12AD1_Get_ValueResult` 0xFFF92CC4; GCC uses a table of absolute addresses and `JMP Rn`), and frames addressed from SP (`SUB #4, R0` ... `RTSD #4`, `eeprom_spi_tx` 0xFFFB15AA; GCC -O0 sets up R6 as a frame pointer). *Open: whether Renesas's own GCC for RX (GNURX/"GCC for Renesas") can produce these shapes; would be settled by compiling `r_cg_sci.c` with it (llvm-gcc-renesas.com, refused by the proxy)* |
| Optimization | **level 0 for the application and drivers** **[inference]** | every parameter and local is stored to the stack and reloaded at each use (`eeprom_spi_tx` 0xFFFB15AC `mov.b r1, 3[r0]`, `eeprom_write`); functions without locals use registers only (`r_sci0_transmit_interrupt` 0xFFF9340E). The library functions are optimized (`strncmp` 0xFFFEDE1D and `__udiv64` 0xFFFEDE41 keep everything in registers), as a precompiled library would be |
| Instruction set | **RXv2 with FPU** (CC-RX `-isa=rxv2 -fpu`) **[inference from the instructions]** | FTOU, an RXv2-only instruction, at 12 sites (e.g. 0xFFFA2B59, 0xFFFAE71E) [fact: rx-elf-objdump; T21c]; FADD 31, FMUL 28, FDIV 25, FSUB 18, FCMP 40, ITOF 42 sites [fact] |
| `double` | **32 bits** (CC-RX `-dbl_size=4`) **[inference]** | the C library at 0xFFFEDD9A..0xFFFEE2B7 has no floating-point routine, and every floating-point operation is an FPU instruction (the FPU is single precision) |
| Endian | little | option-setting memory 0xFE7F5D00.. all 0xFF (MDE = little) [fact: docs/memory-maps.md, T18] |
| Driver source | **Renesas Code Generator** (`r_cg_*`, `R_<module>_Create/_Start/_Stop`, empty `_Create_UserInit`) **[inference: names and structure, T05/T23d]** | e.g. `R_SCI0_Create` 0xFFF9321F .. `R_SCI0_Create_UserInit` 0xFFF9340D (`rts`); BSP pieces with the FIT `r_bsp` API (`R_BSP_InterruptRequestEnable`, `R_BSP_SoftwareInterruptControl`, bsp.md) |
| CC-RX version | **Open** | *Open: the version and the exact options; would be settled by compiling the Code Generator's `r_cg_sci.c`/`r_cg_sci_user.c` at `-optimize=0 -isa=rxv2 -fpu` with each candidate CC-RX release and comparing bytes, as done for the M33 GCC (the image's `-optimize=0` code is regular enough that a byte match per function is likely), or by the release notes of the first CC-RX release that emits FTOU* |

**Obtaining CC-RX: blocked.** www.renesas.com (where the evaluation edition and its licence are published) and
llvm-gcc-renesas.com are refused by the container's proxy [fact: `curl` CONNECT 403, and the proxy's
`recentRelayFailures` list `connect_rejected` for both hosts, 2026-11-01]; the evaluation edition's licence terms
and whether it runs on Linux could not be read. *Open: whether the CC-RX evaluation edition may be used for this
(and installed on the owner's machine); would be settled by its licence agreement on renesas.com, which the owner
can read in a browser.* Even with CC-RX, nothing of it may be committed (AGENTS.md).

**Route taken: GCC 13.3.0 for RX** (built from Ubuntu's source tarballs, docs/tooling.md "GCC for RX") and differential
emulation. Mainline GCC knows RXv1 only (`-mcpu=rx600`); the RX651 runs RXv1 code unchanged (RXv2 is a superset),
and GCC's RX ABI passes R1..R4 and returns R1 (R1:R2 for 64 bits), with R6..R13 preserved, as CC-RX's code does
[fact for the image: every call site and callee checked by the harness below; the cspec of the rx62t module agrees].
Byte matches are possible only where the code is trivial: the empty `*_UserInit` hooks, `R_DA0_Stop` and the four
TPU start/stop functions came out byte-identical at their original addresses [fact: status.tsv].

### MAIN: harness (`tools/equiv_main_emu.py`, `tools/ghidra/EquivMainEmu.java`)

- **Engine.** `EquivMainEmu.java` is a headless Ghidra script that serves JSON requests on stdin: it builds a
  `ghidra.pcode.emu.PcodeEmulator` on the program's language (`rx62t:LE:32:default`, the module with all of
  T17..T22's patches) for every run and watches it with `PcodeEmulationCallbacks` (beforeLoad, afterStore,
  handleMissingUserop). One Ghidra process per worker serves a whole check (start-up about 10 s, a run of a small
  function 5 to 50 ms). Each worker opens its own copy of the project (Ghidra locks an open project, also
  read-only: three workers on one copy died in the first try).
- **Memory.** RAM 0x0..0x3FFFF as after `_INITSCT` (the three DTBL copies), the image at 0xFFF80000, the recreated
  code at 0xFFF00000 (inside BSR.A's +-8 MB reach). Peripheral loads (0x80000..0xFFFFF, 0x7FC000..0x7FFFFF) return a
  seeded random sequence and every access is recorded (kind, address, width, value); any other access ends the run as
  a fault. The string compare pcodeops `scmpu`/`suntil`/`swhile` are implemented after the manual.
- **Linking.** `rx-elf-ld --gc-sections` per function: every other Ghidra name and every `data_symbols.tsv` name is
  defined at its original address in the script (a script assignment overrides the object's own definition [fact:
  a test link]), so the function calls the image's own callees; recreated `.data`/`.bss` is refused.
- **Inputs.** R1..R4 and stack words from the DWARF parameter types (CC-RX callers extend char/short arguments
  [fact: `eeprom_read` 0xFFFB14BA..0xFFFB14C3]; 64-bit arguments as register pairs); pointers to random buffers
  or strings; the RAM bytes the two runs read before writing are collected over the trials and filled with random
  words, small values or pointers; interrupt handlers (the original contains RTE) get a PSW on the stack.
- **Compared.** End (return, fault with its address, budget), R1 (R1:R2) masked to the DWARF return size, R6..R13
  (R1..R15 for an interrupt handler), PSW.I and IPL, RAM 0x1404..0x3FFFF, the peripheral sequence, stub calls;
  **equivalent** needs every trial to agree, one normal return and half of the original's basic blocks
  (Ghidra's SimpleBlockModel); one-sided budget exhaustion is re-run with 8 times the budget.
- **Instruction forms.** T22a checked the module's p-code only on the forms MAIN uses. Every result lists the forms
  the recreated code uses that MAIN does not. One of them was wrong: **`JMP Rs` is `PC = Rs` without a branch, so
  the emulator falls through** [fact: a trace of `R_S12AD0_Get_ValueResult`, GCC's switch `jmp r14` continued at
  the next instruction; T22a had listed it as known and unfixed because MAIN has none]; the engine executes JMP
  itself. Still unchecked (they agree in every trial, but T22a has not modelled them): 3-operand `mul`/`or`/`sub`
  and `scgtu.l` (libgcc's `__udivdi3`), `mov.b Rs, [Rd+]`, `rotl Rs, Rd`, `bra.a`. *Open: their semantics; would be
  settled by `tools/rx_semcheck.py` cases for these forms.*

**Mutation test** (a one-off script, not committed: one source change, rebuild, `check` with 200 trials, restore):

| Mutation | First run | With the presets |
|---|---|---|
| M1 SCI0 BRR 0xC2 → 0xC3 | differs (peripheral write #14) | |
| M2 `eeprom_spi_rx` samples MISO before SCK rises | differs (R1) | |
| M3 RXI clears RE before RIE (SCI0, SCI4) | differs (peripheral write #1) | |
| M4 `eeprom_write` page 64 → 32 | differs (peripheral write #1895) | |
| M5 `strncmp` stops at a shared NUL (ISO C) | **passed** (random strings never share a prefix) | differs (trial 24) |
| M6 `sbrk` `>=` for `>` | **passed** (the limit is never hit exactly) | differs (trial 2) |
| M7 `sci5_rx_byte_hook` 'r' → 8 bytes | **passed** (the first byte is never 'r') | differs (RAM 0x1B626) |

The three that passed showed where random inputs do not reach the interesting cases; the presets added for them
(two strings with a shared prefix, sbrk around its limit, the SDR reply bytes; also 64-bit divisors, EEPROM lengths,
A/D channel numbers) catch all seven, and the recreated originals stay equivalent with them (100 % of the blocks for
`strncmp`, `sbrk`, `sci5_rx_byte_hook`).

### MAIN: recreated (src/main, round 1)

`drivers/r_cg_sci.c`, `drivers/r_cg_sci_user.c` (SCI0..SCI5 written once as inline helpers over a constant
channel description, `drivers/sci_cfg.h`, folded per channel; Yaesu's callbacks and receive hooks), `drivers/eeprom.c`,
`drivers/r_cg_misc.c` (IWDT, DA, TPU0/1), `drivers/r_cg_s12ad.c`, `drivers/r_cg_init.c` (`icu_select_init`,
`R_Pins_Create`, `mpc_pin_functions_init`, `FUN_fff92e25`), `lib/runtime.c`, `bsp/r_bsp.c` (src/main/README.md lists
the functions). Register names come from `tools/ghidra/sfr_rx651.tsv` through a generated `iodefine.h`
(`tools/main_iodefine.py`, build time, not committed). Findings **[fact]**:

- CC-RX's `strncmp` (0xFFFEDE1D) does not stop at a NUL both strings share: it compares n bytes (or up to the first
  difference), so `"ab\0x"` and `"ab\0y"` with n = 4 differ, unlike ISO C (docs/code/main/bsp.md).
- `heap_getmem` returns sbrk's pointer or NULL (`stz #0, r1`, 0xFFFEE2B2), not a flag.
- The CC-RX bit-field writes to IPR keep the field's zero bits only: priority 8 is `(IPR & 0xF8) | 8`, 10 is
  `(IPR & 0xFA) | 0x0A` (`R_SCI0_Create`, `R_SCI1_Create`), which leaves the same value as the field insert.
- Unlisted in Ghidra: the intrinsic setters between the getters (0xFFF9125F `mvtc r1, bpc`, 0xFFF91276 `mvtc r1,
  extb`, 0xFFF9128D/0xFFF91291 `mvtachi`/`mvtaclo`, 0xFFF912BB/BF/C3 byte `bset`/`bclr`/`bnot` helpers) and
  0xFFF927E0 (`bsr.a sw_reset; rts`, the callback registered at index 7, sci.md). *Open: their Ghidra entries and
  names; would be settled by FixFuncEntries rows with this evidence, proved on a copy.*

### MAIN: results (status.tsv, round 1)

| Verdict | Ghidra functions | Bytes (of 387,054) |
|---|---:|---:|
| identical | 26 | 89 |
| equivalent | 107 | 10,822 counted (10,593 own) |
| differs | 0 | 0 |
| not yet | 3,660 | 376,372 |

**Re-implemented: 2.82 %** (README column of the MAIN row). By file: SCI 81 functions (4,840 bytes), pins/ICU/MPC 4
(2,957), S12AD 12 (1,492), IWDT/DA/TPU 18 (489), EEPROM 4 (398), library 7 (574), BSP 7 (161). The status run
(200 trials, 3 workers) took about 15 minutes.

### MAIN: blockers and next steps

- **CC-RX** is not obtainable from the container (above), so no byte match and no CC-RX version; the owner could
  check the evaluation licence and, if it allows, run the version comparison on his machine.
- Next, by size and self-containment: the BSP (interrupt control, software-interrupt queue, group dispatchers),
  the soft timers, the C library's stdio and heap, then the links (DISPLAY, SDR, DSP), the CAT parser and handlers.
- A hybrid image (as DISPLAY's) needs room: the code area ends at 0xFFFEE2B7 and 0xFFFEE2B8..0xFFFFFEFF is 0xFF fill
  (about 72 KB) [fact: docs/memory-maps.md]. *Open: whether the flash update writes that range; would be settled by
  the SFL loader's erase/write ranges (T04).*

## Open steps

1. M33: byte matches for the 34 equivalent functions, which would also put the functions after them at their
   original addresses (`equiv_m33.py layout -v` lists where the spacing breaks; the first is `aic3204_spi_write`).
2. M33: the floating-point path of the printf core, with a preset hook that fills the digit buffer (round 3 above).
3. Apply the round-3 Ghidra changes to the canonical projects with the commands above (M33: the `printf_float_none`
   entry; DISPLAY: the CP15 renames and the four new names), and DISPLAY rounds 4 and 5 with the round-5 command
   block (FixFuncEntries with `entries_display.T24r5.tsv`, ApplyNames), and re-export (T23 rules).
4. DISPLAY, next by size and self-containment: the rest of the VDC5 register layer (write/read data control,
   scaling, cascade, VIN, enhancement, alpha rectangle, chroma key, CLUT, gamma; about 6.5 KB) and
   `vdc5_layers_setup`, then RSPI (7.6 KB), DMAC, the rest of SDHI, USB, the file system, the MAIN link and the
   update code; then the application.
5. DISPLAY build: the hybrid image links and passes linkcheck; before the next round's code goes in, the in-place
   placement and the second region RAM2 of "the gap and the second region" (round 5); a source-only image needs the
   rest of the tree, the NORTi stand-in's port (IRQ entry and exit, the OSTM tick) and a recreated `reset_in_ram`.
   Function addresses that the recreated code stores as data must be the image's entries (round 5: one alias,
   `vdc5_vline_cb_entry`); *Open: a general rule in display_link.py; would be settled by resolving the ABS32 and
   MOVW/MOVT references to linked functions from data stores to their original entries.*
6. HiFi4 (Ghidra p-code): `tools/ghidra/EquivMainEmu.java` is the model (a headless p-code emulator server).
7. MAIN: the next functions (BSP, soft timers, C library, then the links and the CAT code), the semantics of the
   instruction forms only the GCC code uses, the Ghidra entries of the unlisted helpers, and the CC-RX version if the
   owner can obtain CC-RX ("MAIN, round 1").
