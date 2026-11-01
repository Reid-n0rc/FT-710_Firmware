/* FT-710 IFDSP M33: TLV320AIC3204 codec (T24), see codec.c. */
#ifndef CODEC_H_
#define CODEC_H_

#include <stdint.h>

void delay_us(uint32_t us);
void aic3204_spi_write(uint8_t reg, uint8_t value);
void aic3204_init(void);
void aic3204_select_right_input(int in2);

#endif /* CODEC_H_ */
