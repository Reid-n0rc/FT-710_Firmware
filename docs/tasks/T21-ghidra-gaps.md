# T21 — Close the Ghidra decompile gaps (issue #97)

**Status:** done (2026-10-28) · **Depends on:** T05, T07, T11, T12e, T17, T20 · **Issue:** [#97](https://github.com/Reid-n0rc/FT-710_Firmware/issues/97)

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

### T21e
**Status: done (2026-10-28).** Items B6, B7, B8 for DISPLAY. Scratch projects only; `decomp/display` is not re-exported (T21g).
All numbers below are from a fresh rebuild with the new `tools/bootstrap.sh` DISPLAY steps (import → DisplayFindCode ×2 →
FixFuncEntries → DisplayJumpTables apply → DisplayGaps define → ApplyNames → ExportDecomp into scratch). It matches the
incremental run on a copy of the canonical project byte for byte.

| Count (DISPLAY) | before (committed) | after T21e |
|---|---:|---:|
| ARM jump-table sites (`ldr pc,[pc,rX,lsl #2]` / `add pc,pc,rX,lsl #2`) | 85 found (80 + 5) | 86 (81 + 5; one sat in missed code) |
| … that decompile to a `switch` with every case | 80 | 86 |
| `switch(` in the C | 91 | 96 |
| functions exported | 2,087 | 2,210 |
| decompile failures | 0 | 0 |
| call targets that are no function entry (B7 test) | 1 | 0 |
| undefined non-0xFF bytes in `.text` (`quality.tsv`) | 4,258 (340 fragments) | 242 (15 fragments) |

- **B6 [fact]:** `tools/ghidra/DisplayJumpTables.java` (`scan` / `apply` / `check`) finds every site by its encoding (`c79FF10x`,
  `c08FF10x`) and takes the length from the `cmp rX,#n` (up to 64 instructions back, no flag or `rX` write in between) and the
  condition (`cc` → n, `ls` → n+1; with an unconditional jump the earlier `b<cond>` decides). Ghidra already recovered 80 of 85. The
  five that failed are the RSPI helpers `rspi_open` 0x2011F0CC, `rspi_start` 0x2011F138, `rspi_stop` 0x2011F1AC,
  `rspi_reset_buffers` 0x2011F7B4, `rspi_wait_tx_end` 0x2011F8F8. Each checks the channel twice (`cmp r0,#5; mvncs r0,#0; bxcs lr;
  push; cmp r0,#5; ldrcc pc,…`). Auto-analysis guessed their tables one word early, so the site had references to the `b default`
  word and to 0xEA00000C (that word read as an address), and it set a **RETURN flow override** on the `ldrcc pc`. The decompiler then
  treated the jump as a return (`return param_1`). A `JumpTable` override on top of that made the decompiler process die.
  `apply` touches only the sites that `check` fails: it removes the stray references and the flow override and adds the
  COMPUTED_JUMP references. After that, Ghidra builds the switch by itself, so no override is needed (the override path stays in
  the script as a fallback, so no "Switch is manually overridden" warning is added). Now all five show `case 0` … `case 4`. The 17
  "Could not recover jumptable … Too many branches" warnings (16 sites) are a different thing: `bx rN` tail calls through function pointers
  (14 ARM, 2 Thumb), not tables (leftover 1).
- **B7 [fact]:** `tools/ghidra/DisplayGaps.java` lists candidate starts by kind. It found these on the committed project, and all
  were reviewed:
  - 97 undefined ARM functions after a return that nothing branches to (getters, CP15/PMU accessors, wrappers, guards in front of an
    existing `push` function). The chain mode finds the next helper in the same gap.
  - 2 address-taken NORTi resume stubs: 0x2015677C and 0x201567D0.
  - 1 address-taken function: 0x20138410.
  - 2 call targets that were no function entry: 0x2012001C (from the `tsc2007` task) and 0x2015632C (the IRQ entry called through
    `blx ip` from 0x2010020C, inside the stub at 0x20156310).
  - 30 + 2 **tail targets**: an unconditional `b` from one function lands inside another function body that analysis had merged.
    Examples: 0x20164654, a library routine absorbed by `FUN_20163428`, and 0x20151520 inside `mainlink_inject_rx`.
  - 2 late starts found while reviewing B8 (0x20110E68 and 0x2014E044).
  - 1 Thumb function, 0x2016385C, reached from the .data word 0x2042807C.

  That makes 137 new entries in `entries_display.tsv` (205 in all). One candidate was rejected: 0x20100104 is dead code inside
  `reset_in_ram`, a jumped-over block that falls back into its body (kind `dead_code`), and making it a function had cut
  `reset_in_ram` from 216 to 112 bytes. **FixFuncEntries fix:** its late-start walk now stops at a call and keeps functions that have
  callers. Without that, the entry 0x20103B4C (it ends in `bl` to a task loop that never returns) removed `sd_task_create`. The new
  column-2 value `thumb` disassembles an entry as Thumb. The rebuild from scratch gives the same result for the 68 older entries.
- **B8 [fact]:** before: 340 undefined fragments with non-0xFF bytes (4,258 B). About 2.9 KB of that was code; it became the B7
  functions above. `DisplayGaps … define` defines the rest (237 fragments) as strings, pointers, dwords or bytes with the EOL comment
  `T21e B8: [unreferenced] <class> fragment`, and it disassembles the one dead-code block without making it a function. Left
  undefined: 15 fragments, 242 B, all in the armcc Thumb library (0x20154xxx–0x20164fxx). They are fplib code that is reached
  through inline-parameter calls (`bl` 0x20164EFC reads the halfwords after the call), two 128-byte lookup tables (0x20156D5C,
  0x20164C00) and padding. They are listed in the fragments report as class `thumb` **[inference: library tables and code; not
  reviewed one by one]**.
- **Quality counts:** the 2,076 functions that exist before and after have exactly the same warning, `in_`/`unaff_`/`extraout_`
  and unreachable-block counts. 136 of them have changed C: smaller bodies where a tail target became its own function, and the
  five RSPI switches. The 134 new functions bring 46 warnings (43 "Removing unreachable block"), 12 `in_`, 4 `unaff_` and 1
  `extraout_`. 11 functions are gone: unnamed late starts that the new entries replace. **`tools/decomp_quality.py compare`
  therefore reports warnings 347 → 393, functions with `in_` 52 → 61 and similar rises as "WORSE" when T21g re-exports. All of
  them come from the new functions, so the new numbers are the baseline.**
- **For T21g:** run the DISPLAY steps from `tools/bootstrap.sh` (or the commands in `decomp/display/INDEX.md`), re-export
  `decomp/display`, refresh the INDEX quality table and the "File" column (`tools/index_refresh.py`).
- **Leftovers:** (1) the 16 `bx rN` tail calls through function pointers; a CALL_RETURN flow override would turn the "Could not
  recover jumptable" warnings into calls. (2) 15 other jumps from one function into another's body (kind `jump_inside`): shared
  tails in hand-written or library code (`__aeabi_uidivmod` internal entries from the unrolled divider at 0x20156260, `memclr`+4,
  `__rt_entry`, `Reset_Handler` → `reset_in_ram`+0x64, fplib 0x20164888/0x20164FA4); left as they are. (3) The 15 Thumb library
  fragments above. (4) `DisplayGaps` still reports 11 `after_return_thumb` places; the pseudo-disassembler decodes only ARM, so
  they were reviewed with `arm-none-eabi-objdump -M force-thumb`, and only 0x2016385C was added.

### T21g
**Status:** done (2026-10-28). A step 8 and integration. DISPLAY and IFDSP done first (branch
`worktree-agent-ad5fb8b0f04061087`, merged): both projects rebuilt with HiFi4 on `Xtensa:LE:32:rt600hifi4`, `decomp/display` and
`decomp/ifdsp` re-exported, new `quality.tsv` baselines, docs (`ghidra-flix.md`, `hifi4.md`, INDEX quality tables) updated.

**Plan (MAIN, parent agent).** (1) Fold `rx62t-rtsd-fix.patch` into `tools/bootstrap.sh`'s RX step as a third stage after T21c's
patch; the T21c hash becomes `RX_SINC_T21C` and `RX_SINC_FIXED` is the hash with RTSD fixed (T21d measured `618938bb…`). (2) Patch the
shared RX module through that step and recompile `rx62t.sla`. (3) Rebuild the canonical `ghidra/FT710_MAIN` with `bootstrap.sh --only
ghidra` (ApplyNames → DefineRomData → ApplySignatures) and re-export `decomp/main` (`--only export`). (4) Compare the new `quality.tsv`
with the committed one and with T21d's combined numbers, commit the new baseline, update `decomp/main/INDEX.md` and the docs.
(5) Close T21: Findings, Follow-ups, board, `issues_sync.py`. Out of scope (follow-ups): memory effect for the string pcodeops, the
two undecoded fragments at 0xFFF8FEF3 and 0xFFF9129B (now T21h).

**Results, MAIN [fact].** `bootstrap.sh --only rx,ghidra,export` (MAIN forced by a stale stamp; DISPLAY/IFDSP kept the committed projects
and re-exported byte-identical): RX module `rx62t.sinc` `618938bb…4b36`; DefineRomData 98 strings, 8 pointers, 130 zero runs, 161 B left
in 2 runs; ApplySignatures 1,212 applied, 0 failed. Export against the T17 baseline:

| Metric | before | after |
|---|---:|---:|
| functions | 2,268 | 2,324 |
| decompile failures | 0 | 0 |
| warnings (functions with one) | 1,294 (347) | 1,229 (352) |
| "Unable to track spacebase" | 8 | 0 |
| "Removing unreachable block" | 1,226 | 1,187 |
| unimplemented-instruction warnings | 3 + 3 | 0 |
| functions with `in_`/`unaff_`/`extraout_` | 61 | 8 |
| undefined non-0xFF bytes | 20,622 | 161 |

This is T21d's combined result plus T21c: two more functions (2,322 → 2,324) and no unimplemented instructions. `functions_with_warnings`
347 → 352 is the expected rise from the new functions (T21f leftover), so the new `quality.tsv` was committed as the baseline. The
export chunks were renamed (50-function boundaries moved); no doc linked to an old chunk name.

### T21h
**Status:** done (2026-10-28). The canonical MAIN rebuild and re-export ran once, in the main checkout, together with
T22a's `rx62t-semantics-fix.patch` (the worktree attempt aborted: Ghidra rejects a project path under `.claude/`); results in
`decomp/main/INDEX.md` (2,328 functions, 0 undefined non-0xFF bytes). MAIN: decode the two RX fragments T21d left undefined (161 B), 0xFFF8FEF3 (`FE D1 55 …`, inside an
`R_BSP_InterruptControl` caller at 0xFFF8FEC0, 2 references) and 0xFFF9129B (`FD 1F 02 …` after `PUSH.L R2`, likely the RXv2 accumulator
save `MVFACHI/MVFACMI`) **[inference]**. Settle each from the RXv2 software manual and `rx-elf-objdump`; patch the SLEIGH if the
module lacks the form, fold the patch into `bootstrap.sh --only rx`, rebuild MAIN and re-export.

**Plan (T21h, worktree branch off `issue-97-ghidra-gaps`).** (1) Disassemble both runs with `rx-elf-objdump` (T21c's binutils 2.47)
and read the forms in R01US0071EJ0100 (pdftotext, page ranges). (2) Dump Ghidra's listing around them (read-only `ListingExport.java`
on the canonical project) to see why each run is undefined (missing constructor, wrong length, or flow problem). (3) If the module lacks
or mis-decodes a form, write `tools/ghidra/rx62t-<name>-fix.patch` (applies after `rx62t-rtsd-fix.patch`) and test it in a private
Ghidra copy (hard links + own RX module dir, like `~/opt/t21d-ghidra-tmp`): sleigh compile, fresh MAIN import with the bootstrap recipe,
`ListingExport` + `rx_compare.py --all` (0 differences), `ExportDecomp` and `decomp_quality.py compare`. (4) Add the patch as the fourth
stage of `step_rx` (`RX_SINC_RTSD` = `618938bb…`, new `RX_SINC_FIXED`), patch the shared install with `bootstrap.sh --only rx`, rebuild
MAIN (`.stamp_main` stale) and re-export with `--only rx --only ghidra --only export` (DISPLAY/IFDSP must stay byte-identical).
(5) Commit project + `decomp/main` + new `quality.tsv`; update INDEX.md, tooling.md, tools/README.md and this section. If a run is data,
define it as data instead and say why.

**Findings [fact].** Both runs are code; neither is data.
- **0xFFF8FEC0..0xFFF8FEF4 (53 B) was not a SLEIGH gap.** `FE D1 55` is `MOVU.W [R1,R5],R5` and decodes (`rx-elf-objdump` and Ghidra
  agree; the same form at 0xFFF8FED7 too). DefineRomData's string pass ran over the code area before its code pass and took the bytes
  `55 57 5F 77 3F 00` at 0xFFF8FEF5 (`OR R5,R15` + the first bytes of `OR #0xA500,R15`) as the string "UW_w?". The flow from
  0xFFF8FEC0 then ran into the string and was cleared, and the code pass made a bogus function `FUN_fff8fefb` starting inside
  `OR #0xA500,R15` (`A5 00` read as `MOV.L SP,0x50[SP]`). Fix in `tools/ghidra/DefineRomData.java`: the first data scan covers only the
  const area (below `code=`), the code area is scanned for data after the code pass, and a clean run that is called (BSR at 0xFFF8FF2E
  and 0xFFF92477) becomes a function even when its return lies in code that analysis had already decoded. `FUN_fff8fec0` (108 B) now
  decompiles: `R_BSP_InterruptControl(0x5e,6,…)`, a per-channel counter at 0x1B5FC, the IPR-style write `0x803FE |= tbl[ch] | 0xA500`
  (channel 3: bits of 0x8C11F instead), `R_BSP_InterruptControl(0x5e,5,…)`.
- **0xFFF91295..0xFFF91302 (110 B) had two causes.** `FD 1F 02` at 0xFFF9129B is RXv2 `MVFACHI #0,A0,R2` and `FD 1F 22` at 0xFFF912AE
  `MVFACMI #0,A0,R2` (manual pp. 265-266; objdump agrees). The module had only comment lines for MVFACxx. New patch
  `tools/ghidra/rx62t-mvfac-fix.patch` (field `acci6_1`, six constructors for HI/MI/LO with imm 0/1/2; ACC is 64 bits in the module, exact
  for imm ≤ 2; details in `docs/tooling.md`). Second cause: 0xFFF91228..0xFFF91302 is a chain of 15 small CC-RX intrinsic helpers
  back to back (a PSW.PM switch through `RTE` at 0xFFF91228, `mvtc bpsw`/`mvfc bpsw`, `bpc`, `extb`, `mvtachi`, `mvtaclo`, `mvfachi`, `mvfacmi`, then
  `bset`/`bclr`/`bnot Rs,[Rd]` and an `sbrk`-style pointer bump at 0xFFF912C7 **[inference for the roles]**). DefineRomData decodes one function per run per pass and stopped
  after 10 passes, at 0xFFF91295; the limit is now 200 (the loop still ends on the first pass that adds nothing).
- Sleigh: `bootstrap.sh --only rx` gained a fourth stage (`RX_SINC_RTSD` = `618938bb…4b36` → `RX_SINC_FIXED` = `9efea07b…82a5`),
  8 NOP-constructor warnings as before; the shared install was patched with it. `rx_compare.py` rule N11 (`ACC` = `a0`).
- Test (private Ghidra copy `~/opt/t21h-ghidra-tmp`, fresh import with the bootstrap recipe; not yet the canonical project):
  DefineRomData 60 functions (was 54) and 0 B left undefined (was 161 B in 2 runs); 160 defined strings (was 161: "UW_w?" is gone);
  `rx_compare.py --all` 131,274 instructions, 131,274 same, 0 different/missing/bad/undefined.

| `quality.tsv` (MAIN) | T21g | T21h (test import) |
|---|---:|---:|
| functions | 2,324 | 2,328 (+5: 0xFFF91295, 0xFFF912A8, 0xFFF912BB, 0xFFF912BF, 0xFFF912C3; −1: bogus 0xFFF8FEFB) |
| decompile failures | 0 | 0 |
| warnings | 1,229 | 1,229 |
| functions with `in_`/`unaff_`/`extraout_` | 8 | 7 |
| undefined non-0xFF bytes | 161 | **0** |

`FUN_fff8fec0` and `FUN_fff912c7` were 1-byte stubs before (entry known, body undefined) and now have their full bodies.
DISPLAY and IFDSP are ARM/Xtensa and do not use the RX module; their re-export is byte-identical.

**Leftovers / follow-ups:**
- The `get_*` helpers (0xFFF9124C, 0xFFF91263, 0xFFF9127A, 0xFFF91295, 0xFFF912A8: `SUB #8,SP; MOV.L SP,R1; PUSH.L R2; MVFC/MVFACxx
  …,R2; MOV.L R2,[R1]; POP R2; MOV.L [SP],R1; …; RTSD #8`) decompile as `return param_2;` instead of the register they read. This is
  older than T21h (the `MVFC` ones show it in the T21g export) and looks like a stack-aliasing or PUSH/POP p-code problem; for T22a's
  semantics check.
- `MVTACHI`/`MVTACLO` still have empty semantics (writes to ACC are lost) and A1/`MVFACGU`/guard bits are not modelled; left to T22a's
  `rx62t-semantics-fix.patch` to avoid two patches editing the same constructors.

### T21i
**Status:** done (2026-10-28). MAIN: give the RX string instructions a memory effect again (T22e follow-up, regression of
T21c's B4 pcodeops).

**Problem [fact, T22e].** T21c made `SMOVF`/`SMOVB`/`SMOVU`/`SSTR` named pcodeops. The decompiler treats a CALLOTHER as touching
no memory, so stores into a stack buffer that only a string op reads are dead: 34 CAT/AI reply builders (0xFFFDE064–0xFFFE1774)
lose 119 stores and 31 `nib2hex` results. #97 B4 asked for pcodeops "for readability only" with "no other output changes", so
correctness wins over B4 here.

**Plan.**
1. Patch `tools/ghidra/rx62t-stringmem-fix.patch` (after T22a's `rx62t-semantics-fix.patch`): `SMOVF`, `SMOVB`, `SMOVU` and the
   three `SSTR` sizes go back to explicit byte/element loops (T17's, with `R2:1`/`R2:2` for the narrow `SSTR` stores and
   the register results of the manual pp. 189-192). The compare/search ops `SCMPU`/`SUNTIL`/`SWHILE` (12 uses, read only) stay
   pcodeops unless step 3 shows lost stores for them too.
2. `rx_semcheck.py`: model the copy/store bytes for `SMOVF`/`SSTR` instead of a call, and keep R3 small (0–40) for them, so the
   emulator's p-code loop terminates; rerun gen/emulate/check on a scratch import (expect 0 failures).
3. Private Ghidra copy (`~/opt/t21i-ghidra-tmp`: hard links, own RX module), fresh MAIN import with the bootstrap recipe,
   `ExportDecomp`; `decomp_behavior_diff.py` against pre-T21 MAIN (`9622a8f^`) and against the current `decomp/main`:
   `lost_buffer_stores` and `dropped_result=F_fffb2e9c` go to 0, nothing else regresses; `decomp_quality.py compare`.
4. Sixth `bootstrap.sh --only rx` stage, rebuild canonical MAIN and re-export (one Ghidra job at a time), update
   `decomp/main/INDEX.md`, `docs/tooling.md`, `tools/README.md`, this section; board and `issues_sync.py`.

**Findings [fact].**
- Patch `tools/ghidra/rx62t-stringmem-fix.patch` (3 hunks): `rx62t.sinc` `c4d71924…c3d0` → `30af4806…c69d`; sleigh: the usual 8 NOP
  warnings. `SCMPU`/`SUNTIL`/`SWHILE` stay pcodeops: all 12 MAIN calls read a ROM constant, a parameter, or `cat_parse`'s
  `uStack_d`, which also goes to `toupper_inplace` (a real call), so no store can be lost.
- Semantics (`rx_semcheck.py`, model now copies/stores the bytes, R3 0–40): 28,772 cases from 286 shapes, **0 fail**, 0
  emulation errors (SMOVF 160, SSTR 84).
- Test import (private Ghidra `~/opt/t21i-ghidra-tmp`, bootstrap recipe) and the canonical rebuild are file-for-file identical.
  `decomp_behavior_diff.py` against the T22a export: 1,799 unchanged, 341 `other`, 108 `data`, 72 `signature`, 7 moved; checked
  by hand: reply builders have their stores back (`FUN_fffe0ba1` `"SF00;"` + `local_9[3]`, `FUN_fffdebd1` `local_6[2] =
  nib2hex(…)`, `FUN_fffde887` `"CN00000;"`); `fewer_args` (20) and `dropped_result` (2) are false parameters/returns the pcodeop
  made up by reading R1–R3 (`FUN_fff9a869` loads R1 at its entry and takes no arguments; `FUN_fffe56e4` returned `main`);
  `lost_strings` are fragments replaced by the whole literal. Against pre-T21 MAIN (`9622a8f^`): 0 functions drop a `nib2hex`
  (F_fffb2e9c) result (T22e: 17).
- `quality.tsv`: functions 2,328, failures 0, undefined non-0xFF 0, warnings 1,217 → 1,222 (Globals-overlap 24 → 29),
  `functions_with_extraout_vars` 1 → 0. DefineRomData defines 2 strings and 3 zero runs fewer (analysis types those bytes
  first now; still 0 B undefined); the C shows more literals (51 → 66 distinct).
- DISPLAY and IFDSP exports byte-identical.
- **T21h leftovers, also closed here.** (a) The five `get_*` helpers 0xFFF9124C–0xFFF912A8 decompiled as `return param_2;`: not
  p-code, but the default prototype. Its `<output>` lists R1, R2, R3, R4, R14 as alternatives, and for these five (only these:
  1,117 unsigned functions checked with a decompile pass, 5 come out `R2:4`, the rest `R1` or void) the decompiler picked R2,
  the `POP R2` restore. They are named in `names_main.tsv` and locked in `signatures_main.tsv` as `uint32 f(void)` (`doc`):
  `get_bpsw` now returns `in_BPSW`, `get_acc_hi` `(uint)(in_ACC >> 0x20)`. No callers; the cspec is left as it is. (b)
  `MVTACHI`/`MVTACLO` had empty bodies: `tools/ghidra/rx62t-mvtac-fix.patch` (seventh `--only rx` stage, `30af4806…c69d` →
  `73d417d2…8290`; sleigh NOP constructors 8 → 6) writes ACC bits 63..32 / 31..0 (manual pp. 267-268). The two MAIN uses are
  one-instruction helpers (0xFFF9128D, 0xFFF91291) whose ACC write nothing reads, so their C does not change. Rebuild diff
  against the first T21i export: exactly the five helpers changed (`signature`), ApplySignatures 1,217 applied.

### T21j
**Status:** done (2026-10-28). DISPLAY and IFDSP: apply T22d's recommended Ghidra fixes (items 1, 2, 3, 5 of its list).

**Plan.**
1. `tools/ghidra/ApplyData.java` + `data_<image>.tsv` (address, type, count, name, note): clears the range and applies the type;
   `float`/`int32` arrays split at every referenced address inside the range (so the two FFT twiddle tables stay separate); `code`
   rows only disassemble (no function). Rows (from `docs/tasks/T22d-undefined-classes.tsv`, cleanly classified ones only):
   HiFi4 float32 tables (FFT twiddles, FIR/window, ramps, libm), `two_over_pi` int32[201], the XOS/libm names; code at
   0x2316F1 (switch case) and 0x2287FC (level-2 interrupt epilogue); DISPLAY printf sign tables `char[4][4]` at 0x20154B64 and
   0x20154BE0, fplib reciprocal seed `byte[128]` at 0x20164C00; M33 `ctype` `byte[256]` at 0x87D84, FCFB `byte[512]` at
   0x08000400, the referenced short strings and the pointer at 0x08001830.
2. `IfdspHifi4Setup.java`: 0x200000–0x207CEF becomes its own read-only, non-executable block `sram_dsp_rodata`.
3. Entries: DISPLAY `2016385a thumb` replaces `2016385c` in `entries_display.tsv`; new `entries_m33.tsv` (0x0800143C, 0x00087232,
   Thumb) applied with `FixFuncEntries.java`; HiFi4 0x228B08 (idle thread start, stored in a context at 0x227859) as an
   `EXTRA_ENTRIES` row of `flix_compare.py`, `entries_hifi4.tsv` regenerated.
4. `bootstrap.sh`: wire the scripts/tables into `build_display`/`build_ifdsp` (and their stamps); rebuild DISPLAY, M33 and HiFi4
   one job at a time; re-export; `decomp_quality.py compare` and `decomp_behavior_diff.py` per image; docs, board, sync.
Left on purpose: the jump table at 0x206290 (no load of its address; needs a jump-table override for one 13-byte case), the
other T22d "leave" items (fill, alignment, unreferenced stubs, unknown bytes).

**Findings [fact].** Canonical rebuild of DISPLAY, M33 and HiFi4 (one Ghidra job at a time), all exports re-done; MAIN unchanged.
- Scripts: `FixFuncEntries` DISPLAY 205 created, 28 late starts removed, 0 failed; M33 2 created, 1 removed; `ApplyData` DISPLAY 3/3,
  M33 12/12, HiFi4 30/30 rows (29 data items after splitting at referenced elements), 0 failed.
- Functions: DISPLAY 2,210 (0x2016385A replaces 0x2016385C); M33 426 → 427 (`SystemCoreClockUpdate` 0x0800143C replaces
  0x0800143E, + 0x00087232); HiFi4 1,081 → 1,083 (+ idle thread 0x228B08, + 0x2287F8: once 0x2287FC was disassembled, analysis
  found this `ret.n` through five pointers in `.data` 0x237A94–0x237AA4, the empty default handler; both are `EXTRA_ENTRIES` now,
  and `flix_compare.py funcs`: 1,069 SRAM functions = reference list, MATCH).
- `quality.tsv`: undefined non-0xFF bytes DISPLAY 242 → 86, M33 5,162 → 4,363, HiFi4 29,161 → 6,377; warnings and failures
  unchanged; HiFi4 functions with `in_` variables 161 → 162 (the new idle thread reads CCOUNT).
- `decomp_behavior_diff.py`: DISPLAY 2,208 unchanged (+ the moved entry); M33 412 unchanged, 6 moved, 7 `data`; HiFi4 1,044
  unchanged, 8 moved, 16 `data`, 13 `other`, all checked in samples to be typed table reads (`*(undefined4 *)(&DAT_00204be0 + i*4)`
  → `FLOAT_ARRAY_00204be0[i]`, `&DAT_00201900` → `FLOAT_ARRAY_00201900` as an FFT argument).
- The idle thread showed T22e's cosmetic `wsr_ps` … `wsr_ps_5`; fixed in T21k.

### T21k
**Status:** done (2026-10-28). HiFi4: one pcodeop per special-register write (T22e cosmetic follow-up).

**Problem [fact, T22e].** `xtensa_sleigh_gen.py` emits one opaque pcodeop per iclass output, so one `wsr.ps a3` decompiles as six
calls `wsr_ps` … `wsr_ps_5` (one per PS field state). **Plan.** Generator: keep one pcodeop per register output (their values
differ: `xsr` gives AR the old SR and SR the old AR, so `xsr_excsave1` ×2 stays), but give two or more state outputs one call whose
result is cut into disjoint byte ranges, one per field (no false equalities between fields). Regenerate from the pinned
`xtensa-modules.c` (the old generator reproduces the committed files), selftest, private Ghidra copy, scratch HiFi4 import:
`flix_compare.py compare` unchanged, decomp diff; then install, rebuild HiFi4, re-export, docs.

**Findings [fact].** The committed generator reproduces the committed language byte for byte from the pinned `xtensa-modules.c`
(SHA-256 `9e218b19…f372`); the new one changes 45 constructors and 2,090 → 2,008 pcodeops: `wsr`/`xsr` of PS, CCOMPARE0/1,
DEBUGCAUSE, three `wur.ae_*`, the HiFi4 bit-stream loads/stores (`ae_db*`, `ae_sb*`, `ae_vl*`) and `f64cmph`/`f64iter`/`f64norm` (all
write two or more state fields). `selftest`: 49,389/49,389 instructions equal objdump. Private Ghidra (`~/opt/t21k-ghidra-tmp`),
scratch HiFi4 import with the bootstrap recipe: Ghidra listing identical to the canonical one (address, length, mnemonic,
operands), `flix_compare.py compare` unchanged (MATCH 47,340/49,389 = 95.85 %, bundles 12,633/12,676; every mismatch `missing`);
`quality.tsv` unchanged (1,083 functions, 0 failures, 258 warnings). Decomp diff: 1,008 unchanged, 75 changed, all fewer calls
or temporaries, e.g. `FUN_00226f70` six `wsr_ps*` calls → `wsr_ps(uVar2 & 0xfffffff0 | param_3 & 0xf);`, the idle thread
`FUN_00228b08` one `wsr_ps(&DAT_00040020)`. The canonical rebuild (`bootstrap.sh --only hifi4 --only ghidra --only export`) equals
the scratch export; MAIN, DISPLAY and M33 exports unchanged. `xsr_*` stays two calls (register and state values differ).

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
Every #97 item is closed; details in the sub-task sections, numbers in `decomp/*/INDEX.md` and `decomp/*/quality.tsv` **[fact]**.

| # | Result | Sub-tasks |
|---|---|---|
| A | Generated language `Xtensa:LE:32:rt600hifi4` (FLIX bundles, HiFi4/FPU ops) from Cadence's `xtensa-modules.c`: selftest 49,389/49,389 instructions = objdump; Ghidra listing vs `flix.dis` 95.85 % (bundles 99.66 %), every mismatch an instruction analysis does not reach; decompile failures 1,054 → 0 (1 `halt_baddata` on data), warnings 2,038 → 258 | T21a, T21b, T21g, T21k |
| B1 | RXv2 coverage diff against binutils; missing/mis-decoded forms patched (MUL/XCHG memory forms, SCCnd, RTSD, MVFACxx, MVTACxx); Ghidra = objdump on all 131,274 MAIN instructions; T22a's semantics check 28,772/28,772 | T21c, T21h, T21i, T22a |
| B2 | spacebase warnings 8 → 0 (RTSD frame size) | T21d |
| B3 | 1,217 locked prototypes (`signatures_main.tsv`); call-argument/return checker; JSR Rs is a call (T22a) | T21d, T21i, T22a |
| B4 | compare/search string ops are named calls; copy/store ops are loops again because as calls their stores were lost | T21c, T21i |
| B5 | MAIN undefined non-0xFF bytes 20,622 → 0 | T21d, T21h |
| B6 | DISPLAY: 86 jump-table sites, all decompile to a switch | T21e |
| B7 | DISPLAY: 205 hand-checked entries (`entries_display.tsv`), incl. the 2-byte-late 0x2016385A | T21e, T21j |
| B8 | DISPLAY undefined non-0xFF bytes 4,258 → 86 | T21e, T21j |
| B9 | `FUN_0020bb74` decompiles | T21b |
| B10 | HiFi4 function list = reference list (1,065 `flix.dis` functions + 4 documented extras), checked with `flix_compare.py funcs` | T21b, T21j |
| B11 | `quality.tsv` per image from the export; `bootstrap.sh --only verify` fails when a count gets worse | T21f |

Also from T22's independent checks: M33 `SystemCoreClockUpdate` entry, M33/HiFi4 data typed, HiFi4 rodata in its own read-only
block (HiFi4 undefined bytes 29,161 → 6,377, mostly alignment), five MAIN intrinsic helpers with locked signatures (T21i, T21j).

## Follow-ups
Known, small, left on purpose (none changes decompiled behaviour that MAIN, DISPLAY or the DSP use):
- HiFi4 jump table at 0x206290 (cases 0x2316F1, 0x231549, 0x231517): no instruction loads its address, so Ghidra cannot recover it
  without a jump-table override; the 13-byte case at 0x2316F1 is disassembled (T21j).
- RX module: `JMP Rs` (no branch op, like `JSR Rs` before T22a) and `BNOT Rs,Rd` (`Rd ^ (Rs & 31)`) are still wrong; MAIN has no
  such instruction, so nothing can test a fix (T22a).
- The default RX prototype lists R1–R4/R14 as alternative return registers; only five unreferenced MAIN helpers were affected and
  they are locked now (T21i). A cspec change would touch every unsigned function.
- REA feature requests from T22 that are not device support (prototype seeds, analysis reuse across CLI calls, `.sla` digest in the
  analysis profile, a rizin deep provider, pseudocode-set import): see T22f in `T22-rea-verification.md`.
