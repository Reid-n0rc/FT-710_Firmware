/* CC-RX C library and runtime pieces of the MAIN image, recreated for T24 (docs/code/main/bsp.md).
 *
 * The library names are Ghidra's (docs/code/main/bsp.md: inferred from the code shape; the image has no symbols).
 * The low-level I/O ("lowsrc") is the E1/E2 debugger virtual console through the DBG registers, which the radio
 * never uses (no caller of write() reaches it outside the C library's own start-up) [fact: bsp.md]. */
#include <stdint.h>
#include "iodefine.h"
#include "main_ram.h"

#define DBG_C2E0    SFR32(0x84080u)   /* host -> E1/E2 data (the image writes 32 bits) */
#define DBG_E2C0    SFR32(0x84090u)   /* E1/E2 -> host data */
#define DBG_DBGSTAT SFR32(0x840C0u)   /* bit 8: C2E0 full, bit 12: E2C0 full */

#define HEAP_START 0x000203F4u        /* sbrk's heap area and its 0x400 bytes [fact: 0xFFF912D4..0xFFF912DA] */
#define HEAP_SIZE  0x400u

/* strncmp 0xFFFEDE1D: CC-RX's: stops at the first differing byte or after n bytes; unlike ISO C it does not stop
 * at a NUL that both strings share, so equal strings compare up to n bytes [fact: the loop 0xFFFEDE25..0xFFFEDE33
 * tests only the count and the bytes' equality] */
int strncmp(const char *a, const char *b, unsigned n)
{
    unsigned i = 0;

    if (n == 0u)
        return 0;
    do {
        if (i >= n)
            break;
        i++;
    } while ((uint8_t)*a++ == (uint8_t)*b++);
    return (int)((uint8_t)a[-1] - (uint8_t)b[-1]);
}

/* __udiv64 0xFFFEDE41: 64-bit unsigned quotient (n in R1:R2, d in R3:R4, quotient in R1:R2) [fact: the shift and
 * subtract loop 0xFFFEDE5F..0xFFFEDE77 and the 16-bit DIVU fast paths]. A zero divisor reaches DIVU by zero, whose
 * result the RX leaves undefined (R01US0071EJ0100, DIVU); the check does not draw it. */
uint64_t __udiv64(uint64_t n, uint64_t d)
{
    return n / d;
}

/* charput 0xFFF8F8BB: wait until the debugger has taken the previous byte, then write the next one */
void charput(uint8_t c)
{
    while (DBG_DBGSTAT & (1u << 8))
        __asm__ volatile("nop");
    DBG_C2E0 = c;
}

/* charget 0xFFF8F8D8: wait for a byte from the debugger */
uint8_t charget(void)
{
    while (!(DBG_DBGSTAT & (1u << 12)))
        __asm__ volatile("nop");
    return (uint8_t)DBG_E2C0;
}

/* close 0xFFF8FAC2: nothing to close; returns 1 */
long close(long fileno)
{
    (void)fileno;
    return 1;
}

/* sbrk 0xFFF912C7: grow the heap by size bytes inside its fixed 1 KB area; -1 when it does not fit (unsigned
 * compare of the new end with the area's end) */
char *sbrk(unsigned long size)
{
    char *p;

    if ((uintptr_t)heap_break + size > HEAP_START + HEAP_SIZE)
        return (char *)-1;
    p = (char *)heap_break;
    heap_break += size;
    return p;
}

/* heap_getmem 0xFFFEE29C: sbrk for sizes > 0 (signed test); NULL for a size <= 0 or when sbrk fails, else the
 * old end of the heap (stz #0, r1 keeps sbrk's result in R1 when it worked, 0xFFFEE2B2) */
char *heap_getmem(long size)
{
    char *p;

    if (size <= 0)
        return 0;
    p = sbrk((unsigned long)size);
    return p == (char *)-1 ? 0 : p;
}
