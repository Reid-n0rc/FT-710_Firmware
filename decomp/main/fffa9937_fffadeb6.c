// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== cat_EX @ fffa9937 (134 bytes)

void cat_EX(uint param_1,char param_2,ushort param_3)

{
  bool bVar1;
  ushort local_e;
  ushort *local_c;
  ushort local_8;
  char local_5;
  uint local_4;
  
  local_e = 0;
  local_c = &local_e;
  local_8 = param_3;
  local_5 = param_2;
  local_4 = param_1;
  cat_error = ex_command((char *)param_1,param_2,param_3,(byte *)&DAT_00001c8e,local_c);
  if (local_5 == '\0') {
    DAT_0001b788 = *local_c;
    return;
  }
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

void cat_FA_FB(int param_1,char param_2,char param_3)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  void *pvVar6;
  byte local_19;
  uint local_18;
  void *local_14;
  int iStack_10;
  
  if (param_2 == '\0') {
    if (param_3 == '\0') {
      local_14 = (void *)g_ui.freq_a;
    }
    else {
      local_14 = (void *)g_ui.freq_b;
    }
    if ((g_ui.transmitting == 1) && (param_3 == g_opstate.active_vfo)) {
      local_14 = (void *)g_ui.freq_tx;
    }
    local_18 = 100000000;
    for (local_19 = 0; local_19 < 9; local_19 = local_19 + 1) {
      if (local_18 == 0) {
        bVar3 = (byte)local_14;
        pvVar6 = local_14;
      }
      else {
        bVar3 = (byte)((uint)local_14 / local_18);
        pvVar6 = (void *)((uint)local_14 / local_18);
      }
      local_14 = (void *)((int)local_14 - (int)pvVar6 * local_18);
      local_18 = local_18 / 10;
      cVar4 = nib2hex(bVar3);
      (&DAT_00001c90)[local_19] = cVar4;
    }
    DAT_00001c99 = 0x3b;
    DAT_0001b788 = 0xc;
    return;
  }
  if ((g_ui.dialog_shown == 1) || (g_ui.f_0x40d_u8 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cat_error = 1;
    return;
  }
  local_14 = (void *)0x0;
  local_18 = 100000000;
  for (local_19 = 2; local_19 < 0xb; local_19 = local_19 + 1) {
    if ((*(byte *)((uint)local_19 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_19 + param_1))
       ) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      cat_error = 1;
      return;
    }
    local_14 = (void *)((*(byte *)((uint)local_19 + param_1) & 0xf) * local_18 + (int)local_14);
    local_18 = local_18 / 10;
  }
  bVar5 = freq_in_range(local_14);
  bVar2 = g_opstate.vfo_state_b;
  bVar3 = g_opstate.vfo_state_a;
  if (bVar5 == 0) {
    cat_error = 1;
    return;
  }
  if (g_opstate.split_on == 1) {
    g_opstate.vfo_state_a = g_opstate.split_saved_vfo_state_a;
    g_opstate.vfo_state_b = g_opstate.split_saved_vfo_state_a;
  }
  bVar5 = vfo_tune_locked(param_3);
  if (bVar5 != 1) {
    if (param_3 == '\0') {
      if (g_opstate.vfo_state_a == 2) {
        vfo_mem_to_memtune('\0');
      }
    }
    else if (g_opstate.vfo_state_b == 2) {
      vfo_mem_to_memtune(param_3);
    }
    g_ui.freq_clamp_result = freq_clamp(param_3,(uint)local_14);
    if (g_ui.freq_rejected != 1) {
      if (g_opstate.split_on != 1) {
        bVar3 = g_opstate.vfo_state_a;
        bVar2 = g_opstate.vfo_state_b;
      }
      g_opstate.vfo_state_b = bVar2;
      g_opstate.vfo_state_a = bVar3;
      if (param_3 == '\0') {
        iStack_10 = 0x9d09;
      }
      else {
        iStack_10 = 0x9d63;
      }
      for (local_19 = 0; local_19 < 4; local_19 = local_19 + 1) {
        *(char *)((uint)local_19 + iStack_10 + 0x4a) =
             (char)((uint)local_14 >> ((3 - local_19 & 3) << 3));
      }
      for (local_19 = 0; local_19 < 2; local_19 = local_19 + 1) {
        *(undefined1 *)(iStack_10 + (uint)local_19 + 0x48) = 0;
      }
      g_ui.freq_refresh_req = 1;
      vfo_mark_edited(param_3);
      vfo_store_back(param_3);
      return;
    }
    g_opstate.vfo_state_a = bVar3;
    g_opstate.vfo_state_b = bVar2;
    cat_error = 1;
    return;
  }
  g_opstate.vfo_state_a = bVar3;
  g_opstate.vfo_state_b = bVar2;
  cat_error = 1;
  return;
}


// ===== cat_FN @ fffa9c96 (167 bytes)

void cat_FN(int param_1,char param_2)

{
  if (param_2 == '\0') {
    if (g_opstate.fn_select == 1) {
      DAT_00001c90 = 0x31;
    }
    else if (g_opstate.fn_select == 2) {
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
    g_opstate.fn_select = 0;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    g_opstate.fn_select = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '2') {
    cat_error = 1;
    return;
  }
  g_opstate.fn_select = 2;
  return;
}


// ===== cat_FS @ fffa9d3d (17 bytes)

void cat_FS(uint param_1,byte param_2)

{
  cat_error = 1;
  return;
}


// ===== cat_FT @ fffa9d4e (469 bytes)

void cat_FT(int param_1,char param_2)

{
  bool bVar1;
  
  if (param_2 == '\0') {
    if (g_opstate.split_on == 1) {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
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
  if ((bVar1) || (g_ui.f_0x40d_u8 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.msgmem_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
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


// ===== cat_GT @ fffa9f23 (764 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaa1e9) */

void cat_GT(int param_1,char param_2)

{
  radio_mode rVar1;
  byte bVar2;
  vfo_rec *pvVar3;
  uint uVar4;
  byte *pbStack_14;
  byte bStack_e;
  
  pvVar3 = vfo_rec_ptr(VFO_RX);
  rVar1 = vfo_mode(VFO_RX);
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 == '\0') {
    uVar4 = (uint)rVar1;
    if (uVar4 == 0xe) {
LAB_fffaa02c:
      bVar2 = pvVar3->blk[3].flags2;
      if ((bVar2 & 0x40) == 0) {
        bStack_e = 0;
      }
      else {
        uVar4 = (bVar2 & 0x30) >> 4;
        if (uVar4 == 0) {
          bStack_e = 5;
        }
        else if (uVar4 == 3) {
          bStack_e = 3;
        }
        else if (uVar4 == 2) {
          bStack_e = 2;
        }
        else if (uVar4 == 1) {
          bStack_e = 1;
        }
      }
    }
    else {
      if (uVar4 - 2 < 2) {
        bVar2 = pvVar3->blk[1].flags2;
        if ((bVar2 & 0x40) == 0) {
          bStack_e = 0;
        }
        else {
          uVar4 = (bVar2 & 0x30) >> 4;
          if (uVar4 == 3) {
            bStack_e = 3;
          }
          else if (uVar4 == 1) {
            bStack_e = 1;
          }
          else if (uVar4 == 2) {
            bStack_e = 2;
          }
          else if (uVar4 == 0) {
            bStack_e = 4;
          }
        }
        goto LAB_fffaa12f;
      }
      if (uVar4 - 4 < 2) {
        bVar2 = pvVar3->blk[4].flags2;
        if ((bVar2 & 0x40) == 0) {
          bStack_e = 0;
        }
        else {
          uVar4 = (bVar2 & 0x30) >> 4;
          if (uVar4 == 0) {
            bStack_e = 6;
          }
          else if (uVar4 == 3) {
            bStack_e = 3;
          }
          else if (uVar4 == 2) {
            bStack_e = 2;
          }
          else if (uVar4 == 1) {
            bStack_e = 1;
          }
        }
        goto LAB_fffaa12f;
      }
      if (1 < uVar4 - 6) {
        if (uVar4 - 8 < 2) goto LAB_fffaa02c;
        if (1 < uVar4 - 10) {
          if (uVar4 - 0xc < 2) {
            bVar2 = pvVar3->blk[2].flags2;
            if ((bVar2 & 0x40) == 0) {
              bStack_e = 0;
            }
            else {
              uVar4 = (bVar2 & 0x30) >> 4;
              if (uVar4 == 0) {
                bStack_e = 5;
              }
              else if (uVar4 == 3) {
                bStack_e = 3;
              }
              else if (uVar4 == 2) {
                bStack_e = 2;
              }
              else if (uVar4 == 1) {
                bStack_e = 1;
              }
            }
          }
          else if (uVar4 < 2) {
            bVar2 = pvVar3->blk[0].flags2;
            if ((bVar2 & 0x40) == 0) {
              bStack_e = 0;
            }
            else {
              uVar4 = (bVar2 & 0x30) >> 4;
              if (uVar4 == 0) {
                bStack_e = 6;
              }
              else if (uVar4 == 3) {
                bStack_e = 3;
              }
              else if (uVar4 == 2) {
                bStack_e = 2;
              }
              else if (uVar4 == 1) {
                bStack_e = 1;
              }
            }
          }
          goto LAB_fffaa12f;
        }
      }
      bVar2 = pvVar3->blk[5].flags2;
      if ((bVar2 & 0x40) == 0) {
        bStack_e = 0;
      }
      else {
        uVar4 = (bVar2 & 0x30) >> 4;
        if (uVar4 == 3) {
          bStack_e = 3;
        }
        else if (uVar4 == 1) {
          bStack_e = 1;
        }
        else if (uVar4 == 2) {
          bStack_e = 2;
        }
        else if (uVar4 == 0) {
          bStack_e = 4;
        }
      }
    }
LAB_fffaa12f:
    DAT_00001c91 = nib2hex(bStack_e);
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  uVar4 = (uint)rVar1;
  if (uVar4 - 2 < 2) {
    pbStack_14 = &pvVar3->blk[1].flags2;
    goto LAB_fffaa1b3;
  }
  if (uVar4 - 4 < 2) {
    pbStack_14 = &pvVar3->blk[4].flags2;
    goto LAB_fffaa1b3;
  }
  if (uVar4 - 6 < 2) {
LAB_fffaa1ac:
    pbStack_14 = &pvVar3->blk[5].flags2;
  }
  else {
    if (1 < uVar4 - 8) {
      if (uVar4 - 10 < 2) goto LAB_fffaa1ac;
      if (uVar4 - 0xc < 2) {
        pbStack_14 = &pvVar3->blk[2].flags2;
        goto LAB_fffaa1b3;
      }
      if (uVar4 != 0xe) {
        pbStack_14 = &pvVar3->blk[0].flags2;
        goto LAB_fffaa1b3;
      }
    }
    pbStack_14 = &pvVar3->blk[3].flags2;
  }
LAB_fffaa1b3:
  bVar2 = hex2nib(*(byte *)(param_1 + 3));
  if (4 < bVar2) {
    cat_error = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 & 0x8f;
  if (bVar2 == 4) {
    *pbStack_14 = *pbStack_14 | 0x40;
  }
  else if (bVar2 - 1 < 3) {
    *pbStack_14 = *pbStack_14 | 0x40;
    *pbStack_14 = bVar2 << 4 | *pbStack_14;
  }
  g_ui.freq_refresh_req = 1;
  vfo_mark_edited(g_opstate.active_vfo);
  vfo_store_back(g_opstate.active_vfo);
  return;
}


// ===== cat_GP @ fffaa21f (326 bytes)

void cat_GP(int param_1,char param_2)

{
  bool bVar1;
  tunlin_mode tVar2;
  byte bVar3;
  
  tVar2 = tunlin_port_mode();
  if (tVar2 != TUNLIN_GPO) {
    cat_error = 1;
    return;
  }
  if (param_2 == '\0') {
    bVar3 = gpo_a_get();
    DAT_00001c90 = nib2hex(bVar3);
    bVar3 = gpo_b_get();
    DAT_00001c91 = nib2hex(bVar3);
    bVar3 = gpo_c_get();
    DAT_00001c92 = nib2hex(bVar3);
    bVar3 = gpo_d_get();
    DAT_00001c93._0_1_ = nib2hex(bVar3);
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
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
    cat_error = 1;
    return;
  }
  bVar3 = hex2nib(*(byte *)(param_1 + 2));
  gpo_a_set(bVar3);
  bVar3 = hex2nib(*(byte *)(param_1 + 3));
  gpo_b_set(bVar3);
  bVar3 = hex2nib(*(byte *)(param_1 + 4));
  gpo_c_set(bVar3);
  bVar3 = hex2nib(*(byte *)(param_1 + 5));
  gpo_d_set(bVar3);
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

void cat_IF_OI(char param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  ushort uVar4;
  byte local_27;
  byte local_26;
  byte local_25;
  byte abStack_24 [9];
  byte local_1b;
  byte local_1a;
  byte local_19;
  ushort uStack_18;
  ushort uStack_16;
  uint uStack_14;
  uint uStack_10;
  vfo_rec *local_c;
  vfo_side local_5;
  
  if (param_1 == '\0') {
    local_c = &g_opstate.vfo_a;
    local_1a = g_mem_hdr.chan_a;
    local_25 = g_opstate.vfo_state_a;
    local_27 = g_ui.clar_flags_a;
  }
  else {
    local_c = &g_opstate.vfo_b;
    local_1a = g_mem_hdr.chan_b;
    local_25 = g_opstate.vfo_state_b;
    local_27 = g_ui.clar_flags_b;
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
      uVar3 = (uint)local_19;
      cVar2 = nib2hex(local_1b);
      (&DAT_00001c90)[uVar3] = cVar2;
    }
  }
  else {
    local_1a = local_1a + 0x9d;
    DAT_00001c92 = BYTE_ARRAY_fff805ac[(uint)local_1a * 3 + 0x13f];
    _DAT_00001c90 = *(undefined2 *)(BYTE_ARRAY_fff805ac + (uint)local_1a * 3 + 0x13d);
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
  uStack_10 = vfo_freq(VFO_RX,local_5);
  uStack_14 = 100000000;
  for (local_19 = 0; local_19 < 9; local_19 = local_19 + 1) {
    uVar3 = uStack_10;
    if (uStack_14 != 0) {
      uVar3 = uStack_10 / uStack_14;
    }
    abStack_24[local_19] = (byte)uVar3;
    uVar3 = uStack_10;
    if (uStack_14 != 0) {
      uVar3 = uStack_10 / uStack_14;
    }
    uStack_10 = uStack_10 - uVar3 * uStack_14;
    uStack_14 = uStack_14 / 10;
  }
  for (local_19 = 0; local_19 < 9; local_19 = local_19 + 1) {
    uVar3 = (uint)local_19;
    cVar2 = nib2hex(abStack_24[uVar3]);
    *(char *)((int)&DAT_00001c93 + uVar3) = cVar2;
  }
  uStack_16 = CONCAT11(local_c->clar_offset_be[0],local_c->clar_offset_be[1]);
  if ((local_c->clar_offset_be[0] & 0x80) == 0) {
    DAT_00001c9c = 0x2b;
  }
  else {
    DAT_00001c9c = 0x2d;
    uStack_16 = ~uStack_16 + 1;
  }
  uStack_18 = 1000;
  for (local_19 = 0; local_19 < 4; local_19 = local_19 + 1) {
    uVar3 = (uint)uStack_16;
    if (uStack_18 != 0) {
      uVar3 = uVar3 / uStack_18;
    }
    abStack_24[local_19] = (byte)uVar3;
    uVar4 = uStack_16;
    if (uStack_18 != 0) {
      uVar4 = uStack_16 / uStack_18;
    }
    uStack_16 = uStack_16 - uVar4 * uStack_18;
    uStack_18 = uStack_18 / 10;
  }
  for (local_19 = 0; local_19 < 4; local_19 = local_19 + 1) {
    uVar3 = (uint)local_19;
    cVar2 = nib2hex(abStack_24[uVar3]);
    (&DAT_00001c9d)[uVar3] = cVar2;
  }
  if (local_27 == 0) {
    DAT_00001ca1 = 0x30;
    DAT_00001ca2 = 0x30;
  }
  else if (local_27 == 1) {
    DAT_00001ca1 = 0x31;
    DAT_00001ca2 = 0x30;
  }
  else if (local_27 == 2) {
    DAT_00001ca1 = 0x30;
    DAT_00001ca2 = 0x31;
  }
  else if (local_27 == 3) {
    DAT_00001ca1 = 0x31;
    DAT_00001ca2 = 0x31;
  }
  DAT_00001ca3 = BYTE_ARRAY_fff805ac[(local_c->mode & 0xf) + 0x124];
  DAT_00001ca4 = BYTE_ARRAY_fff805ac[local_25 + 0x133];
  cVar2 = (char)((local_c->flags3 & 0x38) >> 3);
  if (cVar2 == '\x01') {
    DAT_00001ca5 = 0x32;
  }
  else if (cVar2 == '\x02') {
    DAT_00001ca5 = 0x31;
  }
  else {
    DAT_00001ca5 = 0x30;
  }
  DAT_00001ca7 = 0x30;
  DAT_00001ca6 = 0x30;
  cVar2 = (char)((local_c->flags2 & 0xc) >> 2);
  if (cVar2 == '\0') {
    DAT_00001ca8 = 0x32;
  }
  else if (cVar2 == '\x02') {
    DAT_00001ca8 = 0x31;
  }
  else {
    DAT_00001ca8 = 0x30;
  }
  DAT_00001ca9 = 0x3b;
  DAT_0001b788 = 0x1c;
  return;
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

void cat_IS(int param_1,char param_2)

{
  bool bVar1;
  radio_mode rVar2;
  char cVar3;
  vfo_rec *pvVar4;
  uint uVar5;
  ushort uVar6;
  byte *pbStack_1c;
  byte bStack_17;
  ushort uStack_14;
  ushort uStack_12;
  
  pvVar4 = vfo_rec_ptr(VFO_RX);
  rVar2 = vfo_mode(VFO_RX);
  uVar5 = (uint)rVar2;
  if (uVar5 - 2 < 2) {
    pbStack_1c = pvVar4->blk[1].shift_be;
    goto LAB_fffaa75f;
  }
  if (uVar5 - 4 < 2) {
    pbStack_1c = pvVar4->blk[4].shift_be;
    goto LAB_fffaa75f;
  }
  if (uVar5 - 6 < 2) {
LAB_fffaa758:
    pbStack_1c = pvVar4->blk[5].shift_be;
  }
  else {
    if (1 < uVar5 - 8) {
      if (uVar5 - 10 < 2) goto LAB_fffaa758;
      if (uVar5 - 0xc < 2) {
        pbStack_1c = pvVar4->blk[2].shift_be;
        goto LAB_fffaa75f;
      }
      if (uVar5 != 0xe) {
        pbStack_1c = pvVar4->blk[0].shift_be;
        goto LAB_fffaa75f;
      }
    }
    pbStack_1c = pvVar4->blk[3].shift_be;
  }
LAB_fffaa75f:
  if (param_2 == '\0') {
    DAT_00001c91 = 0x30;
    DAT_00001c90 = 0x30;
    uStack_12 = 0;
    for (bStack_17 = 0; bStack_17 < 2; bStack_17 = bStack_17 + 1) {
      uStack_12 = (ushort)pbStack_1c[bStack_17] | uStack_12 << 8;
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
      uVar5 = (uint)uStack_12;
      if (uStack_14 != 0) {
        uVar5 = uVar5 / uStack_14;
      }
      uVar6 = uStack_12;
      if (uStack_14 != 0) {
        uVar6 = uStack_12 / uStack_14;
      }
      uStack_12 = uStack_12 - uVar6 * uStack_14;
      uStack_14 = uStack_14 / 10;
      cVar3 = nib2hex((byte)uVar5);
      *(char *)((int)&DAT_00001c93 + (uint)bStack_17) = cVar3;
    }
    DAT_00001c97 = 0x3b;
    DAT_0001b788 = 10;
    return;
  }
  uStack_12 = 0;
  uStack_14 = 1000;
  bStack_17 = 5;
  while( true ) {
    if (8 < bStack_17) {
      if (12000 < uStack_12) {
        cat_error = 1;
        return;
      }
      if (*(char *)(param_1 + 4) == '-') {
        uStack_12 = ~uStack_12 + 1;
      }
      else if (*(char *)(param_1 + 4) != '+') {
        cat_error = 1;
        return;
      }
      for (bStack_17 = 0; bStack_17 < 2; bStack_17 = bStack_17 + 1) {
        pbStack_1c[bStack_17] = (byte)(uStack_12 >> ((1 - bStack_17 & 3) << 3));
      }
      g_ui.freq_refresh_req = 1;
      vfo_mark_edited(g_opstate.active_vfo);
      vfo_store_back(g_opstate.active_vfo);
      return;
    }
    if ((*(byte *)((uint)bStack_17 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_17 + param_1))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) break;
    uStack_12 = (*(byte *)((uint)bStack_17 + param_1) & 0xf) * uStack_14 + uStack_12;
    uStack_14 = uStack_14 / 10;
    bStack_17 = bStack_17 + 1;
  }
  cat_error = 1;
  return;
}


// ===== cat_KM @ fffaa905 (817 bytes)

void cat_KM(int param_1,char param_2,ushort param_3)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  byte bStack_d;
  
  bVar2 = hex2nib(*(byte *)(param_1 + 2));
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 2) == '1') {
      bStack_d = DAT_0000969f;
      puVar4 = &DAT_000096a0;
      puVar3 = &DAT_00001c91;
      for (uVar6 = (uint)DAT_0000969f; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    else if (*(char *)(param_1 + 2) == '2') {
      bStack_d = DAT_000096d2;
      puVar4 = &DAT_000096d3;
      puVar3 = &DAT_00001c91;
      for (uVar6 = (uint)DAT_000096d2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    else if (*(char *)(param_1 + 2) == '3') {
      bStack_d = DAT_00009705;
      puVar4 = &DAT_00009706;
      puVar3 = &DAT_00001c91;
      for (uVar6 = (uint)DAT_00009705; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    else if (*(char *)(param_1 + 2) == '4') {
      bStack_d = DAT_00009738;
      puVar4 = &DAT_00009739;
      puVar3 = &DAT_00001c91;
      for (uVar6 = (uint)DAT_00009738; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    else {
      if (*(char *)(param_1 + 2) != '5') {
        cat_error = 1;
        return;
      }
      bStack_d = DAT_0000976b;
      puVar4 = &DAT_0000976c;
      puVar3 = &DAT_00001c91;
      for (uVar6 = (uint)DAT_0000976b; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
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
  if ((g_ui.kbd_open == 1) && (g_ui.kbd_target == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && ((uint)bVar2 == g_ui.msg_slot_idx + 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cat_error = 1;
    return;
  }
  bVar2 = (char)param_3 - 4;
  if (*(char *)(param_1 + 2) == '1') {
    puVar3 = &DAT_000096a0;
    for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = 0x20;
      puVar3 = puVar3 + 1;
    }
    puVar4 = (undefined1 *)(param_1 + 3);
    puVar3 = &DAT_000096a0;
    for (uVar6 = (uint)bVar2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar5 = mem_find_byte(param_1 + 3,0x7d,0x32);
    if (iVar5 == param_1 + 3) {
      (&DAT_000096a0)[bVar2] = 0x7d;
    }
    DAT_0000969f = bVar2;
    eeprom_save_msg(1,1);
    return;
  }
  if (*(char *)(param_1 + 2) != '2') {
    if (*(char *)(param_1 + 2) == '3') {
      puVar3 = &DAT_00009706;
      for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = 0x20;
        puVar3 = puVar3 + 1;
      }
      puVar4 = (undefined1 *)(param_1 + 3);
      puVar3 = &DAT_00009706;
      for (uVar6 = (uint)bVar2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar3 = *puVar4;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar5 = mem_find_byte(param_1 + 3,0x7d,0x32);
      if (iVar5 == param_1 + 3) {
        (&DAT_00009706)[bVar2] = 0x7d;
      }
      DAT_00009705 = bVar2;
      eeprom_save_msg(1,3);
      return;
    }
    if (*(char *)(param_1 + 2) != '4') {
      if (*(char *)(param_1 + 2) == '5') {
        puVar3 = &DAT_0000976c;
        for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar3 = 0x20;
          puVar3 = puVar3 + 1;
        }
        puVar4 = (undefined1 *)(param_1 + 3);
        puVar3 = &DAT_0000976c;
        for (uVar6 = (uint)bVar2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar3 = *puVar4;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        iVar5 = mem_find_byte(param_1 + 3,0x7d,0x32);
        if (iVar5 == param_1 + 3) {
          (&DAT_0000976c)[bVar2] = 0x7d;
        }
        DAT_0000976b = bVar2;
        eeprom_save_msg(1,5);
        return;
      }
      cat_error = 1;
      return;
    }
    puVar3 = &DAT_00009739;
    for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = 0x20;
      puVar3 = puVar3 + 1;
    }
    puVar4 = (undefined1 *)(param_1 + 3);
    puVar3 = &DAT_00009739;
    for (uVar6 = (uint)bVar2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar5 = mem_find_byte(param_1 + 3,0x7d,0x32);
    if (iVar5 == param_1 + 3) {
      (&DAT_00009739)[bVar2] = 0x7d;
    }
    DAT_00009738 = bVar2;
    eeprom_save_msg(1,4);
    return;
  }
  puVar3 = &DAT_000096d3;
  for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0x20;
    puVar3 = puVar3 + 1;
  }
  puVar4 = (undefined1 *)(param_1 + 3);
  puVar3 = &DAT_000096d3;
  for (uVar6 = (uint)bVar2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar5 = mem_find_byte(param_1 + 3,0x7d,0x32);
  if (iVar5 == param_1 + 3) {
    (&DAT_000096d3)[bVar2] = 0x7d;
  }
  DAT_000096d2 = bVar2;
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

void cat_KP(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_b = 10;
    local_d = g_opstate.cw_pitch;
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
  if (0x4b < local_d) {
    cat_error = 1;
    return;
  }
  g_opstate.cw_pitch = local_d;
  if (g_opstate.ex030126_scu_lan10 == 0) {
    g_ui.popup_code = 0x31;
    popup_duration_get(0x31);
    popup_open_timed();
    return;
  }
  return;
}


// ===== cat_KR @ fffaad52 (152 bytes)

void cat_KR(int param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(g_opstate.keyer_on);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar1 = key_event_filter(0xe0,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  iVar2 = vfo_mode_is_cw();
  if (iVar2 == 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    if (*(char *)(param_1 + 2) != '0') {
      cat_error = 1;
      return;
    }
    g_opstate.keyer_on = 0;
    return;
  }
  g_opstate.keyer_on = 1;
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

void cat_KS(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_b = 100;
    local_d = g_opstate.key_speed;
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
  if ((local_d < 4) || (0x3c < local_d)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    g_opstate.key_speed = local_d;
    if (g_opstate.ex030126_scu_lan10 != 0) {
      return;
    }
    g_ui.popup_code = 0x30;
    popup_duration_get(0x30);
    popup_open_timed();
    return;
  }
  cat_error = 1;
  return;
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

void cat_KY(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = key_event_filter(0x87,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  iVar3 = vfo_mode_is_cw();
  if (iVar3 != 1) {
    cat_error = 1;
    return;
  }
  g_ui.msgmem_type = 1;
  if (g_ui.playlist_open == 1) {
    cat_error = 1;
    return;
  }
  if (0x31 < *(byte *)(param_1 + 2)) {
    cat_error = 1;
    return;
  }
  bVar1 = hex2nib(*(byte *)(param_1 + 3));
  if (bVar1 == 0) {
    g_ui.keyer_state = 7;
    return;
  }
  if (5 < bVar1) {
    cat_error = 1;
    return;
  }
  bVar2 = hex2nib(*(byte *)(param_1 + 2));
  g_opstate.ex020205_contest_number_be[bVar1 + 1] = bVar2;
  msg_slot_select(bVar1);
  if (*(char *)(param_1 + 2) == '0') {
    g_ui.ky_send_0 = 1;
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      cat_error = 1;
      return;
    }
    g_ui.ky_send_1 = 1;
  }
  iVar3 = FUN_fffe564b();
  if (iVar3 == 0) {
    g_ui.ky_send_1 = 0;
    g_ui.ky_send_0 = 0;
    cat_error = 1;
    return;
  }
  iVar3 = FUN_fffe5401(bVar1);
  if (iVar3 == 0) {
    g_ui.ky_send_1 = 0;
    g_ui.ky_send_0 = 0;
    beep_request(3);
    cat_error = 1;
    return;
  }
  if (g_ui.keyer_state == 1) {
    g_ui.keyer_state = 5;
    return;
  }
  msg_cw_stop();
  g_ui.ky_queued = 1;
  return;
}


// ===== cat_LK @ fffab09f (208 bytes)

void cat_LK(int param_1,char param_2)

{
  byte bVar1;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(g_opstate.lock_on);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar1 = key_event_filter(0x300,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    g_opstate.lock_on = 1;
    if (g_opstate.ex030126_scu_lan10 == 0) {
      g_ui.popup_code = 0x47;
      popup_duration_get(0x47);
      popup_open_timed();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '0') {
      cat_error = 1;
      return;
    }
    g_opstate.lock_on = 0;
    if (g_opstate.ex030126_scu_lan10 == 0) {
      g_ui.popup_code = 0x48;
      popup_duration_get(0x48);
      popup_open_timed();
      return;
    }
  }
  return;
}


// ===== cat_LM @ fffab16f (654 bytes)

void cat_LM(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 2) == '0') {
      if (g_ui.dvs_state == 2) {
        DAT_00001c91 = nib2hex(g_ui.dvs_slot + 1);
      }
      else {
        DAT_00001c91 = '0';
      }
    }
    else if (*(char *)(param_1 + 2) == '1') {
      DAT_00001c91 = nib2hex(g_ui.dvs_lm1_flag);
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  bVar2 = key_event_filter(0x87,0);
  if (bVar2 == 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '0') {
    if (*(char *)(param_1 + 2) != '1') {
      return;
    }
    if ((g_ui.dvs_state == 1) || (g_ui.dvs_state == 2)) {
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
    if (!bVar1) {
      if (*(char *)(param_1 + 3) == '0') {
        g_ui.dvs_lm1_flag = 0;
      }
      else {
        if (*(char *)(param_1 + 3) != '1') {
          cat_error = 1;
          return;
        }
        if (g_ui.dvs_lm1_flag != 1) {
          g_ui.dvs_lm1_flag = 1;
        }
      }
      g_ui.dl_req_3f = 1;
      return;
    }
    cat_error = 1;
    return;
  }
  if ((g_ui.dvs_lm1_flag == 1) || (g_ui.msg_rec_active == 1)) {
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
  if (bVar1) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    g_ui.dvs_state = 0;
    g_ui.dvs_busy = 0;
    g_ui.dvs_armed = 0;
    return;
  }
  if (*(byte *)(param_1 + 3) < 0x36) {
    iVar3 = msg_voice_mode_ok();
    if (iVar3 != 1) {
      cat_error = 1;
      return;
    }
    if (g_ui.dvs_state != 0) {
      cat_error = 1;
      return;
    }
    g_ui.msg_slot = hex2nib(*(byte *)(param_1 + 3));
    g_ui.msgmem_type = 0;
    g_ui.dvs_busy = 1;
    g_ui.dvs_armed = 1;
    g_ui.dvs_slot = g_ui.msg_slot - 1;
    FUN_fffe4efc();
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_MA @ fffab3fd (123 bytes)

void cat_MA(void)

{
  byte bVar1;
  vfo_rec *pvVar2;
  vfo_rec *pvVar3;
  int iVar4;
  
  pvVar3 = memch + g_mem_hdr.chan_a;
  bVar1 = key_event_filter(0x308,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  if (g_ui.tx_lamp == 0) {
    pvVar2 = &g_opstate.vfo_a;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      pvVar2->mode = pvVar3->mode;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pvVar3 = (vfo_rec *)&pvVar3->flags1;
    }
    vfo_mark_edited(0);
    vfo_store_back(0);
    g_ui.freq_refresh_req = 1;
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_MB @ fffab478 (123 bytes)

void cat_MB(void)

{
  byte bVar1;
  vfo_rec *pvVar2;
  vfo_rec *pvVar3;
  int iVar4;
  
  pvVar3 = memch + g_mem_hdr.chan_b;
  bVar1 = key_event_filter(0x308,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  if (g_ui.tx_lamp == 0) {
    pvVar2 = &g_opstate.vfo_b;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      pvVar2->mode = pvVar3->mode;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pvVar3 = (vfo_rec *)&pvVar3->flags1;
    }
    vfo_mark_edited(1);
    vfo_store_back(1);
    g_ui.freq_refresh_req = 1;
    return;
  }
  cat_error = 1;
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

void cat_MC(int param_1,byte param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  vfo_rec *pvVar6;
  vfo_rec *pvVar7;
  byte *pbStack_1c;
  vfo_rec *pvStack_18;
  vfo_rec *pvStack_14;
  byte local_e;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  byte bStack_a;
  byte local_9;
  int local_8;
  
  local_e = 0;
  local_9 = param_2;
  local_8 = param_1;
  pvStack_18 = vfo_rec_ptr(VFO_RX);
  toupper_inplace((char *)(local_8 + 2));
  toupper_inplace((char *)(local_8 + 3));
  toupper_inplace((char *)(local_8 + 4));
  bStack_d = g_opstate.active_vfo;
  if (local_9 == 0) {
    if (g_opstate.active_vfo == 0) {
      local_e = g_mem_hdr.chan_a;
    }
    else {
      local_e = g_mem_hdr.chan_b;
    }
    if (local_e < 99) {
      local_e = local_e + 1;
      bStack_b = 100;
      for (bStack_a = 0; bStack_a < 3; bStack_a = bStack_a + 1) {
        bStack_c = local_e;
        if (bStack_b != 0) {
          bStack_c = local_e / bStack_b;
        }
        local_e = local_e - bStack_c * bStack_b;
        bStack_b = bStack_b / 10;
        uVar1 = (uint)bStack_a;
        cVar2 = nib2hex(bStack_c);
        (&DAT_00001c90)[uVar1] = cVar2;
      }
    }
    else {
      iVar5 = (uint)(byte)(local_e + 0x9d) * 3;
      DAT_00001c92 = BYTE_ARRAY_fff805ac[iVar5 + 0x13f];
      _DAT_00001c90 = *(undefined2 *)(BYTE_ARRAY_fff805ac + iVar5 + 0x13d);
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  if (g_ui.tx_lamp != 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(local_8 + 2) == '0') {
    bStack_c = 0;
    bStack_b = 100;
    for (bStack_a = 2; bStack_a < 5; bStack_a = bStack_a + 1) {
      if ((*(byte *)((uint)bStack_a + local_8) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_a + local_8))) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (bVar4) {
        cat_error = 1;
        return;
      }
      bStack_c = (*(byte *)((uint)bStack_a + local_8) & 0xf) * bStack_b + bStack_c;
      bStack_b = bStack_b / 10;
    }
    if ((bStack_c == 0) || (99 < bStack_c)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (!bVar4) {
      cat_error = 1;
      return;
    }
    local_e = bStack_c - 1;
  }
  else {
    local_e = 0;
    for (bStack_b = 0; bStack_b < 0x22; bStack_b = bStack_b + 1) {
      iVar5 = strncmp((uint)bStack_b * 3 + -0x7f917,local_8 + 2,3);
      if (iVar5 == 0) {
        local_e = bStack_b + 99;
        break;
      }
    }
    if (local_e < 99) {
      cat_error = 1;
      return;
    }
  }
  if ((local_e < 0x84) && (0x74 < local_e)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (bVar4) {
    iVar5 = dest_has_5mhz_channels();
    if (iVar5 != 1) {
      cat_error = 1;
      return;
    }
    bVar3 = memch_dest_blocked(local_e);
    if (bVar3 == 1) {
      cat_error = 1;
      return;
    }
  }
  if ((g_opstate.ex030406_emergency_freq_tx == 0) && (local_e == 0x84)) {
    cat_error = 1;
    return;
  }
  bVar4 = memch_valid(local_e,&pbStack_1c);
  if (!bVar4) {
    cat_error = 1;
    return;
  }
  if (bStack_d == 0) {
    g_mem_hdr.chan_a = local_e;
    g_opstate.vfo_state_a = 2;
    pvVar6 = &g_opstate.memtune_a;
    pvVar7 = pvStack_18;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      pvVar6->mode = pvVar7->mode;
      pvVar6 = (vfo_rec *)&pvVar6->flags1;
      pvVar7 = (vfo_rec *)&pvVar7->flags1;
    }
  }
  else {
    g_mem_hdr.chan_b = local_e;
    g_opstate.vfo_state_b = 2;
    pvVar6 = &g_opstate.memtune_b;
    pvVar7 = pvStack_18;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      pvVar6->mode = pvVar7->mode;
      pvVar6 = (vfo_rec *)&pvVar6->flags1;
      pvVar7 = (vfo_rec *)&pvVar7->flags1;
    }
  }
  pvStack_14 = memch + local_e;
  pvVar7 = pvStack_18;
  pvVar6 = pvStack_14;
  for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
    pvVar7->mode = pvVar6->mode;
    pvVar7 = (vfo_rec *)&pvVar7->flags1;
    pvVar6 = (vfo_rec *)&pvVar6->flags1;
  }
  eeprom_save_memch(1);
  g_ui.freq_refresh_req = 1;
  return;
}


// ===== cat_MD @ fffab7d1 (659 bytes)

void cat_MD(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  radio_mode rStack_e;
  radio_mode local_d;
  vfo_rec *local_c;
  
  if (*(char *)(param_1 + 2) == '0') {
    if (g_opstate.active_vfo == 0) {
      local_c = &g_opstate.vfo_a;
    }
    else {
      local_c = &g_opstate.vfo_b;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      cat_error = 1;
      return;
    }
    if (g_opstate.active_vfo == 0) {
      local_c = &g_opstate.vfo_b;
    }
    else {
      local_c = &g_opstate.vfo_a;
    }
  }
  if (param_2 == '\0') {
    DAT_00001c91 = BYTE_ARRAY_fff805ac[(local_c->mode & 0xf) + 0x124];
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  bVar2 = key_event_filter(0x30c,0);
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
  if ((bVar1) || (g_ui.f_0x40d_u8 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (g_ui.msgmem_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cat_error = 1;
    return;
  }
  g_ui.msg_active = 0;
  local_d = MODE_NONE;
  toupper_inplace((char *)(param_1 + 3));
  rStack_e = MODE_LSB;
  do {
    if (MODE_PSK < rStack_e) {
LAB_fffaba23:
      if (local_d == MODE_NONE) {
        cat_error = 1;
        return;
      }
      if (*(char *)(param_1 + 2) == '0') {
        FUN_fffc4bd5(local_d);
        return;
      }
      if (*(char *)(param_1 + 2) == '1') {
        local_c->mode = local_c->mode & ~MODE_15 | local_d;
        return;
      }
      return;
    }
    if (*(byte *)(param_1 + 3) == BYTE_ARRAY_fff805ac[rStack_e + 0x124]) {
      local_d = rStack_e;
      goto LAB_fffaba23;
    }
    rStack_e = rStack_e + MODE_USB;
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

void cat_MG(int param_1,char param_2)

{
  uint uVar1;
  bool bVar2;
  radio_mode rVar3;
  char cVar4;
  byte n;
  byte *pbStack_1c;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  ushort uStack_14;
  
  rVar3 = vfo_mode(VFO_RX);
  uVar1 = (uint)rVar3;
  if (uVar1 == 0xe) {
LAB_fffabab6:
    pbStack_1c = g_opstate.mic_gain + 1;
    bStack_18 = g_opstate.mic_gain[1];
  }
  else {
    if (uVar1 - 4 < 2) {
      pbStack_1c = g_opstate.mic_gain + 2;
      bStack_18 = g_opstate.mic_gain[2];
      goto LAB_fffabaef;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffabab6;
      if (1 < uVar1 - 10) {
        if (1 < uVar1) {
          cat_error = 1;
          return;
        }
        pbStack_1c = g_opstate.mic_gain;
        bStack_18 = g_opstate.mic_gain[0];
        goto LAB_fffabaef;
      }
    }
    pbStack_1c = g_opstate.mic_gain + 3;
    bStack_18 = g_opstate.mic_gain[3];
  }
LAB_fffabaef:
  if (param_2 == '\0') {
    bStack_17 = 100;
    for (bStack_16 = 0; bStack_16 < 3; bStack_16 = bStack_16 + 1) {
      n = bStack_18;
      if (bStack_17 != 0) {
        n = bStack_18 / bStack_17;
      }
      bStack_18 = bStack_18 - n * bStack_17;
      bStack_17 = bStack_17 / 10;
      cVar4 = nib2hex(n);
      (&DAT_00001c90)[bStack_16] = cVar4;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  uStack_14 = 0;
  bStack_17 = 100;
  bStack_16 = 2;
  while( true ) {
    if (4 < bStack_16) {
      if (uStack_14 < 0x65) {
        *pbStack_1c = (byte)uStack_14;
        if (g_opstate.ex030126_scu_lan10 == 0) {
          g_ui.popup_code = 0x25;
          popup_duration_get(0x25);
          popup_open_timed();
        }
        g_ui.freq_refresh_req = 1;
        return;
      }
      cat_error = 1;
      return;
    }
    if ((*(byte *)((uint)bStack_16 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_16 + param_1))) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) break;
    uStack_14 = (*(byte *)((uint)bStack_16 + param_1) & 0xf) * (ushort)bStack_17 + uStack_14;
    bStack_17 = bStack_17 / 10;
    bStack_16 = bStack_16 + 1;
  }
  cat_error = 1;
  return;
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

void cat_ML(int param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  radio_mode rVar3;
  char cVar4;
  byte n;
  byte *pbStack_1c;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  rVar3 = vfo_mode(VFO_RX);
  uVar2 = (uint)rVar3;
  if (uVar2 == 0xe) {
LAB_fffabc78:
    bStack_12 = g_opstate.monitor[3];
    pbStack_1c = g_opstate.monitor + 3;
  }
  else {
    if (uVar2 - 2 < 2) {
      bStack_12 = g_opstate.monitor[1];
      pbStack_1c = g_opstate.monitor + 1;
      goto LAB_fffabcc3;
    }
    if (uVar2 - 4 < 2) {
      bStack_12 = g_opstate.monitor[4];
      pbStack_1c = g_opstate.monitor + 4;
      goto LAB_fffabcc3;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 - 8 < 2) goto LAB_fffabc78;
      if (1 < uVar2 - 10) {
        if (uVar2 - 0xc < 2) {
          bStack_12 = g_opstate.monitor[2];
          pbStack_1c = g_opstate.monitor + 2;
        }
        else {
          if (1 < uVar2) {
            cat_error = 1;
            return;
          }
          bStack_12 = g_opstate.monitor[0];
          pbStack_1c = g_opstate.monitor;
        }
        goto LAB_fffabcc3;
      }
    }
    if (param_2 == '\x01') {
      cat_error = 1;
      return;
    }
    bStack_12 = g_opstate.f_0x1d7_u8;
    pbStack_1c = &g_opstate.f_0x1d7_u8;
  }
LAB_fffabcc3:
  bVar1 = *(char *)(param_1 + 2) == '0';
  if (param_2 == '\0') {
    if (bVar1) {
      DAT_00001c91 = 0x30;
      DAT_00001c92 = 0x30;
      if (bStack_12 == 0) {
        DAT_00001c93._0_1_ = 0x30;
      }
      else {
        DAT_00001c93._0_1_ = 0x31;
      }
      DAT_00001c93._1_1_ = 0x3b;
      DAT_0001b788 = 7;
      return;
    }
    if (*(char *)(param_1 + 2) != '1') {
      cat_error = 1;
      return;
    }
    bStack_13 = 100;
    for (bStack_14 = 0; bStack_14 < 3; bStack_14 = bStack_14 + 1) {
      n = bStack_12;
      if (bStack_13 != 0) {
        n = bStack_12 / bStack_13;
      }
      bStack_12 = bStack_12 - n * bStack_13;
      bStack_13 = bStack_13 / 10;
      cVar4 = nib2hex(n);
      (&DAT_00001c91)[bStack_14] = cVar4;
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  if (bVar1) {
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      cat_error = 1;
      return;
    }
    if (*(char *)(param_1 + 5) == '0') {
      *pbStack_1c = 0;
      return;
    }
    if (*(char *)(param_1 + 5) == '1') {
      *pbStack_1c = 0x32;
      return;
    }
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    cat_error = 1;
    return;
  }
  bStack_12 = 0;
  bStack_13 = 100;
  for (bStack_14 = 3; bStack_14 < 6; bStack_14 = bStack_14 + 1) {
    if ((*(byte *)((uint)bStack_14 + param_1) < 0x30) ||
       (0x39 < *(byte *)((uint)bStack_14 + param_1))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      cat_error = 1;
      return;
    }
    bStack_12 = (*(byte *)((uint)bStack_14 + param_1) & 0xf) * bStack_13 + bStack_12;
    bStack_13 = bStack_13 / 10;
  }
  if (100 < bStack_12) {
    cat_error = 1;
    return;
  }
  *pbStack_1c = bStack_12;
  if (g_opstate.ex030126_scu_lan10 == 0) {
    g_ui.popup_code = 0x2d;
    popup_duration_get(0x2d);
    popup_open_timed();
    return;
  }
  return;
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

void cat_MR(int param_1,byte param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  byte bStack_30;
  byte bStack_2e;
  byte abStack_2d [9];
  byte bStack_24;
  byte bStack_22;
  byte bStack_21;
  ushort uStack_20;
  ushort uStack_1e;
  byte *pbStack_1c;
  uint uStack_18;
  uint uStack_14;
  vfo_rec *pvStack_10;
  byte local_9;
  int local_8;
  
  local_9 = param_2;
  local_8 = param_1;
  toupper_inplace((char *)(param_1 + 2));
  toupper_inplace((char *)(local_8 + 3));
  toupper_inplace((char *)(local_8 + 4));
  if (*(char *)(local_8 + 2) == '0') {
    bStack_24 = 0;
    bStack_22 = 100;
    for (bStack_21 = 2; bStack_21 < 5; bStack_21 = bStack_21 + 1) {
      if ((*(byte *)((uint)bStack_21 + local_8) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_21 + local_8))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        cat_error = 1;
        return;
      }
      bStack_24 = (*(byte *)((uint)bStack_21 + local_8) & 0xf) * bStack_22 + bStack_24;
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
      iVar3 = strncmp((uint)bStack_22 * 3 + -0x7f917,local_8 + 2,3);
      if (iVar3 == 0) {
        bStack_30 = bStack_22 + 99;
        break;
      }
    }
    if (bStack_30 < 99) {
      cat_error = 1;
      return;
    }
  }
  bVar1 = memch_valid(bStack_30,&pbStack_1c);
  if (!bVar1) {
    cat_error = 1;
    return;
  }
  pvStack_10 = memch + bStack_30;
  if (g_opstate.active_vfo == 0) {
    bStack_2e = g_opstate.vfo_state_a;
  }
  else {
    bStack_2e = g_opstate.vfo_state_b;
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
      uVar4 = (uint)bStack_21;
      cVar2 = nib2hex(bStack_24);
      (&DAT_00001c90)[uVar4] = cVar2;
    }
  }
  else {
    iVar3 = (uint)(byte)(bStack_30 + 0x9d) * 3;
    DAT_00001c92 = BYTE_ARRAY_fff805ac[iVar3 + 0x13f];
    _DAT_00001c90 = *(undefined2 *)(BYTE_ARRAY_fff805ac + iVar3 + 0x13d);
  }
  uStack_14 = 0;
  for (bStack_21 = 0; bStack_21 < 4; bStack_21 = bStack_21 + 1) {
    uStack_14 = (uint)pvStack_10->freq_be[bStack_21] | uStack_14 << 8;
  }
  if (uStack_14 != 0) {
    uStack_18 = 100000000;
    for (bStack_21 = 0; bStack_21 < 9; bStack_21 = bStack_21 + 1) {
      uVar4 = uStack_14;
      if (uStack_18 != 0) {
        uVar4 = uStack_14 / uStack_18;
      }
      abStack_2d[bStack_21] = (byte)uVar4;
      uVar4 = uStack_14;
      if (uStack_18 != 0) {
        uVar4 = uStack_14 / uStack_18;
      }
      uStack_14 = uStack_14 - uVar4 * uStack_18;
      uStack_18 = uStack_18 / 10;
    }
    for (bStack_21 = 0; bStack_21 < 9; bStack_21 = bStack_21 + 1) {
      uVar4 = (uint)bStack_21;
      cVar2 = nib2hex(abStack_2d[uVar4]);
      *(char *)((int)&DAT_00001c93 + uVar4) = cVar2;
    }
    uStack_1e = CONCAT11(pvStack_10->clar_offset_be[0],pvStack_10->clar_offset_be[1]);
    if ((pvStack_10->clar_offset_be[0] & 0x80) == 0) {
      DAT_00001c9c = 0x2b;
    }
    else {
      DAT_00001c9c = 0x2d;
      uStack_1e = ~uStack_1e + 1;
    }
    uStack_20 = 1000;
    for (bStack_21 = 0; bStack_21 < 4; bStack_21 = bStack_21 + 1) {
      uVar4 = (uint)uStack_1e;
      if (uStack_20 != 0) {
        uVar4 = uVar4 / uStack_20;
      }
      abStack_2d[bStack_21] = (byte)uVar4;
      uVar5 = uStack_1e;
      if (uStack_20 != 0) {
        uVar5 = uStack_1e / uStack_20;
      }
      uStack_1e = uStack_1e - uVar5 * uStack_20;
      uStack_20 = uStack_20 / 10;
    }
    for (bStack_21 = 0; bStack_21 < 4; bStack_21 = bStack_21 + 1) {
      uVar4 = (uint)bStack_21;
      cVar2 = nib2hex(abStack_2d[uVar4]);
      (&DAT_00001c9d)[uVar4] = cVar2;
    }
    if ((pvStack_10->flags1 & 0x10) == 0) {
      DAT_00001ca1 = 0x30;
    }
    else {
      DAT_00001ca1 = 0x31;
    }
    if ((pvStack_10->flags1 & 8) == 0) {
      DAT_00001ca2 = 0x30;
    }
    else {
      DAT_00001ca2 = 0x31;
    }
    DAT_00001ca3 = BYTE_ARRAY_fff805ac[(pvStack_10->mode & 0xf) + 0x124];
    DAT_00001ca4 = BYTE_ARRAY_fff805ac[bStack_2e + 0x133];
    cVar2 = (char)((pvStack_10->flags3 & 0x38) >> 3);
    if (cVar2 == '\x01') {
      DAT_00001ca5 = 0x32;
    }
    else if (cVar2 == '\x02') {
      DAT_00001ca5 = 0x31;
    }
    else {
      DAT_00001ca5 = 0x30;
    }
    DAT_00001ca7 = 0x30;
    DAT_00001ca6 = 0x30;
    cVar2 = (char)((pvStack_10->flags2 & 0xc) >> 2);
    if (cVar2 == '\0') {
      DAT_00001ca8 = 0x32;
    }
    else if (cVar2 == '\x02') {
      DAT_00001ca8 = 0x31;
    }
    else {
      DAT_00001ca8 = 0x30;
    }
    DAT_00001ca9 = 0x3b;
    DAT_0001b788 = 0x1c;
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_MT @ fffac285 (561 bytes)

/* WARNING: Removing unreachable block (ram,0xfffac2fe) */

void cat_MT(int param_1,char param_2,ushort param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  byte *pbStack_18;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  vfo_rec *pvStack_c;
  ushort local_8;
  char local_5;
  int local_4;
  
  local_8 = param_3;
  local_5 = param_2;
  local_4 = param_1;
  toupper_inplace((char *)(param_1 + 2));
  toupper_inplace((char *)(local_4 + 3));
  toupper_inplace((char *)(local_4 + 4));
  if (*(char *)(local_4 + 2) == '0') {
    bStack_f = 0;
    bStack_e = 100;
    for (bStack_d = 2; bStack_d < 5; bStack_d = bStack_d + 1) {
      if ((*(byte *)((uint)bStack_d + local_4) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_d + local_4))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        cat_error = 1;
        return;
      }
      bStack_f = (*(byte *)((uint)bStack_d + local_4) & 0xf) * bStack_e + bStack_f;
      bStack_e = bStack_e / 10;
    }
    if ((bStack_f == 0) || (99 < bStack_f)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      cat_error = 1;
      return;
    }
    bStack_10 = bStack_f - 1;
  }
  else {
    for (bStack_e = 0; bStack_e < 0x22; bStack_e = bStack_e + 1) {
      iVar3 = strncmp((uint)bStack_e * 3 + -0x7f917,local_4 + 2,3);
      if (iVar3 == 0) {
        bStack_10 = bStack_e + 99;
        break;
      }
    }
    if (bStack_10 < 99) {
      cat_error = 1;
      return;
    }
    if (0x75 < bStack_10) {
      cat_error = 1;
      return;
    }
  }
  bVar2 = memch_valid(bStack_10,&pbStack_18);
  if (!bVar2) {
    cat_error = 1;
    return;
  }
  uVar1 = (uint)bStack_10;
  pvStack_c = memch + uVar1;
  if (local_5 != '\0') {
    if (*(char *)(local_4 + 5) == '0') {
      memch[uVar1].flags5 = memch[uVar1].flags5 & 0x7f;
    }
    else {
      if (*(char *)(local_4 + 5) != '1') {
        cat_error = 1;
        return;
      }
      memch[uVar1].flags5 = memch[uVar1].flags5 | 0x80;
    }
    bStack_11 = (char)local_8 - 7;
    bStack_e = 0;
    while( true ) {
      if (bStack_11 <= bStack_e) {
        for (; bStack_e < 0xc; bStack_e = bStack_e + 1) {
          pvStack_c->tag[bStack_e] = ' ';
        }
        eeprom_save_memch(bStack_10);
        return;
      }
      if ((*(byte *)((uint)bStack_e + local_4 + 6) < 0x20) ||
         (0x7d < *(byte *)((uint)bStack_e + local_4 + 6))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) break;
      pvStack_c->tag[bStack_e] = *(char *)((uint)bStack_e + local_4 + 6);
      bStack_e = bStack_e + 1;
    }
    cat_error = 1;
    return;
  }
  if ((memch[uVar1].flags5 & 0x80) == 0) {
    DAT_00001c93._0_1_ = 0x30;
  }
  else {
    DAT_00001c93._0_1_ = 0x31;
  }
  for (bStack_e = 0; bStack_e < 0xc; bStack_e = bStack_e + 1) {
    *(char *)((int)&DAT_00001c93 + bStack_e + 1) = pvStack_c->tag[bStack_e];
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
    DAT_00001c90 = nib2hex(g_opstate.meter_sel);
    DAT_00001c91 = 0x30;
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    bVar1 = hex2nib(*(byte *)(param_1 + 2));
    if (5 < bVar1) {
      cat_error = 1;
      return;
    }
    g_opstate.meter_sel = bVar1;
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_MW @ fffac534 (1145 bytes)

/* WARNING: Removing unreachable block (ram,0xfffac79c) */
/* WARNING: Removing unreachable block (ram,0xfffac700) */
/* WARNING: Removing unreachable block (ram,0xfffac5e5) */
/* WARNING: Removing unreachable block (ram,0xfffac8bb) */
/* WARNING: Removing unreachable block (ram,0xfffac91b) */

void cat_MW(int param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte local_21 [6];
  byte bStack_1b;
  byte bStack_1a;
  byte bStack_19;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  void *pvStack_10;
  vfo_rec *pvStack_c;
  byte local_5;
  int local_4;
  
  local_21[0] = 0;
  local_21[1] = 0;
  local_21[2] = 0;
  local_21[3] = 0;
  local_5 = param_2;
  local_4 = param_1;
  toupper_inplace((char *)(param_1 + 2));
  toupper_inplace((char *)(local_4 + 3));
  toupper_inplace((char *)(local_4 + 4));
  local_21[5] = g_opstate.active_vfo;
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
        cat_error = 1;
        return;
      }
      bStack_1b = (*(byte *)((uint)bStack_19 + local_4) & 0xf) * bStack_1a + bStack_1b;
      bStack_1a = bStack_1a / 10;
    }
    if ((bStack_1b == 0) || (99 < bStack_1b)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      cat_error = 1;
      return;
    }
    local_21[4] = bStack_1b - 1;
  }
  else {
    local_21[4] = 0;
    for (bStack_1a = 0; bStack_1a < 0x22; bStack_1a = bStack_1a + 1) {
      iVar4 = strncmp((uint)bStack_1a * 3 + -0x7f917,local_4 + 2,3);
      if (iVar4 == 0) {
        local_21[4] = bStack_1a + 99;
        break;
      }
    }
    if (local_21[4] < 99) {
      cat_error = 1;
      return;
    }
    if (0x75 < local_21[4]) {
      cat_error = 1;
      return;
    }
  }
  if (local_21[5] == 0) {
    g_mem_hdr.chan_a = local_21[4];
  }
  else {
    g_mem_hdr.chan_b = local_21[4];
  }
  pvStack_c = memch + local_21[4];
  pvStack_10 = (void *)0x0;
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
      cat_error = 1;
      return;
    }
    pvStack_10 = (void *)((*(byte *)((uint)bStack_19 + local_4) & 0xf) * uStack_14 + (int)pvStack_10
                         );
    uStack_14 = uStack_14 / 10;
  }
  bVar2 = freq_in_range(pvStack_10);
  if (bVar2 == 0) {
    cat_error = 1;
    return;
  }
  for (bStack_19 = 0; bStack_19 < 4; bStack_19 = bStack_19 + 1) {
    local_21[bStack_19] = (byte)((uint)pvStack_10 >> ((3 - bStack_19 & 3) << 3));
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
      cat_error = 1;
      return;
    }
    uStack_18 = uStack_18 / 10;
  }
  if ((*(char *)(local_4 + 0xe) != '-') && (*(char *)(local_4 + 0xe) != '+')) {
    cat_error = 1;
    return;
  }
  uStack_16 = 0;
  if ((*(char *)(local_4 + 0x13) != '0') && (*(char *)(local_4 + 0x13) != '1')) {
    cat_error = 1;
    return;
  }
  if ((*(char *)(local_4 + 0x14) != '0') && (*(char *)(local_4 + 0x14) != '1')) {
    cat_error = 1;
    return;
  }
  bStack_1b = 0xff;
  bStack_19 = 0;
  do {
    if (0xe < bStack_19) {
LAB_fffac85b:
      bVar2 = bStack_1b;
      if (bStack_1b == 0xff) {
        cat_error = 1;
        return;
      }
      if (*(char *)(local_4 + 0x16) != '1') {
        cat_error = 1;
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
          cat_error = 1;
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
            cat_error = 1;
            return;
          }
          bStack_1b = '\x01';
        }
        pvStack_c->freq_be[0] = local_21[0];
        pvStack_c->freq_be[1] = local_21[1];
        pvStack_c->freq_be[2] = local_21[2];
        pvStack_c->freq_be[3] = local_21[3];
        pvStack_c->clar_offset_be[0] = 0;
        pvStack_c->clar_offset_be[1] = 0;
        pvStack_c->flags1 = pvStack_c->flags1 & 0xe7;
        pvStack_c->flags1 = pvStack_c->flags1;
        pvStack_c->mode = pvStack_c->mode & 0xf0;
        pvStack_c->mode = pvStack_c->mode | bVar2;
        pvStack_c->flags3 = pvStack_c->flags3 & 199;
        pvStack_c->flags3 = pvStack_c->flags3 | bVar3;
        pvStack_c->flags2 = pvStack_c->flags2 & 0xf3;
        pvStack_c->flags2 = pvStack_c->flags2 | bStack_1b << 2;
        FUN_fffb01df(local_21[4]);
        eeprom_save_memch(local_21[4]);
        vfo_mark_edited(local_21[5]);
        vfo_store_back(local_21[5]);
        return;
      }
      cat_error = 1;
      return;
    }
    if (*(byte *)(local_4 + 0x15) == BYTE_ARRAY_fff805ac[bStack_19 + 0x124]) {
      bStack_1b = bStack_19;
      goto LAB_fffac85b;
    }
    bStack_19 = bStack_19 + 1;
  } while( true );
}


// ===== cat_MX @ fffac9ad (154 bytes)

void cat_MX(int param_1,char param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  bVar1 = g_ui.ptt_mox;
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(g_ui.ptt_mox);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar2 = key_event_filter(0x302,2);
  if (bVar2 == 0) {
    cat_error = 1;
    return;
  }
  cVar3 = hex2nib(*(byte *)(param_1 + 2));
  if (cVar3 == '\0') {
    if (bVar1 != 0) {
      key_mox_vox_press();
      key_mox_vox_short();
      return;
    }
  }
  else {
    if (cVar3 != '\x01') {
      cat_error = 1;
      return;
    }
    if (bVar1 == 0) {
      key_mox_vox_long();
      return;
    }
  }
  return;
}


// ===== cat_NA @ fffaca47 (542 bytes)

void cat_NA(int param_1,char param_2)

{
  bool bVar1;
  vfo_rec *pvVar2;
  byte bVar3;
  radio_mode rVar4;
  byte bVar5;
  byte bStack_15;
  byte *pbStack_14;
  
  vfo_rec_ptr(VFO_RX);
  bVar3 = g_opstate.active_vfo;
  rVar4 = vfo_mode(g_opstate.active_vfo);
  bVar1 = false;
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 == '\0') {
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
  }
  else {
    bVar5 = key_event_filter(0x30d,0);
    if (bVar5 == 0) {
      cat_error = 1;
      return;
    }
    if (0x31 < *(byte *)(param_1 + 3)) {
      cat_error = 1;
      return;
    }
  }
  if (bVar3 == 0) {
    pvVar2 = &g_opstate.vfo_a;
  }
  else {
    pvVar2 = &g_opstate.vfo_b;
  }
  pbStack_14 = &pvVar2->nar_flags;
  switch(rVar4) {
  case MODE_LSB:
  case MODE_USB:
    bVar1 = true;
    bStack_15 = 0x80;
    break;
  case MODE_CW_L:
  case MODE_CW_U:
    bVar1 = true;
    bStack_15 = 0x20;
    break;
  case MODE_AM:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x30;
    }
    else if (*(char *)(param_1 + 3) == '1') {
      FUN_fffc4bd5(MODE_AM_N);
    }
    break;
  case MODE_AM_N:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x31;
    }
    else if (*(char *)(param_1 + 3) == '0') {
      FUN_fffc4bd5(MODE_AM);
    }
    break;
  case MODE_FM:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x30;
    }
    else if (*(char *)(param_1 + 3) == '1') {
      FUN_fffc4bd5(MODE_FM_N);
    }
    break;
  case MODE_FM_N:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x31;
    }
    else if (*(char *)(param_1 + 3) == '0') {
      FUN_fffc4bd5(MODE_FM);
    }
    break;
  case MODE_DATA_L:
  case MODE_DATA_U:
  case MODE_PSK:
    bVar1 = true;
    bStack_15 = 4;
    break;
  case MODE_DATA_FM:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x30;
    }
    else if (*(char *)(param_1 + 3) == '1') {
      FUN_fffc4bd5(MODE_DATA_FM_N);
    }
    break;
  case MODE_DATA_FM_N:
    if (param_2 == '\0') {
      DAT_00001c91 = 0x31;
    }
    else if (*(char *)(param_1 + 3) == '0') {
      FUN_fffc4bd5(MODE_DATA_FM);
    }
    break;
  case MODE_RTTY_L:
  case MODE_RTTY_U:
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
  vfo_mark_edited(bVar3);
  vfo_store_back(bVar3);
  g_ui.freq_refresh_req = 1;
  return;
}


// ===== cat_NB @ fffacc65 (131 bytes)

void cat_NB(int param_1,char param_2)

{
  byte bVar1;
  vfo_rec *pvVar2;
  
  pvVar2 = vfo_rec_ptr(VFO_RX);
  if (param_2 == '\0') {
    DAT_00001c91 = nib2hex((byte)((pvVar2->flags2 & 2) >> 1));
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  bVar1 = key_event_filter(0x303,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    pvVar2->flags2 = pvVar2->flags2 & 0xfd;
    return;
  }
  if (*(char *)(param_1 + 3) != '1') {
    cat_error = 1;
    return;
  }
  pvVar2->flags2 = pvVar2->flags2 | 2;
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

void cat_NL(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 == '\0') {
    local_b = 10;
    local_d = g_opstate.nb_level;
    DAT_00001c91 = 0x30;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      n = local_d;
      if (local_b != 0) {
        n = local_d / local_b;
      }
      local_d = local_d - n * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c92)[local_c] = cVar2;
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  local_a = 0;
  local_b = 10;
  for (local_c = 4; local_c < 6; local_c = local_c + 1) {
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
    local_a = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_a;
    local_b = local_b / 10;
  }
  if (10 < local_a) {
    cat_error = 1;
    return;
  }
  g_opstate.nb_level = local_a;
  if (g_opstate.ex030126_scu_lan10 != 0) {
    return;
  }
  g_ui.popup_code = 0x38;
  popup_duration_get(0x38);
  popup_open_timed();
  return;
}


// ===== cat_NR @ ffface21 (157 bytes)

void cat_NR(int param_1,char param_2)

{
  byte bVar1;
  vfo_rec *pvVar2;
  
  pvVar2 = vfo_rec_ptr(VFO_RX);
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 == '\0') {
    if ((pvVar2->dnr & 0x10) == 0) {
      DAT_00001c91 = 0x30;
    }
    else {
      DAT_00001c91 = 0x31;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  bVar1 = key_event_filter(0x304,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 3) != '1') {
    if (*(char *)(param_1 + 3) != '0') {
      cat_error = 1;
      return;
    }
    pvVar2->dnr = pvVar2->dnr & 0xef;
    return;
  }
  pvVar2->dnr = pvVar2->dnr | 0x10;
  return;
}


// ===== cat_OS @ fffacebe (323 bytes)

/* WARNING: Removing unreachable block (ram,0xfffacfeb) */

void cat_OS(int param_1,char param_2)

{
  radio_mode rVar1;
  char cVar2;
  char cStack_d;
  int iStack_c;
  
  rVar1 = vfo_mode(VFO_RX);
  if (*(char *)(param_1 + 2) == '0') {
    if (g_opstate.active_vfo == 0) {
      iStack_c = 0x9d09;
    }
    else {
      iStack_c = 0x9d63;
    }
  }
  else if (*(char *)(param_1 + 2) == '1') {
    if (g_opstate.active_vfo == 0) {
      iStack_c = 0x9d63;
    }
    else {
      iStack_c = 0x9d09;
    }
  }
  if (param_2 == '\0') {
    cVar2 = (char)((*(byte *)(iStack_c + 2) & 0xc) >> 2);
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
  if (g_opstate.split_on == 1) {
    cat_error = 1;
    return;
  }
  if ((1 < rVar1 - 6) && (1 < rVar1 - 10)) {
    cat_error = 1;
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
      cat_error = 1;
      return;
    }
    cStack_d = '\x01';
  }
  *(byte *)(iStack_c + 2) = *(byte *)(iStack_c + 2) & 0xf3;
  *(byte *)(iStack_c + 2) = cStack_d << 2 | *(byte *)(iStack_c + 2);
  g_ui.freq_refresh_req = 1;
  return;
}


// ===== cat_PA @ fffad001 (161 bytes)

void cat_PA(int param_1,char param_2)

{
  char cVar1;
  byte bVar2;
  vfo_rec *pvVar3;
  byte bStack_d;
  
  pvVar3 = vfo_rec_ptr(VFO_RX);
  if (param_2 == '\0') {
    bVar2 = pvVar3->flags5 & 3;
    if (bVar2 == 2) {
      bStack_d = 0x31;
    }
    else if (bVar2 == 3) {
      bStack_d = 0x32;
    }
    else {
      bStack_d = 0x30;
    }
    DAT_00001c90 = 0x30;
    DAT_00001c91 = bStack_d;
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  cVar1 = *(char *)(param_1 + 3);
  if (cVar1 == '0') {
    bStack_d = 0;
  }
  else if (cVar1 == '1') {
    bStack_d = 2;
  }
  else {
    if (cVar1 != '2') {
      cat_error = 1;
      return;
    }
    bStack_d = 3;
  }
  pvVar3->flags5 = pvVar3->flags5 & 0xfc;
  pvVar3->flags5 = pvVar3->flags5 | bStack_d;
  return;
}


// ===== cat_PB @ fffad0a2 (415 bytes)

void cat_PB(int param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 == '\0') {
    if (g_ui.dvs_state == 1) {
      DAT_00001c91 = nib2hex(g_ui.dvs_slot + 1);
    }
    else {
      DAT_00001c91 = '0';
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  bVar1 = key_event_filter(0x87,0);
  if (bVar1 == 0) {
    cat_error = 1;
    return;
  }
  iVar2 = msg_voice_mode_ok();
  if (iVar2 != 1) {
    cat_error = 1;
    return;
  }
  if (g_ui.playlist_open == 1) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    g_ui.dvs_state = 0;
    g_ui.dvs_busy = 0;
    g_ui.dvs_armed = 0;
    if (g_ui.ptt_msg_play == 1) {
      g_ui.ptt_msg_play = 0;
      return;
    }
  }
  else {
    if (0x35 < *(byte *)(param_1 + 3)) {
      cat_error = 1;
      return;
    }
    if (g_ui.dvs_state == 0) {
      g_ui.dvs_state = 1;
      g_ui.msg_slot = hex2nib(*(byte *)(param_1 + 3));
      g_ui.dvs_slot = g_ui.msg_slot - 1;
      iVar2 = tx_breakin_on();
      if (iVar2 == 1) {
        g_ui.ptt_msg_play = 1;
      }
      g_ui.msg_playing = 1;
      g_ui.msg_state_1d0 = 0;
      return;
    }
    g_ui.dvs_state = 0;
    g_ui.dvs_busy = 0;
    g_ui.dvs_armed = 0;
    if (g_ui.ptt_msg_play == 1) {
      g_ui.ptt_msg_play = 0;
      return;
    }
  }
  g_ui.dvs_busy = 0;
  g_ui.dvs_armed = 0;
  g_ui.dvs_state = 0;
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

void cat_PC(int param_1,char param_2)

{
  bool bVar1;
  radio_mode rVar2;
  char cVar3;
  uint uVar4;
  byte n;
  byte *pbStack_24;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte bStack_1c;
  
  uVar4 = vfo_freq(VFO_RX,VFO_SIDE_SEL);
  rVar2 = vfo_mode(VFO_RX);
  cVar3 = tx_band_of_freq(uVar4);
  if ((rVar2 == MODE_AM) || (rVar2 == MODE_AM_N)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    pbStack_24 = g_opstate.rf_power + 3;
    bStack_1e = g_opstate.rf_power[3];
    bStack_1f = g_opstate.ex030404_am_max_power;
  }
  else if (cVar3 == '\t') {
    pbStack_24 = g_opstate.rf_power + 1;
    bStack_1e = g_opstate.rf_power[1];
    bStack_1f = g_opstate.ex030402_50m_max_power;
  }
  else if (cVar3 == '\n') {
    pbStack_24 = g_opstate.rf_power + 2;
    bStack_1e = g_opstate.rf_power[2];
    bStack_1f = g_opstate.ex030403_70m_max_power;
  }
  else {
    pbStack_24 = g_opstate.rf_power;
    bStack_1e = g_opstate.rf_power[0];
    bStack_1f = g_opstate.ex030401_hf_max_power;
  }
  if (param_2 != '\0') {
    bStack_1e = 0;
    bStack_1d = 100;
    for (bStack_1c = 2; bStack_1c < 5; bStack_1c = bStack_1c + 1) {
      if ((*(byte *)((uint)bStack_1c + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_1c + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        cat_error = 1;
        return;
      }
      bStack_1e = (*(byte *)((uint)bStack_1c + param_1) & 0xf) * bStack_1d + bStack_1e;
      bStack_1d = bStack_1d / 10;
    }
    if ((rVar2 == MODE_AM) || (rVar2 == MODE_AM_N)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((bStack_1e < 5) || (0x19 < bStack_1e)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        cat_error = 1;
        return;
      }
      if (bStack_1f < bStack_1e) {
        bStack_1e = bStack_1f;
      }
      *pbStack_24 = bStack_1e;
    }
    else {
      if ((bStack_1e < 5) || (100 < bStack_1e)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        cat_error = 1;
        return;
      }
      if (bStack_1f < bStack_1e) {
        bStack_1e = bStack_1f;
      }
      *pbStack_24 = bStack_1e;
    }
    if (g_opstate.ex030126_scu_lan10 != 0) {
      return;
    }
    g_ui.popup_code = 0x2c;
    popup_duration_get(0x2c);
    popup_open_timed();
    return;
  }
  bStack_1d = 100;
  for (bStack_1c = 0; bStack_1c < 3; bStack_1c = bStack_1c + 1) {
    n = bStack_1e;
    if (bStack_1d != 0) {
      n = bStack_1e / bStack_1d;
    }
    bStack_1e = bStack_1e - n * bStack_1d;
    bStack_1d = bStack_1d / 10;
    cVar3 = nib2hex(n);
    (&DAT_00001c90)[bStack_1c] = cVar3;
  }
  DAT_00001c93._0_1_ = 0x3b;
  DAT_0001b788 = 6;
  return;
}


// ===== cat_PL @ fffad467 (302 bytes)

/* WARNING: Removing unreachable block (ram,0xfffad4d7) */
/* WARNING: Removing unreachable block (ram,0xfffad528) */
/* WARNING: Removing unreachable block (ram,0xfffad58f) */
/* WARNING: Removing unreachable block (ram,0xfffad583) */
/* WARNING: Removing unreachable block (ram,0xfffad512) */
/* WARNING: Removing unreachable block (ram,0xfffad4a2) */
/* WARNING: Removing unreachable block (ram,0xfffad592) */

void cat_PL(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = g_opstate.proc_level;
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
  if ((local_d == 0) || (100 < local_d)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    g_opstate.proc_level = local_d;
    if (g_opstate.ex030126_scu_lan10 != 0) {
      return;
    }
    g_ui.popup_code = 0x27;
    popup_duration_get(0x27);
    popup_open_timed();
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_PR @ fffad595 (257 bytes)

void cat_PR(int param_1,char param_2)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_1 + 2) == '0';
  if (param_2 == '\0') {
    if (bVar1) {
      if (g_opstate.proc_level == 0) {
        DAT_00001c91 = 0x30;
      }
      else {
        DAT_00001c91 = 0x31;
      }
    }
    else if (*(char *)(param_1 + 2) == '1') {
      if (g_opstate.proc_on == 0) {
        DAT_00001c91 = 0x30;
      }
      else {
        DAT_00001c91 = 0x31;
      }
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (bVar1) {
    if (*(char *)(param_1 + 3) == '0') {
      g_opstate.proc_level = 0;
      return;
    }
    if (*(char *)(param_1 + 3) == '1') {
      g_opstate.proc_level = 0x32;
      return;
    }
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    return;
  }
  if (*(char *)(param_1 + 3) == '0') {
    g_opstate.proc_on = 0;
    return;
  }
  if (*(char *)(param_1 + 3) == '1') {
    g_opstate.proc_on = 1;
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_PS @ fffad696 (110 bytes)

void cat_PS(int param_1,char param_2)

{
  if (param_2 == '\0') {
    DAT_00001c90 = 0x31;
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (*(char *)(param_1 + 2) != '0') {
    if (*(char *)(param_1 + 2) != '1') {
      cat_error = 1;
      return;
    }
    g_opstate.auto_power_on = 1;
    power_on_request();
    return;
  }
  g_ui.restart_req = 1;
  g_ui.power_cmd = 0x10;
  return;
}


// ===== cat_QI @ fffad704 (5 bytes)

void cat_QI(void)

{
  qmb_store();
  return;
}


// ===== cat_QR @ fffad709 (5 bytes)

void cat_QR(void)

{
  qmb_recall();
  return;
}


// ===== cat_QS @ fffad70e (10 bytes)

void cat_QS(void)

{
  cat_error = 1;
  return;
}


// ===== cat_RA @ fffad718 (150 bytes)

void cat_RA(int param_1,char param_2)

{
  byte bVar1;
  vfo_rec *pvVar2;
  
  pvVar2 = vfo_rec_ptr(VFO_RX);
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 != '\0') {
    bVar1 = hex2nib(*(byte *)(param_1 + 3));
    if (bVar1 < 4) {
      pvVar2->flags3 = pvVar2->flags3 & 0xfc;
      pvVar2->flags3 = pvVar2->flags3 | bVar1;
    }
    else {
      cat_error = 1;
    }
    g_ui.freq_refresh_req = 1;
    return;
  }
  DAT_00001c90 = 0x30;
  DAT_00001c91 = nib2hex(pvVar2->flags3 & 3);
  DAT_00001c92 = 0x3b;
  DAT_0001b788 = 5;
  return;
}


// ===== cat_RG @ fffad7ae (309 bytes)

/* WARNING: Removing unreachable block (ram,0xfffad885) */
/* WARNING: Removing unreachable block (ram,0xfffad7c9) */
/* WARNING: Removing unreachable block (ram,0xfffad8d5) */
/* WARNING: Removing unreachable block (ram,0xfffad89b) */
/* WARNING: Removing unreachable block (ram,0xfffad84a) */
/* WARNING: Removing unreachable block (ram,0xfffad8e0) */
/* WARNING: Removing unreachable block (ram,0xfffad815) */

void cat_RG(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 != '\0') {
    local_d = 0;
    local_b = 100;
    local_c = 3;
    while( true ) {
      if (5 < local_c) {
        if (g_opstate.ex030102_rf_sql_vr != 0) {
          rf_gain_alt = local_d;
          return;
        }
        g_ui.rf_gain = local_d;
        rf_gain_alt = local_d;
        return;
      }
      if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1))
         ) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
      local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
      local_b = local_b / 10;
      local_c = local_c + 1;
    }
    cat_error = 1;
    return;
  }
  if (g_opstate.ex030102_rf_sql_vr == 0) {
    local_d = g_ui.rf_gain;
  }
  else {
    local_d = rf_gain_alt;
  }
  local_b = 100;
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    n = local_d;
    if (local_b != 0) {
      n = local_d / local_b;
    }
    local_d = local_d - n * local_b;
    local_b = local_b / 10;
    cVar2 = nib2hex(n);
    (&DAT_00001c91)[local_c] = cVar2;
  }
  DAT_00001c93._1_1_ = 0x3b;
  DAT_0001b788 = 7;
  return;
}


// ===== cat_RI @ fffad8e3 (355 bytes)

void cat_RI(int param_1)

{
  byte n;
  bool bVar1;
  
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00001c90 = 0x30;
    if (g_ui.hi_swr == 0) {
      DAT_00001c91 = 0x30;
    }
    else {
      DAT_00001c91 = 0x31;
    }
    n = FUN_fffe0755();
    DAT_00001c92 = nib2hex(n);
    if (g_ui.tx_lamp == 0) {
      DAT_00001c93._0_1_ = 0x30;
    }
    else if (g_ui.tx_lamp == 1) {
      DAT_00001c93._0_1_ = 0x31;
    }
    else {
      DAT_00001c93._0_1_ = 0x32;
    }
    DAT_00001c93._1_1_ = 0x30;
    if ((g_ui.tune_cycle_3c == 2) || (g_ui.tune_cycle_3d == 2)) {
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
      DAT_00001c93._2_1_ = 0x31;
    }
    else {
      DAT_00001c93._2_1_ = 0x30;
    }
    if (g_ui.scan_running == 0) {
      DAT_00001c93._3_1_ = 0x30;
    }
    else {
      if ((g_ui.scan_hold != 1) || (bVar1 = af_mute_get(), bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        DAT_00001c93._3_1_ = 0x32;
      }
      else {
        DAT_00001c93._3_1_ = 0x31;
      }
    }
    if ((g_ui.lamp_map & 0x10) == 0) {
      DAT_00001c97 = 0x30;
    }
    else {
      DAT_00001c97 = 0x31;
    }
    DAT_00001c98 = 0x3b;
    DAT_0001b788 = 0xb;
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_RL @ fffada46 (311 bytes)

/* WARNING: Removing unreachable block (ram,0xfffada79) */
/* WARNING: Removing unreachable block (ram,0xfffadb03) */
/* WARNING: Removing unreachable block (ram,0xfffada8d) */

void cat_RL(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  vfo_rec *pvVar3;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  
  pvVar3 = vfo_rec_ptr(VFO_RX);
  if (*(char *)(param_1 + 2) != '0') {
    cat_error = 1;
    return;
  }
  if (param_2 == '\0') {
    bVar2 = pvVar3->dnr & 0xf;
    DAT_00001c91 = nib2hex(bVar2 / 10);
    DAT_00001c92 = nib2hex(bVar2 % 10);
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  bStack_d = 0;
  bStack_e = 10;
  for (bStack_f = 3; bStack_f < 5; bStack_f = bStack_f + 1) {
    if ((*(byte *)((uint)bStack_f + param_1) < 0x30) || (0x39 < *(byte *)((uint)bStack_f + param_1))
       ) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      cat_error = 1;
      return;
    }
    bStack_d = (*(byte *)((uint)bStack_f + param_1) & 0xf) * bStack_e + bStack_d;
    bStack_e = bStack_e / 10;
  }
  if ((bStack_d == 0) || (0xf < bStack_d)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    pvVar3->dnr = pvVar3->dnr & 0xf0;
    pvVar3->dnr = pvVar3->dnr | bStack_d;
    if (g_opstate.ex030126_scu_lan10 == 0) {
      g_ui.popup_code = 0x39;
      popup_duration_get(0x39);
      popup_open_timed();
    }
    g_ui.freq_refresh_req = 1;
    return;
  }
  cat_error = 1;
  return;
}


// ===== cat_RM @ fffadb7d (345 bytes)

/* WARNING: Removing unreachable block (ram,0xfffadc40) */
/* WARNING: Removing unreachable block (ram,0xfffadc92) */
/* WARNING: Removing unreachable block (ram,0xfffadcd3) */

void cat_RM(int param_1)

{
  bool bVar1;
  char cVar2;
  byte n;
  char cStack_d;
  byte bStack_c;
  byte bStack_b;
  byte bStack_9;
  
  cStack_d = hex2nib(*(byte *)(param_1 + 2));
  if (cStack_d == '\0') {
    if (g_ui.tx_lamp == 1) {
      if (g_opstate.meter_sel == 1) {
        cStack_d = '\x03';
      }
      else if (g_opstate.meter_sel == 2) {
        cStack_d = '\x04';
      }
      else if (g_opstate.meter_sel == 3) {
        cStack_d = '\b';
      }
      else if (g_opstate.meter_sel == 4) {
        cStack_d = '\a';
      }
      else if (g_opstate.meter_sel == 5) {
        cStack_d = '\x06';
      }
      else {
        cStack_d = '\x05';
      }
    }
    else {
      cStack_d = '\x01';
    }
  }
  if (cStack_d == '\b') {
    bStack_9 = meter_get_vdd();
  }
  else if (cStack_d == '\x03') {
    bStack_9 = meter_get_comp();
  }
  else if (cStack_d == '\x04') {
    bStack_9 = meter_get_alc();
  }
  else if (cStack_d == '\x05') {
    bStack_9 = meter_get_po();
  }
  else if (cStack_d == '\x06') {
    bStack_9 = meter_get_swr();
  }
  else if (cStack_d == '\a') {
    bStack_9 = meter_get_idd();
  }
  else {
    if (cStack_d != '\x01') {
      cat_error = 1;
      return;
    }
    bStack_9 = meter_get_s();
  }
  if (g_ui.tx_lamp == 0) {
    if ((cStack_d == '\b') || (cStack_d == '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      bStack_9 = 0;
    }
  }
  else if (cStack_d == '\x01') {
    bStack_9 = 0;
  }
  bStack_b = 100;
  for (bStack_c = 0; bStack_c < 3; bStack_c = bStack_c + 1) {
    n = bStack_9;
    if (bStack_b != 0) {
      n = bStack_9 / bStack_b;
    }
    bStack_9 = bStack_9 - n * bStack_b;
    bStack_b = bStack_b / 10;
    cVar2 = nib2hex(n);
    (&DAT_00001c91)[bStack_c] = cVar2;
    *(undefined1 *)((int)&DAT_00001c93 + bStack_c + 1) = 0x30;
  }
  DAT_00001c97 = 0x3b;
  DAT_0001b788 = 10;
  return;
}


// ===== cat_SC @ fffadcd6 (196 bytes)

void cat_SC(int param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    if (g_ui.scan_running == 1) {
      iVar2 = FUN_fffe5d0e();
      if (iVar2 == 0) {
        DAT_00001c90 = 0x31;
      }
      else {
        DAT_00001c90 = 0x32;
      }
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (g_ui.tx_lamp != 0) {
    cat_error = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (g_ui.scan_running == 1) {
      scan_stop();
      return;
    }
  }
  else if (*(char *)(param_1 + 2) == '1') {
    bVar1 = scan_allowed();
    if (bVar1 == 1) {
      scan_start_up();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '2') {
      cat_error = 1;
      return;
    }
    bVar1 = scan_allowed();
    if (bVar1 == 1) {
      scan_start_down();
      return;
    }
  }
  return;
}


// ===== cat_SD @ fffadd9a (284 bytes)

/* WARNING: Removing unreachable block (ram,0xfffade46) */
/* WARNING: Removing unreachable block (ram,0xfffade0a) */
/* WARNING: Removing unreachable block (ram,0xfffadeb3) */
/* WARNING: Removing unreachable block (ram,0xfffadeb0) */
/* WARNING: Removing unreachable block (ram,0xfffade5c) */
/* WARNING: Removing unreachable block (ram,0xfffadea4) */
/* WARNING: Removing unreachable block (ram,0xfffaddd5) */

void cat_SD(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  
  if (param_2 == '\0') {
    local_b = 10;
    local_d = g_opstate.cw_bkin_delay;
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
  local_a = 0;
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
    local_a = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_a;
    local_b = local_b / 10;
  }
  if (0x21 < local_a) {
    cat_error = 1;
    return;
  }
  g_opstate.cw_bkin_delay = local_a;
  if (g_opstate.ex030126_scu_lan10 == 0) {
    g_ui.popup_code = 0x32;
    popup_duration_get(0x32);
    popup_open_timed();
    return;
  }
  return;
}


// ===== cat_SF @ fffadeb6 (1044 bytes)

void cat_SF(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  
  bVar1 = *(char *)(param_1 + 2) != '0';
  if (param_2 == '\0') {
    if (bVar1) {
      if (*(char *)(param_1 + 2) == '1') {
        if (g_ui.func_knob_item == 0x21) {
          DAT_00001c91 = 0x35;
        }
        else if (g_ui.func_knob_item == 0x1e) {
          DAT_00001c91 = 0x32;
        }
        else if (g_ui.func_knob_item == 0x1f) {
          DAT_00001c91 = 0x33;
        }
        else if (g_ui.func_knob_item == 0x20) {
          DAT_00001c91 = 0x34;
        }
        else if (g_ui.func_knob_item == 0x1d) {
          DAT_00001c91 = 0x31;
        }
        else {
          DAT_00001c91 = 0x30;
        }
      }
    }
    else {
      switch(g_opstate.func_knob) {
      case 0:
        DAT_00001c91 = 0x31;
        break;
      case 1:
        DAT_00001c91 = 0x32;
        break;
      default:
        DAT_00001c91 = 0x30;
        break;
      case 3:
        DAT_00001c91 = 0x33;
        break;
      case 4:
        DAT_00001c91 = 0x34;
        break;
      case 5:
        DAT_00001c91 = 0x35;
        break;
      case 6:
        DAT_00001c91 = 0x36;
        break;
      case 7:
        DAT_00001c91 = 0x37;
        break;
      case 9:
        DAT_00001c91 = 0x38;
        break;
      case 10:
        DAT_00001c91 = 0x39;
        break;
      case 0xb:
        DAT_00001c91 = 0x41;
        break;
      case 0xc:
        DAT_00001c91 = 0x42;
        break;
      case 0xd:
        DAT_00001c91 = 0x43;
        break;
      case 0xe:
        DAT_00001c91 = 0x44;
        break;
      case 0xf:
        DAT_00001c91 = 0x45;
        break;
      case 0x12:
        DAT_00001c91 = 0x46;
        break;
      case 0x13:
        DAT_00001c91 = 0x47;
        break;
      case 0x14:
        DAT_00001c91 = 0x48;
      }
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (bVar1) {
    if (*(char *)(param_1 + 2) != '1') {
      return;
    }
    cVar2 = *(char *)(param_1 + 3);
    if (cVar2 == '5') {
      g_ui.func_knob_item = 0x21;
      g_ui.dsp_knob_func = 3;
    }
    else if (cVar2 == '2') {
      g_ui.func_knob_item = 0x1e;
      g_ui.dsp_knob_func = 1;
    }
    else if (cVar2 == '3') {
      g_ui.func_knob_item = 0x1f;
      g_ui.dsp_knob_func = 2;
    }
    else if (cVar2 == '4') {
      g_ui.func_knob_item = 0x20;
      g_ui.dsp_knob_func = 3;
    }
    else {
      if (cVar2 != '1') {
        cat_error = 1;
        return;
      }
      g_ui.func_knob_item = 0x1d;
      g_ui.dsp_knob_func = 0;
    }
    func_display_open();
    return;
  }
  switch(*(undefined1 *)(param_1 + 3)) {
  case 0x31:
    g_opstate.func_knob = 0;
    g_opstate.func_knob_sf = 0;
    return;
  case 0x32:
    g_opstate.func_knob = 1;
    g_opstate.func_knob_sf = 1;
    return;
  case 0x33:
    g_opstate.func_knob = 3;
    g_opstate.func_knob_sf = 3;
    return;
  case 0x34:
    g_opstate.func_knob = 4;
    g_opstate.func_knob_sf = 4;
    return;
  case 0x35:
    g_opstate.func_knob = 5;
    g_opstate.func_knob_sf = 5;
    return;
  case 0x36:
    g_opstate.func_knob = 6;
    g_opstate.func_knob_sf = 6;
    return;
  case 0x37:
    g_opstate.func_knob = 7;
    g_opstate.func_knob_sf = 7;
    return;
  case 0x38:
    g_opstate.func_knob = 9;
    g_opstate.func_knob_sf = 9;
    return;
  case 0x39:
    g_opstate.func_knob = 10;
    g_opstate.func_knob_sf = 10;
    return;
  default:
    cat_error = 1;
    return;
  case 0x41:
    g_opstate.func_knob = 0xb;
    g_opstate.func_knob_sf = 0xb;
    return;
  case 0x42:
    g_opstate.func_knob = 0xc;
    g_opstate.func_knob_sf = 0xc;
    return;
  case 0x43:
    g_opstate.func_knob = 0xd;
    g_opstate.func_knob_sf = 0xd;
    return;
  case 0x44:
    g_opstate.func_knob = 0xe;
    g_opstate.func_knob_sf = 0xe;
    return;
  case 0x45:
    g_opstate.func_knob = 0xf;
    g_opstate.func_knob_sf = 0xf;
    return;
  case 0x46:
    g_opstate.func_knob = 0x12;
    g_opstate.func_knob_sf = 0x12;
    return;
  case 0x47:
    g_opstate.func_knob = 0x13;
    g_opstate.func_knob_sf = 0x13;
    return;
  case 0x48:
    g_opstate.func_knob = 0x14;
    g_opstate.func_knob_sf = 0x14;
    return;
  }
}

