/*
 * FT-710 IFDSP HiFi4: the Cadence XOS calls the recreated code makes (T24). XOS is proprietary and is not recreated:
 * these are its entry points in the image as the image's callers use them (arguments from the call sites,
 * docs/code/ifdsp/hifi4.md and hifi4-libraries.md). Names follow Cadence's XOS API [inference: the strings and the
 * call pattern, hifi4.md "XOS threads"].
 */
#ifndef XOS_API_H
#define XOS_API_H

#include <stdint.h>

typedef struct XosThread XosThread;

/* a mutex: the owning thread at +0 [fact: __malloc_lock 0x228DCE compares it with the current thread]; 32 bytes
 * [fact: the C-library lock keeps its count at +32] */
typedef struct {
    XosThread *owner;
    uint32_t priv[7];
} XosMutex;

/* the running thread [fact: 0x237858, read by __malloc_lock/__malloc_unlock; name: inference] */
extern XosThread *xos_curr_thread;

int32_t xos_mutex_create(XosMutex *mutex, uint32_t flags, uint8_t priority);
int32_t xos_mutex_lock(XosMutex *mutex);
int32_t xos_mutex_unlock(XosMutex *mutex);
int32_t xos_interrupt_enable(uint32_t intnum);
int32_t xos_interrupt_disable(uint32_t intnum);
int32_t xos_register_interrupt_handler(uint32_t intnum, void (*handler)(void *), void *arg);

#endif
