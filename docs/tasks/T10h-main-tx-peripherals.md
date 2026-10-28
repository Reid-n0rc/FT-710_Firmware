# T10h — MAIN TX control, protection, meters and other peripherals

**Status:** todo · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): tx-protection.md, peripherals.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10h.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
PTT/TX sequencing (TX1 path), protection (SWR/temp/current/ALC), meters and the 12 ADC channels (SPIR), DAC (0x88040), tuner/linear port SCI2, SCI6 simple-I2C device, timers (CMT/TPU), GPIO map, power on/off (`power_off_io` 0xFFFB73A6), region/TX coverage (JP destination code).

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
