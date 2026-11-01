/*
 * FT-710 DISPLAY (T24 round 3): the GPIO helpers of the image (RZ/A1H ports P0..P11), recreated from the image.
 * Names and purposes as in docs/code/display/peripherals.md ("Pin multiplexing", "GPIO wrappers used at run time",
 * "GPIO pin helpers"); board signal names from there and docs/hardware.md.
 *
 * Register layout (RZ/A1H hardware manual, chapter 54 "Ports"; tools/ghidra/sfr_rza1h.tsv): Pn 0xFCFE3000 + 4n,
 * PSRn +0x100 (32 bit: mask in the upper half, value in the lower), PPRn +0x200, PMn +0x300, PMCn +0x400,
 * PFCn +0x500, PFCEn +0x600, PFCAEn +0xA00, PIBCn +0x4000, PBDCn +0x4100, PIPCn +0x4200. The port helpers reach Pn
 * through a table of pointers at 0x20800000 (.data2) [fact: literal in gpio_cfg_reset 0x201003A0; gpio_early_init
 * stores &P7 = 0xFCFE301C into entry 7].
 */
#include <stdint.h>

extern volatile uint16_t *gpio_port_regs[12];   /* 0x20800000 */
extern void system_reset_select(int v);
extern int itron_dly_tsk(int ms);

#define REG16(p, off) (*(volatile uint16_t *)((volatile uint8_t *)(p) + (off)))
#define PSR(n) (*(volatile uint32_t *)(0xFCFE3100U + 4U * (n)))
#define PPR(n) (*(volatile uint16_t *)(0xFCFE3200U + 4U * (n)))
#define O_P 0x000
#define O_PSR 0x100
#define O_PM 0x300
#define O_PMC 0x400
#define O_PFC 0x500
#define O_PFCE 0x600
#define O_PFCAE 0xA00
#define O_PIBC 0x4000
#define O_PBDC 0x4100
#define O_PIPC 0x4200

/* 0x201002AC: (Pn, mask | value << 16, flag): port mode for the pins in mask: PIBC, PBDC, PMC, PIPC off, PM input
 * while P is set (value != 0), then output; PSR = (flag ? mask : 0) | mask << 16 [fact] */
void gpio_cfg_mask(volatile uint16_t *pn, uint32_t mv, int flag)
{
    uint16_t m = (uint16_t)mv;

    if (pn == 0)
    {
        return;
    }
    REG16(pn, O_PIBC) &= (uint16_t)~m;
    REG16(pn, O_PBDC) &= (uint16_t)~m;
    REG16(pn, O_PM) |= m;
    REG16(pn, O_PMC) &= (uint16_t)~m;
    REG16(pn, O_PIPC) &= (uint16_t)~m;
    if (mv >> 16)
    {
        REG16(pn, O_P) |= m;
    }
    REG16(pn, O_PM) &= (uint16_t)~m;
    *(volatile uint32_t *)((volatile uint8_t *)pn + O_PSR) = (flag ? (mv & 0xFFFF) : 0) | mv << 16;
}

/* 0x201003A0: (port, pin): PIBC, PBDC, PMC, PIPC = 0, PM = 1 (input, port mode) [fact] */
void gpio_cfg_reset(int port, unsigned int pin)
{
    uint16_t b = (uint16_t)(1U << (pin & 0xFF));

    REG16(gpio_port_regs[port], O_PIBC) &= (uint16_t)~b;
    REG16(gpio_port_regs[port], O_PBDC) &= (uint16_t)~b;
    REG16(gpio_port_regs[port], O_PM) |= b;
    REG16(gpio_port_regs[port], O_PMC) &= (uint16_t)~b;
    REG16(gpio_port_regs[port], O_PIPC) &= (uint16_t)~b;
}

/* 0x20100414: (port, pin): gpio_cfg_reset, then output low [fact: bl 0x201003A0 at 0x20100428; Ghidra's decompiled
 * C of this and the next two helpers leaves the call out] */
void gpio_cfg_out_low(int port, unsigned int pin)
{
    uint16_t b = (uint16_t)(1U << (pin & 0xFF));

    gpio_cfg_reset(port, pin);
    REG16(gpio_port_regs[port], O_P) &= (uint16_t)~b;
    REG16(gpio_port_regs[port], O_PM) &= (uint16_t)~b;
}

/* 0x20100458: from cpg_early_init: P7_11 (RZ_PWR_ON) output low [fact] */
void gpio_early_init(void)
{
    system_reset_select(0);
    gpio_port_regs[7] = (volatile uint16_t *)0xFCFE301CU;
    gpio_cfg_out_low(7, 11);
}

/* 0x20100480: P7_11 and P7_9 together, through PSR7 [fact] */
void gpio_p7_9_11(int on)
{
    PSR(7) = on ? 0x08000800U : 0x08000000U;
    PSR(7) = on ? 0x02000200U : 0x02000000U;
}

/* 0x20100534: (port, pin, func 1..8): PFCAE, PFCE, PFC bits = func - 1 (bit 2, 1, 0); func 0 or > 8 leaves them
 * [fact] */
void gpio_set_alt_func(int port, unsigned int pin, unsigned int func)
{
    uint16_t b = (uint16_t)(1U << (pin & 0xFF));

    if (func - 1U > 7U)
    {
        return;
    }
    unsigned int f = func - 1U;
    if (f & 4)
        REG16(gpio_port_regs[port], O_PFCAE) |= b;
    else
        REG16(gpio_port_regs[port], O_PFCAE) &= (uint16_t)~b;
    if (f & 2)
        REG16(gpio_port_regs[port], O_PFCE) |= b;
    else
        REG16(gpio_port_regs[port], O_PFCE) &= (uint16_t)~b;
    if (f & 1)
        REG16(gpio_port_regs[port], O_PFC) |= b;
    else
        REG16(gpio_port_regs[port], O_PFC) &= (uint16_t)~b;
}

/* 0x20100658: (port, pin, func, mode): gpio_cfg_reset, gpio_set_alt_func, then mode 0: PIPC and PMC (direction by the
 * function), 1: input (PIPC 0, PMC, PM 1), 2: output (PIPC 0, PMC, PM 0), 3: bidirectional (PBDC, PIPC, PMC) [fact] */
void gpio_cfg_alt(int port, unsigned int pin, unsigned int func, int mode)
{
    uint16_t b = (uint16_t)(1U << (pin & 0xFF));

    gpio_cfg_reset(port, pin);
    gpio_set_alt_func(port, pin, func);
    switch (mode)
    {
        case 0:
            REG16(gpio_port_regs[port], O_PIPC) |= b;
            REG16(gpio_port_regs[port], O_PMC) |= b;
            break;
        case 1:
            REG16(gpio_port_regs[port], O_PIPC) &= (uint16_t)~b;
            REG16(gpio_port_regs[port], O_PMC) |= b;
            REG16(gpio_port_regs[port], O_PM) |= b;
            break;
        case 2:
            REG16(gpio_port_regs[port], O_PIPC) &= (uint16_t)~b;
            REG16(gpio_port_regs[port], O_PMC) |= b;
            REG16(gpio_port_regs[port], O_PM) &= (uint16_t)~b;
            break;
        case 3:
            REG16(gpio_port_regs[port], O_PBDC) |= b;
            REG16(gpio_port_regs[port], O_PIPC) |= b;
            REG16(gpio_port_regs[port], O_PMC) |= b;
            break;
        default:
            break;
    }
}

/* 0x20100838: (port, pin): gpio_cfg_reset, then output high [fact: bl 0x201003A0 at 0x2010084C] */
void gpio_cfg_out_high(int port, unsigned int pin)
{
    uint16_t b = (uint16_t)(1U << (pin & 0xFF));

    gpio_cfg_reset(port, pin);
    REG16(gpio_port_regs[port], O_P) |= b;
    REG16(gpio_port_regs[port], O_PM) &= (uint16_t)~b;
}

/* 0x2010087C: (port, pin): gpio_cfg_reset, then input buffer on (PIBC) [fact: bl 0x201003A0 at 0x2010088C] */
void gpio_cfg_input(int port, unsigned int pin)
{
    gpio_cfg_reset(port, pin);
    REG16(gpio_port_regs[port], O_PIBC) |= (uint16_t)(1U << (pin & 0xFF));
}

/* 0x201008AC: (port, bit) -> PPRn & (1 << bit), or 0xFFFFFFFF for a port above 11 [fact] */
uint32_t gpio_read_bit(unsigned int port, unsigned int bit)
{
    if (port > 11)
    {
        return 0xFFFFFFFFU;
    }
    return PPR(port) & (1U << (bit & 0xFF));
}

/* 0x20101BA4 .. 0x20101F8C: single pins through PSRn (mask in the upper half) [fact] */
void gpio_p8_14(int on) { PSR(8) = on ? 0x40004000U : 0x40000000U; }
void gpio_p4_7(int on) { PSR(4) = on ? 0x00800080U : 0x00800000U; }
void gpio_rx_reset(int on) { PSR(7) = on ? 0x04000400U : 0x04000000U; }     /* P7_10 RX_RESET */
void gpio_rx_update(int on) { PSR(4) = on ? 0x00080008U : 0x00080000U; }    /* P4_3 RX_UPDATE */
void gpio_p8_5(int on) { PSR(8) = on ? 0x00200020U : 0x00200000U; }         /* P8_5 SDR_MOSI */
void gpio_rx_update_b(int on) { PSR(4) = on ? 0x00080008U : 0x00080000U; }  /* a second copy of gpio_rx_update */
void gpio_qf_reset(int on) { PSR(11) = on ? 0x00040004U : 0x00040000U; }    /* P11_2 QF_RESETn */
void gpio_p2_15(int on) { PSR(2) = on ? 0x80008000U : 0x80000000U; }       /* P2_15 ACC_MOSI */
void gpio_p2_7(int on) { PSR(2) = on ? 0x00800080U : 0x00800000U; }
void gpio_ft4222_reset(int on) { PSR(2) = on ? 0x00800080U : 0x00800000U; } /* P2_7 FT4222_RESET, same as gpio_p2_7 */

/* 0x20101CD4: three-way select on P2_4 / P2_5 / P10_1: 0 -> P10_1, 1 -> P2_5, 2 -> P2_4, else none [fact] */
void gpio_p2_4_5_select(int sel)
{
    uint32_t p2 = 0, p10 = 0;

    if (sel == 0)
        p10 = 2;
    else if (sel == 1)
        p2 = 0x20;
    else if (sel == 2)
        p2 = 0x10;
    PSR(2)  = p2 | 0x300000U;
    PSR(10) = p10 | 0x20000U;
}

/* 0x20101D14: P2_4, P2_5 and P10_1 low [fact] */
void gpio_p2_4_5_clear(void)
{
    PSR(2)  = 0x300000U;
    PSR(10) = 0x20000U;
}

/* 0x20101D2C: RX_UPDATE low when the argument is not 0 [fact] */
void gpio_rx_update_off(int v)
{
    if (v != 0)
    {
        gpio_rx_update_b(0);
    }
}

/* 0x20101D40, 0x20101D50, 0x20101D60: P8_6..P8_9 = 0b0011, 0b1000, 0b0110 [fact] */
void gpio_p8_6to9_3(void) { PSR(8) = 0x03C000C0U; }
void gpio_p8_6to9_8(void) { PSR(8) = 0x03C00200U; }
void gpio_p8_6to9_6(void) { PSR(8) = 0x03C00180U; }

/* 0x20101DA4: (port, on): P8_10 USB0_EN, only for USB port 0 [fact] */
void gpio_usb0_en(int port, int on)
{
    if (port == 0)
    {
        PSR(8) = on ? 0x04000400U : 0x04000000U;
    }
}

/* 0x20101DC4: (dvr0, dvr1): P5_9 DVR0 and P5_8 DVR1 in one PSR5 write [fact] */
void gpio_dvr(int dvr0, int dvr1)
{
    PSR(5) = (dvr0 ? 0x02000200U : 0x02000000U) | (dvr1 ? 0x01000100U : 0x01000000U);
}

/* 0x201131E8: (port, bit) -> 1 when PPRn bit is set, for ports 2, 3, 7, 8, 9, 10; 0 otherwise [fact] */
int gpio_read_port_bit(unsigned int port, unsigned int bit)
{
    uint32_t m = 1U << (bit & 0xFF);

    switch (port)
    {
        case 2:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
            return (PPR(port) & m) != 0;
        default:
            return 0;
    }
}

/* 0x20116E30: P2_0 debounced: read until three samples 10 ms apart agree [fact] */
int gpio_p2_0_debounced(void)
{
    uint32_t v = gpio_read_bit(2, 0);
    int same   = 0;

    do
    {
        itron_dly_tsk(10);
        uint32_t w = gpio_read_bit(2, 0);
        if (w != v)
        {
            same = 0;
            v    = w;
        }
        same++;
    } while (same < 3);
    return v != 0;
}

/* 0x20117260: 1 when P8_12 reads high [fact] */
int gpio_p8_12_high(void)
{
    return gpio_read_bit(8, 12) != 0;
}
