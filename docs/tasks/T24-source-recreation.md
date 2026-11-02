# T24 — Recreate the source code of every image

**Status:** in progress (2026-11-01; IFDSP M33 100.0 % re-implemented, round 3; DISPLAY 19.09 % re-implemented, round 8; MAIN 19.98 % re-implemented, round 4; the hybrid image links in place, into the gap and into RAM2, passes linkcheck (634 of 634) and boots in emulation as far as the original) · **Depends on:** T12, T21, T23 · **Issue:** (created by `tools/issues_sync.py`)

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

**Owner decision (2026-11-01): use the CC-RX evaluation edition.** It is still not reachable from the container (www.renesas.com fails at the proxy). It becomes usable once the owner either allows the Renesas download host in the environment's network settings or puts the installer in the container. Nothing of CC-RX (installer, compiler, libraries, licence files) may be committed (AGENTS.md); builds with it stay in `src/main/out/`.

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
  settled by `tools/rx_semcheck.py` cases for these forms.* Settled in round 2 ("MAIN: semantics of the GCC-only forms"): all of them agree with the manual; JMP Rs, BNOT Rs,Rd, same-register post-increment stores and REVL/REVW Rd,Rd were SLEIGH bugs, fixed by `rx62t-gccforms-fix.patch`.

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

## DISPLAY, round 6 (2026-11-01)

### Plan (round 6)

1. The gap: round 5's plan (in place, then RAM2 with a recreated `reset_in_ram`), after settling whether anything
   writes into 0x20920000.. through a computed pointer (an emulated boot with a write watch).
2. A general rule in `display_link.py` for function addresses the recreated code stores as data.
3. More code, biggest self-contained first: the rest of the VDC5 register layer and `vdc5_layers_setup`, RSPI,
   DMAC, the large SDHI functions, the file system, the MAIN link, the update code, as far as the round goes.
4. One compiler for the DISPLAY tree, selected by the Makefile.
5. `status.tsv`, linkcheck, readability stats; Ghidra names with evidence, proved on a copy.

### DISPLAY: is RAM2 free? An emulated boot (round 6)

`tools/display_boot_emu.py` (new) boots the image in Unicorn as the CPU sees it after the boot loader called bank 1:
the file in the flash window at 0x18400000, PC at its `Reset_Handler` (0x1840002C), SPIBSC1 0x3FEFB018 non-zero (so
`boot_select_bank` is skipped, boot-rtos.md section 1). It runs the image's own `reset_in_ram` (copies, MMU on),
`__main`, `__scatterload`, `__rt_entry`, `main`, the NORTi kernel, the tasks and the GUI. Machine model: on-chip RAM
and its page-interleaved mirror 0x60000000.. as one host buffer mapped twice (Table 53.1); peripherals read back the
last value written, XORed with seeded random bits half of the time (polling loops end); the GIC CPU interface's
ICCIAR returns the interrupt being injected; every 50,000 instructions, when the CPU has IRQs unmasked, an IRQ
exception is entered as the CPU would (IRQ mode, SPSR, LR + 4, VBAR + 0x18) with an ID drawn from the image's GIC
handler table 0x208DC1E0 (the OSTM0 tick 0x86 half of the time, then the 25 other registered sources); SVCs enter
the image's `SVC_Handler`; PMCCNTR advances by 256 at each read (Unicorn does not count cycles, and
`cpu_delay_cycles4` & co. spin on it: the first runs stalled there). The watched range (whole pages
0x2091D000..0x2097FFFF and the same pages of the mirror) is mapped with `mmio_map`, so every access is seen with its
PC without a Unicorn memory hook.

Results **[fact: the runs]**: seeds 1, 2, 3 (1.5·10⁹ instructions each; seeds 1 and 2 again with the cycle-counter
model): 33 kernel tasks created, `task_root` and `gui_main_loop` reached, 684..709 of the 2,214 Ghidra functions
executed, about 28,000 interrupts; **no access at all at or above 0x2091D570** (464 below it, the C library's
libspace and the end of `.bss2`). Control run (watch extended to 0x209A0000): the pool writes of `itron_acre_tsk`,
`knl_freelist_alloc`, `itron_act_tsk`, the ISR stubs and `bootinfo_load` are recorded with their PCs, and the first
pool block is `task_root`'s stack 0x20980028..0x20982027 (filled with its ID); in the runs 5,672 of its 8,192 bytes
stayed unused, so its overflow, the one thing that would grow down into RAM2, did not come near. The C library heap
base is 0x20A00000 (`__user_initial_stackheap` 0x201172EC: 0x20980000 + 0x80000) **[fact]**, outside the range.
`reset_in_ram` makes 0x20800000..0x209FFFFF cacheable (`mmu_set_cacheable` at 0x201000FC) and the flat L1 table
leaves it executable (XN = 0) **[fact]**, which settles round 5's MMU question. **RAM2 = 0x20920000..0x2097FFFF
stays as planned.** Open: paths the emulation does not reach (about 1,500 functions, e.g. the update and USB code
that need real SD-card and USB data) could still write there through a computed pointer; would be settled by
running them with recorded peripheral data, or on a radio with a RAM fill pattern checked after use.

### DISPLAY: the hybrid link, round 6

`tools/display_link.py` places each linked function **in place** when its GCC code fits into the original extent,
the original is A32, and nothing outside the extent refers into it past the entry (a scan of the image's branches,
literal words, PC-relative loads and ADRs), otherwise into the **gap**, and what does not fit there into **RAM2**
(`.recreated2` in `display.ld`; its bytes at file offset 0x340000). With RAM2 in use the hybrid links
`startup/vectors.S` assembled with `-DRAM2_LOAD`: its `reset_in_ram` copies RAM2 from flash in the nine words the
original branches over (0x20100104..0x20100127, its literals in the padding at 0x201000CC), while the MMU and caches
are still off, as the image's own copies run. `--gap-limit N` forces RAM2 (the gap still has room: 43,452 of
82,928 bytes with everything linked).

Rules found by booting the hybrid in emulation (`display_boot_emu.py --compare`, which boots both images and checks
for no fault, as many tasks, the GUI loop, RAM2 loaded intact and nothing in the watched range above RAM2):

- **Shared literal pools.** The first in-place link overwrote a literal at 0x20140118 that the unlisted function at
  0x2013FE68 loads, and the hybrid faulted (`sdhi0_clock_on` + 0x70 read an instruction word as an address). The
  reference scan now includes PC-relative loads and ADRs **[fact]**.
- **Registers beyond the C return.** `_ll_udiv10` returns the remainder in r2 as well, and `_fp_digits` adds '0' to
  r2 after the call (0x20155C8A) **[fact]**; the C recreation returned only r0:r1, passed the check, and the hybrid
  hung in a `snprintf` of `vk_key_name`. It is now an assembly transcription (`lib/aeabi_ldiv.S`, identical).
  `equiv_display_emu.py abicheck` (new) scans every direct call of a recreated function in the image for a read of
  r1, r2, r3 or ip after the call that the GCC code may change and does not return: one site,
  `sdhi_error_reset` keeps r2, r3, ip across `sdhi_soft_reset` (0x201407C4..0x201407D8; armcc knows the callee in the
  same file) **[fact]**. `display_link.py` holds such functions back (links the original) until their callers are
  recreated too.
- **The reset path.** `Reset_Handler` calls its callees from the flash bank before any copy, and `reset_in_ram`
  calls `spibsc0_init` and `boot_select_bank` after copying only 0x20100000..0x20100BBF **[fact: vectors.S]**. From
  the image's static call graph, `display_link.py` keeps the first group out of RAM2 (a PC-relative branch from the
  flash copy finds the gap in flash, not RAM2) and the second in place within the first copy or original:
  `gpio_cfg_reset` is held back.

**Function addresses as data.** Where the recreated code takes the address of a linked recreated function
(`R_ARM_ABS32`, `MOVW`/`MOVT` in an allocated section; not a call), `display_link.py` retargets the relocation in the
object copy to an absolute symbol at the function's original entry (Thumb bit included), which the patch forwards to
the recreation: 14 such references (the TCON function table of `vdc5_reg.c`, the line-interrupt callback of
`gui_vdc5.c`). Round 5's alias `vdc5_vline_cb_entry` is gone.

Result (`make link`): 487 recreated functions linked, 103 in place (10,020 bytes), 384 in the gap 0x2042BC10..0x204365CB (43,452 of 82,928 bytes), RAM2 empty; 384 entries patched (9,115 bytes of the image changed), none too short; 55 byte-identical left as they are; 2 held back (`gpio_cfg_reset`: reset path, `sdhi_soft_reset`: abicheck). With `--gap-limit 15000`: 134 in the gap, 250 (27,232 bytes) in RAM2. **linkcheck: 487 of 487 agree, for the default hybrid and for the one with RAM2 forced** (100 trials per
entry, in-place entries included). linkcheck leaves RAM2 out of the memory comparison and requires both runs to
change it alike (an argument pointer can point there). The first RAM2 run had three "differs" in the shared-parameter
getters (`vdc5_shrd_get_ln_off_dir` & co.), not a code difference: with a pointer as table index the read lands
anywhere, here in RAM2, which holds code in the hybrid and zeros in the image; the getters now get an index 0..5
(their verdicts in `status.tsv` stay equivalent with that preset). Emulated boot (seed 1, 1.5·10⁹ instructions each) **[fact: the runs]**: the
default hybrid **agrees with the original** (33 tasks, the GUI loop, 154 recreated functions executed, nothing in
0x2091D000..0x2097FFFF), and so does the hybrid with RAM2 forced (`--gap-limit 15000`: 250 functions, 27,232
bytes in RAM2, loaded intact by the recreated `reset_in_ram`; 157 recreated functions executed). Earlier versions
of the hybrid failed this check twice, for the shared literal pool and for `_ll_udiv10` (above).

### DISPLAY: compiler (round 6)

The DISPLAY Makefile is pinned to **xPack GNU Arm Embedded GCC 10.2.1-1.1** (`XPACK=` its directory or `CROSS=` its
prefix; another `-dumpversion` stops the build unless `ANY_GCC=1`). Reasons (also in the README and the Makefile):
the check verifies the code GCC emits and, where a trial reads past a table, the verdict depends on `.rodata`
layout (round 5's follow-up: GCC 13.2.1 and 10.2.1 disagreed); xPack publishes this exact version for Linux, macOS
and Windows, while the default `arm-none-eabi-gcc` is whatever the system ships; it is the M33 image's own compiler
and DISPLAY rounds 3 to 5 used it. `status.tsv` of this round is from it.

### DISPLAY: code (round 6)

| Where | Functions | Notes |
|---|---:|---|
| `drivers/vdc5_reg.c` | 28 | image enhancement (sharpness, LTI), alpha rectangle and und_sel, colour conversion and `rgb4/5/6_to_8`, chroma key, CLUT, gamma; write data control (Ghidra `vdc5_config`) and its change with scaling down; the scaler background colour; cascade, VIN layer, scaling up, start pixel, enlargement check; `vdc5_ratio_one` (no caller) |
| `app/gui_vdc5.c` | 5 | `fb_get_layer_addr`, `cursor_rect_calc`, `vdc5_layers_setup`, `vdc5_layers_stop`, `vdc5_channel_shutdown` |
| `drivers/rspi.c` (new) | 45 | the per-channel RSPI helpers: flags, receive and transmit ISRs, transmit wait, TEND wait, delay, the GIC stubs of the generic ISRs |
| `lib/aeabi_ldiv.S` | 1 | `_ll_udiv10`, from C to assembly (above) |

Findings **[fact]**: the write side of the scaler stores the ratio 0x1000 (1.0) for vertical scaling whether the
output is smaller or not (0x2011A2C4..0x2011A2D8); this driver version's colour conversion drops the alpha of
ARGB1555 / ARGB4444; `vdc5_layers_setup` starts graphics 0..2 with display selects 2, 3, 3, then waits 0x3458 loop
passes with `dmb oshst` and one frame. Harness: presets for the helpers that take a register-address table entry
(`VDC5_TABLE_ARGS`), CLUT blocks with a small colour count, the layer formats drawn into the shared parameters,
the image-enhancement arguments; `RET_SIZE` for `_ll_udiv10` (r0..r3) and `__rt_udiv10` (r0:r1). A mutation
(threshold shift 8 → 9 in `vdc5_set_gamma_threshold`) is reported as differing.

Not done this round: the register parts of read data control and of its change (0x2011AF34, 0x2011B498, 1,920
bytes: Ghidra's C of them is broken, they need the disassembly), the RSPI driver core (`rspi_hw_config`, open,
read and write, the read bursts), DMAC, the large SDHI functions, the file system, the MAIN link and the update
code. The time went into the gap and the boot emulation, which found three defects of the hybrid image that no
per-function check could see.

### DISPLAY: results (status.tsv, round 6)

| Verdict | Ghidra functions | Bytes (of 396,256) |
|---|---:|---:|
| identical | 54 | 3,974 |
| equivalent | 489 | 45,222 |
| differs | 0 | 0 |
| not yet | 1,673 | 347,060 |

**Re-implemented: 12.42 %** (49,196 bytes; round 5: 10.31 %), with the pinned xPack GCC 10.2.1, 200 trials per
function. The 13 new identical functions: `_ll_udiv10`, `rgb4_to_8`, `vdc5_ratio_one` and the ten RSPI GIC stubs.

### DISPLAY: Ghidra (round 6)

`tools/ghidra/names_display.tsv` gains 18 names with evidence (also in `names_display.T24r6.tsv`): the VDC5 helpers
above, and `vdc5_config` → `vdc5_reg_write_data_control`. No new entries. Proved on a copy
(`/home/user/ghidra_tasks/t24r6/disp`, OWNER root): ApplyNames **1,917 applied, 0 failed**; ExportFuncModes: the
new names, no change of any entry, size or mode [fact: apply.log, modes.tsv there]. Commands for the canonical project
(repository root):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/display/quality.tsv /tmp/quality_display_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -scriptPath tools/ghidra \
  -postScript ApplyNames.java tools/ghidra/names_display.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/display" 50 \
  -postScript ExportFuncModes.java "$PWD/src/display/modes.tsv"
python3 -I tools/decomp_quality.py compare /tmp/quality_display_before.tsv decomp/display/quality.tsv display
make -C src/display && python3 -I tools/equiv_display_emu.py status
python3 -I tools/readability_stats.py readme
```

After the re-export the alias rows of the round-6 names in `src/display/aliases.tsv` are redundant.

## MAIN, round 2 (2026-11-01)

### Plan (MAIN round 2)

1. Harness soundness: semantics cases for the RX forms only the GCC code uses (3-operand `SUB`/`MUL`/`OR`,
   `SCGTU.L`, `MOV.B Rs,[Rd+]`, `ROTL`, `BRA.A`, and `JMP Rs`), checked against the RXv2 manual like T22a; a SLEIGH
   patch for any bug, wired into `bootstrap.sh --only rx`.
2. More MAIN code, biggest self-contained first: the EEPROM settings store, the DSP and SDR link frame layers, the
   CAT glue and handlers, the DISPLAY link, the TX/RX sequencer, tuner and keyer.
3. Ghidra entries and names of the unlisted intrinsic setters and 0xFFF927E0.
4. `status.tsv` and the README progress block.

### MAIN: semantics of the GCC-only forms (`tools/rx_semcheck_forms.sh`)

`rx_semcheck.py forms` writes 12 random instances of each of 40 forms (`GCC_FORMS`: the forms the recreated
objects use and MAIN does not, from `equiv_main_emu.py`'s per-function list, libgcc's, the two T22a left
unchecked, `JMP Rs` and `BNOT Rs,Rd`, and the same-register cases the manual singles out). The script assembles them
(`rx-elf-as`/`ld` at 0xFFF00000), imports the binary raw into a scratch Ghidra project, decodes each instruction
with `ExportListing.java decode` and runs T22a's model check (`gen`, `RxEmuStep.java`, `check`; 8 start states
per instruction). The model gained ROTL/ROTR (manual p. 169/170), ABS (p. 58), NEG/NOT Rs,Rd (p. 144/146), REVL
(p. 163), XOR (p. 206), EMUL/EMULU (p. 82/85), JMP (p. 112) and the SCC/SCNC/SCZ/SCNZ aliases (p. 182). The
operand order of the 3-operand forms is the manual's: `SUB Rs, Rs2, Rd` is `FF 0 rd / rs rs2` and Rd = Rs2 - Rs
(p. 296, p. 195), as Ghidra and binutils print and decode it.

| Module | Cases | ok | fail |
|---|---:|---:|---:|
| T21i (`73d417d2…8290`, the module of round 1) | 3,848 | 3,176 | 672 |
| with `rx62t-gccforms-fix.patch` (`11fbb030…0e14`) | 3,848 | **3,848** | **0** |

The 672 failures fall in three classes, all SLEIGH bugs **[fact]**: `JMP Rs` is `PC = Rs` without a branch (96
cases; manual p. 112: PC = src; round 1 had worked around it in EquivMainEmu.java); `BNOT Rs,Rd` XORs `Rs & 31`
instead of `1 << (Rs & 31)` (96; p. 68); `MOV.size Rs,[Rd+]` and `[-Rd]` with Rs = Rd store the updated register,
because the `rd_post` sub-constructor runs before the source is read (480 = 5 forms x 96; p. 121 note 3: the value
before the update is stored). Everything else, among it the round-1 list (3-operand `SUB`/`MUL`/`OR`, `SCGTU.L`,
`MOV.B Rs,[Rd+]` with different registers, `ROTL`, `BRA.A`), agrees with the manual without a change.
`tools/ghidra/rx62t-gccforms-fix.patch` fixes the three (`goto [Rs]`; `1 << (Rs & 31)`; source read into a local,
then `build rd_post`) and is the eighth stage of `bootstrap.sh --only rx` (`RX_SINC_MVTAC` → `RX_SINC_FIXED`
`11fbb030…0e14`; checked on a private Ghidra copy: patch, sleigh compile and the idempotent second run). MAIN has
none of the three forms **[fact: rx-elf-objdump of 0xFFF8FBDB..0xFFFEE2B7: no `jmp`, no `bnot Rs,Rd`, no
post-increment or pre-decrement store]**, so MAIN's decompile does not change and `decomp/` is not re-exported. The
patch is **not installed into the shared Ghidra** of this container (other sessions' bootstraps check the old hash);
`tools/bootstrap.sh --only rx` installs it. EquivMainEmu.java keeps its own JMP execution, so results do not depend
on whether the patch is installed; the GCC code uses neither `BNOT Rs,Rd` nor a same-register store
[fact: forms of the recreated objects].

### MAIN: harness changes (round 2)

- **EEPROM transfers as stubs.** `eeprom_read` / `eeprom_write` are stubbed for every other function
  (`STUBS`): the settings store moves up to 0x5837 bytes per call through the bit-banged SPI, millions of
  emulated instructions; the calls (address, buffer, length) are compared instead. The two are still checked on
  their own (a function is never stubbed in its own check).
- **Presets** from the callers: `buffer_args` keeps the buffer of `sum8`, `cat_checksum_ok`, `dsp_sum8`,
  `sdr_sum8`, `dsp_reply_sum_ok`, `sdr_check_hex_sum`, `displink_put_sum` non-NULL (a NULL buffer with n = 0x15AB
  summed the stack, where the original keeps its locals: a difference on a call that never happens), and
  `copy_if_changed_args` gives `displink_copy_if_changed` two separate buffers and the callers' lengths (every
  caller copies a staging buffer to 0x1456, n <= 0x23F). *Open: why the original's SMOVF and the recreated byte
  loop disagree when the two buffers overlap (a random trial with n > 0x800); would be settled by a trace of such a
  trial.*
- A stack local whose address leaves the function is observable: `displink_send_ack`/`_nak` pass a pointer to a
  one-byte buffer that `R_SCI1_Serial_Send` keeps in `gp_sci1_tx_address`, so the recreated code keeps the byte
  where the image does (last byte of a 4-byte frame).

### MAIN: recreated (src/main, round 2)

All in `src/main/app/` (src/main/README.md lists the functions):

- `settings.c`: the settings store. The whole EEPROM is mirrored at RAM 0x464F, so each save is
  `eeprom_write(ee, &ee_mirror[ee], n)` [fact: every call loads 0x464F + the EEPROM address]; the saves bracketed by
  `eeprom_hdr_update(0/1)` (state byte 0 while saving), the power-fail check, the boot load and the defaults.
- `reglink.h`, `dsp_link.c`, `sdr_link.c`: the DSP (SCI4) and SDR (SCI5) links are the same code over different
  buffers, flags and timers [fact: `dsp_send_frame`/`sdr_send_frame`, `dsp_check_reply`/`sdr_poll_reply`,
  `dsp_sum8`/`sdr_sum8` match instruction for instruction apart from the addresses], written once over a constant
  link description and folded per link; the frame layer and the register setters whose value is a constant, a
  route-table entry or one menu setting.
- `cat_link.c`: the CAT receive ring, the three ports and their busy flags, the sums and the handlers that do not
  touch the radio state (`ID`, `QI`, `QR`, and `QS`/`EN`/`FS`, which answer `?;` in this firmware [fact]).
- `display_link.c`: the SCI1 glue, ACK/NAK, the send path (sum byte, outstanding flag, resend) and the frame senders
  that build into a staging buffer and send only when the frame changed.
- `trx_lines.c`, `tuner.c`, `keyer.c`: the sequencer's port lines (SEND_A/B gated by ETUN_TXINH_REQ and TX), the
  tuner task dispatch and relay bytes, the keyer resets and ring index.

New RAM and ROM names are in `src/main/data_symbols.tsv`, each with the instruction that shows the address.

### MAIN: Ghidra (round 2)

`tools/ghidra/entries_main.T24m2.tsv` (FixFuncEntries `nolate`; in bootstrap's `build_main` and its stamp) lists the
intrinsic helpers between the getters, `chg_pmusr` 0xFFF91228, `set_bpsw` 0xFFF91248, `set_bpc` 0xFFF9125F,
`set_extb` 0xFFF91276, `set_acc_hi` 0xFFF9128D, `set_acc_lo` 0xFFF91291, `byte_bset`/`byte_bclr`/`byte_bnot`
0xFFF912BB/BF/C3 (the current project already has them as 4-byte `FUN_` functions; the rows make them independent
of auto-analysis), and **0xFFF927E0, which was no function**: `iwdt_error_nmi_cb`, `BSR.A sw_reset; RTS`,
registered by `R_Systeminit` as `R_BSP_InterruptWrite(7, 0xFFF927E0)` at 0xFFF8F6DD and called by `NMI` 0xFFF9061B
when NMISR bit 3 (IWDTST, IWDT underflow/refresh error; RX651 hardware manual 15.2.14) is set **[fact]**. Names in
`names_main.tsv`, signatures in `signatures_main.tsv`. The names of the setters follow the getters' (inference from
the instruction each one wraps); `chg_pmusr` is CC-RX's name for the code at 0xFFF91228 **[inference: it tests and
sets PSW.PM and returns through RTE]**. Proved on a copy of `/home/user/ghidra_tasks/t24main/proj` [fact: the
script log]: FixFuncEntries 10 created, 0 late starts removed, 0 failed; ApplyNames 2,805 applied, 0 failed;
ApplySignatures 1,230 applied, 0 failed; the decompile of 0xFFF927E0 is `iwdt_error_nmi_cb() { sw_reset(); }`.
Commands for the canonical project (repository root; Ghidra closed):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/main/quality.tsv /tmp/quality_main_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
  -postScript FixFuncEntries.java tools/ghidra/entries_main.T24m2.tsv nolate \
  -postScript ApplyNames.java tools/ghidra/names_main.tsv \
  -postScript ApplySignatures.java tools/ghidra/signatures_main.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/main" 50 \
  -postScript CatDispatch.java "$PWD/decomp/main/cat_dispatch.tsv" 0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
python3 -I tools/decomp_quality.py compare /tmp/quality_main_before.tsv decomp/main/quality.tsv main
rm -rf /home/user/ghidra_tasks/t24main/proj/FT710_MAIN.rep    # refresh the harness copy
cp -r ghidra/FT710_MAIN.gpr ghidra/FT710_MAIN.rep /home/user/ghidra_tasks/t24main/proj/
python3 -I tools/equiv_main_emu.py status
python3 -I tools/readability_stats.py readme
```

After the re-export `iwdt_error_nmi_cb` is a function of `decomp/main/functions.tsv`, and the setters keep their
addresses under their new names.

### MAIN: results (status.tsv, round 2)

`equiv_main_emu.py status --trials 200 --jobs 3`, run on a Ghidra copy with `rx62t-gccforms-fix.patch` installed
(`GHIDRA_HEADLESS` pointing at it; about 30 minutes):

| Verdict | Ghidra functions | Bytes (of 387,054) |
|---|---:|---:|
| identical | 43 | 259 |
| equivalent | 213 | 16,323 |
| differs | 0 | 0 |
| not yet | 3,537 | 370,472 |

**Re-implemented: 4.28 %** (2.82 % after round 1). Round 2 added 123 functions (5,671 bytes counted): DSP link 24
(1,523), settings store 19 (1,258), SDR link 19 (1,121), DISPLAY link 26 (811), CAT glue and handlers 21 (560),
sequencer lines 6 (197), keyer 4 (132), tuner 4 (69). The 133 functions of round 1 still pass with the new compiler
flag and the stubs. Found on the way, all fixed before the run: two RAM addresses computed wrong at first
(`menu_affft_att` 0x9C39 and `menu_cw_pitch` 0x9C04: 21994 and 21941 are 0x55EA and 0x55B5), and the REVL bug above
(`eeprom_hdr_update` differed until the patch).

### MAIN: blockers and next steps (round 2)

- **CC-RX** is still not obtainable from the container ("MAIN, round 1").
- **The shared Ghidra here still has the T21i module**: the results above need the round-2 patch for the GCC code
  that uses `REVL Rd,Rd` (`eeprom_hdr_update`); `tools/bootstrap.sh --only rx` installs it. Installing it into the
  container's shared Ghidra changes `rx62t.sinc`, which the bootstrap of a branch without this patch then rejects,
  so it was left to the merge.
- **Ghidra:** the round-2 entries and names are not applied to the canonical project (commands above).
- Next, by size and self-containment: the rest of the DSP setters (`dsp_set_agc` 1,261 bytes, the EQ, contour,
  tone and DNR setters, about 9 KB) and the SDR updaters (`sdr_upd_r18_rx_freq`, `_r1d_notch`, `_r1e_passband`,
  about 4 KB), `dsp_shadow_store`/`sdr_shadow_update`, the DISPLAY frame builders and receive handlers, `cat_parse`
  and the CAT handlers that change the radio state, `trx_sequencer`, `keyer_task`, the tuner tasks.

## DISPLAY, round 7 (2026-11-01)

### Plan (round 7)

1. Code, biggest self-contained first: the register parts of read data control and its change (from the
   disassembly), the RSPI driver core and DMAC, the large SDHI functions, then the file system, the MAIN link, the
   update code and GUI building blocks as far as the round goes.
2. `abicheck` for calls through function pointers (round 6 left it open).
3. After linking: `linkcheck` and the emulated boot of the new hybrid; any new defect the boot finds is fixed.
4. `status.tsv`, readability stats; Ghidra names and entries with evidence, proved on a copy.

### DISPLAY: code (round 7)

| Where | Functions | Notes |
|---|---:|---|
| `drivers/vdc5_reg.c` | 3 | `vdc5_reg_read_data_control` 0x2011AF34, `vdc5_reg_change_read_process` 0x2011B498 and its tail-called VIN set-up 0x2011B374 (`vdc5_change_graphics_vin`, no Ghidra entry), from the disassembly |
| `drivers/rspi.c` | 26 | `rspi_hw_config`, the five opens and two interrupt-only opens, the five read bursts, `rspi_hw_config_master`, open/start/stop/base/SPE, the PIO read and write: bodies 0x2011F278 / 0x2011F4D4 behind the argument checks 0x2011F494 / 0x2011F718, FIFO and buffer reset, the generic ISRs, the TEND wait, the empty 0x2011DEA0 |
| `drivers/dmac.c` (new) | 30 | DMA channels 3, 4, 5, 9, 10 (the SPI links) and 8 (memory copier): set-ups with the CHCFG fields in the image's order, ISRs, enable/disable/stop, callback setters; `dmac9_enable` 0x20137DEC (no Ghidra entry) |
| `drivers/sdhi.c` | 12 | the command layer: response copy, CMD16, CMD12, `sdhi_error_reset`, sector read/write commands and ops, the PIO buffer read 0x20140998, `sdhi_open` and its DMA side 0x2013FE68 (`sdhi_dma_open`, no Ghidra entry), the buffer interrupt |
| `drivers/sd_card.c` (new) | 10 | CMD0, CMD2, CMD9, CMD10, CMD13 through the operation table; the SD and MMC CSD checks; READ_BL_LEN, C_SIZE, C_SIZE_MULT |
| `app/fat_format.c` (new) | 6 | the MBR CHS helpers (start/end head, sector and cylinder), the partition type, the format parameter block |
| `include/sd.h` (new) | | the SD driver's card context (CSD +0x201, CID +0x211, RCA +0x2AA, response +0x2B0, addressing +0x2C0, card type +0x2C6), handle and operation table |

Findings **[fact]**: `rspi_hw_config` rejects `ch > 5`, so channel 5 is accepted and indexes past the 5-entry
register table (0x2011D9AC: `cmp r0, #5; bhi`); `rspi_read_pio` passes every read burst a second argument
(0x2011F378: fewer bytes than the RX trigger), with which the burst polls SPBFDR instead of waiting for the receive
interrupt (Ghidra's C passed it only for channel 4); `rspi_write_pio` reads and drops SPDR after each access when
SPSR.SPRF is set (0x2011F63C..0x2011F67C, missing from Ghidra's C); the RX trigger table 0x20800434 is
{1, 2, 4, 8, 16, 24, 32, 5} bytes, the TX one {1, 2, 4, 8}; `rspi3_open` also enables GIC 0x117 (SPEI3), which has
no ISR; `dmac3_isr` is the only DMA ISR that sets the done flag, the others call the callbacks 0x20808AA4..B0, and
the slot 0x20808AA0 (set by 0x20137D78, no caller) is never called; `sdhi_read_sectors_cmd` and the write side leave
DMA mode (CC_EXT_MODE bit 1) on when the command fails three times (0x20140888); `sdhi_dma_open` reads each
priority register before `gic_def_inh` and writes it afterwards; `sdhi_error_reset` keeps SD_CLK_CTRL and SD_OPTION
in r3 and ip across `sdhi_soft_reset` (the round-6 hazard), which the C version keeps in callee-saved registers.

### DISPLAY: checks (round 7)

- **abicheck, calls through a register.** Each `blx rN` (and `mov lr, pc` + a write of pc) is scanned like a direct
  call. Its possible targets are the recreated functions whose entry the image holds as a word: literal pool, table
  or data (`address_taken`: 114). Result **[fact: the run]**: 339 indirect call sites, none reads r1, r2, r3 or ip
  after the call, so no new hazard. The direct hazard stays (`sdhi_error_reset` → `sdhi_soft_reset`).
  `display_link.py` now drops a hazard when its caller is linked too, because the original caller code no longer
  runs (iterated to a fixed point). With `sdhi_error_reset` recreated, `sdhi_soft_reset` is linked.
- **Harness defects found by mutations** (each mutation was reported as differing after the fix):
  - The 64-byte random fill of a referenced data symbol ran into the next table the trials keep (`rspi_rx_done`
    0x20800418 covered the trigger tables 0x20800424/34). Nearly every `rspi_read_pio` trial failed its trigger
    check, and the mutation `n < trg` → `n <= trg` passed. Now the fill stops at the next kept table (`ref_span`).
  - A stub's output-pointer argument compared the stack bytes it pointed at before the call. Those bytes are
    uninitialised and differed between the armcc and GCC frames in `sdhi_flag_wait`. They are now left out.
  - Presets may bias chosen MMIO registers (`args['mmio']`). With random SDHI status, CMD16 almost never passed and
    the sector transfers reached 12 % of their blocks; with SD_INFO1/2 and RSP00/01 biased they reach 94 %.
- **A stale alias** (introduced by the round-6 re-export): `aliases.tsv` still mapped
  `vdc5_reg_write_data_control` to `vdc5_config`, the name the re-export replaced. So `status.tsv` lost it and
  `r_vdc5_write_data_control` (1,064 bytes). The row is removed, and the resolver now falls back to the source name
  when an alias target no longer exists. The other alias rows that point to addresses Ghidra has since named are
  redundant and harmless (98 rows).

### DISPLAY: hybrid image (round 7)

`make link` **[fact: the run]**: 585 recreated functions linked, 117 of them in place (11,332 bytes) and 468 in the
gap 0x2042BC10..0x2043AF4C (62,268 of 82,928 bytes). RAM2 stays empty. 468 original entries are patched (10,529 bytes
of the image changed), 48 byte-identical functions are left as they are, and one function is held back
(`gpio_cfg_reset`, reset path). `sdhi_soft_reset` is linked now (above).

Emulated boot (`display_boot_emu.py --compare`, seed 1, 1.5·10⁹ instructions each) **[fact: the run]**: the hybrid
**agrees with the original**:
- no fault;
- 33 kernel tasks; `task_root` and `gui_main_loop` reached;
- 742 image functions reached (the original: 709), 176 recreated functions executed;
- RAM2 intact, nothing in the watched range;
- the `task_root` stack's untouched bottom: 5,648 bytes (the original: 5,672).

The hybrid with RAM2 forced (`--gap-limit 15000`) also agrees with the original **[fact: the run]**: 134 functions in
the gap, 334 in RAM2 (45,440 bytes, loaded intact by the recreated `reset_in_ram`), 179 recreated functions executed.
The boot found no new defect. The round's defects were all in the tooling (the stale alias, the fill overrun and the
output-pointer compare above). **linkcheck: 585 of 585 agree** for the default hybrid (100 trials per entry,
in-place entries included) **[fact: the run]**.

### DISPLAY: results (status.tsv, round 7)

| Verdict | Ghidra functions | Bytes (of 396,256) |
|---|---:|---:|
| identical | 47 | 3,930 |
| equivalent | 582 | 60,646 |
| differs | 0 | 0 |
| not yet | 1,587 | 331,680 |

**Re-implemented: 16.30 %** (64,576 bytes; round 6: 12.42 %), with the pinned xPack GCC 10.2.1 and 200 trials per
function. The count of identical functions falls from 54 to 47 with no loss of bytes:
- The ten RSPI GIC stubs (`mov r0, #n; b rspi_tx_isr`) now branch to `rspi_tx_isr` / `rspi_rx_isr` in the same
  object, so they verify as equivalent.
- The new `rspi_spe_set`, `rspi_spe_clear` and the empty 0x2011DEA0 are identical.

The functions Ghidra merges count with their Ghidra size. `rspi_write` counts 604 bytes, including the body
0x2011F4D4. `sdhi_open` counts 424, including 0x2013FE68, and `vdc5_reg_change_read_process` 868, including
0x2011B374. Their own rows (alias addresses) count no bytes until the re-export lists them.

Not done this round: the large SD functions (`sd_select_bus_speed`, `sd_card_identify`, `sd_init_v1_or_mmc`,
`sd_init_v2`, the ACMDs), the FAT file system, the MAIN link (`docs/code/display/mainlink.md`), the update code and
the GUI building blocks. Each status run takes about 30 minutes on 3 cores, and so does linkcheck (the inconclusive
read-burst trials run up to 8·10⁶ instructions). That limits how many check-and-link cycles fit in a round.

### DISPLAY: Ghidra (round 7)

`tools/ghidra/entries_display.T24r7.tsv` has 4 new entries: 0x2011B374, 0x2011F4D4, 0x20137DEC and 0x2013FE68
(also appended to `entries_display.tsv`). `names_display.T24r7.tsv` has 8 names with evidence (also appended to
`names_display.tsv`): the four entries, `rspi_read` → `rspi_read_pio` at 0x2011F278, `FUN_2011f494` → `rspi_read`,
`FUN_20137d78` → `dmac3_set_callback` **[inference]** and `FUN_20140998` → `sdhi_read_buf_pio`. Proved on a copy
(`/home/user/ghidra_tasks/t24r7/disp`, OWNER root) **[fact: apply.log, modes.tsv there]**:
- FixFuncEntries: 4 created, 0 failed, 4 branches marked as tail calls.
- ApplyNames: 1,925 applied, 0 failed.
- ExportFuncModes, 2,260 functions: the four new functions (292, 540, 20 and 372 bytes, A32). The functions that had
  them folded in shrink: `vdc5_reg_change_read_process` 868 → 576, `rspi_write` 604 → 64, `sdhi_open` 424 → 52, and
  `pclink_tx_dma_start` 60 → 40 (its tail call into 0x20137DEC). No other entry, size or mode changes.

Commands for the canonical project (repository root):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/display/quality.tsv /tmp/quality_display_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -scriptPath tools/ghidra \
  -postScript FixFuncEntries.java tools/ghidra/entries_display.T24r7.tsv \
  -postScript ApplyNames.java tools/ghidra/names_display.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/display" 50 \
  -postScript ExportFuncModes.java "$PWD/src/display/modes.tsv"
python3 -I tools/decomp_quality.py compare /tmp/quality_display_before.tsv decomp/display/quality.tsv display
make -C src/display && python3 -I tools/equiv_display_emu.py status
python3 -I tools/readability_stats.py readme
```

After the re-export the four new functions count in their own rows. The alias rows of round 7 give addresses, not
names, so they stay right when the Ghidra name `rspi_read` moves from 0x2011F278 to 0x2011F494. They only become
redundant.

## MAIN, round 3 (2026-11-01)

### Plan (MAIN round 3)

1. The typed state blocks of `tools/ghidra/structs_main.h` as a C header for the recreated source, so the code
   uses `g_ui.trx_state`, `g_opstate.vfo_a.blk[1].flags2` instead of addresses.
2. Code, biggest first from round 2's list: `cat_parse` and the dispatcher structured by the dispatch table, then
   the CAT handlers that read or change the radio state; `trx_sequencer`; the DSP setters (`dsp_set_agc`, EQ,
   tone, DNR, about 9 KB) and the SDR updaters (about 4 KB); the shadow stores. Keyer, tuner tasks and the DISPLAY
   frame builders after that.
3. The SMOVF overlap question of round 2 (`displink_copy_if_changed`), with single runs.
4. Ghidra names for the new tables and flags; `status.tsv` and the README progress block.

### MAIN: the state header (`tools/main_structs.py`)

`structs_main.h` places every field at an explicit offset and leaves the bytes between fields undefined, so it is
not C. `tools/main_structs.py` (build time, `src/main/Makefile`) writes `out/include/ft710_state.h`: one packed
struct per structure with filler arrays over the undefined bytes, a `_Static_assert` per field offset and per size
(876 asserts), enum fields as integers of the enum's `@size` with `enums_main.h` included for the values, and an
`extern` per typed global. RX has unaligned loads and stores, and GCC for RX keeps the plain access widths on a
packed struct [fact: a test compile, `movu.w [r4]` / `add [r14].l` for fields at odd offsets]. `equiv_main_emu.py`
reads the globals' `@0x` addresses through the same module and defines them when it links, as it does for
`src/main/data_symbols.tsv` (which wins on a clash). Where six menu groups repeat the same item order, a view
struct is asserted against the field offsets (`struct af_menu` in `app/dsp_link.c`: items 01..10 of EX0101, 0102,
0103, 0104, 0105 and 0201).

### MAIN: harness changes (round 3)

- **Stub buffers by content.** `EquivMainEmu.java` stubs can record the bytes behind a pointer argument
  (`[name, nargs, ptr_arg, len_arg]`); `eeprom_write`'s buffer is compared by content, and a buffer address in the
  stack (below 0x1004) is compared as `stack`. Found with `cat_ext_SP`: `cat_SP_eeprom_byte` passes a stack byte to
  `eeprom_read` / `eeprom_write`, whose address moves with the caller's frame (0xEE3 under the original's
  12-byte frame, 0xED7 under GCC's) [fact: the stub call of trial 22]. The round-1/2 functions that call
  `eeprom_write` stay equivalent with the content compared (settings.o, 19 functions, rerun).
- **Presets** (`PRESETS`): `cat_parse` (a ring slot at the tail with a mnemonic from either table, upper or lower
  case, port 1..3, or the E9 slot with an empty ring), `cat_dispatch` / `cat_dispatch_ext` (every index with the
  lengths its case tests and their neighbours, from `decomp/main/cat_dispatch.tsv`), `cat_ext_SP` (the
  sub-command letters it compares and a good sum half of the time), a generic CAT handler preset (command text
  with mostly digit parameters, read or set), `trx_sequencer` (state 0..8 and the flags it tests), the two shadow
  stores (the register numbers they compare), `dsp_set_rf_gain` and `cat_GP` (the menu bytes they switch on),
  `eeprom_read_raw` / `_write_raw` (a caller's buffer, not the stack).

### MAIN: the SMOVF question (round 2) settled

Single runs of `displink_copy_if_changed` (one Ghidra engine, a pattern at 0x30000) **[fact]**:

| src, dst, n | original (SMOVF) | recreated (byte loop) |
|---|---|---|
| 0x30000, 0x30010, n = 0x08 / 0x10 / 0x20 (overlap, dst > src) | returns 1 | same RAM, returns 1 |
| 0x30000, 0x30800, n = 0x900 / 0x1000 / 0xF800 | returns 1 | same RAM, returns 1 |
| 0x30000, 0x30800, n = 0xFFFF | fault: store at 0x40000 | same fault, same RAM |
| 0x30000, 0, n = 0xEE0 | returns 1 | returns 1 |
| 0x30000, 0, n = 0xF00 | **returns 152** | returns 1 |

So SMOVF and the forward byte loop agree on overlapping buffers; they differ only when the destination covers the
original's own stack frame: it keeps the result flag at `1[r0]` = 0xEF1 and copies it to R1 at 0xFFF9C6A3, and the
copy overwrote it with the pattern byte (0xEF1 x 7 + 1 mod 256 = 152). Every caller copies a staging buffer to the
frame buffer 0x1456, so the preset stays and the open point is closed.

### MAIN: recreated (src/main, round 3)

- `app/cat_parse.c`: `cat_parse`, `cat_dispatch` (one `case CAT_xx` per index of `enum cat_cmd`: the echo of the
  first bytes into the reply, the length test that tells the read from the set form, the handler; the ten
  table entries without a case (BY, ED, EK, EU, RC, RD, RS, RT, RU, XT) answer "?;"), `cat_dispatch_ext`,
  `cat_ext_SP`. The SCMPU lookup is a two-byte compare: no table entry holds a NUL [fact: ROM 0xFFF805EC..
  0xFFF806CF]. `include/cat_cmds.h` holds the handler prototypes; the indexes are `enum cat_cmd` /
  `enum cat_ext_cmd` of `enums_main.h`.
- `app/cat_handlers.c`: 41 handlers (AG AI AO AV BA BC BI CS CT DN EX FN GP KP KR KS LK MA MB MS MX NB NL NR PA PL PR
  PS RA RG RL SC SD SM ST TX UP VD VG VX ZI) over shared helpers: `put_dec` / `get_dec` (the image's digit loops: each
  digit is v / place of what is left, through `nib2hex`, so an out-of-range value prints as the image prints it;
  digits summed in 8 bits), the key filter, the setting pop-up (`popup_open_timed(popup_duration_get(code))`
  unless EX030126 is set: the call passes the duration in R1 [fact: 0xFFFAB11B..0xFFFAB122; the decompile drops
  the argument]), the mode-block selectors.
- `app/trx_lines.c`: `trx_sequencer` (tx-protection.md "RX<->TX sequencer"), with named states.
- `app/dsp_link.c`: 39 setters (TX gain, VOX gain, anti-VOX, parametric EQ freq/level/width, processor, TX BPF,
  regs 0x31/0x32/0x3B, AMC, CTCSS enc/dec, FM flag, the seven DNR registers over one table at 0xFFF87F1A, DNF,
  CONTOUR freq/level/width, APF, AM notch, oscilloscope, RF gain, AESS, HCUT, LCUT, AF tone freq/gain/Q, AGC,
  IF-AGC) and `dsp_shadow_store` as a register -> slot table.
- `app/sdr_link.c`: `sdr_upd_r18_rx_freq`, `sdr_upd_r1d_notch`, `sdr_upd_r1e_passband` (one passband-centre
  helper; the notch adds DATA SHIFT x 10 to the PSK tone where the passband adds the IF SHIFT [fact: 0xFFFA20F7
  vs 0xFFFA2478]) and `sdr_shadow_update`.

Findings **[fact]** on the way:

- `cat_PS` reads "1" always; a radio that is off answers nothing but "PS1;" (`cat_parse` returns before the
  dispatch unless the index is PS and P1 is '1', 0xFFFA3539..0xFFFA356C).
- `cat_RA` sets `g_ui.freq_refresh_req` also after a refused value (0xFFFAD718).
- `cat_SP` (SPN): `W`/`w` and `S`/`s` both call `cat_SP_table` with write = 1; SPW/SPR (EEPROM byte) take the
  upper-case letter only (0xFFFA3848); an unknown third letter gets no reply and no error (0xFFFA399B..0xFFFA39A1).
- The AGC speed (mode block flags2 bits 4..5) 0 reads as SLOW in SSB and AM, as MID in RTTY and DATA/PSK and as
  FAST in CW and FM (`dsp_set_agc` 0xFFF9F681); `dsp_set_agc` writes only reg 0x62 when that changed and reg 0x66
  on the next call.
- The DSP shadow slots of the AF tone triples are by kind, not by register: 0x48/0x4B/0x4E -> slots 50..52,
  0x49/0x4C/0x4F -> 53..55, 0x4A/0x4D/0x50 -> 56..58 (`dsp_shadow_store` 0xFFFA037A).
- RTTY: the passband constants are 1275 or 2125 Hz (MARK FREQUENCY) plus the receive offset of the same SHIFT
  choice (85, 105, 215, 425 Hz) [inference: the differences of the constants in 0xFFFA2478 and 0xFFFA1C69].
- Not recreated, with the reason: `cat_OS` uses an uninitialised record pointer when P1 is not 0 or 1 (the stack
  decides where it writes; a recreation cannot match it), `cat_SQ` converts with the FPU's ROUND, which GCC's
  float-to-int conversion does not emit (*Open: a `lrintf` that GCC for RX inlines as ROUND; would be settled by
  a test compile*).

### MAIN: Ghidra (round 3)

`tools/ghidra/names_main.tsv` gains five labels with their evidence: `@dnr_tables` 0xFFF87F1A, `@rf_gain_curve`
0xFFF805AC, `@pc_keying_active` 0x12050, `@pc_key_last` 0x12051, `@spk_route` 0x20FCC. Proved on a copy of `/home/user/ghidra_tasks/t24main/proj` [fact: the script log]: ApplyNames 2,810 applied, 0 failed (2,805 + 5). No entries, signatures or structs change, so FixFuncEntries and ApplySignatures are not needed this round; `structs_main.h` is read, not changed.
Commands for the canonical project (repository root; Ghidra closed):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/main/quality.tsv /tmp/quality_main_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
  -postScript ApplyNames.java tools/ghidra/names_main.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/main" 50 \
  -postScript CatDispatch.java "$PWD/decomp/main/cat_dispatch.tsv" 0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
python3 -I tools/decomp_quality.py compare /tmp/quality_main_before.tsv decomp/main/quality.tsv main
rm -rf /home/user/ghidra_tasks/t24main/proj/FT710_MAIN.rep    # refresh the harness copy
cp -r ghidra/FT710_MAIN.gpr ghidra/FT710_MAIN.rep /home/user/ghidra_tasks/t24main/proj/
python3 -I tools/equiv_main_emu.py status
python3 -I tools/readability_stats.py readme
```

### MAIN: results (status.tsv, round 3)

`equiv_main_emu.py status --trials 200 --jobs 3` (about 50 minutes):

| Verdict | Ghidra functions | Bytes (of 387,059) |
|---|---:|---:|
| identical | 43 | 259 |
| equivalent | 303 | 47,446 |
| differs | 0 | 0 |
| not yet | 3,448 | 339,354 |

**Re-implemented: 12.32 %** (4.28 % after round 2). Round 3 added 90 functions (31,123 bytes counted): DSP setters
and `dsp_shadow_store` 40 (10,647, now 64 functions / 12,170 bytes in `dsp_link.o`), CAT handlers 41 (9,478), the
CAT parser and dispatch 4 (6,581), SDR updaters and `sdr_shadow_update` 4 (3,224), `trx_sequencer` (1,193). The
256 functions of rounds 1 and 2 still pass with the new stub comparison. A first status run of this round found
`sum8` and `displink_put_sum` "differs": a comment in the `PRESETS` literal had swallowed their `buffer_args`
entries (the round-2 NULL-buffer case); fixed before the run above.

### MAIN: blockers and next steps (round 3)

- **CC-RX** is still not obtainable from the container ("MAIN, round 1").
- Not done this round: `keyer_task` (2,120 bytes), the tuner tasks, the DISPLAY frame builders and receive
  handlers, the larger CAT handlers (SS 2,917 bytes, CO, MW, SF, MR, CF, DT, SH, IF/OI, BP, KM, GT, VM, EM, MC,
  FA/FB, ...), `cat_OS` and `cat_SQ` (above).
- Coverage: `cat_dispatch` reaches 55 % of its 598 blocks and `trx_sequencer` 60 % of 173 with 200 trials; more
  trials or presets that drive the handlers' own state would raise both.

## DISPLAY, round 8 (2026-11-01)

### Plan (round 8)

1. Harness speed: model the RSPI interrupt flags in `tools/equiv_display_emu.py` so the read-burst trials stop
   spinning to the budget; an honest result in less time, never a weaker comparison.
2. Code, biggest self-contained first: the large SD functions (identify, init paths, bus speed, ACMDs), then the
   FAT file system, the MAIN link, the update code and GUI building blocks as far as the round goes.
3. After linking: `linkcheck` and the emulated boot; any new defect the boot finds is fixed.
4. `status.tsv`, readability stats; Ghidra entries and names with evidence, proved on a copy.

### DISPLAY: harness speed (round 8)

Measured first **[fact: per-function times of a status run of round 7's tree, 2 worker processes, in the shared
container]**: 634 functions, 2,243 s wall. Most of the time was not in the read bursts: every function took about
7 s for 200 trials whatever its code (`bcd_to_bin`, one block: 7.1 s), 80 % of it memory handling: each run mapped
36 MB of RAM, wrote the image's regions into it and read 16 MB of compared ranges back through `mem_read` and a
`join` (cProfile). The functions with inconclusive trials (43) took 680 s, the RSPI read path (bursts, `rspi_read`,
`rspi_read_pio`, the transmit waits) 277 s.

Changes, each keeping the start state and what is compared:

- **Copy-on-write start memory.** Each worker writes the start contents of each RAM range once per image into a
  memfd; each run maps it `MAP_PRIVATE` and hands the pages to Unicorn (`mem_map_ptr`). Only written pages are
  copied; the snapshots are slices of the mapping, one bytes object per range (the compare reports the same first
  differing address). `bcd_to_bin`: 7.1 s → 3.9 s, the same detail line.
- **RSPI interrupts** (`Run.rspi_irq`): SPCR written with SPTIE raises the transmit interrupt at once (the transmit
  buffer is always empty) and the harness sets the transmit ISR's flag `rspi_tx_done[ch]`; an SPDR write while SPRIE
  was last written set raises the receive interrupt (`rspi_rx_done[ch]`). Only the flags are modelled; the ISRs' own
  register writes and `rspi_rx_count` are left out for both runs. *Open: the receive trigger level (the ISR fires
  after RXTRG bytes, not after the first frame); would be settled by counting the clocked bytes against the trigger
  table 0x20800434.*
- **SPDCR pinned per trial** in the RSPI presets: nothing these functions call writes it, and a fresh random SPLW at
  every read gave a burst another access size than `rspi_read_pio` had chosen, so `left -= 4` passed zero and ran to
  the budget. A burst gets an access size that divides its byte count, its callers' contract.
- **Length presets** for the four cache-range functions and the three CRCs: a random 32-bit length left half of their
  trials inconclusive (never compared); the lengths now run from 0 over line and word boundaries to 64 KB (cache) or
  within and just past a 1 KB buffer (CRC).

Effect per function **[fact: the runs]**: `rspi0_read_burst` 32.2 s with 122 of 200 trials inconclusive → 5.3 s
with 8; `rspi_read_pio` 23.7 s (81) → 4.0 s (2); `rspi0_tx_wait` 12.5 s (32) → 3.6 s (0); `icache_invalidate_range`
27.4 s (103) → 3.5 s (0); `crc16_xmodem` 18.0 s (57) → 4.0 s (0). Mutations still reported as differing:
`n < trg` → `n <= trg` in `rspi_read_pio`, the 16-bit dummy word 0xFFFF → 0xFFFE in a burst. The whole status run **[fact: per-function times, same
container, other sessions running]**: round 7's tree 2,243 s wall with 2 workers for 634 functions; this round's tree
1,120 s with 2 workers for 689 functions (before the length presets) and 908 s with 3 workers; over the 634 functions
both trees have, the time inside the checks fell from 4,484 s to 2,046 s (2 workers). linkcheck (634 entries, 100
trials, 2 workers, beside the emulated boot): 2,411 s; *open: why linkcheck gains less than status; would be
settled by per-entry times of a linkcheck run (it logs none yet).*

Also: an extent now ends at the next entry `aliases.tsv` gives too (0x2013DA6C's extent ran over 0x2013DB74, so
its coverage counted both functions' blocks); `mmio_seq` plays a fixed MMIO read sequence (a CMD6 status block
through SD_BUF0); a preset may substitute a copy of the SDHI operation table with slots 6 and 7 answering 0 (the
card layer takes the table from the handle, so it is an input), which reaches the switch functions' accepting paths.

### DISPLAY: code (round 8)

| Where | Functions | Notes |
|---|---:|---|
| `drivers/sd_setup.c` (new) | 25 | clock, init v2 / v1 or MMC, CMD11, CMD3, CID check, CMD7, the transfer-state selection, ACMD51/6/13, CMD6, high speed, UHS, driver strength, bus speed, identify, CSD/CID, selected op, SCR bus width, sector and partition read/write, the card check |
| `drivers/sd_drive.c` (new) | 17 | volume mount, `sd_driver_op` and its operations (attach, mount, unmount), task start, remount, poll, unmount, write protect, cluster-map state and prepare, mutex, CPU lock pair, `sd_delay_ms` |
| `app/fat_format.c` | 15 | progress counters, layout, MBR, boot sector, FSInfo, FATs, root directory, volume id, geometry, volume format, `sd_fat_format`, `sd_format` |
| `include/sd.h` | | the 26 operation slots by name, card context (sector buffer, SCR, SD status, CMD6 block, flags, speed, clock, format parameters, progress), drive record |

Findings are in docs/code/display/filesystem.md "SD card layer, recreated (T24 round 8)". In short **[fact]**:
twelve functions had no Ghidra entry (tail-call targets folded into their callers; `sd_select_bus_speed` is 104
bytes, not 1,084); the UHS path is dead on this host (slots 4..7 answer -9, -10, 4, 5); the format code refuses
cards of 32 GB and more (-5); the volume id ORs year, minute and hour where a DOS date would add them;
`sd_card_unmount` 0x2013FD50 is a tail call of `fs_drive_unmount` (Ghidra's C showed that function's body).
Not done: `sd_ins_check_task` (an endless task loop), `sd_mount_volume` and `sd_drive_mount` (equivalent in all
trials but below the coverage floor: random sector data never holds a valid MBR); the FAT file system, the MAIN
link, the update code and the GUI building blocks.

Mutations: reported as differing: `+0x41000000` → `+0x40000000` in `sd_init_v2`, the volume id's 1900 → 1901, the
FAT12/16 root directory 0x20 → 0x10 sectors and a reserved-sector step in `fat_format_layout`. Not caught (trials
do not reach them): the clock mode of the SDR104 case in `sd_switch_uhs_speed`, the "cannot switch" test of
`sd_set_driver_strength`, the `rsv < 9` boundary of the layout.

### DISPLAY: checks and hybrid image (round 8)

- `make link` **[fact: the run]**: 634 recreated functions linked, 145 in place (16,400 bytes), 489 in the gap
  0x2042BC10..0x2043C910 (68,864 of 82,928 bytes), RAM2 empty; 489 entries patched (14,587 bytes of the image
  changed); 51 byte-identical left as they are; 3 not linked (not verified); 1 held back (`gpio_cfg_reset`, reset
  path). abicheck: the one known direct hazard (`sdhi_error_reset` / `sdhi_soft_reset`, dropped because its caller
  is linked); 339 calls through a register, none reads r1, r2, r3 or ip after the call; 124 address-taken.
- **linkcheck: 634 of 634 agree** (100 trials per entry) **[fact: the run]**.
- **Emulated boot** (`display_boot_emu.py --compare`, seed 1, 1.5·10⁹ instructions each) **[fact: the run]**: the
  hybrid **agrees with the original**: no fault, 33 tasks, `task_root` and `gui_main_loop` reached, 744 image functions
  reached (original 712), 179 recreated functions executed, RAM2 empty and intact, nothing in the watched range,
  5,648 untouched bytes at the bottom of `task_root`'s stack (original 5,672). No new defect found: the SD code is not
  reached in the boot (no card data), so the boot says nothing about it beyond the link.
- The gap has 14,064 bytes left (about 12 KB of armcc code at round 5's ratio); the next round's code goes into RAM2
  (round 6's mechanism, tested with `--gap-limit`).

### DISPLAY: results (status.tsv, round 8)

| Verdict | Ghidra functions | Bytes (of 396,256) |
|---|---:|---:|
| identical | 48 | 3,942 |
| equivalent | 626 | 71,714 |
| differs | 0 | 0 |
| not yet | 1,546 | 320,600 |

**Re-implemented: 19.09 %** (75,656 bytes; round 7: 16.30 %), pinned xPack GCC 10.2.1, 200 trials per function.
Bytes count with the Ghidra sizes of the round-7 export, in which `sd_select_bus_speed`, `sd_card_identify`,
`sd_driver_op` & co. still include the twelve functions without an entry; after the round-8 re-export they count in
their own rows.

### DISPLAY: Ghidra (round 8)

`tools/ghidra/entries_display.T24r8.tsv` has 12 new entries (also appended to `entries_display.tsv`),
`names_display.T24r8.tsv` 16 names with evidence (also in `names_display.tsv`; the superseded rows of 0x2013DE60 and
0x2013F79C removed): the twelve entries, `FUN_2013c928` → `sd_card_clock`, `FUN_2013cde8` →
`sd_cmd11_voltage_switch`, `sd_switch_status_check` → `sd_set_driver_strength`, `fat_clear_root_dir` →
`fat_format_volume`. Proved on a copy (`/home/user/ghidra_tasks/t24r8/disp`, OWNER root) **[fact: apply.log,
modes.tsv there]**: FixFuncEntries 12 created, 0 failed, 10 branches marked as tail calls; ApplyNames 1,939 applied,
0 failed; ExportFuncModes 2,270 functions (was 2,260), all A32; the callers shrink to their own code
(`sd_select_bus_speed` 1,084 → 104, `sd_card_identify` 624 → 308, `sd_read_csd_cid` 304 → 108, `sd_driver_op`
700 → 164, `fat_format_volume` 356 → 160, `sd_drive_flag5` 40 → 8); 0x2013F9F4 / 0x2013F9F8 were listed as
`itron_loc_cpu` / `itron_unl_cpu` (Ghidra named the one-branch thunks after their targets) and become `sd_lock` /
`sd_unlock`. No other entry, size or mode changes. Commands for the canonical project (repository root):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/display/quality.tsv /tmp/quality_display_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -scriptPath tools/ghidra \
  -postScript FixFuncEntries.java tools/ghidra/entries_display.T24r8.tsv \
  -postScript ApplyNames.java tools/ghidra/names_display.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/display" 50 \
  -postScript ExportFuncModes.java "$PWD/src/display/modes.tsv"
python3 -I tools/decomp_quality.py compare /tmp/quality_display_before.tsv decomp/display/quality.tsv display
make -C src/display && python3 -I tools/equiv_display_emu.py status
python3 -I tools/readability_stats.py readme
```

After the re-export the alias rows of round 8 give addresses (or the old Ghidra names `sd_switch_status_check`,
`fat_clear_root_dir`, which the resolver falls back from, round 7) and become redundant.

### DISPLAY: blockers and next steps (round 8)

- Not reached this round: the FAT file system, the MAIN link (`docs/code/display/mainlink.md`), the update code and
  the GUI building blocks. The time went into the harness (measurement first: the per-run memory cost, not the
  bursts, dominated) and the SD layer's presets (its paths need card answers in a consistent order).
- `sd_mount_volume` and `sd_drive_mount` agree in all trials but stay below the coverage floor: a preset that serves
  an MBR and a boot sector through SD_BUF0 (`mmio_seq`) would settle them.
- Faster still: compare only the pages a run wrote (the anonymous pages of the private mapping, `/proc/self/pagemap`),
  and per-entry times for linkcheck.

## MAIN, round 4 (2026-11-01)

### Plan (MAIN round 4)

1. Harness housekeeping: every temporary file of a run under one scratch root that the run removes, also when it is
   killed; partial `status` runs (a full one takes about an hour on the shared container).
2. `cat_SQ`: whether a `lrintf` that GCC for RX inlines as ROUND matches the image's rounding.
3. Code, biggest first: the large CAT handlers (SS, CO, MW, SF, MR, CF, DT, SH, IF/OI, BP, KM, GT, VM, EM, MC,
   FA/FB), `keyer_task`, the tuner tasks, the DISPLAY frame builders and receive handlers, the main loop and tasks.
4. Coverage presets for `cat_dispatch` (55 %) and `trx_sequencer` (60 %).
5. `status.tsv`, the README progress block, Ghidra rows with the apply commands.

### MAIN: harness changes (round 4)

- **Temporary files.** Everything a run writes (link scripts, the workers' project copies, the Ghidra logs) is under
  one `equiv_main_run_*` directory (`EQUIV_MAIN_SCRATCH`, default the system temp directory). The owning process
  removes it on exit and on SIGTERM/SIGHUP/SIGINT (pool workers inherit the handler and close their engines); a
  directory whose owner pid is gone (SIGKILL) is removed by the next run. Ghidra runs in its own process group, so
  `close()` kills the JVM, not only the launcher script [fact: a SIGTERM during a two-worker check left no process
  and no directory]. The `/tmp/equiv_main_*` left by rounds 1..3 were removed.
- **Partial status runs.** `status FUNCTION... / --object O` reruns those and keeps the other rows of status.tsv.
- **FTOI, ROUND, FTOU.** The module's p-code for all three was `Rd = round(src)`, a float result: FTOU of 50.7 gave
  0x424C0000 (the float 51.0) and 0.5 gave 0x3F800000 [fact: `tools/rx_fpconv_check.py module`]. T22a had modelled
  no FPU instruction but ITOF. `EquivMainEmu.java` now steps the instruction (so its load is seen) and then sets Rd
  and Z/S after the RXv2 manual: FTOI p. 103 and FTOU p. 106 round towards 0 whatever FPSW.RM says, ROUND p. 171 by
  RM (MAIN sets FPSW = 0x100, RM = 0, at 0xFFF8FBFF), NaN and out of range per Table 1.5 (p. 26) with
  the flags unchanged. `tools/rx_fpconv_check.py`: **84 / 84 agree** with the manual (21 values each: ties, limits
  around 2^31 and 2^32, infinities, NaN; FTOU also from memory). No function checked before round 4 contains one of
  the three [fact: MAIN's 12 FPU conversions are all FTOU, in functions not yet recreated; the GCC objects had no
  FPU instruction]. `tools/ghidra/rx62t-fpconv-fix.patch` (ninth `--only rx` stage, `8451ead0…8ed7` →
  `f4688bc6…f403`) fixes the module for the decompiler: FTOI `trunc`, FTOU `trunc` through 64 bits, ROUND to nearest
  even from `trunc`; checked on a private Ghidra copy (in-range values all agree; NaN, range and FTOU of values
  <= -1 left to the engine) and the decompile of `cat_SQ` then reads `(byte)(longlong)(x * 100.0 / 255.0 + 0.5)`.
  **Not installed in the container's shared Ghidra** (docs/tooling.md "Float to integer").
- **Per-function stubs with chosen returns** (`FUNC_STUBS`; `EquivMainEmu.java` `stub_rets`): a task's gate callees
  are stubbed with return values drawn from a list, and the calls are compared like the EEPROM stubs. Used for
  `keyer_task` (`tx_cw_keying_class`, `swtimer_expired`, `FUN_fffb2dfe`, `tx_breakin_on`) and `trx_sequencer`
  (`swtimer_expired`). Only callees whose side effects the caller does not read back are stubbed.
- **More trials and enumerated presets** (`FUNC_TRIALS`, `_TRIAL`): `cat_dispatch` 800 trials whose preset goes
  through every (index, length) pair of `decomp/main/cat_dispatch.tsv` before random ones; `trx_sequencer` 400.
- **Presets**: `cat_SS`, `keyer_task` (state, speeds, keyer type, message slot and CW MEMORY n, texts of the special
  characters, element counts), the memory-channel commands (MR, MC: a channel as three digits or a name, the
  channel-used flags; MW: IF's layout with each field valid most of the time), `cat_SF`, `cat_DT`; the generic CAT
  preset puts '0' in P1/P2 half the time.

### MAIN: `cat_SQ` and `lrintf` (round 4)

The question of round 3 was whether a `lrintf` that GCC for RX inlines as ROUND matches the image's rounding. Answer
**[fact]**: (1) GCC 13.3.0 for RX never inlines `lrintf`: `__builtin_lrintf` and `lrintf` compile to a call of
`_lrintf` at -O0 and -Os, also with `-ffast-math`, `-fno-math-errno`, `-funsafe-math-optimizations`; only the target
builtin `__builtin_rx_round` emits `ROUND` (test compile, `-mcpu=rx600`). (2) The image does not round with ROUND:
`cat_SQ` converts with **FTOU** after `FADD #0x3F000000` (0xFFFAE717 / 0xFFFAE71E, 0xFFFAE806 / 0xFFFAE80D), a C cast
to unsigned of `x + 0.5f`; the `ROUND()` in decomp/main is the module's p-code for FTOU (above). So the recreation
is `(uint8_t)(int)(v * mul / div + 0.5f)` (GCC's FTOI; in range 0.5..255.5 the two casts agree, and an unsigned
cast would call libgcc's `__fixunssfsi`), **equivalent**, and a mutation without the `+ 0.5f` differs (trial 22).
With the old FTOU p-code the original's reply was the low byte of a float's bits, so no recreation could have
matched it.

### MAIN: recreated (src/main, round 4)

- `app/cat_scope.c`: `cat_SS` (2,917 bytes). `app/cat_dsp.c`: `cat_CO`, `cat_BP`, `cat_SH`, `cat_GT` on the per-mode
  block. `app/cat_vfo.c`: `cat_FA_FB`, `cat_IF_OI`, `cat_CF`, `cat_MR`, `cat_MW`, `cat_MC`, `cat_VM` over shared IF
  layout helpers (channel, clarifier offset, mode/state/tone/shift). `app/cat_handlers.c`: `cat_SQ`, `cat_SF`,
  `cat_DT`, `cat_EM`, `cat_KM`. `app/cat_util.h`: the helpers these files share (moved out of cat_handlers.c; the
  41 handlers of round 3 still pass).
- `app/keyer.c`: `keyer_task` (2,120 bytes) with named states and soft timers; the message memories as
  `struct keyer_msg` / `struct keyer_text` (main_ram.h); RAM names for the speed, dot/dash times, QSK delay, element
  counts (data_symbols.tsv, and as Ghidra labels below); `keyer_msg_active` and `keyer_state` of round 2 are
  renamed `keyer_type` and `keyer_elem_buf` after what keyer_task does with them.
- Behaviour found on the way, each **[fact]** with its address in docs/code/main/cat.md "Handler behaviour found by
  the source recreation": BP00 with P3P4 not 00 is ignored without an error; CO refuses an APF set outside the CW,
  RTTY and DATA/PSK blocks and when the flags byte is 0xFF; SH and GT print an uninitialised stack byte for mode
  code 15, MR uses one as the channel for 000 or > 099 (the recreation answers 0, which is what the check's zeroed
  stack gives the original; on the radio the byte is whatever the stack held); MW sets the memory channel before it
  checks the rest and does not store the clarifier; MC always saves channel 1; KM does not limit the count to 50.
- **Round-3 bug found by the new coverage:** `spk_route` (0x20FCC) is a 32-bit word in every access (MOV.L at
  0xFFFB732C, 0xFFFB8280, 0xFFFB853E, 0xFFFB8AC5, 0xFFFB8B71, 0xFFFB8BAF) **[fact]**; round 3 declared it `uint8_t`
  and `trx_sequencer` compared a byte. With the timers stubbed, trial 115 differed (a peripheral read of PORTB_PODR
  where the original called `ear_det`); fixed in main_ram.h.
- **GCC and byte arguments:** GCC passes a `uint8_t` argument loaded with the sign-extending `MOV.B`; an image callee
  that uses the whole register (`bcd_to_ascii2`, signature `uint`) printed a byte >= 0x80 differently (cat_DT, trial
  17) **[fact]**, so such callees are declared with `uint32_t`.
- Every image address cited in the new files was checked to be an instruction of what it is cited for (a
  disassembly lookup over the files); eight citations taken from the decompile were wrong and were corrected.
- `app/tuner.c`: `tuner_int_task`, `tuner_ext_task`, `tuner_atas_task` (the step switches and the indicator blink)
  and `tuner_rearm`. `app/display_link.c`: `displink_task` (receive, NAK for an unknown type or a bad sum, the gap and
  ACK window, ACK/NAK first), `displink_rx_E1_encoder`, `displink_build_status` (the 0x97-byte status block: fixed
  offsets, the VFO sections swapped in place when VFO-B is active) and the frame builders 0x30, 0x31, 0x37, 0x39,
  0x41, 0x60, 0x70 (0x31, 0x37 and 0x70 table-driven). Found **[fact]**: `displink_rx_E1_encoder` calls
  `FUN_fffc523a(0, 0)` with R3 still holding the step byte (0xFFF95A02), and the callee stores its third argument, so
  the step reaches 0x1B4E3 (the recreation passes it explicitly); `displink_build_41` keeps its write offset in RAM
  (0x1B632) and the row's record in 0x20884 (docs/code/main/display-link.md "Found by the source recreation").
- Not recreated: `main_loop` never returns, so both runs exhaust the budget and the check cannot decide (*Open: a
  check mode for endless loops; would be settled by comparing the call sequence of the first N iterations*);
  `cat_OS` (round 3: an uninitialised record pointer).

### MAIN: harness, more (round 4)

- `EQUIV_MAIN_OBJDIR`: the objects to check (e.g. a `make OUT=out2` build), so new code can be checked while a status
  run reads `out/obj`.
- `STACK_PTR_SLOTS`: `displink_send_ack` hands `R_SCI1_Serial_Send` a one-byte buffer on its stack, which the driver
  keeps in `gp_sci1_tx_address` (0x207FC); its value follows the caller's frame depth (12 bytes under CC-RX in
  `displink_task`, 28 under GCC). A stack address left there is compared as "stack" (the byte itself goes out through
  the compared SCI accesses), as round 3 did for the EEPROM stub buffers.

### MAIN: results (status.tsv, round 4)

`equiv_main_emu.py status --trials 200 --jobs 2` (about 45 minutes with the container shared), then
`status --object app/tuner.o --object app/display_link.o --object app/sdr_link.o --object app/tasks.o` for the code
written while the first run read `out/obj` (about 35 minutes):

| Verdict | Ghidra functions | Bytes (of 387,059) |
|---|---:|---:|
| identical | 44 | 264 |
| equivalent | 341 | 77,076 |
| differs | 0 | 0 |
| not yet | 3,409 | 309,719 |

**Re-implemented: 19.98 %** (12.32 % after round 3). Round 4 added 39 functions (29,635 bytes counted): DISPLAY link
11 (8,645: the status block, seven frame builders, `displink_task`, `displink_rx_E1_encoder`, `dispreq_e7_task`),
VFO / memory CAT handlers 7 (6,157), the other CAT handlers 5 (3,952), the per-mode-block handlers 4 (3,777), `cat_SS`
(2,917), `keyer_task` (2,120), the tuner tasks 4 (766), `sdr_task` (664) and the small tasks 5 (637; `wdt_kick` is
byte-identical). The 346 functions of rounds 1..3 still pass, among them `cat_dispatch` with 99 % of its blocks
(was 55 %) and `trx_sequencer` with 90 % (was 60 %; 400 trials) after the `spk_route` fix. Lowest coverage of the new ones:
`sdr_task` 52 %, `cat_EM` 66 %, `cat_GT` 68 %; `io_task` has 137 of 200 trials inconclusive (both runs exhaust the
budget in its callees).

### MAIN: Ghidra (round 4)

- `tools/ghidra/names_main.tsv`: 44 labels with their evidence (the keyer, tuner and DISPLAY-link RAM of this round,
  `cat_sq_level`, the message memories, `morse_table`, the frame-0x41/0x39/0x70 ROM tables, the status-block
  globals), and the `@spk_route` comment now says 32 bits. `tools/ghidra/signatures_main.tsv`: `mem_find_byte`
  returns `uint8 *` (the decompile showed void and lost the result in `cat_EM` / `cat_KM`).
- `tools/ghidra/rx62t-fpconv-fix.patch`: FTOI / FTOU / ROUND for the decompiler (the ninth `bootstrap.sh --only rx`
  stage, above). After it the FTOU sites decompile as casts instead of `ROUND()` (checked for `cat_SQ`).
- Proved on a copy of `/home/user/ghidra_tasks/t24main/proj` [fact: the script log]: ApplyNames **2,854 applied,
  0 failed** (2,810 + 44), ApplySignatures **1,231 applied, 0 failed** (1,230 + 1); the decompile of `cat_EM` then
  reads `pbVar3 = mem_find_byte((byte *)&em_text_mem,-2,0x32)`. The patch: on a private Ghidra copy (above).

Commands for the canonical project (repository root; Ghidra closed):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
tools/bootstrap.sh --only rx                                   # applies rx62t-fpconv-fix.patch and recompiles rx62t.sla
cp decomp/main/quality.tsv /tmp/quality_main_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
  -postScript ApplyNames.java tools/ghidra/names_main.tsv \
  -postScript ApplySignatures.java tools/ghidra/signatures_main.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/main" 50 \
  -postScript CatDispatch.java "$PWD/decomp/main/cat_dispatch.tsv" 0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
python3 -I tools/decomp_quality.py compare /tmp/quality_main_before.tsv decomp/main/quality.tsv main
rm -rf /home/user/ghidra_tasks/t24main/proj/FT710_MAIN.rep    # refresh the harness copy
cp -r ghidra/FT710_MAIN.gpr ghidra/FT710_MAIN.rep /home/user/ghidra_tasks/t24main/proj/
python3 -I tools/rx_fpconv_check.py module   # the patched module: every in-range value agrees (NaN / range are the engine's)
python3 -I tools/equiv_main_emu.py status
python3 -I tools/readability_stats.py readme
```

`bootstrap.sh --only rx` changes the shared Ghidra's `rx62t.sinc` hash (`RX_SINC_FIXED` becomes `f4688bc6…f403`), so
a branch without this patch then refuses to bootstrap that Ghidra, as with round 2's patch.

### MAIN: blockers and next steps (round 4)

- **CC-RX** is still not obtainable from the container ("MAIN, round 1").
- **FPU instructions other than the conversions are unverified.** T22a modelled only ITOF; FADD, FSUB, FMUL, FDIV,
  FCMP (MAIN: 31, 18, 28, 25, 40 sites) run on the module's p-code, which uses the host's IEEE single precision
  (round to nearest). *Open: whether the module's FCMP flags and the FPSW.DN = 1 flush of denormals match the RX
  FPU; would be settled by `rx_semcheck.py` cases for the FPU forms with denormal and NaN operands.* `beep_task`
  (bit-exact float constants and FCMP) waits for that.
- **Endless functions:** `main_loop` (and the power-off loop) cannot be decided by a check that needs a return.
- **Coverage still below 90 %:** `sdr_task` 52 % (each updater that writes ends the pass; the per-step returns are
  reached only when that updater writes), `cat_GT` 68 %, `cat_EM` 66 %.
- **Shared Ghidra:** the round-2 and round-4 SLEIGH patches are not installed in the container's Ghidra; the harness
  does not depend on them (EquivMainEmu executes JMP and the conversions itself).
- Next, by size: `displink_rx_F0_hello` (892), `displink_tx_schedule` (689), `ladder_key_task` (699), `key_task`
  (939), `dsp_link_poll` (1,591), `beep_task` (1,220, after the FPU check), the `cat_ai_*` change detectors
  (`cat_ai_IF_OI` 1,333, `cat_ai_SS` 1,121, `cat_ai_poll` 979), the extended CAT commands (`cat_ext_PE` 1,166,
  `cat_ext_EO` 847, `cat_ext_JP` 822), `keyer_output_step` (1,397) and `keyer_elekey` (1,225).

## SDR RTL, round 1 (2026-11-01)

### Plan (SDR round 1)

Re-implement the RX front end that #172/#193 traced, block by block, each against a netlist slice whose cell set is a
`slice:N` row of `tools/sdr_blocks.tsv` (so the verified cells and the counted cells are the same): the DC removal of
both ADC channels, the gain/round/clamp stage of both, then the A + B combine. Slice boundaries go on registers with a
clear meaning (IDDR outputs, the y register, register-bank bits, the operand registers' D nets); every other slice
input is driven with random bits. Then the register file, the scope writer and the decimator stages, as far as the
round goes.

### SDR: results (round 1)

| Block (tsv row) | RTL | Cells | Check [fact, Icarus 11] |
|---|---|---|---|
| `adc_dc_a`, `adc_dc_b` | `hdl/sdr/adc_dc.v` | 227 + 225 | `tb_adc_dc.v -DSTRUCT` (`-DCHB`): 4,000,000 clocks each, 0 mismatching clocks |
| `adc_gain_a`, `adc_gain_b` | `hdl/sdr/adc_gain.v` | 190 + 189 | `tb_adc_gain.v -DSTRUCT` (`-DCHB`): 2,000,000 clocks each, 0 mismatching clocks |
| `adc_combine_mux` | `hdl/sdr/adc_combine.v` | 378 | `tb_adc_combine.v -DSTRUCT`: 2,000,000 clocks, 0 mismatching clocks |

SDR re-implemented: **3.1 % -> 5.0 %** of 63,735 cells (1,973 -> 3,182; `decomp/sdr/progress.tsv`). New
`tools/sdr_progress.py --slice BLOCK OUT.v` writes the slice of a `slice:N` row. Findings (rounding half away from zero,
symmetric clamp, gain 0x8000 = unity, the 8-bit override fields, the combine's strobe/reset and the level flag's
thresholds) are in [netlist.md 3.7](../code/sdr/netlist.md#37-adc-capture-two-14-bit-channels-dc-removal-and-per-channel-gain-172).

### SDR: blockers and next steps (round 1)

- **Register file** (`register_bank`, 1,597 cells): not a block with one boundary. A scan for flip-flops whose D comes
  from the link's nibble registers finds 974 register bits under 86 write enables spread over the die, with the read
  mux in `SLICE_X9..X14Y63..Y70`. A slice from the read-data flops back pulls in most of the link; it needs the
  `uart_link.v` style of check (whole-netlist co-simulation, writes checked through read-back and through the register
  bits' Q), plus the address map of every bit. Open: the address of each write enable; would be settled by a
  write-one-register-at-a-time sweep in the whole netlist that logs which enables pulse (as #193 did for reg 0x0A).
- **Scope writer** (1,948 cells) and **decimator stages**: their slices reach block RAMs (delay lines, coefficient
  ROMs, the scope RAM), so the Icarus slice runs need `hdl/sdr/sim/xc7_bram_vl.v` in place of the Yosys RAMB18E1 and
  stops on the BRAM outputs or the BRAMs as seeds; not started.
- **Override fields of the gain stage.** Open: which MAIN register holds them; would be settled by a register sweep.

## MAIN, UI track (2026-11-01; parallel to MAIN round 5)

### Plan (UI track)

A second MAIN worker on areas round 5 does not touch: the BSP and system code not done yet, the meters, the dial-step
helpers, the beep requests outside `beep_task`, the FUNC knob and key dispatch, the frame-0x50 keyboard builders.
Own Ghidra copy `/home/user/ghidra_tasks/t24main_ui/`, own files (`bsp/r_bsp_sys.c`, `app/meters.c`, `app/ui_*.c`,
`include/ui.h`), own preset block in `equiv_main_emu.py` (`UI_PRESETS`).

### MAIN: recreated (UI track)

| File | Functions | Bytes counted | What |
|---|---:|---:|---|
| `bsp/r_bsp_sys.c` | 62 (9 identical) | 6,215 | FIT locks, PSW helpers, register protection, `R_BSP_SoftwareDelay`, the callback table and `R_BSP_InterruptControl` with its helpers, group enables, five exception vectors and the bus-error vector, the software-interrupt queue and its ISRs, the clocks, `bsp_non_existent_port_init`; the CC-RX setters and `chg_pmusr` as naked transcriptions (byte-identical) |
| `app/meters.c` | 28 | 2,329 | VDD, IDD, ALC, PO, COMP, S, the 16-sample averages, getters, `meter_task`, `adc_scan_blocking`, `vdd_scale_calc`, `remote_keypad_scan` |
| `app/ui_funcknob.c` | 35 | 1,744 | the FUNC-knob entries and steps (one clamp helper; ui-keys.md "Found by the source recreation") |
| `app/ui_kbd.c` | 11 | 1,335 | `dl50_*`, `kbd_fmt_char_pos`, `kbd_copy_text` |
| `app/ui_dial.c` | 4 | 850 | `dial_step_hz`, `dial_step_mode_hz`, `ch_step_hz`, `ch_step_scale` |
| `app/ui_keys.c` | 16 (2 identical) | 799 | `key_class_of`, `key_assign_slot`, `key_call_*`, `key_slot_*`, `key_nop`, `key_task_init`, CONTOUR / APF reset |
| `app/ui_beep.c` | 5 (1 identical) | 246 | `beep_request`, `beep_stop`, `beep_pattern_get`, `tone_idle`, `tone_set` |

Not done, with the reason: `NMI` (ends in an endless loop), `R_Systeminit`, the six group-interrupt dispatchers
(`vec106`..`vec113`, 2.2 KB), `swr_meter_protect` (SWR and the HI-SWR protection: TX protection is round 5's),
`key_task`, `key_event_filter`, `key_touch_scope_tune`, `enc_*`, the physical-key handlers, `funcknob_step` /
`_popup_step` / `_mgroup_step` / `_mic_eq_step` / `_rf_power_step` / `_bk_in_step` / `_dnr_level_step`, `kbd_edit_*`,
`ladder_key_task`, `displink_rx_E6_beep` (a DISPLAY-link receive handler, round 5's), `keyer_sidetone_on` (its name is
also the RAM flag 0x1215E of `keyer.c`; one of the two needs another name first).

### MAIN: harness findings (UI track)

- **SUNTIL / SWHILE counted twice [fact].** `EquivMainEmu.java` set R3 in its `suntil`/`swhile` pcodeop, and the
  module's constructors (rx62t-rxv2-fix.patch) reduce R3 from the returned pointer again, so `dl50_memory_name`'s title
  copy (SUNTIL.B, SMOVF of -2 - R3 bytes) copied 23 bytes of "MEMORY NAME" instead of 11. Fixed in the engine (R3 is
  left to the module). MAIN has six SUNTIL/SWHILE, all in the `dl50_*` builders [fact: rx-elf-objdump of the image],
  so no earlier verdict depended on it.
- **MAX #imm is MIN in the module [fact].** rx62t.sinc's `MAX liop, reg0_4` (and the `MAX dsp[Rs]` forms) is
  `if (src > Rd) skip; Rd = src`, the same body as MIN, and both compare unsigned where the RXv2 manual's MAX / MIN
  compare signed. MAIN uses neither [fact: the forms list], so the decompile is unaffected; GCC does. Found with
  `funcknob_peak_step`, whose clamp GCC folded into `MAX #0` / `MIN #4` and the emulation then stored the setting
  unchanged; the recreation now keeps compare-and-branch. The other recreated objects use only MIN (`cat_SS`,
  `displink_build_41`, `keyer_task`, `meter_vdd`, `meter_comp`), and their checks pass; *Open: whether a negative
  operand reaches one of those MINs; would be settled by the module fix and a rerun of their objects.* *Open: the SLEIGH fix
  (`s>`/`s<` and MAX's direction) as a tenth `--only rx` stage, or an engine override like JMP; would be settled by
  `rx_semcheck.py forms` cases for MAX/MIN with negative operands.*
- **FTOU from GCC code.** GCC for RXv1 has no FTOU and its unsigned cast calls `__fixunssfsi`, so the meters and
  `tone_set` write FTOU as its encoding (`FC A7 rs:rd`), which the engine executes after the manual.
- Presets in `UI_PRESETS` (software-interrupt slots with the image's dummy task, the BSP vector and region ranges,
  the dial-step flags through 0x25D58, key codes inside the 863-entry tables: a random code read past the table into
  `Undefined_0xD8`, whose RTE popped the caller's frame), and `adc_scan_blocking` with its two driver calls stubbed.
- The float meters (PO, COMP, S, VDD) and `tone_set` are compared on the module's FADD/FSUB/FMUL/FDIV/FCMP, which round
  5 checks; their verdicts should be rerun after that check (`status --object app/meters.o --object app/ui_beep.o`).

### MAIN: results (UI track)

`equiv_main_emu.py status --jobs 2 --object` for the seven objects, 200 trials, after merging origin/main: **161 functions, 13,518 bytes counted: 12 identical (80 bytes), 149 equivalent (13,438), 0
differs.** MAIN total: identical 56, equivalent 490, not yet 3,248; **23.47 %** (19.98 % after round 4).

### MAIN: Ghidra (UI track)

`tools/ghidra/names_main.T24ui.tsv` (also appended to `names_main.tsv`): 21 function names for `FUN_` entries (the FIT
helpers, the meter averages, `ch_step_scale`, `beep_pattern_get`) and 9 labels (BSP, meter and channel-step tables), each
with its evidence. Proved on a copy of `/home/user/ghidra_tasks/t24main_ui` [fact: the script log]: ApplyNames **2,884
applied, 0 failed** (2,854 + 30). Commands for the canonical project (repository root; Ghidra closed):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
cp decomp/main/quality.tsv /tmp/quality_main_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
  -postScript ApplyNames.java tools/ghidra/names_main.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/main" 50 \
  -postScript CatDispatch.java "$PWD/decomp/main/cat_dispatch.tsv" 0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
python3 -I tools/decomp_quality.py compare /tmp/quality_main_before.tsv decomp/main/quality.tsv main
rm -rf /home/user/ghidra_tasks/t24main/proj/FT710_MAIN.rep    # refresh the harness copy
cp -r ghidra/FT710_MAIN.gpr ghidra/FT710_MAIN.rep /home/user/ghidra_tasks/t24main/proj/
python3 -I tools/equiv_main_emu.py status
python3 -I tools/readability_stats.py readme
```

After the re-export the 21 functions carry their new names in `decomp/main/functions.tsv`; the rows in
`src/main/aliases.tsv` then name the same addresses and can be removed.

## MAIN, round 5 (2026-11-01)

### Plan (MAIN round 5)

1. FPU semantics: FADD/FSUB/FMUL/FDIV/FCMP/FSQRT/ITOF/UTOF (and the round-4 conversions) against the RXv2 manual,
   rounding modes, FPSW flags, denormals and NaNs, the way `rx_fpconv_check.py` and T22a did; fix the module in a new
   `rx62t-*-fix.patch` and/or the engine; then `beep_task` and the other float users.
2. Code, biggest first: CAT handlers, tasks and DISPLAY-link handlers, menu, band/VFO/memory, TX protection.
3. Coverage of `sdr_task` (52 %), `cat_EM` (66 %), `cat_GT` (68 %); the inconclusive `io_task` trials; `main_loop` for
   one pass.
4. `status.tsv`, the README block, Ghidra rows with the apply commands.

### MAIN: the FPU (round 5)

MAIN uses FADD 31, FSUB 18 (one 3-operand, `signal_level_squelch` 0xFFFB7ECD), FMUL 28, FDIV 25, FCMP 40, ITOF 42 and
FTOU 12 times, in 23 functions; no FSQRT, FTOI, ROUND or UTOF **[fact: rx-elf-objdump of 0xFFF8FBDB..0xFFFEE2B7]**. FPSW is
0x100 (RM 0, DN 1, all exceptions masked) from 0xFFF8FBFF on; the only `R_BSP_InterruptControl(…, 1, …)` call enables
vector 0xB, not the FPU's 3 **[inference from the call sites; docs/tooling.md "The other FPU instructions"]**.

- **Engine.** `EquivMainEmu.java` executes every FPU instruction itself (`RxFpu`): exact arithmetic on (sign, BigInteger,
  exponent) with one rounding by FPSW.RM; DN = 1 reads a denormal as a zero of its sign and returns 0 for an underflow,
  DN = 0 starts unimplemented processing; Table 1.6 NaN results (the QNaN operand, an SNaN made quiet, 7FFFFFFFh for an
  invalid operation without a NaN); overflow by RM (Table 1.1); division by zero; FCMP's Z/S/O; FPSW cause and
  accumulated flags (Fj only while Ej = 0, FS); an enabled exception ends the run as a fault with the destination
  unchanged. The memory operand goes through the same load path as the module's p-code (I/O recorded, tracked bytes).
  The result carries FPSW; `compare` checks its mode bits (RM, DN, EV..EX), not the flags (MAIN reads them only in the FPU
  exception handler, which never runs, and GCC folds constant FDIVs whose inexact flag the original sets: `meter_comp`).
- **Check.** `tools/rx_fpu_check.py` runs 11,950 cases (every form: #imm, Rs, [Rs].L, dsp:8, dsp:16, 3-operand; ITOF/UTOF
  every memex; specials, ties, limits, random values; RM 0..3, DN 0/1, enable bits) against a model written from the
  manual in Python fractions: **11,950 / 11,950 agree**. `rx_fpconv_check.py`: 84 / 84 still.
- **The module (`rx_fpu_check.py module`)** disagrees on 4,136 of 11,553 returning cases **[fact]**: FCMP never writes O
  (and FCMP #imm compared through `Rs f- imm`), S of a float result is `f< 0` (clear for -0), UTOF does not decode (FC 54..57)
  and converts 2^31.. as negative, plus the host-arithmetic classes it cannot change (DN, NaN payloads, RM, the invalid
  NaN). The O flag matters for MAIN: 17 BLT and 1 BGE follow an FCMP, and a stale O from an earlier ADD inverted them in
  the emulator and the decompile (`swr_meter_protect`: `10.0 < (float)uVar6 == bVar1` with `bVar1 = SCARRY4(...)`).
  `rx62t-fpu-fix.patch` (tenth `--only rx` stage) fixes the first three; then only DN 599, NaN 953, RM 381 and invalid 426
  disagree, none with MAIN's FPSW and normal operands.
- **GCC and NaN [fact: the objects].** GCC for RX tests a float compare with S alone (`a < b` BN, `a >= b` BPZ), so a NaN
  passes `a >= b`, and it drops a `v != v` next to such a compare as redundant. CC-RX's BLT/BGE read O. `swr_meter_protect`
  gets 0 / 0 with no RF (both ADC readings 0), which the image counts as in range; the recreation tests the NaN on the bits
  (`app/fpu_conv.h` `is_nan`), and `ftou()` writes CC-RX's FTOU in C (GCC's unsigned cast calls `__fixunssfsi`).
- **MIN / MAX [fact].** All six constructors were an unsigned minimum, MAX too (found in parallel by the UI track).
  `rx62t-minmax-fix.patch` (eleventh stage) makes them signed with MAX keeping the larger value; `rx_semcheck.py` models
  MIN/MAX, and the forms check gains MIN/MAX #imm, Rs and memory forms, SCGE.L, SCLT.L: **5,960 / 5,960** with the patch,
  807 failures without. This settles the UI track's two Open points on MIN/MAX: the fix is a SLEIGH stage, and the objects
  using MIN (`cat_SS`, `displink_build_41`, `keyer_task`, the meters, `swr_meter_protect`) were rerun in the status below
  with the patched module.
- Open (both readings are the model's and the engine's): whether underflow is decided before rounding (p. 24 does not say),
  and whether "the S and Z flags do not change when an exception is generated" also covers a masked exception such as
  inexact; would be settled by FADD of a result just below 2^-126 and of 0.1f + 0.2f on an RX651, reading the
  destination and PSW. MAIN never branches on S/Z after an FPU arithmetic instruction [fact: the instructions after each].

### MAIN: harness changes (round 5)

- `stub_sets` (a stubbed callee writes one RAM byte, drawn from the seeded sequence) and `stop_after` / `FUNC_STOP` (the run
  ends "stop" at the n-th call of a stubbed callee): `main_loop` is checked for one pass, its 16 tasks stubbed, stopping at
  the second `wdt_kick`; a mutation swapping two tasks differs at stub call 5.
- Coverage: `sdr_task` 100 % of 86 blocks (every updater stubbed and setting `sdr_busy_write` one time in eight; was
  52 %), `cat_EM` 100 % of 59 (slot digits, ';', 0xFE end marks; was 66 %), `cat_GT` 91 % of 104 (`vfo_mode` over all 16
  codes, 600 trials; was 68 %), `io_task` 0 inconclusive (meters, GPIO poll, lamps and the save path stubbed; was 137 of
  200), 100 %.
- `beep_task` stubs `tone_set`, so the tone's float bits are compared (a mutation 1046.502 → 1046.5 passed through
  `tone_set`, which only shows the truncated TPU period); `STUB_WIDTHS` for its 16-bit duration.
- The FPU mnemonics are no longer listed as "forms not checked by T22a" (`rx_fpu_check.py` checks them).

### MAIN: recreated (src/main, round 5)

- `app/beep.c`: `beep_task` (the eleven patterns, docs/code/main/peripherals.md); the request / stop / tone functions are
  the UI track's `ui_beep.c`.
- `app/swr_squelch.c`: `swr_meter_protect`, `fm_noise_squelch`, `signal_level_squelch`. Found **[fact]**: the meter is pinned
  only when both readings are <= 10 counts (tx-protection.md said "or"), and SWR = +inf (ρ = 1) is not pinned.
- `app/sdr_link.c`: `sdr_upd_r25_tx_drive` (the band's TX gain row interpolated between the power points).
- `app/display_link.c`: `displink_tx_schedule` (the send priority list) and `displink_rx_F0_hello` (the DISPLAY's version and
  date texts in 0x199F, the boot codes).
- `app/keys.c`: `ladder_key_task`, the remote-keypad dispatch over three action tables.
- `app/main_loop.c`: `main_loop` (a file of its own, so GCC inlines none of the tasks).
- The UI track recreated `meter_vdd`, `meter_po`, `meter_comp`, `meter_s`, `vdd_scale_calc` and the beep request functions in
  parallel; round 5's versions were dropped at the merge.

### MAIN: results (status.tsv, round 5)

`equiv_main_emu.py status --trials 200 --jobs 3` on every object, after merging the UI track (#266), with `GHIDRA_HEADLESS`
on a private Ghidra copy that has `rx62t-fpu-fix.patch` and `rx62t-minmax-fix.patch` (about an hour), then
`status --object app/dsp_link.o --object app/keyer.o` (the first run could not link `dsp_set_peq_freq` and `keyer_task`:
they called `FUN_fffb2dfe`, which the UI track renamed `beep_pattern_get`):

| Verdict | Ghidra functions | Bytes (of 387,059) |
|---|---:|---:|
| identical | 56 | 344 |
| equivalent | 499 | 95,657 |
| differs | 0 | 0 |
| not yet | 3,239 | 291,312 |

**Re-implemented: 24.80 %** (19.98 % after round 4, 23.47 % after the UI track). Round 5 added 9 functions (5,143
bytes): `beep_task` 1,220, `displink_rx_F0_hello` 892, `ladder_key_task` 699, `displink_tx_schedule` 689,
`swr_meter_protect` 557, `sdr_upd_r25_tx_drive` 377, `fm_noise_squelch` 373, `signal_level_squelch` 270, `main_loop` 66.
Every function of rounds 1..4 and of the UI track is still equivalent or identical with the FPU executed by `RxFpu` and
the signed MIN/MAX, among them the MIN users `cat_SS` (88 %), `displink_build_41` (90 %), `keyer_task` (93 %),
`meter_vdd`, `meter_comp` and the float users of the UI track (`meter_po`, `meter_comp`, `meter_s`, `meter_vdd`,
`tone_set`, `funcknob_peak_step`).

### MAIN: Ghidra (round 5)

- `tools/ghidra/names_main.tsv`: 21 RAM labels of round 5 (beep state, the SWR counters, `fm_sql_last_mode`, `dl_hello_req`,
  `dl_hello_text`, `ladder_key_last`, `ladder_delay_armed`, ...), each with its instruction. Proved on a copy of
  `/home/user/ghidra_tasks/t24main/proj` with the UI track's 30 names merged: **ApplyNames 2,905 applied, 0 failed**.
- `tools/ghidra/rx62t-fpu-fix.patch` and `rx62t-minmax-fix.patch`: the tenth and eleventh `bootstrap.sh --only rx` stages
  (`f4688bc6…f403` → `ff99d4e8…cd25` → `8b7bc4f0…bb2c`), checked on a private Ghidra copy and with `RX_MODULE_DIR` on a copy
  of the round-4 module. They change the decompile at the FCMP sites (16 functions) and the S flag after FPU arithmetic (23 functions), nothing else in MAIN (MAIN has
  no MIN, MAX or UTOF), so `decomp/main` should be re-exported after installing them.

Commands for the canonical project (repository root; Ghidra closed):

```sh
export GHIDRA_JAVA_HOME=/usr/lib/jvm/java-21-openjdk-amd64     # the container; on the owner's Mac leave it unset
tools/bootstrap.sh --only rx                                   # rx62t-fpu-fix.patch, rx62t-minmax-fix.patch, sleigh
cp decomp/main/quality.tsv /tmp/quality_main_before.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
  -postScript ApplyNames.java tools/ghidra/names_main.tsv
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript ExportDecomp.java "$PWD/decomp/main" 50 \
  -postScript CatDispatch.java "$PWD/decomp/main/cat_dispatch.tsv" 0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
python3 -I tools/decomp_quality.py compare /tmp/quality_main_before.tsv decomp/main/quality.tsv main
rm -rf /home/user/ghidra_tasks/t24main/proj/FT710_MAIN.rep    # refresh the harness copy
cp -r ghidra/FT710_MAIN.gpr ghidra/FT710_MAIN.rep /home/user/ghidra_tasks/t24main/proj/
python3 -I tools/rx_fpu_check.py module     # with the patches: only the DN / NaN / RM / invalid classes remain
sh tools/rx_semcheck_forms.sh /tmp/semforms # 5,960 / 5,960
python3 -I tools/equiv_main_emu.py status
python3 -I tools/readability_stats.py readme
```

`bootstrap.sh --only rx` changes the shared Ghidra's `rx62t.sinc` hash, so a branch without these patches then refuses to
bootstrap that Ghidra, as with rounds 2 and 4.

### MAIN: blockers and next steps (round 5)

- **CC-RX** is still not obtainable from the container ("MAIN, round 1").
- **The shared Ghidra has neither round-5 patch.** The round-5 status ran with `GHIDRA_HEADLESS` on a private Ghidra copy
  that has both; the FPU results do not depend on them (the engine executes the FPU), the GCC `MIN` results do.
- Not done this round (step 2 of the plan): the remaining CAT handlers (`cat_ext_PE`, `_EO`, `_JP`, the `cat_ai_*` change
  detectors), `key_task`, `dsp_link_poll`, the menu/settings code, the band/VFO/memory logic, `keyer_output_step`,
  `keyer_elekey`; the float users `cat_ai_SQ`, `pa_dac_update`, `align_store_ui8_scaled` and the seven unnamed FPU
  functions 0xFFFEC8A1..0xFFFEDA3B.

## Open steps

1. M33: byte matches for the 34 equivalent functions, which would also put the functions after them at their
   original addresses (`equiv_m33.py layout -v` lists where the spacing breaks; the first is `aic3204_spi_write`).
2. M33: the floating-point path of the printf core, with a preset hook that fills the digit buffer (round 3 above).
3. Apply the round-3 Ghidra changes to the canonical projects with the commands above (M33: the `printf_float_none`
   entry; DISPLAY: the CP15 renames and the four new names), and DISPLAY rounds 4 and 5 with the round-5 command
   block (FixFuncEntries with `entries_display.T24r5.tsv`, ApplyNames), and re-export (T23 rules).
4. DISPLAY, next by size and self-containment (round 7 did read data control, RSPI, DMAC and the SDHI command
   layer): the large SD functions (identify, the init paths, bus speed, the ACMDs), USB, the file system, the MAIN
   link and the update code; then the application (round 8 did the SD card layer, the SD drive and the format code).
   Apply the round-8 Ghidra rows (commands in "DISPLAY: Ghidra (round 8)").
5. DISPLAY build: the hybrid image links and passes linkcheck; before the next round's code goes in, the in-place
   placement and the second region RAM2 of "the gap and the second region" (round 5); a source-only image needs the
   rest of the tree, the NORTi stand-in's port (IRQ entry and exit, the OSTM tick) and a recreated `reset_in_ram`.
   Function addresses that the recreated code stores as data must be the image's entries (round 5: one alias,
   `vdc5_vline_cb_entry`); *Open: a general rule in display_link.py; would be settled by resolving the ABS32 and
   MOVW/MOVT references to linked functions from data stores to their original entries.*
6. HiFi4 (Ghidra p-code): `tools/ghidra/EquivMainEmu.java` is the model (a headless p-code emulator server).
7. MAIN: apply the round-2 Ghidra entries and names (command block in "MAIN: Ghidra (round 2)"), install
   `rx62t-gccforms-fix.patch` (`bootstrap.sh --only rx`), the round-3 names ("MAIN: Ghidra (round 3)") and the
   round-4 names, signature and `rx62t-fpconv-fix.patch` ("MAIN: Ghidra (round 4)"), then the next functions ("MAIN:
   blockers and next steps (round 4)"), and the CC-RX version if the owner can obtain CC-RX ("MAIN, round 1"). Round 5:
   `rx62t-fpu-fix.patch`, `rx62t-minmax-fix.patch` and the 21 names ("MAIN: Ghidra (round 5)"), then "MAIN: blockers and
   next steps (round 5)".

5. DISPLAY build: the hybrid image links in place, into the gap and RAM2 (round 6) and boots in emulation;
   `abicheck` covers calls through a register (round 7). Open: the functions the emulated boot does not reach; a source-only image needs the rest of the tree and the NORTi stand-in's port (IRQ entry and exit, the
   OSTM tick).
6. HiFi4 (Ghidra p-code), MAIN (CC-RX check) after.
