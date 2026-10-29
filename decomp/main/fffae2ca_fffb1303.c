// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== cat_SH @ fffae2ca (897 bytes)

/* WARNING: Removing unreachable block (ram,0xfffae499) */
/* WARNING: Removing unreachable block (ram,0xfffae402) */
/* WARNING: Removing unreachable block (ram,0xfffae5c0) */
/* WARNING: Removing unreachable block (ram,0xfffae648) */
/* WARNING: Removing unreachable block (ram,0xfffae606) */
/* WARNING: Removing unreachable block (ram,0xfffae4af) */
/* WARNING: Removing unreachable block (ram,0xfffae554) */
/* WARNING: Removing unreachable block (ram,0xfffae5cc) */
/* WARNING: Removing unreachable block (ram,0xfffae51c) */
/* WARNING: Removing unreachable block (ram,0xfffae58a) */
/* WARNING: Removing unreachable block (ram,0xfffae2f5) */
/* WARNING: Removing unreachable block (ram,0xfffae45e) */
/* WARNING: Removing unreachable block (ram,0xfffae449) */
/* WARNING: Removing unreachable block (ram,0xfffae37f) */
/* WARNING: Removing unreachable block (ram,0xfffae31e) */
/* WARNING: Removing unreachable block (ram,0xfffae350) */
/* WARNING: Removing unreachable block (ram,0xfffae3af) */

void cat_SH(int param_1,char param_2)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  byte *pbStack_1c;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  ushort uStack_12;
  
  pbStack_1c = vfo_rec_ptr(0);
  bVar3 = vfo_mode(0);
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 == '\0') {
    switch(bVar3) {
    case 0:
    case 1:
      cVar4 = FUN_fffb36ff(bVar3,CONCAT11(pbStack_1c[0x10],pbStack_1c[0x11]));
      bStack_17 = cVar4 + 1;
      if (0x17 < bStack_17) {
        bStack_17 = 0;
      }
      break;
    case 2:
    case 3:
      cVar4 = FUN_fffb36ff(bVar3,CONCAT11(pbStack_1c[0x1a],pbStack_1c[0x1b]));
      bStack_17 = cVar4 + 1;
      if (0x15 < bStack_17) {
        bStack_17 = 0;
      }
      break;
    case 4:
    case 7:
    case 0xb:
      bStack_17 = 2;
      break;
    case 5:
      bStack_17 = 1;
      break;
    case 6:
    case 10:
      bStack_17 = 3;
      break;
    case 8:
    case 9:
    case 0xe:
      cVar4 = FUN_fffb36ff(bVar3,CONCAT11(pbStack_1c[0x2e],pbStack_1c[0x2f]));
      bStack_17 = cVar4 + 1;
      if (0x15 < bStack_17) {
        bStack_17 = 0;
      }
      break;
    case 0xc:
    case 0xd:
      cVar4 = FUN_fffb36ff(bVar3,CONCAT11(pbStack_1c[0x24],pbStack_1c[0x25]));
      bStack_17 = cVar4 + 1;
      if (0x15 < bStack_17) {
        bStack_17 = 0;
      }
    }
    bStack_15 = 10;
    for (bStack_16 = 0; bStack_16 < 2; bStack_16 = bStack_16 + 1) {
      bVar3 = bStack_17;
      if (bStack_15 != 0) {
        bVar3 = bStack_17 / bStack_15;
      }
      bStack_17 = bStack_17 - bVar3 * bStack_15;
      bStack_15 = bStack_15 / 10;
      cVar4 = nib2hex(bVar3);
      (&DAT_00001c92)[bStack_16] = cVar4;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c91 = 0x30;
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  if (*(char *)(param_1 + 3) != '0') {
    DAT_0000464a = 1;
    return;
  }
  bStack_17 = 0;
  bStack_15 = 10;
  for (bStack_16 = 4; bStack_16 < 6; bStack_16 = bStack_16 + 1) {
    if ((*(byte *)((uint)bStack_16 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_16 + param_1))) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      DAT_0000464a = 1;
      return;
    }
    bStack_17 = (*(byte *)((uint)bStack_16 + param_1) & 0xf) * bStack_15 + bStack_17;
    bStack_15 = bStack_15 / 10;
  }
  uVar1 = (uint)bVar3;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      pbStack_1c = pbStack_1c + 0x1a;
      if (bStack_17 == 0) {
        uStack_12 = 500;
      }
      else {
        if (0x15 < bStack_17) {
          DAT_0000464a = 1;
          return;
        }
        uStack_12 = FUN_fffb3775(bVar3,bStack_17 - 1);
      }
      goto LAB_fffae5cf;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        pbStack_1c = pbStack_1c + 0x24;
        if (bStack_17 == 0) {
          uStack_12 = 500;
        }
        else {
          if (0x15 < bStack_17) {
            DAT_0000464a = 1;
            return;
          }
          uStack_12 = FUN_fffb3775(bVar3,bStack_17 - 1);
        }
      }
      else {
        if (1 < uVar1) {
          DAT_0000464a = 1;
          return;
        }
        pbStack_1c = pbStack_1c + 0x10;
        if (bStack_17 == 0) {
          uStack_12 = 3000;
        }
        else {
          if (0x17 < bStack_17) {
            DAT_0000464a = 1;
            return;
          }
          uStack_12 = FUN_fffb3775(bVar3,bStack_17 - 1);
        }
      }
      goto LAB_fffae5cf;
    }
  }
  pbStack_1c = pbStack_1c + 0x2e;
  if (bStack_17 == 0) {
    uStack_12 = 0xc80;
  }
  else {
    if (0x15 < bStack_17) {
      DAT_0000464a = 1;
      return;
    }
    uStack_12 = FUN_fffb3775(bVar3,bStack_17 - 1);
  }
LAB_fffae5cf:
  if (uStack_12 == 0xffff) {
    DAT_0000464a = 1;
    return;
  }
  for (bStack_16 = 0; bStack_16 < 2; bStack_16 = bStack_16 + 1) {
    pbStack_1c[bStack_16] = (byte)(uStack_12 >> ((1 - bStack_16 & 3) << 3));
  }
  DAT_00020b7e = 0x1e;
  DAT_00020b77 = 1;
  FUN_fffc89b0();
  DAT_00020f10 = 1;
  vfo_mark_edited(DAT_00009dbd);
  vfo_store_back(DAT_00009dbd);
  return;
}


// ===== cat_SM @ fffae64b (129 bytes)

/* WARNING: Removing unreachable block (ram,0xfffae661) */
/* WARNING: Removing unreachable block (ram,0xfffae68b) */
/* WARNING: Removing unreachable block (ram,0xfffae6c9) */

void cat_SM(int param_1)

{
  char cVar1;
  byte n;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  
  if (*(char *)(param_1 + 2) == '0') {
    bStack_c = meter_get_s();
    bStack_a = 100;
    for (bStack_b = 0; bStack_b < 3; bStack_b = bStack_b + 1) {
      n = bStack_c;
      if (bStack_a != 0) {
        n = bStack_c / bStack_a;
      }
      bStack_c = bStack_c - n * bStack_a;
      bStack_a = bStack_a / 10;
      cVar1 = nib2hex(n);
      (&DAT_00001c91)[bStack_b] = cVar1;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_SQ @ fffae6cc (388 bytes)

/* WARNING: Removing unreachable block (ram,0xfffae7bd) */
/* WARNING: Removing unreachable block (ram,0xfffae782) */
/* WARNING: Removing unreachable block (ram,0xfffae841) */
/* WARNING: Removing unreachable block (ram,0xfffae84d) */
/* WARNING: Removing unreachable block (ram,0xfffae7d3) */
/* WARNING: Removing unreachable block (ram,0xfffae836) */
/* WARNING: Removing unreachable block (ram,0xfffae744) */

void cat_SQ(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  float local_14;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    bVar3 = DAT_00020ba7;
    if (DAT_00009ab6 == '\0') {
      bVar3 = DAT_0000464e;
    }
    local_14 = (float)bVar3;
    local_d = SUB41(ROUND((local_14 * 100.0) / 255.0 + 0.5),0);
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(bVar3);
      (&DAT_00001c91)[local_c] = cVar2;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  local_d = 0;
  local_b = 100;
  for (local_c = 3; local_c < 6; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
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
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (100 < local_d) {
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464e = SUB41(ROUND(((float)local_d * 255.0) / 100.0 + 0.5),0);
  if (DAT_00009ab6 != '\0') {
    DAT_00020ba7 = DAT_0000464e;
    return;
  }
  return;
}


// ===== cat_SS @ fffae850 (2917 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaf243) */
/* WARNING: Removing unreachable block (ram,0xfffae86b) */
/* WARNING: Removing unreachable block (ram,0xfffaec73) */
/* WARNING: Removing unreachable block (ram,0xfffaec96) */
/* WARNING: Removing unreachable block (ram,0xfffaecae) */
/* WARNING: Removing unreachable block (ram,0xfffaeca2) */
/* WARNING: Removing unreachable block (ram,0xfffaed06) */
/* WARNING: Removing unreachable block (ram,0xfffaed30) */
/* WARNING: Removing unreachable block (ram,0xfffaed24) */
/* WARNING: Removing unreachable block (ram,0xfffaed88) */
/* WARNING: Removing unreachable block (ram,0xfffaedb2) */
/* WARNING: Removing unreachable block (ram,0xfffaeda6) */
/* WARNING: Removing unreachable block (ram,0xfffaee0a) */
/* WARNING: Removing unreachable block (ram,0xfffaee34) */
/* WARNING: Removing unreachable block (ram,0xfffaee28) */
/* WARNING: Removing unreachable block (ram,0xfffaee96) */
/* WARNING: Removing unreachable block (ram,0xfffaef84) */
/* WARNING: Removing unreachable block (ram,0xfffaef8d) */
/* WARNING: Removing unreachable block (ram,0xfffaeeac) */
/* WARNING: Removing unreachable block (ram,0xfffaef39) */
/* WARNING: Removing unreachable block (ram,0xfffaf277) */
/* WARNING: Removing unreachable block (ram,0xfffaf2ae) */
/* WARNING: Removing unreachable block (ram,0xfffaf2d9) */
/* WARNING: Removing unreachable block (ram,0xfffaf324) */
/* WARNING: Removing unreachable block (ram,0xfffaf39a) */
/* WARNING: Removing unreachable block (ram,0xfffaf3a6) */
/* WARNING: Removing unreachable block (ram,0xfffaf37c) */
/* WARNING: Removing unreachable block (ram,0xfffaf3b2) */
/* WARNING: Removing unreachable block (ram,0xfffaf21b) */
/* WARNING: Removing unreachable block (ram,0xfffaf20f) */
/* WARNING: Removing unreachable block (ram,0xfffaf1e0) */
/* WARNING: Removing unreachable block (ram,0xfffaf1b1) */
/* WARNING: Removing unreachable block (ram,0xfffaf1a5) */
/* WARNING: Removing unreachable block (ram,0xfffaf176) */
/* WARNING: Removing unreachable block (ram,0xfffaf147) */
/* WARNING: Removing unreachable block (ram,0xfffaf13b) */
/* WARNING: Removing unreachable block (ram,0xfffaf10c) */
/* WARNING: Removing unreachable block (ram,0xfffaf0dd) */
/* WARNING: Removing unreachable block (ram,0xfffaf0c4) */
/* WARNING: Removing unreachable block (ram,0xfffaf0ab) */
/* WARNING: Removing unreachable block (ram,0xfffaf227) */
/* WARNING: Removing unreachable block (ram,0xfffaf074) */
/* WARNING: Removing unreachable block (ram,0xfffaf010) */
/* WARNING: Removing unreachable block (ram,0xfffaf01c) */
/* WARNING: Removing unreachable block (ram,0xfffaefe5) */
/* WARNING: Removing unreachable block (ram,0xfffaec1d) */
/* WARNING: Removing unreachable block (ram,0xfffae9e4) */
/* WARNING: Removing unreachable block (ram,0xfffaebfd) */
/* WARNING: Removing unreachable block (ram,0xfffaef62) */

void cat_SS(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  cVar2 = hex2nib(*(byte *)(param_1 + 3));
  if (param_2 == '\0') {
    if (cVar2 == '\0') {
      iVar4 = FUN_fffc4f8f();
      if (iVar4 == 1) {
        bStack_11 = 5;
      }
      else {
        bStack_11 = DAT_00009c5a;
      }
      DAT_00001c92 = nib2hex(bStack_11);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x01') {
      DAT_00001c92 = nib2hex(DAT_00009be6);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x02') {
      DAT_00001c92 = nib2hex(DAT_00009be7);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x03') {
      DAT_00001c92 = nib2hex(DAT_00009be8);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x04') {
      uVar5 = vfo_freq(DAT_00020b6b,2);
      pbVar6 = (byte *)scope_level_ptr(uVar5,DAT_00020b6b);
      if (*pbVar6 < 0x3c) {
        DAT_00001c92 = '-';
        bStack_11 = 0x3c - *pbVar6;
      }
      else {
        DAT_00001c92 = '+';
        bStack_11 = *pbVar6 - 0x3c;
      }
      bStack_14 = bStack_11 >> 1;
      bStack_12 = 10;
      for (bStack_13 = 0; bStack_13 < 2; bStack_13 = bStack_13 + 1) {
        bVar3 = bStack_14;
        if (bStack_12 != 0) {
          bVar3 = bStack_14 / bStack_12;
        }
        bStack_14 = bStack_14 - bVar3 * bStack_12;
        bStack_12 = bStack_12 / 10;
        cVar2 = nib2hex(bVar3);
        *(char *)((int)&DAT_00001c93 + (uint)bStack_13) = cVar2;
      }
      DAT_00001c93._0_3_ = CONCAT12(0x2e,(undefined2)DAT_00001c93);
      if ((bStack_11 & 1) == 0) {
        DAT_00001c93 = CONCAT13(0x30,(undefined3)DAT_00001c93);
      }
      else {
        DAT_00001c93 = CONCAT13(0x35,(undefined3)DAT_00001c93);
      }
    }
    else if (cVar2 == '\x05') {
      uVar5 = vfo_freq(0,2);
      pbVar6 = (byte *)scope_span_ptr(uVar5);
      DAT_00001c92 = nib2hex(*pbVar6);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x06') {
      if (DAT_00009c36 == '\0') {
        if (DAT_00009c35 == '\0') {
          if (DAT_00009c38 == '\0') {
            bStack_11 = 3;
          }
          else if (DAT_00009c38 == '\x01') {
            bStack_11 = 4;
          }
          else {
            bStack_11 = 5;
          }
        }
        else if (DAT_00009c35 == '\x01') {
          if (DAT_00009c38 == '\0') {
            bStack_11 = 6;
          }
          else if (DAT_00009c38 == '\x01') {
            bStack_11 = 7;
          }
          else {
            bStack_11 = 8;
          }
        }
        else if (DAT_00009c38 == '\0') {
          bStack_11 = 9;
        }
        else if (DAT_00009c38 == '\x01') {
          bStack_11 = 10;
        }
        else {
          bStack_11 = 0xb;
        }
      }
      else if (DAT_00009c35 == '\0') {
        bStack_11 = 0;
      }
      else if (DAT_00009c35 == '\x01') {
        bStack_11 = 1;
      }
      else {
        bStack_11 = 2;
      }
      DAT_00001c92 = nib2hex(bStack_11);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\a') {
      DAT_00001c92 = nib2hex(DAT_00009c39);
      cVar2 = nib2hex(DAT_00009c3b);
      DAT_00001c93 = CONCAT31(DAT_00001c93._1_3_,cVar2);
      cVar2 = nib2hex(DAT_00009c3c);
      DAT_00001c93._0_2_ = CONCAT11(cVar2,(undefined1)DAT_00001c93);
      cVar2 = nib2hex(DAT_00009c3a);
      DAT_00001c93._0_3_ = CONCAT12(cVar2,(undefined2)DAT_00001c93);
      DAT_00001c93 = CONCAT13(0x30,(undefined3)DAT_00001c93);
    }
    else {
      if (cVar2 != '\b') {
        DAT_0000464a = 1;
        return;
      }
      DAT_00001c92 = nib2hex(DAT_00020f1f);
      DAT_00001c93 = 0x30303030;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c97 = 0x3b;
    DAT_0001b788 = 10;
    return;
  }
  if (cVar2 == '\0') {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (*(char *)(param_1 + 7) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (*(char *)(param_1 + 8) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    bVar3 = hex2nib(*(byte *)(param_1 + 4));
    if (bVar3 < 5) {
      DAT_00009c5a = bVar3;
      FUN_fffc4f9e(0);
      return;
    }
    if (bVar3 == 5) {
      FUN_fffc4f9e(1);
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (cVar2 == '\x01') {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (*(char *)(param_1 + 7) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (*(char *)(param_1 + 8) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      bVar3 = hex2nib(*(byte *)(param_1 + 4));
      if (bVar3 < 5) {
        DAT_00009be6 = bVar3;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (cVar2 == '\x02') {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (*(char *)(param_1 + 7) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (*(char *)(param_1 + 8) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      bVar3 = hex2nib(*(byte *)(param_1 + 4));
      if (bVar3 < 2) {
        DAT_00009be7 = bVar3;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (cVar2 == '\x03') {
    if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (*(char *)(param_1 + 7) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (*(char *)(param_1 + 8) != '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      bVar3 = hex2nib(*(byte *)(param_1 + 4));
      if (bVar3 < 0xb) {
        DAT_00009be8 = bVar3;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (cVar2 != '\x04') {
    if (cVar2 == '\x05') {
      if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) || (*(char *)(param_1 + 7) != '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (*(char *)(param_1 + 8) != '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        uVar5 = vfo_freq(0,2);
        pbVar6 = (byte *)scope_span_ptr(uVar5);
        bVar3 = hex2nib(*(byte *)(param_1 + 4));
        if (bVar3 < 10) {
          *pbVar6 = bVar3;
          return;
        }
        DAT_0000464a = 1;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    if (cVar2 == '\x06') {
      if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) || (*(char *)(param_1 + 7) != '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (*(char *)(param_1 + 8) != '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        cVar2 = hex2nib(*(byte *)(param_1 + 4));
        switch(cVar2) {
        case '\0':
          DAT_00009c36 = 1;
          DAT_00009c35 = 0;
          return;
        case '\x01':
          DAT_00009c36 = 1;
          DAT_00009c35 = 1;
          return;
        case '\x02':
          DAT_00009c36 = 1;
          DAT_00009c35 = 2;
          return;
        case '\x03':
          DAT_00009c36 = 0;
          DAT_00009c35 = 0;
          DAT_00009c38 = 2;
          DAT_00009c3d = 1;
          return;
        case '\x04':
          DAT_00009c36 = 0;
          DAT_00009c35 = 0;
          DAT_00009c38 = 1;
          DAT_00009c3d = 0;
          return;
        case '\x05':
          DAT_0000464a = 1;
          return;
        case '\x06':
          DAT_00009c36 = 0;
          DAT_00009c35 = 1;
          DAT_00009c38 = 2;
          DAT_00009c3d = 1;
          return;
        case '\a':
          DAT_00009c36 = 0;
          DAT_00009c35 = 1;
          DAT_00009c38 = 1;
          DAT_00009c3d = 0;
          return;
        case '\b':
          DAT_0000464a = 1;
          return;
        case '\t':
          DAT_00009c36 = 0;
          DAT_00009c35 = 2;
          DAT_00009c38 = 2;
          DAT_00009c3d = 1;
          return;
        case '\n':
          DAT_00009c36 = 0;
          DAT_00009c35 = 2;
          DAT_00009c38 = 1;
          DAT_00009c3d = 0;
          return;
        case '\v':
          DAT_0000464a = 1;
          return;
        default:
          DAT_0000464a = 1;
          return;
        }
      }
      DAT_0000464a = 1;
      return;
    }
    if (cVar2 != '\a') {
      if (cVar2 != '\b') {
        DAT_0000464a = 1;
        return;
      }
      if ((*(char *)(param_1 + 5) == '0') && (*(char *)(param_1 + 6) == '0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) || (*(char *)(param_1 + 7) != '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (*(char *)(param_1 + 8) != '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        bVar3 = hex2nib(*(byte *)(param_1 + 4));
        if (bVar3 < 2) {
          DAT_00020f1f = bVar3;
          return;
        }
        DAT_0000464a = 1;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    if (*(char *)(param_1 + 8) != '0') {
      DAT_0000464a = 1;
      return;
    }
    for (bStack_13 = 4; bStack_13 < 6; bStack_13 = bStack_13 + 1) {
      if ((*(byte *)((uint)bStack_13 + param_1) < 0x30) ||
         (0x32 < *(byte *)((uint)bStack_13 + param_1))) {
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
    if ((*(byte *)(param_1 + 6) < 0x30) || (0x35 < *(byte *)(param_1 + 6))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if ((*(byte *)(param_1 + 7) < 0x30) || (0x32 < *(byte *)(param_1 + 7))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      DAT_00009c39 = hex2nib(*(byte *)(param_1 + 4));
      DAT_00009c3b = hex2nib(*(byte *)(param_1 + 5));
      DAT_00009c3c = hex2nib(*(byte *)(param_1 + 6));
      DAT_00009c3a = hex2nib(*(byte *)(param_1 + 7));
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  uVar5 = vfo_freq(DAT_00020b6b,2);
  pbVar6 = (byte *)scope_level_ptr(uVar5,DAT_00020b6b);
  bStack_14 = 0;
  bStack_12 = 10;
  for (bStack_13 = 5; bStack_13 < 7; bStack_13 = bStack_13 + 1) {
    if ((*(byte *)((uint)bStack_13 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_13 + param_1))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    bStack_14 = (*(byte *)((uint)bStack_13 + param_1) & 0xf) * bStack_12 + bStack_14;
    bStack_12 = bStack_12 / 10;
  }
  cVar2 = *(char *)(param_1 + 4);
  if ((bStack_14 < 0x1f) && (*(char *)(param_1 + 7) == '.')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
LAB_fffaeef9:
    bVar1 = true;
  }
  else {
    if ((cVar2 == '+') || (cVar2 == '-')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) goto LAB_fffaeef9;
    bVar1 = false;
  }
  if (!bVar1) {
    if ((*(char *)(param_1 + 8) == '0') || (*(char *)(param_1 + 8) == '5')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      bVar1 = false;
      goto LAB_fffaef2a;
    }
  }
  bVar1 = true;
LAB_fffaef2a:
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (cVar2 == '-') {
    bStack_14 = ('\x1e' - bStack_14) * '\x02';
    if (*(char *)(param_1 + 8) == '5') {
      bStack_14 = bStack_14 - 1;
    }
  }
  else {
    bStack_14 = (bStack_14 + 0x1e) * '\x02';
    if (*(char *)(param_1 + 8) == '5') {
      bStack_14 = bStack_14 + 1;
    }
  }
  if (0x78 < bStack_14) {
    DAT_0000464a = 1;
    return;
  }
  *pbVar6 = bStack_14;
  return;
}


// ===== cat_ST @ fffaf3b5 (185 bytes)

void cat_ST(int param_1,char param_2)

{
  byte bVar1;
  
  if (param_2 == '\0') {
    if (DAT_00009c5e == '\0') {
      DAT_00001c90 = 0x30;
    }
    else {
      DAT_00001c90 = 0x31;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar1 = key_event_filter(0x305,0);
  if (bVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00020b3d != '\0') {
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


// ===== cat_SV @ fffaf46e (345 bytes)

void cat_SV(uint param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  
  bVar2 = key_event_filter(0x30a,0);
  if (bVar2 == 0) {
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
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  vfo_ab_toggle();
  return;
}


// ===== cat_TS @ fffaf5c7 (497 bytes)

void cat_TS(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 uStack_60;
  undefined1 auStack_5f [90];
  char local_5;
  int local_4;
  
  local_4 = param_1;
  local_5 = param_2;
  if (param_2 == '\0') {
    if (DAT_00020f09 == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020f87 = 0;
    if (DAT_00020f09 == '\x01') {
      DAT_00020f09 = 0;
      puVar5 = &DAT_00009d09;
      puVar3 = auStack_5f;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar3 = *puVar5;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar5 = &DAT_00009d63;
      puVar3 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar3 = *puVar5;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = &DAT_00009d63;
      puVar5 = auStack_5f;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar3 = *puVar5;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      DAT_00020f0f = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  bVar2 = key_event_filter(0xec,0);
  puVar3 = &uStack_60;
  if (bVar2 == 0) {
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
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009c5e != '\x01') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020f87 = 1;
    if (DAT_00020f09 == '\0') {
      DAT_00020f09 = 1;
      puVar4 = &DAT_00009d09;
      puVar5 = puVar3;
      for (iVar6 = 0x5a; puVar5 = puVar5 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
      }
      puVar4 = &DAT_00009d63;
      puVar5 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = *puVar4;
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar5 = &DAT_00009d63;
      for (iVar6 = 0x5a; puVar3 = puVar3 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = *puVar3;
        puVar5 = puVar5 + 1;
      }
      DAT_00020f0f = 1;
      return;
    }
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_TX @ fffaf7b8 (188 bytes)

void cat_TX(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  
  if (param_2 == '\0') {
    bVar2 = ptt_source_get();
    if (bVar2 == 0) {
      DAT_00001c90 = 0x30;
    }
    else if (bVar2 == 5) {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x32;
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
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  cVar3 = hex2nib(*(byte *)(param_1 + 2));
  if (cVar3 == '\0') {
    DAT_00020b28 = 0;
    return;
  }
  if (cVar3 == '\x01') {
    DAT_00020b28 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VD @ fffaf874 (332 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaf93d) */
/* WARNING: Removing unreachable block (ram,0xfffaf902) */
/* WARNING: Removing unreachable block (ram,0xfffaf9bd) */
/* WARNING: Removing unreachable block (ram,0xfffaf9ba) */
/* WARNING: Removing unreachable block (ram,0xfffaf953) */
/* WARNING: Removing unreachable block (ram,0xfffaf9ae) */
/* WARNING: Removing unreachable block (ram,0xfffaf8cd) */

void cat_VD(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    if (DAT_00009af3 == '\0') {
      local_d = DAT_00009bf4;
    }
    else {
      local_d = DAT_00009bf5;
    }
    local_b = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      n = local_d;
      if (local_b != 0) {
        n = local_d / local_b;
      }
      local_d = local_d - n * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c90)[local_c] = cVar2;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  local_d = 0;
  local_b = 10;
  for (local_c = 2; local_c < 4; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
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
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (0x21 < local_d) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009af3 == '\0') {
    DAT_00009bf4 = local_d;
  }
  else {
    DAT_00009bf5 = local_d;
  }
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x2a;
    FUN_fffc8cbb(0x2a);
    FUN_fffc8d8c();
    return;
  }
  return;
}


// ===== cat_VG @ fffaf9c0 (283 bytes)

/* WARNING: Removing unreachable block (ram,0xfffafa6b) */
/* WARNING: Removing unreachable block (ram,0xfffafa30) */
/* WARNING: Removing unreachable block (ram,0xfffafad8) */
/* WARNING: Removing unreachable block (ram,0xfffafad5) */
/* WARNING: Removing unreachable block (ram,0xfffafa81) */
/* WARNING: Removing unreachable block (ram,0xfffafac9) */
/* WARNING: Removing unreachable block (ram,0xfffaf9fb) */

void cat_VG(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00009bf3;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      n = local_d;
      if (local_b != 0) {
        n = local_d / local_b;
      }
      local_d = local_d - n * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c90)[local_c] = cVar2;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  local_d = 0;
  local_b = 100;
  for (local_c = 2; local_c < 5; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
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
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (100 < local_d) {
    DAT_0000464a = 1;
    return;
  }
  DAT_00009bf3 = local_d;
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x29;
    FUN_fffc8cbb(0x29);
    FUN_fffc8d8c();
    return;
  }
  return;
}


// ===== cat_VM @ fffafadb (738 bytes)

void cat_VM(int param_1,short param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_8;
  char local_7;
  
  if ((param_2 == 3) || (*(char *)(param_1 + 2) == '0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_7 = DAT_00009dbe;
    local_8 = DAT_000060c9;
  }
  else {
    local_7 = DAT_00009dbf;
    local_8 = DAT_000060ca;
  }
  if (param_2 == 4) {
    DAT_00001c90 = 0x30;
    if (local_7 == '\x02') {
      if (local_8 < 0x84) {
        if (local_8 < 0x75) {
          if (local_8 < 99) {
            byte2hex(&DAT_00001c91,0x11);
          }
          else {
            byte2hex(&DAT_00001c91,0x21);
          }
        }
        else {
          byte2hex(&DAT_00001c91,0x51);
        }
      }
      else {
        byte2hex(&DAT_00001c91,0x91);
      }
    }
    else if (local_7 == '\x03') {
      byte2hex(&DAT_00001c91,0x10);
    }
    else if (local_7 == '\x04') {
      byte2hex(&DAT_00001c91,0x20);
    }
    else {
      byte2hex(&DAT_00001c91,0);
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  bVar2 = key_event_filter(0x309,0);
  if (bVar2 == 0) {
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
  if (!bVar1) {
    if (param_2 == 3) {
      vm_toggle();
      return;
    }
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (local_7 != '\x01') {
        vm_toggle();
        if (DAT_00009dbd == '\0') {
          local_7 = DAT_00009dbe;
        }
        else {
          local_7 = DAT_00009dbf;
        }
        if (local_7 != '\x01') {
          vm_toggle();
          return;
        }
      }
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VS @ fffafdbd (483 bytes)

void cat_VS(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(DAT_00009dbd);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar2 = key_event_filter(0x30a,0);
  if (bVar2 != 0) {
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
      DAT_00009c5e = 0;
      if (*(char *)(param_1 + 2) == '0') {
        if (DAT_00009dbd == 1) {
          vfo_ab_toggle();
        }
      }
      else {
        if (*(char *)(param_1 + 2) != '1') {
          DAT_0000464a = 1;
          return;
        }
        if (DAT_00009dbd == 0) {
          vfo_ab_toggle();
        }
      }
      DAT_00020f10 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VX @ fffaffa0 (206 bytes)

void cat_VX(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  
  vfo_rec_ptr(0);
  bVar2 = vfo_mode(1);
  if (param_2 == '\0') {
    uVar1 = (uint)bVar2;
    if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
      DAT_00001c90 = '0';
    }
    else {
      DAT_00001c90 = nib2hex(DAT_00009c5d);
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar3 = key_event_filter(0x302,0);
  if (bVar3 == 0) {
    DAT_0000464a = 1;
    return;
  }
  uVar1 = (uint)bVar2;
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00009c5d = 0;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00009c5d = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_ZI @ fffb006e (190 bytes)

void cat_ZI(int param_1)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar2 = key_event_filter(0x307,0);
  if (bVar2 == 0) {
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
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  pbVar3 = vfo_rec_ptr(DAT_00020b6b);
  if (((*pbVar3 & 0xf) == 2) || ((*pbVar3 & 0xf) == 3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  key_zin_spot_short();
  return;
}


// ===== FUN_fffb012c @ fffb012c (58 bytes)

void FUN_fffb012c(int param_1,char param_2,ushort param_3)

{
  ushort local_e;
  
  for (local_e = 0; (local_e < param_3 && (*(char *)((uint)local_e + param_1) != param_2));
      local_e = local_e + 1) {
  }
  return;
}


// ===== cat_reply_error @ fffb0166 (28 bytes)

/* Builds the '?;' error reply (len 2) */

void cat_reply_error(void)

{
  DAT_00001c8e._0_1_ = 0x3f;
  DAT_00001c8e._1_1_ = 0x3b;
  DAT_0001b788 = 2;
  return;
}


// ===== cat_checksum_ok @ fffb0182 (45 bytes)

/* sum8(buf,n)==buf[n]; callers in cat_ext_SP pass n = len-2 (the earlier "n read from RAM[len-2]"
   was the MOVU decoder bug, T10e/T17) */

bool cat_checksum_ok(int param_1,ushort param_2)

{
  char cVar1;
  
  cVar1 = sum8(param_1,param_2);
  return cVar1 == *(char *)((uint)param_2 + param_1);
}


// ===== sum8 @ fffb01af (48 bytes)

/* 8-bit additive checksum of n bytes */

char sum8(int param_1,ushort param_2)

{
  undefined1 local_b;
  undefined2 local_a;
  
  local_b = '\0';
  for (local_a = 0; local_a < param_2; local_a = local_a + 1) {
    local_b = *(char *)((uint)local_a + param_1) + local_b;
  }
  return local_b;
}


// ===== FUN_fffb01df @ fffb01df (20 bytes)

void FUN_fffb01df(byte param_1)

{
  (&DAT_000060cb)[param_1] = 1;
  return;
}


// ===== eeprom_init @ fffb01f3 (54 bytes)

/* Boot: CS high, SCK low, P65 (/WP?) high, WRSR(0x01)=0x80 (SRWD=1, no block protect), P65 low */

void eeprom_init(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xdf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x20;
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xfe;
  eeprom_spi_tx(1);
  eeprom_spi_tx(0x80);
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0xdf;
  return;
}


// ===== eeprom_load_all @ fffb0229 (134 bytes)

/* Boot load: reads header; flag 1 -> mirror EEPROM 0..0x5836 to RAM 0x464F; 0 -> keep cal+dest,
   defaults; else factory init */

void eeprom_load_all(void)

{
  eeprom_read(0,(byte *)&DAT_0000464f,10);
  if (DAT_00004657._1_1_ == '\x01') {
    eeprom_read(0,(byte *)&DAT_0000464f,0x5837);
    return;
  }
  if (DAT_00004657._1_1_ == '\0') {
    eeprom_read(10,&DAT_00004659,0x105);
    eeprom_read(0x10f,&DAT_0000475e,3);
    settings_defaults(0);
  }
  else {
    DAT_00004657 = 0;
    DAT_00004653 = 0;
    DAT_0000464f = 0;
    settings_defaults(1);
    eeprom_save_cfg105();
    eeprom_save_dest();
  }
  DAT_00020b45 = 1;
  return;
}


// ===== eeprom_save_all @ fffb02af (32 bytes)

/* Writes EEPROM 0x0112..0x5836 (RAM 0x4761, 0x5725 bytes) between header updates: power-down and
   first-boot save */

void eeprom_save_all(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x112,&DAT_00004761,0x5725);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_opstate @ fffb02cf (52 bytes)

/* Writes 0x53DB (menu/VFO/state block 0x9A2A, 0x45C) and 0x1A62 (band-stack indices 0x60B1, 0x18)
    */

void eeprom_save_opstate(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x53db,&DAT_00009a2a,0x45c);
  eeprom_write(0x1a62,&DAT_000060b1,0x18);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_bandstack @ fffb0303 (83 bytes)

/* One band-stack entry to EEPROM 0x112/0xDBA + level*0x438 + band*0x5A */

void eeprom_save_bandstack(char param_1,byte param_2,byte param_3,uint param_4)

{
  char cVar1;
  short local_a;
  
  local_a = 0x112;
  cVar1 = supply_undervolt_check();
  if (cVar1 != '\x01') {
    if (param_1 != '\0') {
      local_a = 0xdba;
    }
    eeprom_hdr_update(0);
    eeprom_write((ushort)param_2 * 0x5a + (ushort)param_3 * 0x438 + local_a,(byte *)param_4,0x5a);
    eeprom_hdr_update(1);
    return;
  }
  return;
}


// ===== eeprom_save_image @ fffb0356 (32 bytes)

/* eeprom_write(0x1A7A, 0x60C9, 0x2F49) bracketed by header update */

void eeprom_save_image(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x1a7a,&DAT_000060c9,0x2f49);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_memch @ fffb0376 (75 bytes)

/* Writes the 0x87-byte block at 0x60C9 and one 0x5A-byte memory channel to EEPROM */

void eeprom_save_memch(byte param_1)

{
  char cVar1;
  
  cVar1 = supply_undervolt_check();
  if (cVar1 == '\x01') {
    return;
  }
  eeprom_hdr_update(0);
  eeprom_write(0x1a7a,&DAT_000060c9,0x87);
  eeprom_write((short)((uint)param_1 * 0x5a) + 0x1b01,&DAT_00006150 + (uint)param_1 * 0x5a,0x5a);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_qmb @ fffb03c1 (32 bytes)

/* EEPROM 0x49C3 <- 0x9012 (0x395) */

void eeprom_save_qmb(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x49c3,&DAT_00009012,0x395);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_qmb_slot @ fffb03e1 (111 bytes)

/* QMB header + one slot */

void eeprom_save_qmb_slot(byte param_1)

{
  char cVar1;
  
  cVar1 = supply_undervolt_check();
  if (cVar1 == '\x01') {
    return;
  }
  eeprom_hdr_update(0);
  eeprom_write(0x49c3,&DAT_00009012,0x11);
  eeprom_write((short)((uint)param_1 * 0x5a) + 0x49d4,&DAT_00009023 + (uint)param_1 * 0x5a,0x5a);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_msg @ fffb0450 (185 bytes)

/* (type, n=1..5): type 0 = 0x98-byte message 0x93A7, 1 = keyer text 0x969F (KM), 2 = text 0x979E
   (EM) */

void eeprom_save_msg(int param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  
  cVar3 = supply_undervolt_check();
  if ((cVar3 != '\x01') && (param_1 < 3)) {
    if ((param_2 < 1) || (5 < param_2)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      sVar1 = (short)param_2 + -1;
      eeprom_hdr_update(0);
      if (param_1 == 0) {
        eeprom_write(sVar1 * 0x98 + 0x4d58,&DAT_000093a7 + (ushort)(sVar1 * 0x98),0x98);
      }
      else if (param_1 == 1) {
        eeprom_write(sVar1 * 0x33 + 0x5050,&DAT_0000969f + (ushort)(sVar1 * 0x33),0x33);
      }
      else {
        eeprom_write(sVar1 * 0x32 + 0x514f,
                     (byte *)((int)&DAT_0000979e + (uint)(ushort)(sVar1 * 0x32)),0x32);
      }
      eeprom_hdr_update(1);
      return;
    }
  }
  return;
}


// ===== eeprom_save_atu_mem @ fffb0509 (41 bytes)

/* Writes the 100-entry tuner memory 0x9898 (0x192 bytes) to EEPROM 0x5249 */

void eeprom_save_atu_mem(void)

{
  char cVar1;
  
  cVar1 = supply_undervolt_check();
  if (cVar1 == '\x01') {
    return;
  }
  eeprom_hdr_update(0);
  eeprom_write(0x5249,&DAT_00009898,0x192);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_cfg105 @ fffb0532 (18 bytes)

/* eeprom_write(0x000A, 0x4659, 0x105) */

void eeprom_save_cfg105(void)

{
  eeprom_write(10,&DAT_00004659,0x105);
  return;
}


// ===== eeprom_save_dest @ fffb0544 (20 bytes)

/* eeprom_write(0x010F, 0x475E, 3): destination code */

void eeprom_save_dest(void)

{
  eeprom_write(0x10f,&DAT_0000475e,3);
  return;
}


// ===== settings_defaults @ fffb0558 (222 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reload settings RAM from ROM defaults; arg 1 also the 0x4659 table and destination 0x8043 */

void settings_defaults(byte param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (param_1 == 1) {
    puVar1 = &DAT_00004659;
    puVar2 = &cfg105_defaults;
    for (iVar3 = 0x105; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    DAT_00004760 = 0;
    _DAT_0000475e = 0x8043;
  }
  defaults_vfo();
  defaults_bandstack();
  defaults_qmb();
  defaults_memch();
  defaults_msg();
  puVar1 = &DAT_00009898;
  for (iVar3 = 0x192; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = &DAT_00009c69;
  puVar2 = &DAT_fff80d82;
  for (iVar3 = 0xa0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009c35;
  puVar2 = &DAT_fff80e22;
  for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  menu_defaults_load();
  DAT_00009c65 = 0;
  _DAT_00009c61 = 0;
  _DAT_00009c5d = 0x1000000;
  puVar1 = &DAT_00009dbe;
  for (iVar3 = 200; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = &DAT_00009dbe;
  puVar2 = &DAT_fff80fc6;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009c17;
  puVar2 = &DAT_fff80fd6;
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== reset_memch @ fffb0636 (4 bytes)

/* -> defaults_memch */

void reset_memch(void)

{
  defaults_memch();
  return;
}


// ===== reset_menu @ fffb063a (4 bytes)

/* -> defaults_menu */

void reset_menu(void)

{
  menu_defaults_load();
  return;
}


// ===== eeprom_read_raw @ fffb063e (19 bytes)

/* Wrapper eeprom_read(addr,buf,n); used by SPR */

void eeprom_read_raw(ushort addr,byte *buf,ushort n)

{
  eeprom_read(addr,buf,n);
  return;
}


// ===== eeprom_write_raw @ fffb0651 (19 bytes)

/* Wrapper eeprom_write(addr,buf,n); used by SPW */

void eeprom_write_raw(ushort param_1,uint param_2,ushort param_3)

{
  eeprom_write(param_1,(byte *)param_2,param_3);
  return;
}


// ===== FUN_fffb0664 @ fffb0664 (129 bytes)

void FUN_fffb0664(int param_1)

{
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined4 *)(param_1 + 0xe) = 0xb80b9600;
  *(undefined4 *)(param_1 + 10) = 0x96004004;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf4019600;
  *(undefined4 *)(param_1 + 0x14) = 0x96004005;
  *(undefined2 *)(param_1 + 0x26) = 0;
  *(undefined4 *)(param_1 + 0x22) = 0xf4019600;
  *(undefined4 *)(param_1 + 0x1e) = 0x96004004;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0x800c9600;
  *(undefined4 *)(param_1 + 0x28) = 0x96004004;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x36) = 0x28239600;
  *(undefined4 *)(param_1 + 0x32) = 0x96007004;
  *(undefined2 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0x803e9600;
  *(undefined4 *)(param_1 + 0x3c) = 0x96004001;
  return;
}


// ===== defaults_vfo @ fffb06e5 (148 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Default VFO-A/B working records 0x9D09/0x9D63 (dest-dependent byte +0x46) */

void defaults_vfo(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar1 = dest_code_get();
  uRam00009d11 = 0;
  _DAT_00009d0d = &DAT_00010200;
  _DAT_00009d09 = 0x80040040;
  puVar2 = &DAT_00009d4f;
  puVar3 = &DAT_fff80947;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(&DAT_00009d09);
  uRam00009d6b = 0;
  _DAT_00009d67 = &DAT_00010200;
  _DAT_00009d63 = 0x80040040;
  puVar2 = &DAT_00009da9;
  puVar3 = &DAT_fff80947;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664();
  DAT_00009dbd = 0;
  if (((uVar1 != 0x20b) && (uVar1 != 0x4380)) && (uVar1 != 0x60e6)) {
    return;
  }
  DAT_00009d4f = 8;
  DAT_00009da9 = 8;
  return;
}


// ===== FUN_fffb0779 @ fffb0779 (687 bytes)

void FUN_fffb0779(undefined4 *param_1)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  uVar1 = dest_code_get();
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[1] = &DAT_00010200;
  *param_1 = 0x80040042;
  puVar2 = (undefined1 *)((int)param_1 + 0x46);
  puVar4 = &DAT_fff8090b;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664(param_1);
  *(undefined2 *)((int)param_1 + 0x62) = 0;
  *(undefined **)((int)param_1 + 0x5e) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x5a) = 0x80040040;
  puVar3 = param_1 + 0x28;
  puVar2 = &DAT_fff8091f;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0x2f) = 0;
  param_1[0x2e] = &DAT_00010200;
  param_1[0x2d] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0xfa);
  puVar4 = &DAT_fff80933;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x116) = 0;
  *(undefined **)((int)param_1 + 0x112) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x10e) = 0x80040040;
  puVar3 = param_1 + 0x55;
  puVar2 = &DAT_fff80947;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0x5c) = 0;
  param_1[0x5b] = &DAT_00010200;
  param_1[0x5a] = 0x80040042;
  puVar2 = (undefined1 *)((int)param_1 + 0x1ae);
  puVar4 = &DAT_fff8095b;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x1ca) = 0;
  *(undefined **)((int)param_1 + 0x1c6) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x1c2) = 0x800400c1;
  puVar3 = param_1 + 0x82;
  puVar2 = &DAT_fff8096f;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0x89) = 0;
  param_1[0x88] = &DAT_00010200;
  param_1[0x87] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0x262);
  puVar4 = &DAT_fff80983;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x27e) = 0;
  *(undefined **)((int)param_1 + 0x27a) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x276) = 0x800400c1;
  puVar3 = param_1 + 0xaf;
  puVar2 = &DAT_fff80997;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0xb6) = 0;
  param_1[0xb5] = &DAT_00010200;
  param_1[0xb4] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0x316);
  puVar4 = &DAT_fff809ab;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x332) = 0;
  *(undefined **)((int)param_1 + 0x32e) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x32a) = 0x800400c1;
  puVar3 = param_1 + 0xdc;
  puVar2 = &DAT_fff809bf;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)(param_1 + 0xe3) = 1;
  param_1[0xe2] = &DAT_00010200;
  param_1[0xe1] = 0x800400c1;
  puVar2 = (undefined1 *)((int)param_1 + 0x3ca);
  puVar4 = &DAT_fff809d3;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar4;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_fffb0664();
  *(undefined2 *)((int)param_1 + 0x3e6) = 0;
  *(undefined **)((int)param_1 + 0x3e2) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x3de) = 0x800400c1;
  puVar3 = param_1 + 0x109;
  puVar2 = &DAT_fff809e7;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  FUN_fffb0664();
  if (((uVar1 != 0x20b) && (uVar1 != 0x4380)) && (uVar1 != 0x60e6)) {
    return;
  }
  *(undefined1 *)((int)param_1 + 0x46) = 8;
  *(undefined1 *)(param_1 + 0x28) = 8;
  *(undefined1 *)((int)param_1 + 0xfa) = 8;
  *(undefined1 *)(param_1 + 0x55) = 8;
  *(undefined1 *)((int)param_1 + 0x1ae) = 8;
  *(undefined1 *)(param_1 + 0x82) = 8;
  *(undefined1 *)((int)param_1 + 0x262) = 8;
  *(undefined1 *)(param_1 + 0xaf) = 8;
  *(undefined1 *)((int)param_1 + 0x316) = 8;
  *(undefined1 *)(param_1 + 0xdc) = 8;
  *(undefined1 *)((int)param_1 + 0x3ca) = 8;
  *(undefined1 *)(param_1 + 0x109) = 8;
  return;
}


// ===== defaults_bandstack @ fffb0a28 (84 bytes)

/* Clears 0x4761..0x60C8 and fills 6 band-stack sets (FUN_fffb0779 per set) */

void defaults_bandstack(void)

{
  undefined1 *puVar1;
  undefined *puVar2;
  
  puVar1 = &DAT_00004761;
  for (puVar2 = &DAT_00001968; puVar2 != (undefined *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  FUN_fffb0779(&DAT_00004761);
  FUN_fffb0779(0x4b99);
  FUN_fffb0779(0x4fd1);
  FUN_fffb0779(&DAT_00005409);
  FUN_fffb0779(0x5841);
  FUN_fffb0779(0x5c79);
  return;
}


// ===== defaults_qmb @ fffb0a7c (19 bytes)

/* Clears the QMB block 0x9012 (0x395) */

void defaults_qmb(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_00009012;
  for (iVar2 = 0x395; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ===== defaults_memch @ fffb0a8f (1557 bytes)

/* Clears 0x60C9 (0x2F49), default records for 117 channels, dest-specific 60 m channels */

void defaults_memch(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  byte bStack_b;
  
  uVar1 = dest_code_get();
  puVar2 = &DAT_000060c9;
  for (puVar4 = &DAT_00002f49; puVar4 != (undefined *)0x0; puVar4 = puVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_000060c9;
  for (iVar5 = 0x22; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_000060cb = 1;
  for (bStack_b = 0; bStack_b < 0x75; bStack_b = bStack_b + 1) {
    iVar5 = (uint)bStack_b * 0x5a;
    *(undefined2 *)(iVar5 + 0x6158) = 0;
    *(undefined **)(iVar5 + 0x6154) = &DAT_00010200;
    *(undefined4 *)(&DAT_00006150 + iVar5) = 0x80040040;
    puVar2 = (undefined1 *)(iVar5 + 0x6196);
    puVar3 = &DAT_fff80947;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(&DAT_00006150 + iVar5);
  }
  if (uVar1 == 0xd950) {
LAB_fffb0e99:
    uRam00008a7a = 0;
    puRam00008a76 = &DAT_00030200;
    uRam00008a72 = 0x80040101;
    puVar2 = (undefined1 *)0x8ab8;
    puVar3 = &DAT_fff80b4f;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8a72);
    uRam00008ad4 = 0;
    puRam00008ad0 = &DAT_00030200;
    uRam00008acc = 0x80040101;
    puVar2 = (undefined1 *)0x8b12;
    puVar3 = &DAT_fff80b63;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8acc);
    uRam00008b2e = 0;
    puRam00008b2a = &DAT_00030200;
    uRam00008b26 = 0x80040101;
    puVar2 = (undefined1 *)0x8b6c;
    puVar3 = &DAT_fff80b77;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8b26);
    uRam00008b88 = 0;
    puRam00008b84 = &DAT_00030200;
    uRam00008b80 = 0x80040101;
    puVar2 = (undefined1 *)0x8bc6;
    puVar3 = &DAT_fff80b8b;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8b80);
    uRam00008be2 = 0;
    puRam00008bde = &DAT_00030200;
    uRam00008bda = 0x80040101;
    puVar2 = (undefined1 *)0x8c20;
    puVar3 = &DAT_fff80b9f;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8bda);
    uRam00008c3c = 0;
    puRam00008c38 = &DAT_00030200;
    uRam00008c34 = 0x80040101;
    puVar2 = (undefined1 *)0x8c7a;
    puVar3 = &DAT_fff80bb3;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8c34);
    uRam00008c96 = 0;
    puRam00008c92 = &DAT_00030200;
    uRam00008c8e = 0x80040101;
    puVar2 = (undefined1 *)0x8cd4;
    puVar3 = &DAT_fff80bc7;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8c8e);
    uRam00008cf0 = 0;
    puRam00008cec = &DAT_00030200;
    uRam00008ce8 = 0x80040101;
    puVar2 = (undefined1 *)0x8d2e;
    puVar3 = &DAT_fff80bdb;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8ce8);
    uRam00008d4a = 0;
    puRam00008d46 = &DAT_00030200;
    uRam00008d42 = 0x80040101;
    puVar2 = (undefined1 *)0x8d88;
    puVar3 = &DAT_fff80bef;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8d42);
    uRam00008da4 = 0;
    puRam00008da0 = &DAT_00030200;
    uRam00008d9c = 0x80040101;
    puVar2 = (undefined1 *)0x8de2;
    puVar3 = &DAT_fff80c03;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8d9c);
    return;
  }
  if (uVar1 == 0x1cb9) {
    uRam00008fc0 = 0;
    puRam00008fbc = &DAT_00030200;
    uRam00008fb8 = 0x80040101;
    puVar2 = (undefined1 *)0x8ffe;
    puVar3 = &DAT_fff80c21;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8fb8);
    return;
  }
  if (uVar1 != 0x315b) {
    if (uVar1 != 0x4380) {
      if (uVar1 == 0x50e2) goto LAB_fffb0b88;
      if (uVar1 != 0x60e6) {
        if (uVar1 == 0xa4c5) goto LAB_fffb0e99;
        if (uVar1 != 0x20b) {
          return;
        }
      }
    }
    uRam00006196 = 8;
    uRam00008fc0 = 0;
    puRam00008fbc = &DAT_00030200;
    uRam00008fb8 = 0x80040003;
    puVar2 = (undefined1 *)0x8ffe;
    puVar3 = &DAT_fff80c3f;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_fffb0664(0x8fb8);
    return;
  }
LAB_fffb0b88:
  for (bStack_b = 0; bStack_b < 0xf; bStack_b = bStack_b + 1) {
    (&DAT_00006140)[bStack_b] = 1;
  }
  uRam00008a7a = 0;
  puRam00008a76 = &DAT_00030200;
  uRam00008a72 = 0x80040101;
  puVar2 = (undefined1 *)0x8ab8;
  puVar3 = &DAT_fff80a19;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8a72);
  uRam00008ad4 = 0;
  puRam00008ad0 = &DAT_00030200;
  uRam00008acc = 0x80040101;
  puVar2 = (undefined1 *)0x8b12;
  puVar3 = &DAT_fff80a2d;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8acc);
  uRam00008b2e = 0;
  puRam00008b2a = &DAT_00030200;
  uRam00008b26 = 0x80040101;
  puVar2 = (undefined1 *)0x8b6c;
  puVar3 = &DAT_fff80a41;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8b26);
  uRam00008b88 = 0;
  puRam00008b84 = &DAT_00030200;
  uRam00008b80 = 0x80040101;
  puVar2 = (undefined1 *)0x8bc6;
  puVar3 = &DAT_fff80a55;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8b80);
  uRam00008be2 = 0;
  puRam00008bde = &DAT_00030200;
  uRam00008bda = 0x80040101;
  puVar2 = (undefined1 *)0x8c20;
  puVar3 = &DAT_fff80a69;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8bda);
  uRam00008c3c = 0;
  puRam00008c38 = &DAT_00030200;
  uRam00008c34 = 0x80040103;
  puVar2 = (undefined1 *)0x8c7a;
  puVar3 = &DAT_fff80a7d;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8c34);
  uRam00008c96 = 0;
  puRam00008c92 = &DAT_00030200;
  uRam00008c8e = 0x80040103;
  puVar2 = (undefined1 *)0x8cd4;
  puVar3 = &DAT_fff80a91;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8c8e);
  uRam00008cf0 = 0;
  puRam00008cec = &DAT_00030200;
  uRam00008ce8 = 0x80040103;
  puVar2 = (undefined1 *)0x8d2e;
  puVar3 = &DAT_fff80aa5;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8ce8);
  uRam00008d4a = 0;
  puRam00008d46 = &DAT_00030200;
  uRam00008d42 = 0x80040103;
  puVar2 = (undefined1 *)0x8d88;
  puVar3 = &DAT_fff80ab9;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8d42);
  uRam00008da4 = 0;
  puRam00008da0 = &DAT_00030200;
  uRam00008d9c = 0x80040103;
  puVar2 = (undefined1 *)0x8de2;
  puVar3 = &DAT_fff80acd;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8d9c);
  uRam00008dfe = 0;
  puRam00008dfa = &DAT_00030200;
  uRam00008df6 = 0x80040109;
  puVar2 = (undefined1 *)0x8e3c;
  puVar3 = &DAT_fff80ae1;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8df6);
  uRam00008e58 = 0;
  puRam00008e54 = &DAT_00030200;
  uRam00008e50 = 0x80040109;
  puVar2 = (undefined1 *)0x8e96;
  puVar3 = &DAT_fff80af5;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8e50);
  uRam00008eb2 = 0;
  puRam00008eae = &DAT_00030200;
  uRam00008eaa = 0x80040109;
  puVar2 = (undefined1 *)0x8ef0;
  puVar3 = &DAT_fff80b09;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8eaa);
  uRam00008f0c = 0;
  puRam00008f08 = &DAT_00030200;
  uRam00008f04 = 0x80040109;
  puVar2 = (undefined1 *)0x8f4a;
  puVar3 = &DAT_fff80b1d;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8f04);
  uRam00008f66 = 0;
  puRam00008f62 = &DAT_00030200;
  uRam00008f5e = 0x80040109;
  puVar2 = (undefined1 *)0x8fa4;
  puVar3 = &DAT_fff80b31;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8f5e);
  uRam00008fc0 = 0;
  puRam00008fbc = &DAT_00030200;
  uRam00008fb8 = 0x80040101;
  puVar2 = (undefined1 *)0x8ffe;
  puVar3 = &DAT_fff80c21;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_fffb0664(0x8fb8);
  return;
}


// ===== defaults_msg @ fffb10a4 (196 bytes)

/* Clears 0x93A7 (0x4F1), keyer texts from ROM 0xFFF80C53.. */

void defaults_msg(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar1 = &DAT_000093a7;
  for (iVar4 = 0x4f1; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = &DAT_0000969f;
  puVar3 = &DAT_fff80c53;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_000096d2;
  puVar3 = &DAT_fff80c53;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_00009705;
  puVar3 = &DAT_fff80c53;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_00009738;
  puVar3 = &DAT_fff80c86;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = &DAT_0000976b;
  puVar3 = &DAT_fff80cb9;
  for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_0000979e;
  puVar1 = &DAT_fff80cec;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar2 = *puVar1;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar1 = puVar1 + 1;
  }
  puVar2 = &DAT_000097d0;
  puVar1 = &DAT_fff80cec;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar2 = *puVar1;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar1 = puVar1 + 1;
  }
  puVar2 = &DAT_00009802;
  puVar1 = &DAT_fff80cec;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar2 = *puVar1;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar1 = puVar1 + 1;
  }
  puVar2 = &DAT_00009834;
  puVar1 = &DAT_fff80d1e;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar2 = *puVar1;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar1 = puVar1 + 1;
  }
  puVar2 = &DAT_00009866;
  puVar1 = &DAT_fff80d50;
  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar2 = *puVar1;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar1 = puVar1 + 1;
  }
  return;
}


// ===== menu_defaults_load @ fffb1168 (43 bytes)

/* Reset menu value block 0x9A2A.. from ROM 0xFFF80E4A.. (callees below) + 0x9C17<-0xFFF80FD6 */

void menu_defaults_load(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  menu_defaults_mode();
  menu_defaults_cw();
  menu_defaults_operation();
  menu_defaults_display();
  FUN_fffb1303();
  menu_defaults_presets();
  FUN_fffb13e2();
  puVar1 = &DAT_00009c17;
  puVar2 = &DAT_fff80fd6;
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== menu_defaults_mode @ fffb1193 (93 bytes)

/* RADIO SETTING mode groups 0x9A2A..0x9A90 <- ROM */

void menu_defaults_mode(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80e4a;
  puVar1 = &DAT_00009a2a;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a3f;
  puVar2 = &DAT_fff80e5f;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a52;
  puVar2 = &DAT_fff80e72;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a67;
  puVar2 = &DAT_fff80e87;
  for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009a7e;
  puVar2 = &DAT_fff80e9e;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== menu_defaults_cw @ fffb11f0 (29 bytes)

/* CW SETTING 0x9A91..0x9AB4 <- ROM 0xFFF80EB1 */

void menu_defaults_cw(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80eb1;
  puVar1 = &DAT_00009a91;
  for (iVar3 = 0x24; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== menu_defaults_operation @ fffb120d (217 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb12c1) */
/* WARNING: Removing unreachable block (ram,0xfffb12e3) */
/* WARNING: Removing unreachable block (ram,0xfffb12c9) */
/* WARNING: Removing unreachable block (ram,0xfffb12d6) */
/* OPERATION SETTING 0x9AB5.. <- ROM 0xFFF80ED5, then dest-dependent MAX POWER, KEYBOARD LANGUAGE,
   TX TOT */

void menu_defaults_operation(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar1 = dest_code_get();
  puVar3 = &DAT_fff80ed5;
  puVar2 = &DAT_00009ab5;
  for (iVar4 = 0x4c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_00009aee = FUN_fffb3e6f(0);
  DAT_00009aef = FUN_fffb3e6f(1);
  DAT_00009af0 = FUN_fffb3e6f(2);
  if (uVar1 == 0x60e6) {
    DAT_00009af1 = FUN_fffb3e6f(4);
  }
  else {
    DAT_00009af1 = FUN_fffb3e6f(3);
  }
  if (uVar1 == 0xd950) {
    DAT_00009ac7 = 2;
    DAT_00009ac3 = 10;
    return;
  }
  if (((uVar1 != 0x1cb9) && (uVar1 != 0x306f)) && (uVar1 != 0x315b)) {
    if (uVar1 == 0x4380) {
      DAT_00009ac7 = 0;
      return;
    }
    if (uVar1 != 0x50e2) {
      if (uVar1 == 0x60e6) {
        DAT_00009ac7 = 0;
        return;
      }
      if ((uVar1 != 0x7753) && (uVar1 != 0x9cf7)) {
        if (uVar1 == 0xa4c5) {
          DAT_00009ac3 = 10;
          DAT_00009ac7 = 2;
          return;
        }
        if (uVar1 != 0xd32d) {
          if (uVar1 == 0x20b) {
            DAT_00009ac7 = 0;
            return;
          }
          DAT_00009ac7 = 5;
          DAT_00009ac3 = 10;
          return;
        }
      }
    }
  }
  DAT_00009ac7 = 1;
  return;
}


// ===== menu_defaults_display @ fffb12e6 (29 bytes)

/* DISPLAY SETTING 0x9B01.. <- ROM 0xFFF80F21 */

void menu_defaults_display(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80f21;
  puVar1 = &DAT_00009b01;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fffb1303 @ fffb1303 (34 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffb1303(void)

{
  _DAT_00009b2c = 0;
  _DAT_00009b28 = 0;
  _DAT_00009b24 = 0;
  return;
}

