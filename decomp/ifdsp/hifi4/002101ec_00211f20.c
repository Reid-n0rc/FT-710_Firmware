// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== I2S_AddTransferDMA @ 002101ec (558 bytes)

/* fsl_i2s_dma.c static [inference] */

void I2S_AddTransferDMA(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  memw();
  do {
    if (1 < DAT_00238c7e) {
      return;
    }
    memw();
    iVar1 = (uint)DAT_00238c80 * 8;
    piVar2 = (int *)(&DAT_00238c84 + iVar1);
    memw();
    uVar7 = (uint)DAT_00238ca4;
    memw();
    if (*(int *)(&DAT_00238c88 + iVar1) == 0) {
      return;
    }
    bVar12 = *param_2 == 1;
    if (bVar12) {
      memw();
      iVar8 = *piVar2;
      iVar9 = param_1 + 0xe20;
    }
    else {
      memw();
      iVar8 = param_1 + 0xe30;
      iVar9 = *piVar2;
    }
    uVar10 = (uint)!bVar12;
    uVar4 = (uint)bVar12;
    memw();
    uVar11 = (uint)DAT_00238c7f;
    memw();
    DAT_00238c7f = DAT_00238c7f + 1 & 1;
    memw();
    memw();
    uVar6 = (uint)DAT_00238c7f;
    memw();
    puVar3 = &DAT_00001000;
    if (*(undefined **)(&DAT_00238c88 + iVar1) <= &DAT_00001fff) {
      memw();
      if (*(undefined **)(&DAT_00238c88 + iVar1) < (undefined *)0x1001) {
        memw();
        puVar3 = (undefined *)ae_zext16(*(undefined4 *)(&DAT_00238c88 + iVar1));
      }
      else {
        memw();
        uVar5 = 0;
        if ((*(uint *)(&DAT_00238c88 + iVar1) >> 1 & 3) != 0) {
          uVar5 = *(uint *)(&DAT_00238c88 + iVar1) >> 1 & (uint)&DAT_0000fffc;
        }
        puVar3 = (undefined *)ae_zext16(uVar5);
      }
    }
    memw();
    memw();
    *(short *)((int)&DAT_00238c78 + (uint)DAT_00238c7d * 2) = (short)puVar3;
    memw();
    DAT_00238c7d = DAT_00238c7d + 1 & 1;
    memw();
    uVar5 = 0x200;
    if ((char)param_2[1] == '\x04') {
      if (uVar4 == 4) goto LAB_002103e0;
LAB_0021027a:
      uVar4 = uVar4 << 0xc;
      if (uVar10 != 4) goto LAB_00210288;
LAB_002103f0:
      uVar10 = (uVar10 - 1) * 0x4000 & (uint)&DAT_0000c000;
    }
    else {
      uVar5 = (*(byte *)(param_2 + 1) - 1) * 0x100 & 0x300;
      if (uVar4 != 4) goto LAB_0021027a;
LAB_002103e0:
      uVar4 = (uVar4 - 1) * 0x1000 & (uint)&DAT_00003000;
      if (uVar10 == 4) goto LAB_002103f0;
LAB_00210288:
      uVar10 = uVar10 << 0xe;
    }
    DMA_SetupDescriptor(&DAT_20060610 + uVar11 * 0x10,
                        ((uint)puVar3 / (uint)*(byte *)(param_2 + 1) - 1) * 0x10000 & 0x3ff0000 |
                        uVar5 | (uVar7 & 1) << 5 | 0x10 | uVar4 | uVar10 | 3,iVar8,iVar9,
                        &DAT_20060610 + uVar6 * 0x10);
    memw();
    DAT_00238c7e = DAT_00238c7e + 1;
    memw();
    memw();
    DAT_00238ca4 = DAT_00238ca4 == 0;
    memw();
    memw();
    memw();
    *(int *)(&DAT_00238c88 + iVar1) = *(int *)(&DAT_00238c88 + iVar1) - (int)puVar3;
    memw();
    memw();
    *piVar2 = (int)(puVar3 + *piVar2);
    memw();
    if (*(int *)(&DAT_00238c88 + iVar1) == 0) {
      memw();
      *piVar2 = 0;
      memw();
      DAT_00238c80 = DAT_00238c80 + 1 & 3;
      memw();
    }
    memw();
  } while( true );
}


// ===== I2S_DMACallback @ 00210420 (208 bytes)

/* fsl_i2s_dma.c: DMA callback installed by I2S_TxTransferCreateHandleDMA [inference] */

void I2S_DMACallback(undefined4 param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  piVar2 = (int *)param_2[1];
  uVar3 = *param_2;
  memw();
  bVar1 = *(byte *)((int)piVar2 + 0x35);
  memw();
  memw();
  uVar4 = (uint)*(ushort *)((int)param_2 + (uint)*(byte *)(param_2 + 3) * 2 + 8);
  memw();
  iVar5 = piVar2[(uint)bVar1 * 2 + 5];
  if ((param_3 != 0) && (*piVar2 != 0)) {
    memw();
    if (*(char *)((int)param_2 + 0xe) != '\0') {
      memw();
      memw();
      piVar2[(uint)bVar1 * 2 + 6] = piVar2[(uint)bVar1 * 2 + 6] - uVar4;
      memw();
      piVar2[(uint)bVar1 * 2 + 5] = uVar4 + iVar5;
      memw();
      memw();
      *(undefined2 *)((int)param_2 + (uint)*(byte *)(param_2 + 3) * 2 + 8) = 0;
      memw();
      memw();
      *(byte *)(param_2 + 3) = *(char *)(param_2 + 3) + 1U & 1;
      memw();
      memw();
      *(char *)((int)param_2 + 0xe) = *(char *)((int)param_2 + 0xe) + -1;
    }
    memw();
    if (piVar2[(uint)bVar1 * 2 + 6] == 0) {
      memw();
      piVar2[(uint)bVar1 * 2 + 5] = 0;
      memw();
      *(byte *)((int)piVar2 + 0x35) = bVar1 + 1 & 3;
      if (piVar2[2] != 0) {
        (*(code *)piVar2[2])(uVar3,piVar2,0xa8c,piVar2[3]);
      }
    }
    memw();
    memw();
    if (piVar2[(uint)*(byte *)((int)piVar2 + 0x35) * 2 + 6] == 0) {
      I2S_TransferAbortDMA(uVar3,piVar2);
      return;
    }
    I2S_AddTransferDMA(uVar3,piVar2);
  }
  return;
}


// ===== I3C_MasterGetErrorStatusFlags @ 002104f0 (11 bytes)

/* fsl_i3c.h inline: MERRWARN (+0x9C) [fact for the code] */

undefined4 I3C_MasterGetErrorStatusFlags(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x9c);
}


// ===== I3C_MasterClearErrorStatusFlags @ 002104fc (38 bytes)

/* fsl_i3c.h inline: write MERRWARN, wait clear [fact for the code] */

void I3C_MasterClearErrorStatusFlags(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  *(uint *)(param_1 + 0x9c) = param_2;
  memw();
  uVar1 = *(uint *)(param_1 + 0x9c);
  while ((param_2 & uVar1) != 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x9c);
  }
  return;
}


// ===== I3C_MasterEnableInterrupts @ 00210524 (20 bytes)

/* fsl_i3c.h inline: MINTSET (+0x90) |= mask [fact for the code] */

void I3C_MasterEnableInterrupts(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) | param_2;
  return;
}


// ===== I3C_MasterDisableInterrupts @ 00210538 (11 bytes)

/* fsl_i3c.h inline: MINTCLR (+0x94) [fact for the code] */

void I3C_MasterDisableInterrupts(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x94) = param_2;
  return;
}


// ===== I3C_MasterGetEnabledInterrupts @ 00210544 (11 bytes)

/* fsl_i3c.h inline: MINTSET [fact for the code] */

undefined4 I3C_MasterGetEnabledInterrupts(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x90);
}


// ===== I3C_MasterGetPendingInterrupts @ 00210550 (11 bytes)

/* fsl_i3c.h inline: MINTMASKED (+0x98) [fact for the code] */

undefined4 I3C_MasterGetPendingInterrupts(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x98);
}


// ===== I3C_SlaveGetErrorStatusFlags @ 0021055c (10 bytes)

/* fsl_i3c.h inline: SERRWARN (+0x1C) [fact for the code] */

undefined4 I3C_SlaveGetErrorStatusFlags(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x1c);
}


// ===== I3C_SlaveClearErrorStatusFlags @ 00210568 (10 bytes)

/* fsl_i3c.h inline: SERRWARN write [fact for the code] */

void I3C_SlaveClearErrorStatusFlags(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}


// ===== I3C_SlaveEnableInterrupts @ 00210574 (18 bytes)

/* fsl_i3c.h inline: SINTSET (+0x10) |= mask [fact for the code] */

void I3C_SlaveEnableInterrupts(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | param_2;
  return;
}


// ===== I3C_SlaveDisableInterrupts @ 00210588 (10 bytes)

/* fsl_i3c.h inline: SINTCLR (+0x14) [fact for the code] */

void I3C_SlaveDisableInterrupts(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


// ===== I3C_SlaveGetEnabledInterrupts @ 00210594 (10 bytes)

/* fsl_i3c.h inline: SINTSET [fact for the code] */

undefined4 I3C_SlaveGetEnabledInterrupts(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x10);
}


// ===== I3C_SlaveGetPendingInterrupts @ 002105a0 (10 bytes)

/* fsl_i3c.h inline: SINTMASKED (+0x18) [fact for the code] */

undefined4 I3C_SlaveGetPendingInterrupts(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x18);
}


// ===== I3C_GetInstance @ 002105ac (19 bytes)

/* fsl_i3c.c: I3C 0x40036000 [inference] */

bool I3C_GetInstance(undefined4 *param_1)

{
  return param_1 != &I3C_MCONFIG;
}


// ===== I3C_MasterCheckAndClearError @ 002105c0 (141 bytes)

/* fsl_i3c.c: kStatus_I3C_* 0x1EDE.. [inference] */

undefined * I3C_MasterCheckAndClearError(int param_1,uint param_2)

{
  undefined *puVar1;
  
  if ((param_2 & (uint)&DAT_001f061c) == 0) {
    return (undefined *)0x0;
  }
  if ((param_2 & 0x100000) == 0) {
    if ((param_2 & 4) == 0) {
      if ((param_2 & 8) == 0) {
        if ((param_2 & 0x10) == 0) {
          if ((param_2 & 0x200) == 0) {
            if ((param_2 & 0x400) == 0) {
              if ((param_2 & 0x40000) == 0) {
                if ((param_2 & 0x10000) == 0) {
                  if ((param_2 & 0x20000) == 0) {
                    puVar1 = (undefined *)0x0;
                    if ((param_2 >> 0x13 & 1) != 0) {
                      puVar1 = &DAT_00001ee6;
                    }
                  }
                  else {
                    puVar1 = &DAT_00001ee4;
                  }
                }
                else {
                  puVar1 = &DAT_00001ee3;
                }
              }
              else {
                puVar1 = &DAT_00001ee5;
              }
            }
            else {
              puVar1 = &DAT_00001ee2;
            }
          }
          else {
            puVar1 = &DAT_00001ee1;
          }
        }
        else {
          puVar1 = &DAT_00001ee0;
        }
      }
      else {
        puVar1 = &DAT_00001edf;
      }
    }
    else {
      puVar1 = &DAT_00001ede;
    }
  }
  else {
    puVar1 = &DAT_00001ee7;
  }
  I3C_MasterClearErrorStatusFlags(param_1,param_2 & (uint)&DAT_001f061c);
  memw();
  memw();
  *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 3;
  return puVar1;
}


// ===== I3C_MasterWaitForCtrlDone @ 00210650 (83 bytes)

/* fsl_i3c.c static [inference] */

int I3C_MasterWaitForCtrlDone(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  memw();
  uVar4 = *(uint *)(param_1 + 0x60);
  do {
    memw();
    uVar3 = *(uint *)(param_1 + 0xac);
    uVar1 = I3C_MasterGetErrorStatusFlags(param_1);
    iVar2 = I3C_MasterCheckAndClearError(param_1,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
  } while ((2 << 0x20 - (0x20 - ((uVar4 & 0xc000000) >> 0x1a))) -
           ((uVar3 & (uint)&DAT_001f0000) >> 0x10) < param_2);
  return 0;
}


// ===== I3C_MasterWaitForTxReady @ 002106a4 (72 bytes)

/* fsl_i3c.c static [inference] */

int I3C_MasterWaitForTxReady(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  do {
    memw();
    uVar4 = *(uint *)(param_1 + 0x88);
    uVar1 = I3C_MasterGetErrorStatusFlags(param_1);
    iVar2 = I3C_MasterCheckAndClearError(param_1,uVar1);
    if ((uVar4 >> 10 & 1) != 0) break;
  } while (iVar2 == 0);
  memw();
  *(undefined4 *)(param_1 + 0x88) = 0x400;
  if (param_2 != 0) {
    iVar3 = I3C_MasterGetState(param_1);
    while (iVar3 != 0) {
      iVar3 = I3C_MasterGetState(param_1);
    }
  }
  return iVar2;
}


// ===== I3C_SlaveCheckAndClearError @ 002106ec (149 bytes)

/* fsl_i3c.c static: slave status codes 0x1EEA.. [inference] */

undefined * I3C_SlaveCheckAndClearError(int param_1,uint param_2)

{
  undefined *puVar1;
  
  if ((param_2 & (uint)&DAT_00030f1f) == 0) {
    return (undefined *)0x0;
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      if ((param_2 & 4) == 0) {
        if ((param_2 & 8) == 0) {
          if ((param_2 & 0x10) == 0) {
            if ((param_2 & 0x100) == 0) {
              if ((param_2 & 0x200) == 0) {
                if ((param_2 & 0x400) == 0) {
                  if ((param_2 & 0x800) == 0) {
                    if ((param_2 & 0x10000) == 0) {
                      puVar1 = (undefined *)0x0;
                      if ((param_2 >> 0x11 & 1) != 0) {
                        puVar1 = &DAT_00001ee4;
                      }
                    }
                    else {
                      puVar1 = &DAT_00001ee3;
                    }
                  }
                  else {
                    puVar1 = &DAT_00001eef;
                  }
                }
                else {
                  puVar1 = &DAT_00001ee2;
                }
              }
              else {
                puVar1 = &DAT_00001ee1;
              }
            }
            else {
              puVar1 = &DAT_00001eee;
            }
          }
          else {
            puVar1 = &DAT_00001eed;
          }
        }
        else {
          puVar1 = &DAT_00001ee0;
        }
      }
      else {
        puVar1 = &DAT_00001eec;
      }
    }
    else {
      puVar1 = &DAT_00001eeb;
    }
  }
  else {
    puVar1 = &DAT_00001eea;
  }
  I3C_SlaveClearErrorStatusFlags(param_1);
  memw();
  memw();
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 3;
  return puVar1;
}


// ===== I3C_MasterEmitStop @ 00210784 (104 bytes)

/* fsl_i3c.c static [inference] */

undefined * I3C_MasterEmitStop(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  
  iVar1 = I3C_MasterGetState(param_1);
  if (iVar1 != 3) {
    return &DAT_00001ee6;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xff00fef8 | 2;
  do {
    memw();
    uVar4 = *(uint *)(param_1 + 0x88);
    uVar2 = I3C_MasterGetErrorStatusFlags(param_1);
    puVar3 = (undefined *)I3C_MasterCheckAndClearError(param_1,uVar2);
    if ((uVar4 >> 9 & 1) == 0) {
      if (param_2 != 0) goto LAB_002107de;
    }
    else {
      memw();
      *(undefined4 *)(param_1 + 0x88) = 0x200;
      if (param_2 == 0) {
        return puVar3;
      }
LAB_002107de:
      iVar1 = I3C_MasterGetState(param_1);
      if (iVar1 == 0) {
        return puVar3;
      }
    }
    if (puVar3 != (undefined *)0x0) {
      return puVar3;
    }
  } while( true );
}


// ===== I3C_GetIBIType @ 002107ec (39 bytes)

/* fsl_i3c.c static: table 0x20020C [inference] */

undefined4 I3C_GetIBIType(int param_1)

{
  uint uVar1;
  
  memw();
  uVar1 = (*(uint *)(param_1 + 0x88) & 0xc0) >> 6;
  if (uVar1 - 2 < 2) {
    return *(undefined4 *)(&DAT_00200408 + uVar1 * 4);
  }
  return 0;
}


// ===== I3C_CheckForBusyBus @ 00210814 (32 bytes)

/* fsl_i3c.c: kStatus_I3C_Busy 0x1EDC [inference] */

undefined * I3C_CheckForBusyBus(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  
  memw();
  puVar1 = &DAT_00001edc;
  uVar2 = *(uint *)(param_1 + 0x88) & 7;
  if (uVar2 == 0) {
    uVar2 = 1;
  }
  if (uVar2 != 0) {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}


// ===== I3C_GetDefaultConfig @ 00210834 (101 bytes)

/* fsl_i3c.c: 400 kHz / 1 / 2.5 / 12.5 MHz defaults [fact for the constants] */

void I3C_GetDefaultConfig(undefined4 *param_1)

{
  memset(param_1,0,0x40);
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  *(undefined1 *)((int)param_1 + 0x3b) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  *(undefined1 *)((int)param_1 + 0x3d) = 0;
  *(undefined1 *)((int)param_1 + 0x3e) = 0;
  *param_1 = 2;
  param_1[4] = &DAT_00061a80;
  param_1[5] = 12500000;
  param_1[6] = &DAT_002625a0;
  *(undefined1 *)(param_1 + 7) = 10;
  *(undefined1 *)(param_1 + 3) = 1;
  *(undefined1 *)((int)param_1 + 0xd) = 1;
  *(undefined1 *)(param_1 + 0xb) = 1;
  *(undefined1 *)((int)param_1 + 0x3a) = 1;
  param_1[8] = &DAT_000f4240;
  *(undefined2 *)((int)param_1 + 0x2e) = 0x11b;
  return;
}


// ===== I3C_Init @ 0021089c (587 bytes)

/* fsl_i3c.c order [inference] */

void I3C_Init(uint *param_1,uint *param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar8 = I3C_GetInstance(param_1);
  uVar9 = *(uint *)(&DAT_00200404 + iVar8 * 4);
  uVar10 = uVar9 >> 8 & 0xff;
  if (uVar10 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
  }
  else if (uVar10 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
  }
  else if (uVar10 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
  }
  else if (uVar10 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
  }
  else if (uVar10 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
  }
  else if (uVar10 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar9 & 0x1f));
  }
  RESET_PeripheralReset(*(undefined4 *)(&DAT_00200408 + iVar8 * 4));
  uVar9 = param_2[7];
  uVar10 = *param_2;
  if (((byte)uVar9 != 0) && (uVar10 == 1)) {
    memw();
    memw();
    param_1[0x39] = param_1[0x39] & 0xffffff01;
    memw();
    memw();
    param_1[0x39] = param_1[0x39] | ((byte)uVar9 & 0x7f) << 1 | 1;
  }
  memw();
  *param_1 = ((byte)param_2[3] & 1) << 6 | (*(byte *)((int)param_2 + 0xd) & 1) << 0x18 |
             (param_2[2] & 3) << 4 | uVar10 & 3 | ((byte)param_2[1] & 1) << 3;
  memw();
  param_1[0x2b] = 0x37;
  I3C_MasterSetBaudRate(param_1,param_2 + 4,param_3);
  memw();
  bVar5 = *(byte *)((int)param_2 + 0x3b);
  bVar1 = *(byte *)((int)param_2 + 0x3a);
  uVar9 = param_2[0xf];
  bVar2 = *(byte *)((int)param_2 + 0x3d);
  uVar11 = param_2[8];
  bVar3 = *(byte *)((int)param_2 + 0x3e);
  bVar4 = *(byte *)((int)param_2 + 0x2d);
  uVar10 = param_2[0xc];
  uVar7 = param_2[0xb];
  memw();
  memw();
  param_1[0x1d] = param_1[0x1d] & 0xffff8000;
  memw();
  memw();
  param_1[0x1d] = param_1[0x1d] | *(ushort *)((int)param_2 + 0x2e) & 0x7fff;
  if ((byte)uVar10 == 0) {
    memw();
    param_1[0x1b] = param_2[0xd];
  }
  memw();
  memw();
  bVar6 = *(byte *)((int)param_2 + 0x39);
  param_1[0x1c] = param_1[0x1c] & 0xff0000ff;
  memw();
  memw();
  param_1[0x1c] = param_1[0x1c] | (uint)(byte)param_2[0xe] << 8 | (uint)bVar6 << 0x10;
  memw();
  param_1[1] = (uint)(byte)uVar7 | param_1[1] & 0x100fce0 |
               (bVar5 & 1) << 1 | (bVar3 & 1) << 2 |
               ((byte)uVar9 & 1) << 3 | (bVar1 & 1) << 4 |
               (uint)bVar4 << 0x19 | (uVar11 / (uint)&DAT_000f4240 & 0xff) << 0x10 |
               (bVar2 & 1) << 9 | ((byte)uVar10 & 1) << 8;
  return;
}


// ===== I3C_MasterGetDefaultConfig @ 00210ae8 (40 bytes)

/* fsl_i3c.c order [inference] */

void I3C_MasterGetDefaultConfig(undefined4 *param_1)

{
  param_1[6] = &DAT_002625a0;
  param_1[5] = 12500000;
  param_1[4] = &DAT_00061a80;
  *param_1 = 1;
  *(undefined1 *)(param_1 + 3) = 1;
  *(undefined1 *)((int)param_1 + 0xd) = 1;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  return;
}


// ===== I3C_MasterInit @ 00210b10 (271 bytes)

/* fsl_i3c.c order [inference] */

void I3C_MasterInit(uint *param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = I3C_GetInstance(param_1);
  uVar2 = *(uint *)(&DAT_00200404 + iVar1 * 4);
  uVar3 = uVar2 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  RESET_PeripheralReset(*(undefined4 *)(&DAT_00200408 + iVar1 * 4));
  memw();
  *param_1 = ((byte)param_2[3] & 1) << 6 | (*(byte *)((int)param_2 + 0xd) & 1) << 0x18 |
             (param_2[2] & 3) << 4 | *param_2 & 3 | ((byte)param_2[1] & 1) << 3;
  memw();
  param_1[0x2b] = 0x37;
  I3C_MasterSetBaudRate(param_1,param_2 + 4,param_3);
  return;
}


// ===== I3C_MasterGetState @ 00210c20 (22 bytes)

/* fsl_i3c.c: state table 0x200420 [inference] */

undefined4 I3C_MasterGetState(int param_1)

{
  memw();
  return *(undefined4 *)(&DAT_00200420 + (*(uint *)(param_1 + 0x88) & 7) * 4);
}


// ===== I3C_MasterDeinit @ 00210c38 (248 bytes)

/* fsl_i3c.c order [inference] */

void I3C_MasterDeinit(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = I3C_GetInstance(param_1);
  RESET_PeripheralReset(*(undefined4 *)(&DAT_00200408 + iVar1 * 4));
  uVar2 = *(uint *)(&DAT_00200404 + iVar1 * 4);
  uVar3 = uVar2 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238e38)[iVar1] = 0;
    return;
  }
  if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238e38)[iVar1] = 0;
    return;
  }
  if (uVar3 == 2) {
    memw();
    CLKCTL0_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238e38)[iVar1] = 0;
    return;
  }
  if (uVar3 != 3) {
    if (uVar3 == 4) {
      memw();
      CLKCTL1_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      (&DAT_00238e38)[iVar1] = 0;
      return;
    }
    if (uVar3 != 5) {
      (&DAT_00238e38)[iVar1] = 0;
      return;
    }
    memw();
    CLKCTL1_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238e38)[iVar1] = 0;
    return;
  }
  memw();
  CLKCTL1_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  (&DAT_00238e38)[iVar1] = 0;
  return;
}


// ===== I3C_CalcErrorRatio @ 00210d30 (39 bytes)

/* fsl_i3c.c static; called by I3C_MasterSetBaudRate [inference] */

uint I3C_CalcErrorRatio(uint param_1,uint param_2)

{
  if (param_2 < param_1) {
    return ((param_1 - param_2) * 100) / param_2;
  }
  return ((param_2 - param_1) * 100) / param_2;
}


// ===== I3C_MasterSetBaudRate @ 00210d58 (223 bytes)

/* fsl_i3c.c order [inference] */

void I3C_MasterSetBaudRate(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar4 = param_2[2];
  uVar5 = param_2[1];
  param_3 = param_3 >> 1;
  uVar3 = 0x28;
  if (param_3 / uVar5 != 0) {
    uVar3 = param_3 / uVar5;
  }
  uVar6 = *param_2;
  uVar2 = uVar3 + 1;
  if (param_3 / uVar3 <= uVar5 + uVar5 / 0x28) {
    uVar2 = uVar3;
  }
  param_3 = param_3 / uVar2;
  uVar3 = param_3 / uVar4;
  if (uVar3 < 2) {
    uVar3 = 2;
  }
  uVar5 = uVar3 + 1;
  if (param_3 / uVar3 <= uVar4 + uVar4 / 10) {
    uVar5 = uVar3;
  }
  param_3 = param_3 / uVar5;
  uVar3 = 1;
  if (param_3 / uVar6 != 0) {
    uVar3 = param_3 / uVar6;
  }
  uVar4 = I3C_CalcErrorRatio(param_3 / uVar3,uVar6);
  iVar7 = uVar3 * 2;
  uVar1 = I3C_CalcErrorRatio((param_3 << 1) / (iVar7 + 1U),uVar6);
  if ((uVar4 < 10) || (uVar1 < 10)) {
    iVar8 = iVar7 + -2;
    if (uVar1 <= uVar4) {
      iVar8 = iVar7 + -1;
    }
  }
  else {
    iVar8 = iVar7;
    if (param_3 / uVar3 < uVar6) {
      iVar8 = iVar7 + -2;
    }
  }
  memw();
  memw();
  *param_1 = *param_1 & 0xf0000ff | (uVar2 - 1) * 0x100 & (uint)&DAT_00000f00 |
             iVar8 << 0x1c | (uVar5 - 1) * 0x10000 & 0xff0000;
  return;
}


// ===== I3C_MasterStart @ 00210e38 (63 bytes)

/* fsl_i3c.c: GetState, then I3C_MasterRepeatedStart [inference] */

undefined *
I3C_MasterStart(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = I3C_MasterGetState(param_1);
  if ((iVar1 != 0) && (iVar1 != 3)) {
    return &DAT_00001edc;
  }
  puVar2 = (undefined *)I3C_MasterRepeatedStart(param_1,param_2,param_3,param_4);
  return puVar2;
}


// ===== I3C_MasterRepeatedStart @ 00210e7c (77 bytes)

/* fsl_i3c.c order [inference] */

undefined4 I3C_MasterRepeatedStart(int param_1,uint param_2,uint param_3,uint param_4)

{
  memw();
  *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
  memw();
  memw();
  *(uint *)(param_1 + 0x84) =
       *(uint *)(param_1 + 0x84) & 0xff0000c8 |
       (param_3 & 0x7f) << 9 | (param_2 & 3) << 4 | (param_4 & 1) << 8 | 1;
  return 0;
}


// ===== I3C_MasterStop @ 00210ecc (96 bytes)

/* fsl_i3c.c order [inference] */

undefined * I3C_MasterStop(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  
  iVar1 = I3C_MasterGetState(param_1);
  if (iVar1 != 3) {
    return &DAT_00001ee6;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xff00fef8 | 2;
  do {
    memw();
    uVar4 = *(uint *)(param_1 + 0x88);
    uVar2 = I3C_MasterGetErrorStatusFlags(param_1);
    puVar3 = (undefined *)I3C_MasterCheckAndClearError(param_1,uVar2);
    if ((uVar4 >> 9 & 1) != 0) {
      memw();
      *(undefined4 *)(param_1 + 0x88) = 0x200;
    }
    iVar1 = I3C_MasterGetState(param_1);
  } while ((iVar1 != 0) && (puVar3 == (undefined *)0x0));
  return puVar3;
}


// ===== I3C_MasterEmitRequest @ 00210f34 (28 bytes)

/* fsl_i3c.c order [inference] */

void I3C_MasterEmitRequest(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x84) = param_2 & 7 | *(uint *)(param_1 + 0x84) & 0xfffffff8;
  return;
}


// ===== I3C_MasterRegisterIBI @ 00210f50 (83 bytes)

/* fsl_i3c.c order [inference] */

byte * I3C_MasterRegisterIBI(int param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*param_2 | (uint)&RSTCTL0_SYSRSTSTAT | (uint)param_2[1] << 6;
  if (param_2[5] == 0) {
    uVar1 = uVar1 | 0x80000000;
  }
  memw();
  *(uint *)(param_1 + 0x8c) = uVar1;
  return param_2 + 2;
}


// ===== I3C_MasterReceive @ 00210fa4 (310 bytes)

/* WARNING: Removing unreachable block (ram,0x00211096) */
/* fsl_i3c.c order [inference] */

undefined * I3C_MasterReceive(int param_1,undefined1 *param_2,int param_3,uint param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  
  if (param_3 == 0) {
    return (undefined *)0x0;
  }
  if (param_3 == 1) {
    memw();
    memw();
    *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | (uint)&DAT_00010000;
  }
  bVar1 = false;
LAB_00210ffb:
  do {
    uVar2 = I3C_MasterGetErrorStatusFlags(param_1);
    puVar3 = (undefined *)I3C_MasterCheckAndClearError(param_1,uVar2);
    if (puVar3 != (undefined *)0x0) {
      return puVar3;
    }
    if ((!bVar1) && (memw(), (*(uint *)(param_1 + 0x88) & 0x400) != 0)) {
      memw();
      *(undefined4 *)(param_1 + 0x88) = 0x400;
      if ((param_4 & 4) == 0) {
        iVar4 = I3C_MasterGetState(param_1);
        if (iVar4 == 4) {
          I3C_MasterEmitRequest(param_1,6);
        }
        else {
          iVar4 = I3C_MasterGetState(param_1);
          if (iVar4 == 3) {
            memw();
            memw();
            *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xff00fef8 | 2;
            do {
              memw();
              uVar5 = *(uint *)(param_1 + 0x88);
              uVar2 = I3C_MasterGetErrorStatusFlags(param_1);
              puVar3 = (undefined *)I3C_MasterCheckAndClearError(param_1,uVar2);
              if ((uVar5 & 0x200) != 0) {
                memw();
                *(undefined4 *)(param_1 + 0x88) = 0x200;
                break;
              }
            } while (puVar3 == (undefined *)0x0);
          }
          else {
            puVar3 = &DAT_00001ee6;
          }
          if (puVar3 != (undefined *)0x0) {
            return puVar3;
          }
        }
      }
      bVar1 = true;
    }
    if (param_3 != 0) {
      memw();
      if ((*(uint *)(param_1 + 0xac) & 0x1f000000) != 0) {
        memw();
        *param_2 = (char)*(undefined4 *)(param_1 + 0xc0);
        param_3 = param_3 + -1;
        param_2 = param_2 + 1;
        if (param_3 == 1) {
          memw();
          memw();
          *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | (uint)&DAT_00010000;
        }
      }
      if (param_3 != 0) goto LAB_00210ffb;
    }
    if (bVar1) {
      if ((param_4 & 4) == 0) {
        iVar4 = I3C_MasterGetState(param_1);
        while (iVar4 != 0) {
          iVar4 = I3C_MasterGetState(param_1);
        }
      }
      return (undefined *)0x0;
    }
  } while( true );
}


// ===== I3C_MasterSend @ 002110e4 (283 bytes)

/* fsl_i3c.c order [inference] */

int I3C_MasterSend(int param_1,byte *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  for (; param_3 != 0; param_3 = param_3 - 2) {
    memw();
    uVar5 = *(uint *)(param_1 + 0x60);
    do {
      memw();
      uVar4 = *(uint *)(param_1 + 0xac);
      uVar2 = I3C_MasterGetErrorStatusFlags(param_1);
      iVar3 = I3C_MasterCheckAndClearError(param_1,uVar2);
      if (iVar3 != 0) {
        return iVar3;
      }
    } while ((2 << 0x20 - (0x20 - ((uVar5 & 0xc000000) >> 0x1a))) -
             ((uVar4 & (uint)&DAT_001f0000) >> 0x10) < 2);
    bVar1 = *param_2;
    if (param_3 < 3) {
      if ((param_4 & 8) == 0) {
        memw();
        *(uint *)(param_1 + 0xb4) = (uint)bVar1;
      }
      else {
        memw();
        *(uint *)(param_1 + 0xbc) = (uint)CONCAT11(param_2[1],bVar1);
      }
    }
    else if ((param_4 & 8) == 0) {
      memw();
      *(uint *)(param_1 + 0xb0) = (uint)bVar1;
    }
    else {
      memw();
      *(uint *)(param_1 + 0xb8) = (uint)CONCAT11(param_2[1],bVar1);
    }
    param_2 = param_2 + 2;
  }
  iVar3 = I3C_MasterWaitForTxReady(param_1,0);
  if ((iVar3 == 0) && ((param_4 & 4) == 0)) {
    iVar3 = I3C_MasterGetState(param_1);
    if (iVar3 == 4) {
      I3C_MasterEmitRequest(param_1,6);
      return 0;
    }
    iVar3 = I3C_MasterEmitStop(param_1,1);
    return iVar3;
  }
  return iVar3;
}


// ===== I3C_MasterProcessDAA @ 00211204 (404 bytes)

/* fsl_i3c.c order [inference] */

undefined * I3C_MasterProcessDAA(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_40;
  undefined1 local_3c;
  undefined1 uStack_3b;
  byte bStack_3a;
  byte bStack_39;
  uint uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  byte *pbStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  bStack_39 = 0xff;
  bStack_3a = 0xff;
  local_3c = 0xff;
  uStack_3b = 0xff;
  uStack_40 = 0xffffffff;
  puVar2 = (undefined *)I3C_CheckForBusyBus(param_1);
  if (puVar2 != (undefined *)0x0) {
    return puVar2;
  }
  I3C_MasterClearErrorStatusFlags(param_1,&DAT_001f061c);
  memw();
  *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
  uVar3 = I3C_MasterGetEnabledInterrupts(param_1);
  I3C_MasterDisableInterrupts(param_1,uVar3);
  uStack_34 = uVar3;
  I3C_MasterEmitRequest(param_1,4);
  uStack_30 = param_3 - 1;
  pbStack_2c = &DAT_00238e40;
  uStack_28 = 0;
  uStack_24 = 0;
  do {
    do {
      memw();
      uVar5 = *(uint *)(param_1 + 0x88);
      memw();
      uVar6 = (*(uint *)(param_1 + 0xac) & 0x1f000000) >> 0x18;
      uStack_38 = uVar6;
      uVar3 = I3C_MasterGetErrorStatusFlags(param_1);
      puVar2 = (undefined *)I3C_MasterCheckAndClearError(param_1,uVar3);
      if (puVar2 != (undefined *)0x0) {
        return puVar2;
      }
      if (((uVar5 & 0x800) != 0) && (uVar6 != 0)) {
        memw();
        *(char *)((int)&uStack_40 + uStack_24) = (char)*(undefined4 *)(param_1 + 0xc0);
        uStack_24 = uStack_24 + 1 & 0xff;
      }
    } while ((uVar5 & 0x200) == 0);
    memw();
    *(undefined4 *)(param_1 + 0x88) = 0x200;
    iVar4 = I3C_MasterGetState(param_1);
    if ((iVar4 == 5) && (memw(), (*(uint *)(param_1 + 0x88) & 0x10) != 0)) {
      if ((uStack_30 < uStack_28) || (uVar6 = uStack_28 + 1, 10 < uVar6)) {
        return &DAT_00001ee8;
      }
      pbStack_2c[2] = bStack_39;
      pbStack_2c[3] = bStack_3a;
      bVar1 = *param_2;
      *pbStack_2c = bVar1;
      *(uint *)(pbStack_2c + 8) =
           (uint)CONCAT11(local_3c,uStack_3b) |
           (uStack_40 >> 0x10) << 0x18 | (uStack_40 >> 0x18) << 0x10;
      *(ushort *)(pbStack_2c + 4) = CONCAT11((undefined1)uStack_40,uStack_40._1_1_) >> 1;
      memw();
      param_2 = param_2 + 1;
      *(uint *)(param_1 + 0xb0) = (uint)bVar1;
      I3C_MasterEmitRequest(param_1,4);
      uStack_24 = 0;
      pbStack_2c = pbStack_2c + 0x14;
      uStack_28 = uVar6;
    }
    if ((uVar5 & 0x400) != 0) {
      I3C_MasterClearErrorStatusFlags(param_1,&DAT_001f061c);
      memw();
      *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
      I3C_MasterEnableInterrupts(param_1,uStack_34);
      return (undefined *)0x0;
    }
  } while( true );
}


// ===== I3C_MasterTransferBlocking @ 0021139c (493 bytes)

/* fsl_i3c.c order [inference] */

undefined * I3C_MasterTransferBlocking(int param_1,uint *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_2[2];
  iVar1 = I3C_MasterGetState(param_1);
  if ((iVar1 != 0) && (iVar1 != 3)) {
    return &DAT_00001edc;
  }
  memw();
  *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
  memw();
  memw();
  *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 3;
  I3C_MasterDisableInterrupts(param_1,&DAT_0008af00);
  if (param_2[7] != 2) {
    if (param_2[4] == 0) {
      uVar5 = param_2[2];
    }
    else {
      uVar5 = 0;
    }
  }
  if ((*param_2 & 1) == 0) {
    puVar3 = (undefined *)I3C_MasterStart(param_1,param_2[7],(char)param_2[1],uVar5);
    do {
      memw();
    } while ((*(uint *)(param_1 + 0xac) & (uint)&DAT_001f0000) != 0);
    memw();
    if ((*(uint *)(param_1 + 0x88) >> 0xd & 1) != 0) {
      memw();
      *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
      I3C_MasterEnableInterrupts(param_1,&DAT_0008af00);
      return &DAT_00001ee9;
    }
  }
  else {
    puVar3 = (undefined *)0x0;
  }
  if (param_2[4] == 0) {
    uVar5 = param_2[2];
  }
  else {
    iVar1 = param_2[4] - 1;
    if (iVar1 != -1) {
      uVar5 = iVar1 * 8;
      do {
        uVar4 = param_2[3] >> (uVar5 & 0x1f) & 0xff;
        puVar3 = (undefined *)I3C_MasterWaitForCtrlDone(param_1,1);
        if ((uVar5 == 0) && (((param_2[2] == 1 || (param_2[6] == 0)) && (param_2[7] != 2)))) {
          memw();
          *(uint *)(param_1 + 0xb4) = uVar4;
          puVar2 = (undefined *)I3C_MasterWaitForTxReady(param_1,0);
          puVar3 = (undefined *)0x0;
          if (puVar2 != (undefined *)0x0) {
            if (puVar2 == &DAT_00001ede) {
              I3C_MasterEmitStop(param_1,1);
            }
            memw();
            *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
            I3C_MasterEnableInterrupts(param_1,&DAT_0008af00);
            return puVar2;
          }
        }
        else {
          memw();
          *(uint *)(param_1 + 0xb0) = uVar4;
        }
        uVar5 = uVar5 - 8;
      } while (uVar5 != 0xfffffff8);
    }
    if (param_2[7] != 2) {
      uVar5 = param_2[2];
      if ((param_2[6] == 0) || (uVar5 != 1)) goto joined_r0x002114a4;
      puVar2 = (undefined *)I3C_MasterRepeatedStart(param_1,param_2[7],(char)param_2[1],1);
      puVar3 = (undefined *)0x0;
      if (puVar2 != (undefined *)0x0) {
        memw();
        *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
        I3C_MasterEnableInterrupts(param_1,&DAT_0008af00);
        return puVar2;
      }
    }
    uVar5 = param_2[2];
  }
joined_r0x002114a4:
  if ((uVar5 == 0) && (param_2[6] != 0)) {
    puVar3 = (undefined *)I3C_MasterSend(param_1,param_2[5],param_2[6],*param_2);
  }
  else if ((uVar5 == 1) && (param_2[6] != 0)) {
    puVar3 = (undefined *)I3C_MasterReceive(param_1,param_2[5],param_2[6],*param_2);
  }
  else if ((*param_2 & 4) == 0) {
    puVar3 = (undefined *)I3C_MasterEmitStop(param_1,1);
  }
  memw();
  *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
  I3C_MasterEnableInterrupts(param_1,&DAT_0008af00);
  return puVar3;
}


// ===== I3C_MasterTransferCreateHandle @ 00211590 (103 bytes)

/* fsl_i3c.c: handler 0x2117DC [inference] */

void I3C_MasterTransferCreateHandle(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  
  memset(param_2,0,0x4c);
  iVar1 = I3C_GetInstance(param_1);
  *(undefined4 *)(param_2 + 0x48) = param_4;
  *(undefined4 *)(param_2 + 0x44) = param_3[2];
  *(undefined4 *)(param_2 + 0x40) = param_3[1];
  *(undefined4 *)(param_2 + 0x3c) = *param_3;
  (&DAT_00238e38)[iVar1] = param_2;
  DAT_00238e30 = I3C_MasterTransferHandleIRQ;
  I3C_MasterClearErrorStatusFlags(param_1,&DAT_001f061c);
  memw();
  *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
  memw();
  memw();
  *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 3;
  I3C_MasterEnableInterrupts(param_1,&DAT_0008af00);
  return;
}


// ===== I3C_MasterTransferNonBlocking @ 002115f8 (325 bytes)

/* WARNING: Removing unreachable block (ram,0x002116da) */
/* fsl_i3c.c order [inference] */

undefined * I3C_MasterTransferNonBlocking(int param_1,char *param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = I3C_MasterGetState(param_1);
  if ((*param_2 != '\0') || ((iVar1 != 0 && (iVar1 != 3)))) {
    return &DAT_00001edc;
  }
  I3C_MasterDisableInterrupts(param_1,&DAT_0008af00);
  memcpy(param_2 + 8,param_3,0x24);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_3 + 0x18);
  memw();
  memw();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xffffff3f;
  memw();
  memw();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | (*(uint *)(param_3 + 0x20) & 3) << 6;
  I3C_MasterClearErrorStatusFlags(param_1,&DAT_001f061c);
  memw();
  *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
  memw();
  memw();
  iVar3 = *(int *)(param_2 + 0x24);
  iVar1 = *(int *)(param_2 + 0x10);
  *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 3;
  if ((iVar3 != 2) && (*(int *)(param_2 + 0x18) != 0)) {
    iVar1 = 0;
  }
  if ((*(uint *)(param_2 + 8) & 1) == 0) {
    if ((*(uint *)(param_2 + 8) & 2) == 0) {
      I3C_MasterStart(param_1,iVar3,param_2[0xc],iVar1);
    }
    else {
      I3C_MasterRepeatedStart(param_1,iVar3,param_2[0xc],iVar1);
    }
    cVar2 = '\x06';
    if (*(int *)(param_2 + 0x18) != 0) {
      cVar2 = '\x04';
    }
    *param_2 = cVar2;
    if ((*(int *)(param_2 + 4) == 1) && (iVar1 == 1)) {
      memw();
      memw();
      *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | (uint)&DAT_00010000;
    }
  }
  else {
    if (*(int *)(param_2 + 0x18) == 0) {
      if (iVar1 != 0) goto LAB_00211707;
      *param_2 = '\x06';
    }
    else {
      *param_2 = '\x04';
    }
    I3C_MasterTransferHandleIRQ(param_1,param_2);
  }
LAB_00211707:
  I3C_MasterEnableInterrupts(param_1,&DAT_0008af00);
  if (*(int *)(param_3 + 8) == 0) {
    I3C_MasterEnableInterrupts(param_1,&DAT_00001000);
    return (undefined *)0x0;
  }
  return (undefined *)0x0;
}


// ===== I3C_MasterTransferGetCount @ 00211748 (95 bytes)

/* fsl_i3c.c order [inference] */

undefined4 I3C_MasterTransferGetCount(undefined4 param_1,char *param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == (int *)0x0) {
    return 4;
  }
  if (*param_2 != '\0') {
    uVar2 = I3C_MasterGetEnabledInterrupts(param_1);
    I3C_MasterDisableInterrupts(param_1,uVar2);
    iVar3 = *(int *)(param_2 + 4);
    cVar1 = *param_2;
    iVar4 = *(int *)(param_2 + 0x20);
    I3C_MasterEnableInterrupts(param_1,uVar2);
    if ((cVar1 != '\0') && (cVar1 != '\x04')) {
      if (cVar1 != '\x06') {
        *param_3 = iVar4;
        return 0;
      }
      *param_3 = iVar4 - iVar3;
      return 0;
    }
    *param_3 = 0;
    return 0;
  }
  *param_3 = 0;
  return 6;
}


// ===== I3C_MasterTransferAbort @ 002117a8 (49 bytes)

/* fsl_i3c.c order [inference] */

void I3C_MasterTransferAbort(int param_1,char *param_2)

{
  if (*param_2 != '\0') {
    I3C_MasterDisableInterrupts(param_1,&DAT_0008af00);
    memw();
    memw();
    *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 3;
    I3C_MasterStop(param_1);
    *param_2 = '\0';
    return;
  }
  return;
}


// ===== I3C_MasterTransferHandleIRQ @ 002117dc (1031 bytes)

/* fsl_i3c.c (state machine inlined) [inference] */

void I3C_MasterTransferHandleIRQ(int param_1,char *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  uint uVar14;
  int iStack_28;
  
  if (param_2 == (char *)0x0) {
    return;
  }
  memw();
  uVar6 = *(uint *)(param_1 + 0x60);
  memw();
  uVar5 = *(uint *)(param_1 + 0x88);
  uVar2 = I3C_MasterGetPendingInterrupts(param_1);
  memw();
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  iVar3 = I3C_MasterGetState(param_1);
  uVar2 = I3C_MasterGetErrorStatusFlags(param_1);
  puVar4 = (undefined *)I3C_MasterCheckAndClearError(param_1,uVar2);
  if (puVar4 == (undefined *)0x0) {
    if (((uVar5 & 0x80000) != 0) && (*(code **)(param_2 + 0x3c) != (code *)0x0)) {
      (**(code **)(param_2 + 0x3c))(param_1,*(undefined4 *)(param_2 + 0x48));
    }
    if (((uVar5 >> 8 & 1) != 0) && (*(int *)(param_2 + 0x24) != 1)) {
      *param_2 = '\x02';
    }
    if ((iVar3 == 7) || (iVar3 == 6)) {
      *param_2 = '\x01';
      cVar7 = '\x01';
    }
    else {
      cVar7 = *param_2;
    }
    if (cVar7 == '\0') {
      return;
    }
    memw();
    memw();
    iStack_28 = (2 << 0x20 - (0x20 - ((uVar6 & 0xc000000) >> 0x1a))) -
                ((*(uint *)(param_1 + 0xac) & (uint)&DAT_001f0000) >> 0x10);
    uVar10 = uVar5 & 0x400;
    uVar6 = (*(uint *)(param_1 + 0xac) & 0x1f000000) >> 0x18;
LAB_002118f2:
    do {
      while( true ) {
        if (cVar7 == '\x02') {
          I3C_MasterStart(param_1,0,0x7e,0);
          cVar7 = '\x03';
          *param_2 = '\x03';
          bVar1 = false;
          goto LAB_00211940;
        }
        if (cVar7 == '\x03') {
          I3C_MasterEmitStop(param_1,0);
          cVar7 = '\0';
          *param_2 = '\0';
          bVar1 = false;
          goto LAB_00211940;
        }
        if (cVar7 != '\x01') break;
        if (iVar3 == 6) {
          uVar2 = I3C_GetIBIType(param_1);
          *(undefined4 *)(param_2 + 0x38) = uVar2;
          if (*(code **)(param_2 + 0x40) == (code *)0x0) {
            memw();
            memw();
            *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xffffff38 | 0x43;
          }
          else {
            (**(code **)(param_2 + 0x40))(param_1,param_2,uVar2,2);
          }
        }
        if (uVar6 == 0) {
          if (uVar10 != 0) {
            uVar2 = I3C_GetIBIType(param_1);
            puVar4 = &DAT_00001ee9;
            *(undefined4 *)(param_2 + 0x38) = uVar2;
            param_2[0x2c] = (byte)(uVar5 >> 0x18) & 0x7f;
          }
LAB_00211bc0:
          cVar7 = *param_2;
          bVar1 = false;
          goto LAB_00211940;
        }
        iVar8 = *(int *)(param_2 + 0x30);
        if ((iVar8 == 0) && (*(code **)(param_2 + 0x40) != (code *)0x0)) {
          (**(code **)(param_2 + 0x40))(param_1,param_2,0,1);
          iVar8 = *(int *)(param_2 + 0x30);
        }
        memw();
        uVar2 = *(undefined4 *)(param_1 + 0xc0);
        uVar6 = uVar6 - 1;
        if (iVar8 != 0) {
          iVar9 = *(int *)(param_2 + 0x34);
          *(int *)(param_2 + 0x34) = iVar9 + 1;
          *(char *)(iVar9 + iVar8) = (char)uVar2;
        }
        cVar7 = *param_2;
      }
      if (cVar7 == '\x04') {
        I3C_MasterEnableInterrupts(param_1,&DAT_00001000);
        iStack_28 = iStack_28 + -1;
        if (iStack_28 == -1) goto LAB_00211bc0;
        uVar11 = *(uint *)(param_2 + 0x18);
        if (uVar11 < 2) {
          if (uVar11 == 1) {
            iVar8 = *(int *)(param_2 + 0x10);
            param_2[0x18] = '\0';
            param_2[0x19] = '\0';
            param_2[0x1a] = '\0';
            param_2[0x1b] = '\0';
            if ((iVar8 == 1) || (*(int *)(param_2 + 0x20) == 0)) {
              memw();
              *(uint *)(param_1 + 0xb4) = *(uint *)(param_2 + 0x14) & 0xff;
              *param_2 = '\b';
              cVar7 = '\b';
            }
            else {
              *param_2 = '\x06';
              cVar7 = '\x06';
              memw();
              *(uint *)(param_1 + 0xb0) = *(uint *)(param_2 + 0x14) & 0xff;
            }
            if ((*(int *)(param_2 + 0x24) != 2) && (iVar8 == 1)) {
              *param_2 = '\x05';
              cVar7 = '\x05';
            }
          }
          else {
            cVar7 = *param_2;
          }
        }
        else {
          *(uint *)(param_2 + 0x18) = uVar11 - 1;
          memw();
          *(uint *)(param_1 + 0xb0) = *(uint *)(param_2 + 0x14) >> ((uVar11 - 1) * 8 & 0x1f) & 0xff;
          cVar7 = *param_2;
        }
        goto LAB_002118f2;
      }
      if (cVar7 == '\x05') {
        if (uVar10 != 0) {
          *param_2 = '\x06';
          puVar4 = (undefined *)
                   I3C_MasterRepeatedStart(param_1,*(undefined4 *)(param_2 + 0x24),param_2[0xc],1);
          if (*(int *)(param_2 + 4) == 1) {
            memw();
            memw();
            *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | (uint)&DAT_00010000;
          }
          cVar7 = *param_2;
        }
        goto LAB_00211b64;
      }
      if (cVar7 == '\x06') {
        puVar12 = *(undefined1 **)(param_2 + 0x1c);
        if (*(int *)(param_2 + 0x10) == 0) {
          iStack_28 = iStack_28 + -1;
          if (iStack_28 == -1) goto LAB_00211b64;
          uVar11 = *(uint *)(param_2 + 0x20);
          pbVar13 = *(byte **)(param_2 + 0x1c);
          uVar14 = (uint)*pbVar13;
          if (uVar11 < 2) {
            memw();
            *(uint *)(param_1 + 0xb4) = uVar14;
          }
          else {
            memw();
            *(uint *)(param_1 + 0xb0) = uVar14;
          }
          *(uint *)(param_2 + 0x20) = uVar11 - 1;
          *(byte **)(param_2 + 0x1c) = pbVar13 + 1;
        }
        else {
          uVar6 = uVar6 - 1;
          if (uVar6 == 0xffffffff) goto LAB_00211b64;
          memw();
          *puVar12 = (char)*(undefined4 *)(param_1 + 0xc0);
          *(undefined1 **)(param_2 + 0x1c) = puVar12 + 1;
        }
        iVar8 = *(int *)(param_2 + 4) + -1;
        *(int *)(param_2 + 4) = iVar8;
        cVar7 = *param_2;
        if (iVar8 == 0) {
          *param_2 = '\b';
          cVar7 = '\b';
        }
        if ((iVar8 == 1) && (*(int *)(param_2 + 0x10) == 1)) {
          memw();
          memw();
          *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | (uint)&DAT_00010000;
        }
        goto LAB_002118f2;
      }
      if (cVar7 == '\b') {
        if (uVar10 == 0) goto LAB_00211b64;
        *param_2 = '\a';
        cVar7 = '\a';
        goto LAB_002118f2;
      }
    } while (cVar7 != '\a');
    if ((*(uint *)(param_2 + 8) & 4) == 0) {
      if (iStack_28 != 0) {
        if (*(int *)(param_2 + 0x24) == 2) {
          I3C_MasterEmitRequest(param_1,6);
        }
        else {
          I3C_MasterEmitStop(param_1,0);
        }
        cVar7 = *param_2;
        goto LAB_0021193e;
      }
LAB_00211b64:
      bVar1 = false;
    }
    else {
LAB_0021193e:
      bVar1 = true;
    }
LAB_00211940:
    if (cVar7 == '\0') {
      return;
    }
    if (bVar1) goto LAB_00211839;
  }
  else if (*param_2 == '\0') {
    return;
  }
  if (puVar4 == (undefined *)0x0) {
    return;
  }
LAB_00211839:
  if ((puVar4 == &DAT_00001ede) || (puVar4 == &DAT_00001ee9)) {
    I3C_MasterEmitStop(param_1,0);
  }
  I3C_MasterDisableInterrupts(param_1,&DAT_00001000);
  *param_2 = '\0';
  if ((puVar4 == &DAT_00001ee9) && (*(code **)(param_2 + 0x40) != (code *)0x0)) {
    (**(code **)(param_2 + 0x40))(param_1,param_2,*(undefined4 *)(param_2 + 0x38),0);
  }
  if (*(code **)(param_2 + 0x44) != (code *)0x0) {
    (**(code **)(param_2 + 0x44))(param_1,param_2,puVar4,*(undefined4 *)(param_2 + 0x48));
  }
  return;
}


// ===== I3C_SlaveGetDefaultConfig @ 00211bec (58 bytes)

/* fsl_i3c.c order [inference] */

void I3C_SlaveGetDefaultConfig(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 0xe) = 1;
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)((int)param_1 + 0xf) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  ae_s16i_n(0x11b,param_1,2);
  return;
}


// ===== I3C_SlaveInit @ 00211c28 (444 bytes)

/* fsl_i3c.c order [inference] */

void I3C_SlaveInit(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  memw();
  uVar12 = *(uint *)(param_1 + 4);
  iVar10 = I3C_GetInstance(param_1);
  uVar11 = *(uint *)(&DAT_00200404 + iVar10 * 4);
  uVar13 = uVar11 >> 8 & 0xff;
  if (uVar13 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
  }
  else if (uVar13 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
  }
  else if (uVar13 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
  }
  else if (uVar13 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
  }
  else if (uVar13 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
  }
  else if (uVar13 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - (uVar11 & 0x1f));
  }
  RESET_PeripheralReset(*(undefined4 *)(&DAT_00200408 + iVar10 * 4));
  bVar1 = param_2[0x12];
  bVar5 = param_2[1];
  bVar2 = param_2[0x10];
  bVar6 = param_2[0xf];
  bVar3 = param_2[4];
  bVar4 = param_2[0x11];
  bVar7 = param_2[0xe];
  bVar8 = *param_2;
  memw();
  memw();
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) & 0xffff8000;
  uVar11 = ae_l16ui_n(param_2,2);
  memw();
  memw();
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | uVar11 & 0x7fff;
  if (bVar3 == 0) {
    memw();
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 8);
  }
  memw();
  memw();
  bVar9 = param_2[0xd];
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xff0000ff;
  memw();
  memw();
  *(uint *)(param_1 + 0x70) =
       *(uint *)(param_1 + 0x70) | (uint)param_2[0xc] << 8 | (uint)bVar9 << 0x10;
  memw();
  *(uint *)(param_1 + 4) =
       (uint)bVar8 | uVar12 & 0x100fce0 |
       (bVar6 & 1) << 1 | (bVar1 & 1) << 2 |
       (bVar2 & 1) << 3 | (bVar7 & 1) << 4 |
       (uint)bVar5 << 0x19 | (param_3 / (uint)&DAT_000f4240 & 0xff) << 0x10 |
       (bVar4 & 1) << 9 | (bVar3 & 1) << 8;
  return;
}


// ===== I3C_SlaveDeinit @ 00211de8 (248 bytes)

/* fsl_i3c.c order [inference] */

void I3C_SlaveDeinit(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = I3C_GetInstance(param_1);
  RESET_PeripheralReset(*(undefined4 *)(&DAT_00200408 + iVar1 * 4));
  uVar2 = *(uint *)(&DAT_00200404 + iVar1 * 4);
  uVar3 = uVar2 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238f10)[iVar1] = 0;
    return;
  }
  if (uVar3 == 1) {
    memw();
    CLKCTL0_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238f10)[iVar1] = 0;
    return;
  }
  if (uVar3 == 2) {
    memw();
    CLKCTL0_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238f10)[iVar1] = 0;
    return;
  }
  if (uVar3 != 3) {
    if (uVar3 == 4) {
      memw();
      CLKCTL1_PSCCTL1_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      (&DAT_00238f10)[iVar1] = 0;
      return;
    }
    if (uVar3 != 5) {
      (&DAT_00238f10)[iVar1] = 0;
      return;
    }
    memw();
    CLKCTL1_PSCCTL2_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    (&DAT_00238f10)[iVar1] = 0;
    return;
  }
  memw();
  CLKCTL1_PSCCTL0_CLR = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  (&DAT_00238f10)[iVar1] = 0;
  return;
}


// ===== I3C_SlaveGetActivityState @ 00211ee0 (36 bytes)

/* fsl_i3c.c: table 0x200450 [inference] */

undefined4 I3C_SlaveGetActivityState(int param_1)

{
  uint uVar1;
  
  memw();
  uVar1 = (*(uint *)(param_1 + 8) & 0x30000000) >> 0x1c;
  if (uVar1 < 4) {
    return *(undefined4 *)(&DAT_00200450 + uVar1 * 4);
  }
  return 0;
}


// ===== I3C_SlaveRequestEvent @ 00211f04 (26 bytes)

/* fsl_i3c.c order [inference] */

void I3C_SlaveRequestEvent(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0xc) = param_2 & 3 | *(uint *)(param_1 + 0xc) & 0xfffffffc;
  return;
}


// ===== I3C_SlaveRequestIBIWithData @ 00211f20 (69 bytes)

/* fsl_i3c.c order [inference] */

void I3C_SlaveRequestIBIWithData(int param_1,int param_2,byte *param_3,uint param_4)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0xc) & 0xffff00fc | (uint)*param_3 << 8 | 1;
  if (param_4 < 2) {
    memw();
    *(uint *)(param_1 + 0xc) = uVar1;
    return;
  }
  *(byte **)(param_2 + 0x30) = param_3 + 1;
  *(uint *)(param_2 + 0x34) = param_4 - 1;
  memw();
  *(uint *)(param_1 + 0xc) = uVar1;
  return;
}

