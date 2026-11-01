/*
 * FT-710 IFDSP M33 (T24): __check_heap_overflow, recreated from the image's C library (NXP Redlib, closed source) at 0x85F70.
 * Non-zero when a new heap end reaches the linker heap limit (none: never) [fact: 0x85F70].
 */
/* Open: the linker symbol names Redlib uses for the heap bounds; would be settled by the Redlib archive's undefined
 * symbols from an MCUXpresso IDE install. ifdsp_m33.ld defines these two. */
extern char _pvHeapLimit[] __attribute__((weak));

int __check_heap_overflow(void *new_end)
{
    if (_pvHeapLimit == 0)
    {
        return 0;
    }
    return (char *)new_end >= _pvHeapLimit;
}
