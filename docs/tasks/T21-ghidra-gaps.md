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

### T21c
**Status: done (2026-10-28).** B1 and B4 for MAIN. Details, tables and commands: `docs/tooling.md` → "RXv2 coverage check and
second SLEIGH fix (T21c)".
- Reference: GNU binutils 2.47 built for `rx-elf` (`~/opt/rx-binutils-2.47`, signature checked), which decodes RXv2 and RXv3.
- Tools: `tools/ghidra/ListingExport.java` (instruction TSV + Error bookmarks), `tools/rx_compare.py` (per-instruction diff,
  normalisation rules N1–N10).
- **B1 count [fact]:** 129,938 instructions compared; before 57 different (all `MUL dsp[Rs].UB,Rd`, a module bug, not an RXv2
  gap), 0 missing, 0 undecodable, 0 undefined holes; after the patch **0 differences** (129,936 instructions, `--all`).
  The firmware uses no RXv2-only instruction that the module lacks: the only RXv2-only one is `FTOU` (12 sites, correct).
  No EMACA or other DSP op occurs. The one "Bad Instruction" bookmark (0xFFF88FE5) is data in the constant area (B5).
- **Semantic bugs found while checking the C [fact]**, also fixed: `XCHG [Rs].L,Rd` was `unimpl` (3 functions were
  `halt_unimplemented()`); `SCCnd` skipped the store when false and `SCCnd.L Rd` stored through [Rd] (56 sites, e.g. every
  `SCMPU` result test).
- **B4 [fact]:** SMOVF 689 uses (634 in functions), SSTR.B 21, SUNTIL.B 6, SCMPU 6; SMOVB/SMOVU/SWHILE unused. All seven
  are named pcodeops now; `cat_parse` shows `scmpu(&uStack_d,&cat_mnemonics + (uint)bStack_e * 2,2)`.
- Patch `tools/ghidra/rx62t-rxv2-fix.patch` (on top of the T17 patch), applied by `tools/bootstrap.sh --only rx`
  (`RX_SINC_FIXED` = `9eadf83b…`). **Installed** in `~/opt/ghidra_12.1.4_PUBLIC/Ghidra/Processors/RX/` (backups `rx62t.sinc.t17`,
  `rx62t.sla.t17`).
- C diff (fresh imports, old vs new module): 586 of 2268 functions changed, 570 contain a patched instruction, 16 only
  changed types/global names that propagate from those. 0 decompile failures; `quality.tsv`: warnings 1294 → 1218,
  unimplemented 3 → 0; `extraout_` 14 → 17 functions and undefined non-0xFF bytes +66 (64 one-byte placeholders the old
  loops created) got worse, both explained in `docs/tooling.md`. **`tools/decomp_quality.py compare` will flag those two
  counts when T21g re-exports; the new numbers are the baseline.**
- For T21g: re-import MAIN with the installed module, re-export `decomp/main`, and update the "Known decompiler artifacts"
  in `decomp/main/INDEX.md` (string ops are calls now; MUL .UB, XCHG and SCCnd fixed).
- Leftovers: `UTOF` memory .UB form and `SATR` are still broken/`unimpl` in the module (unused by MAIN). The SUNTIL
  `strlen` idiom decompiles as `-(-(p + 0x70cb0) - 1U & 0xff)` (correct, not pretty). Only the listing was checked
  against objdump; other p-code semantics were not audited systematically.

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
### T21a
**Status:** done (A steps 1–6 and 9). Branch `worktree-agent-ac317c7805449506f`. Language `Xtensa:LE:32:rt600hifi4`, generated by
`tools/xtensa_sleigh_gen.py` (+ probe `tools/xtensa_isa_dump.c`) from Cadence's `xtensa-modules.c` (sdk-ng `15daabb`, SHA-256
`9e218b19…f372`), committed in `tools/ghidra/xtensa-rt600hifi4/`, installed by `tools/bootstrap.sh --only hifi4` and installed in
`~/opt/ghidra_12.1.4_PUBLIC` (stock `Xtensa:LE:32:default` unchanged). Details: [ghidra-flix.md](../code/ifdsp/ghidra-flix.md),
"The SLEIGH language".

**Plan (as done).** (1) Probe the libisa tables and functions in C, rebuild the decoder in Python and prove it on `flix.dis` (the
generator's own reference disassembler matches objdump on all 49,389 instructions). (2) Emit one 48-bit and one 88-bit token, a
sub-table per slot with one constructor per decode entry, operand sub-tables from the probed bit maps and fitted decoders, and bundle
constructors from `format_decoder`'s bit tests. (3) Keep the stock 24/16-bit constructors where they are right for this core,
generate the rest. (4) Semantics: hand p-code for the base-ISA/FPU ops, real memory access for the simple HiFi4 loads/stores, named
p-code ops with iclass in/out for the rest. (5) Bundle parallelism through staging registers and per-slot commit sub-tables.
(6) Bootstrap step `hifi4`.

**Results [fact].**
- T21b oracle, decode mode: **49,389 / 49,389 = 100 %** (bundles 12,676 / 12,676; mnemonic, operands and length). Listing mode
  95.8 %, every mismatch an unreachable `flix.dis` sweep artefact. Functions 1,067 = reference. B9: `FUN_0020bb74` decompiles.
- Full HiFi4 decompile on a scratch project vs the committed (stock-language) `quality.tsv`: failures 1 → 0, `halt_baddata`
  1,054 → 1 (`FUN_00218480`, data that objdump cannot decode either), bad-instruction bookmarks 1,098 → 1, warnings 2,038 → 258.
- Open questions answered: SLEIGH tokens may be wider than 64 bits (88-bit token works in sleigh and Ghidra); `local` temporaries
  do not cross sub-constructors, so parallel slots use global staging registers and a commit sub-table per slot, built after all
  compute parts; the decompiler handles the 2,090 named p-code ops without trouble (full export in about two minutes).
- Stock SLEIGH bugs found on the way (dropped and regenerated for this language; also present in `Xtensa:LE:32:default`): `movi.n`
  negative values, `bany`/`bnone`/`ball`/`bnall` operand order, `remu`/`rems` trailing comma, `bgeui`/`bltui` constant 0x1000
  for 0x10000, `ret` shadowing `jx a0`, `mula.da.*.ldinc` on the `mula.dd.*.ldinc` encodings, `licw` shadowing `rems`, `mul.dd.lh`
  shadowing `ae_pksr24`, missing `ret.n` encoding.

**Left / follow-ups.** T21g: switch `build_ifdsp` (bootstrap) and the canonical `FT710_IFDSP` HiFi4 program to
`Xtensa:LE:32:rt600hifi4` (with `--only hifi4` before `ghidra`) and re-export `decomp/ifdsp/hifi4`. Later, per need: exact
arithmetic for the filter kernels' `ae_*` ops, memory semantics for the aligning `ae_la*`/`ae_sa*` loads/stores, the FPU lane
layout (now a guess: low 32 bits).

### T21b
**Status:** done. The oracle, B10 and B9 are checked on the stock language and on T21a's first `Xtensa:LE:32:rt600hifi4` (installed
2026-10-28 11:27). B9 is fixed on that language and B10 matches. The oracle is not yet at 100 % (see "On T21a's language").
Branch `worktree-agent-a3cf9ef23f5240768`.

**Plan.** (1) `ExportListing.java` exports instructions, either the analysed listing or a flow-independent decode at every
`flix.dis` address; `tools/flix_compare.py` compares that export with `flix.dis`, and `tools/flix_oracle.sh <language-id>` runs
the whole thing end to end. (2) B10: diff the function lists, classify the differences, and make `IfdspHifi4FindFuncs.java` use a
committed reference list. (3) B9: find the instruction that kills the decompile of `FUN_0020bb74` (`DecompileBisect.java`).
(4) Re-run everything on T21a's language once it is installed.

**Oracle (A step 7).** The reference is every instruction line of `flix.dis`: 49,389 instructions (12,676 bundles) in 1,065
functions. The 461 `.byte` lines are not compared. An instruction matches when it has the same address, length, mnemonic and
operands, slot by slot for bundles. The normalisation rules N1–N8 are listed in the docstring of `flix_compare.py`, and each one
is counted in `summary.txt`:
- N1: case and spacing.
- N2: integers compared by value, so hex and decimal spellings match.
- N3: integers compared modulo 2^32.
- N4: the `(literal)` that objdump appends to `l32r` is dropped.
- N5: the call-name comments are dropped.
- N6: bundles are parsed as `{a; b}`.
- N7: `rsr.X a` is the same as `rsr a, X`.
- N8: `or a,b,b` is the same as `mov a,b`.

Register names, suffixes, signs and operand order are not normalised. Baseline on the stock `Xtensa:LE:32:default` **[fact: run
2026-10-28]**:

| Export | Match | Bundles | Non-bundle | Functions fully matching | Mismatches |
|---|---|---|---|---|---|
| listing (after setup, FindFuncs, Names) | **7,034 / 49,389 = 14.24 %** | 0 / 12,676 | 7,034 / 36,713 (19.2 %) | 114 / 1,065 | 40,935 no instruction at the address, 1,323 length, 96 operands, 1 mnemonic; 2,525 Ghidra instructions decoded from the middle of a reference instruction |
| decode (flow-independent) | **32,581 / 49,389 = 65.97 %** | 0 | 32,581 / 36,713 (88.7 %) | 156 / 1,065 | 10,438 length (every 6-byte bundle decoded as the 3-byte `FLIX` placeholder), 4,648 decode errors (the 11-byte bundles and unknown ops), 1,714 operands, 8 mnemonic |

Mismatches on the base ISA that the stock language also gets wrong **[fact: `mismatches.tsv`]**:
- The FPU ops (`mul.s`, `add.s`, `sub.s`, `wfr`, `olt.s`, `madd.s`, …) use `f0..f15` instead of `aed0..15`. Some of them also have
  their operands in a different order: `add.s f0,f0,f1` against `add.s aed0, aed1, aed0`.
- `bany`, `bnone`, `ball` and `bnall` print the target first and add a trailing comma, and `remu` also adds a trailing comma.
- `movi.n` prints negative values as 8-bit unsigned (`0xfd` for `-3`).
- `jx a0` prints as `ret`.
- `rsr` on SR 226 prints as `INTSET`, where objdump has `interrupt`.

The latest outputs for T21a are in the session scratchpad `oracle/` (`<lang>/{listing,decode}/{summary.txt,by_mnemonic.tsv,mismatches.tsv}`).

**B10: function list.** Ghidra's 1,148 entries (`decomp/ifdsp/hifi4/functions.tsv`) against the 1,065 functions of `flix.dis`
give 84 extra and 1 missing **[fact]**:

| Class | Count | Verdict |
|---|---|---|
| ITCM vectors (`_Window*`, `_Vector_*`, `FUN_24020044`) | 13 | real code outside the SRAM range that `flix.dis` covers; seeded by `IfdspHifi4Setup.java`, kept |
| in rodata/literals (0x200000–0x207cf0) | 15 | data, reached through call targets of mis-decoded bundles |
| inside a 6- or 11-byte bundle | 22 | mid-bundle artefacts of the 3-byte `FLIX` placeholder |
| inside an ordinary instruction | 15 | the same desynchronisation after a bundle |
| in padding | 1 | artefact |
| at an instruction boundary inside a `flix.dis` function | 18 | 16 are branch targets or mid-function code that became call targets through mis-decoded `call`s. The other 2 are **real entries without an `entry` instruction**: 0x2332C4 (a `call0` target from 0x228AA1, 0x228D18 and 0x2333F7 that reads WINDOWBASE/WINDOWSTART, so a window-spill helper) and 0x2354E0 (its address is stored at DTCM 0x24000004 and it saves a0 in EXCSAVE4, so a level-4 interrupt handler) **[fact: flix.dis, image bytes; inference: roles]** |
| missing: 0x21F320 | 1 | a real `entry` function (a call target that `ifdsp_hifi4_dis.py` found); Ghidra had swallowed it into a mis-decoded instruction |

`tools/ghidra/entries_hifi4.tsv` (generated by `flix_compare.py entries`) holds the 1,065 `flix.dis` entries plus those 2 extras.
The new `IfdspHifi4FindFuncs.java` creates each entry, first clearing any instruction that overlaps it, and removes every other
function outside the ITCM. Test (`flix_compare.py funcs`, run from `flix_oracle.sh`) on the stock language: **1,067 SRAM functions
= reference, 0 extra, 0 missing**, plus 15 functions in the TCM. `IfdspHifi4Names.java` adds none. `bootstrap.sh` now stamps the
HiFi4 step on `entries_hifi4.tsv`. The reference was built from Ghidra's own list (`ifdsp_hifi4_dis.py` reads `functions.tsv`).
Rebuilding `flix.dis` from the new list should give the same file, because that script drops entries without `entry` (the 2 extras) **[inference]**.

**B9: `FUN_0020bb74`.** On the stock language the decompiler process dies; the headless log shows only "Unable to resolve
constructor" warnings at 0x20BC08, 0x20BC0A and 0x20BC2C. Clearing the listing does not help, because the decompiler re-decodes
undefined bytes itself. So `DecompileBisect.java` patches the bytes instead. With `retw.n` written over 0x20BC2A the decompiler
still dies, and with `retw.n` over 0x20BC28 it succeeds. Writing a `nop.n` over 0x20BC28 alone, with the original bytes restored,
also makes it succeed. The culprit is Ghidra's `s32i.n a1,a12,0x34` at **0x20BC28**. In `flix.dis` that address is the middle
(bytes 3–4) of the 6-byte bundle `{ slli a15, a15, 4; and a13, a13, a9 }` at 0x20BC25 **[fact]**. The crash therefore comes from
the misaligned FLIX decode **[inference]**. On `rt600hifi4` the function decompiles: `void FUN_0020bb74(uint *param_1,int
param_2)`, with no `halt_baddata` **[fact: run 2026-10-28]**.

**On T21a's language (`Xtensa:LE:32:rt600hifi4`, first install, 2026-10-28 11:27)** **[fact: `flix_oracle.sh` run]**:

| Export | Match | Bundles | Functions fully matching | Mismatches |
|---|---|---|---|---|
| decode | **48,650 / 49,389 = 98.50 %** | 12,471 / 12,676 | 871 / 1,065 | 730 operands, 8 mnemonic, 1 error |
| listing | **46,623 / 49,389 = 94.40 %** | 12,427 / 12,676 | 545 / 1,065 | 2,077 no instruction (1,416 of them within 8 bytes of a `flix.dis` `.byte`/`ill`), 688 operands, 1 mnemonic |
| functions | 1,067 SRAM functions = reference, 0 extra, 0 missing (16 in the TCM) | | | |

The 739 decode mismatches have two causes; the list went to T21a in the scratchpad `oracle/FEEDBACK_T21a.txt`.
- **BR view register names (459 rows, including all 205 bundle mismatches).** objdump names the BR2/4/8 views after the bits they
  cover (`b2:b3`, `b0:b1:b2:b3`, `b8:…:b15`), while Ghidra prints `b2`. At least `any8` also maps to the wrong register: it prints
  `b14` for `b8:…:b15`.
- **Bugs inherited from the stock base-ISA SLEIGH:**
  - `movi.n` with a negative immediate is printed 8-bit unsigned (89 rows).
  - `bnone`/`bany`/`ball`/`bnall` print the target first and add a trailing comma (136 rows).
  - `remu`/`rems` add a trailing comma (48 rows).
  - The `b4constu` table has 0x1000 where it should have 0x10000 (`bgeui`, 4 rows; a value bug).
  - `jx a0` prints as `ret` (1 row).
  - `rems` is shadowed by `licw` (6 rows).
  - `ae_pksr24` is shadowed by MAC16 `mul.dd.lh` (1 row).
  - `ret.n` with bytes `0d fc` does not decode (1 row).

**Limit of the reference.** `flix.dis` sweeps each function linearly from its entry to the next one. It therefore decodes padding
and unreachable bytes, and after padding it can stay out of sync for a few instructions. At 0x207F9E–0x207FA4 objdump shows
`sub`/`remu`/`add.n`, while Ghidra's flow decode has two padding bytes and then `memw` at 0x207FA0, which is right **[fact]**. So
the listing mode cannot reach 100 % against `flix.dis`: 1,075 of the "no instruction" rows are bytes that flow never reaches, and
1,002 are conflicts, most of them next to padding. The decode mode, which decodes the same bytes objdump did, is the decoder test.
The listing-mode target should be "no mismatch except sweep artefacts". That needs an adjudication step, for example running
objdump at Ghidra's instruction starts in the conflict regions (a follow-up).

**Commits:** `77cf14b` oracle tools; `a6488de` B10 reference list and FindFuncs, B9 bisect, stock baseline; then the rt600hifi4
results and the padding annotation.

**Leftovers:**
1. Re-run `tools/flix_oracle.sh Xtensa:LE:32:rt600hifi4` after T21a fixes the items above.
2. Listing-mode adjudication of the 337 conflict regions.
3. T21g: re-export `decomp/ifdsp/hifi4` with the new `IfdspHifi4FindFuncs.java`. The expected count is 1,067 SRAM functions plus
   the TCM vectors, against 1,148 today, and 0 decompile failures if `FUN_0020bb74` stays fixed.

## Findings

## Follow-ups
