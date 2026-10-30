// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== I3C_SlaveSend @ 00211f68 (135 bytes)

/* fsl_i3c.c order [inference] */

int I3C_SlaveSend(int param_1,byte *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  param_3 = param_3 + -1;
  if (param_3 == -1) {
    return 0;
  }
  do {
    memw();
    uVar4 = *(uint *)(param_1 + 0x60);
    do {
      memw();
      uVar3 = *(uint *)(param_1 + 0x2c);
      uVar1 = I3C_SlaveGetErrorStatusFlags(param_1);
      iVar2 = I3C_SlaveCheckAndClearError(param_1,uVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
    } while (2 << 0x20 - (0x20 - ((uVar4 & 0xc000000) >> 0x1a)) ==
             (uVar3 & (uint)&DAT_001f0000) >> 0x10);
    if (param_3 == 0) {
      memw();
      *(uint *)(param_1 + 0x34) = (uint)*param_2;
    }
    else {
      memw();
      *(uint *)(param_1 + 0x30) = (uint)*param_2;
    }
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != -1);
  return 0;
}


// ===== I3C_SlaveReceive @ 00211ff0 (59 bytes)

/* fsl_i3c.c order [inference] */

int I3C_SlaveReceive(int param_1,undefined1 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  do {
    uVar1 = I3C_SlaveGetErrorStatusFlags(param_1);
    iVar2 = I3C_SlaveCheckAndClearError(param_1,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    memw();
    if ((*(uint *)(param_1 + 0x2c) & 0x1f000000) != 0) {
      memw();
      param_3 = param_3 + -1;
      *param_2 = (char)*(undefined4 *)(param_1 + 0x40);
      param_2 = param_2 + 1;
    }
  } while (param_3 != 0);
  return 0;
}


// ===== I3C_SlaveTransferCreateHandle @ 0021202c (52 bytes)

/* fsl_i3c.c: handler 0x2120F4 [inference] */

void I3C_SlaveTransferCreateHandle
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  memset(param_2,0,0x38);
  iVar1 = I3C_GetInstance(param_1);
  *(undefined4 *)(param_2 + 0x2c) = param_4;
  *(undefined4 *)(param_2 + 0x28) = param_3;
  DAT_00238e34 = I3C_SlaveTransferHandleIRQ;
  (&DAT_00238f10)[iVar1] = param_2;
  I3C_SlaveDisableInterrupts(param_1,&DAT_0007ef00);
  return;
}


// ===== I3C_SlaveTransferNonBlocking @ 00212060 (69 bytes)

/* fsl_i3c.c order [inference] */

undefined * I3C_SlaveTransferNonBlocking(int param_1,undefined4 *param_2,uint param_3)

{
  if (*(char *)(param_2 + 7) != '\0') {
    return &DAT_00001edc;
  }
  I3C_SlaveDisableInterrupts(param_1,&DAT_0007ef00);
  param_2[6] = 0;
  param_2[5] = 0;
  param_2[4] = 0;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  param_2[8] = param_3 | 6;
  memw();
  *(undefined4 *)(param_1 + 8) = 0x700;
  I3C_SlaveEnableInterrupts(param_1,&DAT_0007ef00);
  return (undefined *)0x0;
}


// ===== I3C_SlaveTransferGetCount @ 002120a8 (34 bytes)

/* fsl_i3c.c order [inference] */

undefined4 I3C_SlaveTransferGetCount(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 4;
  }
  if (*(char *)(param_2 + 0x1c) != '\0') {
    *param_3 = *(undefined4 *)(param_2 + 0x24);
    return 0;
  }
  *param_3 = 0;
  return 6;
}


// ===== I3C_SlaveTransferAbort @ 002120cc (40 bytes)

/* fsl_i3c.c order [inference] */

void I3C_SlaveTransferAbort(undefined4 param_1,undefined4 *param_2)

{
  if (*(char *)(param_2 + 7) != '\0') {
    I3C_SlaveDisableInterrupts(param_1,&DAT_0007ef00);
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    *(undefined1 *)(param_2 + 7) = 0;
    return;
  }
  return;
}


// ===== I3C_SlaveTransferHandleIRQ @ 002120f4 (745 bytes)

/* fsl_i3c.c order [inference] */

void I3C_SlaveTransferHandleIRQ(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  uint uStack_24;
  
  memw();
  uVar5 = *(uint *)(param_1 + 0x60);
  if (param_2 == (undefined4 *)0x0) {
    return;
  }
  memw();
  uVar8 = *(uint *)(param_1 + 8) & 0xfcfffff;
  uVar2 = I3C_SlaveGetErrorStatusFlags(param_1);
  uStack_24 = I3C_SlaveGetPendingInterrupts(param_1);
  uVar3 = I3C_SlaveGetEnabledInterrupts(param_1);
  if ((uVar2 & (uint)&DAT_00030f1f) != 0) {
    *param_2 = 0x40;
    uVar4 = I3C_SlaveCheckAndClearError(param_1,uVar2);
    param_2[5] = uVar4;
    if ((param_2[8] & 0x40) == 0) {
      return;
    }
    if ((code *)param_2[10] == (code *)0x0) {
      return;
    }
    (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    return;
  }
  memw();
  *(uint *)(param_1 + 8) = uVar8;
  if ((uVar8 >> 8 & 1) != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 3;
    param_2[2] = 0;
    I3C_SlaveEnableInterrupts(param_1,&DAT_00001000);
    uStack_24 = uStack_24 | (uint)&DAT_00001000;
    memw();
    uVar8 = *(uint *)(param_1 + 8) & 0xfcfffff;
  }
  if ((uVar8 >> 0x12 & 1) != 0) {
    *param_2 = 0x80;
    iVar9 = param_2[0xd];
    if ((((byte *)param_2[0xc] != (byte *)0x0) && (iVar9 != 0)) && ((iVar9 == 1 || (iVar9 != 0)))) {
      memw();
      memw();
      *(uint *)(param_1 + 0xc) =
           *(uint *)(param_1 + 0xc) & 0xffff00ff | (uint)*(byte *)param_2[0xc] << 8 | 1;
    }
    param_2[0xc] = 0;
    if (((param_2[8] & 0x80) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
  }
  if ((uVar8 >> 0xe & 1) != 0) {
    *param_2 = 0x100;
    *(undefined1 *)(param_2 + 7) = 1;
    if (((param_2[8] & 0x100) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
  }
  if ((uVar8 >> 10 & 1) != 0) {
    I3C_SlaveDisableInterrupts(param_1,&DAT_00001000);
    memw();
    memw();
    cVar1 = *(char *)(param_2 + 7);
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 3;
    if (cVar1 == '\0') {
      return;
    }
    param_2[5] = 0;
    *param_2 = 0x40;
    *(undefined1 *)(param_2 + 7) = 0;
    param_2[6] = param_2[9];
    if (*(char *)((int)param_2 + 0x1d) != '\0') {
      *(undefined1 *)((int)param_2 + 0x1d) = 0;
      param_2[6] = param_2[9] + -1;
    }
    if (((param_2[8] & 0x40) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
  }
  if ((uVar8 >> 9 & 1) != 0) {
    *param_2 = 1;
    *(undefined1 *)(param_2 + 7) = 1;
    if (((param_2[8] & 1) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
  }
  memw();
  memw();
  iVar9 = (2 << 0x20 - (0x20 - ((uVar5 & 0xc000000) >> 0x1a))) -
          ((*(uint *)(param_1 + 0x2c) & (uint)&DAT_001f0000) >> 0x10);
  uVar5 = (*(uint *)(param_1 + 0x2c) & 0x1f000000) >> 0x18;
  if (((uVar8 >> 0xc & 1) != 0) && ((uStack_24 & 0x1000) != 0)) {
    *(undefined1 *)((int)param_2 + 0x1d) = 1;
    if ((param_2[1] == 0) || (uVar2 = param_2[2], uVar2 == 0)) {
      *param_2 = 2;
      if ((uVar8 & 0x40) != 0) {
        *param_2 = 0x22;
      }
      if ((code *)param_2[10] != (code *)0x0) {
        (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
      }
      uVar2 = param_2[2];
      param_2[9] = 0;
      if (uVar2 == 0) goto LAB_00212243;
    }
    do {
      if (iVar9 == 0) break;
      uVar7 = (uint)*(byte *)param_2[1];
      pbVar10 = (byte *)param_2[1] + 1;
      if (uVar2 < 2) {
        param_2[1] = pbVar10;
        memw();
        *(uint *)(param_1 + 0x34) = uVar7;
        I3C_SlaveDisableInterrupts(param_1,&DAT_00001000);
        uVar2 = param_2[2];
      }
      else {
        param_2[1] = pbVar10;
        memw();
        *(uint *)(param_1 + 0x30) = uVar7;
      }
      uVar2 = uVar2 - 1;
      param_2[2] = uVar2;
      iVar9 = iVar9 + -1;
      param_2[9] = param_2[9] + 1;
    } while (uVar2 != 0);
  }
LAB_00212243:
  if (((uVar8 & 0x800) != 0) && ((uVar3 & 0x800) != 0)) {
    if ((param_2[3] == 0) || (param_2[4] == 0)) {
      *param_2 = 4;
      if ((uVar8 & 0x40) != 0) {
        *param_2 = 0x24;
      }
      if ((code *)param_2[10] != (code *)0x0) {
        (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
      }
      param_2[9] = 0;
    }
    uVar2 = I3C_SlaveGetEnabledInterrupts(param_1);
    if ((((uVar2 & 0x800) != 0) && (uVar5 != 0)) &&
       (puVar6 = (undefined1 *)param_2[3], puVar6 != (undefined1 *)0x0)) {
      iVar9 = param_2[4];
      while (iVar9 != 0) {
        memw();
        *puVar6 = (char)*(undefined4 *)(param_1 + 0x40);
        param_2[9] = param_2[9] + 1;
        puVar6 = (undefined1 *)(param_2[3] + 1);
        param_2[3] = puVar6;
        iVar9 = param_2[4] + -1;
        param_2[4] = iVar9;
        uVar5 = uVar5 - 1;
        if (uVar5 == 0) {
          return;
        }
        if (puVar6 == (undefined1 *)0x0) {
          return;
        }
      }
    }
  }
  return;
}


// ===== I3C0_DriverIRQHandler @ 002123e0 (67 bytes)

/* fsl_i3c.c (I3C_CommonIRQHandler inlined) [inference] */

void I3C0_DriverIRQHandler(void)

{
  uint uVar1;
  
  memw();
  uVar1 = I3C_MCONFIG;
  if (((uVar1 & 3) == 1) && (DAT_00238e30 != (code *)0x0)) {
    (*DAT_00238e30)(&I3C_MCONFIG,DAT_00238e38);
  }
  memw();
  uVar1 = I3C_SCONFIG;
  if (((uVar1 & 1) != 0) && (DAT_00238e34 != (code *)0x0)) {
    (*DAT_00238e34)(&I3C_MCONFIG,DAT_00238f10);
  }
  return;
}


// ===== IAP_RunBootLoader @ 00212430 (16 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: ROM API tree 0x1303EE00 + 0x200 (runBootloader) [fact for the code] */

void IAP_RunBootLoader(undefined4 param_1)

{
  (*_DAT_1303f000)(param_1);
  return;
}


// ===== IAP_FlexspiNorInit @ 00212440 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver (tree + 0x21C) -> init (+4) [fact for the code] */

undefined4 IAP_FlexspiNorInit(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 4))(param_1,param_2);
  return uVar1;
}


// ===== IAP_FlexspiNorPageProgram @ 00212458 (30 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> page_program (+8) [fact for the code] */

undefined4
IAP_FlexspiNorPageProgram
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 8))(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== IAP_FlexspiNorEraseAll @ 00212478 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> erase_all (+12) [fact for the code] */

undefined4 IAP_FlexspiNorEraseAll(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0xc))(param_1,param_2);
  return uVar1;
}


// ===== IAP_FlexspiNorErase @ 00212490 (30 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> erase (+16) [fact for the code] */

undefined4
IAP_FlexspiNorErase(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x10))(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== IAP_FlexspiNorEraseSector @ 002124b0 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> erase_sector (+20) [fact for the code] */

undefined4 IAP_FlexspiNorEraseSector(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x14))(param_1,param_2,param_3);
  return uVar1;
}


// ===== IAP_FlexspiNorEraseBlock @ 002124cc (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> erase_block (+24) [fact for the code] */

undefined4 IAP_FlexspiNorEraseBlock(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x18))(param_1,param_2,param_3);
  return uVar1;
}


// ===== IAP_FlexspiNorGetConfig @ 002124e8 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> get_config (+28) [fact for the code] */

undefined4 IAP_FlexspiNorGetConfig(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x1c))(param_1,param_2,param_3);
  return uVar1;
}


// ===== IAP_FlexspiNorRead @ 00212504 (34 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> read (+32) [fact for the code] */

undefined4
IAP_FlexspiNorRead(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x20))(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}


// ===== IAP_FlexspiXfer @ 00212528 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> xfer (+36) [fact for the code] */

undefined4 IAP_FlexspiXfer(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x24))(param_1,param_2);
  return uVar1;
}


// ===== IAP_FlexspiUpdateLut @ 00212540 (30 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> update_lut (+40) [fact for the code] */

undefined4
IAP_FlexspiUpdateLut(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x28))(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== IAP_FlexspiSetClockSource @ 00212560 (20 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> set_clock_source (+44) [fact for the code] */

undefined4 IAP_FlexspiSetClockSource(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x2c))(param_1);
  return uVar1;
}


// ===== IAP_FlexspiConfigClock @ 00212574 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: flexspiNorDriver -> config_clock (+48) [fact for the code] */

void IAP_FlexspiConfigClock(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(_DAT_1303f01c + 0x30))(param_1,param_2,param_3);
  return;
}


// ===== IAP_FlexspiNorAutoConfig @ 0021258c (46 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: get_config then init [fact for the code] */

int IAP_FlexspiNorAutoConfig(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(_DAT_1303f01c + 0x1c))(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = (**(code **)(_DAT_1303f01c + 4))(param_1,param_2);
  return iVar1;
}


// ===== IAP_OtpInit @ 002125bc (20 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: otpDriver (tree + 0x220) -> init (+0) [fact for the code] */

undefined4 IAP_OtpInit(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)*_DAT_1303f020)(param_1);
  return uVar1;
}


// ===== IAP_OtpDeinit @ 002125d0 (18 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: otpDriver -> deinit (+4) [fact for the code] */

undefined4 IAP_OtpDeinit(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 4))();
  return uVar1;
}


// ===== IAP_OtpFuseRead @ 002125e4 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: otpDriver -> fuse_read [inference] */

undefined4 IAP_OtpFuseRead(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 8))(param_1,param_2);
  return uVar1;
}


// ===== IAP_OtpFuseProgram @ 002125fc (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: otpDriver -> fuse_program [inference] */

undefined4 IAP_OtpFuseProgram(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0xc))(param_1,param_2,param_3);
  return uVar1;
}


// ===== IAP_OtpCrcCalc @ 00212618 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: otpDriver -> crc_calc [inference] */

undefined4 IAP_OtpCrcCalc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0x10))(param_1,param_2,param_3);
  return uVar1;
}


// ===== IAP_OtpShadowRegisterReload @ 00212634 (18 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: otpDriver -> reload [inference] */

undefined4 IAP_OtpShadowRegisterReload(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0x14))();
  return uVar1;
}


// ===== IAP_OtpCrcCheck @ 00212648 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* fsl_iap.c: otpDriver -> crc_check [inference] */

undefined4 IAP_OtpCrcCheck(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0x18))(param_1,param_2,param_3);
  return uVar1;
}


// ===== INPUTMUX_Init @ 00212670 (17 bytes)

/* fsl_inputmux.c: clock enable (CLKCTL1) [inference] */

void INPUTMUX_Init(void)

{
  memw();
  CLKCTL1_PSCCTL2_SET = 0x80000000;
  return;
}


// ===== INPUTMUX_AttachSignal @ 00212684 (25 bytes)

void INPUTMUX_AttachSignal(int param_1,int param_2,uint param_3)

{
  memw();
  *(uint *)(param_2 * 4 + param_1 + (param_3 >> 0x14)) = param_3 & (uint)&DAT_000fffff;
  return;
}


// ===== INPUTMUX_EnableSignal @ 002126a0 (63 bytes)

/* fsl_inputmux.c order [inference] */

void INPUTMUX_EnableSignal(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(param_1 + (param_2 >> 8));
  uVar2 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  if (param_3 != 0) {
    memw();
    memw();
    *puVar1 = *puVar1 | uVar2;
    return;
  }
  memw();
  memw();
  *puVar1 = *puVar1 & (uVar2 ^ 0xffffffff);
  return;
}


// ===== INPUTMUX_Deinit @ 002126e0 (17 bytes)

/* fsl_inputmux.c: clock disable [inference] */

void INPUTMUX_Deinit(void)

{
  memw();
  CLKCTL1_PSCCTL2_CLR = 0x80000000;
  return;
}


// ===== LPADC_Init @ 00212700 (437 bytes)

/* WARNING: Removing unreachable block (ram,0x002128a4) */
/* WARNING: Removing unreachable block (ram,0x00212880) */
/* WARNING: Removing unreachable block (ram,0x00212868) */
/* WARNING: Removing unreachable block (ram,0x00212892) */
/* WARNING: Removing unreachable block (ram,0x0021273b) */
/* WARNING: Removing unreachable block (ram,0x0021286d) */
/* fsl_lpadc.c: ADC0 0x4013A000 [inference] */

void LPADC_Init(dword *param_1,char *param_2)

{
  char cVar1;
  dword dVar2;
  uint uVar3;
  
  if (param_1 == &ADC0_VERID) {
    memw();
    CLKCTL0_PSCCTL1_SET = 0x10000;
  }
  memw();
  memw();
  param_1[4] = param_1[4] | 2;
  memw();
  memw();
  param_1[4] = param_1[4] & 0xfffffffd;
  memw();
  memw();
  param_1[4] = param_1[4] | 0x100;
  memw();
  memw();
  cVar1 = *param_2;
  param_1[4] = param_1[4] & 0xfffffffe;
  if (cVar1 == '\0') {
    memw();
    dVar2 = param_1[4] | 4;
  }
  else {
    memw();
    dVar2 = param_1[4] & 0xfffffffb;
  }
  memw();
  param_1[4] = dVar2;
  memw();
  uVar3 = *(uint *)(param_2 + 0x18);
  cVar1 = param_2[0x14];
  param_1[8] = *(uint *)(param_2 + 0x10) & 1 | (uint)(byte)param_2[1] << 0x1c |
               (*(uint *)(param_2 + 0xc) & 3) << 4 |
               (*(uint *)(param_2 + 4) & 0xff) << 0x10 | (*(uint *)(param_2 + 8) & 3) << 6;
  if (cVar1 != '\0') {
    memw();
    param_1[9] = uVar3 & 0x1ff | 0x80000000;
    memw();
    param_1[0xc] = (*(uint *)(param_2 + 0x1c) & 0xf) << 0x10;
    memw();
    memw();
    param_1[4] = param_1[4] | 1;
    return;
  }
  memw();
  param_1[9] = 0;
  memw();
  param_1[0xc] = (*(uint *)(param_2 + 0x1c) & 0xf) << 0x10;
  memw();
  memw();
  param_1[4] = param_1[4] | 1;
  return;
}


// ===== LPADC_GetDefaultConfig @ 002128b8 (48 bytes)

/* fsl_lpadc.c order [inference] */

void LPADC_GetDefaultConfig(undefined1 *param_1)

{
  memset(param_1,0,0x20);
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[0x14] = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 4) = 0x80;
  return;
}


// ===== LPADC_Deinit @ 002128e8 (188 bytes)

/* WARNING: Removing unreachable block (ram,0x00212995) */
/* WARNING: Removing unreachable block (ram,0x00212973) */
/* WARNING: Removing unreachable block (ram,0x00212951) */
/* WARNING: Removing unreachable block (ram,0x00212984) */
/* WARNING: Removing unreachable block (ram,0x00212940) */
/* WARNING: Removing unreachable block (ram,0x00212962) */
/* fsl_lpadc.c order [inference] */

void LPADC_Deinit(dword *param_1)

{
  memw();
  memw();
  param_1[4] = param_1[4] & 0xfffffffe;
  if (param_1 != &ADC0_VERID) {
    return;
  }
  memw();
  CLKCTL0_PSCCTL1_CLR = 0x10000;
  return;
}


// ===== LPADC_GetConvResult @ 002129a8 (42 bytes)

/* fsl_lpadc.c order [inference] */

undefined4 LPADC_GetConvResult(int param_1,uint *param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x300);
  if (-1 < (int)uVar1) {
    return 0;
  }
  *(short *)(param_2 + 3) = (short)uVar1;
  *param_2 = uVar1 >> 0x18 & 0xf;
  param_2[1] = uVar1 >> 0x14 & 0xf;
  param_2[2] = uVar1 >> 0x10 & 0xf;
  return 1;
}


// ===== LPADC_SetConvTriggerConfig @ 002129d4 (67 bytes)

/* fsl_lpadc.c order [inference] */

void LPADC_SetConvTriggerConfig(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((char)param_3[3] != '\0') {
    uVar1 = (param_3[2] & 0xf) << 8 | (*param_3 & 0xf) << 0x18 | (param_3[1] & 0xf) << 0x10 | 1;
  }
  memw();
  *(uint *)(param_2 * 4 + param_1 + 0xc0) = uVar1;
  return;
}


// ===== LPADC_GetDefaultConvTriggerConfig @ 00212a18 (18 bytes)

/* fsl_lpadc.c order [inference] */

void LPADC_GetDefaultConvTriggerConfig(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}


// ===== LPADC_SetConvCommandConfig @ 00212a2c (200 bytes)

/* fsl_lpadc.c order [inference] */

void LPADC_SetConvCommandConfig(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_3[1];
  iVar2 = param_2 * 8 + param_1;
  uVar3 = param_3[2] & 0x1f | (*param_3 & 1) << 0xd;
  if (uVar1 == 1) {
    uVar3 = uVar3 | 0x20;
  }
  else if (uVar1 == 2) {
    uVar3 = uVar3 | 0x40;
  }
  else if (uVar1 == 3) {
    uVar3 = uVar3 | 0x60;
  }
  memw();
  *(uint *)(iVar2 + 0xf8) = uVar3;
  uVar1 = param_3[8];
  uVar3 = uVar1 & 3 | (param_3[7] & 7) << 8 |
          (param_3[6] & 7) << 0xc | (param_3[3] & 0xf) << 0x18 | (param_3[5] & 0xf) << 0x10;
  if ((char)param_3[4] != '\0') {
    uVar3 = uVar3 | 0x80;
  }
  memw();
  *(uint *)(iVar2 + 0xfc) = uVar3;
  if (uVar1 != 0) {
    memw();
    *(uint *)(param_2 * 4 + param_1 + 0x1fc) = (uint)(ushort)param_3[10] | param_3[9] << 0x10;
    return;
  }
  return;
}


// ===== LPADC_GetDefaultConvCommandConfig @ 00212af4 (45 bytes)

/* fsl_lpadc.c order (calibration functions excluded by feature macros) [inference] */

void LPADC_GetDefaultConvCommandConfig(undefined4 *param_1)

{
  memset(param_1,0,0x2c);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *param_1 = 1;
  return;
}


// ===== MRT_Init @ 00212b30 (209 bytes)

/* WARNING: Removing unreachable block (ram,0x00212bf2) */
/* WARNING: Removing unreachable block (ram,0x00212bcc) */
/* WARNING: Removing unreachable block (ram,0x00212bba) */
/* WARNING: Removing unreachable block (ram,0x00212be0) */
/* WARNING: Removing unreachable block (ram,0x00212ba8) */
/* fsl_mrt.c: MRT0 0x4002D000, clock, reset [inference] */

void MRT_Init(dword *param_1,byte *param_2)

{
  memw();
  CLKCTL1_PSCCTL2_SET =
       1 << 0x20 - (0x20 - ((byte)(&DAT_0020046c)[(uint)(param_1 != &MRT0_CHANNEL0_INTVAL) * 4] &
                           0x1f));
  RESET_PeripheralReset
            (*(undefined4 *)(&DAT_00200470 + (uint)(param_1 != &MRT0_CHANNEL0_INTVAL) * 4));
  memw();
  param_1[0x3c] = (uint)*param_2 << 0x1f;
  return;
}


// ===== MRT_Deinit @ 00212c04 (196 bytes)

/* WARNING: Removing unreachable block (ram,0x00212cb7) */
/* WARNING: Removing unreachable block (ram,0x00212c95) */
/* WARNING: Removing unreachable block (ram,0x00212c84) */
/* WARNING: Removing unreachable block (ram,0x00212ca6) */
/* WARNING: Removing unreachable block (ram,0x00212c49) */
/* WARNING: Removing unreachable block (ram,0x00212c73) */
/* fsl_mrt.c order [inference] */

void MRT_Deinit(dword *param_1)

{
  memw();
  *param_1 = 0x80000000;
  memw();
  param_1[4] = 0x80000000;
  memw();
  param_1[8] = 0x80000000;
  memw();
  param_1[0xc] = 0x80000000;
  if (param_1 != &MRT0_CHANNEL0_INTVAL) {
    memw();
    CLKCTL1_PSCCTL2_CLR = 0x100;
    return;
  }
  memw();
  CLKCTL1_PSCCTL2_CLR = 0x100;
  return;
}


// ===== MRT_UpdateTimerPeriod @ 00212cc8 (50 bytes)

/* fsl_mrt.c order [inference] */

void MRT_UpdateTimerPeriod(int param_1,int param_2,uint param_3,int param_4)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + param_2 * 0x10);
  memw();
  if (((puVar1[2] & 6) != 2) && (param_4 == 0)) {
    memw();
    *puVar1 = param_3;
    return;
  }
  memw();
  *puVar1 = param_3 | 0x80000000;
  return;
}


// ===== MU_Init @ 00212d00 (172 bytes)

/* WARNING: Removing unreachable block (ram,0x00212d9b) */
/* WARNING: Removing unreachable block (ram,0x00212d46) */
/* WARNING: Removing unreachable block (ram,0x00212d1c) */
/* WARNING: Removing unreachable block (ram,0x00212d1f) */
/* WARNING: Removing unreachable block (ram,0x00212d22) */
/* WARNING: Removing unreachable block (ram,0x00212d25) */
/* WARNING: Removing unreachable block (ram,0x00212d28) */
/* WARNING: Removing unreachable block (ram,0x00212d2b) */
/* WARNING: Removing unreachable block (ram,0x00212d68) */
/* WARNING: Removing unreachable block (ram,0x00212d8a) */
/* WARNING: Removing unreachable block (ram,0x00212d79) */
/* clock enable for MU (base 0x40111000 MU-B passed by Thread_Ipc) */

void MU_Init(dword *param_1)

{
  if (param_1 != &MUB_VER) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1;
    return;
  }
  memw();
  CLKCTL1_PSCCTL1_SET = 0x10000000;
  return;
}


// ===== MU_Deinit @ 00212dac (172 bytes)

/* WARNING: Removing unreachable block (ram,0x00212e47) */
/* WARNING: Removing unreachable block (ram,0x00212df2) */
/* WARNING: Removing unreachable block (ram,0x00212dc8) */
/* WARNING: Removing unreachable block (ram,0x00212dcb) */
/* WARNING: Removing unreachable block (ram,0x00212dce) */
/* WARNING: Removing unreachable block (ram,0x00212dd1) */
/* WARNING: Removing unreachable block (ram,0x00212dd4) */
/* WARNING: Removing unreachable block (ram,0x00212dd7) */
/* WARNING: Removing unreachable block (ram,0x00212e14) */
/* WARNING: Removing unreachable block (ram,0x00212e36) */
/* WARNING: Removing unreachable block (ram,0x00212e25) */
/* fsl_mu.c order (MU-B 0x40111000) [inference] */

void MU_Deinit(dword *param_1)

{
  if (param_1 != &MUB_VER) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1;
    return;
  }
  memw();
  CLKCTL1_PSCCTL1_CLR = 0x10000000;
  return;
}


// ===== MU_SendMsg @ 00212e58 (46 bytes)

/* wait SR TEn, TR[reg] (+0x20) */

void MU_SendMsg(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x800000U >> (param_2 & 0x1f)) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  *(undefined4 *)(param_2 * 4 + param_1 + 0x20) = param_3;
  return;
}


// ===== MU_ReceiveMsg @ 00212e88 (47 bytes)

/* wait SR RFn, RR[reg] (+0x40) */

undefined4 MU_ReceiveMsg(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x8000000U >> (param_2 & 0x1f)) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  return *(undefined4 *)(param_2 * 4 + param_1 + 0x40);
}


// ===== MU_SetFlags @ 00212eb8 (55 bytes)

/* wait SR FUP (bit 8) clear, CR Fn = flags */

void MU_SetFlags(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x100) != 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  memw();
  *(uint *)(param_1 + 100) = param_2 & 7 | *(uint *)(param_1 + 100) & 0xfff0fff8;
  return;
}


// ===== MU_TriggerInterrupts @ 00212ef0 (36 bytes)

/* fsl_mu.c order [inference] */

undefined4 MU_TriggerInterrupts(int param_1,uint param_2)

{
  memw();
  if ((param_2 & *(uint *)(param_1 + 100)) != 0) {
    return 1;
  }
  memw();
  *(uint *)(param_1 + 100) = param_2 | *(uint *)(param_1 + 100) & 0xfff0ffff;
  return 0;
}

