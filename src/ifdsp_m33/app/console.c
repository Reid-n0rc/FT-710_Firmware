/*
 * FT-710 IFDSP M33: the console on the MAIN link (T24, recreated from the image 0x81274..0x81852).
 *
 * Characters from CommandTask (uart.c) go through a line editor (echo, backspace, Ctrl+C, ESC) into a 128-byte line,
 * which is split into at most 4 tokens of at most 15 characters. Two modes (docs/code/ifdsp/control-link.md):
 *  - interactive (after "i db01", the start-up mode): tokens are lower-cased and looked up in a table of four
 *    commands r, w, d, i; replies end with the "\r\n>> " prompt;
 *  - machine mode (after "i db00" or "IDB00cc"): MAIN's frames "rAAAAcc", "dAAAAcc", "iDB0xcc" (7 characters) and
 *    "wAAAADDDDcc" (11 characters), cc = 8-bit sum of the characters before it in hex; replies "rDDDDcc", ACK 0x06, "?".
 */
#include "ctype.h" /* libc/ctype.h: the Redlib character table */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "regfile.h"
#include "uart.h"
#include "console.h"

#define CONSOLE_MAX_ARGS  4
#define CONSOLE_TOKEN_LEN 16 /* 15 characters + NUL */
#define CONSOLE_LINE_LEN  0x80
#define CONSOLE_DUMP_REGS 0x40

#define PROMPT "\r\n>> "
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

typedef void (*console_handler_t)(char **argv, int argc);
typedef struct
{
    char name[16];
    console_handler_t handler;
} console_command_t;

static void console_cmd_r(char **argv, int argc);
static void console_cmd_w(char **argv, int argc);
static void console_cmd_d(char **argv, int argc);
static void console_cmd_i(char **argv, int argc);

/* The interactive commands [fact: table at 0x8795C] */
static const console_command_t s_commands[] = {
    {"r", console_cmd_r},
    {"w", console_cmd_w},
    {"d", console_cmd_d},
    {"i", console_cmd_i},
};

static char *s_argv[CONSOLE_MAX_ARGS];
static int s_lineLen;
static uint8_t s_interactive; /* 1: interactive commands, lower-casing; 0: machine frames */
static uint8_t s_echo;        /* 1: echo input and print prompts */
static char s_tokens[CONSOLE_MAX_ARGS][CONSOLE_TOKEN_LEN];
static char s_line[CONSOLE_LINE_LEN];
static uint8_t s_lineActive; /* a line is being collected */
static char s_printBuf[256];

/* "i db00": machine mode, no echo; "i db01": interactive with echo */
static void console_cmd_i(char **argv, int argc)
{
    if (argc != 2)
    {
        return;
    }
    if (strcmp(argv[1], "db00") == 0)
    {
        s_interactive = 0;
        s_echo        = 0;
    }
    else if (strcmp(argv[1], "db01") == 0)
    {
        s_interactive = 1;
        s_echo        = 1;
        console_puts(PROMPT);
    }
}

/* "w AAAA DDDD": write a register */
static void console_cmd_w(char **argv, int argc)
{
    if (argc != 3)
    {
        return;
    }
    uint16_t reg   = (uint16_t)strtoul(argv[1], NULL, 16);
    uint16_t value = (uint16_t)strtoul(argv[2], NULL, 16);
    regfile_write(reg, value);
    console_puts(PROMPT);
}

/* Dump 0x40 registers from reg, 8 per line; header is the line-start format. */
static void console_dump(uint16_t reg, const char *header)
{
    char buf[16];
    uint16_t end = reg + CONSOLE_DUMP_REGS;

    do
    {
        snprintf(buf, sizeof(buf), header, reg);
        console_puts(buf);
        for (int i = 0; i != 8; i++)
        {
            snprintf(buf, sizeof(buf), " %04X", regfile_read((uint16_t)(reg + i)));
            console_puts(buf);
            if (uart0_tx_pending())
            {
                vTaskDelay(1);
            }
        }
        reg += 8;
    } while (end != reg);
}

/* "d AAAA": dump 0x40 registers */
static void console_cmd_d(char **argv, int argc)
{
    if (argc != 2)
    {
        console_puts("\r\n?" PROMPT);
        return;
    }
    console_dump((uint16_t)strtoul(argv[1], NULL, 16), "\r\n %04X :");
    console_puts(PROMPT);
}

void console_printf(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vsprintf(s_printBuf, fmt, ap);
    va_end(ap);
    console_puts(s_printBuf);
}

/* "r AAAA": read a register */
static void console_cmd_r(char **argv, int argc)
{
    if (argc != 2)
    {
        console_puts("\r\n?" PROMPT);
        return;
    }
    uint16_t reg = (uint16_t)strtoul(argv[1], NULL, 16);
    console_printf("\r\nr %04X %04X" PROMPT, reg, regfile_read(reg));
}

void console_init(void)
{
    s_argv[0]     = s_tokens[0];
    s_argv[1]     = s_tokens[1];
    s_argv[2]     = s_tokens[2];
    s_argv[3]     = s_tokens[3];
    s_lineActive  = 0;
    s_lineLen     = 0;
    s_echo        = 1;
    s_interactive = 1;
}

static void console_reset_line(void)
{
    s_lineLen    = 0;
    s_lineActive = 0;
}

/* Machine-mode frame in argv[0]. */
static void console_machine_frame(const char *frame)
{
    char cmd        = frame[0];
    const char *hex = frame + 1;
    char field[5];
    const char *reply;

    if (!is_hex_string(hex))
    {
        return;
    }
    switch (strlen(frame))
    {
        case 7: /* cAAAAcc */
        {
            if (!frame_checksum_ok(frame, 5))
            {
                console_puts("?");
                return;
            }
            memcpy(field, hex, 4);
            field[4]     = 0;
            uint16_t reg = (uint16_t)strtoul(field, NULL, 16);
            if (cmd == 'd' || cmd == 'D')
            {
                console_dump(reg, "\r\n%04X :");
                console_puts("\r\n");
            }
            else if (cmd == 'r' || cmd == 'R')
            {
                char out[8];
                out[0] = 'r';
                sprintf(out + 1, "%04X", regfile_read(reg));
                sprintf(out + 5, "%02X", (uint8_t)(out[0] + out[1] + out[2] + out[3] + out[4]));
                console_puts(out);
            }
            else if (cmd == 'i' || cmd == 'I')
            {
                if (strncmp(field, "db", 2) == 0 || strncmp(field, "DB", 2) == 0)
                {
                    if (strncmp(field + 2, "00", 2) == 0)
                    {
                        s_interactive = 0;
                        s_echo        = 0;
                    }
                    else if (strncmp(field + 2, "01", 2) == 0)
                    {
                        s_interactive = 1;
                        s_echo        = 1;
                    }
                }
            }
            return;
        }
        case 11: /* wAAAADDDDcc */
        {
            if (!frame_checksum_ok(frame, 9))
            {
                console_puts("?");
                return;
            }
            memcpy(field, hex, 4);
            field[4]       = 0;
            uint16_t reg   = (uint16_t)strtoul(field, NULL, 16);
            memcpy(field, frame + 5, 4);
            uint16_t value = (uint16_t)strtoul(field, NULL, 16);
            if ((cmd & ~0x20) == 'W')
            {
                regfile_write(reg, value);
                reply = "\x06"; /* ACK */
                console_puts(reply);
            }
            return;
        }
        default:
            console_puts("?");
            return;
    }
}

/* A complete line: split it into tokens and run it. */
static void console_execute_line(void)
{
    const char *p   = s_line;
    const char *end = s_line + strlen(s_line) + 1; /* the NUL ends the last token */
    int argc        = 0;
    int pos         = 0;

    memset(s_tokens, 0, sizeof(s_tokens));

    /* skip leading white space */
    while (isspace((unsigned char)*p))
    {
        if (++p == end)
        {
            return;
        }
    }
    for (; p < end; p++)
    {
        unsigned char c = (unsigned char)*p;

        if (isspace(c) || c == 0)
        {
            /* end of a token; NUL, CR or LF ends the line */
            while (p != end && isspace((unsigned char)*p) && *p != '\r' && *p != '\n')
            {
                p++;
            }
            if (p == end)
            {
                break;
            }
            if (*p == 0 || *p == '\r' || *p == '\n')
            {
                argc++;
                goto run;
            }
            if (++argc == CONSOLE_MAX_ARGS)
            {
                break;
            }
            pos = 0;
            p--;
            continue;
        }
        s_tokens[argc][pos++] = (char)c;
        if (pos == CONSOLE_TOKEN_LEN - 1)
        {
            break;
        }
    }
    /* too many or too long tokens, or a line of white space */
    if (s_interactive)
    {
        console_puts("\r\n?" PROMPT);
    }
    return;

run:
    for (int i = 0; i != argc; i++)
    {
        int n = strlen(s_argv[i]);
        if (s_interactive)
        {
            for (int j = 0; j < n; j++)
            {
                s_argv[i][j] = (char)tolower((unsigned char)s_argv[i][j]);
            }
        }
        /* white space left in a token becomes NUL */
        for (n = strlen(s_argv[i]); --n >= 0;)
        {
            if (isspace((unsigned char)s_argv[i][n]))
            {
                s_argv[i][n] = 0;
            }
        }
    }
    if (!s_interactive)
    {
        console_machine_frame(s_argv[0]);
        return;
    }
    for (int k = 0; k != ARRAY_SIZE(s_commands); k++)
    {
        if (strcmp(s_argv[0], s_commands[k].name) == 0)
        {
            s_commands[k].handler(s_argv, argc);
            return;
        }
    }
    console_puts("\r\n?" PROMPT);
}

/* One character from the link. */
void console_rx_char(int c)
{
    uint8_t ch = (uint8_t)c;

    if (!(c >= 0x20 && c < 0x7F))
    {
        switch (c)
        {
            case 0:
                return;
            case 3: /* Ctrl+C */
                if (s_echo)
                {
                    console_puts(PROMPT);
                    if (s_echo)
                    {
                        console_puts("\r\nCtrl+C" PROMPT);
                    }
                }
                return;
            case 8: /* backspace */
            case 0x7F:
                if (s_lineLen < 1)
                {
                    return;
                }
                if (--s_lineLen == 0)
                {
                    s_lineActive = 0;
                }
                if (s_echo)
                {
                    uart0_write("\b \b", 3);
                }
                return;
            case 0x1B: /* ESC */
                if (s_echo)
                {
                    console_puts(PROMPT);
                }
                return;
            default:
                break;
        }
    }
    if (s_echo)
    {
        uart0_write(&ch, 1);
    }
    if (!s_lineActive)
    {
        if (!isspace(ch))
        {
            s_lineLen    = 1;
            s_line[0]    = (char)ch;
            s_lineActive = 1;
        }
        else if (ch == '\r' && s_echo)
        {
            console_puts(PROMPT);
        }
        return;
    }
    if (ch == 0 || ch == '\n' || ch == '\r')
    {
        s_line[s_lineLen] = 0;
        console_execute_line();
    }
    else
    {
        s_line[s_lineLen] = (char)ch;
        if (s_lineLen + 1 < CONSOLE_LINE_LEN)
        {
            s_lineLen++;
            return;
        }
    }
    console_reset_line();
}
