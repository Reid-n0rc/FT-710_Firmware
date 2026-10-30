// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== CLOCK_InitSysPll @ 00209720 (338 bytes)

/* fsl_clock.c: SYSPLL0, POWER PDRUNCFG (SYSCTL0 0x40002600), SDK_DelayAtLeastUs [inference] */

void CLOCK_InitSysPll(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  memw();
  SYSCTL0_PDRUNCFG0_SET = &DAT_00060000;
  memw();
  CLKCTL0_SYSPLL0CLKSEL = *param_1;
  memw();
  CLKCTL0_SYSPLL0NUM = param_1[1];
  memw();
  iVar2 = param_1[3];
  CLKCTL0_SYSPLL0DENOM = param_1[2];
  if (iVar2 == 0) {
    memw();
    uVar3 = CLKCTL0_SYSPLL0CTL0;
    memw();
    CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00100000;
  }
  else if (iVar2 == 1) {
    memw();
    uVar3 = CLKCTL0_SYSPLL0CTL0;
    memw();
    CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00110000;
  }
  else if (iVar2 == 2) {
    memw();
    uVar3 = CLKCTL0_SYSPLL0CTL0;
    memw();
    CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00120000;
  }
  else if (iVar2 == 3) {
    memw();
    uVar3 = CLKCTL0_SYSPLL0CTL0;
    memw();
    CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00130000;
  }
  else if (iVar2 == 4) {
    memw();
    uVar3 = CLKCTL0_SYSPLL0CTL0;
    memw();
    CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00140000;
  }
  else if (iVar2 == 5) {
    memw();
    uVar3 = CLKCTL0_SYSPLL0CTL0;
    memw();
    CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00150000;
  }
  else if (iVar2 == 6) {
    memw();
    uVar3 = CLKCTL0_SYSPLL0CTL0;
    memw();
    CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00160000;
  }
  memw();
  uVar3 = CLKCTL0_SYSPLL0CTL0;
  memw();
  CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xfffffffd;
  memw();
  SYSCTL0_PDRUNCFG0_CLR = &DAT_00060000;
  memw();
  uVar3 = CLKCTL0_SYSPLL0LOCKTIMEDIV2;
  SDK_DelayAtLeastUs(uVar3 >> 1 & 0x7fff,600000000);
  memw();
  uVar3 = CLKCTL0_SYSPLL0CTL0;
  memw();
  CLKCTL0_SYSPLL0CTL0 = uVar3 | (uint)&DAT_00002000;
  memw();
  uVar1 = CLKCTL0_SYSPLL0LOCKTIMEDIV2;
  uVar3 = ae_zext16(uVar1);
  SDK_DelayAtLeastUs(uVar3 / 6,600000000);
  memw();
  uVar3 = CLKCTL0_SYSPLL0CTL0;
  memw();
  CLKCTL0_SYSPLL0CTL0 = uVar3 & 0xffffdfff;
  memw();
  uVar1 = CLKCTL0_SYSPLL0LOCKTIMEDIV2;
  uVar3 = ae_zext16(uVar1);
  SDK_DelayAtLeastUs(uVar3 / 3,600000000);
  return;
}


// ===== CLOCK_InitSysPfd @ 00209878 (114 bytes)

/* fsl_clock.c order [inference] */

void CLOCK_InitSysPfd(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << 3;
  memw();
  uVar2 = CLKCTL0_SYSPLL0PFD;
  uVar2 = uVar2 & (0xbf << 0x20 - (0x20 - (uVar1 & 0x1f)) ^ 0xffffffffU);
  memw();
  CLKCTL0_SYSPLL0PFD = uVar2 | 0x80 << 0x20 - (0x20 - (uVar1 & 0x1f));
  memw();
  CLKCTL0_SYSPLL0PFD = uVar2 | (param_2 & 0x3f) << 0x20 - (0x20 - (uVar1 & 0x1f));
  uVar1 = 0x40 << 0x20 - (0x20 - (uVar1 & 0x1f));
  memw();
  uVar2 = CLKCTL0_SYSPLL0PFD;
  while ((uVar2 & uVar1) == 0) {
    memw();
    uVar2 = CLKCTL0_SYSPLL0PFD;
  }
  memw();
  uVar2 = CLKCTL0_SYSPLL0PFD;
  memw();
  CLKCTL0_SYSPLL0PFD = uVar2 | uVar1;
  return;
}


// ===== CLOCK_InitAudioPll @ 002098ec (338 bytes)

/* fsl_clock.c: AUDIOPLL0 (0x40021200) [inference] */

void CLOCK_InitAudioPll(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  memw();
  SYSCTL0_PDRUNCFG0_SET = &DAT_00180000;
  memw();
  CLKCTL1_AUDIOPLL0CLKSEL = *param_1;
  memw();
  CLKCTL1_AUDIOPLL0NUM = param_1[1];
  memw();
  iVar2 = param_1[3];
  CLKCTL1_AUDIOPLL0DENOM = param_1[2];
  if (iVar2 == 0) {
    memw();
    uVar3 = CLKCTL1_AUDIOPLL0CTL0;
    memw();
    CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00100000;
  }
  else if (iVar2 == 1) {
    memw();
    uVar3 = CLKCTL1_AUDIOPLL0CTL0;
    memw();
    CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00110000;
  }
  else if (iVar2 == 2) {
    memw();
    uVar3 = CLKCTL1_AUDIOPLL0CTL0;
    memw();
    CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00120000;
  }
  else if (iVar2 == 3) {
    memw();
    uVar3 = CLKCTL1_AUDIOPLL0CTL0;
    memw();
    CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00130000;
  }
  else if (iVar2 == 4) {
    memw();
    uVar3 = CLKCTL1_AUDIOPLL0CTL0;
    memw();
    CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00140000;
  }
  else if (iVar2 == 5) {
    memw();
    uVar3 = CLKCTL1_AUDIOPLL0CTL0;
    memw();
    CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00150000;
  }
  else if (iVar2 == 6) {
    memw();
    uVar3 = CLKCTL1_AUDIOPLL0CTL0;
    memw();
    CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xff00ffff | (uint)&DAT_00160000;
  }
  memw();
  uVar3 = CLKCTL1_AUDIOPLL0CTL0;
  memw();
  CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xfffffffd;
  memw();
  SYSCTL0_PDRUNCFG0_CLR = &DAT_00180000;
  memw();
  uVar3 = CLKCTL1_AUDIOPLL0LOCKTIMEDIV2;
  SDK_DelayAtLeastUs(uVar3 >> 1 & 0x7fff,600000000);
  memw();
  uVar3 = CLKCTL1_AUDIOPLL0CTL0;
  memw();
  CLKCTL1_AUDIOPLL0CTL0 = uVar3 | (uint)&DAT_00002000;
  memw();
  uVar1 = CLKCTL1_AUDIOPLL0LOCKTIMEDIV2;
  uVar3 = ae_zext16(uVar1);
  SDK_DelayAtLeastUs(uVar3 / 6,600000000);
  memw();
  uVar3 = CLKCTL1_AUDIOPLL0CTL0;
  memw();
  CLKCTL1_AUDIOPLL0CTL0 = uVar3 & 0xffffdfff;
  memw();
  uVar1 = CLKCTL1_AUDIOPLL0LOCKTIMEDIV2;
  uVar3 = ae_zext16(uVar1);
  SDK_DelayAtLeastUs(uVar3 / 3,600000000);
  return;
}


// ===== CLOCK_InitAudioPfd @ 00209a40 (114 bytes)

/* fsl_clock.c order [inference] */

void CLOCK_InitAudioPfd(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << 3;
  memw();
  uVar2 = CLKCTL1_AUDIOPLL0PFD;
  uVar2 = uVar2 & (0xbf << 0x20 - (0x20 - (uVar1 & 0x1f)) ^ 0xffffffffU);
  memw();
  CLKCTL1_AUDIOPLL0PFD = uVar2 | 0x80 << 0x20 - (0x20 - (uVar1 & 0x1f));
  memw();
  CLKCTL1_AUDIOPLL0PFD = uVar2 | (param_2 & 0x3f) << 0x20 - (0x20 - (uVar1 & 0x1f));
  uVar1 = 0x40 << 0x20 - (0x20 - (uVar1 & 0x1f));
  memw();
  uVar2 = CLKCTL1_AUDIOPLL0PFD;
  while ((uVar2 & uVar1) == 0) {
    memw();
    uVar2 = CLKCTL1_AUDIOPLL0PFD;
  }
  memw();
  uVar2 = CLKCTL1_AUDIOPLL0PFD;
  memw();
  CLKCTL1_AUDIOPLL0PFD = uVar2 | uVar1;
  return;
}


// ===== CLOCK_EnableSysOscClk @ 00209ab4 (52 bytes)

/* fsl_clock.c order, SDK_DelayAtLeastUs [inference] */

void CLOCK_EnableSysOscClk(int param_1,uint param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    memw();
    CLKCTL0_SYSOSCCTL0 = param_2;
    memw();
    CLKCTL0_SYSOSCBYPASS = 0;
    SDK_DelayAtLeastUs(param_3,600000000);
    return;
  }
  memw();
  CLKCTL0_SYSOSCCTL0 = param_2 | 2;
  return;
}


// ===== CLOCK_EnableUsbhsDeviceClock @ 00209ae8 (35 bytes)

/* fsl_clock.c order [inference] */

void CLOCK_EnableUsbhsDeviceClock(void)

{
  memw();
  CLKCTL0_PSCCTL0_SET = &DAT_00100000;
  memw();
  CLKCTL0_PSCCTL0_SET = &DAT_00200000;
  memw();
  CLKCTL0_PSCCTL0_SET = 0x800000;
  return;
}


// ===== CLOCK_EnableUsbhsHostClock @ 00209b0c (35 bytes)

/* fsl_clock.c order [inference] */

void CLOCK_EnableUsbhsHostClock(void)

{
  memw();
  CLKCTL0_PSCCTL0_SET = &DAT_00100000;
  memw();
  CLKCTL0_PSCCTL0_SET = &DAT_00400000;
  memw();
  CLKCTL0_PSCCTL0_SET = 0x800000;
  return;
}


// ===== CLOCK_EnableUsbhsPhyClock @ 00209b30 (219 bytes)

/* fsl_clock.c order; USBPHY 0x4013B000 [inference] */

undefined4 CLOCK_EnableUsbhsPhyClock(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  
  memw();
  USBPHY_CTRL_CLR = 0x80000000;
  param_2 = 480000000 / param_2;
  if (param_2 == 0xd) {
    puVar3 = (undefined *)0x0;
  }
  else if (param_2 == 0xf) {
    puVar3 = &DAT_00400000;
  }
  else if (param_2 == 0x10) {
    puVar3 = (undefined *)0x800000;
  }
  else if (param_2 == 0x14) {
    puVar3 = (undefined *)0xc00000;
  }
  else if (param_2 == 0x16) {
    puVar3 = (undefined *)0x1000000;
  }
  else if (param_2 == 0x19) {
    puVar3 = (undefined *)0x1400000;
  }
  else if (param_2 == 0x1e) {
    puVar3 = (undefined *)0x1800000;
  }
  else {
    if (param_2 != 0xf0) {
      return 0;
    }
    puVar3 = (undefined *)0x1c00000;
  }
  memw();
  USBPHY_PLL_SIC_SET = FLOAT_ARRAY_00201000;
  memw();
  uVar1 = USBPHY_PLL_SIC;
  memw();
  USBPHY_PLL_SIC = uVar1 & 0xfe3fffff | (uint)puVar3;
  memw();
  USBPHY_PLL_SIC_CLR = &DAT_00010000;
  memw();
  USBPHY_PLL_SIC_SET = 0x40;
  memw();
  USBPHY_CTRL_CLR = &RSTCTL0_SYSRSTSTAT;
  memw();
  USBPHY_PWD_SET = 0;
  memw();
  iVar2 = USBPHY_PLL_SIC;
  while (-1 < iVar2) {
    memw();
    iVar2 = USBPHY_PLL_SIC;
  }
  return 1;
}


// ===== SDK_Malloc @ 00209c10 (68 bytes)

/* fsl_common.c: malloc(aligned size + 4), magic 0x3039 (SDK_MEM_MAGIC_NUMBER 12345) and offset
   below the result; SDK >= 2.9 overflow checks [fact for the code] */

uint SDK_Malloc(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = -param_2 & (param_1 + param_2) - 1;
  if ((param_1 <= uVar2) && (uVar2 <= -param_2 - 5U)) {
    iVar1 = malloc(uVar2 + param_2 + 4);
    if (iVar1 != 0) {
      uVar2 = -param_2 & iVar1 + param_2 + 3U;
      ae_s16i_n(uVar2 - iVar1,uVar2 - 4,2);
      ae_s16i_n(&DAT_00003039,uVar2 - 4,0);
      return uVar2;
    }
  }
  return 0;
}


// ===== SDK_Free @ 00209c54 (28 bytes)

/* fsl_common.c: checks magic 0x3039, free(ptr - offset) [fact for the code] */

void SDK_Free(int param_1)

{
  if (*(short *)(param_1 + -4) != 0x3039) {
    return;
  }
  free(param_1 - (uint)*(ushort *)(param_1 + -2));
  return;
}


// ===== SDK_DelayAtLeastUs @ 00209c70 (166 bytes)

/* WARNING: Removing unreachable block (ram,0x00209d05) */
/* fsl_common.c (XCC path: CCOUNT cycles, 1,000,000 divisor) [inference] */

void SDK_DelayAtLeastUs(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  undefined8 uVar7;
  
  if (param_1 != 0) {
    uVar2 = xthal_get_ccount();
    uVar7 = __udivdi3(param_1 * param_2,(int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20),
                      &DAT_000f4240,0);
    iVar3 = (int)((ulonglong)uVar7 >> 0x20);
    uVar6 = uVar2 + (int)uVar7;
    if (uVar6 < uVar2) {
      iVar3 = iVar3 + 1;
    }
    if (iVar3 != 0) {
      uVar2 = uVar6 + 1;
      iVar1 = iVar3 + -1;
      if (uVar2 < uVar6) {
        iVar1 = iVar3;
      }
      iVar3 = iVar1;
      uVar6 = xthal_get_ccount();
      bVar5 = false;
      if ((iVar3 == 0) && (uVar2 < uVar6)) {
        bVar5 = true;
      }
      uVar6 = uVar2;
      if (bVar5) {
        do {
          uVar4 = xthal_get_ccount();
          bVar5 = false;
          if ((iVar3 == 0) && (uVar2 < uVar4)) {
            bVar5 = true;
          }
        } while (bVar5);
      }
    }
    uVar2 = xthal_get_ccount();
    bVar5 = false;
    if ((iVar3 != 0) || (uVar2 < uVar6)) {
      bVar5 = true;
    }
    if (bVar5) {
      do {
        uVar2 = xthal_get_ccount();
        bVar5 = false;
        if ((iVar3 != 0) || (uVar2 < uVar6)) {
          bVar5 = true;
        }
      } while (bVar5);
    }
  }
  return;
}


// ===== CRC_Init @ 00209d20 (101 bytes)

/* fsl_crc.c (lpc_crc) order [inference] */

void CRC_Init(uint *param_1,uint *param_2)

{
  memw();
  CLKCTL1_PSCCTL1_SET = &DAT_00010000;
  RESET_PeripheralReset(0x410);
  memw();
  *param_1 = (*(byte *)((int)param_2 + 5) & 1) << 3 | *param_2 & 3 | ((byte)param_2[1] & 1) << 2 |
             (*(byte *)((int)param_2 + 6) & 1) << 4 | (*(byte *)((int)param_2 + 7) & 1) << 5;
  memw();
  param_1[1] = param_2[2];
  return;
}


// ===== CRC_GetDefaultConfig @ 00209d88 (45 bytes)

/* fsl_crc.c: copies default_config 0x2000FC; CRC_Reset (0x209DB8) follows inside this listing entry
   [fact for the code] */

void CRC_GetDefaultConfig(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  param_1[2] = &DAT_0000ffff;
  return;
}


// ===== CRC_WriteSeed @ 00209dcc (10 bytes)

/* fsl_crc.c: base->SEED = seed [fact for the code] */

void CRC_WriteSeed(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}


// ===== CRC_GetConfig @ 00209dd8 (62 bytes)

/* fsl_crc.c order [inference] */

void CRC_GetConfig(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *param_1;
  *(byte *)((int)param_2 + 7) = (byte)(uVar1 >> 5) & 1;
  *(byte *)((int)param_2 + 6) = (byte)(uVar1 >> 4) & 1;
  *(byte *)((int)param_2 + 5) = (byte)(uVar1 >> 3) & 1;
  *(byte *)(param_2 + 1) = (byte)(uVar1 >> 2) & 1;
  *param_2 = uVar1 & 3;
  memw();
  *param_1 = uVar1 & 0xffffffcf;
  memw();
  param_2[2] = param_1[2];
  memw();
  *param_1 = uVar1;
  return;
}


// ===== CRC_WriteData @ 00209e18 (112 bytes)

/* fsl_crc.c order [inference] */

undefined4 * CRC_WriteData(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  
  for (; (param_3 != 0 && (((uint)param_2 & 3) != 0)); param_2 = (undefined4 *)((int)param_2 + 1)) {
    memw();
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)param_2;
    param_3 = param_3 - 1;
  }
  if (3 < param_3) {
    uVar1 = param_3 >> 2;
    if ((uVar1 != 0) && ((uVar1 == 1 || (uVar1 != 0)))) {
      memw();
      *(undefined4 *)(param_1 + 8) = *param_2;
      param_2 = param_2 + 1;
    }
    param_3 = param_3 + uVar1 * -4;
  }
  if ((param_3 != 0) && ((param_3 == 1 || (param_3 != 0)))) {
    memw();
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return param_2;
}


// ===== CTIMER_Init @ 00209e90 (266 bytes)

/* fsl_ctimer.c: s_ctimerBases 0x200110, clocks 0x200130 [inference] */

void CTIMER_Init(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (param_1 != &CTIMER0_IR) {
    iVar2 = 4;
  }
  uVar1 = *(uint *)((int)&PTR_DAT_00200130 + iVar2);
  uVar3 = uVar1 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  iVar2 = 0;
  if (param_1 != &CTIMER0_IR) {
    iVar2 = 4;
  }
  RESET_PeripheralReset(*(undefined4 *)((int)&PTR_DAT_00200150 + iVar2));
  memw();
  param_1[0x1c] = *param_2 & 3 | (param_2[1] & 3) << 2;
  memw();
  param_1[3] = param_2[2];
  return;
}


// ===== CTIMER_Deinit @ 00209f9c (190 bytes)

/* fsl_ctimer.c order [inference] */

void CTIMER_Deinit(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (param_1 != &CTIMER0_IR) {
    iVar2 = 4;
  }
  memw();
  memw();
  uVar1 = *(uint *)((int)&PTR_DAT_00200130 + iVar2);
  param_1[1] = param_1[1] & 0xfffffffe;
  uVar3 = uVar1 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    return;
  }
  if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    return;
  }
  if (uVar3 != 2) {
    if (uVar3 == 3) {
      memw();
      CLKCTL1_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
      return;
    }
    if (uVar3 != 4) {
      if (uVar3 == 5) {
        memw();
        CLKCTL1_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
        return;
      }
      return;
    }
    memw();
    CLKCTL1_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    return;
  }
  memw();
  CLKCTL0_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  return;
}


// ===== CTIMER_GetDefaultConfig @ 0020a05c (13 bytes)

/* fsl_ctimer.c order [inference] */

void CTIMER_GetDefaultConfig(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ===== CTIMER_SetupPwm @ 0020a06c (203 bytes)

/* fsl_ctimer.c order [inference] */

undefined4
CTIMER_SetupPwm(uint *param_1,uint param_2,uint param_3,int param_4,uint param_5,uint param_6,
               char param_7)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  if (param_2 == param_3) {
    return 1;
  }
  uVar1 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  memw();
  memw();
  param_1[0x1d] = param_1[0x1d] | uVar1;
  memw();
  uVar2 = param_1[5] & (7 << 0x20 - (0x20 - (param_3 * 3 & 0x1f)) ^ 0xffffffffU);
  if (param_7 != '\0') {
    uVar2 = uVar2 | 1 << 0x20 - (0x20 - (param_3 * 3 & 0x1f));
  }
  memw();
  param_1[5] = uVar2 | 0x400;
  param_5 = (param_6 / (param_1[3] + 1)) / param_5;
  uVar2 = param_5 - 1;
  if (param_4 == 0) {
    memw();
    param_1[param_2 + 6] = uVar2;
    memw();
    param_1[param_3 + 6] = param_5;
    memw();
    *param_1 = uVar1;
    return 0;
  }
  memw();
  param_1[param_2 + 6] = uVar2;
  memw();
  param_1[param_3 + 6] = (uVar2 * (100 - param_4)) / 100;
  memw();
  *param_1 = uVar1;
  return 0;
}


// ===== CTIMER_SetupPwmPeriod @ 0020a138 (145 bytes)

/* fsl_ctimer.c order [inference] */

undefined4
CTIMER_SetupPwmPeriod(uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == param_3) {
    return 1;
  }
  uVar1 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  memw();
  memw();
  param_1[0x1d] = param_1[0x1d] | uVar1;
  memw();
  uVar2 = 2;
  if (param_6 != 0) {
    uVar2 = param_1[5] & (7 << 0x20 - (0x20 - (param_3 * 3 & 0x1f)) ^ 0xffffffffU) |
            1 << 0x20 - (0x20 - (param_3 * 3 & 0x1f));
  }
  memw();
  param_1[5] = uVar2 | 2 << 0x20 - (0x20 - (param_2 * 3 & 0x1f));
  memw();
  param_1[param_2 + 6] = param_4;
  memw();
  param_1[param_3 + 6] = param_5;
  memw();
  *param_1 = uVar1;
  return 0;
}


// ===== CTIMER_UpdatePwmDutycycle @ 0020a1cc (48 bytes)

/* fsl_ctimer.c order [inference] */

void CTIMER_UpdatePwmDutycycle(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  memw();
  iVar1 = *(int *)(param_2 * 4 + param_1 + 0x18);
  if (param_4 != 0) {
    memw();
    *(uint *)(param_3 * 4 + param_1 + 0x18) = (uint)(iVar1 * (100 - param_4)) / 100;
    return;
  }
  memw();
  *(int *)(param_3 * 4 + param_1 + 0x18) = iVar1 + 1;
  return;
}


// ===== CTIMER_SetupMatch @ 0020a200 (185 bytes)

/* fsl_ctimer.c order [inference] */

void CTIMER_SetupMatch(uint *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  
  memw();
  uVar1 = param_2 * 3;
  memw();
  param_1[5] = param_1[5] & (7 << 0x20 - (0x20 - (uVar1 & 0x1f)) ^ 0xffffffffU) |
               (uint)(byte)param_3[1] << 0x20 - (0x20 - (uVar1 + 1 & 0x1f)) |
               (uint)*(byte *)((int)param_3 + 5) << 0x20 - (0x20 - (uVar1 + 2 & 0x1f)) |
               (uint)*(byte *)((int)param_3 + 0xd) << 0x20 - (0x20 - (uVar1 & 0x1f));
  memw();
  uVar1 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  memw();
  param_1[0xf] = (param_1[0xf] & (0x30 << 0x20 - (0x20 - (param_2 * 2 & 0x1f)) ^ 0xffffffffU) |
                 param_3[2] << 0x20 - (0x20 - (param_2 * 2 + 4 & 0x1f))) & (uVar1 ^ 0xffffffff) |
                 (uint)(byte)param_3[3] << 0x20 - (0x20 - (param_2 & 0x1f));
  memw();
  param_1[param_2 + 6] = *param_3;
  memw();
  *param_1 = uVar1;
  return;
}


// ===== CTIMER_GetOutputMatchStatus @ 0020a2bc (13 bytes)

/* fsl_ctimer.c order [inference] */

uint CTIMER_GetOutputMatchStatus(int param_1,uint param_2)

{
  memw();
  return *(uint *)(param_1 + 0x3c) & param_2;
}


// ===== CTIMER_SetupCapture @ 0020a2cc (97 bytes)

/* fsl_ctimer.c order [inference] */

void CTIMER_SetupCapture(int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  memw();
  iVar1 = 0x20 - (param_2 * 3 & 0x1f);
  uVar2 = param_1[10] & (7 << 0x20 - iVar1 ^ 0xffffffffU) | param_3 << 0x20 - iVar1;
  memw();
  *param_1 = 0x10 << 0x20 - (0x20 - (param_2 & 0x1f));
  if (param_4 == 0) {
    memw();
    param_1[10] = uVar2;
    return;
  }
  memw();
  param_1[10] = uVar2 | 4 << 0x20 - (0x20 - (param_2 * 3 & 0x1f));
  return;
}


// ===== CTIMER_RegisterCallBack @ 0020a330 (71 bytes)

/* fsl_ctimer.c: callback table 0x238430 [inference] */

void CTIMER_RegisterCallBack(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != &CTIMER0_IR) {
    DAT_00238434 = param_2;
    DAT_00238454 = param_3;
    return;
  }
  DAT_00238430 = param_2;
  DAT_00238450 = param_3;
  return;
}


// ===== CTIMER0_DriverIRQHandler @ 0020a378 (74 bytes)

/* fsl_ctimer.c (CTIMER_GenericIRQHandler inlined, CTIMER0 0x40028000) [inference] */

void CTIMER0_DriverIRQHandler(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  memw();
  uVar1 = CTIMER0_IR;
  memw();
  CTIMER0_IR = uVar1;
  iVar3 = 0;
  iVar2 = 0;
  if (DAT_00238450 == 0) {
    if ((code *)*DAT_00238430 != (code *)0x0) {
      (*(code *)*DAT_00238430)(uVar1);
      return;
    }
  }
  else {
    do {
      if (((uVar1 & 1 << ((byte)iVar2 & 0x1f)) != 0) &&
         (*(code **)((int)DAT_00238430 + iVar3) != (code *)0x0)) {
        (**(code **)((int)DAT_00238430 + iVar3))(uVar1);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 != 7);
  }
  return;
}


// ===== CTIMER1_DriverIRQHandler @ 0020a3c4 (76 bytes)

/* fsl_ctimer.c [inference] */

void CTIMER1_DriverIRQHandler(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  memw();
  uVar1 = CTIMER1_IR;
  memw();
  CTIMER1_IR = uVar1;
  iVar3 = 0;
  iVar2 = 0;
  if (DAT_00238454 == 0) {
    if ((code *)*DAT_00238434 != (code *)0x0) {
      (*(code *)*DAT_00238434)(uVar1);
      return;
    }
  }
  else {
    do {
      if (((uVar1 & 1 << ((byte)iVar2 & 0x1f)) != 0) &&
         (*(code **)((int)DAT_00238434 + iVar3) != (code *)0x0)) {
        (**(code **)((int)DAT_00238434 + iVar3))(uVar1);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 != 7);
  }
  return;
}


// ===== CTIMER2_DriverIRQHandler @ 0020a410 (75 bytes)

/* fsl_ctimer.c [inference] */

void CTIMER2_DriverIRQHandler(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  memw();
  uVar1 = CTIMER2_IR;
  memw();
  CTIMER2_IR = uVar1;
  iVar3 = 0;
  iVar2 = 0;
  if (DAT_00238458 == 0) {
    if ((code *)*DAT_00238438 != (code *)0x0) {
      (*(code *)*DAT_00238438)(uVar1);
      return;
    }
  }
  else {
    do {
      if (((uVar1 & 1 << ((byte)iVar2 & 0x1f)) != 0) &&
         (*(code **)((int)DAT_00238438 + iVar3) != (code *)0x0)) {
        (**(code **)((int)DAT_00238438 + iVar3))(uVar1);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 != 7);
  }
  return;
}


// ===== CTIMER3_DriverIRQHandler @ 0020a45c (76 bytes)

/* fsl_ctimer.c [inference] */

void CTIMER3_DriverIRQHandler(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  memw();
  uVar1 = CTIMER3_IR;
  memw();
  CTIMER3_IR = uVar1;
  iVar3 = 0;
  iVar2 = 0;
  if (DAT_0023845c == 0) {
    if ((code *)*DAT_0023843c != (code *)0x0) {
      (*(code *)*DAT_0023843c)(uVar1);
      return;
    }
  }
  else {
    do {
      if (((uVar1 & 1 << ((byte)iVar2 & 0x1f)) != 0) &&
         (*(code **)((int)DAT_0023843c + iVar3) != (code *)0x0)) {
        (**(code **)((int)DAT_0023843c + iVar3))(uVar1);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 != 7);
  }
  return;
}


// ===== CTIMER4_DriverIRQHandler @ 0020a4a8 (75 bytes)

/* fsl_ctimer.c [inference] */

void CTIMER4_DriverIRQHandler(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  memw();
  uVar1 = CTIMER4_IR;
  memw();
  CTIMER4_IR = uVar1;
  iVar3 = 0;
  iVar2 = 0;
  if (DAT_00238460 == 0) {
    if ((code *)*DAT_00238440 != (code *)0x0) {
      (*(code *)*DAT_00238440)(uVar1);
      return;
    }
  }
  else {
    do {
      if (((uVar1 & 1 << ((byte)iVar2 & 0x1f)) != 0) &&
         (*(code **)((int)DAT_00238440 + iVar3) != (code *)0x0)) {
        (**(code **)((int)DAT_00238440 + iVar3))(uVar1);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 != 7);
  }
  return;
}


// ===== DMA_GetVirtualStartChannel @ 0020a500 (38 bytes)

/* fsl_dma.c static, called by DMA_CreateHandle [inference] */

void DMA_GetVirtualStartChannel(int param_1,uint param_2)

{
  param_1 = (param_2 >> 5 & 7) * 4 + param_1;
  memw();
  memw();
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  return;
}


// ===== DMA_Init @ 0020a528 (282 bytes)

void DMA_Init(dword *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (param_1 != &DMA0_CTRL) {
    iVar2 = 4;
  }
  uVar1 = *(uint *)((int)&DAT_00200190 + iVar2);
  uVar3 = uVar1 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  else if (uVar3 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  }
  iVar2 = 0;
  if (param_1 != &DMA0_CTRL) {
    iVar2 = 4;
  }
  RESET_PeripheralReset(*(undefined4 *)((int)&DAT_00200198 + iVar2));
  memw();
  param_1[2] = (dword)(&PTR_DAT_00236828)[param_1 != &DMA0_CTRL];
  memw();
  memw();
  *param_1 = *param_1 | 1;
  return;
}


// ===== DMA_Deinit @ 0020a644 (192 bytes)

/* fsl_dma.c order [inference] */

void DMA_Deinit(dword *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffffe;
  iVar2 = 0;
  if (param_1 != &DMA0_CTRL) {
    iVar2 = 4;
  }
  uVar1 = *(uint *)((int)&DAT_00200190 + iVar2);
  uVar3 = uVar1 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    return;
  }
  if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    return;
  }
  if (uVar3 != 2) {
    if (uVar3 == 3) {
      memw();
      CLKCTL1_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
      return;
    }
    if (uVar3 != 4) {
      if (uVar3 == 5) {
        memw();
        CLKCTL1_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
        return;
      }
      return;
    }
    memw();
    CLKCTL1_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    return;
  }
  memw();
  CLKCTL0_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
  return;
}


// ===== DMA_ConfigureChannelTrigger @ 0020a708 (51 bytes)

/* fsl_dma.c order [inference] */

void DMA_ConfigureChannelTrigger(int param_1,int param_2,uint *param_3)

{
  param_1 = param_1 + param_2 * 0x10;
  memw();
  memw();
  *(uint *)(param_1 + 0x400) =
       *param_3 | param_3[1] | param_3[2] | *(uint *)(param_1 + 0x400) & 0xffff308d;
  return;
}


// ===== DMA_GetRemainingBytes @ 0020a73c (80 bytes)

/* fsl_dma.c; called by the *_TransferGet*CountDMA functions [inference] */

int DMA_GetRemainingBytes(int param_1,uint param_2)

{
  int iVar1;
  
  memw();
  iVar1 = param_1 + param_2 * 0x10;
  if (((*(uint *)((param_2 >> 5 & 7) * 4 + param_1 + 0x30) >> (param_2 & 0x1f) & 1) == 0) &&
     (memw(), (*(uint *)(iVar1 + 0x408) & 0x3ff0000) == 0x3ff0000)) {
    return 0;
  }
  memw();
  return ((*(uint *)(iVar1 + 0x408) & 0x3ff0000) >> 0x10) + 1;
}


// ===== DMA_SetupDescriptor @ 0020a78c (140 bytes)

/* fsl_dma.c; called by DMA_CreateDescriptor and the I2S/DMIC/SPI DMA drivers [inference] */

void DMA_SetupDescriptor(uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = param_2 >> 8 & 3;
  if (uVar1 == 2) {
    if ((((param_3 != 0) && ((param_3 & 3) == 0)) && (param_4 != 0)) && ((param_4 & 3) == 0)) {
      uVar1 = 4;
      goto LAB_0020a7d3;
    }
  }
  else {
    uVar1 = uVar1 + 1;
    if (((param_3 != 0) && (param_3 % uVar1 == 0)) && ((param_4 != 0 && (param_4 % uVar1 == 0)))) {
LAB_0020a7d3:
      iVar2 = (param_2 >> 0xe & 3) - 3;
      iVar4 = (param_2 >> 0xc & 3) - 3;
      iVar3 = iVar2;
      if (iVar4 == 0) {
        iVar3 = 4;
      }
      if (iVar2 == 0) {
        iVar4 = 4;
      }
      memw();
      *param_1 = param_2;
      iVar2 = uVar1 * ((param_2 >> 0x10 & 0x3ff) + 1);
      param_1[3] = param_5;
      param_1[1] = (param_3 + iVar2 * iVar3) - iVar3 * uVar1;
      param_1[2] = (param_4 + iVar2 * iVar4) - iVar4 * uVar1;
      return;
    }
  }
  memw();
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ===== DMA_SetupChannelDescriptor @ 0020a818 (305 bytes)

/* fsl_dma.c order [inference] */

void DMA_SetupChannelDescriptor
               (uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5,undefined *param_6
               ,uint param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = param_2 >> 8 & 3;
  uVar4 = uVar1 + 1;
  if (uVar1 == 2) {
    if ((((param_3 == 0) || ((param_3 & 3) != 0)) || (param_4 == 0)) || ((param_4 & 3) != 0))
    goto LAB_0020a875;
    uVar4 = 4;
  }
  else if (((param_3 == 0) || (param_3 % uVar4 != 0)) || ((param_4 == 0 || (param_4 % uVar4 != 0))))
  {
LAB_0020a875:
    memw();
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    return;
  }
  iVar2 = (param_2 >> 0xc & 3) - 3;
  iVar5 = (param_2 >> 0xe & 3) - 3;
  iVar3 = iVar2;
  if (iVar5 == 0) {
    iVar3 = 4;
  }
  if (iVar2 == 0) {
    iVar5 = 4;
  }
  memw();
  *param_1 = param_2;
  if (param_6 == (undefined *)0x0) {
    iVar2 = uVar4 * ((param_2 >> 0x10 & 0x3ff) + 1);
    param_1[1] = (param_3 + iVar2 * iVar5) - iVar5 * uVar4;
    param_1[2] = (param_4 + iVar2 * iVar3) - iVar3 * uVar4;
  }
  if (param_6 == &DAT_00004000) {
    param_1[2] = (param_4 + iVar3 * uVar4 * ((param_2 >> 0x10 & 0x3ff) + 1)) - iVar3 * uVar4;
    param_1[1] = param_3 + iVar5 * uVar4 * ((1 << 0x20 - (0x20 - (param_7 & 0x1f))) + -1);
  }
  if (param_6 == &DAT_00008000) {
    param_1[1] = (param_3 + iVar5 * uVar4 * ((param_2 >> 0x10 & 0x3ff) + 1)) - iVar5 * uVar4;
    param_1[2] = param_4 + iVar3 * uVar4 * ((1 << 0x20 - (0x20 - (param_7 & 0x1f))) + -1);
  }
  if (param_6 != &DAT_0000c000) {
    param_1[3] = param_5;
    return;
  }
  iVar2 = uVar4 * ((1 << 0x20 - (0x20 - (param_7 & 0x1f))) + -1);
  param_1[3] = param_5;
  param_1[1] = param_3 + iVar2 * iVar5;
  param_1[2] = param_4 + iVar2 * iVar3;
  return;
}


// ===== DMA_CreateDescriptor @ 0020a94c (211 bytes)

/* fsl_dma.c; calls DMA_SetupDescriptor [inference] */

void DMA_CreateDescriptor
               (undefined4 param_1,byte *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2[6] == 4) {
    uVar1 = 0x200;
  }
  else {
    uVar1 = (param_2[6] - 1) * 0x100 & 0x300;
  }
  uVar2 = (uint)param_2[7] << 0xc;
  if (param_2[7] == 4) {
    uVar2 = 0x3000;
  }
  uVar3 = (uint)param_2[8] << 0xe;
  if (param_2[8] == 4) {
    uVar3 = 0xc000;
  }
  DMA_SetupDescriptor(param_1,uVar3 & (uint)&DAT_0000c000 |
                              (*(ushort *)(param_2 + 10) - 1) * 0x10000 & 0x3ff0000 |
                              uVar1 | uVar2 & (uint)&DAT_00003000 |
                              (param_2[4] & 1) << 4 | (param_2[5] & 1) << 5 |
                              (uint)*param_2 | (param_2[1] & 1) << 1 |
                              (param_2[2] & 1) << 2 | (param_2[3] & 1) << 3,param_3,param_4,param_5)
  ;
  return;
}


// ===== DMA_AbortTransfer @ 0020aa20 (145 bytes)

/* fsl_dma.c; called by every *_TransferAbort*DMA [inference] */

void DMA_AbortTransfer(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (uint)(*(byte *)(param_1 + 0xc) >> 5) * 4 + *(int *)(param_1 + 8);
  memw();
  memw();
  *(uint *)(iVar3 + 0x28) =
       *(uint *)(iVar3 + 0x28) | 1 << 0x20 - (0x20 - (*(byte *)(param_1 + 0xc) & 0x1f));
  uVar2 = (uint)*(byte *)(param_1 + 0xc);
  iVar3 = (uint)(*(byte *)(param_1 + 0xc) >> 5) * 4 + *(int *)(param_1 + 8);
  memw();
  uVar1 = *(uint *)(iVar3 + 0x38) >> (uVar2 & 0x1f);
  while ((uVar1 & 1) != 0) {
    memw();
    uVar1 = *(uint *)(iVar3 + 0x38) >> (uVar2 & 0x1f);
  }
  memw();
  memw();
  *(uint *)(iVar3 + 0x78) = *(uint *)(iVar3 + 0x78) | 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  iVar3 = (uint)(*(byte *)(param_1 + 0xc) >> 5) * 4 + *(int *)(param_1 + 8);
  memw();
  memw();
  *(uint *)(iVar3 + 0x20) =
       *(uint *)(iVar3 + 0x20) | 1 << 0x20 - (0x20 - (*(byte *)(param_1 + 0xc) & 0x1f));
  return;
}


// ===== DMA_CreateHandle @ 0020aab4 (115 bytes)

/* WARNING: Removing unreachable block (ram,0x0020aafa) */
/* WARNING: Removing unreachable block (ram,0x0020aafd) */
/* WARNING: Removing unreachable block (ram,0x0020ab00) */

void DMA_CreateHandle(undefined4 *param_1,dword *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != &DMA0_CTRL) {
    if (param_2 != &DMA0_CTRL) {
      iVar1 = 0x21;
    }
  }
  else {
    iVar1 = 0;
  }
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  *(char *)(param_1 + 3) = (char)param_3;
  (&DAT_00238470)[param_3 + iVar1] = param_1;
  DMA_GetVirtualStartChannel();
  return;
}


// ===== DMA_SetCallback @ 0020ab28 (9 bytes)

/* fsl_dma.c order [inference] */

void DMA_SetCallback(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== DMA_PrepareTransfer @ 0020ab34 (205 bytes)

/* fsl_dma.c order [inference] */

void DMA_PrepareTransfer(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                        uint param_5,int param_6,int param_7)

{
  undefined1 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  uVar1 = (undefined1)param_4;
  if (param_6 == 0) {
    *(undefined1 *)(param_1 + 6) = 0;
    param_1[1] = param_3;
    *param_1 = param_2;
    *(undefined1 *)((int)param_1 + 0x12) = uVar1;
    *(undefined1 *)((int)param_1 + 0x13) = 1;
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 3) = 1;
    param_1[2] = param_7;
    *(short *)((int)param_1 + 0x16) = (short)(param_5 / param_4);
    *(bool *)((int)param_1 + 0xd) = param_7 != 0;
    return;
  }
  if (param_6 != 1) {
    if (param_6 != 2) {
      *(undefined1 *)(param_1 + 6) = 1;
      param_1[1] = param_3;
      *param_1 = param_2;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 3) = 1;
      *(undefined1 *)((int)param_1 + 0x12) = uVar1;
      *(undefined1 *)((int)param_1 + 0x13) = 0;
      *(undefined1 *)(param_1 + 5) = 0;
      param_1[2] = param_7;
      *(short *)((int)param_1 + 0x16) = (short)(param_5 / param_4);
      *(bool *)((int)param_1 + 0xd) = param_7 != 0;
      return;
    }
    *(undefined1 *)(param_1 + 5) = 0;
    param_1[1] = param_3;
    *param_1 = param_2;
    *(undefined1 *)((int)param_1 + 0x12) = uVar1;
    *(undefined1 *)((int)param_1 + 0x13) = 1;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 3) = 1;
    param_1[2] = param_7;
    *(short *)((int)param_1 + 0x16) = (short)(param_5 / param_4);
    *(bool *)((int)param_1 + 0xd) = param_7 != 0;
    return;
  }
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined1 *)(param_1 + 6) = 1;
  param_1[1] = param_3;
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined1 *)(param_1 + 3) = 1;
  *(undefined1 *)((int)param_1 + 0x12) = uVar1;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  param_1[2] = param_7;
  *(short *)((int)param_1 + 0x16) = (short)(param_5 / param_4);
  *(undefined1 *)((int)param_1 + 0xd) = 1;
  return;
}


// ===== DMA_SetChannelConfig @ 0020ac04 (79 bytes)

/* fsl_dma.c order [inference] */

void DMA_SetChannelConfig(int param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  
  param_1 = param_1 + param_2 * 0x10;
  uVar1 = 0xfffffffe;
  if (param_3 != (uint *)0x0) {
    uVar1 = 0xffff308c;
  }
  memw();
  uVar1 = *(uint *)(param_1 + 0x400) & uVar1;
  if (param_3 != (uint *)0x0) {
    memw();
    *(uint *)(param_1 + 0x400) = param_4 | *param_3 | param_3[1] | param_3[2] | uVar1;
    return;
  }
  memw();
  *(uint *)(param_1 + 0x400) = param_4 | uVar1;
  return;
}


// ===== DMA_PrepareChannelTransfer @ 0020ac54 (82 bytes)

/* fsl_dma.c order [inference] */

void DMA_PrepareChannelTransfer
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5,undefined4 param_6,undefined4 param_7)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_5 == 0) {
    *(undefined1 *)(param_1 + 5) = 0;
    param_1[1] = param_3;
    *param_1 = param_2;
    param_1[4] = param_6;
    param_1[3] = param_4;
    param_1[2] = param_7;
    return;
  }
  if (param_5 != 1) {
    *(undefined1 *)(param_1 + 5) = 1;
    param_1[1] = param_3;
    *param_1 = param_2;
    param_1[4] = param_6;
    param_1[3] = param_4;
    param_1[2] = param_7;
    return;
  }
  *(undefined1 *)(param_1 + 5) = 1;
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[4] = param_6;
  param_1[3] = param_4;
  param_1[2] = param_7;
  return;
}


// ===== DMA_LoadChannelDescriptor @ 0020aca8 (91 bytes)

/* fsl_dma.c order [inference] */

void DMA_LoadChannelDescriptor(dword *param_1,int param_2,dword *param_3)

{
  int iVar1;
  dword *pdVar2;
  
  iVar1 = 0;
  if (param_1 != &DMA0_CTRL) {
    iVar1 = 4;
  }
  pdVar2 = (dword *)(param_2 * 0x10 + *(int *)((int)&PTR_DAT_00236828 + iVar1));
  memw();
  memw();
  *pdVar2 = *param_3;
  pdVar2[1] = param_3[1];
  pdVar2[2] = param_3[2];
  pdVar2[3] = param_3[3];
  memw();
  memw();
  param_1[param_2 * 4 + 0x102] = *param_3;
  return;
}


// ===== DMA_InstallDescriptorMemory @ 0020ad04 (10 bytes)

/* fsl_dma.c order [inference] */

void DMA_InstallDescriptorMemory(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}


// ===== DMA_SubmitChannelTransferParameter @ 0020ad10 (88 bytes)

/* fsl_dma.c order [inference] */

void DMA_SubmitChannelTransferParameter
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(dword **)(param_1 + 8) != &DMA0_CTRL) {
    iVar1 = 4;
  }
  DMA_SetupDescriptor(*(int *)((int)&PTR_DAT_00236828 + iVar1) +
                      (uint)*(byte *)(param_1 + 0xc) * 0x10,param_2,param_3,param_4,param_5);
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0xc) * 0x10 + 0x408) = param_2;
  return;
}


// ===== DMA_SubmitChannelDescriptor @ 0020ad68 (16 bytes)

/* fsl_dma.c; calls DMA_LoadChannelDescriptor [inference] */

void DMA_SubmitChannelDescriptor(int param_1,undefined4 param_2)

{
  DMA_LoadChannelDescriptor(*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),param_2);
  return;
}


// ===== DMA_SubmitChannelTransfer @ 0020ad78 (159 bytes)

/* fsl_dma.c order [inference] */

undefined * DMA_SubmitChannelTransfer(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  dword *pdVar5;
  uint uVar6;
  
  pdVar5 = *(dword **)(param_1 + 8);
  iVar3 = 0;
  if (pdVar5 != &DMA0_CTRL) {
    iVar3 = 4;
  }
  uVar6 = (uint)*(byte *)(param_1 + 0xc);
  iVar3 = *(int *)((int)&PTR_DAT_00236828 + iVar3);
  memw();
  if ((pdVar5[(*(byte *)(param_1 + 0xc) >> 5) + 0xc] >> (uVar6 & 0x1f) & 1) != 0) {
    return &DAT_00001388;
  }
  DMA_SetChannelConfig(pdVar5,uVar6,param_2[4],*(undefined1 *)(param_2 + 5));
  iVar2 = param_2[4];
  uVar4 = 0;
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = *(uint *)(iVar2 + 4) >> 8 & 0xf;
    uVar4 = *(undefined4 *)(iVar2 + 8);
  }
  DMA_SetupChannelDescriptor
            (iVar3 + uVar6 * 0x10,param_2[3],*param_2,param_2[1],param_2[2],uVar4,uVar1);
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0xc) * 0x10 + 0x408) =
       param_2[3];
  return (undefined *)0x0;
}

