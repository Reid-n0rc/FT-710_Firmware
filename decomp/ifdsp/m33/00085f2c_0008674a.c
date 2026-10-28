// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== ftell @ 00085f2c (64 bytes)

/* [inference] */

int ftell(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[3];
  if ((uVar2 & 3) == 0) {
    DAT_00088b74 = 0x21;
    return -1;
  }
  if ((int)(uVar2 << 0xc) < 0) {
    if ((uVar2 & 0x20) == 0) {
      iVar1 = (*param_1 + param_1[6]) - param_1[4];
    }
    else {
      iVar1 = param_1[10];
    }
    return iVar1 + -1;
  }
  if ((uVar2 & 0x20) != 0) {
    return param_1[10];
  }
  return (*param_1 + param_1[6]) - param_1[4];
}


// ===== __check_heap_overflow @ 00085f70 (18 bytes)

/* WARNING: Removing unreachable block (ram,0x00085f7e) */
/* new_end >= 0xA2EF8 [fact] */

bool __check_heap_overflow(undefined *param_1)

{
  return &DAT_000a2ef8 <= param_1;
}


// ===== aic3204_select_right_input @ 00085f88 (38 bytes)

/* codec P1 R55 = 0x10 (arg 1, IN2R) or 0x40 (arg 0, IN1R); called by regfile_write for reg 10 */

void aic3204_select_right_input(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0x40;
  }
  aic3204_spi_write(0,1);
  aic3204_spi_write(0x37,uVar1);
  aic3204_spi_write(0);
  return;
}


// ===== console_puts @ 00085fae (20 bytes)

void console_puts(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = strlen();
  uart0_write(param_1,uVar1);
  return;
}


// ===== IpcRecvTask @ 00085fc6 (36 bytes)

void IpcRecvTask(int param_1)

{
  undefined1 auStack_a0 [152];
  
  do {
    do {
      ipc_recv(auStack_a0);
      ipc_print_dsp_reply(auStack_a0);
    } while (*(int *)(param_1 + 4) == 0);
    xTaskGenericNotify(*(int *)(param_1 + 4),0,2);
  } while( true );
}


// ===== HardFault_Handler @ 00085fea (42 bytes)

void HardFault_Handler(void)

{
  undefined4 *puVar1;
  uint unaff_lr;
  
  if ((unaff_lr & 4) == 0) {
    puVar1 = (undefined4 *)getMainStackPointer();
  }
  else {
    puVar1 = (undefined4 *)getProcessStackPointer();
  }
  if (*(short *)puVar1[6] != -0x4155) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  puVar1[6] = (short *)puVar1[6] + 1;
  *puVar1 = 0x20;
  return;
}


// ===== is_hex_string @ 00086014 (48 bytes)

undefined4 is_hex_string(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = param_1;
  do {
    uVar2 = strlen(pbVar3);
    if (uVar2 <= (uint)((int)pbVar3 - (int)param_1)) {
      return 1;
    }
    pbVar4 = pbVar3 + 1;
    bVar1 = *pbVar3;
    pbVar3 = pbVar4;
  } while ((bVar1 - 0x30 < 10) || ((bVar1 & 0xffffffdf) - 0x41 < 6));
  return 0;
}


// ===== frame_checksum_ok @ 00086044 (38 bytes)

bool frame_checksum_ok(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  
  cVar3 = '\0';
  pcVar2 = param_1 + param_2;
  for (; param_1 != pcVar2; param_1 = param_1 + 1) {
    cVar3 = cVar3 + *param_1;
  }
  cVar1 = strtoul(param_1,0,0x10);
  return cVar1 == cVar3;
}


// ===== env_map_vatopa @ 0008606a (2 bytes)

/* Identity (also used as env_map_patova through a thunk) [inference] */

void env_map_vatopa(void)

{
  return;
}


// ===== env_free_memory @ 00086072 (8 bytes)

void env_free_memory(int param_1)

{
  if (param_1 != 0) {
    vPortFree();
    return;
  }
  return;
}


// ===== env_mb @ 00086086 (6 bytes)

/* DSB [inference] */

void env_mb(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== env_rmb @ 0008608c (6 bytes)

/* DSB [inference] */

void env_rmb(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== env_wmb @ 00086092 (6 bytes)

/* DSB [inference] */

void env_wmb(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== env_create_mutex @ 000860a0 (32 bytes)

int env_create_mutex(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0xb) {
    iVar1 = xQueueCreateCountingSemaphore(10);
    *param_1 = iVar1;
    iVar1 = -(uint)(iVar1 == 0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


// ===== env_lock_mutex @ 000860c4 (26 bytes)

void env_lock_mutex(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = xPortIsInsideInterrupt();
  if (iVar1 == 0) {
    xQueueSemaphoreTake(param_1,0xffffffff);
    return;
  }
  return;
}


// ===== env_unlock_mutex @ 000860de (28 bytes)

void env_unlock_mutex(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = xPortIsInsideInterrupt();
  if (iVar1 == 0) {
    xQueueGenericSend(param_1,0,0,0);
    return;
  }
  return;
}


// ===== env_create_queue @ 00086106 (26 bytes)

/* [inference] */

int env_create_queue(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = xQueueGenericCreate(param_2,param_3,0);
  *param_1 = iVar1;
  return -(uint)(iVar1 == 0);
}


// ===== env_put_queue @ 00086120 (78 bytes)

/* Queue send, ISR-aware [inference] */

bool env_put_queue(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int local_14 [2];
  
  bVar2 = false;
  local_14[0] = 0;
  iVar1 = xPortIsInsideInterrupt();
  if (iVar1 == 0) {
    iVar1 = xQueueGenericSend(param_1,param_2,param_3,0);
    bVar2 = iVar1 == 1;
  }
  else {
    iVar1 = xQueueGenericSendFromISR(param_1,param_2,local_14,0);
    if ((iVar1 == 1) && (bVar2 = true, local_14[0] != 0)) {
      DAT_e000ed04 = 0x10000000;
    }
  }
  return bVar2;
}


// ===== env_get_queue @ 0008616e (74 bytes)

/* Queue receive, ISR-aware [inference] */

bool env_get_queue(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int local_14 [2];
  
  bVar2 = false;
  local_14[0] = 0;
  iVar1 = xPortIsInsideInterrupt();
  if (iVar1 == 0) {
    iVar1 = xQueueReceive(param_1,param_2,param_3);
    bVar2 = iVar1 == 1;
  }
  else {
    iVar1 = xQueueReceiveFromISR(param_1,param_2,local_14);
    if ((iVar1 == 1) && (bVar2 = true, local_14[0] != 0)) {
      DAT_e000ed04 = 0x10000000;
    }
  }
  return bVar2;
}


// ===== rpmsg_queue_rx_cb @ 000861b8 (34 bytes)

/* create: endpoint callback of ept 0x28; env_put_queue(q, {src, data, len}); returns RL_HOLD (1) */

bool rpmsg_queue_rx_cb(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  if (param_4 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  local_14 = param_3;
  local_10 = param_1;
  uStack_c = param_2;
  iVar1 = env_put_queue(param_4,&local_14,0,param_4,param_1);
  return iVar1 != 0;
}


// ===== rpmsg_queue_create @ 000861da (38 bytes)

undefined4 rpmsg_queue_create(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  if ((param_1 == (int *)0x0) ||
     (uStack_8 = param_3,
     iVar1 = env_create_queue(&local_c,*(undefined2 *)(*param_1 + 0x52),0xc,*param_1,param_1),
     iVar1 != 0)) {
    local_c = 0;
  }
  return local_c;
}


// ===== add_to_list @ 00086200 (30 bytes)

/* rpmsg_lite endpoint list [inference] */

void add_to_list(int *param_1,int param_2)

{
  if (param_2 != 0) {
    if (*param_1 != 0) {
      *(int *)(param_2 + 8) = *param_1;
      *(undefined4 *)(param_2 + 0xc) = 0;
      *(int *)(*param_1 + 0xc) = param_2;
      *param_1 = param_2;
      return;
    }
    *param_1 = param_2;
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(*param_1 + 0xc) = 0;
  }
  return;
}


// ===== rpmsg_lite_tx_callback @ 0008621e (12 bytes)

/* create: tx_vq callback, sets rl->link_state = 1 */

void rpmsg_lite_tx_callback(int param_1)

{
  if (*(int *)(param_1 + 100) == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(*(int *)(param_1 + 100) + 0x10) = 1;
  return;
}


// ===== virtqueue_notify @ 0008622a (8 bytes)

/* create: vq notify hook, platform_notify(vq->vq_queue_index) */

void virtqueue_notify(int param_1)

{
  platform_notify(*(undefined2 *)(param_1 + 0x50));
  return;
}


// ===== vq_tx_master @ 00086232 (14 bytes)

/* create: master_vq_ops[0] (table 0x879AC): virtqueue_add_buffer, assert on error */

void vq_tx_master(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = virtqueue_add_buffer(param_1,param_4,param_3,param_4,param_4);
  if (iVar1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== rpmsg_lite_get_endpoint_from_addr @ 00086248 (16 bytes)

/* [inference] */

void rpmsg_lite_get_endpoint_from_addr(undefined4 *param_1,int param_2)

{
  for (; (param_1 != (undefined4 *)0x0 && (*(int *)*param_1 != param_2));
      param_1 = (undefined4 *)param_1[2]) {
  }
  return;
}


// ===== rpmsg_lite_rx_callback @ 00086258 (86 bytes)

/* Virtqueue rx callback, dispatches to endpoint callbacks [inference] */

void rpmsg_lite_rx_callback(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_18;
  undefined4 local_14;
  
  puVar4 = *(undefined4 **)(param_1 + 100);
  uStack_18 = param_1;
  local_14 = param_2;
  if (puVar4 == (undefined4 *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  while (puVar3 = (undefined4 *)(**(code **)(puVar4[8] + 8))(*puVar4,&local_14,(int)&uStack_18 + 2),
        puVar3 != (undefined4 *)0x0) {
    piVar1 = (int *)rpmsg_lite_get_endpoint_from_addr(puVar4[2],puVar3[1]);
    if ((piVar1 == (int *)0x0) ||
       (iVar2 = (**(code **)(*piVar1 + 4))
                          (puVar3 + 4,*(undefined2 *)(puVar3 + 3),*puVar3,
                           *(undefined4 *)(*piVar1 + 8)), iVar2 != 1)) {
      (**(code **)(puVar4[8] + 0xc))(*puVar4,puVar3,local_14,uStack_18._2_2_);
    }
    else {
      *(undefined2 *)((int)puVar3 + 10) = uStack_18._2_2_;
    }
  }
  return;
}


// ===== rpmsg_lite_create_ept @ 000862b2 (144 bytes)

int * rpmsg_lite_create_ept(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_r2;
  bool bVar5;
  
  if (param_1 == 0) {
    return (int *)0x0;
  }
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  if (param_2 == -1) {
    uVar4 = *(undefined4 *)(param_1 + 8);
    param_2 = 1;
    do {
      iVar1 = rpmsg_lite_get_endpoint_from_addr(uVar4,param_2);
      if (iVar1 == 0) goto LAB_000862fa;
      bVar5 = param_2 != -2;
      uVar4 = extraout_r2;
      param_2 = param_2 + 1;
    } while (bVar5);
  }
  else {
    iVar1 = rpmsg_lite_get_endpoint_from_addr(*(undefined4 *)(param_1 + 8),param_2);
    if (iVar1 == 0) {
LAB_000862fa:
      piVar2 = (int *)pvPortMalloc(0x10);
      if (piVar2 != (int *)0x0) {
        piVar3 = (int *)pvPortMalloc(0x10);
        if (piVar3 == (int *)0x0) {
          env_free_memory(piVar2);
          goto LAB_000862e0;
        }
        memset(piVar2,0,0x10);
        *piVar2 = param_2;
        piVar2[1] = param_3;
        piVar2[2] = param_4;
        *piVar3 = (int)piVar2;
        add_to_list(param_1 + 8,piVar3);
      }
      env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
      return piVar2;
    }
  }
LAB_000862e0:
  env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
  return (int *)0x0;
}


// ===== vq_ring_update_avail @ 00086342 (46 bytes)

/* [inference] */

void vq_ring_update_avail(int param_1,undefined2 param_2)

{
  *(undefined2 *)
   (*(int *)(param_1 + 0x48) +
    (*(ushort *)(param_1 + 0x52) - 1 & (uint)*(ushort *)(*(int *)(param_1 + 0x48) + 2)) * 2 + 4) =
       param_2;
  env_wmb();
  *(short *)(*(int *)(param_1 + 0x48) + 2) = *(short *)(*(int *)(param_1 + 0x48) + 2) + 1;
  *(short *)(param_1 + 0x56) = *(short *)(param_1 + 0x56) + 1;
  return;
}


// ===== vq_ring_update_used @ 00086370 (38 bytes)

/* [inference] */

void vq_ring_update_used(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c) +
          (*(ushort *)(param_1 + 0x52) - 1 & (uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2)) * 8;
  *(undefined4 *)(iVar1 + 4) = param_2;
  *(undefined4 *)(iVar1 + 8) = param_3;
  env_wmb();
  *(short *)(*(int *)(param_1 + 0x4c) + 2) = *(short *)(*(int *)(param_1 + 0x4c) + 2) + 1;
  return;
}


// ===== virtqueue_add_buffer @ 00086396 (22 bytes)

/* [inference] */

undefined4 virtqueue_add_buffer(void)

{
  vq_ring_update_avail();
  return 0;
}


// ===== virtqueue_fill_avail_buffers @ 000863ac (82 bytes)

/* [inference] */

undefined4 virtqueue_fill_avail_buffers(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x58);
  iVar5 = *(int *)(param_1 + 0x44);
  uVar2 = env_map_vatopa(param_2);
  iVar4 = iVar5 + uVar3 * 0x10;
  *(undefined4 *)(iVar5 + uVar3 * 0x10) = uVar2;
  *(undefined2 *)(iVar4 + 0xc) = 2;
  sVar1 = *(short *)(param_1 + 0x58);
  *(undefined4 *)(iVar4 + 4) = 0;
  *(undefined4 *)(iVar4 + 8) = param_3;
  *(short *)(param_1 + 0x58) = sVar1 + 1;
  vq_ring_update_avail(param_1,uVar3);
  return 0;
}


// ===== virtqueue_get_buffer @ 000863fe (94 bytes)

/* [inference] */

undefined4 virtqueue_get_buffer(int param_1,undefined4 *param_2,undefined2 *param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if ((uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2) != (uint)*(ushort *)(param_1 + 0x5a)) {
      iVar2 = *(int *)(param_1 + 0x4c) +
              ((uint)*(ushort *)(param_1 + 0x5a) & *(ushort *)(param_1 + 0x52) - 1) * 8;
      env_rmb();
      uVar1 = *(uint *)(iVar2 + 4);
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(iVar2 + 8);
      }
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = (short)uVar1;
      }
      *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + 1;
      return *(undefined4 *)(*(int *)(param_1 + 0x44) + (uVar1 & 0xffff) * 0x10);
    }
  }
  return 0;
}


// ===== virtqueue_get_buffer_length @ 00086456 (10 bytes)

/* [inference] */

undefined4 virtqueue_get_buffer_length(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x44) + param_2 * 0x10 + 8);
}


// ===== virtqueue_fill_used_buffers @ 00086460 (74 bytes)

/* [inference] */

undefined4
virtqueue_fill_used_buffers(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x58);
  uVar2 = uVar3;
  if (param_2 != 0) {
    iVar5 = *(int *)(param_1 + 0x44);
    uVar1 = env_map_vatopa(param_2);
    iVar4 = iVar5 + uVar3 * 0x10;
    *(undefined4 *)(iVar5 + uVar3 * 0x10) = uVar1;
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = param_3;
    *(undefined2 *)(iVar4 + 0xc) = 2;
    uVar2 = uVar3 + 1 & 0xffff;
  }
  *(short *)(param_1 + 0x58) = (short)uVar2;
  vq_ring_update_used(param_1,uVar3,param_3,uVar2,param_4);
  return 0;
}


// ===== virtqueue_disable_cb @ 000864aa (40 bytes)

/* [inference] */

void virtqueue_disable_cb(int param_1)

{
  ushort *puVar1;
  
  puVar1 = *(ushort **)(param_1 + 0x48);
  if (*(int *)(param_1 + 0x20) << 0x1e < 0) {
    puVar1[*(int *)(param_1 + 0x40) + 2] =
         (*(short *)(param_1 + 0x5a) + -1) - *(short *)(param_1 + 0x52);
    return;
  }
  *puVar1 = *puVar1 | 1;
  return;
}


// ===== virtqueue_kick @ 000864d2 (70 bytes)

/* [inference] */

void virtqueue_kick(int param_1)

{
  env_mb();
  if ((*(uint *)(param_1 + 0x20) & 2) == 0) {
    if ((int)((uint)**(ushort **)(param_1 + 0x4c) << 0x1f) < 0) goto LAB_000864fe;
  }
  else if ((uint)*(ushort *)(param_1 + 0x56) <=
           ((*(ushort *)(*(int *)(param_1 + 0x48) + 2) - 1) -
            *(int *)(*(ushort **)(param_1 + 0x4c) + *(int *)(param_1 + 0x40) * 4 + 2) & 0xffff))
  goto LAB_000864fe;
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    (**(code **)(param_1 + 0x34))(param_1);
  }
LAB_000864fe:
  *(undefined2 *)(param_1 + 0x56) = 0;
  return;
}


// ===== vq_ring_init @ 00086518 (32 bytes)

/* Chains the descriptors, last = 0x8000 [inference] */

void vq_ring_init(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = *(ushort *)(param_1 + 0x52);
  iVar2 = *(int *)(param_1 + 0x44);
  while (iVar3 = iVar2 + uVar4 * 0x10, uVar4 < uVar1 - 1) {
    uVar4 = uVar4 + 1;
    *(short *)(iVar3 + 0xe) = (short)uVar4;
  }
  *(undefined2 *)(iVar3 + 0xe) = 0x8000;
  return;
}


// ===== vPortYield @ 00086542 (22 bytes)

/* ICSR = PENDSVSET, DSB, ISB [inference] */

void vPortYield(void)

{
  DAT_e000ed04 = 0x10000000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== SysTick_Handler @ 00086558 (36 bytes)

void SysTick_Handler(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = vPortRaiseBASEPRI();
  iVar2 = xTaskIncrementTick();
  if (iVar2 != 0) {
    DAT_e000ed04 = 0x10000000;
  }
  vPortClearBASEPRI(uVar1);
  return;
}


// ===== vPortSVCHandler_C @ 0008657c (26 bytes)

void vPortSVCHandler_C(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x18) + -2) == '\x02') {
    vRestoreContextOfFirstTask();
    return;
  }
  vPortRaiseBASEPRI();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== vPortRaiseBASEPRI @ 00086596 (22 bytes)

undefined8 vPortRaiseBASEPRI(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return CONCAT44(0x40,uVar2);
}


// ===== vPortClearBASEPRI @ 000865ac (14 bytes)

void vPortClearBASEPRI(undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_1);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== xEventGroupCreate @ 000865ba (26 bytes)

undefined4 * xEventGroupCreate(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)pvPortMalloc(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    vListInitialise(puVar1 + 1);
  }
  return puVar1;
}


// ===== xEventGroupWaitBits @ 000865d4 (208 bytes)

uint xEventGroupWaitBits(uint *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (uint *)0x0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 & 0xff000000) != 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = xTaskGetSchedulerState();
  if ((iVar1 == 0) && (param_5 != 0)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vTaskSuspendAll();
  uVar2 = *param_1;
  if (param_4 == 0) {
    if ((param_2 & uVar2) != 0) goto LAB_00086652;
LAB_00086624:
    if (param_5 != 0) {
      if (param_3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0x1000000;
      }
      if (param_4 != 0) {
        uVar2 = uVar2 | 0x4000000;
      }
      vTaskPlaceOnUnorderedEventList(param_1 + 1,uVar2 | param_2,param_5);
      uVar2 = 0;
    }
  }
  else {
    if (param_2 != (param_2 & uVar2)) goto LAB_00086624;
LAB_00086652:
    param_5 = 0;
    if (param_3 != 0) {
      *param_1 = uVar2 & ~param_2;
    }
  }
  iVar1 = xTaskResumeAll();
  if (param_5 == 0) {
    return uVar2;
  }
  if (iVar1 == 0) {
    vPortYield();
  }
  uVar2 = uxTaskResetEventItemValue();
  if ((int)(uVar2 << 6) < 0) goto LAB_0008668a;
  vPortEnterCritical();
  uVar2 = *param_1;
  if (param_4 == 0) {
    if ((param_2 & uVar2) != 0) {
LAB_00086698:
      if (param_3 != 0) {
        *param_1 = uVar2 & ~param_2;
      }
    }
  }
  else if (param_2 == (param_2 & uVar2)) goto LAB_00086698;
  vPortExitCritical();
LAB_0008668a:
  return uVar2 & 0xffffff;
}


// ===== xEventGroupSetBits @ 000866a4 (110 bytes)

/* [inference] */

uint xEventGroupSetBits(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  if (param_1 == (uint *)0x0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 & 0xff000000) != 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vTaskSuspendAll();
  *param_1 = *param_1 | param_2;
  uVar5 = 0;
  puVar6 = (uint *)param_1[4];
LAB_000866d0:
  do {
    puVar1 = puVar6;
    uVar2 = *param_1;
    if (param_1 + 3 == puVar1) {
      *param_1 = uVar2 & ~uVar5;
      xTaskResumeAll();
      return *param_1;
    }
    uVar3 = *puVar1;
    puVar6 = (uint *)puVar1[1];
    uVar4 = uVar3 & 0xffffff;
    if ((uVar3 & 0x4000000) != 0) goto LAB_000866fe;
  } while ((uVar4 & uVar2) == 0);
  goto LAB_00086702;
LAB_000866fe:
  if (uVar4 == (uVar4 & uVar2)) {
LAB_00086702:
    if ((int)(uVar3 << 7) < 0) {
      uVar5 = uVar5 | uVar4;
    }
    vTaskRemoveFromUnorderedEventList(puVar1,uVar2 | 0x2000000);
  }
  goto LAB_000866d0;
}


// ===== vListInitialise @ 00086716 (22 bytes)

/* [inference] */

void vListInitialise(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 2;
  param_1[2] = 0xffffffff;
  param_1[3] = puVar1;
  param_1[1] = puVar1;
  param_1[4] = puVar1;
  *param_1 = 0;
  return;
}


// ===== vListInitialiseItem @ 0008672c (6 bytes)

/* [inference] */

void vListInitialiseItem(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ===== vListInsertEnd @ 00086732 (24 bytes)

/* [inference] */

void vListInsertEnd(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  uVar1 = *(undefined4 *)(iVar2 + 8);
  *(int *)(param_2 + 4) = iVar2;
  *(undefined4 *)(param_2 + 8) = uVar1;
  *(int *)(*(int *)(iVar2 + 8) + 4) = param_2;
  *(int *)(iVar2 + 8) = param_2;
  iVar2 = *param_1;
  *(int **)(param_2 + 0x10) = param_1;
  *param_1 = iVar2 + 1;
  return;
}


// ===== vListInsert @ 0008674a (46 bytes)

/* [inference] */

void vListInsert(int *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  if (*param_2 == 0xffffffff) {
    puVar3 = (uint *)param_1[4];
  }
  else {
    puVar1 = (uint *)(param_1 + 2);
    do {
      puVar3 = puVar1;
      puVar1 = (uint *)puVar3[1];
    } while (*(uint *)puVar3[1] <= *param_2);
  }
  uVar2 = puVar3[1];
  param_2[1] = uVar2;
  *(uint **)(uVar2 + 8) = param_2;
  param_2[2] = (uint)puVar3;
  puVar3[1] = (uint)param_2;
  iVar4 = *param_1;
  param_2[4] = (uint)param_1;
  *param_1 = iVar4 + 1;
  return;
}

