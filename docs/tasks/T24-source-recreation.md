# T24 — Recreate the source code of every image

**Status:** in progress (2026-11-01; IFDSP M33 86.5 % re-implemented, round 2; DISPLAY started) · **Depends on:** T12, T21, T23 · **Issue:** (created by `tools/issues_sync.py`)

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

## Open steps

1. M33 `vsnprintf_core` (2,778 B, 9.8 % of the code): translate 0x84EB0..0x85989 (flags, `*` width/precision, length
   modifiers l ll L q h hh j z t, conversions a c d e f g i n o p s u x X, 64-bit values through `__aeabi_uldivmod`, the
   hook for floating point) and check it with the printf-like inputs the harness now draws.
2. M33 `console_rx_char` (1,058 B): the recreated one faults where the original returns (trial 0 of the harness: a
   store at `s_line[s_lineLen]` with the random `.bss` length); needs a console-state preset (line length < 128, flags
   0/1) and then the remaining differences of the line editor and both command modes.
3. M33 remaining layout differences: sizes of the non-identical functions; `console_cmd_d`/`console_cmd_w` order.
4. Apply the Ghidra corrections to the canonical project with the commands above and re-export (T23 rules), then add
   0x872F4 (`printf_float_none`, the hook) to `entries_m33.tsv` (not a Ghidra function yet).
5. DISPLAY: port the relocation and stub machinery to the A32 harness; NORTi service calls as stubs; then the
   library functions (strcpy, strlen, memcpy, crc*) and the drivers. HiFi4 (Ghidra p-code), MAIN (CC-RX check) after.
