// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0020ae18 @ 0020ae18 (189 bytes)

undefined * FUN_0020ae18(int param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar3 = *(undefined **)(param_1 + 8);
  iVar2 = 0;
  if (puVar3 != &DAT_40104000) {
    iVar2 = 4;
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  iVar4 = (uint)bVar1 * 0x10;
  puVar5 = (undefined4 *)(*(int *)((int)&PTR_DAT_00236828 + iVar2) + iVar4);
  memw();
  if ((*(uint *)(puVar3 + (uint)(bVar1 >> 5) * 4 + 0x30) >> (bVar1 & 0x1f) & 1) != 0) {
    return &DAT_00001388;
  }
  if (*(char *)(param_2 + 6) == '\0') {
    memw();
    memw();
    *(uint *)(puVar3 + iVar4 + 0x400) = *(uint *)(puVar3 + iVar4 + 0x400) & 0xfffffffe;
  }
  else {
    memw();
    memw();
    *(uint *)(puVar3 + iVar4 + 0x400) = *(uint *)(puVar3 + iVar4 + 0x400) | 1;
  }
  FUN_0020a94c(puVar5,param_2 + 3,*param_2,param_2[1],param_2[2]);
  memw();
  memw();
  *(undefined4 *)(*(int *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0xc) * 0x10 + 0x408) = *puVar5;
  return (undefined *)0x0;
}


// ===== FUN_0020aed8 @ 0020aed8 (96 bytes)

void FUN_0020aed8(int param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0xc);
  iVar2 = (uint)(bVar1 >> 5) * 4 + *(int *)(param_1 + 8);
  memw();
  memw();
  *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1 << 0x20 - (0x20 - (bVar1 & 0x1f));
  memw();
  iVar2 = *(int *)(param_1 + 8) + (uint)bVar1 * 0x10;
  if ((*(uint *)(*(int *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0xc) * 0x10 + 0x400) >> 1 & 1) !=
      0) {
    return;
  }
  memw();
  memw();
  *(uint *)(iVar2 + 0x408) = *(uint *)(iVar2 + 0x408) | 4;
  return;
}


// ===== DMA_IRQHandle @ 0020af38 (277 bytes)

/* WARNING: Removing unreachable block (ram,0x0020af6f) */
/* WARNING: Removing unreachable block (ram,0x0020af72) */
/* WARNING: Removing unreachable block (ram,0x0020af75) */

void DMA_IRQHandle(undefined *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  
  iVar4 = 0x21;
  if (param_1 != &DAT_40104000) {
    iVar5 = 0;
    if (param_1 != &DAT_40104000) {
      iVar5 = 0x21;
    }
  }
  else {
    iVar5 = 0;
  }
  piVar2 = &DAT_00238470 + iVar5;
  do {
    puVar1 = (undefined4 *)*piVar2;
    if (puVar1 != (undefined4 *)0x0) {
      uVar3 = (uint)*(byte *)(puVar1 + 3);
      iVar5 = (uint)(*(byte *)(puVar1 + 3) >> 5) * 4 + puVar1[2];
      memw();
      if ((*(uint *)(iVar5 + 0x58) >> (uVar3 & 0x1f) & 1) != 0) {
        memw();
        pcVar6 = (code *)*puVar1;
        *(int *)(iVar5 + 0x58) = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(puVar1,puVar1[1],1,0);
        }
      }
      iVar5 = (uint)(*(byte *)(puVar1 + 3) >> 5) * 4 + puVar1[2];
      memw();
      if ((*(uint *)(iVar5 + 0x60) >> (uVar3 & 0x1f) & 1) != 0) {
        memw();
        pcVar6 = (code *)*puVar1;
        *(int *)(iVar5 + 0x60) = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(puVar1,puVar1[1],1,1);
        }
        iVar5 = (uint)(*(byte *)(puVar1 + 3) >> 5) * 4 + puVar1[2];
      }
      memw();
      if ((*(uint *)(iVar5 + 0x40) >> (uVar3 & 0x1f) & 1) != 0) {
        memw();
        pcVar6 = (code *)*puVar1;
        *(int *)(iVar5 + 0x40) = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)(puVar1,puVar1[1],0,2);
        }
      }
    }
    iVar4 = iVar4 + -1;
    piVar2 = piVar2 + 1;
  } while (iVar4 != 0);
  return;
}


// ===== FUN_0020b050 @ 0020b050 (11 bytes)

void FUN_0020b050(void)

{
  DMA_IRQHandle(&DAT_40104000);
  return;
}


// ===== FUN_0020b05c @ 0020b05c (11 bytes)

void FUN_0020b05c(void)

{
  DMA_IRQHandle(&DAT_40105000);
  return;
}


// ===== FUN_0020b070 @ 0020b070 (19 bytes)

bool FUN_0020b070(undefined *param_1)

{
  return param_1 != &DAT_40121000;
}


// ===== FUN_0020b084 @ 0020b084 (220 bytes)

void FUN_0020b084(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_0020b070(param_1);
  uVar2 = *(uint *)(&DAT_002001ac + iVar1 * 4);
  uVar3 = uVar2 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    DAT_40001040 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 1) {
    memw();
    DAT_40001044 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 2) {
    memw();
    DAT_40001048 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 3) {
    memw();
    DAT_40021040 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 4) {
    memw();
    DAT_40021044 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar3 == 5) {
    memw();
    DAT_40021048 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  FUN_00213910(0x318);
  memw();
  *(undefined4 *)(param_1 + 0x80) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x180) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x380) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x480) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x580) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x680) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x780) = 0;
  return;
}


// ===== FUN_0020b164 @ 0020b164 (150 bytes)

void FUN_0020b164(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_0020b070(param_1);
  uVar2 = *(uint *)(&DAT_002001ac + iVar1 * 4);
  uVar3 = uVar2 >> 8 & 0xff;
  if (uVar3 == 0) {
    memw();
    DAT_40001070 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 == 1) {
    memw();
    DAT_40001074 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 == 2) {
    memw();
    DAT_40001078 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (uVar3 != 3) {
    if (uVar3 == 4) {
      memw();
      DAT_40021074 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      return;
    }
    if (uVar3 != 5) {
      return;
    }
    memw();
    DAT_40021078 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  memw();
  DAT_40021070 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
  return;
}


// ===== FUN_0020b1fc @ 0020b1fc (80 bytes)

void FUN_0020b1fc(int param_1,int param_2)

{
  if (param_2 == 1) {
    memw();
    memw();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 4;
    memw();
    memw();
    *(uint *)(param_1 + 0x180) = *(uint *)(param_1 + 0x180) | 4;
  }
  else if (param_2 == 2) {
    memw();
    memw();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 8;
    memw();
    memw();
    *(uint *)(param_1 + 0x180) = *(uint *)(param_1 + 0x180) | 8;
    return;
  }
  return;
}


// ===== FUN_0020b24c @ 0020b24c (138 bytes)

void FUN_0020b24c(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = (undefined4 *)(param_1 + param_2 * 0x100);
  memw();
  puVar2[1] = *param_4;
  memw();
  *puVar2 = param_4[1];
  memw();
  puVar2[4] = param_4[2];
  memw();
  puVar2[2] = param_4[3];
  memw();
  uVar3 = param_4[7];
  puVar2[3] = param_4[4];
  memw();
  bVar1 = *(byte *)(param_4 + 8);
  uVar4 = param_4[6];
  uVar5 = param_4[5];
  puVar2[0x23] = param_3 & 1 | (uVar3 & 1) << 1;
  memw();
  puVar2[0x24] = (bVar1 & 1) << 8 | uVar5 & 3 | (uVar4 & 0xf) << 4;
  memw();
  memw();
  puVar2[0x24] = puVar2[0x24] | (*(byte *)((int)param_4 + 0x21) & 1) << 9;
  return;
}


// ===== FUN_0020b2d8 @ 0020b2d8 (44 bytes)

void FUN_0020b2d8(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  memw();
  *(uint *)(param_1 + param_2 * 0x100 + 0x90) =
       (param_5 & 1) << 8 | param_3 & 3 | (param_4 & 0xf) << 4;
  return;
}


// ===== FUN_0020b304 @ 0020b304 (13 bytes)

void FUN_0020b304(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0xf10) = param_2;
  return;
}


// ===== FUN_0020b314 @ 0020b314 (25 bytes)

void FUN_0020b314(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0xf00) = *(uint *)(param_1 + 0xf00) | param_2;
  return;
}


// ===== FUN_0020b330 @ 0020b330 (59 bytes)

void FUN_0020b330(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  param_1 = param_1 + param_2 * 0x100;
  memw();
  memw();
  *(uint *)(param_1 + 0x80) =
       *(uint *)(param_1 + 0x80) & 0xc | (param_3 & 0x1f) << 0x10 | param_4 & 1 | (param_5 & 1) << 1
  ;
  return;
}


// ===== FUN_0020b36c @ 0020b36c (109 bytes)

void FUN_0020b36c(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_2 & 0xc) != 0) {
    uVar1 = (param_2 & 3) != 0 | 2;
  }
  if (param_3 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0xf1c) = *(uint *)(param_1 + 0xf1c) | uVar1 | 0xc;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0xf1c) = *(uint *)(param_1 + 0xf1c) & ((uVar1 | 0xc) ^ 0xffffffff);
  return;
}


// ===== FUN_0020b3dc @ 0020b3dc (18 bytes)

void FUN_0020b3dc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0020b070(param_1);
  (&DAT_00238578)[iVar1] = param_2;
  return;
}


// ===== FUN_0020b3f0 @ 0020b3f0 (21 bytes)

void FUN_0020b3f0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0020b070(param_1);
  (&DAT_00238578)[iVar1] = 0;
  return;
}


// ===== FUN_0020b408 @ 0020b408 (18 bytes)

void FUN_0020b408(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0020b070(param_1);
  (&DAT_0023857c)[iVar1] = param_2;
  return;
}


// ===== FUN_0020b41c @ 0020b41c (21 bytes)

void FUN_0020b41c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0020b070(param_1);
  (&DAT_0023857c)[iVar1] = 0;
  return;
}


// ===== FUN_0020b434 @ 0020b434 (15 bytes)

void FUN_0020b434(void)

{
  if (DAT_00238578 != (code *)0x0) {
    (*DAT_00238578)();
  }
  return;
}


// ===== FUN_0020b444 @ 0020b444 (15 bytes)

void FUN_0020b444(void)

{
  if (DAT_0023857c != (code *)0x0) {
    (*DAT_0023857c)();
  }
  return;
}


// ===== FUN_0020b460 @ 0020b460 (39 bytes)

void FUN_0020b460(undefined4 param_1,undefined4 *param_2)

{
  if (param_2[6] == 0) {
    memw();
    *(undefined1 *)(param_2 + 5) = 0;
  }
  if ((code *)param_2[2] != (code *)0x0) {
    (*(code *)param_2[2])(*param_2,param_2,&DAT_000016a9,param_2[3]);
  }
  return;
}


// ===== FUN_0020b488 @ 0020b488 (9 bytes)

void FUN_0020b488(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return;
}


// ===== FUN_0020b494 @ 0020b494 (46 bytes)

undefined4
FUN_0020b494(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  memset(param_2,0,0x20);
  *(undefined4 *)(param_2 + 0xc) = param_4;
  *(undefined4 *)(param_2 + 8) = param_3;
  *(undefined4 *)(param_2 + 4) = param_5;
  memw();
  *(undefined1 *)(param_2 + 0x14) = 0;
  FUN_0020ab28(param_5,FUN_0020b460,param_2);
  return 0;
}


// ===== FUN_0020b4c4 @ 0020b4c4 (642 bytes)

undefined * FUN_0020b4c4(int param_1,int param_2,undefined4 *param_3,uint param_4)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_60 [24];
  uint uStack_48;
  int iStack_44;
  int iStack_40;
  uint uStack_3c;
  int iStack_38;
  int iStack_34;
  uint uStack_30;
  uint uStack_28;
  
  memcpy(auStack_60,&DAT_002001b8,0x18);
  iVar3 = *(int *)(param_2 + 0x18);
  puVar4 = (undefined4 *)param_3[4];
  uVar7 = iVar3 + 0x10;
  if (iVar3 == 0) {
    uVar7 = 0;
  }
  if ((puVar4 != (undefined4 *)0x0) && (iVar3 == 0)) {
    return (undefined *)0x4;
  }
  memw();
  uVar6 = 3;
  if (*(char *)(param_2 + 0x14) == '\x01') goto LAB_0020b710;
  uStack_48 = param_4;
  if (puVar4 == (undefined4 *)0x0) {
    iStack_40 = param_4 * 0x100;
    iVar8 = iStack_40 + param_1 + 0x88;
    bVar1 = true;
    iVar3 = 0;
  }
  else {
    iStack_40 = param_4 * 0x100;
    iStack_34 = 0;
    bVar1 = true;
    iStack_38 = 0;
    iStack_44 = iStack_40 + param_1 + 0x88;
    iVar3 = 0;
    uStack_28 = uVar6;
    uVar5 = 1;
    do {
      uVar6 = (uint)*(byte *)(puVar4 + 1);
      uStack_30 = uVar5;
      if (puVar4[4] != 0) {
        uStack_30 = uStack_28;
      }
      if (uVar6 == 4) {
        uVar5 = 0x200;
      }
      else {
        uVar5 = (uVar6 - 1) * 0x100 & 0x300;
      }
      if (*(byte *)(puVar4 + 3) == 4) {
        uVar9 = 0xc000;
      }
      else {
        uVar9 = (*(byte *)(puVar4 + 3) & 3) << 0xe;
      }
      uVar10 = (uint)puVar4[2] / uVar6 - 1;
      uVar6 = uVar10;
      if (!bVar1) {
        uVar6 = 1;
      }
      FUN_0020a78c(*(int *)(param_2 + 0x18) + iVar3,
                   uVar9 | uVar10 * 0x10000 & 0x3ff0000 |
                   uStack_30 | (uint)bVar1 << 4 | uVar5 | (uVar6 & 1) << 5,iStack_44,*puVar4,uVar7);
      bVar1 = !bVar1;
      iVar8 = iStack_44;
      uVar6 = uStack_28;
      if (iStack_34 != 0) {
        iVar3 = param_3[4];
        goto LAB_0020b620;
      }
      iStack_38 = iStack_38 + 1;
      iVar3 = iVar3 + 0x10;
      if (*(int *)(param_2 + 0x1c) == iStack_38) {
        return (undefined *)0x1;
      }
      puVar4 = (undefined4 *)puVar4[4];
      uVar7 = *(uint *)(param_2 + 0x18) + iVar3 + 0x10;
      if (param_3 == puVar4) {
        iStack_34 = 1;
        uVar7 = *(uint *)(param_2 + 0x18);
      }
      uVar5 = uVar7;
    } while (puVar4 != (undefined4 *)0x0);
    iVar3 = param_3[4];
  }
LAB_0020b620:
  uStack_3c = param_3[2];
  uVar5 = (uint)*(byte *)(param_3 + 1);
  *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + uStack_3c;
  uVar7 = (uint)*(byte *)(param_3 + 3);
  if ((uVar5 != 2) && (uVar5 != 4)) {
    *(undefined1 *)(param_3 + 1) = 2;
    uVar5 = 2;
  }
  if ((uVar7 == 0) || (4 < uVar7)) {
    *(undefined1 *)(param_3 + 3) = 1;
    uVar6 = 1;
    uVar7 = 1;
  }
  if (iVar3 == 0) {
    uVar6 = 1;
  }
  if (uVar5 == 4) {
    uVar9 = 0x200;
    if (uVar7 == 4) goto LAB_0020b720;
LAB_0020b674:
    uVar7 = (uVar7 & 3) << 0xe;
  }
  else {
    uVar9 = (uVar5 - 1) * 0x100 & 0x300;
    if (uVar7 != 4) goto LAB_0020b674;
LAB_0020b720:
    uVar7 = (uVar7 - 1) * 0x4000 & (uint)&DAT_0000c000;
  }
  FUN_0020ac54(auStack_60,iVar8,*param_3,
               uVar7 | (uStack_3c / uVar5 - 1) * 0x10000 & 0x3ff0000 |
               uVar6 | (uint)bVar1 << 4 | uVar9 | 0x20,1,0,*(undefined4 *)(param_2 + 0x18));
  puVar2 = (undefined *)FUN_0020ad78(*(undefined4 *)(param_2 + 4),auStack_60);
  iVar3 = iStack_40;
  if (puVar2 != &DAT_00001388) {
    FUN_0020b314(&DAT_40121000,1 << 0x20 - (0x20 - (uStack_48 & 0x1f)));
    memw();
    memw();
    *(uint *)(&DAT_40121080 + iVar3) = *(uint *)(&DAT_40121080 + iVar3) | 8;
    FUN_0020aed8(*(undefined4 *)(param_2 + 4));
    memw();
    *(undefined1 *)(param_2 + 0x14) = 1;
    return (undefined *)0x0;
  }
LAB_0020b710:
  return &DAT_000016a8;
}


// ===== FUN_0020b74c @ 0020b74c (18 bytes)

void FUN_0020b74c(undefined4 param_1,int param_2)

{
  FUN_0020aa20(*(undefined4 *)(param_2 + 4));
  memw();
  *(undefined1 *)(param_2 + 0x14) = 0;
  return;
}


// ===== FUN_0020b760 @ 0020b760 (41 bytes)

undefined4 FUN_0020b760(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  
  memw();
  if (*(char *)(param_2 + 0x14) == '\0') {
    return 6;
  }
  iVar1 = FUN_0020a73c(*(undefined4 *)(*(int *)(param_2 + 4) + 8),
                       *(undefined1 *)(*(int *)(param_2 + 4) + 0xc));
  *param_3 = *(int *)(param_2 + 0x10) - iVar1;
  return 0;
}


// ===== FUN_0020b790 @ 0020b790 (30 bytes)

bool FUN_0020b790(undefined *param_1)

{
  return param_1 != &DAT_40106000;
}


// ===== FUN_0020b7b0 @ 0020b7b0 (305 bytes)

undefined4 FUN_0020b7b0(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0020b790(param_1);
  uVar3 = *(uint *)(&DAT_00200200 + iVar2 * 4);
  uVar4 = uVar3 >> 8 & 0xff;
  if (uVar4 == 0) {
    memw();
    DAT_40001040 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 1) {
    memw();
    DAT_40001044 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 2) {
    memw();
    DAT_40001048 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 3) {
    memw();
    DAT_40021040 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 4) {
    memw();
    DAT_40021044 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 5) {
    memw();
    DAT_40021048 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  FUN_00213910(*(undefined4 *)(&DAT_00200230 + iVar2 * 4));
  if (param_2 != 0) {
    if (param_2 < 5) {
      memw();
      bVar1 = true;
      if ((*(uint *)(param_1 + 0xff8) & 1 << 0x20 - (0x20 - (param_2 + 3 & 0x1f))) == 0) {
        return 3;
      }
    }
    else {
      if (param_2 != 5) {
        return 3;
      }
      memw();
      bVar1 = true;
      if ((*(uint *)(param_1 + 0xff8) >> 7 & 1) == 0) {
        bVar1 = false;
      }
    }
    if (!bVar1) {
      return 3;
    }
  }
  memw();
  if ((*(uint *)(param_1 + 0xff8) & 8) != 0) {
    memw();
    if (param_2 != (*(uint *)(param_1 + 0xff8) & 7)) {
      return 1;
    }
  }
  memw();
  *(uint *)(param_1 + 0xff8) = param_2;
  return 0;
}


// ===== FUN_0020b8e4 @ 0020b8e4 (30 bytes)

void FUN_0020b8e4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(param_1);
  *(undefined4 *)(&DAT_00238580 + iVar1 * 4) = param_2;
  *(undefined4 *)(&DAT_002385b0 + iVar1 * 4) = param_3;
  return;
}


// ===== FUN_0020b904 @ 0020b904 (44 bytes)

void FUN_0020b904(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40106000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020b930 @ 0020b930 (44 bytes)

void FUN_0020b930(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40107000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020b95c @ 0020b95c (44 bytes)

void FUN_0020b95c(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40108000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020b988 @ 0020b988 (44 bytes)

void FUN_0020b988(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40109000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020b9b4 @ 0020b9b4 (44 bytes)

void FUN_0020b9b4(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40122000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020b9e0 @ 0020b9e0 (44 bytes)

void FUN_0020b9e0(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40123000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020ba0c @ 0020ba0c (44 bytes)

void FUN_0020ba0c(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40124000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020ba38 @ 0020ba38 (44 bytes)

void FUN_0020ba38(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40125000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020ba64 @ 0020ba64 (44 bytes)

void FUN_0020ba64(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40126000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020ba90 @ 0020ba90 (44 bytes)

void FUN_0020ba90(void)

{
  int iVar1;
  
  iVar1 = FUN_0020b790(&DAT_40127000);
  (**(code **)(&DAT_00238580 + iVar1 * 4))
            ((&PTR_DAT_002001d0)[iVar1],*(undefined4 *)(&DAT_002385b0 + iVar1 * 4));
  return;
}


// ===== FUN_0020bac0 @ 0020bac0 (18 bytes)

void FUN_0020bac0(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | param_2;
  return;
}


// ===== FUN_0020bad4 @ 0020bad4 (23 bytes)

void FUN_0020bad4(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & (param_2 ^ 0xffffffff);
  return;
}


// ===== FUN_0020baec @ 0020baec (18 bytes)

void FUN_0020baec(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | param_2;
  return;
}


// ===== FUN_0020bb00 @ 0020bb00 (19 bytes)

bool FUN_0020bb00(undefined *param_1)

{
  return param_1 != &DAT_40134000;
}


// ===== FUN_0020bb14 @ 0020bb14 (96 bytes)

undefined * FUN_0020bb14(int param_1,uint param_2)

{
  undefined *puVar1;
  
  if ((param_2 & 0x80a) == 0) {
    return (undefined *)0x0;
  }
  if ((param_2 & 0x800) == 0) {
    if ((param_2 >> 3 & 1) == 0) {
      puVar1 = (undefined *)0x0;
      if ((param_2 & 2) != 0) {
        puVar1 = &DAT_00001b5b;
      }
    }
    else {
      puVar1 = &DAT_00001b5a;
    }
  }
  else {
    puVar1 = &DAT_00001b59;
  }
  FUN_0020baec(param_1,param_2 & 0x80a);
  memw();
  memw();
  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
  memw();
  memw();
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  return puVar1;
}


// ===== FUN_0020bb74 @ 0020bb74 (755 bytes)

void FUN_0020bb74(uint *param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_0020bb00(param_1);
  uVar3 = *(uint *)(&DAT_0020028c + iVar2 * 4);
  uVar4 = uVar3 >> 8 & 0xff;
  if (uVar4 == 0) {
    memw();
    DAT_40001040 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 1) {
    memw();
    DAT_40001044 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 2) {
    memw();
    DAT_40001048 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 3) {
    memw();
    DAT_40021040 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 4) {
    memw();
    DAT_40021044 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  else if (uVar4 == 5) {
    memw();
    DAT_40021048 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffffd;
  memw();
  memw();
  *param_1 = *param_1 | 1;
  memw();
  uVar3 = *param_1;
  while ((uVar3 & 1) != 0) {
    memw();
    uVar3 = *param_1;
  }
  memw();
  *param_1 = (*(byte *)((int)param_2 + 6) & 1) << 0xb |
             ((byte)param_2[1] & 1) << 0xe | (uint)(byte)param_2[4] << 0x18 |
             (uint)(byte)param_2[3] << 0x10 |
             (*(byte *)((int)param_2 + 5) & 1) << 0xc | (*param_2 & 3) << 4 | 2;
  memw();
  param_1[1] = CONCAT22(*(undefined2 *)((int)param_2 + 10),*(undefined2 *)((int)param_2 + 0x12));
  memw();
  memw();
  param_1[2] = param_1[2] & 0xf777ff | (*(byte *)((int)param_2 + 0x46) & 1) << 0xb |
               ((byte)param_2[2] & 1) << 0xf |
               (*(byte *)((int)param_2 + 7) & 1) << 0x13 | (uint)(byte)param_2[5] << 0x18;
  memw();
  memw();
  param_1[3] = param_1[3] & 0xffffff87 | (*(byte *)((int)param_2 + 0x4a) & 1) << 3 |
               (*(byte *)((int)param_2 + 0x49) & 1) << 4 |
               (*(byte *)((int)param_2 + 0x47) & 1) << 6 | ((byte)param_2[0x12] & 1) << 5;
  memw();
  memw();
  param_1[8] = param_1[8] & 0x78f0fe00 | (ushort)((ushort)param_2[6] >> 3) & 0x1ff |
               (*(byte *)((int)param_2 + 0x17) & 0xf) << 0x10 |
               (*(byte *)((int)param_2 + 0x16) & 7) << 0x18 |
               (uint)*(byte *)((int)param_2 + 0x1a) << 0x1f;
  memw();
  memw();
  bVar1 = *(byte *)((int)param_2 + 0xe);
  param_1[0x2e] = param_1[0x2e] & 0xffffff03;
  memw();
  memw();
  param_1[0x2e] = param_1[0x2e] | ((bVar1 >> 3) - 1) * 4 & 0xfc;
  memw();
  memw();
  bVar1 = *(byte *)((int)param_2 + 0xd);
  param_1[0x2f] = param_1[0x2f] & 0xfffffe03;
  memw();
  memw();
  param_1[0x2f] = param_1[0x2f] | ((bVar1 >> 3) - 1) * 4 & 0x1fc;
  memw();
  param_1[0x18] = 0;
  memw();
  param_1[0x19] = 0;
  memw();
  param_1[0x1a] = 0;
  memw();
  param_1[0x1b] = 0;
  return;
}


// ===== FUN_0020be6c @ 0020be6c (196 bytes)

void FUN_0020be6c(undefined4 *param_1)

{
  *(undefined1 *)param_1 = 0;
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0xffff;
  *(undefined2 *)((int)param_1 + 0x12) = 0xffff;
  *(undefined1 *)((int)param_1 + 0xd) = 8;
  *(undefined1 *)((int)param_1 + 0xe) = 8;
  *(undefined1 *)(param_1 + 5) = 0x20;
  *(undefined1 *)(param_1 + 3) = 0xff;
  *(undefined1 *)(param_1 + 4) = 0xff;
  *(undefined1 *)((int)param_1 + 5) = 1;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x1a) = 1;
  *(undefined1 *)((int)param_1 + 0x17) = 0xf;
  *(undefined1 *)((int)param_1 + 0x1d) = 0xf;
  *(undefined2 *)((int)param_1 + 0x1e) = 0;
  *(undefined1 *)(param_1 + 8) = 1;
  *(undefined1 *)((int)param_1 + 0x23) = 0xf;
  *(undefined2 *)(param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 0x26) = 1;
  *(undefined1 *)((int)param_1 + 0x29) = 0xf;
  *(undefined1 *)(param_1 + 0xb) = 1;
  *(undefined2 *)((int)param_1 + 0x2a) = 0;
  *(undefined1 *)((int)param_1 + 0x3e) = 1;
  *(undefined1 *)(param_1 + 0x11) = 1;
  *(undefined2 *)(param_1 + 0xf) = 0x100;
  *(undefined2 *)((int)param_1 + 0x42) = 0x100;
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  *(undefined1 *)((int)param_1 + 0x47) = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x49) = 0;
  *(undefined1 *)((int)param_1 + 0x4a) = 0;
  return;
}


// ===== FUN_0020bf30 @ 0020bf30 (42 bytes)

void FUN_0020bf30(uint *param_1)

{
  uint uVar1;
  
  memw();
  memw();
  *param_1 = *param_1 | 1;
  memw();
  uVar1 = *param_1;
  while ((uVar1 & 1) != 0) {
    memw();
    uVar1 = *param_1;
  }
  return;
}


// ===== FUN_0020bf5c @ 0020bf5c (221 bytes)

void FUN_0020bf5c(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  if ((param_1[0x38] & 2) == 0) goto LAB_0020bf6d;
  memw();
  uVar2 = param_1[0x38];
  while ((uVar2 & 1) == 0) {
LAB_0020bf6d:
    do {
      memw();
    } while ((param_1[0x38] & 2) == 0);
    memw();
    uVar2 = param_1[0x38];
  }
  memw();
  uVar2 = (*param_1 & 0x30) >> 4;
  if ((((uVar2 == 0) || (uVar2 == 1)) || (uVar2 == 2)) ||
     ((uVar2 != 3 || ((char)param_2[1] != '\0')))) {
    uVar2 = 0x100;
  }
  else if (*param_2 < 100000000) {
    uVar3 = (short)(ushort)(byte)param_2[5] * 1000;
    uVar1 = uVar3 / 0x4b;
    uVar2 = uVar1 + 1;
    if (uVar3 <= uVar1 * 0x4b) {
      uVar2 = uVar1;
    }
    uVar2 = (uVar2 & 0x3f) << 9 | 0x100;
  }
  else {
    uVar2 = 0x79;
  }
  memw();
  param_1[(param_3 >> 1 & 0x7f) + 0x30] = uVar2;
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffffd;
  if ((uVar2 & 1) != 0) {
    memw();
    uVar2 = param_1[0x3a];
    while ((~uVar2 & 3) != 0) {
      memw();
      uVar2 = param_1[0x3a];
    }
  }
  return;
}


// ===== FUN_0020c03c @ 0020c03c (485 bytes)

void FUN_0020c03c(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  if ((param_1[0x38] >> 1 & 1) == 0) goto LAB_0020c050;
  memw();
  uVar2 = param_1[0x38];
  while ((uVar2 & 1) == 0) {
LAB_0020c050:
    do {
      memw();
    } while ((param_1[0x38] & 2) == 0);
    memw();
    uVar2 = param_1[0x38];
  }
  memw();
  param_1[param_3 + 0x18] = *(uint *)(param_2 + 8);
  memw();
  param_1[param_3 + 0x1c] =
       (*(byte *)(param_2 + 0x15) & 0xf) << 0xb | (*(byte *)(param_2 + 0x16) & 1) << 10 |
       *(byte *)(param_2 + 0x13) & 0x1f | (*(byte *)(param_2 + 0x12) & 0x1f) << 5 |
       (uint)*(ushort *)(param_2 + 0x10) << 0x10 | (*(uint *)(param_2 + 0xc) & 1) << 0xf;
  memw();
  uVar2 = param_1[param_3 + 0x20] & 0x80000000 |
          (*(ushort *)(param_2 + 0x20) & 0xfff) << 0x10 | (*(uint *)(param_2 + 0x1c) & 7) << 0x1c;
  if (*(byte *)(param_2 + 0x18) != 0) {
    uVar2 = uVar2 | (*(byte *)(param_2 + 0x17) & 0x1f) << 8 |
                    (*(byte *)(param_2 + 0x18) - 1) * 0x2000 & (uint)&DAT_0000e000;
  }
  if (*(byte *)(param_2 + 0x1a) != 0) {
    uVar2 = uVar2 | *(byte *)(param_2 + 0x19) & 0x1f | (*(byte *)(param_2 + 0x1a) - 1) * 0x20 & 0xe0
    ;
  }
  memw();
  param_1[param_3 + 0x20] = uVar2;
  FUN_0020bf5c(param_1,param_2,param_3);
  memw();
  memw();
  uVar2 = (uint)*(byte *)(param_2 + 0x22);
  *param_1 = *param_1 | 2;
  if (uVar2 == 0) {
    memw();
    uVar1 = param_1[0x25] | 1;
  }
  else {
    memw();
    uVar1 = param_1[0x25] & 0xfffffffe;
  }
  memw();
  param_1[0x25] = uVar1;
  if ((param_3 >> 1 & 0x7f) == 0) {
    memw();
    memw();
    param_1[0x25] = param_1[0x25] & 0xfffffffb;
    memw();
    memw();
    param_1[0x25] = param_1[0x25] | (uVar2 & 1) << 2;
  }
  else {
    memw();
    memw();
    param_1[0x25] = param_1[0x25] & 0xfffffff7;
    memw();
    memw();
    param_1[0x25] = param_1[0x25] | (uVar2 & 1) << 3;
  }
  memw();
  memw();
  *param_1 = *param_1 & 0xfffffffd;
  memw();
  if ((param_1[0x38] & 2) == 0) goto LAB_0020c1b5;
  memw();
  uVar2 = param_1[0x38];
  while ((uVar2 & 1) == 0) {
LAB_0020c1b5:
    do {
      memw();
    } while ((param_1[0x38] & 2) == 0);
    memw();
    uVar2 = param_1[0x38];
  }
  return;
}

