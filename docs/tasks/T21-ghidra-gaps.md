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
