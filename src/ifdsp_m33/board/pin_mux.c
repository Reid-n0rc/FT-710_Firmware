/*
 * FT-710 IFDSP M33 pin mux (T24), recreated from the image (0x84B78..0x84D34, 0x87242..0x872AE).
 * Pin table and nets: docs/code/ifdsp/m33-platform.md section 4. IOPCTL bits: FSEL[2:0], IBENA 0x40 (input buffer),
 * FULLDRIVE 0x100, IIENA 0x800 (input invert).
 * The original function names are not known: the five groups carry the descriptive names used in the Ghidra project,
 * and BOARD_InitPins is the function that calls them (0x87294). The file order matches the link order in the image.
 */
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iopctl.h"
#include "pin_mux.h"

#define FUNC0 0x000U     /* GPIO */
#define FUNC1 0x001U
#define FUNC2 0x002U
#define FUNC5 0x005U
#define IBENA 0x040U     /* input buffer enable */
#define FULLDRIVE 0x100U
#define IIENA 0x800U     /* input invert */

/* FLEXCOMM0 USART (MAIN link), FLEXCOMM1 SPI, codec MCLK, SCT0_OUT0 PWM, CLKIN */
void BOARD_InitPins_flexcomm(void)
{
    IOPCTL_PinMuxSet(IOPCTL, 0U, 1U, FUNC1);                  /* FC0_TXD  DSP_UMISO */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 10U, FUNC1);                 /* FC1_SSEL0 */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 2U, FUNC1 | IBENA);          /* FC0_RXD  DSP_UMOSI */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 7U, FUNC1 | IBENA);          /* FC1_SCK */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 8U, FUNC1 | IBENA);          /* FC1_TXD */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 9U, FUNC1 | IBENA);          /* FC1_RXD */
    IOPCTL_PinMuxSet(IOPCTL, 1U, 10U, FUNC1 | FULLDRIVE);     /* MCLK     AIC_MCLK */
    IOPCTL_PinMuxSet(IOPCTL, 2U, 2U, FUNC2);                  /* SCT0_OUT0 */
    IOPCTL_PinMuxSet(IOPCTL, 2U, 30U, FUNC5 | IBENA);         /* CLKIN    DSP_CLK 18.432 MHz */
}

/* GPIO inputs on port 0: AF_MUTE (PIO0_4), ADC0_0 test point (PIO0_5), TX and SEND_A from the SDR (PIO0_21/22) */
void BOARD_InitPins_P0(void)
{
    CLOCK_EnableClock(kCLOCK_HsGpio0);

    gpio_pin_config_t af_mute = {kGPIO_DigitalInput, 0};
    GPIO_PinInit(GPIO, 0U, 4U, &af_mute);
    gpio_pin_config_t adc0_0 = {kGPIO_DigitalInput, 0};
    GPIO_PinInit(GPIO, 0U, 5U, &adc0_0);
    gpio_pin_config_t tx = {kGPIO_DigitalInput, 0};
    GPIO_PinInit(GPIO, 0U, 21U, &tx);
    gpio_pin_config_t send_a = {kGPIO_DigitalInput, 0};
    GPIO_PinInit(GPIO, 0U, 22U, &send_a);

    IOPCTL_PinMuxSet(IOPCTL, 0U, 21U, FUNC0 | IBENA);
    IOPCTL_PinMuxSet(IOPCTL, 0U, 22U, FUNC0 | IBENA);
    IOPCTL_PinMuxSet(IOPCTL, 0U, 4U, FUNC0 | IBENA);
    IOPCTL_PinMuxSet(IOPCTL, 0U, 5U, FUNC0 | IBENA);
}

/* TLV320AIC3204 codec: reset and the bit-banged SPI (aic3204_spi_write) */
void BOARD_InitPins_codec_spi(void)
{
    CLOCK_EnableClock(kCLOCK_HsGpio1);
    CLOCK_EnableClock(kCLOCK_HsGpio2);

    gpio_pin_config_t aic_reset = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 1U, 0U, &aic_reset);
    gpio_pin_config_t aic_mosi = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 1U, 1U, &aic_mosi);
    gpio_pin_config_t aic_ss = {kGPIO_DigitalOutput, 1};
    GPIO_PinInit(GPIO, 1U, 7U, &aic_ss);
    gpio_pin_config_t aic_miso = {kGPIO_DigitalInput, 0};
    GPIO_PinInit(GPIO, 2U, 28U, &aic_miso);
    gpio_pin_config_t aic_sclk = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 2U, 29U, &aic_sclk);

    IOPCTL_PinMuxSet(IOPCTL, 1U, 0U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 1U, 1U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 1U, 7U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 2U, 28U, FUNC0 | IBENA);
    IOPCTL_PinMuxSet(IOPCTL, 2U, 29U, FUNC0);
}

/* I2S: FLEXCOMM2 to the SDR (TX audio), FLEXCOMM3/4 data in (RX IF, codec ADC), FLEXCOMM5 codec */
void BOARD_InitPins_i2s(void)
{
    IOPCTL_PinMuxSet(IOPCTL, 0U, 14U, FUNC1 | IBENA | FULLDRIVE | IIENA); /* FC2_SCK, inverted */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 15U, FUNC1 | IBENA | FULLDRIVE);         /* FC2_TXD_WS */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 16U, FUNC1 | FULLDRIVE);                 /* FC2 data out TX_AF_DAT */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 23U, FUNC1 | IBENA | FULLDRIVE);         /* FC3 data in RX_IF_DAT */
    IOPCTL_PinMuxSet(IOPCTL, 0U, 30U, FUNC1 | IBENA | FULLDRIVE);         /* FC4 data in AIC_DOUT */
    IOPCTL_PinMuxSet(IOPCTL, 1U, 3U, FUNC1 | IBENA | FULLDRIVE);          /* FC5_SCK AIC_BCLK */
    IOPCTL_PinMuxSet(IOPCTL, 1U, 4U, FUNC1 | IBENA | FULLDRIVE);          /* FC5_WS  AIC_WCLK */
    IOPCTL_PinMuxSet(IOPCTL, 1U, 5U, FUNC1 | FULLDRIVE);                  /* FC5 data out AIC_DIN */
}

/* Debug GPIO outputs, low: PIO0_28/29/31 (TP2043/2046/2044), PIO2_4/5/6 (TP2007/2008/2009) */
void BOARD_InitPins_debug_gpio(void)
{
    CLOCK_EnableClock(kCLOCK_HsGpio0);
    CLOCK_EnableClock(kCLOCK_HsGpio2);

    gpio_pin_config_t tp2043 = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 0U, 28U, &tp2043);
    gpio_pin_config_t tp2046 = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 0U, 29U, &tp2046);
    gpio_pin_config_t tp2044 = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 0U, 31U, &tp2044);
    gpio_pin_config_t tp2007 = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 2U, 4U, &tp2007);
    gpio_pin_config_t tp2008 = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 2U, 5U, &tp2008);
    gpio_pin_config_t tp2009 = {kGPIO_DigitalOutput, 0};
    GPIO_PinInit(GPIO, 2U, 6U, &tp2009);

    IOPCTL_PinMuxSet(IOPCTL, 0U, 28U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 0U, 29U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 0U, 31U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 2U, 4U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 2U, 5U, FUNC0);
    IOPCTL_PinMuxSet(IOPCTL, 2U, 6U, FUNC0);
}

void BOARD_InitPins(void)
{
    BOARD_InitPins_flexcomm();
    BOARD_InitPins_P0();
    BOARD_InitPins_codec_spi();
    BOARD_InitPins_i2s();
    BOARD_InitPins_debug_gpio();
}
