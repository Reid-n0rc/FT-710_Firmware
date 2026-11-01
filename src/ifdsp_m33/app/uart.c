/*
 * FT-710 IFDSP M33: FLEXCOMM0 USART, the console/control link to MAIN (T24, recreated from the image 0x80CA4..0x80F4A,
 * 0x85FAE). 115200 baud, 8N1, interrupt driven with a 1 KiB ring buffer each way. The receive interrupt sets bit 0 of
 * an event group; CommandTask drains the receive ring into the console line editor (console.c).
 * Protocol: docs/code/ifdsp/control-link.md.
 */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "fsl_common.h"
#include "fsl_usart.h"
#include "fsl_gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "console.h"
#include "ipc.h"
#include "uart.h"

#define UART_RING_SIZE 1024U
#define UART_RING_MASK (UART_RING_SIZE - 1U)
#define UART_RX_EVENT  (1U << 0)

#define DEBUG_GPIO_PORT 2U /* PIO2_5 (TP2008) goes high when CommandTask starts */
#define DEBUG_GPIO_PIN  5U

static EventGroupHandle_t s_uartEvents;

typedef struct
{
    uint8_t buf[UART_RING_SIZE];
    uint32_t count;
    uint32_t head; /* next write */
    uint32_t tail; /* next read */
} uart_ring_t;

static uart_ring_t s_rx;
static uart_ring_t s_tx;

static char s_printBuf[256];

/* Queue up to len bytes for transmission; returns how many fit. */
int uart0_write(const void *data, int len)
{
    const uint8_t *p = data;
    int n;

    if (s_tx.count >= UART_RING_SIZE)
    {
        return 0;
    }
    taskENTER_CRITICAL();
    n = 0;
    do
    {
        s_tx.buf[s_tx.head] = p[n++];
        s_tx.head = (s_tx.head + 1U) & UART_RING_MASK;
        s_tx.count++;
        if (n == len)
        {
            break;
        }
    } while (s_tx.count < UART_RING_SIZE);
    if ((USART0->FIFOINTENSET & USART_FIFOINTENSET_TXLVL_MASK) == 0U)
    {
        USART0->FIFOINTENSET = USART_FIFOINTENSET_TXERR_MASK | USART_FIFOINTENSET_RXERR_MASK |
                               USART_FIFOINTENSET_TXLVL_MASK | USART_FIFOINTENSET_RXLVL_MASK;
    }
    taskEXIT_CRITICAL();
    return n;
}

void uart0_init(void)
{
    usart_config_t config;

    /* FRG0 from the FRG PLL clock (49.5 MHz), MULT 0 (divide by 1), to FLEXCOMM0 */
    CLOCK_SetFRGClock(&(const clock_frg_clk_config_t){0, kCLOCK_FrgPllDiv, 255, 0});
    CLOCK_AttachClk(kFRG_to_FLEXCOMM0);

    USART_GetDefaultConfig(&config);
    config.baudRate_Bps = 115200U;
    config.enableTx     = true;
    config.enableRx     = true;
    USART_Init(USART0, &config, CLOCK_GetFlexCommClkFreq(0U));

    s_uartEvents = xEventGroupCreate();
    USART_EnableInterrupts(USART0, kUSART_RxLevelInterruptEnable | kUSART_RxErrorInterruptEnable);
    EnableIRQ(FLEXCOMM0_IRQn);
}

static inline void uart0_reset_rx(void)
{
    taskENTER_CRITICAL();
    s_rx.tail  = 0;
    s_rx.head  = 0;
    s_rx.count = 0;
    taskEXIT_CRITICAL();
}

static inline void uart0_reset_tx(void)
{
    taskENTER_CRITICAL();
    s_tx.tail  = 0;
    s_tx.head  = 0;
    s_tx.count = 0;
    taskEXIT_CRITICAL();
}

/* The console task: feeds every received character to the line editor. */
void CommandTask(void *param)
{
    (void)param;
    console_init();
    uart0_reset_rx();
    uart0_reset_tx();
    uart0_init();
    GPIO_PinWrite(GPIO, DEBUG_GPIO_PORT, DEBUG_GPIO_PIN, 1);

    for (;;)
    {
        EventBits_t bits = xEventGroupWaitBits(s_uartEvents, UART_RX_EVENT, pdTRUE, pdFALSE, portMAX_DELAY);
        if ((bits & UART_RX_EVENT) == 0U)
        {
            continue;
        }
        while ((s_tx.count < UART_RING_SIZE) && (s_rx.count != 0U))
        {
            uint8_t c;

            taskENTER_CRITICAL();
            c        = s_rx.buf[s_rx.tail];
            s_rx.tail = (s_rx.tail + 1U) & UART_RING_MASK;
            s_rx.count--;
            taskEXIT_CRITICAL();
            console_rx_char(c);
        }
    }
}

void create_CommandTask(void)
{
    task_handles_t *handles = get_task_handles();

    if (xTaskCreate(CommandTask, "Command Task", 0x1800, handles, 1, &handles->command) != pdPASS)
    {
        for (;;)
        {
        }
    }
}

void FLEXCOMM0_IRQHandler(void)
{
    uint32_t stat = USART0->FIFOSTAT;

    if ((stat & (USART_FIFOSTAT_RXNOTEMPTY_MASK | USART_FIFOSTAT_RXERR_MASK)) != 0U)
    {
        BaseType_t woken = stat & USART_FIFOSTAT_RXERR_MASK;

        if (woken != 0)
        {
            /* receive error: drop the character, clear the flag */
            (void)USART0->FIFORD;
            USART0->FIFOSTAT = USART_FIFOSTAT_RXERR_MASK;
        }
        else if (s_rx.count < UART_RING_SIZE)
        {
            uint8_t c = (uint8_t)USART0->FIFORD;
            s_rx.count++;
            s_rx.buf[s_rx.head] = c;
            s_rx.head           = (s_rx.head + 1U) & UART_RING_MASK;
            if ((xEventGroupSetBitsFromISR(s_uartEvents, UART_RX_EVENT, &woken) != pdFAIL) && (woken != pdFALSE))
            {
                portYIELD_FROM_ISR(woken);
            }
        }
    }
    if ((stat & (USART_FIFOSTAT_TXNOTFULL_MASK | USART_FIFOSTAT_TXERR_MASK)) != 0U)
    {
        if (s_tx.count != 0U)
        {
            uint8_t c = s_tx.buf[s_tx.tail];
            s_tx.tail  = (s_tx.tail + 1U) & UART_RING_MASK;
            s_tx.count--;
            USART0->FIFOWR = c;
            if (s_tx.count != 0U)
            {
                return;
            }
        }
        USART0->FIFOINTENCLR = USART_FIFOINTENCLR_TXERR_MASK | USART_FIFOINTENCLR_TXLVL_MASK;
    }
}

/* printf to the link (used for the DSP replies, ipc.c). */
void uart0_printf(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vsprintf(s_printBuf, fmt, ap);
    va_end(ap);
    uart0_write(s_printBuf, strlen(s_printBuf));
}

bool uart0_tx_pending(void)
{
    return s_tx.count != 0U;
}

void console_puts(const char *s)
{
    uart0_write(s, strlen(s));
}
