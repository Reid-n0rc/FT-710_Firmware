# T17 — Integration: names, RX decoder fix, re-exports, shared-file edits

**Status:** in progress · **Depends on:** T09–T13 sub-tasks

## Goal
Fold the parallel sub-task results (T09–T12) into the shared files: apply every proposed Ghidra name and missed function
entry, fix the RX SLEIGH `MOVU.B/W Rs,Rd` decoder bug found in T10e (against the Renesas RXv2 software manual), re-analyse and
re-export `decomp/main`, `decomp/display`, `decomp/ifdsp`, switch the pages from proposed (italic) names to final names, and
apply every sub-task's "Proposed shared-file edits".

## Plan
Owner: T17 agent (worktree branch), 2026-10-27. Shared Ghidra projects `ghidra/FT710_{MAIN,DISPLAY,IFDSP}` in the main checkout
(only T17 writes them); exports go into this worktree's `decomp/`. One commit per step, decomp re-exports in their own commits.
1. **RX decoder.** Check `MOVU` (2) ld=11 and the string ops against the RXv2 software manual (pp. 124, 184-198, 259), patch the
   installed `rx62t.sinc` (backup `rx62t.sinc.orig-ea4cd204`), recompile with `support/sleigh`, store the diff as
   `tools/ghidra/rx62t-movu-fix.patch`, document it in `docs/tooling.md`.
2. **MAIN.** A script merges `names_main.T10?.tsv` into `names_main.tsv` (dedupe by address, list conflicts; pick the most specific
   name, keep names already used in the pages when equal). Full re-import with the fixed module (`-max-cpu 16`, 8 GB), ApplyNames,
   ExportDecomp, CatDispatch. Check the listed MOVU functions and the SP checksum sites in the new export.
3. **DISPLAY.** Merge `names_display.T11?.tsv` / `entries_display.T11?.tsv` (renames per T11b/c/e/f), FixFuncEntries → ApplyNames →
   ExportDecomp on the existing project, refresh the INDEX file columns.
4. **IFDSP.** Fold `names_ifdsp.T12{b,c,d}.tsv` into `IfdspM33Names.java` (creates + T12d's removals) and check `IfdspHifi4Names.java`;
   rebuild both programs per `decomp/ifdsp/INDEX.md` with the HiFi4 names script added.
5. **Pages.** Script: replace italic proposed names in `docs/code/{main,display,ifdsp}/*.md` with the applied names (from the
   merged TSVs / functions.tsv), then fix conflict renames.
6. **Shared-file edits.** Work through every `## Proposed shared-file edits` section (T10a-h, T11b-g, T12b-e; T09a/b and T13 have
   none, T13 follow-ups for hardware.md), RX651 hardware manual for quick [inference] → [fact] upgrades.
7. Findings, follow-ups, board changes for the parent.

## Findings
_(fill in as you go)_

## Follow-ups
