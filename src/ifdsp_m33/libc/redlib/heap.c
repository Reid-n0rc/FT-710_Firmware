/*
 * FT-710 IFDSP M33 (T24): the C library heap, recreated from the image (NXP Redlib, closed source; malloc 0x84D3C,
 * free 0x872C4; the heap end moves with _sbrk, sbrk.c).
 *
 * A first-fit list of blocks {tag, size in words, next} in front of each allocation [fact: 0x84D3C]; free only retags
 * the block and merges the free blocks that follow it [fact: 0x872C4]. The list grows with _sbrk from the end of .bss
 * (0xA1EF8, the linker's heap start) up to 0xA2EF8 [fact: literal pools 0x85D7C, 0x85F84]. Nothing in the application
 * calls malloc: the only caller chain is stdio (fputc's buffer, _Csys_alloc) [fact: call graph], and FreeRTOS has its
 * own heap_4.
 */
#include <stddef.h>

typedef struct heap_block
{
    unsigned int tag; /* 0x10000000 free, 0x20000000 in use */
    int size;         /* payload in 32-bit words */
    struct heap_block *next;
} heap_block_t;

extern void *_sbrk(int incr);

static heap_block_t *s_heapList; /* 0x88B70 [fact: literal 0x84E00] */

void *malloc(size_t n)
{
    heap_block_t *b = s_heapList, *prev, *nx;
    unsigned words;
    int sz;

    if (n != 0)
    {
        words = (n + 3) >> 2;
        prev  = NULL;
        while (b != NULL)
        {
            if (b->tag == 0x10000000u)
            {
                for (;;)
                {
                    sz = b->size;
                    nx = b->next;
                    if (nx == NULL || nx->tag != 0x10000000u)
                        break;
                    b->size = nx->size + (sz + 3);
                    b->next = nx->next;
                }
                if ((int)words <= sz && sz <= (int)(words + 3))
                {
                    b->tag = 0x20000000u;
                    return b + 1;
                }
                if (words + 10 < (unsigned)sz)
                {
                    heap_block_t *rest;
                    b->size = words;
                    b->tag  = 0x20000000u;
                    rest    = (heap_block_t *)((char *)(b + 1) + ((n + 3) & ~3u));
                    b->next = rest;
                    rest->tag  = 0x10000000u;
                    rest->size = sz - words - 3;
                    rest->next = nx;
                    return b + 1;
                }
                if (nx == NULL)
                {
                    if (_sbrk(n - sz * 4) == (void *)-1)
                        return NULL;
                    b->tag  = 0x20000000u;
                    b->size = words;
                    return b + 1;
                }
            }
            prev = b;
            b    = b->next;
        }
        b = _sbrk(n + 12);
        if (b != (void *)-1)
        {
            b->next = NULL;
            b->tag  = 0x20000000u;
            b->size = words;
            if (prev != NULL)
                prev->next = b;
            else
                s_heapList = b;
            return b + 1;
        }
    }
    return NULL;
}

void free(void *p)
{
    heap_block_t *b = (heap_block_t *)p - 1, *nx;
    if (!p) return;
    b->tag = 0x10000000u;
    for (;;) {
        nx = b->next;
        if (!nx || nx->tag != 0x10000000u) break;
        b->size = b->size + 3 + nx->size;
        b->next = nx->next;
    }
}
