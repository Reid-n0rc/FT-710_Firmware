/* The register-link protocol MAIN speaks with the IF DSP (SCI4, app/dsp_link.c) and the SDR unit (SCI5,
 * app/sdr_link.c), recreated for T24. The two are the same code with different buffers, flags and timers
 * [fact: dsp_send_frame 0xFFFA0B4C / sdr_send_frame 0xFFFA30F9, dsp_check_reply 0xFFFA0AD6 / sdr_poll_reply
 * 0xFFFA3083, dsp_sum8 0xFFFA0C01 / sdr_sum8 0xFFFA31AE match instruction for instruction apart from the
 * addresses], so it is written once here, over a constant description of each link, and folded per link.
 *
 * Frames (docs/code/main/dsp-link.md, sdr-link.md): "r" + 4 hex digits of the register, or "w" + register + 4 hex
 * digits of the value, then 2 hex digits of the 8-bit sum of the bytes before and CR. A read is answered with "r" +
 * 4 hex digits + their sum, a write with ACK (0x06). The register setters compare the value with the register's
 * shadow (the last value the other side confirmed) and send a write only when it differs. */
#ifndef REGLINK_H
#define REGLINK_H

#include "main.h"

#define LINK_READ  'r'
#define LINK_WRITE 'w'
#define LINK_ACK   0x06
#define LINK_REPLY_MS 6u

struct reglink {
    uint8_t *frame;              /* frame buffer */
    uint16_t *reg, *data;        /* register and value of the next frame */
    uint16_t *shadow;            /* shadows, uint16 per slot */
    uint8_t *busy_write, *busy_read;
    int32_t timer;               /* soft timer of the reply timeout */
    uint8_t (*sum8)(const uint8_t *p, uint8_t n);
    uint8_t (*sum_ok)(const uint8_t *p, uint8_t n);
    void (*send)(uint32_t buf, uint16_t len);
    uint8_t (*rx_ready)(void);
    uint32_t (*rx_buf)(void);
};

static inline uint8_t link_sum8(const uint8_t *p, uint8_t n)
{
    uint8_t sum = 0, i;

    for (i = 0; i < n; i++)
        sum = (uint8_t)(sum + p[i]);
    return sum;
}

/* 1 when the two hex digits after the first n bytes are their sum */
static inline uint8_t link_sum_ok(const struct reglink *l, const uint8_t *p, uint8_t n)
{
    char hex[2];

    byte2hex(hex, l->sum8(p, n));
    return (p[n] == (uint8_t)hex[0] && p[n + 1] == (uint8_t)hex[1]) ? 1u : 0u;
}

/* 1 when a good reply to the pending kind of transaction is in (*reply points to it); a received frame or the
 * expiry of the reply timer ends the transaction */
static inline uint8_t link_check_reply(const struct reglink *l, uint8_t kind, uint8_t **reply)
{
    uint8_t ok = 0;

    if (l->rx_ready() == 1u) {
        *reply = (uint8_t *)l->rx_buf();
        *l->busy_write = 0;
        *l->busy_read = 0;
        if (kind == LINK_READ) {
            if (l->sum_ok(*reply, 5) == 1u)
                ok = 1;
        } else if (**reply == LINK_ACK) {
            ok = 1;
        }
    } else if (swtimer_expired(l->timer) == 1u) {
        *l->busy_write = 0;
        *l->busy_read = 0;
    }
    return ok;
}

/* frame *reg (and *data for a write), mark the transaction busy, send, start the reply timer */
static inline void link_send_frame(const struct reglink *l, uint8_t kind)
{
    uint8_t n = 0;

    l->frame[n++] = kind;
    word2hex((int32_t)(uintptr_t)&l->frame[n], *l->reg);
    n = (uint8_t)(n + 4u);
    if (kind == LINK_WRITE) {
        word2hex((int32_t)(uintptr_t)&l->frame[n], *l->data);
        n = (uint8_t)(n + 4u);
        *l->busy_write = 1;
    } else {
        *l->busy_read = 1;
    }
    byte2hex((char *)&l->frame[n], l->sum8(l->frame, n));
    n = (uint8_t)(n + 2u);
    l->frame[n++] = '\r';
    l->send((uint32_t)(uintptr_t)l->frame, n);
    swtimer_start(l->timer, LINK_REPLY_MS);
}

/* the setters' common tail: write reg = value unless the shadow slot already holds it */
static inline void link_write_if_changed(const struct reglink *l, void (*send_frame)(uint8_t), uint16_t reg,
                                         unsigned slot, uint16_t value)
{
    if (l->shadow[slot] == value)
        return;
    *l->reg = reg;
    *l->data = value;
    send_frame(LINK_WRITE);
}

#endif
