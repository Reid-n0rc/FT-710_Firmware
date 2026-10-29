// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menuitem_EX060118 @ fffdb89c (108 bytes)

/* Menu item 5.22.17 PRESET / PRESET1 / RPTT SELECT */

void menuitem_EX060118(void)

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
  local_38[3] = 5;
  local_38[4] = 0x16;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff86c2b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060118_draw;
  local_18 = menu_ex060118_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b4a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060201 @ fffdb908 (108 bytes)

/* Menu item 5.23.0 PRESET / PRESET2 / PRESET NAME */

void menuitem_EX060201(void)

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
  undefined4 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff86c40;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060201_draw;
  local_18 = menu_step_nop;
  local_14 = menu_ex060101_enter;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b4d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060202 @ fffdb974 (108 bytes)

/* Menu item 5.23.1 PRESET / PRESET2 / CAT-1 RATE */

void menuitem_EX060202(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff86c55;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060202_draw;
  local_18 = menu_ex060202_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b59;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060203 @ fffdb9e0 (108 bytes)

/* Menu item 5.23.2 PRESET / PRESET2 / CAT-1 TIME OUT TIMER */

void menuitem_EX060203(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff86c6a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060203_draw;
  local_18 = menu_ex060203_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b5a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060204 @ fffdba4c (108 bytes)

/* Menu item 5.23.3 PRESET / PRESET2 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060204(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff86c7f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060204_draw;
  local_18 = menu_ex060204_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b5b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060205 @ fffdbab8 (108 bytes)

/* Menu item 5.23.4 PRESET / PRESET2 / AGC FAST DELAY */

void menuitem_EX060205(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff86c94;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060205_draw;
  local_18 = menu_ex060205_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b5c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060206 @ fffdbb24 (108 bytes)

/* Menu item 5.23.5 PRESET / PRESET2 / AGC MID DELAY */

void menuitem_EX060206(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff86ca9;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060206_draw;
  local_18 = menu_ex060206_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b5d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060207 @ fffdbb90 (108 bytes)

/* Menu item 5.23.6 PRESET / PRESET2 / AGC SLOW DELAY */

void menuitem_EX060207(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff86cbe;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060207_draw;
  local_18 = menu_ex060207_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b5e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060208 @ fffdbbfc (108 bytes)

/* Menu item 5.23.7 PRESET / PRESET2 / LCUT FREQ */

void menuitem_EX060208(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff86cd3;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060208_draw;
  local_18 = menu_ex060208_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b5f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060209 @ fffdbc68 (108 bytes)

/* Menu item 5.23.8 PRESET / PRESET2 / LCUT SLOPE */

void menuitem_EX060209(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff86ce8;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060209_draw;
  local_18 = menu_ex060209_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b60;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060210 @ fffdbcd4 (108 bytes)

/* Menu item 5.23.9 PRESET / PRESET2 / HCUT FREQ */

void menuitem_EX060210(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff86cfd;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060210_draw;
  local_18 = menu_ex060210_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b61;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060211 @ fffdbd40 (108 bytes)

/* Menu item 5.23.10 PRESET / PRESET2 / HCUT SLOPE */

void menuitem_EX060211(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff86d12;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060211_draw;
  local_18 = menu_ex060211_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b62;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060212 @ fffdbdac (108 bytes)

/* Menu item 5.23.11 PRESET / PRESET2 / USB OUT LEVEL */

void menuitem_EX060212(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff86d27;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060212_draw;
  local_18 = menu_ex060212_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b63;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060213 @ fffdbe18 (108 bytes)

/* Menu item 5.23.12 PRESET / PRESET2 / REAR OUT LEVEL */

void menuitem_EX060213(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff86d3c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060213_draw;
  local_18 = menu_ex060213_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b64;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060214 @ fffdbe84 (108 bytes)

/* Menu item 5.23.13 PRESET / PRESET2 / TX BPF SEL */

void menuitem_EX060214(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff86d51;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060214_draw;
  local_18 = menu_ex060214_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b65;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060215 @ fffdbef0 (108 bytes)

/* Menu item 5.23.14 PRESET / PRESET2 / MOD SOURCE */

void menuitem_EX060215(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff86d66;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060215_draw;
  local_18 = menu_ex060215_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b66;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060216 @ fffdbf5c (108 bytes)

/* Menu item 5.23.15 PRESET / PRESET2 / USB MOD GAIN */

void menuitem_EX060216(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff86d7b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060216_draw;
  local_18 = menu_ex060216_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b67;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060217 @ fffdbfc8 (108 bytes)

/* Menu item 5.23.16 PRESET / PRESET2 / REAR MOD GAIN */

void menuitem_EX060217(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff86d90;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060217_draw;
  local_18 = menu_ex060217_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b68;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060218 @ fffdc034 (108 bytes)

/* Menu item 5.23.17 PRESET / PRESET2 / RPTT SELECT */

void menuitem_EX060218(void)

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
  local_38[3] = 5;
  local_38[4] = 0x17;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff86da5;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060218_draw;
  local_18 = menu_ex060218_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b69;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060301 @ fffdc0a0 (108 bytes)

/* Menu item 5.24.0 PRESET / PRESET3 / PRESET NAME */

void menuitem_EX060301(void)

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
  undefined4 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff86dba;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060301_draw;
  local_18 = menu_step_nop;
  local_14 = menu_ex060101_enter;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b6c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060302 @ fffdc10c (108 bytes)

/* Menu item 5.24.1 PRESET / PRESET3 / CAT-1 RATE */

void menuitem_EX060302(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff86dcf;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060302_draw;
  local_18 = menu_ex060302_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b78;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060303 @ fffdc178 (108 bytes)

/* Menu item 5.24.2 PRESET / PRESET3 / CAT-1 TIME OUT TIMER */

void menuitem_EX060303(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff86de4;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060303_draw;
  local_18 = menu_ex060303_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b79;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060304 @ fffdc1e4 (108 bytes)

/* Menu item 5.24.3 PRESET / PRESET3 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060304(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff86df9;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060304_draw;
  local_18 = menu_ex060304_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b7a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060305 @ fffdc250 (108 bytes)

/* Menu item 5.24.4 PRESET / PRESET3 / AGC FAST DELAY */

void menuitem_EX060305(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff86e0e;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060305_draw;
  local_18 = menu_ex060305_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b7b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060306 @ fffdc2bc (108 bytes)

/* Menu item 5.24.5 PRESET / PRESET3 / AGC MID DELAY */

void menuitem_EX060306(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff86e23;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060306_draw;
  local_18 = menu_ex060306_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b7c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060307 @ fffdc328 (108 bytes)

/* Menu item 5.24.6 PRESET / PRESET3 / AGC SLOW DELAY */

void menuitem_EX060307(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff86e38;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060307_draw;
  local_18 = menu_ex060307_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b7d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060308 @ fffdc394 (109 bytes)

/* Menu item 5.24.7 PRESET / PRESET3 / LCUT FREQ */

void menuitem_EX060308(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff86e4d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060308_draw;
  local_18 = menu_ex060308_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b7e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060309 @ fffdc401 (109 bytes)

/* Menu item 5.24.8 PRESET / PRESET3 / LCUT SLOPE */

void menuitem_EX060309(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff86e62;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060309_draw;
  local_18 = menu_ex060309_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b7f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060310 @ fffdc46e (109 bytes)

/* Menu item 5.24.9 PRESET / PRESET3 / HCUT FREQ */

void menuitem_EX060310(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff86e77;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060310_draw;
  local_18 = menu_ex060310_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b80;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060311 @ fffdc4db (109 bytes)

/* Menu item 5.24.10 PRESET / PRESET3 / HCUT SLOPE */

void menuitem_EX060311(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff86e8c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060311_draw;
  local_18 = menu_ex060311_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b81;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060312 @ fffdc548 (109 bytes)

/* Menu item 5.24.11 PRESET / PRESET3 / USB OUT LEVEL */

void menuitem_EX060312(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff86ea1;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060312_draw;
  local_18 = menu_ex060312_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b82;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060313 @ fffdc5b5 (109 bytes)

/* Menu item 5.24.12 PRESET / PRESET3 / REAR OUT LEVEL */

void menuitem_EX060313(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff86eb6;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060313_draw;
  local_18 = menu_ex060313_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b83;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060314 @ fffdc622 (109 bytes)

/* Menu item 5.24.13 PRESET / PRESET3 / TX BPF SEL */

void menuitem_EX060314(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff86ecb;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060314_draw;
  local_18 = menu_ex060314_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b84;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060315 @ fffdc68f (109 bytes)

/* Menu item 5.24.14 PRESET / PRESET3 / MOD SOURCE */

void menuitem_EX060315(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff86ee0;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060315_draw;
  local_18 = menu_ex060315_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b85;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060316 @ fffdc6fc (109 bytes)

/* Menu item 5.24.15 PRESET / PRESET3 / USB MOD GAIN */

void menuitem_EX060316(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff86ef5;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060316_draw;
  local_18 = menu_ex060316_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b86;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060317 @ fffdc769 (109 bytes)

/* Menu item 5.24.16 PRESET / PRESET3 / REAR MOD GAIN */

void menuitem_EX060317(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff86f0a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060317_draw;
  local_18 = menu_ex060317_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009b87;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060318 @ fffdc7d6 (109 bytes)

/* Menu item 5.24.17 PRESET / PRESET3 / RPTT SELECT */

void menuitem_EX060318(void)

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
  local_38[3] = 5;
  local_38[4] = 0x18;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff86f1f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060318_draw;
  local_18 = menu_ex060318_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b88;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060401 @ fffdc843 (109 bytes)

/* Menu item 5.25.0 PRESET / PRESET4 / PRESET NAME */

void menuitem_EX060401(void)

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
  undefined4 *local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_38[0] = 1;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff86f34;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060401_draw;
  local_18 = menu_step_nop;
  local_14 = menu_ex060101_enter;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = &DAT_00009b8b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060402 @ fffdc8b0 (109 bytes)

/* Menu item 5.25.1 PRESET / PRESET4 / CAT-1 RATE */

void menuitem_EX060402(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff86f49;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060402_draw;
  local_18 = menu_ex060402_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b97;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060403 @ fffdc91d (109 bytes)

/* Menu item 5.25.2 PRESET / PRESET4 / CAT-1 TIME OUT TIMER */

void menuitem_EX060403(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff86f5e;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060403_draw;
  local_18 = menu_ex060403_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b98;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060404 @ fffdc98a (109 bytes)

/* Menu item 5.25.3 PRESET / PRESET4 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060404(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff86f73;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060404_draw;
  local_18 = menu_ex060404_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b99;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060405 @ fffdc9f7 (109 bytes)

/* Menu item 5.25.4 PRESET / PRESET4 / AGC FAST DELAY */

void menuitem_EX060405(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff86f88;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060405_draw;
  local_18 = menu_ex060405_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b9a;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060406 @ fffdca64 (109 bytes)

/* Menu item 5.25.5 PRESET / PRESET4 / AGC MID DELAY */

void menuitem_EX060406(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff86f9d;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060406_draw;
  local_18 = menu_ex060406_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b9b;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060407 @ fffdcad1 (109 bytes)

/* Menu item 5.25.6 PRESET / PRESET4 / AGC SLOW DELAY */

void menuitem_EX060407(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff86fb2;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060407_draw;
  local_18 = menu_ex060407_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = &DAT_00009b9c;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060408 @ fffdcb3e (109 bytes)

/* Menu item 5.25.7 PRESET / PRESET4 / LCUT FREQ */

void menuitem_EX060408(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff86fc7;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060408_draw;
  local_18 = menu_ex060408_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b9d;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060409 @ fffdcbab (109 bytes)

/* Menu item 5.25.8 PRESET / PRESET4 / LCUT SLOPE */

void menuitem_EX060409(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff86fdc;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060409_draw;
  local_18 = menu_ex060409_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009b9e;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060410 @ fffdcc18 (109 bytes)

/* Menu item 5.25.9 PRESET / PRESET4 / HCUT FREQ */

void menuitem_EX060410(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff86ff1;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060410_draw;
  local_18 = menu_ex060410_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = &DAT_00009b9f;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060411 @ fffdcc85 (109 bytes)

/* Menu item 5.25.10 PRESET / PRESET4 / HCUT SLOPE */

void menuitem_EX060411(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff87006;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060411_draw;
  local_18 = menu_ex060411_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = &DAT_00009ba0;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060412 @ fffdccf2 (109 bytes)

/* Menu item 5.25.11 PRESET / PRESET4 / USB OUT LEVEL */

void menuitem_EX060412(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff8701b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060412_draw;
  local_18 = menu_ex060412_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009ba1;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060413 @ fffdcd5f (109 bytes)

/* Menu item 5.25.12 PRESET / PRESET4 / REAR OUT LEVEL */

void menuitem_EX060413(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff87030;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060413_draw;
  local_18 = menu_ex060413_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = &DAT_00009ba2;
  local_3 = 0;
  menu_register(local_38);
  return;
}

