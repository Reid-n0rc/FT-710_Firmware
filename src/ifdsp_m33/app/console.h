/* FT-710 IFDSP M33: the console line editor and command interpreter (T24), see console.c. */
#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <stdint.h>

void console_init(void);
void console_rx_char(int c);
void console_printf(const char *fmt, ...);

/* console_frame.c */
int is_hex_string(const char *s);
int frame_checksum_ok(const char *frame, int len);

#endif /* CONSOLE_H_ */
