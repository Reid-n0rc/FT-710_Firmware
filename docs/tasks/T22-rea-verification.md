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
**Status:** in progress (2026-10-28). IFDSP HiFi4.

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
  the conflict regions below) **[inference]**.

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

### T22d
**Status:** in progress (2026-10-28). All images: classify the undefined non-0xFF bytes left in executable blocks (T21f baseline:
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
REA tools used for cross-checks: `inspect_byte_entropy`, `search_strings`, `search_bytes`, `inspect_firmware_regions`.


## Findings

## Follow-ups
