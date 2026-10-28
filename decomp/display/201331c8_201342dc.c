// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201331c8 @ 201331c8 (20 bytes)

void FUN_201331c8(int param_1)

{
  DAT_20808598 = param_1;
  DAT_2080858e = *(undefined2 *)(param_1 + 2);
  return;
}


// ===== FUN_201331dc @ 201331dc (532 bytes)

void FUN_201331dc(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  thunk_FUN_20132fe0(&DAT_208f4dc8);
  DAT_208f4da4 = DAT_208f4da4 + 1;
  DAT_208085a0 = DAT_208085a0 + 1;
  puVar3 = &DAT_60502000;
  if (DAT_2080858c == '\0') {
    FUN_20120d40(&DAT_60502000);
    puVar2 = (undefined1 *)FUN_20132f7c();
    *puVar2 = DAT_60502000;
    puVar2[1] = DAT_60502001;
    puVar2[2] = DAT_60502002;
    puVar2[3] = DAT_60502003;
  }
  else {
    FUN_20120d40(&DAT_60503450);
    puVar3 = (undefined1 *)FUN_20132f7c();
    *puVar3 = DAT_60503450;
    puVar3[1] = DAT_60503451;
    puVar3[2] = DAT_60503452;
    puVar3[3] = DAT_60503453;
    puVar3 = &DAT_60503450;
  }
  FUN_201331c8(puVar3 + 600);
  FUN_20137dcc();
  FUN_2011f1ac(4);
  bVar1 = DAT_e800e803;
  if ((bVar1 & 1) != 0) {
    DAT_20808594 = DAT_20808594 + 1;
    DAT_208f4db4 = DAT_208f4db4 + 1;
    bVar1 = DAT_e800e803;
    DAT_e800e803 = bVar1 & 0xfe;
  }
  bVar1 = DAT_e800e803;
  if ((bVar1 & 4) != 0) {
    DAT_208f4db0 = DAT_208f4db0 + 1;
    bVar1 = DAT_e800e803;
    DAT_e800e803 = bVar1 & 0xfb;
  }
  FUN_20137d64();
  FUN_2011f7b4(4);
  DAT_2080858c = DAT_2080858c == '\0';
  if ((bool)DAT_2080858c) {
    DAT_e82000c0 = 0x605036a8;
    DAT_e8200104 = 0x60502000;
  }
  else {
    DAT_e82000c0 = 0x60502258;
    DAT_e8200104 = 0x60503450;
  }
  if (DAT_208000b2 != '\0') {
    memcpy(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8,DAT_20808598,4000);
    FUN_20106dc8(1,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8);
    DAT_208000b0 = DAT_208000b0 + 1;
    if (0xf < DAT_208000b0) {
      DAT_208000b0 = 0;
    }
  }
  if (DAT_208000b1 == '\0') {
    DAT_e82000c0 = &DAT_20906d60;
  }
  else {
    DAT_e82000c0 = &DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8;
    FUN_20106dc8(2);
    itron_set_flg(DAT_208000c8,4);
  }
  FUN_20137d50();
  FUN_20137db8();
  return;
}


// ===== FUN_201333f4 @ 201333f4 (36 bytes)

void FUN_201333f4(void)

{
  thunk_FUN_20132fe0();
  DAT_208085a8 = DAT_208085a8 + 1;
  FUN_2011f138(2);
  return;
}


// ===== FUN_2013341c @ 2013341c (36 bytes)

void FUN_2013341c(void)

{
  thunk_FUN_20132fe0();
  DAT_208085ac = DAT_208085ac + 1;
  FUN_2011f138(4);
  return;
}


// ===== FUN_20133440 @ 20133440 (68 bytes)

void FUN_20133440(void)

{
  int iVar1;
  
  iVar1 = itron_acre_isr(0,&DAT_203a7080);
  if (0 < iVar1) {
    gic_enable_irq(0x217);
    iVar1 = itron_acre_isr(0,&DAT_203a7094);
    if (0 < iVar1) {
      gic_enable_irq(0x1c1);
      return;
    }
  }
  return;
}


// ===== FUN_20133484 @ 20133484 (200 bytes)

void FUN_20133484(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_20132f74();
  FUN_20137278(&DAT_e800d804,uVar1,0x6a4);
  FUN_2015525c(&DAT_60502000,0x1450,0xf0);
  FUN_2015525c(&DAT_208f4de0,0x11f80,0xf0);
  FUN_201374ac(&DAT_e800e804,&DAT_60502000,0x11f8);
  FUN_20137080(&DAT_208f4de0,&DAT_e800e804,0x11f8);
  FUN_2015525c(&DAT_20906d60,0x11f8,0xf0);
  DAT_20906d60 = 0;
  DAT_20906d61 = 0;
  FUN_20137dac(FUN_201330d4);
  FUN_20137de0(FUN_201331dc);
  FUN_2011f0cc(2);
  FUN_2011f7b4(2);
  FUN_20137d84();
  FUN_2011f138(2);
  FUN_2011f0cc(4);
  FUN_2011f7b4(4);
  FUN_20137db8();
  FUN_2011f138(4);
  return;
}


// ===== FUN_201335d8 @ 201335d8 (32 bytes)

void FUN_201335d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_2015b9cc(&DAT_20907f78,param_1,param_2,param_3,param_4);
  return;
}


// ===== FUN_201335f8 @ 201335f8 (32 bytes)

void FUN_201335f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_2015bb7c(&DAT_20907f78,param_1,param_2,param_3,param_4);
  return;
}


// ===== FUN_20133618 @ 20133618 (8 bytes)

void FUN_20133618(void)

{
  FUN_2015b9a8(&DAT_20907f78);
  return;
}


// ===== FUN_20133620 @ 20133620 (340 bytes)

void FUN_20133620(void)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar2;
  undefined4 extraout_r3_01;
  undefined4 unaff_r4;
  int iVar3;
  
  DAT_208085b4 = FUN_20111174(0);
  iVar3 = 0;
  uVar2 = extraout_r3;
  do {
    iVar1 = FUN_20134368(iVar3,8,0,uVar2,unaff_r4);
    iVar1 = iVar3 * -4 - iVar1;
    (&DAT_20907f7c)[iVar3] = iVar1 + 0xde;
    if (0 < iVar3) {
      (&DAT_20907f7c)[iVar3] = iVar1 + 0xe1;
    }
    iVar3 = iVar3 + 1;
    uVar2 = extraout_r3_00;
  } while (iVar3 < 0x1e);
  iVar3 = 0;
  do {
    iVar1 = FUN_20134368(iVar3,8,1,uVar2,unaff_r4);
    iVar1 = iVar3 * -6 - iVar1;
    (&DAT_20907ff4)[iVar3] = iVar1 + 0x112;
    if (0 < iVar3) {
      (&DAT_20907ff4)[iVar3] = iVar1 + 0x117;
    }
    iVar3 = iVar3 + 1;
    uVar2 = extraout_r3_01;
  } while (iVar3 < 0x1e);
  iVar3 = 0;
  do {
    iVar1 = FUN_20134368(iVar3,9,0);
    iVar1 = iVar3 * -3 - iVar1;
    (&DAT_2090806c)[iVar3] = iVar1 + 0x68;
    if (0 < iVar3) {
      (&DAT_2090806c)[iVar3] = iVar1 + 0x6a;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xf);
  iVar3 = 0;
  do {
    iVar1 = FUN_20134368(iVar3,9,1);
    iVar1 = iVar3 * -6 - iVar1;
    (&DAT_209080a8)[iVar3] = iVar1 + 0x9c;
    if (0 < iVar3) {
      (&DAT_209080a8)[iVar3] = iVar1 + 0xa1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xf);
  FUN_2015b9a8(&DAT_20907f78);
  DAT_20907f78 = DAT_208085b4;
  return;
}


// ===== FUN_20133640 @ 20133640 (12 bytes)

undefined4 FUN_20133640(void)

{
  return DAT_208085b4;
}


// ===== FUN_20133658 @ 20133658 (240 bytes)

int FUN_20133658(int param_1,int param_2,undefined1 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_2011819c();
  if (iVar1 == 0) {
    puVar2 = &DAT_209080e4 + param_2 * 0x24 + param_1 * 0x144;
    *puVar2 = param_3;
    if (param_4 == (undefined4 *)0x0) {
      *(undefined4 *)(puVar2 + 4) = 0;
    }
    else {
      uVar4 = param_4[1];
      uVar5 = param_4[2];
      *(undefined4 *)(puVar2 + 8) = *param_4;
      *(undefined4 *)(puVar2 + 0xc) = uVar4;
      *(undefined4 *)(puVar2 + 0x10) = uVar5;
      *(undefined **)(puVar2 + 4) = puVar2 + 8;
      puVar3 = (undefined2 *)*param_4;
      if (puVar3 != (undefined2 *)0x0) {
        *(undefined2 *)(puVar2 + 0x14) = *puVar3;
        *(undefined2 *)(puVar2 + 0x16) = puVar3[1];
        *(undefined2 *)(puVar2 + 0x18) = puVar3[2];
        *(undefined2 *)(puVar2 + 0x1a) = puVar3[3];
        *(undefined **)(puVar2 + 8) = puVar2 + 0x14;
      }
      puVar3 = (undefined2 *)param_4[1];
      if (puVar3 != (undefined2 *)0x0) {
        *(undefined2 *)(puVar2 + 0x1c) = *puVar3;
        *(undefined2 *)(puVar2 + 0x1e) = puVar3[1];
        *(undefined2 *)(puVar2 + 0x20) = puVar3[2];
        *(undefined **)(puVar2 + 0xc) = puVar2 + 0x1c;
      }
      if ((undefined1 *)param_4[2] != (undefined1 *)0x0) {
        puVar2[0x22] = *(undefined1 *)param_4[2];
        *(undefined **)(puVar2 + 0x10) = puVar2 + 0x22;
      }
    }
  }
  return iVar1;
}


// ===== FUN_20133748 @ 20133748 (36 bytes)

void FUN_20133748(int param_1,int param_2)

{
  FUN_2011819c(param_1,param_2,(&DAT_209080e4)[param_2 * 0x24 + param_1 * 0x144],
               *(undefined4 *)(&DAT_209080e4 + param_2 * 0x24 + param_1 * 0x144 + 4));
  return;
}


// ===== FUN_2013376c @ 2013376c (140 bytes)

undefined4 FUN_2013376c(int param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  if (((((((&DAT_209080e4)[param_1 * 0x24] == '\x01') &&
         (puVar1 = *(undefined4 **)(&DAT_209080e8 + param_1 * 0x24), puVar1 != (undefined4 *)0x0))
        && (puVar1[1] != 0)) &&
       ((*(char *)(puVar1[1] + 3) != '\0' && (puVar2 = (ushort *)*puVar1, puVar2 != (ushort *)0x0)))
       ) && ((puVar2[2] <= param_2 &&
             ((param_2 < (uint)puVar2[2] + (uint)puVar2[3] && (*puVar2 <= param_3)))))) &&
     (param_3 < (uint)puVar2[1] + (uint)*puVar2)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== FUN_201337f8 @ 201337f8 (120 bytes)

void FUN_201337f8(undefined4 param_1)

{
  undefined2 *local_28;
  undefined2 *local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_c = 0;
  local_a = 800;
  local_10 = 0;
  local_1c = 0;
  local_e = 0x1e0;
  local_28 = &local_10;
  local_1a = 0;
  local_24 = &local_1c;
  local_19 = 0;
  local_18 = 0;
  local_20 = 0;
  FUN_20133658(0,param_1,0,&local_28);
  FUN_20133658(1,param_1,0,&local_28);
  return;
}


// ===== FUN_20133870 @ 20133870 (128 bytes)

void FUN_20133870(undefined4 param_1)

{
  undefined2 *local_28;
  undefined2 *local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_c = 0;
  local_a = 800;
  local_10 = 0;
  local_1c = 0;
  local_e = 0x1e0;
  local_28 = &local_10;
  local_1a = 0;
  local_19 = 0xff;
  local_24 = &local_1c;
  local_18 = 0;
  local_20 = 0;
  FUN_20133658(0,param_1,1,&local_28);
  FUN_20133658(1,param_1,1,&local_28);
  return;
}


// ===== FUN_201338f0 @ 201338f0 (124 bytes)

void FUN_201338f0(undefined4 param_1)

{
  undefined2 *local_28;
  undefined2 *local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_c = 0;
  local_a = 800;
  local_1c = 0;
  local_10 = 0;
  local_1a = 0;
  local_e = 0x1e0;
  local_28 = &local_10;
  local_24 = &local_1c;
  local_19 = 0;
  local_18 = 0;
  local_20 = 0;
  FUN_20133658(0,param_1,1,&local_28);
  FUN_20133658(1,param_1,1,&local_28);
  return;
}


// ===== FUN_2013396c @ 2013396c (160 bytes)

void FUN_2013396c(undefined4 param_1,int param_2)

{
  undefined2 local_28;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined2 *local_20;
  undefined1 *local_1c;
  undefined4 uStack_18;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_1c = (undefined1 *)&local_28;
  local_c = 0;
  local_10 = 0;
  local_a = 800;
  local_e = 0x1e0;
  local_20 = &local_10;
  if (param_2 == 0) {
    local_28 = 0xfffb;
    local_25 = 0xff;
  }
  else {
    local_28 = 5;
    local_25 = 0;
  }
  local_26 = 2;
  local_24 = 0;
  uStack_18 = 0;
  FUN_20133658(0,param_1,1,&local_20);
  FUN_20133658(1,param_1,1,&local_20);
  return;
}


// ===== FUN_20133a0c @ 20133a0c (44 bytes)

void FUN_20133a0c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_20117f00(0,param_1,param_3,param_4,param_4);
  FUN_20117f00(1,param_1);
  return;
}


// ===== FUN_20133a38 @ 20133a38 (84 bytes)

void FUN_20133a38(int param_1)

{
  undefined1 *local_18;
  undefined1 local_14 [4];
  undefined1 local_10;
  
  if (param_1 == 3) {
    local_14[0] = 2;
  }
  else {
    local_14[0] = 3;
  }
  local_18 = local_14;
  local_10 = FUN_20117ebc(0,param_1,&local_18);
  FUN_20117ebc(1,param_1,&local_18);
  return;
}


// ===== gui_update_layers @ 20133a8c (436 bytes)

void gui_update_layers(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_208f4d50 = fb_get_layer_addr(DAT_208085b8);
  FUN_20117e5c(0,4,&DAT_208f4d50);
  FUN_20117e5c(1,4,&DAT_208f4d50);
  DAT_208f4d60 = fb_get_layer_addr(DAT_208085bc);
  FUN_20117e5c(0,5,&DAT_208f4d60);
  FUN_20117e5c(1,5,&DAT_208f4d60);
  if ((((ushort)DAT_20808a84 ^ (ushort)DAT_208085c0) & 0x200) != 0) {
    FUN_20134854();
  }
  DAT_208085c0 = DAT_20808a84;
  if ((DAT_20808a84 & 0x20) != 0) {
    DAT_208085bc = 3;
    if (DAT_208085b8 != 1) {
      DAT_208085b8 = 1;
      uVar1 = fb_get_layer_addr();
      uVar2 = fb_get_layer_addr(DAT_208085b8);
      memcpy(uVar2,uVar1,0xbb800);
      return;
    }
    DAT_208085b8 = 2;
    uVar1 = fb_get_layer_addr(1);
    uVar2 = fb_get_layer_addr(DAT_208085b8);
    memcpy(uVar2,uVar1,0xbb800);
    return;
  }
  if (DAT_208085b8 == 1) {
    DAT_208085b8 = 2;
    uVar1 = fb_get_layer_addr(1);
    uVar2 = fb_get_layer_addr(DAT_208085b8);
    FUN_201378b0(uVar2,uVar1,0xbb800);
  }
  else {
    DAT_208085b8 = 1;
    uVar1 = fb_get_layer_addr(2);
    uVar2 = fb_get_layer_addr(DAT_208085b8);
    FUN_201378b0(uVar2,uVar1,0xbb800);
  }
  if (DAT_208085bc != 3) {
    DAT_208085bc = 3;
    uVar1 = fb_get_layer_addr(4);
    uVar2 = fb_get_layer_addr(DAT_208085bc);
    memcpy(uVar2,uVar1,0xbb800);
    return;
  }
  DAT_208085bc = 4;
  uVar1 = fb_get_layer_addr(3);
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  memcpy(uVar2,uVar1,0xbb800);
  return;
}


// ===== FUN_20133c40 @ 20133c40 (316 bytes)

void FUN_20133c40(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    DAT_208f4d50 = fb_get_layer_addr(DAT_208085b8);
    FUN_20117e5c(0,4,&DAT_208f4d50);
    FUN_20117e5c(1,4,&DAT_208f4d50);
    DAT_208f4d60 = fb_get_layer_addr(DAT_208085bc);
    FUN_20117e5c(0,5,&DAT_208f4d60);
    FUN_20117e5c(1,5,&DAT_208f4d60);
    if (DAT_208085b8 != 1) {
      DAT_208085b8 = 1;
      uVar1 = fb_get_layer_addr(2);
      uVar2 = fb_get_layer_addr(DAT_208085b8);
      FUN_201378b0(uVar2,uVar1,0xbb800);
      return;
    }
    DAT_208085b8 = 2;
    uVar1 = fb_get_layer_addr(1);
    uVar2 = fb_get_layer_addr(DAT_208085b8);
    FUN_201378b0(uVar2,uVar1,0xbb800);
    return;
  }
  if (DAT_208085bc != 3) {
    DAT_208085bc = 3;
    uVar1 = fb_get_layer_addr(4);
    uVar2 = fb_get_layer_addr(DAT_208085bc);
    memcpy(uVar2,uVar1,0xbb800);
    return;
  }
  DAT_208085bc = 4;
  uVar1 = fb_get_layer_addr(3);
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  memcpy(uVar2,uVar1,0xbb800);
  return;
}


// ===== FUN_20133d7c @ 20133d7c (44 bytes)

void FUN_20133d7c(undefined4 param_1)

{
  undefined4 uVar1;
  
  gui_update_layers();
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  memcpy(param_1,uVar1,0xbb800);
  return;
}


// ===== FUN_20133da8 @ 20133da8 (44 bytes)

void FUN_20133da8(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_20133870(5);
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  memcpy(uVar1,param_1,0xbb800);
  return;
}


// ===== FUN_20133dec @ 20133dec (36 bytes)

void FUN_20133dec(undefined4 param_1)

{
  FUN_20158848(&DAT_20470294,param_1);
  FUN_20158848(&DAT_20474c68,param_1);
  return;
}


// ===== FUN_20133e18 @ 20133e18 (60 bytes)

void FUN_20133e18(int param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar2 = iVar3 * 2;
      pbVar1 = (byte *)(param_2 + iVar3);
      iVar3 = iVar3 + 1;
      iVar2 = (int)*(short *)(param_3 + iVar2);
      if (*(byte *)(param_1 + iVar2) < *pbVar1) {
        *(byte *)(param_1 + iVar2) = *pbVar1;
      }
    } while (iVar3 < param_4);
    return;
  }
  return;
}


// ===== FUN_20133e54 @ 20133e54 (108 bytes)

void FUN_20133e54(int param_1,short *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar4 = *param_2 + -1;
  if (0 < param_3) {
    do {
      iVar5 = (int)param_2[iVar3];
      bVar1 = *(byte *)(param_4 + param_5);
      if (iVar5 == iVar4) {
        bVar2 = *(byte *)(param_4 + param_5 + -1);
        if (bVar1 < bVar2) {
          *(byte *)(param_1 + iVar5) = bVar2;
        }
        else if (bVar1 != 0) {
          *(byte *)(param_1 + iVar5) = bVar1;
        }
      }
      else {
        *(byte *)(param_1 + iVar5) = bVar1;
      }
      iVar3 = iVar3 + 1;
      param_5 = param_5 + 1;
      iVar4 = iVar5;
    } while (iVar3 < param_3);
  }
  return;
}


// ===== FUN_20133ec0 @ 20133ec0 (20 bytes)

void FUN_20133ec0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  FUN_20133e18(param_2 + 399,param_3 + 4,DAT_209083a8 + param_1 * 0x62e,0x317);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  return;
}


// ===== FUN_20133ed4 @ 20133ed4 (20 bytes)

void FUN_20133ed4(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  FUN_20133e18(param_2 + 399,param_3 + 4,DAT_209083e8 + param_1 * 0x62e,0x317);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  return;
}


// ===== FUN_20133ee8 @ 20133ee8 (20 bytes)

void FUN_20133ee8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  FUN_20133e54(param_2 + 399,DAT_209083a8 + param_1 * 0x62e,0x317,param_3 + 399,0xfffffe75);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  return;
}


// ===== FUN_20133efc @ 20133efc (20 bytes)

void FUN_20133efc(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  FUN_20133e54(param_2 + 399,DAT_209083e8 + param_1 * 0x62e,0x317,param_3 + 399,0xfffffe75);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  return;
}


// ===== FUN_20133f10 @ 20133f10 (88 bytes)

void FUN_20133f10(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  FUN_20133e18(param_2 + 399,param_3 + 4,DAT_209083a8 + param_1 * 0x62e,0x317);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
  return;
}


// ===== FUN_20133f24 @ 20133f24 (116 bytes)

void FUN_20133f24(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 < 0xf) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
    } while (iVar1 < 800);
    FUN_20133e54(param_2 + 399,DAT_209083a8 + param_1 * 0x62e,0x317,param_3 + 399,0xfffffe75);
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
    } while (iVar1 < 800);
    return;
  }
  return;
}


// ===== FUN_20133f44 @ 20133f44 (20 bytes)

void FUN_20133f44(int param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  
  uVar1 = *param_2;
  if (uVar1 < 4) {
    *param_3 = 0;
    param_3[1] = 0;
    return;
  }
  if (param_2[1] == 0) {
    *param_3 = uVar1;
    uVar1 = param_2[1];
  }
  else {
    uVar1 = *(short *)(DAT_209083a8 + param_1 * 0x62e + (uint)uVar1 * 2 + -8) + 399;
    *param_3 = uVar1;
    uVar1 = (*(short *)(DAT_209083a8 + param_1 * 0x62e +
                       ((uint)param_2[1] + (uint)*param_2) * 2 + -10) - uVar1) + 400;
  }
  param_3[1] = uVar1;
  return;
}


// ===== FUN_20133f58 @ 20133f58 (176 bytes)

void FUN_20133f58(int param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  
  uVar1 = *param_2;
  if (uVar1 < 4) {
    *param_3 = 0;
    param_3[1] = 0;
    return;
  }
  if (param_2[1] == 0) {
    *param_3 = uVar1;
    uVar1 = param_2[1];
  }
  else {
    uVar1 = *(short *)(DAT_209083e8 + param_1 * 0x62e + (uint)uVar1 * 2 + -8) + 399;
    *param_3 = uVar1;
    uVar1 = (*(short *)(DAT_209083e8 + param_1 * 0x62e +
                       ((uint)param_2[1] + (uint)*param_2) * 2 + -10) - uVar1) + 400;
  }
  param_3[1] = uVar1;
  return;
}


// ===== FUN_20133f6c @ 20133f6c (100 bytes)

void FUN_20133f6c(int param_1,byte *param_2,short *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = *param_2;
  iVar4 = 0;
  iVar3 = *param_3 + -1;
  if (0 < param_4) {
    do {
      iVar2 = (int)param_3[iVar4];
      if (iVar3 + 1 < iVar2) {
        *(char *)(iVar3 + param_1 + 1) = (char)((uint)bVar1 + (uint)param_2[iVar4] >> 1);
      }
      bVar1 = param_2[iVar4];
      iVar4 = iVar4 + 1;
      *(byte *)(param_1 + iVar2) = bVar1;
      iVar3 = iVar2;
    } while (iVar4 < param_4);
  }
  return;
}


// ===== FUN_20133fd0 @ 20133fd0 (164 bytes)

void FUN_20133fd0(int param_1,ushort *param_2,short *param_3,int param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  uVar2 = *param_2;
  iVar7 = 0;
  iVar4 = *param_3 + -1;
  if (0 < param_4) {
    do {
      iVar3 = (int)param_3[iVar7];
      if (iVar4 + 1 < iVar3) {
        iVar4 = param_1 + iVar4 * 2;
        *(char *)(iVar4 + 2) = (char)((uVar2 & 0xff) + (uint)(byte)param_2[iVar7] >> 1);
        *(char *)(iVar4 + 3) =
             (char)((uint)(uVar2 >> 8) + (uint)*(byte *)((int)param_2 + iVar7 * 2 + 1) >> 1);
      }
      puVar5 = param_2 + iVar7;
      puVar6 = (undefined1 *)(param_1 + iVar3 * 2);
      iVar7 = iVar7 + 1;
      uVar1 = *(undefined1 *)((int)puVar5 + 1);
      uVar2 = *puVar5;
      *puVar6 = (char)*puVar5;
      puVar6[1] = uVar1;
      iVar4 = iVar3;
    } while (iVar7 < param_4);
  }
  return;
}


// ===== FUN_20134074 @ 20134074 (104 bytes)

void FUN_20134074(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  FUN_20133f6c(param_1,param_2,&DAT_2090857c,200);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x187);
  return;
}


// ===== FUN_20134084 @ 20134084 (112 bytes)

void FUN_20134084(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0xffffffff;
  iVar1 = 0;
  iVar4 = *DAT_2090870c + -1;
  do {
    iVar5 = (int)DAT_2090870c[iVar1];
    if (iVar5 == iVar4) {
      uVar3 = (uint)*(byte *)(param_2 + iVar1);
      if ((int)uVar2 < (int)uVar3) goto LAB_20164178;
    }
    else {
      uVar3 = (uint)*(byte *)(param_2 + iVar1);
LAB_20164178:
      *(char *)(param_1 + iVar5) = (char)uVar3;
      uVar2 = uVar3;
    }
    iVar1 = iVar1 + 1;
    iVar4 = iVar5;
    if (199 < iVar1) {
      return;
    }
  } while( true );
}


// ===== FUN_20134094 @ 20134094 (104 bytes)

void FUN_20134094(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  FUN_20133fd0(param_1,param_2,&DAT_209083ec,200);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x187);
  return;
}


// ===== FUN_201340a4 @ 201340a4 (136 bytes)

void FUN_201340a4(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  
  FUN_20164334(&DAT_2090836c,&DAT_203a70ae);
  FUN_20164334(&DAT_209083ac,&DAT_203a70ae);
  iVar4 = 0;
  do {
    puVar2 = &DAT_203b2a12 + iVar4;
    puVar3 = &DAT_209083ec + iVar4;
    iVar4 = iVar4 + 1;
    *puVar3 = *puVar2;
  } while (iVar4 < 200);
  iVar4 = 0;
  do {
    iVar1 = iVar4 + 1;
    (&DAT_2090857c)[iVar4] = (&DAT_203b2ba2)[iVar4];
    iVar4 = iVar1;
  } while (iVar1 < 200);
  DAT_2090870c = &DAT_203b2d32;
  return;
}


// ===== FUN_201340ec @ 201340ec (56 bytes)

uint FUN_201340ec(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = __aeabi_uidivmod(param_1 * 10000);
  return (iVar1 * param_3 + 0x26ac) / 10000 & 0xffff;
}


// ===== FUN_20134124 @ 20134124 (168 bytes)

void FUN_20134124(int param_1,int param_2,ushort *param_3,int param_4,ushort *param_5)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (0 < param_1) {
    do {
      uVar4 = 0;
      uVar5 = (uint)param_5[iVar3];
      if (uVar5 != 0) {
        do {
          uVar1 = *param_5;
          iVar2 = FUN_201340ec(param_3[iVar3],uVar5,uVar4);
          *(undefined2 *)(*(int *)(param_4 + 4) + (((uVar1 - uVar4) + -1) * param_1 + iVar3) * 2) =
               *(undefined2 *)
                (*(int *)(param_2 + 4) + ((((uint)*param_3 - iVar2) + -1) * param_1 + iVar3) * 2);
          uVar4 = uVar4 + 1 & 0xffff;
        } while (uVar4 < uVar5);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1);
  }
  return;
}


// ===== FUN_201341cc @ 201341cc (28 bytes)

uint FUN_201341cc(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 + param_2;
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  else if ((int)uVar1 < 0x100) {
    uVar1 = uVar1 & 0xff;
  }
  else {
    uVar1 = 0xff;
  }
  return uVar1;
}


// ===== FUN_201341e8 @ 201341e8 (28 bytes)

void FUN_201341e8(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  undefined2 local_8;
  undefined2 local_6;
  
  _local_8 = CONCAT22(param_3,param_2);
  FUN_20133f44(param_1,&local_8,param_4);
  return;
}


// ===== FUN_20134204 @ 20134204 (44 bytes)

void FUN_20134204(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_10;
  
  iVar1 = 1;
  uStack_10 = param_4;
  do {
    FUN_20133f44(iVar1,param_1,&uStack_10);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1e);
  return;
}


// ===== FUN_20134230 @ 20134230 (132 bytes)

void FUN_20134230(void)

{
  uint uVar1;
  undefined1 auStack_18 [4];
  uint local_14 [2];
  
  FUN_201341e8(1,4,2,auStack_18);
  FUN_201341e8(2,4,2,auStack_18);
  FUN_201341e8(1,0x310,2,auStack_18);
  FUN_201341e8(2,0x310,2,auStack_18);
  uVar1 = 0;
  do {
    local_14[0] = uVar1 & 0xffff;
    FUN_20134204(local_14);
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 800);
  return;
}


// ===== FUN_201342b4 @ 201342b4 (448 bytes)

void FUN_201342b4(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_r4;
  
  memclr(&DAT_2047963c,0x82fb8);
  DAT_204832b8 = 0;
  DAT_204832b9 = 0;
  DAT_204832ba = 0;
  FUN_2015525c(&DAT_204832bb,0x352,0xff);
  FUN_2015525c(&DAT_2048360d,0x352,0xff);
  FUN_20164054(&DAT_2047c848,0,0x1e,&DAT_203d9a18,&DAT_203d99dc,unaff_r4);
  FUN_20163f80(&DAT_2047f400,0,0xf,&DAT_203d9a9e);
  FUN_20164018(&DAT_2047c848,&DAT_203b6704);
  FUN_20163f44(&DAT_2047f400,&DAT_203daf14);
  FUN_201587fc(&DAT_20470294);
  uVar1 = FUN_20164680(&DAT_2047f400);
  uVar2 = FUN_2016469c(&DAT_2047c848);
  FUN_20158838(&DAT_20470294,&DAT_203e58ac,uVar2,uVar1);
  FUN_201640a4(&DAT_2047fd80,&DAT_2047c848);
  FUN_20163fd0(&DAT_20482938,&DAT_2047f400);
  FUN_201587fc(&DAT_20474c68);
  uVar1 = FUN_20164680(&DAT_20482938);
  uVar2 = FUN_2016469c(&DAT_2047fd80);
  FUN_20158838(&DAT_20474c68,&DAT_203e58ac,uVar2,uVar1);
  thunk_FUN_20162d48(&DAT_2047963c,100);
  FUN_201584f8(&DAT_2047963c,0);
  FUN_20158544(&DAT_2047963c,0);
  FUN_20162c28(&DAT_2047c442,DAT_2047032c);
  FUN_20162c28(&DAT_2047c644,DAT_20474d00);
  FUN_201576f4(&DAT_2047963c,2);
  FUN_20157778(&DAT_2047963c);
  return;
}


// ===== FUN_201342d0 @ 201342d0 (12 bytes)

void FUN_201342d0(undefined4 param_1)

{
  FUN_201576f4(&DAT_2047963c,param_1);
  return;
}


// ===== FUN_201342dc @ 201342dc (256 bytes)

void FUN_201342dc(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_20164018(&DAT_2047c848,(&PTR_DAT_203d9a54)[param_1]);
  FUN_20163f44(&DAT_2047f400,(&PTR_DAT_203d9abc)[param_1]);
  uVar1 = FUN_20164680(&DAT_2047f400);
  uVar2 = FUN_2016469c(&DAT_2047c848);
  FUN_20158838(&DAT_20470294,(&PTR_DAT_203d9ae8)[param_1],uVar2,uVar1);
  FUN_20164018(&DAT_2047fd80,(&PTR_DAT_203d9a54)[param_2]);
  FUN_20163f44(&DAT_20482938,(&PTR_DAT_203d9abc)[param_2]);
  uVar1 = FUN_20164680(&DAT_20482938);
  uVar2 = FUN_2016469c(&DAT_2047fd80);
  FUN_20158838(&DAT_20474c68,(&PTR_DAT_203d9ae8)[param_2],uVar2,uVar1);
  FUN_20162c28(&DAT_2047c442,DAT_2047032c);
  FUN_20162c28(&DAT_2047c644,DAT_20474d00);
  return;
}

