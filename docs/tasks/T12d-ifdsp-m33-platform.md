# T12d — IFDSP M33 platform (boot, DSP loader, RTOS)

**Status:** done (2026-10-27) · **Parent:** T12 · **Depends on:** T12a

## Goal
`docs/code/ifdsp/m33-platform.md`: reset and copy-down, clock/pin/GPIO init, BOARD_DSP_Init, codec init, SCT0 PWM, FreeRTOS kernel, heap and libc; full M33 function table; remaining `FUN_` names.

## Plan
See T12 plan. Starting notes from T12a below. T12d approach:
1. Private Ghidra copy `FT710_IFDSP_T12d`; export the current decompile to the scratchpad (one file) and read every SRAM `FUN_`
   body plus the raw SRAM/flash disassembly (`build/ifdsp_m33_*.dis`) for code Ghidra did not turn into functions.
2. Identify FUN_ by matching NXP MCUXpresso SDK (fsl_clock/power/reset/flexcomm/usart/sctimer/pint/dma), board.c/pin_mux.c,
   FreeRTOS kernel (tasks/queue/list/timers/event_groups, ARM_CM33 port, heap_4), rpmsg-lite virtqueue/env and Redlib.
   Review the three uncertain T12a names.
3. Decode: boot (FCFB, boot header, ResetISR/SystemInit, copy tables), clock tree (PLL config structs, divider calls →
   frequencies), pin mux (IOPCTL writes → pins/functions, cross-checked against service manual p19 renders), IRQ vector →
   flash stub → veneer → SRAM handler map, DSP loader, FreeRTOS objects, fault handling, watchdog.
4. Write `tools/ghidra/names_ifdsp.T12d.tsv` and `docs/code/ifdsp/m33-platform.md`; record shared-file edits here.

## Starting notes (from T12a)
- 140 M33 functions are named in `tools/ghidra/IfdspM33Names.java` (171 SRAM `FUN_` remain, mostly FreeRTOS internals, clock driver internals and Redlib). Group names by subsystem comment in that file.
- `BOARD_BootClockRUN` 0x8494C: core 198 MHz, `g_xtal` 24 MHz, CLKIN 18.432 MHz (PIO2_30 func 5 = `DSP_CLK` from SDR, p19). `BOARD_InitPins` 0x87294 → `BOARD_InitPins_P0` 0x84B78 (P0_4 `AF_MUTE`, P0_5, P0_21, P0_22 as GPIO inputs; P0_22/23/24 wiring to `RX_IF_DAT`/`TX`/`SEND_A` is ambiguous on p19) and `BOARD_InitPins_codec_spi` 0x84BEC.
- Codec: `aic3204_init` 0x80BD0 (reset PIO1_0 low/high, then 67 × {reg, val, delay_us} from 0x87A1C via `aic3204_spi_write` 0x80B68 = 16-bit word `reg<<9 | val`, MSB first, CS PIO1_7, SCLK PIO2_29, MOSI PIO1_1). Table includes DAC/ADC first-order IIR coefficients N0=0x7FE36C, N1=0x801C94, D1=0x7FC6DA (pages 8/9, a DC-blocking high-pass **[inference]**).
- SCT0: `sct0_pwm_init` 0x811E0 (20 kHz, output 0 = PIO2_2 func 2), `sct0_pwm_callback` 0x81164 (every 400 periods: duty = clamp(reg 0x4005, 1..99) %). The DSP writes reg 0x4005 (0x21F348). SCT0_OUT0 → R2041/C2003 → TP2005 only (p19).
- Unused SDK code: `POWER_EnterSleep_mode1..3`, `POWER_EnterDeepSleep` (no callers).
- Pending/uncertain names to review: `CLOCK_SetDiv_0x620` 0x809A0, `POWER_CalcSafetyCount` 0x800EE, `redlib_malloc` 0x84D3C; FreeRTOS port asm 0x80A24 (undecodable instruction).

## Findings
Page: `docs/code/ifdsp/m33-platform.md`. Names: `tools/ghidra/names_ifdsp.T12d.tsv` (178 entries: 132 SRAM `FUN_` named, 5 T12a
corrections, ~40 new function entries for code Ghidra missed).
- T12a review: `CLOCK_SetDiv_0x620` 0x809A0 is SDK `BOARD_SetFlexspiClock` (FLEXSPIFCLKSEL/DIV + XIP-safe deinit/init);
  `POWER_CalcSafetyCount` 0x800EE is a mid-function entry, the real `POWER_CalculateSafetyCount` starts at 0x800E8;
  `redlib_malloc` 0x84D3C is Redlib `malloc`; `_Csys_alloc_failed` 0x84E04 is really `_Csys_alloc` **[fact/inference]**.
- Clock tree: SYSOSC bypassed to CLKIN 18.432 MHz; SYSPLL = 18.432 × (21 + 31/64) = 396 MHz; PFD0 /12 = 594 MHz, core /3 = 198 MHz;
  DSP PFD1 /12 = 594 MHz HiFi4, DSP RAM 297 MHz; audio PLL bypassed → 18.432 MHz; FlexSPI 99 MHz; FC0 49.5 MHz; tick 1 kHz.
- Pin mux table decoded and matched to p19 nets (FC2 SCK input inverted, FC3/FC4 have data pins only so SCK/WS are shared,
  PIO2_4..6 / PIO0_28/29/31 drive debug test points, PIO2_5 goes high when the command task starts).
- 35 SDK `*_DriverIRQHandler`s live in SRAM, reached through flash stubs + veneers; only SCT0 (plus FC0 and MU-A direct) is enabled.
- No watchdog, no fault logging (HardFault = semihosting BKPT skip, else spin), sleep code unused, stdio goes to no-host stubs.
- Flash: FCFB = QSPI x4, 0xEB read, 16 MB, 120 MHz; image ends at 0x080652EC; no flash program/erase code on the M33.
- `0x40146000` (unidentified in memory-maps.md) is SCT0 **[fact: used by the SCTIMER functions]**.

## Proposed shared-file edits
- `tools/ghidra/IfdspM33Names.java`: apply the TSV. Replace `CLOCK_SetDiv_0x620`, `POWER_CalcSafetyCount`, `redlib_malloc`,
  `_Csys_alloc_failed` as listed. Add FIX_START-style fixes: remove the function at 0x800EE and let 0x800E8 own the body; remove
  0x80A24 and create 0x80A18 (`OTFAD_Init`). Create the NEW entries (IRQ handlers, 0x84C90, 0x80A60, 0x821D0, 0x83D5C, 0x86F3C,
  0x87946, 0x80A44). Then re-export `decomp/ifdsp/m33`.
- `docs/memory-maps.md` IFDSP: 0x40146000 = SCT0; add PINT 0x40025000, OSTIMER 0x40113000, I3C0 0x40036000, HASHCRYPT 0x40158000
  (referenced only by unused SDK IRQ handlers); ucHeap 0x88EF0..0xA1EE8, Redlib heap 0xA1EF8..0xA2EF8.
- `decomp/ifdsp/INDEX.md`: the "undecodable instruction" in 0x80A24/0x80A90 is 0xFFFFFFFF padding after literal pools;
  0x80A24 is the inside of `OTFAD_Init` 0x80A18, not a port stub.
- `docs/code/ifdsp/README.md`: key numbers can add DSP 594 MHz, SYSPLL 396 MHz, FreeRTOS tick 1 kHz, no watchdog.
- `docs/hardware.md` Q2002: FCFB parameters; PIO2_4..6 / PIO0_28/29/31 are debug GPIOs to TP2007–2009 / TP2043–2046.

## Follow-ups
- Which FLEXCOMM provides SCK/WS to FC3 (RX IF) and FC4 (codec in), and the MCLK clock select: DSP side (T12e).
- The INPUTMUX selection `INPUTMUX_AttachSignal(1, 0x14000015)` in `app_main` (T12c).

## Status
Done. All SRAM `FUN_` have proposals; Ghidra/decomp re-export left to the parent (shared files).
