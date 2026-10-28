// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20101bbc @ 20101bbc (84 bytes)

void FUN_20101bbc(int param_1)

{
  if (param_1 != 0) {
    FUN_20100658(3,4,1,0);
    FUN_20100658(0xb,0xf,5,0);
    return;
  }
  FUN_2010087c(3,4);
  FUN_2010087c(0xb,0xf);
  return;
}


// ===== FUN_20101c10 @ 20101c10 (52 bytes)

void FUN_20101c10(uint param_1)

{
  undefined4 uVar1;
  
  FUN_20101bbc(param_1 & 0xff);
  if (param_1 != 0) {
    uVar1 = 0x400040;
  }
  else {
    uVar1 = 0x400000;
  }
  DAT_fcfe3110 = uVar1;
  if (param_1 != 0) {
    uVar1 = 0x40004000;
  }
  else {
    uVar1 = 0x40000000;
  }
  DAT_fcfe3128 = uVar1;
  return;
}


// ===== gpio_rx_reset @ 20101c5c (24 bytes)

/* P7_10 (RX_RESET per hardware.md) via PSR7 */

void gpio_rx_reset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x4000000;
  }
  else {
    uVar1 = 0x4000400;
  }
  DAT_fcfe311c = uVar1;
  return;
}


// ===== FUN_20101c74 @ 20101c74 (24 bytes)

void FUN_20101c74(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x80000;
  }
  else {
    uVar1 = 0x80008;
  }
  DAT_fcfe3110 = uVar1;
  return;
}


// ===== FUN_20101c8c @ 20101c8c (24 bytes)

void FUN_20101c8c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x200000;
  }
  else {
    uVar1 = 0x200020;
  }
  DAT_fcfe3120 = uVar1;
  return;
}


// ===== FUN_20101ca4 @ 20101ca4 (24 bytes)

void FUN_20101ca4(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x80000;
  }
  else {
    uVar1 = 0x80008;
  }
  DAT_fcfe3110 = uVar1;
  return;
}


// ===== FUN_20101cbc @ 20101cbc (24 bytes)

void FUN_20101cbc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x40000;
  }
  else {
    uVar1 = 0x40004;
  }
  DAT_fcfe312c = uVar1;
  return;
}


// ===== FUN_20101d14 @ 20101d14 (24 bytes)

void FUN_20101d14(void)

{
  DAT_fcfe3108 = 0x300000;
  DAT_fcfe3128 = 0x20000;
  return;
}


// ===== FUN_20101d2c @ 20101d2c (20 bytes)

void FUN_20101d2c(int param_1)

{
  if (param_1 != 0) {
    FUN_20101ca4(0);
    return;
  }
  return;
}


// ===== FUN_20101d70 @ 20101d70 (36 bytes)

void FUN_20101d70(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = 0x10001000;
  }
  else {
    uVar1 = 0x10000000;
  }
  DAT_fcfe311c = uVar1;
  if (param_1 == 0) {
    return;
  }
  itron_dly_tsk(1);
  return;
}


// ===== FUN_20101d94 @ 20101d94 (16 bytes)

uint FUN_20101d94(void)

{
  ushort uVar1;
  
  uVar1 = DAT_fcfe322c;
  return (uVar1 & 0x1f) >> 4;
}


// ===== FUN_20101dc4 @ 20101dc4 (40 bytes)

void FUN_20101dc4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0x1000000;
  }
  else {
    uVar2 = 0x1000100;
  }
  if (param_1 == 0) {
    uVar1 = 0x2000000;
  }
  else {
    uVar1 = 0x2000200;
  }
  DAT_fcfe3114 = uVar1 | uVar2;
  return;
}


// ===== FUN_20101dec @ 20101dec (276 bytes)

void FUN_20101dec(int param_1)

{
  if (param_1 != 0) {
    FUN_20100658(5,0,1);
    FUN_20100658(5,1,1);
    FUN_20100658(5,2,1);
    FUN_20100658(5,3,1);
    FUN_20100658(5,4,1);
    FUN_20100658(5,5,1);
    FUN_20100658(5,6,1);
    FUN_20100658(5,7,1);
    return;
  }
  FUN_20100414(5,0);
  FUN_20100414(5,1);
  FUN_20100414(5,2);
  FUN_20100414(5,3);
  FUN_20100414(5,4);
  FUN_20100414(5);
  FUN_20100414(5,6);
  FUN_20100414(5,7);
  return;
}


// ===== FUN_20101f44 @ 20101f44 (12 bytes)

void FUN_20101f44(void)

{
  FUN_20100414(1,0);
  return;
}


// ===== FUN_20101f50 @ 20101f50 (12 bytes)

void FUN_20101f50(void)

{
  FUN_2010087c(1,0);
  return;
}


// ===== FUN_20101f5c @ 20101f5c (24 bytes)

void FUN_20101f5c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x80000000;
  }
  else {
    uVar1 = 0x80008000;
  }
  DAT_fcfe3108 = uVar1;
  return;
}


// ===== FUN_20101f8c @ 20101f8c (24 bytes)

void FUN_20101f8c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x800000;
  }
  else {
    uVar1 = 0x800080;
  }
  DAT_fcfe3108 = uVar1;
  return;
}


// ===== FUN_20101fa4 @ 20101fa4 (76 bytes)

void FUN_20101fa4(int param_1,int param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_10 = 0xe0b0d0a;
  uStack_c = 0x8050904;
  local_8 = 0xc;
  if (param_1 != 0) {
    FUN_20100838();
    return;
  }
  FUN_20100414(6,*(undefined1 *)((int)&local_10 + param_2),&local_10);
  return;
}


// ===== FUN_20102040 @ 20102040 (88 bytes)

void FUN_20102040(uint param_1)

{
  uint uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  uVar1 = 0;
  local_18 = 0x4090508;
  uStack_14 = 0xd0b0c0e;
  do {
    if ((param_1 >> (uVar1 & 0xff) & 1) == 0) {
      FUN_20100414(6,*(undefined1 *)((int)&local_18 + uVar1));
    }
    else {
      FUN_20100838();
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 8);
  return;
}


// ===== cpg_set_clock_profile @ 201020a0 (144 bytes)

/* FRQCR + STBCR1..11 from a 2-entry table at 0x2016517C */

void cpg_set_clock_profile(int param_1)

{
  DAT_fcfe0024 = (&DAT_2016517c)[param_1];
  DAT_fcfe0420 = (&DAT_2016517e)[param_1];
  DAT_fcfe0424 = (&DAT_20165180)[param_1];
  DAT_fcfe0428 = (&DAT_20165182)[param_1];
  DAT_fcfe042c = (&DAT_20165184)[param_1];
  DAT_fcfe0430 = (&DAT_20165186)[param_1];
  DAT_fcfe0434 = (&DAT_20165188)[param_1];
  DAT_fcfe0438 = (&DAT_2016518a)[param_1];
  DAT_fcfe043c = (&DAT_2016518c)[param_1];
  DAT_fcfe0440 = (&DAT_2016518e)[param_1];
  DAT_fcfe0444 = (&DAT_20165190)[param_1];
  return;
}


// ===== FUN_20102138 @ 20102138 (400 bytes)

void FUN_20102138(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_2 == 0) {
    piVar3 = &DAT_2080003c;
    iVar2 = 0x20808bdc;
  }
  else {
    piVar3 = &DAT_20800030;
    iVar2 = 0x20808bd0;
  }
  piVar4 = piVar3 + 2;
  if (*piVar3 == 0) {
    if (piVar3[1] != 0) {
      DAT_20808bec = DAT_20808bec + '\x01';
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      *param_1 = 2;
      *piVar3 = 1;
      goto LAB_2010226c;
    }
    if (*piVar4 != 0) {
      DAT_20808bed = DAT_20808bed + '\x01';
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      uVar1 = 5;
      goto LAB_201022a4;
    }
    DAT_20808bee = DAT_20808bee + '\x01';
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    if (piVar3[1] != 0) {
      if (*piVar4 == 0) {
        DAT_20808be9 = DAT_20808be9 + '\x01';
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
        *param_1 = 3;
        *piVar3 = 1;
      }
      else {
        DAT_20808be8 = DAT_20808be8 + '\x01';
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
        *param_1 = 4;
        *piVar3 = 1;
      }
      goto LAB_2010226c;
    }
    if (*piVar4 == 0) {
      DAT_20808beb = DAT_20808beb + '\x01';
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 1;
    }
    else {
      DAT_20808bea = DAT_20808bea + '\x01';
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      uVar1 = 6;
LAB_201022a4:
      *param_1 = uVar1;
    }
  }
  *piVar3 = 0;
LAB_2010226c:
  *piVar4 = 0;
  return;
}


// ===== FUN_201022c8 @ 201022c8 (84 bytes)

void FUN_201022c8(undefined4 param_1,undefined4 param_2)

{
  DAT_20808bef = DAT_20808bef + '\x01';
  if (((DAT_2080003c == 0 && DAT_20800040 == 0) && DAT_20800044 == 0) && DAT_20800048 == 0) {
    if (DAT_20800034 == 0) {
      DAT_20800038 = 1;
    }
    DAT_20800034 = 1;
    DAT_20808bd4 = param_1;
    DAT_20808bd8 = param_2;
  }
  return;
}


// ===== FUN_2010231c @ 2010231c (32 bytes)

void FUN_2010231c(void)

{
  DAT_20808bf0 = DAT_20808bf0 + '\x01';
  DAT_20800034 = 0;
  return;
}


// ===== FUN_20102348 @ 20102348 (84 bytes)

void FUN_20102348(undefined4 param_1,undefined4 param_2)

{
  DAT_20808bf1 = DAT_20808bf1 + '\x01';
  if (((DAT_20800030 == 0 && DAT_20800034 == 0) && DAT_20800038 == 0) && DAT_20800048 == 0) {
    if (DAT_20800040 == 0) {
      DAT_20800044 = 1;
    }
    DAT_20800040 = 1;
    DAT_20808be0 = param_1;
    DAT_20808be4 = param_2;
  }
  return;
}


// ===== FUN_2010239c @ 2010239c (32 bytes)

void FUN_2010239c(void)

{
  DAT_20808bf2 = DAT_20808bf2 + '\x01';
  DAT_20800040 = 0;
  return;
}


// ===== FUN_201023bc @ 201023bc (188 bytes)

void FUN_201023bc(undefined1 *param_1)

{
  undefined1 uVar1;
  
  if (DAT_2080004c == 0) {
    if (DAT_20800048 != 0) {
      *param_1 = 2;
      DAT_2080004c = 1;
      DAT_20800050 = 0;
      return;
    }
    if (DAT_20800050 == 0) {
      *param_1 = 0;
      DAT_2080004c = 0;
      DAT_20800050 = 0;
      return;
    }
    uVar1 = 5;
  }
  else {
    if (DAT_20800048 != 0) {
      if (DAT_20800050 == 0) {
        uVar1 = 3;
      }
      else {
        uVar1 = 4;
      }
      *param_1 = uVar1;
      DAT_2080004c = 1;
      DAT_20800050 = 0;
      return;
    }
    if (DAT_20800050 == 0) {
      DAT_20808beb = DAT_20808beb + '\x01';
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 1;
      DAT_2080004c = 0;
      DAT_20800050 = 0;
      return;
    }
    uVar1 = 6;
  }
  *param_1 = uVar1;
  DAT_2080004c = 0;
  DAT_20800050 = 0;
  return;
}


// ===== FUN_20102478 @ 20102478 (60 bytes)

void FUN_20102478(void)

{
  if (((DAT_20800030 == 0 && DAT_20800034 == 0) && DAT_20800038 == 0) && DAT_20800040 == 0) {
    if (DAT_20800048 == 0) {
      DAT_20800050 = 1;
    }
    DAT_20800048 = 1;
  }
  return;
}


// ===== FUN_201024b4 @ 201024b4 (16 bytes)

void FUN_201024b4(void)

{
  DAT_20800048 = 0;
  return;
}


// ===== FUN_201024c4 @ 201024c4 (168 bytes)

void FUN_201024c4(undefined1 *param_1)

{
  undefined1 uVar1;
  
  if (DAT_20800058 == 0) {
    if (DAT_20800054 != 0) {
      *param_1 = 2;
      DAT_20800058 = 1;
      DAT_2080005c = 0;
      return;
    }
    if (DAT_2080005c == 0) {
      *param_1 = 0;
      DAT_20800058 = 0;
      DAT_2080005c = 0;
      return;
    }
    uVar1 = 5;
  }
  else {
    if (DAT_20800054 != 0) {
      if (DAT_2080005c == 0) {
        uVar1 = 3;
      }
      else {
        uVar1 = 4;
      }
      *param_1 = uVar1;
      DAT_20800058 = 1;
      DAT_2080005c = 0;
      return;
    }
    if (DAT_2080005c == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 1;
      DAT_20800058 = 0;
      DAT_2080005c = 0;
      return;
    }
    uVar1 = 6;
  }
  *param_1 = uVar1;
  DAT_20800058 = 0;
  DAT_2080005c = 0;
  return;
}


// ===== FUN_2010256c @ 2010256c (72 bytes)

void FUN_2010256c(void)

{
  int iVar1;
  
  if ((((DAT_20800030 == 0 && DAT_20800034 == 0) && DAT_20800038 == 0) && DAT_20800048 == 0) &&
     (iVar1 = FUN_20113c6c(), iVar1 == 0)) {
    if (DAT_20800054 == 0) {
      DAT_2080005c = 1;
    }
    DAT_20800054 = 1;
  }
  return;
}


// ===== FUN_201025b4 @ 201025b4 (16 bytes)

void FUN_201025b4(void)

{
  DAT_20800054 = 0;
  return;
}


// ===== FUN_201025c4 @ 201025c4 (60 bytes)

undefined4 FUN_201025c4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_2080005c != 0 || (DAT_20800058 != 0 || DAT_20800054 != 0)) &&
     (iVar1 = FUN_20120fe4(), iVar1 == 0x30f)) {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== FUN_2010261c @ 2010261c (124 bytes)

void FUN_2010261c(void)

{
  byte bVar1;
  
  DAT_fcff0200 = 0x40;
  DAT_fcff0210 = 0;
  DAT_fcff0212 = 0;
  DAT_fcff0218 = 0;
  DAT_fcff021a = 0x13f;
  DAT_fcff0224 = 0;
  DAT_fcff0226 = 0x13f;
  DAT_fcff021c = 0;
  DAT_fcff021e = 0;
  DAT_fcff0228 = 0;
  DAT_fcff022a = 0;
  DAT_fcff020e = 0x47;
  DAT_fcff020f = 0x7f;
  DAT_fcff0236 = 0x3f;
  DAT_fcff0202 = 0x38;
  bVar1 = DAT_fcff020a;
  DAT_fcff020a = bVar1 | 0x20;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 0x40;
  return;
}


// ===== FUN_201026e0 @ 201026e0 (80 bytes)

void FUN_201026e0(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = FUN_201353f8(param_1 * 0x140,param_1 * 0x140 >> 0x1f);
  iVar1 = FUN_201353f8(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== FUN_201026e8 @ 201026e8 (24 bytes)

/* WARNING: Removing unreachable block (ram,0x201026a0) */
/* WARNING: Removing unreachable block (ram,0x201026ac) */

void FUN_201026e8(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  FUN_2010261c();
  iVar1 = FUN_201353f8(0x4b00,0,extraout_r2,extraout_r3,unaff_r4,unaff_lr);
  iVar1 = FUN_201353f8(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== FUN_20102708 @ 20102708 (108 bytes)

void FUN_20102708(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*param_1 != -1) && (*param_1 == -0x5a3cffff)) {
    crc32_make_table();
    uVar1 = crc32_update(0xffffffff,0x30,param_1 + 2);
    if (param_1[0xe] == ~uVar1) {
      iVar2 = param_1[3];
      iVar3 = param_1[4];
      iVar4 = param_1[5];
      *param_2 = param_1[2];
      param_2[1] = iVar2;
      param_2[2] = iVar3;
      param_2[3] = iVar4;
      iVar2 = param_1[7];
      iVar3 = param_1[8];
      iVar4 = param_1[9];
      param_2[4] = param_1[6];
      param_2[5] = iVar2;
      param_2[6] = iVar3;
      param_2[7] = iVar4;
      iVar2 = param_1[0xb];
      iVar3 = param_1[0xc];
      iVar4 = param_1[0xd];
      param_2[8] = param_1[10];
      param_2[9] = iVar2;
      param_2[10] = iVar3;
      param_2[0xb] = iVar4;
    }
  }
  return;
}


// ===== FUN_20102774 @ 20102774 (132 bytes)

void FUN_20102774(undefined4 *param_1)

{
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint local_18;
  
  local_50[0] = 0xa5c30001;
  local_48 = *param_1;
  uStack_44 = param_1[1];
  uStack_40 = param_1[2];
  uStack_3c = param_1[3];
  local_38 = param_1[4];
  uStack_34 = param_1[5];
  uStack_30 = param_1[6];
  uStack_2c = param_1[7];
  local_28 = param_1[8];
  uStack_24 = param_1[9];
  uStack_20 = param_1[10];
  uStack_1c = param_1[0xb];
  crc32_make_table();
  local_18 = crc32_update(0xffffffff,0x30,&local_48);
  local_18 = ~local_18;
  FUN_20103e74(0,0x3d0000,0x40);
  FUN_20103dd0(0x3d0000,local_50,0x40);
  return;
}


// ===== FUN_201027f8 @ 201027f8 (1836 bytes)

void FUN_201027f8(undefined8 *param_1)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar3 = 0;
  do {
    *(undefined4 *)(&local_e0 + iVar3) = 0;
    *(undefined4 *)((int)&local_e0 + iVar3 * 8 + 4) = 0;
    *(undefined4 *)(&local_58 + iVar3) = 0;
    *(undefined4 *)((int)&local_58 + iVar3 * 8 + 4) = 0;
    *(undefined4 *)(&local_40 + iVar3) = 0;
    *(undefined4 *)((int)&local_40 + iVar3 * 8 + 4) = 0;
    iVar1 = iVar3 * 8;
    puVar10 = &local_70 + iVar3;
    iVar3 = iVar3 + 1;
    *(undefined4 *)puVar10 = 0;
    *(undefined4 *)((int)&local_70 + iVar1 + 4) = 0;
    uVar16 = CONCAT44(local_68._4_4_,(undefined4)local_68);
  } while (iVar3 < 3);
  iVar3 = 0;
  do {
    local_68 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20808bf8)[iVar3 * 2]);
    uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar4 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar4,uVar11,(undefined4)local_d0,local_d0._4_4_);
    local_d0 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20808bfa)[iVar3 * 2]);
    uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar5 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar5,uVar12,(undefined4)local_48,local_48._4_4_);
    local_48 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20800060)[iVar3 * 2]);
    uVar13 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar6 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar6,uVar13,(undefined4)local_30,local_30._4_4_);
    local_30 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20800062)[iVar3 * 2]);
    uVar14 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar7 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar7,uVar14,(undefined4)local_60,local_60._4_4_);
    local_60 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar4,uVar11);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_e0,
                          local_e0._4_4_);
    local_e0 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar5,uVar12);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_d8,
                          local_d8._4_4_);
    local_d8 = uVar16;
    local_58 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar5,uVar12);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_50,
                          local_50._4_4_);
    local_50 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar6,uVar13);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_40,
                          local_40._4_4_);
    local_40 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar6,uVar13);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_38,
                          local_38._4_4_);
    local_38 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar7,uVar14);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_70,
                          local_70._4_4_);
    local_70 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar7,uVar14);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_68,
                          local_68._4_4_);
    uVar5 = local_d0._4_4_;
    uVar4 = (undefined4)local_d0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  local_68 = uVar16;
  uVar16 = FUN_201649d8((undefined4)local_e0,local_e0._4_4_);
  uVar7 = local_48._4_4_;
  uVar6 = (undefined4)local_48;
  uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar8 = (undefined4)uVar16;
  local_e0 = uVar16;
  uVar16 = FUN_201649d8((undefined4)local_d8,local_d8._4_4_,(undefined4)local_48,local_48._4_4_);
  local_d8 = uVar16;
  local_78 = FUN_201649d8((undefined4)local_58,local_58._4_4_,uVar4,uVar5);
  local_58 = local_78;
  local_88 = FUN_201649d8((undefined4)local_50,local_50._4_4_,uVar6,uVar7);
  local_50 = local_88;
  local_98 = FUN_201649d8((undefined4)local_40,local_40._4_4_,uVar4,uVar5);
  local_40 = local_98;
  uVar17 = FUN_201649d8((undefined4)local_38,local_38._4_4_,uVar6,uVar7);
  local_c8._0_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar11 = (undefined4)uVar17;
  local_c0._0_4_ = (undefined4)local_c8;
  local_38 = uVar17;
  uVar17 = FUN_201649d8((undefined4)local_70,local_70._4_4_,uVar4,uVar5);
  local_70 = uVar17;
  uVar17 = FUN_201649d8((undefined4)local_68,local_68._4_4_,uVar6,uVar7);
  local_68 = uVar17;
  uVar17 = FUN_201649d8(uVar4,uVar5,0,0x40140000);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_d0 = uVar17;
  uVar18 = FUN_201649d8(uVar6,uVar7,0,0x40140000);
  uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
  local_48 = uVar18;
  uVar19 = FUN_201649d8((undefined4)local_30,local_30._4_4_,0,0x40140000);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  local_30 = uVar19;
  uVar20 = FUN_201649d8((undefined4)local_60,local_60._4_4_,0,0x40140000);
  local_60 = uVar20;
  uVar20 = FUN_20164fa4((undefined4)local_78,local_78._4_4_,(int)uVar18,uVar4);
  local_80 = (undefined4)((ulonglong)uVar20 >> 0x20);
  local_7c = (undefined4)uVar20;
  local_78._0_4_ = local_7c;
  local_78._4_4_ = local_80;
  local_b0 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,uVar5);
  uVar16 = FUN_20164da8((int)local_b0,(int)((ulonglong)local_b0 >> 0x20),(undefined4)local_78,
                        local_78._4_4_);
  local_a8 = FUN_20164fa4((undefined4)local_88,local_88._4_4_,(int)uVar18,uVar4);
  uVar2 = (ulonglong)local_a8 >> 0x20;
  uVar4 = (undefined4)local_a8;
  uVar17 = FUN_20164fa4(uVar8,uVar12,(int)uVar17,uVar5);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = FUN_20164da8((int)uVar17,uVar5,uVar4,(int)uVar2);
  uVar16 = FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar15 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar9 = (undefined4)uVar16;
  local_90._4_4_ = local_80;
  local_90._0_4_ = local_7c;
  uVar16 = FUN_20164fa4(uVar11,(undefined4)local_c8,(int)uVar19,uVar6);
  uVar4 = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_90 = FUN_20164da8((int)uVar16,uVar4,(undefined4)local_90,local_90._4_4_);
  local_c8 = local_a8;
  uVar18 = FUN_20164fa4((undefined4)local_98,local_98._4_4_,(int)uVar19,uVar6);
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = FUN_20164da8((int)uVar18,uVar6,(undefined4)local_c8,local_c8._4_4_);
  uVar19 = FUN_20164fa4((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(undefined4)local_90,
                        local_90._4_4_);
  uVar19 = FUN_201649d8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar9,uVar15);
  *param_1 = uVar19;
  uVar18 = FUN_20164da8((undefined4)local_b0,local_b0._4_4_,(int)uVar18,uVar6);
  uVar16 = FUN_20164da8((int)uVar17,uVar5,(int)uVar16,uVar4);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar18,
                        (int)((ulonglong)uVar18 >> 0x20));
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[1] = uVar16;
  local_b0._4_4_ = (undefined4)local_c0;
  local_b0._0_4_ = uVar11;
  local_98._0_4_ = uVar12;
  uVar16 = FUN_20164da8(uVar8,uVar12,uVar11);
  uVar5 = local_d8._4_4_;
  uVar4 = (undefined4)local_d8;
  local_c8 = local_40;
  uVar17 = FUN_20164da8((undefined4)local_d8,local_d8._4_4_);
  FUN_20164fa4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
               (int)((ulonglong)uVar16 >> 0x20));
  local_c0 = local_48;
  uVar16 = FUN_20164da8();
  uVar7 = local_d0._4_4_;
  uVar6 = (undefined4)local_d0;
  uVar17 = FUN_20164da8((undefined4)local_d0,local_d0._4_4_,(undefined4)local_c8,local_c8._4_4_);
  local_90 = local_30;
  uVar18 = FUN_20164da8(uVar8,(undefined4)local_98);
  FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
               (int)((ulonglong)uVar17 >> 0x20));
  local_b8 = local_50;
  uVar17 = FUN_20164da8();
  uVar18 = FUN_20164da8(uVar4,uVar5,(undefined4)local_90,local_90._4_4_);
  local_c8 = uVar18;
  uVar18 = FUN_20164da8(uVar6,uVar7,(undefined4)local_b0,local_b0._4_4_);
  FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(undefined4)local_c8,local_c8._4_4_);
  local_c8 = local_58;
  uVar18 = FUN_20164da8();
  uVar17 = FUN_20164888((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar16 = FUN_20164888((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[2] = uVar16;
  uVar16 = FUN_20164fa4((undefined4)local_c8,local_c8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar14 = local_60._4_4_;
  uVar13 = (undefined4)local_60;
  local_90 = local_68;
  uVar17 = FUN_20164fa4();
  local_98._4_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_9c = (undefined4)uVar17;
  local_b0 = FUN_20164da8(local_9c,local_98._4_4_,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164fa4((undefined4)local_b8,local_b8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar12 = local_70._4_4_;
  uVar11 = (undefined4)local_70;
  local_88._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_a0 = (undefined4)uVar16;
  uVar16 = FUN_20164fa4((undefined4)local_70,local_70._4_4_,uVar13,uVar14);
  local_a8 = uVar16;
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_a0,(undefined4)local_88);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[3] = uVar16;
  uVar16 = FUN_20164fa4(uVar4,uVar5,uVar6,uVar7);
  uVar16 = FUN_20164da8((undefined4)local_a8,local_a8._4_4_,(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  local_b0 = uVar16;
  uVar16 = FUN_20164fa4(uVar8,(undefined4)local_98,uVar6,uVar7);
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_9c,local_98._4_4_);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[4] = uVar16;
  uVar16 = FUN_20164da8(uVar8,(undefined4)local_98,(undefined4)local_90,local_90._4_4_);
  local_b0 = uVar16;
  uVar16 = FUN_20164da8(uVar4,uVar5,uVar11,uVar12);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_c0,
                        local_c0._4_4_);
  local_c0._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_b0._0_4_ = (undefined4)uVar16;
  uVar16 = FUN_20164da8(uVar6,uVar7,uVar11,uVar12);
  uVar17 = FUN_20164da8(uVar8,(undefined4)local_98,uVar13,uVar14);
  uVar16 = FUN_20164fa4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b8,
                        local_b8._4_4_);
  uVar17 = FUN_20164da8(uVar4,uVar5,uVar13,uVar14);
  uVar18 = FUN_20164da8(uVar6,uVar7,(undefined4)local_90,local_90._4_4_);
  uVar17 = FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar17 = FUN_20164da8((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(undefined4)local_c8,
                        local_c8._4_4_);
  uVar16 = FUN_20164888((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        (undefined4)local_c0);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[5] = uVar16;
  return;
}


// ===== FUN_20102f34 @ 20102f34 (88 bytes)

void FUN_20102f34(void)

{
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  memcpy(&DAT_20808bf8,&DAT_20800060,0x14);
  FUN_201027f8(&local_38);
  FUN_20102708(&DAT_183d0000,&local_38);
  DAT_20808c10 = local_38;
  DAT_20808c14 = uStack_34;
  DAT_20808c18 = uStack_30;
  DAT_20808c1c = uStack_2c;
  DAT_20808c20 = local_28;
  DAT_20808c24 = uStack_24;
  DAT_20808c28 = uStack_20;
  DAT_20808c2c = uStack_1c;
  DAT_20808c30 = local_18;
  DAT_20808c34 = uStack_14;
  DAT_20808c38 = uStack_10;
  DAT_20808c3c = uStack_c;
  return;
}


// ===== FUN_20102f8c @ 20102f8c (68 bytes)

void FUN_20102f8c(int param_1,uint param_2,undefined2 *param_3)

{
  if (param_2 < 5) {
    if (param_1 == 0) {
      (&DAT_20800060)[param_2 * 2] = *param_3;
      (&DAT_20800062)[param_2 * 2] = param_3[1];
      return;
    }
    (&DAT_20808bf8)[param_2 * 2] = *param_3;
    (&DAT_20808bfa)[param_2 * 2] = param_3[1];
  }
  return;
}


// ===== FUN_20102fd0 @ 20102fd0 (144 bytes)

void FUN_20102fd0(int param_1,int param_2)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_20102f8c(param_1,2,param_2);
  FUN_20102f8c(param_1,3,param_2 + 4);
  FUN_20102f8c(param_1,0,param_2 + 8);
  FUN_20102f8c(param_1,1,param_2 + 0xc);
  if (param_1 != 0) {
    FUN_201027f8(&local_40);
    FUN_20102774(&local_40);
    DAT_20808c10 = local_40;
    DAT_20808c14 = uStack_3c;
    DAT_20808c18 = uStack_38;
    DAT_20808c1c = uStack_34;
    DAT_20808c20 = local_30;
    DAT_20808c24 = uStack_2c;
    DAT_20808c28 = uStack_28;
    DAT_20808c2c = uStack_24;
    DAT_20808c30 = local_20;
    DAT_20808c34 = uStack_1c;
    DAT_20808c38 = uStack_18;
    DAT_20808c3c = uStack_14;
  }
  return;
}


// ===== FUN_20103060 @ 20103060 (260 bytes)

void FUN_20103060(undefined4 param_1,undefined4 param_2,short *param_3,short *param_4)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar5 = FUN_20164d54(param_2);
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar6 = FUN_20164da8((int)uVar5,uVar3,DAT_20808c18,DAT_20808c1c);
  uVar7 = FUN_20164d54(param_1);
  uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar8 = FUN_20164da8((int)uVar7,uVar4,DAT_20808c10,DAT_20808c14);
  uVar6 = FUN_20164888((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar6,
                       (int)((ulonglong)uVar6 >> 0x20));
  uVar6 = FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_20808c20,DAT_20808c24);
  FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
  sVar1 = FUN_20164c90();
  uVar5 = FUN_20164da8((int)uVar5,uVar3,DAT_20808c30,DAT_20808c34);
  uVar6 = FUN_20164da8((int)uVar7,uVar4,DAT_20808c28,DAT_20808c2c);
  uVar5 = FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                       (int)((ulonglong)uVar5 >> 0x20));
  uVar5 = FUN_20164888((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_20808c38,DAT_20808c3c);
  FUN_20164888((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3fe00000);
  sVar2 = FUN_20164c90();
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  else if (799 < sVar1) {
    sVar1 = 799;
  }
  if (sVar2 < 0) {
    sVar2 = 0;
  }
  else if (0x1df < sVar2) {
    sVar2 = 0x1df;
  }
  *param_3 = sVar1;
  *param_4 = sVar2;
  return;
}


// ===== FUN_20103164 @ 20103164 (40 bytes)

void FUN_20103164(void)

{
  undefined1 auStack_10 [4];
  undefined1 auStack_c [8];
  
  FUN_20102f34();
  FUN_20103060(100,100,auStack_10,auStack_c);
  return;
}


// ===== FUN_20103198 @ 20103198 (96 bytes)

undefined4 FUN_20103198(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_10;
  
  uStack_10 = param_1;
  FUN_20120674(2,0);
  iVar1 = FUN_20120750(2,0x90,0);
  if (iVar1 == 0) {
    FUN_2012081c(2,&uStack_10,1);
  }
  FUN_20120674(2);
  FUN_20120bc8(2);
  return 0;
}


// ===== FUN_201031f8 @ 201031f8 (248 bytes)

uint FUN_201031f8(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte local_14;
  byte local_13;
  undefined4 uStack_10;
  
  uStack_10 = param_1;
  iVar1 = FUN_20120674(2,0);
  if (iVar1 == 0) {
    iVar1 = FUN_20120750(2,0x90,0);
    if ((iVar1 == 0) && (iVar1 = FUN_2012081c(2,&uStack_10,1), iVar1 == 0)) {
      itron_dly_tsk(1);
      FUN_20120674(2,1);
      iVar1 = FUN_20120750(2,0x91,1,0);
      if (iVar1 == 0) {
        iVar1 = FUN_20120a9c(2,&local_14);
      }
    }
    if (iVar1 == -2) {
      FUN_20120674(2);
      FUN_20120bac(2);
      FUN_20120bc8(2);
      uVar2 = 0xfffffffe;
    }
    else {
      uVar2 = (uint)local_14 << 4 | (int)(uint)local_13 >> 4;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== FUN_201032f0 @ 201032f0 (248 bytes)

undefined4 FUN_201032f0(short *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = 0;
  if (*param_1 == 0xfff) {
    *param_1 = 0;
  }
  if ((*param_1 != 0) && (param_1[2] != 0)) {
    uVar2 = FUN_20164d82(param_1[2]);
    uVar3 = FUN_20164d82(param_1[3]);
    uVar2 = FUN_201649d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                         (int)((ulonglong)uVar2 >> 0x20));
    uVar2 = FUN_20164fa4((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3ff00000);
    uVar3 = FUN_20164d82(*param_1);
    uVar3 = FUN_201649d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x40b00000);
    uVar3 = FUN_20164da8(0,0x40790000,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    FUN_20164da8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                 (int)((ulonglong)uVar2 >> 0x20));
    uVar1 = FUN_20164cf0();
  }
  return uVar1;
}


// ===== intc_irq_setup @ 201033e8 (124 bytes)

/* INTC 0xFCFEF800 */

void intc_irq_setup(void)

{
  ushort uVar1;
  
  FUN_201177a0(0x23);
  DAT_20808c40 = DAT_20808c40 + 1;
  DAT_20800074 = DAT_20800074 + 1;
  FUN_20152fac(DAT_20800088);
  uVar1 = DAT_fcfef804;
  if ((uVar1 & 8) != 0) {
    uVar1 = DAT_fcfef804;
    DAT_fcfef804 = uVar1 & 0xfff7;
  }
  return;
}


// ===== task_tsc2007 @ 20103464 (904 bytes)

void task_tsc2007(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  iVar2 = FUN_20120454(2);
  if (iVar2 == 0) {
    uVar1 = DAT_fcfef802;
    DAT_fcfef802 = uVar1 & 0xff3f;
    uVar1 = DAT_fcfef802;
    local_28 = (uint)uVar1;
    uVar1 = DAT_fcfef802;
    DAT_fcfef802 = uVar1 | 0x40;
    iVar2 = FUN_2014f1a8(0,&DAT_20165194);
    if (0 < iVar2) {
      FUN_20150ba0(&DAT_20800088);
      FUN_20152fac(DAT_2080008c);
      FUN_20103198(0xb0);
      itron_dly_tsk(10);
      do {
        while( true ) {
          local_30 = 0;
          local_2c = 0;
          iVar2 = FUN_20103198();
          if (-1 < iVar2) break;
          itron_dly_tsk(10);
        }
        while( true ) {
          itron_dly_tsk(1);
          uVar1 = DAT_fcfe3204;
          if ((uVar1 & 8) != 0) break;
          DAT_20808c48 = DAT_20808c48 + 1;
        }
        DAT_20808c44 = DAT_20808c44 + 1;
        FUN_2010231c();
        uVar1 = DAT_fcfef804;
        if ((uVar1 & 8) != 0) {
          uVar1 = DAT_fcfef804;
          DAT_fcfef804 = uVar1 & 0xfff7;
        }
        uVar1 = DAT_fcfef804;
        local_28 = (uint)uVar1;
        FUN_2011775c(0x23);
        FUN_201525f8(0xffffffff);
        iVar2 = 2;
        do {
          iVar2 = iVar2 + -1;
          iVar3 = FUN_201031f8(0xd4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          DAT_2080007c = (undefined2)iVar3;
          local_30._2_2_ = DAT_2080007c;
          iVar3 = FUN_201031f8(0xc4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          DAT_2080007a = (undefined2)iVar3;
          local_30 = CONCAT22(local_30._2_2_,DAT_2080007a);
          iVar3 = FUN_201031f8(0xe4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          local_2c = CONCAT22(local_2c._2_2_,(short)iVar3);
          iVar3 = FUN_201031f8(0xf4);
          if (iVar3 < 0) {
            itron_dly_tsk(10);
            break;
          }
          local_2c = CONCAT22((short)iVar3,(undefined2)local_2c);
          iVar3 = __aeabi_uidivmod(((local_30 & 0xffff) - 0xf3c) * 10000,0xfffff178);
          iVar3 = __aeabi_uidivmod(iVar3 * 800,10000);
          iVar4 = __aeabi_uidivmod(((local_30 >> 0x10) - 0x15e) * 10000,0xcb2);
          iVar4 = __aeabi_uidivmod(iVar4 * -0x1e0 + 4800000,10000);
          if ((((iVar3 < 0) || (799 < iVar3)) || (iVar4 < 0)) ||
             ((0x1df < iVar4 || (DAT_20800080 = FUN_201032f0(&local_30), DAT_20800080 == 0))))
          break;
          if (DAT_20800080 < 0x514) {
            if (((DAT_20800495 != '\0') || (DAT_20800496 != '\0')) || (DAT_20808532 != '\0')) {
              FUN_201022c8(iVar3,iVar4);
              DAT_20800076 = (undefined2)iVar3;
              DAT_20800078 = (undefined2)iVar4;
              DAT_20800084 = DAT_20800084 + 1;
            }
            break;
          }
        } while (0 < iVar2);
      } while( true );
    }
  }
  return;
}


// ===== FUN_201037ec @ 201037ec (24 bytes)

undefined4 FUN_201037ec(void)

{
  itron_dly_tsk(0x14);
  return DAT_20800090;
}


// ===== task_tsc2007_irq @ 20103804 (84 bytes)

void task_tsc2007_irq(void)

{
  int iVar1;
  int iVar2;
  
  FUN_20150ba0(&DAT_2080008c);
  do {
    do {
      FUN_201525f8(0xffffffff);
      iVar1 = func_0x2012001c();
      itron_dly_tsk(100);
      iVar2 = func_0x2012001c();
    } while (iVar1 != iVar2);
    DAT_20800090 = 1;
    FUN_20151934(DAT_20800088);
  } while( true );
}

