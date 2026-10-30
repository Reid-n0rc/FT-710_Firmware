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
    cat_error = 1;
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
    cat_error = 1;
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
      cat_error = 1;
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
          cat_error = 1;
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
            cat_error = 1;
            return;
          }
          uStack_12 = FUN_fffb3775(bVar3,bStack_17 - 1);
        }
      }
      else {
        if (1 < uVar1) {
          cat_error = 1;
          return;
        }
        pbStack_1c = pbStack_1c + 0x10;
        if (bStack_17 == 0) {
          uStack_12 = 3000;
        }
        else {
          if (0x17 < bStack_17) {
            cat_error = 1;
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
      cat_error = 1;
      return;
    }
    uStack_12 = FUN_fffb3775(bVar3,bStack_17 - 1);
  }
LAB_fffae5cf:
  if (uStack_12 == 0xffff) {
    cat_error = 1;
    return;
  }
  for (bStack_16 = 0; bStack_16 < 2; bStack_16 = bStack_16 + 1) {
    pbStack_1c[bStack_16] = (byte)(uStack_12 >> ((1 - bStack_16 & 3) << 3));
  }
  g_ui.func_knob_item = 0x1e;
  g_ui.dsp_knob_func = 1;
  func_display_open();
  g_ui.freq_refresh_req = 1;
  vfo_mark_edited(g_opstate.active_vfo);
  vfo_store_back(g_opstate.active_vfo);
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
  cat_error = 1;
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
    bVar3 = g_ui.rf_gain;
    if (g_opstate.ex030102_rf_sql_vr == 0) {
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
      cat_error = 1;
      return;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (100 < local_d) {
    cat_error = 1;
    return;
  }
  DAT_0000464e = SUB41(ROUND(((float)local_d * 255.0) / 100.0 + 0.5),0);
  if (g_opstate.ex030102_rf_sql_vr != 0) {
    g_ui.rf_gain = DAT_0000464e;
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
    cat_error = 1;
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
        bStack_11 = g_opstate.ss00_value;
      }
      DAT_00001c92 = nib2hex(bStack_11);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x01') {
      DAT_00001c92 = nib2hex(g_opstate.ss01_peak);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x02') {
      DAT_00001c92 = nib2hex(g_opstate.ss02_marker);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x03') {
      DAT_00001c92 = nib2hex(g_opstate.ss03_value);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\x04') {
      uVar5 = vfo_freq(g_ui.transmitting,2);
      pbVar6 = (byte *)scope_level_ptr(uVar5,g_ui.transmitting);
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
      if (g_opstate.scope_3dss == 0) {
        if (g_opstate.scope_mode == 0) {
          if (g_opstate.wf_size == 0) {
            bStack_11 = 3;
          }
          else if (g_opstate.wf_size == 1) {
            bStack_11 = 4;
          }
          else {
            bStack_11 = 5;
          }
        }
        else if (g_opstate.scope_mode == 1) {
          if (g_opstate.wf_size == 0) {
            bStack_11 = 6;
          }
          else if (g_opstate.wf_size == 1) {
            bStack_11 = 7;
          }
          else {
            bStack_11 = 8;
          }
        }
        else if (g_opstate.wf_size == 0) {
          bStack_11 = 9;
        }
        else if (g_opstate.wf_size == 1) {
          bStack_11 = 10;
        }
        else {
          bStack_11 = 0xb;
        }
      }
      else if (g_opstate.scope_mode == 0) {
        bStack_11 = 0;
      }
      else if (g_opstate.scope_mode == 1) {
        bStack_11 = 1;
      }
      else {
        bStack_11 = 2;
      }
      DAT_00001c92 = nib2hex(bStack_11);
      DAT_00001c93 = 0x30303030;
    }
    else if (cVar2 == '\a') {
      DAT_00001c92 = nib2hex(g_opstate.ss07_affft_att);
      cVar2 = nib2hex(g_opstate.osc_level_rx);
      DAT_00001c93 = CONCAT31(DAT_00001c93._1_3_,cVar2);
      cVar2 = nib2hex(g_opstate.osc_time);
      DAT_00001c93._0_2_ = CONCAT11(cVar2,(undefined1)DAT_00001c93);
      cVar2 = nib2hex(g_opstate.osc_level_tx);
      DAT_00001c93._0_3_ = CONCAT12(cVar2,(undefined2)DAT_00001c93);
      DAT_00001c93 = CONCAT13(0x30,(undefined3)DAT_00001c93);
    }
    else {
      if (cVar2 != '\b') {
        cat_error = 1;
        return;
      }
      DAT_00001c92 = nib2hex(g_ui.ss08_value);
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
      cat_error = 1;
      return;
    }
    bVar3 = hex2nib(*(byte *)(param_1 + 4));
    if (bVar3 < 5) {
      g_opstate.ss00_value = bVar3;
      FUN_fffc4f9e(0);
      return;
    }
    if (bVar3 == 5) {
      FUN_fffc4f9e(1);
      return;
    }
    cat_error = 1;
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
        g_opstate.ss01_peak = bVar3;
        return;
      }
      cat_error = 1;
      return;
    }
    cat_error = 1;
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
        g_opstate.ss02_marker = bVar3;
        return;
      }
      cat_error = 1;
      return;
    }
    cat_error = 1;
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
        g_opstate.ss03_value = bVar3;
        return;
      }
      cat_error = 1;
      return;
    }
    cat_error = 1;
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
        cat_error = 1;
        return;
      }
      cat_error = 1;
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
          g_opstate.scope_3dss = 1;
          g_opstate.scope_mode = 0;
          return;
        case '\x01':
          g_opstate.scope_3dss = 1;
          g_opstate.scope_mode = 1;
          return;
        case '\x02':
          g_opstate.scope_3dss = 1;
          g_opstate.scope_mode = 2;
          return;
        case '\x03':
          g_opstate.scope_3dss = 0;
          g_opstate.scope_mode = 0;
          g_opstate.wf_size = 2;
          g_opstate.scope_expand = 1;
          return;
        case '\x04':
          g_opstate.scope_3dss = 0;
          g_opstate.scope_mode = 0;
          g_opstate.wf_size = 1;
          g_opstate.scope_expand = 0;
          return;
        case '\x05':
          cat_error = 1;
          return;
        case '\x06':
          g_opstate.scope_3dss = 0;
          g_opstate.scope_mode = 1;
          g_opstate.wf_size = 2;
          g_opstate.scope_expand = 1;
          return;
        case '\a':
          g_opstate.scope_3dss = 0;
          g_opstate.scope_mode = 1;
          g_opstate.wf_size = 1;
          g_opstate.scope_expand = 0;
          return;
        case '\b':
          cat_error = 1;
          return;
        case '\t':
          g_opstate.scope_3dss = 0;
          g_opstate.scope_mode = 2;
          g_opstate.wf_size = 2;
          g_opstate.scope_expand = 1;
          return;
        case '\n':
          g_opstate.scope_3dss = 0;
          g_opstate.scope_mode = 2;
          g_opstate.wf_size = 1;
          g_opstate.scope_expand = 0;
          return;
        case '\v':
          cat_error = 1;
          return;
        default:
          cat_error = 1;
          return;
        }
      }
      cat_error = 1;
      return;
    }
    if (cVar2 != '\a') {
      if (cVar2 != '\b') {
        cat_error = 1;
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
          g_ui.ss08_value = bVar3;
          return;
        }
        cat_error = 1;
        return;
      }
      cat_error = 1;
      return;
    }
    if (*(char *)(param_1 + 8) != '0') {
      cat_error = 1;
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
        cat_error = 1;
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
        cat_error = 1;
        return;
      }
      g_opstate.ss07_affft_att = hex2nib(*(byte *)(param_1 + 4));
      g_opstate.osc_level_rx = hex2nib(*(byte *)(param_1 + 5));
      g_opstate.osc_time = hex2nib(*(byte *)(param_1 + 6));
      g_opstate.osc_level_tx = hex2nib(*(byte *)(param_1 + 7));
      return;
    }
    cat_error = 1;
    return;
  }
  uVar5 = vfo_freq(g_ui.transmitting,2);
  pbVar6 = (byte *)scope_level_ptr(uVar5,g_ui.transmitting);
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
      cat_error = 1;
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
    cat_error = 1;
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
    cat_error = 1;
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
    if (g_opstate.split_on == 0) {
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
    cat_error = 1;
    return;
  }
  if (g_ui.tx_lamp != 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (g_opstate.split_on == 1) {
      split_toggle();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      cat_error = 1;
      return;
    }
    if (g_opstate.split_on == 0) {
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
    cat_error = 1;
    return;
  }
  if ((g_ui.scan_running == 1) || (g_ui.mic_key_hold == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.tune_cycle != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dialog_shown == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.tx_lamp != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dvs_armed == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dvs_busy == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.msg_rec_active == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dvs_state != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.ky_send_0 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.ky_send_1 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.keypad_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cat_error = 1;
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
  byte *pbVar3;
  vfo_rec *pvVar4;
  byte *pbVar5;
  vfo_rec *pvVar6;
  int iVar7;
  byte bStack_60;
  byte abStack_5f [90];
  char local_5;
  int local_4;
  
  local_4 = param_1;
  local_5 = param_2;
  if (param_2 == '\0') {
    if (g_ui.txw_swap == 1) {
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
      cat_error = 1;
      return;
    }
    g_ui.txw_on = 0;
    if (g_ui.txw_swap == 1) {
      g_ui.txw_swap = 0;
      pvVar4 = &g_opstate.vfo_a;
      pbVar5 = abStack_5f;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pbVar5 = pvVar4->mode;
        pbVar5 = pbVar5 + 1;
        pvVar4 = (vfo_rec *)&pvVar4->flags1;
      }
      pvVar6 = &g_opstate.vfo_b;
      pvVar4 = &g_opstate.vfo_a;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        pvVar4->mode = pvVar6->mode;
        pvVar4 = (vfo_rec *)&pvVar4->flags1;
        pvVar6 = (vfo_rec *)&pvVar6->flags1;
      }
      pvVar4 = &g_opstate.vfo_b;
      pbVar5 = abStack_5f;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        pvVar4->mode = *pbVar5;
        pvVar4 = (vfo_rec *)&pvVar4->flags1;
        pbVar5 = pbVar5 + 1;
      }
      g_ui.vfo_refresh_req = 1;
      return;
    }
    cat_error = 1;
    return;
  }
  bVar2 = key_event_filter(0xec,0);
  pbVar5 = &bStack_60;
  if (bVar2 == 0) {
    cat_error = 1;
    return;
  }
  if ((g_ui.scan_running == 1) || (g_ui.mic_key_hold == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.tune_cycle != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dialog_shown == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.keypad_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (g_opstate.split_on != 1) {
      cat_error = 1;
      return;
    }
    g_ui.txw_on = 1;
    if (g_ui.txw_swap == 0) {
      g_ui.txw_swap = 1;
      pvVar4 = &g_opstate.vfo_a;
      pbVar3 = pbVar5;
      for (iVar7 = 0x5a; pbVar3 = pbVar3 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
        *pbVar3 = pvVar4->mode;
        pvVar4 = (vfo_rec *)&pvVar4->flags1;
      }
      pvVar6 = &g_opstate.vfo_b;
      pvVar4 = &g_opstate.vfo_a;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        pvVar4->mode = pvVar6->mode;
        pvVar4 = (vfo_rec *)&pvVar4->flags1;
        pvVar6 = (vfo_rec *)&pvVar6->flags1;
      }
      pvVar4 = &g_opstate.vfo_b;
      for (iVar7 = 0x5a; pbVar5 = pbVar5 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
        pvVar4->mode = *pbVar5;
        pvVar4 = (vfo_rec *)&pvVar4->flags1;
      }
      g_ui.vfo_refresh_req = 1;
      return;
    }
    return;
  }
  cat_error = 1;
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
  if ((g_ui.scan_running == 1) || (g_ui.mic_key_hold == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cat_error = 1;
    return;
  }
  cVar3 = hex2nib(*(byte *)(param_1 + 2));
  if (cVar3 == '\0') {
    g_ui.cat_tx_req = 0;
    return;
  }
  if (cVar3 == '\x01') {
    g_ui.cat_tx_req = 1;
    return;
  }
  cat_error = 1;
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
    if (g_opstate.ex030405_vox_select == 0) {
      local_d = g_opstate.vox_delay[0];
    }
    else {
      local_d = g_opstate.vox_delay[1];
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
      cat_error = 1;
      return;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (0x21 < local_d) {
    cat_error = 1;
    return;
  }
  if (g_opstate.ex030405_vox_select == 0) {
    g_opstate.vox_delay[0] = local_d;
  }
  else {
    g_opstate.vox_delay[1] = local_d;
  }
  if (g_opstate.ex030126_scu_lan10 == 0) {
    g_ui.popup_code = 0x2a;
    popup_duration_get(0x2a);
    popup_open_timed();
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
    local_d = g_opstate.vox_gain;
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
      cat_error = 1;
      return;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (100 < local_d) {
    cat_error = 1;
    return;
  }
  g_opstate.vox_gain = local_d;
  if (g_opstate.ex030126_scu_lan10 == 0) {
    g_ui.popup_code = 0x29;
    popup_duration_get(0x29);
    popup_open_timed();
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
  vfo_state local_7;
  
  if ((param_2 == 3) || (*(char *)(param_1 + 2) == '0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    cat_error = 1;
    return;
  }
  if (g_opstate.active_vfo == VFO_A) {
    local_7 = g_opstate.vfo_state_a;
    local_8 = g_mem_hdr.chan_a;
  }
  else {
    local_7 = g_opstate.vfo_state_b;
    local_8 = g_mem_hdr.chan_b;
  }
  if (param_2 == 4) {
    DAT_00001c90 = 0x30;
    if (local_7 == VFO_STATE_MEMORY) {
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
    else if (local_7 == VFO_STATE_MEMTUNE) {
      byte2hex(&DAT_00001c91,0x10);
    }
    else if (local_7 == VFO_STATE_PMS) {
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
    cat_error = 1;
    return;
  }
  if ((g_ui.scan_running == 1) || (g_ui.mic_key_hold == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.tune_cycle != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dialog_shown == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.tx_lamp != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dvs_armed == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dvs_busy == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.msg_rec_active == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.dvs_state != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.ky_send_0 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.ky_send_1 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.keypad_open == 1)) {
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
      if (local_7 != VFO_STATE_VFO) {
        vm_toggle();
        if (g_opstate.active_vfo == VFO_A) {
          local_7 = g_opstate.vfo_state_a;
        }
        else {
          local_7 = g_opstate.vfo_state_b;
        }
        if (local_7 != VFO_STATE_VFO) {
          vm_toggle();
          return;
        }
      }
      return;
    }
    cat_error = 1;
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_VS @ fffafdbd (483 bytes)

void cat_VS(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(g_opstate.active_vfo);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar2 = key_event_filter(0x30a,0);
  if (bVar2 != 0) {
    if ((g_ui.scan_running == 1) || (g_ui.mic_key_hold == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.tune_cycle != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.dialog_shown == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.tx_lamp != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.dvs_armed == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.dvs_busy == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.msg_rec_active == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.dvs_state != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.ky_send_0 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.ky_send_1 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.keypad_open == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      g_opstate.split_on = 0;
      if (*(char *)(param_1 + 2) == '0') {
        if (g_opstate.active_vfo == VFO_B) {
          vfo_ab_toggle();
        }
      }
      else {
        if (*(char *)(param_1 + 2) != '1') {
          cat_error = 1;
          return;
        }
        if (g_opstate.active_vfo == VFO_A) {
          vfo_ab_toggle();
        }
      }
      g_ui.freq_refresh_req = 1;
      return;
    }
    cat_error = 1;
    return;
  }
  cat_error = 1;
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
      DAT_00001c90 = nib2hex(g_opstate.vox_on);
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar3 = key_event_filter(0x302,0);
  if (bVar3 == 0) {
    cat_error = 1;
    return;
  }
  uVar1 = (uint)bVar2;
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    g_opstate.vox_on = 0;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    g_opstate.vox_on = 1;
    return;
  }
  cat_error = 1;
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
    cat_error = 1;
    return;
  }
  if ((g_ui.scan_running == 1) || (g_ui.mic_key_hold == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.tune_cycle != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  pbVar3 = vfo_rec_ptr(g_ui.transmitting);
  if (((*pbVar3 & 0xf) == 2) || ((*pbVar3 & 0xf) == 3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    cat_error = 1;
    return;
  }
  key_zin_spot_short();
  return;
}


// ===== mem_find_byte @ fffb012c (58 bytes)

/* (buf, c, n): pointer to the first byte == c in buf[0..n), else buf itself; returned in R1 (EM,
   KM) [fact, #173 listing check] */

void mem_find_byte(int param_1,char param_2,ushort param_3)

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
  g_mem_hdr.chan_used[param_1] = 1;
  return;
}


// ===== eeprom_init @ fffb01f3 (54 bytes)

/* Boot: CS high, SCK low, P65 (/WP?) high, WRSR(0x01)=0x80 (SRWD=1, no block protect), P65 low */

void eeprom_init(void)

{
  byte bVar1;
  
  bVar1 = PORTE_PODR;
  PORTE_PODR = bVar1 | 1;
  bVar1 = PORTE_PODR;
  PORTE_PODR = bVar1 & 0xdf;
  bVar1 = PORT6_PODR;
  PORT6_PODR = bVar1 | 0x20;
  bVar1 = PORTE_PODR;
  PORTE_PODR = bVar1 & 0xfe;
  eeprom_spi_tx(1);
  eeprom_spi_tx(0x80);
  bVar1 = PORTE_PODR;
  PORTE_PODR = bVar1 | 1;
  bVar1 = PORT6_PODR;
  PORT6_PODR = bVar1 & 0xdf;
  return;
}


// ===== eeprom_load_all @ fffb0229 (134 bytes)

/* Boot load: reads header; flag 1 -> mirror EEPROM 0..0x5836 to RAM 0x464F; 0 -> keep cal+dest,
   defaults; else factory init */

void eeprom_load_all(void)

{
  eeprom_read(0,g_ee_hdr.stamp,10);
  if (g_ee_hdr.state == 1) {
    eeprom_read(0,g_ee_hdr.stamp,0x5837);
    return;
  }
  if (g_ee_hdr.state == 0) {
    eeprom_read(10,&g_cfg105.a001_gn_vdd_mtr,0x105);
    eeprom_read(0x10f,dest_code,3);
    settings_defaults(0);
  }
  else {
    g_ee_hdr.save_count_be[3] = 0;
    g_ee_hdr.state = 0;
    g_ee_hdr.stamp[4] = 0;
    g_ee_hdr.save_count_be[0] = 0;
    g_ee_hdr.save_count_be[1] = 0;
    g_ee_hdr.save_count_be[2] = 0;
    g_ee_hdr.stamp[0] = 0;
    g_ee_hdr.stamp[1] = 0;
    g_ee_hdr.stamp[2] = 0;
    g_ee_hdr.stamp[3] = 0;
    settings_defaults(1);
    eeprom_save_cfg105();
    eeprom_save_dest();
  }
  g_ui.defaults_loaded = 1;
  return;
}


// ===== eeprom_save_all @ fffb02af (32 bytes)

/* Writes EEPROM 0x0112..0x5836 (RAM 0x4761, 0x5725 bytes) between header updates: power-down and
   first-boot save */

void eeprom_save_all(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x112,(byte *)bandstack_a,0x5725);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_opstate @ fffb02cf (52 bytes)

/* Writes 0x53DB (menu/VFO/state block 0x9A2A, 0x45C) and 0x1A62 (band-stack indices 0x60B1, 0x18)
    */

void eeprom_save_opstate(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x53db,(byte *)&g_opstate,0x45c);
  eeprom_write(0x1a62,bandstack_level_a,0x18);
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
  eeprom_write(0x1a7a,&g_mem_hdr.chan_a,0x2f49);
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
  eeprom_write(0x1a7a,&g_mem_hdr.chan_a,0x87);
  eeprom_write((ushort)param_1 * 0x5a + 0x1b01,&memch[param_1].mode,0x5a);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_qmb @ fffb03c1 (32 bytes)

/* EEPROM 0x49C3 <- 0x9012 (0x395) */

void eeprom_save_qmb(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x49c3,g_qmb_hdr.used_mask_be,0x395);
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
  eeprom_write(0x49c3,g_qmb_hdr.used_mask_be,0x11);
  eeprom_write((ushort)param_1 * 0x5a + 0x49d4,&qmb[param_1].mode,0x5a);
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
  eeprom_write(10,&g_cfg105.a001_gn_vdd_mtr,0x105);
  return;
}


// ===== eeprom_save_dest @ fffb0544 (20 bytes)

/* eeprom_write(0x010F, 0x475E, 3): destination code */

void eeprom_save_dest(void)

{
  eeprom_write(0x10f,dest_code,3);
  return;
}


// ===== settings_defaults @ fffb0558 (222 bytes)

/* Reload settings RAM from ROM defaults; arg 1 also the 0x4659 table and destination 0x8043 */

void settings_defaults(byte param_1)

{
  cfg105 *pcVar1;
  undefined1 *puVar2;
  uint *puVar3;
  byte *pbVar4;
  vfo_state *pvVar5;
  byte *pbVar6;
  vfo_state *pvVar7;
  int iVar8;
  
  if (param_1 == 1) {
    pcVar1 = &g_cfg105;
    pbVar4 = &cfg105_defaults;
    for (iVar8 = 0x105; iVar8 != 0; iVar8 = iVar8 + -1) {
      pcVar1->a001_gn_vdd_mtr = *pbVar4;
      pcVar1 = (cfg105 *)&pcVar1->a002_gn_fan;
      pbVar4 = pbVar4 + 1;
    }
    dest_code[2] = 0;
    dest_code[0] = 0x43;
    dest_code[1] = 0x80;
  }
  defaults_vfo();
  defaults_bandstack();
  defaults_qmb();
  defaults_memch();
  defaults_msg();
  puVar2 = &DAT_00009898;
  for (iVar8 = 0x192; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar3 = g_opstate.bandmem_cursor;
  puVar2 = &DAT_fff80d82;
  for (iVar8 = 0xa0; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(undefined1 *)puVar3 = *puVar2;
    puVar3 = (uint *)((int)puVar3 + 1);
    puVar2 = puVar2 + 1;
  }
  pbVar4 = &g_opstate.scope_mode;
  pbVar6 = &DAT_fff80e22;
  for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar4 = *pbVar6;
    pbVar4 = pbVar4 + 1;
    pbVar6 = pbVar6 + 1;
  }
  menu_defaults_load();
  g_opstate.f_0x23b_u16 = 0;
  g_opstate._573_1_ = 0;
  g_opstate.na_ai_value = 0;
  g_opstate.fn_select = 0;
  g_opstate.lock_on = 0;
  g_opstate._569_2_ = 0;
  g_opstate.vox_on = 0;
  g_opstate.split_on = 0;
  g_opstate.apf_freq = 0;
  g_opstate._566_1_ = 1;
  pvVar5 = &g_opstate.vfo_state_a;
  for (iVar8 = 200; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pvVar5 = VFO_STATE_UNUSED_0;
    pvVar5 = pvVar5 + 1;
  }
  pvVar5 = &g_opstate.vfo_state_a;
  pvVar7 = &DAT_fff80fc6;
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pvVar5 = *pvVar7;
    pvVar5 = pvVar5 + 1;
    pvVar7 = pvVar7 + 1;
  }
  pbVar4 = g_opstate.zero_9c17;
  pbVar6 = &DAT_fff80fd6;
  for (iVar8 = 0x1e; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar4 = *pbVar6;
    pbVar4 = pbVar4 + 1;
    pbVar6 = pbVar6 + 1;
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

/* Default VFO-A/B working records 0x9D09/0x9D63 (dest-dependent byte +0x46) */

void defaults_vfo(void)

{
  ushort uVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  uVar1 = dest_code_get();
  g_opstate.vfo_a.reserved_07[1] = 0;
  g_opstate.vfo_a.reserved_07[2] = 0;
  g_opstate.vfo_a._4_4_ = &DAT_00010200;
  g_opstate.vfo_a.mode = 0x40;
  g_opstate.vfo_a.flags1 = 0;
  g_opstate.vfo_a.flags2 = 4;
  g_opstate.vfo_a.flags3 = 0x80;
  pbVar2 = &g_opstate.vfo_a.tone_num;
  pbVar3 = &DAT_fff80947;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  }
  FUN_fffb0664(0x9d09);
  g_opstate.vfo_b.reserved_07[1] = 0;
  g_opstate.vfo_b.reserved_07[2] = 0;
  g_opstate.vfo_b._4_4_ = &DAT_00010200;
  g_opstate.vfo_b.mode = 0x40;
  g_opstate.vfo_b.flags1 = 0;
  g_opstate.vfo_b.flags2 = 4;
  g_opstate.vfo_b.flags3 = 0x80;
  pbVar2 = &g_opstate.vfo_b.tone_num;
  pbVar3 = &DAT_fff80947;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  }
  FUN_fffb0664();
  g_opstate.active_vfo = VFO_A;
  if (((uVar1 != 0x20b) && (uVar1 != 0x4380)) && (uVar1 != 0x60e6)) {
    return;
  }
  g_opstate.vfo_a.tone_num = 8;
  g_opstate.vfo_b.tone_num = 8;
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
  vfo_rec (*pavVar1) [12];
  undefined *puVar2;
  
  pavVar1 = bandstack_a;
  for (puVar2 = &DAT_00001968; puVar2 != (undefined *)0x0; puVar2 = puVar2 + -1) {
    *(byte *)pavVar1 = 0;
    pavVar1 = (vfo_rec (*) [12])((int)pavVar1 + 1);
  }
  FUN_fffb0779(bandstack_a);
  FUN_fffb0779(0x4b99);
  FUN_fffb0779(0x4fd1);
  FUN_fffb0779(bandstack_b);
  FUN_fffb0779(0x5841);
  FUN_fffb0779(0x5c79);
  return;
}


// ===== defaults_qmb @ fffb0a7c (19 bytes)

/* Clears the QMB block 0x9012 (0x395) */

void defaults_qmb(void)

{
  qmb_hdr *pqVar1;
  int iVar2;
  
  pqVar1 = &g_qmb_hdr;
  for (iVar2 = 0x395; iVar2 != 0; iVar2 = iVar2 + -1) {
    pqVar1->used_mask_be[0] = 0;
    pqVar1 = (qmb_hdr *)(pqVar1->used_mask_be + 1);
  }
  return;
}


// ===== defaults_memch @ fffb0a8f (1557 bytes)

/* Clears 0x60C9 (0x2F49), default records for 117 channels, dest-specific 60 m channels */

void defaults_memch(void)

{
  uint uVar1;
  ushort uVar2;
  mem_hdr *pmVar3;
  vfo_rec *pvVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined *puVar7;
  int iVar8;
  byte bStack_b;
  
  uVar2 = dest_code_get();
  pmVar3 = &g_mem_hdr;
  for (puVar7 = &DAT_00002f49; puVar7 != (undefined *)0x0; puVar7 = puVar7 + -1) {
    pmVar3->chan_a = 0;
    pmVar3 = (mem_hdr *)&pmVar3->chan_b;
  }
  pmVar3 = &g_mem_hdr;
  for (iVar8 = 0x22; iVar8 != 0; iVar8 = iVar8 + -1) {
    pmVar3->chan_a = 0;
    pmVar3 = (mem_hdr *)&pmVar3->chan_b;
  }
  g_mem_hdr.chan_used[0] = 1;
  for (bStack_b = 0; bStack_b < 0x75; bStack_b = bStack_b + 1) {
    uVar1 = (uint)bStack_b;
    pvVar4 = memch + uVar1;
    memch[uVar1].reserved_07[1] = 0;
    memch[uVar1].reserved_07[2] = 0;
    *(undefined **)&memch[uVar1].nar_flags = &DAT_00010200;
    pvVar4->mode = 0x40;
    pvVar4->flags1 = 0;
    pvVar4->flags2 = 4;
    pvVar4->flags3 = 0x80;
    pbVar5 = &memch[uVar1].tone_num;
    pbVar6 = &DAT_fff80947;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(pvVar4);
  }
  if (uVar2 == 0xd950) {
LAB_fffb0e99:
    memch[0x75].reserved_07[1] = 0;
    memch[0x75].reserved_07[2] = 0;
    memch[0x75]._4_4_ = &DAT_00030200;
    memch[0x75].mode = 1;
    memch[0x75].flags1 = 1;
    memch[0x75].flags2 = 4;
    memch[0x75].flags3 = 0x80;
    pbVar5 = &memch[0x75].tone_num;
    pbVar6 = &DAT_fff80b4f;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8a72);
    memch[0x76].reserved_07[1] = 0;
    memch[0x76].reserved_07[2] = 0;
    memch[0x76]._4_4_ = &DAT_00030200;
    memch[0x76].mode = 1;
    memch[0x76].flags1 = 1;
    memch[0x76].flags2 = 4;
    memch[0x76].flags3 = 0x80;
    pbVar5 = &memch[0x76].tone_num;
    pbVar6 = &DAT_fff80b63;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8acc);
    memch[0x77].reserved_07[1] = 0;
    memch[0x77].reserved_07[2] = 0;
    memch[0x77]._4_4_ = &DAT_00030200;
    memch[0x77].mode = 1;
    memch[0x77].flags1 = 1;
    memch[0x77].flags2 = 4;
    memch[0x77].flags3 = 0x80;
    pbVar5 = &memch[0x77].tone_num;
    pbVar6 = &DAT_fff80b77;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8b26);
    memch[0x78].reserved_07[1] = 0;
    memch[0x78].reserved_07[2] = 0;
    memch[0x78]._4_4_ = &DAT_00030200;
    memch[0x78].mode = 1;
    memch[0x78].flags1 = 1;
    memch[0x78].flags2 = 4;
    memch[0x78].flags3 = 0x80;
    pbVar5 = &memch[0x78].tone_num;
    pbVar6 = &DAT_fff80b8b;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8b80);
    memch[0x79].reserved_07[1] = 0;
    memch[0x79].reserved_07[2] = 0;
    memch[0x79]._4_4_ = &DAT_00030200;
    memch[0x79].mode = 1;
    memch[0x79].flags1 = 1;
    memch[0x79].flags2 = 4;
    memch[0x79].flags3 = 0x80;
    pbVar5 = &memch[0x79].tone_num;
    pbVar6 = &DAT_fff80b9f;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8bda);
    memch[0x7a].reserved_07[1] = 0;
    memch[0x7a].reserved_07[2] = 0;
    memch[0x7a]._4_4_ = &DAT_00030200;
    memch[0x7a].mode = 1;
    memch[0x7a].flags1 = 1;
    memch[0x7a].flags2 = 4;
    memch[0x7a].flags3 = 0x80;
    pbVar5 = &memch[0x7a].tone_num;
    pbVar6 = &DAT_fff80bb3;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8c34);
    memch[0x7b].reserved_07[1] = 0;
    memch[0x7b].reserved_07[2] = 0;
    memch[0x7b]._4_4_ = &DAT_00030200;
    memch[0x7b].mode = 1;
    memch[0x7b].flags1 = 1;
    memch[0x7b].flags2 = 4;
    memch[0x7b].flags3 = 0x80;
    pbVar5 = &memch[0x7b].tone_num;
    pbVar6 = &DAT_fff80bc7;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8c8e);
    memch[0x7c].reserved_07[1] = 0;
    memch[0x7c].reserved_07[2] = 0;
    memch[0x7c]._4_4_ = &DAT_00030200;
    memch[0x7c].mode = 1;
    memch[0x7c].flags1 = 1;
    memch[0x7c].flags2 = 4;
    memch[0x7c].flags3 = 0x80;
    pbVar5 = &memch[0x7c].tone_num;
    pbVar6 = &DAT_fff80bdb;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8ce8);
    memch[0x7d].reserved_07[1] = 0;
    memch[0x7d].reserved_07[2] = 0;
    memch[0x7d]._4_4_ = &DAT_00030200;
    memch[0x7d].mode = 1;
    memch[0x7d].flags1 = 1;
    memch[0x7d].flags2 = 4;
    memch[0x7d].flags3 = 0x80;
    pbVar5 = &memch[0x7d].tone_num;
    pbVar6 = &DAT_fff80bef;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8d42);
    memch[0x7e].reserved_07[1] = 0;
    memch[0x7e].reserved_07[2] = 0;
    memch[0x7e]._4_4_ = &DAT_00030200;
    memch[0x7e].mode = 1;
    memch[0x7e].flags1 = 1;
    memch[0x7e].flags2 = 4;
    memch[0x7e].flags3 = 0x80;
    pbVar5 = &memch[0x7e].tone_num;
    pbVar6 = &DAT_fff80c03;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8d9c);
    return;
  }
  if (uVar2 == 0x1cb9) {
    memch[0x84].reserved_07[1] = 0;
    memch[0x84].reserved_07[2] = 0;
    memch[0x84]._4_4_ = &DAT_00030200;
    memch[0x84].mode = 1;
    memch[0x84].flags1 = 1;
    memch[0x84].flags2 = 4;
    memch[0x84].flags3 = 0x80;
    pbVar5 = &memch[0x84].tone_num;
    pbVar6 = &DAT_fff80c21;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8fb8);
    return;
  }
  if (uVar2 != 0x315b) {
    if (uVar2 != 0x4380) {
      if (uVar2 == 0x50e2) goto LAB_fffb0b88;
      if (uVar2 != 0x60e6) {
        if (uVar2 == 0xa4c5) goto LAB_fffb0e99;
        if (uVar2 != 0x20b) {
          return;
        }
      }
    }
    memch[0].tone_num = 8;
    memch[0x84].reserved_07[1] = 0;
    memch[0x84].reserved_07[2] = 0;
    memch[0x84]._4_4_ = &DAT_00030200;
    memch[0x84].mode = 3;
    memch[0x84].flags1 = 0;
    memch[0x84].flags2 = 4;
    memch[0x84].flags3 = 0x80;
    pbVar5 = &memch[0x84].tone_num;
    pbVar6 = &DAT_fff80c3f;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar5 = *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    }
    FUN_fffb0664(0x8fb8);
    return;
  }
LAB_fffb0b88:
  for (bStack_b = 0; bStack_b < 0xf; bStack_b = bStack_b + 1) {
    g_mem_hdr.chan_used[bStack_b + 0x75] = 1;
  }
  memch[0x75].reserved_07[1] = 0;
  memch[0x75].reserved_07[2] = 0;
  memch[0x75]._4_4_ = &DAT_00030200;
  memch[0x75].mode = 1;
  memch[0x75].flags1 = 1;
  memch[0x75].flags2 = 4;
  memch[0x75].flags3 = 0x80;
  pbVar5 = &memch[0x75].tone_num;
  pbVar6 = &DAT_fff80a19;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8a72);
  memch[0x76].reserved_07[1] = 0;
  memch[0x76].reserved_07[2] = 0;
  memch[0x76]._4_4_ = &DAT_00030200;
  memch[0x76].mode = 1;
  memch[0x76].flags1 = 1;
  memch[0x76].flags2 = 4;
  memch[0x76].flags3 = 0x80;
  pbVar5 = &memch[0x76].tone_num;
  pbVar6 = &DAT_fff80a2d;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8acc);
  memch[0x77].reserved_07[1] = 0;
  memch[0x77].reserved_07[2] = 0;
  memch[0x77]._4_4_ = &DAT_00030200;
  memch[0x77].mode = 1;
  memch[0x77].flags1 = 1;
  memch[0x77].flags2 = 4;
  memch[0x77].flags3 = 0x80;
  pbVar5 = &memch[0x77].tone_num;
  pbVar6 = &DAT_fff80a41;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8b26);
  memch[0x78].reserved_07[1] = 0;
  memch[0x78].reserved_07[2] = 0;
  memch[0x78]._4_4_ = &DAT_00030200;
  memch[0x78].mode = 1;
  memch[0x78].flags1 = 1;
  memch[0x78].flags2 = 4;
  memch[0x78].flags3 = 0x80;
  pbVar5 = &memch[0x78].tone_num;
  pbVar6 = &DAT_fff80a55;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8b80);
  memch[0x79].reserved_07[1] = 0;
  memch[0x79].reserved_07[2] = 0;
  memch[0x79]._4_4_ = &DAT_00030200;
  memch[0x79].mode = 1;
  memch[0x79].flags1 = 1;
  memch[0x79].flags2 = 4;
  memch[0x79].flags3 = 0x80;
  pbVar5 = &memch[0x79].tone_num;
  pbVar6 = &DAT_fff80a69;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8bda);
  memch[0x7a].reserved_07[1] = 0;
  memch[0x7a].reserved_07[2] = 0;
  memch[0x7a]._4_4_ = &DAT_00030200;
  memch[0x7a].mode = 3;
  memch[0x7a].flags1 = 1;
  memch[0x7a].flags2 = 4;
  memch[0x7a].flags3 = 0x80;
  pbVar5 = &memch[0x7a].tone_num;
  pbVar6 = &DAT_fff80a7d;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8c34);
  memch[0x7b].reserved_07[1] = 0;
  memch[0x7b].reserved_07[2] = 0;
  memch[0x7b]._4_4_ = &DAT_00030200;
  memch[0x7b].mode = 3;
  memch[0x7b].flags1 = 1;
  memch[0x7b].flags2 = 4;
  memch[0x7b].flags3 = 0x80;
  pbVar5 = &memch[0x7b].tone_num;
  pbVar6 = &DAT_fff80a91;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8c8e);
  memch[0x7c].reserved_07[1] = 0;
  memch[0x7c].reserved_07[2] = 0;
  memch[0x7c]._4_4_ = &DAT_00030200;
  memch[0x7c].mode = 3;
  memch[0x7c].flags1 = 1;
  memch[0x7c].flags2 = 4;
  memch[0x7c].flags3 = 0x80;
  pbVar5 = &memch[0x7c].tone_num;
  pbVar6 = &DAT_fff80aa5;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8ce8);
  memch[0x7d].reserved_07[1] = 0;
  memch[0x7d].reserved_07[2] = 0;
  memch[0x7d]._4_4_ = &DAT_00030200;
  memch[0x7d].mode = 3;
  memch[0x7d].flags1 = 1;
  memch[0x7d].flags2 = 4;
  memch[0x7d].flags3 = 0x80;
  pbVar5 = &memch[0x7d].tone_num;
  pbVar6 = &DAT_fff80ab9;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8d42);
  memch[0x7e].reserved_07[1] = 0;
  memch[0x7e].reserved_07[2] = 0;
  memch[0x7e]._4_4_ = &DAT_00030200;
  memch[0x7e].mode = 3;
  memch[0x7e].flags1 = 1;
  memch[0x7e].flags2 = 4;
  memch[0x7e].flags3 = 0x80;
  pbVar5 = &memch[0x7e].tone_num;
  pbVar6 = &DAT_fff80acd;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8d9c);
  memch[0x7f].reserved_07[1] = 0;
  memch[0x7f].reserved_07[2] = 0;
  memch[0x7f]._4_4_ = &DAT_00030200;
  memch[0x7f].mode = 9;
  memch[0x7f].flags1 = 1;
  memch[0x7f].flags2 = 4;
  memch[0x7f].flags3 = 0x80;
  pbVar5 = &memch[0x7f].tone_num;
  pbVar6 = &DAT_fff80ae1;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8df6);
  memch[0x80].reserved_07[1] = 0;
  memch[0x80].reserved_07[2] = 0;
  memch[0x80]._4_4_ = &DAT_00030200;
  memch[0x80].mode = 9;
  memch[0x80].flags1 = 1;
  memch[0x80].flags2 = 4;
  memch[0x80].flags3 = 0x80;
  pbVar5 = &memch[0x80].tone_num;
  pbVar6 = &DAT_fff80af5;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8e50);
  memch[0x81].reserved_07[1] = 0;
  memch[0x81].reserved_07[2] = 0;
  memch[0x81]._4_4_ = &DAT_00030200;
  memch[0x81].mode = 9;
  memch[0x81].flags1 = 1;
  memch[0x81].flags2 = 4;
  memch[0x81].flags3 = 0x80;
  pbVar5 = &memch[0x81].tone_num;
  pbVar6 = &DAT_fff80b09;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8eaa);
  memch[0x82].reserved_07[1] = 0;
  memch[0x82].reserved_07[2] = 0;
  memch[0x82]._4_4_ = &DAT_00030200;
  memch[0x82].mode = 9;
  memch[0x82].flags1 = 1;
  memch[0x82].flags2 = 4;
  memch[0x82].flags3 = 0x80;
  pbVar5 = &memch[0x82].tone_num;
  pbVar6 = &DAT_fff80b1d;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8f04);
  memch[0x83].reserved_07[1] = 0;
  memch[0x83].reserved_07[2] = 0;
  memch[0x83]._4_4_ = &DAT_00030200;
  memch[0x83].mode = 9;
  memch[0x83].flags1 = 1;
  memch[0x83].flags2 = 4;
  memch[0x83].flags3 = 0x80;
  pbVar5 = &memch[0x83].tone_num;
  pbVar6 = &DAT_fff80b31;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  FUN_fffb0664(0x8f5e);
  memch[0x84].reserved_07[1] = 0;
  memch[0x84].reserved_07[2] = 0;
  memch[0x84]._4_4_ = &DAT_00030200;
  memch[0x84].mode = 1;
  memch[0x84].flags1 = 1;
  memch[0x84].flags2 = 4;
  memch[0x84].flags3 = 0x80;
  pbVar5 = &memch[0x84].tone_num;
  pbVar6 = &DAT_fff80c21;
  for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pbVar5 = *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
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
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  
  menu_defaults_mode();
  menu_defaults_cw();
  menu_defaults_operation();
  menu_defaults_display();
  FUN_fffb1303();
  menu_defaults_presets();
  FUN_fffb13e2();
  pbVar1 = g_opstate.zero_9c17;
  pbVar2 = &DAT_fff80fd6;
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pbVar1 = *pbVar2;
    pbVar1 = pbVar1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_defaults_mode @ fffb1193 (93 bytes)

/* RADIO SETTING mode groups 0x9A2A..0x9A90 <- ROM */

void menu_defaults_mode(void)

{
  opstate *poVar1;
  sbyte *psVar2;
  sbyte *psVar3;
  int iVar4;
  
  psVar2 = &DAT_fff80e4a;
  poVar1 = &g_opstate;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    poVar1->ex010101_af_treble_gain = *psVar2;
    poVar1 = (opstate *)&poVar1->ex010102_af_middle_tone_gain;
    psVar2 = psVar2 + 1;
  }
  psVar2 = &g_opstate.ex010201_af_treble_gain;
  psVar3 = &DAT_fff80e5f;
  for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
    *psVar2 = *psVar3;
    psVar2 = psVar2 + 1;
    psVar3 = psVar3 + 1;
  }
  psVar2 = &g_opstate.ex010301_af_treble_gain;
  psVar3 = &DAT_fff80e72;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *psVar2 = *psVar3;
    psVar2 = psVar2 + 1;
    psVar3 = psVar3 + 1;
  }
  psVar2 = &g_opstate.ex010401_af_treble_gain;
  psVar3 = &DAT_fff80e87;
  for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
    *psVar2 = *psVar3;
    psVar2 = psVar2 + 1;
    psVar3 = psVar3 + 1;
  }
  psVar2 = &g_opstate.ex010501_af_treble_gain;
  psVar3 = &DAT_fff80e9e;
  for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
    *psVar2 = *psVar3;
    psVar2 = psVar2 + 1;
    psVar3 = psVar3 + 1;
  }
  return;
}


// ===== menu_defaults_cw @ fffb11f0 (29 bytes)

/* CW SETTING 0x9A91..0x9AB4 <- ROM 0xFFF80EB1 */

void menu_defaults_cw(void)

{
  sbyte *psVar1;
  sbyte *psVar2;
  int iVar3;
  
  psVar2 = &DAT_fff80eb1;
  psVar1 = &g_opstate.ex020101_af_treble_gain;
  for (iVar3 = 0x24; iVar3 != 0; iVar3 = iVar3 + -1) {
    *psVar1 = *psVar2;
    psVar1 = psVar1 + 1;
    psVar2 = psVar2 + 1;
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
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  uVar1 = dest_code_get();
  pbVar3 = &DAT_fff80ed5;
  pbVar2 = &g_opstate.ex030101_beep_level;
  for (iVar4 = 0x4c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pbVar2 = *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  }
  g_opstate.ex030401_hf_max_power = max_power_limit(0);
  g_opstate.ex030402_50m_max_power = max_power_limit(1);
  g_opstate.ex030403_70m_max_power = max_power_limit(2);
  if (uVar1 == 0x60e6) {
    g_opstate.ex030404_am_max_power = max_power_limit(4);
  }
  else {
    g_opstate.ex030404_am_max_power = max_power_limit(3);
  }
  if (uVar1 == 0xd950) {
    g_opstate.ex030119_keyboard_language = 2;
    g_opstate.ex030115_tx_time_out_timer = 10;
    return;
  }
  if (((uVar1 != 0x1cb9) && (uVar1 != 0x306f)) && (uVar1 != 0x315b)) {
    if (uVar1 == 0x4380) {
      g_opstate.ex030119_keyboard_language = 0;
      return;
    }
    if (uVar1 != 0x50e2) {
      if (uVar1 == 0x60e6) {
        g_opstate.ex030119_keyboard_language = 0;
        return;
      }
      if ((uVar1 != 0x7753) && (uVar1 != 0x9cf7)) {
        if (uVar1 == 0xa4c5) {
          g_opstate.ex030115_tx_time_out_timer = 10;
          g_opstate.ex030119_keyboard_language = 2;
          return;
        }
        if (uVar1 != 0xd32d) {
          if (uVar1 == 0x20b) {
            g_opstate.ex030119_keyboard_language = 0;
            return;
          }
          g_opstate.ex030119_keyboard_language = 5;
          g_opstate.ex030115_tx_time_out_timer = 10;
          return;
        }
      }
    }
  }
  g_opstate.ex030119_keyboard_language = 1;
  return;
}


// ===== menu_defaults_display @ fffb12e6 (29 bytes)

/* DISPLAY SETTING 0x9B01.. <- ROM 0xFFF80F21 */

void menu_defaults_display(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = "FT-710      \x01\x01\x03\x14\n";
  pcVar1 = g_opstate.ex040101_my_call;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return;
}


// ===== FUN_fffb1303 @ fffb1303 (34 bytes)

void FUN_fffb1303(void)

{
  g_opstate.menu_cursor_9b2c[0] = 0;
  g_opstate.menu_cursor_9b2c[1] = 0;
  g_opstate.menu_cursor_9b28[0] = 0;
  g_opstate.menu_cursor_9b28[1] = 0;
  g_opstate.menu_cursor_9b2a[0] = 0;
  g_opstate.menu_cursor_9b2a[1] = 0;
  g_opstate.menu_cursor_9b24[0] = 0;
  g_opstate.menu_cursor_9b24[1] = 0;
  g_opstate.menu_cursor_9b26[0] = 0;
  g_opstate.menu_cursor_9b26[1] = 0;
  return;
}

