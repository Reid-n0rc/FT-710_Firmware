/* FT-710 IFDSP M33: the parameter register file (T24), see regfile.c. */
#ifndef REGFILE_H_
#define REGFILE_H_

#include <stdint.h>

#define REGFILE_BASE  0x20070000U
#define REGFILE_BYTES 0x10000U

/* Registers the M33 itself uses (docs/code/ifdsp/control-link.md "Register-driven side effects on the M33") */
#define REG_VERSION       0x0000U /* IFDSP version, 0x0101 = V01-01; MAIN reads it once */
#define REG_STATUS_FLAGS  0x0001U /* status flags; the M33 sets bit 0 at start */
#define REG_CODEC_INPUT   0x000AU /* low nibble: codec right input (any write updates the codec) */
#define REG_M33_STARTED   0x4000U /* the M33 writes 1 after the DSP is up; no reader found */
#define REG_PWM_DUTY      0x4005U /* SCT0_OUT0 duty cycle 0..99, written by the DSP */

void regfile_clear(void);
uint16_t regfile_read(uint32_t reg);
void regfile_write(uint32_t reg, uint16_t value);
void regfile_set_bits(uint32_t reg, uint16_t bits);

#endif /* REGFILE_H_ */
