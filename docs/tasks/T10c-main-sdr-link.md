# T10c — MAIN SDR link (SCI5) and SDR control GPIOs

**Status:** in progress · **Depends on:** T05 T13 · **Parent:** [T10](T10-docs-main.md)

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
1. Read the frame layer (`sdr_send_cmd`, the builder/checksum/reply-check functions next to `sdr_reg_access`) and the
   SCI5 driver (baud from SMR/BRR/SEMR) in `decomp/main`; confirm lost call arguments in the disassembly
   (own Ghidra copy `FT710_MAIN_T10c`, DumpListing.java).
2. Walk the polled SDR task (`FUN_fffa11ed`, called from `main_loop`) and its ~30 per-register updaters; build the
   register map (address, writer, value source, shadow slot, RX/TX condition) and cross-check with the reply handler.
3. Identify the GPIOs from the port-bit helpers and the PODR addresses, and check them against the schematic (p17).
4. Document the boot sequence (`FUN_fffa1132` from `app_main`) and the DISPLAY-driven update bridge (`sdr_bridge_mode`).
5. Write `docs/code/main/sdr-link.md` (tables, globals, Mermaid figures), `tools/ghidra/names_main.T10c.tsv`, and
   proposed edits for `docs/code/sdr/interfaces.md` / `docs/hardware.md` / `cat-commands.md`.

## Findings
_(fill in as you go)_

## Follow-ups
