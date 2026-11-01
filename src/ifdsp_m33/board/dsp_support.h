/* FT-710 IFDSP M33: start the HiFi4 (T24), see dsp_support.c and dsp_image.S. */
#ifndef DSP_SUPPORT_H_
#define DSP_SUPPORT_H_

#include <stdint.h>

#define DSP_TCM_ADDRESS       0x24000000U /* HiFi4 TCMs; reset vector 0x24020000 */
#define DSP_SRAM_TEXT_ADDRESS 0x00200000U
#define DSP_SRAM_DATA_ADDRESS 0x20040000U

/* The three HiFi4 images in flash (0x08001844, 0x08021E88, 0x0805A23C) and their sizes (0x0805D41C..0x0805D424). */
extern const uint8_t dsp_image0_tcm[];
extern const uint8_t dsp_image1_sram_text[];
extern const uint8_t dsp_image2_sram_data[];
extern const uint32_t dsp_image0_size;
extern const uint32_t dsp_image1_size;
extern const uint32_t dsp_image2_size;

void BOARD_DSP_Init(void);

#endif /* DSP_SUPPORT_H_ */
