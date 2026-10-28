# T12c — IFDSP M33↔HiFi4 IPC (MU-A, rpmsg)

**Status:** todo · **Parent:** T12 · **Depends on:** T12a

## Goal
`docs/code/ifdsp/ipc.md`: MU-A boot handshake, rpmsg-lite virtqueues and endpoints, IpcRecvTask/IpcSendTask, message format and the categories in ipc_print_dsp_reply.

## Plan
See T12 plan. Starting notes from T12a below.

## Starting notes (from T12a)
- Boot handshake in `app_main` 0x8106C: `SEMA42_Init` 0x848F4, `SEMA42_ResetAllGates` 0x87008, `MU_SetFlags(MUA,1)` 0x86F14, wait `MU_SR & 7 == 1`, `SEMA42_Lock(gate 0)` 0x86FEC, `MU_SetFlags(2)`, write 0 to SEMA42 gate 3 (0x40112003), wait `== 3`.
- rpmsg-lite master: `ipc_init` 0x84A50 → `rpmsg_lite_master_init(0x20020000, 0x20000, link 0)` 0x81C28 (`virtqueue_create` 0x81DEC, 512-byte buffers), `rpmsg_queue_create` 0x861DA, `rpmsg_lite_create_ept(…, 0x28, rpmsg_queue_rx_cb)` 0x862B2; remote endpoint 0x1E. `ipc_send` 0x84A8C (`rpmsg_lite_send` 0x81AFC, 0x98 bytes), `ipc_recv` 0x84AB0 (`rpmsg_queue_recv` 0x81A88).
- Platform layer: `platform_init` 0x819E8, `platform_init_interrupt` 0x819B4 (`MU_Init`, NVIC prio 0x60, IRQ 34), `platform_register_isr` 0x81A60 (table 0x88720), `platform_interrupt_enable` 0x818D0, `env_enable/disable_interrupt` 0x81958/0x81980, `MU_A_IRQHandler` 0x818B8.
- Tasks: `IpcSendTask` 0x80F50 waits on queue 0x886E0 (8 × 0x98) — **no writer exists**; `IpcRecvTask` 0x85FC6 → `ipc_print_dsp_reply` 0x80FE8 (byte +8 = category, +0xC = command, +0x14 = error, +0x18 = value; categories 0 = component versions, 1 = mute, 3 = DSP version) — looks like NXP SDK SRTM-style messages **[inference]**.
- DSP side: `Thread_Ipc` entry 0x21C3B4 (MU-B 0x40111000, SEMA42), rpmsg debug strings 0x2062D4.., function 0x21B34C references `rx_vq/tx_vq`.

## Findings

## Status
