# T10h — MAIN TX control, protection, meters and other peripherals

**Status:** done · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

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
Pages: [tx-protection.md](../code/main/tx-protection.md), [peripherals.md](../code/main/peripherals.md). There are 140 name proposals in
`tools/ghidra/names_main.T10h.tsv`.
- **GPIO map**: built from the p17 schematic and matched to every port access. Three code checks confirm the pin reading
  (EEPROM PE0/5/6/7, SCI4 on PB0/PB1 = DSP UART, `power_off_io` clears PC0 = PA_PON) [fact].
- **12 ADC channels / SPIR**: unit 0 converts AN001 MCUP_RVS, AN002 MCUP_FOR, AN003 PA_VDD, AN005 ALCM, AN006 PA_VU_TH and AN007 PA_IDD.
  Unit 1 converts AN108 REM_KEY, AN109 PA_HF_TH, AN115 SDR_DET and AN117. SPIR reports AN000..AN007 in order (AN000, AN004 and AN006 as 0),
  then AN115, AN117, AN108, AN109 [fact]. AN006 is converted but never used.
- **DAC 0x88040** = beep/sidetone tone generator (36-sample table, TPU1 sample clock). DA_OUT → TONE_BEEP on the schematic [fact].
- **Timers**: TPU0 10 kHz soft timers (75 one-shot), TPU3 100 ms, TPU1 tone, TPU2 speaker soft start. CMT is not used. MTU2 is set up but never
  started. IWDT → NMI [fact].
- **SCI6 simple-I2C has no device**: pins P00/P01 are unconnected on p17, and no code ever starts a transfer [fact].
- **SCI2** port modes follow TUN/LIN PORT SELECT (0x9AB7): EXT-TUNER UART / LINEAR band data / CAT-3 / GPO (GP A..D = P13/P12/P50/P22) [fact].
- **PTT**: there are 11 sources in a fixed priority (CAT TX1 first). CAT `TX1` writes its request flag directly, without `key_event_filter`.
  TX is gated only by `tx_freq_allowed` (inhibit flags + destination-code range table; bypassed completely in `zz_mode0`) [fact].
- **TRX sequencer** 0x20B18 has 9 states with per-step soft timers. The order is DATA_BUSY → AF_MUTE → speakers → RX off → TX on → TX delay → SEND [fact].
- **Protection**: HI-SWR (SWR ≥ 5 for 9 samples) sets a flag but does not drop TX in MAIN. There is a supply under-voltage power-down, a TOT, and
  fan control from the HF PA thermistor through the PA BU2505 DAC [fact/inference as tagged on the page].
- **Destination code / TX coverage**: 7 range tables decoded. Single-point 60 m rows (US table) can never match because of the
  `lo <= f < hi` compare [fact]. So US 60 m TX looks impossible as coded [inference]. Strap **JP_P51** (P51) toggles restricted ↔ wide
  codes on a reset start-up (start modes 1/7) [fact].

## Follow-ups
- `FUN_fffb5d68` (/SST2 12-bit register, 2322 bytes) and the exact BU2505 channel → PA net mapping (PA schematic p56–57).
- Who sets PTT sources 0x20B2A..0x20B2E (front-panel/MIC PTT via the DISPLAY link, tuner, PB) and the acks 0x20B19/0x20B1A (T10b/T10c/T10d).
- After the SLEIGH MOVU fix, re-check the TX→RX timer table in `trx_sequencer` (indexed by 0x9AA1) and `main_dac_update`.
- The meaning of 0x9AF5, 0x20B97, 0x20F1C/0x20F70 (TX inhibits) and the meaning of the start-mode byte in `FUN_fff9546a` (T10b).
- Confirm the US 60 m behaviour only with the owner's approval (no on-air test without it).

## Proposed shared-file edits
- `docs/code/main/README.md` subsystem index: add [tx-protection.md](tx-protection.md) and [peripherals.md](peripherals.md).
- `docs/hardware.md` MAIN section: replace "Other peripherals …" with a pointer to `docs/code/main/peripherals.md#gpio-map`. Note that the
  SCI6 pins (UART6, pins 7/8) are unconnected, that SCI4 = PB0/PB1 `DSP_UMISO/UMOSI` (fills the gap noted under the C4 bus), and that DA0 → `TONE_BEEP`.
- `docs/memory-maps.md` MAIN RAM table: add 0x20B04..0x20B16 ADC results (per-channel order as on the peripherals page), 0x20B18 `trx_state`,
  0x1204D `ptt_source`, 0x12043..0x1204C meters, and the note that `cfg105` 0x4659 is the calibration block.
- `docs/code/main/cat.md`: `cat_SP_adc_dump` row → field order AN000..AN007, AN115, AN117, AN108, AN109. `cat_TX` bypasses `key_event_filter`.
- `decomp/main/INDEX.md`: the "SCI6 … device is unknown" row → "no device (pins NC)". The SDR pins: SDR_UPDATE = P76, SDR_RESET = P77.
