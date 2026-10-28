# T10g — MAIN band, VFO, mode, frequency and memory control

**Status:** todo · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): radio-control.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10g.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
VFO A/B state, band stack and band data (FD command), mode handling, frequency → synth/SDR/DSP programming, split/clarifier, memory channels and QMB, scan.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
