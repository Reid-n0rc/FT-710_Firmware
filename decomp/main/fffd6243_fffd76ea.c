// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
  undefined4 local_c;
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
  local_c = 0x9a4f;
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
  undefined4 local_c;
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
  local_c = 0x9a52;
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
  undefined4 local_c;
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
  local_c = 0x9a53;
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
  undefined4 local_c;
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
  local_c = 0x9a54;
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
  undefined4 local_c;
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
  local_c = 0x9a55;
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
  undefined4 local_c;
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
  local_c = 0x9a56;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010306 @ fffd64d1 (108 bytes)

/* Menu item 0.2.5 RADIO SETTING / MODE FM / AGC SLOW DELAY */

void menuitem_EX010306(void)

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
  undefined4 local_c;
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
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff85bc3;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010306_draw;
  local_18 = menu_ex010306_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9a57;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010307 @ fffd653d (108 bytes)

/* Menu item 0.2.6 RADIO SETTING / MODE FM / LCUT FREQ */

void menuitem_EX010307(void)

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
  undefined4 local_c;
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
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff85bd8;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010307_draw;
  local_18 = menu_ex010307_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a58;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010308 @ fffd65a9 (108 bytes)

/* Menu item 0.2.7 RADIO SETTING / MODE FM / LCUT SLOPE */

void menuitem_EX010308(void)

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
  undefined4 local_c;
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
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff85bed;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010308_draw;
  local_18 = menu_ex010308_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a59;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010309 @ fffd6615 (108 bytes)

/* Menu item 0.2.8 RADIO SETTING / MODE FM / HCUT FREQ */

void menuitem_EX010309(void)

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
  undefined4 local_c;
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
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff85c02;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010309_draw;
  local_18 = menu_ex010309_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a5a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010310 @ fffd6681 (108 bytes)

/* Menu item 0.2.9 RADIO SETTING / MODE FM / HCUT SLOPE */

void menuitem_EX010310(void)

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
  undefined4 local_c;
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
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff85c17;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010310_draw;
  local_18 = menu_ex010310_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a5b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010311 @ fffd66ed (108 bytes)

/* Menu item 0.2.10 RADIO SETTING / MODE FM / USB OUT LEVEL */

void menuitem_EX010311(void)

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
  undefined4 local_c;
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
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff85c2c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010311_draw;
  local_18 = menu_ex010311_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a5c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010312 @ fffd6759 (108 bytes)

/* Menu item 0.2.11 RADIO SETTING / MODE FM / REAR OUT LEVEL */

void menuitem_EX010312(void)

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
  undefined4 local_c;
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
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff85c41;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010312_draw;
  local_18 = menu_ex010312_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a5d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010313 @ fffd67c5 (108 bytes)

/* Menu item 0.2.12 RADIO SETTING / MODE FM / MOD SOURCE */

void menuitem_EX010313(void)

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
  undefined4 local_c;
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
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff85c56;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010313_draw;
  local_18 = menu_ex010313_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a5e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010314 @ fffd6831 (108 bytes)

/* Menu item 0.2.13 RADIO SETTING / MODE FM / USB MOD GAIN */

void menuitem_EX010314(void)

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
  undefined4 local_c;
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
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff85c6b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010314_draw;
  local_18 = menu_ex010314_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a5f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010315 @ fffd689d (108 bytes)

/* Menu item 0.2.14 RADIO SETTING / MODE FM / REAR MOD GAIN */

void menuitem_EX010315(void)

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
  undefined4 local_c;
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
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff85c80;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010315_draw;
  local_18 = menu_ex010315_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a60;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010316 @ fffd6909 (108 bytes)

/* Menu item 0.2.15 RADIO SETTING / MODE FM / RPTT SELECT */

void menuitem_EX010316(void)

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
  undefined4 local_c;
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
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff85c95;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010316_draw;
  local_18 = menu_ex010316_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a61;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010317 @ fffd6975 (99 bytes)

/* Menu item 0.2.16 RADIO SETTING / MODE FM / RPT SHIFT */

void menuitem_EX010317(void)

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
  undefined4 local_c;
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
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff85caa;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010317_draw;
  local_18 = menu_ex010317_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 1;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010318 @ fffd69d8 (108 bytes)

/* Menu item 0.2.17 RADIO SETTING / MODE FM / RPT SHIFT(28MHz) */

void menuitem_EX010318(void)

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
  undefined4 local_c;
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
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff85cbf;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010318_draw;
  local_18 = menu_ex010318_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = 0x9a62;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010319 @ fffd6a44 (110 bytes)

/* Menu item 0.2.18 RADIO SETTING / MODE FM / RPT SHIFT(50MHz) */

void menuitem_EX010319(void)

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
  undefined4 local_c;
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
  local_38[5] = 0x12;
  pbVar2 = (byte *)0xfff85cd4;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010319_draw;
  local_18 = menu_ex010319_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 400;
  local_8 = 0;
  local_7 = 1;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = 0x9a63;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010320 @ fffd6ab2 (99 bytes)

/* Menu item 0.2.19 RADIO SETTING / MODE FM / ENC/DEC */

void menuitem_EX010320(void)

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
  undefined4 local_c;
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
  local_38[5] = 0x13;
  pbVar2 = (byte *)0xfff85ce9;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010320_draw;
  local_18 = menu_ex010320_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0;
  local_3 = 2;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010321 @ fffd6b15 (99 bytes)

/* Menu item 0.2.20 RADIO SETTING / MODE FM / TONE FREQ */

void menuitem_EX010321(void)

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
  undefined4 local_c;
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
  local_38[5] = 0x14;
  pbVar2 = (byte *)0xfff85cfe;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010321_draw;
  local_18 = menu_ex010321_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x31;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0;
  local_3 = 3;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010401 @ fffd6b78 (110 bytes)

/* Menu item 0.3.0 RADIO SETTING / MODE PSK/DATA / AF TREBLE GAIN */

void menuitem_EX010401(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff85d13;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010401_draw;
  local_18 = menu_ex010401_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a67;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010402 @ fffd6be6 (110 bytes)

/* Menu item 0.3.1 RADIO SETTING / MODE PSK/DATA / AF MIDDLE TONE GAIN */

void menuitem_EX010402(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff85d28;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010402_draw;
  local_18 = menu_ex010402_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a68;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010403 @ fffd6c54 (110 bytes)

/* Menu item 0.3.2 RADIO SETTING / MODE PSK/DATA / AF BASS GAIN */

void menuitem_EX010403(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85d3d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010403_draw;
  local_18 = menu_ex010403_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a69;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010404 @ fffd6cc2 (108 bytes)

/* Menu item 0.3.3 RADIO SETTING / MODE PSK/DATA / AGC FAST DELAY */

void menuitem_EX010404(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff85d52;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010404_draw;
  local_18 = menu_ex010404_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9a6a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010405 @ fffd6d2e (108 bytes)

/* Menu item 0.3.4 RADIO SETTING / MODE PSK/DATA / AGC MID DELAY */

void menuitem_EX010405(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff85d67;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010405_draw;
  local_18 = menu_ex010405_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9a6b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010406 @ fffd6d9a (108 bytes)

/* Menu item 0.3.5 RADIO SETTING / MODE PSK/DATA / AGC SLOW DELAY */

void menuitem_EX010406(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff85d7c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010406_draw;
  local_18 = menu_ex010406_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9a6c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010407 @ fffd6e06 (108 bytes)

/* Menu item 0.3.6 RADIO SETTING / MODE PSK/DATA / LCUT FREQ */

void menuitem_EX010407(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff85d91;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010407_draw;
  local_18 = menu_ex010407_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a6d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010408 @ fffd6e72 (108 bytes)

/* Menu item 0.3.7 RADIO SETTING / MODE PSK/DATA / LCUT SLOPE */

void menuitem_EX010408(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff85da6;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010408_draw;
  local_18 = menu_ex010408_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a6e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010409 @ fffd6ede (108 bytes)

/* Menu item 0.3.8 RADIO SETTING / MODE PSK/DATA / HCUT FREQ */

void menuitem_EX010409(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff85dbb;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010409_draw;
  local_18 = menu_ex010409_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a6f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010410 @ fffd6f4a (108 bytes)

/* Menu item 0.3.9 RADIO SETTING / MODE PSK/DATA / HCUT SLOPE */

void menuitem_EX010410(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff85dd0;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010410_draw;
  local_18 = menu_ex010410_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a70;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010411 @ fffd6fb6 (108 bytes)

/* Menu item 0.3.10 RADIO SETTING / MODE PSK/DATA / USB OUT LEVEL */

void menuitem_EX010411(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff85de5;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010411_draw;
  local_18 = menu_ex010411_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a71;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010412 @ fffd7022 (108 bytes)

/* Menu item 0.3.11 RADIO SETTING / MODE PSK/DATA / REAR OUT LEVEL */

void menuitem_EX010412(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff85dfa;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010412_draw;
  local_18 = menu_ex010412_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a72;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010413 @ fffd708e (108 bytes)

/* Menu item 0.3.12 RADIO SETTING / MODE PSK/DATA / TX BPF SEL */

void menuitem_EX010413(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff85e0f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010413_draw;
  local_18 = menu_ex010413_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a73;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010414 @ fffd70fa (108 bytes)

/* Menu item 0.3.13 RADIO SETTING / MODE PSK/DATA / MOD SOURCE */

void menuitem_EX010414(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff85e24;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010414_draw;
  local_18 = menu_ex010414_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a74;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010415 @ fffd7166 (108 bytes)

/* Menu item 0.3.14 RADIO SETTING / MODE PSK/DATA / USB MOD GAIN */

void menuitem_EX010415(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff85e39;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010415_draw;
  local_18 = menu_ex010415_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a75;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010416 @ fffd71d2 (108 bytes)

/* Menu item 0.3.15 RADIO SETTING / MODE PSK/DATA / REAR MOD GAIN */

void menuitem_EX010416(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff85e4e;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010416_draw;
  local_18 = menu_ex010416_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9a76;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010417 @ fffd723e (108 bytes)

/* Menu item 0.3.16 RADIO SETTING / MODE PSK/DATA / RPTT SELECT */

void menuitem_EX010417(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff85e63;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010417_draw;
  local_18 = menu_ex010417_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a77;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010418 @ fffd72aa (108 bytes)

/* Menu item 0.3.17 RADIO SETTING / MODE PSK/DATA / NAR WIDTH */

void menuitem_EX010418(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff85e78;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010418_draw;
  local_18 = menu_ex010418_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x14;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a78;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010419 @ fffd7316 (108 bytes)

/* Menu item 0.3.18 RADIO SETTING / MODE PSK/DATA / PSK TONE */

void menuitem_EX010419(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0x12;
  pbVar2 = (byte *)0xfff85e8d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010419_draw;
  local_18 = menu_ex010419_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 2;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a79;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010420 @ fffd7382 (110 bytes)

/* Menu item 0.3.19 RADIO SETTING / MODE PSK/DATA / DATA SHIFT (SSB) */

void menuitem_EX010420(void)

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
  undefined4 local_c;
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
  local_38[4] = 3;
  local_38[5] = 0x13;
  pbVar2 = (byte *)0xfff85ea2;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010420_draw;
  local_18 = menu_ex010420_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 300;
  local_8 = 0;
  local_7 = 1;
  local_6 = 0;
  local_5 = 4;
  local_4 = 1;
  local_c = 0x9a7a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010501 @ fffd73f0 (110 bytes)

/* Menu item 0.4.0 RADIO SETTING / MODE RTTY / AF TREBLE GAIN */

void menuitem_EX010501(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff85eb7;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010501_draw;
  local_18 = menu_ex010501_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a7e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010502 @ fffd745e (110 bytes)

/* Menu item 0.4.1 RADIO SETTING / MODE RTTY / AF MIDDLE TONE GAIN */

void menuitem_EX010502(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff85ecc;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010502_draw;
  local_18 = menu_ex010502_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a7f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010503 @ fffd74cc (110 bytes)

/* Menu item 0.4.2 RADIO SETTING / MODE RTTY / AF BASS GAIN */

void menuitem_EX010503(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff85ee1;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010503_draw;
  local_18 = menu_ex010503_step;
  local_14 = menu_enter_nop;
  local_10 = 0xffec;
  local_e = 10;
  local_8 = 0;
  local_7 = 0;
  local_6 = 1;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a80;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010504 @ fffd753a (108 bytes)

/* Menu item 0.4.3 RADIO SETTING / MODE RTTY / AGC FAST DELAY */

void menuitem_EX010504(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff85ef6;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010504_draw;
  local_18 = menu_ex010504_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9a81;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010505 @ fffd75a6 (108 bytes)

/* Menu item 0.4.4 RADIO SETTING / MODE RTTY / AGC MID DELAY */

void menuitem_EX010505(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff85f0b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010505_draw;
  local_18 = menu_ex010505_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9a82;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010506 @ fffd7612 (108 bytes)

/* Menu item 0.4.5 RADIO SETTING / MODE RTTY / AGC SLOW DELAY */

void menuitem_EX010506(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff85f20;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010506_draw;
  local_18 = menu_ex010506_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9a83;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010507 @ fffd767e (108 bytes)

/* Menu item 0.4.6 RADIO SETTING / MODE RTTY / LCUT FREQ */

void menuitem_EX010507(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff85f35;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010507_draw;
  local_18 = menu_ex010507_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9a84;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX010508 @ fffd76ea (108 bytes)

/* Menu item 0.4.7 RADIO SETTING / MODE RTTY / LCUT SLOPE */

void menuitem_EX010508(void)

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
  undefined4 local_c;
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
  local_38[4] = 4;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff85f4a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex010508_draw;
  local_18 = menu_ex010508_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9a85;
  local_3 = 0;
  menu_register(local_38);
  return;
}

