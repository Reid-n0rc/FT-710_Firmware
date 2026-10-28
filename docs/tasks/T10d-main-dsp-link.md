# T10d — MAIN DSP link (SCI4 console protocol, SCI7)

**Status:** todo · **Depends on:** T05 T12a · **Parent:** [T10](T10-docs-main.md)

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
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
