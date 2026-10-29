// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201041a0 @ 201041a0 (84 bytes)

undefined4 FUN_201041a0(undefined4 param_1)

{
  uint uVar1;
  undefined4 local_10;
  
  local_10 = 100000;
  do {
    uVar1 = FUN_20104104(param_1,0x48);
    if ((uVar1 & 1) != 0) {
      return 0;
    }
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  return 0xffffffff;
}


// ===== FUN_201041f4 @ 201041f4 (136 bytes)

undefined4 FUN_201041f4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_20104104(param_1,0x48);
  if (iVar1 != 1) {
    iVar1 = FUN_201041a0(param_1);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_20104104(param_1,0x48);
    if (iVar1 != 1) {
      FUN_20104110(param_1,0x20,1);
      FUN_20104110(param_1,0x20,0);
      FUN_201041a0(param_1);
      iVar1 = FUN_20104104(param_1,0x48);
      if (iVar1 != 1) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}


// ===== FUN_2010427c @ 2010427c (528 bytes)

int FUN_2010427c(int param_1,ushort *param_2,uint param_3,int param_4)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  byte bVar9;
  undefined4 uVar10;
  
  bVar9 = 0;
  uVar10 = 0;
  bVar2 = true;
  iVar3 = FUN_201041a0();
  do {
    if (iVar3 < 0) {
      return iVar3;
    }
    if (param_3 == 0) {
      return 0;
    }
    uVar8 = param_3;
    if (*(int *)(param_1 + 4) == 0) {
      if (param_3 < 4) {
        if (param_3 == 3) {
          uVar8 = 2;
        }
      }
      else {
        uVar8 = 4;
      }
      bVar9 = (&UNK_2016525c)[uVar8] | bVar9 & 0xf0;
      uVar4 = (uint)(byte)*param_2;
      puVar6 = (ushort *)((int)param_2 + 1);
      if (1 < (int)uVar8) {
        uVar1 = CONCAT11(*(byte *)((int)param_2 + 1),(byte)*param_2);
        uVar4 = (uint)uVar1;
        puVar6 = param_2 + 1;
        if (2 < (int)uVar8) {
          puVar6 = (ushort *)((int)param_2 + 3);
          uVar4 = (uint)CONCAT12((byte)param_2[1],uVar1);
        }
      }
      puVar7 = puVar6;
      if ((int)uVar8 < 4) goto LAB_201043ac;
      puVar7 = (ushort *)((int)puVar6 + 1);
      uVar4 = uVar4 | (uint)(byte)*puVar6 << 0x18;
LAB_201043b4:
      if (uVar8 == 1) {
        FUN_20104138(param_1,uVar4 & 0xff,0x40);
      }
      else {
        FUN_20104110(param_1,uVar4,0x40);
        if (uVar8 == 8) {
          FUN_20104110(param_1,uVar10,0x44);
        }
      }
    }
    else {
      if (7 < param_3) {
        uVar8 = 8;
      }
      if ((uVar8 & 1) != 0) {
        return -1;
      }
      if (uVar8 == 6) {
        uVar8 = 4;
      }
      bVar9 = *(byte *)((int)&DAT_20165268 + uVar8 + 1) | bVar9 & 0xf0;
      if (uVar8 == 8) {
        uVar10 = *(undefined4 *)param_2;
        param_2 = param_2 + 2;
      }
      uVar4 = (uint)*param_2;
      puVar7 = param_2 + 1;
      if (3 < (int)uVar8) {
        puVar7 = param_2 + 2;
        uVar4 = CONCAT13(*(byte *)((int)param_2 + 3),CONCAT12((byte)param_2[1],*param_2));
        goto LAB_201043b4;
      }
LAB_201043ac:
      if (uVar8 != 2) goto LAB_201043b4;
      FUN_20104124(param_1,uVar4 & 0xffff,0x40);
    }
    param_3 = param_3 - uVar8;
    if (param_3 == 0) {
      bVar2 = false;
    }
    FUN_20104110(param_1,0,0x24);
    FUN_20104110(param_1,0,0x28);
    FUN_20104110(param_1,0,0x2c);
    FUN_20104110(param_1,bVar9,0x30);
    uVar5 = 3;
    if (bVar2 || param_4 != 0) {
      uVar5 = 0x103;
    }
    FUN_20104110(param_1,uVar5,0x20);
    iVar3 = FUN_201041a0(param_1);
    param_2 = puVar7;
  } while( true );
}


// ===== FUN_2010448c @ 2010448c (704 bytes)

int FUN_2010448c(int param_1,byte *param_2,uint param_3,int param_4)

{
  undefined1 uVar1;
  byte bVar2;
  bool bVar9;
  bool bVar10;
  byte bVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  byte *pbVar16;
  uint uVar17;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  
  bVar10 = true;
  bVar9 = false;
  iVar12 = FUN_201041a0();
  if (iVar12 < 0) {
    return iVar12;
  }
  if (((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x14) == 0)) &&
     (*(char *)(param_1 + 0x28) == '\x05' || *(char *)(param_1 + 0x28) == -0x61)) {
    bVar9 = true;
    param_3 = param_3 << 1;
  }
  if (*(char *)(param_1 + 0x28) == 'p') {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    uVar17 = param_3;
    if (*(int *)(param_1 + 4) == 0) {
      if (param_3 < 4) {
        if (param_3 == 3) {
          uVar17 = 2;
        }
      }
      else {
        uVar17 = 4;
      }
      puVar13 = &UNK_2016525c;
    }
    else {
      if (7 < param_3) {
        uVar17 = 8;
      }
      if ((uVar17 & 1) != 0) {
        return -1;
      }
      puVar13 = (undefined *)0x20165269;
      if (uVar17 == 6) {
        uVar17 = 4;
      }
    }
    param_3 = param_3 - uVar17;
    if (param_3 == 0) {
      bVar10 = false;
    }
    uVar1 = puVar13[uVar17];
    FUN_20104110(param_1,0,0x24);
    FUN_20104110(param_1,0,0x28);
    FUN_20104110(param_1,0,0x2c);
    FUN_20104110(param_1,uVar1,0x30);
    uVar15 = 7;
    if (bVar10 || param_4 != 0) {
      uVar15 = 0x107;
    }
    FUN_20104110(param_1,uVar15,0x20);
    iVar12 = FUN_201041a0(param_1);
    if (iVar12 < 0) break;
    uVar15 = FUN_20104104(param_1,0x38);
    uVar14 = FUN_20104104(param_1,0x3c);
    bVar2 = (byte)uVar14;
    bVar3 = (byte)((uint)uVar14 >> 8);
    bVar4 = (byte)((uint)uVar14 >> 0x10);
    bVar5 = (byte)((uint)uVar14 >> 0x18);
    bVar6 = (byte)uVar15;
    bVar11 = (byte)((uint)uVar15 >> 8);
    bVar7 = (byte)((uint)uVar15 >> 0x10);
    bVar8 = (byte)((uint)uVar15 >> 0x18);
    if (bVar9) {
      if (uVar17 == 8) {
        if (*(int *)(param_1 + 0x18) == 0) {
          *param_2 = bVar3 | bVar2;
          param_2[1] = bVar4 | bVar5;
          param_2[2] = bVar6 | bVar11;
          param_2[3] = bVar7 | bVar8;
          param_2 = param_2 + 4;
        }
        else {
          *param_2 = bVar3 & bVar2;
          param_2[1] = bVar4 & bVar5;
          param_2[2] = bVar6 & bVar11;
          param_2[3] = bVar7 & bVar8;
          param_2 = param_2 + 4;
        }
      }
      else if (uVar17 == 2) {
        if (*(int *)(param_1 + 0x18) == 0) {
          bVar11 = bVar11 | bVar6;
        }
        else {
          bVar11 = bVar11 & bVar6;
        }
        *param_2 = bVar11;
        param_2 = param_2 + 1;
      }
      else if (uVar17 == 4) {
        if (*(int *)(param_1 + 0x18) == 0) {
          *param_2 = bVar11 | bVar6;
          param_2[1] = bVar7 | bVar8;
          param_2 = param_2 + 2;
        }
        else {
          *param_2 = bVar11 & bVar6;
          param_2[1] = bVar7 & bVar8;
          param_2 = param_2 + 2;
        }
      }
    }
    else {
      if (uVar17 == 8) {
        *param_2 = bVar2;
        param_2[1] = bVar3;
        param_2[2] = bVar4;
        param_2[3] = bVar5;
        param_2 = param_2 + 4;
      }
      *param_2 = bVar6;
      pbVar16 = param_2 + 1;
      if (1 < (int)uVar17) {
        pbVar16 = param_2 + 2;
        param_2[1] = bVar11;
      }
      param_2 = pbVar16;
      if (3 < (int)uVar17) {
        *pbVar16 = bVar7;
        pbVar16[1] = bVar8;
        param_2 = pbVar16 + 2;
      }
    }
  }
  return iVar12;
}


// ===== FUN_2010474c @ 2010474c (104 bytes)

void FUN_2010474c(int param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *unaff_r5;
  uint uVar3;
  undefined1 local_20 [16];
  
  *(undefined1 *)(param_1 + 0x28) = *param_2;
  if (*(int *)(param_1 + 4) != 0) {
    uVar3 = 0;
    if (param_3 != 0) {
      unaff_r5 = local_20;
    }
    iVar2 = 0;
    if (param_3 != 0) {
      do {
        unaff_r5[iVar2] = param_2[uVar3];
        puVar1 = param_2 + uVar3;
        uVar3 = uVar3 + 1;
        unaff_r5[iVar2 + 1] = *puVar1;
        iVar2 = iVar2 + 2;
      } while (uVar3 < param_3);
    }
    param_3 = param_3 << 1;
    param_2 = local_20;
  }
  FUN_2010427c(param_1,param_2,param_3);
  return;
}


// ===== FUN_201047b4 @ 201047b4 (148 bytes)

undefined4 FUN_201047b4(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  undefined1 local_14 [8];
  
  iVar2 = 1000000;
  local_14[0] = 5;
  local_18 = 0;
  FUN_2010474c(param_1,local_14,1);
  do {
    FUN_2010448c(param_1,&local_18,1);
    if ((local_18 & 0x81) == 0) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_2010448c(param_1,&local_18,1,0);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20104848 @ 20104848 (156 bytes)

undefined4 FUN_20104848(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  undefined1 local_14 [8];
  
  iVar2 = 1000000;
  local_14[0] = 5;
  local_18 = 0;
  FUN_2010474c(param_1,local_14,1);
  do {
    FUN_2010448c(param_1,&local_18,1);
    if (((local_18 & 2) != 0) && ((local_18 & 0x81) == 0)) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_2010448c(param_1,&local_18,1,0);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_201048e4 @ 201048e4 (96 bytes)

uint FUN_201048e4(undefined4 param_1)

{
  uint local_10;
  undefined1 local_c [4];
  
  local_c[0] = 0x35;
  local_10 = 0;
  FUN_2010474c(param_1,local_c,1);
  FUN_2010448c(param_1,&local_10,1);
  FUN_2010448c(param_1,&local_10,1,0);
  return local_10 & 0xff;
}


// ===== FUN_20104944 @ 20104944 (36 bytes)

undefined4 FUN_20104944(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x81fff320;
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = 0x81fff321;
  }
  FUN_20104110(param_1,uVar1,0);
  return 0;
}


// ===== FUN_20104968 @ 20104968 (140 bytes)

undefined4 FUN_20104968(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_20104104(param_1,0xc);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  FUN_20104110(param_1,0x1000000,0xc);
  FUN_20104110(param_1,0,0x20);
  FUN_201041a0(param_1);
  iVar2 = FUN_20104188(param_1);
  if (iVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_20104104(param_1,0);
    *(undefined4 *)(param_1 + 0x20) = uVar1;
    uVar3 = FUN_20104104(param_1,0);
    FUN_20104110(param_1,uVar3 | 0x80000000,0);
    FUN_20104944(param_1);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20104a08 @ 20104a08 (92 bytes)

undefined4 FUN_20104a08(int param_1)

{
  uint uVar1;
  
  FUN_201041f4();
  FUN_20104110(param_1,*(undefined4 *)(param_1 + 0x24),0xc);
  FUN_20104110(param_1,*(undefined4 *)(param_1 + 0x20),0);
  uVar1 = FUN_20104104(param_1,0xc);
  FUN_20104110(param_1,uVar1 | 0x200,0xc);
  FUN_20104104(param_1,0xc);
  return 0;
}


// ===== FUN_20104a64 @ 20104a64 (188 bytes)

int FUN_20104a64(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined4 local_14;
  
  _local_18 = CONCAT13(*(undefined1 *)(param_1 + 0xc),
                       CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0xc) >> 8),
                                CONCAT11((char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10),0xb)))
  ;
  local_14 = 0x80000ff;
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    FUN_201048e4(param_1);
    FUN_2010474c(param_1,&local_18,5,1);
    FUN_2010448c(param_1,param_2,param_3,0);
    if (*(int *)(param_1 + 4) != 0) {
      param_3 = param_3 / 2;
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
    FUN_20104a08(&DAT_20810d90);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_20104b20 @ 20104b20 (184 bytes)

int FUN_20104b20(int param_1)

{
  int iVar1;
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 local_c [4];
  
  local_c[0] = 6;
  _local_10 = CONCAT13(*(undefined1 *)(param_1 + 0xc),
                       CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0xc) >> 8),
                                CONCAT11((char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10),0xd8))
                      );
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    FUN_2010474c(param_1,local_c,1,0);
    iVar1 = FUN_20104848(param_1);
    if (iVar1 == 0) {
      thunk_FUN_20104154(&DAT_208000a8);
      FUN_2010474c(param_1,&local_10,4,0);
      iVar1 = FUN_201047b4(param_1);
      thunk_FUN_20104154(&DAT_208000a8);
      FUN_20104a08(&DAT_20810d90);
    }
  }
  return iVar1;
}


// ===== FUN_20104bd8 @ 20104bd8 (452 bytes)

int FUN_20104bd8(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined1 local_2c [8];
  
  local_30 = 2;
  local_2c[0] = 6;
  iVar2 = *(int *)(param_1 + 4) * 0x100 + 0x100;
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      while( true ) {
        local_30 = CONCAT13(*(undefined1 *)(param_1 + 0xc),
                            CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0xc) >> 8),
                                     CONCAT11((char)((uint)*(undefined4 *)(param_1 + 0xc) >> 0x10),
                                              (undefined1)local_30)));
        FUN_2010474c(param_1,local_2c,1,0);
        iVar1 = FUN_20104848(param_1);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (DAT_208000a0 == 0) {
          if (iVar2 <= param_3) {
            FUN_2010474c(param_1,&local_30,4,1);
            FUN_2010427c(param_1,param_2,iVar2,0);
            param_3 = param_3 - iVar2;
            param_2 = param_2 + iVar2;
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x100;
          }
        }
        else if (iVar2 <= DAT_208000a0 + param_3) {
          FUN_2010474c(param_1,&local_30,4,1);
          FUN_2010427c(param_1,&DAT_20810dbc,DAT_208000a0,1);
          FUN_2010427c(param_1,param_2,iVar2 - DAT_208000a0,0);
          iVar1 = DAT_208000a0;
          DAT_208000a0 = 0;
          param_3 = param_3 - (iVar2 - iVar1);
          param_2 = param_2 + (iVar2 - iVar1);
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x100;
        }
        iVar1 = FUN_201047b4(param_1);
        if (*(int *)(param_1 + 0x10) != 0) break;
        if (param_3 < iVar2) {
          for (; param_3 != 0; param_3 = param_3 + -1) {
            (&DAT_20810dbc)[DAT_208000a0] = *param_2;
            DAT_208000a0 = DAT_208000a0 + 1;
            param_2 = param_2 + 1;
          }
        }
        if ((iVar1 != 0) || (param_3 == 0)) break;
      }
    }
    FUN_20104a08(&DAT_20810d90);
  }
  return iVar1;
}


// ===== FUN_20104d9c @ 20104d9c (132 bytes)

int FUN_20104d9c(undefined4 param_1)

{
  int iVar1;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  
  local_10[0] = 0x98;
  local_c[0] = 6;
  iVar1 = FUN_20104968(param_1);
  if (iVar1 == 0) {
    FUN_2010474c(param_1,local_c,1,0);
    iVar1 = FUN_20104848(param_1);
    if (iVar1 == 0) {
      FUN_2010474c(param_1,local_10,1,0);
      iVar1 = FUN_201047b4(param_1);
      FUN_20104a08(&DAT_20810d90);
    }
  }
  return iVar1;
}


// ===== FUN_20104e20 @ 20104e20 (276 bytes)

uint FUN_20104e20(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  if (DAT_20810d98 != 1) {
    if (DAT_20810d98 == 3) {
      if (DAT_208000a0 != 0) {
        iVar2 = DAT_20810d94 * 0x100;
        DAT_20810d98 = 3;
        for (; DAT_208000a0 < iVar2 + 0x100; DAT_208000a0 = DAT_208000a0 + 1) {
          (&DAT_20810dbc)[DAT_208000a0] = 0xff;
        }
        DAT_208000a0 = 0;
        FUN_20104bd8(&DAT_20810d90);
      }
    }
    else if (DAT_20810d98 != 2) {
      DAT_20810d98 = 0;
      DAT_20810da0 = 0;
      return 0;
    }
    DAT_20810d98 = 0;
    uVar1 = (undefined1)DAT_20810da0;
    DAT_20810da0 = 0;
    *param_1 = uVar1;
    return 1;
  }
  bVar3 = DAT_20810d94 != 0;
  bVar4 = (param_2 & 1) != 0;
  if (bVar3 && bVar4) {
    param_2 = param_2 + 1;
  }
  iVar2 = FUN_20104a64(&DAT_20810d90,param_1,param_2);
  if (DAT_20810da0 == 0) {
    if (bVar3 && bVar4) {
      param_2 = param_2 - 1;
      DAT_20810d98 = 0;
    }
    if (iVar2 != 0) {
      param_2 = 0xfffffffd;
      DAT_20810d98 = 0;
    }
    return param_2;
  }
  DAT_20810d98 = 0;
  return 0xffffffff;
}


// ===== FUN_20104f34 @ 20104f34 (300 bytes)

uint FUN_20104f34(char *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  
  if (DAT_20810da0 != 0) {
    return 0xffffffff;
  }
  if (DAT_20810d98 == 1) {
    DAT_20810d98 = 0;
    DAT_20810d9c = 0;
  }
  else {
    uVar2 = param_2;
    if (DAT_20810d98 == 3) goto LAB_20105028;
    if (DAT_20810d98 != 0) {
      return 0xfffffffc;
    }
  }
  cVar1 = *param_1;
  if (cVar1 == 'r') {
    if (5 < param_2) {
      DAT_20810d98 = 1;
      DAT_20810d9c = *(undefined4 *)(param_1 + 2);
      return param_2;
    }
    return 0xfffffffc;
  }
  if (cVar1 == 'e') {
    if (5 < param_2) {
      DAT_20810d98 = 2;
      DAT_20810d9c = *(undefined4 *)(param_1 + 2);
      uVar2 = FUN_20104b20(&DAT_20810d90);
      return uVar2;
    }
    return 0xfffffffc;
  }
  if (cVar1 != 'p') {
    if (cVar1 == 'd') {
      if (1 < param_2) {
        DAT_20810d94 = (byte)param_1[1] - 0x30;
        return param_2;
      }
      return 0xfffffffc;
    }
    if (cVar1 == 'b') {
      FUN_20104d9c(&DAT_20810d90);
      return param_2;
    }
    return 0xfffffffc;
  }
  if (param_2 < 6) {
    return 0xfffffffc;
  }
  DAT_20810d98 = 3;
  DAT_20810d9c = *(undefined4 *)(param_1 + 2);
  if (param_2 < 7) {
    DAT_20810d98 = 3;
    return param_2;
  }
  param_1 = param_1 + 6;
  uVar2 = param_2 - 6;
LAB_20105028:
  FUN_20104bd8(&DAT_20810d90,param_1,uVar2);
  return param_2;
}


// ===== FUN_20105060 @ 20105060 (20 bytes)

undefined4 FUN_20105060(void)

{
  DAT_20810d90 = &SPIBSC_CMNCR_0;
  return 0;
}


// ===== play_close @ 2010508c (32 bytes)

void play_close(void)

{
  if (DAT_208000e0 != 0) {
    fs_fclose();
  }
  DAT_208000e0 = 0;
  return;
}


// ===== FUN_201050ac @ 201050ac (96 bytes)

undefined4 FUN_201050ac(void)

{
  int iVar1;
  
  iVar1 = sd_state_bit6();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    play_close();
  }
  else if (DAT_208000e0 != 0) {
    iVar1 = fs_fclose();
    if (iVar1 == 0) {
      DAT_208000e0 = 0;
      return 0;
    }
    DAT_208000bc = fs_task_ctx_get();
    DAT_208000e0 = 0;
  }
  return 0xfffffffe;
}


// ===== FUN_2010510c @ 2010510c (76 bytes)

char * FUN_2010510c(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  do {
    cVar1 = *param_1;
    if (cVar1 == *param_2) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        if (param_2[iVar2] == '\0') {
          return param_1;
        }
      } while (param_1[iVar2] == param_2[iVar2]);
    }
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return (char *)0x0;
}


// ===== wav_check_header @ 20105158 (292 bytes)

uint wav_check_header(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    iVar1 = memcmp(param_1,"RIFF",4);
    if ((((((iVar1 == 0) && (iVar1 = memcmp(param_1 + 8,"WAVE",4), iVar1 == 0)) &&
          (iVar1 = memcmp(param_1 + 0x24,"LIST",4), iVar1 == 0)) &&
         ((iVar1 = memcmp(param_1 + 0x2c,"ICMT",4), iVar1 == 0 &&
          (iVar1 = memcmp(param_1 + 0xc,"fmt ",4), iVar1 == 0)))) &&
        ((iVar1 = memcmp(param_1 + 0x54,"data",4), iVar1 == 0 &&
         ((param_3 != 2 || (iVar1 = memcmp(param_2,param_1 + 0x34,7), iVar1 == 0)))))) &&
       ((*(int *)(param_1 + 0x30) == 0x20 && (*(int *)(param_1 + 0x10) == 0x10)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffffd;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== wav_open_read @ 201052b0 (588 bytes)

uint wav_open_read(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [20];
  ushort local_64;
  ushort local_62;
  int local_60;
  undefined4 local_5c;
  ushort local_56;
  undefined1 auStack_44 [36];
  int local_20;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if (DAT_208000e0 != 0) {
    return 0xfffffffe;
  }
  if (param_2 == 1) {
    pcVar7 = "I:\\FT-710\\PlayList";
  }
  else {
    if (param_2 != 2) {
      return 0xfffffffe;
    }
    pcVar7 = "I:\\FT-710\\MESSAGE";
  }
  iVar1 = sd_state_bit6();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    return 0xfffffffe;
  }
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  strcpy(&local_b8,pcVar7);
  strcat(&local_b8,0x20105524);
  strcat(&local_b8,*param_1);
  strcat(&local_b8,0x20105528);
  DAT_208000e0 = fs_fopen((uint)&local_b8,0x20105530);
  if (DAT_208000e0 == 0) {
    return 0xfffffffe;
  }
  uVar2 = fs_fread((uint)auStack_78,0x5c,1,DAT_208000e0);
  if (uVar2 == 0) {
    play_close();
    return 0xfffffffe;
  }
  uVar2 = wav_check_header((int)auStack_78,*param_1,param_2);
  if (uVar2 != 0) {
    play_close();
    return 0xfffffffd;
  }
  param_1[3] = (uint)local_64;
  param_1[4] = (uint)local_62;
  param_1[5] = local_60;
  param_1[6] = (uint)local_56;
  param_1[7] = local_20;
  puVar3 = (undefined1 *)FUN_2010510c(auStack_44,0x20105534);
  if (puVar3 == (undefined1 *)0x0) {
    iVar1 = param_1[1];
    if (iVar1 == 0) goto LAB_20105468;
    puVar3 = auStack_44;
  }
  else {
    *puVar3 = 0;
    if (param_1[1] != 0) {
      strcpy(param_1[1],auStack_44);
    }
    iVar1 = param_1[2];
    if (iVar1 == 0) goto LAB_20105468;
    puVar3 = puVar3 + 1;
  }
  strcpy(iVar1,puVar3);
LAB_20105468:
  iVar1 = param_1[8];
  if (iVar1 != 0) {
    uVar2 = __aeabi_uidivmod(local_20,local_5c);
    uVar5 = (uint)((ulonglong)uVar2 * 0x91a2b3c5 >> 0x20);
    uVar6 = (uVar5 & 0x7ffff) >> 0xb;
    if (99 < uVar6) {
      uVar6 = 99;
    }
    uVar2 = uVar2 + (short)(ushort)(byte)((uVar5 << 0xd) >> 0x18) * -0xe10;
    uVar4 = ((uint)((ulonglong)uVar2 * 0x88888889 >> 0x20) & 0x1fff) >> 5;
    uVar5 = uVar4;
    if (0x3b < uVar4) {
      uVar5 = 0x3b;
    }
    uVar2 = uVar2 + uVar4 * -0x3c & 0xff;
    if (0x3b < uVar2) {
      uVar2 = 0x3b;
    }
    snprintf(iVar1,10,"%02d:%02d:%02d",uVar6,uVar5,uVar2);
  }
  return 0;
}


// ===== wav_list_dir @ 20105550 (576 bytes)

/* scans the folder for *.wav, up to 255 entries of 0x34 bytes, sorted */

int wav_list_dir(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int iStack_28;
  
  bVar1 = false;
  local_30 = param_1;
  local_2c = param_2;
  iStack_28 = param_3;
  iVar2 = sd_state_bit6();
  if (iVar2 == 0) {
    iVar2 = -1;
  }
  else {
    if (param_3 == 1) {
      pcVar3 = "I:\\FT-710\\PlayList";
    }
    else {
      if (param_3 != 2) {
        return -3;
      }
      pcVar3 = "I:\\FT-710\\MESSAGE";
    }
    local_34 = FUN_2014c410(pcVar3);
    if (local_34 == 0) {
      iVar2 = -4;
    }
    else {
      gui_scope_draw_hold_set(1);
      iVar4 = work_buf_get(0x33cc);
      iVar2 = 0;
LAB_201055b8:
      piVar5 = (int *)FUN_2014ca4c(local_34);
      if (piVar5 != (int *)0x0) {
        iVar6 = FUN_201476f0((int)*(char *)(*piVar5 + 0xb),0);
        if (iVar6 == 0) {
          iVar6 = (int)piVar5 + 10;
          if (piVar5 == (int *)0xfffffff6) goto LAB_20105660;
          uVar7 = strlen(iVar6);
          uVar9 = uVar7;
          if (uVar7 < 0x15) {
            do {
              uVar9 = uVar9 - 1;
              if ((int)uVar9 < 1) goto LAB_201055b8;
            } while ((*(char *)(iVar6 + uVar9) != '.') ||
                    (iVar8 = FUN_2014e208(iVar6 + uVar9,0x20105528), iVar8 != 0));
            iVar8 = iVar2 + 1;
            if ((0xff < iVar8) || (local_2c < iVar8)) {
              bVar1 = true;
              goto LAB_20105660;
            }
            iVar2 = iVar4 + iVar2 * 0x34;
            FUN_2014e2e4(iVar2,iVar6,uVar7 - 4);
            local_44 = 0;
            local_4c = 0;
            local_48 = 0;
            local_40 = 0;
            local_3c = 0;
            local_54 = iVar2 + 0x10;
            local_50 = iVar2 + 0x1b;
            local_38 = iVar2 + 0x26;
            local_58 = iVar2;
            uVar9 = wav_open_read(&local_58,param_3);
            *(uint *)(iVar2 + 0x30) = uVar9;
            if (uVar9 == 0) {
              FUN_201050ac();
            }
            iVar2 = (int)(short)iVar8;
          }
        }
        goto LAB_201055b8;
      }
LAB_20105660:
      thunk_FUN_2014c474(local_34);
      if (bVar1) {
        iVar2 = -5;
      }
      else if (iVar2 < 1) {
        iVar2 = -4;
      }
      else {
        FUN_20154fca(iVar4,iVar2,0x34,FUN_2014e208);
        __aeabi_memclr4(local_30,0x33cc);
        iVar6 = 0;
        do {
          puVar14 = (undefined4 *)(iVar4 + iVar6 * 0x34);
          puVar13 = (undefined4 *)(local_30 + iVar6 * 0x34);
          uVar10 = puVar14[1];
          uVar11 = puVar14[2];
          uVar12 = puVar14[3];
          *puVar13 = *puVar14;
          puVar13[1] = uVar10;
          puVar13[2] = uVar11;
          puVar13[3] = uVar12;
          __aeabi_memcpy4(puVar13 + 4,puVar14 + 4,0xb);
          memcpy((int)puVar13 + 0x1b,(int)puVar14 + 0x1b,0xb);
          memcpy((int)puVar13 + 0x26,(int)puVar14 + 0x26,9);
          iVar6 = iVar6 + 1;
          puVar13[0xc] = puVar14[0xc];
        } while (iVar6 < iVar2);
      }
      FUN_20133620();
      gui_scope_draw_hold_set(0);
    }
  }
  return iVar2;
}


// ===== audio_state @ 20105790 (12 bytes)

/* 0 idle, 2 recording, 4 playing, 8 paused, 0x10/0x20 seeking */

uint audio_state(void)

{
  return DAT_208000cc;
}


// ===== play_stop @ 2010579c (60 bytes)

void play_stop(void)

{
  uint uVar1;
  
  DAT_208000d4 = 0;
  DAT_208000ec = 0;
  DAT_208000f0 = 0;
  do {
    itron_tslp_tsk(10);
    uVar1 = audio_state();
  } while (uVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== wav_delete @ 201057d8 (232 bytes)

/* deletes <dir>\<name>.wav and rescans */

uint wav_delete(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_a0 [132];
  
  __aeabi_memclr4(auStack_a0,0x80);
  if (param_1 == 0 || param_2 == 0) {
LAB_20105820:
    uVar1 = 0xfffffffc;
  }
  else {
    if (param_4 == 1) {
      pcVar3 = "I:\\FT-710\\PlayList";
    }
    else {
      if (param_4 != 2) goto LAB_20105820;
      pcVar3 = "I:\\FT-710\\MESSAGE";
    }
    iVar2 = sd_state_bit6();
    if (iVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = audio_state();
      if (uVar1 == 8) {
        play_stop();
        iVar2 = 0;
        do {
          uVar1 = audio_state();
          if (uVar1 == 0) break;
          itron_tslp_tsk(10);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 10);
      }
      strcpy(auStack_a0,pcVar3);
      strcat(auStack_a0,0x20105524);
      strcat(auStack_a0,param_1);
      iVar2 = FUN_20143b20(auStack_a0);
      if (iVar2 == 0) {
        uVar1 = wav_list_dir(param_2,param_3,param_4);
        return uVar1;
      }
      uVar1 = 0xfffffffa;
    }
  }
  return uVar1;
}


// ===== audio_error @ 201058c0 (12 bytes)

uint audio_error(void)

{
  return DAT_208000d8;
}


// ===== audio_clear_error @ 201058cc (16 bytes)

void audio_clear_error(void)

{
  DAT_208000d8 = 0;
  return;
}


// ===== rec_start @ 201058dc (288 bytes)

/* (name16, freq digits, mode index, kind): sets event flag 2 */

void rec_start(int param_1,void *param_2,uint param_3,byte param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 != 0 && param_2 != (void *)0x0) && param_3 < 0x10) {
    DAT_2081104c = 0;
    DAT_20811050 = 0;
    DAT_20811054 = 0;
    DAT_20811058 = 0;
    DAT_2081105c = 0;
    DAT_20811060 = 0;
    DAT_20811064 = 0;
    DAT_20811068 = 0;
    DAT_2081106c = 0;
    DAT_20811070 = 0;
    DAT_20811074 = 0;
    DAT_20811078 = 0;
    DAT_2081107c = 0;
    memcpy(&DAT_2081104c,param_1,0x10);
    sprintf(&DAT_2081105c,"%c%c.%c%c%c.%c%c%c",*(undefined1 *)param_2,
            *(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2),
            *(undefined1 *)((int)param_2 + 3),*(undefined1 *)((int)param_2 + 4),
            *(undefined1 *)((int)param_2 + 5),*(undefined1 *)((int)param_2 + 6),
            *(undefined1 *)((int)param_2 + 7));
    FUN_2014e2e4(0x20811067,&UNK_20165274 + param_3 * 10,10);
    DAT_208000d0 = 1;
    DAT_208000b3 = param_4;
    audio_clear_error();
    iVar1 = itron_set_flg(DAT_208000c8,2);
    do {
      if (iVar1 != 0) break;
      itron_tslp_tsk(10);
      uVar2 = audio_state();
      iVar1 = DAT_208000d8;
    } while (uVar2 != 2);
  }
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== rec_stop @ 20105a20 (52 bytes)

void rec_stop(void)

{
  uint uVar1;
  
  DAT_208000d0 = 0;
  do {
    itron_tslp_tsk(10);
    uVar1 = audio_state();
  } while (uVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_start @ 20105a54 (148 bytes)

/* (name16, kind): sets event flag 4 */

void play_start(uint param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  
  memcpy(&DAT_20810fbc,param_1,0x10);
  DAT_208000d4 = 1;
  DAT_208000b3 = param_2;
  audio_clear_error();
  iVar1 = itron_set_flg(DAT_208000c8,4);
  if (iVar1 == 0) {
    do {
      itron_tslp_tsk(10);
      uVar2 = audio_state();
      if ((uVar2 == 4) || (DAT_208000d8 != 0)) goto LAB_20105ab4;
      uVar2 = audio_state();
    } while ((uVar2 != 0) || (DAT_208000b4 == '\0'));
    DAT_208000b4 = '\0';
  }
LAB_20105ab4:
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_resume @ 20105ae8 (64 bytes)

void play_resume(void)

{
  uint uVar1;
  
  DAT_208000d4 = 1;
  do {
    itron_tslp_tsk(10);
    uVar1 = audio_state();
    if (uVar1 == 4) break;
    uVar1 = audio_state();
  } while (uVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_pause @ 20105b28 (64 bytes)

void play_pause(void)

{
  uint uVar1;
  
  DAT_208000d4 = 2;
  do {
    itron_tslp_tsk(10);
    uVar1 = audio_state();
    if (uVar1 == 8) break;
    uVar1 = audio_state();
  } while (uVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_ffwd @ 20105b68 (64 bytes)

/* +5 s (320000 bytes) */

void play_ffwd(void)

{
  uint uVar1;
  
  DAT_208000d4 = 3;
  do {
    itron_tslp_tsk(10);
    uVar1 = audio_state();
    if (uVar1 == 4) break;
    uVar1 = audio_state();
  } while (uVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_rewind @ 20105ba8 (64 bytes)

/* -5 s */

void play_rewind(void)

{
  uint uVar1;
  
  DAT_208000d4 = 4;
  do {
    itron_tslp_tsk(10);
    uVar1 = audio_state();
    if (uVar1 == 4) break;
    uVar1 = audio_state();
  } while (uVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_progress @ 20105be8 (144 bytes)

/* "%02d:%02d:%02d" + percent */

void play_progress(void *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_208000f0;
  if (DAT_208000e4 < DAT_208000f0) {
    uVar2 = DAT_208000e4;
  }
  uVar1 = (uVar2 / 64000) % 0xe10;
  sprintf(param_2,"%02d:%02d:%02d",(uVar2 / 64000) / 0xe10,uVar1 / 0x3c,uVar1 % 0x3c);
  uVar2 = __aeabi_uidivmod(uVar2,DAT_208000e4 / 100);
  if (100 < uVar2) {
    uVar2 = 100;
  }
  *(short *)param_1 = (short)uVar2;
  return;
}


// ===== audio_codec_init @ 20105c78 (156 bytes)

/* task "audio_codec" */

void audio_codec_init(void)

{
  uint uVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_10 = 2;
  uStack_c = 0;
  local_8 = 0;
  uVar1 = itron_acre_flg(0,(byte *)&local_10);
  if (0 < (int)uVar1) {
    DAT_2081104c = 0;
    DAT_20811050 = 0;
    DAT_20811054 = 0;
    DAT_20811058 = 0;
    DAT_2081105c = 0;
    DAT_20811060 = 0;
    DAT_20811064 = 0;
    DAT_20811068 = 0;
    DAT_2081106c = 0;
    DAT_20811070 = 0;
    DAT_20811074 = 0;
    DAT_20811078 = 0;
    DAT_2081107c = 0;
    DAT_208000c8 = uVar1;
    uVar1 = itron_acre_tsk(0,&DAT_20165314);
    if (0 < (int)uVar1) {
      itron_sta_tsk(uVar1,0);
    }
  }
  return;
}


// ===== FUN_20105d14 @ 20105d14 (16 bytes)

undefined4 FUN_20105d14(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffffd;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== play_read_block @ 20105d24 (444 bytes)

/* reads 0xC80 bytes, keeps the left channel, header {count/2, 0x1234} */

uint play_read_block(int param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_fb8 [4000];
  
  iVar1 = sd_state_bit6();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    play_close();
    return 0xfffffffe;
  }
  if (param_1 == 0) {
    return 0xfffffffb;
  }
  if (param_2 == (void *)0x0) {
    play_close();
    return 0xffffffff;
  }
  if (DAT_208000e0 != 0) {
    __aeabi_memset(param_2,4000,0xf0);
    __aeabi_memset(local_fb8,4000,0xf0);
    uVar2 = fs_fread((uint)local_fb8,1,0xc80,DAT_208000e0);
    if (uVar2 != 0) {
      uVar6 = uVar2 >> 1;
      uVar5 = 0;
      iVar1 = 0;
      if (uVar2 >> 1 != 0) {
        do {
          uVar4 = uVar5 + 2;
          *(undefined1 *)((int)param_2 + uVar5 + 4) = local_fb8[iVar1];
          *(undefined1 *)((int)param_2 + uVar5 + 5) = local_fb8[iVar1 + 1];
          uVar5 = uVar4;
          iVar1 = iVar1 + 4;
        } while (uVar4 < uVar2 >> 1);
      }
      if (DAT_208000b5 == '\0') {
        DAT_208000b5 = '\x01';
        __aeabi_memset(local_fb8,4000,0xf0);
        uVar2 = fs_fread((uint)local_fb8,1,0xc80,DAT_208000e0);
        if (uVar2 != 0) {
          uVar5 = 0;
          iVar1 = 0;
          if (uVar2 >> 1 != 0) {
            do {
              iVar3 = uVar6 + uVar5;
              uVar5 = uVar5 + 2;
              *(undefined1 *)((int)param_2 + iVar3 + 4) = local_fb8[iVar1];
              *(undefined1 *)((int)param_2 + iVar3 + 5) = local_fb8[iVar1 + 1];
              iVar1 = iVar1 + 4;
            } while (uVar5 < uVar2 >> 1);
          }
          uVar6 = uVar6 + (uVar2 >> 1);
        }
      }
      *(char *)param_2 = (char)(uVar6 >> 1);
      *(char *)((int)param_2 + 1) = (char)(uVar6 >> 9);
      *(undefined1 *)((int)param_2 + 2) = 0x34;
      *(undefined1 *)((int)param_2 + 3) = 0x12;
      return 0;
    }
    DAT_208000bc = fs_task_ctx_get();
    if (DAT_208000bc == 0xfffffff2) {
      return 0xfffffffb;
    }
  }
  play_close();
  return 0xfffffffe;
}


// ===== play_advance @ 20105ee0 (76 bytes)

uint play_advance(void)

{
  uint uVar1;
  
  uVar1 = DAT_208000e4 - DAT_208000ec;
  if (uVar1 < 4000) {
    if (uVar1 == 0) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc80;
  }
  DAT_208000ec = DAT_208000ec + uVar1;
  return uVar1;
}


// ===== play_seek @ 20105f2c (116 bytes)

/* fseek(pos + 0x5C) */

uint play_seek(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  DAT_208000c0 = param_1;
  if (DAT_208000e0 == 0) {
    play_close();
    return 0xfffffffe;
  }
  iVar1 = sd_state_bit6();
  if (iVar1 != 0) {
    uVar2 = fs_fseek(DAT_208000e0,param_1 + 0x5c,0);
    uVar3 = 0;
    if (uVar2 != 0) {
      DAT_208000bc = fs_task_ctx_get();
      play_close();
      uVar3 = 0xfffffffe;
    }
    return uVar3;
  }
  DAT_208000d8 = 0xffffffff;
  play_close();
  return 0xfffffffe;
}


// ===== play_prime @ 20105fa0 (120 bytes)

int play_prime(int param_1)

{
  uint uVar1;
  uint unaff_r7;
  bool bVar2;
  
  uVar1 = 0;
  if (param_1 == 2) {
    unaff_r7 = play_advance();
    uVar1 = play_read_block(unaff_r7,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8);
    bVar2 = uVar1 == 0xfffffffb;
    if (bVar2) {
      uVar1 = 0;
    }
    if (!bVar2 && uVar1 != 0) {
      DAT_208000b8 = DAT_208000b8 + 1;
    }
  }
  dcache_clean_range(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8,unaff_r7);
  return uVar1;
}


// ===== rec_close_abort @ 20106018 (72 bytes)

void rec_close_abort(void)

{
  if (DAT_208000dc != 0) {
    fs_fclose();
  }
  DAT_208000dc = 0;
  DAT_208000e8 = 0;
  if (DAT_20810fcc != '\0') {
    FUN_20143b20(&DAT_20810fcc);
  }
  __aeabi_memclr4_veneer(&DAT_20810fcc,0x80);
  return;
}


// ===== rec_finish @ 20106060 (332 bytes)

/* pads to 4 bytes, rewrites the 0x5C-byte header sizes */

uint rec_finish(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_78 [4];
  int local_74;
  uint local_20;
  undefined4 local_1c [2];
  
  uVar4 = 0;
  local_1c[0] = 0;
  iVar1 = sd_state_bit6();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    rec_close_abort();
    return 0xfffffffe;
  }
  uVar3 = DAT_208000e8 & 0xfffffffc;
  if (uVar3 != DAT_208000e8) {
    uVar3 = uVar3 + 4;
  }
  if ((DAT_208000e8 < uVar3) &&
     (uVar2 = fs_fwrite((uint)local_1c,uVar3 - DAT_208000e8,1,DAT_208000dc), uVar2 == 0)) {
    uVar4 = 0xfffffffe;
  }
  iVar1 = fs_fclose(DAT_208000dc);
  if (iVar1 == 0) {
    DAT_208000dc = fs_fopen(0x20810fcc,0x201061c4);
    if (((DAT_208000dc != 0) && (uVar2 = fs_fseek(DAT_208000dc,0,0), uVar2 == 0)) &&
       (uVar2 = fs_fread((uint)auStack_78,0x5c,1,DAT_208000dc), uVar2 != 0)) {
      local_74 = uVar3 + 0x54;
      local_20 = uVar3;
      uVar3 = fs_fseek(DAT_208000dc,0,0);
      if ((uVar3 == 0) && (uVar3 = fs_fwrite((uint)auStack_78,0x5c,1,DAT_208000dc), uVar3 != 0)) {
        iVar1 = fs_fclose(DAT_208000dc);
        DAT_208000dc = 0;
        if (iVar1 != 0) {
          uVar4 = 0xfffffffe;
        }
        DAT_208000e8 = 0;
        __aeabi_memclr4(&DAT_20810fcc,0x80);
        return uVar4;
      }
    }
  }
  rec_close_abort();
  return 0xfffffffe;
}


// ===== rec_write @ 201061c8 (128 bytes)

uint rec_write(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0 || param_2 == 0) {
    return 0xffffffff;
  }
  iVar1 = sd_state_bit6();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    return 0xfffffffe;
  }
  uVar2 = fs_fwrite(param_2,param_1,1,DAT_208000dc);
  if (uVar2 == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    DAT_208000e8 = DAT_208000e8 + param_1;
    if (0xe0000000 < DAT_208000e8) {
      DAT_208000d0 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== rec_open_wav @ 20106248 (740 bytes)

/* writes RIFF/WAVE/fmt/LIST-ICMT/data header (0x5C bytes) */

uint rec_open_wav(void *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined4 local_60;
  int local_5c;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 auStack_44 [32];
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_1 == (void *)0x0) {
    return 0xffffffff;
  }
  if (((((*(char **)param_1 != (char *)0x0) && (*(char **)((int)param_1 + 4) != (char *)0x0)) &&
       (*(char **)((int)param_1 + 8) != (char *)0x0)) &&
      ((**(char **)param_1 != '\0' && (**(char **)((int)param_1 + 4) != '\0')))) &&
     (**(char **)((int)param_1 + 8) != '\0')) {
    if (DAT_208000dc == 0) {
      iVar1 = sd_state_bit6();
      if (iVar1 == 0) {
        DAT_208000d8 = 0xffffffff;
      }
      else {
        pcVar4 = (char *)0x0;
        DAT_208000e8 = 0;
        __aeabi_memclr4(&local_78,0x5c);
        local_74 = 0;
        local_78 = 0x46464952;
        local_70 = 0x45564157;
        local_6c = &DAT_20746d66;
        local_68 = 0x10;
        local_64 = *(undefined2 *)((int)param_1 + 0xc);
        local_62 = *(undefined2 *)((int)param_1 + 0x10);
        local_60 = *(undefined4 *)((int)param_1 + 0x14);
        local_56 = *(undefined2 *)((int)param_1 + 0x18);
        uVar2 = *(int *)((int)param_1 + 0x10) * *(int *)((int)param_1 + 0x18);
        local_58 = (undefined2)(uVar2 * 0x2000 >> 0x10);
        local_5c = *(int *)((int)param_1 + 0x14) * ((uVar2 & 0x7ffff) >> 3);
        local_54 = 0x5453494c;
        local_50 = 0x28;
        local_4c = 0x544d4349;
        local_48 = 0x20;
        if (param_2 == 1) {
          iVar1 = strlen(*(undefined4 *)((int)param_1 + 4));
          iVar3 = strlen(*(undefined4 *)((int)param_1 + 8));
          if ((uint)(iVar3 + iVar1) < 0x1f) {
            strcpy(auStack_44,*(undefined4 *)((int)param_1 + 4));
            strcat(auStack_44,0x20106558);
            strcat(auStack_44,*(undefined4 *)((int)param_1 + 8));
          }
        }
        else if (param_2 == 2) {
          strcpy(auStack_44,*(undefined4 *)param_1);
        }
        local_20 = 0;
        if (param_2 == 1) {
          pcVar4 = "I:\\FT-710\\PlayList";
        }
        local_24 = 0x61746164;
        if (param_2 != 1) {
          if (param_2 != 2) {
            return 0xfffffffe;
          }
          pcVar4 = "I:\\FT-710\\MESSAGE";
        }
        __aeabi_memclr4(&DAT_20810fcc,0x80);
        strcpy(&DAT_20810fcc,pcVar4);
        strcat(&DAT_20810fcc,DWORD_ARRAY_2010656c);
        strcat(&DAT_20810fcc,*(undefined4 *)param_1);
        strcat(&DAT_20810fcc,0x20106570);
        if (param_2 == 2) {
          FUN_20143b20(&DAT_20810fcc);
        }
        DAT_208000dc = fs_fopen(0x20810fcc,0x20106578);
        if ((DAT_208000dc == 0) &&
           (((DAT_208000bc = FUN_2014beec(pcVar4), DAT_208000bc != 0 &&
             ((DAT_208000bc = FUN_2014beec("I:\\FT-710"), DAT_208000bc != 0 ||
              (DAT_208000bc = FUN_2014beec(pcVar4), DAT_208000bc != 0)))) ||
            (DAT_208000dc = fs_fopen(0x20810fcc,0x20106578), DAT_208000dc == 0)))) {
          DAT_208000bc = fs_task_ctx_get();
        }
        else {
          uVar2 = fs_fwrite((uint)&local_78,0x5c,1,DAT_208000dc);
          if (uVar2 != 0) {
            return 0;
          }
          rec_close_abort();
        }
      }
    }
    return 0xfffffffe;
  }
  return 0xffffffff;
}


// ===== sd_is_full @ 20106588 (60 bytes)

/* drive 'I' free space == 0 */

uint sd_is_full(char param_1)

{
  int iVar1;
  uint uVar2;
  int local_10;
  int iStack_c;
  
  uVar2 = 0;
  iVar1 = FUN_2014b880((int)param_1,&local_10,&iStack_c);
  if ((iVar1 == 0) && (local_10 == 0 && iStack_c == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== task_audio_codec @ 201065c4 (2052 bytes)

void task_audio_codec(void)

{
  ushort uVar1;
  ushort *puVar2;
  byte bVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  uint unaff_r4;
  uint uVar9;
  bool bVar10;
  uint local_1004;
  ushort local_1000 [2000];
  int local_60;
  ushort *local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  
  DAT_208000d0 = 0;
  DAT_208000d4 = 0;
  DAT_208000cc = 0;
  audio_clear_error();
  DAT_208000c4 = itron_acre_mbf(0,&DAT_208000f8);
  if (DAT_208000c4 < 1) {
    DAT_208000b8 = DAT_208000b8 + 1;
    return;
  }
  local_50 = &DAT_2081105c;
  local_54 = 0x20811067;
  do {
    pvVar4 = itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,-1);
    if (pvVar4 != (void *)0x0) {
      DAT_208000b8 = DAT_208000b8 + 1;
      return;
    }
    if (local_1004 == 2) {
      DAT_208000cc = 2;
      DAT_208000e4 = 0;
      local_4c = (undefined4 *)0x0;
      local_48 = (undefined4 *)0x0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      uVar5 = sd_is_full('I');
      if (uVar5 == 0) {
        local_4c = &DAT_2081104c;
        local_3c = 2;
        local_48 = local_50;
        local_40 = 1;
        local_44 = local_54;
        local_38 = 16000;
        local_34 = 0x10;
        uVar5 = rec_open_wav(&local_4c,(uint)DAT_208000b3);
        if (uVar5 == 0) {
          DAT_208000b2 = 1;
          if (DAT_208000d0 != 0) {
            do {
              iVar6 = itron_trcv_mbf(DAT_208000c4,&local_60,0x1e);
              if (iVar6 == -0x32) {
                iVar6 = sd_state_bit6();
                if (iVar6 != 0) goto LAB_201068b8;
                DAT_208000d8 = -1;
                break;
              }
              if (iVar6 < 0) {
                DAT_208000b8 = DAT_208000b8 + 1;
                DAT_208000d8 = -9;
                break;
              }
              if (local_60 != 1) {
                DAT_208000b8 = DAT_208000b8 + 1;
                DAT_208000d8 = -9;
                break;
              }
              unaff_r4 = FUN_20105d14(local_5c);
              puVar2 = local_5c;
              if (unaff_r4 == 0) {
                uVar1 = *local_5c;
                if (uVar1 == 0) {
                  DAT_208000b8 = DAT_208000b8 + 1;
                  DAT_208000f4 = DAT_208000f4 + 1;
                  if (DAT_208000f4 < 4) goto LAB_201068b8;
                }
                iVar7 = 0;
                DAT_208000f4 = 0;
                __aeabi_memclr4(local_1000,4000);
                uVar9 = uVar1 + 2;
                uVar5 = 2;
                iVar6 = iVar7;
                if (2 < uVar9) {
                  do {
                    puVar8 = puVar2 + uVar5;
                    uVar5 = uVar5 + 1;
                    iVar7 = iVar6 + 2;
                    local_1000[iVar6] = *puVar8;
                    local_1000[iVar6 + 1] = *puVar8;
                    iVar6 = iVar7;
                  } while (uVar5 < uVar9);
                }
                unaff_r4 = rec_write(iVar7 * 2,(int)local_1000);
                if (unaff_r4 != 0) {
                  DAT_208000b8 = DAT_208000b8 + 1;
                  if (DAT_208000d8 != -1) {
                    DAT_208000d8 = -9;
                  }
                  break;
                }
                FUN_20101088(local_5c,4000);
                DAT_208000e4 = DAT_208000e4 + iVar7 * 2;
                if ((DAT_208000b3 == 2) && (0x57e3ff < DAT_208000e4)) break;
              }
              else {
                DAT_208000b8 = DAT_208000b8 + 1;
              }
LAB_201068b8:
            } while (DAT_208000d0 != 0);
          }
          DAT_208000b2 = 0;
          if (unaff_r4 != 0) {
            DAT_208000b8 = DAT_208000b8 + 1;
          }
          unaff_r4 = rec_finish();
          if (unaff_r4 != 0) {
            DAT_208000b8 = DAT_208000b8 + 1;
          }
          do {
            iVar6 = itron_trcv_mbf(DAT_208000c4,&local_60,0);
          } while (-1 < iVar6);
          DAT_208000d0 = 0;
          goto LAB_20106918;
        }
        DAT_208000d8 = -3;
      }
      else {
        DAT_208000d8 = -2;
      }
      DAT_208000d0 = 0;
    }
    else {
LAB_20106918:
      if (local_1004 == 4) {
        DAT_208000ec = 0;
        DAT_208000cc = 4;
        DAT_208000f0 = 0;
        DAT_208000b4 = 1;
        local_48 = (undefined4 *)0x0;
        local_44 = 0;
        local_40 = 0;
        local_38 = 0;
        local_3c = 0;
        local_34 = 0;
        local_30 = 0;
        local_4c = (undefined4 *)&DAT_20810fbc;
        local_2c = 0;
        unaff_r4 = wav_open_read((int *)&local_4c,(uint)DAT_208000b3);
        if (unaff_r4 == 0) {
          DAT_208000e4 = local_30;
          DAT_208000b0 = 0;
          DAT_208000b5 = 0;
          if (DAT_208000d4 != 0) {
LAB_201069b4:
            bVar3 = 0;
            unaff_r4 = play_prime(2);
            if (unaff_r4 == 0) {
              DAT_208000b1 = 1;
              itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,-1);
              DAT_208000b0 = DAT_208000b0 + 1;
              if (0xf < DAT_208000b0) {
                DAT_208000b0 = 0;
              }
              DAT_208000d4 = 1;
              DAT_208000cc = 4;
LAB_20106a5c:
              iVar6 = itron_trcv_mbf(DAT_208000c4,&local_60,0x1e);
              if (-1 < iVar6) {
                bVar3 = 0;
                DAT_208000f0 = DAT_208000f0 + 0xc80;
                if (local_60 == 2) {
                  if (0xff < DAT_2080858e) {
                    local_58 = play_advance();
                    unaff_r4 = play_read_block(local_58,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8)
                    ;
                    if (unaff_r4 == 0xfffffffb) {
                      if (local_58 == 0) goto LAB_20106bd0;
                      if (DAT_2080858e < 0x29a) {
                        __aeabi_memset(&DAT_208f4de0,0x11f80,0xf0);
                        uVar5 = (uint)DAT_208000b0;
                        (&DAT_208f4de0)[uVar5 * 0x11f8] = 0;
                        iVar6 = uVar5 * 0x11f8;
                        *(undefined1 *)(iVar6 + 0x208f4de1) = 0;
                        dcache_clean_range(&DAT_208f4de0 + iVar6,local_58);
                        itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,-1);
                        DAT_208000b0 = DAT_208000b0 + 1;
                        if (0xf < DAT_208000b0) {
                          DAT_208000b0 = 0;
                        }
                        goto LAB_20106d80;
                      }
                    }
                    else if (unaff_r4 == 0) goto LAB_20106cf4;
                    DAT_208000d8 = -9;
                    goto LAB_20106c3c;
                  }
                  __aeabi_memset(&DAT_208f4de0,0x11f80,0xf0);
                  uVar5 = (uint)DAT_208000b0;
                  (&DAT_208f4de0)[uVar5 * 0x11f8] = 0;
                  *(undefined1 *)(uVar5 * 0x11f8 + 0x208f4de1) = 0;
LAB_20106cf4:
                  dcache_clean_range(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8,local_58);
                  itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,-1);
                  DAT_208000b0 = DAT_208000b0 + 1;
                  if (0xf < DAT_208000b0) {
                    DAT_208000b0 = 0;
                  }
                  if (((DAT_208000b3 != 2) || (DAT_208000f0 < 0x57e400)) &&
                     ((DAT_208000e4 != DAT_208000ec || (DAT_208000f0 < DAT_208000e4))))
                  goto LAB_20106d80;
                }
LAB_20106bd0:
                DAT_208000d4 = 0;
                goto LAB_20106d8c;
              }
              iVar7 = sd_state_bit6();
              if (iVar7 == 0) {
                DAT_208000d8 = -1;
                DAT_208000d4 = 0;
                goto LAB_20106d8c;
              }
              if ((iVar6 != -0x32) || (bVar3 = bVar3 + 1, 8 < bVar3)) goto LAB_20106bd0;
              DAT_208000b8 = DAT_208000b8 + 1;
LAB_20106d80:
              while( true ) {
                if (DAT_208000d4 == 0) goto LAB_20106d8c;
                if (DAT_208000d4 != 2) break;
                DAT_208000b1 = 0;
                DAT_208000cc = 8;
                itron_tslp_tsk(1);
              }
              if (DAT_208000cc == 8) {
                do {
                  iVar6 = itron_trcv_mbf(DAT_208000c4,&local_60,0);
                } while (-1 < iVar6);
                DAT_208000b5 = 0;
                unaff_r4 = play_seek(DAT_208000f0);
              }
              else {
                if (DAT_208000d4 != 3) break;
                DAT_208000b1 = 0;
                DAT_208000cc = 0x20;
                do {
                  iVar6 = itron_trcv_mbf(DAT_208000c4,&local_60,0);
                } while (-1 < iVar6);
                DAT_208000f0 = DAT_208000f0 + 320000;
                if (DAT_208000e4 <= DAT_208000f0) {
                  DAT_208000f0 = DAT_208000e4 - 0xc80;
                }
                unaff_r4 = play_seek(DAT_208000f0);
              }
              if (unaff_r4 == 0) goto LAB_20106ad8;
              goto LAB_20106acc;
            }
            DAT_208000b8 = DAT_208000b8 + 1;
            DAT_208000d8 = -9;
          }
LAB_20106d8c:
          DAT_208000b1 = 0;
          FUN_201050ac();
          DAT_208000d4 = 0;
          do {
            iVar6 = itron_trcv_mbf(DAT_208000c4,&local_60,0);
          } while (-1 < iVar6);
        }
        else {
          DAT_208000d8 = -4;
        }
      }
    }
    DAT_208000cc = 0;
  } while( true );
  if (DAT_208000d4 == 4) goto LAB_20106b44;
  goto LAB_20106a5c;
LAB_20106b44:
  DAT_208000b1 = 0;
  DAT_208000cc = 0x10;
  do {
    iVar6 = itron_trcv_mbf(DAT_208000c4,&local_60,0);
  } while (-1 < iVar6);
  bVar10 = DAT_208000f0 < 320000;
  DAT_208000f0 = DAT_208000f0 - 320000;
  iVar6 = -(uint)bVar10;
  if ((int)-(iVar6 + (uint)(DAT_208000f0 != 0)) < 0 ==
      (SBORROW4(0,iVar6) != SBORROW4((uint)bVar10,(uint)(DAT_208000f0 != 0)))) {
    DAT_208000f0 = 0;
  }
  unaff_r4 = play_seek(DAT_208000f0);
  if (unaff_r4 != 0) {
LAB_20106acc:
    DAT_208000d8 = -3;
LAB_20106c3c:
    DAT_208000d4 = 0;
    goto LAB_20106d8c;
  }
LAB_20106ad8:
  DAT_208000ec = DAT_208000f0;
  if (DAT_208000d4 == 0) goto LAB_20106d8c;
  goto LAB_201069b4;
}


// ===== audio_codec_post @ 20106dc8 (44 bytes)

/* 8-byte msg to task_audio_codec mailbox */

void audio_codec_post(uint param_1,uint param_2)

{
  uint local_10;
  uint uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  itron_tsnd_mbf(DAT_208000c4,&local_10,8,0);
  return;
}

