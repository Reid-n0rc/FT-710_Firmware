/* FT-710 IFDSP HiFi4: the shared parameter register file (recreated, T24; app/regfile.c). */
#ifndef REGFILE_H
#define REGFILE_H

#include <stdint.h>

/* register n at 0x20070000 + 2n, for 0..0x3FFF and 0x4000.. alike (0x4000 is 0x20078000; the DSP code addresses
 * them from the bases 0x2006FF00 and 0x20077F00 with offset 0x100 + 2n) [fact]. Not volatile [inference]: the image
 * accesses the registers without a MEMW and the GPIO registers with one (regfile_gpio_sel: reg 0xC at 0x21C5D5, the
 * GPIO byte at 0x21C5E3), and the Xtensa compilers put MEMW before volatile accesses (GCC: -mserialize-volatile) */
#define REG(n) (((uint16_t *)0x20070000u)[n])

#define CAPTURE_SAMPLES 0x3FF   /* 32-bit samples per 4 KB capture block (after ctrl and count) */

void regfile_set_defaults(void);
void regfile_capture_init(void);
void regfile_capture_clear(unsigned ch);
void regfile_capture_set_ctrl(unsigned ch, uint16_t ctrl);
void regfile_capture_append(unsigned ch, uint32_t sample);
uint8_t regfile_gpio_sel(void);

#endif
