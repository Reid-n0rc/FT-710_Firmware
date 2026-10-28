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

## Findings

## Follow-ups
