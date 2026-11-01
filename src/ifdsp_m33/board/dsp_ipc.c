/*
 * FT-710 IFDSP M33: rpmsg-lite master towards the HiFi4 (T24, recreated from the image 0x84A50..0x84AD2).
 * Shared memory 0x20020000 (0x20000 bytes), local endpoint 0x28, remote endpoint 0x1E (docs/code/ifdsp/ipc.md).
 * [inference] The object sits between clock_config.c and dsp_support.c in link order; the file name is not known.
 */
#include "rpmsg_lite.h"
#include "rpmsg_queue.h"
#include "ipc.h"

#define RPMSG_SHMEM_BASE   0x20020000U
#define RPMSG_SHMEM_SIZE   0x20000U
#define RPMSG_LINK_ID      0U
#define LOCAL_EPT_ADDR     0x28U
#define REMOTE_EPT_ADDR    0x1EU

/* One object in the image (ipc_send reads all four fields from one base) [fact: 0x84A8C] */
static struct
{
    uint32_t remoteAddr;
    struct rpmsg_lite_endpoint *ept;
    rpmsg_queue_handle queue;
    struct rpmsg_lite_instance *rpmsg;
} s_ipc;

void ipc_init(void)
{
    s_ipc.rpmsg      = rpmsg_lite_master_init((void *)RPMSG_SHMEM_BASE, RPMSG_SHMEM_SIZE, RPMSG_LINK_ID, RL_NO_FLAGS);
    s_ipc.queue      = rpmsg_queue_create(s_ipc.rpmsg);
    s_ipc.ept        = rpmsg_lite_create_ept(s_ipc.rpmsg, LOCAL_EPT_ADDR, rpmsg_queue_rx_cb, s_ipc.queue);
    s_ipc.remoteAddr = REMOTE_EPT_ADDR;
}

void ipc_send(dsp_message_t *msg)
{
    rpmsg_lite_send(s_ipc.rpmsg, s_ipc.ept, s_ipc.remoteAddr, (char *)msg, sizeof(*msg), RL_BLOCK);
}

void ipc_recv(dsp_message_t *msg)
{
    rpmsg_queue_recv(s_ipc.rpmsg, s_ipc.queue, &s_ipc.remoteAddr, (char *)msg, sizeof(*msg), NULL, RL_BLOCK);
}
