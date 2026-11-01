/* The MAIN -> SDR unit register link on SCI5, recreated for T24 (docs/code/main/sdr-link.md): the SCI5 glue, the
 * frame layer (app/reglink.h, shared with the DSP link) and the register updaters whose value is a constant or one
 * menu setting. The shadows are filled by sdr_shadow_update from the replies. */
#include "main.h"
#include "main_ram.h"
#include "r_cg_sci.h"
#include "reglink.h"

#define SDR_REPLY_TIMER 2    /* soft timer of the reply timeout [fact: swtimer_start(2, 6), 0xFFFA31A8] */
#define SDR_RX_MAX      7u   /* a reply is at most "r" + 4 hex + 2 hex [fact: sdr_send_cmd 0xFFFB1B42] */

/* sdr_shadow (RAM 0x1B736, uint16 each): slot of each register [fact: the offset each updater compares] */
enum sdr_shadow_slot {
    SH_R03 = 2, SH_R04 = 3, SH_R0D = 9, SH_R0E = 10, SH_R12 = 12, SH_R13 = 13, SH_R15 = 15, SH_R1C = 21,
    SH_R23 = 28, SH_R24 = 29,
};

static const struct reglink sdr_link = {
    .frame = sdr_tx_frame, .reg = &sdr_tx_reg, .data = &sdr_tx_data, .shadow = sdr_shadow,
    .busy_write = &sdr_busy_write, .busy_read = &sdr_busy_read, .timer = SDR_REPLY_TIMER,
    .sum8 = sdr_sum8, .sum_ok = sdr_check_hex_sum, .send = sdr_send_cmd, .rx_ready = sdr_rx_ready,
    .rx_buf = sdr_rx_buf,
};

/* --- SCI5 glue (0xFFFB1AF8..0xFFFB1B4F) --- */

/* sdr_link_start 0xFFFB1AF8: no reply yet; start SCI5 (part of sci_start_all) */
void sdr_link_start(void)
{
    sdr_rx_done = 0;
    R_SCI5_Start();
}

/* sdr_rx_ready 0xFFFB1B06 */
uint8_t sdr_rx_ready(void)
{
    return sdr_rx_done;
}

/* sdr_rx_done_cb 0xFFFB1B15: SCI5's receive-end callback */
void sdr_rx_done_cb(void)
{
    sdr_rx_done = 1;
}

/* sdr_rx_buf 0xFFFB1B1F */
uint32_t sdr_rx_buf(void)
{
    return (uint32_t)(uintptr_t)sdr_rx_frame;
}

/* sdr_send_cmd 0xFFFB1B2B: send, then receive the reply (sci5_rx_byte_hook ends it early for ACK or "?") */
void sdr_send_cmd(uint32_t buf, uint16_t len)
{
    R_SCI5_Serial_Send((uint8_t *)(uintptr_t)buf, len);
    sdr_rx_done = 0;
    R_SCI5_Serial_Receive(sdr_rx_frame, SDR_RX_MAX);
}

/* --- frame layer --- */

/* sdr_sum8 0xFFFA31AE */
uint8_t sdr_sum8(const uint8_t *p, uint8_t n)
{
    return link_sum8(p, n);
}

/* sdr_check_hex_sum 0xFFFA31DB */
uint8_t sdr_check_hex_sum(const uint8_t *p, uint8_t n)
{
    return link_sum_ok(&sdr_link, p, n);
}

/* sdr_poll_reply 0xFFFA3083 */
uint8_t sdr_poll_reply(uint8_t kind, uint8_t **reply)
{
    return link_check_reply(&sdr_link, kind, reply);
}

/* sdr_send_frame 0xFFFA30F9 */
void sdr_send_frame(uint8_t kind)
{
    link_send_frame(&sdr_link, kind);
}

static inline void sdr_write_if_changed(uint16_t reg, enum sdr_shadow_slot slot, uint16_t value)
{
    link_write_if_changed(&sdr_link, sdr_send_frame, reg, slot, value);
}

/* --- register updaters (sdr-link.md "Register map") --- */

/* sdr_upd_r03 0xFFFA15A0: 0xE61D, with bit 5 set up to 60 MHz on VFO 1's TX side [fact: cmp #0x3B9ACA0] */
void sdr_upd_r03(void)
{
    uint32_t f = vfo_freq(1, 2);
    uint16_t v = 0xE61Du;

    if (f <= 60000000u)
        v |= 0x0020u;
    else
        v &= (uint16_t)~0x0020u;
    sdr_write_if_changed(0x03u, SH_R03, v);
}

/* sdr_upd_r04 0xFFFA15F3: constant 0xE519; it reads VFO 0's record pointer and does not use it [fact] */
void sdr_upd_r04(void)
{
    (void)vfo_rec_ptr(0);
    sdr_write_if_changed(0x04u, SH_R04, 0xE519u);
}

/* sdr_upd_r0d 0xFFFA18AE: 9 / 14 / 19 from the CW wave-shape setting (0x9AA1: 0, 1, other) */
void sdr_upd_r0d(void)
{
    uint8_t s = menu_cw_wave_shape;
    uint16_t v;

    if (s == 1u)
        v = 14;
    else if (s == 0u)
        v = 9;
    else
        v = 19;
    sdr_write_if_changed(0x0Du, SH_R0D, v);
}

/* constants [fact: the immediate of each updater] */
void sdr_upd_r0e(void) { sdr_write_if_changed(0x0Eu, SH_R0E, 0x1200u); }
void sdr_upd_r12(void) { sdr_write_if_changed(0x12u, SH_R12, 0x8000u); }
void sdr_upd_r13(void) { sdr_write_if_changed(0x13u, SH_R13, 0x8000u); }
void sdr_init_r15(void) { sdr_write_if_changed(0x15u, SH_R15, 0x2000u); }
void sdr_init_r24(void) { sdr_write_if_changed(0x24u, SH_R24, 0x0317u); }

/* sdr_upd_r1c 0xFFFA20AF: 2 / 5 / 10 from the NB REJECTION setting (0x9AD2: 0, other, 2) */
void sdr_upd_r1c(void)
{
    uint8_t s = menu_nb_rejection;
    uint16_t v;

    if (s == 2u)
        v = 10;
    else if (s == 0u)
        v = 2;
    else
        v = 5;
    sdr_write_if_changed(0x1Cu, SH_R1C, v);
}

/* sdr_upd_r23 0xFFFA2992: 0x7000 / 0x5000 / 0x8000 from the scope RBW setting (0x9B14: 1, 2, other) */
void sdr_upd_r23(void)
{
    uint8_t s = menu_scope_rbw;
    uint16_t v;

    if (s == 1u)
        v = 0x7000u;
    else if (s == 2u)
        v = 0x5000u;
    else
        v = 0x8000u;
    sdr_write_if_changed(0x23u, SH_R23, v);
}
