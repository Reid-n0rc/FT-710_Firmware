// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== xTaskGenericNotify @ 00082b34 (164 bytes)

undefined4 xTaskGenericNotify(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortEnterCritical();
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x68);
  }
  cVar1 = *(char *)(param_1 + 0x6c);
  *(undefined1 *)(param_1 + 0x6c) = 2;
  switch(param_3) {
  case 0:
    break;
  case 1:
    param_2 = param_2 | *(uint *)(param_1 + 0x68);
  case 3:
switchD_00082b60_caseD_3:
    *(uint *)(param_1 + 0x68) = param_2;
    break;
  case 2:
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
    break;
  case 4:
    if (cVar1 == '\x02') {
      uVar3 = 0;
      goto LAB_00082b7e;
    }
    goto switchD_00082b60_caseD_3;
  default:
    if (*(int *)(param_1 + 0x68) != -1) {
      vPortRaiseBASEPRI();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  if (cVar1 == '\x01') {
    uxListRemove(param_1 + 4);
    uVar2 = *(uint *)(param_1 + 0x2c);
    if (DAT_0008887c < uVar2) {
      DAT_0008887c = uVar2;
    }
    vListInsertEnd(&DAT_0008880c + uVar2 * 5,param_1 + 4);
    if (*(int *)(param_1 + 0x28) != 0) {
      vPortRaiseBASEPRI();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (*(uint *)(DAT_00088800 + 0x2c) < *(uint *)(param_1 + 0x2c)) {
      vPortYield();
    }
  }
  uVar3 = 1;
LAB_00082b7e:
  vPortExitCritical();
  return uVar3;
}


// ===== prvCheckForValidListAndQueue @ 00082bec (64 bytes)

void prvCheckForValidListAndQueue(void)

{
  vPortEnterCritical();
  if (DAT_00088920 == 0) {
    vListInitialise(&DAT_000888f4);
    vListInitialise(&DAT_00088908);
    DAT_000888ec = &DAT_000888f4;
    DAT_000888f0 = &DAT_00088908;
    DAT_00088920 = xQueueGenericCreate(10,0x10,0);
    if (DAT_00088920 != 0) {
      vQueueAddToRegistry(DAT_00088920,"TmrQ");
    }
  }
  vPortExitCritical();
  return;
}


// ===== prvInsertTimerInActiveList @ 00082c44 (50 bytes)

/* [inference] */

undefined4 prvInsertTimerInActiveList(int param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  
  *(uint *)(param_1 + 4) = param_2;
  *(int *)(param_1 + 0x10) = param_1;
  if (param_3 < param_2) {
    if ((param_3 < param_4) && (param_4 <= param_2)) {
      return 1;
    }
    puVar1 = &DAT_000888ec;
  }
  else {
    param_3 = param_3 - param_4;
    if (*(uint *)(param_1 + 0x18) <= param_3) {
      return 1;
    }
    puVar1 = &DAT_000888f0;
  }
  vListInsert(*puVar1,param_1 + 4,param_3,puVar1,param_4);
  return 0;
}


// ===== xTimerCreateTimerTask @ 00082c80 (50 bytes)

void xTimerCreateTimerTask(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  prvCheckForValidListAndQueue();
  if (DAT_00088920 != 0) {
    iVar1 = xTaskCreate(0x82db1,"Tmr Svc",0x100,0,2,&DAT_00088924,param_3);
    if (iVar1 != 0) {
      return;
    }
  }
  vPortRaiseBASEPRI();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== xTimerGenericCommand @ 00082cc4 (70 bytes)

/* Posts to TmrQ 0x88920 [inference] */

void xTimerGenericCommand
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int local_20;
  int iStack_1c;
  int local_18;
  undefined4 uStack_14;
  
  uStack_14 = param_4;
  if (param_1 == 0) {
    local_20 = param_1;
    iStack_1c = param_2;
    local_18 = param_3;
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_00088920 != 0) {
    local_20 = param_2;
    iStack_1c = param_3;
    local_18 = param_1;
    if (param_2 < 6) {
      iVar1 = xTaskGetSchedulerState();
      if (iVar1 != 2) {
        param_5 = 0;
      }
      xQueueGenericSend(DAT_00088920,&local_20,param_5);
    }
    else {
      xQueueGenericSendFromISR(DAT_00088920,&local_20,param_4,0);
    }
  }
  return;
}


// ===== prvSampleTimeNow @ 00082d10 (146 bytes)

/* With prvSwitchTimerLists inlined [inference] */

uint prvSampleTimeNow(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = xTaskGetTickCount();
  if (uVar2 < DAT_0008891c) {
    while (piVar1 = DAT_000888f0, *DAT_000888ec != 0) {
      uVar6 = ((uint *)DAT_000888ec[3])[3];
      uVar7 = *(uint *)DAT_000888ec[3];
      uxListRemove(uVar6 + 4);
      (**(code **)(uVar6 + 0x20))(uVar6);
      piVar1 = DAT_000888ec;
      if ((*(byte *)(uVar6 + 0x28) & 4) != 0) {
        uVar5 = *(int *)(uVar6 + 0x18) + uVar7;
        if (uVar7 < uVar5) {
          *(uint *)(uVar6 + 4) = uVar5;
          *(uint *)(uVar6 + 0x10) = uVar6;
          vListInsert(piVar1,uVar6 + 4);
        }
        else {
          iVar3 = xTimerGenericCommand(uVar6,0,uVar7,0,0,param_2,param_3);
          if (iVar3 == 0) {
            vPortRaiseBASEPRI();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
        }
      }
    }
    DAT_000888f0 = DAT_000888ec;
    uVar4 = 1;
    DAT_000888ec = piVar1;
  }
  else {
    uVar4 = 0;
  }
  *param_1 = uVar4;
  DAT_0008891c = uVar2;
  return uVar2;
}


// ===== prvTimerTask @ 00082db0 (384 bytes)

void prvTimerTask(void)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_34 [4];
  int local_30;
  code *local_2c;
  int local_28;
  undefined4 local_24;
  
LAB_00082dba:
  iVar5 = *DAT_000888ec;
  if (iVar5 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(uint *)DAT_000888ec[3];
  }
  vTaskSuspendAll();
  uVar1 = prvSampleTimeNow(&local_30);
  if (local_30 == 0) {
    if (iVar5 == 0) {
      bVar4 = *DAT_000888f0 == 0;
    }
    else {
      bVar4 = false;
      if (uVar6 <= uVar1) {
        xTaskResumeAll();
        iVar5 = *(int *)(DAT_000888ec[3] + 0xc);
        uxListRemove(iVar5 + 4);
        if ((int)((uint)*(byte *)(iVar5 + 0x28) << 0x1d) < 0) {
          iVar2 = prvInsertTimerInActiveList(iVar5,*(int *)(iVar5 + 0x18) + uVar6,uVar1,uVar6);
          if ((iVar2 != 0) && (iVar2 = xTimerGenericCommand(iVar5,0,uVar6,0,0), iVar2 == 0)) {
            vPortRaiseBASEPRI();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
        }
        else {
          *(byte *)(iVar5 + 0x28) = *(byte *)(iVar5 + 0x28) & 0xfe;
        }
        (**(code **)(iVar5 + 0x20))(iVar5);
        goto switchD_00082e62_default;
      }
    }
    vQueueWaitForMessageRestricted(DAT_00088920,uVar6 - uVar1,bVar4);
    iVar5 = xTaskResumeAll();
    if (iVar5 == 0) {
      vPortYield();
    }
  }
  else {
    xTaskResumeAll();
  }
switchD_00082e62_default:
  do {
    iVar5 = xQueueReceive(DAT_00088920,&local_30,0);
    if (iVar5 == 0) goto LAB_00082dba;
    if ((-1 < local_30) || ((*local_2c)(local_28,local_24), -1 < local_30)) {
      iVar5 = local_28;
      if (*(int *)(local_28 + 0x14) != 0) {
        uxListRemove(local_28 + 4);
      }
      iVar2 = prvSampleTimeNow(auStack_34);
      switch(local_30) {
      case 0:
      case 1:
      case 2:
      case 6:
      case 7:
        *(byte *)(iVar5 + 0x28) = *(byte *)(iVar5 + 0x28) | 1;
        iVar2 = prvInsertTimerInActiveList(iVar5,local_2c + *(int *)(iVar5 + 0x18),iVar2);
        if (((iVar2 != 0) &&
            ((**(code **)(iVar5 + 0x20))(iVar5), (int)((uint)*(byte *)(iVar5 + 0x28) << 0x1d) < 0))
           && (iVar5 = xTimerGenericCommand(iVar5,0,local_2c + *(int *)(iVar5 + 0x18),0,0),
              iVar5 == 0)) {
          vPortRaiseBASEPRI();
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        goto switchD_00082e62_default;
      case 3:
      case 8:
        bVar3 = *(byte *)(iVar5 + 0x28);
        break;
      case 4:
      case 9:
        *(byte *)(iVar5 + 0x28) = *(byte *)(iVar5 + 0x28) | 1;
        *(code **)(iVar5 + 0x18) = local_2c;
        if (local_2c == (code *)0x0) {
          vPortRaiseBASEPRI();
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        prvInsertTimerInActiveList(iVar5,local_2c + iVar2,iVar2,iVar2);
        goto switchD_00082e62_default;
      case 5:
        bVar3 = *(byte *)(iVar5 + 0x28);
        if (-1 < (int)((uint)bVar3 << 0x1e)) {
          vPortFree(iVar5);
          goto switchD_00082e62_default;
        }
        break;
      default:
        goto switchD_00082e62_default;
      }
      *(byte *)(iVar5 + 0x28) = bVar3 & 0xfe;
    }
  } while( true );
}


// ===== CLOCK_GetOsc32KFreq @ 00082f70 (18 bytes)

/* OSC32KHZCTL0 bit0 ? 32768 : 0 [inference] */

undefined4 CLOCK_GetOsc32KFreq(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_400011c0;
  uVar2 = 0;
  if ((uVar1 & 1) != 0) {
    uVar2 = 0x8000;
  }
  return uVar2;
}


// ===== CLOCK_GetXtalInClkFreq @ 00082f88 (30 bytes)

/* SYSOSCBYPASS 0 -> g_xtalFreq (0x88930), 1 -> g_clkinFreq (0x88928) [inference] */

undefined4 CLOCK_GetXtalInClkFreq(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_40001168;
  if (iVar1 == 0) {
    puVar2 = &DAT_00088930;
  }
  else {
    iVar1 = DAT_40001168;
    if (iVar1 != 1) {
      return 0;
    }
    puVar2 = &DAT_00088928;
  }
  return *puVar2;
}


// ===== CLOCK_GetFFroFreq @ 00082fb4 (28 bytes)

/* FFROCTL0 trim range: 48 or 60 MHz [inference] */

undefined4 CLOCK_GetFFroFreq(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_40001100;
  if ((uVar1 & 0xc0000) != 0) {
    uVar2 = 60000000;
    if ((uVar1 & 0xc0000) != 0xc0000) {
      uVar2 = 0;
    }
    return uVar2;
  }
  return 48000000;
}


// ===== CLOCK_GetSysPllFreq @ 00082fdc (82 bytes)

/* SYSPLL0 source (SFRO/SYSOSC/FFRO/2) x (MULT + NUM/DENOM) [inference] */

uint CLOCK_GetSysPllFreq(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = DAT_40001200;
  uVar5 = uVar5 & 7;
  if (uVar5 == 1) {
    uVar3 = CLOCK_GetXtalInClkFreq();
  }
  else if (uVar5 == 2) {
    uVar3 = CLOCK_GetFFroFreq();
    uVar3 = uVar3 >> 1;
  }
  else {
    uVar3 = 16000000;
    if (uVar5 != 0) {
      uVar3 = 0;
    }
  }
  uVar5 = DAT_40001204;
  if ((uVar5 & 1) == 0) {
    uVar1 = DAT_40001210;
    uVar2 = DAT_40001214;
    uVar5 = DAT_40001204;
    iVar4 = __aeabi_uldivmod((int)((ulonglong)uVar3 * (ulonglong)uVar1),
                             (int)((ulonglong)uVar3 * (ulonglong)uVar1 >> 0x20),uVar2);
    uVar3 = iVar4 + uVar3 * ((uVar5 & 0xffffff) >> 0x10);
  }
  return uVar3;
}


// ===== CLOCK_GetSysPfdFreq @ 00083038 (88 bytes)

/* SYSPLL x 18 / PFDn [inference] */

uint CLOCK_GetSysPfdFreq(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = CLOCK_GetSysPllFreq();
  iVar1 = DAT_40001204;
  if (-1 < iVar1 << 0x1f) {
    switch(param_1) {
    case 0:
      uVar3 = DAT_40001218;
      uVar3 = uVar3 & 0x3f;
      break;
    case 1:
      uVar3 = DAT_40001218;
      uVar3 = (uVar3 & 0x3fff) >> 8;
      break;
    case 2:
      uVar3 = DAT_40001218;
      uVar3 = (uVar3 & 0x3fffff) >> 0x10;
      break;
    case 3:
      uVar3 = DAT_40001218;
      uVar3 = (uVar3 & 0x3fffffff) >> 0x18;
      break;
    default:
      return 0;
    }
    uVar2 = __aeabi_uldivmod((int)((ulonglong)uVar2 * 0x12),(int)((ulonglong)uVar2 * 0x12 >> 0x20),
                             uVar3,0);
  }
  return uVar2;
}


// ===== CLOCK_GetMainPllClkFreq @ 00083098 (24 bytes)

/* PFD0 / MAINPLLCLKDIV [inference] */

uint CLOCK_GetMainPllClkFreq(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = CLOCK_GetSysPfdFreq(0);
  uVar1 = DAT_40001240;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetAux0PllClkFreq @ 000830b4 (24 bytes)

/* PFD2 / AUX0PLLCLKDIV [inference] */

uint CLOCK_GetAux0PllClkFreq(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = CLOCK_GetSysPfdFreq(2);
  uVar1 = DAT_40001248;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetAux1PllClkFreq @ 000830d0 (24 bytes)

/* PFD3 / AUX1PLLCLKDIV [inference] */

uint CLOCK_GetAux1PllClkFreq(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = CLOCK_GetSysPfdFreq(3);
  uVar1 = DAT_4000124c;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetAudioPllFreq @ 000830ec (82 bytes)

/* CLKCTL1 AUDIOPLL0 (bypass returns the input) [inference] */

uint CLOCK_GetAudioPllFreq(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = DAT_40021200;
  uVar5 = uVar5 & 7;
  if (uVar5 == 1) {
    uVar3 = CLOCK_GetXtalInClkFreq();
  }
  else if (uVar5 == 2) {
    uVar3 = CLOCK_GetFFroFreq();
    uVar3 = uVar3 >> 1;
  }
  else {
    uVar3 = 16000000;
    if (uVar5 != 0) {
      uVar3 = 0;
    }
  }
  uVar5 = DAT_40021204;
  if ((uVar5 & 1) == 0) {
    uVar1 = DAT_40021210;
    uVar2 = DAT_40021214;
    uVar5 = DAT_40021204;
    iVar4 = __aeabi_uldivmod((int)((ulonglong)uVar3 * (ulonglong)uVar1),
                             (int)((ulonglong)uVar3 * (ulonglong)uVar1 >> 0x20),uVar2);
    uVar3 = iVar4 + uVar3 * ((uVar5 & 0xffffff) >> 0x10);
  }
  return uVar3;
}


// ===== CLOCK_GetAudioPfdFreq @ 00083148 (88 bytes)

/* AUDIOPLL x 18 / PFDn unless bypassed [inference] */

uint CLOCK_GetAudioPfdFreq(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = CLOCK_GetAudioPllFreq();
  iVar1 = DAT_40021204;
  if (-1 < iVar1 << 0x1f) {
    switch(param_1) {
    case 0:
      uVar3 = DAT_40021218;
      uVar3 = uVar3 & 0x3f;
      break;
    case 1:
      uVar3 = DAT_40021218;
      uVar3 = (uVar3 & 0x3fff) >> 8;
      break;
    case 2:
      uVar3 = DAT_40021218;
      uVar3 = (uVar3 & 0x3fffff) >> 0x10;
      break;
    case 3:
      uVar3 = DAT_40021218;
      uVar3 = (uVar3 & 0x3fffffff) >> 0x18;
      break;
    default:
      return 0;
    }
    uVar2 = __aeabi_uldivmod((int)((ulonglong)uVar2 * 0x12),(int)((ulonglong)uVar2 * 0x12 >> 0x20),
                             uVar3,0);
  }
  return uVar2;
}


// ===== CLOCK_GetAudioPllClkFreq @ 000831a8 (24 bytes)

/* Audio PFD0 / AUDIOPLLCLKDIV [inference] */

uint CLOCK_GetAudioPllClkFreq(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = CLOCK_GetAudioPfdFreq(0);
  uVar1 = DAT_40021240;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetMainClkFreq @ 000831c4 (92 bytes)

/* MAINCLKSELA/B [inference] */

undefined * CLOCK_GetMainClkFreq(void)

{
  undefined *puVar1;
  uint uVar2;
  
  uVar2 = DAT_40001434;
  uVar2 = uVar2 & 3;
  if (uVar2 == 2) {
    puVar1 = (undefined *)CLOCK_GetMainPllClkFreq();
    return puVar1;
  }
  if (uVar2 == 3) {
    puVar1 = (undefined *)CLOCK_GetOsc32KFreq();
    return puVar1;
  }
  if (uVar2 == 1) {
    puVar1 = (undefined *)0xf42400;
  }
  else {
    uVar2 = DAT_40001430;
    uVar2 = uVar2 & 3;
    if (uVar2 == 2) {
      puVar1 = &DAT_000f4240;
    }
    else {
      if (uVar2 == 3) {
        puVar1 = (undefined *)CLOCK_GetFFroFreq();
        return puVar1;
      }
      if (uVar2 == 1) {
        puVar1 = (undefined *)CLOCK_GetXtalInClkFreq();
        return puVar1;
      }
      uVar2 = CLOCK_GetFFroFreq();
      puVar1 = (undefined *)(uVar2 >> 2);
    }
  }
  return puVar1;
}


// ===== CLOCK_GetDspMainClkFreq @ 0008322c (106 bytes)

/* DSPCPUCLKSELA/B (CLKCTL1 0x430/0x434) [inference] */

undefined * CLOCK_GetDspMainClkFreq(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = DAT_40021434;
  uVar3 = uVar3 & 3;
  if (uVar3 == 2) {
    uVar2 = CLOCK_GetSysPfdFreq(1);
    uVar3 = DAT_40001244;
    puVar1 = (undefined *)(uVar2 / ((uVar3 & 0xff) + 1));
  }
  else {
    if (uVar3 == 3) {
      puVar1 = (undefined *)CLOCK_GetOsc32KFreq();
      return puVar1;
    }
    if (uVar3 == 1) {
      puVar1 = (undefined *)CLOCK_GetMainPllClkFreq();
      return puVar1;
    }
    uVar3 = DAT_40021430;
    uVar3 = uVar3 & 3;
    if (uVar3 == 2) {
      puVar1 = &DAT_000f4240;
    }
    else {
      if (uVar3 != 3) {
        if (uVar3 != 1) {
          puVar1 = (undefined *)CLOCK_GetFFroFreq();
          return puVar1;
        }
        puVar1 = (undefined *)CLOCK_GetXtalInClkFreq();
        return puVar1;
      }
      puVar1 = (undefined *)0xf42400;
    }
  }
  return puVar1;
}


// ===== CLOCK_GetFlexCommClkFreq @ 00083470 (238 bytes)

undefined4 CLOCK_GetFlexCommClkFreq(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_1 < 8) {
    uVar5 = *(undefined4 *)(&DAT_40021508 + param_1 * 0x20);
  }
  else if (param_1 == 0xe) {
    uVar5 = DAT_400216c8;
  }
  else {
    if (param_1 != 0xf) {
      return 16000000;
    }
    uVar5 = DAT_400216e8;
  }
  switch(uVar5) {
  case 0:
    return 16000000;
  case 1:
    uVar5 = CLOCK_GetFFroFreq();
    return uVar5;
  case 2:
    uVar5 = CLOCK_GetAudioPllClkFreq();
    return uVar5;
  case 3:
    return DAT_0008892c;
  case 4:
    break;
  default:
    return 0;
  }
  if (param_1 < 8) {
    iVar3 = param_1 * 0x20;
    bVar6 = (byte)*(undefined4 *)(&DAT_40021504 + iVar3);
    uVar4 = *(uint *)(&DAT_40021500 + iVar3) & 7;
    uVar8 = (*(uint *)(&DAT_40021504 + iVar3) & 0xffff) >> 8;
LAB_000833e4:
    uVar7 = (uint)bVar6;
    switch(uVar4) {
    case 0:
      goto switchD_000833ea_caseD_0;
    case 1:
      uVar2 = DAT_400216fc;
      uVar4 = CLOCK_GetMainPllClkFreq();
      uVar4 = uVar4 / ((uVar2 & 0xff) + 1);
      break;
    case 2:
      uVar4 = 16000000;
      break;
    case 3:
      uVar4 = CLOCK_GetFFroFreq();
      break;
    default:
      uVar4 = 0;
    }
  }
  else {
    if (param_1 == 0xe) {
      uVar4 = DAT_400216c0;
      uVar8 = DAT_400216c4;
      uVar4 = uVar4 & 7;
      uVar5 = DAT_400216c4;
      bVar6 = (byte)uVar5;
      uVar8 = (uVar8 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    if (param_1 == 0xf) {
      uVar4 = DAT_400216e0;
      uVar8 = DAT_400216e4;
      uVar4 = uVar4 & 7;
      uVar5 = DAT_400216e4;
      bVar6 = (byte)uVar5;
      uVar8 = (uVar8 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    uVar8 = 0;
    uVar7 = 0;
switchD_000833ea_caseD_0:
    uVar4 = CLOCK_GetMainClkFreq();
  }
  lVar1 = (ulonglong)(uVar7 + 1) * (ulonglong)uVar4;
  uVar5 = __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar7 + uVar8 + 1,0);
  return uVar5;
}


// ===== CLOCK_GetFreq @ 000837a8 (214 bytes)

/* WARNING: Removing unreachable block (ram,0x000835a6) */

undefined *
CLOCK_GetFreq(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;
  
  switch(param_1) {
  case 0:
  case 1:
    uVar4 = CLOCK_GetMainClkFreq();
    puVar5 = &DAT_40001000;
    goto LAB_000837d4;
  case 2:
    iVar1 = DAT_40021740;
    if (iVar1 == 0) {
      uVar4 = CLOCK_GetFFroFreq();
    }
    else {
      iVar1 = DAT_40021740;
      if (iVar1 == 1) {
        uVar4 = CLOCK_GetAudioPllClkFreq();
      }
      else {
        uVar4 = 0;
      }
    }
    uVar3 = DAT_40021744;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 3:
    uVar4 = DAT_40021764;
    puVar5 = (undefined *)(uVar4 & 7);
    switch(puVar5) {
    case (undefined *)0x0:
      uVar4 = DAT_40021760;
      switch(uVar4 & 7) {
      case 0:
        puVar5 = (undefined *)0xf42400;
        break;
      case 1:
        puVar5 = (undefined *)CLOCK_GetXtalInClkFreq();
        break;
      case 2:
        puVar5 = &DAT_000f4240;
        break;
      case 3:
        puVar5 = (undefined *)CLOCK_GetFFroFreq();
        break;
      case 4:
        puVar5 = (undefined *)CLOCK_GetMainClkFreq();
        break;
      case 6:
        puVar5 = (undefined *)CLOCK_GetDspMainClkFreq();
      }
      break;
    case (undefined *)0x1:
      puVar5 = (undefined *)CLOCK_GetMainPllClkFreq();
      break;
    case (undefined *)0x2:
      puVar5 = (undefined *)CLOCK_GetAux0PllClkFreq();
      break;
    case (undefined *)0x3:
      uVar3 = CLOCK_GetSysPfdFreq(1);
      uVar4 = DAT_40001244;
      puVar5 = (undefined *)(uVar3 / ((uVar4 & 0xff) + 1));
      break;
    case (undefined *)0x4:
      puVar5 = (undefined *)CLOCK_GetAux1PllClkFreq();
      break;
    case (undefined *)0x5:
      puVar5 = (undefined *)CLOCK_GetAudioPllClkFreq();
      break;
    case (undefined *)0x6:
      puVar5 = (undefined *)CLOCK_GetOsc32KFreq();
      break;
    default:
      puVar5 = (undefined *)0x0;
    }
    uVar4 = DAT_40021768;
    return (undefined *)((uint)puVar5 / ((uVar4 & 0xff) + 1));
  case 4:
    uVar4 = DAT_400016d4;
    puVar5 = (undefined *)(uVar4 & 7);
    switch(puVar5) {
    case (undefined *)0x0:
      uVar4 = DAT_400016d0;
      switch(uVar4 & 7) {
      case 0:
        puVar5 = (undefined *)0xf42400;
        break;
      case 1:
        puVar5 = (undefined *)CLOCK_GetXtalInClkFreq();
        break;
      case 2:
        puVar5 = &DAT_000f4240;
        break;
      case 3:
        puVar5 = (undefined *)CLOCK_GetFFroFreq();
      }
      break;
    case (undefined *)0x1:
      puVar5 = (undefined *)CLOCK_GetMainPllClkFreq();
      break;
    default:
      puVar5 = (undefined *)0x0;
      break;
    case (undefined *)0x3:
      puVar5 = (undefined *)CLOCK_GetAux0PllClkFreq();
      break;
    case (undefined *)0x5:
      puVar5 = (undefined *)CLOCK_GetAux1PllClkFreq();
    }
    uVar4 = DAT_400016d8;
    return (undefined *)((uint)puVar5 / ((uVar4 & 0xff) + 1));
  case 5:
    uVar4 = DAT_40001620;
    switch(uVar4 & 7) {
    case 0:
      uVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      uVar4 = CLOCK_GetMainPllClkFreq();
      break;
    case 2:
      uVar4 = CLOCK_GetAux0PllClkFreq();
      break;
    case 3:
      uVar4 = CLOCK_GetFFroFreq();
      break;
    case 4:
      uVar4 = CLOCK_GetAux1PllClkFreq();
      break;
    default:
      uVar4 = 0;
    }
    uVar3 = DAT_40001624;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 6:
    uVar4 = DAT_40001640;
    switch(uVar4 & 7) {
    case 0:
      uVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      uVar4 = CLOCK_GetMainPllClkFreq();
      break;
    case 2:
      uVar4 = CLOCK_GetAux0PllClkFreq();
      break;
    case 3:
      uVar4 = CLOCK_GetFFroFreq();
      break;
    case 4:
      uVar4 = CLOCK_GetAux1PllClkFreq();
      break;
    case 5:
      uVar4 = CLOCK_GetAudioPllClkFreq();
      break;
    default:
      uVar4 = 0;
    }
    uVar3 = DAT_40001644;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 7:
    uVar4 = DAT_40001720;
    if ((uVar4 & 7) == 0) {
      return &DAT_000f4240;
    }
    puVar5 = (undefined *)CLOCK_GetMainClkFreq();
    return puVar5;
  case 8:
    uVar4 = DAT_400217a0;
    if ((uVar4 & 7) != 0) {
      puVar5 = (undefined *)CLOCK_GetMainClkFreq();
      return puVar5;
    }
    return &DAT_000f4240;
  case 9:
    uVar6 = DAT_40001760;
    switch(uVar6) {
    case 0:
      uVar3 = CLOCK_GetMainClkFreq();
      uVar4 = DAT_40001764;
      puVar5 = (undefined *)(uVar3 / ((uVar4 & 0xff) + 1));
      break;
    case 1:
      puVar5 = &DAT_000f4240;
      break;
    case 2:
      puVar5 = (undefined *)CLOCK_GetOsc32KFreq();
      return puVar5;
    case 3:
      puVar5 = (undefined *)0xf42400;
      break;
    default:
      puVar5 = (undefined *)0x0;
    }
    return puVar5;
  case 10:
    bVar2 = false;
    goto LAB_00083830;
  case 0xb:
    bVar2 = true;
LAB_00083830:
    puVar8 = (uint *)&DAT_40001684;
    if (bVar2) {
      puVar8 = &DAT_40001694;
    }
    puVar7 = &DAT_40001680;
    if (bVar2) {
      puVar7 = &DAT_40001690;
    }
    switch(*puVar7 & 7) {
    case 0:
      uVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      uVar4 = CLOCK_GetMainPllClkFreq();
      break;
    case 2:
      uVar4 = CLOCK_GetAux0PllClkFreq();
      break;
    case 3:
      uVar4 = CLOCK_GetFFroFreq();
      break;
    case 4:
      uVar4 = CLOCK_GetAux1PllClkFreq();
      break;
    default:
      uVar4 = 0;
    }
    return (undefined *)(uVar4 / ((*puVar8 & 0xff) + 1));
  case 0xc:
    uVar4 = DAT_40021780;
    if ((uVar4 & 7) == 0) {
      uVar4 = CLOCK_GetMainClkFreq();
    }
    else if ((uVar4 & 7) == 1) {
      uVar4 = CLOCK_GetFFroFreq();
    }
    else {
      uVar4 = 0;
    }
    uVar3 = DAT_40021790;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 0xd:
    iVar1 = DAT_40001660;
    if (iVar1 == 0) {
      uVar4 = CLOCK_GetXtalInClkFreq();
    }
    else {
      iVar1 = DAT_40001660;
      if (iVar1 == 1) {
        uVar4 = CLOCK_GetMainClkFreq();
      }
      else {
        uVar4 = 0;
      }
    }
    uVar3 = DAT_40001664;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 0xe:
    uVar4 = DAT_40021700;
    switch(uVar4 & 7) {
    case 0:
      puVar5 = (undefined *)0xf42400;
      break;
    case 1:
      puVar5 = (undefined *)CLOCK_GetFFroFreq();
      break;
    case 2:
      puVar5 = (undefined *)CLOCK_GetAudioPllClkFreq();
      break;
    case 3:
      puVar5 = DAT_0008892c;
      break;
    case 4:
      puVar5 = &DAT_000f4240;
      break;
    case 5:
      uVar4 = DAT_40001730;
      if ((uVar4 & 7) == 0) {
        puVar5 = (undefined *)CLOCK_GetOsc32KFreq();
      }
      else {
        uVar4 = DAT_40001734;
        puVar5 = (undefined *)(1000000 / ((uVar4 & 0xff) + 1));
      }
      break;
    default:
      puVar5 = (undefined *)0x0;
    }
    uVar4 = DAT_40021704;
    return (undefined *)((uint)puVar5 / ((uVar4 & 0xff) + 1));
  case 0xf:
    uVar4 = CLOCK_GetDspMainClkFreq();
    puVar5 = &DAT_40021000;
LAB_000837d4:
    return (undefined *)(uVar4 / ((*(uint *)(puVar5 + 0x400) & 0xff) + 1));
  case 0x10:
    uVar4 = DAT_400217c0;
    switch(uVar4 & 7) {
    case 0:
      uVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      uVar4 = 16000000;
      break;
    case 2:
      uVar4 = CLOCK_GetFFroFreq();
      break;
    case 3:
      uVar4 = CLOCK_GetAux0PllClkFreq();
      break;
    case 4:
      uVar4 = CLOCK_GetAux1PllClkFreq();
      break;
    default:
      uVar4 = 0;
    }
    uVar3 = DAT_400217c4;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 0x11:
    uVar6 = 0;
    break;
  case 0x12:
    uVar6 = 1;
    break;
  case 0x13:
    uVar6 = 2;
    break;
  case 0x14:
    uVar6 = 3;
    break;
  case 0x15:
    uVar6 = 4;
    break;
  case 0x16:
    uVar6 = 5;
    break;
  case 0x17:
    uVar6 = 6;
    break;
  case 0x18:
    uVar6 = 7;
    break;
  case 0x19:
    uVar6 = 0xe;
    break;
  case 0x1a:
    uVar6 = 0xf;
    break;
  default:
    return (undefined *)0x0;
  }
  puVar5 = (undefined *)CLOCK_GetFlexCommClkFreq(uVar6,param_2,param_3,param_4);
  return puVar5;
}


// ===== CLOCK_SetFRGClock @ 000838a8 (70 bytes)

/* FRGnCLKSEL/FRGnCTL for FC0..7, 14, 15 [inference] */

void CLOCK_SetFRGClock(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1;
  if (uVar1 < 8) {
    *(uint *)(&DAT_40021500 + uVar1 * 0x20) = (uint)param_1[1];
    *(uint *)(&DAT_40021504 + uVar1 * 0x20) = (uint)*(ushort *)(param_1 + 2);
    return;
  }
  if (uVar1 == 0xe) {
    DAT_400216c0 = (uint)param_1[1];
    DAT_400216c4 = (uint)*(ushort *)(param_1 + 2);
    return;
  }
  if (uVar1 == 0xf) {
    DAT_400216e0 = (uint)param_1[1];
    DAT_400216e4 = (uint)*(ushort *)(param_1 + 2);
  }
  return;
}


// ===== CLOCK_EnableFfroClk @ 000838f4 (170 bytes)

/* FFRO trim from OTP via ROM otp_init/otp_fuse_read/otp_deinit (0x13009FF9/0x1300A057/0x1300A047)
   [inference] */

void CLOCK_EnableFfroClk(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14 [2];
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14[0] = 0;
  uVar3 = DAT_40001104;
  DAT_40001104 = uVar3 | 1;
  uVar1 = CLOCK_GetMainClkFreq();
  uVar3 = DAT_40001400;
  (*(code *)0x13009ff9)(uVar1 / ((uVar3 & 0xff) + 1));
  if (param_1 == 0) {
    (*(code *)0x1300a057)(0x30);
    (*(code *)0x1300a057)(0x31,&local_1c);
    uVar2 = 0x32;
  }
  else {
    (*(code *)0x1300a057)(0x33,&local_20);
    (*(code *)0x1300a057)(0x34,&local_1c);
    uVar2 = 0x35;
  }
  (*(code *)0x1300a057)(uVar2,&local_18);
  (*(code *)0x1300a057)(0xc,local_14);
  (*(code *)0x1300a047)();
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0000;
  }
  DAT_40001100 = (local_1c & 0x3f) << 5 | (local_18 & 0x7f) << 0xb | local_20 & 0x1f | uVar3;
  uVar3 = DAT_40001104;
  DAT_40001104 = uVar3 & 0xfffffffe;
  SDK_DelayAtLeastUs(local_14[0],300000000);
  return;
}


// ===== CLOCK_EnableSfroClk @ 000839b4 (56 bytes)

/* SFRO enable, OTP fuse 0x0D settling delay [inference] */

void CLOCK_EnableSfroClk(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 extraout_r2;
  undefined4 local_c;
  
  local_c = 0;
  uVar2 = CLOCK_GetMainClkFreq();
  uVar1 = DAT_40001400;
  (*(code *)0x13009ff9)(uVar2 / ((uVar1 & 0xff) + 1));
  (*(code *)0x1300a057)(0xd,&local_c,extraout_r2,0x1300a057,param_1);
  (*(code *)0x1300a047)();
  SDK_DelayAtLeastUs(local_c,300000000);
  return;
}


// ===== CLOCK_InitSysPll @ 000839fc (242 bytes)

/* Power SYSPLL, set source/NUM/DENOM/MULT, lock-time delays [inference] */

void CLOCK_InitSysPll(byte *param_1)

{
  uint uVar1;
  
  DAT_40002620 = 0x60000;
  DAT_40001200 = (uint)*param_1;
  DAT_40001210 = *(undefined4 *)(param_1 + 4);
  DAT_40001214 = *(undefined4 *)(param_1 + 8);
  switch(param_1[0xc]) {
  case 0:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x100000;
    break;
  case 1:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x110000;
    break;
  case 2:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x120000;
    break;
  case 3:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x130000;
    break;
  case 4:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x140000;
    break;
  case 5:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x150000;
    break;
  case 6:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x160000;
    break;
  default:
    goto switchD_00083a22_default;
  }
  DAT_40001204 = uVar1;
switchD_00083a22_default:
  uVar1 = DAT_40001204;
  DAT_40001204 = uVar1 & 0xfffffffd;
  DAT_40002630 = 0x60000;
  uVar1 = DAT_4000120c;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) >> 1,300000000);
  uVar1 = DAT_40001204;
  DAT_40001204 = uVar1 | 0x2000;
  uVar1 = DAT_4000120c;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) / 6,300000000);
  uVar1 = DAT_40001204;
  DAT_40001204 = uVar1 & 0xffffdfff;
  uVar1 = DAT_4000120c;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) / 3,300000000);
  return;
}


// ===== CLOCK_InitSysPfd @ 00083b04 (66 bytes)

/* SYSPLL0PFD n: set divider, wait stable [inference] */

void CLOCK_InitSysPfd(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << 3;
  uVar2 = DAT_40001218;
  uVar2 = uVar2 & ~(0xbf << (uVar1 & 0xff));
  DAT_40001218 = 0x80 << (uVar1 & 0xff) | uVar2;
  DAT_40001218 = (param_2 & 0x3f) << (uVar1 & 0xff) | uVar2;
  uVar2 = 0x40 << (uVar1 & 0xff);
  do {
    uVar1 = DAT_40001218;
  } while ((uVar1 & uVar2) == 0);
  uVar1 = DAT_40001218;
  DAT_40001218 = uVar2 | uVar1;
  return;
}


// ===== CLOCK_InitAudioPll @ 00083b4c (242 bytes)

/* Same for AUDIOPLL0 (CLKCTL1) [inference] */

void CLOCK_InitAudioPll(byte *param_1)

{
  uint uVar1;
  
  DAT_40002620 = 0x180000;
  DAT_40021200 = (uint)*param_1;
  DAT_40021210 = *(undefined4 *)(param_1 + 4);
  DAT_40021214 = *(undefined4 *)(param_1 + 8);
  switch(param_1[0xc]) {
  case 0:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x100000;
    break;
  case 1:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x110000;
    break;
  case 2:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x120000;
    break;
  case 3:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x130000;
    break;
  case 4:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x140000;
    break;
  case 5:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x150000;
    break;
  case 6:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x160000;
    break;
  default:
    goto switchD_00083b72_default;
  }
  DAT_40021204 = uVar1;
switchD_00083b72_default:
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 & 0xfffffffd;
  DAT_40002630 = 0x180000;
  uVar1 = DAT_4002120c;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) >> 1,300000000);
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 | 0x2000;
  uVar1 = DAT_4002120c;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) / 6,300000000);
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 & 0xffffdfff;
  uVar1 = DAT_4002120c;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) / 3,300000000);
  return;
}


// ===== CLOCK_InitAudioPfd @ 00083c54 (66 bytes)

/* AUDIOPLL0PFD n [inference] */

void CLOCK_InitAudioPfd(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << 3;
  uVar2 = DAT_40021218;
  uVar2 = uVar2 & ~(0xbf << (uVar1 & 0xff));
  DAT_40021218 = 0x80 << (uVar1 & 0xff) | uVar2;
  DAT_40021218 = (param_2 & 0x3f) << (uVar1 & 0xff) | uVar2;
  uVar2 = 0x40 << (uVar1 & 0xff);
  do {
    uVar1 = DAT_40021218;
  } while ((uVar1 & uVar2) == 0);
  uVar1 = DAT_40021218;
  DAT_40021218 = uVar2 | uVar1;
  return;
}


// ===== CLOCK_EnableSysOscClk @ 00083c9c (32 bytes)

/* SYSOSCCTL0 = mode, SYSOSCBYPASS = 0, delay [inference] */

void CLOCK_EnableSysOscClk(int param_1,uint param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    DAT_40001160 = param_2;
    DAT_40001168 = 0;
    SDK_DelayAtLeastUs(param_3,300000000);
    return;
  }
  DAT_40001160 = param_2 | 2;
  return;
}


// ===== SDK_DelayAtLeastUs @ 00083cc4 (28 bytes)

/* Busy loop: us x 300 MHz / 4e6 iterations [inference] */

void SDK_DelayAtLeastUs(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = __aeabi_uldivmod((int)((ulonglong)param_1 * (ulonglong)param_2),
                             (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20),&DAT_003d0900,0,
                             param_4);
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ===== DMA_GetInstance @ 00083d40 (24 bytes)

/* 0x40104000 -> 0, 0x40105000 -> 1 [fact] */

undefined4 DMA_GetInstance(undefined *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == &DAT_40104000) {
    return 0;
  }
  if (param_1 == &DAT_40105000) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


// ===== DMA_IRQHandle @ 00083d5c (176 bytes)

/* NEW. fsl_dma.c channel interrupt dispatcher (33 channels); unused (DMA IRQs never enabled by the
   M33) [inference] */

void DMA_IRQHandle(void)

{
  int iVar1;
  uint uVar2;
  undefined4 in_r3;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  code *pcVar7;
  
  iVar1 = DMA_GetInstance();
  iVar6 = 0;
  piVar5 = (int *)(&DAT_00088948 + iVar1 * 0x84);
  do {
    puVar3 = (undefined4 *)*piVar5;
    if (puVar3 != (undefined4 *)0x0) {
      uVar2 = (uint)(*(byte *)(puVar3 + 3) >> 5);
      uVar4 = *(byte *)(puVar3 + 3) & 0x1f;
      if ((int)((*(uint *)(puVar3[2] + 0x58 + uVar2 * 4) >> uVar4) << 0x1f) < 0) {
        pcVar7 = (code *)*puVar3;
        *(int *)(puVar3[2] + 0x58 + uVar2 * 4) = 1 << uVar4;
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)(puVar3,puVar3[1],1,0,in_r3);
        }
      }
      if ((int)((*(uint *)(puVar3[2] + 0x60 + (uint)(*(byte *)(puVar3 + 3) >> 5) * 4) >> uVar4) <<
               0x1f) < 0) {
        pcVar7 = (code *)*puVar3;
        *(int *)(puVar3[2] + 0x60 + (uint)(*(byte *)(puVar3 + 3) >> 5) * 4) = 1 << uVar4;
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)(puVar3,puVar3[1],1);
        }
      }
      if ((int)((*(uint *)(puVar3[2] + 0x40 + (uint)(*(byte *)(puVar3 + 3) >> 5) * 4) >> uVar4) <<
               0x1f) < 0) {
        *(int *)(puVar3[2] + 0x40 + (uint)(*(byte *)(puVar3 + 3) >> 5) * 4) = 1 << uVar4;
        if ((code *)*puVar3 != (code *)0x0) {
          (*(code *)*puVar3)(puVar3,puVar3[1],0,2);
        }
      }
    }
    iVar6 = iVar6 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar6 != 0x21);
  return;
}


// ===== DMA0_DriverIRQHandler @ 00083e10 (6 bytes)

/* IRQ1 -> DMA_IRQHandle(DMA0) [fact: vector] */

void DMA0_DriverIRQHandler(void)

{
  DMA_IRQHandle(&DAT_40104000);
  return;
}


// ===== DMA1_DriverIRQHandler @ 00083e1c (6 bytes)

/* IRQ54 [fact: vector] */

void DMA1_DriverIRQHandler(void)

{
  DMA_IRQHandle(&DAT_40105000);
  return;
}


// ===== DMIC0_DriverIRQHandler @ 00083e28 (10 bytes)

/* IRQ25 [fact: vector] */

void DMIC0_DriverIRQHandler(void)

{
  if (DAT_00088a50 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083e2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_00088a50)();
    return;
  }
  return;
}


// ===== HWVAD0_DriverIRQHandler @ 00083e38 (10 bytes)

/* IRQ29 [fact: vector] */

void HWVAD0_DriverIRQHandler(void)

{
  if (DAT_00088a54 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083e3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_00088a54)();
    return;
  }
  return;
}


// ===== DSP_Init @ 00083e48 (190 bytes)

/* WARNING: Removing unreachable block (ram,0x00084574) */
/* fsl_dsp.c: if PDRUNCFG1 DSP cache/TCM bits set, clear them (PDRUNCFG1_CLR), POWER_ApplyPD,
   release DSP reset [inference] */

void DSP_Init(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_40002614;
  if ((uVar2 & 0xf000000) != 0) {
    DAT_40002634 = 0x4000000;
    DAT_40002634 = 0x8000000;
    DAT_40002634 = 0x1000000;
    DAT_40002634 = 0x2000000;
    POWER_ApplyPD();
    RESET_ClearPeripheralReset(1);
    return;
  }
  iVar1 = DAT_40000010;
  if (iVar1 << 0x1e < 0) {
    DAT_40000070 = 2;
    do {
      uVar2 = DAT_40000010;
    } while ((~uVar2 & 2) == 0);
    return;
  }
  return;
}


// ===== FLEXCOMM_GetInstance @ 00083ea0 (22 bytes)

/* Search of 10 FLEXCOMM bases at 0x879D0 [fact] */

void FLEXCOMM_GetInstance(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_000879d0;
  do {
    if (*piVar2 == param_1) {
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 != 10);
  return;
}


// ===== FLEXCOMM_Init @ 00083ebc (180 bytes)

/* Clock enable + reset release from table 0x87B28, PSELID (base+0xFF8) [inference] */

undefined4 FLEXCOMM_Init(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uVar5;
  
  iVar2 = FLEXCOMM_GetInstance();
  uVar1 = *(ushort *)(&DAT_00087b28 + iVar2 * 2);
  uVar5 = (uint)uVar1;
  switch(uVar1 >> 8) {
  case 0:
    puVar4 = &DAT_40001000;
    break;
  case 1:
    uVar5 = (uint)(byte)uVar1;
    puVar4 = &DAT_40001000;
    goto LAB_00083f2a;
  case 2:
    puVar4 = &DAT_40001000;
    goto LAB_00083f38;
  case 3:
    puVar4 = &DAT_40021000;
    break;
  case 4:
    uVar5 = uVar5 & 0xff;
    puVar4 = &DAT_40021000;
LAB_00083f2a:
    *(int *)(puVar4 + 0x44) = 1 << uVar5;
    goto switchD_00083ed2_default;
  case 5:
    puVar4 = &DAT_40021000;
LAB_00083f38:
    *(int *)(puVar4 + 0x48) = 1 << (uVar5 & 0xff);
  default:
    goto switchD_00083ed2_default;
  }
  *(int *)(puVar4 + 0x40) = 1 << (uVar5 & 0xff);
switchD_00083ed2_default:
  RESET_ClearPeripheralReset(*(undefined2 *)(&DAT_00087b28 + iVar2 * 2));
  if (param_2 == 0) {
LAB_00083f04:
    if ((*(int *)(param_1 + 0xff8) << 0x1c < 0) && ((*(uint *)(param_1 + 0xff8) & 7) != param_2)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
      *(uint *)(param_1 + 0xff8) = param_2;
    }
  }
  else {
    if (param_2 < 5) {
      uVar5 = *(uint *)(param_1 + 0xff8) >> (param_2 + 3 & 0xff) & 1;
LAB_00083f02:
      if (uVar5 != 0) goto LAB_00083f04;
    }
    else if (param_2 == 5) {
      uVar5 = *(uint *)(param_1 + 0xff8) & 0x80;
      goto LAB_00083f02;
    }
    uVar3 = 3;
  }
  return uVar3;
}


// ===== FLEXCOMM1_DriverIRQHandler @ 00083f88 (32 bytes)

/* IRQ15, generic fsl_flexcomm handler [fact: vector] */

void FLEXCOMM1_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40107000);
                    /* WARNING: Could not recover jumptable at 0x00083fa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM2_DriverIRQHandler @ 00083fb8 (32 bytes)

/* IRQ16 [fact: vector] */

void FLEXCOMM2_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40108000);
                    /* WARNING: Could not recover jumptable at 0x00083fd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM3_DriverIRQHandler @ 00083fe8 (32 bytes)

/* IRQ17 [fact: vector] */

void FLEXCOMM3_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40109000);
                    /* WARNING: Could not recover jumptable at 0x00084006. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM4_DriverIRQHandler @ 00084018 (32 bytes)

/* IRQ18 [fact: vector] */

void FLEXCOMM4_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40122000);
                    /* WARNING: Could not recover jumptable at 0x00084036. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM5_DriverIRQHandler @ 00084048 (32 bytes)

/* IRQ19 [fact: vector] */

void FLEXCOMM5_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40123000);
                    /* WARNING: Could not recover jumptable at 0x00084066. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM6_DriverIRQHandler @ 00084078 (32 bytes)

/* IRQ43 [fact: vector] */

void FLEXCOMM6_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40124000);
                    /* WARNING: Could not recover jumptable at 0x00084096. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM7_DriverIRQHandler @ 000840a8 (32 bytes)

/* IRQ44 [fact: vector] */

void FLEXCOMM7_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40125000);
                    /* WARNING: Could not recover jumptable at 0x000840c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM14_DriverIRQHandler @ 000840d8 (32 bytes)

/* IRQ20 [fact: vector] */

void FLEXCOMM14_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40126000);
                    /* WARNING: Could not recover jumptable at 0x000840f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXCOMM15_DriverIRQHandler @ 00084108 (32 bytes)

/* IRQ21 [fact: vector] */

void FLEXCOMM15_DriverIRQHandler(void)

{
  int iVar1;
  
  iVar1 = FLEXCOMM_GetInstance(&DAT_40127000);
                    /* WARNING: Could not recover jumptable at 0x00084126. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + iVar1 * 4))
            ((&DAT_000879d0)[iVar1],*(undefined4 *)(&DAT_00088a58 + iVar1 * 4));
  return;
}


// ===== FLEXSPI_DriverIRQHandler @ 00084138 (12 bytes)

/* IRQ42 [fact: vector] */

void FLEXSPI_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x00084142. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088aac)(&DAT_40134000,DAT_00088aa8);
  return;
}

