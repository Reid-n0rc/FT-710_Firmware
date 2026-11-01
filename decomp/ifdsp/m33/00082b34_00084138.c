// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

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


// ===== CLOCK_GetFlexCommClkFreq @ 00083470 (238 bytes)

uint CLOCK_GetFlexCommClkFreq(uint param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  uint CLOCK_GetMainPllClkFreq_ret;
  uint uVar3;
  dword dVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  ulonglong __aeabi_uldivmod_ret;
  
  if (param_1 < 8) {
    dVar4 = (&CLKCTL1_FLEXCOMM0_FCFCLKSEL)[param_1 * 8];
  }
  else if (param_1 == 0xe) {
                    /* flexcomm14 clock selection [sfr] */
    dVar4 = CLKCTL1_FC14FCLKSEL;
  }
  else {
    if (param_1 != 0xf) {
      return 16000000;
    }
                    /* flexcomm15 clock selection [sfr] */
    dVar4 = CLKCTL1_FC15FCLKSEL;
  }
  switch(dVar4) {
  case 0:
    return 16000000;
  case 1:
    uVar3 = CLOCK_GetFFroFreq();
    return uVar3;
  case 2:
    uVar3 = CLOCK_GetAudioPllClkFreq();
    return uVar3;
  case 3:
    return DAT_0008892c;
  case 4:
    break;
  default:
    return 0;
  }
  if (param_1 < 8) {
    bVar5 = (byte)(&CLKCTL1_FLEXCOMM0_FRGCTL)[param_1 * 8];
    uVar3 = (&CLKCTL1_FLEXCOMM0_FRGCLKSEL)[param_1 * 8] & 7;
    uVar7 = ((&CLKCTL1_FLEXCOMM0_FRGCTL)[param_1 * 8] & 0xffff) >> 8;
LAB_000833e4:
    uVar6 = (uint)bVar5;
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
    if (param_1 == 0xe) {
                    /* FRG clock selection 14 [sfr] */
      uVar3 = CLKCTL1_FRG14CLKSEL;
                    /* FRG clock controller 14 [sfr] */
      uVar7 = CLKCTL1_FRG14CTL;
      uVar3 = uVar3 & 7;
      uVar1 = CLKCTL1_FRG14CTL;
      bVar5 = (byte)uVar1;
      uVar7 = (uVar7 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    if (param_1 == 0xf) {
                    /* FRG clock selection 15 [sfr] */
      uVar3 = CLKCTL1_FRG15CLKSEL;
                    /* FRG clock controller 15 [sfr] */
      uVar7 = CLKCTL1_FRG15CTL;
      uVar3 = uVar3 & 7;
      uVar1 = CLKCTL1_FRG15CTL;
      bVar5 = (byte)uVar1;
      uVar7 = (uVar7 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    uVar7 = 0;
    uVar6 = 0;
switchD_000833ea_caseD_0:
    pvVar2 = CLOCK_GetMainClkFreq();
  }
  __aeabi_uldivmod_ret =
       __aeabi_uldivmod((ulonglong)(uVar6 + 1) * ZEXT48(pvVar2),(ulonglong)(uVar6 + uVar7 + 1));
  return (uint)__aeabi_uldivmod_ret;
}


// ===== CLOCK_GetFreq @ 000837a8 (214 bytes)

/* WARNING: Removing unreachable block (ram,0x000835a6) */

undefined * CLOCK_GetFreq(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  void *pvVar4;
  undefined *puVar5;
  uint uVar6;
  uint *puVar7;
  dword *pdVar8;
  undefined4 clkctl0_systickfclksel;
  
  switch(param_1) {
  case 0:
  case 1:
    pvVar4 = CLOCK_GetMainClkFreq();
    pdVar8 = &CLKCTL0_BASE;
    goto LAB_000837d4;
  case 2:
    iVar1 = CLKCTL1_AUDIOMCLKSEL;
    if (iVar1 == 0) {
      uVar6 = CLOCK_GetFFroFreq();
    }
    else {
      iVar1 = CLKCTL1_AUDIOMCLKSEL;
      if (iVar1 == 1) {
        uVar6 = CLOCK_GetAudioPllClkFreq();
      }
      else {
        uVar6 = 0;
      }
    }
    uVar3 = CLKCTL1_AUDIOMCLKDIV;
    return (undefined *)(uVar6 / ((uVar3 & 0xff) + 1));
  case 3:
    uVar6 = CLKCTL1_CLKOUTSEL1;
    puVar5 = (undefined *)(uVar6 & 7);
    switch(puVar5) {
    case (undefined *)0x0:
      uVar6 = CLKCTL1_CLKOUTSEL0;
      switch(uVar6 & 7) {
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
        puVar5 = CLOCK_GetMainClkFreq();
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
      uVar6 = CLKCTL0_DSPPLLCLKDIV;
      puVar5 = (undefined *)(uVar3 / ((uVar6 & 0xff) + 1));
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
    uVar6 = CLKCTL1_CLKOUTDIV;
    return (undefined *)((uint)puVar5 / ((uVar6 & 0xff) + 1));
  case 4:
    uVar6 = CLKCTL0_ADC0FCLKSEL1;
    puVar5 = (undefined *)(uVar6 & 7);
    switch(puVar5) {
    case (undefined *)0x0:
      uVar6 = CLKCTL0_ADC0FCLKSEL0;
      switch(uVar6 & 7) {
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
    uVar6 = CLKCTL0_ADC0FCLKDIV;
    return (undefined *)((uint)puVar5 / ((uVar6 & 0xff) + 1));
  case 5:
    uVar6 = CLKCTL0_FLEXSPIFCLKSEL;
    switch(uVar6 & 7) {
    case 0:
      pvVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      pvVar4 = (void *)CLOCK_GetMainPllClkFreq();
      break;
    case 2:
      pvVar4 = (void *)CLOCK_GetAux0PllClkFreq();
      break;
    case 3:
      pvVar4 = (void *)CLOCK_GetFFroFreq();
      break;
    case 4:
      pvVar4 = (void *)CLOCK_GetAux1PllClkFreq();
      break;
    default:
      pvVar4 = (void *)0x0;
    }
    uVar6 = CLKCTL0_FLEXSPIFCLKDIV;
    return (undefined *)((uint)pvVar4 / ((uVar6 & 0xff) + 1));
  case 6:
    uVar6 = CLKCTL0_SCTFCLKSEL;
    switch(uVar6 & 7) {
    case 0:
      pvVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      pvVar4 = (void *)CLOCK_GetMainPllClkFreq();
      break;
    case 2:
      pvVar4 = (void *)CLOCK_GetAux0PllClkFreq();
      break;
    case 3:
      pvVar4 = (void *)CLOCK_GetFFroFreq();
      break;
    case 4:
      pvVar4 = (void *)CLOCK_GetAux1PllClkFreq();
      break;
    case 5:
      pvVar4 = (void *)CLOCK_GetAudioPllClkFreq();
      break;
    default:
      pvVar4 = (void *)0x0;
    }
    uVar6 = CLKCTL0_SCTFCLKDIV;
    return (undefined *)((uint)pvVar4 / ((uVar6 & 0xff) + 1));
  case 7:
    uVar6 = CLKCTL0_WDT0FCLKSEL;
    if ((uVar6 & 7) == 0) {
      return &DAT_000f4240;
    }
    puVar5 = CLOCK_GetMainClkFreq();
    return puVar5;
  case 8:
    uVar6 = CLKCTL1_WDT1FCLKSEL;
    if ((uVar6 & 7) != 0) {
      puVar5 = CLOCK_GetMainClkFreq();
      return puVar5;
    }
    return &DAT_000f4240;
  case 9:
    clkctl0_systickfclksel = CLKCTL0_SYSTICKFCLKSEL;
    switch(clkctl0_systickfclksel) {
    case 0:
      pvVar4 = CLOCK_GetMainClkFreq();
      uVar6 = CLKCTL0_SYSTICKFCLKDIV;
      puVar5 = (undefined *)((uint)pvVar4 / ((uVar6 & 0xff) + 1));
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
    pdVar8 = &CLKCTL0_SDIO0FCLKDIV;
    if (bVar2) {
      pdVar8 = &CLKCTL0_SDIO1FCLKDIV;
    }
    puVar7 = &CLKCTL0_SDIO0FCLKSEL;
    if (bVar2) {
      puVar7 = &CLKCTL0_SDIO1FCLKSEL;
    }
    switch(*puVar7 & 7) {
    case 0:
      pvVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      pvVar4 = (void *)CLOCK_GetMainPllClkFreq();
      break;
    case 2:
      pvVar4 = (void *)CLOCK_GetAux0PllClkFreq();
      break;
    case 3:
      pvVar4 = (void *)CLOCK_GetFFroFreq();
      break;
    case 4:
      pvVar4 = (void *)CLOCK_GetAux1PllClkFreq();
      break;
    default:
      pvVar4 = (void *)0x0;
    }
    return (undefined *)((uint)pvVar4 / ((*pdVar8 & 0xff) + 1));
  case 0xc:
    uVar6 = CLKCTL1_I3C0FCLKSEL;
    if ((uVar6 & 7) == 0) {
      pvVar4 = CLOCK_GetMainClkFreq();
    }
    else if ((uVar6 & 7) == 1) {
      pvVar4 = (void *)CLOCK_GetFFroFreq();
    }
    else {
      pvVar4 = (void *)0x0;
    }
    uVar6 = CLKCTL1_I3C0FCLKDIV;
    return (undefined *)((uint)pvVar4 / ((uVar6 & 0xff) + 1));
  case 0xd:
    iVar1 = CLKCTL0_USBHSFCLKSEL;
    if (iVar1 == 0) {
      pvVar4 = (void *)CLOCK_GetXtalInClkFreq();
    }
    else {
      iVar1 = CLKCTL0_USBHSFCLKSEL;
      if (iVar1 == 1) {
        pvVar4 = CLOCK_GetMainClkFreq();
      }
      else {
        pvVar4 = (void *)0x0;
      }
    }
    uVar6 = CLKCTL0_USBHSFCLKDIV;
    return (undefined *)((uint)pvVar4 / ((uVar6 & 0xff) + 1));
  case 0xe:
    uVar6 = CLKCTL1_DMIC0FCLKSEL;
    switch(uVar6 & 7) {
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
      uVar6 = CLKCTL0_WAKECLK32KHZSEL;
      if ((uVar6 & 7) == 0) {
        puVar5 = (undefined *)CLOCK_GetOsc32KFreq();
      }
      else {
        uVar6 = CLKCTL0_WAKECLK32KHZDIV;
        puVar5 = (undefined *)(1000000 / ((uVar6 & 0xff) + 1));
      }
      break;
    default:
      puVar5 = (undefined *)0x0;
    }
    uVar6 = CLKCTL1_DMIC0FCLKDIV;
    return (undefined *)((uint)puVar5 / ((uVar6 & 0xff) + 1));
  case 0xf:
    pvVar4 = (void *)CLOCK_GetDspMainClkFreq();
    pdVar8 = &CLKCTL1_BASE;
LAB_000837d4:
    return (undefined *)((uint)pvVar4 / ((pdVar8[0x100] & 0xff) + 1));
  case 0x10:
    uVar6 = CLKCTL1_ACMP0FCLKSEL;
    switch(uVar6 & 7) {
    case 0:
      pvVar4 = CLOCK_GetMainClkFreq();
      break;
    case 1:
      pvVar4 = (void *)0xf42400;
      break;
    case 2:
      pvVar4 = (void *)CLOCK_GetFFroFreq();
      break;
    case 3:
      pvVar4 = (void *)CLOCK_GetAux0PllClkFreq();
      break;
    case 4:
      pvVar4 = (void *)CLOCK_GetAux1PllClkFreq();
      break;
    default:
      pvVar4 = (void *)0x0;
    }
    uVar6 = CLKCTL1_ACMP0FCLKDIV;
    return (undefined *)((uint)pvVar4 / ((uVar6 & 0xff) + 1));
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
  puVar5 = (undefined *)CLOCK_GetFlexCommClkFreq(uVar6);
  return puVar5;
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


// ===== DMA_IRQHandle @ 00083d5c (176 bytes)

/* NEW. fsl_dma.c channel interrupt dispatcher (33 channels); unused (DMA IRQs never enabled by the
   M33) [inference] */

void DMA_IRQHandle(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int i;
  code *pcVar5;
  
  uVar1 = DMA_GetInstance(param_1);
  i = 0;
  piVar4 = (int *)(&DAT_00088948 + uVar1 * 0x84);
  do {
    puVar2 = (undefined4 *)*piVar4;
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = (uint)(*(byte *)(puVar2 + 3) >> 5);
      uVar3 = *(byte *)(puVar2 + 3) & 0x1f;
      if ((int)((*(uint *)(puVar2[2] + 0x58 + uVar1 * 4) >> uVar3) << 0x1f) < 0) {
        pcVar5 = (code *)*puVar2;
        *(int *)(puVar2[2] + 0x58 + uVar1 * 4) = 1 << uVar3;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(puVar2,puVar2[1],1,0,param_4);
        }
      }
      if ((int)((*(uint *)(puVar2[2] + 0x60 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) >> uVar3) <<
               0x1f) < 0) {
        pcVar5 = (code *)*puVar2;
        *(int *)(puVar2[2] + 0x60 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) = 1 << uVar3;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(puVar2,puVar2[1],1);
        }
      }
      if ((int)((*(uint *)(puVar2[2] + 0x40 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) >> uVar3) <<
               0x1f) < 0) {
        *(int *)(puVar2[2] + 0x40 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) = 1 << uVar3;
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)(puVar2,puVar2[1],0,2);
        }
      }
    }
    i = i + 1;
    piVar4 = piVar4 + 1;
  } while (i != 0x21);
  return;
}


// ===== DMA0_DriverIRQHandler @ 00083e10 (6 bytes)

/* IRQ1 -> DMA_IRQHandle(DMA0) [fact: vector] */

void DMA0_DriverIRQHandler(void)

{
                    /* fsl_dma.c channel interrupt dispatcher [doc, inference] */
  DMA_IRQHandle(&DMA0_CTRL);
  return;
}


// ===== DMA1_DriverIRQHandler @ 00083e1c (6 bytes)

/* IRQ54 [fact: vector] */

void DMA1_DriverIRQHandler(void)

{
                    /* fsl_dma.c channel interrupt dispatcher [doc, inference] */
  DMA_IRQHandle(&DMA1_CTRL);
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
  uint uVar1;
  int rstctl0_prstctl0;
  
                    /* Run configuration 1 [sfr] */
  uVar1 = SYSCTL0_PDRUNCFG1;
  if ((uVar1 & 0xf000000) != 0) {
                    /* Run configuration 1 clear [sfr] */
    SYSCTL0_PDRUNCFG1_CLR = 0x4000000;
    SYSCTL0_PDRUNCFG1_CLR = 0x8000000;
    SYSCTL0_PDRUNCFG1_CLR = 0x1000000;
    SYSCTL0_PDRUNCFG1_CLR = 0x2000000;
    POWER_ApplyPD();
    RESET_ClearPeripheralReset(1);
    return;
  }
  rstctl0_prstctl0 = RSTCTL0_PRSTCTL0;
  if (rstctl0_prstctl0 << 0x1e < 0) {
                    /* peripheral reset clear 0 [sfr] */
    RSTCTL0_PRSTCTL0_CLR = 2;
    do {
      uVar1 = RSTCTL0_PRSTCTL0;
    } while ((~uVar1 & 2) == 0);
    return;
  }
  return;
}


// ===== FLEXCOMM_GetInstance @ 00083ea0 (22 bytes)

/* Search of 10 FLEXCOMM bases at 0x879D0 [fact] */

uint FLEXCOMM_GetInstance(int param_1)

{
  uint i;
  int *piVar1;
  
  i = 0;
  piVar1 = &DAT_000879d0;
  do {
    if (*piVar1 == param_1) {
      return i;
    }
    i = i + 1;
    piVar1 = piVar1 + 1;
  } while (i != 10);
  return 10;
}


// ===== FLEXCOMM_Init @ 00083ebc (180 bytes)

/* Clock enable + reset release from table 0x87B28, PSELID (base+0xFF8) [inference] */

uint FLEXCOMM_Init(int param_1,uint param_2)

{
  ushort uVar1;
  uint FLEXCOMM_GetInstance_ret;
  dword *pdVar2;
  uint uVar3;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(param_1);
  uVar1 = *(ushort *)(&DAT_00087b28 + FLEXCOMM_GetInstance_ret * 2);
  uVar3 = (uint)uVar1;
  switch(uVar1 >> 8) {
  case 0:
    pdVar2 = &CLKCTL0_BASE;
    break;
  case 1:
    uVar3 = (uint)(byte)uVar1;
    pdVar2 = &CLKCTL0_BASE;
    goto LAB_00083f2a;
  case 2:
    pdVar2 = &CLKCTL0_BASE;
    goto LAB_00083f38;
  case 3:
    pdVar2 = &CLKCTL1_BASE;
    break;
  case 4:
    uVar3 = uVar3 & 0xff;
    pdVar2 = &CLKCTL1_BASE;
LAB_00083f2a:
    pdVar2[0x11] = 1 << uVar3;
    goto switchD_00083ed2_default;
  case 5:
    pdVar2 = &CLKCTL1_BASE;
LAB_00083f38:
    pdVar2[0x12] = 1 << (uVar3 & 0xff);
  default:
    goto switchD_00083ed2_default;
  }
  pdVar2[0x10] = 1 << (uVar3 & 0xff);
switchD_00083ed2_default:
  RESET_ClearPeripheralReset((uint)*(ushort *)(&DAT_00087b28 + FLEXCOMM_GetInstance_ret * 2));
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
      uVar3 = *(uint *)(param_1 + 0xff8) >> (param_2 + 3 & 0xff) & 1;
LAB_00083f02:
      if (uVar3 != 0) goto LAB_00083f04;
    }
    else if (param_2 == 5) {
      uVar3 = *(uint *)(param_1 + 0xff8) & 0x80;
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
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40107000);
                    /* WARNING: Could not recover jumptable at 0x00083fa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM2_DriverIRQHandler @ 00083fb8 (32 bytes)

/* IRQ16 [fact: vector] */

void FLEXCOMM2_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40108000);
                    /* WARNING: Could not recover jumptable at 0x00083fd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM3_DriverIRQHandler @ 00083fe8 (32 bytes)

/* IRQ17 [fact: vector] */

void FLEXCOMM3_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40109000);
                    /* WARNING: Could not recover jumptable at 0x00084006. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM4_DriverIRQHandler @ 00084018 (32 bytes)

/* IRQ18 [fact: vector] */

void FLEXCOMM4_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40122000);
                    /* WARNING: Could not recover jumptable at 0x00084036. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM5_DriverIRQHandler @ 00084048 (32 bytes)

/* IRQ19 [fact: vector] */

void FLEXCOMM5_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40123000);
                    /* WARNING: Could not recover jumptable at 0x00084066. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM6_DriverIRQHandler @ 00084078 (32 bytes)

/* IRQ43 [fact: vector] */

void FLEXCOMM6_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40124000);
                    /* WARNING: Could not recover jumptable at 0x00084096. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM7_DriverIRQHandler @ 000840a8 (32 bytes)

/* IRQ44 [fact: vector] */

void FLEXCOMM7_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40125000);
                    /* WARNING: Could not recover jumptable at 0x000840c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM14_DriverIRQHandler @ 000840d8 (32 bytes)

/* IRQ20 [fact: vector] */

void FLEXCOMM14_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40126000);
                    /* WARNING: Could not recover jumptable at 0x000840f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM15_DriverIRQHandler @ 00084108 (32 bytes)

/* IRQ21 [fact: vector] */

void FLEXCOMM15_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40127000);
                    /* WARNING: Could not recover jumptable at 0x00084126. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXSPI_DriverIRQHandler @ 00084138 (12 bytes)

/* IRQ42 [fact: vector] */

void FLEXSPI_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x00084142. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088aac)(&FLEXSPI_MCR0,DAT_00088aa8);
  return;
}

