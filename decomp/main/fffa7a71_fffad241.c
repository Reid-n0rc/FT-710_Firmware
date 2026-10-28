// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== cat_BP @ fffa7a71 (836 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa7d1c) */
/* WARNING: Removing unreachable block (ram,0xfffa7b81) */
/* WARNING: Removing unreachable block (ram,0xfffa7ba9) */
/* WARNING: Removing unreachable block (ram,0xfffa7db2) */
/* WARNING: Removing unreachable block (ram,0xfffa7cd9) */
/* WARNING: Removing unreachable block (ram,0xfffa7d69) */
/* WARNING: Removing unreachable block (ram,0xfffa7daf) */
/* WARNING: Removing unreachable block (ram,0xfffa7d33) */
/* WARNING: Removing unreachable block (ram,0xfffa7a9d) */
/* WARNING: Removing unreachable block (ram,0xfffa7bde) */
/* WARNING: Removing unreachable block (ram,0xfffa7d85) */

undefined2 * cat_BP(int param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  ushort uVar6;
  short in_stack_00000038;
  undefined2 *puStack_2c;
  ushort uStack_26;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  byte *pbStack_1c;
  undefined1 uStack_16;
  undefined1 uStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  iVar3 = vfo_rec_ptr(0);
  bVar1 = vfo_mode(0);
  if ((undefined2 *)(uint)*(byte *)(param_1 + 2) != (undefined2 *)0x30) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)*(byte *)(param_1 + 2);
  }
  uVar4 = (uint)bVar1;
  if (param_2 == '\0') {
    if (uVar4 - 2 < 2) {
      bStack_12 = *(byte *)(iVar3 + 0x14);
      uStack_16 = *(undefined1 *)(iVar3 + 0x18);
      uStack_15 = *(undefined1 *)(iVar3 + 0x19);
      goto LAB_fffa7b4e;
    }
    if (uVar4 - 4 < 2) {
      bStack_12 = *(byte *)(iVar3 + 0x32);
      uStack_16 = *(undefined1 *)(iVar3 + 0x36);
      uStack_15 = *(undefined1 *)(iVar3 + 0x37);
      goto LAB_fffa7b4e;
    }
    if (uVar4 - 6 < 2) {
LAB_fffa7b3c:
      bStack_12 = *(byte *)(iVar3 + 0x3c);
      uStack_16 = *(undefined1 *)(iVar3 + 0x40);
      uStack_15 = *(undefined1 *)(iVar3 + 0x41);
    }
    else {
      if (1 < uVar4 - 8) {
        if (uVar4 - 10 < 2) goto LAB_fffa7b3c;
        if (uVar4 - 0xc < 2) {
          bStack_12 = *(byte *)(iVar3 + 0x1e);
          uStack_16 = *(undefined1 *)(iVar3 + 0x22);
          uStack_15 = *(undefined1 *)(iVar3 + 0x23);
          goto LAB_fffa7b4e;
        }
        if (uVar4 != 0xe) {
          bStack_12 = *(byte *)(iVar3 + 10);
          uStack_16 = *(undefined1 *)(iVar3 + 0xe);
          uStack_15 = *(undefined1 *)(iVar3 + 0xf);
          goto LAB_fffa7b4e;
        }
      }
      bStack_12 = *(byte *)(iVar3 + 0x28);
      uStack_16 = *(undefined1 *)(iVar3 + 0x2c);
      uStack_15 = *(undefined1 *)(iVar3 + 0x2d);
    }
LAB_fffa7b4e:
    if (*(char *)(param_1 + 3) == '0') {
      DAT_00001c92 = 0x30;
      DAT_00001c93._0_1_ = 0x30;
      if ((bStack_12 & 0x80) == 0) {
        DAT_00001c93._1_1_ = 0x30;
      }
      else {
        DAT_00001c93._1_1_ = 0x31;
      }
    }
    else {
      uStack_26 = CONCAT11(uStack_16,uStack_15);
      bStack_13 = 100;
      for (bStack_14 = 0; bStack_14 < 3; bStack_14 = bStack_14 + 1) {
        uVar4 = (uint)uStack_26;
        if (bStack_13 != 0) {
          uVar4 = uVar4 / bStack_13;
        }
        uVar6 = uStack_26;
        if (bStack_13 != 0) {
          uVar6 = uStack_26 / bStack_13;
        }
        uStack_26 = uStack_26 - (uVar6 * bStack_13 & 0xff);
        bStack_13 = bStack_13 / 10;
        uVar2 = nib2hex(uVar4 & 0xff);
        (&DAT_00001c92)[bStack_14] = uVar2;
      }
    }
    DAT_00001c93._2_1_ = 0x3b;
    DAT_0001b788 = 8;
    return &DAT_00001c8e;
  }
  if (uVar4 - 2 < 2) {
    pbStack_1c = (byte *)(iVar3 + 0x14);
    puStack_24 = (undefined1 *)(iVar3 + 0x18);
    puStack_20 = (undefined1 *)(iVar3 + 0x19);
    goto LAB_fffa7c97;
  }
  if (uVar4 - 4 < 2) {
    pbStack_1c = (byte *)(iVar3 + 0x32);
    puStack_24 = (undefined1 *)(iVar3 + 0x36);
    puStack_20 = (undefined1 *)(iVar3 + 0x37);
    goto LAB_fffa7c97;
  }
  if (uVar4 - 6 < 2) {
LAB_fffa7c82:
    pbStack_1c = (byte *)(iVar3 + 0x3c);
    puStack_24 = (undefined1 *)(iVar3 + 0x40);
    puStack_20 = (undefined1 *)(iVar3 + 0x41);
  }
  else {
    if (1 < uVar4 - 8) {
      if (uVar4 - 10 < 2) goto LAB_fffa7c82;
      if (uVar4 - 0xc < 2) {
        pbStack_1c = (byte *)(iVar3 + 0x1e);
        puStack_24 = (undefined1 *)(iVar3 + 0x22);
        puStack_20 = (undefined1 *)(iVar3 + 0x23);
        goto LAB_fffa7c97;
      }
      if (uVar4 != 0xe) {
        pbStack_1c = (byte *)(iVar3 + 10);
        puStack_24 = (undefined1 *)(iVar3 + 0xe);
        puStack_20 = (undefined1 *)(iVar3 + 0xf);
        goto LAB_fffa7c97;
      }
    }
    pbStack_1c = (byte *)(iVar3 + 0x28);
    puStack_24 = (undefined1 *)(iVar3 + 0x2c);
    puStack_20 = (undefined1 *)(iVar3 + 0x2d);
  }
LAB_fffa7c97:
  if (*(char *)(param_1 + 3) == '0') {
    puVar5 = (undefined2 *)(uint)*(byte *)(param_1 + 4);
    if ((puVar5 != (undefined2 *)0x30) ||
       (puVar5 = (undefined2 *)(uint)*(byte *)(param_1 + 5), puVar5 != (undefined2 *)0x30)) {
      return puVar5;
    }
    if (*(char *)(param_1 + 6) == '0') {
      *pbStack_1c = *pbStack_1c & 0x7f;
    }
    else {
      if ((undefined2 *)(uint)*(byte *)(param_1 + 6) != (undefined2 *)0x31) {
        DAT_0000464a = 1;
        return (undefined2 *)(uint)*(byte *)(param_1 + 6);
      }
      *pbStack_1c = *pbStack_1c | 0x80;
    }
  }
  else {
    if ((undefined2 *)(uint)*(byte *)(param_1 + 3) != (undefined2 *)0x31) {
      DAT_0000464a = 1;
      return (undefined2 *)(uint)*(byte *)(param_1 + 3);
    }
    uStack_26 = 0;
    for (bStack_14 = 4; bStack_14 < 7; bStack_14 = bStack_14 + 1) {
      if ((*(byte *)((uint)bStack_14 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_14 + param_1))) {
        puStack_2c = (undefined2 *)0x1;
      }
      else {
        puStack_2c = (undefined2 *)0x0;
      }
      if (puStack_2c != (undefined2 *)0x0) {
        DAT_0000464a = 1;
        return puStack_2c;
      }
      uStack_26 = (*(byte *)((uint)bStack_14 + param_1) & 0xf) * in_stack_00000038 + uStack_26;
    }
    if ((uStack_26 == 0) || (0x140 < uStack_26)) {
      puStack_2c = (undefined2 *)0x1;
    }
    else {
      puStack_2c = (undefined2 *)0x0;
    }
    if (puStack_2c != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return puStack_2c;
    }
    *puStack_24 = (char)(uStack_26 >> 8);
    *puStack_20 = (undefined1)uStack_26;
  }
  DAT_00020f10 = 1;
  vfo_mark_edited(DAT_00009dbd);
  puVar5 = (undefined2 *)vfo_store_back(DAT_00009dbd);
  return puVar5;
}


// ===== cat_BS @ fffa7db5 (492 bytes)

void cat_BS(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  uVar2 = DAT_00009dbd;
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
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
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((*(byte *)(param_1 + 2) < 0x30) || (0x31 < *(byte *)(param_1 + 2))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      cVar3 = hex2nib(*(undefined1 *)(param_1 + 2));
      if ((*(byte *)(param_1 + 3) < 0x30) || (0x39 < *(byte *)(param_1 + 3))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        cVar4 = hex2nib(*(undefined1 *)(param_1 + 3));
        bVar5 = cVar4 + cVar3 * '\n';
        if (0xc < bVar5) {
          DAT_0000464a = 1;
          return;
        }
        band_select_on(bVar5,uVar2);
        DAT_00009c5e = 0;
        DAT_00009dbe = 1;
        DAT_00009dbf = 1;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CF @ fffa7fa1 (980 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8071) */
/* WARNING: Removing unreachable block (ram,0xfffa808d) */
/* WARNING: Removing unreachable block (ram,0xfffa8303) */
/* WARNING: Removing unreachable block (ram,0xfffa82ac) */
/* WARNING: Removing unreachable block (ram,0xfffa8287) */
/* WARNING: Removing unreachable block (ram,0xfffa825c) */
/* WARNING: Removing unreachable block (ram,0xfffa8218) */
/* WARNING: Removing unreachable block (ram,0xfffa831d) */
/* WARNING: Removing unreachable block (ram,0xfffa8372) */
/* WARNING: Removing unreachable block (ram,0xfffa8354) */
/* WARNING: Removing unreachable block (ram,0xfffa81e0) */
/* WARNING: Removing unreachable block (ram,0xfffa8191) */
/* WARNING: Removing unreachable block (ram,0xfffa813d) */
/* WARNING: Removing unreachable block (ram,0xfffa81c6) */
/* WARNING: Removing unreachable block (ram,0xfffa81fa) */

undefined2 * cat_CF(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  ushort uVar7;
  undefined2 *puStack_24;
  byte bStack_1e;
  char local_1d;
  byte *local_1c;
  ushort uStack_18;
  ushort uStack_16;
  byte bStack_13;
  byte bStack_12;
  undefined2 *local_10;
  short sStack_c;
  
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      local_10 = (undefined2 *)&DAT_00009d09;
      local_1c = (byte *)&DAT_00020f29;
      local_1d = DAT_00020f29;
    }
    else {
      local_10 = (undefined2 *)&DAT_00009d63;
      local_1c = (byte *)&DAT_00020f2a;
      local_1d = DAT_00020f2a;
    }
  }
  else {
    if ((undefined2 *)(uint)*(byte *)(param_1 + 2) != (undefined2 *)0x31) {
      DAT_0000464a = 1;
      return (undefined2 *)(uint)*(byte *)(param_1 + 2);
    }
    if (DAT_00009dbd == '\0') {
      local_10 = (undefined2 *)&DAT_00009d63;
      local_1c = (byte *)&DAT_00020f2a;
      local_1d = DAT_00020f2a;
    }
    else {
      local_10 = (undefined2 *)&DAT_00009d09;
      local_1c = (byte *)&DAT_00020f29;
      local_1d = DAT_00020f29;
    }
  }
  bVar2 = hex2nib(*(undefined1 *)(param_1 + 4));
  if ((undefined2 *)0x1 < (undefined2 *)(uint)bVar2) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)bVar2;
  }
  if (param_2 == '\0') {
    DAT_00001c91 = 0x30;
    DAT_00001c92 = nib2hex(bVar2);
    if (bVar2 == 0) {
      if (local_1d == '\0') {
        DAT_00001c93._0_1_ = 0x30;
        DAT_00001c93._1_1_ = 0x30;
      }
      else if (local_1d == '\x01') {
        DAT_00001c93._0_1_ = 0x31;
        DAT_00001c93._1_1_ = 0x30;
      }
      else if (local_1d == '\x02') {
        DAT_00001c93._0_1_ = 0x30;
        DAT_00001c93._1_1_ = 0x31;
      }
      else if (local_1d == '\x03') {
        DAT_00001c93._0_1_ = 0x31;
        DAT_00001c93._1_1_ = 0x31;
      }
      DAT_00001c93._2_1_ = 0x30;
      DAT_00001c93._3_1_ = 0x30;
      DAT_00001c97 = 0x30;
    }
    else {
      uStack_16 = CONCAT11(*(byte *)(local_10 + 0x24),*(undefined1 *)((int)local_10 + 0x49));
      if ((*(byte *)(local_10 + 0x24) & 0x80) == 0) {
        DAT_00001c93._0_1_ = 0x2b;
      }
      else {
        DAT_00001c93._0_1_ = 0x2d;
        uStack_16 = ~uStack_16 + 1;
      }
      uStack_18 = 1000;
      for (bStack_13 = 0; bStack_13 < 4; bStack_13 = bStack_13 + 1) {
        uVar4 = (uint)uStack_16;
        if (uStack_18 != 0) {
          uVar4 = uVar4 / uStack_18;
        }
        uVar7 = uStack_16;
        if ((uStack_18 & 0xff) != 0) {
          uVar7 = (ushort)((uint)uStack_16 / (uStack_18 & 0xff));
        }
        uStack_16 = uStack_16 - (uVar7 * uStack_18 & 0xff);
        uStack_18 = uStack_18 / 10;
        uVar3 = nib2hex(uVar4 & 0xff);
        *(undefined1 *)((int)&DAT_00001c93 + bStack_13 + 1) = uVar3;
      }
    }
    DAT_00001c98 = 0x3b;
    DAT_0001b788 = 0xb;
    return &DAT_00001c8e;
  }
  puVar5 = (undefined2 *)key_event_filter(0x306,0);
  if (puVar5 != (undefined2 *)0x0) {
    if (DAT_00009c5e == '\x01') {
      DAT_0000464a = 1;
      return puVar5;
    }
    iVar6 = vfo_tune_locked(DAT_00009dbd);
    if (iVar6 != 1) {
      if (bVar2 == 0) {
        if ((*(char *)(param_1 + 7) == '0') && (*(char *)(param_1 + 8) == '0')) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((bVar1) || (*(char *)(param_1 + 9) != '0')) {
          puStack_24 = (undefined2 *)0x1;
        }
        else {
          puStack_24 = (undefined2 *)0x0;
        }
        if (puStack_24 != (undefined2 *)0x0) {
          DAT_0000464a = 1;
          return puStack_24;
        }
        bStack_12 = 0;
        bStack_1e = 0;
        if (*(char *)(param_1 + 5) == '1') {
          bStack_12 = 1;
          bStack_1e = 0x10;
        }
        else if ((undefined2 *)(uint)*(byte *)(param_1 + 5) != (undefined2 *)0x30) {
          DAT_0000464a = 1;
          return (undefined2 *)(uint)*(byte *)(param_1 + 5);
        }
        if (*(char *)(param_1 + 6) == '1') {
          bStack_12 = bStack_12 | 2;
          bStack_1e = bStack_1e | 8;
        }
        else if ((undefined2 *)(uint)*(byte *)(param_1 + 6) != (undefined2 *)0x30) {
          DAT_0000464a = 1;
          return (undefined2 *)(uint)*(byte *)(param_1 + 6);
        }
        *local_1c = bStack_12;
        *(byte *)((int)local_10 + 1) = *(byte *)((int)local_10 + 1) & 0xe7;
        *(byte *)((int)local_10 + 1) = *(byte *)((int)local_10 + 1) | bStack_1e;
      }
      else {
        uStack_16 = 0;
        for (bStack_13 = 6; bStack_13 < 10; bStack_13 = bStack_13 + 1) {
          if ((*(byte *)((uint)bStack_13 + param_1) < 0x30) ||
             (0x39 < *(byte *)((uint)bStack_13 + param_1))) {
            puStack_24 = (undefined2 *)0x1;
          }
          else {
            puStack_24 = (undefined2 *)0x0;
          }
          if (puStack_24 != (undefined2 *)0x0) {
            DAT_0000464a = 1;
            return puStack_24;
          }
          uStack_16 = (*(byte *)((uint)bStack_13 + param_1) & 0xf) * sStack_c + uStack_16;
        }
        if (*(char *)(param_1 + 5) == '-') {
          uStack_16 = ~uStack_16 + 1;
        }
        else if ((undefined2 *)(uint)*(byte *)(param_1 + 5) != (undefined2 *)0x2b) {
          DAT_0000464a = 1;
          return (undefined2 *)(uint)*(byte *)(param_1 + 5);
        }
        *(char *)(local_10 + 0x24) = (char)(uStack_16 >> 8);
        *(byte *)((int)local_10 + 0x49) = (byte)uStack_16;
        local_10 = (undefined2 *)(uint)(byte)uStack_16;
      }
      DAT_00020f10 = 1;
      return local_10;
    }
    DAT_0000464a = 1;
    return (undefined2 *)0x1;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_CH @ fffa8375 (414 bytes)

void cat_CH(int param_1)

{
  bool bVar1;
  char local_6;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
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
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_6 = DAT_00009dbe;
  }
  else {
    local_6 = DAT_00009dbf;
  }
  if (local_6 != '\x02') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00020f80 = 0;
    FUN_fffc54cc(1,DAT_00009dbd);
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00020f80 = 1;
    FUN_fffc54cc(1,DAT_00009dbd);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CN @ fffa8513 (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8603) */
/* WARNING: Removing unreachable block (ram,0xfffa863e) */
/* WARNING: Removing unreachable block (ram,0xfffa8695) */
/* WARNING: Removing unreachable block (ram,0xfffa8654) */
/* WARNING: Removing unreachable block (ram,0xfffa85ce) */
/* WARNING: Removing unreachable block (ram,0xfffa852e) */

undefined2 * cat_CN(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_0000000c;
  undefined2 *local_1c;
  undefined1 local_15;
  byte local_14;
  byte local_13;
  byte local_12;
  undefined1 *local_10;
  
  if ((undefined2 *)(uint)*(byte *)(param_1 + 3) != (undefined2 *)0x30) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)*(byte *)(param_1 + 3);
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d09;
      local_15 = 0;
    }
    else {
      local_10 = &DAT_00009d63;
      local_15 = 1;
    }
  }
  else if (*(char *)(param_1 + 2) == '1') {
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d63;
      local_15 = 1;
    }
    else {
      local_10 = &DAT_00009d09;
      local_15 = 0;
    }
  }
  if (param_2 != '\0') {
    local_14 = 0;
    local_13 = 4;
    while( true ) {
      if (6 < local_13) {
        if (local_14 < 0x32) {
          local_10[0x46] = local_14;
        }
        else {
          DAT_0000464a = 1;
        }
        DAT_00020f10 = 1;
        vfo_mark_edited(local_15);
        puVar2 = (undefined2 *)vfo_store_back(local_15);
        return puVar2;
      }
      if ((*(byte *)((uint)local_13 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)local_13 + param_1))) {
        local_1c = (undefined2 *)0x1;
      }
      else {
        local_1c = (undefined2 *)0x0;
      }
      if (local_1c != (undefined2 *)0x0) break;
      local_14 = (*(byte *)((uint)local_13 + param_1) & 0xf) * in_stack_0000000c + local_14;
      local_13 = local_13 + 1;
    }
    DAT_0000464a = 1;
    return local_1c;
  }
  local_12 = 100;
  local_14 = local_10[0x46];
  for (local_13 = 0; local_13 < 3; local_13 = local_13 + 1) {
    bVar3 = local_14;
    if (local_12 != 0) {
      bVar3 = local_14 / local_12;
    }
    local_14 = local_14 - bVar3 * local_12;
    local_12 = local_12 / 10;
    uVar1 = nib2hex(bVar3);
    (&DAT_00001c92)[local_13] = uVar1;
  }
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return &DAT_00001c8e;
}


// ===== cat_CO @ fffa8698 (1280 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa89a8) */
/* WARNING: Removing unreachable block (ram,0xfffa89f9) */
/* WARNING: Removing unreachable block (ram,0xfffa8b95) */
/* WARNING: Removing unreachable block (ram,0xfffa8b27) */
/* WARNING: Removing unreachable block (ram,0xfffa8b7d) */
/* WARNING: Removing unreachable block (ram,0xfffa8b3d) */
/* WARNING: Removing unreachable block (ram,0xfffa89b4) */
/* WARNING: Removing unreachable block (ram,0xfffa8999) */
/* WARNING: Removing unreachable block (ram,0xfffa8aad) */
/* WARNING: Removing unreachable block (ram,0xfffa8ab9) */
/* WARNING: Removing unreachable block (ram,0xfffa8a9e) */
/* WARNING: Removing unreachable block (ram,0xfffa8a8f) */
/* WARNING: Removing unreachable block (ram,0xfffa8a47) */
/* WARNING: Removing unreachable block (ram,0xfffa8a11) */
/* WARNING: Removing unreachable block (ram,0xfffa8a71) */
/* WARNING: Removing unreachable block (ram,0xfffa88d2) */
/* WARNING: Removing unreachable block (ram,0xfffa87dc) */
/* WARNING: Removing unreachable block (ram,0xfffa889d) */
/* WARNING: Removing unreachable block (ram,0xfffa871e) */
/* WARNING: Removing unreachable block (ram,0xfffa8732) */
/* WARNING: Removing unreachable block (ram,0xfffa875a) */
/* WARNING: Removing unreachable block (ram,0xfffa8746) */
/* WARNING: Removing unreachable block (ram,0xfffa870a) */
/* WARNING: Removing unreachable block (ram,0xfffa8a4c) */
/* WARNING: Removing unreachable block (ram,0xfffa8b89) */
/* WARNING: Removing unreachable block (ram,0xfffa8aec) */
/* WARNING: Removing unreachable block (ram,0xfffa86f7) */

byte * cat_CO(int param_1,char param_2)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  short sVar4;
  uint3 uVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined1 uVar8;
  uint uVar9;
  byte bVar10;
  ushort uVar11;
  char in_stack_00000004;
  byte *pbStack_30;
  ushort uStack_2a;
  ushort uStack_28;
  byte bStack_25;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  byte *pbStack_1c;
  byte *pbStack_18;
  byte bStack_11;
  int iStack_10;
  char local_9;
  int local_8;
  
  local_9 = param_2;
  local_8 = param_1;
  iStack_10 = vfo_rec_ptr(0);
  bStack_11 = vfo_mode(0);
  uVar6 = uStack_24;
  uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
  uVar9 = (uint)bStack_11;
  if (local_9 != '\0') {
    if (uVar9 - 2 < 2) {
      pbStack_18 = (byte *)(iStack_10 + 0x14);
      pbStack_1c = (byte *)(iStack_10 + 0x14);
      puStack_20 = (undefined1 *)(iStack_10 + 0x16);
      goto LAB_fffa8986;
    }
    if (uVar9 - 4 < 2) {
      pbStack_18 = (byte *)(iStack_10 + 0x32);
      pbStack_1c = (byte *)((int)&uStack_24 + 3);
      puStack_20 = (undefined1 *)(iStack_10 + 0x34);
      goto LAB_fffa8986;
    }
    if (uVar9 - 6 < 2) {
LAB_fffa8973:
      pbStack_18 = (byte *)(iStack_10 + 0x3c);
      pbStack_1c = (byte *)((int)&uStack_24 + 3);
      puStack_20 = (undefined1 *)(iStack_10 + 0x3e);
    }
    else {
      if (1 < uVar9 - 8) {
        if (uVar9 - 10 < 2) goto LAB_fffa8973;
        if (uVar9 - 0xc < 2) {
          pbStack_18 = (byte *)(iStack_10 + 0x1e);
          pbStack_1c = (byte *)(iStack_10 + 0x1e);
          puStack_20 = (undefined1 *)(iStack_10 + 0x20);
          goto LAB_fffa8986;
        }
        if (uVar9 != 0xe) {
          pbStack_18 = (byte *)(iStack_10 + 10);
          pbStack_1c = (byte *)((int)&uStack_24 + 3);
          puStack_20 = (undefined1 *)(iStack_10 + 0xc);
          goto LAB_fffa8986;
        }
      }
      pbStack_18 = (byte *)(iStack_10 + 0x28);
      pbStack_1c = (byte *)(iStack_10 + 0x28);
      puStack_20 = (undefined1 *)(iStack_10 + 0x2a);
    }
LAB_fffa8986:
    if (*(char *)(local_8 + 3) == '0') {
      if (*(char *)(local_8 + 7) == '0') {
        *pbStack_18 = *pbStack_18 & 0xbf;
        return pbStack_18;
      }
      if ((byte *)(uint)*(byte *)(local_8 + 7) == (byte *)0x31) {
        *pbStack_18 = *pbStack_18 | 0x40;
        return pbStack_18;
      }
      DAT_0000464a = 1;
      return (byte *)(uint)*(byte *)(local_8 + 7);
    }
    if (*(char *)(local_8 + 3) == '1') {
      uStack_28 = 0;
      uStack_24 = CONCAT31(uStack_24._1_3_,4);
      while (uVar9 = uStack_24, (uStack_24 & 0xff) < 8) {
        bVar7 = *(byte *)((uStack_24 & 0xff) + local_8);
        sVar4 = (ushort)uStack_24;
        uStack_24._0_3_ = CONCAT12(bVar7,(ushort)uStack_24);
        uVar5 = (uint3)uStack_24;
        uStack_24 = (uint)(uint3)uStack_24;
        uVar2 = uStack_24;
        if ((bVar7 < 0x30) || (0x39 < bVar7)) {
          pbStack_30 = (byte *)0x1;
        }
        else {
          pbStack_30 = (byte *)0x0;
        }
        if (pbStack_30 != (byte *)0x0) {
          DAT_0000464a = 1;
          return pbStack_30;
        }
        uStack_24._0_1_ = (char)uVar9;
        uStack_28 = (*(byte *)((uVar2 & 0xff) + local_8) & 0xf) * sVar4 + uStack_28;
        uStack_24 = CONCAT31(uVar5 >> 8,(char)uStack_24 + '\x01');
      }
      if ((uStack_28 < 10) || (0xc80 < uStack_28)) {
        pbStack_30 = (byte *)0x1;
      }
      else {
        pbStack_30 = (byte *)0x0;
      }
      if (pbStack_30 == (byte *)0x0) {
        *puStack_20 = (char)(uStack_28 / 10 >> 8);
        uStack_28._0_1_ = (byte)(uStack_28 / 10);
        puStack_20[1] = (byte)uStack_28;
        DAT_00020f10 = 1;
        return (byte *)(uint)(byte)uStack_28;
      }
      DAT_0000464a = 1;
      return pbStack_30;
    }
    if (*(char *)(local_8 + 3) == '2') {
      if (*pbStack_1c == 0xff) {
        DAT_0000464a = 1;
        return pbStack_1c;
      }
      if (*(char *)(local_8 + 7) != '0') {
        if ((byte *)(uint)*(byte *)(local_8 + 7) == (byte *)0x31) {
          *pbStack_1c = *pbStack_1c | 0x20;
          return pbStack_1c;
        }
        DAT_0000464a = 1;
        return (byte *)(uint)*(byte *)(local_8 + 7);
      }
      *pbStack_1c = *pbStack_1c & 0xdf;
      return pbStack_1c;
    }
    if ((byte *)(uint)*(byte *)(local_8 + 3) != (byte *)0x33) {
      DAT_0000464a = 1;
      return (byte *)(uint)*(byte *)(local_8 + 3);
    }
    if ((*(char *)(local_8 + 4) == '0') && (*(char *)(local_8 + 5) == '0')) {
      pbStack_30 = (byte *)0x0;
    }
    else {
      pbStack_30 = (byte *)0x1;
    }
    if (pbStack_30 == (byte *)0x0) {
      bStack_25 = 0;
      uStack_24 = 6;
      while( true ) {
        cVar3 = (char)uStack_24;
        if (7 < uStack_24) {
          pbVar1 = (byte *)(uint)bStack_25;
          if ((byte *)0x32 < pbVar1) {
            DAT_0000464a = 1;
            return pbVar1;
          }
          DAT_00009c5f = bStack_25 - 0x19;
          DAT_00020f10 = 1;
          return pbVar1;
        }
        bVar7 = *(byte *)(uStack_24 + local_8);
        uStack_24._0_3_ = CONCAT12(bVar7,(ushort)uStack_24);
        uStack_24 = (uint)(uint3)uStack_24;
        if ((bVar7 < 0x30) || (0x39 < bVar7)) {
          pbStack_30 = (byte *)0x1;
        }
        else {
          pbStack_30 = (byte *)0x0;
        }
        if (pbStack_30 != (byte *)0x0) break;
        bStack_25 = (*(byte *)((uStack_24 & 0xff) + local_8) & 0xf) * in_stack_00000004 + bStack_25;
        uStack_24 = (uint)(byte)(cVar3 + 1);
      }
      DAT_0000464a = 1;
      return pbStack_30;
    }
    DAT_0000464a = 1;
    return pbStack_30;
  }
  uStack_24._0_2_ = (ushort)uVar6;
  if (uVar9 - 2 < 2) {
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x14),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x16),*(undefined1 *)(iStack_10 + 0x17));
    goto LAB_fffa8761;
  }
  if (uVar9 - 4 < 2) {
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x32),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x34),*(undefined1 *)(iStack_10 + 0x35));
    goto LAB_fffa8761;
  }
  if (uVar9 - 6 < 2) {
LAB_fffa874f:
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x3c),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x3e),*(undefined1 *)(iStack_10 + 0x3f));
  }
  else {
    if (1 < uVar9 - 8) {
      if (uVar9 - 10 < 2) goto LAB_fffa874f;
      if (uVar9 - 0xc < 2) {
        uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x1e),(ushort)uStack_24);
        uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
        uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x20),*(undefined1 *)(iStack_10 + 0x21));
        goto LAB_fffa8761;
      }
      if (uVar9 != 0xe) {
        uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 10),(ushort)uStack_24);
        uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
        uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0xc),*(undefined1 *)(iStack_10 + 0xd));
        goto LAB_fffa8761;
      }
    }
    uStack_24._0_3_ = CONCAT12(*(undefined1 *)(iStack_10 + 0x28),(ushort)uStack_24);
    uStack_24 = CONCAT13(0xff,(uint3)uStack_24);
    uStack_28 = CONCAT11(*(undefined1 *)(iStack_10 + 0x2a),*(undefined1 *)(iStack_10 + 0x2b));
  }
LAB_fffa8761:
  if (*(char *)(local_8 + 3) == '0') {
    DAT_00001c91 = 0x30;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    DAT_00001c93._1_1_ = 0x30;
    if ((uStack_24 & 0x400000) == 0) {
      DAT_00001c93._2_1_ = 0x30;
    }
    else {
      DAT_00001c93._2_1_ = 0x31;
    }
  }
  else if (*(char *)(local_8 + 3) == '1') {
    DAT_00001c91 = 0x31;
    uStack_2a = 1000;
    uStack_28 = uStack_28 * 10;
    uStack_24 = uStack_24 & 0xffffff00;
    while ((uStack_24 & 0xff) < 4) {
      uVar9 = (uint)uStack_28;
      if (uStack_2a != 0) {
        uVar9 = uVar9 / uStack_2a;
      }
      uStack_24._0_3_ = CONCAT12((char)uVar9,(ushort)uStack_24);
      uVar11 = uStack_28;
      if ((uStack_2a & 0xff) != 0) {
        uVar11 = (ushort)((uint)uStack_28 / (uStack_2a & 0xff));
      }
      uStack_28 = uStack_28 - (uVar11 * uStack_2a & 0xff);
      uStack_2a = uStack_2a / 10;
      uVar2 = (uint)(uint3)uStack_24;
      uVar8 = nib2hex((char)uVar9);
      (&DAT_00001c92)[uVar2 & 0xff] = uVar8;
      uStack_24 = CONCAT31(uStack_24._1_3_,(char)uStack_24 + '\x01');
    }
    DAT_00001c93._2_1_ = 0x30;
  }
  else if (*(char *)(local_8 + 3) == '2') {
    DAT_00001c91 = 0x32;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    DAT_00001c93._1_1_ = 0x30;
    if ((uStack_24 & 0x200000) == 0) {
      DAT_00001c93._2_1_ = 0x30;
    }
    else {
      DAT_00001c93._2_1_ = 0x31;
    }
  }
  else if (*(char *)(local_8 + 3) == '3') {
    DAT_00001c91 = 0x33;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    bStack_25 = DAT_00009c5f + 0x19;
    uStack_24 = CONCAT22(uStack_24._2_2_,0xa00);
    while ((uStack_24 & 0xff) < 2) {
      bVar7 = bStack_25;
      if (uStack_24._1_1_ != 0) {
        bVar7 = bStack_25 / uStack_24._1_1_;
      }
      bVar10 = bStack_25;
      if (uStack_24._1_1_ != 0) {
        bVar10 = bStack_25 / uStack_24._1_1_;
      }
      bStack_25 = bStack_25 - bVar10 * uStack_24._1_1_;
      uStack_24._0_2_ = CONCAT11(uStack_24._1_1_ / 10,(char)uStack_24);
      uStack_24 = CONCAT22(CONCAT11(uStack_24._3_1_,bVar7),(ushort)uStack_24);
      uVar9 = (uint)(ushort)uStack_24;
      uVar8 = nib2hex(bVar7);
      *(undefined1 *)((int)&DAT_00001c93 + (uVar9 & 0xff) + 1) = uVar8;
      uStack_24 = CONCAT31(uStack_24._1_3_,(char)uStack_24 + '\x01');
    }
  }
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return (byte *)&DAT_00001c8e;
}


// ===== cat_CS @ fffa8b98 (225 bytes)

void cat_CS(int param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    if (DAT_00020f0b == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  uVar1 = vfo_rec_ptr(1);
  iVar2 = key_event_filter(0x307,2);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_0000464a = 1;
    return;
  }
  iVar2 = FUN_fffc3e3c(uVar1);
  if (iVar2 != 0) {
    if (*(char *)(param_1 + 2) == '1') {
      DAT_00020f0b = 1;
      beep_request(4);
      return;
    }
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00020f0b != '\x01') {
      return;
    }
    DAT_00020f0b = 0;
    beep_stop();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CT @ fffa8c79 (273 bytes)

void cat_CT(int param_1,char param_2)

{
  byte bVar1;
  undefined1 *local_c;
  
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  if (param_2 != '\0') {
    if (*(char *)(param_1 + 3) == '0') {
      local_c[3] = local_c[3] & 199;
    }
    else if (*(char *)(param_1 + 3) == '2') {
      local_c[3] = local_c[3] & 199;
      local_c[3] = local_c[3] | 8;
    }
    else {
      if (*(char *)(param_1 + 3) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_c[3] = local_c[3] & 199;
      local_c[3] = local_c[3] | 0x10;
    }
    DAT_00020f10 = 1;
    return;
  }
  bVar1 = (local_c[3] & 0x38) >> 3;
  if (bVar1 == 0) {
    DAT_00001c91 = 0x30;
  }
  else if (bVar1 == 1) {
    DAT_00001c91 = 0x32;
  }
  else {
    if (bVar1 != 2) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00001c91 = 0x31;
  }
  DAT_00001c92 = 0x3b;
  DAT_0001b788 = 5;
  return;
}


// ===== cat_DA @ fffa8d8a (671 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8eab) */
/* WARNING: Removing unreachable block (ram,0xfffa8e27) */
/* WARNING: Removing unreachable block (ram,0xfffa8ee6) */
/* WARNING: Removing unreachable block (ram,0xfffa8f41) */
/* WARNING: Removing unreachable block (ram,0xfffa9026) */
/* WARNING: Removing unreachable block (ram,0xfffa8ef7) */
/* WARNING: Removing unreachable block (ram,0xfffa8f52) */
/* WARNING: Removing unreachable block (ram,0xfffa8f9c) */
/* WARNING: Removing unreachable block (ram,0xfffa8dd8) */
/* WARNING: Removing unreachable block (ram,0xfffa8e76) */
/* WARNING: Removing unreachable block (ram,0xfffa8fad) */
/* WARNING: Removing unreachable block (ram,0xfffa901a) */

undefined2 * cat_DA(int param_1,char param_2)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_f;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    DAT_00001c90 = 0x30;
    DAT_00001c91 = 0x30;
    local_b = 10;
    local_f = DAT_00009be9;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_f;
      if (local_b != 0) {
        bVar3 = local_f / local_b;
      }
      local_f = local_f - bVar3 * local_b;
      local_b = local_b / 10;
      uVar2 = nib2hex(bVar3);
      (&DAT_00001c92)[local_c] = uVar2;
    }
    local_b = 10;
    local_d = DAT_00009bea;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar2 = nib2hex(bVar3);
      *(undefined1 *)((int)&DAT_00001c93 + local_c + 1) = uVar2;
    }
    local_b = 10;
    local_e = DAT_00009b10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_e;
      if (local_b != 0) {
        bVar3 = local_e / local_b;
      }
      local_e = local_e - bVar3 * local_b;
      local_b = local_b / 10;
      uVar2 = nib2hex(bVar3);
      *(undefined1 *)((int)&DAT_00001c93 + local_c + 3) = uVar2;
    }
    DAT_00001c98 = 0x3b;
    DAT_0001b788 = 0xb;
    return &DAT_00001c8e;
  }
  local_f = 0;
  for (local_c = 4; local_c < 6; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_f = (bVar3 & 0xf) * in_stack_00000010 + local_f;
  }
  local_d = 0;
  for (local_c = 6; local_c < 8; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_d = (bVar3 & 0xf) * in_stack_00000010 + local_d;
  }
  local_e = 0;
  for (local_c = 8; local_c < 10; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_e = (bVar3 & 0xf) * in_stack_00000010 + local_e;
  }
  if ((local_f < 0x15) && (local_d < 0x15)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (local_e < 0x15)) {
    local_14 = (undefined2 *)0x1;
  }
  else {
    local_14 = (undefined2 *)0x0;
  }
  if (local_14 != (undefined2 *)0x0) {
    DAT_00009be9 = local_f;
    DAT_00009bea = local_d;
    DAT_00009b10 = local_e;
    DAT_00020f04 = 1;
    return local_14;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_DN @ fffa9029 (300 bytes)

void cat_DN(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = key_event_filter(0x34e,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
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
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  FUN_fffc037b();
  DAT_00020f6f = 0;
  return;
}


// ===== cat_UP @ fffa9155 (300 bytes)

void cat_UP(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = key_event_filter(0x348,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
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
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  FUN_fffc0335();
  DAT_00020f6f = 0;
  return;
}


// ===== cat_DT @ fffa9281 (967 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa943d) */
/* WARNING: Removing unreachable block (ram,0xfffa93cb) */
/* WARNING: Removing unreachable block (ram,0xfffa940d) */
/* WARNING: Removing unreachable block (ram,0xfffa9491) */
/* WARNING: Removing unreachable block (ram,0xfffa95a3) */
/* WARNING: Removing unreachable block (ram,0xfffa95e5) */

void cat_DT(int param_1,char param_2)

{
  bool bVar1;
  undefined4 *in_R14;
  char in_stack_00000010;
  byte local_b;
  byte local_a;
  byte local_9;
  byte local_7;
  byte local_6;
  
  if (*(char *)(param_1 + 2) == '0') {
    *in_R14 = 1;
  }
  if (param_2 == '\0') {
    if (in_R14 != (undefined4 *)0x0) {
      DAT_00001c91 = 0x32;
      DAT_00001c92 = 0x30;
      FUN_fffb311d(&DAT_00001c93,DAT_00020bb1);
      FUN_fffb311d(0x1c95,DAT_00020bb2);
      FUN_fffb311d(&DAT_00001c97,DAT_00020bb3);
      DAT_00001c99 = 0x3b;
      DAT_0001b788 = 0xc;
      return;
    }
    if (*(char *)(param_1 + 2) == '1') {
      FUN_fffb311d(&DAT_00001c91,DAT_00020bb4);
      FUN_fffb311d(&DAT_00001c93,DAT_00020bb5);
      DAT_00001c93._3_1_ = 0x30;
      DAT_00001c93._2_1_ = 0x30;
      DAT_00001c97 = 0x3b;
      DAT_0001b788 = 10;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (in_R14 != (undefined4 *)0x0) {
    for (local_6 = 3; local_6 < 0xb; local_6 = local_6 + 1) {
      if ((*(byte *)((uint)local_6 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_6 + param_1))
         ) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
    }
    local_9 = '\0';
    for (local_6 = 3; local_6 < 5; local_6 = local_6 + 1) {
      local_9 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_9;
    }
    if (local_9 != '\x14') {
      DAT_0000464a = 1;
      return;
    }
    local_9 = 0;
    for (local_6 = 5; local_6 < 7; local_6 = local_6 + 1) {
      local_9 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_9;
    }
    local_a = 0;
    for (local_6 = 7; local_6 < 9; local_6 = local_6 + 1) {
      local_a = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_a;
    }
    if ((local_a == 0) || (0xc < local_a)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_b = 0;
      for (local_6 = 9; local_6 < 0xb; local_6 = local_6 + 1) {
        local_b = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_b;
      }
      if (local_a == 2) {
        if ((local_9 & 3) == 0) {
          local_7 = 0x1d;
        }
        else {
          local_7 = 0x1c;
        }
      }
      else if ((((local_a == 4) || (local_a == 6)) || (local_a == 9)) || (local_a == 0xb)) {
        local_7 = 0x1e;
      }
      else {
        local_7 = 0x1f;
      }
      if ((local_b == 0) || (local_7 < local_b)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      DAT_00020bb1 = FUN_fffb30b5(param_1 + 5);
      DAT_00020bb6 = DAT_00020bb1;
      DAT_00020bb2 = FUN_fffb30b5(param_1 + 7);
      DAT_00020bb7 = DAT_00020bb2;
      DAT_00020bb3 = FUN_fffb30b5(param_1 + 9);
      DAT_00020bb8 = DAT_00020bb3;
      DAT_00020b91 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    DAT_0000464a = 1;
    return;
  }
  for (local_6 = 3; local_6 < 9; local_6 = local_6 + 1) {
    if ((*(byte *)((uint)local_6 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_6 + param_1)))
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
  }
  local_7 = 0;
  for (local_6 = 3; local_6 < 5; local_6 = local_6 + 1) {
    local_7 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_7;
  }
  if (local_7 < 0x18) {
    local_7 = 0;
    for (local_6 = 5; local_6 < 7; local_6 = local_6 + 1) {
      local_7 = (*(byte *)((uint)local_6 + param_1) & 0xf) * in_stack_00000010 + local_7;
    }
    if (0x3b < local_7) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020bb4 = FUN_fffb30b5(param_1 + 3);
    DAT_00020bb9 = DAT_00020bb4;
    DAT_00020bba = FUN_fffb30b5(param_1 + 5);
    DAT_00020bb5 = DAT_00020bba;
    DAT_00020b91 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_EM @ fffa9648 (736 bytes)

void cat_EM(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  byte bStack_d;
  
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    if (*(char *)(param_1 + 3) == '1') {
      cVar2 = FUN_fffb012c(&DAT_0000979e,0xfe,0x32);
      bStack_d = cVar2 + 0x62;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_0000979e;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      cVar2 = FUN_fffb012c(&DAT_000097d0,0xfe,0x32);
      bStack_d = cVar2 + 0x30;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_000097d0;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else if (*(char *)(param_1 + 3) == '3') {
      cVar2 = FUN_fffb012c(&DAT_00009802,0xfe,0x32);
      bStack_d = cVar2 - 2;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_00009802;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else if (*(char *)(param_1 + 3) == '4') {
      cVar2 = FUN_fffb012c(&DAT_00009834,0xfe,0x32);
      bStack_d = cVar2 - 0x34;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_00009834;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else {
      if (*(char *)(param_1 + 3) != '5') {
        DAT_0000464a = 1;
        return;
      }
      cVar2 = FUN_fffb012c(&DAT_00009866,0xfe,0x32);
      bStack_d = cVar2 + 0x9a;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_00009866;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    (&DAT_00001c92)[bStack_d] = 0x3b;
    DAT_0001b788 = bStack_d + 5;
    return;
  }
  cVar2 = FUN_fffb012c(param_1,0x3b,0x32);
  bVar3 = (cVar2 - (char)param_1) - 4;
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '1') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_0000979e;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_0000979e + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '2') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_000097d0;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_000097d0 + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '3') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_00009802;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_00009802 + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '4') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_00009834;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_00009834 + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '5') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_00009866;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_00009866 + (uint)bVar3) = 0xfe;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_EN @ fffa9928 (15 bytes)

void cat_EN(void)

{
  DAT_0000464a = 1;
  return;
}


// ===== cat_EX @ fffa9937 (134 bytes)

void cat_EX(undefined4 param_1,char param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
           )

{
  bool bVar1;
  undefined2 local_e;
  undefined2 *local_c;
  undefined2 local_8;
  char local_5;
  undefined4 local_4;
  
  local_e = 0;
  local_c = &local_e;
  local_8 = param_3;
  local_5 = param_2;
  local_4 = param_1;
  DAT_0000464a = ex_command(param_1,param_2,param_3,&DAT_00001c8e,param_5,local_c);
  if (local_5 == '\0') {
    DAT_0001b788 = *local_c;
    return;
  }
  if ((DAT_00020b20 == '\x01') || (DAT_00020b21 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b22 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cat_ai_holdoff();
    return;
  }
  return;
}


// ===== cat_FA_FB @ fffa99bd (729 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa9a6e) */
/* WARNING: Removing unreachable block (ram,0xfffa9b85) */
/* WARNING: Removing unreachable block (ram,0xfffa9af8) */
/* WARNING: Removing unreachable block (ram,0xfffa9b1d) */
/* WARNING: Removing unreachable block (ram,0xfffa9ae0) */
/* WARNING: Removing unreachable block (ram,0xfffa9a39) */
/* WARNING: Removing unreachable block (ram,0xfffa9aa1) */
/* WARNING: Removing unreachable block (ram,0xfffa9c93) */
/* WARNING: Removing unreachable block (ram,0xfffa9bf6) */

undefined2 * cat_FA_FB(int param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  uint uVar7;
  undefined2 *local_20;
  byte local_19;
  uint local_18;
  uint local_14;
  undefined1 *puStack_10;
  
  if (param_2 == '\0') {
    if (param_3 == '\0') {
      local_14 = DAT_00020f54;
    }
    else {
      local_14 = DAT_00020f58;
    }
    if ((DAT_00020b6b == '\x01') && (param_3 == DAT_00009dbd)) {
      local_14 = DAT_00020f50;
    }
    local_18 = 100000000;
    for (local_19 = 0; local_19 < 9; local_19 = local_19 + 1) {
      uVar4 = local_14;
      if (local_18 != 0) {
        uVar4 = local_14 / local_18;
      }
      uVar7 = local_14;
      if ((local_18 & 0xff) != 0) {
        uVar7 = local_14 / (local_18 & 0xff);
      }
      local_14 = local_14 - (uVar7 * local_18 & 0xff);
      local_18 = local_18 / 10;
      uVar3 = nib2hex(uVar4 & 0xff);
      (&DAT_00001c90)[local_19] = uVar3;
    }
    DAT_00001c99 = 0x3b;
    DAT_0001b788 = 0xc;
    return &DAT_00001c8e;
  }
  if ((DAT_00020b8a == '\x01') || (DAT_00020f11 == '\x01')) {
    local_20 = (undefined2 *)0x1;
  }
  else {
    local_20 = (undefined2 *)0x0;
  }
  if (local_20 != (undefined2 *)0x0) {
    DAT_0000464a = 1;
    return local_20;
  }
  local_14 = 0;
  local_18 = 100000000;
  for (local_19 = 2; local_19 < 0xb; local_19 = local_19 + 1) {
    if ((*(byte *)((uint)local_19 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_19 + param_1))
       ) {
      local_20 = (undefined2 *)0x1;
    }
    else {
      local_20 = (undefined2 *)0x0;
    }
    if (local_20 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_20;
    }
    local_14 = (*(byte *)((uint)local_19 + param_1) & 0xf) * local_18 + local_14;
    local_18 = local_18 / 10;
  }
  iVar5 = freq_in_range(local_14);
  cVar2 = DAT_00009dbf;
  cVar1 = DAT_00009dbe;
  if (iVar5 == 0) {
    DAT_0000464a = 1;
    return (undefined2 *)0x0;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009dbe = DAT_00009dc7;
    DAT_00009dbf = DAT_00009dc7;
  }
  iVar5 = vfo_tune_locked(param_3);
  if (iVar5 != 1) {
    if (param_3 == '\0') {
      if (DAT_00009dbe == '\x02') {
        vfo_mem_to_memtune(0);
      }
    }
    else if (DAT_00009dbf == '\x02') {
      vfo_mem_to_memtune(param_3);
    }
    DAT_00020f68 = (undefined2 *)freq_clamp(param_3,local_14);
    if (DAT_00020f6d != '\x01') {
      if (DAT_00009c5e != '\x01') {
        cVar1 = DAT_00009dbe;
        cVar2 = DAT_00009dbf;
      }
      DAT_00009dbf = cVar2;
      DAT_00009dbe = cVar1;
      if (param_3 == '\0') {
        puStack_10 = &DAT_00009d09;
      }
      else {
        puStack_10 = &DAT_00009d63;
      }
      for (local_19 = 0; local_19 < 4; local_19 = local_19 + 1) {
        puStack_10[local_19 + 0x4a] = (char)(local_14 >> ((3 - local_19 & 3) << 3));
      }
      for (local_19 = 0; local_19 < 2; local_19 = local_19 + 1) {
        puStack_10[local_19 + 0x48] = 0;
      }
      DAT_00020f10 = 1;
      vfo_mark_edited(param_3);
      puVar6 = (undefined2 *)vfo_store_back(param_3);
      return puVar6;
    }
    DAT_00009dbe = cVar1;
    DAT_00009dbf = cVar2;
    DAT_0000464a = 1;
    return DAT_00020f68;
  }
  DAT_00009dbe = cVar1;
  DAT_00009dbf = cVar2;
  DAT_0000464a = 1;
  return (undefined2 *)0x1;
}


// ===== cat_FN @ fffa9c96 (167 bytes)

void cat_FN(int param_1,char param_2)

{
  if (param_2 == '\0') {
    if (DAT_00009c61 == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else if (DAT_00009c61 == '\x02') {
      DAT_00001c90 = 0x32;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00009c61 = 0;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00009c61 = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '2') {
    DAT_0000464a = 1;
    return;
  }
  DAT_00009c61 = 2;
  return;
}


// ===== cat_FS @ fffa9d3d (17 bytes)

void cat_FS(void)

{
  DAT_0000464a = 1;
  return;
}


// ===== cat_FT @ fffa9d4e (469 bytes)

void cat_FT(int param_1,char param_2)

{
  bool bVar1;
  
  if (param_2 == '\0') {
    if (DAT_00009c5e == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
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
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009c5e == '\x01') {
      split_toggle();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00009c5e == '\0') {
      split_toggle();
      return;
    }
  }
  return;
}


// ===== cat_GT @ fffa9f23 (764 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaa1e9) */

void cat_GT(int param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbStack_14;
  undefined1 uStack_e;
  
  iVar2 = vfo_rec_ptr(0);
  bVar1 = vfo_mode(0);
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 == '\0') {
    uVar3 = (uint)bVar1;
    if (uVar3 == 0xe) {
LAB_fffaa02c:
      if ((*(byte *)(iVar2 + 0x29) & 0x40) == 0) {
        uStack_e = 0;
      }
      else {
        uVar3 = (*(byte *)(iVar2 + 0x29) & 0x30) >> 4;
        if (uVar3 == 0) {
          uStack_e = 5;
        }
        else if (uVar3 == 3) {
          uStack_e = 3;
        }
        else if (uVar3 == 2) {
          uStack_e = 2;
        }
        else if (uVar3 == 1) {
          uStack_e = 1;
        }
      }
    }
    else {
      if (uVar3 - 2 < 2) {
        if ((*(byte *)(iVar2 + 0x15) & 0x40) == 0) {
          uStack_e = 0;
        }
        else {
          uVar3 = (*(byte *)(iVar2 + 0x15) & 0x30) >> 4;
          if (uVar3 == 3) {
            uStack_e = 3;
          }
          else if (uVar3 == 1) {
            uStack_e = 1;
          }
          else if (uVar3 == 2) {
            uStack_e = 2;
          }
          else if (uVar3 == 0) {
            uStack_e = 4;
          }
        }
        goto LAB_fffaa12f;
      }
      if (uVar3 - 4 < 2) {
        if ((*(byte *)(iVar2 + 0x33) & 0x40) == 0) {
          uStack_e = 0;
        }
        else {
          uVar3 = (*(byte *)(iVar2 + 0x33) & 0x30) >> 4;
          if (uVar3 == 0) {
            uStack_e = 6;
          }
          else if (uVar3 == 3) {
            uStack_e = 3;
          }
          else if (uVar3 == 2) {
            uStack_e = 2;
          }
          else if (uVar3 == 1) {
            uStack_e = 1;
          }
        }
        goto LAB_fffaa12f;
      }
      if (1 < uVar3 - 6) {
        if (uVar3 - 8 < 2) goto LAB_fffaa02c;
        if (1 < uVar3 - 10) {
          if (uVar3 - 0xc < 2) {
            if ((*(byte *)(iVar2 + 0x1f) & 0x40) == 0) {
              uStack_e = 0;
            }
            else {
              uVar3 = (*(byte *)(iVar2 + 0x1f) & 0x30) >> 4;
              if (uVar3 == 0) {
                uStack_e = 5;
              }
              else if (uVar3 == 3) {
                uStack_e = 3;
              }
              else if (uVar3 == 2) {
                uStack_e = 2;
              }
              else if (uVar3 == 1) {
                uStack_e = 1;
              }
            }
          }
          else if (uVar3 < 2) {
            if ((*(byte *)(iVar2 + 0xb) & 0x40) == 0) {
              uStack_e = 0;
            }
            else {
              uVar3 = (*(byte *)(iVar2 + 0xb) & 0x30) >> 4;
              if (uVar3 == 0) {
                uStack_e = 6;
              }
              else if (uVar3 == 3) {
                uStack_e = 3;
              }
              else if (uVar3 == 2) {
                uStack_e = 2;
              }
              else if (uVar3 == 1) {
                uStack_e = 1;
              }
            }
          }
          goto LAB_fffaa12f;
        }
      }
      if ((*(byte *)(iVar2 + 0x3d) & 0x40) == 0) {
        uStack_e = 0;
      }
      else {
        uVar3 = (*(byte *)(iVar2 + 0x3d) & 0x30) >> 4;
        if (uVar3 == 3) {
          uStack_e = 3;
        }
        else if (uVar3 == 1) {
          uStack_e = 1;
        }
        else if (uVar3 == 2) {
          uStack_e = 2;
        }
        else if (uVar3 == 0) {
          uStack_e = 4;
        }
      }
    }
LAB_fffaa12f:
    DAT_00001c91 = nib2hex(uStack_e);
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  uVar3 = (uint)bVar1;
  if (uVar3 - 2 < 2) {
    pbStack_14 = (byte *)(iVar2 + 0x15);
    goto LAB_fffaa1b3;
  }
  if (uVar3 - 4 < 2) {
    pbStack_14 = (byte *)(iVar2 + 0x33);
    goto LAB_fffaa1b3;
  }
  if (uVar3 - 6 < 2) {
LAB_fffaa1ac:
    pbStack_14 = (byte *)(iVar2 + 0x3d);
  }
  else {
    if (1 < uVar3 - 8) {
      if (uVar3 - 10 < 2) goto LAB_fffaa1ac;
      if (uVar3 - 0xc < 2) {
        pbStack_14 = (byte *)(iVar2 + 0x1f);
        goto LAB_fffaa1b3;
      }
      if (uVar3 != 0xe) {
        pbStack_14 = (byte *)(iVar2 + 0xb);
        goto LAB_fffaa1b3;
      }
    }
    pbStack_14 = (byte *)(iVar2 + 0x29);
  }
LAB_fffaa1b3:
  bVar1 = hex2nib(*(undefined1 *)(param_1 + 3));
  if (4 < bVar1) {
    DAT_0000464a = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 & 0x8f;
  if (bVar1 == 4) {
    *pbStack_14 = *pbStack_14 | 0x40;
  }
  else if (bVar1 - 1 < 3) {
    *pbStack_14 = *pbStack_14 | 0x40;
    *pbStack_14 = bVar1 << 4 | *pbStack_14;
  }
  DAT_00020f10 = 1;
  vfo_mark_edited(DAT_00009dbd);
  vfo_store_back(DAT_00009dbd);
  return;
}


// ===== cat_GP @ fffaa21f (326 bytes)

void cat_GP(int param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = tunlin_port_mode();
  if (iVar2 != 3) {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 == '\0') {
    gpo_a_get();
    DAT_00001c90 = nib2hex();
    gpo_b_get();
    DAT_00001c91 = nib2hex();
    gpo_c_get();
    DAT_00001c92 = nib2hex();
    gpo_d_get();
    DAT_00001c93._0_1_ = nib2hex();
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if ((*(byte *)(param_1 + 2) < 0x32) && (*(byte *)(param_1 + 3) < 0x32)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (0x31 < *(byte *)(param_1 + 4))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (0x31 < *(byte *)(param_1 + 5))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  hex2nib(*(undefined1 *)(param_1 + 2));
  gpo_a_set();
  hex2nib(*(undefined1 *)(param_1 + 3));
  gpo_b_set();
  hex2nib(*(undefined1 *)(param_1 + 4));
  gpo_c_set();
  hex2nib(*(undefined1 *)(param_1 + 5));
  gpo_d_set();
  return;
}


// ===== cat_ID @ fffaa365 (55 bytes)

void cat_ID(void)

{
  DAT_00001c90 = 0x30;
  DAT_00001c91 = 0x38;
  DAT_00001c92 = 0x30;
  DAT_00001c93._0_1_ = 0x30;
  DAT_00001c93._1_1_ = 0x3b;
  DAT_0001b788 = 7;
  return;
}


// ===== cat_IF_OI @ fffaa39c (839 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaa6e0) */
/* WARNING: Removing unreachable block (ram,0xfffaa433) */
/* WARNING: Removing unreachable block (ram,0xfffaa4f0) */
/* WARNING: Removing unreachable block (ram,0xfffaa52e) */
/* WARNING: Removing unreachable block (ram,0xfffaa588) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * cat_IF_OI(char param_1)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  ushort uVar5;
  char local_27;
  byte local_26;
  byte local_25;
  undefined1 auStack_24 [9];
  byte local_1b;
  byte local_1a;
  byte local_19;
  ushort uStack_18;
  ushort uStack_16;
  uint uStack_14;
  uint uStack_10;
  byte *local_c;
  char local_5;
  
  if (param_1 == '\0') {
    local_c = &DAT_00009d09;
    local_1a = DAT_000060c9;
    local_25 = DAT_00009dbe;
    local_27 = DAT_00020f29;
  }
  else {
    local_c = &DAT_00009d63;
    local_1a = DAT_000060ca;
    local_25 = DAT_00009dbf;
    local_27 = DAT_00020f2a;
  }
  local_5 = param_1;
  if (local_1a < 99) {
    local_1a = local_1a + 1;
    local_26 = 100;
    for (local_19 = 0; local_19 < 3; local_19 = local_19 + 1) {
      local_1b = local_1a;
      if (local_26 != 0) {
        local_1b = local_1a / local_26;
      }
      local_1a = local_1a - local_1b * local_26;
      local_26 = local_26 / 10;
      uVar4 = (uint)local_19;
      uVar2 = nib2hex(local_1b);
      (&DAT_00001c90)[uVar4] = uVar2;
    }
  }
  else {
    local_1a = local_1a + 0x9d;
    DAT_00001c92 = (&DAT_fff806eb)[(uint)local_1a * 3];
    _DAT_00001c90 = *(undefined2 *)(&cat_pms_names + (uint)local_1a * 3);
  }
  if ((local_25 == 1) || (local_25 == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (local_25 == 5)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    _DAT_00001c90 = 0x3030;
    DAT_00001c92 = 0x30;
  }
  uStack_10 = vfo_freq(0,local_5);
  uStack_14 = 100000000;
  for (local_19 = 0; local_19 < 9; local_19 = local_19 + 1) {
    uVar4 = uStack_10;
    if (uStack_14 != 0) {
      uVar4 = uStack_10 / uStack_14;
    }
    auStack_24[local_19] = (char)uVar4;
    uVar4 = uStack_10;
    if ((uStack_14 & 0xff) != 0) {
      uVar4 = uStack_10 / (uStack_14 & 0xff);
    }
    uStack_10 = uStack_10 - (uVar4 * uStack_14 & 0xff);
    uStack_14 = uStack_14 / 10;
  }
  for (local_19 = 0; local_19 < 9; local_19 = local_19 + 1) {
    uVar4 = (uint)local_19;
    uVar2 = nib2hex(auStack_24[uVar4]);
    *(undefined1 *)((int)&DAT_00001c93 + uVar4) = uVar2;
  }
  uStack_16 = CONCAT11(local_c[0x48],local_c[0x49]);
  if ((local_c[0x48] & 0x80) == 0) {
    DAT_00001c9c = 0x2b;
  }
  else {
    DAT_00001c9c = 0x2d;
    uStack_16 = ~uStack_16 + 1;
  }
  uStack_18 = 1000;
  for (local_19 = 0; local_19 < 4; local_19 = local_19 + 1) {
    uVar4 = (uint)uStack_16;
    if (uStack_18 != 0) {
      uVar4 = uVar4 / uStack_18;
    }
    auStack_24[local_19] = (char)uVar4;
    uVar5 = uStack_16;
    if ((uStack_18 & 0xff) != 0) {
      uVar5 = (ushort)((uint)uStack_16 / (uStack_18 & 0xff));
    }
    uStack_16 = uStack_16 - (uVar5 * uStack_18 & 0xff);
    uStack_18 = uStack_18 / 10;
  }
  for (local_19 = 0; local_19 < 4; local_19 = local_19 + 1) {
    uVar4 = (uint)local_19;
    uVar2 = nib2hex(auStack_24[uVar4]);
    (&DAT_00001c9d)[uVar4] = uVar2;
  }
  if (local_27 == '\0') {
    DAT_00001ca1 = 0x30;
    DAT_00001ca2 = 0x30;
  }
  else if (local_27 == '\x01') {
    DAT_00001ca1 = 0x31;
    DAT_00001ca2 = 0x30;
  }
  else if (local_27 == '\x02') {
    DAT_00001ca1 = 0x30;
    DAT_00001ca2 = 0x31;
  }
  else if (local_27 == '\x03') {
    DAT_00001ca1 = 0x31;
    DAT_00001ca2 = 0x31;
  }
  DAT_00001ca3 = (&cat_mode_codes)[*local_c & 0xf];
  DAT_00001ca4 = (&cat_vfo_state_codes)[local_25];
  cVar3 = (char)((local_c[3] & 0x38) >> 3);
  if (cVar3 == '\x01') {
    DAT_00001ca5 = 0x32;
  }
  else if (cVar3 == '\x02') {
    DAT_00001ca5 = 0x31;
  }
  else {
    DAT_00001ca5 = 0x30;
  }
  DAT_00001ca7 = 0x30;
  DAT_00001ca6 = 0x30;
  cVar3 = (char)((local_c[2] & 0xc) >> 2);
  if (cVar3 == '\0') {
    DAT_00001ca8 = 0x32;
  }
  else if (cVar3 == '\x02') {
    DAT_00001ca8 = 0x31;
  }
  else {
    DAT_00001ca8 = 0x30;
  }
  DAT_00001ca9 = 0x3b;
  DAT_0001b788 = 0x1c;
  return &DAT_00001c8e;
}


// ===== cat_IS @ fffaa6e3 (546 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaa84e) */
/* WARNING: Removing unreachable block (ram,0xfffaa811) */
/* WARNING: Removing unreachable block (ram,0xfffaa7dc) */
/* WARNING: Removing unreachable block (ram,0xfffaa88b) */
/* WARNING: Removing unreachable block (ram,0xfffaa868) */
/* WARNING: Removing unreachable block (ram,0xfffaa902) */
/* WARNING: Removing unreachable block (ram,0xfffaa8b5) */
/* WARNING: Removing unreachable block (ram,0xfffaa77a) */

undefined2 * cat_IS(int param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  ushort uVar5;
  undefined2 *puStack_20;
  int iStack_1c;
  byte bStack_17;
  ushort uStack_14;
  ushort uStack_12;
  
  iStack_1c = vfo_rec_ptr(0);
  bVar1 = vfo_mode(0);
  uVar3 = (uint)bVar1;
  if (uVar3 - 2 < 2) {
    iStack_1c = iStack_1c + 0x1c;
    goto LAB_fffaa75f;
  }
  if (uVar3 - 4 < 2) {
    iStack_1c = iStack_1c + 0x3a;
    goto LAB_fffaa75f;
  }
  if (uVar3 - 6 < 2) {
LAB_fffaa758:
    iStack_1c = iStack_1c + 0x44;
  }
  else {
    if (1 < uVar3 - 8) {
      if (uVar3 - 10 < 2) goto LAB_fffaa758;
      if (uVar3 - 0xc < 2) {
        iStack_1c = iStack_1c + 0x26;
        goto LAB_fffaa75f;
      }
      if (uVar3 != 0xe) {
        iStack_1c = iStack_1c + 0x12;
        goto LAB_fffaa75f;
      }
    }
    iStack_1c = iStack_1c + 0x30;
  }
LAB_fffaa75f:
  if (param_2 == '\0') {
    DAT_00001c91 = 0x30;
    DAT_00001c90 = 0x30;
    uStack_12 = 0;
    for (bStack_17 = 0; bStack_17 < 2; bStack_17 = bStack_17 + 1) {
      uStack_12 = (ushort)*(byte *)((uint)bStack_17 + iStack_1c) | uStack_12 << 8;
    }
    if ((uStack_12 & 0x8000) == 0) {
      DAT_00001c92 = 0x2b;
    }
    else {
      DAT_00001c92 = 0x2d;
      uStack_12 = ~uStack_12 + 1;
    }
    uStack_14 = 1000;
    for (bStack_17 = 0; bStack_17 < 4; bStack_17 = bStack_17 + 1) {
      uVar3 = (uint)uStack_12;
      if (uStack_14 != 0) {
        uVar3 = uVar3 / uStack_14;
      }
      uVar5 = uStack_12;
      if ((uStack_14 & 0xff) != 0) {
        uVar5 = (ushort)((uint)uStack_12 / (uStack_14 & 0xff));
      }
      uStack_12 = uStack_12 - (uVar5 * uStack_14 & 0xff);
      uStack_14 = uStack_14 / 10;
      uVar2 = nib2hex(uVar3 & 0xff);
      *(undefined1 *)((int)&DAT_00001c93 + (uint)bStack_17) = uVar2;
    }
    DAT_00001c97 = 0x3b;
    DAT_0001b788 = 10;
    return &DAT_00001c8e;
  }
  uStack_12 = 0;
  bStack_17 = 5;
  while( true ) {
    if (8 < bStack_17) {
      if ((undefined2 *)0x2ee0 < (undefined2 *)(uint)uStack_12) {
        DAT_0000464a = 1;
        return (undefined2 *)(uint)uStack_12;
      }
      bVar1 = *(byte *)(param_1 + 4);
      if (bVar1 == 0x2d) {
        uStack_12 = ~uStack_12 + 1;
      }
      else if ((undefined2 *)(uint)bVar1 != (undefined2 *)0x2b) {
        DAT_0000464a = 1;
        return (undefined2 *)(uint)bVar1;
      }
      for (bStack_17 = 0; bStack_17 < 2; bStack_17 = bStack_17 + 1) {
        *(char *)((uint)bStack_17 + iStack_1c) = (char)(uStack_12 >> ((1 - bStack_17 & 3) << 3));
      }
      DAT_00020f10 = 1;
      vfo_mark_edited(DAT_00009dbd);
      puVar4 = (undefined2 *)vfo_store_back(DAT_00009dbd);
      return puVar4;
    }
    if ((*(byte *)((uint)bStack_17 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_17 + param_1))) {
      puStack_20 = (undefined2 *)0x1;
    }
    else {
      puStack_20 = (undefined2 *)0x0;
    }
    if (puStack_20 != (undefined2 *)0x0) break;
    uStack_12 = (*(byte *)((uint)bStack_17 + param_1) & 0xf) * (short)param_1 + uStack_12;
    bStack_17 = bStack_17 + 1;
  }
  DAT_0000464a = 1;
  return puStack_20;
}


// ===== cat_KM @ fffaa905 (817 bytes)

void cat_KM(int param_1,char param_2,char param_3)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  byte bStack_d;
  
  cVar2 = hex2nib(*(undefined1 *)(param_1 + 2));
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 2) == '1') {
      bStack_d = DAT_0000969f;
      puVar6 = &DAT_000096a0;
      puVar5 = &DAT_00001c91;
      for (uVar8 = (uint)DAT_0000969f; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
    }
    else if (*(char *)(param_1 + 2) == '2') {
      bStack_d = DAT_000096d2;
      puVar6 = &DAT_000096d3;
      puVar5 = &DAT_00001c91;
      for (uVar8 = (uint)DAT_000096d2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
    }
    else if (*(char *)(param_1 + 2) == '3') {
      bStack_d = DAT_00009705;
      puVar6 = &DAT_00009706;
      puVar5 = &DAT_00001c91;
      for (uVar8 = (uint)DAT_00009705; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
    }
    else if (*(char *)(param_1 + 2) == '4') {
      bStack_d = DAT_00009738;
      puVar6 = &DAT_00009739;
      puVar5 = &DAT_00001c91;
      for (uVar8 = (uint)DAT_00009738; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
    }
    else {
      if (*(char *)(param_1 + 2) != '5') {
        DAT_0000464a = 1;
        return;
      }
      bStack_d = DAT_0000976b;
      puVar6 = &DAT_0000976c;
      puVar5 = &DAT_00001c91;
      for (uVar8 = (uint)DAT_0000976b; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
    }
    if (bStack_d == 0) {
      DAT_00001c90 = 0x3b;
      DAT_0001b788 = 3;
      return;
    }
    (&DAT_00001c91)[bStack_d] = 0x3b;
    DAT_0001b788 = bStack_d + 4;
    return;
  }
  if ((DAT_00020b94 == '\x01') && (DAT_00020bc2 == '\x02')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (cVar2 == (char)(DAT_00020bc3 + '\x01'))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  bVar3 = param_3 - 4;
  if (*(char *)(param_1 + 2) == '1') {
    puVar4 = (undefined4 *)&DAT_000096a0;
    for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0x20;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar6 = (undefined1 *)(param_1 + 3);
    puVar5 = &DAT_000096a0;
    for (uVar8 = (uint)bVar3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar5 = *puVar6;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    uVar8 = FUN_fffb012c(param_1 + 3,0x7d,0x32);
    if (uVar8 == (param_1 + 3U & 0xff)) {
      (&DAT_000096a0)[bVar3] = 0x7d;
    }
    DAT_0000969f = bVar3;
    eeprom_save_msg(1,1);
    return;
  }
  if (*(char *)(param_1 + 2) != '2') {
    if (*(char *)(param_1 + 2) == '3') {
      puVar4 = (undefined4 *)&DAT_00009706;
      for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = 0x20;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      puVar6 = (undefined1 *)(param_1 + 3);
      puVar5 = &DAT_00009706;
      for (uVar8 = (uint)bVar3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar5 = *puVar6;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      uVar8 = FUN_fffb012c(param_1 + 3,0x7d,0x32);
      if (uVar8 == (param_1 + 3U & 0xff)) {
        (&DAT_00009706)[bVar3] = 0x7d;
      }
      DAT_00009705 = bVar3;
      eeprom_save_msg(1,3);
      return;
    }
    if (*(char *)(param_1 + 2) != '4') {
      if (*(char *)(param_1 + 2) == '5') {
        puVar4 = (undefined4 *)&DAT_0000976c;
        for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar4 = 0x20;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        puVar6 = (undefined1 *)(param_1 + 3);
        puVar5 = &DAT_0000976c;
        for (uVar8 = (uint)bVar3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar5 = *puVar6;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        uVar8 = FUN_fffb012c(param_1 + 3,0x7d,0x32);
        if (uVar8 == (param_1 + 3U & 0xff)) {
          (&DAT_0000976c)[bVar3] = 0x7d;
        }
        DAT_0000976b = bVar3;
        eeprom_save_msg(1,5);
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    puVar4 = (undefined4 *)&DAT_00009739;
    for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar4 = 0x20;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar6 = (undefined1 *)(param_1 + 3);
    puVar5 = &DAT_00009739;
    for (uVar8 = (uint)bVar3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar5 = *puVar6;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    uVar8 = FUN_fffb012c(param_1 + 3,0x7d,0x32);
    if (uVar8 == (param_1 + 3U & 0xff)) {
      (&DAT_00009739)[bVar3] = 0x7d;
    }
    DAT_00009738 = bVar3;
    eeprom_save_msg(1,4);
    return;
  }
  puVar4 = (undefined4 *)&DAT_000096d3;
  for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0x20;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  puVar6 = (undefined1 *)(param_1 + 3);
  puVar5 = &DAT_000096d3;
  for (uVar8 = (uint)bVar3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar5 = *puVar6;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar8 = FUN_fffb012c(param_1 + 3,0x7d,0x32);
  if (uVar8 == (param_1 + 3U & 0xff)) {
    (&DAT_000096d3)[bVar3] = 0x7d;
  }
  DAT_000096d2 = bVar3;
  eeprom_save_msg(1,2);
  return;
}


// ===== cat_KP @ fffaac36 (284 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaace2) */
/* WARNING: Removing unreachable block (ram,0xfffaaca6) */
/* WARNING: Removing unreachable block (ram,0xfffaad4f) */
/* WARNING: Removing unreachable block (ram,0xfffaad4c) */
/* WARNING: Removing unreachable block (ram,0xfffaacf8) */
/* WARNING: Removing unreachable block (ram,0xfffaad40) */
/* WARNING: Removing unreachable block (ram,0xfffaac71) */

undefined2 * cat_KP(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_b = 10;
    local_d = DAT_00009c04;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = nib2hex(bVar3);
      (&DAT_00001c90)[local_c] = uVar1;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return &DAT_00001c8e;
  }
  local_d = 0;
  for (local_c = 2; local_c < 4; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_d;
  }
  puVar2 = (undefined2 *)(uint)local_d;
  if ((undefined2 *)0x4b < puVar2) {
    DAT_0000464a = 1;
    return puVar2;
  }
  DAT_00009c04 = local_d;
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x31;
    FUN_fffc8cbb(0x31);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  return puVar2;
}


// ===== cat_KR @ fffaad52 (152 bytes)

void cat_KR(int param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(DAT_00009c02);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  iVar1 = key_event_filter(0xe0,0);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  iVar1 = FUN_fffe5690();
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009c02 = 0;
    return;
  }
  DAT_00009c02 = 1;
  return;
}


// ===== cat_KS @ fffaadea (303 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaae5a) */
/* WARNING: Removing unreachable block (ram,0xfffaaeac) */
/* WARNING: Removing unreachable block (ram,0xfffaaf13) */
/* WARNING: Removing unreachable block (ram,0xfffaaf07) */
/* WARNING: Removing unreachable block (ram,0xfffaae96) */
/* WARNING: Removing unreachable block (ram,0xfffaae25) */
/* WARNING: Removing unreachable block (ram,0xfffaaf16) */

undefined2 * cat_KS(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_b = 100;
    local_d = DAT_00009c03;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = nib2hex(bVar3);
      (&DAT_00001c90)[local_c] = uVar1;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return &DAT_00001c8e;
  }
  local_d = 0;
  for (local_c = 2; local_c < 5; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_d;
  }
  if ((local_d < 4) || (0x3c < local_d)) {
    local_14 = (undefined2 *)0x0;
  }
  else {
    local_14 = (undefined2 *)0x1;
  }
  if (local_14 != (undefined2 *)0x0) {
    DAT_00009c03 = local_d;
    if (DAT_00009ace != '\0') {
      return local_14;
    }
    DAT_00020cc6 = 0x30;
    FUN_fffc8cbb(0x30);
    puVar2 = (undefined2 *)FUN_fffc8d8c();
    return puVar2;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_KY @ fffaaf19 (390 bytes)

/* WARNING: Removing unreachable block (ram,0xfffab014) */
/* WARNING: Removing unreachable block (ram,0xfffaaf41) */
/* WARNING: Removing unreachable block (ram,0xfffab08f) */
/* WARNING: Removing unreachable block (ram,0xfffab09c) */
/* WARNING: Removing unreachable block (ram,0xfffab070) */
/* WARNING: Removing unreachable block (ram,0xfffab03e) */
/* WARNING: Removing unreachable block (ram,0xfffaafe5) */
/* WARNING: Removing unreachable block (ram,0xfffaafad) */
/* WARNING: Removing unreachable block (ram,0xfffaaf90) */
/* WARNING: Removing unreachable block (ram,0xfffaaf7b) */
/* WARNING: Removing unreachable block (ram,0xfffaaf6f) */

uint cat_KY(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = key_event_filter(0x87,0);
  if (iVar3 == 0) {
    DAT_0000464a = 1;
    return 0;
  }
  uVar4 = FUN_fffe5690();
  if (uVar4 != 1) {
    DAT_0000464a = 1;
    return uVar4;
  }
  DAT_00020ccb = 1;
  if (DAT_00020b97 == '\x01') {
    DAT_0000464a = 1;
    return 1;
  }
  if (0x31 < *(byte *)(param_1 + 2)) {
    DAT_0000464a = 1;
    return (uint)*(byte *)(param_1 + 2);
  }
  bVar1 = hex2nib(*(undefined1 *)(param_1 + 3));
  if (bVar1 == 0) {
    DAT_00020b2f = 7;
    return 0;
  }
  if (5 < bVar1) {
    DAT_0000464a = 1;
    return (uint)bVar1;
  }
  uVar2 = hex2nib(*(undefined1 *)(param_1 + 2));
  (&DAT_00009aac)[bVar1] = uVar2;
  FUN_fffe538f(bVar1);
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00020cd0 = 1;
  }
  else {
    if (*(byte *)(param_1 + 2) != 0x31) {
      DAT_0000464a = 1;
      return (uint)*(byte *)(param_1 + 2);
    }
    DAT_00020cd1 = 1;
  }
  iVar3 = FUN_fffe564b();
  if (iVar3 == 0) {
    DAT_00020cd1 = 0;
    DAT_00020cd0 = 0;
    DAT_0000464a = 1;
    return 0;
  }
  uVar4 = FUN_fffe5401(bVar1);
  if (uVar4 == 0) {
    DAT_00020cd1 = 0;
    DAT_00020cd0 = 0;
    uVar4 = beep_request(3);
    DAT_0000464a = 1;
    return uVar4;
  }
  if (DAT_00020b2f == '\x01') {
    DAT_00020b2f = 5;
    return uVar4;
  }
  uVar4 = FUN_fffe53c0();
  DAT_00020cd6 = 1;
  return uVar4;
}


// ===== cat_LK @ fffab09f (208 bytes)

void cat_LK(int param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(DAT_00009c62);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  iVar1 = key_event_filter(0x300,0);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00009c62 = 1;
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x47;
      FUN_fffc8cbb(0x47);
      FUN_fffc8d8c();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009c62 = 0;
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x48;
      FUN_fffc8cbb(0x48);
      FUN_fffc8d8c();
      return;
    }
  }
  return;
}


// ===== cat_LM @ fffab16f (654 bytes)

void cat_LM(int param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 2) == '0') {
      if (DAT_00020b7c == '\x02') {
        DAT_00001c91 = nib2hex(DAT_00020b7d + '\x01');
      }
      else {
        DAT_00001c91 = 0x30;
      }
    }
    else if (*(char *)(param_1 + 2) == '1') {
      DAT_00001c91 = nib2hex(DAT_00020b96);
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  iVar2 = key_event_filter(0x87,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '0') {
    if (*(char *)(param_1 + 2) != '1') {
      return;
    }
    if ((DAT_00020b7c == '\x01') || (DAT_00020b7c == '\x02')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020ccd == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020cd0 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020cd1 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 3) == '0') {
        DAT_00020b96 = '\0';
      }
      else {
        if (*(char *)(param_1 + 3) != '1') {
          DAT_0000464a = 1;
          return;
        }
        if (DAT_00020b96 != '\x01') {
          DAT_00020b96 = '\x01';
        }
      }
      DAT_00020b95 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020b96 == '\x01') || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    DAT_00020b7c = 0;
    DAT_00020f1b = 0;
    DAT_00020cce = 0;
    return;
  }
  if (*(byte *)(param_1 + 3) < 0x36) {
    iVar2 = FUN_fffe56bf();
    if (iVar2 != 1) {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00020b7c != '\0') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020ccc = hex2nib(*(undefined1 *)(param_1 + 3));
    DAT_00020ccb = 0;
    DAT_00020f1b = 1;
    DAT_00020cce = 1;
    DAT_00020b7d = DAT_00020ccc + -1;
    FUN_fffe4efc();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_MA @ fffab3fd (123 bytes)

void cat_MA(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = &DAT_00006150 + (uint)DAT_000060c9 * 0x5a;
  iVar1 = key_event_filter(0x308,0);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00020b3d == '\0') {
    puVar2 = &DAT_00009d09;
    for (iVar1 = 0x5a; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    vfo_mark_edited(0);
    vfo_store_back(0);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_MB @ fffab478 (123 bytes)

void cat_MB(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = &DAT_00006150 + (uint)DAT_000060ca * 0x5a;
  iVar1 = key_event_filter(0x308,0);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00020b3d == '\0') {
    puVar2 = &DAT_00009d63;
    for (iVar1 = 0x5a; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    vfo_mark_edited(1);
    vfo_store_back(1);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_MC @ fffab4f3 (734 bytes)

/* WARNING: Removing unreachable block (ram,0xfffab5d0) */
/* WARNING: Removing unreachable block (ram,0xfffab62f) */
/* WARNING: Removing unreachable block (ram,0xfffab748) */
/* WARNING: Removing unreachable block (ram,0xfffab645) */
/* WARNING: Removing unreachable block (ram,0xfffab7ce) */
/* WARNING: Removing unreachable block (ram,0xfffab70e) */
/* WARNING: Removing unreachable block (ram,0xfffab702) */
/* WARNING: Removing unreachable block (ram,0xfffab681) */
/* WARNING: Removing unreachable block (ram,0xfffab57b) */
/* WARNING: Removing unreachable block (ram,0xfffab5e9) */
/* WARNING: Removing unreachable block (ram,0xfffab72f) */
/* WARNING: Removing unreachable block (ram,0xfffab6c9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * cat_MC(int param_1,byte param_2)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  undefined1 *puVar8;
  byte bVar9;
  char in_stack_00000034;
  undefined2 *puStack_20;
  byte local_e;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  
  puVar4 = (undefined1 *)vfo_rec_ptr(0);
  toupper_inplace();
  toupper_inplace();
  toupper_inplace();
  cVar2 = DAT_00009dbd;
  if ((undefined2 *)(uint)param_2 == (undefined2 *)0x0) {
    if (DAT_00009dbd == '\0') {
      local_e = DAT_000060c9;
    }
    else {
      local_e = DAT_000060ca;
    }
    if (local_e < 99) {
      local_e = local_e + 1;
      bStack_b = 100;
      for (bStack_a = 0; bStack_a < 3; bStack_a = bStack_a + 1) {
        bVar9 = local_e;
        if (bStack_b != 0) {
          bVar9 = local_e / bStack_b;
        }
        local_e = local_e - bVar9 * bStack_b;
        bStack_b = bStack_b / 10;
        uVar3 = nib2hex(bVar9);
        (&DAT_00001c90)[bStack_a] = uVar3;
      }
    }
    else {
      iVar5 = (uint)(byte)(local_e + 0x9d) * 3;
      DAT_00001c92 = (&DAT_fff806eb)[iVar5];
      _DAT_00001c90 = *(undefined2 *)(&cat_pms_names + iVar5);
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return &DAT_00001c8e;
  }
  if (DAT_00020b3d != '\0') {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)param_2;
  }
  if (*(char *)(param_1 + 2) == '0') {
    bStack_c = 0;
    for (bStack_a = 2; bStack_a < 5; bStack_a = bStack_a + 1) {
      if ((*(byte *)((uint)bStack_a + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_a + param_1))) {
        puStack_20 = (undefined2 *)0x1;
      }
      else {
        puStack_20 = (undefined2 *)0x0;
      }
      if (puStack_20 != (undefined2 *)0x0) {
        DAT_0000464a = 1;
        return puStack_20;
      }
      bStack_c = (*(byte *)((uint)bStack_a + param_1) & 0xf) * in_stack_00000034 + bStack_c;
    }
    if ((bStack_c == 0) || (99 < bStack_c)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return (undefined2 *)0x0;
    }
    local_e = bStack_c - 1;
  }
  else {
    local_e = 0;
    for (bStack_b = 0; bStack_b < 0x22; bStack_b = bStack_b + 1) {
      iVar5 = FUN_fffede1d(&cat_pms_names + (uint)bStack_b * 3,param_1 + 2,3);
      if (iVar5 == 0) {
        local_e = bStack_b + 99;
        break;
      }
    }
    if ((undefined2 *)(uint)local_e < (undefined2 *)0x63) {
      DAT_0000464a = 1;
      return (undefined2 *)(uint)local_e;
    }
  }
  if ((local_e < 0x84) && (0x74 < local_e)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    puVar7 = (undefined2 *)FUN_fff9c2cd();
    if (puVar7 != (undefined2 *)0x1) {
      DAT_0000464a = 1;
      return puVar7;
    }
    iVar5 = memch_dest_blocked(local_e);
    if (iVar5 == 1) {
      DAT_0000464a = 1;
      return (undefined2 *)0x1;
    }
  }
  if ((DAT_00009af4 == '\0') && (local_e == 0x84)) {
    DAT_0000464a = 1;
    return (undefined2 *)0x84;
  }
  iVar5 = memch_valid(local_e);
  if (iVar5 == 0) {
    DAT_0000464a = 1;
    return (undefined2 *)0x0;
  }
  if (cVar2 == '\0') {
    DAT_000060c9 = local_e;
    DAT_00009dbe = 2;
    puVar6 = &DAT_00009dce;
    puVar8 = puVar4;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar8;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  else {
    DAT_000060ca = local_e;
    DAT_00009dbf = 2;
    puVar6 = &DAT_00009e28;
    puVar8 = puVar4;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar8;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  puVar8 = &DAT_00006150 + (uint)local_e * 0x5a;
  for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puVar8;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  puVar7 = (undefined2 *)eeprom_save_memch(1);
  DAT_00020f10 = 1;
  return puVar7;
}


// ===== cat_MD @ fffab7d1 (659 bytes)

void cat_MD(int param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  byte bStack_e;
  byte local_d;
  byte *local_c;
  
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      local_c = &DAT_00009d09;
    }
    else {
      local_c = &DAT_00009d63;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00009dbd == '\0') {
      local_c = &DAT_00009d63;
    }
    else {
      local_c = &DAT_00009d09;
    }
  }
  if (param_2 == '\0') {
    DAT_00001c91 = (&cat_mode_codes)[*local_c & 0xf];
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  iVar2 = key_event_filter(0x30c,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
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
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  DAT_00020cd5 = 0;
  local_d = 0xff;
  toupper_inplace();
  bStack_e = 0;
  do {
    if (0xe < bStack_e) {
LAB_fffaba23:
      if (local_d == 0xff) {
        DAT_0000464a = 1;
        return;
      }
      if (*(char *)(param_1 + 2) == '0') {
        FUN_fffc4bd5(local_d);
        return;
      }
      if (*(char *)(param_1 + 2) == '1') {
        *local_c = *local_c & 0xf0 | local_d;
        return;
      }
      return;
    }
    if (*(char *)(param_1 + 3) == (&cat_mode_codes)[bStack_e]) {
      local_d = bStack_e;
      goto LAB_fffaba23;
    }
    bStack_e = bStack_e + 1;
  } while( true );
}


// ===== cat_MG @ fffaba64 (406 bytes)

/* WARNING: Removing unreachable block (ram,0xfffabaec) */
/* WARNING: Removing unreachable block (ram,0xfffabb4b) */
/* WARNING: Removing unreachable block (ram,0xfffabb86) */
/* WARNING: Removing unreachable block (ram,0xfffabbbf) */
/* WARNING: Removing unreachable block (ram,0xfffabb9d) */
/* WARNING: Removing unreachable block (ram,0xfffabbf7) */
/* WARNING: Removing unreachable block (ram,0xfffabb16) */

undefined2 * cat_MG(int param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  short in_stack_00000004;
  undefined2 *puStack_20;
  byte *pbStack_1c;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  ushort uStack_14;
  
  bVar1 = vfo_mode(0);
  puVar3 = (undefined2 *)(uint)bVar1;
  if (puVar3 == (undefined2 *)0xe) {
LAB_fffabab6:
    pbStack_1c = &DAT_00009bed;
    bStack_18 = DAT_00009bed;
  }
  else {
    if (puVar3 + -2 < (undefined2 *)0x2) {
      pbStack_1c = &DAT_00009bee;
      bStack_18 = DAT_00009bee;
      goto LAB_fffabaef;
    }
    if ((undefined2 *)0x1 < puVar3 + -3) {
      if (puVar3 + -4 < (undefined2 *)0x2) goto LAB_fffabab6;
      if ((undefined2 *)0x1 < puVar3 + -5) {
        if ((undefined2 *)0x1 < puVar3) {
          DAT_0000464a = 1;
          return puVar3;
        }
        pbStack_1c = &DAT_00009bec;
        bStack_18 = DAT_00009bec;
        goto LAB_fffabaef;
      }
    }
    pbStack_1c = &DAT_00009bef;
    bStack_18 = DAT_00009bef;
  }
LAB_fffabaef:
  if (param_2 == '\0') {
    bStack_17 = 100;
    for (bStack_16 = 0; bStack_16 < 3; bStack_16 = bStack_16 + 1) {
      bVar1 = bStack_18;
      if (bStack_17 != 0) {
        bVar1 = bStack_18 / bStack_17;
      }
      bStack_18 = bStack_18 - bVar1 * bStack_17;
      bStack_17 = bStack_17 / 10;
      uVar2 = nib2hex(bVar1);
      (&DAT_00001c90)[bStack_16] = uVar2;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return &DAT_00001c8e;
  }
  uStack_14 = 0;
  bStack_16 = 2;
  while( true ) {
    if (4 < bStack_16) {
      if ((undefined2 *)(uint)uStack_14 < (undefined2 *)0x65) {
        puVar3 = (undefined2 *)(uint)(byte)uStack_14;
        *pbStack_1c = (byte)uStack_14;
        if (DAT_00009ace == '\0') {
          DAT_00020cc6 = 0x25;
          FUN_fffc8cbb(0x25);
          puVar3 = (undefined2 *)FUN_fffc8d8c();
        }
        DAT_00020f10 = 1;
        return puVar3;
      }
      DAT_0000464a = 1;
      return (undefined2 *)(uint)uStack_14;
    }
    if ((*(byte *)((uint)bStack_16 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_16 + param_1))) {
      puStack_20 = (undefined2 *)0x1;
    }
    else {
      puStack_20 = (undefined2 *)0x0;
    }
    if (puStack_20 != (undefined2 *)0x0) break;
    uStack_14 = (*(byte *)((uint)bStack_16 + param_1) & 0xf) * in_stack_00000004 + uStack_14;
    bStack_16 = bStack_16 + 1;
  }
  DAT_0000464a = 1;
  return puStack_20;
}


// ===== cat_ML @ fffabbfa (683 bytes)

/* WARNING: Removing unreachable block (ram,0xfffabca5) */
/* WARNING: Removing unreachable block (ram,0xfffabdbc) */
/* WARNING: Removing unreachable block (ram,0xfffabdcc) */
/* WARNING: Removing unreachable block (ram,0xfffabde8) */
/* WARNING: Removing unreachable block (ram,0xfffabddc) */
/* WARNING: Removing unreachable block (ram,0xfffabe2e) */
/* WARNING: Removing unreachable block (ram,0xfffabe87) */
/* WARNING: Removing unreachable block (ram,0xfffabea2) */
/* WARNING: Removing unreachable block (ram,0xfffabe93) */
/* WARNING: Removing unreachable block (ram,0xfffabe44) */
/* WARNING: Removing unreachable block (ram,0xfffabd83) */
/* WARNING: Removing unreachable block (ram,0xfffabd49) */
/* WARNING: Removing unreachable block (ram,0xfffabcc0) */
/* WARNING: Removing unreachable block (ram,0xfffabd15) */
/* WARNING: Removing unreachable block (ram,0xfffabe9f) */
/* WARNING: Removing unreachable block (ram,0xfffabd8f) */

byte * cat_ML(int param_1,char param_2)

{
  byte extraout_R1;
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  char in_stack_00000014;
  byte *pbStack_20;
  byte *pbStack_1c;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  pbVar2 = (byte *)vfo_mode(0);
  pbVar1 = (byte *)(uint)extraout_R1;
  if (pbVar1 == (byte *)0xe) {
LAB_fffabc78:
    bStack_12 = DAT_00009bff;
    pbStack_1c = &DAT_00009bff;
  }
  else {
    pbVar2 = pbVar1 + -2;
    if (pbVar2 < (byte *)0x2) {
      bStack_12 = DAT_00009bfd;
      pbStack_1c = &DAT_00009bfd;
      goto LAB_fffabcc3;
    }
    pbVar2 = pbVar1 + -4;
    if (pbVar2 < (byte *)0x2) {
      bStack_12 = DAT_00009c00;
      pbStack_1c = &DAT_00009c00;
      goto LAB_fffabcc3;
    }
    pbVar2 = pbVar1 + -6;
    if ((byte *)0x1 < pbVar2) {
      pbVar2 = pbVar1 + -8;
      if (pbVar2 < (byte *)0x2) goto LAB_fffabc78;
      pbVar2 = pbVar1 + -10;
      if ((byte *)0x1 < pbVar2) {
        pbVar2 = pbVar1 + -0xc;
        if (pbVar2 < (byte *)0x2) {
          bStack_12 = DAT_00009bfe;
          pbStack_1c = &DAT_00009bfe;
        }
        else {
          if ((byte *)0x1 < pbVar1) {
            DAT_0000464a = 1;
            return pbVar1;
          }
          bStack_12 = DAT_00009bfc;
          pbStack_1c = &DAT_00009bfc;
        }
        goto LAB_fffabcc3;
      }
    }
    if (param_2 == '\x01') {
      DAT_0000464a = 1;
      return (byte *)0x1;
    }
    bStack_12 = bRam00009c01;
    pbStack_1c = (byte *)0x9c01;
  }
LAB_fffabcc3:
  if (*(char *)(param_1 + 2) == '0') {
    pbVar2[0] = 1;
    pbVar2[1] = 0;
    pbVar2[2] = 0;
    pbVar2[3] = 0;
  }
  if (param_2 == '\0') {
    if (pbVar2 != (byte *)0x0) {
      DAT_00001c91 = 0x30;
      DAT_00001c92 = 0x30;
      if ((byte *)(uint)bStack_12 == (byte *)0x0) {
        DAT_00001c93._0_1_ = 0x30;
      }
      else {
        DAT_00001c93._0_1_ = 0x31;
      }
      DAT_00001c93._1_1_ = 0x3b;
      DAT_0001b788 = 7;
      return (byte *)(uint)bStack_12;
    }
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return (byte *)0x0;
    }
    bStack_13 = 100;
    pbVar1 = (byte *)0x0;
    for (bStack_14 = 0; bStack_14 < 3; bStack_14 = bStack_14 + 1) {
      bVar3 = bStack_12;
      if (bStack_13 != 0) {
        bVar3 = bStack_12 / bStack_13;
      }
      bStack_12 = bStack_12 - bVar3 * bStack_13;
      bStack_13 = bStack_13 / 10;
      pbVar1 = (byte *)nib2hex(bVar3);
      (&DAT_00001c91)[bStack_14] = (char)pbVar1;
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return pbVar1;
  }
  if (pbVar2 != (byte *)0x0) {
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      pbStack_20 = (byte *)0x0;
    }
    else {
      pbStack_20 = (byte *)0x1;
    }
    if (pbStack_20 != (byte *)0x0) {
      DAT_0000464a = 1;
      return pbStack_20;
    }
    if (*(char *)(param_1 + 5) == '0') {
      *pbStack_1c = 0;
      return pbStack_1c;
    }
    if ((byte *)(uint)*(byte *)(param_1 + 5) == (byte *)0x31) {
      *pbStack_1c = 0x32;
      return pbStack_1c;
    }
    DAT_0000464a = 1;
    return (byte *)(uint)*(byte *)(param_1 + 5);
  }
  if ((byte *)(uint)*(byte *)(param_1 + 2) != (byte *)0x31) {
    DAT_0000464a = 1;
    return (byte *)(uint)*(byte *)(param_1 + 2);
  }
  bStack_12 = 0;
  for (bStack_14 = 3; bStack_14 < 6; bStack_14 = bStack_14 + 1) {
    if ((*(byte *)((uint)bStack_14 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_14 + param_1))) {
      pbStack_20 = (byte *)0x1;
    }
    else {
      pbStack_20 = (byte *)0x0;
    }
    if (pbStack_20 != (byte *)0x0) {
      DAT_0000464a = 1;
      return pbStack_20;
    }
    bStack_12 = (*(byte *)((uint)bStack_14 + param_1) & 0xf) * in_stack_00000014 + bStack_12;
  }
  if ((byte *)0x64 < (byte *)(uint)bStack_12) {
    DAT_0000464a = 1;
    return (byte *)(uint)bStack_12;
  }
  *pbStack_1c = bStack_12;
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x2d;
    FUN_fffc8cbb(0x2d);
    pbVar1 = (byte *)FUN_fffc8d8c();
    return pbVar1;
  }
  return (byte *)(uint)bStack_12;
}


// ===== cat_MR @ fffabea5 (992 bytes)

/* WARNING: Removing unreachable block (ram,0xfffac282) */
/* WARNING: Removing unreachable block (ram,0xfffac15c) */
/* WARNING: Removing unreachable block (ram,0xfffac01d) */
/* WARNING: Removing unreachable block (ram,0xfffabf20) */
/* WARNING: Removing unreachable block (ram,0xfffac0c4) */
/* WARNING: Removing unreachable block (ram,0xfffac102) */
/* WARNING: Removing unreachable block (ram,0xfffabf0a) */
/* WARNING: Removing unreachable block (ram,0xfffabf99) */
/* WARNING: Removing unreachable block (ram,0xfffabfb2) */
/* WARNING: Removing unreachable block (ram,0xfffac095) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * cat_MR(int param_1,undefined1 param_2)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  char in_stack_00000014;
  undefined2 *puStack_34;
  byte bStack_30;
  byte bStack_2e;
  undefined1 auStack_2d [9];
  byte bStack_24;
  byte bStack_22;
  byte bStack_21;
  ushort uStack_20;
  ushort uStack_1e;
  uint uStack_18;
  uint uStack_14;
  byte *pbStack_10;
  undefined1 local_9;
  int local_8;
  
  local_9 = param_2;
  local_8 = param_1;
  toupper_inplace();
  toupper_inplace();
  toupper_inplace();
  if (*(char *)(local_8 + 2) == '0') {
    bStack_24 = 0;
    bStack_22 = 100;
    for (bStack_21 = 2; bStack_21 < 5; bStack_21 = bStack_21 + 1) {
      if ((*(byte *)((uint)bStack_21 + local_8) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_21 + local_8))) {
        puStack_34 = (undefined2 *)0x1;
      }
      else {
        puStack_34 = (undefined2 *)0x0;
      }
      if (puStack_34 != (undefined2 *)0x0) {
        DAT_0000464a = 1;
        return puStack_34;
      }
      bStack_24 = (*(byte *)((uint)bStack_21 + local_8) & 0xf) * in_stack_00000014 + bStack_24;
      bStack_22 = bStack_22 / 10;
    }
    if ((bStack_24 == 0) || (99 < bStack_24)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      bStack_30 = bStack_24 - 1;
    }
  }
  else {
    bStack_30 = 0;
    for (bStack_22 = 0; bStack_22 < 0x22; bStack_22 = bStack_22 + 1) {
      iVar4 = FUN_fffede1d(&cat_pms_names + (uint)bStack_22 * 3,local_8 + 2,3);
      if (iVar4 == 0) {
        bStack_30 = bStack_22 + 99;
        break;
      }
    }
    if ((undefined2 *)(uint)bStack_30 < (undefined2 *)0x63) {
      DAT_0000464a = 1;
      return (undefined2 *)(uint)bStack_30;
    }
  }
  iVar4 = memch_valid(bStack_30);
  if (iVar4 == 0) {
    DAT_0000464a = 1;
    return (undefined2 *)0x0;
  }
  pbStack_10 = &DAT_00006150 + (uint)bStack_30 * 0x5a;
  if (DAT_00009dbd == '\0') {
    bStack_2e = DAT_00009dbe;
  }
  else {
    bStack_2e = DAT_00009dbf;
  }
  if (bStack_30 < 99) {
    bStack_30 = bStack_30 + 1;
    bStack_22 = 100;
    for (bStack_21 = 0; bStack_21 < 3; bStack_21 = bStack_21 + 1) {
      bStack_24 = bStack_30;
      if (bStack_22 != 0) {
        bStack_24 = bStack_30 / bStack_22;
      }
      bStack_30 = bStack_30 - bStack_24 * bStack_22;
      bStack_22 = bStack_22 / 10;
      uVar5 = (uint)bStack_21;
      uVar2 = nib2hex(bStack_24);
      (&DAT_00001c90)[uVar5] = uVar2;
    }
  }
  else {
    iVar4 = (uint)(byte)(bStack_30 + 0x9d) * 3;
    DAT_00001c92 = (&DAT_fff806eb)[iVar4];
    _DAT_00001c90 = *(undefined2 *)(&cat_pms_names + iVar4);
  }
  uStack_14 = 0;
  for (bStack_21 = 0; bStack_21 < 4; bStack_21 = bStack_21 + 1) {
    uStack_14 = (uint)pbStack_10[bStack_21 + 0x4a] | uStack_14 << 8;
  }
  if (uStack_14 != 0) {
    uStack_18 = 100000000;
    for (bStack_21 = 0; bStack_21 < 9; bStack_21 = bStack_21 + 1) {
      uVar5 = uStack_14;
      if (uStack_18 != 0) {
        uVar5 = uStack_14 / uStack_18;
      }
      auStack_2d[bStack_21] = (char)uVar5;
      uVar5 = uStack_14;
      if ((uStack_18 & 0xff) != 0) {
        uVar5 = uStack_14 / (uStack_18 & 0xff);
      }
      uStack_14 = uStack_14 - (uVar5 * uStack_18 & 0xff);
      uStack_18 = uStack_18 / 10;
    }
    for (bStack_21 = 0; bStack_21 < 9; bStack_21 = bStack_21 + 1) {
      uVar5 = (uint)bStack_21;
      uVar2 = nib2hex(auStack_2d[uVar5]);
      *(undefined1 *)((int)&DAT_00001c93 + uVar5) = uVar2;
    }
    uStack_1e = CONCAT11(pbStack_10[0x48],pbStack_10[0x49]);
    if ((pbStack_10[0x48] & 0x80) == 0) {
      DAT_00001c9c = 0x2b;
    }
    else {
      DAT_00001c9c = 0x2d;
      uStack_1e = ~uStack_1e + 1;
    }
    uStack_20 = 1000;
    for (bStack_21 = 0; bStack_21 < 4; bStack_21 = bStack_21 + 1) {
      uVar5 = (uint)uStack_1e;
      if (uStack_20 != 0) {
        uVar5 = uVar5 / uStack_20;
      }
      auStack_2d[bStack_21] = (char)uVar5;
      uVar6 = uStack_1e;
      if ((uStack_20 & 0xff) != 0) {
        uVar6 = (ushort)((uint)uStack_1e / (uStack_20 & 0xff));
      }
      uStack_1e = uStack_1e - (uVar6 * uStack_20 & 0xff);
      uStack_20 = uStack_20 / 10;
    }
    for (bStack_21 = 0; bStack_21 < 4; bStack_21 = bStack_21 + 1) {
      uVar5 = (uint)bStack_21;
      uVar2 = nib2hex(auStack_2d[uVar5]);
      (&DAT_00001c9d)[uVar5] = uVar2;
    }
    if ((pbStack_10[1] & 0x10) == 0) {
      DAT_00001ca1 = 0x30;
    }
    else {
      DAT_00001ca1 = 0x31;
    }
    if ((pbStack_10[1] & 8) == 0) {
      DAT_00001ca2 = 0x30;
    }
    else {
      DAT_00001ca2 = 0x31;
    }
    DAT_00001ca3 = (&cat_mode_codes)[*pbStack_10 & 0xf];
    DAT_00001ca4 = (&cat_vfo_state_codes)[bStack_2e];
    cVar3 = (char)((pbStack_10[3] & 0x38) >> 3);
    if (cVar3 == '\x01') {
      DAT_00001ca5 = 0x32;
    }
    else if (cVar3 == '\x02') {
      DAT_00001ca5 = 0x31;
    }
    else {
      DAT_00001ca5 = 0x30;
    }
    DAT_00001ca7 = 0x30;
    DAT_00001ca6 = 0x30;
    cVar3 = (char)((pbStack_10[2] & 0xc) >> 2);
    if (cVar3 == '\0') {
      DAT_00001ca8 = 0x32;
    }
    else if (cVar3 == '\x02') {
      DAT_00001ca8 = 0x31;
    }
    else {
      DAT_00001ca8 = 0x30;
    }
    DAT_00001ca9 = 0x3b;
    DAT_0001b788 = 0x1c;
    return &DAT_00001c8e;
  }
  DAT_0000464a = 1;
  return (undefined2 *)0x0;
}


// ===== cat_MT @ fffac285 (561 bytes)

/* WARNING: Removing unreachable block (ram,0xfffac2fe) */

void cat_MT(int param_1,char param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  char in_stack_0000001c;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  
  toupper_inplace();
  toupper_inplace();
  toupper_inplace();
  if (*(char *)(param_1 + 2) == '0') {
    bStack_f = 0;
    for (bStack_d = 2; bStack_d < 5; bStack_d = bStack_d + 1) {
      if ((*(byte *)((uint)bStack_d + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_d + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      bStack_f = (*(byte *)((uint)bStack_d + param_1) & 0xf) * in_stack_0000001c + bStack_f;
    }
    if ((bStack_f == 0) || (99 < bStack_f)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    bStack_10 = bStack_f - 1;
  }
  else {
    for (bStack_e = 0; bStack_e < 0x22; bStack_e = bStack_e + 1) {
      iVar2 = FUN_fffede1d(&cat_pms_names + (uint)bStack_e * 3,param_1 + 2,3);
      if (iVar2 == 0) {
        bStack_10 = bStack_e + 99;
        break;
      }
    }
    if (bStack_10 < 99) {
      DAT_0000464a = 1;
      return;
    }
    if (0x75 < bStack_10) {
      DAT_0000464a = 1;
      return;
    }
  }
  iVar2 = memch_valid(bStack_10);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  iVar2 = (uint)bStack_10 * 0x5a;
  if (param_2 != '\0') {
    if (*(char *)(param_1 + 5) == '0') {
      (&DAT_00006155)[iVar2] = (&DAT_00006155)[iVar2] & 0x7f;
    }
    else {
      if (*(char *)(param_1 + 5) != '1') {
        DAT_0000464a = 1;
        return;
      }
      (&DAT_00006155)[iVar2] = (&DAT_00006155)[iVar2] | 0x80;
    }
    bStack_e = 0;
    while( true ) {
      if ((byte)(param_3 - 7U) <= bStack_e) {
        for (; bStack_e < 0xc; bStack_e = bStack_e + 1) {
          (&DAT_00006150)[(uint)bStack_e + iVar2 + 0x4e] = 0x20;
        }
        eeprom_save_memch(bStack_10);
        return;
      }
      if ((*(byte *)((uint)bStack_e + param_1 + 6) < 0x20) ||
         (0x7d < *(byte *)((uint)bStack_e + param_1 + 6))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
      (&DAT_00006150)[(uint)bStack_e + iVar2 + 0x4e] = *(undefined1 *)((uint)bStack_e + param_1 + 6)
      ;
      bStack_e = bStack_e + 1;
    }
    DAT_0000464a = 1;
    return;
  }
  if (((&DAT_00006155)[iVar2] & 0x80) == 0) {
    DAT_00001c93._0_1_ = 0x30;
  }
  else {
    DAT_00001c93._0_1_ = 0x31;
  }
  for (bStack_e = 0; bStack_e < 0xc; bStack_e = bStack_e + 1) {
    *(undefined1 *)((int)&DAT_00001c93 + bStack_e + 1) =
         (&DAT_00006150)[(uint)bStack_e + iVar2 + 0x4e];
  }
  DAT_00001ca0 = 0x3b;
  DAT_0001b788 = 0x13;
  return;
}


// ===== cat_MS @ fffac4b6 (126 bytes)

void cat_MS(int param_1,char param_2)

{
  byte bVar1;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(DAT_00009c5b);
    DAT_00001c91 = 0x30;
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    bVar1 = hex2nib(*(undefined1 *)(param_1 + 2));
    if (5 < bVar1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009c5b = bVar1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_MW @ fffac534 (1145 bytes)

/* WARNING: Removing unreachable block (ram,0xfffac79c) */
/* WARNING: Removing unreachable block (ram,0xfffac700) */
/* WARNING: Removing unreachable block (ram,0xfffac5e5) */
/* WARNING: Removing unreachable block (ram,0xfffac8bb) */
/* WARNING: Removing unreachable block (ram,0xfffac91b) */

void cat_MW(int param_1,undefined1 param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  char in_stack_0000001c;
  byte local_21 [6];
  byte bStack_1b;
  byte bStack_1a;
  byte bStack_19;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  uint uStack_10;
  byte *pbStack_c;
  undefined1 local_5;
  int local_4;
  
  local_21[0] = 0;
  local_21[1] = 0;
  local_21[2] = 0;
  local_21[3] = 0;
  local_5 = param_2;
  local_4 = param_1;
  toupper_inplace();
  toupper_inplace();
  toupper_inplace();
  local_21[5] = DAT_00009dbd;
  if (*(char *)(local_4 + 2) == '0') {
    bStack_1b = 0;
    bStack_1a = 100;
    for (bStack_19 = 2; bStack_19 < 5; bStack_19 = bStack_19 + 1) {
      if ((*(byte *)((uint)bStack_19 + local_4) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_19 + local_4))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      bStack_1b = (*(byte *)((uint)bStack_19 + local_4) & 0xf) * in_stack_0000001c + bStack_1b;
      bStack_1a = bStack_1a / 10;
    }
    if ((bStack_1b == 0) || (99 < bStack_1b)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_21[4] = bStack_1b - 1;
  }
  else {
    local_21[4] = 0;
    for (bStack_1a = 0; bStack_1a < 0x22; bStack_1a = bStack_1a + 1) {
      iVar4 = FUN_fffede1d(&cat_pms_names + (uint)bStack_1a * 3,local_4 + 2,3);
      if (iVar4 == 0) {
        local_21[4] = bStack_1a + 99;
        break;
      }
    }
    if (local_21[4] < 99) {
      DAT_0000464a = 1;
      return;
    }
    if (0x75 < local_21[4]) {
      DAT_0000464a = 1;
      return;
    }
  }
  if (local_21[5] == '\0') {
    DAT_000060c9 = local_21[4];
  }
  else {
    DAT_000060ca = local_21[4];
  }
  pbStack_c = &DAT_00006150 + (uint)local_21[4] * 0x5a;
  uStack_10 = 0;
  uStack_14 = 100000000;
  for (bStack_19 = 5; bStack_19 < 0xe; bStack_19 = bStack_19 + 1) {
    bStack_1b = *(byte *)((uint)bStack_19 + local_4);
    if ((bStack_1b < 0x30) || (0x39 < bStack_1b)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    uStack_10 = (*(byte *)((uint)bStack_19 + local_4) & 0xf) * uStack_14 + uStack_10;
    uStack_14 = uStack_14 / 10;
  }
  iVar4 = freq_in_range(uStack_10);
  if (iVar4 == 0) {
    DAT_0000464a = 1;
    return;
  }
  for (bStack_19 = 0; bStack_19 < 4; bStack_19 = bStack_19 + 1) {
    local_21[bStack_19] = (byte)(uStack_10 >> ((3 - bStack_19 & 3) << 3));
  }
  uStack_18 = 1000;
  for (bStack_19 = 0xf; bStack_19 < 0x13; bStack_19 = bStack_19 + 1) {
    if ((*(byte *)((uint)bStack_19 + local_4) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_19 + local_4))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    uStack_18 = uStack_18 / 10;
  }
  if ((*(char *)(local_4 + 0xe) != '-') && (*(char *)(local_4 + 0xe) != '+')) {
    DAT_0000464a = 1;
    return;
  }
  uStack_16 = 0;
  if ((*(char *)(local_4 + 0x13) != '0') && (*(char *)(local_4 + 0x13) != '1')) {
    DAT_0000464a = 1;
    return;
  }
  if ((*(char *)(local_4 + 0x14) != '0') && (*(char *)(local_4 + 0x14) != '1')) {
    DAT_0000464a = 1;
    return;
  }
  bStack_1b = 0xff;
  bStack_19 = 0;
  do {
    if (0xe < bStack_19) {
LAB_fffac85b:
      bVar2 = bStack_1b;
      if (bStack_1b == 0xff) {
        DAT_0000464a = 1;
        return;
      }
      if (*(char *)(local_4 + 0x16) != '1') {
        DAT_0000464a = 1;
        return;
      }
      if (*(char *)(local_4 + 0x17) == '2') {
        bStack_1b = '\x01';
      }
      else if (*(char *)(local_4 + 0x17) == '1') {
        bStack_1b = '\x02';
      }
      else {
        if (*(char *)(local_4 + 0x17) != '0') {
          DAT_0000464a = 1;
          return;
        }
        bStack_1b = '\0';
      }
      bVar3 = bStack_1b << 3;
      if ((*(char *)(local_4 + 0x18) == '0') && (*(char *)(local_4 + 0x19) == '0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        if (*(char *)(local_4 + 0x1a) == '2') {
          bStack_1b = '\0';
        }
        else if (*(char *)(local_4 + 0x1a) == '1') {
          bStack_1b = '\x02';
        }
        else {
          if (*(char *)(local_4 + 0x1a) != '0') {
            DAT_0000464a = 1;
            return;
          }
          bStack_1b = '\x01';
        }
        pbStack_c[0x4a] = local_21[0];
        pbStack_c[0x4b] = local_21[1];
        pbStack_c[0x4c] = local_21[2];
        pbStack_c[0x4d] = local_21[3];
        pbStack_c[0x48] = 0;
        pbStack_c[0x49] = 0;
        pbStack_c[1] = pbStack_c[1] & 0xe7;
        pbStack_c[1] = pbStack_c[1];
        *pbStack_c = *pbStack_c & 0xf0;
        *pbStack_c = *pbStack_c | bVar2;
        pbStack_c[3] = pbStack_c[3] & 199;
        pbStack_c[3] = pbStack_c[3] | bVar3;
        pbStack_c[2] = pbStack_c[2] & 0xf3;
        pbStack_c[2] = pbStack_c[2] | bStack_1b << 2;
        FUN_fffb01df(local_21[4]);
        eeprom_save_memch(local_21[4]);
        vfo_mark_edited(local_21[5]);
        vfo_store_back(local_21[5]);
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    if (*(char *)(local_4 + 0x15) == (&cat_mode_codes)[bStack_19]) {
      bStack_1b = bStack_19;
      goto LAB_fffac85b;
    }
    bStack_19 = bStack_19 + 1;
  } while( true );
}


// ===== cat_MX @ fffac9ad (154 bytes)

void cat_MX(int param_1,char param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = DAT_00020b2c;
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(DAT_00020b2c);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  iVar3 = key_event_filter(0x302,2);
  if (iVar3 == 0) {
    DAT_0000464a = 1;
    return;
  }
  cVar2 = hex2nib(*(undefined1 *)(param_1 + 2));
  if (cVar2 == '\0') {
    if (cVar1 != '\0') {
      FUN_fffbe7e7();
      FUN_fffbe83f();
      return;
    }
  }
  else {
    if (cVar2 != '\x01') {
      DAT_0000464a = 1;
      return;
    }
    if (cVar1 == '\0') {
      FUN_fffbe8d2();
      return;
    }
  }
  return;
}


// ===== cat_NA @ fffaca47 (542 bytes)

void cat_NA(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  byte bStack_15;
  byte *pbStack_14;
  
  vfo_rec_ptr(0);
  cVar2 = DAT_00009dbd;
  uVar3 = vfo_mode(DAT_00009dbd);
  bVar1 = false;
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 == '\0') {
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
  }
  else {
    iVar4 = key_event_filter(0x30d,0);
    if (iVar4 == 0) {
      DAT_0000464a = 1;
      return;
    }
    if (0x31 < *(byte *)(param_1 + 3)) {
      DAT_0000464a = 1;
      return;
    }
  }
  if (cVar2 == '\0') {
    pbStack_14 = &DAT_00009d0d;
  }
  else {
    pbStack_14 = &DAT_00009d67;
  }
  switch(uVar3) {
  case 0:
  case 1:
    bVar1 = true;
    bStack_15 = 0x80;
    break;
  case 2:
  case 3:
    bVar1 = true;
    bStack_15 = 0x20;
    break;
  case 4:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x30;
    }
    else if (*(char *)(param_1 + 3) == '1') {
      FUN_fffc4bd5(5);
    }
    break;
  case 5:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x31;
    }
    else if (*(char *)(param_1 + 3) == '0') {
      FUN_fffc4bd5(4);
    }
    break;
  case 6:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x30;
    }
    else if (*(char *)(param_1 + 3) == '1') {
      FUN_fffc4bd5(7);
    }
    break;
  case 7:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x31;
    }
    else if (*(char *)(param_1 + 3) == '0') {
      FUN_fffc4bd5(6);
    }
    break;
  case 8:
  case 9:
  case 0xe:
    bVar1 = true;
    bStack_15 = 4;
    break;
  case 10:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x30;
    }
    else if (*(char *)(param_1 + 3) == '1') {
      FUN_fffc4bd5(0xb);
    }
    break;
  case 0xb:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x31;
    }
    else if (*(char *)(param_1 + 3) == '0') {
      FUN_fffc4bd5(10);
    }
    break;
  case 0xc:
  case 0xd:
    bVar1 = true;
    bStack_15 = 8;
  }
  if (bVar1) {
    if (param_2 == '\0') {
      if ((*pbStack_14 & bStack_15) == 0) {
        DAT_00001c91 = 0x30;
      }
      else {
        DAT_00001c91 = 0x31;
      }
    }
    else if (*(char *)(param_1 + 3) == '0') {
      if ((*pbStack_14 & bStack_15) != 0) {
        *pbStack_14 = ~bStack_15 & *pbStack_14;
      }
    }
    else if ((*pbStack_14 & bStack_15) == 0) {
      *pbStack_14 = *pbStack_14 | bStack_15;
    }
  }
  vfo_mark_edited(cVar2);
  vfo_store_back(cVar2);
  DAT_00020f10 = 1;
  return;
}


// ===== cat_NB @ fffacc65 (131 bytes)

void cat_NB(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = vfo_rec_ptr(0);
  if (param_2 == '\0') {
    DAT_00001c91 = nib2hex((*(byte *)(iVar1 + 2) & 2) >> 1);
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  iVar2 = key_event_filter(0x303,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0xfd;
    return;
  }
  if (*(char *)(param_1 + 3) != '1') {
    DAT_0000464a = 1;
    return;
  }
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) | 2;
  return;
}


// ===== cat_NL @ fffacce8 (313 bytes)

/* WARNING: Removing unreachable block (ram,0xfffacdb2) */
/* WARNING: Removing unreachable block (ram,0xfffacd03) */
/* WARNING: Removing unreachable block (ram,0xffface0f) */
/* WARNING: Removing unreachable block (ram,0xfffacdc8) */
/* WARNING: Removing unreachable block (ram,0xffface1b) */
/* WARNING: Removing unreachable block (ram,0xfffacd76) */
/* WARNING: Removing unreachable block (ram,0xfffacd41) */
/* WARNING: Removing unreachable block (ram,0xffface1e) */

undefined2 * cat_NL(int param_1,char param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  char in_stack_00000010;
  undefined2 *local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  
  if ((undefined2 *)(uint)*(byte *)(param_1 + 2) != (undefined2 *)0x30) {
    DAT_0000464a = 1;
    return (undefined2 *)(uint)*(byte *)(param_1 + 2);
  }
  if (param_2 == '\0') {
    local_b = 10;
    local_d = DAT_00009dc0;
    DAT_00001c91 = 0x30;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      uVar1 = nib2hex(bVar3);
      (&DAT_00001c92)[local_c] = uVar1;
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return &DAT_00001c8e;
  }
  local_a = 0;
  for (local_c = 4; local_c < 6; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      local_14 = (undefined2 *)0x1;
    }
    else {
      local_14 = (undefined2 *)0x0;
    }
    if (local_14 != (undefined2 *)0x0) {
      DAT_0000464a = 1;
      return local_14;
    }
    local_a = (*(byte *)((uint)local_c + param_1) & 0xf) * in_stack_00000010 + local_a;
  }
  puVar2 = (undefined2 *)(uint)local_a;
  if ((undefined2 *)0xa < puVar2) {
    DAT_0000464a = 1;
    return puVar2;
  }
  DAT_00009dc0 = local_a;
  if (DAT_00009ace != '\0') {
    return puVar2;
  }
  DAT_00020cc6 = 0x38;
  FUN_fffc8cbb(0x38);
  puVar2 = (undefined2 *)FUN_fffc8d8c();
  return puVar2;
}


// ===== cat_NR @ ffface21 (157 bytes)

void cat_NR(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = vfo_rec_ptr(0);
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 == '\0') {
    if ((*(byte *)(iVar1 + 6) & 0x10) == 0) {
      DAT_00001c91 = 0x30;
    }
    else {
      DAT_00001c91 = 0x31;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  iVar2 = key_event_filter(0x304,0);
  if (iVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 3) != '1') {
    if (*(char *)(param_1 + 3) != '0') {
      DAT_0000464a = 1;
      return;
    }
    *(byte *)(iVar1 + 6) = *(byte *)(iVar1 + 6) & 0xef;
    return;
  }
  *(byte *)(iVar1 + 6) = *(byte *)(iVar1 + 6) | 0x10;
  return;
}


// ===== cat_OS @ fffacebe (323 bytes)

/* WARNING: Removing unreachable block (ram,0xfffacfeb) */

void cat_OS(int param_1,char param_2)

{
  byte bVar1;
  char cVar2;
  char cStack_d;
  undefined1 *puStack_c;
  
  bVar1 = vfo_mode(0);
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      puStack_c = &DAT_00009d09;
    }
    else {
      puStack_c = &DAT_00009d63;
    }
  }
  else if (*(char *)(param_1 + 2) == '1') {
    if (DAT_00009dbd == '\0') {
      puStack_c = &DAT_00009d63;
    }
    else {
      puStack_c = &DAT_00009d09;
    }
  }
  if (param_2 == '\0') {
    cVar2 = (char)(((byte)puStack_c[2] & 0xc) >> 2);
    if (cVar2 == '\0') {
      DAT_00001c91 = 0x32;
    }
    else if (cVar2 == '\x02') {
      DAT_00001c91 = 0x31;
    }
    else {
      DAT_00001c91 = 0x30;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_0000464a = 1;
    return;
  }
  if ((1 < bVar1 - 6) && (1 < bVar1 - 10)) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '2') {
    cStack_d = '\0';
  }
  else if (*(char *)(param_1 + 3) == '1') {
    cStack_d = '\x02';
  }
  else {
    if (*(char *)(param_1 + 3) != '0') {
      DAT_0000464a = 1;
      return;
    }
    cStack_d = '\x01';
  }
  puStack_c[2] = puStack_c[2] & 0xf3;
  puStack_c[2] = cStack_d << 2 | puStack_c[2];
  DAT_00020f10 = 1;
  return;
}


// ===== cat_PA @ fffad001 (161 bytes)

void cat_PA(int param_1,char param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined1 uStack_d;
  
  iVar3 = vfo_rec_ptr(0);
  if (param_2 == '\0') {
    bVar2 = *(byte *)(iVar3 + 5) & 3;
    if (bVar2 == 2) {
      uStack_d = 0x31;
    }
    else if (bVar2 == 3) {
      uStack_d = 0x32;
    }
    else {
      uStack_d = 0x30;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c91 = uStack_d;
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  cVar1 = *(char *)(param_1 + 3);
  if (cVar1 == '0') {
    uStack_d = 0;
  }
  else if (cVar1 == '1') {
    uStack_d = 2;
  }
  else {
    if (cVar1 != '2') {
      DAT_0000464a = 1;
      return;
    }
    uStack_d = 3;
  }
  *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) & 0xfc;
  *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) | uStack_d;
  return;
}


// ===== cat_PB @ fffad0a2 (415 bytes)

void cat_PB(int param_1,char param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 == '\0') {
    if (DAT_00020b7c == '\x01') {
      DAT_00001c91 = nib2hex(DAT_00020b7d + '\x01');
    }
    else {
      DAT_00001c91 = 0x30;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  iVar1 = key_event_filter(0x87,0);
  if (iVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  iVar1 = FUN_fffe56bf();
  if (iVar1 != 1) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00020b97 == '\x01') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    DAT_00020b7c = 0;
    DAT_00020f1b = 0;
    DAT_00020cce = 0;
    if (DAT_00020b2e == '\x01') {
      DAT_00020b2e = 0;
      return;
    }
  }
  else {
    if (0x35 < *(byte *)(param_1 + 3)) {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00020b7c == '\0') {
      DAT_00020b7c = 1;
      DAT_00020ccc = hex2nib(*(undefined1 *)(param_1 + 3));
      DAT_00020b7d = DAT_00020ccc + -1;
      iVar1 = FUN_fffb521a();
      if (iVar1 == 1) {
        DAT_00020b2e = '\x01';
      }
      DAT_00020cd3 = 1;
      DAT_00020cd4 = 0;
      return;
    }
    DAT_00020b7c = 0;
    DAT_00020f1b = 0;
    DAT_00020cce = 0;
    if (DAT_00020b2e == '\x01') {
      DAT_00020b2e = 0;
      return;
    }
  }
  DAT_00020f1b = 0;
  DAT_00020cce = 0;
  DAT_00020b7c = 0;
  return;
}


// ===== cat_PC @ fffad241 (550 bytes)

/* WARNING: Removing unreachable block (ram,0xfffad34b) */
/* WARNING: Removing unreachable block (ram,0xfffad43a) */
/* WARNING: Removing unreachable block (ram,0xfffad39c) */
/* WARNING: Removing unreachable block (ram,0xfffad464) */
/* WARNING: Removing unreachable block (ram,0xfffad461) */
/* WARNING: Removing unreachable block (ram,0xfffad386) */
/* WARNING: Removing unreachable block (ram,0xfffad316) */
/* WARNING: Removing unreachable block (ram,0xfffad403) */

byte * cat_PC(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  char extraout_R1;
  undefined1 uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte bVar6;
  uint *puVar7;
  char in_stack_00000004;
  byte *pbStack_28;
  byte *pbStack_24;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte bStack_1c;
  
  uVar4 = vfo_freq(0,2);
  cVar2 = vfo_mode(0);
  puVar7 = (uint *)FUN_fffb3371(uVar4);
  if ((cVar2 == '\x04') || (cVar2 == '\x05')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    pbStack_24 = &DAT_00009bfb;
    bStack_1e = DAT_00009bfb;
    bStack_1f = DAT_00009af1;
  }
  else if (extraout_R1 == '\t') {
    pbStack_24 = &DAT_00009bf9;
    bStack_1e = DAT_00009bf9;
    bStack_1f = DAT_00009aef;
  }
  else if (extraout_R1 == '\n') {
    pbStack_24 = &DAT_00009bfa;
    bStack_1e = DAT_00009bfa;
    bStack_1f = DAT_00009af0;
  }
  else {
    pbStack_24 = &DAT_00009bf8;
    bStack_1e = DAT_00009bf8;
    bStack_1f = DAT_00009aee;
  }
  if (param_2 == '\0') {
    bStack_1d = 100;
    for (bStack_1c = 0; bStack_1c < 3; bStack_1c = bStack_1c + 1) {
      bVar6 = bStack_1e;
      if (bStack_1d != 0) {
        bVar6 = bStack_1e / bStack_1d;
      }
      bStack_1e = bStack_1e - bVar6 * bStack_1d;
      bStack_1d = bStack_1d / 10;
      uVar3 = nib2hex(bVar6);
      (&DAT_00001c90)[bStack_1c] = uVar3;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return (byte *)&DAT_00001c8e;
  }
  bStack_1e = 0;
  for (bStack_1c = 2; bStack_1c < 5; bStack_1c = bStack_1c + 1) {
    if ((*(byte *)((uint)bStack_1c + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_1c + param_1))) {
      pbStack_28 = (byte *)0x1;
    }
    else {
      pbStack_28 = (byte *)0x0;
    }
    if (pbStack_28 != (byte *)0x0) {
      DAT_0000464a = 1;
      return pbStack_28;
    }
    bStack_1e = (*(byte *)((uint)bStack_1c + param_1) & 0xf) * in_stack_00000004 + bStack_1e;
  }
  if ((cVar2 == '\x04') || (cVar2 == '\x05')) {
    pbStack_28 = (byte *)0x1;
  }
  else {
    pbStack_28 = (byte *)0x0;
  }
  if (4 < bStack_1e) {
    *puVar7 = (uint)(4 < bStack_1e);
  }
  if (pbStack_28 == (byte *)0x0) {
    if ((puVar7 == (uint *)0x0) || (100 < bStack_1e)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return (byte *)0x0;
    }
    if (bStack_1f < bStack_1e) {
      bStack_1e = bStack_1f;
    }
    *pbStack_24 = bStack_1e;
    pbStack_24 = (byte *)(uint)bStack_1e;
  }
  else {
    if ((puVar7 == (uint *)0x0) || (0x19 < bStack_1e)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return pbStack_28;
    }
    if (bStack_1f < bStack_1e) {
      bStack_1e = bStack_1f;
    }
    *pbStack_24 = bStack_1e;
  }
  if (DAT_00009ace != '\0') {
    return pbStack_24;
  }
  DAT_00020cc6 = 0x2c;
  FUN_fffc8cbb(0x2c);
  pbVar5 = (byte *)FUN_fffc8d8c();
  return pbVar5;
}

