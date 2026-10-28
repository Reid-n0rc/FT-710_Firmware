# T10g — MAIN band, VFO, mode, frequency and memory control

**Status:** done · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

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
1. Read the CAT handlers for FA/FB, MD, BS/BU/BD, ST, CF, MC/MR/MW/MA/MT, QI/QR, SC, LK, FT/FR, AB/BA/SV, ext FD in the
   committed decomp (`decomp/main/*.c`), and list the RAM globals they read/write.
2. Follow the shared helpers they call (frequency set/apply, band lookup, mode set, memory load/store) and identify the
   VFO record layout, the band table (ROM limits, 30 kHz-75 MHz), band-stack and memory-channel (0x5A-byte) layouts.
3. Trace how a frequency change goes out: SCI5 (SDR), SCI4 device registers, DISPLAY (SCI1) messages; use xrefs from
   a private Ghidra copy `FT710_MAIN_T10g` where the decomp is not enough.
4. Write `docs/code/main/radio-control.md` (function tables, structure tables, globals, Mermaid figures) and
   `tools/ghidra/names_main.T10g.tsv`; record findings/follow-ups here; commit.

## Findings
Page: [docs/code/main/radio-control.md](../code/main/radio-control.md). Proposed names: `tools/ghidra/names_main.T10g.tsv` (89 entries).
- 0x5A-byte channel record shared by the VFO operating records (A 0x9D09, B 0x9D63), memory channels (0x6150+ch*0x5A),
  band stack, QMB slots and memory-tune backups. Mode is in +0 bits 0-3, the clarifier is +0x48 (s16), the frequency is
  +0x4A (u32 BE) and the tag is +0x4E (12). Per-mode 10-byte blocks: SSB 0x0A, CW 0x14, RTTY 0x1E, DATA/PSK 0x28, AM 0x32. [fact]
- Band table 0xFFF8876C (12 ranges, GEN = 30 kHz..75 MHz). Band stack is 3 levels x 12 bands per VFO at 0x4761/0x5409,
  level per band at 0x60B1/0x60BD, auto-saved to EEPROM 0x112/0xDBA on change. [fact]
- The RAM block 0x464F.. mirrors EEPROM 0x0000.. (RAM = 0x464F + EEPROM address). [fact]
- FD decoded: scope start frequency per scope mode (0x9C35: CENTER/CURSOR/FIX). FD002 = per-band FIX start
  (0x9C99/0x9CC9). [inference, strong]
- Frequency output is polled. freq_cache_update (FUN_fff9cee1) computes 0x20F50 TX / 0x20F54 A / 0x20F58 B / 0x20F5C dial.
  sdr_update_poll (FUN_fffa11ed) writes SDR registers 0x18/0x19 (RX), 8/9 (TX) and 0x20/0x21 (scope centre) when they
  change. SCI4 gets only reg 99 by frequency range. DISPLAY gets 4 frequencies in its status frame. [fact]
- VFO states 1..8 (0x9DBE/0x9DBF), split 0x9C5E (FT and ST are the same flag), clarifier flags 0x20F29/0x20F2A,
  QMB at 0x9012, scan state machine FUN_fffe587f, lock 0x9C62 (key filter only, CAT FA is not blocked). [fact]
- BS accepts 12, which indexes past a band-stack row [inference, untested].

## Follow-ups
- Unknown record bytes (+0x04, +0x06..09, +0x47, FM block), states 0/6/7/8/9 entry.
- Dial encoder and key paths (FUN_fffc5e0a, 0xFFF89D94 table) are only followed to the shared helpers.
- Overlapping proposed names with T10b (disp_put_*), T10c (sdr_*), T10d (dsp_set_freq_range_param) and T10e (eeprom_save_*): the parent should reconcile them.

## Proposed shared-file edits
- `docs/cat-commands.md` FD section: replace "Meaning: not known" with "scope start frequency: n=0 dial (+offset), 1 CURSOR start 0x20F60, 2 FIX start of the current band; see code/main/radio-control.md".
- `docs/cat-commands-primary.md` FT/ST: both toggle split 0x9C5E via split_toggle; 0x20F10 is a frequency-cache refresh request (not a settings-dirty flag).
- `docs/memory-maps.md` MAIN RAM: add the EEPROM mirror rule (RAM 0x464F + EEPROM addr) and the band stack / memory / QMB / VFO block addresses from radio-control.md.
