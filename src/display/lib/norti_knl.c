/*
 * FT-710 DISPLAY (T24 USB track): NORTi kernel helpers in C (docs/code/display/boot-rtos.md "NORTi memory and wait
 * helpers", "NORTi message buffer ring"): the first-fit free-list allocator of the kernel pools and its wrappers, the
 * message-buffer ring copy, and three small C++ helpers of the TX objects. Recreated from the image's disassembly.
 *
 * Only plain-C helpers are here. The service-call paths (svc, the dispatcher, the interrupt entry and exit, the
 * TCB queues) stay the image's kernel in the hybrid link.
 */
#include <stdint.h>
#include "norti.h"

/* a free block: {next, size}, address-ordered; the list head is a word whose "next" is the first block [fact:
 * knl_freelist_alloc starts with prev = the head's address, 0x20153B34] */
typedef struct knl_blk
{
    struct knl_blk *next;
    uint32_t size;
} knl_blk_t;

extern knl_blk_t knl_pool_main;          /* 0x208003FC: the system pool (head word) */
extern knl_blk_t knl_pool_mpl;           /* 0x208003F8: the memory-pool area, when configured */
extern knl_blk_t knl_pool_sys;           /* 0x208003F4: the control-block area, when configured */
extern const uint32_t knl_cfg_mpl_area;  /* 0x20165A34: non-zero selects knl_pool_mpl */
extern const uint32_t knl_cfg_sys_area;  /* 0x20165A30: non-zero selects knl_pool_sys */

/* 0x20153B34: (head, size): first fit, the size rounded up to 8; a block that fits exactly is unlinked, a larger
 * one keeps its tail on the list; 0 for size 0 or when nothing fits [fact] */
void *knl_freelist_alloc(knl_blk_t *head, uint32_t size)
{
    knl_blk_t *prev = head;

    size = (size + 7) & ~7u;
    if (size == 0)
    {
        return 0;
    }
    for (knl_blk_t *b = head->next; b != 0; prev = b, b = b->next)
    {
        uint32_t bsize = b->size;
        knl_blk_t *next = b->next;

        if (bsize < size)
        {
            continue;
        }
        if (bsize == size)
        {
            prev->next = next;
            return b;
        }
        knl_blk_t *rest = (knl_blk_t *)((uint8_t *)b + size);

        prev->next = rest;
        rest->next = next;
        rest->size = bsize - size;
        return b;
    }
    return 0;
}

/* 0x2015460C: (head, block, size): returns the block (size rounded up to 8) to the address-ordered list, merged
 * with the free block before and the one after when they touch; E_PAR (-17) when it overlaps either [fact] */
ER knl_freelist_free(knl_blk_t *head, knl_blk_t *blk, uint32_t size)
{
    knl_blk_t *prev = head, *cur = head->next, *n;
    uint32_t psize = 0;

    size = (size + 7) & ~7u;
    while (cur != 0)
    {
        if ((uintptr_t)cur > (uintptr_t)blk)
        {
            if ((uintptr_t)blk + size > (uintptr_t)cur)
            {
                return E_PAR;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
        psize = prev->size;
        if ((uintptr_t)prev + psize > (uintptr_t)blk)
        {
            return E_PAR;
        }
    }
    if ((uintptr_t)prev + psize == (uintptr_t)blk)
    {
        n = prev;
        size += psize;
    }
    else
    {
        prev->next = blk;
        n = blk;
    }
    if (cur == 0)
    {
        n->next = 0;
        n->size = size;
    }
    else if ((uintptr_t)n + size == (uintptr_t)cur)
    {
        n->next = cur->next;
        n->size = cur->size + size;
    }
    else
    {
        n->next = cur;
        n->size = size;
    }
    return E_OK;
}

/* 0x20154704: task stacks from the system pool (itron_acre_tsk) [fact] */
void *knl_stack_alloc(uint32_t size)
{
    return knl_freelist_alloc(&knl_pool_main, size);
}

/* 0x20154710: no caller in the image [fact] */
ER knl_sys_free_a(void *blk, uint32_t size)
{
    return knl_freelist_free(&knl_pool_main, blk, size);
}

/* 0x20154720 / 0x20154744: the buffers of itron_acre_mbf / acre_mpf / acre_mpl, from their own area when the
 * configuration word 0x20165A34 is set [fact] */
void *knl_pool_alloc(uint32_t size)
{
    return knl_freelist_alloc(knl_cfg_mpl_area ? &knl_pool_mpl : &knl_pool_main, size);
}

ER knl_pool_free(void *blk, uint32_t size)
{
    return knl_freelist_free(knl_cfg_mpl_area ? &knl_pool_mpl : &knl_pool_main, blk, size);
}

/* 0x2015476C / 0x20154790: the control blocks of the itron_acre_* calls, from their own area when 0x20165A30 is
 * set [fact] */
void *knl_sys_alloc(uint32_t size)
{
    return knl_freelist_alloc(knl_cfg_sys_area ? &knl_pool_sys : &knl_pool_main, size);
}

ER knl_sys_free(void *blk, uint32_t size)
{
    return knl_freelist_free(knl_cfg_sys_area ? &knl_pool_sys : &knl_pool_main, blk, size);
}

/* 0x201545F0: (dst, src, n): byte copy [fact] */
void knl_memcpy(uint8_t *dst, const uint8_t *src, uint32_t n)
{
    while (n--)
    {
        *dst++ = *src++;
    }
}

/* the message-buffer control block's ring part [fact: the offsets knl_mbf_get / knl_mbf_put use] */
typedef struct
{
    uint32_t hdr;
    uint8_t *buf;        /* +4 */
    uint16_t wr;         /* +8 */
    uint16_t rd;         /* +0xA */
    uint16_t size;       /* +0xC: ring bytes */
    uint16_t free;       /* +0xE */
    uint16_t maxmsz;     /* +0x10: 1 = one byte per message, no length */
} knl_mbf_t;

/* 0x201520B0: (mbf, dst): the next message out of the ring, after its 16-bit little-endian length (one byte and no
 * length when the maximum size is 1); returns its size [fact] */
uint32_t knl_mbf_get(knl_mbf_t *m, uint8_t *dst)
{
    uint8_t *buf = m->buf;
    uint32_t rd = m->rd;

    if (m->maxmsz == 1)
    {
        *dst = buf[rd];
        m->free++;
        rd++;
        m->rd = rd == m->size ? 0 : rd;
        return 1;
    }
    uint32_t size = m->size;
    uint32_t lo = buf[rd];

    if (++rd == size)
    {
        rd = 0;
    }
    uint32_t hi = buf[rd];

    if (++rd == size)
    {
        rd = 0;
    }
    uint16_t len = (uint16_t)(lo | hi << 8);
    uint16_t n = len;

    m->free = (uint16_t)(m->free + len + 2);
    if (len + rd >= size)
    {
        for (uint32_t k = rd; k < size; k++)
        {
            *dst++ = buf[k];
        }
        n = (uint16_t)(len - (size - rd));
        rd = 0;
    }
    buf = m->buf;
    m->rd = (uint16_t)(rd + n);
    for (uint32_t k = 0; k < n; k++)
    {
        *dst++ = buf[rd + k];
    }
    return len;
}

/* 0x20153CD4: (mbf, msg, size): one byte (maximum size 1), or the 16-bit length and the bytes with wrap-around;
 * 0 when there is no room (free < size + 2), else 1 [fact] */
int knl_mbf_put(knl_mbf_t *m, const uint8_t *msg, uint32_t len)
{
    uint32_t free = m->free;

    if (m->maxmsz == 1)
    {
        if (free == 0)
        {
            return 0;
        }
        m->free = (uint16_t)(free - 1);
        uint32_t wr = m->wr;

        m->buf[wr] = *msg;
        wr++;
        m->wr = wr == m->size ? 0 : wr;
        return 1;
    }
    if (free < len + 2)
    {
        return 0;
    }
    uint16_t n = (uint16_t)len;
    uint32_t wr = m->wr;

    m->free = (uint16_t)(free - n - 2);
    m->buf[wr] = (uint8_t)n;
    if (++wr == m->size)
    {
        wr = 0;
    }
    m->buf[wr] = (uint8_t)(n >> 8);
    if (++wr == m->size)
    {
        wr = 0;
    }
    uint32_t size = m->size;

    if (n + wr >= size)
    {
        uint8_t *p = m->buf + wr;
        uint32_t first = size - wr;

        n = (uint16_t)(n - first);
        while (first--)
        {
            *p++ = *msg++;
        }
        wr = 0;
    }
    uint8_t *p = m->buf + wr;

    m->wr = (uint16_t)(wr + n);
    while (n--)
    {
        *p++ = *msg++;
    }
    return 1;
}

/* 0x20158618: (obj): the two halfword indices +4 / +6 and the 0x80-byte buffer at +8 cleared (the TX objects of
 * mainlink_tx_init, uart4_tx_init, mainlink_disp_init, mouse_cursor_obj_init) [fact] */
void __aeabi_memclr4(void *dst, uint32_t n);
void msgbuf_init(uint8_t *obj)
{
    *(uint16_t *)(obj + 4) = 0;
    *(uint16_t *)(obj + 6) = 0;
    __aeabi_memclr4(obj + 8, 0x80);
}

/* 0x20162D10: a mailbox from the ROM packet 0x204283AC (16 bytes copied to the stack, mbxatr 0, maxmpri 1) with an
 * id the kernel chooses; returns the id or the error [fact] */
typedef struct
{
    uint32_t w[4];
} os_cmbx_t;
extern const os_cmbx_t os_mbx_fifo_pk;
ER os_mbx_create_fifo(void)
{
    os_cmbx_t pk = os_mbx_fifo_pk;

    return itron_acre_mbx(0, &pk);
}

/* 0x20162D3C: (this, id, msg): the object argument is not used [fact] */
ER os_mbx_send(void *self, ID id, void *msg)
{
    return itron_snd_mbx(id, msg);
}
