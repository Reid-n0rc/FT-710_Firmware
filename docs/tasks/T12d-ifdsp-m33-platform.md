# T12d — IFDSP M33 platform (boot, DSP loader, RTOS)

**Status:** in progress (2026-10-27) · **Parent:** T12 · **Depends on:** T12a

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

## Status
