# T10c — MAIN SDR link (SCI5) and SDR control GPIOs

**Status:** done · **Depends on:** T05 T13 · **Parent:** [T10](T10-docs-main.md)

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
Page: [docs/code/main/sdr-link.md](../code/main/sdr-link.md). Names: `tools/ghidra/names_main.T10c.tsv` (59 proposals).
- SCI5 = 8N1, BRR 0x40, SEMR 0x50 → 115200 baud at PCLKB 60 MHz (PCLKB derived from the SCI0 baud table) [fact/inference].
- Frames: `r`+4hex+sum+CR / `w`+4hex+4hex+sum+CR (sum8 of ASCII bytes, 2 hex); 7-byte reply, write ACK = 0x06, read =
  x + 4 hex + 2-hex sum; timeout timer 2 = 6 ms (`FUN_fffa30f9`, `FUN_fffa3083`, `FUN_fffa2ff7`) [fact].
- `FUN_fffa11ed` (sdr_task, main loop) syncs ~35 registers through write-on-change shadows 0x1B736..0x1B780, one
  write per pass, RX-only set skipped in TX; register map with value sources (TX NCO 0x08/09, RX NCO 0x18/19, demod
  0x0A, filter class 0x16, passband 0x1E, width 0x1F, notch 0x1D, NB 0x1A, scope centre/span/level 0x20-0x22/0x27,
  TX drive 0x25 from the SPN calibration table, RTTY shift 0x0C) [fact for values, inference for meanings].
- Boot (`FUN_fffa1132`): P77 SDR_RESET=1, wait 1 s, read reg 0/1; reg 0 → `Vxx-yy` at 0x144A (VE2); failure → 0x20B36=3.
- GPIOs (p17 + code): P77 = SDR_RESET (pin 68), P76 = SDR_UPDATE (pin 69), P71 = DSP_RESET, P72 = DSP_UPDATE,
  P74 = AF_RESET, PC0 = PA_PON, P75 = USB_DET (input), P73 = TX, PB7 = RX. Port init PODR7=0x40.
- Update bridge (`sdr_bridge_mode`): DSP_RESET low, FPGA reset with SDR_UPDATE **low**, unlock reg 0x37=0xBCC5, then
  DISPLAY frames FD 00 (write) / FE 00 (read, only 0x32/0x33) / F1 81 (end) relayed SCI1↔SCI5; exit re-pulses reset
  with UPDATE high. On unlock failure DSP stays in reset [fact]. SDR_UPDATE polarity contradicts a plain flash WP#.
- `SPSW` values bypass the shadows and persist until the firmware's own value for that register changes [inference].

## Follow-ups
- T11c (DISPLAY): find the sender of link sub-command 1 and the FD/FE/F1 frames; decide whether image data goes via
  regs 0x30/0x31 (UART) or SPI.
- Menu page: names of settings 0x9AA1, 0x9AD2, 0x9AD3, 0x9B14, 0x9B16/17 (drive regs 0x0D, 0x1C, 0x1B, 0x23/0x27, 0x26).
- Optional, needs owner approval: `SPSR` reads of the unknown registers.
- After the parent's SLEIGH MOVU fix + re-export, recheck `FUN_fffa1c69` and `FUN_fffb3196`.

## Proposed shared-file edits
- `docs/code/sdr/interfaces.md` (T13 page, configuration/update sequence): replace the guessed steps with the MAIN
  bridge: D→M sub-command 1; M: DSP_RESET=0, SDR_RESET=0, SDR_UPDATE=0 (low, not "WP released"), 100 ms, SDR_RESET=1,
  2 s, write reg 0x37=0xBCC5; D↔M↔F register frames; F1 81 → SDR_RESET pulse with SDR_UPDATE=1, DSP_RESET=1. Replace
  `F-->>M: UART5 version` with "M reads reg 0 at boot → V01-04". In "To confirm" item 2 mark answered, link
  `../main/sdr-link.md`. Note the WP polarity issue (P76 low during update).
- `docs/hardware.md` MAIN UART table: SCI5 115200 8N1; add GPIO rows P76 SDR_UPDATE (pin 69), P77 SDR_RESET
  (pin 68, R1133 10k pull), P71 DSP_RESET (pin 86), P72 DSP_UPDATE (pin 85), P74 AF_RESET (pin 72), PC0 PA_PON
  (pin 75), P75 USB_DET (pin 71). Line 123 "DISPLAY most likely writes the module's config flash over SPI" → MAIN
  bridges register traffic during the update (T10c). The RX-CPU DEBUG header symbol on p17 reads **J1004**, while
  hardware.md says J1005 — recheck.
- `docs/code/main/cat.md` / `docs/cat-commands.md`: `SPSW` writes bypass the shadow (persist until the firmware's own
  value changes); `cat_SP_table` (SPN): entries from index 70 (0x469E..) hold per-band TX power calibration used by
  SDR reg 0x25; `dev4_reg_access` SCI4 device = RT685 DSP (T12). Link `sdr-link.md` from the "other pages" list.
- `decomp/main/INDEX.md` SCI table: SCI5 note → link sdr-link.md; replace "SDR reset/update pins are not yet identified".
