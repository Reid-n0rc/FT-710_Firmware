// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0020e0c8 @ 0020e0c8 (119 bytes)

undefined4 FUN_0020e0c8(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  memw();
  iVar2 = *param_2;
  FUN_0020d4e0(param_1,&DAT_00008100);
  uVar1 = 0;
  memw();
  if (*(char *)(iVar2 + 0x28) != '\0') {
    uVar1 = 0xa28;
  }
  memw();
  *(undefined4 *)(iVar2 + 0x14) = 0;
  memw();
  *(undefined4 *)(iVar2 + 0x18) = 0;
  memw();
  *(undefined4 *)(iVar2 + 0x10) = param_3;
  memw();
  *(undefined4 *)(iVar2 + 0x1c) = param_4;
  memw();
  *(undefined4 *)(iVar2 + 0x20) = 0;
  memw();
  *(uint *)(iVar2 + 0xc) = param_5 | 6;
  memw();
  *(undefined1 *)(iVar2 + 0x28) = 1;
  memw();
  *(undefined4 *)(param_1 + 0x800) = 2;
  memw();
  memw();
  *(undefined4 *)(param_1 + 0x804) = *(undefined4 *)(param_1 + 0x804);
  FUN_0020d4d0(param_1,&DAT_00008100);
  return uVar1;
}


// ===== FUN_0020e140 @ 0020e140 (29 bytes)

void FUN_0020e140(int param_1,int param_2,uint param_3,uint param_4)

{
  memw();
  *(uint *)(param_2 * 4 + param_1 + 0x848) = param_4 | (param_3 & 0x7f) << 1;
  return;
}


// ===== FUN_0020e160 @ 0020e160 (44 bytes)

void FUN_0020e160(undefined4 param_1)

{
  undefined1 auStack_40 [3];
  undefined1 uStack_3d;
  undefined1 uStack_3b;
  undefined1 uStack_39;
  undefined1 uStack_2c;
  
  memcpy(auStack_40,&DAT_00200340,0x18);
  uStack_2c = 1;
  uStack_3d = 1;
  uStack_3b = 1;
  uStack_39 = 1;
  memcpy(param_1,auStack_40,0x18);
  return;
}


// ===== FUN_0020e18c @ 0020e18c (185 bytes)

undefined4 FUN_0020e18c(int param_1,undefined1 *param_2,uint param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  if (((*(uint *)(param_2 + 0x10) & 0xff) < 4) &&
     (*(int *)(&DAT_00200360 + (*(uint *)(param_2 + 0x10) & 0xff) * 4) != 0)) {
    puVar1 = (undefined *)
             ((*(int *)(&DAT_00200360 + (*(uint *)(param_2 + 0x10) & 0xff) * 4) * (param_3 / 1000))
             / (uint)&DAT_000f4240);
    puVar2 = &DAT_0000ffff;
    if (puVar1 < &DAT_0000ffff) {
      puVar2 = puVar1;
    }
    FUN_0020b7b0(param_1,3);
    memw();
    *(undefined **)(param_1 + 0x814) = puVar2;
    FUN_0020e140(param_1,0,*param_2,param_2[1]);
    FUN_0020e140(param_1,1,param_2[2],param_2[3]);
    FUN_0020e140(param_1,2,param_2[4],param_2[5]);
    FUN_0020e140(param_1,3,param_2[6],param_2[7]);
    memw();
    *(uint *)(param_1 + 0x858) = *(uint *)(param_2 + 8) & 1 | ((byte)param_2[0xc] & 0x7f) << 1;
    memw();
    *(uint *)(param_1 + 0x800) = ((byte)param_2[0x14] & 1) << 1;
    return 0;
  }
  return 4;
}


// ===== FUN_0020e248 @ 0020e248 (16 bytes)

void FUN_0020e248(int param_1)

{
  memw();
  *(undefined4 *)(param_1 + 0x800) = 0;
  return;
}


// ===== FUN_0020e258 @ 0020e258 (192 bytes)

undefined4 FUN_0020e258(int param_1,byte *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  *(undefined4 *)(param_1 + 0x800) = 2;
  do {
    memw();
    uVar1 = *(uint *)(param_1 + 0x804);
  } while ((uVar1 & 0x100) == 0);
  if (uVar1 == 0xa32) {
    return 0xa32;
  }
  uVar2 = uVar1 >> 9 & 3;
  if (uVar2 == 0) {
    memw();
    *(undefined4 *)(param_1 + 0x840) = 1;
    do {
      memw();
      uVar1 = *(uint *)(param_1 + 0x804);
    } while ((uVar1 & 0x100) == 0);
    if (uVar1 == 0xa32) {
      return 0xa32;
    }
  }
  else if (uVar2 != 2) {
    memw();
    *(undefined4 *)(param_1 + 0x800) = 0;
    return 1;
  }
  do {
    if (param_3 == 0) {
      return 0;
    }
    if ((uVar1 >> 9 & 3) != 2) {
      memw();
      *(undefined4 *)(param_1 + 0x800) = 0;
      return 1;
    }
    memw();
    *(uint *)(param_1 + 0x844) = (uint)*param_2;
    memw();
    *(undefined4 *)(param_1 + 0x840) = 1;
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
    if (param_3 == 0) {
      return 0;
    }
    do {
      memw();
      uVar1 = *(uint *)(param_1 + 0x804);
    } while ((uVar1 & 0x100) == 0);
  } while (uVar1 != 0xa32);
  return 0xa32;
}


// ===== FUN_0020e31c @ 0020e31c (192 bytes)

undefined4 FUN_0020e31c(int param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  *(undefined4 *)(param_1 + 0x800) = 2;
  do {
    memw();
    uVar1 = *(uint *)(param_1 + 0x804);
  } while ((uVar1 & 0x100) == 0);
  if (uVar1 == 0xa32) {
    return 0xa32;
  }
  uVar2 = uVar1 >> 9 & 3;
  if (uVar2 == 0) {
    memw();
    *(undefined4 *)(param_1 + 0x840) = 1;
    do {
      memw();
      uVar1 = *(uint *)(param_1 + 0x804);
    } while ((uVar1 & 0x100) == 0);
    if (uVar1 == 0xa32) {
      return 0xa32;
    }
  }
  else if (uVar2 != 1) {
    memw();
    *(undefined4 *)(param_1 + 0x800) = 0;
    return 1;
  }
  do {
    if (param_3 == 0) {
      return 0;
    }
    if ((uVar1 >> 9 & 3) != 1) {
      memw();
      *(undefined4 *)(param_1 + 0x800) = 0;
      return 1;
    }
    memw();
    *param_2 = (char)*(undefined4 *)(param_1 + 0x844);
    memw();
    *(undefined4 *)(param_1 + 0x840) = 1;
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
    if (param_3 == 0) {
      return 0;
    }
    do {
      memw();
      uVar1 = *(uint *)(param_1 + 0x804);
    } while ((uVar1 & 0x100) == 0);
  } while (uVar1 != 0xa32);
  return 0xa32;
}


// ===== FUN_0020e3e0 @ 0020e3e0 (59 bytes)

void FUN_0020e3e0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  memset(param_2,0,0x38);
  FUN_0020d4f0(param_1);
  *(undefined4 *)(param_2 + 0x34) = param_4;
  *(undefined4 *)(param_2 + 0x30) = param_3;
  memw();
  *(undefined4 *)(param_2 + 0x2c) = 0;
  memw();
  *(int *)param_2 = param_2;
  FUN_0020b8e4(param_1,FUN_0020e4e8,param_2);
  FUN_0020d4e0(param_1,&DAT_00008100);
  return;
}


// ===== FUN_0020e41c @ 0020e41c (114 bytes)

undefined4 FUN_0020e41c(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  FUN_0020d4e0(param_1,&DAT_00008100);
  uVar1 = 0;
  memw();
  if (*(char *)(param_2 + 0x28) != '\0') {
    uVar1 = 0xa28;
  }
  memw();
  *(undefined4 *)(param_2 + 0x14) = 0;
  memw();
  *(undefined4 *)(param_2 + 0x18) = 0;
  memw();
  *(undefined4 *)(param_2 + 0x10) = 0;
  memw();
  *(undefined4 *)(param_2 + 0x1c) = 0;
  memw();
  *(undefined4 *)(param_2 + 0x20) = 0;
  memw();
  *(uint *)(param_2 + 0xc) = param_3 | 6;
  memw();
  *(undefined1 *)(param_2 + 0x28) = 1;
  memw();
  *(undefined4 *)(param_1 + 0x800) = 2;
  memw();
  memw();
  *(undefined4 *)(param_1 + 0x804) = *(undefined4 *)(param_1 + 0x804);
  FUN_0020d4d0(param_1,&DAT_00008100);
  return uVar1;
}


// ===== FUN_0020e490 @ 0020e490 (42 bytes)

undefined4 FUN_0020e490(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 4;
  }
  memw();
  if (*(char *)(param_2 + 0x28) != '\0') {
    memw();
    *param_3 = *(undefined4 *)(param_2 + 0x20);
    return 0;
  }
  *param_3 = 0;
  return 6;
}


// ===== FUN_0020e4bc @ 0020e4bc (41 bytes)

void FUN_0020e4bc(int param_1,int param_2)

{
  FUN_0020d4e0(param_1,&DAT_00008100);
  memw();
  *(undefined4 *)(param_1 + 0x800) = 0;
  memw();
  *(undefined1 *)(param_2 + 0x28) = 0;
  memw();
  *(undefined4 *)(param_2 + 0x18) = 0;
  memw();
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return;
}


// ===== FUN_0020e4e8 @ 0020e4e8 (555 bytes)

void FUN_0020e4e8(int param_1,int param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x804);
  if ((uVar1 >> 0xf & 1) != 0) {
    FUN_0020dfe8(param_1,param_2,0x40);
    memw();
    *(undefined **)(param_1 + 0x804) = &DAT_00008000;
  }
  if ((uVar1 >> 8 & 1) == 0) {
    return;
  }
  uVar1 = uVar1 >> 9 & 3;
  if (uVar1 != 0) {
    memw();
    if (*(int *)(param_2 + 0x2c) == 2) {
      if (uVar1 != 1) {
        memw();
        *(undefined4 *)(param_1 + 0x840) = 2;
        return;
      }
      memw();
      memw();
      if ((*(int *)(param_2 + 0x10) == 0) || (*(int *)(param_2 + 0x1c) == 0)) {
        FUN_0020dfe8(param_1,param_2,4);
      }
      memw();
      memw();
      if ((*(int *)(param_2 + 0x10) != 0) && (*(int *)(param_2 + 0x1c) != 0)) {
        memw();
        *(undefined4 *)(param_1 + 0x840) = 1;
        memw();
        memw();
        **(undefined1 **)(param_2 + 0x10) = (char)*(undefined4 *)(param_1 + 0x844);
        memw();
        memw();
        *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + -1;
        memw();
        memw();
        *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
        memw();
        memw();
        *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
      }
      memw();
      memw();
      if (*(int *)(param_2 + 0x1c) != 0) {
        return;
      }
      if (*(int *)(param_2 + 0x18) != 0) {
        return;
      }
      memw();
      *(undefined1 *)(param_2 + 0x28) = 0;
      FUN_0020dfe8(param_1,param_2,0x20);
      return;
    }
    if (*(int *)(param_2 + 0x2c) != 3) {
      return;
    }
    if (uVar1 == 2) {
      memw();
      memw();
      if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(param_2 + 0x18) == 0)) {
        FUN_0020dfe8(param_1,param_2,2);
      }
      memw();
      memw();
      if ((*(int *)(param_2 + 0x14) != 0) && (*(int *)(param_2 + 0x18) != 0)) {
        memw();
        memw();
        *(uint *)(param_1 + 0x844) = (uint)**(byte **)(param_2 + 0x14);
        memw();
        *(undefined4 *)(param_1 + 0x840) = 1;
        memw();
        memw();
        *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
        memw();
        memw();
        *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
        memw();
        memw();
        *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
      }
      memw();
      memw();
      if (*(int *)(param_2 + 0x1c) != 0) {
        return;
      }
      if (*(int *)(param_2 + 0x18) != 0) {
        return;
      }
      memw();
      *(undefined1 *)(param_2 + 0x28) = 0;
      FUN_0020dfe8(param_1,param_2,0x20);
      return;
    }
    memw();
    *(undefined4 *)(param_1 + 0x840) = 2;
    return;
  }
  memw();
  uVar1 = *(uint *)(param_1 + 0x844);
  memw();
  *(char *)(param_2 + 8) = (char)uVar1;
  if ((uVar1 & 1) == 0) {
    memw();
    memw();
    if ((*(int *)(param_2 + 0x10) == 0) || (*(int *)(param_2 + 0x1c) == 0)) {
      FUN_0020dfe8(param_1,param_2,4);
    }
    memw();
    memw();
    if ((*(int *)(param_2 + 0x10) == 0) || (*(int *)(param_2 + 0x1c) == 0)) {
      memw();
      *(undefined4 *)(param_1 + 0x840) = 2;
      goto LAB_0020e6a0;
    }
    memw();
    *(undefined4 *)(param_2 + 0x2c) = 2;
  }
  else {
    memw();
    memw();
    if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(param_2 + 0x18) == 0)) {
      FUN_0020dfe8(param_1,param_2,2);
    }
    memw();
    memw();
    if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(param_2 + 0x18) == 0)) {
      memw();
      *(undefined4 *)(param_1 + 0x840) = 2;
      goto LAB_0020e6a0;
    }
    memw();
    *(undefined4 *)(param_2 + 0x2c) = 3;
  }
  memw();
  *(undefined4 *)(param_1 + 0x840) = 1;
LAB_0020e6a0:
  FUN_0020dfe8(param_1,param_2,1);
  return;
}


// ===== FUN_0020e720 @ 0020e720 (13 bytes)

void FUN_0020e720(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x808) = param_2;
  return;
}


// ===== FUN_0020e730 @ 0020e730 (13 bytes)

void FUN_0020e730(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x80c) = param_2;
  return;
}


// ===== FUN_0020e740 @ 0020e740 (137 bytes)

void FUN_0020e740(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_40 [64];
  
  iVar2 = *(int *)(param_2 + 0xc);
  uVar1 = *(uint *)(param_2 + 8);
  *(int *)(param_2 + 4) = iVar2 - *(int *)(param_2 + 0x34);
  uVar3 = 0x400;
  if (uVar1 < 0x400) {
    uVar3 = uVar1;
  }
  if (uVar1 != 0) {
    if (*(int *)(param_2 + 0x28) == 0) {
      FUN_0020ab34(auStack_40,iVar2,param_1 + 0x828,1,uVar3,2,0);
    }
    else if (*(int *)(param_2 + 0x28) == 1) {
      FUN_0020ab34(auStack_40,param_1 + 0x828,iVar2,1,uVar3,1,0);
    }
    FUN_0020ae18(*(undefined4 *)(param_2 + 0x1c),auStack_40);
    FUN_0020aed8(*(undefined4 *)(param_2 + 0x1c));
    *(undefined1 *)(param_2 + 0x18) = 0;
    *(uint *)(param_2 + 8) = *(int *)(param_2 + 8) - uVar3;
    *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + uVar3;
    return;
  }
  memw();
  *(undefined4 *)(param_1 + 0x820) = 0;
  return;
}


// ===== FUN_0020e7d0 @ 0020e7d0 (782 bytes)

void FUN_0020e7d0(int param_1,char *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_40 [64];
  
  if (param_2 == (char *)0x0) {
    return;
  }
  uVar1 = FUN_0020d5a0(param_1);
  if ((uVar1 >> 4 & 1) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x10;
    FUN_0020aa20(*(undefined4 *)(param_2 + 0x1c));
    memw();
    *(undefined4 *)(param_1 + 0x820) = 0;
    uVar2 = 0xa2d;
    goto LAB_0020e80d;
  }
  if ((uVar1 >> 6 & 1) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x40;
    FUN_0020aa20(*(undefined4 *)(param_2 + 0x1c));
    memw();
    *(undefined4 *)(param_1 + 0x820) = 0;
    uVar2 = 0xa30;
    goto LAB_0020e80d;
  }
  if ((uVar1 >> 0x18 & 1) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x1000000;
    FUN_0020aa20(*(undefined4 *)(param_2 + 0x1c));
    memw();
    *(undefined4 *)(param_1 + 0x820) = 0;
    uVar2 = 0xa34;
    goto LAB_0020e80d;
  }
  if ((uVar1 >> 0x19 & 1) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x2000000;
    FUN_0020aa20(*(undefined4 *)(param_2 + 0x1c));
    memw();
    *(undefined4 *)(param_1 + 0x820) = 0;
    uVar2 = 0xa35;
    goto LAB_0020e80d;
  }
  if ((uVar1 & 1) == 0) {
    uVar2 = 0xa28;
    goto LAB_0020e80d;
  }
  memw();
  uVar1 = (*(uint *)(param_1 + 0x804) & 0xe) >> 1;
  if ((uVar1 == 3) || (uVar1 == 4)) {
    FUN_0020aa20(*(undefined4 *)(param_2 + 0x1c));
    memw();
    *(undefined4 *)(param_1 + 0x820) = 4;
    *param_2 = '\b';
    if ((uVar1 == 3) || (param_2[0x18] != '\0')) {
      uVar2 = 0xa33;
    }
    else {
      uVar2 = 0xa2a;
    }
    goto LAB_0020e80d;
  }
  cVar3 = *param_2;
  if (cVar3 == '\x06') {
    iVar5 = *(int *)(param_2 + 0x10);
    if (iVar5 == 0) {
      if (*(int *)(param_2 + 0x28) == 0) {
        memw();
        iVar4 = *(int *)(param_2 + 0x38);
        *(uint *)(param_1 + 0x828) = (uint)(byte)param_2[0x24] << 1;
        if (iVar4 == 0) {
          memw();
          *(undefined4 *)(param_1 + 0x820) = 2;
          *param_2 = '\a';
          return;
        }
        *param_2 = '\x02';
        cVar3 = '\x02';
      }
      else {
        if ((*(int *)(param_2 + 0x28) != 1) || (iVar4 = *(int *)(param_2 + 0x38), iVar4 == 0)) {
          *param_2 = '\0';
          uVar2 = 0xa31;
          goto LAB_0020e80d;
        }
        memw();
        *(uint *)(param_1 + 0x828) = (uint)(byte)param_2[0x24] * 2 + 1;
        if (iVar4 == 1) {
          memw();
          *(undefined4 *)(param_1 + 0x820) = 2;
          *param_2 = '\x05';
          return;
        }
        *param_2 = '\x04';
        cVar3 = '\x04';
      }
    }
    else {
      memw();
      *(uint *)(param_1 + 0x828) = (uint)(byte)param_2[0x24] << 1;
      *param_2 = '\x01';
      cVar3 = '\x01';
    }
    if (cVar3 == '\x01') {
      uVar1 = 2;
LAB_0020e95c:
      memw();
      *(uint *)(param_1 + 0x820) = uVar1 | 8;
      FUN_0020ab34(auStack_40,param_2 + 0x14,param_1 + 0x828,1,iVar5,2,0);
      FUN_0020ae18(*(undefined4 *)(param_2 + 0x1c),auStack_40);
      FUN_0020aed8(*(undefined4 *)(param_2 + 0x1c));
      cVar3 = '\x02';
      param_2[0x10] = '\0';
      param_2[0x11] = '\0';
      param_2[0x12] = '\0';
      param_2[0x13] = '\0';
      if (*(int *)(param_2 + 0x38) == 0) {
        *param_2 = '\a';
        return;
      }
      if (*(int *)(param_2 + 0x28) == 1) {
        cVar3 = '\x06';
      }
      *param_2 = cVar3;
      return;
    }
    if (cVar3 == '\x02') {
      uVar1 = 2;
LAB_0020e9b0:
      memw();
      *(uint *)(param_1 + 0x820) = uVar1 | 8;
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 0x38);
      FUN_0020e740(param_1,param_2);
      param_2[0x18] = '\0';
      *param_2 = '\a';
      return;
    }
    if (cVar3 == '\x04') {
      uVar6 = *(uint *)(param_2 + 0x20);
      uVar1 = 2;
LAB_0020e9e2:
      memw();
      iVar5 = *(int *)(param_2 + 0x38);
      *(uint *)(param_1 + 0x820) = uVar1 | 8;
      *(int *)(param_2 + 8) = iVar5 + -1;
      if ((uVar6 & 1) != 0) {
        memw();
      }
      FUN_0020e740(param_1,param_2);
      *param_2 = '\x05';
      param_2[0x18] = '\0';
      return;
    }
LAB_0020e871:
    if (cVar3 != '\x05') {
      if (cVar3 == '\a') {
        if ((*(uint *)(param_2 + 0x20) >> 2 & 1) == 0) {
          memw();
          *(undefined4 *)(param_1 + 0x820) = 4;
          *param_2 = '\b';
          return;
        }
      }
      else if (cVar3 != '\b') goto LAB_0020e883;
      *param_2 = '\0';
      uVar2 = 0;
      goto LAB_0020e80d;
    }
    if (uVar1 == 1) {
      memw();
      *(char *)(*(int *)(param_2 + 0x34) + *(int *)(param_2 + 0x38) + -1) =
           (char)*(undefined4 *)(param_1 + 0x828);
      *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
      if ((*(uint *)(param_2 + 0x20) & 4) == 0) {
        memw();
        *(undefined4 *)(param_1 + 0x820) = 4;
        *param_2 = '\b';
        return;
      }
      *param_2 = '\b';
      return;
    }
  }
  else if (cVar3 == '\x01') {
    if (uVar1 == 2) {
      iVar5 = *(int *)(param_2 + 0x10);
      uVar1 = 0;
      goto LAB_0020e95c;
    }
  }
  else if (cVar3 == '\x02') {
    if (uVar1 == 2) {
      uVar1 = 0;
      goto LAB_0020e9b0;
    }
  }
  else {
    if (cVar3 != '\x04') goto LAB_0020e871;
    uVar6 = *(uint *)(param_2 + 0x20);
    if ((uVar1 == 1) || ((uVar6 & 1) != 0)) {
      uVar1 = 0;
      goto LAB_0020e9e2;
    }
  }
LAB_0020e883:
  uVar2 = 0xa31;
LAB_0020e80d:
  *param_2 = '\0';
  FUN_0020e730(param_1,0x1000051);
  if (*(code **)(param_2 + 0x3c) == (code *)0x0) {
    return;
  }
  (**(code **)(param_2 + 0x3c))(param_1,param_2,uVar2,*(undefined4 *)(param_2 + 0x40));
  return;
}


// ===== FUN_0020eaec @ 0020eaec (148 bytes)

void FUN_0020eaec(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_40 [64];
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = param_2[1];
  iVar3 = *(int *)(iVar1 + 0xc);
  uVar2 = *(uint *)(iVar1 + 8);
  iVar4 = *param_2;
  *(int *)(iVar1 + 4) = iVar3 - *(int *)(iVar1 + 0x34);
  uVar5 = 0x400;
  if (uVar2 < 0x400) {
    uVar5 = uVar2;
  }
  if (uVar2 != 0) {
    if (*(int *)(iVar1 + 0x28) == 0) {
      FUN_0020ab34(auStack_40,iVar3,iVar4 + 0x828,1,uVar5,2,0);
    }
    else if (*(int *)(iVar1 + 0x28) == 1) {
      FUN_0020ab34(auStack_40,iVar4 + 0x828,iVar3,1,uVar5,1,0);
    }
    FUN_0020ae18(*(undefined4 *)(iVar1 + 0x1c),auStack_40);
    FUN_0020aed8(*(undefined4 *)(iVar1 + 0x1c));
    *(undefined1 *)(iVar1 + 0x18) = 0;
    *(uint *)(iVar1 + 8) = *(int *)(iVar1 + 8) - uVar5;
    *(uint *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + uVar5;
    return;
  }
  memw();
  *(undefined4 *)(iVar4 + 0x820) = 0;
  return;
}


// ===== FUN_0020eb84 @ 0020eb84 (74 bytes)

void FUN_0020eb84(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  memset(param_2,0,0x44);
  iVar1 = FUN_0020d4f0(param_1);
  *(undefined4 *)(param_2 + 0x40) = param_4;
  *(undefined4 *)(param_2 + 0x3c) = param_3;
  FUN_0020b8e4(param_1,FUN_0020e7d0,param_2);
  FUN_0020e730(param_1,0x1000051);
  *(undefined4 *)(param_2 + 0x1c) = param_5;
  *(undefined4 *)(&DAT_00238c10 + iVar1 * 8) = param_1;
  *(int *)(&DAT_00238c14 + iVar1 * 8) = param_2;
  FUN_0020ab28(param_5,FUN_0020eaec);
  return;
}


// ===== FUN_0020ebd0 @ 0020ebd0 (250 bytes)

undefined4 FUN_0020ebd0(int param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  
  if (*param_2 != '\0') {
    return 0xa28;
  }
  memcpy(param_2 + 0x20,param_3,0x1c);
  param_2[4] = '\0';
  param_2[5] = '\0';
  param_2[6] = '\0';
  param_2[7] = '\0';
  param_2[8] = '\0';
  param_2[9] = '\0';
  param_2[10] = '\0';
  param_2[0xb] = '\0';
  param_2[0x10] = '\0';
  param_2[0x11] = '\0';
  param_2[0x12] = '\0';
  param_2[0x13] = '\0';
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_2 + 0x34);
  if ((*(uint *)(param_2 + 0x20) & 1) == 0) {
    uVar2 = *(uint *)(param_2 + 0x30);
    if (uVar2 != 0) {
      if (4 < uVar2) {
LAB_0020ec17:
        uVar1 = 0xa2b;
        goto LAB_0020ec90;
      }
      uVar5 = *(uint *)(param_3 + 0x10);
      uVar6 = *(uint *)(param_3 + 0xc);
      if (-1 < (int)(uVar5 - 1)) {
        pcVar3 = param_2 + (uVar5 - 1);
        if ((uVar5 & 7) != 0) {
          pcVar3[0x14] = (char)uVar6;
          pcVar3 = pcVar3 + -1;
          uVar6 = uVar6 >> 8;
        }
        if (0 < (int)uVar5 >> 3) {
          pcVar3[0x14] = (char)uVar6;
          pcVar3[0x13] = (char)(uVar6 >> 8);
          pcVar3[0x12] = (char)(uVar6 >> 0x10);
          pcVar3[0x11] = (char)(uVar6 >> 0x18);
          pcVar3[0x10] = '\0';
          pcVar3[0xf] = '\0';
          pcVar3[0xe] = '\0';
          pcVar3[0xd] = '\0';
        }
        uVar2 = *(uint *)(param_2 + 0x30);
      }
      *(uint *)(param_2 + 0x10) = uVar2;
    }
    param_2[0x18] = '\x01';
    *param_2 = '\x06';
  }
  else {
    param_2[0x18] = '\0';
    if (*(int *)(param_2 + 0x38) == 0) {
      *param_2 = '\a';
    }
    else if (*(int *)(param_2 + 0x28) == 0) {
      *param_2 = '\x02';
    }
    else {
      if (*(int *)(param_2 + 0x28) != 1) goto LAB_0020ec17;
      cVar4 = '\x04';
      if (*(int *)(param_3 + 0x18) == 1) {
        cVar4 = '\x05';
      }
      *param_2 = cVar4;
    }
  }
  uVar1 = 0;
LAB_0020ec90:
  memw();
  *(undefined4 *)(param_1 + 0x804) = 0x50;
  FUN_0020e720(param_1,0x1000051);
  return uVar1;
}


// ===== FUN_0020eccc @ 0020eccc (34 bytes)

undefined4 FUN_0020eccc(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 4;
  }
  if (*param_2 != '\0') {
    *param_3 = *(undefined4 *)(param_2 + 4);
    return 0;
  }
  *param_3 = 0;
  return 6;
}


// ===== FUN_0020ecf0 @ 0020ecf0 (113 bytes)

void FUN_0020ecf0(int param_1,char *param_2)

{
  uint uVar1;
  
  if (*param_2 == '\0') {
    return;
  }
  FUN_0020aa20(*(undefined4 *)(param_2 + 0x1c));
  memw();
  *(undefined4 *)(param_1 + 0x820) = 0;
  FUN_0020e730(param_1,0x1000051);
  do {
    uVar1 = FUN_0020d5a0(param_1);
  } while ((uVar1 & 1) == 0);
  memw();
  *(undefined4 *)(param_1 + 0x804) = 0x50;
  memw();
  if ((*(uint *)(param_1 + 0x804) & 0xe) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x820) = 4;
    do {
      uVar1 = FUN_0020d5a0(param_1);
    } while ((uVar1 & 1) == 0);
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x50;
    *param_2 = '\0';
    return;
  }
  *param_2 = '\0';
  return;
}


// ===== FUN_0020ed70 @ 0020ed70 (13 bytes)

void FUN_0020ed70(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0xe10) = param_2;
  return;
}


// ===== FUN_0020ed80 @ 0020ed80 (13 bytes)

void FUN_0020ed80(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0xe14) = param_2;
  return;
}


// ===== FUN_0020ed90 @ 0020ed90 (28 bytes)

void FUN_0020ed90(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  memw();
  *(uint *)(param_1 + 0xc1c) = ((param_2 / param_3) / param_4) / param_5 - 1 & 0xfff;
  return;
}


// ===== I2S_TxInit @ 0020edac (285 bytes)

void I2S_TxInit(dword *param_1,uint *param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_0020b7b0(param_1,4);
  uVar4 = ((byte)param_2[2] & 1) << 8 | (*(byte *)((int)param_2 + 9) & 1) << 9 |
          (*param_2 & 3) << 4 | (param_2[1] & 3) << 6;
  if (param_1 == &USART0_CFG) {
    uVar4 = uVar4 | (*(byte *)((int)param_2 + 10) & 1) << 0xb;
  }
  uVar2 = *(ushort *)((int)param_2 + 0x12);
  uVar3 = param_2[5];
  memw();
  param_1[0x300] =
       uVar4 | (*(byte *)((int)param_2 + 0xb) & 1) << 0xc | ((byte)param_2[3] & 1) << 0xd |
       ((byte)param_2[4] & 1) << 10 |
       (*(byte *)((int)param_2 + 0x11) - 1) * 0x10000 & (uint)&DAT_001f0000;
  memw();
  param_1[0x301] = uVar2 - 1 & 0x7ff | ((ushort)uVar3 & 0x7ff) << 0x10;
  memw();
  bVar1 = *(byte *)((int)param_2 + 0x16);
  uVar4 = param_2[6];
  param_1[0x307] = *(ushort *)((int)param_2 + 0xe) - 1 & 0xfff;
  memw();
  param_1[0x380] =
       (*(byte *)((int)param_2 + 0x17) & 1) << 2 | ((byte)uVar4 & 1) << 3 | (uint)&DAT_00010001;
  memw();
  param_1[0x382] = (bVar1 & 0xf) << 8 | 1;
  return;
}


// ===== I2S_RxInit @ 0020eecc (272 bytes)

void I2S_RxInit(dword *param_1,uint *param_2)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_0020b7b0(param_1,5);
  uVar4 = ((byte)param_2[2] & 1) << 8 | (*(byte *)((int)param_2 + 9) & 1) << 9 |
          (*param_2 & 3) << 4 | (param_2[1] & 3) << 6;
  if (param_1 == &USART0_CFG) {
    uVar4 = uVar4 | (*(byte *)((int)param_2 + 10) & 1) << 0xb;
  }
  uVar1 = *(ushort *)((int)param_2 + 0x12);
  uVar3 = param_2[5];
  memw();
  param_1[0x300] =
       uVar4 | (*(byte *)((int)param_2 + 0xb) & 1) << 0xc | ((byte)param_2[3] & 1) << 0xd |
       ((byte)param_2[4] & 1) << 10 |
       (*(byte *)((int)param_2 + 0x11) - 1) * 0x10000 & (uint)&DAT_001f0000;
  memw();
  param_1[0x301] = uVar1 - 1 & 0x7ff | ((ushort)uVar3 & 0x7ff) << 0x10;
  memw();
  bVar2 = *(byte *)((int)param_2 + 0x16);
  param_1[0x307] = *(ushort *)((int)param_2 + 0xe) - 1 & 0xfff;
  memw();
  param_1[0x380] = ((byte)param_2[6] & 1) << 3 | (uint)&DAT_00020002;
  memw();
  param_1[0x382] = (bVar2 & 0xf) << 0x10 | 2;
  return;
}


// ===== I2S_TxGetDefaultConfig @ 0020efdc (67 bytes)

void I2S_TxGetDefaultConfig(undefined4 *param_1)

{
  *(undefined2 *)((int)param_1 + 0xe) = 1;
  *(undefined1 *)((int)param_1 + 0x17) = 1;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *param_1 = 3;
  *(undefined1 *)((int)param_1 + 0x16) = 4;
  *(undefined2 *)((int)param_1 + 0x12) = 0x20;
  *(undefined1 *)((int)param_1 + 0x11) = 0x10;
  return;
}


// ===== I2S_RxGetDefaultConfig @ 0020f020 (64 bytes)

void I2S_RxGetDefaultConfig(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined2 *)((int)param_1 + 0xe) = 1;
  *(undefined1 *)((int)param_1 + 0x11) = 0x10;
  *(undefined1 *)((int)param_1 + 0x16) = 4;
  *(undefined2 *)((int)param_1 + 0x12) = 0x20;
  return;
}


// ===== FUN_0020f060 @ 0020f060 (5 bytes)

void FUN_0020f060(void)

{
  return;
}


// ===== FUN_0020f068 @ 0020f068 (82 bytes)

void FUN_0020f068(int param_1,int param_2,uint param_3,uint param_4)

{
  param_1 = param_1 + param_2 * 0x20;
  memw();
  memw();
  memw();
  *(uint *)(param_1 + 0xc20) = *(uint *)(param_1 + 0xc20) & 0xfffffbff | (param_3 & 1) << 10 | 1;
  memw();
  *(uint *)(param_1 + 0xc24) = *(uint *)(param_1 + 0xc24) & 0xf800ffff | (param_4 & 0x7ff) << 0x10;
  return;
}


// ===== FUN_0020f0bc @ 0020f0bc (152 bytes)

void FUN_0020f0bc(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  
  memset(param_2,0,0x40);
  *(undefined4 *)(param_2 + 8) = param_4;
  *(undefined4 *)(param_2 + 4) = param_3;
  memw();
  *(byte *)(param_2 + 0xf) = (byte)((uint)*(undefined4 *)(param_1 + 0xe08) >> 8) & 0xf;
  memw();
  uVar2 = (*(uint *)(param_1 + 0xc00) & 0x400) >> 10;
  uVar1 = (undefined1)uVar2;
  if (uVar2 != 0) {
    uVar1 = 1;
  }
  *(undefined1 *)(param_2 + 0xc) = uVar1;
  memw();
  *(byte *)(param_2 + 0xd) = ((byte)((uint)*(undefined4 *)(param_1 + 0xc00) >> 0x10) & 0x1f) + 1;
  memw();
  uVar2 = *(uint *)(param_1 + 0xe00);
  *(undefined1 *)(param_2 + 0x10) = 0;
  *(bool *)(param_2 + 0xe) = (uVar2 & 8) != 0;
  FUN_0020b8e4(param_1,FUN_0020f518,param_2);
  FUN_0020ed80(param_1,5);
  return;
}


// ===== FUN_0020f154 @ 0020f154 (266 bytes)

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0020f154(int param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    return 4;
  }
  if (param_3 == 0) {
    return 4;
  }
  if (param_4 == 0) {
    return 4;
  }
  bVar2 = *(byte *)((int)param_2 + 0xd);
  if (bVar2 != 4) {
    if ((bVar2 < 5) || (8 < bVar2)) {
      if ((*(byte *)((int)param_2 + 0xd) < 9) || (0x10 < *(byte *)((int)param_2 + 0xd))) {
        if ((*(byte *)((int)param_2 + 0xd) < 0x11) || (0x18 < *(byte *)((int)param_2 + 0xd))) {
          if ((param_3 & 3) != 0) {
            return 4;
          }
          if (*(char *)(param_2 + 3) == '\0') {
            uVar1 = param_4 & 7;
          }
          else {
            uVar1 = param_4 & 3;
          }
        }
        else {
          if (param_4 % 6 != 0) {
            return 4;
          }
          if (*(char *)((int)param_2 + 0xe) == '\0') goto LAB_0020f17d;
          uVar1 = param_3 & 3;
        }
      }
      else {
        if ((param_3 & 3) != 0) {
          return 4;
        }
        uVar1 = param_4 & 3;
      }
    }
    else {
      if ((param_3 & 1) != 0) {
        return 4;
      }
      uVar1 = param_4 & 1;
    }
    if (uVar1 != 0) {
      return 4;
    }
  }
LAB_0020f17d:
  memw();
  memw();
  if (param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] != 0) {
    return 0xa8e;
  }
  memw();
  *param_2 = 1;
  memw();
  memw();
  param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 5] = param_3;
  memw();
  memw();
  param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] = param_4;
  memw();
  memw();
  *(byte *)(param_2 + 0xd) = *(char *)(param_2 + 0xd) + 1U & 3;
  memw();
  memw();
  *(uint *)(param_1 + 0xe08) =
       *(uint *)(param_1 + 0xe08) & 0xfffff0ff | (*(byte *)((int)param_2 + 0xf) & 0xf) << 8;
  memw();
  memw();
  *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) | 1;
  FUN_0020ed70(param_1,5);
  return 0;
}


// ===== FUN_0020f260 @ 0020f260 (95 bytes)

void FUN_0020f260(int param_1,undefined4 *param_2)

{
  FUN_0020ed80(param_1,5);
  memw();
  memw();
  *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) & 0xfffffffe;
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00010000;
  memw();
  *param_2 = 0;
  memset(param_2 + 5,0,0x20);
  memw();
  *(undefined1 *)((int)param_2 + 0x35) = 0;
  memw();
  *(undefined1 *)(param_2 + 0xd) = 0;
  return;
}


// ===== FUN_0020f2c0 @ 0020f2c0 (155 bytes)

void FUN_0020f2c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  
  memset(param_2,0,0x40);
  *(undefined4 *)(param_2 + 8) = param_4;
  *(undefined4 *)(param_2 + 4) = param_3;
  memw();
  *(byte *)(param_2 + 0xf) = (byte)((uint)*(undefined4 *)(param_1 + 0xe08) >> 0x10) & 0xf;
  memw();
  uVar2 = (*(uint *)(param_1 + 0xc00) & 0x400) >> 10;
  uVar1 = (undefined1)uVar2;
  if (uVar2 != 0) {
    uVar1 = 1;
  }
  *(undefined1 *)(param_2 + 0xc) = uVar1;
  memw();
  *(byte *)(param_2 + 0xd) = ((byte)((uint)*(undefined4 *)(param_1 + 0xc00) >> 0x10) & 0x1f) + 1;
  memw();
  uVar2 = *(uint *)(param_1 + 0xe00);
  *(undefined1 *)(param_2 + 0x10) = 0;
  *(bool *)(param_2 + 0xe) = (uVar2 & 8) != 0;
  FUN_0020b8e4(param_1,FUN_0020f8a0,param_2);
  FUN_0020ed80(param_1,10);
  return;
}


// ===== FUN_0020f35c @ 0020f35c (268 bytes)

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0020f35c(int param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    return 4;
  }
  if (param_3 == 0) {
    return 4;
  }
  if (param_4 == 0) {
    return 4;
  }
  bVar2 = *(byte *)((int)param_2 + 0xd);
  if (bVar2 != 4) {
    if ((bVar2 < 5) || (8 < bVar2)) {
      if ((*(byte *)((int)param_2 + 0xd) < 9) || (0x10 < *(byte *)((int)param_2 + 0xd))) {
        if ((*(byte *)((int)param_2 + 0xd) < 0x11) || (0x18 < *(byte *)((int)param_2 + 0xd))) {
          if ((param_3 & 3) != 0) {
            return 4;
          }
          if (*(char *)(param_2 + 3) == '\0') {
            uVar1 = param_4 & 7;
          }
          else {
            uVar1 = param_4 & 3;
          }
        }
        else {
          if (param_4 % 6 != 0) {
            return 4;
          }
          if (*(char *)((int)param_2 + 0xe) == '\0') goto LAB_0020f385;
          uVar1 = param_3 & 3;
        }
      }
      else {
        if ((param_3 & 3) != 0) {
          return 4;
        }
        uVar1 = param_4 & 3;
      }
    }
    else {
      if ((param_3 & 1) != 0) {
        return 4;
      }
      uVar1 = param_4 & 1;
    }
    if (uVar1 != 0) {
      return 4;
    }
  }
LAB_0020f385:
  memw();
  memw();
  if (param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] != 0) {
    return 0xa8e;
  }
  memw();
  *param_2 = 4;
  memw();
  memw();
  param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 5] = param_3;
  memw();
  memw();
  param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] = param_4;
  memw();
  memw();
  *(byte *)(param_2 + 0xd) = *(char *)(param_2 + 0xd) + 1U & 3;
  memw();
  memw();
  *(uint *)(param_1 + 0xe08) =
       *(uint *)(param_1 + 0xe08) & 0xfff0ffff | (*(byte *)((int)param_2 + 0xf) & 0xf) << 0x10;
  memw();
  memw();
  *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) | 1;
  FUN_0020ed70(param_1,10);
  return 0;
}


// ===== FUN_0020f468 @ 0020f468 (95 bytes)

void FUN_0020f468(int param_1,undefined4 *param_2)

{
  FUN_0020ed80(param_1,10);
  memw();
  memw();
  *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) & 0xfffffffe;
  memw();
  memw();
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00020000;
  memw();
  *param_2 = 0;
  memset(param_2 + 5,0,0x20);
  memw();
  *(undefined1 *)((int)param_2 + 0x35) = 0;
  memw();
  *(undefined1 *)(param_2 + 0xd) = 0;
  return;
}


// ===== FUN_0020f4c8 @ 0020f4c8 (39 bytes)

undefined4 FUN_0020f4c8(undefined4 param_1,int *param_2,int *param_3)

{
  if ((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) {
    memw();
    if (*param_2 != 0) {
      memw();
      *param_3 = param_2[0xf];
      return 0;
    }
    return 6;
  }
  return 4;
}


// ===== FUN_0020f4f0 @ 0020f4f0 (39 bytes)

undefined4 FUN_0020f4f0(undefined4 param_1,int *param_2,int *param_3)

{
  if ((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) {
    memw();
    if (*param_2 != 0) {
      memw();
      *param_3 = param_2[0xe];
      return 0;
    }
    return 6;
  }
  return 4;
}


// ===== FUN_0020f518 @ 0020f518 (898 bytes)

void FUN_0020f518(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  uint3 uVar3;
  uint3 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  memw();
  uVar5 = *(uint *)(param_1 + 0xe18);
  memw();
  bVar1 = *(byte *)((int)param_2 + 0x35);
  memw();
  puVar4 = (uint3 *)param_2[(uint)bVar1 * 2 + 5];
  memw();
  iVar7 = param_2[(uint)bVar1 * 2 + 6];
  if ((uVar5 & 1) != 0) {
    memw();
    memw();
    param_2[0xe] = param_2[0xe] + 1;
    memw();
    *(undefined4 *)(param_1 + 0xe04) = 1;
  }
  if ((uVar5 >> 2 & 1) == 0) {
    return;
  }
  memw();
  if (*param_2 == 1) {
    memw();
    if (((*(uint *)(param_1 + 0xe04) & 0x20) != 0) && (iVar7 != 0)) {
      do {
        bVar2 = *(byte *)((int)param_2 + 0xd);
        if (bVar2 == 4) {
          memw();
          *(uint *)(param_1 + 0xe20) = (byte)*puVar4 & 0xf | ((byte)*puVar4 & 0xf0) << 0xc;
          puVar4 = (uint3 *)((int)puVar4 + 1);
          memw();
          memw();
          param_2[0xf] = param_2[0xf] + 1;
          iVar7 = iVar7 + -1;
          if (iVar7 == 0) goto LAB_0020f687;
LAB_0020f61b:
          memw();
          param_2[(uint)bVar1 * 2 + 6] = iVar7;
          memw();
          param_2[(uint)bVar1 * 2 + 5] = (int)puVar4;
        }
        else {
          if (bVar2 < 9) {
            memw();
            uVar5 = (ushort)*puVar4 & 0xff;
            if ((char)param_2[3] == '\0') {
              memw();
              *(uint *)(param_1 + 0xe20) =
                   uVar5 | ((uint)(ushort)*puVar4 & (uint)&DAT_0000ff00) << 8;
              puVar4 = (uint3 *)((int)puVar4 + 2);
              memw();
              memw();
              param_2[0xf] = param_2[0xf] + 2;
              iVar7 = iVar7 + -2;
            }
            else {
              memw();
              *(uint *)(param_1 + 0xe20) = uVar5;
              puVar4 = (uint3 *)((int)puVar4 + 1);
              memw();
              memw();
              param_2[0xf] = param_2[0xf] + 1;
              iVar7 = iVar7 + -1;
            }
          }
          else if (bVar2 < 0x11) {
            memw();
            if ((char)param_2[3] == '\0') {
              memw();
              *(undefined4 *)(param_1 + 0xe20) = *(undefined4 *)puVar4;
              puVar4 = puVar4 + 1;
              memw();
              memw();
              param_2[0xf] = param_2[0xf] + 4;
              iVar7 = iVar7 + -4;
            }
            else {
              uVar6 = ae_zext16(*(undefined4 *)puVar4);
              memw();
              *(undefined4 *)(param_1 + 0xe20) = uVar6;
              puVar4 = (uint3 *)((int)puVar4 + 2);
              memw();
              memw();
              param_2[0xf] = param_2[0xf] + 2;
              iVar7 = iVar7 + -2;
            }
          }
          else if (bVar2 < 0x19) {
            if (*(char *)((int)param_2 + 0xe) == '\0') {
              uVar3 = *puVar4;
              puVar4 = (uint3 *)((int)puVar4 + 3);
              if (((char)param_2[4] == '\0') || ((char)param_2[3] != '\0')) {
                memw();
                *(uint *)(param_1 + 0xe20) = (uint)uVar3;
                *(undefined1 *)(param_2 + 4) = 1;
              }
              else {
                memw();
                *(uint *)(param_1 + 0xe24) = (uint)uVar3;
                *(undefined1 *)(param_2 + 4) = 0;
              }
              memw();
              memw();
              param_2[0xf] = param_2[0xf] + 3;
              iVar7 = iVar7 + -3;
            }
            else if ((char)param_2[4] == '\0') {
              memw();
              memw();
              *(undefined4 *)(param_1 + 0xe20) = *(undefined4 *)puVar4;
              puVar4 = puVar4 + 1;
              memw();
              memw();
              param_2[0xf] = param_2[0xf] + 4;
              *(undefined1 *)(param_2 + 4) = 1;
              iVar7 = iVar7 + -4;
            }
            else {
              memw();
              uVar6 = ae_l16ui_n(puVar4,0);
              memw();
              *(undefined4 *)(param_1 + 0xe24) = uVar6;
              puVar4 = (uint3 *)((int)puVar4 + 2);
              memw();
              memw();
              param_2[0xf] = param_2[0xf] + 2;
              *(undefined1 *)(param_2 + 4) = 0;
              iVar7 = iVar7 + -2;
            }
          }
          else {
            memw();
            memw();
            *(undefined4 *)(param_1 + 0xe20) = *(undefined4 *)puVar4;
            puVar4 = puVar4 + 1;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 4;
            iVar7 = iVar7 + -4;
          }
          if (iVar7 != 0) goto LAB_0020f61b;
LAB_0020f687:
          memw();
          param_2[(uint)bVar1 * 2 + 6] = 0;
          memw();
          *(byte *)((int)param_2 + 0x35) = bVar1 + 1 & 3;
          if (param_2[1] != 0) {
            (*(code *)param_2[1])(param_1,param_2,0xa8c,param_2[2]);
          }
          memw();
          memw();
          if (param_2[(uint)*(byte *)((int)param_2 + 0x35) * 2 + 6] == 0) {
            memw();
            *param_2 = 2;
            memw();
            *(undefined4 *)(param_1 + 0xe04) = 0x100;
            return;
          }
        }
        memw();
      } while (((*(uint *)(param_1 + 0xe04) >> 5 & 1) != 0) && (iVar7 != 0));
    }
  }
  else {
    memw();
    if (*param_2 == 2) {
      if ((0x10 < *(byte *)((int)param_2 + 0xd)) && (*(byte *)((int)param_2 + 0xd) < 0x19)) {
        if ((char)param_2[4] != '\0') {
          memw();
          *(undefined4 *)(param_1 + 0xe24) = 0;
          *(undefined1 *)(param_2 + 4) = 0;
          memw();
          memw();
          *(uint *)(param_1 + 0xe08) = *(uint *)(param_1 + 0xe08) & 0xfffff0ff;
          memw();
          *param_2 = 3;
          memw();
          *(undefined4 *)(param_1 + 0xe04) = 0x100;
          return;
        }
        memw();
        *(undefined4 *)(param_1 + 0xe20) = 0;
        memw();
        *(undefined4 *)(param_1 + 0xe24) = 0;
        memw();
        memw();
        *(uint *)(param_1 + 0xe08) = *(uint *)(param_1 + 0xe08) & 0xfffff0ff;
        memw();
        *param_2 = 3;
        memw();
        *(undefined4 *)(param_1 + 0xe04) = 0x100;
        return;
      }
      memw();
      *(undefined4 *)(param_1 + 0xe20) = 0;
      memw();
      memw();
      *(uint *)(param_1 + 0xe08) = *(uint *)(param_1 + 0xe08) & 0xfffff0ff;
      memw();
      *param_2 = 3;
      memw();
      *(undefined4 *)(param_1 + 0xe04) = 0x100;
      return;
    }
    memw();
    if (*param_2 == 3) {
      memw();
      memw();
      *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) & 0xfffffffe;
      FUN_0020ed80(param_1,5);
      memw();
      memw();
      *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00010000;
      memw();
      *param_2 = 0;
      if (param_2[1] != 0) {
        (*(code *)param_2[1])(param_1,param_2,0xa8d,param_2[2]);
        memw();
        *(undefined4 *)(param_1 + 0xe04) = 0x100;
        return;
      }
    }
  }
  memw();
  *(undefined4 *)(param_1 + 0xe04) = 0x100;
  return;
}


// ===== FUN_0020f8a0 @ 0020f8a0 (701 bytes)

void FUN_0020f8a0(int param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  memw();
  uVar4 = *(uint *)(param_1 + 0xe18);
  memw();
  bVar1 = *(byte *)((int)param_2 + 0x35);
  memw();
  pbVar3 = (byte *)param_2[(uint)bVar1 * 2 + 5];
  memw();
  iVar5 = param_2[(uint)bVar1 * 2 + 6];
  if ((uVar4 >> 1 & 1) != 0) {
    memw();
    memw();
    param_2[0xe] = param_2[0xe] + 1;
    memw();
    *(undefined4 *)(param_1 + 0xe04) = 2;
  }
  if ((uVar4 >> 3 & 1) == 0) {
    return;
  }
  memw();
  if (((*(uint *)(param_1 + 0xe04) >> 6 & 1) != 0) && (iVar5 != 0)) {
    do {
      bVar2 = *(byte *)((int)param_2 + 0xd);
      if (bVar2 == 4) {
        memw();
        *pbVar3 = (byte)*(uint *)(param_1 + 0xe30) & 0xf |
                  (byte)(*(uint *)(param_1 + 0xe30) >> 0xc) & 0xf0;
        pbVar3 = pbVar3 + 1;
        memw();
        memw();
        param_2[0xf] = param_2[0xf] + 1;
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) goto LAB_0020f98e;
LAB_0020f923:
        memw();
        param_2[(uint)bVar1 * 2 + 6] = iVar5;
        memw();
        param_2[(uint)bVar1 * 2 + 5] = pbVar3;
      }
      else {
        if (bVar2 < 9) {
          memw();
          uVar4 = *(uint *)(param_1 + 0xe30);
          if (*(char *)(param_2 + 3) == '\0') {
            memw();
            ae_s16i_n(uVar4 >> 8 & (uint)&DAT_0000ff00 | uVar4 & 0xff,pbVar3,0);
            pbVar3 = pbVar3 + 2;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 2;
            iVar5 = iVar5 + -2;
          }
          else {
            memw();
            *pbVar3 = (byte)uVar4;
            pbVar3 = pbVar3 + 1;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 1;
            iVar5 = iVar5 + -1;
          }
        }
        else if (bVar2 < 0x11) {
          memw();
          if (*(char *)(param_2 + 3) == '\0') {
            memw();
            *(undefined4 *)pbVar3 = *(undefined4 *)(param_1 + 0xe30);
            pbVar3 = pbVar3 + 4;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 4;
            iVar5 = iVar5 + -4;
          }
          else {
            memw();
            ae_s16i_n(*(undefined4 *)(param_1 + 0xe30),pbVar3,0);
            pbVar3 = pbVar3 + 2;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 2;
            iVar5 = iVar5 + -2;
          }
        }
        else if (bVar2 < 0x19) {
          if (*(char *)((int)param_2 + 0xe) == '\0') {
            if (*(char *)(param_2 + 4) == '\0') {
              memw();
              *(undefined1 *)(param_2 + 4) = 1;
              uVar6 = *(undefined4 *)(param_1 + 0xe30);
            }
            else {
              memw();
              *(undefined1 *)(param_2 + 4) = 0;
              uVar6 = *(undefined4 *)(param_1 + 0xe34);
            }
            *pbVar3 = (byte)uVar6;
            pbVar3[1] = (byte)((uint)uVar6 >> 8);
            pbVar3[2] = (byte)((uint)uVar6 >> 0x10);
            pbVar3 = pbVar3 + 3;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 3;
            iVar5 = iVar5 + -3;
          }
          else if (*(char *)(param_2 + 4) == '\0') {
            memw();
            *(undefined1 *)(param_2 + 4) = 1;
            memw();
            *(undefined4 *)pbVar3 = *(undefined4 *)(param_1 + 0xe30);
            pbVar3 = pbVar3 + 4;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 4;
            iVar5 = iVar5 + -4;
          }
          else {
            memw();
            *(undefined1 *)(param_2 + 4) = 0;
            memw();
            ae_s16i_n(*(undefined4 *)(param_1 + 0xe34),pbVar3,0);
            pbVar3 = pbVar3 + 2;
            memw();
            memw();
            param_2[0xf] = param_2[0xf] + 2;
            iVar5 = iVar5 + -2;
          }
        }
        else {
          memw();
          memw();
          *(undefined4 *)pbVar3 = *(undefined4 *)(param_1 + 0xe30);
          pbVar3 = pbVar3 + 4;
          memw();
          memw();
          param_2[0xf] = param_2[0xf] + 4;
          iVar5 = iVar5 + -4;
        }
        if (iVar5 != 0) goto LAB_0020f923;
LAB_0020f98e:
        memw();
        param_2[(uint)bVar1 * 2 + 6] = 0;
        memw();
        *(byte *)((int)param_2 + 0x35) = bVar1 + 1 & 3;
        if (param_2[1] != 0) {
          (*(code *)param_2[1])(param_1,param_2,0xa8c,param_2[2]);
        }
        memw();
        memw();
        if (param_2[(uint)*(byte *)((int)param_2 + 0x35) * 2 + 6] == 0) {
          memw();
          memw();
          *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) & 0xfffffffe;
          FUN_0020ed80(param_1,10);
          memw();
          memw();
          *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00020000;
          memw();
          *param_2 = 0;
          if (param_2[1] != 0) {
            (*(code *)param_2[1])(param_1,param_2,0xa8d,param_2[2]);
          }
          memw();
          *(undefined **)(param_1 + 0xe04) = &DAT_00010000;
          return;
        }
      }
      memw();
    } while (((*(uint *)(param_1 + 0xe04) >> 6 & 1) != 0) && (iVar5 != 0));
  }
  memw();
  *(undefined **)(param_1 + 0xe04) = &DAT_00010000;
  return;
}


// ===== FUN_0020fb70 @ 0020fb70 (38 bytes)

void FUN_0020fb70(int param_1,uint param_2)

{
  param_1 = (param_2 >> 5 & 7) * 4 + param_1;
  memw();
  memw();
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  return;
}


// ===== FUN_0020fb98 @ 0020fb98 (38 bytes)

void FUN_0020fb98(int param_1,uint param_2)

{
  param_1 = (param_2 >> 5 & 7) * 4 + param_1;
  memw();
  memw();
  *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  return;
}


// ===== FUN_0020fbc0 @ 0020fbc0 (16 bytes)

void FUN_0020fbc0(int param_1)

{
  FUN_0020fb98(*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),
               *(undefined1 *)(*(int *)(param_1 + 0x10) + 0xc));
  return;
}


// ===== FUN_0020fbd0 @ 0020fbd0 (20 bytes)

void FUN_0020fbd0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_0020fb70(*(undefined4 *)(param_1[4] + 8),*(undefined1 *)(param_1[4] + 0xc));
  }
  return;
}


// ===== I2S_TxTransferCreateHandleDMA @ 0020fbe4 (149 bytes)

void I2S_TxTransferCreateHandleDMA
               (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  memset(param_2,0,0x38);
  param_2[3] = param_5;
  param_2[2] = param_4;
  param_2[4] = param_3;
  *param_2 = 0;
  memw();
  *(char *)(param_2 + 1) =
       (char)(((*(uint *)(param_1 + 0xc00) & (uint)&DAT_001f0000) >> 0x10) + 1 >> 3);
  memw();
  if ((*(uint *)(param_1 + 0xc00) & 0x400) == 0) {
    *(undefined1 *)(param_2 + 1) = 4;
  }
  if (*(char *)(param_2 + 1) == '\x03') {
    *(undefined1 *)(param_2 + 1) = 4;
  }
  memset(&DAT_00238c70,0,0x38);
  DAT_00238c70 = param_1;
  DAT_00238c74 = param_2;
  FUN_0020ab28(param_3,FUN_00210420,&DAT_00238c70);
  return;
}


// ===== I2S_TxTransferSendDMA @ 0020fc7c (215 bytes)

int I2S_TxTransferSendDMA(undefined4 param_1,int *param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  FUN_0020fbc0(param_2);
  if ((((param_2 == (int *)0x0) || ((param_3 & 3) != 0)) || (param_4 == 0)) || ((param_4 & 3) != 0))
  {
    iVar1 = 4;
  }
  else {
    memw();
    memw();
    if (param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] == 0) {
      memw();
      memw();
      *(uint *)(&DAT_00238c84 + (uint)*(byte *)(param_2 + 0xd) * 8) = param_3;
      memw();
      memw();
      *(uint *)(&DAT_00238c88 + (uint)*(byte *)(param_2 + 0xd) * 8) = param_4;
      memw();
      memw();
      param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 5] = param_3;
      memw();
      memw();
      param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] = param_4;
      memw();
      memw();
      *(byte *)(param_2 + 0xd) = (char)param_2[0xd] + 1U & 3;
      if (*param_2 == 0) {
        *param_2 = 1;
        iVar1 = FUN_0020ff80(param_1,param_2);
        if (iVar1 != 0) {
          FUN_0020fbd0(param_2);
          return iVar1;
        }
      }
      FUN_002101ec(param_1,param_2);
      FUN_0020fbd0(param_2);
      return 0;
    }
    iVar1 = 0xa8e;
  }
  FUN_0020fbd0(param_2);
  return iVar1;
}


// ===== FUN_0020fd54 @ 0020fd54 (313 bytes)

void FUN_0020fd54(dword *param_1,int *param_2)

{
  uint uVar1;
  
  FUN_0020fbc0(param_2,param_1 != &USART0_CFG);
  FUN_0020aa20(param_2[4]);
  if (*param_2 == 1) {
    memw();
    uVar1 = param_1[0x381] >> 4 & 1;
    while (uVar1 == 0) {
      memw();
      uVar1 = param_1[0x381] & 0x10;
    }
    memw();
    param_1[0x388] = 0;
    memw();
    uVar1 = param_1[0x381];
    while ((uVar1 & 0x10) == 0) {
      memw();
      uVar1 = param_1[0x381];
    }
    memw();
    memw();
    param_1[0x380] = param_1[0x380] & 0xffffefff;
    memw();
    memw();
    param_1[0x380] = param_1[0x380] | (uint)&DAT_00010000;
  }
  else {
    memw();
    memw();
    param_1[0x380] = param_1[0x380] & 0xffffdfff;
    memw();
    memw();
    param_1[0x380] = param_1[0x380] | (uint)&DAT_00020000;
  }
  memw();
  memw();
  param_1[0x300] = param_1[0x300] & 0xfffffffe;
  *param_2 = 0;
  memset(param_2 + 5,0,0x20);
  memw();
  *(undefined1 *)((int)param_2 + 0x35) = 0;
  memw();
  *(undefined1 *)(param_2 + 0xd) = 0;
  memset(&DAT_00238c84,0,0x20);
  DAT_00238c78 = 0;
  memw();
  DAT_00238c7c = 0;
  memw();
  DAT_00238c7d = 0;
  memw();
  DAT_00238c7e = 0;
  memw();
  DAT_00238c7f = 0;
  memw();
  DAT_00238c80 = 0;
  memw();
  DAT_00238ca4 = 0;
  return;
}


// ===== I2S_RxTransferCreateHandleDMA @ 0020fe90 (22 bytes)

void I2S_RxTransferCreateHandleDMA
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  I2S_TxTransferCreateHandleDMA(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ===== I2S_RxTransferReceiveDMA @ 0020fea8 (215 bytes)

int I2S_RxTransferReceiveDMA(undefined4 param_1,int *param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  FUN_0020fbc0(param_2);
  if ((((param_2 == (int *)0x0) || ((param_3 & 3) != 0)) || (param_4 == 0)) || ((param_4 & 3) != 0))
  {
    iVar1 = 4;
  }
  else {
    memw();
    memw();
    if (param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] == 0) {
      memw();
      memw();
      *(uint *)(&DAT_00238c84 + (uint)*(byte *)(param_2 + 0xd) * 8) = param_3;
      memw();
      memw();
      *(uint *)(&DAT_00238c88 + (uint)*(byte *)(param_2 + 0xd) * 8) = param_4;
      memw();
      memw();
      param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 5] = param_3;
      memw();
      memw();
      param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] = param_4;
      memw();
      memw();
      *(byte *)(param_2 + 0xd) = (char)param_2[0xd] + 1U & 3;
      if (*param_2 == 0) {
        *param_2 = 2;
        iVar1 = FUN_0020ff80(param_1,param_2);
        if (iVar1 != 0) {
          FUN_0020fbd0(param_2);
          return iVar1;
        }
      }
      FUN_002101ec(param_1,param_2);
      FUN_0020fbd0(param_2);
      return 0;
    }
    iVar1 = 0xa8e;
  }
  FUN_0020fbd0(param_2);
  return iVar1;
}


// ===== FUN_0020ff80 @ 0020ff80 (620 bytes)

undefined4 FUN_0020ff80(int param_1,int *param_2)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined *puStack_2c;
  
  memw();
  iVar4 = (uint)DAT_00238c80 * 8;
  piVar1 = (int *)(&DAT_00238c84 + iVar4);
  memw();
  if (*(undefined **)(&DAT_00238c88 + iVar4) < &DAT_00002000) {
    memw();
    if (*(undefined **)(&DAT_00238c88 + iVar4) < (undefined *)0x1001) {
      memw();
      puStack_2c = (undefined *)ae_zext16(*(undefined4 *)(&DAT_00238c88 + iVar4));
    }
    else {
      memw();
      uVar5 = *(uint *)(&DAT_00238c88 + iVar4) >> 1;
      if ((*(uint *)(&DAT_00238c88 + iVar4) >> 1 & 3) != 0) {
        uVar5 = uVar5 & (uint)&DAT_0000fffc;
      }
      puStack_2c = (undefined *)ae_zext16(uVar5);
    }
  }
  else {
    puStack_2c = &DAT_00001000;
  }
  bVar9 = *param_2 == 1;
  if (bVar9) {
    memw();
    puVar6 = (undefined *)*piVar1;
    puVar2 = (undefined *)(param_1 + 0xe20);
  }
  else {
    memw();
    puVar6 = (undefined *)(param_1 + 0xe30);
    puVar2 = (undefined *)*piVar1;
  }
  memw();
  DAT_00238c7e = 1;
  memw();
  DAT_00238ca4 = 0;
  uVar5 = 0x223;
  if ((char)param_2[1] != '\x04') {
    uVar5 = (*(byte *)(param_2 + 1) - 1) * 0x100 & 0x300 | 0x23;
  }
  uVar7 = (uint)bVar9 << 0xc;
  if (bVar9 == 4) {
    uVar7 = 0x3000;
  }
  uVar8 = (uint)!bVar9 << 0xe;
  if (!bVar9 == 4) {
    uVar8 = 0xc000;
  }
  FUN_0020ad10(param_2[4],
               uVar5 | uVar7 |
               uVar8 | ((uint)puStack_2c / (uint)*(byte *)(param_2 + 1) - 1) * 0x10000 & 0x3ff0000,
               puVar6,puVar2,&DAT_20060610);
  memw();
  memw();
  *(short *)((int)&DAT_00238c78 + (uint)DAT_00238c7d * 2) = (short)puStack_2c;
  memw();
  DAT_00238c7d = DAT_00238c7d + 1 & 1;
  memw();
  memw();
  memw();
  *(int *)(&DAT_00238c88 + iVar4) = *(int *)(&DAT_00238c88 + iVar4) - (int)puStack_2c;
  memw();
  memw();
  *piVar1 = (int)(puStack_2c + *piVar1);
  memw();
  if (*(int *)(&DAT_00238c88 + iVar4) == 0) {
    memw();
    *piVar1 = 0;
    memw();
    DAT_00238c80 = DAT_00238c80 + 1 & 3;
    memw();
  }
  puVar6 = &DAT_20060610;
  uVar5 = 1;
  do {
    puVar2 = (undefined *)(param_1 + 0xe30);
    if (*param_2 == 1) {
      puVar2 = &DAT_00238c60;
    }
    puVar3 = (undefined *)(param_1 + 0xe20);
    if (*param_2 != 1) {
      puVar3 = &DAT_00238c64;
    }
    FUN_0020a78c(puVar6,&DAT_00010203,puVar2,puVar3,&DAT_20060610 + (uVar5 & 1) * 0x10);
    uVar5 = uVar5 + 1;
    puVar6 = puVar6 + 0x10;
  } while (uVar5 != 3);
  if (*param_2 == 1) {
    memw();
    memw();
    *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00001000;
  }
  else {
    memw();
    memw();
    *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) | (uint)&DAT_00002000;
  }
  iVar4 = *(int *)(param_2[4] + 8) + (uint)*(byte *)(param_2[4] + 0xc) * 0x10;
  memw();
  memw();
  *(uint *)(iVar4 + 0x400) = *(uint *)(iVar4 + 0x400) | 1;
  FUN_0020aed8(param_2[4]);
  memw();
  memw();
  *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) | 1;
  return 0;
}

