// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== vPortSVCHandler_C @ 0008657c (56 bytes)

void vPortSVCHandler_C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  undefined4 *puVar3;
  
  if (*(char *)(*(int *)(param_1 + 0x18) + -2) == '\x02') {
    puVar3 = (undefined4 *)*DAT_00088800;
    setProcStackPointerLimit(*puVar3);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setThreadModePrivileged(1);
      bVar1 = (bool)isThreadMode();
      if (bVar1) {
        cVar2 = isUsingMainStack();
        setStackMode(cVar2 == '\x01');
      }
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setProcessStackPointer(puVar3 + 10);
    }
    InstructionSynchronizationBarrier(0xf);
                    /* WARNING: Could not recover jumptable at 0x00080a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)puVar3[1])(puVar3 + 10,2,(code *)puVar3[1],param_4);
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
    FUN_00086716(puVar1 + 1);
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
  iVar1 = FUN_00082910();
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
      FUN_00082728(param_1 + 1,uVar2 | param_2,param_5);
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
    FUN_00086542();
  }
  uVar2 = FUN_00082ab0();
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


// ===== FUN_000866a4 @ 000866a4 (110 bytes)

uint FUN_000866a4(uint *param_1,uint param_2)

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
    FUN_00082818(puVar1,uVar2 | 0x2000000);
  }
  goto LAB_000866d0;
}


// ===== FUN_00086716 @ 00086716 (22 bytes)

void FUN_00086716(undefined4 *param_1)

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


// ===== FUN_0008672c @ 0008672c (6 bytes)

void FUN_0008672c(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ===== FUN_00086732 @ 00086732 (24 bytes)

void FUN_00086732(int *param_1,int param_2)

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


// ===== FUN_0008674a @ 0008674a (46 bytes)

void FUN_0008674a(int *param_1,uint *param_2)

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


// ===== FUN_00086778 @ 00086778 (32 bytes)

int FUN_00086778(int param_1)

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


// ===== FUN_00086798 @ 00086798 (22 bytes)

bool FUN_00086798(int param_1)

{
  int iVar1;
  
  vPortEnterCritical();
  iVar1 = *(int *)(param_1 + 0x38);
  vPortExitCritical();
  return iVar1 == 0;
}


// ===== FUN_000867ae @ 000867ae (106 bytes)

undefined4 FUN_000867ae(uint *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1[0xe];
  if (param_1[0x10] == 0) {
    if (*param_1 == 0) {
      uVar1 = FUN_000829b4(param_1[2]);
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


// ===== FUN_00086818 @ 00086818 (44 bytes)

void FUN_00086818(uint *param_1,undefined4 param_2)

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


// ===== FUN_00086844 @ 00086844 (112 bytes)

void FUN_00086844(int param_1)

{
  char cVar1;
  int iVar2;
  
  vPortEnterCritical();
  cVar1 = *(char *)(param_1 + 0x45);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x24) != 0))) {
    iVar2 = FUN_0008279c(param_1 + 0x24);
    if (iVar2 != 0) {
      FUN_00082904();
    }
    cVar1 = cVar1 + -1;
  }
  *(undefined1 *)(param_1 + 0x45) = 0xff;
  vPortExitCritical();
  vPortEnterCritical();
  cVar1 = *(char *)(param_1 + 0x44);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x10) != 0))) {
    iVar2 = FUN_0008279c(param_1 + 0x10);
    if (iVar2 != 0) {
      FUN_00082904();
    }
    cVar1 = cVar1 + -1;
  }
  *(undefined1 *)(param_1 + 0x44) = 0xff;
  vPortExitCritical();
  return;
}


// ===== FUN_000868b4 @ 000868b4 (98 bytes)

undefined4 FUN_000868b4(int *param_1,int param_2)

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
    if ((param_1[4] != 0) && (iVar1 = FUN_0008279c(param_1 + 4), iVar1 != 0)) {
      FUN_00086542();
    }
  }
  else {
    FUN_00086716(param_1 + 4);
    FUN_00086716(param_1 + 9);
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
      FUN_000868b4(piVar1,1);
      *(undefined1 *)(piVar1 + 0x13) = param_3;
    }
    return (int)piVar1;
  }
  vPortRaiseBASEPRI();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_00086952 @ 00086952 (36 bytes)

void FUN_00086952(uint param_1,uint param_2)

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
  iVar2 = FUN_00082910();
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
      iVar2 = FUN_000867ae(param_1,param_2,param_4);
      if (*(int *)(param_1 + 0x24) != 0) {
        iVar2 = FUN_0008279c(param_1 + 0x24);
      }
      if (iVar2 != 0) {
        FUN_00086542();
      }
      vPortExitCritical();
      return 1;
    }
    if (local_2c == 0) {
      vPortExitCritical();
      return 0;
    }
    if (!bVar1) {
      FUN_0008288c(auStack_28);
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
    iVar2 = FUN_000828a4(auStack_28,&local_2c);
    if (iVar2 != 0) break;
    vPortEnterCritical();
    if (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x3c)) {
      vPortExitCritical();
      FUN_00082700(param_1 + 0x10,local_2c);
      FUN_00086844(param_1);
      iVar2 = xTaskResumeAll();
      if (iVar2 == 0) {
        FUN_00086542();
      }
    }
    else {
      vPortExitCritical();
      FUN_00086844(param_1);
      xTaskResumeAll();
    }
    bVar1 = true;
  }
  FUN_00086844(param_1);
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
    FUN_000867ae(param_1,param_2,param_4,*(undefined4 *)(param_1 + 0x38));
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x24) != 0) && (iVar3 = FUN_0008279c(param_1 + 0x24), iVar3 != 0)) &&
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
  iVar2 = FUN_00082910();
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
      FUN_00086818(param_1,param_2);
      *(int *)(param_1 + 0x38) = iVar2 + -1;
      if ((*(int *)(param_1 + 0x10) != 0) && (iVar2 = FUN_0008279c(param_1 + 0x10), iVar2 != 0)) {
        FUN_00086542();
      }
      vPortExitCritical();
      return 1;
    }
    if (local_24 == 0) break;
    if (!bVar1) {
      FUN_0008288c(&iStack_20);
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
    iVar2 = FUN_000828a4(&iStack_20,&local_24);
    if (iVar2 == 0) {
      iVar2 = FUN_00086798(param_1);
      if (iVar2 == 0) {
        FUN_00086844(param_1);
        xTaskResumeAll();
      }
      else {
        FUN_00082700(param_1 + 0x24,local_24);
        FUN_00086844(param_1);
        iVar2 = xTaskResumeAll();
        if (iVar2 == 0) {
          FUN_00086542();
        }
      }
    }
    else {
      FUN_00086844(param_1);
      xTaskResumeAll();
      iVar2 = FUN_00086798(param_1);
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
    iVar1 = FUN_00082910();
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
          iVar1 = FUN_00082ac8();
          param_1[2] = iVar1;
        }
        if ((param_1[4] != 0) && (iVar1 = FUN_0008279c(param_1 + 4), iVar1 != 0)) {
          FUN_00086542();
        }
        vPortExitCritical();
        return 1;
      }
      if (local_24 == 0) break;
      if (iVar1 == 0) {
        FUN_0008288c(auStack_20);
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
      iVar1 = FUN_000828a4(auStack_20,&local_24);
      if (iVar1 == 0) {
        iVar1 = FUN_00086798(param_1);
        if (iVar1 == 0) {
          FUN_00086844(param_1);
          xTaskResumeAll();
        }
        else {
          if (*param_1 == 0) {
            vPortEnterCritical();
            iVar2 = FUN_00082930(param_1[2]);
            vPortExitCritical();
          }
          FUN_00082700(param_1 + 9,local_24);
          FUN_00086844(param_1);
          iVar1 = xTaskResumeAll();
          if (iVar1 == 0) {
            FUN_00086542();
          }
        }
      }
      else {
        FUN_00086844(param_1);
        xTaskResumeAll();
        iVar1 = FUN_00086798(param_1);
        if (iVar1 != 0) {
          if (iVar2 == 0) {
            return 0;
          }
          vPortEnterCritical();
          iVar1 = 0;
          if (param_1[9] != 0) {
            iVar1 = 5 - *(int *)param_1[0xc];
          }
          FUN_00082a24(param_1[2],iVar1);
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
    FUN_00086818(param_1,param_2);
    *(int *)(param_1 + 0x38) = iVar3 + -1;
    if (cVar1 == -1) {
      if (((*(int *)(param_1 + 0x10) != 0) && (iVar3 = FUN_0008279c(param_1 + 0x10), iVar3 != 0)) &&
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


// ===== FUN_00086dbc @ 00086dbc (26 bytes)

void FUN_00086dbc(int param_1)

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


// ===== FUN_00086dd6 @ 00086dd6 (70 bytes)

void FUN_00086dd6(int param_1,undefined4 param_2,undefined4 param_3)

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
    FUN_00082768(param_1 + 0x24,param_2,param_3);
  }
  FUN_00086844(param_1);
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


// ===== FUN_00086ec4 @ 00086ec4 (44 bytes)

void FUN_00086ec4(int param_1,int param_2)

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


// ===== FUN_00086efe @ 00086efe (22 bytes)

void FUN_00086efe(int param_1,uint param_2,undefined4 param_3)

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


// ===== FUN_00086f2e @ 00086f2e (14 bytes)

void FUN_00086f2e(int param_1)

{
  if (*(uint *)(param_1 + 0x28) >> 0x18 != 0) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  }
  return;
}


// ===== RESET_ClearPeripheralReset @ 00086f52 (18 bytes)

void RESET_ClearPeripheralReset(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  FUN_00084498();
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
    uVar3 = FUN_00087756((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),100,0,param_4);
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


// ===== FUN_0008704e @ 0008704e (178 bytes)

undefined * FUN_0008704e(uint *param_1,uint param_2,uint param_3)

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
    puVar2 = (undefined *)FUN_00083ebc(param_1,1,param_3,param_4,param_4);
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
        puVar3 = (undefined *)FUN_0008704e(param_1,uVar4,param_3);
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


// ===== FUN_00087234 @ 00087234 (8 bytes)

void FUN_00087234(void)

{
  CLOCK_SetDiv_0x620(3,1);
  return;
}


// ===== FUN_00087240 @ 00087240 (2 bytes)

void FUN_00087240(void)

{
  return;
}


// ===== FUN_00087242 @ 00087242 (42 bytes)

void FUN_00087242(void)

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


// ===== FUN_0008726c @ 0008726c (40 bytes)

void FUN_0008726c(void)

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


// ===== BOARD_InitPins @ 00087294 (190 bytes)

void BOARD_InitPins(void)

{
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_14;
  undefined1 local_13;
  
  FUN_00087242();
  BOARD_InitPins_P0();
  BOARD_InitPins_codec_spi();
  FUN_0008726c();
  DAT_40021044 = 1;
  DAT_40021044 = 4;
  local_28 = 1;
  local_27 = 0;
  GPIO_PinInit(&DAT_40100000,0,0x1c,&local_28);
  local_24 = 1;
  local_23 = 0;
  GPIO_PinInit(&DAT_40100000,0,0x1d,&local_24);
  local_20 = 1;
  local_1f = 0;
  GPIO_PinInit(&DAT_40100000,0,0x1f,&local_20);
  local_1c = 1;
  local_1b = 0;
  GPIO_PinInit(&DAT_40100000,2,4,&local_1c);
  local_18 = 1;
  local_17 = 0;
  GPIO_PinInit(&DAT_40100000,2,5,&local_18);
  local_14 = 1;
  local_13 = 0;
  GPIO_PinInit(&DAT_40100000,2,6,&local_14);
  DAT_40004070 = 0;
  DAT_40004074 = 0;
  DAT_4000407c = 0;
  DAT_40004110 = 0;
  DAT_40004114 = 0;
  DAT_40004118 = 0;
  return;
}


// ===== main @ 000872ae (14 bytes)

void main(void)

{
  stdio_init();
  app_main();
  return;
}


// ===== FUN_000872c4 @ 000872c4 (48 bytes)

void FUN_000872c4(int param_1)

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


// ===== FUN_000872f8 @ 000872f8 (62 bytes)

undefined4 FUN_000872f8(int *param_1,int *param_2,uint param_3,int param_4)

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

