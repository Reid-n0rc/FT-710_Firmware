// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2012cf30 @ 2012cf30 (900 bytes)

void FUN_2012cf30(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int local_40;
  byte local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if ((((param_3 == 0) && (*(char *)(param_1 + 1) == *(char *)(param_2 + 1))) &&
      (*(char *)(param_1 + 2) == *(char *)(param_2 + 2))) &&
     ((((*(byte *)(param_1 + 3) & 7) == (*(byte *)(param_2 + 3) & 7) &&
       (*(char *)(param_1 + 0x11) == *(char *)(param_2 + 0x11))) &&
      (iVar6 = memcmp(param_1 + 0x75,param_2 + 0x75,0x10), iVar6 == 0)))) {
    return;
  }
  if (DAT_20800482 == '\0') {
    if (1 < DAT_208004d0) {
      return;
    }
    bVar7 = false;
  }
  else {
    if (DAT_20800482 != '\x01') {
      return;
    }
    if (1 < DAT_208004d0) {
      return;
    }
    bVar7 = true;
  }
  local_30 = fb_get_layer_addr(0);
  if (DAT_20800480 == '\0') {
    iVar6 = FUN_20133640();
  }
  else {
    iVar6 = 0;
  }
  cVar1 = DAT_208004d1;
  if (bVar7) {
    if (!bVar7) {
      return;
    }
    puVar9 = &DAT_20800754;
  }
  else {
    puVar9 = (ushort *)0x20800750;
  }
  uVar11 = *(byte *)(param_1 + 0x11) & 0x1f;
  uVar2 = (uint)puVar9[1];
  if (9 < uVar11) {
    uVar11 = 9;
  }
  local_34 = 800;
  local_40 = local_30;
  if (iVar6 != 0) {
    local_40 = iVar6 + uVar2 * -0x640;
  }
  fb_clear_rect(local_40,uVar2,0,800,9);
  gui_area_dirty_set(0);
  if (cVar1 == '\0') {
    local_3b = *(undefined1 *)(param_1 + 0x7e);
    local_3a = *(undefined1 *)(param_1 + 0x7f);
    local_3c = *(byte *)(param_1 + 0x7d) & 0xf;
    local_39 = *(undefined1 *)(param_1 + 0x80);
    uVar3 = be32_load(&local_3c);
    FUN_2012cb60(local_40,puVar9[1],*puVar9 + DAT_20800758,uVar3);
    iVar8 = 0;
    local_2c = uVar11 * 0x10 + 0x20802dd0;
    iVar4 = uVar11 * 0x18 + 0x20802e70;
    do {
      uVar3 = 0;
      uVar11 = (uint)*(ushort *)(local_2c + iVar8 * 4) + (uint)*puVar9;
      local_38 = (uint)puVar9[1];
      iVar12 = iVar4 + iVar8 * 6;
      iVar10 = strlen(iVar12);
      if (iVar10 != 0) {
        do {
          gui_draw_runs(local_40,local_38,uVar11 & 0xffff,
                        *(void **)(&DAT_2080086c + (uint)*(byte *)(iVar12 + uVar3) * 4));
          uVar11 = (uVar11 & 0xffff) + 8;
          uVar3 = uVar3 + 1;
          uVar5 = strlen(iVar12);
        } while (uVar3 < uVar5);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
  }
  else {
    local_3b = *(undefined1 *)(param_1 + 0x82);
    local_3a = *(undefined1 *)(param_1 + 0x83);
    local_3c = *(byte *)(param_1 + 0x81) & 0xf;
    local_39 = *(undefined1 *)(param_1 + 0x84);
    uVar3 = be32_load(&local_3c);
    iVar4 = __aeabi_uidivmod((*(int *)(&UNK_2016d6e8 + uVar11 * 4) + uVar3) - uVar3,5);
    iVar8 = 0;
    do {
      FUN_2012cb60(local_40,puVar9[1],*puVar9 + (&DAT_20802db8)[iVar8 * 2],iVar4 * iVar8 + uVar3);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 6);
  }
  if (iVar6 != 0) {
    iVar8 = 0;
    iVar10 = local_30 + uVar2 * 0x640;
    iVar4 = local_34 << 1;
    do {
      memcpy(iVar10,iVar6,iVar4);
      iVar8 = iVar8 + 1;
      iVar10 = iVar10 + 0x640;
      iVar6 = iVar6 + 0x640;
    } while (iVar8 < 9);
  }
  return;
}


// ===== FUN_2012d000 @ 2012d000 (412 bytes)

void FUN_2012d000(int param_1,short param_2,short param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  short *psVar3;
  ushort uVar4;
  
  uVar1 = fb_get_layer_addr(0);
  uVar2 = 0;
  gui_area_dirty_set(0);
  if (param_1 == 0) {
    if (((param_4 != 0) && (uVar2 = (uint)(param_4 == 1), param_4 != 1)) && (param_4 == 2)) {
      uVar2 = 2;
    }
  }
  else if (param_1 == 1) {
    uVar2 = 3;
  }
  else if (param_1 == 2) {
    uVar2 = 4;
  }
  else if (param_1 == 3) {
    uVar2 = 5;
  }
  uVar4 = 0;
  psVar3 = (short *)(&DAT_2016e420 + uVar2 * 0x14 + param_5 * 0x78);
  if (psVar3[3] != 0) {
    do {
      fb_fill_box_t(uVar1,(uint)(ushort)(psVar3[1] + param_2),
                    (uint)(ushort)(psVar3[4] * uVar4 + *psVar3 + param_3),(uint)(ushort)psVar3[2],1,
                    0x3186);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (ushort)psVar3[3]);
  }
  uVar4 = 0;
  if (psVar3[8] != 0) {
    do {
      fb_fill_box(uVar1,(uint)(ushort)(psVar3[9] * uVar4 + psVar3[6] + param_2),
                  (uint)(ushort)(psVar3[5] + param_3),(uint)(ushort)psVar3[7],1,0x632c);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (ushort)psVar3[8]);
  }
  if (param_1 == 3) {
    return;
  }
  fb_fill_box(uVar1,(uint)(ushort)(psVar3[9] * uVar4 + psVar3[6] + param_2),
              (uint)(ushort)(psVar3[5] + param_3),(uint)(ushort)psVar3[7],1,0xffff);
  gui_area_dirty_set(0);
  return;
}


// ===== scope_area_frame_draw @ 2012d19c (380 bytes)

/* scope frame sprites (layout words 0x208004F4/F6) */

void scope_area_frame_draw(uint param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  undefined1 *puVar9;
  uint uVar10;
  
  uVar2 = fb_get_layer_addr(0);
  gui_area_dirty_set(0);
  if (param_1 < 3) {
    fb_fill_box(uVar2,(uint)*(ushort *)(&DAT_2016e342 + param_1 * 4),
                (uint)*(ushort *)(&DAT_2016e340 + param_1 * 4),
                (uint)*(ushort *)(&DAT_2016d2a6 + param_1 * 2),1,0xffff);
    uVar8 = 0;
    if ((&DAT_2016d294)[param_1] != '\0') {
      do {
        fb_fill_box_t(uVar2,(uint)*(ushort *)(&DAT_2016e352 + param_1 * 4),
                      (uint)(ushort)(*(short *)(&DAT_2016d2ae + param_1 * 2) * uVar8 +
                                    *(short *)(&DAT_2016e350 + param_1 * 4)),2,1,0xffff);
        uVar8 = uVar8 + 1;
      } while (uVar8 < (byte)(&DAT_2016d294)[param_1]);
    }
    if (param_1 == 2) {
      uVar10 = 0;
      do {
        uVar7 = 0;
        uVar8 = (&DAT_2080084e)[uVar10 * 2];
        uVar5 = (uint)DAT_208004f4 + (uint)(ushort)(&DAT_2080084c)[uVar10 * 2];
        uVar6 = (uint)DAT_208004f6;
        puVar9 = &DAT_20800860 + uVar10 * 6;
        iVar3 = strlen(puVar9);
        if (iVar3 != 0) {
          do {
            gui_draw_runs(uVar2,uVar8 + uVar6 & 0xffff,uVar5 & 0xffff,
                          *(void **)(&DAT_2080086c + (uint)(byte)puVar9[uVar7] * 4));
            pbVar1 = puVar9 + uVar7;
            uVar7 = uVar7 + 1;
            uVar5 = (uint)**(ushort **)(&DAT_2080086c + (uint)*pbVar1 * 4) + (uVar5 & 0xffff) + 1;
            uVar4 = strlen(puVar9);
          } while (uVar7 < uVar4);
        }
        uVar10 = uVar10 + 1 & 0xffff;
      } while (uVar10 < 5);
    }
  }
  return;
}


// ===== FUN_2012d318 @ 2012d318 (132 bytes)

undefined4 FUN_2012d318(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 100;
  if (DAT_208004d0 == '\x01') {
    if (DAT_20800482 == '\0') {
      if (DAT_208004d2 == '\0') {
        if (param_1 != 0) {
          return 0xd2;
        }
      }
      else {
        if (DAT_208004d2 != '\x01') {
          if (DAT_208004d2 == '\x02') {
            uVar1 = 0x3c;
          }
          return uVar1;
        }
        if (param_1 == 0) {
          return 100;
        }
      }
      return 0x8c;
    }
    if (DAT_20800482 == '\x01') {
      if (param_1 == 0) {
        uVar1 = 0x28;
      }
      else {
        uVar1 = 0x50;
      }
    }
  }
  return uVar1;
}


// ===== scope_mode_split @ 2012d3b8 (40 bytes)

/* byte 2 -> 0/1/2 spectrum/waterfall split (inference) */

byte scope_mode_split(uint param_1)

{
  switch(param_1) {
  case 3:
  case 6:
  case 9:
    return 0;
  default:
    return 1;
  case 5:
  case 8:
  case 0xb:
    return 2;
  }
}


// ===== scope_mode_sub @ 2012d404 (36 bytes)

/* byte 2 -> 0/1/2 sub-setting */

byte scope_mode_sub(uint param_1)

{
  switch(param_1) {
  default:
    return 0;
  case 1:
  case 6:
  case 7:
  case 8:
    return 1;
  case 2:
  case 9:
  case 10:
  case 0xb:
    return 2;
  }
}


// ===== scope_mode_is_2d @ 2012d458 (28 bytes)

/* byte 2: 0-2 -> 0 (3DSS), 3-11 -> 1 */

byte scope_mode_is_2d(uint param_1)

{
  switch(param_1) {
  default:
    return 0;
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    return 1;
  }
}


// ===== scope_mode_decode @ 2012d4a4 (164 bytes)

/* packet 0x20 bytes 1-3 -> 0x20800482, 0x208004D0..D2 */

void scope_mode_decode(int param_1)

{
  if ((*(char *)(param_1 + 1) == '\0') || (*(char *)(param_1 + 1) != '\x01')) {
    DAT_20800482 = 0;
    DAT_208004d0 = scope_mode_is_2d((uint)*(byte *)(param_1 + 2));
    DAT_208004d1 = scope_mode_sub((uint)*(byte *)(param_1 + 2));
    DAT_208004d2 = scope_mode_split((uint)*(byte *)(param_1 + 2));
  }
  else {
    DAT_20800482 = 1;
    DAT_208004d0 = scope_mode_is_2d((uint)*(byte *)(param_1 + 2));
    DAT_208004d1 = scope_mode_sub((uint)*(byte *)(param_1 + 2));
    DAT_208004d2 = 1;
  }
  if ((*(byte *)(param_1 + 3) & 4) != 0) {
    DAT_208004d0 = 3;
  }
  return;
}


// ===== scope_area_setup @ 2012d52c (864 bytes)

/* packet 0x20 scope bytes changed: clear area, decode mode, reset history */

void scope_area_setup(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined *local_2c;
  
  iVar2 = fb_get_layer_addr(0);
  iVar3 = fb_get_layer_addr(DAT_208085b8);
  uVar4 = *(byte *)(param_1 + 6) & 0x80;
  iVar8 = -((int)((uint)*(byte *)(param_1 + 5) << 0x1a) >> 0x1f);
  bVar1 = DAT_208f463a | DAT_208f463d;
  if ((((param_3 == 0) && (*(char *)(param_1 + 1) == *(char *)(param_2 + 1))) &&
      (*(char *)(param_1 + 2) == *(char *)(param_2 + 2))) &&
     ((*(byte *)(param_1 + 3) & 7) == (*(byte *)(param_2 + 3) & 7))) {
    return;
  }
  scope_mode_decode(param_1);
  if (iVar8 == 0) {
    local_2c = &DAT_2016d2d0;
    if (DAT_208004d0 == 0) {
      iVar10 = 0xb4;
      iVar9 = 0xf0;
    }
    else {
      iVar10 = 0xc9;
      iVar9 = 0xdb;
    }
  }
  else {
    iVar10 = 0x80;
    iVar9 = 0x124;
    local_2c = &DAT_2016d2f0;
  }
  fb_clear_rect(iVar2,iVar10,0,800,iVar9);
  gui_area_dirty_set(0);
  if (DAT_20800483 == '\0') {
    if ((iVar8 == 0) && (DAT_208004d0 == 0)) {
      fb_clear_rect(iVar3,199,0,800,0xdd);
    }
    else {
      fb_clear_rect(iVar3,iVar10 - 2U & 0xffff,0,800,iVar9 + 2);
    }
  }
  DAT_20800489 = 3;
  FUN_20134304(1);
  if ((*(byte *)(param_1 + 7) & 0x80) != 0) {
    FUN_201342d0(0);
  }
  FUN_20120d58();
  if (DAT_20800480 == '\0') {
    FUN_20133618();
  }
  DAT_208007c8 = 0;
  if (DAT_20800482 == '\0') {
    if (DAT_208004d0 == 0) {
      scope_area_frame_draw(0);
      gui_draw_runs32(iVar2,iVar10,4,local_2c);
      return;
    }
    if (DAT_208004d0 != 1) {
      if (DAT_208004d0 != 3) {
        DAT_208007c8 = 0;
        return;
      }
      FUN_20131f74(0,0xb8,1,iVar8,bVar1,param_2);
      return;
    }
    uVar5 = FUN_2012d318(iVar8);
    FUN_20134444(uVar5,uVar4);
    scope_area_frame_draw(0);
    uVar6 = 1;
    uVar5 = 0;
    uVar7 = DAT_208004d2;
  }
  else {
    if (DAT_20800482 != '\x01') {
      DAT_208007c8 = 0;
      return;
    }
    if (DAT_208004d0 == 0) {
      scope_area_frame_draw(1);
      gui_draw_runs32(iVar2,iVar10,4,local_2c + 0x10);
    }
    else if (DAT_208004d0 == 1) {
      uVar5 = FUN_2012d318(iVar8);
      FUN_20134444(uVar5,uVar4);
      scope_area_frame_draw(1);
      FUN_2012d000(1,iVar10,1,1,iVar8);
    }
    else {
      if (DAT_208004d0 != 3) {
        DAT_208007c8 = 0;
        return;
      }
      FUN_20131f74(0,0xb8,1,iVar8,bVar1,param_2);
    }
    if (1 < DAT_208004d0) {
      return;
    }
    gui_draw_runs(iVar2,0x12e,1,&DAT_2016d320);
    scope_area_frame_draw(3);
    FUN_2012d000(3,0x12e,1,1,iVar8);
    gui_draw_runs(iVar2,0x12e,0x192,&DAT_2016d320);
    scope_area_frame_draw(2);
    uVar6 = 0x192;
    iVar10 = 0x12e;
    uVar5 = 2;
    uVar7 = 1;
  }
  FUN_2012d000(uVar5,iVar10,uVar6,uVar7,iVar8);
  return;
}


// ===== FUN_2012d8bc @ 2012d8bc (828 bytes)

void FUN_2012d8bc(char *param_1,char *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  byte local_38 [8];
  uint local_30;
  undefined2 *local_2c;
  
  local_30 = fb_get_layer_addr(0);
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  if (*param_1 != '7') {
    if (*param_2 == '7') {
      param_3 = 1;
    }
    if (-1 < (int)((uint)(byte)param_1[5] << 0x1a)) {
      bVar7 = (param_2[5] & 0x20U) != 0;
      if (bVar7) {
        param_3 = 1;
      }
      if (bVar7 || param_3 != 0) {
        uVar3 = 3;
        do {
          uVar3 = uVar3 + 1;
          fb_blit_raw(local_30,0x6d,(uint)uVar3,0x2016e090,1,0x45);
        } while (uVar3 < 0x1b5);
        gui_draw_runs(local_30,0x6d,1,&DAT_2016e080);
        uVar4 = 1;
        do {
          fb_fill_box_t(local_30,(uint)DAT_208004c0,(uint)(ushort)(&DAT_2016e15c)[uVar4 * 5],
                        (uint)DAT_208006ba,(uint)DAT_208006b8,0);
          uVar4 = uVar4 + 1 & 0xff;
        } while (uVar4 < 4);
        gui_area_dirty_set(0);
      }
      uVar4 = (uint)(byte)param_1[0xc];
      uVar5 = 0;
      local_38[0] = (byte)(uVar4 & 3);
      if (3 < (uVar4 & 3)) {
        local_38[0] = 3;
      }
      uVar2 = (uint)(byte)param_2[0xc];
      local_38[4] = (byte)(uVar2 & 3);
      if (3 < (uVar2 & 3)) {
        local_38[4] = 3;
      }
      uVar1 = (uVar4 & 0xf) >> 2;
      local_38[1] = (byte)uVar1;
      if (2 < uVar1) {
        local_38[1] = 2;
      }
      uVar1 = (uVar2 & 0xf) >> 2;
      local_38[5] = (byte)uVar1;
      if (2 < uVar1) {
        local_38[5] = 2;
      }
      uVar4 = (uVar4 & 0x3f) >> 4;
      local_38[2] = (byte)uVar4;
      if (2 < uVar4) {
        local_38[2] = 2;
      }
      uVar4 = (uVar2 & 0x3f) >> 4;
      local_38[6] = (byte)uVar4;
      if (2 < uVar4) {
        local_38[6] = 2;
      }
      local_38[3] = param_1[0xd] & 7;
      if (4 < local_38[3]) {
        local_38[3] = 4;
      }
      local_38[7] = param_2[0xd] & 7;
      if (4 < local_38[7]) {
        local_38[7] = 4;
      }
      local_2c = &DAT_2016e170;
      do {
        if ((param_3 != 0) || (local_38[uVar5] != local_38[uVar5 + 4])) {
          uVar3 = 0;
          iVar6 = (&DAT_20802698)[uVar5];
          if (**(short **)(iVar6 + (uint)local_38[uVar5] * 4) != 0) {
            do {
              fb_blit_raw(local_30,(uint)(ushort)(&DAT_2016e15e)[uVar5 * 5],
                          (uint)(ushort)(DAT_208006b4 + (&DAT_2016e15c)[uVar5 * 5] + uVar3),
                          0x2016e090,1,0x45);
              uVar3 = uVar3 + 1;
            } while (uVar3 < **(ushort **)(iVar6 + (uint)local_38[uVar5] * 4));
          }
          if ((uVar5 == 2) && (local_38[2] == '\x02')) {
            gui_draw_runs(local_30,(uint)DAT_208006b2 + (uint)(ushort)local_2c[1] & 0xffff,
                          DAT_208006b0 + 0xdd & 0xffff,&DAT_2016e14c);
          }
          else {
            gui_draw_runs(local_30,(uint)DAT_208006b2 + (uint)(ushort)(&DAT_2016e15e)[uVar5 * 5] &
                                   0xffff,
                          (uint)(ushort)(&DAT_2016e15c)[uVar5 * 5] + (uint)DAT_208006b0 & 0xffff,
                          (void *)(&DAT_20802688)[uVar5]);
            gui_draw_runs(local_30,(uint)DAT_208006b6 + (uint)(ushort)(&DAT_2016e15e)[uVar5 * 5] &
                                   0xffff,
                          (uint)(ushort)(&DAT_2016e15c)[uVar5 * 5] + (uint)DAT_208006b4 & 0xffff,
                          *(void **)(iVar6 + (uint)local_38[uVar5] * 4));
          }
          gui_area_dirty_set(0);
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 4);
    }
  }
  return;
}


// ===== FUN_2012dbf8 @ 2012dbf8 (460 bytes)

void FUN_2012dbf8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  undefined *puVar6;
  
  uVar1 = fb_get_layer_addr(0);
  if (param_3 != 0) {
    uVar5 = 3;
    do {
      fb_blit_raw(uVar1,0x1a4,uVar5,0x2016e28c,1,0x3c);
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x31d);
    gui_draw_runs(uVar1,0x1a4,0,&DAT_2016e27c);
    uVar5 = 1;
    do {
      fb_fill_box_t(uVar1,(uint)DAT_20800706,(uint)(ushort)(&DAT_2016e304)[uVar5 * 5],
                    (uint)DAT_2080070a,(uint)DAT_20800708,0);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 6);
    gui_area_dirty_set(0);
  }
  uVar5 = 0;
  do {
    uVar3 = (uint)*(byte *)(param_1 + uVar5 + 0x25);
    uVar2 = uVar3 & 0x7f;
    if ((param_3 != 0) || (uVar3 != *(byte *)(param_2 + uVar5 + 0x25))) {
      puVar6 = (undefined *)0x0;
      if ((uVar2 != 0x7f) && (uVar2 < 0xd)) {
        puVar6 = (&PTR_DAT_20802d38)[uVar2];
      }
      uVar4 = 0;
      if (*(short *)PTR_DAT_20802d38 != 0) {
        do {
          fb_blit_raw(uVar1,(uint)(ushort)(&DAT_2016e306)[uVar5 * 5],
                      (uint)(ushort)(DAT_2080070c + (&DAT_2016e304)[uVar5 * 5] + uVar4),0x2016e28c,1
                      ,0x3c);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(ushort *)PTR_DAT_20802d38);
      }
      if (puVar6 != (undefined *)0x0) {
        gui_draw_runs(uVar1,(uint)(ushort)(&DAT_2016e306)[uVar5 * 5] + (uint)DAT_2080070e & 0xffff,
                      (uint)DAT_2080070c + (uint)(ushort)(&DAT_2016e304)[uVar5 * 5] & 0xffff,puVar6)
        ;
      }
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 6);
  return;
}


// ===== FUN_2012ddc4 @ 2012ddc4 (828 bytes)

void FUN_2012ddc4(int param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  ushort *unaff_r4;
  int iVar2;
  int iVar3;
  undefined *local_38 [3];
  int local_2c;
  
  local_2c = fb_get_layer_addr(DAT_208085b8);
  iVar3 = 0;
  switch(param_1) {
  case 1:
  case 3:
  case 4:
  case 8:
    unaff_r4 = &DAT_20800674;
    break;
  case 2:
    if (param_2 < 99) {
      unaff_r4 = &DAT_20800678;
    }
    else {
      unaff_r4 = (ushort *)0x2080067c;
    }
    break;
  case 5:
    unaff_r4 = &DAT_20800684;
    break;
  case 7:
    unaff_r4 = &DAT_20800680;
    break;
  case 9:
  case 10:
    unaff_r4 = &DAT_20800688;
  }
  if (*(void **)(&DAT_20802630 + param_1 * 4) != (void *)0x0) {
    gui_draw_runs(local_2c,unaff_r4[1] + 10 & 0xffff,*unaff_r4 + 0x11a & 0xffff,
                  *(void **)(&DAT_20802630 + param_1 * 4));
  }
  if (param_1 == 1) {
    puVar1 = &DAT_2016deec;
    if (param_3 != 0) {
      puVar1 = &DAT_2016df0c;
    }
    gui_draw_runs(local_2c,unaff_r4[1] + 10 & 0xffff,*unaff_r4 + 0x11a & 0xffff,puVar1);
  }
  else {
    if (param_1 == 2) {
      if (param_2 < 99) {
        iVar3 = 2;
        local_38[0] = *(undefined **)
                       (&DAT_20802310 + ((uint)((short)(param_2 + 1) * 0xcd) >> 0xb) * 4);
        local_38[1] = *(undefined **)(&DAT_20802310 + ((param_2 + 1) % 10) * 4);
      }
      else if (param_2 < 0x75) {
        iVar3 = 3;
        local_38[0] = &DAT_2016decc;
        local_38[1] = (&PTR_DAT_20802314)[(int)(param_2 - 99) / 2];
        local_38[2] = (undefined *)*(undefined4 *)(&DAT_208007f8 + (param_2 & 1) * 4);
      }
      iVar2 = 0;
      if (iVar3 == 0) {
        return;
      }
      do {
        gui_draw_runs(local_2c,unaff_r4[1] + 10 & 0xffff,
                      (uint)DAT_2080068c * iVar2 + 0x11a +
                      (uint)*(ushort *)PTR_DAT_20802638 + (uint)*unaff_r4 & 0xffff,local_38[iVar2]);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar3);
    }
    if (param_1 == 7) {
      iVar2 = 0;
      iVar3 = (short)((short)param_2 + -0x95) * 0xcd;
      local_38[0] = *(undefined **)(&DAT_20802310 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
      local_38[1] = (undefined *)*(undefined4 *)(&DAT_20802310 + ((int)(param_2 - 0x95) % 10) * 4);
      do {
        gui_draw_runs(local_2c,unaff_r4[1] + 10 & 0xffff,
                      (uint)DAT_2080068c * iVar2 + 0x11a +
                      (uint)*(ushort *)PTR_DAT_2080264c + (uint)*unaff_r4 & 0xffff,local_38[iVar2]);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 2);
    }
    if (param_1 == 5) {
      local_38[0] = (undefined *)0x0;
      if (9 < (int)(param_2 - 199)) {
        iVar3 = (short)(param_2 - 199) * 0xcd;
        local_38[0] = *(undefined **)(&DAT_20802338 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
      }
      iVar3 = 0;
      local_38[1] = (undefined *)*(undefined4 *)(&DAT_20802338 + ((int)(param_2 - 199) % 10) * 4);
      do {
        if (local_38[iVar3] != (undefined *)0x0) {
          gui_draw_runs(local_2c,unaff_r4[1] + 10 & 0xffff,
                        (uint)*unaff_r4 + (uint)*(ushort *)PTR_DAT_20802644 +
                        (uint)DAT_2080068c * iVar3 + 0x11a & 0xffff,local_38[iVar3]);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
      return;
    }
  }
  return;
}


// ===== FUN_2012e1a4 @ 2012e1a4 (216 bytes)

void FUN_2012e1a4(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  
  iVar1 = fb_get_layer_addr(DAT_208085b8);
  uVar3 = (uint)*(byte *)(param_1 + 0x2d);
  bVar5 = *(byte *)(param_1 + 0x2e);
  bVar4 = *(byte *)(param_1 + 0x2f);
  bVar2 = *(byte *)(param_1 + 3) & 0x80;
  if ((param_3 == 0 && uVar3 == *(byte *)(param_2 + 0x2d)) &&
     ((bVar5 == *(byte *)(param_2 + 0x2e) && bVar4 == *(byte *)(param_2 + 0x2f)) &&
      bVar2 == (*(byte *)(param_2 + 3) & 0x80))) {
    return;
  }
  if (0xf < uVar3) {
    uVar3 = 0xf;
  }
  if (10 < bVar5) {
    bVar5 = 10;
  }
  if (0xd1 < bVar4) {
    bVar4 = 0xd1;
  }
  gui_draw_runs(iVar1,10,0x11a,&DAT_2016e714);
  FUN_2012ddc4(bVar5,bVar4,bVar2);
  gui_draw_runs(iVar1,DAT_20800776 + 10 & 0xffff,DAT_20800774 + 0x11a & 0xffff,
                (&PTR_DAT_20802ff4)[uVar3]);
  return;
}


// ===== FUN_2012e27c @ 2012e27c (332 bytes)

void FUN_2012e27c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = fb_get_layer_addr(DAT_208085b8);
  if (((param_3 != 0) || ((*(byte *)(param_1 + 0xd) & 0x80) != (*(byte *)(param_2 + 0xd) & 0x80)))
     || (iVar2 = memcmp(param_1 + 0x15,param_2 + 0x15,4), iVar2 != 0)) {
    fb_clear_rect(iVar1,(uint)DAT_2080050a,(uint)DAT_20800508,0xa3,0xe);
    if ((*(byte *)(param_1 + 0xd) & 0x80) != 0) {
      gui_draw_runs(iVar1,(uint)DAT_2080050a,(uint)DAT_20800508,&DAT_2016d5dc);
      uVar3 = 0;
      do {
        if (((uint)*(byte *)(param_1 + (uVar3 >> 3) + 0x15) & 1 << (uVar3 & 7)) != 0) {
          fb_fill_rect(iVar1,0xffff,(uint)DAT_2080050a + (uint)DAT_20800512 & 0xffff,
                       DAT_20800514 * uVar3 + (uint)DAT_20800508 + (uint)DAT_20800510 & 0xffff,
                       (uint)DAT_20800518,(uint)DAT_2080051a);
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 0x19);
    }
    if (param_3 != 0) {
      fb_clear_rect(iVar1,(uint)DAT_2080050e,(uint)DAT_2080050c,0xa3,0xe);
    }
  }
  return;
}


// ===== FUN_2012e3c8 @ 2012e3c8 (24 bytes)

void FUN_2012e3c8(byte param_1,byte *param_2,byte *param_3)

{
  param_1 = param_1 & 0xf;
  if (10 < param_1) {
    param_1 = 10;
  }
  *param_2 = param_1;
  *param_3 = param_1;
  return;
}


// ===== scr_main_layout @ 2012e3e0 (964 bytes)

/* main screen static parts (scope frame, mode/filter labels) */

void scr_main_layout(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined1 local_3c [4];
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  local_28 = fb_get_layer_addr(0);
  local_2c = fb_get_layer_addr(DAT_208085b8);
  local_30 = fb_get_layer_addr(DAT_208085bc);
  bVar2 = false;
  bVar1 = false;
  bVar7 = DAT_208f4638 != '\0';
  local_38 = *(byte *)(param_1 + 0x12) & 0xf;
  local_34 = *(byte *)(param_2 + 0x12) & 0xf;
  bVar3 = *(byte *)(param_1 + 0x10) >> 4;
  FUN_2012616c(2);
  if (param_3 != 0 || bVar7) {
    FUN_20134480((*(byte *)(param_1 + 5) & 0x3f) >> 5);
  }
  uVar6 = *(byte *)(param_1 + 6) & 0x80;
  uVar5 = *(byte *)(param_1 + 6) & 0x40;
  if ((param_3 != 0 || bVar7) || ((*(byte *)(param_2 + 6) & 0x80) != uVar6)) {
    FUN_20134468(uVar6);
    bVar2 = true;
    if (param_3 == 0 && !bVar7) goto LAB_2012e4b4;
  }
  else {
LAB_2012e4b4:
    if ((*(byte *)(param_2 + 6) & 0x40) == uVar5) goto LAB_2012e4d4;
  }
  FUN_20134474(uVar5);
  bVar2 = true;
LAB_2012e4d4:
  if (bVar3 != 0) {
    DAT_208004a0 = bVar3 * '\x03';
  }
  if ((param_3 != 0 || bVar7) ||
     ((*(byte *)(param_1 + 0x10) & 7) != (*(byte *)(param_2 + 0x10) & 7))) {
    bVar3 = *(byte *)(param_1 + 0x10) & 7;
    if (4 < bVar3) {
      bVar3 = 4;
    }
    FUN_20133dec(bVar3);
    bVar1 = true;
  }
  if ((bVar7) || ((local_38 != local_34 || bVar1) || bVar2)) {
    FUN_2012e3c8(local_38,local_3c,&stack0xffffffc0);
    FUN_201342dc(local_3c[0],uVar5 & 0xff);
    scope2d_set_color(local_3c[0]);
  }
  meter_draw_scale(param_1,param_2,param_3);
  FUN_2012e27c(param_1,param_2,param_3);
  FUN_2012e1a4(param_1,param_2,param_3);
  scr_vfo((char *)param_1,(char *)param_2,param_3);
  FUN_2012dbf8(param_1,param_2,param_3);
  if (bVar7) {
    fb_clear_rect(local_28,0x6d,0,800,0x137);
    gui_area_dirty_set(0);
    fb_clear_rect(local_2c,0x6d,0,800,0x137);
    fb_clear_rect(local_30,0x6d,0,800,0x137);
    param_3 = 1;
  }
  FUN_2012d8bc(param_1,param_2,param_3);
  scope_area_setup(param_1,param_2,param_3);
  FUN_2012cf30(param_1,param_2,param_3);
  FUN_2012caac(param_1,param_2,param_3);
  FUN_2012c6c4(param_1,param_2,param_3);
  iVar4 = fb_get_layer_addr(DAT_208085b8);
  uVar5 = (uint)*(byte *)(param_1 + 0x2c);
  bVar3 = *(byte *)(param_2 + 0x2c);
  if (param_3 != 0) {
    fb_fill_rect(iVar4,0x821,(uint)DAT_208007be,(uint)DAT_208007bc,(uint)DAT_208007c0,
                 (uint)DAT_208007c2);
    gui_draw_runs(iVar4,(uint)DAT_208007be,(uint)DAT_208007bc,&DAT_2016ed18);
  }
  if (uVar5 != 0xe) {
    if (uVar5 < 0xf) {
      if (0xd < uVar5) {
        return;
      }
    }
    else if (uVar5 != 0x15) {
      if (uVar5 < 0x16) {
        if (5 < uVar5 - 0xf) {
          return;
        }
      }
      else if (uVar5 != 0x2d) {
        if (uVar5 < 0x2e) {
          if ((uVar5 != 0x1a && uVar5 != 0x1b) && uVar5 != 0x1c) {
            return;
          }
        }
        else if (uVar5 != 0x36 && uVar5 != 0x3a) {
          return;
        }
      }
    }
  }
  if (param_3 == 0 && uVar5 == bVar3) {
    return;
  }
  fb_fill_rect(iVar4,0x821,(uint)DAT_208007c6,(uint)DAT_208007c4,
               (uint)**(ushort **)(&DAT_20803644 + uVar5 * 4),
               (uint)(*(ushort **)(&DAT_20803644 + uVar5 * 4))[1]);
  gui_draw_runs(iVar4,(uint)DAT_208007c6,(uint)DAT_208007c4,*(void **)(&DAT_20803644 + uVar5 * 4));
  return;
}


// ===== FUN_2012e678 @ 2012e678 (80 bytes)

void FUN_2012e678(int param_1,int param_2)

{
  gpio_p2_15(1);
  if (((*(byte *)(param_1 + 3) & 4) != 0) ||
     ((*(byte *)(param_1 + 3) & 3) != (*(byte *)(param_2 + 3) & 3))) {
    DAT_208f4897 = 0;
  }
  FUN_201310ec(param_1,1);
  return;
}


// ===== screen_saver_exit @ 2012e6c8 (124 bytes)

/* layers back after 0x7B */

void screen_saver_exit(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  layer_fade(5,0);
  layer_alpha_rect_off(5);
  __aeabi_memclr(uVar2,0xbb800);
  layer_hide(6);
  itron_dly_tsk(0xf);
  bVar1 = mouse_cursor_visible();
  if (bVar1 != 0) {
    layer_show(6);
  }
  DAT_208004ca = 0;
  DAT_208004cc = 0;
  layer_show(3);
  layer_show(4);
  return;
}


// ===== rec_start_stop @ 2012e744 (352 bytes)

/* packet 0x3F: start/stop recording to SD with a time-stamp name */

void rec_start_stop(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_5c [4];
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
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  
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
  if (DAT_2080048e < 2) {
    DAT_2080048e = 1;
    cVar1 = *(char *)(param_1 + 1);
    iVar2 = sd_state_bit6();
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
LAB_2012e7f0:
      mainlink_send_audio_error(uVar3);
      return;
    }
    if (cVar1 == '\x01') {
      iVar2 = FUN_20103bc0(iVar2);
      if (iVar2 != 0) {
        uVar3 = 0xfffffffd;
        goto LAB_2012e7f0;
      }
      iVar2 = FUN_20124848(2,1);
      if (iVar2 != 0) {
        rtc_get_date(local_5c,local_18,local_1c);
        rtc_get_time(local_20,local_24,local_28);
        snprintf(&local_58,0x20,"20%02x%02x%02x_%02x%02x%02x",local_5c[0],local_18[0],local_1c[0],
                 local_20[0],local_24[0],local_28[0]);
        uVar4 = be32_load(&DAT_208f0b9f);
        snprintf(&local_38,0x10,"%08d",uVar4);
        rec_start((int)&local_58,&local_38,(uint)DAT_208f0b57,1);
        DAT_20800491 = 1;
        return;
      }
    }
    else if (cVar1 == '\0') {
      iVar2 = FUN_20124848(0);
      if (iVar2 != 0) {
        rec_stop();
      }
      DAT_20800491 = 0;
    }
  }
  return;
}


// ===== rtc_set_from_main @ 2012e8f4 (180 bytes)

/* packet 0x65: BCD date/time -> RTC */

void rtc_set_from_main(int param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  bVar2 = *(byte *)(param_1 + 1);
  uVar6 = (uint)*(byte *)(param_1 + 2);
  uVar5 = (uint)*(byte *)(param_1 + 3);
  bVar3 = *(byte *)(param_1 + 4);
  bVar4 = *(byte *)(param_1 + 5);
  iVar1 = bcd_to_bin((uint)bVar2);
  if (99 < iVar1) {
    bVar2 = 99;
  }
  iVar1 = bcd_to_bin(uVar6);
  if (0xc < iVar1) {
    uVar6 = 0xc;
  }
  iVar1 = bcd_to_bin(uVar6);
  if (iVar1 < 1) {
    uVar6 = 1;
  }
  iVar1 = bcd_to_bin(uVar5);
  if (0x1f < iVar1) {
    uVar5 = 0x1f;
  }
  iVar1 = bcd_to_bin(uVar5);
  if (iVar1 < 1) {
    uVar5 = 1;
  }
  iVar1 = bcd_to_bin((uint)bVar3);
  if (0x17 < iVar1) {
    bVar3 = 0x17;
  }
  iVar1 = bcd_to_bin((uint)bVar4);
  if (0x3b < iVar1) {
    bVar4 = 0x3b;
  }
  rtc_set_datetime(bVar2,(byte)uVar6,(byte)uVar5,bVar3,bVar4);
  return;
}


// ===== FUN_2012e9a8 @ 2012e9a8 (204 bytes)

void FUN_2012e9a8(int param_1,int param_2)

{
  DAT_208f4638 = 0;
  DAT_208f4639 = 0;
  DAT_208f463a = 0;
  DAT_208f463b = 0;
  DAT_208f4634 = 0;
  DAT_208f463c = 0;
  DAT_208f463d = 0;
  if (DAT_208f0b18 == '\0') {
    return;
  }
  DAT_208f4638 = (*(byte *)(param_1 + 5) & 0x20) != (*(byte *)(param_2 + 5) & 0x20);
  DAT_208f4639 = DAT_208f4632 != DAT_208f0b1e;
  DAT_208f463a = DAT_208f4631 != DAT_208f0b1d;
  if ((DAT_208f4633 == '\0') && (DAT_208f0b1f == '\x01')) {
    DAT_208f463b = 1;
  }
  DAT_208f4634 = (DAT_208f462c == '@' || DAT_208f462c == 'C') || DAT_208f462c == ':';
  if ((DAT_208f462c == '0') && (*(char *)(param_1 + 0x98) == -1)) {
    DAT_208f463c = 1;
  }
  DAT_208f463d = DAT_208f4635 != DAT_208f0b21;
  return;
}


// ===== FUN_2012ea74 @ 2012ea74 (324 bytes)

void FUN_2012ea74(char *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (((cVar1 == '#' || cVar1 == '?') || (cVar1 == 'd' || cVar1 == 'e')) ||
     ((cVar1 == 'z' || cVar1 == '{') || cVar1 == '|')) {
    return;
  }
  if (cVar1 == 'C') {
    memcpy(&DAT_208f0fcb,param_1,0x240);
    return;
  }
  memcpy(&DAT_208f0fcb,param_1,0x240);
  if (cVar1 != DAT_208f0b18) {
    DAT_208f462d = 0;
  }
  DAT_208f462e = param_1[1];
  DAT_208f462f = param_1[2];
  DAT_208f4630 = (byte)(((uint)(byte)param_1[5] << 0x1a) >> 0x1f);
  DAT_208f4631 = (byte)(((uint)(byte)param_1[3] << 0x1d) >> 0x1f);
  DAT_208f4635 = param_1[3] & 3;
  DAT_208f4632 = (byte)(((uint)(byte)param_1[4] << 0x1a) >> 0x1f);
  DAT_208f4633 = (byte)param_1[0x23] >> 7;
  if (cVar1 == '@') {
    DAT_208f4636 = 1;
LAB_2012eb64:
    DAT_208f4633 = 0;
LAB_2012eb68:
    if (cVar1 == ':') {
      DAT_208f4637 = 1;
    }
    if (cVar1 == ':' || cVar1 == '1') goto LAB_2012eb7c;
  }
  else if (cVar1 == 'p') {
    if ((-1 < (int)((uint)(byte)param_1[4] << 0x1a)) && (DAT_208f0b1e == '\x01')) {
      DAT_208f4632 = 1;
    }
  }
  else if (cVar1 != 'P') {
    DAT_208f4636 = 0;
    if (cVar1 == '7' || cVar1 == '@') goto LAB_2012eb64;
    goto LAB_2012eb68;
  }
  DAT_208f4637 = 0;
LAB_2012eb7c:
  DAT_208f462c = cVar1;
  FUN_2012e9a8(param_1,param_2);
  __aeabi_memcpy4(&DAT_208f0b18,&DAT_208f462c,0x12);
  return;
}


// ===== gui_screen_update @ 2012ebb8 (2912 bytes)

/* compares the new MAIN screen packet with 0x208F0B2A and dispatches on byte 0 */

void gui_screen_update(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  bool bVar6;
  byte local_270;
  byte local_26f;
  byte local_26e;
  byte local_269;
  byte local_268;
  byte local_260;
  undefined2 local_1d8;
  undefined2 local_1d6;
  undefined2 local_1d4;
  int local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = fb_get_layer_addr(0);
  local_30 = fb_get_layer_addr(DAT_208085b8);
  local_2c = fb_get_layer_addr(DAT_208085bc);
  pcVar5 = (char *)0x0;
  uVar4 = 0;
  if (DAT_20800488 == '\x01') {
    mainlink_inject_rx(&DAT_208f0fcb);
    DAT_20800488 = '\0';
  }
  mainlink_get_last_frame((uint)&local_270);
  FUN_2012ea74(&local_270,&DAT_208f0b2a);
  iVar2 = memcmp(&local_270,&DAT_208f0b2a,0x240);
  if (iVar2 == 0) goto LAB_2012f698;
  if ((local_270 == 0x39 || local_270 == 0x3a) || local_270 == 0x3f) {
LAB_2012ec7c:
    DAT_2080049f = 0;
  }
  else {
    if ((DAT_20800490 == '\0' && DAT_2080048f == '\0') && DAT_20800491 == '\0') {
      if (DAT_2080048e != '\x03') {
        audio_clear_error();
      }
      DAT_2080048e = '\0';
      DAT_208007d8 = 0;
    }
    if (local_270 != 0x7c) goto LAB_2012ec7c;
  }
  if (DAT_208f0b2a == 100) {
    if (local_270 != 100) {
      layer_show(6);
      if (DAT_208f0b2a != 100) goto LAB_2012ecc8;
      goto LAB_2012ecdc;
    }
  }
  else {
LAB_2012ecc8:
    if (local_270 == 100) {
      layer_hide(6);
    }
LAB_2012ecdc:
    if (local_270 == 0x65) {
      rtc_set_from_main((int)&local_270);
      return;
    }
    if (local_270 == 0x23) {
      pkt23_tx_text(&local_270);
      return;
    }
    if ((((((DAT_208f0b2a == 0x40) && (local_270 != 0x40 && local_270 != 0x20)) &&
          (local_270 != 0x30 && local_270 != 0x31)) &&
         ((local_270 != 0x37 && local_270 != 0x24 && (local_270 != 0x43 && local_270 != 0x70)))) &&
        ((local_270 != 0x7b && local_270 != 0x7c &&
         ((local_270 != 0x7a && local_270 != 0x41 && (local_270 != 0x62 && local_270 != 0x21))))))
       && (local_270 != 0x34 && local_270 != 0x50)) {
      return;
    }
  }
  if (DAT_208f4633 != '\0') {
    if (DAT_208f4638 == '\0') {
      if (((local_270 == 0x3a || local_270 == 0x39) || local_270 == 0x31) || (DAT_208f0b2a == 0x70))
      {
        if (DAT_208f4630 != '\0') {
          DAT_20800483 = '\x01';
        }
        return;
      }
    }
    else {
      __aeabi_memclr(local_2c,0xbb800);
    }
  }
  if ((DAT_208f463c != '\0') && (DAT_208f0b2a == 0x31 || DAT_208f0b2a == 0x3a)) {
    return;
  }
  if ((DAT_208f0b2a == 0x70) && (local_270 == 0x30)) {
    if ((byte)local_1d8 == 0xff) {
      return;
    }
  }
  else {
    if (local_270 == 0x3f) {
      rec_start_stop((int)&local_270);
      DAT_2080049e = DAT_208f0b2a;
      memcpy(&DAT_208f0b2a,&local_270,0x240);
      return;
    }
    if (((DAT_208f0b2a == 0x7b) && (local_270 != 0x7b)) &&
       ((screen_saver_exit(), DAT_208f4636 != '\0' || (local_270 == 0x3a)))) {
      FUN_2012616c(0);
    }
  }
  if ((DAT_208f463b != '\0') && (__aeabi_memclr(local_2c,0xbb800), DAT_208f4630 != '\0')) {
    if (local_270 == 0x41) {
      fb_fill_rect(local_30,0x821,0x6d,0x1bb,0x164,0x45);
    }
    else {
      fb_clear_rect(local_30,0x6d,0x1bb,0x164,0x45);
    }
  }
  if (DAT_208f463a != '\0') {
    if (DAT_208f4630 == '\0') {
      iVar2 = 0xb4;
    }
    else {
      iVar2 = 0x6d;
    }
    fb_clear_rect(local_28,iVar2,1,0x31e,0x15);
    fb_clear_rect(local_30,iVar2,1,0x31e,0x15);
  }
  uVar3 = (uint)local_270;
  if (uVar3 - 0x20 < 0x22) {
    if (uVar3 != 0x21) {
LAB_2012efbc:
      pclink_tx_set_status((uint)&local_26f);
      DAT_2080048b = DAT_2080048a;
      bVar6 = (local_269 & 0x80) != 0;
      bVar1 = ~DAT_2080048a;
      DAT_2080048a = bVar6;
      if ((bVar6 & bVar1) != 0) {
        FUN_2013448c();
        FUN_20120db4();
      }
      if ((DAT_2080048b & ~DAT_2080048a) != 0) {
        FUN_20134498();
        FUN_20120dc0();
      }
      if ((local_260 & 0xf0) != (DAT_208f0b3a & 0xf0)) {
        bVar6 = (local_260 & 0xf0) == 0;
        if (bVar6) {
          FUN_201342f8(0);
        }
        else {
          FUN_201342f8(1);
        }
        FUN_20120d4c(!bVar6);
      }
      FUN_2012e678(&local_270,&DAT_208f0b2a,DAT_20800485);
      if (local_270 != 0x3a) {
        if ((DAT_208f4632 == '\0') && (DAT_208f4636 == '\0')) {
          if (((DAT_20800483 != '\0') || ((local_270 == 0x39 && (DAT_208f0b2a != 0x39)))) ||
             ((DAT_208f463c != '\0' && (DAT_208f0b2a == 0x39)))) {
            DAT_20800483 = '\0';
            DAT_20800484 = 0;
            fb_clear_rect(local_30,0x6d,0,800,0x173);
            if ((local_270 == 0x39) || (DAT_208f0b2a == 0x39)) {
              DAT_20800485 = 0;
            }
            else {
              DAT_20800485 = 1;
            }
            goto LAB_2012f188;
          }
        }
        else {
          DAT_20800483 = '\x01';
          if (local_270 == 0x37) {
LAB_2012f0ac:
            DAT_20800484 = 1;
          }
          else {
            if (local_270 == 0x70) {
              if (((DAT_208f0b2a != 0x3f && DAT_208f0b2a != 0x37) && (DAT_208f4632 == '\0')) &&
                 (DAT_208f0b2a != 0x70)) goto LAB_2012f09c;
              goto LAB_2012f0ac;
            }
            if (local_270 == 0x24) goto LAB_2012f0ac;
LAB_2012f09c:
            if (DAT_208f4636 != '\0') goto LAB_2012f0ac;
            DAT_20800484 = 0;
          }
          if ((DAT_208f0b2a == 0x37) &&
             ((local_270 != 0x37 && local_270 != 0x70) && local_270 != 0x24)) {
            fb_clear_rect(local_30,0x6d,0,800,0x173);
            DAT_20800485 = 1;
          }
LAB_2012f188:
          if ((DAT_208f4636 != '\0') || (local_270 == 0x3a)) goto LAB_2012f1c0;
        }
        scr_main_layout((int)&local_270,0x208f0b2a,(uint)DAT_20800485);
        DAT_20800485 = 0;
      }
LAB_2012f1c0:
      if (local_270 == DAT_208f0b2a) {
        if ((local_270 == 0x30) || (local_270 == 0x31)) {
          if ((byte)local_1d8 != DAT_208f0bc2) {
LAB_2012f2d8:
            __aeabi_memclr(local_2c,0xbb800);
            goto LAB_2012f2f8;
          }
        }
        else if (local_270 == 0x70) {
          pcVar5 = (char *)&DAT_208f0b2a;
          uVar4 = 1;
          goto LAB_2012f320;
        }
        pcVar5 = (char *)&DAT_208f0b2a;
LAB_2012f2f8:
        if (((local_270 == 0x20 || local_270 == 0x39) || local_270 == 0x37) &&
           (DAT_208f0b2a != 0x70)) {
          audio_error_check((int)&local_270);
        }
      }
      else {
        if (((local_270 == 0x40 || local_270 == 0x43) || (local_270 == 0x70 || local_270 == 0x31))
           && ((DAT_208f0b2a == 0x40 || DAT_208f0b2a == 0x43 ||
               ((DAT_208f0b2a == 0x70 || DAT_208f0b2a == 0x7c ||
                ((DAT_208f0b2a == 0x31 || DAT_208f0b2a == 0x7a) || local_270 == 0x70)))))) {
          uVar4 = 1;
          goto LAB_2012f2f8;
        }
        uVar4 = 1;
        if ((DAT_208f0b2a != 0) &&
           (layer_alpha_rect_off(5), DAT_208f0b2a == 0x7b || DAT_208f0b2a == 0x7a)) {
          if (DAT_208f4636 != '\0') goto LAB_2012f2f8;
          if (local_270 == 0x3a) goto LAB_2012f320;
        }
        if (local_270 == 0x30) {
          if ((byte)local_1d8 != 0xff) {
LAB_2012f26c:
            if (DAT_20800497 == '\0') {
              return;
            }
            if (DAT_208f0b2a != 0) goto LAB_2012f2d8;
            goto LAB_2012f2f8;
          }
        }
        else if (local_270 != 0x24) goto LAB_2012f26c;
      }
LAB_2012f320:
      iVar2 = FUN_2012c2d8(&local_270,pcVar5);
      if (iVar2 != 0) {
        if (local_270 == 0x39) {
          scr_vfo((char *)&local_270,pcVar5,uVar4);
          vfo_audio_status_draw((int)&local_270,uVar4);
        }
        else if (local_270 < 0x3a) {
          if (local_270 == 0x31) {
            scr_value_popup((int)&local_270);
          }
          else if (local_270 < 0x32) {
            if (local_270 != 0x20) {
              if (local_270 == 0x24) {
                if ((local_1d6._1_1_ & 0x7f) != (DAT_208007ea._1_1_ & 0x7f)) {
                  backlight_set(local_1d6._1_1_ & 0x7f);
                }
                if (((byte)local_1d4 & 0x7f) != ((byte)DAT_208007ec & 0x7f)) {
                  dimmer_set((byte)local_1d4 & 0x7f);
                }
                FUN_2012194c(&local_270,&DAT_208f0b2a,0);
                if (((byte)local_1d8 & 3) == ((byte)DAT_208007e8 & 3)) {
                  if ((local_1d4._1_1_ & 0x1f) != (DAT_208007ec._1_1_ & 0x1f)) goto LAB_2012f534;
                }
                else {
LAB_2012f534:
                  gui_apply_display_cfg((byte *)&local_1d8,(byte *)&DAT_208007e8,0);
                }
                if (((byte)local_1d8 & 4) != ((byte)DAT_208007e8 & 4)) {
                  gpio_ft4222_reset((byte)local_1d8 & 4);
                }
                DAT_208007e8 = local_1d8;
                DAT_208007ea = local_1d6;
                DAT_208007ec = local_1d4;
              }
              else if (local_270 == 0x30) {
                scr_select_popup((int)&local_270,(int)pcVar5,uVar4);
              }
            }
          }
          else if (local_270 == 0x34) {
            scr_info((int)&local_270);
          }
          else if (local_270 == 0x37) {
            scr_func_panel((int)&local_270,uVar4);
          }
        }
        else if (local_270 == 0x50) {
          if (DAT_208f463b != '\0') {
            uVar4 = 1;
          }
          scr_keyboard((int)&local_270,(int)pcVar5,uVar4);
        }
        else if (local_270 < 0x51) {
          if (local_270 == 0x3a) {
            scr_playlist((int)&local_270,(char *)&DAT_208f0b2a);
            FUN_2012616c(1);
          }
          else if (local_270 == 0x40) {
            scr_text_list((int)&local_270,(int)pcVar5,uVar4);
          }
          else if (local_270 == 0x41) {
            scr_memory_list((int)&local_270,uVar4);
          }
        }
        else if (local_270 == 0x62) {
          if (DAT_208f463b != '\0') {
            uVar4 = 1;
          }
          scr_setup_menu((int)&local_270,(int)pcVar5,uVar4);
          rtc_int_setup();
        }
        else if ((local_270 == 0x70) && (scr_confirm((int)&local_270,uVar4), DAT_208f4636 != '\0'))
        {
          FUN_2012616c(1);
        }
      }
      led_set_mask((uint)local_268);
      DAT_2080049e = DAT_208f0b2a;
      memcpy(&DAT_208f0b2a,&local_270,0x240);
      goto LAB_2012f698;
    }
  }
  else if ((uVar3 == 0x50 || uVar3 == 0x62) || uVar3 == 0x70) goto LAB_2012efbc;
  if (uVar3 == 0x7a) {
    screen_capture_bmp();
    DAT_208f0b2a = local_270;
    DAT_20800488 = '\x01';
    if (DAT_208f0fcb == ':') {
      FUN_2012616c(0);
    }
    goto LAB_2012f698;
  }
  if (uVar3 < 0x7b) {
    if (uVar3 == 0x21) {
      led_set_one((uint)local_26f,(uint)local_26e);
      goto LAB_2012f698;
    }
    if (uVar3 != 0x43) {
      if (uVar3 == 100) {
        scr_lcd_test((int)&local_270);
        DAT_208f0b2a = local_270;
      }
      goto LAB_2012f698;
    }
    if ((DAT_208f0b2a != 0x43) || (iVar2 = memcmp(&DAT_208f0d6a,&local_26f,0x21), iVar2 != 0)) {
      scr_sd_menu((int)&local_270);
      memcpy(&DAT_208f0d6a,&local_26f,0x21);
    }
  }
  else {
    if (uVar3 == 0x7b) {
      if (DAT_208f0b2a != 0x7b) {
        DAT_20800487 = 0;
        DAT_20800485 = 1;
        DAT_208f0b2a = local_270;
        DAT_208f0b2b = local_26f;
      }
      goto LAB_2012f698;
    }
    if (uVar3 != 0x7c) goto LAB_2012f698;
    if (DAT_208f0b2a != 0x7c) {
      DAT_2080049f = 1;
      touch_calibration(1);
    }
  }
  DAT_208f0b2a = local_270;
LAB_2012f698:
  iVar2 = FUN_20125d8c();
  if (iVar2 != 0) {
    scr_playlist((int)&local_270,(char *)&DAT_208f0b2a);
    DAT_2080049e = DAT_208f0b2a;
    memcpy(&DAT_208f0b2a,&local_270,0x240);
  }
  FUN_201248f8();
  if (DAT_20800491 != '\0') {
    uVar4 = audio_state();
    if (uVar4 == 0) {
      FUN_20124848(0);
      DAT_20800491 = '\0';
    }
    iVar2 = sd_state_bit6();
    if (iVar2 == 0) {
      rec_stop();
      mainlink_send_audio_error(0xffffffff);
      DAT_20800491 = 0;
      return;
    }
  }
  return;
}


// ===== opening_check_main @ 2012f734 (416 bytes)

/* handles the 0x60 power-on packet */

uint opening_check_main(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_260;
  byte local_25f [14];
  undefined1 auStack_251 [4];
  byte local_24d;
  byte local_24c;
  byte local_24b;
  byte local_242;
  undefined1 local_240;
  byte local_1ba;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  
  uVar3 = 0;
  fb_get_layer_addr(DAT_208085b8);
  mainlink_get_frame60((uint)&local_260);
  if (local_260 == '`') {
    if ((~local_25f[0] & 0xf0) == 0) {
      iVar2 = 0;
      backlight_set(100);
      do {
        itron_dly_tsk(3);
        iVar2 = iVar2 + 1;
      } while (iVar2 * 0x21 < 0x9c5);
      uVar1 = fb_get_layer_addr(DAT_208085b8);
      __aeabi_memclr(uVar1,0xbb800);
      gui_update_layers();
      FUN_201322f0();
      while (DAT_20800493 == '\0') {
        gui_update_layers();
        itron_tslp_tsk(0xffffffff);
      }
    }
    else {
      local_242 = local_242 & 7;
      if (4 < local_242) {
        local_242 = 4;
      }
      FUN_20133dec(local_242);
      DAT_2080048a = (local_24b & 0x80) != 0;
      if ((DAT_2080048a & ~DAT_2080048b) != 0) {
        FUN_2013448c();
        FUN_20120db4();
      }
      if ((DAT_2080048b & ~DAT_2080048a) != 0) {
        FUN_20134498();
        FUN_20120dc0();
      }
      FUN_20134480((local_24d & 0x3f) >> 5);
      uVar1 = FUN_2012d318(local_24d & 0x20);
      FUN_20134444(uVar1,local_24c & 0x80);
      FUN_20134474(local_24c & 0x40);
      FUN_2012e3c8(local_240,local_20,local_1c);
      FUN_201342dc(local_20[0],local_1c[0]);
      scope2d_set_color(local_20[0]);
      fw_installed_versions_set_thunk((uint)local_25f);
      DAT_20800481 = local_1ba & 0xf;
      DAT_208f0b2a = 0x20;
      memcpy(&DAT_208f0b2b,auStack_251,0x97);
      FUN_201310ec(&local_260,0);
      uVar3 = 1;
    }
  }
  return uVar3;
}


// ===== opening_screen @ 2012f8d4 (1216 bytes)

/* YAESU logo fade-in, waits for MAIN ('`' 0x60 packet); timeout -> error screen */

void opening_screen(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined2 local_4e0;
  undefined1 local_4de;
  undefined1 local_4dd;
  undefined1 local_4dc;
  undefined2 local_4d8;
  undefined2 local_4d6;
  undefined2 local_4d4;
  ushort local_4d0;
  short local_4ce;
  ushort local_4cc;
  undefined2 local_4ca;
  undefined1 uStack_4c8;
  undefined1 auStack_4c7 [575];
  char local_288 [14];
  char local_27a;
  undefined1 auStack_1e1 [409];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  ushort *local_34;
  undefined2 *local_30;
  undefined4 local_2c;
  
  iVar5 = fb_get_layer_addr(0);
  iVar6 = fb_get_layer_addr(DAT_208085bc);
  local_38 = fb_get_layer_addr(DAT_208085b8);
  iVar9 = 0;
  __aeabi_memclr4(&uStack_4c8,0x240);
  fb_clear_rect(iVar5,0,0,800,0x1e0);
  fb_clear_rect(local_38,0,0,800,0x1e0);
  fb_clear_rect(iVar6,0,0,800,0x1e0);
  gui_update_layers();
  fb_clear_rect(iVar5,0,0,800,0x1e0);
  fb_clear_rect(local_38,0,0,800,0x1e0);
  fb_clear_rect(iVar6,0,0,800,0x1e0);
  gui_update_layers();
  layer_alpha_rect_off(3);
  layer_alpha_rect_off(5);
  local_4cc = DAT_208004d4;
  local_4d0 = DAT_208004d6;
  local_4ca = 0x1e6;
  local_4e0 = 0;
  local_4de = 0;
  local_4ce = (DAT_208004da - DAT_208004d6) + 0x18;
  local_34 = &local_4d0;
  local_4dd = 0;
  local_30 = &local_4e0;
  local_4dc = 0;
  local_2c = 0;
  lcd_power(1);
  local_4e0 = 0;
  layer_alpha_rect_set(0,4,1,&local_34);
  layer_alpha_rect_set(1,4,1,&local_34);
  vdc5_wait_frames(1);
  itron_dly_tsk(0x14);
  gui_draw_runs(local_38,(uint)DAT_208004d6,(uint)DAT_208004d4,&DAT_2016d2c0);
  gui_update_layers();
  local_4e0 = 2;
  layer_alpha_rect_set(0,4,1,&local_34);
  layer_alpha_rect_set(1,4,1,&local_34);
  backlight_enable(1);
  led_set_one(1,0);
  DAT_208004a2 = key_scan_first();
  if (DAT_2080049a == '\0') {
    mainlink_clear_status();
    mainlink_hello_poweron();
  }
  gui_update_layers();
  uVar7 = opening_check_main();
  while (uVar7 == 0) {
    if (DAT_20800493 != '\0') {
      return;
    }
    uVar7 = mainlink_got_esc();
    if (uVar7 != 0) {
      for (; iVar9 * 0x21 < 0x9c5; iVar9 = iVar9 + 1) {
        itron_dly_tsk(3);
      }
      fwupdate_screen_thunk();
    }
    itron_dly_tsk(3);
    iVar9 = iVar9 + 1;
    if (4999 < iVar9 * 0x21) goto LAB_2012fb90;
    uVar7 = opening_check_main();
  }
  bVar4 = mainlink_get_settings24((uint)&local_4d8);
  while( true ) {
    uVar1 = local_4d8;
    uVar2 = local_4d6;
    uVar3 = local_4d4;
    if (bVar4 != 0) {
      for (; DAT_208007ec = uVar3, DAT_208007ea = uVar2, DAT_208007e8 = uVar1, iVar9 * 0x21 < 0x9c5;
          iVar9 = iVar9 + 1) {
        itron_dly_tsk(3);
        uVar1 = DAT_208007e8;
        uVar2 = DAT_208007ea;
        uVar3 = DAT_208007ec;
      }
      mainlink_get_frame60((uint)local_288);
      if ((DAT_20800481 != 0) && (local_27a == '\0' || local_27a == -0x25)) {
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        memcpy(&local_48,auStack_1e1,0xc);
        str_rtrim((int)&local_48);
        gui_draw_text_centered
                  (local_38,(int)&local_48,(uint)DAT_208004da,(uint)DAT_208004d8,0x10,0x20800b1c);
        gui_update_layers();
        iVar9 = 0;
        if (DAT_20800481 != 0) {
          do {
            iVar9 = iVar9 + 1;
            itron_dly_tsk(100);
          } while (iVar9 < (int)(uint)DAT_20800481);
        }
      }
      mainlink_get_frame60((uint)local_288);
      if ((local_288[0] == '`') &&
         ((local_27a == '\x01' || local_27a == '\x02') || local_27a == '\x03')) {
        fwupdate_insert_sd_screen_thunk();
      }
      key_task_resume();
      DAT_20800495 = 1;
      pot_resend_all();
      layer_alpha_rect_set(0,4,0,&local_34);
      layer_alpha_rect_set(1,4,0,&local_34);
      gui_update_layers();
      uVar8 = fb_get_layer_addr(DAT_208085b8);
      __aeabi_memclr(uVar8,0xbb800);
      gui_update_layers();
      backlight_set(local_4d6._1_1_ & 0x7f);
      dimmer_set((byte)local_4d4 & 0x7f);
      memcpy(auStack_4c7,&DAT_208f0b2b,0x97);
      pclink_tx_set_status(0x208f0b2b);
      FUN_2012e678(&uStack_4c8,0,1);
      gui_apply_display_cfg((byte *)&local_4d8,(byte *)&local_4d8,1);
      gpio_ft4222_reset((byte)local_4d8 & 4);
      scr_main_layout(0x208f0b2a,0,1);
      gui_update_layers();
      return;
    }
    itron_dly_tsk(3);
    iVar9 = iVar9 + 1;
    if (4999 < iVar9 * 0x21) break;
    bVar4 = mainlink_get_settings24((uint)&local_4d8);
  }
LAB_2012fb90:
  fwupdate_insert_sd_screen_thunk();
  return;
}


// ===== logo_fade_in @ 2012fd94 (568 bytes)

/* key combo 6 path: logo fade-in before the boot-loader screen */

void logo_fade_in(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 local_27c;
  undefined1 local_27a;
  undefined1 local_279;
  undefined1 local_278;
  ushort local_270;
  short local_26e;
  ushort local_26c;
  undefined2 local_26a;
  undefined1 auStack_268 [576];
  ushort *local_28;
  undefined2 *local_24;
  undefined4 local_20;
  
  iVar1 = fb_get_layer_addr(0);
  iVar2 = fb_get_layer_addr(DAT_208085bc);
  iVar3 = fb_get_layer_addr(DAT_208085b8);
  iVar4 = 0;
  __aeabi_memclr4(auStack_268,0x240);
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  fb_clear_rect(iVar3,0,0,800,0x1e0);
  fb_clear_rect(iVar2,0,0,800,0x1e0);
  gui_update_layers();
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  fb_clear_rect(iVar3,0,0,800,0x1e0);
  fb_clear_rect(iVar2,0,0,800,0x1e0);
  gui_update_layers();
  layer_alpha_rect_off(3);
  layer_alpha_rect_off(5);
  local_26c = DAT_208004d4;
  local_270 = DAT_208004d6;
  local_26a = 0x1e6;
  local_27c = 0;
  local_26e = (DAT_208004da - DAT_208004d6) + 0x18;
  local_27a = 0;
  local_28 = &local_270;
  local_279 = 0;
  local_24 = &local_27c;
  local_278 = 0;
  local_20 = 0;
  lcd_power(1);
  layer_alpha_rect_set(0,4,1,&local_28);
  layer_alpha_rect_set(1,4,1,&local_28);
  vdc5_wait_frames(1);
  itron_dly_tsk(0x14);
  gui_draw_runs(iVar3,(uint)DAT_208004d6,(uint)DAT_208004d4,&DAT_2016d2c0);
  gui_update_layers();
  local_27c = 2;
  layer_alpha_rect_set(0,4,1,&local_28);
  layer_alpha_rect_set(1,4,1,&local_28);
  backlight_enable(1);
  led_set_one(1,0);
  mainlink_hello_key6();
  do {
    itron_dly_tsk(3);
    iVar4 = iVar4 + 1;
  } while (iVar4 * 0x21 < 0x9c5);
  layer_alpha_rect_set(0,4,0,&local_28);
  layer_alpha_rect_set(1,4,0,&local_28);
  gui_update_layers();
  return;
}


// ===== power_on_request @ 2012ffcc (88 bytes)

/* calls power_on_full_init [inference] */

void power_on_request(void)

{
  byte bVar1;
  
  power_on_full_init();
  backlight_set(100);
  bVar1 = key_scan_first();
  if (bVar1 != 6) {
    opening_screen();
    DAT_20800486 = 0;
    DAT_208004c8 = 0;
    DAT_208004c6 = 0;
    DAT_2080049c = 0;
    return;
  }
  DAT_208dbb4c = 2;
  logo_fade_in();
  FUN_201322e4(&DAT_208dbb44);
  return;
}


// ===== mainlink_wait_status @ 20130024 (324 bytes)

/* waits up to 5 s for the first MAIN status packet */

bool mainlink_wait_status(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_260;
  undefined4 local_25c;
  char local_258 [14];
  char local_24a;
  char local_1a5;
  
  iVar3 = 0;
  local_260 = 0;
  local_25c = 0;
  __aeabi_memclr4(local_258,0x240);
  mainlink_get_frame60((uint)local_258);
  DAT_2080049b = 1;
  itron_dly_tsk(0x14);
  mainlink_hello_poweron();
  DAT_2080049b = 0;
  key_task_resume();
  uVar2 = opening_check_main();
  while (uVar2 == 0) {
    itron_dly_tsk(3);
    iVar3 = iVar3 + 1;
    if (4999 < iVar3 * 0x21) {
      return false;
    }
    uVar2 = opening_check_main();
  }
  mainlink_get_frame60((uint)local_258);
  if (local_1a5 == '\x01') {
    DAT_2080049a = 1;
    return true;
  }
  bVar1 = mainlink_get_settings24((uint)&local_260);
  while (bVar1 == 0) {
    itron_dly_tsk(3);
    iVar3 = iVar3 + 1;
    if (4999 < iVar3 * 0x21) {
      return false;
    }
    bVar1 = mainlink_get_settings24((uint)&local_260);
  }
  DAT_208007e8 = (undefined2)local_260;
  local_260._2_2_ = (undefined2)((uint)local_260 >> 0x10);
  DAT_208007ea = local_260._2_2_;
  DAT_208007ec = (undefined2)local_25c;
  mainlink_get_frame60((uint)local_258);
  if ((local_258[0] == '`') && ((local_24a == '\x01' || local_24a == '\x02') || local_24a == '\x03')
     ) {
    return false;
  }
  iVar3 = FUN_2011727c();
  return iVar3 != 0;
}


// ===== gui_main_loop @ 20130188 (1044 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* runs in task_root after gui_start; one frame per wake-up */

void gui_main_loop(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte abStack_8 [8];
  
  iVar3 = fb_get_layer_addr(5);
  iVar6 = 0;
  DAT_208004a2 = key_scan_first();
  bVar1 = key_scan_first();
  if (bVar1 == 6) {
    DAT_208dbb4c = 2;
    logo_fade_in();
    FUN_201322e4(&DAT_208dbb44);
    do {
      if (DAT_20800493 != '\0') {
        FUN_20117030();
      }
      gui_update_layers();
      itron_tslp_tsk(0xffffffff);
    } while( true );
  }
  iVar4 = FUN_2011727c();
  if (iVar4 == 0) {
    bVar2 = mainlink_wait_status();
    if (!bVar2) {
      DAT_20800493 = '\x01';
      goto LAB_20130238;
    }
    bVar1 = key_scan_first();
    if (bVar1 == 6) {
      fwupdate_insert_sd_screen_thunk();
      goto LAB_20130238;
    }
    if (DAT_2080049a != '\0') {
      power_on_request();
      goto LAB_20130238;
    }
  }
  opening_screen();
LAB_20130238:
  bVar1 = mouse_cursor_visible();
  if (bVar1 != 0) {
    layer_show(6);
  }
  fb_blit_raw(iVar3,0,0,0x2016e860,0xc,0x13);
  while( true ) {
    if (DAT_20800494 != '\0') {
      iVar3 = sd_state_bit7();
      if (iVar3 != 0) {
        DAT_20800495 = 0;
        FUN_201322f0();
        __aeabi_memclr(&DAT_208f0b2a,0x240);
        if (DAT_20800493 == '\0') {
          DAT_20800495 = 1;
          mainlink_send_touch_key(1,0x166,0);
          itron_dly_tsk(1);
          mainlink_send_touch_key(0,0x166);
        }
      }
      DAT_20800496 = 0;
      DAT_20800494 = '\0';
      DAT_20450027 = 0;
    }
    if (DAT_20800492 != '\x10') break;
    DAT_20800492 = -1;
    DAT_20800493 = '\x01';
LAB_201303a8:
    if (DAT_208000b1 == '\x01') {
      play_stop();
      DAT_20800490 = 0;
    }
    if (DAT_208000b2 == '\x01') {
      rec_stop();
      DAT_2080048f = 0;
    }
    DAT_20800495 = 0;
    DAT_20800493 = '\0';
    DAT_20450027 = 0;
    DAT_2080049a = '\0';
    FUN_20117030();
    pclink_set_testmode(0);
    bVar1 = mainlink_get_settings24((uint)abStack_8);
    if (bVar1 != 0) {
      DAT_208007e8._0_1_ = (byte)DAT_208007e8 & 0xfe;
      gui_apply_display_cfg((byte *)&DAT_208007e8,abStack_8,0);
    }
    iVar3 = FUN_2011727c();
    while (iVar3 == 0) {
      itron_tslp_tsk(0xffffffff);
      iVar3 = FUN_2011727c();
    }
    DAT_20800496 = 0;
    power_on_request();
    if (DAT_20800493 == '\0') {
LAB_20130450:
      gui_screen_update();
      if (DAT_208004d0 == '\x03') {
        if (DAT_208f4632 == '\0') {
          scope_text_view_draw();
        }
      }
      else if ((DAT_20800483 == '\0') && (DAT_208f0b2a != 'z')) {
        scope_draw_frame();
        scope_markers_update();
      }
      if (DAT_20800484 == '\0') {
        if (DAT_208f4633 == '\0') {
          FUN_201233d4();
        }
        else {
          main_filter_graph();
        }
      }
      if (DAT_208004a0 != '\0') {
        DAT_208004a0 = DAT_208004a0 + -1;
      }
      main_status_icons();
      meter_draw();
      mainlink_send_rtc();
      mainlink_send_sd_state();
      FUN_201217b0();
      if ((DAT_208f0b2a == '{') && (DAT_208f0b2b != '\0')) {
        scr_screen_saver();
      }
      else {
        FUN_201218a4();
      }
      FUN_20131638();
      FUN_20121988(&DAT_20800838);
      iVar6 = iVar6 + DAT_20800838;
      if (DAT_208004a2 == 4) {
        pclink_set_testmode(1);
      }
      uVar5 = fb_get_layer_addr(DAT_208085bc);
      pclink_stats_print(uVar5);
      debug_overlay_draw(iVar6);
      FUN_20121988(&DAT_20800838);
      gui_update_layers();
      FUN_20121988(&DAT_20800838);
      iVar6 = DAT_20800838;
      itron_tslp_tsk(0xffffffff);
      FUN_20121988(&DAT_20800838);
      _DAT_208f4bf0 = _DAT_208f4bf0 + 1;
    }
  }
  if (DAT_20800492 == '\x11') {
    DAT_20800492 = -1;
    if (DAT_208000b1 == '\x01') {
      play_stop();
      DAT_20800490 = 0;
    }
    if (DAT_208000b2 == '\x01') {
      rec_stop();
      DAT_2080048f = 0;
    }
    DAT_20800495 = 0;
    FUN_20116da0(0);
    led_set_one(0,0);
    led_set_mask(0);
    backlight_enable(0);
    lcd_power(0);
    pclink_set_testmode(0);
    DAT_2080049a = '\0';
    itron_dly_tsk(200);
    DAT_2080049c = 0;
    DAT_20800497 = 1;
    power_on_request();
  }
  if (DAT_20800493 != '\0') goto LAB_201303a8;
  goto LAB_20130450;
}


// ===== screenshot_popup @ 2013059c (384 bytes)

/* "SCREEN SHOT" popup (popup slot 44); was screen_shot_menu */

void screenshot_popup(void)

{
  ushort *puVar1;
  uint uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  puVar1 = DAT_20802ce4;
  if (DAT_20802ce4 != (ushort *)0x0) {
    fb_fill_rect(uVar2,0x821,DAT_2080278e + 2 & 0xffff,DAT_2080278c + 2 & 0xffff,
                 *DAT_20802ce4 - 4 & 0xffff,DAT_20802ce4[1] - 4 & 0xffff);
    gui_draw_runs(uVar2,(uint)DAT_2080278e,(uint)DAT_2080278c,puVar1);
    fb_fill_box(uVar2,(uint)DAT_2080278e,DAT_2080278c + 6 & 0xffff,*puVar1 - 0xc & 0xffff,2,0x632c);
    fb_fill_box(uVar2,((uint)DAT_2080278e + (uint)puVar1[1]) - 2 & 0xffff,DAT_2080278c + 6 & 0xffff,
                *puVar1 - 0xc & 0xffff,2,0x632c);
    if (DAT_20802890 != 0) {
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      memcpy(&local_28,DAT_20802b9c,DAT_20802c1c);
      gui_draw_text(uVar2,&local_28,DAT_2080278e + DAT_20802892,DAT_2080278c + DAT_20802890,0x22,
                    &DAT_208015bc);
    }
  }
  return;
}


// ===== touch_cal_hit @ 2013071c (76 bytes)

/* touch inside the 70x70 window of calibration cross n */

uint touch_cal_hit(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (((((int)param_2 < (int)(*(ushort *)(&DAT_2016d61c + param_1 * 4) - 10)) ||
       (*(ushort *)(&DAT_2016d61c + param_1 * 4) + 0x3c <= param_2)) ||
      ((int)param_3 < (int)(*(ushort *)(&DAT_2016d61e + param_1 * 4) - 10))) ||
     (*(ushort *)(&DAT_2016d61e + param_1 * 4) + 0x3c <= param_3)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== touch_cal_step @ 20130768 (420 bytes)

/* calibration screen 0x7C: 5 crosses, store, send E5 to MAIN */

void touch_cal_step(uint param_1,uint param_2)

{
  undefined2 uVar1;
  uint uVar3;
  int iVar4;
  undefined1 auStack_2c [20];
  undefined4 local_18;
  undefined2 uVar2;
  
  local_18 = 0xe5;
  uVar3 = (uint)DAT_2080049f;
  uVar1 = (undefined2)param_1;
  uVar2 = (undefined2)param_2;
  switch(uVar3) {
  case 1:
    uVar3 = touch_cal_hit(uVar3,param_1,param_2);
    if (uVar3 != 0) {
      DAT_2080049f = DAT_2080049f + 1;
      DAT_208f120c = uVar1;
      DAT_208f120e = uVar2;
      touch_calibration((uint)DAT_2080049f);
    }
    break;
  case 2:
    uVar3 = touch_cal_hit(uVar3,param_1,param_2);
    if (uVar3 != 0) {
      DAT_2080049f = DAT_2080049f + 1;
      DAT_208f1210 = uVar1;
      DAT_208f1212 = uVar2;
      touch_calibration((uint)DAT_2080049f);
      return;
    }
    break;
  case 3:
    uVar3 = touch_cal_hit(uVar3,param_1,param_2);
    if (uVar3 != 0) {
      DAT_2080049f = DAT_2080049f + 1;
      DAT_208f1214 = uVar1;
      DAT_208f1216 = uVar2;
      touch_calibration((uint)DAT_2080049f);
      return;
    }
    break;
  case 4:
    uVar3 = touch_cal_hit(uVar3,param_1,param_2);
    if (uVar3 != 0) {
      DAT_2080049f = DAT_2080049f + 1;
      DAT_208f1218 = uVar1;
      DAT_208f121a = uVar2;
      touch_calibration((uint)DAT_2080049f);
      return;
    }
    break;
  case 5:
    uVar3 = touch_cal_hit(uVar3,param_1,param_2);
    if (uVar3 != 0) {
      layer_alpha_rect_opaque(5);
      iVar4 = fb_get_layer_addr(DAT_208085bc);
      fb_clear_rect(iVar4,0,0,800,0x1e0);
      gui_update_layers();
      DAT_208f121c = uVar1;
      DAT_208f121e = uVar2;
      memcpy(auStack_2c,&DAT_2016d638,0x14);
      touch_cal_store_points(0,(int)auStack_2c);
      touch_cal_store_points(1,0x208f120c);
      mainlink_queue_frame(&local_18,4);
      DAT_2080049f = 0;
      return;
    }
  }
  return;
}


// ===== FUN_20130968 @ 20130968 (48 bytes)

void FUN_20130968(void)

{
  if (DAT_208f1220 != '\0') {
    if (DAT_208f1220 == '\x01' || DAT_208f1220 == -1) {
      DAT_208f1221 = DAT_208f1220;
    }
    return;
  }
  DAT_208f1221 = 0;
  return;
}


// ===== FUN_20130998 @ 20130998 (12 bytes)

undefined1 FUN_20130998(void)

{
  return DAT_208f4637;
}


// ===== FUN_201309b4 @ 201309b4 (12 bytes)

undefined1 FUN_201309b4(void)

{
  return DAT_20800493;
}


// ===== gui_link_error_popup @ 201309c0 (604 bytes)

/* draws the link error box with the unanswered command as hex */

void gui_link_error_popup(undefined4 param_1,uint param_2)

{
  short sVar1;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_40 = fb_get_layer_addr(DAT_208085bc);
  local_38 = 0x33323130;
  uStack_34 = 0x37363534;
  uStack_30 = 0x42413938;
  uStack_2c = 0x46454443;
  DAT_20800497 = 0;
  fb_fill_rect(local_40,0x821,DAT_208027de + 2 & 0xffff,DAT_208027dc + 2 & 0xffff,0x1e8,0x54);
  gui_draw_runs(local_40,(uint)DAT_208027de,(uint)DAT_208027dc,&DAT_2016e248);
  fb_fill_box(local_40,(uint)DAT_208027de,DAT_208027dc + 6 & 0xffff,0x1e0,2,0x632c);
  fb_fill_box(local_40,DAT_208027de + 0x56 & 0xffff,DAT_208027dc + 6 & 0xffff,0x1e0,2,0x632c);
  if (DAT_208028e0 != 0) {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    memcpy(&local_50,DAT_20802bec,DAT_20802c30);
    gui_draw_text(local_40,&local_50,DAT_208027de + DAT_208028e2,DAT_208027dc + DAT_208028e0,0x22,
                  &DAT_208015bc);
  }
  sVar1 = DAT_208029e4;
  if (DAT_208029e4 != 0) {
    __aeabi_memset(&local_50,0xd,0x20);
    local_48 = CONCAT13(*(undefined1 *)((int)&local_38 + (param_2 & 0xf)),
                        CONCAT12(*(undefined1 *)((int)&local_38 + (param_2 >> 4)),
                                 CONCAT11(0x20,(undefined1)local_48)));
    local_44 = CONCAT31(local_44._1_3_,0x68);
    if (DAT_208028e0 == 0) {
      gui_draw_text_centered
                (local_40,(int)&local_50,(uint)DAT_208027de + (uint)DAT_208029e6 & 0xffff,
                 (uint)(ushort)(DAT_208027dc + sVar1),0x22,0x208015bc);
      return;
    }
    sVar1 = strlen(&local_50);
    gui_draw_text(local_40,&local_50,DAT_208027de + DAT_208029e6,
                  (DAT_208027dc + 0x1ec + sVar1 * -0x22) - DAT_208029e4,0x22,&DAT_208015bc);
  }
  return;
}


// ===== mainlink_set_power_cmd @ 20130c40 (12 bytes)

/* 0x20800492 = 0x7F sub-command (0x10 / 0x11 end the GUI loop) */

void mainlink_set_power_cmd(byte param_1)

{
  DAT_20800492 = param_1;
  return;
}


// ===== FUN_20130c70 @ 20130c70 (32 bytes)

void FUN_20130c70(void)

{
  undefined1 uVar1;
  
  uVar1 = DAT_208f4baa;
  __aeabi_memclr(&DAT_208f4896,0x35e);
  DAT_208f4baa = uVar1;
  return;
}


// ===== FUN_20130c90 @ 20130c90 (1052 bytes)

void FUN_20130c90(undefined4 param_1,int param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 local_8;
  
  local_8 = 0;
  switch(param_1) {
  case 0:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b91 >> 6;
    }
    else {
      if ((DAT_208f0b91 & 0xc0) == (*(byte *)(param_2 + 0x67) & 0xc0)) {
        return;
      }
      bVar3 = *(byte *)(param_2 + 0x67) >> 6;
    }
    goto LAB_20130eb4;
  case 1:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b91;
      if ((DAT_208f0b91 & 0x30) != 0) goto LAB_20130d5c;
    }
    else {
      if ((DAT_208f0b91 & 0x3f) == (*(byte *)(param_2 + 0x67) & 0x3f)) {
        return;
      }
      if ((*(byte *)(param_2 + 0x67) & 0x30) != 0) {
        bVar3 = *(byte *)(param_2 + 0x67);
LAB_20130d5c:
        local_8 = 0x100000;
        bVar3 = bVar3 & 0xf;
        goto LAB_20130eb4;
      }
    }
    break;
  case 2:
    if (param_3 == 0) {
      local_8 = (uint)(byte)((DAT_208f0b92 & 3) + (DAT_208f0b92 >> 3 & 0x10)) << 8;
    }
    else {
      if (DAT_208f0b92 == *(byte *)(param_2 + 0x68)) {
        return;
      }
      local_8 = (uint)(byte)((*(byte *)(param_2 + 0x68) & 3) +
                            (*(byte *)(param_2 + 0x68) >> 3 & 0x10)) << 8;
    }
    break;
  case 3:
    bVar3 = DAT_208f0b93;
    if ((param_3 != 0) && (bVar3 = *(byte *)(param_2 + 0x69), DAT_208f0b93 == bVar3)) {
      return;
    }
    goto LAB_20130eb4;
  case 4:
    if (param_3 == 0) {
      local_8 = (uint)(byte)((DAT_208f0b95 & 3) + DAT_208f0b94 * '\x10') << 8;
    }
    else {
      if ((DAT_208f0b94 == *(char *)(param_2 + 0x6a)) && (DAT_208f0b95 == *(byte *)(param_2 + 0x6b))
         ) {
        return;
      }
      local_8 = (uint)(byte)((*(byte *)(param_2 + 0x6b) & 3) + *(char *)(param_2 + 0x6a) * '\x10')
                << 8;
    }
    break;
  case 5:
    if (param_3 != 0) {
      bVar3 = *(byte *)(param_2 + 0x6c);
      if (DAT_208f0b96 == bVar3) {
        return;
      }
      bVar2 = *(byte *)(param_2 + 0x6c);
LAB_20130ee8:
      bVar3 = bVar3 >> 3 & 0x10;
      bVar2 = (byte)((bVar2 & 0x1f) >> 4);
      goto LAB_20130f3c;
    }
    bVar3 = (DAT_208f0b96 >> 3 & 0x10) - (char)((int)((uint)DAT_208f0b96 << 0x1b) >> 0x1f);
    goto LAB_20130eb4;
  case 6:
    if (param_3 != 0) {
      bVar3 = *(byte *)(param_2 + 0x6d);
      if (DAT_208f0b97 == bVar3) {
        return;
      }
      bVar2 = *(byte *)(param_2 + 0x6d);
      goto LAB_20130ee8;
    }
    bVar3 = (DAT_208f0b97 >> 3 & 0x10) - (char)((int)((uint)DAT_208f0b97 << 0x1b) >> 0x1f);
    goto LAB_20130eb4;
  case 7:
    bVar2 = DAT_208f0b97;
    bVar3 = DAT_208f0b97;
    if (param_3 != 0) {
      if (DAT_208f0b97 == *(byte *)(param_2 + 0x6d)) {
        return;
      }
      bVar2 = *(byte *)(param_2 + 0x6d);
      bVar3 = *(byte *)(param_2 + 0x6d);
    }
    bVar3 = (bVar3 & 4) << 2;
    bVar2 = bVar2 & 3;
LAB_20130f3c:
    local_8 = 0;
    bVar3 = bVar2 + bVar3;
    goto LAB_20130eb4;
  case 8:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b98 & 3;
    }
    else {
      if (DAT_208f0b98 == *(byte *)(param_2 + 0x6e)) {
        return;
      }
      bVar3 = *(byte *)(param_2 + 0x6e) & 3;
    }
    goto LAB_20130eb4;
  case 9:
    if (param_3 == 0) {
      bVar3 = DAT_208f0b99 & 0x7f;
    }
    else {
      bVar3 = *(byte *)(param_2 + 0x6f) & 0x7f;
      if ((DAT_208f0b99 & 0x7f) == bVar3) {
        return;
      }
    }
LAB_20130eb4:
    local_8 = (uint)CONCAT21(local_8._2_2_,bVar3) << 8;
    break;
  case 10:
    if (param_3 != 0) {
      return;
    }
    local_8 = (uint)(DAT_208f0b9a & 0xff30) << 0x10;
    if ((DAT_208f0b9a & 0x30) != 0) {
      local_8 = (uint)(CONCAT11(DAT_208f0b9a,DAT_208f0b9a) & 0xff300f) << 8;
    }
    DAT_208084d9 = DAT_208f0b9a & 0xf;
    break;
  default:
    goto switchD_20130ca0_caseD_b;
  case 0xd:
    if (param_3 == 0) {
      bVar3 = (byte)(((uint)DAT_208f0b9b << 0x19) >> 0x18);
    }
    else {
      if ((uint)DAT_208f0b9b == (uint)*(byte *)(param_2 + 0x71)) {
        return;
      }
      bVar3 = (byte)(((uint)*(byte *)(param_2 + 0x71) << 0x19) >> 0x18);
    }
    local_8 = (uint)(byte)((bVar3 >> 6) + 0x10) << 0x10;
    break;
  case 0xe:
    if (param_3 == 0) {
      uVar1 = CONCAT11((byte)(((uint)DAT_208f0b9b << 0x1b) >> 0x1e),DAT_208f0b9b);
    }
    else {
      if ((uint)DAT_208f0b9b == (uint)*(byte *)(param_2 + 0x71)) {
        return;
      }
      uVar1 = CONCAT11((byte)(((uint)*(byte *)(param_2 + 0x71) << 0x1b) >> 0x1e),
                       *(undefined1 *)(param_2 + 0x71));
    }
    local_8._0_2_ = (short)(uVar1 & 0xffff07) << 8;
    local_8._2_1_ = (char)((uVar1 & 0xffff07) >> 8);
    local_8._0_3_ = CONCAT12(local_8._2_1_ + '\x10',(short)local_8);
    local_8 = (uint)(uint3)local_8;
    break;
  case 0xf:
    if ((param_3 != 0) && (DAT_208f0b4c == *(byte *)(param_2 + 0x22))) {
      return;
    }
    local_8._0_2_ = (ushort)DAT_208f0b4c << 8;
    local_8._0_3_ = CONCAT12(0x10,(short)local_8);
    local_8 = (uint)(uint3)local_8;
    param_1 = 0x31;
  }
  local_8 = CONCAT31(local_8._1_3_,(char)param_1 + '\x11');
  uart4_send((uint)&local_8,3);
  itron_dly_tsk(1);
switchD_20130ca0_caseD_b:
  return;
}


// ===== FUN_201310ec @ 201310ec (68 bytes)

void FUN_201310ec(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = 0;
  do {
    FUN_20130c90(bVar1,param_1,param_2);
    do {
      bVar1 = bVar1 + 1;
      if (0xf < bVar1) {
        return;
      }
    } while (bVar1 == 0xb || bVar1 == 0xc);
  } while( true );
}


// ===== FUN_20131130 @ 20131130 (36 bytes)

void FUN_20131130(undefined1 param_1)

{
  (&DAT_208f4bac)[DAT_208f4bec] = param_1;
  DAT_208f4bec = DAT_208f4bec + 1 & 0x3f;
  return;
}


// ===== decode_text_rx @ 20131154 (512 bytes)

/* RX text filter (47-char sets 0x20801DE0..) -> 0x208F48C8 (inference: decoder) */

void decode_text_rx(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (0 < param_2) {
    do {
      bVar4 = *param_1;
      if (bVar4 == 0x10) {
LAB_20131230:
        FUN_20131130(bVar4);
LAB_20131238:
        if (bVar4 == 0x20) goto LAB_2013129c;
      }
      else {
        if (bVar4 < 0x11) {
          if (bVar4 == 0) goto LAB_20131238;
          if (bVar4 == 6) goto LAB_20131230;
          if (bVar4 != 10) goto LAB_201311c4;
          goto LAB_2013129c;
        }
        if (bVar4 == 0x1c) goto LAB_20131238;
        if (bVar4 == 0x1d) goto LAB_20131230;
LAB_201311c4:
        if (DAT_208084d9 == '\x01') {
          iVar3 = 8;
LAB_20131244:
          uVar2 = 0;
          do {
            if (iVar3 == 3) {
              if ((&DAT_20801de0)[uVar2] == bVar4) goto LAB_2013129c;
              bVar1 = (&DAT_20801e0f)[uVar2];
            }
            else {
              if ((&DAT_20801ecb)[uVar2] == bVar4) goto LAB_2013129c;
              bVar1 = (&DAT_20801efa)[uVar2];
            }
            if (bVar1 == bVar4) goto LAB_2013129c;
            uVar2 = uVar2 + 1 & 0xff;
          } while (uVar2 < 0x2f);
        }
        else {
          if (DAT_208084d9 == '\x04') {
            iVar3 = 3;
            goto LAB_20131244;
          }
          uVar2 = 0;
          do {
            if ((((&DAT_20801e3e)[uVar2] == bVar4) || ((&DAT_20801e6d)[uVar2] == bVar4)) ||
               ((&DAT_20801e9c)[uVar2] == bVar4)) goto LAB_2013129c;
            uVar2 = uVar2 + 1 & 0xff;
          } while (uVar2 < 0x2f);
        }
        bVar4 = 0x20;
LAB_2013129c:
        (&DAT_208f48c8)[DAT_208f489a] = bVar4;
        if ((bVar4 == 10) || (0x26 < DAT_208f489a)) {
          uVar2 = 0;
          do {
            iVar3 = uVar2 * 0x29;
            __aeabi_memclr(&DAT_208f48f1 + iVar3,0x29);
            memcpy(&DAT_208f48f1 + iVar3,&DAT_208f491a + iVar3,0x29);
            uVar2 = uVar2 + 1 & 0xff;
          } while (uVar2 < 0xf);
          __aeabi_memclr(&DAT_208f4b58,0x29);
          memcpy(&DAT_208f4b58,&DAT_208f48c8,DAT_208f489a + 1);
          __aeabi_memclr(&DAT_208f48c8,0x29);
          if (DAT_208f4899 < 0x10) {
            DAT_208f4899 = DAT_208f4899 + 1;
          }
          DAT_208f489a = 0;
        }
        else {
          DAT_208f489a = DAT_208f489a + 1;
        }
      }
      uVar5 = uVar5 + 1 & 0xff;
      param_1 = param_1 + 1;
    } while ((int)uVar5 < param_2);
  }
  return;
}


// ===== pkt23_tx_text @ 20131354 (492 bytes)

/* packet 0x23: TX text line 0x208F489F */

void pkt23_tx_text(int param_1)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
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
  
  bVar3 = *(byte *)(param_1 + 1) & 0x3f;
  DAT_208084d5 = -((char)*(byte *)(param_1 + 1) >> 7);
  if (DAT_208084d5 == '\0') {
    uVar2 = 0x32;
    do {
      cVar1 = *(char *)(param_1 + uVar2 + 3);
      if (cVar1 != ' ' && cVar1 != -2) break;
      uVar2 = uVar2 - 1 & 0xff;
    } while (uVar2 != 0);
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    __aeabi_memclr(&DAT_208f489f,0x29);
    memcpy(&local_48,param_1 + 4,uVar2);
    memcpy(&DAT_208f489f,param_1 + 4,uVar2);
    DAT_208f489b = (undefined1)uVar2;
    if ((DAT_208084d9 == '\x01' || DAT_208084d9 == '\x02') || DAT_208084d9 == '\x03') {
      if (DAT_208f4baa == 5) {
        DAT_208f4baa = 6;
      }
      else {
        DAT_208f4baa = 0;
      }
      DAT_208f4bab = 0;
      return;
    }
    if (DAT_208084d9 == '\x04') {
      DAT_208f4baa = 0xf;
      if (0x32 < bVar3) {
        bVar3 = 0x32;
      }
      DAT_208f4bab = bVar3;
      return;
    }
  }
  else {
    DAT_208084d7 = 0;
    if (DAT_208f4baa != 0x65) {
      if (0x65 < DAT_208f4baa) {
        switch(DAT_208f4baa) {
        case 0x66:
          DAT_208f4baa = 0x6f;
          break;
        case 0x67:
        case 0x68:
        case 0x69:
          DAT_208f4baa = 0x6d;
          break;
        case 0x6a:
          DAT_208f4baa = 0x6b;
          break;
        case 0x6b:
        case 0x6c:
        case 0x6d:
        case 0x6e:
        case 0x6f:
        case 0x70:
        case 0x71:
        case 0x72:
          goto switchD_201313b0_caseD_0;
        default:
switchD_201313b0_default:
          DAT_208f4baa = 0;
          return;
        }
        return;
      }
      if (DAT_208f4baa != 10) {
        if (DAT_208f4baa < 0xb) {
          switch(DAT_208f4baa) {
          case 0:
          case 4:
            goto switchD_201313b0_caseD_0;
          case 1:
            DAT_208f4baa = 0xe;
            return;
          case 2:
          case 3:
            if ((DAT_208084d9 != '\x01' && DAT_208084d9 != '\x02') && DAT_208084d9 != '\x03') {
              DAT_208084d7 = 0;
              DAT_208f4baa = 0xe;
              return;
            }
            if (DAT_208084d8 != '\0') {
              DAT_208084d7 = 0;
              DAT_208f4baa = 0xc;
              return;
            }
            DAT_208084d7 = 0;
            DAT_208f4baa = 0xe;
            return;
          case 5:
          case 6:
            DAT_208f4baa = 10;
            return;
          default:
            goto switchD_201313b0_default;
          }
        }
        if (DAT_208f4baa != 0xe) {
          if (DAT_208f4baa < 0xf) {
            if ((DAT_208f4baa != 0xb && DAT_208f4baa != 0xc) && DAT_208f4baa != 0xd) {
              DAT_208084d7 = 0;
              DAT_208f4baa = 0;
              return;
            }
          }
          else if (DAT_208f4baa != 0xf) {
            if (DAT_208f4baa == 100) {
              DAT_208084d7 = 0;
              DAT_208f4baa = 10;
              return;
            }
            DAT_208084d7 = 0;
            DAT_208f4baa = 0;
            return;
          }
        }
      }
    }
  }
switchD_201313b0_caseD_0:
  return;
}


// ===== FUN_201315a4 @ 201315a4 (28 bytes)

void FUN_201315a4(void)

{
  DAT_208f4bed = 0;
  DAT_208f4bec = 0;
  __aeabi_memclr_veneer(&DAT_208f4bac,0x40);
  return;
}


// ===== FUN_201315c0 @ 201315c0 (120 bytes)

undefined4 FUN_201315c0(uint param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_208f4bed;
  if (uVar1 == DAT_208f4bec) {
    return 0;
  }
  if ((byte)(&DAT_208f4bac)[uVar1] == param_1) {
    (&DAT_208f4bac)[uVar1] = 0;
    DAT_208f4bed = DAT_208f4bed + 1 & 0x3f;
    return 1;
  }
  if ((byte)(&DAT_208f4bac)[uVar1] != 0) {
    (&DAT_208f4bac)[uVar1] = 0;
    DAT_208f4bed = DAT_208f4bed + 1 & 0x3f;
  }
  return 0;
}


// ===== FUN_20131638 @ 20131638 (1204 bytes)

void FUN_20131638(void)

{
  byte bVar1;
  undefined3 uVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_28;
  undefined4 local_24;
  
  local_28 = 0;
  local_24 = 0xb3;
  DAT_208084d9 = DAT_208f0b9a & 0xf;
  if (((DAT_208f0b31 & 0x80) == 0) || (DAT_208084d5 != '\0')) {
    DAT_208084d6 = '\0';
  }
  else {
    DAT_208084d6 = '\x01';
  }
  bVar1 = DAT_208f0b31 & 0x40;
  if ((((DAT_208f0b31 & 0x80) != 0 && DAT_208084d5 != '\0') && (DAT_208084d7 < 0x15)) &&
     (bVar4 = DAT_208084d7 + 1, bVar5 = DAT_208084d7 + 1, DAT_208084d7 = bVar4, 0x14 < bVar5)) {
    mainlink_queue_frame(&local_24,2);
    DAT_208084d7 = 99;
  }
  if (DAT_208f4baa == 0x65) {
    iVar6 = FUN_201315c0(6);
    goto joined_r0x2013199c;
  }
  uVar2 = local_28._1_3_;
  uVar3 = local_28._3_1_;
  if (DAT_208f4baa < 0x66) {
    if (DAT_208f4baa == 10) {
      local_28 = CONCAT13(local_28._3_1_,0x10);
      uart4_send((uint)&local_28,3);
LAB_20131940:
      FUN_201315a4();
    }
    else {
      if (DAT_208f4baa < 0xb) {
        switch(DAT_208f4baa) {
        case 0:
          if (DAT_208084d6 == '\0') {
            return;
          }
          DAT_208f4baa = 1;
          return;
        case 1:
          if (((DAT_208084d9 == 1 || DAT_208084d9 == 2) || DAT_208084d9 == 3) && (bVar1 != 0)) {
            local_28 = CONCAT31(uVar2,0x1b);
            local_28 = CONCAT13(uVar3,CONCAT12(DAT_208f0b9a,(ushort)local_28)) & 0xff30ffff;
            if ((DAT_208f0b9a & 0x30) != 0) {
              local_28 = CONCAT22(local_28._2_2_,CONCAT11(DAT_208f0b9a,(undefined1)local_28)) &
                         0xffff0fff;
            }
            uart4_send((uint)&local_28,3);
            FUN_201315a4();
            DAT_208f4baa = DAT_208f4baa + 1;
            DAT_208084d8 = 1;
            return;
          }
          DAT_208f4baa = 3;
          return;
        case 2:
          iVar6 = FUN_201315c0(6);
          break;
        case 3:
          goto switchD_2013170c_caseD_3;
        case 4:
          iVar6 = FUN_201315c0(6);
          break;
        case 5:
          if ((DAT_208084d6 != '\0') && (DAT_208084d5 == '\0')) {
            if (DAT_208084d4 != '\x01') {
              return;
            }
            DAT_208f4baa = 100;
            return;
          }
          DAT_208f4baa = 10;
          return;
        case 6:
          DAT_208f4baa = 100;
          return;
        default:
          goto switchD_2013170c_default;
        }
        goto joined_r0x2013199c;
      }
      if (DAT_208f4baa == 0xe) {
LAB_20131904:
        DAT_208f4baa = 0;
        FUN_201315a4();
        return;
      }
      if (DAT_208f4baa < 0xf) {
        if (DAT_208f4baa == 0xb) {
          iVar6 = FUN_201315c0(0x10);
          if (iVar6 == 0) {
            return;
          }
        }
        else {
          if (DAT_208f4baa == 0xc) {
            if (((DAT_208084d9 != 1 && DAT_208084d9 != 2) && DAT_208084d9 != 3) ||
               (DAT_208084d8 != '\x01')) goto LAB_20131904;
            local_28 = CONCAT13(local_28._3_1_,CONCAT12(DAT_208f0b9a,(ushort)local_28)) & 0xff30ffff
            ;
            if ((DAT_208f0b9a & 0x30) != 0) {
              local_28 = (uint)(CONCAT21(local_28._2_2_,DAT_208f0b9a) & 0xffff0f) << 8;
            }
            local_28 = CONCAT31(local_28._1_3_,0x1b);
            uart4_send((uint)&local_28,3);
            DAT_208084d8 = '\0';
            goto LAB_20131940;
          }
          if (DAT_208f4baa != 0xd) goto switchD_2013170c_default;
          iVar6 = FUN_201315c0(6);
          if (iVar6 == 0) {
            return;
          }
        }
      }
      else {
        if (DAT_208f4baa == 0xf) {
          return;
        }
        if (DAT_208f4baa != 100) goto switchD_2013170c_default;
        local_28 = CONCAT31(uVar2,0x1b);
        local_28 = CONCAT13(uVar3,CONCAT12(DAT_208f0b9a,(ushort)local_28)) & 0xff30ffff;
        if ((DAT_208f0b9a & 0x30) != 0) {
          local_28 = CONCAT22(local_28._2_2_,CONCAT11(DAT_208f0b9a,(undefined1)local_28)) &
                     0xffff0fff;
        }
        uart4_send((uint)&local_28,3);
      }
    }
    goto LAB_201319a0;
  }
  switch(DAT_208f4baa) {
  case 0x66:
switchD_2013170c_caseD_3:
    local_28 = CONCAT13(local_28._3_1_,0x110);
    uart4_send((uint)&local_28,3);
    FUN_201315a4();
    goto LAB_201319a0;
  case 0x67:
    iVar6 = FUN_201315c0(6);
    if (iVar6 == 0) {
      return;
    }
    DAT_208084da = 3;
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x68:
    if (DAT_208084da != 0) {
LAB_20131a8c:
      DAT_208084da = DAT_208084da + -1;
      return;
    }
    goto LAB_201319d8;
  case 0x69:
    uVar7 = (uint)DAT_208f4bab;
    DAT_208f4bab = DAT_208f4bab + 1;
    local_28._0_2_ = CONCAT11((&DAT_208f489f)[uVar7],0x1d);
    local_28._0_3_ = (uint3)(ushort)local_28;
    uart4_send((uint)&local_28,3);
    FUN_201315a4();
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x6a:
    iVar6 = FUN_201315c0(0x1d);
    if (iVar6 == 0) {
      return;
    }
    if (DAT_208f489b <= DAT_208f4bab) {
      DAT_208f4baa = DAT_208f4baa + 1;
      return;
    }
LAB_201319d8:
    DAT_208f4baa = 'i';
    break;
  case 0x6b:
    if (DAT_208084d9 == 1) {
      DAT_208084da = 1;
    }
    else {
      DAT_208084da = 0x21;
    }
    DAT_208f4baa = 'l';
    break;
  case 0x6c:
    if (DAT_208084da != 0) goto LAB_20131a8c;
    DAT_208f4baa = 'm';
    break;
  case 0x6d:
    local_28 = CONCAT13(local_28._3_1_,0x10);
    uart4_send((uint)&local_28,3);
    FUN_201315a4();
    goto LAB_201319a0;
  case 0x6e:
    iVar6 = FUN_201315c0(0x10);
    goto joined_r0x2013199c;
  case 0x6f:
    local_28 = CONCAT13(local_28._3_1_,0x1b);
    uart4_send((uint)&local_28,3);
    DAT_208f4baa = DAT_208f4baa + 1;
    goto LAB_20131af4;
  case 0x70:
    iVar6 = FUN_201315c0(6);
joined_r0x2013199c:
    if (iVar6 == 0) {
      return;
    }
LAB_201319a0:
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x71:
    mainlink_queue_frame(&local_24,2);
    DAT_208f4baa = DAT_208f4baa + 1;
    break;
  case 0x72:
    DAT_208084d4 = '\0';
    DAT_208f4baa = '\x05';
    break;
  default:
switchD_2013170c_default:
    DAT_208f4baa = '\0';
LAB_20131af4:
    FUN_201315a4();
    return;
  }
  return;
}


// ===== FUN_20131f74 @ 20131f74 (768 bytes)

void FUN_20131f74(undefined1 param_1,uint param_2,uint param_3,undefined4 param_4,int param_5,
                 char *param_6)

{
  uint uVar1;
  
  uVar1 = fb_get_layer_addr(0);
  if (*param_6 != '{' && param_5 != 0) {
    FUN_20130c70();
  }
  DAT_2080850e = (ushort)param_2;
  DAT_2080850c = (ushort)param_3;
  DAT_208f489c = 5;
  DAT_208f489d = 0x28;
  DAT_20808510 = DAT_208084e8;
  DAT_20808512 = DAT_208084ea;
  DAT_20808514 = DAT_208084f4;
  DAT_20808516 = DAT_208084f6;
  DAT_208f4896 = param_1;
  fb_fill_box(uVar1,param_2,param_3,0x31e,3,0x3186);
  fb_fill_box_t(uVar1,(uint)DAT_2080850e,(uint)DAT_2080850c,0xe8,3,0x3186);
  fb_fill_box(uVar1,(uint)DAT_208084de,(uint)DAT_208084dc,0x31e,3,0x3186);
  fb_fill_box_t(uVar1,(uint)DAT_208084e2,(uint)DAT_208084e0,0xe8,3,0x3186);
  fb_fill_box(uVar1,DAT_208084ea - 3 & 0xffff,DAT_208084e8 - 3 & 0xffff,0x31e,3,0x3186);
  fb_fill_box_t(uVar1,(uint)DAT_208084e6,(uint)DAT_208084e4,
                (uint)DAT_208084f2 + (uint)DAT_208084fa + 3 & 0xffff,3,0x3186);
  fb_fill_box(uVar1,DAT_208084f6 - 3 & 0xffff,DAT_208084f4 - 3 & 0xffff,0x2b6,3,0x3186);
  fb_fill_box(uVar1,(uint)DAT_20808522,DAT_20808520 - 3 & 0xffff,
              (uint)DAT_208084e0 - (uint)DAT_20808520 & 0xffff,3,0x3186);
  fb_fill_box(uVar1,(uint)DAT_2080851e,DAT_2080851c - 3 & 0xffff,
              (uint)DAT_208084e0 - (uint)DAT_20808520 & 0xffff,3,0x3186);
  fb_clear_rect(uVar1,(uint)DAT_2080851a,(uint)DAT_20808518,0x62,0x3c);
  gui_draw_runs(uVar1,(uint)DAT_2080851a,(uint)DAT_20808518,&DAT_2016dc48);
  gui_draw_runs(uVar1,(uint)DAT_2080851a + (uint)DAT_20808502 & 0xffff,
                (uint)DAT_20808518 + (uint)DAT_20808500 & 0xffff,&DAT_2016dc58);
  fb_clear_rect(uVar1,(uint)DAT_2080851e,(uint)DAT_2080851c,0x62,0x3c);
  gui_draw_runs(uVar1,(uint)DAT_2080851e,(uint)DAT_2080851c,&DAT_2016dc48);
  gui_draw_runs(uVar1,(uint)DAT_2080851e + (uint)DAT_20808502 & 0xffff,
                (uint)DAT_2080851c + (uint)DAT_20808500 & 0xffff,&DAT_2016dc68);
  gui_area_dirty_set(0);
  FUN_20136584(uVar1,DAT_20808522,DAT_20808520,DAT_20808504,DAT_20808506,0,0,0);
  return;
}


// ===== fwupdate_insert_sd_screen_thunk @ 201322ac (8 bytes)

/* r0 = update-UI object 0x208F4BF4; b fwupdate_insert_sd_screen */

void fwupdate_insert_sd_screen_thunk(void)

{
  fwupdate_insert_sd_screen(&DAT_208f4bf4);
  return;
}


// ===== fwupdate_screen_thunk @ 201322b4 (8 bytes)

/* r0 = update-UI object 0x208F4BF4; b fwupdate_screen (#81) */

void fwupdate_screen_thunk(void)

{
  fwupdate_screen(&DAT_208f4bf4);
  return;
}


// ===== fw_installed_versions_set_thunk @ 201322bc (12 bytes)

/* r1 = r0, r0 = update-UI object 0x208F4BF4; b fw_installed_versions_set (#81) */

void fw_installed_versions_set_thunk(uint param_1)

{
  fw_installed_versions_set(&DAT_208f4bf4,param_1);
  return;
}

