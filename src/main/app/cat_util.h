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

#endif
