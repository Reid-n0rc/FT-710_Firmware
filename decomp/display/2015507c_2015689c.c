// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2015507c @ 2015507c (88 bytes)

int FUN_2015507c(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      uVar5 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      if (uVar5 != uVar3) {
        if ((uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18) <=
            (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18)) {
          return -1;
        }
        return 1;
      }
    }
  }
  if (param_3 != 0) {
    if ((param_3 & 1) == 0) goto LAB_201550b4;
    param_3 = param_3 + 1;
    puVar1 = param_1;
    puVar2 = param_2;
    while( true ) {
      param_1 = (uint *)((int)puVar1 + 1);
      param_2 = (uint *)((int)puVar2 + 1);
      iVar4 = (uint)(byte)*puVar1 - (uint)(byte)*puVar2;
      if (iVar4 != 0) {
        return iVar4;
      }
      param_3 = param_3 - 2;
      if (param_3 == 0) break;
LAB_201550b4:
      puVar1 = (uint *)((int)param_1 + 1);
      puVar2 = (uint *)((int)param_2 + 1);
      iVar4 = (uint)(byte)*param_1 - (uint)(byte)*param_2;
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    return 0;
  }
  return 0;
}


// ===== FUN_201550dc @ 201550dc (70 bytes)

void FUN_201550dc(uint *param_1,uint *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while( true ) {
      uVar8 = *param_2;
      param_2 = param_2 + 1;
      uVar2 = UnsignedSaturate(1 - (uVar8 & 0xff),8);
      uVar3 = UnsignedSaturate(1 - (uVar8 >> 8 & 0xff),8);
      uVar4 = UnsignedSaturate(1 - (uVar8 >> 0x10 & 0xff),8);
      uVar5 = UnsignedSaturate(1 - (uVar8 >> 0x18),8);
      if (CONCAT13((char)uVar5,CONCAT12((char)uVar4,CONCAT11((char)uVar3,(char)uVar2))) != 0) break;
      *param_1 = uVar8;
      param_1 = param_1 + 1;
    }
    while( true ) {
      *(char *)param_1 = (char)uVar8;
      if ((uVar8 & 0xff) == 0) break;
      uVar8 = uVar8 >> 8;
      param_1 = (uint *)((int)param_1 + 1);
    }
  }
  else {
    do {
      pcVar6 = (char *)((int)param_2 + 1);
      uVar8 = *param_2;
      pcVar7 = (char *)((int)param_1 + 1);
      *(char *)param_1 = (char)uVar8;
      if ((char)uVar8 == '\0') {
        return;
      }
      param_2 = (uint *)((int)param_2 + 2);
      cVar1 = *pcVar6;
      param_1 = (uint *)((int)param_1 + 2);
      *pcVar7 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ===== FUN_20155122 @ 20155122 (58 bytes)

int FUN_20155122(uint *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short sVar5;
  int3 iVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  
  puVar8 = param_1;
  while (((uint)puVar8 & 3) != 0) {
    puVar7 = (uint *)((int)puVar8 + 1);
    uVar10 = *puVar8;
    puVar8 = puVar7;
    if ((char)uVar10 == '\0') {
      return (int)puVar7 - ((int)param_1 + 1);
    }
  }
  do {
    uVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    uVar1 = UnsignedSaturate(1 - (uVar10 & 0xff),8);
    uVar2 = UnsignedSaturate(1 - (uVar10 >> 8 & 0xff),8);
    uVar3 = UnsignedSaturate(1 - (uVar10 >> 0x10 & 0xff),8);
    uVar4 = UnsignedSaturate(1 - (uVar10 >> 0x18),8);
    sVar5 = CONCAT11((char)uVar2,(char)uVar1);
    iVar6 = CONCAT12((char)uVar3,sVar5);
  } while (CONCAT13((char)uVar4,iVar6) == 0);
  iVar9 = (int)puVar8 - (int)((int)param_1 + 1);
  if ((char)uVar1 == '\0') {
    if (sVar5 == 0) {
      if (iVar6 != 0) {
        return iVar9 + -1;
      }
    }
    else {
      iVar9 = iVar9 + -2;
    }
    return iVar9;
  }
  return iVar9 + -3;
}


// ===== FUN_2015515c @ 2015515c (36 bytes)

void FUN_2015515c(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + -1);
  do {
    pcVar2 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  do {
    cVar1 = *param_2;
    *pcVar2 = cVar1;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return;
}


// ===== memcpy @ 20155180 (212 bytes)

undefined8 memcpy(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  byte *pbVar3;
  uint *puVar4;
  byte bVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  uint in_r12;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  
  if (3 < param_3) {
    uVar14 = (uint)param_1 & 3;
    in_r12 = uVar14;
    if (uVar14 != 0) {
      bVar5 = (byte)*param_2;
      puVar2 = (uint *)((int)param_2 + 1);
      if (uVar14 < 3) {
        puVar2 = (uint *)((int)param_2 + 2);
        in_r12 = (uint)*(byte *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar5;
      param_2 = puVar2;
      if (uVar14 < 2) {
        param_2 = (uint *)((int)puVar2 + 1);
        bVar5 = (byte)*puVar2;
      }
      puVar2 = (uint *)((int)param_1 + 1);
      if (uVar14 < 3) {
        puVar2 = (uint *)((int)param_1 + 2);
        *(byte *)((int)param_1 + 1) = (byte)in_r12;
      }
      param_3 = (param_3 + uVar14) - 4;
      param_1 = puVar2;
      if (uVar14 < 2) {
        param_1 = (uint *)((int)puVar2 + 1);
        *(byte *)puVar2 = bVar5;
      }
    }
    param_4 = (uint)param_2 & 3;
    if (param_4 == 0) {
      uVar14 = param_3 - 0x20;
      uVar7 = 0;
      if (0x1f < param_3) {
        for (; 0x7f < uVar14; uVar14 = uVar14 - 0x20) {
          HintPreloadData(param_2 + 0x20);
          uVar7 = *param_2;
          uVar8 = param_2[1];
          uVar9 = param_2[2];
          uVar10 = param_2[3];
          uVar11 = param_2[4];
          uVar12 = param_2[5];
          uVar15 = param_2[6];
          uVar16 = param_2[7];
          param_2 = param_2 + 8;
          *param_1 = uVar7;
          param_1[1] = uVar8;
          param_1[2] = uVar9;
          param_1[3] = uVar10;
          param_1[4] = uVar11;
          param_1[5] = uVar12;
          param_1[6] = uVar15;
          param_1[7] = uVar16;
          param_1 = param_1 + 8;
        }
        do {
          uVar7 = *param_2;
          uVar8 = param_2[1];
          uVar9 = param_2[2];
          uVar10 = param_2[3];
          uVar11 = param_2[4];
          uVar12 = param_2[5];
          uVar15 = param_2[6];
          uVar16 = param_2[7];
          param_2 = param_2 + 8;
          bVar17 = 0x1f < uVar14;
          uVar14 = uVar14 - 0x20;
          *param_1 = uVar7;
          param_1[1] = uVar8;
          param_1[2] = uVar9;
          param_1[3] = uVar10;
          param_1[4] = uVar11;
          param_1[5] = uVar12;
          param_1[6] = uVar15;
          param_1[7] = uVar16;
          param_1 = param_1 + 8;
        } while (bVar17);
      }
      if ((bool)((byte)(uVar14 >> 4) & 1)) {
        uVar7 = *param_2;
        uVar8 = param_2[1];
        uVar9 = param_2[2];
        uVar10 = param_2[3];
        param_2 = param_2 + 4;
        *param_1 = uVar7;
        param_1[1] = uVar8;
        param_1[2] = uVar9;
        param_1[3] = uVar10;
        param_1 = param_1 + 4;
      }
      if ((int)(uVar14 << 0x1c) < 0) {
        uVar7 = *param_2;
        uVar8 = param_2[1];
        param_2 = param_2 + 2;
        *param_1 = uVar7;
        param_1[1] = uVar8;
        param_1 = param_1 + 2;
      }
      puVar1 = param_1;
      puVar2 = param_2;
      if ((bool)((byte)(uVar14 >> 2) & 1)) {
        puVar2 = param_2 + 1;
        uVar7 = *param_2;
        puVar1 = param_1 + 1;
        *param_1 = uVar7;
      }
      uVar6 = (undefined2)uVar7;
      if ((uVar14 & 3) != 0) {
        bVar18 = (bool)((byte)(uVar14 >> 1) & 1);
        uVar14 = uVar14 << 0x1f;
        bVar17 = (int)uVar14 < 0;
        puVar4 = puVar2;
        if (bVar18) {
          puVar4 = (uint *)((int)puVar2 + 2);
          uVar6 = (undefined2)*puVar2;
        }
        puVar2 = puVar4;
        if (bVar17) {
          puVar2 = (uint *)((int)puVar4 + 1);
          uVar14 = (uint)(byte)*puVar4;
        }
        puVar4 = puVar1;
        if (bVar18) {
          puVar4 = (uint *)((int)puVar1 + 2);
          *(undefined2 *)puVar1 = uVar6;
        }
        puVar1 = puVar4;
        if (bVar17) {
          puVar1 = (uint *)((int)puVar4 + 1);
          *(byte *)puVar4 = (byte)uVar14;
        }
        return CONCAT44(puVar2,puVar1);
      }
      return CONCAT44(puVar2,puVar1);
    }
    bVar17 = 3 < param_3;
    param_3 = param_3 - 4;
    if (bVar17) {
      param_2 = (uint *)((int)param_2 - param_4);
      in_r12 = *param_2;
      puVar2 = param_1;
      if (param_4 == 2) {
        do {
          puVar1 = param_2;
          param_4 = in_r12 >> 0x10;
          param_2 = puVar1 + 1;
          in_r12 = *param_2;
          bVar17 = 3 < param_3;
          param_3 = param_3 - 4;
          param_4 = param_4 | in_r12 << 0x10;
          param_1 = puVar2 + 1;
          *puVar2 = param_4;
          puVar2 = param_1;
        } while (bVar17);
        param_2 = (uint *)((int)puVar1 + 6);
      }
      else if (param_4 < 3) {
        do {
          puVar1 = param_2;
          param_4 = in_r12 >> 8;
          param_2 = puVar1 + 1;
          in_r12 = *param_2;
          bVar17 = 3 < param_3;
          param_3 = param_3 - 4;
          param_4 = param_4 | in_r12 << 0x18;
          param_1 = puVar2 + 1;
          *puVar2 = param_4;
          puVar2 = param_1;
        } while (bVar17);
        param_2 = (uint *)((int)puVar1 + 5);
      }
      else {
        do {
          puVar1 = param_2;
          param_4 = in_r12 >> 0x18;
          param_2 = puVar1 + 1;
          in_r12 = *param_2;
          bVar17 = 3 < param_3;
          param_3 = param_3 - 4;
          param_4 = param_4 | in_r12 << 8;
          param_1 = puVar2 + 1;
          *puVar2 = param_4;
          puVar2 = param_1;
        } while (bVar17);
        param_2 = (uint *)((int)puVar1 + 7);
      }
    }
  }
  bVar13 = (byte)in_r12;
  bVar5 = (byte)param_4;
  bVar18 = (bool)((byte)(param_3 >> 1) & 1);
  param_3 = param_3 << 0x1f;
  bVar17 = (int)param_3 < 0;
  if (bVar18) {
    pbVar3 = (byte *)((int)param_2 + 1);
    bVar5 = (byte)*param_2;
    param_2 = (uint *)((int)param_2 + 2);
    bVar13 = *pbVar3;
  }
  puVar2 = param_2;
  if (bVar17) {
    puVar2 = (uint *)((int)param_2 + 1);
    param_3 = (uint)(byte)*param_2;
  }
  if (bVar18) {
    pbVar3 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = bVar5;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar3 = bVar13;
  }
  puVar1 = param_1;
  if (bVar17) {
    puVar1 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  return CONCAT44(puVar2,puVar1);
}


// ===== FUN_20155254 @ 20155254 (8 bytes)

undefined4 * FUN_20155254(undefined4 *param_1,uint param_2,undefined1 param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  uVar1 = CONCAT11(param_3,param_3);
  uVar6 = CONCAT22(uVar1,uVar1);
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar3 = (undefined1 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar3 = param_3;
    }
    puVar2 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
    }
    return puVar2;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar7 = 4 - ((uint)param_1 & 3);
    puVar2 = param_1;
    if (iVar7 != 2) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
    }
    param_1 = puVar2;
    if (1 < iVar7) {
      param_1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
    }
    param_2 = param_2 - iVar7;
  }
  bVar8 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar8) {
      *param_1 = uVar6;
      param_1[1] = uVar6;
      param_1[2] = uVar6;
      param_1[3] = uVar6;
      param_1[4] = uVar6;
      param_1[5] = uVar6;
      param_1[6] = uVar6;
      param_1[7] = uVar6;
      param_1 = param_1 + 8;
      bVar8 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar8);
  if ((param_2 & 0x10) != 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1[2] = uVar6;
    param_1[3] = uVar6;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1 = param_1 + 2;
  }
  uVar5 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = uVar6;
  }
  if (uVar5 == 0) {
    return puVar2;
  }
  puVar4 = puVar2;
  if ((int)uVar5 < 0) {
    puVar4 = (undefined4 *)((int)puVar2 + 2);
    *(undefined2 *)puVar2 = uVar1;
  }
  puVar2 = puVar4;
  if ((uVar5 & 0x40000000) != 0) {
    puVar2 = (undefined4 *)((int)puVar4 + 1);
    *(undefined1 *)puVar4 = param_3;
  }
  return puVar2;
}


// ===== FUN_2015525c @ 2015525c (16 bytes)

undefined4 * FUN_2015525c(undefined4 *param_1,uint param_2,undefined1 param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  uVar1 = CONCAT11(param_3,param_3);
  uVar6 = CONCAT22(uVar1,uVar1);
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar3 = (undefined1 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar3 = param_3;
    }
    puVar2 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
    }
    return puVar2;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar7 = 4 - ((uint)param_1 & 3);
    puVar2 = param_1;
    if (iVar7 != 2) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
    }
    param_1 = puVar2;
    if (1 < iVar7) {
      param_1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
    }
    param_2 = param_2 - iVar7;
  }
  bVar8 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar8) {
      *param_1 = uVar6;
      param_1[1] = uVar6;
      param_1[2] = uVar6;
      param_1[3] = uVar6;
      param_1[4] = uVar6;
      param_1[5] = uVar6;
      param_1[6] = uVar6;
      param_1[7] = uVar6;
      param_1 = param_1 + 8;
      bVar8 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar8);
  if ((param_2 & 0x10) != 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1[2] = uVar6;
    param_1[3] = uVar6;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1 = param_1 + 2;
  }
  uVar5 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = uVar6;
  }
  if (uVar5 != 0) {
    puVar4 = puVar2;
    if ((int)uVar5 < 0) {
      puVar4 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
    }
    puVar2 = puVar4;
    if ((uVar5 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar4 + 1);
      *(undefined1 *)puVar4 = param_3;
    }
    return puVar2;
  }
  return puVar2;
}


// ===== FUN_2015526c @ 2015526c (8 bytes)

undefined4 * FUN_2015526c(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar2 = (undefined1 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar2 = 0;
    }
    puVar1 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    return puVar1;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar5 = 4 - ((uint)param_1 & 3);
    puVar1 = param_1;
    if (iVar5 != 2) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    param_1 = puVar1;
    if (1 < iVar5) {
      param_1 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    param_2 = param_2 - iVar5;
  }
  bVar6 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar6) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar6 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar6);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar4 = param_2 << 0x1e;
  puVar1 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar1 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar4 == 0) {
    return puVar1;
  }
  puVar3 = puVar1;
  if ((int)uVar4 < 0) {
    puVar3 = (undefined4 *)((int)puVar1 + 2);
    *(undefined2 *)puVar1 = 0;
  }
  puVar1 = puVar3;
  if ((uVar4 & 0x40000000) != 0) {
    puVar1 = (undefined4 *)((int)puVar3 + 1);
    *(undefined1 *)puVar3 = 0;
  }
  return puVar1;
}


// ===== FUN_20155274 @ 20155274 (68 bytes)

undefined4 * FUN_20155274(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar2 = (undefined1 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar2 = 0;
    }
    puVar1 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    return puVar1;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar5 = 4 - ((uint)param_1 & 3);
    puVar1 = param_1;
    if (iVar5 != 2) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    param_1 = puVar1;
    if (1 < iVar5) {
      param_1 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    param_2 = param_2 - iVar5;
  }
  bVar6 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar6) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar6 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar6);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar4 = param_2 << 0x1e;
  puVar1 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar1 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar4 != 0) {
    puVar3 = puVar1;
    if ((int)uVar4 < 0) {
      puVar3 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    puVar1 = puVar3;
    if ((uVar4 & 0x40000000) != 0) {
      puVar1 = (undefined4 *)((int)puVar3 + 1);
      *(undefined1 *)puVar3 = 0;
    }
    return puVar1;
  }
  return puVar1;
}


// ===== memclr @ 201552c0 (78 bytes)

undefined4 * memclr(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar4) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar4 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar4);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar3 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar3 != 0) {
    puVar1 = puVar2;
    if ((int)uVar3 < 0) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = 0;
    }
    puVar2 = puVar1;
    if ((uVar3 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(undefined1 *)puVar1 = 0;
    }
    return puVar2;
  }
  return puVar2;
}


// ===== FUN_20155310 @ 20155310 (124 bytes)

undefined8 FUN_20155310(undefined4 *param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  bool bVar15;
  bool bVar16;
  
  uVar5 = param_3 - 0x20;
  if (0x1f < param_3) {
    for (; 0x7f < uVar5; uVar5 = uVar5 - 0x20) {
      HintPreloadData(param_2 + 0x80);
      uVar7 = *(undefined4 *)param_2;
      uVar8 = *(undefined4 *)(param_2 + 4);
      uVar9 = *(undefined4 *)(param_2 + 8);
      uVar10 = *(undefined4 *)(param_2 + 0xc);
      uVar11 = *(undefined4 *)(param_2 + 0x10);
      uVar12 = *(undefined4 *)(param_2 + 0x14);
      uVar13 = *(undefined4 *)(param_2 + 0x18);
      uVar14 = *(undefined4 *)(param_2 + 0x1c);
      param_2 = param_2 + 0x20;
      *param_1 = uVar7;
      param_1[1] = uVar8;
      param_1[2] = uVar9;
      param_1[3] = uVar10;
      param_1[4] = uVar11;
      param_1[5] = uVar12;
      param_1[6] = uVar13;
      param_1[7] = uVar14;
      param_1 = param_1 + 8;
    }
    do {
      param_4 = *(undefined4 *)param_2;
      uVar7 = *(undefined4 *)(param_2 + 4);
      uVar8 = *(undefined4 *)(param_2 + 8);
      uVar9 = *(undefined4 *)(param_2 + 0xc);
      uVar10 = *(undefined4 *)(param_2 + 0x10);
      uVar11 = *(undefined4 *)(param_2 + 0x14);
      uVar12 = *(undefined4 *)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(param_2 + 0x1c);
      param_2 = param_2 + 0x20;
      bVar15 = 0x1f < uVar5;
      uVar5 = uVar5 - 0x20;
      *param_1 = param_4;
      param_1[1] = uVar7;
      param_1[2] = uVar8;
      param_1[3] = uVar9;
      param_1[4] = uVar10;
      param_1[5] = uVar11;
      param_1[6] = uVar12;
      param_1[7] = uVar13;
      param_1 = param_1 + 8;
    } while (bVar15);
  }
  if ((bool)((byte)(uVar5 >> 4) & 1)) {
    param_4 = *(undefined4 *)param_2;
    uVar7 = *(undefined4 *)(param_2 + 4);
    uVar8 = *(undefined4 *)(param_2 + 8);
    uVar9 = *(undefined4 *)(param_2 + 0xc);
    param_2 = param_2 + 0x10;
    *param_1 = param_4;
    param_1[1] = uVar7;
    param_1[2] = uVar8;
    param_1[3] = uVar9;
    param_1 = param_1 + 4;
  }
  if ((int)(uVar5 << 0x1c) < 0) {
    param_4 = *(undefined4 *)param_2;
    uVar7 = *(undefined4 *)(param_2 + 4);
    param_2 = param_2 + 8;
    *param_1 = param_4;
    param_1[1] = uVar7;
    param_1 = param_1 + 2;
  }
  puVar2 = param_1;
  pbVar3 = param_2;
  if ((bool)((byte)(uVar5 >> 2) & 1)) {
    pbVar3 = param_2 + 4;
    param_4 = *(undefined4 *)param_2;
    puVar2 = param_1 + 1;
    *param_1 = param_4;
  }
  uVar6 = (undefined2)param_4;
  if ((uVar5 & 3) != 0) {
    bVar16 = (bool)((byte)(uVar5 >> 1) & 1);
    uVar5 = uVar5 << 0x1f;
    bVar15 = (int)uVar5 < 0;
    pbVar4 = pbVar3;
    if (bVar16) {
      pbVar4 = pbVar3 + 2;
      uVar6 = *(undefined2 *)pbVar3;
    }
    pbVar3 = pbVar4;
    if (bVar15) {
      pbVar3 = pbVar4 + 1;
      uVar5 = (uint)*pbVar4;
    }
    puVar1 = puVar2;
    if (bVar16) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar6;
    }
    puVar2 = puVar1;
    if (bVar15) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(char *)puVar1 = (char)uVar5;
    }
    return CONCAT44(pbVar3,puVar2);
  }
  return CONCAT44(pbVar3,puVar2);
}


// ===== strcmp @ 2015538c (240 bytes)

uint strcmp(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  byte *pbVar4;
  uint *puVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  if ((((uint)param_1 ^ (uint)param_2) & 3) == 0) {
    puVar1 = param_1;
    puVar5 = param_2;
    if (((uint)param_1 & 3) != 0) {
      puVar1 = (uint *)((int)param_1 + 1);
      uVar7 = (uint)(byte)*param_1;
      uVar8 = (uint)(byte)*param_2;
      bVar10 = uVar7 == 1;
      if (uVar7 != 0) {
        bVar10 = uVar7 == uVar8;
      }
      if (!bVar10) goto LAB_20155474;
      puVar5 = (uint *)((int)param_2 + 1);
      if (((uint)puVar1 & 3) != 0) {
        puVar2 = (uint *)((int)param_1 + 2);
        uVar7 = (uint)*(byte *)puVar1;
        uVar8 = (uint)*(byte *)((int)param_2 + 1);
        bVar10 = uVar7 == 1;
        if (uVar7 != 0) {
          bVar10 = uVar7 == uVar8;
        }
        if (!bVar10) goto LAB_20155474;
        puVar1 = puVar2;
        puVar5 = (uint *)((int)param_2 + 2);
        if (((uint)puVar2 & 3) != 0) {
          puVar1 = (uint *)((int)param_1 + 3);
          uVar7 = (uint)*(byte *)puVar2;
          puVar5 = (uint *)((int)param_2 + 3);
          uVar8 = (uint)*(byte *)((int)param_2 + 2);
          bVar10 = uVar7 == 1;
          if (uVar7 != 0) {
            bVar10 = uVar7 == uVar8;
          }
          if (!bVar10) goto LAB_20155474;
        }
      }
    }
    do {
      uVar7 = *puVar1;
      uVar8 = *puVar5;
      uVar9 = uVar7 + 0xfefefeff & ~uVar7;
      puVar1 = puVar1 + 1;
      puVar5 = puVar5 + 1;
    } while ((uVar9 & 0x80808080) == 0 && uVar7 == uVar8);
    uVar3 = uVar8 * 0x1000000 + uVar7 * -0x1000000;
    bVar11 = uVar3 == 0;
    bVar13 = !bVar11 && uVar7 * 0x1000000 <= uVar8 * 0x1000000;
    bVar12 = (uVar9 & 0x80) == 0;
    bVar10 = bVar11 && bVar12;
    if (bVar11 && bVar12) {
      uVar3 = uVar8 * 0x10000 + uVar7 * -0x10000;
      bVar11 = uVar3 == 0;
      bVar13 = !bVar11 && uVar7 * 0x10000 <= uVar8 * 0x10000;
      bVar12 = (uVar9 & 0x8000) == 0;
      bVar10 = bVar11 && bVar12;
      if (bVar11 && bVar12) {
        uVar3 = uVar8 * 0x100 + uVar7 * -0x100;
        bVar11 = uVar3 == 0;
        bVar13 = !bVar11 && uVar7 * 0x100 <= uVar8 * 0x100;
        bVar12 = (uVar9 & 0x800000) == 0;
        bVar10 = bVar11 && bVar12;
        if (bVar11 && bVar12) {
          bVar13 = uVar7 <= uVar8;
          uVar3 = uVar8 - uVar7;
          bVar10 = uVar3 == 0;
        }
      }
    }
    if (!bVar10) {
      uVar3 = (uint)bVar13 << 0x1f | uVar3 >> 1;
    }
    return uVar3;
  }
  do {
    pbVar4 = (byte *)((int)param_1 + 1);
    uVar7 = (uint)(byte)*param_1;
    pbVar6 = (byte *)((int)param_2 + 1);
    uVar8 = (uint)(byte)*param_2;
    bVar10 = uVar7 == 1;
    if (uVar7 != 0) {
      bVar10 = uVar7 == uVar8;
    }
    if (!bVar10) break;
    param_1 = (uint *)((int)param_1 + 2);
    uVar7 = (uint)*pbVar4;
    param_2 = (uint *)((int)param_2 + 2);
    uVar8 = (uint)*pbVar6;
    bVar10 = uVar7 == 1;
    if (uVar7 != 0) {
      bVar10 = uVar7 == uVar8;
    }
  } while (bVar10);
LAB_20155474:
  return uVar7 - uVar8;
}


// ===== __aeabi_uidivmod @ 20155480 (556 bytes)

longlong __aeabi_uidivmod(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  if ((int)(param_1 | param_2) < 0) {
    uVar5 = param_2 & 0x80000000;
    if ((int)uVar5 < 0) {
      param_2 = -param_2;
    }
    uVar4 = uVar5 ^ (int)param_1 >> 0x20;
    if (SUB41(param_1 >> 0x1f,0)) {
      param_1 = -param_1;
    }
    iVar3 = (int)uVar4 >> 0x1f;
    uVar2 = param_2;
    if (param_1 >> 4 < param_2) goto LAB_20155650;
    if (param_1 >> 8 < param_2) goto LAB_20155620;
    uVar2 = param_2 << 6;
    uVar5 = 0xfc000000;
    if (param_1 >> 8 < uVar2) goto LAB_20155620;
    uVar2 = param_2 << 0xc;
    uVar5 = 0xfff00000;
    if (param_1 >> 8 < uVar2) goto LAB_20155620;
    uVar2 = param_2 << 0x12;
    uVar5 = 0xffffc000;
    if (uVar2 <= param_1 >> 8) {
      uVar2 = param_2 << 0x18;
      uVar5 = 0xffffff00;
    }
    bVar7 = uVar2 == 0;
    if (!bVar7) {
      do {
        if (bVar7) {
          uVar2 = uVar2 >> 6;
        }
LAB_20155620:
        bVar7 = uVar2 <= param_1 >> 7;
        if (bVar7) {
          param_1 = param_1 + uVar2 * -0x80;
        }
        bVar8 = uVar2 <= param_1 >> 6;
        if (bVar8) {
          param_1 = param_1 + uVar2 * -0x40;
        }
        bVar9 = uVar2 <= param_1 >> 5;
        if (bVar9) {
          param_1 = param_1 + uVar2 * -0x20;
        }
        bVar10 = uVar2 <= param_1 >> 4;
        if (bVar10) {
          param_1 = param_1 + uVar2 * -0x10;
        }
        uVar5 = (((uVar5 * 2 + (uint)bVar7) * 2 + (uint)bVar8) * 2 + (uint)bVar9) * 2 + (uint)bVar10
        ;
LAB_20155650:
        bVar7 = uVar2 <= param_1 >> 3;
        if (bVar7) {
          param_1 = param_1 + uVar2 * -8;
        }
        uVar6 = uVar5 * 2 + (uint)bVar7;
        bVar8 = uVar2 <= param_1 >> 2;
        if (bVar8) {
          param_1 = param_1 + uVar2 * -4;
        }
        uVar5 = uVar6 * 2 + (uint)bVar8;
        bVar7 = true;
      } while (CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar8));
      bVar7 = uVar2 <= param_1 >> 1;
      if (bVar7) {
        param_1 = param_1 + uVar2 * -2;
      }
      uVar6 = param_1 - uVar2;
      if (uVar2 > param_1) {
        uVar6 = param_1;
      }
      iVar1 = (uVar5 * 2 + (uint)bVar7) * 2 + (uint)(uVar2 <= param_1);
      if (iVar3 < 0) {
        iVar1 = -iVar1;
      }
      if ((bool)((byte)(uVar4 >> 0x1e) & 1)) {
        uVar6 = -uVar6;
      }
      return CONCAT44(uVar6,iVar1);
    }
    if (iVar3 < 0) {
      param_1 = -param_1;
    }
LAB_2015569c:
    return (ulonglong)param_1 << 0x20;
  }
  if (param_1 >> 1 < param_2) {
    if (param_1 < param_2) {
      return (ulonglong)param_1 << 0x20;
    }
    return CONCAT44(param_1 - param_2,1);
  }
  iVar3 = 0;
  uVar5 = param_2;
  if (param_2 <= param_1 >> 4) {
    if (param_2 <= param_1 >> 8) {
      if (param_1 >> 0xc < param_2) goto LAB_2015550c;
      if (param_1 >> 0x10 < param_2) goto LAB_201554dc;
      uVar5 = param_2 << 8;
      iVar3 = -0x1000000;
      if (uVar5 <= param_1 >> 0x10) {
        iVar3 = -0x10000;
        uVar5 = param_2 << 0x10;
      }
      if (param_1 >> 0xc < uVar5) goto LAB_2015550c;
      bVar7 = false;
      if (uVar5 == 0) goto LAB_2015569c;
      do {
        if (bVar7) {
          uVar5 = uVar5 >> 8;
        }
LAB_201554dc:
        bVar7 = uVar5 <= param_1 >> 0xf;
        if (bVar7) {
          param_1 = param_1 + uVar5 * -0x8000;
        }
        bVar8 = uVar5 <= param_1 >> 0xe;
        if (bVar8) {
          param_1 = param_1 + uVar5 * -0x4000;
        }
        bVar9 = uVar5 <= param_1 >> 0xd;
        if (bVar9) {
          param_1 = param_1 + uVar5 * -0x2000;
        }
        bVar10 = uVar5 <= param_1 >> 0xc;
        if (bVar10) {
          param_1 = param_1 + uVar5 * -0x1000;
        }
        iVar3 = (((iVar3 * 2 + (uint)bVar7) * 2 + (uint)bVar8) * 2 + (uint)bVar9) * 2 + (uint)bVar10
        ;
LAB_2015550c:
        bVar7 = uVar5 <= param_1 >> 0xb;
        if (bVar7) {
          param_1 = param_1 + uVar5 * -0x800;
        }
        bVar8 = uVar5 <= param_1 >> 10;
        if (bVar8) {
          param_1 = param_1 + uVar5 * -0x400;
        }
        bVar9 = uVar5 <= param_1 >> 9;
        if (bVar9) {
          param_1 = param_1 + uVar5 * -0x200;
        }
        uVar4 = ((iVar3 * 2 + (uint)bVar7) * 2 + (uint)bVar8) * 2 + (uint)bVar9;
        bVar8 = uVar5 <= param_1 >> 8;
        if (bVar8) {
          param_1 = param_1 + uVar5 * -0x100;
        }
        iVar3 = uVar4 * 2 + (uint)bVar8;
        bVar7 = true;
      } while (CARRY4(uVar4,uVar4) || CARRY4(uVar4 * 2,(uint)bVar8));
    }
    bVar7 = uVar5 <= param_1 >> 7;
    if (bVar7) {
      param_1 = param_1 + uVar5 * -0x80;
    }
    bVar8 = uVar5 <= param_1 >> 6;
    if (bVar8) {
      param_1 = param_1 + uVar5 * -0x40;
    }
    bVar9 = uVar5 <= param_1 >> 5;
    if (bVar9) {
      param_1 = param_1 + uVar5 * -0x20;
    }
    bVar10 = uVar5 <= param_1 >> 4;
    if (bVar10) {
      param_1 = param_1 + uVar5 * -0x10;
    }
    iVar3 = (((iVar3 * 2 + (uint)bVar7) * 2 + (uint)bVar8) * 2 + (uint)bVar9) * 2 + (uint)bVar10;
  }
  bVar7 = uVar5 <= param_1 >> 3;
  if (bVar7) {
    param_1 = param_1 + uVar5 * -8;
  }
  bVar8 = uVar5 <= param_1 >> 2;
  if (bVar8) {
    param_1 = param_1 + uVar5 * -4;
  }
  bVar9 = uVar5 <= param_1 >> 1;
  if (bVar9) {
    param_1 = param_1 + uVar5 * -2;
  }
  uVar4 = param_1 - uVar5;
  if (uVar5 > param_1) {
    uVar4 = param_1;
  }
  return CONCAT44(uVar4,(((iVar3 * 2 + (uint)bVar7) * 2 + (uint)bVar8) * 2 + (uint)bVar9) * 2 +
                        (uint)(uVar5 <= param_1));
}


// ===== FUN_201556ac @ 201556ac (26 bytes)

void FUN_201556ac(void)

{
  byte *pbVar1;
  
  for (pbVar1 = BYTE_ARRAY_204286f8 + 300; pbVar1 != BYTE_ARRAY_204286f8 + 0x13c;
      pbVar1 = pbVar1 + 4) {
    (*(code *)(pbVar1 + *(int *)pbVar1))();
  }
  return;
}


// ===== FUN_201556d0 @ 201556d0 (4 bytes)

undefined * FUN_201556d0(void)

{
  return &DAT_2091d530;
}


// ===== FUN_201556d8 @ 201556d8 (4 bytes)

undefined * FUN_201556d8(void)

{
  return &DAT_2091d510;
}


// ===== FUN_201556e0 @ 201556e0 (752 bytes)

ulonglong FUN_201556e0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  bVar11 = param_4 == 0;
  uVar9 = param_4;
  if (bVar11) {
    uVar9 = param_3;
  }
  uVar10 = LZCOUNT(uVar9);
  uVar9 = uVar9 << uVar10 + 1;
  uVar5 = 0;
  if (!bVar11) {
    uVar10 = 0x3f - uVar10;
    bVar11 = uVar10 == 0;
    uVar5 = uVar10;
  }
  if (bVar11) {
    uVar10 = 0x1f - uVar10;
    uVar5 = uVar10;
  }
  if ((int)uVar5 < 0) {
    return 0;
  }
  if (param_2 == 0) {
    iVar4 = LZCOUNT(param_1);
    bVar11 = true;
  }
  else {
    iVar4 = 0x3f - LZCOUNT(param_2);
    bVar11 = iVar4 == 0;
  }
  if (bVar11) {
    iVar4 = 0x1f - iVar4;
  }
  uVar5 = iVar4 - uVar10;
  if ((int)uVar5 < 0) {
    return 0;
  }
  if (-1 < (int)(4 - uVar5)) {
    uVar6 = 0;
    uVar10 = param_3 << (uVar5 & 0xff);
    uVar9 = param_4 << (uVar5 & 0xff) | param_3 >> (0x20 - uVar5 & 0xff);
    while( true ) {
      bVar12 = uVar10 <= param_1;
      bVar11 = param_2 - uVar9 < (uint)bVar12;
      uVar6 = uVar6 * 2 + (uint)(uVar9 < param_2 || bVar11);
      if (uVar9 < param_2 || bVar11) {
        param_1 = param_1 - uVar10;
        param_2 = param_2 - (uVar9 + !bVar12);
      }
      bVar11 = uVar5 == 0;
      uVar5 = uVar5 - 1;
      if (bVar11) break;
      bVar2 = (byte)uVar9;
      uVar9 = uVar9 >> 1;
      uVar10 = (uint)(bVar2 & 1) << 0x1f | uVar10 >> 1;
    }
    return (ulonglong)uVar6;
  }
  if ((int)(uVar10 - 0x20) < 5) {
    uVar9 = uVar9 | param_3 >> (uVar10 - 0x20 & 0xff);
  }
  uVar5 = *(uint *)(&DAT_201559d0 + (uVar9 >> 0x1c) * 4);
  uVar9 = uVar10;
  if (0x1f < uVar10) {
    uVar9 = uVar10 - 0x20;
  }
  uVar6 = 0x20 - uVar9;
  if (uVar10 < 0x20) {
    uVar3 = (uint)((ulonglong)param_3 * (ulonglong)uVar5);
    uVar10 = -((int)((ulonglong)param_3 * (ulonglong)uVar5 >> 0x20) << (uVar6 & 0xff) |
              uVar3 >> (uVar9 & 0xff));
    if (uVar3 << (uVar6 & 0xff) != 0) {
      uVar10 = uVar10 - 1;
    }
    uVar5 = uVar5 + (int)((ulonglong)uVar10 * (ulonglong)uVar5 >> 0x20);
    uVar3 = (uint)((ulonglong)param_3 * (ulonglong)uVar5);
    uVar10 = -((int)((ulonglong)param_3 * (ulonglong)uVar5 >> 0x20) << (uVar6 & 0xff) |
              uVar3 >> (uVar9 & 0xff));
    if (uVar3 << (uVar6 & 0xff) != 0) {
      uVar10 = uVar10 - 1;
    }
    uVar5 = uVar5 + (int)((ulonglong)uVar10 * (ulonglong)uVar5 >> 0x20);
    if (param_2 != 0) {
      uVar3 = (uint)((ulonglong)param_3 * (ulonglong)uVar5);
      uVar10 = -((int)((ulonglong)param_3 * (ulonglong)uVar5 >> 0x20) << (uVar6 & 0xff) |
                uVar3 >> (uVar9 & 0xff));
      if (uVar3 << (uVar6 & 0xff) != 0) {
        uVar10 = uVar10 - 1;
      }
      uVar5 = uVar5 + (int)((ulonglong)uVar10 * (ulonglong)uVar5 >> 0x20);
    }
    lVar1 = (ulonglong)param_2 * (ulonglong)uVar5 + ((ulonglong)param_1 * (ulonglong)uVar5 >> 0x20);
    uVar10 = (uint)((ulonglong)lVar1 >> 0x20);
    uVar3 = (uint)lVar1 >> (uVar9 & 0xff) | uVar10 << (uVar6 & 0xff);
    uVar10 = uVar10 >> (uVar9 & 0xff);
    uVar7 = (uint)((ulonglong)param_3 * (ulonglong)uVar3);
    uVar6 = param_1 - uVar7;
    param_2 = param_2 - (uVar10 * param_3 + (int)((ulonglong)param_3 * (ulonglong)uVar3 >> 0x20) +
                        (uint)(param_1 < uVar7));
    if (param_2 == 0 && uVar6 < param_3) {
      return CONCAT44(uVar10,uVar3);
    }
    lVar1 = (ulonglong)param_2 * (ulonglong)uVar5 + ((ulonglong)uVar6 * (ulonglong)uVar5 >> 0x20);
    uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
    uVar8 = (uint)lVar1 >> (uVar9 & 0xff) | uVar7 << (0x20 - uVar9 & 0xff);
    uVar5 = uVar3 + uVar8;
    iVar4 = uVar10 + (uVar7 >> (uVar9 & 0xff)) + (uint)CARRY4(uVar3,uVar8);
    uVar6 = uVar6 - param_3 * uVar8;
    if (uVar6 < param_3) {
      return CONCAT44(iVar4,uVar5);
    }
    uVar6 = uVar6 - param_3;
    bVar11 = param_3 <= uVar6;
    if (bVar11) {
      uVar6 = uVar6 - param_3;
    }
    uVar9 = uVar5 + 1 + (uint)bVar11;
    return CONCAT44(iVar4 + (uint)(0xfffffffe < uVar5) + (uint)CARRY4(uVar5 + 1,(uint)bVar11) +
                    (uint)CARRY4(uVar9,(uint)(param_3 <= uVar6)),uVar9 + (param_3 <= uVar6));
  }
  lVar1 = (ulonglong)param_4 * (ulonglong)uVar5 + ((ulonglong)param_3 * (ulonglong)uVar5 >> 0x20);
  uVar3 = (uint)lVar1;
  uVar10 = -((int)((ulonglong)lVar1 >> 0x20) << (uVar6 & 0xff) | uVar3 >> (uVar9 & 0xff));
  if (uVar3 << (0x20 - uVar9 & 0xff) != 0) {
    uVar10 = uVar10 - 1;
  }
  uVar5 = uVar5 + (int)((ulonglong)uVar10 * (ulonglong)uVar5 >> 0x20);
  lVar1 = (ulonglong)param_4 * (ulonglong)uVar5 + ((ulonglong)param_3 * (ulonglong)uVar5 >> 0x20);
  uVar6 = (uint)lVar1;
  uVar10 = -((int)((ulonglong)lVar1 >> 0x20) << (0x20 - uVar9 & 0xff) | uVar6 >> (uVar9 & 0xff));
  if (uVar6 << (0x20 - uVar9 & 0xff) != 0) {
    uVar10 = uVar10 - 1;
  }
  uVar3 = (uVar5 + (int)((ulonglong)uVar10 * (ulonglong)uVar5 >> 0x20)) - 1;
  uVar5 = (uint)((ulonglong)param_2 * (ulonglong)uVar3 +
                 ((ulonglong)param_1 * (ulonglong)uVar3 >> 0x20) >> 0x20) >> (uVar9 & 0xff);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar5);
  uVar10 = param_1 - uVar6;
  param_2 = param_2 - (uVar5 * param_4 + (int)((ulonglong)param_3 * (ulonglong)uVar5 >> 0x20) +
                      (uint)(param_1 < uVar6));
  bVar11 = param_4 <= param_2;
  if (param_2 == param_4) {
    bVar11 = param_3 <= uVar10;
  }
  if (!bVar11) {
    return (ulonglong)uVar5;
  }
  uVar9 = (uint)((ulonglong)param_2 * (ulonglong)uVar3 +
                 ((ulonglong)uVar10 * (ulonglong)uVar3 >> 0x20) >> 0x20) >> (uVar9 & 0xff);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar9);
  param_2 = param_2 - (uVar9 * param_4 + (int)((ulonglong)param_3 * (ulonglong)uVar9 >> 0x20) +
                      (uint)(uVar10 < uVar6));
  bVar11 = param_4 <= param_2;
  if (param_2 == param_4) {
    bVar11 = param_3 <= uVar10 - uVar6;
  }
  if (!bVar11) {
    return (ulonglong)(uVar5 + uVar9);
  }
  return (ulonglong)(uVar5 + uVar9 + 1);
}


// ===== FUN_20155a10 @ 20155a10 (152 bytes)

undefined8 FUN_20155a10(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 >> 2 | param_2 << 0x1e;
  uVar1 = param_1 - uVar3;
  uVar2 = param_2 - ((param_2 >> 2) + (uint)(param_1 < uVar3));
  uVar4 = uVar1 >> 4 | uVar2 * 0x10000000;
  uVar3 = uVar1 + uVar4;
  uVar2 = uVar2 + (uVar2 >> 4) + (uint)CARRY4(uVar1,uVar4);
  uVar4 = uVar3 >> 8 | uVar2 * 0x1000000;
  uVar1 = uVar3 + uVar4;
  uVar2 = uVar2 + (uVar2 >> 8) + (uint)CARRY4(uVar3,uVar4);
  uVar4 = uVar1 >> 0x10 | uVar2 * 0x10000;
  uVar3 = uVar1 + uVar4;
  uVar1 = uVar2 + (uVar2 >> 0x10) + (uint)CARRY4(uVar1,uVar4);
  uVar2 = uVar1 + CARRY4(uVar3,uVar1);
  uVar3 = uVar3 + uVar1 >> 3 | uVar2 * 0x20000000;
  uVar1 = uVar2 >> 3;
  if (-1 < (int)((param_2 - (param_1 < 10)) -
                (((uVar1 << 2 | (uVar2 & 7) >> 1) + uVar1 + (uint)CARRY4(uVar3,uVar3 * 4)) * 2 +
                 (uint)CARRY4(uVar3 * 5,uVar3 * 5) + (uint)(param_1 - 10 < uVar3 * 10)))) {
    return CONCAT44(uVar1 + (0xfffffffe < uVar3),uVar3 + 1);
  }
  return CONCAT44(uVar1,uVar3);
}


// ===== FUN_20155b5c @ 20155b5c (430 bytes)

/* WARNING: Removing unreachable block (ram,0x20155ba6) */

void FUN_20155b5c(uint *param_1,char *param_2,int *param_3,uint param_4,uint param_5)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char extraout_r2;
  char extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  uint unaff_r11;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined8 local_60;
  int local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint local_3c;
  int local_38;
  uint *local_34;
  char *pcStack_30;
  int *piStack_2c;
  uint uStack_28;
  
  uVar12 = CONCAT44(local_60._4_4_,(int)local_60);
  local_38 = *param_3;
  uVar4 = param_3[1];
  uVar8 = (ushort)((uVar4 & 0x7fffffff) >> 0x14);
  if ((uVar4 & 0x7fffffff) >> 0x14 == 0) {
    uVar8 = 0xffff;
  }
  if (local_38 == 0 && (uVar4 & 0x7fffffff) == 0) {
    uVar4 = 0;
    if (param_5 == 1) {
      uVar10 = ~param_4;
    }
    else {
      for (; (int)uVar4 < (int)param_4; uVar4 = uVar4 + 1) {
        param_2[uVar4] = '0';
      }
      uVar10 = 0;
      uVar4 = param_4;
    }
    param_2[uVar4] = '\0';
    param_1[2] = param_5;
    *param_1 = uVar10;
    param_1[1] = uVar4;
    return;
  }
  uVar10 = (short)(uVar8 - 0x3ff) * 0x4d10 >> 0x10;
  local_34 = param_1;
  pcStack_30 = param_2;
  piStack_2c = param_3;
  uStack_28 = param_4;
LAB_20155bbe:
  do {
    if (param_5 == 0) {
      iVar7 = (uVar10 - param_4) + 1;
    }
    else {
      iVar7 = -param_4;
    }
    iVar5 = iVar7;
    if (iVar7 < 0) {
      iVar5 = -iVar7;
    }
    local_60 = uVar12;
    FUN_201560a0(&local_48,iVar5,0);
    local_54 = local_48;
    uStack_50 = uStack_44;
    uStack_4c = uStack_40;
    uVar11 = FUN_201569c0(uVar4,local_38);
    local_60._4_4_ = (undefined4)((ulonglong)uVar11 >> 0x20);
    local_60._0_4_ = (int)uVar11 + -0x201f;
    if (iVar7 < 1) {
      local_54 = local_54 + -0x201f;
      uVar12 = FUN_20156eca(&local_60,&local_54,0);
      uVar3 = extraout_r2_02;
    }
    else {
      local_54 = local_54 + 0x201f;
      uVar12 = FUN_20156ea2(&local_60,&local_54,0);
      uVar3 = extraout_r2_01;
    }
    local_60._4_4_ = (undefined4)(uVar12 >> 0x20);
    uVar6 = local_60._4_4_;
    if ((uVar12 & 0xffff) != 0) {
      uVar3 = 0xffffffff;
      uVar6 = 0x7fffffff;
    }
    lVar13 = CONCAT44(uVar6,uVar3);
    uVar9 = param_4;
    if (param_5 != 0) {
      local_60._0_4_ = 0;
      for (uVar9 = 0;
          (uVar12 = CONCAT44(local_60._4_4_,(int)local_60), lVar13 != 0 && ((int)uVar9 < 0x11));
          uVar9 = uVar9 + 1) {
        lVar13 = FUN_20155a10();
        param_2[uVar9] = extraout_r2_00 + '0';
      }
      if (lVar13 != 0) {
        if ((int)local_60 != 0) goto LAB_20155cee;
        param_4 = 0x11;
        param_5 = 0;
        goto LAB_20155bbe;
      }
      uVar4 = uVar9;
      for (iVar7 = 0; uVar4 = uVar4 - 1, iVar7 < (int)uVar4; iVar7 = iVar7 + 1) {
        cVar1 = param_2[iVar7];
        param_2[iVar7] = param_2[uVar4];
        param_2[uVar4] = cVar1;
      }
      unaff_r11 = uVar9;
      local_3c = (uVar9 - param_4) - 1;
LAB_20155cee:
      param_2[unaff_r11] = '\0';
      local_34[2] = param_5;
      *local_34 = local_3c;
      local_34[1] = unaff_r11;
      return;
    }
    while (uVar9 = uVar9 - 1, -1 < (int)uVar9) {
      local_60 = uVar12;
      lVar13 = FUN_20155a10();
      param_2[uVar9] = extraout_r2 + '0';
      uVar12 = local_60;
    }
    bVar2 = true;
    if (lVar13 == 0) {
      if (*param_2 == '0') {
        bVar2 = false;
        uVar10 = uVar10 - 1;
      }
    }
    else {
      bVar2 = false;
      uVar10 = uVar10 + 1;
    }
    unaff_r11 = param_4;
    local_3c = uVar10;
    if (bVar2) goto LAB_20155cee;
  } while( true );
}


// ===== FUN_20155f68 @ 20155f68 (10 bytes)

undefined1 FUN_20155f68(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + 0x10);
  *(undefined1 **)(param_1 + 0x10) = puVar1 + 1;
  return *puVar1;
}


// ===== FUN_20155f72 @ 20155f72 (32 bytes)

void FUN_20155f72(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  
  local_2c = 0;
  local_34 = 0x20155f69;
  local_3c = param_4;
  uStack_38 = param_2;
  uStack_30 = param_1;
  FUN_20154c48(auStack_40,param_3);
  return;
}


// ===== FUN_20155f98 @ 20155f98 (10 bytes)

void FUN_20155f98(undefined1 param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  *puVar1 = param_1;
  *param_2 = puVar1 + 1;
  return;
}


// ===== FUN_20155fa2 @ 20155fa2 (16 bytes)

void FUN_20155fa2(undefined1 param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  if (puVar1 < (undefined1 *)param_2[1]) {
    *param_2 = puVar1 + 1;
    *puVar1 = param_1;
  }
  return;
}


// ===== FUN_20155fde @ 20155fde (24 bytes)

void FUN_20155fde(void)

{
  int iVar1;
  
  iVar1 = FUN_20156184();
  if (iVar1 != 0) {
    FUN_201561b4();
    return;
  }
  return;
}


// ===== FUN_20155fec @ 20155fec (44 bytes)

undefined8 FUN_20155fec(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 - (param_1 >> 2);
  uVar1 = uVar1 + (uVar1 >> 4);
  uVar1 = uVar1 + (uVar1 >> 8);
  uVar1 = uVar1 + (uVar1 >> 0x10) >> 3;
  iVar2 = (param_1 - 10) + uVar1 * -10;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 10;
  }
  else {
    uVar1 = uVar1 + 1;
  }
  return CONCAT44(iVar2,uVar1);
}


// ===== FUN_20156018 @ 20156018 (4 bytes)

undefined * FUN_20156018(void)

{
  return &DAT_2091d510;
}


// ===== FUN_20156020 @ 20156020 (112 bytes)

void FUN_20156020(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = 3;
  uVar1 = *param_1 & 0x800;
  if (param_3 < 7) {
    if (uVar1 == 0) {
      puVar2 = &UNK_2015609c;
    }
    else {
      puVar2 = &UNK_20156098;
    }
  }
  else if (uVar1 == 0) {
    puVar2 = &UNK_20156094;
  }
  else {
    puVar2 = &DAT_20156090;
  }
  *param_1 = *param_1 & 0xffffffef;
  uVar1 = param_1[6];
  param_1[6] = uVar1 - 3;
  if (param_4 != 0) {
    param_1[6] = uVar1 - 4;
  }
  FUN_20154a64(param_1);
  if (param_4 == 0) {
    uVar1 = param_1[8];
  }
  else {
    (*(code *)param_1[1])(param_4,param_1[2]);
    uVar1 = param_1[8] + 1;
    param_1[8] = uVar1;
  }
  param_1[8] = uVar1 + 3;
  while (bVar4 = iVar3 != 0, iVar3 = iVar3 + -1, bVar4) {
    (*(code *)param_1[1])(*puVar2,param_1[2]);
    puVar2 = puVar2 + 1;
  }
  FUN_20154a90(param_1);
  return;
}


// ===== FUN_201560a0 @ 201560a0 (210 bytes)

void FUN_201560a0(undefined8 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 local_48;
  undefined4 uStack_40;
  undefined8 local_3c;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_48._0_4_ = 0x3fff;
  local_48._4_4_ = 0x80000000;
  uStack_40 = 0;
  local_3c._0_4_ = 0x3fff;
  local_3c._4_4_ = 0x80000000;
  uStack_34 = 0;
  uVar7 = __aeabi_uidivmod(param_2 + 0x1b9b,0x37);
  uVar8 = CONCAT44(local_48._4_4_,(undefined4)local_48);
  uVar3 = (int)((ulonglong)uVar7 >> 0x20) - 0x1b;
  bVar6 = -1 < (int)uVar3;
  uVar4 = (int)uVar7 - 0x80;
  if (!bVar6) {
    uVar3 = -uVar3;
  }
  iVar5 = 0;
  for (; uVar7 = CONCAT44(local_3c._4_4_,(undefined4)local_3c), uVar3 != 0; uVar3 = (int)uVar3 >> 1)
  {
    if ((uVar3 & 1) != 0) {
      local_48 = uVar8;
      uVar8 = FUN_20156eca(&local_48,&DAT_20427f10 + iVar5 * 0xc,param_3);
      uStack_40 = extraout_r2;
    }
    iVar5 = iVar5 + 1;
  }
  iVar5 = 0;
  for (; local_48 = uVar8, local_3c = uVar7, uVar4 != 0; uVar4 = (int)uVar4 >> 1) {
    if ((uVar4 & 1) != 0) {
      iVar1 = iVar5 * 0x10;
      local_30 = *(undefined4 *)(&DAT_20427f4c + iVar1);
      uStack_2c = *(undefined4 *)(&DAT_20427f50 + iVar1);
      local_28 = *(int *)(&DAT_20427f54 + iVar1);
      if (*(int *)(&DAT_20427f58 + iVar1) + param_3 == 0) {
        local_28 = local_28 + param_3;
      }
      uVar7 = FUN_20156eca(&local_3c,&local_30,param_3);
      uStack_34 = extraout_r2_00;
      uVar8 = local_48;
    }
    iVar5 = iVar5 + 1;
  }
  if (bVar6) {
    uVar8 = FUN_20156eca(&local_3c,&local_48,param_3);
    uVar2 = extraout_r2_02;
  }
  else {
    uVar8 = FUN_20156ea2();
    uVar2 = extraout_r2_01;
  }
  *param_1 = uVar8;
  *(undefined4 *)(param_1 + 1) = uVar2;
  return;
}


// ===== FUN_20156184 @ 20156184 (14 bytes)

undefined4 FUN_20156184(void)

{
  FUN_2015621c("SIGPVFN: Pure virtual fn called",0);
  return 1;
}


// ===== FUN_201561b4 @ 201561b4 (8 bytes)

void FUN_201561b4(void)

{
  software_interrupt(0xab);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_201561c0 @ 201561c0 (74 bytes)

void FUN_201561c0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 unaff_lr;
  uint *puVar3;
  
  uVar1 = FUN_20156018();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = unaff_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_201172ec();
  puVar2 = (undefined4 *)*puVar3;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  return;
}


// ===== FUN_2015620a @ 2015620a (18 bytes)

uint FUN_2015620a(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int extraout_r3;
  
  FUN_20100cd8();
  iVar1 = FUN_201561b4(param_1,param_2);
  *(short *)(iVar1 + 0x1c) = (short)iVar1;
  *(short *)(extraout_r3 + 0x20) = (short)iVar1;
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  DataSynchronizationBarrier(0xf);
  coproc_moveto_Invalidate_Entire_Instruction(0);
  coproc_moveto_Instruction_cache(0,6);
  InstructionSynchronizationBarrier(0xf);
  uVar2 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar2 & 0xfffffffd);
  uVar2 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar2 & 0xffffeffa);
  return uVar2 & 0xffffeffa;
}


// ===== FUN_2015621c @ 2015621c (50 bytes)

undefined8 FUN_2015621c(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = '\n';
  for (; (FUN_2015624e(cVar1), param_1 != (char *)0x0 && (cVar1 = *param_1, cVar1 != '\0'));
      param_1 = param_1 + 1) {
  }
  for (; (param_2 != (char *)0x0 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    FUN_2015624e();
  }
  software_interrupt(0xab);
  return CONCAT44(&stack0xfffffff8,3);
}


// ===== FUN_2015624e @ 2015624e (14 bytes)

undefined8 FUN_2015624e(void)

{
  undefined1 local_8 [4];
  
  software_interrupt(0xab);
  return CONCAT44(local_8,3);
}


// ===== FUN_20156260 @ 20156260 (48 bytes)

longlong FUN_20156260(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  iVar3 = 0;
  uVar1 = param_2;
  if (param_2 <= param_1 >> 2) {
    if (param_2 <= param_1 >> 5) {
      if (param_2 <= param_1 >> 8) {
        if (param_1 >> 0xc < param_2) goto LAB_2015550c;
        if (param_1 >> 0x10 < param_2) goto LAB_201554dc;
        uVar1 = param_2 << 8;
        iVar3 = -0x1000000;
        if (uVar1 <= param_1 >> 0x10) {
          iVar3 = -0x10000;
          uVar1 = param_2 << 0x10;
        }
        if (param_1 >> 0xc < uVar1) goto LAB_2015550c;
        bVar4 = false;
        if (uVar1 == 0) {
          return (ulonglong)param_1 << 0x20;
        }
        do {
          if (bVar4) {
            uVar1 = uVar1 >> 8;
          }
LAB_201554dc:
          bVar4 = uVar1 <= param_1 >> 0xf;
          if (bVar4) {
            param_1 = param_1 + uVar1 * -0x8000;
          }
          bVar5 = uVar1 <= param_1 >> 0xe;
          if (bVar5) {
            param_1 = param_1 + uVar1 * -0x4000;
          }
          bVar6 = uVar1 <= param_1 >> 0xd;
          if (bVar6) {
            param_1 = param_1 + uVar1 * -0x2000;
          }
          bVar7 = uVar1 <= param_1 >> 0xc;
          if (bVar7) {
            param_1 = param_1 + uVar1 * -0x1000;
          }
          iVar3 = (((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6) * 2 +
                  (uint)bVar7;
LAB_2015550c:
          bVar4 = uVar1 <= param_1 >> 0xb;
          if (bVar4) {
            param_1 = param_1 + uVar1 * -0x800;
          }
          bVar5 = uVar1 <= param_1 >> 10;
          if (bVar5) {
            param_1 = param_1 + uVar1 * -0x400;
          }
          bVar6 = uVar1 <= param_1 >> 9;
          if (bVar6) {
            param_1 = param_1 + uVar1 * -0x200;
          }
          uVar2 = ((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6;
          bVar5 = uVar1 <= param_1 >> 8;
          if (bVar5) {
            param_1 = param_1 + uVar1 * -0x100;
          }
          iVar3 = uVar2 * 2 + (uint)bVar5;
          bVar4 = true;
        } while (CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar5));
      }
      bVar4 = uVar1 <= param_1 >> 7;
      if (bVar4) {
        param_1 = param_1 + uVar1 * -0x80;
      }
      bVar5 = uVar1 <= param_1 >> 6;
      if (bVar5) {
        param_1 = param_1 + uVar1 * -0x40;
      }
      bVar6 = uVar1 <= param_1 >> 5;
      if (bVar6) {
        param_1 = param_1 + uVar1 * -0x20;
      }
      iVar3 = ((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6;
    }
    bVar4 = uVar1 <= param_1 >> 4;
    if (bVar4) {
      param_1 = param_1 + uVar1 * -0x10;
    }
    bVar5 = uVar1 <= param_1 >> 3;
    if (bVar5) {
      param_1 = param_1 + uVar1 * -8;
    }
    bVar6 = uVar1 <= param_1 >> 2;
    if (bVar6) {
      param_1 = param_1 + uVar1 * -4;
    }
    iVar3 = ((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6;
  }
  bVar4 = uVar1 <= param_1 >> 1;
  if (bVar4) {
    param_1 = param_1 + uVar1 * -2;
  }
  uVar2 = param_1 - uVar1;
  if (uVar1 > param_1) {
    uVar2 = param_1;
  }
  return CONCAT44(uVar2,(iVar3 * 2 + (uint)bVar4) * 2 + (uint)(uVar1 <= param_1));
}


// ===== kernel_heap_init @ 201562b4 (92 bytes)

/* heap/kernel memory up to 0x20980000 */

void kernel_heap_init(void)

{
  int iVar1;
  
  iVar1 = gic_init();
  if (iVar1 == 0) {
    DAT_208003ac = 0;
    DAT_208003a8 = 0;
    FUN_201530fc(&DAT_20980000,&stack0xfffffff8);
  }
  return;
}


// ===== FUN_2015632c @ 2015632c (192 bytes)

ulonglong FUN_2015632c(undefined4 param_1)

{
  undefined1 *puVar1;
  bool bVar2;
  undefined1 auStack_58 [52];
  undefined1 local_8 [4];
  
  puVar1 = local_8;
  bVar2 = DAT_208003da == '\0';
  DAT_208003da = DAT_208003da + -1;
  if (bVar2) {
    **(int **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4) = (int)auStack_58;
    puVar1 = DAT_208003f0;
  }
  return CONCAT44(puVar1,param_1) & 0xfffffff8ffffffff;
}


// ===== FUN_201563f4 @ 201563f4 (360 bytes)

undefined8 FUN_201563f4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  int iVar4;
  int in_stack_00000010;
  uint in_stack_00000014;
  
  gic_irq_exit();
  DAT_208003da = DAT_208003da + '\x01';
  if (DAT_208003da != '\0') {
    return *(undefined8 *)(in_stack_00000010 + 8);
  }
  pbVar3 = &DAT_208dc18c;
  uVar1 = (uint)DAT_208003d8;
  if ((uVar1 != 0) && (-1 < (int)(8 - uVar1))) {
    DAT_208003de = DAT_208dc18c;
  }
  if (((in_stack_00000014 & 0xc0) == 0) && (uVar1 != 0)) {
    uVar1 = (uint)DAT_208003dc;
    if (uVar1 == 0) {
      if ((DAT_208003db != '\0') || (DAT_208003d9 == '\0')) goto LAB_201564f8;
      DAT_208003d9 = '\0';
      do {
        pbVar3 = pbVar3 + 1;
        uVar1 = (uint)*pbVar3;
      } while (uVar1 == 0);
    }
    if (uVar1 != DAT_208dc18c) {
      iVar4 = **(int **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4);
      *(undefined4 *)(iVar4 + 0x2c) = unaff_r11;
      *(undefined4 *)(iVar4 + 0x28) = unaff_r10;
      *(undefined4 *)(iVar4 + 0x24) = unaff_r9;
      *(undefined4 *)(iVar4 + 0x20) = unaff_r8;
      *(undefined4 *)(iVar4 + 0x1c) = unaff_r7;
      *(undefined4 *)(iVar4 + 0x18) = unaff_r6;
      *(undefined4 *)(iVar4 + 0x14) = unaff_r5;
      *(undefined4 *)(iVar4 + 0x10) = unaff_r4;
      DAT_208dc18c = (byte)uVar1;
      puVar2 = *(undefined4 **)(&DAT_208dbba0 + uVar1 * 4);
      goto LAB_2015650c;
    }
  }
LAB_201564f8:
  puVar2 = *(undefined4 **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4);
LAB_2015650c:
  DAT_208003d8 = *(byte *)(puVar2 + 1);
  if (DAT_208003d8 != '\0') {
    DAT_208003df = DAT_208003d8;
  }
  return *(undefined8 *)*puVar2;
}


// ===== FUN_2015655c @ 2015655c (404 bytes)

longlong FUN_2015655c(void)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint in_stack_00000004;
  undefined1 auStack_38 [16];
  
  DAT_208003d9 = 1;
  if (((((DAT_208003cc & 0x80) == 0) && (DAT_208003da == '\0')) && (DAT_208003db == '\0')) &&
     (DAT_208003d8 != '\0')) {
    uVar2 = (uint)DAT_208003dc;
    pbVar3 = &DAT_208dc18c;
    DAT_208003dc = 0;
    uVar1 = (uint)DAT_208dc18c;
    if (uVar2 == 0) {
      DAT_208003d9 = 0;
      do {
        pbVar3 = pbVar3 + 1;
        uVar2 = (uint)*pbVar3;
      } while (uVar2 == 0);
    }
    DAT_208dc18c = (byte)uVar2;
    if (uVar1 != uVar2) {
      **(undefined4 **)(&DAT_208dbba0 + uVar1 * 4) = auStack_38;
      DAT_208003d8 = *(char *)(*(undefined4 **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4) + 1);
      if (DAT_208003d8 != '\0') {
        DAT_208003df = DAT_208003d8;
      }
      return *(longlong *)**(undefined4 **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4);
    }
    DAT_208003d8 = *(char *)(*(undefined4 **)(&DAT_208dbba0 + uVar1 * 4) + 1);
    if (DAT_208003d8 != '\0') {
      DAT_208003df = DAT_208003d8;
    }
  }
  return (ulonglong)(in_stack_00000004 & 0xffffff3f | DAT_208003cc) << 0x20;
}


// ===== FUN_201566f0 @ 201566f0 (88 bytes)

longlong FUN_201566f0(void)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint in_stack_00000004;
  undefined1 auStack_38 [16];
  
  DAT_208003d9 = 1;
  uVar2 = (uint)DAT_208003dc;
  pbVar3 = &DAT_208dc18c;
  DAT_208003dc = 0;
  uVar1 = (uint)DAT_208dc18c;
  if (uVar2 == 0) {
    DAT_208003d9 = 0;
    do {
      pbVar3 = pbVar3 + 1;
      uVar2 = (uint)*pbVar3;
    } while (uVar2 == 0);
  }
  DAT_208dc18c = (byte)uVar2;
  if (uVar1 == uVar2) {
    DAT_208003d8 = *(char *)(*(undefined4 **)(&DAT_208dbba0 + uVar1 * 4) + 1);
    if (DAT_208003d8 != '\0') {
      DAT_208003df = DAT_208003d8;
    }
    DAT_208003dc = 0;
    return (ulonglong)(in_stack_00000004 & 0xffffff3f | DAT_208003cc) << 0x20;
  }
  **(undefined4 **)(&DAT_208dbba0 + uVar1 * 4) = auStack_38;
  DAT_208003d8 = *(char *)(*(undefined4 **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4) + 1);
  if (DAT_208003d8 != '\0') {
    DAT_208003df = DAT_208003d8;
  }
  return *(longlong *)**(undefined4 **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4);
}


// ===== FUN_20156748 @ 20156748 (52 bytes)

longlong FUN_20156748(void)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint in_stack_00000004;
  undefined1 auStack_38 [16];
  
  uVar2 = (uint)DAT_208003dc;
  pbVar3 = &DAT_208dc18c;
  DAT_208003dc = 0;
  uVar1 = (uint)DAT_208dc18c;
  if (uVar2 == 0) {
    DAT_208003d9 = 0;
    do {
      pbVar3 = pbVar3 + 1;
      uVar2 = (uint)*pbVar3;
    } while (uVar2 == 0);
  }
  DAT_208dc18c = (byte)uVar2;
  if (uVar1 == uVar2) {
    DAT_208003d8 = *(char *)(*(undefined4 **)(&DAT_208dbba0 + uVar1 * 4) + 1);
    if (DAT_208003d8 != '\0') {
      DAT_208003df = DAT_208003d8;
    }
    return (ulonglong)(in_stack_00000004 & 0xffffff3f | DAT_208003cc) << 0x20;
  }
  **(undefined4 **)(&DAT_208dbba0 + uVar1 * 4) = auStack_38;
  DAT_208003d8 = *(char *)(*(undefined4 **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4) + 1);
  if (DAT_208003d8 != '\0') {
    DAT_208003df = DAT_208003d8;
  }
  return *(longlong *)**(undefined4 **)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4);
}


// ===== FUN_201567d4 @ 201567d4 (32 bytes)

uint FUN_201567d4(void)

{
  uint in_stack_00000004;
  
  DAT_208003cc = in_stack_00000004 & 0xc0;
  return in_stack_00000004 & 0xffffff3f | 0x80;
}


// ===== FUN_201567f4 @ 201567f4 (32 bytes)

longlong FUN_201567f4(void)

{
  uint in_stack_00000004;
  
  return (ulonglong)(DAT_208003cc | in_stack_00000004 & 0xffffff3f) << 0x20;
}


// ===== FUN_20156814 @ 20156814 (28 bytes)

void FUN_20156814(void)

{
  return;
}


// ===== FUN_20156830 @ 20156830 (48 bytes)

undefined8 FUN_20156830(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 in_stack_00000004;
  
  return CONCAT44(in_stack_00000004,
                  (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b);
}


// ===== FUN_20156860 @ 20156860 (12 bytes)

undefined * FUN_20156860(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  uint uVar2;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  
  param_1[-1] = FUN_201509f4;
  param_1[-2] = unaff_r8;
  param_1[-3] = unaff_r7;
  param_1[-4] = unaff_r6;
  param_1[-5] = unaff_r5;
  param_1[-6] = unaff_r4;
  uVar2 = *(uint *)(param_3[6] + 8);
  param_1[0xc] = param_1 + 0x12;
  *param_1 = param_2;
  uVar1 = DAT_208003ac;
  if ((uVar2 & 1) != 0) {
    uVar1 = DAT_208003ac | 0x20;
  }
  param_1[0xf] = uVar1;
  uVar1 = FUN_201568b8();
  param_1[0xf] = uVar1 | param_1[0xf];
  param_1[0xd] = FUN_201508ec;
  param_1[0x11] = uVar2;
  *param_3 = (int)param_1;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 9) = 0;
  param_3[8] = 0;
  *(undefined1 *)((int)param_3 + 5) = 0x10;
  FUN_201538d4(&DAT_208dc18c + *(char *)((int)param_3 + 0x27),param_3,param_4);
  software_interrupt(0);
  return &DAT_2015677c;
}


// ===== FUN_2015686c @ 2015686c (12 bytes)

code * FUN_2015686c(void)

{
  software_interrupt(0);
  return FUN_20156878;
}


// ===== FUN_20156878 @ 20156878 (20 bytes)

ulonglong FUN_20156878(void)

{
  undefined4 in_stack_00000004;
  
  return CONCAT44(in_stack_00000004,in_stack_00000004) & 0xffffffff000000c0 | 0x8000000000;
}


// ===== FUN_2015688c @ 2015688c (16 bytes)

undefined8 FUN_2015688c(undefined4 param_1)

{
  software_interrupt(0);
  return CONCAT44(param_1,FUN_2015689c);
}


// ===== FUN_2015689c @ 2015689c (20 bytes)

uint FUN_2015689c(void)

{
  uint in_stack_00000004;
  
  return in_stack_00000004 & 0xffffff3f;
}

