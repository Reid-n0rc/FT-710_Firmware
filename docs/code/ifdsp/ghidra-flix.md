# What Ghidra needs to decode the HiFi4 FLIX bundles

Ghidra 12.1.4 cannot decode most of the IF DSP's HiFi4 code, so `decomp/ifdsp/hifi4/` is close to useless and the DSP is known
mainly from an objdump listing (`decomp/ifdsp/hifi4/flix.dis`). This page measures the gap, says exactly what is missing, and
proposes how to close it. Issues: [#97](https://github.com/Reid-n0rc/FT-710_Firmware/issues/97) (the decompile) and
[FT-710_Custom_Firmware#1](https://github.com/Reid-n0rc/FT-710_Custom_Firmware/issues/1) (RADE in the DSP, formerly #102, which needs this code understood). Claims are
tagged **[fact]**, **[inference]** or **[guess]**; counts come from `flix.dis` (V01-01, 1,065 functions) and the core's ISA
description, and are reproducible with the commands at the end.

## The gap in numbers

| Measure | Value |
|---|---|
| HiFi4 functions (FLIX listing) | 1,065, with 49,389 instructions in 188,006 bytes (plus 461 single padding bytes the listing shows as `.byte`) **[fact]** |
| Functions that contain at least one FLIX bundle | **891 (84 %)** **[fact]** |
| FLIX bundles | **12,676**: 26 % of the instructions, **46 % of the code bytes** **[fact]** |
| Bundle sizes | 10,438 × 6 bytes (48-bit), 2,238 × 11 bytes (88-bit) **[fact]** |
| Slots per bundle | 2 slots: 10,173; 3 slots: 817; 4 slots: 1,686 **[fact]** |
| Bundles with a branch or loop in a slot | **2,387 (19 %)**, e.g. `beqz.w15` 425, `beqi.w15` 311, `loop`/`loopgtz`/`loopnez` 154 **[fact]** |
| Bundles where one slot writes a register another slot names | about 1,465 (12 %), so slots must read before any slot writes **[inference: operand heuristic]** |
| Distinct operations used | 476 (239 inside bundles, 351 outside) **[fact]** |
| … not in Ghidra's Xtensa module | **197**: 158 HiFi4 `ae_*` plus 39 FPU and other ops (`div0.s`, `recip0.s`, `f64*`, `maddn.s`, …); 6,508 of 66,254 operations (9.8 %) **[fact]** |
| … in Ghidra's module but on the wrong registers | **30 FPU ops** (`mul.s`, `add.s`, `sub.s`, `madd.s`, `wfr`, …), 3,159 uses: this core's FPU works on the 64-bit `aed` registers, Ghidra's on `f0..f15` **[fact]** |
| Operations Ghidra cannot represent correctly | about **14.6 %** of all operations (the two rows above) **[fact]** |
| What Ghidra does today | `op0 = 0xE` becomes a 3-byte placeholder `FLIX` (the real bundle is 6 bytes, so the next instructions are decoded from the middle of the bundle); `op0 = 0xF` (the 11-byte bundles) has no constructor, so disassembly stops; one function (`FUN_0020bb74`) crashes the decompiler **[fact: `flix.sinc`, `xtensaArch.sinc`, `decomp/ifdsp/INDEX.md`]** |

So even with the FLIX listing, the DSP has **no usable decompiled C**: every reading of the audio chain is done from assembly.

## What the core is

The RT600's HiFi4 is a configured Xtensa core. Its exact instruction set is published as a generated C file,
`xtensa-modules.c`, in Zephyr's SDK repository:
[`sdk-ng/overlays/xtensa_nxp_rt600_adsp/binutils/bfd/xtensa-modules.c`](https://github.com/zephyrproject-rtos/sdk-ng/blob/main/overlays/xtensa_nxp_rt600_adsp/binutils/bfd/xtensa-modules.c)
(2,996,889 bytes, last changed in commit `15daabb` on 2023-12-11, SHA-256 `9e218b19…f372`). It is the same description the Zephyr
objdump is built with, so it matches this firmware exactly **[inference: the objdump decodes every bundle in the image]**. It is
**MIT-licensed** by Cadence ("Permission is hereby granted, free of charge … to use, copy, modify, merge, publish, distribute"), so
SLEIGH generated from it can be committed **[fact: file header]**.

| Item in `xtensa-modules.c` | Count | Notes |
|---|---|---|
| Formats | 10 | `x24`, `x16a`, `x16b` (the base ISA) and 7 FLIX formats: `ae_format48`, `ae_format48_2`, `ae_format48_3` (6 bytes, `op0 = 0xE`), `ae_format88`, `ae_format88_2/_3/_4` (11 bytes, `op0 = 0xF`) **[fact: `formats[]`, `format_decoder`]** |
| Slots | 25 | each with a `get` function that gathers the slot's bits from the bundle; they are **scattered**, e.g. `ae_slot0` of `ae_format88` is assembled from 6 pieces in 3 words **[fact]** |
| Opcodes | 1,713 | 5,857 opcode-in-slot encodings (one opcode can sit in several slots) **[fact]** |
| Operands / fields | 554 / 406 | immediates have encode/decode functions (scaling, sign, offsets) **[fact]** |
| Instruction classes | 1,548 | each lists its operands as in/out/inout and the processor states it reads and writes **[fact]** |
| Register files | 10 | `AR` (32 × 32-bit), `AE_DR` (16 × 64-bit), `AE_VALIGN` (4 × 64), `AE_EP` (4 × 8), `MR`, `BR` and its 2/4/8/16-bit views **[fact]** |
| States / special registers | 83 / 74 | **[fact]** |

## What Ghidra needs

1. **Length and format decode.** Constructors for the 7 FLIX formats with their true lengths (6 and 11 bytes), selected by the
   same bit tests as `format_decoder`. This alone stops the desynchronisation.
2. **Slot extraction.** For each of the 25 slots, the bit pieces from the slot's `get` function, as SLEIGH fields. libisa works on
   the bundle as 32-bit little-endian words (`insn[0..2]`); mirroring that (tokens of 32 + 16 or 32 + 32 + 24 bits) makes every
   piece a plain field **[inference]**.
3. **Opcodes per slot.** One constructor per opcode-in-slot encoding, from each slot's `decode` function. Only the 476 operations
   the firmware uses are needed at first; the generator can emit all 5,857 later.
4. **Operands.** Fields → operand values through the operand decode functions (written as SLEIGH disassembly expressions).
5. **Registers.** `AE_DR` (`aed0..15`, 64-bit), `AE_VALIGN`, `AE_EP`, `MR`, the `BR` views, and the HiFi4 states and user
   registers, added to the language. The 30 FPU ops must be re-pointed from `f0..f15` to the low 32 bits of `aed0..15`.
6. **Semantics.** Three levels, in order of value:
   - base-ISA ops inside slots: reuse the existing Ghidra p-code (with the `.w15` branch forms mapped to the normal branches);
   - `ae_*` and the 39 missing FPU ops: a named p-code operation per opcode with the right inputs and outputs, taken from the
     instruction class (in/out operands and states). The decompiler then tracks data flow correctly even without the arithmetic;
   - exact arithmetic for the few kernels that matter (for example the multiply-accumulates in the filters), later and by hand.
7. **Parallel execution.** All slots of a bundle read their inputs before any slot writes. The generated bundle constructor must
   compute each slot into temporaries and commit afterwards; about 12 % of bundles depend on this.
8. **Control flow in slots.** Branches and zero-overhead loops inside a slot (2,387 bundles) need the existing branch and loop
   semantics, with targets relative to the bundle start.
9. **A test oracle.** Ghidra's listing compared with `flix.dis` for all 49,389 instructions: length, mnemonic and operands must
   match.

## How to get there

| Option | What it gives | Effort **[guess]** |
|---|---|---|
| **A. Generator** (recommended): a script that reads `xtensa-modules.c` and writes a SLEIGH extension (`.sinc` files plus language and pspec entries) for this core | correct disassembly of all 49,389 instructions; decompiler data flow through `ae_*` ops as named operations; re-runnable for other Xtensa cores | large: a few thousand lines of generator, mostly mechanical, because the C file is regular generated code |
| **B. Length and control flow only**: the 7 formats with correct lengths plus the branch and loop slots; every other slot a single opaque operation | function boundaries and control-flow graphs right, so the decompiler no longer breaks; no data flow through HiFi4 ops | small to medium, and a first step of A |
| **C. Stay with the objdump listing** (today) | readable assembly for every function; no decompiler | none |

Recommended order: B as the first milestone of A (it already fixes the 84 % of functions that break), then the `ae_*` ops as named
operations with correct in/out, then the parallel commit, then exact semantics only where an algorithm needs them. Every step is
checked against `flix.dis`. Nothing here touches the radio.

Open points: whether SLEIGH accepts the 11-byte bundles as one constructor across three tokens without problems
**[inference: Ghidra allows instructions up to 16 bytes]**; how the decompiler copes with about 1,700 named p-code operations;
whether `FUN_0020bb74` still crashes once its bundles decode.

## Reproduce the counts

```sh
python3 -I tools/flix_stats.py      # every count in "The gap in numbers" (Ghidra dir defaults to the Homebrew install)
curl -L -o xtensa-modules.c https://raw.githubusercontent.com/zephyrproject-rtos/sdk-ng/main/overlays/xtensa_nxp_rt600_adsp/binutils/bfd/xtensa-modules.c
sed -n '/^xtensa_isa_internal xtensa_modules = {/,/^};/p' xtensa-modules.c     # formats, slots, operands, iclasses, opcodes, regfiles
grep -c "Opcode_.*_Slot_.*_encode" xtensa-modules.c                             # 5857 opcode-in-slot encodings
grep -h -oE "^:[a-zA-Z0-9_.]+" "$GHIDRA"/Ghidra/Processors/Xtensa/data/languages/*.sinc | sort -u   # Ghidra's mnemonics
```
