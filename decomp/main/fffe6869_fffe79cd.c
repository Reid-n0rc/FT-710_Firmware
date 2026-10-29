// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ex_parse_4digits @ fffe6869 (210 bytes)

/* 4 decimal digits, range check [min,max] */

bool ex_parse_4digits(char *text,ushort *out,ushort min,ushort max,byte digits,ushort len)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  ushort uVar6;
  bool local_17;
  byte local_16;
  
  if (digits == len) {
    for (local_16 = 0; local_16 < 4; local_16 = local_16 + 1) {
      if (((byte)text[local_16] < 0x30) || (0x39 < (byte)text[local_16])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return false;
      }
    }
    cVar2 = hex2nib(*text);
    cVar3 = hex2nib(text[1]);
    cVar4 = hex2nib(text[2]);
    cVar5 = hex2nib(text[3]);
    uVar6 = (short)cVar5 + cVar4 * 10 + cVar3 * 100 + cVar2 * 1000;
    if ((uVar6 < min) || (max < uVar6)) {
      local_17 = false;
    }
    else {
      local_17 = true;
    }
    if (local_17) {
      *out = uVar6;
    }
  }
  else {
    local_17 = false;
  }
  return local_17;
}


// ===== ex_parse_byte @ fffe693b (748 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6ab4) */
/* WARNING: Removing unreachable block (ram,0xfffe6b97) */
/* WARNING: Removing unreachable block (ram,0xfffe6a5c) */
/* WARNING: Removing unreachable block (ram,0xfffe6b40) */
/* 1-3 digits with optional sign, exact length, range check */

byte ex_parse_byte(char *text,byte *out,byte digits,byte is_signed,byte min,byte max,ushort len)

{
  bool bVar1;
  char cVar2;
  byte local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  byte local_10;
  
  local_10 = 0;
  local_14 = 0;
  if (is_signed == 1) {
    local_11 = digits + 10;
  }
  else {
    local_11 = digits + 9;
  }
  if (local_11 != len) {
    return 0;
  }
  if (digits == 1) {
    if (is_signed == 0) {
      if (((byte)*text < 0x30) || (0x39 < (byte)*text)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = hex2nib(*text);
    }
    else {
      if (((byte)text[1] < 0x30) || (0x39 < (byte)text[1])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = hex2nib(text[1]);
      if (*text == '-') {
        local_10 = ~local_10 + 1;
      }
      else if (*text != '+') {
        return 0;
      }
    }
  }
  else if (digits == 2) {
    local_12 = 10;
    if (is_signed == 0) {
      for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 3; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
      if (*text == '-') {
        local_10 = ~local_10 + 1;
      }
      else if (*text != '+') {
        return 0;
      }
    }
  }
  else if (digits == 3) {
    local_12 = 100;
    if (is_signed == 0) {
      for (local_13 = 0; local_13 < 3; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 4; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
      if (*text == '-') {
        local_10 = ~local_10 + 1;
      }
      else if (*text != '+') {
        return 0;
      }
    }
  }
  if (is_signed == 0) {
    if ((local_10 < min) || (max < local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *out = local_10;
      local_14 = 1;
    }
  }
  else {
    if (((char)local_10 < (char)min) || ((char)max < (char)local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *out = local_10;
      local_14 = 1;
    }
  }
  return local_14;
}


// ===== ex_parse_key @ fffe6c27 (339 bytes)

/* P1P1P2P2P3P3 (decimal) -> internal {P1-1, P2+base, P3-1}; CAT P1 05 and >06 rejected */

byte ex_parse_key(char *param_1,byte *param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte local_15;
  byte *local_14;
  byte local_10;
  char cStack_e;
  
  local_10 = 0;
  local_14 = param_2;
  while( true ) {
    if (5 < local_10) {
      cVar2 = hex2nib(*param_2);
      if (cVar2 == -1) {
        local_15 = 0;
      }
      else {
        cVar3 = hex2nib(param_2[1]);
        if (cVar3 == -1) {
          local_15 = 0;
        }
        else {
          cVar5 = cVar2 * '\n' + cVar3;
          cVar4 = hex2nib(param_2[2]);
          if (cVar4 == -1) {
            local_15 = 0;
          }
          else {
            cStack_e = hex2nib(param_2[3]);
            if (cStack_e == -1) {
              local_15 = 0;
            }
            else {
              cStack_e = cVar4 * '\n' + cStack_e;
              if (cVar5 == '\x06') {
                cStack_e = cStack_e + '\x15';
              }
              else if (cVar5 == '\x02') {
                cStack_e = cStack_e + '\x04';
              }
              else if (cVar5 == '\x03') {
                cStack_e = cStack_e + '\x06';
              }
              else if (cVar5 == '\x04') {
                cStack_e = cStack_e + '\v';
              }
              else {
                if (cVar5 != '\x01') {
                  return 0;
                }
                cStack_e = cStack_e + -1;
              }
              cVar5 = hex2nib(param_2[4]);
              if (cVar5 == -1) {
                local_15 = 0;
              }
              else {
                cVar4 = hex2nib(param_2[5]);
                if (cVar4 == -1) {
                  local_15 = 0;
                }
                else {
                  *param_1 = cVar2 * '\n' + cVar3 + -1;
                  param_1[1] = cStack_e;
                  param_1[2] = cVar5 * '\n' + cVar4 + -1;
                  local_15 = 1;
                }
              }
            }
          }
        }
      }
      return local_15;
    }
    if ((*local_14 < 0x30) || (0x39 < *local_14)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) break;
    local_14 = local_14 + 1;
    local_10 = local_10 + 1;
  }
  return 0;
}


// ===== cat_ai_ex_scan @ fffe6d7a (172 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6dac) */
/* Calls the 296 detectors in 0xFFF8E1A0 until one sets the length 0x1FF12; builds "EXnnnnnn" +
   value at 0x1B235; held off while 0x1B299 = 1 and timer 0x32 runs */

ushort cat_ai_ex_scan(undefined1 *param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  byte bStack_9;
  ushort local_8;
  
  DAT_0001ff12 = 0;
  local_8 = 0;
  while( true ) {
    if (0x127 < local_8) goto LAB_fffe6df2;
    (*(code *)(&PTR_ai_ex010101_fff8e1a0)[local_8])();
    if (DAT_0001ff12 != 0) break;
    local_8 = local_8 + 1;
  }
  for (bStack_9 = 0; bStack_9 < 8; bStack_9 = bStack_9 + 1) {
    (&DAT_0001b235)[bStack_9] =
         "EX010101EX010102EX010103EX010104EX010105EX010106EX010107EX010108EX010109EX010110EX010111EX010112EX010113EX010114EX010115EX010116EX010117EX010118EX010119EX010201EX010202EX010203EX010204EX010205EX010206EX010207EX010208EX010209EX010210EX010211EX010212EX010213EX010214EX010215EX010216EX010217EX010301EX010302EX010303EX010304EX010305EX010306EX010307EX010308EX010309EX010310EX010311EX010312EX010313EX010314EX010315EX010316EX010317EX010318EX010319EX010320EX010321EX010401EX010402EX010403EX010404EX010405EX010406EX010407EX010408EX010409EX010410EX010411EX010412EX010413EX010414EX010415EX010416EX010417EX010418EX010419EX010420EX010501EX010502EX010503EX010504EX010505EX010506EX010507EX010508EX010509EX010510EX010511EX010512EX010513EX010514EX010515EX010516EX010517EX020101EX020102EX020103EX020104EX020105EX020106EX020107EX020108EX020109EX020110EX020111EX020112EX020113EX020114EX020115EX020116EX020117EX020118EX020119EX020120EX020201EX020202EX020203EX020204EX020205EX020206EX020207EX020208EX020209EX020210EX020211EX030101EX030102EX030103EX030104EX030105EX030106EX030107EX030108EX030109EX030110EX030111EX030112EX030113EX030114EX030115EX030116EX030117EX030118EX030119EX030120EX030121EX030122EX030123EX030124EX030125EX030126EX030201EX030202EX030203EX030204EX030205EX030206EX030301EX030302EX030303EX030304EX030305EX030306EX030307EX030308EX030309EX030310EX030311EX030312EX030313EX030314EX030315EX030316EX030317EX030318EX030319EX030401EX030402EX030403EX030404EX030405EX030406EX030407EX030408EX030501EX030502EX030503EX030504EX030505EX030506EX040101EX040102EX040103EX040104EX040105EX040106EX040201EX040202EX040203EX040204EX040301EX040302EX040303EX040304EX040401EX040402EX060101EX060102EX060103EX060104EX060105EX060106EX060107EX060108EX060109EX060110EX060111EX060112EX060113EX060114EX060115EX060116EX060117EX060118EX060201EX060202EX060203EX060204EX060205EX060206EX060207EX060208EX060209EX060210EX060211EX060212EX060213EX060214EX060215EX060216EX060217EX060218EX060301EX060302EX060303EX060304EX060305EX060306EX060307EX060308EX060309EX060310EX060311EX060312EX060313EX060314..." /* TRUNCATED STRING LITERAL */
         [(uint)bStack_9 + (uint)local_8 * 8];
  }
  puVar2 = &DAT_0001b235;
  for (uVar3 = (uint)DAT_0001ff12; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_1 = *puVar2;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
LAB_fffe6df2:
  if (DAT_0001b299 == '\x01') {
    bVar1 = swtimer_expired(0x32);
    if (bVar1 != 1) {
      return 0;
    }
    DAT_0001b299 = '\0';
  }
  return DAT_0001ff12;
}


// ===== cat_ai_ex_holdoff @ fffe6e26 (20 bytes)

/* After an EX set: timer 0x32 = 200, 0x1B299 = 1 (like cat_ai_holdoff, own flag) */

void cat_ai_ex_holdoff(void)

{
  swtimer_start(0x32,200);
  DAT_0001b299 = 1;
  return;
}


// ===== ai_ex010101 @ fffe6e3a (61 bytes)

/* AI change detector for menu item EX010101 (table 0xFFF8E1A0[0]) */

void ai_ex010101(void)

{
  if (DAT_0001b29a == DAT_00009a2a) {
    return;
  }
  DAT_0001b29a = DAT_00009a2a;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a2a,0,1);
  return;
}


// ===== ai_ex010102 @ fffe6e77 (61 bytes)

/* AI change detector for menu item EX010102 (table 0xFFF8E1A0[1]) */

void ai_ex010102(void)

{
  if (DAT_0001b29b == DAT_00009a2b) {
    return;
  }
  DAT_0001b29b = DAT_00009a2b;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a2b,0,1);
  return;
}


// ===== ai_ex010103 @ fffe6eb4 (61 bytes)

/* AI change detector for menu item EX010103 (table 0xFFF8E1A0[2]) */

void ai_ex010103(void)

{
  if (DAT_0001b29c == DAT_00009a2c) {
    return;
  }
  DAT_0001b29c = DAT_00009a2c;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a2c,0,1);
  return;
}


// ===== ai_ex010104 @ fffe6ef1 (72 bytes)

/* AI change detector for menu item EX010104 (table 0xFFF8E1A0[3]) */

void ai_ex010104(void)

{
  if (DAT_0001b29d == DAT_00009a2d) {
    return;
  }
  DAT_0001b29d = DAT_00009a2d;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a2d + 1) * 0x14);
  return;
}


// ===== ai_ex010105 @ fffe6f39 (72 bytes)

/* AI change detector for menu item EX010105 (table 0xFFF8E1A0[4]) */

void ai_ex010105(void)

{
  if (DAT_0001b29e == DAT_00009a2e) {
    return;
  }
  DAT_0001b29e = DAT_00009a2e;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a2e + 1) * 0x14);
  return;
}


// ===== ai_ex010106 @ fffe6f81 (72 bytes)

/* AI change detector for menu item EX010106 (table 0xFFF8E1A0[5]) */

void ai_ex010106(void)

{
  if (DAT_0001b29f == DAT_00009a2f) {
    return;
  }
  DAT_0001b29f = DAT_00009a2f;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a2f + 1) * 0x14);
  return;
}


// ===== ai_ex010107 @ fffe6fc9 (61 bytes)

/* AI change detector for menu item EX010107 (table 0xFFF8E1A0[6]) */

void ai_ex010107(void)

{
  if (DAT_0001b2a0 == DAT_00009a30) {
    return;
  }
  DAT_0001b2a0 = DAT_00009a30;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a30,0,0);
  return;
}


// ===== ai_ex010108 @ fffe7006 (76 bytes)

/* AI change detector for menu item EX010108 (table 0xFFF8E1A0[7]) */

void ai_ex010108(void)

{
  if (DAT_0001b2a1 == DAT_00009a31) {
    return;
  }
  DAT_0001b2a1 = DAT_00009a31;
  DAT_0001b23d = nib2hex(DAT_00009a31);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010109 @ fffe7052 (61 bytes)

/* AI change detector for menu item EX010109 (table 0xFFF8E1A0[8]) */

void ai_ex010109(void)

{
  if (DAT_0001b2a2 == DAT_00009a32) {
    return;
  }
  DAT_0001b2a2 = DAT_00009a32;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a32,0,0);
  return;
}


// ===== ai_ex010110 @ fffe708f (76 bytes)

/* AI change detector for menu item EX010110 (table 0xFFF8E1A0[9]) */

void ai_ex010110(void)

{
  if (DAT_0001b2a3 == DAT_00009a33) {
    return;
  }
  DAT_0001b2a3 = DAT_00009a33;
  DAT_0001b23d = nib2hex(DAT_00009a33);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010111 @ fffe70db (61 bytes)

/* AI change detector for menu item EX010111 (table 0xFFF8E1A0[10]) */

void ai_ex010111(void)

{
  if (DAT_0001b2a4 == DAT_00009a34) {
    return;
  }
  DAT_0001b2a4 = DAT_00009a34;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a34,1,0);
  return;
}


// ===== ai_ex010112 @ fffe7118 (61 bytes)

/* AI change detector for menu item EX010112 (table 0xFFF8E1A0[11]) */

void ai_ex010112(void)

{
  if (DAT_0001b2a5 == DAT_00009a35) {
    return;
  }
  DAT_0001b2a5 = DAT_00009a35;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a35,1,0);
  return;
}


// ===== ai_ex010113 @ fffe7155 (76 bytes)

/* AI change detector for menu item EX010113 (table 0xFFF8E1A0[12]) */

void ai_ex010113(void)

{
  if (DAT_0001b2a6 == DAT_00009a36) {
    return;
  }
  DAT_0001b2a6 = DAT_00009a36;
  DAT_0001b23d = nib2hex(DAT_00009a36);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010114 @ fffe71a1 (76 bytes)

/* AI change detector for menu item EX010114 (table 0xFFF8E1A0[13]) */

void ai_ex010114(void)

{
  if (DAT_0001b2a7 == DAT_00009a37) {
    return;
  }
  DAT_0001b2a7 = DAT_00009a37;
  DAT_0001b23d = nib2hex(DAT_00009a37);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010115 @ fffe71ed (61 bytes)

/* AI change detector for menu item EX010115 (table 0xFFF8E1A0[14]) */

void ai_ex010115(void)

{
  if (DAT_0001b2a8 == DAT_00009a38) {
    return;
  }
  DAT_0001b2a8 = DAT_00009a38;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a38,1,0);
  return;
}


// ===== ai_ex010116 @ fffe722a (61 bytes)

/* AI change detector for menu item EX010116 (table 0xFFF8E1A0[15]) */

void ai_ex010116(void)

{
  if (DAT_0001b2a9 == DAT_00009a39) {
    return;
  }
  DAT_0001b2a9 = DAT_00009a39;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a39,1,0);
  return;
}


// ===== ai_ex010117 @ fffe7267 (76 bytes)

/* AI change detector for menu item EX010117 (table 0xFFF8E1A0[16]) */

void ai_ex010117(void)

{
  if (DAT_0001b2aa == DAT_00009a3a) {
    return;
  }
  DAT_0001b2aa = DAT_00009a3a;
  DAT_0001b23d = nib2hex(DAT_00009a3a);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010118 @ fffe72b3 (61 bytes)

/* AI change detector for menu item EX010118 (table 0xFFF8E1A0[17]) */

void ai_ex010118(void)

{
  if (DAT_0001b2ab == DAT_00009a3b) {
    return;
  }
  DAT_0001b2ab = DAT_00009a3b;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a3b,0,0);
  return;
}


// ===== ai_ex010119 @ fffe72f0 (76 bytes)

/* AI change detector for menu item EX010119 (table 0xFFF8E1A0[18]) */

void ai_ex010119(void)

{
  if (DAT_0001b2ac == DAT_00009a3c) {
    return;
  }
  DAT_0001b2ac = DAT_00009a3c;
  DAT_0001b23d = nib2hex(DAT_00009a3c);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010201 @ fffe733c (61 bytes)

/* AI change detector for menu item EX010201 (table 0xFFF8E1A0[19]) */

void ai_ex010201(void)

{
  if (DAT_0001b2ad == DAT_00009a3f) {
    return;
  }
  DAT_0001b2ad = DAT_00009a3f;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a3f,0,1);
  return;
}


// ===== ai_ex010202 @ fffe7379 (61 bytes)

/* AI change detector for menu item EX010202 (table 0xFFF8E1A0[20]) */

void ai_ex010202(void)

{
  if (DAT_0001b2ae == DAT_00009a40) {
    return;
  }
  DAT_0001b2ae = DAT_00009a40;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a40,0,1);
  return;
}


// ===== ai_ex010203 @ fffe73b6 (61 bytes)

/* AI change detector for menu item EX010203 (table 0xFFF8E1A0[21]) */

void ai_ex010203(void)

{
  if (DAT_0001b2af == DAT_00009a41) {
    return;
  }
  DAT_0001b2af = DAT_00009a41;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a41,0,1);
  return;
}


// ===== ai_ex010204 @ fffe73f3 (72 bytes)

/* AI change detector for menu item EX010204 (table 0xFFF8E1A0[22]) */

void ai_ex010204(void)

{
  if (DAT_0001b2b0 == DAT_00009a42) {
    return;
  }
  DAT_0001b2b0 = DAT_00009a42;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a42 + 1) * 0x14);
  return;
}


// ===== ai_ex010205 @ fffe743b (72 bytes)

/* AI change detector for menu item EX010205 (table 0xFFF8E1A0[23]) */

void ai_ex010205(void)

{
  if (DAT_0001b2b1 == DAT_00009a43) {
    return;
  }
  DAT_0001b2b1 = DAT_00009a43;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a43 + 1) * 0x14);
  return;
}


// ===== ai_ex010206 @ fffe7483 (72 bytes)

/* AI change detector for menu item EX010206 (table 0xFFF8E1A0[24]) */

void ai_ex010206(void)

{
  if (DAT_0001b2b2 == DAT_00009a44) {
    return;
  }
  DAT_0001b2b2 = DAT_00009a44;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a44 + 1) * 0x14);
  return;
}


// ===== ai_ex010207 @ fffe74cb (61 bytes)

/* AI change detector for menu item EX010207 (table 0xFFF8E1A0[25]) */

void ai_ex010207(void)

{
  if (DAT_0001b2b3 == DAT_00009a45) {
    return;
  }
  DAT_0001b2b3 = DAT_00009a45;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a45,0,0);
  return;
}


// ===== ai_ex010208 @ fffe7508 (76 bytes)

/* AI change detector for menu item EX010208 (table 0xFFF8E1A0[26]) */

void ai_ex010208(void)

{
  if (DAT_0001b2b4 == DAT_00009a46) {
    return;
  }
  DAT_0001b2b4 = DAT_00009a46;
  DAT_0001b23d = nib2hex(DAT_00009a46);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010209 @ fffe7554 (61 bytes)

/* AI change detector for menu item EX010209 (table 0xFFF8E1A0[27]) */

void ai_ex010209(void)

{
  if (DAT_0001b2b5 == DAT_00009a47) {
    return;
  }
  DAT_0001b2b5 = DAT_00009a47;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a47,0,0);
  return;
}


// ===== ai_ex010210 @ fffe7591 (76 bytes)

/* AI change detector for menu item EX010210 (table 0xFFF8E1A0[28]) */

void ai_ex010210(void)

{
  if (DAT_0001b2b6 == DAT_00009a48) {
    return;
  }
  DAT_0001b2b6 = DAT_00009a48;
  DAT_0001b23d = nib2hex(DAT_00009a48);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010211 @ fffe75dd (61 bytes)

/* AI change detector for menu item EX010211 (table 0xFFF8E1A0[29]) */

void ai_ex010211(void)

{
  if (DAT_0001b2b7 == DAT_00009a49) {
    return;
  }
  DAT_0001b2b7 = DAT_00009a49;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a49,1,0);
  return;
}


// ===== ai_ex010212 @ fffe761a (61 bytes)

/* AI change detector for menu item EX010212 (table 0xFFF8E1A0[30]) */

void ai_ex010212(void)

{
  if (DAT_0001b2b8 == DAT_00009a4a) {
    return;
  }
  DAT_0001b2b8 = DAT_00009a4a;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a4a,1,0);
  return;
}


// ===== ai_ex010213 @ fffe7657 (76 bytes)

/* AI change detector for menu item EX010213 (table 0xFFF8E1A0[31]) */

void ai_ex010213(void)

{
  if (DAT_0001b2b9 == DAT_00009a4b) {
    return;
  }
  DAT_0001b2b9 = DAT_00009a4b;
  DAT_0001b23d = nib2hex(DAT_00009a4b);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010214 @ fffe76a3 (76 bytes)

/* AI change detector for menu item EX010214 (table 0xFFF8E1A0[32]) */

void ai_ex010214(void)

{
  if (DAT_0001b2ba == DAT_00009a4c) {
    return;
  }
  DAT_0001b2ba = DAT_00009a4c;
  DAT_0001b23d = nib2hex(DAT_00009a4c);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010215 @ fffe76ef (61 bytes)

/* AI change detector for menu item EX010215 (table 0xFFF8E1A0[33]) */

void ai_ex010215(void)

{
  if (DAT_0001b2bb == DAT_00009a4d) {
    return;
  }
  DAT_0001b2bb = DAT_00009a4d;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a4d,1,0);
  return;
}


// ===== ai_ex010216 @ fffe772c (61 bytes)

/* AI change detector for menu item EX010216 (table 0xFFF8E1A0[34]) */

void ai_ex010216(void)

{
  if (DAT_0001b2bc == DAT_00009a4e) {
    return;
  }
  DAT_0001b2bc = DAT_00009a4e;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a4e,1,0);
  return;
}


// ===== ai_ex010217 @ fffe7769 (76 bytes)

/* AI change detector for menu item EX010217 (table 0xFFF8E1A0[35]) */

void ai_ex010217(void)

{
  if (DAT_0001b2bd == DAT_00009a4f) {
    return;
  }
  DAT_0001b2bd = DAT_00009a4f;
  DAT_0001b23d = nib2hex(DAT_00009a4f);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010301 @ fffe77b5 (61 bytes)

/* AI change detector for menu item EX010301 (table 0xFFF8E1A0[36]) */

void ai_ex010301(void)

{
  if (DAT_0001b2be == DAT_00009a52) {
    return;
  }
  DAT_0001b2be = DAT_00009a52;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a52,0,1);
  return;
}


// ===== ai_ex010302 @ fffe77f2 (61 bytes)

/* AI change detector for menu item EX010302 (table 0xFFF8E1A0[37]) */

void ai_ex010302(void)

{
  if (DAT_0001b2bf == DAT_00009a53) {
    return;
  }
  DAT_0001b2bf = DAT_00009a53;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a53,0,1);
  return;
}


// ===== ai_ex010303 @ fffe782f (61 bytes)

/* AI change detector for menu item EX010303 (table 0xFFF8E1A0[38]) */

void ai_ex010303(void)

{
  if (DAT_0001b2c0 == DAT_00009a54) {
    return;
  }
  DAT_0001b2c0 = DAT_00009a54;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a54,0,1);
  return;
}


// ===== ai_ex010304 @ fffe786c (72 bytes)

/* AI change detector for menu item EX010304 (table 0xFFF8E1A0[39]) */

void ai_ex010304(void)

{
  if (DAT_0001b2c1 == DAT_00009a55) {
    return;
  }
  DAT_0001b2c1 = DAT_00009a55;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a55 + 1) * 0x14);
  return;
}


// ===== ai_ex010305 @ fffe78b4 (72 bytes)

/* AI change detector for menu item EX010305 (table 0xFFF8E1A0[40]) */

void ai_ex010305(void)

{
  if (DAT_0001b2c2 == DAT_00009a56) {
    return;
  }
  DAT_0001b2c2 = DAT_00009a56;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a56 + 1) * 0x14);
  return;
}


// ===== ai_ex010306 @ fffe78fc (72 bytes)

/* AI change detector for menu item EX010306 (table 0xFFF8E1A0[41]) */

void ai_ex010306(void)

{
  if (DAT_0001b2c3 == DAT_00009a57) {
    return;
  }
  DAT_0001b2c3 = DAT_00009a57;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a57 + 1) * 0x14);
  return;
}


// ===== ai_ex010307 @ fffe7944 (61 bytes)

/* AI change detector for menu item EX010307 (table 0xFFF8E1A0[42]) */

void ai_ex010307(void)

{
  if (DAT_0001b2c4 == DAT_00009a58) {
    return;
  }
  DAT_0001b2c4 = DAT_00009a58;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a58,0,0);
  return;
}


// ===== ai_ex010308 @ fffe7981 (76 bytes)

/* AI change detector for menu item EX010308 (table 0xFFF8E1A0[43]) */

void ai_ex010308(void)

{
  if (DAT_0001b2c5 == DAT_00009a59) {
    return;
  }
  DAT_0001b2c5 = DAT_00009a59;
  DAT_0001b23d = nib2hex(DAT_00009a59);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010309 @ fffe79cd (61 bytes)

/* AI change detector for menu item EX010309 (table 0xFFF8E1A0[44]) */

void ai_ex010309(void)

{
  if (DAT_0001b2c6 == DAT_00009a5a) {
    return;
  }
  DAT_0001b2c6 = DAT_00009a5a;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a5a,0,0);
  return;
}

