/*
 * FT-710 DISPLAY (T24 USB track): the ring indices of the scope, 3DSS and AF-FFT histories, 0x20164334..0x20164887
 * (docs/code/display/gui.md "Ring indices of the scope and AF-FFT histories"), and the 16-slot pointer ring of the
 * USB keyboard objects. Recreated from the image's disassembly.
 *
 * A ring index is one word holding the slot of the newest row: 100 rows of the AF-FFT waterfall, 133 of a scope
 * waterfall bank, 20 of the scope history, 30 lines of the 3DSS; one halfword for the 32-entry ring. The offset
 * functions use C's signed % (armcc's smull by the reciprocal and the sign fix-up [fact: 0x20164768..0x20164770]),
 * so an offset below -(n + idx) gives a negative slot, as in the image.
 */
#include <stdint.h>

/* 0x20164758 / 0x20164788 / 0x20164360: the 100-row AF-FFT ring (affft_wf_row_addr, affft_wf_add_row) [fact] */
int ring100_offset(const int *idx, int d)
{
    return (*idx + d + 100) % 100;
}

int ring100_next(const int *idx)
{
    int i = *idx + 1;

    return i == 100 ? 0 : i;
}

int ring100_advance(int *idx)
{
    int cur = *idx;

    *idx = ring100_next(idx);
    return cur;
}

/* 0x2016479C / 0x201647D0 / 0x20164388 / 0x201643A4: the 133-row waterfall bank ring [fact] */
int ring133_offset(const int *idx, int d)
{
    return (*idx + d + 133) % 133;
}

int ring133_next(const int *idx)
{
    int i = *idx + 1;

    return i == 133 ? 0 : i;
}

int ring133_advance(int *idx)
{
    int cur = *idx;

    *idx = ring133_next(idx);
    return cur;
}

void ring133_reset(int *idx)
{
    *idx = 0;
}

/* 0x201647E4 / 0x20164814 / 0x201643B0: the 20-row scope history ring [fact] */
int ring20_offset(const int *idx, int d)
{
    return (*idx + d + 20) % 20;
}

int ring20_next(const int *idx)
{
    int i = *idx + 1;

    return i == 20 ? 0 : i;
}

int ring20_advance(int *idx)
{
    int cur = *idx;

    *idx = ring20_next(idx);
    return cur;
}

/* 0x20164828 / 0x2016485C / 0x201643CC: the 30-line 3DSS ring [fact] */
int ring30_offset(const int *idx, int d)
{
    return (*idx + d + 30) % 30;
}

int ring30_next(const int *idx)
{
    int i = *idx + 1;

    return i == 30 ? 0 : i;
}

int ring30_advance(int *idx)
{
    int cur = *idx;

    *idx = ring30_next(idx);
    return cur;
}

/* 0x20164870 / 0x201643F0: a 32-entry ring with a halfword index [fact: ldrh, uxth, cmp #32] */
unsigned ring32_next(const uint16_t *idx)
{
    uint16_t i = (uint16_t)(*idx + 1);

    return i == 32 ? 0 : i;
}

unsigned ring32_post_inc(uint16_t *idx)
{
    uint16_t cur = *idx;

    *idx = (uint16_t)ring32_next(idx);
    return cur;
}

/* 0x20164334: (table, v): the 3DSS line widths, 30 halfwords 791 - 10 * i (gui.md: line i is 791 - 10i wide), then
 * the word v at +0x3C [fact] */
void scope3d_widths_init(uint16_t *t, uint32_t v)
{
    uint16_t w = 791;

    for (int i = 0; i < 30; i++)
    {
        t[i] = w;
        w = (uint16_t)(w - 10);
    }
    *(uint32_t *)(t + 30) = v;
}

/* The 16-slot ring of 8-byte records: {count, read index, write index} halfwords, then 16 record pointers at +8;
 * push copies a record into the slot at the write index, pop returns the slot pointer at the read index, or 0 when
 * empty; the USB keyboard objects keep their key ring in one (kbdobj_*: +0x88) [fact: 0x201645A0..0x2016464B] */
typedef struct
{
    uint16_t count;
    uint16_t rd;
    uint16_t wr;
    uint16_t pad;
    uint32_t *slot[16];
} ring16_t;

/* 0x201645A0: (ring, rec): nothing when full (count >= 16) */
void ring16_push(ring16_t *r, const uint32_t *rec)
{
    if (r->count >= 16)
    {
        return;
    }
    uint32_t a = rec[0], b = rec[1];
    uint32_t *s = r->slot[r->wr];

    s[0] = a;
    s[1] = b;
    r->wr = (r->wr + 1) & 15;
    r->count++;
}

/* 0x201645E4 */
void ring16_reset(ring16_t *r)
{
    r->count = 0;
    r->rd = 0;
    r->wr = 0;
}

/* 0x201645F8: (ring, i, p): slot i points at p */
void ring16_set_slot(ring16_t *r, int i, uint32_t *p)
{
    r->slot[i] = p;
}

/* 0x20164604 */
uint32_t *ring16_pop(ring16_t *r)
{
    if (r->count == 0)
    {
        return 0;
    }
    r->count--;
    uint16_t i = r->rd;

    r->rd = (i + 1) & 15;
    return r->slot[i];
}

/* 0x20164638: returns the ring */
ring16_t *ring16_ctor(ring16_t *r)
{
    ring16_reset(r);
    return r;
}
