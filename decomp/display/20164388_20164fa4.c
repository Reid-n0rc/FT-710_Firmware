// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 37 functions

// ===== FUN_20164388 @ 20164388 (28 bytes)

undefined4 FUN_20164388(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_201647d0();
  *param_1 = uVar1;
  return uVar2;
}


// ===== FUN_201643a4 @ 201643a4 (12 bytes)

void FUN_201643a4(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_201643b0 @ 201643b0 (28 bytes)

undefined4 FUN_201643b0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_20164814();
  *param_1 = uVar1;
  return uVar2;
}


// ===== FUN_201643cc @ 201643cc (28 bytes)

undefined4 FUN_201643cc(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_2016485c();
  *param_1 = uVar1;
  return uVar2;
}


// ===== FUN_201643f0 @ 201643f0 (28 bytes)

undefined2 FUN_201643f0(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = *param_1;
  uVar2 = FUN_20164870();
  *param_1 = uVar2;
  return uVar1;
}


// ===== FUN_20164414 @ 20164414 (60 bytes)

void FUN_20164414(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = FUN_2014fd24(0,&local_18);
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  return;
}


// ===== FUN_20164454 @ 20164454 (12 bytes)

void FUN_20164454(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== FUN_20164460 @ 20164460 (60 bytes)

void FUN_20164460(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = FUN_2014fd24(0,&local_18);
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  return;
}


// ===== FUN_201644a0 @ 201644a0 (12 bytes)

void FUN_201644a0(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== FUN_201644e4 @ 201644e4 (60 bytes)

void FUN_201644e4(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = FUN_2014fd24(0,&local_18);
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  return;
}


// ===== FUN_20164524 @ 20164524 (12 bytes)

void FUN_20164524(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 4) = param_3;
  return;
}


// ===== FUN_20164568 @ 20164568 (56 bytes)

uint FUN_20164568(char *param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = *param_1;
  iVar3 = 0;
  if (cVar1 != param_3) {
    *param_1 = (char)param_3;
    iVar3 = (int)(char)((char)param_3 - cVar1);
  }
  uVar2 = param_2 + iVar3;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if ((int)uVar2 < 0x100) {
    uVar2 = uVar2 & 0xff;
  }
  else {
    uVar2 = 0xff;
  }
  return uVar2;
}


// ===== FUN_201645a0 @ 201645a0 (68 bytes)

void FUN_201645a0(ushort *param_1,undefined4 *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*param_1 < 0x10) {
    uVar3 = param_2[1];
    uVar1 = param_1[2];
    puVar2 = *(undefined4 **)(param_1 + (uint)uVar1 * 2 + 4);
    *puVar2 = *param_2;
    puVar2[1] = uVar3;
    param_1[2] = uVar1 + 1 & 0xf;
    *param_1 = *param_1 + 1;
  }
  return;
}


// ===== FUN_201645e4 @ 201645e4 (20 bytes)

void FUN_201645e4(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ===== FUN_201645f8 @ 201645f8 (12 bytes)

void FUN_201645f8(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4 + 8) = param_3;
  return;
}


// ===== FUN_20164604 @ 20164604 (52 bytes)

undefined4 FUN_20164604(short *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (*param_1 == 0) {
    uVar2 = 0;
  }
  else {
    *param_1 = *param_1 + -1;
    uVar1 = param_1[1];
    param_1[1] = uVar1 + 1 & 0xf;
    uVar2 = *(undefined4 *)(param_1 + (uint)uVar1 * 2 + 4);
  }
  return uVar2;
}


// ===== FUN_20164638 @ 20164638 (20 bytes)

undefined4 FUN_20164638(undefined4 param_1)

{
  FUN_201645e4();
  return param_1;
}


// ===== FUN_20164680 @ 20164680 (36 bytes)

undefined4 FUN_20164680(char *param_1)

{
  if (*param_1 == '\0') {
    return *(undefined4 *)(param_1 + 0x97c);
  }
  return *(undefined4 *)(param_1 + 4);
}


// ===== FUN_2016469c @ 2016469c (40 bytes)

undefined4 FUN_2016469c(char *param_1)

{
  if (*param_1 == '\0') {
    return *(undefined4 *)(param_1 + 0x2bb4);
  }
  return *(undefined4 *)(param_1 + 4);
}


// ===== FUN_20164758 @ 20164758 (44 bytes)

int FUN_20164758(int *param_1,int param_2)

{
  return (*param_1 + param_2 + 100) % 100;
}


// ===== FUN_20164788 @ 20164788 (20 bytes)

int FUN_20164788(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 100) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_2016479c @ 2016479c (48 bytes)

int FUN_2016479c(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x85 + *param_1;
  iVar1 = (int)((longlong)(int)uVar2 * -0x99fc267 + ((ulonglong)uVar2 << 0x20) >> 0x20);
  return ((iVar1 >> 7) - (iVar1 >> 0x1f)) * -0x85 + uVar2;
}


// ===== FUN_201647d0 @ 201647d0 (20 bytes)

int FUN_201647d0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x85) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_201647e4 @ 201647e4 (44 bytes)

int FUN_201647e4(int *param_1,int param_2)

{
  return (*param_1 + param_2 + 0x14) % 0x14;
}


// ===== FUN_20164814 @ 20164814 (20 bytes)

int FUN_20164814(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x14) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_20164828 @ 20164828 (48 bytes)

int FUN_20164828(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x1e + *param_1;
  iVar1 = (int)((longlong)(int)uVar2 * -0x77777777 + ((ulonglong)uVar2 << 0x20) >> 0x20);
  return uVar2 + ((iVar1 >> 4) - (iVar1 >> 0x1f)) * -0x1e;
}


// ===== FUN_2016485c @ 2016485c (20 bytes)

int FUN_2016485c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1 + 1;
  if (iVar1 == 0x1e) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_20164870 @ 20164870 (24 bytes)

short FUN_20164870(short *param_1)

{
  short sVar1;
  
  sVar1 = *param_1 + 1;
  if (sVar1 == 0x20) {
    sVar1 = 0;
  }
  return sVar1;
}


// ===== FUN_20164888 @ 20164888 (316 bytes)

/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_20164888(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    bVar11 = param_3 <= param_1;
    uVar6 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar6);
      param_3 = param_3 + uVar6;
      uVar7 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar7 + bVar12;
      bVar11 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = (param_2 - uVar7) - (uint)bVar11;
    }
    uVar7 = param_2 >> 0x14;
    uVar6 = uVar7 - (param_4 >> 0x14);
    if ((param_4 & 0x7ff00000) == 0 || (uVar7 & 0x7ff) == 0x7ff) {
      if ((uVar7 & 0x7ff) != 0x7ff) {
        if ((param_2 & 0x7ff00000) == 0) {
          param_2 = 0;
          param_1 = 0;
        }
        return CONCAT44(param_2,param_1);
      }
      FUN_20164efc();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar5 = -param_3;
    uVar1 = param_2 & ~(uVar7 << 0x14);
    iVar8 = -(param_4 & 0xfffff) + -0x100000;
    if (param_3 != 0) {
      iVar8 = -(param_4 & 0xfffff) + -0x100001;
    }
    if (uVar6 < 0x21) {
      uVar2 = uVar5 >> (uVar6 & 0xff);
      uVar9 = param_1 + uVar2;
      uVar1 = uVar1 + (iVar8 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar2);
      uVar10 = iVar8 << (0x20 - uVar6 & 0xff);
      uVar2 = uVar9 + uVar10;
      bVar11 = CARRY4(uVar1,(uint)CARRY4(uVar9,uVar10));
      iVar8 = uVar1 + CARRY4(uVar9,uVar10);
      uVar6 = 0x20 - uVar6;
    }
    else {
      uVar5 = (uint)(param_3 * -2 != 0) | (iVar8 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar6 = uVar6 - 0x20;
      if (0x1d < uVar6) {
        return CONCAT44(uVar1 + uVar7 * 0x100000,param_1);
      }
      uVar9 = iVar8 >> (uVar6 & 0xff);
      uVar2 = param_1 + uVar9;
      bVar11 = uVar1 != 0 || CARRY4(uVar1 - 1,(uint)CARRY4(param_1,uVar9));
      iVar8 = (uVar1 - 1) + (uint)CARRY4(param_1,uVar9);
      uVar6 = 0x1e - uVar6;
    }
    if (-1 < iVar8) {
      iVar4 = uVar5 << (uVar6 & 0xff);
      iVar8 = iVar8 + uVar7 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar8,uVar2);
      }
      uVar2 = uVar2 + 1;
      if (uVar2 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar8,uVar2);
      }
      if (uVar2 == 0) {
        iVar8 = iVar8 + 1;
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar2);
    }
    uVar1 = uVar6 + 1 & 0xff;
    bVar11 = uVar1 == 0 && bVar11 || uVar1 != 0 && (uVar5 << uVar1 - 1 & 0x80000000) != 0;
    uVar9 = uVar2 * 2 + (uint)bVar11;
    uVar6 = iVar8 * 2 + (uint)(CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar11));
    uVar2 = uVar6 + uVar7 * 0x200000;
    bVar11 = (uVar2 >> 0x14 & 1) != 0;
    if (bVar11 && uVar2 >> 0x15 != 0) {
      uVar2 = -((int)(uVar5 << uVar1) >> 0x1f);
      uVar10 = uVar9 + uVar2;
      bVar11 = uVar10 == 0;
      iVar8 = uVar6 + uVar7 * 0x100000;
      if (!CARRY4(uVar9,uVar2)) {
        bVar11 = uVar5 << uVar1 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar8,uVar10);
      }
      if (uVar10 == 0) {
        iVar8 = iVar8 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar10);
    }
    if (!bVar11) {
      iVar8 = uVar6 + 0x200000;
      if (iVar8 == 0) {
        uVar6 = uVar9 << LZCOUNT(uVar9);
        if (uVar6 == 0) {
          return (ulonglong)uVar9;
        }
        iVar4 = ((uVar7 & 0xfffff7ff) - LZCOUNT(uVar9)) + -0x17;
        iVar8 = uVar6 << 0x15;
        uVar6 = uVar6 >> 0xb;
      }
      else {
        uVar5 = LZCOUNT(iVar8) - 0xb;
        iVar4 = ((uVar7 & 0xfffff7ff) - uVar5) + -2;
        uVar6 = iVar8 << (uVar5 & 0xff) | uVar9 >> (0x20 - uVar5 & 0xff);
        iVar8 = uVar9 << (uVar5 & 0xff);
      }
      iVar3 = uVar6 + (param_2 & 0x80000000) + iVar4 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar3,iVar8);
      }
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    uVar7 = ((int)uVar6 >> 1) + uVar7 * 0x100000;
    uVar6 = (uint)((uVar6 & 1) != 0) << 0x1f | uVar9 >> 1;
    if (uVar7 * 2 == 0 && uVar6 == 0) {
      return (ulonglong)uVar6;
    }
    if (0x1fffff < uVar7 * 2) {
      return CONCAT44(uVar7,uVar6);
    }
    return (ulonglong)(uVar7 & 0x80000000) << 0x20;
  }
  uVar6 = param_1 - param_3;
  iVar8 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + iVar8 + (uint)bVar11;
    bVar11 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = (param_2 - iVar8) - (uint)bVar11;
  }
  uVar7 = param_2 >> 0x14;
  uVar6 = uVar7 - (param_4 >> 0x14);
  if ((param_4 & 0x7ff00000) == 0 || (uVar7 & 0x7ff) == 0x7ff) {
    if ((uVar7 & 0x7ff) != 0x7ff) {
      if ((param_2 & 0x7ff00000) == 0) {
        param_2 = param_2 & 0x80000000;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    FUN_20164efc();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_2 = param_2 & ~(uVar7 << 0x14);
  uVar5 = param_4 & 0x1fffff | 0x100000;
  if (uVar6 < 0x21) {
    uVar9 = param_3 >> (uVar6 & 0xff);
    uVar1 = param_1 + uVar9;
    uVar10 = uVar5 << (0x20 - uVar6 & 0xff);
    uVar2 = uVar1 + uVar10;
    param_2 = param_2 + (uVar5 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar9) +
              (uint)CARRY4(uVar1,uVar10);
    uVar6 = 0x20 - uVar6;
    if (param_2 < 0x100000) {
      param_2 = param_2 + uVar7 * 0x100000;
      goto LAB_20164904;
    }
LAB_20164966:
    bVar13 = (byte)uVar2 & 1;
    uVar5 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar2 >> 1;
    param_2 = (param_2 + 0x100000 >> 1) + uVar7 * 0x100000;
    if ((uVar2 & 1) == 0) {
LAB_20164994:
      if (param_2 * 2 < 0xffe00000) {
        return CONCAT44(param_2,uVar5);
      }
      goto LAB_20164f98;
    }
    bVar11 = CARRY4(uVar5,(uint)bVar13);
    uVar5 = uVar5 + bVar13;
    uVar7 = uVar5;
    if (!bVar11) {
      uVar7 = param_3 << (uVar6 & 0xff);
    }
    if (uVar7 != 0) goto LAB_20164994;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar1 = uVar6 - 0x20;
    uVar6 = 0x1f - uVar1;
    if (uVar1 < 0x20) {
      uVar5 = uVar5 >> (uVar1 & 0xff);
      uVar2 = param_1 + uVar5;
    }
    else {
      uVar6 = 0;
      uVar2 = param_1;
    }
    param_2 = param_2 + uVar7 * 0x100000 + (uint)(uVar1 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar7 != param_2 >> 0x14) {
      param_2 = param_2 + uVar7 * -0x100000;
      goto LAB_20164966;
    }
LAB_20164904:
    param_3 = param_3 << (uVar6 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(param_2,uVar2);
    }
    uVar5 = uVar2 + 1;
    uVar6 = uVar5;
    if (uVar2 != 0xffffffff) {
      uVar6 = param_3 & 0x7fffffff;
    }
    if (uVar6 != 0) {
      return CONCAT44(param_2,uVar5);
    }
  }
  if (uVar5 == 0) {
    param_2 = param_2 + 1;
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar5);
  }
LAB_20164f98:
  return (ulonglong)((uint)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_201649d8 @ 201649d8 (538 bytes)

longlong FUN_201649d8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint unaff_lr;
  uint uVar12;
  bool bVar13;
  
  if ((~(param_2 >> 4) & 0x7ff0000) == 0 || (~(param_4 >> 4) & 0x7ff0000) == 0) {
    FUN_20164efc();
    param_2 = extraout_r3;
  }
  else {
    uVar7 = param_2 ^ param_4;
    uVar4 = param_2 >> 4 & 0x7ff0000;
    bVar13 = uVar4 == 0;
    uVar6 = uVar7 >> 0x1f;
    if (!bVar13) {
      uVar7 = param_4 >> 4 & 0x7ff0000;
      bVar13 = uVar7 == 0;
    }
    if (bVar13) {
      if ((param_2 & 0x7ff00000) == 0) {
        if ((param_4 & 0x7ff00000) == 0) {
          return 0x7ff8000000000000;
        }
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
      param_2 = param_2 ^ param_4;
    }
    else {
      iVar5 = (uVar4 | uVar6) - uVar7;
      uVar7 = param_4 << 0xb | 0x80000000;
      uVar4 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
      uVar3 = uVar7 | param_3 >> 0x15;
      uVar6 = iVar5 + 0x3fe0000;
      if (uVar4 == uVar3 && param_1 * 0x800 == param_3 * 0x800) {
        uVar3 = 0x100000;
        uVar4 = 0;
      }
      else {
        uVar9 = (uint)*(byte *)((uVar7 >> 0x18) + 0x20164b80);
        uVar9 = uVar9 * (0x1000000 - uVar9 * (uVar7 >> 0x10)) >> 0xf;
        iVar10 = (int)((ulonglong)uVar9 * (ulonglong)uVar3);
        iVar8 = -(int)((ulonglong)uVar9 * (ulonglong)uVar3 >> 0x20);
        iVar11 = iVar8 + 0x10000;
        if (iVar10 != 0) {
          iVar11 = iVar8 + 0xffff;
        }
        uVar9 = uVar9 * iVar11 + (int)((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        lVar1 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(param_3 * 0x800) >> 0x20);
        iVar10 = (int)lVar1;
        iVar8 = -(int)((ulonglong)lVar1 >> 0x20);
        uVar3 = iVar8 + 0x80000000;
        if (iVar10 != 0) {
          uVar3 = iVar8 + 0x7fffffff;
        }
        uVar2 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        uVar9 = (uint)(uVar2 >> 0x20);
        uVar3 = (uint)((ulonglong)uVar4 * (uVar2 & 0xffffffff) >> 0x20);
        uVar12 = (uint)((ulonglong)(param_1 * 0x800) * (ulonglong)uVar9 >> 0x20);
        uVar2 = (ulonglong)uVar4 * (ulonglong)uVar9 +
                (ulonglong)CONCAT14(CARRY4(uVar3,uVar12),uVar3 + uVar12);
        iVar8 = (int)(uVar2 >> 0x20);
        unaff_lr = iVar8 + 0x70000000;
        if (!SCARRY4(iVar8,0x70000000)) {
          uVar6 = iVar5 + 0x3fd0000;
          uVar2 = CONCAT44(iVar8 * 2 + (uint)((uVar2 & 0x80000000) != 0),(int)uVar2 << 1);
        }
        uVar3 = (uint)(uVar2 + 0x80 >> 0x20);
        uVar4 = (uint)(uVar2 + 0x80) >> 8 | uVar3 * 0x1000000;
        uVar3 = uVar3 >> 8;
        if ((int)uVar2 * 0x1000000 + 0x91000000U < 0x10000001) {
          uVar9 = param_3 & 0x1fffff | (param_3 >> 0x15) << 0x15;
          iVar5 = uVar3 * uVar9 +
                  uVar4 * (uVar7 >> 0xb) + (int)((ulonglong)uVar4 * (ulonglong)uVar9 >> 0x20);
          if (-1 < (int)unaff_lr) {
            iVar5 = iVar5 + param_1 * -0x100000;
          }
          unaff_lr = iVar5 + param_1 * -0x100000 +
                     (uVar7 >> 0xc) +
                     (uint)CARRY4((uint)((ulonglong)uVar4 * (ulonglong)uVar9),
                                  uVar9 >> 1 | (uVar7 >> 0xb) << 0x1f);
          if ((int)unaff_lr < 0) {
            bVar13 = 0xfffffffe < uVar4;
            uVar4 = uVar4 + 1;
            uVar3 = uVar3 + bVar13;
          }
        }
      }
      iVar5 = uVar3 + uVar6 * -0x80000000 + (uVar6 & 0xfffffffe) * 0x10;
      if ((uVar6 & 0xfffffffe) < 0x7f00001) {
        return CONCAT44(iVar5,uVar4);
      }
      if (-1 < (int)uVar6) {
        unaff_lr = iVar5 + 0x100000;
      }
      if (-1 < (int)uVar6 && -1 < (int)(unaff_lr ^ uVar6 << 0x1f)) {
        return CONCAT44(iVar5,uVar4);
      }
      if ((int)uVar6 < 0) {
        return (ulonglong)(iVar5 + 0x60000000U & 0x80000000) << 0x20;
      }
      param_2 = iVar5 + 0xa0000000;
    }
  }
  return (ulonglong)((uint)((int)param_2 < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_20164c90 @ 20164c90 (92 bytes)

uint FUN_20164c90(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  
  iVar1 = ((param_2 & 0x7fffffff) >> 0x14) - 0x400;
  bVar5 = SBORROW4(0x1e,iVar1);
  uVar2 = -iVar1 + 0x1e;
  bVar4 = uVar2 == 0;
  uVar3 = uVar2;
  if (!bVar4 && iVar1 < 0x1f) {
    bVar5 = SBORROW4(0x21,uVar2);
    uVar3 = 0x21 - uVar2;
    bVar4 = uVar2 == 0x21;
  }
  if (!bVar4 && (int)uVar3 < 0 == bVar5) {
    return ((param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff) ^ (int)param_2 >> 0x1f
           ) - ((int)param_2 >> 0x1f);
  }
  if (0x10 < (int)uVar2) {
    return 0;
  }
  if (-iVar1 != -0x3ff) {
    return (int)param_2 >> 0x20 ^ 0x7fffffff;
  }
  FUN_20164efc(param_1);
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== FUN_20164cf0 @ 20164cf0 (88 bytes)

uint FUN_20164cf0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  uint uVar3;
  bool bVar4;
  
  iVar1 = (param_2 >> 0x14) - 0x400;
  bVar4 = SBORROW4(0x1e,iVar1);
  uVar2 = -iVar1 + 0x1e;
  uVar3 = uVar2;
  if (iVar1 < 0x1f) {
    bVar4 = SBORROW4(0x20,uVar2);
    uVar3 = 0x20 - uVar2;
  }
  if ((int)uVar3 < 0 == bVar4) {
    return (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff);
  }
  if ((int)param_2 < 0) {
    return 0;
  }
  if (0x10 < (int)uVar2) {
    return 0;
  }
  if (-iVar1 != -0x3ff) {
    return 0xffffffff;
  }
  FUN_20164efc(param_1);
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== FUN_20164d54 @ 20164d54 (46 bytes)

undefined8 FUN_20164d54(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    return CONCAT44(uVar2 + (0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
  }
  return 0;
}


// ===== FUN_20164d82 @ 20164d82 (38 bytes)

undefined8 FUN_20164d82(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    return CONCAT44((0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
  }
  return 0;
}


// ===== FUN_20164da8 @ 20164da8 (312 bytes)

longlong FUN_20164da8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  int extraout_r1;
  int iVar7;
  uint uVar8;
  uint extraout_r3;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  
  uVar13 = param_2 >> 4 & 0x7ff0000;
  bVar16 = uVar13 == 0;
  if (!bVar16) {
    unaff_r5 = param_4 >> 4 & 0x7ff0000;
    bVar16 = unaff_r5 == 0;
  }
  if (!bVar16) {
    bVar16 = uVar13 == 0x7ff0000;
  }
  if (!bVar16) {
    bVar16 = unaff_r5 == 0x7ff0000;
  }
  if (bVar16) {
    if (uVar13 != 0x7ff0000 && (param_4 >> 4 & 0x7ff0000) != 0x7ff0000) {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    FUN_20164efc();
    uVar13 = extraout_r1 << 2 ^ extraout_r3;
  }
  else {
    uVar6 = param_2 & 0x1fffff | 0x100000;
    uVar8 = param_4 & 0x1fffff | 0x100000;
    iVar14 = (uVar13 | (param_2 ^ param_4) >> 0x1f) + unaff_r5;
    lVar1 = (ulonglong)uVar6 * (ulonglong)param_3;
    uVar11 = (uint)((ulonglong)lVar1 >> 0x20);
    lVar2 = (ulonglong)param_1 * (ulonglong)uVar8;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    iVar15 = iVar14 + -0x3fc0000;
    lVar4 = lVar1 + lVar2;
    uVar10 = (uint)((ulonglong)lVar4 >> 0x20);
    lVar3 = (ulonglong)uVar6 * (ulonglong)uVar8;
    uVar13 = (uint)lVar3;
    uVar12 = (uint)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
    lVar5 = lVar4 + CONCAT44(uVar13,uVar12);
    uVar8 = (uint)lVar5;
    uVar6 = (uint)((ulonglong)lVar5 >> 0x20);
    uVar13 = (int)((ulonglong)lVar3 >> 0x20) +
             (uint)(CARRY4(uVar9,uVar11) ||
                   CARRY4(uVar9 + uVar11,(uint)CARRY4((uint)lVar2,(uint)lVar1))) +
             (uint)(CARRY4(uVar10,uVar13) ||
                   CARRY4(uVar10 + uVar13,(uint)CARRY4((uint)lVar4,uVar12)));
    if ((int)((ulonglong)param_1 * (ulonglong)param_3) != 0) {
      uVar8 = uVar8 | 1;
    }
    if ((uVar13 & 0x200) == 0) {
      uVar9 = uVar8 << 0xc;
      uVar13 = uVar13 * 0x1000 | uVar6 >> 0x14;
      uVar6 = uVar6 << 0xc | uVar8 >> 0x14;
      iVar7 = -4;
    }
    else {
      uVar9 = uVar8 << 0xb;
      uVar13 = uVar13 * 0x800 | uVar6 >> 0x15;
      uVar6 = uVar6 << 0xb | uVar8 >> 0x15;
      iVar7 = -3;
    }
    uVar8 = iVar7 + (iVar15 >> 0x10);
    uVar13 = uVar13 + uVar8 * 0x100000 ^ iVar14 * -0x80000000;
    if (uVar9 != 0) {
      bVar16 = (uVar9 & 0x80000000) != 0;
      if ((uVar9 & 0x7fffffff) != 0) {
        uVar9 = 0;
      }
      uVar13 = uVar13 + CARRY4(uVar6,(uint)bVar16);
      uVar6 = uVar6 + bVar16 & ~(uVar9 >> 0x1f);
    }
    if (uVar8 < 0x7fe) {
      return CONCAT44(uVar13,uVar6);
    }
    if (iVar15 < 0x4000000) {
      return (ulonglong)(uVar13 + 0x60000000 & 0x80000000) << 0x20;
    }
    uVar13 = uVar13 + 0xa0000000;
  }
  return (ulonglong)((uint)((int)uVar13 < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_20164efc @ 20164efc (152 bytes)

int FUN_20164efc(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r5;
  uint uVar2;
  uint uVar3;
  int unaff_lr;
  uint *puVar4;
  bool bVar5;
  
  puVar4 = (uint *)(unaff_lr + 2U & 0xfffffffc);
  uVar2 = *puVar4;
  if ((((int)uVar2 < 0) || (unaff_r5 = param_4 * 2 + (uint)(param_3 != 0), unaff_r5 < 0xffe00001))
     && (uVar3 = param_2 * 2 + (uint)(param_1 != 0), uVar3 < 0xffe00001)) {
    if (uVar3 == 0xffe00000) {
      uVar3 = ((int)param_2 >> 0x1f) * -3 + 2;
      if (unaff_r5 == 0xffe00000) {
        uVar3 = uVar3 + (1 - ((int)param_4 >> 0x1f));
      }
    }
    else {
      uVar3 = param_4 >> 0x1f;
    }
  }
  else {
    uVar3 = 8;
  }
  uVar2 = uVar2 >> (uVar3 * 3 & 0xff) & 7;
  switch(uVar2) {
  case 4:
    param_1 = param_3;
    param_2 = param_4;
switchD_20164f68_caseD_5:
    bVar5 = CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)(param_1 != 0));
    uVar2 = param_2 * 2 + (uint)(param_1 != 0);
    if (uVar2 != 0) {
      bVar5 = uVar2 < 0x200001;
    }
    if (bVar5 && (uVar2 != 0 && uVar2 != 0x200000)) {
      param_1 = 0;
    }
    return param_1;
  case 5:
    goto switchD_20164f68_caseD_5;
  case 6:
  case 7:
    return 0;
  default:
                    /* WARNING: Could not recover jumptable at 0x20164f66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(puVar4 + uVar2 + 1))();
    return iVar1;
  }
}


// ===== FUN_20164fa4 @ 20164fa4 (464 bytes)

/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_20164fa4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  
  if (-1 < (int)(param_2 ^ param_4)) {
    bVar11 = param_3 <= param_1;
    uVar7 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar7);
      param_3 = param_3 + uVar7;
      uVar8 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar8 + bVar12;
      bVar11 = param_1 < uVar7;
      param_1 = param_1 - uVar7;
      param_2 = (param_2 - uVar8) - (uint)bVar11;
    }
    uVar8 = param_2 >> 0x14;
    uVar7 = uVar8 - (param_4 >> 0x14);
    if ((param_4 & 0x7ff00000) == 0 || (uVar8 & 0x7ff) == 0x7ff) {
      if ((uVar8 & 0x7ff) != 0x7ff) {
        if ((param_2 & 0x7ff00000) == 0) {
          param_2 = 0;
          param_1 = 0;
        }
        return CONCAT44(param_2,param_1);
      }
      FUN_20164efc();
      do {
        software_interrupt(0x40);
      } while( true );
    }
    uVar5 = -param_3;
    uVar2 = param_2 & ~(uVar8 << 0x14);
    iVar6 = -(param_4 & 0xfffff) + -0x100000;
    if (param_3 != 0) {
      iVar6 = -(param_4 & 0xfffff) + -0x100001;
    }
    if (uVar7 < 0x21) {
      uVar9 = uVar5 >> (uVar7 & 0xff);
      uVar1 = param_1 + uVar9;
      uVar2 = uVar2 + (iVar6 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar9);
      uVar10 = iVar6 << (0x20 - uVar7 & 0xff);
      uVar9 = uVar1 + uVar10;
      bVar11 = CARRY4(uVar2,(uint)CARRY4(uVar1,uVar10));
      iVar6 = uVar2 + CARRY4(uVar1,uVar10);
      uVar7 = 0x20 - uVar7;
    }
    else {
      uVar5 = (uint)(param_3 * -2 != 0) | (iVar6 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar7 = uVar7 - 0x20;
      if (0x1d < uVar7) {
        return CONCAT44(uVar2 + uVar8 * 0x100000,param_1);
      }
      uVar1 = iVar6 >> (uVar7 & 0xff);
      uVar9 = param_1 + uVar1;
      bVar11 = uVar2 != 0 || CARRY4(uVar2 - 1,(uint)CARRY4(param_1,uVar1));
      iVar6 = (uVar2 - 1) + (uint)CARRY4(param_1,uVar1);
      uVar7 = 0x1e - uVar7;
    }
    if (-1 < iVar6) {
      iVar4 = uVar5 << (uVar7 & 0xff);
      iVar6 = iVar6 + uVar8 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar6,uVar9);
      }
      uVar9 = uVar9 + 1;
      if (uVar9 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar6,uVar9);
      }
      if (uVar9 == 0) {
        iVar6 = iVar6 + 1;
        uVar9 = 0;
      }
      else {
        uVar9 = uVar9 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar9);
    }
    uVar2 = uVar7 + 1 & 0xff;
    bVar11 = uVar2 == 0 && bVar11 || uVar2 != 0 && (uVar5 << uVar2 - 1 & 0x80000000) != 0;
    uVar1 = uVar9 * 2 + (uint)bVar11;
    uVar7 = iVar6 * 2 + (uint)(CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)bVar11));
    uVar9 = uVar7 + uVar8 * 0x200000;
    bVar11 = (uVar9 >> 0x14 & 1) != 0;
    if (bVar11 && uVar9 >> 0x15 != 0) {
      uVar9 = -((int)(uVar5 << uVar2) >> 0x1f);
      uVar10 = uVar1 + uVar9;
      bVar11 = uVar10 == 0;
      iVar6 = uVar7 + uVar8 * 0x100000;
      if (!CARRY4(uVar1,uVar9)) {
        bVar11 = uVar5 << uVar2 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar6,uVar10);
      }
      if (uVar10 == 0) {
        iVar6 = iVar6 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar10);
    }
    if (!bVar11) {
      iVar6 = uVar7 + 0x200000;
      if (iVar6 == 0) {
        uVar7 = uVar1 << LZCOUNT(uVar1);
        if (uVar7 == 0) {
          return (ulonglong)uVar1;
        }
        iVar4 = ((uVar8 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
        iVar6 = uVar7 << 0x15;
        uVar7 = uVar7 >> 0xb;
      }
      else {
        uVar5 = LZCOUNT(iVar6) - 0xb;
        iVar4 = ((uVar8 & 0xfffff7ff) - uVar5) + -2;
        uVar7 = iVar6 << (uVar5 & 0xff) | uVar1 >> (0x20 - uVar5 & 0xff);
        iVar6 = uVar1 << (uVar5 & 0xff);
      }
      iVar3 = uVar7 + (param_2 & 0x80000000) + iVar4 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar3,iVar6);
      }
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    uVar8 = ((int)uVar7 >> 1) + uVar8 * 0x100000;
    uVar7 = (uint)((uVar7 & 1) != 0) << 0x1f | uVar1 >> 1;
    if (uVar8 * 2 == 0 && uVar7 == 0) {
      return (ulonglong)uVar7;
    }
    if (0x1fffff < uVar8 * 2) {
      return CONCAT44(uVar8,uVar7);
    }
    return (ulonglong)(uVar8 & 0x80000000) << 0x20;
  }
  param_4 = param_4 ^ 0x80000000;
  uVar7 = param_1 - param_3;
  iVar6 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar7);
    param_3 = param_3 + uVar7;
    param_4 = param_4 + iVar6 + (uint)bVar11;
    bVar11 = param_1 < uVar7;
    param_1 = param_1 - uVar7;
    param_2 = (param_2 - iVar6) - (uint)bVar11;
  }
  uVar8 = param_2 >> 0x14;
  uVar7 = uVar8 - (param_4 >> 0x14);
  if ((param_4 & 0x7ff00000) == 0 || (uVar8 & 0x7ff) == 0x7ff) {
    if ((uVar8 & 0x7ff) != 0x7ff) {
      if ((param_2 & 0x7ff00000) == 0) {
        param_2 = param_2 & 0x80000000;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    FUN_20164efc();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_2 = param_2 & ~(uVar8 << 0x14);
  uVar5 = param_4 & 0x1fffff | 0x100000;
  if (uVar7 < 0x21) {
    uVar1 = param_3 >> (uVar7 & 0xff);
    uVar2 = param_1 + uVar1;
    uVar10 = uVar5 << (0x20 - uVar7 & 0xff);
    uVar9 = uVar2 + uVar10;
    param_2 = param_2 + (uVar5 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar1) +
              (uint)CARRY4(uVar2,uVar10);
    uVar7 = 0x20 - uVar7;
    if (param_2 < 0x100000) {
      param_2 = param_2 + uVar8 * 0x100000;
      goto LAB_20164904;
    }
LAB_20164966:
    bVar13 = (byte)uVar9 & 1;
    uVar5 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar9 >> 1;
    param_2 = (param_2 + 0x100000 >> 1) + uVar8 * 0x100000;
    if ((uVar9 & 1) == 0) {
LAB_20164994:
      if (param_2 * 2 < 0xffe00000) {
        return CONCAT44(param_2,uVar5);
      }
      goto LAB_20164f98;
    }
    bVar11 = CARRY4(uVar5,(uint)bVar13);
    uVar5 = uVar5 + bVar13;
    uVar8 = uVar5;
    if (!bVar11) {
      uVar8 = param_3 << (uVar7 & 0xff);
    }
    if (uVar8 != 0) goto LAB_20164994;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar2 = uVar7 - 0x20;
    uVar7 = 0x1f - uVar2;
    if (uVar2 < 0x20) {
      uVar5 = uVar5 >> (uVar2 & 0xff);
      uVar9 = param_1 + uVar5;
    }
    else {
      uVar7 = 0;
      uVar9 = param_1;
    }
    param_2 = param_2 + uVar8 * 0x100000 + (uint)(uVar2 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar8 != param_2 >> 0x14) {
      param_2 = param_2 + uVar8 * -0x100000;
      goto LAB_20164966;
    }
LAB_20164904:
    param_3 = param_3 << (uVar7 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(param_2,uVar9);
    }
    uVar5 = uVar9 + 1;
    uVar7 = uVar5;
    if (uVar9 != 0xffffffff) {
      uVar7 = param_3 & 0x7fffffff;
    }
    if (uVar7 != 0) {
      return CONCAT44(param_2,uVar5);
    }
  }
  if (uVar5 == 0) {
    param_2 = param_2 + 1;
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar5);
  }
LAB_20164f98:
  return (ulonglong)((uint)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}

