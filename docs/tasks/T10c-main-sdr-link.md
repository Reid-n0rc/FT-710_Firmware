# T10c — MAIN SDR link (SCI5) and SDR control GPIOs

**Status:** todo · **Depends on:** T05 T13 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): sdr-link.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10c.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
SCI5 command/reply protocol to the FPGA (`sdr_send_cmd` 0xFFFB1B2B, 7-byte replies at 0xA2AC), the SPSR/SPSW register map seen from MAIN (cat.md), SDR_UPDATE (= config flash WP, T13) / SDR_RESET GPIOs (port-bit helpers 0xFFFB70C9..0xFFFB71A7), and the SDR update sequence seen from MAIN.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
