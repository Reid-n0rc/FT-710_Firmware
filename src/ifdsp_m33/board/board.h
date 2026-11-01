/*
 * Copyright 2018-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * FT-710 IFDSP M33 board header (T24). Derived from the MCUXpresso SDK evkmimxrt685 board.h (MCUX_2.11.0), cut down to
 * what the FT-710 image uses.
 */
#ifndef BOARD_H_
#define BOARD_H_

#include "clock_config.h"
#include "fsl_common.h"
#include "fsl_flexspi.h"

void BOARD_InitDebugConsole(void);
void BOARD_FlexspiClockSafeConfig(void);
AT_QUICKACCESS_SECTION_CODE(void BOARD_SetFlexspiClock(uint32_t src, uint32_t divider));
AT_QUICKACCESS_SECTION_CODE(void BOARD_DeinitXip(FLEXSPI_Type *base));
AT_QUICKACCESS_SECTION_CODE(void BOARD_InitXip(FLEXSPI_Type *base));

#endif /* BOARD_H_ */
