// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20124a98 @ 20124a98 (32 bytes)

void FUN_20124a98(int param_1,int param_2,uint *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  
  puVar6 = (uint *)(&DAT_208f1234 + (param_1 + param_2 & 0xffffU) * 0x34);
  if (((uint)param_3 & 3) == 0) {
    while( true ) {
      uVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar2 = UnsignedSaturate(1 - (uVar9 & 0xff),8);
      uVar3 = UnsignedSaturate(1 - (uVar9 >> 8 & 0xff),8);
      uVar4 = UnsignedSaturate(1 - (uVar9 >> 0x10 & 0xff),8);
      uVar5 = UnsignedSaturate(1 - (uVar9 >> 0x18),8);
      if (CONCAT13((char)uVar5,CONCAT12((char)uVar4,CONCAT11((char)uVar3,(char)uVar2))) != 0) break;
      *param_3 = uVar9;
      param_3 = param_3 + 1;
    }
    while( true ) {
      *(char *)param_3 = (char)uVar9;
      if ((uVar9 & 0xff) == 0) break;
      uVar9 = uVar9 >> 8;
      param_3 = (uint *)((int)param_3 + 1);
    }
  }
  else {
    do {
      pcVar7 = (char *)((int)puVar6 + 1);
      uVar9 = *puVar6;
      pcVar8 = (char *)((int)param_3 + 1);
      *(char *)param_3 = (char)uVar9;
      if ((char)uVar9 == '\0') {
        return;
      }
      puVar6 = (uint *)((int)puVar6 + 2);
      cVar1 = *pcVar7;
      param_3 = (uint *)((int)param_3 + 2);
      *pcVar8 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ===== FUN_20124ab8 @ 20124ab8 (44 bytes)

void FUN_20124ab8(int param_1,int param_2,uint *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  
  puVar6 = (uint *)((param_1 + param_2 & 0xffffU) * 0x34 + 0x208f125a);
  if ((((uint)param_3 | (uint)puVar6) & 3) == 0) {
    while( true ) {
      uVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar2 = UnsignedSaturate(1 - (uVar9 & 0xff),8);
      uVar3 = UnsignedSaturate(1 - (uVar9 >> 8 & 0xff),8);
      uVar4 = UnsignedSaturate(1 - (uVar9 >> 0x10 & 0xff),8);
      uVar5 = UnsignedSaturate(1 - (uVar9 >> 0x18),8);
      if (CONCAT13((char)uVar5,CONCAT12((char)uVar4,CONCAT11((char)uVar3,(char)uVar2))) != 0) break;
      *param_3 = uVar9;
      param_3 = param_3 + 1;
    }
    while( true ) {
      *(char *)param_3 = (char)uVar9;
      if ((uVar9 & 0xff) == 0) break;
      uVar9 = uVar9 >> 8;
      param_3 = (uint *)((int)param_3 + 1);
    }
  }
  else {
    do {
      pcVar7 = (char *)((int)puVar6 + 1);
      uVar9 = *puVar6;
      pcVar8 = (char *)((int)param_3 + 1);
      *(char *)param_3 = (char)uVar9;
      if ((char)uVar9 == '\0') {
        return;
      }
      puVar6 = (uint *)((int)puVar6 + 2);
      cVar1 = *pcVar7;
      param_3 = (uint *)((int)param_3 + 2);
      *pcVar8 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ===== FUN_20124adc @ 20124adc (204 bytes)

int FUN_20124adc(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 0xe7;
  uStack_14 = 0;
  local_10 = 0;
  if (DAT_208f1222 != 0) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    uVar1 = be16_load(param_1 + 0x9b);
    FUN_20124a98(uVar1,*(undefined1 *)(param_1 + 0x9d),&local_30);
    FUN_2015515c(&local_30,&DAT_20124bb8);
    iVar2 = wav_delete(&local_30,&DAT_208f1234,0xff,1);
    if (iVar2 < 1) {
      FUN_20124744();
    }
    else {
      uStack_14._0_2_ = CONCAT11((char)iVar2,(undefined1)uStack_14);
      mainlink_queue_frame(&local_18,9);
      DAT_208f1222 = (short)iVar2;
    }
    return (int)(char)iVar2;
  }
  FUN_20124744(0xfffffffa);
  return -6;
}


// ===== FUN_20124bc0 @ 20124bc0 (100 bytes)

int FUN_20124bc0(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 0xe7;
  uStack_14 = 0;
  local_10 = 0;
  iVar1 = wav_list_dir(&DAT_208f1234,0xff,1);
  if (iVar1 < 1) {
    FUN_20124744();
  }
  else {
    uStack_14._0_2_ = CONCAT11((char)iVar1,(undefined1)uStack_14);
    mainlink_queue_frame(&local_18,9);
    DAT_208f1222 = (undefined2)iVar1;
  }
  return (int)(char)iVar1;
}


// ===== scr_playlist @ 20124c24 (4304 bytes)

/* packet 0x3A: voice/REC PLAY LIST */

void scr_playlist(int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bVar6;
  undefined2 *puVar7;
  short *psVar8;
  uint uVar9;
  int iVar10;
  short local_5c [2];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined1 auStack_3c [24];
  
  local_58 = fb_get_layer_addr(DAT_208085bc);
  uVar5 = 0;
  iVar10 = 0;
  bVar6 = 0;
  uVar9 = 0;
  if (1 < DAT_2080048e) {
    return;
  }
  DAT_2080048e = 1;
  DAT_20800483 = 1;
  DAT_20800484 = 1;
  switch(*(undefined1 *)(param_1 + 0x98)) {
  case 0:
    if ((*param_2 != ':') || (param_2[0x98] != '\0')) {
      FUN_20124bc0();
    }
    DAT_2080048d = 0;
    DAT_20800490 = 0;
    DAT_208004a1 = *(undefined1 *)(param_1 + 0x9b);
    DAT_208f1224 = 0;
    return;
  case 1:
    uVar2 = be16_load(param_1 + 0x9b);
    puVar7 = DAT_20800810;
    uVar5 = uVar2 & 0xffff;
    DAT_208f1226 = (undefined2)uVar2;
    bVar6 = *(byte *)(param_1 + 0x9d) & 0xf;
    DAT_208f1229 = *(byte *)(param_1 + 0x9e) & 0xf;
    DAT_208f122a = *(byte *)(param_1 + 0x9f) >> 7;
    local_54 = DAT_20800818;
    DAT_208f1228 = bVar6;
    play_stop();
    if (DAT_20800490 != '\0') {
      iVar3 = FUN_20124848(0,1);
      if (iVar3 == 0) {
        return;
      }
      DAT_2080048d = '\0';
      DAT_20800490 = '\0';
    }
    DAT_208f1224 = '\0';
    break;
  case 2:
    uVar2 = be16_load(param_1 + 0x9b);
    uVar5 = uVar2 & 0xffff;
    DAT_208f122c = (undefined2)uVar2;
    bVar6 = *(byte *)(param_1 + 0x9d);
    DAT_208f122f = *(char *)(param_1 + 0x9e);
    puVar7 = DAT_20800810;
    local_54 = DAT_20800818;
    DAT_208f122e = bVar6;
    break;
  case 3:
    FUN_20124adc(param_1);
    uVar2 = be16_load(param_1 + 0x9b);
    uVar5 = uVar2 & 0xffff;
    DAT_208f1226 = (undefined2)uVar2;
    bVar6 = *(byte *)(param_1 + 0x9d) & 0xf;
    DAT_208f1229 = *(byte *)(param_1 + 0x9e) & 0xf;
    DAT_208f122a = *(byte *)(param_1 + 0x9f) >> 7;
    local_54 = DAT_20800818;
    DAT_20800490 = '\0';
    DAT_208f1224 = '\0';
    DAT_208f122f = '\0';
    puVar7 = DAT_20800810;
    DAT_208f1228 = bVar6;
    break;
  case 4:
    uVar9 = *(byte *)(param_1 + 0x9b) & 1;
    DAT_208004a1 = *(byte *)(param_1 + 0x9c);
    local_54 = (&DAT_20800818)[uVar9];
    puVar7 = (&DAT_20800810)[uVar9];
    break;
  default:
    DAT_20800490 = 0;
    return;
  }
  iVar3 = FUN_20103ba0();
  if (iVar3 == 0) {
    DAT_20800490 = 0;
    DAT_2080048d = 0;
    play_stop();
    FUN_20124744(0xffffffff);
    return;
  }
  if ((*(char *)(param_1 + 0x98) != param_2[0x98]) || (*(char *)(param_1 + 0x98) == '\x03')) {
    if (DAT_208f462d == '\0') {
      fb_fill_rect(local_58,0x4a69,0,0,800,0x1e0);
      fb_fill_rect(local_58,0x2124,DAT_208006c6,DAT_208006c4,DAT_208006c8,DAT_208006ca);
      gui_draw_runs(local_58,DAT_208006ce,DAT_208006cc,&DAT_2016e184);
      DAT_208f462d = '\x01';
    }
    fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
    fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
    fb_fill_rect(local_58,0x821,0x7e,0x294,*puVar7,puVar7[1]);
    gui_draw_runs(local_58,0x7e,0x294,puVar7);
    gui_draw_runs(local_58,DAT_208006f2 + 0x7e,DAT_208006f0 + 0x294,local_54);
    if ((DAT_20800490 != '\x01') && (*(char *)(param_1 + 0x98) != '\x04')) {
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      sprintf(&local_50,"00:00:00");
      fb_fill_rect(local_58,0x4a69,DAT_208006da,DAT_208006d8,
                   (*(ushort *)PTR_DAT_20800b64 & 0x1fff) << 3,*(undefined2 *)(PTR_DAT_20800b64 + 2)
                  );
      gui_draw_text(local_58,&local_50,DAT_208006da,DAT_208006d8,0xf,&DAT_20800b1c);
      local_5c[0] = 0;
      FUN_201219b8(local_58,DAT_208006de,DAT_208006dc,0);
    }
    iVar10 = 1;
  }
  if (*(char *)(param_1 + 0x98) == '\x04' || *(char *)(param_1 + 0x98) == '\x02') {
    fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
    fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
    if (DAT_20800490 != '\0' || uVar9 != 0) {
LAB_201250b4:
      gui_draw_runs(local_58,DAT_208006f6,DAT_208006f4,&DAT_2016ebac);
      if (100 < DAT_208004a1) {
        DAT_208004a1 = 100;
      }
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      sprintf(&local_50,&DAT_20125360,DAT_208004a1);
      local_50 = CONCAT13(0x25,(undefined3)local_50);
      gui_draw_text(local_58,&local_50,DAT_208006fa,DAT_208006f8,0x11,&DAT_20803030);
LAB_2012512c:
      if (*(char *)(param_1 + 0x98) == '\x04') {
        fb_fill_rect(local_58,0x821,0x7e,0x294,*puVar7,puVar7[1]);
        gui_draw_runs(local_58,0x7e,0x294,puVar7);
        gui_draw_runs(local_58,DAT_208006f2 + 0x7e,DAT_208006f0 + 0x294,local_54);
      }
      goto LAB_20125194;
    }
    if (*(char *)(param_1 + 0x98) != '\x02') goto LAB_2012512c;
    if (DAT_208f122f == '\x01') goto LAB_201250b4;
LAB_201251a8:
    if (iVar10 == 0) {
      if (*(char *)(param_1 + 0x98) != '\x02') goto LAB_20125284;
      if (*(char *)(param_1 + 0x9e) != param_2[0x9e]) goto LAB_201251d0;
    }
    else {
LAB_201251d0:
      if ((*(char *)(param_1 + 0x9e) != '\x03' && *(char *)(param_1 + 0x9e) != '\x02') &&
         (param_2[0x9e] != '\x03' && param_2[0x9e] != '\x02')) {
        iVar3 = 0;
        do {
          psVar8 = &DAT_2016e1c4 + iVar3 * 5;
          fb_fill_rect(local_58,0x821,(&DAT_2016e1c6)[iVar3 * 5],*psVar8,(&DAT_2016e1c8)[iVar3 * 5],
                       (&DAT_2016e1ca)[iVar3 * 5]);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar3 * 5],*psVar8,DAT_20802290);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar3 * 5] + DAT_208006e2,*psVar8 + DAT_208006e0,
                        (&PTR_DAT_208026c8)[iVar3]);
          iVar3 = iVar3 + 1;
        } while (iVar3 < 5);
      }
      if (iVar10 == 0) {
LAB_20125284:
        if (*(char *)(param_1 + 0x98) == '\x01' || *(char *)(param_1 + 0x98) == '\x03')
        goto LAB_20125294;
      }
      else {
LAB_20125294:
        fb_fill_rect(local_58,0x4a69,DAT_208006d2,DAT_208006d0,
                     *(short *)PTR_DAT_20800b64 * 0xf + 0xf,*(undefined2 *)(PTR_DAT_20800b64 + 2));
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        FUN_20124a98(uVar5,bVar6,&local_50);
        FUN_201550dc(auStack_3c,&local_50);
        gui_draw_text(local_58,&local_50,DAT_208006d2,DAT_208006d0,0xf,&DAT_20800b1c);
        fb_fill_rect(local_58,0x4a69,DAT_208006d6,DAT_208006d4,*(short *)PTR_DAT_20800b64 * 9,
                     *(undefined2 *)(PTR_DAT_20800b64 + 2));
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        FUN_20124ab8(uVar5,bVar6,&local_50);
        gui_draw_text(local_58,&local_50,DAT_208006d6,DAT_208006d4,0xf,&DAT_20800b1c);
        iVar10 = 5;
        do {
          psVar8 = &DAT_2016e1c4 + iVar10 * 5;
          fb_fill_rect(local_58,0x821,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,
                       (&DAT_2016e1c8)[iVar10 * 5],(&DAT_2016e1ca)[iVar10 * 5]);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,&DAT_2016e194);
          iVar3 = 0;
          do {
            fb_fill_box_t(local_58,(&DAT_2080080a)[iVar3 * 2] + (&DAT_2016e1c6)[iVar10 * 5],
                          *psVar8 + (&DAT_20800808)[iVar3 * 2],(&DAT_2016e1ca)[iVar10 * 5] + -2,1,
                          0x8410);
            iVar3 = iVar3 + 1;
          } while (iVar3 < 2);
          iVar3 = ((uVar5 + iVar10) - 5 & 0xff) * 0x34;
          gui_draw_text(local_58,&DAT_208f1234 + iVar3,DAT_208006e6 + (&DAT_2016e1c6)[iVar10 * 5],
                        *psVar8 + DAT_208006e4,0xf,&DAT_20800b1c);
          gui_draw_text(local_58,&DAT_208f1244 + iVar3,DAT_208006ea + (&DAT_2016e1c6)[iVar10 * 5],
                        *psVar8 + DAT_208006e8,0xf,&DAT_20800b1c);
          gui_draw_text(local_58,&DAT_208f124f + iVar3,DAT_208006ee + (&DAT_2016e1c6)[iVar10 * 5],
                        *psVar8 + DAT_208006ec,0xf,&DAT_20800b1c);
          if (((uint)DAT_208f1228 == iVar10 - 5U) && (*(char *)(param_1 + 0x98) == '\x01')) {
            if (DAT_208f122a == 0) {
              uVar4 = 0xf980;
            }
            else {
              uVar4 = 0xffff;
            }
            fb_draw_round_frame(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,
                                (&DAT_2016e1c8)[iVar10 * 5],(&DAT_2016e1ca)[iVar10 * 5],3,uVar4);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 9);
        iVar10 = 9;
        do {
          psVar8 = &DAT_2016e1c4 + iVar10 * 5;
          fb_fill_rect(local_58,0x821,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,
                       (&DAT_2016e1c8)[iVar10 * 5],(&DAT_2016e1ca)[iVar10 * 5]);
          gui_draw_runs(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,DAT_20802290);
          gui_draw_runs(local_58,DAT_208006e2 + (&DAT_2016e1c6)[iVar10 * 5],*psVar8 + DAT_208006e0,
                        *(undefined4 *)(iVar10 * 4 + 0x208007fc));
          if ((DAT_208f122a != 0) && ((uint)DAT_208f1229 == iVar10 - 9U)) {
            FUN_20136398(local_58,(&DAT_2016e1c6)[iVar10 * 5],*psVar8,(&DAT_2016e1c8)[iVar10 * 5],
                         (&DAT_2016e1ca)[iVar10 * 5],3);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0xb);
        if ((DAT_208f122a == 0) && (DAT_208f1228 == 4)) {
          fb_draw_round_frame(local_58,0x1a2,0x2b4,0x68,0x3c,3,0xf980);
        }
      }
      if (*(char *)(param_1 + 0x98) != '\x02') goto LAB_201256d0;
    }
  }
  else {
LAB_20125194:
    cVar1 = *(char *)(param_1 + 0x98);
    if ((cVar1 == '\x01' || cVar1 == '\x02') || cVar1 == '\x03') goto LAB_201251a8;
LAB_201256d0:
    if (DAT_20800490 == '\0') goto LAB_20125cbc;
  }
  DAT_2080048c = DAT_208f122f;
  if (DAT_208f122f == DAT_2080048d) {
    if (DAT_208f122f == '\x01') {
      if ((((DAT_20800490 == '\x01') && (iVar10 = audio_state(), iVar10 != 4)) &&
          (iVar10 = audio_state(), iVar10 != 8)) &&
         ((iVar10 = audio_state(), iVar10 != 0x10 && (iVar10 = audio_state(), iVar10 != 0x20)))) {
        iVar10 = FUN_20124848(0,1);
        if (iVar10 == 0) {
          return;
        }
        fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
        gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
        gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
        fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
        fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
        DAT_20800490 = '\0';
        *(undefined1 *)(param_1 + 0x98) = 2;
        *(undefined1 *)(param_1 + 0x9e) = 0;
        DAT_2080048c = '\0';
        DAT_2080048d = '\0';
        mainlink_set_last_frame(param_1);
      }
    }
    else if (((DAT_208f122f == '\x03' || DAT_208f122f == '\x02') && (DAT_20800490 == '\x01')) &&
            (iVar10 = audio_state(), iVar10 == 0)) {
      iVar10 = FUN_20124848(0,1);
      if (iVar10 == 0) {
        return;
      }
      fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
      gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
      gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
      DAT_20800490 = '\0';
      *(undefined1 *)(param_1 + 0x9e) = 0;
      DAT_2080048c = '\0';
      DAT_2080048d = '\0';
      mainlink_set_last_frame(param_1);
    }
  }
  else {
    if (DAT_208f122f == '\x01') {
      if (DAT_20800490 == '\0') {
        FUN_20124a74(uVar5,bVar6,&local_40);
        if (local_40 != 0) {
LAB_20125a30:
          FUN_20124744(0xfffffff8);
          DAT_208f1224 = 0;
          DAT_20800490 = 0;
          DAT_2080048d = 0;
          play_stop();
          return;
        }
        iVar10 = FUN_20124848(1);
        if (iVar10 == 0) {
          return;
        }
        local_5c[0] = 0;
        play_progress(local_5c,&local_50);
        if (local_5c[0] == 0) {
          local_50 = 0;
          local_4c = 0;
          local_48 = 0;
          local_44 = 0;
          FUN_20124a98(uVar5,bVar6,&local_50);
          play_start(&local_50,1);
        }
        else {
          play_resume();
        }
        fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
        gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
        gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1a4);
        DAT_208f1224 = '\x01';
        DAT_20800490 = '\x01';
      }
      else {
        iVar10 = audio_state();
        if ((((iVar10 != 4) && (iVar10 = audio_state(), iVar10 != 8)) &&
            (iVar10 = audio_state(), iVar10 != 0x10)) && (iVar10 = audio_state(), iVar10 != 0x20)) {
          iVar10 = FUN_20124848(0,1);
          if (iVar10 == 0) {
            return;
          }
          fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
          gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
          gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
          fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
          fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
          DAT_20800490 = '\0';
          *(undefined1 *)(param_1 + 0x98) = 2;
          *(undefined1 *)(param_1 + 0x9e) = 0;
          DAT_2080048c = '\0';
          DAT_2080048d = 0;
          mainlink_set_last_frame(param_1);
        }
      }
    }
    else if (DAT_208f122f == '\0') {
      iVar10 = FUN_20124848(0,1);
      if (iVar10 == 0) {
        return;
      }
      if (DAT_20800490 != '\0') {
        play_pause();
        fb_fill_rect(local_58,0x821,0x7e,0x10e,0x68,0x3c);
        gui_draw_runs(local_58,0x7e,0x10e,DAT_20802290);
        gui_draw_runs(local_58,DAT_208006e2 + 0x7e,DAT_208006e0 + 0x10e,&DAT_2016e1b4);
        fb_fill_rect(local_58,0x4a69,DAT_208006f6,DAT_208006f4,0x7a,0x12);
        fb_fill_rect(local_58,0x4a69,DAT_208006fa,DAT_208006f8,0x44,0x18);
        DAT_20800490 = '\0';
      }
    }
    else if (DAT_208f122f == '\x03') {
      FUN_20124a74(uVar5,bVar6,&local_40);
      if (local_40 != 0) goto LAB_20125a30;
      iVar10 = FUN_20124848(1);
      if (iVar10 == 0) {
        return;
      }
      play_ffwd();
      *(undefined1 *)(param_1 + 0x9e) = 1;
      mainlink_set_last_frame(param_1);
    }
    else if (DAT_208f122f == '\x02') {
      FUN_20124a74(uVar5,bVar6,&local_40);
      if (local_40 != 0) {
        FUN_20124744(0xfffffff9);
        DAT_208f1224 = 0;
        DAT_20800490 = 0;
        DAT_2080048d = 0;
        play_stop();
        return;
      }
      iVar10 = FUN_20124848(1);
      if (iVar10 == 0) {
        return;
      }
      play_rewind();
      *(undefined1 *)(param_1 + 0x9e) = 1;
      mainlink_set_last_frame(param_1);
    }
    else {
      DAT_20800490 = '\0';
      DAT_208f1224 = '\0';
      play_stop();
    }
    DAT_2080048d = DAT_2080048c;
  }
LAB_20125cbc:
  if (DAT_208f1224 == '\0') {
    return;
  }
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  play_progress(local_5c,&local_50);
  fb_fill_rect(local_58,0x4a69,DAT_208006da,DAT_208006d8,(*(ushort *)PTR_DAT_20800b64 & 0x1fff) << 3
               ,*(undefined2 *)(PTR_DAT_20800b64 + 2));
  gui_draw_text(local_58,&local_50,DAT_208006da,DAT_208006d8,0xf,&DAT_20800b1c);
  FUN_201219b8(local_58,DAT_208006de,DAT_208006dc,local_5c[0]);
  if (local_5c[0] == 100) {
    DAT_208f1224 = '\0';
  }
  return;
}


// ===== FUN_20125d8c @ 20125d8c (232 bytes)

bool FUN_20125d8c(void)

{
  bool bVar1;
  int iVar2;
  short local_30 [4];
  undefined1 auStack_28 [20];
  
  if (((DAT_208f0b2a == 'p' && DAT_2080049e == ':') && (DAT_20800490 != '\0')) &&
     (iVar2 = FUN_20103ba0(), iVar2 == 0)) {
    DAT_2080048e = '\x01';
  }
  else {
    if (DAT_2080048e != '\x01') {
      iVar2 = audio_state();
      if (iVar2 != 8) {
        return false;
      }
      DAT_20800490 = 0;
      play_stop();
      return false;
    }
    if (DAT_208f0b2a != ':') {
      return false;
    }
    iVar2 = FUN_20103ba0();
    if (iVar2 != 0) {
      bVar1 = (DAT_208f122f == '\x01' || DAT_208f122f == '\x03') || DAT_208f122f == '\x02';
      if ((DAT_208f122f == '\x01' || DAT_208f122f == '\x03') || DAT_208f122f == '\x02') {
        return bVar1;
      }
      local_30[0] = 0;
      play_progress(local_30,auStack_28);
      if (local_30[0] != 100) {
        return bVar1;
      }
      play_stop();
      return bVar1;
    }
  }
  DAT_20800490 = 0;
  play_stop();
  FUN_20124744(0xffffffff);
  return false;
}


// ===== touch_calibration @ 20125e78 (244 bytes)

/* TOUCH THE CROSS */

void touch_calibration(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
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
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  layer_alpha_rect_opaque(5);
  fb_fill_rect(uVar1,0,0,0,800,0x1e0);
  gui_draw_runs(uVar1,*(undefined2 *)(&DAT_2016d61e + param_1 * 4),
                *(undefined2 *)(&DAT_2016d61c + param_1 * 4),&DAT_2016d60c);
  uVar2 = 0;
  do {
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
    local_24 = 0;
    FUN_201550dc(&local_50,(&DAT_20800880)[uVar2]);
    gui_draw_text_centered(uVar1,&local_50,uVar2 * 0x14 + 0x177,400,0xf,&DAT_20800b1c);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return;
}


// ===== scr_lcd_test @ 20125f6c (476 bytes)

/* packet 0x64: full-screen test colours and 8 colour bars */

void scr_lcd_test(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  layer_alpha_rect_opaque(5);
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    fb_fill_rect(uVar1,0,0,0,800,0x1e0);
    break;
  case 1:
    fb_fill_rect(uVar1,0xffff,0,0,800,0x1e0);
    return;
  case 2:
    fb_fill_rect(uVar1,0xf800,0,0,800,0x1e0);
    return;
  case 3:
    fb_fill_rect(uVar1,0x7e0,0,0,800,0x1e0);
    return;
  case 4:
    fb_fill_rect(uVar1,0x1f,0,0,800,0x1e0);
    return;
  case 5:
    fb_fill_rect(uVar1,0xffff,0,0,100,0x1e0);
    fb_fill_rect(uVar1,0xfea0,0,100,100,0x1e0);
    fb_fill_rect(uVar1,0x57d,0,200,100,0x1e0);
    fb_fill_rect(uVar1,0x7e0,0,300,100,0x1e0);
    fb_fill_rect(uVar1,0xf81f,0,400,100,0x1e0);
    fb_fill_rect(uVar1,0xf800,0,500,100,0x1e0);
    fb_fill_rect(uVar1,0x1f,0,600,100,0x1e0);
    fb_fill_rect(uVar1,0,0,700,100,0x1e0);
    return;
  }
  return;
}


// ===== FUN_20126160 @ 20126160 (12 bytes)

void FUN_20126160(undefined1 param_1)

{
  DAT_20800480 = param_1;
  return;
}


// ===== FUN_2012616c @ 2012616c (116 bytes)

void FUN_2012616c(int param_1)

{
  if (param_1 == 1) {
    FUN_20126160(1);
    DAT_208007cc = FUN_20111174(0xffffffff);
    FUN_20133d7c();
    return;
  }
  if (param_1 == 0) {
    if (DAT_208007cc == 0) {
      return;
    }
    FUN_20133da8();
  }
  else if (DAT_208007cc == 0) {
    return;
  }
  DAT_208007cc = 0;
  FUN_20133620();
  FUN_20126160(0);
  return;
}


// ===== scr_sd_menu @ 201261e0 (456 bytes)

/* packet 0x43: SD card load/save/format */

void scr_sd_menu(int param_1)

{
  byte bVar1;
  int iVar2;
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
  layer_alpha_rect_set(0,5,1,&local_28);
  layer_alpha_rect_set(1,5,1,&local_28);
  bVar1 = *(byte *)(param_1 + 1);
  if (bVar1 == 0x41) {
switchD_2012629c_caseD_43:
    if (*(char *)(param_1 + 2) == '\x01') {
LAB_20126304:
      FUN_20134984(param_1);
      return;
    }
    if ((*(char *)(param_1 + 2) == '\x10') && (iVar2 = FUN_20134990(param_1), iVar2 != 0)) {
      FUN_2013499c(param_1);
      return;
    }
  }
  else {
    if (bVar1 < 0x42) {
      switch(bVar1) {
      default:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        FUN_20134978(param_1);
        return;
      case 5:
        FUN_201349d8(param_1);
        return;
      case 8:
        FUN_201349f0(param_1);
        return;
      }
    }
    switch(bVar1) {
    case 0x42:
    case 0x44:
      bVar1 = *(byte *)(param_1 + 2);
      if (bVar1 == 3) {
        FUN_201349b4(param_1);
        return;
      }
      if (3 < bVar1) {
        if (bVar1 == 4) {
          FUN_201349c0(param_1);
          return;
        }
        if (bVar1 != 0x10) {
          return;
        }
        FUN_201349cc(param_1);
        return;
      }
      if (bVar1 != 1) {
        if (bVar1 != 2) {
          return;
        }
        FUN_201349a8(param_1);
        return;
      }
      goto LAB_20126304;
    case 0x43:
      goto switchD_2012629c_caseD_43;
    case 0x45:
      FUN_201349e4(param_1);
      return;
    case 0x48:
      if (*(char *)(param_1 + 2) == '\x01') {
        FUN_201349fc(param_1);
        return;
      }
      if (*(char *)(param_1 + 2) == '\x10') {
        FUN_20134a08(param_1);
        return;
      }
    }
  }
  return;
}


// ===== scr_info @ 201263e8 (696 bytes)

/* packet 0x34: information / CERTIFICATIONS, FCC ID K6620801X50 */

void scr_info(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  if ((*(char *)(param_1 + 0x98) == '\x01') && (*(char *)(param_1 + 0x99) != '\0')) {
    fb_fill_rect(uVar1,0x821,0,0,800,0x1e0);
    fb_fill_rect(uVar1,0x4a69,0x1e,3,0x31a,0x1c2);
    fb_fill_rect(uVar1,0x3186,3,3,0x31a,0x18);
    gui_draw_runs(uVar1,3,3,&DAT_2016dc08);
    gui_draw_text_centered(uVar1,"CERTIFICATIONS",4,400,0xf,&DAT_20800b1c);
    FUN_201363c0(uVar1,DAT_20800602,DAT_20800600,DAT_20800604,DAT_20800606,
                 *(undefined4 *)(&DAT_2016edbc + (uint)*(byte *)(param_1 + 0x99) * 4),0x19,0xc,0x821
                );
    fb_fill_rect(uVar1,0x821,DAT_208005f2,DAT_208005f0,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005f2,DAT_208005f0,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005f6,DAT_208005f4,&DAT_2016dc58);
    fb_fill_rect(uVar1,0x821,DAT_208005fa,DAT_208005f8,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005fa,DAT_208005f8,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005fe,DAT_208005fc,&DAT_2016dc68);
    fb_fill_rect(uVar1,0x821,0x1a0,0x247,*DAT_20802290,DAT_20802290[1]);
    gui_draw_runs(uVar1,0x1a0,0x247,DAT_20802290);
    gui_draw_runs(uVar1,0x1b7,0x250,&DAT_2016edb0);
    FUN_20136398(uVar1,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
    fb_fill_box(uVar1,400,10,0x2b2,1,0x821);
    sVar5 = 10;
    iVar4 = 0;
    do {
      sVar5 = sVar5 + 0x1e;
      uVar3 = 0x23;
      iVar2 = *(int *)(&DAT_2016edbc + (uint)*(byte *)(param_1 + 0x99) * 4) + iVar4;
      if (iVar2 == 0 || iVar2 == 0xf) {
        uVar3 = 0x14;
      }
      gui_draw_text_words(uVar1,"FCC ID : K6620801X50" + iVar2 * 0x31,sVar5,uVar3,0x10,&DAT_20803030
                         );
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xc);
  }
  return;
}


// ===== gui_apply_display_cfg @ 201266ec (304 bytes)

/* packet 0x24: DVI on/off, DVI resolution, LCD contrast */

void gui_apply_display_cfg(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  undefined4 local_2c;
  char local_28;
  char local_27;
  char local_26;
  undefined2 local_24 [2];
  undefined2 local_20 [2];
  undefined1 local_1c;
  
  if ((param_3 != 0) || ((*param_1 & 3) != (*param_2 & 3))) {
    bVar2 = *param_2;
    uVar4 = *param_1 & 1;
    uVar1 = (*param_1 & 3) >> 1;
    if (((param_3 != 0 || uVar4 != (bVar2 & 1)) && (lvds_pins_enable(uVar4), param_3 != 0)) ||
       (uVar1 != (bVar2 & 3) >> 1)) {
      local_1c = dvi_set_resolution(uVar1);
      iVar3 = mouse_cursor_visible();
      if (iVar3 != 0) {
        mouse_cursor_get_pos(local_24,local_20);
        layer_show(6);
        mouse_cursor_set_pos(local_24[0],local_20[0]);
        FUN_201218a4();
      }
      if (param_3 != 0) goto LAB_201267bc;
    }
  }
  if ((param_1[5] & 0x1f) == (param_2[5] & 0x1f)) {
    return;
  }
LAB_201267bc:
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  bVar2 = param_1[5] & 0x1f;
  if (0x14 < bVar2) {
    bVar2 = 0x14;
  }
  local_28 = bVar2 * '\n' + '\x1c';
  local_26 = bVar2 * '\n' + '\x11';
  local_30 = &local_28;
  local_27 = local_28;
  r_vdc5_display_calibration(0,&local_38);
  return;
}


// ===== FUN_2012681c @ 2012681c (248 bytes)

void FUN_2012681c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  fb_fill_box_t(param_1,param_2 + 1U & 0xffff,param_3,
                *(short *)((&PTR_DAT_208022a0)[param_4] + 2) + -2,2,0xf980);
  fb_fill_box_t(param_1,param_2 + 1U & 0xffff,
                (uint)*(ushort *)(&PTR_DAT_208022a0)[param_4] + param_3 + -2 & 0xffff,
                *(ushort *)((int)(&PTR_DAT_208022a0)[param_4] + 2) - 2,2,0xf980);
  fb_fill_box(param_1,param_2,param_3 + 1U & 0xffff,*(short *)(&PTR_DAT_208022a0)[param_4] + -2,2,
              0xf980);
  fb_fill_box(param_1,(uint)*(ushort *)((int)(&PTR_DAT_208022a0)[param_4] + 2) + param_2 + -2 &
                      0xffff,param_3 + 1U & 0xffff,*(short *)(&PTR_DAT_208022a0)[param_4] + -2,2,
              0xf980);
  gui_draw_runs(param_1,param_2,param_3,(&PTR_DAT_208022a0)[param_4]);
  return;
}


// ===== FUN_20126914 @ 20126914 (324 bytes)

void FUN_20126914(undefined4 param_1,int param_2,int param_3,int param_4)

{
  fb_fill_rect(param_1,0x4a69,param_2 + 2U & 0xffff,param_3 + 2U & 0xffff,
               **(short **)(&DAT_2080228c + param_4 * 4) + -4,
               (*(short **)(&DAT_2080228c + param_4 * 4))[1] + -4);
  fb_fill_box_t(param_1,param_2 + 1U & 0xffff,param_3,
                *(short *)(*(int *)(&DAT_2080228c + param_4 * 4) + 2) + -2,2,0x821);
  fb_fill_box_t(param_1,param_2 + 1U & 0xffff,
                (uint)**(ushort **)(&DAT_2080228c + param_4 * 4) + param_3 + -2 & 0xffff,
                *(short *)((&PTR_DAT_208022a0)[param_4] + 2) + -2,2,0x821);
  fb_fill_box(param_1,param_2,param_3 + 1U & 0xffff,**(short **)(&DAT_2080228c + param_4 * 4) + -2,2
              ,0x821);
  fb_fill_box(param_1,(uint)*(ushort *)(*(int *)(&DAT_2080228c + param_4 * 4) + 2) + param_2 + -2 &
                      0xffff,param_3 + 1U & 0xffff,*(short *)(&PTR_DAT_208022a0)[param_4] + -2,2,
              0x821);
  gui_draw_runs(param_1,param_2,param_3,*(undefined4 *)(&DAT_2080228c + param_4 * 4));
  return;
}


// ===== FUN_20126a58 @ 20126a58 (1084 bytes)

void FUN_20126a58(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined **ppuVar6;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  uint local_28;
  
  iStack_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  local_28 = param_4;
  local_3c = fb_get_layer_addr(DAT_208085bc);
  iVar3 = 0;
  if (param_3 < 3) {
    puVar4 = (ushort *)(&PTR_DAT_208022c0)[param_2];
  }
  else {
    puVar4 = (ushort *)(&PTR_DAT_208022d0)[param_2];
  }
  local_38 = (uint)(param_3 >= 3);
  if (((uint)puVar4[1] + param_6 < 0x1e1) && ((uint)*puVar4 + param_5 < 0x321)) {
    if (param_1 != 0) {
      fb_draw_frame(local_3c,0xf980,param_6,param_5,(uint)*puVar4,(uint)puVar4[1],2);
      fb_fill_rect(local_3c,0x821,param_6 + 2U & 0xffff,param_5 + 2U & 0xffff,*puVar4 - 4,
                   puVar4[1] - 4);
      iVar1 = 0;
      if ((&DAT_2016d28c)[param_2] != '\0') {
        do {
          if (param_2 == 3) {
            if (param_3 < 3) {
              if (param_3 < 2) {
                iVar3 = 0;
              }
            }
            else {
              iVar3 = 2;
            }
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            memcpy(&local_54,param_7 + iVar1 * 0x16,0x16);
            str_rtrim(&local_54);
            gui_draw_text_centered
                      (local_3c,&local_54,
                       (uint)(ushort)(&DAT_2016dcca)[iVar3 * 2] + param_6 & 0xffff,
                       (uint)(ushort)(&DAT_2016dcc8)[iVar3 * 2] + param_5 & 0xffff,
                       **(undefined2 **)(DAT_208022ec + 0x48),DAT_208022ec);
          }
          else if (param_2 == 1) {
            if (param_3 < 3) {
              if (param_3 == 1) {
                iVar3 = 0;
              }
            }
            else {
              iVar3 = 1;
            }
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            memcpy(&local_54,param_7 + iVar1 * 0x16,0x16);
            str_rtrim(&local_54);
            gui_draw_text_centered
                      (local_3c,&local_54,
                       (uint)(ushort)(&DAT_2016dcca)[iVar3 * 2] + param_6 + iVar1 * 0x28 & 0xffff,
                       (uint)(ushort)(&DAT_2016dcc8)[iVar3 * 2] + param_5 & 0xffff,
                       **(undefined2 **)(DAT_208022e4 + 0x48),DAT_208022e4);
          }
          else {
            iVar3 = 0;
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            if (param_2 == 0) {
              FUN_20155310(&local_54,&DAT_20126eb8,0x16);
              str_rtrim(&local_54);
              gui_draw_text_centered
                        (local_3c,&local_54,param_6 + iVar1 * 0x28 + 0x14U & 0xffff,
                         param_5 + 0xaaU & 0xffff,**(undefined2 **)(DAT_208022e0 + 0x48),
                         DAT_208022e0);
            }
            else {
              memcpy(&local_54,param_7 + iVar1 * 0x16,0x16);
              str_rtrim(&local_54);
              gui_draw_text_centered
                        (local_3c,&local_54,param_6 + iVar1 * 0x28 + 0x14U & 0xffff,
                         param_5 + 0xaaU & 0xffff,**(undefined2 **)((&DAT_208022e0)[param_2] + 0x48)
                         ,(&DAT_208022e0)[param_2]);
            }
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)(uint)(byte)(&DAT_2016d28c)[param_2]);
      }
    }
    if (local_38 == 0) {
      uVar2 = 0;
      uVar5 = (((uint)puVar4[1] + param_6) -
              (uint)*(ushort *)
                     (*(int *)(&DAT_2080228c + (uint)(byte)(&DAT_20800654)[param_3] * 4) + 2)) -
              0x14 & 0xffff;
      if ((&DAT_20800650)[param_3] != '\0') {
        ppuVar6 = &PTR_DAT_208022f0 + param_3 * 2;
        do {
          puVar4 = (ushort *)(&DAT_2016dcd4 + uVar2 * 4 + param_3 * 8);
          FUN_20126914(local_3c,uVar5,(uint)*puVar4 + param_5 & 0xffff,(&DAT_20800654)[param_3]);
          gui_draw_runs(local_3c,*(ushort *)(&DAT_2016dcf6 + param_3 * 4) + uVar5 & 0xffff,
                        (uint)*puVar4 + (uint)*(ushort *)(&DAT_2016dcf4 + param_3 * 4) + param_5 &
                        0xffff,ppuVar6[uVar2]);
          if (uVar2 == local_28) {
            FUN_2012681c(local_3c,uVar5,(uint)*puVar4 + param_5 & 0xffff,(&DAT_20800654)[param_3]);
          }
          uVar2 = uVar2 + 1 & 0xff;
        } while (uVar2 < (byte)(&DAT_20800650)[param_3]);
      }
    }
  }
  return;
}


// ===== scr_confirm @ 20126ebc (108 bytes)

/* packet 0x70: OK / CANCEL dialog */

void scr_confirm(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  byte bVar4;
  byte bVar5;
  
  bVar5 = *(byte *)(param_1 + 0x98);
  bVar4 = *(byte *)(param_1 + 0x99);
  uVar1 = *(undefined1 *)(param_1 + 0x9a);
  if (3 < bVar5) {
    bVar5 = 3;
  }
  if (3 < bVar4) {
    bVar4 = 3;
  }
  uVar2 = be16_load(param_1 + 0x9c);
  uVar3 = be16_load(param_1 + 0x9e);
  FUN_20126a58(param_2,bVar5,bVar4,uVar1,uVar2,uVar3,param_1 + 0xa0);
  return;
}


// ===== scr_setup_menu @ 20126f28 (676 bytes)

/* packet 0x62: MENU list, 8 rows of {5, 20, 3} chars */

void scr_setup_menu(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  short *local_50;
  undefined2 *local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  short local_38;
  short local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_54 = fb_get_layer_addr(DAT_208085bc);
  if (param_3 != 0) {
    local_34 = 0;
    local_38 = DAT_208004a4;
    local_44 = 0;
    local_42 = 0;
    local_36 = 0x1e0 - DAT_208004a4;
    local_50 = &local_38;
    local_41 = 0xff;
    local_4c = &local_44;
    local_32 = 800;
    local_40 = 0;
    local_48 = 0;
    layer_alpha_rect_set(0,5,1,&local_50);
    layer_alpha_rect_set(1,5,1,&local_50);
    fb_fill_rect(local_54,0x821,DAT_208004a4,0,800,0x1e0 - DAT_208004a4);
    iVar1 = 0;
    do {
      fb_fill_box(local_54,iVar1 * (uint)DAT_208004a6 + (uint)DAT_208004ee & 0xffff,DAT_208004ec,
                  DAT_208004f0,DAT_208004f2,0x8410);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
  }
  uVar2 = 0;
  do {
    if (((param_3 != 0) || (*(char *)(param_1 + 0x98) != *(char *)(param_2 + 0x98))) ||
       (iVar1 = FUN_2015507c(param_1 + uVar2 * 0x1c + 0x9a,param_2 + uVar2 * 0x1c + 0x9a,0x1c),
       iVar1 != 0)) {
      local_30 = 0;
      local_2c = 0;
      local_70 = 0;
      local_6c = 0;
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      iVar1 = param_1 + uVar2 * 0x1c;
      FUN_2014e2e4(&local_30,iVar1 + 0x9a,5);
      FUN_2014e2e4(&local_70,iVar1 + 0x9f,0x14);
      FUN_2014e2e4(&local_58,iVar1 + 0xb3,3);
      fb_fill_rect(local_54,0x821,uVar2 * DAT_208004a6 + (uint)DAT_208004e2 & 0xffff,0,800,0x18);
      if (*(byte *)(param_1 + 0x98) == uVar2) {
        gui_draw_runs(local_54,uVar2 * DAT_208004a6 + (uint)DAT_208004de & 0xffff,DAT_208004dc,
                      &DAT_2016d310);
      }
      gui_draw_text(local_54,&local_30,uVar2 * DAT_208004a6 + (uint)DAT_208004e2 & 0xffff,
                    DAT_208004e0,0xf,&DAT_20800cac);
      gui_draw_text(local_54,&local_70,uVar2 * DAT_208004a6 + (uint)DAT_208004e6 & 0xffff,
                    DAT_208004e4,0xf,&DAT_20800cac);
      gui_draw_text(local_54,&local_58,uVar2 * DAT_208004a6 + (uint)DAT_208004ea & 0xffff,
                    DAT_208004e8,0xf,&DAT_20800cac);
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 9);
  return;
}


// ===== FUN_201271cc @ 201271cc (904 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_201271cc(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  ushort *puVar6;
  short *psVar7;
  int iVar8;
  short sVar9;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  puVar5 = (undefined *)0x0;
  iVar8 = 0;
  DAT_20800465 = (undefined1)param_1;
  param_1 = param_1 * 0x2f;
  do {
    puVar6 = &DAT_20801fb6 + iVar8 * 5;
    sVar9 = (&DAT_20801fba)[iVar8 * 5];
    if (sVar9 == 0x102) {
      psVar7 = (short *)&UNK_2016d93c;
    }
    else if (sVar9 == 0x7e) {
      psVar7 = (short *)&UNK_2016d92c;
    }
    else if (sVar9 == 0x66) {
      psVar7 = &DAT_2016d90c;
    }
    else {
      psVar7 = &DAT_2016d94c;
    }
    uVar3 = (uint)(byte)(&DAT_20801d53)[iVar8 + param_1];
    if (uVar3 == 0xe2) {
      psVar7 = (short *)&UNK_2016d91c;
    }
    else if ((uVar3 == 0xe3 || uVar3 == 0xec) || uVar3 == 0xed) {
      psVar7 = &DAT_2016d90c;
    }
    sVar9 = 0;
    if (uVar3 == 0xe7) {
      psVar7 = &DAT_2016d90c;
      uVar4 = (uint)DAT_2080057c;
      puVar5 = &UNK_2016d9bc;
      uVar3 = (uint)DAT_2080057e;
      goto LAB_201273f8;
    }
    if (uVar3 < 0xe8) {
      if (uVar3 == 0xe3) {
        uVar4 = (uint)DAT_20800580;
        puVar5 = &UNK_2016d98c;
        uVar3 = (uint)DAT_20800582;
      }
      else if (uVar3 < 0xe4) {
        uVar4 = 0;
        if (uVar3 == 0) goto LAB_20127424;
        if (uVar3 == 0xe1) {
          puVar5 = &DAT_2016d97c;
          uVar4 = (uint)DAT_20800578;
          uVar3 = (uint)DAT_2080057a;
        }
        else {
          if (uVar3 != 0xe2) goto switchD_201272d0_default;
          uVar4 = (uint)DAT_20800580;
          puVar5 = &UNK_2016d99c;
          uVar3 = (uint)DAT_20800582;
        }
      }
      else if (uVar3 == 0xe4) {
        puVar5 = &DAT_2016d96c;
        uVar4 = (uint)DAT_2080057c;
        uVar3 = (uint)DAT_2080057e;
      }
      else if (uVar3 == 0xe5) {
        uVar4 = (uint)DAT_20800584;
        puVar5 = &UNK_2016d9fc;
        uVar3 = (uint)DAT_20800586;
      }
      else {
        if (uVar3 != 0xe6) goto switchD_201272d0_default;
        puVar5 = &DAT_2016d9cc;
        uVar4 = (uint)DAT_2080057c;
        uVar3 = (uint)DAT_2080057e;
      }
      goto LAB_201273f8;
    }
    switch(uVar3) {
    case 0xe8:
    case 0xe9:
      uVar4 = (uint)DAT_20800570;
      uVar3 = (uint)DAT_20800572;
      break;
    case 0xea:
      uVar4 = (uint)DAT_20800588;
      puVar5 = &UNK_2016d9dc;
      uVar3 = (uint)DAT_2080058a;
      break;
    case 0xeb:
      uVar4 = (uint)DAT_20800588;
      puVar5 = &UNK_2016d9ec;
      uVar3 = (uint)DAT_2080058a;
      break;
    case 0xec:
      puVar5 = &UNK_2016d95c;
      uVar4 = (uint)DAT_20800574;
      uVar3 = (uint)DAT_20800576;
      break;
    case 0xed:
      puVar5 = &UNK_2016d9ac;
      uVar4 = (uint)DAT_20800574;
      uVar3 = (uint)DAT_20800576;
      break;
    default:
switchD_201272d0_default:
      puVar5 = *(undefined **)(&DAT_208012b8 + (uint)(byte)(&DAT_2080173c)[uVar3] * 4);
      uVar4 = _DAT_2080056c;
      goto LAB_20127424;
    }
LAB_201273f8:
    uVar4 = uVar4 | uVar3 << 0x10;
LAB_20127424:
    if ((iVar8 == 0x20) && ((&DAT_20801d73)[param_1] != -0x1e && (&DAT_20801d73)[param_1] != -0x1d))
    {
      sVar9 = 0x24;
      psVar7 = &DAT_2016d94c;
      uVar4 = uVar4 & 0xffff0000 | uVar4 + 0x24 & 0xffff;
    }
    fb_fill_rect(uVar2,0x821,(&DAT_20801fb8)[iVar8 * 5] + 1,*puVar6 + sVar9 + 1,*psVar7 + -2,
                 psVar7[1] + -2);
    gui_draw_runs(uVar2,(&DAT_20801fb8)[iVar8 * 5],*puVar6 + sVar9,psVar7);
    cVar1 = (&DAT_20801d53)[iVar8 + param_1];
    if (cVar1 == -0x18) {
      gui_draw_text_words(uVar2,&DAT_201275e0,
                          (uint)(ushort)(&DAT_20801fb8)[iVar8 * 5] + (uVar4 >> 0x10) & 0xffff,
                          *puVar6 + uVar4 & 0xffff,0x18,&DAT_208012b8);
    }
    else if (cVar1 == -0x17) {
      gui_draw_text_words(uVar2,&DAT_201275e4,
                          (uint)(ushort)(&DAT_20801fb8)[iVar8 * 5] + (uVar4 >> 0x10) & 0xffff,
                          *puVar6 + uVar4 & 0xffff,0x18,&DAT_208012b8);
    }
    else if (cVar1 != '\0') {
      gui_draw_runs(uVar2,(uint)(ushort)(&DAT_20801fb8)[iVar8 * 5] + (uVar4 >> 0x10) & 0xffff,
                    *puVar6 + uVar4 & 0xffff,puVar5);
    }
    iVar8 = iVar8 + 1;
    if (0x2e < iVar8) {
      return;
    }
  } while( true );
}


// ===== scr_keyboard @ 201275e8 (1340 bytes)

/* packet 0x50: on-screen keyboard (Caps, Space, ENT, ABC, #%^) */

void scr_keyboard(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte local_a8 [96];
  undefined4 local_48;
  undefined2 *local_44;
  undefined2 *local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  
  local_48 = fb_get_layer_addr(DAT_208085bc);
  iVar7 = 0;
  bVar2 = *(byte *)(param_1 + 0x98);
  uVar3 = bVar2 & 0xf;
  uVar8 = *(byte *)(param_1 + 0x99) & 0x3f;
  uVar6 = *(byte *)(param_2 + 0x99) & 0x3f;
  local_28 = 0x28;
  DAT_20800464 = (&DAT_20801d44)[uVar3 % 3 + ((uint)(bVar2 >> 4) % 5) * 3];
  uVar4 = (uint)DAT_20800464;
  memcpy(&DAT_20801fb6,(&PTR_DAT_20802198)[uVar4],0x1e0,uVar3 * -0x55555555);
  if ((param_3 == 0) && ((uint)*(byte *)(param_2 + 0x98) == (uint)bVar2)) {
    memcpy(local_a8,param_2 + 0xc2,0x32);
    memcpy(local_a8 + 0x34,param_2 + 0x9a,local_28);
  }
  else {
    FUN_20107d8c(uVar4);
    local_30 = 0;
    local_44 = &local_30;
    local_38 = 0;
    local_2e = 0x1e0;
    local_36 = 0;
    local_2c = 0;
    local_35 = 0xff;
    local_40 = &local_38;
    local_2a = 800;
    local_34 = 0;
    local_3c = 0;
    layer_alpha_rect_set(0,5,1,&local_44);
    layer_alpha_rect_set(1,5,1,&local_44);
    fb_clear_rect(local_48,0,0,800,0x1e0);
    fb_fill_rect(local_48,0x821,0,0,800,0x1e0);
    fb_fill_rect(local_48,0x4a69,DAT_20800546,DAT_20800544,DAT_20800548,DAT_2080054a);
    fb_fill_rect(local_48,0x821,DAT_20800562,DAT_20800560,DAT_20800564,DAT_20800566);
    FUN_201271cc(DAT_20800464);
    memclr(local_a8,0x32);
    memclr(local_a8 + 0x34,local_28);
  }
  iVar5 = 0;
  do {
    if (uVar8 != uVar6) {
      uVar3 = (uint)DAT_2080055c + uVar6 * 0xf & 0xffff;
      bVar2 = *(byte *)(param_1 + uVar6 + 0xc2);
      fb_fill_rect(local_48,0x821,DAT_2080055e,uVar3,0xf,0x18);
      gui_draw_runs(local_48,DAT_2080055e,uVar3,
                    *(undefined4 *)(&DAT_20800cac + (uint)(byte)(&DAT_2080173c)[bVar2] * 4));
      uVar6 = uVar8;
    }
    uVar3 = (uint)*(byte *)(param_1 + iVar5 + 0xc2);
    if (local_a8[iVar5] != uVar3) {
      fb_fill_rect(local_48,0x821,DAT_2080055e,(uint)DAT_2080055c + iVar5 * 0xf & 0xffff,0xf,0x18);
      gui_draw_runs(local_48,DAT_2080055e,(uint)DAT_2080055c + iVar5 * 0xf & 0xffff,
                    *(undefined4 *)(&DAT_20800cac + (uint)(byte)(&DAT_2080173c)[uVar3] * 4));
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x32);
  fb_fill_rect(local_48,0xffff,DAT_2080055e,(uint)DAT_2080055c + uVar8 * 0xf + 1 & 0xffff,
               DAT_20800568,DAT_2080056a);
  iVar5 = FUN_2015507c(param_1 + 0x9a,local_a8 + 0x34,local_28);
  if (iVar5 != 0) {
    fb_fill_rect(local_48,0x821,DAT_2080054e,DAT_2080054c,DAT_20800548,0x1e0 - DAT_2080054a);
    local_a8[0] = 0;
    local_a8[1] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[10] = 0;
    local_a8[0xb] = 0;
    local_a8[0xc] = 0;
    local_a8[0xd] = 0;
    local_a8[0xe] = 0;
    local_a8[0xf] = 0;
    local_a8[0x10] = 0;
    local_a8[0x11] = 0;
    local_a8[0x12] = 0;
    local_a8[0x13] = 0;
    local_a8[0x14] = 0;
    local_a8[0x15] = 0;
    local_a8[0x16] = 0;
    local_a8[0x17] = 0;
    local_a8[0x18] = 0;
    local_a8[0x19] = 0;
    local_a8[0x1a] = 0;
    local_a8[0x1b] = 0;
    local_a8[0x1c] = 0;
    local_a8[0x1d] = 0;
    local_a8[0x1e] = 0;
    local_a8[0x1f] = 0;
    local_a8[0x20] = 0;
    local_a8[0x21] = 0;
    local_a8[0x22] = 0;
    local_a8[0x23] = 0;
    local_a8[0x24] = 0;
    local_a8[0x25] = 0;
    local_a8[0x26] = 0;
    local_a8[0x27] = 0;
    local_a8[0x28] = 0;
    local_a8[0x29] = 0;
    local_a8[0x2a] = 0;
    local_a8[0x2b] = 0;
    local_a8[0x2c] = 0;
    local_a8[0x2d] = 0;
    local_a8[0x2e] = 0;
    local_a8[0x2f] = 0;
    local_a8[0x30] = 0;
    local_a8[0x31] = 0;
    local_a8[0x32] = 0;
    local_a8[0x33] = 0;
    memcpy(local_a8,param_1 + 0xa4,0x14);
    uVar6 = 0;
    iVar5 = FUN_20155122(local_a8);
    if (iVar5 != 0) {
      do {
        pbVar1 = local_a8 + uVar6;
        uVar6 = uVar6 + 1;
        if (*pbVar1 == 0x20) {
          iVar7 = iVar7 + 1;
        }
        uVar3 = FUN_20155122(local_a8);
      } while (uVar6 < uVar3);
    }
    iVar5 = FUN_20155122(local_a8);
    uVar3 = 0;
    uVar6 = (uint)DAT_20800554 - ((iVar5 * 0xf + iVar7 * -7 & 0xffffU) >> 1);
    iVar7 = FUN_20155122(local_a8);
    if (iVar7 != 0) {
      do {
        uVar6 = uVar6 & 0xffff;
        if (local_a8[uVar3] == 0x20) {
          uVar6 = uVar6 + 8;
        }
        else {
          gui_draw_runs(local_48,DAT_20800556,uVar6,
                        *(undefined4 *)
                         (&DAT_20800cac + (uint)(byte)(&DAT_2080173c)[local_a8[uVar3]] * 4));
          uVar6 = uVar6 + 0xf;
        }
        uVar3 = uVar3 + 1;
        uVar4 = FUN_20155122(local_a8);
      } while (uVar3 < uVar4);
    }
    local_a8[0] = 0;
    local_a8[1] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[10] = 0;
    local_a8[0xb] = 0;
    local_a8[0xc] = 0;
    local_a8[0xd] = 0;
    local_a8[0xe] = 0;
    local_a8[0xf] = 0;
    local_a8[0x10] = 0;
    local_a8[0x11] = 0;
    local_a8[0x12] = 0;
    local_a8[0x13] = 0;
    local_a8[0x14] = 0;
    local_a8[0x15] = 0;
    local_a8[0x16] = 0;
    local_a8[0x17] = 0;
    local_a8[0x18] = 0;
    local_a8[0x19] = 0;
    local_a8[0x1a] = 0;
    local_a8[0x1b] = 0;
    local_a8[0x1c] = 0;
    local_a8[0x1d] = 0;
    local_a8[0x1e] = 0;
    local_a8[0x1f] = 0;
    local_a8[0x20] = 0;
    local_a8[0x21] = 0;
    local_a8[0x22] = 0;
    local_a8[0x23] = 0;
    local_a8[0x24] = 0;
    local_a8[0x25] = 0;
    local_a8[0x26] = 0;
    local_a8[0x27] = 0;
    local_a8[0x28] = 0;
    local_a8[0x29] = 0;
    local_a8[0x2a] = 0;
    local_a8[0x2b] = 0;
    local_a8[0x2c] = 0;
    local_a8[0x2d] = 0;
    local_a8[0x2e] = 0;
    local_a8[0x2f] = 0;
    local_a8[0x30] = 0;
    local_a8[0x31] = 0;
    local_a8[0x32] = 0;
    local_a8[0x33] = 0;
    memcpy(local_a8,param_1 + 0x9a,10);
    gui_draw_text_words(local_48,local_a8,DAT_20800552,DAT_20800550,0xf,&DAT_20800cac);
    local_a8[0] = 0;
    local_a8[1] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[10] = 0;
    local_a8[0xb] = 0;
    local_a8[0xc] = 0;
    local_a8[0xd] = 0;
    local_a8[0xe] = 0;
    local_a8[0xf] = 0;
    local_a8[0x10] = 0;
    local_a8[0x11] = 0;
    local_a8[0x12] = 0;
    local_a8[0x13] = 0;
    local_a8[0x14] = 0;
    local_a8[0x15] = 0;
    local_a8[0x16] = 0;
    local_a8[0x17] = 0;
    local_a8[0x18] = 0;
    local_a8[0x19] = 0;
    local_a8[0x1a] = 0;
    local_a8[0x1b] = 0;
    local_a8[0x1c] = 0;
    local_a8[0x1d] = 0;
    local_a8[0x1e] = 0;
    local_a8[0x1f] = 0;
    local_a8[0x20] = 0;
    local_a8[0x21] = 0;
    local_a8[0x22] = 0;
    local_a8[0x23] = 0;
    local_a8[0x24] = 0;
    local_a8[0x25] = 0;
    local_a8[0x26] = 0;
    local_a8[0x27] = 0;
    local_a8[0x28] = 0;
    local_a8[0x29] = 0;
    local_a8[0x2a] = 0;
    local_a8[0x2b] = 0;
    local_a8[0x2c] = 0;
    local_a8[0x2d] = 0;
    local_a8[0x2e] = 0;
    local_a8[0x2f] = 0;
    local_a8[0x30] = 0;
    local_a8[0x31] = 0;
    local_a8[0x32] = 0;
    local_a8[0x33] = 0;
    memcpy(local_a8,param_1 + 0xb8,10);
    gui_draw_text_words(local_48,local_a8,DAT_2080055a,DAT_20800558,0xf,&DAT_20800cac);
  }
  return;
}


// ===== scr_memory_list @ 20127b24 (1516 bytes)

/* packet 0x41: MEMORY CH LIST */

void scr_memory_list(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  iVar7 = (uint)*(byte *)(param_1 + 0x98) << 0x19;
  local_2c = (uint)(*(byte *)(param_1 + 0x99) >> 4);
  local_30 = *(byte *)(param_1 + 0x99) & 0xf;
  if (param_2 != 0) {
    if ((*(byte *)(param_1 + 5) & 0x20) == 0) {
      iVar3 = 0xb4;
    }
    else {
      iVar3 = 0x6d;
    }
    fb_fill_rect(uVar1,0x821,iVar3,0,800,0x1e0 - iVar3);
    fb_fill_rect(uVar1,0x4a69,DAT_2080058e,DAT_2080058c,DAT_20800590,DAT_20800592);
  }
  fb_fill_rect(uVar1,0x2124,DAT_20800596,DAT_20800594,DAT_20800598,DAT_2080059a);
  gui_draw_runs(uVar1,DAT_20800702,DAT_20800700,&DAT_2016dae8);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  FUN_201636cc(&local_40,param_1 + 0xab);
  gui_draw_text(uVar1,&local_40,DAT_2080059e,DAT_2080059c,0xf,&DAT_2080099c);
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_40 = *(undefined4 *)(param_1 + 0xb0);
  gui_draw_text(uVar1,&local_40,DAT_208005a2,DAT_208005a0,0xe,&DAT_2080099c);
  uVar5 = 0;
  do {
    psVar4 = &DAT_2016db98 + uVar5 * 5;
    fb_fill_rect(uVar1,0x821,(&DAT_2016db9a)[uVar5 * 5],*psVar4,0x239,0x3c);
    gui_draw_runs(uVar1,(&DAT_2016db9a)[uVar5 * 5],*psVar4,&DAT_2016d5fc);
    iVar3 = 0;
    do {
      fb_fill_box_t(uVar1,(&DAT_20802282)[iVar3 * 2] + (&DAT_2016db9a)[uVar5 * 5],
                    *psVar4 + (&DAT_20802280)[iVar3 * 2],0x3a,1,0x8410);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    if (uVar5 == local_30) {
      if (iVar7 < 0) {
        uVar2 = 0xffff;
      }
      else {
        uVar2 = 0xf980;
      }
      fb_draw_round_frame(uVar1,(&DAT_2016db9a)[uVar5 * 5],*psVar4,0x239,0x3c,3,uVar2);
    }
    iVar3 = param_1 + uVar5 * 0x24;
    if ((*(byte *)(iVar3 + 0xb5) & 2) != 0) {
      gui_draw_runs(uVar1,DAT_208005b2 + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005b0,
                    &DAT_2016daf8);
    }
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    FUN_201636cc(&local_40,iVar3 + 0xb6);
    gui_draw_text(uVar1,&local_40,DAT_208005b6 + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005b4,
                  0xf,&DAT_20800b1c);
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    memcpy(&local_40,iVar3 + 0xbb,10);
    gui_draw_text(uVar1,&local_40,DAT_208005ba + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005b8,
                  0xf,&DAT_20800b1c);
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    memcpy(&local_40,iVar3 + 0xc5,7);
    gui_draw_text(uVar1,&local_40,DAT_208005be + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005bc,
                  0xf,&DAT_20800b1c);
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    if ((*(byte *)(iVar3 + 0xb5) & 1) == 0) {
      puVar9 = &DAT_20801134;
    }
    else {
      puVar9 = &DAT_20800cac;
    }
    local_34 = 0;
    memcpy(&local_40,iVar3 + 0xcd,0xc);
    gui_draw_text(uVar1,&local_40,DAT_208005c2 + (&DAT_2016db9a)[uVar5 * 5],*psVar4 + DAT_208005c0,
                  0xf,puVar9);
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 4);
  iVar3 = 4;
  iVar8 = local_2c + 4;
  do {
    puVar6 = &DAT_2016db98 + iVar3 * 5;
    fb_fill_rect(uVar1,0x821,(&DAT_2016db9a)[iVar3 * 5],*puVar6,*DAT_20802290,DAT_20802290[1]);
    gui_draw_runs(uVar1,(&DAT_2016db9a)[iVar3 * 5],*puVar6,DAT_20802290);
    if ((iVar7 < 0) && (iVar3 == iVar8)) {
      FUN_20136398(uVar1,(&DAT_2016db9a)[iVar3 * 5],*puVar6,
                   *(undefined2 *)(&UNK_2016db9c + iVar3 * 10),
                   *(undefined2 *)(&UNK_2016db9e + iVar3 * 10),3);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  gui_draw_runs(uVar1,DAT_208005a6 + 0xd3,DAT_208005a4 + 0x244,&DAT_2016db48);
  gui_draw_runs(uVar1,DAT_208005a6 + 0xd3,DAT_208005a4 + 0x2b4,&DAT_2016db38);
  gui_draw_runs(uVar1,DAT_208005aa + 0x118,DAT_208005a8 + 0x244,&DAT_2016db68);
  gui_draw_runs(uVar1,DAT_208005ae + 0x118,DAT_208005ac + 0x244,&DAT_2016db28);
  gui_draw_runs(uVar1,DAT_208005aa + 0x118,DAT_208005a8 + 0x2b4,&DAT_2016db08);
  gui_draw_runs(uVar1,DAT_208005ae + 0x118,DAT_208005ac + 0x2b4,&DAT_2016db78);
  if ((*(byte *)(param_1 + 0x98) & 0x80) == 0) {
    gui_draw_runs(uVar1,DAT_208005a6 + 0x15d,DAT_208005a4 + 0x2b4,&DAT_2016db18);
  }
  else {
    gui_draw_runs(uVar1,DAT_208005a6 + 0x15d,DAT_208005a4 + 0x2b4,&DAT_2016db58);
  }
  gui_draw_runs(uVar1,DAT_208005a6 + 0x1a2,DAT_208005a4 + 0x2b4,&DAT_2016db88);
  return;
}


// ===== FUN_201281c0 @ 201281c0 (540 bytes)

void FUN_201281c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = fb_get_layer_addr(DAT_208085bc);
  bVar3 = *(byte *)(param_1 + 0x9b) & 0xf;
  if (param_3 != 0) {
    fb_fill_rect(local_2c,0x821,DAT_2080060a,DAT_20800628 + DAT_20800634 + 1,DAT_208005e0,
                 DAT_208005e2);
  }
  uVar2 = 0;
  do {
    if ((param_3 != 0) ||
       (iVar1 = FUN_2015507c(param_1 + uVar2 * 0x1e + 0x119,param_2 + uVar2 * 0x1e + 0x119,0x1e),
       iVar1 != 0)) {
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      memcpy(&local_4c,param_1 + uVar2 * 0x1e + 0x119,0x1e);
      gui_draw_text(local_2c,&local_4c,DAT_2080064e * uVar2 + (uint)DAT_2080063a & 0xffff,
                    DAT_20800638,0xf,&DAT_20800b1c);
      if (uVar2 != 4) {
        fb_fill_box(local_2c,DAT_2080064e * uVar2 + (uint)DAT_2080062a & 0xffff,DAT_20800628,
                    DAT_2080063c,DAT_2080063e,0);
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 5);
  fb_fill_rect(local_2c,0x3186,DAT_20800616,DAT_20800614,DAT_2080061c,DAT_2080061e);
  gui_draw_text(local_2c,"BACK",DAT_208005ea,DAT_208005e8,DAT_208005ec,&DAT_20800fb4);
  if (bVar3 != 4 && bVar3 != 1) {
    fb_draw_round_frame(local_2c,DAT_20800616,DAT_20800614,DAT_2080061c,DAT_2080061e,1,0x821);
    return;
  }
  FUN_20136398(local_2c,DAT_20800616,DAT_20800614,DAT_2080061c,DAT_2080061e,3);
  return;
}


// ===== FUN_201283fc @ 201283fc (360 bytes)

void FUN_201283fc(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_28 = fb_get_layer_addr(DAT_208085bc);
  param_2 = param_1 * 0x2d + param_2;
  cVar1 = *(char *)(param_2 + 0x119);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_40,param_2 + 0x11c,0x15);
  gui_draw_text_words(local_28,&local_40,(uint)DAT_2080064e * param_1 + (uint)DAT_20800622 & 0xffff,
                      DAT_20800620,0xf,&DAT_20800b1c);
  fb_fill_rect(local_28,0x821,(uint)DAT_2080064e * param_1 + (uint)DAT_20800626 & 0xffff,
               DAT_20800624,*DAT_2080229c,DAT_2080229c[1]);
  gui_draw_runs(local_28,(uint)DAT_2080064e * param_1 + (uint)DAT_20800626 & 0xffff,DAT_20800624,
                DAT_2080229c);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_40,param_2 + 0x131,*(byte *)(param_2 + 0x11a) & 0x1f);
  str_rtrim(&local_40);
  if (cVar1 < '\0') {
    puVar2 = &DAT_20800e34;
  }
  else {
    puVar2 = &DAT_20800b1c;
  }
  gui_draw_text_centered
            (local_28,&local_40,(uint)DAT_2080064e * param_1 + (uint)DAT_20800632 & 0xffff,
             DAT_20800630,0xf,puVar2);
  return;
}


// ===== FUN_20128564 @ 20128564 (416 bytes)

void FUN_20128564(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  param_2 = param_1 * 0x2d + param_2;
  cVar1 = *(char *)(param_2 + 0x119);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x11c,0x15);
  gui_draw_text_words(uVar2,&local_38,(uint)DAT_2080064e * param_1 + (uint)DAT_20800622 & 0xffff,
                      DAT_20800620,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar2,0x821,(uint)DAT_2080064e * param_1 + 0x2f & 0xffff,0x120,*DAT_208022b4,
               DAT_208022b4[1]);
  gui_draw_runs(uVar2,(uint)DAT_2080064e * param_1 + 0x2f & 0xffff,0x120,DAT_208022b4);
  gui_draw_runs(uVar2,(uint)DAT_2080064e * param_1 + 0x39 & 0xffff,0x129,DAT_208022b8);
  gui_draw_runs(uVar2,(uint)DAT_2080064e * param_1 + 0x39 & 0xffff,0x291,DAT_208022bc);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x131,*(byte *)(param_2 + 0x11a) & 0x1f);
  str_rtrim(&local_38);
  if (cVar1 < '\0') {
    puVar3 = &DAT_2080143c;
  }
  else {
    puVar3 = &DAT_208012b8;
  }
  gui_draw_text_centered
            (uVar2,&local_38,(uint)DAT_2080064e * param_1 + 0x39 & 0xffff,0x1e9,0x18,puVar3);
  return;
}


// ===== FUN_20128704 @ 20128704 (348 bytes)

void FUN_20128704(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  param_2 = param_2 + param_1 * 0x2d;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x11c,0x15);
  gui_draw_text_words(uVar1,&local_38,(uint)DAT_2080064e * param_1 + (uint)DAT_20800622 & 0xffff,
                      DAT_20800620,0xf,&DAT_20800b1c);
  fb_fill_rect(uVar1,0x821,(uint)DAT_2080064e * param_1 + (uint)DAT_20800642 & 0xffff,DAT_20800640,
               *DAT_20802290,DAT_20802290[1]);
  gui_draw_runs(uVar1,(uint)DAT_2080064e * param_1 + (uint)DAT_20800642 & 0xffff,DAT_20800640,
                DAT_20802290);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  memcpy(&local_38,param_2 + 0x131,*(byte *)(param_2 + 0x11a) & 0x1f);
  str_rtrim(&local_38);
  gui_draw_runs(uVar1,(uint)DAT_2080064e * param_1 + (uint)DAT_2080064a + (uint)DAT_20800642 &
                      0xffff,DAT_20800640 + DAT_20800648,&DAT_2016dc18);
  return;
}


// ===== FUN_20128860 @ 20128860 (1104 bytes)

void FUN_20128860(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  uVar8 = 0xff;
  uVar10 = 0xff;
  uVar2 = (uint)*(byte *)(param_1 + 0x9a);
  uVar3 = (uint)*(byte *)(param_1 + 0x99);
  bVar7 = *(byte *)(param_1 + 0x9b) & 0xf;
  if ((bVar7 == 2 || bVar7 == 3) || (5 < uVar2)) {
    uVar8 = *(byte *)(param_1 + 0x9c) & 0xf;
  }
  bVar9 = *(byte *)(param_2 + 0x9b) & 0xf;
  if ((bVar9 == 2 || bVar9 == 3) || (5 < uVar2)) {
    uVar10 = *(byte *)(param_2 + 0x9c) & 0xf;
  }
  uVar6 = 0;
  do {
    if (((param_3 != 0) || (uVar8 != uVar10 || bVar7 != bVar9)) ||
       (iVar4 = FUN_2015507c(uVar6 * 0x2d + param_1 + 0x119,uVar6 * 0x2d + param_2 + 0x119,0x2d),
       iVar4 != 0)) {
      fb_fill_rect(uVar1,0x4a69,DAT_2080064e * uVar6 + (uint)DAT_2080060e & 0xffff,DAT_2080060c,
                   DAT_20800610,DAT_2080062e + DAT_20800612,uVar3);
      iVar4 = uVar6 * 0x2d + param_1;
      uVar5 = (*(byte *)(iVar4 + 0x119) & 0x7f) >> 6;
      if ((*(byte *)(iVar4 + 0x11a) & 0x1f) != 0) {
        iVar4 = FUN_2015507c(iVar4 + 0x131,"DONE",4);
        if (iVar4 == 0) {
          FUN_20128704(uVar6,param_1);
          if (bVar7 == 2 && uVar6 == uVar8) {
            FUN_20136398(uVar1,DAT_2080064e * uVar6 + (uint)DAT_20800642 & 0xffff,DAT_20800640,
                         DAT_20800644,DAT_20800646,3);
          }
        }
        else if ((bVar7 == 3) && (uVar5 != 0)) {
          FUN_20128564(uVar6,param_1);
        }
        else {
          FUN_201283fc(uVar6,param_1);
          if (bVar7 == 2 && uVar6 == uVar8) {
            FUN_20136398(uVar1,DAT_2080064e * uVar6 + (uint)DAT_2080060e & 0xffff,DAT_2080060c,
                         DAT_20800610,DAT_20800612,3);
          }
        }
      }
      if (uVar6 != 4) {
        fb_fill_box(uVar1,DAT_2080064e * uVar6 + (uint)DAT_2080062a & 0xffff,DAT_20800628,
                    DAT_2080062c,(undefined1)DAT_2080062e,0x821);
      }
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 5);
  if (((param_3 != 0) || (*(char *)(param_1 + 0x99) != DAT_208f0bc3)) ||
     (*(char *)(param_1 + 0x9a) != DAT_208f0bc4)) {
    FUN_201363c0(uVar1,DAT_20800602,DAT_20800600,DAT_20800604,DAT_20800606,uVar2,uVar3,5,0x821);
    fb_fill_rect(uVar1,0x821,DAT_208005f2,DAT_208005f0,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005f2,DAT_208005f0,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005f6,DAT_208005f4,&DAT_2016dc58);
    fb_fill_rect(uVar1,0x821,DAT_208005fa,DAT_208005f8,0x62,0x3c);
    gui_draw_runs(uVar1,DAT_208005fa,DAT_208005f8,&DAT_2016dc48);
    gui_draw_runs(uVar1,DAT_208005fe,DAT_208005fc,&DAT_2016dc68);
    if (param_3 != 0) goto LAB_20128bf0;
  }
  if (bVar7 == bVar9) {
    return;
  }
LAB_20128bf0:
  if (*(char *)(param_1 + 0x98) == '\0') {
    fb_fill_rect(uVar1,0x3186,DAT_20800616,DAT_20800614,DAT_20800618,DAT_2080061a);
    gui_draw_text(uVar1,"BACK",DAT_208005ea,DAT_208005e8,DAT_208005ec,&DAT_20800fb4);
    if (bVar7 == 4 || bVar7 == 1) {
      FUN_20136398(uVar1,DAT_20800616,DAT_20800614,DAT_20800618,DAT_2080061a,3);
      return;
    }
    fb_draw_round_frame(uVar1,DAT_20800616,DAT_20800614,DAT_20800618,DAT_2080061a,1,0x821);
  }
  return;
}


// ===== FUN_20128d00 @ 20128d00 (404 bytes)

void FUN_20128d00(int param_1,int param_2,int param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = fb_get_layer_addr(DAT_208085bc);
  bVar2 = *(byte *)(param_1 + 0x9b);
  uVar1 = (uint)(*(byte *)(param_1 + 0x9c) >> 4);
  bVar6 = (bVar2 & 0xf) == (*(byte *)(param_2 + 0x9b) & 0xf);
  bVar7 = param_3 == 0 && bVar6;
  if (param_3 == 0 && bVar6) {
    bVar7 = uVar1 == *(byte *)(param_2 + 0x9c) >> 4;
  }
  if ((!bVar7) || (iVar3 = FUN_2015507c(param_1 + 0xb1,param_2 + 0xb1,0x68), iVar3 != 0)) {
    uVar5 = 0;
    do {
      psVar4 = &DAT_2016dc78 + uVar5 * 5;
      fb_fill_rect(local_2c,0x821,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,(&DAT_2016dc7c)[uVar5 * 5],
                   (&DAT_2016dc7e)[uVar5 * 5]);
      if (uVar5 == uVar1) {
        if ((bVar2 & 0xf) == 0) {
          gui_draw_runs(local_2c,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,&DAT_2016dc28);
          FUN_20135864(local_2c,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,(&DAT_2016dc7c)[uVar5 * 5],
                       (&DAT_2016dc7e)[uVar5 * 5],0x821,0x4a69);
        }
        else {
          fb_fill_rect(local_2c,0x4a69,(&DAT_2016dc7a)[uVar5 * 5],*psVar4,(&DAT_2016dc7c)[uVar5 * 5]
                       ,(&DAT_2016dc7e)[uVar5 * 5]);
        }
      }
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      memcpy(&local_3c,uVar5 * 0xd + param_1 + 0xb1,0xd);
      gui_draw_text_words(local_2c,&local_3c,(&DAT_2016dc7a)[uVar5 * 5] + DAT_208005e6,
                          *psVar4 + DAT_208005e4,0xf,&DAT_20800b1c);
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 7);
  }
  return;
}


// ===== FUN_20128e94 @ 20128e94 (184 bytes)

void FUN_20128e94(void)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  fb_fill_rect(uVar1,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar1,0x3186,DAT_208005c6,DAT_208005c4,DAT_208005cc,DAT_208005ce);
  fb_fill_rect(uVar1,0x821,DAT_208005d2,DAT_208005d0,DAT_208005d4,DAT_208005d6);
  fb_fill_rect(uVar1,0x4a69,DAT_208005da,DAT_208005d8,DAT_208005dc,DAT_208005de);
  return;
}


// ===== FUN_20128f4c @ 20128f4c (264 bytes)

void FUN_20128f4c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar1 = fb_get_layer_addr(DAT_208085bc);
  if (param_3 == 0) {
    iVar2 = FUN_2015507c(param_1 + 0x9d,param_2 + 0x9d,0x14);
    if (iVar2 == 0) goto LAB_20129000;
  }
  else {
    FUN_20128e94();
  }
  gui_draw_runs(uVar1,DAT_208005c6,DAT_208005c4,&DAT_2016dc08);
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  memcpy(&local_30,param_1 + 0x9d,0x14);
  gui_draw_text_centered(uVar1,&local_30,DAT_208005ca,DAT_208005c8,0xf,&DAT_20800b1c);
LAB_20129000:
  FUN_20128d00(param_1,param_2,param_3);
  if (*(char *)(param_1 + 0x98) != '\0') {
    if (*(char *)(param_1 + 0x98) == '\x01') {
      FUN_201281c0(param_1,param_2,param_3);
    }
    return;
  }
  FUN_20128860(param_1,param_2,param_3);
  return;
}


// ===== scr_text_list @ 20129054 (184 bytes)

/* packet 0x40: text list with LF/CR glyphs, DONE/BACK */

void scr_text_list(int param_1,int param_2,int param_3)

{
  undefined2 *local_30;
  undefined2 *local_2c;
  undefined4 local_28;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  if (param_3 != 0) {
    local_14 = 0;
    local_12 = 800;
    local_18 = 0;
    local_24 = 0;
    local_16 = 0x1e0;
    local_30 = &local_18;
    local_22 = 0;
    local_21 = 0xff;
    local_2c = &local_24;
    local_20 = 0;
    local_28 = 0;
    layer_alpha_rect_set(0,5,1,&local_30);
    layer_alpha_rect_set(1,5,1,&local_30);
  }
  if (*(byte *)(param_1 + 0x98) != *(byte *)(param_2 + 0x98)) {
    param_3 = 1;
  }
  if (*(byte *)(param_1 + 0x98) < 2) {
    FUN_20128f4c(param_1,param_2,param_3);
  }
  return;
}


// ===== FUN_2012910c @ 2012910c (676 bytes)

void FUN_2012910c(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
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
  char local_28;
  byte local_24;
  
  uVar2 = DAT_208f0b57;
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
  bVar1 = *(byte *)(param_1 + 0x24) >> 4;
  cVar5 = (*(byte *)(param_1 + 0x24) & 0xf) + 1;
  sprintf(&local_48,"MSG_CH%d",cVar5);
  if (bVar1 == 1) {
    if (DAT_2080048f == '\0') {
      if (DAT_20800490 == '\x01') {
        if (DAT_2080049d == cVar5) {
          return;
        }
        play_stop();
      }
      DAT_2080049d = cVar5;
      iVar3 = wav_list_dir(&DAT_208f1234,0xff,2);
      if (0 < iVar3) {
        local_28 = '\0';
        local_24 = 0;
        do {
          iVar3 = FUN_2015507c(&DAT_208f1234 + (uint)local_24 * 0x34,&local_48,7);
          if (iVar3 == 0) {
            if (*(int *)(&DAT_208f1264 + (uint)local_24 * 0x34) != 0) {
              FUN_20124744(0xfffffff7);
              return;
            }
            local_28 = '\x01';
            break;
          }
          local_24 = local_24 + 1;
        } while (local_24 < 5);
        if (local_28 != '\0') {
          if (DAT_20800490 == '\0') {
            FUN_201248a4(1);
          }
          play_start(&local_48,2);
          DAT_20800490 = 1;
          return;
        }
        iVar3 = -4;
      }
LAB_201292c4:
      FUN_20124744(iVar3);
      return;
    }
LAB_20129190:
    iVar3 = audio_state();
    if (iVar3 != 0) goto LAB_20129330;
  }
  else {
    if (bVar1 == 2) {
      if (DAT_2080048f == '\0') {
        iVar3 = FUN_20103bc0();
        if (iVar3 == 0) {
          FUN_201248a4(2,1);
          uVar4 = be32_load(&DAT_208f0ba3);
          FUN_20154a30(&local_58,0x10,&DAT_201293f0,uVar4);
          rec_start(&local_48,&local_58,uVar2,2);
          DAT_2080048f = 1;
          return;
        }
        iVar3 = -3;
        goto LAB_201292c4;
      }
      goto LAB_20129190;
    }
    if (bVar1 != 0) goto LAB_20129190;
  }
  if ((DAT_20800490 != '\x01') && (DAT_2080048f != '\x01')) {
LAB_20129330:
    if (bVar1 != 0) {
      return;
    }
    iVar3 = audio_error();
    if (iVar3 != 0) {
      audio_clear_error();
    }
    return;
  }
  iVar3 = audio_error();
  if (iVar3 == 0) {
    if (DAT_20800490 == '\x01') {
      play_stop();
      DAT_20800490 = '\0';
    }
    if (DAT_2080048f != '\x01') goto LAB_20129398;
    rec_stop();
  }
  else {
    audio_error();
    FUN_20124744();
    DAT_208007d8 = 0;
    audio_clear_error();
    DAT_20800490 = '\0';
  }
  DAT_2080048f = '\0';
LAB_20129398:
  FUN_201248a4(0);
  DAT_2080048e = 0;
  return;
}


// ===== FUN_201293f8 @ 201293f8 (2000 bytes)

void FUN_201293f8(int param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  short *psVar6;
  byte bVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  uint local_28;
  
  fb_get_layer_addr(DAT_208085b8);
  local_30 = fb_get_layer_addr(DAT_208085bc);
  iVar3 = audio_state();
  if ((((iVar3 == 0) && (iVar3 = audio_error(), iVar3 == 0)) &&
      ((bVar4 = *(byte *)(param_1 + 0x2d), bVar4 < 2 ||
       ((bVar4 == 4 || bVar4 == 5 || (bVar4 == 6 || bVar4 == 7)))))) &&
     (iVar3 = FUN_20103ba0(), iVar3 == 0)) {
    FUN_20124744(0xffffffff);
    return;
  }
  if (DAT_2080048e != '\x01') {
    DAT_2080048e = '\x02';
  }
  if (param_2 != 0) {
    fb_draw_frame(local_30,0x821,0x6d,0x62,0x25c,0xd2,2);
    fb_fill_rect(local_30,0x4a69,0x6f,100,600,0xce);
    fb_fill_rect(local_30,0x3186,0x74,0x69,0x24d,0x17);
    gui_draw_runs(local_30,DAT_2080078e,DAT_2080078c,&DAT_2016ebbc);
  }
  fb_fill_rect(local_30,0x4a69,DAT_20800792,DAT_20800790,0x7a,0x12);
  fb_fill_rect(local_30,0x4a69,DAT_20800796,DAT_20800794,0x44,0x18);
  if ((*(byte *)(param_1 + 0xb1) & 0xc) != 0) {
    if ((*(byte *)(param_1 + 0xb1) & 8) == 0) {
      bVar4 = *(byte *)(param_1 + 0xb7);
      gui_draw_runs(local_30,DAT_20800792,DAT_20800790,&DAT_2016ebac);
    }
    else {
      bVar4 = *(byte *)(param_1 + 0xb8);
      gui_draw_runs(local_30,DAT_20800792,DAT_20800790,&DAT_2016ebcc);
    }
    local_4c = 0;
    if (100 < bVar4) {
      bVar4 = 100;
    }
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    sprintf(&local_4c,&DAT_20129988,bVar4);
    local_4c = CONCAT13(0x25,(undefined3)local_4c);
    gui_draw_text(local_30,&local_4c,DAT_20800796,DAT_20800794,0x11,&DAT_20803030);
  }
  bVar4 = *(byte *)(param_1 + 0xb1);
  uVar5 = 0;
  bVar7 = bVar4 & 3;
  local_28 = (uint)*(byte *)(param_1 + 0xb4);
  do {
    puVar11 = (undefined *)0x0;
    puVar10 = (undefined *)0x0;
    puVar8 = (undefined *)0x0;
    if (uVar5 + 1 == local_28) {
      if ((bVar4 & 3) == 0) {
        psVar6 = (short *)0x20800798;
        puVar9 = *(undefined **)(&UNK_2016ecbc + uVar5 * 8);
      }
      else {
        psVar6 = &DAT_2080079c;
        puVar8 = &DAT_208031c0;
        puVar10 = &DAT_2016eb8c;
        puVar9 = (undefined *)(&DAT_2016ece4)[uVar5 * 2];
        puVar11 = &DAT_2016eb6c;
      }
      gui_draw_runs(local_30,(&DAT_2016ebde)[uVar5 * 5],(&DAT_2016ebdc)[uVar5 * 5]);
    }
    else {
      if ((bVar4 & 3) == 0) {
        psVar6 = (short *)0x20800798;
        puVar9 = *(undefined **)(&UNK_2016ecb8 + uVar5 * 8);
      }
      else {
        psVar6 = &DAT_2080079c;
        puVar8 = &DAT_208031c0;
        puVar9 = (&PTR_DAT_2016ece0)[uVar5 * 2];
        puVar11 = &DAT_2016eb5c;
        puVar10 = &UNK_2016eb9c;
      }
      fb_fill_rect(local_30,0x821,(&DAT_2016ebde)[uVar5 * 5],(&DAT_2016ebdc)[uVar5 * 5],
                   *(undefined2 *)(&UNK_2016ebe0 + uVar5 * 10),
                   *(undefined2 *)(&UNK_2016ebe2 + uVar5 * 10));
      gui_draw_runs(local_30,(&DAT_2016ebde)[uVar5 * 5],(&DAT_2016ebdc)[uVar5 * 5],&DAT_2016eb2c);
    }
    gui_draw_runs(local_30,(&DAT_2016ebde)[uVar5 * 5] + psVar6[1],
                  (&DAT_2016ebdc)[uVar5 * 5] + *psVar6,puVar9);
    if (bVar7 == 1) {
      uVar1 = 1 << (uVar5 & 0xff);
      if ((*(byte *)(param_1 + 0xb2) & uVar1) != 0) {
        gui_draw_runs(local_30,(&DAT_2016ec4c)[uVar5 * 5] + DAT_208007a2,
                      (&DAT_2016ec4a)[uVar5 * 5] + DAT_208007a0,puVar11);
      }
      if ((*(byte *)(param_1 + 0xb3) & uVar1) != 0) {
        gui_draw_runs(local_30,(&DAT_2016ec4c)[uVar5 * 5] + DAT_208007a6,
                      (&DAT_2016ec4a)[uVar5 * 5] + DAT_208007a4,puVar10);
      }
    }
    if (puVar8 != (undefined *)0x0) {
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      if ((bVar7 == 1) && (((uint)*(byte *)(param_1 + 0xb6) & 1 << (uVar5 & 0xff)) != 0)) {
        local_4c = 0x20;
        FUN_2015525c((int)&local_4c + 1,6,0x7f);
        local_48 = CONCAT13(0x20,(undefined3)local_48);
      }
      else {
        FUN_2016372c(&local_4c,param_1 + uVar5 * 8 + 0xc0);
      }
      gui_draw_text(local_30,&local_4c,(&DAT_2016ec4c)[uVar5 * 5] + DAT_208007aa,
                    (&DAT_2016ec4a)[uVar5 * 5] + DAT_208007a8,0xd,puVar8);
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 5);
  iVar3 = 6;
  do {
    if ((bVar4 & 3) == 0) {
      if (iVar3 + 1U == local_28) {
        puVar11 = (&PTR_DAT_2016ecdc)[iVar3 * 2];
        gui_draw_runs(local_30,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],&DAT_2016eb3c);
      }
      else {
        local_2c = &DAT_2016eb2c;
        puVar11 = (&PTR_DAT_2016ecd8)[iVar3 * 2];
        fb_fill_rect(local_30,0x821,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],
                     *(undefined2 *)(&UNK_2016ebe0 + iVar3 * 10),
                     *(undefined2 *)(&UNK_2016ebe2 + iVar3 * 10));
        gui_draw_runs(local_30,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],local_2c);
      }
      gui_draw_runs(local_30,(&DAT_2016ebde)[iVar3 * 5] + DAT_208007ae,
                    (&DAT_2016ebdc)[iVar3 * 5] + DAT_208007ac,puVar11);
    }
    else if (bVar7 == 1 && iVar3 == 6) {
      fb_fill_rect(local_30,0x821,0xfc,0xe1,0x6e,0x3c);
      gui_draw_runs(local_30,0xfc,0xe1,&DAT_2016eb2c);
      gui_draw_runs(local_30,DAT_208007b2 + 0xfc,DAT_208007b0 + 0xe1,&DAT_2016eb4c);
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      uVar2 = be16_load(param_1 + 0xba);
      if (9999 < uVar2) {
        uVar2 = 9999;
      }
      sprintf(&local_4c,&DAT_20129c38,uVar2);
      gui_draw_text(local_30,&local_4c,DAT_208007b6 + 0xfc,DAT_208007b4 + 0xe1,0xd,&DAT_208031c0);
    }
    else {
      fb_fill_rect(local_30,0x4a69,(&DAT_2016ebde)[iVar3 * 5],(&DAT_2016ebdc)[iVar3 * 5],
                   *(undefined2 *)(&UNK_2016ebe0 + iVar3 * 10),
                   *(undefined2 *)(&UNK_2016ebe2 + iVar3 * 10));
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  if (local_28 == 6) {
    gui_draw_runs(local_30,0xfc,0x69,&DAT_2016eb3c);
    gui_draw_runs(local_30,DAT_208007ba + 0xfc,DAT_208007b8 + 0x69,&DAT_2016eb7c);
  }
  else {
    fb_fill_rect(local_30,0x821,0xfc,0x69,0x6e,0x3c);
    gui_draw_runs(local_30,0xfc,0x69,&DAT_2016eb2c);
    gui_draw_runs(local_30,DAT_208007ba + 0xfc,DAT_208007b8 + 0x69,&DAT_2016eb7c);
  }
  fb_fill_rect(local_30,0x821,0xfc,0x249,0x6e,0x3c);
  gui_draw_runs(local_30,0xfc,0x249,&DAT_2016eb2c);
  gui_draw_runs(local_30,DAT_208007ba + 0xfc,DAT_208007b8 + 0x249,&DAT_2016eb1c);
  FUN_2012910c(param_1);
  return;
}


// ===== FUN_20129c44 @ 20129c44 (172 bytes)

void FUN_20129c44(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_r4;
  
  iVar2 = -9999;
  iVar4 = 4;
  if ((-10000 < param_1) && (iVar2 = param_1, 9999 < param_1)) {
    iVar2 = 9999;
  }
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = -iVar2;
  }
  iVar3 = (int)(short)iVar3;
  if (0 < iVar3) {
    unaff_r4 = 0x66666667;
  }
  if (iVar3 == 0) {
    iVar4 = 3;
    *(undefined1 *)(param_2 + 4) = 0x30;
  }
  else {
    for (; 0 < iVar3; iVar3 = (int)(short)iVar3 / 10) {
      *(char *)(param_2 + iVar4) =
           (char)iVar3 +
           ((char)(int)((longlong)unaff_r4 * (longlong)iVar3 >> 0x22) -
           (char)((longlong)unaff_r4 * (longlong)iVar3 >> 0x3f)) * -10 + '0';
      iVar4 = iVar4 + -1;
    }
  }
  iVar3 = iVar2;
  if (iVar2 < 0) {
    iVar3 = 0x2d;
  }
  uVar1 = (undefined1)iVar3;
  if (0 < iVar2) {
    uVar1 = 0x2b;
  }
  if (iVar2 != 0) {
    *(undefined1 *)(param_2 + iVar4) = uVar1;
  }
  return;
}


// ===== FUN_20129cf0 @ 20129cf0 (348 bytes)

void FUN_20129cf0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined1 auStack_2c [5];
  undefined1 local_27;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  uVar5 = (uint)*(byte *)(param_1 + 0x42);
  uVar6 = (uint)*(byte *)(param_2 + 0x42);
  iVar2 = be16_load(param_1 + 0x43);
  iVar3 = be16_load(param_2 + 0x43);
  bVar7 = param_3 == 0 && uVar5 == uVar6;
  bVar4 = *(byte *)(param_1 + 0x49) & 0xf;
  if (param_3 == 0 && uVar5 == uVar6) {
    bVar7 = bVar4 == (*(byte *)(param_2 + 0x49) & 0xf);
  }
  if (bVar7) {
    if (bVar4 != 9) {
      return;
    }
  }
  else {
    fb_clear_rect(uVar1,DAT_20800522,DAT_2080051c,0x121,0x36);
    if (bVar4 != 9) {
      return;
    }
    gui_draw_runs(uVar1,DAT_2080051e,DAT_2080051c,(&PTR_DAT_20800890)[uVar5 & 3]);
  }
  if ((param_3 != 0 || uVar5 != uVar6) || (iVar2 != iVar3)) {
    fb_clear_rect(uVar1,DAT_20800522,DAT_20800520,DAT_20800528,0x26);
    FUN_201637f0(auStack_2c,0x20);
    local_27 = 0;
    FUN_20129c44(iVar2,auStack_2c);
    gui_draw_text(uVar1,auStack_2c,DAT_20800522,DAT_20800520,DAT_20800524,&DAT_20802394);
    gui_draw_runs(uVar1,DAT_2080052e,DAT_2080052c,&DAT_2016d64c);
  }
  return;
}


// ===== FUN_20129e4c @ 20129e4c (280 bytes)

void FUN_20129e4c(byte *param_1,uint param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = fb_get_layer_addr(DAT_208085b8);
  uVar4 = 0;
  uVar5 = (param_2 & 0x3f) >> 5;
  if (*param_1 == 0xff) {
    uVar4 = 2;
    if (DAT_208004ce != 0) {
      uVar5 = 0;
    }
  }
  else {
    DAT_208004ce = (ushort)*param_1;
  }
  if (uVar4 < 8) {
    do {
      bVar1 = param_1[(int)uVar4 / 2] >> (((int)(uVar4 + 1) % 2 & 0x3fU) << 2);
      uVar6 = bVar1 & 0xf;
      if (uVar4 != 7 || (param_2 & 0x10) != 0) {
        if ((bVar1 & 0xf) == 0) {
          if (uVar5 == 0) {
LAB_20129ef4:
            puVar3 = (undefined2 *)(param_3 + uVar4 * 4);
            gui_draw_runs(uVar2,puVar3[1],*puVar3,*(undefined4 *)(param_4 + uVar6 * 4));
          }
        }
        else if (uVar6 == 0xf) {
          uVar5 = 0;
        }
        else if (uVar6 < 0xc) {
          uVar5 = 0;
          goto LAB_20129ef4;
        }
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 8);
  }
  if ((param_2 & 0x80) != 0) {
    gui_draw_runs(uVar2,*(undefined2 *)(param_3 + 0x22),*(undefined2 *)(param_3 + 0x20),
                  *(undefined4 *)(param_4 + 0x30));
  }
  if ((param_2 & 0x40) == 0) {
    return;
  }
  gui_draw_runs(uVar2,*(undefined2 *)(param_3 + 0x26),*(undefined2 *)(param_3 + 0x24),
                *(undefined4 *)(param_4 + 0x30));
  return;
}


// ===== FUN_20129f64 @ 20129f64 (1676 bytes)

void FUN_20129f64(char *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  undefined **unaff_r5;
  uint uVar6;
  uint uVar7;
  undefined **ppuVar8;
  uint uVar9;
  uint uVar10;
  undefined *local_9c [4];
  undefined1 uStack_8c;
  undefined1 uStack_8b;
  byte local_8a;
  byte local_89;
  undefined1 auStack_84 [12];
  undefined1 local_78;
  undefined1 auStack_74 [12];
  undefined1 local_68;
  uint local_64;
  uint local_60;
  byte local_5c [4];
  uint local_58;
  uint local_54;
  undefined1 auStack_50 [8];
  uint local_48;
  uint local_44;
  uint local_40;
  undefined *local_3c;
  undefined *local_38;
  char *pcStack_30;
  int iStack_2c;
  int local_28;
  
  pcStack_30 = param_1;
  iStack_2c = param_2;
  local_28 = param_3;
  local_9c[3] = (undefined *)fb_get_layer_addr(DAT_208085b8);
  local_38 = &DAT_2016dedc;
  local_3c = &DAT_20800800;
  local_60 = (uint)(byte)param_1[0x46];
  local_40 = (uint)*(byte *)(param_2 + 0x46);
  bVar1 = param_1[0x49];
  local_44 = (uint)*(byte *)(param_2 + 0x49);
  local_64 = (uint)bVar1;
  FUN_201636cc(&uStack_8c,param_1 + 0x4a);
  FUN_201636cc(auStack_50,param_2 + 0x4a);
  bVar2 = param_1[3];
  uVar5 = bVar1 & 0xf;
  uVar10 = bVar2 & 0x80;
  local_58 = *(byte *)(param_2 + 3) & 0x80;
  memcpy(auStack_84,param_1 + 0x4f,0xc);
  local_78 = 0;
  memcpy(auStack_74,param_2 + 0x4f,0xc);
  local_68 = 0;
  local_54 = (uint)*(byte *)(param_2 + 0x47);
  uVar6 = (uint)(byte)param_1[0x47];
  bVar1 = param_1[0x48];
  uVar7 = (uint)bVar1;
  ppuVar8 = (undefined **)&DAT_20800690;
  local_48 = (uint)*(byte *)(param_2 + 0x48);
  if (uVar6 == 1) {
    if (((local_28 != 0) || (uVar10 != local_58)) || (local_54 != 1)) {
      fb_clear_rect(local_9c[3],DAT_20800692 + -3,DAT_20800778,*(undefined2 *)PTR_DAT_20802ff4,
                    ((DAT_2080077a + *(short *)(PTR_DAT_20802ff4 + 2)) - DAT_20800692) + 3);
      if ((uVar5 == 4 || uVar5 == 5) || uVar5 == 7) {
        puVar4 = &DAT_2016df1c;
        if ((bVar2 & 0x80) != 0) {
          puVar4 = &DAT_2016defc;
        }
        gui_draw_runs(local_9c[3],DAT_20800692,DAT_20800690,puVar4);
      }
      goto LAB_2012a1b0;
    }
LAB_2012a1bc:
    if (((uVar10 != local_58) || (local_60 != local_40)) ||
       ((uVar6 != local_54 || (uVar7 != local_48)))) goto LAB_2012a1f0;
  }
  else {
    switch(uVar6) {
    case 2:
      if (uVar7 < 99) goto switchD_2012a048_caseD_7;
      ppuVar8 = (undefined **)0x20800694;
      break;
    case 5:
      ppuVar8 = (undefined **)0x2080069c;
      break;
    case 7:
switchD_2012a048_caseD_7:
      ppuVar8 = (undefined **)0x20800698;
      break;
    case 9:
    case 10:
      ppuVar8 = (undefined **)0x208006a0;
    }
    unaff_r5 = ppuVar8;
    if (((local_28 == 0) && (uVar10 == local_58)) &&
       ((uVar6 == local_54 && (uVar7 == *(byte *)(param_2 + 0x48))))) goto LAB_2012a1bc;
    fb_clear_rect(local_9c[3],DAT_20800692 + -3,DAT_20800778,*(undefined2 *)PTR_DAT_20802ff4,
                  ((DAT_2080077a + *(short *)(PTR_DAT_20802ff4 + 2)) - DAT_20800692) + 3);
    gui_draw_runs(local_9c[3],*(ushort *)((int)ppuVar8 + 2),*(ushort *)ppuVar8,
                  *(undefined4 *)(&DAT_2080265c + uVar6 * 4));
LAB_2012a1b0:
    if (local_28 == 0) goto LAB_2012a1bc;
LAB_2012a1f0:
    if ((uVar5 == 4 || uVar5 == 5) || uVar5 == 7) {
      uVar10 = local_60;
      if (0xf < local_60) {
        uVar10 = 0xf;
      }
      fb_clear_rect(local_9c[3],DAT_2080077a,DAT_20800778,*(undefined2 *)(&PTR_DAT_20802ff4)[uVar10]
                    ,*(undefined2 *)((int)(&PTR_DAT_20802ff4)[uVar10] + 2));
      gui_draw_runs(local_9c[3],DAT_2080077a,DAT_20800778,(&PTR_DAT_20802ff4)[uVar10]);
    }
  }
  if (uVar6 == 2) {
    if ((uVar5 != 4 && uVar5 != 5) && uVar5 != 7) goto LAB_2012a4b4;
    uVar10 = 0;
    if (uVar7 < 99) {
      uVar10 = 2;
      local_9c[0] = *(undefined **)(&DAT_20802338 + ((uint)((short)(uVar7 + 1) * 0xcd) >> 0xb) * 4);
      local_9c[1] = *(undefined **)(&DAT_20802338 + ((uVar7 + 1) % 10) * 4);
    }
    else if (uVar7 < 0x75) {
      uVar10 = 3;
      local_9c[0] = local_38;
      local_9c[1] = (&PTR_DAT_2080233c)[(int)(uVar7 - 99) / 2];
      local_9c[2] = (undefined *)*(undefined4 *)(local_3c + (uVar7 & 1) * 4);
    }
    uVar9 = 0;
    if (uVar10 == 0) goto LAB_2012a4b4;
    do {
      gui_draw_runs(local_9c[3],*(ushort *)((int)unaff_r5 + 2),
                    DAT_2080068c * uVar9 +
                    (uint)*(ushort *)unaff_r5 + (uint)*(ushort *)PTR_DAT_20802664 & 0xffff,
                    local_9c[uVar9]);
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < uVar10);
  }
  if (uVar6 == 7) {
    if ((uVar5 != 5 && uVar5 != 4) && uVar5 != 7) goto LAB_2012a4b4;
    uVar10 = 0;
    iVar3 = (short)(bVar1 - 0x74) * 0xcd;
    local_9c[0] = *(undefined **)(&DAT_20802338 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
    local_9c[1] = *(undefined **)(&DAT_20802338 + ((int)(uVar7 - 0x74) % 10) * 4);
    do {
      gui_draw_runs(local_9c[3],*(ushort *)((int)unaff_r5 + 2),
                    DAT_2080068c * uVar10 +
                    (uint)*(ushort *)unaff_r5 + (uint)*(ushort *)PTR_DAT_20802678 & 0xffff,
                    local_9c[uVar10]);
      uVar10 = uVar10 + 1 & 0xff;
    } while (uVar10 < 2);
  }
  if ((uVar6 == 5) && ((uVar5 == 5 || uVar5 == 4) || uVar5 == 7)) {
    local_9c[0] = (undefined *)0x0;
    if (9 < (int)(uVar7 - 0x82)) {
      iVar3 = (short)(uVar7 - 0x82) * 0xcd;
      local_9c[0] = *(undefined **)(&DAT_20802338 + ((iVar3 >> 0xb) - (iVar3 >> 0x1f)) * 4);
    }
    uVar6 = 0;
    local_9c[1] = *(undefined **)(&DAT_20802338 + ((int)(uVar7 - 0x82) % 10) * 4);
    do {
      if (local_9c[uVar6] != (undefined *)0x0) {
        gui_draw_runs(local_9c[3],*(ushort *)((int)unaff_r5 + 2),
                      DAT_2080068c * uVar6 +
                      (uint)*(ushort *)PTR_DAT_20802670 + (uint)*(ushort *)unaff_r5 & 0xffff);
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 2);
  }
LAB_2012a4b4:
  if (((((local_28 != 0) || (local_64 != local_44)) ||
       (iVar3 = FUN_2015507c(&uStack_8c,auStack_50,5), iVar3 != 0)) ||
      (iVar3 = FUN_2015507c(auStack_84,auStack_74,0xd), iVar3 != 0)) &&
     ((uVar5 == 5 || uVar5 == 4) || uVar5 == 7)) {
    if (uVar5 == 4) {
      unaff_r5 = &PTR_DAT_20802514;
    }
    else if (uVar5 == 5) {
      unaff_r5 = &PTR_DAT_20802548;
    }
    else if (uVar5 == 7) {
      unaff_r5 = &PTR_DAT_20802360;
    }
    fb_clear_rect(local_9c[3],DAT_20800772,DAT_20801864,
                  (DAT_20801880 + *(short *)*unaff_r5) - DAT_20801864,0x26);
    if ((*param_1 == '0') && (param_1[0x98] == '\a')) {
      uVar5 = 0;
      local_5c[0] = local_8a >> 4;
      local_5c[1] = local_8a & 0xf;
      local_5c[2] = local_89 >> 4;
      do {
        if (local_5c[uVar5] < 0xc) {
          gui_draw_runs(local_9c[3],(&DAT_20801876)[uVar5 * 2],(&DAT_20801874)[uVar5 * 2],
                        unaff_r5[local_5c[uVar5]]);
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < 3);
    }
    else {
      switch(local_64 & 0xf) {
      case 4:
      case 5:
      case 7:
        FUN_20129e4c(&uStack_8b,local_64,&DAT_20801864,unaff_r5);
        return;
      }
    }
  }
  return;
}


// ===== scr_vfo @ 2012a6a4 (636 bytes)

/* packet 0x39: frequency digits */

void scr_vfo(char *param_1,char *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_58 [12];
  undefined1 local_4c;
  undefined1 auStack_48 [12];
  undefined1 local_3c;
  undefined1 uStack_38;
  undefined1 auStack_37 [7];
  undefined4 local_30;
  undefined1 auStack_2c [8];
  
  local_30 = fb_get_layer_addr(DAT_208085b8);
  iVar8 = 0;
  iVar7 = 0;
  bVar1 = param_1[0x30];
  uVar6 = (uint)bVar1;
  bVar5 = param_1[0x49] & 0xf;
  bVar2 = param_2[0x49];
  uVar3 = (uint)(byte)param_2[0x30];
  FUN_201636cc(&uStack_38,param_1 + 0x31);
  FUN_201636cc(auStack_2c,param_2 + 0x31);
  memcpy(auStack_58,param_1 + 0x36,0xd);
  local_4c = 0;
  memcpy(auStack_48,param_2 + 0x36,0xd);
  local_3c = 0;
  if ((((param_3 != 0) || (uVar6 != uVar3)) ||
      (iVar4 = FUN_2015507c(&uStack_38,auStack_2c,5), iVar4 != 0)) ||
     (iVar4 = FUN_2015507c(auStack_58,auStack_48,0xd), iVar4 != 0 || bVar5 != (bVar2 & 0xf))) {
    fb_clear_rect(local_30,10,0x17e,0x1a2,0x32);
    uVar3 = uVar6 & 0xf;
    if ((bVar1 & 0xf) != 0) {
      if (uVar3 == 1) {
        gui_draw_text(local_30,auStack_58,DAT_2080076a,DAT_20800768,DAT_2080076c,&DAT_208015bc);
      }
      else if (uVar3 == 4) {
        FUN_20129e4c(auStack_37,uVar6,&DAT_2080183c);
      }
      else if (uVar3 == 6) {
        FUN_20129e4c(auStack_37,uVar6,&DAT_2080183c,&PTR_DAT_208025b0);
      }
    }
  }
  if (bVar5 != (bVar2 & 0xf)) {
    param_3 = 1;
  }
  if ((bVar5 == 4 || bVar5 == 5) || bVar5 == 7) {
    if ((*param_1 == '0') && (param_1[0x98] == '\a')) {
      iVar8 = 1;
    }
    if ((*param_2 == '0') && (param_2[0x98] == '\a')) {
      iVar7 = 1;
    }
    if (iVar8 == iVar7) goto LAB_2012a868;
    param_3 = 1;
  }
  else {
LAB_2012a868:
    if (param_3 == 0) goto LAB_2012a8d8;
  }
  fb_clear_rect(local_30,DAT_20800692 + -3,DAT_20800778,
                ((*(short *)PTR_DAT_20802548 + DAT_20801880) - DAT_20800778) + 1,
                ((*(short *)(PTR_DAT_20802ff4 + 2) + DAT_2080077a) - DAT_20800692) + 3);
LAB_2012a8d8:
  if ((bVar5 == 4 || bVar5 == 5) || bVar5 == 7) {
    FUN_20129f64(param_1,param_2,param_3);
    return;
  }
  if (bVar5 == 9) {
    FUN_20129cf0(param_1,param_2,param_3);
  }
  return;
}


// ===== FUN_2012a920 @ 2012a920 (204 bytes)

void FUN_2012a920(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_r9;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  iVar3 = 0;
  do {
    if (0x20 < *(byte *)(param_1 + iVar3)) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  uVar2 = 8 - iVar3;
  if ((uVar2 & 1) == 0) {
    param_3 = param_3 + 1 & 0xffff;
  }
  if (iVar3 < 8) {
    unaff_r9 = 0x20801bc4;
  }
  uVar2 = (param_3 - ((uVar2 * 0xc & 0xffff) >> 1)) + ((int)uVar2 / 2) * -2;
  for (; iVar3 < 8; iVar3 = iVar3 + 1) {
    gui_draw_runs(uVar1,param_2,uVar2 & 0xffff,
                  *(undefined4 *)(unaff_r9 + (uint)*(byte *)(param_1 + iVar3) * 4 + -0x80));
    uVar2 = (uint)**(ushort **)(unaff_r9 + (uint)*(byte *)(param_1 + iVar3) * 4 + -0x80) +
            (uVar2 & 0xffff) + 2;
  }
  return;
}


// ===== scr_func_panel @ 2012a9ec (908 bytes)

/* packet 0x37: FUNC panel (CONTRAST, DIMMER, MIC GAIN, ...) */

void scr_func_panel(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  undefined **ppuVar9;
  int iVar10;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  
  uVar3 = fb_get_layer_addr(DAT_208085b8);
  local_34 = *(byte *)(param_1 + 0x99) & 0x3f;
  local_28 = *(byte *)(param_1 + 0x9a) & 0x3f;
  bVar1 = *(byte *)(param_1 + 0x98);
  if ((bVar1 & 0x40) == 0) {
    local_38 = 0xfc00;
  }
  else {
    local_38 = 0xffff;
  }
  local_3c = (uint)(bVar1 >> 7);
  local_2c = bVar1 & 0x20;
  if (param_2 != 0) {
    fb_fill_rect(uVar3,0x821,0x6d,0,800,0x173);
  }
  local_30 = 0x21;
  gui_draw_runs(uVar3,DAT_208019d8,DAT_208019d6,&DAT_2016d740);
  gui_draw_runs(uVar3,DAT_20800532 + DAT_208019d8,DAT_208019d6 + DAT_20800530,&DAT_2016d720);
  if ((local_3c != 0) && (local_34 == 0x21)) {
    fb_draw_round_frame(uVar3,DAT_208019d8,DAT_208019d6,0xe1,0x32,3,local_38);
  }
  uVar5 = 0;
  do {
    fb_fill_rect(uVar3,0x4a69,(&DAT_2016d900)[uVar5 * 2],(&DAT_2016d8fe)[uVar5 * 2],0x316,2);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 3);
  uVar5 = 0;
  if (0 < local_30) {
    do {
      iVar10 = param_1 + uVar5 * 10;
      uVar8 = (uint)*(byte *)(iVar10 + 0x9c);
      if ((*(byte *)(iVar10 + 0x9b) & 0x80) == 0) {
        ppuVar9 = &PTR_DAT_208019ec;
      }
      else {
        ppuVar9 = (undefined **)&DAT_20801ad8;
      }
      if ((uVar8 < 0x41) && (ppuVar9[uVar8] != (undefined *)0x0)) {
        psVar6 = &DAT_2080188c + uVar5 * 5;
        gui_draw_runs(uVar3,(&DAT_2080188e)[uVar5 * 5],*psVar6,&DAT_2016d710);
        uVar4 = (uint)(ushort)(&DAT_2080188e)[uVar5 * 5];
        sVar2 = *psVar6;
        uVar7 = (DAT_2080053a + uVar4) * 0x10000 | (uint)(ushort)(DAT_20800538 + sVar2);
        if (uVar8 == 0xf) {
switchD_2012abd4_caseD_0:
          local_48 = 0;
          local_44 = 0;
          local_40 = 0;
          FUN_2016372c(&local_48,iVar10 + 0x9d);
          FUN_2012a920(&local_48,DAT_2080053e + (&DAT_2080188e)[uVar5 * 5],*psVar6 + DAT_2080053c);
        }
        else {
          if (uVar8 < 0x10) {
            switch(uVar8) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 7:
            case 8:
            case 9:
            case 10:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
              goto switchD_2012abd4_caseD_0;
            default:
              goto switchD_2012abd4_caseD_6;
            }
          }
          if (uVar8 == 0x24) goto switchD_2012abd4_caseD_0;
          if (uVar8 < 0x25) {
            if (uVar8 - 0x10 < 6) goto switchD_2012abd4_caseD_0;
switchD_2012abd4_caseD_6:
            uVar7 = (uVar4 + DAT_20800536) * 0x10000 | (uint)(ushort)(DAT_20800534 + sVar2);
          }
          else {
            switch(uVar8) {
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
              gui_draw_runs(uVar3,uVar4 + DAT_20800542 & 0xffff,sVar2 + DAT_20800540,&DAT_2016d730);
              break;
            default:
              goto switchD_2012abd4_caseD_6;
            case 0x3a:
              goto switchD_2012abd4_caseD_0;
            }
          }
        }
        gui_draw_runs(uVar3,uVar7 >> 0x10,uVar7 & 0xffff,ppuVar9[uVar8]);
        if ((local_3c == 0) || (uVar5 != local_34)) {
          if ((uVar5 == local_28) && (local_2c != 0)) {
            fb_draw_round_frame(uVar3,(&DAT_2080188e)[uVar5 * 5],*psVar6,0x6e,0x32,3,0x6e0);
          }
        }
        else {
          fb_draw_round_frame(uVar3,(&DAT_2080188e)[uVar5 * 5],*psVar6,0x6e,0x32,3,local_38);
        }
      }
      else {
        fb_fill_rect(uVar3,0x821,(&DAT_2080188e)[uVar5 * 5],(&DAT_2080188c)[uVar5 * 5],0x6e,0x32);
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < local_30);
  }
  return;
}


// ===== scr_value_popup @ 2012ade0 (680 bytes)

/* packet 0x31: setting name + value popup (tables at 0x208026DC..) */

void scr_value_popup(int param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = fb_get_layer_addr(DAT_208085bc);
  uVar3 = (uint)*(byte *)(param_1 + 0x98);
  iVar6 = *(int *)(&DAT_208029e8 + uVar3 * 4);
  psVar5 = *(short **)(&DAT_20802c34 + uVar3 * 4);
  if (psVar5 != (short *)0x0) {
    iVar1 = uVar3 * 4;
    psVar4 = (short *)(&DAT_208026dc + iVar1);
    fb_fill_rect(local_2c,0x821,*(short *)(&DAT_208026de + iVar1) + 2,*psVar4 + 2,*psVar5 + -4,
                 psVar5[1] + -4);
    gui_draw_runs(local_2c,*(undefined2 *)(&DAT_208026de + iVar1),*psVar4,psVar5);
    fb_fill_box(local_2c,*(undefined2 *)(&DAT_208026de + iVar1),*psVar4 + 6,*psVar5 + -0xc,2,0x632c)
    ;
    fb_fill_box(local_2c,*(short *)(&DAT_208026de + iVar1) + psVar5[1] + -2,*psVar4 + 6,
                *psVar5 + -0xc,2,0x632c);
    if (iVar6 == 0) {
      if (*(short *)(&DAT_208027e0 + uVar3 * 4) != 0) {
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        memcpy(&local_38,*(undefined4 *)(&DAT_20802aec + uVar3 * 4),(&DAT_20802bf0)[uVar3]);
        gui_draw_text(local_2c,&local_38,
                      *(short *)(&DAT_208026de + iVar1) + *(short *)(&DAT_208027e2 + uVar3 * 4),
                      *psVar4 + *(short *)(&DAT_208027e0 + uVar3 * 4),0x22,&DAT_208015bc);
      }
    }
    else {
      gui_draw_runs(local_2c,*(short *)(&DAT_208027e2 + uVar3 * 4) +
                             *(short *)(&DAT_208026de + iVar1),
                    *psVar4 + *(short *)(&DAT_208027e0 + uVar3 * 4),iVar6);
    }
    iVar6 = uVar3 * 4;
    psVar7 = (short *)(&DAT_208028e4 + iVar6);
    if (*psVar7 != 0) {
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      memcpy(&local_38,param_1 + 0x99,9);
      local_30._0_2_ = (ushort)(byte)local_30;
      str_rtrim(&local_38);
      if (*(short *)(&DAT_208027e0 + uVar3 * 4) == 0) {
        gui_draw_text_centered
                  (local_2c,&local_38,
                   *(short *)(&DAT_208026de + iVar1) + *(short *)(&DAT_208028e6 + iVar6),
                   *psVar4 + *psVar7,0x22,&DAT_208015bc);
        return;
      }
      sVar2 = FUN_20155122(&local_38);
      gui_draw_text(local_2c,&local_38,
                    *(short *)(&DAT_208026de + iVar1) + *(short *)(&DAT_208028e6 + iVar6),
                    (*psVar4 + *psVar5 + sVar2 * -0x22) - *psVar7,0x22,&DAT_208015bc);
    }
  }
  return;
}


// ===== FUN_2012b0f0 @ 2012b0f0 (204 bytes)

void FUN_2012b0f0(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  if (4 < param_1) {
    param_1 = 4;
  }
  uVar3 = param_2 & 0xffff;
  iVar1 = param_1 * 4;
  param_2 = param_2 >> 0x10;
  fb_draw_frame(uVar2,0x821,param_2,uVar3,*(short *)(&DAT_2016e620 + iVar1),
                *(undefined2 *)(&DAT_2016e622 + iVar1),2);
  fb_fill_rect(uVar2,0x4a69,param_2 + 2 & 0xffff,uVar3 + 2 & 0xffff,
               *(short *)(&DAT_2016e620 + iVar1) + -4,*(short *)(&DAT_2016e622 + iVar1) + -4);
  fb_fill_rect(uVar2,0x3186,param_2 + 7 & 0xffff,uVar3 + 7 & 0xffff,0x1d5,0x17);
  return;
}


// ===== scr_select_popup @ 2012c1b4 (4200 bytes)

/* packet 0x30: METER / MODE selection popups */

void scr_select_popup(int param_1,int param_2,int param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  ushort uVar9;
  uint uVar10;
  undefined4 unaff_r4;
  int iVar11;
  short *psVar12;
  undefined4 unaff_r5;
  undefined **ppuVar13;
  undefined4 unaff_r6;
  uint uVar14;
  uint uVar15;
  undefined4 unaff_r7;
  uint uVar16;
  undefined4 unaff_r8;
  undefined4 uVar17;
  undefined4 unaff_r9;
  short *psVar18;
  undefined4 unaff_r10;
  undefined4 unaff_lr;
  undefined *in_stack_ffffffc8;
  byte bVar19;
  
  bVar19 = *(byte *)(param_1 + 0x98);
  bVar1 = *(byte *)(param_1 + 0x99);
  uVar14 = (uint)bVar1;
  uVar16 = *(byte *)(param_1 + 0x9a) & 1;
  fb_get_layer_addr(DAT_208085bc);
  if (bVar19 != 7) {
    if (bVar19 < 8) {
      switch(bVar19) {
      case 0:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        FUN_2012b0f0(0,0x6d0000);
        gui_draw_runs(uVar5,0x75,0xc5,&DAT_2016dd04,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
                      unaff_r9,unaff_r10);
        if (5 < uVar14) {
          uVar14 = 5;
        }
        uVar16 = 0;
        do {
          iVar11 = (&DAT_2016dd14)[uVar16 * 2];
          if (iVar11 != 0) {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              iVar11 = (&DAT_2016dd18)[uVar16 * 2];
            }
            else {
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016dd46)[uVar16 * 5],(&DAT_2016dd44)[uVar16 * 5],puVar7,
                          unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,unaff_r9,unaff_r10);
            gui_draw_runs(uVar5,(&DAT_2016dd46)[uVar16 * 5] + DAT_2080065a,
                          (&DAT_2016dd44)[uVar16 * 5] + DAT_20800658,iVar11);
          }
          uVar16 = uVar16 + 1 & 0xff;
        } while (uVar16 < 6);
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        bVar4 = bVar19 - 1;
        puVar7 = (undefined *)0x0;
        bVar1 = (&DAT_2016d290)[bVar4];
        if ((bVar19 == 1 || bVar19 == 2) || (bVar19 == 3 || bVar19 == 4)) {
          in_stack_ffffffc8 = (&PTR_DAT_208026a8)[bVar4];
          puVar7 = (&PTR_PTR_208026b8)[bVar4];
        }
        uVar15 = 0;
        if (bVar1 != 0) {
          do {
            if (uVar15 == uVar14) {
              if (uVar16 == 0) {
                puVar8 = &UNK_2016e12c;
                uVar17 = *(undefined4 *)(puVar7 + uVar15 * 0xc + 4);
                goto LAB_2012c03c;
              }
              puVar8 = &DAT_2016e11c;
              psVar12 = &DAT_208006c0;
              uVar17 = *(undefined4 *)(puVar7 + uVar15 * 0xc + 8);
              sVar2 = DAT_208004c4;
            }
            else {
              puVar8 = &UNK_2016e13c;
              uVar17 = *(undefined4 *)(puVar7 + uVar15 * 0xc);
LAB_2012c03c:
              psVar12 = (short *)0x208006bc;
              sVar2 = DAT_208004c2;
            }
            psVar18 = (short *)(in_stack_ffffffc8 + uVar15 * 10);
            fb_clear_rect(uVar5,DAT_208004c4,*psVar18,0x6b,0x68);
            gui_draw_runs(uVar5,sVar2,*psVar18,puVar8);
            gui_draw_runs(uVar5,psVar12[1] + sVar2,*psVar18 + *psVar12,uVar17);
            uVar15 = uVar15 + 1 & 0xff;
          } while (uVar15 < bVar1);
        }
        return;
      case 5:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        uVar15 = (uint)*(byte *)(param_1 + 0x9b);
        FUN_2012b0f0(2,0x5b009e);
        gui_draw_runs(uVar5,DAT_20800782,DAT_20800780,&DAT_2016e724);
        uVar16 = 0;
        do {
          if (uVar16 == uVar14) {
            puVar7 = &DAT_2016e5e0;
            uVar17 = (&DAT_2016e7e4)[uVar16 * 2];
          }
          else {
            uVar17 = *(undefined4 *)(&UNK_2016e7e0 + uVar16 * 8);
            puVar7 = &DAT_2016e5f0;
          }
          while( true ) {
            gui_draw_runs(uVar5,(&DAT_2016e736)[uVar16 * 5],(&DAT_2016e734)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016e736)[uVar16 * 5] + DAT_2080077e,
                          (&DAT_2016e734)[uVar16 * 5] + DAT_2080077c,uVar17);
            uVar16 = uVar16 + 1 & 0xff;
            if (0xf < uVar16) {
              fb_draw_round_frame(uVar5,(&DAT_2016e736)[(uVar15 & 0xff) * 5],
                                  (&DAT_2016e734)[(uVar15 & 0xff) * 5],0x6e,0x32,3,0xf980);
              return;
            }
            if (uVar16 != 0xf) break;
            if ((*(byte *)(param_1 + 5) & 0x40) == 0) {
              puVar7 = &DAT_20802fe4;
              uVar17 = 0x208084bc;
            }
            else {
              puVar7 = &DAT_2016e5e0;
              uVar17 = 0x20807b38;
            }
          }
        } while( true );
      case 6:
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        FUN_2012b0f0(1,0xa1009e);
        gui_draw_runs(uVar5,0xa9,0x163,&DAT_2016e644,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
                      unaff_r9,unaff_r10);
        uVar16 = 0;
        do {
          if (uVar16 == uVar14) {
            puVar7 = &DAT_2016e5e0;
            puVar8 = (undefined *)(&DAT_2016e658)[uVar16 * 2];
          }
          else {
            puVar8 = (&PTR_DAT_2016e654)[uVar16 * 2];
            puVar7 = &DAT_2016e5f0;
          }
          gui_draw_runs(uVar5,(&DAT_2016e6a6)[uVar16 * 5],(&DAT_2016e6a4)[uVar16 * 5],puVar7,
                        unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,unaff_r9,unaff_r10);
          gui_draw_runs(uVar5,(&DAT_2016e6a6)[uVar16 * 5] + DAT_20800766,
                        (&DAT_2016e6a4)[uVar16 * 5] + DAT_20800764,puVar8);
          uVar16 = uVar16 + 1 & 0xff;
        } while (uVar16 < 10);
        return;
      }
    }
    else {
      if (bVar19 == 0xb) {
        uVar5 = fb_get_layer_addr(DAT_208085bc);
        uVar16 = *(byte *)(param_1 + 0x99) & 0xffffff0f;
        uVar14 = *(byte *)(param_2 + 0x99) & 0xffffff0f;
        bVar19 = *(byte *)(param_1 + 0x9b);
        uVar15 = (uint)*(byte *)(param_2 + 0x9b);
        bVar3 = false;
        if (10 < (byte)uVar16) {
          uVar16 = 10;
        }
        if (0xb < bVar19) {
          bVar19 = 0xb;
        }
        uVar10 = (uint)bVar19;
        if ((param_3 != 0) || (*(char *)(param_1 + 0x98) != *(char *)(param_2 + 0x98))) {
          bVar3 = true;
          fb_draw_frame(uVar5,0x821,0xa1,0x3d,0x2a6,0x128,2);
          fb_fill_rect(uVar5,0x821,0xa1,0x3d,0x2a6,0x128);
          gui_draw_runs32(uVar5,0xa1,0x3d,&DAT_2016e600);
          uVar9 = 8;
          do {
            gui_draw_runs32(uVar5,0xa1,uVar9 + 0x3d,&DAT_2016e610);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0x29e);
          gui_draw_runs(uVar5,DAT_20800762 + 0xa1,DAT_20800760 + 0x3d,&DAT_2016e520);
        }
        if (((uVar14 & 0xff) != (uVar16 & 0xff)) || ((uVar15 & 0xff) != (uVar10 & 0xff) || bVar3)) {
          uVar14 = 0;
          do {
            puVar6 = (undefined2 *)(&DAT_20802f60)[uVar14];
            fb_blit_raw(uVar5,(&DAT_2016e532)[uVar14 * 5],(&DAT_2016e530)[uVar14 * 5],
                        *(undefined4 *)(puVar6 + 6),*puVar6,puVar6[1]);
            gui_draw_runs(uVar5,(&DAT_2016e5b4)[uVar14 * 2],(&DAT_2016e5b2)[uVar14 * 2],
                          (&PTR_DAT_20802fb8)[uVar14]);
            uVar14 = uVar14 + 1 & 0xff;
          } while (uVar14 < 0xb);
          fb_fill_rect(uVar5,0x821,(&DAT_2016e532)[(uVar16 & 0xff) * 5] + DAT_2080075e,
                       (&DAT_2016e530)[(uVar16 & 0xff) * 5] + DAT_2080075c,
                       *(undefined2 *)(&PTR_DAT_20802f8c)[uVar16 & 0xff],
                       *(undefined2 *)((&PTR_DAT_20802f8c)[uVar16 & 0xff] + 2));
          gui_draw_runs(uVar5,(&DAT_2016e532)[(uVar16 & 0xff) * 5] + DAT_2080075e,
                        (&DAT_2016e530)[(uVar16 & 0xff) * 5] + DAT_2080075c,
                        (&PTR_DAT_20802f8c)[uVar16 & 0xff]);
          fb_draw_frame(uVar5,0x3186,0x186,0x274,0x68,0x3c,2);
          fb_fill_rect(uVar5,0x821,0x188,0x276,100,0x38);
          gui_draw_runs(uVar5,0x186,0x274,&DAT_2016dc38);
          gui_draw_runs(uVar5,0x19c,0x27c,&DAT_2016db88);
          if ((byte)uVar10 < 0xb) {
            gui_draw_runs(uVar5,(&DAT_2016e532)[(uVar10 & 0xff) * 5],
                          (&DAT_2016e530)[(uVar10 & 0xff) * 5],&DAT_2016e510);
            return;
          }
          FUN_20136398(uVar5,(&DAT_2016e532)[(uVar10 & 0xff) * 5],
                       (&DAT_2016e530)[(uVar10 & 0xff) * 5],0x68,0x3c,3);
        }
        return;
      }
      if (bVar19 < 0xc) {
        if (bVar19 == 8) goto LAB_2012bb34;
        if (bVar19 == 9) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          fb_draw_frame(uVar5,0x821,0xa1,0xda,0x16c,0x65,2,unaff_r4,unaff_r5,unaff_r6,unaff_r7,
                        unaff_r8,unaff_r9,unaff_r10);
          fb_fill_rect(uVar5,0x4a69,0xa3,0xdc,0x168,0x61);
          fb_fill_rect(uVar5,0x3186,DAT_208004fe + 0xa1,DAT_208004fc + 0xda,DAT_20800500,
                       DAT_20800502);
          gui_draw_runs(uVar5,DAT_208004fa + 0xa1,DAT_208004f8 + 0xda,&DAT_2016d330);
          uVar16 = 0;
          do {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              puVar8 = (undefined *)(&DAT_2016d344)[uVar16 * 2];
            }
            else {
              puVar8 = (&PTR_DAT_2016d340)[uVar16 * 2];
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016d35a)[uVar16 * 5],(&DAT_2016d358)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016d35a)[uVar16 * 5] + DAT_20800506,
                          (&DAT_2016d358)[uVar16 * 5] + DAT_20800504,puVar8);
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 3);
          return;
        }
        if (bVar19 == 10) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          fb_draw_frame(uVar5,0x821,0xa1,0x9e,0x1e4,0xf1,2);
          gui_draw_runs(uVar5,0xa1,0x9e,&DAT_2016df7c);
          uVar9 = 0;
          do {
            gui_draw_runs(uVar5,0xa1,uVar9 + 0xa6,&DAT_2016df5c);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0x6d);
          gui_draw_runs(uVar5,0xa1,0x112,&DAT_2016df6c);
          uVar9 = 0;
          do {
            gui_draw_runs(uVar5,0xa1,uVar9 + 0x11e,&DAT_2016df5c);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0x6d);
          gui_draw_runs(uVar5,0xa1,0x18a,&DAT_2016df6c);
          uVar9 = 0;
          do {
            gui_draw_runs(uVar5,0xa1,uVar9 + 0x196,&DAT_2016df5c);
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0xe5);
          gui_draw_runs(uVar5,0xa1,0x27a,&DAT_2016df8c);
          gui_draw_runs(uVar5,DAT_208006a6 + 0xa1,DAT_208006a4 + 0x9e,&DAT_2016df4c);
          gui_draw_runs(uVar5,DAT_208006aa + 0xa1,DAT_208006a8 + 0x9e,&DAT_2016df3c);
          gui_draw_runs(uVar5,DAT_208006ae + 0xa1,DAT_208006ac + 0x9e,&DAT_2016df2c);
          uVar16 = (uint)(bVar1 >> 6);
          uVar15 = (uVar14 & 0x3f) >> 4;
          if (2 < uVar16) {
            uVar16 = 2;
          }
          uVar14 = uVar14 & 0xf;
          if (2 < uVar15) {
            uVar15 = 2;
          }
          uVar10 = 0;
          if (5 < uVar14) {
            uVar14 = 5;
          }
          do {
            if (uVar10 == uVar16) {
              puVar7 = &DAT_2016e5e0;
              uVar17 = (&DAT_2016dfa0)[uVar10 * 2];
            }
            else {
              uVar17 = (&DAT_2016df9c)[uVar10 * 2];
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016dffe)[uVar10 * 5],(&DAT_2016dffc)[uVar10 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016dffe)[uVar10 * 5] + DAT_20800506,
                          (&DAT_2016dffc)[uVar10 * 5] + DAT_20800504,uVar17);
            if (uVar10 == uVar15) {
              puVar7 = (&PTR_DAT_2016dfb8)[uVar10 * 2];
              puVar8 = &DAT_2016e5e0;
            }
            else {
              puVar7 = (undefined *)(&DAT_2016dfb4)[uVar10 * 2];
              puVar8 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016e01c)[uVar10 * 5],(&DAT_2016e01a)[uVar10 * 5],puVar8);
            gui_draw_runs(uVar5,(&DAT_2016e01c)[uVar10 * 5] + DAT_20800506,
                          (&DAT_2016e01a)[uVar10 * 5] + DAT_20800504,puVar7);
            uVar10 = uVar10 + 1 & 0xff;
          } while (uVar10 < 3);
          uVar16 = 0;
          do {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              uVar17 = *(undefined4 *)(&UNK_2016dfd0 + uVar16 * 8);
            }
            else {
              puVar7 = &DAT_2016e5f0;
              uVar17 = (&DAT_2016dfcc)[uVar16 * 2];
            }
            gui_draw_runs(uVar5,(&DAT_2016e03a)[uVar16 * 5],(&DAT_2016e038)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016e03a)[uVar16 * 5] + DAT_20800506,
                          (&DAT_2016e038)[uVar16 * 5] + DAT_20800504,uVar17);
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 6);
          return;
        }
      }
      else {
        if (bVar19 == 0xc) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          uVar15 = (uint)*(byte *)(param_1 + 0x9b);
          FUN_2012b0f0(1,0xa1009e);
          gui_draw_runs(uVar5,DAT_2080078a,DAT_20800788,&DAT_2016ea28);
          uVar16 = 0;
          do {
            if (uVar16 == uVar14) {
              puVar7 = &DAT_2016e5e0;
              uVar17 = (&DAT_2016eac0)[uVar16 * 2];
            }
            else {
              uVar17 = *(undefined4 *)(&UNK_2016eabc + uVar16 * 8);
              puVar7 = &DAT_2016e5f0;
            }
            gui_draw_runs(uVar5,(&DAT_2016ea3a)[uVar16 * 5],(&DAT_2016ea38)[uVar16 * 5],puVar7);
            gui_draw_runs(uVar5,(&DAT_2016ea3a)[uVar16 * 5] + DAT_20800786,
                          (&DAT_2016ea38)[uVar16 * 5] + DAT_20800784,uVar17);
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 0xc);
          fb_draw_round_frame(uVar5,(&DAT_2016ea3a)[(uVar15 & 0xff) * 5],
                              (&DAT_2016ea38)[(uVar15 & 0xff) * 5],0x6e,0x32,3,0xf980);
          return;
        }
        if (bVar19 == 0xd) {
          uVar5 = fb_get_layer_addr(DAT_208085bc);
          FUN_2012b0f0(0,0xa1009e);
          gui_draw_runs(uVar5,0xa9,0x163,&DAT_2016ed28,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
                        unaff_r9,unaff_r10);
          if ((4 < uVar14) && (uVar14 != 5)) {
            uVar14 = 4;
          }
          uVar16 = 0;
          do {
            iVar11 = (&DAT_2016ed38)[uVar16 * 2];
            if (iVar11 != 0) {
              if (uVar16 == uVar14) {
                iVar11 = *(int *)(&UNK_2016ed3c + uVar16 * 8);
              }
              gui_draw_runs(uVar5,(&DAT_2016ed6a)[uVar16 * 5],(&DAT_2016ed68)[uVar16 * 5]);
              gui_draw_runs(uVar5,(&DAT_2016ed6a)[uVar16 * 5] + DAT_2080065a,
                            (&DAT_2016ed68)[uVar16 * 5] + DAT_20800658,iVar11);
            }
            uVar16 = uVar16 + 1 & 0xff;
          } while (uVar16 < 6);
          return;
        }
      }
    }
    return;
  }
LAB_2012bb34:
  uVar5 = fb_get_layer_addr(DAT_208085bc);
  if (bVar19 == 7) {
    ppuVar13 = &PTR_DAT_20802208;
  }
  else {
    ppuVar13 = &PTR_DAT_20802244;
  }
  fb_fill_rect(uVar5,0x4a69,0xb8,0x169,0x1b7,0x128,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,
               unaff_r9,unaff_r10,unaff_lr);
  iVar11 = 0;
  do {
    psVar12 = &DAT_2016da0c + iVar11 * 5;
    fb_fill_rect(uVar5,0x821,(&DAT_2016da0e)[iVar11 * 5] + 1,*psVar12 + 1,
                 (&DAT_2016da10)[iVar11 * 5] + -2,(&DAT_2016da12)[iVar11 * 5] + -2,unaff_r4,unaff_r5
                 ,unaff_r6,unaff_r7,unaff_r8,unaff_r9,unaff_r10,unaff_lr);
    gui_draw_runs(uVar5,(&DAT_2016da0e)[iVar11 * 5],*psVar12,(&PTR_DAT_208021cc)[iVar11]);
    gui_draw_runs(uVar5,(&DAT_2016daae)[iVar11 * 2] + (&DAT_2016da0e)[iVar11 * 5],
                  *psVar12 + (&DAT_2016daac)[iVar11 * 2],ppuVar13[iVar11]);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0xf);
  return;
}


// ===== FUN_2012c2d8 @ 2012c2d8 (328 bytes)

undefined4 FUN_2012c2d8(byte *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *param_1;
  if ((bVar1 != *param_2) || (bVar1 == 0x40)) {
    return 0xffffffff;
  }
  if (bVar1 < 0x41) {
    if (bVar1 == 0x37) {
      cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0x1a7);
    }
    else if (bVar1 < 0x38) {
      if (bVar1 == 0x30) {
        cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,7);
        if (cVar2 != '\0') {
          return 1;
        }
        if (param_1[0x98] == 5) {
          if ((param_1[5] & 0x40) != (param_2[5] & 0x40)) {
            return 1;
          }
          return 0;
        }
        return 0;
      }
      if (bVar1 != 0x31) {
        return 0xffffffff;
      }
      cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,10);
    }
    else {
      if (bVar1 != 0x39) {
        return 0xffffffff;
      }
      cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0x50);
    }
  }
  else if (bVar1 == 0x41) {
    cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0xad);
  }
  else {
    if (bVar1 == 0x50 || bVar1 == 0x62) {
      return 0xffffffff;
    }
    if (bVar1 != 0x70) {
      return 0xffffffff;
    }
    cVar2 = FUN_2015507c(param_1 + 0x98,param_2 + 0x98,0x4a);
  }
  if (cVar2 != '\0') {
    return 1;
  }
  return 0;
}


// ===== FUN_2012c4a0 @ 2012c4a0 (248 bytes)

void FUN_2012c4a0(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (DAT_2080048e != '\0' && DAT_2080048e != '\x03') {
    return;
  }
  if (*(byte *)(param_1 + 0x24) >> 4 == 0) {
    iVar2 = audio_error();
    if (iVar2 == -1) {
      if ((((DAT_208f0b57 < 2) || (DAT_208f0b57 == 4 || DAT_208f0b57 == 5)) ||
          (DAT_208f0b57 == 6 || DAT_208f0b57 == 7)) && (iVar2 = FUN_20103ba0(), iVar2 == 0)) {
        FUN_20124744(0xffffffff);
      }
      audio_clear_error();
    }
    if (DAT_20800490 == '\0' && DAT_2080048f == '\0') {
      return;
    }
  }
  iVar2 = audio_state();
  if ((((iVar2 == 0) && (iVar2 = audio_error(), iVar2 == 0)) &&
      ((bVar1 = *(byte *)(param_1 + 0x2d), bVar1 < 2 ||
       ((bVar1 == 4 || bVar1 == 5 || (bVar1 == 6 || bVar1 == 7)))))) &&
     (iVar2 = FUN_20103ba0(), iVar2 == 0)) {
    FUN_20124744(0xffffffff);
    return;
  }
  DAT_2080048e = 3;
  FUN_2012910c(param_1);
  return;
}


// ===== FUN_2012c6c4 @ 2012c6c4 (108 bytes)

void FUN_2012c6c4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if ((param_3 == 0) && ((*(byte *)(param_1 + 0x12) & 0xf0) == (*(byte *)(param_2 + 0x12) & 0xf0)))
  {
    return;
  }
  uVar1 = (uint)(*(byte *)(param_1 + 0x12) >> 4);
  if (5 < uVar1) {
    uVar1 = 5;
  }
  thunk_FUN_2015d1c4(uVar1);
  if (DAT_20800480 != '\0') {
    return;
  }
  DAT_208085b0 = (ushort)(byte)(&UNK_203a70a8)[uVar1];
  return;
}


// ===== FUN_2012c71c @ 2012c71c (912 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2012c71c(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar3;
  uint uVar4;
  uint unaff_r4;
  uint unaff_r5;
  int iVar5;
  int iVar6;
  uint in_stack_ffffffd0;
  undefined2 uVar2;
  
  iVar3 = fb_get_layer_addr(0);
  if (DAT_20800480 == '\0') {
    iVar5 = FUN_20133640();
  }
  else {
    iVar5 = 0;
  }
  if (param_2 == 0) {
    in_stack_ffffffd0 = (uint)DAT_208004d0;
    unaff_r5 = _DAT_20800728;
    uVar1 = DAT_20800736;
    uVar2 = DAT_20800734;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        unaff_r5 = ((uint)DAT_20800726 + (uint)DAT_2080073a) * 0x10000 |
                   (uint)DAT_20800724 + (uint)DAT_20800738 & 0xffff;
        unaff_r4 = _DAT_20800730;
      }
      goto LAB_2012c814;
    }
    unaff_r5 = ((uint)DAT_20800722 + (uint)DAT_2080073a) * 0x10000 |
               (uint)DAT_20800720 + (uint)DAT_20800738 & 0xffff;
    uVar1 = DAT_2080072e;
    uVar2 = DAT_2080072c;
  }
  unaff_r4 = CONCAT22(uVar1,uVar2);
LAB_2012c814:
  iVar6 = iVar3;
  if (iVar5 != 0) {
    iVar6 = iVar5 + (unaff_r5 >> 0x10) * -0x640;
  }
  if (param_2 == 0) {
    if (in_stack_ffffffd0 == 3) {
      fb_fill_rect(iVar6,0x2124,unaff_r5 >> 0x10,unaff_r5 & 0xffff,unaff_r4 & 0xffff,
                   unaff_r4 >> 0x10);
      FUN_20132f44(0);
      uVar4 = *(byte *)(param_1 + 3) & 3;
      if (2 < uVar4) {
        uVar4 = 2;
      }
      gui_draw_runs(iVar6,DAT_2080073e,DAT_2080073c,*(undefined4 *)(&DAT_20808524 + uVar4 * 4));
    }
  }
  else if (param_2 == 2) {
    fb_clear_rect(iVar6,unaff_r5 >> 0x10,unaff_r5 & 0xffff,unaff_r4 & 0xffff,unaff_r4 >> 0x10);
    FUN_20132f44(0);
    gui_draw_runs(iVar6,DAT_20800722 + DAT_2080073a,DAT_20800720 + DAT_20800738,&DAT_2016e380);
    uVar4 = *(byte *)(param_1 + 0x71) & 7;
    if (5 < uVar4) {
      uVar4 = 5;
    }
    gui_draw_runs(iVar6,DAT_2080074a + DAT_20800722,DAT_20800720 + DAT_20800748,
                  (&PTR_DAT_20802da0)[uVar4]);
    gui_draw_runs(iVar6,DAT_2080074e + DAT_20800722,DAT_20800720 + DAT_2080074c,&DAT_2016e390);
  }
  else if (param_2 == 3) {
    fb_clear_rect(iVar6,unaff_r5 >> 0x10,unaff_r5 & 0xffff,unaff_r4 & 0xffff,unaff_r4 >> 0x10);
    FUN_20132f44(0);
    gui_draw_runs(iVar6,DAT_20800726 + DAT_2080073a,DAT_20800724 + DAT_20800738,&DAT_2016e360);
    gui_draw_runs(iVar6,DAT_20800742 + DAT_20800726,DAT_20800724 + DAT_20800740,&DAT_2016e370);
    uVar4 = (*(byte *)(param_1 + 0x71) & 0x7f) >> 5;
    if (2 < uVar4) {
      uVar4 = 2;
    }
    gui_draw_runs(iVar6,DAT_20800746 + DAT_20800726,DAT_20800724 + DAT_20800744,
                  *(undefined4 *)(&DAT_20802d94 + uVar4 * 4));
  }
  if (iVar5 != 0) {
    iVar6 = 0;
    iVar5 = iVar5 + (unaff_r5 & 0xffff) * 2;
    iVar3 = iVar3 + ((unaff_r5 & 0xffff) + (unaff_r5 >> 0x10) * 800) * 2;
    if (unaff_r4 >> 0x10 != 0) {
      do {
        memcpy(iVar3,iVar5,(unaff_r4 & 0xffff) << 1);
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x640;
        iVar3 = iVar3 + 0x640;
      } while (iVar6 < (int)(unaff_r4 >> 0x10));
    }
  }
  return;
}


// ===== FUN_2012caac @ 2012caac (180 bytes)

void FUN_2012caac(int param_1,int param_2,int param_3)

{
  if (((param_3 == 0) && (*(char *)(param_1 + 1) == *(char *)(param_2 + 1))) &&
     (*(char *)(param_1 + 2) == *(char *)(param_2 + 2))) {
    if ((((*(byte *)(param_1 + 3) & 7) == (*(byte *)(param_2 + 3) & 7)) &&
        ((byte)(*(byte *)(param_1 + 3) * '@') == (byte)(*(byte *)(param_2 + 3) * '@'))) &&
       (*(char *)(param_1 + 0x71) == *(char *)(param_2 + 0x71))) {
      return;
    }
  }
  if (DAT_208004d0 == '\x03') {
    FUN_2012c71c(param_1,0);
    return;
  }
  if (DAT_20800482 != '\x01') {
    return;
  }
  FUN_2012c71c(param_1,2);
  FUN_2012c71c(param_1,3);
  return;
}


// ===== FUN_2012cb60 @ 2012cb60 (168 bytes)

void FUN_2012cb60(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = 0;
    if (param_4 != 0) {
      iVar1 = iVar2 + -8;
    }
    if (iVar1 < 0 == (param_4 != 0 && SBORROW4(iVar2,8))) break;
    if (iVar2 == 6 || iVar2 == 3) {
      uVar3 = param_3 + 4 & 0xffff;
      gui_draw_runs(param_1,param_2,uVar3,DAT_20800924);
      param_3 = uVar3 - 8 & 0xffff;
    }
    gui_draw_runs(param_1,param_2,param_3,(&PTR_DAT_2080092c)[param_4 % 10]);
    FUN_20132f44(0);
    iVar2 = iVar2 + 1;
    param_3 = param_3 - 8 & 0xffff;
    param_4 = param_4 / 10;
  }
  return;
}


// ===== FUN_2012cf30 @ 2012cf30 (900 bytes)

void FUN_2012cf30(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int iVar10;
  short *psVar11;
  uint uVar12;
  int iVar13;
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
      (iVar8 = FUN_2015507c(param_1 + 0x75,param_2 + 0x75,0x10), iVar8 == 0)))) {
    return;
  }
  if (DAT_20800482 == '\0') {
    if (1 < DAT_208004d0) {
      return;
    }
    bVar9 = false;
  }
  else {
    if (DAT_20800482 != '\x01') {
      return;
    }
    if (1 < DAT_208004d0) {
      return;
    }
    bVar9 = true;
  }
  local_30 = fb_get_layer_addr(0);
  if (DAT_20800480 == '\0') {
    iVar8 = FUN_20133640();
  }
  else {
    iVar8 = 0;
  }
  cVar1 = DAT_208004d1;
  if (bVar9) {
    if (!bVar9) {
      return;
    }
    psVar11 = &DAT_20800754;
  }
  else {
    psVar11 = (short *)0x20800750;
  }
  uVar12 = *(byte *)(param_1 + 0x11) & 0x1f;
  uVar3 = (uint)(ushort)psVar11[1];
  if (9 < uVar12) {
    uVar12 = 9;
  }
  local_34 = 800;
  local_40 = local_30;
  if (iVar8 != 0) {
    local_40 = iVar8 + uVar3 * -0x640;
  }
  fb_clear_rect(local_40,uVar3,0,800,9);
  FUN_20132f44(0);
  if (cVar1 == '\0') {
    local_3b = *(undefined1 *)(param_1 + 0x7e);
    local_3a = *(undefined1 *)(param_1 + 0x7f);
    local_3c = *(byte *)(param_1 + 0x7d) & 0xf;
    local_39 = *(undefined1 *)(param_1 + 0x80);
    uVar6 = be32_load(&local_3c);
    FUN_2012cb60(local_40,psVar11[1],*psVar11 + DAT_20800758,uVar6);
    iVar5 = 0;
    local_2c = uVar12 * 0x10 + 0x20802dd0;
    iVar4 = uVar12 * 0x18 + 0x20802e70;
    do {
      uVar12 = 0;
      sVar2 = *(short *)(local_2c + iVar5 * 4) + *psVar11;
      local_38 = (uint)(ushort)psVar11[1];
      iVar13 = iVar4 + iVar5 * 6;
      iVar10 = FUN_20155122(iVar13);
      if (iVar10 != 0) {
        do {
          gui_draw_runs(local_40,local_38,sVar2,
                        *(undefined4 *)(&DAT_2080086c + (uint)*(byte *)(iVar13 + uVar12) * 4));
          sVar2 = sVar2 + 8;
          uVar12 = uVar12 + 1;
          uVar7 = FUN_20155122(iVar13);
        } while (uVar12 < uVar7);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  else {
    local_3b = *(undefined1 *)(param_1 + 0x82);
    local_3a = *(undefined1 *)(param_1 + 0x83);
    local_3c = *(byte *)(param_1 + 0x81) & 0xf;
    local_39 = *(undefined1 *)(param_1 + 0x84);
    iVar4 = be32_load(&local_3c);
    iVar5 = FUN_20156260((*(int *)(&UNK_2016d6e8 + uVar12 * 4) + iVar4) - iVar4,5);
    iVar10 = 0;
    do {
      FUN_2012cb60(local_40,psVar11[1],*psVar11 + (&DAT_20802db8)[iVar10 * 2],iVar5 * iVar10 + iVar4
                  );
      iVar10 = iVar10 + 1;
    } while (iVar10 < 6);
  }
  if (iVar8 != 0) {
    iVar5 = 0;
    iVar10 = local_30 + uVar3 * 0x640;
    iVar4 = local_34 << 1;
    do {
      memcpy(iVar10,iVar8,iVar4);
      iVar5 = iVar5 + 1;
      iVar10 = iVar10 + 0x640;
      iVar8 = iVar8 + 0x640;
    } while (iVar5 < 9);
  }
  return;
}


// ===== FUN_2012d000 @ 2012d000 (412 bytes)

void FUN_2012d000(int param_1,short param_2,short param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  uint uVar2;
  short *psVar3;
  ushort uVar4;
  
  uVar1 = fb_get_layer_addr(0);
  uVar2 = 0;
  FUN_20132f44(0);
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
      fb_fill_box_t(uVar1,psVar3[1] + param_2,psVar3[4] * uVar4 + *psVar3 + param_3,psVar3[2],1,
                    0x3186);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (ushort)psVar3[3]);
  }
  uVar4 = 0;
  if (psVar3[8] != 0) {
    do {
      fb_fill_box(uVar1,psVar3[9] * uVar4 + psVar3[6] + param_2,psVar3[5] + param_3,psVar3[7],1,
                  0x632c);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (ushort)psVar3[8]);
  }
  if (param_1 == 3) {
    return;
  }
  fb_fill_box(uVar1,psVar3[9] * uVar4 + psVar3[6] + param_2,psVar3[5] + param_3,psVar3[7],1,0xffff);
  FUN_20132f44(0);
  return;
}

