/*
 * Copyright 2018-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * FT-710 IFDSP M33 clock setup (T24), see clock_config.c.
 */
#ifndef CLOCK_CONFIG_H_
#define CLOCK_CONFIG_H_

#include "fsl_common.h"

#define BOARD_BOOTCLOCKRUN_CORE_CLOCK 198000000U /* SystemCoreClock (0x87EC0) [fact] */

void BOARD_BootClockRUN(void);
void BOARD_InitBootClocks(void);

#endif /* CLOCK_CONFIG_H_ */
