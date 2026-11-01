/*
 * rpmsg_config.h for the FT-710 IFDSP Cortex-M33 (T24). Recreated: values settled against the image
 * (tools/equiv_m33.py) and docs/code/ifdsp/ipc.md.
 */
#ifndef RPMSG_CONFIG_H
#define RPMSG_CONFIG_H

#define RL_MS_PER_INTERVAL (1)
#define RL_BUFFER_PAYLOAD_SIZE (496U)  /* [fact] rpmsg_lite_send: max payload 0x1F0 */
#define RL_BUFFER_COUNT (2U)           /* [fact] rpmsg_lite_master_init: 2 descriptors per vring */
#define RL_API_HAS_ZEROCOPY (1)
#define RL_USE_STATIC_API (0)
#define RL_USE_MCMGR_IPC_ISR_HANDLER (0)
#define RL_ASSERT(x)  \
    do                \
    {                 \
        if (!(x))     \
            while (1) \
                ;     \
    } while (0)

#endif /* RPMSG_CONFIG_H */
