# T10h — MAIN TX control, protection, meters and other peripherals

**Status:** in progress · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

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
1. PeriphRefs.java over CMT, DA, TPU, S12AD/S12AD1, SCI2, SCI6, ports (PDR/PODR/PIDR/PMR/ODR), MPC, ICU and any other
   peripheral range (TMR, MTU, RTC, WDT) on a private project copy `FT710_MAIN_T10h`; list the functions per peripheral.
2. Read the decomp for: ADC scan/readout (0x20B04, `FUN_fffb27fb`/`FUN_fffb2858`), DAC, CMT/TPU tick and timer service,
   SCI2 (`sci2_configure`), SCI6 I2C device, `power_off_io` and the port-bit helpers, the PTT/TX path (`cat_TX`,
   CAT TX1, key-event filter), protection (SWR/temp/current/ALC/fan) and meters (RM/SM/SPM), the destination code
   (0x475E) TX band-limit tables.
3. Map ADC channels and GPIOs to schematic nets (service manual p17 MAIN CPU sheet, PA sheets), via pdftotext.
4. Write `docs/code/main/tx-protection.md` and `docs/code/main/peripherals.md` (tables + Mermaid), propose names in
   `tools/ghidra/names_main.T10h.tsv`, then Findings/Follow-ups here and commit.

## Findings
_(fill in as you go)_

## Follow-ups
