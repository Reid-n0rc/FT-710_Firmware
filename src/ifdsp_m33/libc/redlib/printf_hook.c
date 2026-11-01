/*
 * FT-710 IFDSP M33 (T24): the hook that sprintf, snprintf and vsprintf pass to the printf core as its last argument
 * (0x872F5, Thumb) [fact: literal pools 0x85B04, 0x85B7C, 0x85BD8]; it returns 0 [fact: 0x872F4 movs r0, #0; bx lr].
 * Open: what the core calls it for (the floating-point conversions are the likely case, Redlib's "no float" printf);
 * would be settled by the call sites of the hook in the core 0x84EB0.
 */
int printf_float_none(void)
{
    return 0;
}
