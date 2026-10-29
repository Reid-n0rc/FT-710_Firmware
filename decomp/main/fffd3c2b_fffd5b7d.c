// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd3c2b @ fffd3c2b (132 bytes)

void FUN_fffd3c2b(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &DAT_00009bc6;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b69;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b88;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba7;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b4a;
  }
  menu_step_u8(0,3,local_8);
  return;
}


// ===== FUN_fffd3caf @ fffd3caf (38 bytes)

void FUN_fffd3caf(void)

{
  DAT_00015e05 = DAT_00009bc9;
  PTR_DAT_00025d60[0x420] = DAT_00009bc9;
  return;
}


// ===== FUN_fffd3d03 @ fffd3d03 (859 bytes)

void FUN_fffd3d03(void)

{
  DAT_00009a3d = DAT_00012238;
  DAT_00009a3e = DAT_00012239;
  DAT_00009a50 = DAT_0001223a;
  DAT_00009a51 = DAT_0001223b;
  DAT_00009a65 = DAT_0001223c;
  DAT_00009a66 = DAT_0001223d;
  DAT_00009a7c = DAT_0001223e;
  DAT_00009a7d = DAT_0001223f;
  DAT_00009a8f = DAT_00012240;
  DAT_00009a90 = DAT_00012241;
  DAT_00009aa5 = DAT_00012242;
  DAT_00009aa6 = DAT_00012243;
  DAT_00009ab3 = DAT_00012244;
  DAT_00009ab4 = DAT_00012245;
  DAT_00009acf = DAT_00012246;
  DAT_00009ad0 = DAT_00012247;
  DAT_00009ad7 = DAT_00012248;
  DAT_00009ad8 = DAT_00012249;
  DAT_00009aec = DAT_0001224a;
  DAT_00009aed = DAT_0001224b;
  DAT_00009af7 = DAT_0001224c;
  DAT_00009af8 = DAT_0001224d;
  DAT_00009aff = DAT_0001224e;
  DAT_00009b00 = DAT_0001224f;
  DAT_00009b12 = DAT_00012250;
  DAT_00009b13 = DAT_00012251;
  DAT_00009b18 = DAT_00012252;
  DAT_00009b19 = DAT_00012253;
  DAT_00009b1e = DAT_00012254;
  DAT_00009b1f = DAT_00012255;
  DAT_00009b22 = DAT_00012256;
  DAT_00009b23 = DAT_00012257;
  DAT_00009b24 = DAT_00012258;
  DAT_00009b25 = DAT_00012259;
  DAT_00009b26 = DAT_0001225a;
  DAT_00009b27 = DAT_0001225b;
  DAT_00009b28 = DAT_0001225e;
  DAT_00009b29 = DAT_0001225f;
  DAT_00009b2a = DAT_00012260;
  DAT_00009b2b = DAT_00012261;
  DAT_00009b2c = DAT_00012262;
  DAT_00009b2d = DAT_00012263;
  DAT_00009b4b = DAT_00012264;
  DAT_00009b4c = DAT_00012265;
  DAT_00009b6a = DAT_00012266;
  DAT_00009b6b = DAT_00012267;
  DAT_00009b89 = DAT_00012268;
  DAT_00009b8a = DAT_00012269;
  DAT_00009ba8 = DAT_0001226a;
  DAT_00009ba9 = DAT_0001226b;
  DAT_00009bc7 = DAT_0001226c;
  DAT_00009bc8 = DAT_0001226d;
  return;
}


// ===== FUN_fffd405e @ fffd405e (859 bytes)

void FUN_fffd405e(void)

{
  DAT_00012238 = DAT_00009a3d;
  DAT_00012239 = DAT_00009a3e;
  DAT_0001223a = DAT_00009a50;
  DAT_0001223b = DAT_00009a51;
  DAT_0001223c = DAT_00009a65;
  DAT_0001223d = DAT_00009a66;
  DAT_0001223e = DAT_00009a7c;
  DAT_0001223f = DAT_00009a7d;
  DAT_00012240 = DAT_00009a8f;
  DAT_00012241 = DAT_00009a90;
  DAT_00012242 = DAT_00009aa5;
  DAT_00012243 = DAT_00009aa6;
  DAT_00012244 = DAT_00009ab3;
  DAT_00012245 = DAT_00009ab4;
  DAT_00012246 = DAT_00009acf;
  DAT_00012247 = DAT_00009ad0;
  DAT_00012248 = DAT_00009ad7;
  DAT_00012249 = DAT_00009ad8;
  DAT_0001224a = DAT_00009aec;
  DAT_0001224b = DAT_00009aed;
  DAT_0001224c = DAT_00009af7;
  DAT_0001224d = DAT_00009af8;
  DAT_0001224e = DAT_00009aff;
  DAT_0001224f = DAT_00009b00;
  DAT_00012250 = DAT_00009b12;
  DAT_00012251 = DAT_00009b13;
  DAT_00012252 = DAT_00009b18;
  DAT_00012253 = DAT_00009b19;
  DAT_00012254 = DAT_00009b1e;
  DAT_00012255 = DAT_00009b1f;
  DAT_00012256 = DAT_00009b22;
  DAT_00012257 = DAT_00009b23;
  DAT_00012258 = DAT_00009b24;
  DAT_00012259 = DAT_00009b25;
  DAT_0001225a = DAT_00009b26;
  DAT_0001225b = DAT_00009b27;
  DAT_0001225e = DAT_00009b28;
  DAT_0001225f = DAT_00009b29;
  DAT_00012260 = DAT_00009b2a;
  DAT_00012261 = DAT_00009b2b;
  DAT_00012262 = DAT_00009b2c;
  DAT_00012263 = DAT_00009b2d;
  DAT_00012264 = DAT_00009b4b;
  DAT_00012265 = DAT_00009b4c;
  DAT_00012266 = DAT_00009b6a;
  DAT_00012267 = DAT_00009b6b;
  DAT_00012268 = DAT_00009b89;
  DAT_00012269 = DAT_00009b8a;
  DAT_0001226a = DAT_00009ba8;
  DAT_0001226b = DAT_00009ba9;
  DAT_0001226c = DAT_00009bc7;
  DAT_0001226d = DAT_00009bc8;
  return;
}


// ===== FUN_fffd43b9 @ fffd43b9 (118 bytes)

char FUN_fffd43b9(char param_1)

{
  bool bVar1;
  char local_3;
  
  local_3 = '\x01';
  if (DAT_00020b97 == '\0') {
    if (DAT_00020b96 != '\0') {
      local_3 = '\0';
    }
  }
  else {
    local_3 = '\0';
  }
  if ((local_3 == '\0') || (param_1 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (PTR_DAT_00025d60[0xa6] != '\x01')) {
    local_3 = '\0';
    if (param_1 == '\x01') {
      FUN_fffcf4d5();
    }
    else {
      FUN_fffcf4f2();
    }
  }
  if (local_3 == '\0') {
    beep_request(3);
    FUN_fffc8f30(0);
  }
  return local_3;
}


// ===== menu_register @ fffd442f (377 bytes)

/* Copy a 0x38-byte item descriptor into RAM table 0x2105C[0x15E]; append index to per-P1 list
   0x1FA50+0xC8*P1 (counts 0x1B4F6..FB) */

byte menu_register(byte *desc)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  byte local_6;
  
  if (desc == (byte *)0x0) {
    local_6 = 0;
  }
  else if (DAT_0001fa4e == 0x15e) {
    local_6 = 0;
  }
  else {
    pbVar2 = &DAT_0002105c + (uint)DAT_0001fa4e * 0x38;
    pbVar3 = desc;
    for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pbVar2 = *pbVar3;
      pbVar2 = pbVar2 + 1;
      pbVar3 = pbVar3 + 1;
    }
    bVar1 = desc[3];
    if (bVar1 == 5) {
      *(ushort *)(&DAT_0001fe38 + (uint)DAT_0001b4fb * 2) = DAT_0001fa4e;
      DAT_0001b4fb = DAT_0001b4fb + 1;
    }
    else if (bVar1 == 1) {
      *(ushort *)(&DAT_0001fb18 + (uint)DAT_0001b4f7 * 2) = DAT_0001fa4e;
      DAT_0001b4f7 = DAT_0001b4f7 + 1;
    }
    else if (bVar1 == 2) {
      *(ushort *)(&DAT_0001fbe0 + (uint)DAT_0001b4f8 * 2) = DAT_0001fa4e;
      DAT_0001b4f8 = DAT_0001b4f8 + 1;
    }
    else if (bVar1 == 3) {
      *(ushort *)(&DAT_0001fca8 + (uint)DAT_0001b4f9 * 2) = DAT_0001fa4e;
      DAT_0001b4f9 = DAT_0001b4f9 + 1;
    }
    else if (bVar1 == 4) {
      *(ushort *)(&DAT_0001fd70 + (uint)DAT_0001b4fa * 2) = DAT_0001fa4e;
      DAT_0001b4fa = DAT_0001b4fa + 1;
    }
    else {
      if (bVar1 != 0) {
        return 0;
      }
      *(ushort *)(&DAT_0001fa50 + (uint)DAT_0001b4f6 * 2) = DAT_0001fa4e;
      DAT_0001b4f6 = DAT_0001b4f6 + 1;
    }
    DAT_0001fa4e = DAT_0001fa4e + 1;
    if (0x15e < DAT_0001fa4e) {
      DAT_0001fa4e = 0x15f;
    }
    local_6 = 1;
  }
  return local_6;
}


// ===== menu_group_visible @ fffd45a8 (169 bytes)

/* (P1, global P2): 1 if any item of that group exists for this destination */

byte menu_group_visible(char param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  ushort uStack_6;
  
  bVar2 = menu_dest_mask();
  uStack_6 = 0;
  do {
    if (0x15d < uStack_6) {
      return 0;
    }
    if ((&DAT_0002105c)[(uint)uStack_6 * 0x38] == '\x01') {
      if (((&DAT_0002105f)[(uint)uStack_6 * 0x38] == param_1) &&
         ((&DAT_00021060)[(uint)uStack_6 * 0x38] == param_2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if ((&DAT_0002105d)[(uint)uStack_6 * 0x38] == '\0') {
          return 1;
        }
        if (((&DAT_0002105d)[(uint)uStack_6 * 0x38] & bVar2) != 0) {
          return 1;
        }
      }
    }
    uStack_6 = uStack_6 + 1;
  } while( true );
}


// ===== menu_find @ fffd4651 (324 bytes)

/* key {P1,P2,P3} -> table index via per-P1 list, honours dest_mask (+1); 0xFFFF if none */

ushort menu_find(char *param_1)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  byte bVar4;
  undefined *puStack_10;
  ushort uStack_8;
  
  if (param_1 != (char *)0x0) {
    bVar4 = menu_dest_mask();
    cVar1 = *param_1;
    if (cVar1 == '\x05') {
      puStack_10 = &DAT_0001fe38;
    }
    else if (cVar1 == '\x01') {
      puStack_10 = &DAT_0001fb18;
    }
    else if (cVar1 == '\x02') {
      puStack_10 = &DAT_0001fbe0;
    }
    else if (cVar1 == '\x03') {
      puStack_10 = &DAT_0001fca8;
    }
    else if (cVar1 == '\x04') {
      puStack_10 = &DAT_0001fd70;
    }
    else {
      if (cVar1 != '\0') {
        return 0xffff;
      }
      puStack_10 = &DAT_0001fa50;
    }
    for (uStack_8 = 0; uStack_8 < 100; uStack_8 = uStack_8 + 1) {
      uVar2 = *(ushort *)(puStack_10 + (uint)uStack_8 * 2);
      if ((&DAT_0002105c)[(uint)uVar2 * 0x38] == '\x01') {
        if ((*param_1 == (&DAT_0002105f)[(uint)uVar2 * 0x38]) &&
           (param_1[1] == (&DAT_00021060)[(uint)uVar2 * 0x38])) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if ((bVar3) && (param_1[2] == (&DAT_00021061)[(uint)uVar2 * 0x38])) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          if ((&DAT_0002105d)[(uint)uVar2 * 0x38] == '\0') {
            return uVar2;
          }
          if (((&DAT_0002105d)[(uint)uVar2 * 0x38] & bVar4) != 0) {
            return uVar2;
          }
        }
      }
    }
  }
  return 0xffff;
}


// ===== menu_get_desc @ fffd4795 (85 bytes)

/* key -> copy of the 0x38-byte descriptor */

byte menu_get_desc(char *key,byte *desc)

{
  bool bVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  byte local_d;
  
  if ((key == (char *)0x0) || (desc == (byte *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_d = 0;
  }
  else {
    uVar2 = menu_find(key);
    if (uVar2 == 0xffff) {
      local_d = 0;
    }
    else {
      pbVar3 = &DAT_0002105c + (uint)uVar2 * 0x38;
      for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {
        *desc = *pbVar3;
        desc = desc + 1;
        pbVar3 = pbVar3 + 1;
      }
      local_d = 1;
    }
  }
  return local_d;
}


// ===== menu_get_name @ fffd47ea (87 bytes)

/* key -> 21-char item name (desc+6) */

byte menu_get_name(char *key,char *name)

{
  bool bVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  byte local_d;
  
  if ((key == (char *)0x0) || (name == (char *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_d = 0;
  }
  else {
    uVar2 = menu_find(key);
    if (uVar2 == 0xffff) {
      local_d = 0;
    }
    else {
      pcVar3 = &DAT_00021062 + (uint)uVar2 * 0x38;
      for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
        *name = *pcVar3;
        name = name + 1;
        pcVar3 = pcVar3 + 1;
      }
      local_d = 1;
    }
  }
  return local_d;
}


// ===== menu_count_items @ fffd4841 (144 bytes)

/* Number of items in global P2 group (dest-filtered) */

char menu_count_items(char param_1)

{
  bool bVar1;
  byte bVar2;
  ushort local_6;
  char local_3;
  
  local_3 = '\0';
  for (local_6 = 0; local_6 < 0x15e; local_6 = local_6 + 1) {
    if (((&DAT_0002105c)[(uint)local_6 * 0x38] == '\x01') &&
       (param_1 == (&DAT_00021060)[(uint)local_6 * 0x38])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((&DAT_0002105d)[(uint)local_6 * 0x38] == '\0') {
        local_3 = local_3 + '\x01';
      }
      else {
        bVar2 = menu_dest_mask();
        if (((&DAT_0002105d)[(uint)local_6 * 0x38] & bVar2) != 0) {
          local_3 = local_3 + '\x01';
        }
      }
    }
  }
  return local_3;
}


// ===== menu_count_groups @ fffd48d1 (207 bytes)

/* Number of P2 groups in a P1 group (dest-filtered) */

char menu_count_groups(char param_1)

{
  bool bVar1;
  byte bVar2;
  ushort local_8;
  char local_5;
  char local_3;
  
  local_3 = '\0';
  local_5 = -1;
  for (local_8 = 0; local_8 < 0x15e; local_8 = local_8 + 1) {
    if (((&DAT_0002105c)[(uint)local_8 * 0x38] == '\x01') &&
       (param_1 == (&DAT_0002105f)[(uint)local_8 * 0x38])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (local_5 != (&DAT_00021060)[(uint)local_8 * 0x38])) {
      if ((&DAT_0002105d)[(uint)local_8 * 0x38] == '\0') {
        local_3 = local_3 + '\x01';
        local_5 = (&DAT_00021060)[(uint)local_8 * 0x38];
      }
      else {
        bVar2 = menu_dest_mask();
        if (((&DAT_0002105d)[(uint)local_8 * 0x38] & bVar2) != 0) {
          local_3 = local_3 + '\x01';
          local_5 = (&DAT_00021060)[(uint)local_8 * 0x38];
        }
      }
    }
  }
  return local_3;
}


// ===== menu_call_draw @ fffd49a0 (32 bytes)

/* key, buf -> desc.on_draw(buf) (+0x1C): encode value for the DISPLAY menu page */

void menu_call_draw(uint param_1,uint param_2)

{
  byte bVar1;
  byte abStack_40 [28];
  code *pcStack_24;
  uint local_8;
  uint local_4;
  
  local_8 = param_2;
  local_4 = param_1;
  bVar1 = menu_get_desc((char *)param_1,abStack_40);
  if (bVar1 != 1) {
    return;
  }
  (*pcStack_24)(local_8,pcStack_24);
  return;
}


// ===== menu_call_step @ fffd49c0 (26 bytes)

/* key -> desc.on_step() (+0x20): dial step, or apply hook when 0x15DFC=1 (CAT) */

void menu_call_step(uint param_1)

{
  byte bVar1;
  byte abStack_3c [32];
  code *pcStack_1c;
  uint local_4;
  
  local_4 = param_1;
  bVar1 = menu_get_desc((char *)param_1,abStack_3c);
  if (bVar1 != 1) {
    return;
  }
  (*pcStack_1c)(pcStack_1c);
  return;
}


// ===== menu_call_enter @ fffd49da (26 bytes)

/* key -> desc.on_enter() (+0x24): action items (SD card, reset, calibration...) */

void menu_call_enter(uint param_1)

{
  byte bVar1;
  byte abStack_3c [36];
  code *pcStack_18;
  uint local_4;
  
  local_4 = param_1;
  bVar1 = menu_get_desc((char *)param_1,abStack_3c);
  if (bVar1 != 1) {
    return;
  }
  (*pcStack_18)(pcStack_18);
  return;
}


// ===== menu_p2_global @ fffd49f4 (91 bytes)

/* (P1, local P2) -> global P2 index (bases 0,5,7,12,16,22) */

char menu_p2_global(char param_1,char param_2)

{
  char local_4;
  
  local_4 = param_2;
  if (param_1 != '\0') {
    if (param_1 == '\x01') {
      local_4 = param_2 + '\x05';
    }
    else if (param_1 == '\x02') {
      local_4 = param_2 + '\a';
    }
    else if (param_1 == '\x03') {
      local_4 = param_2 + '\f';
    }
    else if (param_1 == '\x04') {
      local_4 = param_2 + '\x10';
    }
    else if (param_1 == '\x05') {
      local_4 = param_2 + '\x16';
    }
  }
  return local_4;
}


// ===== menu_dest_mask @ fffd4a4f (139 bytes)

/* Destination code -> item mask bit (1,2,4,8,0x10,0x20) compared with desc+1 */

byte menu_dest_mask(void)

{
  ushort uVar1;
  byte bStack_5;
  
  uVar1 = dest_code_get();
  if (uVar1 == 0xd950) {
    return 0x10;
  }
  if (uVar1 == 0x1cb9) {
    return 0x20;
  }
  if (uVar1 == 0x306f) {
    return 8;
  }
  if (uVar1 == 0x315b) {
LAB_fffd4ab8:
    bStack_5 = 2;
  }
  else {
    if (uVar1 != 0x4380) {
      if (uVar1 == 0x50e2) goto LAB_fffd4ab8;
      if (uVar1 != 0x60e6) {
        if ((uVar1 == 0x7753) || (uVar1 == 0x9cf7)) {
          return 8;
        }
        if (uVar1 == 0xa4c5) {
          return 0x10;
        }
        if ((uVar1 == 0xa983) || (uVar1 == 0xb5a7)) {
          return 4;
        }
        if (uVar1 == 0xd32d) {
          return 8;
        }
        if (uVar1 != 0x20b) {
          return 1;
        }
      }
    }
    bStack_5 = 1;
  }
  return bStack_5;
}


// ===== menu_cursor_of @ fffd4ada (317 bytes)

/* Global P2 -> pointer to that group's {top,row} cursor */

uint menu_cursor_of(byte param_1)

{
  undefined1 *local_c;
  
  switch(param_1) {
  case 0:
    local_c = &DAT_00012238;
    break;
  case 1:
    local_c = &DAT_0001223a;
    break;
  case 2:
    local_c = &DAT_0001223c;
    break;
  case 3:
    local_c = &DAT_0001223e;
    break;
  case 4:
    local_c = &DAT_00012240;
    break;
  case 5:
    local_c = &DAT_00012242;
    break;
  case 6:
    local_c = &DAT_00012244;
    break;
  case 7:
    local_c = &DAT_00012246;
    break;
  case 8:
    local_c = &DAT_00012248;
    break;
  case 9:
    local_c = &DAT_0001224a;
    break;
  case 10:
    local_c = &DAT_0001224c;
    break;
  case 0xb:
    local_c = &DAT_0001224e;
    break;
  case 0xc:
    local_c = &DAT_00012250;
    break;
  case 0xd:
    local_c = &DAT_00012252;
    break;
  case 0xe:
    local_c = &DAT_00012254;
    break;
  case 0xf:
    local_c = &DAT_00012256;
    break;
  case 0x10:
    local_c = &DAT_00012258;
    break;
  case 0x11:
    local_c = &DAT_0001225a;
    break;
  case 0x12:
    local_c = &DAT_0001225c;
    break;
  case 0x13:
    local_c = &DAT_0001225e;
    break;
  case 0x14:
    local_c = &DAT_00012260;
    break;
  case 0x15:
    local_c = &DAT_00012262;
    break;
  case 0x16:
    local_c = &DAT_00012264;
    break;
  case 0x17:
    local_c = &DAT_00012266;
    break;
  case 0x18:
    local_c = &DAT_00012268;
    break;
  case 0x19:
    local_c = &DAT_0001226a;
    break;
  case 0x1a:
    local_c = &DAT_0001226c;
    break;
  default:
    local_c = (undefined1 *)0x0;
  }
  return (uint)local_c;
}


// ===== FUN_fffd4c17 @ fffd4c17 (15 bytes)

undefined1 FUN_fffd4c17(void)

{
  return PTR_s_V01_12_0001b4fd._0_1_;
}


// ===== FUN_fffd4c26 @ fffd4c26 (10 bytes)

void FUN_fffd4c26(void)

{
  PTR_s_V01_12_0001b4fd._0_1_ = 0;
  return;
}


// ===== menu_build_all @ fffd4c30 (961 bytes)

/* Straight list of 314 BSRs to menuitem_* (registration order = table index) */

void menu_build_all(void)

{
  menuitem_EX010101();
  menuitem_EX010102();
  menuitem_EX010103();
  menuitem_EX010104();
  menuitem_EX010105();
  menuitem_EX010106();
  menuitem_EX010107();
  menuitem_EX010108();
  menuitem_EX010109();
  menuitem_EX010110();
  menuitem_EX010111();
  menuitem_EX010112();
  menuitem_EX010113();
  menuitem_EX010114();
  menuitem_EX010115();
  menuitem_EX010116();
  menuitem_EX010117();
  menuitem_EX010118();
  menuitem_EX010119();
  menuitem_EX010201();
  menuitem_EX010202();
  menuitem_EX010203();
  menuitem_EX010204();
  menuitem_EX010205();
  menuitem_EX010206();
  menuitem_EX010207();
  menuitem_EX010208();
  menuitem_EX010209();
  menuitem_EX010210();
  menuitem_EX010211();
  menuitem_EX010212();
  menuitem_EX010213();
  menuitem_EX010214();
  menuitem_EX010215();
  menuitem_EX010216();
  menuitem_EX010217();
  menuitem_EX010301();
  menuitem_EX010302();
  menuitem_EX010303();
  menuitem_EX010304();
  menuitem_EX010305();
  menuitem_EX010306();
  menuitem_EX010307();
  menuitem_EX010308();
  menuitem_EX010309();
  menuitem_EX010310();
  menuitem_EX010311();
  menuitem_EX010312();
  menuitem_EX010313();
  menuitem_EX010314();
  menuitem_EX010315();
  menuitem_EX010316();
  menuitem_EX010317();
  menuitem_EX010318();
  menuitem_EX010319();
  menuitem_EX010320();
  menuitem_EX010321();
  menuitem_EX010401();
  menuitem_EX010402();
  menuitem_EX010403();
  menuitem_EX010404();
  menuitem_EX010405();
  menuitem_EX010406();
  menuitem_EX010407();
  menuitem_EX010408();
  menuitem_EX010409();
  menuitem_EX010410();
  menuitem_EX010411();
  menuitem_EX010412();
  menuitem_EX010413();
  menuitem_EX010414();
  menuitem_EX010415();
  menuitem_EX010416();
  menuitem_EX010417();
  menuitem_EX010418();
  menuitem_EX010419();
  menuitem_EX010420();
  menuitem_EX010501();
  menuitem_EX010502();
  menuitem_EX010503();
  menuitem_EX010504();
  menuitem_EX010505();
  menuitem_EX010506();
  menuitem_EX010507();
  menuitem_EX010508();
  menuitem_EX010509();
  menuitem_EX010510();
  menuitem_EX010511();
  menuitem_EX010512();
  menuitem_EX010513();
  menuitem_EX010514();
  menuitem_EX010515();
  menuitem_EX010516();
  menuitem_EX010517();
  menuitem_EX020101();
  menuitem_EX020102();
  menuitem_EX020103();
  menuitem_EX020104();
  menuitem_EX020105();
  menuitem_EX020106();
  menuitem_EX020107();
  menuitem_EX020108();
  menuitem_EX020109();
  menuitem_EX020110();
  menuitem_EX020111();
  menuitem_EX020112();
  menuitem_EX020113();
  menuitem_EX020114();
  menuitem_EX020115();
  menuitem_EX020116();
  menuitem_EX020117();
  menuitem_EX020118();
  menuitem_EX020119();
  menuitem_EX020120();
  menuitem_EX020201();
  menuitem_EX020202();
  menuitem_EX020203();
  menuitem_EX020204();
  menuitem_EX020205();
  menuitem_EX020206();
  menuitem_EX020207();
  menuitem_EX020208();
  menuitem_EX020209();
  menuitem_EX020210();
  menuitem_EX020211();
  menuitem_EX030101();
  menuitem_EX030102();
  menuitem_EX030103();
  menuitem_EX030104();
  menuitem_EX030105();
  menuitem_EX030106();
  menuitem_EX030107();
  menuitem_EX030108();
  menuitem_EX030109();
  menuitem_EX030110();
  menuitem_EX030111();
  menuitem_EX030112();
  menuitem_EX030113();
  menuitem_EX030114();
  menuitem_EX030115();
  menuitem_EX030116();
  menuitem_EX030117();
  menuitem_EX030118();
  menuitem_EX030119();
  menuitem_EX030120();
  menuitem_EX030121();
  menuitem_EX030122();
  menuitem_EX030123();
  menuitem_EX030124();
  menuitem_EX030125();
  menuitem_EX030126();
  menuitem_EX030201();
  menuitem_EX030202();
  menuitem_EX030203();
  menuitem_EX030204();
  menuitem_EX030205();
  menuitem_EX030206();
  menuitem_EX030301();
  menuitem_EX030302();
  menuitem_EX030303();
  menuitem_EX030304();
  menuitem_EX030305();
  menuitem_EX030306();
  menuitem_EX030307();
  menuitem_EX030308();
  menuitem_EX030309();
  menuitem_EX030310();
  menuitem_EX030311();
  menuitem_EX030312();
  menuitem_EX030313();
  menuitem_EX030314();
  menuitem_EX030315();
  menuitem_EX030316();
  menuitem_EX030317();
  menuitem_EX030318();
  menuitem_EX030319();
  menuitem_EX030401();
  menuitem_EX030402();
  menuitem_EX030403();
  menuitem_EX030404();
  menuitem_EX030405();
  menuitem_EX030406();
  menuitem_EX030407();
  menuitem_EX030408();
  menuitem_EX030501();
  menuitem_EX030502();
  menuitem_EX030503();
  menuitem_EX030504();
  menuitem_EX030505();
  menuitem_EX030506();
  menuitem_EX040101();
  menuitem_EX040102();
  menuitem_EX040103();
  menuitem_EX040104();
  menuitem_EX040105();
  menuitem_EX040106();
  menuitem_EX040201();
  menuitem_EX040202();
  menuitem_EX040203();
  menuitem_EX040204();
  menuitem_EX040301();
  menuitem_EX040302();
  menuitem_EX040303();
  menuitem_EX040304();
  menuitem_EX040401();
  menuitem_EX040402();
  menuitem_int4_16_00();
  menuitem_int4_16_01();
  menuitem_int4_16_02();
  menuitem_int4_16_03();
  menuitem_int4_16_04();
  menuitem_int4_17_00();
  menuitem_int4_17_01();
  menuitem_int4_17_02();
  menuitem_int4_17_03();
  menuitem_int4_17_04();
  menuitem_int4_17_05();
  menuitem_int4_17_06();
  menuitem_int4_18_00();
  menuitem_int4_19_00();
  menuitem_int4_20_00();
  menuitem_int4_20_01();
  menuitem_int4_20_02();
  menuitem_int4_21_00();
  menuitem_EX060101();
  menuitem_EX060102();
  menuitem_EX060103();
  menuitem_EX060104();
  menuitem_EX060105();
  menuitem_EX060106();
  menuitem_EX060107();
  menuitem_EX060108();
  menuitem_EX060109();
  menuitem_EX060110();
  menuitem_EX060111();
  menuitem_EX060112();
  menuitem_EX060113();
  menuitem_EX060114();
  menuitem_EX060115();
  menuitem_EX060116();
  menuitem_EX060117();
  menuitem_EX060118();
  menuitem_EX060201();
  menuitem_EX060202();
  menuitem_EX060203();
  menuitem_EX060204();
  menuitem_EX060205();
  menuitem_EX060206();
  menuitem_EX060207();
  menuitem_EX060208();
  menuitem_EX060209();
  menuitem_EX060210();
  menuitem_EX060211();
  menuitem_EX060212();
  menuitem_EX060213();
  menuitem_EX060214();
  menuitem_EX060215();
  menuitem_EX060216();
  menuitem_EX060217();
  menuitem_EX060218();
  menuitem_EX060301();
  menuitem_EX060302();
  menuitem_EX060303();
  menuitem_EX060304();
  menuitem_EX060305();
  menuitem_EX060306();
  menuitem_EX060307();
  menuitem_EX060308();
  menuitem_EX060309();
  menuitem_EX060310();
  menuitem_EX060311();
  menuitem_EX060312();
  menuitem_EX060313();
  menuitem_EX060314();
  menuitem_EX060315();
  menuitem_EX060316();
  menuitem_EX060317();
  menuitem_EX060318();
  menuitem_EX060401();
  menuitem_EX060402();
  menuitem_EX060403();
  menuitem_EX060404();
  menuitem_EX060405();
  menuitem_EX060406();
  menuitem_EX060407();
  menuitem_EX060408();
  menuitem_EX060409();
  menuitem_EX060410();
  menuitem_EX060411();
  menuitem_EX060412();
  menuitem_EX060413();
  menuitem_EX060414();
  menuitem_EX060415();
  menuitem_EX060416();
  menuitem_EX060417();
  menuitem_EX060418();
  menuitem_EX060501();
  menuitem_EX060502();
  menuitem_EX060503();
  menuitem_EX060504();
  menuitem_EX060505();
  menuitem_EX060506();
  menuitem_EX060507();
  menuitem_EX060508();
  menuitem_EX060509();
  menuitem_EX060510();
  menuitem_EX060511();
  menuitem_EX060512();
  menuitem_EX060513();
  menuitem_EX060514();
  menuitem_EX060515();
  menuitem_EX060516();
  menuitem_EX060517();
  menuitem_EX060518();
  return;
}


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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9b6b;
  local_18 = &LAB_fffcde05;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9be2;
  local_18 = &LAB_fffcde62;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9bfa;
  local_18 = &LAB_fffcde75;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9c12;
  local_18 = &LAB_fffcde88;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9cab;
  local_18 = &LAB_fffcde9b;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9cc2;
  local_18 = &LAB_fffcdeae;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9cd9;
  local_18 = &LAB_fffcdec1;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9d85;
  local_18 = &LAB_fffcdf17;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9e11;
  local_18 = &LAB_fffcdf29;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9ebf;
  local_18 = &LAB_fffcdf93;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9f4b;
  local_18 = &LAB_fffcdfa5;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9fc3;
  local_18 = &LAB_fffce000;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffc9fd9;
  local_18 = &LAB_fffce013;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffca110;
  local_18 = &LAB_fffce0ca;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffca19c;
  local_18 = &LAB_fffce0dc;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffca214;
  local_18 = &LAB_fffce0ef;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffca28c;
  local_18 = &LAB_fffce102;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffca318;
  local_18 = &LAB_fffce114;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffca396;
  local_18 = &LAB_fffce127;
  local_14 = &LAB_fffcdc78;
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
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
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
  local_1c = &LAB_fffca422;
  local_18 = &LAB_fffce139;
  local_14 = &LAB_fffcdc78;
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

