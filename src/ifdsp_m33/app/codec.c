/*
 * FT-710 IFDSP M33: TLV320AIC3204 codec (T24, recreated from the image 0x80B44..0x80C18, 0x85F88).
 * The codec hangs off four GPIOs and is written over a bit-banged SPI (16-bit words, register << 9 | value, MSB first).
 * Init sequence and register meanings: docs/code/ifdsp/control-link.md "TLV320AIC3204 initialisation".
 */
#include "fsl_common.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "codec.h"

/* Codec GPIOs (pin_mux.c BOARD_InitPins_codec_spi) */
#define AIC_RESET_PORT 1U
#define AIC_RESET_PIN  0U
#define AIC_MOSI_PORT  1U
#define AIC_MOSI_PIN   1U
#define AIC_SS_PORT    1U
#define AIC_SS_PIN     7U
#define AIC_SCLK_PORT  2U
#define AIC_SCLK_PIN   29U

typedef struct
{
    uint8_t reg;       /* register on the current page; register 0 selects the page */
    uint8_t value;
    uint16_t delay_us; /* wait after the write */
} aic3204_init_step_t;

/* 67 writes [fact: table at 0x87A1C] */
static const aic3204_init_step_t s_aic3204InitSequence[] = {
    {0x00, 0x00, 0}, {0x01, 0x01, 1000}, {0x00, 0x01, 1}, {0x01, 0x08, 0},
    {0x02, 0x01, 0}, {0x7B, 0x05, 50000}, {0x00, 0x00, 0}, {0x1B, 0x3C, 0},
    {0x1C, 0x00, 0}, {0x04, 0x03, 0}, {0x06, 0x05, 0}, {0x07, 0x00, 0},
    {0x08, 0x00, 0}, {0x1E, 0x84, 0}, {0x05, 0x91, 10000}, {0x0D, 0x00, 0},
    {0x0E, 0x40, 0}, {0x14, 0x40, 0}, {0x0B, 0x85, 0}, {0x0C, 0x84, 0},
    {0x12, 0x85, 0}, {0x13, 0x84, 0}, {0x00, 0x08, 0}, {0x01, 0x00, 0},
    {0x18, 0x7F, 0}, {0x19, 0xE3, 0}, {0x1A, 0x6C, 0}, {0x1C, 0x80, 0},
    {0x1D, 0x1C, 0}, {0x1E, 0x94, 0}, {0x20, 0x7F, 0}, {0x21, 0xC6, 0},
    {0x22, 0xDA, 0}, {0x00, 0x09, 0}, {0x20, 0x7F, 0}, {0x21, 0xE3, 0},
    {0x22, 0x6C, 0}, {0x24, 0x80, 0}, {0x25, 0x1C, 0}, {0x26, 0x94, 0},
    {0x28, 0x7F, 0}, {0x29, 0xC6, 0}, {0x2A, 0xDA, 0}, {0x00, 0x08, 0},
    {0x01, 0x04, 0}, {0x00, 0x01, 0}, {0x0E, 0x08, 0}, {0x0F, 0x08, 0},
    {0x00, 0x00, 0}, {0x40, 0x02, 0}, {0x41, 0x00, 0}, {0x3F, 0xD4, 0},
    {0x00, 0x01, 0}, {0x12, 0x00, 0}, {0x13, 0x00, 0}, {0x09, 0x0C, 100},
    {0x00, 0x01, 0}, {0x34, 0x40, 0}, {0x37, 0x40, 0}, {0x36, 0x40, 0},
    {0x39, 0x40, 0}, {0x3B, 0x00, 0}, {0x3C, 0x00, 0}, {0x00, 0x00, 0},
    {0x51, 0xC0, 0}, {0x52, 0x00, 0}, {0x00, 0x00, 100},
};

/* Busy wait of us x core clock / 1e6 loop iterations; each iteration takes several cycles, so the real delay is
   several times longer than asked [inference]. */
void delay_us(uint32_t us)
{
    uint32_t loops = us * CLOCK_GetFreq(kCLOCK_CoreSysClk) / 1000000U;

    for (uint32_t i = 0; i != loops; i++)
    {
        __NOP();
    }
}

/* One codec register write: CS low, 16 bits MSB first with 1 us half periods, CS high, 10 us gap. */
void aic3204_spi_write(uint8_t reg, uint8_t value)
{
    uint32_t word = ((uint32_t)reg << 9) | value; /* bit 0 of the address byte = 0: write */

    GPIO_PinWrite(GPIO, AIC_SS_PORT, AIC_SS_PIN, 0);
    delay_us(1);
    for (int bit = 16; bit != 0; bit--)
    {
        GPIO_PinWrite(GPIO, AIC_SCLK_PORT, AIC_SCLK_PIN, 1);
        GPIO_PinWrite(GPIO, AIC_MOSI_PORT, AIC_MOSI_PIN, (word & 0x8000U) ? 1 : 0);
        delay_us(1);
        GPIO_PinWrite(GPIO, AIC_SCLK_PORT, AIC_SCLK_PIN, 0);
        delay_us(1);
        word = (word & 0xFFFFU) << 1;
    }
    delay_us(1);
    GPIO_PinWrite(GPIO, AIC_SS_PORT, AIC_SS_PIN, 1);
    delay_us(10);
}

/* Hardware reset (20 ms low, 20 ms settle), then the init sequence. */
void aic3204_init(void)
{
    GPIO_PinWrite(GPIO, AIC_RESET_PORT, AIC_RESET_PIN, 0);
    GPIO_PinWrite(GPIO, AIC_SS_PORT, AIC_SS_PIN, 0);
    GPIO_PinWrite(GPIO, AIC_SCLK_PORT, AIC_SCLK_PIN, 0);
    GPIO_PinWrite(GPIO, AIC_MOSI_PORT, AIC_MOSI_PIN, 0);
    delay_us(20000);
    GPIO_PinWrite(GPIO, AIC_RESET_PORT, AIC_RESET_PIN, 1);
    delay_us(20000);

    const aic3204_init_step_t *step = s_aic3204InitSequence;
    for (int i = 0; i != ARRAY_SIZE(s_aic3204InitSequence); i++, step++)
    {
        aic3204_spi_write(step->reg, step->value);
        delay_us(step->delay_us);
    }
}

/* Right MICPGA input (page 1 register 55): IN2R when in2 is 1, else IN1R. Called by regfile_write for register 10. */
void aic3204_select_right_input(int in2)
{
    uint8_t route = (in2 == 1) ? 0x10U : 0x40U;

    aic3204_spi_write(0x00, 0x01); /* page 1 */
    aic3204_spi_write(0x37, route);
    aic3204_spi_write(0x00, 0x00); /* page 0 */
}
