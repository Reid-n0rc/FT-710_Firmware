// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb2fc0 @ fffb2fc0 (44 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2fd4) */

char FUN_fffb2fc0(byte param_1)

{
  return *(char *)((int)&PTR_DAT_fff880c2 + (uint)(param_1 >> 4) * 2) + (param_1 & 0xf);
}


// ===== FUN_fffb2fec @ fffb2fec (93 bytes)

short FUN_fffb2fec(ushort param_1)

{
  return *(short *)(&DAT_fff880ea + (uint)(param_1 >> 0xc) * 2) +
         *(short *)(&DAT_fff880d6 + (param_1 >> 8 & 0xf) * 2) +
         *(short *)((int)&PTR_DAT_fff880c2 + (param_1 >> 4 & 0xf) * 2) + (param_1 & 0xf);
}


// ===== FUN_fffb30b5 @ fffb30b5 (104 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb30e6) */

byte FUN_fffb30b5(byte *param_1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte local_6;
  
  local_6 = 0;
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    cVar2 = hex2nib(*param_1);
    local_6 = cVar2 << 4;
  }
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bVar3 = hex2nib(param_1[1]);
    local_6 = bVar3 | local_6;
  }
  return local_6;
}


// ===== FUN_fffb311d @ fffb311d (75 bytes)

void FUN_fffb311d(char *param_1,uint param_2)

{
  byte bVar1;
  
  if ((param_2 >> 4 & 0xff) < 10) {
    *param_1 = "@0123456789ABCDEF"[(param_2 >> 4 & 0xff) + 1];
  }
  else {
    *param_1 = ' ';
  }
  bVar1 = (byte)param_2 & 0xf;
  if (9 < bVar1) {
    param_1[1] = ' ';
    return;
  }
  param_1[1] = "@0123456789ABCDEF"[bVar1 + 1];
  return;
}


// ===== toupper_inplace @ fffb3168 (46 bytes)

/* a-z -> A-Z on one byte in place */

void toupper_inplace(byte *param_1)

{
  bool bVar1;
  
  if ((*param_1 < 0x61) || (0x7a < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *param_1 = *param_1 - 0x20;
    return;
  }
  return;
}


// ===== FUN_fffb3196 @ fffb3196 (182 bytes)

byte FUN_fffb3196(char param_1)

{
  undefined4 *in_R14;
  char local_a;
  byte local_9;
  
  local_a = '\0';
  if (param_1 != '\0') {
    in_R14 = (undefined4 *)&DAT_0000464f;
    local_a = DAT_00009c5e;
  }
  if (local_a == '\0') {
    *in_R14 = 1;
  }
  if (DAT_00009dbd == '\0') {
    if (in_R14 == (undefined4 *)0x0) {
      local_9 = DAT_00009d63;
    }
    else {
      local_9 = DAT_00009d09;
    }
  }
  else if (in_R14 == (undefined4 *)0x0) {
    local_9 = DAT_00009d09;
  }
  else {
    local_9 = DAT_00009d63;
  }
  if (DAT_00020f0c == '\x01') {
    local_9 = 2;
  }
  else if (DAT_00020f0c == '\x02') {
    local_9 = 2;
  }
  else if (DAT_00020b40 == '\x02') {
    local_9 = 2;
  }
  else if (DAT_00020b41 == '\x02') {
    local_9 = 2;
  }
  else if (DAT_00020b25 == '\x01') {
    local_9 = 2;
  }
  return local_9 & 0xf;
}


// ===== FUN_fffb324c @ fffb324c (94 bytes)

void FUN_fffb324c(char param_1)

{
  undefined4 *in_R14;
  char local_11;
  
  local_11 = '\0';
  if (param_1 != '\0') {
    in_R14 = (undefined4 *)&DAT_0000464f;
    local_11 = DAT_00009c5e;
  }
  if (local_11 == '\0') {
    *in_R14 = 1;
  }
  return;
}


// ===== FUN_fffb32aa @ fffb32aa (83 bytes)

undefined1 FUN_fffb32aa(char param_1)

{
  undefined4 *in_R14;
  undefined1 local_a;
  char local_9;
  
  local_9 = '\0';
  if (param_1 != '\0') {
    in_R14 = (undefined4 *)&DAT_0000464f;
    local_9 = DAT_00009c5e;
  }
  if (local_9 == '\0') {
    *in_R14 = 1;
  }
  if (DAT_00009dbd == '\0') {
    if (in_R14 == (undefined4 *)0x0) {
      local_a = 1;
    }
    else {
      local_a = 0;
    }
  }
  else if (in_R14 == (undefined4 *)0x0) {
    local_a = 0;
  }
  else {
    local_a = 1;
  }
  return local_a;
}


// ===== FUN_fffb32fd @ fffb32fd (58 bytes)

byte FUN_fffb32fd(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xd < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff886b8 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb3337 @ fffb3337 (58 bytes)

byte FUN_fffb3337(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (6 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff886f0 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb3371 @ fffb3371 (58 bytes)

byte FUN_fffb3371(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (10 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff8870c + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb33ab @ fffb33ab (58 bytes)

byte FUN_fffb33ab(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xc < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff88738 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== band_of_freq @ fffb33e5 (96 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb33f4) */
/* WARNING: Removing unreachable block (ram,0xfffb3403) */
/* Band index 0..11 of a frequency (ranges at 0xFFF8876C), 0xFF if none */

byte band_of_freq(uint param_1)

{
  bool bVar1;
  byte local_11;
  
  local_11 = 0;
  while( true ) {
    if (0xb < local_11) {
      return 0xff;
    }
    if ((param_1 < *(uint *)(&DAT_fff8876c + (uint)local_11 * 8)) ||
       (*(uint *)(&DAT_fff88770 + (uint)local_11 * 8) <= param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) break;
    local_11 = local_11 + 1;
  }
  return local_11;
}


// ===== FUN_fffb3445 @ fffb3445 (59 bytes)

byte FUN_fffb3445(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0x11 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff887cc + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb3480 @ fffb3480 (58 bytes)

byte FUN_fffb3480(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xd < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(&DAT_fff88814 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb34ba @ fffb34ba (21 bytes)

char FUN_fffb34ba(byte param_1)

{
  return "@0123456789ABCDEF"[param_1 + 0x11];
}


// ===== FUN_fffb34cf @ fffb34cf (21 bytes)

undefined1 FUN_fffb34cf(byte param_1)

{
  return (&DAT_fff81118)[param_1];
}


// ===== FUN_fffb34e4 @ fffb34e4 (21 bytes)

undefined2 FUN_fffb34e4(byte param_1)

{
  return *(undefined2 *)((int)&PTR_DAT_fff88126 + (uint)param_1 * 2);
}


// ===== FUN_fffb34f9 @ fffb34f9 (21 bytes)

undefined1 FUN_fffb34f9(byte param_1)

{
  return (&DAT_fff8117d)[param_1];
}


// ===== FUN_fffb350e @ fffb350e (21 bytes)

undefined2 FUN_fffb350e(byte param_1)

{
  return *(undefined2 *)(&DAT_fff881f0 + (uint)param_1 * 2);
}


// ===== FUN_fffb3523 @ fffb3523 (21 bytes)

undefined1 FUN_fffb3523(byte param_1)

{
  return (&DAT_fff811e2)[param_1];
}


// ===== FUN_fffb3538 @ fffb3538 (21 bytes)

undefined1 FUN_fffb3538(byte param_1)

{
  return (&DAT_fff812e2)[param_1];
}


// ===== FUN_fffb354d @ fffb354d (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3553) */

undefined1 FUN_fffb354d(byte param_1)

{
  return (&DAT_fff81347)[(uint)param_1 * 2];
}


// ===== FUN_fffb3564 @ fffb3564 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb356a) */

undefined1 FUN_fffb3564(byte param_1)

{
  return (&DAT_fff81348)[(uint)param_1 * 2];
}


// ===== FUN_fffb357c @ fffb357c (91 bytes)

void FUN_fffb357c(undefined1 param_1,char param_2)

{
  byte local_15;
  
  if ((param_2 != '\0') && (param_2 != '\x01')) {
    FUN_fffb324c(param_1);
  }
  for (local_15 = 0; local_15 < 4; local_15 = local_15 + 1) {
  }
  return;
}


// ===== FUN_fffb35d7 @ fffb35d7 (296 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb36cf) */

void FUN_fffb35d7(char param_1,char param_2)

{
  undefined4 *extraout_R14;
  undefined4 *puVar1;
  char cStack_18;
  
  FUN_fffb357c(param_1,param_2);
  cStack_18 = '\0';
  if ((param_2 != '\0') && (param_2 != '\x01')) {
    FUN_fffb324c(param_1);
    puVar1 = extraout_R14;
    if (param_1 != '\0') {
      puVar1 = (undefined4 *)&DAT_0000464f;
      cStack_18 = DAT_00009c5e;
    }
    if (cStack_18 == '\0') {
      *puVar1 = 1;
    }
  }
  return;
}


// ===== FUN_fffb36ff @ fffb36ff (118 bytes)

byte FUN_fffb36ff(byte param_1,ushort param_2)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    for (local_6 = 0; local_6 < 0x15; local_6 = local_6 + 1) {
      if (param_2 == (*(ushort *)(&DAT_fff882e8 + (uint)local_6 * 2) & 0xff)) {
        return local_6;
      }
    }
  }
  else if (uVar1 < 2) {
    for (local_6 = 0; local_6 < 0x17; local_6 = local_6 + 1) {
      if (param_2 == (*(ushort *)(&DAT_fff882ba + (uint)local_6 * 2) & 0xff)) {
        return local_6;
      }
    }
  }
  return 0xff;
}


// ===== FUN_fffb3775 @ fffb3775 (88 bytes)

undefined2 FUN_fffb3775(byte param_1,byte param_2)

{
  uint uVar1;
  undefined2 local_6;
  
  local_6 = 0xffff;
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    if (param_2 < 0x15) {
      local_6 = *(undefined2 *)(&DAT_fff882e8 + (uint)param_2 * 2);
    }
  }
  else if ((uVar1 < 2) && (param_2 < 0x17)) {
    local_6 = *(undefined2 *)(&DAT_fff882ba + (uint)param_2 * 2);
  }
  return local_6;
}


// ===== FUN_fffb37cd @ fffb37cd (49 bytes)

undefined1 FUN_fffb37cd(byte param_1)

{
  uint uVar1;
  undefined1 local_3;
  
  local_3 = 0xff;
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    local_3 = 0x15;
  }
  else if (uVar1 < 2) {
    local_3 = 0x17;
  }
  return local_3;
}


// ===== FUN_fffb37fe @ fffb37fe (675 bytes)

undefined1 FUN_fffb37fe(undefined *param_1)

{
  undefined *puVar1;
  bool bVar2;
  short sVar3;
  undefined **ppuVar4;
  int iVar5;
  byte bStack_1c;
  char cStack_1b;
  undefined1 uStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  undefined **ppuStack_14;
  
  sVar3 = dest_code_get();
  bStack_18 = 0;
  uStack_1a = 0;
  bStack_19 = 0xff;
  if (DAT_00020bbe != '\0') {
    return 1;
  }
  if ((DAT_0000465c == '\0') && (DAT_00009af5 == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (DAT_00020b46 == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (DAT_00020b47 == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return 0;
  }
  if (sVar3 == -0x26b0) {
    bStack_18 = 0xc;
    ppuStack_14 = (undefined **)&DAT_fff88a0c;
    goto LAB_fffb3933;
  }
  if (sVar3 == 0x1cb9) {
    bStack_18 = 1;
    ppuStack_14 = &PTR_DAT_fff88a6c;
    goto LAB_fffb3933;
  }
  if (sVar3 == 0x306f) goto LAB_fffb38f4;
  if (sVar3 == 0x315b) {
    bStack_18 = 0x15;
    ppuStack_14 = (undefined **)&DAT_fff888a4;
    goto LAB_fffb3933;
  }
  if (sVar3 == 0x4380) {
LAB_fffb38da:
    bStack_18 = 0xb;
    ppuStack_14 = (undefined **)&DAT_fff8884c;
  }
  else {
    if (sVar3 != 0x50e2) {
      if (sVar3 == 0x60e6) goto LAB_fffb38da;
      if (sVar3 == 0x7753) {
LAB_fffb3901:
        bStack_18 = 10;
        ppuStack_14 = (undefined **)&DAT_fff88964;
        goto LAB_fffb3933;
      }
      if ((sVar3 != -0x6309) && (sVar3 != -0x5b3b)) {
        if (sVar3 == -0x567d) {
          bStack_18 = 0xb;
          ppuStack_14 = (undefined **)&DAT_fff889b4;
          goto LAB_fffb3933;
        }
        if (sVar3 != -0x4a59) {
          if (sVar3 != -0x2cd3) {
            if (sVar3 != 0x20b) goto LAB_fffb3933;
            goto LAB_fffb38da;
          }
          goto LAB_fffb3901;
        }
      }
    }
LAB_fffb38f4:
    bStack_18 = 3;
    ppuStack_14 = (undefined **)&DAT_fff8894c;
  }
LAB_fffb3933:
  bStack_17 = 0;
  do {
    if (bStack_18 <= bStack_17) {
LAB_fffb397e:
      if (bStack_19 != 0xff) {
        if ((sVar3 == 0x315b) && (9 < bStack_19)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          iVar5 = FUN_fffb32aa(1);
          if (iVar5 == 0) {
            cStack_1b = DAT_00009dbe;
            bStack_1c = DAT_000060c9;
          }
          else {
            cStack_1b = DAT_00009dbf;
            bStack_1c = DAT_000060ca;
          }
          if ((cStack_1b == '\x02') && (0x74 < bStack_1c)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if ((bVar2) && (bStack_1c < 0x85)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (!bVar2) {
            uStack_1a = 0;
          }
        }
        if ((DAT_00020b8c == '\x01') || (DAT_00020b9e == '\x01')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          uStack_1a = 0;
          DAT_00020b24 = 0;
          DAT_00020b25 = 0;
          DAT_00020b26 = 0;
          DAT_00020b27 = 0;
          DAT_00020b28 = 0;
          DAT_00020b29 = 0;
          DAT_00020b2b = 0;
          DAT_00020b2c = 0;
          DAT_00020b2d = 0;
          DAT_00020b2e = 0;
        }
      }
      return uStack_1a;
    }
    puVar1 = *ppuStack_14;
    ppuVar4 = ppuStack_14 + 1;
    ppuStack_14 = ppuStack_14 + 2;
    if ((param_1 < puVar1) || (*ppuVar4 <= param_1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bStack_19 = bStack_17;
      uStack_1a = 1;
      goto LAB_fffb397e;
    }
    bStack_17 = bStack_17 + 1;
  } while( true );
}


// ===== FUN_fffb3aa1 @ fffb3aa1 (77 bytes)

undefined1 FUN_fffb3aa1(undefined *param_1)

{
  undefined1 uVar1;
  
  if ((&DAT_0000752f < param_1) && (param_1 < (undefined *)0x47868c1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffb3aee @ fffb3aee (69 bytes)

void FUN_fffb3aee(void)

{
  return;
}


// ===== dest_code_get @ fffb3b33 (42 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3b43) */
/* Returns destination code 0x475E:0x475F */

undefined2 dest_code_get(void)

{
  return CONCAT11(DAT_0000475e,DAT_0000475f);
}


// ===== dest_code_set @ fffb3b5d (73 bytes)

/* Sets destination code, writes EEPROM, settings_defaults(0), requests restart (0x20F4B=1,
   0x20B39=0x11) */

void dest_code_set(undefined2 param_1)

{
  undefined1 local_2;
  
  DAT_00009dc5 = 1;
  DAT_0000475e = (undefined1)((ushort)param_1 >> 8);
  local_2 = (undefined1)param_1;
  DAT_0000475f = local_2;
  eeprom_save_dest();
  settings_defaults(0);
  DAT_00020f4b = 1;
  DAT_00020b39 = 0x11;
  return;
}


// ===== FUN_fffb3ba6 @ fffb3ba6 (363 bytes)

void FUN_fffb3ba6(void)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  
  sVar3 = dest_code_get();
  cVar2 = FUN_fffb6f2a();
  if ((sVar3 == 0x315b) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_000050e2);
    return;
  }
  if ((sVar3 == 0x50e2) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000315b);
    return;
  }
  if ((sVar3 == -0x567d) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000b5a7);
    return;
  }
  if ((sVar3 == -0x4a59) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000a983);
    return;
  }
  if ((sVar3 == -0x26b0) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000a4c5);
    return;
  }
  if ((sVar3 == -0x5b3b) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000d950);
    return;
  }
  if ((sVar3 == -0x2cd3) && (cVar2 == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(&DAT_0000306f);
    return;
  }
  if ((sVar3 == 0x306f) && (cVar2 != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((sVar3 == 0x7753) && (cVar2 == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(&DAT_00009cf7);
      return;
    }
    if ((sVar3 == -0x6309) && (cVar2 != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(&DAT_00007753);
      return;
    }
    return;
  }
  dest_code_set(&DAT_0000d32d);
  return;
}


// ===== FUN_fffb3d11 @ fffb3d11 (324 bytes)

char FUN_fffb3d11(byte param_1)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  char local_3;
  
  local_3 = -1;
  bVar3 = FUN_fffb6ec5();
  uVar1 = (uint)param_1;
  if (uVar1 == 0xe) {
LAB_fffb3dc1:
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a74;
    }
    else {
      local_3 = DAT_00020b65;
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 == '\0') {
        local_3 = DAT_00009a4c;
      }
      else {
        local_3 = DAT_00020b65;
      }
      goto LAB_fffb3de6;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb3dc1;
      if (1 < uVar1 - 10) {
        if (uVar1 < 2) {
          if (DAT_00009dc6 == '\0') {
            local_3 = DAT_00009a37;
          }
          else {
            local_3 = DAT_00020b65;
          }
        }
        goto LAB_fffb3de6;
      }
    }
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a5e;
    }
    else {
      local_3 = DAT_00020b65;
    }
  }
LAB_fffb3de6:
  if (local_3 != -1) {
    if (DAT_00020b7c == '\x02') {
      local_3 = '\0';
    }
    else {
      if ((bVar3 == 0) || (bVar3 == 6)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (DAT_00009c5d != '\0') {
          local_3 = DAT_00009af3;
        }
      }
      else if (local_3 == '\x03') {
        if (bVar3 == 1) {
          local_3 = '\x02';
        }
        else if (bVar3 - 3 < 3) {
          local_3 = '\x01';
        }
        else {
          local_3 = '\0';
        }
      }
    }
  }
  return local_3;
}


// ===== FUN_fffb3e55 @ fffb3e55 (21 bytes)

void FUN_fffb3e55(void)

{
  DAT_000803fe = 0xa502;
  DAT_000800c2 = 0xa501;
  return;
}


// ===== FUN_fffb3e6a @ fffb3e6a (5 bytes)

void FUN_fffb3e6a(void)

{
  FUN_fff927ce();
  return;
}


// ===== FUN_fffb3e6f @ fffb3e6f (156 bytes)

undefined1 FUN_fffb3e6f(byte param_1)

{
  short sVar1;
  byte bStack_5;
  
  sVar1 = dest_code_get();
  if (sVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3ef4;
  }
  if (sVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3ef4;
  }
  if (sVar1 == 0x306f) {
LAB_fffb3edf:
    bStack_5 = 5;
  }
  else {
    if (sVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3ef4;
    }
    if (sVar1 != -0x26b0) {
      if (sVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3ef4;
      }
      if (sVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3ef4;
      }
      if ((sVar1 == 0x7753) || (sVar1 == -0x6309)) {
        bStack_5 = 9;
        goto LAB_fffb3ef4;
      }
      if (sVar1 != -0x5b3b) {
        if (sVar1 != -0x2cd3) {
          if (sVar1 == 0x4380) {
            bStack_5 = 0;
          }
          else {
            bStack_5 = 6;
          }
          goto LAB_fffb3ef4;
        }
        goto LAB_fffb3edf;
      }
    }
    bStack_5 = 7;
  }
LAB_fffb3ef4:
  return (&DAT_fff81547)[(uint)param_1 + (uint)bStack_5 * 5];
}


// ===== FUN_fffb3f0b @ fffb3f0b (156 bytes)

undefined1 FUN_fffb3f0b(byte param_1)

{
  short sVar1;
  byte bStack_5;
  
  sVar1 = dest_code_get();
  if (sVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3f90;
  }
  if (sVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3f90;
  }
  if (sVar1 == 0x306f) {
LAB_fffb3f7b:
    bStack_5 = 5;
  }
  else {
    if (sVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3f90;
    }
    if (sVar1 != -0x26b0) {
      if (sVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3f90;
      }
      if (sVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3f90;
      }
      if ((sVar1 == 0x7753) || (sVar1 == -0x6309)) {
        bStack_5 = 9;
        goto LAB_fffb3f90;
      }
      if (sVar1 != -0x5b3b) {
        if (sVar1 != -0x2cd3) {
          if (sVar1 == 0x4380) {
            bStack_5 = 0;
          }
          else {
            bStack_5 = 6;
          }
          goto LAB_fffb3f90;
        }
        goto LAB_fffb3f7b;
      }
    }
    bStack_5 = 7;
  }
LAB_fffb3f90:
  return (&DAT_fff81579)[(uint)param_1 + (uint)bStack_5 * 5];
}


// ===== FUN_fffb3fa7 @ fffb3fa7 (187 bytes)

void FUN_fffb3fa7(void)

{
  dest_code_get();
  return;
}


// ===== FUN_fffb4062 @ fffb4062 (211 bytes)

byte FUN_fffb4062(void)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  undefined *puVar6;
  byte bStack_f;
  
  uVar5 = FUN_fffb357c(1,2);
  cVar3 = FUN_fffb3196(1);
  cVar4 = FUN_fffb3371(uVar5);
  bVar2 = DAT_00009bfb;
  if ((cVar3 == '\x04') || (cVar3 == '\x05')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_f = DAT_00009bfb;
    puVar6 = (undefined *)dest_code_get();
    if (puVar6 == &DAT_000060e6) {
      if ((cVar4 == '\t') || (bVar2 < 0xb)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bStack_f = 10;
      }
    }
  }
  else if (cVar4 == '\t') {
    bStack_f = DAT_00009bf9;
  }
  else if (cVar4 == '\n') {
    bStack_f = DAT_00009bfa;
  }
  else {
    bStack_f = DAT_00009bf8;
  }
  if (DAT_00020f0c == '\x01') {
    bStack_f = 10;
  }
  else if (DAT_00020f0c == '\x02') {
    bStack_f = 5;
  }
  else if (DAT_00020b40 == '\x02') {
    bStack_f = 5;
  }
  else if (DAT_00020b41 == '\x02') {
    bStack_f = 5;
  }
  return bStack_f;
}


// ===== FUN_fffb4135 @ fffb4135 (85 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4172) */

void FUN_fffb4135(void)

{
  byte local_15;
  
  for (local_15 = 0; local_15 < 8; local_15 = local_15 + 1) {
  }
  return;
}


// ===== FUN_fffb418a @ fffb418a (143 bytes)

undefined1 FUN_fffb418a(undefined1 param_1)

{
  uint uVar1;
  undefined1 local_9;
  undefined1 local_1;
  
  local_1 = param_1;
  if (DAT_00009c5e != '\0') {
    local_1 = 1;
  }
  uVar1 = FUN_fffb3196(local_1);
  if (uVar1 == 0xe) {
LAB_fffb41fc:
    local_9 = DAT_00009bff;
  }
  else {
    if (uVar1 - 2 < 2) {
      return DAT_00009bfd;
    }
    if (uVar1 - 4 < 2) {
      return DAT_00009c00;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb41fc;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return DAT_00009bfe;
        }
        if (1 < uVar1) {
          return 0;
        }
        return DAT_00009bfc;
      }
    }
    local_9 = uRam00009c01;
  }
  return local_9;
}


// ===== FUN_fffb4219 @ fffb4219 (734 bytes)

/* WARNING: Type propagation algorithm not settling */

void FUN_fffb4219(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined4 *puVar7;
  
  cVar2 = DAT_00020b3d;
  FUN_fffb3196(DAT_00020b6b);
  FUN_fffb2dfe();
  cVar6 = DAT_00020cd1;
  cVar5 = DAT_00020cd0;
  cVar4 = DAT_00020ccd;
  cVar3 = DAT_00020b7c;
  FUN_fffba192();
  if (DAT_00020b96 == '\x01') {
    puVar7 = (undefined4 *)0x1;
  }
  else {
    puVar7 = (undefined4 *)(uint)DAT_00020b97;
    if (puVar7 != (undefined4 *)0x1) {
      bVar1 = false;
      goto LAB_fffb42a2;
    }
  }
  bVar1 = true;
LAB_fffb42a2:
  if (bVar1) {
    puVar7 = (undefined4 *)FUN_fffb3196(0);
  }
  else {
    if ((cVar3 == '\0') && (cVar5 != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (cVar6 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (cVar4 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (puVar7 = (undefined4 *)(uint)DAT_00020f1b, puVar7 == (undefined4 *)0x1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      puVar7 = (undefined4 *)FUN_fffb3196(1);
    }
  }
  if (cVar2 != '\x01') {
    *puVar7 = 1;
  }
  return;
}


// ===== key_event_filter @ fffb44f7 (1585 bytes)

/* Front-panel key event gate (key code, action): returns 1 if the key may run now; used by many CAT
   handlers */

undefined1 key_event_filter(ushort param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  undefined1 local_7;
  byte bStack_6;
  ushort local_2;
  
  cVar5 = (char)(param_2 >> 4);
  local_7 = 1;
  iVar4 = FUN_fffc4cc5(param_1,param_2 & 0xff);
  if ((iVar4 == 1) && (2 < param_1 - 0xff0)) {
    local_7 = 0;
  }
  bVar3 = (byte)param_2 & 0xf;
  bStack_6 = 0xff;
  if (param_1 == 0x348) {
    bStack_6 = DAT_00009acc;
  }
  else if (param_1 == 0x34e) {
    bStack_6 = DAT_00009acd;
  }
  else if (param_1 == 0x35e) {
    bStack_6 = DAT_00009acb;
  }
  else if (param_1 == 0x35c) {
    bStack_6 = DAT_00009ac9;
  }
  else if (param_1 == 0x35d) {
    bStack_6 = DAT_00009aca;
  }
  else if (param_1 == 0x35b) {
    bStack_6 = DAT_00009ac8;
  }
  local_2 = param_1;
  if (bStack_6 != 0xff) {
    if ((*(short *)(&DAT_fff88312 + (uint)bStack_6 * 2) == 0x300) && (bVar3 == 2)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      local_2 = *(ushort *)(&DAT_fff88312 + (uint)bStack_6 * 2);
    }
  }
  if ((local_2 == 0x300) && (bVar3 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    DAT_00020b30 = 2;
    local_7 = 0;
  }
  if (DAT_00020bbe == '\x01') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else if ((local_2 < 8) || (local_2 - 0x16 < 4)) {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
  }
  if (DAT_00020b8a == '\x01') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((((1 < uVar1 - 0xfe) && (uVar1 != 0xff1)) && (uVar1 != 0x302)) &&
         ((uVar1 != 0x30f && (uVar1 != 0x340)))) {
        if (uVar1 == 0x300) {
          local_7 = 0;
        }
        else {
          if (bVar3 == 1) {
            FUN_fffb2da6(3);
          }
          local_7 = 0;
        }
      }
    }
    return local_7;
  }
  if (DAT_00020b98 != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else {
      if ((local_2 < 0x200) || (0x288 < local_2)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((((!bVar2) && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) && (uVar1 != 0xe6)) &&
         (((0xe < uVar1 - 0x300 && (1 < uVar1 - 0x310)) && ((uVar1 != 0x340 && (1 < uVar1 - 0xff0)))
          ))) {
        if (bVar3 == 1) {
          FUN_fffb2da6(3);
        }
        local_7 = 0;
      }
    }
  }
  if ((DAT_00020b7c == '\x02') && ((local_2 - 0x87 < 5 || (local_2 - 0x8d < 4)))) {
    if (bVar3 == 1) {
      FUN_fffb2da6(3);
    }
    local_7 = 0;
  }
  if ((((DAT_00020b97 != '\0') && (uVar1 = (uint)local_2, uVar1 != 0xe8)) && (1 < uVar1 - 0xfe)) &&
     (((0xb < uVar1 - 0x110 && (uVar1 != 0xff1)) && ((uVar1 != 0x30c && (uVar1 != 0x30f)))))) {
    if (uVar1 == 0x300) {
      local_7 = 0;
    }
    else {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
  }
  if (((DAT_00020baf == '\x01') && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) &&
     ((4 < uVar1 - 0x110 &&
      ((((uVar1 != 0x119 && (uVar1 != 0x302)) && (uVar1 != 0x340)) && (uVar1 != 0xff1)))))) {
    if (bVar3 == 1) {
      FUN_fffb2da6(3);
    }
    local_7 = 0;
  }
  if (DAT_00020b3d != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if (((uVar1 != 0x10) && (5 < uVar1 - 0x30)) &&
         (((((9 < uVar1 - 0x87 && ((5 < uVar1 - 0xd0 && (0xd < uVar1 - 0xd7)))) &&
            (1 < uVar1 - 0xe6)) &&
           (((((uVar1 != 0xe9 && (6 < uVar1 - 0xec)) && (uVar1 != 0x12d)) &&
             (((2 < uVar1 - 0x300 && (uVar1 != 0x306)) &&
              ((uVar1 != 0x30f && ((uVar1 != 0x311 && (2 < uVar1 - 0xff0)))))))) && (uVar1 != 0x340)
            ))) && (((uVar1 != 0x348 && (uVar1 != 0x34e)) &&
                    ((uVar1 != 0x312 || (DAT_00020bbe == '\0')))))))) {
        if (bVar3 == 1) {
          FUN_fffb2da6(3);
        }
        local_7 = 0;
      }
    }
  }
  if (DAT_00020f11 != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((uVar1 != 0x14) && (0xe < uVar1 - 0xb0)) {
        if (uVar1 == 0x300) {
          local_7 = 0;
        }
        else {
          if (uVar1 != 0x302) {
            if (uVar1 == 0x30c) goto LAB_fffb48f7;
            if (uVar1 != 0x340) {
              if (bVar3 == 1) {
                FUN_fffb2da6(3);
              }
              local_7 = 0;
              goto LAB_fffb48f7;
            }
          }
          FUN_fffc23b6();
        }
      }
    }
  }
LAB_fffb48f7:
  if (DAT_00020f0c != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((((2 < uVar1 - 0x300) && (uVar1 != 0x340)) && (uVar1 != 0x348)) &&
         ((uVar1 != 0x34e && (uVar1 != 0xff0)))) {
        if (bVar3 == 1) {
          FUN_fffb2da6(3);
        }
        local_7 = 0;
      }
    }
  }
  if (DAT_00020b74 != '\0') {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else if (local_2 == 0x14) {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else if ((local_2 == 0x302) || (local_2 == 0x340)) {
      DAT_00020b74 = '\0';
    }
  }
  iVar4 = FUN_fffb4bba(2);
  if (iVar4 == 1) {
    if (cVar5 == '\x04') {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
    else if (local_2 - 0x12 < 3) {
      if (bVar3 == 1) {
        FUN_fffb2da6(3);
      }
      local_7 = 0;
    }
  }
  if ((DAT_00020b9b == '\x01') && (local_2 == 0xff1)) {
    local_7 = 0;
  }
  if ((DAT_00020f1b == '\x01') && (local_2 == 0x30e)) {
    if (bVar3 == 1) {
      FUN_fffb2da6(3);
    }
    local_7 = 0;
  }
  if ((DAT_00020ccd == '\x01') && (local_2 == 0x30e)) {
    if (bVar3 == 1) {
      FUN_fffb2da6(3);
    }
    local_7 = 0;
  }
  if ((DAT_00009c5e != '\0') && (local_2 == 0x306)) {
    if (bVar3 == 1) {
      FUN_fffb2da6(3);
    }
    local_7 = 0;
  }
  if ((DAT_00009c62 == '\0') || (DAT_00020b97 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((bVar2) && (local_2 == 0xff0)) {
    FUN_fffc8cbb(0x47);
    FUN_fffc8d8c();
    DAT_00020cc6 = 0x47;
    local_7 = 0;
  }
  if (((DAT_00020f0b != '\0') && (local_2 != 0x340)) && (2 < local_2 - 0xff0)) {
    DAT_00020f0b = '\0';
    FUN_fffb2df4();
  }
  if (((param_2 & 0xf) == 0) && (2 < local_2 - 0xff0)) {
    local_7 = 1;
  }
  if ((DAT_00020b8c == '\x01') || (DAT_00020b9e == '\x01')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && ((local_2 == 0x302 || (local_2 == 0x340)))) {
    if (bVar3 == 1) {
      FUN_fffb2da6(3);
    }
    local_7 = 0;
  }
  return local_7;
}


// ===== FUN_fffb4b28 @ fffb4b28 (146 bytes)

char FUN_fffb4b28(void)

{
  int iVar1;
  
  if ((DAT_00020b43 != '\x01') && (DAT_00020b08 < 0x7dd)) {
    iVar1 = FUN_fffb23f3(0x13);
    DAT_00020b43 = '\x01';
    if (iVar1 == 1) {
      power_off_io();
      DAT_00009dc5 = 1;
      FUN_fffd3d03();
      FUN_fffb02cf();
      DAT_00020f4b = 1;
      DAT_00020b39 = 0x90;
    }
    else {
      power_off_io();
      DAT_00009dc5 = 1;
      DAT_00020f4b = 1;
      DAT_00020b39 = 0x90;
    }
  }
  return DAT_00020b43;
}


// ===== FUN_fffb4bba @ fffb4bba (139 bytes)

undefined1 FUN_fffb4bba(char param_1)

{
  bool bVar1;
  undefined1 local_5;
  byte local_4;
  char local_3;
  char local_1;
  
  local_5 = 0;
  local_1 = param_1;
  if (param_1 == '\x02') {
    if (DAT_00009dbd == '\0') {
      local_1 = '\0';
    }
    else {
      local_1 = '\x01';
    }
  }
  if (local_1 == '\0') {
    local_3 = DAT_00009dbe;
    local_4 = DAT_000060c9;
  }
  else {
    local_3 = DAT_00009dbf;
    local_4 = DAT_000060ca;
  }
  if (local_3 == '\x02') {
    if ((local_4 < 0x75) || (0x84 < local_4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_5 = 1;
    }
  }
  else if (local_3 == '\a' || local_3 == '\b') {
    local_5 = 1;
  }
  return local_5;
}


// ===== FUN_fffb4c45 @ fffb4c45 (467 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4d66) */
/* WARNING: Removing unreachable block (ram,0xfffb4c6a) */
/* WARNING: Removing unreachable block (ram,0xfffb4dfd) */
/* WARNING: Removing unreachable block (ram,0xfffb4cbe) */
/* WARNING: Removing unreachable block (ram,0xfffb4d3b) */
/* WARNING: Removing unreachable block (ram,0xfffb4d06) */

ushort FUN_fffb4c45(void)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  ushort uStack_e;
  ushort uStack_a;
  
  iVar4 = FUN_fffb324c(0);
  bVar2 = FUN_fffb3196(0);
  uStack_e = 0;
  if (DAT_00009b15 == '\0') {
    uVar1 = (uint)bVar2;
    if (uVar1 == 0xe) {
      uStack_e = CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
    }
    else if (uVar1 - 2 < 2) {
      uStack_a = CONCAT11(*(undefined1 *)(iVar4 + 0x1c),*(undefined1 *)(iVar4 + 0x1d));
      if (bVar2 == 2) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 8 < 2) {
      uStack_a = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
                 CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
      if (bVar2 == 8) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 0xc < 2) {
      uStack_a = (ushort)*(byte *)(iVar4 + 0x27);
      sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x26),*(byte *)(iVar4 + 0x27));
      if (DAT_00009a8d == '\x01') {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0x69;
        }
        else {
          uStack_a = 0x69 - uStack_a;
        }
      }
      else if (DAT_00009a8d == '\x02') {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0xd7;
        }
        else {
          uStack_a = 0xd7 - uStack_a;
        }
      }
      else if (DAT_00009a8d == '\x03') {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0x1a9;
        }
        else {
          uStack_a = 0x1a9 - uStack_a;
        }
      }
      else if (bVar2 == 0xc) {
        uStack_a = sVar3 + 0x55;
      }
      else {
        uStack_a = 0x55 - uStack_a;
      }
      uStack_e = ~uStack_a + 1;
    }
    else if (uVar1 < 2) {
      uStack_a = CONCAT11(*(byte *)(iVar4 + 0x12),*(undefined1 *)(iVar4 + 0x13));
      if ((*(byte *)(iVar4 + 0x12) & 0x80) != 0) {
        uStack_a = -(~uStack_a + 1);
      }
      uStack_a = uStack_a + 0x5dc;
      if (bVar2 == 0) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
  }
  return uStack_e;
}


// ===== FUN_fffb4e18 @ fffb4e18 (166 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4e89) */
/* WARNING: Removing unreachable block (ram,0xfffb4e33) */
/* WARNING: Removing unreachable block (ram,0xfffb4e52) */

void FUN_fffb4e18(char param_1,uint param_2)

{
  byte bVar1;
  undefined1 *puStack_10;
  byte bStack_b;
  
  FUN_fffb35d7(0,2);
  bVar1 = band_of_freq();
  if (param_1 == '\x02') {
    puStack_10 = &DAT_00009c99 + (uint)bVar1 * 4;
    if (bVar1 == 0xb) {
      bVar1 = FUN_fffb3445(param_2);
      for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
        *(char *)((uint)bStack_b + (uint)bVar1 * 4 + 0x9cc9) =
             (char)(param_2 >> ((3 - bStack_b & 3) << 3));
      }
    }
  }
  else {
    puStack_10 = &DAT_00009c69 + (uint)bVar1 * 4;
  }
  for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
    puStack_10[bStack_b] = (char)(param_2 >> ((3 - bStack_b & 3) << 3));
  }
  return;
}

