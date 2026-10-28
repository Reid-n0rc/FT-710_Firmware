// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

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


// ===== FUN_201090a0 @ 201090a0 (8 bytes)

void FUN_201090a0(void)

{
  FUN_20108bc8(0);
  return;
}


// ===== FUN_201090a8 @ 201090a8 (432 bytes)

void FUN_201090a8(void)

{
  FUN_20108bc8(1);
  DAT_204508a8 = 0x39;
  DAT_204508ac = 0xfe;
  DAT_204508b0 = 0x14;
  DAT_20450c54 = 1;
  DAT_20450c58 = 0xb2;
  DAT_20450c80 = 0x24;
  DAT_20450c84 = 1;
  DAT_20450c88 = 0xb6;
  DAT_20450c50 = 0x34;
  DAT_20450c8c = 0x34;
  DAT_20450c90 = 0;
  DAT_20450c94 = 0xb7;
  DAT_20450c98 = 0x26;
  DAT_20450c9c = 1;
  DAT_20450ca0 = 0xb8;
  DAT_20450ca4 = 0x27;
  DAT_20450ca8 = 1;
  DAT_20450cac = 0xb9;
  DAT_20450cb0 = 0x33;
  DAT_20450cb4 = 1;
  DAT_20450cb8 = 0xba;
  DAT_20450cc0 = 1;
  DAT_20450cc4 = 0xbb;
  DAT_20450cf8 = 0x1f;
  DAT_20450cfc = 1;
  DAT_20450d00 = 0xc0;
  DAT_20450d04 = 0x25;
  DAT_20450d08 = 1;
  DAT_20450d0c = 0xc1;
  DAT_20450cbc = 0x2e;
  DAT_20450d28 = 0x2e;
  DAT_20450d2c = 0;
  DAT_20450d30 = 0xc4;
  DAT_20450d50 = 0;
  DAT_20450d54 = 199;
  DAT_20450d5c = 0;
  DAT_20450d60 = 200;
  DAT_20450d68 = 0;
  DAT_20450d6c = 0xc9;
  DAT_20450d70 = 0x23;
  DAT_20450d74 = 1;
  DAT_20450d78 = 0xca;
  DAT_20450d4c = 0x35;
  DAT_20450d58 = 0x2f;
  DAT_20450d64 = 0x30;
  DAT_20450d7c = 0x2f;
  DAT_20450d80 = 1;
  DAT_20450d84 = 0xcb;
  DAT_20450d88 = 0x30;
  DAT_20450d8c = 1;
  DAT_20450d90 = 0xcc;
  DAT_20450d94 = 0x35;
  DAT_20450d98 = 1;
  DAT_20450d9c = 0xcd;
  DAT_20450da0 = 0x2d;
  DAT_20450da4 = 1;
  DAT_20450da8 = 0xce;
  DAT_20450dbc = 1;
  DAT_20450dc0 = 0xcf;
  DAT_20450db8 = 0x31;
  DAT_20450dc4 = 0x31;
  DAT_20450dc8 = 0;
  DAT_20450dcc = 0xd0;
  return;
}


// ===== FUN_20109258 @ 20109258 (432 bytes)

void FUN_20109258(void)

{
  FUN_20108bc8(2);
  DAT_20450ea8 = 0x39;
  DAT_20450eac = 0xfe;
  DAT_20450eb0 = 0x14;
  DAT_20451264 = 0xb3;
  DAT_20451280 = 0x24;
  DAT_20451284 = 1;
  DAT_20451288 = 0xb6;
  DAT_20451260 = 0;
  DAT_2045125c = 0x31;
  DAT_2045128c = 0x34;
  DAT_20451290 = 0;
  DAT_20451294 = 0xb7;
  DAT_20451298 = 0x26;
  DAT_2045129c = 1;
  DAT_204512a0 = 0xb8;
  DAT_204512a4 = 0x27;
  DAT_204512a8 = 1;
  DAT_204512ac = 0xb9;
  DAT_204512b0 = 0x33;
  DAT_204512b4 = 1;
  DAT_204512b8 = 0xba;
  DAT_204512c0 = 1;
  DAT_204512c4 = 0xbb;
  DAT_204512f8 = 0x34;
  DAT_204512bc = 0x2e;
  DAT_204512fc = 1;
  DAT_20451300 = 0xc0;
  DAT_20451304 = 0x25;
  DAT_20451308 = 1;
  DAT_2045130c = 0xc1;
  DAT_2045132c = 0;
  DAT_20451330 = 0xc4;
  DAT_2045134c = 0x35;
  DAT_20451350 = 0;
  DAT_20451354 = 199;
  DAT_20451328 = 0x2e;
  DAT_2045135c = 0;
  DAT_20451360 = 200;
  DAT_20451368 = 0;
  DAT_2045136c = 0xc9;
  DAT_20451370 = 0x23;
  DAT_20451374 = 1;
  DAT_20451378 = 0xca;
  DAT_20451358 = 0x2f;
  DAT_20451364 = 0x30;
  DAT_2045137c = 0x2f;
  DAT_20451380 = 1;
  DAT_20451384 = 0xcb;
  DAT_20451388 = 0x30;
  DAT_2045138c = 1;
  DAT_20451390 = 0xcc;
  DAT_20451394 = 0x31;
  DAT_20451398 = 1;
  DAT_2045139c = 0xcd;
  DAT_204513a0 = 0x2d;
  DAT_204513a4 = 1;
  DAT_204513a8 = 0xce;
  DAT_204513bc = 1;
  DAT_204513c0 = 0xcf;
  DAT_204513b8 = 100;
  DAT_204513c4 = 100;
  DAT_204513c8 = 0;
  DAT_204513cc = 0xd0;
  return;
}


// ===== FUN_2010940c @ 2010940c (816 bytes)

void FUN_2010940c(void)

{
  int iVar1;
  int iVar2;
  
  FUN_20108bc8(3);
  DAT_204514f0 = 0x27;
  DAT_204514f4 = 1;
  DAT_204514f8 = 0x30;
  iVar1 = 1;
  do {
    (&DAT_204514f0)[iVar1 * 3] = iVar1 + 0x1d;
    iVar2 = iVar1 + 1;
    (&DAT_204514f4)[iVar1 * 3] = 1;
    (&DAT_204514f8)[iVar1 * 3] = iVar1 + 0x30;
    iVar1 = iVar2;
  } while (iVar2 < 10);
  DAT_204514a8 = 0x39;
  DAT_204514ac = 0xfe;
  DAT_204514b0 = 0x14;
  DAT_20451568 = 0x14;
  DAT_2045156c = 0;
  DAT_20451570 = 0x41;
  DAT_204515f8 = 0x33;
  DAT_204515fc = 0;
  DAT_20451600 = 0x4d;
  DAT_20451628 = 4;
  DAT_2045162c = 0;
  DAT_20451630 = 0x51;
  DAT_20451670 = 0x1d;
  DAT_20451674 = 0;
  DAT_20451678 = 0x57;
  DAT_20451694 = 0x1a;
  DAT_20451698 = 0;
  DAT_2045169c = 0x5a;
  DAT_20451844 = 0x38;
  DAT_20451848 = 0;
  DAT_2045184c = 0xb1;
  DAT_20451854 = 0;
  DAT_20451858 = 0xb2;
  DAT_20451850 = 0x20;
  DAT_2045185c = 0x20;
  DAT_20451860 = 2;
  DAT_20451864 = 0xb3;
  DAT_20451868 = 0x30;
  DAT_2045186c = 0;
  DAT_20451870 = 0xb4;
  DAT_20451874 = 0x34;
  DAT_20451878 = 1;
  DAT_2045187c = 0xb5;
  DAT_20451880 = 0x1e;
  DAT_20451884 = 0;
  DAT_20451888 = 0xb6;
  DAT_2045188c = 0x21;
  DAT_20451890 = 0;
  DAT_20451894 = 0xb7;
  DAT_20451898 = 0x22;
  DAT_2045189c = 0;
  DAT_204518a0 = 0xb8;
  DAT_204518a4 = 0x2d;
  DAT_204518a8 = 0;
  DAT_204518ac = 0xb9;
  DAT_204518b0 = 0x37;
  DAT_204518b4 = 0;
  DAT_204518b8 = 0xba;
  DAT_204518c0 = 1;
  DAT_204518c4 = 0xbb;
  DAT_204518cc = 0;
  DAT_204518d0 = 0xbc;
  DAT_204518d8 = 0;
  DAT_204518dc = 0xbd;
  DAT_204518e4 = 1;
  DAT_204518e8 = 0xbe;
  DAT_204518c8 = 0x10;
  DAT_204518d4 = 0x23;
  DAT_204518e0 = 0x36;
  DAT_204518ec = 0x37;
  DAT_204518bc = 0x2e;
  DAT_204518f0 = 1;
  DAT_204518f4 = 0xbf;
  DAT_204518f8 = 0x27;
  DAT_204518fc = 2;
  DAT_20451900 = 0xc0;
  DAT_20451904 = 0x32;
  DAT_20451908 = 0;
  DAT_2045190c = 0xc1;
  DAT_20451910 = 0x36;
  DAT_20451914 = 0;
  DAT_20451918 = 0xc2;
  DAT_20451920 = 0;
  DAT_20451924 = 0xc3;
  DAT_20451928 = 0x2e;
  DAT_2045191c = 100;
  DAT_2045192c = 0;
  DAT_20451930 = 0xc4;
  DAT_20451934 = 100;
  DAT_20451938 = 1;
  DAT_2045193c = 0xc5;
  DAT_20451940 = 0x10;
  DAT_20451944 = 1;
  DAT_20451948 = 0xc6;
  DAT_2045194c = 0x24;
  DAT_20451950 = 2;
  DAT_20451954 = 199;
  DAT_20451958 = 0x22;
  DAT_2045195c = 2;
  DAT_20451960 = 200;
  DAT_20451964 = 0x2d;
  DAT_20451968 = 2;
  DAT_2045196c = 0xc9;
  DAT_20451970 = 0x26;
  DAT_20451974 = 2;
  DAT_20451978 = 0xca;
  DAT_2045197c = 0x21;
  DAT_20451980 = 2;
  DAT_20451984 = 0xcb;
  DAT_20451988 = 0x2e;
  DAT_2045198c = 2;
  DAT_20451990 = 0xcc;
  DAT_20451994 = 0x1f;
  DAT_20451998 = 2;
  DAT_2045199c = 0xcd;
  DAT_204519a4 = 0;
  DAT_204519a8 = 0xce;
  DAT_204519c0 = 0xcf;
  DAT_204519bc = 2;
  DAT_204519a0 = 0x25;
  DAT_204519b8 = 0x23;
  DAT_204519c4 = 0x25;
  DAT_204519c8 = 2;
  DAT_204519cc = 0xd0;
  return;
}


// ===== FUN_2010973c @ 2010973c (520 bytes)

void FUN_2010973c(void)

{
  FUN_20108bc8(4);
  DAT_20451aa8 = 0x39;
  DAT_20451aac = 0xfe;
  DAT_20451ab0 = 0x14;
  DAT_20451e54 = 1;
  DAT_20451e58 = 0xb2;
  DAT_20451e5c = 0x35;
  DAT_20451e60 = 0;
  DAT_20451e64 = 0xb3;
  DAT_20451e80 = 0x24;
  DAT_20451e84 = 1;
  DAT_20451e88 = 0xb6;
  DAT_20451e8c = 0x36;
  DAT_20451e90 = 1;
  DAT_20451e94 = 0xb7;
  DAT_20451e98 = 0x26;
  DAT_20451e9c = 1;
  DAT_20451ea0 = 0xb8;
  DAT_20451ea4 = 0x27;
  DAT_20451ea8 = 1;
  DAT_20451eac = 0xb9;
  DAT_20451e50 = 0x1f;
  DAT_20451eb0 = 0x33;
  DAT_20451eb4 = 1;
  DAT_20451eb8 = 0xba;
  DAT_20451ebc = 0x2e;
  DAT_20451ec0 = 1;
  DAT_20451ec4 = 0xbb;
  DAT_20451eec = 0x20;
  DAT_20451ef8 = 0x1f;
  DAT_20451ef0 = 1;
  DAT_20451ef4 = 0xbf;
  DAT_20451efc = 2;
  DAT_20451f00 = 0xc0;
  DAT_20451f04 = 0x25;
  DAT_20451f08 = 1;
  DAT_20451f0c = 0xc1;
  DAT_20451f20 = 0;
  DAT_20451f24 = 0xc3;
  DAT_20451f28 = 0x2e;
  DAT_20451f1c = 0x32;
  DAT_20451f2c = 0;
  DAT_20451f30 = 0xc4;
  DAT_20451f34 = 0x32;
  DAT_20451f38 = 1;
  DAT_20451f3c = 0xc5;
  DAT_20451f40 = 0x23;
  DAT_20451f44 = 1;
  DAT_20451f48 = 0xc6;
  DAT_20451f50 = 0;
  DAT_20451f54 = 199;
  DAT_20451f5c = 2;
  DAT_20451f60 = 200;
  DAT_20451f64 = 0x30;
  DAT_20451f68 = 2;
  DAT_20451f6c = 0xc9;
  DAT_20451f4c = 0x34;
  DAT_20451f58 = 0x2f;
  DAT_20451f74 = 0;
  DAT_20451f78 = 0xca;
  DAT_20451f7c = 0x34;
  DAT_20451f80 = 2;
  DAT_20451f84 = 0xcb;
  DAT_20451f88 = 0x32;
  DAT_20451f70 = 0x2f;
  DAT_20451f8c = 2;
  DAT_20451f90 = 0xcc;
  DAT_20451f94 = 0x33;
  DAT_20451f98 = 2;
  DAT_20451f9c = 0xcd;
  DAT_20451fa0 = 0x2d;
  DAT_20451fa4 = 1;
  DAT_20451fa8 = 0xce;
  DAT_20451fb8 = 0x35;
  DAT_20451fbc = 1;
  DAT_20451fc0 = 0xcf;
  DAT_20451fc4 = 0x35;
  DAT_20451fc8 = 2;
  DAT_20451fcc = 0xd0;
  return;
}


// ===== FUN_20109944 @ 20109944 (464 bytes)

void FUN_20109944(void)

{
  FUN_20108bc8(4);
  DAT_20451aa8 = 0x39;
  DAT_20451aac = 0xfe;
  DAT_20451ab0 = 0x14;
  DAT_20451e54 = 1;
  DAT_20451e58 = 0xb2;
  DAT_20451e50 = 0x37;
  DAT_20451e80 = 0x24;
  DAT_20451e84 = 1;
  DAT_20451e88 = 0xb6;
  DAT_20451e8c = 0x26;
  DAT_20451e90 = 1;
  DAT_20451e94 = 0xb7;
  DAT_20451e9c = 1;
  DAT_20451ea0 = 0xb8;
  DAT_20451ea8 = 1;
  DAT_20451eac = 0xb9;
  DAT_20451eb0 = 0x33;
  DAT_20451eb4 = 1;
  DAT_20451eb8 = 0xba;
  DAT_20451ec0 = 1;
  DAT_20451ec4 = 0xbb;
  DAT_20451eec = 0x35;
  DAT_20451ef0 = 1;
  DAT_20451ef4 = 0xbf;
  DAT_20451ef8 = 0x1f;
  DAT_20451efc = 1;
  DAT_20451f00 = 0xc0;
  DAT_20451f08 = 1;
  DAT_20451f0c = 0xc1;
  DAT_20451e98 = 0x36;
  DAT_20451ea4 = 0x27;
  DAT_20451ebc = 0x2e;
  DAT_20451f04 = 0x25;
  DAT_20451f1c = 0x36;
  DAT_20451f28 = 0x2e;
  DAT_20451f20 = 2;
  DAT_20451f24 = 0xc3;
  DAT_20451f34 = 0x37;
  DAT_20451f38 = 2;
  DAT_20451f3c = 0xc5;
  DAT_20451f40 = 0x23;
  DAT_20451f44 = 1;
  DAT_20451f48 = 0xc6;
  DAT_20451f2c = 0;
  DAT_20451f30 = 0xc4;
  DAT_20451f50 = 2;
  DAT_20451f54 = 199;
  DAT_20451f58 = 0x26;
  DAT_20451f4c = 0x2f;
  DAT_20451f5c = 2;
  DAT_20451f60 = 200;
  DAT_20451f64 = 0x27;
  DAT_20451f70 = 0x2f;
  DAT_20451f74 = 0;
  DAT_20451f68 = 2;
  DAT_20451f6c = 0xc9;
  DAT_20451f78 = 0xca;
  DAT_20451f7c = 0x24;
  DAT_20451f80 = 2;
  DAT_20451f84 = 0xcb;
  DAT_20451f88 = 0x25;
  DAT_20451f8c = 2;
  DAT_20451f90 = 0xcc;
  DAT_20451f98 = 2;
  DAT_20451f9c = 0xcd;
  DAT_20451fa4 = 1;
  DAT_20451f94 = 0x30;
  DAT_20451fa0 = 0x2d;
  DAT_20451fa8 = 0xce;
  return;
}


// ===== FUN_20109b14 @ 20109b14 (516 bytes)

void FUN_20109b14(void)

{
  FUN_20108bc8(5);
  DAT_204520a8 = 0x39;
  DAT_204520ac = 0xfe;
  DAT_204520b0 = 0x14;
  DAT_20452288 = 0x1d;
  DAT_2045228c = 0;
  DAT_20452290 = 0x59;
  DAT_20452294 = 0x1c;
  DAT_20452298 = 0;
  DAT_2045229c = 0x5a;
  DAT_2045245c = 0x32;
  DAT_20452460 = 0;
  DAT_20452464 = 0xb3;
  DAT_2045248c = 0x32;
  DAT_20452490 = 1;
  DAT_20452494 = 0xb7;
  DAT_204524b0 = 0x37;
  DAT_204524b4 = 1;
  DAT_204524b8 = 0xba;
  DAT_204524c0 = 0;
  DAT_204524c4 = 0xbb;
  DAT_204524d4 = 0x38;
  DAT_204524bc = 0x30;
  DAT_204524d8 = 0;
  DAT_204524dc = 0xbd;
  DAT_204524f8 = 0x14;
  DAT_204524f0 = 1;
  DAT_204524f4 = 0xbf;
  DAT_204524fc = 2;
  DAT_20452500 = 0xc0;
  DAT_20452508 = 1;
  DAT_2045250c = 0xc1;
  DAT_20452510 = 0x36;
  DAT_20452514 = 1;
  DAT_20452518 = 0xc2;
  DAT_20452520 = 0;
  DAT_20452524 = 0xc3;
  DAT_2045252c = 1;
  DAT_20452530 = 0xc4;
  DAT_204524ec = 0x24;
  DAT_20452528 = 0x27;
  DAT_20452504 = 0x30;
  DAT_2045251c = 100;
  DAT_20452538 = 1;
  DAT_2045253c = 0xc5;
  DAT_20452544 = 1;
  DAT_20452548 = 0xc6;
  DAT_2045254c = 0x2e;
  DAT_20452550 = 1;
  DAT_20452554 = 199;
  DAT_20452558 = 0x25;
  DAT_2045255c = 2;
  DAT_20452560 = 200;
  DAT_20452564 = 0x26;
  DAT_20452568 = 2;
  DAT_2045256c = 0xc9;
  DAT_20452574 = 0;
  DAT_20452578 = 0xca;
  DAT_2045257c = 0x24;
  DAT_20452580 = 2;
  DAT_20452584 = 0xcb;
  DAT_20452588 = 0x27;
  DAT_20452540 = 0x2d;
  DAT_20452570 = 0x35;
  DAT_20452534 = 100;
  DAT_2045258c = 2;
  DAT_20452590 = 0xcc;
  DAT_20452594 = 0x30;
  DAT_204525a4 = 1;
  DAT_204525a8 = 0xce;
  DAT_20452598 = 2;
  DAT_2045259c = 0xcd;
  DAT_204525a0 = 0x38;
  DAT_204525b8 = 100;
  DAT_204525c0 = 0xcf;
  DAT_204525c4 = 0x2d;
  DAT_204525bc = 2;
  DAT_204525c8 = 2;
  DAT_204525cc = 0xd0;
  return;
}


// ===== FUN_20109d24 @ 20109d24 (464 bytes)

void FUN_20109d24(void)

{
  FUN_20108bc8(6);
  DAT_204526a8 = 0x39;
  DAT_204526ac = 0xfe;
  DAT_204526b0 = 0x14;
  DAT_20452a94 = 0xb7;
  DAT_20452ab0 = 0x37;
  DAT_20452ab4 = 1;
  DAT_20452ab8 = 0xba;
  DAT_20452abc = 0x2f;
  DAT_20452a90 = 0;
  DAT_20452a8c = 0x2d;
  DAT_20452ac0 = 0;
  DAT_20452ac4 = 0xbb;
  DAT_20452ad4 = 0x38;
  DAT_20452ad8 = 0;
  DAT_20452adc = 0xbd;
  DAT_20452af0 = 1;
  DAT_20452af4 = 0xbf;
  DAT_20452af8 = 0x1f;
  DAT_20452b04 = 0x2f;
  DAT_20452b08 = 1;
  DAT_20452b0c = 0xc1;
  DAT_20452b10 = 0x36;
  DAT_20452b14 = 1;
  DAT_20452b18 = 0xc2;
  DAT_20452afc = 2;
  DAT_20452b00 = 0xc0;
  DAT_20452b20 = 0;
  DAT_20452b24 = 0xc3;
  DAT_20452b2c = 1;
  DAT_20452b30 = 0xc4;
  DAT_20452aec = 0x24;
  DAT_20452b1c = 100;
  DAT_20452b28 = 0x27;
  DAT_20452b34 = 100;
  DAT_20452b38 = 1;
  DAT_20452b3c = 0xc5;
  DAT_20452b40 = 0x2d;
  DAT_20452b44 = 1;
  DAT_20452b48 = 0xc6;
  DAT_20452b4c = 0x30;
  DAT_20452b50 = 1;
  DAT_20452b54 = 199;
  DAT_20452b58 = 0x25;
  DAT_20452b5c = 2;
  DAT_20452b60 = 200;
  DAT_20452b64 = 0x26;
  DAT_20452b68 = 2;
  DAT_20452b6c = 0xc9;
  DAT_20452b7c = 0x24;
  DAT_20452b74 = 1;
  DAT_20452b78 = 0xca;
  DAT_20452b80 = 2;
  DAT_20452b84 = 0xcb;
  DAT_20452b88 = 0x27;
  DAT_20452b70 = 0x32;
  DAT_20452b8c = 2;
  DAT_20452b90 = 0xcc;
  DAT_20452b94 = 0x32;
  DAT_20452b98 = 0;
  DAT_20452b9c = 0xcd;
  DAT_20452ba0 = 0x38;
  DAT_20452ba4 = 1;
  DAT_20452ba8 = 0xce;
  DAT_20452bbc = 1;
  DAT_20452bc0 = 0xcf;
  DAT_20452bb8 = 0x35;
  DAT_20452bc4 = 0x35;
  DAT_20452bc8 = 0;
  DAT_20452bcc = 0xd0;
  return;
}


// ===== FUN_20109ef4 @ 20109ef4 (408 bytes)

void FUN_20109ef4(void)

{
  FUN_20108bc8(7);
  DAT_20452ca8 = 0x39;
  DAT_20452cac = 0xfe;
  DAT_20452cb0 = 0x14;
  DAT_20453054 = 1;
  DAT_20453058 = 0xb2;
  DAT_20453080 = 0x24;
  DAT_20453084 = 1;
  DAT_20453088 = 0xb6;
  DAT_20453050 = 0x35;
  DAT_2045308c = 0x35;
  DAT_20453090 = 0;
  DAT_20453094 = 0xb7;
  DAT_20453098 = 0x26;
  DAT_2045309c = 1;
  DAT_204530a0 = 0xb8;
  DAT_204530a4 = 0x27;
  DAT_204530a8 = 1;
  DAT_204530ac = 0xb9;
  DAT_204530b4 = 1;
  DAT_204530b8 = 0xba;
  DAT_204530c0 = 1;
  DAT_204530c4 = 0xbb;
  DAT_204530f0 = 0;
  DAT_204530f4 = 0xbf;
  DAT_204530f8 = 0x1f;
  DAT_204530fc = 1;
  DAT_20453100 = 0xc0;
  DAT_20453104 = 0x25;
  DAT_20453108 = 1;
  DAT_2045310c = 0xc1;
  DAT_204530b0 = 0x38;
  DAT_204530bc = 0x2e;
  DAT_204530ec = 0x87;
  DAT_20453110 = 0x38;
  DAT_20453114 = 0;
  DAT_20453118 = 0xc2;
  DAT_20453128 = 0x2e;
  DAT_2045312c = 0;
  DAT_20453130 = 0xc4;
  DAT_20453144 = 1;
  DAT_20453148 = 0xc6;
  DAT_2045314c = 0x2f;
  DAT_20453150 = 0;
  DAT_20453154 = 199;
  DAT_20453174 = 1;
  DAT_20453178 = 0xca;
  DAT_20453170 = 0x34;
  DAT_20453140 = 0x87;
  DAT_20453194 = 0x34;
  DAT_20453198 = 0;
  DAT_2045319c = 0xcd;
  DAT_204531a0 = 0x2d;
  DAT_204531a4 = 1;
  DAT_204531a8 = 0xce;
  DAT_204531bc = 1;
  DAT_204531c0 = 0xcf;
  DAT_204531b8 = 100;
  DAT_204531c4 = 100;
  DAT_204531c8 = 0;
  DAT_204531cc = 0xd0;
  return;
}


// ===== FUN_2010a08c @ 2010a08c (488 bytes)

void FUN_2010a08c(void)

{
  FUN_20108bc8(8);
  DAT_204532a8 = 0x39;
  DAT_204532ac = 0xfe;
  DAT_204532b0 = 0x14;
  DAT_2045365c = 0x20;
  DAT_20453660 = 2;
  DAT_20453664 = 0xb3;
  DAT_20453694 = 0xb7;
  DAT_204536b0 = 0x37;
  DAT_204536b4 = 1;
  DAT_204536b8 = 0xba;
  DAT_20453690 = 0;
  DAT_204536bc = 0x30;
  DAT_2045368c = 0x2d;
  DAT_204536c0 = 0;
  DAT_204536c4 = 0xbb;
  DAT_204536d8 = 0;
  DAT_204536dc = 0xbd;
  DAT_204536ec = 0x24;
  DAT_204536f0 = 1;
  DAT_204536f4 = 0xbf;
  DAT_204536f8 = 0x1f;
  DAT_204536fc = 2;
  DAT_20453700 = 0xc0;
  DAT_20453704 = 0x30;
  DAT_20453708 = 1;
  DAT_2045370c = 0xc1;
  DAT_20453710 = 0x36;
  DAT_20453714 = 1;
  DAT_20453718 = 0xc2;
  DAT_20453720 = 0;
  DAT_20453724 = 0xc3;
  DAT_20453728 = 0x27;
  DAT_2045372c = 1;
  DAT_20453730 = 0xc4;
  DAT_204536d4 = 0x38;
  DAT_2045371c = 100;
  DAT_20453734 = 100;
  DAT_20453738 = 1;
  DAT_2045373c = 0xc5;
  DAT_20453740 = 0x2d;
  DAT_20453744 = 1;
  DAT_20453748 = 0xc6;
  DAT_20453750 = 0;
  DAT_20453754 = 199;
  DAT_2045374c = 0x2f;
  DAT_2045375c = 2;
  DAT_20453760 = 200;
  DAT_20453764 = 0x30;
  DAT_20453758 = 0x2f;
  DAT_20453768 = 2;
  DAT_2045376c = 0xc9;
  DAT_20453770 = 0x2f;
  DAT_20453774 = 1;
  DAT_20453778 = 0xca;
  DAT_2045377c = 0x34;
  DAT_20453780 = 2;
  DAT_20453784 = 0xcb;
  DAT_20453788 = 0x32;
  DAT_2045378c = 2;
  DAT_20453790 = 0xcc;
  DAT_20453794 = 0x21;
  DAT_204537a4 = 1;
  DAT_204537a8 = 0xce;
  DAT_20453798 = 2;
  DAT_2045379c = 0xcd;
  DAT_204537a0 = 0x38;
  DAT_204537b8 = 0x1e;
  DAT_204537bc = 2;
  DAT_204537c0 = 0xcf;
  DAT_204537c8 = 2;
  DAT_204537c4 = 0x35;
  DAT_204537cc = 0xd0;
  return;
}


// ===== FUN_2010a274 @ 2010a274 (452 bytes)

void FUN_2010a274(void)

{
  FUN_20108bc8(9);
  DAT_204538a8 = 0x39;
  DAT_204538ac = 0xfe;
  DAT_204538b0 = 0x14;
  DAT_20453c94 = 0xb7;
  DAT_20453cb0 = 0x37;
  DAT_20453cb4 = 1;
  DAT_20453cb8 = 0xba;
  DAT_20453c90 = 0;
  DAT_20453c8c = 0x2d;
  DAT_20453cbc = 0x30;
  DAT_20453cc0 = 0;
  DAT_20453cc4 = 0xbb;
  DAT_20453cd4 = 0x38;
  DAT_20453cd8 = 0;
  DAT_20453cdc = 0xbd;
  DAT_20453cec = 0x24;
  DAT_20453cf8 = 0x14;
  DAT_20453cf0 = 1;
  DAT_20453cf4 = 0xbf;
  DAT_20453cfc = 2;
  DAT_20453d00 = 0xc0;
  DAT_20453d04 = 0x30;
  DAT_20453d08 = 1;
  DAT_20453d0c = 0xc1;
  DAT_20453d10 = 0x36;
  DAT_20453d14 = 1;
  DAT_20453d18 = 0xc2;
  DAT_20453d20 = 0;
  DAT_20453d24 = 0xc3;
  DAT_20453d28 = 0x27;
  DAT_20453d2c = 1;
  DAT_20453d30 = 0xc4;
  DAT_20453d1c = 100;
  DAT_20453d34 = 100;
  DAT_20453d38 = 1;
  DAT_20453d3c = 0xc5;
  DAT_20453d40 = 0x2d;
  DAT_20453d44 = 1;
  DAT_20453d48 = 0xc6;
  DAT_20453d50 = 2;
  DAT_20453d54 = 199;
  DAT_20453d5c = 1;
  DAT_20453d60 = 200;
  DAT_20453d4c = 0x32;
  DAT_20453d58 = 0x34;
  DAT_20453d68 = 1;
  DAT_20453d6c = 0xc9;
  DAT_20453d74 = 2;
  DAT_20453d78 = 0xca;
  DAT_20453d64 = 0x32;
  DAT_20453d70 = 0x34;
  DAT_20453d7c = 0x34;
  DAT_20453d80 = 0;
  DAT_20453d84 = 0xcb;
  DAT_20453d88 = 0x32;
  DAT_20453d8c = 0;
  DAT_20453d90 = 0xcc;
  DAT_20453d94 = 0x30;
  DAT_20453da4 = 1;
  DAT_20453da8 = 0xce;
  DAT_20453db8 = 0x35;
  DAT_20453dbc = 0;
  DAT_20453dc0 = 0xcf;
  DAT_20453dc4 = 0x2d;
  DAT_20453d98 = 2;
  DAT_20453d9c = 0xcd;
  DAT_20453da0 = 0x38;
  DAT_20453dc8 = 2;
  DAT_20453dcc = 0xd0;
  return;
}


// ===== FUN_2010a438 @ 2010a438 (484 bytes)

void FUN_2010a438(void)

{
  FUN_20108bc8(10);
  DAT_20453ea8 = 0x39;
  DAT_20453eac = 0xfe;
  DAT_20453eb0 = 0x14;
  DAT_2045425c = 0x34;
  DAT_20454260 = 2;
  DAT_20454264 = 0xb3;
  DAT_20454294 = 0xb7;
  DAT_204542b0 = 0x37;
  DAT_204542b4 = 1;
  DAT_204542b8 = 0xba;
  DAT_20454290 = 0;
  DAT_204542bc = 0x30;
  DAT_2045428c = 0x2d;
  DAT_204542c0 = 0;
  DAT_204542c4 = 0xbb;
  DAT_204542d8 = 0;
  DAT_204542dc = 0xbd;
  DAT_204542ec = 0x24;
  DAT_204542f0 = 1;
  DAT_204542f4 = 0xbf;
  DAT_204542f8 = 0x33;
  DAT_204542fc = 2;
  DAT_20454300 = 0xc0;
  DAT_20454304 = 0x30;
  DAT_20454308 = 1;
  DAT_2045430c = 0xc1;
  DAT_20454310 = 0x36;
  DAT_20454314 = 1;
  DAT_20454318 = 0xc2;
  DAT_20454320 = 0;
  DAT_20454324 = 0xc3;
  DAT_20454328 = 0x27;
  DAT_2045432c = 1;
  DAT_20454330 = 0xc4;
  DAT_204542d4 = 0x38;
  DAT_2045431c = 100;
  DAT_20454334 = 100;
  DAT_20454338 = 1;
  DAT_2045433c = 0xc5;
  DAT_20454340 = 0x2d;
  DAT_20454344 = 1;
  DAT_20454348 = 0xc6;
  DAT_2045434c = 0x2d;
  DAT_20454350 = 2;
  DAT_20454354 = 199;
  DAT_2045435c = 2;
  DAT_20454360 = 200;
  DAT_20454364 = 0x30;
  DAT_20454358 = 0x2f;
  DAT_20454368 = 2;
  DAT_2045436c = 0xc9;
  DAT_20454370 = 0x2e;
  DAT_20454374 = 1;
  DAT_20454378 = 0xca;
  DAT_2045437c = 0x2f;
  DAT_20454384 = 0xcb;
  DAT_20454388 = 0x30;
  DAT_20454380 = 3;
  DAT_20454390 = 0xcc;
  DAT_20454398 = 2;
  DAT_2045439c = 0xcd;
  DAT_204543a0 = 0x38;
  DAT_204543a4 = 1;
  DAT_204543a8 = 0xce;
  DAT_204543bc = 1;
  DAT_204543c0 = 0xcf;
  DAT_204543b8 = 0x35;
  DAT_20454394 = 0x32;
  DAT_2045438c = 3;
  DAT_204543c4 = 0x35;
  DAT_204543c8 = 0;
  DAT_204543cc = 0xd0;
  return;
}


// ===== kbd_layout_tables_init @ 2010a630 (84 bytes)

/* fills the keyboard layout tables 0x20450290 / 0x2045C290 */

undefined4 kbd_layout_tables_init(void)

{
  memclr(&DAT_20450290,0xc000);
  memclr(&DAT_2045c290,0x1200);
  vk_key_name();
  FUN_201090a0();
  FUN_201090a8();
  FUN_20109258();
  FUN_20109b14();
  FUN_2010940c();
  FUN_2010973c();
  FUN_20109ef4();
  FUN_20109d24();
  FUN_2010a08c();
  FUN_2010a274();
  FUN_2010a438();
  return 0;
}


// ===== FUN_2010a684 @ 2010a684 (212 bytes)

undefined4 FUN_2010a684(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar1 = 0;
  do {
    iVar2 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600);
    if (param_2 == 0) {
      if ((iVar2 == param_1) && (*(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4) == 0))
      goto LAB_2010a744;
      if (iVar2 == param_1) {
        iVar2 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4);
        goto joined_r0x2010a728;
      }
    }
    else {
      if (iVar2 == param_1) {
        uVar3 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 8) - 0x41;
        bVar4 = uVar3 == 0x19;
        if (uVar3 < 0x1a) {
          bVar4 = param_2 == 1;
        }
        if (bVar4) goto LAB_2010a744;
      }
      if ((iVar2 == param_1) &&
         (*(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4) == param_2))
      goto LAB_2010a744;
      if (iVar2 == param_1) {
        iVar2 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4);
joined_r0x2010a728:
        if (iVar2 == 0xfe) {
LAB_2010a744:
          return *(undefined4 *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 8);
        }
      }
    }
    iVar1 = iVar1 + 1;
    if (0x7f < iVar1) {
      return 0xffffffff;
    }
  } while( true );
}


// ===== vk_name_lookup @ 2010a758 (60 bytes)

undefined4 * vk_name_lookup(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_2045c290)[iVar1 * 9] == param_1) {
      return &DAT_2045c294 + iVar1 * 9;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  return (undefined4 *)0x0;
}


// ===== kbdtest_draw @ 2010a79c (180 bytes)

/* F12 overlay: layout, usage hex, VK name */

void kbdtest_draw(undefined4 param_1)

{
  undefined1 auStack_50 [64];
  
  if (((ushort)DAT_20808a84 & 0x800) != 0) {
    DAT_20800130 = 0;
    fb_fill_rect(param_1,0xf800,0x28,10,400,100);
    FUN_2013608c(param_1,(&PTR_DAT_20800134)[DAT_20800130],0x32);
    sprintf(auStack_50,&DAT_2010a85c,DAT_20811282);
    FUN_2013608c(param_1,auStack_50,0x50,0x32);
    if (DAT_20811288 != 0) {
      FUN_2013608c(param_1,DAT_20811288,0x6e,0x32);
    }
  }
  return;
}


// ===== kbdtest_record @ 2010a864 (52 bytes)

void kbdtest_record(undefined1 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_2010a684();
  DAT_20811288 = vk_name_lookup();
  DAT_20811282 = param_1;
  DAT_20811284 = uVar1;
  DAT_20811280 = DAT_20811280 + '\x01';
  return;
}


// ===== kbdtest_line @ 2010a898 (96 bytes)

/* record last usage + modifier class for the F12 overlay */

void kbdtest_line(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_2 + 5);
  if (*(char *)(param_2 + 0xc) == '\0' && bVar1 == 0) {
    return;
  }
  uVar2 = 0;
  if ((bVar1 & 0x22) == 0) {
    if ((bVar1 & 0x40) == 0) {
      if (bVar1 == 0) goto LAB_2010a8e8;
    }
    else if ((bVar1 & 0xbf) == 0) {
      uVar2 = 2;
      goto LAB_2010a8e8;
    }
  }
  else if ((bVar1 & 0xdd) == 0) {
    uVar2 = 1;
    goto LAB_2010a8e8;
  }
  uVar2 = 0xff;
LAB_2010a8e8:
  kbdtest_record(*(char *)(param_2 + 0xc),uVar2,DAT_20800130);
  return;
}


// ===== kbdtest_init @ 2010a8f8 (28 bytes)

/* returns kbdtest_line */

code * kbdtest_init(void)

{
  DAT_20800130 = 0;
  kbd_layout_tables_init();
  return kbdtest_line;
}


// ===== be_bytes_to_u32 @ 2010a918 (40 bytes)

/* big-endian bytes to integer */

int be_bytes_to_u32(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
    iVar1 = (uint)*(byte *)(param_1 + iVar2) + iVar1 * 0x100;
  }
  return iVar1;
}


// ===== sum8_neg_append @ 2010a940 (52 bytes)

/* appends the negated 8-bit sum */

void sum8_neg_append(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  cVar2 = '\0';
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    cVar2 = cVar2 + *(char *)(param_1 + iVar1);
  }
  *(char *)(param_1 + param_2) = -cVar2;
  return;
}


// ===== isp_relay_mode_cmd @ 2010a974 (188 bytes)

/* same F1 <code> frame (DSP 02/82) */

undefined4 isp_relay_mode_cmd(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  iVar2 = 0;
  local_1c = (uint)CONCAT11(param_2,0xf1);
  local_18 = (uint)(byte)(param_2 - 0xf) << 0x18;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  while( true ) {
    itron_dly_tsk(1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_1c,8);
    if (iVar1 != 8) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_28,1,100);
    if ((iVar1 != -1) && ((char)local_28 == '\x06')) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  }
  return 1;
}


// ===== crc16_xmodem @ 2010aa30 (76 bytes)

/* CRC-16 poly 0x1021 init 0 (NXP framing) */

void crc16_xmodem(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  while (uVar4 < param_2) {
    uVar3 = 0;
    uVar2 = uVar2 ^ (uint)*(byte *)(param_1 + uVar4) << 8;
    do {
      uVar1 = uVar2 & 0x8000;
      uVar2 = uVar2 << 1;
      uVar3 = uVar3 + 1;
      if (uVar1 != 0) {
        uVar2 = uVar2 ^ 0x1021;
      }
      uVar4 = uVar4 + (7 < uVar3);
    } while (7 >= uVar3);
  }
  return;
}


// ===== dsp_isp_ping @ 2010aa7c (248 bytes)

/* 5A A6 ping -> 5A A7 */

undefined4 dsp_isp_ping(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  char local_20;
  
  local_38 = 0x5a;
  local_37 = 2;
  iVar2 = 0;
  local_36 = 0;
  local_34 = 0xa6;
  local_35 = 0x5a;
  local_33 = 0x5c;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  while( true ) {
    itron_dly_tsk(1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_38,6);
    if (iVar1 != 6) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_30,1,100);
    if ((((iVar1 != -1) && ((char)local_30 == '\x06')) &&
        (iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_24,0xe,100), iVar1 != -1)) &&
       (local_20 == -0x59)) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  }
  return 1;
}


// ===== dsp_isp_write_image @ 2010ab74 (1408 bytes)

/* WriteMemory 256 B per packet from 0x08000000 */

undefined4 dsp_isp_write_image(int *param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 extraout_r1;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int local_194;
  int local_190;
  char *local_18c;
  char local_188 [5];
  undefined2 local_183;
  undefined1 local_181;
  undefined1 local_180;
  undefined1 auStack_17f [256];
  char local_7f;
  char local_7c [5];
  undefined2 local_77;
  undefined1 local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  undefined1 local_64;
  char local_63;
  char local_60 [4];
  char local_5c;
  char local_57;
  char local_53;
  char local_52;
  char local_51;
  char local_50;
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [12];
  
  iVar10 = 0;
  iVar9 = 0;
  memclr(local_60,0x18);
  memclr(local_7c,0x1c);
  memclr(local_188,0x10c);
  local_7c[0] = 'Z';
  local_7c[1] = 0x16;
  local_7c[4] = 0xa4;
  local_70 = 3;
  local_7c[2] = 0;
  local_7c[3] = 0x5a;
  local_74 = 0;
  local_73 = 4;
  local_6f = 0;
  local_68 = 0;
  local_6e = 0;
  local_67 = 9;
  local_6d = 0;
  local_6c = 0;
  local_188[0] = 'Z';
  local_6b = 0;
  local_188[1] = 6;
  local_6a = 1;
  local_188[2] = 1;
  local_69 = 0;
  local_188[3] = 0x5a;
  local_77 = 0x10;
  local_188[4] = 0xa5;
  local_75 = 0;
  local_72 = 1;
  local_66 = 0;
  local_71 = 0;
  local_65 = 0;
  local_64 = 0;
  local_183 = 0x100;
  thunk_FUN_2014af64(param_2,&local_194);
  uVar7 = 0;
  if (local_194 != 0) {
    progress_scale(&DAT_20800178,extraout_r1,0,0x3ff00000);
    progress_set();
    progress_range_init(auStack_30,DAT_2080017c,99);
    sfl_stream_init(auStack_48,param_2,0,param_1);
    itron_dly_tsk(100);
    iVar6 = dsp_isp_ping(param_1);
    uVar7 = 0;
    if (iVar6 != 0) {
LAB_2010acc8:
      local_190 = sfl_stream_read(auStack_17f,1,0x100,auStack_48);
      if (local_190 != 0) {
        iVar11 = 0;
        iVar6 = iVar9 * 0x100 + 0x8000000;
        local_6f = 0;
        local_6e = (undefined1)((uint)iVar6 >> 8);
        local_6c = (undefined1)((uint)iVar6 >> 0x18);
        local_18c = local_7c + 2;
        local_6d = (undefined1)((uint)iVar6 >> 0x10);
        do {
          uVar4 = local_77;
          cVar3 = local_7c[4];
          cVar2 = local_7c[3];
          local_75 = (undefined1)local_77;
          uVar8 = (uint)local_77;
          local_74 = local_77._1_1_;
          local_77 = CONCAT11(local_7c[4],local_7c[3]);
          uVar5 = crc16_xmodem(local_18c + 3,uVar8 + 4);
          local_7c[4] = cVar3;
          local_77 = uVar4;
          local_75 = (char)uVar5;
          local_7c[3] = cVar2;
          local_74 = (char)((ushort)uVar5 >> 8);
          iVar6 = 0;
          do {
            pcVar1 = local_7c + iVar6;
            iVar6 = iVar6 + 1;
            local_63 = local_63 + *pcVar1;
          } while (iVar6 < 0x19);
          iVar6 = (**(code **)(*param_1 + 0x24))(param_1,local_7c,0x1a);
          if (iVar6 != 0x1a) {
            return 0;
          }
          iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
          if (((((iVar6 != -1) && (local_60[0] == '\x06')) &&
               (iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,6,100), iVar6 != -1)) &&
              ((local_5c == -0x5f &&
               (iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,0x16,100), iVar6 != -1))))
             && (local_57 == -0x60)) {
            cVar2 = local_53;
            if (local_53 == '\0') {
              cVar2 = local_52;
            }
            if (local_53 != '\0' || cVar2 != '\0') {
              return 0;
            }
            cVar2 = local_51;
            if (local_51 == '\0') {
              cVar2 = local_50;
            }
            if (local_51 != '\0' || cVar2 != '\0') {
              return 0;
            }
            iVar6 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
            if (iVar6 != 6) {
              return 0;
            }
            iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
            if ((iVar6 != -1) && (local_60[0] == '\x06')) goto LAB_2010aed8;
          }
          iVar11 = iVar11 + 1;
          if (4 < iVar11) {
            return 0;
          }
        } while( true );
      }
      uVar7 = 1;
    }
  }
  return uVar7;
LAB_2010aed8:
  iVar6 = 0;
  local_18c = local_188 + 2;
  do {
    uVar4 = local_183;
    cVar3 = local_188[4];
    cVar2 = local_188[3];
    local_180 = local_183._1_1_;
    local_181 = (undefined1)local_183;
    uVar8 = (uint)local_183;
    local_183 = CONCAT11(local_188[4],local_188[3]);
    uVar5 = crc16_xmodem(local_18c + 3,uVar8 + 4);
    local_188[4] = cVar3;
    local_183 = uVar4;
    local_181 = (char)uVar5;
    local_188[3] = cVar2;
    local_180 = (char)((ushort)uVar5 >> 8);
    iVar11 = 0;
    do {
      pcVar1 = local_188 + iVar11;
      iVar11 = iVar11 + 1;
      local_7f = local_7f + *pcVar1;
    } while (iVar11 < 0x109);
    iVar11 = (**(code **)(*param_1 + 0x24))(param_1,local_188,0x10a);
    if (iVar11 != 0x10a) {
      return 0;
    }
    iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
    if ((((iVar11 != -1) && (local_60[0] == '\x06')) &&
        (iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,6,100), iVar11 != -1)) &&
       (((local_5c == -0x5f &&
         (iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,0x16,100), iVar11 != -1)) &&
        (local_57 == -0x60)))) {
      cVar2 = local_53;
      if (local_53 == '\0') {
        cVar2 = local_52;
      }
      if (local_53 != '\0' || cVar2 != '\0') {
        return 0;
      }
      cVar2 = local_51;
      if (local_51 == '\0') {
        cVar2 = local_50;
      }
      if (local_51 != '\0' || cVar2 != '\0') {
        return 0;
      }
      iVar11 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
      if (iVar11 != 6) {
        return 0;
      }
      iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
      if ((iVar11 != -1) && (local_60[0] == '\x06')) break;
    }
    iVar6 = iVar6 + 1;
    if (4 < iVar6) {
      return 0;
    }
  } while( true );
  iVar10 = iVar10 + local_190;
  uVar12 = FUN_20164d82(local_194);
  uVar13 = FUN_20164d82(iVar10);
  uVar12 = FUN_201649d8((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,
                        (int)((ulonglong)uVar12 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar12 >> 0x20);
  progress_scale(auStack_30,uVar7,(int)uVar12,uVar7);
  progress_set();
  iVar9 = iVar9 + 1;
  goto LAB_2010acc8;
}


// ===== dsp_isp_erase_region @ 2010b0f4 (620 bytes)

/* FlashEraseRegion 0x08000000, 0xA0000, 9 */

undefined4 dsp_isp_erase_region(int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  char local_50 [28];
  char local_34 [4];
  char local_30;
  char local_2b;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  
  memclr(local_34,0x18);
  memclr(local_50,0x1c);
  local_50[0] = 'Z';
  local_50[1] = 0x16;
  local_50[8] = 0;
  local_50[9] = 2;
  local_50[0xc] = 3;
  local_50[0x10] = 8;
  local_50[2] = 0;
  local_50[0x11] = 0;
  local_50[3] = 0x5a;
  local_50[0x12] = 0;
  local_50[4] = 0xa4;
  local_50[0x13] = 10;
  local_50[0x14] = 0;
  local_50[0x18] = 0;
  local_50[0x15] = 9;
  local_50[0xd] = 0;
  local_50[5] = 0x5a;
  local_50[10] = 0;
  local_50[0xe] = 0;
  local_50[0x16] = 0;
  local_50[6] = 0xa4;
  local_50[0xb] = 0;
  local_50[0xf] = 0;
  local_50[0x17] = 0;
  local_50[7] = 0x10;
  uVar3 = crc16_xmodem(local_50 + 5,0x14);
  local_50[4] = 0xa4;
  local_50[5] = 0x10;
  local_50[6] = 0;
  local_50[7] = (char)uVar3;
  local_50[8] = (char)((ushort)uVar3 >> 8);
  local_50[3] = 0x5a;
  iVar4 = dsp_isp_ping(param_1);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = local_50 + iVar4;
      iVar4 = iVar4 + 1;
      iVar5 = 0;
      local_50[0x19] = local_50[0x19] + *pcVar1;
    } while (iVar4 < 0x19);
    do {
      itron_dly_tsk(1);
      iVar4 = (**(code **)(*param_1 + 0x24))(param_1,local_50,0x1a);
      if (iVar4 != 0x1a) {
        return 0;
      }
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
      if (((((iVar4 != -1) && (local_34[0] == '\x06')) &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,6,1000), iVar4 != -1)) &&
          ((local_30 == -0x5f &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,0x16,100), iVar4 != -1)))) &&
         (local_2b == -0x60)) {
        cVar2 = local_27;
        if (local_27 == '\0') {
          cVar2 = local_26;
        }
        if (local_27 != '\0' || cVar2 != '\0') {
          return 0;
        }
        cVar2 = local_25;
        if (local_25 == '\0') {
          cVar2 = local_24;
        }
        if (local_25 != '\0' || cVar2 != '\0') {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
        if (iVar4 != 6) {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
        if ((iVar4 != -1) && (local_34[0] == '\x06')) {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
  }
  return 0;
}


// ===== dsp_isp_configure_memory @ 2010b360 (604 bytes)

/* ConfigureMemory 9 (FlexSPI NOR), 0x1C000 */

undefined4 dsp_isp_configure_memory(int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  char local_50 [24];
  char local_38 [4];
  char local_34;
  char local_2f;
  char local_2b;
  char local_2a;
  char local_29;
  char local_28;
  
  memclr(local_38,0x18);
  memclr(local_50,0x18);
  local_50[0] = 'Z';
  local_50[1] = 0x12;
  local_50[8] = 0;
  local_50[9] = 0x11;
  local_50[0xc] = 2;
  local_50[0xd] = 9;
  local_50[0x10] = 0;
  local_50[4] = 0xa4;
  local_50[0x11] = 0;
  local_50[2] = 0;
  local_50[5] = 0x5a;
  local_50[0x12] = 0xc0;
  local_50[3] = 0x5a;
  local_50[10] = 0;
  local_50[0xe] = 0;
  local_50[6] = 0xa4;
  local_50[0x13] = 1;
  local_50[0xb] = 0;
  local_50[0xf] = 0;
  local_50[0x14] = 0;
  local_50[7] = 0xc;
  uVar3 = crc16_xmodem(local_50 + 5,0x10);
  local_50[4] = 0xa4;
  local_50[5] = 0xc;
  local_50[6] = 0;
  local_50[7] = (char)uVar3;
  local_50[8] = (char)((ushort)uVar3 >> 8);
  local_50[3] = 0x5a;
  iVar4 = dsp_isp_ping(param_1);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = local_50 + iVar4;
      iVar4 = iVar4 + 1;
      iVar5 = 0;
      local_50[0x15] = local_50[0x15] + *pcVar1;
    } while (iVar4 < 0x15);
    do {
      itron_dly_tsk(1);
      iVar4 = (**(code **)(*param_1 + 0x24))(param_1,local_50,0x16);
      if (iVar4 != 0x16) {
        return 0;
      }
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,1,100);
      if (((((iVar4 != -1) && (local_38[0] == '\x06')) &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,6,100), iVar4 != -1)) &&
          ((local_34 == -0x5f &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,0x16,100), iVar4 != -1)))) &&
         (local_2f == -0x60)) {
        cVar2 = local_2b;
        if (local_2b == '\0') {
          cVar2 = local_2a;
        }
        if (local_2b != '\0' || cVar2 != '\0') {
          return 0;
        }
        cVar2 = local_29;
        if (local_29 == '\0') {
          cVar2 = local_28;
        }
        if (local_29 != '\0' || cVar2 != '\0') {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
        if (iVar4 != 6) {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,1,100);
        if ((iVar4 != -1) && (local_38[0] == '\x06')) {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
  }
  return 0;
}


// ===== dsp_isp_fill_option @ 2010b5bc (608 bytes)

/* FillMemory 0x1C000, 4, 0xC0000002 */

undefined4 dsp_isp_fill_option(int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  char local_50 [28];
  char local_34 [4];
  char local_30;
  char local_2b;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  
  memclr(local_34,0x18);
  memclr(local_50,0x1c);
  local_50[0] = 'Z';
  local_50[1] = 0x16;
  local_50[8] = 0;
  local_50[9] = 5;
  local_50[0xc] = 3;
  local_50[0xd] = 0;
  local_50[0xe] = 0xc0;
  local_50[0xf] = 1;
  local_50[0x10] = 0;
  local_50[2] = 0;
  local_50[0x11] = 4;
  local_50[3] = 0x5a;
  local_50[4] = 0xa4;
  local_50[0x14] = 0;
  local_50[0x18] = 0xc0;
  local_50[0x15] = 2;
  local_50[5] = 0x5a;
  local_50[10] = 0;
  local_50[0x12] = 0;
  local_50[0x16] = 0;
  local_50[6] = 0xa4;
  local_50[0xb] = 0;
  local_50[0x13] = 0;
  local_50[0x17] = 0;
  local_50[7] = 0x10;
  uVar3 = crc16_xmodem(local_50 + 5,0x14);
  local_50[4] = 0xa4;
  local_50[5] = 0x10;
  local_50[6] = 0;
  local_50[7] = (char)uVar3;
  local_50[3] = 0x5a;
  local_50[8] = (char)((ushort)uVar3 >> 8);
  iVar4 = 0;
  do {
    pcVar1 = local_50 + iVar4;
    iVar4 = iVar4 + 1;
    iVar5 = 0;
    local_50[0x19] = local_50[0x19] + *pcVar1;
  } while (iVar4 < 0x19);
  do {
    itron_dly_tsk(1);
    iVar4 = (**(code **)(*param_1 + 0x24))(param_1,local_50,0x1a);
    if (iVar4 != 0x1a) {
      return 0;
    }
    iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
    if (((((iVar4 != -1) && (local_34[0] == '\x06')) &&
         (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,6,100), iVar4 != -1)) &&
        ((local_30 == -0x5f &&
         (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,0x16,100), iVar4 != -1)))) &&
       (local_2b == -0x60)) {
      cVar2 = local_27;
      if (local_27 == '\0') {
        cVar2 = local_26;
      }
      if (local_27 != '\0' || cVar2 != '\0') {
        return 0;
      }
      cVar2 = local_25;
      if (local_25 == '\0') {
        cVar2 = local_24;
      }
      if (local_25 != '\0' || cVar2 != '\0') {
        return 0;
      }
      iVar4 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
      if (iVar4 != 6) {
        return 0;
      }
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
      if ((iVar4 != -1) && (local_34[0] == '\x06')) {
        return 1;
      }
    }
    iVar5 = iVar5 + 1;
    if (4 < iVar5) {
      return 0;
    }
  } while( true );
}


// ===== dsp_isp_program @ 2010b81c (320 bytes)

/* IFDSP: NXP ROM ISP over the MAIN relay */

undefined4
dsp_isp_program(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined8 uVar4;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = param_3;
  uStack_14 = param_4;
  progress_range_init(&local_18,5,10);
  DAT_20800178 = local_18;
  DAT_2080017c = uStack_14;
  DAT_2080016c = 0x1d1;
  itron_dly_tsk(1);
  progress_scale(&DAT_20800178,extraout_r1,0,0);
  progress_set();
  if (param_5 == 0) {
    uVar1 = 0;
  }
  else {
    mainlink_rx_ctrl(1);
    uVar4 = scif5_get(0);
    piVar2 = (int *)uVar4;
    progress_scale(&DAT_20800178,(int)((ulonglong)uVar4 >> 0x20),0x9999999a,0x3fc99999);
    progress_set();
    DAT_2080016c = 0x1e4;
    local_18 = 2;
    (**(code **)(*piVar2 + 4))(piVar2,0x54600,8,0);
    progress_scale(&DAT_20800178,extraout_r1_00,0,0x3fe00000);
    progress_set();
    iVar3 = isp_relay_mode_cmd(piVar2,2);
    uVar1 = 0;
    if ((((iVar3 != 0) && (iVar3 = dsp_isp_ping(piVar2), uVar1 = 0, iVar3 != 0)) &&
        (iVar3 = dsp_isp_fill_option(piVar2), uVar1 = 0, iVar3 != 0)) &&
       (((iVar3 = dsp_isp_configure_memory(piVar2), uVar1 = 0, iVar3 != 0 &&
         (iVar3 = dsp_isp_erase_region(piVar2), uVar1 = 0, iVar3 != 0)) &&
        ((iVar3 = dsp_isp_write_image(piVar2,param_1), uVar1 = 0, iVar3 != 0 &&
         (iVar3 = isp_relay_mode_cmd(piVar2,0x82), uVar1 = 0, iVar3 != 0)))))) {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ===== rx_boot_read_compare @ 2010b95c (380 bytes)

/* reads a block and memcmp with the expected data */

undefined4
rx_boot_read_compare
          (int *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          uint param_6)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_238 [3];
  byte local_235;
  undefined1 auStack_234 [516];
  undefined1 local_30 [3];
  undefined1 uStack_2d;
  undefined4 local_2c;
  
  memclr(auStack_238,0x208);
  iVar2 = 0;
  while( true ) {
    _local_30 = CONCAT13((char)param_6,0x10081);
    local_2c = 0x300;
    sum8_neg_append(local_30 + 1,3);
    itron_dly_tsk(1);
    do {
      iVar1 = (**(code **)(*param_1 + 0x10))(param_1,auStack_238,1);
    } while (iVar1 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,local_30,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(5);
    memclr(auStack_238,0x208);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_238,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_235 != param_6) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_234,1);
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1,auStack_234,param_3 + 2,100);
  if (iVar2 == -1) {
    return 0;
  }
  if ((param_6 != 0x52) && (iVar2 = FUN_2015507c(auStack_234,param_4,param_3), iVar2 != 0)) {
    return 0;
  }
  return 1;
}


// ===== rx_boot_read_start @ 2010bb00 (416 bytes)

/* command packet for read-back */

undefined4 rx_boot_read_start(int *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_88 [3];
  byte local_85;
  undefined1 auStack_84 [60];
  undefined1 local_48 [3];
  undefined1 uStack_45;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined4 uStack_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  
  memclr(auStack_88,0x40);
  local_28 = 1;
  iVar3 = 0;
  local_2c = 0;
  local_30 = param_2 >> 0x18;
  local_34 = (param_2 & 0xffffff) >> 0x10;
  local_38 = (param_2 & 0xffff) >> 8;
  while( true ) {
    uStack_3c = 0x300;
    _local_48 = CONCAT13((char)param_4,0x90001);
    local_44 = CONCAT13((char)param_2,
                        CONCAT12((char)local_38,CONCAT11((char)local_34,(char)local_30)));
    _local_40 = CONCAT13((char)param_3,
                         CONCAT12((char)((uint)param_3 >> 8),
                                  CONCAT11((char)((uint)param_3 >> 0x10),
                                           (char)((uint)param_3 >> 0x18))));
    sum8_neg_append(local_48 + 1,0xb);
    itron_dly_tsk(1);
    do {
      iVar1 = (**(code **)(*param_1 + 0x10))(param_1,auStack_88,1);
    } while (iVar1 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,local_48,0xe);
    if (iVar1 != 0xe) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_88,4,100);
    if (iVar1 != -1) break;
    iVar3 = iVar3 + 1;
    if (local_28 <= iVar3) {
      uVar2 = 0;
      if (local_2c != 0) {
LAB_2010bc7c:
        (**(code **)(*param_1 + 0x18))(param_1,auStack_88,2,100);
        uVar2 = 1;
      }
      return uVar2;
    }
  }
  if (local_85 != param_4) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_84,1);
    return 0;
  }
  goto LAB_2010bc7c;
}


// ===== rx_boot_verify_areas @ 2010bca0 (744 bytes)

/* WARNING: Removing unreachable block (ram,0x2010be6c) */
/* boot cmd 0x15 / 0x52 read-back and compare */

undefined4
rx_boot_verify_areas
          (undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  bool bVar12;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  iVar9 = 0;
  iVar2 = FUN_20111174(0);
  uVar10 = 0;
  do {
    if (param_2 <= uVar10) {
      return 1;
    }
    uVar8 = 0x20;
    iVar3 = param_3 + uVar10 * 0x1c;
    local_50 = *(uint *)(iVar3 + 0x14);
    iVar6 = param_3;
    if (local_50 != 0) {
      iVar6 = *(int *)(iVar3 + 0x18);
    }
    if ((local_50 != 0 && iVar6 != 0) && (cVar1 = *(char *)(param_3 + uVar10 * 0x1c), cVar1 != ' '))
    {
      if (cVar1 == '0') {
        uVar11 = 0x52;
      }
      else {
        uVar11 = 0x15;
        uVar8 = 0x200;
      }
      for (local_4c = 0; uVar5 = *(uint *)(iVar3 + 0x18),
          local_4c == 0 && (uVar5 <= local_50) <= local_4c; local_4c = local_4c + bVar12) {
        uVar7 = local_50 + 0x7ffff;
        local_44 = local_4c + (0xfff80000 < local_50);
        local_48 = uVar7;
        if ((uint)(uVar7 <= uVar5) <= -local_44) {
          local_44 = 0;
          local_48 = uVar5;
        }
        FUN_2015525c(iVar2,0x80000,0xff,uVar5 - uVar7);
        iVar6 = fs_fseek(param_4,0);
        if (iVar6 != 0) {
          return 0;
        }
        iVar6 = srec_load_range(param_4,local_50,local_48,iVar2,param_5);
        if (iVar6 < 0) {
          return 0;
        }
        if (iVar6 != 0) {
          uVar5 = local_50;
          uVar7 = local_4c;
          if (*(char *)(param_3 + uVar10 * 0x1c) == '0') {
            progress_set(100);
            iVar9 = rx_boot_read_start(param_1,local_50,local_50 + 0x2f,0x52);
            if (iVar9 == 0) {
              return 0;
            }
            rx_boot_read_compare(param_1,local_50,0x30,iVar2,1,0x52);
            iVar9 = rx_boot_read_start(param_1,local_50 + 0x40,local_50 + 0x7f,0x52);
            if (iVar9 != 0) {
              rx_boot_read_compare(param_1,local_50 + 0x40,0x40,iVar2 + 0x40,1,0x52);
              return 1;
            }
            return 0;
          }
          for (; uVar7 <= local_44 && (uint)(local_48 <= uVar5) <= uVar7 - local_44;
              uVar7 = uVar7 + ((int)uVar8 >> 0x1f) + (uint)bVar12) {
            uVar4 = uVar7 + ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar5,uVar8);
            bVar12 = uVar4 - local_44 < (uint)(local_48 <= uVar5 + uVar8);
            if (local_44 < uVar4 || bVar12) {
              uVar8 = (local_48 - uVar5) + 1;
            }
            iVar6 = rx_boot_read_start(param_1,uVar5,uVar5 + uVar8 + -1,uVar11);
            if (iVar6 == 0) {
              return 0;
            }
            iVar6 = rx_boot_read_compare
                              (param_1,uVar5,uVar8,(uVar5 - local_50) + iVar2,
                               local_44 < uVar4 || bVar12,uVar11);
            if (iVar6 == 0) {
              return 0;
            }
            iVar9 = iVar9 + 1;
            iVar6 = FUN_20156260(iVar9 * 0x46,DAT_20800164);
            progress_set(iVar6 + 0x1e);
            bVar12 = CARRY4(uVar5,uVar8);
            uVar5 = uVar5 + uVar8;
          }
        }
        bVar12 = 0xfff7ffff < local_50;
        local_50 = local_50 + 0x80000;
      }
    }
    uVar10 = uVar10 + 1;
  } while( true );
}


// ===== rx_boot_data_packet @ 2010bf9c (432 bytes)

/* data packet 81 LNH LNL <cmd> data SUM 03/17 */

undefined4
rx_boot_data_packet(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                   uint param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_488;
  undefined1 uStack_487;
  undefined1 uStack_486;
  undefined1 uStack_485;
  undefined1 uStack_484;
  undefined1 auStack_483 [1027];
  undefined1 auStack_80 [3];
  byte local_7d;
  undefined1 auStack_7c [60];
  int local_40;
  int *piStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 local_2c;
  
  piStack_38 = param_1;
  uStack_34 = param_2;
  iStack_30 = param_3;
  local_2c = param_4;
  memclr(auStack_80,0x40);
  iVar4 = 0;
  local_40 = 0;
  while( true ) {
    memclr(&uStack_484,0x402);
    _local_488 = CONCAT13((char)param_6,
                          CONCAT12((char)(param_3 + 1),
                                   CONCAT11((char)((uint)(param_3 + 1) >> 8),0x81)));
    memcpy(&uStack_484,local_2c,param_3);
    sum8_neg_append(&uStack_487,param_3 + 3);
    if (param_5 == 0) {
      uVar1 = 0x17;
    }
    else {
      uVar1 = 3;
    }
    auStack_483[param_3] = uVar1;
    itron_dly_tsk(1);
    do {
      iVar2 = (**(code **)(*param_1 + 0x10))(param_1,auStack_80,1);
    } while (iVar2 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x24))(param_1,&local_488,param_3 + 6);
    if (iVar2 != param_3 + 6) {
      return 0;
    }
    itron_dly_tsk(1);
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,auStack_80,4,100);
    if (iVar2 != -1) break;
    iVar4 = iVar4 + 1;
    if (0 < iVar4) {
      uVar3 = 0;
      if (local_40 != 0) {
LAB_2010c11c:
        itron_dly_tsk(1);
        (**(code **)(*param_1 + 0x18))(param_1,auStack_80,2,100);
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  if (local_7d != param_6) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_7c,1);
    return 0;
  }
  goto LAB_2010c11c;
}


// ===== rx_boot_write_start @ 2010c14c (424 bytes)

/* command packet 01 00 09 <cmd> start end */

undefined4 rx_boot_write_start(int *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_88 [3];
  byte local_85;
  undefined1 auStack_84 [60];
  undefined1 local_48 [3];
  undefined1 uStack_45;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined4 uStack_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  
  memclr(auStack_88,0x40);
  local_28 = 1;
  iVar3 = 0;
  local_2c = 0;
  local_30 = param_2 >> 0x18;
  local_34 = (param_2 & 0xffffff) >> 0x10;
  local_38 = (param_2 & 0xffff) >> 8;
  while( true ) {
    uStack_3c = 0x300;
    _local_48 = CONCAT13((char)param_4,0x90001);
    local_44 = CONCAT13((char)param_2,
                        CONCAT12((char)local_38,CONCAT11((char)local_34,(char)local_30)));
    _local_40 = CONCAT13((char)param_3,
                         CONCAT12((char)((uint)param_3 >> 8),
                                  CONCAT11((char)((uint)param_3 >> 0x10),
                                           (char)((uint)param_3 >> 0x18))));
    sum8_neg_append(local_48 + 1,0xb);
    itron_dly_tsk(1);
    do {
      iVar1 = (**(code **)(*param_1 + 0x10))(param_1,auStack_88,1);
    } while (iVar1 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,local_48,0xe);
    if (iVar1 != 0xe) {
      return 0;
    }
    itron_dly_tsk(1);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_88,4,100);
    if (iVar1 != -1) break;
    iVar3 = iVar3 + 1;
    if (local_28 <= iVar3) {
      uVar2 = 0;
      if (local_2c != 0) {
LAB_2010c2d0:
        (**(code **)(*param_1 + 0x18))(param_1,auStack_88,2,100);
        uVar2 = 1;
      }
      return uVar2;
    }
  }
  if (local_85 != param_4) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_84,1);
    return 0;
  }
  goto LAB_2010c2d0;
}


// ===== rx_boot_write_areas @ 2010c2f4 (624 bytes)

/* boot cmd 0x13 (512-byte blocks) / 0x51 (config area) */

undefined4
rx_boot_write_areas(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,
                   undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  
  iVar13 = 0;
  iVar2 = FUN_20111174(0);
  uVar3 = 0;
  do {
    if (param_2 <= uVar3) {
      return 1;
    }
    iVar4 = param_3 + uVar3 * 0x1c;
    uVar8 = *(uint *)(iVar4 + 0x14);
    iVar5 = iVar4;
    if (uVar8 != 0) {
      iVar5 = *(int *)(iVar4 + 0x18);
    }
    if ((uVar8 != 0 && iVar5 != 0) && (*(char *)(param_3 + uVar3 * 0x1c) != ' ')) {
      for (uVar10 = 0; uVar6 = *(uint *)(iVar4 + 0x18), uVar10 == 0 && (uVar6 <= uVar8) <= uVar10;
          uVar10 = uVar10 + bVar14) {
        uVar11 = uVar10 + (0xfff80000 < uVar8);
        uVar1 = uVar8 + 0x7ffff;
        if ((uint)(uVar8 + 0x7ffff <= uVar6) <= -uVar11) {
          uVar11 = 0;
          uVar1 = uVar6;
        }
        FUN_2015525c(iVar2,0x80000,0xff);
        iVar5 = fs_fseek(param_4,0);
        if (iVar5 != 0) {
          return 0;
        }
        iVar5 = srec_load_range(param_4,uVar8,uVar1,iVar2,param_5);
        if (iVar5 < 0) {
          return 0;
        }
        if (iVar5 != 0) {
          if (*(char *)(param_3 + uVar3 * 0x1c) == '0') {
            iVar5 = rx_boot_write_start(param_1,uVar8,uVar8 + 0x2f,0x51);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = rx_boot_data_packet(param_1,uVar8,0x30,iVar2,1,0x51);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = rx_boot_write_start(param_1,uVar8 + 0x40,uVar8 + 0x7f,0x51);
            if (iVar5 == 0) {
              return 0;
            }
            iVar5 = rx_boot_data_packet(param_1,uVar8 + 0x40,0x40,iVar2 + 0x40,1,0x51);
            if (iVar5 == 0) {
              return 0;
            }
          }
          else {
            uVar12 = 0x200;
            iVar5 = rx_boot_write_start(param_1,uVar8,uVar1,0x13);
            uVar6 = uVar8;
            uVar9 = uVar10;
            if (iVar5 == 0) {
              return 0;
            }
            for (; uVar9 <= uVar11 && (uint)(uVar1 <= uVar6) <= uVar9 - uVar11;
                uVar9 = uVar9 + bVar14) {
              uVar7 = uVar9 + CARRY4(uVar6,uVar12);
              bVar14 = uVar7 - uVar11 < (uint)(uVar1 <= uVar6 + uVar12);
              if (uVar11 < uVar7 || bVar14) {
                uVar12 = (uVar1 - uVar6) + 1;
              }
              iVar5 = rx_boot_data_packet(param_1,uVar6,uVar12,(uVar6 - uVar8) + iVar2,
                                          uVar11 < uVar7 || bVar14,0x13);
              if (iVar5 == 0) {
                return 0;
              }
              iVar13 = iVar13 + 1;
              uVar7 = FUN_20156260(iVar13 * 0x14,DAT_20800164);
              if (uVar7 < 0x14) {
                progress_set(uVar7 + 10);
              }
              bVar14 = CARRY4(uVar6,uVar12);
              uVar6 = uVar6 + uVar12;
            }
          }
        }
        bVar14 = 0xfff7ffff < uVar8;
        uVar8 = uVar8 + 0x80000;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}


// ===== rx_boot_erase @ 2010c564 (328 bytes)

/* boot cmd 0x50 (argument 0) */

undefined4 rx_boot_erase(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_70 [3];
  char local_6d;
  undefined1 auStack_6c [60];
  undefined4 local_30;
  undefined1 local_2c;
  undefined3 uStack_2b;
  undefined4 local_28 [2];
  undefined4 local_20 [2];
  
  memclr(auStack_70,0x40);
  iVar3 = 1;
  local_20[0] = 0x20;
  local_28[0] = 0x1400;
  local_28[1] = 0x9000;
  do {
    iVar4 = 0;
    while( true ) {
      if (0 < iVar4) {
        return 0;
      }
      local_30 = 0x50020001;
      _local_2c = CONCAT31(0x300,*(undefined1 *)((int)local_20 + iVar3));
      sum8_neg_append((int)&local_30 + 1,4);
      itron_dly_tsk(2);
      iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_30,7);
      if (iVar1 != 7) {
        return 0;
      }
      itron_dly_tsk(2);
      uVar2 = FUN_20156260(local_28[iVar3],10);
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_70,4,uVar2);
      if (iVar1 != -1) break;
      iVar4 = iVar4 + 1;
    }
    if (local_6d != 'P') {
      (**(code **)(*param_1 + 0x10))(param_1,auStack_6c,1);
      return 0;
    }
    itron_dly_tsk(2);
    (**(code **)(*param_1 + 0x18))(param_1,auStack_70,2,100);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return 1;
}


// ===== rx_boot_area_info @ 2010c6ac (588 bytes)

/* boot cmd 0x54 per area: type, start, end, unit sizes */

undefined4 rx_boot_area_info(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_78 [3];
  char local_75;
  undefined1 local_74;
  undefined1 auStack_73 [4];
  undefined1 auStack_6f [4];
  undefined1 auStack_6b [4];
  undefined1 auStack_67 [4];
  undefined1 auStack_63 [43];
  undefined4 local_38;
  undefined1 local_34;
  undefined3 uStack_33;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  memclr(auStack_78,0x40);
  uVar3 = 0;
LAB_2010c8f4:
  if (param_2 <= uVar3) {
    return 1;
  }
  iVar4 = 0;
  do {
    if (0 < iVar4) {
      return 0;
    }
    local_38 = 0x54020001;
    _local_34 = CONCAT31(0x300,(char)uVar3);
    local_30 = 0x54010081;
    uStack_2c = 0x3ab;
    sum8_neg_append((int)&local_38 + 1,4);
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_38,7);
    if (iVar1 != 7) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_78,4,100);
    if (iVar1 != -1) {
      if (local_75 != 'T') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_74,2,100);
      if (iVar1 != -1) {
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_30,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        FUN_2015525c(auStack_78,0x40,0xaa);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_78,4,100);
        if (iVar1 != -1) {
          if (local_75 != 'T') {
            (**(code **)(*param_1 + 0x18))(param_1,&local_74,1,100);
            return 0;
          }
          itron_dly_tsk(10);
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_74,0x11,200);
          if (iVar1 != -1) break;
        }
      }
    }
    iVar4 = iVar4 + 1;
  } while( true );
  *(undefined1 *)(param_3 + uVar3 * 0x1c) = local_74;
  uVar2 = be_bytes_to_u32(auStack_73,4);
  iVar4 = param_3 + uVar3 * 0x1c;
  *(undefined4 *)(iVar4 + 4) = uVar2;
  uVar2 = be_bytes_to_u32(auStack_6f,4);
  *(undefined4 *)(iVar4 + 8) = uVar2;
  uVar2 = be_bytes_to_u32(auStack_6b,4);
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  uVar2 = be_bytes_to_u32(auStack_67,4);
  *(undefined4 *)(iVar4 + 0x10) = uVar2;
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_63,2,100);
  uVar3 = uVar3 + 1;
  goto LAB_2010c8f4;
}


// ===== rx_boot_area_count @ 2010c918 (412 bytes)

/* boot cmd 0x53 */

undefined4 rx_boot_area_count(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_68 [3];
  char local_65;
  byte local_64 [60];
  undefined4 local_28;
  undefined4 uStack_24;
  
  memclr(auStack_68,0x40);
  iVar2 = 0;
  do {
    local_28 = 0x53010001;
    uStack_24 = 0x3ac;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
    if (iVar1 != -1) {
      if (local_65 != 'S') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_64,2,100);
      if (iVar1 != -1) {
        local_28 = CONCAT31(local_28._1_3_,0x81);
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
        if (iVar1 != -1) {
          if (local_65 != 'S') {
            return 0;
          }
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_64,1,100);
          if (iVar1 != -1) {
            *param_2 = (uint)local_64[0];
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_68,2,100);
            return 1;
          }
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_id_auth @ 2010cab4 (256 bytes)

/* boot cmd 0x30 with 16 x 0xFF ID code */

undefined4 rx_boot_id_auth(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_70 [3];
  char local_6d;
  undefined1 auStack_6c [60];
  undefined1 auStack_30 [24];
  
  memclr(auStack_70,0x40);
  iVar2 = 0;
  while( true ) {
    FUN_20155310(auStack_30,&DAT_2010cbbc,0x18);
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,auStack_30,0x16);
    if (iVar1 != 0x16) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_70,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_6d != '0') {
    (**(code **)(*param_1 + 0x18))(param_1,auStack_6c,4,100);
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_70,2,100);
  return 1;
}


// ===== rx_boot_cmd_2c @ 2010cbd4 (400 bytes)

/* boot cmd 0x2C, 1-byte answer */

undefined4 rx_boot_cmd_2c(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined1 auStack_5c [60];
  undefined4 local_20;
  undefined4 uStack_1c;
  
  memclr(auStack_60,0x40);
  iVar2 = 0;
  do {
    local_20 = 0x2c010001;
    uStack_1c = 0x3d3;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) {
      if (local_5d != ',') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,2,100);
      if (iVar1 != -1) {
        local_20 = CONCAT31(local_20._1_3_,0x81);
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
        if (iVar1 != -1) {
          if (local_5d != ',') {
            return 0;
          }
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,1,100);
          if (iVar1 != -1) {
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
            return 1;
          }
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_sync_cmd @ 2010cd64 (224 bytes)

/* boot cmd 0x00 */

undefined4 rx_boot_sync_cmd(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  memclr(auStack_60,0x40);
  iVar2 = 0;
  while( true ) {
    local_20 = 0x10001;
    uStack_1c = 0x3ff;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_5d != '\0') {
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
  return 1;
}


// ===== rx_boot_set_baud @ 2010ce54 (244 bytes)

/* boot cmd 0x34: 345600 bps */

undefined4 rx_boot_set_baud(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_68 [3];
  char local_65;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  memclr(auStack_68,0x40);
  iVar2 = 0;
  while( true ) {
    local_28 = 0x34050001;
    uStack_24 = 0x460500;
    uStack_20 = 0x304;
    sum8_neg_append((int)&local_28 + 1,7);
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,10);
    if (iVar1 != 10) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_65 != '4') {
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_68,2,100);
  return 1;
}


// ===== rx_boot_set_freq @ 2010cf48 (464 bytes)

/* boot cmd 0x32: 16 MHz input, 120 MHz system */

undefined4 rx_boot_set_freq(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_68 [3];
  char local_65;
  undefined1 auStack_64 [60];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  memclr(auStack_68,0x40);
  iVar4 = 0;
  do {
    local_28 = 0x32090001;
    uStack_24 = 0x24f400;
    uStack_20 = 0xe2707;
    uStack_1c = 0x371;
    itron_dly_tsk(2);
    iVar3 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,0xe);
    if (iVar3 != 0xe) {
      return 0;
    }
    itron_dly_tsk(2);
    FUN_2015525c(auStack_68,0x40,0xff);
    iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
    if (iVar3 != -1) {
      if (local_65 != '2') {
        return 0;
      }
      iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_64,2,100);
      uVar1 = local_28;
      if (iVar3 != -1) {
        local_28 = CONCAT31(local_28._1_3_,0x81);
        uVar2 = local_28;
        local_28._3_1_ = SUB41(uVar1,3);
        local_28._0_3_ = CONCAT12(1,(short)uVar2);
        sum8_neg_append((int)&local_28 + 1,3);
        uStack_24._0_2_ = CONCAT11(3,(undefined1)uStack_24);
        itron_dly_tsk(2);
        iVar3 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,6);
        if (iVar3 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        FUN_2015525c(auStack_68,0x40,0xff);
        iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
        if (iVar3 != -1) {
          if (local_65 != '2') {
            return 0;
          }
          iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_64,8,100);
          if (iVar3 != -1) {
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_68,2,100);
            return 1;
          }
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (0 < iVar4) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_endian @ 2010d134 (240 bytes)

/* boot cmd 0x36 (01) */

undefined4 rx_boot_endian(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  memclr(auStack_60,0x40);
  iVar2 = 0;
  while( true ) {
    local_20 = 0x36020001;
    uStack_1c = 0x3c701;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,7);
    if (iVar1 != 7) {
      return 0;
    }
    itron_dly_tsk(2);
    FUN_2015525c(auStack_60,0x40,0xff);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_5d != '6') {
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
  return 1;
}


// ===== rx_boot_signature @ 2010d224 (432 bytes)

/* boot cmd 0x38 */

undefined4 rx_boot_signature(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined1 auStack_5c [60];
  undefined4 local_20;
  undefined4 uStack_1c;
  
  memclr(auStack_60,0x40);
  iVar2 = 0;
  do {
    local_20 = 0x38010001;
    uStack_1c = 0x3c7;
    itron_dly_tsk(5);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    FUN_2015525c(auStack_60,0x40,0xff);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) {
      if (local_5d != '8') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,2,100);
      if (iVar1 != -1) {
        local_20 = CONCAT31(local_20._1_3_,0x81);
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(10);
        FUN_2015525c(auStack_60,0x40,0xff);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
        if (iVar1 != -1) {
          if (local_5d != '8') {
            return 0;
          }
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,0x18,100);
          if (iVar1 != -1) {
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
            return 1;
          }
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_sync @ 2010d3e4 (296 bytes)

/* 0x00 / 0x55 auto-baud at 9600 */

undefined4 rx_boot_sync(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint local_70;
  undefined1 auStack_6c [60];
  int local_30;
  byte local_2c [12];
  
  memclr(auStack_6c,0x3c);
  local_70 = 0xff;
  local_30 = 0;
  bVar1 = false;
  iVar2 = 0;
  local_2c[4] = 0;
  local_2c[5] = 0x55;
  local_2c[6] = 0;
  local_2c[7] = 0;
  local_2c[0] = 0;
  local_2c[1] = 0xc2;
  local_2c[2] = 0;
  local_2c[3] = 0;
  do {
    for (iVar3 = 0; iVar3 < 0x1e; iVar3 = iVar3 + 1) {
      itron_dly_tsk(1);
      local_30 = (**(code **)(*param_1 + 0x24))(param_1,local_2c + iVar2 + 4,1);
      if (local_30 != 1) {
        return 0;
      }
      itron_dly_tsk(2);
      local_30 = (**(code **)(*param_1 + 0x18))(param_1,&local_70,1,2);
      if (local_30 != -1) {
        if ((local_70 & 0xff) == (uint)local_2c[iVar2]) {
          bVar1 = true;
          goto LAB_2010d4c8;
        }
        break;
      }
    }
    if (!bVar1) {
      return 0;
    }
LAB_2010d4c8:
    itron_dly_tsk(2);
    (**(code **)(*param_1 + 0x18))(param_1,&local_70,4,100);
    iVar2 = iVar2 + 1;
    if (1 < iVar2) {
      return 1;
    }
  } while( true );
}


// ===== rx_boot_program @ 2010d50c (1040 bytes)

/* RX651 boot-mode programming of the decoded S-record */

undefined4 rx_boot_program(undefined4 param_1,uint *param_2)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  bool bVar10;
  uint *local_130;
  uint *puStack_12c;
  char local_128 [4];
  int aiStack_124 [55];
  char local_48 [12];
  uint local_3c;
  char local_38 [4];
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  uint *puStack_28;
  
  uVar7 = 0;
  local_38[0] = '\0';
  local_130 = (uint *)0x0;
  local_2c = param_1;
  puStack_28 = param_2;
  progress_range_init(&local_130,0,100);
  DAT_20800178 = local_130;
  DAT_2080017c = puStack_12c;
  piVar2 = (int *)scif5_get(0);
  local_130 = (uint *)0x1;
  (**(code **)(*piVar2 + 4))(piVar2,0x2580,8,0);
  iVar3 = rx_boot_sync(piVar2);
  uVar6 = 0;
  if (iVar3 != 0) {
    iVar3 = rx_boot_signature(piVar2);
    uVar6 = 0;
    if (iVar3 != 0) {
      iVar3 = rx_boot_endian(piVar2);
      uVar6 = 0;
      if (iVar3 != 0) {
        iVar3 = rx_boot_set_freq(piVar2);
        uVar6 = 0;
        if (iVar3 != 0) {
          progress_set(5);
          iVar3 = rx_boot_set_baud(piVar2);
          uVar6 = 0;
          if (iVar3 != 0) {
            (**(code **)(*piVar2 + 8))(piVar2);
            local_130 = (uint *)0x1;
            (**(code **)(*piVar2 + 4))(piVar2,0x54600,8,0);
            itron_dly_tsk(0x32);
            progress_set(6);
            iVar3 = rx_boot_sync_cmd(piVar2);
            uVar6 = 0;
            if (iVar3 != 0) {
              progress_set(7);
              iVar3 = rx_boot_cmd_2c(piVar2);
              uVar6 = 0;
              if (iVar3 != 0) {
                iVar3 = rx_boot_id_auth(piVar2);
                uVar6 = 0;
                if (iVar3 != 0) {
                  progress_set(8);
                  local_3c = 0;
                  iVar3 = rx_boot_area_count(piVar2,&local_3c);
                  uVar6 = 0;
                  if (iVar3 != 0) {
                    progress_set(9);
                    memclr(local_128,0xe0);
                    iVar3 = rx_boot_area_info(piVar2,local_3c,local_128);
                    uVar6 = 0;
                    if (iVar3 != 0) {
                      DAT_20800164 = 0;
                      for (; uVar7 < local_3c; uVar7 = uVar7 + 1) {
                        local_34 = 0;
                        local_30 = 0;
                        iVar3 = fs_fseek(local_2c,0);
                        if (iVar3 != 0) {
                          return 0;
                        }
                        if (local_128[uVar7 * 0x1c] != '@') {
                          local_130 = &local_30;
                          puStack_12c = param_2;
                          srec_find_range(local_2c,aiStack_124[uVar7 * 7],aiStack_124[uVar7 * 7 + 1]
                                          ,&local_34);
                          uVar5 = local_30;
                          if (local_34 <= local_30) {
                            iVar9 = aiStack_124[uVar7 * 7 + 3];
                            iVar3 = FUN_20156260(local_34,iVar9);
                            aiStack_124[uVar7 * 7 + 4] = iVar3 * iVar9;
                            iVar4 = FUN_20156260(uVar5,iVar9);
                            iVar4 = iVar4 * iVar9 + iVar9 + -1;
                            aiStack_124[uVar7 * 7 + 5] = iVar4;
                            uVar5 = (iVar4 - iVar3 * iVar9) + 1;
                            DAT_20800164 = DAT_20800164 +
                                           ((int)(uVar5 + ((uint)((int)uVar5 >> 0x1f) >> 0x17)) >> 9
                                           );
                            if ((uVar5 & 0x1ff) != 0) {
                              DAT_20800164 = DAT_20800164 + 1;
                            }
                          }
                        }
                      }
                      iVar3 = rx_boot_erase(piVar2);
                      uVar6 = 0;
                      if (iVar3 != 0) {
                        progress_set(10);
                        local_130 = param_2;
                        iVar3 = rx_boot_write_areas(piVar2,local_3c,local_128,local_2c);
                        uVar6 = 0;
                        if (iVar3 != 0) {
                          local_130 = param_2;
                          iVar3 = rx_boot_verify_areas(piVar2,local_3c,local_128,local_2c);
                          uVar6 = 0;
                          if (iVar3 != 0) {
                            progress_set(100);
                            gpio_rx_update(0);
                            itron_dly_tsk(10);
                            gpio_rx_reset(0);
                            itron_dly_tsk(10);
                            gpio_rx_reset(1);
                            itron_dly_tsk(500);
                            (**(code **)(*piVar2 + 8))(piVar2);
                            local_130 = (uint *)0x2;
                            pcVar8 = *(code **)(*piVar2 + 4);
                            (*pcVar8)(piVar2,0x54600,8,0);
                            local_48[0] = -0x10;
                            local_48[1] = 1;
                            local_48[2] = 8;
                            local_48[3] = 0x20;
                            local_48[4] = 0x23;
                            local_48[5] = 6;
                            local_48[8] = 0;
                            local_48[9] = '\0';
                            local_48[6] = 0x29;
                            local_48[7] = 6;
                            iVar3 = 0;
                            do {
                              pcVar1 = local_48 + iVar3;
                              iVar3 = iVar3 + 1;
                              if (8 < iVar3) {
                                pcVar8 = (code *)0x1e;
                              }
                              local_48[9] = local_48[9] + *pcVar1;
                            } while (iVar3 < 9);
                            do {
                              bVar10 = pcVar8 == (code *)0x0;
                              pcVar8 = pcVar8 + -1;
                              if ((bVar10) ||
                                 (local_130 = (uint *)(**(code **)(*piVar2 + 0x24))
                                                                (piVar2,local_48,10),
                                 local_130 != (uint *)0xa)) {
                                return 0;
                              }
                              iVar3 = (**(code **)(*piVar2 + 0x18))(piVar2,local_38,1,5);
                            } while ((iVar3 == -1) || (local_38[0] != '\x06'));
                            uVar6 = 1;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar6;
}

