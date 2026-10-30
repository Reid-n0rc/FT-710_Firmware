// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== SPI_SlaveInit @ 0021413c (271 bytes)

/* fsl_spi.c order [inference] */

int SPI_SlaveInit(int param_1,char *param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    return 4;
  }
  iVar1 = FLEXCOMM_Init(param_1,2);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = SPI_GetInstance(param_1);
  memw();
  memw();
  *(uint *)(param_1 + 0x400) =
       *(uint *)(param_1 + 0x400) & 0xfffff0c2 | (*(uint *)(param_2 + 8) & 1) << 4 |
       (*(uint *)(param_2 + 4) & 1) << 5 | (*(uint *)(param_2 + 0xc) & 1) << 3 |
       *(uint *)(param_2 + 0x14) & (uint)&DAT_00000f00;
  *(undefined4 *)(&DAT_00238f50 + iVar1 * 8) = *(undefined4 *)(param_2 + 0x10);
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
       ((byte)param_2[0x18] & 0xf) << 8 | ((byte)param_2[0x19] & 0xf) << 0x10 | 3;
  SPI_SetDummyData(param_1,0xff);
  if (*param_2 != '\0') {
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


// ===== SPI_Deinit @ 00214250 (61 bytes)

/* fsl_spi.c order [inference] */

void SPI_Deinit(int param_1)

{
  memw();
  *(undefined4 *)(param_1 + 0xe14) = 0xf;
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) & 0xffffcfff;
  memw();
  memw();
  *(uint *)(param_1 + 0x400) = *(uint *)(param_1 + 0x400) & 0xfffffffe;
  return;
}


// ===== SPI_EnableTxDMA @ 00214290 (52 bytes)

/* fsl_spi.c: FIFOCFG bit 12 [inference] */

void SPI_EnableTxDMA(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00001000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) & 0xffffefff;
  return;
}


// ===== SPI_EnableRxDMA @ 002142c4 (52 bytes)

/* fsl_spi.c: FIFOCFG bit 13 [inference] */

void SPI_EnableRxDMA(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00002000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) & 0xffffdfff;
  return;
}


// ===== SPI_MasterSetBaud @ 002142f8 (99 bytes)

/* fsl_spi.c: kStatus_SPI_BaudrateNotSupport 5603; called by SPI_MasterInit [inference] */

undefined * SPI_MasterSetBaud(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    uVar1 = ((uint)(param_3 * 10) / param_2 + 5) / 10 - 1;
    if (0xffff < uVar1) {
      return &DAT_000015e3;
    }
    memw();
    memw();
    *(uint *)(param_1 + 0x424) = *(uint *)(param_1 + 0x424) & 0xffff0000;
    uVar1 = ae_zext16(uVar1);
    memw();
    memw();
    *(uint *)(param_1 + 0x424) = *(uint *)(param_1 + 0x424) | uVar1;
    return (undefined *)0x0;
  }
  return (undefined *)0x4;
}


// ===== SPI_WriteData @ 0021435c (77 bytes)

/* fsl_spi.c order [inference] */

void SPI_WriteData(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = SPI_GetInstance(param_1);
  memw();
  *(uint *)(param_1 + 0xe20) =
       param_2 | param_3 & 0xf0f00000 |
       (1 << 0x20 - (0x20 - (*(int *)(&DAT_00238f54 + iVar1 * 8) + 0x10U & 0x1f)) ^ 0xffffffffU) &
       (uint)&DAT_000f0000 | (*(uint *)(&DAT_00238f50 + iVar1 * 8) & 0xf) << 0x18;
  return;
}


// ===== SPI_MasterTransferCreateHandle @ 002143ac (130 bytes)

/* fsl_spi.c order [inference] */

undefined4
SPI_MasterTransferCreateHandle(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = SPI_GetInstance(param_1);
  memset(param_2,0,0x30);
  memw();
  if ((*(uint *)(param_1 + 0x400) & 4) == 0) {
    FLEXCOMM_SetIRQHandler(param_1,SPI_SlaveTransferHandleIRQ,param_2);
  }
  else {
    FLEXCOMM_SetIRQHandler(param_1,SPI_MasterTransferHandleIRQ,param_2);
  }
  uVar2 = *(undefined4 *)(&DAT_00238f54 + iVar1 * 8);
  *(char *)(param_2 + 0x24) = (char)*(undefined4 *)(&DAT_00238f50 + iVar1 * 8);
  *(char *)(param_2 + 0x25) = (char)uVar2;
  memw();
  *(byte *)(param_2 + 0x2c) = (byte)((uint)*(undefined4 *)(param_1 + 0xe08) >> 8) & 0xf;
  memw();
  uVar2 = *(undefined4 *)(param_1 + 0xe08);
  *(undefined4 *)(param_2 + 0x1c) = param_3;
  *(undefined4 *)(param_2 + 0x20) = param_4;
  *(byte *)(param_2 + 0x2d) = (byte)((uint)uVar2 >> 0x10) & 0xf;
  return 0;
}


// ===== SPI_MasterTransferBlocking @ 00214430 (445 bytes)

/* fsl_spi.c order [inference] */

undefined4 SPI_MasterTransferBlocking(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined1 *puVar14;
  byte *pbVar15;
  
  if (param_1 == 0) {
    return 4;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 4;
  }
  pbVar3 = (byte *)*param_2;
  puVar9 = (undefined1 *)param_2[1];
  if ((pbVar3 == (byte *)0x0) && (puVar9 == (undefined1 *)0x0)) {
    return 4;
  }
  memw();
  uVar1 = *(uint *)(param_1 + 0xe00);
  if (pbVar3 == (byte *)0x0) {
    iVar10 = 0;
  }
  else {
    iVar10 = param_2[3];
  }
  if (puVar9 == (undefined1 *)0x0) {
    uVar11 = 0;
  }
  else {
    uVar11 = param_2[3];
  }
  iVar2 = SPI_GetInstance();
  uVar5 = *(uint *)(&DAT_00238f50 + iVar2 * 8);
  if ((7 < uVar5) && ((param_2[3] & 1) != 0)) {
    return 4;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00030000;
  memw();
  memw();
  iVar7 = *(int *)(&DAT_00238f54 + iVar2 * 8);
  uVar6 = param_2[2];
  *(uint *)(param_1 + 0xe04) = *(uint *)(param_1 + 0xe04) | 3;
  uVar8 = (uVar6 >> 0x14 & 1) << 0x14;
  uVar6 = (1 << 0x20 - (0x20 - (iVar7 + 0x10U & 0x1f)) ^ 0xffffffffU) & (uint)&DAT_000f0000 |
          (uVar5 & 0xf) << 0x18 | (uVar6 >> 0x15 & 1) << 0x15;
  if ((iVar10 != 0) || (uVar11 != 0)) {
    uVar4 = 0;
    do {
      memw();
      uVar13 = uVar11;
      puVar14 = puVar9;
      if ((*(uint *)(param_1 + 0xe04) & 0x40) != 0) {
        memw();
        uVar12 = *(undefined4 *)(param_1 + 0xe30);
        if (uVar11 != 0) {
          uVar13 = uVar11 - 1;
          *puVar9 = (char)uVar12;
          puVar14 = puVar9 + 1;
          if (8 < uVar5) {
            uVar13 = uVar11 - 2;
            *puVar14 = (char)((uint)uVar12 >> 8);
            puVar14 = puVar9 + 2;
          }
        }
        uVar4 = uVar4 - 1;
      }
      memw();
      if (((*(uint *)(param_1 + 0xe04) & 0x20) != 0) && (uVar4 < ((uVar1 & 0x30) >> 4) << 3)) {
        if (iVar10 == 0) {
          if (uVar13 < uVar4 + 1 << 0x20 - (0x20 - (uVar5 >> 3 & 0x1f))) goto LAB_00214577;
          memw();
          memw();
          uVar11 = (uint)CONCAT11((&DAT_00238f40)[iVar2],(&DAT_00238f40)[iVar2]);
          uVar6 = uVar8 | uVar6;
        }
        else {
          uVar11 = (uint)*pbVar3;
          iVar7 = iVar10 + -1;
          pbVar15 = pbVar3 + 1;
          if (8 < uVar5) {
            iVar7 = iVar10 + -2;
            uVar11 = (uint)CONCAT11(*pbVar15,*pbVar3);
            pbVar15 = pbVar3 + 2;
          }
          pbVar3 = pbVar15;
          iVar10 = iVar7;
          if (iVar7 == 0) {
            uVar6 = uVar8 | uVar6;
          }
        }
        memw();
        *(uint *)(param_1 + 0xe20) = uVar11 | uVar6;
        uVar4 = uVar4 + 1;
      }
LAB_00214577:
      uVar11 = uVar13;
      puVar9 = puVar14;
    } while (((iVar10 != 0) || (uVar13 != 0)) || (uVar4 != 0));
  }
  memw();
  uVar1 = *(uint *)(param_1 + 0xe04);
  while ((uVar1 & 0x10) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0xe04);
  }
  return 0;
}


// ===== SPI_MasterTransferNonBlocking @ 002145f0 (186 bytes)

/* fsl_spi.c order [inference] */

undefined * SPI_MasterTransferNonBlocking(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_1 != 0) && (param_2 != (int *)0x0)) && (param_3 != (int *)0x0)) {
    if (((*param_3 != 0) || (param_3[1] != 0)) &&
       ((*(byte *)(param_2 + 9) < 8 || ((param_3[3] & 1U) == 0)))) {
      memw();
      if ((undefined *)param_2[6] != &DAT_000015e0) {
        memw();
        *param_2 = *param_3;
        iVar1 = param_3[1];
        memw();
        param_2[1] = iVar1;
        iVar3 = param_3[3];
        memw();
        param_2[2] = 0;
        iVar2 = iVar3;
        if (iVar1 == 0) {
          iVar2 = 0;
        }
        memw();
        param_2[5] = iVar3;
        param_2[3] = iVar2;
        memw();
        *(undefined1 *)(param_2 + 4) = 0;
        param_2[10] = param_3[2];
        memw();
        param_2[6] = (int)&DAT_000015e0;
        memw();
        memw();
        *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00030000;
        memw();
        memw();
        *(uint *)(param_1 + 0xe04) = *(uint *)(param_1 + 0xe04) | 3;
        memw();
        memw();
        *(uint *)(param_1 + 0xe10) = *(uint *)(param_1 + 0xe10) | 0xc;
        return (undefined *)0x0;
      }
      return &DAT_000015e0;
    }
  }
  return (undefined *)0x4;
}


// ===== SPI_MasterHalfDuplexTransferBlocking @ 002146ac (166 bytes)

/* fsl_spi.c: calls SPI_MasterTransferBlocking [inference] */

int SPI_MasterHalfDuplexTransferBlocking(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uStack_24 = param_2[2];
  if (*(char *)((int)param_2 + 0x15) == '\0') {
    local_30 = 0;
    uStack_2c = param_2[1];
    uStack_24 = param_2[3];
  }
  else {
    uStack_2c = 0;
    local_30 = *param_2;
  }
  if (*(char *)(param_2 + 5) == '\0') {
    uStack_28 = param_2[4] | (uint)&DAT_00100000;
  }
  else {
    uStack_28 = param_2[4] & 0xffefffff;
  }
  iVar1 = SPI_MasterTransferBlocking(param_1,&local_30);
  if (iVar1 != 0) {
    return iVar1;
  }
  uStack_24 = param_2[3];
  if (*(char *)((int)param_2 + 0x15) == '\0') {
    uStack_2c = 0;
    local_30 = *param_2;
    uStack_24 = param_2[2];
  }
  else {
    local_30 = 0;
    uStack_2c = param_2[1];
  }
  uStack_28 = param_2[4];
  iVar1 = SPI_MasterTransferBlocking(param_1,&local_30);
  return iVar1;
}


// ===== SPI_MasterHalfDuplexTransferNonBlocking @ 00214754 (167 bytes)

/* fsl_spi.c: calls SPI_MasterTransferNonBlocking [inference] */

int SPI_MasterHalfDuplexTransferNonBlocking
              (undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uStack_24 = param_3[2];
  if (*(char *)((int)param_3 + 0x15) == '\0') {
    local_30 = 0;
    uStack_2c = param_3[1];
    uStack_24 = param_3[3];
  }
  else {
    uStack_2c = 0;
    local_30 = *param_3;
  }
  if (*(char *)(param_3 + 5) == '\0') {
    uStack_28 = param_3[4] | (uint)&DAT_00100000;
  }
  else {
    uStack_28 = param_3[4] & 0xffefffff;
  }
  iVar1 = SPI_MasterTransferBlocking(param_1,&local_30);
  if (iVar1 != 0) {
    return iVar1;
  }
  uStack_24 = param_3[3];
  if (*(char *)((int)param_3 + 0x15) == '\0') {
    uStack_2c = 0;
    local_30 = *param_3;
    uStack_24 = param_3[2];
  }
  else {
    local_30 = 0;
    uStack_2c = param_3[1];
  }
  uStack_28 = param_3[4];
  iVar1 = SPI_MasterTransferNonBlocking(param_1,param_2,&local_30);
  return iVar1;
}


// ===== SPI_MasterTransferGetCount @ 00214804 (49 bytes)

/* fsl_spi.c order [inference] */

undefined4 SPI_MasterTransferGetCount(undefined4 param_1,int param_2,int *param_3)

{
  if (param_3 == (int *)0x0) {
    return 4;
  }
  memw();
  if (*(undefined **)(param_2 + 0x18) != &DAT_000015e0) {
    *param_3 = 0;
    return 6;
  }
  memw();
  *param_3 = *(int *)(param_2 + 0x14) - *(int *)(param_2 + 0xc);
  return 0;
}


// ===== SPI_MasterTransferAbort @ 00214838 (68 bytes)

/* fsl_spi.c order [inference] */

void SPI_MasterTransferAbort(int param_1,int param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0xe10) = *(uint *)(param_1 + 0xe10) & 0xfffffff3;
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00030000;
  memw();
  *(undefined **)(param_2 + 0x18) = &DAT_000015e1;
  memw();
  *(undefined4 *)(param_2 + 8) = 0;
  memw();
  *(undefined4 *)(param_2 + 0xc) = 0;
  return;
}


// ===== SPI_MasterTransferHandleIRQ @ 0021487c (932 bytes)

/* fsl_spi.c: installed by SPI_MasterTransferCreateHandle (literal 0x21487C) [fact for the pointer]
    */

void SPI_MasterTransferHandleIRQ(int param_1,int *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  bool bVar3;
  int unaff_retaddr;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  memw();
  if (((param_2[2] == 0) && (memw(), param_2[3] == 0)) && (memw(), (char)param_2[4] == '\0')) {
    memw();
    bVar1 = *(byte *)(param_2 + 0xb);
    *(undefined4 *)(param_1 + 0xe14) = 0xc;
    memw();
    memw();
    *(uint *)(param_1 + 0xe08) =
         *(uint *)(param_1 + 0xe08) & 0xfff0ffff | (*(byte *)((int)param_2 + 0x2d) & 0xf) << 0x10 |
         (bVar1 & 0xf) << 8;
    memw();
    param_2[6] = (int)&DAT_000015e1;
    if (param_2[7] != 0) {
      memw();
      (*(code *)param_2[7])(param_1,param_2,param_2[6],param_2[8]);
      return;
    }
  }
  else {
    iVar5 = SPI_GetInstance(param_1);
    memw();
    uVar9 = *(uint *)(param_1 + 0xe00);
    uVar7 = ((uint)param_2[10] >> 0x14 & 1) << 0x14;
    uVar10 = (1 << 0x20 - (0x20 - (*(byte *)((int)param_2 + 0x25) + 0x10 & 0x1f)) ^ 0xffffffffU) &
             (uint)&DAT_000f0000 | (*(byte *)(param_2 + 9) & 0xf) << 0x18 |
             ((uint)param_2[10] >> 0x15 & 1) << 0x15;
    do {
      uVar4 = rsr_lend(0x214920);
      wsr_lbeg(uVar4);
      wsr_lend(0x214a87);
      isync();
      unaff_retaddr = rsr_lcount(unaff_retaddr + -1);
      unaff_retaddr = unaff_retaddr + 1;
      while( true ) {
        memw();
        if ((*(uint *)(param_1 + 0xe04) & 0x40) == 0) {
          bVar3 = false;
        }
        else {
          memw();
          uVar4 = *(undefined4 *)(param_1 + 0xe30);
          memw();
          if (param_2[3] != 0) {
            memw();
            *(char *)param_2[1] = (char)uVar4;
            memw();
            memw();
            param_2[1] = param_2[1] + 1;
            memw();
            memw();
            param_2[3] = param_2[3] + -1;
            if (7 < *(byte *)(param_2 + 9)) {
              memw();
              *(char *)param_2[1] = (char)((uint)uVar4 >> 8);
              memw();
              memw();
              param_2[1] = param_2[1] + 1;
              memw();
              memw();
              param_2[3] = param_2[3] + -1;
            }
          }
          memw();
          memw();
          *(char *)(param_2 + 4) = (char)param_2[4] + -1;
          bVar3 = true;
        }
        memw();
        memw();
        memw();
        if ((char)param_2[4] < '\x01') {
          uVar6 = 0;
        }
        else {
          memw();
          uVar6 = (uint)*(byte *)(param_2 + 4);
        }
        memw();
        if (((*(uint *)(param_1 + 0xe04) >> 5 & 1) == 0) || (((uVar9 & 0x30) >> 4) << 3 <= uVar6))
        break;
        if (param_2[2] == 0) {
          if ((uint)param_2[3] < uVar6 + 1 << 0x20 - (0x20 - (uint)(*(byte *)(param_2 + 9) >> 3)))
          break;
LAB_00214a8c:
          memw();
          memw();
          uVar8 = uVar7 | uVar10;
          uVar10 = param_2[3] - (uVar6 + 1 << 0x20 - (0x20 - (uint)(*(byte *)(param_2 + 9) >> 3)));
          uVar6 = (uint)CONCAT11((&DAT_00238f40)[iVar5],(&DAT_00238f40)[iVar5]);
          if (uVar10 == 0) {
            uVar10 = uVar8;
          }
        }
        else {
          memw();
          if (*param_2 == 0) goto LAB_00214a8c;
          memw();
          bVar1 = *(byte *)*param_2;
          uVar6 = (uint)bVar1;
          memw();
          memw();
          *param_2 = *param_2 + 1;
          memw();
          memw();
          param_2[2] = param_2[2] + -1;
          memw();
          if (7 < *(byte *)(param_2 + 9)) {
            memw();
            uVar2 = *(undefined1 *)*param_2;
            memw();
            memw();
            *param_2 = *param_2 + 1;
            uVar6 = (uint)CONCAT11(uVar2,bVar1);
            memw();
            memw();
            param_2[2] = param_2[2] + -1;
            memw();
          }
          memw();
          if (param_2[2] == 0) {
            uVar10 = uVar7 | uVar10;
          }
        }
        memw();
        *(uint *)(param_1 + 0xe20) = uVar6 | uVar10;
        memw();
        memw();
        *(char *)(param_2 + 4) = (char)param_2[4] + '\x01';
        memw();
        if ('\0' < (char)param_2[4]) {
          memw();
        }
      }
    } while (bVar3);
    memw();
    if (((param_2[2] == 0) && (memw(), param_2[3] == 0)) && (memw(), (char)param_2[4] == '\0')) {
      memw();
      memw();
      *(uint *)(param_1 + 0xe08) = *(uint *)(param_1 + 0xe08) & 0xfffff0ff;
      memw();
      memw();
      *(uint *)(param_1 + 0xe10) = *(uint *)(param_1 + 0xe10) | 4;
      return;
    }
    memw();
    uVar10 = (uint)param_2[3] >> (uint)(*(byte *)(param_2 + 9) >> 3);
    memw();
    if ((char)param_2[4] < '\x01') {
      uVar7 = 0;
    }
    else {
      memw();
      uVar7 = (uint)*(byte *)(param_2 + 4);
    }
    memw();
    if ((param_2[2] == 0) && (uVar10 <= uVar7)) {
      memw();
      *(undefined4 *)(param_1 + 0xe14) = 4;
    }
    if (uVar10 == 0) {
      memw();
      if (((param_2[2] == 0) && (uVar7 != 0)) &&
         (memw(), uVar7 < ((*(uint *)(param_1 + 0xe08) & (uint)&DAT_000f0000) >> 0x10) + 1)) {
        memw();
        memw();
        *(uint *)(param_1 + 0xe08) =
             *(uint *)(param_1 + 0xe08) & 0xfff0ffff | (uVar7 - 1) * 0x10000 & (uint)&DAT_000f0000;
        return;
      }
    }
    else {
      memw();
      if (uVar10 < ((*(uint *)(param_1 + 0xe08) & (uint)&DAT_000f0000) >> 0x10) + 1) {
        memw();
        memw();
        *(uint *)(param_1 + 0xe08) =
             *(uint *)(param_1 + 0xe08) & 0xfff0ffff | (uVar10 - 1) * 0x10000 & (uint)&DAT_000f0000;
        return;
      }
    }
  }
  return;
}


// ===== SPI_MasterTransferCreateHandleDMA @ 00214c30 (89 bytes)

/* fsl_spi_dma.c: DMA callbacks 0x2151B8 / 0x2151F0; called by the app SPI setup [inference] */

undefined4
SPI_MasterTransferCreateHandleDMA
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = SPI_GetInstance(param_1);
    memset(param_2,0,0x20);
    *(undefined4 *)(param_2 + 0x10) = param_3;
    *(undefined4 *)(param_2 + 0x14) = param_4;
    *(undefined4 *)(param_2 + 8) = param_6;
    *(undefined4 *)(param_2 + 4) = param_5;
    *(undefined4 *)(param_2 + 0x18) = 0;
    piVar2 = (int *)(&DAT_00238fa0 + iVar1 * 8);
    *piVar2 = param_1;
    *(int *)(&DAT_00238fa4 + iVar1 * 8) = param_2;
    DMA_SetCallback(param_5,SPI_TxDMACallback,piVar2);
    DMA_SetCallback(*(undefined4 *)(param_2 + 8),SPI_RxDMACallback,piVar2);
    return 0;
  }
  return 4;
}


// ===== SPI_MasterTransferDMA @ 00214c8c (1149 bytes)

/* fsl_spi_dma.c (SPI_SetupDummy inlined); called by the app [inference] */

undefined * SPI_MasterTransferDMA(int param_1,undefined1 *param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar4;
  uint *puVar5;
  undefined *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined1 auStack_70 [16];
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined2 uStack_4a;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined1 uStack_40;
  undefined2 uStack_3e;
  uint *puStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  
  if (((param_2 == (undefined1 *)0x0) || (param_3 == (int *)0x0)) || (param_3[3] == 0)) {
    return (undefined *)0x4;
  }
  iStack_34 = SPI_GetInstance(param_1);
  if (*(int *)(param_2 + 0x18) == 1) {
    return &DAT_000015e0;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00030000;
  memw();
  memw();
  *(uint *)(param_1 + 0xe04) = *(uint *)(param_1 + 0xe04) | 3;
  memcpy(auStack_70,&DAT_00200570,0x1c);
  iStack_38 = param_1 + 0xd14;
  puVar5 = (uint *)SPI_GetConfig(param_1);
  *(int *)(param_2 + 0x1c) = param_3[3];
  *(undefined4 *)(param_2 + 0x18) = 1;
  SPI_EnableRxDMA(param_1,1);
  uVar8 = 2;
  if (*puVar5 < 8) {
    uVar8 = 1;
  }
  if (param_3[1] == 0) {
    DMA_PrepareTransfer(auStack_70,param_1 + 0xe30,&DAT_20060710,uVar8,param_3[3],3,0);
  }
  else {
    DMA_PrepareTransfer(auStack_70,param_1 + 0xe30,param_3[1],uVar8,param_3[3],1,0);
  }
  uVar8 = 1;
  DMA_SubmitTransfer(*(undefined4 *)(param_2 + 8),auStack_70);
  memw();
  param_2[1] = 1;
  DMA_StartTransfer(*(undefined4 *)(param_2 + 8));
  SPI_EnableTxDMA(param_1,1);
  uVar14 = param_3[2];
  if (*param_3 == 0) {
    iVar11 = SPI_GetInstance(param_1);
    memw();
    memw();
    uVar10 = param_3[2];
    iVar13 = iStack_34 * 8;
    puVar7 = (uint *)(&DAT_00238ff0 + iVar13);
    uVar14 = (uint)CONCAT11((&DAT_00238f40)[iVar11],(&DAT_00238f40)[iVar11]);
    *(uint *)(&DAT_00238ff4 + iVar13) = uVar14;
    uVar16 = uVar14 | (uVar10 >> 0x15 & 1) << 0x15;
    *(uint *)(&DAT_00238ff4 + iVar13) = uVar16;
    uVar12 = uVar16 | ((uint)param_3[2] >> 0x14 & 1) << 0x14;
    *(uint *)(&DAT_00238ff4 + iVar13) = uVar12;
    uVar10 = param_3[2];
    *puVar7 = uVar14;
    uVar14 = uVar14 | (uVar10 >> 0x15 & 1) << 0x15;
    *puVar7 = uVar14;
    uVar14 = uVar14 | ((uint)param_3[2] >> 0x14 & 1) << 0x14;
    *puVar7 = uVar14;
    uVar10 = (1 << 0x20 - (0x20 - (puVar5[1] + 0x10 & 0x1f)) ^ 0xffffffffU) & (uint)&DAT_000f0000;
    uVar12 = uVar12 | uVar10;
    *(uint *)(&DAT_00238ff4 + iVar13) = uVar12;
    uVar15 = (*puVar5 & 0xf) << 0x18;
    *(uint *)(&DAT_00238ff4 + iVar13) = uVar12 | uVar15;
    uVar14 = uVar14 | (1 << 0x20 - (0x20 - (puVar5[1] + 0x10 & 0x1f)) ^ 0xffffffffU) &
                      (uint)&DAT_000f0000;
    *puVar7 = uVar14;
    *puVar7 = uVar14 | (*puVar5 & 0xf) << 0x18;
    uVar14 = param_3[2];
    *(uint *)(&DAT_00238ff4 + iVar13) = uVar16 | uVar10 | uVar15;
    uVar10 = param_3[3];
    if ((uVar14 >> 0x14 & 1) != 0) {
      if (*puVar5 < 8) {
        bVar2 = true;
        if (uVar10 < 2) {
          bVar2 = false;
        }
      }
      else {
        bVar2 = true;
        if (uVar10 < 3) {
          bVar2 = false;
        }
      }
      puStack_3c = puVar7;
      if (bVar2) {
        uStack_48 = 1;
        uStack_46 = 1;
        uStack_44 = 1;
        uStack_3e = 1;
        iStack_30 = param_1 + 0xe20;
        uStack_42 = 4;
        uStack_41 = 0;
        uStack_40 = 0;
        uStack_47 = 0;
        iVar13 = iStack_34 * 0x10;
        uStack_45 = 0;
        uStack_43 = 0;
        DMA_CreateDescriptor(&DAT_20060750 + iVar13,&uStack_48,puVar7,iStack_30,0);
        uVar9 = 2;
        if (*puVar5 < 8) {
          uVar9 = uVar8;
        }
        if (*puVar5 < 8) {
          iVar11 = param_3[3] + -1;
        }
        else {
          iVar11 = param_3[3] + -2;
        }
        DMA_PrepareTransfer(auStack_70,puStack_3c + 1,iStack_30,uVar9,iVar11,3,
                            &DAT_20060750 + iVar13);
        uStack_60 = 0;
        uStack_5f = 0;
        puVar6 = (undefined *)DMA_SubmitTransfer(*(undefined4 *)(param_2 + 4),auStack_70);
        if (puVar6 != (undefined *)0x0) {
          return puVar6;
        }
        goto LAB_00214e94;
      }
    }
    uVar9 = 2;
    if (*puVar5 < 8) {
      uVar9 = uVar8;
    }
    DMA_PrepareTransfer(auStack_70,&DAT_00238ff4 + iVar13,param_1 + 0xe20,uVar9,uVar10,3,0);
    puVar6 = (undefined *)DMA_SubmitTransfer(*(undefined4 *)(param_2 + 4),auStack_70);
    if (puVar6 != (undefined *)0x0) {
      return puVar6;
    }
  }
  else {
    if ((uVar14 & 0x100000) != 0) {
      iVar13 = param_3[3] + *param_3;
      bVar1 = *(byte *)(iVar13 + -1);
      uVar14 = (uint)bVar1;
      if (7 < *puVar5) {
        uVar14 = (uint)CONCAT11(bVar1,*(undefined1 *)(iVar13 + -2));
      }
      puVar7 = (uint *)(&DAT_20060720 + iStack_34 * 4);
      *puVar7 = uVar14;
      uVar14 = uVar14 | ((uint)param_3[2] >> 0x15 & 1) << 0x15;
      *puVar7 = uVar14;
      uVar14 = uVar14 | ((uint)param_3[2] >> 0x14 & 1) << 0x14;
      *puVar7 = uVar14;
      uVar14 = uVar14 | (1 << 0x20 - (0x20 - (puVar5[1] + 0x10 & 0x1f)) ^ 0xffffffffU) &
                        (uint)&DAT_000f0000;
      *puVar7 = uVar14;
      *puVar7 = uVar14 | (*puVar5 & 0xf) << 0x18;
      uVar14 = param_3[2];
    }
    uVar10 = param_3[3];
    if ((uVar14 & (uint)&DAT_00100000) != 0) {
      if (*puVar5 < 8) {
        bVar2 = true;
        if (uVar10 < 2) {
          bVar2 = false;
        }
      }
      else {
        bVar2 = true;
        if (uVar10 < 3) {
          bVar2 = false;
        }
      }
      if (bVar2) {
        uStack_54 = 1;
        uStack_52 = 1;
        uStack_50 = 1;
        uStack_4a = 1;
        uStack_4d = 0;
        uStack_4c = 0;
        uStack_53 = 0;
        uStack_51 = 0;
        uStack_4e = 4;
        uStack_4f = 0;
        iVar13 = iStack_34 * 0x10;
        iStack_30 = param_1 + 0xe20;
        DMA_CreateDescriptor
                  (&DAT_20060750 + iVar13,&uStack_54,&DAT_20060720 + iStack_34 * 4,iStack_30,0);
        uVar9 = 2;
        if (*puVar5 < 8) {
          uVar9 = uVar8;
        }
        if (*puVar5 < 8) {
          iVar11 = param_3[3] + -1;
        }
        else {
          iVar11 = param_3[3] + -2;
        }
        DMA_PrepareTransfer(auStack_70,*param_3,iStack_30,uVar9,iVar11,2,&DAT_20060750 + iVar13);
        uStack_60 = 0;
        uStack_5f = 0;
        puVar6 = (undefined *)DMA_SubmitTransfer(*(undefined4 *)(param_2 + 4),auStack_70);
        if (puVar6 != (undefined *)0x0) {
          return puVar6;
        }
        goto LAB_00214e94;
      }
    }
    uVar9 = 2;
    if (*puVar5 < 8) {
      uVar9 = uVar8;
    }
    DMA_PrepareTransfer(auStack_70,*param_3,param_1 + 0xe20,uVar9,uVar10,2,0);
    DMA_SubmitTransfer(*(undefined4 *)(param_2 + 4),auStack_70);
  }
LAB_00214e94:
  memw();
  uVar14 = puVar5[1];
  uVar10 = *puVar5;
  *param_2 = 1;
  uVar15 = param_3[2];
  uVar4 = (ushort)(((uVar15 >> 0x15 & 1) << 0x15) >> 0x10);
  uVar3 = ((ushort)((uint)(1 << 0x20 - (0x20 - (uVar14 + 0x10 & 0x1f))) >> 0x10) ^ 0xffff) & 0xf |
          (ushort)(((uVar10 & 0xf) << 0x18) >> 0x10);
  if ((uVar15 & (uint)&DAT_00100000) != 0) {
    if (uVar10 < 8) {
      if (param_3[3] == 1) goto LAB_00214f17;
    }
    else if (param_3[3] == 2) {
LAB_00214f17:
      *(ushort *)(iStack_38 + 0x10e) =
           uVar3 | (ushort)(((uint)((uVar15 & (uint)&DAT_00100000) != 0) << 0x14) >> 0x10) | uVar4;
      goto LAB_00214f20;
    }
  }
  *(ushort *)(iStack_38 + 0x10e) = uVar3 | uVar4;
LAB_00214f20:
  DMA_StartTransfer(*(undefined4 *)(param_2 + 4));
  return (undefined *)0x0;
}


// ===== SPI_MasterHalfDuplexTransferDMA @ 0021510c (168 bytes)

/* fsl_spi_dma.c order [inference] */

int SPI_MasterHalfDuplexTransferDMA(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uStack_24 = param_3[2];
  if (*(char *)((int)param_3 + 0x15) == '\0') {
    local_30 = 0;
    uStack_2c = param_3[1];
    uStack_24 = param_3[3];
  }
  else {
    uStack_2c = 0;
    local_30 = *param_3;
  }
  if (*(char *)(param_3 + 5) == '\0') {
    uStack_28 = param_3[4] | (uint)&DAT_00100000;
  }
  else {
    uStack_28 = param_3[4] & 0xffefffff;
  }
  iVar1 = SPI_MasterTransferBlocking(param_1,&local_30);
  if (iVar1 != 0) {
    return iVar1;
  }
  uStack_24 = param_3[3];
  if (*(char *)((int)param_3 + 0x15) == '\0') {
    uStack_2c = 0;
    local_30 = *param_3;
    uStack_24 = param_3[2];
  }
  else {
    local_30 = 0;
    uStack_2c = param_3[1];
  }
  uStack_28 = param_3[4];
  iVar1 = SPI_MasterTransferDMA(param_1,param_2,&local_30);
  return iVar1;
}


// ===== SPI_RxDMACallback @ 002151b8 (55 bytes)

/* fsl_spi_dma.c static [inference] */

void SPI_RxDMACallback(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (char *)param_2[1];
  uVar2 = *param_2;
  memw();
  pcVar1[1] = '\0';
  memw();
  if (*pcVar1 == '\0') {
    memw();
    if ((pcVar1[1] == '\0') &&
       (pcVar1[0x18] = '\0', pcVar1[0x19] = '\0', pcVar1[0x1a] = '\0', pcVar1[0x1b] = '\0',
       *(code **)(pcVar1 + 0x10) != (code *)0x0)) {
      (**(code **)(pcVar1 + 0x10))(uVar2,pcVar1,0,*(undefined4 *)(pcVar1 + 0x14));
      return;
    }
  }
  return;
}


// ===== SPI_TxDMACallback @ 002151f0 (55 bytes)

/* fsl_spi_dma.c static [inference] */

void SPI_TxDMACallback(undefined4 param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (char *)param_2[1];
  uVar2 = *param_2;
  memw();
  *pcVar1 = '\0';
  memw();
  if (*pcVar1 == '\0') {
    memw();
    if ((pcVar1[1] == '\0') &&
       (pcVar1[0x18] = '\0', pcVar1[0x19] = '\0', pcVar1[0x1a] = '\0', pcVar1[0x1b] = '\0',
       *(code **)(pcVar1 + 0x10) != (code *)0x0)) {
      (**(code **)(pcVar1 + 0x10))(uVar2,pcVar1,0,*(undefined4 *)(pcVar1 + 0x14));
      return;
    }
  }
  return;
}


// ===== SPI_MasterTransferAbortDMA @ 00215228 (31 bytes)

/* fsl_spi_dma.c: DMA_AbortTransfer [inference] */

void SPI_MasterTransferAbortDMA(undefined4 param_1,undefined1 *param_2)

{
  DMA_AbortTransfer(*(undefined4 *)(param_2 + 4));
  DMA_AbortTransfer(*(undefined4 *)(param_2 + 8));
  memw();
  *param_2 = 0;
  memw();
  param_2[1] = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  return;
}


// ===== SPI_MasterTransferGetCountDMA @ 00215248 (47 bytes)

/* fsl_spi_dma.c: DMA_GetRemainingBytes [inference] */

undefined4 SPI_MasterTransferGetCountDMA(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    return 4;
  }
  if (*(int *)(param_2 + 0x18) != 1) {
    *param_3 = 0;
    return 6;
  }
  iVar1 = DMA_GetRemainingBytes
                    (*(undefined4 *)(*(int *)(param_2 + 8) + 8),
                     *(undefined1 *)(*(int *)(param_2 + 8) + 0xc));
  *param_3 = *(int *)(param_2 + 0x1c) - iVar1;
  return 0;
}


// ===== TRNG_GetDefaultConfig @ 00215280 (152 bytes)

/* fsl_trng.c: default limits (3200, 2500, ...) [inference] */

undefined4 TRNG_GetDefaultConfig(undefined1 *param_1)

{
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 1;
    param_1[0x16] = 1;
    *(undefined4 *)(param_1 + 0x44) = 1;
    *(undefined4 *)(param_1 + 0x4c) = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x2f;
    *(undefined4 *)(param_1 + 0x48) = 0x2f;
    *(undefined4 *)(param_1 + 0x20) = 0x195;
    *(undefined4 *)(param_1 + 0x1c) = 0x45c;
    *(undefined2 *)(param_1 + 0x12) = 0x9c4;
    *(undefined2 *)(param_1 + 0x10) = 0xc80;
    *(undefined4 *)(param_1 + 0x18) = 0x568;
    *(undefined2 *)(param_1 + 0x14) = 0x3f;
    param_1[0x17] = 0x22;
    *(undefined4 *)(param_1 + 0x34) = 0x25;
    *(undefined4 *)(param_1 + 0x38) = 0x4b;
    *(undefined4 *)(param_1 + 0x3c) = 0xb;
    *(undefined4 *)(param_1 + 0x2c) = 0x62;
    *(undefined4 *)(param_1 + 0x30) = 0x7d;
    *(undefined **)(param_1 + 0x54) = &DAT_00005f7d;
    *(undefined **)(param_1 + 0x50) = &DAT_00006920;
    *(undefined4 *)(param_1 + 0x24) = 0xe3;
    *(undefined4 *)(param_1 + 0x28) = 0xdc;
    *(undefined **)(param_1 + 0x58) = &DAT_00006400;
    *(undefined4 *)(param_1 + 0x5c) = 0x640;
    return 0;
  }
  return 4;
}


// ===== trng_ApplyUserConfig @ 00215318 (692 bytes)

/* fsl_trng.c static; called by TRNG_Init [inference] */

undefined4 trng_ApplyUserConfig(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    puVar2 = (undefined *)*param_3;
    puVar3 = (undefined *)param_3[1];
    puVar4 = puVar2 + -(int)puVar3;
    if (puVar3 < puVar2) {
      if (param_2 == 1) {
        if ((puVar4 < &DAT_00010000) && (puVar2 < &DAT_00010000)) {
          uVar1 = ae_zext16(puVar2);
          memw();
          memw();
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffff0000 | uVar1;
          memw();
          uVar1 = ae_zext16(*(undefined4 *)(param_1 + 0x20));
          memw();
          *(uint *)(param_1 + 0x20) = uVar1 | (int)puVar4 * 0x10000;
          return 0;
        }
        return 4;
      }
      if (param_2 == 2) {
        if ((puVar4 < &DAT_00008000) && (puVar2 < &DAT_00008000)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xffff8000 | (uint)puVar2 & 0x7fff
          ;
          memw();
          memw();
          *(uint *)(param_1 + 0x24) =
               *(uint *)(param_1 + 0x24) & 0x8000ffff | (int)puVar4 * 0x10000 & 0x7fff0000U;
          return 0;
        }
        return 4;
      }
      if (param_2 == 3) {
        if ((puVar4 < &DAT_00004000) && (puVar2 < &DAT_00004000)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffc000 | (uint)puVar2 & 0x3fff
          ;
          memw();
          memw();
          *(uint *)(param_1 + 0x28) =
               *(uint *)(param_1 + 0x28) & 0xc000ffff | (int)puVar4 * 0x10000 & 0x3fff0000U;
          return 0;
        }
        return 4;
      }
      if (param_2 == 4) {
        if ((puVar4 < &DAT_00002000) && (puVar2 < &DAT_00002000)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffe000 | (uint)puVar2 & 0x1fff
          ;
          memw();
          memw();
          *(uint *)(param_1 + 0x2c) =
               *(uint *)(param_1 + 0x2c) & 0xe000ffff | (int)puVar4 * 0x10000 & 0x1fff0000U;
          return 0;
        }
        return 4;
      }
      if (param_2 == 5) {
        if ((puVar4 < &DAT_00001000) && (puVar2 < &DAT_00001000)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffff000 | (uint)puVar2 & 0xfff;
          memw();
          memw();
          *(uint *)(param_1 + 0x30) =
               *(uint *)(param_1 + 0x30) & 0xf000ffff | (int)puVar4 * 0x10000 & 0xfff0000U;
          return 0;
        }
        return 4;
      }
      if (param_2 == 6) {
        if ((puVar4 < &DAT_00000800) && (puVar2 < &DAT_00000800)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xfffff800 | (uint)puVar2 & 0x7ff;
          memw();
          memw();
          *(uint *)(param_1 + 0x34) =
               *(uint *)(param_1 + 0x34) & 0xf800ffff | (int)puVar4 * 0x10000 & 0x7ff0000U;
          return 0;
        }
        return 4;
      }
      if (param_2 == 7) {
        if ((puVar4 < &DAT_00000800) && (puVar2 < &DAT_00000800)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfffff800 | (uint)puVar2 & 0x7ff;
          memw();
          memw();
          *(uint *)(param_1 + 0x38) =
               *(uint *)(param_1 + 0x38) & 0xf800ffff | (int)puVar4 * 0x10000 & 0x7ff0000U;
          return 0;
        }
        return 4;
      }
      if (param_2 != 8) {
        if (param_2 != 9) {
          return 4;
        }
        if ((puVar3 < &DAT_00400000) && (puVar2 < &DAT_00400000)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x1c) =
               *(uint *)(param_1 + 0x1c) & 0xffc00000 | (uint)puVar2 & (uint)&DAT_003fffff;
          memw();
          memw();
          *(uint *)(param_1 + 0x18) =
               *(uint *)(param_1 + 0x18) & 0xffc00000 | (uint)puVar3 & (uint)&DAT_003fffff;
          return 0;
        }
        return 4;
      }
      if ((puVar4 < &DAT_00010000) && (puVar2 < (undefined *)0x1000000)) {
        memw();
        memw();
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xff000000 | (uint)puVar2 & 0xffffff;
        uVar1 = ae_zext16(puVar4);
        memw();
        memw();
        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffff0000 | uVar1;
        return 0;
      }
      return 4;
    }
  }
  return 0;
}


// ===== TRNG_Init @ 002155d0 (687 bytes)

/* WARNING: Removing unreachable block (ram,0x00215857) */
/* WARNING: Removing unreachable block (ram,0x00215614) */
/* WARNING: Removing unreachable block (ram,0x002155f6) */
/* WARNING: Removing unreachable block (ram,0x002155fc) */
/* WARNING: Removing unreachable block (ram,0x00215602) */
/* WARNING: Removing unreachable block (ram,0x0021560b) */
/* WARNING: Removing unreachable block (ram,0x00215611) */
/* WARNING: Removing unreachable block (ram,0x00215869) */
/* WARNING: Removing unreachable block (ram,0x00215835) */
/* WARNING: Removing unreachable block (ram,0x00215823) */
/* fsl_trng.c: TRNG 0x40138000 [inference] */

int TRNG_Init(dword *param_1,char *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 == (dword *)0x0) || (param_2 == (char *)0x0)) {
    return 4;
  }
  memw();
  CLKCTL0_PSCCTL0_SET =
       1 << 0x20 - (0x20 - ((byte)(&DAT_002005a0)[(uint)(param_1 != &TRNG_MCTL) * 4] & 0x1f));
  memw();
  memw();
  bVar1 = param_2[0x16];
  *param_1 = *param_1 | (uint)&DAT_00011040;
  iVar2 = 4;
  if (bVar1 - 1 < 0xf) {
    memw();
    memw();
    param_1[1] = param_1[1] & 0xfff0ffff | (bVar1 & 0xf) << 0x10;
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    iVar2 = trng_ApplyUserConfig(param_1,1,param_2 + 0x18);
  }
  if ((((((iVar2 == 0) && (iVar2 = trng_ApplyUserConfig(param_1,2,param_2 + 0x20), iVar2 == 0)) &&
        (iVar2 = trng_ApplyUserConfig(param_1,3,param_2 + 0x28), iVar2 == 0)) &&
       ((iVar2 = trng_ApplyUserConfig(param_1,4,param_2 + 0x30), iVar2 == 0 &&
        (iVar2 = trng_ApplyUserConfig(param_1,5,param_2 + 0x38), iVar2 == 0)))) &&
      ((iVar2 = trng_ApplyUserConfig(param_1,6,param_2 + 0x40), iVar2 == 0 &&
       ((iVar2 = trng_ApplyUserConfig(param_1,7,param_2 + 0x48), iVar2 == 0 &&
        (iVar2 = trng_ApplyUserConfig(param_1,8,param_2 + 0x50), iVar2 == 0)))))) &&
     (iVar2 = trng_ApplyUserConfig(param_1,9,param_2 + 0x58), iVar2 == 0)) {
    memw();
    memw();
    *param_1 = *param_1 & 0xffffef7f | (*(uint *)(param_2 + 4) & 1) << 7;
    memw();
    memw();
    *param_1 = *param_1 & 0xffffeff3 | (*(uint *)(param_2 + 8) & 3) << 2;
    memw();
    memw();
    *param_1 = *param_1 & 0xffffeffc | *(uint *)(param_2 + 0xc) & 3;
    memw();
    uVar3 = ae_zext16(param_1[4]);
    memw();
    param_1[4] = uVar3 | (uint)*(ushort *)(param_2 + 0x10) << 0x10;
    memw();
    memw();
    param_1[4] = param_1[4] & 0xffff0000 | (uint)*(ushort *)(param_2 + 0x12);
    memw();
    memw();
    param_1[5] = param_1[5] & 0xfffffc00 | *(ushort *)(param_2 + 0x14) & 0x3ff;
    memw();
    memw();
    param_1[1] = param_1[1] & 0xffffff00 | (uint)(byte)param_2[0x17];
    memw();
    memw();
    *param_1 = *param_1 & 0xfffeefff;
    memw();
    memw();
    *param_1 = *param_1 & 0xffffefdf | 0x20;
    memw();
    memw();
    if (*param_2 == '\0') {
      return 0;
    }
    memw();
    memw();
    param_1[0x28] = param_1[0x28] | 2;
    return 0;
  }
  return iVar2;
}


// ===== TRNG_Deinit @ 00215880 (233 bytes)

/* WARNING: Removing unreachable block (ram,0x00215947) */
/* WARNING: Removing unreachable block (ram,0x00215903) */
/* WARNING: Removing unreachable block (ram,0x002158d6) */
/* WARNING: Removing unreachable block (ram,0x002158d9) */
/* WARNING: Removing unreachable block (ram,0x002158dc) */
/* WARNING: Removing unreachable block (ram,0x002158e2) */
/* WARNING: Removing unreachable block (ram,0x002158e5) */
/* WARNING: Removing unreachable block (ram,0x00215958) */
/* WARNING: Removing unreachable block (ram,0x00215936) */
/* WARNING: Removing unreachable block (ram,0x00215925) */
/* fsl_trng.c order [inference] */

void TRNG_Deinit(dword *param_1)

{
  uint uVar1;
  
  if (param_1 == (dword *)0x0) {
    return;
  }
  memw();
  memw();
  *param_1 = *param_1 & 0xfffeefff | (uint)&DAT_00010000;
  memw();
  uVar1 = *param_1 & (uint)&DAT_00002000;
  while (uVar1 == 0) {
    memw();
    uVar1 = *param_1 & (uint)&DAT_00002000;
  }
  if (param_1 != &TRNG_MCTL) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1;
    return;
  }
  memw();
  CLKCTL0_PSCCTL0_CLR = 0x1000;
  return;
}


// ===== TRNG_GetRandomData @ 0021596c (351 bytes)

/* WARNING: Type propagation algorithm not settling */
/* fsl_trng.c order [inference] */

undefined4 TRNG_GetRandomData(uint *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_2c [44];
  
  if (((param_1 == (uint *)0x0) || (param_2 == (undefined1 *)0x0)) || (param_3 == 0)) {
    return 4;
  }
  memw();
  if ((*param_1 & (uint)&DAT_00001000) != 0) {
    memw();
    memw();
    *param_1 = *param_1 | (uint)&DAT_00001000;
    memw();
    memw();
  }
  uVar6 = 0;
  do {
    memw();
    uVar7 = *param_1;
    memw();
    uVar3 = *param_1 & (uint)&DAT_00001000;
    while (((uVar7 & 0x400) == 0 && (uVar3 == 0))) {
      memw();
      uVar7 = *param_1;
      memw();
      uVar3 = *param_1 & (uint)&DAT_00001000;
    }
    memw();
    uVar3 = uVar6 & 0xf;
    if ((*param_1 & (uint)&DAT_00001000) != 0) {
      memw();
      memw();
      *param_1 = *param_1 | (uint)&DAT_00001000;
      uVar5 = 1;
      goto LAB_00215a81;
    }
    memw();
    if (uVar3 == 0xf) {
      memw();
    }
    uVar7 = param_3;
    if (4 < param_3) {
      uVar7 = 4;
    }
    uVar6 = uVar6 + 1;
    auStack_2c._0_4_ = param_1[uVar3 + 0x10];
    param_3 = param_3 - uVar7;
    if (uVar7 != 0) {
      puVar4 = (undefined4 *)auStack_2c;
      if ((uVar7 & 7) != 0) {
        puVar4 = (undefined4 *)((int)auStack_2c + 1);
        auStack_2c[0] = (undefined1)param_1[uVar3 + 0x10];
        *param_2 = auStack_2c[0];
        param_2 = param_2 + 1;
      }
      if (uVar7 >> 3 != 0) {
        uVar1 = *(undefined1 *)((int)puVar4 + 1);
        *param_2 = *(undefined1 *)puVar4;
        uVar2 = *(undefined1 *)((int)puVar4 + 2);
        param_2[1] = uVar1;
        uVar1 = *(undefined1 *)((int)puVar4 + 3);
        param_2[2] = uVar2;
        uVar2 = *(undefined1 *)(puVar4 + 1);
        param_2[3] = uVar1;
        uVar1 = *(undefined1 *)((int)puVar4 + 5);
        param_2[4] = uVar2;
        uVar2 = *(undefined1 *)((int)puVar4 + 6);
        param_2[5] = uVar1;
        uVar1 = *(undefined1 *)((int)puVar4 + 7);
        param_2[6] = uVar2;
        param_2[7] = uVar1;
        param_2 = param_2 + 8;
      }
    }
  } while (param_3 != 0);
  uVar5 = 0;
LAB_00215a81:
  if ((uVar6 & 0xf) != 0) {
    memw();
    memw();
    return uVar5;
  }
  return uVar5;
}


// ===== USART_EnableInterrupts @ 00215ad0 (16 bytes)

/* fsl_usart.h inline: FIFOINTENSET (+0xE10) = mask & 0xF [fact for the code] */

void USART_EnableInterrupts(int param_1,uint param_2)

{
  memw();
  *(uint *)(param_1 + 0xe10) = param_2 & 0xf;
  return;
}


// ===== USART_DisableInterrupts @ 00215ae0 (16 bytes)

/* fsl_usart.h inline: FIFOINTENCLR (+0xE14) [fact for the code] */

void USART_DisableInterrupts(int param_1,uint param_2)

{
  memw();
  *(uint *)(param_1 + 0xe14) = param_2 & 0xf;
  return;
}


// ===== USART_GetEnabledInterrupts @ 00215af0 (13 bytes)

/* fsl_usart.h inline: FIFOINTENSET [fact for the code] */

undefined4 USART_GetEnabledInterrupts(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0xe10);
}


// ===== USART_GetInstance @ 00215b00 (30 bytes)

/* fsl_usart.c: 8 bases at 0x2005B0 [inference] */

bool USART_GetInstance(dword *param_1)

{
  return param_1 != &USART0_CFG;
}


// ===== USART_TransferGetRxRingBufferLength @ 00215b20 (34 bytes)

/* fsl_usart.c order [inference] */

int USART_TransferGetRxRingBufferLength(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  uVar1 = (uint)*(ushort *)(param_1 + 0x20);
  memw();
  uVar2 = (uint)*(ushort *)(param_1 + 0x22);
  if (uVar1 < uVar2) {
    return (uVar1 + *(int *)(param_1 + 0x1c)) - uVar2;
  }
  return uVar1 - uVar2;
}


// ===== USART_TransferStartRingBuffer @ 00215b44 (36 bytes)

/* fsl_usart.c order [inference] */

void USART_TransferStartRingBuffer(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_2 + 0x18) = param_3;
  *(undefined4 *)(param_2 + 0x1c) = param_4;
  memw();
  *(undefined2 *)(param_2 + 0x20) = 0;
  memw();
  *(undefined2 *)(param_2 + 0x22) = 0;
  memw();
  *(undefined4 *)(param_1 + 0xe10) = 10;
  return;
}


// ===== USART_TransferStopRingBuffer @ 00215b68 (66 bytes)

/* fsl_usart.c order [inference] */

void USART_TransferStopRingBuffer(int param_1,int param_2)

{
  memw();
  if (*(char *)(param_2 + 0x2d) != '\x02') {
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x1c) = 0;
    memw();
    *(undefined2 *)(param_2 + 0x20) = 0;
    memw();
    *(undefined2 *)(param_2 + 0x22) = 0;
    return;
  }
  memw();
  *(undefined4 *)(param_1 + 0xe14) = 10;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  memw();
  *(undefined2 *)(param_2 + 0x20) = 0;
  memw();
  *(undefined2 *)(param_2 + 0x22) = 0;
  return;
}


// ===== USART_Init @ 00215bac (449 bytes)

/* fsl_usart.c: FLEXCOMM_Init, USART_SetBaudRate [inference] */

undefined * USART_Init(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  
  if (((param_1 == (uint *)0x0) || (param_2 == (uint *)0x0)) || (param_3 == 0)) {
    return (undefined *)0x4;
  }
  puVar2 = (undefined *)FLEXCOMM_Init(param_1,1);
  if (puVar2 != (undefined *)0x0) {
    return puVar2;
  }
  if (*(char *)((int)param_2 + 0x12) != '\0') {
    memw();
    memw();
    param_1[0x380] = param_1[0x380] | (uint)&DAT_00010001;
    memw();
    memw();
    param_1[0x382] = param_1[0x382] & 0xfffff0ff;
    memw();
    memw();
    param_1[0x382] = param_1[0x382] | (param_2[6] & 0xf) << 8;
    memw();
    memw();
    param_1[0x382] = param_1[0x382] | 1;
  }
  if (*(char *)((int)param_2 + 0x11) != '\0') {
    memw();
    memw();
    param_1[0x380] = param_1[0x380] | (uint)&DAT_00020002;
    memw();
    memw();
    param_1[0x382] = param_1[0x382] & 0xfff0ffff;
    memw();
    memw();
    param_1[0x382] = param_1[0x382] | (param_2[7] & 0xf) << 0x10;
    memw();
    memw();
    param_1[0x382] = param_1[0x382] | 2;
  }
  uVar1 = param_2[5];
  memw();
  *param_1 = (*(byte *)((int)param_2 + 0x15) & 1) << 9 |
             ((byte)uVar1 & 1) << 7 | (param_2[9] & 1) << 0xc |
             (param_2[8] & 1) << 0xe | (param_2[8] >> 1 & 1) << 0xb |
             ((byte)param_2[4] & 1) << 0xf | (param_2[3] & 3) << 2 |
             (param_2[1] & 3) << 4 | (param_2[2] & 1) << 6 | 1;
  uVar3 = *param_2;
  if ((byte)uVar1 == 0) {
    puVar2 = (undefined *)USART_SetBaudRate(param_1,uVar3,param_3);
    if (puVar2 != (undefined *)0x0) {
      return puVar2;
    }
  }
  else {
    if ((uint)&DAT_00002580 % uVar3 != 0) {
      return &DAT_00001651;
    }
    memw();
    param_1[8] = (uint)&DAT_00002580 / uVar3;
  }
  if (*(char *)((int)param_2 + 0x13) != '\0') {
    memw();
    memw();
    param_1[1] = param_1[1] | 0x100;
    return (undefined *)0x0;
  }
  memw();
  memw();
  param_1[1] = param_1[1] & 0xfffffeff;
  return (undefined *)0x0;
}


// ===== USART_Deinit @ 00215d70 (77 bytes)

/* fsl_usart.c order [inference] */

void USART_Deinit(uint *param_1)

{
  uint uVar1;
  
  memw();
  uVar1 = param_1[2];
  while ((uVar1 & 8) == 0) {
    memw();
    uVar1 = param_1[2];
  }
  memw();
  param_1[0x385] = 0xf;
  memw();
  memw();
  param_1[0x380] = param_1[0x380] & 0xffffcfff;
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffffe;
  return;
}


// ===== USART_GetDefaultConfig @ 00215dc0 (60 bytes)

/* fsl_usart.c: 115200 baud [fact for the constant] */

void USART_GetDefaultConfig(undefined4 *param_1)

{
  memset(param_1,0,0x28);
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  param_1[9] = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  *param_1 = &DAT_0001c200;
  param_1[3] = 1;
  return;
}


// ===== USART_SetBaudRate @ 00215dfc (213 bytes)

/* fsl_usart.c: kStatus_USART_BaudrateNotSupport 5713 [inference] */

undefined * USART_SetBaudRate(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (((param_1 == (uint *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    return (undefined *)0x4;
  }
  memw();
  if ((*param_1 >> 0xb & 1) != 0) {
    memw();
    if ((*param_1 & 0x4000) == 0) {
      return (undefined *)0x0;
    }
    memw();
    param_1[8] = param_3 / param_2 - 1;
    return (undefined *)0x0;
  }
  uVar1 = ((param_3 * 10) / (param_2 << 4) - 5) / 10;
  uVar4 = 0xffffffff;
  if (uVar1 < 0x10000) {
    uVar2 = param_3 / ((uVar1 + 1) * 0x10);
    if (param_2 < uVar2) {
      iVar3 = uVar2 - param_2;
    }
    else {
      iVar3 = param_2 - uVar2;
    }
    if (iVar3 != -1) {
      uVar4 = uVar1;
    }
  }
  param_3 = param_3 / ((uVar4 + 1) * 0x10);
  if (param_2 < param_3) {
    param_3 = param_3 - param_2;
  }
  else {
    param_3 = param_2 - param_3;
  }
  if ((param_3 <= (param_2 / 100) * 3) && (uVar4 < 0x10000)) {
    memw();
    param_1[10] = 0xf;
    memw();
    param_1[8] = uVar4;
    return (undefined *)0x0;
  }
  return &DAT_00001651;
}


// ===== USART_Enable32kMode @ 00215ed4 (150 bytes)

/* fsl_usart.c: 9600 baud, calls USART_SetBaudRate [inference] */

undefined * USART_Enable32kMode(uint *param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffffe;
  if (param_3 == 0) {
    memw();
    memw();
    *param_1 = *param_1 & 0xffffff7f;
    puVar1 = (undefined *)USART_SetBaudRate(param_1,param_2,param_4);
    if (puVar1 != (undefined *)0x0) {
      return puVar1;
    }
    memw();
    memw();
    *param_1 = *param_1 | 1;
    return (undefined *)0x0;
  }
  memw();
  memw();
  *param_1 = *param_1 | 0x80;
  if ((uint)&DAT_00002580 % param_2 != 0) {
    return &DAT_00001651;
  }
  memw();
  param_1[8] = (uint)&DAT_00002580 / param_2 - 1;
  memw();
  memw();
  *param_1 = *param_1 | 1;
  return (undefined *)0x0;
}


// ===== USART_Enable9bitMode @ 00215f70 (67 bytes)

/* fsl_usart.c order [inference] */

void USART_Enable9bitMode(uint *param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *param_1 = *param_1 & 0xffffffc3 | 8;
    return;
  }
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffff3;
  memw();
  memw();
  *param_1 = *param_1 | 4;
  return;
}


// ===== USART_SendAddress @ 00215fb4 (19 bytes)

/* fsl_usart.c order [inference] */

void USART_SendAddress(int param_1,uint param_2)

{
  memw();
  *(uint *)(param_1 + 0xe20) = param_2 | 0x100;
  return;
}


// ===== USART_WriteBlocking @ 00215fc8 (103 bytes)

/* fsl_usart.c order [inference] */

undefined4 USART_WriteBlocking(int param_1,byte *param_2,int param_3)

{
  uint uVar1;
  
  if (((param_1 != 0) && (param_2 != (byte *)0x0)) &&
     (memw(), (*(uint *)(param_1 + 0xe00) & 1) != 0)) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      memw();
      uVar1 = *(uint *)(param_1 + 0xe04);
      while ((uVar1 & 0x20) == 0) {
        memw();
        uVar1 = *(uint *)(param_1 + 0xe04);
      }
      memw();
      *(uint *)(param_1 + 0xe20) = (uint)*param_2;
      param_2 = param_2 + 1;
    }
    memw();
    uVar1 = *(uint *)(param_1 + 8);
    while ((uVar1 & 8) == 0) {
      memw();
      uVar1 = *(uint *)(param_1 + 8);
    }
    return 0;
  }
  return 4;
}


// ===== USART_ReadBlocking @ 00216034 (193 bytes)

/* fsl_usart.c: kStatus_USART_* 5709..5712 [inference] */

undefined * USART_ReadBlocking(int param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  undefined *puVar2;
  
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    return (undefined *)0x4;
  }
  memw();
  if ((*(uint *)(param_1 + 0xe00) & 2) == 0) {
    return (undefined *)0x1;
  }
  if (param_3 != 0) {
    while( true ) {
      memw();
      uVar1 = *(uint *)(param_1 + 0xe04);
      while ((uVar1 & 0x40) == 0) {
        memw();
        uVar1 = *(uint *)(param_1 + 0xe04);
      }
      memw();
      if ((*(uint *)(param_1 + 0xe04) & 2) != 0) break;
      memw();
      uVar1 = *(uint *)(param_1 + 8);
      memw();
      memw();
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | uVar1;
      puVar2 = (undefined *)0x0;
      if ((uVar1 >> 0xf & 1) != 0) {
        puVar2 = &DAT_0000164e;
      }
      if (puVar2 != (undefined *)0x0) {
        return puVar2;
      }
      memw();
      *param_2 = (char)*(undefined4 *)(param_1 + 0xe30);
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
      if (param_3 == 0) {
        return puVar2;
      }
    }
    memw();
    memw();
    *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00020000;
    memw();
    memw();
    *(uint *)(param_1 + 0xe04) = *(uint *)(param_1 + 0xe04) | 2;
    return &DAT_0000164d;
  }
  return (undefined *)0x0;
}


// ===== USART_TransferCreateHandle @ 002160f8 (107 bytes)

/* fsl_usart.c: IRQ handler 0x21640C [inference] */

undefined4 USART_TransferCreateHandle(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    USART_GetInstance(param_1);
    memset(param_2,0,0x30);
    memw();
    *(undefined1 *)(param_2 + 0x2d) = 2;
    memw();
    *(undefined4 *)(param_2 + 0x28) = param_4;
    *(undefined4 *)(param_2 + 0x24) = param_3;
    *(undefined1 *)(param_2 + 0x2c) = 0;
    memw();
    *(byte *)(param_2 + 0x2f) = (byte)((uint)*(undefined4 *)(param_1 + 0xe08) >> 0x10) & 0xf;
    memw();
    *(byte *)(param_2 + 0x2e) = (byte)((uint)*(undefined4 *)(param_1 + 0xe08) >> 8) & 0xf;
    FLEXCOMM_SetIRQHandler(param_1,USART_TransferHandleIRQ,param_2);
    return 0;
  }
  return 4;
}


// ===== USART_TransferSendNonBlocking @ 00216164 (93 bytes)

/* fsl_usart.c: kStatus_USART_TxBusy 5700 [inference] */

undefined * USART_TransferSendNonBlocking(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((((param_1 != 0) && (param_2 != (int *)0x0)) && (param_3 != (int *)0x0)) &&
     ((param_3[1] != 0 && (*param_3 != 0)))) {
    memw();
    if ((char)param_2[0xb] == '\x01') {
      return &DAT_00001644;
    }
    uVar1 = USART_GetEnabledInterrupts(param_1);
    USART_DisableInterrupts(param_1,uVar1);
    memw();
    *param_2 = *param_3;
    iVar2 = param_3[1];
    memw();
    param_2[2] = iVar2;
    param_2[1] = iVar2;
    memw();
    *(undefined1 *)(param_2 + 0xb) = 1;
    USART_EnableInterrupts(param_1,uVar1 | 4);
    return (undefined *)0x0;
  }
  return (undefined *)0x4;
}


// ===== USART_TransferAbortSend @ 002161c4 (52 bytes)

/* fsl_usart.c order [inference] */

void USART_TransferAbortSend(int param_1,int param_2)

{
  USART_DisableInterrupts(param_1,4);
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00010000;
  memw();
  *(undefined4 *)(param_2 + 4) = 0;
  memw();
  *(undefined1 *)(param_2 + 0x2c) = 0;
  return;
}


// ===== USART_TransferGetSendCount @ 002161f8 (61 bytes)

/* fsl_usart.c order [inference] */

undefined4 USART_TransferGetSendCount(int param_1,int param_2,int *param_3)

{
  memw();
  if (*(char *)(param_2 + 0x2c) != '\0') {
    memw();
    memw();
    *param_3 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) -
               ((*(uint *)(param_1 + 0xe04) & (uint)&DAT_00001f00) >> 8);
    return 0;
  }
  return 6;
}


// ===== USART_TransferReceiveNonBlocking @ 00216238 (341 bytes)

/* fsl_usart.c order [inference] */

undefined * USART_TransferReceiveNonBlocking(uint *param_1,int param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  
  if (((param_1 != (uint *)0x0) && (param_2 != 0)) && (param_3 != (int *)0x0)) {
    uVar3 = param_3[1];
    if ((uVar3 != 0) && (*param_3 != 0)) {
      memw();
      if ((*param_1 >> 0x13 & 1) != 0) {
        memw();
        memw();
        param_1[1] = param_1[1] | 4;
      }
      memw();
      if (*(char *)(param_2 + 0x2d) == '\x03') {
        return &DAT_00001645;
      }
      if (*(int *)(param_2 + 0x18) == 0) {
        uVar1 = USART_GetEnabledInterrupts(param_1);
        USART_DisableInterrupts(param_1,uVar1);
        memw();
        *(int *)(param_2 + 0xc) = *param_3;
        memw();
        *(uint *)(param_2 + 0x10) = uVar3;
        *(uint *)(param_2 + 0x14) = uVar3;
        memw();
        *(undefined1 *)(param_2 + 0x2d) = 3;
        memw();
        param_1[900] = 8;
        USART_EnableInterrupts(param_1,uVar1);
        iVar4 = 0;
      }
      else {
        uVar1 = USART_GetEnabledInterrupts(param_1);
        USART_DisableInterrupts(param_1,uVar1);
        uVar2 = USART_TransferGetRxRingBufferLength(param_2);
        uVar6 = uVar2;
        if (uVar3 < uVar2) {
          uVar6 = uVar3;
        }
        if (uVar2 == 0) {
          iVar4 = 0;
        }
        else {
          uVar3 = uVar3 - uVar6;
          if (uVar6 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = 0;
            if ((uVar6 != 0) && ((uVar6 == 1 || (uVar6 != 0)))) {
              memw();
              *(undefined1 *)*param_3 =
                   *(undefined1 *)(*(int *)(param_2 + 0x18) + (uint)*(ushort *)(param_2 + 0x22));
              iVar4 = 1;
              memw();
              sVar5 = 0;
              if (*(ushort *)(param_2 + 0x22) + 1 != *(int *)(param_2 + 0x1c)) {
                memw();
                sVar5 = *(short *)(param_2 + 0x22) + 1;
              }
              memw();
              *(short *)(param_2 + 0x22) = sVar5;
            }
          }
        }
        if (uVar3 != 0) {
          memw();
          *(int *)(param_2 + 0xc) = *param_3 + iVar4;
          memw();
          *(uint *)(param_2 + 0x10) = uVar3;
          *(int *)(param_2 + 0x14) = param_3[1];
          memw();
          *(undefined1 *)(param_2 + 0x2d) = 3;
        }
        USART_EnableInterrupts(param_1,uVar1);
        if ((uVar3 == 0) && (*(code **)(param_2 + 0x24) != (code *)0x0)) {
          (**(code **)(param_2 + 0x24))
                    (param_1,param_2,&DAT_00001647,*(undefined4 *)(param_2 + 0x28));
        }
      }
      if (param_4 == (int *)0x0) {
        return (undefined *)0x0;
      }
      *param_4 = iVar4;
      return (undefined *)0x0;
    }
  }
  return (undefined *)0x4;
}


// ===== USART_TransferAbortReceive @ 00216394 (76 bytes)

/* fsl_usart.c order [inference] */

void USART_TransferAbortReceive(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x18) != 0) {
    memw();
    *(undefined4 *)(param_2 + 0x10) = 0;
    memw();
    *(undefined1 *)(param_2 + 0x2d) = 2;
    return;
  }
  USART_DisableInterrupts(param_1,8);
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00020000;
  memw();
  *(undefined4 *)(param_2 + 0x10) = 0;
  memw();
  *(undefined1 *)(param_2 + 0x2d) = 2;
  return;
}


// ===== USART_TransferGetReceiveCount @ 002163e4 (37 bytes)

/* fsl_usart.c order [inference] */

undefined4 USART_TransferGetReceiveCount(undefined4 param_1,int param_2,int *param_3)

{
  memw();
  if (*(char *)(param_2 + 0x2d) != '\x02') {
    memw();
    *param_3 = *(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10);
    return 0;
  }
  return 6;
}


// ===== USART_TransferHandleIRQ @ 0021640c (729 bytes)

/* fsl_usart.c; USART_TransferSendDMACallback (fsl_usart_dma.c, 0x2166F0) follows inside this
   listing entry [inference] */

void USART_TransferHandleIRQ(int param_1,int *param_2)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint in_w1_0_4;
  
  bVar1 = true;
  memw();
  if (param_2[4] == 0) {
    bVar1 = param_2[6] != 0;
  }
  memw();
  if (param_2[1] != 0) {
    in_w1_0_4 = 1;
  }
  memw();
  if ((*(uint *)(param_1 + 0xe04) & 2) != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0xe04) = *(uint *)(param_1 + 0xe04) | 2;
    memw();
    memw();
    iVar3 = param_2[9];
    *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00020000;
    if (iVar3 != 0) {
      (*(code *)param_2[9])(param_1,param_2,&DAT_0000164d,param_2[10]);
    }
  }
  if ((bVar1) && (memw(), (*(uint *)(param_1 + 0xe04) >> 6 & 1) != 0)) goto LAB_00216503;
  if (in_w1_0_4 != 0) {
    memw();
    uVar4 = *(uint *)(param_1 + 0xe04);
    while ((uVar4 >> 5 & 1) != 0) {
LAB_00216503:
      do {
        if ((bVar1) && (memw(), (*(uint *)(param_1 + 0xe04) & 0x40) != 0)) {
          memw();
          memw();
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffb;
          memw();
          if (param_2[4] == 0) {
            if (param_2[6] != 0) {
              iVar3 = USART_TransferGetRxRingBufferLength(param_2);
              if ((iVar3 == param_2[7] + -1) && ((code *)param_2[9] != (code *)0x0)) {
                (*(code *)param_2[9])(param_1,param_2,&DAT_0000164c,param_2[10]);
              }
              iVar3 = USART_TransferGetRxRingBufferLength(param_2);
              if (iVar3 == param_2[7] + -1) {
                memw();
                sVar2 = 0;
                if (*(ushort *)((int)param_2 + 0x22) + 1 != param_2[7]) {
                  memw();
                  sVar2 = *(short *)((int)param_2 + 0x22) + 1;
                }
                memw();
                *(short *)((int)param_2 + 0x22) = sVar2;
              }
              memw();
              memw();
              *(char *)(param_2[6] + (uint)*(ushort *)(param_2 + 8)) =
                   (char)*(undefined4 *)(param_1 + 0xe30);
              memw();
              sVar2 = 0;
              if (*(ushort *)(param_2 + 8) + 1 != param_2[7]) {
                memw();
                sVar2 = (short)param_2[8] + 1;
              }
              memw();
              *(short *)(param_2 + 8) = sVar2;
            }
          }
          else {
            memw();
            memw();
            *(char *)param_2[3] = (char)*(undefined4 *)(param_1 + 0xe30);
            memw();
            memw();
            param_2[4] = param_2[4] + -1;
            memw();
            memw();
            param_2[3] = param_2[3] + 1;
            bVar1 = true;
            memw();
            if (param_2[4] == 0) {
              bVar1 = param_2[6] != 0;
            }
            memw();
            if (param_2[4] == 0) {
              if (param_2[6] == 0) {
                memw();
                *(undefined4 *)(param_1 + 0xe14) = 10;
              }
              memw();
              *(undefined1 *)((int)param_2 + 0x2d) = 2;
              if (param_2[9] != 0) {
                (*(code *)param_2[9])(param_1,param_2,&DAT_00001647,param_2[10]);
              }
            }
          }
        }
        if ((in_w1_0_4 != 0) && (memw(), (*(uint *)(param_1 + 0xe04) & 0x20) != 0)) {
          memw();
          memw();
          *(uint *)(param_1 + 0xe20) = (uint)*(byte *)*param_2;
          memw();
          memw();
          param_2[1] = param_2[1] + -1;
          memw();
          memw();
          *param_2 = *param_2 + 1;
          memw();
          in_w1_0_4 = (uint)(param_2[1] != 0);
          if (in_w1_0_4 == 0) {
            memw();
            *(undefined4 *)(param_1 + 0xe14) = 4;
            memw();
            *(undefined4 *)(param_1 + 0xc) = 8;
          }
        }
      } while ((bVar1) && (memw(), (*(uint *)(param_1 + 0xe04) >> 6 & 1) != 0));
      if (in_w1_0_4 == 0) break;
      memw();
      uVar4 = *(uint *)(param_1 + 0xe04);
    }
  }
  memw();
  if (((*(uint *)(param_1 + 0xc) & 8) != 0) && (memw(), (*(uint *)(param_1 + 0x24) >> 3 & 1) != 0))
  {
    memw();
    *(undefined1 *)(param_2 + 0xb) = 0;
    memw();
    iVar3 = param_2[9];
    *(undefined4 *)(param_1 + 0x10) = 8;
    if (iVar3 != 0) {
      (*(code *)param_2[9])(param_1,param_2,&DAT_00001646,param_2[10]);
    }
  }
  if (param_2[6] == 0) {
    memw();
    uVar4 = param_2[4];
    if (uVar4 == 0) {
      memw();
      if ((*(uint *)(param_1 + 0xe08) & (uint)&DAT_000f0000) >> 0x10 !=
          (uint)*(byte *)((int)param_2 + 0x2f)) {
        memw();
        memw();
        *(uint *)(param_1 + 0xe08) =
             *(uint *)(param_1 + 0xe08) & 0xfff0ffff |
             (*(byte *)((int)param_2 + 0x2f) & 0xf) << 0x10;
        return;
      }
    }
    else {
      memw();
      if (uVar4 < ((*(uint *)(param_1 + 0xe08) & (uint)&DAT_000f0000) >> 0x10) + 1) {
        memw();
        memw();
        *(uint *)(param_1 + 0xe08) =
             *(uint *)(param_1 + 0xe08) & 0xfff0ffff | (uVar4 - 1) * 0x10000 & (uint)&DAT_000f0000;
        return;
      }
    }
  }
  return;
}

