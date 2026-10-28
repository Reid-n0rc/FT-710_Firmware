# T10b — MAIN SCI drivers, DISPLAY link (SCI1) and front-panel key events

**Status:** todo · **Depends on:** T05 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): sci.md, display-link.md, ui-keys.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10b.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
SCI0–SCI7 driver layer (create/start/stop, ISRs, ring buffers, baud tables); the SCI1 protocol to the DISPLAY CPU (frame format, commands both ways, retries; cross-check with T11b `mainlink_*` on the DISPLAY side); how key/encoder/touch events from DISPLAY are turned into radio actions.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
