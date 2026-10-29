// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_init @ fffd4ff1 (13 bytes)

/* Calls menu_build_all */

void menu_init(void)

{
  DAT_0001fa4e = 0;
  menu_build_all();
  return;
}


// ===== menu_get_limits @ fffd4ffe (78 bytes)

/* key -> 16 bytes desc+0x28..0x37 (min,max,store,flags) */

byte menu_get_limits(char *key,byte *lim)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_45;
  byte abStack_44 [40];
  byte abStack_1c [18];
  byte bStack_a;
  byte *local_8;
  char *local_4;
  
  if ((key == (char *)0x0) || (lim == (byte *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_45 = 0;
  }
  else {
    local_8 = lim;
    local_4 = key;
    bStack_a = menu_get_desc(key,abStack_44);
    if (bStack_a == 0) {
      local_45 = 0;
    }
    else {
      pbVar2 = abStack_1c;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *local_8 = *pbVar2;
        local_8 = local_8 + 1;
        pbVar2 = pbVar2 + 1;
      }
      local_45 = 1;
    }
  }
  return local_45;
}


// ===== menu_value_rw @ fffd504c (343 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd51a0) */
/* WARNING: Removing unreachable block (ram,0xfffd50f0) */
/* (key, 0=read/1=write, u16*): byte or big-endian word at desc.store, or FM VFO accessor (desc+0x35
   = 1/2/3) */

byte menu_value_rw(int param_1,char param_2,ushort *param_3)

{
  ushort uVar1;
  bool bVar2;
  ushort *puVar3;
  byte bVar4;
  byte local_55;
  byte abStack_54 [44];
  byte *pbStack_28;
  char cStack_23;
  char cStack_1f;
  byte *pbStack_1c;
  byte bStack_17;
  byte bStack_12;
  ushort *local_10;
  char local_9;
  int local_8;
  
  if ((param_1 == 0) || (param_3 == (ushort *)0x0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    local_55 = 0;
  }
  else {
    if ((param_2 == '\0') || (param_2 == '\x01')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      local_55 = 0;
    }
    else {
      local_10 = param_3;
      local_9 = param_2;
      local_8 = param_1;
      bStack_12 = menu_get_desc((char *)param_1,abStack_54);
      puVar3 = local_10;
      if (bStack_12 == 0) {
        local_55 = 0;
      }
      else {
        pbStack_1c = pbStack_28;
        if (local_9 == '\0') {
          if (cStack_1f == '\0') {
            if (cStack_23 == '\0') {
              *local_10 = (ushort)*pbStack_28;
            }
            else {
              *local_10 = CONCAT11(*pbStack_28,pbStack_28[1]);
            }
          }
          else if (cStack_1f == '\x03') {
            bVar4 = menu_fm_tone_get();
            *puVar3 = (ushort)bVar4;
          }
          else if (cStack_1f == '\x02') {
            bVar4 = menu_fm_encdec_get();
            *puVar3 = (ushort)bVar4;
          }
          else {
            if (cStack_1f != '\x01') {
              return 0;
            }
            bVar4 = menu_fm_rptshift_get();
            *puVar3 = (ushort)bVar4;
          }
        }
        else if (cStack_1f == '\0') {
          if (cStack_23 == '\0') {
            *pbStack_28 = (byte)*local_10;
          }
          else {
            uVar1 = *local_10;
            *pbStack_28 = (byte)(uVar1 >> 8);
            pbStack_28[1] = (byte)uVar1;
          }
        }
        else {
          bStack_17 = (byte)*local_10;
          if (cStack_1f == '\x03') {
            menu_fm_tone_set(bStack_17);
          }
          else if (cStack_1f == '\x02') {
            menu_fm_encdec_set(bStack_17);
          }
          else {
            if (cStack_1f != '\x01') {
              return 0;
            }
            menu_fm_rptshift_set(bStack_17);
          }
        }
        local_55 = 1;
      }
    }
  }
  return local_55;
}


// ===== menu_value_get @ fffd51a3 (39 bytes)

/* menu_value_rw(key, 0, p) */

byte menu_value_get(char *key,ushort *val)

{
  undefined1 local_b;
  
  if (key == (char *)0x0) {
    local_b = 0;
  }
  else {
    local_b = menu_value_rw((int)key,'\0',val);
  }
  return local_b;
}


// ===== menu_value_set @ fffd51ca (39 bytes)

/* menu_value_rw(key, 1, p) */

byte menu_value_set(char *key,ushort *val)

{
  undefined1 local_b;
  
  if (key == (char *)0x0) {
    local_b = 0;
  }
  else {
    local_b = menu_value_rw((int)key,'\x01',val);
  }
  return local_b;
}


// ===== menu_string_rw @ fffd51f1 (156 bytes)

/* (key, rw, buf, n): copy text item (MY CALL, PRESET NAME) */

byte menu_string_rw(int param_1,char param_2,int param_3,byte param_4)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  byte local_4d;
  byte abStack_4c [44];
  undefined4 *puStack_20;
  byte local_d;
  undefined1 *local_c;
  char local_5;
  int local_4;
  
  if ((param_1 == 0) || (param_3 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_4d = 0;
  }
  else if (param_4 == 0) {
    local_4d = 0;
  }
  else {
    if ((param_2 == '\0') || (param_2 == '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_4d = 0;
    }
    else {
      local_d = param_4;
      local_c = (undefined1 *)param_3;
      local_5 = param_2;
      local_4 = param_1;
      bVar2 = menu_get_desc((char *)param_1,abStack_4c);
      if (bVar2 == 0) {
        local_4d = 0;
      }
      else {
        if (local_5 == '\0') {
          for (uVar3 = (uint)local_d; uVar3 != 0; uVar3 = uVar3 - 1) {
            *local_c = *(undefined1 *)puStack_20;
            local_c = local_c + 1;
            puStack_20 = (undefined4 *)((int)puStack_20 + 1);
          }
        }
        else {
          puStack_20[2] = 0;
          puStack_20[1] = 0;
          *puStack_20 = 0;
          for (uVar3 = (uint)local_d; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puStack_20 = *local_c;
            puStack_20 = (undefined4 *)((int)puStack_20 + 1);
            local_c = local_c + 1;
          }
        }
        local_4d = 1;
      }
    }
  }
  return local_4d;
}


// ===== menu_string_get @ fffd528d (41 bytes)

/* menu_string_rw(key, 0, buf, n) */

byte menu_string_get(int param_1,uint param_2,byte param_3)

{
  undefined1 local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = menu_string_rw(param_1,'\0',param_2,param_3);
  }
  return local_c;
}


// ===== menu_string_set @ fffd52b6 (41 bytes)

/* menu_string_rw(key, 1, buf, n) */

byte menu_string_set(int param_1,uint param_2,byte param_3)

{
  undefined1 local_c;
  
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = menu_string_rw(param_1,'\x01',param_2,param_3);
  }
  return local_c;
}


// ===== menu_p1_range @ fffd52df (148 bytes)

/* P1 -> first/last global P2 (0-4, 5-6, 7-11, 12-15, 16-21, 22-26) */

byte menu_p1_range(char param_1,void *param_2,void *param_3)

{
  bool bVar1;
  byte local_e;
  
  if ((param_2 == (void *)0x0) || (param_3 == (void *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_e = 0;
  }
  else {
    if (param_1 == '\x05') {
      *(undefined1 *)param_2 = 0x16;
      *(undefined1 *)param_3 = 0x1a;
    }
    else if (param_1 == '\x01') {
      *(undefined1 *)param_2 = 5;
      *(undefined1 *)param_3 = 6;
    }
    else if (param_1 == '\x02') {
      *(undefined1 *)param_2 = 7;
      *(undefined1 *)param_3 = 0xb;
    }
    else if (param_1 == '\x03') {
      *(undefined1 *)param_2 = 0xc;
      *(undefined1 *)param_3 = 0xf;
    }
    else if (param_1 == '\x04') {
      *(undefined1 *)param_2 = 0x10;
      *(undefined1 *)param_3 = 0x15;
    }
    else {
      if (param_1 != '\0') {
        return 0;
      }
      *(undefined1 *)param_2 = 0;
      *(undefined1 *)param_3 = 4;
    }
    local_e = 1;
  }
  return local_e;
}


// ===== menuitem_EX010101 @ fffd5373 (110 bytes)

/* Menu item 0.0.0 RADIO SETTING / MODE SSB / AF TREBLE GAIN */

void menuitem_EX010101(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff85866;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010101_draw;
  local_18 = menu_ex010101_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a2a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010102 @ fffd53e1 (110 bytes)

/* Menu item 0.0.1 RADIO SETTING / MODE SSB / AF MIDDLE TONE GAIN */

void menuitem_EX010102(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff8587b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010102_draw;
  local_18 = menu_ex010102_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a2b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010103 @ fffd544f (110 bytes)

/* Menu item 0.0.2 RADIO SETTING / MODE SSB / AF BASS GAIN */

void menuitem_EX010103(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85890;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010103_draw;
  local_18 = menu_ex010103_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a2c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010104 @ fffd54bd (108 bytes)

/* Menu item 0.0.3 RADIO SETTING / MODE SSB / AGC FAST DELAY */

void menuitem_EX010104(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff858a5;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010104_draw;
  local_18 = menu_ex010104_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a2d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010105 @ fffd5529 (108 bytes)

/* Menu item 0.0.4 RADIO SETTING / MODE SSB / AGC MID DELAY */

void menuitem_EX010105(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff858ba;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010105_draw;
  local_18 = menu_ex010105_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a2e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010106 @ fffd5595 (108 bytes)

/* Menu item 0.0.5 RADIO SETTING / MODE SSB / AGC SLOW DELY */

void menuitem_EX010106(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff858cf;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010106_draw;
  local_18 = menu_ex010106_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a2f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010107 @ fffd5601 (108 bytes)

/* Menu item 0.0.6 RADIO SETTING / MODE SSB / LCUT FREQ */

void menuitem_EX010107(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff858e4;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010107_draw;
  local_18 = menu_ex010107_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a30;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010108 @ fffd566d (108 bytes)

/* Menu item 0.0.7 RADIO SETTING / MODE SSB / LCUT SLOPE */

void menuitem_EX010108(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff858f9;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010108_draw;
  local_18 = menu_ex010108_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a31;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010109 @ fffd56d9 (108 bytes)

/* Menu item 0.0.8 RADIO SETTING / MODE SSB / HCUT FREQ */

void menuitem_EX010109(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff8590e;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010109_draw;
  local_18 = menu_ex010109_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a32;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010110 @ fffd5745 (108 bytes)

/* Menu item 0.0.9 RADIO SETTING / MODE SSB / HCUT SLOPE */

void menuitem_EX010110(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff85923;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010110_draw;
  local_18 = menu_ex010110_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a33;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010111 @ fffd57b1 (108 bytes)

/* Menu item 0.0.10 RADIO SETTING / MODE SSB / USB OUT LEVEL */

void menuitem_EX010111(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff85938;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010111_draw;
  local_18 = menu_ex010111_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a34;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010112 @ fffd581d (108 bytes)

/* Menu item 0.0.11 RADIO SETTING / MODE SSB / REAR OUT LEVEL */

void menuitem_EX010112(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff8594d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010112_draw;
  local_18 = menu_ex010112_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a35;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010113 @ fffd5889 (108 bytes)

/* Menu item 0.0.12 RADIO SETTING / MODE SSB / TX BPF SEL */

void menuitem_EX010113(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff85962;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010113_draw;
  local_18 = menu_ex010113_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 6;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a36;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010114 @ fffd58f5 (108 bytes)

/* Menu item 0.0.13 RADIO SETTING / MODE SSB / MOD SOURCE */

void menuitem_EX010114(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff85977;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010114_draw;
  local_18 = menu_ex010114_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a37;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010115 @ fffd5961 (108 bytes)

/* Menu item 0.0.14 RADIO SETTING / MODE SSB / USB MOD GAIN */

void menuitem_EX010115(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff8598c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010115_draw;
  local_18 = menu_ex010115_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a38;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010116 @ fffd59cd (108 bytes)

/* Menu item 0.0.15 RADIO SETTING / MODE SSB / REAR MOD GAIN */

void menuitem_EX010116(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff859a1;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010116_draw;
  local_18 = menu_ex010116_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a39;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010117 @ fffd5a39 (108 bytes)

/* Menu item 0.0.16 RADIO SETTING / MODE SSB / RPTT SELECT */

void menuitem_EX010117(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff859b6;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010117_draw;
  local_18 = menu_ex010117_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a3a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010118 @ fffd5aa5 (108 bytes)

/* Menu item 0.0.17 RADIO SETTING / MODE SSB / NAR WIDTH */

void menuitem_EX010118(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff859cb;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010118_draw;
  local_18 = menu_ex010118_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x16;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a3b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010119 @ fffd5b11 (108 bytes)

/* Menu item 0.0.18 RADIO SETTING / MODE SSB / CW AUTO MODE */

void menuitem_EX010119(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0x12;
  pbVar2 = (byte *)0xfff859e0;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010119_draw;
  local_18 = menu_ex010119_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a3c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010201 @ fffd5b7d (110 bytes)

/* Menu item 0.1.0 RADIO SETTING / MODE AM / AF TREBLE GAIN */

void menuitem_EX010201(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff859f5;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010201_draw;
  local_18 = menu_ex010201_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a3f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010202 @ fffd5beb (110 bytes)

/* Menu item 0.1.1 RADIO SETTING / MODE AM / AF MIDDLE TONE GAIN */

void menuitem_EX010202(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff85a0a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010202_draw;
  local_18 = menu_ex010202_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a40;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010203 @ fffd5c59 (110 bytes)

/* Menu item 0.1.2 RADIO SETTING / MODE AM / AF BASS GAIN */

void menuitem_EX010203(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85a1f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010203_draw;
  local_18 = menu_ex010203_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a41;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010204 @ fffd5cc7 (108 bytes)

/* Menu item 0.1.3 RADIO SETTING / MODE AM / AGC FAST DELAY */

void menuitem_EX010204(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff85a34;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010204_draw;
  local_18 = menu_ex010204_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a42;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010205 @ fffd5d33 (108 bytes)

/* Menu item 0.1.4 RADIO SETTING / MODE AM / AGC MID DELAY */

void menuitem_EX010205(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff85a49;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010205_draw;
  local_18 = menu_ex010205_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a43;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010206 @ fffd5d9f (108 bytes)

/* Menu item 0.1.5 RADIO SETTING / MODE AM / AGC SLOW DELAY */

void menuitem_EX010206(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff85a5e;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010206_draw;
  local_18 = menu_ex010206_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a44;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010207 @ fffd5e0b (108 bytes)

/* Menu item 0.1.6 RADIO SETTING / MODE AM / LCUT FREQ */

void menuitem_EX010207(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff85a73;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010207_draw;
  local_18 = menu_ex010207_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a45;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010208 @ fffd5e77 (108 bytes)

/* Menu item 0.1.7 RADIO SETTING / MODE AM / LCUT SLOPE */

void menuitem_EX010208(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff85a88;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010208_draw;
  local_18 = menu_ex010208_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a46;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010209 @ fffd5ee3 (108 bytes)

/* Menu item 0.1.8 RADIO SETTING / MODE AM / HCUT FREQ */

void menuitem_EX010209(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff85a9d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010209_draw;
  local_18 = menu_ex010209_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a47;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010210 @ fffd5f4f (108 bytes)

/* Menu item 0.1.9 RADIO SETTING / MODE AM / HCUT SLOPE */

void menuitem_EX010210(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff85ab2;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010210_draw;
  local_18 = menu_ex010210_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a48;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010211 @ fffd5fbb (108 bytes)

/* Menu item 0.1.10 RADIO SETTING / MODE AM / USB OUT LEVEL */

void menuitem_EX010211(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff85ac7;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010211_draw;
  local_18 = menu_ex010211_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a49;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010212 @ fffd6027 (108 bytes)

/* Menu item 0.1.11 RADIO SETTING / MODE AM / REAR OUT LEVEL */

void menuitem_EX010212(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff85adc;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010212_draw;
  local_18 = menu_ex010212_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010213 @ fffd6093 (108 bytes)

/* Menu item 0.1.12 RADIO SETTING / MODE AM / TX BPF SEL */

void menuitem_EX010213(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff85af1;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010213_draw;
  local_18 = menu_ex010213_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010214 @ fffd60ff (108 bytes)

/* Menu item 0.1.13 RADIO SETTING / MODE AM / MOD SOURCE */

void menuitem_EX010214(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff85b06;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010214_draw;
  local_18 = menu_ex010214_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010215 @ fffd616b (108 bytes)

/* Menu item 0.1.14 RADIO SETTING / MODE AM / USB MOD GAIN */

void menuitem_EX010215(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff85b1b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010215_draw;
  local_18 = menu_ex010215_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010216 @ fffd61d7 (108 bytes)

/* Menu item 0.1.15 RADIO SETTING / MODE AM / REAR MOD GAIN */

void menuitem_EX010216(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff85b30;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010216_draw;
  local_18 = menu_ex010216_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009a4e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010217 @ fffd6243 (108 bytes)

/* Menu item 0.1.16 RADIO SETTING / MODE AM / RPTT SELECT */

void menuitem_EX010217(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 1;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff85b45;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010217_draw;
  local_18 = menu_ex010217_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009a4f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010301 @ fffd62af (110 bytes)

/* Menu item 0.2.0 RADIO SETTING / MODE FM / AF TREBLE GAIN */

void menuitem_EX010301(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff85b5a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010301_draw;
  local_18 = menu_ex010301_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a52;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010302 @ fffd631d (110 bytes)

/* Menu item 0.2.1 RADIO SETTING / MODE FM / AF MIDDLE TONE GAIN */

void menuitem_EX010302(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff85b6f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010302_draw;
  local_18 = menu_ex010302_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a53;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010303 @ fffd638b (110 bytes)

/* Menu item 0.2.2 RADIO SETTING / MODE FM / AF BASS GAIN */

void menuitem_EX010303(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85b84;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010303_draw;
  local_18 = menu_ex010303_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009a54;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010304 @ fffd63f9 (108 bytes)

/* Menu item 0.2.3 RADIO SETTING / MODE FM / AGC FAST DELAY */

void menuitem_EX010304(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff85b99;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010304_draw;
  local_18 = menu_ex010304_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a55;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010305 @ fffd6465 (108 bytes)

/* Menu item 0.2.4 RADIO SETTING / MODE FM / AGC MID DELAY */

void menuitem_EX010305(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte local_38 [28];
  code *local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 2;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff85bae;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010305_draw;
  local_18 = menu_ex010305_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009a56;
  local_3 = 0;
  menu_register(local_38);
  return;
}

