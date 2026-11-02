/*
 * FT-710 DISPLAY (T24 USB track): the USB keyboard objects' small methods and state accessors (docs/code/display/
 * input.md "USB keyboard object methods", "USB HID"). Recreated from the image's disassembly.
 *
 * Two keyboard objects of 0xD0 bytes at 0x20811080 [fact: usbkbd_active, 13 << 4 = 0xD0]: +0x80 active, +0x81
 * present, +0x84 the device, +0x88 the key ring (scope_rings.c ring16_t).
 */
#include <stdint.h>

typedef struct ring16 ring16_t;
void ring16_reset(ring16_t *r);
ring16_t *ring16_ctor(ring16_t *r);
void usbkbd_flush_all(void);

typedef struct
{
    uint8_t pad[0x80];
    uint8_t active;      /* +0x80 */
    uint8_t present;     /* +0x81 */
    uint8_t pad2[2];
    void *device;        /* +0x84 */
    uint8_t ring[0x48];  /* +0x88 */
} kbdobj_t;

extern kbdobj_t usbkbd_objs[2];     /* 0x20811080 */
extern volatile struct
{
    uint8_t leds;       /* +0: the lock-LED state usbkbd_leds_refresh sends */
    uint8_t last_key;   /* +1 */
    uint8_t layout;     /* +2: the KEYBOARD LANGUAGE table, 0..10 */
} usbkbd_state;                     /* 0x2080010C */
extern volatile uint8_t usbkbd_mode[];   /* 0x20800128 */
extern void *kbd_current;                /* 0x208001C8 */

/* 0x2015F098: (obj, device, present): present flag and device; not present also clears the active flag [fact] */
void kbdobj_set_device(kbdobj_t *k, void *dev, int present)
{
    k->present = (uint8_t)present;
    k->device = dev;
    if (!present)
    {
        k->active = 0;
    }
}

/* 0x2015F0B4 / 0x2015F0C4 / 0x2015F0CC [fact] */
void kbdobj_activate(kbdobj_t *k)
{
    k->active = 1;
    ring16_reset((ring16_t *)k->ring);
}

void kbdobj_flush(kbdobj_t *k)
{
    ring16_reset((ring16_t *)k->ring);
}

kbdobj_t *kbdobj_ctor(kbdobj_t *k)
{
    ring16_ctor((ring16_t *)k->ring);
    return k;
}

/* 0x2010709C: the first active keyboard object, or 0 [fact] */
kbdobj_t *usbkbd_active(void)
{
    for (int i = 0; i < 2; i++)
    {
        if (usbkbd_objs[i].active)
        {
            return &usbkbd_objs[i];
        }
    }
    return 0;
}

/* 0x20107378: (layout): 11 and above select table 0 (JPN) [fact: cmp r0, #11; movcs r0, #0] */
void usbkbd_set_layout(unsigned layout)
{
    usbkbd_state.layout = (uint8_t)(layout >= 11 ? 0 : layout);
}

/* 0x2010738C: both key rings flushed and the byte 0x20800129 cleared [fact] */
void usbkbd_reset(void)
{
    usbkbd_flush_all();
    usbkbd_mode[1] = 0;
}

/* 0x20107E90 */
unsigned usbkbd_last_key(void)
{
    return usbkbd_state.last_key;
}

/* 0x20111218: (p): the word 0x208001C8 [fact] */
void kbd_set_current(void *p)
{
    kbd_current = p;
}
