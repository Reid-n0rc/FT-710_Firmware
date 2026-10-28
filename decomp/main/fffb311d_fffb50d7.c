// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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

void toupper_inplace(char *c)

{
  bool bVar1;
  
  if (((byte)*c < 0x61) || (0x7a < (byte)*c)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *c = *c + -0x20;
    return;
  }
  return;
}


// ===== vfo_mode @ fffb3196 (182 bytes)

/* (which): mode nibble (rec+0) of vfo_rec_ptr(which); forced to 2 during tune cycles */

byte vfo_mode(byte which)

{
  undefined1 local_a;
  undefined1 local_9;
  
  local_a = '\0';
  if (which != 0) {
    local_a = DAT_00009c5e;
  }
  if (DAT_00009dbd == '\0') {
    if (local_a == '\0') {
      local_9 = DAT_00009d09;
    }
    else {
      local_9 = DAT_00009d63;
    }
  }
  else if (local_a == '\0') {
    local_9 = DAT_00009d63;
  }
  else {
    local_9 = DAT_00009d09;
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


// ===== vfo_rec_ptr @ fffb324c (94 bytes)

/* (which): 0 = active VFO record (0x9DBD), !=0 = TX record (other VFO while split 0x9C5E); returns
   0x9D09/0x9D63 in R1 */

byte * vfo_rec_ptr(byte which)

{
  char local_11;
  byte *local_10;
  
  local_11 = '\0';
  if (which != 0) {
    local_11 = DAT_00009c5e;
  }
  if (DAT_00009dbd == '\0') {
    if (local_11 == '\0') {
      local_10 = &DAT_00009d09;
    }
    else {
      local_10 = &DAT_00009d63;
    }
  }
  else if (local_11 == '\0') {
    local_10 = &DAT_00009d63;
  }
  else {
    local_10 = &DAT_00009d09;
  }
  return local_10;
}


// ===== FUN_fffb32aa @ fffb32aa (83 bytes)

undefined1 FUN_fffb32aa(char param_1)

{
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = '\0';
  if (param_1 != '\0') {
    local_9 = DAT_00009c5e;
  }
  if (DAT_00009dbd == '\0') {
    if (local_9 == '\0') {
      local_a = 0;
    }
    else {
      local_a = 1;
    }
  }
  else if (local_9 == '\0') {
    local_a = 1;
  }
  else {
    local_a = 0;
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
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886b8 + (uint)local_d * 4)) break;
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
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_d * 4 + 0x28)) break;
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
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_d * 4 + 0x44)) break;
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
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_d * 4 + 0x70)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== band_of_freq @ fffb33e5 (96 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb33f4) */
/* WARNING: Removing unreachable block (ram,0xfffb3403) */
/* Band index 0..11 of a frequency (ranges at 0xFFF8876C), 0xFF if none */

byte band_of_freq(uint freq)

{
  bool bVar1;
  byte local_11;
  
  local_11 = 0;
  while( true ) {
    if (0xb < local_11) {
      return 0xff;
    }
    if ((freq < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_11 * 8 + 0xa4)) ||
       (*(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_11 * 8 + 0xa8) <= freq)) {
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


// ===== gen_subband_of_freq @ fffb3445 (59 bytes)

/* GEN sub-slot 0..15 from boundaries at 0xFFF887CC */

byte gen_subband_of_freq(uint freq)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0x11 < local_d) {
      return 0xff;
    }
    if (freq < *(uint *)(BYTE_ARRAY_fff887c4 + (uint)local_d * 4 + 8)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== freq_range_index @ fffb3480 (58 bytes)

/* Index of f in boundary table 0xFFF88814 */

byte freq_range_index(uint freq)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xd < local_d) {
      return 0xff;
    }
    if (freq < *(uint *)(BYTE_ARRAY_fff887dc + (uint)local_d * 4 + 0x38)) break;
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

byte FUN_fffb34cf(byte param_1)

{
  return BYTE_ARRAY_fff81041[param_1 + 0xd7];
}


// ===== FUN_fffb34e4 @ fffb34e4 (21 bytes)

undefined2 FUN_fffb34e4(byte param_1)

{
  return *(undefined2 *)((int)&PTR_DAT_fff88126 + (uint)param_1 * 2);
}


// ===== FUN_fffb34f9 @ fffb34f9 (21 bytes)

byte FUN_fffb34f9(byte param_1)

{
  return BYTE_ARRAY_fff81041[param_1 + 0x13c];
}


// ===== FUN_fffb350e @ fffb350e (21 bytes)

undefined2 FUN_fffb350e(byte param_1)

{
  return *(undefined2 *)(BYTE_ARRAY_fff881a8 + (uint)param_1 * 2 + 0x48);
}


// ===== FUN_fffb3523 @ fffb3523 (21 bytes)

byte FUN_fffb3523(byte param_1)

{
  return BYTE_ARRAY_fff81041[param_1 + 0x1a1];
}


// ===== FUN_fffb3538 @ fffb3538 (21 bytes)

byte FUN_fffb3538(byte param_1)

{
  return BYTE_ARRAY_fff812ba[param_1 + 0x28];
}


// ===== FUN_fffb354d @ fffb354d (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3553) */

char FUN_fffb354d(byte param_1)

{
  return " \"#%&(*+-/1357:<<<<<<<<<<<"[(uint)param_1 * 2 + 0x1a];
}


// ===== FUN_fffb3564 @ fffb3564 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb356a) */

byte FUN_fffb3564(byte param_1)

{
  return BYTE_ARRAY_fff81348[(uint)param_1 * 2];
}


// ===== vfo_freq @ fffb357c (91 bytes)

/* (which, side): BE u32 at rec+0x4A; side 0=A 1=B 2=vfo_rec_ptr(which) */

uint vfo_freq(byte which,byte side)

{
  byte local_15;
  uint uStack_14;
  byte *local_10;
  
  if (side == 0) {
    local_10 = &DAT_00009d09;
  }
  else if (side == 1) {
    local_10 = &DAT_00009d63;
  }
  else {
    local_10 = vfo_rec_ptr(which);
  }
  for (local_15 = 0; local_15 < 4; local_15 = local_15 + 1) {
    uStack_14 = (uint)local_10[local_15 + 0x4a] | uStack_14 << 8;
  }
  return uStack_14;
}


// ===== vfo_freq_clar @ fffb35d7 (296 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb36cf) */
/* (which, side): vfo_freq + clar offset rec+0x48 if RX/TX clar bit set in 0x20F29/0x20F2A */

uint vfo_freq_clar(byte which,byte side)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  char cStack_18;
  byte bStack_17;
  uint uStack_14;
  byte *pbStack_10;
  
  uStack_14 = vfo_freq(which,side);
  cStack_18 = '\0';
  bVar2 = false;
  if (side == 0) {
    bStack_17 = DAT_00020f29;
    pbStack_10 = &DAT_00009d09;
  }
  else if (side == 1) {
    bStack_17 = DAT_00020f2a;
    pbStack_10 = &DAT_00009d63;
  }
  else {
    pbStack_10 = vfo_rec_ptr(which);
    if (which != 0) {
      cStack_18 = DAT_00009c5e;
    }
    if (DAT_00009dbd == '\0') {
      if (cStack_18 == '\0') {
        bStack_17 = DAT_00020f29;
      }
      else {
        bStack_17 = DAT_00020f2a;
      }
    }
    else if (cStack_18 == '\0') {
      bStack_17 = DAT_00020f2a;
    }
    else {
      bStack_17 = DAT_00020f29;
    }
  }
  if ((which == 0) || ((bStack_17 & 2) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bVar2 = true;
  }
  else {
    if ((which == 0) && ((bStack_17 & 1) != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    uVar3 = CONCAT11(pbStack_10[0x48],pbStack_10[0x49]);
    if ((pbStack_10[0x48] & 0x80) == 0) {
      uStack_14 = uVar3 + uStack_14;
    }
    else {
      uStack_14 = uStack_14 - (ushort)(~uVar3 + 1);
    }
  }
  return uStack_14;
}


// ===== FUN_fffb36ff @ fffb36ff (118 bytes)

byte FUN_fffb36ff(byte param_1,ushort param_2)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    for (local_6 = 0; local_6 < 0x15; local_6 = local_6 + 1) {
      if (param_2 == (*(ushort *)(BYTE_ARRAY_fff88270 + (uint)local_6 * 2 + 0x78) & 0xff)) {
        return local_6;
      }
    }
  }
  else if (uVar1 < 2) {
    for (local_6 = 0; local_6 < 0x17; local_6 = local_6 + 1) {
      if (param_2 == (*(ushort *)(BYTE_ARRAY_fff88270 + (uint)local_6 * 2 + 0x4a) & 0xff)) {
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
      local_6 = *(undefined2 *)(BYTE_ARRAY_fff88270 + (uint)param_2 * 2 + 0x78);
    }
  }
  else if ((uVar1 < 2) && (param_2 < 0x17)) {
    local_6 = *(undefined2 *)(BYTE_ARRAY_fff88270 + (uint)param_2 * 2 + 0x4a);
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


// ===== tx_freq_allowed @ fffb37fe (675 bytes)

/* (freq): destination-code band table 0xFFF8884C.., inhibit flags */

bool tx_freq_allowed(uint freq)

{
  undefined *puVar1;
  bool bVar2;
  ushort uVar3;
  undefined **ppuVar4;
  int iVar5;
  byte bStack_1c;
  char cStack_1b;
  bool bStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  undefined **ppuStack_14;
  
  uVar3 = dest_code_get();
  bStack_18 = 0;
  bStack_1a = false;
  bStack_19 = 0xff;
  if (DAT_00020bbe != '\0') {
    return true;
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
    return false;
  }
  if (uVar3 == 0xd950) {
    bStack_18 = 0xc;
    ppuStack_14 = (undefined **)&DAT_fff88a0c;
    goto LAB_fffb3933;
  }
  if (uVar3 == 0x1cb9) {
    bStack_18 = 1;
    ppuStack_14 = &PTR_DAT_fff88a6c;
    goto LAB_fffb3933;
  }
  if (uVar3 == 0x306f) goto LAB_fffb38f4;
  if (uVar3 == 0x315b) {
    bStack_18 = 0x15;
    ppuStack_14 = (undefined **)(BYTE_ARRAY_fff887dc + 200);
    goto LAB_fffb3933;
  }
  if (uVar3 == 0x4380) {
LAB_fffb38da:
    bStack_18 = 0xb;
    ppuStack_14 = (undefined **)(BYTE_ARRAY_fff887dc + 0x70);
  }
  else {
    if (uVar3 != 0x50e2) {
      if (uVar3 == 0x60e6) goto LAB_fffb38da;
      if (uVar3 == 0x7753) {
LAB_fffb3901:
        bStack_18 = 10;
        ppuStack_14 = (undefined **)(BYTE_ARRAY_fff8894c + 0x18);
        goto LAB_fffb3933;
      }
      if ((uVar3 != 0x9cf7) && (uVar3 != 0xa4c5)) {
        if (uVar3 == 0xa983) {
          bStack_18 = 0xb;
          ppuStack_14 = (undefined **)(BYTE_ARRAY_fff8894c + 0x68);
          goto LAB_fffb3933;
        }
        if (uVar3 != 0xb5a7) {
          if (uVar3 != 0xd32d) {
            if (uVar3 != 0x20b) goto LAB_fffb3933;
            goto LAB_fffb38da;
          }
          goto LAB_fffb3901;
        }
      }
    }
LAB_fffb38f4:
    bStack_18 = 3;
    ppuStack_14 = (undefined **)BYTE_ARRAY_fff8894c;
  }
LAB_fffb3933:
  bStack_17 = 0;
  do {
    if (bStack_18 <= bStack_17) {
LAB_fffb397e:
      if (bStack_19 != 0xff) {
        if ((uVar3 == 0x315b) && (9 < bStack_19)) {
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
            bStack_1a = false;
          }
        }
        if ((DAT_00020b8c == '\x01') || (DAT_00020b9e == '\x01')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          bStack_1a = false;
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
      return bStack_1a;
    }
    puVar1 = *ppuStack_14;
    ppuVar4 = ppuStack_14 + 1;
    ppuStack_14 = ppuStack_14 + 2;
    if ((freq < puVar1) || (*ppuVar4 <= freq)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bStack_19 = bStack_17;
      bStack_1a = true;
      goto LAB_fffb397e;
    }
    bStack_17 = bStack_17 + 1;
  } while( true );
}


// ===== freq_in_range @ fffb3aa1 (77 bytes)

/* 29999 < f < 75000001 */

byte freq_in_range(void *param_1)

{
  byte bVar1;
  
  if ((&DAT_0000752f < param_1) && (param_1 < (void *)0x47868c1)) {
    bVar1 = 1;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}


// ===== FUN_fffb3aee @ fffb3aee (69 bytes)

void FUN_fffb3aee(void)

{
  return;
}


// ===== dest_code_get @ fffb3b33 (42 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3b43) */
/* Returns destination code 0x475E:0x475F */

ushort dest_code_get(void)

{
  return CONCAT11(DAT_0000475e,DAT_0000475f);
}


// ===== dest_code_set @ fffb3b5d (73 bytes)

/* Sets destination code, writes EEPROM, settings_defaults(0), requests restart (0x20F4B=1,
   0x20B39=0x11) */

void dest_code_set(ushort param_1)

{
  undefined1 local_2;
  
  DAT_00009dc5 = 1;
  DAT_0000475e = (undefined1)(param_1 >> 8);
  local_2 = (undefined1)param_1;
  DAT_0000475f = local_2;
  eeprom_save_dest();
  settings_defaults(0);
  DAT_00020f4b = 1;
  DAT_00020b39 = 0x11;
  return;
}


// ===== dest_jumper_apply @ fffb3ba6 (363 bytes)

/* JP_P51 strap: switch destination code between restricted/wide pairs */

void dest_jumper_apply(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar3 = dest_code_get();
  bVar2 = jp_p51_get();
  if ((uVar3 == 0x315b) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x50e2);
    return;
  }
  if ((uVar3 == 0x50e2) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x315b);
    return;
  }
  if ((uVar3 == 0xa983) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xb5a7);
    return;
  }
  if ((uVar3 == 0xb5a7) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xa983);
    return;
  }
  if ((uVar3 == 0xd950) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xa4c5);
    return;
  }
  if ((uVar3 == 0xa4c5) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xd950);
    return;
  }
  if ((uVar3 == 0xd32d) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x306f);
    return;
  }
  if ((uVar3 == 0x306f) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((uVar3 == 0x7753) && (bVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(0x9cf7);
      return;
    }
    if ((uVar3 == 0x9cf7) && (bVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(0x7753);
      return;
    }
    return;
  }
  dest_code_set(0xd32d);
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
  bVar3 = ptt_source_get();
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


// ===== sw_reset @ fffb3e55 (21 bytes)

/* PRCR=0xA502, SWRR 0x800C2=0xA501: software reset (end of power-off) [inference] */

void sw_reset(void)

{
  DAT_000803fe = 0xa502;
  DAT_000800c2 = 0xa501;
  return;
}


// ===== wdt_kick @ fffb3e6a (5 bytes)

/* main_loop task 1 / power-off loop: R_IWDT_Restart */

void wdt_kick(void)

{
  iwdt_refresh();
  return;
}


// ===== FUN_fffb3e6f @ fffb3e6f (156 bytes)

undefined1 FUN_fffb3e6f(byte param_1)

{
  ushort uVar1;
  byte bStack_5;
  
  uVar1 = dest_code_get();
  if (uVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3ef4;
  }
  if (uVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3ef4;
  }
  if (uVar1 == 0x306f) {
LAB_fffb3edf:
    bStack_5 = 5;
  }
  else {
    if (uVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3ef4;
    }
    if (uVar1 != 0xd950) {
      if (uVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3ef4;
      }
      if (uVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3ef4;
      }
      if ((uVar1 == 0x7753) || (uVar1 == 0x9cf7)) {
        bStack_5 = 9;
        goto LAB_fffb3ef4;
      }
      if (uVar1 != 0xa4c5) {
        if (uVar1 != 0xd32d) {
          if (uVar1 == 0x4380) {
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
  return *(undefined1 *)((uint)param_1 + (uint)bStack_5 * 5 + -0x7eab9);
}


// ===== FUN_fffb3f0b @ fffb3f0b (156 bytes)

undefined1 FUN_fffb3f0b(byte param_1)

{
  ushort uVar1;
  byte bStack_5;
  
  uVar1 = dest_code_get();
  if (uVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3f90;
  }
  if (uVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3f90;
  }
  if (uVar1 == 0x306f) {
LAB_fffb3f7b:
    bStack_5 = 5;
  }
  else {
    if (uVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3f90;
    }
    if (uVar1 != 0xd950) {
      if (uVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3f90;
      }
      if (uVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3f90;
      }
      if ((uVar1 == 0x7753) || (uVar1 == 0x9cf7)) {
        bStack_5 = 9;
        goto LAB_fffb3f90;
      }
      if (uVar1 != 0xa4c5) {
        if (uVar1 != 0xd32d) {
          if (uVar1 == 0x4380) {
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
  return *(undefined1 *)((uint)param_1 + (uint)bStack_5 * 5 + -0x7ea87);
}


// ===== FUN_fffb3fa7 @ fffb3fa7 (187 bytes)

uint FUN_fffb3fa7(void)

{
  ushort uVar1;
  byte bStack_7;
  
  uVar1 = dest_code_get();
  if (uVar1 == 0x20b) {
    bStack_7 = 1;
  }
  else if (uVar1 == 0x1cb9) {
    bStack_7 = 8;
  }
  else if (uVar1 == 0x306f) {
    bStack_7 = 0xd;
  }
  else if (uVar1 == 0x315b) {
    bStack_7 = 3;
  }
  else if (uVar1 == 0xd950) {
    bStack_7 = 7;
  }
  else if (uVar1 == 0x50e2) {
    bStack_7 = 4;
  }
  else if (uVar1 == 0x60e6) {
    bStack_7 = 2;
  }
  else if (uVar1 == 0x7753) {
    bStack_7 = 9;
  }
  else if (uVar1 == 0x9cf7) {
    bStack_7 = 0xe;
  }
  else if (uVar1 == 0xa4c5) {
    bStack_7 = 0xc;
  }
  else if (uVar1 == 0xa983) {
    bStack_7 = 6;
  }
  else if (uVar1 == 0xb5a7) {
    bStack_7 = 0xb;
  }
  else if (uVar1 == 0xd32d) {
    bStack_7 = 5;
  }
  else if (uVar1 == 0x4380) {
    bStack_7 = 0;
  }
  else {
    bStack_7 = 10;
  }
  return (uint)(s_Japan_0001b3e4 + (uint)bStack_7 * 0xf);
}


// ===== FUN_fffb4062 @ fffb4062 (211 bytes)

byte FUN_fffb4062(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  byte bStack_f;
  
  uVar6 = vfo_freq(1,2);
  bVar3 = vfo_mode(1);
  cVar4 = FUN_fffb3371(uVar6);
  bVar2 = DAT_00009bfb;
  if ((bVar3 == 4) || (bVar3 == 5)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_f = DAT_00009bfb;
    uVar5 = dest_code_get();
    if (uVar5 == 0x60e6) {
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

uint FUN_fffb4135(uint param_1)

{
  uint uVar1;
  byte local_15;
  uint local_14;
  uint local_c;
  uint local_4;
  
  local_c = 0;
  local_14 = 10000000;
  local_4 = param_1;
  for (local_15 = 0; local_15 < 8; local_15 = local_15 + 1) {
    uVar1 = local_4;
    if (local_14 != 0) {
      uVar1 = local_4 / local_14;
    }
    local_c = uVar1 << (7 - local_15 & 7) * 4 | local_c;
    local_4 = local_4 - (uVar1 * local_14 & 0xff);
    local_14 = local_14 / 10;
  }
  return local_c;
}


// ===== FUN_fffb418a @ fffb418a (143 bytes)

undefined1 FUN_fffb418a(byte param_1)

{
  byte bVar1;
  undefined1 local_9;
  byte local_1;
  uint uVar2;
  
  local_1 = param_1;
  if (DAT_00009c5e != '\0') {
    local_1 = 1;
  }
  bVar1 = vfo_mode(local_1);
  uVar2 = (uint)bVar1;
  if (uVar2 == 0xe) {
LAB_fffb41fc:
    local_9 = DAT_00009bff;
  }
  else {
    if (uVar2 - 2 < 2) {
      return DAT_00009bfd;
    }
    if (uVar2 - 4 < 2) {
      return DAT_00009c00;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 - 8 < 2) goto LAB_fffb41fc;
      if (1 < uVar2 - 10) {
        if (uVar2 - 0xc < 2) {
          return DAT_00009bfe;
        }
        if (1 < uVar2) {
          return 0;
        }
        return DAT_00009bfc;
      }
    }
    local_9 = uRam00009c01;
  }
  return local_9;
}


// ===== audio_route_state @ fffb4219 (734 bytes)

/* Returns 0..14: CW/RTTY RX 0, record 1/3, spot 2, playback 4/5, CW/RTTY TX 6/7, voice RX 8 (9-12
   variants), voice TX 13, playback TX 14 */

uint audio_route_state(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  byte bStack_b;
  uint uStack_8;
  
  cVar2 = DAT_00020b3d;
  bStack_b = vfo_mode(DAT_00020b6b);
  bVar9 = FUN_fffb2dfe();
  cVar8 = DAT_00020cd1;
  cVar7 = DAT_00020cd0;
  cVar6 = DAT_00020ccd;
  cVar5 = DAT_00020baf;
  cVar4 = DAT_00020b96;
  cVar3 = DAT_00020b7c;
  bVar10 = FUN_fffba192();
  if ((DAT_00020b96 == '\x01') || (DAT_00020b97 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_b = vfo_mode(0);
  }
  else {
    if ((cVar3 == '\0') && (cVar7 != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (cVar8 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (cVar6 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f1b == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bStack_b = vfo_mode(1);
    }
  }
  if ((bStack_b == 3) || (bStack_b == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bStack_b == 0xd)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bStack_b == 0xc)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (cVar2 != '\x01') {
      if ((DAT_00020f0b == '\x01') || (bVar9 == 4)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 2;
      }
      else if (cVar4 == '\x01') {
        uStack_8 = 1;
      }
      else if (cVar6 == '\x01') {
        uStack_8 = 3;
      }
      else {
        if ((cVar5 == '\x01') && (DAT_00020b97 == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_8 = 5;
        }
        else {
          if ((cVar5 == '\x01') || (cVar7 == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if ((bVar1) || (cVar8 == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            uStack_8 = 4;
          }
          else {
            uStack_8 = 0;
          }
        }
      }
    }
    else {
      if ((cVar5 == '\x01') || (cVar7 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (cVar8 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 7;
      }
      else {
        uStack_8 = 6;
      }
    }
  }
  else if (cVar2 != '\x01') {
    if ((bVar10 == 0) || (bVar9 != 4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_8 = 2;
    }
    else if (cVar4 == '\x01') {
      uStack_8 = 9;
    }
    else {
      if ((cVar3 == '\x02') || (DAT_00020f1b == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 10;
      }
      else {
        if ((cVar3 == '\x01') && (DAT_00020b97 == '\0')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_8 = 0xb;
        }
        else {
          if ((cVar5 == '\x01') && (DAT_00020b97 == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            uStack_8 = 0xc;
          }
          else {
            uStack_8 = 8;
          }
        }
      }
    }
  }
  else {
    if ((bVar10 == 3) && (bVar9 == 4)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uStack_8 = 6;
    }
    else {
      if ((cVar5 == '\x01') || (cVar3 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 0xe;
      }
      else {
        uStack_8 = 0xd;
      }
    }
  }
  return uStack_8;
}


// ===== key_event_filter @ fffb44f7 (1585 bytes)

/* Front-panel key event gate (key code, action): returns 1 if the key may run now; used by many CAT
   handlers */

byte key_event_filter(ushort param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  byte local_7;
  byte bStack_6;
  ushort local_2;
  
  bVar2 = param_2 >> 4;
  local_7 = 1;
  iVar6 = FUN_fffc4cc5(param_1,param_2);
  if ((iVar6 == 1) && (2 < param_1 - 0xff0)) {
    local_7 = 0;
  }
  bVar4 = param_2 & 0xf;
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
    if ((*(short *)(BYTE_ARRAY_fff88270 + (uint)bStack_6 * 2 + 0xa2) == 0x300) && (bVar4 == 2)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (!bVar3) {
      local_2 = *(ushort *)(BYTE_ARRAY_fff88270 + (uint)bStack_6 * 2 + 0xa2);
    }
  }
  if ((local_2 == 0x300) && (bVar4 == 2)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    DAT_00020b30 = 2;
    local_7 = 0;
  }
  if (DAT_00020bbe == '\x01') {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if ((local_2 < 8) || (local_2 - 0x16 < 4)) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if (DAT_00020b8a == '\x01') {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
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
          if (bVar4 == 1) {
            beep_request(3);
          }
          local_7 = 0;
        }
      }
    }
    return local_7;
  }
  if (DAT_00020b98 != '\0') {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      if ((local_2 < 0x200) || (0x288 < local_2)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if ((((!bVar3) && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) && (uVar1 != 0xe6)) &&
         (((0xe < uVar1 - 0x300 && (1 < uVar1 - 0x310)) && ((uVar1 != 0x340 && (1 < uVar1 - 0xff0)))
          ))) {
        if (bVar4 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if ((DAT_00020b7c == '\x02') && ((local_2 - 0x87 < 5 || (local_2 - 0x8d < 4)))) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((((DAT_00020b97 != '\0') && (uVar1 = (uint)local_2, uVar1 != 0xe8)) && (1 < uVar1 - 0xfe)) &&
     (((0xb < uVar1 - 0x110 && (uVar1 != 0xff1)) && ((uVar1 != 0x30c && (uVar1 != 0x30f)))))) {
    if (uVar1 == 0x300) {
      local_7 = 0;
    }
    else {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if (((DAT_00020baf == '\x01') && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) &&
     ((4 < uVar1 - 0x110 &&
      ((((uVar1 != 0x119 && (uVar1 != 0x302)) && (uVar1 != 0x340)) && (uVar1 != 0xff1)))))) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if (DAT_00020b3d != '\0') {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
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
        if (bVar4 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if (DAT_00020f11 != '\0') {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
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
              if (bVar4 == 1) {
                beep_request(3);
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
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((((2 < uVar1 - 0x300) && (uVar1 != 0x340)) && (uVar1 != 0x348)) &&
         ((uVar1 != 0x34e && (uVar1 != 0xff0)))) {
        if (bVar4 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if (DAT_00020b74 != '\0') {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if (local_2 == 0x14) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if ((local_2 == 0x302) || (local_2 == 0x340)) {
      DAT_00020b74 = '\0';
    }
  }
  bVar5 = vfo_tune_locked('\x02');
  if (bVar5 == 1) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if (local_2 - 0x12 < 3) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if ((DAT_00020b9b == '\x01') && (local_2 == 0xff1)) {
    local_7 = 0;
  }
  if ((DAT_00020f1b == '\x01') && (local_2 == 0x30e)) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((DAT_00020ccd == '\x01') && (local_2 == 0x30e)) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((DAT_00009c5e != '\0') && (local_2 == 0x306)) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((DAT_00009c62 == '\0') || (DAT_00020b97 != '\0')) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if ((bVar3) && (local_2 == 0xff0)) {
    FUN_fffc8cbb(0x47);
    FUN_fffc8d8c();
    DAT_00020cc6 = 0x47;
    local_7 = 0;
  }
  if (((DAT_00020f0b != '\0') && (local_2 != 0x340)) && (2 < local_2 - 0xff0)) {
    DAT_00020f0b = '\0';
    beep_stop();
  }
  if ((bVar4 == 0) && (2 < local_2 - 0xff0)) {
    local_7 = 1;
  }
  if ((DAT_00020b8c == '\x01') || (DAT_00020b9e == '\x01')) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((bVar3) && ((local_2 == 0x302 || (local_2 == 0x340)))) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  return local_7;
}


// ===== supply_undervolt_check @ fffb4b28 (146 bytes)

/* AN003 < 0x7DD -> power_off_io, save, shutdown request 0x20B39=0x90 */

char supply_undervolt_check(void)

{
  byte bVar1;
  
  if ((DAT_00020b43 != '\x01') && (DAT_00020b08 < 0x7dd)) {
    bVar1 = swtimer_expired(0x13);
    DAT_00020b43 = '\x01';
    if (bVar1 == 1) {
      power_off_io();
      DAT_00009dc5 = 1;
      FUN_fffd3d03();
      eeprom_save_opstate();
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


// ===== vfo_tune_locked @ fffb4bba (139 bytes)

/* 1 if side is in state 7/8 or on 5 MHz/EMG memory (ch 117..132) */

byte vfo_tune_locked(char param_1)

{
  bool bVar1;
  byte local_5;
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


// ===== vfo_display_offset @ fffb4c45 (467 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4d66) */
/* WARNING: Removing unreachable block (ram,0xfffb4c6a) */
/* WARNING: Removing unreachable block (ram,0xfffb4dfd) */
/* WARNING: Removing unreachable block (ram,0xfffb4cbe) */
/* WARNING: Removing unreachable block (ram,0xfffb4d3b) */
/* WARNING: Removing unreachable block (ram,0xfffb4d06) */
/* Mode-dependent signed offset added to dial freq (0x20F5C); 0 if setting 0x9B15 != 0 */

ushort vfo_display_offset(void)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  byte *pbVar4;
  ushort uStack_e;
  ushort uStack_a;
  
  pbVar4 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uStack_e = 0;
  if (DAT_00009b15 == '\0') {
    uVar1 = (uint)bVar2;
    if (uVar1 == 0xe) {
      uStack_e = CONCAT11(pbVar4[0x30],pbVar4[0x31]);
    }
    else if (uVar1 - 2 < 2) {
      uStack_a = CONCAT11(pbVar4[0x1c],pbVar4[0x1d]);
      if (bVar2 == 2) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 8 < 2) {
      uStack_a = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 + CONCAT11(pbVar4[0x30],pbVar4[0x31]);
      if (bVar2 == 8) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 0xc < 2) {
      uStack_a = (ushort)pbVar4[0x27];
      sVar3 = CONCAT11(pbVar4[0x26],pbVar4[0x27]);
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
      uStack_a = CONCAT11(pbVar4[0x12],pbVar4[0x13]);
      if ((pbVar4[0x12] & 0x80) != 0) {
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


// ===== bandmem_set @ fffb4e18 (166 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4e89) */
/* WARNING: Removing unreachable block (ram,0xfffb4e33) */
/* WARNING: Removing unreachable block (ram,0xfffb4e52) */
/* (kind, f): kind 1 -> 0x9C69[band] (scope CURSOR start), 2 -> 0x9C99[band] / 0x9CC9[GEN sub] (FIX
   start) */

void bandmem_set(char param_1,uint param_2)

{
  byte bVar1;
  uint freq;
  undefined1 *puStack_10;
  byte bStack_b;
  
  freq = vfo_freq_clar(0,2);
  bVar1 = band_of_freq(freq);
  if (param_1 == '\x02') {
    puStack_10 = &DAT_00009c99 + (uint)bVar1 * 4;
    if (bVar1 == 0xb) {
      bVar1 = gen_subband_of_freq(param_2);
      for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
        *(char *)((uint)bStack_b + (uint)bVar1 * 4 + 0x9cc9) =
             (char)(param_2 >> ((3 - bStack_b & 3) << 3));
      }
    }
  }
  else {
    puStack_10 = (undefined1 *)((uint)bVar1 * 4 + 0x9c69);
  }
  for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
    puStack_10[bStack_b] = (char)(param_2 >> ((3 - bStack_b & 3) << 3));
  }
  return;
}


// ===== bandmem_get @ fffb4ebe (148 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4edb) */
/* WARNING: Removing unreachable block (ram,0xfffb4f17) */
/* WARNING: Removing unreachable block (ram,0xfffb4f03) */
/* (kind): read band memory of the band containing the active frequency */

uint bandmem_get(char param_1)

{
  byte bVar1;
  uint freq;
  undefined1 *puStack_14;
  byte bStack_e;
  byte bStack_d;
  uint uStack_c;
  
  freq = vfo_freq(0,2);
  bVar1 = band_of_freq(freq);
  if (param_1 == '\x02') {
    puStack_14 = &DAT_00009c99 + (uint)bVar1 * 4;
    if (bVar1 == 0xb) {
      bStack_d = gen_subband_of_freq(freq);
      if (0xf < bStack_d) {
        bStack_d = 0xf;
      }
      puStack_14 = (undefined1 *)((uint)bStack_d * 4 + 0x9cc9);
    }
  }
  else {
    puStack_14 = (undefined1 *)((uint)bVar1 * 4 + 0x9c69);
  }
  uStack_c = 0;
  for (bStack_e = 0; bStack_e < 4; bStack_e = bStack_e + 1) {
    uStack_c = (uint)(byte)puStack_14[bStack_e] | uStack_c << 8;
  }
  return uStack_c;
}


// ===== tx_freq_repeater_shift @ fffb4f52 (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5062) */
/* FM/DATA-FM repeater shift (rec+2 bits2-3) on 28/50 MHz, x10 kHz settings */

uint tx_freq_repeater_shift(uint param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  byte *pbVar6;
  uint uStack_14;
  uint local_4;
  uint uVar7;
  
  pbVar6 = vfo_rec_ptr(1);
  bVar4 = pbVar6[2] >> 2 & 3;
  bVar3 = false;
  bVar2 = false;
  bVar5 = vfo_mode(1);
  uVar7 = (uint)bVar5;
  if ((uVar7 - 6 < 2) || (uVar7 == 10 || uVar7 == 0xb)) {
    if ((param_1 < 28000000) || (29999999 < param_1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar4 == 2) {
      uStack_14 = param_1 + (uint)DAT_00009a62 * 10000;
    }
    else {
      uStack_14 = param_1;
      if (bVar4 == 0) {
        uStack_14 = param_1 + (uint)DAT_00009a62 * -10000;
      }
    }
    if ((uStack_14 < 28000000) || (29999999 < uStack_14)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if ((bVar2) || (bVar3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if ((param_1 < 50000000) || (53999999 < param_1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bVar2 = true;
      }
      if (bVar4 == 2) {
        uStack_14 = param_1 + (uint)CONCAT11(DAT_00009a63,DAT_00009a64) * 10000;
      }
      else {
        uStack_14 = param_1;
        if (bVar4 == 0) {
          uStack_14 = param_1 + (uint)CONCAT11(DAT_00009a63,DAT_00009a64) * -10000;
        }
      }
      if ((uStack_14 < 50000000) || (53999999 < uStack_14)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bVar3 = true;
      }
    }
  }
  if ((bVar2) || (bVar3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_4 = param_1;
  if (bVar2) {
    local_4 = uStack_14;
  }
  return local_4;
}


// ===== FUN_fffb50d7 @ fffb50d7 (323 bytes)

undefined1 FUN_fffb50d7(byte param_1)

{
  uint uVar1;
  undefined1 local_3;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0xe) {
LAB_fffb51ed:
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a77;
    }
    else {
      local_3 = DAT_00020b68;
    }
  }
  else {
    if (uVar1 - 2 < 2) {
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b68;
      }
      return DAT_00009a9d;
    }
    if (uVar1 - 4 < 2) {
      if (DAT_00009dc6 != '\0') {
        return DAT_00020b68;
      }
      return DAT_00009a4f;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb51ed;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (DAT_00009dc6 != '\0') {
            return DAT_00020b68;
          }
          return DAT_00009a8a;
        }
        if (1 < uVar1) {
          return 0;
        }
        if (DAT_00009dc6 != '\0') {
          return DAT_00020b68;
        }
        return DAT_00009a3a;
      }
    }
    if (DAT_00009dc6 == '\0') {
      local_3 = DAT_00009a61;
    }
    else {
      local_3 = DAT_00020b68;
    }
  }
  return local_3;
}

