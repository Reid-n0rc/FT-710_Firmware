/*
 * Copyright 2018-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * FT-710 IFDSP M33 clock setup (T24). Structure of the MCUXpresso SDK evkmimxrt685 clock_config.c (MCUX_2.11.0); the
 * values are the FT-710's, read from BOARD_BootClockRUN at 0x8494C (docs/code/ifdsp/m33-platform.md section 3).
 * The FT-710 has no crystal: SYSOSC runs in bypass from CLKIN = DSP_CLK 18.432 MHz from the SDR module.
 */
#include "fsl_power.h"
#include "fsl_clock.h"
#include "board.h"
#include "clock_config.h"

#define BOARD_SYSOSC_SETTLING_US 260U    /* POWER_UpdateOscSettlingTime(0x104) [fact] */
#define BOARD_XTAL_SYS_CLK_HZ   24000000U /* g_xtalFreq; not used with SYSOSC in bypass [fact] */
#define BOARD_CLKIN_CLK_HZ      18432000U /* g_clkinFreq = DSP_CLK [fact] */

/* SYSPLL: 18.432 MHz x (21 + 31/64) = 396 MHz [fact: 0x87A08] */
const clock_sys_pll_config_t g_sysPllConfig_BOARD_BootClockRUN = {
    .sys_pll_src  = kCLOCK_SysPllXtalIn,
    .numerator    = 31,
    .denominator  = 64,
    .sys_pll_mult = kCLOCK_SysPllMult21,
};
/* Audio PLL: 18.432 MHz x (22 + 5040/27000); bypassed below, so the audio PLL clock is CLKIN [fact: 0x879F8] */
const clock_audio_pll_config_t g_audioPllConfig_BOARD_BootClockRUN = {
    .audio_pll_src  = kCLOCK_AudioPllXtalIn,
    .numerator      = 5040,
    .denominator    = 27000,
    .audio_pll_mult = kCLOCK_AudioPllMult22,
};

void BOARD_BootClockRUN(void)
{
    /* Configure LPOSC clock*/
    POWER_DisablePD(kPDRUNCFG_PD_LPOSC); /* Power on LPOSC (1MHz) */
    /* Configure FFRO clock */
    POWER_DisablePD(kPDRUNCFG_PD_FFRO);  /* Power on FFRO (48/60MHz) */
    CLOCK_EnableFfroClk(kCLOCK_Ffro48M); /* Enable FFRO clock*/
    /* Configure SFRO clock */
    POWER_DisablePD(kPDRUNCFG_PD_SFRO); /* Power on SFRO (16MHz) */
    CLOCK_EnableSfroClk();              /* Wait until SFRO stable */

    /* Move FLEXSPI clock to a stable source while the PLL and main clock change. */
    BOARD_FlexspiClockSafeConfig();

    /* Let CPU run on ffro for safe switching */
    CLOCK_AttachClk(kFFRO_to_MAIN_CLK);

    /* Configure SYSOSC clock source: bypass, clock from CLKIN */
    POWER_DisablePD(kPDRUNCFG_PD_SYSXTAL);
    POWER_UpdateOscSettlingTime(BOARD_SYSOSC_SETTLING_US);
    CLOCK_EnableSysOscClk(true, true, BOARD_SYSOSC_SETTLING_US);
    CLOCK_SetXtalFreq(BOARD_XTAL_SYS_CLK_HZ);
    CLOCK_SetClkinFreq(BOARD_CLKIN_CLK_HZ);
    CLKCTL0->SYSOSCBYPASS = 1U; /* SYSOSC from CLKIN [fact] */

    /* Configure SysPLL0 clock source */
    CLOCK_InitSysPll(&g_sysPllConfig_BOARD_BootClockRUN);
    CLOCK_InitSysPfd(kCLOCK_Pfd0, 12); /* MAIN PLL clock 594 MHz */
    CLOCK_InitSysPfd(kCLOCK_Pfd2, 24); /* AUX0 PLL clock 297 MHz */

    /* Configure Audio PLL clock source, then bypass it: audio PLL clock = CLKIN 18.432 MHz = 384 x 48 kHz */
    CLOCK_InitAudioPll(&g_audioPllConfig_BOARD_BootClockRUN);
    CLKCTL1->AUDIOPLL0CTL0 |= CLKCTL1_AUDIOPLL0CTL0_BYPASS_MASK;
    CLOCK_InitAudioPfd(kCLOCK_Pfd0, 26);

    CLOCK_SetClkDiv(kCLOCK_DivSysCpuAhbClk, 3U); /* M33 at 594 / 3 = 198 MHz */

    /* Set up clock selectors - Attach clocks to the peripheries */
    CLOCK_AttachClk(kMAIN_PLL_to_MAIN_CLK);

    /* Set up dividers */
    CLOCK_SetClkDiv(kCLOCK_DivAudioPllClk, 1U);
    CLOCK_SetClkDiv(kCLOCK_DivPfc0Clk, 2U);
    CLOCK_SetClkDiv(kCLOCK_DivPllFrgClk, 12U); /* FRG PLL clock 49.5 MHz */

    BOARD_SetFlexspiClock(1U, 6U); /* FlexSPI from main PLL / 6 = 99 MHz */

    /* Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKRUN_CORE_CLOCK;
}

void BOARD_InitBootClocks(void)
{
    BOARD_BootClockRUN();
}
