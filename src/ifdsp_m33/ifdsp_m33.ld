/*
 * FT-710 IFDSP M33 linker script (T24), after the image layout (docs/code/ifdsp/m33-platform.md sections 1-2):
 *   flash 0x08001000: vector table and boot header, MCUXpresso startup (ResetISR, IRQ stubs), system_*.c, the
 *                     GNU ld long-branch veneers, the three HiFi4 images and their size words, then the load image of
 *                     everything else;
 *   SRAM 0x00080000:  ResetISR's data_init copies all other code, constants and data there (the image runs from
 *                     SRAM); then .bss, the FreeRTOS heap (in .bss) and a 4 KB main stack below 0x200000.
 * Inside SRAM the input sections are sorted by alignment, as the image is: every 4-aligned function (those with a
 * literal pool) of every object first, then the 2-aligned ones [fact: functions.tsv addresses]. The section
 * tables are in the MCUXpresso managed-linker-script format the startup's data_init / bss_init read.
 */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08001000, LENGTH = 0x00FFF000
    SRAM  (rwx) : ORIGIN = 0x00080000, LENGTH = 0x0017F000
}

ENTRY(ResetISR)

SECTIONS
{
    .text_flash : ALIGN(4)
    {
        FILL(0xFF)
        __vectors_start__ = ABSOLUTE(.);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
        __section_table_start = .;
        __data_section_table = .;
        LONG(LOADADDR(.data));
        LONG(ADDR(.data));
        LONG(SIZEOF(.data));
        __data_section_table_end = .;
        __bss_section_table = .;
        LONG(ADDR(.bss));
        LONG(SIZEOF(.bss));
        __bss_section_table_end = .;
        __section_table_end = .;
        KEEP(*(.after_vectors.reset))
        *(.after_vectors*)
        *startup_mimxrt685s.o(.text*)
        *system_MIMXRT685S_cm33.o(.text*)
        *system_MIMXRT685S_cm33.o(.rodata*)
        . = ALIGN(4);
        KEEP(*(.dspcode))
        . = ALIGN(4);
    } > FLASH

    .data : ALIGN(4)
    {
        FILL(0xFF)
        *(CodeQuickAccess)
        *(SORT_BY_ALIGNMENT(.text*))
        . = ALIGN(4);
        *(SORT_BY_ALIGNMENT(.rodata*))
        . = ALIGN(4);
        *(DataQuickAccess)
        *(.data*)
        . = ALIGN(4);
    } > SRAM AT > FLASH

    .bss (NOLOAD) : ALIGN(4)
    {
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
    } > SRAM

    /DISCARD/ : { *(.ARM.exidx*) *(.ARM.attributes) *(.comment) }

    _image_size = LOADADDR(.data) + SIZEOF(.data) - ORIGIN(FLASH);   /* boot header +0x20 (0x642EC in the image) */
    __imghdr_loadaddress = ORIGIN(FLASH);                              /* boot header +0x34 */
    __imghdr_imagetype = 0;                                            /* plain XIP image */
    _vStackTop = 0x00200000;                                           /* MSP [fact: ResetISR] */
    _vStackBase = 0x001FF000;                                          /* MSPLIM [fact: ResetISR] */
}
