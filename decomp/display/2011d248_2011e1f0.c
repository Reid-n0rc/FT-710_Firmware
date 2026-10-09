// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2011d248 @ 2011d248 (20 bytes)

void FUN_2011d248(int param_1,int param_2)

{
  (&DAT_208dccc8)[param_1 * 0x10] = *(undefined1 *)(param_2 + 1);
  return;
}


// ===== FUN_2011d25c @ 2011d25c (88 bytes)

int FUN_2011d25c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                )

{
  int iVar1;
  
  if (0x3ff < param_4) {
    param_4 = param_4 + -0x800;
  }
  if (0x3ff < param_5) {
    param_5 = param_5 + -0x800;
  }
  if (0x3ff < param_6) {
    param_6 = param_6 + -0x800;
  }
  iVar1 = param_3 * param_6 + param_2 * param_5 + param_1 * param_4;
  param_7 = param_7 + ((int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x18)) >> 8);
  if (param_7 < 0) {
    param_7 = 0;
  }
  else if (0xff < param_7) {
    param_7 = 0xff;
  }
  return param_7;
}


// ===== FUN_2011d2b4 @ 2011d2b4 (192 bytes)

void FUN_2011d2b4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  *(undefined4 *)(&DAT_208dcccc + param_1 * 0x10) = *(undefined4 *)(param_2 + 0x2c);
  uVar1 = *(uint *)(param_2 + 0x2c);
  uVar6 = (uVar1 & 0xffffff) >> 0x10;
  uVar5 = (uVar1 & 0xffff) >> 8;
  uVar1 = uVar1 & 0xff;
  iVar2 = FUN_2011d25c(uVar6,uVar5,uVar1,0x4d,0x96,0x1d,0);
  uVar3 = FUN_2011d25c(uVar6,uVar5,uVar1,0x7d5,0x7ab,0x80,0x80);
  iVar4 = FUN_2011d25c(uVar6,uVar5,uVar1,0x80,0x795,0x7eb,0x80);
  *(uint *)(&DAT_208dccd0 + param_1 * 0x10) = iVar4 << 0x10 | iVar2 << 8 | uVar3;
  return;
}


// ===== FUN_2011d374 @ 2011d374 (124 bytes)

void FUN_2011d374(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  
  puVar1 = &DAT_208dcce4 + param_2 * 0xc + param_1 * 0x24;
  if (param_2 == 2) {
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  else {
    *puVar1 = *(undefined1 *)(param_3 + 0xf);
    puVar1[1] = *(undefined1 *)(param_3 + 0x13);
  }
  if (*(char *)(param_3 + 0x11) == '\0' || *(char *)(param_3 + 0x11) == '\x03') {
    puVar1[2] = 1;
  }
  else {
    puVar1[2] = 0;
  }
  *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(param_3 + 0x28);
  if (param_2 == 2) {
    uVar2 = *(undefined2 *)(param_3 + 2);
  }
  else {
    uVar2 = *(undefined2 *)(param_3 + 10);
  }
  *(undefined2 *)(puVar1 + 8) = uVar2;
  if (param_2 == 2) {
    uVar2 = *(undefined2 *)(param_3 + 6);
  }
  else {
    uVar2 = *(undefined2 *)(param_3 + 0xc);
  }
  *(undefined2 *)(puVar1 + 10) = uVar2;
  return;
}


// ===== FUN_2011d3f0 @ 2011d3f0 (72 bytes)

void FUN_2011d3f0(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  undefined2 uVar2;
  
  puVar1 = &DAT_208dcce4 + param_2 * 0xc + param_1 * 0x24;
  if (param_2 == 2) {
    *(undefined2 *)(puVar1 + 8) = *(undefined2 *)(param_3 + 2);
    uVar2 = *(undefined2 *)(param_3 + 6);
  }
  else {
    *puVar1 = *(undefined1 *)(param_3 + 0xf);
    *(undefined2 *)(puVar1 + 8) = *(undefined2 *)(param_3 + 10);
    uVar2 = *(undefined2 *)(param_3 + 0xc);
  }
  *(undefined2 *)(puVar1 + 10) = uVar2;
  return;
}


// ===== FUN_2011d438 @ 2011d438 (220 bytes)

void FUN_2011d438(int param_1,int param_2,undefined1 *param_3)

{
  undefined2 uVar1;
  undefined *puVar2;
  
  puVar2 = &DAT_208dcd2c + param_2 * 0x12 + param_1 * 0x6c;
  *puVar2 = *param_3;
  puVar2[1] = param_3[1];
  puVar2[2] = param_3[0x11];
  puVar2[3] = param_3[0x11] == '\b' || param_3[0x11] == '\t';
  puVar2[4] = param_3[0x10];
  *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(param_3 + 0x14);
  *(undefined2 *)(puVar2 + 8) = *(undefined2 *)(param_3 + 0x16);
  *(undefined2 *)(puVar2 + 10) = *(undefined2 *)(param_3 + 0x18);
  *(undefined2 *)(puVar2 + 0xc) = *(undefined2 *)(param_3 + 0x1a);
  if (*(undefined2 **)(param_3 + 0xc) == (undefined2 *)0x0) {
    if (param_3[1] == '\x01' || param_2 == 5) {
      *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_3 + 0x16);
      uVar1 = *(undefined2 *)(param_3 + 0x1a);
    }
    else {
      param_1 = param_1 * 0x24;
      if (param_2 == 0) {
        uVar1 = *(undefined2 *)(&DAT_208dccec + param_1);
      }
      else {
        uVar1 = *(undefined2 *)(&DAT_208dccf8 + param_1);
      }
      *(undefined2 *)(puVar2 + 0xe) = uVar1;
      if (param_2 == 0) {
        uVar1 = *(undefined2 *)(&DAT_208dccee + param_1);
      }
      else {
        uVar1 = *(undefined2 *)(&DAT_208dccfa + param_1);
      }
    }
  }
  else {
    *(undefined2 *)(puVar2 + 0xe) = **(undefined2 **)(param_3 + 0xc);
    uVar1 = *(undefined2 *)(*(int *)(param_3 + 0xc) + 2);
  }
  *(undefined2 *)(puVar2 + 0x10) = uVar1;
  return;
}


// ===== FUN_2011d514 @ 2011d514 (104 bytes)

void FUN_2011d514(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = param_2 * 0x12 + param_1 * 0x6c;
  puVar2 = *(undefined2 **)(param_3 + 8);
  if (puVar2 != (undefined2 *)0x0) {
    *(undefined2 *)(&DAT_208dcd2c + iVar1 + 6) = *puVar2;
    *(undefined2 *)(&DAT_208dcd2c + iVar1 + 8) = puVar2[1];
    *(undefined2 *)(&DAT_208dcd2c + iVar1 + 10) = puVar2[2];
    *(undefined2 *)(&DAT_208dcd2c + iVar1 + 0xc) = puVar2[3];
  }
  if (*(undefined2 **)(param_3 + 4) != (undefined2 *)0x0) {
    *(undefined2 *)(&DAT_208dcd2c + iVar1 + 0xe) = **(undefined2 **)(param_3 + 4);
    *(undefined2 *)(&DAT_208dcd2c + iVar1 + 0x10) = *(undefined2 *)(*(int *)(param_3 + 4) + 2);
  }
  return;
}


// ===== FUN_2011d57c @ 2011d57c (16 bytes)

void FUN_2011d57c(int param_1,undefined1 param_2)

{
  (&DAT_208dccc9)[param_1 * 0x10] = param_2;
  return;
}


// ===== FUN_2011d58c @ 2011d58c (16 bytes)

void FUN_2011d58c(int param_1,undefined1 param_2)

{
  (&DAT_208dccca)[param_1 * 0x10] = param_2;
  return;
}


// ===== FUN_2011d5a8 @ 2011d5a8 (36 bytes)

undefined1 FUN_2011d5a8(void)

{
  undefined1 uVar1;
  
  if ((DAT_208dccc5 != '\0') || (uVar1 = 0, DAT_208dccd5 != '\0')) {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== FUN_2011d5cc @ 2011d5cc (16 bytes)

undefined1 FUN_2011d5cc(int param_1)

{
  return (&DAT_208dccc6)[param_1 * 0x10];
}


// ===== FUN_2011d5ec @ 2011d5ec (16 bytes)

undefined1 FUN_2011d5ec(int param_1)

{
  return (&DAT_208dccc8)[param_1 * 0x10];
}


// ===== FUN_2011d5fc @ 2011d5fc (16 bytes)

undefined1 FUN_2011d5fc(int param_1)

{
  return (&DAT_208dccc9)[param_1 * 0x10];
}


// ===== FUN_2011d60c @ 2011d60c (16 bytes)

undefined1 FUN_2011d60c(int param_1)

{
  return (&DAT_208dccca)[param_1 * 0x10];
}


// ===== FUN_2011d61c @ 2011d61c (24 bytes)

undefined4 FUN_2011d61c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(undefined4 *)(&DAT_208dcccc + param_1 * 0x10);
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_208dccd0 + param_1 * 0x10);
  }
  return uVar1;
}


// ===== FUN_2011d634 @ 2011d634 (24 bytes)

undefined1 FUN_2011d634(int param_1,int param_2)

{
  return (&DAT_208dcce4)[param_2 * 0xc + param_1 * 0x24];
}


// ===== FUN_2011d64c @ 2011d64c (28 bytes)

undefined1 FUN_2011d64c(int param_1,int param_2)

{
  return (&DAT_208dcce5)[param_1 * 0x24 + param_2 * 0xc];
}


// ===== FUN_2011d668 @ 2011d668 (28 bytes)

undefined1 FUN_2011d668(int param_1,int param_2)

{
  return (&DAT_208dcce6)[param_1 * 0x24 + param_2 * 0xc];
}


// ===== FUN_2011d6a0 @ 2011d6a0 (28 bytes)

undefined1 FUN_2011d6a0(int param_1,int param_2)

{
  return (&DAT_208dcd2c)[param_2 * 0x12 + param_1 * 0x6c];
}


// ===== FUN_2011d6bc @ 2011d6bc (32 bytes)

undefined1 FUN_2011d6bc(int param_1,int param_2)

{
  return (&DAT_208dcd2d)[param_1 * 0x6c + param_2 * 0x12];
}


// ===== FUN_2011d6dc @ 2011d6dc (32 bytes)

undefined1 FUN_2011d6dc(int param_1,int param_2)

{
  return (&DAT_208dcd2e)[param_1 * 0x6c + param_2 * 0x12];
}


// ===== FUN_2011d6fc @ 2011d6fc (32 bytes)

undefined1 FUN_2011d6fc(int param_1,int param_2)

{
  return (&DAT_208dcd2f)[param_1 * 0x6c + param_2 * 0x12];
}


// ===== FUN_2011d71c @ 2011d71c (32 bytes)

undefined1 FUN_2011d71c(int param_1,int param_2)

{
  return (&DAT_208dcd30)[param_1 * 0x6c + param_2 * 0x12];
}


// ===== FUN_2011d73c @ 2011d73c (32 bytes)

undefined * FUN_2011d73c(int param_1,int param_2)

{
  return &DAT_208dcd32 + param_1 * 0x6c + param_2 * 0x12;
}


// ===== FUN_2011d75c @ 2011d75c (32 bytes)

undefined * FUN_2011d75c(int param_1,int param_2)

{
  return &DAT_208dcd3a + param_1 * 0x6c + param_2 * 0x12;
}


// ===== FUN_2011d788 @ 2011d788 (60 bytes)

undefined * FUN_2011d788(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  param_1 = param_1 * 4;
  puVar1 = (undefined *)(param_1 + 0x20800410);
  switch(param_2) {
  case 0:
    goto switchD_2011d794_caseD_0;
  case 1:
    puVar1 = (undefined *)(param_1 + 0x20800411);
switchD_2011d794_caseD_0:
    return puVar1;
  case 2:
    return (undefined *)(param_1 + 0x20800412);
  case 3:
    return (undefined *)(param_1 + 0x20800413);
  case 4:
    return &DAT_2080040c;
  default:
    return (undefined *)0x0;
  }
}


// ===== FUN_2011d7d8 @ 2011d7d8 (24 bytes)

void FUN_2011d7d8(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_2011d788();
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_3;
  }
  return;
}


// ===== FUN_2011d7f0 @ 2011d7f0 (64 bytes)

void FUN_2011d7f0(int param_1,int param_2,undefined1 param_3)

{
  uint uVar1;
  
  param_1 = param_1 * 9;
  if (param_2 == -1) {
    uVar1 = 0;
    do {
      if ((&DAT_208dce16)[uVar1 + param_1] == '\0') {
        (&DAT_208dce04)[uVar1 + param_1] = param_3;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 9);
  }
  else {
    (&DAT_208dce04)[param_2 + param_1] = param_3;
  }
  return;
}


// ===== FUN_2011d830 @ 2011d830 (28 bytes)

undefined1 FUN_2011d830(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  puVar1 = (undefined1 *)FUN_2011d788();
  if (puVar1 != (undefined1 *)0x0) {
    uVar2 = *puVar1;
  }
  return uVar2;
}


// ===== FUN_2011d84c @ 2011d84c (20 bytes)

undefined1 FUN_2011d84c(int param_1,int param_2)

{
  return (&DAT_208dce04)[param_2 + param_1 * 9];
}


// ===== FUN_2011d8e8 @ 2011d8e8 (56 bytes)

undefined4 FUN_2011d8e8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((&DAT_208dce04)[param_2 + param_1 * 9] == '\0') ||
     ((&DAT_208dce16)[param_2 + param_1 * 9] != '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== FUN_2011d920 @ 2011d920 (56 bytes)

undefined4 FUN_2011d920(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((&DAT_208dce04)[param_2 + param_1 * 9] == '\0') ||
     ((&DAT_208dce16)[param_2 + param_1 * 9] == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== FUN_2011d958 @ 2011d958 (80 bytes)

undefined4 FUN_2011d958(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  param_1 = param_1 * 9;
  if (((&DAT_208dce06)[param_1] != '\0') && ((&DAT_208dce18)[param_1] != '\0')) {
    uVar1 = 1;
  }
  if (((&DAT_208dce0c)[param_1] != '\0') && ((&DAT_208dce1e)[param_1] != '\0')) {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== FUN_2011d9a8 @ 2011d9a8 (1272 bytes)

undefined4 FUN_2011d9a8(uint param_1,int param_2)

{
  undefined **ppuVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 < 6) {
    ppuVar1 = &PTR_DAT_20166b4c + param_1 * 0xb;
    if (param_2 == 0) {
      FUN_20157138(*ppuVar1,0,6,0x40);
      FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,5,0x20);
      FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,4,0x10);
      FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,0,1);
      FUN_20157138((&PTR_DAT_20166b54)[param_1 * 0xb],1,0,0xff);
      FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],0,7,0x80);
      FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],1,5,0x60);
      FUN_20157138((&PTR_DAT_20166b5c)[param_1 * 0xb],0,0,7);
      FUN_20157138((&PTR_DAT_20166b60)[param_1 * 0xb],0,0,7);
      FUN_20157138((&PTR_DAT_20166b64)[param_1 * 0xb],0,0,7);
      FUN_20157138((&PTR_DAT_20166b68)[param_1 * 0xb],0,0,3);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xf,0x8000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xe,0x4000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xd,0x2000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,0xc,0x1000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],7,8,0xf00);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,7,0x80);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],3,2,0xc);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,1,2);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,7,0x80);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,6,0x40);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],2,4,0x30);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],5,0,7);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,7,0x80);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,6,0x40);
      FUN_20157138((&PTR_DAT_20166b74)[param_1 * 0xb],0,0,1);
      FUN_20157138(*ppuVar1,0,7,0x80);
      FUN_20157138(*ppuVar1,0,6,0x40);
      FUN_20157138(*ppuVar1,1,5,0x20);
      FUN_20157138(*ppuVar1,1,3,8);
      FUN_20157138(*ppuVar1,0,2,4);
    }
    else if (param_2 == 1) {
      FUN_20157138(*ppuVar1,0,6,0x40);
      FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,5,0x20);
      FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,4,0x10);
      FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,0,1);
      FUN_20157138((&PTR_DAT_20166b74)[param_1 * 0xb],0,0,1);
      FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],0,7,0x80);
      FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],1,5,0x60);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,0xf,0x8000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,0xe,0x4000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,0xd,0x2000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,0xc,0x1000);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],7,8,0xf00);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,7,0x80);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,2,0xc);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,1,2);
      FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,7,0x80);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,6,0x40);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],3,4,0x30);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,0,7);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,7,0x80);
      FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,6,0x40);
      FUN_20157138(*ppuVar1,1,7,0x80);
      FUN_20157138(*ppuVar1,0,6,0x40);
      FUN_20157138(*ppuVar1,1,5,0x20);
      FUN_20157138(*ppuVar1,0,4,0x10);
      FUN_20157138(*ppuVar1,0,3,8);
      FUN_20157138(*ppuVar1,0,2,4);
    }
    else {
      uVar2 = 0xff;
    }
  }
  else {
    uVar2 = 0xff;
  }
  return uVar2;
}


// ===== FUN_2011dea4 @ 2011dea4 (124 bytes)

undefined4 FUN_2011dea4(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,7,0x80,in_r3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166a84);
  if ((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166a98), 0 < iVar1)) {
    FUN_2011775c(0x110);
    FUN_2011775c(0x10f);
    uVar2 = FUN_2011d9a8(0,1);
    return uVar2;
  }
  return 0xff;
}


// ===== FUN_2011df20 @ 2011df20 (124 bytes)

undefined4 FUN_2011df20(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,6,0x40,in_r3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166aac);
  if ((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166ac0), 0 < iVar1)) {
    FUN_2011775c(0x113);
    FUN_2011775c(0x112);
    uVar2 = FUN_2011d9a8(1,0);
    return uVar2;
  }
  return 0xff;
}


// ===== FUN_2011df9c @ 2011df9c (124 bytes)

undefined4 FUN_2011df9c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,5,0x20,in_r3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166ad4);
  if ((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166ae8), 0 < iVar1)) {
    FUN_2011775c(0x116);
    FUN_2011775c(0x115);
    uVar2 = FUN_2011d9a8(2,1);
    return uVar2;
  }
  return 0xff;
}


// ===== FUN_2011e018 @ 2011e018 (132 bytes)

undefined4 FUN_2011e018(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,4,0x10,in_r3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166afc);
  if ((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166b10), 0 < iVar1)) {
    FUN_2011775c(0x119);
    FUN_2011775c(0x118);
    FUN_2011775c(0x117);
    uVar2 = FUN_2011d9a8(3,1);
    return uVar2;
  }
  return 0xff;
}


// ===== FUN_2011e09c @ 2011e09c (124 bytes)

undefined4 FUN_2011e09c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,3,8,in_r3);
  iVar1 = FUN_2014f1a8(0,&DAT_20166b24);
  if ((0 < iVar1) && (iVar1 = FUN_2014f1a8(0,&DAT_20166b38), 0 < iVar1)) {
    FUN_2011775c(0x11c);
    FUN_2011775c(0x11b);
    uVar2 = FUN_2011d9a8(4,1);
    return uVar2;
  }
  return 0xff;
}


// ===== FUN_2011e118 @ 2011e118 (16 bytes)

void FUN_2011e118(void)

{
  DAT_20800418 = 0;
  return;
}


// ===== FUN_2011e128 @ 2011e128 (16 bytes)

void FUN_2011e128(void)

{
  DAT_20800419 = 0;
  return;
}


// ===== FUN_2011e138 @ 2011e138 (16 bytes)

void FUN_2011e138(void)

{
  DAT_2080041a = 0;
  return;
}


// ===== FUN_2011e148 @ 2011e148 (16 bytes)

void FUN_2011e148(void)

{
  DAT_2080041b = 0;
  return;
}


// ===== FUN_2011e158 @ 2011e158 (16 bytes)

void FUN_2011e158(void)

{
  DAT_2080041c = 0;
  return;
}


// ===== FUN_2011e168 @ 2011e168 (16 bytes)

void FUN_2011e168(void)

{
  DAT_2080041d = 0;
  return;
}


// ===== FUN_2011e178 @ 2011e178 (16 bytes)

void FUN_2011e178(void)

{
  DAT_2080041e = 0;
  return;
}


// ===== FUN_2011e188 @ 2011e188 (16 bytes)

void FUN_2011e188(void)

{
  DAT_2080041f = 0;
  return;
}


// ===== FUN_2011e198 @ 2011e198 (16 bytes)

void FUN_2011e198(void)

{
  DAT_20800420 = 0;
  return;
}


// ===== FUN_2011e1e0 @ 2011e1e0 (16 bytes)

void FUN_2011e1e0(void)

{
  DAT_20800421 = 0;
  return;
}


// ===== FUN_2011e1f0 @ 2011e1f0 (80 bytes)

void FUN_2011e1f0(void)

{
  FUN_20157138(&DAT_e800c820,1,6,0x40);
  FUN_20157138(&DAT_e800c820,0,6,0x40);
  DAT_208dce28 = DAT_208dce28 + 1;
  DAT_20800418 = 1;
  return;
}

