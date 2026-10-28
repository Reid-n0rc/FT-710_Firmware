// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2011e290 @ 2011e290 (40 bytes)

void FUN_2011e290(void)

{
  FUN_20157138(&DAT_e800d800,0,7,0x80);
  DAT_2080041a = 1;
  return;
}


// ===== FUN_2011e2b8 @ 2011e2b8 (40 bytes)

void FUN_2011e2b8(void)

{
  FUN_20157138(&DAT_e800e000,0,7,0x80);
  DAT_2080041b = 1;
  return;
}


// ===== FUN_2011e2e0 @ 2011e2e0 (40 bytes)

void FUN_2011e2e0(void)

{
  FUN_20157138(&DAT_e800e800,0,7,0x80);
  DAT_2080041c = 1;
  return;
}


// ===== FUN_2011e308 @ 2011e308 (40 bytes)

void FUN_2011e308(void)

{
  FUN_20157138(&DAT_e800c800,0,5,0x20);
  DAT_2080041d = 1;
  return;
}


// ===== FUN_2011e330 @ 2011e330 (40 bytes)

void FUN_2011e330(void)

{
  FUN_20157138(&DAT_e800d000,0,5,0x20);
  DAT_2080041e = 1;
  return;
}


// ===== FUN_2011e358 @ 2011e358 (40 bytes)

void FUN_2011e358(void)

{
  FUN_20157138(&DAT_e800d800,0,5,0x20);
  DAT_2080041f = 1;
  return;
}


// ===== FUN_2011e380 @ 2011e380 (40 bytes)

void FUN_2011e380(void)

{
  FUN_20157138(&DAT_e800e000,0,5,0x20);
  DAT_20800420 = 1;
  return;
}


// ===== FUN_2011e3a8 @ 2011e3a8 (40 bytes)

void FUN_2011e3a8(void)

{
  FUN_20157138(&DAT_e800e800,0,5,0x20);
  DAT_20800421 = 1;
  return;
}


// ===== FUN_2011e3d0 @ 2011e3d0 (44 bytes)

void FUN_2011e3d0(void)

{
  FUN_20157138(&DAT_e800c800,1,5,0x20);
  do {
  } while (DAT_2080041d == '\0');
  return;
}


// ===== FUN_2011e3fc @ 2011e3fc (328 bytes)

void FUN_2011e3fc(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1;
  uVar1 = FUN_20157174(&DAT_e800c820,4,0x30);
  iVar2 = FUN_20157174(&DAT_e800c80b,5,0x60);
  if (iVar2 == 3) {
    FUN_20157138(&DAT_e800c820,2,4,0x30,uVar1,uVar3);
  }
  else if (iVar2 == 2) {
    FUN_20157138(&DAT_e800c820,1,4,0x30,uVar1,uVar3);
  }
  else {
    FUN_20157138(&DAT_e800c820,0,4,0x30,uVar1,uVar3);
  }
  FUN_20157138(&DAT_e800c800,1,7,0x80,uVar1,uVar3);
  uVar3 = param_1;
  while (uVar3 != 0) {
    FUN_2011e3d0();
    FUN_2011e168();
    if (iVar2 == 3) {
      DAT_e800c804 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (iVar2 == 2) {
      DAT_e800c804._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
      DAT_e800c804._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = FUN_20157184(&DAT_e800c822,0,0x3f);
    } while (uVar3 < param_1);
    FUN_2011e1f0();
  }
  else {
    do {
    } while (DAT_20800418 == '\0');
  }
  FUN_20157138(&DAT_e800c820,uVar1,4,0x30);
  return;
}


// ===== FUN_2011e544 @ 2011e544 (44 bytes)

void FUN_2011e544(void)

{
  FUN_20157138(&DAT_e800d000,1,5,0x20);
  do {
  } while (DAT_2080041e == '\0');
  return;
}


// ===== FUN_2011e570 @ 2011e570 (320 bytes)

void FUN_2011e570(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_20157174(&DAT_e800d020,4,0x30,param_4,param_4);
  iVar2 = FUN_20157174(&DAT_e800d00b,5,0x60);
  if (iVar2 == 3) {
    FUN_20157138(&DAT_e800d020,2,4,0x30);
  }
  else if (iVar2 == 2) {
    FUN_20157138(&DAT_e800d020,1,4,0x30);
  }
  else {
    FUN_20157138(&DAT_e800d020,0,4,0x30);
  }
  FUN_20157138(&DAT_e800d000,1,7,0x80);
  uVar3 = param_1;
  while (uVar3 != 0) {
    FUN_2011e544();
    FUN_2011e178();
    if (iVar2 == 3) {
      DAT_e800d004 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (iVar2 == 2) {
      DAT_e800d004._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
      DAT_e800d004._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = FUN_20157184(&DAT_e800d022,0,0x3f);
    } while (uVar3 < param_1);
    FUN_2011e240();
  }
  else {
    do {
    } while (DAT_20800419 == '\0');
  }
  FUN_20157138(&DAT_e800d020,uVar1,4,0x30);
  return;
}


// ===== FUN_2011e6b0 @ 2011e6b0 (44 bytes)

void FUN_2011e6b0(void)

{
  FUN_20157138(&DAT_e800d800,1,5,0x20);
  do {
  } while (DAT_2080041f == '\0');
  return;
}


// ===== FUN_2011e6dc @ 2011e6dc (328 bytes)

void FUN_2011e6dc(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1;
  uVar1 = FUN_20157174(&DAT_e800d820,4,0x30);
  iVar2 = FUN_20157174(&DAT_e800d80b,5,0x60);
  if (iVar2 == 3) {
    FUN_20157138(&DAT_e800d820,2,4,0x30,uVar1,uVar3);
  }
  else if (iVar2 == 2) {
    FUN_20157138(&DAT_e800d820,1,4,0x30,uVar1,uVar3);
  }
  else {
    FUN_20157138(&DAT_e800d820,0,4,0x30,uVar1,uVar3);
  }
  FUN_20157138(&DAT_e800d800,1,7,0x80,uVar1,uVar3);
  uVar3 = param_1;
  while (uVar3 != 0) {
    FUN_2011e6b0();
    FUN_2011e188();
    if (iVar2 == 3) {
      DAT_e800d804 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (iVar2 == 2) {
      DAT_e800d804._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
      DAT_e800d804._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = FUN_20157184(&DAT_e800d822,0,0x3f);
    } while (uVar3 < param_1);
    FUN_2011e290();
  }
  else {
    do {
    } while (DAT_2080041a == '\0');
  }
  FUN_20157138(&DAT_e800d820,uVar1,4,0x30);
  return;
}


// ===== FUN_2011e824 @ 2011e824 (44 bytes)

void FUN_2011e824(void)

{
  FUN_20157138(&DAT_e800e000,1,5,0x20);
  do {
  } while (DAT_20800420 == '\0');
  return;
}


// ===== FUN_2011e850 @ 2011e850 (320 bytes)

void FUN_2011e850(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_20157174(&DAT_e800e020,4,0x30,param_4,param_4);
  iVar2 = FUN_20157174(&DAT_e800e00b,5,0x60);
  if (iVar2 == 3) {
    FUN_20157138(&DAT_e800e020,2,4,0x30);
  }
  else if (iVar2 == 2) {
    FUN_20157138(&DAT_e800e020,1,4,0x30);
  }
  else {
    FUN_20157138(&DAT_e800e020,0,4,0x30);
  }
  FUN_20157138(&DAT_e800e000,1,7,0x80);
  uVar3 = param_1;
  while (uVar3 != 0) {
    FUN_2011e824();
    FUN_2011e198();
    if (iVar2 == 3) {
      DAT_e800e004 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (iVar2 == 2) {
      DAT_e800e004._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
      DAT_e800e004._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = FUN_20157184(&DAT_e800e022,0,0x3f);
    } while (uVar3 < param_1);
    FUN_2011e2b8();
  }
  else {
    do {
    } while (DAT_2080041b == '\0');
  }
  FUN_20157138(&DAT_e800e020,uVar1,4,0x30);
  return;
}


// ===== FUN_2011e990 @ 2011e990 (44 bytes)

void FUN_2011e990(void)

{
  FUN_20157138(&DAT_e800e800,1,5,0x20);
  do {
  } while (DAT_20800421 == '\0');
  return;
}


// ===== FUN_2011e9bc @ 2011e9bc (328 bytes)

void FUN_2011e9bc(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1;
  uVar1 = FUN_20157174(&DAT_e800e820,4,0x30);
  iVar2 = FUN_20157174(&DAT_e800e80b,5,0x60);
  if (iVar2 == 3) {
    FUN_20157138(&DAT_e800e820,2,4,0x30,uVar1,uVar3);
  }
  else if (iVar2 == 2) {
    FUN_20157138(&DAT_e800e820,1,4,0x30,uVar1,uVar3);
  }
  else {
    FUN_20157138(&DAT_e800e820,0,4,0x30,uVar1,uVar3);
  }
  FUN_20157138(&DAT_e800e800,1,7,0x80,uVar1,uVar3);
  uVar3 = param_1;
  while (uVar3 != 0) {
    FUN_2011e990();
    FUN_2011e1e0();
    if (iVar2 == 3) {
      DAT_e800e804 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (iVar2 == 2) {
      DAT_e800e804._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
      DAT_e800e804._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = FUN_20157184(&DAT_e800e822,0,0x3f);
    } while (uVar3 < param_1);
    FUN_2011e2e0();
  }
  else {
    do {
    } while (DAT_2080041c == '\0');
  }
  FUN_20157138(&DAT_e800e820,uVar1,4,0x30);
  return;
}


// ===== FUN_2011eb58 @ 2011eb58 (36 bytes)

void FUN_2011eb58(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_20157174(&DAT_e800c803,6,0x40);
  } while (iVar1 == 0);
  return;
}


// ===== FUN_2011eb7c @ 2011eb7c (36 bytes)

void FUN_2011eb7c(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_20157174(&DAT_e800d003,6,0x40);
  } while (iVar1 == 0);
  return;
}


// ===== FUN_2011eba0 @ 2011eba0 (36 bytes)

void FUN_2011eba0(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_20157174(&DAT_e800d803,6,0x40);
  } while (iVar1 == 0);
  return;
}


// ===== FUN_2011ebc4 @ 2011ebc4 (36 bytes)

void FUN_2011ebc4(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_20157174(&DAT_e800e003,6,0x40);
  } while (iVar1 == 0);
  return;
}


// ===== FUN_2011ebe8 @ 2011ebe8 (36 bytes)

void FUN_2011ebe8(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_20157174(&DAT_e800e803,6,0x40);
  } while (iVar1 == 0);
  return;
}


// ===== FUN_2011ec0c @ 2011ec0c (40 bytes)

void FUN_2011ec0c(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== FUN_2011ec34 @ 2011ec34 (40 bytes)

void FUN_2011ec34(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== FUN_2011ec5c @ 2011ec5c (40 bytes)

void FUN_2011ec5c(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== FUN_2011ec84 @ 2011ec84 (40 bytes)

void FUN_2011ec84(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== FUN_2011ecac @ 2011ecac (40 bytes)

void FUN_2011ecac(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== FUN_2011ed24 @ 2011ed24 (676 bytes)

void FUN_2011ed24(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_DAT_20166b4c + param_1 * 0xb;
  FUN_20157138(*ppuVar1,0,6,0x40);
  FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,5,0x20);
  FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,4,0x10);
  FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],param_4,0,1);
  FUN_20157138((&PTR_DAT_20166b54)[param_1 * 0xb],param_2,0,0xff);
  FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],0,7,0x80);
  FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],1,5,0x60);
  FUN_20157138((&PTR_DAT_20166b5c)[param_1 * 0xb],7,0);
  FUN_20157138((&PTR_DAT_20166b60)[param_1 * 0xb],0,0,7);
  FUN_20157138((&PTR_DAT_20166b64)[param_1 * 0xb],0,0,7);
  FUN_20157138((&PTR_DAT_20166b68)[param_1 * 0xb],0,0,3);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xf,0x8000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xe,0x4000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xd,0x2000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,0xc,0x1000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],7,8,0xf00);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,7,0x80);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],param_3,2,0xc);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,1,2);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,7,0x80);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,6,0x40);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],3,4,0x30);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,0,7);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,7,0x80);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,6,0x40);
  FUN_20157138((&PTR_DAT_20166b74)[param_1 * 0xb],0,0,1);
  FUN_20157138(*ppuVar1,1,7,0x80);
  FUN_20157138(*ppuVar1,0,6,0x40);
  FUN_20157138(*ppuVar1,1,5,0x20);
  FUN_20157138(*ppuVar1,1,3,8);
  FUN_20157138(*ppuVar1,0,2,4);
  return;
}


// ===== FUN_2011efc8 @ 2011efc8 (120 bytes)

undefined4 FUN_2011efc8(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,7,0x80,in_r3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166a84);
  if ((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166a98), 0 < iVar1)) {
    FUN_2011775c(0x110);
    FUN_2011775c(0x10f);
    return 0;
  }
  return 0xff;
}


// ===== FUN_2011f040 @ 2011f040 (120 bytes)

undefined4 FUN_2011f040(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,6,0x40,in_r3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166aac);
  if ((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166ac0), 0 < iVar1)) {
    FUN_2011775c(0x113);
    FUN_2011775c(0x112);
    return 0;
  }
  return 0xff;
}


// ===== FUN_2011f0cc @ 2011f0cc (72 bytes)

uint FUN_2011f0cc(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== FUN_2011f128 @ 2011f128 (16 bytes)

void FUN_2011f128(undefined4 param_1)

{
  FUN_20157138(param_1,1,6,0x40);
  return;
}


// ===== FUN_2011f138 @ 2011f138 (80 bytes)

uint FUN_2011f138(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== FUN_2011f19c @ 2011f19c (16 bytes)

void FUN_2011f19c(undefined4 param_1)

{
  FUN_20157138(param_1,0,6,0x40);
  return;
}


// ===== FUN_2011f1ac @ 2011f1ac (112 bytes)

uint FUN_2011f1ac(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== FUN_2011f230 @ 2011f230 (52 bytes)

undefined * FUN_2011f230(undefined4 param_1)

{
  switch(param_1) {
  default:
    return &DAT_e800c800;
  case 1:
    return &DAT_e800d000;
  case 2:
    return &DAT_e800d800;
  case 3:
    return &DAT_e800e000;
  case 4:
    return &DAT_e800e800;
  }
}


// ===== FUN_2011f278 @ 2011f278 (500 bytes)

undefined4 FUN_2011f278(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int extraout_r1;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 local_3c;
  undefined4 local_38;
  
  puVar9 = (undefined4 *)0x0;
  puVar8 = (undefined4 *)0x0;
  local_38 = 0;
  iVar1 = FUN_2011f230(param_1);
  if (param_4 != 0xff) {
    local_38 = FUN_20157174(iVar1 + 0x20,0,7);
    FUN_20157138(iVar1 + 0x20,param_4,0,7);
  }
  iVar2 = FUN_20157174(iVar1 + 0xb,5,0x60);
  if (iVar2 == 3) {
    uVar7 = 4;
  }
  else if (iVar2 == 2) {
    uVar7 = 2;
    puVar9 = param_2;
    param_2 = (undefined4 *)0x0;
  }
  else {
    uVar7 = 1;
    puVar8 = param_2;
    param_2 = (undefined4 *)0x0;
  }
  iVar3 = FUN_20157174(iVar1 + 0x20,0,7);
  uVar4 = *(uint *)(&DAT_20800434 + iVar3 * 4);
  if ((uVar4 < uVar7) || (FUN_20156260(uVar4,uVar7), extraout_r1 != 0)) {
    local_3c = 0xffffffff;
  }
  else {
    local_3c = 0;
    while (param_3 != 0) {
      uVar5 = param_3 * uVar7;
      uVar6 = uVar5;
      if (uVar4 <= uVar5) {
        uVar6 = uVar4;
      }
      switch(param_1) {
      case 0:
        FUN_2011e3fc(uVar6);
        break;
      case 1:
        FUN_2011e570(uVar6);
        break;
      case 2:
        FUN_2011e6dc(uVar6);
        break;
      case 3:
        FUN_2011e850(uVar6);
        break;
      case 4:
        FUN_2011e9bc(uVar6,uVar4 > uVar5);
      }
      for (; uVar7 <= uVar6; uVar6 = uVar6 - uVar7) {
        if (iVar2 == 3) {
          puVar10 = param_2 + 1;
          *param_2 = *(undefined4 *)(iVar1 + 4);
        }
        else {
          puVar10 = param_2;
          if (iVar2 == 2) {
            *(undefined2 *)puVar9 = *(undefined2 *)(iVar1 + 4);
            puVar9 = (undefined4 *)((int)puVar9 + 2);
          }
          else {
            *(undefined1 *)puVar8 = *(undefined1 *)(iVar1 + 4);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
        }
        param_3 = param_3 + -1;
        param_2 = puVar10;
      }
      switch(param_1) {
      case 0:
        FUN_2011e118();
        break;
      case 1:
        FUN_2011e128();
        break;
      case 2:
        FUN_2011e138();
        break;
      case 3:
        FUN_2011e148();
        break;
      case 4:
        FUN_2011e158();
      }
    }
  }
  if (param_4 != 0xff) {
    FUN_20157138(iVar1 + 0x20,local_38,0,7);
  }
  return local_3c;
}


// ===== FUN_2011f718 @ 2011f718 (604 bytes)

undefined4 FUN_2011f718(uint param_1,undefined4 *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int extraout_r1;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 local_48;
  undefined4 local_40;
  
  uVar6 = 0;
  if ((param_1 < 5) && (0xfa < param_4 - 4U)) {
    if (param_3 != 0) {
      puVar9 = (undefined4 *)0x0;
      puVar8 = (undefined4 *)0x0;
      local_40 = 0;
      iVar2 = FUN_2011f230(param_1);
      if (param_4 != 0xff) {
        local_40 = FUN_20157174(iVar2 + 0x20,4,0x30);
        FUN_20157138(iVar2 + 0x20,param_4,4,0x30);
      }
      iVar3 = FUN_20157174(iVar2 + 0xb,5,0x60);
      if (iVar3 == 3) {
        uVar7 = 4;
      }
      else if (iVar3 == 2) {
        uVar7 = 2;
        puVar9 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      else {
        uVar7 = 1;
        puVar8 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      iVar4 = FUN_20157174(iVar2 + 0x20,4,0x30);
      uVar5 = *(uint *)(&DAT_20800424 + iVar4 * 4);
      if ((uVar5 < uVar7) || (FUN_20156260(uVar5,uVar7), extraout_r1 != 0)) {
        local_48 = 0xffffffff;
      }
      else {
        local_48 = 0;
        while (param_3 != 0) {
          switch(param_1) {
          case 0:
            FUN_2011e3d0();
            break;
          case 1:
            FUN_2011e544();
            break;
          case 2:
            FUN_2011e6b0();
            break;
          case 3:
            FUN_2011e824();
            break;
          case 4:
            FUN_2011e990();
          }
          uVar1 = uVar5;
          if (param_3 * uVar7 < uVar5) {
            uVar1 = param_3 * uVar7;
          }
          for (; uVar7 <= uVar1; uVar1 = uVar1 - uVar7) {
            if (iVar3 == 3) {
              puVar10 = param_2 + 1;
              *(undefined4 *)(iVar2 + 4) = *param_2;
            }
            else {
              puVar10 = param_2;
              if (iVar3 == 2) {
                *(undefined2 *)(iVar2 + 4) = *(undefined2 *)puVar9;
                puVar9 = (undefined4 *)((int)puVar9 + 2);
              }
              else {
                *(undefined1 *)(iVar2 + 4) = *(undefined1 *)puVar8;
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
            }
            FUN_20157174(iVar2 + 3,7,0x80);
            param_3 = param_3 + -1;
            param_2 = puVar10;
          }
          switch(param_1) {
          case 0:
            FUN_2011e168();
            break;
          case 1:
            FUN_2011e178();
            break;
          case 2:
            FUN_2011e188();
            break;
          case 3:
            FUN_2011e198();
            break;
          case 4:
            FUN_2011e1e0();
          }
        }
      }
      if (param_4 != 0xff) {
        FUN_20157138(iVar2 + 0x20,local_40,4,0x30);
      }
      return local_48;
    }
  }
  else {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}


// ===== FUN_2011f758 @ 2011f758 (92 bytes)

void FUN_2011f758(int param_1)

{
  FUN_20157138(param_1 + 0x20,1,6,0x40);
  FUN_20157138(param_1 + 0x20,1,7,0x80);
  FUN_20157138(param_1 + 0x20,0,6,0x40);
  FUN_20157138(param_1 + 0x20,0,7,0x80);
  return;
}


// ===== FUN_2011f7b4 @ 2011f7b4 (120 bytes)

uint FUN_2011f7b4(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== FUN_2011f84c @ 2011f84c (60 bytes)

undefined4 FUN_2011f84c(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    FUN_2011e1f0();
    break;
  case 1:
    FUN_2011e240();
    break;
  case 2:
    FUN_2011e290();
    break;
  case 3:
    FUN_2011e2b8();
    break;
  case 4:
    FUN_2011e2e0();
  }
  return 0;
}


// ===== FUN_2011f8a8 @ 2011f8a8 (60 bytes)

undefined4 FUN_2011f8a8(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    FUN_2011e308();
    break;
  case 1:
    FUN_2011e330();
    break;
  case 2:
    FUN_2011e358();
    break;
  case 3:
    FUN_2011e380();
    break;
  case 4:
    FUN_2011e3a8();
  }
  return 0;
}


// ===== FUN_2011f8f8 @ 2011f8f8 (72 bytes)

uint FUN_2011f8f8(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== FUN_2011f970 @ 2011f970 (288 bytes)

void FUN_2011f970(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (3 < param_1) {
    return;
  }
  iVar1 = param_1 * 0x24;
  puVar2 = (undefined4 *)(&DAT_20166d18 + iVar1);
  FUN_20157138(*puVar2,0,7,0x80);
  FUN_20157138(*puVar2,1,6,0x40);
  FUN_20157138(*puVar2,1,7,0x80);
  FUN_20157138(*(undefined4 *)(&DAT_20166d1c + iVar1),3,4,0x70);
  FUN_20157138(*(undefined4 *)(&DAT_20166d20 + iVar1),0xe,0,0x1f);
  FUN_20157138(*(undefined4 *)(&DAT_20166d24 + iVar1),0x10,0,0x1f);
  FUN_20157138(*(undefined4 *)(&DAT_20166d28 + iVar1),3,0);
  FUN_20157138(*(undefined4 *)(&DAT_20166d2c + iVar1),1,4,0x10);
  FUN_20157138(*(undefined4 *)(&DAT_20166d2c + iVar1),1,5,0x20);
  FUN_20157138((&PTR_DAT_20166d30)[param_1 * 9],1,5,0x20);
  FUN_20157138((&PTR_DAT_20166d30)[param_1 * 9],1,7,0x80);
  FUN_20157138((&PTR_DAT_20166d30)[param_1 * 9],1,6,0x40);
  FUN_20157138(*puVar2,0,6,0x40);
  return;
}


// ===== FUN_2011fa90 @ 2011fa90 (508 bytes)

void FUN_2011fa90(uint param_1)

{
  if ((1 < param_1) && (param_1 != 2 && param_1 != 3)) {
    return;
  }
  FUN_2015714c(&DAT_fcfe7004,0,0,1);
  FUN_2015714c(&DAT_fcfe7104,0,0,1);
  FUN_2015714c(&DAT_fcfe3304,1,0);
  FUN_2015714c(&DAT_fcfe3404,0,0,1);
  FUN_2015714c(&DAT_fcfe7204,0,0,1);
  FUN_2015714c(&DAT_fcfe7104,1,0);
  FUN_2015714c(&DAT_fcfe3504,0,0,1);
  FUN_2015714c(&DAT_fcfe3604,0,0,1);
  FUN_2015714c(&DAT_fcfe3a04,0,0,1);
  FUN_2015714c(&DAT_fcfe7204,1,0);
  FUN_2015714c(&DAT_fcfe3404,1,0);
  FUN_2015714c(&DAT_fcfe7004,0,1,2);
  FUN_2015714c(&DAT_fcfe7104,0,1,2);
  FUN_2015714c(&DAT_fcfe3304,1,1,2);
  FUN_2015714c(&DAT_fcfe3404,0,1,2);
  FUN_2015714c(&DAT_fcfe7204,0,1,2);
  FUN_2015714c(&DAT_fcfe7104,1,1,2);
  FUN_2015714c(&DAT_fcfe3504,0,1,2);
  FUN_2015714c(&DAT_fcfe3604,0,1,2);
  FUN_2015714c(&DAT_fcfe3a04,0,1,2);
  FUN_2015714c(&DAT_fcfe7204,1,1,2);
  FUN_2015714c(&DAT_fcfe3404,1,1,2);
  return;
}


// ===== FUN_2011fc8c @ 2011fc8c (144 bytes)

void FUN_2011fc8c(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,7,0x80,in_r3);
  FUN_2011fa90(0);
  FUN_2011f970(0);
  iVar1 = FUN_2014f1a8(0,&DAT_20166c28);
  if (((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166c3c), 0 < iVar1)) &&
     (iVar1 = FUN_2014f1a8(0,&DAT_20166c50), 0 < iVar1)) {
    FUN_2011775c(0xbf);
    FUN_2011775c(0xbe);
    FUN_2011775c(0xbd);
    return;
  }
  return;
}


// ===== FUN_2011fd1c @ 2011fd1c (144 bytes)

void FUN_2011fd1c(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,6,0x40,in_r3);
  FUN_2011fa90(1);
  FUN_2011f970(1);
  iVar1 = FUN_2014f1a8(0,&DAT_20166c64);
  if (((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166c78), 0 < iVar1)) &&
     (iVar1 = FUN_2014f1a8(0,&DAT_20166c8c), 0 < iVar1)) {
    FUN_2011775c(199);
    FUN_2011775c(0xc6);
    FUN_2011775c(0xc5);
    return;
  }
  return;
}


// ===== FUN_2011fdac @ 2011fdac (136 bytes)

void FUN_2011fdac(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,5,0x20,in_r3);
  FUN_2011f970(2);
  iVar1 = FUN_2014f1a8(0,&DAT_20166ca0);
  if (((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166cb4), 0 < iVar1)) &&
     (iVar1 = FUN_2014f1a8(0,&DAT_20166cc8), 0 < iVar1)) {
    FUN_2011775c(0xcf);
    FUN_2011775c(0xce);
    FUN_2011775c(0xcd);
    return;
  }
  return;
}


// ===== FUN_2011fe34 @ 2011fe34 (136 bytes)

void FUN_2011fe34(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,4,0x10,in_r3);
  FUN_2011f970(3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166cdc);
  if (((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166cf0), 0 < iVar1)) &&
     (iVar1 = FUN_2014f1a8(0,&DAT_20166d04), 0 < iVar1)) {
    FUN_2011775c(0xd7);
    FUN_2011775c(0xd6);
    FUN_2011775c(0xd5);
    return;
  }
  return;
}

