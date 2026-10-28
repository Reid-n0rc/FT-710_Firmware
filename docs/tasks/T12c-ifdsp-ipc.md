# T12c — IFDSP M33↔HiFi4 IPC (MU-A, rpmsg)

**Status:** done (2026-10-27) · **Parent:** T12 · **Depends on:** T12a

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
Page: `docs/code/ifdsp/ipc.md`. Names: `tools/ghidra/names_ifdsp.T12c.tsv` (79 entries, M33 and HiFi4 sections; "create" and
"rename" lines flagged). New tool: `tools/ifdsp_xtdis.py` (Xtensa base-ISA sweep; FLIX op0=0xE skipped as 6 bytes, which
keeps control code in sync, measured over all 1120 function entries).
- Boot handshake (MU flags 1 → 2 → 3, SEMA42 token) is the only IPC that runs. DSP side is in `Thread_Ipc` 0x0021C3B4:
  polls MU-B SR&7 == 1, sets flags, polls == 2, `SEMA42_Init`/`SEMA42_Lock`, sets flags (3) [fact: calls; values in FLIX].
  **Correction:** the M33 releases SEMA42 **gate 0** (byte 0x40112003 is GATE0, gate n is at n^3), not gate 3.
- The handshake orders register-file ownership: DSP `main` 0x0021C498 calls `regfile_init_defaults` 0x0021BE80 (clear and about 100
  defaults) before threads start, and the M33 creates `CommandTask` (MAIN's link) only after flag 3 [inference].
- rpmsg-lite: vrings 0x20020000 / 0x20020400, 2 descriptors each, 4 × 512 B buffers at 0x20020800–0x20020FFF; rest of the
  0x20000 window unused. MU channel 1 doorbell = vq index << 16 on both sides. Endpoints 0x28/0x1E = NXP `dsp_xaf` demo
  `MCU_EPT_ADDR`/`DSP_EPT_ADDR`. Confirmed: queue 0x886E0 has no writer, so the link is idle. The DSP only replies to requests
  (`handle_srtm_msg` 0x0021BD40), so no rpmsg traffic flows after the init kick.
- Message = 0x98-byte NXP `srtm_message` layout shifted by an 8-byte prefix (category +8, command +0xC, error +0x14,
  param[32] +0x18). DSP handles categories 0 (versions: nine `major<<16|minor` words) and 1 (mute). The M33's category 3
  "DSP Version" has no DSP handler.
- The M33 never stops or resets the DSP after `BOARD_DSP_Init`. No audio buffers cross the cores.

## Follow-ups
- T12e: confirm the FLIX-hidden operands (flag values, gate, endpoint 0x1E, shm literal 0x00206CA8 load), and the meaning of
  reg 0x4000 and reg 1 bit 0 on the DSP. The `ifdsp_xtdis.py` 6-byte FLIX rule may help the HiFi4 decode generally.
- Parent: apply `names_ifdsp.T12c.tsv` (M33 entries into `IfdspM33Names.java`, including the 5 renames and the "create" entries;
  HiFi4 entries into a HiFi4 names script), then re-export. Check for overlap with T12d/T12e proposals (MU/SEMA42/XOS names).

## Proposed shared-file edits
- `docs/code/ifdsp/README.md` boot-flow diagram: "release gate 3" → "release gate 0 (GATE0 byte 0x40112003)". Add DSP-side steps:
  the DSP sets flags 1 and then 3, and DSP `main` writes register-file defaults before the handshake.
- README memory-map table: split 0x20020000 into vrings 0x20020000/0x20020400, buffers 0x20020800–0x20020FFF, and unused
  0x20021000–0x2003FFFF. Link to ipc.md for the extended table.
- README subsystem row for ipc.md: "endpoints 0x28 ↔ 0x1E, srtm-style 0x98-byte messages, link idle (no writer of the send queue)".
- `decomp/ifdsp/INDEX.md`, HiFi4 limitations: note that op0=0xE bundles appear to be 6 bytes (tools/ifdsp_xtdis.py).
- `docs/memory-maps.md` IFDSP: same rpmsg sub-layout as above.
- `docs/tooling.md`: list `tools/ifdsp_xtdis.py`.

## Status
Done. All scope items covered; DSP-side operand values inside FLIX bundles remain inference (see Follow-ups).
