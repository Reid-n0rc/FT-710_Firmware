# T10d — MAIN DSP link (SCI4 console protocol, SCI7)

**Status:** in progress · **Depends on:** T05 T12a · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): dsp-link.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10d.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
The MAIN side of the IFDSP register-poke protocol (T12a: `FUN_fff9d06c` sends `i DB00`, `FUN_fffa0b4c` builds `rAAAACC`/`wAAAADDDDCC`): which registers MAIN writes for which radio functions, timing, error handling; what SCI7 ("C4") carries. Cross-reference `docs/code/ifdsp/` (T12b owns the DSP side).

## Plan
1. Read the SCI4 transport (`R_SCI4_*`, `FUN_fffb1ab4`), the frame builder/checksum/reply wait (`FUN_fffa0b4c`, `FUN_fffa0c01`,
   `FUN_fffa0ad6`), the generic accessor `FUN_fff9d8a4` and init `FUN_fff9d06c` in `decomp/main/`; get timing/retry from them.
2. Enumerate every caller of the frame builder / accessor (Ghidra xrefs on my project copy `FT710_MAIN_T10d`), and for each
   setter record register address, value source (RAM global → setting/menu/CAT command, via xrefs to that global from
   `cat_XX` handlers and the menu tables), and trigger (boot, mode change, CAT set, periodic).
3. SCI7: read `R_SCI7_Create` and its ISRs/callers, find what is sent and received.
4. Write `docs/code/main/dsp-link.md` (function table, register table, globals, sequence + flow figures), names TSV, findings.

## Findings
_(fill in as you go)_

## Follow-ups
