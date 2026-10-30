// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== USART_TransferReceiveDMACallback @ 00216718 (55 bytes)

/* fsl_usart_dma.c static [inference] */

void USART_TransferReceiveDMACallback(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  memw();
  memw();
  *(uint *)(iVar1 + 0xe00) = *(uint *)(iVar1 + 0xe00) & 0xffffdfff;
  iVar2 = param_2[1];
  memw();
  *(undefined1 *)(iVar2 + 0x1d) = 2;
  if (*(int *)(iVar2 + 4) != 0) {
    (**(code **)(iVar2 + 4))(iVar1,iVar2,&DAT_00001647,*(undefined4 *)(iVar2 + 8));
  }
  return;
}


// ===== USART_TransferCreateHandleDMA @ 00216750 (118 bytes)

/* fsl_usart_dma.c: callbacks 0x2166F0 / 0x216718, IRQ 0x216914 [inference] */

undefined4
USART_TransferCreateHandleDMA
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = USART_GetInstance(param_1);
    memset(param_2,0,0x20);
    piVar2 = (int *)(&DAT_00239040 + iVar1 * 8);
    *(int *)(&DAT_00239044 + iVar1 * 8) = param_2;
    *piVar2 = param_1;
    memw();
    *(undefined1 *)(param_2 + 0x1d) = 2;
    memw();
    *(undefined4 *)(param_2 + 4) = param_3;
    *(undefined4 *)(param_2 + 8) = param_4;
    *(int *)(param_2 + 0x18) = param_6;
    *(int *)(param_2 + 0x14) = param_5;
    *(undefined1 *)(param_2 + 0x1c) = 0;
    FLEXCOMM_SetIRQHandler(param_1,USART_TransferDMAHandleIRQ,param_2);
    if (param_5 != 0) {
      DMA_SetCallback(param_5,&LAB_002166f0,piVar2);
    }
    if (param_6 != 0) {
      DMA_SetCallback(param_6,USART_TransferReceiveDMACallback,piVar2);
    }
    return 0;
  }
  return 4;
}


// ===== USART_TransferSendDMA @ 002167c8 (96 bytes)

/* fsl_usart_dma.c order [inference] */

undefined * USART_TransferSendDMA(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_40 [64];
  
  memw();
  if (*(char *)(param_2 + 0x1c) == '\x01') {
    return &DAT_00001644;
  }
  memw();
  *(undefined1 *)(param_2 + 0x1c) = 1;
  uVar1 = param_3[1];
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00001000;
  DMA_PrepareTransfer(auStack_40,*param_3,param_1 + 0xe20,1,uVar1,2,0);
  DMA_SubmitTransfer(*(undefined4 *)(param_2 + 0x14),auStack_40);
  DMA_StartTransfer(*(undefined4 *)(param_2 + 0x14));
  return (undefined *)0x0;
}


// ===== USART_TransferReceiveDMA @ 0021682c (102 bytes)

/* fsl_usart_dma.c order [inference] */

undefined * USART_TransferReceiveDMA(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_40 [64];
  
  memw();
  if (*(char *)(param_2 + 0x1d) == '\x03') {
    return &DAT_00001645;
  }
  memw();
  *(undefined1 *)(param_2 + 0x1d) = 3;
  uVar1 = param_3[1];
  *(undefined4 *)(param_2 + 0xc) = uVar1;
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00002000;
  DMA_PrepareTransfer(auStack_40,param_1 + 0xe30,*param_3,1,uVar1,1,0);
  DMA_SubmitTransfer(*(undefined4 *)(param_2 + 0x18),auStack_40);
  DMA_StartTransfer(*(undefined4 *)(param_2 + 0x18));
  return (undefined *)0x0;
}


// ===== USART_TransferAbortSendDMA @ 00216894 (18 bytes)

/* fsl_usart_dma.c order [inference] */

void USART_TransferAbortSendDMA(undefined4 param_1,int param_2)

{
  DMA_AbortTransfer(*(undefined4 *)(param_2 + 0x14));
  memw();
  *(undefined1 *)(param_2 + 0x1c) = 0;
  return;
}


// ===== USART_TransferAbortReceiveDMA @ 002168a8 (18 bytes)

/* fsl_usart_dma.c order [inference] */

void USART_TransferAbortReceiveDMA(undefined4 param_1,int param_2)

{
  DMA_AbortTransfer(*(undefined4 *)(param_2 + 0x18));
  memw();
  *(undefined1 *)(param_2 + 0x1d) = 2;
  return;
}


// ===== USART_TransferGetReceiveCountDMA @ 002168bc (41 bytes)

/* fsl_usart_dma.c order [inference] */

undefined4 USART_TransferGetReceiveCountDMA(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  
  memw();
  if (*(char *)(param_2 + 0x1d) == '\x02') {
    return 6;
  }
  iVar1 = DMA_GetRemainingBytes
                    (*(undefined4 *)(*(int *)(param_2 + 0x18) + 8),
                     *(undefined1 *)(*(int *)(param_2 + 0x18) + 0xc));
  *param_3 = *(int *)(param_2 + 0xc) - iVar1;
  return 0;
}


// ===== USART_TransferGetSendCountDMA @ 002168e8 (41 bytes)

/* fsl_usart_dma.c order [inference] */

undefined4 USART_TransferGetSendCountDMA(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  
  memw();
  if (*(char *)(param_2 + 0x1c) == '\0') {
    return 6;
  }
  iVar1 = DMA_GetRemainingBytes
                    (*(undefined4 *)(*(int *)(param_2 + 0x14) + 8),
                     *(undefined1 *)(*(int *)(param_2 + 0x14) + 0xc));
  *param_3 = *(int *)(param_2 + 0x10) - iVar1;
  return 0;
}


// ===== USART_TransferDMAHandleIRQ @ 00216914 (41 bytes)

/* fsl_usart_dma.c order [inference] */

void USART_TransferDMAHandleIRQ(int param_1,int param_2)

{
  int iVar1;
  
  memw();
  *(undefined1 *)(param_2 + 0x1c) = 0;
  memw();
  iVar1 = *(int *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x10) = 8;
  if (iVar1 != 0) {
    (**(code **)(param_2 + 4))(param_1,param_2,&DAT_00001646,*(undefined4 *)(param_2 + 8));
  }
  return;
}


// ===== UTICK_SetTick @ 00216940 (45 bytes)

/* fsl_utick.c: UTICK0 0x4000F000, callback 0x239084 [inference] */

void UTICK_SetTick(dword *param_1,int param_2,uint param_3,undefined4 param_4)

{
  (&DAT_00239084)[param_1 != &UTICK0_CTRL] = param_4;
  memw();
  *param_1 = param_3 | param_2 << 0x1f;
  return;
}


// ===== UTICK_Init @ 00216970 (196 bytes)

/* WARNING: Removing unreachable block (ram,0x00216a12) */
/* WARNING: Removing unreachable block (ram,0x002169a2) */
/* WARNING: Removing unreachable block (ram,0x00216993) */
/* WARNING: Removing unreachable block (ram,0x00216999) */
/* WARNING: Removing unreachable block (ram,0x0021699f) */
/* WARNING: Removing unreachable block (ram,0x00216a24) */
/* WARNING: Removing unreachable block (ram,0x00216a00) */
/* WARNING: Removing unreachable block (ram,0x002169e7) */
/* fsl_utick.c order [inference] */

void UTICK_Init(dword *param_1)

{
  memw();
  CLKCTL0_PSCCTL2_SET =
       1 << 0x20 - (0x20 - ((byte)(&DAT_00200618)[(uint)(param_1 != &UTICK0_CTRL) * 4] & 0x1f));
  RESET_PeripheralReset(*(undefined4 *)(&DAT_0020061c + (uint)(param_1 != &UTICK0_CTRL) * 4));
  DAT_00239080 = UTICK_HandleIRQ;
  return;
}


// ===== UTICK_Deinit @ 00216a38 (180 bytes)

/* WARNING: Removing unreachable block (ram,0x00216aca) */
/* WARNING: Removing unreachable block (ram,0x00216a86) */
/* WARNING: Removing unreachable block (ram,0x00216a5f) */
/* WARNING: Removing unreachable block (ram,0x00216a65) */
/* WARNING: Removing unreachable block (ram,0x00216a68) */
/* WARNING: Removing unreachable block (ram,0x00216a6b) */
/* WARNING: Removing unreachable block (ram,0x00216adb) */
/* WARNING: Removing unreachable block (ram,0x00216ab9) */
/* WARNING: Removing unreachable block (ram,0x00216aa8) */
/* fsl_utick.c order [inference] */

void UTICK_Deinit(dword *param_1)

{
  memw();
  *param_1 = 0;
  if (param_1 != &UTICK0_CTRL) {
    memw();
    CLKCTL0_PSCCTL2_CLR = 1;
    return;
  }
  memw();
  CLKCTL0_PSCCTL2_CLR = 1;
  return;
}


// ===== UTICK_GetStatusFlags @ 00216aec (10 bytes)

/* fsl_utick.c order [inference] */

undefined4 UTICK_GetStatusFlags(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 4);
}


// ===== UTICK_ClearStatusFlags @ 00216af8 (12 bytes)

/* fsl_utick.c; called by UTICK_HandleIRQ [inference] */

void UTICK_ClearStatusFlags(int param_1)

{
  memw();
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}


// ===== UTICK_HandleIRQ @ 00216b04 (15 bytes)

/* fsl_utick.c order [inference] */

void UTICK_HandleIRQ(undefined4 param_1,code *param_2)

{
  UTICK_ClearStatusFlags(param_1);
  if (param_2 != (code *)0x0) {
    (*param_2)();
  }
  return;
}


// ===== UTICK0_DriverIRQHandler @ 00216b14 (18 bytes)

/* fsl_utick.c order [inference] */

void UTICK0_DriverIRQHandler(void)

{
  (*DAT_00239080)(&UTICK0_CTRL,DAT_00239084);
  return;
}


// ===== WWDT_GetDefaultConfig @ 00216b30 (37 bytes)

/* fsl_wwdt.c order [inference] */

void WWDT_GetDefaultConfig(undefined4 *param_1)

{
  param_1[1] = 0xffffff;
  param_1[2] = 0xffffff;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined1 *)param_1 = 1;
  return;
}


// ===== WWDT_Init @ 00216b58 (420 bytes)

/* fsl_wwdt.c: clock 0x200628, SDK_DelayAtLeastUs [inference] */

void WWDT_Init(dword *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  dword dVar6;
  uint uVar7;
  
  iVar5 = 0;
  if (param_1 != &WWDT0_MOD) {
    iVar5 = 4;
  }
  uVar4 = *(uint *)((int)&DAT_00200628 + iVar5);
  uVar7 = uVar4 >> 8 & 0xff;
  if (uVar7 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
  }
  else if (uVar7 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
  }
  else if (uVar7 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
  }
  else if (uVar7 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
  }
  else if (uVar7 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
  }
  else if (uVar7 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
  }
  iVar5 = 0;
  if (param_1 != &WWDT0_MOD) {
    iVar5 = 4;
  }
  RESET_PeripheralReset(*(undefined4 *)((int)&DAT_00200630 + iVar5));
  bVar2 = param_2[1];
  bVar3 = param_2[3];
  bVar1 = *param_2;
  memw();
  memw();
  param_1[1] = *(uint *)(param_2 + 8) & 0xffffff;
  memw();
  *param_1 = (bVar3 & 1) << 5 | (uint)bVar1 | (bVar2 & 1) << 1 | 8;
  memw();
  param_1[6] = *(uint *)(param_2 + 4) & 0xffffff;
  memw();
  param_1[5] = *(uint *)(param_2 + 0xc) & 0x3ff;
  memw();
  param_1[2] = 0xaa;
  memw();
  param_1[2] = 0x55;
  if (bVar1 != 0) {
    memw();
    dVar6 = param_1[3];
    while (dVar6 == 0xff) {
      memw();
      dVar6 = param_1[3];
    }
  }
  if ((param_2[2] != 0) && (memw(), (*param_1 & 0x10) == 0)) {
    SDK_DelayAtLeastUs((uint)&DAT_002dc6c0 / *(uint *)(param_2 + 0x10) + 1,600000000);
    memw();
    memw();
    *param_1 = *param_1 | 0x10;
    return;
  }
  return;
}


// ===== WWDT_Deinit @ 00216d00 (173 bytes)

/* fsl_wwdt.c order [inference] */

void WWDT_Deinit(dword *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (param_1 != &WWDT0_MOD) {
    iVar2 = 4;
  }
  uVar1 = *(uint *)((int)&DAT_00200628 + iVar2);
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


// ===== WWDT_Refresh @ 00216db0 (20 bytes)

/* fsl_wwdt.c order [inference] */

void WWDT_Refresh(int param_1)

{
  memw();
  *(undefined4 *)(param_1 + 8) = 0xaa;
  memw();
  *(undefined4 *)(param_1 + 8) = 0x55;
  return;
}


// ===== WWDT_ClearStatusFlags @ 00216dc4 (45 bytes)

/* fsl_wwdt.c, last SDK driver function [inference] */

void WWDT_ClearStatusFlags(uint *param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *param_1 & 0xfffffff7;
  if ((param_2 >> 2 & 1) != 0) {
    uVar1 = *param_1 & 0xfffffff3;
  }
  if ((param_2 >> 3 & 1) != 0) {
    uVar1 = uVar1 | 8;
  }
  memw();
  *param_1 = uVar1;
  return;
}


// ===== vec_complex2mag @ 00216e00 (1708 bytes)

/* NDSP complexf/vec_complex2mag: |x| per bin (abs, max/min, sqrt0.s, divn.s, 0x400000); used by
   spectral_nr_frame [inference] */

void vec_complex2mag(undefined4 *param_1,undefined8 *param_2,uint param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  float fVar12;
  undefined8 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  undefined8 *puVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined4 *puVar23;
  int iVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  undefined8 uVar31;
  float fVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 local_230 [70];
  
  if ((int)param_3 < 1) {
    return;
  }
  uVar10 = param_3 & 0xfffffffe;
  iVar24 = uVar10 + 0x7e;
  if (-1 < (int)(uVar10 + 0x3f)) {
    iVar24 = uVar10 + 0x3f;
  }
  if (0 < iVar24 >> 6) {
    uVar18 = ae_zalign64();
    uVar25 = ae_movda32(0x7f);
    puVar17 = param_2 + (iVar24 >> 6) * 0x40;
    uVar26 = ae_movda32(&DAT_00400000);
    uVar27 = ae_movi(0);
    puVar9 = param_1;
    puVar11 = param_2;
    do {
      uVar4 = ((int)uVar10 < 0x40) * uVar10 + (uint)((int)uVar10 >= 0x40) * 0x40;
      uVar19 = ae_movalign(uVar18);
      iVar24 = (int)uVar4 >> 1;
      param_2 = puVar11;
      if (0 < iVar24) {
        puVar7 = local_230;
        puVar8 = puVar11;
        if ((uVar4 & 2) != 0) {
          uVar13 = ae_l32x2_ip(*puVar11);
          uVar20 = ae_l32x2_ip(puVar11[1]);
          puVar8 = puVar11 + 2;
          uVar21 = ae_sel16i((ulonglong)(uint)ABS((float)uVar13),(ulonglong)(uint)ABS((float)uVar20)
                             ,3);
          uVar28 = ae_sel16i_n((ulonglong)(uint)ABS((float)uVar13),
                               (ulonglong)(uint)ABS((float)uVar20),1);
          uVar13 = ae_max32(uVar28,uVar21);
          uVar13 = ae_srli32(uVar13,0x17);
          uVar13 = ae_sub32(uVar13,uVar25);
          uVar13 = ae_min32(uVar13,uVar25);
          uVar20 = ae_sub32(uVar25,uVar13);
          uVar14 = ae_eq32(uVar20,uVar27);
          uVar20 = ae_slai32(uVar20,0x17);
          uVar20 = ae_movt32x2(uVar20,uVar26,uVar14);
          fVar12 = (float)uVar28 * (float)uVar20;
          fVar32 = (float)uVar21 * (float)uVar20;
          uVar13 = ae_add32(uVar25,uVar13);
          uVar14 = ae_eq32(uVar13,uVar27);
          uVar13 = ae_slai32(uVar13,0x17);
          local_230[0] = ae_s32x2_ip((ulonglong)(uint)(fVar12 * fVar12 + fVar32 * fVar32));
          uVar13 = ae_movt32x2(uVar13,uVar26,uVar14);
          local_230[1] = ae_s32x2_ip(uVar13);
          puVar7 = local_230 + 2;
        }
        iVar5 = (int)uVar4 >> 2;
        param_2 = puVar8;
        if (iVar5 != 0) {
          uVar13 = ae_l32x2_ip(*puVar8);
          param_2 = puVar8 + 4;
          uVar20 = ae_l32x2_i(puVar8[3]);
          uVar21 = ae_l32x2_i(puVar8[1]);
          uVar28 = ae_l32x2_i(puVar8[2]);
          uVar22 = ae_sel16i((ulonglong)(uint)ABS((float)uVar13),(ulonglong)(uint)ABS((float)uVar21)
                             ,3);
          uVar33 = ae_sel16i((ulonglong)(uint)ABS((float)uVar13),(ulonglong)(uint)ABS((float)uVar21)
                             ,1);
          uVar13 = ae_max32(uVar33,uVar22);
          uVar21 = ae_sel16i_n((ulonglong)(uint)ABS((float)uVar28),
                               (ulonglong)(uint)ABS((float)uVar20),3);
          uVar28 = ae_sel16i((ulonglong)(uint)ABS((float)uVar28),(ulonglong)(uint)ABS((float)uVar20)
                             ,1);
          uVar13 = ae_srli32(uVar13,0x17);
          uVar20 = ae_max32(uVar28,uVar21);
          uVar13 = ae_sub32(uVar13,uVar25);
          uVar20 = ae_srli32(uVar20,0x17);
          uVar20 = ae_sub32(uVar20,uVar25);
          uVar34 = ae_min32(uVar13,uVar25);
          uVar13 = ae_sub32(uVar25,uVar34);
          uVar35 = ae_min32(uVar20,uVar25);
          uVar14 = ae_eq32(uVar13,uVar27);
          uVar20 = ae_sub32(uVar25,uVar35);
          uVar13 = ae_slai32(uVar13,0x17);
          uVar15 = ae_eq32(uVar20,uVar27);
          uVar36 = ae_movt32x2(uVar13,uVar26,uVar14);
          uVar13 = ae_slai32(uVar20,0x17);
          fVar12 = (float)uVar33 * (float)uVar36;
          fVar1 = (float)uVar22 * (float)uVar36;
          uVar13 = ae_movt32x2(uVar13,uVar26,uVar15);
          fVar32 = (float)uVar28 * (float)uVar13;
          fVar2 = (float)uVar21 * (float)uVar13;
          uVar13 = ae_add32(uVar25,uVar34);
          uVar14 = ae_eq32(uVar13,uVar27);
          uVar20 = ae_add32(uVar25,uVar35);
          uVar13 = ae_slai32(uVar13,0x17);
          uVar15 = ae_eq32(uVar20,uVar27);
          uVar29 = (ulonglong)(uint)(fVar12 * fVar12 + fVar1 * fVar1);
          uVar20 = ae_slai32(uVar20,0x17);
          uVar13 = ae_movt32x2(uVar13,uVar26,uVar14);
          uVar20 = ae_movt32x2(uVar20,uVar26,uVar15);
          uVar30 = (ulonglong)(uint)(fVar32 * fVar32 + fVar2 * fVar2);
          if (1 < iVar5) {
            uVar21 = ae_l32x2_ip(*param_2);
            param_2 = puVar8 + 8;
            uVar28 = ae_l32x2_i(puVar8[5]);
            uVar33 = ae_l32x2_i(puVar8[7]);
            uVar22 = ae_sel16i((ulonglong)(uint)ABS((float)uVar21),
                               (ulonglong)(uint)ABS((float)uVar28),3);
            uVar35 = ae_l32x2_i(puVar8[6]);
            uVar21 = ae_sel16i((ulonglong)(uint)ABS((float)uVar21),
                               (ulonglong)(uint)ABS((float)uVar28),1);
            uVar28 = ae_max32(uVar21,uVar22);
            uVar28 = ae_srli32(uVar28,0x17);
            uVar34 = ae_sel16i_n((ulonglong)(uint)ABS((float)uVar35),
                                 (ulonglong)(uint)ABS((float)uVar33),3);
            uVar35 = ae_sel16i((ulonglong)(uint)ABS((float)uVar35),
                               (ulonglong)(uint)ABS((float)uVar33),1);
            uVar28 = ae_sub32(uVar28,uVar25);
            uVar33 = ae_max32(uVar35,uVar34);
            uVar33 = ae_srli32(uVar33,0x17);
            uVar36 = ae_min32(uVar28,uVar25);
            uVar28 = ae_add32(uVar25,uVar36);
            uVar33 = ae_sub32(uVar33,uVar25);
            uVar36 = ae_sub32(uVar25,uVar36);
            uVar14 = ae_eq32(uVar28,uVar27);
            uVar37 = ae_min32(uVar33,uVar25);
            uVar15 = ae_eq32(uVar36,uVar27);
            uVar33 = ae_sub32(uVar25,uVar37);
            uVar36 = ae_slai32(uVar36,0x17);
            uVar16 = ae_eq32(uVar33,uVar27);
            uVar38 = ae_slai32(uVar33,0x17);
            uVar36 = ae_movt32x2(uVar36,uVar26,uVar15);
            uVar33 = ae_add32(uVar25,uVar37);
            uVar37 = ae_movt32x2(uVar38,uVar26,uVar16);
            fVar32 = (float)uVar37;
            fVar12 = (float)uVar36;
            puVar6 = puVar7;
            if (0 < iVar5 + -2) {
              uVar36 = ae_s32x2_ip(uVar29);
              *puVar7 = uVar36;
              puVar6 = puVar7 + 4;
              uVar36 = ae_l32x2_ip(*param_2);
              param_2 = puVar8 + 0xc;
              fVar1 = (float)uVar21 * fVar12;
              fVar2 = (float)uVar34 * fVar32;
              uVar13 = ae_s32x2_i(uVar13);
              puVar7[1] = uVar13;
              uVar21 = ae_l32x2_i(puVar8[9]);
              fVar12 = (float)uVar22 * fVar12;
              fVar32 = (float)uVar35 * fVar32;
              uVar13 = ae_s32x2_i(uVar30);
              puVar7[2] = uVar13;
              uVar35 = ae_l32x2_i(puVar8[10]);
              uVar28 = ae_slai32(uVar28,0x17);
              uVar13 = ae_s32x2_i(uVar20);
              puVar7[3] = uVar13;
              uVar20 = ae_l32x2_i(puVar8[0xb]);
              uVar37 = ae_slai32(uVar33,0x17);
              uVar22 = ae_sel16i((ulonglong)(uint)ABS((float)uVar36),
                                 (ulonglong)(uint)ABS((float)uVar21),3);
              uVar21 = ae_sel16i((ulonglong)(uint)ABS((float)uVar36),
                                 (ulonglong)(uint)ABS((float)uVar21),1);
              uVar13 = ae_max32(uVar21,uVar22);
              uVar34 = ae_sel16i_n((ulonglong)(uint)ABS((float)uVar35),
                                   (ulonglong)(uint)ABS((float)uVar20),3);
              uVar35 = ae_sel16i((ulonglong)(uint)ABS((float)uVar35),
                                 (ulonglong)(uint)ABS((float)uVar20),1);
              uVar13 = ae_srli32(uVar13,0x17);
              uVar15 = ae_eq32(uVar33,uVar27);
              uVar20 = ae_sub32(uVar13,uVar25);
              uVar13 = ae_movt32x2(uVar28,uVar26,uVar14);
              uVar28 = ae_min32(uVar20,uVar25);
              uVar30 = (ulonglong)(uint)(fVar32 * fVar32 + fVar2 * fVar2);
              uVar20 = ae_max32(uVar35,uVar34);
              uVar33 = ae_srli32(uVar20,0x17);
              uVar36 = ae_sub32(uVar25,uVar28);
              uVar20 = ae_movt32x2(uVar37,uVar26,uVar15);
              uVar15 = ae_eq32(uVar36,uVar27);
              uVar33 = ae_sub32(uVar33,uVar25);
              uVar37 = ae_slai32(uVar36,0x17);
              uVar28 = ae_add32(uVar25,uVar28);
              uVar29 = (ulonglong)(uint)(fVar1 * fVar1 + fVar12 * fVar12);
              uVar33 = ae_min32(uVar33,uVar25);
              uVar14 = ae_eq32(uVar28,uVar27);
              uVar36 = ae_sub32(uVar25,uVar33);
              uVar33 = ae_add32(uVar25,uVar33);
              uVar16 = ae_eq32(uVar36,uVar27);
              uVar38 = ae_slai32(uVar36,0x17);
              uVar36 = ae_movt32x2(uVar37,uVar26,uVar15);
              uVar37 = ae_movt32x2(uVar38,uVar26,uVar16);
              fVar12 = (float)uVar36;
              fVar32 = (float)uVar37;
            }
            fVar1 = (float)uVar22 * fVar12;
            fVar12 = (float)uVar21 * fVar12;
            fVar2 = (float)uVar35 * fVar32;
            fVar32 = (float)uVar34 * fVar32;
            uVar21 = ae_s32x2_ip(uVar29);
            *puVar6 = uVar21;
            puVar7 = puVar6 + 4;
            uVar21 = ae_s32x2_i(uVar30);
            puVar6[2] = uVar21;
            uVar15 = ae_eq32(uVar33,uVar27);
            uVar29 = (ulonglong)(uint)(fVar12 * fVar12 + fVar1 * fVar1);
            uVar20 = ae_s32x2_i(uVar20);
            puVar6[3] = uVar20;
            uVar20 = ae_slai32(uVar33,0x17);
            uVar13 = ae_s32x2_i(uVar13);
            puVar6[1] = uVar13;
            uVar30 = (ulonglong)(uint)(fVar2 * fVar2 + fVar32 * fVar32);
            uVar13 = ae_slai32(uVar28,0x17);
            uVar13 = ae_movt32x2(uVar13,uVar26,uVar14);
            uVar20 = ae_movt32x2(uVar20,uVar26,uVar15);
          }
          uVar21 = ae_s32x2_ip(uVar29);
          *puVar7 = uVar21;
          uVar13 = ae_s32x2_i(uVar13);
          puVar7[1] = uVar13;
          uVar13 = ae_s32x2_i(uVar30);
          puVar7[2] = uVar13;
          uVar13 = ae_s32x2_i(uVar20);
          puVar7[3] = uVar13;
        }
      }
      uVar10 = uVar10 - 0x40;
      puVar11 = puVar11 + 0x40;
      param_1 = puVar9;
      uVar13 = uVar19;
      if (0 < iVar24) {
        uVar28 = ae_l32x2_ip(local_230[0]);
        uVar21 = sqrt0_s(uVar28);
        uVar13 = const_s(0);
        uVar20 = maddn_s(uVar13,uVar21,uVar21);
        uVar22 = nexp01_s(uVar28);
        uVar13 = const_s(3);
        uVar33 = addexp_s(uVar22,uVar13);
        uVar13 = maddn_s(uVar13,uVar20,uVar33);
        uVar22 = maddn_s(uVar21,uVar13,uVar21);
        uVar34 = nexp01_s(uVar28);
        uVar13 = const_s(0);
        uVar20 = ae_mov(uVar13);
        uVar36 = msubn_s(uVar13,uVar34,uVar22);
        uVar13 = ae_mov(uVar20);
        uVar35 = const_s(3);
        uVar21 = maddn_s(uVar13,uVar22,uVar33);
        uVar20 = maddn_s(uVar20,uVar35,uVar22);
        uVar13 = maddn_s(uVar34,uVar36,uVar36);
        uVar21 = maddn_s(uVar35,uVar21,uVar22);
        uVar13 = maddn_s(uVar36,uVar13,(ulonglong)(uint)-(float)uVar20);
        uVar22 = nexp01_s(uVar28);
        uVar21 = maddn_s(uVar20,uVar21,uVar20);
        uVar28 = mksadj_s(uVar28);
        uVar20 = maddn_s(uVar22,uVar13,uVar13);
        uVar13 = addexpm_s(uVar13,uVar28);
        uVar21 = addexp_s((ulonglong)(uint)-(float)uVar21,uVar28);
        uVar20 = divn_s(uVar13,uVar20,uVar21);
        uVar13 = ae_l32x2_i(local_230[1]);
        uVar30 = (ulonglong)(uint)((float)uVar13 * (float)uVar20);
        puVar23 = puVar9;
        if (1 < iVar24) {
          uVar21 = ae_l32x2_ip(local_230[2]);
          uVar28 = sqrt0_s(uVar21);
          uVar13 = const_s(0);
          uVar20 = maddn_s(uVar13,uVar28,uVar28);
          uVar22 = nexp01_s(uVar21);
          uVar13 = const_s(3);
          uVar22 = addexp_s(uVar22,uVar13);
          uVar13 = maddn_s(uVar13,uVar20,uVar22);
          uVar35 = const_s(3);
          uVar36 = mksadj_s(uVar21);
          uVar34 = const_s(0);
          uVar28 = maddn_s(uVar28,uVar13,uVar28);
          uVar13 = ae_l32x2_i(local_230[3]);
          fVar12 = (float)uVar13;
          uVar33 = nexp01_s(uVar21);
          uVar20 = uVar21;
          uVar13 = uVar19;
          if (0 < iVar24 + -2) {
            uVar20 = ae_l32x2_ip(local_230[4]);
            uVar37 = nexp01_s(uVar21);
            uVar21 = ae_mov(uVar34);
            uVar13 = ae_mov(uVar21);
            uVar38 = maddn_s(uVar21,uVar35,uVar28);
            uVar39 = msubn_s(uVar34,uVar33,uVar28);
            uVar21 = maddn_s(uVar13,uVar28,uVar22);
            uVar13 = ae_sa32x2_ip(uVar30,uVar19,puVar9);
            puVar23 = (undefined4 *)ae_sa32x2_ip_1(uVar30,uVar19,puVar9);
            uVar22 = nexp01_s(uVar20);
            uVar34 = const_s(3);
            uVar33 = maddn_s(uVar33,uVar39,uVar39);
            uVar28 = maddn_s(uVar35,uVar21,uVar28);
            uVar19 = const_s(0);
            uVar31 = sqrt0_s(uVar20);
            uVar21 = maddn_s(uVar39,uVar33,(ulonglong)(uint)-(float)uVar38);
            uVar19 = maddn_s(uVar19,uVar31,uVar31);
            uVar28 = maddn_s(uVar38,uVar28,uVar38);
            uVar35 = const_s(3);
            uVar22 = addexp_s(uVar22,uVar34);
            uVar33 = maddn_s(uVar37,uVar21,uVar21);
            uVar34 = maddn_s(uVar34,uVar19,uVar22);
            uVar19 = addexp_s((ulonglong)(uint)-(float)uVar28,uVar36);
            uVar21 = addexpm_s(uVar21,uVar36);
            uVar19 = divn_s(uVar21,uVar33,uVar19);
            uVar36 = mksadj_s(uVar20);
            uVar28 = maddn_s(uVar31,uVar34,uVar31);
            uVar33 = nexp01_s(uVar20);
            uVar21 = ae_l32x2_i(local_230[5]);
            uVar34 = const_s(0);
            uVar30 = (ulonglong)(uint)(fVar12 * (float)uVar19);
            fVar12 = (float)uVar21;
          }
          uVar35 = ae_mov(uVar35);
          uVar21 = ae_mov(uVar34);
          uVar34 = msubn_s(uVar34,uVar33,uVar28);
          uVar19 = ae_mov(uVar21);
          uVar19 = maddn_s(uVar19,uVar28,uVar22);
          uVar22 = maddn_s(uVar21,uVar35,uVar28);
          uVar21 = maddn_s(uVar33,uVar34,uVar34);
          uVar28 = maddn_s(uVar35,uVar19,uVar28);
          uVar19 = maddn_s(uVar34,uVar21,(ulonglong)(uint)-(float)uVar22);
          uVar20 = nexp01_s(uVar20);
          uVar21 = maddn_s(uVar22,uVar28,uVar22);
          uVar20 = maddn_s(uVar20,uVar19,uVar19);
          uVar19 = addexpm_s(uVar19,uVar36);
          uVar21 = addexp_s((ulonglong)(uint)-(float)uVar21,uVar36);
          uVar20 = divn_s(uVar19,uVar20,uVar21);
          uVar19 = ae_sa32x2_ip(uVar30,uVar13,puVar23);
          puVar23 = (undefined4 *)ae_sa32x2_ip_1(uVar30,uVar13,puVar23);
          uVar30 = (ulonglong)(uint)(fVar12 * (float)uVar20);
        }
        uVar13 = ae_sa32x2_ip(uVar30,uVar19,puVar23);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar30,uVar19,puVar23);
      }
      ae_sa64pos_fp(uVar13,param_1);
      puVar9 = puVar9 + 0x40;
    } while (puVar11 != puVar17);
  }
  if ((param_3 & 1) != 0) {
    uVar18 = ae_l32x2_ip(*param_2);
    uVar30 = (ulonglong)(uint)ABS((float)uVar18);
    uVar25 = ae_sel16i(uVar30,uVar30,3);
    uVar27 = ae_sel16i_n(uVar30,uVar30,1);
    uVar18 = ae_max32(uVar27,uVar25);
    uVar18 = ae_srli32(uVar18,0x17);
    uVar13 = ae_movda32(0x7f);
    uVar18 = ae_sub32(uVar18,uVar13);
    uVar26 = ae_min32(uVar18,uVar13);
    uVar18 = ae_sub32(uVar13,uVar26);
    uVar20 = ae_movi(0);
    uVar14 = ae_eq32(uVar18,uVar20);
    uVar21 = ae_movda32(&DAT_00400000);
    uVar18 = ae_slai32(uVar18,0x17);
    uVar18 = ae_movt32x2(uVar18,uVar21,uVar14);
    fVar12 = (float)uVar27 * (float)uVar18;
    fVar32 = (float)uVar25 * (float)uVar18;
    uVar30 = (ulonglong)(uint)(fVar12 * fVar12 + fVar32 * fVar32);
    uVar27 = sqrt0_s(uVar30);
    uVar18 = const_s(0);
    uVar25 = maddn_s(uVar18,uVar27,uVar27);
    uVar19 = nexp01_s(uVar30);
    uVar18 = const_s(3);
    uVar28 = addexp_s(uVar19,uVar18);
    uVar18 = maddn_s(uVar18,uVar25,uVar28);
    uVar18 = maddn_s(uVar27,uVar18,uVar27);
    uVar22 = nexp01_s(uVar30);
    uVar25 = const_s(0);
    uVar19 = ae_mov(uVar25);
    uVar33 = msubn_s(uVar25,uVar22,uVar18);
    uVar27 = const_s(3);
    uVar25 = ae_mov(uVar19);
    uVar28 = maddn_s(uVar19,uVar18,uVar28);
    uVar25 = maddn_s(uVar25,uVar27,uVar18);
    uVar19 = maddn_s(uVar22,uVar33,uVar33);
    uVar27 = maddn_s(uVar27,uVar28,uVar18);
    uVar18 = maddn_s(uVar33,uVar19,(ulonglong)(uint)-(float)uVar25);
    uVar19 = nexp01_s(uVar30);
    uVar27 = maddn_s(uVar25,uVar27,uVar25);
    uVar28 = mksadj_s(uVar30);
    uVar25 = maddn_s(uVar19,uVar18,uVar18);
    uVar18 = addexpm_s(uVar18,uVar28);
    uVar27 = addexp_s((ulonglong)(uint)-(float)uVar27,uVar28);
    uVar25 = divn_s(uVar18,uVar25,uVar27);
    uVar18 = ae_add32(uVar13,uVar26);
    uVar14 = ae_eq32(uVar18,uVar20);
    uVar18 = ae_slai32(uVar18,0x17);
    uVar18 = ae_movt32x2(uVar18,uVar21,uVar14);
    uVar30 = (ulonglong)(uint)((float)uVar18 * (float)uVar25);
    uVar18 = ae_sel16i(uVar30,uVar30,3);
    uVar3 = ae_s32_l_x(uVar18);
    *param_1 = uVar3;
    return;
  }
  return;
}


// ===== fft_cplxf_ie @ 002174b0 (2144 bytes)

/* WARNING: Removing unreachable block (ram,0x00217730) */
/* NDSP fft/fft_ief: complex float FFT with external twiddles; its own sqrt(0.5) constant 0x200638
   (was fft512_cplx) [inference] */

undefined1  [16]
fft_cplxf_ie(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 *puVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  undefined8 *puVar25;
  uint uVar26;
  int iVar27;
  float fVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 *puVar32;
  ulonglong uVar33;
  ulonglong uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  ulonglong uVar39;
  ulonglong uVar40;
  ulonglong uVar41;
  undefined8 uVar42;
  ulonglong uVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  int iStack_44;
  
  uVar22 = param_5 >> 2;
  wur_ae_cbegin0(param_3);
  wur_ae_cend0(param_3 + uVar22 * (int)param_4 * 3);
  iVar23 = param_5 >> 3;
  uVar26 = uVar22;
  puVar21 = param_4;
  if (param_5 == 0x10) {
    uVar29 = ae_l32x2_ip(param_2[4]);
    uVar19 = ae_l32x2_ip(param_2[0xc]);
    uVar20 = ae_l32x2_ip(param_2[8]);
    uVar30 = ae_l32x2_ip(*param_2);
    uVar33 = (ulonglong)(uint)((float)uVar29 - (float)uVar19);
    fVar18 = (float)uVar29 + (float)uVar19;
    fVar14 = (float)uVar30 + (float)uVar20;
    fVar16 = (float)uVar30 - (float)uVar20;
    uVar19 = ae_l32x2_ip(param_2[5]);
    uVar29 = ae_l32x2_ip(param_2[0xd]);
    uVar20 = ae_sel16i(uVar33,uVar33,0);
    uVar33 = (ulonglong)(uint)((float)uVar19 - (float)uVar29);
    uVar30 = conjc_s(uVar20);
    fVar15 = (float)uVar19 + (float)uVar29;
    uVar20 = ae_l32x2_ip(param_2[9]);
    uVar29 = ae_l32x2_ip(param_2[1]);
    uVar34 = (ulonglong)(uint)(fVar14 - fVar18);
    uVar40 = (ulonglong)(uint)(fVar16 + (float)uVar30);
    fVar12 = (float)uVar29 + (float)uVar20;
    uVar19 = ae_s32x2_ip((ulonglong)(uint)(fVar14 + fVar18));
    *param_2 = uVar19;
    uVar31 = ae_l32x2_ip(*param_3);
    uVar35 = ae_sel16i_n(uVar33,uVar33,0);
    fVar13 = (float)uVar29 - (float)uVar20;
    uVar19 = ae_l32x2_i(param_3[1]);
    iVar23 = (int)param_4 * 0x18 + -0x10;
    uVar36 = conjc_s(uVar35);
    uVar41 = (ulonglong)(uint)(fVar16 - (float)uVar30);
    uVar20 = ae_l32x2_xc(param_3[2]);
    puVar21 = (undefined8 *)ae_circ0(param_3 + 2,iVar23);
    uVar37 = mulmux_s(uVar40,uVar31,0);
    uVar35 = mulmux_s(uVar34,uVar19,0);
    uVar29 = ae_l32x2_ip(param_2[0xe]);
    uVar38 = mulmux_s(uVar41,uVar20,0);
    uVar30 = ae_l32x2_ip(param_2[6]);
    uVar33 = (ulonglong)(uint)(fVar12 - fVar15);
    uVar42 = maddmux_s(uVar35,uVar34,uVar19,1);
    uVar35 = ae_l32x2_ip(param_2[10]);
    uVar34 = (ulonglong)(uint)((float)uVar30 - (float)uVar29);
    fVar14 = (float)uVar30 + (float)uVar29;
    uVar29 = ae_l32x2_ip(param_2[2]);
    uVar30 = ae_l32x2_ip(*puVar21);
    uVar39 = (ulonglong)(uint)(fVar13 + (float)uVar36);
    uVar37 = maddmux_s(uVar37,uVar40,uVar31,1);
    uVar19 = ae_s32x2_ip((ulonglong)(uint)(fVar12 + fVar15));
    param_2[1] = uVar19;
    fVar18 = (float)uVar29 + (float)uVar35;
    uVar38 = maddmux_s(uVar38,uVar41,uVar20,1);
    uVar19 = ae_s32x2_ip(uVar42);
    param_2[4] = uVar19;
    uVar31 = ae_l32x2_i(puVar21[1]);
    fVar12 = (float)uVar29 - (float)uVar35;
    uVar40 = (ulonglong)(uint)(fVar13 - (float)uVar36);
    uVar20 = ae_sel16i(uVar34,uVar34,0);
    uVar35 = ae_l32x2_xc(puVar21[2]);
    puVar21 = (undefined8 *)ae_circ0(puVar21 + 2,iVar23);
    uVar29 = mulmux_s(uVar33,uVar31,0);
    uVar19 = ae_s32x2_ip(uVar37);
    param_2[8] = uVar19;
    uVar36 = conjc_s(uVar20);
    uVar37 = mulmux_s(uVar39,uVar30,0);
    uVar19 = ae_s32x2_ip(uVar38);
    param_2[0xc] = uVar19;
    uVar19 = ae_mov(uVar29);
    uVar34 = (ulonglong)(uint)(fVar12 - (float)uVar36);
    uVar38 = maddmux_s(uVar19,uVar33,uVar31,1);
    uVar20 = ae_l32x2_ip(*puVar21);
    uVar29 = ae_l32x2_xc(puVar21[2]);
    ae_circ0(puVar21 + 2,iVar23);
    uVar31 = ae_l32x2_i(puVar21[1]);
    uVar19 = ae_s32x2_ip((ulonglong)(uint)(fVar18 + fVar14));
    param_2[2] = uVar19;
    uVar19 = mulmux_s(uVar34,uVar29,0);
    uVar41 = (ulonglong)(uint)(fVar18 - fVar14);
    uVar33 = (ulonglong)(uint)(fVar12 + (float)uVar36);
    uVar36 = maddmux_s(uVar19,uVar34,uVar29,1);
    uVar42 = mulmux_s(uVar41,uVar31,0);
    uVar29 = ae_mov(uVar35);
    uVar30 = maddmux_s(uVar37,uVar39,uVar30,1);
    uVar19 = ae_s32x2_ip(uVar38);
    param_2[5] = uVar19;
    uVar37 = mulmux_s(uVar40,uVar29,0);
    uVar38 = maddmux_s(uVar42,uVar41,uVar31,1);
    uVar31 = mulmux_s(uVar33,uVar20,0);
    uVar19 = ae_s32x2_ip(uVar30);
    param_2[9] = uVar19;
    uVar30 = ae_l32x2_ip(param_2[3]);
    uVar35 = ae_l32x2_ip(param_2[1]);
    uVar37 = maddmux_s(uVar37,uVar40,uVar29,1);
    uVar42 = maddmux_s(uVar31,uVar33,uVar20,1);
    uVar19 = ae_l32x2_ip(param_2[2]);
    uVar29 = ae_l32x2_ip(*param_2);
    fVar14 = (float)uVar35 + (float)uVar30;
    uVar20 = ae_l32x2_ip(param_2[7]);
    uVar31 = ae_l32x2_ip(param_2[5]);
    fVar18 = (float)uVar29 - (float)uVar19;
    fVar15 = (float)uVar29 + (float)uVar19;
    uVar19 = ae_l32x2_ip(param_2[6]);
    uVar29 = ae_l32x2_ip(param_2[4]);
    fVar13 = (float)uVar31 + (float)uVar20;
    fVar12 = (float)uVar29 - (float)uVar19;
    fVar16 = (float)uVar29 + (float)uVar19;
    uVar19 = ae_s32x2_ip(uVar37);
    param_2[0xd] = uVar19;
    uVar19 = ae_s32x2_ip(uVar36);
    param_2[0xe] = uVar19;
    uVar19 = ae_s32x2_ip(uVar38);
    param_2[6] = uVar19;
    uVar29 = conjc_s((ulonglong)(uint)((float)uVar35 - (float)uVar30));
    uVar19 = ae_s32x2_ip(uVar42);
    param_2[10] = uVar19;
    puVar21 = param_1 + 8;
    uVar29 = ae_sel16i_n(uVar29,uVar29,0);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 - fVar14));
    *puVar21 = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 + fVar14));
    *param_1 = uVar19;
    iVar23 = ae_addbrba32(0,0x8000000);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 + fVar13));
    *(undefined8 *)((int)param_1 + iVar23) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 - fVar13));
    *(undefined8 *)((int)puVar21 + iVar23) = uVar19;
    puVar32 = param_1 + 0xc;
    uVar20 = conjc_s((ulonglong)(uint)((float)uVar31 - (float)uVar20));
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar18 + (float)uVar29));
    *puVar32 = uVar19;
    puVar8 = param_1 + 4;
    uVar38 = ae_sel16i_n(uVar20,uVar20,0);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar18 - (float)uVar29));
    *puVar8 = uVar19;
    iVar24 = ae_addbrba32(iVar23,0x8000000);
    uVar19 = ae_l32x2_ip(param_2[0xb]);
    uVar35 = ae_l32x2_ip(param_2[9]);
    uVar20 = ae_l32x2_ip(param_2[10]);
    uVar31 = ae_l32x2_ip(param_2[8]);
    uVar29 = ae_l32x2_ip(param_2[0xf]);
    uVar36 = ae_l32x2_ip(param_2[0xd]);
    fVar18 = (float)uVar35 + (float)uVar19;
    fVar15 = (float)uVar31 + (float)uVar20;
    fVar28 = (float)uVar36 + (float)uVar29;
    uVar30 = ae_l32x2_ip(param_2[0xe]);
    uVar37 = ae_l32x2_ip(param_2[0xc]);
    fVar16 = (float)uVar31 - (float)uVar20;
    uVar19 = conjc_s((ulonglong)(uint)((float)uVar35 - (float)uVar19));
    fVar13 = (float)uVar37 + (float)uVar30;
    uVar20 = ae_sel16i(uVar19,uVar19,0);
    fVar14 = (float)uVar37 - (float)uVar30;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar12 + (float)uVar38));
    *(undefined8 *)((int)puVar32 + iVar23) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 - fVar18));
    *(undefined8 *)((int)puVar21 + iVar24) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar12 - (float)uVar38));
    *(undefined8 *)((int)puVar8 + iVar23) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 + fVar18));
    *(undefined8 *)((int)param_1 + iVar24) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 - (float)uVar20));
    *(undefined8 *)((int)puVar8 + iVar24) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 + (float)uVar20));
    *(undefined8 *)((int)puVar32 + iVar24) = uVar19;
    iVar23 = ae_addbrba32(iVar24,0x8000000);
    uVar20 = conjc_s((ulonglong)(uint)((float)uVar36 - (float)uVar29));
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar13 + fVar28));
    *(undefined8 *)((int)param_1 + iVar23) = uVar19;
    uVar20 = ae_sel16i(uVar20,uVar20,0);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar13 - fVar28));
    *(undefined8 *)((int)puVar21 + iVar23) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 - (float)uVar20));
    *(undefined8 *)((int)puVar8 + iVar23) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 + (float)uVar20));
    *(undefined8 *)((int)puVar32 + iVar23) = uVar19;
    auVar5._4_4_ = param_2 + 0x12;
    auVar5._0_4_ = param_2 + 0x11;
    auVar5._8_4_ = param_2 + 0x10;
    auVar5._12_4_ = 0;
    return auVar5 << 0x20;
  }
  for (; 2 < (int)uVar26; uVar26 = (int)uVar26 >> 2) {
    iVar24 = (int)puVar21 * 0x18 + -0x10;
    iStack_44 = 0;
    param_4 = param_2;
    do {
      puVar9 = param_4 + uVar26;
      uVar30 = ae_l32x2_ip(*param_4);
      puVar10 = puVar9 + uVar26;
      puVar11 = puVar10 + uVar26;
      uVar29 = ae_l32x2_ip(*puVar9);
      uVar19 = ae_l32x2_ip(*puVar11);
      uVar20 = ae_l32x2_ip(*puVar10);
      uVar33 = (ulonglong)(uint)((float)uVar29 - (float)uVar19);
      fVar18 = (float)uVar29 + (float)uVar19;
      fVar13 = (float)uVar30 + (float)uVar20;
      uVar29 = ae_l32x2_ip(puVar9[1]);
      fVar16 = (float)uVar30 - (float)uVar20;
      uVar19 = ae_l32x2_ip(puVar11[1]);
      uVar20 = ae_sel16i(uVar33,uVar33,0);
      uVar33 = (ulonglong)(uint)((float)uVar29 - (float)uVar19);
      uVar30 = ae_l32x2_ip(param_4[1]);
      uVar35 = conjc_s(uVar20);
      uVar41 = (ulonglong)(uint)(fVar13 - fVar18);
      uVar20 = ae_l32x2_ip(puVar10[1]);
      uVar43 = (ulonglong)(uint)(fVar16 + (float)uVar35);
      fVar12 = (float)uVar29 + (float)uVar19;
      fVar14 = (float)uVar30 + (float)uVar20;
      uVar19 = ae_sel16i(uVar33,uVar33,0);
      uVar36 = ae_l32x2_ip(*param_3);
      fVar15 = (float)uVar30 - (float)uVar20;
      uVar20 = ae_l32x2_i(param_3[1]);
      uVar29 = conjc_s(uVar19);
      uVar39 = (ulonglong)(uint)(fVar16 - (float)uVar35);
      uVar19 = ae_s32x2_ip((ulonglong)(uint)(fVar13 + fVar18));
      *param_4 = uVar19;
      puVar8 = param_4 + 1;
      uVar35 = ae_l32x2_xc(param_3[2]);
      puVar32 = (undefined8 *)ae_circ0(param_3 + 2,iVar24);
      uVar30 = mulmux_s(uVar41,uVar20,0);
      uVar31 = mulmux_s(uVar43,uVar36,0);
      uVar40 = (ulonglong)(uint)(fVar14 + fVar12);
      uVar33 = uVar41;
      uVar34 = uVar43;
      uVar19 = uVar36;
      fVar18 = fVar15;
      if (0 < (int)(uVar26 - 2)) {
        uVar19 = ae_l32x2_ip(puVar11[2]);
        uVar38 = mulmux_s(uVar39,uVar35,0);
        uVar37 = ae_l32x2_ip(puVar9[2]);
        uVar33 = (ulonglong)(uint)(fVar14 - fVar12);
        uVar42 = maddmux_s(uVar30,uVar41,uVar20,1);
        uVar30 = ae_l32x2_ip(puVar10[2]);
        uVar41 = (ulonglong)(uint)((float)uVar37 - (float)uVar19);
        fVar12 = (float)uVar37 + (float)uVar19;
        uVar37 = ae_l32x2_ip(param_4[2]);
        uVar19 = ae_l32x2_ip(*puVar32);
        uVar34 = (ulonglong)(uint)(fVar15 + (float)uVar29);
        uVar36 = maddmux_s(uVar31,uVar43,uVar36,1);
        uVar20 = ae_s32x2_ip(uVar40);
        *puVar8 = uVar20;
        puVar8 = param_4 + 2;
        fVar14 = (float)uVar37 + (float)uVar30;
        uVar38 = maddmux_s(uVar38,uVar39,uVar35,1);
        uVar20 = ae_s32x2_ip(uVar42);
        *puVar9 = uVar20;
        puVar9 = puVar9 + 1;
        uVar20 = ae_l32x2_i(puVar32[1]);
        fVar18 = (float)uVar37 - (float)uVar30;
        uVar39 = (ulonglong)(uint)(fVar15 - (float)uVar29);
        uVar31 = ae_sel16i(uVar41,uVar41,0);
        uVar35 = ae_l32x2_xc(puVar32[2]);
        puVar32 = (undefined8 *)ae_circ0(puVar32 + 2,iVar24);
        uVar30 = mulmux_s(uVar33,uVar20,0);
        uVar29 = ae_s32x2_ip(uVar36);
        *puVar10 = uVar29;
        puVar10 = puVar10 + 1;
        uVar29 = conjc_s(uVar31);
        uVar31 = mulmux_s(uVar34,uVar19,0);
        uVar36 = ae_s32x2_ip(uVar38);
        *puVar11 = uVar36;
        puVar11 = puVar11 + 1;
        uVar40 = (ulonglong)(uint)(fVar14 + fVar12);
      }
      uVar36 = ae_mov((ulonglong)(uint)fVar12);
      uVar29 = ae_mov(uVar29);
      uVar41 = (ulonglong)(uint)(fVar14 - (float)uVar36);
      uVar44 = ae_mov(uVar33);
      uVar36 = ae_mov((ulonglong)(uint)fVar18);
      uVar38 = ae_l32x2_ip(*puVar32);
      uVar33 = (ulonglong)(uint)(fVar18 + (float)uVar29);
      uVar45 = ae_mov(uVar19);
      uVar37 = ae_mov(uVar39);
      uVar19 = ae_l32x2_i(puVar32[1]);
      uVar42 = mulmux_s(uVar39,uVar35,0);
      uVar39 = (ulonglong)(uint)((float)uVar36 - (float)uVar29);
      uVar36 = mulmux_s(uVar41,uVar19,0);
      uVar31 = maddmux_s(uVar31,uVar34,uVar45,1);
      uVar45 = mulmux_s(uVar33,uVar38,0);
      uVar29 = ae_l32x2_xc(puVar32[2]);
      param_3 = (undefined8 *)ae_circ0(puVar32 + 2,iVar24);
      uVar20 = maddmux_s(uVar30,uVar44,uVar20,1);
      uVar30 = mulmux_s(uVar39,uVar29,0);
      uVar44 = maddmux_s(uVar36,uVar41,uVar19,1);
      uVar19 = ae_s32x2_ip(uVar40);
      *puVar8 = uVar19;
      uVar36 = maddmux_s(uVar45,uVar33,uVar38,1);
      uVar19 = ae_s32x2_ip(uVar20);
      *puVar9 = uVar19;
      uVar20 = maddmux_s(uVar42,uVar37,uVar35,1);
      uVar19 = ae_s32x2_ip(uVar44);
      puVar9[1] = uVar19;
      uVar29 = maddmux_s(uVar30,uVar39,uVar29,1);
      uVar19 = ae_s32x2_ip(uVar31);
      *puVar10 = uVar19;
      uVar19 = ae_s32x2_ip(uVar36);
      puVar10[1] = uVar19;
      uVar19 = ae_s32x2_ip(uVar20);
      *puVar11 = uVar19;
      uVar19 = ae_s32x2_ip(uVar29);
      puVar11[1] = uVar19;
      param_4 = puVar11 + 2;
      iStack_44 = iStack_44 + uVar26;
    } while (iStack_44 < (int)uVar22);
    puVar21 = (undefined8 *)((int)puVar21 << 2);
  }
  if ((int)uVar26 < 2) {
    uVar19 = ae_l32x2_ip(param_2[3]);
    uVar35 = ae_l32x2_ip(param_2[1]);
    uVar20 = ae_l32x2_ip(param_2[2]);
    uVar31 = ae_l32x2_ip(*param_2);
    fVar18 = (float)uVar35 + (float)uVar19;
    fVar15 = (float)uVar31 + (float)uVar20;
    uVar29 = ae_l32x2_ip(param_2[7]);
    uVar36 = ae_l32x2_ip(param_2[5]);
    puVar21 = param_2 + 9;
    uVar30 = ae_l32x2_ip(param_2[6]);
    puVar32 = param_2 + 10;
    uVar37 = ae_l32x2_ip(param_2[4]);
    fVar14 = (float)uVar31 - (float)uVar20;
    fVar13 = (float)uVar37 - (float)uVar30;
    uVar19 = conjc_s((ulonglong)(uint)((float)uVar35 - (float)uVar19));
    uVar20 = ae_sel16i(uVar19,uVar19,0);
    puVar8 = param_1 + uVar22;
    uVar19 = conjc_s((ulonglong)(uint)((float)uVar36 - (float)uVar29));
    puVar9 = puVar8 + uVar22;
    uVar35 = ae_sel16i_n(uVar19,uVar19,0);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 - fVar18));
    *puVar9 = uVar19;
    fVar12 = (float)uVar36 + (float)uVar29;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 + fVar18));
    *param_1 = uVar19;
    puVar10 = puVar9 + uVar22;
    fVar18 = (float)uVar37 + (float)uVar30;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 + (float)uVar20));
    *puVar10 = uVar19;
    uVar26 = 0x80000000 >> (0x20U - LZCOUNT(~uVar22) & 0x1f);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 - (float)uVar20));
    *puVar8 = uVar19;
    iVar27 = ae_addbrba32(0,uVar26);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar13 - (float)uVar35));
    *(undefined8 *)((int)puVar8 + iVar27) = uVar19;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar13 + (float)uVar35));
    *(undefined8 *)((int)puVar10 + iVar27) = uVar19;
    uVar33 = (ulonglong)(uint)(fVar18 + fVar12);
    iVar24 = ae_addbrba32(iVar27,uVar26);
    uVar34 = (ulonglong)(uint)(fVar18 - fVar12);
    if (1 < iVar23) {
      uVar19 = ae_l32x2_ip(param_2[0xb]);
      uVar35 = ae_l32x2_ip(*puVar21);
      uVar20 = ae_l32x2_ip(param_2[0xf]);
      uVar31 = ae_l32x2_ip(param_2[0xd]);
      puVar21 = param_2 + 0x11;
      uVar29 = ae_l32x2_ip(*puVar32);
      uVar36 = ae_l32x2_ip(param_2[8]);
      fVar18 = (float)uVar31 + (float)uVar20;
      fVar12 = (float)uVar35 + (float)uVar19;
      fVar14 = (float)uVar36 + (float)uVar29;
      uVar30 = ae_l32x2_ip(param_2[0xe]);
      puVar32 = param_2 + 0x12;
      uVar37 = ae_l32x2_ip(param_2[0xc]);
      param_4 = param_2 + 0x10;
      uVar35 = conjc_s((ulonglong)(uint)((float)uVar35 - (float)uVar19));
      fVar15 = (float)uVar36 - (float)uVar29;
      uVar19 = conjc_s((ulonglong)(uint)((float)uVar31 - (float)uVar20));
      fVar13 = (float)uVar30;
      fVar17 = (float)uVar37;
      fVar16 = fVar17 - fVar13;
      uVar20 = ae_sel16i(uVar35,uVar35,0);
      fVar28 = (float)uVar20;
      if (0 < iVar23 + -2) {
        uVar20 = ae_s32x2_x(uVar33);
        *(undefined8 *)((int)param_1 + iVar27) = uVar20;
        uVar30 = ae_l32x2_ip(*param_4);
        fVar13 = fVar17 + fVar13;
        uVar20 = ae_s32x2_x(uVar34);
        *(undefined8 *)((int)puVar9 + iVar27) = uVar20;
        uVar35 = ae_l32x2_ip(*puVar21);
        uVar20 = ae_l32x2_ip(param_2[0x13]);
        iVar27 = ae_addbrba32(iVar24,uVar26);
        fVar1 = fVar14 - fVar12;
        uVar37 = ae_sel16i(uVar19,uVar19,0);
        uVar29 = ae_l32x2_ip(param_2[0x17]);
        uVar19 = ae_l32x2_ip(param_2[0x14]);
        param_4 = param_2 + 0x18;
        fVar17 = (float)uVar19;
        uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 + fVar12));
        *(undefined8 *)((int)param_1 + iVar24) = uVar19;
        uVar31 = ae_l32x2_ip(param_2[0x15]);
        puVar21 = param_2 + 0x19;
        fVar12 = (float)uVar35 + (float)uVar20;
        uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 + fVar28));
        *(undefined8 *)((int)puVar10 + iVar24) = uVar19;
        uVar36 = ae_l32x2_ip(*puVar32);
        uVar34 = (ulonglong)(uint)(fVar13 - fVar18);
        uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 - fVar28));
        *(undefined8 *)((int)puVar8 + iVar24) = uVar19;
        fVar14 = (float)uVar30 + (float)uVar36;
        uVar33 = (ulonglong)(uint)(fVar13 + fVar18);
        uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 - (float)uVar37));
        *(undefined8 *)((int)puVar8 + iVar27) = uVar19;
        uVar19 = ae_l32x2_ip(param_2[0x16]);
        puVar32 = param_2 + 0x1a;
        fVar15 = (float)uVar30 - (float)uVar36;
        fVar18 = (float)uVar31 + (float)uVar29;
        fVar13 = (float)uVar19;
        uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 + (float)uVar37));
        *(undefined8 *)((int)puVar10 + iVar27) = uVar19;
        uVar20 = conjc_s((ulonglong)(uint)((float)uVar35 - (float)uVar20));
        fVar16 = fVar17 - fVar13;
        uVar19 = ae_s32x2_x((ulonglong)(uint)fVar1);
        *(undefined8 *)((int)puVar9 + iVar24) = uVar19;
        iVar24 = ae_addbrba32(iVar27,uVar26);
        uVar19 = conjc_s((ulonglong)(uint)((float)uVar31 - (float)uVar29));
        uVar20 = ae_sel16i(uVar20,uVar20,0);
        fVar28 = (float)uVar20;
      }
      uVar20 = ae_s32x2_x(uVar34);
      *(undefined8 *)((int)puVar9 + iVar27) = uVar20;
      uVar20 = ae_s32x2_x(uVar33);
      *(undefined8 *)((int)param_1 + iVar27) = uVar20;
      uVar20 = ae_sel16i_n(uVar19,uVar19,0);
      uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 + fVar12));
      *(undefined8 *)((int)param_1 + iVar24) = uVar19;
      uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 - fVar12));
      *(undefined8 *)((int)puVar9 + iVar24) = uVar19;
      uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 + fVar28));
      *(undefined8 *)((int)puVar10 + iVar24) = uVar19;
      uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 - fVar28));
      *(undefined8 *)((int)puVar8 + iVar24) = uVar19;
      iVar27 = ae_addbrba32(iVar24,uVar26);
      uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 - (float)uVar20));
      *(undefined8 *)((int)puVar8 + iVar27) = uVar19;
      uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar16 + (float)uVar20));
      *(undefined8 *)((int)puVar10 + iVar27) = uVar19;
      uVar33 = (ulonglong)(uint)(fVar17 + fVar13 + fVar18);
      uVar34 = (ulonglong)(uint)((fVar17 + fVar13) - fVar18);
    }
    uVar19 = ae_s32x2_x(uVar34);
    *(undefined8 *)((int)puVar9 + iVar27) = uVar19;
    uVar19 = ae_s32x2_x(uVar33);
    *(undefined8 *)((int)param_1 + iVar27) = uVar19;
    auVar7._4_4_ = puVar32;
    auVar7._0_4_ = puVar21;
    auVar7._8_4_ = param_4;
    auVar7._12_4_ = 0;
    return auVar7 << 0x20;
  }
  uVar20 = ae_l32x2_ip(*param_2);
  uVar19 = ae_l32x2_i(param_2[2]);
  uVar29 = ae_l32x2_i(param_2[1]);
  uVar31 = ae_l32x2_ip(param_2[4]);
  uVar30 = ae_l32x2_i(param_2[6]);
  uVar36 = ae_l32x2_i(param_2[5]);
  fVar18 = (float)uVar20 + (float)uVar31;
  uVar35 = ae_l32x2_ip(param_2[3]);
  uVar37 = ae_l32x2_ip(param_2[7]);
  puVar21 = param_2 + 0xc;
  fVar12 = (float)uVar29 + (float)uVar36;
  fVar15 = (float)uVar19 + (float)uVar30;
  uVar33 = (ulonglong)(uint)((float)uVar35 - (float)uVar37);
  fVar16 = (float)uVar35 + (float)uVar37;
  fVar14 = (float)uVar20 - (float)uVar31;
  fVar13 = (float)uVar29 - (float)uVar36;
  uVar34 = (ulonglong)(uint)((float)uVar19 - (float)uVar30);
  fVar28 = fVar18 + fVar15;
  uVar19 = ae_sel16i(uVar33,uVar33,0);
  uVar33 = (ulonglong)(uint)(fVar12 - fVar16);
  fVar12 = fVar12 + fVar16;
  puVar32 = param_1 + iVar23;
  uVar20 = conjc_s(uVar19);
  uVar19 = ae_sel16i(uVar34,uVar34,0);
  puVar9 = puVar32 + iVar23;
  fVar18 = fVar18 - fVar15;
  fVar16 = fVar13 + (float)uVar20;
  puVar8 = puVar9 + iVar23;
  uVar29 = conjc_s(uVar19);
  fVar13 = fVar13 - (float)uVar20;
  iVar24 = 0;
  uVar19 = ae_sel16i(uVar33,uVar33,0);
  puVar10 = puVar8 + iVar23;
  fVar15 = fVar14 - (float)uVar29;
  puVar11 = puVar10 + iVar23;
  uVar30 = conjc_s(uVar19);
  fVar14 = fVar14 + (float)uVar29;
  uVar19 = ae_sel16i((ulonglong)(uint)fVar16,(ulonglong)(uint)fVar16,0);
  puVar25 = puVar11 + iVar23;
  uVar33 = (ulonglong)(uint)(fVar28 + fVar12);
  uVar39 = (ulonglong)(uint)(fVar18 + (float)uVar30);
  uVar20 = ae_sel16i((ulonglong)(uint)fVar13,(ulonglong)(uint)fVar13,0);
  uVar29 = conjc_s(uVar19);
  uVar34 = (ulonglong)(uint)(fVar18 - (float)uVar30);
  uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar28 - fVar12));
  *puVar10 = uVar19;
  uVar20 = conjc_s(uVar20);
  fVar16 = (float)uVar29 + fVar16;
  uVar19 = ae_l32_i(0x3f3504f3);
  fVar13 = (float)uVar20 - fVar13;
  fVar12 = (float)uVar19;
  fVar18 = fVar15;
  if (0 < iVar23 + -1) {
    uVar19 = ae_l32x2_ip(param_2[8]);
    uVar29 = ae_l32x2_ip(*puVar21);
    uVar20 = ae_l32x2_i(param_2[0xd]);
    uVar30 = ae_l32x2_i(param_2[9]);
    fVar28 = (float)uVar19 + (float)uVar29;
    fVar4 = (float)uVar19 - (float)uVar29;
    uVar19 = ae_l32x2_i(param_2[10]);
    uVar29 = ae_l32x2_i(param_2[0xe]);
    fVar1 = (float)uVar30 - (float)uVar20;
    fVar2 = (float)uVar30 + (float)uVar20;
    uVar20 = ae_l32x2_ip(param_2[0xf]);
    puVar21 = param_2 + 0x14;
    uVar30 = ae_l32x2_ip(param_2[0xb]);
    fVar18 = (float)uVar19 + (float)uVar29;
    uVar40 = (ulonglong)(uint)((float)uVar19 - (float)uVar29);
    uVar19 = ae_s32x2_x(uVar39);
    *puVar9 = uVar19;
    uVar39 = (ulonglong)(uint)((float)uVar30 - (float)uVar20);
    fVar3 = (float)uVar30 + (float)uVar20;
    uVar19 = ae_s32x2_x(uVar33);
    *param_1 = uVar19;
    uVar19 = ae_s32x2_x(uVar34);
    *puVar25 = uVar19;
    uVar19 = ae_sel16i(uVar40,uVar40,0);
    fVar17 = fVar28 + fVar18;
    fVar28 = fVar28 - fVar18;
    uVar20 = ae_sel16i(uVar39,uVar39,0);
    uVar33 = (ulonglong)(uint)(fVar2 - fVar3);
    fVar2 = fVar2 + fVar3;
    uVar20 = conjc_s(uVar20);
    fVar3 = fVar1 - (float)uVar20;
    fVar1 = fVar1 + (float)uVar20;
    uVar30 = conjc_s(uVar19);
    uVar20 = ae_sel16i(uVar33,uVar33,0);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 + fVar16 * fVar12));
    *puVar32 = uVar19;
    fVar18 = fVar4 - (float)uVar30;
    uVar29 = ae_sel16i((ulonglong)(uint)fVar1,(ulonglong)(uint)fVar1,0);
    uVar20 = conjc_s(uVar20);
    uVar35 = ae_sel16i((ulonglong)(uint)fVar3,(ulonglong)(uint)fVar3,0);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 + fVar13 * fVar12));
    *puVar8 = uVar19;
    uVar29 = conjc_s(uVar29);
    uVar39 = (ulonglong)(uint)(fVar28 + (float)uVar20);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 - fVar16 * fVar12));
    *puVar11 = uVar19;
    uVar35 = conjc_s(uVar35);
    fVar16 = (float)uVar29 + fVar1;
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar15 - fVar13 * fVar12));
    puVar25[iVar23] = uVar19;
    iVar24 = ae_addbrba32(0,(0x80000000U >> (0x20U - LZCOUNT(~uVar22) & 0x1f)) << 1);
    fVar13 = (float)uVar35 - fVar3;
    uVar34 = (ulonglong)(uint)(fVar28 - (float)uVar20);
    uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar17 - fVar2));
    *(undefined8 *)((int)puVar10 + iVar24) = uVar19;
    fVar14 = fVar4 + (float)uVar30;
    uVar33 = (ulonglong)(uint)(fVar17 + fVar2);
  }
  uVar19 = ae_s32x2_x(uVar39);
  *(undefined8 *)((int)puVar9 + iVar24) = uVar19;
  uVar19 = ae_s32x2_x(uVar34);
  *(undefined8 *)((int)puVar25 + iVar24) = uVar19;
  uVar19 = ae_s32x2_x(uVar33);
  *(undefined8 *)((int)param_1 + iVar24) = uVar19;
  uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 + fVar16 * fVar12));
  *(undefined8 *)((int)puVar32 + iVar24) = uVar19;
  uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar18 + fVar13 * fVar12));
  *(undefined8 *)((int)puVar8 + iVar24) = uVar19;
  uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar14 - fVar16 * fVar12));
  *(undefined8 *)((int)puVar11 + iVar24) = uVar19;
  uVar19 = ae_s32x2_x((ulonglong)(uint)(fVar18 - fVar13 * fVar12));
  *(undefined8 *)((int)(puVar25 + iVar23) + iVar24) = uVar19;
  auVar6._4_4_ = iVar24;
  auVar6._0_4_ = puVar21;
  auVar6._8_4_ = param_1;
  auVar6._12_4_ = 0;
  return auVar6 << 0x20;
}


// ===== ifft_cplxf_ie @ 00217d10 (2329 bytes)

/* WARNING: Removing unreachable block (ram,0x00218042) */
/* WARNING: Removing unreachable block (ram,0x00217ed8) */
/* WARNING: Removing unreachable block (ram,0x00218632) */
/* NDSP fft/fft_ief: inverse complex float FFT; sqrt(0.5) constant 0x20063C (was ifft512_cplx)
   [inference] */

undefined1  [16]
ifft_cplxf_ie(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  float fVar14;
  float fVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 *puVar18;
  uint uVar19;
  int iVar20;
  undefined8 *puVar21;
  uint uVar22;
  int iVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 *puVar27;
  ulonglong uVar28;
  undefined8 uVar29;
  ulonglong uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  ulonglong uVar34;
  ulonglong uVar35;
  ulonglong uVar36;
  ulonglong uVar37;
  undefined8 uVar38;
  ulonglong uVar39;
  ulonglong uVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  ulonglong uVar43;
  undefined8 uVar44;
  int iStack_3c;
  
  uVar19 = param_5 >> 2;
  wur_ae_cbegin0(param_3);
  wur_ae_cend0(param_3 + uVar19 * param_4 * 3);
  iVar13 = param_5 >> 3;
  uVar22 = uVar19;
  if (param_5 == 0x10) {
    uVar24 = ae_l32x2_ip(param_2[4]);
    uVar16 = ae_l32x2_ip(param_2[0xc]);
    uVar17 = ae_l32x2_ip(param_2[8]);
    uVar25 = ae_l32x2_ip(*param_2);
    uVar28 = (ulonglong)(uint)((float)uVar24 - (float)uVar16);
    fVar15 = (float)uVar24 + (float)uVar16;
    fVar11 = (float)uVar25 + (float)uVar17;
    fVar3 = (float)uVar25 - (float)uVar17;
    uVar16 = ae_l32x2_ip(param_2[5]);
    uVar24 = ae_l32x2_ip(param_2[0xd]);
    uVar17 = ae_sel16i(uVar28,uVar28,0);
    uVar28 = (ulonglong)(uint)((float)uVar16 - (float)uVar24);
    uVar29 = conjc_s(uVar17);
    fVar12 = (float)uVar16 + (float)uVar24;
    uVar17 = ae_l32x2_ip(param_2[9]);
    uVar24 = ae_l32x2_ip(param_2[1]);
    uVar30 = (ulonglong)(uint)(fVar11 - fVar15);
    uVar36 = (ulonglong)(uint)(fVar3 - (float)uVar29);
    iVar13 = param_4 * 0x18 + -0x10;
    fVar2 = (float)uVar24 + (float)uVar17;
    uVar16 = ae_s32x2_ip((ulonglong)(uint)(fVar11 + fVar15));
    *param_2 = uVar16;
    uVar26 = ae_l32x2_ip(*param_3);
    uVar16 = ae_sel16i_n(uVar28,uVar28,0);
    fVar1 = (float)uVar24 - (float)uVar17;
    uVar17 = ae_l32x2_xc(param_3[2]);
    puVar18 = (undefined8 *)ae_circ0(param_3 + 2,iVar13);
    uVar25 = ae_l32x2_i(param_3[1]);
    uVar31 = conjc_s(uVar16);
    uVar37 = (ulonglong)(uint)(fVar3 + (float)uVar29);
    uVar32 = mulmux_s(uVar36,uVar26,1);
    uVar29 = mulmux_s(uVar30,uVar25,1);
    uVar16 = ae_l32x2_ip(param_2[0xe]);
    uVar33 = mulmux_s(uVar37,uVar17,1);
    uVar24 = ae_l32x2_ip(param_2[6]);
    uVar34 = (ulonglong)(uint)(fVar2 - fVar12);
    uVar38 = maddmux_s(uVar29,uVar30,uVar25,5);
    uVar25 = ae_l32x2_ip(param_2[10]);
    uVar28 = (ulonglong)(uint)((float)uVar24 - (float)uVar16);
    fVar3 = (float)uVar24 + (float)uVar16;
    uVar24 = ae_l32x2_ip(param_2[2]);
    uVar29 = ae_l32x2_ip(*puVar18);
    uVar35 = (ulonglong)(uint)(fVar1 - (float)uVar31);
    uVar32 = maddmux_s(uVar32,uVar36,uVar26,5);
    uVar16 = ae_s32x2_ip((ulonglong)(uint)(fVar2 + fVar12));
    param_2[1] = uVar16;
    fVar15 = (float)uVar24 + (float)uVar25;
    uVar33 = maddmux_s(uVar33,uVar37,uVar17,5);
    uVar16 = ae_s32x2_ip(uVar38);
    param_2[4] = uVar16;
    uVar26 = ae_l32x2_i(puVar18[1]);
    fVar11 = (float)uVar24 - (float)uVar25;
    uVar37 = (ulonglong)(uint)(fVar1 + (float)uVar31);
    uVar17 = ae_sel16i(uVar28,uVar28,0);
    uVar25 = ae_l32x2_xc(puVar18[2]);
    puVar18 = (undefined8 *)ae_circ0(puVar18 + 2,iVar13);
    uVar31 = mulmux_s(uVar34,uVar26,1);
    uVar16 = ae_s32x2_ip(uVar32);
    param_2[8] = uVar16;
    uVar24 = conjc_s(uVar17);
    uVar32 = mulmux_s(uVar35,uVar29,1);
    uVar16 = ae_s32x2_ip(uVar33);
    param_2[0xc] = uVar16;
    uVar28 = (ulonglong)(uint)(fVar15 - fVar3);
    uVar30 = (ulonglong)(uint)(fVar11 + (float)uVar24);
    uVar17 = ae_l32x2_ip(*puVar18);
    uVar36 = (ulonglong)(uint)(fVar11 - (float)uVar24);
    uVar33 = maddmux_s(uVar32,uVar35,uVar29,5);
    uVar24 = ae_l32x2_i(puVar18[1]);
    uVar29 = maddmux_s(uVar31,uVar34,uVar26,5);
    uVar38 = mulmux_s(uVar37,uVar25,1);
    uVar16 = ae_s32x2_ip((ulonglong)(uint)(fVar15 + fVar3));
    param_2[2] = uVar16;
    uVar26 = ae_l32x2_xc(puVar18[2]);
    ae_circ0(puVar18 + 2,iVar13);
    uVar16 = mulmux_s(uVar28,uVar24,1);
    uVar31 = mulmux_s(uVar30,uVar26,1);
    uVar32 = mulmux_s(uVar36,uVar17,1);
    uVar25 = maddmux_s(uVar38,uVar37,uVar25,5);
    uVar24 = maddmux_s(uVar16,uVar28,uVar24,5);
    uVar16 = ae_s32x2_ip(uVar33);
    param_2[9] = uVar16;
    uVar26 = maddmux_s(uVar31,uVar30,uVar26,5);
    uVar16 = ae_s32x2_ip(uVar29);
    param_2[5] = uVar16;
    uVar17 = maddmux_s(uVar32,uVar36,uVar17,5);
    uVar16 = ae_s32x2_ip(uVar25);
    param_2[0xd] = uVar16;
    uVar16 = ae_s32x2_ip(uVar24);
    param_2[6] = uVar16;
    uVar16 = ae_s32x2_ip(uVar26);
    param_2[0xe] = uVar16;
    uVar16 = ae_s32x2_ip(uVar17);
    param_2[10] = uVar16;
    puVar18 = param_1 + 4;
    puVar27 = param_1 + 8;
    puVar7 = param_1 + 0xc;
    uVar16 = ae_l32x2_ip(param_2[2]);
    uVar26 = ae_l32x2_ip(*param_2);
    uVar17 = ae_l32x2_ip(param_2[6]);
    uVar29 = ae_l32x2_ip(param_2[4]);
    uVar24 = ae_l32x2_ip(param_2[3]);
    uVar31 = ae_l32x2_ip(param_2[1]);
    uVar28 = (ulonglong)(uint)((float)uVar31 - (float)uVar24);
    uVar36 = (ulonglong)(uint)(((float)uVar26 - (float)uVar16) * 2.3283064e-10);
    uVar25 = ae_l32x2_ip(param_2[7]);
    uVar32 = ae_l32x2_ip(param_2[5]);
    uVar30 = (ulonglong)(uint)((float)uVar31 + (float)uVar24);
    uVar37 = (ulonglong)(uint)(((float)uVar26 + (float)uVar16) * 2.3283064e-10);
    uVar34 = (ulonglong)(uint)((float)uVar32 + (float)uVar25);
    uVar39 = (ulonglong)(uint)(((float)uVar29 + (float)uVar17) * 2.3283064e-10);
    uVar35 = (ulonglong)(uint)((float)uVar32 - (float)uVar25);
    uVar40 = (ulonglong)(uint)(((float)uVar29 - (float)uVar17) * 2.3283064e-10);
    uVar17 = ae_mov(uVar36);
    uVar16 = maddmux_s(uVar36,0x2f800000,uVar28,3);
    uVar24 = ae_mov(uVar37);
    uVar29 = maddmux_s(uVar37,0x2f800000,uVar30,2);
    uVar25 = ae_mov(uVar39);
    uVar31 = maddmux_s(uVar39,0x2f800000,uVar34,2);
    uVar26 = ae_mov(uVar40);
    uVar32 = maddmux_s(uVar40,0x2f800000,uVar35,3);
    uVar16 = ae_s32x2_x(uVar16);
    *puVar7 = uVar16;
    uVar24 = maddmux_s(uVar24,0x2f800000,uVar30,0);
    uVar16 = ae_s32x2_x(uVar29);
    *puVar27 = uVar16;
    iVar13 = ae_addbrba32(0,0x8000000);
    uVar17 = maddmux_s(uVar17,0x2f800000,uVar28,1);
    uVar16 = ae_s32x2_x(uVar31);
    *(undefined8 *)((int)puVar27 + iVar13) = uVar16;
    uVar16 = ae_s32x2_x(uVar32);
    *(undefined8 *)((int)puVar7 + iVar13) = uVar16;
    uVar16 = ae_s32x2_x(uVar24);
    *param_1 = uVar16;
    uVar16 = ae_s32x2_x(uVar17);
    *puVar18 = uVar16;
    uVar33 = maddmux_s(uVar25,0x2f800000,uVar34,0);
    uVar38 = maddmux_s(uVar26,0x2f800000,uVar35,1);
    iVar20 = ae_addbrba32(iVar13,0x8000000);
    uVar16 = ae_l32x2_ip(param_2[10]);
    uVar26 = ae_l32x2_ip(param_2[8]);
    uVar17 = ae_l32x2_ip(param_2[0xb]);
    uVar29 = ae_l32x2_ip(param_2[9]);
    uVar30 = (ulonglong)(uint)((float)uVar29 + (float)uVar17);
    uVar24 = ae_l32x2_ip(param_2[0xf]);
    uVar31 = ae_l32x2_ip(param_2[0xe]);
    uVar28 = (ulonglong)(uint)(((float)uVar26 + (float)uVar16) * 2.3283064e-10);
    uVar25 = ae_l32x2_ip(param_2[0xc]);
    uVar32 = ae_l32x2_ip(param_2[0xd]);
    uVar36 = (ulonglong)(uint)((float)uVar32 + (float)uVar24);
    uVar34 = (ulonglong)(uint)((float)uVar32 - (float)uVar24);
    uVar37 = (ulonglong)(uint)((float)uVar29 - (float)uVar17);
    uVar17 = ae_mov(uVar28);
    uVar29 = maddmux_s(uVar28,0x2f800000,uVar30,2);
    uVar35 = (ulonglong)(uint)(((float)uVar26 - (float)uVar16) * 2.3283064e-10);
    uVar28 = (ulonglong)(uint)(((float)uVar25 + (float)uVar31) * 2.3283064e-10);
    uVar24 = ae_mov(uVar35);
    uVar17 = maddmux_s(uVar17,0x2f800000,uVar30,0);
    uVar30 = (ulonglong)(uint)(((float)uVar25 - (float)uVar31) * 2.3283064e-10);
    uVar16 = ae_s32x2_x(uVar29);
    *(undefined8 *)((int)puVar27 + iVar20) = uVar16;
    uVar24 = maddmux_s(uVar24,0x2f800000,uVar37,1);
    uVar16 = ae_s32x2_x(uVar38);
    *(undefined8 *)((int)puVar18 + iVar13) = uVar16;
    uVar25 = maddmux_s(uVar35,0x2f800000,uVar37,3);
    uVar16 = ae_s32x2_x(uVar33);
    *(undefined8 *)((int)param_1 + iVar13) = uVar16;
    uVar26 = maddmux_s(uVar28,0x2f800000,uVar36,2);
    uVar29 = ae_mov(uVar28);
    uVar16 = ae_s32x2_x(uVar17);
    *(undefined8 *)((int)param_1 + iVar20) = uVar16;
    uVar17 = maddmux_s(uVar30,0x2f800000,uVar34,3);
    uVar31 = ae_mov(uVar30);
    uVar16 = ae_s32x2_x(uVar24);
    *(undefined8 *)((int)puVar18 + iVar20) = uVar16;
    uVar16 = ae_s32x2_x(uVar25);
    *(undefined8 *)((int)puVar7 + iVar20) = uVar16;
    iVar13 = ae_addbrba32(iVar20,0x8000000);
    uVar16 = ae_s32x2_x(uVar26);
    *(undefined8 *)((int)puVar27 + iVar13) = uVar16;
    uVar16 = ae_s32x2_x(uVar17);
    *(undefined8 *)((int)puVar7 + iVar13) = uVar16;
    uVar16 = maddmux_s(uVar29,0x2f800000,uVar36,0);
    uVar17 = maddmux_s(uVar31,0x2f800000,uVar34,1);
    uVar16 = ae_s32x2_x(uVar16);
    *(undefined8 *)((int)param_1 + iVar13) = uVar16;
    uVar16 = ae_s32x2_x(uVar17);
    *(undefined8 *)((int)puVar18 + iVar13) = uVar16;
    auVar4._4_4_ = param_2 + 0x13;
    auVar4._0_4_ = param_2 + 0x10;
    auVar4._8_4_ = param_2 + 0x11;
    auVar4._12_4_ = 0;
    return auVar4 << 0x20;
  }
  for (; 2 < (int)uVar22; uVar22 = (int)uVar22 >> 2) {
    iVar20 = param_4 * 0x18 + -0x10;
    iStack_3c = 0;
    puVar18 = param_2;
    do {
      puVar8 = puVar18 + uVar22;
      uVar25 = ae_l32x2_ip(*puVar18);
      puVar9 = puVar8 + uVar22;
      puVar10 = puVar9 + uVar22;
      uVar24 = ae_l32x2_ip(*puVar8);
      uVar16 = ae_l32x2_ip(*puVar10);
      uVar17 = ae_l32x2_ip(*puVar9);
      uVar28 = (ulonglong)(uint)((float)uVar24 - (float)uVar16);
      fVar15 = (float)uVar24 + (float)uVar16;
      fVar1 = (float)uVar25 + (float)uVar17;
      uVar24 = ae_l32x2_ip(puVar8[1]);
      fVar2 = (float)uVar25 - (float)uVar17;
      uVar16 = ae_l32x2_ip(puVar10[1]);
      uVar17 = ae_sel16i(uVar28,uVar28,0);
      uVar28 = (ulonglong)(uint)((float)uVar24 - (float)uVar16);
      uVar25 = ae_l32x2_ip(puVar18[1]);
      uVar26 = conjc_s(uVar17);
      uVar36 = (ulonglong)(uint)(fVar1 - fVar15);
      uVar17 = ae_l32x2_ip(puVar9[1]);
      uVar37 = (ulonglong)(uint)(fVar2 - (float)uVar26);
      fVar11 = (float)uVar24 + (float)uVar16;
      fVar12 = (float)uVar25 + (float)uVar17;
      uVar16 = ae_sel16i(uVar28,uVar28,0);
      uVar31 = ae_l32x2_ip(*param_3);
      fVar3 = (float)uVar25 - (float)uVar17;
      uVar17 = ae_l32x2_i(param_3[1]);
      uVar24 = conjc_s(uVar16);
      uVar34 = (ulonglong)(uint)(fVar2 + (float)uVar26);
      uVar16 = ae_s32x2_ip((ulonglong)(uint)(fVar1 + fVar15));
      *puVar18 = uVar16;
      puVar7 = puVar18 + 1;
      uVar26 = ae_l32x2_xc(param_3[2]);
      puVar27 = (undefined8 *)ae_circ0(param_3 + 2,iVar20);
      uVar25 = mulmux_s(uVar36,uVar17,1);
      uVar29 = mulmux_s(uVar37,uVar31,1);
      uVar35 = (ulonglong)(uint)(fVar12 + fVar11);
      uVar28 = uVar36;
      uVar30 = uVar37;
      uVar16 = uVar31;
      fVar15 = fVar3;
      if (0 < (int)(uVar22 - 2)) {
        uVar16 = ae_l32x2_ip(puVar10[2]);
        uVar33 = mulmux_s(uVar34,uVar26,1);
        uVar32 = ae_l32x2_ip(puVar8[2]);
        uVar28 = (ulonglong)(uint)(fVar12 - fVar11);
        uVar38 = maddmux_s(uVar25,uVar36,uVar17,5);
        uVar25 = ae_l32x2_ip(puVar9[2]);
        uVar36 = (ulonglong)(uint)((float)uVar32 - (float)uVar16);
        fVar11 = (float)uVar32 + (float)uVar16;
        uVar32 = ae_l32x2_ip(puVar18[2]);
        uVar16 = ae_l32x2_ip(*puVar27);
        uVar30 = (ulonglong)(uint)(fVar3 - (float)uVar24);
        uVar31 = maddmux_s(uVar29,uVar37,uVar31,5);
        uVar17 = ae_s32x2_ip(uVar35);
        *puVar7 = uVar17;
        puVar7 = puVar18 + 2;
        fVar12 = (float)uVar32 + (float)uVar25;
        uVar33 = maddmux_s(uVar33,uVar34,uVar26,5);
        uVar17 = ae_s32x2_ip(uVar38);
        *puVar8 = uVar17;
        puVar8 = puVar8 + 1;
        uVar17 = ae_l32x2_i(puVar27[1]);
        fVar15 = (float)uVar32 - (float)uVar25;
        uVar34 = (ulonglong)(uint)(fVar3 + (float)uVar24);
        uVar29 = ae_sel16i(uVar36,uVar36,0);
        uVar26 = ae_l32x2_xc(puVar27[2]);
        puVar27 = (undefined8 *)ae_circ0(puVar27 + 2,iVar20);
        uVar25 = mulmux_s(uVar28,uVar17,1);
        uVar24 = ae_s32x2_ip(uVar31);
        *puVar9 = uVar24;
        puVar9 = puVar9 + 1;
        uVar24 = conjc_s(uVar29);
        uVar29 = mulmux_s(uVar30,uVar16,1);
        uVar31 = ae_s32x2_ip(uVar33);
        *puVar10 = uVar31;
        puVar10 = puVar10 + 1;
        uVar35 = (ulonglong)(uint)(fVar12 + fVar11);
      }
      uVar31 = ae_mov((ulonglong)(uint)fVar11);
      uVar24 = ae_mov(uVar24);
      uVar36 = (ulonglong)(uint)(fVar12 - (float)uVar31);
      uVar41 = ae_mov(uVar28);
      uVar31 = ae_mov((ulonglong)(uint)fVar15);
      uVar33 = ae_l32x2_ip(*puVar27);
      uVar28 = (ulonglong)(uint)(fVar15 - (float)uVar24);
      uVar42 = ae_mov(uVar16);
      uVar32 = ae_mov(uVar34);
      uVar16 = ae_l32x2_i(puVar27[1]);
      uVar38 = mulmux_s(uVar34,uVar26,1);
      uVar34 = (ulonglong)(uint)((float)uVar31 + (float)uVar24);
      uVar31 = mulmux_s(uVar36,uVar16,1);
      uVar29 = maddmux_s(uVar29,uVar30,uVar42,5);
      uVar42 = mulmux_s(uVar28,uVar33,1);
      uVar24 = ae_l32x2_xc(puVar27[2]);
      param_3 = (undefined8 *)ae_circ0(puVar27 + 2,iVar20);
      uVar17 = maddmux_s(uVar25,uVar41,uVar17,5);
      uVar25 = mulmux_s(uVar34,uVar24,1);
      uVar41 = maddmux_s(uVar31,uVar36,uVar16,5);
      uVar16 = ae_s32x2_ip(uVar35);
      *puVar7 = uVar16;
      uVar31 = maddmux_s(uVar42,uVar28,uVar33,5);
      uVar16 = ae_s32x2_ip(uVar17);
      *puVar8 = uVar16;
      uVar17 = maddmux_s(uVar38,uVar32,uVar26,5);
      uVar16 = ae_s32x2_ip(uVar41);
      puVar8[1] = uVar16;
      uVar24 = maddmux_s(uVar25,uVar34,uVar24,5);
      uVar16 = ae_s32x2_ip(uVar29);
      *puVar9 = uVar16;
      uVar16 = ae_s32x2_ip(uVar31);
      puVar9[1] = uVar16;
      uVar16 = ae_s32x2_ip(uVar17);
      *puVar10 = uVar16;
      uVar16 = ae_s32x2_ip(uVar24);
      puVar10[1] = uVar16;
      puVar18 = puVar10 + 2;
      iStack_3c = iStack_3c + uVar22;
    } while (iStack_3c < (int)uVar19);
    param_4 = param_4 << 2;
  }
  if ((int)uVar22 < 2) {
    fVar15 = (float)((LZCOUNT(~uVar19) + 0x5f) * 0x800000);
    uVar35 = (ulonglong)(uint)fVar15;
    uVar16 = ae_l32x2_ip(*param_2);
    uVar25 = ae_l32x2_ip(param_2[2]);
    uVar17 = ae_l32x2_ip(param_2[3]);
    uVar26 = ae_l32x2_ip(param_2[1]);
    uVar24 = ae_l32x2_ip(param_2[4]);
    puVar18 = param_2 + 8;
    uVar29 = ae_l32x2_ip(param_2[6]);
    uVar36 = (ulonglong)(uint)((float)uVar26 + (float)uVar17);
    uVar40 = (ulonglong)(uint)(((float)uVar16 + (float)uVar25) * fVar15);
    uVar37 = (ulonglong)(uint)((float)uVar26 - (float)uVar17);
    puVar7 = param_1 + uVar19;
    iVar20 = 0;
    uVar17 = ae_l32x2_ip(param_2[7]);
    uVar26 = ae_l32x2_ip(param_2[5]);
    puVar27 = param_2 + 9;
    uVar39 = (ulonglong)(uint)(((float)uVar16 - (float)uVar25) * fVar15);
    puVar9 = puVar7 + uVar19;
    uVar28 = (ulonglong)(uint)((float)uVar26 + (float)uVar17);
    uVar43 = (ulonglong)(uint)(((float)uVar24 + (float)uVar29) * fVar15);
    puVar8 = puVar9 + uVar19;
    uVar30 = (ulonglong)(uint)((float)uVar26 - (float)uVar17);
    uVar34 = (ulonglong)(uint)(((float)uVar24 - (float)uVar29) * fVar15);
    uVar16 = maddmux_s(uVar40,uVar35,uVar36,2);
    uVar17 = ae_mov(uVar40);
    uVar25 = ae_mov(uVar39);
    uVar22 = 0x80000000 >> (0x20U - LZCOUNT(~uVar19) & 0x1f);
    uVar17 = maddmux_s(uVar17,uVar35,uVar36,0);
    uVar24 = maddmux_s(uVar39,uVar35,uVar37,3);
    uVar26 = ae_mov(uVar43);
    iVar23 = ae_addbrba32(0,uVar22);
    uVar29 = maddmux_s(uVar43,uVar35,uVar28,2);
    uVar25 = maddmux_s(uVar25,uVar35,uVar37,1);
    uVar31 = ae_mov(uVar34);
    if (0 < iVar13 + -1) {
      uVar32 = ae_l32x2_ip(param_2[10]);
      uVar33 = ae_l32x2_ip(*puVar18);
      uVar42 = maddmux_s(uVar34,uVar35,uVar30,3);
      uVar44 = maddmux_s(uVar26,uVar35,uVar28,0);
      uVar26 = ae_l32x2_ip(param_2[0xb]);
      uVar38 = ae_l32x2_ip(*puVar27);
      uVar16 = ae_s32x2_x(uVar16);
      *puVar9 = uVar16;
      uVar41 = ae_l32x2_ip(param_2[0xe]);
      uVar36 = (ulonglong)(uint)((float)uVar38 + (float)uVar26);
      uVar40 = (ulonglong)(uint)((float)uVar38 - (float)uVar26);
      uVar16 = ae_s32x2_x(uVar17);
      *param_1 = uVar16;
      uVar17 = ae_l32x2_ip(param_2[0xc]);
      puVar18 = param_2 + 0x10;
      uVar31 = maddmux_s(uVar31,uVar35,uVar30,1);
      uVar16 = ae_s32x2_x(uVar44);
      *(undefined8 *)((int)param_1 + iVar23) = uVar16;
      uVar26 = ae_l32x2_ip(param_2[0xf]);
      uVar16 = ae_s32x2_x(uVar29);
      *(undefined8 *)((int)puVar9 + iVar23) = uVar16;
      uVar29 = ae_l32x2_ip(param_2[0xd]);
      puVar27 = param_2 + 0x11;
      uVar30 = (ulonglong)(uint)(((float)uVar33 + (float)uVar32) * fVar15);
      uVar16 = ae_s32x2_x(uVar24);
      *puVar8 = uVar16;
      uVar37 = (ulonglong)(uint)(((float)uVar33 - (float)uVar32) * fVar15);
      uVar28 = (ulonglong)(uint)((float)uVar29 + (float)uVar26);
      uVar16 = ae_s32x2_x(uVar25);
      *puVar7 = uVar16;
      iVar20 = ae_addbrba32(iVar23,uVar22);
      uVar16 = ae_s32x2_x(uVar42);
      *(undefined8 *)((int)puVar8 + iVar23) = uVar16;
      uVar39 = (ulonglong)(uint)(((float)uVar17 + (float)uVar41) * fVar15);
      uVar34 = (ulonglong)(uint)(((float)uVar17 - (float)uVar41) * fVar15);
      uVar17 = ae_mov(uVar30);
      uVar16 = maddmux_s(uVar30,uVar35,uVar36,2);
      uVar30 = (ulonglong)(uint)((float)uVar29 - (float)uVar26);
      uVar26 = ae_mov(uVar37);
      uVar24 = maddmux_s(uVar37,uVar35,uVar40,3);
      uVar17 = maddmux_s(uVar17,uVar35,uVar36,0);
      uVar25 = ae_s32x2_x(uVar31);
      *(undefined8 *)((int)puVar7 + iVar23) = uVar25;
      iVar23 = ae_addbrba32(iVar20,uVar22);
      uVar25 = maddmux_s(uVar26,uVar35,uVar40,1);
      uVar26 = ae_mov(uVar39);
      uVar31 = ae_mov(uVar34);
      uVar29 = maddmux_s(uVar39,uVar35,uVar28,2);
    }
    uVar25 = ae_s32x2_x(uVar25);
    *(undefined8 *)((int)puVar7 + iVar20) = uVar25;
    uVar17 = ae_s32x2_x(uVar17);
    *(undefined8 *)((int)param_1 + iVar20) = uVar17;
    uVar25 = maddmux_s(uVar34,uVar35,uVar30,3);
    uVar17 = ae_s32x2_x(uVar24);
    *(undefined8 *)((int)puVar8 + iVar20) = uVar17;
    uVar17 = maddmux_s(uVar26,uVar35,uVar28,0);
    uVar16 = ae_s32x2_x(uVar16);
    *(undefined8 *)((int)puVar9 + iVar20) = uVar16;
    uVar24 = maddmux_s(uVar31,uVar35,uVar30,1);
    uVar16 = ae_s32x2_x(uVar29);
    *(undefined8 *)((int)puVar9 + iVar23) = uVar16;
    uVar16 = ae_s32x2_x(uVar25);
    *(undefined8 *)((int)puVar8 + iVar23) = uVar16;
    uVar16 = ae_s32x2_x(uVar17);
    *(undefined8 *)((int)param_1 + iVar23) = uVar16;
    uVar16 = ae_s32x2_x(uVar24);
    *(undefined8 *)((int)puVar7 + iVar23) = uVar16;
    auVar6._0_8_ = ZEXT48(puVar18) << 0x20;
    auVar6._8_4_ = 0x80000000;
    auVar6._12_4_ = puVar27;
    return auVar6;
  }
  uVar16 = ae_l32x2_ip(*param_2);
  uVar17 = ae_l32x2_i(param_2[1]);
  uVar24 = ae_l32x2_i(param_2[2]);
  uVar29 = ae_l32x2_ip(param_2[4]);
  uVar25 = ae_l32x2_i(param_2[6]);
  fVar14 = (float)((LZCOUNT(~uVar19) + 0x5f) * 0x800000);
  uVar31 = ae_l32x2_i(param_2[5]);
  fVar15 = (float)uVar16 + (float)uVar29;
  fVar1 = (float)uVar24 + (float)uVar25;
  uVar37 = (ulonglong)(uint)fVar14;
  uVar26 = ae_l32x2_ip(param_2[3]);
  uVar32 = ae_l32x2_ip(param_2[7]);
  puVar18 = param_2 + 0xc;
  fVar11 = (float)uVar17 + (float)uVar31;
  fVar2 = (float)uVar26 + (float)uVar32;
  fVar12 = (float)uVar16 - (float)uVar29;
  fVar3 = (float)uVar17 - (float)uVar31;
  puVar27 = param_1 + iVar13;
  uVar16 = conjc_s((ulonglong)(uint)((float)uVar24 - (float)uVar25));
  uVar25 = ae_sel16i(uVar16,uVar16,0);
  uVar16 = conjc_s((ulonglong)(uint)((float)uVar26 - (float)uVar32));
  uVar36 = (ulonglong)(uint)(fVar11 + fVar2);
  uVar16 = ae_sel16i(uVar16,uVar16,0);
  puVar9 = puVar27 + iVar13;
  uVar35 = (ulonglong)(uint)((fVar15 + fVar1) * fVar14);
  puVar7 = puVar9 + iVar13;
  uVar17 = ae_l32_i(0x3f3504f3);
  uVar28 = (ulonglong)(uint)(fVar11 - fVar2);
  fVar11 = fVar3 + (float)uVar16;
  puVar10 = puVar7 + iVar13;
  uVar39 = (ulonglong)(uint)((float)uVar17 * fVar14);
  puVar8 = puVar10 + iVar13;
  fVar3 = fVar3 - (float)uVar16;
  uVar30 = (ulonglong)(uint)fVar3;
  uVar34 = (ulonglong)(uint)((fVar15 - fVar1) * fVar14);
  iVar20 = 0;
  uVar24 = ae_mov(uVar35);
  puVar21 = puVar8 + iVar13;
  uVar17 = maddmux_s(uVar35,uVar37,uVar36,2);
  uVar35 = (ulonglong)(uint)((fVar12 - (float)uVar25) * fVar14);
  uVar16 = conjc_s((ulonglong)(uint)fVar11);
  uVar24 = maddmux_s(uVar24,uVar37,uVar36,0);
  uVar36 = (ulonglong)(uint)((fVar12 + (float)uVar25) * fVar14);
  if (0 < iVar13 + -1) {
    uVar25 = ae_mov(uVar34);
    uVar29 = ae_l32x2_ip(param_2[8]);
    uVar26 = conjc_s(uVar30);
    uVar32 = ae_sel16i(uVar16,uVar16,0);
    uVar16 = ae_sel16i(uVar26,uVar26,0);
    uVar31 = ae_l32x2_ip(*puVar18);
    uVar30 = (ulonglong)(uint)((float)uVar32 + fVar11);
    uVar33 = maddmux_s(uVar34,uVar37,uVar28,3);
    uVar26 = ae_mov(uVar36);
    uVar32 = ae_l32x2_i(param_2[10]);
    fVar15 = (float)uVar29 + (float)uVar31;
    fVar2 = (float)uVar29 - (float)uVar31;
    uVar29 = ae_mov(uVar35);
    uVar31 = ae_l32x2_i(param_2[0xe]);
    uVar34 = (ulonglong)(uint)((float)uVar16 - fVar3);
    uVar38 = maddmux_s(uVar25,uVar37,uVar28,1);
    uVar16 = ae_s32x2_x(uVar17);
    *puVar10 = uVar16;
    uVar17 = ae_l32x2_i(param_2[0xd]);
    fVar12 = (float)uVar32 + (float)uVar31;
    uVar16 = ae_s32x2_x(uVar33);
    *puVar21 = uVar16;
    uVar25 = ae_l32x2_i(param_2[9]);
    uVar26 = maddmux_s(uVar26,uVar39,uVar30,0);
    uVar33 = maddmux_s(uVar36,uVar39,uVar30,2);
    uVar16 = ae_s32x2_x(uVar24);
    *param_1 = uVar16;
    uVar24 = ae_l32x2_ip(param_2[0xf]);
    puVar18 = param_2 + 0x14;
    fVar3 = (float)uVar25 - (float)uVar17;
    fVar11 = (float)uVar25 + (float)uVar17;
    uVar16 = ae_s32x2_x(uVar38);
    *puVar9 = uVar16;
    uVar17 = ae_l32x2_ip(param_2[0xb]);
    uVar25 = maddmux_s(uVar29,uVar39,uVar34,0);
    uVar29 = maddmux_s(uVar35,uVar39,uVar34,2);
    uVar16 = ae_s32x2_x(uVar26);
    *puVar27 = uVar16;
    uVar26 = conjc_s((ulonglong)(uint)((float)uVar32 - (float)uVar31));
    fVar1 = (float)uVar17 + (float)uVar24;
    uVar16 = ae_s32x2_x(uVar33);
    *puVar8 = uVar16;
    uVar26 = ae_sel16i(uVar26,uVar26,0);
    uVar16 = ae_s32x2_x(uVar25);
    *puVar7 = uVar16;
    uVar16 = ae_s32x2_x(uVar29);
    puVar21[iVar13] = uVar16;
    iVar20 = ae_addbrba32(0,(0x80000000U >> (0x20U - LZCOUNT(~uVar19) & 0x1f)) << 1);
    uVar16 = conjc_s((ulonglong)(uint)((float)uVar17 - (float)uVar24));
    uVar43 = (ulonglong)(uint)((fVar15 + fVar12) * fVar14);
    uVar16 = ae_sel16i(uVar16,uVar16,0);
    uVar40 = (ulonglong)(uint)(fVar11 + fVar1);
    uVar28 = (ulonglong)(uint)(fVar11 - fVar1);
    fVar11 = fVar3 + (float)uVar16;
    uVar30 = (ulonglong)(uint)(fVar3 - (float)uVar16);
    uVar34 = (ulonglong)(uint)((fVar15 - fVar12) * fVar14);
    uVar35 = (ulonglong)(uint)((fVar2 - (float)uVar26) * fVar14);
    uVar16 = ae_mov(uVar43);
    uVar36 = (ulonglong)(uint)((fVar2 + (float)uVar26) * fVar14);
    uVar17 = maddmux_s(uVar43,uVar37,uVar40,2);
    uVar24 = maddmux_s(uVar16,uVar37,uVar40,0);
    uVar16 = conjc_s((ulonglong)(uint)fVar11);
  }
  uVar16 = ae_sel16i(uVar16,uVar16,0);
  uVar25 = conjc_s(uVar30);
  uVar40 = (ulonglong)(uint)((float)uVar16 + fVar11);
  uVar16 = ae_sel16i(uVar25,uVar25,0);
  uVar25 = ae_mov(uVar34);
  uVar29 = maddmux_s(uVar34,uVar37,uVar28,1);
  uVar30 = (ulonglong)(uint)((float)uVar16 - (float)uVar30);
  uVar26 = ae_mov(uVar36);
  uVar25 = maddmux_s(uVar25,uVar37,uVar28,3);
  uVar16 = ae_s32x2_x(uVar17);
  *(undefined8 *)((int)puVar10 + iVar20) = uVar16;
  uVar17 = maddmux_s(uVar26,uVar39,uVar40,0);
  uVar16 = ae_s32x2_x(uVar24);
  *(undefined8 *)((int)param_1 + iVar20) = uVar16;
  uVar24 = ae_mov(uVar35);
  uVar26 = maddmux_s(uVar36,uVar39,uVar40,2);
  uVar16 = ae_s32x2_x(uVar29);
  *(undefined8 *)((int)puVar9 + iVar20) = uVar16;
  uVar24 = maddmux_s(uVar24,uVar39,uVar30,0);
  uVar16 = ae_s32x2_x(uVar25);
  *(undefined8 *)((int)puVar21 + iVar20) = uVar16;
  uVar25 = maddmux_s(uVar35,uVar39,uVar30,2);
  uVar16 = ae_s32x2_x(uVar17);
  *(undefined8 *)((int)puVar27 + iVar20) = uVar16;
  uVar16 = ae_s32x2_x(uVar26);
  *(undefined8 *)((int)puVar8 + iVar20) = uVar16;
  uVar16 = ae_s32x2_x(uVar24);
  *(undefined8 *)((int)puVar7 + iVar20) = uVar16;
  uVar16 = ae_s32x2_x(uVar25);
  *(undefined8 *)((int)(puVar21 + iVar13) + iVar20) = uVar16;
  auVar5._4_4_ = iVar20;
  auVar5._0_4_ = puVar18;
  auVar5._8_4_ = param_1;
  auVar5._12_4_ = 0;
  return auVar5 << 0x20;
}


// ===== FUN_00218480 @ 00218480 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00218480(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== fft_spectrumf @ 00218640 (1314 bytes)

/* WARNING: Removing unreachable block (ram,0x00218738) */
/* WARNING: Removing unreachable block (ram,0x0021880c) */
/* WARNING: Removing unreachable block (ram,0x002188d0) */
/* WARNING: Removing unreachable block (ram,0x00218986) */
/* WARNING: Removing unreachable block (ram,0x002189a6) */
/* NDSP fft/fft_spectrum: (y, x, N, mode): returns at once unless N is a power of 2 and mode is 0
   (power) or 1 (magnitude, sqrt0.s) [fact for the checks] */

void fft_spectrumf(int param_1,int param_2,uint param_3,int param_4)

{
  float fVar1;
  int iVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  float fVar26;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 uStack_28;
  
  if (((1 < (int)param_3) && ((param_3 & param_3 - 1) == 0)) && ((param_4 == 0 || (param_4 == 1))))
  {
    uVar12 = param_3 + 1;
    if (-1 < (int)param_3) {
      uVar12 = param_3;
    }
    uVar6 = ae_movda32((param_4 + LZCOUNT(~param_3) + 0x61) * 0x800000);
    uVar12 = ((int)uVar12 >> 1) + 1;
    uStack_28 = ae_s32x2_i(uVar6);
    if (0 < (int)uVar12) {
      uVar6 = ae_zalign64();
      uVar17 = ae_movi(0);
      do {
        uVar7 = ae_movalign(uVar6);
        uVar13 = (uint)((uVar12 & 1) != 0);
        uVar8 = ae_la64_pp(param_2);
        iVar2 = param_1;
        uVar10 = uVar7;
        if ((uVar13 != 0) && (uVar13 + 1 >> 1 != 0)) {
          uVar10 = ae_la32x2_ip(uVar8,param_2);
          uVar9 = ae_la32x2_ip_1(uVar8,param_2);
          uVar11 = ae_la32x2_ip_2(uVar8,param_2);
          uVar8 = ae_la32x2_ip(uVar9,uVar11);
          ae_la32x2_ip_1(uVar9,uVar11);
          ae_la32x2_ip_2(uVar9,uVar11);
          uVar9 = ae_sel16i(uVar10,uVar8,1);
          uVar14 = ae_movda32(0xff);
          uVar18 = ae_sel16i_n(uVar10,uVar8,3);
          uVar10 = ae_srli32(uVar18,0x17);
          uVar8 = ae_srli32(uVar9,0x17);
          uVar8 = ae_and(uVar8,uVar14);
          uVar15 = ae_movda32(0x7f);
          uVar10 = ae_and(uVar10,uVar14);
          uVar10 = ae_sub32(uVar10,uVar15);
          uVar8 = ae_sub32(uVar8,uVar15);
          uVar10 = ae_max32(uVar8,uVar10);
          uVar3 = ae_lt32(uVar15,uVar10);
          uVar8 = ae_movt32x2(uVar10,uVar15,uVar3);
          uVar10 = ae_sub32(uVar15,uVar8);
          uVar3 = ae_eq32(uVar10,uVar17);
          uVar14 = ae_movda32(&DAT_00400000);
          uVar10 = ae_slai32(uVar10,0x17);
          uVar10 = ae_movt32x2(uVar10,uVar14,uVar3);
          fVar1 = (float)uVar9 * (float)uVar10;
          fVar26 = (float)uVar18 * (float)uVar10;
          uVar10 = ae_sa32x2_ip(uVar8,uVar7,param_1);
          iVar2 = ae_sa32x2_ip_1(uVar8,uVar7,param_1);
          local_230 = ae_s32x2_ip((ulonglong)(uint)(fVar1 * fVar1 + fVar26 * fVar26));
        }
        ae_sa64pos_fp(uVar10,iVar2);
        uVar10 = ae_movalign(uVar6);
        uVar7 = ae_la64_pp(param_1);
        iVar2 = param_1;
        if (uVar13 != 0) {
          uVar14 = ae_l32x2_ip(local_230);
          uVar15 = sqrt0_s(uVar14);
          uVar8 = const_s(0);
          uVar9 = maddn_s(uVar8,uVar15,uVar15);
          uVar18 = nexp01_s(uVar14);
          uVar8 = const_s(3);
          uVar18 = addexp_s(uVar18,uVar8);
          uVar8 = maddn_s(uVar8,uVar9,uVar18);
          uVar5 = maddn_s(uVar15,uVar8,uVar15);
          uVar8 = const_s(0);
          uVar9 = ae_mov(uVar8);
          uVar15 = ae_mov(uVar9);
          uVar19 = const_s(3);
          uVar15 = maddn_s(uVar15,uVar5,uVar18);
          uVar20 = nexp01_s(uVar14);
          uVar21 = nexp01_s(uVar14);
          uVar22 = maddn_s(uVar9,uVar19,uVar5);
          uVar18 = msubn_s(uVar8,uVar20,uVar5);
          uVar8 = ae_la32x2_ip(uVar7,param_1);
          uVar9 = ae_la32x2_ip_1(uVar7,param_1);
          uVar11 = ae_la32x2_ip_2(uVar7,param_1);
          uVar15 = maddn_s(uVar19,uVar15,uVar5);
          uVar19 = ae_movda32(0x7f);
          uVar5 = ae_l32x2_i(uStack_28);
          uVar14 = mksadj_s(uVar14);
          uVar7 = ae_add32(uVar19,uVar8);
          uVar3 = ae_eq32(uVar7,uVar17);
          uVar16 = ae_movda32(&DAT_00400000);
          uVar8 = maddn_s(uVar20,uVar18,uVar18);
          uVar7 = ae_slai32(uVar7,0x17);
          uStack_28 = ae_s32x2_i(uVar5);
          uVar23 = (ulonglong)(uint)-(float)uVar22;
          uVar7 = ae_movt32x2(uVar7,uVar16,uVar3);
          fVar26 = (float)uVar7;
          uVar7 = uVar10;
          if (0 < ((int)(uVar13 + 1) >> 1) + -1) {
            uVar20 = ae_l32x2_ip(uStack_228);
            uVar24 = const_s(0);
            uVar7 = ae_la32x2_ip(uVar9,uVar11);
            ae_la32x2_ip_1(uVar9,uVar11);
            ae_la32x2_ip_2(uVar9,uVar11);
            uVar25 = sqrt0_s(uVar20);
            uVar9 = maddn_s(uVar18,uVar8,uVar23);
            uVar18 = ae_add32(uVar19,uVar7);
            uVar22 = maddn_s(uVar22,uVar15,uVar22);
            uVar3 = ae_eq32(uVar18,uVar17);
            uVar19 = nexp01_s(uVar20);
            uVar7 = maddn_s(uVar24,uVar25,uVar25);
            uVar8 = const_s(3);
            uVar24 = nexp01_s(uVar20);
            uVar15 = maddn_s(uVar21,uVar9,uVar9);
            uVar19 = addexp_s(uVar19,uVar8);
            uVar7 = maddn_s(uVar8,uVar7,uVar19);
            uVar8 = addexpm_s(uVar9,uVar14);
            uVar9 = addexp_s((ulonglong)(uint)-(float)uVar22,uVar14);
            uVar8 = divn_s(uVar8,uVar15,uVar9);
            uVar7 = maddn_s(uVar25,uVar7,uVar25);
            uVar21 = nexp01_s(uVar20);
            uVar14 = mksadj_s(uVar20);
            uVar9 = ae_slai32(uVar18,0x17);
            uVar15 = const_s(0);
            fVar1 = (float)uVar8 * fVar26;
            uVar8 = ae_mov(uVar15);
            uVar20 = const_s(3);
            uVar18 = msubn_s(uVar15,uVar24,uVar7);
            uVar15 = ae_mov(uVar8);
            uVar22 = maddn_s(uVar8,uVar20,uVar7);
            uVar8 = ae_movt32x2(uVar9,uVar16,uVar3);
            fVar26 = (float)uVar8;
            uVar9 = maddn_s(uVar15,uVar7,uVar19);
            uVar4 = (ulonglong)(uint)(fVar1 * (float)uVar5);
            uVar8 = maddn_s(uVar24,uVar18,uVar18);
            uVar23 = (ulonglong)(uint)-(float)uVar22;
            uVar15 = maddn_s(uVar20,uVar9,uVar7);
            uVar7 = ae_sa32x2_ip(uVar4,uVar10,param_1);
            iVar2 = ae_sa32x2_ip_1(uVar4,uVar10,param_1);
          }
          uVar10 = maddn_s(uVar18,uVar8,uVar23);
          uVar8 = maddn_s(uVar22,uVar15,uVar22);
          uVar9 = maddn_s(uVar21,uVar10,uVar10);
          uVar8 = addexp_s((ulonglong)(uint)-(float)uVar8,uVar14);
          uVar10 = addexpm_s(uVar10,uVar14);
          uVar10 = divn_s(uVar10,uVar9,uVar8);
          uVar23 = (ulonglong)(uint)((float)uVar10 * fVar26 * (float)uVar5);
          uVar10 = ae_sa32x2_ip(uVar23,uVar7,iVar2);
          iVar2 = ae_sa32x2_ip_1(uVar23,uVar7,iVar2);
        }
        param_1 = uVar13 * 4 + param_1;
        ae_sa64pos_fp(uVar10,iVar2);
        uVar12 = uVar12 - uVar13;
        param_2 = uVar13 * 8 + param_2;
      } while (0 < (int)uVar12);
    }
  }
  return;
}


// ===== scl_antilog10f @ 00218b70 (375 bytes)

/* NDSP mathf: alog10fminmax 0x2006C8 and expftbl_Q30 0x200720 (was pow10f_) [fact for the tables]
    */

void scl_antilog10f(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined8 in_aed0;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 in_st_AE_OVERFLOW;
  undefined1 uVar8;
  byte bVar9;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar10;
  
  uVar2 = un_s(in_aed0,in_aed0);
  if (SUB21(uVar2,0)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x21;
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar7 = ae_l32_i(0xc23369f4);
  uVar11 = ae_l32_i(0x421a209b);
  uVar7 = max_s(uVar7,in_aed0);
  uVar7 = min_s(uVar11,uVar7);
  uVar19 = ae_movvfcrfsr();
  uVar11 = trunc_sx2(uVar7,0x19);
  uVar7 = ae_l32_i(0x6a4d3c26);
  uVar14 = ae_mul32_hh(uVar11,uVar7);
  uVar11 = ae_slai64(uVar14,10);
  uVar7 = ae_trunci32x2f64s(uVar11,uVar11,0,in_st_AE_OVERFLOW);
  uVar8 = ae_trunci32x2f64s_1(uVar11,uVar11,0,in_st_AE_OVERFLOW);
  uVar12 = ae_srli32(uVar7,1);
  uVar15 = ae_movda32(0xfe);
  uVar13 = ae_l32_i(0x9eb2d1);
  uVar16 = ae_l32_i(&DAT_0014498f);
  uVar18 = ae_mulfp32x2ras(uVar12,uVar12,uVar8);
  uVar8 = ae_mulfp32x2ras_1(uVar12,uVar12,uVar8);
  uVar7 = ae_trunca32x2f64s(uVar14,uVar14,0xffffffea,uVar8);
  uVar8 = ae_trunca32x2f64s_1(uVar14,uVar14,0xffffffea,uVar8);
  uVar17 = ae_l32_i(&DAT_00039559);
  uVar11 = ae_mulafp32x2ras(uVar13,uVar12,uVar16,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar13,uVar12,uVar16,uVar8);
  uVar14 = ae_l32_i(0xf5ff241);
  uVar16 = ae_l32_i(0x38cf76b);
  uVar13 = ae_mulafp32x2ras(uVar11,uVar18,uVar17,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar11,uVar18,uVar17,uVar8);
  uVar17 = ae_add32(uVar7,uVar15);
  uVar15 = ae_srai32(uVar17,1);
  uVar7 = ae_mulafp32x2ras(uVar14,uVar12,uVar16,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar14,uVar12,uVar16,uVar8);
  uVar14 = ae_l32_i(&RSTCTL0_SYSRSTSTAT);
  uVar16 = ae_l32_i(0x2c5c849b);
  uVar11 = ae_mulafp32x2ras(uVar7,uVar18,uVar13,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar7,uVar18,uVar13,uVar8);
  uVar13 = ae_sub32(uVar17,uVar15);
  uVar15 = ae_slai32(uVar15,0x17);
  uVar7 = ae_mulafp32x2ras(uVar14,uVar12,uVar16,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar14,uVar12,uVar16,uVar8);
  uVar12 = ae_slai32(uVar13,0x17);
  uVar13 = ae_mulafp32x2ras(uVar7,uVar18,uVar11,uVar8);
  ae_mulafp32x2ras_1(uVar7,uVar18,uVar11,uVar8);
  uVar7 = float_sx2(uVar13,0x1e);
  uVar6 = (ulonglong)(uint)((float)uVar12 * (float)uVar15 * (float)uVar7);
  uVar7 = ae_l32_i(0x7f800000);
  ae_movfcrfsrv(uVar19);
  uVar5 = olt_s(in_aed0,uVar7);
  uVar4 = oeq_s(uVar6,uVar7);
  bVar3 = (byte)uVar4;
  ae_sel16i_n(uVar6,uVar6,1);
  if (!(bool)((byte)uVar5 & bVar3)) {
    return;
  }
  uVar11 = const_s(1);
  bVar9 = (byte)((ushort)uVar2 >> 8);
  bVar9 = bVar9 & (bVar9 ^ 1);
  uVar10 = (undefined4)CONCAT71((int7)((ulonglong)uVar7 >> 8),bVar9);
  uVar7 = ae_mov(uVar11);
  uVar13 = movt_s(uVar7,(ulonglong)(uint)-(float)uVar11,bVar9);
  uVar7 = ae_s32x2_i(uVar6);
  rsqrt0_s(uVar13);
  if (bVar9 != 0) {
    uVar10 = 0x7f7f7f7f;
  }
  uVar13 = const_s(0);
  uVar12 = ae_mov(uVar11);
  uVar13 = movt_s(uVar12,uVar13,bVar9);
  uVar18 = ae_movi(1);
  uVar14 = ae_mov(uVar12);
  uVar12 = ae_movda32(0x7f7f7f7f);
  uVar18 = ae_sel16i_n(uVar18,uVar18,3);
  movt_s(uVar14,uVar18,bVar9);
  uVar18 = ae_sel16i_n(uVar12,uVar12,3);
  movt_s(uVar11,uVar18,bVar3 | bVar3 ^ 1);
  recip0_s(uVar13);
  float_s(uVar10,0);
  puVar1 = (undefined4 *)__errno(0x7f7f7f7f);
  uVar7 = ae_l32x2_i(uVar7);
  *puVar1 = 0x22;
  ae_sel16i(uVar7,uVar7,1);
  return;
}


// ===== scl_antilognf @ 00218cf0 (355 bytes)

/* NDSP mathf: expftbl_Q30 0x200720, no alog10f table; used by soft_knee_compressor /
   soft_knee_limiter [inference] */

void scl_antilognf(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined8 in_aed0;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 in_st_AE_OVERFLOW;
  undefined1 uVar8;
  byte bVar9;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined4 uVar10;
  
  uVar2 = un_s(in_aed0,in_aed0);
  uVar11 = ae_movda32(0xfe);
  uVar15 = ae_movvfcrfsr();
  if (SUB21(uVar2,0)) {
    puVar1 = (undefined4 *)__errno();
    *puVar1 = 0x21;
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar12 = trunc_sx2(in_aed0,0x18);
  uVar7 = ae_l32_i(0x5c551d95);
  uVar13 = ae_mul32_hh(uVar12,uVar7);
  uVar12 = ae_slai64(uVar13,10);
  uVar7 = ae_trunci32x2f64s(uVar12,uVar12,0,in_st_AE_OVERFLOW);
  uVar8 = ae_trunci32x2f64s_1(uVar12,uVar12,0,in_st_AE_OVERFLOW);
  uVar12 = ae_l32_i(&DAT_00039559);
  uVar14 = ae_l32_i(&DAT_0014498f);
  uVar16 = ae_srli32(uVar7,1);
  uVar7 = ae_mulafp32x2ras(uVar14,uVar16,uVar12,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar14,uVar16,uVar12,uVar8);
  uVar14 = ae_l32_i(0x9eb2d1);
  uVar12 = ae_mulafp32x2ras(uVar14,uVar16,uVar7,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar14,uVar16,uVar7,uVar8);
  uVar7 = ae_l32_i(0x38cf76b);
  uVar14 = ae_mulafp32x2ras(uVar7,uVar16,uVar12,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar7,uVar16,uVar12,uVar8);
  uVar7 = ae_trunca32x2f64s(uVar13,uVar13,0xffffffea,uVar8);
  uVar8 = ae_trunca32x2f64s_1(uVar13,uVar13,0xffffffea,uVar8);
  uVar12 = ae_l32_i(0xf5ff241);
  uVar11 = ae_add32(uVar7,uVar11);
  uVar7 = ae_mulafp32x2ras(uVar12,uVar16,uVar14,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar12,uVar16,uVar14,uVar8);
  uVar12 = ae_srai32(uVar11,1);
  uVar13 = ae_l32_i(0x2c5c849b);
  uVar14 = ae_sub32(uVar11,uVar12);
  uVar11 = ae_mulafp32x2ras(uVar13,uVar16,uVar7,uVar8);
  uVar8 = ae_mulafp32x2ras_1(uVar13,uVar16,uVar7,uVar8);
  uVar12 = ae_slai32(uVar12,0x17);
  uVar13 = ae_l32_i(&RSTCTL0_SYSRSTSTAT);
  uVar14 = ae_slai32(uVar14,0x17);
  uVar7 = ae_mulafp32x2ras(uVar13,uVar16,uVar11,uVar8);
  ae_mulafp32x2ras_1(uVar13,uVar16,uVar11,uVar8);
  uVar11 = float_sx2(uVar7,0x1e);
  uVar6 = (ulonglong)(uint)((float)uVar14 * (float)uVar12 * (float)uVar11);
  uVar11 = ae_l32_i(0x7f800000);
  ae_movfcrfsrv(uVar15);
  uVar5 = olt_s(in_aed0,uVar11);
  uVar4 = oeq_s(uVar6,uVar11);
  bVar3 = (byte)uVar4;
  ae_sel16i_n(uVar6,uVar6,1);
  if (!(bool)((byte)uVar5 & bVar3)) {
    return;
  }
  uVar15 = const_s(1);
  bVar9 = (byte)((ushort)uVar2 >> 8);
  bVar9 = bVar9 & (bVar9 ^ 1);
  uVar10 = (undefined4)CONCAT71((int7)((ulonglong)uVar11 >> 8),bVar9);
  uVar11 = ae_mov(uVar15);
  uVar7 = movt_s(uVar11,(ulonglong)(uint)-(float)uVar15,bVar9);
  uVar11 = ae_s32x2_i(uVar6);
  rsqrt0_s(uVar7);
  if (bVar9 != 0) {
    uVar10 = 0x7f7f7f7f;
  }
  uVar7 = const_s(0);
  uVar14 = ae_mov(uVar15);
  uVar7 = movt_s(uVar14,uVar7,bVar9);
  uVar12 = ae_movi(1);
  uVar13 = ae_mov(uVar14);
  uVar14 = ae_movda32(0x7f7f7f7f);
  uVar12 = ae_sel16i_n(uVar12,uVar12,3);
  movt_s(uVar13,uVar12,bVar9);
  uVar12 = ae_sel16i_n(uVar14,uVar14,3);
  movt_s(uVar15,uVar12,bVar3 | bVar3 ^ 1);
  recip0_s(uVar7);
  float_s(uVar10,0);
  puVar1 = (undefined4 *)__errno();
  uVar11 = ae_l32x2_i(uVar11);
  *puVar1 = 0x22;
  ae_sel16i(uVar11,uVar11,1);
  return;
}


// ===== scl_atan2f @ 00218e60 (346 bytes)

/* NDSP mathf: atanftbl 0x2006D0 / 0x2006F0, pi and pi/2 (pif_tbl) (was atan2f_) [fact for the
   tables] */

void scl_atan2f(void)

{
  float fVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  undefined8 in_aed0;
  float in_aed1;
  undefined4 in_register_0000400c;
  float fVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  uVar3 = un_s(in_aed0,CONCAT44(in_register_0000400c,in_aed1));
  uVar5 = (ulonglong)(uint)ABS(in_aed1);
  uVar13 = ae_movvfcrfsr();
  if (SUB21(uVar3,0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x21;
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar6 = (ulonglong)(uint)ABS((float)in_aed0);
  uVar14 = max_s(uVar6,uVar5);
  uVar15 = min_s(uVar5,uVar6);
  uVar3 = olt_s(uVar15,0x800000);
  uVar7 = ae_movt32x2(uVar14,(ulonglong)(uint)((float)uVar14 * 8388608.0),uVar3);
  uVar16 = recip0_s(uVar7);
  uVar14 = const_s(1);
  uVar10 = ae_mov(uVar14);
  fVar4 = (float)uVar16;
  fVar4 = fVar4 + fVar4 * ((float)uVar14 - fVar4 * (float)uVar7);
  uVar14 = ae_movt32x2(uVar15,(ulonglong)(uint)((float)uVar15 * 8388608.0),uVar3);
  fVar1 = (float)uVar14 * fVar4;
  uVar16 = ae_mov(uVar14);
  uVar15 = ae_l32_i(0x7f800000);
  uVar3 = oeq_s(uVar7,uVar15);
  uVar17 = const_s(0);
  uVar8 = oeq_s(uVar16,uVar15);
  uVar14 = ae_movt32x2((ulonglong)(uint)(fVar1 + fVar4 * ((float)uVar14 - fVar1 * (float)uVar7)),
                       uVar17,uVar3);
  uVar9 = oeq_s(uVar7,uVar17);
  uVar14 = ae_movt32x2(uVar14,uVar10,uVar8);
  uVar14 = ae_movt32x2(uVar14,uVar17,uVar9);
  uVar7 = const_s(3);
  uVar3 = olt_s(uVar14,uVar7);
  puVar2 = &DAT_002006d0;
  if (!SUB21(uVar3,0)) {
    puVar2 = &DAT_002006f0;
  }
  uVar7 = ae_l32_i(puVar2[2]);
  uVar16 = ae_l32_i(puVar2[3]);
  uVar15 = ae_l32_i(*puVar2);
  uVar17 = ae_l32_i(puVar2[1]);
  fVar4 = (float)uVar14;
  fVar1 = fVar4 * fVar4;
  uVar14 = ae_l32_i(puVar2[4]);
  uVar11 = ae_l32_i(puVar2[5]);
  uVar10 = ae_l32_i(puVar2[6]);
  uVar12 = ae_l32_i(puVar2[7]);
  fVar4 = fVar4 + fVar4 * ((float)uVar12 + (float)uVar10 * fVar4 +
                          ((float)uVar11 + (float)uVar14 * fVar4 +
                          ((float)uVar16 + (float)uVar7 * fVar4 +
                          ((float)uVar17 + (float)uVar15 * fVar4) * fVar1) * fVar1) * fVar1);
  uVar14 = ae_l32_i(0x3fc90fdb);
  uVar3 = olt_s(uVar5,uVar6);
  uVar7 = ae_movt32x2((ulonglong)(uint)fVar4,(ulonglong)(uint)((float)uVar14 - fVar4),uVar3);
  uVar15 = ae_l32_i(0x40490fdb);
  uVar14 = ae_movi(0);
  uVar3 = ae_lt32(CONCAT44(in_register_0000400c,in_aed1),uVar14);
  uVar14 = ae_srli32(in_aed0,0x1f);
  uVar14 = ae_slai32(uVar14,0x1f);
  uVar7 = ae_movt32x2(uVar7,(ulonglong)(uint)((float)uVar15 - (float)uVar7),uVar3);
  uVar14 = ae_xor(uVar7,uVar14);
  ae_movfcrfsrv(uVar13);
  if (!SUB21(uVar9,0)) {
    ae_sel16i(uVar14,uVar14,1);
    return;
  }
  uVar13 = ae_s32x2_i(uVar14);
  puVar2 = (undefined4 *)__errno();
  uVar13 = ae_l32x2_i(uVar13);
  *puVar2 = 0x21;
  ae_sel16i(uVar13,uVar13,1);
  return;
}


// ===== scl_cosinef @ 00218fc0 (299 bytes)

/* NDSP mathf: local range-reduction table 0x200650 and sinf_tbl 0x200830 (was cosf_) [fact for the
   tables] */

void scl_cosinef(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  undefined2 uVar8;
  undefined8 in_aed0;
  float fVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  
  uVar8 = un_s(in_aed0,in_aed0);
  if (SUB21(uVar8,0)) {
    puVar7 = (undefined4 *)__errno();
    *puVar7 = 0x21;
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar13 = ae_l32_i(0x47c90e00);
  fVar1 = ABS((float)in_aed0);
  uVar8 = olt_s(uVar13,(ulonglong)(uint)fVar1);
  uVar13 = ae_movvfcrfsr();
  if (SUB21(uVar8,0)) {
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar12 = ae_l32_i(0x3f22f983);
  uVar14 = firound_s((ulonglong)(uint)(fVar1 * (float)uVar12));
  uVar10 = ae_l32_i(0x3fca0000);
  fVar9 = (float)uVar14;
  uVar12 = ae_l32_i(0xbbf00000);
  uVar15 = ae_l32_i(0xb6960000);
  uVar16 = ae_l32_i(0x32880000);
  fVar2 = fVar9 * (float)uVar16;
  fVar3 = ((fVar1 - fVar9 * (float)uVar10) - fVar9 * (float)uVar12) - fVar9 * (float)uVar15;
  uVar12 = ae_l32_i(0x2e860000);
  fVar1 = fVar9 * (float)uVar12;
  fVar4 = fVar3 - fVar2;
  uVar12 = ae_l32_i(0xaa39ee5a);
  fVar9 = fVar9 * (float)uVar12;
  fVar5 = fVar4 - fVar1;
  fVar6 = fVar5 - fVar9;
  uVar12 = trunc_sx2(uVar14,0);
  fVar6 = fVar6 + ((fVar5 - fVar6) - fVar9) + ((fVar4 - fVar5) - fVar1) + ((fVar3 - fVar4) - fVar2);
  puVar7 = &DAT_00200860;
  uVar10 = ae_slai32(uVar12,0x1f);
  uVar14 = ae_movi(0);
  uVar8 = ae_le32(uVar14,uVar10);
  uVar11 = (ulonglong)(uint)(fVar6 * fVar6);
  if (!SUB21(uVar8,0)) {
    puVar7 = &DAT_00200850;
  }
  uVar10 = ae_l32_i(*puVar7);
  uVar14 = ae_l32_i(puVar7[1]);
  uVar14 = maddn_s(uVar14,uVar10,uVar11);
  uVar10 = ae_l32_i(puVar7[2]);
  uVar14 = maddn_s(uVar10,uVar14,uVar11);
  uVar10 = const_s(0);
  uVar15 = maddn_s(uVar10,uVar14,uVar11);
  uVar10 = const_s(1);
  uVar14 = maddn_s(uVar10,uVar14,uVar11);
  uVar10 = maddn_s((ulonglong)(uint)fVar6,uVar15,(ulonglong)(uint)fVar6);
  uVar15 = ae_movi(1);
  uVar12 = ae_add32(uVar12,uVar15);
  uVar12 = ae_srli32(uVar12,1);
  uVar12 = ae_slai32(uVar12,0x1f);
  uVar10 = ae_movt32x2(uVar10,uVar14,uVar8);
  uVar12 = ae_xor(uVar12,uVar10);
  ae_sel16i(uVar12,uVar12,1);
  ae_movfcrfsrv(uVar13);
  return;
}


// ===== scl_log10f @ 002190f0 (558 bytes)

/* WARNING: Removing unreachable block (ram,0x002192b0) */
/* WARNING: Removing unreachable block (ram,0x00219251) */
/* NDSP mathf: log10f_tbl 0x2007A0.., sqrt(0.5) (was log10f_) [fact for the tables] */

undefined4 scl_log10f(undefined4 param_1)

{
  float fVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 in_br2_10;
  undefined8 in_aed0;
  byte bVar6;
  byte bVar7;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar8;
  
  bVar6 = (byte)((ushort)in_br2_10 >> 8);
  uVar4 = un_s(in_aed0,in_aed0);
  uVar15 = 0;
  uVar12 = const_s(0);
  if (SUB21(uVar4,0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x21;
    ae_l32_i(0x7fc00000);
    return param_1;
  }
  uVar5 = olt_s(in_aed0,uVar12);
  if (SUB21(uVar5,0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x21;
    uVar12 = const_s(1);
    bVar6 = bVar6 | bVar6 ^ 1;
    uVar8 = (undefined4)CONCAT71((int7)((ulonglong)uVar15 >> 8),bVar6);
    uVar15 = ae_mov(uVar12);
    uVar15 = movt_s(uVar15,(ulonglong)(uint)-(float)uVar12,bVar6);
    rsqrt0_s(uVar15);
    bVar3 = SUB21(uVar4,0) && !SUB21(uVar4,0);
    if (bVar3) {
      uVar8 = 0x7f7f7f7f;
    }
    uVar10 = ae_movi(1);
    uVar15 = const_s(0);
    uVar19 = ae_mov(uVar12);
    uVar15 = movt_s(uVar19,uVar15,bVar3);
    uVar11 = ae_movda32(0x7f7f7f7f);
    uVar10 = ae_sel16i_n(uVar10,uVar10,3);
    uVar19 = ae_mov(uVar19);
    movt_s(uVar19,uVar10,bVar3);
    uVar10 = ae_sel16i_n(uVar11,uVar11,3);
    movt_s(uVar12,uVar10,bVar3);
    recip0_s(uVar15);
    float_s(uVar8,0);
    ae_l32_i(0x7fc00000);
    return 0x7f7f7f7f;
  }
  uVar5 = oeq_s(in_aed0,uVar12);
  uVar15 = 0x4b000000;
  uVar12 = ae_movda32(0x800000);
  if (SUB21(uVar5,0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x22;
    bVar7 = (byte)uVar4 & ((byte)uVar4 ^ 1);
    uVar8 = (undefined4)CONCAT71((int7)((ulonglong)uVar15 >> 8),bVar7);
    uVar15 = const_s(1);
    bVar6 = (byte)((ushort)uVar4 >> 8);
    if (bVar7 != 0) {
      uVar8 = 0x7f7f7f7f;
    }
    uVar12 = ae_movda32(0x7f7f7f7f);
    uVar12 = ae_sel16i_n(uVar12,uVar12,3);
    uVar11 = ae_mov(uVar15);
    movt_s(uVar15,uVar12,bVar7);
    uVar12 = ae_mov(uVar11);
    uVar15 = movt_s(uVar12,(ulonglong)(uint)-(float)uVar15,bVar7);
    uVar10 = ae_movi(1);
    uVar12 = const_s(0);
    uVar19 = ae_mov(uVar11);
    uVar12 = movt_s(uVar19,uVar12,bVar6 | bVar6 ^ 1);
    uVar10 = ae_sel16i_n(uVar10,uVar10,3);
    movt_s(uVar11,uVar10,bVar7);
    rsqrt0_s(uVar15);
    recip0_s(uVar12);
    float_s(uVar8,0);
    ae_l32_i(0xff800000);
    return 0x7f7f7f7f;
  }
  uVar5 = olt_s(in_aed0,uVar12);
  uVar15 = ae_movda32(0x4b000000);
  uVar12 = const_s(1);
  uVar15 = ae_movt32x2(uVar12,uVar15,uVar5);
  uVar10 = ae_mov(uVar12);
  uVar19 = ae_movvfcrfsr();
  uVar16 = (ulonglong)(uint)((float)in_aed0 * (float)uVar15);
  uVar15 = ae_movda32(0x7fffff);
  uVar15 = ae_and(uVar16,uVar15);
  uVar12 = ae_movda32(0x3f000000);
  uVar12 = ae_or(uVar15,uVar12);
  uVar11 = const_s(2);
  uVar15 = ae_l32_i(0x3f3504f3);
  uVar4 = olt_s(uVar12,uVar15);
  uVar15 = ae_movt32x2(uVar12,(ulonglong)(uint)((float)uVar12 * (float)uVar11),uVar4);
  fVar1 = (float)uVar10 - (float)uVar15;
  uVar9 = (ulonglong)(uint)fVar1;
  uVar15 = ae_l32_i(0xbd7c887e);
  uVar12 = ae_l32_i(0xbd849a5b);
  uVar11 = maddn_s(uVar12,uVar15,uVar9);
  uVar17 = (ulonglong)(uint)(fVar1 * fVar1);
  uVar15 = ae_l32_i(0xbd937f39);
  uVar10 = ae_l32_i(0xbdb18ed5);
  uVar12 = ae_l32_i(0xbd199153);
  uVar13 = maddn_s(uVar10,uVar15,uVar9);
  uVar15 = maddn_s(uVar11,uVar12,uVar17);
  uVar12 = ae_l32_i(0xbdde5eef);
  uVar11 = ae_l32_i(0xbe143dfd);
  uVar10 = ae_l32_i(0xbe5e5bd7);
  uVar14 = maddn_s(uVar11,uVar12,uVar9);
  uVar12 = ae_movda32(0x95);
  uVar11 = ae_movda32(0x7e);
  uVar13 = maddn_s(uVar13,uVar15,uVar17);
  uVar15 = ae_srli32(uVar16,0x17);
  uVar18 = ae_movt32x2(uVar11,uVar12,uVar5);
  uVar12 = ae_l32_i(0xbede5bd8);
  uVar11 = ae_movi(1);
  uVar18 = ae_sub32(uVar15,uVar18);
  uVar15 = ae_sub32(uVar18,uVar11);
  uVar10 = maddn_s(uVar12,uVar10,uVar9);
  uVar15 = ae_movt32x2(uVar18,uVar15,uVar4);
  uVar11 = maddn_s(uVar14,uVar13,uVar17);
  uVar12 = float_sx2(uVar15,2);
  uVar15 = ae_l32_i(0x3e5104d4);
  uVar15 = maddn_s(uVar12,uVar12,uVar15);
  uVar12 = maddn_s(uVar10,uVar11,uVar17);
  uVar15 = maddn_s(uVar15,uVar12,uVar9);
  uVar12 = ae_l32_i(0x7f800000);
  ae_movfcrfsrv(uVar19);
  uVar4 = oeq_s(in_aed0,uVar12);
  uVar15 = ae_movt32x2(uVar15,uVar12,uVar4);
  ae_sel16i(uVar15,uVar15,1);
  return 0x7f7f7f7f;
}


// ===== scl_lognf @ 00219320 (561 bytes)

/* WARNING: Removing unreachable block (ram,0x002194e5) */
/* WARNING: Removing unreachable block (ram,0x00219484) */
/* NDSP mathf: lognf_tbl 0x2007E0.. [fact for the tables] */

undefined4 scl_lognf(undefined4 param_1)

{
  float fVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 in_br2_10;
  undefined8 in_aed0;
  byte bVar6;
  byte bVar7;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined4 uVar8;
  
  bVar6 = (byte)((ushort)in_br2_10 >> 8);
  uVar4 = un_s(in_aed0,in_aed0);
  uVar15 = 0;
  uVar12 = const_s(0);
  if (SUB21(uVar4,0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x21;
    ae_l32_i(0x7fc00000);
    return param_1;
  }
  uVar5 = olt_s(in_aed0,uVar12);
  if (SUB21(uVar5,0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x21;
    uVar12 = const_s(1);
    bVar6 = bVar6 | bVar6 ^ 1;
    uVar8 = (undefined4)CONCAT71((int7)((ulonglong)uVar15 >> 8),bVar6);
    uVar15 = ae_mov(uVar12);
    uVar15 = movt_s(uVar15,(ulonglong)(uint)-(float)uVar12,bVar6);
    rsqrt0_s(uVar15);
    bVar3 = SUB21(uVar4,0) && !SUB21(uVar4,0);
    if (bVar3) {
      uVar8 = 0x7f7f7f7f;
    }
    uVar10 = ae_movi(1);
    uVar15 = const_s(0);
    uVar18 = ae_mov(uVar12);
    uVar15 = movt_s(uVar18,uVar15,bVar3);
    uVar11 = ae_movda32(0x7f7f7f7f);
    uVar10 = ae_sel16i_n(uVar10,uVar10,3);
    uVar18 = ae_mov(uVar18);
    movt_s(uVar18,uVar10,bVar3);
    uVar10 = ae_sel16i_n(uVar11,uVar11,3);
    movt_s(uVar12,uVar10,bVar3);
    recip0_s(uVar15);
    float_s(uVar8,0);
    ae_l32_i(0x7fc00000);
    return 0x7f7f7f7f;
  }
  uVar5 = oeq_s(in_aed0,uVar12);
  uVar15 = 0x4b000000;
  uVar12 = ae_movda32(0x800000);
  if (SUB21(uVar5,0)) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x22;
    bVar7 = (byte)uVar4 & ((byte)uVar4 ^ 1);
    uVar8 = (undefined4)CONCAT71((int7)((ulonglong)uVar15 >> 8),bVar7);
    uVar15 = const_s(1);
    bVar6 = (byte)((ushort)uVar4 >> 8);
    if (bVar7 != 0) {
      uVar8 = 0x7f7f7f7f;
    }
    uVar12 = ae_movda32(0x7f7f7f7f);
    uVar12 = ae_sel16i_n(uVar12,uVar12,3);
    uVar11 = ae_mov(uVar15);
    movt_s(uVar15,uVar12,bVar7);
    uVar12 = ae_mov(uVar11);
    uVar15 = movt_s(uVar12,(ulonglong)(uint)-(float)uVar15,bVar7);
    uVar10 = ae_movi(1);
    uVar12 = const_s(0);
    uVar18 = ae_mov(uVar11);
    uVar12 = movt_s(uVar18,uVar12,bVar6 | bVar6 ^ 1);
    uVar10 = ae_sel16i_n(uVar10,uVar10,3);
    movt_s(uVar11,uVar10,bVar7);
    rsqrt0_s(uVar15);
    recip0_s(uVar12);
    float_s(uVar8,0);
    ae_l32_i(0xff800000);
    return 0x7f7f7f7f;
  }
  uVar5 = olt_s(in_aed0,uVar12);
  uVar15 = ae_movda32(0x4b000000);
  uVar12 = const_s(1);
  uVar15 = ae_movt32x2(uVar12,uVar15,uVar5);
  uVar18 = ae_mov(uVar12);
  uVar13 = ae_movvfcrfsr();
  uVar16 = (ulonglong)(uint)((float)in_aed0 * (float)uVar15);
  uVar15 = ae_movda32(0x7fffff);
  uVar15 = ae_and(uVar16,uVar15);
  uVar12 = ae_movda32(0x3f000000);
  uVar12 = ae_or(uVar15,uVar12);
  uVar10 = const_s(2);
  uVar15 = ae_l32_i(0x3f3504f3);
  uVar4 = olt_s(uVar12,uVar15);
  uVar15 = ae_movt32x2(uVar12,(ulonglong)(uint)((float)uVar12 * (float)uVar10),uVar4);
  fVar1 = (float)uVar18 - (float)uVar15;
  uVar9 = (ulonglong)(uint)fVar1;
  uVar15 = ae_l32_i(0xbdb0cd23);
  uVar10 = ae_l32_i(0xbe115eaa);
  uVar12 = ae_l32_i(0xbe18aa2f);
  uVar11 = ae_l32_i(0xbe29cfe9);
  uVar10 = maddn_s(uVar10,uVar15,uVar9);
  uVar11 = maddn_s(uVar11,uVar12,uVar9);
  uVar17 = (ulonglong)(uint)(fVar1 * fVar1);
  uVar15 = ae_l32_i(0xbe4c6bcf);
  uVar12 = ae_l32_i(0xbe8001c7);
  uVar12 = maddn_s(uVar12,uVar15,uVar9);
  uVar10 = maddn_s(uVar11,uVar10,uVar17);
  uVar15 = ae_l32_i(0xbeaaab8a);
  uVar11 = ae_l32_i(0xbefffffe);
  uVar15 = maddn_s(uVar11,uVar15,uVar9);
  uVar14 = maddn_s(uVar12,uVar10,uVar17);
  uVar12 = ae_movda32(0x95);
  uVar11 = ae_movda32(0x7e);
  uVar10 = ae_srli32(uVar16,0x17);
  uVar11 = ae_movt32x2(uVar11,uVar12,uVar5);
  uVar12 = ae_movi(1);
  uVar10 = ae_sub32(uVar10,uVar11);
  uVar12 = ae_sub32(uVar10,uVar12);
  uVar11 = maddn_s(uVar15,uVar14,uVar17);
  uVar15 = ae_movt32x2(uVar10,uVar12,uVar4);
  uVar12 = float_sx2(uVar15,0);
  uVar15 = ae_l32_i(0x3f317218);
  uVar10 = msubn_s(uVar18,uVar11,uVar9);
  uVar12 = msubn_s((ulonglong)(uint)((float)uVar12 * (float)uVar15),uVar10,uVar9);
  uVar15 = ae_l32_i(0x7f800000);
  ae_movfcrfsrv(uVar13);
  uVar4 = oeq_s(in_aed0,uVar15);
  uVar15 = ae_movt32x2(uVar12,uVar15,uVar4);
  ae_sel16i(uVar15,uVar15,1);
  return 0x7f7f7f7f;
}


// ===== scl_sinef @ 00219560 (291 bytes)

/* NDSP mathf: local table 0x200670 and sinf_tbl (was sinf_) [fact for the tables] */

void scl_sinef(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  undefined2 uVar8;
  undefined8 in_aed0;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  float fVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  
  uVar8 = un_s(in_aed0,in_aed0);
  if (SUB21(uVar8,0)) {
    puVar7 = (undefined4 *)__errno();
    *puVar7 = 0x21;
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar13 = ae_l32_i(0x47c90e00);
  fVar1 = ABS((float)in_aed0);
  uVar8 = olt_s(uVar13,(ulonglong)(uint)fVar1);
  uVar13 = ae_movvfcrfsr();
  if (SUB21(uVar8,0)) {
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar11 = ae_l32_i(0x3f22f983);
  uVar14 = firound_s((ulonglong)(uint)(fVar1 * (float)uVar11));
  uVar10 = ae_l32_i(0x3fca0000);
  fVar12 = (float)uVar14;
  uVar11 = ae_l32_i(0xbbf00000);
  uVar15 = ae_l32_i(0xb6960000);
  uVar16 = ae_l32_i(0x32880000);
  fVar2 = fVar12 * (float)uVar16;
  fVar3 = ((fVar1 - fVar12 * (float)uVar10) - fVar12 * (float)uVar11) - fVar12 * (float)uVar15;
  uVar11 = ae_l32_i(0x2e860000);
  fVar1 = fVar12 * (float)uVar11;
  fVar4 = fVar3 - fVar2;
  uVar11 = ae_l32_i(0xaa39ee5a);
  fVar12 = fVar12 * (float)uVar11;
  fVar5 = fVar4 - fVar1;
  fVar6 = fVar5 - fVar12;
  uVar11 = trunc_sx2(uVar14,0);
  fVar6 = fVar6 + ((fVar5 - fVar6) - fVar12) + ((fVar4 - fVar5) - fVar1) + ((fVar3 - fVar4) - fVar2)
  ;
  puVar7 = &DAT_00200860;
  uVar10 = ae_slai32(uVar11,0x1f);
  uVar14 = ae_movi(0);
  uVar8 = ae_lt32(uVar10,uVar14);
  uVar9 = (ulonglong)(uint)(fVar6 * fVar6);
  if (!SUB21(uVar8,0)) {
    puVar7 = &DAT_00200850;
  }
  uVar10 = ae_l32_i(*puVar7);
  uVar14 = ae_l32_i(puVar7[1]);
  uVar14 = maddn_s(uVar14,uVar10,uVar9);
  uVar10 = ae_l32_i(puVar7[2]);
  uVar14 = maddn_s(uVar10,uVar14,uVar9);
  uVar10 = const_s(0);
  uVar15 = maddn_s(uVar10,uVar14,uVar9);
  uVar10 = const_s(1);
  uVar14 = maddn_s(uVar10,uVar14,uVar9);
  uVar10 = maddn_s((ulonglong)(uint)fVar6,uVar15,(ulonglong)(uint)fVar6);
  uVar11 = ae_slai32(uVar11,0x1e);
  uVar11 = ae_xor(in_aed0,uVar11);
  uVar11 = ae_srli32(uVar11,0x1f);
  uVar11 = ae_slai32(uVar11,0x1f);
  uVar10 = ae_movt32x2(uVar10,uVar14,uVar8);
  uVar11 = ae_xor(uVar11,uVar10);
  ae_sel16i(uVar11,uVar11,1);
  ae_movfcrfsrv(uVar13);
  return;
}


// ===== scl_tanf @ 00219690 (363 bytes)

/* NDSP mathf: local table 0x200690, tanf_tbl 0x200890 (was tanf_) [fact for the tables] */

void scl_tanf(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined2 uVar9;
  undefined8 in_aed0;
  float fVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  
  uVar9 = un_s(in_aed0,in_aed0);
  if (SUB21(uVar9,0)) {
    puVar7 = (undefined4 *)__errno();
    *puVar7 = 0x21;
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar13 = ae_l32_i(0x460e2c00);
  fVar1 = ABS((float)in_aed0);
  uVar9 = olt_s(uVar13,(ulonglong)(uint)fVar1);
  uVar13 = ae_movvfcrfsr();
  if (SUB21(uVar9,0)) {
    ae_l32_i(0x7fc00000);
    return;
  }
  uVar12 = ae_l32_i(0x3f22f983);
  uVar14 = firound_s((ulonglong)(uint)(fVar1 * (float)uVar12));
  uVar11 = ae_l32_i(0x3fca0000);
  fVar10 = (float)uVar14;
  uVar12 = ae_l32_i(0xbbf00000);
  uVar15 = ae_l32_i(0xb6960000);
  uVar17 = ae_l32_i(0x32880000);
  fVar2 = fVar10 * (float)uVar17;
  fVar3 = ((fVar1 - fVar10 * (float)uVar11) - fVar10 * (float)uVar12) - fVar10 * (float)uVar15;
  uVar12 = ae_l32_i(0x2e860000);
  fVar1 = fVar10 * (float)uVar12;
  fVar4 = fVar3 - fVar2;
  uVar12 = ae_l32_i(0xaa39ee5a);
  fVar10 = fVar10 * (float)uVar12;
  fVar5 = fVar4 - fVar1;
  fVar6 = fVar5 - fVar10;
  fVar6 = fVar6 + ((fVar5 - fVar6) - fVar10) + ((fVar4 - fVar5) - fVar1) + ((fVar3 - fVar4) - fVar2)
  ;
  fVar2 = fVar6 * fVar6;
  uVar11 = ae_l32_i(0x39996b33);
  uVar18 = ae_l32_i(0x3e0886df);
  uVar15 = ae_l32_i(0x3caec172);
  uVar19 = ae_l32_i(0x3d5d65cf);
  uVar17 = ae_l32_i(0x3c2f1d4e);
  uVar20 = ae_l32_i(0x3eaaaab1);
  fVar1 = fVar2 * fVar2;
  uVar16 = ae_l32_i(0x3b8beb97);
  uVar12 = trunc_sx2(uVar14,0);
  uVar14 = ae_slai32(uVar12,0x1f);
  iVar8 = ae_movad32_h(uVar14);
  uVar12 = const_s(1);
  fVar6 = fVar6 + fVar2 * fVar6 *
                  ((float)uVar20 + (float)uVar18 * fVar2 +
                   ((float)uVar19 + (float)uVar15 * fVar2) * fVar1 +
                  ((float)uVar17 + (float)uVar11 * fVar2 + (float)uVar16 * fVar1) * fVar1 * fVar1);
  if (iVar8 < 0) {
    uVar11 = recip0_s((ulonglong)(uint)fVar6);
    uVar12 = maddn_s(uVar11,uVar11,(ulonglong)(uint)((float)uVar12 - fVar6 * (float)uVar11));
    uVar11 = const_s(1);
    uVar11 = maddn_s(uVar12,uVar12,(ulonglong)(uint)((float)uVar11 - fVar6 * (float)uVar12));
    uVar12 = ae_xor(in_aed0,uVar14);
    uVar12 = ae_srli32(uVar12,0x1f);
    uVar12 = ae_slai32(uVar12,0x1f);
    uVar12 = ae_xor(uVar11,uVar12);
    ae_sel16i(uVar12,uVar12,1);
    ae_movfcrfsrv(uVar13);
    return;
  }
  uVar12 = ae_xor(in_aed0,uVar14);
  uVar12 = ae_srli32(uVar12,0x1f);
  uVar12 = ae_slai32(uVar12,0x1f);
  uVar12 = ae_xor((ulonglong)(uint)fVar6,uVar12);
  ae_sel16i(uVar12,uVar12,1);
  ae_movfcrfsrv(uVar13);
  return;
}


// ===== vec_atan2f @ 00219800 (2215 bytes)

/* NDSP mathf: vector atan2 (recip0.s, atanftbl, pi); used by spectral_nr_frame [inference] */

void vec_atan2f(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  ulonglong uVar13;
  float fVar14;
  float fVar15;
  undefined2 uVar16;
  undefined2 uVar17;
  undefined2 uVar18;
  undefined2 uVar19;
  undefined2 uVar20;
  int iVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined4 uVar30;
  undefined4 *puVar31;
  undefined4 *puVar32;
  undefined4 uVar33;
  uint uVar34;
  uint uVar35;
  float fVar36;
  undefined4 *puVar37;
  float fVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined4 uVar41;
  undefined8 uVar42;
  undefined8 uVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  undefined8 uVar48;
  ulonglong uVar49;
  undefined8 uVar50;
  undefined8 uVar51;
  undefined8 uVar52;
  undefined8 uVar53;
  undefined8 uVar54;
  undefined8 uVar55;
  undefined8 uVar56;
  undefined8 uVar57;
  undefined8 uVar58;
  undefined8 uVar59;
  undefined8 uVar60;
  undefined8 uVar61;
  undefined8 local_2a0 [71];
  undefined4 *puStack_64;
  undefined8 *puStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined1 auStack_28 [40];
  
  puStack_60 = local_2a0;
  if (0 < (int)param_4) {
    iVar21 = param_4 + 0xfe;
    if (-1 < (int)(param_4 + 0x7f)) {
      iVar21 = param_4 + 0x7f;
    }
    if (0 < iVar21 >> 7) {
      uVar22 = ae_zalign64();
      uVar42 = const_s(1);
      uStack_48 = ae_s32x2_i(uVar42);
      uVar42 = const_s(0);
      uStack_38 = ae_s32x2_i(uVar42);
      uVar42 = const_s(3);
      uStack_58 = ae_s32x2_i(uVar42);
      uStack_50 = ae_s32x2_i(0x4b000000);
      uStack_40 = ae_s32x2_i(0x800000);
      puStack_64 = param_3 + (iVar21 >> 7) * 0x80;
      do {
        puVar5 = puStack_60;
        uVar42 = ae_la64_pp(param_3);
        uVar23 = ae_l32_i(0x7fc00000);
        uVar24 = ae_la64_pp(param_2);
        uVar34 = param_4;
        if (0x80 < (int)param_4) {
          uVar34 = 0x80;
        }
        uVar25 = ae_l32_i(0x7f800000);
        uVar35 = uVar34 + 2;
        if (-1 < (int)(uVar34 + 1)) {
          uVar35 = uVar34 + 1;
        }
        puVar32 = param_2;
        puVar31 = param_3;
        uVar29 = uVar24;
        uVar28 = uVar42;
        if ((uVar35 >> 1 & 1) != 0) {
          uVar26 = ae_la32x2_ip(uVar24,param_2);
          uVar29 = ae_la32x2_ip_1(uVar24,param_2);
          puVar32 = (undefined4 *)ae_la32x2_ip_2(uVar24,param_2);
          uVar24 = ae_la32x2_ip(uVar42,param_3);
          uVar28 = ae_la32x2_ip_1(uVar42,param_3);
          puVar31 = (undefined4 *)ae_la32x2_ip_2(uVar42,param_3);
          uVar7 = un_s(uVar24,uVar26);
          uVar42 = ae_movt32x2(uVar26,uVar23,uVar7);
          uVar24 = ae_movt32x2(uVar24,uVar23,uVar7);
          uVar26 = ae_l32x2_i(uStack_48);
          uVar27 = ae_l32x2_i(uStack_40);
          uVar43 = min_s((ulonglong)(uint)ABS((float)uVar24),(ulonglong)(uint)ABS((float)uVar42));
          uVar7 = olt_s(uVar43,uVar27);
          uVar27 = ae_l32x2_i(uStack_50);
          uVar27 = ae_movf32x2(uVar27,uVar26,uVar7);
          uVar42 = max_s((ulonglong)(uint)ABS((float)uVar42),(ulonglong)(uint)ABS((float)uVar24));
          fVar14 = (float)uVar42 * (float)uVar27;
          uVar13 = (ulonglong)(uint)fVar14;
          uVar24 = recip0_s(uVar13);
          uVar42 = ae_mov(uVar26);
          fVar9 = (float)uVar24;
          fVar12 = (float)uVar43 * (float)uVar27;
          fVar9 = fVar9 + fVar9 * ((float)uVar42 - fVar9 * fVar14);
          fVar38 = fVar12 * fVar9;
          uVar42 = ae_mov((ulonglong)(uint)fVar12);
          uVar7 = oeq_s(uVar13,uVar25);
          uVar24 = ae_l32x2_i(uStack_38);
          uVar16 = oeq_s((ulonglong)(uint)fVar12,uVar25);
          uVar42 = ae_movt32x2((ulonglong)(uint)(fVar38 + fVar9 * ((float)uVar42 - fVar38 * fVar14))
                               ,uVar24,uVar7);
          uVar7 = oeq_s(uVar13,uVar24);
          uVar42 = ae_movt32x2(uVar42,uVar26,uVar16);
          uVar42 = ae_movt32x2(uVar42,uVar24,uVar7);
          uVar42 = ae_s32x2_ip(uVar42);
          *puStack_60 = uVar42;
          puVar5 = puVar5 + 1;
        }
        uVar42 = ae_movalign(uVar22);
        if ((int)uVar35 >> 2 != 0) {
          uVar43 = ae_la32x2_ip(uVar28,puVar31);
          uVar40 = ae_la32x2_ip_1(uVar28,puVar31);
          uVar30 = ae_la32x2_ip_2(uVar28,puVar31);
          uVar26 = ae_s32x2_i(uVar23);
          uVar27 = ae_la32x2_ip(uVar29,puVar32);
          uVar24 = ae_la32x2_ip_1(uVar29,puVar32);
          uVar41 = ae_la32x2_ip_2(uVar29,puVar32);
          uVar23 = ae_la32x2_ip(uVar24,uVar41);
          uVar28 = ae_la32x2_ip_1(uVar24,uVar41);
          uVar41 = ae_la32x2_ip_2(uVar24,uVar41);
          uVar39 = ae_l32x2_i(uVar26);
          uVar7 = un_s(uVar43,uVar27);
          uVar24 = ae_la32x2_ip(uVar40,uVar30);
          uVar29 = ae_la32x2_ip_1(uVar40,uVar30);
          uVar30 = ae_la32x2_ip_2(uVar40,uVar30);
          uVar40 = ae_l32x2_i(uVar26);
          uVar46 = ae_movt32x2(uVar27,uVar39,uVar7);
          uVar27 = ae_movt32x2(uVar43,uVar40,uVar7);
          uVar40 = ae_l32x2_i(uVar26);
          uVar7 = un_s(uVar24,uVar23);
          uVar43 = ae_l32x2_i(uStack_40);
          uVar39 = ae_l32x2_i(uVar26);
          uVar47 = ae_movt32x2(uVar23,uVar40,uVar7);
          uVar23 = ae_s32x2_i(uVar43);
          uVar43 = ae_l32x2_i(uStack_50);
          uVar48 = ae_movt32x2(uVar24,uVar39,uVar7);
          uVar24 = ae_s32x2_i(uVar43);
          uVar39 = ae_l32x2_i(uStack_48);
          uVar43 = ae_l32x2_i(uVar24);
          uVar40 = ae_l32x2_i(uVar23);
          uVar44 = min_s((ulonglong)(uint)ABS((float)uVar27),(ulonglong)(uint)ABS((float)uVar46));
          uVar7 = olt_s(uVar44,uVar40);
          uVar40 = ae_l32x2_i(uVar23);
          uVar45 = min_s((ulonglong)(uint)ABS((float)uVar48),(ulonglong)(uint)ABS((float)uVar47));
          uVar16 = olt_s(uVar45,uVar40);
          uVar40 = ae_l32x2_i(uVar24);
          uVar27 = max_s((ulonglong)(uint)ABS((float)uVar46),(ulonglong)(uint)ABS((float)uVar27));
          uVar46 = ae_movf32x2(uVar43,uVar39,uVar7);
          uVar43 = ae_movf32x2(uVar40,uVar39,uVar16);
          uVar40 = max_s((ulonglong)(uint)ABS((float)uVar47),(ulonglong)(uint)ABS((float)uVar48));
          fVar38 = (float)uVar27 * (float)uVar46;
          uVar13 = (ulonglong)(uint)fVar38;
          fVar9 = (float)uVar44 * (float)uVar46;
          fVar14 = (float)uVar40 * (float)uVar43;
          uVar49 = (ulonglong)(uint)fVar14;
          uVar25 = ae_s32x2_i(uVar25);
          uVar27 = ae_l32x2_i(uVar25);
          uVar40 = ae_l32x2_i(uVar25);
          uVar44 = recip0_s(uVar13);
          fVar11 = (float)uVar45 * (float)uVar43;
          uVar16 = oeq_s((ulonglong)(uint)fVar9,uVar40);
          uVar43 = ae_l32x2_i(uStack_38);
          uVar40 = recip0_s(uVar49);
          uVar45 = ae_mov(uVar39);
          uVar7 = oeq_s(uVar13,uVar27);
          fVar12 = (float)uVar44;
          uVar44 = ae_mov(uVar39);
          uVar17 = oeq_s(uVar13,uVar43);
          uVar27 = ae_l32x2_i(uVar25);
          fVar15 = (float)uVar40;
          uVar18 = oeq_s(uVar49,uVar43);
          uVar40 = ae_l32x2_i(uVar25);
          uVar19 = oeq_s((ulonglong)(uint)fVar11,uVar40);
          uVar20 = oeq_s(uVar49,uVar27);
          fVar12 = fVar12 + fVar12 * ((float)uVar45 - fVar12 * fVar38);
          uVar27 = ae_mov((ulonglong)(uint)fVar9);
          fVar10 = (float)uVar27;
          uVar27 = ae_mov((ulonglong)(uint)fVar11);
          fVar36 = (float)uVar27;
          fVar15 = fVar15 + fVar15 * ((float)uVar44 - fVar15 * fVar14);
          puVar4 = puVar5;
          if (0 < ((int)uVar35 >> 2) + -1) {
            uVar27 = ae_la32x2_ip(uVar28,uVar41);
            uVar40 = ae_la32x2_ip_1(uVar28,uVar41);
            uVar41 = ae_la32x2_ip_2(uVar28,uVar41);
            uVar46 = ae_mov(uVar39);
            uVar28 = ae_la32x2_ip(uVar29,uVar30);
            uVar44 = ae_la32x2_ip_1(uVar29,uVar30);
            uVar30 = ae_la32x2_ip_2(uVar29,uVar30);
            uVar47 = ae_mov(uVar46);
            uVar45 = ae_la32x2_ip(uVar40,uVar41);
            ae_la32x2_ip_1(uVar40,uVar41);
            ae_la32x2_ip_2(uVar40,uVar41);
            fVar2 = fVar9 * fVar12;
            uVar6 = un_s(uVar28,uVar27);
            uVar40 = ae_l32x2_i(uVar26);
            fVar3 = fVar11 * fVar15;
            uVar29 = ae_la32x2_ip(uVar44,uVar30);
            ae_la32x2_ip_1(uVar44,uVar30);
            ae_la32x2_ip_2(uVar44,uVar30);
            uVar50 = ae_movt32x2(uVar27,uVar40,uVar6);
            uVar27 = ae_l32x2_i(uVar26);
            fVar11 = fVar2 * fVar38;
            uVar8 = un_s(uVar29,uVar45);
            uVar28 = ae_movt32x2(uVar28,uVar27,uVar6);
            uVar27 = ae_l32x2_i(uVar26);
            fVar1 = fVar3 * fVar14;
            uVar27 = ae_movt32x2(uVar45,uVar27,uVar8);
            uVar26 = ae_l32x2_i(uVar26);
            uVar29 = ae_movt32x2(uVar29,uVar26,uVar8);
            uVar40 = ae_l32x2_i(uVar24);
            uVar45 = min_s((ulonglong)(uint)ABS((float)uVar28),(ulonglong)(uint)ABS((float)uVar50));
            uVar26 = ae_l32x2_i(uVar23);
            uVar6 = olt_s(uVar45,uVar26);
            uVar44 = ae_l32x2_i(uVar23);
            uVar26 = ae_movf32x2(uVar40,uVar39,uVar6);
            uVar40 = ae_l32x2_i(uVar24);
            uVar48 = min_s((ulonglong)(uint)ABS((float)uVar29),(ulonglong)(uint)ABS((float)uVar27));
            uVar6 = olt_s(uVar48,uVar44);
            uVar44 = ae_l32x2_i(uVar25);
            uVar50 = max_s((ulonglong)(uint)ABS((float)uVar50),(ulonglong)(uint)ABS((float)uVar28));
            fVar9 = (float)uVar45 * (float)uVar26;
            uVar28 = ae_movf32x2(uVar40,uVar39,uVar6);
            uVar40 = ae_l32x2_i(uVar25);
            uVar27 = max_s((ulonglong)(uint)ABS((float)uVar27),(ulonglong)(uint)ABS((float)uVar29));
            fVar38 = (float)uVar50 * (float)uVar26;
            uVar49 = (ulonglong)(uint)fVar38;
            uVar29 = ae_movt32x2((ulonglong)(uint)(fVar2 + fVar12 * (fVar10 - fVar11)),uVar43,uVar7)
            ;
            uVar26 = ae_l32x2_i(uVar25);
            fVar14 = (float)uVar27 * (float)uVar28;
            uVar13 = (ulonglong)(uint)fVar14;
            fVar11 = (float)uVar48 * (float)uVar28;
            uVar29 = ae_movt32x2(uVar29,uVar39,uVar16);
            uVar25 = ae_l32x2_i(uVar25);
            uVar27 = ae_movt32x2((ulonglong)(uint)(fVar3 + fVar15 * (fVar36 - fVar1)),uVar43,uVar20)
            ;
            uVar16 = oeq_s((ulonglong)(uint)fVar9,uVar40);
            uVar28 = ae_mov((ulonglong)(uint)fVar9);
            uVar40 = ae_movt32x2(uVar29,uVar43,uVar17);
            fVar10 = (float)uVar28;
            uVar7 = oeq_s(uVar49,uVar44);
            uVar29 = recip0_s(uVar49);
            uVar27 = ae_movt32x2(uVar27,uVar39,uVar19);
            uVar17 = oeq_s(uVar49,uVar43);
            uVar28 = recip0_s(uVar13);
            uVar44 = ae_mov((ulonglong)(uint)fVar11);
            fVar36 = (float)uVar44;
            uVar20 = oeq_s(uVar13,uVar26);
            fVar12 = (float)uVar29;
            uVar29 = ae_movt32x2(uVar27,uVar43,uVar18);
            uVar19 = oeq_s((ulonglong)(uint)fVar11,uVar25);
            fVar15 = (float)uVar28;
            uVar18 = oeq_s(uVar13,uVar43);
            uVar25 = ae_s32x2_ip(uVar40);
            *puVar5 = uVar25;
            puVar4 = puVar5 + 2;
            uVar25 = ae_s32x2_i(uVar29);
            puVar5[1] = uVar25;
            fVar12 = fVar12 + fVar12 * ((float)uVar46 - fVar12 * fVar38);
            fVar15 = fVar15 + fVar15 * ((float)uVar47 - fVar15 * fVar14);
          }
          uStack_38 = ae_s32x2_i(uVar43);
          uVar24 = ae_l32x2_i(uVar24);
          uStack_50 = ae_s32x2_i(uVar24);
          uStack_48 = ae_s32x2_i(uVar39);
          uVar24 = ae_movt32x2((ulonglong)
                               (uint)(fVar11 * fVar15 + fVar15 * (fVar36 - fVar11 * fVar15 * fVar14)
                                     ),uVar43,uVar20);
          uVar25 = ae_movt32x2((ulonglong)
                               (uint)(fVar9 * fVar12 + fVar12 * (fVar10 - fVar9 * fVar12 * fVar38)),
                               uVar43,uVar7);
          uVar25 = ae_movt32x2(uVar25,uVar39,uVar16);
          uVar23 = ae_l32x2_i(uVar23);
          uVar24 = ae_movt32x2(uVar24,uVar39,uVar19);
          uStack_40 = ae_s32x2_i(uVar23);
          uVar23 = ae_movt32x2(uVar25,uVar43,uVar17);
          uVar23 = ae_s32x2_ip(uVar23);
          *puVar4 = uVar23;
          uVar23 = ae_movt32x2(uVar24,uVar43,uVar18);
          uVar23 = ae_s32x2_i(uVar23);
          puVar4[1] = uVar23;
        }
        param_4 = param_4 - 0x80;
        uVar23 = ae_la64_pp(param_3);
        uVar35 = param_4;
        if (-1 < (int)uVar34) {
          uVar35 = uVar34;
        }
        uVar24 = ae_la64_pp(param_2);
        puVar37 = param_1 + 0x80;
        puVar5 = puStack_60;
        puVar31 = param_2;
        puVar32 = param_3;
        if (0 < (int)uVar35 >> 1) {
          uVar28 = ae_l32_i(0x3fc90fdb);
          iVar21 = (int)uVar35 >> 2;
          uVar26 = ae_movi(0);
          uVar27 = ae_l32_i(0x40490fdb);
          puVar4 = puStack_60;
          uVar25 = uVar24;
          uVar29 = uVar23;
          if (((int)uVar35 >> 1 & 1U) != 0) {
            uVar25 = ae_l32x2_i(uStack_58);
            uVar39 = ae_l32_i(0xbe30c39c);
            uVar29 = ae_l32_i(0x3dbc14c0);
            uVar44 = ae_l32_i(0x3b2791e4);
            uVar43 = ae_l32x2_ip(*puStack_60);
            puVar4 = puStack_60 + 1;
            uVar40 = ae_l32_i(0x3e4dac9d);
            uVar7 = olt_s(uVar43,uVar25);
            uVar45 = ae_l32_i(0x3e217c35);
            uVar25 = ae_l32_i(0xbecf4163);
            uVar46 = ae_l32_i(0x3ef7b762);
            uVar40 = ae_movf32x2(uVar40,uVar46,uVar7);
            uVar46 = ae_l32_i(0xbcccc037);
            uVar47 = ae_movf32x2(uVar44,uVar25,uVar7);
            uVar25 = ae_movf32x2(uVar29,uVar46,uVar7);
            fVar9 = (float)uVar43;
            fVar12 = fVar9 * fVar9;
            uVar46 = ae_movf32x2(uVar39,uVar45,uVar7);
            uVar29 = ae_l32_i(0xb97d9a57);
            uVar39 = ae_l32_i(0xbe9b8b75);
            uVar43 = ae_l32_i(0xbdf35059);
            uVar44 = ae_l32_i(0xbeaaa7b5);
            uVar29 = ae_movf32x2(uVar29,uVar43,uVar7);
            uVar48 = ae_movf32x2(uVar44,uVar39,uVar7);
            uVar43 = ae_l32_i(0xbb80ed5c);
            uVar44 = ae_l32_i(0x3956fc52);
            uVar39 = ae_l32_i(0xb54f34c8);
            uVar45 = ae_l32_i(0x31cf3fa2);
            uVar43 = ae_movf32x2(uVar39,uVar43,uVar7);
            uVar39 = ae_movf32x2(uVar45,uVar44,uVar7);
            fVar9 = fVar9 + fVar9 * ((float)uVar39 + (float)uVar43 * fVar9 +
                                    ((float)uVar48 + (float)uVar29 * fVar9 +
                                    ((float)uVar40 + (float)uVar47 * fVar9 +
                                    ((float)uVar46 + (float)uVar25 * fVar9) * fVar12) * fVar12) *
                                    fVar12);
            uVar43 = ae_la32x2_ip(uVar23,param_3);
            uVar29 = ae_la32x2_ip_1(uVar23,param_3);
            puVar32 = (undefined4 *)ae_la32x2_ip_2(uVar23,param_3);
            uVar23 = ae_la32x2_ip(uVar24,param_2);
            uVar25 = ae_la32x2_ip_1(uVar24,param_2);
            puVar31 = (undefined4 *)ae_la32x2_ip_2(uVar24,param_2);
            uVar7 = olt_s((ulonglong)(uint)ABS((float)uVar43),(ulonglong)(uint)ABS((float)uVar23));
            uVar24 = ae_movt32x2((ulonglong)(uint)fVar9,(ulonglong)(uint)((float)uVar28 - fVar9),
                                 uVar7);
            uVar7 = ae_lt32(uVar43,uVar26);
            uVar23 = ae_srli32(uVar23,0x1f);
            uVar23 = ae_slai32(uVar23,0x1f);
            uVar24 = ae_movt32x2(uVar24,(ulonglong)(uint)((float)uVar27 - (float)uVar24),uVar7);
            uVar24 = ae_xor(uVar24,uVar23);
            uVar23 = ae_sa32x2_ip(uVar24,uVar42,param_1);
            param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar24,uVar42,param_1);
            uVar42 = uVar23;
          }
          puVar5 = puVar4;
          if (iVar21 != 0) {
            uVar23 = ae_l32_i(0x3b2791e4);
            uVar39 = ae_l32_i(0xbe30c39c);
            uVar45 = ae_l32x2_i(uStack_58);
            uVar44 = ae_l32x2_ip(*puVar4);
            puVar5 = puVar4 + 2;
            uVar7 = olt_s(uVar44,uVar45);
            uVar40 = ae_l32_i(0x3dbc14c0);
            uVar24 = ae_l32_i(0x3ef7b762);
            uVar46 = ae_l32_i(0xbecf4163);
            uVar43 = ae_l32_i(0x3e217c35);
            uVar47 = ae_l32_i(0xbcccc037);
            uVar40 = ae_movf32x2(uVar40,uVar47,uVar7);
            uVar47 = ae_l32_i(0x3e4dac9d);
            uVar51 = ae_movf32x2(uVar39,uVar43,uVar7);
            uVar43 = ae_movf32x2(uVar23,uVar46,uVar7);
            fVar9 = (float)uVar44;
            uVar52 = ae_movf32x2(uVar47,uVar24,uVar7);
            uVar44 = ae_l32_i(0xb97d9a57);
            fVar38 = fVar9 * fVar9;
            uVar23 = ae_l32_i(0xbeaaa7b5);
            uVar46 = ae_l32_i(0xbdf35059);
            uVar24 = ae_l32_i(0xbe9b8b75);
            uVar47 = ae_l32_i(0x3956fc52);
            uVar39 = ae_movf32x2(uVar23,uVar24,uVar7);
            uVar48 = ae_l32_i(0x31cf3fa2);
            uVar53 = ae_movf32x2(uVar44,uVar46,uVar7);
            uVar23 = ae_l32_i(0xbb80ed5c);
            uVar44 = ae_l32_i(0xb54f34c8);
            uVar24 = ae_l32_i(0x3956fc52);
            uVar50 = ae_l32_i(0xbb80ed5c);
            uVar54 = ae_movf32x2(uVar44,uVar23,uVar7);
            uVar44 = ae_l32x2_i(puVar4[1]);
            uVar46 = ae_l32_i(0xbecf4163);
            uVar55 = ae_movf32x2(uVar48,uVar47,uVar7);
            uVar7 = olt_s(uVar44,uVar45);
            uVar47 = ae_l32_i(0x3b2791e4);
            uVar23 = ae_l32_i(0xbcccc037);
            uVar48 = ae_l32_i(0x3ef7b762);
            uVar56 = ae_movf32x2(uVar47,uVar46,uVar7);
            uVar46 = ae_l32_i(0xb54f34c8);
            uVar47 = ae_l32_i(0x31cf3fa2);
            uVar46 = ae_movf32x2(uVar46,uVar50,uVar7);
            uVar50 = ae_l32_i(0x3e217c35);
            uVar57 = ae_movf32x2(uVar47,uVar24,uVar7);
            uVar24 = ae_l32_i(0xbdf35059);
            uVar47 = ae_l32_i(0x3dbc14c0);
            fVar14 = (float)uVar44;
            fVar12 = (float)uVar57 + (float)uVar46 * fVar14;
            uVar46 = ae_l32_i(0xbe30c39c);
            uVar57 = ae_l32_i(0xb97d9a57);
            uVar58 = ae_movf32x2(uVar47,uVar23,uVar7);
            uVar46 = ae_movf32x2(uVar46,uVar50,uVar7);
            uVar47 = ae_l32_i(0x3e4dac9d);
            uVar50 = ae_movf32x2(uVar57,uVar24,uVar7);
            uVar23 = ae_s32x2_i(uVar27);
            uVar57 = ae_movf32x2(uVar47,uVar48,uVar7);
            ae_salign64_i(uVar22,auStack_28,0);
            fVar11 = fVar14 * fVar14;
            uVar47 = ae_l32_i(0xbe9b8b75);
            uVar48 = ae_l32_i(0xbeaaa7b5);
            uVar24 = ae_la32x2_ip(uVar29,puVar32);
            uVar27 = ae_la32x2_ip_1(uVar29,puVar32);
            uVar30 = ae_la32x2_ip_2(uVar29,puVar32);
            fVar9 = fVar9 + fVar9 * ((float)uVar55 + (float)uVar54 * fVar9 +
                                    ((float)uVar39 + (float)uVar53 * fVar9 +
                                    ((float)uVar52 + (float)uVar43 * fVar9 +
                                    ((float)uVar51 + (float)uVar40 * fVar9) * fVar38) * fVar38) *
                                    fVar38);
            uVar48 = ae_movf32x2(uVar48,uVar47,uVar7);
            uVar39 = ae_s32x2_i(uVar28);
            uVar7 = ae_lt32(uVar24,uVar26);
            uVar28 = ae_la32x2_ip(uVar27,uVar30);
            uVar43 = ae_la32x2_ip_1(uVar27,uVar30);
            puVar32 = (undefined4 *)ae_la32x2_ip_2(uVar27,uVar30);
            uVar47 = ae_l32x2_i(uVar39);
            uVar27 = ae_la32x2_ip(uVar25,puVar31);
            uVar40 = ae_la32x2_ip_1(uVar25,puVar31);
            uVar30 = ae_la32x2_ip_2(uVar25,puVar31);
            uVar17 = ae_lt32(uVar28,uVar26);
            uVar25 = ae_la32x2_ip(uVar40,uVar30);
            uVar29 = ae_la32x2_ip_1(uVar40,uVar30);
            puVar31 = (undefined4 *)ae_la32x2_ip_2(uVar40,uVar30);
            uVar16 = olt_s((ulonglong)(uint)ABS((float)uVar24),(ulonglong)(uint)ABS((float)uVar27));
            uVar27 = ae_srli32(uVar27,0x1f);
            uVar24 = ae_l32x2_i(uVar39);
            fVar15 = (float)uVar24;
            uVar24 = ae_movt32x2((ulonglong)(uint)fVar9,(ulonglong)(uint)((float)uVar47 - fVar9),
                                 uVar16);
            uVar16 = olt_s((ulonglong)(uint)ABS((float)uVar28),(ulonglong)(uint)ABS((float)uVar25));
            uVar40 = ae_l32x2_i(uVar23);
            uVar47 = ae_srli32(uVar25,0x1f);
            uVar25 = ae_slai32(uVar27,0x1f);
            uVar28 = ae_l32x2_i(uVar23);
            fVar38 = (float)uVar28;
            uVar28 = ae_slai32(uVar47,0x1f);
            uVar27 = ae_mov((ulonglong)
                            (uint)((float)uVar48 + (float)uVar50 * fVar14 +
                                  ((float)uVar57 + (float)uVar56 * fVar14 +
                                  ((float)uVar46 + (float)uVar58 * fVar14) * fVar11) * fVar11));
            uVar13 = (ulonglong)(uint)((float)uVar40 - (float)uVar24);
            fVar9 = (float)uVar27;
            if ((iVar21 != 1) && (-1 < iVar21 + -1)) {
              if (0 < iVar21 + -1) {
                uVar30 = rsr_lend(0x219e20);
                wsr_lbeg(uVar30);
                wsr_lend(0x219f79);
                isync();
                rsr_lcount(iVar21 + -2);
              }
              uVar27 = ae_l32_i(0x3ef7b762);
              uVar44 = ae_l32_i(0xbcccc037);
              uVar40 = ae_l32_i(0x3e4dac9d);
              uVar46 = ae_l32_i(0x3dbc14c0);
              uVar47 = ae_movt32x2(uVar24,uVar13,uVar7);
              uVar24 = ae_l32x2_ip(*puVar5);
              puVar5 = puVar4 + 4;
              uVar48 = ae_xor(uVar47,uVar25);
              uVar7 = olt_s(uVar24,uVar45);
              uVar25 = ae_l32_i(0x3e217c35);
              fVar10 = (float)uVar24;
              fVar36 = fVar10 * fVar10;
              uVar24 = ae_l32_i(0xbe30c39c);
              uVar47 = ae_l32_i(0x3b2791e4);
              fVar14 = fVar14 + fVar14 * (fVar12 + fVar9 * fVar11);
              uVar52 = ae_movf32x2(uVar46,uVar44,uVar7);
              uVar46 = ae_movf32x2(uVar24,uVar25,uVar7);
              uVar25 = ae_l32_i(0xbecf4163);
              uVar53 = ae_movf32x2(uVar40,uVar27,uVar7);
              uVar24 = ae_l32_i(0xbe9b8b75);
              uVar27 = ae_l32_i(0xbdf35059);
              uVar54 = ae_movf32x2(uVar47,uVar25,uVar7);
              uVar25 = ae_l32_i(0xbeaaa7b5);
              uVar40 = ae_l32_i(0xb97d9a57);
              uVar47 = ae_movf32x2(uVar40,uVar27,uVar7);
              uVar27 = ae_l32_i(0x3956fc52);
              uVar55 = ae_movf32x2(uVar25,uVar24,uVar7);
              uVar24 = ae_l32_i(0x31cf3fa2);
              uVar25 = ae_l32_i(0xb54f34c8);
              uVar40 = ae_sa32x2_ip(uVar48,uVar42,param_1);
              uVar30 = ae_sa32x2_ip_1(uVar48,uVar42,param_1);
              uVar44 = ae_l32_i(0xbb80ed5c);
              uVar56 = ae_movf32x2(uVar24,uVar27,uVar7);
              uVar42 = ae_la32x2_ip(uVar29,puVar31);
              uVar27 = ae_la32x2_ip_1(uVar29,puVar31);
              uVar41 = ae_la32x2_ip_2(uVar29,puVar31);
              uVar58 = ae_movf32x2(uVar25,uVar44,uVar7);
              uVar24 = ae_la32x2_ip(uVar43,puVar32);
              uVar29 = ae_la32x2_ip_1(uVar43,puVar32);
              uVar33 = ae_la32x2_ip_2(uVar43,puVar32);
              uVar44 = ae_movt32x2((ulonglong)(uint)fVar14,(ulonglong)(uint)(fVar15 - fVar14),uVar16
                                  );
              uVar25 = ae_srli32(uVar42,0x1f);
              uVar48 = ae_l32x2_i(uVar39);
              uVar7 = ae_lt32(uVar24,uVar26);
              uVar50 = ae_l32x2_i(uVar23);
              uVar25 = ae_slai32(uVar25,0x1f);
              uVar20 = olt_s((ulonglong)(uint)ABS((float)uVar24),(ulonglong)(uint)ABS((float)uVar42)
                            );
              uVar57 = ae_l32_i(0x3ef7b762);
              uVar42 = ae_l32_i(0x3e4dac9d);
              uVar43 = ae_l32_i(0x3dbc14c0);
              uVar24 = ae_l32_i(0xbcccc037);
              uVar51 = ae_l32_i(0x3e217c35);
              uVar59 = ae_movt32x2(uVar44,(ulonglong)(uint)(fVar38 - (float)uVar44),uVar17);
              uVar44 = ae_l32x2_i(puVar4[3]);
              uVar59 = ae_xor(uVar59,uVar28);
              uVar16 = olt_s(uVar44,uVar45);
              uVar28 = ae_l32_i(0xbe30c39c);
              fVar9 = (float)uVar44;
              fVar11 = fVar9 * fVar9;
              uVar43 = ae_movf32x2(uVar43,uVar24,uVar16);
              uVar45 = ae_l32_i(0xbecf4163);
              uVar51 = ae_movf32x2(uVar28,uVar51,uVar16);
              uVar24 = ae_l32_i(0x3b2791e4);
              uVar28 = ae_l32_i(0xbeaaa7b5);
              uVar60 = ae_movf32x2(uVar42,uVar57,uVar16);
              uVar42 = ae_l32_i(0xbe9b8b75);
              uVar57 = ae_l32_i(0xbdf35059);
              uVar61 = ae_movf32x2(uVar24,uVar45,uVar16);
              uVar45 = ae_movf32x2(uVar28,uVar42,uVar16);
              uVar24 = ae_l32_i(0xb97d9a57);
              fVar10 = fVar10 + fVar10 * ((float)uVar56 + (float)uVar58 * fVar10 +
                                         ((float)uVar55 + (float)uVar47 * fVar10 +
                                         ((float)uVar53 + (float)uVar54 * fVar10 +
                                         ((float)uVar46 + (float)uVar52 * fVar10) * fVar36) * fVar36
                                         ) * fVar36);
              uVar42 = ae_l32_i(0x3956fc52);
              uVar28 = ae_l32_i(0xbb80ed5c);
              uVar47 = ae_movf32x2(uVar24,uVar57,uVar16);
              uVar24 = ae_l32_i(0x31cf3fa2);
              uVar46 = ae_l32_i(0xb54f34c8);
              uVar28 = ae_movf32x2(uVar46,uVar28,uVar16);
              uVar39 = ae_l32x2_i(uVar39);
              uVar42 = ae_movf32x2(uVar24,uVar42,uVar16);
              fVar15 = (float)uVar39;
              uVar24 = ae_la32x2_ip(uVar27,uVar41);
              ae_la32x2_ip_1(uVar27,uVar41);
              puVar31 = (undefined4 *)ae_la32x2_ip_2(uVar27,uVar41);
              uVar27 = ae_la32x2_ip(uVar29,uVar33);
              ae_la32x2_ip_1(uVar29,uVar33);
              puVar32 = (undefined4 *)ae_la32x2_ip_2(uVar29,uVar33);
              fVar12 = (float)uVar42 + (float)uVar28 * fVar9;
              uVar42 = ae_sa32x2_ip(uVar59,uVar40,uVar30);
              param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar59,uVar40,uVar30);
              uVar23 = ae_l32x2_i(uVar23);
              uVar29 = ae_srli32(uVar24,0x1f);
              fVar38 = (float)uVar23;
              uVar17 = ae_lt32(uVar27,uVar26);
              uVar28 = ae_slai32(uVar29,0x1f);
              uVar16 = olt_s((ulonglong)(uint)ABS((float)uVar27),(ulonglong)(uint)ABS((float)uVar24)
                            );
              fVar9 = (float)uVar45 + (float)uVar47 * fVar9 +
                      ((float)uVar60 + (float)uVar61 * fVar9 +
                      ((float)uVar51 + (float)uVar43 * fVar9) * fVar11) * fVar11;
              uVar24 = ae_movt32x2((ulonglong)(uint)fVar10,(ulonglong)(uint)((float)uVar48 - fVar10)
                                   ,uVar20);
              uVar13 = (ulonglong)(uint)((float)uVar50 - (float)uVar24);
            }
            fVar12 = (float)uVar44 + (float)uVar44 * (fVar12 + fVar9 * fVar11);
            uVar29 = ae_movt32x2((ulonglong)(uint)fVar12,(ulonglong)(uint)(fVar15 - fVar12),uVar16);
            uVar23 = ae_movt32x2(uVar24,uVar13,uVar7);
            uVar24 = ae_xor(uVar23,uVar25);
            uVar25 = ae_movt32x2(uVar29,(ulonglong)(uint)(fVar38 - (float)uVar29),uVar17);
            uVar23 = ae_sa32x2_ip(uVar24,uVar42,param_1);
            uVar30 = ae_sa32x2_ip_1(uVar24,uVar42,param_1);
            uVar24 = ae_xor(uVar25,uVar28);
            uVar42 = ae_sa32x2_ip(uVar24,uVar23,uVar30);
            param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar24,uVar23,uVar30);
          }
        }
        ae_sa64pos_fp(uVar42,param_1);
        param_3 = param_3 + 0x80;
        param_2 = param_2 + 0x80;
        if ((uVar34 & 1) != 0) {
          uVar25 = ae_l32_i(0xbe30c39c);
          uVar26 = ae_l32_i(0x3dbc14c0);
          uVar29 = ae_l32_i(0x3e4dac9d);
          uVar27 = ae_l32_i(0x3b2791e4);
          uVar28 = ae_l32_i(*(undefined4 *)puVar5);
          uVar24 = ae_l32x2_i(uStack_58);
          uVar23 = ae_l32_i(0x3e217c35);
          uVar42 = ae_l32_i(0x3ef7b762);
          uVar7 = olt_s(uVar28,uVar24);
          uVar24 = ae_l32_i(0xbecf4163);
          uVar24 = ae_movf32x2(uVar27,uVar24,uVar7);
          uVar27 = ae_l32_i(0xbcccc037);
          uVar43 = ae_movf32x2(uVar29,uVar42,uVar7);
          uVar29 = ae_movf32x2(uVar26,uVar27,uVar7);
          fVar9 = (float)uVar28;
          fVar12 = fVar9 * fVar9;
          uVar27 = ae_movf32x2(uVar25,uVar23,uVar7);
          uVar23 = ae_l32_i(0xbe9b8b75);
          uVar42 = ae_l32_i(0xbdf35059);
          uVar25 = ae_l32_i(0xb97d9a57);
          uVar28 = ae_l32_i(0xbeaaa7b5);
          uVar25 = ae_movf32x2(uVar25,uVar42,uVar7);
          uVar40 = ae_movf32x2(uVar28,uVar23,uVar7);
          uVar23 = ae_l32_i(0x3956fc52);
          uVar42 = ae_l32_i(0xbb80ed5c);
          uVar28 = ae_l32_i(0xb54f34c8);
          uVar26 = ae_l32_i(0x31cf3fa2);
          uVar42 = ae_movf32x2(uVar28,uVar42,uVar7);
          uVar23 = ae_movf32x2(uVar26,uVar23,uVar7);
          fVar9 = fVar9 + fVar9 * ((float)uVar23 + (float)uVar42 * fVar9 +
                                  ((float)uVar40 + (float)uVar25 * fVar9 +
                                  ((float)uVar43 + (float)uVar24 * fVar9 +
                                  ((float)uVar27 + (float)uVar29 * fVar9) * fVar12) * fVar12) *
                                  fVar12);
          uVar42 = ae_l32_i(0x3fc90fdb);
          uVar23 = ae_l32_i(*puVar32);
          uVar24 = ae_l32_i(*puVar31);
          uVar7 = olt_s((ulonglong)(uint)ABS((float)uVar23),(ulonglong)(uint)ABS((float)uVar24));
          uVar25 = ae_movt32x2((ulonglong)(uint)fVar9,(ulonglong)(uint)((float)uVar42 - fVar9),uVar7
                              );
          uVar29 = ae_l32_i(0x40490fdb);
          uVar42 = ae_movi(0);
          uVar7 = ae_lt32(uVar23,uVar42);
          uVar42 = ae_srli32(uVar24,0x1f);
          uVar42 = ae_slai32(uVar42,0x1f);
          uVar23 = ae_movt32x2(uVar25,(ulonglong)(uint)((float)uVar29 - (float)uVar25),uVar7);
          uVar42 = ae_xor(uVar23,uVar42);
          uVar42 = ae_sel16i(uVar42,uVar42,3);
          uVar30 = ae_s32_l_i(uVar42);
          *param_1 = uVar30;
        }
        param_1 = puVar37;
      } while (param_3 != puStack_64);
    }
    return;
  }
  return;
}


// ===== vec_log10f @ 0021a0b0 (1661 bytes)

/* NDSP mathf: vector log10 (float.sx2, log10f_tbl) [inference] */

void vec_log10f(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int in_WindowStart;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined4 *puVar22;
  undefined4 *puVar23;
  undefined4 *puVar24;
  undefined4 uVar25;
  undefined4 *puVar26;
  uint uVar27;
  int iVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  ulonglong uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  undefined8 uVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  undefined8 uVar48;
  undefined8 uVar49;
  undefined8 uVar50;
  undefined8 uVar51;
  undefined8 uVar52;
  undefined8 uVar53;
  ulonglong uVar54;
  undefined8 uVar55;
  undefined8 uVar56;
  undefined8 uVar57;
  undefined8 uVar58;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 auStack_180 [30];
  undefined1 auStack_90 [72];
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined1 auStack_18 [24];
  
  puVar4 = (undefined4 *)
           ((uint)(in_WindowStart == 0) * (int)auStack_90 +
            (uint)(in_WindowStart != 0) * (int)&local_190 + -0x100);
  if ((int)param_3 < 1) {
    return;
  }
  iVar28 = param_3 + 0x7e;
  if (-1 < (int)(param_3 + 0x3f)) {
    iVar28 = param_3 + 0x3f;
  }
  if (0 < iVar28 >> 6) {
    uVar16 = ae_zalign64();
    uVar51 = const_s(1);
    uStack_40 = ae_s32x2_i(uVar51);
    uVar17 = ae_movalign(uVar16);
    uVar51 = const_s(0);
    uVar51 = ae_s32x2_i(uVar51);
    uVar52 = const_s(2);
    uStack_48 = ae_s32x2_i(uVar52);
    puVar26 = param_2 + (iVar28 >> 6) * 0x40;
    uVar3 = param_3;
    if (0x40 < (int)param_3) {
      uVar3 = 0x40;
    }
    do {
      uVar18 = ae_la64_pp(param_2);
      uVar27 = (int)uVar3 >> 1;
      puVar23 = param_2;
      puVar1 = &local_190;
      puVar22 = puVar4;
      uVar52 = uVar17;
      if (0 < (int)uVar27) {
        uVar52 = ae_la32x2_ip(uVar18,param_2);
        uVar33 = ae_la32x2_ip_1(uVar18,param_2);
        puVar23 = (undefined4 *)ae_la32x2_ip_2(uVar18,param_2);
        uVar29 = ae_movda32(0x4b000000);
        uVar18 = ae_movda32(0x800000);
        uVar56 = ae_s32x2_i(uVar18);
        uVar30 = ae_l32x2_i(uStack_48);
        fVar11 = (float)uVar29;
        uVar31 = (ulonglong)(uint)((float)uVar52 * fVar11);
        uVar29 = ae_movda32(0x7fffff);
        uVar18 = ae_l32x2_i(uVar56);
        uVar5 = olt_s(uVar52,uVar18);
        uVar18 = ae_movt32x2(uVar52,uVar31,uVar5);
        uVar53 = ae_mov(uVar52);
        uVar52 = ae_and(uVar18,uVar29);
        uVar32 = ae_movda32(0x3f000000);
        uVar29 = ae_s32x2_i(uVar30);
        uVar30 = ae_l32x2_i(uVar29);
        uVar18 = ae_l32_i(0x3f3504f3);
        uVar19 = ae_movda32(0x7e);
        uVar57 = ae_or(uVar52,uVar32);
        uVar32 = ae_srli32(uVar53,0x17);
        uVar53 = ae_movda32(0x95);
        uVar58 = ae_srli32(uVar31,0x17);
        uVar52 = ae_s32x2_i(uVar18);
        uVar19 = ae_sub32(uVar32,uVar19);
        uVar58 = ae_sub32(uVar58,uVar53);
        uVar18 = ae_l32x2_i(uVar52);
        uVar32 = ae_movi(1);
        uVar58 = ae_movt32x2(uVar19,uVar58,uVar5);
        uVar5 = olt_s(uVar57,uVar18);
        uVar18 = ae_l32x2_i(uStack_40);
        uVar19 = ae_sub32(uVar58,uVar32);
        uVar18 = ae_s32x2_i(uVar18);
        uVar19 = ae_movt32x2(uVar58,uVar19,uVar5);
        local_190 = ae_s32x2_ip(uVar19);
        puVar1 = &uStack_188;
        uVar19 = ae_l32x2_i(uVar18);
        uVar30 = ae_movt32x2(uVar57,(ulonglong)(uint)((float)uVar57 * (float)uVar30),uVar5);
        uVar31 = (ulonglong)(uint)((float)uVar19 - (float)uVar30);
        if (1 < (int)uVar27) {
          uVar19 = ae_l32x2_i(uVar52);
          uVar17 = ae_la32x2_ip(uVar33,puVar23);
          uVar30 = ae_la32x2_ip_1(uVar33,puVar23);
          puVar23 = (undefined4 *)ae_la32x2_ip_2(uVar33,puVar23);
          uVar33 = ae_l32x2_i(uVar56);
          uVar34 = ae_movda32(0x7fffff);
          uVar54 = (ulonglong)(uint)((float)uVar17 * fVar11);
          uVar57 = ae_movalign(uVar30);
          uVar30 = ae_l32x2_i(uVar29);
          fVar9 = (float)uVar30;
          uVar55 = ae_mov(uVar53);
          uVar58 = ae_movalign(uVar16);
          uVar35 = ae_movda32(0x7e);
          uVar30 = ae_mov(uVar17);
          uVar5 = olt_s(uVar17,uVar33);
          iVar28 = uVar27 - 2;
          uVar30 = ae_srli32(uVar30,0x17);
          uVar17 = ae_movt32x2(uVar17,uVar54,uVar5);
          uVar33 = ae_l32x2_i(uVar18);
          fVar8 = (float)uVar33;
          uVar33 = ae_srli32(uVar54,0x17);
          uVar53 = ae_sub32(uVar30,uVar35);
          uVar36 = ae_movda32(0x3f000000);
          uVar30 = ae_sub32(uVar33,uVar55);
          uVar33 = ae_and(uVar17,uVar34);
          uVar17 = uVar58;
          if ((0 < iVar28) && ((iVar28 == 1 || (0 < iVar28)))) {
            uVar20 = ae_la32x2_ip(uVar57,puVar23);
            ae_la32x2_ip_1(uVar57,puVar23);
            puVar23 = (undefined4 *)ae_la32x2_ip_2(uVar57,puVar23);
            uVar33 = ae_or(uVar33,uVar36);
            uVar12 = olt_s(uVar33,uVar19);
            uVar17 = ae_l32x2_i(uVar56);
            fVar10 = (float)uVar33 * fVar9;
            uVar30 = ae_movt32x2(uVar53,uVar30,uVar5);
            uVar5 = olt_s(uVar20,uVar17);
            uVar17 = ae_l32x2_i(uVar29);
            uVar56 = ae_mov(uVar20);
            uVar54 = (ulonglong)(uint)((float)uVar20 * fVar11);
            fVar9 = (float)uVar17;
            uVar17 = ae_sa32x2_ip(uVar31,uVar58,puVar4);
            puVar22 = (undefined4 *)ae_sa32x2_ip_1(uVar31,uVar58,puVar4);
            uVar19 = ae_l32x2_i(uVar52);
            uVar52 = ae_sub32(uVar30,uVar32);
            uVar56 = ae_srli32(uVar56,0x17);
            uVar52 = ae_movt32x2(uVar30,uVar52,uVar12);
            uStack_188 = ae_s32x2_ip(uVar52);
            puVar1 = auStack_180;
            uVar53 = ae_sub32(uVar56,uVar35);
            uVar33 = ae_movt32x2(uVar33,(ulonglong)(uint)fVar10,uVar12);
            uVar52 = ae_movt32x2(uVar20,uVar54,uVar5);
            uVar56 = ae_l32x2_i(uVar18);
            uVar31 = (ulonglong)(uint)(fVar8 - (float)uVar33);
            uVar30 = ae_srli32(uVar54,0x17);
            fVar8 = (float)uVar56;
            uVar33 = ae_and(uVar52,uVar34);
            uVar30 = ae_sub32(uVar30,uVar55);
          }
          uVar56 = ae_or(uVar33,uVar36);
          uVar52 = ae_movt32x2(uVar53,uVar30,uVar5);
          uVar5 = olt_s(uVar56,uVar19);
          uVar30 = ae_sub32(uVar52,uVar32);
          uVar33 = ae_movalign(uVar17);
          uVar17 = ae_movt32x2(uVar52,uVar30,uVar5);
          uVar17 = ae_s32x2_ip(uVar17);
          *puVar1 = uVar17;
          puVar1 = puVar1 + 1;
          uVar52 = ae_movt32x2(uVar56,(ulonglong)(uint)((float)uVar56 * fVar9),uVar5);
          uVar17 = ae_sa32x2_ip(uVar31,uVar33,puVar22);
          puVar22 = (undefined4 *)ae_sa32x2_ip_1(uVar31,uVar33,puVar22);
          uVar31 = (ulonglong)(uint)(fVar8 - (float)uVar52);
        }
        uVar52 = ae_sa32x2_ip(uVar31,uVar17,puVar22);
        puVar22 = (undefined4 *)ae_sa32x2_ip_1(uVar31,uVar17,puVar22);
        uVar17 = ae_l32x2_i(uVar29);
        uStack_48 = ae_s32x2_i(uVar17);
        uVar17 = ae_l32x2_i(uVar18);
        uStack_40 = ae_s32x2_i(uVar17);
      }
      ae_sa64pos_fp(uVar52,puVar22);
      uVar17 = ae_movalign(uVar16);
      if ((uVar3 & 1) != 0) {
        uVar52 = ae_l32_i(*puVar23);
        uVar18 = ae_movda32(0x4b000000);
        uVar31 = (ulonglong)(uint)((float)uVar52 * (float)uVar18);
        uVar18 = ae_movda32(0x800000);
        uVar33 = ae_movda32(0x7fffff);
        uVar5 = olt_s(uVar52,uVar18);
        uVar18 = ae_movt32x2(uVar52,uVar31,uVar5);
        uVar29 = ae_mov(uVar52);
        uVar56 = ae_movda32(0x3f000000);
        uVar18 = ae_and(uVar18,uVar33);
        uVar52 = ae_l32x2_i(uStack_48);
        uVar56 = ae_or(uVar18,uVar56);
        uVar33 = ae_l32_i(0x3f3504f3);
        uVar18 = ae_movda32(0x7e);
        uVar12 = olt_s(uVar56,uVar33);
        uVar30 = ae_srli32(uVar31,0x17);
        uVar33 = ae_movda32(0x95);
        uVar19 = ae_movt32x2(uVar56,(ulonglong)(uint)((float)uVar56 * (float)uVar52),uVar12);
        uVar52 = ae_l32x2_i(uStack_40);
        uVar56 = ae_sub32(uVar30,uVar33);
        uVar33 = ae_srli32(uVar29,0x17);
        uVar18 = ae_sub32(uVar33,uVar18);
        uVar31 = (ulonglong)(uint)((float)uVar52 - (float)uVar19);
        uVar18 = ae_movt32x2(uVar18,uVar56,uVar5);
        uVar52 = ae_movi(1);
        uVar52 = ae_sub32(uVar18,uVar52);
        uVar52 = ae_movt32x2(uVar18,uVar52,uVar12);
        uVar25 = ae_s32_l_i(uVar52);
        *(undefined4 *)puVar1 = uVar25;
        uVar52 = ae_sel16i(uVar31,uVar31,3);
        uVar25 = ae_s32_l_i(uVar52);
        *puVar22 = uVar25;
      }
      uVar18 = ae_la64_pp(param_2);
      uVar52 = ae_la64_pp(puVar4);
      uVar56 = ae_l32_i(0x3e5104d4);
      puVar23 = param_2;
      puVar24 = puVar4;
      puVar1 = &local_190;
      puVar22 = param_1;
      if (0 < (int)uVar27) {
        puVar2 = &local_190;
        uVar33 = uVar52;
        uVar29 = uVar18;
        if ((uVar27 & 1) != 0) {
          uVar58 = ae_l32_ip(0xbd199153);
          uVar29 = ae_la32x2_ip(uVar52,puVar4);
          uVar33 = ae_la32x2_ip_1(uVar52,puVar4);
          puVar24 = (undefined4 *)ae_la32x2_ip_2(uVar52,puVar4);
          uVar37 = ae_l32_ip(0xbd7c887e);
          uVar57 = ae_l32_ip(0xbd849a5b);
          fVar9 = (float)uVar29;
          fVar11 = fVar9 * fVar9;
          uVar34 = ae_l32_ip(0xbd937f39);
          uVar32 = ae_l32_ip(0xbdb18ed5);
          uVar53 = ae_l32_ip(0xbdde5eef);
          uVar30 = ae_l32_ip(0xbe143dfd);
          uVar19 = ae_l32_ip(0xbe5e5bd7);
          uVar36 = ae_l32_ip(0xbede5bd8);
          uVar52 = ae_l32x2_ip(local_190);
          puVar2 = &uStack_188;
          uVar55 = float_sx2(uVar52,2);
          uVar52 = ae_la32x2_ip(uVar18,param_2);
          uVar29 = ae_la32x2_ip_1(uVar18,param_2);
          puVar23 = (undefined4 *)ae_la32x2_ip_2(uVar18,param_2);
          uVar20 = ae_l32_ip(0);
          uVar5 = ult_s(uVar52,uVar20);
          uVar18 = ae_l32_ip(0x7f800000);
          uVar35 = ae_l32_ip(0x7fc00000);
          uVar12 = oeq_s(uVar52,uVar20);
          uVar20 = ae_l32_ip(0xff800000);
          uVar30 = ae_movt32x2((ulonglong)
                               (uint)((float)uVar55 + (float)uVar55 * (float)uVar56 +
                                     fVar9 * ((float)uVar36 + (float)uVar19 * fVar9 +
                                             ((float)uVar30 + (float)uVar53 * fVar9 +
                                             ((float)uVar32 + (float)uVar34 * fVar9 +
                                             ((float)uVar57 + (float)uVar37 * fVar9 +
                                             (float)uVar58 * fVar11) * fVar11) * fVar11) * fVar11)),
                               uVar35,uVar5);
          uVar5 = oeq_s(uVar52,uVar18);
          uVar52 = ae_movt32x2(uVar30,uVar20,uVar12);
          uVar18 = ae_movt32x2(uVar52,uVar18,uVar5);
          uVar52 = ae_sa32x2_ip(uVar18,uVar17,param_1);
          puVar22 = (undefined4 *)ae_sa32x2_ip_1(uVar18,uVar17,param_1);
          uVar17 = uVar52;
        }
        puVar1 = puVar2;
        if ((int)uVar3 >> 2 != 0) {
          uVar52 = ae_la32x2_ip(uVar33,puVar24);
          uVar30 = ae_la32x2_ip_1(uVar33,puVar24);
          uVar25 = ae_la32x2_ip_2(uVar33,puVar24);
          uVar38 = ae_l32_ip(0xbd199153);
          uVar57 = ae_l32_i(0xbd7c887e);
          uVar39 = ae_l32_i(0xbd849a5b);
          fVar8 = (float)uVar52;
          fVar11 = fVar8 * fVar8;
          ae_salign64_i(uVar16,auStack_18,0xfffffff0);
          uVar58 = ae_l32_i(0xbd937f39);
          uVar40 = ae_l32_i(0xbdb18ed5);
          uVar52 = ae_s32x2_i(uVar56);
          uVar56 = ae_l32_ip(0);
          uVar34 = ae_l32_i(0xbd199153);
          uVar41 = ae_l32_i(0xbdde5eef);
          uVar35 = ae_l32_i(0xbe5e5bd7);
          uVar42 = ae_l32_i(0xbede5bd8);
          uVar18 = ae_la32x2_ip(uVar30,uVar25);
          uVar33 = ae_la32x2_ip_1(uVar30,uVar25);
          puVar24 = (undefined4 *)ae_la32x2_ip_2(uVar30,uVar25);
          uVar43 = ae_l32_i(0xbe143dfd);
          fVar10 = (float)uVar18;
          uVar36 = ae_l32_i(0xbd7c887e);
          uVar44 = ae_l32_i(0xbd849a5b);
          uVar18 = ae_la32x2_ip(uVar29,puVar23);
          uVar30 = ae_la32x2_ip_1(uVar29,puVar23);
          uVar25 = ae_la32x2_ip_2(uVar29,puVar23);
          uVar45 = ae_l32_i(0xbd937f39);
          fVar9 = fVar10 * fVar10;
          uVar55 = ae_l32_i(0xbdb18ed5);
          uVar46 = ae_l32_i(0xbdde5eef);
          uVar5 = ult_s(uVar18,uVar56);
          uVar12 = oeq_s(uVar18,uVar56);
          uVar56 = ae_l32x2_ip(*puVar2);
          puVar1 = puVar2 + 2;
          uVar20 = ae_l32_i(0xbe143dfd);
          uVar47 = ae_l32_ip(0xbe5e5bd7);
          uVar37 = ae_l32_ip(0xbede5bd8);
          uVar48 = ae_l32x2_i(uVar52);
          uVar21 = float_sx2(uVar56,2);
          uVar19 = ae_l32_i(0);
          uVar56 = ae_la32x2_ip(uVar30,uVar25);
          uVar29 = ae_la32x2_ip_1(uVar30,uVar25);
          puVar23 = (undefined4 *)ae_la32x2_ip_2(uVar30,uVar25);
          uVar49 = ae_l32x2_i(uVar52);
          uVar32 = ae_l32_i(0x7fc00000);
          uVar53 = ae_l32_i(0x7f800000);
          uVar6 = ult_s(uVar56,uVar19);
          uVar13 = oeq_s(uVar56,uVar19);
          uVar14 = oeq_s(uVar56,uVar53);
          uVar19 = ae_l32_i(0x7f800000);
          uVar15 = oeq_s(uVar18,uVar19);
          uVar18 = ae_l32x2_i(puVar2[1]);
          uVar30 = float_sx2(uVar18,2);
          uVar56 = ae_l32_i(0xff800000);
          uVar18 = ae_l32_i(0x7fc00000);
          uVar31 = (ulonglong)
                   (uint)((float)uVar21 + (float)uVar21 * (float)uVar48 +
                         fVar8 * ((float)uVar42 + (float)uVar35 * fVar8 +
                                 ((float)uVar43 + (float)uVar41 * fVar8 +
                                 ((float)uVar40 + (float)uVar58 * fVar8 +
                                 ((float)uVar39 + (float)uVar57 * fVar8 + (float)uVar38 * fVar11) *
                                 fVar11) * fVar11) * fVar11));
          fVar8 = (float)uVar30 + (float)uVar30 * (float)uVar49;
          uVar30 = ae_l32_i(0xff800000);
          fVar11 = (float)uVar37 + (float)uVar47 * fVar10 +
                   ((float)uVar20 + (float)uVar46 * fVar10 +
                   ((float)uVar55 + (float)uVar45 * fVar10 +
                   ((float)uVar44 + (float)uVar36 * fVar10 + (float)uVar34 * fVar9) * fVar9) * fVar9
                   ) * fVar9;
          if (0 < ((int)uVar3 >> 2) + -1) {
            uVar58 = ae_l32_ip(0xbd199153);
            fVar11 = fVar10 * fVar11;
            uVar34 = ae_movt32x2(uVar31,uVar18,uVar5);
            uVar18 = ae_la32x2_ip(uVar33,puVar24);
            uVar57 = ae_la32x2_ip_1(uVar33,puVar24);
            uVar25 = ae_la32x2_ip_2(uVar33,puVar24);
            uVar33 = ae_movt32x2(uVar34,uVar56,uVar12);
            uVar34 = ae_l32_i(0xbd7c887e);
            uVar40 = ae_l32_i(0xbd849a5b);
            uVar56 = ae_la32x2_ip(uVar57,uVar25);
            ae_la32x2_ip_1(uVar57,uVar25);
            puVar24 = (undefined4 *)ae_la32x2_ip_2(uVar57,uVar25);
            fVar7 = (float)uVar18;
            fVar9 = fVar7 * fVar7;
            fVar10 = (float)uVar56;
            uVar57 = ae_l32_i(0xbd7c887e);
            uVar41 = ae_l32_i(0xbd849a5b);
            uVar18 = ae_movt32x2((ulonglong)(uint)(fVar8 + fVar11),uVar32,uVar6);
            uVar35 = ae_l32_i(0xbd937f39);
            uVar42 = ae_l32_i(0xbdb18ed5);
            fVar11 = fVar10 * fVar10;
            uVar32 = ae_l32_i(0xbd199153);
            uVar43 = ae_l32_i(0xbd937f39);
            uVar56 = ae_movt32x2(uVar33,uVar19,uVar15);
            uVar36 = ae_l32_i(0xbdde5eef);
            uVar44 = ae_l32_i(0xbdb18ed5);
            uVar18 = ae_movt32x2(uVar18,uVar30,uVar13);
            uVar55 = ae_l32_i(0xbe143dfd);
            uVar45 = ae_l32_i(0xbdde5eef);
            uVar33 = ae_movt32x2(uVar18,uVar53,uVar14);
            uVar20 = ae_l32_i(0xbe5e5bd7);
            uVar46 = ae_l32_i(0xbe143dfd);
            uVar37 = ae_l32_i(0xbede5bd8);
            uVar47 = ae_l32_ip(0xbe5e5bd7);
            uVar18 = ae_sa32x2_ip(uVar56,uVar17,puVar22);
            uVar25 = ae_sa32x2_ip_1(uVar56,uVar17,puVar22);
            uVar48 = ae_l32_ip(0xbede5bd8);
            uVar17 = ae_l32x2_ip(*puVar1);
            puVar1 = puVar2 + 4;
            uVar19 = ae_l32x2_i(puVar2[3]);
            uVar21 = float_sx2(uVar17,2);
            uVar49 = ae_l32x2_i(uVar52);
            uVar30 = ae_l32x2_i(uVar52);
            uVar17 = ae_sa32x2_ip(uVar33,uVar18,uVar25);
            puVar22 = (undefined4 *)ae_sa32x2_ip_1(uVar33,uVar18,uVar25);
            uVar52 = ae_la32x2_ip(uVar29,puVar23);
            uVar33 = ae_la32x2_ip_1(uVar29,puVar23);
            uVar25 = ae_la32x2_ip_2(uVar29,puVar23);
            uVar38 = ae_l32_ip(0);
            uVar18 = ae_l32_i(0x7fc00000);
            uVar5 = ult_s(uVar52,uVar38);
            uVar56 = ae_l32_i(0xff800000);
            uVar50 = ae_l32_i(0);
            uVar39 = float_sx2(uVar19,2);
            uVar19 = ae_l32_i(0x7f800000);
            uVar29 = ae_la32x2_ip(uVar33,uVar25);
            ae_la32x2_ip_1(uVar33,uVar25);
            puVar23 = (undefined4 *)ae_la32x2_ip_2(uVar33,uVar25);
            uVar15 = oeq_s(uVar52,uVar19);
            uVar53 = ae_l32_i(0x7f800000);
            fVar11 = (float)uVar48 + (float)uVar47 * fVar10 +
                     ((float)uVar46 + (float)uVar45 * fVar10 +
                     ((float)uVar44 + (float)uVar43 * fVar10 +
                     ((float)uVar41 + (float)uVar57 * fVar10 + (float)uVar32 * fVar11) * fVar11) *
                     fVar11) * fVar11;
            uVar13 = oeq_s(uVar29,uVar50);
            uVar32 = ae_l32_i(0x7fc00000);
            uVar31 = (ulonglong)
                     (uint)((float)uVar21 + (float)uVar21 * (float)uVar49 +
                           fVar7 * ((float)uVar37 + (float)uVar20 * fVar7 +
                                   ((float)uVar55 + (float)uVar36 * fVar7 +
                                   ((float)uVar42 + (float)uVar35 * fVar7 +
                                   ((float)uVar40 + (float)uVar34 * fVar7 + (float)uVar58 * fVar9) *
                                   fVar9) * fVar9) * fVar9));
            fVar8 = (float)uVar39 + (float)uVar39 * (float)uVar30;
            uVar14 = oeq_s(uVar29,uVar53);
            uVar30 = ae_l32_i(0xff800000);
            uVar12 = oeq_s(uVar52,uVar38);
            uVar6 = ult_s(uVar29,uVar50);
          }
          uVar52 = ae_movt32x2(uVar31,uVar18,uVar5);
          uVar52 = ae_movt32x2(uVar52,uVar56,uVar12);
          uVar56 = ae_movt32x2((ulonglong)(uint)(fVar8 + fVar10 * fVar11),uVar32,uVar6);
          uVar18 = ae_movt32x2(uVar52,uVar19,uVar15);
          uVar56 = ae_movt32x2(uVar56,uVar30,uVar13);
          uVar52 = ae_sa32x2_ip(uVar18,uVar17,puVar22);
          uVar25 = ae_sa32x2_ip_1(uVar18,uVar17,puVar22);
          uVar18 = ae_movt32x2(uVar56,uVar53,uVar14);
          uVar17 = ae_sa32x2_ip(uVar18,uVar52,uVar25);
          puVar22 = (undefined4 *)ae_sa32x2_ip_1(uVar18,uVar52,uVar25);
        }
      }
      ae_sa64pos_fp(uVar17,puVar22);
      param_1 = param_1 + 0x40;
      uVar17 = ae_movalign(uVar16);
      param_2 = param_2 + 0x40;
      param_3 = param_3 - 0x40;
      if ((uVar3 & 1) != 0) {
        uVar52 = ae_l32_i(*puVar24);
        uVar56 = ae_l32_i(0xbd7c887e);
        uVar57 = ae_l32_i(0xbd849a5b);
        fVar9 = (float)uVar52;
        fVar11 = fVar9 * fVar9;
        uVar34 = ae_l32_i(0xbd199153);
        uVar52 = ae_l32_i(0xbd937f39);
        uVar53 = ae_l32_i(0xbdb18ed5);
        uVar58 = ae_l32_i(0xbdde5eef);
        uVar19 = ae_l32_i(0xbe143dfd);
        uVar35 = ae_l32_i(0xbe5e5bd7);
        uVar30 = ae_l32_i(0xbede5bd8);
        uVar18 = ae_l32_i(*(undefined4 *)puVar1);
        uVar36 = float_sx2(uVar18,2);
        uVar32 = ae_l32_i(0x3e5104d4);
        uVar33 = ae_l32_i(*puVar23);
        uVar18 = ae_l32_i(0x7f800000);
        uVar55 = ae_l32_i(0x7fc00000);
        uVar29 = ae_l32x2_i(uVar51);
        uVar5 = ult_s(uVar33,uVar29);
        uVar12 = oeq_s(uVar33,uVar29);
        uVar29 = ae_l32_i(0xff800000);
        uVar52 = ae_movt32x2((ulonglong)
                             (uint)((float)uVar36 + (float)uVar36 * (float)uVar32 +
                                   fVar9 * ((float)uVar30 + (float)uVar35 * fVar9 +
                                           ((float)uVar19 + (float)uVar58 * fVar9 +
                                           ((float)uVar53 + (float)uVar52 * fVar9 +
                                           ((float)uVar57 + (float)uVar56 * fVar9 +
                                           (float)uVar34 * fVar11) * fVar11) * fVar11) * fVar11)),
                             uVar55,uVar5);
        uVar5 = oeq_s(uVar33,uVar18);
        uVar52 = ae_movt32x2(uVar52,uVar29,uVar12);
        uVar52 = ae_movt32x2(uVar52,uVar18,uVar5);
        uVar52 = ae_sel16i(uVar52,uVar52,3);
        uVar25 = ae_s32_l_i(uVar52);
        *puVar22 = uVar25;
      }
      uVar3 = param_3;
      if (0x40 < (int)param_3) {
        uVar3 = 0x40;
      }
    } while (param_2 != puVar26);
  }
  return;
}


// ===== scl_bexpf @ 0021a730 (97 bytes)

/* NDSP vectorf: block exponent of one float (2^24 scaling for subnormals) [inference] */

int scl_bexpf(void)

{
  float fVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  float in_aed0;
  ulonglong uVar4;
  int iVar5;
  undefined8 uVar6;
  
  fVar1 = ABS(in_aed0);
  uVar4 = (ulonglong)(uint)fVar1;
  uVar6 = const_s(0);
  iVar5 = ((uint)fVar1 >> 0x17) - 0x7e;
  if ((uint)fVar1 >> 0x17 != 0) {
    uVar2 = oeq_s(uVar4,uVar6);
    uVar3 = un_s(uVar4,uVar4);
    if (SUB21(uVar3,0) || SUB21(uVar2,0)) {
      iVar5 = 0;
    }
    return -iVar5;
  }
  uVar3 = un_s(uVar4,uVar4);
  uVar6 = const_s(0);
  uVar2 = oeq_s(uVar4,uVar6);
  iVar5 = ((uint)(fVar1 * 16777216.0) >> 0x17) - 0x96;
  if ((bool)((byte)uVar3 | (byte)uVar2)) {
    iVar5 = 0;
  }
  return -iVar5;
}


// ===== vec_bexpf @ 0021a7a0 (274 bytes)

/* NDSP vectorf: max |x| over the vector, then exponent [inference] */

int vec_bexpf(undefined4 *param_1,uint param_2)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  
  if ((int)param_2 < 1) {
    return 0;
  }
  uVar10 = ae_la64_pp(param_1);
  uVar16 = const_s(0);
  uVar14 = ae_mov(uVar16);
  if (0 < (int)param_2 >> 1) {
    iVar13 = (int)param_2 >> 2;
    uVar15 = ae_movda32(0x7fffffff);
    uVar11 = uVar10;
    if ((param_2 >> 1 & 1) != 0) {
      uVar14 = ae_la32x2_ip(uVar10,param_1);
      uVar11 = ae_la32x2_ip_1(uVar10,param_1);
      param_1 = (undefined4 *)ae_la32x2_ip_2(uVar10,param_1);
      uVar14 = ae_and(uVar14,uVar15);
      uVar14 = max_s(uVar14,uVar16);
    }
    if (iVar13 != 0) {
      uVar10 = ae_la32x2_ip(uVar11,param_1);
      uVar8 = ae_la32x2_ip_1(uVar11,param_1);
      uVar12 = ae_la32x2_ip_2(uVar11,param_1);
      uVar11 = ae_la32x2_ip(uVar8,uVar12);
      uVar5 = ae_la32x2_ip_1(uVar8,uVar12);
      param_1 = (undefined4 *)ae_la32x2_ip_2(uVar8,uVar12);
      uVar8 = ae_and(uVar10,uVar15);
      uVar10 = ae_and(uVar11,uVar15);
      uVar14 = max_s(uVar8,uVar14);
      if (1 < iVar13) {
        uVar4 = ae_la32x2_ip(uVar5,param_1);
        uVar11 = ae_la32x2_ip_1(uVar5,param_1);
        uVar12 = ae_la32x2_ip_2(uVar5,param_1);
        uVar5 = ae_la32x2_ip(uVar11,uVar12);
        uVar3 = ae_la32x2_ip_1(uVar11,uVar12);
        param_1 = (undefined4 *)ae_la32x2_ip_2(uVar11,uVar12);
        iVar13 = iVar13 + -2;
        uVar11 = uVar4;
        uVar8 = uVar5;
        if ((0 < iVar13) && ((iVar13 == 1 || (0 < iVar13)))) {
          uVar11 = ae_la32x2_ip(uVar3,param_1);
          uVar1 = ae_la32x2_ip_1(uVar3,param_1);
          uVar12 = ae_la32x2_ip_2(uVar3,param_1);
          uVar14 = max_s(uVar10,uVar14);
          uVar10 = ae_and(uVar4,uVar15);
          uVar8 = ae_la32x2_ip(uVar1,uVar12);
          ae_la32x2_ip_1(uVar1,uVar12);
          param_1 = (undefined4 *)ae_la32x2_ip_2(uVar1,uVar12);
          uVar14 = max_s(uVar10,uVar14);
          uVar10 = ae_and(uVar5,uVar15);
        }
        uVar11 = ae_and(uVar11,uVar15);
        uVar14 = max_s(uVar10,uVar14);
        uVar10 = ae_and(uVar8,uVar15);
        uVar14 = max_s(uVar11,uVar14);
      }
      uVar14 = max_s(uVar10,uVar14);
    }
  }
  uVar10 = ae_sel16i(uVar14,uVar14,0);
  uVar14 = max_s(uVar10,uVar14);
  if ((param_2 & 1) != 0) {
    uVar10 = ae_l32_i(*param_1);
    uVar14 = max_s((ulonglong)(uint)ABS((float)uVar10),uVar14);
  }
  uVar7 = oeq_s(uVar14,uVar16);
  uVar6 = un_s(uVar14,uVar14);
  bVar9 = (bool)((byte)uVar6 | (byte)uVar7);
  uVar2 = (uint)(float)uVar14 >> 0x17;
  if (uVar2 != 0) {
    iVar13 = uVar2 - 0x7e;
    if (bVar9) {
      iVar13 = 0;
    }
    return -iVar13;
  }
  iVar13 = ((uint)((float)uVar14 * 16777216.0) >> 0x17) - 0x96;
  if (bVar9) {
    iVar13 = 0;
  }
  return -iVar13;
}


// ===== vec_maxf @ 0021a8c0 (164 bytes)

/* NDSP vectorf: max.s loop from -inf (0x2008B8) [fact for the code] */

void vec_maxf(undefined4 *param_1,uint param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  
  if ((int)param_2 < 1) {
    const_s(0);
    return;
  }
  uVar6 = ae_la64_pp(param_1);
  uVar9 = ae_l32_i(0xff800000);
  if (1 < (int)param_2) {
    uVar5 = uVar6;
    if ((param_2 >> 1 & 1) != 0) {
      uVar2 = ae_la32x2_ip(uVar6,param_1);
      uVar5 = ae_la32x2_ip_1(uVar6,param_1);
      param_1 = (undefined4 *)ae_la32x2_ip_2(uVar6,param_1);
      uVar9 = max_s(uVar2,uVar9);
    }
    iVar8 = ((int)param_2 >> 2) + -1;
    if ((int)param_2 >> 2 != 0) {
      uVar2 = ae_la32x2_ip(uVar5,param_1);
      uVar6 = ae_la32x2_ip_1(uVar5,param_1);
      uVar7 = ae_la32x2_ip_2(uVar5,param_1);
      uVar3 = ae_la32x2_ip(uVar6,uVar7);
      uVar4 = ae_la32x2_ip_1(uVar6,uVar7);
      param_1 = (undefined4 *)ae_la32x2_ip_2(uVar6,uVar7);
      uVar6 = uVar2;
      uVar5 = uVar3;
      if ((0 < iVar8) && ((iVar8 == 1 || (0 < iVar8)))) {
        uVar6 = ae_la32x2_ip(uVar4,param_1);
        uVar1 = ae_la32x2_ip_1(uVar4,param_1);
        uVar7 = ae_la32x2_ip_2(uVar4,param_1);
        uVar9 = max_s(uVar2,uVar9);
        uVar5 = ae_la32x2_ip(uVar1,uVar7);
        ae_la32x2_ip_1(uVar1,uVar7);
        param_1 = (undefined4 *)ae_la32x2_ip_2(uVar1,uVar7);
        uVar9 = max_s(uVar3,uVar9);
      }
      uVar9 = max_s(uVar6,uVar9);
      uVar9 = max_s(uVar5,uVar9);
    }
  }
  uVar6 = ae_sel16i(uVar9,uVar9,0);
  uVar9 = max_s(uVar6,uVar9);
  if ((param_2 & 1) != 0) {
    uVar6 = ae_l32_i(*param_1);
    max_s(uVar6,uVar9);
    return;
  }
  return;
}


// ===== vec_minf @ 0021a970 (169 bytes)

/* NDSP vectorf: min.s loop from +inf (0x2008BC) [fact for the code] */

void vec_minf(undefined4 *param_1,uint param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  
  if ((int)param_2 < 1) {
    const_s(0);
    return;
  }
  uVar7 = ae_la64_pp(param_1);
  uVar11 = ae_l32_i(0x7f800000);
  if (0 < (int)(param_2 & 0xfffffffe)) {
    uVar5 = (param_2 & 0xfffffffe) + 1;
    iVar9 = (int)uVar5 >> 2;
    uVar6 = uVar7;
    if ((uVar5 >> 1 & 1) != 0) {
      uVar2 = ae_la32x2_ip(uVar7,param_1);
      uVar6 = ae_la32x2_ip_1(uVar7,param_1);
      param_1 = (undefined4 *)ae_la32x2_ip_2(uVar7,param_1);
      uVar11 = min_s(uVar2,uVar11);
    }
    iVar10 = iVar9 + -1;
    if (iVar9 != 0) {
      uVar2 = ae_la32x2_ip(uVar6,param_1);
      uVar7 = ae_la32x2_ip_1(uVar6,param_1);
      uVar8 = ae_la32x2_ip_2(uVar6,param_1);
      uVar3 = ae_la32x2_ip(uVar7,uVar8);
      uVar4 = ae_la32x2_ip_1(uVar7,uVar8);
      param_1 = (undefined4 *)ae_la32x2_ip_2(uVar7,uVar8);
      uVar7 = uVar2;
      uVar6 = uVar3;
      if ((0 < iVar10) && ((iVar10 == 1 || (0 < iVar10)))) {
        uVar7 = ae_la32x2_ip(uVar4,param_1);
        uVar1 = ae_la32x2_ip_1(uVar4,param_1);
        uVar8 = ae_la32x2_ip_2(uVar4,param_1);
        uVar11 = min_s(uVar2,uVar11);
        uVar6 = ae_la32x2_ip(uVar1,uVar8);
        ae_la32x2_ip_1(uVar1,uVar8);
        param_1 = (undefined4 *)ae_la32x2_ip_2(uVar1,uVar8);
        uVar11 = min_s(uVar3,uVar11);
      }
      uVar11 = min_s(uVar7,uVar11);
      uVar11 = min_s(uVar6,uVar11);
    }
  }
  uVar7 = ae_sel16i(uVar11,uVar11,0);
  uVar11 = min_s(uVar7,uVar11);
  if ((param_2 & 1) != 0) {
    uVar7 = ae_l32_i(*param_1);
    min_s(uVar7,uVar11);
    return;
  }
  return;
}


// ===== FUN_0021aa20 @ 0021aa20 (101 bytes)

void FUN_0021aa20(void)

{
  undefined2 uVar1;
  undefined8 in_aed0;
  undefined8 in_aed1;
  undefined8 uVar2;
  
  uVar1 = olt_s(in_aed0,0x358637bd);
  uVar2 = const_s(0);
  if ((SUB21(uVar1,0)) && (uVar1 = olt_s(0xb58637bd,in_aed0), SUB21(uVar1,0))) {
    uVar1 = ole_s(uVar2,in_aed1);
    movt_s(0x40490fdb,uVar2,(char)uVar1);
    return;
  }
  uVar1 = olt_s(in_aed1,0x358637bd);
  if ((SUB21(uVar1,0)) && (uVar1 = olt_s(0xb58637bd,in_aed1), SUB21(uVar1,0))) {
    ole_s(uVar2,in_aed0);
    return;
  }
  scl_atan2f();
  return;
}


// ===== env_init @ 0021aa90 (46 bytes)

/* rpmsg_env_bm.c: memset, platform_init [inference] */

undefined4 env_init(void)

{
  undefined4 uVar1;
  bool bVar2;
  
  bVar2 = DAT_00239090 < 0;
  DAT_00239090 = DAT_00239090 + 1;
  if (bVar2) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (1 < DAT_00239090) {
    return 0;
  }
  memset(&DAT_002390a0,0,0x30);
  uVar1 = platform_init();
  return uVar1;
}


// ===== env_deinit @ 0021aac0 (34 bytes)

/* rpmsg_env_bm.c: platform_deinit [inference] */

undefined4 env_deinit(void)

{
  undefined4 uVar1;
  bool bVar2;
  
  bVar2 = DAT_00239090 < 1;
  DAT_00239090 = DAT_00239090 + -1;
  if (bVar2) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (0 < DAT_00239090) {
    return 0;
  }
  uVar1 = platform_deinit();
  return uVar1;
}


// ===== env_allocate_memory @ 0021aae4 (12 bytes)

/* rpmsg_env_bm.c: malloc [inference] */

undefined4 env_allocate_memory(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = malloc(param_1);
  return uVar1;
}


// ===== env_free_memory @ 0021aaf0 (12 bytes)

/* rpmsg_env_bm.c: free [inference] */

void env_free_memory(int param_1)

{
  if (param_1 != 0) {
    free(param_1);
  }
  return;
}


// ===== env_memset @ 0021aafc (16 bytes)

/* rpmsg_env_bm.c [inference] */

void env_memset(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  memset(param_1,param_2,param_3);
  return;
}


// ===== env_memcpy @ 0021ab0c (16 bytes)

/* rpmsg_env_bm.c [inference] */

void env_memcpy(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}


// ===== env_strcmp @ 0021ab1c (16 bytes)

/* rpmsg_env_bm.c: strcmp [inference] */

undefined4 env_strcmp(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = strcmp(param_1,param_2);
  return uVar1;
}


// ===== env_strncpy @ 0021ab2c (16 bytes)

/* rpmsg_env_bm.c: strncpy [inference] */

void env_strncpy(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  strncpy(param_1,param_2,param_3);
  return;
}


// ===== env_strncmp @ 0021ab3c (18 bytes)

/* rpmsg_env_bm.c: strncmp [inference] */

undefined4 env_strncmp(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = strncmp(param_1,param_2,param_3);
  return uVar1;
}

