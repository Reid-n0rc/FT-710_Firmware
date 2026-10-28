// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb4ebe @ fffb4ebe (148 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4edb) */
/* WARNING: Removing unreachable block (ram,0xfffb4f17) */
/* WARNING: Removing unreachable block (ram,0xfffb4f03) */

void FUN_fffb4ebe(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  byte bStack_e;
  
  uVar2 = FUN_fffb357c(0,2);
  cVar1 = band_of_freq(uVar2);
  if ((param_1 == '\x02') && (cVar1 == '\v')) {
    FUN_fffb3445(uVar2);
  }
  for (bStack_e = 0; bStack_e < 4; bStack_e = bStack_e + 1) {
  }
  return;
}


// ===== FUN_fffb4f52 @ fffb4f52 (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5062) */

void FUN_fffb4f52(void)

{
  FUN_fffb324c(1);
  FUN_fffb3196(1);
  return;
}


// ===== FUN_fffb50d7 @ fffb50d7 (323 bytes)

undefined1 FUN_fffb50d7(byte param_1)

{
  uint uVar1;
  undefined1 local_3;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0xe) {
LAB_fffb51ed:
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a77;
    }
    else {
      local_3 = DAT_00020b68;
    }
  }
  else {
    if (uVar1 - 2 < 2) {
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b68;
      }
      return DAT_00009a9d;
    }
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b68;
      }
      return DAT_00009a4f;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb51ed;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 != '\0') {
            return DAT_00020b68;
          }
          return DAT_00009a8a;
        }
        if (1 < uVar1) {
          return 0;
        }
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b68;
        }
        return DAT_00009a3a;
      }
    }
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a61;
    }
    else {
      local_3 = DAT_00020b68;
    }
  }
  return local_3;
}


// ===== FUN_fffb521a @ fffb521a (98 bytes)

bool FUN_fffb521a(void)

{
  int iVar1;
  uint uVar2;
  byte bStack_9;
  
  iVar1 = FUN_fffb324c(1);
  uVar2 = FUN_fffb3196(1);
  if (1 < uVar2 - 10) {
    if (uVar2 - 2 < 2) {
      bStack_9 = *(byte *)(iVar1 + 0x14);
      goto LAB_fffb526d;
    }
    if (uVar2 - 4 < 2) {
      bStack_9 = *(byte *)(iVar1 + 0x32);
      goto LAB_fffb526d;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 < 2) {
        bStack_9 = *(byte *)(iVar1 + 10);
      }
      else {
        bStack_9 = 0;
      }
      goto LAB_fffb526d;
    }
  }
  bStack_9 = *(byte *)(iVar1 + 0x3c);
LAB_fffb526d:
  return (bStack_9 & 2) != 0;
}


// ===== FUN_fffb527c @ fffb527c (526 bytes)

undefined1 FUN_fffb527c(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uStack_b;
  
  bVar2 = FUN_fffb3196(DAT_00020b6b);
  cVar3 = FUN_fffb3d11(bVar2);
  uStack_b = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fffb5345:
    if (cVar3 == '\0') {
      uStack_b = DAT_00009bed;
    }
    else if (cVar3 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a75;
      }
      else {
        uStack_b = DAT_00020b66;
      }
    }
    else if (cVar3 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a76;
      }
      else {
        uStack_b = DAT_00020b67;
      }
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (cVar3 == '\0') {
        return DAT_00009bee;
      }
      if (cVar3 == '\x01') {
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b66;
        }
        return DAT_00009a4d;
      }
      if (cVar3 != '\x02') {
        return 0;
      }
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b67;
      }
      return DAT_00009a4e;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb5345;
      if (1 < uVar1 - 10) {
        if (1 < uVar1) {
          return 0;
        }
        if (cVar3 == '\0') {
          return DAT_00009bec;
        }
        if (cVar3 == '\x01') {
          if (DAT_00009dc6 != '\0') {
            return DAT_00020b66;
          }
          return DAT_00009a38;
        }
        if (cVar3 != '\x02') {
          return 0;
        }
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b67;
        }
        return DAT_00009a39;
      }
    }
    if (cVar3 == '\0') {
      uStack_b = DAT_00009bef;
    }
    else if (cVar3 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a5f;
      }
      else {
        uStack_b = DAT_00020b66;
      }
    }
    else if (cVar3 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        uStack_b = DAT_00009a60;
      }
      else {
        uStack_b = DAT_00020b67;
      }
    }
  }
  return uStack_b;
}


// ===== FUN_fffb548a @ fffb548a (22 bytes)

char FUN_fffb548a(void)

{
  return DAT_00009aa3 * '\x05' + '\x0f';
}


// ===== FUN_fffb54a0 @ fffb54a0 (140 bytes)

void FUN_fffb54a0(void)

{
  FUN_fffb3196(0);
  return;
}


// ===== FUN_fffb552c @ fffb552c (140 bytes)

void FUN_fffb552c(void)

{
  FUN_fffb3196(0);
  return;
}


// ===== FUN_fffb55b8 @ fffb55b8 (10 bytes)

void FUN_fffb55b8(void)

{
  DAT_00012042 = 0;
  return;
}


// ===== FUN_fffb55c2 @ fffb55c2 (41 bytes)

void FUN_fffb55c2(void)

{
  FUN_fffb55eb();
  FUN_fffb56a5();
  FUN_fffb5786();
  FUN_fffb5874();
  FUN_fffb5976();
  FUN_fffb5d68();
  if (DAT_00012042 != '\0') {
    return;
  }
  DAT_00012042 = 1;
  return;
}


// ===== FUN_fffb55eb @ fffb55eb (186 bytes)

void FUN_fffb55eb(void)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  uint uStack_8;
  
  cVar3 = FUN_fffb3196(1);
  uVar2 = DAT_00020f50;
  bVar4 = FUN_fffb3337(DAT_00020f50);
  uStack_8 = 1 << (bVar4 & 0x1f);
  if (DAT_00020b3f == '\x02') {
    iVar5 = FUN_fffec50f();
    if ((iVar5 == 0) && (iVar5 = FUN_fffec500(), iVar5 == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_8 = uStack_8 | 0x80;
    }
  }
  if (cVar3 == '\x04') {
    uStack_8 = uStack_8 | 0x100;
  }
  iVar5 = FUN_fffb721a();
  if (iVar5 == 1) {
    uStack_8 = uStack_8 | 0x200;
  }
  cVar3 = FUN_fffb3371(uVar2);
  if (cVar3 == '\n') {
    uStack_8 = uStack_8 | 0x400;
  }
  if ((DAT_00020f98 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  FUN_fffb214c(3,uStack_8);
  DAT_00020f98 = uStack_8;
  return;
}


// ===== FUN_fffb56a5 @ fffb56a5 (225 bytes)

void FUN_fffb56a5(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar5 = FUN_fffb324c(DAT_00020b6b);
  bVar2 = *(byte *)(iVar5 + 3) & 3;
  bVar3 = *(byte *)(iVar5 + 5) & 3;
  if (DAT_00020b6b == '\x01') {
    uStack_8 = DAT_00020f50;
  }
  else {
    uStack_8 = FUN_fffb357c(0,2);
    iVar5 = FUN_fffb6fac();
    if (iVar5 != 0) {
      return;
    }
  }
  bVar4 = FUN_fffb32fd(uStack_8);
  uStack_c = 1 << (bVar4 & 0x1f);
  if (bVar2 == 1) {
    uStack_c = uStack_c | 0x8000;
  }
  else if (bVar2 == 2) {
    uStack_c = uStack_c | 0x10000;
  }
  else if (bVar2 != 3) {
    uStack_c = uStack_c | 0x18000;
  }
  if (bVar3 == 3) {
    uStack_c = uStack_c | 0x40000;
  }
  else if (bVar3 == 0) {
    uStack_c = uStack_c | 0x20000;
  }
  uStack_c = uStack_c | 0x200000;
  if ((DAT_00020f9c == uStack_c) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  FUN_fffb214c(2,uStack_c);
  DAT_00020f9c = uStack_c;
  return;
}


// ===== FUN_fffb5786 @ fffb5786 (238 bytes)

void FUN_fffb5786(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uStack_8;
  
  cVar2 = FUN_fffb6fbf();
  uStack_8 = 0;
  if (DAT_00020b3f == '\x02') {
    iVar4 = FUN_fffec50f();
    uVar3 = FUN_fffec500();
    uStack_8 = FUN_fffec51e();
    uStack_8 = uStack_8 | (uVar3 | iVar4 << 8) << 8;
  }
  if ((DAT_00020fa0 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (cVar2 != '\0') {
      FUN_fffb6fd2(0);
      FUN_fffb7011(0);
      DAT_0001b4c5 = '\x01';
      FUN_fffb237a(0x30,0xf);
    }
    FUN_fffb214c(5,uStack_8);
    DAT_00020fa0 = uStack_8;
  }
  if ((DAT_0001b4c5 == '\x01') && (iVar4 = FUN_fffb23f3(0x30), iVar4 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_00020b18 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return;
  }
  DAT_0001b4c5 = 0;
  FUN_fffb6fd2(1);
  FUN_fffb7011(1);
  return;
}


// ===== FUN_fffb5874 @ fffb5874 (258 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb58a4) */
/* WARNING: Removing unreachable block (ram,0xfffb5934) */

void FUN_fffb5874(void)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  undefined4 uVar4;
  ushort local_a;
  
  sVar3 = (ushort)*(byte *)((uint)DAT_0000465b - (uint)DAT_00009ac6) << 2;
  if ((DAT_00020fa4 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(0,3,sVar3);
    DAT_00020fa4 = sVar3;
  }
  uVar4 = FUN_fffb357c(0,2);
  bVar2 = FUN_fffb33ab(uVar4);
  if (bVar2 < 5) {
    local_a = (ushort)bRam0000466f;
  }
  else if (bVar2 < 7) {
    local_a = (ushort)bRam00004670;
  }
  else if (bVar2 < 9) {
    local_a = (ushort)bRam00004671;
  }
  else if (bVar2 < 0xb) {
    local_a = (ushort)bRam00004672;
  }
  else {
    local_a = (ushort)bRam00004673;
  }
  sVar3 = local_a << 2;
  if ((DAT_00020fa6 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(0,5,sVar3);
    DAT_00020fa6 = sVar3;
    return;
  }
  return;
}


// ===== FUN_fffb5976 @ fffb5976 (1010 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5b07) */
/* WARNING: Removing unreachable block (ram,0xfffb5a6c) */
/* WARNING: Removing unreachable block (ram,0xfffb5bbc) */
/* WARNING: Removing unreachable block (ram,0xfffb5caf) */
/* WARNING: Removing unreachable block (ram,0xfffb5d26) */
/* WARNING: Removing unreachable block (ram,0xfffb5aaf) */
/* WARNING: Removing unreachable block (ram,0xfffb5bff) */
/* WARNING: Removing unreachable block (ram,0xfffb5c42) */

void FUN_fffb5976(void)

{
  bool bVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  short sVar6;
  float fVar7;
  ushort uStack_14;
  ushort uStack_12;
  ushort uStack_10;
  ushort uStack_e;
  ushort uStack_c;
  ushort uStack_a;
  
  uVar2 = DAT_00020f50;
  bVar3 = (byte)(DAT_00020b12 >> 4);
  uVar4 = FUN_fffb3371(DAT_00020f50);
  switch(uVar4) {
  case 0:
    uStack_c = (ushort)bRam00004743;
    uStack_e = (ushort)bRam00004693;
    break;
  case 1:
    uStack_c = (ushort)bRam00004744;
    uStack_e = (ushort)bRam00004694;
    break;
  case 2:
    uStack_c = (ushort)bRam00004745;
    uStack_e = (ushort)bRam00004695;
    break;
  case 3:
    uStack_c = (ushort)bRam00004746;
    uStack_e = (ushort)bRam00004696;
    break;
  case 4:
    uStack_c = (ushort)bRam00004747;
    uStack_e = (ushort)bRam00004697;
    break;
  case 5:
    uStack_c = (ushort)bRam00004748;
    uStack_e = (ushort)bRam00004698;
    break;
  case 6:
    uStack_c = (ushort)bRam00004749;
    uStack_e = (ushort)bRam00004699;
    break;
  case 7:
    uStack_c = (ushort)bRam0000474a;
    uStack_e = (ushort)bRam0000469a;
    break;
  case 8:
    uStack_c = (ushort)bRam0000474b;
    uStack_e = (ushort)bRam0000469b;
    break;
  case 9:
    uStack_c = (ushort)bRam0000474c;
    uStack_e = (ushort)bRam0000469c;
    break;
  default:
    uStack_c = (ushort)bRam0000474d;
    uStack_e = (ushort)bRam0000469d;
  }
  sVar6 = uStack_c << 2;
  if ((DAT_00020fa8 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(4,1,sVar6);
    DAT_00020fa8 = sVar6;
  }
  sVar6 = uStack_e << 2;
  if ((DAT_00020fb6 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(4,10,sVar6);
    DAT_00020fb6 = sVar6;
  }
  bVar5 = FUN_fffb4062();
  sVar6 = FUN_fffb667a(uVar4,bVar5);
  fVar7 = ROUND((float)(((int)sVar6 & 0x3fffU) << 2) * *(float *)(&DAT_fff88a68 + (uint)bVar5 * 4) +
                0.5);
  sVar6 = SUB42(fVar7,0);
  if ((DAT_00020faa == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(4,2,(uint)fVar7 & 0xffff);
    DAT_00020faa = sVar6;
  }
  bVar5 = FUN_fffb3337(uVar2);
  if (bVar5 == 0) {
    uStack_10 = (ushort)bRam0000468c;
    uStack_12 = (ushort)bRam0000468b;
    uStack_14 = (ushort)bRam0000468a;
  }
  else if (bVar5 < 6) {
    uStack_10 = (ushort)bRam0000468f;
    uStack_12 = (ushort)bRam0000468e;
    uStack_14 = (ushort)bRam0000468d;
  }
  else {
    uStack_10 = (ushort)bRam00004692;
    uStack_12 = (ushort)bRam00004691;
    uStack_14 = (ushort)bRam00004690;
  }
  sVar6 = uStack_10 << 2;
  if ((DAT_00020fac == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(4,3,sVar6);
    DAT_00020fac = sVar6;
  }
  sVar6 = uStack_12 << 2;
  if ((DAT_00020fae == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(4,4,sVar6);
    DAT_00020fae = sVar6;
  }
  sVar6 = uStack_14 << 2;
  if ((DAT_00020fb0 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(4,5,sVar6);
    DAT_00020fb0 = sVar6;
  }
  if (bVar3 < DAT_0000465a) {
    uStack_a = 0xad;
  }
  else if (DAT_0000465a + 10 < (uint)bVar3) {
    uStack_a = 0;
  }
  else {
    uStack_a = DAT_00020fb2 >> 2;
  }
  uStack_a = uStack_a << 2;
  if ((DAT_00020fb2 == uStack_a) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffb1fef(4,6,uStack_a);
    DAT_00020fb2 = uStack_a;
  }
  if (DAT_00020b3c == '\x03') {
    uStack_a = 0xff;
  }
  else if (DAT_00020b3c == '\x02') {
    uStack_a = 0x51;
  }
  else if (DAT_00020b3c == '\x01') {
    uStack_a = 0x60;
  }
  else {
    uStack_a = 0;
  }
  if (DAT_00009ab8 != '\x03') {
    uStack_a = 0;
  }
  sVar6 = uStack_a << 2;
  if ((DAT_00020fb4 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  FUN_fffb1fef(4,7,sVar6);
  DAT_00020fb4 = sVar6;
  return;
}


// ===== FUN_fffb5d68 @ fffb5d68 (2322 bytes)

void FUN_fffb5d68(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  char cStack_f;
  char cStack_e;
  char cStack_d;
  char cStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  char cStack_8;
  char cStack_7;
  
  iVar8 = FUN_fffb4219();
  bVar4 = FUN_fffb3196(0);
  bVar5 = FUN_fffb2dfe();
  FUN_fffb3d11(bVar4);
  cVar7 = DAT_00020b6b;
  bVar2 = false;
  cStack_e = '\0';
  cStack_d = '\0';
  cStack_b = '\0';
  uStack_a = 0;
  uStack_9 = 0;
  cStack_8 = '\0';
  cStack_f = DAT_00020b31;
  cVar6 = FUN_fffb3d11(bVar4);
  uVar1 = (uint)bVar4;
  if (uVar1 == 0xe) {
LAB_fffb6009:
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a71;
      uStack_a = DAT_00009a72;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar6 == '\0') {
      cStack_b = DAT_00009bed;
    }
    else if (cVar6 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a75;
      }
      else {
        cStack_b = DAT_00020b66;
      }
    }
    else if (cVar6 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a76;
      }
      else {
        cStack_b = DAT_00020b67;
      }
    }
  }
  else if (uVar1 - 2 < 2) {
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a9b;
      uStack_a = DAT_00009a9c;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
  }
  else if (uVar1 - 4 < 2) {
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a49;
      uStack_a = DAT_00009a4a;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar6 == '\0') {
      cStack_b = DAT_00009bee;
    }
    else if (cVar6 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a4d;
      }
      else {
        cStack_b = DAT_00020b66;
      }
    }
    else if (cVar6 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a4e;
      }
      else {
        cStack_b = DAT_00020b67;
      }
    }
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb6009;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 == '\0') {
            uStack_9 = DAT_00009a88;
            uStack_a = DAT_00009a89;
          }
          else {
            uStack_9 = DAT_00020b62;
            uStack_a = DAT_00020b63;
          }
        }
        else if (uVar1 < 2) {
          if (DAT_00009dc6 == '\0') {
            uStack_9 = DAT_00009a34;
            uStack_a = DAT_00009a35;
          }
          else {
            uStack_9 = DAT_00020b62;
            uStack_a = DAT_00020b63;
          }
          if (cVar6 == '\0') {
            cStack_b = DAT_00009bec;
          }
          else if (cVar6 == '\x01') {
            if (DAT_00009dc6 == '\0') {
              cStack_b = DAT_00009a38;
            }
            else {
              cStack_b = DAT_00020b66;
            }
          }
          else if (cVar6 == '\x02') {
            if (DAT_00009dc6 == '\0') {
              cStack_b = DAT_00009a39;
            }
            else {
              cStack_b = DAT_00020b67;
            }
          }
        }
        goto LAB_fffb612b;
      }
    }
    if (DAT_00009dc6 == '\0') {
      uStack_9 = DAT_00009a5c;
      uStack_a = DAT_00009a5d;
    }
    else {
      uStack_9 = DAT_00020b62;
      uStack_a = DAT_00020b63;
    }
    if (cVar6 == '\0') {
      cStack_b = DAT_00009bef;
    }
    else if (cVar6 == '\x01') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a5f;
      }
      else {
        cStack_b = DAT_00020b66;
      }
    }
    else if (cVar6 == '\x02') {
      if (DAT_00009dc6 == '\0') {
        cStack_b = DAT_00009a60;
      }
      else {
        cStack_b = DAT_00020b67;
      }
    }
  }
LAB_fffb612b:
  cVar6 = FUN_fffb418a(cVar7);
  cVar7 = DAT_00020ba8;
  switch(iVar8) {
  case 0:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    bVar2 = true;
    break;
  case 1:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    bVar2 = true;
    break;
  case 2:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar6;
    break;
  case 3:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar6;
    break;
  case 4:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    cStack_e = cVar6;
    break;
  case 5:
    cStack_8 = DAT_00009dc1;
    cStack_d = -1;
    cStack_b = FUN_fffb34cf(0x32);
    break;
  case 6:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_d = -1;
    cStack_b = FUN_fffb34cf(0x1a);
    cStack_e = cVar6;
    break;
  case 7:
    cStack_8 = FUN_fffb34f9(cVar6);
    cStack_d = -1;
    cStack_b = FUN_fffb34cf(0x1a);
    break;
  case 8:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    FUN_fffb527c();
    cStack_b = FUN_fffb34cf();
    bVar2 = true;
    break;
  case 9:
    iVar9 = FUN_fffb730a();
    if (iVar9 == 1) {
      cStack_8 = FUN_fffb354d(cVar7);
      cStack_f = FUN_fffb3564(cVar7);
    }
    else {
      cStack_8 = FUN_fffb34ba();
    }
    cStack_b = FUN_fffb34cf(0x32);
    bVar2 = true;
    break;
  case 10:
    cStack_8 = FUN_fffb34f9(cVar6);
    cStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xb:
  case 0xc:
    cStack_8 = DAT_00009dc1;
    cStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xd:
    cStack_8 = FUN_fffb34f9(cVar6);
    FUN_fffb527c();
    cStack_b = FUN_fffb34cf();
    break;
  case 0xe:
    cStack_8 = DAT_00009dc1;
    cStack_b = FUN_fffb350e(DAT_00009dc2);
  }
  if ((bVar5 - 1 < 3) || (bVar5 - 5 < 4)) {
    cStack_d = '\0';
    cStack_e = DAT_00009ab5;
    if (DAT_00009ab5 != '\0') goto LAB_fffb6432;
  }
  if (DAT_00020ba8 == '\0') {
    if ((iVar8 == 4) || (iVar8 == 7)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      iVar8 = FUN_fffb418a(DAT_00020b6b);
      if (iVar8 == 0) {
        FUN_fffb71f5();
      }
    }
    else if (bVar2) {
      FUN_fffb71f5();
    }
  }
LAB_fffb6432:
  if ((DAT_00020b18 < 3) && (iVar8 = FUN_fffb23f3(0xe), iVar8 != 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((!bVar2) && (DAT_00020b3d != '\x02')) {
    if ((DAT_00020fbd == cStack_8) && (DAT_00012042 != '\0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      FUN_fffb208d(1,cStack_8);
      DAT_00020fbd = cStack_8;
    }
    if ((DAT_00020fbc == cStack_8) && (DAT_00012042 != '\0')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      FUN_fffb208d(5,cStack_8);
      DAT_00020fbc = cStack_8;
    }
  }
  cStack_7 = FUN_fffb34f9(uStack_9);
  if (DAT_00020b6b != '\0') {
    cStack_7 = '\0';
  }
  if ((DAT_00020fb8 == cStack_7) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_fffb208d(2,cStack_7);
    DAT_00020fb8 = cStack_7;
  }
  cVar7 = FUN_fffb34f9(uStack_a);
  if ((DAT_00020fb9 == cVar7) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_fffb208d(3,cVar7);
    DAT_00020fb9 = cVar7;
  }
  if ((DAT_00020fba == cStack_b) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_fffb208d(4,cStack_b);
    DAT_00020fba = cStack_b;
  }
  if ((DAT_00020fbe == cStack_d) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_fffb208d(6,cStack_d);
    DAT_00020fbe = cStack_d;
  }
  cVar7 = FUN_fffb34f9(cStack_e);
  if ((DAT_00020fbf == cVar7) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_fffb208d(7,cVar7);
    DAT_00020fbf = cVar7;
  }
  if ((DAT_00020fbb == cStack_f) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    FUN_fffb208d(8,cStack_f);
    DAT_00020fbb = cStack_f;
    return;
  }
  return;
}


// ===== FUN_fffb667a @ fffb667a (1636 bytes)

char FUN_fffb667a(undefined1 param_1,byte param_2)

{
  uint uVar1;
  int in_stack_0000000c;
  undefined1 local_e;
  char local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  
  switch(param_1) {
  case 0:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_0000469e;
      local_c = DAT_0000469e;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046a7;
          local_c = DAT_000046aa;
        }
        else {
          local_a = 10;
          local_b = DAT_000046a4;
          local_c = DAT_000046a7;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046a1;
        local_c = DAT_000046a4;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_0000469e;
      local_c = DAT_000046a1;
    }
    local_e = DAT_0000469f;
    break;
  case 1:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046ad;
      local_c = DAT_000046ad;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046b6;
          local_c = DAT_000046b9;
        }
        else {
          local_a = 10;
          local_b = DAT_000046b3;
          local_c = DAT_000046b6;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046b0;
        local_c = DAT_000046b3;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046ad;
      local_c = DAT_000046b0;
    }
    local_e = DAT_000046ae;
    break;
  case 2:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046bc;
      local_c = DAT_000046bc;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046c5;
          local_c = DAT_000046c8;
        }
        else {
          local_a = 10;
          local_b = DAT_000046c2;
          local_c = DAT_000046c5;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046bf;
        local_c = DAT_000046c2;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046bc;
      local_c = DAT_000046bf;
    }
    local_e = DAT_000046bd;
    break;
  case 3:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046cb;
      local_c = DAT_000046cb;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046d4;
          local_c = DAT_000046d7;
        }
        else {
          local_a = 10;
          local_b = DAT_000046d1;
          local_c = DAT_000046d4;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046ce;
        local_c = DAT_000046d1;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046cb;
      local_c = DAT_000046ce;
    }
    local_e = DAT_000046cc;
    break;
  case 4:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046da;
      local_c = DAT_000046da;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046e3;
          local_c = DAT_000046e6;
        }
        else {
          local_a = 10;
          local_b = DAT_000046e0;
          local_c = DAT_000046e3;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046dd;
        local_c = DAT_000046e0;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046da;
      local_c = DAT_000046dd;
    }
    local_e = DAT_000046db;
    break;
  case 5:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046e9;
      local_c = DAT_000046e9;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_000046f2;
          local_c = DAT_000046f5;
        }
        else {
          local_a = 10;
          local_b = DAT_000046ef;
          local_c = DAT_000046f2;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046ec;
        local_c = DAT_000046ef;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046e9;
      local_c = DAT_000046ec;
    }
    local_e = DAT_000046ea;
    break;
  case 6:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_000046f8;
      local_c = DAT_000046f8;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_00004701;
          local_c = DAT_00004704;
        }
        else {
          local_a = 10;
          local_b = DAT_000046fe;
          local_c = DAT_00004701;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_000046fb;
        local_c = DAT_000046fe;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_000046f8;
      local_c = DAT_000046fb;
    }
    local_e = DAT_000046f9;
    break;
  case 7:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004707;
      local_c = DAT_00004707;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_00004710;
          local_c = DAT_00004713;
        }
        else {
          local_a = 10;
          local_b = DAT_0000470d;
          local_c = DAT_00004710;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_0000470a;
        local_c = DAT_0000470d;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004707;
      local_c = DAT_0000470a;
    }
    local_e = DAT_00004708;
    break;
  case 8:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004716;
      local_c = DAT_00004716;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_0000471f;
          local_c = DAT_00004722;
        }
        else {
          local_a = 10;
          local_b = DAT_0000471c;
          local_c = DAT_0000471f;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_00004719;
        local_c = DAT_0000471c;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004716;
      local_c = DAT_00004719;
    }
    local_e = DAT_00004717;
    break;
  case 9:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004725;
      local_c = DAT_00004725;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_0000472e;
          local_c = DAT_00004731;
        }
        else {
          local_a = 10;
          local_b = DAT_0000472b;
          local_c = DAT_0000472e;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_00004728;
        local_c = DAT_0000472b;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004725;
      local_c = DAT_00004728;
    }
    local_e = DAT_00004726;
    break;
  default:
    if (param_2 == 100) {
      local_a = 0;
      local_b = DAT_00004737;
      local_c = DAT_00004737;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_a = 5;
          local_b = DAT_0000473d;
          local_c = DAT_00004740;
        }
        else {
          local_a = 10;
          local_b = DAT_0000473a;
          local_c = DAT_0000473d;
        }
      }
      else {
        local_a = 0x1e;
        local_b = DAT_00004737;
        local_c = DAT_0000473a;
      }
    }
    else {
      local_a = 0x32;
      local_b = DAT_00004737;
      local_c = DAT_00004737;
    }
    local_e = DAT_00004738;
  }
  DAT_00020b1e = local_e;
  if (local_b < local_c) {
    in_stack_0000000c = ((uint)local_c - (uint)local_b) * in_stack_0000000c;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (uVar1 != 0x80000000 || in_stack_0000000c != -1)) {
      in_stack_0000000c = in_stack_0000000c / (int)uVar1;
    }
    local_d = (char)in_stack_0000000c;
  }
  else {
    in_stack_0000000c = ((uint)local_b - (uint)local_c) * in_stack_0000000c;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (uVar1 != 0x80000000 || in_stack_0000000c != -1)) {
      in_stack_0000000c = in_stack_0000000c / (int)uVar1;
    }
    local_d = (char)in_stack_0000000c;
  }
  local_d = local_d + local_c;
  return local_d;
}


// ===== FUN_fffb6cde @ fffb6cde (120 bytes)

void FUN_fffb6cde(void)

{
  byte bVar1;
  byte bStack_1;
  
  DAT_00020b18 = 4;
  DAT_00020b6b = 0;
  DAT_0001204d = 0;
  FUN_fffb237a(0x13,0x9c4);
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 8;
  DAT_00020b44 = 1;
  for (bStack_1 = 0; bStack_1 < 4; bStack_1 = bStack_1 + 1) {
    DAT_00020f60 = DAT_00020f60 << 8 | (uint)(byte)(&DAT_00009e82)[bStack_1];
  }
  return;
}


// ===== FUN_fffb6d56 @ fffb6d56 (173 bytes)

void FUN_fffb6d56(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_fffb23f3(0x2a);
  if (((iVar1 != 0) && (uVar2 = FUN_fffb722b(), uVar2 != DAT_00020b44)) && (DAT_00020b18 == '\b')) {
    FUN_fffb7243(DAT_00020b44);
  }
  FUN_fffb73dd();
  FUN_fffb7b43();
  FUN_fffb8d77();
  FUN_fffb9605();
  iVar1 = FUN_fffb4b28();
  if (iVar1 != 1) {
    if (DAT_00020b30 == '\x02') {
      DAT_00009dc5 = 0;
      FUN_fffd3d03();
      if (DAT_00020bbe == '\0') {
        FUN_fffb02cf();
      }
      do {
        iVar1 = sci1_tx_end();
      } while (iVar1 == 0);
      FUN_fffb3e55();
    }
    iVar1 = FUN_fffb267f();
    if (iVar1 == 1) {
      if (DAT_00020b86 == '\0') {
        DAT_00020b87 = 1;
        return;
      }
    }
    else if (DAT_00020b86 != '\0') {
      DAT_00020b87 = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffb6e03 @ fffb6e03 (15 bytes)

undefined1 FUN_fffb6e03(void)

{
  return DAT_00012043;
}


// ===== FUN_fffb6e12 @ fffb6e12 (15 bytes)

undefined1 FUN_fffb6e12(void)

{
  return DAT_00012044;
}


// ===== FUN_fffb6e21 @ fffb6e21 (15 bytes)

undefined1 FUN_fffb6e21(void)

{
  return DAT_00012045;
}


// ===== FUN_fffb6e30 @ fffb6e30 (15 bytes)

undefined1 FUN_fffb6e30(void)

{
  return DAT_00012046;
}


// ===== FUN_fffb6e3f @ fffb6e3f (15 bytes)

undefined1 FUN_fffb6e3f(void)

{
  return DAT_00012047;
}


// ===== FUN_fffb6e4e @ fffb6e4e (14 bytes)

void FUN_fffb6e4e(void)

{
  return;
}


// ===== FUN_fffb6e5c @ fffb6e5c (14 bytes)

void FUN_fffb6e5c(void)

{
  return;
}


// ===== FUN_fffb6e6a @ fffb6e6a (46 bytes)

undefined1 FUN_fffb6e6a(void)

{
  undefined1 local_3;
  
  if (DAT_00009af6 == '\0') {
    local_3 = DAT_00012048;
  }
  else {
    local_3 = DAT_0001204b;
  }
  return local_3;
}


// ===== FUN_fffb6e98 @ fffb6e98 (15 bytes)

undefined1 FUN_fffb6e98(void)

{
  return DAT_00012049;
}


// ===== FUN_fffb6ea7 @ fffb6ea7 (15 bytes)

undefined1 FUN_fffb6ea7(void)

{
  return DAT_0001204a;
}


// ===== FUN_fffb6eb6 @ fffb6eb6 (15 bytes)

undefined1 FUN_fffb6eb6(void)

{
  return DAT_0001204c;
}


// ===== FUN_fffb6ec5 @ fffb6ec5 (15 bytes)

undefined1 FUN_fffb6ec5(void)

{
  return DAT_0001204d;
}


// ===== FUN_fffb6ed4 @ fffb6ed4 (31 bytes)

bool FUN_fffb6ed4(void)

{
  char cVar1;
  
  cVar1 = DAT_0008c048;
  return -1 < cVar1;
}


// ===== FUN_fffb6ef3 @ fffb6ef3 (24 bytes)

bool FUN_fffb6ef3(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c041;
  return (bVar1 & 0x40) == 0;
}


// ===== FUN_fffb6f0b @ fffb6f0b (31 bytes)

bool FUN_fffb6f0b(void)

{
  char cVar1;
  
  cVar1 = DAT_0008c041;
  return -1 < cVar1;
}


// ===== FUN_fffb6f2a @ fffb6f2a (19 bytes)

byte FUN_fffb6f2a(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return bVar1 >> 1 & 1;
}


// ===== FUN_fffb6f76 @ fffb6f76 (30 bytes)

bool FUN_fffb6f76(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c045;
  return (bVar1 >> 5 & 1) == 1;
}


// ===== FUN_fffb6fac @ fffb6fac (19 bytes)

byte FUN_fffb6fac(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  return bVar1 >> 3 & 1;
}


// ===== FUN_fffb6fbf @ fffb6fbf (19 bytes)

byte FUN_fffb6fbf(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02a;
  return bVar1 >> 2 & 1;
}


// ===== FUN_fffb6fd2 @ fffb6fd2 (63 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7007) */

void FUN_fffb6fd2(byte param_1)

{
  byte bVar1;
  bool bVar2;
  byte local_1;
  
  bVar1 = DAT_0008c041;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = DAT_0008c027, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xfb | (local_1 & 1) << 2;
  return;
}


// ===== FUN_fffb7011 @ fffb7011 (64 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7046) */

void FUN_fffb7011(byte param_1)

{
  byte bVar1;
  bool bVar2;
  byte local_1;
  
  bVar1 = DAT_0008c041;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = DAT_0008c027, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xef | (local_1 & 1) << 4;
  return;
}


// ===== FUN_fffb7051 @ fffb7051 (22 bytes)

void FUN_fffb7051(char param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0x7f | param_1 << 7;
  return;
}


// ===== FUN_fffb7067 @ fffb7067 (25 bytes)

void FUN_fffb7067(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== FUN_fffb7080 @ fffb7080 (24 bytes)

void FUN_fffb7080(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfd | (param_1 & 1) << 1;
  return;
}


// ===== FUN_fffb7098 @ fffb7098 (24 bytes)

void FUN_fffb7098(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== FUN_fffb70b0 @ fffb70b0 (25 bytes)

void FUN_fffb70b0(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xef | (param_1 & 1) << 4;
  return;
}


// ===== FUN_fffb70c9 @ fffb70c9 (22 bytes)

void FUN_fffb70c9(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== FUN_fffb70df @ fffb70df (24 bytes)

void FUN_fffb70df(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c028;
  DAT_0008c028 = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== FUN_fffb70f7 @ fffb70f7 (25 bytes)

void FUN_fffb70f7(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c028;
  DAT_0008c028 = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== FUN_fffb7110 @ fffb7110 (12 bytes)

void FUN_fffb7110(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c001;
  DAT_0008c001 = bVar1 | 8;
  return;
}


// ===== FUN_fffb711c @ fffb711c (12 bytes)

void FUN_fffb711c(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c001;
  DAT_0008c001 = bVar1 | 4;
  return;
}

