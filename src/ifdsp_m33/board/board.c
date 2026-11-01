/*
 * Copyright 2018-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * FT-710 IFDSP M33 board support (T24). The functions the image keeps from the MCUXpresso SDK evkmimxrt685 board.c
 * (MCUX_2.11.0), in the same order; the rest of that file (hyper RAM, I2C/I3C helpers) is not in the image.
 * Changed from the SDK: BOARD_InitDebugConsole is empty in the image (bx lr at 0x87232) [fact].
 */
#include <stdint.h>
#include "fsl_common.h"
#include "board.h"

#define BOARD_FLEXSPI_DLL_LOCK_RETRY (10)
/* The XIP test of the SDK: true while the code runs from FlexSPI flash. In the FT-710 image this code runs from SRAM,
   so the test is false at run time, but it is still compiled in (literal &BOARD_InitDebugConsole at 0x80A10) [fact]. */
#define BOARD_IS_XIP_FLEXSPI()                                                                                  \
    ((((uint32_t)BOARD_InitDebugConsole >= 0x08000000U) && ((uint32_t)BOARD_InitDebugConsole < 0x10000000U)) || \
     (((uint32_t)BOARD_InitDebugConsole >= 0x18000000U) && ((uint32_t)BOARD_InitDebugConsole < 0x20000000U)))

/* Debug console: not used; all console output goes through uart0_write (docs/code/ifdsp/m33-platform.md section 9). */
void BOARD_InitDebugConsole(void)
{
}

void BOARD_DeinitXip(FLEXSPI_Type *base)
{
    /* Wait until FLEXSPI is not busy */
    while (!((base->STS0 & FLEXSPI_STS0_ARBIDLE_MASK) && (base->STS0 & FLEXSPI_STS0_SEQIDLE_MASK)))
    {
    }
    /* Disable module during the reset procedure */
    base->MCR0 |= FLEXSPI_MCR0_MDIS_MASK;
}

void BOARD_InitXip(FLEXSPI_Type *base)
{
    uint32_t status;
    uint32_t lastStatus;
    uint32_t retry;
    uint32_t mask = 0;

    /* Enable FLEXSPI module */
    base->MCR0 &= ~FLEXSPI_MCR0_MDIS_MASK;

    base->MCR0 |= FLEXSPI_MCR0_SWRESET_MASK;
    while (base->MCR0 & FLEXSPI_MCR0_SWRESET_MASK)
    {
    }

    /* Need to wait DLL locked if DLL enabled */
    if (0U != (base->DLLCR[0] & FLEXSPI_DLLCR_DLLEN_MASK))
    {
        lastStatus = base->STS2;
        retry      = BOARD_FLEXSPI_DLL_LOCK_RETRY;
        /* Flash on port A */
        if (((base->FLSHCR0[0] & FLEXSPI_FLSHCR0_FLSHSZ_MASK) > 0) ||
            ((base->FLSHCR0[1] & FLEXSPI_FLSHCR0_FLSHSZ_MASK) > 0))
        {
            mask |= FLEXSPI_STS2_AREFLOCK_MASK | FLEXSPI_STS2_ASLVLOCK_MASK;
        }
        /* Flash on port B */
        if (((base->FLSHCR0[2] & FLEXSPI_FLSHCR0_FLSHSZ_MASK) > 0) ||
            ((base->FLSHCR0[3] & FLEXSPI_FLSHCR0_FLSHSZ_MASK) > 0))
        {
            mask |= FLEXSPI_STS2_BREFLOCK_MASK | FLEXSPI_STS2_BSLVLOCK_MASK;
        }
        /* Wait slave delay line locked and slave reference delay line locked. */
        do
        {
            status = base->STS2;
            if ((status & mask) == mask)
            {
                /* Locked */
                retry = 100;
                break;
            }
            else if (status == lastStatus)
            {
                /* Same delay cell number in calibration */
                retry--;
            }
            else
            {
                retry      = BOARD_FLEXSPI_DLL_LOCK_RETRY;
                lastStatus = status;
            }
        } while (retry > 0);
        /* According to ERR011377, need to delay at least 100 NOPs to ensure the DLL is locked. */
        for (; retry > 0U; retry--)
        {
            __NOP();
        }
    }
}

/* BOARD_SetFlexspiClock run in RAM used to configure FlexSPI clock source and divider when XIP. */
void BOARD_SetFlexspiClock(uint32_t src, uint32_t divider)
{
    if ((CLKCTL0->FLEXSPIFCLKSEL != CLKCTL0_FLEXSPIFCLKSEL_SEL(src)) ||
        ((CLKCTL0->FLEXSPIFCLKDIV & CLKCTL0_FLEXSPIFCLKDIV_DIV_MASK) != (divider - 1)))
    {
        if (BOARD_IS_XIP_FLEXSPI())
        {
            BOARD_DeinitXip(FLEXSPI);
        }
        /* Disable clock before changing clock source */
        CLKCTL0->PSCCTL0_CLR = CLKCTL0_PSCCTL0_CLR_FLEXSPI_OTFAD_CLK_MASK;
        /* Update flexspi clock. */
        CLKCTL0->FLEXSPIFCLKSEL = CLKCTL0_FLEXSPIFCLKSEL_SEL(src);
        CLKCTL0->FLEXSPIFCLKDIV |= CLKCTL0_FLEXSPIFCLKDIV_RESET_MASK; /* Reset the divider counter */
        CLKCTL0->FLEXSPIFCLKDIV = CLKCTL0_FLEXSPIFCLKDIV_DIV(divider - 1);
        while ((CLKCTL0->FLEXSPIFCLKDIV) & CLKCTL0_FLEXSPIFCLKDIV_REQFLAG_MASK)
        {
        }
        /* Enable FLEXSPI clock again */
        CLKCTL0->PSCCTL0_SET = CLKCTL0_PSCCTL0_SET_FLEXSPI_OTFAD_CLK_MASK;
        if (BOARD_IS_XIP_FLEXSPI())
        {
            BOARD_InitXip(FLEXSPI);
        }
    }
}

void BOARD_FlexspiClockSafeConfig(void)
{
    /* Move FLEXSPI clock source from main clock to FFRO to avoid instruction/data fetch issue in XIP when
     * updating PLL and main clock.
     */
    BOARD_SetFlexspiClock(3U, 1U);
}
