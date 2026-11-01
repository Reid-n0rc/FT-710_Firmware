/* FT-710 IFDSP M33 pin mux (T24), see pin_mux.c. */
#ifndef PIN_MUX_H_
#define PIN_MUX_H_

void BOARD_InitPins_flexcomm(void);
void BOARD_InitPins_P0(void);
void BOARD_InitPins_codec_spi(void);
void BOARD_InitPins_i2s(void);
void BOARD_InitPins_debug_gpio(void);
void BOARD_InitBootPins(void);

#endif /* PIN_MUX_H_ */
