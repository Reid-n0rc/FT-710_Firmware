# T21 — Close the Ghidra decompile gaps (issue #97)

**Status:** in progress · **Depends on:** T05, T07, T11, T12e, T17, T20 · **Issue:** [#97](https://github.com/Reid-n0rc/FT-710_Firmware/issues/97)

## Goal
Close every known gap in the Ghidra decompiles listed in #97, so `decomp/` is decompiled C that can be trusted. Part A (HiFi4 FLIX
bundles, a SLEIGH generator from Cadence's MIT-licensed `xtensa-modules.c`) is the main work; part B covers the smaller MAIN and
DISPLAY gaps (B1–B8) and a regression check for all images (B11). Analysis and tooling only; no radio.

## Plan
Owner: parent agent, branch `issue-97-ghidra-gaps`, 2026-10-28. Work is split into sub-tasks that run in parallel, each in its own
worktree, each committing after every step:

| Sub-task | Items in #97 | Deliverable |
|---|---|---|
| T21a | A steps 1–6, 9 | `tools/xtensa_sleigh_gen.py` and the generated language `Xtensa:LE:32:rt600hifi4` (SLEIGH + ldefs/pspec/cspec), installed by `tools/bootstrap.sh` |
| T21b | A step 7, B9, B10 | the test oracle: a Ghidra listing export plus `tools/flix_compare.py` against `flix.dis` (all 49,389 instructions); function list matched to `flix.dis` |
| T21c | B1, B4 | RXv2 coverage diff against GNU binutils `rx-elf-objdump`; SLEIGH patch for any missing RXv2 op and for the string ops as named pcodeops |
| T21d | B2, B3, B5 | MAIN: spacebase fixes, call-argument/return mismatch counter and `signatures_main.tsv` + script, string/pointer-table definition |
| T21e | B6, B7, B8 | DISPLAY: jump-table recovery, missed function starts, undefined fragments |
| T21f | B11 | decompile-quality counts per image in `INDEX.md`; `tools/bootstrap.sh verify` fails if any count gets worse |
| T21g | A step 8, integration | canonical Ghidra projects re-imported with all fixes, `decomp/` re-exported, docs (`INDEX.md`, `hifi4.md`, `ghidra-flix.md`, `tooling.md`) updated |

Rules for the sub-tasks:
- Work on per-task Ghidra copies (`ghidra/FT710_<IMAGE>_T21x`, gitignored). Only T21g writes the canonical projects and re-exports
  `decomp/`, so the binary projects never conflict.
- Inputs come from the main checkout's `build/` (read only).
- Ghidra runs go through a slot limiter (at most 3 at once, 3 GB heap each) so the 15 GB machine does not run out of memory.
- Every step: commit, heartbeat, and record findings in this file's sub-task section and in `docs/`.

## Sub-task status
(filled in by each sub-task)

### T21f
**Status:** done (2026-10-28). Item B11.
- `tools/ghidra/ExportDecomp.java` writes `<outdir>/quality.tsv` (`metric<TAB>value`) from the same decompile pass as the `.c` files:
  functions, decompile failures, warnings (total, functions with one, and one `warning:<kind>` row per kind with addresses/numbers
  replaced by `#`; `spacebase_warnings` and `unreachable_block_warnings` pulled out), `halt_baddata()` calls and functions, functions with
  `in_*` / `unaff_*` / `extraout_*` variables and with any of them, undefined non-0xFF bytes in initialized executable blocks (total and
  `undefined_nonff_bytes:<block>`), Error and "Bad Instruction" bookmarks. The `.c` and `functions.tsv` output is unchanged.
- `tools/decomp_quality.py` (stdlib): `compare old new [label]` (exit 1 if any count except `functions` went up; a missing row is 0)
  and `index INDEX.md LABEL=quality.tsv ...` (table between `<!-- quality:begin -->` / `<!-- quality:end -->`).
- `tools/bootstrap.sh verify`: `quality.tsv` is left out of the byte diff (`diff -x quality.tsv`, and a `:(exclude)` pathspec for the
  in-place `git diff`); each image's fresh `quality.tsv` is compared with the committed one (from `HEAD` when exporting in place).
  Fails if any count got worse; better counts are printed. The `export` step also prints the warning total.
- **Test** [fact]: all four programs exported with the new script from copies of the canonical projects (`-readOnly`, into scratch);
  `diff -r` against `decomp/` is identical for every `.c` and `functions.tsv` (MAIN's `cat_dispatch.tsv` was not part of that run).
  `bootstrap.sh --only verify` passes against that export, and fails when one count is raised (spacebase 8 → 9), both with
  `DECOMP_OUT` in scratch and in place.
- **Baselines** committed in `decomp/{main,display,ifdsp/m33,ifdsp/hifi4}/quality.tsv` and rendered into the three `INDEX.md`. They are
  the state **before** T21a–e; T21g regenerates them after the re-export.

| Metric | MAIN | DISPLAY | M33 | HiFi4 |
|---|---:|---:|---:|---:|
| functions | 2,268 | 2,087 | 426 | 1,148 |
| decompile failures | 0 | 0 | 0 | 1 |
| warnings (functions with one) | 1,294 (347) | 347 (89) | 181 (93) | 2,038 (861) |
| "Unable to track spacebase" | 8 | 0 | 0 | 0 |
| "Removing unreachable block" | 1,226 | 224 | 37 | 47 |
| `halt_baddata()` (functions) | 0 | 4 (4) | 1 (1) | 1,054 (819) |
| functions with `in_`/`unaff_`/`extraout_` | 61 | 170 | 25 | 317 |
| undefined non-0xFF bytes, executable blocks | 20,622 | 4,258 | 5,162 | 186,167 |
| "Bad Instruction" bookmarks | 1 | 1 | 1 | 1,098 |

- These match the documented numbers: MAIN 2268 functions, 0 failures, 8 spacebase and 1226 unreachable-block warnings, about 20 KB
  undefined non-0xFF bytes; DISPLAY 2087 / 0; M33 426 / 0; HiFi4 1148 functions, 1 failure (`FUN_0020bb74`). Two documented figures are
  measured differently: DISPLAY's "about 2.7 KB of small unreferenced fragments" (T06) is fragment size, here every non-0xFF byte of
  `.text` not covered by code or data counts (4,258); HiFi4's "955 functions hit FLIX bundles or bad data" (T07) is from the T07
  export; today 819 functions have a bad-instruction warning / `halt_baddata()`.
- Not new gaps, but now visible: MAIN has 1 "Bad Instruction" bookmark and 3 "Unimplemented instruction" warnings (relevant to T21c, B1),
  and 16 "Ignoring partial resolution of indirect"; DISPLAY 50 "may not be properly labeled as switch case" and 17 unrecovered jump tables
  (T21e, B6).
- Leftover: when a fix makes a count go up on purpose (e.g. T21e finds more functions, so more warnings), the committer must commit the
  new `quality.tsv`; verify cannot tell that apart from a regression.

### T21d
Branch `worktree-agent-a1563dabd320e565e` (off `issue-97-ghidra-gaps`), scratch project `<scratchpad>/t21d/ghidra/FT710_MAIN_T21d` (copy of the canonical one).

**B2 (spacebase): cause found, fixed in SLEIGH.** [fact] All 8 functions end in `RTSD #imm,Rd-Rd2` (`displink_build_60` 0xFFF96241,
`cat_SP_meters` 0xFFFA5284, `eeprom_read` 0xFFFB14A4, `menu_page_serialize` 0xFFFC98F9, `FUN_fffedd9a`, `FUN_fffeddc9`, `FUN_fffedf24`,
`FUN_fffedfa7`). The module's RTSD form (2) computes `n_regs = reg0_4 - reg4_4 + 1` from the register *values* (R7 − R6 + 1), not the
register numbers, so SP after the frame release depends on data and the decompiler loses the stack. Fix: `n_regs = rs2 - rs1 + 1`
(`tools/ghidra/rx62t-rtsd-fix.patch`, one line, applies on top of the T17 patch with `patch -p1` in the RX module dir). Tested in a private
Ghidra copy (not the shared install): full MAIN export, spacebase warnings 8 → 0, no other line of the C changes. **For T21c/T21g:** fold this
into the RX step of `tools/bootstrap.sh` together with T21c's patch (the step checks the patched `rx62t.sinc` SHA-256, so the two patches
must be applied in one place); T21d does not edit that step.

**Measurement setup.** T21c patched the shared RX module in place on 2026-10-28 11:20 (sinc SHA-256 `9eadf83b…6a11`), so every number
below comes from a private Ghidra copy (`~/opt/t21d-ghidra-tmp`, hard links to the shared install with its own RX module: T21c's
`rx62t.sinc` + `rx62t-rtsd-fix.patch`, SHA-256 `618938bb…4b36`), on a copy of the canonical project, exported to scratch. "Base" is that
SLEIGH without signatures.

**B3 (dropped arguments / lost returns): counter, signatures, fixed.**
- `tools/ghidra/CallArgCheck.java <mismatch.tsv> [<protos.tsv>]` (read-only). For each of the 6,010 direct call sites it compares the
  disassembly with the CALL op in the caller's decompile. Disassembly view [inference: heuristic]: arguments = R1..R4 written in the
  call's basic block and not read again before the call (string instructions excluded, their R1–R3 outputs are side effects; PUSHM/POPM/
  RTSD use their register range, not Ghidra's input objects, which name every register); `dropped_arg` also needs the callee to read
  the missing register at its entry (block liveness). Return = R1 read before written in up to 8 fall-through instructions after the
  call. `protos.tsv` has, per function, the live-in registers with the first spill size, how many sites read R1/R2 and with what size,
  the decompiler's prototype, the entry instruction, and the -O0 return idiom before each RTS/RTSD.
- Counts [fact]:

| | canonical project (T17 SLEIGH) | base (T21c + RTSD SLEIGH) | with `signatures_main.tsv` |
|---|---:|---:|---:|
| dropped arguments (callees) | 130 (36) | 116 (35) | **0** (0) |
| lost returns (callees) | 65 (28) | 91 (29) | 42 (8), all at callees with a signature |
| 64-bit return candidates | 1 | 1 | 0 (`FUN_fffede41` gets `uint64`, a runtime helper) |
| `quality.tsv`: functions with `in_`/`unaff_`/`extraout_` | 61 | 23 | **6** |
| `quality.tsv`: warnings (functions) | 1,294 (347) | 1,217 (341) | 1,226 (350) |

  The 9 extra warnings are "Removing unreachable block" in byte-parameter setters (`gpo_a_set`, `hex2word`, …) whose parameter is now
  known to be a byte. The base column has more lost returns because T21c's string pcodeops make some results dead (next point).
- The 42 left are not missing signatures [fact, read in the listings]: 16 are results the source stores into a local that is never read
  again (`cat_AC` 0xFFFA65E1 `MOV.L R1,0x8[SP]` after `vfo_rec_ptr`, `ptt_arbiter` 0xFFFB8707 after `vfo_mode`, …), 26 are
  **a regression from T21c's B4 change**: a value stored into a stack buffer that a string instruction then copies is dropped, because
  the `smovf()` pcodeop has no memory effect for the decompiler. Example `FUN_fffdebd1` 0xFFFDEC12: `nib2hex()` result goes into
  `local_6[2]` and `SMOVF` copies the reply to 0x15E06; the C now shows `builtin_strncpy(local_6,"CS0;",4); nib2hex(DAT_00020f0b);
  smovf(...)` with the digit lost (all 24 `nib2hex` sites in the AI reply builders 0xFFFDEBD1..0xFFFE1774, and the 16-byte limits block in
  `ex_read_or_write` → `in_stack_ffffffcc`). **For T21c/T21g:** give the pcodeops a memory effect (e.g. keep the T17 copy loop for
  SMOVF/SMOVB/SSTR and use pcodeops only for the compare/search ops, or copy through a `*[ram]` loop after the call), then re-run
  `CallArgCheck.java`: the 26 should go away.
- `tools/ghidra/signatures_main.tsv`: 1,212 rows = every named function in `names_main.tsv` (1,121) + 91 unnamed `FUN_` callees/callers
  listed by the baseline mismatch file. 33 rows are `doc` (checked against the listing and `docs/code/main/`): `eeprom_read/write/
  read_raw/spi_tx/spi_rx`, `vfo_freq`, `vfo_freq_clar`, `vfo_rec_ptr`, `vfo_mode`, `tx_freq_allowed`, `dest_code_get`, `band_of_freq`,
  `freq_range_index`, `gen_subband_of_freq` (the #103 path), the hex helpers, `menu_*`, and the `ex_*` EX parser with CC-RX's packed stack
  arguments (`ex_parse_byte`: byte at SP+4, byte at SP+5, word at SP+6; `ex_read_value`/`ex_write_value`: a 16-byte limits block by
  value at SP+4). The rest are `asm` rows drafted by `tools/signatures_draft.py` from `protos.tsv` (rules in its docstring: entry
  liveness and spill size for parameters; the `MOVU.B/W|MOV.x dsp[SP],R1` or `MOV.x R1,dsp[SP]` return idiom, else callers' use of R1, for
  the return; interrupt handlers `void(void)`). Drafted parameters are unnamed (`param_N`), so no made-up name spreads into callers.
- `tools/ghidra/ApplySignatures.java <tsv>`: sets each prototype with `SourceType.USER_DEFINED` and the cspec's `__fastcall`
  (without a named convention every function got "Unknown calling convention -- yet parameter storage is locked"), dynamic storage
  except for `@stack:N` parameters or a 64-bit return (custom storage, return R2:R1), and stack purge 0 (CC-RX callers pop their stack
  arguments; with the purge left unknown, callers of custom-storage functions lost track of SP: `unaff_R6` in `ex_write_value`).
  Locked prototypes are not overridden by the decompiler's parameter ID (B3 step 3).
- Test [fact]: `eeprom_read` → `void eeprom_read(ushort addr,byte *buf,ushort n)` with `eeprom_spi_tx(3); eeprom_spi_tx((byte)(addr >> 8));
  eeprom_spi_tx((byte)addr)`; `vfo_freq` → `uint vfo_freq(byte which,byte side)` that builds and returns the big-endian u32 (it
  decompiled as `void` with an empty loop); `tx_freq_allowed` → `bool tx_freq_allowed(uint freq)`; float arguments now show
  (`tone_set(880.0,100)`); 0 decompile failures.
- Regenerate: run `CallArgCheck.java` on a project **without** signatures for `protos.tsv`/`mismatch.tsv`, then
  `python3 -I tools/signatures_draft.py protos.tsv tools/ghidra/names_main.tsv tools/ghidra/signatures_main.tsv mismatch.tsv` (keeps the
  `doc` rows), then `ApplySignatures.java`.

**B5 (undefined ROM bytes): `tools/ghidra/DefineRomData.java [report.tsv] [code=0xFFF8F658] [dry]`, run after ApplyNames.**
- Steps: strings (≥ 3 printable ASCII + NUL), runs of ≥ 2 aligned pointers into ROM (instruction/data starts) or ≥ 4 into labelled or
  referenced RAM/IO, runs of ≥ 4 NUL bytes → `byte[n]`; repeated until nothing new. In the code area (from `main` 0xFFF8F658) every
  undefined run after an instruction is disassembled inside the run; a clean flow that reaches RTS/RTSD/RTE becomes a function
  (unreferenced CC-RX functions: 54, mostly after a `RTS` in the BSP/driver code, e.g. 0xFFF92475, 0xFFFC9654, 0xFFFEE1BE); a flow
  with a bad instruction is cleared again with its bookmarks. What is left in the const area (0xFFF80000..0xFFF8F657) are numeric tables
  that no decoded code reads directly: `float[n]` if ≥ 90 % of the words are 0 or normal floats, `uint16[n]` if ≥ 80 % of the
  half-words have a zero high byte, else `byte[n]`, each with a plate comment that the layout is a guess **[guess for the layouts]**.
- Test [fact, full re-import with the recipe into scratch, T21c + RTSD SLEIGH, then ApplySignatures and ExportDecomp]:

| | before | after |
|---|---:|---:|
| undefined non-0xFF bytes (ROM) | 20,622 | **161** in 2 runs |
| defined strings | 63 | **161** (98 new, 3,077 B) |
| pointers / zero runs / const tables | – | 8 (32 B) / 130 (2,328 B) / 221 (11,586 B) |
| functions | 2,268 | 2,322 (54 unreferenced functions, 3,657 B) |
| decompile failures, error bookmarks | 0, 1 | 0, 1 |

- The 161 B left are code the RX module cannot decode **(for T21c, B1)**: 0xFFF8FEF3 `FE D1 55 …` inside an `R_BSP_InterruptControl`
  caller at 0xFFF8FEC0 (2 references; expected a `MOV.W [R1,R5],R5`-type `[Ri,Rb]` form), and 0xFFF9129B `FD 1F 02 …` after
  `PUSH.L R2` at 0xFFF91295, which looks like the RXv2 accumulator save `MVFACHI/MVFACMI` of an interrupt prologue **[inference]**.

**Combined result (B2 + B3 + B5, full re-import, `quality.tsv` against the committed baseline):** spacebase 8 → 0, functions with
`in_`/`unaff_`/`extraout_` 61 → 8, undefined non-0xFF bytes 20,622 → 161, warnings 1,294 → 1,229, 0 decompile failures; functions
2,268 → 2,322. `functions_with_warnings` goes 347 → 352 ("Removing unreachable block" in byte-parameter setters and in the new
functions), so the committer of the re-export (T21g) must commit the new `quality.tsv` (see T21f's leftover).

**Status:** done (2026-10-28). Commits on `worktree-agent-a1563dabd320e565e`. `tools/bootstrap.sh` MAIN step: ApplyNames →
DefineRomData → ApplySignatures (stamped on the three new inputs); `docs/tooling.md` "MAIN full rebuild" and `decomp/main/INDEX.md`
list the order. `decomp/` not re-exported (T21g).

**Leftovers / follow-ups:**
- T21c/T21g: add `rx62t-rtsd-fix.patch` to the RX step and update `RX_SINC_FIXED`; give the string pcodeops a memory effect (26 lost
  values, above); decode the two fragments above.
- 2 dropped arguments remain at 2 of the 54 new functions (no signature; redraft `signatures_main.tsv` from a project that has them).
- 16 "lost returns" are dead stores in the source and cannot be fixed by a signature; `CallArgCheck` cannot tell them apart.
- The 1,179 `asm` signatures are drafted, not reviewed: pointer vs integer parameters come from the decompiler's own guess when the
  size matches, and names are `param_N`. Review more of them by subsystem and mark them `doc`.
- Const tables are typed by a simple test; their real layout comes with the code that reads them (most are reached through computed
  addresses, e.g. the band and filter tables in the subsystem pages).

## Findings

## Follow-ups
