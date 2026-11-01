// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== uxTaskResetEventItemValue @ 00082ab0 (20 bytes)

/* [inference] */

uint uxTaskResetEventItemValue(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_00088800 + 0x18);
  *(int *)(DAT_00088800 + 0x18) = 5 - *(int *)(DAT_00088800 + 0x2c);
  return uVar1;
}


// ===== pvTaskIncrementMutexHeldCount @ 00082ac8 (18 bytes)

/* [inference] */

int pvTaskIncrementMutexHeldCount(void)

{
  if (DAT_00088800 != 0) {
    *(int *)(DAT_00088800 + 0x50) = *(int *)(DAT_00088800 + 0x50) + 1;
  }
  return DAT_00088800;
}


// ===== ulTaskNotifyTake @ 00082ae0 (80 bytes)

int ulTaskNotifyTake(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  vPortEnterCritical();
  if ((*(int *)(DAT_00088800 + 0x68) == 0) &&
     (*(undefined1 *)(DAT_00088800 + 0x6c) = 1, param_2 != 0)) {
    prvAddCurrentTaskToDelayedList(param_2,1);
    vPortYield();
  }
  vPortExitCritical();
  vPortEnterCritical();
  iVar2 = *(int *)(DAT_00088800 + 0x68);
  if (iVar2 != 0) {
    if (param_1 == 0) {
      iVar1 = iVar2 + -1;
    }
    else {
      iVar1 = 0;
    }
    *(int *)(DAT_00088800 + 0x68) = iVar1;
  }
  *(undefined1 *)(DAT_00088800 + 0x6c) = 0;
  vPortExitCritical();
  return iVar2;
}


// ===== xTaskGenericNotify @ 00082b34 (164 bytes)

undefined4 xTaskGenericNotify(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    ulSetInterruptMask();
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
      ulSetInterruptMask();
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
      ulSetInterruptMask();
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
      vQueueAddToRegistry(DAT_00088920,0x87cdd);
    }
  }
  vPortExitCritical();
  return;
}


// ===== prvInsertTimerInActiveList @ 00082c44 (50 bytes)

/* [inference] */

uint prvInsertTimerInActiveList(int param_1,uint param_2,uint param_3,uint param_4)

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
    if (*(uint *)(param_1 + 0x18) <= param_3 - param_4) {
      return 1;
    }
    puVar1 = &DAT_000888f0;
  }
  vListInsert((int *)*puVar1,(uint *)(param_1 + 4));
  return 0;
}


// ===== xTimerCreateTimerTask @ 00082c80 (50 bytes)

void xTimerCreateTimerTask(void)

{
  uint xTaskCreate_ret;
  
  prvCheckForValidListAndQueue();
  if (DAT_00088920 != 0) {
    xTaskCreate_ret = xTaskCreate(0x82db1,0x87ce2,0x100,0,2,(int *)&DAT_00088924);
    if (xTaskCreate_ret != 0) {
      return;
    }
  }
  ulSetInterruptMask();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== xTimerGenericCommand @ 00082cc4 (70 bytes)

/* Posts to TmrQ 0x88920 [inference] */

uint xTimerGenericCommand(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int local_20;
  uint uStack_1c;
  uint local_18;
  uint uStack_14;
  
  uStack_14 = param_4;
  if (param_1 == 0) {
    local_20 = param_1;
    uStack_1c = param_2;
    local_18 = param_3;
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar1 = 0;
  if (DAT_00088920 != 0) {
    local_20 = param_2;
    uStack_1c = param_3;
    local_18 = param_1;
    if (param_2 < 6) {
      uVar1 = xTaskGetSchedulerState();
      if (uVar1 != 2) {
        param_5 = 0;
      }
      uVar1 = xQueueGenericSend(DAT_00088920,(int)&local_20,param_5,0);
    }
    else {
      uVar1 = xQueueGenericSendFromISR(DAT_00088920,(int)&local_20,(void *)param_4,0);
    }
  }
  return uVar1;
}


// ===== prvSampleTimeNow @ 00082d10 (146 bytes)

/* With prvSwitchTimerLists inlined [inference] */

uint prvSampleTimeNow(undefined4 *param_1)

{
  int *piVar1;
  uint xTaskGetTickCount_ret;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  xTaskGetTickCount_ret = xTaskGetTickCount();
  if (xTaskGetTickCount_ret < DAT_0008891c) {
    while (piVar1 = DAT_000888f0, *DAT_000888ec != 0) {
      uVar4 = ((uint *)DAT_000888ec[3])[3];
      uVar5 = *(uint *)DAT_000888ec[3];
      uxListRemove((uint *)(uVar4 + 4));
      (**(code **)(uVar4 + 0x20))(uVar4);
      piVar1 = DAT_000888ec;
      if ((*(byte *)(uVar4 + 0x28) & 4) != 0) {
        uVar3 = *(int *)(uVar4 + 0x18) + uVar5;
        if (uVar5 < uVar3) {
          *(uint *)(uVar4 + 4) = uVar3;
          *(uint *)(uVar4 + 0x10) = uVar4;
          vListInsert(piVar1,(uint *)(uVar4 + 4));
        }
        else {
          uVar4 = xTimerGenericCommand(uVar4,0,uVar5,0,0);
          if (uVar4 == 0) {
            ulSetInterruptMask();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
        }
      }
    }
    DAT_000888f0 = DAT_000888ec;
    uVar2 = 1;
    DAT_000888ec = piVar1;
  }
  else {
    uVar2 = 0;
  }
  *param_1 = uVar2;
  DAT_0008891c = xTaskGetTickCount_ret;
  return xTaskGetTickCount_ret;
}


// ===== prvTimerTask @ 00082db0 (384 bytes)

void prvTimerTask(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_34 [4];
  int local_30;
  code *local_2c;
  int local_28;
  undefined4 local_24;
  
LAB_00082dba:
  iVar4 = *DAT_000888ec;
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(uint *)DAT_000888ec[3];
  }
  vTaskSuspendAll();
  uVar1 = prvSampleTimeNow(&local_30);
  if (local_30 == 0) {
    if (iVar4 == 0) {
      uVar3 = (uint)(*DAT_000888f0 == 0);
    }
    else {
      uVar3 = 0;
      if (uVar5 <= uVar1) {
        xTaskResumeAll();
        iVar4 = *(int *)(DAT_000888ec[3] + 0xc);
        uxListRemove(iVar4 + 4);
        if ((int)((uint)*(byte *)(iVar4 + 0x28) << 0x1d) < 0) {
          uVar1 = prvInsertTimerInActiveList(iVar4,*(int *)(iVar4 + 0x18) + uVar5,uVar1,uVar5);
          if ((uVar1 != 0) && (uVar5 = xTimerGenericCommand(iVar4,0,uVar5,0,0), uVar5 == 0)) {
            ulSetInterruptMask();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
        }
        else {
          *(byte *)(iVar4 + 0x28) = *(byte *)(iVar4 + 0x28) & 0xfe;
        }
        (**(code **)(iVar4 + 0x20))(iVar4);
        goto switchD_00082e62_default;
      }
    }
    vQueueWaitForMessageRestricted(DAT_00088920,uVar5 - uVar1,uVar3);
    uVar5 = xTaskResumeAll();
    if (uVar5 == 0) {
      vPortYield();
    }
  }
  else {
    xTaskResumeAll();
  }
switchD_00082e62_default:
  do {
    iVar4 = xQueueReceive(DAT_00088920,&local_30,0);
    if (iVar4 == 0) goto LAB_00082dba;
    if ((-1 < local_30) || ((*local_2c)(local_28,local_24), -1 < local_30)) {
      iVar4 = local_28;
      if (*(int *)(local_28 + 0x14) != 0) {
        uxListRemove(local_28 + 4);
      }
      uVar5 = prvSampleTimeNow(auStack_34);
      switch(local_30) {
      case 0:
      case 1:
      case 2:
      case 6:
      case 7:
        *(byte *)(iVar4 + 0x28) = *(byte *)(iVar4 + 0x28) | 1;
        uVar5 = prvInsertTimerInActiveList
                          (iVar4,(uint)(local_2c + *(int *)(iVar4 + 0x18)),uVar5,(uint)local_2c);
        if (((uVar5 != 0) &&
            ((**(code **)(iVar4 + 0x20))(iVar4), (int)((uint)*(byte *)(iVar4 + 0x28) << 0x1d) < 0))
           && (uVar5 = xTimerGenericCommand(iVar4,0,(uint)(local_2c + *(int *)(iVar4 + 0x18)),0,0),
              uVar5 == 0)) {
          ulSetInterruptMask();
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        goto switchD_00082e62_default;
      case 3:
      case 8:
        bVar2 = *(byte *)(iVar4 + 0x28);
        break;
      case 4:
      case 9:
        *(byte *)(iVar4 + 0x28) = *(byte *)(iVar4 + 0x28) | 1;
        *(code **)(iVar4 + 0x18) = local_2c;
        if (local_2c == (code *)0x0) {
          ulSetInterruptMask();
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        prvInsertTimerInActiveList(iVar4,(uint)(local_2c + uVar5),uVar5,uVar5);
        goto switchD_00082e62_default;
      case 5:
        bVar2 = *(byte *)(iVar4 + 0x28);
        if (-1 < (int)((uint)bVar2 << 0x1e)) {
          vPortFree(iVar4);
          goto switchD_00082e62_default;
        }
        break;
      default:
        goto switchD_00082e62_default;
      }
      *(byte *)(iVar4 + 0x28) = bVar2 & 0xfe;
    }
  } while( true );
}


// ===== xTimerPendFunctionCallFromISR @ 00082f48 (34 bytes)

/* NEW (entries_m33.tsv): byte-identical to xTimerPendFunctionCallFromISR of FreeRTOS-Kernel
   MCUX_2.9.0 timers.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24 round 2) */

int xTimerPendFunctionCallFromISR
              (void *xFunctionToPend,void *pvParameter1,uint ulParameter2,
              int *pxHigherPriorityTaskWoken)

{
  uint xQueueGenericSendFromISR_ret;
  undefined4 local_18;
  void *pvStack_14;
  void *local_10;
  uint uStack_c;
  
  local_18 = 0xfffffffe;
  pvStack_14 = xFunctionToPend;
  local_10 = pvParameter1;
  uStack_c = ulParameter2;
  xQueueGenericSendFromISR_ret =
       xQueueGenericSendFromISR(DAT_00088920,(int)&local_18,pxHigherPriorityTaskWoken,0);
  return xQueueGenericSendFromISR_ret;
}


// ===== CLOCK_GetOsc32KFreq @ 00082f70 (18 bytes)

/* OSC32KHZCTL0 bit 0 ? 32768 : 0 [fact: 0x82F70]; same as CLOCK_GetOsc32KFreq in mcux-sdk@8a289764
   devices/MIMXRT685S/drivers/fsl_clock.c [inference] */

undefined4 CLOCK_GetOsc32KFreq(void)

{
  undefined4 uVar1;
  uint clkctl0_osc32khzctl0;
  
                    /* 32k oscillator control0 [sfr] */
  clkctl0_osc32khzctl0 = CLKCTL0_OSC32KHZCTL0;
  uVar1 = 0;
  if ((clkctl0_osc32khzctl0 & 1) != 0) {
    uVar1 = 0x8000;
  }
  return uVar1;
}


// ===== CLOCK_GetXtalInClkFreq @ 00082f88 (30 bytes)

/* SYSOSCBYPASS 0 -> word 0x88930, 1 -> word 0x88928, else 0 [fact: 0x82F88]; same as
   CLOCK_GetXtalInClkFreq (g_xtalFreq / g_clkinFreq) in mcux-sdk@8a289764 fsl_clock.c [inference] */

undefined4 CLOCK_GetXtalInClkFreq(void)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* system oscillator bypass [sfr] */
  iVar1 = CLKCTL0_SYSOSCBYPASS;
  if (iVar1 == 0) {
    puVar2 = &DAT_00088930;
  }
  else {
    iVar1 = CLKCTL0_SYSOSCBYPASS;
    if (iVar1 != 1) {
      return 0;
    }
    puVar2 = &DAT_00088928;
  }
  return *puVar2;
}


// ===== CLOCK_GetFFroFreq @ 00082fb4 (28 bytes)

/* FFROCTL0 trim range: 48 or 60 MHz [inference] */

uint CLOCK_GetFFroFreq(void)

{
  uint uVar1;
  uint clkctl0_ffroctl0;
  
                    /* FFRO control 0 [sfr] */
  clkctl0_ffroctl0 = CLKCTL0_FFROCTL0;
  if ((clkctl0_ffroctl0 & 0xc0000) != 0) {
    uVar1 = 60000000;
    if ((clkctl0_ffroctl0 & 0xc0000) != 0xc0000) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 48000000;
}


// ===== CLOCK_GetSysPllFreq @ 00082fdc (82 bytes)

/* SYSPLL0 source (SFRO/SYSOSC/FFRO/2) x (MULT + NUM/DENOM) [inference] */

uint CLOCK_GetSysPllFreq(void)

{
  uint uVar1;
  uint uVar2;
  ulonglong __aeabi_uldivmod_ret;
  uint clkctl0_syspll0ctl0;
  undefined4 clkctl0_syspll0denom;
  uint clkctl0_syspll0num;
  
                    /* system pll0 clock selection [sfr] */
  uVar2 = CLKCTL0_SYSPLL0CLKSEL;
  uVar2 = uVar2 & 7;
  if (uVar2 == 1) {
    uVar1 = CLOCK_GetXtalInClkFreq();
  }
  else if (uVar2 == 2) {
    uVar1 = CLOCK_GetFFroFreq();
    uVar1 = uVar1 >> 1;
  }
  else {
    uVar1 = 16000000;
    if (uVar2 != 0) {
      uVar1 = 0;
    }
  }
                    /* system pll0 control0 [sfr] */
  uVar2 = CLKCTL0_SYSPLL0CTL0;
  if ((uVar2 & 1) == 0) {
                    /* system pll0 number [sfr] */
    clkctl0_syspll0num = CLKCTL0_SYSPLL0NUM;
                    /* system pll0 denom [sfr] */
    clkctl0_syspll0denom = CLKCTL0_SYSPLL0DENOM;
    clkctl0_syspll0ctl0 = CLKCTL0_SYSPLL0CTL0;
    __aeabi_uldivmod_ret =
         __aeabi_uldivmod((ulonglong)uVar1 * (ulonglong)clkctl0_syspll0num,
                          CONCAT44(uVar2,clkctl0_syspll0denom) & 0x1ffffffff);
    uVar1 = (int)__aeabi_uldivmod_ret + uVar1 * ((clkctl0_syspll0ctl0 & 0xffffff) >> 0x10);
  }
  return uVar1;
}


// ===== CLOCK_GetSysPfdFreq @ 00083038 (88 bytes)

/* SYSPLL x 18 / PFDn [inference] */

uint CLOCK_GetSysPfdFreq(uint param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong __aeabi_uldivmod_ret;
  int clkctl0_syspll0ctl0;
  
  uVar1 = CLOCK_GetSysPllFreq();
                    /* system pll0 control0 [sfr] */
  clkctl0_syspll0ctl0 = CLKCTL0_SYSPLL0CTL0;
  if (-1 < clkctl0_syspll0ctl0 << 0x1f) {
    switch(param_1) {
    case 0:
                    /* sys pll0 PFD [sfr] */
      uVar2 = CLKCTL0_SYSPLL0PFD;
      uVar2 = uVar2 & 0x3f;
      break;
    case 1:
      uVar2 = CLKCTL0_SYSPLL0PFD;
      uVar2 = (uVar2 & 0x3fff) >> 8;
      break;
    case 2:
      uVar2 = CLKCTL0_SYSPLL0PFD;
      uVar2 = (uVar2 & 0x3fffff) >> 0x10;
      break;
    case 3:
      uVar2 = CLKCTL0_SYSPLL0PFD;
      uVar2 = (uVar2 & 0x3fffffff) >> 0x18;
      break;
    default:
      return 0;
    }
    __aeabi_uldivmod_ret = __aeabi_uldivmod((ulonglong)uVar1 * 0x12,(ulonglong)uVar2);
    uVar1 = (uint)__aeabi_uldivmod_ret;
  }
  return uVar1;
}


// ===== CLOCK_GetMainPllClkFreq @ 00083098 (24 bytes)

/* PFD0 / MAINPLLCLKDIV [inference] */

uint CLOCK_GetMainPllClkFreq(void)

{
  uint CLOCK_GetSysPfdFreq_ret;
  uint clkctl0_mainpllclkdiv;
  
  CLOCK_GetSysPfdFreq_ret = CLOCK_GetSysPfdFreq(0);
                    /* main pll clk divider [sfr] */
  clkctl0_mainpllclkdiv = CLKCTL0_MAINPLLCLKDIV;
  return CLOCK_GetSysPfdFreq_ret / ((clkctl0_mainpllclkdiv & 0xff) + 1);
}


// ===== CLOCK_GetAux0PllClkFreq @ 000830b4 (24 bytes)

/* PFD2 / AUX0PLLCLKDIV [inference] */

uint CLOCK_GetAux0PllClkFreq(void)

{
  uint CLOCK_GetSysPfdFreq_ret;
  uint clkctl0_aux0pllclkdiv;
  
  CLOCK_GetSysPfdFreq_ret = CLOCK_GetSysPfdFreq(2);
                    /* aux0 pll clk divider [sfr] */
  clkctl0_aux0pllclkdiv = CLKCTL0_AUX0PLLCLKDIV;
  return CLOCK_GetSysPfdFreq_ret / ((clkctl0_aux0pllclkdiv & 0xff) + 1);
}


// ===== CLOCK_GetAux1PllClkFreq @ 000830d0 (24 bytes)

/* PFD3 / AUX1PLLCLKDIV [inference] */

uint CLOCK_GetAux1PllClkFreq(void)

{
  uint CLOCK_GetSysPfdFreq_ret;
  uint clkctl0_aux1pllclkdiv;
  
  CLOCK_GetSysPfdFreq_ret = CLOCK_GetSysPfdFreq(3);
                    /* aux1 pll clk divider [sfr] */
  clkctl0_aux1pllclkdiv = CLKCTL0_AUX1PLLCLKDIV;
  return CLOCK_GetSysPfdFreq_ret / ((clkctl0_aux1pllclkdiv & 0xff) + 1);
}


// ===== CLOCK_GetAudioPllFreq @ 000830ec (82 bytes)

/* CLKCTL1 AUDIOPLL0 (bypass returns the input) [inference] */

uint CLOCK_GetAudioPllFreq(void)

{
  uint uVar1;
  uint uVar2;
  ulonglong __aeabi_uldivmod_ret;
  uint clkctl1_audiopll0ctl0;
  undefined4 clkctl1_audiopll0denom;
  uint clkctl1_audiopll0num;
  
                    /* audio pll0 clock selection [sfr] */
  uVar2 = CLKCTL1_AUDIOPLL0CLKSEL;
  uVar2 = uVar2 & 7;
  if (uVar2 == 1) {
    uVar1 = CLOCK_GetXtalInClkFreq();
  }
  else if (uVar2 == 2) {
    uVar1 = CLOCK_GetFFroFreq();
    uVar1 = uVar1 >> 1;
  }
  else {
    uVar1 = 16000000;
    if (uVar2 != 0) {
      uVar1 = 0;
    }
  }
                    /* audio pll0 control0 [sfr] */
  uVar2 = CLKCTL1_AUDIOPLL0CTL0;
  if ((uVar2 & 1) == 0) {
                    /* audio pll0 number [sfr] */
    clkctl1_audiopll0num = CLKCTL1_AUDIOPLL0NUM;
                    /* Audio pll0 denom [sfr] */
    clkctl1_audiopll0denom = CLKCTL1_AUDIOPLL0DENOM;
    clkctl1_audiopll0ctl0 = CLKCTL1_AUDIOPLL0CTL0;
    __aeabi_uldivmod_ret =
         __aeabi_uldivmod((ulonglong)uVar1 * (ulonglong)clkctl1_audiopll0num,
                          CONCAT44(uVar2,clkctl1_audiopll0denom) & 0x1ffffffff);
    uVar1 = (int)__aeabi_uldivmod_ret + uVar1 * ((clkctl1_audiopll0ctl0 & 0xffffff) >> 0x10);
  }
  return uVar1;
}


// ===== CLOCK_GetAudioPfdFreq @ 00083148 (88 bytes)

/* AUDIOPLL x 18 / PFDn unless bypassed [inference] */

uint CLOCK_GetAudioPfdFreq(uint param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong __aeabi_uldivmod_ret;
  int clkctl1_audiopll0ctl0;
  
  uVar1 = CLOCK_GetAudioPllFreq();
                    /* audio pll0 control0 [sfr] */
  clkctl1_audiopll0ctl0 = CLKCTL1_AUDIOPLL0CTL0;
  if (-1 < clkctl1_audiopll0ctl0 << 0x1f) {
    switch(param_1) {
    case 0:
                    /* audio pll0 PFD [sfr] */
      uVar2 = CLKCTL1_AUDIOPLL0PFD;
      uVar2 = uVar2 & 0x3f;
      break;
    case 1:
      uVar2 = CLKCTL1_AUDIOPLL0PFD;
      uVar2 = (uVar2 & 0x3fff) >> 8;
      break;
    case 2:
      uVar2 = CLKCTL1_AUDIOPLL0PFD;
      uVar2 = (uVar2 & 0x3fffff) >> 0x10;
      break;
    case 3:
      uVar2 = CLKCTL1_AUDIOPLL0PFD;
      uVar2 = (uVar2 & 0x3fffffff) >> 0x18;
      break;
    default:
      return 0;
    }
    __aeabi_uldivmod_ret = __aeabi_uldivmod((ulonglong)uVar1 * 0x12,(ulonglong)uVar2);
    uVar1 = (uint)__aeabi_uldivmod_ret;
  }
  return uVar1;
}


// ===== CLOCK_GetAudioPllClkFreq @ 000831a8 (24 bytes)

/* Audio PFD0 / AUDIOPLLCLKDIV [inference] */

uint CLOCK_GetAudioPllClkFreq(void)

{
  uint CLOCK_GetAudioPfdFreq_ret;
  uint clkctl1_audiopllclkdiv;
  
  CLOCK_GetAudioPfdFreq_ret = CLOCK_GetAudioPfdFreq(0);
                    /* audio pll0 clock divider [sfr] */
  clkctl1_audiopllclkdiv = CLKCTL1_AUDIOPLLCLKDIV;
  return CLOCK_GetAudioPfdFreq_ret / ((clkctl1_audiopllclkdiv & 0xff) + 1);
}


// ===== CLOCK_GetMainClkFreq @ 000831c4 (92 bytes)

/* MAINCLKSELA/B [inference] */

void * CLOCK_GetMainClkFreq(void)

{
  undefined *puVar1;
  void *pvVar2;
  uint uVar3;
  
                    /* main clock selection B [sfr] */
  uVar3 = CLKCTL0_MAINCLKSELB;
  uVar3 = uVar3 & 3;
  if (uVar3 == 2) {
    pvVar2 = (void *)CLOCK_GetMainPllClkFreq();
    return pvVar2;
  }
  if (uVar3 == 3) {
    pvVar2 = (void *)CLOCK_GetOsc32KFreq();
    return pvVar2;
  }
  if (uVar3 == 1) {
    puVar1 = (undefined *)0xf42400;
  }
  else {
    uVar3 = CLKCTL0_MAINCLKSELA;
    uVar3 = uVar3 & 3;
    if (uVar3 == 2) {
      puVar1 = &DAT_000f4240;
    }
    else {
      if (uVar3 == 3) {
        pvVar2 = (void *)CLOCK_GetFFroFreq();
        return pvVar2;
      }
      if (uVar3 == 1) {
        pvVar2 = (void *)CLOCK_GetXtalInClkFreq();
        return pvVar2;
      }
      uVar3 = CLOCK_GetFFroFreq();
      puVar1 = (undefined *)(uVar3 >> 2);
    }
  }
  return puVar1;
}


// ===== CLOCK_GetDspMainClkFreq @ 0008322c (106 bytes)

/* DSPCPUCLKSELA/B (CLKCTL1 0x430/0x434) [inference] */

undefined * CLOCK_GetDspMainClkFreq(void)

{
  undefined *puVar1;
  uint CLOCK_GetSysPfdFreq_ret;
  uint uVar2;
  
                    /* DSP clock selection B [sfr] */
  uVar2 = CLKCTL1_DSPCPUCLKSELB;
  uVar2 = uVar2 & 3;
  if (uVar2 == 2) {
    CLOCK_GetSysPfdFreq_ret = CLOCK_GetSysPfdFreq(1);
                    /* dsp pll clk divider [sfr] */
    uVar2 = CLKCTL0_DSPPLLCLKDIV;
    puVar1 = (undefined *)(CLOCK_GetSysPfdFreq_ret / ((uVar2 & 0xff) + 1));
  }
  else {
    if (uVar2 == 3) {
      puVar1 = (undefined *)CLOCK_GetOsc32KFreq();
      return puVar1;
    }
    if (uVar2 == 1) {
      puVar1 = (undefined *)CLOCK_GetMainPllClkFreq();
      return puVar1;
    }
    uVar2 = CLKCTL1_DSPCPUCLKSELA;
    uVar2 = uVar2 & 3;
    if (uVar2 == 2) {
      puVar1 = &DAT_000f4240;
    }
    else {
      if (uVar2 != 3) {
        if (uVar2 != 1) {
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


// ===== CLOCK_GetAdcClkFreq @ 000832a8 (90 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetAdcClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetAdcClkFreq(void)

{
  uint uVar1;
  undefined *puVar2;
  
                    /* ADC0 fclk selection 1 [sfr] */
  uVar1 = CLKCTL0_ADC0FCLKSEL1;
  puVar2 = (undefined *)(uVar1 & 7);
  switch(puVar2) {
  case (undefined *)0x0:
                    /* ADC0 fclk selection 0 [sfr] */
    uVar1 = CLKCTL0_ADC0FCLKSEL0;
    switch(uVar1 & 7) {
    case 0:
      puVar2 = (undefined *)0xf42400;
      break;
    case 1:
      puVar2 = (undefined *)CLOCK_GetXtalInClkFreq();
      break;
    case 2:
      puVar2 = &DAT_000f4240;
      break;
    case 3:
      puVar2 = (undefined *)CLOCK_GetFFroFreq();
    }
    break;
  case (undefined *)0x1:
    puVar2 = (undefined *)CLOCK_GetMainPllClkFreq();
    break;
  default:
    puVar2 = (undefined *)0x0;
    break;
  case (undefined *)0x3:
    puVar2 = (undefined *)CLOCK_GetAux0PllClkFreq();
    break;
  case (undefined *)0x5:
    puVar2 = (undefined *)CLOCK_GetAux1PllClkFreq();
  }
                    /* ADC0 fclk divider [sfr] */
  uVar1 = CLKCTL0_ADC0FCLKDIV;
  return (uint)puVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetClockOutClkFreq @ 00083318 (136 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetClockOutClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetClockOutClkFreq(void)

{
  uint uVar1;
  undefined *puVar2;
  uint CLOCK_GetSysPfdFreq_ret;
  
                    /* clock out selection 1 [sfr] */
  uVar1 = CLKCTL1_CLKOUTSEL1;
  puVar2 = (undefined *)(uVar1 & 7);
  switch(puVar2) {
  case (undefined *)0x0:
                    /* clock out selection 0 [sfr] */
    uVar1 = CLKCTL1_CLKOUTSEL0;
    switch(uVar1 & 7) {
    case 0:
      puVar2 = (undefined *)0xf42400;
      break;
    case 1:
      puVar2 = (undefined *)CLOCK_GetXtalInClkFreq();
      break;
    case 2:
      puVar2 = &DAT_000f4240;
      break;
    case 3:
      puVar2 = (undefined *)CLOCK_GetFFroFreq();
      break;
    case 4:
      puVar2 = CLOCK_GetMainClkFreq();
      break;
    case 6:
      puVar2 = (undefined *)CLOCK_GetDspMainClkFreq();
    }
    break;
  case (undefined *)0x1:
    puVar2 = (undefined *)CLOCK_GetMainPllClkFreq();
    break;
  case (undefined *)0x2:
    puVar2 = (undefined *)CLOCK_GetAux0PllClkFreq();
    break;
  case (undefined *)0x3:
    CLOCK_GetSysPfdFreq_ret = CLOCK_GetSysPfdFreq(1);
                    /* dsp pll clk divider [sfr] */
    uVar1 = CLKCTL0_DSPPLLCLKDIV;
    puVar2 = (undefined *)(CLOCK_GetSysPfdFreq_ret / ((uVar1 & 0xff) + 1));
    break;
  case (undefined *)0x4:
    puVar2 = (undefined *)CLOCK_GetAux1PllClkFreq();
    break;
  case (undefined *)0x5:
    puVar2 = (undefined *)CLOCK_GetAudioPllClkFreq();
    break;
  case (undefined *)0x6:
    puVar2 = (undefined *)CLOCK_GetOsc32KFreq();
    break;
  default:
    puVar2 = (undefined *)0x0;
  }
                    /* clock_out divider [sfr] */
  uVar1 = CLKCTL1_CLKOUTDIV;
  return (uint)puVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetFRGClock @ 000833c0 (162 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetFRGClock of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetFRGClock(uint id)

{
  undefined4 uVar1;
  void *pvVar2;
  uint CLOCK_GetMainPllClkFreq_ret;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  ulonglong __aeabi_uldivmod_ret;
  
  if (id < 8) {
    bVar4 = (byte)(&CLKCTL1_FLEXCOMM0_FRGCTL)[id * 8];
    uVar3 = (&CLKCTL1_FLEXCOMM0_FRGCLKSEL)[id * 8] & 7;
    uVar6 = ((&CLKCTL1_FLEXCOMM0_FRGCTL)[id * 8] & 0xffff) >> 8;
LAB_000833e4:
    uVar5 = (uint)bVar4;
    switch(uVar3) {
    case 0:
      goto switchD_000833ea_caseD_0;
    case 1:
                    /* FRG pll clock divider [sfr] */
      uVar3 = CLKCTL1_FRGPLLCLKDIV;
      CLOCK_GetMainPllClkFreq_ret = CLOCK_GetMainPllClkFreq();
      pvVar2 = (void *)(CLOCK_GetMainPllClkFreq_ret / ((uVar3 & 0xff) + 1));
      break;
    case 2:
      pvVar2 = (void *)0xf42400;
      break;
    case 3:
      pvVar2 = (void *)CLOCK_GetFFroFreq();
      break;
    default:
      pvVar2 = (void *)0x0;
    }
  }
  else {
    if (id == 0xe) {
                    /* FRG clock selection 14 [sfr] */
      uVar3 = CLKCTL1_FRG14CLKSEL;
                    /* FRG clock controller 14 [sfr] */
      uVar6 = CLKCTL1_FRG14CTL;
      uVar3 = uVar3 & 7;
      uVar1 = CLKCTL1_FRG14CTL;
      bVar4 = (byte)uVar1;
      uVar6 = (uVar6 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    if (id == 0xf) {
                    /* FRG clock selection 15 [sfr] */
      uVar3 = CLKCTL1_FRG15CLKSEL;
                    /* FRG clock controller 15 [sfr] */
      uVar6 = CLKCTL1_FRG15CTL;
      uVar3 = uVar3 & 7;
      uVar1 = CLKCTL1_FRG15CTL;
      bVar4 = (byte)uVar1;
      uVar6 = (uVar6 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    uVar6 = 0;
    uVar5 = 0;
switchD_000833ea_caseD_0:
    pvVar2 = CLOCK_GetMainClkFreq();
  }
  __aeabi_uldivmod_ret =
       __aeabi_uldivmod((ulonglong)(uVar5 + 1) * ZEXT48(pvVar2),(ulonglong)(uVar5 + uVar6 + 1));
  return (uint)__aeabi_uldivmod_ret;
}


// ===== CLOCK_GetFlexCommClkFreq @ 00083470 (76 bytes)

uint CLOCK_GetFlexCommClkFreq(uint id)

{
  uint uVar1;
  dword dVar2;
  
  if (id < 8) {
    dVar2 = (&CLKCTL1_FLEXCOMM0_FCFCLKSEL)[id * 8];
  }
  else if (id == 0xe) {
                    /* flexcomm14 clock selection [sfr] */
    dVar2 = CLKCTL1_FC14FCLKSEL;
  }
  else {
    if (id != 0xf) {
switchD_00083486_caseD_0:
      return 16000000;
    }
                    /* flexcomm15 clock selection [sfr] */
    dVar2 = CLKCTL1_FC15FCLKSEL;
  }
  switch(dVar2) {
  case 0:
    goto switchD_00083486_caseD_0;
  case 1:
    uVar1 = CLOCK_GetFFroFreq();
    return uVar1;
  case 2:
    uVar1 = CLOCK_GetAudioPllClkFreq();
    return uVar1;
  case 3:
    return DAT_0008892c;
  case 4:
                    /* fractional rate generator output clock [doc] */
    uVar1 = CLOCK_GetFRGClock(id);
    return uVar1;
  default:
    return 0;
  }
}


// ===== CLOCK_GetFlexspiClkFreq @ 000834d0 (66 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetFlexspiClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)];
   Ghidra had merged it into CLOCK_GetFlexCommClkFreq [fact: 0x834D0] (T24 round 2) */

uint CLOCK_GetFlexspiClkFreq(void)

{
  uint uVar1;
  void *pvVar2;
  
                    /* FlexSPI FCLK selection [sfr] */
  uVar1 = CLKCTL0_FLEXSPIFCLKSEL;
  switch(uVar1 & 7) {
  case 0:
    pvVar2 = CLOCK_GetMainClkFreq();
    break;
  case 1:
    pvVar2 = (void *)CLOCK_GetMainPllClkFreq();
    break;
  case 2:
    pvVar2 = (void *)CLOCK_GetAux0PllClkFreq();
    break;
  case 3:
    pvVar2 = (void *)CLOCK_GetFFroFreq();
    break;
  case 4:
    pvVar2 = (void *)CLOCK_GetAux1PllClkFreq();
    break;
  default:
    pvVar2 = (void *)0x0;
  }
                    /* FlexSPI FCLK divider [sfr] */
  uVar1 = CLKCTL0_FLEXSPIFCLKDIV;
  return (uint)pvVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetSctClkFreq @ 0008351c (72 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetSctClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)];
   Ghidra had merged it into CLOCK_GetFlexCommClkFreq [fact: 0x8351C] (T24 round 2) */

uint CLOCK_GetSctClkFreq(void)

{
  uint uVar1;
  void *pvVar2;
  
                    /* SCT FCLK selection [sfr] */
  uVar1 = CLKCTL0_SCTFCLKSEL;
  switch(uVar1 & 7) {
  case 0:
    pvVar2 = CLOCK_GetMainClkFreq();
    break;
  case 1:
    pvVar2 = (void *)CLOCK_GetMainPllClkFreq();
    break;
  case 2:
    pvVar2 = (void *)CLOCK_GetAux0PllClkFreq();
    break;
  case 3:
    pvVar2 = (void *)CLOCK_GetFFroFreq();
    break;
  case 4:
    pvVar2 = (void *)CLOCK_GetAux1PllClkFreq();
    break;
  case 5:
    pvVar2 = (void *)CLOCK_GetAudioPllClkFreq();
    break;
  default:
    pvVar2 = (void *)0x0;
  }
                    /* SCT fclk divider [sfr] */
  uVar1 = CLKCTL0_SCTFCLKDIV;
  return (uint)pvVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetMclkClkFreq @ 00083570 (46 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetMclkClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetMclkClkFreq(void)

{
  int iVar1;
  uint uVar2;
  uint clkctl1_audiomclkdiv;
  
                    /* audio mclock selection [sfr] */
  iVar1 = CLKCTL1_AUDIOMCLKSEL;
  if (iVar1 == 0) {
    uVar2 = CLOCK_GetFFroFreq();
  }
  else {
    iVar1 = CLKCTL1_AUDIOMCLKSEL;
    if (iVar1 == 1) {
      uVar2 = CLOCK_GetAudioPllClkFreq();
    }
    else {
      uVar2 = 0;
    }
  }
                    /* audio mclock divider [sfr] */
  clkctl1_audiomclkdiv = CLKCTL1_AUDIOMCLKDIV;
  return uVar2 / ((clkctl1_audiomclkdiv & 0xff) + 1);
}


// ===== CLOCK_GetWdtClkFreq @ 000835a4 (28 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetWdtClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetWdtClkFreq(uint id)

{
  void *CLOCK_GetMainClkFreq_ret;
  uint uVar1;
  
  if (id == 0) {
                    /* wdt clock selection [sfr] */
    uVar1 = CLKCTL0_WDT0FCLKSEL;
  }
  else {
                    /* WDT1 clock selection [sfr] */
    uVar1 = CLKCTL1_WDT1FCLKSEL;
  }
  if ((uVar1 & 7) != 0) {
    CLOCK_GetMainClkFreq_ret = CLOCK_GetMainClkFreq();
    return (uint)CLOCK_GetMainClkFreq_ret;
  }
  return 1000000;
}


// ===== CLOCK_GetSystickClkFreq @ 000835cc (54 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetSystickClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetSystickClkFreq(void)

{
  void *CLOCK_GetMainClkFreq_ret;
  uint uVar1;
  undefined *puVar2;
  undefined4 clkctl0_systickfclksel;
  
                    /* system tick fclk selection [sfr] */
  clkctl0_systickfclksel = CLKCTL0_SYSTICKFCLKSEL;
  switch(clkctl0_systickfclksel) {
  case 0:
    CLOCK_GetMainClkFreq_ret = CLOCK_GetMainClkFreq();
                    /* system tick fclk divider [sfr] */
    uVar1 = CLKCTL0_SYSTICKFCLKDIV;
    puVar2 = (undefined *)((uint)CLOCK_GetMainClkFreq_ret / ((uVar1 & 0xff) + 1));
    break;
  case 1:
    puVar2 = &DAT_000f4240;
    break;
  case 2:
    uVar1 = CLOCK_GetOsc32KFreq();
    return uVar1;
  case 3:
    puVar2 = (undefined *)0xf42400;
    break;
  default:
    puVar2 = (undefined *)0x0;
  }
  return (uint)puVar2;
}


// ===== CLOCK_GetSdioClkFreq @ 00083614 (80 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetSdioClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetSdioClkFreq(uint id)

{
  void *pvVar1;
  uint *puVar2;
  dword *pdVar3;
  
  pdVar3 = &CLKCTL0_SDIO0FCLKDIV;
  if (id != 0) {
    pdVar3 = &CLKCTL0_SDIO1FCLKDIV;
  }
  puVar2 = &CLKCTL0_SDIO0FCLKSEL;
  if (id != 0) {
    puVar2 = &CLKCTL0_SDIO1FCLKSEL;
  }
  switch(*puVar2 & 7) {
  case 0:
    pvVar1 = CLOCK_GetMainClkFreq();
    break;
  case 1:
    pvVar1 = (void *)CLOCK_GetMainPllClkFreq();
    break;
  case 2:
    pvVar1 = (void *)CLOCK_GetAux0PllClkFreq();
    break;
  case 3:
    pvVar1 = (void *)CLOCK_GetFFroFreq();
    break;
  case 4:
    pvVar1 = (void *)CLOCK_GetAux1PllClkFreq();
    break;
  default:
    pvVar1 = (void *)0x0;
  }
  return (uint)pvVar1 / ((*pdVar3 & 0xff) + 1);
}


// ===== CLOCK_GetI3cClkFreq @ 00083678 (46 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetI3cClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetI3cClkFreq(void)

{
  uint uVar1;
  void *pvVar2;
  
                    /* I3C0 fclk selection [sfr] */
  uVar1 = CLKCTL1_I3C0FCLKSEL;
  if ((uVar1 & 7) == 0) {
    pvVar2 = CLOCK_GetMainClkFreq();
  }
  else if ((uVar1 & 7) == 1) {
    pvVar2 = (void *)CLOCK_GetFFroFreq();
  }
  else {
    pvVar2 = (void *)0x0;
  }
                    /* I3C0 fclk divider [sfr] */
  uVar1 = CLKCTL1_I3C0FCLKDIV;
  return (uint)pvVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetUsbClkFreq @ 000836ac (46 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetUsbClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetUsbClkFreq(void)

{
  int iVar1;
  void *pvVar2;
  uint clkctl0_usbhsfclkdiv;
  
                    /* USBHS Fclk selection [sfr] */
  iVar1 = CLKCTL0_USBHSFCLKSEL;
  if (iVar1 == 0) {
    pvVar2 = (void *)CLOCK_GetXtalInClkFreq();
  }
  else {
    iVar1 = CLKCTL0_USBHSFCLKSEL;
    if (iVar1 == 1) {
      pvVar2 = CLOCK_GetMainClkFreq();
    }
    else {
      pvVar2 = (void *)0x0;
    }
  }
                    /* USBHS Fclk divider [sfr] */
  clkctl0_usbhsfclkdiv = CLKCTL0_USBHSFCLKDIV;
  return (uint)pvVar2 / ((clkctl0_usbhsfclkdiv & 0xff) + 1);
}


// ===== CLOCK_GetDmicClkFreq @ 000836e0 (94 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetDmicClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetDmicClkFreq(void)

{
  uint uVar1;
  undefined *puVar2;
  
                    /* DMIC0 clk selection [sfr] */
  uVar1 = CLKCTL1_DMIC0FCLKSEL;
  switch(uVar1 & 7) {
  case 0:
    puVar2 = (undefined *)0xf42400;
    break;
  case 1:
    puVar2 = (undefined *)CLOCK_GetFFroFreq();
    break;
  case 2:
    puVar2 = (undefined *)CLOCK_GetAudioPllClkFreq();
    break;
  case 3:
    puVar2 = DAT_0008892c;
    break;
  case 4:
    puVar2 = &DAT_000f4240;
    break;
  case 5:
                    /* 32k wake clock selection [sfr] */
    uVar1 = CLKCTL0_WAKECLK32KHZSEL;
    if ((uVar1 & 7) == 0) {
      puVar2 = (undefined *)CLOCK_GetOsc32KFreq();
    }
    else {
                    /* 32k wake clock divider [sfr] */
      uVar1 = CLKCTL0_WAKECLK32KHZDIV;
      puVar2 = (undefined *)(1000000 / ((uVar1 & 0xff) + 1));
    }
    break;
  default:
    puVar2 = (undefined *)0x0;
  }
                    /* DMIC clock clock divider [sfr] */
  uVar1 = CLKCTL1_DMIC0FCLKDIV;
  return (uint)puVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetAcmpClkFreq @ 00083758 (64 bytes)

/* NEW (entries_m33.tsv): byte-identical to CLOCK_GetAcmpClkFreq of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_clock.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24
   round 2) */

uint CLOCK_GetAcmpClkFreq(void)

{
  uint uVar1;
  void *pvVar2;
  
                    /* acomparator 0 clock selection [sfr] */
  uVar1 = CLKCTL1_ACMP0FCLKSEL;
  switch(uVar1 & 7) {
  case 0:
    pvVar2 = CLOCK_GetMainClkFreq();
    break;
  case 1:
    pvVar2 = (void *)0xf42400;
    break;
  case 2:
    pvVar2 = (void *)CLOCK_GetFFroFreq();
    break;
  case 3:
    pvVar2 = (void *)CLOCK_GetAux0PllClkFreq();
    break;
  case 4:
    pvVar2 = (void *)CLOCK_GetAux1PllClkFreq();
    break;
  default:
    pvVar2 = (void *)0x0;
  }
                    /* acomparator 0 fclk divider [sfr] */
  uVar1 = CLKCTL1_ACMP0FCLKDIV;
  return (uint)pvVar2 / ((uVar1 & 0xff) + 1);
}


// ===== CLOCK_GetFreq @ 000837a8 (214 bytes)

undefined * CLOCK_GetFreq(undefined4 param_1)

{
  void *pvVar1;
  undefined *puVar2;
  uint uVar3;
  dword *pdVar4;
  
  switch(param_1) {
  case 0:
  case 1:
    pvVar1 = CLOCK_GetMainClkFreq();
    pdVar4 = &CLKCTL0_BASE;
    goto LAB_000837d4;
  case 2:
    puVar2 = (undefined *)CLOCK_GetMclkClkFreq();
    return puVar2;
  case 3:
                    /* clock frequency of the ClockOut function clock [doc] */
    puVar2 = (undefined *)CLOCK_GetClockOutClkFreq();
    return puVar2;
  case 4:
    puVar2 = (undefined *)CLOCK_GetAdcClkFreq();
    return puVar2;
  case 5:
    puVar2 = (undefined *)CLOCK_GetFlexspiClkFreq();
    return puVar2;
  case 6:
    puVar2 = (undefined *)CLOCK_GetSctClkFreq();
    return puVar2;
  case 7:
    uVar3 = CLKCTL0_WDT0FCLKSEL;
    if ((uVar3 & 7) == 0) {
      return &DAT_000f4240;
    }
    puVar2 = CLOCK_GetMainClkFreq();
    return puVar2;
  case 8:
    puVar2 = (undefined *)CLOCK_GetWdtClkFreq(1);
    return puVar2;
  case 9:
    puVar2 = (undefined *)CLOCK_GetSystickClkFreq();
    return puVar2;
  case 10:
    uVar3 = 0;
    goto LAB_00083830;
  case 0xb:
    uVar3 = 1;
LAB_00083830:
    puVar2 = (undefined *)CLOCK_GetSdioClkFreq(uVar3);
    return puVar2;
  case 0xc:
    puVar2 = (undefined *)CLOCK_GetI3cClkFreq();
    return puVar2;
  case 0xd:
    puVar2 = (undefined *)CLOCK_GetUsbClkFreq();
    return puVar2;
  case 0xe:
    puVar2 = (undefined *)CLOCK_GetDmicClkFreq();
    return puVar2;
  case 0xf:
    pvVar1 = (void *)CLOCK_GetDspMainClkFreq();
    pdVar4 = &CLKCTL1_BASE;
LAB_000837d4:
    return (undefined *)((uint)pvVar1 / ((pdVar4[0x100] & 0xff) + 1));
  case 0x10:
    puVar2 = (undefined *)CLOCK_GetAcmpClkFreq();
    return puVar2;
  case 0x11:
    uVar3 = 0;
    break;
  case 0x12:
    uVar3 = 1;
    break;
  case 0x13:
    uVar3 = 2;
    break;
  case 0x14:
    uVar3 = 3;
    break;
  case 0x15:
    uVar3 = 4;
    break;
  case 0x16:
    uVar3 = 5;
    break;
  case 0x17:
    uVar3 = 6;
    break;
  case 0x18:
    uVar3 = 7;
    break;
  case 0x19:
    uVar3 = 0xe;
    break;
  case 0x1a:
    uVar3 = 0xf;
    break;
  default:
    return (undefined *)0x0;
  }
  puVar2 = (undefined *)CLOCK_GetFlexCommClkFreq(uVar3);
  return puVar2;
}


// ===== CLOCK_SetFRGClock @ 000838a8 (70 bytes)

/* FRGnCLKSEL/FRGnCTL for FC0..7, 14, 15 [inference] */

void CLOCK_SetFRGClock(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1;
  if (uVar1 < 8) {
    (&CLKCTL1_FLEXCOMM0_FRGCLKSEL)[uVar1 * 8] = (uint)param_1[1];
    (&CLKCTL1_FLEXCOMM0_FRGCTL)[uVar1 * 8] = (uint)*(ushort *)(param_1 + 2);
    return;
  }
  if (uVar1 == 0xe) {
                    /* FRG clock selection 14 [sfr] */
    CLKCTL1_FRG14CLKSEL = (uint)param_1[1];
                    /* FRG clock controller 14 [sfr] */
    CLKCTL1_FRG14CTL = (uint)*(ushort *)(param_1 + 2);
    return;
  }
  if (uVar1 == 0xf) {
                    /* FRG clock selection 15 [sfr] */
    CLKCTL1_FRG15CLKSEL = (uint)param_1[1];
                    /* FRG clock controller 15 [sfr] */
    CLKCTL1_FRG15CTL = (uint)*(ushort *)(param_1 + 2);
  }
  return;
}


// ===== CLOCK_EnableFfroClk @ 000838f4 (170 bytes)

/* FFRO trim from OTP via ROM otp_init/otp_fuse_read/otp_deinit (0x13009FF9/0x1300A057/0x1300A047)
   [inference] */

void CLOCK_EnableFfroClk(int param_1)

{
  void *CLOCK_GetMainClkFreq_ret;
  undefined4 uVar1;
  uint uVar2;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14 [2];
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14[0] = 0;
                    /* FFRO control 1 [sfr] */
  uVar2 = CLKCTL0_FFROCTL1;
  CLKCTL0_FFROCTL1 = uVar2 | 1;
  CLOCK_GetMainClkFreq_ret = CLOCK_GetMainClkFreq();
                    /* system cpu AHB clock divider [sfr] */
  uVar2 = CLKCTL0_SYSCPUAHBCLKDIV;
  (*(code *)0x13009ff9)((uint)CLOCK_GetMainClkFreq_ret / ((uVar2 & 0xff) + 1));
  if (param_1 == 0) {
    (*(code *)0x1300a057)(0x30);
    (*(code *)0x1300a057)(0x31,&local_1c);
    uVar1 = 0x32;
  }
  else {
    (*(code *)0x1300a057)(0x33,&local_20);
    (*(code *)0x1300a057)(0x34,&local_1c);
    uVar1 = 0x35;
  }
  (*(code *)0x1300a057)(uVar1,&local_18);
  (*(code *)0x1300a057)(0xc,local_14);
  (*(code *)0x1300a047)();
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000;
  }
                    /* FFRO control 0 [sfr] */
  CLKCTL0_FFROCTL0 = (local_1c & 0x3f) << 5 | (local_18 & 0x7f) << 0xb | local_20 & 0x1f | uVar2;
  uVar2 = CLKCTL0_FFROCTL1;
  CLKCTL0_FFROCTL1 = uVar2 & 0xfffffffe;
  SDK_DelayAtLeastUs(local_14[0],300000000);
  return;
}


// ===== CLOCK_EnableSfroClk @ 000839b4 (56 bytes)

/* SFRO enable, OTP fuse 0x0D settling delay [inference] */

void CLOCK_EnableSfroClk(undefined4 param_1)

{
  void *CLOCK_GetMainClkFreq_ret;
  undefined4 extraout_r2;
  undefined4 local_c;
  uint clkctl0_syscpuahbclkdiv;
  
  local_c = 0;
  CLOCK_GetMainClkFreq_ret = CLOCK_GetMainClkFreq();
                    /* system cpu AHB clock divider [sfr] */
  clkctl0_syscpuahbclkdiv = CLKCTL0_SYSCPUAHBCLKDIV;
  (*(code *)0x13009ff9)((uint)CLOCK_GetMainClkFreq_ret / ((clkctl0_syscpuahbclkdiv & 0xff) + 1));
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
  
                    /* Run configuration 0 set [sfr] */
  SYSCTL0_PDRUNCFG0_SET = 0x60000;
                    /* system pll0 clock selection [sfr] */
  CLKCTL0_SYSPLL0CLKSEL = (uint)*param_1;
                    /* system pll0 number [sfr] */
  CLKCTL0_SYSPLL0NUM = *(undefined4 *)(param_1 + 4);
                    /* system pll0 denom [sfr] */
  CLKCTL0_SYSPLL0DENOM = *(undefined4 *)(param_1 + 8);
  switch(param_1[0xc]) {
  case 0:
                    /* system pll0 control0 [sfr] */
    uVar1 = CLKCTL0_SYSPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x100000;
    break;
  case 1:
    uVar1 = CLKCTL0_SYSPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x110000;
    break;
  case 2:
    uVar1 = CLKCTL0_SYSPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x120000;
    break;
  case 3:
    uVar1 = CLKCTL0_SYSPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x130000;
    break;
  case 4:
    uVar1 = CLKCTL0_SYSPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x140000;
    break;
  case 5:
    uVar1 = CLKCTL0_SYSPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x150000;
    break;
  case 6:
    uVar1 = CLKCTL0_SYSPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x160000;
    break;
  default:
    goto switchD_00083a22_default;
  }
  CLKCTL0_SYSPLL0CTL0 = uVar1;
switchD_00083a22_default:
  uVar1 = CLKCTL0_SYSPLL0CTL0;
  CLKCTL0_SYSPLL0CTL0 = uVar1 & 0xfffffffd;
                    /* Run configuration 0 clear [sfr] */
  SYSCTL0_PDRUNCFG0_CLR = 0x60000;
                    /* system pll0 lock time [sfr] */
  uVar1 = CLKCTL0_SYSPLL0LOCKTIMEDIV2;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) >> 1,300000000);
  uVar1 = CLKCTL0_SYSPLL0CTL0;
  CLKCTL0_SYSPLL0CTL0 = uVar1 | 0x2000;
  uVar1 = CLKCTL0_SYSPLL0LOCKTIMEDIV2;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) / 6,300000000);
  uVar1 = CLKCTL0_SYSPLL0CTL0;
  CLKCTL0_SYSPLL0CTL0 = uVar1 & 0xffffdfff;
  uVar1 = CLKCTL0_SYSPLL0LOCKTIMEDIV2;
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
                    /* sys pll0 PFD [sfr] */
  uVar2 = CLKCTL0_SYSPLL0PFD;
  uVar2 = uVar2 & ~(0xbf << (uVar1 & 0xff));
  CLKCTL0_SYSPLL0PFD = 0x80 << (uVar1 & 0xff) | uVar2;
  CLKCTL0_SYSPLL0PFD = (param_2 & 0x3f) << (uVar1 & 0xff) | uVar2;
  uVar2 = 0x40 << (uVar1 & 0xff);
  do {
    uVar1 = CLKCTL0_SYSPLL0PFD;
  } while ((uVar1 & uVar2) == 0);
  uVar1 = CLKCTL0_SYSPLL0PFD;
  CLKCTL0_SYSPLL0PFD = uVar2 | uVar1;
  return;
}


// ===== CLOCK_InitAudioPll @ 00083b4c (242 bytes)

/* Same for AUDIOPLL0 (CLKCTL1) [inference] */

void CLOCK_InitAudioPll(byte *param_1)

{
  uint uVar1;
  
                    /* Run configuration 0 set [sfr] */
  SYSCTL0_PDRUNCFG0_SET = 0x180000;
                    /* audio pll0 clock selection [sfr] */
  CLKCTL1_AUDIOPLL0CLKSEL = (uint)*param_1;
                    /* audio pll0 number [sfr] */
  CLKCTL1_AUDIOPLL0NUM = *(undefined4 *)(param_1 + 4);
                    /* Audio pll0 denom [sfr] */
  CLKCTL1_AUDIOPLL0DENOM = *(undefined4 *)(param_1 + 8);
  switch(param_1[0xc]) {
  case 0:
                    /* audio pll0 control0 [sfr] */
    uVar1 = CLKCTL1_AUDIOPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x100000;
    break;
  case 1:
    uVar1 = CLKCTL1_AUDIOPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x110000;
    break;
  case 2:
    uVar1 = CLKCTL1_AUDIOPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x120000;
    break;
  case 3:
    uVar1 = CLKCTL1_AUDIOPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x130000;
    break;
  case 4:
    uVar1 = CLKCTL1_AUDIOPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x140000;
    break;
  case 5:
    uVar1 = CLKCTL1_AUDIOPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x150000;
    break;
  case 6:
    uVar1 = CLKCTL1_AUDIOPLL0CTL0;
    uVar1 = uVar1 & 0xff00ffff | 0x160000;
    break;
  default:
    goto switchD_00083b72_default;
  }
  CLKCTL1_AUDIOPLL0CTL0 = uVar1;
switchD_00083b72_default:
  uVar1 = CLKCTL1_AUDIOPLL0CTL0;
  CLKCTL1_AUDIOPLL0CTL0 = uVar1 & 0xfffffffd;
                    /* Run configuration 0 clear [sfr] */
  SYSCTL0_PDRUNCFG0_CLR = 0x180000;
                    /* audio pll0 lock time [sfr] */
  uVar1 = CLKCTL1_AUDIOPLL0LOCKTIMEDIV2;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) >> 1,300000000);
  uVar1 = CLKCTL1_AUDIOPLL0CTL0;
  CLKCTL1_AUDIOPLL0CTL0 = uVar1 | 0x2000;
  uVar1 = CLKCTL1_AUDIOPLL0LOCKTIMEDIV2;
  SDK_DelayAtLeastUs((uVar1 & 0xffff) / 6,300000000);
  uVar1 = CLKCTL1_AUDIOPLL0CTL0;
  CLKCTL1_AUDIOPLL0CTL0 = uVar1 & 0xffffdfff;
  uVar1 = CLKCTL1_AUDIOPLL0LOCKTIMEDIV2;
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
                    /* audio pll0 PFD [sfr] */
  uVar2 = CLKCTL1_AUDIOPLL0PFD;
  uVar2 = uVar2 & ~(0xbf << (uVar1 & 0xff));
  CLKCTL1_AUDIOPLL0PFD = 0x80 << (uVar1 & 0xff) | uVar2;
  CLKCTL1_AUDIOPLL0PFD = (param_2 & 0x3f) << (uVar1 & 0xff) | uVar2;
  uVar2 = 0x40 << (uVar1 & 0xff);
  do {
    uVar1 = CLKCTL1_AUDIOPLL0PFD;
  } while ((uVar1 & uVar2) == 0);
  uVar1 = CLKCTL1_AUDIOPLL0PFD;
  CLKCTL1_AUDIOPLL0PFD = uVar2 | uVar1;
  return;
}


// ===== CLOCK_EnableSysOscClk @ 00083c9c (32 bytes)

/* SYSOSCCTL0 = mode, SYSOSCBYPASS = 0, delay [inference] */

void CLOCK_EnableSysOscClk(int param_1,uint param_2,uint param_3)

{
  if (param_1 != 0) {
                    /* system oscillator control 0 [sfr] */
    CLKCTL0_SYSOSCCTL0 = param_2;
                    /* system oscillator bypass [sfr] */
    CLKCTL0_SYSOSCBYPASS = 0;
    SDK_DelayAtLeastUs(param_3,300000000);
    return;
  }
  CLKCTL0_SYSOSCCTL0 = param_2 | 2;
  return;
}


// ===== SDK_DelayAtLeastUs @ 00083cc4 (28 bytes)

/* Busy loop: us x 300 MHz / 4e6 iterations [inference] */

void SDK_DelayAtLeastUs(uint param_1,uint param_2)

{
  int iVar1;
  ulonglong __aeabi_uldivmod_ret;
  
  if (param_1 != 0) {
    __aeabi_uldivmod_ret = __aeabi_uldivmod((ulonglong)param_1 * (ulonglong)param_2,4000000);
    iVar1 = (int)__aeabi_uldivmod_ret;
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ===== CTIMER_GenericIRQHandler @ 00083ce4 (80 bytes)

/* NEW (entries_m33.tsv): byte-identical to CTIMER_GenericIRQHandler of mcux-sdk MCUX_2.11.0
   drivers/ctimer/fsl_ctimer.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24 round 2) */

void CTIMER_GenericIRQHandler(uint index)

{
  code *pcVar1;
  uint i;
  uint uVar2;
  
  uVar2 = *(uint *)(&PTR_CTIMER0_IR_000879bc)[index];
  *(uint *)(&PTR_CTIMER0_IR_000879bc)[index] = uVar2;
  if ((&DAT_000a1ef0)[index] == '\0') {
    if (*(code **)(&DAT_00088934)[index] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(&DAT_00088934)[index])(uVar2);
      return;
    }
  }
  else {
    i = 0;
    do {
      if (((1 << (i & 0xff) & uVar2) != 0) &&
         (pcVar1 = *(code **)((&DAT_00088934)[index] + i * 4), pcVar1 != (code *)0x0)) {
        (*pcVar1)(uVar2);
      }
      i = i + 1;
    } while (i != 7);
  }
  return;
}


// ===== DMA_GetInstance @ 00083d40 (24 bytes)

/* 0x40104000 -> 0, 0x40105000 -> 1 [fact] */

uint DMA_GetInstance(void *param_1)

{
  uint uVar1;
  
  if (param_1 == &DMA0_CTRL) {
    return 0;
  }
  if (param_1 == &DMA1_CTRL) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

