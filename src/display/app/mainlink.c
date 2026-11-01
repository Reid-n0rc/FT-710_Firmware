/*
 * FT-710 DISPLAY (T24 round 9): the MAIN link's state accessors and its ACK / NAK handling, 0x20115000..0x201150EB,
 * 0x2011593C..0x2011598B and 0x2011606C..0x2011639F (docs/code/display/mainlink.md). Recreated from the image's
 * disassembly.
 *
 * The link keeps its state in one block of .data at 0x20450024 (struct ml_state of tools/ghidra/structs_display.h,
 * whose field names are used here), the resend copy of the frame waiting for its ACK at 0x2045EFC0 and the newest
 * MAIN frames for the GUI at 0x2045F8C0 and 0x2045FB00 [fact: the literals].
 */
#include <stdint.h>
#include "norti.h"

struct ml_state
{
    uint8_t got24;            /* +0x00 a new 0x24 frame */
    uint8_t got21;            /* +0x01 a new 0x21 frame */
    uint8_t got60;            /* +0x02 a new 0x60 frame */
    uint8_t fwupdate_armed;   /* +0x03 */
    uint8_t hello_acked;      /* +0x04 */
    uint8_t err_box_on_fail;  /* +0x05 on link failure an error box instead of a reset */
    uint8_t ack_pending;      /* +0x06 a frame waits for its ACK */
    uint8_t enc_queue_mask;   /* +0x07 */
    uint8_t retry_count;      /* +0x08 */
    uint8_t wait_cmd;         /* +0x09 the command waiting for its ACK */
    uint8_t e0_wr, e0_rd;     /* +0x0A, +0x0B */
    uint8_t pot5_last[2];     /* +0x0C */
    uint8_t pot4_last[2];     /* +0x0E */
    uint8_t last_rx_cmd;      /* +0x10 */
    uint8_t last21[3];        /* +0x11 the last 0x21 frame's payload and the two bytes after it */
    uint32_t resend_len;      /* +0x14 */
    uint32_t pot5_sum;        /* +0x18 */
    uint8_t pot5_hist[4];     /* +0x1C */
    uint32_t pot4_sum;        /* +0x20 */
    uint8_t pot4_hist[4];     /* +0x24 */
    ID retry_flg;             /* +0x28 the retry task's event flag */
    int pace_count;           /* +0x2C */
    ID pace_sem;              /* +0x30 */
    ID enc_sem;               /* +0x34 */
    uint32_t got_esc;         /* +0x38 */
    uint8_t *link_obj;        /* +0x3C the link object (0x2045FD40) */
    ID ack_tmo_cyc;           /* +0x40 the ACK timeout's cyclic handler */
    uint8_t last_e1[5];       /* +0x44 the last E1 frame */
    uint8_t settings24[7];    /* +0x49 */
};
_Static_assert(sizeof(struct ml_state) == 0x50, "ml_state size");

extern struct ml_state g_ml;               /* 0x20450024 */
extern uint8_t ml_gui_snapshot[0x240];     /* 0x2045F8C0: the newest MAIN frame */
extern uint8_t ml_frame60[0x240];          /* 0x2045FB00: the newest 0x60 frame */
extern uint8_t ml_resend[];                /* 0x2045EFC0: the frame kept for a resend */
extern uint32_t ml_parked[3];              /* 0x2045F240: parked-frame ring state (0x2045EFC0 + 0x280) */
extern uint8_t ml_enc_queue[7][10][5];     /* 0x2045F0C5: the encoder queue, 7 x 10 entries of 5 bytes */

void __aeabi_memcpy(void *dst, const void *src, unsigned n);
int memcmp(const void *a, const void *b, unsigned n);
void ml_settings24_copy(void *out, const void *src);    /* 0x201636F8 */
void ml_enc_entry_clear(void *entry);                   /* 0x20163668 */
int mainlink_queue_frame(const void *frame, int len);   /* 0x20115494 */
void mainlink_flush_parked(void);                       /* 0x20115CFC */
void mainlink_flush_enc(void);                          /* 0x20115F5C */
void mainlink_tx_raw(const void *frame, uint32_t len);  /* 0x20115BE0 */
void mainlink_tx_e1_raw(const void *frame);             /* 0x20115C74 */
int gui_link_error_popup(int kind, int cmd);            /* 0x201309C0 */
int system_reboot(void);                                /* 0x20114DF4 */
uint8_t mainlink_get_wait_cmd(void);

/* 0x20115000 / 0x2011500C / 0x2011508C: copies of the frame snapshots (0x240 bytes each; the 0x60 one is read with
 * the same length) [fact] */
void mainlink_get_last_frame(void *out)
{
    __aeabi_memcpy(out, ml_gui_snapshot, 0x240);
}

void mainlink_get_frame60(void *out)
{
    __aeabi_memcpy(out, ml_frame60, 0x240);
}

void mainlink_set_last_frame(const void *in)
{
    __aeabi_memcpy(ml_gui_snapshot, in, 0x240);
}

/* 0x20115018: the "new 0x60 frame" flag [fact] */
uint8_t mainlink_got_frame60(void)
{
    return g_ml.got60;
}

/* 0x20115024: the 0x24 frame's settings to out; the "new 0x24 frame" flag [fact] */
uint8_t mainlink_get_settings24(void *out)
{
    ml_settings24_copy(out, g_ml.settings24);
    return g_ml.got24;
}

/* 0x2011503C: the last 0x21 payload and the two bytes after it to out; the "new 0x21 frame" flag [fact] */
uint8_t mainlink_get_last21(uint8_t *out)
{
    out[0] = g_ml.last21[0];
    out[1] = g_ml.last21[1];
    out[2] = g_ml.last21[2];
    return g_ml.got21;
}

/* 0x20115060: an ESC (0x1B) frame came [fact] */
uint32_t mainlink_got_esc(void)
{
    return g_ml.got_esc;
}

/* 0x2011506C: 1 when frame differs from the newest snapshot [fact] */
int mainlink_last_frame_differs(const void *frame)
{
    return memcmp(ml_gui_snapshot, frame, 0x240) != 0;
}

/* 0x201150E0 / 0x201150EC: the command waiting for its ACK [fact] */
void mainlink_set_wait_cmd(uint8_t cmd)
{
    g_ml.wait_cmd = cmd;
}

uint8_t mainlink_get_wait_cmd(void)
{
    return g_ml.wait_cmd;
}

/* 0x2011593C: (max?, four bytes): the largest (max != 0) or the smallest of four bytes, for the knob filters [fact] */
uint8_t minmax4(int want_max, const uint8_t *v)
{
    uint8_t m = v[0];

    for (unsigned k = 1; k < 4; k++)
    {
        if (want_max ? v[k] > m : v[k] < m)
        {
            m = v[k];
        }
    }
    return m;
}

/* 0x2011606C: an ACK (0x06) while a frame waits: the retry flag cleared, the timeout stopped, the parked frames and
 * (when queued) an encoder event sent, the retries reset [fact] */
void mainlink_on_ack(void)
{
    if (g_ml.ack_pending == 0)
    {
        return;
    }
    itron_clr_flg(g_ml.retry_flg, 0);
    itron_stp_cyc(g_ml.ack_tmo_cyc);
    g_ml.ack_pending = 0;
    mainlink_flush_parked();
    if (g_ml.enc_queue_mask != 0)
    {
        mainlink_flush_enc();
    }
    g_ml.retry_count = 0;
}

/* 0x201160B4: a NAK (0x15) while a frame waits: the timeout stopped; after three resends the error box (when the
 * 0x60 frame asked for it) or the reboot of both CPUs; else the frame again (the E1 copy for an E1) and the
 * timeout restarted [fact] */
void mainlink_on_nak(void)
{
    if (g_ml.ack_pending == 0)
    {
        return;
    }
    itron_stp_cyc(g_ml.ack_tmo_cyc);
    if (g_ml.retry_count >= 3)
    {
        if (g_ml.err_box_on_fail != 0)
        {
            gui_link_error_popup(0, mainlink_get_wait_cmd());
            return;
        }
        system_reboot();
        return;
    }
    if (mainlink_get_wait_cmd() == 0xE1)
    {
        mainlink_tx_e1_raw(g_ml.last_e1);
    }
    else
    {
        mainlink_tx_raw(ml_resend, g_ml.resend_len);
    }
    itron_sta_cyc(g_ml.ack_tmo_cyc);
    g_ml.retry_count++;
}

/* 0x20116140: drops the waiting frame, the parked ring and the encoder queue (the 0x7F maintenance key, the retry
 * task) [fact] */
void mainlink_tx_reset(void)
{
    itron_clr_flg(g_ml.retry_flg, 0);
    itron_stp_cyc(g_ml.ack_tmo_cyc);
    g_ml.ack_pending = 0;
    g_ml.enc_queue_mask = 0;
    g_ml.retry_count = 0;
    ml_parked[0] = 0;
    ml_parked[1] = 0;
    ml_parked[2] = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ml_enc_entry_clear(ml_enc_queue[i][j]);
        }
    }
}

/* 0x20116334: an F1 frame with one sub-command byte (no caller in V01-08) [fact] */
void mainlink_send_f1(uint8_t sub)
{
    uint8_t f[8] = {0xF1, sub, 0, 0, 0, 0, 0, 0};

    mainlink_queue_frame(f, 7);
}

/* 0x20116368 / 0x2011637C: the RX task's resync and NAK counters (link object +0x38, +0x48), 0 before it exists */
uint32_t mainlink_stat_rx_resync(void)
{
    return g_ml.link_obj != 0 ? *(const uint32_t *)(g_ml.link_obj + 0x38) : 0;
}

uint32_t mainlink_stat_nak_sent(void)
{
    return g_ml.link_obj != 0 ? *(const uint32_t *)(g_ml.link_obj + 0x48) : 0;
}

/* 0x20116390: the ACK timeout's cyclic handler wakes the retry task (flag bit 0) [fact] */
ER mainlink_ack_timeout_cyc(void)
{
    return itron_set_flg(g_ml.retry_flg, 1);
}
