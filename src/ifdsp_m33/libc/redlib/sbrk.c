/*
 * FT-710 IFDSP M33 (T24): _sbrk, recreated from the image's C library (NXP Redlib, closed source) at 0x85D48.
 * Moves the heap end up from the linker heap start; errno 12 (ENOMEM) when __check_heap_overflow refuses [fact: 0x85D48].
 */
extern int errno;
extern int __check_heap_overflow(void *new_end);
extern char _pvHeapStart[];

static char *s_heapEnd; /* 0x88B6C [fact: literal 0x85D78] */

void *_sbrk(int incr)
{
    char *old;
    char *end;

    if (s_heapEnd == 0)
    {
        s_heapEnd = _pvHeapStart;
    }
    old = s_heapEnd;
    end = old + ((incr + 3) & ~3);
    if (__check_heap_overflow(end))
    {
        errno = 12;
        return (void *)-1;
    }
    s_heapEnd = end;
    return old;
}
