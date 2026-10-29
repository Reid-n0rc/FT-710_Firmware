// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffcdd0f @ fffcdd0f (111 bytes)

undefined1 FUN_fffcdd0f(void)

{
  byte bVar1;
  char *pcVar2;
  undefined1 uStack_9;
  
  bVar1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar2 = (char *)menu_cursor_of(bVar1);
  if (pcVar2 == (char *)0x0) {
    uStack_9 = 0;
  }
  else {
    bVar1 = menu_count_items(bVar1);
    if (bVar1 < 5) {
      uStack_9 = 0;
    }
    else if ((int)(uint)(byte)pcVar2[1] < (int)(bVar1 - 5)) {
      pcVar2[1] = pcVar2[1] + '\x01';
      if (*pcVar2 != '\0') {
        *pcVar2 = *pcVar2 + -1;
      }
      uStack_9 = FUN_fffcdce3();
    }
    else {
      uStack_9 = 0;
    }
  }
  return uStack_9;
}


// ===== menu_ui_step @ fffcdd7e (93 bytes)

/* Front panel: dial step on the selected row (timer 3000, sets 0x20F0F, menu_call_step) */

void menu_ui_step(void)

{
  char *pcVar1;
  undefined1 uStack_4;
  byte bStack_3;
  char cStack_2;
  byte bStack_1;
  
  FUN_fffc8f30(3000);
  PTR_DAT_00025d60[0x40b] = 1;
  bStack_1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar1 = (char *)menu_cursor_of(bStack_1);
  if (pcVar1 == (char *)0x0) {
    return;
  }
  uStack_4 = PTR_DAT_00025d60[0x41f];
  bStack_3 = bStack_1;
  cStack_2 = *pcVar1 + pcVar1[1];
  menu_call_step((uint)&uStack_4);
  return;
}


// ===== menu_apply_from_cat @ fffcdddb (42 bytes)

/* Set 0x15DFC=1, menu_call_step(key), clear, set state+0x40B (0x20F0F) refresh flag */

void menu_apply_from_cat(uint param_1)

{
  DAT_00015dfc = 1;
  menu_call_step(param_1);
  DAT_00015dfc = 0;
  PTR_DAT_00025d60[0x40b] = 1;
  return;
}


// ===== menu_ex010101_step @ fffcde05 (19 bytes)

/* Menu item ex010101 AF TREBLE GAIN: on_step (#74) */

void menu_ex010101_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a2a);
  return;
}


// ===== menu_step_s8 @ fffcde18 (74 bytes)

/* Generic signed stepper (min, max, ptr); no-op when 0x15DFC=1 (CAT apply); direction state+0x421
    */

void menu_step_s8(char param_1,char param_2,char *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + '\x01';
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 + -1;
      return;
    }
  }
  return;
}


// ===== menu_ex010102_step @ fffcde62 (19 bytes)

/* Menu item ex010102 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010102_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a2b);
  return;
}


// ===== menu_ex010103_step @ fffcde75 (19 bytes)

/* Menu item ex010103 AF BASS GAIN: on_step (#74) */

void menu_ex010103_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a2c);
  return;
}


// ===== menu_ex010104_step @ fffcde88 (19 bytes)

/* Menu item ex010104 AGC FAST DELAY: on_step (#74) */

void menu_ex010104_step(void)

{
  menu_step_u8(0,199,&DAT_00009a2d);
  return;
}


// ===== menu_ex010105_step @ fffcde9b (19 bytes)

/* Menu item ex010105 AGC MID DELAY: on_step (#74) */

void menu_ex010105_step(void)

{
  menu_step_u8(0,199,&DAT_00009a2e);
  return;
}


// ===== menu_ex010106_step @ fffcdeae (19 bytes)

/* Menu item ex010106 AGC SLOW DELY: on_step (#74) */

void menu_ex010106_step(void)

{
  menu_step_u8(0,199,&DAT_00009a2f);
  return;
}


// ===== menu_ex010107_step @ fffcdec1 (14 bytes)

/* Menu item ex010107 LCUT FREQ: on_step (#74) */

void menu_ex010107_step(void)

{
  FUN_fffcdecf(&DAT_00009a30);
  return;
}


// ===== FUN_fffcdecf @ fffcdecf (72 bytes)

void FUN_fffcdecf(byte *param_1)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      *param_1 = *param_1 + 1;
      if (0x13 < *param_1) {
        *param_1 = 0x13;
        return;
      }
    }
    else if (*param_1 != 0) {
      *param_1 = *param_1 - 1;
      return;
    }
  }
  return;
}


// ===== menu_ex010108_step @ fffcdf17 (18 bytes)

/* Menu item ex010108 LCUT SLOPE: on_step (#74) */

void menu_ex010108_step(void)

{
  menu_step_u8(0,1,&DAT_00009a31);
  return;
}


// ===== menu_ex010109_step @ fffcdf29 (14 bytes)

/* Menu item ex010109 HCUT FREQ: on_step (#74) */

void menu_ex010109_step(void)

{
  FUN_fffcdf37(&DAT_00009a32);
  return;
}


// ===== FUN_fffcdf37 @ fffcdf37 (92 bytes)

void FUN_fffcdf37(byte *param_1)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if ((*param_1 != 0) && (*param_1 = *param_1 + 1, 0x43 < *param_1)) {
        *param_1 = 0;
        return;
      }
    }
    else {
      if (*param_1 == 0) {
        *param_1 = 0x43;
        return;
      }
      if (*param_1 != 1) {
        *param_1 = *param_1 - 1;
        return;
      }
    }
  }
  return;
}


// ===== menu_ex010110_step @ fffcdf93 (18 bytes)

/* Menu item ex010110 HCUT SLOPE: on_step (#74) */

void menu_ex010110_step(void)

{
  menu_step_u8(0,1,&DAT_00009a33);
  return;
}


// ===== menu_ex010111_step @ fffcdfa5 (19 bytes)

/* Menu item ex010111 USB OUT LEVEL: on_step (#74) */

void menu_ex010111_step(void)

{
  menu_step_u8(0,100,&DAT_00009a34);
  return;
}


// ===== menu_step_u8 @ fffcdfb8 (72 bytes)

/* Generic unsigned stepper (min, max, ptr) [inference: unsigned twin of menu_step_s8] */

void menu_step_u8(byte param_1,byte param_2,byte *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 - 1;
      return;
    }
  }
  return;
}


// ===== menu_ex010112_step @ fffce000 (19 bytes)

/* Menu item ex010112 REAR OUT LEVEL: on_step (#74) */

void menu_ex010112_step(void)

{
  menu_step_u8(0,100,&DAT_00009a35);
  return;
}


// ===== menu_ex010113_step @ fffce013 (183 bytes)

/* Menu item ex010113 TX BPF SEL: on_step (#74) */

void menu_ex010113_step(void)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  
  bVar2 = false;
  if ((DAT_00015dfc == '\x01') || (menu_step_u8(0,6,&DAT_00009a36), DAT_00009a36 < 5)) {
    return;
  }
  uVar3 = dest_code_get();
  if ((uVar3 == 0x315b) || (uVar3 == 0x50e2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (uVar3 == 0x1cb9)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_00004760 != '\0')) {
    bVar2 = true;
  }
  if (PTR_DAT_00025d60[0x421] == '\0') {
    if (bVar2) {
      DAT_00009a36 = 6;
      return;
    }
    DAT_00009a36 = 4;
    return;
  }
  DAT_00009a36 = 4;
  return;
}


// ===== menu_ex010114_step @ fffce0ca (18 bytes)

/* Menu item ex010114 MOD SOURCE: on_step (#74) */

void menu_ex010114_step(void)

{
  menu_step_u8(0,3,&DAT_00009a37);
  return;
}


// ===== menu_ex010115_step @ fffce0dc (19 bytes)

/* Menu item ex010115 USB MOD GAIN: on_step (#74) */

void menu_ex010115_step(void)

{
  menu_step_u8(0,100,&DAT_00009a38);
  return;
}


// ===== menu_ex010116_step @ fffce0ef (19 bytes)

/* Menu item ex010116 REAR MOD GAIN: on_step (#74) */

void menu_ex010116_step(void)

{
  menu_step_u8(0,100,&DAT_00009a39);
  return;
}


// ===== menu_ex010117_step @ fffce102 (18 bytes)

/* Menu item ex010117 RPTT SELECT: on_step (#74) */

void menu_ex010117_step(void)

{
  menu_step_u8(0,3,&DAT_00009a3a);
  return;
}


// ===== menu_ex010118_step @ fffce114 (19 bytes)

/* Menu item ex010118 NAR WIDTH: on_step (#74) */

void menu_ex010118_step(void)

{
  menu_step_u8(0,0x16,&DAT_00009a3b);
  return;
}


// ===== menu_ex010119_step @ fffce127 (18 bytes)

/* Menu item ex010119 CW AUTO MODE: on_step (#74) */

void menu_ex010119_step(void)

{
  menu_step_u8(0,2,&DAT_00009a3c);
  return;
}


// ===== menu_ex010201_step @ fffce139 (19 bytes)

/* Menu item ex010201 AF TREBLE GAIN: on_step (#74) */

void menu_ex010201_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a3f);
  return;
}


// ===== menu_ex010202_step @ fffce14c (19 bytes)

/* Menu item ex010202 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010202_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a40);
  return;
}


// ===== menu_ex010203_step @ fffce15f (19 bytes)

/* Menu item ex010203 AF BASS GAIN: on_step (#74) */

void menu_ex010203_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a41);
  return;
}


// ===== menu_ex010204_step @ fffce172 (19 bytes)

/* Menu item ex010204 AGC FAST DELAY: on_step (#74) */

void menu_ex010204_step(void)

{
  menu_step_u8(0,199,&DAT_00009a42);
  return;
}


// ===== menu_ex010205_step @ fffce185 (19 bytes)

/* Menu item ex010205 AGC MID DELAY: on_step (#74) */

void menu_ex010205_step(void)

{
  menu_step_u8(0,199,&DAT_00009a43);
  return;
}


// ===== menu_ex010206_step @ fffce198 (19 bytes)

/* Menu item ex010206 AGC SLOW DELAY: on_step (#74) */

void menu_ex010206_step(void)

{
  menu_step_u8(0,199,&DAT_00009a44);
  return;
}


// ===== menu_ex010207_step @ fffce1ab (14 bytes)

/* Menu item ex010207 LCUT FREQ: on_step (#74) */

void menu_ex010207_step(void)

{
  FUN_fffcdecf(&DAT_00009a45);
  return;
}


// ===== menu_ex010208_step @ fffce1b9 (18 bytes)

/* Menu item ex010208 LCUT SLOPE: on_step (#74) */

void menu_ex010208_step(void)

{
  menu_step_u8(0,1,&DAT_00009a46);
  return;
}


// ===== menu_ex010209_step @ fffce1cb (14 bytes)

/* Menu item ex010209 HCUT FREQ: on_step (#74) */

void menu_ex010209_step(void)

{
  FUN_fffcdf37(&DAT_00009a47);
  return;
}


// ===== menu_ex010210_step @ fffce1d9 (18 bytes)

/* Menu item ex010210 HCUT SLOPE: on_step (#74) */

void menu_ex010210_step(void)

{
  menu_step_u8(0,1,&DAT_00009a48);
  return;
}


// ===== menu_ex010211_step @ fffce1eb (19 bytes)

/* Menu item ex010211 USB OUT LEVEL: on_step (#74) */

void menu_ex010211_step(void)

{
  menu_step_u8(0,100,&DAT_00009a49);
  return;
}


// ===== menu_ex010212_step @ fffce1fe (19 bytes)

/* Menu item ex010212 REAR OUT LEVEL: on_step (#74) */

void menu_ex010212_step(void)

{
  menu_step_u8(0,100,&DAT_00009a4a);
  return;
}


// ===== menu_ex010213_step @ fffce211 (18 bytes)

/* Menu item ex010213 TX BPF SEL: on_step (#74) */

void menu_ex010213_step(void)

{
  menu_step_u8(0,4,&DAT_00009a4b);
  return;
}


// ===== menu_ex010214_step @ fffce223 (18 bytes)

/* Menu item ex010214 MOD SOURCE: on_step (#74) */

void menu_ex010214_step(void)

{
  menu_step_u8(0,3,&DAT_00009a4c);
  return;
}


// ===== menu_ex010215_step @ fffce235 (19 bytes)

/* Menu item ex010215 USB MOD GAIN: on_step (#74) */

void menu_ex010215_step(void)

{
  menu_step_u8(0,100,&DAT_00009a4d);
  return;
}


// ===== menu_ex010216_step @ fffce248 (19 bytes)

/* Menu item ex010216 REAR MOD GAIN: on_step (#74) */

void menu_ex010216_step(void)

{
  menu_step_u8(0,100,&DAT_00009a4e);
  return;
}


// ===== menu_ex010217_step @ fffce25b (18 bytes)

/* Menu item ex010217 RPTT SELECT: on_step (#74) */

void menu_ex010217_step(void)

{
  menu_step_u8(0,3,&DAT_00009a4f);
  return;
}


// ===== menu_ex010301_step @ fffce26d (19 bytes)

/* Menu item ex010301 AF TREBLE GAIN: on_step (#74) */

void menu_ex010301_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a52);
  return;
}


// ===== menu_ex010302_step @ fffce280 (19 bytes)

/* Menu item ex010302 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010302_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a53);
  return;
}


// ===== menu_ex010303_step @ fffce293 (19 bytes)

/* Menu item ex010303 AF BASS GAIN: on_step (#74) */

void menu_ex010303_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a54);
  return;
}


// ===== menu_ex010304_step @ fffce2a6 (19 bytes)

/* Menu item ex010304 AGC FAST DELAY: on_step (#74) */

void menu_ex010304_step(void)

{
  menu_step_u8(0,199,&DAT_00009a55);
  return;
}


// ===== menu_ex010305_step @ fffce2b9 (19 bytes)

/* Menu item ex010305 AGC MID DELAY: on_step (#74) */

void menu_ex010305_step(void)

{
  menu_step_u8(0,199,&DAT_00009a56);
  return;
}


// ===== menu_ex010306_step @ fffce2cc (19 bytes)

/* Menu item ex010306 AGC SLOW DELAY: on_step (#74) */

void menu_ex010306_step(void)

{
  menu_step_u8(0,199,&DAT_00009a57);
  return;
}


// ===== menu_ex010307_step @ fffce2df (14 bytes)

/* Menu item ex010307 LCUT FREQ: on_step (#74) */

void menu_ex010307_step(void)

{
  FUN_fffcdecf(&DAT_00009a58);
  return;
}

