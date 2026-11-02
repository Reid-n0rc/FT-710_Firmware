/* FT-710 IFDSP HiFi4: the Xtensa HAL calls and RT600 registers the recreated code uses (T24). The HAL itself
 * (xthal_*) is Cadence's and stays the image's code; these are its prototypes as the image calls them. */
#ifndef HIFI4_HAL_H
#define HIFI4_HAL_H

#include <stdint.h>

/* 0x233410: set the cache attribute of the 512 MB regions covering [vaddr, vaddr + size) (docs/code/ifdsp/dsp-chains.md,
 * "xthal_set_region_attribute"); a2 = vaddr, a3 = size, a4 = attribute, a5 = flags [fact: regfile_set_defaults 0x21BE83] */
int xthal_set_region_attribute(void *vaddr, unsigned size, unsigned cattr, unsigned flags);

/* RT600 GPIO byte pin registers B[port][pin] (base 0x40100000, 0x20 per port) [fact: 0x21C5E0 reads 0x40100004 = B0_4] */
#define GPIO_B(port, pin) (*(volatile uint8_t *)(0x40100000u + 0x20u * (port) + (pin)))

/* 0x236470: the cycle counter (rsr.ccount) [fact: hifi4-libraries.md] */
unsigned xthal_get_ccount(void);

#endif
