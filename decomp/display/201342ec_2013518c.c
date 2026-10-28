// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201342ec @ 201342ec (168 bytes)

void FUN_201342ec(undefined4 param_1)

{
  if (DAT_204832b8 == '\0') {
    if ((DAT_208004a0 == '\0') && (DAT_204832ba == '\0')) {
      memcpy(&DAT_204832bb,param_1,0x352);
    }
    else {
      FUN_2015525c(&DAT_204832bb,0x352,0xff);
    }
    if (((ushort)DAT_20808a84 & 0x400) != 0) {
      FUN_20155310(&DAT_204832d4,&DAT_203d9b14,800);
      return;
    }
  }
  else if (DAT_204832ba != '\0') {
    FUN_20155254(&DAT_204832bb,0x352,0xff);
    return;
  }
  return;
}


// ===== FUN_201342f8 @ 201342f8 (24 bytes)

void FUN_201342f8(undefined1 param_1)

{
  DAT_204832b8 = param_1;
  return;
}


// ===== FUN_20134304 @ 20134304 (24 bytes)

void FUN_20134304(undefined1 param_1)

{
  DAT_204832b9 = param_1;
  return;
}


// ===== FUN_20134310 @ 20134310 (8 bytes)

void FUN_20134310(void)

{
  FUN_20157778(&DAT_2047963c);
  return;
}


// ===== FUN_20134318 @ 20134318 (452 bytes)

void FUN_20134318(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  if (((DAT_204832b8 == '\0') && (DAT_204832b9 == '\0')) && (DAT_204832ba == '\0')) {
    FUN_201643cc();
    iVar2 = 0x1d;
    do {
      iVar1 = FUN_20164828(&DAT_20490890,-iVar2);
      iVar4 = iVar2 * 800 + 0x2048395f;
      FUN_20155274(iVar4,800);
      if (param_1 == 8) {
        if (param_2 == 0) {
          FUN_20133ee8(iVar2,iVar4,&DAT_2048a0f8 + iVar1 * 800);
        }
        else {
          FUN_20133efc();
        }
      }
      else if ((param_1 == 9) && (iVar2 < 0xf)) {
        FUN_20133f24(iVar2,iVar4,&DAT_2048a0f8 + iVar1 * 800);
      }
      iVar2 = iVar2 + -1;
    } while (1 < iVar2);
    iVar2 = 0x1d;
    do {
      iVar1 = FUN_20164828(&DAT_20490890,-iVar2);
      piVar3 = (int *)(&DAT_2048feb8 + iVar1 * 0x54);
      piVar5 = (int *)(iVar2 * 0x54 + 0x20489720);
      if ((param_1 == 8) || ((param_1 == 9 && (iVar2 < 0xf)))) {
        iVar1 = *piVar3;
        iVar4 = 0;
        if (0 < iVar1) {
          do {
            if (param_1 == 8) {
              if (param_2 == 0) goto LAB_20157b88;
              FUN_20133f58(iVar2,piVar3 + iVar4 + 1,piVar5 + iVar4 + 1);
            }
            else if ((param_1 == 9) && (iVar2 < 0xf)) {
LAB_20157b88:
              FUN_20133f44(iVar2);
            }
            iVar1 = *piVar3;
            iVar4 = iVar4 + 1;
          } while (iVar4 < iVar1);
        }
        *piVar5 = iVar1;
      }
      iVar2 = iVar2 + -1;
    } while (1 < iVar2);
  }
  return;
}


// ===== FUN_20134328 @ 20134328 (588 bytes)

void FUN_20134328(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int *piVar6;
  undefined *puVar7;
  
  iVar1 = DAT_20489774;
  if (((DAT_204832b8 == '\0') && (DAT_204832b9 == '\0')) && (DAT_204832ba == '\0')) {
    iVar1 = FUN_20164828(&DAT_20490890,0xffffffff,param_2,param_3,param_3);
    puVar7 = &DAT_2048a0f8 + iVar1 * 800;
    iVar2 = FUN_201647e4(&DAT_20494768,0);
    memcpy(puVar7,&DAT_20490894 + iVar2 * 800,800);
    iVar2 = 1;
    if (1 < param_2) {
      do {
        iVar3 = FUN_201647e4(&DAT_20494768,-iVar2);
        iVar4 = 0;
        do {
          if ((byte)puVar7[iVar4] < (byte)(&DAT_20490894)[iVar4 + iVar3 * 800]) {
            puVar7[iVar4] = (&DAT_20490894)[iVar4 + iVar3 * 800];
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 800);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
    iVar2 = 0;
    if (0 < DAT_20494714) {
      puVar5 = &DAT_2047963c + iVar1 * 0x54;
      do {
        iVar4 = FUN_201647e4(&DAT_20494768,-iVar2);
        iVar3 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        *(undefined4 *)(puVar5 + iVar3 + 0x16880) = *(undefined4 *)(&DAT_20494718 + iVar4 * 4);
      } while (iVar2 < DAT_20494714);
    }
    *(int *)(&DAT_2048feb8 + iVar1 * 0x54) = DAT_20494714;
    FUN_20155274(&DAT_20483c7f,800);
    if (param_1 == 8) {
      if (param_3 == 0) {
        FUN_20133ec0(1,&DAT_20483c7f,puVar7);
      }
      else {
        FUN_20133ed4();
      }
    }
    else if (param_1 == 9) {
      FUN_20133f10(1,&DAT_20483c7f,puVar7);
    }
    piVar6 = (int *)(&DAT_2048feb8 + iVar1 * 0x54);
    iVar2 = 0;
    iVar1 = *piVar6;
    if (0 < *piVar6) {
      do {
        if (param_1 == 8) {
          if (param_3 == 0) goto LAB_201582f8;
          FUN_20133f58(1,piVar6 + iVar2 + 1,iVar2 * 4 + 0x20489778);
        }
        else if (param_1 == 9) {
LAB_201582f8:
          FUN_20133f44(1);
        }
        iVar2 = iVar2 + 1;
        iVar1 = *piVar6;
      } while (iVar2 < *piVar6);
    }
  }
  DAT_20489774 = iVar1;
  return;
}


// ===== FUN_20134348 @ 20134348 (212 bytes)

void FUN_20134348(int param_1,undefined2 *param_2)

{
  int iVar1;
  
  if ((((DAT_20800498 == '\0') && (DAT_204832b8 == '\0')) && (DAT_204832b9 == '\0')) &&
     (DAT_204832ba == '\0')) {
    FUN_201643b0();
    iVar1 = FUN_201647e4(&DAT_20494768,0);
    FUN_201577f8(&DAT_2047963c,&DAT_20490894 + iVar1 * 800,&DAT_204832d4,800);
    *(undefined2 *)(&DAT_20494718 + iVar1 * 4) = *param_2;
    *(undefined2 *)(&DAT_2049471a + iVar1 * 4) = param_2[1];
    DAT_20494714 = DAT_20494714 + 1;
    if (param_1 <= DAT_20494714) {
      DAT_20494714 = param_1;
    }
  }
  return;
}


// ===== FUN_20134358 @ 20134358 (68 bytes)

undefined2 FUN_20134358(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (param_2 == 8) {
    return *(undefined2 *)(DAT_20450278 + param_1 * 2);
  }
  if (param_2 == 9) {
    uVar1 = *(undefined2 *)(DAT_2045027c + param_1 * 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20134368 @ 20134368 (88 bytes)

undefined2 FUN_20134368(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  if (param_2 == 8) {
    if (param_3 == 0) {
      puVar2 = (undefined2 *)&DAT_203d99dc;
    }
    else {
      puVar2 = &DAT_203d9a18;
    }
    return puVar2[param_1];
  }
  if (param_2 == 9) {
    if (param_3 == 0) {
      puVar2 = (undefined2 *)&DAT_203d9a80;
    }
    else {
      puVar2 = &DAT_203d9a9e;
    }
    uVar1 = puVar2[param_1];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_2013437c @ 2013437c (20 bytes)

void FUN_2013437c(undefined4 param_1,undefined4 param_2)

{
  FUN_20157c50(&DAT_2047963c,param_1,param_2,0);
  return;
}


// ===== FUN_20134398 @ 20134398 (44 bytes)

undefined4 FUN_20134398(int param_1)

{
  if (param_1 == 8) {
    return uRam2047854c;
  }
  if (param_1 != 9) {
    return DAT_20474d00;
  }
  return uRam20479638;
}


// ===== FUN_201343c4 @ 201343c4 (40 bytes)

void FUN_201343c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_20163428(&DAT_2047963c,param_1,param_2,param_3,0);
  return;
}


// ===== FUN_201343ec @ 201343ec (28 bytes)

void FUN_201343ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_20163428(&DAT_2047963c,param_1,param_3,param_4,param_5);
  return;
}


// ===== FUN_20134408 @ 20134408 (36 bytes)

int FUN_20134408(int param_1)

{
  return param_1 * 0x54 + 0x20489720;
}


// ===== FUN_20134414 @ 20134414 (568 bytes)

/* WARNING: Removing unreachable block (ram,0x20157e8c) */
/* WARNING: Removing unreachable block (ram,0x20157eb8) */
/* WARNING: Removing unreachable block (ram,0x20157e64) */

void FUN_20134414(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  
  if ((((DAT_20800498 == '\0') && (DAT_204832b8 == '\0')) && (DAT_204832b9 == '\0')) &&
     (DAT_204832ba == '\0')) {
    iVar3 = FUN_20164828(&DAT_20490890,0xffffffff);
    puVar7 = &DAT_2048a0f8 + iVar3 * 800;
    iVar3 = FUN_201647e4(&DAT_20494768,0);
    memcpy(puVar7,&DAT_20490894 + iVar3 * 800,800);
    iVar3 = 1;
    if (1 < param_1) {
      do {
        iVar4 = FUN_201647e4(&DAT_20494768,-iVar3);
        iVar5 = 0;
        do {
          if ((byte)puVar7[iVar5] < (byte)(&DAT_20490894)[iVar5 + iVar4 * 800]) {
            puVar7[iVar5] = (&DAT_20490894)[iVar5 + iVar4 * 800];
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 800);
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1);
    }
    iVar3 = FUN_20164388(&DAT_204fc5f0);
    if (DAT_20450280 == 1) {
      iVar3 = FUN_20164388(&DAT_204fc5ec);
    }
    iVar4 = DAT_20450280 * 0x33f40 + iVar3 * 0x640 + 0x2049476c;
    iVar3 = 0;
    do {
      pbVar2 = puVar7 + iVar3;
      iVar5 = iVar3 * 2;
      iVar3 = iVar3 + 1;
      *(undefined2 *)(iVar4 + iVar5) = *(undefined2 *)(&DAT_2047c442 + (uint)*pbVar2 * 2);
    } while (iVar3 < 800);
    iVar3 = 0;
    if (0 < DAT_20494714) {
      do {
        iVar5 = FUN_201647e4(&DAT_20494768,-iVar3);
        iVar5 = iVar5 * 4;
        uVar6 = (uint)*(ushort *)(&DAT_20494718 + iVar5);
        if (uVar6 < *(ushort *)(&DAT_2049471a + iVar5) + uVar6) {
          do {
            iVar1 = uVar6 * 2;
            pbVar2 = puVar7 + uVar6;
            uVar6 = uVar6 + 1;
            *(undefined2 *)(iVar4 + iVar1) = *(undefined2 *)(&DAT_2047c644 + (uint)*pbVar2 * 2);
          } while ((int)uVar6 <
                   (int)((uint)*(ushort *)(&DAT_20494718 + iVar5) +
                        (uint)*(ushort *)(&DAT_2049471a + iVar5)));
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_20494714);
    }
  }
  return;
}


// ===== FUN_20134434 @ 20134434 (116 bytes)

int FUN_20134434(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_2016479c(&DAT_204fc5f0,~param_1,param_2);
  if (DAT_20450280 == 1) {
    iVar1 = FUN_2016479c(&DAT_204fc5ec,~param_1);
  }
  return DAT_20450280 * 0x33f40 + iVar1 * 0x640 + 0x2049476c;
}


// ===== FUN_20134444 @ 20134444 (36 bytes)

void FUN_20134444(undefined4 param_1,undefined4 param_2)

{
  thunk_FUN_20162d48(&DAT_2047963c,param_1);
  FUN_201584f8(&DAT_2047963c,param_2);
  return;
}


// ===== FUN_20134468 @ 20134468 (12 bytes)

void FUN_20134468(undefined4 param_1)

{
  FUN_201584f8(&DAT_2047963c,param_1);
  return;
}


// ===== FUN_20134474 @ 20134474 (12 bytes)

void FUN_20134474(undefined4 param_1)

{
  FUN_20158544(&DAT_2047963c,param_1);
  return;
}


// ===== FUN_20134480 @ 20134480 (120 bytes)

void FUN_20134480(int param_1)

{
  DAT_2047c848 = (undefined1)param_1;
  DAT_2047f400 = DAT_2047c848;
  DAT_2047fd80 = DAT_2047c848;
  DAT_20482938 = DAT_2047c848;
  if (param_1 != 0) {
    DAT_20450278 = &DAT_203d9a18;
  }
  else {
    DAT_20450278 = (undefined2 *)&DAT_203d99dc;
  }
  if (param_1 != 0) {
    DAT_2045027c = &DAT_203d9a9e;
  }
  else {
    DAT_2045027c = (undefined2 *)&DAT_203d9a80;
  }
  return;
}


// ===== FUN_2013448c @ 2013448c (12 bytes)

void FUN_2013448c(undefined4 param_1)

{
  FUN_201578c8(&DAT_2047963c,param_1);
  return;
}


// ===== FUN_20134498 @ 20134498 (8 bytes)

void FUN_20134498(void)

{
  FUN_20158568(&DAT_2047963c);
  return;
}


// ===== FUN_201344a0 @ 201344a0 (8 bytes)

undefined * FUN_201344a0(void)

{
  return &DAT_204832bb;
}


// ===== FUN_201344c8 @ 201344c8 (88 bytes)

void FUN_201344c8(undefined2 param_1,int param_2,int param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    sVar1 = *(short *)(param_3 + uVar3 * 2);
    if ((sVar1 != 0) || (iVar2 = FUN_2013376c(param_4,uVar3 & 0xffff,param_1), iVar2 != 0)) {
      *(short *)(param_2 + uVar3 * 2) = sVar1;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 800);
  return;
}


// ===== FUN_20134520 @ 20134520 (76 bytes)

void FUN_20134520(int param_1,int param_2)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  do {
    iVar1 = iVar4 * 2;
    iVar3 = iVar4 * 3;
    iVar5 = iVar3 + param_2;
    iVar4 = iVar4 + 1;
    uVar2 = *(ushort *)(param_1 + iVar1);
    *(byte *)(iVar5 + 2) = (byte)(uVar2 >> 8) & 0xf8;
    *(byte *)(iVar5 + 1) = (byte)(uVar2 >> 3) & 0xfc;
    *(char *)(param_2 + iVar3) = (char)uVar2 << 3;
  } while (iVar4 < 800);
  return;
}


// ===== FUN_2013456c @ 2013456c (216 bytes)

undefined4 FUN_2013456c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = fs_fwrite(&DAT_208085c4,1,0x36,param_1);
  if (iVar1 != 0) {
    iVar1 = fb_get_layer_addr(0);
    iVar2 = FUN_20132e78(DAT_208085b8);
    iVar3 = FUN_20132e78(DAT_208085bc);
    iVar5 = 0x1df;
    while( true ) {
      memcpy(&DAT_20908710,iVar1 + iVar5 * 0x640,0x640);
      FUN_201344c8(iVar5,&DAT_20908710,iVar2 + iVar5 * 0x640,4);
      FUN_201344c8(iVar5,&DAT_20908710,iVar3 + iVar5 * 0x640,5);
      FUN_20134520(&DAT_20908710,&DAT_20908d50);
      iVar4 = fs_fwrite(&DAT_20908d50,1,0x960,param_1);
      if (iVar4 == 0) break;
      iVar5 = iVar5 + -1;
      if (iVar5 < 0) {
        return 0;
      }
    }
  }
  return 1;
}


// ===== screen_capture_bmp @ 20134644 (416 bytes)

/* I:\FT-710\Capture\20YYMMDD_HHMMSS.bmp */

void screen_capture_bmp(void)

{
  int iVar1;
  undefined1 auStack_68 [64];
  byte local_28 [4];
  byte local_24 [4];
  byte local_20 [4];
  byte local_1c [4];
  byte local_18 [4];
  byte local_14 [4];
  uint local_10;
  uint local_c;
  
  iVar1 = FUN_2014b880(0x49,&local_10,&local_c);
  if ((iVar1 != 0) || (local_10 == 0 && (0x119435 < local_c) <= local_10)) goto LAB_20134794;
  if (DAT_208f0b2a == 'z') {
    return;
  }
  screen_shot_menu(DAT_208f0b2a,local_c - 0x119436);
  FUN_20133c40(0);
  FUN_201525f8(0xffffffff);
  iVar1 = FUN_2014c410("I:\\FT-710\\Capture");
  if (iVar1 == 0) {
    iVar1 = FUN_2014c410("I:\\FT-710");
    if (iVar1 == 0) {
      iVar1 = FUN_2014beec("I:\\FT-710");
      if (iVar1 == 0) goto LAB_201347b8;
    }
    else {
      thunk_FUN_2014c474();
LAB_201347b8:
      iVar1 = FUN_2014beec("I:\\FT-710\\Capture");
      if (iVar1 == 0) goto LAB_201346c0;
    }
    FUN_2014d95c();
  }
  else {
    thunk_FUN_2014c474();
LAB_201346c0:
    FUN_20114658(local_28,local_24,local_20,local_1c,local_18,local_14);
    sprintf(auStack_68,"I:\\FT-710\\Capture\\20%02d%02d%02d_%02d%02d%02d.bmp",
            (local_28[0] & 0xf) + (uint)(local_28[0] >> 4) * 10,
            (local_24[0] & 0xf) + (uint)(local_24[0] >> 4) * 10,
            (local_20[0] & 0xf) + (uint)(local_20[0] >> 4) * 10,
            (local_1c[0] & 0xf) + (uint)(local_1c[0] >> 4) * 10,
            (local_18[0] & 0xf) + (uint)(local_18[0] >> 4) * 10,
            (local_14[0] & 0xf) + (uint)(local_14[0] >> 4) * 10);
    iVar1 = fs_fopen(auStack_68,&DAT_20134844);
    if (iVar1 != 0) {
      FUN_2013456c();
      FUN_20141ff0(iVar1);
    }
  }
LAB_20134794:
  FUN_20133c40(1);
  return;
}


// ===== FUN_20134854 @ 20134854 (256 bytes)

void FUN_20134854(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined1 auStack_68 [64];
  byte local_28 [4];
  byte local_24 [4];
  byte local_20 [4];
  byte local_1c [4];
  byte local_18 [4];
  byte local_14 [8];
  
  FUN_20114658(local_28,local_24,local_20,local_1c,local_18,local_14);
  sprintf(auStack_68,"I:\\20%02d%02d%02d_%02d%02d%02d.bmp",
          (local_28[0] & 0xf) + (uint)(local_28[0] >> 4) * 10,
          (local_24[0] & 0xf) + (uint)(local_24[0] >> 4) * 10,
          (local_20[0] & 0xf) + (uint)(local_20[0] >> 4) * 10,
          (local_1c[0] & 0xf) + (uint)(local_1c[0] >> 4) * 10,
          (local_18[0] & 0xf) + (uint)(local_18[0] >> 4) * 10,
          (local_14[0] & 0xf) + (uint)(local_14[0] >> 4) * 10);
  iVar2 = 2;
  do {
    iVar1 = fs_fopen(auStack_68,&DAT_20134844);
    if (iVar1 != 0) {
      FUN_2013456c();
      FUN_20141ff0(iVar1);
      return;
    }
    itron_dly_tsk(0x32);
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}


// ===== FUN_20134978 @ 20134978 (860 bytes)

void FUN_20134978(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_64;
  undefined1 auStack_63 [35];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  uVar4 = (uint)bVar1;
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar2,*(undefined4 *)(&DAT_208085fc + uVar4 * 4),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar2,0x1e,3,&DAT_203e5e2c);
  FUN_20135ff0(uVar2,"Searching files...",0xdc,400,0xc,&DAT_20803bc0);
  FUN_201363c0(uVar2,0x60,700,0x5e,0x13b,0,0,5,0x821);
  fb_fill_rect(uVar2,0x821,0x1f,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1f,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x37,0x2dd,&DAT_2016dc58);
  fb_fill_rect(uVar2,0x821,0x1a0,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1a0,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x1b6,0x2dd,&DAT_2016dc68);
  iVar3 = FUN_20103bb0();
  if (iVar3 == 0) {
    local_2c = 0;
    local_40._0_2_ = (ushort)(byte)(bVar1 + 0x40);
    local_3c = 0;
    local_28 = 0;
    local_40._0_3_ = CONCAT12(4,(ushort)local_40);
    local_40 = (uint)(uint3)local_40;
    local_38 = 0;
    local_34 = 0;
    local_64 = 0xc3;
    local_30 = 0;
    local_24 = 0;
    local_20 = 0;
    memcpy(auStack_63,&local_40,0x21);
    mainlink_queue_frame(&local_64,0x22);
    return;
  }
  if ((uVar4 == 2 || uVar4 == 4) && (iVar3 = FUN_2010f35c(), iVar3 != 0)) {
    local_2c = 0;
    local_40._0_2_ = (ushort)(byte)(bVar1 + 0x40);
    local_3c = 0;
    local_28 = 0;
    local_40._0_3_ = CONCAT12(1,(ushort)local_40);
    local_40 = (uint)(uint3)local_40;
    local_38 = 0;
    local_34 = 0;
    local_64 = 0xc3;
    local_30 = 0;
    local_24 = 0;
    local_20 = 0;
    memcpy(auStack_63,&local_40,0x21);
    mainlink_queue_frame(&local_64,0x22);
    return;
  }
  DAT_20909cf0 = FUN_2010ef88(uVar4 != 1 && uVar4 != 2,&DAT_209096b0,100);
  iVar3 = FUN_20103bb0();
  if (iVar3 == 0) {
    FUN_20160ed8();
    return;
  }
  local_2c = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_64 = 0xc3;
  local_40._0_3_ = (uint3)(byte)(bVar1 + 0x40);
  local_40 = CONCAT13((undefined1)DAT_20909cf0,(uint3)local_40);
  memcpy(auStack_63,&local_40,0x21);
  mainlink_queue_frame(&local_64,0x22);
  FUN_20161bb0();
  return;
}


// ===== FUN_20134984 @ 20134984 (944 bytes)

void FUN_20134984(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  uVar5 = (uint)*(byte *)(param_1 + 1);
  bVar1 = *(byte *)(param_1 + 3);
  uVar6 = (uint)*(byte *)(param_1 + 4);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar2,*(undefined4 *)(&DAT_208084fc + uVar5 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar2,0x1e,3,&DAT_203e5e2c);
  iVar3 = 0;
  iVar4 = 5;
  if (DAT_20909cf0 < 5) {
    iVar4 = DAT_20909cf0;
  }
  if (0 < iVar4) {
    do {
      FUN_20135dd4(uVar2,&DAT_209096b0 + ((uint)bVar1 + iVar3) * 0x10,iVar3 * 0x4b + 0x38U & 0xffff,
                   0x127,0xf,&DAT_20800b1c);
      FUN_20135aa4(uVar2,iVar3 * 0x4b + 0x67U & 0xffff,7,0x2ae,1,0x821);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  if (uVar5 == 0x42 || uVar5 == 0x44) {
    fb_fill_rect(uVar2,0x821,0x1a0,0x1d4,*DAT_20802290,DAT_20802290[1]);
    gui_draw_runs(uVar2,0x1a0,0x1d4,DAT_20802290);
    gui_draw_runs(uVar2,0x1b7,0x1dd,&DAT_203e5e4c);
  }
  fb_fill_rect(uVar2,0x821,0x1a0,0x247,*DAT_20802290,DAT_20802290[1]);
  gui_draw_runs(uVar2,0x1a0,0x247,DAT_20802290);
  gui_draw_runs(uVar2,0x1b7,0x250,&DAT_203e5e3c);
  if (uVar6 == 0xfe) {
    if (uVar5 == 0x42 || uVar5 == 0x44) {
      FUN_20136398(uVar2,0x1a0,0x1d4,*DAT_20802290,DAT_20802290[1],3);
    }
  }
  else if (uVar6 == 0xff) {
    FUN_20136398(uVar2,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
    goto LAB_20161e8c;
  }
  if ((int)uVar6 < iVar4) {
    FUN_20136290(uVar2,uVar6 * 0x4b + 0x1e,3,0x2b2,0x4f,3,0xf980);
  }
LAB_20161e8c:
  FUN_201363c0(uVar2,0x60,700,0x5e,0x13b,(uint)bVar1,DAT_20909cf0,5,0x821);
  fb_fill_rect(uVar2,0x821,0x1f,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1f,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x37,0x2dd,&DAT_2016dc58);
  fb_fill_rect(uVar2,0x821,0x1a0,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1a0,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x1b6,0x2dd,&DAT_2016dc68);
  return;
}


// ===== FUN_20134990 @ 20134990 (692 bytes)

bool FUN_20134990(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c;
  undefined1 auStack_5b [35];
  undefined4 local_38;
  int local_34;
  uint local_30;
  undefined *local_2c;
  int iStack_28;
  
  local_2c = &DAT_209096b0;
  iStack_28 = param_1;
  local_38 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  uVar6 = (uint)bVar1;
  uVar3 = *(undefined1 *)(param_1 + 3);
  uVar2 = *(undefined1 *)(param_1 + 4);
  local_30 = 0;
  fb_copy_rect(local_38,0,0,800,0x1e0);
  fb_fill_rect(local_38,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(local_38,3,3,&DAT_2016dc08);
  FUN_20135ff0(local_38,*(undefined4 *)(&DAT_208084fc + uVar6 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(local_38,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(local_38,0x1e,3,&DAT_203e5e2c);
  FUN_20135ff0(local_38,"LOADING",0xdc,400,0xf,&DAT_20800b1c);
  FUN_2010f300(uVar6 != 0x41,local_2c,uVar3,uVar2);
  while (iVar4 = FUN_201101e8(0,&local_30,&local_34), iVar4 == 0) {
    FUN_201219b8(local_38,0xf0,0x129,local_30 & 0xffff);
    FUN_20133090(1);
    gui_update_layers();
    FUN_201525f8(0xffffffff);
    local_38 = fb_get_layer_addr(DAT_208085bc);
  }
  if (iVar4 == 1) {
    FUN_201219b8(local_38,0xf0,0x129,100);
    FUN_20133090(1);
    gui_update_layers();
    FUN_201525f8(0xffffffff);
    fb_get_layer_addr(DAT_208085bc);
  }
  else {
    iVar5 = FUN_20103bb0();
    if (iVar5 == 0) {
      FUN_20160ed8();
      return false;
    }
  }
  local_6c = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_80._0_2_ = CONCAT11(0x10,bVar1);
  local_70 = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  if (iVar4 == 1) {
    local_80 = (uint)(ushort)local_80;
    FUN_20135488(32000,(int)&local_80 + 3);
LAB_201615c8:
    if (local_34 == 0) {
      FUN_2010f240(uVar6 != 0x41,32000);
    }
  }
  else {
    if (local_34 == 1) {
      uVar3 = 2;
    }
    else {
      if (local_34 != 2) {
        local_80._0_3_ = CONCAT12(0xff,(ushort)local_80);
        local_80 = (uint)(uint3)local_80;
        goto LAB_201615c8;
      }
      uVar3 = 3;
    }
    local_80._0_3_ = CONCAT12(uVar3,(ushort)local_80);
    local_80 = (uint)(uint3)local_80;
  }
  local_5c = 0xc3;
  memcpy(auStack_5b,&local_80,0x21);
  mainlink_queue_frame(&local_5c,0x22);
  FUN_20161bb0();
  return local_34 == 0;
}


// ===== FUN_2013499c @ 2013499c (408 bytes)

void FUN_2013499c(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_copy_rect(uVar3,0,0,800,0x1e0);
  fb_fill_rect(uVar3,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar3,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar3,*(undefined4 *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar3,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar3,0x1e,3,&DAT_203e5e2c);
  FUN_20135ff0(uVar3,"PROCESSING",0xdc,400,0xf,&DAT_20800b1c);
  iVar4 = FUN_2010f2c8();
  while( true ) {
    iVar5 = FUN_20103bb0();
    if (iVar5 == 0) {
      FUN_20160ed8();
      return;
    }
    iVar5 = FUN_2010f2c8();
    uVar2 = __aeabi_uidivmod(iVar5 * 100,iVar4);
    FUN_201219b8(uVar3,0xf0,0x129,uVar2);
    if ((iVar4 <= iVar5) || (iVar5 = FUN_2011506c(param_1), iVar5 != 0)) break;
    FUN_20133090(1);
    gui_update_layers();
    FUN_201525f8(0xffffffff);
    uVar3 = fb_get_layer_addr(DAT_208085bc);
  }
  return;
}


// ===== FUN_201349a8 @ 201349a8 (232 bytes)

void FUN_201349a8(int param_1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  undefined4 unaff_r5;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  undefined1 auStack_33 [39];
  
  cVar1 = *(char *)(param_1 + 1);
  bVar2 = *(byte *)(param_1 + 3);
  local_44 = 0;
  if (cVar1 == 'B') {
    unaff_r5 = 0;
  }
  local_58._0_2_ = CONCAT11(1,cVar1);
  uVar3 = (ushort)local_58;
  if (cVar1 != 'B') {
    unaff_r5 = 1;
  }
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_58 = (uint)(ushort)local_58;
  local_48 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  if (bVar2 == 0xff) {
    if (DAT_20909cf0 < 100) {
      FUN_2010f0dc(unaff_r5,&DAT_209096b0,DAT_20909cf0,(int)&local_58 + 3);
    }
    else {
      local_58._0_3_ = CONCAT12(1,uVar3);
      local_58 = (uint)(uint3)local_58;
    }
  }
  else {
    FUN_201550dc((int)&local_58 + 3);
    iVar4 = FUN_2010f1e0(unaff_r5,&DAT_209096b0 + (uint)bVar2 * 0x10);
    if (iVar4 != 0) {
      local_58._0_3_ = CONCAT12(2,(ushort)local_58);
    }
  }
  local_34 = 0xc3;
  memcpy(auStack_33,&local_58,0x21);
  mainlink_queue_frame(&local_34,0x22);
  return;
}


// ===== FUN_201349b4 @ 201349b4 (236 bytes)

void FUN_201349b4(int param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 auStack_3b [35];
  
  cVar1 = *(char *)(param_1 + 1);
  puVar5 = (undefined *)0x0;
  iVar4 = 0;
  if (0 < DAT_20909cf0) {
    do {
      iVar3 = FUN_2014e208(param_1 + 3,&DAT_209096b0 + iVar4 * 0x10);
      if (iVar3 == 0) {
        puVar5 = &DAT_209096b0 + iVar4 * 0x10;
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_20909cf0);
  }
  local_4c = 0;
  local_60._0_2_ = CONCAT11(2,cVar1);
  uVar2 = (ushort)local_60;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_60 = (uint)(ushort)local_60;
  local_50 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  if (puVar5 != (undefined *)0x0) {
    local_60._0_3_ = CONCAT12(1,uVar2);
    local_60 = (uint)(uint3)local_60;
    iVar4 = FUN_2010f1e0(cVar1 != 'B',puVar5);
    if (iVar4 != 0) {
      local_60._0_3_ = CONCAT12(2,(ushort)local_60);
    }
  }
  local_3c = 0xc3;
  memcpy(auStack_3b,&local_60,0x21);
  mainlink_queue_frame(&local_3c,0x22);
  return;
}


// ===== FUN_201349c0 @ 201349c0 (584 bytes)

void FUN_201349c0(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 auStack_4b [39];
  
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  uVar4 = FUN_20135470(param_1 + 3);
  fb_copy_rect(uVar3,0,0,800,0x1e0);
  fb_fill_rect(uVar3,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar3,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar3,*(undefined4 *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar3,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar3,0x1e,3,&DAT_203e5e2c);
  FUN_20135ff0(uVar3,"PROCESSING",0xdc,400,0xf,&DAT_20800b1c);
  bVar7 = bVar1 != 0x42;
  FUN_2010f284(bVar7,uVar4);
  local_5c = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_70 = (uint)CONCAT11(3,bVar1);
  local_4c = 0xc3;
  memcpy(auStack_4b,&local_70,0x21);
  mainlink_queue_frame(&local_4c,0x22);
  iVar5 = FUN_2010f2c8(bVar7,0);
  while( true ) {
    iVar6 = FUN_20103bb0();
    if (iVar6 == 0) {
      FUN_20160ed8();
      return;
    }
    iVar6 = FUN_2010f2c8(bVar7,1);
    uVar2 = __aeabi_uidivmod(iVar6 * 100,iVar5);
    FUN_201219b8(uVar3,0xf0,0x129,uVar2);
    FUN_20133090(1);
    gui_update_layers();
    FUN_201525f8(0xffffffff);
    uVar3 = fb_get_layer_addr(DAT_208085bc);
    if (iVar5 <= iVar6) break;
    iVar6 = FUN_2011506c(param_1);
    if (iVar6 != 0) {
      return;
    }
  }
  FUN_201219b8(uVar3,0xf0,0x129,100);
  FUN_20133090(1);
  gui_update_layers();
  FUN_201525f8(0xffffffff);
  fb_get_layer_addr(DAT_208085bc);
  return;
}


// ===== FUN_201349cc @ 201349cc (708 bytes)

void FUN_201349cc(int param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 auStack_57 [35];
  uint local_34;
  int local_30;
  uint local_2c;
  
  local_6c = fb_get_layer_addr(DAT_208085bc);
  local_2c = (uint)*(byte *)(param_1 + 3);
  bVar1 = *(byte *)(param_1 + 1);
  uVar6 = (uint)bVar1;
  local_34 = 0;
  fb_fill_rect(local_6c,0x821,0,0,800,0x1e0);
  fb_fill_rect(local_6c,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(local_6c,3,3,&DAT_2016dc08);
  FUN_20135ff0(local_6c,*(undefined4 *)(&DAT_208084fc + uVar6 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(local_6c,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(local_6c,0x1e,3,&DAT_203e5e2c);
  FUN_20135ff0(local_6c,"SAVING",0xdc,400,0xf,&DAT_20800b1c);
  memcpy(&local_68,param_1 + 6,0x10);
  iVar4 = FUN_2015507c(&local_68,&PTR_DAT_2042821c,0xf);
  if ((iVar4 == 0) || ((char)local_68 == '\0')) {
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
    FUN_2010f0dc(uVar6 != 0x42,&DAT_209096b0,DAT_20909cf0,&local_68);
  }
  FUN_2010f2e8(uVar6 != 0x42,&local_68,local_2c);
  while (iVar4 = FUN_201101e8(1,&local_34,&local_30), iVar4 == 0) {
    FUN_201219b8(local_6c,0xf0,0x129,local_34 & 0xffff);
    FUN_20133090(1);
    gui_update_layers();
    FUN_201525f8(0xffffffff);
    local_6c = fb_get_layer_addr(DAT_208085bc);
  }
  if (iVar4 == 1) {
    FUN_201219b8(local_6c,0xf0,0x129,100);
    FUN_20133090(1);
    gui_update_layers();
    FUN_201525f8(0xffffffff);
    fb_get_layer_addr(DAT_208085bc);
  }
  else {
    iVar5 = FUN_20103bb0();
    if (iVar5 == 0) {
      FUN_20160ed8();
      return;
    }
  }
  local_7c = 0;
  local_90._0_2_ = CONCAT11(0x10,bVar1);
  uVar2 = (ushort)local_90;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_90 = (uint)(ushort)local_90;
  local_80 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  if (iVar4 != 1) {
    if (local_30 == 1) {
      local_90._0_3_ = CONCAT12(2,uVar2);
      local_90 = (uint)(uint3)local_90;
    }
    else {
      if (local_30 == 2) {
        uVar3 = 3;
      }
      else {
        uVar3 = 0xff;
      }
      local_90._0_3_ = CONCAT12(uVar3,uVar2);
      local_90 = (uint)(uint3)local_90;
    }
  }
  local_58 = 0xc3;
  memcpy(auStack_57,&local_90,0x21);
  mainlink_queue_frame(&local_58,0x22);
  FUN_20161bb0();
  return;
}


// ===== FUN_201349d8 @ 201349d8 (424 bytes)

void FUN_201349d8(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar2,*(undefined4 *)(&DAT_208085fc + (uint)bVar1 * 4),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar2,0x1e,3,&DAT_203e5e2c);
  sd_info_screen(&DAT_20909cf4);
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  iVar3 = FUN_20103bb0();
  if (iVar3 != 0) {
    local_60._0_2_ = CONCAT11(bVar1 + 0x40,0xc3);
    mainlink_queue_frame(&local_60,0x22);
    FUN_20161bb0();
    return;
  }
  local_28 = 0;
  local_38 = 0;
  local_24 = 0;
  local_3c = (uint)CONCAT12(4,(ushort)(byte)(bVar1 + 0x40));
  local_60 = CONCAT31(local_60._1_3_,0xc3);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_1c = 0;
  memcpy((int)&local_60 + 1,&local_3c,0x21);
  mainlink_queue_frame(&local_60,0x22);
  return;
}


// ===== FUN_201349e4 @ 201349e4 (524 bytes)

void FUN_201349e4(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  cVar2 = *(char *)(param_1 + 4);
  fb_fill_rect(uVar3,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar3,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar3,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar3,*(undefined4 *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar3,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar3,0x1e,3,&DAT_203e5e2c);
  fb_fill_rect(uVar3,0x821,0x1a0,0x247,*DAT_20802290,DAT_20802290[1]);
  gui_draw_runs(uVar3,0x1a0,0x247,DAT_20802290);
  gui_draw_runs(uVar3,0x1b7,0x250,&DAT_203e5e3c);
  if (cVar2 == -1) {
    FUN_20136398(uVar3,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
  }
  FUN_20135ff0(uVar3,&DAT_20909cf4,0x38,400,0xf,&DAT_20800b1c);
  FUN_20135aa4(uVar3,0x67,7,0x312,1,0x821);
  FUN_20135ff0(uVar3,&DAT_20909d34,0x83,400,0xf,&DAT_20800b1c);
  FUN_20135aa4(uVar3,0xb2,7,0x312,1,0x821);
  return;
}


// ===== FUN_201349f0 @ 201349f0 (348 bytes)

void FUN_201349f0(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar2,*(undefined4 *)(&DAT_208085fc + (uint)bVar1 * 4),4,400,0xf,&DAT_20800b1c);
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  iVar3 = FUN_2010f35c();
  if (iVar3 != 0) {
    local_20 = 0;
    local_30 = 0;
    local_1c = 0;
    local_34 = (uint)CONCAT12(1,(ushort)(byte)(bVar1 + 0x40));
    local_58 = CONCAT31(local_58._1_3_,0xc3);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_18 = 0;
    local_14 = 0;
    memcpy((int)&local_58 + 1,&local_34,0x21);
    mainlink_queue_frame(&local_58,0x22);
    return;
  }
  local_58._0_2_ = CONCAT11(bVar1 + 0x40,0xc3);
  mainlink_queue_frame(&local_58,0x22);
  return;
}


// ===== FUN_201349fc @ 201349fc (560 bytes)

void FUN_201349fc(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  cVar2 = *(char *)(param_1 + 4);
  fb_fill_rect(uVar3,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar3,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar3,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar3,*(undefined4 *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar3,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar3,0x1e,3,&DAT_203e5e2c);
  FUN_20135ff0(uVar3,"FORMAT SD CARD",0xd5,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar3,0x821,0x1a0,0x1d4,*DAT_20802290,DAT_20802290[1]);
  gui_draw_runs(uVar3,0x1a0,0x1d4,DAT_20802290);
  gui_draw_runs(uVar3,0x1b7,0x1dd,&DAT_203e5e5c);
  fb_fill_rect(uVar3,0x821,0x1a0,0x247,*DAT_20802290,DAT_20802290[1]);
  gui_draw_runs(uVar3,0x1a0,0x247,DAT_20802290);
  gui_draw_runs(uVar3,0x1b7,0x250,&DAT_203e5e6c);
  if (cVar2 != -2) {
    if (cVar2 == -1) {
      FUN_20136398(uVar3,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
    }
    return;
  }
  FUN_20136398(uVar3,0x1a0,0x1d4,*DAT_20802290,DAT_20802290[1],3);
  return;
}


// ===== FUN_20134a08 @ 20134a08 (496 bytes)

void FUN_20134a08(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 auStack_4b [35];
  int local_28;
  uint local_24 [2];
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  FUN_20135ff0(uVar2,*(undefined4 *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  FUN_201359bc(uVar2,0x1e,3,&DAT_203e5e2c);
  FUN_20135ff0(uVar2,"Now format in progress...",0xd2,400,0xf,&DAT_20800b1c);
  local_24[0] = 0;
  local_28 = 0;
  while (iVar3 = FUN_20110278(local_24,&local_28), iVar3 == 0) {
    FUN_201219b8(uVar2,0xf0,0x129,local_24[0] & 0xffff);
    FUN_20133090(1);
    gui_update_layers();
    FUN_201525f8(0xffffffff);
    uVar2 = fb_get_layer_addr(DAT_208085bc);
  }
  FUN_20110368();
  if ((iVar3 != 1) && (local_28 == 5)) {
    FUN_20160ed8();
    return;
  }
  local_5c = 0;
  local_70._0_2_ = CONCAT11(0x10,bVar1);
  if (iVar3 == 1) {
    local_70._0_3_ = (uint3)(ushort)local_70;
  }
  else {
    local_70._0_3_ = CONCAT12(0xff,(ushort)local_70);
  }
  local_70 = (uint)(uint3)local_70;
  local_60 = 0;
  local_4c = 0xc3;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  memcpy(auStack_4b,&local_70,0x21);
  mainlink_queue_frame(&local_4c,0x22);
  FUN_20161bb0();
  return;
}


// ===== FUN_20134a18 @ 20134a18 (104 bytes)

int FUN_20134a18(int param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 < 5) {
    return 0;
  }
  if (param_1 < 0xf0) {
    lVar1 = (longlong)(param_1 + -4) * 10000000;
    FUN_20154984((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),0xec,0);
    uVar2 = FUN_201353f8();
    iVar3 = FUN_20154984((int)((ulonglong)uVar2 * 0xb3),
                         ((int)uVar2 >> 0x1f) * 0xb3 + (int)((ulonglong)uVar2 * 0xb3 >> 0x20),
                         1000000,0);
    return iVar3 + 1;
  }
  return 0xb4;
}


// ===== FUN_20134a80 @ 20134a80 (60 bytes)

void FUN_20134a80(void)

{
  undefined2 local_28 [18];
  
  FUN_201110cc(local_28);
  *(undefined2 *)(&DAT_20909d74 + (uint)DAT_20808624 * 2) = local_28[0];
  DAT_20808624 = DAT_20808624 + 1 & 0x1f;
  return;
}


// ===== FUN_20134abc @ 20134abc (616 bytes)

void FUN_20134abc(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (DAT_208f0b2a == 0x3a) {
LAB_20134b8c:
    uVar5 = (uint)DAT_208f0b89;
  }
  else {
    uVar5 = DAT_20808640;
    if (0x3a < DAT_208f0b2a) {
      if (DAT_208f0b2a != 0x50) {
        if (DAT_208f0b2a < 0x51) {
          if (DAT_208f0b2a == 0x40 || DAT_208f0b2a == 0x41) goto LAB_20134b8c;
        }
        else if (DAT_208f0b2a == 0x62 || DAT_208f0b2a == 0x70) goto LAB_20134b8c;
        goto LAB_20134b08;
      }
      goto LAB_20134b8c;
    }
    if (DAT_208f0b2a == 0x31) goto LAB_20134b8c;
    if (DAT_208f0b2a < 0x32) {
      if ((DAT_208f0b2a == 0x20 || DAT_208f0b2a == 0x24) || DAT_208f0b2a == 0x30) goto LAB_20134b8c;
    }
    else if (DAT_208f0b2a == 0x37 || DAT_208f0b2a == 0x39) goto LAB_20134b8c;
  }
LAB_20134b08:
  iVar2 = FUN_20134a18(uVar5);
  if (iVar2 < DAT_20808638) {
    iVar3 = 0;
    if (DAT_20808638 - iVar2 == 1) {
      if (DAT_2080863c == 0) goto LAB_20134bac;
      DAT_2080863c = DAT_2080863c + -1;
    }
    else {
      DAT_2080863c = 1;
      iVar3 = (iVar2 - DAT_20808638) / 3;
      if (iVar3 == 0) {
LAB_20134bac:
        iVar3 = -1;
      }
    }
    DAT_20808638 = DAT_20808638 + iVar3;
    if (DAT_20808638 < iVar2) {
LAB_20134bbc:
      DAT_20808638 = iVar2;
    }
  }
  else if (DAT_20808638 < iVar2) {
    iVar3 = (iVar2 - DAT_20808638) / 3;
    if (iVar3 == 0) {
      DAT_20808638 = DAT_20808638 + 1;
    }
    else {
      DAT_20808638 = DAT_20808638 + iVar3;
    }
    if (iVar2 < DAT_20808638) goto LAB_20134bbc;
  }
  if (DAT_20808638 < 0xb4) {
    iVar2 = DAT_20808638;
    if (DAT_20808638 < 0) {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0xb4;
  }
  DAT_20808638 = iVar2;
  DAT_20808640 = uVar5;
  fb_copy_rect(uVar1,DAT_2080862c,DAT_2080862a,0x118,0x50);
  fb_copy_rect(uVar1,DAT_20808630,DAT_2080862e,0x40,0x11);
  gui_draw_runs(uVar1,DAT_2080862c,DAT_2080862a,(&PTR_DAT_2080865c)[iVar2]);
  if (DAT_20808634 < iVar2) {
    DAT_20808622 = DAT_20808620;
    DAT_20808634 = iVar2;
  }
  if (DAT_20808622 == 0) {
    DAT_20808634 = 0;
  }
  else {
    gui_draw_runs(uVar1,DAT_2080862c,DAT_2080862a,(&PTR_DAT_2080865c)[DAT_20808634]);
    if (DAT_20808622 < 0x21) {
      DAT_20808622 = 0;
    }
    else {
      DAT_20808622 = DAT_20808622 - 0x21;
    }
  }
  if ((DAT_208f0b31 & 0x30) == 0x10) {
    puVar4 = &DAT_203eea9c;
  }
  else {
    if ((DAT_208f0b31 & 0x30) != 0x20) goto LAB_20134cec;
    puVar4 = &DAT_203eeaac;
  }
  if (puVar4 != (undefined *)0x0) {
    gui_draw_runs(uVar1,DAT_20808630,DAT_2080862e);
  }
LAB_20134cec:
  if (((byte)DAT_20808a84 & 1) != 0) {
    uVar1 = fb_get_layer_addr(DAT_208085bc);
    FUN_20135c14(uVar1,iVar2,3,0x46,100);
  }
  return;
}


// ===== FUN_20134d24 @ 20134d24 (176 bytes)

void FUN_20134d24(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = fb_get_layer_addr(0);
  uVar2 = *(byte *)(param_1 + 0xb) & 7;
  if (param_3 != 0 || uVar2 != (*(byte *)(param_2 + 0xb) & 7)) {
    if (5 < uVar2) {
      uVar2 = 5;
    }
    fb_fill_rect(uVar1,0,10,0,0x118,0x50);
    FUN_20132f44(0);
    gui_draw_runs(uVar1,10,0,&DAT_203eea8c);
    gui_draw_runs(uVar1,DAT_20808628,DAT_20808626,(&PTR_DAT_20808644)[uVar2]);
    DAT_20808620 = 0;
  }
  return;
}


// ===== test_disp_init @ 20134e0c (100 bytes)

/* task "test_disp" */

void test_disp_init(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  iVar1 = itron_acre_flg(0,&local_18);
  if (0 < iVar1) {
    DAT_20808934 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_20420088);
    if (0 < iVar1) {
      DAT_20808938 = iVar1;
      itron_sta_tsk(iVar1,0);
    }
  }
  return;
}


// ===== FUN_20134e70 @ 20134e70 (364 bytes)

undefined4 FUN_20134e70(short *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 local_bf0 [2048];
  undefined1 auStack_3f0 [952];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 auStack_34 [4];
  undefined1 local_30;
  undefined1 auStack_2c [3];
  undefined1 local_29;
  char local_28 [8];
  
  iVar5 = fs_fread(auStack_2c,3,1,param_2);
  if (iVar5 < 1) {
    uVar6 = 0xffffffff;
  }
  else {
    local_29 = 0;
    uVar3 = FUN_20154dd0(auStack_2c);
    uVar1 = (uint)uVar3;
    param_1[1] = uVar3;
    if (uVar1 != 0) {
      fs_fread(local_28,1,1,param_2);
      fs_fread(local_bf0,uVar1 * 3,1,param_2);
      puVar8 = auStack_34;
      fs_fread(puVar8,4,1,param_2);
      local_30 = 0;
      sVar4 = FUN_20154dd0(puVar8);
      *param_1 = sVar4;
      if (sVar4 == 0) {
        *param_1 = 1000;
      }
      if (uVar1 != 0) {
        puVar8 = auStack_3f0;
      }
      local_36 = 0;
      if (uVar1 != 0) {
        iVar5 = 0;
        do {
          local_38 = local_bf0[iVar5 * 3];
          local_37 = local_bf0[iVar5 * 3 + 1];
          uVar2 = FUN_2014e3c4(puVar8 + 0x3b8,0,0x10);
          iVar7 = iVar5 + 1;
          *(undefined1 *)((int)param_1 + iVar5 + 4) = uVar2;
          iVar5 = iVar7;
        } while (iVar7 < (int)uVar1);
      }
      fs_fread(local_28,1,1,param_2);
      return 1;
    }
    do {
      fs_fread(local_28,1,1,param_2);
    } while (local_28[0] != '\n');
    uVar6 = 0;
  }
  return uVar6;
}


// ===== debug_recv_cmd_log @ 20134fdc (268 bytes)

/* I:\FT-710\DEBUG_RECV_CMD\RECV_CMD.TXT */

undefined4 debug_recv_cmd_log(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort local_e5c;
  undefined2 local_e5a;
  char local_e58 [3000];
  char local_2a0 [576];
  undefined1 auStack_60 [64];
  
  iVar2 = FUN_20103ba0();
  uVar5 = 0;
  if (iVar2 != 0) {
    FUN_20154a30(auStack_60,0x32,"%s\\%s","I:\\FT-710\\DEBUG_RECV_CMD","SEND_CMD.TXT");
    iVar2 = fs_fopen(auStack_60,&DAT_20135124);
    uVar5 = 0;
    if (iVar2 != 0) {
      do {
        memclr(local_e58,3000);
        iVar3 = FUN_20134e70(&local_e5c,iVar2);
        cVar1 = local_e58[0];
        if (iVar3 == -1) break;
        if (iVar3 == 1) {
          memclr(local_2a0,0x240);
          uVar4 = 0;
          do {
            if ((&DAT_2080893c)[uVar4 * 0xc] == cVar1) {
              FUN_20155310(local_2a0,local_e58,local_e5a);
              break;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < 0x1a);
          if (local_2a0[0] != '\0') {
            FUN_2011508c(local_2a0);
          }
          itron_dly_tsk(local_e5c / 10);
        }
      } while (DAT_20808931 != '\x02');
      FUN_20141ff0(iVar2);
      uVar5 = 1;
    }
  }
  return uVar5;
}


// ===== task_test_disp @ 2013512c (96 bytes)

void task_test_disp(void)

{
  int iVar1;
  int local_1c [2];
  
  DAT_20808931 = 2;
  while( true ) {
    iVar1 = itron_twai_flg(DAT_20808934,0xffff,5,local_1c,0xffffffff);
    if (iVar1 != 0) break;
    if (local_1c[0] == 1) {
      DAT_20808931 = 1;
      debug_recv_cmd_log();
      DAT_20808931 = 2;
    }
  }
  return;
}


// ===== FUN_2013518c @ 2013518c (16 bytes)

void FUN_2013518c(void)

{
  itron_set_flg(DAT_20808934,1);
  return;
}

