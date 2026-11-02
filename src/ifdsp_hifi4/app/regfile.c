/*
 * FT-710 IFDSP HiFi4: the shared parameter register file and its two capture blocks (recreated, T24).
 *
 * The register file is 16-bit registers in the shared SRAM: register n (0x0000..0x3FFF) at 0x20070000 + 2n and
 * register 0x4000 + n at 0x20078000 + 2n (docs/code/ifdsp/ipc.md "How the DSP consumes the register file"). The M33
 * clears the file before the DSP starts; regfile_set_defaults writes only the non-zero defaults and the zeros of the
 * registers listed in its table (docs/code/ifdsp/hifi4.md "Register file use"). Registers 0x7000 and 0x7800 are two
 * 4 KB capture blocks (docs/code/ifdsp/control-link.md): a 16-bit control word (bit 0 enable, bit 1 wrap), a 16-bit
 * count and up to 0x3FF 32-bit samples.
 */
#include <stdint.h>
#include <string.h>
#include "hifi4_hal.h"
#include "regfile.h"

#define REGFILE_BASE 0x20070000u
#define REGFILE_SIZE 0x10000u

/* [fact] the defaults, in register order (0x21BE80 stores them grouped by value; the order of the stores has no effect
 * on the uncached RAM they go to) */
static const struct { uint16_t reg, value; } regfile_defaults[] = {
    {0x0002, 0x0000}, {0x0003, 0x0000}, {0x0004, 0x0000}, {0x0006, 0x0000}, {0x0008, 0x2031}, {0x0009, 0x0002},
    {0x000A, 0x0022}, {0x000C, 0x0001}, {0x000D, 0x0000}, {0x000E, 0x0000}, {0x000F, 0x0000}, {0x0010, 0x0000},
    {0x0011, 0xFFD4}, {0x0012, 0x0000}, {0x0013, 0x0000}, {0x0020, 0x0000}, {0x0021, 0xFFB0}, {0x0022, 0x0000},
    {0x0023, 0x0000}, {0x0025, 0x0000}, {0x0026, 0x0000}, {0x0027, 0x0000}, {0x0028, 0x0000}, {0x0029, 0x0000},
    {0x002A, 0x0000}, {0x002B, 0x0000}, {0x002C, 0x0000}, {0x002D, 0x0000}, {0x002E, 0x0000}, {0x002F, 0x0001},
    {0x0030, 0x00FF}, {0x0031, 0x0FFA}, {0x0032, 0x0FFA}, {0x0033, 0x000C}, {0x0034, 0x0000}, {0x0035, 0x0000},
    {0x0036, 0x0000}, {0x0037, 0x0000}, {0x0038, 0x0000}, {0x0039, 0x0000}, {0x003A, 0x0001}, {0x003B, 0x02C4},
    {0x0040, 0x0000}, {0x0041, 0x0000}, {0x0042, 0x0000}, {0x0043, 0x0000}, {0x0044, 0x0000}, {0x0045, 0x0000},
    {0x0046, 0x0000}, {0x0047, 0x0000}, {0x0048, 0x0000}, {0x0049, 0x0000}, {0x004A, 0x0000}, {0x004B, 0x0000},
    {0x004C, 0x0000}, {0x004D, 0x0000}, {0x004E, 0x0000}, {0x004F, 0x0000}, {0x0050, 0x0000}, {0x0051, 0x0000},
    {0x0052, 0x0000}, {0x0053, 0x0000}, {0x0054, 0x0000}, {0x0055, 0x0000}, {0x0056, 0x0000}, {0x0057, 0x0000},
    {0x0058, 0x02C4}, {0x005C, 0x0000}, {0x005D, 0x0000}, {0x0060, 0x0000}, {0x0061, 0x0000}, {0x0062, 0x0001},
    {0x0063, 0x00E7}, {0x0066, 0x0BB8}, {0x0067, 0x00FF}, {0x0068, 0x0000}, {0x2000, 0x0000}, {0x2001, 0x0000},
    {0x2002, 0x0000}, {0x2003, 0x0000}, {0x2004, 0x0000}, {0x2005, 0x0000}, {0x2006, 0x0000}, {0x2007, 0x0000},
    {0x2008, 0x0000}, {0x2009, 0x0000}, {0x200A, 0x0000}, {0x200B, 0x0000}, {0x200C, 0x0000}, {0x200D, 0x0000},
    {0x200E, 0x0000}, {0x200F, 0x0000}, {0x4001, 0x0001}, {0x4005, 0x0000}, {0x4006, 0x0000}, {0x4007, 0x003A},
    {0x4008, 0x0000}, {0x4009, 0x0000}, {0x400A, 0x0000}, {0x400B, 0x0008}, {0x400C, 0x0400}, {0x400D, 0x0200},
    {0x400E, 0x0002}, {0x400F, 0x0000}, {0x4011, 0x0080}, {0x4012, 0x4000}, {0x4013, 0x03E8}, {0x4014, 0xFFE8},
    {0x4015, 0x0000}, {0x4016, 0xFFFA}, {0x4017, 0x0000}, {0x4018, 0x0064}, {0x4019, 0x0000}, {0x401A, 0x0000},
    {0x401B, 0x02C4}, {0x401C, 0x000A}, {0x401D, 0x012C}, {0x401E, 0x0000}, {0x401F, 0x000A}, {0x4020, 0x0000},
    {0x4021, 0x0000}, {0x4022, 0x0000}, {0x4023, 0x0064}, {0x4025, 0x0000}, {0x4026, 0x0000},
};

/* 0x21BE80: make the register file uncached (cache attribute 2 = bypass), then write the defaults */
void regfile_set_defaults(void)
{
    unsigned i;

    xthal_set_region_attribute((void *)REGFILE_BASE, REGFILE_SIZE, 2, 0);
    for (i = 0; i < sizeof regfile_defaults / sizeof regfile_defaults[0]; i++)
        REG(regfile_defaults[i].reg) = regfile_defaults[i].value;
}

/* [fact] the capture blocks: registers 0x7000 and 0x7800 */
struct capture {
    uint16_t ctrl;                       /* bit 0: append enabled, bit 1: wrap at the end */
    uint16_t count;                      /* samples stored */
    uint32_t data[CAPTURE_SAMPLES];
};

struct capture *capture_buf[2];          /* 0x2390E0 (data_symbols.tsv) */

/* 0x21C090 */
void regfile_capture_init(void)
{
    unsigned i;

    capture_buf[0] = (struct capture *)&REG(0x7000);
    capture_buf[1] = (struct capture *)&REG(0x7800);
    for (i = 0; i < 2; i++)
        memset(capture_buf[i], 0, sizeof(struct capture));
}

/* 0x21C0B8 */
void regfile_capture_clear(unsigned ch)
{
    if (ch > 1)
        return;
    memset(capture_buf[ch], 0, sizeof(struct capture));
}

/* 0x21C0D4 */
void regfile_capture_set_ctrl(unsigned ch, uint16_t ctrl)
{
    if (ch > 1)
        return;
    capture_buf[ch]->ctrl = ctrl;
}

/* 0x21C0E8: append one sample while enabled and not full (0x3FF samples); at 0x3FF the count wraps to 0 if the wrap
 * bit is set, otherwise stays there and later samples are dropped [fact] */
void regfile_capture_append(unsigned ch, uint32_t sample)
{
    struct capture *c;
    uint16_t n;

    if (ch > 1)
        return;
    c = capture_buf[ch];
    if (!(c->ctrl & 1) || c->count >= CAPTURE_SAMPLES)
        return;
    c->data[c->count] = sample;
    n = c->count + 1;
    if (n >= CAPTURE_SAMPLES && (c->ctrl & 2))
        n = 0;
    c->count = n;
}

/* 0x21C5CC: the GPIO input that reg 0x4004 reports in bit 2 (tx_gpio_to_reg4004): P0_5 when the top nibble of
 * reg 0xC is 1, otherwise P0_4 (GPIO byte pin registers B0_4/B0_5) [fact] */
uint8_t regfile_gpio_sel(void)
{
    if ((REG(0x000C) & 0xF000) != 0x1000)
        return GPIO_B(0, 4);
    return GPIO_B(0, 5);
}
