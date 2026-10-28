// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201493b4 @ 201493b4 (108 bytes)

void FUN_201493b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int local_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iStack_24 = param_1;
  uStack_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  uVar3 = FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 2);
  iVar1 = FUN_2014919c(param_1,(int)uVar3,&local_28,param_4);
  if (iVar1 == 0) {
    uVar2 = FUN_2014d93c(&uStack_1c);
    *(undefined4 *)(local_28 + (int)((ulonglong)uVar3 >> 0x20) * 4) = uVar2;
    FUN_20149278(param_1,(int)uVar3);
  }
  return;
}


// ===== FUN_20149420 @ 20149420 (636 bytes)

uint FUN_20149420(int param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_30;
  undefined1 local_2f;
  int local_2c [2];
  
  if (*(char *)(param_1 + 0x10) == ' ') {
    if (param_4 != 0x77) {
      uVar3 = FUN_2014933c(param_1,param_2,param_5);
      return uVar3;
    }
    iVar4 = FUN_201493b4(param_1,param_2,param_3,param_5);
    if (iVar4 != 0) {
      return 0xffffff7;
    }
    return 0;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar5 = FUN_20156260(param_2,*(uint *)(param_1 + 0x6c) >> 1);
    iVar1 = (int)uVar5;
    iVar4 = (int)((ulonglong)uVar5 >> 0x20) << 1;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x6c);
    iVar1 = FUN_20156260(param_2 * 3,iVar4 << 1);
    iVar4 = (param_2 * 3 >> 1) - iVar4 * iVar1;
  }
  iVar2 = FUN_2014919c(param_1,iVar1,local_2c,param_5);
  if (iVar2 != 0) {
    return 0xffffff7;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar3 = FUN_2014d900(local_2c[0] + iVar4);
    if (param_4 == 0x77) {
      FUN_2014d8ec(local_2c[0] + iVar4,param_3 & 0xffff);
      iVar4 = FUN_20149278(param_1,iVar1,local_2c[0]);
      if (iVar4 != 0) {
        return 0xffffff7;
      }
    }
    goto LAB_20149684;
  }
  local_30 = *(undefined1 *)(local_2c[0] + iVar4);
  if (*(int *)(param_1 + 0x6c) + -1 == iVar4) {
    iVar1 = iVar1 + 1;
    iVar4 = -1;
    iVar2 = FUN_2014919c(param_1,iVar1,local_2c,param_5);
    if (iVar2 != 0) {
      return 0xffffff7;
    }
  }
  local_2f = *(undefined1 *)(local_2c[0] + iVar4 + 1);
  uVar3 = FUN_2014d900(&local_30);
  if ((param_2 & 1) == 0) {
    if (param_4 == 0x77) {
      FUN_2014d8ec(&local_30,uVar3 & 0xf000 | param_3 & 0xfff);
      goto LAB_201495e4;
    }
  }
  else {
    if (param_4 == 0x77) {
      FUN_2014d8ec(&local_30,uVar3 & 0xf | (param_3 & 0xfff) << 4);
    }
    uVar3 = uVar3 >> 4;
    if (param_4 == 0x77) {
LAB_201495e4:
      *(undefined1 *)(local_2c[0] + iVar4 + 1) = local_2f;
      if (iVar4 == -1) {
        iVar4 = FUN_20149278(param_1,iVar1);
        if (iVar4 != 0) {
          return 0xffffff7;
        }
        iVar1 = iVar1 + -1;
        iVar4 = FUN_2014919c(param_1,iVar1,local_2c,param_5);
        if (iVar4 != 0) {
          return 0xffffff7;
        }
        *(undefined1 *)(*(int *)(param_1 + 0x6c) + local_2c[0] + -1) = local_30;
      }
      else {
        *(undefined1 *)(local_2c[0] + iVar4) = local_30;
      }
      iVar4 = FUN_20149278(param_1,iVar1,local_2c[0]);
      if (iVar4 != 0) {
        return 0xffffff7;
      }
    }
  }
  uVar3 = uVar3 & 0xffff0fff;
  if (0xff6 < uVar3) {
    uVar3 = uVar3 | 0xf000;
  }
LAB_20149684:
  if (0xfff7 < uVar3) {
    uVar3 = 0xfffffff;
  }
  return uVar3;
}


// ===== FUN_2014969c @ 2014969c (32 bytes)

void FUN_2014969c(int param_1,uint param_2)

{
  *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) =
       *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) & ~(&DAT_20808bac)[param_2 & 7];
  return;
}


// ===== FUN_201496bc @ 201496bc (204 bytes)

undefined4 FUN_201496bc(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2;
  while( true ) {
    uVar1 = FUN_20149420(param_1,uVar3,0,0x72,param_3);
    if ((uVar1 == 0xffffff7) || (uVar3 < 2)) {
      return 0xffffffc3;
    }
    if ((*(int *)(param_1 + 0x58) != 0) && (uVar3 < *(uint *)(param_1 + 0x60))) {
      FUN_2014969c(param_1,uVar3);
    }
    iVar2 = FUN_20149420(param_1,uVar3,0,0x77,param_3);
    if (iVar2 == 0xffffff7) break;
    if (*(char *)(param_1 + 0x10) == ' ') {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    }
    uVar3 = uVar1;
    if (uVar1 + 0xf0000008 < 8) {
      if (*(int *)(param_1 + 0x2c) == 0) {
        *(uint *)(param_1 + 0x2c) = param_2;
      }
      return 0;
    }
  }
  return 0xffffffc3;
}


// ===== FUN_20149788 @ 20149788 (68 bytes)

undefined4 FUN_20149788(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_201496bc(param_1,param_2,param_3);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_201497cc @ 201497cc (88 bytes)

undefined4
FUN_201497cc(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_20149420(param_1,param_3,param_4,param_5,param_6);
    *param_2 = uVar2;
    FUN_2014dc10(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_20149824 @ 20149824 (32 bytes)

void FUN_20149824(int param_1,uint param_2)

{
  *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) =
       *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) | (&DAT_20808bac)[param_2 & 7];
  return;
}


// ===== FUN_20149844 @ 20149844 (28 bytes)

byte FUN_20149844(int param_1,uint param_2)

{
  return *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) & (&DAT_20808bac)[param_2 & 7];
}


// ===== FUN_20149860 @ 20149860 (224 bytes)

undefined4 FUN_20149860(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
LAB_20149870:
  uVar2 = *(uint *)(param_1 + 0x28);
  bVar4 = uVar2 <= *(uint *)(param_1 + 0x60);
  bVar3 = *(uint *)(param_1 + 0x60) == uVar2;
  if (bVar4 && !bVar3) {
    do {
      if (bVar4 && !bVar3) {
        iVar1 = FUN_20149844(param_1,uVar2);
        if (iVar1 == 0) goto LAB_20149908;
        if (*(int *)(param_1 + 0x2c) != 0) goto code_r0x201498a4;
      }
      uVar2 = uVar2 + 1;
      bVar4 = uVar2 <= *(uint *)(param_1 + 0x60);
      bVar3 = *(uint *)(param_1 + 0x60) == uVar2;
      if (!bVar4 || bVar3) break;
    } while( true );
  }
  goto LAB_201498c0;
code_r0x201498a4:
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  goto LAB_20149870;
LAB_201498c0:
  uVar2 = 2;
  if (*(uint *)(param_1 + 0x28) < 3) {
    return 0xffffff9d;
  }
  do {
    if (uVar2 < *(uint *)(param_1 + 0x60)) {
      iVar1 = FUN_20149844(param_1,uVar2);
      if (iVar1 == 0) {
LAB_20149908:
        *param_2 = uVar2;
        *(uint *)(param_1 + 0x28) = uVar2 + 1;
        FUN_20149824(param_1,uVar2);
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) break;
    }
    uVar2 = uVar2 + 1;
    if (*(uint *)(param_1 + 0x28) <= uVar2) {
      return 0xffffff9d;
    }
  } while( true );
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  goto LAB_201498c0;
}


// ===== FUN_20149940 @ 20149940 (320 bytes)

int FUN_20149940(int param_1,uint *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  int local_38 [2];
  int iStack_30;
  uint *local_2c;
  undefined4 local_28;
  
  bVar1 = false;
  iVar7 = 0;
  local_38[0] = 0;
  iVar4 = *(int *)(param_1 + 0xc);
  uVar6 = (*(uint *)(param_1 + 0x6c) >> 2) * iVar4;
  iStack_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5);
  iVar2 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + iVar4 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  if (iVar2 + 2U < uVar6) {
    uVar6 = iVar2 + 2U;
  }
LAB_201499a0:
  do {
    iVar2 = -1;
    for (uVar5 = *(uint *)(param_1 + 0x28); uVar5 < uVar6; uVar5 = uVar5 + 1) {
      uVar8 = FUN_20156260(uVar5,*(uint *)(param_1 + 0x6c) >> 2);
      iVar4 = (int)uVar8;
      if ((iVar2 != iVar4) &&
         (iVar3 = FUN_2014919c(param_1,iVar4,local_38,local_28), iVar2 = iVar4, iVar3 != 0)) {
        return iVar3;
      }
      if (local_38[0] != 0) {
        iVar7 = FUN_2014d93c(local_38[0] + (int)((ulonglong)uVar8 >> 0x20) * 4);
      }
      if (iVar7 == 0) {
        *local_2c = uVar5;
        *(uint *)(param_1 + 0x28) = uVar5 + 1;
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x2c) = 0;
        goto LAB_201499a0;
      }
    }
    if ((uVar5 != uVar6) || (bVar1)) {
      return -99;
    }
    uVar6 = *(uint *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 2;
    bVar1 = true;
  } while( true );
}


// ===== FUN_20149a80 @ 20149a80 (268 bytes)

uint FUN_20149a80(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_18;
  
  local_18 = param_4;
  if ((*(int *)(param_1 + 0x58) == 0) || (*(char *)(param_1 + 0x54) == '\0')) {
    iVar1 = FUN_20149940(param_1,&local_18);
  }
  else {
    iVar1 = FUN_20149860(param_1,&local_18);
    if (iVar1 == 0) goto LAB_20149af8;
    if (*(int *)(param_1 + 0x60) == *(int *)(param_1 + 100)) {
      return 0;
    }
    iVar1 = FUN_20149940(param_1,&local_18,param_3);
  }
  if (iVar1 != 0) {
    return 0;
  }
LAB_20149af8:
  iVar1 = FUN_201493b4(param_1,local_18,0xfffffff,param_3);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x58) != 0) && (local_18 < *(uint *)(param_1 + 0x60))) {
      FUN_20149824(param_1);
    }
    if (*(uint *)(param_1 + 0x2c) == local_18) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
    if (param_2 == 0) {
      return local_18;
    }
    iVar1 = FUN_201493b4(param_1,param_2,local_18,param_3);
    if (iVar1 == 0) {
      return local_18;
    }
  }
  return 0;
}


// ===== FUN_20149b8c @ 20149b8c (608 bytes)

uint FUN_20149b8c(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint local_24;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0x10) == ' ') {
    uVar3 = FUN_20149a80(param_1);
    return uVar3;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar3 = (*(uint *)(param_1 + 0x6c) >> 1) * *(int *)(param_1 + 0xc);
  }
  else {
    uVar3 = (*(uint *)(param_1 + 0x6c) * *(int *)(param_1 + 0xc) * 2) / 3;
  }
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  iVar2 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  if ((iVar2 + 2U & 0xffff) < uVar3) {
    uVar3 = iVar2 + 2U & 0xffff;
  }
  if ((*(int *)(param_1 + 0x58) != 0) && (*(char *)(param_1 + 0x54) != '\0')) {
    iVar2 = FUN_20149860(param_1,&local_24);
    if (iVar2 == 0) {
      iVar2 = FUN_20149420(param_1,local_24,0xffff,0x77,param_3);
      if (iVar2 == 0) {
        if (*(uint *)(param_1 + 0x2c) == local_24) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        if (param_2 != 0) {
          iVar2 = FUN_20149420(param_1,param_2,local_24,0x77,param_3);
joined_r0x20149d18:
          if (iVar2 == 0xffffff7) {
            return 0;
          }
        }
        return local_24;
      }
    }
    else if (*(int *)(param_1 + 0x60) != *(int *)(param_1 + 100)) goto LAB_20149c58;
    return 0;
  }
LAB_20149c58:
  do {
    for (local_24 = *(uint *)(param_1 + 0x28); local_24 < uVar3; local_24 = local_24 + 1) {
      iVar2 = FUN_20149420(param_1,local_24,0,0x72,param_3);
      if (iVar2 == 0) {
        *(uint *)(param_1 + 0x28) = local_24 + 1;
        iVar2 = FUN_20149420(param_1,local_24,0xffff,0x77,param_3);
        if (iVar2 != 0) {
          return 0;
        }
        if (*(uint *)(param_1 + 0x2c) == local_24) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        if ((*(int *)(param_1 + 0x58) != 0) && (local_24 < *(uint *)(param_1 + 0x60))) {
          FUN_20149824(param_1);
        }
        if (param_2 == 0) {
          return local_24;
        }
        iVar2 = FUN_20149420(param_1,param_2,local_24,0x77,param_3);
        goto joined_r0x20149d18;
      }
      if (iVar2 == 0xffffff7) {
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x2c) = 0;
        goto LAB_20149c58;
      }
    }
    if (local_24 != uVar3) {
      return 0;
    }
    if (bVar1) {
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 2;
    bVar1 = true;
  } while( true );
}


// ===== FUN_20149dec @ 20149dec (92 bytes)

undefined4
FUN_20149dec(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_20144800(0);
  iVar1 = FUN_2014db6c(param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_20149b8c(param_1,param_2,param_4);
    *param_3 = uVar2;
    FUN_2014dc10(param_1);
    uVar2 = FUN_2014d95c();
    return uVar2;
  }
  return 0xffffffde;
}


// ===== FUN_20149e48 @ 20149e48 (96 bytes)

undefined4 FUN_20149e48(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar3 = FUN_20149420(param_1,param_2,0,0x72,param_4);
    *param_3 = uVar3;
    if (0xffffff6 < uVar3) {
      *param_3 = 0;
    }
    FUN_2014dc10(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_20149eb0 @ 20149eb0 (184 bytes)

int FUN_20149eb0(int param_1,int param_2,int *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int local_20;
  
  uVar1 = *(ushort *)(param_1 + 4);
  local_20 = param_4;
  if (1 < uVar1) {
    iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    FUN_20156260((param_2 -
                 (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                          (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 != 0) {
      *param_3 = param_2 + 1;
      return 0;
    }
  }
  uVar3 = FUN_201449cc(param_1,param_2);
  iVar2 = FUN_20149dec(param_1,uVar3,&local_20,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_20 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_20144980(param_1);
  }
  *param_3 = iVar2;
  return 0;
}


// ===== FUN_20149f68 @ 20149f68 (184 bytes)

int FUN_20149f68(int param_1,int param_2,int *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int local_20;
  
  uVar1 = *(ushort *)(param_1 + 4);
  local_20 = param_4;
  if (1 < uVar1) {
    iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    FUN_20156260((param_2 -
                 (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                          (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 != 0) {
      *param_3 = param_2 + 1;
      return 0;
    }
  }
  uVar3 = FUN_201449cc(param_1,param_2);
  iVar2 = FUN_20149e48(param_1,uVar3,&local_20,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_20 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_20144980(param_1);
  }
  *param_3 = iVar2;
  return 0;
}


// ===== FUN_2014a020 @ 2014a020 (132 bytes)

int FUN_2014a020(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = *(undefined2 *)(param_1 + 0x3a);
  if (*(char *)(param_1 + 0x10) == ' ') {
    iVar2 = FUN_20144a10(param_1,uVar1,param_2 + 0xc0c,1);
    if (iVar2 == 0) {
      FUN_2014d918(param_2 + 0xdf4,*(undefined4 *)(param_1 + 0x3c));
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x28);
      FUN_2014d918(param_2 + 0xdf8);
      iVar2 = FUN_20144ac0(param_1,uVar1,param_2 + 0xc0c,1);
      return iVar2;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ===== FUN_2014a0a4 @ 2014a0a4 (60 bytes)

undefined4 FUN_2014a0a4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014a020(param_1,param_2);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014a0e0 @ 2014a0e0 (548 bytes)

void FUN_2014a0e0(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_28;
  int local_24 [2];
  
  local_28 = DAT_20808ba0;
  iVar4 = FUN_2014a4a4();
  if (iVar4 != 0) goto LAB_2014a14c;
  if (param_2 == 0 || param_3 == 0) {
    iVar4 = -0xd;
    goto LAB_2014a14c;
  }
  uVar3 = FUN_2014d35c(param_1);
  iVar4 = FUN_20144918(uVar3,&local_28);
  iVar2 = local_28;
  if (iVar4 != 0) goto LAB_2014a14c;
  cVar1 = *(char *)(local_28 + 0x10);
  if (cVar1 == '\f') {
    uVar5 = (uint)(*(int *)(local_28 + 0x6c) * *(int *)(local_28 + 0xc) * 2) / 3;
LAB_2014a1cc:
    *(uint *)(local_28 + 100) = uVar5;
  }
  else {
    if (cVar1 != '\x10') {
      if (cVar1 != ' ') {
        iVar4 = -0x10;
        goto LAB_2014a14c;
      }
      uVar5 = (*(uint *)(local_28 + 0x6c) >> 2) * *(int *)(local_28 + 0xc);
      goto LAB_2014a1cc;
    }
    *(uint *)(local_28 + 100) = (*(uint *)(local_28 + 0x6c) >> 1) * *(int *)(local_28 + 0xc);
  }
  uVar6 = *(undefined4 *)(local_28 + 0x6c);
  iVar4 = FUN_20156260((uint)*(ushort *)(local_28 + 10) << 5);
  iVar4 = FUN_20156260(*(int *)(iVar2 + 0x14) -
                       (iVar4 + *(int *)(iVar2 + 0xc) * (uint)*(ushort *)(iVar2 + 8) +
                                (uint)*(ushort *)(iVar2 + 6)),*(undefined2 *)(iVar2 + 4));
  if (iVar4 + 2U < *(uint *)(iVar2 + 100)) {
    *(uint *)(iVar2 + 100) = iVar4 + 2U;
  }
  uVar5 = *(uint *)(iVar2 + 100);
  if (param_3 < (uint)((uVar5 & 7) != 0) + (uVar5 >> 3)) {
    *(uint *)(iVar2 + 0x60) = param_3 << 3;
  }
  else {
    *(uint *)(iVar2 + 0x60) = uVar5;
  }
  *(int *)(iVar2 + 0x58) = param_2;
  *(uint *)(iVar2 + 0x5c) = param_3;
  FUN_2014d148(param_2,0,param_3,uVar6);
  if (param_5 == 0) {
    iVar4 = 0;
  }
  else {
    uVar5 = 0;
    if (*(int *)(local_28 + 0x60) != 0) {
      do {
        if ((*(byte *)(local_28 + 0x68) & 0x40) == 0) {
          iVar4 = -0x13;
          goto LAB_2014a14c;
        }
        iVar4 = FUN_201497cc(local_28,local_24,uVar5,0,0x72,param_4);
        if (iVar4 != 0) goto LAB_2014a14c;
        if (local_24[0] != 0) {
          FUN_20149824(local_28,uVar5);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(local_28 + 0x60));
    }
    *(undefined1 *)(local_28 + 0x54) = 1;
    iVar4 = 0;
  }
LAB_2014a14c:
  FUN_20144800(iVar4,0);
  return;
}


// ===== FUN_2014a304 @ 2014a304 (92 bytes)

undefined4 FUN_2014a304(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014a0e0(param_1,param_2,param_3,iVar1,1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014a360 @ 2014a360 (320 bytes)

void FUN_2014a360(undefined4 param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int local_18;
  
  local_18 = DAT_20808ba0;
  iVar4 = FUN_2014a4a4();
  if (iVar4 != 0) {
    FUN_20144800(iVar4,0);
    return;
  }
  if (param_2 == (uint *)0x0) {
    iVar4 = -0xd;
  }
  else {
    uVar3 = FUN_2014d35c(param_1);
    iVar4 = FUN_20144918(uVar3,&local_18);
    iVar2 = local_18;
    if (iVar4 == 0) {
      cVar1 = *(char *)(local_18 + 0x10);
      if (cVar1 == '\f') {
        uVar5 = (uint)(*(int *)(local_18 + 0x6c) * *(int *)(local_18 + 0xc) * 2) / 3;
      }
      else if (cVar1 == '\x10') {
        uVar5 = (*(uint *)(local_18 + 0x6c) >> 1) * *(int *)(local_18 + 0xc);
      }
      else {
        if (cVar1 != ' ') {
          iVar4 = -0x10;
          goto LAB_2014a3b8;
        }
        uVar5 = (*(uint *)(local_18 + 0x6c) >> 2) * *(int *)(local_18 + 0xc);
      }
      iVar4 = FUN_20156260((uint)*(ushort *)(local_18 + 10) << 5,*(undefined4 *)(local_18 + 0x6c));
      iVar4 = FUN_20156260(*(int *)(iVar2 + 0x14) -
                           (iVar4 + *(int *)(iVar2 + 0xc) * (uint)*(ushort *)(iVar2 + 8) +
                                    (uint)*(ushort *)(iVar2 + 6)),*(undefined2 *)(iVar2 + 4));
      if (iVar4 + 2U < uVar5) {
        uVar5 = iVar4 + 2U;
      }
      *param_2 = uVar5 >> 3;
      iVar4 = 0;
      *param_2 = (uVar5 >> 3) + (uint)((uVar5 & 7) != 0);
    }
  }
LAB_2014a3b8:
  FUN_20144800(iVar4,0);
  return;
}


// ===== FUN_2014a4a4 @ 2014a4a4 (44 bytes)

undefined4 FUN_2014a4a4(void)

{
  undefined4 uVar1;
  
  if (DAT_20808b90 == 0) {
    uVar1 = 0xffffffee;
  }
  else if (DAT_20808ba0 == 0) {
    uVar1 = 0xffffffef;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_2014a4d0 @ 2014a4d0 (268 bytes)

void FUN_2014a4d0(undefined4 param_1,short param_2,undefined4 param_3,short param_4)

{
  int iVar1;
  
  FUN_2014d148(param_1,0,param_2 * 0x450);
  FUN_2014d148(param_3,0,param_4 * 0x24c);
  DAT_20808ba0 = 0;
  DAT_20808b90 = param_1;
  DAT_20808b94 = param_2;
  DAT_20808b98 = param_3;
  DAT_20808b9c = param_4;
  FUN_2014e0c8();
  iVar1 = FUN_2014e178();
  if (iVar1 < 0) {
    FUN_20144800(0xffffffe2,0);
    return;
  }
  iVar1 = FUN_2014dad0();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffdc,0);
    return;
  }
  iVar1 = FUN_2014dc7c();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffdf,0);
    return;
  }
  iVar1 = FUN_2014de84();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffd9,0);
    return;
  }
  iVar1 = FUN_2014df48();
  if (iVar1 != 0) {
    FUN_20144800(0xffffffd6,0);
    return;
  }
  FUN_20144800(0,0);
  return;
}


// ===== FUN_2014a5dc @ 2014a5dc (572 bytes)

void FUN_2014a5dc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_24 [8];
  
  iVar4 = FUN_2014a4a4();
  if (iVar4 == -0x12) {
    FUN_20144800(0xffffffee,0);
    return;
  }
  FUN_2014d148(param_1,0,0x74,param_6);
  uVar3 = FUN_2014d35c(param_2);
  *(undefined1 *)((int)param_1 + 0x11) = uVar3;
  param_1[0x1b] = param_6;
  param_1[7] = param_4;
  param_1[6] = param_3;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  if (param_5 != 0) {
    *(undefined1 *)(param_1 + 0x1a) = 1;
  }
  param_1[0xd] = 0;
  param_1[10] = 2;
  puVar1 = param_1;
  if (DAT_20808ba0 != (undefined4 *)0x0) {
    puVar1 = DAT_20808ba0;
    for (puVar2 = (undefined4 *)*DAT_20808ba0; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      puVar1 = puVar2;
    }
    *puVar1 = param_1;
    puVar1 = DAT_20808ba0;
  }
  DAT_20808ba0 = puVar1;
  *param_1 = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)((int)param_1 + 0x4a) = 0;
  param_1[0x11] = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined2 *)((int)param_1 + 0x52) = 0;
  param_1[0x13] = 0;
  iVar4 = (*(code *)param_1[6])(param_1,5,0,0,1);
  if (iVar4 != 0) {
LAB_2014a734:
    FUN_20144834();
    return;
  }
  iVar4 = FUN_2014dd4c(param_1);
  if (iVar4 < 0) {
    iVar4 = -0x2d;
    goto LAB_2014a774;
  }
  if (param_5 != 0) goto LAB_2014a774;
  iVar4 = (*(code *)param_1[6])(param_1,7,0,0,1);
  if (iVar4 != 0) goto LAB_2014a734;
  iVar4 = 0;
  if (*(char *)(param_1 + 4) == '@') goto LAB_2014a774;
  if (param_1[0x1b] * (uint)*(ushort *)(param_1 + 1) < 0x20001) {
    if (*(char *)(param_1 + 4) != ' ') goto LAB_2014a774;
    if (param_1[0xf] == -1) {
      iVar5 = FUN_2014e118();
      if (iVar5 == 0) {
        iVar4 = FUN_2014ddd0(param_1);
        if (iVar4 == 0) {
          iVar4 = -0x1f;
          goto LAB_2014a774;
        }
        goto LAB_2014a800;
      }
      iVar4 = FUN_2014b730((int)*(char *)((int)param_1 + 0x11),auStack_24,auStack_24,iVar5);
      FUN_2014e14c(iVar5);
    }
    if (param_1[0x10] == -1) {
      param_1[0x10] = 2;
    }
    param_1[10] = param_1[0x10];
  }
  else {
    iVar4 = FUN_2014ddd0(param_1);
    if (iVar4 == 0) {
      iVar4 = -0x10;
      goto LAB_2014a774;
    }
LAB_2014a800:
    iVar4 = -0x35;
  }
LAB_2014a774:
  FUN_20144800(iVar4,0);
  return;
}


// ===== FUN_2014a818 @ 2014a818 (36 bytes)

void FUN_2014a818(void)

{
  FUN_2014a5dc();
  return;
}


// ===== FUN_2014a83c @ 2014a83c (352 bytes)

void FUN_2014a83c(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 != -0x12) {
    FUN_2014d148(DAT_20808b90,0,DAT_20808b94 * 0x450);
    FUN_2014d148(DAT_20808b98,0,DAT_20808b9c * 0x24c);
    DAT_20808b90 = 0;
    DAT_20808b94 = 0;
    DAT_20808b98 = 0;
    DAT_20808b9c = 0;
    piVar1 = (int *)iVar3;
    while (iVar3 != 0) {
      if ((0 < piVar1[0x1c]) && (iVar3 = FUN_2014ddd0(piVar1), iVar3 != 0)) {
        FUN_20144800(0xffffffcb,0);
        return;
      }
      iVar3 = *piVar1;
      piVar1 = (int *)*piVar1;
    }
    DAT_20808ba0 = 0;
    FUN_2014e100();
    iVar3 = FUN_2014e1b4();
    if (iVar3 != 0) {
      FUN_20144800(0xffffffd0,0);
      return;
    }
    iVar3 = FUN_2014db2c();
    if (iVar3 != 0) {
      FUN_20144800(0xffffffce,0);
      return;
    }
    iVar3 = FUN_2014dcd8();
    if (iVar3 != 0) {
      FUN_20144800(0xffffffcf,0);
      return;
    }
    iVar3 = FUN_2014decc();
    if (iVar3 != 0) {
      FUN_20144800(0xffffffcd,0);
      return;
    }
    iVar3 = FUN_2014df8c();
    if (iVar3 != 0) {
      FUN_20144800(0xffffffcc,0);
      return;
    }
  }
  FUN_20144800(0);
  return;
}


// ===== FUN_2014a99c @ 2014a99c (56 bytes)

void FUN_2014a99c(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}


// ===== FUN_2014a9d4 @ 2014a9d4 (284 bytes)

void FUN_2014a9d4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_1c [8];
  
  uVar3 = FUN_2014a4a4();
  iVar1 = (int)uVar3;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x28) = 2;
    FUN_2014a99c(param_1,(int)((ulonglong)uVar3 >> 0x20));
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,7,0,0,1);
    if (iVar1 != 0) {
      FUN_20144834();
      return;
    }
    iVar1 = 0;
    if (*(char *)(param_1 + 0x10) != '@') {
      if (0x20000 < *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 4)) {
        *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
        iVar1 = -0x10;
        goto LAB_2014aa68;
      }
      if (*(char *)(param_1 + 0x10) == ' ') {
        if (*(int *)(param_1 + 0x3c) == -1) {
          iVar2 = FUN_2014e118();
          if (iVar2 == 0) {
            iVar1 = -0x1f;
            goto LAB_2014aa68;
          }
          iVar1 = FUN_2014b730((int)*(char *)(param_1 + 0x11),auStack_1c,auStack_1c,iVar2);
          FUN_2014e14c(iVar2);
        }
        if (*(int *)(param_1 + 0x40) == -1) {
          *(undefined4 *)(param_1 + 0x40) = 2;
        }
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x40);
      }
    }
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) | 0x80;
  }
LAB_2014aa68:
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_2014aaf0 @ 2014aaf0 (132 bytes)

void FUN_2014aaf0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_2014a4a4();
  if (iVar1 != 0) {
    FUN_20144800(iVar1,0);
    return;
  }
  if ((*(byte *)(param_1 + 0x68) & 1) != 0) {
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,8,0);
    if (iVar1 != 0) {
      FUN_20144834();
      return;
    }
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
    FUN_20144800(0,0);
    return;
  }
  FUN_20144800(0xfffffff0,0);
  return;
}


// ===== FUN_2014ab74 @ 2014ab74 (168 bytes)

void FUN_2014ab74(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    FUN_20144800(0xfffffff3,0);
    return;
  }
  if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
    FUN_20144800(0xfffffff0,0);
    return;
  }
  iVar2 = FUN_2014ddd0(param_1);
  if (iVar2 != 0) {
    FUN_20144800(0xffffffcb,0);
    return;
  }
  if (DAT_20808ba0 == param_1) {
    DAT_20808ba0 = (int *)*param_1;
  }
  else {
    piVar1 = (int *)*DAT_20808ba0;
    piVar4 = DAT_20808ba0;
    while (piVar3 = piVar1, piVar3 != (int *)0x0) {
      if (param_1 == piVar3) {
        *piVar4 = *piVar3;
        break;
      }
      piVar4 = piVar3;
      piVar1 = (int *)*piVar3;
    }
  }
  FUN_20144800(0);
  return;
}


// ===== FUN_2014ac30 @ 2014ac30 (492 bytes)

int FUN_2014ac30(char *param_1,char *param_2,char *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_4c;
  undefined1 auStack_48 [11];
  char local_3d;
  undefined2 local_32;
  undefined2 local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  local_4c = DAT_20808ba0;
  uVar1 = FUN_2014d35c((int)*param_1);
  iVar2 = FUN_20144918(uVar1,&local_4c);
  if ((iVar2 != 0) || (iVar2 = FUN_20144950(local_4c), iVar2 != 0)) {
    return iVar2;
  }
  param_1 = param_1 + 2;
  uVar3 = *(undefined4 *)(local_4c + 0x34);
  if (*(char *)(local_4c + 0x10) != ' ') {
    param_1 = (char *)FUN_20147248(param_1,param_3);
    if ((param_1 == (char *)0x0) || (*param_3 == '\0')) {
      return -1;
    }
    iVar2 = FUN_20146338(local_4c,param_3,auStack_48,0,0,auStack_28,param_3);
    if (iVar2 != 0) {
      if (*param_1 == '\0') {
        return -3;
      }
      return -4;
    }
    uVar3 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
  }
  if (*param_1 != '\0') {
    do {
      param_1 = (char *)FUN_20147248(param_1,param_3);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_3 == '\0') {
        return -1;
      }
      iVar2 = FUN_201471cc(local_4c,uVar3,param_3,auStack_48,0,0,auStack_28,auStack_24,param_3);
      if (iVar2 != 0) {
        if (*param_1 == '\0' && iVar2 == -4) {
          return -3;
        }
        return iVar2;
      }
      uVar3 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
    } while (*param_1 != '\0');
  }
  FUN_2014d128(param_2,auStack_48,0xb);
  if (*param_2 == '\x05') {
    *param_2 = -0x1b;
  }
  param_2[0xb] = local_3d;
  FUN_201475d0(param_2 + 0xc,local_32,local_30);
  uVar3 = FUN_20146884(auStack_48,(int)*(char *)(local_4c + 0x10));
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  uVar3 = FUN_2014d93c(auStack_2c);
  *(undefined4 *)(param_2 + 0x34) = uVar3;
  return 0;
}


// ===== FUN_2014ae1c @ 2014ae1c (172 bytes)

void FUN_2014ae1c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_2014a4a4();
  if (iVar1 == 0) {
    if (param_1 == 0) {
      FUN_20144800(0xffffffff,0);
      return;
    }
    if (param_2 == 0) {
      FUN_20144800(0xfffffff3,0);
      return;
    }
    iVar1 = FUN_201473c4(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_2014d220(param_1);
      iVar2 = param_3 + 0x100c;
      FUN_2014d288(iVar2,param_1,iVar1 + 1);
      FUN_2014cd68(iVar2);
      uVar3 = FUN_2014ac30(iVar2,param_2,param_3);
      FUN_20144800(uVar3,0);
      return;
    }
  }
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_2014aec8 @ 2014aec8 (76 bytes)

undefined4 FUN_2014aec8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014ae1c(param_1,param_2,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014af14 @ 2014af14 (48 bytes)

int FUN_2014af14(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_40 [11];
  char local_35;
  
  iVar1 = FUN_2014aec8(param_1,auStack_40);
  if (iVar1 == 0) {
    FUN_20144800(0);
    iVar1 = (int)local_35;
  }
  return iVar1;
}


// ===== FUN_2014af44 @ 2014af44 (32 bytes)

undefined4 FUN_2014af44(int param_1,undefined4 param_2)

{
  FUN_2014d128(param_2,param_1 + 0x2c,4);
  return 0;
}


// ===== FUN_2014af64 @ 2014af64 (100 bytes)

void FUN_2014af64(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014a4a4();
  if ((iVar1 == 0) && (iVar1 = FUN_20144878(param_1), iVar1 == 0)) {
    if (param_2 != 0) {
      uVar2 = FUN_2014af44(param_1,param_2);
      FUN_20144800(uVar2,param_1);
      return;
    }
    FUN_20144800(0xfffffff3,param_1);
    return;
  }
  FUN_20144800(iVar1,0);
  return;
}


// ===== FUN_2014afcc @ 2014afcc (84 bytes)

void FUN_2014afcc(uint param_1,undefined4 *param_2,int *param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_20156260(0x800000,param_4 >> 9);
  if (param_1 < uVar1) {
    *param_2 = 0;
  }
  else {
    uVar2 = FUN_20156260(param_1,uVar1);
    param_1 = (uint)((ulonglong)uVar2 >> 0x20);
    *param_2 = (int)uVar2;
  }
  *param_3 = param_1 * param_4;
  return;
}


// ===== FUN_2014b020 @ 2014b020 (288 bytes)

undefined4 FUN_2014b020(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  piVar5 = DAT_20808ba0;
  iVar3 = FUN_2014d35c(param_1);
  if (iVar3 != *(char *)((int)piVar5 + 0x11)) {
    do {
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return 0xffffffef;
      }
      iVar3 = FUN_2014d35c(param_1);
    } while (iVar3 != *(char *)((int)piVar5 + 0x11));
  }
  cVar2 = (char)piVar5[4];
  if (cVar2 == '\f') {
    uVar6 = (uint)(piVar5[0x1b] * piVar5[3] * 2) / 3;
  }
  else if (cVar2 == '\x10') {
    uVar6 = ((uint)piVar5[0x1b] >> 1) * piVar5[3];
  }
  else {
    if (cVar2 != ' ') {
      return 0xfffffff3;
    }
    uVar6 = ((uint)piVar5[0x1b] >> 2) * piVar5[3];
  }
  iVar4 = piVar5[0x1b];
  iVar3 = FUN_20156260((uint)*(ushort *)((int)piVar5 + 10) << 5);
  uVar1 = *(ushort *)(piVar5 + 1);
  iVar3 = FUN_20156260(piVar5[5] -
                       (iVar3 + piVar5[3] * (uint)*(ushort *)(piVar5 + 2) +
                                (uint)*(ushort *)((int)piVar5 + 6)));
  if (iVar3 + 2U < uVar6) {
    uVar6 = iVar3 + 2U;
  }
  FUN_2014afcc((uint)uVar1 * (uVar6 - 2),param_2,param_3,iVar4);
  return 0;
}


// ===== FUN_2014b140 @ 2014b140 (156 bytes)

void FUN_2014b140(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 == 0) {
    if (param_2 == 0 || param_3 == 0) {
      uVar3 = 0xfffffff3;
    }
    else {
      uVar1 = FUN_2014d35c(param_1);
      iVar2 = FUN_20144918(uVar1,&local_18);
      if ((iVar2 != 0) || (iVar2 = FUN_20144950(local_18), iVar2 != 0)) goto LAB_2014b1b0;
      uVar3 = FUN_2014d35c(param_1);
      uVar3 = FUN_2014b020(uVar3,param_2,param_3);
    }
    FUN_20144800(uVar3,0);
    return;
  }
LAB_2014b1b0:
  FUN_20144800(iVar2,0);
  return;
}


// ===== FUN_2014b1e0 @ 2014b1e0 (436 bytes)

int FUN_2014b1e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int iStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar7 = 0;
  uVar3 = 0;
  uVar9 = 0;
  local_48 = 0;
  uVar6 = 0;
  local_44 = 0;
  uVar1 = *(ushort *)(param_1 + 4);
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  if ((param_5 != 0) && (*(int *)(param_1 + 0x3c) != -1)) {
    FUN_2014afcc(*(int *)(param_1 + 0x3c) * (uint)uVar1,param_2,param_3,*(uint *)(param_1 + 0x6c));
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  uVar8 = (*(uint *)(param_1 + 0x6c) >> 2) * iVar4;
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5);
  iVar2 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + iVar4 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),(uint)uVar1);
  uVar5 = 2;
  if (iVar2 + 2U < uVar8) {
    uVar8 = iVar2 + 2U;
  }
  local_40 = -1;
  if (2 < uVar8) {
    do {
      uVar11 = FUN_20156260(uVar5,*(uint *)(param_1 + 0x6c) >> 2);
      iVar2 = (int)uVar11;
      local_3c = (int)((ulonglong)uVar11 >> 0x20) << 2;
      if ((local_40 != iVar2) &&
         (iVar4 = FUN_2014919c(param_1,iVar2,&local_44,local_28), local_40 = iVar2, iVar4 != 0)) {
        return iVar4;
      }
      if (local_44 == 0) {
        return -0xd;
      }
      iVar2 = FUN_2014d93c(local_44 + local_3c);
      if (iVar2 == 0) {
        bVar10 = uVar3 == 0;
        uVar3 = uVar3 + 1;
        if (bVar10) {
          uVar6 = uVar5;
        }
        iVar7 = iVar7 + 1;
      }
      else {
        if (uVar9 < uVar3) {
          uVar9 = uVar3;
          local_48 = uVar6;
        }
        uVar3 = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar8);
    if (uVar3 < uVar9) {
      *(uint *)(param_1 + 0x40) = local_48;
      *(uint *)(param_1 + 0x28) = local_48;
      goto LAB_2014b36c;
    }
  }
  *(uint *)(param_1 + 0x40) = uVar6;
  *(uint *)(param_1 + 0x28) = uVar6;
LAB_2014b36c:
  *(int *)(param_1 + 0x3c) = iVar7;
  FUN_2014afcc((uint)*(ushort *)(param_1 + 4) * iVar7,local_30,local_2c,
               *(undefined4 *)(param_1 + 0x6c));
  return 0;
}


// ===== FUN_2014b394 @ 2014b394 (84 bytes)

undefined4
FUN_2014b394(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014b1e0(param_1,param_2,param_3,param_4,param_5);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014b3e8 @ 2014b3e8 (272 bytes)

int FUN_2014b3e8(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  int local_38;
  int iStack_34;
  undefined4 *local_30;
  int *local_2c;
  undefined4 local_28;
  
  iVar6 = 0;
  local_38 = 0;
  iVar3 = *(int *)(param_1 + 0xc);
  uVar5 = (*(uint *)(param_1 + 0x6c) >> 1) * iVar3;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  iVar1 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5);
  iVar3 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar1 + iVar3 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  uVar4 = 2;
  iVar1 = -1;
  if (iVar3 + 2U < uVar5) {
    uVar5 = iVar3 + 2U;
  }
  if (2 < uVar5) {
    do {
      uVar7 = FUN_20156260(uVar4,*(uint *)(param_1 + 0x6c) >> 1);
      iVar3 = (int)uVar7;
      if ((iVar1 != iVar3) &&
         (iVar2 = FUN_2014919c(param_1,iVar3,&local_38,local_28), iVar1 = iVar3, iVar2 != 0)) {
        return iVar2;
      }
      if (local_38 == 0) {
        return -0xd;
      }
      iVar3 = FUN_2014d900(local_38 + (int)((ulonglong)uVar7 >> 0x20) * 2);
      uVar4 = uVar4 + 1;
      if (iVar3 == 0) {
        iVar6 = iVar6 + 1;
      }
    } while (uVar4 < uVar5);
  }
  *local_30 = 0;
  *local_2c = (uint)*(ushort *)(param_1 + 4) * *(int *)(param_1 + 0x6c) * iVar6;
  return 0;
}


// ===== FUN_2014b500 @ 2014b500 (76 bytes)

undefined4 FUN_2014b500(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014b3e8(param_1,param_2,param_3,param_4);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014b54c @ 2014b54c (408 bytes)

int FUN_2014b54c(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  int iStack_34;
  undefined4 *local_30;
  int *local_2c;
  undefined4 local_28;
  
  iVar9 = 0;
  local_40 = 0;
  iVar5 = *(int *)(param_1 + 0xc);
  lVar1 = (ulonglong)(uint)(*(int *)(param_1 + 0x6c) * iVar5 * 2) * 0xaaaaaaab;
  uVar8 = ((uint)((ulonglong)lVar1 >> 0x20) & 0x1ffff) >> 1;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  iVar2 = FUN_20156260((uint)*(ushort *)(param_1 + 10) << 5,*(int *)(param_1 + 0x6c),(int)lVar1);
  iVar5 = FUN_20156260(*(int *)(param_1 + 0x14) -
                       (iVar2 + iVar5 * (uint)*(ushort *)(param_1 + 8) +
                                (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  uVar6 = 2;
  iVar2 = -1;
  if ((iVar5 + 2U & 0xffff) < uVar8) {
    uVar8 = iVar5 + 2U & 0xffff;
  }
  if (2 < uVar8) {
    do {
      iVar7 = *(int *)(param_1 + 0x6c);
      iVar5 = FUN_20156260(uVar6 * 3,iVar7 << 1);
      iVar7 = (uVar6 * 3 >> 1) - iVar7 * iVar5;
      if ((iVar2 != iVar5) &&
         (iVar3 = FUN_2014919c(param_1,iVar5,&local_40,local_28), iVar2 = iVar5, iVar3 != 0)) {
        return iVar3;
      }
      if (local_40 == 0) {
        return -0xd;
      }
      local_3c = *(undefined1 *)(local_40 + iVar7);
      if (*(int *)(param_1 + 0x6c) + -1 == iVar7) {
        iVar2 = iVar5 + 1;
        iVar7 = -1;
        iVar5 = FUN_2014919c(param_1,iVar2,&local_40,local_28);
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      local_3b = *(undefined1 *)(local_40 + iVar7 + 1);
      uVar4 = FUN_2014d900(&local_3c);
      if ((uVar6 & 1) != 0) {
        uVar4 = uVar4 >> 4;
      }
      uVar4 = uVar4 & 0xffff0fff;
      if (0xff6 < uVar4) {
        uVar4 = uVar4 | 0xf000;
      }
      if (uVar4 == 0) {
        iVar9 = iVar9 + 1;
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < uVar8);
  }
  *local_30 = 0;
  *local_2c = (uint)*(ushort *)(param_1 + 4) * *(int *)(param_1 + 0x6c) * iVar9;
  return 0;
}


// ===== FUN_2014b6e4 @ 2014b6e4 (76 bytes)

undefined4 FUN_2014b6e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014db6c();
  if (iVar1 == 0) {
    uVar2 = FUN_2014b54c(param_1,param_2,param_3,param_4);
    FUN_2014dc10(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== FUN_2014b730 @ 2014b730 (172 bytes)

void FUN_2014b730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int local_14;
  
  local_14 = DAT_20808ba0;
  uVar2 = FUN_2014d35c();
  iVar3 = FUN_20144918(uVar2,&local_14);
  if (iVar3 == 0) {
    cVar1 = *(char *)(local_14 + 0x10);
    if (cVar1 == '\f') {
      FUN_2014b6e4(local_14,param_2,param_3,param_4);
      return;
    }
    if (cVar1 == '\x10') {
      FUN_2014b500(local_14,param_2,param_3,param_4);
      return;
    }
    if (cVar1 == ' ') {
      FUN_2014b394(local_14,param_2,param_3,param_4,1);
    }
  }
  return;
}


// ===== FUN_2014b7dc @ 2014b7dc (164 bytes)

void FUN_2014b7dc(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 == 0) {
    if (param_2 == 0 || param_3 == 0) {
      uVar3 = 0xfffffff3;
    }
    else {
      uVar1 = FUN_2014d35c(param_1);
      iVar2 = FUN_20144918(uVar1,&local_18);
      if ((iVar2 != 0) || (iVar2 = FUN_20144950(local_18), iVar2 != 0)) goto LAB_2014b850;
      uVar3 = FUN_2014d35c(param_1);
      uVar3 = FUN_2014b730(uVar3,param_2,param_3,param_4);
    }
    FUN_20144800(uVar3,0);
    return;
  }
LAB_2014b850:
  FUN_20144800(iVar2,0);
  return;
}


// ===== FUN_2014b880 @ 2014b880 (84 bytes)

undefined4 FUN_2014b880(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_2014e118();
  if (iVar1 != 0) {
    uVar2 = FUN_2014b7dc(param_1,param_2,param_3,iVar1);
    FUN_2014e14c(iVar1);
    return uVar2;
  }
  uVar2 = FUN_20144800(0xffffffe1,0);
  return uVar2;
}


// ===== FUN_2014b8d4 @ 2014b8d4 (104 bytes)

void FUN_2014b8d4(int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,int param_5)

{
  FUN_2014d148(param_1,0,0x20,*(undefined4 *)(param_5 + 0x6c));
  FUN_2014d128(param_1,param_2,0xb);
  *(undefined1 *)(param_1 + 0xb) = param_3;
  FUN_201474a4(param_1,0,7);
  FUN_20147588(param_1,param_4,(int)*(char *)(param_5 + 0x10));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


// ===== FUN_2014b93c @ 2014b93c (300 bytes)

int FUN_2014b93c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_48 [32];
  undefined1 local_28;
  undefined1 local_27;
  
  iVar1 = FUN_20144980();
  iVar4 = param_4 + 0xc0c;
  FUN_2014d148(iVar4,0,0x200);
  FUN_2014d148(&local_28,0x20,0xb,*(undefined4 *)(param_1 + 0x6c));
  local_28 = 0x2e;
  FUN_2014b8d4(auStack_48,&local_28,0x10,param_2,param_1);
  FUN_2014d1c4(iVar4,auStack_48,0x20);
  local_27 = 0x2e;
  FUN_2014b8d4(auStack_48,&local_28,0x10,param_3,param_1);
  FUN_2014d1c4(param_4 + 0xc2c,auStack_48,0x20);
  iVar2 = FUN_20144ac0(param_1,iVar1,iVar4,1);
  if (iVar2 == 0) {
    FUN_2014d148(iVar4,0,0x200);
    uVar3 = 1;
    if (1 < *(ushort *)(param_1 + 4)) {
      do {
        iVar2 = FUN_20144ac0(param_1,iVar1 + uVar3,iVar4,1);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < *(ushort *)(param_1 + 4));
    }
    iVar2 = 0;
  }
  return iVar2;
}

