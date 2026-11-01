/*
 * FT-710 IFDSP M33: the parameter register file (T24, recreated from the image 0x80C20..0x80CA0).
 * 32K x 16-bit registers at 0x20070000 in shared SRAM. MAIN writes them over the console link, the HiFi4 reads them
 * directly. Register map: docs/code/ifdsp/control-link.md "Register file".
 */
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "codec.h"
#include "regfile.h"

#define REGFILE ((uint16_t *)REGFILE_BASE)
#define REGFILE_END ((uint16_t *)(REGFILE_BASE + REGFILE_BYTES))

void regfile_clear(void)
{
    memset((void *)REGFILE_BASE, 0, REGFILE_BYTES);
}

uint16_t regfile_read(uint32_t reg)
{
    uint16_t *p = &REGFILE[reg];

    return (p < REGFILE_END) ? *p : 0U;
}

void regfile_write(uint32_t reg, uint16_t value)
{
    uint16_t *p = &REGFILE[reg];

    if (p < REGFILE_END)
    {
        *p = value;
        /* Register 10, low nibble: right codec input, 1 = IN1R, anything else = IN2R */
        if (reg == REG_CODEC_INPUT)
        {
            aic3204_select_right_input(((value & 0xFU) == 1U) ? 0 : 1);
        }
    }
}

void regfile_set_bits(uint32_t reg, uint16_t bits)
{
    uint16_t *p = &REGFILE[reg];

    if (p < REGFILE_END)
    {
        taskENTER_CRITICAL();
        *p |= bits;
        taskEXIT_CRITICAL();
    }
}
