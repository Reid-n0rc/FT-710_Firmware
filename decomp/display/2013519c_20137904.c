// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2013519c @ 2013519c (16 bytes)

void FUN_2013519c(void)

{
  DAT_20808931 = 2;
  return;
}


// ===== FUN_201351ac @ 201351ac (12 bytes)

undefined1 FUN_201351ac(void)

{
  return DAT_20808931;
}


// ===== FUN_201351b8 @ 201351b8 (264 bytes)

void FUN_201351b8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_28 [12];
  
  iVar1 = fs_fopen(param_1,&DAT_201352c0);
  if (iVar1 != 0) {
    FUN_20154a30(auStack_28,5,"%03d:",param_3);
    fs_fwrite(auStack_28,4,1,iVar1);
    iVar2 = 0;
    if (0 < param_3 + -1) {
      do {
        FUN_20154a30(auStack_28,4,"%02x ",*(undefined1 *)(param_2 + iVar2));
        fs_fwrite(auStack_28,3,1,iVar1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_3 + -1);
    }
    FUN_20154a30(auStack_28,4,&DAT_201352d4,*(undefined1 *)(param_2 + param_3 + -1));
    fs_fwrite(auStack_28,2,1,iVar1);
    FUN_20154a30(auStack_28,6,":%04d",1000);
    fs_fwrite(auStack_28,5,1,iVar1);
    fs_fwrite(&DAT_201352e4,1,1,iVar1);
    FUN_20141ff0(iVar1);
  }
  return;
}


// ===== FUN_201352e8 @ 201352e8 (228 bytes)

undefined4 FUN_201352e8(undefined1 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_44 [56];
  
  iVar1 = FUN_20103ba0();
  uVar2 = 0;
  if (iVar1 != 0) {
    DAT_20808930 = *param_1;
    FUN_20154a30(auStack_44,0x32,"%s\\%s","I:\\FT-710\\DEBUG_RECV_CMD","dummy.txt");
    iVar1 = fs_fopen(auStack_44,&DAT_201353d8);
    if ((iVar1 == 0) &&
       (((iVar1 = FUN_2014beec("I:\\FT-710\\DEBUG_RECV_CMD"), iVar1 != 0 &&
         ((iVar1 = FUN_2014beec("I:\\FT-710"), iVar1 != 0 ||
          (iVar1 = FUN_2014beec("I:\\FT-710\\DEBUG_RECV_CMD"), iVar1 != 0)))) ||
        (iVar1 = fs_fopen(auStack_44,&DAT_201353d8), iVar1 == 0)))) {
      FUN_2014d95c();
      return 0xffffffff;
    }
    FUN_20141ff0();
    FUN_20154a30(auStack_44,0x32,"%s\\%s","I:\\FT-710\\DEBUG_RECV_CMD","RECV_CMD.TXT");
    uVar2 = FUN_201351b8(auStack_44,param_1,param_2);
  }
  return uVar2;
}


// ===== FUN_201353f8 @ 201353f8 (80 bytes)

int FUN_201353f8(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = 1;
  }
  iVar1 = (int)param_1 / 10;
  iVar3 = ((int)param_1 % 10) * iVar2;
  if (iVar3 == 5) {
    if ((param_1 & 1) == 0) {
      return iVar1;
    }
  }
  else if (iVar3 < 6) {
    return iVar1;
  }
  return iVar1 + iVar2;
}


// ===== FUN_20135458 @ 20135458 (24 bytes)

int FUN_20135458(uint param_1)

{
  return (int)(char)(((byte)param_1 & 0xf) + (char)(param_1 >> 4) * '\n');
}


// ===== FUN_20135470 @ 20135470 (24 bytes)

uint FUN_20135470(byte *param_1)

{
  return (uint)param_1[1] | (int)(short)((ushort)*param_1 << 8);
}


// ===== FUN_20135488 @ 20135488 (16 bytes)

void FUN_20135488(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)((uint)param_1 >> 8);
  param_2[1] = (char)param_1;
  return;
}


// ===== FUN_20135498 @ 20135498 (36 bytes)

uint FUN_20135498(byte *param_1)

{
  return (uint)param_1[3] |
         (uint)*param_1 << 0x18 | (uint)param_1[1] << 0x10 | (uint)param_1[2] << 8;
}


// ===== FUN_201354ec @ 201354ec (60 bytes)

void FUN_201354ec(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = FUN_20155122();
  while ((uVar1 = uVar2 & 0xff, uVar1 != 0 && (*(char *)(param_1 + uVar1 + -1) == ' '))) {
    uVar2 = uVar1 - 1;
    *(undefined1 *)(param_1 + uVar1 + -1) = 0;
  }
  return;
}


// ===== FUN_20135534 @ 20135534 (88 bytes)

void FUN_20135534(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  iVar1 = 0;
  param_1 = param_1 + (param_3 + param_2 * 800) * 2;
  if (0 < param_6) {
    do {
      memcpy(param_1,param_4,param_5 << 1);
      iVar1 = iVar1 + 1;
      param_4 = param_4 + param_5 * 2;
      param_1 = param_1 + 0x640;
    } while (iVar1 < param_6);
  }
  return;
}


// ===== FUN_2013558c @ 2013558c (48 bytes)

undefined4 FUN_2013558c(uint param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  
  if (param_1 < 0x1e0) {
    bVar1 = 0x1df < param_4 + param_1;
    if (param_4 + param_1 < 0x1e1) {
      bVar1 = 799 < param_2;
    }
    if ((!bVar1) && (param_3 + param_2 < 0x321)) {
      return 1;
    }
  }
  return 0;
}


// ===== fb_copy_rect @ 201355bc (72 bytes)

void fb_copy_rect(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = 0;
  param_1 = param_1 + (param_3 + param_2 * 800) * 2;
  if (0 < param_5) {
    do {
      FUN_20155274(param_1,param_4 << 1);
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x640;
    } while (iVar1 < param_5);
  }
  return;
}


// ===== FUN_20135604 @ 20135604 (84 bytes)

bool FUN_20135604(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 extraout_r12;
  
  iVar1 = FUN_2013558c(param_2,param_3,param_4,param_5,param_4);
  if (iVar1 != 0) {
    fb_copy_rect(param_1,param_2,param_3,param_4,extraout_r12);
  }
  return iVar1 != 0;
}


// ===== fb_fill_rect @ 20135658 (128 bytes)

/* stride 0x640 (800 px * 2) */

void fb_fill_rect(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_2 == 0) {
    fb_copy_rect(param_1,param_3,param_4,param_5,param_6);
    return;
  }
  param_6 = param_6 + param_3;
  param_1 = param_1 + param_3 * 0x640;
  if (param_3 < param_6) {
    iVar1 = param_4;
    do {
      for (; iVar1 < param_5 + param_4; iVar1 = iVar1 + 1) {
        *(short *)(param_1 + iVar1 * 2) = (short)param_2;
      }
      param_3 = param_3 + 1;
      param_1 = param_1 + 0x640;
      iVar1 = param_4;
    } while (param_3 < param_6);
  }
  return;
}


// ===== FUN_201356d8 @ 201356d8 (100 bytes)

bool FUN_201356d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 extraout_r12;
  
  iVar1 = FUN_2013558c(param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    fb_fill_rect(param_1,param_2,param_3,param_4,param_5,extraout_r12);
  }
  return iVar1 != 0;
}


// ===== FUN_2013573c @ 2013573c (172 bytes)

void FUN_2013573c(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,int param_7)

{
  uint uVar1;
  
  fb_fill_rect();
  fb_fill_rect(param_1,param_2,(param_3 + param_6) - param_7 & 0xffff,param_4,param_5,param_7);
  uVar1 = param_6 + param_7 * -2 & 0xffff;
  fb_fill_rect(param_1,param_2,param_3 + param_7 & 0xffff,param_4,param_7,uVar1);
  fb_fill_rect(param_1,param_2,param_3 + param_7 & 0xffff,(param_4 + param_5) - param_7 & 0xffff,
               param_7,uVar1);
  return;
}


// ===== FUN_201357e8 @ 201357e8 (124 bytes)

undefined4
FUN_201357e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5,uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r12;
  
  iVar1 = FUN_2013558c(param_3,param_4,param_5,param_6);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (param_6 < (uint)(extraout_r12 << 1) || param_5 < (uint)(extraout_r12 << 1)) {
      uVar2 = 0;
    }
    else {
      FUN_2013573c(param_1,param_2,param_3,param_4,param_5,param_6,extraout_r12);
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ===== FUN_20135864 @ 20135864 (108 bytes)

void FUN_20135864(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                 ushort param_7)

{
  ushort *puVar1;
  int iVar2;
  
  param_1 = param_1 + param_2 * 0x640;
  param_5 = param_5 + param_2;
  if (param_2 < param_5) {
    iVar2 = param_3;
    do {
      while (iVar2 < param_4 + param_3) {
        puVar1 = (ushort *)(param_1 + iVar2 * 2);
        iVar2 = iVar2 + 1;
        if (*puVar1 == param_6) {
          *puVar1 = param_7;
        }
      }
      param_2 = param_2 + 1;
      param_1 = param_1 + 0x640;
      iVar2 = param_3;
    } while (param_2 < param_5);
  }
  return;
}


// ===== gui_draw_runs @ 201358d0 (160 bytes)

void gui_draw_runs(int param_1,int param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar2 = *param_4;
  iVar4 = 0;
  uVar5 = 0;
  if (*(int *)(param_4 + 2) != 0) {
    do {
      uVar6 = (uint)*(ushort *)(*(int *)(param_4 + 4) + uVar5 * 4);
      for (uVar3 = (uint)*(ushort *)(*(int *)(param_4 + 4) + uVar5 * 4 + 2); uVar3 != 0;
          uVar3 = uVar3 - 1) {
        uVar7 = __aeabi_uidivmod(uVar6,uVar2);
        uVar6 = uVar6 + 1;
        iVar1 = iVar4 * 2;
        iVar4 = iVar4 + 1;
        *(undefined2 *)
         (param_1 + (param_3 + param_2 * 800) * 2 +
         (int)((ulonglong)uVar7 >> 0x20) * 2 + (int)uVar7 * 0x640) =
             *(undefined2 *)(*(int *)(param_4 + 6) + iVar1);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_4 + 2));
  }
  return;
}


// ===== FUN_20135970 @ 20135970 (76 bytes)

bool FUN_20135970(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4)

{
  int iVar1;
  undefined4 extraout_r12;
  
  iVar1 = FUN_2013558c(param_2,param_3,*param_4,param_4[1]);
  if (iVar1 != 0) {
    gui_draw_runs(param_1,param_2,param_3,extraout_r12);
  }
  return iVar1 != 0;
}


// ===== FUN_201359bc @ 201359bc (156 bytes)

void FUN_201359bc(int param_1,int param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined8 uVar6;
  
  iVar3 = 0;
  uVar5 = 0;
  if (*(int *)(param_4 + 2) != 0) {
    do {
      uVar2 = 0;
      piVar4 = (int *)(*(int *)(param_4 + 4) + uVar5 * 8);
      if (piVar4[1] != 0) {
        do {
          uVar6 = FUN_20156260(*piVar4 + uVar2,*param_4);
          uVar2 = uVar2 + 1;
          iVar1 = iVar3 * 2;
          iVar3 = iVar3 + 1;
          *(undefined2 *)
           (param_1 + (param_3 + param_2 * 800) * 2 +
           (int)((ulonglong)uVar6 >> 0x20) * 2 + (int)uVar6 * 0x640) =
               *(undefined2 *)(*(int *)(param_4 + 6) + iVar1);
        } while (uVar2 < (uint)piVar4[1]);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_4 + 2));
  }
  return;
}


// ===== FUN_20135a58 @ 20135a58 (76 bytes)

bool FUN_20135a58(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4)

{
  int iVar1;
  undefined4 extraout_r12;
  
  iVar1 = FUN_2013558c(param_2,param_3,*param_4,param_4[1]);
  if (iVar1 != 0) {
    FUN_201359bc(param_1,param_2,param_3,extraout_r12);
  }
  return iVar1 != 0;
}


// ===== FUN_20135aa4 @ 20135aa4 (52 bytes)

void FUN_20135aa4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  fb_fill_rect(param_1,param_6,param_2,param_3,param_4,param_5);
  return;
}


// ===== FUN_20135ad8 @ 20135ad8 (52 bytes)

void FUN_20135ad8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  fb_fill_rect(param_1,param_6,param_2,param_3,param_5,param_4);
  return;
}


// ===== FUN_20135b0c @ 20135b0c (96 bytes)

void FUN_20135b0c(int param_1,int param_2)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar1 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      puVar2 = (ushort *)(*(int *)(param_1 + 8) + uVar1 * 4);
      memcpy(param_2 + (uint)*puVar2 * 2,*(int *)(param_1 + 0xc) + iVar3 * 2,(uint)puVar2[1] << 1);
      uVar1 = uVar1 + 1;
      iVar3 = iVar3 + (uint)puVar2[1];
    } while (uVar1 < *(uint *)(param_1 + 4));
  }
  return;
}


// ===== FUN_20135b6c @ 20135b6c (168 bytes)

void FUN_20135b6c(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_160 [300];
  undefined4 local_34;
  uint uStack_30;
  int iStack_2c;
  undefined4 local_28;
  
  iVar3 = 0;
  if (0 < param_3 * 2) {
    local_34 = param_1;
    uStack_30 = param_2;
    iStack_2c = param_3;
    local_28 = param_4;
    do {
      memclr(auStack_160,300);
      uVar1 = param_2 >> ((param_3 * 8 + iVar3 * -4) - 4U & 0xff) & 0xf;
      if (uVar1 < 10) {
        iVar2 = uVar1 + 0x10;
      }
      else {
        iVar2 = uVar1 + 0x37;
      }
      FUN_20135b0c((&PTR_DAT_20803738)[iVar2],auStack_160);
      FUN_20135534(local_34,local_28,iVar3 * 0xb + param_5 & 0xffff,auStack_160,10,0xf);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3 * 2);
  }
  return;
}


// ===== FUN_20135c14 @ 20135c14 (212 bytes)

void FUN_20135c14(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_160 [300];
  undefined4 local_34;
  undefined4 local_30;
  int iStack_2c;
  undefined4 local_28;
  
  iVar6 = 0;
  local_34 = param_1;
  local_30 = param_2;
  iStack_2c = param_3;
  local_28 = param_4;
  if (0 < param_3) {
    do {
      iVar4 = 1;
      iVar5 = (param_3 - iVar6) + -1;
      iVar1 = 0;
      if (0 < iVar5) {
        do {
          iVar1 = iVar1 + 1;
          iVar4 = iVar4 * 10;
        } while (iVar1 < iVar5);
      }
      uVar2 = FUN_20156260(local_30,iVar4);
      uVar3 = uVar2 % 10;
      if (uVar3 < 10) {
        iVar4 = uVar3 + 0x10;
      }
      else {
        iVar4 = uVar3 + 0x37;
      }
      memclr(auStack_160,300,uVar2 * -0x33333333);
      FUN_20135b0c((&PTR_DAT_20803738)[iVar4],auStack_160);
      FUN_20135534(local_34,local_28,iVar6 * 0xb + param_5 & 0xffff,auStack_160,10,0xf);
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_3);
  }
  return;
}


// ===== FUN_20135ce8 @ 20135ce8 (236 bytes)

void FUN_20135ce8(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int param_5,
                 uint param_6,ushort param_7)

{
  uint uVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  ushort local_290 [150];
  undefined2 local_164 [152];
  undefined4 local_34;
  uint uStack_30;
  int iStack_2c;
  undefined4 local_28;
  
  uVar1 = 0;
  do {
    puVar3 = local_164 + uVar1;
    uVar1 = uVar1 + 1;
    *puVar3 = (short)param_6;
  } while (uVar1 < 0x96);
  iVar4 = 0;
  if (0 < param_3 * 2) {
    local_34 = param_1;
    uStack_30 = param_2;
    iStack_2c = param_3;
    local_28 = param_4;
    do {
      uVar1 = param_2 >> ((param_3 * 8 + iVar4 * -4) - 4U & 0xff) & 0xf;
      if (uVar1 < 10) {
        iVar5 = uVar1 + 0x10;
      }
      else {
        iVar5 = uVar1 + 0x37;
      }
      FUN_20155310(local_290,local_164,300);
      FUN_20135b0c((&PTR_DAT_20803738)[iVar5],local_290);
      uVar1 = 0;
      do {
        puVar2 = local_290 + uVar1;
        uVar1 = uVar1 + 1;
        if (*puVar2 != param_6) {
          *puVar2 = param_7;
        }
      } while (uVar1 < 0x96);
      FUN_20135534(local_34,local_28,param_5 + iVar4 * 10 & 0xffff,local_290,10,0xf);
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_3 * 2);
  }
  return;
}


// ===== FUN_20135dd4 @ 20135dd4 (108 bytes)

void FUN_20135dd4(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = param_2;
  uVar4 = param_3;
  iVar5 = param_4;
  uVar1 = FUN_20155122(param_2);
  uVar2 = 0;
  if ((uVar1 & 0xffff) != 0) {
    do {
      gui_draw_runs(param_1,param_3,param_5 * uVar2 + param_4 & 0xffff,
                    *(undefined4 *)
                     (param_6 + (uint)(byte)(&DAT_2080173c)[*(byte *)(param_2 + uVar2)] * 4),param_1
                    ,iVar3,uVar4,iVar5);
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < (uVar1 & 0xffff));
  }
  return;
}


// ===== FUN_20135e40 @ 20135e40 (128 bytes)

void FUN_20135e40(undefined4 param_1,int param_2,undefined4 param_3,short param_4,int param_5)

{
  uint uVar1;
  
  uVar1 = FUN_20155122(param_2);
  uVar1 = uVar1 & 0xffff;
  param_4 = **(short **)(param_5 + (uint)(byte)(&DAT_2080173c)[*(byte *)(param_2 + uVar1 + -1)] * 4)
            + param_4;
  while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
    param_4 = param_4 - **(short **)
                          (param_5 + (uint)(byte)(&DAT_2080173c)[*(byte *)(param_2 + uVar1)] * 4);
    gui_draw_runs(param_1,param_3,param_4);
  }
  return;
}


// ===== FUN_20135ec0 @ 20135ec0 (288 bytes)

void FUN_20135ec0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_160 [256];
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
  undefined1 *local_24 [2];
  
  local_24[0] = auStack_160;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  uVar1 = FUN_20155122(param_2);
  memcpy(&local_60,param_2,uVar1);
  iVar2 = FUN_2014e320(&local_60,&DAT_20135fec,local_24);
  FUN_20135dd4(param_1,iVar2,param_3,param_4,param_5,param_6);
  iVar3 = FUN_20155122(iVar2);
  uVar4 = iVar3 * param_5 + param_4;
  if (iVar2 != 0) {
    while( true ) {
      iVar2 = FUN_2014e320(local_24[0],&DAT_20135fec,local_24);
      if (iVar2 == 0) break;
      uVar4 = (uVar4 & 0xffff) + (param_5 >> 1) & 0xffff;
      FUN_20135dd4(param_1,iVar2,param_3,uVar4,param_5,param_6);
      iVar2 = FUN_20155122(iVar2);
      uVar4 = iVar2 * param_5 + uVar4;
    }
  }
  return;
}


// ===== FUN_20135ff0 @ 20135ff0 (156 bytes)

void FUN_20135ff0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,uint param_5,
                 undefined4 param_6)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar4 = 0;
  iVar2 = FUN_20155122(param_2);
  if (iVar2 != 0) {
    do {
      pcVar1 = (char *)(param_2 + uVar4);
      uVar4 = uVar4 + 1;
      if (*pcVar1 == ' ') {
        iVar5 = iVar5 + 1;
      }
      uVar3 = FUN_20155122(param_2);
    } while (uVar4 < uVar3);
  }
  iVar2 = FUN_20155122(param_2);
  FUN_20135ec0(param_1,param_2,param_3,
               param_4 - ((iVar5 * (param_5 >> 1) + (iVar2 - iVar5) * param_5 & 0xffff) >> 1) &
               0xffff,param_5,param_6);
  return;
}


// ===== FUN_2013608c @ 2013608c (36 bytes)

void FUN_2013608c(void)

{
  FUN_20135dd4();
  return;
}


// ===== FUN_201360b0 @ 201360b0 (216 bytes)

void FUN_201360b0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  iVar3 = 0;
  sVar5 = -1;
  uVar4 = 0;
  if (0 < param_3) {
    do {
      if (*(char *)(param_1 + uVar4) == *(char *)(param_2 + uVar4)) {
        uVar2 = 0x94b2;
      }
      else {
        uVar2 = 0xffe0;
      }
      if ((uVar4 & 0x1f) == 0) {
        iVar3 = 0;
        sVar5 = sVar5 + 1;
      }
      else if (iVar3 != 0) {
        if ((uVar4 & 1) == 0) {
          iVar3 = iVar3 + 2;
        }
        if ((uVar4 & 3) == 0) {
          iVar3 = iVar3 + 2;
        }
        if ((uVar4 & 7) == 0) {
          iVar3 = iVar3 + 2;
        }
        if ((uVar4 & 0xf) == 0) {
          iVar3 = iVar3 + 2;
        }
      }
      FUN_20135ce8(uVar1,*(char *)(param_1 + uVar4),1,sVar5 * 0xe + 200,iVar3 + 2U & 0xffff,0x20,
                   uVar2);
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x15;
    } while ((int)uVar4 < param_3);
  }
  return;
}


// ===== FUN_20136188 @ 20136188 (264 bytes)

void FUN_20136188(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  iVar2 = 0;
  sVar4 = -1;
  uVar3 = 0;
  if (0 < param_3) {
    do {
      unaff_r8 = 0x20;
      if (*(char *)(param_1 + uVar3) == *(char *)(param_2 + uVar3)) {
        unaff_r7 = 0x94b2;
      }
      else {
        unaff_r7 = 0xffe0;
      }
      if ((uVar3 & 0x1f) == 0) {
        iVar2 = 0;
        sVar4 = sVar4 + 1;
      }
      else if (iVar2 != 0) {
        if ((uVar3 & 1) == 0) {
          iVar2 = iVar2 + 2;
        }
        if ((uVar3 & 3) == 0) {
          iVar2 = iVar2 + 2;
        }
        if ((uVar3 & 7) == 0) {
          iVar2 = iVar2 + 2;
        }
        if ((uVar3 & 0xf) == 0) {
          iVar2 = iVar2 + 2;
        }
      }
      FUN_20135ce8(uVar1,*(char *)(param_1 + uVar3),1,sVar4 * 0xe + 2,iVar2 + 2U & 0xffff,0x20,
                   unaff_r7);
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x15;
    } while ((int)uVar3 < param_3);
  }
  FUN_20135ce8(uVar1,DAT_20450034,1,sVar4 * 0xe + 0x10,2,unaff_r8,unaff_r7);
  return;
}


// ===== FUN_20136290 @ 20136290 (264 bytes)

void FUN_20136290(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  undefined2 uVar1;
  int iVar2;
  
  FUN_20135ad8(param_1,param_2 + 1U & 0xffff,param_3,param_5 - 2U & 0xffff,param_6,param_7);
  FUN_20135ad8(param_1,param_2 + 1U & 0xffff,(param_3 + param_4) - param_6 & 0xffff,
               param_5 - 2U & 0xffff,param_6,param_7);
  FUN_20135aa4(param_1,param_2,param_3 + 1U & 0xffff,param_4 - 2U & 0xffff,param_6,param_7);
  FUN_20135aa4(param_1,(param_2 + param_5) - param_6 & 0xffff,param_3 + 1U & 0xffff,
               param_4 - 2U & 0xffff,param_6,param_7);
  param_1 = param_1 + (param_3 + param_2 * 800) * 2;
  uVar1 = (undefined2)param_7;
  *(undefined2 *)(param_1 + param_6 * 0x642) = uVar1;
  *(undefined2 *)(param_1 + (param_4 + param_6 * 799) * 2 + -2) = uVar1;
  iVar2 = (param_5 - param_6) + -1;
  *(undefined2 *)(param_1 + (param_6 + iVar2 * 800) * 2) = uVar1;
  *(undefined2 *)(param_1 + ((param_4 + iVar2 * 800) - param_6) * 2 + -2) = uVar1;
  return;
}


// ===== FUN_20136398 @ 20136398 (40 bytes)

void FUN_20136398(void)

{
  FUN_20136290();
  return;
}


// ===== FUN_201363c0 @ 201363c0 (452 bytes)

void FUN_201363c0(undefined4 param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  fb_fill_rect(param_1,param_9,param_2,param_3,param_4,param_5);
  FUN_20135ad8(param_1,param_2 - 1 & 0xffff,param_3 - 2U & 0xffff,param_5 + 2 & 0xffff,2,param_9);
  FUN_20135ad8(param_1,param_2 - 1 & 0xffff,param_3 + param_4 & 0xffff,param_5 + 2 & 0xffff,2,
               param_9);
  FUN_20135aa4(param_1,param_2 - 2 & 0xffff,param_3 - 1U & 0xffff,param_4 + 2U & 0xffff,2,param_9);
  uVar4 = param_2 + param_5;
  FUN_20135aa4(param_1,uVar4 & 0xffff,param_3 - 1U & 0xffff,param_4 + 2U & 0xffff,2,param_9);
  if (param_8 < param_7) {
    iVar1 = __aeabi_uidivmod(param_5 * 10,param_7);
    uVar2 = (iVar1 * param_6) / 10 + param_2 & 0xffff;
    uVar3 = (iVar1 * param_8) / 10 & 0xffff;
    if (param_5 < uVar3) {
      uVar3 = param_5 & 0xffff;
    }
    iVar1 = (iVar1 * (param_7 - param_8)) / 10 + param_2 + uVar3;
    if (iVar1 < (int)uVar4) {
      uVar3 = (uVar4 - iVar1) + uVar3 & 0xffff;
    }
    if ((param_2 <= uVar2) && (uVar2 + uVar3 <= uVar4)) {
      fb_fill_rect(param_1,0x632c,uVar2,param_3,param_4,uVar3);
    }
  }
  return;
}


// ===== FUN_20136584 @ 20136584 (40 bytes)

void FUN_20136584(void)

{
  FUN_201363c0();
  return;
}


// ===== FUN_201365ac @ 201365ac (196 bytes)

void FUN_201365ac(int param_1,int param_2,int param_3,undefined2 *param_4,int param_5,int param_6)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  
  iVar6 = 0;
  uVar8 = 0;
  if (*(int *)(param_4 + 2) != 0) {
    do {
      iVar5 = 0;
      puVar7 = (ushort *)(*(int *)(param_4 + 4) + uVar8 * 4);
      if (puVar7[1] != 0) {
        do {
          uVar10 = __aeabi_uidivmod((uint)*puVar7 + iVar5,*param_4);
          iVar3 = (int)((ulonglong)uVar10 >> 0x20);
          iVar4 = param_3 + iVar3;
          bVar9 = SBORROW4(iVar4,param_5);
          iVar1 = iVar4 - param_5;
          if (param_5 <= iVar4) {
            bVar9 = SBORROW4(param_6,iVar4);
            iVar1 = param_6 - iVar4;
          }
          if (iVar1 < 0 == bVar9) {
            psVar2 = (short *)(param_1 + (param_3 + param_2 * 800) * 2 +
                              iVar3 * 2 + (int)uVar10 * 0x640);
            if (*psVar2 == 0) {
              *psVar2 = *(short *)(*(int *)(param_4 + 6) + iVar6 * 2);
            }
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 1;
        } while (iVar5 < (int)(uint)puVar7[1]);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_4 + 2));
  }
  return;
}


// ===== FUN_20136670 @ 20136670 (112 bytes)

void FUN_20136670(int param_1,int param_2,int param_3,uint param_4,uint param_5,short param_6)

{
  uint uVar1;
  short *psVar2;
  uint uVar3;
  
  uVar3 = 0;
  param_1 = param_1 + (param_3 + param_2 * 800) * 2;
  if (param_5 != 0) {
    do {
      uVar1 = 0;
      if (param_4 != 0) {
        do {
          psVar2 = (short *)(param_1 + uVar1 * 2);
          uVar1 = uVar1 + 1 & 0xffff;
          if (*psVar2 == 0) {
            *psVar2 = param_6;
          }
        } while (uVar1 < param_4);
      }
      param_1 = param_1 + 0x640;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < param_5);
  }
  return;
}


// ===== FUN_201366e0 @ 201366e0 (200 bytes)

void FUN_201366e0(int param_1,int param_2,int param_3,undefined2 *param_4,int param_5,int param_6)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  
  iVar7 = 0;
  uVar9 = 0;
  if (*(int *)(param_4 + 2) != 0) {
    do {
      iVar6 = 0;
      puVar8 = (ushort *)(*(int *)(param_4 + 4) + uVar9 * 4);
      if (puVar8[1] != 0) {
        do {
          uVar11 = __aeabi_uidivmod((uint)*puVar8 + iVar6,*param_4);
          iVar4 = (int)((ulonglong)uVar11 >> 0x20);
          iVar5 = param_3 + iVar4;
          bVar10 = SBORROW4(iVar5,param_5);
          iVar1 = iVar5 - param_5;
          if (param_5 <= iVar5) {
            bVar10 = SBORROW4(param_6,iVar5);
            iVar1 = param_6 - iVar5;
          }
          if ((iVar1 < 0 == bVar10) &&
             (psVar3 = (short *)(param_1 + (param_3 + param_2 * 800) * 2 +
                                iVar4 * 2 + (int)uVar11 * 0x640), sVar2 = *psVar3,
             sVar2 == 0 || sVar2 == 0x1f)) {
            *psVar3 = *(short *)(*(int *)(param_4 + 6) + iVar7 * 2);
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar6 < (int)(uint)puVar8[1]);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(param_4 + 2));
  }
  return;
}


// ===== FUN_201367b4 @ 201367b4 (2056 bytes)

void FUN_201367b4(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  iVar3 = debug_enabled();
  if (iVar3 != 0) {
    if ((DAT_20808a84 & 1) != 0) {
      FUN_20135dd4(uVar2,DAT_2080039c,1,2,10,&DAT_20803730);
      if (DAT_20808a74 == 0) {
        if (DAT_208dbb44 == 1) {
          DAT_20808a78 = DAT_183e0010;
        }
        else if (DAT_208dbb44 == 2) {
          DAT_20808a78 = DAT_183f0010;
        }
        else if (DAT_208dbb44 == 0xbbbb) {
          DAT_20808a78 = DAT_183c0010;
        }
        DAT_20808a74 = 1;
      }
      FUN_20135b6c(uVar2,DAT_20808a78,4,0x14,2);
      DAT_20808a80 = DAT_20808a80 + 1;
      if (DAT_20808a80 == DAT_20808a7c) {
        DAT_20808a80 = 0;
        FUN_20135dd4(uVar2,&DAT_20136c3c,2,0x82,10,&DAT_20803730);
        FUN_20135c14(uVar2,(uint)((ulonglong)(uint)(param_1 * 100) * 0xa7c5ac47 + 0xa7c5ac47 >> 0x31
                                 ),3,2,0xa5);
      }
      FUN_20135dd4(uVar2,&DAT_20136c44,2,0xd2,10,&DAT_20803730);
      uVar4 = FUN_20114920();
      FUN_20135c14(uVar2,uVar4,4,2,0xe1);
      FUN_20135dd4(uVar2,&DAT_20136c48,2,0x118,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_208085a8,3,2,0x127);
      FUN_20135dd4(uVar2,&DAT_20136c50,2,0x154,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_208085ac,3,2,0x163);
      FUN_20135dd4(uVar2,&DAT_20136c58,2,0x19a,10,&DAT_20803730);
      uVar4 = FUN_20116368();
      FUN_20135c14(uVar2,uVar4,2,2,0x1a9);
      FUN_20135dd4(uVar2,&DAT_20136c5c,2,0x1cc,10,&DAT_20803730);
      uVar4 = FUN_2011637c();
      FUN_20135c14(uVar2,uVar4,2,2,0x1db);
      bVar5 = (byte)DAT_208dbb4c & 0xf;
      bVar1 = (char)DAT_208dbb44 << 4;
      FUN_20135dd4(uVar2,&DAT_20136c60,2,0x1fe,10,&DAT_20803730);
      FUN_20135b6c(uVar2,bVar5 | bVar1,1,2,0x20d);
      FUN_20135dd4(uVar2,&DAT_20136c64,2,0x230,10,&DAT_20803730);
      uVar4 = FUN_2011492c();
      FUN_20135c14(uVar2,uVar4,4,2,0x23f);
      FUN_20135dd4(uVar2,&DAT_20136c68,0xd2,0x32,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_20800474,2,0xd2,0x69);
      FUN_20135b6c(uVar2,DAT_2080046c,1,0xd2,0x8a);
      FUN_20135dd4(uVar2,&DAT_20136c74,0xe9,0x32,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_20800478,2,0xe9,0x69);
      FUN_20135dd4(uVar2,&DAT_20136c80,0x100,0x32,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_20800074,4,0x100,0x69);
      FUN_20135dd4(uVar2,&DAT_20136c88,0x117,0x32,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_2080007a,4,0x117,0x69);
      FUN_20135c14(uVar2,DAT_20800076,3,0x117,0xa0);
      FUN_20135dd4(uVar2,&DAT_20136c94,0x12e,0x32,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_2080007c,4,0x12e,0x69);
      FUN_20135c14(uVar2,DAT_20800078,3,0x12e,0xa0);
      FUN_20135dd4(uVar2,&DAT_20136c64,0x145,0x32,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_20800084,4,0x145,0x69);
      FUN_20135dd4(uVar2,&DAT_2013703c,0x15c,0x32,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_20800080,10,0x15c,0x69);
    }
    if ((DAT_20808a84 & 2) != 0) {
      iVar3 = FUN_2015507c(&DAT_2045f260,&DAT_20909db4,0x200);
      if (iVar3 != 0) {
        FUN_201360b0(&DAT_2045f260,&DAT_20909db4,0x200);
        memcpy(&DAT_20909db4,&DAT_2045f260,0x240);
      }
      iVar3 = FUN_2015507c(&DAT_2045f4a0,&DAT_20909ff4,0x20);
      if (iVar3 != 0) {
        FUN_20136188(&DAT_2045f4a0,&DAT_20909ff4,0x20);
        memcpy(&DAT_20909ff4,&DAT_2045f4a0,0x401);
      }
    }
    if ((DAT_20808a84 & 0x60) != 0) {
      if ((DAT_20808a84 & 0x20) == 0) {
        if ((DAT_20808a88 & 0x20) != 0) {
          fb_copy_rect(uVar2,2,0x280,0x14,0xf);
        }
      }
      else {
        FUN_20135dd4(uVar2,&DAT_20137054,2,0x280,10,&DAT_20803730);
      }
      if ((DAT_20808a84 & 0x40) == 0) {
        if ((DAT_20808a88 & 0x40) != 0) {
          fb_copy_rect(uVar2,2,0x29a,0x14,0xf);
        }
      }
      else {
        FUN_20135dd4(uVar2,&DAT_20137060,2,0x29a,10,&DAT_20803730);
      }
    }
    if ((DAT_20808a84 & 0x400) == 0) {
      if ((DAT_20808a88 & 0x400) != 0) {
        fb_copy_rect(uVar2,2,0x2a8,0x32,0xf);
      }
    }
    else {
      FUN_20135dd4(uVar2,&DAT_20137064,2,0x2a8,10,&DAT_20803730);
      FUN_20135b6c(uVar2,DAT_20450284,1,2,0x2c1);
    }
    if (DAT_2080018c != 0) {
      FUN_20135dd4(uVar2,&DAT_20136c44,100,100,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_2080018c,4,100,0x6f);
    }
    if (DAT_2080016c != 0) {
      FUN_20135dd4(uVar2,&DAT_20136c50,100,500,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_2080016c,8,100,0x1ff);
    }
    if (DAT_208001bc != 0) {
      FUN_20135dd4(uVar2,&DAT_20136c48,100,100,10,&DAT_20803730);
      FUN_20135c14(uVar2,DAT_208001bc,8,100,0x6f);
    }
    if (DAT_208001c0 != 0) {
      FUN_20135c14(uVar2,DAT_208001c0,3,0x14,300);
      FUN_20135c14(uVar2,DAT_208001c4,3,0x14,0x15e);
    }
  }
  DAT_20808a88 = DAT_20808a84;
  return;
}


// ===== FUN_20137080 @ 20137080 (504 bytes)

void FUN_20137080(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_e82000e8;
  DAT_e82000e8 = uVar1 | 2;
  uVar1 = DAT_e82000e8;
  DAT_e82000e8 = uVar1 | 8;
  FUN_201177a0(0x2c);
  DAT_20808a8c = 0;
  DAT_fcfe1004 = 0x1310000;
  DAT_e82000ec = 0;
  FUN_20157160(&DAT_e82000ec,0,0x10,0xf0000);
  FUN_20157160(&DAT_e82000ec,1,0xc,0xf000);
  FUN_20157160(&DAT_e82000ec,1,0x15,0x200000);
  FUN_20157160(&DAT_e82000ec,0,0x14,0x100000);
  FUN_20157160(&DAT_e82000ec,0,0x1f,0x80000000);
  FUN_20157160(&DAT_e82000ec,0,0x1c,0x10000000);
  FUN_20157160(&DAT_e82000ec,0,0x1b,0x8000000);
  FUN_20157160(&DAT_e82000ec,0,0x18,0x1000000);
  FUN_20157160(&DAT_e82000ec,0,0x1e,0x40000000);
  FUN_20157160(&DAT_e82000ec,0,0x1d,0x20000000);
  FUN_20157160(&DAT_e82000ec,0,0x16,0x400000);
  FUN_20157160(&DAT_e82000ec,2,8,0x700);
  FUN_20157160(&DAT_e82000ec,1,6,0x40);
  FUN_20157160(&DAT_e82000ec,1,5,0x20);
  FUN_20157160(&DAT_e82000ec,0,4,0x10);
  FUN_20157160(&DAT_e82000ec,1,3,8);
  FUN_20157160(&DAT_e82000ec,3,0,7);
  DAT_e82000f0 = 0;
  DAT_e82000f4 = 0;
  DAT_e82000c0 = param_1;
  DAT_e82000c4 = param_2;
  DAT_e82000c8 = param_3;
  FUN_20157160(&DAT_e8200300,1,0);
  iVar2 = itron_acre_isr(0,&DAT_204200b0);
  if (0 < iVar2) {
    gic_enable_irq(0x2c);
    return;
  }
  return;
}


// ===== FUN_20137278 @ 20137278 (536 bytes)

void FUN_20137278(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = DAT_e8200168;
  DAT_e8200168 = uVar1 | 2;
  uVar1 = DAT_e8200168;
  DAT_e8200168 = uVar1 | 8;
  FUN_201177a0(0x2e);
  DAT_20808a94 = 0;
  uVar1 = DAT_fcfe1008;
  DAT_fcfe1008 = uVar1 | 0x12a0000;
  DAT_e820016c = 0;
  FUN_20157160(&DAT_e820016c,0,0x10,0xf0000,uVar3);
  FUN_20157160(&DAT_e820016c,0,0xc,0xf000);
  FUN_20157160(&DAT_e820016c,0,0x15,0x200000);
  FUN_20157160(&DAT_e820016c,1,0x14,0x100000);
  FUN_20157160(&DAT_e820016c,0,0x1f,0x80000000);
  FUN_20157160(&DAT_e820016c,0,0x1c,0x10000000);
  FUN_20157160(&DAT_e820016c,1,0x1b,0x8000000);
  FUN_20157160(&DAT_e820016c,0,0x18,0x1000000);
  FUN_20157160(&DAT_e820016c,0,0x1e,0x40000000);
  FUN_20157160(&DAT_e820016c,0,0x1d,0x20000000);
  FUN_20157160(&DAT_e820016c,0,0x16,0x400000);
  FUN_20157160(&DAT_e820016c,2,8,0x700);
  FUN_20157160(&DAT_e820016c,1,6,0x40);
  FUN_20157160(&DAT_e820016c,1,5,0x20);
  FUN_20157160(&DAT_e820016c,0,4,0x10);
  FUN_20157160(&DAT_e820016c,0,3,8);
  FUN_20157160(&DAT_e820016c,5,0,7);
  DAT_e8200170 = 0;
  DAT_e8200174 = 0;
  DAT_e8200140 = param_1;
  DAT_e8200144 = param_2;
  DAT_e8200148 = param_3;
  FUN_20157160(&DAT_e8200300,1,0);
  iVar2 = itron_acre_isr(0,&DAT_204200d8);
  if (0 < iVar2) {
    gic_enable_irq(0x2e);
    FUN_20157160(&DAT_e8200168,1,0);
    return;
  }
  return;
}


// ===== FUN_201374ac @ 201374ac (536 bytes)

void FUN_201374ac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = DAT_e8200128;
  DAT_e8200128 = uVar1 | 2;
  uVar1 = DAT_e8200128;
  DAT_e8200128 = uVar1 | 8;
  FUN_201177a0(0x2d);
  DAT_20808a90 = 0;
  uVar1 = DAT_fcfe1008;
  DAT_fcfe1008 = uVar1 | 0x132;
  DAT_e820012c = 0;
  FUN_20157160(&DAT_e820012c,1,0x10,0xf0000,uVar3);
  FUN_20157160(&DAT_e820012c,0,0xc,0xf000);
  FUN_20157160(&DAT_e820012c,0,0x15,0x200000);
  FUN_20157160(&DAT_e820012c,1,0x14,0x100000);
  FUN_20157160(&DAT_e820012c,0,0x1f,0x80000000);
  FUN_20157160(&DAT_e820012c,0,0x1c,0x10000000);
  FUN_20157160(&DAT_e820012c,1,0x1b,0x8000000);
  FUN_20157160(&DAT_e820012c,0,0x18,0x1000000);
  FUN_20157160(&DAT_e820012c,0,0x1e,0x40000000);
  FUN_20157160(&DAT_e820012c,0,0x1d,0x20000000);
  FUN_20157160(&DAT_e820012c,0,0x16,0x400000);
  FUN_20157160(&DAT_e820012c,2,8,0x700);
  FUN_20157160(&DAT_e820012c,1,6,0x40);
  FUN_20157160(&DAT_e820012c,1,5,0x20);
  FUN_20157160(&DAT_e820012c,0,4,0x10);
  FUN_20157160(&DAT_e820012c,0,3,8);
  FUN_20157160(&DAT_e820012c,4,0,7);
  DAT_e8200130 = 0;
  DAT_e8200134 = 0;
  DAT_e8200100 = param_1;
  DAT_e8200104 = param_2;
  DAT_e8200108 = param_3;
  FUN_20157160(&DAT_e8200300,1,0);
  iVar2 = itron_acre_isr(0,&DAT_204200c4);
  if (0 < iVar2) {
    gic_enable_irq(0x2d);
    FUN_20157160(&DAT_e8200128,1,0);
    return;
  }
  return;
}


// ===== FUN_201376d0 @ 201376d0 (436 bytes)

void FUN_201376d0(void)

{
  uint uVar1;
  
  uVar1 = DAT_e8200428;
  DAT_e8200428 = uVar1 | 2;
  uVar1 = DAT_e8200428;
  DAT_e8200428 = uVar1 | 8;
  uVar1 = DAT_e8200428;
  DAT_e8200428 = uVar1 | 4;
  DAT_e820042c = 0;
  FUN_20157160(&DAT_e820042c,7,0x10,0xf0000);
  FUN_20157160(&DAT_e820042c,7,0xc,0xf000);
  FUN_20157160(&DAT_e820042c,0,0x15,0x200000);
  FUN_20157160(&DAT_e820042c,0,0x14,0x100000);
  FUN_20157160(&DAT_e820042c,0,0x1f,0x80000000);
  FUN_20157160(&DAT_e820042c,0,0x1c,0x10000000);
  FUN_20157160(&DAT_e820042c,0,0x1b,0x8000000);
  FUN_20157160(&DAT_e820042c,1,0x18,0x1000000);
  FUN_20157160(&DAT_e820042c,0,0x1e,0x40000000);
  FUN_20157160(&DAT_e820042c,0,0x1d,0x20000000);
  FUN_20157160(&DAT_e820042c,1,0x16,0x400000);
  FUN_20157160(&DAT_e820042c,4,8,0x700);
  FUN_20157160(&DAT_e820042c,1,6,0x40);
  FUN_20157160(&DAT_e820042c,1,5,0x20);
  FUN_20157160(&DAT_e820042c,0,4,0x10);
  FUN_20157160(&DAT_e820042c,0,3,8);
  FUN_20157160(&DAT_e820042c,0,0,7);
  DAT_e8200430 = 0;
  DAT_e8200434 = 0;
  FUN_20157160(&DAT_e8200700,1,0);
  return;
}


// ===== FUN_201378b0 @ 201378b0 (84 bytes)

void FUN_201378b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = DAT_e8200428;
  DAT_e8200428 = uVar1 | 2;
  uVar1 = DAT_e8200428;
  DAT_e8200428 = uVar1 | 8;
  uVar1 = DAT_e8200428;
  DAT_e8200428 = uVar1 | 4;
  DAT_e8200400 = param_2;
  DAT_e8200404 = param_1;
  DAT_e8200408 = param_3;
  FUN_20157160(&DAT_e8200428,1,0);
  return;
}


// ===== FUN_20137904 @ 20137904 (12 bytes)

void FUN_20137904(void)

{
  itron_acre_isr(0,&DAT_204200ec);
  return;
}

