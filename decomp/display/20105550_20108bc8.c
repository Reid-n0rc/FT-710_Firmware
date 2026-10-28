// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20105550 @ 20105550 (576 bytes)

int FUN_20105550(int param_1,int param_2,int param_3)

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
            iVar3 = FUN_201052b0(&local_58,param_3);
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


// ===== FUN_20105790 @ 20105790 (12 bytes)

undefined4 FUN_20105790(void)

{
  return DAT_208000cc;
}


// ===== FUN_2010579c @ 2010579c (60 bytes)

void FUN_2010579c(void)

{
  int iVar1;
  
  DAT_208000d4 = 0;
  DAT_208000ec = 0;
  DAT_208000f0 = 0;
  do {
    FUN_201525f8(10);
    iVar1 = FUN_20105790();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_201057d8 @ 201057d8 (232 bytes)

undefined4 FUN_201057d8(int param_1,int param_2,undefined4 param_3,int param_4)

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
      iVar2 = FUN_20105790(iVar2);
      if (iVar2 == 8) {
        FUN_2010579c();
        iVar2 = 0;
        do {
          iVar3 = FUN_20105790();
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
        uVar1 = FUN_20105550(param_2,param_3,param_4);
        return uVar1;
      }
      uVar1 = 0xfffffffa;
    }
  }
  return uVar1;
}


// ===== FUN_201058c0 @ 201058c0 (12 bytes)

undefined4 FUN_201058c0(void)

{
  return DAT_208000d8;
}


// ===== FUN_201058cc @ 201058cc (16 bytes)

void FUN_201058cc(void)

{
  DAT_208000d8 = 0;
  return;
}


// ===== FUN_201058dc @ 201058dc (288 bytes)

void FUN_201058dc(int param_1,undefined1 *param_2,uint param_3,undefined1 param_4)

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
    FUN_201058cc();
    iVar1 = itron_set_flg(DAT_208000c8,2);
    do {
      if (iVar1 != 0) break;
      FUN_201525f8(10);
      iVar2 = FUN_20105790();
      iVar1 = DAT_208000d8;
    } while (iVar2 != 2);
  }
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_20105a20 @ 20105a20 (52 bytes)

void FUN_20105a20(void)

{
  int iVar1;
  
  DAT_208000d0 = 0;
  do {
    FUN_201525f8(10);
    iVar1 = FUN_20105790();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_20105a54 @ 20105a54 (148 bytes)

void FUN_20105a54(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  
  memcpy(&DAT_20810fbc,param_1,0x10);
  DAT_208000d4 = 1;
  DAT_208000b3 = param_2;
  FUN_201058cc();
  iVar1 = itron_set_flg(DAT_208000c8,4);
  if (iVar1 == 0) {
    do {
      FUN_201525f8(10);
      iVar1 = FUN_20105790();
      if ((iVar1 == 4) || (DAT_208000d8 != 0)) goto LAB_20105ab4;
      iVar1 = FUN_20105790();
    } while ((iVar1 != 0) || (DAT_208000b4 == '\0'));
    DAT_208000b4 = '\0';
  }
LAB_20105ab4:
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_20105ae8 @ 20105ae8 (64 bytes)

void FUN_20105ae8(void)

{
  int iVar1;
  
  DAT_208000d4 = 1;
  do {
    FUN_201525f8(10);
    iVar1 = FUN_20105790();
    if (iVar1 == 4) break;
    iVar1 = FUN_20105790();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_20105b28 @ 20105b28 (64 bytes)

void FUN_20105b28(void)

{
  int iVar1;
  
  DAT_208000d4 = 2;
  do {
    FUN_201525f8(10);
    iVar1 = FUN_20105790();
    if (iVar1 == 8) break;
    iVar1 = FUN_20105790();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_20105b68 @ 20105b68 (64 bytes)

void FUN_20105b68(void)

{
  int iVar1;
  
  DAT_208000d4 = 3;
  do {
    FUN_201525f8(10);
    iVar1 = FUN_20105790();
    if (iVar1 == 4) break;
    iVar1 = FUN_20105790();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_20105ba8 @ 20105ba8 (64 bytes)

void FUN_20105ba8(void)

{
  int iVar1;
  
  DAT_208000d4 = 4;
  do {
    FUN_201525f8(10);
    iVar1 = FUN_20105790();
    if (iVar1 == 4) break;
    iVar1 = FUN_20105790();
  } while (iVar1 != 0);
  DAT_208000b8 = DAT_208000b8 + 1;
  return;
}


// ===== FUN_20105be8 @ 20105be8 (144 bytes)

void FUN_20105be8(undefined2 *param_1,undefined4 param_2)

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


// ===== FUN_20105d24 @ 20105d24 (444 bytes)

undefined4 FUN_20105d24(int param_1,undefined1 *param_2)

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
    FUN_2010508c();
    return 0xfffffffe;
  }
  if (param_1 == 0) {
    return 0xfffffffb;
  }
  if (param_2 == (undefined1 *)0x0) {
    FUN_2010508c();
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
  FUN_2010508c();
  return 0xfffffffe;
}


// ===== FUN_20105ee0 @ 20105ee0 (76 bytes)

void FUN_20105ee0(void)

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


// ===== FUN_20105f2c @ 20105f2c (116 bytes)

undefined4 FUN_20105f2c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_208000c0 = param_1;
  if (DAT_208000e0 == 0) {
    FUN_2010508c();
    return 0xfffffffe;
  }
  iVar1 = FUN_20103ba0();
  if (iVar1 != 0) {
    iVar1 = fs_fseek(DAT_208000e0,param_1 + 0x5c,0);
    uVar2 = 0;
    if (iVar1 != 0) {
      DAT_208000bc = FUN_2014d95c();
      FUN_2010508c();
      uVar2 = 0xfffffffe;
    }
    return uVar2;
  }
  DAT_208000d8 = 0xffffffff;
  FUN_2010508c();
  return 0xfffffffe;
}


// ===== FUN_20105fa0 @ 20105fa0 (120 bytes)

int FUN_20105fa0(int param_1)

{
  int iVar1;
  undefined4 unaff_r7;
  bool bVar2;
  
  iVar1 = 0;
  if (param_1 == 2) {
    unaff_r7 = FUN_20105ee0();
    iVar1 = FUN_20105d24(unaff_r7,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8);
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


// ===== FUN_20106018 @ 20106018 (72 bytes)

/* WARNING: Removing unreachable block (ram,0x201552fe) */
/* WARNING: Removing unreachable block (ram,0x201552f4) */
/* WARNING: Removing unreachable block (ram,0x201552e4) */
/* WARNING: Removing unreachable block (ram,0x201552ea) */
/* WARNING: Removing unreachable block (ram,0x201552fc) */
/* WARNING: Removing unreachable block (ram,0x20155302) */
/* WARNING: Removing unreachable block (ram,0x20155308) */
/* WARNING: Removing unreachable block (ram,0x2015530c) */

undefined4 * FUN_20106018(void)

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


// ===== FUN_20106060 @ 20106060 (332 bytes)

undefined4 FUN_20106060(void)

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
    FUN_20106018();
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
  FUN_20106018();
  return 0xfffffffe;
}


// ===== FUN_201061c8 @ 201061c8 (128 bytes)

undefined4 FUN_201061c8(int param_1,int param_2)

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


// ===== FUN_20106248 @ 20106248 (740 bytes)

undefined4 FUN_20106248(undefined4 *param_1,int param_2)

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
          FUN_20106018(0);
        }
      }
    }
    return 0xfffffffe;
  }
  return 0xffffffff;
}


// ===== FUN_20106588 @ 20106588 (60 bytes)

undefined4 FUN_20106588(char param_1)

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
  FUN_201058cc();
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
      iVar5 = FUN_20106588(0x49);
      if (iVar5 == 0) {
        local_4c = &DAT_2081104c;
        local_3c = 2;
        local_48 = local_50;
        local_40 = 1;
        local_44 = local_54;
        local_38 = 16000;
        local_34 = 0x10;
        iVar5 = FUN_20106248(&local_4c,DAT_208000b3);
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
                unaff_r4 = FUN_201061c8(iVar6 * 2,local_1000);
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
          unaff_r4 = FUN_20106060();
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
        unaff_r4 = FUN_201052b0(&local_4c,DAT_208000b3);
        if (unaff_r4 == 0) {
          DAT_208000e4 = local_30;
          DAT_208000b0 = 0;
          DAT_208000b5 = 0;
          if (DAT_208000d4 != 0) {
LAB_201069b4:
            bVar4 = 0;
            unaff_r4 = FUN_20105fa0(2);
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
                    local_58 = FUN_20105ee0();
                    unaff_r4 = FUN_20105d24(local_58,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8);
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
                unaff_r4 = FUN_20105f2c(DAT_208000f0);
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
                unaff_r4 = FUN_20105f2c();
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
  unaff_r4 = FUN_20105f2c(DAT_208000f0,iVar2,iVar6);
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


// ===== FUN_20106dc8 @ 20106dc8 (44 bytes)

void FUN_20106dc8(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  FUN_201526f4(DAT_208000c4,&local_10,8,0);
  return;
}


// ===== FUN_20106e0c @ 20106e0c (168 bytes)

void FUN_20106e0c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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


// ===== FUN_20106eb4 @ 20106eb4 (164 bytes)

void FUN_20106eb4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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


// ===== FUN_20106f58 @ 20106f58 (104 bytes)

void FUN_20106f58(int param_1,int param_2)

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
  FUN_20106f58(param_1,param_2);
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


// ===== FUN_2010709c @ 2010709c (68 bytes)

undefined * FUN_2010709c(void)

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


// ===== FUN_201070e0 @ 201070e0 (92 bytes)

undefined1
FUN_201070e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = FUN_2010709c();
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


// ===== FUN_2010713c @ 2010713c (140 bytes)

undefined4
FUN_2010713c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = FUN_2010709c();
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


// ===== FUN_201071c8 @ 201071c8 (72 bytes)

void FUN_201071c8(void)

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


// ===== FUN_20107210 @ 20107210 (108 bytes)

undefined4 FUN_20107210(byte *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined1 auStack_18 [8];
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar2 = FUN_2010713c(auStack_18);
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


// ===== FUN_201072d8 @ 201072d8 (36 bytes)

void FUN_201072d8(undefined1 param_1)

{
  if (DAT_2080011c < 0x40) {
    *(undefined1 *)((int)&DAT_20811240 + DAT_2080011c) = param_1;
    DAT_2080011c = DAT_2080011c + 1;
  }
  return;
}


// ===== FUN_201072fc @ 201072fc (40 bytes)

void FUN_201072fc(void)

{
  int iVar1;
  
  if (0 < DAT_2080011c) {
    iVar1 = DAT_2080011c + 3;
    DAT_2080011c = DAT_2080011c + -1;
    *(undefined1 *)((int)&DAT_2081123c + iVar1) = 0;
  }
  return;
}


// ===== FUN_20107324 @ 20107324 (84 bytes)

void FUN_20107324(void)

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


// ===== FUN_20107378 @ 20107378 (20 bytes)

void FUN_20107378(uint param_1)

{
  if (10 < param_1) {
    param_1 = 0;
  }
  DAT_2080010e = (char)param_1;
  return;
}


// ===== FUN_2010738c @ 2010738c (24 bytes)

void FUN_2010738c(void)

{
  FUN_201071c8();
  DAT_20800129 = 0;
  return;
}


// ===== FUN_201073a4 @ 201073a4 (1800 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_201073a4(uint param_1)

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
  
  iVar4 = FUN_20107210(&local_28);
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
  FUN_20121858(uVar5 | 1,uVar1);
  FUN_20121858(uVar5,uVar1);
LAB_20107d28:
  if (uVar3 == 0x1b) {
    FUN_20107324();
  }
  else if (uVar3 == 8) {
    FUN_201072fc();
  }
  else if (uVar7 != 0) {
    FUN_201072d8(uVar7);
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
  iVar1 = FUN_201070e0(auStack_18);
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


// ===== FUN_20107e90 @ 20107e90 (12 bytes)

undefined1 FUN_20107e90(void)

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
  FUN_2010a630();
  return;
}


// ===== FUN_20107ee0 @ 20107ee0 (62 bytes)

undefined * FUN_20107ee0(void)

{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  
  iVar1 = 2;
  puVar2 = &DAT_20811080;
  while (bVar3 = iVar1 != 0, iVar1 = iVar1 + -1, bVar3) {
    FUN_2015f0cc(puVar2);
    puVar2 = puVar2 + 0xd0;
  }
  return &DAT_20811080;
}


// ===== vk_key_name @ 20107efc (2420 bytes)

/* USB keyboard VK_* names */

void vk_key_name(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  DAT_2045c290 = 8;
  DAT_2045c294 = 0x425f4b56;
  DAT_2045c298 = 0x4b4341;
  DAT_2045c2b4 = 0xd;
  FUN_20163770(&DAT_2045c2b8,"VK_RETURN");
  DAT_2045c2d8 = 0x14;
  FUN_20155310(&DAT_2045c2dc,"VK_CAPITAL",0xb);
  DAT_2045c2fc = 0x20;
  FUN_201637bc(&DAT_2045c300,"VK_SPACE");
  DAT_2045c320 = 0x25;
  DAT_2045c324 = 0x4c5f4b56;
  DAT_2045c328 = 0x544645;
  DAT_2045c344 = 0x26;
  DAT_2045c348 = 0x4b56;
  DAT_2045c34a = 0x555f;
  DAT_2045c34c = 0x50;
  DAT_2045c368 = 0x27;
  FUN_201637bc(&DAT_2045c36c,"VK_RIGHT");
  DAT_2045c38c = 0x28;
  iVar1 = 8;
  DAT_2045c390 = 0x445f4b56;
  DAT_2045c394 = 0x4e574f;
  DAT_2045c3b0 = 0x30;
  FUN_2016378c(&DAT_2045c3b4,&DAT_2010833c);
  iVar3 = 1;
  do {
    iVar1 = iVar1 + 1;
    (&DAT_2045c290)[iVar1 * 9] = iVar3 + 0x30;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_%d",iVar3);
    iVar4 = iVar1 * 0x24;
    iVar3 = iVar3 + 1;
    (&DAT_2045c294)[iVar1 * 9] = local_40;
    (&DAT_2045c298)[iVar1 * 9] = local_3c;
    *(undefined4 *)(iVar4 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar4 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar4 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar4 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar4 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar4 + 0x2045c2b0) = local_24;
  } while (iVar3 < 10);
  iVar3 = 0;
  do {
    iVar2 = iVar1;
    iVar1 = iVar2 + 1;
    (&DAT_2045c290)[iVar1 * 9] = iVar3 + 0x41;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_%c",iVar3 + 0x41);
    iVar4 = iVar1 * 0x24;
    iVar3 = iVar3 + 1;
    (&DAT_2045c294)[iVar1 * 9] = local_40;
    (&DAT_2045c298)[iVar1 * 9] = local_3c;
    *(undefined4 *)(iVar4 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar4 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar4 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar4 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar4 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar4 + 0x2045c2b0) = local_24;
  } while (iVar3 < 0x1a);
  iVar2 = iVar2 + 2;
  (&DAT_2045c290)[iVar2 * 9] = 0x60;
  FUN_20155310(&DAT_2045c294 + iVar2 * 9,"VK_NUMPAD0",0xb);
  iVar1 = 1;
  do {
    iVar4 = iVar2;
    iVar2 = iVar4 + 1;
    (&DAT_2045c290)[iVar2 * 9] = iVar1 + 0x60;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_NUMPAD%d",iVar1);
    iVar3 = iVar2 * 0x24;
    iVar1 = iVar1 + 1;
    (&DAT_2045c294)[iVar2 * 9] = local_40;
    (&DAT_2045c298)[iVar2 * 9] = local_3c;
    *(undefined4 *)(iVar3 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar3 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar3 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar3 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar3 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar3 + 0x2045c2b0) = local_24;
  } while (iVar1 < 10);
  iVar1 = iVar4 + 2;
  (&DAT_2045c290)[iVar1 * 9] = 0x6a;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_M",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"ULTI",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"PLY",4);
  (&DAT_2045c290)[(iVar4 + 3) * 9] = 0x6b;
  FUN_201637a0(&DAT_2045c294 + (iVar4 + 3) * 9,"VK_ADD");
  iVar1 = iVar4 + 4;
  (&DAT_2045c290)[iVar1 * 9] = 0x6d;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_S",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"UBTR",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ACT",4);
  (&DAT_2045c290)[(iVar4 + 5) * 9] = 0x6e;
  FUN_20155310(&DAT_2045c294 + (iVar4 + 5) * 9,"VK_DECIMAL",0xb);
  iVar4 = iVar4 + 6;
  (&DAT_2045c290)[iVar4 * 9] = 0x6f;
  FUN_20163770(&DAT_2045c294 + iVar4 * 9,"VK_DIVIDE");
  iVar1 = 0;
  do {
    iVar2 = iVar4;
    iVar4 = iVar2 + 1;
    (&DAT_2045c290)[iVar4 * 9] = iVar1 + 0x70;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_F%d",iVar1 + 1);
    iVar3 = iVar4 * 0x24;
    iVar1 = iVar1 + 1;
    (&DAT_2045c294)[iVar4 * 9] = local_40;
    (&DAT_2045c298)[iVar4 * 9] = local_3c;
    *(undefined4 *)(iVar3 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar3 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar3 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar3 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar3 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar3 + 0x2045c2b0) = local_24;
  } while (iVar1 < 0xc);
  (&DAT_2045c290)[(iVar2 + 2) * 9] = 0xa0;
  FUN_20163770(&DAT_2045c294 + (iVar2 + 2) * 9,"VK_LSHIFT");
  (&DAT_2045c290)[(iVar2 + 3) * 9] = 0xa1;
  FUN_20163770(&DAT_2045c294 + (iVar2 + 3) * 9,"VK_RSHIFT");
  iVar1 = iVar2 + 4;
  iVar3 = iVar2 + 5;
  (&DAT_2045c290)[iVar1 * 9] = 0xa2;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_L",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"CONT",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ROL",4);
  (&DAT_2045c290)[iVar3 * 9] = 0xa3;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar3 * 9),"VK_R",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar3 * 9),"CONT",4);
  builtin_strncpy((char *)(iVar3 * 0x24 + 0x2045c29c),"ROL",4);
  (&DAT_2045c290)[(iVar2 + 6) * 9] = 0xa4;
  FUN_201637bc(&DAT_2045c294 + (iVar2 + 6) * 9,"VK_LMENU");
  (&DAT_2045c290)[(iVar2 + 7) * 9] = 0xa5;
  FUN_201637bc(&DAT_2045c294 + (iVar2 + 7) * 9,"VK_RMENU");
  (&DAT_2045c290)[(iVar2 + 8) * 9] = 0xb1;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 8) * 9,"VK_OEM_EXCLAMATION",0x13);
  (&DAT_2045c290)[(iVar2 + 9) * 9] = 0xb2;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 9) * 9,"VK_OEM_DOUBLEQUOTE",0x13);
  (&DAT_2045c290)[(iVar2 + 10) * 9] = 0xb3;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 10) * 9,"VK_OEM_SHARP",0xd);
  (&DAT_2045c290)[(iVar2 + 0xb) * 9] = 0xb4;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xb) * 9,"VK_OEM_DOLLAR",0xe);
  (&DAT_2045c290)[(iVar2 + 0xc) * 9] = 0xb5;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xc) * 9,"VK_OEM_PERCENT",0xf);
  (&DAT_2045c290)[(iVar2 + 0xd) * 9] = 0xb6;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xd) * 9,"VK_OEM_AMPERSAND",0x11);
  (&DAT_2045c290)[(iVar2 + 0xe) * 9] = 0xb7;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xe) * 9,"VK_OEM_SINGLEQUOTE",0x13);
  (&DAT_2045c290)[(iVar2 + 0xf) * 9] = 0xb8;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xf) * 9,"VK_OEM_PARENTHESIS_1",0x15);
  (&DAT_2045c290)[(iVar2 + 0x10) * 9] = 0xb9;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x10) * 9,"VK_OEM_PARENTHESIS_2",0x15);
  (&DAT_2045c290)[(iVar2 + 0x11) * 9] = 0xba;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x11) * 9,"VK_OEM_COLON",0xd);
  iVar1 = iVar2 + 0x12;
  (&DAT_2045c290)[iVar1 * 9] = 0xbb;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_P",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"LUS",4);
  (&DAT_2045c290)[(iVar2 + 0x13) * 9] = 0xbc;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x13) * 9,"VK_OEM_COMMA",0xd);
  (&DAT_2045c290)[(iVar2 + 0x14) * 9] = 0xbd;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x14) * 9,"VK_OEM_MINUS",0xd);
  (&DAT_2045c290)[(iVar2 + 0x15) * 9] = 0xbe;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x15) * 9,"VK_OEM_PERIOD",0xe);
  (&DAT_2045c290)[(iVar2 + 0x16) * 9] = 0xbf;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x16) * 9,"VK_OEM_SLASH",0xd);
  (&DAT_2045c290)[(iVar2 + 0x17) * 9] = 0xc0;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x17) * 9,"VK_OEM_ATMARK",0xe);
  iVar1 = iVar2 + 0x18;
  (&DAT_2045c290)[iVar1 * 9] = 0xc1;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_A",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"STER",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"ISK",4);
  (&DAT_2045c290)[(iVar2 + 0x19) * 9] = 0xc2;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x19) * 9,"VK_OEM_SEMICOLON",0x11);
  iVar1 = iVar2 + 0x1a;
  (&DAT_2045c290)[iVar1 * 9] = 0xc3;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_L",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ESST",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"HAN",4);
  (&DAT_2045c290)[(iVar2 + 0x1b) * 9] = 0xc4;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1b) * 9,"VK_OEM_EQUAL",0xd);
  (&DAT_2045c290)[(iVar2 + 0x1c) * 9] = 0xc5;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1c) * 9,"VK_OEM_GREATERTHAN",0x13);
  iVar1 = iVar2 + 0x1d;
  (&DAT_2045c290)[iVar1 * 9] = 0xc6;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_Q",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"UEST",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"ION",4);
  (&DAT_2045c290)[(iVar2 + 0x1e) * 9] = 199;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1e) * 9,"VK_OEM_BACKQUOTE",0x11);
  (&DAT_2045c290)[(iVar2 + 0x1f) * 9] = 200;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1f) * 9,"VK_OEM_BRACKET_1",0x11);
  (&DAT_2045c290)[(iVar2 + 0x20) * 9] = 0xc9;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x20) * 9,"VK_OEM_BRACKET_2",0x11);
  (&DAT_2045c290)[(iVar2 + 0x21) * 9] = 0xca;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x21) * 9,"VK_OEM_HAT",0xb);
  (&DAT_2045c290)[(iVar2 + 0x22) * 9] = 0xcb;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x22) * 9,"VK_OEM_BRACKET_3",0x11);
  (&DAT_2045c290)[(iVar2 + 0x23) * 9] = 0xcc;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x23) * 9,"VK_OEM_BRACKET_4",0x11);
  (&DAT_2045c290)[(iVar2 + 0x24) * 9] = 0xcd;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x24) * 9,"VK_OEM_TILDE",0xd);
  iVar1 = iVar2 + 0x25;
  (&DAT_2045c290)[iVar1 * 9] = 0xce;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_U",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"BAR",4);
  (&DAT_2045c290)[(iVar2 + 0x26) * 9] = 0x1b;
  FUN_20163770(&DAT_2045c294 + (iVar2 + 0x26) * 9,"VK_ESCAPE");
  iVar1 = iVar2 + 0x27;
  (&DAT_2045c290)[iVar1 * 9] = 0xcf;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_V",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ERTI",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"CAL",4);
  (&DAT_2045c290)[(iVar2 + 0x28) * 9] = 0xd0;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x28) * 9,"VK_OEM_BACKSLASH",0x11);
  iVar2 = iVar2 + 0x29;
  (&DAT_2045c290)[iVar2 * 9] = 0xd8;
  builtin_strncpy((char *)(iVar2 * 0x24 + 0x2045c29c),"TER",4);
  builtin_strncpy((char *)(&DAT_2045c294 + iVar2 * 9),"VK_N",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar2 * 9),"UMEN",4);
  return;
}


// ===== FUN_20108bc8 @ 20108bc8 (1240 bytes)

void FUN_20108bc8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(&DAT_20450290 + param_1 * 0x600) = 0x2a;
  param_1 = param_1 * 0x600;
  *(undefined4 *)(&DAT_20450298 + param_1) = 8;
  *(undefined4 *)(&DAT_2045029c + param_1) = 0x28;
  *(undefined4 *)(&DAT_20450294 + param_1) = 0;
  *(undefined4 *)(&DAT_204502a4 + param_1) = 0xd;
  *(undefined4 *)(&DAT_204502a8 + param_1) = 0x39;
  *(undefined4 *)(&DAT_204502ac + param_1) = 1;
  *(undefined4 *)(&DAT_204502b0 + param_1) = 0x14;
  *(undefined4 *)(&DAT_204502a0 + param_1) = 0;
  *(undefined4 *)(&DAT_204502b4 + param_1) = 0x2c;
  *(undefined4 *)(&DAT_204502b8 + param_1) = 0;
  *(undefined4 *)(&DAT_204502bc + param_1) = 0x20;
  *(undefined4 *)(&DAT_204502c0 + param_1) = 0x50;
  *(undefined4 *)(&DAT_204502c4 + param_1) = 0;
  *(undefined4 *)(&DAT_204502c8 + param_1) = 0x25;
  *(undefined4 *)(&DAT_204502cc + param_1) = 0x52;
  *(undefined4 *)(&DAT_204502d0 + param_1) = 0;
  *(undefined4 *)(&DAT_204502d4 + param_1) = 0x26;
  *(undefined4 *)(&DAT_204502d8 + param_1) = 0x4f;
  *(undefined4 *)(&DAT_204502dc + param_1) = 0;
  *(undefined4 *)(&DAT_204502e0 + param_1) = 0x27;
  *(undefined4 *)(&DAT_204502e4 + param_1) = 0x51;
  *(undefined4 *)(&DAT_204502ec + param_1) = 0x28;
  iVar2 = 1;
  *(undefined4 *)(&DAT_204502f0 + param_1) = 0x27;
  *(undefined4 *)(&DAT_204502e8 + param_1) = 0;
  *(undefined4 *)(&DAT_204502f4 + param_1) = 0;
  *(undefined4 *)(&DAT_204502f8 + param_1) = 0x30;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0x60) = iVar2 + 0x1d;
    iVar3 = iVar2 + 0x30;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 100) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0x68) = iVar3;
  } while (iVar2 < 10);
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0xd8) = iVar2 + 4;
    iVar3 = iVar2 + 0x41;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 0xdc) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0xe0) = iVar3;
  } while (iVar2 < 0x1a);
  *(undefined4 *)(&DAT_204504b8 + param_1) = 0x62;
  *(undefined4 *)(&DAT_204504bc + param_1) = 0;
  *(undefined4 *)(&DAT_204504c0 + param_1) = 0x60;
  iVar2 = 1;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0x228) = iVar2 + 0x58;
    iVar3 = iVar2 + 0x60;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 0x22c) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0x230) = iVar3;
  } while (iVar2 < 10);
  *(undefined4 *)(&DAT_20450530 + param_1) = 0x55;
  *(undefined4 *)(&DAT_20450534 + param_1) = 0;
  *(undefined4 *)(&DAT_20450538 + param_1) = 0x6a;
  *(undefined4 *)(&DAT_2045053c + param_1) = 0x57;
  *(undefined4 *)(&DAT_20450540 + param_1) = 0;
  *(undefined4 *)(&DAT_20450544 + param_1) = 0x6b;
  *(undefined4 *)(&DAT_20450548 + param_1) = 0x56;
  *(undefined4 *)(&DAT_2045054c + param_1) = 0;
  *(undefined4 *)(&DAT_20450550 + param_1) = 0x6d;
  *(undefined4 *)(&DAT_20450554 + param_1) = 99;
  *(undefined4 *)(&DAT_20450558 + param_1) = 0;
  *(undefined4 *)(&DAT_2045055c + param_1) = 0x6e;
  *(undefined4 *)(&DAT_20450560 + param_1) = 0x54;
  *(undefined4 *)(&DAT_20450564 + param_1) = 0;
  *(undefined4 *)(&DAT_20450568 + param_1) = 0x6f;
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0x2dc) = iVar2 + 0x3a;
    iVar3 = iVar2 + 0x70;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 0x2e0) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0x2e4) = iVar3;
  } while (iVar2 < 0xc);
  *(undefined4 *)(&DAT_204505fc + param_1) = 0xe1;
  *(undefined4 *)(&DAT_20450600 + param_1) = 0;
  *(undefined4 *)(&DAT_20450604 + param_1) = 0xa0;
  *(undefined4 *)(&DAT_20450608 + param_1) = 0xe5;
  *(undefined4 *)(&DAT_2045060c + param_1) = 0;
  *(undefined4 *)(&DAT_20450610 + param_1) = 0xa1;
  *(undefined4 *)(&DAT_20450614 + param_1) = 0xe0;
  *(undefined4 *)(&DAT_20450618 + param_1) = 0;
  *(undefined4 *)(&DAT_2045061c + param_1) = 0xa2;
  *(undefined4 *)(&DAT_20450620 + param_1) = 0xe4;
  *(undefined4 *)(&DAT_20450624 + param_1) = 0;
  *(undefined4 *)(&DAT_20450628 + param_1) = 0xa3;
  *(undefined4 *)(&DAT_2045062c + param_1) = 0xe2;
  *(undefined4 *)(&DAT_20450630 + param_1) = 0;
  *(undefined4 *)(&DAT_20450634 + param_1) = 0xa4;
  *(undefined4 *)(&DAT_20450638 + param_1) = 0xe6;
  *(undefined4 *)(&DAT_2045063c + param_1) = 0;
  *(undefined4 *)(&DAT_20450640 + param_1) = 0xa5;
  *(undefined4 *)(&DAT_20450644 + param_1) = 0x1e;
  *(undefined4 *)(&DAT_20450648 + param_1) = 1;
  *(undefined4 *)(&DAT_2045064c + param_1) = 0xb1;
  *(undefined4 *)(&DAT_20450650 + param_1) = 0x1f;
  *(undefined4 *)(&DAT_20450654 + param_1) = 1;
  *(undefined4 *)(&DAT_20450658 + param_1) = 0xb2;
  *(undefined4 *)(&DAT_2045065c + param_1) = 0x20;
  *(undefined4 *)(&DAT_20450664 + param_1) = 0xb3;
  *(undefined4 *)(&DAT_20450668 + param_1) = 0x21;
  *(undefined4 *)(&DAT_20450660 + param_1) = 1;
  *(undefined4 *)(&DAT_20450670 + param_1) = 0xb4;
  *(undefined4 *)(&DAT_20450674 + param_1) = 0x22;
  *(undefined4 *)(&DAT_2045066c + param_1) = 1;
  *(undefined4 *)(&DAT_2045067c + param_1) = 0xb5;
  *(undefined4 *)(&DAT_20450680 + param_1) = 0x23;
  *(undefined4 *)(&DAT_20450678 + param_1) = 1;
  *(undefined4 *)(&DAT_20450688 + param_1) = 0xb6;
  *(undefined4 *)(&DAT_2045068c + param_1) = 0x24;
  *(undefined4 *)(&DAT_20450684 + param_1) = 1;
  *(undefined4 *)(&DAT_20450694 + param_1) = 0xb7;
  *(undefined4 *)(&DAT_20450698 + param_1) = 0x25;
  *(undefined4 *)(&DAT_20450690 + param_1) = 1;
  *(undefined4 *)(&DAT_204506a0 + param_1) = 0xb8;
  *(undefined4 *)(&DAT_204506a4 + param_1) = 0x26;
  *(undefined4 *)(&DAT_2045069c + param_1) = 1;
  *(undefined4 *)(&DAT_204506ac + param_1) = 0xb9;
  *(undefined4 *)(&DAT_204506b0 + param_1) = 0x34;
  *(undefined4 *)(&DAT_204506b8 + param_1) = 0xba;
  *(undefined4 *)(&DAT_204506bc + param_1) = 0x33;
  *(undefined4 *)(&DAT_204506a8 + param_1) = 1;
  *(undefined4 *)(&DAT_204506b4 + param_1) = 0;
  *(undefined4 *)(&DAT_204506c4 + param_1) = 0xbb;
  *(undefined4 *)(&DAT_204506c8 + param_1) = 0x36;
  *(undefined4 *)(&DAT_204506d0 + param_1) = 0xbc;
  *(undefined4 *)(&DAT_204506d4 + param_1) = 0x2d;
  *(undefined4 *)(&DAT_204506c0 + param_1) = 1;
  *(undefined4 *)(&DAT_204506cc + param_1) = 0;
  *(undefined4 *)(&DAT_204506dc + param_1) = 0xbd;
  *(undefined4 *)(&DAT_204506e0 + param_1) = 0x37;
  *(undefined4 *)(&DAT_204506d8 + param_1) = 0;
  *(undefined4 *)(&DAT_204506e8 + param_1) = 0xbe;
  *(undefined4 *)(&DAT_204506ec + param_1) = 0x38;
  *(undefined4 *)(&DAT_204506e4 + param_1) = 0;
  *(undefined4 *)(&DAT_204506f4 + param_1) = 0xbf;
  *(undefined4 *)(&DAT_204506f8 + param_1) = 0x2f;
  *(undefined4 *)(&DAT_204506f0 + param_1) = 0;
  *(undefined4 *)(&DAT_204506fc + param_1) = 0;
  *(undefined4 *)(&DAT_20450700 + param_1) = 0xc0;
  *(undefined4 *)(&DAT_20450704 + param_1) = 0x34;
  *(undefined4 *)(&DAT_20450708 + param_1) = 1;
  *(undefined4 *)(&DAT_2045070c + param_1) = 0xc1;
  *(undefined4 *)(&DAT_20450714 + param_1) = 0;
  *(undefined4 *)(&DAT_20450718 + param_1) = 0xc2;
  *(undefined4 *)(&DAT_20450720 + param_1) = 1;
  *(undefined4 *)(&DAT_20450724 + param_1) = 0xc3;
  *(undefined4 *)(&DAT_20450710 + param_1) = 0x33;
  *(undefined4 *)(&DAT_2045071c + param_1) = 0x36;
  *(undefined4 *)(&DAT_20450728 + param_1) = 0x2d;
  *(undefined4 *)(&DAT_2045072c + param_1) = 1;
  *(undefined4 *)(&DAT_20450730 + param_1) = 0xc4;
  *(undefined4 *)(&DAT_20450734 + param_1) = 0x37;
  *(undefined4 *)(&DAT_20450738 + param_1) = 1;
  *(undefined4 *)(&DAT_2045073c + param_1) = 0xc5;
  *(undefined4 *)(&DAT_20450740 + param_1) = 0x38;
  *(undefined4 *)(&DAT_2045074c + param_1) = 0x2f;
  *(undefined4 *)(&DAT_20450744 + param_1) = 1;
  *(undefined4 *)(&DAT_20450748 + param_1) = 0xc6;
  *(undefined4 *)(&DAT_20450754 + param_1) = 199;
  *(undefined4 *)(&DAT_20450758 + param_1) = 0x30;
  *(undefined4 *)(&DAT_20450760 + param_1) = 200;
  *(undefined4 *)(&DAT_20450764 + param_1) = 0x32;
  *(undefined4 *)(&DAT_20450750 + param_1) = 1;
  *(undefined4 *)(&DAT_2045075c + param_1) = 0;
  *(undefined4 *)(&DAT_20450768 + param_1) = 0;
  *(undefined4 *)(&DAT_2045076c + param_1) = 0xc9;
  *(undefined4 *)(&DAT_2045077c + param_1) = 0x30;
  *(undefined4 *)(&DAT_20450788 + param_1) = 0x32;
  *(undefined4 *)(&DAT_20450780 + param_1) = 1;
  *(undefined4 *)(&DAT_20450784 + param_1) = 0xcb;
  *(undefined4 *)(&DAT_20450774 + param_1) = 0;
  *(undefined4 *)(&DAT_20450778 + param_1) = 0xca;
  *(undefined4 *)(&DAT_20450770 + param_1) = 0x2e;
  *(undefined4 *)(&DAT_20450790 + param_1) = 0xcc;
  *(undefined4 *)(&DAT_20450794 + param_1) = 0x2e;
  *(undefined4 *)(&DAT_2045078c + param_1) = 1;
  *(undefined4 *)(&DAT_2045079c + param_1) = 0xcd;
  *(undefined4 *)(&DAT_204507a0 + param_1) = 0x87;
  *(undefined4 *)(&DAT_20450798 + param_1) = 1;
  *(undefined4 *)(&DAT_204507a4 + param_1) = 1;
  *(undefined4 *)(&DAT_204507a8 + param_1) = 0xce;
  *(undefined4 *)(&DAT_204507ac + param_1) = 0x29;
  *(undefined4 *)(&DAT_204507b0 + param_1) = 0;
  *(undefined4 *)(&DAT_204507b4 + param_1) = 0x1b;
  *(undefined4 *)(&DAT_204507bc + param_1) = 1;
  *(undefined4 *)(&DAT_204507c4 + param_1) = 0x87;
  *(undefined4 *)(&DAT_204507c8 + param_1) = 0;
  *(undefined4 *)(&DAT_204507cc + param_1) = 0xd0;
  *(undefined4 *)(&DAT_204507d0 + param_1) = 0x58;
  *(undefined4 *)(&DAT_204507d4 + param_1) = 0;
  *(undefined4 *)(&DAT_204507b8 + param_1) = 0x89;
  *(undefined4 *)(&DAT_204507c0 + param_1) = 0xcf;
  *(undefined4 *)(&DAT_204507d8 + param_1) = 0xd8;
  return;
}

