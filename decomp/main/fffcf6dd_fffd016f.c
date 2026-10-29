// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== sd_memlist_load_start @ fffcf6dd (26 bytes)

/* MEM LIST LOAD after the confirmation: 0x15DE5 = 1 (memory list), op +0x1E4 = 1, sd_load_start
   (#65) */

void sd_memlist_load_start(void)

{
  DAT_00015de5 = 1;
  PTR_DAT_00025d60[0x1e4] = 1;
  sd_load_start();
  return;
}


// ===== sd_load_start @ fffcf6f7 (137 bytes)

/* Mode 1: +0x88 = 1, 0x15DE3 = 1, step +0x3F7 = 1, first request frame 0x43 (+0x1E0) (#65) */

void sd_load_start(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 1;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e5] = 0;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== menu_m4_17_1_enter @ fffcf780 (13 bytes)

/* Menu item m4_17_1 MEM LIST SAVE: on_enter (#74) */

void menu_m4_17_1_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(2);
  if (iVar1 != 1) {
    return;
  }
  sd_memlist_save_start();
  return;
}


// ===== sd_memlist_save_start @ fffcf78d (26 bytes)

/* MEM LIST SAVE: 0x15DE5 = 1, op 2, sd_save_start (#65) */

void sd_memlist_save_start(void)

{
  DAT_00015de5 = 1;
  PTR_DAT_00025d60[0x1e4] = 2;
  sd_save_start();
  return;
}


// ===== sd_save_start @ fffcf7a7 (137 bytes)

/* Mode 2: as sd_load_start with 0x15DE3 = 2 (#65) */

void sd_save_start(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 2;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e5] = 0;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== menu_m4_17_2_enter @ fffcf830 (13 bytes)

/* Menu item m4_17_2 MENU LOAD: on_enter (#74) */

void menu_m4_17_2_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(2);
  if (iVar1 != 1) {
    return;
  }
  sd_menu_load_start();
  return;
}


// ===== sd_menu_load_start @ fffcf83d (26 bytes)

/* MENU LOAD: 0x15DE5 = 0 (menu settings), op 3, sd_load_start (#65) */

void sd_menu_load_start(void)

{
  DAT_00015de5 = 0;
  PTR_DAT_00025d60[0x1e4] = 3;
  sd_load_start();
  return;
}


// ===== menu_m4_17_3_enter @ fffcf857 (13 bytes)

/* Menu item m4_17_3 MENU SAVE: on_enter (#74) */

void menu_m4_17_3_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(2);
  if (iVar1 != 1) {
    return;
  }
  sd_menu_save_start();
  return;
}


// ===== sd_menu_save_start @ fffcf864 (26 bytes)

/* MENU SAVE: 0x15DE5 = 0, op 4, sd_save_start (#65) */

void sd_menu_save_start(void)

{
  DAT_00015de5 = 0;
  PTR_DAT_00025d60[0x1e4] = 4;
  sd_save_start();
  return;
}


// ===== menu_m4_17_4_enter @ fffcf87e (13 bytes)

/* Menu item m4_17_4 INFORMATIONS: on_enter (#74) */

void menu_m4_17_4_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(2);
  if (iVar1 != 1) {
    return;
  }
  sd_info_start();
  return;
}


// ===== sd_info_start @ fffcf88b (150 bytes)

/* INFORMATIONS: mode 3, op 5, first frame 0x43 (#65) */

void sd_info_start(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 3;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e4] = 5;
  PTR_DAT_00025d60[0x1e5] = 1;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== menu_m4_17_5_enter @ fffcf921 (13 bytes)

/* Menu item m4_17_5 FIRMWARE UPDATE: on_enter (#74) */

void menu_m4_17_5_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(1);
  if (iVar1 != 1) {
    return;
  }
  sd_op_clear();
  return;
}


// ===== sd_op_clear @ fffcf92e (22 bytes)

/* +0x88 = 0, 0x15DE3 = 0: no SD operation running (#65) */

void sd_op_clear(void)

{
  PTR_DAT_00025d60[0x88] = 0;
  DAT_00015de3 = 0;
  return;
}


// ===== menu_m4_17_6_enter @ fffcf944 (13 bytes)

/* Menu item m4_17_6 FORMAT: on_enter (#74) */

void menu_m4_17_6_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(2);
  if (iVar1 != 1) {
    return;
  }
  sd_format_start();
  return;
}


// ===== sd_format_start @ fffcf951 (150 bytes)

/* FORMAT: mode 4, op 8, first frame 0x43 (#65) */

void sd_format_start(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 4;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e4] = 8;
  PTR_DAT_00025d60[0x1e5] = 0;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== menu_m4_19_0_enter @ fffcf9e7 (48 bytes)

/* Menu item m4_19_0 CALIBRATION: on_enter (#74) */

void menu_m4_19_0_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(0);
  if (iVar1 != 1) {
    return;
  }
  PTR_DAT_00025d60[0x80] = 1;
  PTR_DAT_00025d60[0x81] = 1;
  PTR_DAT_00025d60[0x3ff] = 2;
  return;
}


// ===== menu_m4_20_0_enter @ fffcfa17 (15 bytes)

/* Menu item m4_20_0 MEMORY CLEAR: on_enter (#74) */

void menu_m4_20_0_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(0);
  if (iVar1 != 1) {
    return;
  }
  FUN_fffcfa26(0);
  return;
}


// ===== FUN_fffcfa26 @ fffcfa26 (23 bytes)

void FUN_fffcfa26(undefined1 param_1)

{
  PTR_DAT_00025d60[0xbb] = 0xe;
  FUN_fffcfa3d(param_1);
  return;
}


// ===== FUN_fffcfa3d @ fffcfa3d (55 bytes)

void FUN_fffcfa3d(undefined1 param_1)

{
  PTR_DAT_00025d60[0x86] = 1;
  PTR_DAT_00025d60[0x448] = 1;
  PTR_DAT_00025d60[0xbc] = param_1;
  PTR_DAT_00025d60[0xbd] = 0;
  return;
}


// ===== menu_m4_20_1_enter @ fffcfa74 (15 bytes)

/* Menu item m4_20_1 MENU CLEAR: on_enter (#74) */

void menu_m4_20_1_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(0);
  if (iVar1 != 1) {
    return;
  }
  FUN_fffcfa26(1);
  return;
}


// ===== menu_m4_20_2_enter @ fffcfa83 (15 bytes)

/* Menu item m4_20_2 ALL RESET: on_enter (#74) */

void menu_m4_20_2_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(0);
  if (iVar1 != 1) {
    return;
  }
  FUN_fffcfa92(2);
  return;
}


// ===== FUN_fffcfa92 @ fffcfa92 (23 bytes)

void FUN_fffcfa92(undefined1 param_1)

{
  PTR_DAT_00025d60[0xbb] = 0;
  FUN_fffcfa3d(param_1);
  return;
}


// ===== FUN_fffcfaa9 @ fffcfaa9 (86 bytes)

undefined1 FUN_fffcfaa9(undefined2 param_1)

{
  undefined1 local_4;
  
  if (DAT_00015de3 == '\x04') {
    local_4 = FUN_fffcffd6(param_1);
  }
  else if (DAT_00015de3 == '\x01') {
    local_4 = FUN_fffcfb26(param_1);
  }
  else if (DAT_00015de3 == '\x02') {
    local_4 = FUN_fffcfd45(param_1);
  }
  else if (DAT_00015de3 == '\x03') {
    local_4 = FUN_fffcff9b(param_1);
  }
  else if (DAT_00015de3 == '\0') {
    local_4 = FUN_fffcfaff(param_1);
  }
  else {
    local_4 = 2;
  }
  return local_4;
}


// ===== FUN_fffcfaff @ fffcfaff (39 bytes)

undefined1 FUN_fffcfaff(int param_1)

{
  undefined1 local_4;
  
  if (param_1 == 0x166) {
    PTR_DAT_00025d60[0x47b] = 1;
    local_4 = FUN_fffcfe77();
  }
  else {
    local_4 = 1;
  }
  return local_4;
}


// ===== FUN_fffcfb26 @ fffcfb26 (116 bytes)

undefined1 FUN_fffcfb26(ushort param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if ((param_1 < 0x150) || (0x159 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return 0;
  }
  bVar2 = (char)param_1 + 0xb0;
  if (5 < bVar2) {
    if (bVar2 == 6) {
      uVar3 = FUN_fffcfbee();
      return uVar3;
    }
    if (bVar2 == 7) {
      uVar3 = FUN_fffcfc02();
      return uVar3;
    }
    if (bVar2 != 9) {
      return 0;
    }
    DAT_00015de8 = 0xff;
    bVar2 = DAT_00015de8;
  }
  DAT_00015de8 = bVar2;
  uVar3 = FUN_fffcfb9a();
  return uVar3;
}


// ===== FUN_fffcfb9a @ fffcfb9a (84 bytes)

undefined1 FUN_fffcfb9a(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    if (DAT_00015de8 == 0xff) {
      local_2 = FUN_fffcfe77();
    }
    else if ((uint)DAT_00015de6 < DAT_00015de8 + 1) {
      local_2 = 0;
    }
    else {
      FUN_fffd0902();
      FUN_fffd06d4();
      local_2 = 1;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffcfbee @ fffcfbee (20 bytes)

undefined1 FUN_fffcfbee(void)

{
  FUN_fffcfc16(1);
  beep_request(1);
  return 0;
}


// ===== FUN_fffcfc02 @ fffcfc02 (20 bytes)

undefined1 FUN_fffcfc02(void)

{
  FUN_fffcfc16(0);
  beep_request(1);
  return 0;
}


// ===== FUN_fffcfc16 @ fffcfc16 (58 bytes)

void FUN_fffcfc16(undefined1 param_1)

{
  DAT_00015dfa = 1;
  if (DAT_00015de3 == '\x01') {
    FUN_fffcfc50(param_1);
  }
  else if (DAT_00015de3 == '\x02') {
    FUN_fffcfe83(param_1);
  }
  DAT_00015dfa = 0;
  return;
}


// ===== FUN_fffcfc50 @ fffcfc50 (174 bytes)

void FUN_fffcfc50(char param_1)

{
  if (param_1 == '\0') {
    if (DAT_00015de8 != 0xff) {
      if (3 < DAT_00015de8) {
        if ((uint)DAT_00015de7 + (uint)DAT_00015de8 + 1 < (uint)DAT_00015de6) {
          FUN_fffcfcfe(DAT_00015de7 + 1 & 0xff,DAT_00015de8);
          return;
        }
        FUN_fffcfd1b();
        return;
      }
      if ((byte)(DAT_00015de8 + 1) < DAT_00015de6) {
        FUN_fffcfcfe(DAT_00015de7,DAT_00015de8 + 1);
        return;
      }
      FUN_fffcfd1b();
      return;
    }
  }
  else {
    if (DAT_00015de8 == 0xff) {
      FUN_fffcfcfe(DAT_00015de7,DAT_00015de9);
      return;
    }
    if (DAT_00015de8 != 0) {
      FUN_fffcfcfe(DAT_00015de7,DAT_00015de8 - 1);
      return;
    }
    if (DAT_00015de7 != 0) {
      FUN_fffcfcfe(DAT_00015de7 - 1,0);
      return;
    }
  }
  return;
}


// ===== FUN_fffcfcfe @ fffcfcfe (29 bytes)

void FUN_fffcfcfe(undefined1 param_1,undefined1 param_2)

{
  DAT_00015de7 = param_1;
  DAT_00015de8 = param_2;
  FUN_fffd0902();
  return;
}


// ===== FUN_fffcfd1b @ fffcfd1b (42 bytes)

void FUN_fffcfd1b(undefined1 param_1)

{
  if (DAT_00015dfa != '\0') {
    return;
  }
  DAT_00015de9 = DAT_00015de8;
  FUN_fffcfcfe(param_1,0xff);
  return;
}


// ===== FUN_fffcfd45 @ fffcfd45 (133 bytes)

undefined1 FUN_fffcfd45(ushort param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if ((param_1 < 0x140) || (0x149 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return 0;
  }
  bVar2 = (char)param_1 - 0x40;
  if (5 < bVar2) {
    if (bVar2 == 6) {
      uVar3 = FUN_fffcfe4f();
      return uVar3;
    }
    if (bVar2 == 7) {
      uVar3 = FUN_fffcfe63();
      return uVar3;
    }
    if (bVar2 == 8) {
      DAT_00015de8 = 0xfe;
      bVar2 = DAT_00015de8;
    }
    else {
      if (bVar2 != 9) {
        return 0;
      }
      DAT_00015de8 = 0xff;
      bVar2 = DAT_00015de8;
    }
  }
  DAT_00015de8 = bVar2;
  uVar3 = FUN_fffcfdca();
  return uVar3;
}


// ===== FUN_fffcfdca @ fffcfdca (99 bytes)

undefined1 FUN_fffcfdca(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    if (DAT_00015de8 == 0xff) {
      local_2 = FUN_fffcfe77();
    }
    else if (DAT_00015de8 == 0xfe) {
      local_2 = FUN_fffcfe2d();
    }
    else if ((uint)DAT_00015de6 < DAT_00015de8 + 1) {
      local_2 = 0;
    }
    else {
      local_2 = FUN_fffcfe2d();
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffcfe2d @ fffcfe2d (34 bytes)

undefined1 FUN_fffcfe2d(void)

{
  FUN_fffd0bb0();
  PTR_DAT_00025d60[0x3f7] = 99;
  DAT_00015dfb = 0;
  return 1;
}


// ===== FUN_fffcfe4f @ fffcfe4f (20 bytes)

undefined1 FUN_fffcfe4f(void)

{
  FUN_fffcfc16(1);
  beep_request(1);
  return 2;
}


// ===== FUN_fffcfe63 @ fffcfe63 (20 bytes)

undefined1 FUN_fffcfe63(void)

{
  FUN_fffcfc16(0);
  beep_request(1);
  return 2;
}


// ===== FUN_fffcfe77 @ fffcfe77 (12 bytes)

undefined1 FUN_fffcfe77(void)

{
  FUN_fffd0149();
  return 1;
}


// ===== FUN_fffcfe83 @ fffcfe83 (209 bytes)

void FUN_fffcfe83(char param_1)

{
  if (param_1 == '\0') {
    if (DAT_00015de8 != 0xff) {
      if (DAT_00015de8 == 0xfe) {
        FUN_fffcff54(DAT_00015de7,0xff);
        return;
      }
      if (3 < DAT_00015de8) {
        if ((uint)DAT_00015de7 + (uint)DAT_00015de8 + 1 < (uint)DAT_00015de6) {
          FUN_fffcff54(DAT_00015de7 + 1 & 0xff,DAT_00015de8);
          return;
        }
        FUN_fffcff71();
        return;
      }
      if ((byte)(DAT_00015de8 + 1) < DAT_00015de6) {
        FUN_fffcff54(DAT_00015de7,DAT_00015de8 + 1);
        return;
      }
      FUN_fffcff71();
      return;
    }
  }
  else {
    if (DAT_00015de8 == 0xff) {
      FUN_fffcff54(DAT_00015de7,0xfe);
      return;
    }
    if (DAT_00015de8 == 0xfe) {
      FUN_fffcff54(DAT_00015de7,DAT_00015de9);
      return;
    }
    if (DAT_00015de8 != 0) {
      FUN_fffcff54(DAT_00015de7,DAT_00015de8 - 1);
      return;
    }
    if (DAT_00015de7 != 0) {
      FUN_fffcff54(DAT_00015de7 - 1,0);
      return;
    }
  }
  return;
}


// ===== FUN_fffcff54 @ fffcff54 (29 bytes)

void FUN_fffcff54(undefined1 param_1,undefined1 param_2)

{
  DAT_00015de7 = param_1;
  DAT_00015de8 = param_2;
  FUN_fffd0bb0();
  return;
}


// ===== FUN_fffcff71 @ fffcff71 (42 bytes)

void FUN_fffcff71(undefined1 param_1)

{
  if (DAT_00015dfa != '\0') {
    return;
  }
  DAT_00015de9 = DAT_00015de8;
  FUN_fffcff54(param_1,0xfe);
  return;
}


// ===== FUN_fffcff9b @ fffcff9b (25 bytes)

undefined1 FUN_fffcff9b(int param_1)

{
  undefined1 local_4;
  
  if (param_1 == 0x170) {
    local_4 = FUN_fffcffb4();
  }
  else {
    local_4 = 0;
  }
  return local_4;
}


// ===== FUN_fffcffb4 @ fffcffb4 (34 bytes)

undefined1 FUN_fffcffb4(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    local_2 = FUN_fffcfe77();
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffcffd6 @ fffcffd6 (55 bytes)

undefined1 FUN_fffcffd6(uint param_1)

{
  undefined1 uVar1;
  
  if (param_1 == 0x181) {
    DAT_00015de8 = 0xff;
  }
  else {
    if ((param_1 & 0xffff) != 0x180) {
      return 0;
    }
    DAT_00015de8 = 0xfe;
  }
  uVar1 = FUN_fffd000d();
  return uVar1;
}


// ===== FUN_fffd000d @ fffd000d (57 bytes)

undefined1 FUN_fffd000d(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    if (DAT_00015de8 == -1) {
      local_2 = FUN_fffcfe77();
    }
    else {
      FUN_fffd1683();
      FUN_fffd16f7();
      local_2 = 1;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffd0046 @ fffd0046 (102 bytes)

void FUN_fffd0046(short param_1)

{
  undefined1 local_4;
  
  param_1 = param_1 + -0xfe;
  if (PTR_DAT_00025d60[0x88] == '\x01') {
    local_4 = (undefined1)param_1;
    FUN_fffd00fa(local_4);
    return;
  }
  if (PTR_DAT_00025d60[0x93] != '\x01') {
    if (param_1 != 1) {
      FUN_fffd0234();
      return;
    }
    FUN_fffd038d();
    return;
  }
  if (param_1 != 0) {
    PTR_DAT_00025d60[0x3f8] = 1;
    PTR_DAT_00025d60[0x3f9] = 1;
    FUN_fffd038d();
    return;
  }
  FUN_fffd0234();
  return;
}


// ===== FUN_fffd00ac @ fffd00ac (78 bytes)

void FUN_fffd00ac(void)

{
  if (PTR_DAT_00025d60[0x88] == '\x01') {
    FUN_fffd00fa();
    return;
  }
  if (PTR_DAT_00025d60[0xbd] != '\x01') {
    FUN_fffd0234();
    return;
  }
  if (PTR_DAT_00025d60[0x93] != '\x01') {
    FUN_fffd038d();
    return;
  }
  PTR_DAT_00025d60[0x3f8] = 1;
  PTR_DAT_00025d60[0x3f9] = 1;
  FUN_fffd038d();
  return;
}


// ===== FUN_fffd00fa @ fffd00fa (79 bytes)

void FUN_fffd00fa(undefined1 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)PTR_DAT_00025d60[0xbb];
  if (uVar1 == 0xf) {
    FUN_fffd01f3();
    return;
  }
  if (uVar1 == 7) {
    FUN_fffd016f(param_1);
    return;
  }
  if (uVar1 != 8) {
    if (uVar1 == 9) {
      FUN_fffd0194(param_1);
      return;
    }
    if (uVar1 == 10) {
      FUN_fffd01cd();
      return;
    }
    if ((3 < uVar1 - 0xb) && (3 < uVar1 - 3)) {
      return;
    }
  }
  FUN_fffd0149();
  return;
}


// ===== FUN_fffd0149 @ fffd0149 (38 bytes)

void FUN_fffd0149(void)

{
  PTR_DAT_00025d60[0x88] = 0;
  PTR_DAT_00025d60[0x86] = 0;
  PTR_DAT_00025d60[0x3ff] = 2;
  return;
}


// ===== FUN_fffd016f @ fffd016f (37 bytes)

void FUN_fffd016f(char param_1)

{
  PTR_DAT_00025d60[0x86] = 0;
  if (param_1 != '\x01') {
    FUN_fffd03ac();
    FUN_fffd041e();
    FUN_fffd04a6();
    return;
  }
  FUN_fffd0149();
  return;
}

