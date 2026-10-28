// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2014d288 @ 2014d288 (68 bytes)

void FUN_2014d288(char *param_1,char *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 == 0) {
    return;
  }
  do {
    uVar1 = uVar1 + 1;
    if (*param_2 == '\0') {
      *param_1 = '\0';
    }
    else {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
    }
    param_1 = param_1 + 1;
  } while (uVar1 < param_3);
  return;
}


// ===== FUN_2014d338 @ 2014d338 (36 bytes)

char * FUN_2014d338(char *param_1,char param_2)

{
  while( true ) {
    if (*param_1 == param_2) {
      return param_1;
    }
    if (*param_1 == '\0') break;
    param_1 = param_1 + 1;
  }
  return (char *)0x0;
}


// ===== FUN_2014d35c @ 2014d35c (24 bytes)

int FUN_2014d35c(int param_1)

{
  if (param_1 - 0x61U < 0x1a) {
    param_1 = (int)(char)((char)param_1 + -0x20);
  }
  return param_1;
}


// ===== FUN_2014d374 @ 2014d374 (24 bytes)

int FUN_2014d374(int param_1)

{
  if (param_1 - 0x41U < 0x1a) {
    param_1 = (int)(char)((char)param_1 + ' ');
  }
  return param_1;
}


// ===== FUN_2014d38c @ 2014d38c (108 bytes)

int FUN_2014d38c(byte *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  byte *extraout_r2;
  byte *extraout_r3;
  undefined4 extraout_r12;
  
  do {
    bVar1 = *param_1;
    iVar4 = (int)(char)(bVar1 | *param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if ((char)bVar1 == 0) {
      return -1;
    }
    if (*param_2 == 0) {
      return 1;
    }
    cVar2 = FUN_2014d35c((int)(char)bVar1,iVar4,param_2 + 1,param_1 + 1);
    cVar3 = FUN_2014d35c(extraout_r12);
    param_2 = extraout_r2;
    param_1 = extraout_r3;
  } while ((char)(cVar2 - cVar3) == 0);
  return (int)(char)(cVar2 - cVar3);
}


// ===== FUN_2014d3f8 @ 2014d3f8 (148 bytes)

int FUN_2014d3f8(ushort *param_1,ushort *param_2)

{
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  int extraout_r2;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *extraout_r12;
  undefined8 uVar11;
  
  puVar8 = param_1;
  puVar9 = param_2;
  do {
    uVar3 = *puVar8;
    puVar10 = puVar9 + 1;
    uVar4 = *puVar9;
    if (uVar3 == 0 && uVar4 == 0) {
      return 0;
    }
    if (uVar3 == 0) {
      return -1;
    }
    if (uVar4 == 0) {
      return 1;
    }
    pcVar1 = (char *)((int)param_1 + 1);
    pcVar2 = (char *)((int)param_2 + 1);
    uVar5 = *param_1;
    param_1 = param_1 + 1;
    uVar6 = *param_2;
    param_2 = param_2 + 1;
    if (*pcVar1 == '\0' && *pcVar2 == '\0') {
      uVar11 = FUN_2014d35c((int)(char)uVar5);
      iVar7 = FUN_2014d35c((int)(char)uVar6,(int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      iVar7 = extraout_r2 - iVar7;
      puVar10 = extraout_r12;
    }
    else {
      iVar7 = (uint)uVar3 - (uint)uVar4;
    }
    puVar8 = puVar8 + 1;
    puVar9 = puVar10;
  } while (iVar7 == 0);
  return iVar7;
}


// ===== FUN_2014d48c @ 2014d48c (124 bytes)

int FUN_2014d48c(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  uint extraout_r2;
  int extraout_r3;
  char *extraout_r12;
  
  if (param_3 != 0) {
    do {
      cVar2 = *param_2;
      if (*param_1 == '\0' && cVar2 == '\0') {
        return 0;
      }
      if (*param_1 == '\0') {
        return -1;
      }
      if (cVar2 == 0) {
        return 1;
      }
      cVar1 = FUN_2014d35c();
      cVar2 = FUN_2014d35c((int)cVar2);
      if ((char)(cVar1 - cVar2) != 0) {
        return (int)(char)(cVar1 - cVar2);
      }
      param_1 = param_1 + 1;
      param_2 = extraout_r12;
    } while (extraout_r3 + 1U < extraout_r2);
  }
  return 0;
}


// ===== FUN_2014d508 @ 2014d508 (172 bytes)

int FUN_2014d508(ushort *param_1,ushort *param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  uint extraout_r2;
  int extraout_r3;
  ushort *puVar8;
  ushort *puVar9;
  uint uVar10;
  
  uVar10 = 0;
  puVar8 = param_2;
  puVar9 = param_1;
  if (param_3 != 0) {
    while( true ) {
      uVar3 = *puVar9;
      uVar4 = *puVar8;
      if (uVar3 == 0 && uVar4 == 0) break;
      if (uVar3 == 0) {
        return -1;
      }
      if (uVar4 == 0) {
        return 1;
      }
      pcVar1 = (char *)((int)param_1 + 1);
      pcVar2 = (char *)((int)param_2 + 1);
      uVar5 = *param_1;
      param_1 = param_1 + 1;
      uVar6 = *param_2;
      param_2 = param_2 + 1;
      if (*pcVar1 == '\0' && *pcVar2 == '\0') {
        FUN_2014d35c((int)(char)uVar5);
        iVar7 = FUN_2014d35c((int)(char)uVar6);
        iVar7 = extraout_r3 - iVar7;
        param_3 = extraout_r2;
      }
      else {
        iVar7 = (uint)uVar3 - (uint)uVar4;
      }
      if (iVar7 != 0) {
        return iVar7;
      }
      uVar10 = uVar10 + 1;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      if (param_3 <= uVar10) {
        return 0;
      }
    }
  }
  return 0;
}


// ===== FUN_2014d5b4 @ 2014d5b4 (76 bytes)

byte * FUN_2014d5b4(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  do {
    iVar1 = FUN_2014ca90(*pbVar2);
    if (iVar1 == 0) {
      if (*pbVar2 - 0x41 < 0x1a) {
        *pbVar2 = *pbVar2 + 0x20;
      }
    }
    else {
      pbVar2 = pbVar2 + 1;
    }
    pbVar2 = pbVar2 + 1;
  } while (*pbVar2 != 0);
  return param_1;
}


// ===== FUN_2014d630 @ 2014d630 (72 bytes)

char * FUN_2014d630(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  char extraout_r1;
  
  iVar2 = FUN_20156260(param_1,param_3);
  if (iVar2 != 0) {
    param_2 = (char *)FUN_2014d630(iVar2,param_2,param_3);
  }
  if (extraout_r1 < '\n') {
    cVar1 = extraout_r1 + '0';
  }
  else {
    cVar1 = extraout_r1 + 'W';
  }
  *param_2 = cVar1;
  return param_2 + 1;
}


// ===== FUN_2014d678 @ 2014d678 (80 bytes)

undefined1 * FUN_2014d678(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  if (param_3 - 2U < 0x23) {
    puVar1 = param_2;
    if ((param_3 == 10) && (param_1 < 0)) {
      *param_2 = 0x2d;
      puVar1 = param_2 + 1;
      param_1 = -param_1;
    }
    puVar1 = (undefined1 *)FUN_2014d630(param_1,puVar1);
    *puVar1 = 0;
  }
  else {
    *param_2 = 0;
  }
  return param_2;
}


// ===== FUN_2014d6c8 @ 2014d6c8 (168 bytes)

int FUN_2014d6c8(char *param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char extraout_r2;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined8 uVar8;
  
  bVar1 = false;
  while( true ) {
    pcVar7 = param_1 + 1;
    iVar5 = (int)*param_1;
    pcVar6 = param_2 + 1;
    cVar2 = *param_2;
    iVar4 = (int)cVar2;
    if (*param_1 == '\0' && cVar2 == '\0') {
      return 0;
    }
    if (iVar5 == 0) break;
    if (iVar4 == 0) {
      return 1;
    }
    param_2 = pcVar6;
    param_1 = pcVar7;
    if (bVar1) {
      bVar1 = false;
      if (iVar5 != iVar4) {
        return -1;
      }
    }
    else {
      iVar3 = FUN_2014ca90(cVar2);
      if (iVar3 == 0) {
        uVar8 = FUN_2014d35c(iVar5);
        cVar2 = FUN_2014d35c(iVar4,(int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        if ((char)(extraout_r2 - cVar2) != 0) {
          return (int)(char)(extraout_r2 - cVar2);
        }
      }
      else {
        bVar1 = true;
        if (iVar5 != iVar4) {
          return -1;
        }
      }
    }
  }
  return -1;
}


// ===== FUN_2014d770 @ 2014d770 (196 bytes)

int FUN_2014d770(char *param_1,char *param_2,uint param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char extraout_r2;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  
  bVar1 = false;
  uVar6 = 0;
  if (param_3 != 0) {
    do {
      iVar5 = (int)*param_1;
      cVar2 = *param_2;
      iVar4 = (int)cVar2;
      if (*param_1 == '\0' && cVar2 == '\0') {
        return 0;
      }
      if (iVar5 == 0) {
        return -1;
      }
      if (iVar4 == 0) {
        return 1;
      }
      if (bVar1) {
        bVar1 = false;
joined_r0x2014d7ec:
        if (iVar5 != iVar4) {
          return -1;
        }
      }
      else {
        iVar3 = FUN_2014ca90(cVar2);
        if (iVar3 != 0) {
          bVar1 = true;
          goto joined_r0x2014d7ec;
        }
        uVar7 = FUN_2014d35c(iVar5);
        cVar2 = FUN_2014d35c(iVar4,(int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
        if ((char)(extraout_r2 - cVar2) != 0) {
          return (int)(char)(extraout_r2 - cVar2);
        }
      }
      uVar6 = uVar6 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (uVar6 < param_3);
  }
  return 0;
}


// ===== FUN_2014d834 @ 2014d834 (48 bytes)

int FUN_2014d834(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != 0) {
    param_1 = param_1 + 1;
    iVar2 = (int)cVar1 + iVar2 * 10 + -0x30;
    cVar1 = *param_1;
  }
  return iVar2;
}


// ===== FUN_2014d864 @ 2014d864 (80 bytes)

undefined1 * FUN_2014d864(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  if (param_3 - 2U < 0x23) {
    puVar1 = param_2;
    if ((param_3 == 10) && (param_1 < 0)) {
      *param_2 = 0x2d;
      puVar1 = param_2 + 1;
      param_1 = -param_1;
    }
    puVar1 = (undefined1 *)FUN_2014d630(param_1,puVar1);
    *puVar1 = 0;
  }
  else {
    *param_2 = 0;
  }
  return param_2;
}


// ===== FUN_2014d8ec @ 2014d8ec (20 bytes)

void FUN_2014d8ec(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  return;
}


// ===== FUN_2014d900 @ 2014d900 (24 bytes)

undefined2 FUN_2014d900(undefined2 *param_1)

{
  return *param_1;
}


// ===== FUN_2014d918 @ 2014d918 (36 bytes)

void FUN_2014d918(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  param_1[2] = (char)((uint)param_2 >> 0x10);
  param_1[3] = (char)((uint)param_2 >> 0x18);
  return;
}


// ===== FUN_2014d93c @ 2014d93c (32 bytes)

undefined4 FUN_2014d93c(undefined4 *param_1)

{
  return *param_1;
}


// ===== FUN_2014d95c @ 2014d95c (48 bytes)

undefined4 FUN_2014d95c(void)

{
  undefined4 uVar1;
  int in_r3;
  int local_8;
  
  local_8 = in_r3;
  FUN_20150ba0(&local_8);
  if (local_8 - 1U < 0x100) {
    uVar1 = *(undefined4 *)(&DAT_2091d0bc + local_8 * 4);
  }
  else {
    uVar1 = 0xffffffb8;
  }
  return uVar1;
}


// ===== FUN_2014d98c @ 2014d98c (48 bytes)

void FUN_2014d98c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int local_10;
  
  local_10 = param_4;
  FUN_20150ba0(&local_10);
  if (local_10 - 1U < 0x100) {
    *(undefined4 *)(&DAT_2091d0bc + local_10 * 4) = param_1;
  }
  return;
}


// ===== FUN_2014d9c0 @ 2014d9c0 (164 bytes)

int FUN_2014d9c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4c4)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4c0)[iVar2 * 2] == 0) {
        return -0x25;
      }
      iVar1 = FUN_20152bb0((&DAT_2091d4c0)[iVar2 * 2],300);
      goto joined_r0x2014da50;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  while ((&DAT_2091d4c4)[iVar2 * 8] != '\0') {
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return -0x25;
    }
  }
  if ((&DAT_2091d4c0)[iVar2 * 2] == 0) {
    return -0x25;
  }
  iVar1 = FUN_20152bb0((&DAT_2091d4c0)[iVar2 * 2],300);
joined_r0x2014da50:
  if (iVar1 != 0) {
    return iVar1;
  }
  (&DAT_2091d4c4)[iVar2 * 8] = *(undefined1 *)(param_1 + 0x11);
  return 0;
}


// ===== FUN_2014da64 @ 2014da64 (108 bytes)

int FUN_2014da64(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4c4)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4c0)[iVar2 * 2] == 0) {
        return -0x26;
      }
      FUN_20150678();
      iVar1 = FUN_201511e8((&DAT_2091d4c0)[iVar2 * 2]);
      if (iVar1 == 0) {
        (&DAT_2091d4c4)[iVar2 * 8] = 0;
      }
      FUN_2015080c();
      return iVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return -0x26;
}


// ===== FUN_2014dad0 @ 2014dad0 (76 bytes)

void FUN_2014dad0(void)

{
  int iVar1;
  int iVar2;
  
  FUN_2014d148(&DAT_2091d4c0,0,0x28,0x200);
  iVar2 = 0;
  do {
    iVar1 = os_create_sem_named(&DAT_20427e4c,"dir_sem");
    if (iVar1 < 1) {
      return;
    }
    (&DAT_2091d4c0)[iVar2 * 2] = iVar1;
    FUN_201511e8();
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}


// ===== FUN_2014db2c @ 2014db2c (64 bytes)

undefined4 FUN_2014db2c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if ((&DAT_2091d4c0)[iVar2 * 2] != 0) {
      uVar1 = FUN_201504d0();
      (&DAT_2091d4c0)[iVar2 * 2] = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return uVar1;
}


// ===== FUN_2014db6c @ 2014db6c (164 bytes)

int FUN_2014db6c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4ec)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4e8)[iVar2 * 2] == 0) {
        return -0x22;
      }
      iVar1 = FUN_20152bb0((&DAT_2091d4e8)[iVar2 * 2],300);
      goto joined_r0x2014dbfc;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  while ((&DAT_2091d4ec)[iVar2 * 8] != '\0') {
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return -0x22;
    }
  }
  if ((&DAT_2091d4e8)[iVar2 * 2] == 0) {
    return -0x22;
  }
  iVar1 = FUN_20152bb0((&DAT_2091d4e8)[iVar2 * 2],300);
joined_r0x2014dbfc:
  if (iVar1 != 0) {
    return iVar1;
  }
  (&DAT_2091d4ec)[iVar2 * 8] = *(undefined1 *)(param_1 + 0x11);
  return 0;
}


// ===== FUN_2014dc10 @ 2014dc10 (108 bytes)

int FUN_2014dc10(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4ec)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4e8)[iVar2 * 2] == 0) {
        return -0x23;
      }
      FUN_20150678();
      iVar1 = FUN_201511e8((&DAT_2091d4e8)[iVar2 * 2]);
      if (iVar1 == 0) {
        (&DAT_2091d4ec)[iVar2 * 8] = 0;
      }
      FUN_2015080c();
      return iVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return -0x23;
}


// ===== FUN_2014dc7c @ 2014dc7c (76 bytes)

void FUN_2014dc7c(void)

{
  int iVar1;
  int iVar2;
  
  FUN_2014d148(&DAT_2091d4e8,0,0x28,0x200);
  iVar2 = 0;
  do {
    iVar1 = os_create_sem_named(&DAT_20427e5c,"fat_sem");
    if (iVar1 < 1) {
      return;
    }
    (&DAT_2091d4e8)[iVar2 * 2] = iVar1;
    FUN_201511e8();
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}


// ===== FUN_2014dcd8 @ 2014dcd8 (64 bytes)

undefined4 FUN_2014dcd8(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if ((&DAT_2091d4e8)[iVar2 * 2] != 0) {
      uVar1 = FUN_201504d0();
      (&DAT_2091d4e8)[iVar2 * 2] = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return uVar1;
}


// ===== FUN_2014dd18 @ 2014dd18 (28 bytes)

undefined4 FUN_2014dd18(int param_1)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    uVar1 = FUN_20152bb0(param_1,1000);
    return uVar1;
  }
  return 0xffffffd6;
}


// ===== FUN_2014dd34 @ 2014dd34 (24 bytes)

undefined4 FUN_2014dd34(int param_1)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    uVar1 = FUN_201511e8(param_1);
    return uVar1;
  }
  return 0xffffffd6;
}


// ===== FUN_2014dd4c @ 2014dd4c (112 bytes)

int FUN_2014dd4c(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_20808ba0;
  while ((piVar2[6] != param_1[6] || (piVar2 == param_1))) {
    iVar1 = *piVar2;
    piVar2 = (int *)*piVar2;
    if (iVar1 == 0) {
      iVar1 = os_create_sem_named(&DAT_20427e6c,"disk_sem");
      if (iVar1 < 1) {
        return iVar1;
      }
      param_1[0x1c] = iVar1;
      iVar1 = FUN_201511e8();
      return iVar1;
    }
  }
  param_1[0x1c] = piVar2[0x1c];
  return 0;
}


// ===== FUN_2014ddd0 @ 2014ddd0 (96 bytes)

undefined4 FUN_2014ddd0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = 0;
  piVar3 = DAT_20808ba0;
  if (0 < param_1[0x1c]) {
    do {
      if ((piVar3[6] == param_1[6]) && (piVar3 != param_1)) {
        piVar3[0x1c] = 0;
      }
      iVar2 = *piVar3;
      piVar3 = (int *)*piVar3;
    } while (iVar2 != 0);
    uVar1 = FUN_201504d0(param_1[0x1c]);
    param_1[0x1c] = 0;
  }
  return uVar1;
}


// ===== FUN_2014de30 @ 2014de30 (44 bytes)

undefined4 FUN_2014de30(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = FUN_20152bb0(DAT_20808bb4,300);
  }
  return uVar1;
}


// ===== FUN_2014de5c @ 2014de5c (40 bytes)

undefined4 FUN_2014de5c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = FUN_201511e8();
  }
  return uVar1;
}


// ===== FUN_2014de84 @ 2014de84 (52 bytes)

void FUN_2014de84(void)

{
  int iVar1;
  
  DAT_20808bb4 = 0;
  iVar1 = os_create_sem_named(&DAT_20427e7c,"filestr_sem");
  if (0 < iVar1) {
    DAT_20808bb4 = iVar1;
    FUN_201511e8();
    return;
  }
  return;
}


// ===== FUN_2014decc @ 2014decc (40 bytes)

undefined4 FUN_2014decc(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = FUN_201504d0();
  }
  return uVar1;
}


// ===== FUN_2014def4 @ 2014def4 (44 bytes)

undefined4 FUN_2014def4(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = FUN_20152bb0(DAT_20808bb8,300);
  }
  return uVar1;
}


// ===== FUN_2014df20 @ 2014df20 (40 bytes)

undefined4 FUN_2014df20(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = FUN_201511e8();
  }
  return uVar1;
}


// ===== FUN_2014df48 @ 2014df48 (52 bytes)

void FUN_2014df48(void)

{
  int iVar1;
  
  DAT_20808bb8 = 0;
  iVar1 = os_create_sem_named(&DAT_20427e8c,"dirstr_sem");
  if (0 < iVar1) {
    DAT_20808bb8 = iVar1;
    FUN_201511e8();
    return;
  }
  return;
}


// ===== FUN_2014df8c @ 2014df8c (40 bytes)

undefined4 FUN_2014df8c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = FUN_201504d0();
  }
  return uVar1;
}


// ===== FUN_2014dfb4 @ 2014dfb4 (40 bytes)

void FUN_2014dfb4(void)

{
  if (0 < DAT_20808bbc) {
    DAT_20808bc0 = FUN_20152bb0(DAT_20808bbc,300);
  }
  return;
}


// ===== FUN_2014dfdc @ 2014dfdc (36 bytes)

void FUN_2014dfdc(void)

{
  if (0 < DAT_20808bbc) {
    DAT_20808bc0 = FUN_201511e8(DAT_20808bbc);
  }
  return;
}


// ===== fsys_init_sem @ 2014e000 (52 bytes)

/* fsys_sem */

void fsys_init_sem(void)

{
  int iVar1;
  
  DAT_20808bbc = 0;
  iVar1 = os_create_sem_named(&DAT_20427e9c,"fsys_sem");
  if (0 < iVar1) {
    DAT_20808bbc = iVar1;
    FUN_201511e8();
    return;
  }
  return;
}


// ===== FUN_2014e04c @ 2014e04c (32 bytes)

undefined4 FUN_2014e04c(int param_1,undefined4 param_2)

{
  if (0 < *(int *)(param_1 + 8)) {
    param_2 = FUN_201504d0();
  }
  return param_2;
}


// ===== FUN_2014e06c @ 2014e06c (64 bytes)

undefined4 FUN_2014e06c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_8;
  
  if (0x10000 < param_1) {
    return 0;
  }
  if ((DAT_20808bc4 < 1) ||
     (local_8 = param_4, iVar1 = FUN_20151aa4(DAT_20808bc4,&local_8,0), iVar1 != 0)) {
    local_8 = 0;
  }
  return local_8;
}


// ===== FUN_2014e0ac @ 2014e0ac (28 bytes)

void FUN_2014e0ac(undefined4 param_1)

{
  if (0 < DAT_20808bc4) {
    FUN_20150c70(DAT_20808bc4,param_1);
    return;
  }
  return;
}


// ===== FUN_2014e0c8 @ 2014e0c8 (36 bytes)

void FUN_2014e0c8(void)

{
  DAT_20808bc4 = FUN_2014e690(&DAT_20427eac,"fsys_mpf");
  if (DAT_20808bc4 < 1) {
    DAT_20808bc4 = 0;
  }
  return;
}


// ===== FUN_2014e100 @ 2014e100 (24 bytes)

void FUN_2014e100(void)

{
  if (0 < DAT_20808bc4) {
    FUN_201502f4();
    return;
  }
  return;
}


// ===== FUN_2014e118 @ 2014e118 (52 bytes)

undefined4 FUN_2014e118(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 local_8;
  
  if ((DAT_20808bc8 < 1) ||
     (local_8 = in_r3, iVar1 = FUN_20151aa4(DAT_20808bc8,&local_8,0), iVar1 != 0)) {
    local_8 = 0;
  }
  return local_8;
}

