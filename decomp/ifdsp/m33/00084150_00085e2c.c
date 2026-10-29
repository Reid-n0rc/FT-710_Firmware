// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== CLOCK_EnableClock @ 00084150 (86 bytes)

/* PSCCTLn_SET from (reg << 8 | bit) [inference] */

void CLOCK_EnableClock(uint param_1)

{
  undefined *puVar1;
  
  switch(param_1 >> 8) {
  case 0:
    puVar1 = &DAT_40001000;
    goto LAB_00084168;
  case 1:
    puVar1 = &DAT_40001000;
    goto LAB_00084176;
  case 2:
    puVar1 = &DAT_40001000;
    break;
  case 3:
    puVar1 = &DAT_40021000;
LAB_00084168:
    *(int *)(puVar1 + 0x40) = 1 << (param_1 & 0xff);
    return;
  case 4:
    puVar1 = &DAT_40021000;
LAB_00084176:
    *(int *)(puVar1 + 0x44) = 1 << (param_1 & 0xff);
    return;
  case 5:
    puVar1 = &DAT_40021000;
    break;
  default:
    goto switchD_00084156_default;
  }
  *(int *)(puVar1 + 0x48) = 1 << (param_1 & 0xff);
switchD_00084156_default:
  return;
}


// ===== GPIO_PortInit @ 000841b4 (26 bytes)

void GPIO_PortInit(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r1;
  undefined4 extraout_r2;
  
  CLOCK_EnableClock(*(undefined2 *)(&DAT_00087b3c + param_2 * 2));
  RESET_ClearPeripheralReset
            (*(undefined2 *)(&DAT_00087b3c + extraout_r1 * 2),extraout_r1,extraout_r2,param_4);
  return;
}


// ===== GPIO_PinInit @ 000841d8 (74 bytes)

void GPIO_PinInit(int param_1,int param_2,uint param_3,char *param_4)

{
  int extraout_r1;
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  CLOCK_EnableClock(*(undefined2 *)(&DAT_00087b3c + param_2 * 2));
  uVar2 = 1 << (param_3 & 0xff);
  if (*param_4 == '\0') {
    puVar3 = (uint *)(param_1 + extraout_r1 * 4 + 0x2000);
    uVar2 = *puVar3 & ~uVar2;
  }
  else {
    if (param_4[1] == '\0') {
      iVar1 = extraout_r1 + 0x8a0;
    }
    else {
      iVar1 = extraout_r1 + 0x880;
    }
    *(uint *)(param_1 + iVar1 * 4) = uVar2;
    puVar3 = (uint *)(param_1 + extraout_r1 * 4 + 0x2000);
    uVar2 = uVar2 | *puVar3;
  }
  *puVar3 = uVar2;
  return;
}


// ===== HASHCRYPT_DriverIRQHandler @ 00084228 (80 bytes)

/* IRQ59, base 0x40158000 [fact: vector] */

void HASHCRYPT_DriverIRQHandler(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = DAT_00088ab0;
  iVar1 = DAT_40158004;
  if (iVar1 << 0x1d < 0) {
    uVar3 = 1;
  }
  else {
    uVar5 = *(uint *)(DAT_00088ab0 + 0x4c);
    if (uVar5 != 0) {
      uVar4 = 0x7ff;
      if (uVar5 < 0x800) {
        uVar4 = uVar5;
      }
      *(uint *)(DAT_00088ab0 + 0x4c) = uVar5 - uVar4;
      DAT_40158010 = uVar4 << 0x10 | 1;
      return;
    }
    DAT_4015800c = 6;
    DAT_40158010 = 0;
    hashcrypt_get_digest(&DAT_40158000,DAT_00088ab0);
    uVar3 = 0;
  }
  if (*(code **)(iVar2 + 0x50) == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00084272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x50))(&DAT_40158000,iVar2,uVar3,*(undefined4 *)(iVar2 + 0x54));
  return;
}


// ===== I3C0_DriverIRQHandler @ 00084280 (52 bytes)

/* IRQ49, base 0x40036000 [fact: vector] */

void I3C0_DriverIRQHandler(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_40036000;
  if (((uVar1 & 3) == 1) && (DAT_00088ab8 != (code *)0x0)) {
    (*DAT_00088ab8)(&DAT_40036000,DAT_00088ab4);
  }
  iVar2 = DAT_40036004;
  if ((iVar2 << 0x1f < 0) && (DAT_00088ac0 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000842b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_00088ac0)(&DAT_40036000,DAT_00088abc);
    return;
  }
  return;
}


// ===== MU_Init @ 000842c8 (10 bytes)

void MU_Init(void)

{
  DAT_40021044 = 0x10000000;
  return;
}


// ===== OS_EVENT_DriverIRQHandler @ 000842d8 (12 bytes)

/* IRQ41, OSTIMER 0x40113000 [fact: vector] */

void OS_EVENT_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x000842e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088ac8)(&UNK_40113000,DAT_00088ac4);
  return;
}


// ===== PIN_INT0_DriverIRQHandler @ 000842f0 (40 bytes)

/* IRQ4, PINT 0x40025000 [fact: vector] */

void PIN_INT0_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  if (DAT_00088acc != (code *)0x0) {
    (*DAT_00088acc)(0,uVar2);
  }
  uVar1 = DAT_40025000;
  if ((uVar1 & 1) == 0) {
    PINT_PinInterruptClrStatus();
    return;
  }
  return;
}


// ===== PIN_INT1_DriverIRQHandler @ 00084320 (40 bytes)

/* IRQ5 [fact: vector] */

void PIN_INT1_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 in_r3;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  uVar3 = extraout_r2;
  if (DAT_00088ad0 != (code *)0x0) {
    (*DAT_00088ad0)(1,uVar2);
    uVar3 = extraout_r2_00;
  }
  iVar1 = DAT_40025000;
  if (-1 < iVar1 << 0x1e) {
    PINT_PinInterruptClrStatus(&DAT_40025000,1,uVar3,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT2_DriverIRQHandler @ 00084350 (40 bytes)

/* IRQ6 [fact: vector] */

void PIN_INT2_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 in_r3;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  uVar3 = extraout_r2;
  if (DAT_00088ad4 != (code *)0x0) {
    (*DAT_00088ad4)(2,uVar2);
    uVar3 = extraout_r2_00;
  }
  iVar1 = DAT_40025000;
  if (-1 < iVar1 << 0x1d) {
    PINT_PinInterruptClrStatus(&DAT_40025000,2,uVar3,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT3_DriverIRQHandler @ 00084380 (40 bytes)

/* IRQ7 [fact: vector] */

void PIN_INT3_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 in_r3;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  uVar3 = extraout_r2;
  if (DAT_00088ad8 != (code *)0x0) {
    (*DAT_00088ad8)(3,uVar2);
    uVar3 = extraout_r2_00;
  }
  iVar1 = DAT_40025000;
  if (-1 < iVar1 << 0x1c) {
    PINT_PinInterruptClrStatus(&DAT_40025000,3,uVar3,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT4_DriverIRQHandler @ 000843b0 (40 bytes)

/* IRQ35 [fact: vector] */

void PIN_INT4_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 in_r3;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  uVar3 = extraout_r2;
  if (DAT_00088adc != (code *)0x0) {
    (*DAT_00088adc)(4,uVar2);
    uVar3 = extraout_r2_00;
  }
  iVar1 = DAT_40025000;
  if (-1 < iVar1 << 0x1b) {
    PINT_PinInterruptClrStatus(&DAT_40025000,4,uVar3,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT5_DriverIRQHandler @ 000843e0 (40 bytes)

/* IRQ36 [fact: vector] */

void PIN_INT5_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 in_r3;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  uVar3 = extraout_r2;
  if (DAT_00088ae0 != (code *)0x0) {
    (*DAT_00088ae0)(5,uVar2);
    uVar3 = extraout_r2_00;
  }
  iVar1 = DAT_40025000;
  if (-1 < iVar1 << 0x1a) {
    PINT_PinInterruptClrStatus(&DAT_40025000,5,uVar3,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT6_DriverIRQHandler @ 00084410 (40 bytes)

/* IRQ37 [fact: vector] */

void PIN_INT6_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 in_r3;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  uVar3 = extraout_r2;
  if (DAT_00088ae4 != (code *)0x0) {
    (*DAT_00088ae4)(6,uVar2);
    uVar3 = extraout_r2_00;
  }
  iVar1 = DAT_40025000;
  if (-1 < iVar1 << 0x19) {
    PINT_PinInterruptClrStatus(&DAT_40025000,6,uVar3,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT7_DriverIRQHandler @ 00084440 (40 bytes)

/* IRQ38 [fact: vector] */

void PIN_INT7_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 in_r3;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&DAT_40025000);
  uVar3 = extraout_r2;
  if (DAT_00088ae8 != (code *)0x0) {
    (*DAT_00088ae8)(7,uVar2);
    uVar3 = extraout_r2_00;
  }
  iVar1 = DAT_40025000;
  if (-1 < iVar1 << 0x18) {
    PINT_PinInterruptClrStatus(&DAT_40025000,7,uVar3,in_r3);
    return;
  }
  return;
}


// ===== POWER_ApplyPD @ 00084470 (24 bytes)

/* Wait PMC STATUS busy, PMC CTRL |= APPLYCFG, wait [inference] */

void POWER_ApplyPD(void)

{
  int iVar1;
  uint uVar2;
  
  do {
    iVar1 = DAT_40135004;
  } while (iVar1 << 0x1f < 0);
  uVar2 = DAT_4013500c;
  DAT_4013500c = uVar2 | 1;
  do {
    iVar1 = DAT_40135004;
  } while (iVar1 << 0x1f < 0);
  return;
}


// ===== POWER_UpdateOscSettlingTime @ 0008448c (6 bytes)

/* Stores osc settling time (us) at 0x80A58, read by POWER_EnterDeepSleep [inference] */

void POWER_UpdateOscSettlingTime(undefined4 param_1)

{
  DAT_00080a58 = param_1;
  return;
}


// ===== RESET_SetPeripheralReset @ 00084498 (96 bytes)

/* PRSTCTLn_SET and wait [inference] */

void RESET_SetPeripheralReset(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_1 & 0xff);
  switch(param_1 >> 8) {
  case 0:
    DAT_40000040 = uVar2;
    do {
      uVar1 = DAT_40000010;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 1:
    DAT_40000044 = uVar2;
    do {
      uVar1 = DAT_40000014;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 2:
    DAT_40000048 = uVar2;
    do {
      uVar1 = DAT_40000018;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 3:
    DAT_40020040 = uVar2;
    do {
      uVar1 = DAT_40020010;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 4:
    DAT_40020044 = uVar2;
    do {
      uVar1 = DAT_40020014;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 5:
    DAT_40020048 = uVar2;
    do {
      uVar1 = DAT_40020018;
    } while ((uVar1 & uVar2) == 0);
  }
  return;
}


// ===== SCTIMER_Init @ 000845b4 (154 bytes)

undefined4 SCTIMER_Init(uint *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  DAT_40001040 = 0x1000000;
  RESET_ClearPeripheralReset(0x18);
  bVar1 = *param_2;
  *param_1 = (param_2[2] & 0xf) << 3 | (param_2[1] & 3) << 1 | (uint)bVar1 | (param_2[8] & 0xf) << 9
  ;
  param_1[1] = (uint)param_2[5] << 5 | (uint)param_2[3] << 4 | 4;
  param_1[1] = param_1[1] | 8;
  if (bVar1 == 0) {
    param_1[1] = (uint)param_2[6] << 0x15 | (uint)param_2[4] << 0x14 | param_1[1] | 0x40000;
    param_1[1] = param_1[1] | 0x80000;
  }
  param_1[0x14] = (uint)param_2[7];
  iVar3 = 0;
  DAT_00088aec = 0;
  DAT_00088af8 = 0;
  DAT_00088af0 = 0;
  DAT_00088af4 = 0;
  puVar2 = &DAT_00088afc;
  do {
    iVar3 = iVar3 + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0x10);
  DAT_00088b3c = &LAB_0008457c_1;
  return 0;
}


// ===== SCTIMER_CreateAndScheduleEvent @ 00084670 (250 bytes)

/* Used by SCTIMER_SetupPwm; s_currentEvent/Match at 0x88AEC.. [inference] */

undefined1
SCTIMER_CreateAndScheduleEvent
          (int *param_1,uint param_2,int param_3,uint param_4,char param_5,uint *param_6)

{
  undefined2 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = DAT_00088af4;
  uVar4 = DAT_00088af0;
  if (0xf < DAT_00088aec) {
    return 1;
  }
  uVar5 = (param_2 & 0x3fff) >> 0xc;
  if (uVar5 == 2) {
    param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | (param_4 & 0xf) << 6;
  }
  else {
    if ((uVar5 == 0) || (uVar5 == 3)) {
      param_2 = param_2 | (param_4 & 0xf) << 6;
    }
    uVar1 = (undefined2)param_3;
    if (param_5 == '\x01') {
      if (*param_1 << 0x1f < 0) {
        return 1;
      }
      if (0xf < DAT_00088af0) {
        return 1;
      }
      *(undefined2 *)(param_1 + DAT_00088af0 + 0x40) = uVar1;
      *(undefined2 *)(param_1 + DAT_00088af0 + 0x80) = uVar1;
      param_2 = param_2 | DAT_00088af0;
      DAT_00088af0 = DAT_00088af0 + 1;
      param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2;
    }
    else {
      if (param_5 == '\x02') {
        if ((*param_1 << 0x1f < 0) || (piVar3 = (int *)&DAT_00088af4, 0xf < DAT_00088af4)) {
          return 1;
        }
        param_2 = DAT_00088af4 | param_2;
        *(undefined2 *)((int)param_1 + DAT_00088af4 * 4 + 0x102) = uVar1;
        *(undefined2 *)((int)param_1 + uVar2 * 4 + 0x202) = uVar1;
        param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | 0x10;
        uVar4 = uVar2;
      }
      else {
        if (param_5 != '\x04') {
          return 1;
        }
        if (-1 < *param_1 << 0x1f) {
          return 1;
        }
        piVar3 = (int *)&DAT_00088af0;
        if (0xf < DAT_00088af0) {
          return 1;
        }
        param_1[DAT_00088af0 + 0x40] = param_3;
        param_1[uVar4 + 0x80] = param_3;
        param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | uVar4;
      }
      *piVar3 = uVar4 + 1;
    }
  }
  param_1[(DAT_00088aec + 0x60) * 2] = 1 << (DAT_00088af8 & 0xff);
  *param_6 = DAT_00088aec;
  DAT_00088aec = DAT_00088aec + 1;
  return 0;
}


// ===== SCTIMER_SetupPwm @ 0008477c (344 bytes)

undefined4
SCTIMER_SetupPwm(int param_1,byte *param_2,int param_3,uint param_4,uint param_5,uint *param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_28;
  uint local_24 [2];
  
  local_28 = 0;
  local_24[0] = 0;
  if (0x10 < DAT_00088aec + 2U) {
    return 1;
  }
  param_5 = param_5 / (((*(uint *)(param_1 + 4) & 0x1fff) >> 5) + 1);
  if (param_3 == 1) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
  }
  else if (param_3 == 0) {
    param_5 = param_5 / param_4 - 1;
    goto LAB_000847cc;
  }
  param_5 = param_5 / (param_4 << 1);
LAB_000847cc:
  if (param_2[2] < 100) {
    lVar1 = (ulonglong)(uint)param_2[2] * (ulonglong)param_5;
    iVar2 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),100,0);
  }
  else if (param_3 == 0) {
    iVar2 = param_5 + 2;
  }
  else {
    iVar2 = param_5 - 1;
  }
  iVar3 = SCTIMER_CreateAndScheduleEvent(param_1,0x1000,param_5,0,4,&local_28);
  iVar2 = SCTIMER_CreateAndScheduleEvent(param_1,0x1000,iVar2,0,4,local_24);
  if (iVar2 != 0 || iVar3 != 0) {
    return 1;
  }
  uVar6 = 1 << (local_28 & 0xff);
  *(uint *)(param_1 + 8) = uVar6 & 0xffff | *(uint *)(param_1 + 8);
  *param_6 = local_28;
  uVar4 = (uint)*param_2;
  uVar5 = 1 << (local_24[0] & 0xff);
  if (param_2[1] == 1) {
    iVar2 = uVar4 * 8 + param_1;
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & ~(1 << uVar4);
    if (param_3 == 0) {
      *(uint *)(iVar2 + 0x500) = uVar6 | *(uint *)(iVar2 + 0x500);
      *(uint *)(iVar2 + 0x504) = uVar5 | *(uint *)(iVar2 + 0x504);
      return 0;
    }
    *(uint *)(iVar2 + 0x504) = uVar5 | *(uint *)(iVar2 + 0x504);
    uVar4 = 1 << (uVar4 << 1 & 0xff) | *(uint *)(param_1 + 0x54) & ~(3 << (uVar4 << 1 & 0xff));
  }
  else {
    iVar2 = uVar4 * 8 + param_1;
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 1 << uVar4;
    if (param_3 == 0) {
      *(uint *)(iVar2 + 0x504) = uVar6 | *(uint *)(iVar2 + 0x504);
      *(uint *)(iVar2 + 0x500) = uVar5 | *(uint *)(iVar2 + 0x500);
      return 0;
    }
    *(uint *)(iVar2 + 0x500) = uVar5 | *(uint *)(iVar2 + 0x500);
    uVar4 = 1 << (uVar4 << 1 & 0xff) | *(uint *)(param_1 + 0x54) & ~(3 << (uVar4 << 1 & 0xff));
  }
  *(uint *)(param_1 + 0x54) = uVar4;
  return 0;
}


// ===== SCTIMER_SetCallback @ 000848d8 (8 bytes)

void SCTIMER_SetCallback(undefined4 param_1,undefined4 param_2,int param_3)

{
  (&DAT_00088afc)[param_3] = param_2;
  return;
}


// ===== SCT0_DriverIRQHandler @ 000848e4 (8 bytes)

/* IRQ12: calls the callback at 0x88B3C with SCT0 (sct0_pwm_callback); the only active one of these
   [fact] */

void SCT0_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x000848ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b3c)(&DAT_40146000);
  return;
}


// ===== SEMA42_Init @ 000848f4 (10 bytes)

void SEMA42_Init(void)

{
  DAT_40021044 = 0x20000000;
  return;
}


// ===== USDHC0_DriverIRQHandler @ 00084904 (12 bytes)

/* IRQ45 [fact: vector] */

void USDHC0_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x0008490e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b48)(&UNK_40136000,DAT_00088b40);
  return;
}


// ===== USDHC1_DriverIRQHandler @ 0008491c (12 bytes)

/* IRQ46 [fact: vector] */

void USDHC1_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x00084926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b48)(&UNK_40137000,DAT_00088b44);
  return;
}


// ===== UTICK0_DriverIRQHandler @ 00084934 (12 bytes)

/* IRQ8 [fact: vector] */

void UTICK0_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x0008493e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b50)(&UNK_4000f000,DAT_00088b4c);
  return;
}


// ===== BOARD_BootClockRUN @ 0008494c (204 bytes)

void BOARD_BootClockRUN(void)

{
  uint uVar1;
  
  DAT_40002630 = 0x4000;
  DAT_40002630 = 0x10000;
  CLOCK_EnableFfroClk(0);
  DAT_40002630 = 0x8000;
  CLOCK_EnableSfroClk();
  BOARD_FlexspiClockSafeConfig();
  CLOCK_AttachClk(0x4343430);
  DAT_40002630 = 0x2000;
  POWER_UpdateOscSettlingTime(0x104);
  CLOCK_EnableSysOscClk(1,1,0x104);
  DAT_00088930 = 24000000;
  DAT_00088928 = 0x1194000;
  DAT_40001168 = 1;
  CLOCK_InitSysPll(&DAT_00087a08);
  CLOCK_InitSysPfd(0,0xc);
  CLOCK_InitSysPfd(2,0x18);
  CLOCK_InitAudioPll(&DAT_000879f8);
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 | 1;
  CLOCK_InitAudioPfd(0,0x1a);
  CLOCK_SetClkDiv(0x400,3);
  CLOCK_AttachClk(&DAT_00002434);
  CLOCK_SetClkDiv(0x80000240,1);
  CLOCK_SetClkDiv(0x500,2);
  CLOCK_SetClkDiv(0x800006fc,0xc);
  BOARD_SetFlexspiClock(1,6);
  DAT_00087ec0 = 198000000;
  return;
}


// ===== ipc_init @ 00084a50 (46 bytes)

void ipc_init(void)

{
  DAT_00088b60 = rpmsg_lite_master_init(&DAT_20020000,0x20000,0);
  DAT_00088b5c = rpmsg_queue_create();
  DAT_00088b58 = rpmsg_lite_create_ept(DAT_00088b60,0x28,0x861b9,DAT_00088b5c);
  DAT_00088b54 = 0x1e;
  return;
}


// ===== ipc_send @ 00084a8c (30 bytes)

void ipc_send(undefined4 param_1)

{
  rpmsg_lite_send(DAT_00088b60,DAT_00088b58,DAT_00088b54,param_1,0x98,0xffffffff);
  return;
}


// ===== ipc_recv @ 00084ab0 (34 bytes)

void ipc_recv(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  rpmsg_queue_recv(DAT_00088b60,DAT_00088b5c,&DAT_00088b54,param_1,0x98,0,0xffffffff,param_4);
  return;
}


// ===== BOARD_DSP_Init @ 00084ad8 (114 bytes)

void BOARD_DSP_Init(void)

{
  undefined **local_2c;
  undefined *local_28;
  dword local_24;
  undefined *local_20;
  undefined4 local_1c;
  dword local_18;
  undefined *local_14;
  undefined *local_10;
  dword local_c;
  
  local_28 = &DAT_24000000;
  local_1c = 0x200000;
  local_10 = &DAT_20040000;
  local_2c = &dsp_image0_tcm;
  local_24 = 0x20644;
  local_20 = &dsp_image1_sram_text;
  local_18 = 0x383b4;
  local_14 = &dsp_image2_sram_data;
  local_c = 0x31e0;
  CLOCK_InitSysPfd(1,0xc);
  CLOCK_AttachClk(0x80002434);
  CLOCK_SetClkDiv(0x80000400,1);
  CLOCK_SetClkDiv(0x80000404,2);
  DSP_Init();
  DSP_CopyImage(&local_2c);
  DSP_CopyImage(&local_20);
  DSP_CopyImage(&local_14);
  DAT_4000200c = 0;
  return;
}


// ===== BOARD_InitPins_P0 @ 00084b78 (108 bytes)

void BOARD_InitPins_P0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  DAT_40021044 = 1;
  local_18 = param_1 & 0xffff0000;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  GPIO_PinInit(&DAT_40100000,0,4,&local_18);
  local_14 = local_14 & 0xffff0000;
  GPIO_PinInit(&DAT_40100000,0,5,&local_14);
  local_10 = local_10 & 0xffff0000;
  GPIO_PinInit(&DAT_40100000,0,0x15,&local_10);
  local_c = local_c & 0xffff0000;
  GPIO_PinInit(&DAT_40100000,0,0x16,&local_c);
  DAT_40004054 = 0x40;
  DAT_40004058 = 0x40;
  DAT_40004010 = 0x40;
  DAT_40004014 = 0x40;
  return;
}


// ===== BOARD_InitPins_codec_spi @ 00084bec (150 bytes)

void BOARD_InitPins_codec_spi(void)

{
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1c [2];
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_14;
  undefined1 local_13;
  
  DAT_40021044 = 2;
  DAT_40021044 = 4;
  local_24 = 1;
  local_23 = 0;
  GPIO_PinInit(&DAT_40100000,1,0,&local_24);
  local_20 = 1;
  local_1f = 0;
  GPIO_PinInit(&DAT_40100000,1,1,&local_20);
  local_1c[0] = 0x101;
  GPIO_PinInit(&DAT_40100000,1,7,local_1c);
  local_18 = 0;
  local_17 = 0;
  GPIO_PinInit(&DAT_40100000,2,0x1c,&local_18);
  local_14 = 1;
  local_13 = 0;
  GPIO_PinInit(&DAT_40100000,2,0x1d,&local_14);
  DAT_40004080 = 0;
  DAT_40004084 = 0;
  DAT_4000409c = 0;
  DAT_40004170 = 0x40;
  DAT_40004174 = 0;
  return;
}


// ===== BOARD_InitPins_debug_gpio @ 00084c90 (164 bytes)

/* NEW (tail call from BOARD_InitPins). GPIO outputs low: PIO0_28/29/31 (TP2043/2046/2044),
   PIO2_4/5/6 (TP2007/2008/2009) [fact] */

void BOARD_InitPins_debug_gpio(void)

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


// ===== malloc @ 00084d3c (194 bytes)

/* Replaces redlib_malloc: Redlib heap malloc, free-list blocks tagged 0x10000000 (free) /
   0x20000000 (used), grows with _sbrk 0x85D48 [inference] */

int * malloc(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  
  if (param_1 != 0) {
    uVar7 = param_1 + 3U >> 2;
    piVar1 = DAT_00088b70;
    piVar6 = (int *)0x0;
    while (piVar4 = piVar1, piVar4 != (int *)0x0) {
      if (*piVar4 == 0x10000000) {
        while( true ) {
          uVar3 = piVar4[1];
          piVar1 = (int *)piVar4[2];
          if ((piVar1 == (int *)0x0) || (*piVar1 != 0x10000000)) break;
          piVar4[1] = piVar1[1] + uVar3 + 3;
          piVar4[2] = piVar1[2];
        }
        if (((int)uVar7 <= (int)uVar3) && ((int)uVar3 <= (int)(uVar7 + 3))) {
          *piVar4 = 0x20000000;
          return piVar4 + 3;
        }
        if (uVar7 + 10 < uVar3) {
          piVar4[1] = uVar7;
          piVar6 = piVar4 + 3;
          *piVar4 = 0x20000000;
          uVar5 = param_1 + 3U & 0xfffffffc;
          iVar2 = (int)piVar6 + uVar5;
          piVar4[2] = iVar2;
          *(undefined4 *)((int)piVar6 + uVar5) = 0x10000000;
          *(uint *)(iVar2 + 4) = (uVar3 - uVar7) + -3;
          *(int **)(iVar2 + 8) = piVar1;
          return piVar6;
        }
        if (piVar1 == (int *)0x0) {
          iVar2 = _sbrk(param_1 + uVar3 * -4);
          if (iVar2 == -1) {
            return (int *)0x0;
          }
          *piVar4 = 0x20000000;
          piVar4[1] = uVar7;
          return piVar4 + 3;
        }
      }
      piVar6 = piVar4;
      piVar1 = (int *)piVar4[2];
    }
    piVar1 = (int *)_sbrk(param_1 + 0xc);
    if (piVar1 != (int *)0xffffffff) {
      piVar1[2] = 0;
      *piVar1 = 0x20000000;
      piVar1[1] = uVar7;
      piVar4 = piVar1;
      if (piVar6 != (int *)0x0) {
        piVar6[2] = (int)piVar1;
        piVar4 = DAT_00088b70;
      }
      DAT_00088b70 = piVar4;
      return piVar1 + 3;
    }
  }
  return (int *)0x0;
}


// ===== _Csys_alloc @ 00084e04 (26 bytes)

/* Replaces _Csys_alloc_failed: malloc wrapper; on NULL writes "*** _Csys_alloc failed" via
   __sys_write and calls __sys_appexit (hang) [fact] */

int _Csys_alloc(void)

{
  int iVar1;
  
  iVar1 = malloc();
  if (iVar1 == 0) {
    __sys_write(0,"*** _Csys_alloc failed\n",0x17);
    __sys_appexit();
  }
  return iVar1;
}


// ===== tolower @ 00084e24 (16 bytes)

int tolower(int param_1)

{
  if ((int)((uint)ctype_table[param_1] << 0x1b) < 0) {
    param_1 = param_1 + 0x20;
  }
  return param_1;
}


// ===== stdio_init @ 00084e38 (94 bytes)

/* WARNING: Removing unreachable block (ram,0x00084e94) */

void stdio_init(void)

{
  _Cfdopen(0,"r",&DAT_00088b78);
  setvbuf(&DAT_00088b78,0,0x400,0x100);
  _Cfdopen(1,"w",&DAT_00088bb4);
  setvbuf(&DAT_00088bb4,0,0x400,0x100);
  _Cfdopen(2,"w",&DAT_00088bf0);
  setvbuf(&DAT_00088bf0,0,0x400,0x100);
  return;
}


// ===== vsnprintf_core @ 00084eb0 (2778 bytes)

uint vsnprintf_core(int *param_1,undefined4 param_2,uint param_3,int param_4,byte *param_5,
                   uint *param_6,code *param_7)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  uint *puVar11;
  char *pcVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  int iVar19;
  undefined4 *puVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  bool bVar25;
  uint local_88;
  uint local_84;
  uint local_70;
  uint local_60;
  char *local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  char acStack_48 [36];
  
  local_88 = 0;
LAB_00084ec2:
  while( true ) {
    pbVar18 = param_5 + 1;
    bVar2 = *param_5;
    if (bVar2 == 0) {
      return local_88;
    }
    uVar5 = (int)local_88 >> 0x1f;
    if (bVar2 == 0x25) break;
    bVar25 = local_88 < param_3;
    local_88 = local_88 + 1;
    param_5 = pbVar18;
    if ((int)((uVar5 - param_4) - (uint)bVar25) < 0 !=
        (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)bVar25))) {
      iVar7 = param_1[2];
      param_1[2] = iVar7 + -1;
      if (iVar7 + -1 < 0) {
        fputc(bVar2,param_1);
      }
      else {
        pbVar18 = (byte *)*param_1;
        *param_1 = (int)(pbVar18 + 1);
        *pbVar18 = bVar2;
      }
    }
  }
  uVar23 = 0;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          param_5 = pbVar18 + 1;
          uVar16 = (uint)*pbVar18;
          if (uVar16 != 0x2b) break;
          uVar23 = uVar23 | 2;
          pbVar18 = param_5;
        }
        if (uVar16 < 0x2c) break;
        if (uVar16 == 0x2d) {
          uVar23 = uVar23 | 1;
          pbVar18 = param_5;
        }
        else {
          if (uVar16 != 0x30) goto LAB_00084f3a;
          uVar23 = uVar23 | 0x200;
          pbVar18 = param_5;
        }
      }
      if (uVar16 != 0x20) break;
      uVar23 = uVar23 | 4;
      pbVar18 = param_5;
    }
    if (uVar16 != 0x23) break;
    uVar23 = uVar23 | 8;
    pbVar18 = param_5;
  }
LAB_00084f3a:
  if (uVar16 == 0x2a) {
    uVar21 = *param_6;
    uVar16 = (uint)*param_5;
    if ((int)uVar21 < 0) {
      uVar21 = -uVar21;
      uVar23 = uVar23 ^ 1;
    }
    param_5 = pbVar18 + 2;
    param_6 = param_6 + 1;
  }
  else {
    uVar21 = 0;
    while ((uVar16 - 0x30 & 0xff) < 10) {
      uVar21 = uVar21 * 10 + (uVar16 - 0x30);
      uVar16 = (uint)*param_5;
      param_5 = param_5 + 1;
    }
  }
  uVar8 = uVar21 & ~((int)uVar21 >> 0x1f);
  puVar14 = param_6;
  if (uVar16 == 0x2e) {
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x2a) {
      puVar14 = param_6 + 1;
      uVar24 = *param_6;
      uVar16 = (uint)param_5[1];
      param_5 = param_5 + 2;
    }
    else {
      uVar24 = 0;
      while( true ) {
        param_5 = param_5 + 1;
        if (9 < (uVar16 - 0x30 & 0xff)) break;
        uVar24 = uVar24 * 10 + (uVar16 - 0x30);
        uVar16 = (uint)*param_5;
      }
    }
    if ((int)uVar24 < 0) goto LAB_00085002;
    uVar23 = uVar23 | 0x10;
  }
  else {
LAB_00085002:
    uVar24 = 0;
  }
  if (uVar16 == 0x6c) {
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x6c) {
      uVar16 = (uint)param_5[1];
      uVar23 = uVar23 | 0x60;
      param_5 = param_5 + 2;
    }
    else {
      param_5 = param_5 + 1;
      uVar23 = uVar23 | 0x20;
    }
  }
  if ((uVar16 == 0x4c) || (uVar16 == 0x71)) {
    bVar2 = *param_5;
    uVar23 = uVar23 | 0x60;
LAB_00084ffe:
    uVar16 = (uint)bVar2;
    param_5 = param_5 + 1;
  }
  else {
    if (uVar16 != 0x68) {
      if (uVar16 == 0x6a) {
        uVar23 = uVar23 | 0x40;
      }
      else if ((uVar16 != 0x7a) && (uVar16 != 0x74)) goto LAB_0008502a;
      bVar2 = *param_5;
      goto LAB_00084ffe;
    }
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x68) {
      uVar16 = (uint)param_5[1];
      uVar23 = uVar23 | 0x100;
      param_5 = param_5 + 2;
    }
    else {
      param_5 = param_5 + 1;
      uVar23 = uVar23 | 0x80;
    }
  }
LAB_0008502a:
  param_6 = puVar14;
  if (0x78 < uVar16) goto switchD_000850fe_caseD_59;
  if (uVar16 < 0x58) {
    if (uVar16 == 0x41) {
switchD_000850fe_caseD_61:
      if ((uVar23 & 0x10) == 0) {
        uVar24 = 0xd;
        uVar23 = uVar23 | 0x10;
      }
switchD_000850fe_caseD_65:
      puVar20 = (undefined4 *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar20 + 2;
      local_50 = *puVar20;
      uStack_4c = puVar20[1];
      uVar21 = 0;
      if ((uVar23 & 0x10) == 0) {
        uVar24 = 6;
      }
      uVar6 = 0;
      pcVar3 = (char *)0x0;
      local_5c = (char *)0x0;
      uVar23 = uVar23 | 0x400;
      goto LAB_00085464;
    }
    if (uVar16 < 0x42) {
      if (uVar16 != 0) goto switchD_000850fe_caseD_59;
      param_5 = param_5 + -1;
      goto LAB_00084ec2;
    }
    if ((uVar16 & 0xfffffffd) == 0x45) goto switchD_000850fe_caseD_65;
switchD_000850fe_caseD_59:
    iVar7 = uVar8 - 1;
    if ((uVar23 & 1) == 0) {
      uVar24 = local_88;
      iVar19 = iVar7;
      if ((uVar23 & 0x200) == 0) {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 0x30;
      }
      while (-1 < iVar19 + -1) {
        if ((int)((uVar5 - param_4) - (uint)(uVar24 < param_3)) < 0 !=
            (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)(uVar24 < param_3)))) {
          iVar22 = param_1[2];
          param_1[2] = iVar22 + -1;
          if (iVar22 + -1 < 0) {
            fputc(uVar4,param_1);
          }
          else {
            puVar9 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar9 + 1);
            *puVar9 = uVar4;
          }
        }
        uVar5 = uVar5 + (0xfffffffe < uVar24);
        uVar24 = uVar24 + 1;
        iVar19 = iVar19 + -1;
      }
      if ((int)uVar21 < 1) {
        iVar7 = 0;
      }
      iVar19 = 1 - uVar8;
      if ((int)uVar21 < 1) {
        iVar19 = 0;
      }
      local_88 = iVar7 + local_88;
      iVar7 = iVar19 + (uVar8 - 2);
    }
    uVar5 = local_88 + 1;
    iVar19 = (int)local_88 >> 0x1f;
    if ((int)((iVar19 - param_4) - (uint)(local_88 < param_3)) < 0 !=
        (SBORROW4(iVar19,param_4) != SBORROW4(iVar19 - param_4,(uint)(local_88 < param_3)))) {
      iVar19 = param_1[2];
      param_1[2] = iVar19 + -1;
      if (iVar19 + -1 < 0) {
        fputc(uVar16,param_1);
      }
      else {
        puVar9 = (undefined1 *)*param_1;
        *param_1 = (int)(puVar9 + 1);
        *puVar9 = (char)uVar16;
      }
    }
    local_88 = uVar5;
    if ((uVar23 & 1) != 0) {
      iVar19 = (int)uVar5 >> 0x1f;
      uVar23 = uVar5;
      iVar22 = iVar7;
      while (iVar22 = iVar22 + -1, -1 < iVar22) {
        if ((int)((iVar19 - param_4) - (uint)(uVar23 < param_3)) < 0 !=
            (SBORROW4(iVar19,param_4) != SBORROW4(iVar19 - param_4,(uint)(uVar23 < param_3)))) {
          iVar10 = param_1[2];
          param_1[2] = iVar10 + -1;
          if (iVar10 + -1 < 0) {
            fputc(0x20,param_1);
          }
          else {
            puVar9 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar9 + 1);
            *puVar9 = 0x20;
          }
        }
        bVar25 = 0xfffffffe < uVar23;
        uVar23 = uVar23 + 1;
        iVar19 = iVar19 + (uint)bVar25;
      }
      if (-1 < iVar7) {
        local_88 = uVar5 + iVar7;
      }
    }
    goto LAB_00084ec2;
  }
  switch(uVar16) {
  case 0x58:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = "0X";
    if ((uVar23 & 8) == 0) {
      local_5c = "";
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = "0123456789ABCDEF";
    break;
  default:
    goto switchD_000850fe_caseD_59;
  case 0x61:
    goto switchD_000850fe_caseD_61;
  case 99:
    param_6 = puVar14 + 1;
    uVar16 = *puVar14;
    goto switchD_000850fe_caseD_59;
  case 100:
  case 0x69:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = (int)uVar21 >> 0x1f;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar6 = (int)(uVar21 << 0x18) >> 0x1f;
        uVar21 = (uint)(char)uVar21;
      }
    }
    else {
      uVar6 = (int)(uVar21 << 0x10) >> 0x1f;
      uVar21 = (uint)(short)uVar21;
    }
    if ((int)uVar6 < 0) {
      bVar25 = uVar21 != 0;
      uVar21 = -uVar21;
      local_5c = "-";
      uVar6 = -uVar6 - (uint)bVar25;
    }
    else {
      if ((uVar23 & 2) == 0) {
        local_5c = " ";
        uVar15 = uVar23 & 4;
        goto LAB_000854ea;
      }
      local_5c = "+";
    }
    goto LAB_00085596;
  case 0x65:
  case 0x66:
  case 0x67:
    goto switchD_000850fe_caseD_65;
  case 0x6e:
    puVar11 = (uint *)*puVar14;
    param_6 = puVar14 + 1;
    if ((uVar23 & 0x40) == 0) {
      if ((uVar23 & 0x20) == 0) {
        if ((uVar23 & 0x100) != 0) {
          *(char *)puVar11 = (char)local_88;
          goto LAB_00084ec2;
        }
        if ((uVar23 & 0x80) != 0) {
          *(short *)puVar11 = (short)local_88;
          goto LAB_00084ec2;
        }
      }
      *puVar11 = local_88;
      goto LAB_00084ec2;
    }
    *puVar11 = local_88;
    puVar11[1] = uVar5;
    goto LAB_00084ec2;
  case 0x6f:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = "0";
    uVar15 = uVar23 & 8;
LAB_000854ea:
    if (uVar15 == 0) {
      local_5c = "";
    }
LAB_00085596:
    pcVar3 = (char *)0x0;
    if ((uVar23 & 0x10) != 0) {
      pcVar3 = (char *)0x0;
      uVar23 = uVar23 & 0xfffffdff;
    }
    break;
  case 0x70:
    uVar6 = 0;
    param_6 = puVar14 + 1;
    uVar21 = *puVar14;
    pcVar3 = "0123456789abcdef";
    local_5c = "0x";
    break;
  case 0x73:
    goto switchD_000850fe_caseD_73;
  case 0x75:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = (char *)0x0;
    local_5c = "";
    break;
  case 0x78:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar14 + 1;
      uVar21 = *puVar14;
      uVar6 = 0;
    }
    else {
      puVar14 = (uint *)((int)puVar14 + 7U & 0xfffffff8);
      param_6 = puVar14 + 2;
      uVar21 = *puVar14;
      uVar6 = puVar14[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = "0x";
    if ((uVar23 & 8) == 0) {
      local_5c = "";
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = "0123456789abcdef";
  }
LAB_00085464:
  uVar15 = param_3 - local_88;
  local_58 = -1;
  local_54 = -1;
  iVar19 = (param_4 - uVar5) - (uint)(param_3 < local_88);
  iVar7 = 0;
  pcVar12 = acStack_48;
  do {
    iVar7 = iVar7 + 1;
    *pcVar12 = 'U';
    pcVar12 = pcVar12 + 1;
  } while (iVar7 != 0x20);
  local_60 = uVar24;
  if ((uVar23 & 0x410) == 0) {
    local_60 = 1;
  }
  pcVar12 = acStack_48;
  if (uVar16 < 0x6f) {
    if (uVar16 < 0x48) {
      if (0x40 < uVar16) {
        iVar7 = 0;
        if ((1 << (uVar16 - 0x41 & 0xff) & 0x51U) == 0) goto switchD_000855de_caseD_71;
switchD_000856e6_caseD_61:
        iVar7 = (*param_7)(uVar16,&local_50,acStack_48,uVar23,&local_5c,&local_60,&local_58,
                           &local_54);
        goto switchD_000855de_caseD_71;
      }
    }
    else {
      switch(uVar16) {
      case 0x58:
        iVar7 = 0;
        goto switchD_000855de_caseD_70;
      case 0x61:
      case 0x65:
      case 0x66:
      case 0x67:
        goto switchD_000856e6_caseD_61;
      case 100:
      case 0x69:
        goto switchD_000855de_caseD_75;
      }
    }
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    switch(uVar16) {
    case 0x6f:
      for (; uVar21 != 0 || uVar6 != 0; uVar21 = uVar21 >> 3 | uVar5) {
        uVar5 = uVar6 << 0x1d;
        iVar7 = iVar7 + 1;
        *pcVar12 = ((byte)uVar21 & 7) + 0x30;
        uVar6 = uVar6 >> 3;
        pcVar12 = pcVar12 + 1;
      }
      break;
    case 0x70:
    case 0x78:
switchD_000855de_caseD_70:
      for (; uVar21 != 0 || uVar6 != 0; uVar21 = uVar21 >> 4 | uVar5) {
        uVar5 = uVar6 << 0x1c;
        iVar7 = iVar7 + 1;
        *pcVar12 = pcVar3[uVar21 & 0xf];
        uVar6 = uVar6 >> 4;
        pcVar12 = pcVar12 + 1;
      }
      break;
    case 0x75:
switchD_000855de_caseD_75:
      iVar7 = 0;
      pcVar3 = acStack_48;
      for (; uVar21 != 0 || uVar6 != 0; uVar6 = uVar16 + (uVar5 >> 4) + (uint)CARRY4(uVar6,uVar24))
      {
        uVar5 = uVar21 >> 2 | uVar6 << 0x1e;
        uVar16 = uVar21 >> 1 | uVar6 << 0x1f;
        uVar24 = uVar16 + uVar5;
        uVar5 = (uVar6 >> 2) + (uVar6 >> 1) + (uint)CARRY4(uVar16,uVar5);
        uVar16 = uVar24 >> 4 | uVar5 * 0x10000000;
        uVar17 = uVar24 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 4) + (uint)CARRY4(uVar24,uVar16);
        uVar16 = uVar17 >> 8 | uVar5 * 0x1000000;
        uVar24 = uVar17 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 8) + (uint)CARRY4(uVar17,uVar16);
        uVar16 = uVar24 >> 0x10 | uVar5 * 0x10000;
        uVar17 = uVar24 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 0x10) + (uint)CARRY4(uVar24,uVar16);
        uVar16 = uVar5 + CARRY4(uVar17,uVar5);
        uVar24 = uVar17 + uVar5 >> 3 | uVar16 * 0x20000000;
        uVar17 = (uint)((ulonglong)uVar24 * 10);
        uVar16 = uVar16 >> 3;
        uVar5 = ((uVar6 + (0xfffffff9 < uVar21)) -
                (uVar16 * 10 + (int)((ulonglong)uVar24 * 10 >> 0x20))) - (uint)(uVar21 + 6 < uVar17)
        ;
        uVar6 = (uVar21 + 6) - uVar17 >> 4 | uVar5 * 0x10000000;
        uVar17 = uVar6 + uVar24;
        *pcVar3 = (char)uVar21 + '0' + (char)uVar17 * -10;
        iVar7 = iVar7 + 1;
        uVar21 = uVar17;
        pcVar3 = pcVar3 + 1;
      }
    }
  }
switchD_000855de_caseD_71:
  if ((uVar23 & 0x400) == 0) {
    local_60 = local_60 - iVar7;
    if ((int)local_60 < 0) {
      local_60 = 0;
    }
  }
  else {
    local_60 = 0;
    if (0 < local_58) {
      local_60 = local_58 - 1;
    }
    if (0 < local_54) {
      local_60 = local_54 + -1 + local_60;
    }
  }
  iVar10 = iVar7 + local_60;
  iVar22 = strlen(local_5c);
  local_84 = (uVar8 - iVar10) - iVar22;
  if ((uVar23 & 0x201) == 0) {
    iVar22 = 0;
    for (uVar5 = 0; -1 < (int)((local_84 - 1) - uVar5); uVar5 = uVar5 + 1) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar5 < uVar15)))) {
        iVar10 = param_1[2];
        param_1[2] = iVar10 + -1;
        if (iVar10 + -1 < 0) {
          fputc(0x20,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x20;
        }
      }
      iVar22 = iVar22 + (uint)(0xfffffffe < uVar5);
    }
    uVar5 = local_84 & ~((int)local_84 >> 0x1f);
    local_84 = (local_84 - 1) - uVar5;
  }
  else {
    uVar5 = 0;
  }
  iVar22 = (int)uVar5 >> 0x1f;
  uVar16 = uVar5;
  while( true ) {
    pcVar3 = local_5c + 1;
    cVar1 = *local_5c;
    local_5c = pcVar3;
    if (cVar1 == '\0') break;
    uVar5 = uVar5 + 1;
    if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
        (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
      iVar10 = param_1[2];
      param_1[2] = iVar10 + -1;
      if (iVar10 + -1 < 0) {
        fputc(cVar1,param_1);
      }
      else {
        pcVar3 = (char *)*param_1;
        *param_1 = (int)(pcVar3 + 1);
        *pcVar3 = cVar1;
      }
    }
    bVar25 = 0xfffffffe < uVar16;
    uVar16 = uVar16 + 1;
    iVar22 = iVar22 + (uint)bVar25;
  }
  if ((uVar23 & 1) == 0) {
    if ((uVar23 & 0x200) == 0) {
      uVar4 = 0x20;
    }
    else {
      uVar4 = 0x30;
    }
    iVar22 = (int)uVar5 >> 0x1f;
    local_70 = local_84;
    uVar16 = uVar5;
    while (local_70 = local_70 - 1, -1 < (int)local_70) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
        iVar10 = param_1[2];
        param_1[2] = iVar10 + -1;
        if (iVar10 + -1 < 0) {
          fputc(uVar4,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = uVar4;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
    }
    uVar16 = local_84 & ~((int)local_84 >> 0x1f);
    local_84 = (local_84 - 1) - uVar16;
    uVar5 = uVar5 + uVar16;
  }
  iVar22 = 0;
  if ((uVar23 & 0x400) == 0) {
    iVar22 = (int)uVar5 >> 0x1f;
    uVar16 = uVar5;
    while (local_60 = local_60 - 1, -1 < (int)local_60) {
      uVar5 = uVar5 + 1;
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
        iVar10 = param_1[2];
        param_1[2] = iVar10 + -1;
        if (iVar10 + -1 < 0) {
          fputc(0x30,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x30;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
    }
    iVar22 = (int)uVar5 >> 0x1f;
    iVar10 = iVar7;
    uVar16 = uVar5;
    while (0 < iVar10) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar15)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar15)))) {
        iVar13 = param_1[2];
        cVar1 = acStack_48[iVar10 + -1];
        param_1[2] = iVar13 + -1;
        if (iVar13 + -1 < 0) {
          fputc(cVar1,param_1);
        }
        else {
          pcVar3 = (char *)*param_1;
          *param_1 = (int)(pcVar3 + 1);
          *pcVar3 = cVar1;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
      iVar10 = iVar10 + -1;
    }
    if (-1 < iVar7) {
      uVar5 = uVar5 + iVar7;
    }
  }
  else {
    for (; iVar22 < iVar7; iVar22 = iVar22 + 1) {
      cVar1 = acStack_48[iVar22];
      iVar10 = (int)uVar5 >> 0x1f;
      uVar16 = uVar5;
      if (cVar1 == '<') {
        while (local_58 = local_58 + -1, -1 < local_58) {
          if ((int)((iVar10 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
              (SBORROW4(iVar10,iVar19) != SBORROW4(iVar10 - iVar19,(uint)(uVar5 < uVar15)))) {
            iVar13 = param_1[2];
            param_1[2] = iVar13 + -1;
            if (iVar13 + -1 < 0) {
              fputc(0x30,param_1);
            }
            else {
              puVar9 = (undefined1 *)*param_1;
              *param_1 = (int)(puVar9 + 1);
              *puVar9 = 0x30;
            }
          }
          bVar25 = 0xfffffffe < uVar5;
          uVar5 = uVar5 + 1;
          iVar10 = iVar10 + (uint)bVar25;
          uVar16 = uVar16 + 1;
        }
      }
      else if (cVar1 == '>') {
        while (local_54 = local_54 + -1, -1 < local_54) {
          if ((int)((iVar10 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
              (SBORROW4(iVar10,iVar19) != SBORROW4(iVar10 - iVar19,(uint)(uVar5 < uVar15)))) {
            iVar13 = param_1[2];
            param_1[2] = iVar13 + -1;
            if (iVar13 + -1 < 0) {
              fputc(0x30,param_1);
            }
            else {
              puVar9 = (undefined1 *)*param_1;
              *param_1 = (int)(puVar9 + 1);
              *puVar9 = 0x30;
            }
          }
          bVar25 = 0xfffffffe < uVar5;
          uVar5 = uVar5 + 1;
          iVar10 = iVar10 + (uint)bVar25;
          uVar16 = uVar16 + 1;
        }
      }
      else {
        uVar16 = uVar5 + 1;
        if ((int)((iVar10 - iVar19) - (uint)(uVar5 < uVar15)) < 0 !=
            (SBORROW4(iVar10,iVar19) != SBORROW4(iVar10 - iVar19,(uint)(uVar5 < uVar15)))) {
          iVar10 = param_1[2];
          param_1[2] = iVar10 + -1;
          if (iVar10 + -1 < 0) {
            fputc(cVar1,param_1);
          }
          else {
            pcVar3 = (char *)*param_1;
            *param_1 = (int)(pcVar3 + 1);
            *pcVar3 = cVar1;
          }
        }
      }
      uVar5 = uVar16;
    }
  }
  if ((uVar23 & 1) != 0) {
    iVar7 = (int)uVar5 >> 0x1f;
    uVar23 = uVar5;
    uVar16 = local_84;
    while (uVar16 = uVar16 - 1, -1 < (int)uVar16) {
      if ((int)((iVar7 - iVar19) - (uint)(uVar23 < uVar15)) < 0 !=
          (SBORROW4(iVar7,iVar19) != SBORROW4(iVar7 - iVar19,(uint)(uVar23 < uVar15)))) {
        iVar22 = param_1[2];
        param_1[2] = iVar22 + -1;
        if (iVar22 + -1 < 0) {
          fputc(0x20,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x20;
        }
      }
      bVar25 = 0xfffffffe < uVar23;
      uVar23 = uVar23 + 1;
      iVar7 = iVar7 + (uint)bVar25;
    }
    if (-1 < (int)local_84) {
      uVar5 = uVar5 + local_84;
    }
  }
  local_88 = local_88 + uVar5;
  goto LAB_00084ec2;
switchD_000850fe_caseD_73:
  param_6 = puVar14 + 1;
  pcVar3 = (char *)*puVar14;
  if (pcVar3 == (char *)0x0) {
    pcVar3 = "(null)";
  }
  local_84 = strlen(pcVar3);
  if (((uVar23 & 0x10) != 0) && ((int)uVar24 <= (int)local_84)) {
    local_84 = uVar24;
  }
  uVar8 = uVar8 - local_84;
  if ((uVar23 & 1) == 0) {
    uVar16 = local_88;
    uVar21 = uVar8;
    if ((uVar23 & 0x200) == 0) {
      uVar4 = 0x20;
    }
    else {
      uVar4 = 0x30;
    }
    while (-1 < (int)(uVar21 - 1)) {
      if ((int)((uVar5 - param_4) - (uint)(uVar16 < param_3)) < 0 !=
          (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)(uVar16 < param_3)))) {
        iVar7 = param_1[2];
        param_1[2] = iVar7 + -1;
        if (iVar7 + -1 < 0) {
          fputc(uVar4,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = uVar4;
        }
      }
      uVar5 = uVar5 + (0xfffffffe < uVar16);
      uVar16 = uVar16 + 1;
      uVar21 = uVar21 - 1;
    }
    uVar5 = uVar8 & ~((int)uVar8 >> 0x1f);
    local_88 = local_88 + uVar5;
    uVar8 = (uVar8 - 1) - uVar5;
  }
  iVar7 = (int)local_88 >> 0x1f;
  uVar5 = local_88;
  for (iVar19 = 0; iVar19 < (int)local_84; iVar19 = iVar19 + 1) {
    if ((int)((iVar7 - param_4) - (uint)(uVar5 < param_3)) < 0 !=
        (SBORROW4(iVar7,param_4) != SBORROW4(iVar7 - param_4,(uint)(uVar5 < param_3)))) {
      iVar22 = param_1[2];
      param_1[2] = iVar22 + -1;
      if (iVar22 + -1 < 0) {
        fputc(pcVar3[iVar19],param_1);
      }
      else {
        pcVar12 = (char *)*param_1;
        *param_1 = (int)(pcVar12 + 1);
        *pcVar12 = pcVar3[iVar19];
      }
    }
    bVar25 = 0xfffffffe < uVar5;
    uVar5 = uVar5 + 1;
    iVar7 = iVar7 + (uint)bVar25;
  }
  if (-1 < (int)local_84) {
    local_88 = local_88 + local_84;
  }
  if ((uVar23 & 1) != 0) {
    iVar7 = (int)local_88 >> 0x1f;
    uVar5 = local_88;
    uVar23 = uVar8;
    while (uVar23 = uVar23 - 1, -1 < (int)uVar23) {
      if ((int)((iVar7 - param_4) - (uint)(uVar5 < param_3)) < 0 !=
          (SBORROW4(iVar7,param_4) != SBORROW4(iVar7 - param_4,(uint)(uVar5 < param_3)))) {
        iVar19 = param_1[2];
        param_1[2] = iVar19 + -1;
        if (iVar19 + -1 < 0) {
          fputc(0x20,param_1);
        }
        else {
          puVar9 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar9 + 1);
          *puVar9 = 0x20;
        }
      }
      bVar25 = 0xfffffffe < uVar5;
      uVar5 = uVar5 + 1;
      iVar7 = iVar7 + (uint)bVar25;
    }
    if (-1 < (int)uVar8) {
      local_88 = local_88 + uVar8;
    }
  }
  goto LAB_00084ec2;
}


// ===== siprintf @ 00085a9c (102 bytes)

undefined4 siprintf(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined1 *local_54 [2];
  int local_4c;
  undefined4 local_48;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  memset(local_54,0,0x3c);
  local_48 = 10;
  local_4c = 0x7fffffff;
  local_54[0] = param_1;
  uVar1 = vsnprintf_core(local_54,extraout_r1,0xffffffff,0x7fffffff,param_2,&uStack_8,
                         &LAB_000872f4_1);
  local_4c = local_4c + -1;
  if (local_4c < 0) {
    fputc(0,local_54);
  }
  else {
    *local_54[0] = 0;
  }
  return uVar1;
}


// ===== snprintf @ 00085b08 (114 bytes)

undefined4 snprintf(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined1 local_5c [4];
  undefined4 *local_58;
  undefined1 *local_54 [2];
  int local_4c;
  undefined4 local_48;
  undefined4 uStack_4;
  
  if (param_1 == (undefined1 *)0x0) {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    param_2 = 1;
    param_1 = local_5c;
  }
  local_58 = &uStack_4;
  uStack_4 = param_4;
  memset(local_54,0,0x3c);
  local_48 = 10;
  local_4c = 0x7fffffff;
  local_54[0] = param_1;
  uVar1 = vsnprintf_core(local_54,extraout_r1,param_2 + -1,0,param_3,local_58,&LAB_000872f4_1);
  local_4c = local_4c + -1;
  if (local_4c < 0) {
    fputc(0,local_54);
  }
  else {
    *local_54[0] = 0;
  }
  return uVar1;
}


// ===== sprintf @ 00085b80 (88 bytes)

undefined4 sprintf(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined1 *local_4c [2];
  int local_44;
  undefined4 local_40;
  
  memset(local_4c,0,0x3c);
  local_40 = 10;
  local_44 = 0x7fffffff;
  local_4c[0] = param_1;
  uVar1 = vsnprintf_core(local_4c,extraout_r1,0xffffffff,0x7fffffff,param_2,param_3,&LAB_000872f4_1)
  ;
  local_44 = local_44 + -1;
  if (local_44 < 0) {
    fputc(0,local_4c);
  }
  else {
    *local_4c[0] = 0;
  }
  return uVar1;
}


// ===== _Cdigit_value @ 00085bdc (44 bytes)

/* ctype-table digit value for strtoul [inference] */

int _Cdigit_value(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)ctype_table[param_1];
  if ((int)(uVar1 << 0x1a) < 0) {
    param_1 = param_1 + -0x30;
  }
  else if ((int)(uVar1 << 0x1c) < 0) {
    param_1 = param_1 + -0x57;
  }
  else if ((int)(uVar1 << 0x1b) < 0) {
    param_1 = param_1 + -0x37;
  }
  else {
    param_1 = -1;
  }
  if (param_2 <= param_1) {
    param_1 = -1;
  }
  return param_1;
}


// ===== _strtoul_core @ 00085c0c (172 bytes)

/* Base detection (0x / 0), overflow -> errno 34 (0x88B74) [inference] */

uint _strtoul_core(byte *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
  pbVar6 = param_1;
  do {
    pbVar5 = pbVar6;
    pbVar6 = pbVar5 + 1;
    uVar3 = (uint)*pbVar5;
    if (uVar3 == 0) goto LAB_00085c30;
  } while ((int)((uint)ctype_table[uVar3] << 0x1f) < 0);
  if (uVar3 == 0x30) {
    uVar3 = (uint)*pbVar6;
    pbVar6 = pbVar5 + 2;
    if ((uVar3 & 0xdf) == 0x58) {
      if ((param_3 & 0xffffffef) == 0) {
        param_3 = 0x10;
        uVar3 = (uint)pbVar5[2];
        pbVar6 = pbVar5 + 3;
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
      if (param_3 == 0) {
        param_3 = 8;
      }
    }
  }
  else {
LAB_00085c30:
    if (param_3 == 0) {
      param_3 = 10;
      bVar2 = false;
    }
    else {
      bVar2 = false;
    }
  }
  uVar7 = 0;
  uVar8 = 0;
  bVar1 = false;
  while (iVar4 = _Cdigit_value(uVar3,param_3), -1 < iVar4) {
    uVar7 = uVar7 * param_3 + iVar4;
    uVar8 = uVar8 * param_3 + (uVar7 >> 0x10);
    if (0xffff < uVar8) {
      bVar1 = true;
    }
    bVar2 = true;
    uVar3 = (uint)*pbVar6;
    uVar7 = uVar7 & 0xffff;
    pbVar6 = pbVar6 + 1;
  }
  if (bVar2) {
    param_1 = pbVar6 + -1;
  }
  *param_2 = param_1;
  if (bVar1) {
    uVar7 = 0xffffffff;
    DAT_00088b74 = 0x22;
  }
  else {
    uVar7 = uVar7 | uVar8 << 0x10;
  }
  return uVar7;
}


// ===== strtoul @ 00085cc0 (128 bytes)

int strtoul(byte *param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *local_24;
  undefined4 uStack_20;
  
  iVar1 = DAT_00088b74;
  pbVar5 = param_1;
  do {
    pbVar4 = pbVar5;
    pbVar5 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
    if (uVar3 == 0) {
      uVar6 = 0;
      pbVar5 = pbVar4;
      goto LAB_00085cfa;
    }
    uVar6 = ctype_table[uVar3] & 1;
  } while ((ctype_table[uVar3] & 1) != 0);
  if (uVar3 != 0x2b) {
    if (uVar3 == 0x2d) {
      uVar6 = 0x200;
    }
    else {
      uVar6 = 0;
      pbVar5 = pbVar4;
    }
  }
LAB_00085cfa:
  DAT_00088b74 = 0;
  local_24 = param_2;
  uStack_20 = param_3;
  iVar2 = _strtoul_core(pbVar5,&local_24,param_3,0,param_1);
  if (param_2 != (byte *)0x0) {
    if (local_24 != pbVar5) {
      param_1 = local_24;
    }
    *(byte **)param_2 = param_1;
  }
  if ((DAT_00088b74 != 0x22) && (DAT_00088b74 = iVar1, uVar6 != 0)) {
    if (iVar2 < 0) {
      iVar2 = -1;
      DAT_00088b74 = 0x22;
    }
    else {
      iVar2 = -iVar2;
    }
  }
  return iVar2;
}


// ===== _sbrk @ 00085d48 (48 bytes)

/* Heap 0xA1EF8..0xA2EF8 (4 KB), errno 12 on overflow [fact: addresses] */

undefined * _sbrk(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if (DAT_00088b6c == (undefined *)0x0) {
    DAT_00088b6c = &DAT_000a1ef8;
  }
  puVar3 = DAT_00088b6c;
  puVar2 = DAT_00088b6c + (param_1 + 3U & 0xfffffffc);
  iVar1 = __check_heap_overflow(puVar2);
  if (iVar1 != 0) {
    puVar3 = (undefined *)0xffffffff;
    DAT_00088b74 = 0xc;
    puVar2 = DAT_00088b6c;
  }
  DAT_00088b6c = puVar2;
  return puVar3;
}


// ===== _Cwrite_buffer @ 00085d84 (102 bytes)

/* Flush FILE buffer through __sys_write [inference] */

undefined4 _Cwrite_buffer(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = *(uint *)(param_3 + 0xc);
  uVar4 = *(undefined4 *)(param_3 + 0x14);
  if ((int)(uVar3 << 0xb) < 0) {
    uVar1 = __sys_flen(uVar4);
    uVar3 = uVar3 | 0x10;
    *(undefined4 *)(param_3 + 0x18) = uVar1;
  }
  if ((uVar3 & 0x20010) != 0) {
    iVar2 = __sys_seek(uVar4,*(undefined4 *)(param_3 + 0x18));
    if (iVar2 < 0) goto LAB_00085db4;
    *(uint *)(param_3 + 0xc) = uVar3 & 0xfffdffef;
  }
  uVar3 = __sys_write(uVar4,param_1,param_2);
  *(uint *)(param_3 + 0x18) = (param_2 - (uVar3 & 0x7fffffff)) + *(int *)(param_3 + 0x18);
  if (uVar3 == 0) {
    return 0;
  }
LAB_00085db4:
  *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 0x80;
  return 0xffffffff;
}


// ===== fflush @ 00085df0 (50 bytes)

/* NULL -> all three streams at 0x88B78 (0x3C bytes each) [inference] */

undefined4 fflush(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (param_1 == 0) {
    puVar4 = &DAT_00088b78;
    uVar3 = 0;
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
      iVar1 = _Cfflush1(puVar4);
      if (iVar1 != 0) {
        uVar3 = 0xffffffff;
      }
      puVar4 = puVar4 + 0x3c;
    }
    return uVar3;
  }
  uVar3 = _Cfflush1();
  return uVar3;
}


// ===== fseek @ 00085e2c (252 bytes)

/* [inference] */

undefined4 fseek(uint *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = param_1[3];
  if ((uVar4 & 0x100003) == 0) {
    return 2;
  }
  uVar5 = param_1[5];
  iVar1 = __sys_istty(uVar5);
  if (iVar1 != 0) {
    return 2;
  }
  if (param_3 == 1) {
    iVar1 = ftell(param_1);
    param_2 = param_2 + iVar1;
  }
  else if (param_3 == 2) {
    uVar5 = __sys_flen(uVar5);
    if ((int)uVar5 < 0) {
      param_1[3] = param_1[3] | 0x80;
      return 1;
    }
    uVar3 = *param_1;
    if (uVar3 < param_1[0xb]) {
      uVar3 = param_1[0xb];
    }
    uVar3 = (param_1[6] + uVar3) - param_1[4];
    if (((int)(param_1[3] << 0x1a) < 0) && ((int)uVar3 < (int)param_1[10])) {
      uVar3 = param_1[10];
    }
    if ((int)uVar3 < (int)uVar5) {
      uVar3 = uVar5;
    }
    param_2 = param_2 + uVar3;
  }
  else if (param_3 != 0) {
    return 2;
  }
  if ((int)param_2 < 0) {
    return 2;
  }
  if ((int)(uVar4 << 0x12) < 0) {
    if (param_1[0xb] < *param_1) {
      param_1[0xb] = *param_1;
    }
  }
  uVar5 = param_1[6];
  if ((int)uVar5 <= (int)param_2) {
    uVar3 = *param_1;
    if (*param_1 < param_1[0xb]) {
      uVar3 = param_1[0xb];
    }
    uVar2 = param_1[4];
    if (((int)param_2 <= (int)((uVar3 + uVar5) - uVar2)) &&
       ((int)param_2 < (int)(uVar5 + param_1[0xc]))) {
      iVar1 = param_2 - uVar5;
      if ((int)(uVar4 << 0x1e) < 0) {
        param_1[2] = iVar1 - param_1[0xc];
      }
      bVar6 = (int)(uVar4 << 0x1f) < 0;
      if (bVar6) {
        uVar3 = iVar1 - (uVar3 - uVar2);
      }
      if (bVar6) {
        param_1[1] = uVar3;
      }
      *param_1 = iVar1 + uVar2;
      uVar4 = uVar4 & 0xffffffdf;
      goto LAB_00085eaa;
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  uVar4 = uVar4 | 0x20;
  param_1[10] = param_2;
LAB_00085eaa:
  param_1[3] = uVar4 & 0xfff7cfbf;
  return 0;
}

