# T12c — IFDSP M33↔HiFi4 IPC (MU-A, rpmsg)

**Status:** in progress (2026-10-27) · **Parent:** T12 · **Depends on:** T12a

## Goal
`docs/code/ifdsp/ipc.md`: MU-A boot handshake, rpmsg-lite virtqueues and endpoints, IpcRecvTask/IpcSendTask, message format and the categories in ipc_print_dsp_reply.

## Plan
See T12 plan. Starting notes from T12a below. Approach:
1. M33 side from `decomp/ifdsp/m33` + `build/ifdsp_m33_sram.dis`: `app_main` handshake (MU_SetFlags, MU_SR polling, SEMA42 gate
   encoding), rpmsg-lite master (env/platform layer, virtqueue functions, shared-memory layout computed from the code), IPC tasks
   and queue 0x886E0 (literal search for writers), message struct (0x98 bytes) vs the NXP SDK DSP-example `srtm_message`.
2. Identify the unnamed rpmsg-lite / env helpers (0x85F2C..0x86542, 0x81914) by matching rpmsg-lite source; propose names in
   `tools/ghidra/names_ifdsp.T12c.tsv`.
3. DSP side (Xtensa base ISA only): Ghidra listing of own project copy `FT710_IFDSP_T12c` for the MU-B / SEMA42 / rpmsg functions
   (literal pools via `ifdsp_hifi4_l32r.txt`), find the flag handshake partner, rpmsg remote init and endpoint 0x1E, and how the
   register file is consumed (`tools/ifdsp_regscan.py`). Tag L32R-only evidence as such.
4. Write `docs/code/ifdsp/ipc.md`: function tables, shared-SRAM map (extended), message format, startup + steady-state sequence
   diagrams, start/stop/reset sequencing, audio-buffer handoffs, open questions. Shared-file edits go under "Proposed shared-file edits".

## Starting notes (from T12a)
- Boot handshake in `app_main` 0x8106C: `SEMA42_Init` 0x848F4, `SEMA42_ResetAllGates` 0x87008, `MU_SetFlags(MUA,1)` 0x86F14, wait `MU_SR & 7 == 1`, `SEMA42_Lock(gate 0)` 0x86FEC, `MU_SetFlags(2)`, write 0 to SEMA42 gate 3 (0x40112003), wait `== 3`.
- rpmsg-lite master: `ipc_init` 0x84A50 → `rpmsg_lite_master_init(0x20020000, 0x20000, link 0)` 0x81C28 (`virtqueue_create` 0x81DEC, 512-byte buffers), `rpmsg_queue_create` 0x861DA, `rpmsg_lite_create_ept(…, 0x28, rpmsg_queue_rx_cb)` 0x862B2; remote endpoint 0x1E. `ipc_send` 0x84A8C (`rpmsg_lite_send` 0x81AFC, 0x98 bytes), `ipc_recv` 0x84AB0 (`rpmsg_queue_recv` 0x81A88).
- Platform layer: `platform_init` 0x819E8, `platform_init_interrupt` 0x819B4 (`MU_Init`, NVIC prio 0x60, IRQ 34), `platform_register_isr` 0x81A60 (table 0x88720), `platform_interrupt_enable` 0x818D0, `env_enable/disable_interrupt` 0x81958/0x81980, `MU_A_IRQHandler` 0x818B8.
- Tasks: `IpcSendTask` 0x80F50 waits on queue 0x886E0 (8 × 0x98) — **no writer exists**; `IpcRecvTask` 0x85FC6 → `ipc_print_dsp_reply` 0x80FE8 (byte +8 = category, +0xC = command, +0x14 = error, +0x18 = value; categories 0 = component versions, 1 = mute, 3 = DSP version) — looks like NXP SDK SRTM-style messages **[inference]**.
- DSP side: `Thread_Ipc` entry 0x21C3B4 (MU-B 0x40111000, SEMA42), rpmsg debug strings 0x2062D4.., function 0x21B34C references `rx_vq/tx_vq`.

## Findings

## Status
