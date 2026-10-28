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

## Findings

## Follow-ups
