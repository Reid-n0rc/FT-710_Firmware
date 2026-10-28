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

## Findings

## Follow-ups
