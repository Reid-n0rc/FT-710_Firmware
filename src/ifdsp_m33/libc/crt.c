/*
 * FT-710 IFDSP M33 (T24): __main, the C library entry that ResetISR calls (through the veneer call_main).
 * The image's __main (Redlib, 0x872AE) opens the stdio streams (stdio_init 0x84E38) and tail-calls main [fact];
 * nothing in the application uses those streams, so this one only calls main.
 */
extern int main(void);

void __main(void)
{
    main();
    for (;;)
    {
    }
}
