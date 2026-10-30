// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== OTFAD_GetDefaultConfig @ 00212f20 (19 bytes)

/* fsl_otfad.c: zeroes the 4 config bytes [inference] */

void OTFAD_GetDefaultConfig(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ===== OTFAD_Init @ 00212f34 (105 bytes)

/* fsl_otfad.c: waits FlexSPI STS0 idle, then CR (+0xC00) |= flags [inference] */

void OTFAD_Init(int param_1,int param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(*(int *)(param_2 + 4) + 0xe0);
  while (((uVar1 & 2) == 0 || ((uVar1 & 1) == 0))) {
    memw();
    uVar1 = *(uint *)(*(int *)(param_2 + 4) + 0xe0);
  }
  memw();
  memw();
  *(uint *)(param_1 + 0xc00) =
       (*(byte *)(param_2 + 1) & 1) << 3 | (*(byte *)(param_2 + 2) & 1) << 7 |
       (uint)*(byte *)(param_2 + 3) << 0x1f | *(uint *)(param_1 + 0xc00);
  return;
}


// ===== OTFAD_Deinit @ 00212fa0 (28 bytes)

/* fsl_otfad.c: CR &= ~GE (bit 31) [inference] */

void OTFAD_Deinit(int param_1)

{
  memw();
  memw();
  *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) & 0x7fffffff;
  return;
}


// ===== OTFAD_SetEncryptionConfig @ 00212fbc (173 bytes)

/* fsl_otfad.c: kStatus_OTFAD_* 15000/15001 [inference] */

undefined * OTFAD_SetEncryptionConfig(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined *puVar4;
  uint uVar5;
  
  memw();
  if ((*(uint *)(param_1 + 0xc04) & 0x10000000) == 0) {
    bVar1 = param_2[1];
    uVar5 = *(uint *)(param_2 + 8);
    param_1 = param_1 + (uint)param_2[3] * 0x40;
    bVar2 = *param_2;
    puVar4 = &DAT_00003a99;
    if (*(uint *)(param_2 + 4) <= uVar5) {
      bVar3 = param_2[2];
      memw();
      *(uint *)(param_1 + 0xd18) = *(uint *)(param_2 + 4) & 0xfffffc00;
      memw();
      *(uint *)(param_1 + 0xd1c) =
           (uint)bVar2 | (bVar1 & 1) << 1 | uVar5 & 0xfffffc00 | (bVar3 & 1) << 2;
      puVar4 = (undefined *)0x0;
    }
    memw();
    *(undefined4 *)(param_1 + 0xd00) = *(undefined4 *)(param_2 + 0xc);
    memw();
    *(undefined4 *)(param_1 + 0xd04) = *(undefined4 *)(param_2 + 0x10);
    memw();
    *(undefined4 *)(param_1 + 0xd08) = *(undefined4 *)(param_2 + 0x14);
    memw();
    *(undefined4 *)(param_1 + 0xd0c) = *(undefined4 *)(param_2 + 0x18);
    memw();
    *(undefined4 *)(param_1 + 0xd10) = *(undefined4 *)(param_2 + 0x1c);
    memw();
    *(undefined4 *)(param_1 + 0xd14) = *(undefined4 *)(param_2 + 0x20);
    return puVar4;
  }
  return &DAT_00003a98;
}


// ===== OTFAD_GetEncryptionConfig @ 0021306c (143 bytes)

/* fsl_otfad.c order [inference] */

undefined * OTFAD_GetEncryptionConfig(int param_1,int param_2)

{
  int iVar1;
  
  memw();
  if ((*(uint *)(param_1 + 0xc04) & 0x10000000) != 0) {
    return &DAT_00003a98;
  }
  iVar1 = param_1 + (uint)*(byte *)(param_2 + 3) * 0x40;
  memw();
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar1 + 0xd00);
  memw();
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(iVar1 + 0xd04);
  memw();
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar1 + 0xd08);
  memw();
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar1 + 0xd0c);
  memw();
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0xd10);
  memw();
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar1 + 0xd14);
  memw();
  *(uint *)(param_2 + 4) = *(uint *)(iVar1 + 0xd18) >> 10;
  memw();
  *(uint *)(param_2 + 8) = *(uint *)(param_1 + (uint)*(byte *)(param_2 + 3) * 0x40 + 0xd1c) >> 10;
  return (undefined *)0x0;
}


// ===== OTFAD_HitDetermination @ 00213100 (109 bytes)

/* fsl_otfad.c order [inference] */

undefined8 OTFAD_HitDetermination(int param_1,uint param_2,undefined1 *param_3)

{
  bool bVar1;
  
  bVar1 = false;
  memw();
  memw();
  memw();
  if (((*(uint *)(param_1 + 0xd18) >> 10 <= param_2 >> 10) &&
      (param_2 >> 10 <= *(uint *)(param_1 + 0xd1c) >> 10)) &&
     ((*(uint *)(param_1 + 0xd1c) & 1) != 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    *param_3 = 0;
    return 0x100000000;
  }
  return 0x100003a9a;
}


// ===== PINT_PinInterruptClrFallFlag @ 00213170 (19 bytes)

/* fsl_pint.h inline: FALL (+0x20) = 1 << pin [fact for the code] */

void PINT_PinInterruptClrFallFlag(int param_1,uint param_2)

{
  memw();
  *(int *)(param_1 + 0x20) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  return;
}


// ===== PINT_PinInterruptClrRiseFlag @ 00213184 (19 bytes)

/* fsl_pint.h inline: RISE (+0x1C) = 1 << pin [fact for the code] */

void PINT_PinInterruptClrRiseFlag(int param_1,uint param_2)

{
  memw();
  *(int *)(param_1 + 0x1c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  return;
}


// ===== PINT_Init @ 00213198 (112 bytes)

/* fsl_pint.c: PINT 0x40025000, callback table 0x238F20 [inference] */

void PINT_Init(undefined4 *param_1)

{
  if (param_1 != &PINT_ISEL) {
    memw();
    param_1[0xc] = 0;
    return;
  }
  DAT_00238f20 = 0;
  DAT_00238f24 = 0;
  DAT_00238f28 = 0;
  DAT_00238f2c = 0;
  DAT_00238f30 = 0;
  DAT_00238f34 = 0;
  DAT_00238f38 = 0;
  DAT_00238f3c = 0;
  memw();
  CLKCTL1_PSCCTL2_SET = &RSTCTL0_SYSRSTSTAT;
  RESET_PeripheralReset(0x51e);
  memw();
  PINT_PMCFG = 0x3600;
  return;
}


// ===== PINT_PinInterruptConfig @ 0021320c (124 bytes)

/* fsl_pint.c order [inference] */

void PINT_PinInterruptConfig(uint *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  PINT_PinInterruptClrRiseFlag(param_1,param_2);
  PINT_PinInterruptClrFallFlag(param_1,param_2);
  uVar2 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  if (param_1 == &PINT_ISEL) {
    (&DAT_00238f20)[param_2] = param_4;
  }
  uVar1 = uVar2;
  if ((param_3 >> 4 & 1) == 0) {
    uVar1 = 0;
  }
  memw();
  memw();
  *param_1 = *param_1 & (uVar2 ^ 0xffffffff) | uVar1;
  if ((param_3 & 0x11) == 0) {
    memw();
    param_1[3] = uVar2;
  }
  else {
    memw();
    param_1[2] = uVar2;
  }
  if ((param_3 & 2) != 0) {
    memw();
    param_1[5] = uVar2;
    return;
  }
  memw();
  param_1[6] = uVar2;
  return;
}


// ===== PINT_PinInterruptGetConfig @ 00213288 (105 bytes)

/* fsl_pint.c order [inference] */

void PINT_PinInterruptGetConfig(uint *param_1,uint param_2,int *param_3,undefined4 *param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  *param_3 = 0;
  uVar2 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  memw();
  bVar1 = (*param_1 & uVar2) != 0;
  memw();
  if ((uVar2 & param_1[1]) != 0) {
    iVar3 = 1;
    if (bVar1) {
      iVar3 = 0x10;
    }
    *param_3 = iVar3;
  }
  memw();
  if ((uVar2 & param_1[4]) != 0) {
    if (bVar1) {
      *param_3 = 0x12;
    }
    else {
      iVar4 = 2;
      if (iVar3 == 1) {
        iVar4 = 3;
      }
      *param_3 = iVar4;
    }
  }
  if (param_1 != &PINT_ISEL) {
    return;
  }
  *param_4 = (&DAT_00238f20)[param_2];
  return;
}


// ===== PINT_PatternMatchConfig @ 002132f4 (136 bytes)

/* fsl_pint.c order [inference] */

void PINT_PatternMatchConfig(undefined4 *param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2 * 3 + 8;
  iVar1 = 0x20 - (uVar2 & 0x1f);
  uVar3 = 7 << 0x20 - iVar1 ^ 0xffffffff;
  memw();
  memw();
  param_1[0xb] = param_1[0xb] & uVar3 | *param_3 << 0x20 - iVar1;
  memw();
  uVar2 = uVar3 & param_1[0xc] | param_3[1] << 0x20 - (0x20 - (uVar2 & 0x1f));
  if (param_2 != 7) {
    uVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
    if ((char)param_3[2] == '\0') {
      uVar2 = uVar2 & (uVar3 ^ 0xffffffff);
    }
    else {
      uVar2 = uVar3 | uVar2;
    }
  }
  memw();
  param_1[0xc] = uVar2;
  if ((param_1 == &PINT_ISEL) && (param_2 < 8)) {
    (&DAT_00238f20)[param_2] = param_3[3];
    return;
  }
  return;
}


// ===== PINT_PatternMatchGetConfig @ 0021337c (120 bytes)

/* fsl_pint.c order [inference] */

void PINT_PatternMatchGetConfig(undefined4 *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 * 3 + 8;
  uVar2 = 7 << 0x20 - (0x20 - (uVar1 & 0x1f));
  memw();
  *param_3 = (param_1[0xb] & uVar2) >> (uVar1 & 0x1f);
  memw();
  param_3[1] = (param_1[0xc] & uVar2) >> (uVar1 & 0x1f);
  if (param_2 == 7) {
    *(undefined1 *)(param_3 + 2) = 1;
  }
  else {
    memw();
    *(bool *)(param_3 + 2) =
         (uint)(param_1[0xc] & 1 << 0x20 - (0x20 - (param_2 & 0x1f))) >> (param_2 & 0x1f) != 0;
  }
  if ((param_1 == &PINT_ISEL) && (param_2 < 8)) {
    param_3[3] = (&DAT_00238f20)[param_2];
    return;
  }
  return;
}


// ===== PINT_PatternMatchResetDetectLogic @ 002133f8 (33 bytes)

/* fsl_pint.c; called first by every PIN_INTn handler [inference] */

uint PINT_PatternMatchResetDetectLogic(int param_1)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x28) >> 0x18;
  if (uVar1 != 0) {
    memw();
    memw();
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    return uVar1;
  }
  return 0;
}


// ===== PINT_PinInterruptClrStatus @ 0021341c (44 bytes)

/* fsl_pint.c (base, pin); called by the handlers [inference] */

void PINT_PinInterruptClrStatus(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  memw();
  memw();
  if (((*param_1 & uVar1) == 0) && ((param_1[9] & uVar1) != 0)) {
    memw();
    param_1[9] = uVar1;
    return;
  }
  return;
}


// ===== PINT_PinInterruptClrStatusAll @ 00213448 (93 bytes)

/* fsl_pint.c order [inference] */

void PINT_PinInterruptClrStatusAll(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)(param_1 == &PINT_ISEL);
  uVar2 = 0;
  if (uVar1 != 0) {
    if ((uVar1 != 0) && ((uVar1 << 3 == 1 || (uVar1 != 0)))) {
      memw();
      memw();
      if (((*param_1 & 1) == 0) && ((param_1[9] & 1) != 0)) {
        uVar2 = 1;
      }
    }
    memw();
    param_1[9] = uVar2;
    return;
  }
  memw();
  param_1[9] = 0;
  return;
}


// ===== PINT_EnableCallback @ 002134a8 (32 bytes)

/* fsl_pint.c order [inference] */

void PINT_EnableCallback(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == &PINT_ISEL) {
    do {
      PINT_PinInterruptClrStatus(&PINT_ISEL,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 != 8);
  }
  return;
}


// ===== PINT_EnableCallbackByIndex @ 002134c8 (14 bytes)

/* fsl_pint.c order [inference] */

void PINT_EnableCallbackByIndex(undefined4 param_1,undefined4 param_2)

{
  PINT_PinInterruptClrStatus(param_1,param_2);
  return;
}


// ===== PINT_DisableCallback @ 002134d8 (32 bytes)

/* fsl_pint.c order [inference] */

void PINT_DisableCallback(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == &PINT_ISEL) {
    do {
      PINT_PinInterruptClrStatus(&PINT_ISEL,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 != 8);
  }
  return;
}


// ===== PINT_DisableCallbackByIndex @ 002134f8 (22 bytes)

/* fsl_pint.c order [inference] */

void PINT_DisableCallbackByIndex(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != &PINT_ISEL) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,param_2);
  return;
}


// ===== PINT_Deinit @ 00213514 (56 bytes)

/* fsl_pint.c: DisableCallback, reset [inference] */

void PINT_Deinit(undefined4 *param_1)

{
  PINT_DisableCallback(param_1);
  if (param_1 == &PINT_ISEL) {
    DAT_00238f20 = 0;
    DAT_00238f24 = 0;
    DAT_00238f28 = 0;
    DAT_00238f2c = 0;
    DAT_00238f30 = 0;
    DAT_00238f34 = 0;
    DAT_00238f38 = 0;
    DAT_00238f3c = 0;
    memw();
    CLKCTL1_PSCCTL2_CLR = &RSTCTL0_SYSRSTSTAT;
    RESET_PeripheralReset(0x51e);
  }
  return;
}


// ===== PIN_INT0_DriverIRQHandler @ 0021354c (50 bytes)

/* fsl_pint.c: callback[0](0, status) [fact for the code] */

void PIN_INT0_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f20 != (code *)0x0) {
    (*DAT_00238f20)(0,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 1) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,0);
  return;
}


// ===== PIN_INT1_DriverIRQHandler @ 00213584 (50 bytes)

/* fsl_pint.c: callback[1] [fact for the code] */

void PIN_INT1_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f24 != (code *)0x0) {
    (*DAT_00238f24)(1,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 2) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,1);
  return;
}


// ===== PIN_INT2_DriverIRQHandler @ 002135bc (50 bytes)

/* fsl_pint.c: callback[2] [fact for the code] */

void PIN_INT2_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f28 != (code *)0x0) {
    (*DAT_00238f28)(2,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 4) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,2);
  return;
}


// ===== PIN_INT3_DriverIRQHandler @ 002135f0 (50 bytes)

/* fsl_pint.c: callback[3] [fact for the code] */

void PIN_INT3_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f2c != (code *)0x0) {
    (*DAT_00238f2c)(3,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 8) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,3);
  return;
}


// ===== PIN_INT4_DriverIRQHandler @ 00213628 (50 bytes)

/* fsl_pint.c: callback[4] [inference] */

void PIN_INT4_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f30 != (code *)0x0) {
    (*DAT_00238f30)(4,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 0x10) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,4);
  return;
}


// ===== PIN_INT5_DriverIRQHandler @ 0021365c (50 bytes)

/* fsl_pint.c: callback[5] [inference] */

void PIN_INT5_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f34 != (code *)0x0) {
    (*DAT_00238f34)(5,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 0x20) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,5);
  return;
}


// ===== PIN_INT6_DriverIRQHandler @ 00213690 (50 bytes)

/* fsl_pint.c: callback[6] [inference] */

void PIN_INT6_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f38 != (code *)0x0) {
    (*DAT_00238f38)(6,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 0x40) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,6);
  return;
}


// ===== PIN_INT7_DriverIRQHandler @ 002136c8 (50 bytes)

/* fsl_pint.c: callback[7] [inference] */

void PIN_INT7_DriverIRQHandler(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00238f3c != (code *)0x0) {
    (*DAT_00238f3c)(7,uVar2);
  }
  memw();
  uVar1 = PINT_ISEL;
  if ((uVar1 & 0x80) != 0) {
    return;
  }
  PINT_PinInterruptClrStatus(&PINT_ISEL,7);
  return;
}


// ===== RESET_SetPeripheralReset @ 00213700 (261 bytes)

/* fsl_reset.c: RSTCTL0/1 PRSTCTL_SET, wait [inference] */

void RESET_SetPeripheralReset(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 >> 8 & 0xff;
  if (uVar2 == 0) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL0_PRSTCTL0_SET = uVar1;
    memw();
    uVar2 = RSTCTL0_PRSTCTL0;
    while ((uVar2 & uVar1) == 0) {
      memw();
      uVar2 = RSTCTL0_PRSTCTL0;
    }
  }
  else if (uVar2 == 1) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL0_PRSTCTL1_SET = uVar1;
    memw();
    uVar2 = RSTCTL0_PRSTCTL1;
    if ((uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL0_PRSTCTL1;
      } while ((uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 2) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL0_PRSTCTL2_SET = uVar1;
    memw();
    uVar2 = RSTCTL0_PRSTCTL2;
    if ((uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL0_PRSTCTL2;
      } while ((uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 3) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL1_PRSTCTL0_SET = uVar1;
    memw();
    uVar2 = RSTCTL1_PRSTCTL0;
    if ((uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL1_PRSTCTL0;
      } while ((uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 4) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL1_PRSTCTL1_SET = uVar1;
    memw();
    uVar2 = RSTCTL1_PRSTCTL1;
    if ((uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL1_PRSTCTL1;
      } while ((uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 5) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL1_PRSTCTL2_SET = uVar1;
    memw();
    uVar2 = RSTCTL1_PRSTCTL2;
    if ((uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL1_PRSTCTL2;
      } while ((uVar2 & uVar1) == 0);
      return;
    }
  }
  return;
}


// ===== RESET_ClearPeripheralReset @ 00213808 (261 bytes)

/* fsl_reset.c: PRSTCTL_CLR, wait [inference] */

void RESET_ClearPeripheralReset(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 >> 8 & 0xff;
  if (uVar2 == 0) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL0_PRSTCTL0_CLR = uVar1;
    memw();
    uVar2 = RSTCTL0_PRSTCTL0;
    while ((~uVar2 & uVar1) == 0) {
      memw();
      uVar2 = RSTCTL0_PRSTCTL0;
    }
  }
  else if (uVar2 == 1) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL0_PRSTCTL1_CLR = uVar1;
    memw();
    uVar2 = RSTCTL0_PRSTCTL1;
    if ((~uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL0_PRSTCTL1;
      } while ((~uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 2) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL0_PRSTCTL2_CLR = uVar1;
    memw();
    uVar2 = RSTCTL0_PRSTCTL2;
    if ((~uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL0_PRSTCTL2;
      } while ((~uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 3) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL1_PRSTCTL0_CLR = uVar1;
    memw();
    uVar2 = RSTCTL1_PRSTCTL0;
    if ((~uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL1_PRSTCTL0;
      } while ((~uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 4) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL1_PRSTCTL1_CLR = uVar1;
    memw();
    uVar2 = RSTCTL1_PRSTCTL1;
    if ((~uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL1_PRSTCTL1;
      } while ((~uVar2 & uVar1) == 0);
      return;
    }
  }
  else if (uVar2 == 5) {
    uVar1 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    memw();
    RSTCTL1_PRSTCTL2_CLR = uVar1;
    memw();
    uVar2 = RSTCTL1_PRSTCTL2;
    if ((~uVar2 & uVar1) == 0) {
      do {
        memw();
        uVar2 = RSTCTL1_PRSTCTL2;
      } while ((~uVar2 & uVar1) == 0);
      return;
    }
  }
  return;
}


// ===== RESET_PeripheralReset @ 00213910 (15 bytes)

/* fsl_reset.c: set then clear; 16 callers (every driver Init) [inference] */

void RESET_PeripheralReset(undefined4 param_1)

{
  RESET_SetPeripheralReset(param_1);
  RESET_ClearPeripheralReset(param_1);
  return;
}


// ===== RTC_Init @ 00213920 (48 bytes)

/* fsl_rtc.c (lpc_rtc) order [inference] */

void RTC_Init(uint *param_1)

{
  memw();
  CLKCTL1_PSCCTL2_SET = 0x80;
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffffe;
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffeff;
  return;
}


// ===== RTC_SetDatetime @ 00213950 (296 bytes)

/* fsl_rtc.c: days table 0x2004D0, year <= 2099, 86400 / 3600 s [fact for the constants] */

undefined4 RTC_SetDatetime(int param_1,ushort *param_2)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte abStack_60 [16];
  ushort auStack_50 [16];
  uint uStack_30;
  uint uStack_2c;
  
  uVar1 = *param_2;
  uVar5 = (uint)uVar1;
  abStack_60[0] = 0;
  abStack_60[1] = 0x1f;
  abStack_60[2] = 0x1c;
  abStack_60[3] = 0x1f;
  abStack_60[4] = 0x1e;
  abStack_60[5] = 0x1f;
  abStack_60[6] = 0x1e;
  abStack_60[7] = 0x1f;
  abStack_60[8] = 0x1f;
  abStack_60[9] = 0x1e;
  abStack_60[10] = 0x1f;
  abStack_60[0xb] = 0x1e;
  abStack_60[0xc] = 0x1f;
  uVar6 = (uint)(byte)param_2[1];
  if ((((0x7b1 < uVar5) && (uVar5 < 0x834)) && (uVar6 < 0xd)) && (uVar6 != 0)) {
    bVar3 = (byte)param_2[2];
    bVar2 = *(byte *)((int)param_2 + 5);
    uStack_2c = (uint)(byte)param_2[3];
    if ((bVar3 < 0x18) && (bVar2 < 0x3c)) {
      uStack_30 = uVar5 & 3;
      if (uStack_2c < 0x3c) {
        if ((((uVar1 & 3) == 0) && (uVar5 % 100 != 0)) || (uVar5 % 400 == 0)) {
          abStack_60[0] = 0;
          abStack_60[1] = 0x1f;
          abStack_60[2] = 0x1d;
          abStack_60[3] = 0x1f;
        }
        uVar4 = (uint)*(byte *)((int)param_2 + 3);
        if (uVar4 <= abStack_60[uVar6]) {
          if (uVar4 != 0) {
            memcpy(auStack_50,&DAT_002004b0,0x1a);
            iVar7 = uVar4 + (uint)auStack_50[uVar6] + (uint)(uVar1 >> 2) + uVar5 * 0x16d;
            if ((uStack_30 == 0) && (uVar6 < 3)) {
              memw();
              *(uint *)(param_1 + 8) =
                   uStack_2c + (short)(ushort)bVar2 * 0x3c +
                   (short)(ushort)bVar3 * 0xe10 + (iVar7 + -0xafab8) * (int)&DAT_00015180;
              return 0;
            }
            memw();
            *(uint *)(param_1 + 8) =
                 uStack_2c + (short)(ushort)bVar2 * 0x3c +
                 (short)(ushort)bVar3 * 0xe10 + (iVar7 + -0xafab7) * (int)&DAT_00015180;
            return 0;
          }
        }
      }
    }
  }
  return 4;
}


// ===== RTC_GetDatetime @ 00213a78 (194 bytes)

/* fsl_rtc.c order [inference] */

void RTC_GetDatetime(int param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  
  do {
    memw();
    memw();
    uVar2 = *(uint *)(param_1 + 8);
  } while (*(uint *)(param_1 + 8) != uVar2);
  *param_2 = 0x7b2;
  uVar1 = (uVar2 % (uint)&DAT_00015180) % 0xe10;
  *(char *)(param_2 + 2) = (char)((uVar2 % (uint)&DAT_00015180) / 0xe10);
  *(char *)(param_2 + 3) = (char)(uVar1 % 0x3c);
  uVar2 = uVar2 / (uint)&DAT_00015180 + 1;
  *(char *)((int)param_2 + 5) = (char)(uVar1 / 0x3c);
  uVar3 = 0x7b2;
  if (0x16d < uVar2) {
    uVar1 = 0x16d;
    do {
      uVar3 = uVar3 + 1;
      uVar2 = uVar2 - uVar1;
      uVar1 = 0x16e;
      *param_2 = uVar3;
      if ((uVar3 & 3) != 0) {
        uVar1 = 0x16d;
      }
    } while (uVar1 < uVar2);
  }
  if (0x1f < uVar2) {
    *(char *)((int)param_2 + 3) = (char)uVar2 + -0x1f;
    return;
  }
  *(undefined1 *)(param_2 + 1) = 1;
  *(char *)((int)param_2 + 3) = (char)uVar2;
  return;
}


// ===== RTC_SetAlarm @ 00213b3c (283 bytes)

/* fsl_rtc.c order [inference] */

undefined4 RTC_SetAlarm(int param_1,ushort *param_2)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte abStack_60 [16];
  ushort auStack_50 [16];
  uint uStack_30;
  uint uStack_2c;
  
  uVar1 = *param_2;
  uVar4 = (uint)uVar1;
  abStack_60[0] = 0;
  abStack_60[1] = 0x1f;
  abStack_60[2] = 0x1c;
  abStack_60[3] = 0x1f;
  abStack_60[4] = 0x1e;
  abStack_60[5] = 0x1f;
  abStack_60[6] = 0x1e;
  abStack_60[7] = 0x1f;
  abStack_60[8] = 0x1f;
  abStack_60[9] = 0x1e;
  abStack_60[10] = 0x1f;
  abStack_60[0xb] = 0x1e;
  abStack_60[0xc] = 0x1f;
  uVar5 = (uint)(byte)param_2[1];
  if ((((0x7b1 < uVar4) && (uVar4 < 0x834)) && (uVar5 < 0xd)) && (uVar5 != 0)) {
    uVar3 = param_2[2];
    bVar2 = *(byte *)((int)param_2 + 5);
    uStack_2c = (uint)(byte)param_2[3];
    if (((byte)uVar3 < 0x18) && (bVar2 < 0x3c)) {
      uStack_30 = uVar4 & 3;
      if (uStack_2c < 0x3c) {
        uVar6 = (uint)*(byte *)((int)param_2 + 3);
        if ((((uVar1 & 3) == 0) && (uVar4 % 100 != 0)) || (uVar4 % 400 == 0)) {
          abStack_60[0] = 0;
          abStack_60[1] = 0x1f;
          abStack_60[2] = 0x1d;
          abStack_60[3] = 0x1f;
        }
        if (uVar6 <= abStack_60[uVar5]) {
          if (uVar6 != 0) {
            memcpy(auStack_50,&DAT_002004b0,0x1a);
            iVar7 = uVar6 + (uint)auStack_50[uVar5] + (uint)(uVar1 >> 2) + uVar4 * 0x16d;
            iVar8 = iVar7 + -0xafab7;
            if ((uStack_30 == 0) && (uVar5 < 3)) {
              iVar8 = iVar7 + -0xafab8;
            }
            uVar4 = uStack_2c + (short)(ushort)bVar2 * 0x3c +
                    (short)(ushort)(byte)uVar3 * 0xe10 + iVar8 * (int)&DAT_00015180;
            do {
              memw();
              memw();
            } while (*(uint *)(param_1 + 8) != *(uint *)(param_1 + 8));
            if (uVar4 < *(uint *)(param_1 + 8)) {
              return 1;
            }
            memw();
            *(uint *)(param_1 + 4) = uVar4;
            return 0;
          }
        }
      }
    }
  }
  return 4;
}


// ===== RTC_GetAlarm @ 00213c58 (179 bytes)

/* fsl_rtc.c order [inference] */

void RTC_GetAlarm(int param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  
  memw();
  uVar4 = *(uint *)(param_1 + 4);
  *param_2 = 0x7b2;
  uVar2 = uVar4 % (uint)&DAT_00015180;
  uVar1 = uVar2 % 0xe10;
  *(char *)(param_2 + 2) = (char)(uVar2 / 0xe10);
  *(char *)(param_2 + 3) = (char)(uVar1 % 0x3c);
  *(char *)((int)param_2 + 5) = (char)(uVar1 / 0x3c);
  uVar1 = uVar4 / (uint)&DAT_00015180 + 1;
  uVar3 = 0x7b2;
  if (0x16d < uVar1) {
    uVar2 = 0x16d;
    do {
      uVar3 = uVar3 + 1;
      uVar1 = uVar1 - uVar2;
      uVar2 = 0x16e;
      *param_2 = uVar3;
      if ((uVar3 & 3) != 0) {
        uVar2 = 0x16d;
      }
    } while (uVar2 < uVar1);
  }
  if (0x1f < uVar1) {
    *(char *)((int)param_2 + 3) = (char)uVar1 + -0x1f;
    return;
  }
  *(undefined1 *)(param_2 + 1) = 1;
  *(char *)((int)param_2 + 3) = (char)uVar1;
  return;
}


// ===== SEMA42_GetInstance @ 00213d10 (19 bytes)

/* base -> index via table 0x2004E0 */

bool SEMA42_GetInstance(byte *param_1)

{
  return param_1 != &SEMA42_GATE3;
}


// ===== SEMA42_Init @ 00213d24 (150 bytes)

/* CLOCK_EnableClock(SEMA42) inlined (CLKCTL PSCCTL SET) */

void SEMA42_Init(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = SEMA42_GetInstance(param_1);
  uVar2 = *(uint *)(&DAT_002004e4 + iVar1 * 4);
  uVar3 = uVar2 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 != 3) {
    if (uVar3 == 4) {
      memw();
      CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      return;
    }
    if (uVar3 != 5) {
      return;
    }
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  memw();
  CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  return;
}


// ===== SEMA42_Deinit @ 00213dbc (150 bytes)

/* CLOCK_DisableClock(SEMA42) inlined (CLKCTL PSCCTL CLR) */

void SEMA42_Deinit(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = SEMA42_GetInstance(param_1);
  uVar2 = *(uint *)(&DAT_002004e4 + iVar1 * 4);
  uVar3 = uVar2 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 == 2) {
    memw();
    CLKCTL0_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 != 3) {
    if (uVar3 == 4) {
      memw();
      CLKCTL1_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      return;
    }
    if (uVar3 != 5) {
      return;
    }
    memw();
    CLKCTL1_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  memw();
  CLKCTL1_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  return;
}


// ===== SEMA42_TryLock @ 00213e54 (45 bytes)

/* gate byte at base + (gate ^ 3) = proc+1, read back */

undefined4 SEMA42_TryLock(int param_1,uint param_2,char param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + ((param_2 ^ 3) & 0xff));
  memw();
  *pcVar2 = param_3 + '\x01';
  memw();
  uVar1 = 0;
  if ((char)(param_3 + '\x01') != *pcVar2) {
    uVar1 = 0x640;
  }
  return uVar1;
}


// ===== SEMA42_Lock @ 00213e84 (73 bytes)

/* spin until gate free, then lock */

void SEMA42_Lock(int param_1,uint param_2,char param_3)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + ((param_2 ^ 3) & 0xff));
  memw();
  cVar1 = *pcVar2;
  while ((char)(param_3 + '\x01') != cVar1) {
    memw();
    cVar1 = *pcVar2;
    while (cVar1 != '\0') {
      memw();
      cVar1 = *pcVar2;
    }
    memw();
    *pcVar2 = param_3 + '\x01';
    memw();
    cVar1 = *pcVar2;
  }
  return;
}


// ===== SEMA42_ResetGate @ 00213ed0 (45 bytes)

/* RSTGT = 0xE200 then 0x1D00 | gate */

undefined4 SEMA42_ResetGate(int param_1,ushort param_2)

{
  memw();
  if ((*(ushort *)(param_1 + 0x42) >> 0xc & 3) != 0) {
    return 0x641;
  }
  memw();
  *(undefined2 *)(param_1 + 0x42) = 0xe200;
  memw();
  *(ushort *)(param_1 + 0x42) = param_2 | 0x1d00;
  return 0;
}


// ===== SPI_SlaveTransferHandleIRQ @ 00213f00 (14 bytes)

/* fsl_spi.h inline emitted at the start of fsl_spi.c: forwards to SPI_MasterTransferHandleIRQ;
   installed by SPI_MasterTransferCreateHandle for slave mode [inference] */

void SPI_SlaveTransferHandleIRQ(undefined4 param_1,undefined4 param_2)

{
  SPI_MasterTransferHandleIRQ(param_1,param_2);
  return;
}


// ===== SPI_GetInstance @ 00213f10 (30 bytes)

/* fsl_spi.c: 8 bases at 0x2004F0 [inference] */

bool SPI_GetInstance(dword *param_1)

{
  return param_1 != &USART0_CFG;
}


// ===== SPI_SetDummyData @ 00213f30 (21 bytes)

/* fsl_spi.c: s_dummyData 0x238F40 [inference] */

void SPI_SetDummyData(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = SPI_GetInstance(param_1);
  memw();
  (&DAT_00238f40)[iVar1] = param_2;
  return;
}


// ===== SPI_GetConfig @ 00213f48 (16 bytes)

/* fsl_spi.c: g_configs 0x238F50 [inference] */

undefined * SPI_GetConfig(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = SPI_GetInstance(param_1);
  return &DAT_00238f50 + iVar1 * 8;
}


// ===== SPI_MasterGetDefaultConfig @ 00213f58 (67 bytes)

void SPI_MasterGetDefaultConfig(undefined1 *param_1)

{
  memset(param_1,0,0x28);
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[1] = 1;
  *(undefined **)(param_1 + 0x10) = &DAT_0007a120;
  *(undefined4 *)(param_1 + 0x14) = 7;
  return;
}


// ===== SPI_MasterInit @ 00213f9c (373 bytes)

int SPI_MasterInit(int param_1,byte *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == (byte *)0x0)) || (param_3 == 0)) {
    return 4;
  }
  iVar1 = FLEXCOMM_Init(param_1,2);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = SPI_MasterSetBaud(param_1,*(undefined4 *)(param_2 + 0x10),param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = SPI_GetInstance(param_1);
  memw();
  memw();
  uVar2 = *(undefined4 *)(param_2 + 0x14);
  *(uint *)(param_1 + 0x400) =
       *(uint *)(param_1 + 0x400) & 0xfffff042 | (*(uint *)(param_2 + 8) & 1) << 4 |
       (*(uint *)(param_2 + 4) & 1) << 5 | (*(uint *)(param_2 + 0xc) & 1) << 3 | (*param_2 & 1) << 7
       | 4 | *(uint *)(param_2 + 0x1c) & (uint)&DAT_00000f00;
  *(undefined4 *)(&DAT_00238f50 + iVar1 * 8) = uVar2;
  *(undefined4 *)(&DAT_00238f54 + iVar1 * 8) = *(undefined4 *)(param_2 + 0x18);
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00030000;
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | 3;
  memw();
  memw();
  *(uint *)(param_1 + 0xe08) =
       *(uint *)(param_1 + 0xe08) & 0xfff0f0ff |
       (param_2[0x20] & 0xf) << 8 | (param_2[0x21] & 0xf) << 0x10 | 3;
  memw();
  *(uint *)(param_1 + 0x404) =
       param_2[0x22] & 0xf | (param_2[0x23] & 0xf) << 4 |
       (param_2[0x24] & 0xf) << 8 | (param_2[0x25] & 0xf) << 0xc;
  SPI_SetDummyData(param_1,0xff);
  if (param_2[1] != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0x400) = *(uint *)(param_1 + 0x400) | 1;
    return 0;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x400) = *(uint *)(param_1 + 0x400) & 0xfffffffe;
  return 0;
}


// ===== SPI_SlaveGetDefaultConfig @ 00214114 (38 bytes)

/* fsl_spi.c order [inference] */

void SPI_SlaveGetDefaultConfig(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = 7;
  *param_1 = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined1 *)param_1 = 1;
  return;
}

