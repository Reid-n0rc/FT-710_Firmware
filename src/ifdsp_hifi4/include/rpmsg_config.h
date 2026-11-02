/*
 * rpmsg-lite configuration of the FT-710 IFDSP HiFi4 image (recreated, T24).
 *
 * rpmsg_default_config.h (rpmsg-lite v3.1.1) supplies every value not set here. Each value below is what the image's
 * code shows; the evidence is in docs/tasks/T24-source-recreation.md ("IFDSP HiFi4") and docs/code/ifdsp/ipc.md.
 */
#ifndef RPMSG_CONFIG_H_
#define RPMSG_CONFIG_H_

/* [fact] rpmsg_lite_remote_init 0x21B544 takes a static context (env_memset(ctx, 0, 0xF4), the two vq contexts at
 * +0x24 and +0x8C) and calls virtqueue_create_static */
#define RL_USE_STATIC_API (1)

/* [fact] 512-byte buffers: payload 496 (the M33 side, docs/code/ifdsp/ipc.md) */
#define RL_BUFFER_PAYLOAD_SIZE (496U)
#define RL_BUFFER_COUNT (2U)

#endif /* RPMSG_CONFIG_H_ */
