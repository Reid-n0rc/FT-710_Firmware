// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== vq_ring_update_used @ 00086370 (38 bytes)

/* [inference] */

void vq_ring_update_used(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c) +
          (*(ushort *)(param_1 + 0x52) - 1 & (uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2)) * 8;
  *(uint *)(iVar1 + 4) = param_2;
  *(uint *)(iVar1 + 8) = param_3;
  env_wmb();
  *(short *)(*(int *)(param_1 + 0x4c) + 2) = *(short *)(*(int *)(param_1 + 0x4c) + 2) + 1;
  return;
}


// ===== virtqueue_add_buffer @ 00086396 (22 bytes)

/* [inference] */

uint virtqueue_add_buffer(uint param_1,uint param_2)

{
  vq_ring_update_avail(param_1,(ushort)param_2);
  return 0;
}


// ===== virtqueue_fill_avail_buffers @ 000863ac (82 bytes)

/* [inference] */

uint virtqueue_fill_avail_buffers(int param_1,uint address,uint param_3)

{
  ushort uVar1;
  short sVar2;
  uint platform_vatopa_ret;
  int iVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x58);
  iVar4 = *(int *)(param_1 + 0x44);
  platform_vatopa_ret = env_map_vatopa((void *)address);
  iVar3 = iVar4 + (uint)uVar1 * 0x10;
  *(uint *)(iVar4 + (uint)uVar1 * 0x10) = platform_vatopa_ret;
  *(undefined2 *)(iVar3 + 0xc) = 2;
  sVar2 = *(short *)(param_1 + 0x58);
  *(undefined4 *)(iVar3 + 4) = 0;
  *(uint *)(iVar3 + 8) = param_3;
  *(short *)(param_1 + 0x58) = sVar2 + 1;
  vq_ring_update_avail(param_1,uVar1);
  return 0;
}


// ===== virtqueue_get_buffer @ 000863fe (88 bytes)

/* [inference] */

void * virtqueue_get_buffer(void *rvq,uint *len,ushort *idx)

{
  void *platform_patova_ret;
  uint uVar1;
  int iVar2;
  
  if (rvq != (void *)0x0) {
    if ((uint)*(ushort *)(*(int *)((int)rvq + 0x4c) + 2) != (uint)*(ushort *)((int)rvq + 0x5a)) {
      iVar2 = *(int *)((int)rvq + 0x4c) +
              ((uint)*(ushort *)((int)rvq + 0x5a) & *(ushort *)((int)rvq + 0x52) - 1) * 8;
      env_rmb();
      uVar1 = *(uint *)(iVar2 + 4);
      if (len != (uint *)0x0) {
        *len = *(uint *)(iVar2 + 8);
      }
      if (idx != (ushort *)0x0) {
        *idx = (ushort)uVar1;
      }
      *(short *)((int)rvq + 0x5a) = *(short *)((int)rvq + 0x5a) + 1;
      platform_patova_ret =
           env_map_patova(*(uint *)(*(int *)((int)rvq + 0x44) + (uVar1 & 0xffff) * 0x10));
      return platform_patova_ret;
    }
  }
  return (void *)0x0;
}


// ===== virtqueue_get_buffer_length @ 00086456 (10 bytes)

/* [inference] */

uint virtqueue_get_buffer_length(int param_1,int param_2)

{
  return *(uint *)(*(int *)(param_1 + 0x44) + param_2 * 0x10 + 8);
}


// ===== virtqueue_fill_used_buffers @ 00086460 (74 bytes)

/* [inference] */

undefined4 virtqueue_fill_used_buffers(int param_1,void *address,uint param_3)

{
  uint platform_vatopa_ret;
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x58);
  uVar2 = (uint)uVar1;
  if (address != (void *)0x0) {
    iVar4 = *(int *)(param_1 + 0x44);
    platform_vatopa_ret = env_map_vatopa(address);
    iVar3 = iVar4 + uVar2 * 0x10;
    *(uint *)(iVar4 + uVar2 * 0x10) = platform_vatopa_ret;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(uint *)(iVar3 + 8) = param_3;
    *(undefined2 *)(iVar3 + 0xc) = 2;
    uVar1 = uVar1 + 1;
  }
  *(ushort *)(param_1 + 0x58) = uVar1;
  vq_ring_update_used(param_1,uVar2,param_3);
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
  uint i;
  
  i = 0;
  uVar1 = *(ushort *)(param_1 + 0x52);
  iVar2 = *(int *)(param_1 + 0x44);
  while (iVar3 = iVar2 + i * 0x10, i < uVar1 - 1) {
    i = i + 1;
    *(short *)(iVar3 + 0xe) = (short)i;
  }
  *(undefined2 *)(iVar3 + 0xe) = 0x8000;
  return;
}


// ===== virtqueue_notification @ 00086538 (10 bytes)

/* NEW (entries_m33.tsv): byte-identical to virtqueue_notification of rpmsg-lite v3.1.0
   virtio/virtqueue.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24 round 2) */

void virtqueue_notification(void *vq)

{
  if ((vq != (void *)0x0) && (*(code **)((int)vq + 0x30) != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0008653e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((int)vq + 0x30))();
    return;
  }
  return;
}


// ===== vPortYield @ 00086542 (22 bytes)

/* ICSR = PENDSVSET, DSB, ISB [inference] */

void vPortYield(void)

{
                    /* Interrupt Control and State [sfr] */
  SCB_ICSR = 0x10000000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== SysTick_Handler @ 00086558 (36 bytes)

void SysTick_Handler(void)

{
  uint ulSetInterruptMask_ret;
  uint xTaskIncrementTick_ret;
  
  ulSetInterruptMask_ret = ulSetInterruptMask();
  xTaskIncrementTick_ret = xTaskIncrementTick();
  if (xTaskIncrementTick_ret != 0) {
                    /* Interrupt Control and State [sfr] */
    SCB_ICSR = 0x10000000;
  }
  vClearInterruptMask(ulSetInterruptMask_ret);
  return;
}


// ===== vPortSVCHandler_C @ 0008657c (26 bytes)

void vPortSVCHandler_C(int param_1)

{
  if (*(char *)(*(int *)(param_1 + 0x18) + -2) == '\x02') {
                    /* PSPLIM/CONTROL=2/PSP from pxCurrentTCB [doc, inference] */
    vRestoreContextOfFirstTask();
    return;
  }
  ulSetInterruptMask();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== ulSetInterruptMask @ 00086596 (22 bytes)

/* T23d FreeRTOS V10.3.0 (lib_match 1.000): size 22/22; seq 1.000; margin 0.260; was
   vPortRaiseBASEPRI [fact] */

uint ulSetInterruptMask(void)

{
  bool bVar1;
  uint uVar2;
  
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
  return uVar2;
}


// ===== vClearInterruptMask @ 000865ac (14 bytes)

/* T23d FreeRTOS V10.3.0 (lib_match 1.000): size 14/14; seq 1.000; margin 0.183; was
   vPortClearBASEPRI [fact] */

void vClearInterruptMask(uint param_1)

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

void * xEventGroupCreate(void)

{
  undefined4 *pvPortMalloc_ret;
  
  pvPortMalloc_ret = pvPortMalloc(0x1c);
  if (pvPortMalloc_ret != (undefined4 *)0x0) {
    *pvPortMalloc_ret = 0;
    vListInitialise(pvPortMalloc_ret + 1);
  }
  return pvPortMalloc_ret;
}


// ===== xEventGroupWaitBits @ 000865d4 (208 bytes)

uint xEventGroupWaitBits(uint *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint xTaskResumeAll_ret;
  
  if (param_1 == (uint *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 & 0xff000000) != 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar1 = xTaskGetSchedulerState();
  if ((uVar1 == 0) && (param_5 != 0)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vTaskSuspendAll();
  uVar1 = *param_1;
  if (param_4 == 0) {
    if ((param_2 & uVar1) != 0) goto LAB_00086652;
LAB_00086624:
    if (param_5 != 0) {
      if (param_3 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0x1000000;
      }
      if (param_4 != 0) {
        uVar1 = uVar1 | 0x4000000;
      }
      vTaskPlaceOnUnorderedEventList((int)(param_1 + 1),uVar1 | param_2,param_5);
      uVar1 = 0;
    }
  }
  else {
    if (param_2 != (param_2 & uVar1)) goto LAB_00086624;
LAB_00086652:
    param_5 = 0;
    if (param_3 != 0) {
      *param_1 = uVar1 & ~param_2;
    }
  }
  xTaskResumeAll_ret = xTaskResumeAll();
  if (param_5 == 0) {
    return uVar1;
  }
  if (xTaskResumeAll_ret == 0) {
    vPortYield();
  }
  uVar1 = uxTaskResetEventItemValue();
  if ((int)(uVar1 << 6) < 0) goto LAB_0008668a;
  vPortEnterCritical();
  uVar1 = *param_1;
  if (param_4 == 0) {
    if ((param_2 & uVar1) != 0) {
LAB_00086698:
      if (param_3 != 0) {
        *param_1 = uVar1 & ~param_2;
      }
    }
  }
  else if (param_2 == (param_2 & uVar1)) goto LAB_00086698;
  vPortExitCritical();
LAB_0008668a:
  return uVar1 & 0xffffff;
}


// ===== xEventGroupSetBits @ 000866a4 (110 bytes)

/* [inference] */

void xEventGroupSetBits(void *pvEventGroup,uint ulBitsToSet)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  if (pvEventGroup == (void *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((ulBitsToSet & 0xff000000) != 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vTaskSuspendAll();
  *(uint *)pvEventGroup = *(uint *)pvEventGroup | ulBitsToSet;
  uVar5 = 0;
  puVar6 = *(uint **)((int)pvEventGroup + 0x10);
LAB_000866d0:
  do {
    puVar1 = puVar6;
    uVar2 = *(uint *)pvEventGroup;
    if ((uint *)((int)pvEventGroup + 0xc) == puVar1) {
      *(uint *)pvEventGroup = uVar2 & ~uVar5;
      xTaskResumeAll();
      return;
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

/* list+8 (xListEnd) = item value 0xFFFFFFFF, pxIndex/next/previous = &xListEnd, count = 0 [fact:
   0x86716]; same as vListInitialise in FreeRTOS 10.3.0 list.c without the integrity-check fields
   [inference] */

void vListInitialise(void *param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1 + 8;
  *(undefined4 *)((int)param_1 + 8) = 0xffffffff;
  *(int *)((int)param_1 + 0xc) = iVar1;
  *(int *)((int)param_1 + 4) = iVar1;
  *(int *)((int)param_1 + 0x10) = iVar1;
  *(undefined4 *)param_1 = 0;
  return;
}


// ===== vListInitialiseItem @ 0008672c (6 bytes)

/* item+0x10 (pvContainer) = 0 [fact: 0x8672C]; same as vListInitialiseItem in FreeRTOS 10.3.0
   list.c [inference] */

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

/* value 0xFFFFFFFF goes before xListEnd, else walk from xListEnd while next value <= new value,
   link in, set pvContainer, count+1 [fact: 0x8674A]; same as vListInsert in FreeRTOS 10.3.0 list.c
   [inference] */

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


// ===== uxListRemove @ 00086778 (32 bytes)

/* [inference] */

int uxListRemove(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 8);
  *(int *)(iVar1 + 8) = iVar2;
  *(int *)(iVar2 + 4) = iVar1;
  if (piVar3[1] == param_1) {
    piVar3[1] = iVar2;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *piVar3 = *piVar3 + -1;
  return *piVar3;
}


// ===== prvIsQueueEmpty @ 00086798 (22 bytes)

/* [inference] */

bool prvIsQueueEmpty(int param_1)

{
  int iVar1;
  
  vPortEnterCritical();
  iVar1 = *(int *)(param_1 + 0x38);
  vPortExitCritical();
  return iVar1 == 0;
}


// ===== prvCopyDataToQueue @ 000867ae (106 bytes)

/* [inference] */

uint prvCopyDataToQueue(uint *param_1,void *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1[0x10];
  uVar3 = param_1[0xe];
  if (uVar1 == 0) {
    if (*param_1 == 0) {
      uVar1 = xTaskPriorityDisinherit(param_1[2]);
      param_1[2] = 0;
      goto LAB_000867c8;
    }
  }
  else {
    if (param_3 == 0) {
      memcpy((void *)param_1[1],param_2,uVar1);
      uVar2 = param_1[1];
      param_1[1] = uVar2 + param_1[0x10];
      uVar1 = 0;
      if (param_1[2] <= uVar2 + param_1[0x10]) {
        param_1[1] = *param_1;
      }
      goto LAB_000867c8;
    }
    memcpy((void *)param_1[3],param_2,uVar1);
    uVar1 = param_1[3] - param_1[0x10];
    param_1[3] = uVar1;
    if (uVar1 < *param_1) {
      param_1[3] = param_1[2] - param_1[0x10];
    }
    if (param_3 == 2) {
      if (uVar3 == 0) {
        uVar1 = 0;
        goto LAB_000867c8;
      }
      uVar3 = uVar3 - 1;
    }
  }
  uVar1 = 0;
LAB_000867c8:
  param_1[0xe] = uVar3 + 1;
  return uVar1;
}


// ===== prvCopyDataFromQueue @ 00086818 (44 bytes)

/* [inference] */

void prvCopyDataFromQueue(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar2 = param_1[0x10];
  if (uVar2 != 0) {
    uVar1 = param_1[2];
    uVar3 = param_1[3] + uVar2;
    bVar4 = uVar1 <= uVar3;
    if (bVar4) {
      uVar1 = *param_1;
    }
    param_1[3] = uVar3;
    if (bVar4) {
      param_1[3] = uVar1;
    }
    memcpy((void *)param_2,(void *)param_1[3],uVar2);
    return;
  }
  return;
}


// ===== prvUnlockQueue @ 00086844 (112 bytes)

/* [inference] */

void prvUnlockQueue(int param_1)

{
  char cVar1;
  uint uVar2;
  
  vPortEnterCritical();
  cVar1 = *(char *)(param_1 + 0x45);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x24) != 0))) {
    uVar2 = xTaskRemoveFromEventList(param_1 + 0x24);
    if (uVar2 != 0) {
      vTaskMissedYield();
    }
    cVar1 = cVar1 + -1;
  }
  *(undefined1 *)(param_1 + 0x45) = 0xff;
  vPortExitCritical();
  vPortEnterCritical();
  cVar1 = *(char *)(param_1 + 0x44);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x10) != 0))) {
    uVar2 = xTaskRemoveFromEventList(param_1 + 0x10);
    if (uVar2 != 0) {
      vTaskMissedYield();
    }
    cVar1 = cVar1 + -1;
  }
  *(undefined1 *)(param_1 + 0x44) = 0xff;
  vPortExitCritical();
  return;
}


// ===== xQueueGenericReset @ 000868b4 (98 bytes)

/* [inference] */

undefined4 xQueueGenericReset(int *param_1,int param_2)

{
  uint xTaskRemoveFromEventList_ret;
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortEnterCritical();
  iVar2 = param_1[0x10] * param_1[0xf];
  iVar1 = *param_1;
  param_1[2] = iVar1 + iVar2;
  param_1[3] = (iVar2 - param_1[0x10]) + iVar1;
  param_1[0xe] = 0;
  param_1[1] = iVar1;
  *(undefined1 *)(param_1 + 0x11) = 0xff;
  *(undefined1 *)((int)param_1 + 0x45) = 0xff;
  if (param_2 == 0) {
    if ((param_1[4] != 0) &&
       (xTaskRemoveFromEventList_ret = xTaskRemoveFromEventList((int)(param_1 + 4)),
       xTaskRemoveFromEventList_ret != 0)) {
      vPortYield();
    }
  }
  else {
    vListInitialise(param_1 + 4);
    vListInitialise(param_1 + 9);
  }
  vPortExitCritical();
  return 1;
}


// ===== xQueueGenericCreate @ 00086916 (60 bytes)

int xQueueGenericCreate(int param_1,int param_2,byte param_3)

{
  undefined4 *pvPortMalloc_ret;
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    pvPortMalloc_ret = pvPortMalloc(param_2 * param_1 + 0x50);
    if (pvPortMalloc_ret != (void *)0x0) {
      puVar1 = pvPortMalloc_ret;
      if (param_2 != 0) {
        puVar1 = pvPortMalloc_ret + 0x14;
      }
      pvPortMalloc_ret[0xf] = param_1;
      pvPortMalloc_ret[0x10] = param_2;
      *pvPortMalloc_ret = puVar1;
      xQueueGenericReset(pvPortMalloc_ret,1);
      *(byte *)(pvPortMalloc_ret + 0x13) = param_3;
    }
    return (int)pvPortMalloc_ret;
  }
  ulSetInterruptMask();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== xQueueCreateCountingSemaphore @ 00086952 (36 bytes)

/* [inference] */

uint xQueueCreateCountingSemaphore(uint param_1,uint param_2)

{
  uint xQueueGenericCreate_ret;
  
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_1 < param_2) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  xQueueGenericCreate_ret = xQueueGenericCreate(param_1,0,2);
  if (xQueueGenericCreate_ret != 0) {
    *(uint *)(xQueueGenericCreate_ret + 0x38) = param_2;
  }
  return xQueueGenericCreate_ret;
}


// ===== xQueueGenericSend @ 00086976 (276 bytes)

uint xQueueGenericSend(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  uint local_2c;
  int aiStack_28 [3];
  
  local_2c = param_3;
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = xTaskGetSchedulerState();
  if ((uVar2 == 0) && (local_2c != 0)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  bVar1 = false;
  while( true ) {
    vPortEnterCritical();
    if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
      uVar2 = prvCopyDataToQueue(param_1,param_2,param_4);
      if (*(int *)(param_1 + 0x24) != 0) {
        uVar2 = xTaskRemoveFromEventList(param_1 + 0x24);
      }
      if (uVar2 != 0) {
        vPortYield();
      }
      vPortExitCritical();
      return 1;
    }
    if (local_2c == 0) {
      vPortExitCritical();
      return 0;
    }
    if (!bVar1) {
      vTaskInternalSetTimeOutState(aiStack_28);
    }
    vPortExitCritical();
    vTaskSuspendAll();
    vPortEnterCritical();
    if (*(char *)(param_1 + 0x44) == -1) {
      *(undefined1 *)(param_1 + 0x44) = 0;
    }
    if (*(char *)(param_1 + 0x45) == -1) {
      *(undefined1 *)(param_1 + 0x45) = 0;
    }
    vPortExitCritical();
    uVar2 = xTaskCheckForTimeOut(aiStack_28,&local_2c);
    if (uVar2 != 0) break;
    vPortEnterCritical();
    if (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x3c)) {
      vPortExitCritical();
      vTaskPlaceOnEventList(param_1 + 0x10,local_2c);
      prvUnlockQueue(param_1);
      uVar2 = xTaskResumeAll();
      if (uVar2 == 0) {
        vPortYield();
      }
    }
    else {
      vPortExitCritical();
      prvUnlockQueue(param_1);
      xTaskResumeAll();
    }
    bVar1 = true;
  }
  prvUnlockQueue(param_1);
  xTaskResumeAll();
  return 0;
}


// ===== xQueueGenericSendFromISR @ 00086a8a (146 bytes)

uint xQueueGenericSendFromISR(int param_1,int param_2,void *param_3,int param_4)

{
  char cVar1;
  uint ulSetInterruptMask_ret;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar3 = param_4;
  ulSetInterruptMask_ret = ulSetInterruptMask();
  if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
    cVar1 = *(char *)(param_1 + 0x45);
    prvCopyDataToQueue(param_1,param_2,param_4,*(undefined4 *)(param_1 + 0x38),iVar3);
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x24) != 0) &&
          (uVar2 = xTaskRemoveFromEventList(param_1 + 0x24), uVar2 != 0)) &&
         (param_3 != (void *)0x0)) {
        uVar2 = 1;
        *(undefined4 *)param_3 = 1;
        goto LAB_00086b02;
      }
    }
    else {
      *(char *)(param_1 + 0x45) = cVar1 + '\x01';
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
LAB_00086b02:
  vClearInterruptMask(ulSetInterruptMask_ret);
  return uVar2;
}


// ===== xQueueReceive @ 00086b1c (248 bytes)

undefined4 xQueueReceive(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint local_24;
  uint uStack_20;
  undefined4 uStack_1c;
  
  local_24 = param_3;
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (param_1 == (uint *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (param_1[0x10] != 0)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = xTaskGetSchedulerState();
  if ((uVar2 == 0) && (local_24 != 0)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  bVar1 = false;
  while( true ) {
    vPortEnterCritical();
    uVar2 = param_1[0xe];
    if (uVar2 != 0) {
      prvCopyDataFromQueue(param_1,param_2);
      param_1[0xe] = uVar2 - 1;
      if ((param_1[4] != 0) && (uVar2 = xTaskRemoveFromEventList((int)(param_1 + 4)), uVar2 != 0)) {
        vPortYield();
      }
      vPortExitCritical();
      return 1;
    }
    if (local_24 == 0) break;
    if (!bVar1) {
      vTaskInternalSetTimeOutState(&uStack_20);
    }
    vPortExitCritical();
    vTaskSuspendAll();
    vPortEnterCritical();
    if ((char)param_1[0x11] == -1) {
      *(undefined1 *)(param_1 + 0x11) = 0;
    }
    if (*(char *)((int)param_1 + 0x45) == -1) {
      *(undefined1 *)((int)param_1 + 0x45) = 0;
    }
    vPortExitCritical();
    uVar2 = xTaskCheckForTimeOut((int *)&uStack_20,&local_24);
    if (uVar2 == 0) {
      bVar1 = prvIsQueueEmpty((int)param_1);
      if (bVar1) {
        vTaskPlaceOnEventList((int)(param_1 + 9),local_24);
        prvUnlockQueue((int)param_1);
        uVar2 = xTaskResumeAll();
        if (uVar2 == 0) {
          vPortYield();
        }
      }
      else {
        prvUnlockQueue((int)param_1);
        xTaskResumeAll();
      }
    }
    else {
      prvUnlockQueue((int)param_1);
      xTaskResumeAll();
      bVar1 = prvIsQueueEmpty((int)param_1);
      if (bVar1) {
        return 0;
      }
    }
    bVar1 = true;
  }
  vPortExitCritical();
  return 0;
}


// ===== xQueueSemaphoreTake @ 00086c14 (308 bytes)

uint xQueueSemaphoreTake(int *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int pvTaskIncrementMutexHeldCount_ret;
  uint local_24;
  int aiStack_20 [3];
  
  local_24 = param_2;
  if (param_1 == (int *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_1[0x10] == 0) {
    uVar3 = xTaskGetSchedulerState();
    if ((uVar3 == 0) && (local_24 != 0)) {
      ulSetInterruptMask();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    bVar2 = false;
    bVar1 = bVar2;
    while( true ) {
      vPortEnterCritical();
      if (param_1[0xe] != 0) {
        param_1[0xe] = param_1[0xe] + -1;
        if (*param_1 == 0) {
          pvTaskIncrementMutexHeldCount_ret = pvTaskIncrementMutexHeldCount();
          param_1[2] = pvTaskIncrementMutexHeldCount_ret;
        }
        if ((param_1[4] != 0) && (uVar3 = xTaskRemoveFromEventList((int)(param_1 + 4)), uVar3 != 0))
        {
          vPortYield();
        }
        vPortExitCritical();
        return 1;
      }
      if (local_24 == 0) break;
      if (bVar1 == false) {
        vTaskInternalSetTimeOutState(aiStack_20);
      }
      vPortExitCritical();
      vTaskSuspendAll();
      vPortEnterCritical();
      if ((char)param_1[0x11] == -1) {
        *(undefined1 *)(param_1 + 0x11) = 0;
      }
      if (*(char *)((int)param_1 + 0x45) == -1) {
        *(undefined1 *)((int)param_1 + 0x45) = 0;
      }
      vPortExitCritical();
      uVar3 = xTaskCheckForTimeOut(aiStack_20,&local_24);
      if (uVar3 == 0) {
        bVar1 = prvIsQueueEmpty((int)param_1);
        if (bVar1) {
          if (*param_1 == 0) {
            vPortEnterCritical();
            bVar2 = xTaskPriorityInherit(param_1[2]);
            vPortExitCritical();
          }
          vTaskPlaceOnEventList((int)(param_1 + 9),local_24);
          prvUnlockQueue((int)param_1);
          uVar3 = xTaskResumeAll();
          if (uVar3 == 0) {
            vPortYield();
          }
        }
        else {
          prvUnlockQueue((int)param_1);
          xTaskResumeAll();
        }
      }
      else {
        prvUnlockQueue((int)param_1);
        xTaskResumeAll();
        bVar1 = prvIsQueueEmpty((int)param_1);
        if (bVar1) {
          if (bVar2 == false) {
            return 0;
          }
          vPortEnterCritical();
          uVar3 = 0;
          if (param_1[9] != 0) {
            uVar3 = 5 - *(int *)param_1[0xc];
          }
          vTaskPriorityDisinheritAfterTimeout(param_1[2],uVar3);
          vPortExitCritical();
          return 0;
        }
      }
      bVar1 = true;
    }
    if (bVar2 == false) {
      vPortExitCritical();
      return 0;
    }
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  ulSetInterruptMask();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== xQueueReceiveFromISR @ 00086d48 (116 bytes)

uint xQueueReceiveFromISR(int param_1,int param_2,void *param_3)

{
  char cVar1;
  uint ulSetInterruptMask_ret;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  ulSetInterruptMask_ret = ulSetInterruptMask();
  iVar2 = *(int *)(param_1 + 0x38);
  uVar3 = 0;
  if (iVar2 != 0) {
    cVar1 = *(char *)(param_1 + 0x44);
    prvCopyDataFromQueue((uint *)param_1,param_2);
    *(int *)(param_1 + 0x38) = iVar2 + -1;
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x10) != 0) &&
          (uVar3 = xTaskRemoveFromEventList(param_1 + 0x10), uVar3 != 0)) &&
         (param_3 != (void *)0x0)) {
        uVar3 = 1;
        *(undefined4 *)param_3 = 1;
        goto LAB_00086da6;
      }
    }
    else {
      *(char *)(param_1 + 0x44) = cVar1 + '\x01';
    }
    uVar3 = 1;
  }
LAB_00086da6:
  vClearInterruptMask(ulSetInterruptMask_ret);
  return uVar3;
}


// ===== vQueueDelete @ 00086dbc (26 bytes)

/* [inference] */

void vQueueDelete(int param_1)

{
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vQueueUnregisterQueue(param_1);
  vPortFree(param_1);
  return;
}


// ===== vQueueWaitForMessageRestricted @ 00086dd6 (70 bytes)

/* [inference] */

void vQueueWaitForMessageRestricted(int param_1,uint param_2,uint param_3)

{
  vPortEnterCritical();
  if (*(char *)(param_1 + 0x44) == -1) {
    *(undefined1 *)(param_1 + 0x44) = 0;
  }
  if (*(char *)(param_1 + 0x45) == -1) {
    *(undefined1 *)(param_1 + 0x45) = 0;
  }
  vPortExitCritical();
  if (*(int *)(param_1 + 0x38) == 0) {
    vTaskPlaceOnEventListRestricted(param_1 + 0x24,param_2,param_3);
  }
  prvUnlockQueue(param_1);
  return;
}


// ===== CLOCK_AttachClk @ 00086e1c (60 bytes)

void CLOCK_AttachClk(uint param_1)

{
  dword *pdVar1;
  uint uVar2;
  
  if ((param_1 & 0x80008000) == 0) {
    pdVar1 = &CLKCTL0_BASE;
  }
  else {
    pdVar1 = &CLKCTL1_BASE;
  }
  if ((param_1 & 0xfff) != 0) {
    *(uint *)((int)pdVar1 + (param_1 & 0xfff)) = (param_1 & 0x7fff) >> 0xc;
    uVar2 = (param_1 & 0xfffffff) >> 0x10;
    if ((int)param_1 < 0) {
      pdVar1 = &CLKCTL1_BASE;
    }
    else {
      pdVar1 = &CLKCTL0_BASE;
    }
    if (uVar2 != 0) {
      *(uint *)((int)pdVar1 + uVar2) = (param_1 & 0x7fffffff) >> 0x1c;
    }
  }
  return;
}


// ===== CLOCK_SetClkDiv @ 00086e58 (52 bytes)

void CLOCK_SetClkDiv(uint param_1,int param_2)

{
  dword *pdVar1;
  uint *puVar2;
  
  if ((int)param_1 < 0) {
    pdVar1 = &CLKCTL1_BASE;
  }
  else {
    pdVar1 = &CLKCTL0_BASE;
  }
  puVar2 = (uint *)((int)pdVar1 + (param_1 & 0xfff));
  *puVar2 = *puVar2 | 0x20000000;
  if (param_2 != 0) {
    *puVar2 = param_2 - 1;
    do {
    } while ((int)*puVar2 < 0);
    return;
  }
  *puVar2 = *puVar2 | 0x40000000;
  return;
}


// ===== CTIMER0_DriverIRQHandler @ 00086e8c (6 bytes)

/* IRQ10 [fact: vector] */

void CTIMER0_DriverIRQHandler(void)

{
                    /* dispatches CTIMER callbacks for one instance [doc] */
  CTIMER_GenericIRQHandler(0);
  return;
}


// ===== CTIMER1_DriverIRQHandler @ 00086e92 (6 bytes)

/* IRQ11 [fact: vector] */

void CTIMER1_DriverIRQHandler(void)

{
                    /* dispatches CTIMER callbacks for one instance [doc] */
  CTIMER_GenericIRQHandler(1);
  return;
}


// ===== CTIMER2_DriverIRQHandler @ 00086e98 (6 bytes)

/* IRQ39 [fact: vector] */

void CTIMER2_DriverIRQHandler(void)

{
                    /* dispatches CTIMER callbacks for one instance [doc] */
  CTIMER_GenericIRQHandler(2);
  return;
}


// ===== CTIMER3_DriverIRQHandler @ 00086e9e (6 bytes)

/* IRQ13 [fact: vector] */

void CTIMER3_DriverIRQHandler(void)

{
                    /* dispatches CTIMER callbacks for one instance [doc] */
  CTIMER_GenericIRQHandler(3);
  return;
}


// ===== CTIMER4_DriverIRQHandler @ 00086ea4 (6 bytes)

/* IRQ40 [fact: vector] */

void CTIMER4_DriverIRQHandler(void)

{
                    /* dispatches CTIMER callbacks for one instance [doc] */
  CTIMER_GenericIRQHandler(4);
  return;
}


// ===== DSP_CopyImage @ 00086eaa (26 bytes)

void DSP_CopyImage(void *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)param_1;
  puVar2 = (undefined4 *)(*(int *)((int)param_1 + 4) + -4);
  puVar1 = (undefined4 *)(*(int *)((int)param_1 + 8) + (int)puVar3);
  for (; puVar3 != puVar1; puVar3 = puVar3 + 1) {
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar3;
  }
  return;
}


// ===== hashcrypt_save_running_hash @ 00086ec4 (44 bytes)

/* n = 5 if ctx byte +0x44 == 1 (kHASHCRYPT_Sha1) else 8; wait HASHCRYPT STATUS bit 1 (DIGEST); copy
   DIGEST0[0..n) (base+0x40) to ctx+0x58 [fact: 0x86EC4]. Only caller 0x8425A in the HASHCRYPT IRQ
   handler after INTENCLR/MEMCTRL=0 [fact]. Same as static hashcrypt_save_running_hash in
   mcux-sdk@8a289764 drivers/hashcrypt/fsl_hashcrypt.c, minus its ERROR check and status return
   (older SDK version) [inference] */

void hashcrypt_save_running_hash(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int i;
  int iVar3;
  
  if (*(char *)(param_2 + 0x44) == '\x01') {
    iVar2 = 5;
  }
  else {
    iVar2 = 8;
  }
  do {
  } while (-1 < *(int *)(param_1 + 4) << 0x1e);
  i = 0;
  puVar1 = (undefined4 *)(param_2 + 0x58);
  do {
    iVar3 = i + 0x10;
    i = i + 1;
    *puVar1 = *(undefined4 *)(param_1 + iVar3 * 4);
    puVar1 = puVar1 + 1;
  } while (iVar2 != i);
  return;
}


// ===== INPUTMUX_AttachSignal @ 00086ef0 (14 bytes)

void INPUTMUX_AttachSignal(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + param_2 * 4 + (param_3 >> 0x14)) = param_3 & 0xfffff;
  return;
}


// ===== MU_SendMsg @ 00086efe (22 bytes)

/* Wait TE bit in SR (0x60), write TR[n] [inference] */

void MU_SendMsg(int param_1,uint param_2,uint param_3)

{
  do {
  } while ((*(uint *)(param_1 + 0x60) & 0x800000U >> (param_2 & 0xff)) == 0);
  *(uint *)(param_1 + (param_2 + 8) * 4) = param_3;
  return;
}


// ===== MU_SetFlags @ 00086f14 (26 bytes)

void MU_SetFlags(int param_1,uint param_2)

{
  do {
  } while (*(int *)(param_1 + 0x60) << 0x17 < 0);
  *(uint *)(param_1 + 100) = param_2 & 7 | *(uint *)(param_1 + 100) & 0xfff0fff8;
  return;
}


// ===== PINT_PatternMatchResetDetectLogic @ 00086f2e (14 bytes)

/* PMCTRL PMAT != 0 -> PMSRC = PMSRC [inference] */

void PINT_PatternMatchResetDetectLogic(int param_1)

{
  if (*(uint *)(param_1 + 0x28) >> 0x18 != 0) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  }
  return;
}

