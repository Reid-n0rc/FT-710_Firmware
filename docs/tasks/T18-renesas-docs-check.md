# T18 — Check the docs against the Renesas RX651 documentation

**Status:** done · **Depends on:** T05, T10, T17

## Goal
The owner added the Renesas documentation in `Manuals/Renesas/`: the RX651 hardware manual r01uh0590 Rev.2.40, the datasheet
r01ds0276 Rev.2.40, the handbook, the RXv2 software manual r01us0071, and technical updates TN-RX*-A0267/A0276/A0280/A0291. Check every
MAIN claim still tagged [guess]/[inference] that these documents can settle, correct anything they contradict, and say whether the
technical updates affect this firmware.

## Plan
Parent session, 2026-10-28. T17 already used the hardware manual for clocks, SCI, TPU and ICU, so this task covers the rest.
1. Extract the text with `pdftotext -layout` into `build/renesas/` (gitignored).
2. Part number: datasheet Table 1.3 / Table 1.2 against hardware.md and memory-maps.md (code flash, RAM, data flash, dual bank).
3. Memory map and peripheral bases: hardware manual Figure 4.1 and the I/O register table (§5) against memory-maps.md.
4. Option-setting memory: decode the all-0xFF 116 bytes field by field (§7) for custom-firmware.md.
5. Boot mode: pins (§3 Table 3.1, Table 59.7) and the SCI boot command set (§59.13) against display/update.md §5.
6. `SetupRX651.java` vector names against Table 15.5 (T05 follow-up).
7. IWDT: decode `R_IWDT_Create` (§33) and `wdt_kick`.
8. Technical updates: check each one for code in MAIN that it applies to.
9. Edit the pages and record the findings here, then sync the issues and commit.

## Findings
Citations: HWM = hardware manual R01UH0590EJ0240, DS = datasheet R01DS0276EJ0240.

1. **The part has no data flash [fact: DS Table 1.3 p19, Table 1.2 p12; HWM Figure 4.1 note 5 p189].** R5F56514**ADFB** =
   512 KB code flash (0xFFF80000..0xFFFFFFFF), 256 KB RAM (0x00000000..0x0003FFFF), **no data flash**, no encryption (TSIP), no
   SDHI/SDSI, no dual bank or BGO, PLQP0144KA-B (144-pin LFQFP), −40 to +85 °C. Data flash, the dual bank and 640 KB RAM exist only on the
   1.5/2 MB parts. hardware.md and memory-maps.md said "32 KB data flash" (a guess from the part number). That is wrong, and it explains
   why T10e found no data-flash code. Products with ≤1 MB of flash also have only RIIC0 and RIIC2 (MAIN uses neither; its I2C is
   SCI6 simple-I2C).
2. **Memory map and peripheral bases confirmed [fact: HWM Figure 4.1 p189, I/O register table §5 p204 ff.].** SYSTEM 0x80000,
   ICU 0x87000, CMT 0x88000, IWDT 0x88030, DA 0x88040, TPU 0x88100, S12AD/S12AD1 0x89000/0x89100, SCI0 0x8A000 (+0x20 per channel),
   PDR/PODR/PIDR 0x8C000/0x8C020/0x8C040, MPC 0x8C100, flash registers 0x007FC000. 0x000A4000..0x000A5FFF inside the I/O range is the
   8 KB standby RAM (no references in `decomp/main`).
3. **Option-setting memory, all 0xFF [fact: HWM §7, pp259–275].**
   - MDE = little-endian, linear mode.
   - OFS0: IWDT and WDT are not auto-started (register-start mode, so `R_IWDT_Create` sets them).
   - OFS1: voltage monitor 0 reset off, HOCO off after reset.
   - SPCC.SPE = 1: a serial programmer may connect.
   - OSIS: the control code 0xFF is not 0x45, so wrong IDs never erase the flash. The host must send ID 16 × 0xFF, which DISPLAY does
     (Table 7.3, row 3). The OCD (E2) ID is the same 16 × 0xFF (Table 7.4).
   - TMEF = Trusted Memory off. FAW: FSPR = 1, so the access window is unprotected and the whole area is writable. ROMCODE = 0xFFFFFFFF:
     no ROM code protection for parallel programmers.
   - **Hazard for custom images:** FAW.FSPR = 0 can never be set back to 1 (p271), SPCC.SPE = 0 locks out the serial programmer (and so
     DISPLAY's update path), and control code 0x45 erases the flash after 3 bad IDs. `sfl_encode.py` always writes the 116-byte area, so
     a patched MAIN image must keep it all 0xFF.
   - TN-RX*-A0276B: the option-setting memory is rated for 1000 program/erase cycles, and each MAIN update rewrites it (`51`), so that
     is the limit on MAIN updates [inference].
4. **Boot mode confirmed [fact: HWM Table 3.1 p180, Table 59.7 p2564, §59.13 pp2577–2612].**
   - MD low and PC7/UB low at reset select SCI boot on SCI1 (P30 RXD1 / P26 TXD1). MD low, then high 20–100 ms after reset, selects FINE.
     MAIN never drives PC7 (input, no function), so it must be low on the board for DISPLAY's update to work. **Confirmed (#79):** net `UB`
     is pulled to ground by R1072 10 kΩ on the MAIN CNTL sheet (p17; fitted, parts list p38) [fact].
   - Every command DISPLAY sends matches §59.13, in the required order: `38` device type, `36` endian, `32` frequency, `34` bit rate,
     `00` sync, `2C` ID mode, `30` ID check, `53`/`54` area count/info, `50` area erase, `13` program, `15` read, `51`/`52` configuration
     program/read. Errors are the OK code + 0x80, and `C2` is the sync-phase checksum-error code.
   - The area kinds (KOA) are `00` code flash, `20` data flash, `30` option-setting memory, `40`/`41` Trusted Memory off/on (p2610).
     So DISPLAY skips `' '` (0x20, data flash, absent here) when writing, skips `'@'` (0x40, the Trusted Memory window, which lies inside
     code flash) when sizing, and writes `'0'` (0x30) with `51`.
5. **Vector names in `SetupRX651.java` are correct [fact: HWM Table 15.5 pp461–463]:** BUSERR 16, SWINT2/SWINT 26/27, CMT0/1 28/29,
   CMTW0/1 30/31, RSPI0 38/39, SCI0–2 RXI 58/60/62, IRQ0–15 64–79, SCI3–6 RXI 80/82/84/86, SCI7 RXI 98, GROUPBE0/BL2/BL0/BL1/AL0/AL1
   106/107/110/111/112/113, each with TXI at +1. T05 follow-up closed.
6. **IWDT [fact: code + HWM §33.2 pp1410–1415, NMIER p438].**
   - `R_IWDT_Create`: IWDTCR = 0x3350 is TOPS 00 (1024 cycles), CKS 0101 (IWDTCLK/256), and no refresh window (RPES/RPSS 11).
     IWDTRCR = 0 sends an underflow to an NMI, not a reset. IWDTCSTPR = 0x80 stops the count in sleep mode. NMIER.IWDTEN is set.
   - Timeout = 1024 × 256 / 120 kHz = **≈2.2 s** (2.0–2.4 s over fILOCO 108–132 kHz).
   - `wdt_kick` → `iwdt_refresh` writes IWDTRR 0x88030 with 0x00 then 0xFF, the refresh sequence [fact].
7. **Technical updates.**
   - **TN-RX*-A0280A applies to MAIN's code** [fact for the code, inference for the impact]. On a cold start (RSTSR1.CWSF = 0)
     `hw_init_clock` runs the *uncorrected* Figure 9.15 "sub-clock not used" flow: RCR4.RCKSEL ← 0, RCR3.RTCEN ← 0,
     SOSCCR.SOSTP ← 1, then wait for OSCOVFSR.SOOVF = 0. The erratum deletes the RCKSEL write, because RCKSEL should be written once,
     in the RTC procedure. MAIN writes it exactly once and never uses the RTC (no other RTC references), so the effect is harmless.
     Leave it alone in patches.
   - TN-RX*-A0267A (dual-mode rewrite): does not apply, because this part has no dual bank.
   - TN-RX*-A0291A (QSPI next-access delay): does not apply, because MAIN has no QSPI references.
   - TN-RX*-A0276B: see 3.

## Follow-ups
- None. (The board level of PC7/UB was read in #79: R1072 10 kΩ to ground.)
