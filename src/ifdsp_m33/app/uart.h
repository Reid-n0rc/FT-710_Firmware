/* FT-710 IFDSP M33: FLEXCOMM0 USART, the console/control link to MAIN (T24), see uart.c. */
#ifndef UART_H_
#define UART_H_

#include <stdbool.h>

int uart0_write(const void *data, int len);
void uart0_init(void);
void uart0_printf(const char *fmt, ...);
bool uart0_tx_pending(void);
void console_puts(const char *s);
void CommandTask(void *param);
void create_CommandTask(void);

#endif /* UART_H_ */
