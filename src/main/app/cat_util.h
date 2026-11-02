/* Helpers shared by the CAT handler files (app/cat_handlers.c, app/cat_scope.c, ...; T24 MAIN). */
#ifndef CAT_UTIL_H
#define CAT_UTIL_H

#include "main.h"
#include "main_ram.h"
#include "ft710_state.h"

/* the reply: P1.. from cat_reply[2], ';' after the last byte */
static inline void reply_done(unsigned n)
{
    cat_reply[n] = ';';
    cat_reply_len = (uint16_t)(n + 1u);
}

/* a key code the set form is filtered with (key_event_filter); 0 refuses the command */
static inline int key_allowed(uint16_t key, uint8_t kind)
{
    if (key_event_filter(key, kind) == 0) {
        cat_error = 1;
        return 0;
    }
    return 1;
}

/* digits of v from the place value div down (100: three digits), as the image writes them: each digit is v / div
 * of what is left, through nib2hex [fact: the loops of cat_AG 0xFFFA6867, cat_KS, cat_RG] */
static inline void put_dec(uint8_t *at, uint8_t v, uint8_t div)
{
    for (; div != 0; div = (uint8_t)(div / 10u)) {
        uint8_t n = (uint8_t)(v / div);

        v = (uint8_t)(v - n * div);
        *at++ = (uint8_t)nib2hex(n);
    }
}

/* n decimal digits at p, place value div for the first, summed in 8 bits; 0 with cat_error set at a non-digit */
static inline int get_dec(const uint8_t *p, unsigned n, uint8_t div, uint8_t *out)
{
    uint8_t v = 0;
    unsigned i;

    for (i = 0; i < n; i++) {
        if (p[i] < '0' || p[i] > '9') {
            cat_error = 1;
            return 0;
        }
        v = (uint8_t)((p[i] & 0x0Fu) * div + v);
        div = (uint8_t)(div / 10u);
    }
    *out = v;
    return 1;
}

/* a setting's pop-up (code), unless EX030126 turns them off */
static inline void setting_popup(uint8_t code)
{
    if (g_opstate.ex030126_scu_lan10 == 0) {
        g_ui.popup_code = code;
        popup_open_timed(popup_duration_get(code));
    }
}

/* put_dec with a 16-bit value (cat_CO, cat_BP, cat_SH: the same loop over u16 locals) */
static inline void put_dec16(uint8_t *at, uint16_t v, uint16_t div)
{
    for (; div != 0; div = (uint16_t)(div / 10u)) {
        uint16_t n = (uint16_t)(v / div);

        v = (uint16_t)(v - n * div);
        *at++ = (uint8_t)nib2hex((uint8_t)n);
    }
}

/* get_dec with a 16-bit sum */
static inline int get_dec16(const uint8_t *p, unsigned n, uint16_t div, uint16_t *out)
{
    uint16_t v = 0;
    unsigned i;

    for (i = 0; i < n; i++) {
        if (p[i] < '0' || p[i] > '9') {
            cat_error = 1;
            return 0;
        }
        v = (uint16_t)((p[i] & 0x0Fu) * div + v);
        div = (uint16_t)(div / 10u);
    }
    *out = v;
    return 1;
}

/* the per-mode block of a record for a mode: CW blk 1, AM 4, FM and DATA-FM 5, DATA and PSK 3, RTTY 2, else
 * (LSB/USB and codes above PSK) 0 [fact: the compare chains of cat_CO 0xFFFA8698, cat_BP 0xFFFA7A71] */
static inline uint8_t mode_blk_index(uint8_t m)
{
    switch (m) {
    case MODE_CW_L: case MODE_CW_U:
        return 1;
    case MODE_AM: case MODE_AM_N:
        return 4;
    case MODE_FM: case MODE_FM_N: case MODE_DATA_FM: case MODE_DATA_FM_N:
        return 5;
    case MODE_DATA_L: case MODE_DATA_U: case MODE_PSK:
        return 3;
    case MODE_RTTY_L: case MODE_RTTY_U:
        return 2;
    default:
        return 0;
    }
}

static inline uint16_t be16(const uint8_t *p)
{
    return (uint16_t)(p[0] << 8 | p[1]);
}

static inline void put_be16(uint8_t *p, uint16_t v)
{
    p[0] = (uint8_t)(v >> 8);
    p[1] = (uint8_t)v;
}

/* u32 as 9 decimal digits, as the image prints it: each digit (v / place) through nib2hex [fact: cat_FA_FB
 * 0xFFFA9A21..0xFFFA9A4A] */
static inline void put_dec32(uint8_t *at, uint32_t v, uint32_t div)
{
    for (; div != 0; div /= 10u) {
        uint32_t n = v / div;

        v -= n * div;
        *at++ = (uint8_t)nib2hex((uint8_t)n);
    }
}

extern const uint8_t cat_mode_codes[];        /* 0xFFF806D0: the CAT mode character per mode index */
extern const uint8_t cat_vfo_state_codes[];   /* 0xFFF806DF: the CAT P7 character per VFO state */
extern const uint8_t cat_pms_names[][3];      /* 0xFFF806E9: names of the channels from 99 on */

/* the channel as three characters: 001..099, or the name of channel 99 + n [fact: add #-99, cat_IF_OI 0xFFFAA458;
 * cat_MR, cat_MC] */
static inline void put_channel(uint8_t *at, uint8_t ch)
{
    if (ch < 99u) {
        put_dec(at, (uint8_t)(ch + 1u), 100);
    } else {
        const uint8_t *nm = cat_pms_names[(uint8_t)(ch - 99u)];

        at[2] = nm[2];
        at[0] = nm[0];
        at[1] = nm[1];
    }
}

/* the clarifier offset (s16, big-endian) as sign and four digits */
static inline void put_clar_offset(uint8_t *at, const struct vfo_rec *r)
{
    uint16_t off = be16(r->clar_offset_be);

    if (r->clar_offset_be[0] & 0x80u) {
        at[0] = '-';
        off = (uint16_t)(~off + 1u);
    } else {
        at[0] = '+';
    }
    put_dec16(&at[1], off, 1000);
}

#endif
