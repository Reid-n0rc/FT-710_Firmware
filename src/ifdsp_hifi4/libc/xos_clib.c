/*
 * FT-710 IFDSP HiFi4: the C-library support of Cadence XOS that the image links (recreated, T24): newlib's malloc
 * lock on an XOS mutex, the heap break, the stdio lock hooks and the stubbed system calls. XOS itself is Cadence's
 * (proprietary) and stays the image's code; only the calls below are made into it.
 */
#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <reent.h>
#include <sys/types.h>
#include "xos_api.h"

/* [fact] the C-library lock at 0x2CD6B0: an XOS mutex (owner thread at +0) followed by a recursion count (+32) and a
 * ready flag (+36) that the XOS start-up sets; the layout of the rest of the mutex is XOS's */
struct clib_lock {
    XosMutex mutex;
    int32_t count;
    uint8_t ready;
};

struct clib_lock clib_malloc_lock;      /* 0x2CD6B0 (data_symbols.tsv) */
char *clib_heap_ptr;                    /* 0x2CD6D8 */

#define HEAP_START ((char *)0x2CD860)   /* [fact] the first break (_sbrk_r 0x228E45): the end of .bss [inference] */
#define HEAP_LIMIT ((char *)0x480000)   /* [fact] 0x228E40: the end of the 4.5 MB SRAM */

/* 0x228DC0: recursive: the owning thread only counts */
void __malloc_lock(struct _reent *r)
{
    (void)r;
    if (!clib_malloc_lock.ready)
        return;
    if (clib_malloc_lock.mutex.owner != xos_curr_thread) {
        xos_mutex_lock(&clib_malloc_lock.mutex);
        clib_malloc_lock.count = 1;
        return;
    }
    clib_malloc_lock.count++;
}

/* 0x228DF0 */
void __malloc_unlock(struct _reent *r)
{
    (void)r;
    if (!clib_malloc_lock.ready || clib_malloc_lock.mutex.owner != xos_curr_thread || clib_malloc_lock.count == 0)
        return;
    if (--clib_malloc_lock.count == 0)
        xos_mutex_unlock(&clib_malloc_lock.mutex);
}

/* 0x228E34: the heap grows from the end of .bss to the end of SRAM; ENOMEM (12) and -1 when it would reach it */
void *_sbrk_r(struct _reent *r, ptrdiff_t incr)
{
    char *prev, *next;

    if (clib_heap_ptr == NULL)
        clib_heap_ptr = HEAP_START;
    prev = clib_heap_ptr;
    next = prev + incr;
    if ((uintptr_t)next >= (uintptr_t)HEAP_LIMIT) {
        r->_errno = ENOMEM;
        return (void *)-1;
    }
    clib_heap_ptr = next;
    return prev;
}

/* 0x235F40..0x235F70: newlib's stdio lock hooks, empty (one stdio user) [fact: entry; retw.n] */
void __sfp_lock_acquire(void) { }
void __sfp_lock_release(void) { }
void __sinit_lock_acquire(void) { }
void __sinit_lock_release(void) { }

/* 0x235F80, 0x235F90 (inside Ghidra's __sinit_lock_release): the per-stream lock walkers' callbacks, return 0 */
int __fp_lock(void *fp) { (void)fp; return 0; }
int __fp_unlock(void *fp) { (void)fp; return 0; }

/* 0x236420: no files: close succeeds */
int _close_r(struct _reent *r, int fd)
{
    (void)r;
    (void)fd;
    return 0;
}

/* 0x236430: no seekable files: ESPIPE (29) */
off_t _lseek_r(struct _reent *r, int fd, off_t pos, int whence)
{
    (void)fd;
    (void)pos;
    (void)whence;
    r->_errno = ESPIPE;
    return -1;
}
