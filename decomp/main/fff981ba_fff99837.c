// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff981ba @ fff981ba (158 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9820f) */
/* WARNING: Removing unreachable block (ram,0xfff981d4) */
/* WARNING: Removing unreachable block (ram,0xfff981df) */

void FUN_fff981ba(char param_1,int param_2,char param_3,uint param_4)

{
  bool bVar1;
  byte bVar2;
  byte bStack_19;
  uint uStack_14;
  
  dest_code_get();
  uStack_14 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                         *(undefined1 *)(param_2 + 0x4b)),
                                *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d));
  if ((param_3 == '\x01') || (param_3 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uStack_14 = uStack_14 +
                (int)CONCAT11(*(undefined1 *)(param_2 + 0x48),*(undefined1 *)(param_2 + 0x49));
  }
  bVar2 = vfo_tune_locked(param_1);
  if (bVar2 == 1) {
    if (param_1 == '\0') {
      bStack_19 = DAT_000060c9;
    }
    else {
      bStack_19 = DAT_000060ca;
    }
    uStack_14 = FUN_fff9cba4(uStack_14,bStack_19);
  }
  FUN_fff9ca42(uStack_14,param_4);
  return;
}


// ===== FUN_fff98258 @ fff98258 (82 bytes)

void FUN_fff98258(char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bStack_15;
  uint local_14;
  
  local_14 = *(uint *)(PTR_DAT_00025d38 + 0x44c);
  bVar1 = vfo_tune_locked(param_1);
  if (bVar1 == 1) {
    if (param_1 == '\0') {
      bStack_15 = DAT_000060c9;
    }
    else {
      bStack_15 = DAT_000060ca;
    }
    local_14 = FUN_fff9cba4(local_14,bStack_15);
  }
  FUN_fff9ca42(local_14,param_4);
  return;
}


// ===== FUN_fff982aa @ fff982aa (17 bytes)

void FUN_fff982aa(byte param_1,uint param_2,uint param_3)

{
  FUN_fff982bb(param_1,param_2);
  return;
}


// ===== FUN_fff982bb @ fff982bb (72 bytes)

void FUN_fff982bb(char param_1,undefined4 param_2)

{
  if (param_1 == DAT_00009dbd) {
    FUN_fff98303(param_1,param_2);
    return;
  }
  if (PTR_DAT_00025d38[0x41d] != '\x01') {
    FUN_fff98303(param_1,param_2);
    return;
  }
  FUN_fff98363(param_1,PTR_DAT_00025d38 + 0x40f,param_2);
  return;
}


// ===== FUN_fff98303 @ fff98303 (96 bytes)

void FUN_fff98303(char param_1,undefined4 param_2)

{
  undefined1 auStack_d [5];
  undefined4 local_8;
  char local_1;
  
  local_8 = param_2;
  local_1 = param_1;
  if (PTR_DAT_00025d38[0x40d] == '\0') {
    FUN_fff9810e(param_1,(uint)auStack_d);
    FUN_fff98363(local_1,auStack_d,local_8);
    return;
  }
  if (param_1 == PTR_DAT_00025d38[0x40e]) {
    FUN_fff98363(param_1,PTR_DAT_00025d38 + 0x40f,param_2);
    return;
  }
  FUN_fff9810e(param_1,(uint)auStack_d);
  FUN_fff98363(local_1,auStack_d,local_8);
  return;
}


// ===== FUN_fff98363 @ fff98363 (283 bytes)

void FUN_fff98363(char param_1,byte *param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  byte bStack_d;
  
  if (param_1 == DAT_00009dbd) {
    iVar2 = FUN_fff9847e();
    if (iVar2 == 1) {
      if (PTR_DAT_00025d38[0x416] == '\x01') {
        bVar1 = (*param_2 & 0xf) != 0;
        if (bVar1) {
          bStack_d = *param_2 | 0xf0;
        }
        else {
          bStack_d = 0xff;
        }
        *param_3 = bStack_d;
        if ((param_2[1] & 0xf0) == 0) {
          bStack_d = param_2[1];
          if (!bVar1) {
            if ((bStack_d & 0xf) == 0) {
              bStack_d = 0xff;
            }
            else {
              bStack_d = param_2[1] | 0xf0;
            }
          }
        }
        else {
          bStack_d = param_2[1];
        }
        param_3[1] = bStack_d;
        param_3[2] = 0xff;
        param_3[3] = param_2[3] | 0xf0;
      }
      else {
        *param_3 = 0xff;
        param_3[1] = 0xff;
        param_3[2] = param_2[2];
        param_3[3] = param_2[3];
      }
    }
    else {
      *param_3 = *param_2;
      param_3[1] = param_2[1];
      param_3[2] = param_2[2];
      param_3[3] = param_2[3];
    }
    param_3[4] = param_2[4];
    return;
  }
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  param_3[3] = param_2[3];
  param_3[4] = param_2[4];
  return;
}


// ===== FUN_fff9847e @ fff9847e (32 bytes)

bool FUN_fff9847e(void)

{
  return PTR_DAT_00025d38[0x423] != '\0';
}


// ===== FUN_fff9849e @ fff9849e (136 bytes)

byte FUN_fff9849e(void)

{
  byte local_2;
  
  if (PTR_DAT_00025d38[0x67] == '\0') {
    local_2 = meter_get_s();
  }
  else if (DAT_00009c5b == '\x05') {
    if (DAT_00020b41 == '\x02') {
      local_2 = meter_get_swr_raw();
    }
    else {
      local_2 = meter_get_swr();
    }
  }
  else if (DAT_00009c5b == '\x01') {
    local_2 = meter_get_comp();
  }
  else if (DAT_00009c5b == '\x02') {
    local_2 = meter_get_alc();
  }
  else if (DAT_00009c5b == '\x03') {
    local_2 = meter_get_vdd();
  }
  else if (DAT_00009c5b == '\x04') {
    local_2 = meter_get_idd();
  }
  else if (DAT_00009c5b == '\0') {
    local_2 = meter_get_po();
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff98526 @ fff98526 (64 bytes)

byte FUN_fff98526(int param_1)

{
  undefined1 local_6;
  
  local_6 = 0;
  if ((*(byte *)(param_1 + 6) & 0x10) != 0) {
    local_6 = 0x10;
  }
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    local_6 = local_6 | 8;
  }
  if (DAT_00009c62 == '\x01') {
    local_6 = local_6 | 4;
  }
  return DAT_00009c61 | local_6;
}


// ===== disp_put_op_freq @ fff98566 (95 bytes)

/* DISPLAY frame +0x1715: operating frequency */

void disp_put_op_freq(void *param_1)

{
  undefined4 local_8;
  
  if (PTR_DAT_00025d38[0x67] == '\x01') {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x458);
  }
  else if (DAT_00009dbd == '\0') {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x450);
  }
  else {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x454);
  }
  *(char *)param_1 = (char)((uint)local_8 >> 0x18);
  *(char *)((int)param_1 + 1) = (char)((uint)local_8 >> 0x10);
  *(char *)((int)param_1 + 2) = (char)((uint)local_8 >> 8);
  *(undefined1 *)((int)param_1 + 3) = (undefined1)local_8;
  return;
}


// ===== disp_put_tx_freq @ fff985c5 (48 bytes)

/* DISPLAY frame +0x1719: TX frequency 0x20F50 */

void disp_put_tx_freq(void *param_1)

{
  undefined4 uVar1;
  undefined1 local_8;
  
  uVar1 = *(undefined4 *)(PTR_DAT_00025d38 + 0x44c);
  *(char *)param_1 = (char)((uint)uVar1 >> 0x18);
  *(char *)((int)param_1 + 1) = (char)((uint)uVar1 >> 0x10);
  *(char *)((int)param_1 + 2) = (char)((uint)uVar1 >> 8);
  local_8 = (undefined1)uVar1;
  *(undefined1 *)((int)param_1 + 3) = local_8;
  return;
}


// ===== disp_put_dial_freq @ fff985f5 (116 bytes)

/* DISPLAY frame +0x171D: dial frequency */

void disp_put_dial_freq(void *param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (PTR_DAT_00025d38[0x67] == '\x01') {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x44c);
  }
  else {
    iVar1 = FUN_fff98669();
    if (iVar1 == 0) {
      local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x458);
    }
    else if (DAT_00009dbd == '\0') {
      local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x450);
    }
    else {
      local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x454);
    }
  }
  *(char *)param_1 = (char)((uint)local_8 >> 0x18);
  *(char *)((int)param_1 + 1) = (char)((uint)local_8 >> 0x10);
  *(char *)((int)param_1 + 2) = (char)((uint)local_8 >> 8);
  *(undefined1 *)((int)param_1 + 3) = (undefined1)local_8;
  return;
}


// ===== FUN_fff98669 @ fff98669 (40 bytes)

undefined1 FUN_fff98669(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d38[0x67] == '\x01') {
    local_2 = 1;
  }
  else {
    local_2 = DAT_00009b15;
  }
  return local_2;
}


// ===== disp_put_scope_start @ fff98691 (79 bytes)

/* DISPLAY frame +0x1721: scope start (0x20F60 or FIX band memory) */

void disp_put_scope_start(int param_1)

{
  byte local_a;
  uint local_8;
  
  if (DAT_00009c35 == '\x02') {
    local_8 = bandmem_get('\x02');
  }
  else {
    local_8 = DAT_00020f60;
  }
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    *(char *)((uint)local_a + param_1) = (char)(local_8 >> ((3 - local_a & 3) << 3));
  }
  return;
}


// ===== displink_tx_64 @ fff986e0 (71 bytes)

/* 0x64 (3 bytes): +0xB8 when changed */

void displink_tx_64(void)

{
  if (PTR_DAT_00025d38[0xb8] == PTR_DAT_00025d38[0xb9]) {
    return;
  }
  PTR_DAT_00025d38[0xb9] = PTR_DAT_00025d38[0xb8];
  DAT_00001456 = 100;
  DAT_00001457 = PTR_DAT_00025d38[0xb8];
  DAT_0001b628 = 3;
  displink_tx_start(3);
  return;
}


// ===== FUN_fff98727 @ fff98727 (112 bytes)

void FUN_fff98727(char param_1,char param_2)

{
  byte local_3;
  
  if (param_1 == '\b') {
    local_3 = 0x20;
  }
  else if (param_1 == '\x02') {
    local_3 = 0x40;
  }
  else if (param_1 == '\x03') {
    local_3 = 0x10;
  }
  else if (param_1 == '\x04') {
    local_3 = 8;
  }
  else if (param_1 == '\x05') {
    local_3 = 4;
  }
  else if (param_1 == '\x06') {
    local_3 = 2;
  }
  else if (param_1 == '\a') {
    local_3 = 1;
  }
  else {
    if (param_1 != '\x01') {
      return;
    }
    local_3 = 0x80;
  }
  if (param_2 != '\0') {
    PTR_DAT_00025d38[0x34] = local_3 | PTR_DAT_00025d38[0x34];
    return;
  }
  PTR_DAT_00025d38[0x34] = ~local_3 & PTR_DAT_00025d38[0x34];
  return;
}


// ===== power_down_save @ fff98797 (210 bytes)

/* Restart/power-off request: notifies DISPLAY; code 0x90 waits 2 s, else eeprom_save_all (0x9DC5=1
   if code 0x11); then mcu_software_reset */

void power_down_save(void)

{
  byte bVar1;
  
  DAT_00001456 = 0x7f;
  DAT_00001457 = PTR_DAT_00025d38[0x35] & 0x7f;
  DAT_00001458 = 0x9b;
  DAT_00001459 = 0xba;
  DAT_0000145a = 0xf6;
  DAT_0000145b = 0x38;
  DAT_0000145c = 0xff;
  DAT_0000145d = 0x25;
  DAT_0000145e = 0x73;
  DAT_0000145f = 0x1f;
  DAT_0001b628 = 0xb;
  displink_tx_start(0xb);
  if (PTR_DAT_00025d38[0x35] == -0x70) {
    swtimer_start(0x14,2000);
    do {
      bVar1 = swtimer_expired(0x14);
    } while (bVar1 == 0);
  }
  else if (PTR_DAT_00025d38[0x35] == '\x11') {
    DAT_00009dc5 = 1;
    eeprom_save_all();
  }
  else {
    DAT_00009dc5 = 0;
    eeprom_save_all();
  }
  sw_reset();
  return;
}


// ===== displink_tx_7C @ fff98869 (51 bytes)

/* 0x7C (5 bytes) */

void displink_tx_7C(void)

{
  DAT_00001456 = 0x7c;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_7B @ fff9889c (86 bytes)

/* 0x7B (5 bytes), toggles +0x82 */

void displink_tx_7B(void)

{
  char cVar1;
  
  DAT_00001456 = 0x7b;
  cVar1 = PTR_DAT_00025d38[0x82];
  if (cVar1 == '\x01') {
    PTR_DAT_00025d38[0x82] = 0;
  }
  else {
    PTR_DAT_00025d38[0x82] = 1;
  }
  DAT_00001457 = cVar1 != '\x01';
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_7A @ fff988f2 (51 bytes)

/* 0x7A (5 bytes) */

void displink_tx_7A(void)

{
  DAT_00001456 = 0x7a;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_70 @ fff98925 (42 bytes)

/* 0x70 (0xE3 bytes) */

void displink_tx_70(void)

{
  byte bVar1;
  
  displink_build_70();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0xe2);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xe3;
  displink_tx_start(0xe3);
  return;
}


// ===== displink_build_70 @ fff9894f (638 bytes)

void displink_build_70(void)

{
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x70;
  FUN_fff98cd3();
  switch(PTR_DAT_00025d38[0xbb]) {
  case 0:
    FUN_fff98cec(0xfff80000);
    return;
  case 1:
    DAT_000017d9 = 3;
    DAT_000017da = 2;
    DAT_000017db = PTR_DAT_00025d38[0xbd];
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    smovf(0x17e1,0xfff80016,0x16);
    return;
  case 2:
    FUN_fff98d5b(0xfff8002c);
    return;
  case 3:
    FUN_fff98dca(0xfff80058);
    return;
  case 4:
    FUN_fff98dca(0xfff8006e);
    return;
  case 5:
    FUN_fff98d5b(0xfff80084);
    return;
  case 6:
    FUN_fff98dca(0xfff800b0);
    return;
  case 7:
    DAT_000017d9 = 3;
    DAT_000017da = 0;
    DAT_000017db = PTR_DAT_00025d38[0xbd];
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    smovf(0x17e1,0xfff800c6,0x16);
    return;
  case 8:
    FUN_fff98dca(0xfff800dc);
    return;
  case 9:
    DAT_000017d9 = 3;
    DAT_000017da = 0;
    DAT_000017db = PTR_DAT_00025d38[0xbd];
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    smovf(0x17e1,0xfff800f2,0x16);
    return;
  case 10:
    FUN_fff98dca(0xfff80108);
    return;
  case 0xb:
    FUN_fff98dca(0xfff8011e);
    return;
  case 0xc:
    FUN_fff98dca(0xfff80134);
    return;
  case 0xd:
    FUN_fff98dca(0xfff8014a);
    return;
  case 0xe:
    FUN_fff98cec(0xfff80160);
    return;
  case 0xf:
    FUN_fff98dca(0xfff80176);
    return;
  case 0x10:
    FUN_fff98dca(0xfff8018c);
    return;
  case 0x11:
    FUN_fff98dca(0xfff801a2);
    return;
  case 0x12:
    FUN_fff98dca(0xfff801b8);
    return;
  case 0x13:
    FUN_fff98dca(0xfff801ce);
    return;
  case 0x14:
    FUN_fff98dca(0xfff801e4);
    return;
  case 0x15:
    FUN_fff98dca(0xfff801fa);
    return;
  case 0x16:
    FUN_fff98dca(0xfff80210);
    return;
  case 0x17:
    FUN_fff98cec(0xfff80252);
    return;
  case 0x18:
    FUN_fff98dca(0xfff80176);
    return;
  case 0x19:
    FUN_fff98dca(0xfff80226);
    return;
  case 0x1a:
    FUN_fff98dca(0xfff8023c);
    return;
  default:
    return;
  }
}


// ===== displink_tx_req @ fff98bcd (82 bytes)

/* 0x43/0x44/0x45 request, type +0x1E0, length +0x1E2 */

void displink_tx_req(void)

{
  byte bVar1;
  
  PTR_DAT_00025d38[0x87] = 0;
  displink_build_req();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,*(short *)(PTR_DAT_00025d38 + 0x1e2) - 1);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = *(undefined2 *)(PTR_DAT_00025d38 + 0x1e2);
  displink_tx_start(*(ushort *)(PTR_DAT_00025d38 + 0x1e2));
  return;
}


// ===== displink_build_req @ fff98c1f (86 bytes)

void displink_build_req(void)

{
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = PTR_DAT_00025d38[0x1e0];
  DAT_00001742 = PTR_DAT_00025d38[0x1e4];
  if ((PTR_DAT_00025d38[0x1e4] & 0xf0) == 0) {
    return;
  }
  FUN_fff98c75(2);
  return;
}


// ===== FUN_fff98c75 @ fff98c75 (94 bytes)

undefined1 * FUN_fff98c75(undefined1 *param_1)

{
  uint uVar1;
  
  uVar1 = (byte)PTR_DAT_00025d38[0x1e4] - 1 & 0xf;
  if ((1 < uVar1 - 6) && (uVar1 != 4)) {
    if (uVar1 < 4) {
      smovf(&DAT_00001741 + ((uint)param_1 & 0xffff),PTR_DAT_00025d38 + 0x1e5,
            *(ushort *)(PTR_DAT_00025d38 + 0x1e2) - 1);
      return &DAT_00001741 + ((uint)param_1 & 0xffff) + (*(ushort *)(PTR_DAT_00025d38 + 0x1e2) - 1);
    }
    return param_1;
  }
  *(undefined4 *)(&DAT_00001741 + ((uint)param_1 & 0xffff)) =
       *(undefined4 *)(PTR_DAT_00025d38 + 0x1e5);
  return param_1;
}


// ===== FUN_fff98cd3 @ fff98cd3 (25 bytes)

undefined1 * FUN_fff98cd3(void)

{
  displink_build_status();
  smovf(0x1742,0x16a1,0x97);
  return &DAT_000017d9;
}


// ===== FUN_fff98cec @ fff98cec (111 bytes)

undefined1 * FUN_fff98cec(undefined4 param_1)

{
  DAT_000017d9 = 3;
  DAT_000017da = 0;
  DAT_000017db = PTR_DAT_00025d38[0xbd];
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  smovf(0x17e1,param_1,0x16);
  return &DAT_000017f7;
}


// ===== FUN_fff98d5b @ fff98d5b (111 bytes)

undefined4 FUN_fff98d5b(undefined4 param_1)

{
  DAT_000017d9 = 1;
  DAT_000017da = 4;
  DAT_000017db = PTR_DAT_00025d38[0xbd];
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  smovf(0x17e1,param_1,0x2c);
  return 0x180d;
}


// ===== FUN_fff98dca @ fff98dca (111 bytes)

undefined1 * FUN_fff98dca(undefined4 param_1)

{
  DAT_000017d9 = 3;
  DAT_000017da = 4;
  DAT_000017db = PTR_DAT_00025d38[0xbd];
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  smovf(0x17e1,param_1,0x16);
  return &DAT_000017f7;
}


// ===== displink_tx_23 @ fff98e39 (31 bytes)

/* 0x23 (0x37 bytes) */

void displink_tx_23(void)

{
  PTR_DAT_00025d38[0x89] = 0;
  displink_build_23();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== FUN_fff98e58 @ fff98e58 (31 bytes)

void FUN_fff98e58(void)

{
  PTR_DAT_00025d38[0x8a] = 0;
  FUN_fff98ec9();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== FUN_fff98e77 @ fff98e77 (31 bytes)

void FUN_fff98e77(void)

{
  PTR_DAT_00025d38[0x8b] = 0;
  FUN_fff98eca();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== displink_build_23 @ fff98e96 (51 bytes)

void displink_build_23(void)

{
  DAT_00001456 = 0x23;
  DAT_00001457 = (char)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x1be) >> 8) + '\x01';
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  return;
}


// ===== FUN_fff98ec9 @ fff98ec9 (1 bytes)

void FUN_fff98ec9(void)

{
  return;
}


// ===== FUN_fff98eca @ fff98eca (1 bytes)

void FUN_fff98eca(void)

{
  return;
}


// ===== displink_tx_30_31 @ fff98ecb (177 bytes)

/* 0x30 (0xA0) or 0x31 (0xA3) by +0x1C2 */

void displink_tx_30_31(void)

{
  bool bVar1;
  byte bVar2;
  
  PTR_DAT_00025d38[0x8c] = 0;
  PTR_DAT_00025d38[0x1c0] = 0;
  if ((PTR_DAT_00025d38[0x1c2] == -1) || ((byte)PTR_DAT_00025d38[0x1c2] < 0x1e)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    displink_build_30();
    bVar2 = displink_copy_if_changed(0x1741,0x1456,0x9f);
    if (bVar2 == 1) {
      DAT_0001b628 = 0xa0;
      displink_tx_start(0xa0);
      return;
    }
  }
  else if ((byte)PTR_DAT_00025d38[0x1c2] < 0x5f) {
    displink_build_31();
    bVar2 = displink_copy_if_changed(0x1741,0x1456,0xa2);
    if (bVar2 == 1) {
      DAT_0001b628 = 0xa3;
      displink_tx_start(0xa3);
      return;
    }
  }
  return;
}


// ===== displink_tx_34 @ fff98f7c (53 bytes)

/* 0x34 (0xA3 bytes) */

void displink_tx_34(void)

{
  displink_build_34(1,DAT_0001b3d6);
  DAT_0001b628 = 0xa3;
  displink_tx_start(0xa3);
  PTR_DAT_00025d38[0x99] = 0;
  PTR_DAT_00025d38[0x9a] = 1;
  return;
}


// ===== displink_build_30 @ fff98fb1 (622 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99181) */
/* WARNING: Removing unreachable block (ram,0xfff9917b) */

void displink_build_30(void)

{
  byte bVar1;
  int iVar2;
  bool bStack_9;
  byte *pbStack_8;
  char cStack_1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x30;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x1c2];
  if (PTR_DAT_00025d38[0x1c2] != -1) {
    if (DAT_00009dbd == '\0') {
      pbStack_8 = &DAT_00009d09;
    }
    else {
      pbStack_8 = &DAT_00009d63;
    }
    bStack_9 = DAT_00009dbd != '\0';
    switch(PTR_DAT_00025d38[0x1c2]) {
    case 0:
      DAT_000017da = DAT_00009c5b;
      return;
    case 1:
      DAT_000017da = pbStack_8[3] & 3;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 2:
      if ((pbStack_8[5] & 3) == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = (pbStack_8[5] & 3) - 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 3:
      bVar1 = FUN_fff9921f(pbStack_8);
      DAT_000017da = bVar1 >> 7;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 4:
      bVar1 = FUN_fff9921f(pbStack_8);
      if ((bVar1 & 0x40) == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = (bVar1 >> 4 & 3) + 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 5:
      DAT_000017da = *pbStack_8 & 0xf;
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 6:
      DAT_000017da = scope_span_index(bStack_9);
      return;
    case 7:
    case 8:
      DAT_000017da = 0;
      return;
    case 9:
      DAT_000017da = DAT_00009c39;
      return;
    case 10:
      DAT_000017da = DAT_00009c3a << 6 | DAT_00009c3b << 4 | DAT_00009c3c;
      return;
    case 0xb:
      DAT_000017da = DAT_00009be8;
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 0xc:
      DAT_000017da = PTR_DAT_00025d38[0x1dc];
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 0xd:
      iVar2 = FUN_fffc4f8f();
      if (iVar2 == 0) {
        DAT_000017da = DAT_00009c5a;
        return;
      }
      DAT_000017da = 5;
      return;
    }
  }
  return;
}


// ===== FUN_fff9921f @ fff9921f (120 bytes)

byte FUN_fff9921f(byte *param_1)

{
  uint uVar1;
  byte local_7;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 == 0xe) {
LAB_fff99289:
    local_7 = param_1[0x29];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x15];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x33];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff99289;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1f];
        }
        if (1 < uVar1) {
          return 0;
        }
        return param_1[0xb];
      }
    }
    local_7 = param_1[0x3d];
  }
  return local_7;
}


// ===== displink_build_31 @ fff99297 (478 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void displink_build_31(void)

{
  char cVar1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x31;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x1c2] + -0x1e;
  DAT_000017e2 = 0x20;
  _DAT_000017de = 0x20202020;
  _DAT_000017da = 0x20202020;
  cVar1 = PTR_DAT_00025d38[0x1c2];
  if (cVar1 == '^') {
    FUN_fff9a044(0x99);
    return;
  }
  if (cVar1 == '\x1f') {
    FUN_fff9959f(0x99);
    return;
  }
  if (cVar1 == '\"') {
    FUN_fff99e15(0x99);
    return;
  }
  if (cVar1 == '#') {
    FUN_fff9a00f(0x99);
    return;
  }
  if (cVar1 == '$') {
    FUN_fff99abf(0x99);
    return;
  }
  if (cVar1 == '%') {
    FUN_fff99837(0x99);
    return;
  }
  if (cVar1 == '&') {
    FUN_fff99ddb(0x99);
    return;
  }
  if (cVar1 == '\'') {
    FUN_fff997df(0x99);
    return;
  }
  if (cVar1 == '(') {
    FUN_fff99a8a(0x99);
    return;
  }
  if (cVar1 == ')') {
    FUN_fff996e2(0x99);
    return;
  }
  if (cVar1 == '*') {
    FUN_fff99717(0x99);
    return;
  }
  if (cVar1 == '+') {
    FUN_fff9978c(0x99);
    return;
  }
  if (cVar1 == ',') {
    FUN_fff995cc(0x99);
    return;
  }
  if (cVar1 == '-') {
    FUN_fff9960e(0x99);
    return;
  }
  if (cVar1 == '/') {
    FUN_fff99d82(0x99);
    return;
  }
  if (cVar1 == '0') {
    FUN_fff998e2(0x99);
    return;
  }
  if (cVar1 == '1') {
    FUN_fff9992a(0x99);
    return;
  }
  if (cVar1 == '2') {
    FUN_fff99989(0x99);
    return;
  }
  if (cVar1 == '3') {
    FUN_fff999e3(0x99);
    return;
  }
  if (cVar1 == '8') {
    FUN_fff99b70(0x99);
    return;
  }
  if (cVar1 == '9') {
    FUN_fff99ba5(0x99);
    return;
  }
  if (cVar1 == ':') {
    FUN_fff99d42(0x99);
    return;
  }
  if (cVar1 == 'C') {
    FUN_fff99bfe(0x99);
    return;
  }
  if (cVar1 == 'D') {
    FUN_fff99ca2(0x99);
    return;
  }
  if (cVar1 == 'E') {
    FUN_fff99cf2(0x99);
    return;
  }
  if (cVar1 == 'F') {
    FUN_fff99d48(0x99);
    return;
  }
  if (cVar1 == 'U') {
    FUN_fff99c58(0x99);
    return;
  }
  if (cVar1 == 'X') {
    FUN_fff99a29(0x99);
    return;
  }
  if (cVar1 != '\x1e') {
    return;
  }
  FUN_fff99475(0x99);
  return;
}


// ===== FUN_fff99475 @ fff99475 (298 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99588) */
/* WARNING: Removing unreachable block (ram,0xfff994d7) */
/* WARNING: Removing unreachable block (ram,0xfff99568) */
/* WARNING: Removing unreachable block (ram,0xfff9953b) */

void FUN_fff99475(ushort param_1)

{
  byte bVar1;
  byte *pbVar2;
  ushort uStack_6;
  undefined1 uStack_4;
  
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x4264302e;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  pbVar2 = (byte *)FUN_fff9c6ab();
  bVar1 = *pbVar2;
  if (bVar1 == 0x3c) {
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (bVar1 < 0x3d) {
    uStack_4 = 0x2d;
  }
  else {
    uStack_4 = 0x2b;
  }
  uStack_6 = (ushort)bVar1 * 5 - 300;
  if (bVar1 < 0x3c) {
    uStack_6 = ~uStack_6 + 1;
  }
  if ((uint)uStack_6 % 10 == 0) {
    (&DAT_00001746)[param_1] = 0x30;
  }
  else {
    (&DAT_00001746)[param_1] = 0x35;
  }
  if (uStack_6 < 10) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (uStack_6 < 100) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = (char)(uStack_6 / 10) + '0';
    return;
  }
  if (999 < uStack_6) {
    return;
  }
  (&DAT_00001742)[param_1] = uStack_4;
  (&DAT_00001743)[param_1] = (char)(uStack_6 / 100) + '0';
  (&DAT_00001744)[param_1] =
       (char)((int)((uint)uStack_6 + (uint)(uStack_6 / 100) * -100) / 10) + '0';
  return;
}


// ===== FUN_fff9959f @ fff9959f (45 bytes)

/* WARNING: Removing unreachable block (ram,0xfff995b0) */

void FUN_fff9959f(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_00009be6;
  *(undefined4 *)(&DAT_00001745 + param_1) =
       *(undefined4 *)(BYTE_ARRAY_fff80000 + uVar1 * 8 + 0x328);
  *(undefined4 *)(&DAT_00001741 + param_1) =
       *(undefined4 *)(BYTE_ARRAY_fff80000 + uVar1 * 8 + 0x324);
  return;
}


// ===== FUN_fff995cc @ fff995cc (66 bytes)

undefined * FUN_fff995cc(ushort param_1)

{
  uint uVar1;
  undefined1 uVar2;
  byte bVar3;
  
  uVar2 = FUN_fffb4062();
  bVar3 = FUN_fff99e4a(uVar2,3,&DAT_000019ca);
  (&DAT_00001748)[param_1] = 0x57;
  uVar1 = (uint)bVar3;
  smovf(&DAT_00001748 + (param_1 - uVar1),0x19ca,uVar1);
  return &DAT_00001748 + (param_1 - uVar1) + uVar1;
}


// ===== FUN_fff9960e @ fff9960e (91 bytes)

undefined2 * FUN_fff9960e(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  char *pcVar3;
  char cStack_3;
  
  pcVar3 = (char *)FUN_fff99669();
  if (pcVar3 == (char *)0x0) {
    cStack_3 = '\0';
  }
  else {
    cStack_3 = *pcVar3;
  }
  if (cStack_3 != '\0') {
    bVar2 = FUN_fff99e4a(cStack_3,3,&DAT_000019d2);
    uVar1 = (uint)bVar2;
    smovf(&DAT_00001749 + (param_1 - uVar1),0x19d2,uVar1);
    return (undefined2 *)(&DAT_00001749 + (param_1 - uVar1) + uVar1);
  }
  (&DAT_00001748)[param_1] = 0x46;
  *(undefined2 *)(&DAT_00001746 + param_1) = 17999;
  return (undefined2 *)(&DAT_00001746 + param_1);
}


// ===== FUN_fff99669 @ fff99669 (121 bytes)

uint FUN_fff99669(void)

{
  byte bVar1;
  undefined1 *local_8;
  uint uVar2;
  
  bVar1 = vfo_mode(1);
  uVar2 = (uint)bVar1;
  if (uVar2 != 0xe) {
    if (uVar2 - 2 < 2) {
      local_8 = &DAT_00009bfd;
      return (uint)local_8;
    }
    if (uVar2 - 4 < 2) {
      local_8 = &DAT_00009c00;
      return (uint)local_8;
    }
    if (1 < uVar2 - 8) {
      if (uVar2 - 0xc < 2) {
        local_8 = &DAT_00009bfe;
        return (uint)local_8;
      }
      if (1 < uVar2) {
        return 0;
      }
      local_8 = &DAT_00009bfc;
      return (uint)local_8;
    }
  }
  local_8 = &DAT_00009bff;
  return (uint)local_8;
}


// ===== FUN_fff996e2 @ fff996e2 (53 bytes)

undefined * FUN_fff996e2(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = FUN_fff99e4a(DAT_00009bf3,3,&DAT_000019da);
  uVar1 = (uint)bVar2;
  smovf(&DAT_00001749 + (param_1 - uVar1),0x19da,uVar1);
  return &DAT_00001749 + (param_1 - uVar1) + uVar1;
}


// ===== FUN_fff99717 @ fff99717 (117 bytes)

undefined * FUN_fff99717(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  byte local_3;
  
  *(undefined2 *)(&DAT_00001747 + param_1) = 0x736d;
  if (DAT_00009af3 == '\0') {
    local_3 = DAT_00009bf4;
  }
  else {
    local_3 = DAT_00009bf5;
  }
  if (0x21 < local_3) {
    local_3 = 0;
  }
  bVar2 = FUN_fff99e4a(*(undefined2 *)(BYTE_ARRAY_fff87ed4 + (uint)local_3 * 2 + 2),4,&DAT_000019e2)
  ;
  uVar1 = (uint)bVar2;
  smovf(&DAT_00001747 + (param_1 - uVar1),0x19e2,uVar1);
  return &DAT_00001747 + (param_1 - uVar1) + uVar1;
}


// ===== FUN_fff9978c @ fff9978c (83 bytes)

undefined * FUN_fff9978c(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  undefined1 local_3;
  
  if (DAT_00009af3 == '\0') {
    local_3 = DAT_00009bf6;
  }
  else {
    local_3 = DAT_00009bf7;
  }
  bVar2 = FUN_fff99e4a(local_3,3,&DAT_000019ea);
  uVar1 = (uint)bVar2;
  smovf(&DAT_00001749 + (param_1 - uVar1),0x19ea,uVar1);
  return &DAT_00001749 + (param_1 - uVar1) + uVar1;
}


// ===== FUN_fff997df @ fff997df (88 bytes)

undefined2 * FUN_fff997df(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  
  if (DAT_00009bf1 != '\0') {
    bVar2 = FUN_fff99e4a(DAT_00009bf1,3,&DAT_000019f2);
    uVar1 = (uint)bVar2;
    smovf(&DAT_00001749 + (param_1 - uVar1),0x19f2,uVar1);
    return (undefined2 *)(&DAT_00001749 + (param_1 - uVar1) + uVar1);
  }
  (&DAT_00001748)[param_1] = 0x46;
  *(undefined2 *)(&DAT_00001746 + param_1) = 17999;
  return (undefined2 *)(&DAT_00001746 + param_1);
}


// ===== FUN_fff99837 @ fff99837 (64 bytes)

undefined * FUN_fff99837(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 uStack_3;
  
  puVar3 = (undefined1 *)FUN_fff99877();
  if (puVar3 == (undefined1 *)0x0) {
    uStack_3 = 0;
  }
  else {
    uStack_3 = *puVar3;
  }
  bVar2 = FUN_fff99e4a(uStack_3,3,&DAT_000019fa);
  uVar1 = (uint)bVar2;
  smovf(&DAT_00001749 + (param_1 - uVar1),0x19fa,uVar1);
  return &DAT_00001749 + (param_1 - uVar1) + uVar1;
}

