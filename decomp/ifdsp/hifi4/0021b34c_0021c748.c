// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0021b34c @ 0021b34c (503 bytes)

int * FUN_0021b34c(int param_1,int param_2,uint param_3,undefined4 param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code **ppcVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  char *pcStack_60;
  char *pcStack_5c;
  code *apcStack_58 [2];
  int local_50 [4];
  undefined2 uStack_40;
  uint uStack_3c;
  char **ppcStack_38;
  
  uVar11 = param_2 - 0x800;
  if ((uVar11 & 3) == 0) {
    bVar1 = true;
    if (0x7ff < uVar11) {
      bVar1 = false;
    }
  }
  else {
    bVar1 = true;
    if (0x7ff < (uVar11 & 0xfffffffc)) goto LAB_0021b36c;
  }
  if (bVar1) {
    return (int *)0x0;
  }
LAB_0021b36c:
  if (((param_3 < 2) && (param_1 != 0)) && (param_5 != (int *)0x0)) {
    FUN_0021aafc(param_5,0,0xf4);
    iVar2 = FUN_0021aa90();
    if (iVar2 == 0) {
      uVar8 = param_1 + 0x800;
      if ((uVar8 & 3) != 0) {
        uVar8 = (uVar8 & 0xfffffffc) + 4;
      }
      param_5[5] = uVar8;
      uStack_3c = param_3 << 1;
      param_5[6] = uVar11 >> 9;
      param_5[7] = uVar11 >> 9;
      ppcStack_38 = &pcStack_60;
      param_5[8] = (int)&PTR_FUN_002008d0;
      pcStack_60 = "rx_vq";
      apcStack_58[0] = FUN_0021ae00;
      ppcVar5 = apcStack_58;
      pcStack_5c = "tx_vq";
      piVar4 = local_50;
      piVar6 = param_5 + 9;
      apcStack_58[1] = FUN_0021aed4;
      uVar11 = 0;
      do {
        local_50[3] = 0x10;
        local_50[2] = 0x400;
        uStack_40 = 2;
        if (uVar11 == 0) {
          local_50[2] = 0;
        }
        local_50[2] = param_1 + local_50[2];
        FUN_0021aafc(local_50[2],0,0x4e);
        uVar9 = ae_zext16(uStack_3c | uVar11 & 1);
        iVar2 = FUN_0021b854(uVar9,*ppcStack_38,local_50 + 2,*ppcVar5,FUN_0021af90,piVar4,piVar6);
        if (iVar2 != 0) {
          return (int *)0x0;
        }
        FUN_0021bc54(*piVar4);
        FUN_0021bb54(*piVar4);
        ppcVar5 = ppcVar5 + 1;
        piVar6 = piVar6 + 0x1a;
        *(int **)(*piVar4 + 100) = param_5;
        ppcStack_38 = ppcStack_38 + 1;
        uVar11 = uVar11 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar11 != 2);
      iVar2 = FUN_0021ab80(param_5 + 3,1);
      if (iVar2 == 0) {
        param_5[1] = local_50[1];
        piVar4 = local_50;
        *param_5 = local_50[0];
        iVar2 = 0;
        do {
          if ((*(short *)(*piVar4 + 0x52) != 0) && (uVar11 = param_5[7], uVar11 != 0)) {
            uVar8 = 0;
            do {
              iVar7 = param_5[6];
              if (iVar7 == 0) {
LAB_0021b537:
                do {
                    /* WARNING: Do nothing block with infinite loop */
                } while( true );
              }
              param_5[6] = iVar7 + -1;
              iVar7 = param_5[5] + (uVar11 - iVar7) * 0x200;
              if (iVar7 == 0) goto LAB_0021b537;
              FUN_0021aafc(iVar7,0,0x200);
              iVar10 = *piVar4;
              if (*param_5 == iVar10) {
                iVar3 = FUN_0021b938(iVar10,iVar7,0x200);
                iVar2 = 0;
              }
              else {
                iVar3 = iVar2;
                if (param_5[1] == iVar10) {
                  iVar2 = FUN_0021bae0(iVar10,iVar7,0x200);
                  iVar3 = iVar2;
                }
              }
              if (iVar3 != 0) {
                FUN_0021ab8c(param_5[3]);
                return (int *)0x0;
              }
              uVar8 = uVar8 + 1;
            } while ((uVar8 < *(ushort *)(*piVar4 + 0x52)) && (uVar11 = param_5[7], uVar8 < uVar11))
            ;
          }
          piVar4 = piVar4 + 1;
          if (piVar4 == local_50 + 2) {
            platform_init_interrupt(*(undefined2 *)(*param_5 + 0x50));
            platform_init_interrupt(*(undefined2 *)(param_5[1] + 0x50));
            FUN_0021abe8(*(undefined2 *)(*param_5 + 0x50));
            FUN_0021abe8(*(undefined2 *)(param_5[1] + 0x50));
            param_5[4] = 1;
            FUN_0021abdc(*(undefined2 *)(*param_5 + 0x50));
            FUN_0021abdc(*(undefined2 *)(param_5[1] + 0x50));
            FUN_0021bb84(*param_5);
            return param_5;
          }
        } while( true );
      }
    }
  }
  return (int *)0x0;
}


// ===== rpmsg_lite_remote_init @ 0021b544 (285 bytes)

/* called by Thread_Ipc; init_interrupt x2, disable/enable x2 [inference] */

int * rpmsg_lite_remote_init(int param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  code **ppcVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcStack_50;
  char *pcStack_4c;
  code *apcStack_48 [2];
  int local_40 [4];
  undefined2 uStack_30;
  uint uStack_2c;
  char **ppcStack_28;
  
  if (((param_2 < 2) && (param_1 != 0)) && (param_4 != (int *)0x0)) {
    FUN_0021aafc(param_4,0,0xf4);
    iVar1 = FUN_0021aa90();
    if (iVar1 == 0) {
      ppcVar5 = apcStack_48;
      piVar4 = local_40;
      uVar7 = param_1 + 0x800;
      pcStack_50 = "tx_vq";
      pcStack_4c = "rx_vq";
      apcStack_48[0] = FUN_0021aed4;
      apcStack_48[1] = FUN_0021ae00;
      ppcStack_28 = &pcStack_50;
      param_4[8] = (int)&PTR_FUN_002008e0;
      piVar3 = param_4 + 9;
      uStack_2c = param_2 << 1;
      uVar2 = 0;
      if ((uVar7 & 3) != 0) {
        uVar7 = (uVar7 & 0xfffffffc) + 4;
      }
      param_4[5] = uVar7;
      do {
        uStack_30 = 2;
        local_40[3] = 0x10;
        uVar6 = ae_zext16(uStack_2c | uVar2 & 1);
        local_40[2] = param_1;
        iVar1 = FUN_0021b854(uVar6,*ppcStack_28,local_40 + 2,*ppcVar5,FUN_0021af90,piVar4,piVar3);
        if (iVar1 != 0) {
          return (int *)0x0;
        }
        ppcVar5 = ppcVar5 + 1;
        ppcStack_28 = ppcStack_28 + 1;
        piVar3 = piVar3 + 0x1a;
        *(int **)(*piVar4 + 100) = param_4;
        uVar2 = uVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar2 != 2);
      iVar1 = FUN_0021ab80(param_4 + 3,1);
      if (iVar1 == 0) {
        param_4[1] = local_40[0];
        *param_4 = local_40[1];
        platform_init_interrupt(*(undefined2 *)(local_40[1] + 0x50));
        platform_init_interrupt(*(undefined2 *)(param_4[1] + 0x50));
        FUN_0021abe8(*(undefined2 *)(*param_4 + 0x50));
        FUN_0021abe8(*(undefined2 *)(param_4[1] + 0x50));
        param_4[4] = 0;
        FUN_0021abdc(*(undefined2 *)(*param_4 + 0x50));
        FUN_0021abdc(*(undefined2 *)(param_4[1] + 0x50));
        return param_4;
      }
    }
  }
  return (int *)0x0;
}


// ===== FUN_0021b664 @ 0021b664 (104 bytes)

undefined4 FUN_0021b664(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0xffffec75;
  }
  if (((*param_1 != 0) && (param_1[1] != 0)) && (param_1[3] != 0)) {
    FUN_0021abe8(*(undefined2 *)(*param_1 + 0x50));
    FUN_0021abe8(*(undefined2 *)(param_1[1] + 0x50));
    param_1[4] = 0;
    FUN_0021abdc(*(undefined2 *)(*param_1 + 0x50));
    FUN_0021abdc(*(undefined2 *)(param_1[1] + 0x50));
    platform_deinit_interrupt(*(undefined2 *)(*param_1 + 0x50));
    platform_deinit_interrupt(*(undefined2 *)(param_1[1] + 0x50));
    FUN_0021ba3c(*param_1);
    FUN_0021ba3c(param_1[1]);
    FUN_0021ab8c(param_1[3]);
    FUN_0021aac0();
    return 0;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0021b6d0 @ 0021b6d0 (99 bytes)

undefined4 FUN_0021b6d0(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  if (param_4 == (undefined4 *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((code *)*param_4 != (code *)0x0) {
    if (param_2 != 0x28) {
      return 0;
    }
    (*(code *)*param_4)(*(undefined4 *)(param_1 + 0x20),param_1,*(undefined4 *)(param_1 + 0x24),
                        param_4[1]);
    return 0;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== rpmsg_ns_bind @ 0021b734 (46 bytes)

/* creates an endpoint (no callers found) [inference] */

int rpmsg_ns_bind(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (param_4 != 0)) {
    *(undefined4 *)(param_4 + 0x24) = param_3;
    *(int *)(param_4 + 0x20) = param_2;
    *(int *)(param_4 + 0x2c) = param_4 + 0x20;
    uVar1 = rpmsg_lite_create_ept(param_1,0x35,FUN_0021b6d0,param_4 + 0x20,param_4);
    *(undefined4 *)(param_4 + 0x28) = uVar1;
    return param_4 + 0x28;
  }
  return 0;
}


// ===== FUN_0021b768 @ 0021b768 (16 bytes)

undefined4 FUN_0021b768(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021b034(param_1,*param_2);
  return uVar1;
}


// ===== rpmsg_ns_announce @ 0021b778 (57 bytes)

/* sends via rpmsg_lite_send, error 0xFFFFEC75 (no callers found) [inference] */

undefined4 rpmsg_ns_announce(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 auStack_50 [32];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  if ((param_3 != 0) && (param_2 != (undefined4 *)0x0)) {
    FUN_0021ab2c(auStack_50,param_3,0x20);
    uStack_30 = *param_2;
    uStack_2c = param_4;
    uVar1 = rpmsg_lite_send(param_1,param_2,0x35,auStack_50,0x28,0xffffffff);
    return uVar1;
  }
  return 0xffffec75;
}


// ===== FUN_0021b7c0 @ 0021b7c0 (148 bytes)

/* WARNING: Removing unreachable block (ram,0x0021b7d1) */

undefined4
FUN_0021b7c0(undefined2 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
            undefined4 param_5,int *param_6)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  memw();
  memw();
  iVar2 = FUN_0021aae4(0x68);
  if (iVar2 != 0) {
    FUN_0021aafc(iVar2,0,0x68);
    FUN_0021ab2c(iVar2,param_2,0x20);
    *(undefined4 *)(iVar2 + 0x34) = param_5;
    *(undefined4 *)(iVar2 + 0x30) = param_4;
    *(undefined2 *)(iVar2 + 0x50) = param_1;
    uVar1 = *(ushort *)(param_3 + 2);
    uVar3 = (uint)uVar1;
    *(uint *)(iVar2 + 0x40) = uVar3;
    *(ushort *)(iVar2 + 0x52) = uVar1;
    iVar4 = param_3[1];
    *(int *)(iVar2 + 0x24) = iVar4;
    iVar5 = *param_3;
    *(int *)(iVar2 + 0x44) = iVar5;
    *(int *)(iVar2 + 0x2c) = iVar5;
    *(uint *)(iVar2 + 0x48) = iVar5 + uVar3 * 0x10;
    *(uint *)(iVar2 + 0x4c) = -iVar4 & iVar4 + uVar3 * 0x12 + iVar5 + 3;
    *(uint *)(iVar2 + 0x28) = uVar3 * 8 + (-iVar4 & uVar3 * 0x12 + iVar4 + 7) + 0xe;
    *param_6 = iVar2;
    memw();
    return 0;
  }
  return 0xfffff444;
}


// ===== FUN_0021b854 @ 0021b854 (140 bytes)

/* WARNING: Removing unreachable block (ram,0x0021b865) */

undefined4
FUN_0021b854(undefined2 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
            undefined4 param_5,int *param_6,int param_7)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  memw();
  memw();
  FUN_0021aafc(param_7,0,0x68);
  FUN_0021ab2c(param_7,param_2,0x20);
  *(undefined4 *)(param_7 + 0x34) = param_5;
  *(undefined4 *)(param_7 + 0x30) = param_4;
  uVar1 = *(ushort *)(param_3 + 2);
  uVar2 = (uint)uVar1;
  *(uint *)(param_7 + 0x40) = uVar2;
  *(ushort *)(param_7 + 0x52) = uVar1;
  iVar3 = param_3[1];
  *(int *)(param_7 + 0x24) = iVar3;
  iVar4 = *param_3;
  *(int *)(param_7 + 0x44) = iVar4;
  *(undefined2 *)(param_7 + 0x50) = param_1;
  *(int *)(param_7 + 0x2c) = iVar4;
  *(uint *)(param_7 + 0x48) = iVar4 + uVar2 * 0x10;
  *(uint *)(param_7 + 0x4c) = -iVar3 & iVar3 + uVar2 * 0x12 + iVar4 + 3;
  *(uint *)(param_7 + 0x28) = uVar2 * 8 + (-iVar3 & uVar2 * 0x12 + iVar3 + 7) + 0xe;
  *param_6 = param_7;
  memw();
  return 0;
}


// ===== FUN_0021b8e8 @ 0021b8e8 (77 bytes)

/* WARNING: Removing unreachable block (ram,0x0021b8f9) */

undefined4 FUN_0021b8e8(int param_1,undefined2 param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  memw();
  memw();
  uVar2 = ae_l16ui_n(*(int *)(param_1 + 0x48),2);
  iVar3 = ae_zext16(uVar2 & (uint)(&DAT_0000ffff + *(ushort *)(param_1 + 0x52)));
  *(undefined2 *)(iVar3 * 2 + *(int *)(param_1 + 0x48) + 4) = param_2;
  FUN_0021ab60();
  uVar4 = ae_l16ui_n(*(int *)(param_1 + 0x48),2);
  sVar1 = *(short *)(param_1 + 0x56);
  *(short *)(*(int *)(param_1 + 0x48) + 2) = (short)uVar4 + 1;
  *(short *)(param_1 + 0x56) = sVar1 + 1;
  memw();
  return 0;
}


// ===== FUN_0021b938 @ 0021b938 (123 bytes)

/* WARNING: Removing unreachable block (ram,0x0021b949) */

undefined4 FUN_0021b938(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  memw();
  memw();
  uVar4 = *(ushort *)(param_1 + 0x58);
  puVar7 = (undefined4 *)(*(int *)(param_1 + 0x44) + (uint)uVar4 * 0x10);
  uVar5 = FUN_0021ab68(param_2);
  puVar7[2] = param_3;
  iVar8 = *(int *)(param_1 + 0x48);
  sVar2 = *(short *)(param_1 + 0x58);
  *puVar7 = uVar5;
  uVar3 = *(ushort *)(param_1 + 0x52);
  uVar1 = *(ushort *)(iVar8 + 2);
  puVar7[1] = 0;
  *(undefined2 *)(puVar7 + 3) = 2;
  iVar6 = ae_zext16((uint)uVar1 & (uint)(&DAT_0000ffff + uVar3));
  *(short *)(param_1 + 0x58) = sVar2 + 1;
  *(ushort *)(iVar6 * 2 + iVar8 + 4) = uVar4;
  FUN_0021ab60();
  uVar5 = ae_l16ui_n(*(int *)(param_1 + 0x48),2);
  sVar2 = *(short *)(param_1 + 0x56);
  *(short *)(*(int *)(param_1 + 0x48) + 2) = (short)uVar5 + 1;
  *(short *)(param_1 + 0x56) = sVar2 + 1;
  memw();
  return 0;
}


// ===== FUN_0021b9b4 @ 0021b9b4 (95 bytes)

undefined4 FUN_0021b9b4(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    if ((uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2) != (uint)*(ushort *)(param_1 + 0x5a)) {
      iVar1 = ae_zext16((uint)*(ushort *)(param_1 + 0x5a) &
                        (uint)(&DAT_0000ffff + *(ushort *)(param_1 + 0x52)));
      iVar1 = iVar1 * 8 + *(int *)(param_1 + 0x4c);
      FUN_0021ab58();
      uVar2 = (uint)*(ushort *)(iVar1 + 4);
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(iVar1 + 8);
      }
      if (param_3 != 0) {
        ae_s16i_n(uVar2,param_3,0);
      }
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x44) + uVar2 * 0x10);
      *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + 1;
      uVar3 = FUN_0021ab74(uVar3);
      return uVar3;
    }
  }
  return 0;
}


// ===== FUN_0021ba14 @ 0021ba14 (15 bytes)

undefined4 FUN_0021ba14(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x44) + param_2 * 0x10 + 8);
}


// ===== FUN_0021ba24 @ 0021ba24 (24 bytes)

void FUN_0021ba24(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x2c) != 0) {
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    FUN_0021aaf0(param_1);
  }
  return;
}


// ===== FUN_0021ba3c @ 0021ba3c (21 bytes)

void FUN_0021ba3c(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    return;
  }
  return;
}


// ===== FUN_0021ba54 @ 0021ba54 (84 bytes)

undefined4 FUN_0021ba54(int param_1,undefined4 param_2,undefined4 *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x5c);
  if ((uint)*(ushort *)(*(int *)(param_1 + 0x48) + 2) == (uint)uVar1) {
    return 0;
  }
  iVar3 = ae_zext16((uint)uVar1 & (uint)(&DAT_0000ffff + *(ushort *)(param_1 + 0x52)));
  *(ushort *)(param_1 + 0x5c) = uVar1 + 1;
  ae_s16i_n((uint)*(ushort *)(iVar3 * 2 + *(int *)(param_1 + 0x48) + 4),param_2,0);
  FUN_0021ab58();
  iVar3 = ae_l16ui_n(param_2,0);
  uVar2 = FUN_0021ab74(*(undefined4 *)(*(int *)(param_1 + 0x44) + iVar3 * 0x10));
  iVar3 = ae_l16ui_n(param_2,0);
  *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x44) + iVar3 * 0x10 + 8);
  return uVar2;
}


// ===== FUN_0021baa8 @ 0021baa8 (54 bytes)

undefined4 FUN_0021baa8(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(ushort *)(param_1 + 0x52) < param_2) {
    return 0xfffff441;
  }
  uVar1 = ae_l16ui_n(*(int *)(param_1 + 0x4c),2);
  iVar2 = ae_zext16(uVar1 & (uint)(&DAT_0000ffff + *(ushort *)(param_1 + 0x52)));
  iVar2 = iVar2 * 8 + *(int *)(param_1 + 0x4c);
  *(uint *)(iVar2 + 4) = param_2;
  *(undefined4 *)(iVar2 + 8) = param_3;
  FUN_0021ab60();
  uVar3 = ae_l16ui_n(*(int *)(param_1 + 0x4c),2);
  *(short *)(*(int *)(param_1 + 0x4c) + 2) = (short)uVar3 + 1;
  return 0;
}


// ===== FUN_0021bae0 @ 0021bae0 (98 bytes)

undefined4 FUN_0021bae0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ushort uVar5;
  int iVar6;
  
  uVar5 = *(ushort *)(param_1 + 0x58);
  uVar1 = (uint)uVar5;
  iVar6 = *(int *)(param_1 + 0x44);
  if (param_2 != 0) {
    uVar3 = FUN_0021ab68(param_2);
    puVar4 = (undefined4 *)(iVar6 + uVar1 * 0x10);
    puVar4[1] = 0;
    puVar4[2] = param_3;
    *puVar4 = uVar3;
    *(undefined2 *)(puVar4 + 3) = 2;
    uVar5 = uVar5 + 1;
  }
  uVar2 = ae_l16ui_n(*(int *)(param_1 + 0x4c),2);
  iVar6 = ae_zext16(uVar2 & (uint)(&DAT_0000ffff + *(ushort *)(param_1 + 0x52)));
  *(ushort *)(param_1 + 0x58) = uVar5;
  iVar6 = iVar6 * 8 + *(int *)(param_1 + 0x4c);
  *(uint *)(iVar6 + 4) = uVar1;
  *(undefined4 *)(iVar6 + 8) = param_3;
  FUN_0021ab60();
  uVar3 = ae_l16ui_n(*(int *)(param_1 + 0x4c),2);
  *(short *)(*(int *)(param_1 + 0x4c) + 2) = (short)uVar3 + 1;
  return 0;
}


// ===== FUN_0021bb44 @ 0021bb44 (16 bytes)

undefined4 FUN_0021bb44(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021bcd8(param_1,0);
  return uVar1;
}


// ===== FUN_0021bb54 @ 0021bb54 (46 bytes)

void FUN_0021bb54(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x48);
  if ((*(uint *)(param_1 + 0x20) >> 1 & 1) != 0) {
    *(short *)(*(int *)(param_1 + 0x40) * 2 + iVar2 + 4) =
         (*(short *)(param_1 + 0x5a) - *(short *)(param_1 + 0x52)) + -1;
    return;
  }
  uVar1 = ae_l16ui_n(iVar2,0);
  ae_s16i_n(uVar1 | 1,iVar2,0);
  return;
}


// ===== FUN_0021bb84 @ 0021bb84 (90 bytes)

void FUN_0021bb84(int param_1)

{
  uint uVar1;
  bool bVar2;
  
  FUN_0021ab50();
  if ((*(uint *)(param_1 + 0x20) >> 1 & 1) == 0) {
    uVar1 = ae_l16ui_n(*(int *)(param_1 + 0x4c),0);
    bVar2 = false;
    if ((uVar1 & 1) == 0) {
      bVar2 = true;
    }
  }
  else {
    uVar1 = ae_zext16(((uint)*(ushort *)(*(int *)(param_1 + 0x48) + 2) -
                      *(int *)(*(int *)(param_1 + 0x40) * 8 + *(int *)(param_1 + 0x4c) + 4)) + -1);
    bVar2 = uVar1 < *(ushort *)(param_1 + 0x56);
  }
  if ((bVar2) && (*(code **)(param_1 + 0x34) != (code *)0x0)) {
    (**(code **)(param_1 + 0x34))(param_1);
  }
  *(undefined2 *)(param_1 + 0x56) = 0;
  return;
}


// ===== FUN_0021bbe0 @ 0021bbe0 (62 bytes)

void FUN_0021bbe0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    return;
  }
  uVar4 = (uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2);
  uVar3 = ae_zext16(uVar4 - *(ushort *)(param_1 + 0x5a));
  uVar2 = ae_l16ui_n(*(int *)(param_1 + 0x48),0);
  uVar1 = ae_l16ui_n(*(int *)(param_1 + 0x4c),0);
  FUN_0022bff0("VQ: %s - size=%d; used=%d; queued=%d; desc_head_idx=%d; avail.idx=%d; used_cons_idx=%d; used.idx=%d; avail.flags=0x%x; used.flags=0x%x\r\n"
               ,param_1,*(undefined2 *)(param_1 + 0x52),uVar3,*(undefined2 *)(param_1 + 0x56),
               *(undefined2 *)(param_1 + 0x58),*(undefined2 *)(*(int *)(param_1 + 0x48) + 2),
               (uint)*(ushort *)(param_1 + 0x5a),uVar4,uVar2,uVar1);
  return;
}


// ===== FUN_0021bc20 @ 0021bc20 (50 bytes)

undefined4 FUN_0021bc20(int param_1)

{
  int iVar1;
  
  if ((uint)*(ushort *)(*(int *)(param_1 + 0x48) + 2) == (uint)*(ushort *)(param_1 + 0x5c)) {
    return 0;
  }
  iVar1 = ae_zext16((uint)*(ushort *)(param_1 + 0x5c) &
                    (uint)(&DAT_0000ffff + *(ushort *)(param_1 + 0x52)));
  return *(undefined4 *)
          (*(int *)(param_1 + 0x44) +
           (uint)*(ushort *)(iVar1 * 2 + *(int *)(param_1 + 0x48) + 4) * 0x10 + 8);
}


// ===== FUN_0021bc54 @ 0021bc54 (130 bytes)

ulonglong FUN_0021bc54(uint param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = *(ushort *)(param_1 + 0x52) - 1;
  iVar5 = *(int *)(param_1 + 0x44);
  if (uVar3 != 0) {
    iVar2 = 1;
    iVar4 = iVar5;
    if ((uVar3 & 7) != 0) {
      *(undefined2 *)(iVar5 + 0xe) = 1;
      iVar4 = iVar5 + 0x10;
      iVar2 = 2;
    }
    if (uVar3 >> 3 != 0) {
      sVar1 = (short)iVar2;
      *(short *)(iVar4 + 0xe) = sVar1;
      *(short *)(iVar4 + 0x1e) = sVar1 + 1;
      *(short *)(iVar4 + 0x2e) = sVar1 + 2;
      *(short *)(iVar4 + 0x3e) = sVar1 + 3;
      *(short *)(iVar4 + 0x4e) = sVar1 + 4;
      *(short *)(iVar4 + 0x5e) = sVar1 + 5;
      *(short *)(iVar4 + 0x6e) = sVar1 + 6;
      *(short *)(iVar4 + 0x7e) = sVar1 + 7;
      iVar2 = iVar2 + 8;
      iVar4 = iVar4 + 0x80;
    }
    *(undefined2 *)(iVar5 + uVar3 * 0x10 + 0xe) = 0x8000;
    return CONCAT44(iVar4,iVar2);
  }
  *(undefined2 *)(*(int *)(param_1 + 0x44) + 0xe) = 0x8000;
  return (ulonglong)param_1;
}


// ===== FUN_0021bcd8 @ 0021bcd8 (73 bytes)

undefined4 FUN_0021bcd8(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x48);
  if ((*(uint *)(param_1 + 0x20) >> 1 & 1) == 0) {
    uVar2 = ae_l16ui_n(iVar1,0);
    ae_s16i_n(uVar2 & (uint)&DAT_0000fffe,iVar1,0);
  }
  else {
    *(short *)(*(int *)(param_1 + 0x40) * 2 + iVar1 + 4) =
         *(short *)(param_1 + 0x5a) + (short)param_2;
  }
  FUN_0021ab50();
  uVar2 = ae_zext16((uint)*(ushort *)(*(int *)(param_1 + 0x4c) + 2) -
                    (uint)*(ushort *)(param_1 + 0x5a));
  if (param_2 < uVar2) {
    return 1;
  }
  return 0;
}


// ===== FUN_0021bd24 @ 0021bd24 (16 bytes)

void FUN_0021bd24(int param_1)

{
  if ((param_1 != 0) && (*(code **)(param_1 + 0x30) != (code *)0x0)) {
    (**(code **)(param_1 + 0x30))(param_1);
  }
  return;
}


// ===== ipc_handle_msg @ 0021bd40 (139 bytes)

/* checks version byte, dispatch on category (+8): 0 general, 1 audio, else error at +0x14; if type
   (+0xB) == request, reply with rpmsg_lite_send under mutex */

undefined4 ipc_handle_msg(undefined4 *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  
  cVar1 = *(char *)(param_2 + 0xb);
  if ((*(char *)(param_2 + 9) != '\x01') || (*(char *)(param_2 + 10) != '\x02')) {
    return 0xffffffff;
  }
  cVar2 = *(char *)(param_2 + 8);
  if (cVar2 == '\0') {
    handle_msg_general(param_1,param_2);
  }
  else if (cVar2 == '\x01') {
    FUN_0021be20(param_1,param_2);
  }
  else if (cVar2 == '\x03') {
    handle_msg_audio(param_1,param_2);
  }
  else {
    *(undefined1 *)(param_2 + 0xb) = 2;
    *(undefined4 *)(param_2 + 0x14) = 3;
  }
  if (cVar1 == '\0') {
    *(undefined1 *)(param_2 + 0xb) = 1;
    xos_mutex_lock(param_1 + 0x3ac);
    rpmsg_lite_send(*param_1,param_1[1],0x28,param_2,0x98,0);
    xos_mutex_unlock(param_1 + 0x3ac);
    return 0;
  }
  return 0;
}


// ===== handle_msg_general @ 0021bdcc (81 bytes)

/* category 0: command (+0xC); system info fills param[] with 9 component versions (0x00020000,
   0x00010003, ...) */

undefined4 handle_msg_general(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0xc) != '\0') {
    *(undefined1 *)(param_2 + 0xb) = 2;
    *(undefined4 *)(param_2 + 0x14) = 3;
    return 0;
  }
  *(undefined **)(param_2 + 0x18) = &DAT_00020000;
  *(undefined **)(param_2 + 0x1c) = &DAT_00010003;
  *(undefined **)(param_2 + 0x24) = &DAT_0004000a;
  *(undefined **)(param_2 + 0x28) = &DAT_00030011;
  *(undefined **)(param_2 + 0x2c) = &DAT_00030006;
  *(undefined **)(param_2 + 0x30) = &DAT_0001000c;
  *(undefined **)(param_2 + 0x34) = &DAT_00010008;
  *(undefined **)(param_2 + 0x38) = &DAT_00010004;
  *(undefined **)(param_2 + 0x20) = &DAT_00040000;
  *(undefined **)(param_2 + 0x3c) = &DAT_00010005;
  return 0;
}


// ===== FUN_0021be20 @ 0021be20 (51 bytes)

undefined4 FUN_0021be20(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0xc) != '\0') {
    *(undefined1 *)(param_2 + 0xb) = 2;
    *(undefined4 *)(param_2 + 0x14) = 3;
    return 0;
  }
  if ((*(int *)(param_2 + 0x18) != 0) && (*(int *)(param_2 + 0x18) != 1)) {
    *(undefined1 *)(param_2 + 0xb) = 2;
    *(undefined4 *)(param_2 + 0x14) = 2;
    return 0;
  }
  *(undefined4 *)(param_2 + 0x14) = 0;
  return 0;
}


// ===== handle_msg_audio @ 0021be54 (37 bytes)

/* category 1 (M33 prints it as Mute on/off): command (+0xC), result in +0x14/+0x18 */

undefined4 handle_msg_audio(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0xc) != '\0') {
    *(undefined1 *)(param_2 + 0xb) = 2;
    *(undefined4 *)(param_2 + 0x14) = 3;
    return 0;
  }
  *(undefined4 *)(param_2 + 0x18) = 1;
  *(undefined4 *)(param_2 + 0x14) = 0;
  return 0;
}


// ===== regfile_set_defaults @ 0021be80 (479 bytes)

/* writes the default of every DSP register (all but 0, 1, 0x4000) */

void regfile_set_defaults(void)

{
  xthal_set_region_attribute(&DAT_20070000,&DAT_00010000,2,0);
  DAT_20078002 = 1;
  DAT_200700c4 = 1;
  DAT_20070074 = 1;
  DAT_2007005e = 1;
  DAT_20070018 = 1;
  DAT_200700ce = 0xff;
  DAT_20070060 = 0xff;
  DAT_20070064 = 0xffa;
  DAT_20070062 = 0xffa;
  DAT_20070066 = 0xc;
  DAT_200700cc = 3000;
  DAT_200700c6 = 0xe7;
  DAT_200700b0 = 0x2c4;
  DAT_20070076 = 0x2c4;
  DAT_20070014 = 0x22;
  DAT_200700d0 = 0;
  DAT_200700c2 = 0;
  DAT_200700c0 = 0;
  DAT_200700ba = 0;
  DAT_200700b8 = 0;
  DAT_200700ae = 0;
  DAT_200700ac = 0;
  DAT_200700aa = 0;
  DAT_200700a8 = 0;
  DAT_200700a6 = 0;
  DAT_200700a4 = 0;
  DAT_200700a2 = 0;
  DAT_200700a0 = 0;
  DAT_2007009e = 0;
  DAT_2007009c = 0;
  DAT_2007009a = 0;
  DAT_20070098 = 0;
  DAT_20070096 = 0;
  DAT_20070094 = 0;
  DAT_20070092 = 0;
  DAT_20070090 = 0;
  DAT_2007008e = 0;
  DAT_2007008c = 0;
  DAT_2007008a = 0;
  DAT_20070088 = 0;
  DAT_20070086 = 0;
  DAT_20070084 = 0;
  DAT_20070082 = 0;
  DAT_20070080 = 0;
  DAT_20070072 = 0;
  DAT_20070070 = 0;
  DAT_2007006e = 0;
  DAT_2007006c = 0;
  DAT_2007006a = 0;
  DAT_20070068 = 0;
  DAT_2007005c = 0;
  DAT_2007005a = 0;
  DAT_20070058 = 0;
  DAT_20070056 = 0;
  DAT_20070054 = 0;
  DAT_20070052 = 0;
  DAT_20070050 = 0;
  DAT_2007004e = 0;
  DAT_2007004c = 0;
  DAT_2007004a = 0;
  DAT_20070046 = 0;
  DAT_20070044 = 0;
  DAT_20070040 = 0;
  DAT_20070026 = 0;
  DAT_20070024 = 0;
  DAT_20070020 = 0;
  DAT_2007001e = 0;
  DAT_2007001c = 0;
  DAT_2007001a = 0;
  DAT_20070010 = 0x2031;
  DAT_2007000c = 0;
  DAT_20070008 = 0;
  DAT_20070006 = 0;
  DAT_20070004 = 0;
  DAT_20070042 = 0xffb0;
  DAT_20070022 = 0xffd4;
  DAT_20070012 = 2;
  DAT_2007401e = 0;
  DAT_2007401c = 0;
  DAT_2007401a = 0;
  DAT_20074018 = 0;
  DAT_20074016 = 0;
  DAT_20074014 = 0;
  DAT_20074012 = 0;
  DAT_20074010 = 0;
  DAT_2007400e = 0;
  DAT_2007400c = 0;
  DAT_2007400a = 0;
  DAT_20074008 = 0;
  DAT_20074006 = 0;
  DAT_20074004 = 0;
  DAT_20074002 = 0;
  DAT_20074000 = 0;
  DAT_2007800a = 0;
  DAT_2007800c = 0;
  DAT_20078010 = 0;
  DAT_20078012 = 0;
  DAT_20078014 = 0;
  DAT_2007801e = 0;
  DAT_2007802a = 0;
  DAT_2007802e = 0;
  DAT_20078032 = 0;
  DAT_20078034 = 0;
  DAT_2007803c = 0;
  DAT_20078040 = 0;
  DAT_20078042 = 0;
  DAT_20078044 = 0;
  DAT_2007804a = 0;
  DAT_2007804c = 0;
  DAT_20078030 = 100;
  DAT_20078046 = 100;
  DAT_20078038 = 10;
  DAT_2007803e = 10;
  DAT_2007800e = 0x3a;
  DAT_20078016 = 8;
  DAT_20078036 = 0x2c4;
  DAT_2007801c = 2;
  DAT_2007801a = 0x200;
  DAT_20078018 = 0x400;
  DAT_20078022 = 0x80;
  DAT_20078028 = 0xffe8;
  DAT_2007802c = 0xfffa;
  DAT_2007803a = 300;
  DAT_20078024 = 0x4000;
  DAT_20078026 = 1000;
  return;
}


// ===== tx_gpio_to_reg4004 @ 0021c060 (44 bytes)

/* reg 0x4004 = (f()<<2) | (GPIO P0_21<<1) | GPIO P0_22; called from Thread_Main loop 0x0021C360 */

void tx_gpio_to_reg4004(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  
  sVar3 = regfile_gpio_sel();
  memw();
  bVar1 = DAT_40100015;
  memw();
  bVar2 = DAT_40100016;
  DAT_20078008 = (ushort)bVar2 | sVar3 << 2 | (ushort)bVar1 << 1;
  return;
}


// ===== regfile_capture_init @ 0021c090 (39 bytes)

/* capture block table 0x2390E0 = {0x2007E000, 0x2007F000} (regs 0x7000/0x7800), memset 4 KB each */

void regfile_capture_init(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_002390e0;
  DAT_002390e0 = &DAT_2007e000;
  DAT_002390e4 = &DAT_2007f000;
  do {
    memset(*puVar1,0,&DAT_00001000);
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)0x2390e8);
  return;
}


// ===== regfile_capture_clear @ 0021c0b8 (28 bytes)

/* memset(block[idx], 0, 0x1000) */

void regfile_capture_clear(uint param_1)

{
  if (1 < param_1) {
    return;
  }
  memset((&DAT_002390e0)[param_1],0,&DAT_00001000);
  return;
}


// ===== regfile_capture_set_ctrl @ 0021c0d4 (20 bytes)

/* *(u16 *)block[idx] = v (control word); no caller */

void regfile_capture_set_ctrl(uint param_1,undefined4 param_2)

{
  if (1 < param_1) {
    return;
  }
  ae_s16i_n(param_2,(&DAT_002390e0)[param_1],0);
  return;
}


// ===== regfile_capture_append @ 0021c0e8 (77 bytes)

/* append u32 if ctrl bit 0, count at +2 (max 0x3FE), wrap if ctrl bit 1; no caller */

void regfile_capture_append(uint param_1,undefined4 param_2)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 < 2) {
    puVar1 = (ushort *)(&DAT_002390e0)[param_1];
    uVar3 = ae_l16ui_n(puVar1,0);
    uVar4 = ae_l16ui_n(puVar1,2);
    if (((uVar3 & 1) != 0) && (uVar4 < 0x3ff)) {
      *(undefined4 *)(puVar1 + uVar4 * 2 + 2) = param_2;
      iVar2 = ae_l16ui_n(puVar1,2);
      uVar3 = ae_zext16(iVar2 + 1);
      if (0x3fe < uVar3) {
        if ((*puVar1 & 2) != 0) {
          uVar3 = 0;
        }
        ae_s16i_n(uVar3,puVar1,2);
        return;
      }
      ae_s16i_n(uVar3,puVar1,2);
      return;
    }
  }
  return;
}


// ===== FUN_0021c140 @ 0021c140 (211 bytes)

void FUN_0021c140(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 in_CCOUNT;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  memset(&DAT_00239100,0,&DAT_00001008);
  uVar4 = 0x40c90fdb;
  puVar6 = &DAT_0023a110;
  uVar8 = const_s(0);
  uVar7 = ae_mov(uVar8);
  do {
    uVar5 = ae_l32_i(0x3db2b8c3);
    uVar3 = (ulonglong)(uint)((float)uVar7 + (float)uVar5);
    uVar2 = olt_s(uVar4,uVar3);
    if (SUB21(uVar2,0)) {
      do {
        uVar7 = ae_l32_i(0xc0c90fdb);
        uVar3 = (ulonglong)(uint)((float)uVar3 + (float)uVar7);
        uVar2 = olt_s(uVar4,uVar3);
      } while (SUB21(uVar2,0));
    }
    uVar2 = olt_s(uVar3,uVar8);
    if (SUB21(uVar2,0)) {
      do {
        uVar3 = (ulonglong)(uint)((float)uVar3 + (float)uVar4);
        uVar2 = olt_s(uVar3,uVar8);
      } while (SUB21(uVar2,0));
      ae_s32_l_i(uVar3);
    }
    uVar1 = ae_s32_l_i(uVar3);
    uVar4 = ae_l32_i(uVar1);
    cosf_();
    uVar7 = ae_l32_i(uVar1);
    uVar1 = ae_s32_l_ip(uVar4);
    *puVar6 = uVar1;
    puVar6 = puVar6 + 1;
    uVar4 = ae_l32_i(0x40c90fdb);
    uVar8 = ae_l32_i(0);
  } while (puVar6 != (undefined4 *)&DAT_0023b110);
  DAT_002390f0 = rsr_ccount(in_CCOUNT);
  FUN_00233670(&DAT_00239100,&DAT_0023a110,FLOAT_ARRAY_00201900,1,0x400);
  FUN_00218640(&DAT_0023b110,&DAT_00239100,0x400,1);
  DAT_002390f4 = rsr_ccount(in_CCOUNT);
  DAT_002390f8 = DAT_002390f4 - DAT_002390f0;
  return;
}


// ===== FUN_0021c21c @ 0021c21c (5 bytes)

void FUN_0021c21c(void)

{
  return;
}


// ===== cpu_load_to_regs_2000 @ 0021c230 (298 bytes)

void cpu_load_to_regs_2000(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint local_f0 [4];
  undefined1 auStack_e0 [4];
  undefined2 uStack_dc;
  undefined1 auStack_c8 [200];
  
  local_f0[0] = 8;
  iVar1 = xos_get_cpu_load(auStack_e0,local_f0,1);
  if (iVar1 == 0) {
    if (8 < (int)local_f0[0]) {
      local_f0[0] = 8;
    }
    puVar3 = &DAT_00002000;
    if (0 < (int)local_f0[0]) {
      uVar6 = local_f0[0] & 7;
      puVar2 = auStack_e0;
      if ((uVar6 != 0) && ((uVar6 == 1 || (uVar6 != 0)))) {
        puVar2 = auStack_c8;
        DAT_20074000 = uStack_dc;
        puVar3 = (undefined *)0x2001;
      }
      if ((int)local_f0[0] >> 3 != 0) {
        uVar4 = *(undefined4 *)(puVar2 + 0x1c);
        *(short *)(&DAT_20070000 + (int)puVar3 * 2) = (short)*(undefined4 *)(puVar2 + 4);
        uVar5 = *(undefined4 *)(puVar2 + 0x34);
        *(short *)(&DAT_20070000 + (int)(puVar3 + 1) * 2) = (short)uVar4;
        uVar4 = *(undefined4 *)(puVar2 + 0x4c);
        *(short *)(&DAT_20070000 + (int)(puVar3 + 2) * 2) = (short)uVar5;
        uVar5 = *(undefined4 *)(puVar2 + 100);
        *(short *)(&DAT_20070000 + (int)(puVar3 + 3) * 2) = (short)uVar4;
        uVar4 = *(undefined4 *)(puVar2 + 0x7c);
        *(short *)(&DAT_20070000 + (int)(puVar3 + 4) * 2) = (short)uVar5;
        uVar5 = *(undefined4 *)(puVar2 + 0x94);
        *(short *)(&DAT_20070000 + (int)(puVar3 + 5) * 2) = (short)uVar4;
        uVar4 = *(undefined4 *)(puVar2 + 0xac);
        *(short *)(&DAT_20070000 + (int)(puVar3 + 6) * 2) = (short)uVar5;
        *(short *)(&DAT_20070000 + (int)(puVar3 + 7) * 2) = (short)uVar4;
        if (0 < ((int)local_f0[0] >> 3) + -1) {
          uVar4 = *(undefined4 *)(puVar2 + 0xdc);
          *(short *)(&DAT_20070000 + (int)(puVar3 + 8) * 2) = (short)*(undefined4 *)(puVar2 + 0xc4);
          uVar5 = *(undefined4 *)(puVar2 + 0xf4);
          *(short *)(&DAT_20070000 + (int)(puVar3 + 9) * 2) = (short)uVar4;
          uVar4 = *(undefined4 *)(puVar2 + 0x10c);
          *(short *)(&DAT_20070000 + (int)(puVar3 + 10) * 2) = (short)uVar5;
          uVar5 = *(undefined4 *)(puVar2 + 0x124);
          *(short *)(&DAT_20070000 + (int)(puVar3 + 0xb) * 2) = (short)uVar4;
          uVar4 = *(undefined4 *)(puVar2 + 0x13c);
          *(short *)(&DAT_20070000 + (int)(puVar3 + 0xc) * 2) = (short)uVar5;
          *(short *)(&DAT_20070000 + (int)(puVar3 + 0xd) * 2) = (short)uVar4;
          uVar4 = *(undefined4 *)(puVar2 + 0x16c);
          *(short *)(&DAT_20070000 + (int)(puVar3 + 0xe) * 2) =
               (short)*(undefined4 *)(puVar2 + 0x154);
          *(short *)(&DAT_20070000 + (int)(puVar3 + 0xf) * 2) = (short)uVar4;
        }
        return;
      }
    }
  }
  return;
}


// ===== Thread_Main_entry @ 0021c360 (53 bytes)

/* XOS thread "Thread_Main" (entry from literal 0x206CD0) */

void Thread_Main_entry(void)

{
  uint uVar1;
  
  audio_i2s_fc3_fc4_fc5_init();
  uVar1 = 0;
  do {
    do {
      __udivdi3(DAT_002cb680 * 100,(int)((ulonglong)DAT_002cb680 * 100 >> 0x20),1000,0);
      xos_thread_sleep();
      tx_gpio_to_reg4004();
      uVar1 = ae_zext16(uVar1 + 1);
    } while (uVar1 < 10);
    cpu_load_to_regs_2000();
    uVar1 = 0;
  } while( true );
}


// ===== ipc_ept_rx_cb @ 0021c398 (26 bytes)

/* rpmsg ept callback: if len == 0x98 xos_msgq_put(msg); return RL_RELEASE (NXP my_ept_read_cb) */

undefined4 ipc_ept_rx_cb(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 != 0x98) {
    return 0;
  }
  xos_msgq_put(param_4,param_1);
  return 0;
}


// ===== Thread_Ipc_entry @ 0021c3b4 (224 bytes)

/* XOS thread "Thread_Ipc": MU_Init(MUB), msgq, rpmsg_lite_remote_init(0x20020000), wait link up,
   ept 0x1E, MU flag/SEMA42 boot handshake, then loop xos_msgq_get -> handle_srtm_msg */

void Thread_Ipc_entry(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_1d0 [244];
  undefined1 auStack_dc [32];
  undefined1 auStack_bc [188];
  
  MU_Init(&DAT_40111000);
  FUN_0022700c(param_1 + 0x3ac,0,0);
  uVar2 = FUN_0022ba40(0x618);
  param_1[2] = uVar2;
  xos_msgq_create(uVar2,10,0x98,0);
  uVar2 = rpmsg_lite_remote_init(&DAT_20020000,1,0,auStack_1d0);
  *param_1 = uVar2;
  iVar3 = rpmsg_lite_is_link_up();
  while (iVar3 == 0) {
    iVar3 = rpmsg_lite_is_link_up(*param_1);
  }
  uVar2 = rpmsg_lite_create_ept(*param_1,0x1e,ipc_ept_rx_cb,param_1[2],auStack_dc);
  param_1[1] = uVar2;
  memw();
  uVar1 = DAT_40111060;
  while ((uVar1 & 7) != 1) {
    memw();
    uVar1 = DAT_40111060;
  }
  MU_SetFlags(&DAT_40111000,1);
  memw();
  uVar1 = DAT_40111060;
  while ((uVar1 & 7) != 2) {
    memw();
    uVar1 = DAT_40111060;
  }
  SEMA42_Init(&DAT_40112000);
  SEMA42_Lock(&DAT_40112000,0,3);
  MU_SetFlags(&DAT_40111000,3);
  do {
    xos_msgq_get(param_1[2],auStack_bc);
    ipc_handle_msg(param_1,auStack_bc);
  } while( true );
}


// ===== xos_create_main_ipc_threads @ 0021c498 (193 bytes)

/* XOS main: zero DMA area 0x20060000..0x200631E0, regfile_init_defaults, clock globals (24 MHz,
   18.432 MHz), creates Thread_Main, Thread_Ipc, others, xos_start */

undefined4 xos_create_main_ipc_threads(void)

{
  xthal_set_region_attribute(&DAT_20060000,0x31e0,2,0);
  xthal_set_region_attribute(&DAT_20060000,0,2,0);
  regfile_set_defaults();
  regfile_capture_init();
  DAT_002cb680 = 594000000;
  xos_start_system_timer(0xffffffff,0);
  memw();
  DAT_00238420 = 24000000;
  memw();
  DAT_0023841c = 0x1194000;
  create_rx_tx_path_threads();
  fc1_spi_dma_init();
  FUN_0021c140();
  xos_thread_create(&DAT_0023f920,0,Thread_Main_entry,0,"Thread_Main",&DAT_00241170,&DAT_00001398,4,
                    0,0);
  xos_thread_create(&DAT_0023fdd8,0,Thread_Ipc_entry,&DAT_00240290,"Thread_Ipc",&DAT_00242510,
                    &DAT_00002000,0xd,0,0);
  create_Thread_Spi();
  xos_start(0);
  return 0;
}


// ===== FUN_0021c560 @ 0021c560 (54 bytes)

undefined4 * FUN_0021c560(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  
  if ((param_4 != 0) && ((param_4 == 1 || (param_4 != 0)))) {
    *param_1 = *param_3;
    puVar1 = param_3 + 1;
    param_3 = param_3 + 2;
    *param_2 = *puVar1;
  }
  return param_3;
}


// ===== FUN_0021c598 @ 0021c598 (52 bytes)

undefined4 * FUN_0021c598(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_4 != 0) && ((param_4 == 1 || (param_4 != 0)))) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1[1] = *param_3;
  }
  return param_2;
}


// ===== regfile_gpio_sel @ 0021c5cc (42 bytes)

/* (reg 0xC & 0xF000) == 0x1000 -> GPIO P0_4 byte */

undefined1 regfile_gpio_sel(void)

{
  undefined1 uVar1;
  
  if ((DAT_20070018 & 0xf000) != 0x1000) {
    memw();
    uVar1 = DAT_40100004;
    return uVar1;
  }
  memw();
  uVar1 = DAT_40100005;
  return uVar1;
}


// ===== FUN_0021c600 @ 0021c600 (15 bytes)

void FUN_0021c600(void)

{
  DAT_00244510 = 0;
  DAT_00244514 = 0;
  return;
}


// ===== apf_config @ 0021c610 (96 bytes)

/* reg 0x45 */

void apf_config(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_aed0;
  undefined *puVar4;
  
  uVar1 = ae_l16ui_n(&DAT_00244510,0);
  if (uVar1 != DAT_2007008a) {
    DAT_00244510._0_2_ = DAT_2007008a;
    puVar4 = (undefined *)(DAT_2007008a & 0xfff);
    if ((DAT_2007008a >> 0xc) - 1 < 4) {
      ae_s16i_n((uint)(DAT_2007008a >> 0xc),&DAT_00244510,2);
      if ((&DAT_0000176f < puVar4) || ((DAT_2007008a & 0xfff) != 0)) {
        iVar2 = (uint)(puVar4 < &DAT_0000176f) * (int)puVar4 +
                (uint)(puVar4 >= &DAT_0000176f) * (int)&DAT_0000176f;
      }
      else {
        iVar2 = 1;
      }
      uVar3 = ae_zext16(iVar2);
      i2f_scaled(uVar3,0);
      DAT_00244514 = ae_s32_l_i(in_aed0);
    }
    else {
      ae_s16i_n(0,&DAT_00244510,2);
    }
    apf_design_iir();
    apf_design_fir();
  }
  return;
}


// ===== apf_design_iir @ 0021c670 (215 bytes)

void apf_design_iir(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  ulonglong uVar5;
  float fVar6;
  undefined8 uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  
  iVar4 = ae_l16ui_n(&DAT_00244510,2);
  if (iVar4 != 1) {
    return;
  }
  uVar7 = ae_l32_i(DAT_00244514);
  uVar5 = (ulonglong)(uint)((float)uVar7 * 3.1415927 * 8.333333e-05);
  uVar12 = tanf_();
  uVar1 = ae_s32_l_i(uVar5);
  uVar7 = const_s(1);
  fVar11 = (float)uVar7;
  uVar7 = ae_mov(uVar5);
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar7 * (float)uVar7));
  divf_((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0x3d088889);
  uVar7 = ae_l32_i(uVar1);
  fVar6 = (float)uVar7;
  uVar7 = ae_l32_i(uVar2);
  fVar8 = (float)uVar7;
  uVar7 = ae_l32_i(0x3f800000);
  fVar9 = (float)uVar7;
  uVar7 = const_s(2);
  fVar3 = (fVar8 + -1.0) * (float)uVar7 * fVar11;
  uVar7 = ae_l32_i(0x3a83126f);
  fVar10 = (float)uVar7;
  DAT_0023683c = ae_s32_l_i((ulonglong)(uint)fVar3);
  DAT_00236834 = ae_s32_l_i((ulonglong)(uint)(fVar3 * fVar10));
  DAT_00236840 = ae_s32_l_i((ulonglong)(uint)((fVar6 * -0.033333335 + fVar9 + fVar8) * fVar11));
  DAT_00236830 = ae_s32_l_i((ulonglong)(uint)((fVar6 * 33.333336 + fVar9 + fVar8) * fVar11 * fVar10)
                           );
  DAT_00236838 = ae_s32_l_i((ulonglong)
                            (uint)((fVar6 * -33.333336 + fVar9 + fVar8) * fVar11 * fVar10));
  DAT_00244518 = iir_cascade_init(&DAT_00244520,1,&DAT_00236830,0);
  return;
}


// ===== apf_design_fir @ 0021c748 (207 bytes)

void apf_design_fir(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 *local_30;
  
  uVar5 = ae_l16ui_n(&DAT_00244510,2);
  if ((1 < uVar5) && (uVar5 < 5)) {
    iVar9 = uVar5 - 2;
    uVar10 = ae_l32_i(DAT_00244514);
    if (iVar9 == 0) {
      local_30 = &DAT_00203120;
    }
    else if (iVar9 == 1) {
      local_30 = &DAT_002035c0;
    }
    else if (iVar9 == 2) {
      local_30 = &DAT_002038e0;
    }
    iVar9 = *(int *)(&DAT_00203100 + iVar9 * 4);
    puVar3 = &DAT_00244560;
    if (0 < iVar9) {
      iVar4 = iVar9;
      if (-1 < iVar9 + -1) {
        iVar4 = iVar9 + -1;
      }
      uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar10 * 6.2831855 * 8.333333e-05));
      iVar7 = -(iVar4 >> 1);
      do {
        uVar8 = float_s(iVar7,0);
        uVar11 = ae_l32_i(uVar1);
        uVar10 = ae_l32_i(*local_30);
        uVar2 = ae_s32_l_i(uVar10);
        fVar6 = (float)uVar8 * (float)uVar11;
        cosf_();
        uVar10 = ae_l32_i(uVar2);
        uVar8 = ae_l32_i(&DAT_40000000);
        uVar2 = ae_s32_l_ip((ulonglong)(uint)(fVar6 * (float)uVar10 * (float)uVar8));
        *puVar3 = uVar2;
        puVar3 = puVar3 + 1;
        iVar7 = iVar7 + 1;
        local_30 = local_30 + 1;
      } while (iVar7 != iVar9 - (iVar4 >> 1));
    }
    DAT_0024451c = fir_init(&DAT_00244a00,iVar9,&DAT_00244560);
    return;
  }
  return;
}

