// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

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
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortEnterCritical();
  iVar3 = param_1[0x10] * param_1[0xf];
  iVar2 = *param_1;
  param_1[2] = iVar2 + iVar3;
  param_1[3] = (iVar3 - param_1[0x10]) + iVar2;
  param_1[0xe] = 0;
  param_1[1] = iVar2;
  *(undefined1 *)(param_1 + 0x11) = 0xff;
  *(undefined1 *)((int)param_1 + 0x45) = 0xff;
  if (param_2 == 0) {
    if ((param_1[4] != 0) && (uVar1 = xTaskRemoveFromEventList((int)(param_1 + 4)), uVar1 != 0)) {
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
  uint *puVar1;
  uint *puVar2;
  
  if (param_1 != 0) {
    puVar1 = (uint *)pvPortMalloc(param_2 * param_1 + 0x50);
    if (puVar1 != (uint *)0x0) {
      puVar2 = puVar1;
      if (param_2 != 0) {
        puVar2 = puVar1 + 0x14;
      }
      puVar1[0xf] = param_1;
      puVar1[0x10] = param_2;
      *puVar1 = (uint)puVar2;
      xQueueGenericReset(puVar1,1);
      *(byte *)(puVar1 + 0x13) = param_3;
    }
    return (uint)puVar1;
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
  uint uVar1;
  
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
  uVar1 = xQueueGenericCreate(param_1,0,2);
  if (uVar1 != 0) {
    *(uint *)(uVar1 + 0x38) = param_2;
  }
  return uVar1;
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
  uint uVar2;
  uint uVar3;
  int iVar4;
  
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
  iVar4 = param_4;
  uVar2 = ulSetInterruptMask();
  if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
    cVar1 = *(char *)(param_1 + 0x45);
    prvCopyDataToQueue(param_1,param_2,param_4,*(undefined4 *)(param_1 + 0x38),iVar4);
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x24) != 0) &&
          (uVar3 = xTaskRemoveFromEventList(param_1 + 0x24), uVar3 != 0)) &&
         (param_3 != (void *)0x0)) {
        uVar3 = 1;
        *(undefined4 *)param_3 = 1;
        goto LAB_00086b02;
      }
    }
    else {
      *(char *)(param_1 + 0x45) = cVar1 + '\x01';
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
LAB_00086b02:
  vClearInterruptMask(uVar2);
  return uVar3;
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
  int iVar4;
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
          iVar4 = pvTaskIncrementMutexHeldCount();
          param_1[2] = iVar4;
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
  uint uVar2;
  int iVar3;
  uint uVar4;
  
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
  uVar2 = ulSetInterruptMask();
  iVar3 = *(int *)(param_1 + 0x38);
  uVar4 = 0;
  if (iVar3 != 0) {
    cVar1 = *(char *)(param_1 + 0x44);
    prvCopyDataFromQueue((uint *)param_1,param_2);
    *(int *)(param_1 + 0x38) = iVar3 + -1;
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x10) != 0) &&
          (uVar4 = xTaskRemoveFromEventList(param_1 + 0x10), uVar4 != 0)) &&
         (param_3 != (void *)0x0)) {
        uVar4 = 1;
        *(undefined4 *)param_3 = 1;
        goto LAB_00086da6;
      }
    }
    else {
      *(char *)(param_1 + 0x44) = cVar1 + '\x01';
    }
    uVar4 = 1;
  }
LAB_00086da6:
  vClearInterruptMask(uVar2);
  return uVar4;
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


// ===== CTIMER0_DriverIRQHandler @ 00086e8c (86 bytes)

/* IRQ10 [fact: vector] */

void CTIMER0_DriverIRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = CTIMER0_IR;
  CTIMER0_IR = uVar1;
  if (DAT_000a1ef0 == '\0') {
    if ((code *)*DAT_00088934 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*DAT_00088934)(uVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & uVar1) != 0) && ((code *)DAT_00088934[uVar2] != (code *)0x0)) {
        (*(code *)DAT_00088934[uVar2])(uVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 7);
  }
  return;
}


// ===== CTIMER1_DriverIRQHandler @ 00086e92 (6 bytes)

/* IRQ11 [fact: vector] */

void CTIMER1_DriverIRQHandler(void)

{
  dword dVar1;
  uint uVar2;
  
  dVar1 = CTIMER1_IR;
  CTIMER1_IR = dVar1;
  if (cRam000a1ef1 == '\0') {
    if ((code *)*puRam00088938 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam00088938)(dVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & dVar1) != 0) && ((code *)puRam00088938[uVar2] != (code *)0x0)) {
        (*(code *)puRam00088938[uVar2])(dVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 7);
  }
  return;
}


// ===== CTIMER2_DriverIRQHandler @ 00086e98 (6 bytes)

/* IRQ39 [fact: vector] */

void CTIMER2_DriverIRQHandler(void)

{
  dword dVar1;
  uint uVar2;
  
  dVar1 = CTIMER2_IR;
  CTIMER2_IR = dVar1;
  if (cRam000a1ef2 == '\0') {
    if ((code *)*puRam0008893c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam0008893c)(dVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & dVar1) != 0) && ((code *)puRam0008893c[uVar2] != (code *)0x0)) {
        (*(code *)puRam0008893c[uVar2])(dVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 7);
  }
  return;
}


// ===== CTIMER3_DriverIRQHandler @ 00086e9e (6 bytes)

/* IRQ13 [fact: vector] */

void CTIMER3_DriverIRQHandler(void)

{
  dword dVar1;
  uint uVar2;
  
  dVar1 = CTIMER3_IR;
  CTIMER3_IR = dVar1;
  if (cRam000a1ef3 == '\0') {
    if ((code *)*puRam00088940 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam00088940)(dVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & dVar1) != 0) && ((code *)puRam00088940[uVar2] != (code *)0x0)) {
        (*(code *)puRam00088940[uVar2])(dVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 7);
  }
  return;
}


// ===== CTIMER4_DriverIRQHandler @ 00086ea4 (6 bytes)

/* IRQ40 [fact: vector] */

void CTIMER4_DriverIRQHandler(void)

{
  dword dVar1;
  uint uVar2;
  
  dVar1 = CTIMER4_IR;
  CTIMER4_IR = dVar1;
  if (cRam000a1ef4 == '\0') {
    if ((code *)*puRam00088944 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam00088944)(dVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & dVar1) != 0) && ((code *)puRam00088944[uVar2] != (code *)0x0)) {
        (*(code *)puRam00088944[uVar2])(dVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 7);
  }
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
  int iVar3;
  int iVar4;
  
  if (*(char *)(param_2 + 0x44) == '\x01') {
    iVar2 = 5;
  }
  else {
    iVar2 = 8;
  }
  do {
  } while (-1 < *(int *)(param_1 + 4) << 0x1e);
  iVar3 = 0;
  puVar1 = (undefined4 *)(param_2 + 0x58);
  do {
    iVar4 = iVar3 + 0x10;
    iVar3 = iVar3 + 1;
    *puVar1 = *(undefined4 *)(param_1 + iVar4 * 4);
    puVar1 = puVar1 + 1;
  } while (iVar2 != iVar3);
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


// ===== PINT_PinInterruptClrStatus @ 00086f3c (22 bytes)

/* NEW [inference] */

void PINT_PinInterruptClrStatus(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 1 << (param_2 & 0xff);
  if (((*param_1 & uVar1) == 0) && ((uVar1 & param_1[9]) != 0)) {
    param_1[9] = uVar1;
  }
  return;
}


// ===== RESET_ClearPeripheralReset @ 00086f52 (18 bytes)

void RESET_ClearPeripheralReset(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  RESET_SetPeripheralReset();
  uVar2 = 1 << (param_1 & 0xff);
  switch(param_1 >> 8) {
  case 0:
    RSTCTL0_PRSTCTL0_CLR = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL0;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 1:
    RSTCTL0_PRSTCTL1_CLR = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL1;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 2:
    RSTCTL0_PRSTCTL2_CLR = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL2;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 3:
    RSTCTL1_PRSTCTL0_CLR = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL0;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 4:
    RSTCTL1_PRSTCTL1_CLR = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL1;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 5:
    RSTCTL1_PRSTCTL2_CLR = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL2;
    } while ((uVar2 & ~uVar1) == 0);
  }
  return;
}


// ===== SCTIMER_GetDefaultConfig @ 00086f64 (38 bytes)

void SCTIMER_GetDefaultConfig(void *param_1)

{
  memset(param_1,0,9);
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  *(undefined1 *)((int)param_1 + 8) = 0xf;
  return;
}


// ===== SCTIMER_UpdatePwmDutycycle @ 00086f8a (98 bytes)

void SCTIMER_UpdatePwmDutycycle(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  
  iVar4 = param_1 + param_4 * 8;
  uVar5 = *(uint *)(iVar4 + 0x30c);
  uVar3 = *(uint *)(param_1 + ((*(uint *)(iVar4 + 0x304) & 0xf) + 0x40) * 4);
  if (param_3 == 100) {
    sVar1 = (short)uVar3;
    if (*(int *)(param_1 + 4) << 0x1b < 0) {
      uVar2 = sVar1 - 1;
    }
    else {
      uVar2 = sVar1 + 2;
    }
  }
  else {
    uVar6 = __aeabi_uldivmod((ulonglong)param_3 * (ulonglong)uVar3,100);
    uVar2 = (ushort)uVar6;
  }
  iVar4 = param_1 + (uVar5 & 0xf) * 4;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
  *(uint *)(iVar4 + 0x100) = (uint)uVar2;
  *(uint *)(iVar4 + 0x200) = (uint)uVar2;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffb;
  return;
}


// ===== SEMA42_Lock @ 00086fec (28 bytes)

void SEMA42_Lock(int param_1,uint param_2,char param_3)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 + (param_2 ^ 3));
  while (*pcVar1 != (char)(param_3 + '\x01')) {
    do {
    } while (*pcVar1 != '\0');
    *pcVar1 = param_3 + '\x01';
  }
  return;
}


// ===== SEMA42_ResetAllGates @ 00087008 (36 bytes)

ushort SEMA42_ResetAllGates(int param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x42) & 0x3000;
  if ((*(ushort *)(param_1 + 0x42) & 0x3000) == 0) {
    *(undefined2 *)(param_1 + 0x42) = 0xe200;
    *(ushort *)(param_1 + 0x42) = param_2 | 0x1d00;
  }
  else {
    uVar1 = 0x641;
  }
  return uVar1;
}


// ===== USART_GetDefaultConfig @ 0008702c (34 bytes)

void USART_GetDefaultConfig(void *param_1)

{
  memset(param_1,0,0x14);
  *(undefined **)param_1 = &DAT_0001c200;
  *(undefined4 *)((int)param_1 + 4) = 0x10000;
  *(undefined4 *)((int)param_1 + 8) = 0;
  *(undefined4 *)((int)param_1 + 0xc) = 0;
  *(undefined1 *)((int)param_1 + 0x10) = 0;
  return;
}


// ===== USART_SetBaudRate @ 0008704e (178 bytes)

/* OSR/BRG search, returns 0x1651 kStatus_USART_BaudrateNotSupport [inference] */

void * USART_SetBaudRate(uint *param_1,uint param_2,uint param_3)

{
  undefined **ppuVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (((param_1 == (uint *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    ppuVar1 = &Reset;
  }
  else {
    if ((int)(*param_1 << 0x14) < 0) {
      if ((*param_1 & 0x4000) != 0) {
        param_1[8] = param_3 / param_2 - 1;
      }
    }
    else {
      uVar4 = 0xffffffff;
      uVar6 = 0xf;
      uVar8 = 0xffffffff;
      uVar5 = 0xf;
      uVar7 = param_2 << 4;
      do {
        uVar3 = (param_3 * 10) / uVar7 - 5;
        if (uVar3 < 0xa0000) {
          uVar3 = uVar3 / 10;
          uVar2 = param_3 / (uVar3 * (uVar5 + 1) + uVar5 + 1);
          if (param_2 < uVar2) {
            uVar2 = uVar2 - param_2;
          }
          else {
            uVar2 = param_2 - uVar2;
          }
          if (uVar2 < uVar8) {
            uVar4 = uVar3;
            uVar6 = uVar5;
            uVar8 = uVar2;
          }
        }
        uVar5 = uVar5 - 1;
        uVar7 = uVar7 - param_2;
      } while (uVar5 != 7);
      uVar8 = param_3 / (uVar6 * (uVar4 + 1) + uVar4 + 1);
      if (param_2 < uVar8) {
        uVar8 = uVar8 - param_2;
      }
      else {
        uVar8 = param_2 - uVar8;
      }
      if (((param_2 / 100) * 3 < uVar8) || (0xffff < uVar4)) {
        return &DAT_00001651;
      }
      param_1[10] = uVar6;
      param_1[8] = uVar4;
    }
    ppuVar1 = (undefined **)0x0;
  }
  return ppuVar1;
}


// ===== USART_Init @ 00087100 (306 bytes)

undefined ** USART_Init(uint *param_1,uint *param_2,uint param_3)

{
  byte bVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  uint uVar4;
  
  if (((param_1 == (uint *)0x0) || (param_2 == (uint *)0x0)) || (param_3 == 0)) {
    ppuVar2 = &Reset;
  }
  else {
    ppuVar2 = (undefined **)FLEXCOMM_Init((int)param_1,1);
    if (ppuVar2 == (undefined **)0x0) {
      if (*(char *)((int)param_2 + 9) != '\0') {
        param_1[0x380] = param_1[0x380] | 0x10001;
        param_1[0x382] = param_1[0x382] & 0xfffff0ff;
        param_1[0x382] = (*(byte *)((int)param_2 + 0xd) & 0xf) << 8 | param_1[0x382];
        param_1[0x382] = param_1[0x382] | 1;
      }
      if ((char)param_2[2] != '\0') {
        param_1[0x380] = param_1[0x380] | 0x20002;
        param_1[0x382] = param_1[0x382] & 0xfff0ffff;
        param_1[0x382] = (*(byte *)((int)param_2 + 0xe) & 0xf) << 0x10 | param_1[0x382];
        param_1[0x382] = param_1[0x382] | 2;
      }
      bVar1 = *(byte *)((int)param_2 + 0xb);
      uVar4 = *param_2;
      *param_1 = (uint)bVar1 << 7 | (uint)*(byte *)((int)param_2 + 7) << 0xf |
                 (*(byte *)((int)param_2 + 0xf) & 2) << 10 | (uint)(byte)param_2[3] << 9 |
                 ((byte)param_2[1] & 3) << 4 | (*(byte *)((int)param_2 + 5) & 1) << 6 |
                 (*(byte *)((int)param_2 + 6) & 3) << 2 | (*(byte *)((int)param_2 + 0xf) & 1) << 0xe
                 | ((byte)param_2[4] & 1) << 0xc | 1;
      if (bVar1 == 0) {
        ppuVar3 = USART_SetBaudRate(param_1,uVar4,param_3);
        if (ppuVar3 != (undefined **)0x0) {
          return ppuVar3;
        }
      }
      else {
        if ((undefined *)((0x2580 / uVar4) * uVar4) != &DAT_00002580) {
          return (undefined **)&DAT_00001651;
        }
        param_1[8] = 0x2580 / uVar4;
      }
      if (*(char *)((int)param_2 + 10) == '\0') {
        uVar4 = param_1[1] & 0xfffffeff;
      }
      else {
        uVar4 = param_1[1] | 0x100;
      }
      param_1[1] = uVar4;
    }
  }
  return ppuVar2;
}


// ===== BOARD_InitDebugConsole @ 00087232 (2 bytes)

/* empty (bx lr), no callers [fact: 0x87232]; its address (0x87233, Thumb bit) is the literal at
   0x80A10 that BOARD_SetFlexspiClock masks with 0xE8000000 and compares with 0x08000000 before
   BOARD_DeinitXip/BOARD_InitXip [fact: 0x809BC..0x80A06], which is the BOARD_IS_XIP_FLEXSPI() test
   on &BOARD_InitDebugConsole in mcux-sdk@8a289764 boards/evkmimxrt685/board.c [inference]; the
   vendor built it empty */

void BOARD_InitDebugConsole(void)

{
  return;
}


// ===== BOARD_FlexspiClockSafeConfig @ 00087234 (8 bytes)

/* BOARD_SetFlexspiClock(3 = FFRO, /1) before the main clock switch [inference] */

void BOARD_FlexspiClockSafeConfig(void)

{
  BOARD_SetFlexspiClock(3,1);
  return;
}


// ===== app_init_nop @ 00087240 (2 bytes)

/* body is only bx lr [fact: 0x87240]; one caller, app_main 0x81098, between BOARD_BootClockRUN and
   regfile_clear [fact]. Not BOARD_InitDebugConsole, which is the separate empty function at 0x87232
   [fact: literal 0x80A10]. Open: which source function this was; would be settled by the vendor's
   source or link map */

void app_init_nop(void)

{
  return;
}


// ===== BOARD_InitPins_flexcomm @ 00087242 (42 bytes)

/* IOPCTL: PIO0_1/2 FC0 USART, PIO0_7..10 FC1 SPI, PIO1_10 MCLK, PIO2_2 SCT0_OUT0, PIO2_30 CLKIN
   [fact] */

void BOARD_InitPins_flexcomm(void)

{
  IOPCTL_PIO0_1 = 1;
  IOPCTL_PIO0_10 = 1;
  IOPCTL_PIO0_2 = 0x41;
  IOPCTL_PIO0_7 = 0x41;
  IOPCTL_PIO0_8 = 0x41;
  IOPCTL_PIO0_9 = 0x41;
  IOPCTL_PIO1_10 = 0x101;
  IOPCTL_PIO2_2 = 2;
  IOPCTL_PIO2_30 = 0x45;
  return;
}


// ===== BOARD_InitPins_i2s @ 0008726c (40 bytes)

/* IOPCTL: PIO0_14..16 FC2 (SCK input inverted), PIO0_23 FC3 data in, PIO0_30 FC4 data in, PIO1_3..5
   FC5 [fact] */

void BOARD_InitPins_i2s(void)

{
  IOPCTL_PIO0_14 = 0x941;
  IOPCTL_PIO0_15 = 0x141;
  IOPCTL_PIO0_16 = 0x101;
  IOPCTL_PIO0_23 = 0x141;
  IOPCTL_PIO0_30 = 0x141;
  IOPCTL_PIO1_3 = 0x141;
  IOPCTL_PIO1_4 = 0x141;
  IOPCTL_PIO1_5 = 0x101;
  return;
}


// ===== BOARD_InitPins @ 00087294 (26 bytes)

void BOARD_InitPins(void)

{
  BOARD_InitPins_flexcomm();
  BOARD_InitPins_P0();
  BOARD_InitPins_codec_spi();
  BOARD_InitPins_i2s();
  BOARD_InitPins_debug_gpio();
  return;
}


// ===== main @ 000872ae (14 bytes)

void main(void)

{
  stdio_init();
  app_main();
  return;
}


// ===== free @ 000872c4 (48 bytes)

/* Marks block 0x10000000 and merges free successors [inference] */

void free(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + -0xc) = 0x10000000;
    while ((piVar1 = *(int **)(param_1 + -4), piVar1 != (int *)0x0 && (*piVar1 == 0x10000000))) {
      *(int *)(param_1 + -8) = *(int *)(param_1 + -8) + 3 + piVar1[1];
      *(int *)(param_1 + -4) = piVar1[2];
    }
  }
  return;
}


// ===== setvbuf @ 000872f8 (62 bytes)

/* _IOFBF 0x100 / _IOLBF 0x200 / _IONBF 0x400 [inference] */

undefined4 setvbuf(int *param_1,int *param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_1[3] & 3U) == 0) {
LAB_00087312:
    uVar1 = 1;
  }
  else {
    if (param_3 == 0x200) {
LAB_0008732a:
      if (0xfffffe < param_4 - 1U) goto LAB_00087312;
    }
    else {
      if (param_3 != 0x400) {
        if (param_3 != 0x100) goto LAB_00087312;
        goto LAB_0008732a;
      }
      param_4 = 1;
      param_2 = param_1 + 9;
    }
    param_1[4] = (int)param_2;
    *param_1 = (int)param_2;
    param_1[7] = param_4;
    param_1[3] = param_3 | param_1[3];
    uVar1 = 0;
  }
  return uVar1;
}


// ===== strcmp @ 00087336 (68 bytes)

int strcmp(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = ((uint)param_1 | (uint)param_2) & 3;
  puVar3 = param_1;
  puVar4 = param_2;
  for (; puVar2 = param_2, puVar1 = param_1, uVar5 == 0;
      uVar5 = uVar5 + 0xfefefeff & ~uVar5 & 0x80808080) {
    uVar5 = *puVar2;
    puVar3 = puVar1;
    puVar4 = puVar2;
    if (uVar5 != *puVar1) break;
    param_1 = puVar1 + 1;
    param_2 = puVar2 + 1;
  }
  do {
    uVar5 = (uint)(byte)*puVar3;
    if (uVar5 != (byte)*puVar4) {
      return uVar5 - (byte)*puVar4;
    }
    puVar3 = (uint *)((int)puVar3 + 1);
    puVar4 = (uint *)((int)puVar4 + 1);
  } while (uVar5 != 0);
  return 0;
}


// ===== strlen @ 0008737a (72 bytes)

int strlen(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar1 = param_1;
  do {
    if (((uint)puVar1 & 3) == 0) goto LAB_00087384;
    puVar2 = (uint *)((int)puVar1 + 1);
    uVar3 = *puVar1;
    puVar1 = puVar2;
  } while ((char)uVar3 != '\0');
LAB_000873b6:
  return (int)puVar2 - ((int)param_1 + 1);
LAB_00087384:
  do {
    puVar4 = puVar1;
    puVar2 = puVar4 + 1;
    uVar3 = *puVar4;
    puVar1 = puVar2;
  } while ((uVar3 + 0xfefefeff & ~uVar3 & 0x80808080) == 0);
  if ((uVar3 & 0xff) == 0) {
    puVar2 = (uint *)((int)puVar4 + 1);
  }
  else if ((uVar3 & 0xff00) == 0) {
    puVar2 = (uint *)((int)puVar4 + 2);
  }
  else if ((uVar3 & 0xff0000) == 0) {
    puVar2 = (uint *)((int)puVar4 + 3);
  }
  goto LAB_000873b6;
}


// ===== strncmp @ 000873c2 (86 bytes)

int strncmp(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar2 = *param_2;
      if ((uVar2 != *param_1) || ((uVar2 + 0xfefefeff & ~uVar2 & 0x80808080) != 0)) break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  }
  puVar1 = param_1;
  while( true ) {
    if (puVar1 == (uint *)(param_3 + (int)param_1)) {
      return 0;
    }
    uVar2 = (uint)(byte)*puVar1;
    if (uVar2 != (byte)*param_2) break;
    puVar1 = (uint *)((int)puVar1 + 1);
    param_2 = (uint *)((int)param_2 + 1);
    if (uVar2 == 0) {
      return 0;
    }
  }
  return uVar2 - (byte)*param_2;
}


// ===== strncpy @ 00087418 (88 bytes)

/* [inference] */

void strncpy(uint *param_1,uint *param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar5 = *param_2;
      if ((uVar5 + 0xfefefeff & ~uVar5 & 0x80808080) != 0) break;
      *param_1 = uVar5;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  }
  pcVar2 = (char *)((int)param_2 + -1);
  do {
    param_3 = param_3 - 1;
    if (param_3 == 0xffffffff) {
      return;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
    puVar4 = (uint *)((int)param_1 + 1);
    *(char *)param_1 = cVar1;
    param_1 = puVar4;
  } while (cVar1 != '\0');
  puVar3 = (uint *)(param_3 + (int)puVar4);
  for (; puVar4 != puVar3; puVar4 = (uint *)((int)puVar4 + 1)) {
    *(char *)puVar4 = '\0';
  }
  return;
}

