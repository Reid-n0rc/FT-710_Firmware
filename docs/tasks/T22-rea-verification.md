# T22 — Verify the #97 decompile fixes with independent REA and rizin tools (issue #104)

**Status:** in progress · **Depends on:** T21 · **Issue:** [#104](https://github.com/Reid-n0rc/FT-710_Firmware/issues/104)

## Goal
T21 checks each fix against one reference (`flix.dis`, GNU binutils, Ghidra's own counts). T22 re-reads the same results with tools
that do not share those assumptions: the REA MCP tools (fork github.com/Reid-n0rc/rea) and rizin. Where REA lacks support for one of
the FT-710's cores or formats, the support is added to the owner's fork first (owner's instruction, 2026-10-28) and then used.
Analysis and tooling only; no radio.

## Plan
Owner: parent agent, branch `issue-97-ghidra-gaps`, 2026-10-28. Sub-tasks run in parallel in their own worktrees:

| Sub-task | Deliverable |
|---|---|
| T22a | MAIN: T21c's RX decoder fixes checked with a third decoder (rizin), T21d's signatures re-read through REA; disagreements listed and settled from the manual |
| T22b | DISPLAY: T21e's jump tables, function starts and fragments recovered again with rizin and REA; differences listed and settled |
| T22c | IFDSP HiFi4: base-ISA instructions outside bundles checked with rizin's Xtensa decoder; after T21a and T22f, the DSP opened and decompiled in REA (B9 re-check) |
| T22d | all images: the undefined bytes that are left classified (code / strings / tables / padding) with REA's entropy, string and region tools |
| T22e | after T21g: before/after behaviour diff of changed functions (`find_changed_behavior`, `compare_functions`) |
| T22f | REA fork: device support the others need (raw `xtensa-hifi4` bound to `Xtensa:LE:32:rt600hifi4`, anything missing for ARMv7/ARMv8-M/RX raw images, rizin provider setup), with tests; the only agent that edits `~/opt/rea` |

Rules: as T21 (Ghidra slot limiter, scratch projects outside `.claude/`, heartbeats, commit each step). Agents that find a REA gap
write a request file to the scratchpad `rea-requests/` directory for T22f instead of editing the fork. New REA capabilities are used
through the fork's CLI build until the MCP server is restarted.

## Sub-task status

### T22c
**Status:** done (2026-10-28). IFDSP HiFi4.

Plan (resumed 2026-10-28 after steps 1–2):
1. done: base ISA outside bundles vs rizin.
2. done: `Xtensa:LE:32:rt600hifi4` vs an own decoder. Leftovers to close here: `PcodeDump.java` was committed as WIP but is the
   script the 10-bundle p-code check used (complete, catalogued in `tools/README.md`); settle the open `ret.n` at 0x22F79D
   (desync or real) against Ghidra's listing and the flow decode; record 0x22672C (function missing from `entries_hifi4.tsv`)
   as a follow-up.
3. REA: once T22f's raw `xtensa-hifi4` lane exists (its CLI command in the scratchpad `t22f-ready.md`), open
   `build/FT-710_IFDSP_V0101_hifi4.bin` in REA (fork CLI, under `memgate.py 2700`, hard timeout) with the new language;
   B9 re-check (`FUN_0020bb74` decompiles, `{ l32r a3; and a14, a14, a3 }` uses the old `a3`); compare REA's function list and
   decompile success with the canonical `decomp/ifdsp/hifi4` (T21g: 1,081 functions, 0 failures, 258 warnings, 1 halt_baddata).
   If the lane is not ready when steps 1–2 are closed, T22c is recorded as blocked on T22f.

**Step 1 — base ISA outside bundles, third decoder (rizin 0.9.1, Capstone Xtensa).** `tools/hifi4_rizin_compare.py` runs one
`pdj 1 @ addr` per `flix.dis` instruction start on `build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin` (base 0x200000), so the
bundles cannot desynchronise rizin, and compares mnemonic and operand values (rules in the docstring).

```sh
python3 -I tools/hifi4_rizin_compare.py ~/opt/rizin-0.9.1/bin/rizin build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin \
  decomp/ifdsp/hifi4/flix.dis /tmp/rz.tsv
```

| Class | Non-`ae_*` instructions outside bundles | Notes |
|---|---:|---|
| compared | 34,730 | plus 1,983 `ae_*` outside bundles (rizin has no HiFi4: 1,055 invalid, 928 decoded as ESP32-S3 `ee.*` ops, not counted) |
| bytes in the image differ from `flix.dis` | 0 | |
| **agree** (mnemonic + operands) | **32,084 (92.4 %)** | |
| FPU on the standard FP-option layout | 1,601 | 30 FPU ops; see below |
| rizin cannot decode | 1,031 | 745 are standard density ops Capstone lacks (`beqz.n` 429, `nop.n` 212, `bnez.n` 103, `ret.n` 1); 286 are core options it lacks (`f64*` 214, `rur/wur.ae_*` 29, `s32ri`, `dpf*`, `lict`, `iii`, `l32ai`, `s32nb`, TLB/`diwb*`, `read_impwire`) |
| **disagree** | **14** | all settled for `flix.dis`, below |

Disagreements, settled from the bytes and `xtensa-modules.c` **[fact]**:
- `slli aR, aS, 32` × 9 (e.g. 0x20D8CF `00e801`): the field is 0 and `OperandSem_opnd_sem_msalp32_decode` gives 32 - 0 = 32;
  rizin prints an empty operand but its own ESIL says `0x20,a8,<<`. rizin display bug.
- `all4 b0, b0:b1:b2:b3` × 2: rizin writes the BR4 group by its first register; same value, naming only.
- `any8 b0, b8:…:b15` × 2 (0x22640F, 0x22642F `00ae00`): `bs8` is `FIELD_s8` = bit 11 only, `BR8_decode` shifts it left by 3,
  so s = 0xE gives b8. rizin uses the whole `s` field (`b14`, not a BR8 group). rizin bug.
- `movi.n a15, 47` at 0x211239 (`2cff`): op0 = 0xC with i = 0 is `MOVI.N` (`Slot_inst16b_decode`), imm = t[2:0]·16 + r = 0x2F;
  `break.n` is op0 = 0xD. rizin bug.
- (not counted as a disagreement) `ret.n` at 0x22F79D is `0dfc` with s = 0xC: this core's `Slot_inst16b_decode` does not test
  `s` for `RET.N`, Capstone rejects it. It follows a `.byte 0x93` in `flix.dis`, so it is probably a desync after padding (see
  the conflict regions below) **[inference]**. Settled in the resumed run **[fact]**: 0x22F79D is the middle of Ghidra's
  `call8 0x22b874` at 0x22F79C (`650dfc`), in the block 0x22F790 that `{ bltz.w15 a10, 0x22f790; nop }` at 0x22EAFE branches to;
  conflict region 270 (0x22F791–0x22F79D) is "Ghidra right" in `T22c-hifi4-conflict-regions.tsv`. The `ret.n` is a `flix.dis`
  sweep artefact, and rizin's refusal of the same bytes is not a rizin gap that matters for this image.

FPU (1,601 uses of 30 ops: `mul.s`, `add.s`, `wfr`, `sub.s`, `olt.s`, `maddn.s`, `const.s`, …): rizin decodes the standard
Xtensa FP option (`mul.s fr, fs, ft` = bits 12–15, 8–11, 4–7 on `f0..f15`). This core's VFPU is different **[fact]**:
`Iclass_MUL_S_args` = `opnd_vfpu2_sem_spfma_vt` (out), `_vs`, `_vr`, on `REGFILE_AE_DR`, with `vt` = bits 8–11, `vs` = bits 4–7,
`vr` = bits 12–15 (`Field_fld_vfpu2_sem_spfma_v*_Slot_inst_get`). So 0x208878 `00c22a` is `mul.s aed2, aed0, aed12` as
`flix.dis` prints, not `mul.s f12, f2, f0`: **the output register sits in a different field, not only in a different register
file**. Anything that reuses Ghidra's stock Xtensa FPU constructors for this core gets the destination wrong.

**Step 2 — the new language, checked with an own decoder.** Language: the final T21a install of `Xtensa:LE:32:rt600hifi4`
(`xtensa_rt600hifi4.sla` MD5 `008233af…c3ca`, the same file before and after T21a's merge). Ghidra exports: T21b's
`tools/flix_oracle.sh` run into a T22c scratch project (decode mode 49,389 / 49,389, listing 47,312 / 49,389 = 95.79 %).

The third decoder is `tools/hifi4_isa_decode.c` (driven by `tools/hifi4_hand_decode.py`). It is compiled with
`xtensa-modules.c` and calls only that file's own pieces: `format_decoder`, the format's slot `get` functions, each slot's
opcode `decode`, the slot field getters, operand `decode`/`undo_reloc` and the iclass in/out lists. The rest is its own code:
loading the bytes into the 32-bit words, walking the slots, printing operands (BR groups as `b0:b1:b2:b3` from the operand's
register count, `sout` operands hidden), and PC-relative targets. It is not libisa and shares nothing with T21a's
`xtensa_sleigh_gen.py` / `xtensa_isa_dump.c`. It shares the **tables** with objdump, so it checks the decoder drivers (libisa
in objdump, the generated SLEIGH in Ghidra), not the tables. rizin (step 1) is the check that does not depend on the tables.

| Check | Result **[fact]** |
|---|---|
| hand decoder vs `flix.dis`, every instruction | 49,389 / 49,389 agree (length, mnemonic, operands) |
| hand decoder vs Ghidra decode mode, every `flix.dis` address | 49,389 / 49,389 agree |
| hand decoder vs Ghidra's analysed listing, every Ghidra instruction in SRAM | **48,464 / 48,464 agree**, including the 1,084 that start where `flix.dis` has no instruction |
| 40 bundles, field by field (`sample 40`) | **40 / 40 agree with both** `flix.dis` and Ghidra |
| 10 bundles with a cross-slot write → read, Ghidra p-code (`PcodeDump.java`) | **10 / 10 correct**: every reader slot reads the old value |

The 40 bundles: 8 × `ae_format48`, 8 × `ae_format48_2`, 7 × `ae_format48_3`, 8 × `ae_format88`, 8 × `ae_format88_2`,
1 × `ae_format88_3`, with 85 different slot opcodes. They include every `.w15` branch form, `loop`/`loopgtz` in a slot, `l32r`
in a slot, FPU ops on `aed` (`mul.s`, `madd.s`, `msub.s`, `sub.s`, `float.sx2`, `mulmux.s`, `conjc.s`), 2-, 3- and 4-slot
bundles with `nop` fillers, and the 64-bit `ae_mul*` MACs. `ae_format88_4` occurs nowhere in the image's 12,676 bundles. The
selection is deterministic (greedy on new format, then new opcodes); the slot words, field values and decoded operands of
each are in the scratchpad `t22c/sample40.tsv`. One worked example: 0x207D78 `2e d9 90 d0 00 b4` → words
`insn[0] = 0xD090D92E`, `insn[1] = 0xB400`; `insn[0] & 0xF = 0xE` and `insn[1] & 0xC000 = 0x8000`, so `format_decoder`
gives `ae_format48_2`; slot `ae4_slot0` decodes to `beqi.w15` with `ars` = 9, `b4const` = 2 and `xt_wbr15_label` = 221 →
`0x4 + 221` relative to 0x207D78 = 0x207E59; slot `ae4_slot1` is `nop`. Ghidra prints `{ beqi.w15 a9, 0x2, 0x207e59; nop }`.

Bundle-parallel semantics. From the iclass in/out lists, **1,524 of the 12,676 bundles** (12.0 %) have a slot that writes a
register another slot reads (the earlier estimate was "about 1,465" from an operand heuristic). Ghidra's p-code for the 10
checked bundles (0x210EC1, 0x218084, 0x218923, 0x21A599, 0x21EAC8, 0x22F73E, 0x22FEF4, 0x233E76, 0x233F5F, 0x235DA7) computes each
slot's result into a per-slot staging register (0x4200/0x4240/0x4280/0x42C0 for slots 0–3, plus 0x4250 for a slot's second
output such as the `a2` update of `ae_l32.ip`) and copies all of them to the real registers after the last slot. Every reader
uses the pre-bundle value, for example `{ s32i a6, a2, 132; movi a2, 0 }` stores through the old `a2`, `{ ae_l32.i aed7, a2, 4;
ae_l32.ip aed8, a2, 4; madd.s aed14, aed8, aed12 }` reads the old `a2` and the old `aed8`, and `{ ae_mov aed2, aed13; …; maddmux.s
aed13, … }` swaps through the staging registers. Stores to memory happen in slot order; no checked bundle has a load and a store
to the same address. Two side notes: `mul.s`/`madd.s` write the full 64-bit `aed` with `INT_ZEXT` of the 32-bit result (the
upper half becomes 0) **[fact: p-code]**, whether the hardware keeps the upper half is not known **[guess]**. And 7 bundles in
`flix.dis` have two slots writing one register (0x209C01, 0x212B6D, 0x21E7E2, 0x22F9CB, 0x2317E8, 0x2358D0, 0x2360C1). That is
not a legal bundle, and none of them is in Ghidra's listing: all 7 are `flix.dis` desync artefacts (0x209C01 sits in a
`l32r a3; j 0x209B88` case table) **[fact: listing; inference: illegal]**. One of them (0x209C01) was in the 40-bundle sample:
its bytes still decode identically in all three decoders.

**Listing conflicts: who is right (the coordinator's request from T21b).** `flix_compare.py`'s listing mode has 2,077 "missing"
rows; 1,002 of them lie inside a Ghidra instruction (a conflict), grouped (8-byte gap) into **337 regions**, the same numbers
T21b had. `hifi4_hand_decode.py regions` settles each region on its own, without trusting either listing:
1. Its own recursive-descent flow decode on the hand decoder's table, from the 1,067 entries of `tools/ghidra/entries_hifi4.tsv`
   (branch, loop and call targets from the PC-relative operands of every slot, no fall-through after `j`/`jx`/`ret*`/`rf*`/`ill`).
   This reaches 45,400 instruction starts. A second pass adds 231 code pointers: values of reached `l32r` literals that point
   into `.text`, aligned words in the SRAM rodata below 0x207000 (jump and handler tables) and in the TCM and SRAM-data images.
   It then reaches 48,580.
2. Objdump (`--start-address` at each Ghidra-only start) and the hand decoder at every Ghidra start in the region, compared with
   Ghidra's text.

| Verdict | Regions | `flix.dis` rows |
|---|---:|---:|
| Ghidra right: the flow reaches Ghidra's starts and none of the `flix.dis`-only starts | **313** | 948 |
| Ghidra right, reached only through a code pointer (jump/handler table, `l32r` literal) | **23** | 53 |
| reached by nothing, Ghidra's decode the coherent one (hand-checked) | 1 | 1 |
| `flix.dis` right, or mixed | **0** | 0 |

Ghidra's instructions decode the same in Ghidra, objdump and the hand decoder at every Ghidra-only start in all 337 regions, so
the conflicts are about **where** decoding starts, not about how bytes decode. 218 of the regions have a `.byte` or `ill` within
8 bytes. 0x207F9E–0x207FA4 (T21b's example) is "Ghidra right" (0x207FA0 and 0x207FA3 reached). The one region nothing reaches is
0x22672E: 0x22672C is a 4-aligned `entry a1, 32` with code that registers the interrupt handler 0x22671C
(`xos_register_interrupt_handler` 0x2266FC). It is a function with no caller and no pointer in any image. `flix.dis` loses sync
after the `.byte` at 0x22672A, and the function is missing from `entries_hifi4.tsv` **[fact: bytes; inference: dead code]**.
Verdicts per region (lo, hi, rows, verdict, near padding, the starts each side has alone, which of them are reached, the decode
check): [`T22c-hifi4-conflict-regions.tsv`](T22c-hifi4-conflict-regions.tsv). So the listing-mode gap is entirely `flix.dis`
sweep artefacts: **with Ghidra's starts, Ghidra's listing has no wrong instruction in any conflict region.**

Leftovers closed in the resumed run: `tools/ghidra/PcodeDump.java` (committed as "WIP" in `3a438f3`) is the finished script
the 10-bundle check above ran (`t22c/pcode10.txt`); no change was needed, it is catalogued in `tools/README.md`. Follow-up for
the HiFi4 entry list (T21b/T21g owners): add 0x22672C (`entry a1, 32`, registers handler 0x22671C) to
`tools/ghidra/entries_hifi4.tsv`, as dead code with no caller.

```sh
python3 -I tools/hifi4_hand_decode.py build      # needs xtensa-isa.h, xtensa-isa-internal.h, ansidecl.h from binutils (HD_INCLUDE)
python3 -I tools/hifi4_hand_decode.py flix
python3 -I tools/hifi4_hand_decode.py ghidra <oracle>/listing.tsv
python3 -I tools/hifi4_hand_decode.py sample 40 <oracle>/decode.tsv /tmp/sample40.tsv
python3 -I tools/hifi4_hand_decode.py parallel 10 /tmp/parallel10.tsv
python3 -I tools/hifi4_hand_decode.py regions <oracle>/listing/mismatches.tsv <oracle>/listing.tsv /tmp/regions.tsv
tools/ghidra-headless.sh <projdir> <proj> -process FT-710_IFDSP_V0101_hifi4.bin -noanalysis -readOnly \
  -scriptPath tools/ghidra -postScript PcodeDump.java /tmp/pcode.txt 210ec1 218084 ...
```

### T22e
**Status:** in progress (2026-10-28). All images: before/after behaviour diff of the functions the #97 fixes changed.

Plan:
1. Baselines from git, not re-decompiles (the shared RX module is patched now, so an old project would re-decode with the new SLEIGH):
   "before" = `decomp/` at `9622a8f^` (MAIN) and `7b1b48b^` (DISPLAY, IFDSP M33, IFDSP HiFi4), whose `.c` files are the pre-T21
   exports (T21d/T21f touched only `INDEX.md`/`quality.tsv` there); "after" = `9622a8f` (MAIN) and `7b1b48b` (others), the current
   branch. MAIN numbers are against 9622a8f, before T21h's two fragments.
2. `tools/decomp_behavior_diff.py`: split every `.c` into functions at the `// ===== name @ addr` markers, key by entry address
   (chunk files were renamed), pair with `functions.tsv`, and classify each changed function by successive normalisation:
   renamed/moved only (identical after mapping old→new names of functions/labels and dropping comments), signature/type only
   (same callees in order, same constants, same control-flow keywords after erasing types and variable names), and then by the
   evidence of the fix that touched it: spacebase/stack fixed (`in_`/`unaff_`/`extraout_` or spacebase warning gone), new
   instructions decoded (string pcodeops, XCHG/SCCnd/MUL fixes, `halt_unimplemented` gone), jump table recovered (`switch` gained),
   function boundary changed (size changed with a new neighbouring entry), HiFi4 bundles decoded (`halt_baddata`/bad-instruction
   gone), and a residue "real behaviour difference" (callee set, constants or stores differ without one of those reasons, or a call
   result used before and dropped after). Added/removed functions are counted separately. Output: one TSV per image
   (`docs/tasks/T22e-<image>-changed.tsv`, if modest).
3. REA: try `compare_artifacts` on the two decomp trees and `compare_functions`/`find_changed_behavior` on sample functions;
   record what they can and cannot show for a before state that exists only as exported text (request file if a gap).
4. Sample the "real difference" class (and the known T21d `smovf` lost-value case) against the disassembly
   (`rx-elf-objdump`, `arm-none-eabi-objdump`, HiFi4 `flix.dis`) and settle which side is right, with addresses.
5. Findings and counts here; commit after each step.

**Results [fact unless marked].** Before = `decomp/` at `9622a8f^` (MAIN) / `7b1b48b^` (others), after = `9622a8f` / `7b1b48b`
(= the current branch; **MAIN is measured against 9622a8f, before T21h's two fragments**). M33 is byte-identical (426 / 426
unchanged). Per-function classes and flags: [`T22e-changed-functions.tsv`](T22e-changed-functions.tsv) (image, entry, names,
sizes, class, flags; unchanged functions left out).

```sh
git archive 9622a8f^ decomp/main | tar -x -C <s>/before; git archive 9622a8f decomp/main | tar -x -C <s>/after   # likewise 7b1b48b
python3 -I tools/decomp_behavior_diff.py <s>/before/decomp/main <s>/after/decomp/main main.tsv \
  --marked main_patched_funcs.txt --locked tools/ghidra/signatures_main.tsv --label MAIN
```
`main_patched_funcs.txt` = the 569 MAIN functions whose `rx-elf-objdump` listing (per function, from the after `functions.tsv`)
has `XCHG`, `SC<cnd>`, `MUL dsp[].UB` or a string op (T21c counted 570).

| Class (first match wins) | MAIN | DISPLAY | HiFi4 | M33 |
|---|---:|---:|---:|---:|
| unchanged | 903 | 1,940 | 166 | 426 |
| renamed/moved only (names, labels, stack-variable names, comments) | 50 | 88 | 0 | 0 |
| HiFi4 bundles now decoded (`halt_baddata`, bad-instruction warning or stock `flix()` gone) | – | – | 892 | – |
| new instructions decoded (T21c ops, `halt_unimplemented` gone) | 566 | – | – | – |
| jump table recovered | 0 | 5 | 0 | – |
| spacebase / stack fixed (spacebase warning or `in_`/`unaff_`/`extraout_` gone) | 16 | 0 | 5 | – |
| function boundary (size changed) | 0 | 0 | 10 | – |
| signature locked (own or a callee's prototype changed or locked) | 707 | 3 | 2 | – |
| data defined (strings, arrays, labels) | 25 | 37 | 0 | – |
| other | 1 | 3 | 4 | – |
| added / removed functions | 56 / 0 | 134 / 11 | 2 / 69 | 0 / 0 |

Checks of the classes (sampled against the disassembly):
- MAIN `insn`: `FUN_fff90837` was `halt_unimplemented()`; now `old = *p; *p = 1; return old == 0`, which is the `XCHG [R1].L,R2`
  test-and-set at 0xFFF90845. `FUN_fff97cf7`: before, `*in_R14 = 1` (a store through R14); 0xFFF97D04 is `SCEQ.L R14`, a register
  set, so the after side (`param_1 == 0` tests) is right. MAIN `other` (`FUN_fffb32fd`) and the `fewer_args` cases are argument fixes
  from `doc` rows: `ex_command` loses a bogus sixth argument (5 parameters per the doc row), `dsp_send_frame('r')` = `0x72`.
- MAIN `dropped_result` outside `nib2hex` (`vfo_store_back`, `beep_request`, `swtimer_start`, `FUN_fffc8d8c`, … 19 call sites, 50
  flags in all): with a scripted R1 check after every such `BSR`, none of them reads R1 again: they are tail calls before `RTSD` or
  R1 is overwritten. Before, the C passed a leftover R1 back as a fake return (`cat_AO` returned `undefined2 *`); now it is `void`
  **[inference: the callers of those handlers ignore R1]**. `FUN_fffc8d8c` takes the result of `FUN_fffc8cbb(40)` in R1 as its
  argument (0xFFFA6C83/0xFFFA6C87); both sides drop it, so it is not new.
- MAIN `string_as_int` (329 functions): 325 of the 339 sites are the `smovf` source operand (`smovf(local_38 + 6,0xfff85866,0x15)`
  where the before side printed a truncated literal of a whole string table in a copy loop). Only 5 sites come from drafted `asm`
  signatures typed `uint32` instead of `char *` (`FUN_fffedd9a` in `_INIT_IOLIB` ×3: `"C:\\stdin"` → `0xfff8f2e9`; `sci4_send`).
  Readability, not semantics.
- DISPLAY `other`/`data`: label and type changes (`&DAT_20138410` → `FUN_20138410`, `DWORD_ARRAY_…`, `"RIFF"`/`"WAVE"` now shown in
  `wav_check_header`). One readability loss: `FUN_20100c7c` (printf core) now shows `&UNK_20154b64`/`DWORD_20154be0` where it
  showed `""`, `"-"`, `"+"`, `" "`; the T21e B8 data definitions replaced those short strings. The 11 removed functions are T21e's
  replaced late starts.
- HiFi4: none of the 69 removed functions is an entry in `entries_hifi4.tsv` (the `flix.dis` function list); 14 lie in SRAM
  rodata below 0x207000 and 48 lie inside a function that now decodes. The `boundary` class is functions that were cut short by a
  bad decode: `FUN_00207d58` 26 → 748 B (the next `flix.dis` entry is 0x208050), `FUN_0021b034` 17 → 63 B (before: a false
  "does not return" after `env_lock_mutex`). `FUN_002128e8` (classed `bundles`): before, a `flix()` placeholder and a call to the
  non-code address 0x1F65C0, `& extraout_a5`; after, `& 0xfffffffe` and `DAT_40001074 = 0x10000`. HiFi4 `other` = the special
  register ops: `rsr(CCOUNT)` → `rsr_ccount`, and one `wsr.ps a3` (0x227F4D) becomes six pcodeop calls `wsr_ps` … `wsr_ps_5`,
  likewise `xsr_excsave1` + `xsr_excsave1_1` (one per output of the iclass). Cosmetic **[inference]**.

**Real regression found (after side wrong, before side right): stores into a buffer that SMOVF copies.** 34 MAIN functions,
all in 0xFFFDE064–0xFFFE1774 (the CAT/AI reply builders that copy a local reply into 0x15E06 with `SMOVF`): 119 store statements
into the source buffer are gone (`lost_buffer_stores`, 30 functions), and in 17 functions the `nib2hex` result is called and
dropped (31 sites; each is followed by `MOV.B R1,n[R0]` or `MOV.B R1,n[R6]`). Example `FUN_fffe0ba1`: the before C builds `"SF00;"`
and sets `local_9[2]`/`local_9[3]` in a 26-way decision tree; the after C keeps the empty `if` tree and only
`smovf(0x15e06,local_9,…)`. The disassembly has the stores (0xFFFE0C0D `MOV.B #49,10[R0]` …) and then `SMOVF` from the stack, so
the before side is right. `FUN_fffdebd1` 0xFFFDEC0E: `BSR nib2hex` then `MOV.B R1,8[R0]`, gone in the after C. Cause: T21c's
`smovf()` pcodeop has no memory effect, so the decompiler treats those stores as dead. This is the regression T21d recorded
(26 lost values), but it is wider: it also loses constant stores (reply letters), not only call results. All 34 are classed
`insn` (the cause is the instruction fix), and the TSV flags them. A load from a buffer that `smovf` filled can be wrong in
the same way (`FUN_fffdf13a`: `smovf(&local_43,0xfff8f4ef,0x1c)`, then `local_43` becomes a 1-byte variable and the
`local_43[1]` stores are lost) **[inference for the load side]**. No other class has a semantic regression in the sample.

**REA.** REA 6.8.0 cannot diff a "before" that exists only as exported text: `compare_functions`/`find_changed_behavior` take
`analyze_function` Evidence from a binary opened now (the current SLEIGH), the CLI has no compare command for functions or
artifacts, and `rea inspect-artifact` on a tar of the old `decomp/main` did not finish in 300 s. Request:
scratchpad `rea-requests/T22e-pseudocode-version-diff.md`. The diff was done with `tools/decomp_behavior_diff.py`.

**Status:** done (2026-10-28).

### T22b
**Status:** done (2026-10-28). DISPLAY: T21e's jump tables, function starts and fragments recovered again independently.

**Result.** Jump tables: Ghidra right at all 87 sites (own agrees on all 86 it finds; rizin miscounts 7). Function starts: all 305
own-vs-Ghidra differences settled from the bytes: 199 Ghidra right, 37 same code (thunks, vectors), 6 own wrong, and Ghidra misses:
**0x2016385A** (T21e entry 2 B late), **0x2013FE64** (entry listed, function lost in the build) and **60 functions reached only by a
tail branch** that Ghidra merges into their single caller (convention; rows proposed). Fragments: 14 of T21e's 15 are no code; one
is the late entry. Fixes are listed below for the parent; nothing canonical was changed.

Plan (resumed after the first agent was cut off; its tool commits are kept, the comparison is re-run against the T21g canonical
`ghidra/FT710_DISPLAY` / `decomp/display/functions.tsv`):
1. Own analyser: `tools/arm_recover.py` (stdlib A32/Thumb-2 decoder, recursive descent from the vectors, BL/BLX targets, data
   pointers and prologues; the four jump-table idioms with the bound from the `cmp`; byte classes for the gaps). Shares no code or
   data with Ghidra, rizin or T21e.
2. rizin 0.9.1 (`-a arm -b 32 -m 0x20100000`, `aaa; aap; aanr`, `afbj` with `switch_op`) as the second non-Ghidra analyser.
3. Ghidra as REA runs it: `open_binary` raw-binary, provider `ghidra`, default auto-analysis, none of the T21e scripts
   (`list_procedures`). REA has no rizin provider for raw images (request `T22b-rizin-raw-arm.md`, T22f).
4. The canonical project's map (`tools/ghidra/CodeUnitMap.java` on a `-readOnly` scratch copy) plus `functions.tsv` and
   `DisplayJumpTables.java check` as the T21e result being verified.
5. `tools/arm_recover_compare.py` lines the four up (jump-table sites and case lists, function starts, bytes no analyser covers);
   every difference is classed, and each class is settled from the bytes (objdump / own decoder at the address).
6. Write-up here; real Ghidra misses get the exact `entries_display.tsv` / table fixes for the parent (no canonical rebuild).

**Inputs and runs [fact].** Image `build/FT-710_DISPLAY_V0108.bin` (SHA-256 `65a9b654…77bb`), `.text` 0x20100000–0x20165178.
(1) `arm_recover.py … --bound 20164f68=4 --objdump arm-none-eabi-objdump`: 98,921 instructions (96,006 A32, 2,915 T32), 2,142
starts, 115 computed-PC sites, 3 conflicts; objdump calls 3 recovered instructions undefined/unpredictable (0x2013A0BC
`ldrh r1,[r0,r1]!`, and 0x201649D0/0x201649D6, a Thumb desync settled below). (2) rizin 0.9.1, `-a arm -b 32 -m 0x20100000`,
`aaa; aap; aanr`, then `aflj` and `afbj @@F` (two runs, byte-identical output). (3) REA `open_binary` raw-binary, `arm`, base and entry
0x20100000, provider `ghidra`: Ghidra 12.1.4 default auto-analysis, no project scripts; `list_procedures` = 1,832 procedures
(evidence `ev_313cb0a3…b0ae5`). (4) The T21g canonical project, on a `-readOnly` scratch copy: `CodeUnitMap.java` (6,342 runs) and
`DisplayJumpTables.java check` (86 sites, 86 ok); `decomp/display/functions.tsv` (2,208 entries in `.text`; it leaves thunks out).
The comparison (`arm_recover_compare.py`) gives the same numbers as the first agent's run against T21e's fresh scratch export, so
the T21g canonical DISPLAY is T21e's result.

```sh
python3 -I tools/arm_recover.py build/FT-710_DISPLAY_V0108.bin OWN --bound 20164f68=4 --objdump arm-none-eabi-objdump
rizin -q -a arm -b 32 -m 0x20100000 -i anal.rz build/FT-710_DISPLAY_V0108.bin     # aaa; aap; aanr; aflj; Ps; then afbj @@F
tools/ghidra-headless.sh <copy> FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly -scriptPath tools/ghidra \
  -postScript CodeUnitMap.java map.tsv -postScript DisplayJumpTables.java check jt_check.tsv
python3 -I tools/arm_recover_compare.py --own OWN --rz-bbs rz_bbs.jsonl --rz-funcs rz_funcs.json \
  --ghidra canonical=decomp/display/functions.tsv --ghidra rea=rea_functions.tsv --ghidra-jt jt_check.tsv \
  --ghidra-map canonical=map.tsv --out CMP
```

**Jump tables [fact].** 87 table sites in all: T21e's 86 A32 sites (81 `ldr pc`, 5 `add pc`) and one Thumb `tbb` at 0x20164F68 in the
fplib (outside `DisplayJumpTables.java`'s A32 scope; Ghidra's decompiler builds that switch by itself, `switchD_20164f68`, cases 4–7
of `r6`).

| Pair | Sites both find | Same case count | Settled |
|---|---:|---:|---|
| own vs canonical Ghidra | 86 of 87 | **86 / 86** | own misses 0x20132EF0 (its function has no reference, below) |
| rizin vs canonical Ghidra | 87 of 87 | 80 / 87 | rizin wrong on all 7 |
| own vs rizin | 86 | 79 / 86 | rizin wrong on all 7 |

The seven rizin differences, from the bytes: the five `add pc,pc,rX,lsl #2` sites (0x2010054C, 0x201005A4, 0x201005D8, 0x201008BC,
0x2010E69C) get one case too many: at 0x2010054C `cmp r2,#9; addcc pc,pc,r2,lsl #2; b default` gives 9 cases 0x20100554–0x20100574,
and rizin adds 0x20100578, which is `ldr r4,[r3,r0,lsl #2]` of the case body. 0x20122644 (`cmp r1,#15; ldrcc pc,…`): the table is
15 words 0x2012264C–0x20122684; rizin stops at 13. 0x20164F68 `tbb [pc,ip]` after `and r6,#7; subs ip,r6,#4; bcs`: 4 byte entries
(09 0B 02 02 → 0x20164F7E, 0x20164F82, 0x20164F70, 0x20164F70); rizin gives 1. Own and Ghidra agree on all of it (own needs the
manual `--bound`, its CMP search does not read `subs`). 0x20132EF0 (6 cases) is in FUN_20132EE8, a leaf `ldr; cmp r0,#6; ldrcc pc;
bx lr` with six `ldr r0,=…; b 0x20101030` cases. No word in the image equals 0x20132EE8/9 and no branch reaches it, so own (which
only follows references and prologues) never decodes it; rizin and Ghidra (T21e `after_return_undef`) do, and both count 6.
**Ghidra's 87 tables are all right.**

**Function starts.** Counts in `.text` (canonical without its 38 thunks, which `functions.tsv` omits):

| Pair | Both | Only first | Only second |
|---|---:|---:|---:|
| own (2,137) vs canonical (2,208) | 2,020 | 117 | 188 |
| own vs rizin (2,672) | 1,971 | 166 | 701 |
| own vs REA Ghidra (1,832) | 1,807 | 330 | 25 |
| rizin vs canonical | 2,033 | 639 | 175 |
| REA Ghidra vs canonical | 1,803 | 29 | 405 |
| rizin vs REA Ghidra | 1,757 | 915 | 75 |

Every own-vs-canonical difference was classed and settled (per address:
[`T22b-display-start-diffs.tsv`](T22b-display-start-diffs.tsv)):

| Difference (count) | Verdict, from the bytes |
|---|---|
| own only: 36 thunks (7 exception vectors, `b`/veneer stubs) | same code: Ghidra has them as thunks, `functions.tsv` leaves thunks out **[fact: map]** |
| own only: **58 push-prologue functions reached only by a tail `b`** | **Ghidra merges them into the one function that tail-calls them** (non-contiguous body). Every one starts with `push {…,lr}`, every jump source sits after its own frame is popped (or it has none), and each has exactly one source function **[fact]**. Examples: 0x20157238 (`push {r4,lr}`) only from `afscope_store_frame` 0x20120D48 (`mov r1,r0; ldr r0,=…; b`), so `afscope_store_frame` is exported as 188 B; ten screen functions 0x2012B1BC…0x2012C0D8 inside `scr_select_popup` (4,200 B); 0x20117A68 inside `vdc5_channel_shutdown`. rizin also starts 27 of them, REA's plain Ghidra 1 (0x2015FA88). Proposed fix below |
| own only: 13 late starts | Ghidra's entry is 4–12 B earlier: `mov r2,r1; mov r1,r0` or `ldr r0,=obj` falling into the `push`; the earlier byte is the entry when anything points at it (0x201170C8, task "root", T_CTSK word 0x20165A4C), the others have no reference either way **[fact: bytes; inference: Ghidra's earliest coherent start is the entry]** |
| own only: 0x20100018 | IRQ vector `b 0x201001D8`; Ghidra's 0x20100014 is the reserved vector `nop` falling into it. Same code |
| own only: 0x20100050, 0x20139D04, 0x20140020 | own wrong: data values that happen to equal mid-function addresses (0x20100050 is the literal the reset code subtracts to find its load offset; the other two point after a `bl` / into straight-line code) |
| own only: 0x20164C34 | own wrong: its prologue seed matched `b6 b5` inside the 128-byte descending table 0x20164C00 (T21e leftover) |
| own only: 0x20156584 | own wrong: `push {r0,lr}` straight after `push {r0-r3}` inside the NORTi stub FUN_2015655C (falls in, not an entry) |
| own only: 0x20155D0A, 0x20163838 | **two more tail-only functions, reached through linker veneers** (Ghidra's references, read with a one-off read-only `AtAddr` script): 0x20155D0A (Thumb `push {r4-r11,lr}`) only from FUN_20100C7C 0x20100C7E `cmp r1,#0x66; beq.w 0x20165178`, where 0x20165178 is the Thumb veneer `b.w 0x20155D0A`; 0x20163838 (Thumb `push`) only from FUN_20107EE0 0x20107EF0 `b 0x20163830`, the A32 veneer `adr ip,0x20163839; bx ip`. Ghidra merges both into the caller, like the 58 **[fact]**. The veneer at 0x20165178 is the "1 stray instruction in .rodata" of `DisplayReport.java` (`docs/memory-maps.md`): own's `--text-end` stops just before it |
| own only: **0x2016385A** / canonical only: 0x2016385C | **Ghidra miss: entry 2 B late.** The .data word 0x2042807C is 0x2016385B, so the Thumb entry is 0x2016385A: `movs r0,#0; push {r4,lr}; bl 0x20155FDE; pop {r4,pc}`. T21e's `entries_display.tsv` row says 0x2016385C (it cleared one bit too many); the `movs r0,#0` is left as an undefined fragment and the exported function loses its argument **[fact]** |
| own only: **0x2013FE64** | **Ghidra miss: no function.** `b 0x2014030C`, pointed to by the .data words 0x204205E8 and 0x204205F4 (a function-pointer table). It is a row in `entries_display.tsv` (`after_return_undef`), but the canonical project has code and no function there, and no reference to it (the two .data words are not typed as pointers) **[fact: AtAddr]**. T21e's fresh-build log says FixFuncEntries created all 205 entries with 0 failures, and T21e's and T21g's `DisplayGaps` reports still list 0x2013FE64 as an `after_return` candidate afterwards, so a later bootstrap step removes the one-instruction function; which one was not determined (no intermediate project) |
| canonical only: 62 starts at jump targets inside own code | Ghidra right: every one is entered by a `b` (one `bne`) from code of another Ghidra function, 37 of them from two to nine functions (shared tails: `rspi*_spri/spti_isr` → 0x2011F840/0x2011F89C, eight callers → 0x2011D860, `backlight_set/init` → 0x20102698, fplib tails 0x20164654…) **[fact]**; own only starts functions at calls, pointers and prologues |
| canonical only: 126 starts own never decodes as one (114 in own "unknown", 9 in own "ref_data", 2 inside own code, 1 own conflict) | Ghidra right for 125: each decodes with own's decoder as straight-line code that ends in a return/branch or runs into known code, none hits an undefined encoding; 90 are T21e `after_return_undef` rows, 88 are rizin starts too. Most have no reference own can see (dead or computed-pointer code, as T21e found); 0x201170C8 is the "root" task (descriptor), 0x201567D0 the address-taken NORTi stub, and 0x201649D8 has 41 `bl`s (own flagged a Thumb overlap after it decoded 0x20164994… through the undefined 0x201649D0/D6: own bug). The 126th is 0x2016385C (late entry, above) |

REA's plain Ghidra (default analysis, no T11/T21e scripts) lacks 405 canonical starts (the reviewed entries and the scripts'
work); of its 29 starts that the canonical `functions.tsv` lacks, 28 are thunks the canonical project also has, and one is
0x2015FA88, one of the 58 tail-only functions. rizin's 639 extra starts are mostly false: 353 on literal pools, 75 on other data
(strings, zero runs, referenced data), 89 in the middle of functions with no reference (after calls it treats as no-return),
the rest at jump targets **[fact: own and Ghidra both class those bytes as data / mid-function]**.

**Fragments [fact].** The canonical project has 15 undefined runs in `.text` with 242 non-0xFF bytes (243 B), T21e's numbers. 141 B in
11 of them are covered by neither rizin nor Ghidra. Own classes those bytes as data or unknown, except: 0x2016385A (2 B, real code,
the late entry above), 0x20164C34 (46 B, own's false Thumb function on the table) and 0x201649D2 (2 B, own's desync). So
**14 of the 15 fragments are no reachable code for own and Ghidra; one (0x2016385A) is the first instruction of a real function.**
rizin's blocks run over parts of 0x20164C00 (the descending byte table), 0x2015497E, 0x20155B5A, 0x2015625C, 0x20164CEC, 0x20164D48
**[inference: rizin linear block extension over padding/tables]**.

**Proposed fixes for the parent (not applied; canonical projects untouched).**
1. `tools/ghidra/entries_display.tsv`: change row `2016385c thumb …` to `2016385a thumb dataptr (Thumb): movs r0,#0; push {r4,lr};
   bl 0x20155fde; pop -- .data word 0x2042807c = 0x2016385b`.
2. 0x2013FE64: the row is already in `entries_display.tsv`; find the step after FixFuncEntries that deletes it (candidates:
   `DisplayJumpTables apply`'s orphan removal, `DisplayGaps define`), or re-create it at the end, and mark the .data words
   0x204205E8 and 0x204205F4 as pointers so it has references. Check: `DisplayGaps` no longer lists it.
3. Optional, a convention choice: 60 `tail_only` rows (58 direct, 2 through veneers; ready to append:
   [`T22b-entries-proposed.tsv`](T22b-entries-proposed.tsv)) would make the tail-called functions their own functions. Effect: the
   60 get `FUN_` names, their callers' C shrinks to the call, and `decomp_quality.py compare` will count new functions. T21e's
   `tail_target` rule covered targets inside *another* function's body; these are targets Ghidra absorbed because only one
   function reaches them.
4. Not a fix, a note: the reserved vector 0x20100014 (`nop`) and the IRQ vector 0x20100018 are one Ghidra function; harmless.

REA: the raw-ARM rizin gaps are in `T22b-rizin-raw-arm.md` (scratchpad `rea-requests/`, T22f). REA's Ghidra lane was used as filed.

**Step 3 — the HiFi4 image in REA (fork CLI, `Xtensa:LE:32:rt600hifi4`).** REA fork `~/opt/rea` branch `feat-ft710-devices`
with T22f's raw `xtensa-hifi4` lane (the state T22f's `t22f-ready.md` names), Ghidra 12.1.4, run as
`python3 -I tools/memgate.py 2700 -- node ~/opt/rea/scripts/rea.mjs <cmd> build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin
--target-format raw-binary --architecture xtensa-hifi4 --base-address 0x200000 --entry-point <e> --provider ghidra` with
`JAVA_TOOL_OPTIONS=-Xmx2g`, `GHIDRA_INSTALL_DIR`, `JAVA_HOME` set (REA maps one file, so only the SRAM image: the canonical
project's 14 TCM functions at 0x2402xxxx are out of scope; compared against the 1,067 canonical SRAM functions).

B9 **[fact]**: `decompile … 0x20bb74` (entry 0x20bb74) returns C for `FUN_0020bb74` with no `halt_baddata`, no `flix()` and no
warning. After normalising `PTR_DAT_`/`DAT_` names and whitespace it is identical to T21b's oracle decompile `b9.txt` (same
language, raw SRAM without read-only rodata) except for four `(uint)` casts in front of mask literals. The canonical export
differs only because its rodata block is read-only, so literals fold (`DAT_40001040` instead of `*(DAT_00206504 + 0x240)`).

Run A, `decompile-all`, entry 0x21C498 (DSP `main`), **no seeds** (REA's own discovery from one entry) **[fact]**:

| | canonical (SRAM part) | REA run A |
|---|---:|---:|
| functions | 1,067 | 940 (all written, 0 failures) |
| same entry / same entry and body size | | 930 / 924 |
| warnings (functions) | 255 (96) | 215 (48) |
| `halt_baddata` | 1 (`FUN_00218480`, 3 bytes) | 0 (0x218480 is not a function in REA) |

Warning kinds differ only where the function sets differ (26 "Globals starting with '_'" come from canonical names, which REA
does not have). Of the 6 common functions with a different body, `0x22C5B0` is the big one: canonical 8,131 bytes / 17
warnings, REA 3,098 bytes / 150 warnings (147 "Removing unreachable block"), so with only one entry Ghidra cuts this function
where the seeded project does not **[fact]**. **REA finds 9 functions the canonical project does not have, none inside a
canonical function** **[fact]**: 0x209DB8 (`entry a1, 48`), 0x20D530 (`entry a1, 32`), 0x22672C (the uncalled
interrupt-registration function from step 2), 0x226A24, 0x228FDC, 0x2291C0, 0x2291D8 (`rsr.cpenable` first: an XOS coprocessor
context routine **[inference]**), 0x2291FC, 0x22C4A0. Follow-up for `entries_hifi4.tsv` (T21b/T21g owners): add them after a
check of each. Per-function table: scratchpad `t22c/runA/cmp.tsv`, script `t22c/cmp.py`.

Run B, the same with `REA_GHIDRA_SEED_FILE` = the 1,067 SRAM entries of `entries_hifi4.tsv` (all 1,067 seeds decoded, 0
failed) — the like-for-like comparison **[fact]**:

| | canonical (SRAM part) | REA run B |
|---|---:|---:|
| functions | 1,067 | 1,075 (all written, **0 failures**) |
| same entry / same entry and body size | | **1,065 / 1,059** |
| canonical only | | 2: 0x218480 (inside REA's `0x217D10` body), 0x233818 (REA's `0x233670` is 768 bytes = canonical 631 + 137) |
| REA only | | 10: the 9 of run A plus 0x22C3E0 (inside canonical `FUN_0022c3bc`) |
| warnings (functions) | 255 (96) | 266 (55) |
| `halt_baddata` | 1 (`FUN_00218480`) | **0** |

So with the same entries REA reproduces the canonical function list to 99.8 % and decompiles everything; the canonical project's
only `halt_baddata` is a 3-byte seed fragment inside `FUN_00217d10` that REA's Ghidra does not keep as a function. Warning
differences **[fact]**: the canonical-only ones are 26 "Globals starting with '_'" (from canonical names) and the one bad
instruction in 0x218480; REA has 5 more "Could not recover jumptable" (+5 "indirect jump as call", +35 "Removing unreachable
block") at 0x2095A1, 0x220F1D, 0x2231EA, 0x22C735, 0x231167. Those are the 6 functions whose bodies differ (`0x209590`
24 vs 264 bytes, `0x220EE0`, `0x22313C`, `0x22C5B0` 3,098 vs 8,131 with 0x22D1CA..0x22E573 in no function, `0x231040`,
`0x233670`). Cause **[fact: setup; inference: effect]**: the canonical project makes 0x200000.. (rodata/literals) non-writable
(`IfdspHifi4Setup.java` line 58) so the decompiler folds `l32r` table bases; REA maps the raw file as one writable block. Not a
language problem: the decode is identical. REA gap filed for T22f: scratchpad `rea-requests/T22c-raw-readonly-range.md`
(read-only ranges for raw images). Table: scratchpad `t22c/runB/cmp.tsv`.

**T22c result.** The generated language holds up in a third and fourth decoder (rizin for the base ISA, the hand decoder for
everything) and in an independent tool chain (REA): B9 decompiles in REA, and REA's seeded function list and decompile match
the canonical `decomp/ifdsp/hifi4` except for the read-only-literal effect above. Follow-ups: the 9 REA-found functions for
`entries_hifi4.tsv` (above), and the REA read-only-range request.

### T22d
**Status:** done (2026-10-28). All images: classify the undefined non-0xFF bytes left in executable blocks (T21f baseline:
MAIN 20,622, DISPLAY 4,258, M33 5,162, HiFi4 186,167).

Plan:
1. `tools/ghidra/UndefinedRanges.java` exports the undefined ranges (the same set `ExportDecomp.java` counts) from `-readOnly` copies
   of the canonical projects in scratch.
2. `tools/undefined_classify.py` classifies every range from the raw image only (Ghidra's range list is the only input taken from
   Ghidra): padding/fill, ASCII / UTF-16LE / Shift-JIS strings, pointer tables (words that point into the image per
   `docs/memory-maps.md`), float32 and small-integer tables, code (disassembled with a non-Ghidra decoder: `rx-elf-objdump` for RX,
   `arm-none-eabi-objdump` for A32/T32, the Zephyr RT600 objdump for HiFi4, rizin as a second opinion), and unknown. Inbound
   pointers to a sub-run from anywhere in the image are recorded as evidence. One TSV per image (range, size, class, evidence).
3. After T21d/T21e land on `issue-97-ghidra-gaps`: compare their definitions with these classes; list what is still unexplained
   (addresses) as the T21g follow-up.

Plan, revised 2026-10-28 (resumed after the first agent stopped at "classifier v2, T21e compare done"): the baseline above is
pre-T21. T21g rebuilt and re-exported every program; `decomp/*/quality.tsv` now count **MAIN 161, DISPLAY 242, M33 5,162,
HiFi4 29,161**. So:
4. Re-run `UndefinedRanges.java` on scratch copies of the T21g canonical projects (`ghidra/FT710_{MAIN,DISPLAY,IFDSP}`,
   `-readOnly`, memgate 3G/2G + 700 MB) and check each total against `quality.tsv`.
5. Finish the classifier (float32 tables from the WIP commit) and classify the four new range lists; cross-check samples with REA
   (`inspect_byte_entropy`, `search_strings`, `inspect_firmware_regions`) and rizin. MAIN's 161 B are being decoded by T21h:
   classify only, no deep decode.
6. Per image: bytes per class, and for each class whether Ghidra should define it (how: script/bootstrap step) or leave it.
   Commit a modest per-range TSV, document the tools in `tools/README.md`.
REA tools used for cross-checks: `inspect_byte_entropy`, `search_strings`, `search_bytes`, `inspect_firmware_regions`.

**Step 4 — ranges from the T21g projects [fact].** `UndefinedRanges.java` on `-readOnly` scratch copies of the committed
`ghidra/FT710_{MAIN,DISPLAY,IFDSP}` gives MAIN 2 ranges / 161 B, DISPLAY 15 / 242 B, M33 178 / 5,162 B, HiFi4 1,722 / 29,161 B:
the same totals as `decomp/*/quality.tsv`.

**Step 5 — classifier v3.** Changes against the first agent's v2, each from a false class seen in this run: (a) a run where more
than 1 in 4 decoded instructions are all-zero bytes is not code (M33 0x87AD0: a u32 register table read as Thumb `movs r0, r0`
plus one `bmi`); (b) HiFi4 bytes count as `flix.dis` code only when a whole `flix.dis` instruction lies inside the undefined
range: one that runs into a Ghidra instruction is a sweep artefact (T22c: Ghidra's starts are right in all 337 conflict
regions), which turned 629 B of 1–2-byte "code" between functions back into zero padding; (c) float32 runs (>= 8 words,
1e-30 <= |x| <= 1e10, half of them 1e-6..1e7, so libm hi/lo pairs count) and runs of u32 byte values are found before the string
pass, so tables are no longer cut into "strings" such as `'1bA'`. Every class below was then checked by hand against objdump
(and REA, step 6) at the addresses given.

```sh
tools/ghidra-headless.sh <scratch> FT710_IFDSP_T22d -process FT-710_IFDSP_V0101_hifi4.bin -noanalysis -readOnly \
  -scriptPath tools/ghidra -postScript UndefinedRanges.java hifi4.ghidra.tsv
python3 -I tools/undefined_classify.py hifi4 hifi4.ghidra.tsv hifi4.tsv --flix decomp/ifdsp/hifi4/flix.dis   # main|display|m33 likewise
```

Per-sub-run result without the padding rows (196 rows): [`T22d-undefined-classes.tsv`](T22d-undefined-classes.tsv).

**Bytes per class (non-0xFF bytes, after the hand review; the classifier's own class in brackets where it differs).**

| Class | MAIN | DISPLAY | M33 | HiFi4 | Ghidra should… |
|---|---:|---:|---:|---:|---|
| code, reached | 161 | 64 | 4 | 82 | **define** (details below) |
| code, unreached stubs / dead | 0 | 4 | 8 | 5 | may leave; or disassemble without a function |
| float32 tables | 0 | 0 | 0 | 19,523 | **define** (HiFi4 rodata: split the block, apply `float[]`) |
| int / struct tables | 0 | 127 | 952 | 1,281 | define as arrays (cheap, cosmetic) |
| strings | 0 | 27 [11 unknown, 12 int, 4 pad] | 29 | 83 | define (cosmetic) |
| pointers, literals, other referenced words | 0 | 8 [unknown] | 24 | 256 | define as `addr`/`dword` |
| padding (zero fill, alignment `nop`s) | 0 | 6 | 4,114 | 7,345 | **leave** |
| unknown | 0 | 6 | 31 | 586 | leave (listed in the TSV) |
| **total** | **161** | **242** | **5,162** | **29,161** | |

Region split [fact]: M33 `flexspi_xip` 4,211 B (3,584 B zero fill of the boot header around the FCFB, 512 B FCFB, the rest
handlers/strings at 0x08001xxx) and `sram_text_rodata` 951 B. HiFi4: SRAM rodata 0x200000–0x207CEF 22,704 B, `.text`
0x207CF0– 5,481 B (5,388 B zero padding between functions), ITCM 976 B (971 B zero fill between the vectors).

Findings per image:
- **MAIN (161 B)** — both runs are RX code reached by branches [fact]: 0xFFF8FEC0–0xFFF8FEF4 (52 B, branch from 0xFFF8FF2E) and
  0xFFF91295–0xFFF91302 (109 B, ends in `rtsd`, branch from 0xFFF912E0). These are T21h's two fragments; not decoded further here.
- **DISPLAY (242 B)**, all in the armcc Thumb library [fact unless marked]:
  - fplib code reached through the inline-parameter return of `bl 0x20164EFC` (the handler reads the word after the call and returns
    to `lr + 4 + 4·n`, so the slots after the word are code that no static flow reaches): 0x20164988 (12 B), 0x20164BDC (14),
    0x20164CEC (2), 0x20164D48 (2), 0x20164ECC (14), 0x20164EE2 (18). The inline words themselves: 0x201649D0 (`0x3EBEFB64`),
    and 0x20164EF8 is the literal `0x7FF80000` (double NaN high word) of `ldr r1,[pc,#4]` at 0x20164EF0.
  - **0x2016385A: T21e's Thumb entry 0x2016385C is 2 bytes late.** The `.data` function-table word at 0x2042807C is `0x2016385B`,
    so the function starts with `movs r0, #0` at 0x2016385A; Ghidra's `FUN_2016385c` loses that argument. Fix: `2016385a thumb`
    in `entries_display.tsv` (with `drop` for 0x2016385C).
  - `bx lr` stubs with no reference: 0x20155B5A, 0x2015625C (2 B each) — empty library functions [inference]; leave.
  - 0x20164C00: 128-byte falling table `ff fd fb … 82 81 81 80`, the reciprocal seed table of the fplib divider (`addw r6, pc,
    #320; ldrb r6, [r6, r5]` at 0x20164A3C) → `byte[128]`.
  - 0x20154B64 and 0x20154BE0: two 16-byte tables of 4-byte NUL-padded strings `""`, `"-"`, `"+"`, `" "` (the printf sign prefix,
    selected by `adr r6, …` at 0x20154B88–0x20154BB2 and its twin) → `char[4][4]`.
  - 0x2015497E: `nop` (alignment) + word `0x0000EEF5` in front of the ARM function 0x20154984; no reference found [unknown].
- **M33 (5,162 B)**:
  - **0x0800143C: `FUN_0800143e` starts 2 bytes late.** The word at 0x080015C8 is `0x0800143D`; the function begins with
    `ldr r3, [pc, #236]` at 0x0800143C. Same pattern as DISPLAY 0x2016385A → add the entry 0x0800143C (Thumb).
  - 0x00087232: `bx lr` with the pointer `0x00087233` at 0x00080A10 → an empty function that is called through a pointer; define it.
  - 0x0800120E, 0x08001218, 0x0800121C: `b .` default handlers next to `NMI_Handler` (0x0800120C) with no vector pointing to them
    [fact: no image word]; leave.
  - 0x08000400–0x080005FF: the FlexSPI NOR configuration block (FCFB) → apply a 512-byte struct (`docs/memory-maps.md`); 0x08000000–
    0x080003FF and 0x08000600–0x08000FFF are zero fill.
  - 0x00087D84: 256-byte C `ctype` table (digits 0x20, upper 0x10, lower 0x08) → `byte[256]`; the strings `"r"`, `"w"`, `"0x"`,
    `"0X"`, `"db"`, `"DB"`, `"IDLE"` and the pointer to `"Cortex-M33"` at 0x08001830 are all referenced → define.
  - 147 single `nop` (2 B) and two `nop` runs: Thumb alignment between functions; leave.
- **HiFi4 (29,161 B)**:
  - **Rodata in an executable block.** 22,704 B lie in 0x200000–0x207CEF, the rodata and `l32r` literal pool in front of the first
    function (0x207CF0), which `IfdspHifi4Setup.java` puts in the executable block `sram_dsp_text`. 19,523 B of it are float32
    tables: FFT twiddles (cos/sin pairs at 0x200D18, 763 words, and 0x201918, 1,532 words), FIR/window coefficients and
    rising/falling ramps (0x203124–0x2035BF, 0x20360C–0x20388B, 0x2038E4–0x203A7B, 0x20537C–0x20553B), libm tables (0x205A40
    `n·π/2` high parts, 0x2058D0 hi/lo pairs). 1,281 B more are int tables, among them libm's `two_over_pi[]` at 0x205AA0 (the
    bytes `a2 f9 83 6e 4e 44 15 29 …` stored as int32, about 200 words, pointer from the literal at 0x207A24). Strings: the XOS/libm
    names `idle`, `join`, `cond`, `sem`, `msgq`, `powf`, `inf`, `NAN`, `nan`, `NaN` at 0x2063C4–0x206477.
  - **Code Ghidra misses (82 B):** 0x228B08–0x228B32 (41 B, reached only through the `l32r` literal at 0x207864, loaded at 0x227850;
    an idle routine ending in `waiti 0; j .`); 0x2316F1–0x2316FE (13 B, a switch case: the pointer table at 0x206290 holds
    0x2316F1, 0x231549, 0x231517, so Ghidra did not recover that jump table); 0x2287FC–0x228815 (26 B, a level-2 interrupt
    epilogue: `l32r`/`callx0` hook, `rsr.excsave2 a0; rfi 2`; no pointer found, so it is reached by computed flow
    [inference]); 2 B inside `FUN_00218480` (data, T21a). Not reached: 0x240205FF `break 1, 15; j .` in the ITCM (5 B).
  - 7,345 B of zero padding: 4-byte function alignment in `.text` and fill between the ITCM vectors. Leave.
  - 586 B unknown (including 6 B of rodata the classifier took for `call0`), mostly between the rodata tables (0x205960–0x206130: mixed libm constants); none in `.text` except 9 B next to
    `FUN_00218480` and 3 B at 0x233815 (a `flix.dis` bundle that overlaps Ghidra's `entry` at 0x233818, so padding [inference]).

**Step 6 — REA cross-check [fact].** `rea inspect-byte-entropy` (REA 6.8.0, through `memgate.py 2748`) on the HiFi4 SRAM image
(file offset 0x20644, 4 KiB blocks): the rodata blocks 0x203000–0x204FFF have 7.34 and 7.27 bits/byte, inside the range of the
FLIX code blocks (6.5–7.43), and REA marks them `high` like code; only 0x206000 (strings, small ints, 5.47) stands out. So
block entropy cannot tell the float tables from code; the byte-level classes above (word plausibility, decode, inbound
references) are needed. REA's string search was not run: it needs an analysed REA session per image, and the machine was short
of memory (the entropy run waited about 40 minutes in memgate); the strings above were checked with objdump/hexdump instead.

**Recommended Ghidra fixes (for a T21 follow-up; nothing here was applied to the canonical projects):**
1. `IfdspHifi4Setup.java`: split 0x200000–0x207CEF out of `sram_dsp_text` into a read-only, non-executable `sram_rodata` block.
   This alone removes 22,704 of HiFi4's 29,161 B from the metric and stops the decompiler treating the tables as code space; then
   a small script applies `float[n]` / `int[n]` / strings from `T22d-undefined-classes.tsv` (the float tables matter for reading
   the filter code, which loads them by `l32r`).
2. Entries: DISPLAY 0x2016385A (Thumb, replaces 0x2016385C) and M33 0x0800143C (replaces 0x0800143E): both pointer-proven entries
   2 bytes before the current function. M33 0x00087232 (empty function, pointer at 0x00080A10).
3. HiFi4: disassemble 0x228B08 (code pointer in the literal pool; T22c's flow pass adds such pointers, `IfdspHifi4FindFuncs.java`
   does not), recover the switch at 0x206290 (case 0x2316F1), and disassemble 0x2287FC.
4. MAIN: T21h's two fragments (in progress there).
5. DISPLAY/M33 small data (fplib reciprocal table, printf sign strings, `ctype`, FCFB struct, literals): optional, cosmetic.
6. Leave: zero fill, alignment `nop`s, the unreferenced `bx lr` / `b .` / `break; j .` stubs and the unknown bytes.


## Findings

## Follow-ups
- T22e → T21/T21h: give the RX string pcodeops (`smovf`/`smovb`/`smovu`/`sstr`) a memory effect (or keep the copy loop for them).
  Until then 34 MAIN reply builders (0xFFFDE064–0xFFFE1774) lose their reply bytes in the C. Re-run `tools/decomp_behavior_diff.py`
  after that: `lost_buffer_stores` and `dropped_result=F_fffb2e9c` should go to 0.
- T22e: optional cosmetic fixes. In the HiFi4 generator, one pcodeop per special-register write instead of one per iclass output
  (`wsr_ps` ×6, `xsr_excsave1` ×2). In DISPLAY, `0x20154B64`–`0x20154BE0` should be strings again (`""`, `"-"`, `"+"`, `" "`), not
  dwords.
