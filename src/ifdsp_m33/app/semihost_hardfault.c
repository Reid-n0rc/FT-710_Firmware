/*
 * FT-710 IFDSP M33: HardFault handler (T24, recreated from the image 0x85FEA).
 * The handler of MCUXpresso IDE projects' semihost_hardfault.c, rewritten from the instructions in the image: a fault
 * on a semihosting call (BKPT 0xAB) with no debugger attached is skipped and returns 32; any other fault spins.
 */
__attribute__((naked)) void HardFault_Handler(void)
{
    __asm volatile(
        ".syntax unified        \n"
        "    movs  r0, #4       \n" /* which stack was in use (EXC_RETURN bit 2) */
        "    mov   r1, lr       \n"
        "    tst   r0, r1       \n"
        "    beq   1f           \n"
        "    mrs   r0, psp      \n"
        "    b     2f           \n"
        "1:  mrs   r0, msp      \n"
        "2:  ldr   r1, [r0, #24]\n" /* stacked PC */
        "    ldrh  r2, [r1]     \n"
        "    movw  r3, #0xBEAB  \n" /* BKPT 0xAB */
        "    cmp   r2, r3       \n"
        "    beq   3f           \n"
        "    b     .            \n"
        "3:  adds  r1, #2       \n" /* return past the BKPT */
        "    str   r1, [r0, #24]\n"
        "    movs  r1, #32      \n" /* r0 of the semihosting call = 32 */
        "    str   r1, [r0]     \n"
        "    bx    lr           \n");
}
