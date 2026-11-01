/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * FT-710 IFDSP M33: start the HiFi4 (T24). Shape of BOARD_DSP_Init in the MCUXpresso SDK dsp examples' dsp_support.c
 * (MCUX_2.11.0); the FT-710 version has no PMIC step, copies three images and uses the DSP PLL /12 (594 MHz) [fact:
 * 0x84AD8]. The image symbols are named after their Ghidra labels; their original names are not known.
 */
#include "fsl_common.h"
#include "fsl_dsp.h"
#include "dsp_support.h"

void BOARD_DSP_Init(void)
{
    dsp_copy_image_t tcm_image;
    dsp_copy_image_t sram_text_image;
    dsp_copy_image_t sram_data_image;

    tcm_image.destAddr       = (uint32_t *)DSP_TCM_ADDRESS;
    sram_text_image.destAddr = (uint32_t *)DSP_SRAM_TEXT_ADDRESS;
    sram_data_image.destAddr = (uint32_t *)DSP_SRAM_DATA_ADDRESS;

    tcm_image.srcAddr       = (uint32_t *)dsp_image0_tcm;
    tcm_image.size          = dsp_image0_size;
    sram_text_image.srcAddr = (uint32_t *)dsp_image1_sram_text;
    sram_text_image.size    = dsp_image1_size;
    sram_data_image.srcAddr = (uint32_t *)dsp_image2_sram_data;
    sram_data_image.size    = dsp_image2_size;

    /* Enable DSP PLL clock 594MHz. */
    CLOCK_InitSysPfd(kCLOCK_Pfd1, 12);
    /* Let DSP run on DSP PLL clock with divider 1 (594Mhz), DSP RAM at /2. */
    CLOCK_AttachClk(kDSP_PLL_to_DSP_MAIN_CLK);
    CLOCK_SetClkDiv(kCLOCK_DivDspCpuClk, 1);
    CLOCK_SetClkDiv(kCLOCK_DivDspRamClk, 2);

    /* Power the DSP memories and release the DSP from reset (it stays stalled until DSP_Start). */
    DSP_Init();

    DSP_CopyImage(&tcm_image);
    DSP_CopyImage(&sram_text_image);
    DSP_CopyImage(&sram_data_image);

    /* Run DSP core */
    DSP_Start();
}
