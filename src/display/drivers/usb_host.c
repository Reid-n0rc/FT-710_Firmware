/*
 * FT-710 DISPLAY (T24 USB track): the USB host stack's small parts (docs/code/display/input.md "USB host requests",
 * "USB host", "USB host helpers", "USB host pipes"): the standard requests, the port context, the bounce test, the
 * two interrupt entries, the pipe transfer switch and the pipe-done mark. Recreated from the image's disassembly.
 *
 * Both RZ/A1H USB ports run as hosts (USB0 registers 0xE8010000, USB1 0xE8207000; GIC 73/74) [fact: usbh0_isr,
 * usbh1_isr literals]. A port context is 0x4D8 bytes at 0x2090B660 + 0x4D8 * port [fact: usbh_port_ctx].
 */
#include <stdint.h>
#include "norti.h"

/* a SETUP packet, 8 bytes (USB 2.0 9.3), built on the caller's stack [fact: the strb/strh at sp+8..sp+15] */
typedef struct
{
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} usb_setup_t;

int usbh_control_transfer(int pipe, void *dev, const usb_setup_t *setup, void *buf, uint32_t len);
int usbh_port_isr(int port, uint32_t regs);
int usbh_pipe_read(void *pipe, void *buf, uint32_t len);
int usbh_pipe_write(void *pipe, const void *buf, uint32_t len);

extern uint8_t usbh_ports[];              /* 0x2090B660: two 0x4D8-byte port contexts */
extern uint32_t usbh_bounce_mask;         /* 0x20808AB8 */
extern uint8_t usbh_pipe_slots[];         /* 0x2091C220: 0x34 bytes per port */

/* 0x20138F00: (pipe, dev, setup, buf, len): usbh_control_transfer with the same five arguments [fact] */
int usbh_control_req(int pipe, void *dev, const usb_setup_t *setup, void *buf, uint32_t len)
{
    return usbh_control_transfer(pipe, dev, setup, buf, len);
}

/* 0x2013B35C: (dev, buf, len): GET_DESCRIPTOR (0x80, 6), device (wValue 0x0100) [fact] */
int usbh_get_device_descriptor(void *dev, void *buf, uint32_t len)
{
    usb_setup_t s = {0x80, 6, 0x0100, 0, (uint16_t)len};

    return usbh_control_req(0, dev, &s, buf, len);
}

/* 0x2013B3A8: (dev, buf, len): GET_DESCRIPTOR (0x80, 6), configuration (wValue 0x0200) [fact] */
int usbh_get_config_descriptor(void *dev, void *buf, uint32_t len)
{
    usb_setup_t s = {0x80, 6, 0x0200, 0, (uint16_t)len};

    return usbh_control_req(0, dev, &s, buf, len);
}

/* 0x2013B3F4: (dev, address): SET_ADDRESS (0, 5) [fact] */
int usbh_set_address(void *dev, uint32_t addr)
{
    usb_setup_t s = {0, 5, (uint16_t)addr, 0, 0};

    return usbh_control_req(0, dev, &s, 0, 0);
}

/* 0x2013B43C: (dev, configuration): SET_CONFIGURATION (0, 9) [fact] */
int usbh_set_configuration(void *dev, uint32_t cfg)
{
    usb_setup_t s = {0, 9, (uint16_t)cfg, 0, 0};

    return usbh_control_req(0, dev, &s, 0, 0);
}

/* 0x2013B484: (dev, buf, len): GET_DESCRIPTOR of the class (0xA0, 6) with wValue 0: the hub class's descriptor type
 * 0x29 is not set [fact: strh r1 (0) at sp+10] */
int usbh_get_hub_descriptor(void *dev, void *buf, uint32_t len)
{
    usb_setup_t s = {0xA0, 6, 0, 0, (uint16_t)len};

    return usbh_control_req(0, dev, &s, buf, len);
}

/* 0x2013B524: the host stack's critical section: itron_loc_cpu, then 0 [fact] */
int usbh_loc_cpu(void)
{
    itron_loc_cpu();
    return 0;
}

/* 0x2013B58C / 0x2013B598: the USBI0 / USBI1 handlers [fact] */
int usbh0_isr(void)
{
    return usbh_port_isr(0, 0xE8010000u);
}

int usbh1_isr(void)
{
    return usbh_port_isr(1, 0xE8207000u);
}

/* 0x2013A9D4 */
void *usbh_port_ctx(int port)
{
    return usbh_ports + 0x4D8 * port;
}

/* 0x20139330: (addr): -1 when addr has a bit of the mask 0x20808AB8 set (the transfer goes through the pipe's own
 * buffer), else 0 [fact] */
int usbh_buf_needs_bounce(uint32_t addr)
{
    return (addr & usbh_bounce_mask) ? -1 : 0;
}

/* 0x20139624: (port, pipe, buf, len): -1 without a pipe; the pipe's direction word +0x18 picks the read (non-zero)
 * or the write; the port is not used [fact] */
int usbh_pipe_xfer(int port, uint8_t *pipe, void *buf, uint32_t len)
{
    if (pipe == 0)
    {
        return -1;
    }
    if (*(uint32_t *)(pipe + 0x18) != 0)
    {
        return usbh_pipe_read(pipe, buf, len);
    }
    return usbh_pipe_write(pipe, buf, len);
}

/* 0x2013B2F8: (port, pipe): the port's one slot (the loop runs once): when it is in use (+4) and holds this pipe
 * (+0x2C), its done word +0x30 = 1 [fact: cmp r2, #1; blt] */
void usbh_pipe_mark_done(int port, uint32_t pipe)
{
    for (int i = 0; i < 1; i++)
    {
        uint32_t *slot = (uint32_t *)(usbh_pipe_slots + 0x34 * port + 0x34 * i);

        if (slot[1] != 0 && slot[11] == pipe)
        {
            slot[12] = 1;
        }
    }
}
