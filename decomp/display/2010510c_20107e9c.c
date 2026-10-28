// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2010510c @ 2010510c (76 bytes)

char * FUN_2010510c(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  do {
    cVar1 = *param_1;
    if (cVar1 == *param_2) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        if (param_2[iVar2] == '\0') {
          return param_1;
        }
      } while (param_1[iVar2] == param_2[iVar2]);
    }
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return (char *)0x0;
}


// ===== wav_check_header @ 20105158 (292 bytes)

undefined4 wav_check_header(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_2015507c(param_1,&DAT_20105280,4);
    if ((((((iVar1 == 0) && (iVar1 = FUN_2015507c(param_1 + 8,&DAT_20105288,4), iVar1 == 0)) &&
          (iVar1 = FUN_2015507c(param_1 + 0x24,&DAT_20105290,4), iVar1 == 0)) &&
         ((iVar1 = FUN_2015507c(param_1 + 0x2c,&DAT_20105298,4), iVar1 == 0 &&
          (iVar1 = FUN_2015507c(param_1 + 0xc,&DAT_201052a0,4), iVar1 == 0)))) &&
        ((iVar1 = FUN_2015507c(param_1 + 0x54,&DAT_201052a8,4), iVar1 == 0 &&
         ((param_3 != 2 || (iVar1 = FUN_2015507c(param_2,param_1 + 0x34,7), iVar1 == 0)))))) &&
       ((*(int *)(param_1 + 0x30) == 0x20 && (*(int *)(param_1 + 0x10) == 0x10)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffffd;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== wav_open_read @ 201052b0 (588 bytes)

undefined4 wav_open_read(int *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [20];
  ushort local_64;
  ushort local_62;
  int local_60;
  undefined4 local_5c;
  ushort local_56;
  undefined1 auStack_44 [36];
  int local_20;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if (DAT_208000e0 != 0) {
    return 0xfffffffe;
  }
  if (param_2 == 1) {
    pcVar7 = "I:\\FT-710\\PlayList";
  }
  else {
    if (param_2 != 2) {
      return 0xfffffffe;
    }
    pcVar7 = "I:\\FT-710\\MESSAGE";
  }
  iVar1 = FUN_20103ba0();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    return 0xfffffffe;
  }
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  FUN_201550dc(&local_b8,pcVar7);
  FUN_2015515c(&local_b8,&DAT_20105524);
  FUN_2015515c(&local_b8,*param_1);
  FUN_2015515c(&local_b8,&DAT_20105528);
  DAT_208000e0 = fs_fopen(&local_b8,&DAT_20105530);
  if (DAT_208000e0 == 0) {
    return 0xfffffffe;
  }
  iVar1 = fs_fread(auStack_78,0x5c,1,DAT_208000e0);
  if (iVar1 == 0) {
    play_close();
    return 0xfffffffe;
  }
  iVar1 = wav_check_header(auStack_78,*param_1,param_2);
  if (iVar1 != 0) {
    play_close();
    return 0xfffffffd;
  }
  param_1[3] = (uint)local_64;
  param_1[4] = (uint)local_62;
  param_1[5] = local_60;
  param_1[6] = (uint)local_56;
  param_1[7] = local_20;
  puVar2 = (undefined1 *)FUN_2010510c(auStack_44,&DAT_20105534);
  if (puVar2 == (undefined1 *)0x0) {
    iVar1 = param_1[1];
    if (iVar1 == 0) goto LAB_20105468;
    puVar2 = auStack_44;
  }
  else {
    *puVar2 = 0;
    if (param_1[1] != 0) {
      FUN_201550dc(param_1[1],auStack_44);
    }
    iVar1 = param_1[2];
    if (iVar1 == 0) goto LAB_20105468;
    puVar2 = puVar2 + 1;
  }
  FUN_201550dc(iVar1,puVar2);
LAB_20105468:
  iVar1 = param_1[8];
  if (iVar1 != 0) {
    uVar3 = FUN_20156260(local_20,local_5c);
    uVar5 = (uint)((ulonglong)uVar3 * 0x91a2b3c5 >> 0x20);
    uVar6 = (uVar5 & 0x7ffff) >> 0xb;
    if (99 < uVar6) {
      uVar6 = 99;
    }
    uVar3 = uVar3 + (short)(ushort)(byte)((uVar5 << 0xd) >> 0x18) * -0xe10;
    uVar4 = ((uint)((ulonglong)uVar3 * 0x88888889 >> 0x20) & 0x1fff) >> 5;
    uVar5 = uVar4;
    if (0x3b < uVar4) {
      uVar5 = 0x3b;
    }
    uVar3 = uVar3 + uVar4 * -0x3c & 0xff;
    if (0x3b < uVar3) {
      uVar3 = 0x3b;
    }
    FUN_20154a30(iVar1,10,"%02d:%02d:%02d",uVar6,uVar5,uVar3);
  }
  return 0;
}


// ===== wav_list_dir @ 20105550 (576 bytes)

/* scans the folder for *.wav, up to 255 entries of 0x34 bytes, sorted */

int wav_list_dir(int param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int iStack_28;
  
  bVar1 = false;
  local_30 = param_1;
  local_2c = param_2;
  iStack_28 = param_3;
  iVar3 = FUN_20103ba0();
  if (iVar3 == 0) {
    iVar3 = -1;
  }
  else {
    if (param_3 == 1) {
      pcVar4 = "I:\\FT-710\\PlayList";
    }
    else {
      if (param_3 != 2) {
        return -3;
      }
      pcVar4 = "I:\\FT-710\\MESSAGE";
    }
    local_34 = FUN_2014c410(pcVar4);
    if (local_34 == 0) {
      iVar3 = -4;
    }
    else {
      FUN_20126160(1);
      iVar5 = FUN_20111174(0x33cc);
      iVar3 = 0;
LAB_201055b8:
      piVar6 = (int *)FUN_2014ca4c(local_34);
      if (piVar6 != (int *)0x0) {
        iVar7 = FUN_201476f0((int)*(char *)(*piVar6 + 0xb),0);
        if (iVar7 == 0) {
          iVar7 = (int)piVar6 + 10;
          if (piVar6 == (int *)0xfffffff6) goto LAB_20105660;
          uVar8 = FUN_20155122(iVar7);
          uVar2 = uVar8;
          if (uVar8 < 0x15) {
            do {
              uVar2 = uVar2 - 1;
              if ((int)uVar2 < 1) goto LAB_201055b8;
            } while ((*(char *)(iVar7 + uVar2) != '.') ||
                    (iVar9 = FUN_2014e208(iVar7 + uVar2,&DAT_20105528), iVar9 != 0));
            iVar9 = iVar3 + 1;
            if ((0xff < iVar9) || (local_2c < iVar9)) {
              bVar1 = true;
              goto LAB_20105660;
            }
            iVar13 = iVar5 + iVar3 * 0x34;
            FUN_2014e2e4(iVar13,iVar7,uVar8 - 4);
            local_44 = 0;
            local_4c = 0;
            local_48 = 0;
            local_40 = 0;
            local_3c = 0;
            local_54 = iVar13 + 0x10;
            local_50 = iVar13 + 0x1b;
            local_38 = iVar13 + 0x26;
            local_58 = iVar13;
            iVar3 = wav_open_read(&local_58,param_3);
            *(int *)(iVar13 + 0x30) = iVar3;
            if (iVar3 == 0) {
              FUN_201050ac();
            }
            iVar3 = (int)(short)iVar9;
          }
        }
        goto LAB_201055b8;
      }
LAB_20105660:
      thunk_FUN_2014c474(local_34);
      if (bVar1) {
        iVar3 = -5;
      }
      else if (iVar3 < 1) {
        iVar3 = -4;
      }
      else {
        FUN_20154fca(iVar5,iVar3,0x34,FUN_2014e208);
        memclr(local_30,0x33cc);
        iVar7 = 0;
        do {
          puVar15 = (undefined4 *)(iVar5 + iVar7 * 0x34);
          puVar14 = (undefined4 *)(local_30 + iVar7 * 0x34);
          uVar10 = puVar15[1];
          uVar11 = puVar15[2];
          uVar12 = puVar15[3];
          *puVar14 = *puVar15;
          puVar14[1] = uVar10;
          puVar14[2] = uVar11;
          puVar14[3] = uVar12;
          FUN_20155310(puVar14 + 4,puVar15 + 4,0xb);
          memcpy((int)puVar14 + 0x1b,(int)puVar15 + 0x1b,0xb);
          memcpy((int)puVar14 + 0x26,(int)puVar15 + 0x26,9);
          iVar7 = iVar7 + 1;
          puVar14[0xc] = puVar15[0xc];
        } while (iVar7 < iVar3);
      }
      FUN_20133620();
      FUN_20126160(0);
    }
  }
  return iVar3;
}


// ===== audio_state @ 20105790 (12 bytes)

/* 0 idle, 2 recording, 4 playing, 8 paused, 0x10/0x20 seeking */

undefined4 audio_state(void)

{
  return DAT_208000cc;
}


// ===== play_stop @ 2010579c (60 bytes)

void play_stop(void)

{
  int iVar1;
  
  DAT_208000d4 = 0;
  DAT_208000ec = 0;
  DAT_208000f0 = 0;
  do {
    FUN_201525f8(10);
    iVar1 = audio_state();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== wav_delete @ 201057d8 (232 bytes)

/* deletes <dir>\<name>.wav and rescans */

undefined4 wav_delete(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_a0 [132];
  
  memclr(auStack_a0,0x80);
  if (param_1 == 0 || param_2 == 0) {
LAB_20105820:
    uVar1 = 0xfffffffc;
  }
  else {
    if (param_4 == 1) {
      pcVar4 = "I:\\FT-710\\PlayList";
    }
    else {
      if (param_4 != 2) goto LAB_20105820;
      pcVar4 = "I:\\FT-710\\MESSAGE";
    }
    iVar2 = FUN_20103ba0();
    if (iVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      iVar2 = audio_state(iVar2);
      if (iVar2 == 8) {
        play_stop();
        iVar2 = 0;
        do {
          iVar3 = audio_state();
          if (iVar3 == 0) break;
          FUN_201525f8(10);
          iVar2 = iVar2 + 1;
        } while (iVar2 < 10);
      }
      FUN_201550dc(auStack_a0,pcVar4);
      FUN_2015515c(auStack_a0,&DAT_20105524);
      FUN_2015515c(auStack_a0,param_1);
      iVar2 = FUN_20143b20(auStack_a0);
      if (iVar2 == 0) {
        uVar1 = wav_list_dir(param_2,param_3,param_4);
        return uVar1;
      }
      uVar1 = 0xfffffffa;
    }
  }
  return uVar1;
}


// ===== audio_error @ 201058c0 (12 bytes)

undefined4 audio_error(void)

{
  return DAT_208000d8;
}


// ===== audio_clear_error @ 201058cc (16 bytes)

void audio_clear_error(void)

{
  DAT_208000d8 = 0;
  return;
}


// ===== rec_start @ 201058dc (288 bytes)

/* (name16, freq digits, mode index, kind): sets event flag 2 */

void rec_start(int param_1,undefined1 *param_2,uint param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0 && param_2 != (undefined1 *)0x0) && param_3 < 0x10) {
    DAT_2081104c = 0;
    DAT_20811050 = 0;
    DAT_20811054 = 0;
    DAT_20811058 = 0;
    DAT_2081105c = 0;
    DAT_20811060 = 0;
    DAT_20811064 = 0;
    DAT_20811068 = 0;
    DAT_2081106c = 0;
    DAT_20811070 = 0;
    DAT_20811074 = 0;
    DAT_20811078 = 0;
    DAT_2081107c = 0;
    memcpy(&DAT_2081104c,param_1,0x10);
    sprintf(&DAT_2081105c,"%c%c.%c%c%c.%c%c%c",*param_2,param_2[1],param_2[2],param_2[3],param_2[4],
            param_2[5],param_2[6],param_2[7]);
    FUN_2014e2e4(0x20811067,&UNK_20165274 + param_3 * 10,10);
    DAT_208000d0 = 1;
    DAT_208000b3 = param_4;
    audio_clear_error();
    iVar1 = itron_set_flg(DAT_208000c8,2);
    do {
      if (iVar1 != 0) break;
      FUN_201525f8(10);
      iVar2 = audio_state();
      iVar1 = DAT_208000d8;
    } while (iVar2 != 2);
  }
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== rec_stop @ 20105a20 (52 bytes)

void rec_stop(void)

{
  int iVar1;
  
  DAT_208000d0 = 0;
  do {
    FUN_201525f8(10);
    iVar1 = audio_state();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_start @ 20105a54 (148 bytes)

/* (name16, kind): sets event flag 4 */

void play_start(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  
  memcpy(&DAT_20810fbc,param_1,0x10);
  DAT_208000d4 = 1;
  DAT_208000b3 = param_2;
  audio_clear_error();
  iVar1 = itron_set_flg(DAT_208000c8,4);
  if (iVar1 == 0) {
    do {
      FUN_201525f8(10);
      iVar1 = audio_state();
      if ((iVar1 == 4) || (DAT_208000d8 != 0)) goto LAB_20105ab4;
      iVar1 = audio_state();
    } while ((iVar1 != 0) || (DAT_208000b4 == '\0'));
    DAT_208000b4 = '\0';
  }
LAB_20105ab4:
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_resume @ 20105ae8 (64 bytes)

void play_resume(void)

{
  int iVar1;
  
  DAT_208000d4 = 1;
  do {
    FUN_201525f8(10);
    iVar1 = audio_state();
    if (iVar1 == 4) break;
    iVar1 = audio_state();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_pause @ 20105b28 (64 bytes)

void play_pause(void)

{
  int iVar1;
  
  DAT_208000d4 = 2;
  do {
    FUN_201525f8(10);
    iVar1 = audio_state();
    if (iVar1 == 8) break;
    iVar1 = audio_state();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_ffwd @ 20105b68 (64 bytes)

/* +5 s (320000 bytes) */

void play_ffwd(void)

{
  int iVar1;
  
  DAT_208000d4 = 3;
  do {
    FUN_201525f8(10);
    iVar1 = audio_state();
    if (iVar1 == 4) break;
    iVar1 = audio_state();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_rewind @ 20105ba8 (64 bytes)

/* -5 s */

void play_rewind(void)

{
  int iVar1;
  
  DAT_208000d4 = 4;
  do {
    FUN_201525f8(10);
    iVar1 = audio_state();
    if (iVar1 == 4) break;
    iVar1 = audio_state();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== play_progress @ 20105be8 (144 bytes)

/* "%02d:%02d:%02d" + percent */

void play_progress(undefined2 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_208000f0;
  if (DAT_208000e4 < DAT_208000f0) {
    uVar2 = DAT_208000e4;
  }
  uVar1 = (uVar2 / 64000) % 0xe10;
  sprintf(param_2,"%02d:%02d:%02d",(uVar2 / 64000) / 0xe10,uVar1 / 0x3c,uVar1 % 0x3c);
  uVar2 = FUN_20156260(uVar2,DAT_208000e4 / 100);
  if (100 < uVar2) {
    uVar2 = 100;
  }
  *param_1 = (short)uVar2;
  return;
}


// ===== audio_codec_init @ 20105c78 (156 bytes)

/* task "audio_codec" */

void audio_codec_init(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_10 = 2;
  uStack_c = 0;
  local_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (0 < iVar1) {
    DAT_2081104c = 0;
    DAT_20811050 = 0;
    DAT_20811054 = 0;
    DAT_20811058 = 0;
    DAT_2081105c = 0;
    DAT_20811060 = 0;
    DAT_20811064 = 0;
    DAT_20811068 = 0;
    DAT_2081106c = 0;
    DAT_20811070 = 0;
    DAT_20811074 = 0;
    DAT_20811078 = 0;
    DAT_2081107c = 0;
    DAT_208000c8 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_20165314);
    if (0 < iVar1) {
      itron_sta_tsk(iVar1,0);
    }
  }
  return;
}


// ===== FUN_20105d14 @ 20105d14 (16 bytes)

undefined4 FUN_20105d14(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffffd;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== play_read_block @ 20105d24 (444 bytes)

/* reads 0xC80 bytes, keeps the left channel, header {count/2, 0x1234} */

undefined4 play_read_block(int param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_fb8 [4000];
  
  iVar1 = FUN_20103ba0();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    play_close();
    return 0xfffffffe;
  }
  if (param_1 == 0) {
    return 0xfffffffb;
  }
  if (param_2 == (undefined1 *)0x0) {
    play_close();
    return 0xffffffff;
  }
  if (DAT_208000e0 != 0) {
    FUN_2015525c(param_2,4000,0xf0);
    FUN_2015525c(local_fb8,4000,0xf0);
    uVar2 = fs_fread(local_fb8,1,0xc80,DAT_208000e0);
    if (uVar2 != 0) {
      uVar6 = uVar2 >> 1;
      uVar5 = 0;
      iVar1 = 0;
      if (uVar2 >> 1 != 0) {
        do {
          uVar4 = uVar5 + 2;
          param_2[uVar5 + 4] = local_fb8[iVar1];
          param_2[uVar5 + 5] = local_fb8[iVar1 + 1];
          uVar5 = uVar4;
          iVar1 = iVar1 + 4;
        } while (uVar4 < uVar2 >> 1);
      }
      if (DAT_208000b5 == '\0') {
        DAT_208000b5 = '\x01';
        FUN_2015525c(local_fb8,4000,0xf0);
        uVar2 = fs_fread(local_fb8,1,0xc80,DAT_208000e0);
        if (uVar2 != 0) {
          uVar5 = 0;
          iVar1 = 0;
          if (uVar2 >> 1 != 0) {
            do {
              iVar3 = uVar6 + uVar5;
              uVar5 = uVar5 + 2;
              param_2[iVar3 + 4] = local_fb8[iVar1];
              param_2[iVar3 + 5] = local_fb8[iVar1 + 1];
              iVar1 = iVar1 + 4;
            } while (uVar5 < uVar2 >> 1);
          }
          uVar6 = uVar6 + (uVar2 >> 1);
        }
      }
      *param_2 = (char)(uVar6 >> 1);
      param_2[1] = (char)(uVar6 >> 9);
      param_2[2] = 0x34;
      param_2[3] = 0x12;
      return 0;
    }
    DAT_208000bc = FUN_2014d95c();
    if (DAT_208000bc == -0xe) {
      return 0xfffffffb;
    }
  }
  play_close();
  return 0xfffffffe;
}


// ===== play_advance @ 20105ee0 (76 bytes)

void play_advance(void)

{
  uint uVar1;
  
  uVar1 = DAT_208000e4 - DAT_208000ec;
  if (uVar1 < 4000) {
    if (uVar1 == 0) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc80;
  }
  DAT_208000ec = DAT_208000ec + uVar1;
  return;
}


// ===== play_seek @ 20105f2c (116 bytes)

/* fseek(pos + 0x5C) */

undefined4 play_seek(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_208000c0 = param_1;
  if (DAT_208000e0 == 0) {
    play_close();
    return 0xfffffffe;
  }
  iVar1 = FUN_20103ba0();
  if (iVar1 != 0) {
    iVar1 = fs_fseek(DAT_208000e0,param_1 + 0x5c,0);
    uVar2 = 0;
    if (iVar1 != 0) {
      DAT_208000bc = FUN_2014d95c();
      play_close();
      uVar2 = 0xfffffffe;
    }
    return uVar2;
  }
  DAT_208000d8 = 0xffffffff;
  play_close();
  return 0xfffffffe;
}


// ===== play_prime @ 20105fa0 (120 bytes)

int play_prime(int param_1)

{
  int iVar1;
  undefined4 unaff_r7;
  bool bVar2;
  
  iVar1 = 0;
  if (param_1 == 2) {
    unaff_r7 = play_advance();
    iVar1 = play_read_block(unaff_r7,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8);
    bVar2 = iVar1 == -5;
    if (bVar2) {
      iVar1 = 0;
    }
    if (!bVar2 && iVar1 != 0) {
      DAT_208000b8 = DAT_208000b8 + 1;
    }
  }
  FUN_20101030(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8,unaff_r7);
  return iVar1;
}


// ===== rec_close_abort @ 20106018 (72 bytes)

/* WARNING: Removing unreachable block (ram,0x201552fe) */
/* WARNING: Removing unreachable block (ram,0x201552f4) */
/* WARNING: Removing unreachable block (ram,0x201552e4) */
/* WARNING: Removing unreachable block (ram,0x201552ea) */
/* WARNING: Removing unreachable block (ram,0x201552fc) */
/* WARNING: Removing unreachable block (ram,0x20155302) */
/* WARNING: Removing unreachable block (ram,0x20155308) */
/* WARNING: Removing unreachable block (ram,0x2015530c) */

undefined4 * rec_close_abort(void)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  
  if (DAT_208000dc != 0) {
    FUN_20141ff0();
  }
  DAT_208000dc = 0;
  DAT_208000e8 = 0;
  if (DAT_20810fcc != '\0') {
    FUN_20143b20(&DAT_20810fcc);
  }
  puVar1 = (undefined4 *)&DAT_20810fcc;
  bVar3 = true;
  uVar2 = 0x60;
  do {
    if (bVar3) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1 = puVar1 + 8;
      bVar3 = 0x1f < uVar2;
      uVar2 = uVar2 - 0x20;
    }
  } while (bVar3);
  return puVar1;
}


// ===== rec_finish @ 20106060 (332 bytes)

/* pads to 4 bytes, rewrites the 0x5C-byte header sizes */

undefined4 rec_finish(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_78 [4];
  int local_74;
  uint local_20;
  undefined4 local_1c [2];
  
  uVar3 = 0;
  local_1c[0] = 0;
  iVar1 = FUN_20103ba0();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    rec_close_abort();
    return 0xfffffffe;
  }
  uVar2 = DAT_208000e8 & 0xfffffffc;
  if (uVar2 != DAT_208000e8) {
    uVar2 = uVar2 + 4;
  }
  if ((DAT_208000e8 < uVar2) &&
     (iVar1 = fs_fwrite(local_1c,uVar2 - DAT_208000e8,1,DAT_208000dc), iVar1 == 0)) {
    uVar3 = 0xfffffffe;
  }
  iVar1 = FUN_20141ff0(DAT_208000dc);
  if (iVar1 == 0) {
    DAT_208000dc = fs_fopen(&DAT_20810fcc,&DAT_201061c4);
    if (((DAT_208000dc != 0) && (iVar1 = fs_fseek(DAT_208000dc,0), iVar1 == 0)) &&
       (iVar1 = fs_fread(auStack_78,0x5c,1,DAT_208000dc), iVar1 != 0)) {
      local_74 = uVar2 + 0x54;
      local_20 = uVar2;
      iVar1 = fs_fseek(DAT_208000dc,0);
      if ((iVar1 == 0) && (iVar1 = fs_fwrite(auStack_78,0x5c,1,DAT_208000dc), iVar1 != 0)) {
        iVar1 = FUN_20141ff0(DAT_208000dc);
        DAT_208000dc = 0;
        if (iVar1 != 0) {
          uVar3 = 0xfffffffe;
        }
        DAT_208000e8 = 0;
        memclr(&DAT_20810fcc,0x80);
        return uVar3;
      }
    }
  }
  rec_close_abort();
  return 0xfffffffe;
}


// ===== rec_write @ 201061c8 (128 bytes)

undefined4 rec_write(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0 || param_2 == 0) {
    return 0xffffffff;
  }
  iVar1 = FUN_20103ba0();
  if (iVar1 == 0) {
    DAT_208000d8 = 0xffffffff;
    return 0xfffffffe;
  }
  iVar1 = fs_fwrite(param_2,param_1,1,DAT_208000dc);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffe;
  }
  else {
    DAT_208000e8 = DAT_208000e8 + param_1;
    if (0xe0000000 < DAT_208000e8) {
      DAT_208000d0 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== rec_open_wav @ 20106248 (740 bytes)

/* writes RIFF/WAVE/fmt/LIST-ICMT/data header (0x5C bytes) */

undefined4 rec_open_wav(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined4 local_60;
  int local_5c;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 auStack_44 [32];
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if ((((((char *)*param_1 != (char *)0x0) && ((char *)param_1[1] != (char *)0x0)) &&
       ((char *)param_1[2] != (char *)0x0)) &&
      ((*(char *)*param_1 != '\0' && (*(char *)param_1[1] != '\0')))) &&
     (*(char *)param_1[2] != '\0')) {
    if (DAT_208000dc == 0) {
      iVar1 = FUN_20103ba0();
      if (iVar1 == 0) {
        DAT_208000d8 = 0xffffffff;
      }
      else {
        pcVar3 = (char *)0x0;
        DAT_208000e8 = 0;
        memclr(&local_78,0x5c);
        local_74 = 0;
        local_78 = 0x46464952;
        local_70 = 0x45564157;
        local_6c = &DAT_20746d66;
        local_68 = 0x10;
        local_64 = *(undefined2 *)(param_1 + 3);
        local_62 = *(undefined2 *)(param_1 + 4);
        local_60 = param_1[5];
        local_56 = *(undefined2 *)(param_1 + 6);
        local_58 = (undefined2)((uint)(param_1[4] * param_1[6] * 0x2000) >> 0x10);
        local_5c = param_1[5] * ((param_1[4] * param_1[6] & 0x7ffff) >> 3);
        local_54 = 0x5453494c;
        local_50 = 0x28;
        local_4c = 0x544d4349;
        local_48 = 0x20;
        if (param_2 == 1) {
          iVar1 = FUN_20155122(param_1[1]);
          iVar2 = FUN_20155122(param_1[2]);
          if ((uint)(iVar2 + iVar1) < 0x1f) {
            FUN_201550dc(auStack_44,param_1[1]);
            FUN_2015515c(auStack_44,&DAT_20106558);
            FUN_2015515c(auStack_44,param_1[2]);
          }
        }
        else if (param_2 == 2) {
          FUN_201550dc(auStack_44,*param_1);
        }
        local_20 = 0;
        if (param_2 == 1) {
          pcVar3 = "I:\\FT-710\\PlayList";
        }
        local_24 = 0x61746164;
        if (param_2 != 1) {
          if (param_2 != 2) {
            return 0xfffffffe;
          }
          pcVar3 = "I:\\FT-710\\MESSAGE";
        }
        memclr(&DAT_20810fcc,0x80);
        FUN_201550dc(&DAT_20810fcc,pcVar3);
        FUN_2015515c(&DAT_20810fcc,&DAT_2010656c);
        FUN_2015515c(&DAT_20810fcc,*param_1);
        FUN_2015515c(&DAT_20810fcc,&DAT_20106570);
        if (param_2 == 2) {
          FUN_20143b20(&DAT_20810fcc);
        }
        DAT_208000dc = fs_fopen(&DAT_20810fcc,&DAT_20106578);
        if ((DAT_208000dc == 0) &&
           (((DAT_208000bc = FUN_2014beec(pcVar3), DAT_208000bc != 0 &&
             ((DAT_208000bc = FUN_2014beec("I:\\FT-710"), DAT_208000bc != 0 ||
              (DAT_208000bc = FUN_2014beec(pcVar3), DAT_208000bc != 0)))) ||
            (DAT_208000dc = fs_fopen(&DAT_20810fcc,&DAT_20106578), DAT_208000dc == 0)))) {
          DAT_208000bc = FUN_2014d95c();
        }
        else {
          iVar1 = fs_fwrite(&local_78,0x5c,1,DAT_208000dc);
          if (iVar1 != 0) {
            return 0;
          }
          rec_close_abort(0);
        }
      }
    }
    return 0xfffffffe;
  }
  return 0xffffffff;
}


// ===== sd_is_full @ 20106588 (60 bytes)

/* drive 'I' free space == 0 */

undefined4 sd_is_full(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int iStack_c;
  
  uVar2 = 0;
  iVar1 = FUN_2014b880((int)param_1,&local_10,&iStack_c);
  if ((iVar1 == 0) && (local_10 == 0 && iStack_c == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== task_audio_codec @ 201065c4 (2052 bytes)

void task_audio_codec(void)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ushort *puVar8;
  int unaff_r4;
  uint uVar9;
  bool bVar10;
  int local_1004;
  ushort local_1000 [2000];
  int local_60;
  ushort *local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  
  DAT_208000d0 = 0;
  DAT_208000d4 = 0;
  DAT_208000cc = 0;
  audio_clear_error();
  DAT_208000c4 = FUN_2014f3e4(0,&DAT_208000f8);
  if (DAT_208000c4 < 1) {
    DAT_208000b8 = DAT_208000b8 + 1;
    return;
  }
  local_50 = &DAT_2081105c;
  local_54 = 0x20811067;
  do {
    iVar5 = itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,0xffffffff);
    if (iVar5 != 0) {
      DAT_208000b8 = DAT_208000b8 + 1;
      return;
    }
    if (local_1004 == 2) {
      DAT_208000cc = 2;
      DAT_208000e4 = 0;
      local_4c = (undefined4 *)0x0;
      local_48 = (undefined4 *)0x0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      iVar5 = sd_is_full(0x49);
      if (iVar5 == 0) {
        local_4c = &DAT_2081104c;
        local_3c = 2;
        local_48 = local_50;
        local_40 = 1;
        local_44 = local_54;
        local_38 = 16000;
        local_34 = 0x10;
        iVar5 = rec_open_wav(&local_4c,DAT_208000b3);
        if (iVar5 == 0) {
          DAT_208000b2 = 1;
          if (DAT_208000d0 != 0) {
            do {
              iVar5 = FUN_201521a8(DAT_208000c4,&local_60,0x1e);
              if (iVar5 == -0x32) {
                iVar5 = FUN_20103ba0();
                if (iVar5 != 0) goto LAB_201068b8;
                DAT_208000d8 = -1;
                break;
              }
              if (iVar5 < 0) {
                DAT_208000b8 = DAT_208000b8 + 1;
                DAT_208000d8 = -9;
                break;
              }
              if (local_60 != 1) {
                DAT_208000b8 = DAT_208000b8 + 1;
                DAT_208000d8 = -9;
                break;
              }
              unaff_r4 = FUN_20105d14(local_5c);
              puVar3 = local_5c;
              if (unaff_r4 == 0) {
                uVar1 = *local_5c;
                if (uVar1 == 0) {
                  DAT_208000b8 = DAT_208000b8 + 1;
                  DAT_208000f4 = DAT_208000f4 + 1;
                  if (DAT_208000f4 < 4) goto LAB_201068b8;
                }
                iVar6 = 0;
                DAT_208000f4 = 0;
                memclr(local_1000,4000);
                uVar9 = uVar1 + 2;
                uVar7 = 2;
                iVar5 = iVar6;
                if (2 < uVar9) {
                  do {
                    puVar8 = puVar3 + uVar7;
                    uVar7 = uVar7 + 1;
                    iVar6 = iVar5 + 2;
                    local_1000[iVar5] = *puVar8;
                    local_1000[iVar5 + 1] = *puVar8;
                    iVar5 = iVar6;
                  } while (uVar7 < uVar9);
                }
                unaff_r4 = rec_write(iVar6 * 2,local_1000);
                if (unaff_r4 != 0) {
                  DAT_208000b8 = DAT_208000b8 + 1;
                  if (DAT_208000d8 != -1) {
                    DAT_208000d8 = -9;
                  }
                  break;
                }
                FUN_20101088(local_5c,4000);
                DAT_208000e4 = DAT_208000e4 + iVar6 * 2;
                if ((DAT_208000b3 == '\x02') && (0x57e3ff < DAT_208000e4)) break;
              }
              else {
                DAT_208000b8 = DAT_208000b8 + 1;
              }
LAB_201068b8:
            } while (DAT_208000d0 != 0);
          }
          DAT_208000b2 = 0;
          if (unaff_r4 != 0) {
            DAT_208000b8 = DAT_208000b8 + 1;
          }
          unaff_r4 = rec_finish();
          if (unaff_r4 != 0) {
            DAT_208000b8 = DAT_208000b8 + 1;
          }
          do {
            iVar5 = FUN_201521a8(DAT_208000c4,&local_60,0);
          } while (-1 < iVar5);
          DAT_208000d0 = 0;
          goto LAB_20106918;
        }
        DAT_208000d8 = -3;
      }
      else {
        DAT_208000d8 = -2;
      }
      DAT_208000d0 = 0;
    }
    else {
LAB_20106918:
      if (local_1004 == 4) {
        DAT_208000ec = 0;
        DAT_208000cc = 4;
        DAT_208000f0 = 0;
        DAT_208000b4 = 1;
        local_48 = (undefined4 *)0x0;
        local_44 = 0;
        local_40 = 0;
        local_38 = 0;
        local_3c = 0;
        local_34 = 0;
        local_30 = 0;
        local_4c = (undefined4 *)&DAT_20810fbc;
        local_2c = 0;
        unaff_r4 = wav_open_read(&local_4c,DAT_208000b3);
        if (unaff_r4 == 0) {
          DAT_208000e4 = local_30;
          DAT_208000b0 = 0;
          DAT_208000b5 = 0;
          if (DAT_208000d4 != 0) {
LAB_201069b4:
            bVar4 = 0;
            unaff_r4 = play_prime(2);
            if (unaff_r4 == 0) {
              DAT_208000b1 = 1;
              itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,0xffffffff);
              DAT_208000b0 = DAT_208000b0 + 1;
              if (0xf < DAT_208000b0) {
                DAT_208000b0 = 0;
              }
              DAT_208000d4 = 1;
              DAT_208000cc = 4;
LAB_20106a5c:
              iVar5 = FUN_201521a8(DAT_208000c4,&local_60,0x1e);
              if (-1 < iVar5) {
                bVar4 = 0;
                DAT_208000f0 = DAT_208000f0 + 0xc80;
                if (local_60 == 2) {
                  if (0xff < DAT_2080858e) {
                    local_58 = play_advance();
                    unaff_r4 = play_read_block(local_58,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8)
                    ;
                    if (unaff_r4 == -5) {
                      if (local_58 == 0) goto LAB_20106bd0;
                      if (DAT_2080858e < 0x29a) {
                        FUN_2015525c(&DAT_208f4de0,0x11f80,0xf0);
                        uVar7 = (uint)DAT_208000b0;
                        (&DAT_208f4de0)[uVar7 * 0x11f8] = 0;
                        iVar5 = uVar7 * 0x11f8;
                        *(undefined1 *)(iVar5 + 0x208f4de1) = 0;
                        FUN_20101030(&DAT_208f4de0 + iVar5,local_58);
                        itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,0xffffffff);
                        DAT_208000b0 = DAT_208000b0 + 1;
                        if (0xf < DAT_208000b0) {
                          DAT_208000b0 = 0;
                        }
                        goto LAB_20106d80;
                      }
                    }
                    else if (unaff_r4 == 0) goto LAB_20106cf4;
                    DAT_208000d8 = -9;
                    goto LAB_20106c3c;
                  }
                  FUN_2015525c(&DAT_208f4de0,0x11f80,0xf0);
                  uVar7 = (uint)DAT_208000b0;
                  (&DAT_208f4de0)[uVar7 * 0x11f8] = 0;
                  *(undefined1 *)(uVar7 * 0x11f8 + 0x208f4de1) = 0;
LAB_20106cf4:
                  FUN_20101030(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8,local_58);
                  itron_twai_flg(DAT_208000c8,0xffff,5,&local_1004,0xffffffff);
                  DAT_208000b0 = DAT_208000b0 + 1;
                  if (0xf < DAT_208000b0) {
                    DAT_208000b0 = 0;
                  }
                  if (((DAT_208000b3 != '\x02') || (DAT_208000f0 < 0x57e400)) &&
                     ((DAT_208000e4 != DAT_208000ec || (DAT_208000f0 < DAT_208000e4))))
                  goto LAB_20106d80;
                }
LAB_20106bd0:
                DAT_208000d4 = 0;
                goto LAB_20106d8c;
              }
              iVar6 = FUN_20103ba0();
              if (iVar6 == 0) {
                DAT_208000d8 = -1;
                DAT_208000d4 = 0;
                goto LAB_20106d8c;
              }
              if ((iVar5 != -0x32) || (bVar4 = bVar4 + 1, 8 < bVar4)) goto LAB_20106bd0;
              DAT_208000b8 = DAT_208000b8 + 1;
LAB_20106d80:
              while( true ) {
                if (DAT_208000d4 == 0) goto LAB_20106d8c;
                if (DAT_208000d4 != 2) break;
                DAT_208000b1 = 0;
                DAT_208000cc = 8;
                FUN_201525f8(1);
              }
              if (DAT_208000cc == 8) {
                do {
                  iVar5 = FUN_201521a8(DAT_208000c4,&local_60,0);
                } while (-1 < iVar5);
                DAT_208000b5 = 0;
                unaff_r4 = play_seek(DAT_208000f0);
              }
              else {
                if (DAT_208000d4 != 3) break;
                DAT_208000b1 = 0;
                DAT_208000cc = 0x20;
                do {
                  iVar5 = FUN_201521a8(DAT_208000c4,&local_60,0);
                } while (-1 < iVar5);
                DAT_208000f0 = DAT_208000f0 + 320000;
                if (DAT_208000e4 <= DAT_208000f0) {
                  DAT_208000f0 = DAT_208000e4 - 0xc80;
                }
                unaff_r4 = play_seek();
              }
              if (unaff_r4 == 0) goto LAB_20106ad8;
              goto LAB_20106acc;
            }
            DAT_208000b8 = DAT_208000b8 + 1;
            DAT_208000d8 = -9;
          }
LAB_20106d8c:
          DAT_208000b1 = 0;
          FUN_201050ac();
          DAT_208000d4 = 0;
          do {
            iVar5 = FUN_201521a8(DAT_208000c4,&local_60,0);
          } while (-1 < iVar5);
        }
        else {
          DAT_208000d8 = -4;
        }
      }
    }
    DAT_208000cc = 0;
  } while( true );
  if (DAT_208000d4 == 4) goto LAB_20106b44;
  goto LAB_20106a5c;
LAB_20106b44:
  DAT_208000b1 = 0;
  DAT_208000cc = 0x10;
  do {
    iVar5 = FUN_201521a8(DAT_208000c4,&local_60,0);
  } while (-1 < iVar5);
  bVar10 = DAT_208000f0 < 320000;
  DAT_208000f0 = DAT_208000f0 - 320000;
  iVar5 = -(uint)bVar10;
  iVar6 = -DAT_208000f0;
  iVar2 = -(iVar5 + (uint)(DAT_208000f0 != 0));
  if (iVar2 < 0 == (SBORROW4(0,iVar5) != SBORROW4((uint)bVar10,(uint)(DAT_208000f0 != 0)))) {
    DAT_208000f0 = 0;
  }
  unaff_r4 = play_seek(DAT_208000f0,iVar2,iVar6);
  if (unaff_r4 != 0) {
LAB_20106acc:
    DAT_208000d8 = -3;
LAB_20106c3c:
    DAT_208000d4 = 0;
    goto LAB_20106d8c;
  }
LAB_20106ad8:
  DAT_208000ec = DAT_208000f0;
  if (DAT_208000d4 == 0) goto LAB_20106d8c;
  goto LAB_201069b4;
}


// ===== audio_codec_post @ 20106dc8 (44 bytes)

/* 8-byte msg to task_audio_codec mailbox */

void audio_codec_post(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  FUN_201526f4(DAT_208000c4,&local_10,8,0);
  return;
}


// ===== usbkbd_attach @ 20106e0c (168 bytes)

void usbkbd_attach(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 local_20;
  
  bVar1 = false;
  local_20 = param_4;
  FUN_201571b8(&local_20,DAT_20800118,1);
  FUN_2015f098(&DAT_20811080 + param_1 * 0xd0,param_1,1);
  iVar2 = 0;
  do {
    if ((&DAT_20811100)[iVar2 * 0xd0] != '\0') {
      bVar1 = true;
      goto LAB_20106e8c;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  FUN_2015f0b4(&DAT_20811080 + param_1 * 0xd0);
LAB_20106e8c:
  FUN_201571d4(&local_20);
  if (bVar1) {
    return;
  }
  FUN_2013baac(param_1,0,&DAT_2080010c,local_20);
  return;
}


// ===== usbkbd_detach @ 20106eb4 (164 bytes)

void usbkbd_detach(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  
  iVar2 = -1;
  local_18 = param_4;
  FUN_201571b8(&local_18,DAT_20800118,1);
  FUN_2015f098(&DAT_20811080 + param_1 * 0xd0,param_1,0);
  iVar1 = 0;
  do {
    if ((&DAT_20811101)[iVar1 * 0xd0] != '\0') {
      FUN_2015f0b4(&DAT_20811080 + iVar1 * 0xd0);
      iVar2 = iVar1;
      break;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  FUN_201571d4(&local_18);
  if (iVar2 != -1) {
    FUN_2013baac(iVar2,0,&DAT_2080010c,local_18);
    return;
  }
  return;
}


// ===== usbkbd_queue_key @ 20106f58 (104 bytes)

/* (modifier, first usage) -> per-keyboard FIFO 0x20811108 */

void usbkbd_queue_key(int param_1,int param_2)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 auStack_10 [8];
  
  if (*(char *)(param_2 + 0xd) != '\0') {
    return;
  }
  local_17 = *(undefined1 *)(param_2 + 0xc);
  local_18 = *(undefined1 *)(param_2 + 5);
  FUN_201571b8(auStack_10,DAT_20800118,1);
  FUN_201645a0(param_1 * 0xd0 + 0x20811108,&local_18);
  FUN_201571d4(auStack_10);
  return;
}


// ===== usbkbd_report @ 20106fc0 (220 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* USB keyboard HID report: NumLock/ScrollLock LEDs, chain 0, chain 1 if debug_enabled */

void usbkbd_report(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  DAT_20811220 = *param_2;
  _DAT_20811224 = param_2[1];
  DAT_20811228 = param_2[2];
  DAT_2081122c = param_2[3];
  DAT_20811230 = param_2[4];
  DAT_20811234 = param_2[5];
  DAT_20811238 = param_2[6];
  DAT_2081123c = param_2[7];
  usbkbd_queue_key(param_1,param_2);
  DAT_2080010d = *(char *)(param_2 + 3);
  if (*(char *)((int)param_2 + 0xd) == '\0') {
    if (DAT_2080010d == 'S') {
      DAT_2080010c = DAT_2080010c ^ 1;
      FUN_2013baac(param_1,0,&DAT_2080010c);
    }
    else if (DAT_2080010d == 'G') {
      DAT_2080010c = DAT_2080010c ^ 4;
      FUN_2013baac(param_1,0,&DAT_2080010c);
    }
  }
  if (DAT_20800110 != (code *)0x0) {
    (*DAT_20800110)(param_1,param_2);
  }
  iVar1 = debug_enabled();
  if ((iVar1 != 0) && (DAT_20800114 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x20107094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_20800114)(param_1,param_2);
    return;
  }
  return;
}


// ===== usbkbd_active @ 2010709c (68 bytes)

undefined * usbkbd_active(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_20811100)[iVar1 * 0xd0] != '\0') {
      return &DAT_20811080 + iVar1 * 0xd0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return (undefined *)0x0;
}


// ===== usbkbd_get_device @ 201070e0 (92 bytes)

undefined1
usbkbd_get_device(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = usbkbd_active();
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x84);
    *param_1 = *(undefined4 *)(iVar1 + 0x80);
    param_1[1] = uVar2;
    FUN_201571d4(&uStack_10);
    return *(undefined1 *)param_1;
  }
  FUN_201571d4(&uStack_10);
  return 0;
}


// ===== usbkbd_pop_key @ 2010713c (140 bytes)

undefined4
usbkbd_pop_key(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = usbkbd_active();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x80);
    iVar1 = *(int *)(iVar1 + 0x84);
    param_1[1] = iVar1;
    *param_1 = uVar3;
    puVar2 = (undefined4 *)FUN_20164604(iVar1 * 0xd0 + 0x20811108);
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = puVar2[1];
      param_1[2] = *puVar2;
      param_1[3] = uVar3;
      FUN_201571d4(&uStack_10);
      return 1;
    }
  }
  FUN_201571d4(&uStack_10);
  return 0;
}


// ===== usbkbd_flush_all @ 201071c8 (72 bytes)

void usbkbd_flush_all(void)

{
  undefined4 in_r3;
  int iVar1;
  undefined4 uStack_10;
  
  uStack_10 = in_r3;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = 0;
  do {
    FUN_2015f0c4(&DAT_20811080 + iVar1 * 0xd0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  FUN_201571d4(&uStack_10);
  return;
}


// ===== usbkbd_get_char @ 20107210 (108 bytes)

/* FIFO -> char via the KEYBOARD LANGUAGE layout (0x2080010E) */

undefined4 usbkbd_get_char(byte *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined1 auStack_18 [8];
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar2 = usbkbd_pop_key(auStack_18);
  uVar3 = 0;
  if (iVar2 != 0) {
    *(undefined4 *)param_1 = local_10;
    *(undefined4 *)(param_1 + 4) = uStack_c;
    bVar1 = *param_1;
    if ((bVar1 & 0x9d) == 0) {
      bVar4 = (bVar1 & 0x22) != 0;
      if ((bVar1 & 0x40) != 0) {
        bVar4 = bVar4 | 2;
      }
    }
    else {
      bVar4 = 0xff;
    }
    uVar3 = FUN_2010a684(param_1[1],bVar4,DAT_2080010e);
    *(undefined4 *)(param_1 + 4) = uVar3;
    uVar3 = 1;
  }
  return uVar3;
}


// ===== kbd_text_append @ 201072d8 (36 bytes)

/* text buffer 0x20811240 (64 chars) */

void kbd_text_append(undefined1 param_1)

{
  if (DAT_2080011c < 0x40) {
    *(undefined1 *)((int)&DAT_20811240 + DAT_2080011c) = param_1;
    DAT_2080011c = DAT_2080011c + 1;
  }
  return;
}


// ===== kbd_text_backspace @ 201072fc (40 bytes)

void kbd_text_backspace(void)

{
  int iVar1;
  
  if (0 < DAT_2080011c) {
    iVar1 = DAT_2080011c + 3;
    DAT_2080011c = DAT_2080011c + -1;
    *(undefined1 *)((int)&DAT_2081123c + iVar1) = 0;
  }
  return;
}


// ===== kbd_text_clear @ 20107324 (84 bytes)

void kbd_text_clear(void)

{
  DAT_20811240 = 0;
  DAT_20811244 = 0;
  DAT_20811248 = 0;
  DAT_2081124c = 0;
  DAT_20811250 = 0;
  DAT_20811254 = 0;
  DAT_20811258 = 0;
  DAT_2081125c = 0;
  DAT_20811260 = 0;
  DAT_20811264 = 0;
  DAT_20811268 = 0;
  DAT_2081126c = 0;
  DAT_20811270 = 0;
  DAT_20811274 = 0;
  DAT_20811278 = 0;
  DAT_2081127c = 0;
  DAT_2080011c = 0;
  return;
}


// ===== usbkbd_set_layout @ 20107378 (20 bytes)

/* 0..10 (JPN US UK FRA(AZ) FRA(QW) DEU POR POR(BR) ESP ESP(LA) ITA) */

void usbkbd_set_layout(uint param_1)

{
  if (10 < param_1) {
    param_1 = 0;
  }
  DAT_2080010e = (char)param_1;
  return;
}


// ===== usbkbd_reset @ 2010738c (24 bytes)

void usbkbd_reset(void)

{
  usbkbd_flush_all();
  DAT_20800129 = 0;
  return;
}


// ===== usbkbd_capslock_for_mode @ 201073a4 (1800 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CapsLock LED on for text modes 0,3,5,8,10 */

void usbkbd_capslock_for_mode(uint param_1)

{
  undefined2 uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 auStack_1a8 [48];
  undefined1 auStack_148 [96];
  undefined1 auStack_e8 [96];
  undefined1 auStack_88 [96];
  undefined4 local_28;
  uint local_24;
  
  iVar4 = usbkbd_get_char(&local_28);
  if (iVar4 == 0) {
    return;
  }
  FUN_20155310(auStack_148,&DAT_20165348,0x60);
  FUN_20155310(auStack_e8,&DAT_201653a8,0x60);
  FUN_20155310(auStack_88,&DAT_20165408,0x60);
  FUN_20155310(auStack_1a8,auStack_e8,0x60);
  uVar3 = local_24;
  if (local_28._1_1_ == '\0') {
    _DAT_20800128 = local_28;
    DAT_2080012c = local_24;
    return;
  }
  if (DAT_20800129 != '\0') {
    _DAT_20800128 = local_28;
    DAT_2080012c = local_24;
    return;
  }
  uVar7 = 0;
  iVar4 = 0xff;
  bVar2 = false;
  uVar5 = local_24 - 0x30;
  if (uVar5 < 10) {
    uVar7 = local_24 & 0xff;
    switch(uVar5) {
    case 0:
switchD_20107444_caseD_0:
      iVar4 = 9;
      break;
    case 1:
switchD_20107444_caseD_1:
      iVar4 = 0;
      break;
    case 2:
switchD_20107444_caseD_2:
      iVar4 = 1;
      break;
    case 3:
switchD_20107444_caseD_3:
      iVar4 = 2;
      break;
    case 4:
switchD_20107444_caseD_4:
      iVar4 = 3;
      break;
    case 5:
switchD_20107444_caseD_5:
      iVar4 = 4;
      break;
    case 6:
switchD_20107444_caseD_6:
      iVar4 = 5;
      break;
    case 7:
switchD_20107444_caseD_7:
      iVar4 = 6;
      break;
    case 8:
switchD_20107444_caseD_8:
      iVar4 = 7;
      break;
    case 9:
switchD_20107444_caseD_9:
      iVar4 = 8;
      break;
    default:
switchD_20107444_default:
      if (iVar4 == 0xff) goto LAB_20107d28;
    }
  }
  else {
    if (local_24 - 0x60 < 10) {
      uVar7 = uVar5 & 0xff;
      switch(local_24) {
      case 0x60:
        goto switchD_20107444_caseD_0;
      case 0x61:
        goto switchD_20107444_caseD_1;
      case 0x62:
        goto switchD_20107444_caseD_2;
      case 99:
        goto switchD_20107444_caseD_3;
      case 100:
        goto switchD_20107444_caseD_4;
      case 0x65:
        goto switchD_20107444_caseD_5;
      case 0x66:
        goto switchD_20107444_caseD_6;
      case 0x67:
        goto switchD_20107444_caseD_7;
      case 0x68:
        goto switchD_20107444_caseD_8;
      case 0x69:
        goto switchD_20107444_caseD_9;
      default:
        goto switchD_20107444_default;
      }
    }
    uVar5 = local_24 - 0x41;
    if (0x19 < uVar5) {
      if (local_24 == 0x1b) {
        iVar4 = 0x2a;
      }
      else if (local_24 == 0x25) {
        iVar4 = 0x2b;
      }
      else if (local_24 == 0x20) {
        iVar4 = 0x2c;
      }
      else if (local_24 == 0x27) {
        iVar4 = 0x2d;
      }
      else if (local_24 == 0xd || local_24 == 0xd8) {
        iVar4 = 0x2e;
      }
      else {
        if (local_24 != 8) {
          if (param_1 < 3) {
            bVar2 = true;
            if (local_24 == 0xbc) {
switchD_20107c58_caseD_bc:
              iVar4 = 0x25;
            }
            else if ((int)local_24 < 0xbd) {
              if (local_24 == 0xb3) {
LAB_20107854:
                iVar4 = 0xd;
              }
              else if ((int)local_24 < 0xb4) {
                if (local_24 == 0x6e) goto switchD_20107b38_caseD_6e;
                if ((int)local_24 < 0x6f) {
                  if (local_24 == 0x14) goto switchD_20107b38_caseD_70;
                  if (local_24 == 0x6a) goto switchD_20107ab8_caseD_c1;
                  if (local_24 == 0x6b) goto switchD_20107b38_caseD_6b;
joined_r0x20107790:
                  if (local_24 == 0x6d) goto switchD_20107c58_caseD_bd;
                }
                else {
                  if (local_24 == 0x6f) goto switchD_20107b38_caseD_6f;
                  if (local_24 == 0xb1) goto LAB_20107844;
joined_r0x201077ac:
                  if (local_24 == 0xb2) goto LAB_2010784c;
                }
              }
              else {
                switch(local_24) {
                case 0xb4:
                  goto switchD_20107a88_caseD_b4;
                case 0xb5:
switchD_20107c34_caseD_b5:
                  iVar4 = 0xf;
                  break;
                case 0xb6:
                  goto switchD_20107c34_caseD_b6;
                case 0xb7:
                  goto switchD_20107c34_caseD_b7;
                case 0xb8:
                  goto switchD_20107c34_caseD_b8;
                case 0xb9:
                  goto switchD_20107c34_caseD_b9;
                case 0xba:
                  goto switchD_20107b98_caseD_ba;
                case 0xbb:
                  goto switchD_20107b38_caseD_6b;
                }
              }
            }
            else {
              switch(local_24) {
              case 0xbd:
                goto switchD_20107c58_caseD_bd;
              case 0xbe:
switchD_20107b38_caseD_6e:
                iVar4 = 0x26;
                break;
              case 0xbf:
                goto switchD_20107b38_caseD_6f;
              case 0xc0:
              case 0xcc:
switchD_20107c58_caseD_c0:
                iVar4 = 0x1f;
                break;
              case 0xc1:
switchD_20107ab8_caseD_c1:
                iVar4 = 0x19;
                break;
              case 0xc3:
switchD_20107ab8_caseD_c3:
                iVar4 = 0x1a;
                break;
              case 0xc4:
                goto switchD_20107c58_caseD_c4;
              case 0xc5:
switchD_20107ab8_caseD_c5:
                iVar4 = 0x1b;
                break;
              case 0xc6:
switchD_20107b98_caseD_c6:
                iVar4 = 0x1c;
                break;
              case 200:
                goto switchD_20107c58_caseD_c8;
              case 0xc9:
switchD_20107c58_caseD_c9:
                iVar4 = 0x23;
                break;
              case 0xca:
switchD_20107c58_caseD_ca:
                iVar4 = 0x21;
                break;
              case 0xcb:
                goto switchD_20107c58_caseD_cb;
              case 0xce:
switchD_20107c58_caseD_ce:
                iVar4 = 0x1d;
                break;
              case 0xcf:
switchD_20107ab8_caseD_cf:
                iVar4 = 0x24;
                break;
              case 0xd0:
switchD_20107b38_caseD_70:
                iVar4 = 0x20;
              }
            }
          }
          else {
            bVar2 = param_1 == 3 || param_1 == 4;
            if (param_1 == 3 || param_1 == 4) {
              if (local_24 == 0xbc) goto switchD_20107c58_caseD_bc;
              if ((int)local_24 < 0xbd) {
                if (local_24 == 0xb4) {
switchD_20107a88_caseD_b4:
                  iVar4 = 0xe;
                }
                else if ((int)local_24 < 0xb5) {
                  if (local_24 == 0x6f) goto switchD_20107b38_caseD_6f;
                  if ((int)local_24 < 0x70) {
                    if (local_24 == 0x6b) goto switchD_20107b38_caseD_6b;
                    if (local_24 == 0x6d) goto switchD_20107c58_caseD_bd;
                    if (local_24 == 0x6e) goto switchD_20107b38_caseD_6e;
                  }
                  else {
                    if (local_24 == 0xb1) goto LAB_20107844;
                    if (local_24 == 0xb2) goto LAB_2010784c;
joined_r0x20107978:
                    if (local_24 == 0xb3) goto LAB_20107854;
                  }
                }
                else {
                  switch(local_24) {
                  case 0xb5:
                    goto switchD_20107c34_caseD_b5;
                  case 0xb6:
                    goto switchD_20107c34_caseD_b6;
                  case 0xb7:
                    goto switchD_20107c34_caseD_b7;
                  case 0xb8:
                    goto switchD_20107c34_caseD_b8;
                  case 0xb9:
                    goto switchD_20107c34_caseD_b9;
                  case 0xba:
                    goto switchD_20107b98_caseD_ba;
                  case 0xbb:
                    goto switchD_20107b38_caseD_6b;
                  }
                }
              }
              else {
                switch(local_24) {
                case 0xbd:
                  goto switchD_20107c58_caseD_bd;
                case 0xbe:
                  goto switchD_20107b38_caseD_6e;
                case 0xbf:
switchD_20107b38_caseD_6f:
                  iVar4 = 0x18;
                  break;
                case 0xc0:
                case 0xcc:
                  goto switchD_20107c58_caseD_c0;
                case 0xc2:
switchD_20107b98_caseD_c2:
                  iVar4 = 0x27;
                  break;
                case 0xc3:
                  goto switchD_20107ab8_caseD_c3;
                case 0xc4:
                  goto switchD_20107c58_caseD_c4;
                case 0xc5:
                  goto switchD_20107ab8_caseD_c5;
                case 0xc6:
                  goto switchD_20107b98_caseD_c6;
                case 200:
                  goto switchD_20107c58_caseD_c8;
                case 0xc9:
                  goto switchD_20107c58_caseD_c9;
                case 0xca:
                  goto switchD_20107c58_caseD_ca;
                case 0xce:
                  goto switchD_20107c58_caseD_ce;
                case 0xd0:
                  goto switchD_20107b38_caseD_70;
                }
              }
            }
            else {
              bVar2 = ((param_1 == 5 || param_1 == 6) || param_1 == 7) || bVar2;
              if ((param_1 == 5 || param_1 == 6) || param_1 == 7) {
                if (local_24 == 0xbc) goto switchD_20107c58_caseD_bc;
                if ((int)local_24 < 0xbd) {
                  if (local_24 == 0xb3) goto LAB_20107854;
                  if (0xb3 < (int)local_24) {
                    switch(local_24) {
                    case 0xb4:
                      goto switchD_20107a88_caseD_b4;
                    case 0xb5:
                      goto switchD_20107c34_caseD_b5;
                    case 0xb6:
                      goto switchD_20107c34_caseD_b6;
                    case 0xb7:
                      goto switchD_20107c34_caseD_b7;
                    case 0xb8:
                      goto switchD_20107c34_caseD_b8;
                    case 0xb9:
                      goto switchD_20107c34_caseD_b9;
                    case 0xba:
                      goto switchD_20107b98_caseD_ba;
                    case 0xbb:
                      goto switchD_20107b38_caseD_6b;
                    default:
                      goto switchD_20107c34_default;
                    }
                  }
                  if (local_24 == 0x6e) goto switchD_20107b38_caseD_6e;
                  if (0x6e < (int)local_24) {
                    if (local_24 != 0x6f) {
                      if (local_24 == 0x79) goto LAB_20107b10;
                      if (local_24 != 0xb1) goto joined_r0x201077ac;
                      goto LAB_20107844;
                    }
                    goto switchD_20107b38_caseD_6f;
                  }
                  if (local_24 == 0x14) goto switchD_20107b38_caseD_70;
                  if (local_24 == 0x6a) goto switchD_20107ab8_caseD_c1;
                  if (local_24 != 0x6b) goto joined_r0x20107790;
switchD_20107b38_caseD_6b:
                  iVar4 = 0x15;
                }
                else {
                  switch(local_24) {
                  case 0xbd:
                    goto switchD_20107c58_caseD_bd;
                  case 0xbe:
                    goto switchD_20107b38_caseD_6e;
                  case 0xbf:
                    goto switchD_20107b38_caseD_6f;
                  case 0xc0:
                  case 0xcc:
                    goto switchD_20107c58_caseD_c0;
                  case 0xc1:
                    goto switchD_20107ab8_caseD_c1;
                  case 0xc2:
                    goto switchD_20107b98_caseD_c2;
                  case 0xc3:
                    goto switchD_20107ab8_caseD_c3;
                  case 0xc4:
                    goto switchD_20107c58_caseD_c4;
                  case 0xc5:
                    goto switchD_20107ab8_caseD_c5;
                  case 0xc6:
                    goto switchD_20107b98_caseD_c6;
                  case 200:
                    goto switchD_20107c58_caseD_c8;
                  case 0xc9:
                    goto switchD_20107c58_caseD_c9;
                  case 0xca:
                    goto switchD_20107c58_caseD_ca;
                  case 0xcb:
switchD_20107c58_caseD_cb:
                    iVar4 = 0x1e;
                    break;
                  case 0xce:
                    goto switchD_20107c58_caseD_ce;
                  case 0xcf:
                    goto switchD_20107ab8_caseD_cf;
                  case 0xd0:
                    goto switchD_20107b38_caseD_70;
                  }
                }
              }
              else {
                bVar2 = (param_1 == 8 || param_1 == 9) || bVar2;
                if (param_1 == 8 || param_1 == 9) {
                  if (local_24 == 0xb6) {
switchD_20107c34_caseD_b6:
                    iVar4 = 0x10;
                  }
                  else if ((int)local_24 < 0xb7) {
                    if (local_24 == 0x72) goto switchD_20107c58_caseD_c8;
                    if ((int)local_24 < 0x73) {
                      switch(local_24) {
                      case 0x6b:
                        goto switchD_20107b38_caseD_6b;
                      case 0x6d:
                        goto switchD_20107c58_caseD_bd;
                      case 0x6e:
                        goto switchD_20107b38_caseD_6e;
                      case 0x6f:
                        goto switchD_20107b38_caseD_6f;
                      case 0x70:
                        goto switchD_20107b38_caseD_70;
                      case 0x71:
                        goto switchD_20107c58_caseD_ca;
                      }
                    }
                    else if (local_24 == 0xb2) {
LAB_2010784c:
                      iVar4 = 0xc;
                    }
                    else if ((int)local_24 < 0xb3) {
                      if (local_24 == 0x79) {
LAB_20107b10:
                        iVar4 = 0x14;
                      }
                      else if (local_24 == 0xb1) goto LAB_20107844;
                    }
                    else {
                      if (local_24 == 0xb3) goto LAB_20107854;
                      if (local_24 == 0xb4) goto switchD_20107a88_caseD_b4;
                    }
                  }
                  else {
                    switch(local_24) {
                    case 0xb7:
switchD_20107c34_caseD_b7:
                      iVar4 = 0x11;
                      break;
                    case 0xb8:
switchD_20107c34_caseD_b8:
                      iVar4 = 0x12;
                      break;
                    case 0xb9:
switchD_20107c34_caseD_b9:
                      iVar4 = 0x13;
                      break;
                    case 0xba:
switchD_20107b98_caseD_ba:
                      iVar4 = 0x28;
                      break;
                    case 0xbb:
                      goto switchD_20107b38_caseD_6b;
                    case 0xbc:
                      goto switchD_20107c58_caseD_bc;
                    case 0xbd:
                      goto switchD_20107c58_caseD_bd;
                    case 0xbe:
                      goto switchD_20107b38_caseD_6e;
                    case 0xbf:
                      goto switchD_20107b38_caseD_6f;
                    case 0xc2:
                      goto switchD_20107b98_caseD_c2;
                    case 0xc4:
                      goto switchD_20107c58_caseD_c4;
                    case 0xc6:
                      goto switchD_20107b98_caseD_c6;
                    }
                  }
                }
                else {
                  bVar2 = ((param_1 == 10 || param_1 == 0xb) || param_1 == 0xc) || bVar2;
                  if ((param_1 != 10 && param_1 != 0xb) && param_1 != 0xc) {
                    _DAT_20800128 = local_28;
                    DAT_2080012c = local_24;
                    return;
                  }
                  if (local_24 == 0xbb) goto switchD_20107b38_caseD_6b;
                  if ((int)local_24 < 0xbc) {
                    if (local_24 == 0xb4) goto switchD_20107a88_caseD_b4;
                    if ((int)local_24 < 0xb5) {
                      if (local_24 == 0x6d) goto switchD_20107c58_caseD_bd;
                      if ((int)local_24 < 0x6e) {
                        if (local_24 == 0x14) goto switchD_20107b38_caseD_70;
                        if (local_24 == 0x6b) goto switchD_20107b38_caseD_6b;
                      }
                      else {
                        if (local_24 != 0xb1) goto joined_r0x20107978;
LAB_20107844:
                        iVar4 = 0xb;
                      }
                    }
                    else {
                      switch(local_24) {
                      case 0xb5:
                        goto switchD_20107c34_caseD_b5;
                      case 0xb6:
                        goto switchD_20107c34_caseD_b6;
                      case 0xb7:
                        goto switchD_20107c34_caseD_b7;
                      case 0xb8:
                        goto switchD_20107c34_caseD_b8;
                      case 0xb9:
                        goto switchD_20107c34_caseD_b9;
                      }
                    }
                  }
                  else {
                    switch(local_24) {
                    case 0xbc:
                      goto switchD_20107c58_caseD_bc;
                    case 0xbd:
switchD_20107c58_caseD_bd:
                      iVar4 = 0x16;
                      break;
                    case 0xc0:
                    case 0xcc:
                      goto switchD_20107c58_caseD_c0;
                    case 0xc4:
switchD_20107c58_caseD_c4:
                      iVar4 = 0x17;
                      break;
                    case 200:
switchD_20107c58_caseD_c8:
                      iVar4 = 0x22;
                      break;
                    case 0xc9:
                      goto switchD_20107c58_caseD_c9;
                    case 0xca:
                      goto switchD_20107c58_caseD_ca;
                    case 0xcb:
                      goto switchD_20107c58_caseD_cb;
                    case 0xce:
                      goto switchD_20107c58_caseD_ce;
                    }
                  }
                }
              }
            }
          }
switchD_20107c34_default:
          FUN_20155310(auStack_1a8,auStack_148,0x60);
          goto switchD_20107444_default;
        }
        iVar4 = 10;
      }
      goto LAB_20107cc4;
    }
    if ((local_28 & 0xdd) != 0) goto LAB_20107d28;
    iVar6 = 0x20;
    if ((local_28 & 0x22) == 0) {
      if (DAT_2080010f != '\0') goto LAB_20107538;
LAB_20107548:
      FUN_20155310(auStack_1a8,auStack_88,0x60);
    }
    else {
      if (DAT_2080010f != '\0') goto LAB_20107548;
LAB_20107538:
      iVar6 = 0;
    }
    uVar7 = uVar3 + iVar6 & 0xff;
    switch(uVar5) {
    case 0:
      iVar4 = 0x16;
      break;
    case 1:
      iVar4 = 0x25;
      break;
    case 2:
      iVar4 = 0x23;
      break;
    case 3:
      iVar4 = 0x18;
      break;
    case 4:
      iVar4 = 0xd;
      break;
    case 5:
      iVar4 = 0x19;
      break;
    case 6:
      iVar4 = 0x1a;
      break;
    case 7:
      iVar4 = 0x1b;
      break;
    case 8:
      iVar4 = 0x12;
      break;
    case 9:
      iVar4 = 0x1c;
      break;
    case 10:
      iVar4 = 0x1d;
      break;
    case 0xb:
      iVar4 = 0x1e;
      break;
    case 0xc:
      iVar4 = 0x27;
      break;
    case 0xd:
      iVar4 = 0x26;
      break;
    case 0xe:
      iVar4 = 0x13;
      break;
    case 0xf:
      iVar4 = 0x14;
      break;
    case 0x10:
      iVar4 = 0xb;
      break;
    case 0x11:
      iVar4 = 0xe;
      break;
    case 0x12:
      iVar4 = 0x17;
      break;
    case 0x13:
      iVar4 = 0xf;
      break;
    case 0x14:
      iVar4 = 0x11;
      break;
    case 0x15:
      iVar4 = 0x24;
      break;
    case 0x16:
      iVar4 = 0xc;
      break;
    case 0x17:
      iVar4 = 0x22;
      break;
    case 0x18:
      iVar4 = 0x10;
      break;
    case 0x19:
      iVar4 = 0x21;
      break;
    default:
      goto switchD_20107444_default;
    }
  }
LAB_20107cc4:
  if (uVar3 == 0x14 || uVar3 == 0xc0) {
    FUN_20155310(auStack_1a8,auStack_e8,0x60);
  }
  uVar5 = 0x10;
  uVar1 = auStack_1a8[iVar4];
  if (uVar7 - 0x41 < 0x1a) {
    uVar5 = 0x20;
  }
  if ((bVar2 && uVar3 != 0xc0) && (uVar3 != 0x14)) {
    uVar5 = 0x30;
  }
  mainlink_send_e0(uVar5 | 1,uVar1);
  mainlink_send_e0(uVar5,uVar1);
LAB_20107d28:
  if (uVar3 == 0x1b) {
    kbd_text_clear();
  }
  else if (uVar3 == 8) {
    kbd_text_backspace();
  }
  else if (uVar7 != 0) {
    kbd_text_append(uVar7);
  }
  DAT_2080012c = local_24;
  _DAT_20800128 = local_28;
  return;
}


// ===== FUN_20107d8c @ 20107d8c (144 bytes)

void FUN_20107d8c(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_18 [4];
  undefined4 local_14;
  
  if (param_1 == 5) {
LAB_20107db8:
    uVar3 = 1;
  }
  else {
    if (param_1 < 6) {
      if (param_1 == 0 || param_1 == 3) goto LAB_20107db8;
    }
    else if (param_1 == 8 || param_1 == 10) goto LAB_20107db8;
    uVar3 = 0;
  }
  iVar1 = usbkbd_get_device(auStack_18);
  DAT_2080010f = (undefined1)uVar3;
  uVar2 = (uint)DAT_2080010c;
  if (uVar3 == 0) {
    DAT_2080010c = DAT_2080010c & 0xfd;
  }
  else {
    DAT_2080010c = DAT_2080010c | 2;
  }
  if ((uVar2 & 3) >> 1 != uVar3 && iVar1 != 0) {
    FUN_2013baac(local_14,0,&DAT_2080010c);
  }
  return;
}


// ===== debug_unlock_check @ 20107dc0 (168 bytes)

/* P4_2/P4_3/P8_3 low + Ctrl + Backspace in the HID report */

uint debug_unlock_check(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = gpio_read_bit(4,2);
  iVar3 = gpio_read_bit(4,3);
  iVar4 = gpio_read_bit(8,3);
  uVar1 = (uint)(byte)(iVar2 == 0 | (iVar3 == 0) << 1 | (iVar4 == 0) << 2) << 0x18;
  DAT_20800124 = uVar1;
  if (iVar3 == 0 && iVar4 == 0) {
    itron_dly_tsk(0x1e);
    DAT_20800124 = uVar1 | (uint)DAT_20811225 << 0x10 | (uint)(byte)DAT_2081122c;
    if (((DAT_20811225 & 0x11) != 0) && ((byte)DAT_2081122c == 0x2a)) {
      return DAT_20800124;
    }
  }
  return 0;
}


// ===== debug_unlock @ 20107e68 (56 bytes)

/* sets 0x20450000 = 0xA0B9C8E7; no caller in V01-08 */

void debug_unlock(void)

{
  DAT_20800120 = debug_unlock_check();
  if (DAT_20800120 != 0) {
    DAT_20450000 = 0xa0b9c8e7;
    return;
  }
  return;
}


// ===== usbkbd_last_key @ 20107e90 (12 bytes)

/* first key usage of the last USB keyboard report */

undefined1 usbkbd_last_key(void)

{
  return DAT_2080010d;
}


// ===== FUN_20107e9c @ 20107e9c (68 bytes)

void FUN_20107e9c(void)

{
  int iVar1;
  
  DAT_20800118 = FUN_2014fd24(0,&DAT_2016533c);
  iVar1 = 0;
  do {
    FUN_2015f05c(&DAT_20811080 + iVar1 * 0xd0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  kbd_layout_tables_init();
  return;
}

