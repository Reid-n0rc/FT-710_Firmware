/*
 * FT-710 DISPLAY (T24 USB track): parts of the USB host HID class driver ("UHHID", docs/code/display/input.md "USB
 * host HID class driver"): the HID report field extract, the short-item reader of the report-descriptor parser, the
 * interrupt-IN endpoint search and the interrupt pipe read. Recreated from the image's disassembly.
 */
#include <stdint.h>

int usbh_pipe_xfer(int port, void *pipe, void *buf, uint32_t len);

/* 0x2091CB78: the two HID device slots, 24 bytes each, word 0 the device record [fact: usbhid_pipe_read] */
extern struct
{
    uint8_t *dev;
    uint32_t w[5];
} usbhid_slots[2];

/* 0x2013BBB4: (report, bit offset, bit count): a little-endian bit field; the whole bytes from the first byte
 * boundary are gathered first, then shifted up by the leading bits of the first byte; count 32 and more gives every
 * gathered bit (ARM's register shift: 1 << 32 is 0) [fact] */
uint32_t hid_report_bits_get(const uint8_t *rep, int off, int n)
{
    int lead = off & 7;
    int start = off, rest = n;
    uint32_t v = 0;

    if (lead != 0)
    {
        start = (off + 7) & ~7;
        rest = n - (start - off);
    }
    for (int k = 0; k < rest; k += 8)
    {
        v |= (uint32_t)rep[(start + k) >> 3] << k;
    }
    if (lead != 0)
    {
        v = (v << (8 - lead)) | (rep[off >> 3] >> lead);
    }
    return ((1u << n) - 1) & v;
}

/* 0x2013BC30: (&pos, out, signed): the data of the short item at *pos (size code: the prefix's low two bits), sign
 * extended when asked; *pos moves past the item. Size code 3 (four bytes) reads only the first two bytes, as code
 * 2 does, but skips all four [fact: 0x2013BC60..0x2013BC94] */
void hid_item_data(const uint8_t **pos, uint32_t *out, int sign)
{
    const uint8_t *p = *pos + 1;

    switch (**pos & 3)
    {
    case 0:
        *out = 0;
        *pos += 1;
        return;
    case 1:
        *out = p[0];
        if (sign && (p[0] & 0x80))
        {
            *out = p[0] | 0xFFFFFF00u;
        }
        *pos += 2;
        return;
    case 2:
        *out = p[0] | p[1] << 8;
        if (sign && (p[1] & 0x80))
        {
            *out = p[0] | p[1] << 8 | 0xFFFF0000u;
        }
        *pos += 3;
        return;
    default:
        *out = p[0] | p[1] << 8;
        if (sign && (p[1] & 0x80))
        {
            *out = p[0] | p[1] << 8 | 0xFFFF0000u;
        }
        *pos += 5;
        return;
    }
}

/* the configuration record the host stack hands the class driver: +0x1C the number of endpoint entries, +0x850 a
 * word the slot keeps, 12-byte endpoint entries at +0x860 {address, attributes, ., ., max packet word} [fact: the
 * offsets usbhid_find_int_in reads; entry 0 is never examined] */
typedef struct
{
    uint32_t cfg;
    int ep;
    int maxp;
} usbhid_ep_t;

/* 0x2013C7C4: (slot, config): the first interrupt (attributes 3) IN (address bit 7) endpoint of entries 1..n-1;
 * 0 when there is one with a max packet of 1..256, else -1 [fact] */
int usbhid_find_int_in(usbhid_ep_t *s, const uint8_t *c)
{
    s->ep = -1;
    s->maxp = 0;
    s->cfg = *(const uint32_t *)(c + 0x850);
    for (int i = 1; i < *(const int *)(c + 0x1C); i++)
    {
        const uint8_t *e = c + 0x860 + 12 * i;

        if (e[1] == 3 && (e[0] & 0x80) && s->ep < 0)
        {
            s->ep = i;
            s->maxp = *(const int *)(e + 4);
        }
    }
    if (s->ep < 0 || s->maxp <= 0 || s->maxp > 256)
    {
        return -1;
    }
    return 0;
}

/* 0x2013C76C: (slot, pipe index, buf, len): -1 without a device; else a transfer on the device's pipe +0x8D8 + 4i
 * of its port (+8) [fact] */
int usbhid_pipe_read(int slot, int pipe, void *buf, uint32_t len)
{
    uint8_t *dev = usbhid_slots[slot].dev;

    if (dev == 0)
    {
        return -1;
    }
    return usbh_pipe_xfer(*(int *)(dev + 8), *(void **)(dev + 0x8D8 + 4 * pipe), buf, len);
}
