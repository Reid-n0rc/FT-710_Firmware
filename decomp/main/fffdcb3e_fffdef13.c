// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
  local_c = 0x9b9d;
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
  local_c = 0x9b9e;
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
  local_c = 0x9b9f;
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
  local_c = 0x9ba0;
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
  local_c = 0x9ba1;
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
  local_c = 0x9ba2;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060414 @ fffdcdcc (109 bytes)

/* Menu item 5.25.13 PRESET / PRESET4 / TX BPF SEL */

void menuitem_EX060414(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff87045;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060414_draw;
  local_18 = menu_ex060414_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9ba3;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060415 @ fffdce39 (109 bytes)

/* Menu item 5.25.14 PRESET / PRESET4 / MOD SOURCE */

void menuitem_EX060415(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff8705a;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060415_draw;
  local_18 = menu_ex060415_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9ba4;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060416 @ fffdcea6 (109 bytes)

/* Menu item 5.25.15 PRESET / PRESET4 / USB MOD GAIN */

void menuitem_EX060416(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff8706f;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060416_draw;
  local_18 = menu_ex060416_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9ba5;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060417 @ fffdcf13 (109 bytes)

/* Menu item 5.25.16 PRESET / PRESET4 / REAR MOD GAIN */

void menuitem_EX060417(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff87084;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060417_draw;
  local_18 = menu_ex060417_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9ba6;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060418 @ fffdcf80 (109 bytes)

/* Menu item 5.25.17 PRESET / PRESET4 / RPTT SELECT */

void menuitem_EX060418(void)

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
  local_38[3] = 5;
  local_38[4] = 0x19;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff87099;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060418_draw;
  local_18 = menu_ex060418_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9ba7;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060501 @ fffdcfed (109 bytes)

/* Menu item 5.26.0 PRESET / PRESET5 / PRESET NAME */

void menuitem_EX060501(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0;
  pbVar2 = (byte *)0xfff870ae;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060501_draw;
  local_18 = menu_step_nop;
  local_14 = menu_ex060101_enter;
  local_10 = 0;
  local_e = 0;
  local_8 = 1;
  local_7 = 0;
  local_6 = 0;
  local_5 = 0;
  local_4 = 0;
  local_c = 0x9baa;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060502 @ fffdd05a (109 bytes)

/* Menu item 5.26.1 PRESET / PRESET5 / CAT-1 RATE */

void menuitem_EX060502(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 1;
  pbVar2 = (byte *)0xfff870c3;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060502_draw;
  local_18 = menu_ex060502_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bb6;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060503 @ fffdd0c7 (109 bytes)

/* Menu item 5.26.2 PRESET / PRESET5 / CAT-1 TIME OUT TIMER */

void menuitem_EX060503(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 2;
  pbVar2 = (byte *)0xfff870d8;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060503_draw;
  local_18 = menu_ex060503_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bb7;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060504 @ fffdd134 (109 bytes)

/* Menu item 5.26.3 PRESET / PRESET5 / CAT-1 CAT-3 STOP BIT */

void menuitem_EX060504(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 3;
  pbVar2 = (byte *)0xfff870ed;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060504_draw;
  local_18 = menu_ex060504_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bb8;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060505 @ fffdd1a1 (109 bytes)

/* Menu item 5.26.4 PRESET / PRESET5 / AGC FAST DELAY */

void menuitem_EX060505(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 4;
  pbVar2 = (byte *)0xfff87102;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060505_draw;
  local_18 = menu_ex060505_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9bb9;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060506 @ fffdd20e (109 bytes)

/* Menu item 5.26.5 PRESET / PRESET5 / AGC MID DELAY */

void menuitem_EX060506(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 5;
  pbVar2 = (byte *)0xfff87117;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060506_draw;
  local_18 = menu_ex060506_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9bba;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060507 @ fffdd27b (109 bytes)

/* Menu item 5.26.6 PRESET / PRESET5 / AGC SLOW DELAY */

void menuitem_EX060507(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 6;
  pbVar2 = (byte *)0xfff8712c;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060507_draw;
  local_18 = menu_ex060507_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 199;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 4;
  local_4 = 2;
  local_c = 0x9bbb;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060508 @ fffdd2e8 (109 bytes)

/* Menu item 5.26.7 PRESET / PRESET5 / LCUT FREQ */

void menuitem_EX060508(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 7;
  pbVar2 = (byte *)0xfff87141;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060508_draw;
  local_18 = menu_ex060508_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x13;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9bbc;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060509 @ fffdd355 (109 bytes)

/* Menu item 5.26.8 PRESET / PRESET5 / LCUT SLOPE */

void menuitem_EX060509(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 8;
  pbVar2 = (byte *)0xfff87156;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060509_draw;
  local_18 = menu_ex060509_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bbd;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060510 @ fffdd3c2 (109 bytes)

/* Menu item 5.26.9 PRESET / PRESET5 / HCUT FREQ */

void menuitem_EX060510(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 9;
  pbVar2 = (byte *)0xfff8716b;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060510_draw;
  local_18 = menu_ex060510_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 0x43;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 2;
  local_4 = 0;
  local_c = 0x9bbe;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060511 @ fffdd42f (109 bytes)

/* Menu item 5.26.10 PRESET / PRESET5 / HCUT SLOPE */

void menuitem_EX060511(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 10;
  pbVar2 = (byte *)0xfff87180;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060511_draw;
  local_18 = menu_ex060511_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 1;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bbf;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060512 @ fffdd49c (109 bytes)

/* Menu item 5.26.11 PRESET / PRESET5 / USB OUT LEVEL */

void menuitem_EX060512(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0xb;
  pbVar2 = (byte *)0xfff87195;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060512_draw;
  local_18 = menu_ex060512_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9bc0;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060513 @ fffdd509 (109 bytes)

/* Menu item 5.26.12 PRESET / PRESET5 / REAR OUT LEVEL */

void menuitem_EX060513(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0xc;
  pbVar2 = (byte *)0xfff871aa;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060513_draw;
  local_18 = menu_ex060513_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9bc1;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060514 @ fffdd576 (109 bytes)

/* Menu item 5.26.13 PRESET / PRESET5 / TX BPF SEL */

void menuitem_EX060514(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0xd;
  pbVar2 = (byte *)0xfff871bf;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060514_draw;
  local_18 = menu_ex060514_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 4;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bc2;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060515 @ fffdd5e3 (109 bytes)

/* Menu item 5.26.14 PRESET / PRESET5 / MOD SOURCE */

void menuitem_EX060515(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0xe;
  pbVar2 = (byte *)0xfff871d4;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060515_draw;
  local_18 = menu_ex060515_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bc3;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060516 @ fffdd650 (109 bytes)

/* Menu item 5.26.15 PRESET / PRESET5 / USB MOD GAIN */

void menuitem_EX060516(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0xf;
  pbVar2 = (byte *)0xfff871e9;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060516_draw;
  local_18 = menu_ex060516_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9bc4;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060517 @ fffdd6bd (109 bytes)

/* Menu item 5.26.16 PRESET / PRESET5 / REAR MOD GAIN */

void menuitem_EX060517(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0x10;
  pbVar2 = (byte *)0xfff871fe;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060517_draw;
  local_18 = menu_ex060517_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 100;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 3;
  local_4 = 0;
  local_c = 0x9bc5;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== menuitem_EX060518 @ fffdd72a (109 bytes)

/* Menu item 5.26.17 PRESET / PRESET5 / RPTT SELECT */

void menuitem_EX060518(void)

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
  local_38[3] = 5;
  local_38[4] = 0x1a;
  local_38[5] = 0x11;
  pbVar2 = (byte *)0xfff87213;
  pbVar1 = local_38 + 6;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  local_1c = menu_ex060518_draw;
  local_18 = menu_ex060518_step;
  local_14 = menu_enter_nop;
  local_10 = 0;
  local_e = 3;
  local_8 = 0;
  local_7 = 0;
  local_6 = 0;
  local_5 = 1;
  local_4 = 0;
  local_c = 0x9bc6;
  local_3 = 0;
  menu_register(local_38);
  return;
}


// ===== cat_ai_poll @ fffdd797 (979 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdd814) */
/* Auto-information broadcaster: runs ~70 change detectors, sends one changed item to every port
   with AI on (0x20B20..22) */

void cat_ai_poll(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  ushort local_2;
  
  if ((g_ui.cat_ai_on[0] == 1) || (g_ui.cat_ai_on[1] == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.cat_ai_on[2] == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    iVar3 = FUN_fffb1d79(1);
    if ((iVar3 == 0) && (iVar3 = FUN_fffb1d79(2), iVar3 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (iVar3 = FUN_fffb1d79(3), iVar3 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_2 = FUN_fffddcb5();
      if (local_2 == 0) {
        local_2 = FUN_fffdde79();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffddfc3();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde064(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde064(2);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde180();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde263();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde332();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde3f1();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde58a(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde58a(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde887();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffde9a8();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdebd1();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdec32();
      }
      if (local_2 == 0) {
        local_2 = cat_ai_ex();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffded19();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdee2c();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdee96();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdef13();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf13a(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf13a(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf66f();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf7b3();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf85c();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf8d4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf981();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf9ec(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdf9ec(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfae4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfbe4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfd36();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfda4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfe0a();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfe7a();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdfee6();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffdff9c();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0016();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe00be();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0143();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe024b();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe02f4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0394();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe040b();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe057b();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0839();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe08c7();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0a60();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0aff();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0ba1(0);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0ba1(1);
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0d06();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0e99();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\0');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\x01');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\x02');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\x03');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\x04');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\x05');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\x06');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\a');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe0fe6('\b');
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1447();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe14b4();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1523();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1596();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe165d();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe1774();
      }
      if (local_2 == 0) {
        local_2 = FUN_fffe170a();
      }
      if (local_2 == 0) {
        local_2 = cat_ai_FD();
      }
      if (DAT_000187c2 == '\x01') {
        bVar2 = swtimer_expired(0x32);
        if (bVar2 != 1) {
          return;
        }
        DAT_000187c2 = '\0';
      }
      if (local_2 != 0) {
        if (g_ui.cat_ai_on[0] == 1) {
          cat_send_reply(1,0x15e06,local_2);
        }
        if (g_ui.cat_ai_on[1] == 1) {
          cat_send_reply(2,0x15e06,local_2);
        }
        if (g_ui.cat_ai_on[2] == 1) {
          cat_send_reply(3,0x15e06,local_2);
          return;
        }
      }
    }
  }
  return;
}


// ===== cat_ai_holdoff @ fffddb6a (20 bytes)

/* Arms timer 0x32 (200 ms) and 0x187C2 to hold off the next AI frame after a CAT set */

void cat_ai_holdoff(void)

{
  swtimer_start(0x32,200);
  DAT_000187c2 = 1;
  return;
}


// ===== cat_ai_FD @ fffddb7e (311 bytes)

/* WARNING: Removing unreachable block (ram,0xfffddcb2) */
/* WARNING: Removing unreachable block (ram,0xfffddc73) */
/* AI detector for the undocumented FD command (FD00n + 9 digits) */

ushort cat_ai_FD(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  ushort uStack_26;
  char acStack_23 [4];
  undefined1 uStack_1f;
  char acStack_1e [9];
  undefined1 uStack_15;
  byte bStack_13;
  byte bStack_12;
  band_idx bStack_11;
  uint uStack_10;
  uint uStack_c;
  
  uVar3 = vfo_freq(VFO_RX,VFO_SIDE_SEL);
  bStack_11 = band_of_freq(uVar3);
  pcVar5 = "FD000000000000;";
  pcVar4 = acStack_23;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pcVar4 = *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  uStack_26 = 0;
  if (g_ui.tx_lamp == 1) {
    uStack_c = g_ui.freq_tx;
  }
  else if (g_opstate.scope_mode == 0) {
    uStack_c = g_ui.freq_dial;
    uStack_1f = 0x30;
  }
  else if (g_opstate.scope_mode == 1) {
    uStack_c = g_ui.scope_cursor_start;
    uStack_1f = 0x31;
  }
  else {
    uStack_c = bandmem_get('\x02');
    uStack_1f = 0x32;
  }
  if ((DAT_00025cec == uStack_c) && (g_opstate.scope_mode == DAT_00025cf0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_00025cec = uStack_c;
    DAT_00025cf0 = (uint)g_opstate.scope_mode;
    uStack_10 = 100000000;
    for (bStack_12 = 0; bStack_12 < 9; bStack_12 = bStack_12 + 1) {
      if (uStack_10 == 0) {
        bStack_13 = (byte)uStack_c;
        uVar3 = uStack_c;
      }
      else {
        bStack_13 = (byte)(uStack_c / uStack_10);
        uVar3 = uStack_c / uStack_10;
      }
      uStack_c = uStack_c - uVar3 * uStack_10;
      uStack_10 = uStack_10 / 10;
      uVar3 = (uint)bStack_12;
      cVar2 = nib2hex(bStack_13);
      acStack_1e[uVar3] = cVar2;
    }
    uStack_15 = 0x3b;
    uStack_26 = 0xf;
  }
  if (uStack_26 != 0) {
    pcVar5 = acStack_23;
    pcVar4 = &DAT_00015e06;
    for (uVar3 = (uint)uStack_26; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar4 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  return uStack_26;
}


// ===== FUN_fffddcb5 @ fffddcb5 (452 bytes)

undefined2 FUN_fffddcb5(void)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 local_12;
  char local_f [7];
  byte local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  undefined2 local_4;
  
  local_4 = 0;
  local_5 = g_opstate.ex030104_tuner_type_select;
  local_6 = g_ui.tune_cycle_3d;
  local_7 = g_ui.tune_cycle_3c;
  local_8 = g_ui.tune_cycle;
  local_f[6] = g_ui.tuner_result;
  local_f[0] = 'A';
  local_f[1] = 'C';
  local_f[2] = '0';
  local_f[4] = '0';
  local_f[5] = ';';
  if ((DAT_000187c3 == g_opstate.ex030104_tuner_type_select) && (DAT_000187c4 == g_ui.tune_cycle_3d)
     ) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c5 == g_ui.tune_cycle_3c)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c6 == g_ui.tune_cycle)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c7 == g_ui.tuner_result)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_000187c8 == g_ui.atu_state)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_12 = 0;
  }
  else {
    DAT_000187c3 = g_opstate.ex030104_tuner_type_select;
    DAT_000187c4 = g_ui.tune_cycle_3d;
    DAT_000187c5 = g_ui.tune_cycle_3c;
    DAT_000187c6 = g_ui.tune_cycle;
    DAT_000187c7 = g_ui.tuner_result;
    DAT_000187c8 = g_ui.atu_state;
    if (g_opstate.ex030104_tuner_type_select == 3) {
      local_f[3] = 0x32;
      if (g_ui.tune_cycle == 1) {
        local_f[4] = 0x33;
      }
      else if (g_ui.tune_cycle == 2) {
        if (g_ui.tuner_result == 2) {
          local_f[4] = 0x31;
        }
        else if (g_ui.tuner_result == 3) {
          local_f[4] = 0x32;
        }
        else {
          local_f[4] = 0x30;
        }
      }
      else {
        local_f[4] = 0x30;
      }
    }
    else {
      local_f[3] = 0x30;
      if ((g_ui.tune_cycle_3d == 2) || (g_ui.tune_cycle_3c == 2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_f[4] = 0x33;
      }
      else {
        iVar2 = FUN_fffec55a();
        if (iVar2 == 1) {
          local_f[4] = 0x31;
        }
        else {
          local_f[4] = 0x30;
        }
      }
    }
    iVar2 = strncmp(&DAT_0001b504,local_f,6);
    if (iVar2 != 0) {
      local_4 = 6;
      pcVar4 = local_f;
      pcVar3 = &DAT_00015e06;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pcVar3 = *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      }
      pcVar4 = local_f;
      pcVar3 = &DAT_0001b504;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pcVar3 = *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      }
    }
    local_12 = local_4;
  }
  return local_12;
}


// ===== FUN_fffdde79 @ fffdde79 (330 bytes)

/* WARNING: Removing unreachable block (ram,0xfffddfc0) */
/* WARNING: Removing unreachable block (ram,0xfffddf89) */

undefined2 FUN_fffdde79(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char local_11 [8];
  byte local_9;
  byte local_8;
  byte local_7;
  
  bVar3 = g_ui.af_gain;
  local_11[7] = g_ui.af_gain;
  builtin_strncpy(local_11,"AG0000;",7);
  if (DAT_000187c9 == g_ui.af_gain) {
    return 0;
  }
  DAT_000187c9 = g_ui.af_gain;
  DAT_0001b50a = DAT_0001b50a + 1;
  if (3 < DAT_0001b50a) {
    DAT_0001b50a = 0;
  }
  (&DAT_0001b53e)[DAT_0001b50a] = g_ui.af_gain;
  if ((bVar3 < 3) || (0xfc < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    if ((DAT_0001b53e == DAT_0001b540) || (DAT_0001b53f == DAT_0001b541)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      return 0;
    }
    bVar3 = FUN_fffe1805(&DAT_0001b53e);
    bVar4 = FUN_fffe1839(&DAT_0001b53e);
    if ((int)((uint)bVar3 - (uint)bVar4) < 3) {
      return 0;
    }
  }
  local_8 = 100;
  for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
    local_7 = local_11[7];
    if (local_8 != 0) {
      local_7 = (byte)local_11[7] / local_8;
    }
    local_11[7] = local_11[7] - local_7 * local_8;
    local_8 = local_8 / 10;
    uVar1 = (uint)local_9;
    cVar5 = nib2hex(local_7);
    local_11[uVar1 + 3] = cVar5;
  }
  pcVar7 = local_11;
  pcVar6 = &DAT_00015e06;
  for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pcVar6 = *pcVar7;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return 7;
}


// ===== FUN_fffddfc3 @ fffddfc3 (161 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde061) */
/* WARNING: Removing unreachable block (ram,0xfffde02b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffddfc3(void)

{
  uint uVar1;
  char cVar2;
  undefined2 local_12;
  undefined4 local_10;
  undefined2 local_c;
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  
  local_a = g_opstate.amc_level;
  local_10 = 0x30304f41;
  local_c = 0x3b30;
  if (DAT_000187ca == g_opstate.amc_level) {
    local_12 = 0;
  }
  else {
    DAT_000187ca = g_opstate.amc_level;
    local_8 = 100;
    for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
      local_7 = local_a;
      if (local_8 != 0) {
        local_7 = local_a / local_8;
      }
      local_a = local_a - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar1 = (uint)local_9;
      cVar2 = nib2hex(local_7);
      *(char *)((int)&local_10 + uVar1 + 2) = cVar2;
    }
    DAT_00015e0a = local_c;
    _DAT_00015e06 = local_10;
    local_12 = 6;
  }
  return local_12;
}


// ===== FUN_fffde064 @ fffde064 (284 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde17d) */
/* WARNING: Removing unreachable block (ram,0xfffde0e7) */

ushort FUN_fffde064(char param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char local_15 [7];
  ushort local_e;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  byte bStack_9;
  char local_5;
  
  local_5 = param_1;
  local_e = 0;
  builtin_strncpy(local_15,"AS0000;",7);
  if (param_1 == '\x01') {
    pcVar2 = (char *)aess_level_ptr();
    bStack_9 = *pcVar2;
    if (DAT_000187cb != bStack_9) {
      local_15[2] = 0x31;
      bStack_a = bStack_9 * '\x05';
      bStack_b = 100;
      DAT_000187cb = bStack_9;
      for (bStack_c = 0; bStack_c < 3; bStack_c = bStack_c + 1) {
        bStack_9 = bStack_a;
        if (bStack_b != 0) {
          bStack_9 = bStack_a / bStack_b;
        }
        bStack_a = bStack_a - bStack_9 * bStack_b;
        bStack_b = bStack_b / 10;
        uVar4 = (uint)bStack_c;
        cVar1 = nib2hex(bStack_9);
        local_15[uVar4 + 3] = cVar1;
      }
      local_e = 7;
    }
  }
  else if (param_1 == '\x02') {
    pcVar2 = (char *)aess_mode_ptr();
    bStack_9 = *pcVar2;
    if (DAT_000187cc != bStack_9) {
      local_15[2] = 0x32;
      if (bStack_9 == '\0') {
        local_15[3] = 0x30;
        local_15[4] = 0x30;
        local_15[5] = 0x31;
      }
      else if (bStack_9 == '\x01') {
        local_15[3] = 0x30;
        local_15[4] = 0x30;
        local_15[5] = 0x32;
      }
      local_e = 7;
      DAT_000187cc = bStack_9;
    }
  }
  if (local_e != 0) {
    pcVar3 = local_15;
    pcVar2 = &DAT_00015e06;
    for (uVar4 = (uint)local_e; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return local_e;
}


// ===== FUN_fffde180 @ fffde180 (227 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde260) */
/* WARNING: Removing unreachable block (ram,0xfffde226) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffde180(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  undefined2 local_1a;
  undefined4 local_17;
  undefined2 local_13;
  byte local_11;
  byte local_10;
  byte local_f;
  byte local_e;
  byte local_d;
  undefined4 local_c;
  
  local_c = 0x9bca;
  local_d = g_opstate.ex030405_vox_select;
  local_17 = 0x30305641;
  local_13 = 0x3b30;
  if (g_opstate.ex030405_vox_select == 0) {
    local_11 = g_opstate.antivox[0];
  }
  else {
    local_11 = g_opstate.antivox[1];
  }
  if ((DAT_000187cd == g_opstate.ex030405_vox_select) && (DAT_000187ce == local_11)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    local_1a = 0;
  }
  else {
    DAT_000187cd = g_opstate.ex030405_vox_select;
    DAT_000187ce = local_11;
    local_f = 100;
    for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
      local_e = local_11;
      if (local_f != 0) {
        local_e = local_11 / local_f;
      }
      local_11 = local_11 - local_e * local_f;
      local_f = local_f / 10;
      uVar1 = (uint)local_10;
      cVar3 = nib2hex(local_e);
      *(char *)((int)&local_17 + uVar1 + 2) = cVar3;
    }
    DAT_00015e0a = local_13;
    _DAT_00015e06 = local_17;
    local_1a = 6;
  }
  return local_1a;
}


// ===== FUN_fffde263 @ fffde263 (207 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffde263(void)

{
  uint uVar1;
  radio_mode rVar2;
  vfo_rec *pvVar3;
  undefined2 uStack_12;
  undefined4 uStack_f;
  byte bStack_a;
  
  pvVar3 = vfo_rec_ptr(VFO_RX);
  rVar2 = vfo_mode(VFO_RX);
  uVar1 = (uint)rVar2;
  if (uVar1 - 2 < 2) {
    bStack_a = pvVar3->blk[1].flags2;
  }
  else if (uVar1 - 4 < 2) {
    bStack_a = pvVar3->blk[4].flags2;
  }
  else {
    if (uVar1 - 6 < 2) {
      return 0;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) {
        return 0;
      }
      if (uVar1 - 0xc < 2) {
        bStack_a = pvVar3->blk[2].flags2;
        goto LAB_fffde2eb;
      }
      if (uVar1 != 0xe) {
        bStack_a = pvVar3->blk[0].flags2;
        goto LAB_fffde2eb;
      }
    }
    bStack_a = pvVar3->blk[3].flags2;
  }
LAB_fffde2eb:
  bStack_a = bStack_a & 0x80;
  if (DAT_000187cf == bStack_a) {
    uStack_12 = 0;
  }
  else {
    if (bStack_a == 0) {
      uStack_f = 0x30304342;
    }
    else {
      uStack_f = 0x31304342;
    }
    DAT_00015e0a._0_1_ = ';';
    _DAT_00015e06 = uStack_f;
    uStack_12 = 5;
    DAT_000187cf = bStack_a;
  }
  return uStack_12;
}


// ===== FUN_fffde332 @ fffde332 (191 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffde332(void)

{
  uint uVar1;
  radio_mode rVar2;
  vfo_rec *pvVar3;
  undefined2 uStack_10;
  undefined4 uStack_e;
  byte bStack_a;
  
  pvVar3 = vfo_rec_ptr(VFO_RX);
  rVar2 = vfo_mode(VFO_RX);
  uVar1 = (uint)rVar2;
  if (uVar1 - 2 < 2) {
    bStack_a = pvVar3->blk[1].flags;
  }
  else if (uVar1 - 4 < 2) {
    bStack_a = pvVar3->blk[4].flags;
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        return 0;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return 0;
        }
        if (uVar1 == 0xe) {
          return 0;
        }
        bStack_a = pvVar3->blk[0].flags;
        goto LAB_fffde3b1;
      }
    }
    bStack_a = pvVar3->blk[5].flags;
  }
LAB_fffde3b1:
  bStack_a = bStack_a & 2;
  if (DAT_000187d0 == bStack_a) {
    uStack_10 = 0;
  }
  else {
    if (bStack_a == 0) {
      uStack_e._0_3_ = 0x304942;
    }
    else {
      uStack_e._0_3_ = 0x314942;
    }
    uStack_e = CONCAT13(';',(undefined3)uStack_e);
    _DAT_00015e06 = uStack_e;
    uStack_10 = 4;
    DAT_000187d0 = bStack_a;
  }
  return uStack_10;
}


// ===== FUN_fffde3f1 @ fffde3f1 (409 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde587) */
/* WARNING: Removing unreachable block (ram,0xfffde4d5) */
/* WARNING: Removing unreachable block (ram,0xfffde54d) */

ushort FUN_fffde3f1(void)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  uint uVar4;
  ushort uVar5;
  char acStack_20 [8];
  ushort uStack_18;
  ushort uStack_16;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  radio_mode rStack_d;
  vfo_rec *pvStack_c;
  
  pcVar3 = acStack_20;
  pvStack_c = vfo_rec_ptr(VFO_RX);
  rStack_d = vfo_mode(VFO_RX);
  uStack_18 = 0;
  builtin_strncpy(acStack_20,"BP00000;",8);
  uVar4 = (uint)rStack_d;
  if (uVar4 - 2 < 2) {
    bStack_f = pvStack_c->blk[1].flags;
    bStack_13 = pvStack_c->blk[1].notch_be[0];
    bStack_12 = pvStack_c->blk[1].notch_be[1];
    goto LAB_fffde4d3;
  }
  if (uVar4 - 4 < 2) {
    bStack_f = pvStack_c->blk[4].flags;
    bStack_13 = pvStack_c->blk[4].notch_be[0];
    bStack_12 = pvStack_c->blk[4].notch_be[1];
    goto LAB_fffde4d3;
  }
  if (uVar4 - 6 < 2) {
LAB_fffde4c1:
    bStack_f = pvStack_c->blk[5].flags;
    bStack_13 = pvStack_c->blk[5].notch_be[0];
    bStack_12 = pvStack_c->blk[5].notch_be[1];
  }
  else {
    if (1 < uVar4 - 8) {
      if (uVar4 - 10 < 2) goto LAB_fffde4c1;
      if (uVar4 - 0xc < 2) {
        bStack_f = pvStack_c->blk[2].flags;
        bStack_13 = pvStack_c->blk[2].notch_be[0];
        bStack_12 = pvStack_c->blk[2].notch_be[1];
        goto LAB_fffde4d3;
      }
      if (uVar4 != 0xe) {
        bStack_f = pvStack_c->blk[0].flags;
        bStack_13 = pvStack_c->blk[0].notch_be[0];
        bStack_12 = pvStack_c->blk[0].notch_be[1];
        goto LAB_fffde4d3;
      }
    }
    bStack_f = pvStack_c->blk[3].flags;
    bStack_13 = pvStack_c->blk[3].notch_be[0];
    bStack_12 = pvStack_c->blk[3].notch_be[1];
  }
LAB_fffde4d3:
  uStack_16 = CONCAT11(bStack_13,bStack_12);
  if (DAT_000187d1 == (bStack_f & 0x80)) {
    if (DAT_0001ff06 != uStack_16) {
      acStack_20[2] = 0x30;
      acStack_20[3] = 0x31;
      bStack_10 = 100;
      DAT_0001ff06 = uStack_16;
      for (bStack_11 = 0; bStack_11 < 3; bStack_11 = bStack_11 + 1) {
        uVar4 = (uint)uStack_16;
        if (bStack_10 != 0) {
          uVar4 = uVar4 / bStack_10;
        }
        bStack_e = (byte)uVar4;
        uVar5 = uStack_16;
        if (bStack_10 != 0) {
          uVar5 = uStack_16 / bStack_10;
        }
        uStack_16 = uStack_16 - uVar5 * bStack_10;
        bStack_10 = bStack_10 / 10;
        uVar4 = (uint)bStack_11;
        cVar1 = nib2hex(bStack_e);
        acStack_20[uVar4 + 4] = cVar1;
      }
      uStack_18 = 8;
    }
  }
  else {
    acStack_20[2] = 0x30;
    DAT_000187d1 = bStack_f & 0x80;
    if ((bStack_f & 0x80) == 0) {
      acStack_20[6] = 0x30;
    }
    else {
      acStack_20[6] = 0x31;
    }
    uStack_18 = 8;
  }
  if (uStack_18 != 0) {
    puVar2 = &DAT_00015e06;
    for (uVar4 = (uint)uStack_18; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = *pcVar3;
      puVar2 = puVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return uStack_18;
}


// ===== FUN_fffde58a @ fffde58a (765 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde884) */
/* WARNING: Removing unreachable block (ram,0xfffde5f1) */
/* WARNING: Removing unreachable block (ram,0xfffde6bb) */
/* WARNING: Removing unreachable block (ram,0xfffde67d) */
/* WARNING: Removing unreachable block (ram,0xfffde637) */
/* WARNING: Removing unreachable block (ram,0xfffde848) */
/* WARNING: Removing unreachable block (ram,0xfffde77b) */

short FUN_fffde58a(char param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  ushort uVar7;
  char acStack_21 [4];
  undefined1 local_1d;
  undefined1 local_1c;
  char local_1b [5];
  short local_16;
  byte local_14;
  byte local_13;
  ushort local_12;
  ushort local_10;
  byte local_e;
  byte local_d;
  undefined4 local_c;
  char local_5;
  
  local_5 = param_1;
  local_16 = 0;
  pcVar5 = 
  "CF00000000;CN00000;CO000000;CS0;CT00;FA000000000;FN0;FT0;GT00;IF0000000000000000000000000;IS0000000;KP00;KR0;KS000;LK0;MD00;MG000;ML0000;MS00;MX0;NA00;NB00;NL0000;NR00;OS00;PA00;PC000;PL000;PR00;RA00;RG0000;RI00000000;RL000;RM0000000;SC0;SD00;SF00;SH0000;SQ0000;SS0000000;ST0;TS0;TX0;VD00;VG000;VS0;VX0;     RM 1"
  ;
  pcVar3 = acStack_21;
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pcVar3 = *pcVar5;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  }
  if (local_5 == '\0') {
    if (g_opstate.active_vfo == 0) {
      local_c = 0x9d09;
      local_13 = g_ui.clar_flags_a & 1;
      local_14 = g_ui.clar_flags_a & 2;
      local_10 = CONCAT11(g_opstate.vfo_a.clar_offset_be[0],g_opstate.vfo_a.clar_offset_be[1]);
    }
    else {
      local_c = 0x9d63;
      local_13 = g_ui.clar_flags_b & 1;
      local_14 = g_ui.clar_flags_b & 2;
      local_10 = CONCAT11(g_opstate.vfo_b.clar_offset_be[0],g_opstate.vfo_b.clar_offset_be[1]);
    }
  }
  else if (g_opstate.active_vfo == 0) {
    local_c = 0x9d63;
    local_13 = g_ui.clar_flags_b & 1;
    local_14 = g_ui.clar_flags_b & 2;
    local_10 = CONCAT11(g_opstate.vfo_b.clar_offset_be[0],g_opstate.vfo_b.clar_offset_be[1]);
  }
  else {
    local_c = 0x9d09;
    local_13 = g_ui.clar_flags_a & 1;
    local_14 = g_ui.clar_flags_a & 2;
    local_10 = CONCAT11(g_opstate.vfo_a.clar_offset_be[0],g_opstate.vfo_a.clar_offset_be[1]);
  }
  if (local_5 == '\0') {
    if ((DAT_000187d2 == local_13) && (DAT_000187d3 == local_14)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_000187d2 = local_13;
      DAT_000187d3 = local_14;
      acStack_21[2] = 0x30;
      local_1d = 0x30;
      if (local_13 != 0) {
        local_1c = 0x31;
      }
      if (local_14 != 0) {
        local_1b[0] = '1';
      }
      local_16 = 0xb;
    }
    else if (DAT_0001ff08 != local_10) {
      DAT_0001ff08 = local_10;
      acStack_21[2] = 0x30;
      local_1d = 0x31;
      if ((local_10 & 0x8000) == 0) {
        local_1c = 0x2b;
      }
      else {
        local_1c = 0x2d;
        local_10 = ~local_10 + 1;
      }
      local_12 = 1000;
      for (local_e = 0; local_e < 4; local_e = local_e + 1) {
        uVar4 = (uint)local_10;
        if (local_12 != 0) {
          uVar4 = uVar4 / local_12;
        }
        local_d = (byte)uVar4;
        uVar7 = local_10;
        if (local_12 != 0) {
          uVar7 = local_10 / local_12;
        }
        local_10 = local_10 - uVar7 * local_12;
        local_12 = local_12 / 10;
        uVar4 = (uint)local_e;
        cVar2 = nib2hex(local_d);
        local_1b[uVar4] = cVar2;
      }
      local_16 = 0xb;
    }
  }
  else {
    if ((DAT_000187d4 == local_13) && (DAT_000187d5 == local_14)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_000187d4 = local_13;
      DAT_000187d5 = local_14;
      acStack_21[2] = 0x31;
      local_1d = 0x30;
      if (local_13 != 0) {
        local_1c = 0x31;
      }
      if (local_14 != 0) {
        local_1b[0] = '1';
      }
      local_16 = 0xb;
    }
    else if (DAT_0001ff0a != local_10) {
      DAT_0001ff0a = local_10;
      acStack_21[2] = 0x31;
      local_1d = 0x31;
      if ((local_10 & 0x8000) == 0) {
        local_1c = 0x2b;
      }
      else {
        local_1c = 0x2d;
        local_10 = ~local_10 + 1;
      }
      local_12 = 1000;
      for (local_e = 0; local_e < 4; local_e = local_e + 1) {
        uVar4 = (uint)local_10;
        if (local_12 != 0) {
          uVar4 = uVar4 / local_12;
        }
        local_d = (byte)uVar4;
        uVar7 = local_10;
        if (local_12 != 0) {
          uVar7 = local_10 / local_12;
        }
        local_10 = local_10 - uVar7 * local_12;
        local_12 = local_12 / 10;
        uVar4 = (uint)local_e;
        cVar2 = nib2hex(local_d);
        local_1b[uVar4] = cVar2;
      }
      local_16 = 0xb;
    }
  }
  if (local_16 != 0) {
    pcVar5 = acStack_21;
    pcVar3 = &DAT_00015e06;
    for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pcVar3 = *pcVar5;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  return local_16;
}


// ===== FUN_fffde887 @ fffde887 (289 bytes)

/* WARNING: Removing unreachable block (ram,0xfffde9a5) */
/* WARNING: Removing unreachable block (ram,0xfffde969) */
/* WARNING: Removing unreachable block (ram,0xfffde907) */

ushort FUN_fffde887(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char local_16 [8];
  ushort local_e;
  byte local_b;
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  
  local_e = 0;
  builtin_strncpy(local_16,"CN00000;",8);
  local_a = g_opstate.vfo_a.tone_num;
  local_b = g_opstate.vfo_b.tone_num;
  if (DAT_000187d6 == g_opstate.vfo_a.tone_num) {
    if (DAT_000187d7 != g_opstate.vfo_b.tone_num) {
      DAT_000187d7 = g_opstate.vfo_b.tone_num;
      local_16[2] = 0x31;
      local_16[3] = 0x30;
      local_8 = 100;
      for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
        local_7 = local_b;
        if (local_8 != 0) {
          local_7 = local_b / local_8;
        }
        local_b = local_b - local_7 * local_8;
        local_8 = local_8 / 10;
        uVar4 = (uint)local_9;
        cVar1 = nib2hex(local_7);
        local_16[uVar4 + 4] = cVar1;
      }
      local_e = 8;
    }
  }
  else {
    DAT_000187d6 = g_opstate.vfo_a.tone_num;
    local_16[2] = 0x30;
    local_16[3] = 0x30;
    local_8 = 100;
    for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
      local_7 = local_a;
      if (local_8 != 0) {
        local_7 = local_a / local_8;
      }
      local_a = local_a - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar4 = (uint)local_9;
      cVar1 = nib2hex(local_7);
      local_16[uVar4 + 4] = cVar1;
    }
    local_e = 8;
  }
  if (local_e != 0) {
    pcVar3 = local_16;
    pcVar2 = &DAT_00015e06;
    for (uVar4 = (uint)local_e; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return local_e;
}


// ===== FUN_fffde9a8 @ fffde9a8 (553 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdebce) */
/* WARNING: Removing unreachable block (ram,0xfffdea0f) */
/* WARNING: Removing unreachable block (ram,0xfffdea22) */
/* WARNING: Removing unreachable block (ram,0xfffdea5e) */
/* WARNING: Removing unreachable block (ram,0xfffdea72) */
/* WARNING: Removing unreachable block (ram,0xfffdea4a) */
/* WARNING: Removing unreachable block (ram,0xfffdea36) */
/* WARNING: Removing unreachable block (ram,0xfffdeb92) */
/* WARNING: Removing unreachable block (ram,0xfffdeafe) */

ushort FUN_fffde9a8(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 uStack_21;
  char acStack_1d [5];
  ushort uStack_18;
  ushort uStack_16;
  ushort uStack_14;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  radio_mode rStack_d;
  vfo_rec *pvStack_c;
  
  pvStack_c = vfo_rec_ptr(VFO_RX);
  rStack_d = vfo_mode(VFO_RX);
  uStack_18 = 0;
  builtin_strncpy(acStack_1d,"0000;",5);
  uStack_21 = 0x30304f43;
  uVar4 = (uint)rStack_d;
  if (uVar4 - 2 < 2) {
    bStack_e = pvStack_c->blk[1].flags;
    uStack_14 = CONCAT11(pvStack_c->blk[1].contour_be[0],pvStack_c->blk[1].contour_be[1]);
    goto LAB_fffdea79;
  }
  if (uVar4 - 4 < 2) {
    bStack_e = pvStack_c->blk[4].flags;
    uStack_14 = CONCAT11(pvStack_c->blk[4].contour_be[0],pvStack_c->blk[4].contour_be[1]);
    goto LAB_fffdea79;
  }
  if (uVar4 - 6 < 2) {
LAB_fffdea67:
    bStack_e = pvStack_c->blk[5].flags;
    uStack_14 = CONCAT11(pvStack_c->blk[5].contour_be[0],pvStack_c->blk[5].contour_be[1]);
  }
  else {
    if (1 < uVar4 - 8) {
      if (uVar4 - 10 < 2) goto LAB_fffdea67;
      if (uVar4 - 0xc < 2) {
        bStack_e = pvStack_c->blk[2].flags;
        uStack_14 = CONCAT11(pvStack_c->blk[2].contour_be[0],pvStack_c->blk[2].contour_be[1]);
        goto LAB_fffdea79;
      }
      if (uVar4 != 0xe) {
        bStack_e = pvStack_c->blk[0].flags;
        uStack_14 = CONCAT11(pvStack_c->blk[0].contour_be[0],pvStack_c->blk[0].contour_be[1]);
        goto LAB_fffdea79;
      }
    }
    bStack_e = pvStack_c->blk[3].flags;
    uStack_14 = CONCAT11(pvStack_c->blk[3].contour_be[0],pvStack_c->blk[3].contour_be[1]);
  }
LAB_fffdea79:
  bStack_11 = g_opstate.apf_freq + 0x19;
  if (DAT_000187d8 == (bStack_e & 0x40)) {
    if (DAT_0001ff0c == uStack_14) {
      if (DAT_000187d9 == (bStack_e & 0x20)) {
        if (DAT_000187da != bStack_11) {
          uStack_21 = 0x33304f43;
          bStack_f = 10;
          DAT_000187da = bStack_11;
          for (bStack_10 = 0; bStack_10 < 2; bStack_10 = bStack_10 + 1) {
            bStack_e = bStack_11;
            if (bStack_f != 0) {
              bStack_e = bStack_11 / bStack_f;
            }
            bStack_11 = bStack_11 - bStack_e * bStack_f;
            bStack_f = bStack_f / 10;
            uVar4 = (uint)bStack_10;
            cVar1 = nib2hex(bStack_e);
            acStack_1d[uVar4 + 2] = cVar1;
          }
          uStack_18 = 9;
        }
      }
      else {
        DAT_000187d9 = bStack_e & 0x20;
        uStack_21 = 0x32304f43;
        if ((bStack_e & 0x20) == 0) {
          builtin_strncpy(acStack_1d,"0000",4);
        }
        else {
          builtin_strncpy(acStack_1d,"0001",4);
        }
        uStack_18 = 9;
      }
    }
    else {
      DAT_0001ff0c = uStack_14;
      uStack_21 = 0x31304f43;
      uStack_14 = uStack_14 * 10;
      uStack_16 = 1000;
      for (bStack_10 = 0; bStack_10 < 4; bStack_10 = bStack_10 + 1) {
        uVar4 = (uint)uStack_14;
        if (uStack_16 != 0) {
          uVar4 = uVar4 / uStack_16;
        }
        bStack_e = (byte)uVar4;
        uVar5 = uStack_14;
        if (uStack_16 != 0) {
          uVar5 = uStack_14 / uStack_16;
        }
        uStack_14 = uStack_14 - uVar5 * uStack_16;
        uStack_16 = uStack_16 / 10;
        uVar4 = (uint)bStack_10;
        cVar1 = nib2hex(bStack_e);
        acStack_1d[uVar4] = cVar1;
      }
      acStack_1d[3] = 0x30;
      uStack_18 = 9;
    }
  }
  else {
    DAT_000187d8 = bStack_e & 0x40;
    uStack_21 = 0x30304f43;
    if ((bStack_e & 0x40) == 0) {
      builtin_strncpy(acStack_1d,"0000",4);
    }
    else {
      builtin_strncpy(acStack_1d,"0001",4);
    }
    uStack_18 = 9;
  }
  if (uStack_18 != 0) {
    puVar3 = &uStack_21;
    puVar2 = &DAT_00015e06;
    for (uVar4 = (uint)uStack_18; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = *(undefined1 *)puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return uStack_18;
}


// ===== FUN_fffdebd1 @ fffdebd1 (97 bytes)

ushort FUN_fffdebd1(void)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  ushort local_a;
  char local_6 [6];
  
  builtin_strncpy(local_6,"CS0;",4);
  local_a = 0;
  if (DAT_000187db != g_ui.cw_spot_on) {
    DAT_000187db = g_ui.cw_spot_on;
    local_6[2] = nib2hex(g_ui.cw_spot_on);
    local_a = 4;
  }
  if (local_a != 0) {
    pcVar2 = local_6;
    pcVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_a; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return local_a;
}


// ===== FUN_fffdec32 @ fffdec32 (186 bytes)

undefined2 FUN_fffdec32(void)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 local_e;
  char local_a [6];
  byte local_4;
  byte local_3;
  
  builtin_strncpy(local_a,"CT00;",5);
  local_3 = g_opstate.vfo_a.flags3 & 0x38;
  local_4 = g_opstate.vfo_b.flags3 & 0x38;
  bVar1 = DAT_000187dd;
  local_a[5] = local_3;
  if ((DAT_000187dc == local_3) &&
     (local_3 = DAT_000187dc, bVar1 = local_4, local_a[5] = local_4, DAT_000187dd == local_4)) {
    local_e = 0;
  }
  else {
    DAT_000187dd = bVar1;
    DAT_000187dc = local_3;
    local_a[5] = (byte)local_a[5] >> 3;
    if (local_a[5] == 0) {
      local_a[3] = 0x30;
    }
    else if (local_a[5] == 1) {
      local_a[3] = 0x32;
    }
    else if (local_a[5] == 2) {
      local_a[3] = 0x31;
    }
    pcVar3 = local_a;
    pcVar2 = &DAT_00015e06;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    local_e = 5;
  }
  return local_e;
}


// ===== cat_ai_ex @ fffdecec (45 bytes)

/* AI change detector for the EX menu (one of cat_ai_poll's detectors): cat_ai_ex_scan, copies the
   frame to cat_ai_buf 0x15E06 */

ushort cat_ai_ex(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 auStack_68 [100];
  ushort local_4;
  
  local_4 = 0;
  puVar2 = auStack_68;
  local_4 = cat_ai_ex_scan(auStack_68);
  if (local_4 != 0) {
    puVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_4; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  return local_4;
}


// ===== FUN_fffded19 @ fffded19 (275 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdee29) */
/* WARNING: Removing unreachable block (ram,0xfffdedec) */

ushort FUN_fffded19(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined2 local_28;
  undefined2 uStack_26;
  undefined4 local_24;
  undefined4 local_20;
  ushort local_1c;
  byte local_1a;
  byte local_19;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_20 = 0x3b303030;
  local_24 = 0x30303030;
  local_10 = g_ui.freq_a;
  local_14 = g_ui.freq_b;
  if (g_ui.transmitting == 1) {
    if (g_opstate.active_vfo == 0) {
      local_10 = g_ui.freq_tx;
    }
    else {
      local_14 = g_ui.freq_tx;
    }
  }
  if (DAT_00025cf4 == local_10) {
    if (DAT_00025cf8 == local_14) {
      return 0;
    }
    DAT_00025cf8 = local_14;
    local_28 = 0x4246;
    local_1c = 0xc;
    local_c = local_14;
  }
  else {
    DAT_00025cf4 = local_10;
    local_28 = 0x4146;
    local_1c = 0xc;
    local_c = local_10;
  }
  local_1c = 0xc;
  _local_28 = CONCAT22(0x3030,local_28);
  local_18 = 100000000;
  for (local_19 = 0; local_19 < 9; local_19 = local_19 + 1) {
    if (local_18 == 0) {
      local_1a = (byte)local_c;
      uVar4 = local_c;
    }
    else {
      local_1a = (byte)(local_c / local_18);
      uVar4 = local_c / local_18;
    }
    local_c = local_c - uVar4 * local_18;
    local_18 = local_18 / 10;
    uVar4 = (uint)local_19;
    cVar1 = nib2hex(local_1a);
    *(char *)((int)&uStack_26 + uVar4) = cVar1;
  }
  if (local_1c != 0) {
    puVar3 = &local_28;
    puVar2 = &DAT_00015e06;
    for (uVar4 = (uint)local_1c; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = *(undefined1 *)puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = (undefined2 *)((int)puVar3 + 1);
    }
  }
  return local_1c;
}


// ===== FUN_fffdee2c @ fffdee2c (106 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdee78) */

ushort FUN_fffdee2c(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  ushort local_c;
  char local_6 [6];
  
  builtin_strncpy(local_6,"FN0;",4);
  if (DAT_000187de == g_opstate.fn_select) {
    local_c = 0;
  }
  else {
    DAT_000187de = g_opstate.fn_select;
    local_6[2] = nib2hex(g_opstate.fn_select);
    pcVar2 = local_6;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 4;
  }
  return local_c;
}


// ===== FUN_fffdee96 @ fffdee96 (125 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdeefa) */

undefined2 FUN_fffdee96(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 local_c;
  char local_a [7];
  byte local_3;
  
  local_3 = g_opstate.split_on;
  builtin_strncpy(local_a,"FT0;",4);
  if (DAT_000187df == g_opstate.split_on) {
    local_c = 0;
  }
  else {
    DAT_000187df = g_opstate.split_on;
    local_a[4] = '\x04';
    local_a[5] = '\0';
    if (g_opstate.split_on == 0) {
      local_a[2] = 0x30;
    }
    else if (g_opstate.split_on == 1) {
      local_a[2] = 0x31;
    }
    else if (g_opstate.split_on == 2) {
      local_a[2] = 0x31;
    }
    pcVar2 = local_a;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 4;
  }
  return local_c;
}


// ===== FUN_fffdef13 @ fffdef13 (551 bytes)

ushort FUN_fffdef13(void)

{
  byte bVar1;
  radio_mode rVar2;
  vfo_rec *pvVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  ushort uStack_12;
  byte bStack_e;
  char local_7 [7];
  
  builtin_strncpy(local_7,"GT00;",5);
  pvVar3 = vfo_rec_ptr(VFO_RX);
  rVar2 = vfo_mode(VFO_RX);
  uStack_12 = 0;
  bStack_e = 0;
  uVar6 = (uint)rVar2;
  if (uVar6 == 0xe) {
LAB_fffdf011:
    bVar1 = pvVar3->blk[3].flags2;
    if ((bVar1 & 0x40) != 0) {
      uVar6 = (bVar1 & 0x30) >> 4;
      if (uVar6 == 0) {
        bStack_e = 5;
      }
      else if (uVar6 == 3) {
        bStack_e = 3;
      }
      else if (uVar6 == 2) {
        bStack_e = 2;
      }
      else if (uVar6 == 1) {
        bStack_e = 1;
      }
    }
  }
  else {
    if (uVar6 - 2 < 2) {
      bVar1 = pvVar3->blk[1].flags2;
      if ((bVar1 & 0x40) != 0) {
        uVar6 = (bVar1 & 0x30) >> 4;
        if (uVar6 == 3) {
          bStack_e = 3;
        }
        else if (uVar6 == 1) {
          bStack_e = 1;
        }
        else if (uVar6 == 2) {
          bStack_e = 2;
        }
        else if (uVar6 == 0) {
          bStack_e = 4;
        }
      }
      goto LAB_fffdf0fe;
    }
    if (uVar6 - 4 < 2) {
      bVar1 = pvVar3->blk[4].flags2;
      if ((bVar1 & 0x40) != 0) {
        uVar6 = (bVar1 & 0x30) >> 4;
        if (uVar6 == 0) {
          bStack_e = 6;
        }
        else if (uVar6 == 3) {
          bStack_e = 3;
        }
        else if (uVar6 == 2) {
          bStack_e = 2;
        }
        else if (uVar6 == 1) {
          bStack_e = 1;
        }
      }
      goto LAB_fffdf0fe;
    }
    if (1 < uVar6 - 6) {
      if (uVar6 - 8 < 2) goto LAB_fffdf011;
      if (1 < uVar6 - 10) {
        if (uVar6 - 0xc < 2) {
          bVar1 = pvVar3->blk[2].flags2;
          if ((bVar1 & 0x40) != 0) {
            uVar6 = (bVar1 & 0x30) >> 4;
            if (uVar6 == 0) {
              bStack_e = 5;
            }
            else if (uVar6 == 3) {
              bStack_e = 3;
            }
            else if (uVar6 == 2) {
              bStack_e = 2;
            }
            else if (uVar6 == 1) {
              bStack_e = 1;
            }
          }
        }
        else if ((uVar6 < 2) && (bVar1 = pvVar3->blk[0].flags2, (bVar1 & 0x40) != 0)) {
          uVar6 = (bVar1 & 0x30) >> 4;
          if (uVar6 == 0) {
            bStack_e = 6;
          }
          else if (uVar6 == 3) {
            bStack_e = 3;
          }
          else if (uVar6 == 2) {
            bStack_e = 2;
          }
          else if (uVar6 == 1) {
            bStack_e = 1;
          }
        }
        goto LAB_fffdf0fe;
      }
    }
    bVar1 = pvVar3->blk[5].flags2;
    if ((bVar1 & 0x40) != 0) {
      uVar6 = (bVar1 & 0x30) >> 4;
      if (uVar6 == 3) {
        bStack_e = 3;
      }
      else if (uVar6 == 1) {
        bStack_e = 1;
      }
      else if (uVar6 == 2) {
        bStack_e = 2;
      }
      else if (uVar6 == 0) {
        bStack_e = 4;
      }
    }
  }
LAB_fffdf0fe:
  if (DAT_000187e0 != bStack_e) {
    DAT_000187e0 = bStack_e;
    local_7[3] = nib2hex(bStack_e);
    uStack_12 = 5;
  }
  if (uStack_12 != 0) {
    pcVar5 = local_7;
    pcVar4 = &DAT_00015e06;
    for (uVar6 = (uint)uStack_12; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar4 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  return uStack_12;
}

