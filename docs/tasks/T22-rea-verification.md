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
