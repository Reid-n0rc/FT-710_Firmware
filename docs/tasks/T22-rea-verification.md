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
