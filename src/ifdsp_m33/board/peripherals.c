/*
 * FT-710 IFDSP M33 (T24): the empty function at 0x87240 (bx lr), called once from main.
 * [inference] It is BOARD_InitBootPeripherals of an MCUXpresso Config Tools peripherals.c: it sits in link order between
 * clock_config.c (BOARD_InitBootClocks 0x8723C) and pin_mux.c (0x87242), the place of peripherals.c in alphabetical
 * object order, and the SDK's generated main calls BOARD_InitBootPeripherals right after the pin and clock setup.
 */
#include "peripherals.h"

void BOARD_InitBootPeripherals(void)
{
}
