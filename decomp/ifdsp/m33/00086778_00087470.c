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

undefined4 prvCopyDataToQueue(uint *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1[0xe];
  if (param_1[0x10] == 0) {
    if (*param_1 == 0) {
      uVar1 = xTaskPriorityDisinherit(param_1[2]);
      param_1[2] = 0;
      goto LAB_000867c8;
    }
  }
  else {
    if (param_3 == 0) {
      memcpy(param_1[1]);
      uVar2 = param_1[1];
      param_1[1] = uVar2 + param_1[0x10];
      uVar1 = 0;
      if (param_1[2] <= uVar2 + param_1[0x10]) {
        param_1[1] = *param_1;
      }
      goto LAB_000867c8;
    }
    memcpy(param_1[3]);
    uVar2 = param_1[3] - param_1[0x10];
    param_1[3] = uVar2;
    if (uVar2 < *param_1) {
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

void prvCopyDataFromQueue(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_1[0x10] != 0) {
    uVar1 = param_1[2];
    uVar2 = param_1[3] + param_1[0x10];
    bVar3 = uVar1 <= uVar2;
    if (bVar3) {
      uVar1 = *param_1;
    }
    param_1[3] = uVar2;
    if (bVar3) {
      param_1[3] = uVar1;
    }
    memcpy(param_2,param_1[3]);
    return;
  }
  return;
}


// ===== prvUnlockQueue @ 00086844 (112 bytes)

/* [inference] */

void prvUnlockQueue(int param_1)

{
  char cVar1;
  int iVar2;
  
  vPortEnterCritical();
  cVar1 = *(char *)(param_1 + 0x45);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x24) != 0))) {
    iVar2 = xTaskRemoveFromEventList(param_1 + 0x24);
    if (iVar2 != 0) {
      vTaskMissedYield();
    }
    cVar1 = cVar1 + -1;
  }
  *(undefined1 *)(param_1 + 0x45) = 0xff;
  vPortExitCritical();
  vPortEnterCritical();
  cVar1 = *(char *)(param_1 + 0x44);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x10) != 0))) {
    iVar2 = xTaskRemoveFromEventList(param_1 + 0x10);
    if (iVar2 != 0) {
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
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    vPortRaiseBASEPRI();
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
    if ((param_1[4] != 0) && (iVar1 = xTaskRemoveFromEventList(param_1 + 4), iVar1 != 0)) {
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

int xQueueGenericCreate(int param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    piVar1 = (int *)pvPortMalloc(param_2 * param_1 + 0x50);
    if (piVar1 != (int *)0x0) {
      piVar2 = piVar1;
      if (param_2 != 0) {
        piVar2 = piVar1 + 0x14;
      }
      piVar1[0xf] = param_1;
      piVar1[0x10] = param_2;
      *piVar1 = (int)piVar2;
      xQueueGenericReset(piVar1,1);
      *(undefined1 *)(piVar1 + 0x13) = param_3;
    }
    return (int)piVar1;
  }
  vPortRaiseBASEPRI();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== xQueueCreateCountingSemaphore @ 00086952 (36 bytes)

/* [inference] */

void xQueueCreateCountingSemaphore(uint param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_1 < param_2) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = xQueueGenericCreate(param_1,0,2);
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 0x38) = param_2;
  }
  return;
}


// ===== xQueueGenericSend @ 00086976 (276 bytes)

undefined4 xQueueGenericSend(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int local_2c;
  undefined1 auStack_28 [12];
  
  local_2c = param_3;
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar2 = xTaskGetSchedulerState();
  if ((iVar2 == 0) && (local_2c != 0)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  bVar1 = false;
  while( true ) {
    vPortEnterCritical();
    if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
      iVar2 = prvCopyDataToQueue(param_1,param_2,param_4);
      if (*(int *)(param_1 + 0x24) != 0) {
        iVar2 = xTaskRemoveFromEventList(param_1 + 0x24);
      }
      if (iVar2 != 0) {
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
      vTaskInternalSetTimeOutState(auStack_28);
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
    iVar2 = xTaskCheckForTimeOut(auStack_28,&local_2c);
    if (iVar2 != 0) break;
    vPortEnterCritical();
    if (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x3c)) {
      vPortExitCritical();
      vTaskPlaceOnEventList(param_1 + 0x10,local_2c);
      prvUnlockQueue(param_1);
      iVar2 = xTaskResumeAll();
      if (iVar2 == 0) {
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

undefined4 xQueueGenericSendFromISR(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_4 == 2) && (*(int *)(param_1 + 0x3c) != 1)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = vPortRaiseBASEPRI();
  if ((*(uint *)(param_1 + 0x38) < *(uint *)(param_1 + 0x3c)) || (param_4 == 2)) {
    cVar1 = *(char *)(param_1 + 0x45);
    prvCopyDataToQueue(param_1,param_2,param_4,*(undefined4 *)(param_1 + 0x38));
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x24) != 0) &&
          (iVar3 = xTaskRemoveFromEventList(param_1 + 0x24), iVar3 != 0)) &&
         (param_3 != (undefined4 *)0x0)) {
        uVar4 = 1;
        *param_3 = 1;
        goto LAB_00086b02;
      }
    }
    else {
      *(char *)(param_1 + 0x45) = cVar1 + '\x01';
    }
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
LAB_00086b02:
  vPortClearBASEPRI(uVar2);
  return uVar4;
}


// ===== xQueueReceive @ 00086b1c (248 bytes)

undefined4 xQueueReceive(int param_1,int param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int local_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  local_24 = param_3;
  iStack_20 = param_3;
  uStack_1c = param_4;
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar2 = xTaskGetSchedulerState();
  if ((iVar2 == 0) && (local_24 != 0)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  bVar1 = false;
  while( true ) {
    vPortEnterCritical();
    iVar2 = *(int *)(param_1 + 0x38);
    if (iVar2 != 0) {
      prvCopyDataFromQueue(param_1,param_2);
      *(int *)(param_1 + 0x38) = iVar2 + -1;
      if ((*(int *)(param_1 + 0x10) != 0) &&
         (iVar2 = xTaskRemoveFromEventList(param_1 + 0x10), iVar2 != 0)) {
        vPortYield();
      }
      vPortExitCritical();
      return 1;
    }
    if (local_24 == 0) break;
    if (!bVar1) {
      vTaskInternalSetTimeOutState(&iStack_20);
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
    iVar2 = xTaskCheckForTimeOut(&iStack_20,&local_24);
    if (iVar2 == 0) {
      iVar2 = prvIsQueueEmpty(param_1);
      if (iVar2 == 0) {
        prvUnlockQueue(param_1);
        xTaskResumeAll();
      }
      else {
        vTaskPlaceOnEventList(param_1 + 0x24,local_24);
        prvUnlockQueue(param_1);
        iVar2 = xTaskResumeAll();
        if (iVar2 == 0) {
          vPortYield();
        }
      }
    }
    else {
      prvUnlockQueue(param_1);
      xTaskResumeAll();
      iVar2 = prvIsQueueEmpty(param_1);
      if (iVar2 != 0) {
        return 0;
      }
    }
    bVar1 = true;
  }
  vPortExitCritical();
  return 0;
}


// ===== xQueueSemaphoreTake @ 00086c14 (308 bytes)

undefined4 xQueueSemaphoreTake(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_24;
  undefined1 auStack_20 [12];
  
  local_24 = param_2;
  if (param_1 == (int *)0x0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_1[0x10] == 0) {
    iVar1 = xTaskGetSchedulerState();
    if ((iVar1 == 0) && (local_24 != 0)) {
      vPortRaiseBASEPRI();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar2 = 0;
    iVar1 = iVar2;
    while( true ) {
      vPortEnterCritical();
      if (param_1[0xe] != 0) {
        param_1[0xe] = param_1[0xe] + -1;
        if (*param_1 == 0) {
          iVar1 = pvTaskIncrementMutexHeldCount();
          param_1[2] = iVar1;
        }
        if ((param_1[4] != 0) && (iVar1 = xTaskRemoveFromEventList(param_1 + 4), iVar1 != 0)) {
          vPortYield();
        }
        vPortExitCritical();
        return 1;
      }
      if (local_24 == 0) break;
      if (iVar1 == 0) {
        vTaskInternalSetTimeOutState(auStack_20);
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
      iVar1 = xTaskCheckForTimeOut(auStack_20,&local_24);
      if (iVar1 == 0) {
        iVar1 = prvIsQueueEmpty(param_1);
        if (iVar1 == 0) {
          prvUnlockQueue(param_1);
          xTaskResumeAll();
        }
        else {
          if (*param_1 == 0) {
            vPortEnterCritical();
            iVar2 = xTaskPriorityInherit(param_1[2]);
            vPortExitCritical();
          }
          vTaskPlaceOnEventList(param_1 + 9,local_24);
          prvUnlockQueue(param_1);
          iVar1 = xTaskResumeAll();
          if (iVar1 == 0) {
            vPortYield();
          }
        }
      }
      else {
        prvUnlockQueue(param_1);
        xTaskResumeAll();
        iVar1 = prvIsQueueEmpty(param_1);
        if (iVar1 != 0) {
          if (iVar2 == 0) {
            return 0;
          }
          vPortEnterCritical();
          iVar1 = 0;
          if (param_1[9] != 0) {
            iVar1 = 5 - *(int *)param_1[0xc];
          }
          vTaskPriorityDisinheritAfterTimeout(param_1[2],iVar1);
          vPortExitCritical();
          return 0;
        }
      }
      iVar1 = 1;
    }
    if (iVar2 == 0) {
      vPortExitCritical();
      return 0;
    }
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortRaiseBASEPRI();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== xQueueReceiveFromISR @ 00086d48 (116 bytes)

undefined4 xQueueReceiveFromISR(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((param_2 == 0) && (*(int *)(param_1 + 0x40) != 0)) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = vPortRaiseBASEPRI();
  iVar3 = *(int *)(param_1 + 0x38);
  uVar4 = 0;
  if (iVar3 != 0) {
    cVar1 = *(char *)(param_1 + 0x44);
    prvCopyDataFromQueue(param_1,param_2);
    *(int *)(param_1 + 0x38) = iVar3 + -1;
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x10) != 0) &&
          (iVar3 = xTaskRemoveFromEventList(param_1 + 0x10), iVar3 != 0)) &&
         (param_3 != (undefined4 *)0x0)) {
        uVar4 = 1;
        *param_3 = 1;
        goto LAB_00086da6;
      }
    }
    else {
      *(char *)(param_1 + 0x44) = cVar1 + '\x01';
    }
    uVar4 = 1;
  }
LAB_00086da6:
  vPortClearBASEPRI(uVar2);
  return uVar4;
}


// ===== vQueueDelete @ 00086dbc (26 bytes)

/* [inference] */

void vQueueDelete(int param_1)

{
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vQueueUnregisterQueue();
  vPortFree(param_1);
  return;
}


// ===== vQueueWaitForMessageRestricted @ 00086dd6 (70 bytes)

/* [inference] */

void vQueueWaitForMessageRestricted(int param_1,undefined4 param_2,undefined4 param_3)

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
  undefined *puVar1;
  uint uVar2;
  
  if ((param_1 & 0x80008000) == 0) {
    puVar1 = &DAT_40001000;
  }
  else {
    puVar1 = &DAT_40021000;
  }
  if ((param_1 & 0xfff) != 0) {
    *(uint *)(puVar1 + (param_1 & 0xfff)) = (param_1 & 0x7fff) >> 0xc;
    uVar2 = (param_1 & 0xfffffff) >> 0x10;
    if ((int)param_1 < 0) {
      puVar1 = &DAT_40021000;
    }
    else {
      puVar1 = &DAT_40001000;
    }
    if (uVar2 != 0) {
      *(uint *)(puVar1 + uVar2) = (param_1 & 0x7fffffff) >> 0x1c;
    }
  }
  return;
}


// ===== CLOCK_SetClkDiv @ 00086e58 (52 bytes)

void CLOCK_SetClkDiv(uint param_1,int param_2)

{
  undefined *puVar1;
  uint *puVar2;
  
  if ((int)param_1 < 0) {
    puVar1 = &DAT_40021000;
  }
  else {
    puVar1 = &DAT_40001000;
  }
  puVar2 = (uint *)(puVar1 + (param_1 & 0xfff));
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
  
  uVar1 = DAT_40028000;
  DAT_40028000 = uVar1;
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
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram40029000;
  Ram40029000 = uVar1;
  if (cRam000a1ef1 == '\0') {
    if ((code *)*puRam00088938 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam00088938)(uVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & uVar1) != 0) && ((code *)puRam00088938[uVar2] != (code *)0x0)) {
        (*(code *)puRam00088938[uVar2])(uVar1);
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
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram4002a000;
  Ram4002a000 = uVar1;
  if (cRam000a1ef2 == '\0') {
    if ((code *)*puRam0008893c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam0008893c)(uVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & uVar1) != 0) && ((code *)puRam0008893c[uVar2] != (code *)0x0)) {
        (*(code *)puRam0008893c[uVar2])(uVar1);
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
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram4002b000;
  Ram4002b000 = uVar1;
  if (cRam000a1ef3 == '\0') {
    if ((code *)*puRam00088940 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam00088940)(uVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & uVar1) != 0) && ((code *)puRam00088940[uVar2] != (code *)0x0)) {
        (*(code *)puRam00088940[uVar2])(uVar1);
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
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram4002c000;
  Ram4002c000 = uVar1;
  if (cRam000a1ef4 == '\0') {
    if ((code *)*puRam00088944 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puRam00088944)(uVar1);
      return;
    }
  }
  else {
    uVar2 = 0;
    do {
      if (((1 << (uVar2 & 0xff) & uVar1) != 0) && ((code *)puRam00088944[uVar2] != (code *)0x0)) {
        (*(code *)puRam00088944[uVar2])(uVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 7);
  }
  return;
}


// ===== DSP_CopyImage @ 00086eaa (26 bytes)

void DSP_CopyImage(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)(param_1[1] + -4);
  puVar1 = (undefined4 *)(param_1[2] + (int)puVar3);
  for (; puVar3 != puVar1; puVar3 = puVar3 + 1) {
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar3;
  }
  return;
}


// ===== hashcrypt_get_digest @ 00086ec4 (44 bytes)

/* Reads 5 (SHA-1) or 8 words from HASHCRYPT DIGEST (0x40158040) into the context; only used by the
   HASHCRYPT IRQ handler [guess] */

void hashcrypt_get_digest(int param_1,int param_2)

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

void MU_SendMsg(int param_1,uint param_2,undefined4 param_3)

{
  do {
  } while ((*(uint *)(param_1 + 0x60) & 0x800000U >> (param_2 & 0xff)) == 0);
  *(undefined4 *)(param_1 + (param_2 + 8) * 4) = param_3;
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
    DAT_40000070 = uVar2;
    do {
      uVar1 = DAT_40000010;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 1:
    DAT_40000074 = uVar2;
    do {
      uVar1 = DAT_40000014;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 2:
    DAT_40000078 = uVar2;
    do {
      uVar1 = DAT_40000018;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 3:
    DAT_40020070 = uVar2;
    do {
      uVar1 = DAT_40020010;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 4:
    DAT_40020074 = uVar2;
    do {
      uVar1 = DAT_40020014;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 5:
    DAT_40020078 = uVar2;
    do {
      uVar1 = DAT_40020018;
    } while ((uVar2 & ~uVar1) == 0);
  }
  return;
}


// ===== SCTIMER_GetDefaultConfig @ 00086f64 (38 bytes)

void SCTIMER_GetDefaultConfig(undefined1 *param_1)

{
  memset(param_1,0,9);
  *param_1 = 1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0xf;
  return;
}


// ===== SCTIMER_UpdatePwmDutycycle @ 00086f8a (98 bytes)

void SCTIMER_UpdatePwmDutycycle(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  longlong lVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = param_1 + param_4 * 8;
  uVar6 = *(uint *)(iVar5 + 0x30c);
  uVar4 = *(uint *)(param_1 + ((*(uint *)(iVar5 + 0x304) & 0xf) + 0x40) * 4);
  if (param_3 == 100) {
    sVar2 = (short)uVar4;
    if (*(int *)(param_1 + 4) << 0x1b < 0) {
      uVar3 = sVar2 - 1;
    }
    else {
      uVar3 = sVar2 + 2;
    }
  }
  else {
    lVar1 = (ulonglong)param_3 * (ulonglong)uVar4;
    uVar3 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),100,0,param_4);
  }
  iVar5 = param_1 + (uVar6 & 0xf) * 4;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
  *(uint *)(iVar5 + 0x100) = (uint)uVar3;
  *(uint *)(iVar5 + 0x200) = (uint)uVar3;
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

void USART_GetDefaultConfig(undefined4 *param_1)

{
  memset(param_1,0,0x14);
  *param_1 = &DAT_0001c200;
  param_1[1] = 0x10000;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


// ===== USART_SetBaudRate @ 0008704e (178 bytes)

/* OSR/BRG search, returns 0x1651 kStatus_USART_BaudrateNotSupport [inference] */

undefined * USART_SetBaudRate(uint *param_1,uint param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (((param_1 == (uint *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    puVar1 = (undefined *)0x4;
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
      param_3 = param_3 / (uVar6 * (uVar4 + 1) + uVar4 + 1);
      if (param_2 < param_3) {
        param_3 = param_3 - param_2;
      }
      else {
        param_3 = param_2 - param_3;
      }
      if (((param_2 / 100) * 3 < param_3) || (0xffff < uVar4)) {
        return &DAT_00001651;
      }
      param_1[10] = uVar6;
      param_1[8] = uVar4;
    }
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}


// ===== USART_Init @ 00087100 (306 bytes)

undefined * USART_Init(uint *param_1,uint *param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  if (((param_1 == (uint *)0x0) || (param_2 == (uint *)0x0)) || (param_3 == 0)) {
    puVar2 = (undefined *)0x4;
  }
  else {
    puVar2 = (undefined *)FLEXCOMM_Init(param_1,1,param_3,param_4,param_4);
    if (puVar2 == (undefined *)0x0) {
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
        puVar3 = (undefined *)USART_SetBaudRate(param_1,uVar4,param_3);
        if (puVar3 != (undefined *)0x0) {
          return puVar3;
        }
      }
      else {
        if ((undefined *)((0x2580 / uVar4) * uVar4) != &DAT_00002580) {
          return &DAT_00001651;
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
  return puVar2;
}


// ===== BOARD_FlexspiClockSafeConfig @ 00087234 (8 bytes)

/* BOARD_SetFlexspiClock(3 = FFRO, /1) before the main clock switch [inference] */

void BOARD_FlexspiClockSafeConfig(void)

{
  BOARD_SetFlexspiClock(3,1);
  return;
}


// ===== BOARD_InitDebugConsole @ 00087240 (2 bytes)

/* Empty stub called from app_main right after BOARD_BootClockRUN [guess] */

void BOARD_InitDebugConsole(void)

{
  return;
}


// ===== BOARD_InitPins_flexcomm @ 00087242 (42 bytes)

/* IOPCTL: PIO0_1/2 FC0 USART, PIO0_7..10 FC1 SPI, PIO1_10 MCLK, PIO2_2 SCT0_OUT0, PIO2_30 CLKIN
   [fact] */

void BOARD_InitPins_flexcomm(void)

{
  DAT_40004004 = 1;
  DAT_40004028 = 1;
  DAT_40004008 = 0x41;
  DAT_4000401c = 0x41;
  DAT_40004020 = 0x41;
  DAT_40004024 = 0x41;
  DAT_400040a8 = 0x101;
  DAT_40004108 = 2;
  DAT_40004178 = 0x45;
  return;
}


// ===== BOARD_InitPins_i2s @ 0008726c (40 bytes)

/* IOPCTL: PIO0_14..16 FC2 (SCK input inverted), PIO0_23 FC3 data in, PIO0_30 FC4 data in, PIO1_3..5
   FC5 [fact] */

void BOARD_InitPins_i2s(void)

{
  DAT_40004038 = 0x941;
  DAT_4000403c = 0x141;
  DAT_40004040 = 0x101;
  DAT_4000405c = 0x141;
  DAT_40004078 = 0x141;
  DAT_4000408c = 0x141;
  DAT_40004090 = 0x141;
  DAT_40004094 = 0x101;
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
  uint uVar3;
  
  uVar3 = ((uint)param_1 | (uint)param_2) & 3;
  puVar1 = param_1;
  puVar2 = param_2;
  for (; uVar3 == 0; uVar3 = uVar3 + 0xfefefeff & ~uVar3 & 0x80808080) {
    uVar3 = *param_2;
    puVar1 = param_1;
    puVar2 = param_2;
    if (uVar3 != *param_1) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  do {
    uVar3 = (uint)(byte)*puVar1;
    if (uVar3 != (byte)*puVar2) {
      return uVar3 - (byte)*puVar2;
    }
    puVar1 = (uint *)((int)puVar1 + 1);
    puVar2 = (uint *)((int)puVar2 + 1);
  } while (uVar3 != 0);
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
  return (int)puVar2 - (int)((int)param_1 + 1);
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
  pcVar2 = (char *)((int)param_2 - 1);
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


// ===== _Cflush_read @ 00087470 (64 bytes)

/* [guess] */

void _Cflush_read(undefined4 *param_1)

{
  param_1[3] = param_1[3] & 0xffffffdf;
  if (param_1[6] != param_1[10]) {
    _Cflush_write();
    param_1[3] = param_1[3] & 0xffffcfef | 0x10;
    param_1[6] = param_1[10];
    param_1[0xb] = param_1[4];
    *param_1 = param_1[4];
  }
  param_1[3] = param_1[3] & 0xffffbfbf;
  return;
}

