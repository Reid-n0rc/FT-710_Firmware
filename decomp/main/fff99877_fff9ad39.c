// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== mic_gain_ptr @ fff99877 (107 bytes)

/* Returns the address of the MIC GAIN byte for the TX mode: 0x9BEC (LSB/USB), 0x9BED (DATA-L/U,
   PSK), 0x9BEE (AM), 0x9BEF (FM, DATA-FM), 0 for CW and RTTY [fact: fff99877]; callers
   popup_fmt_mic_gain, funcknob_mic_gain_step */

uint mic_gain_ptr(void)

{
  byte bVar1;
  uint local_8;
  uint uVar2;
  
  bVar1 = vfo_mode(1);
  uVar2 = (uint)bVar1;
  if (uVar2 == 0xe) {
LAB_fff998d0:
    local_8 = 0x9bed;
  }
  else {
    if (uVar2 - 4 < 2) {
      return 0x9bee;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 - 8 < 2) goto LAB_fff998d0;
      if (1 < uVar2 - 10) {
        if (1 < uVar2) {
          return 0;
        }
        return 0x9bec;
      }
    }
    local_8 = 0x9bef;
  }
  return local_8;
}


// ===== popup_fmt_cw_speed @ fff998e2 (72 bytes)

/* Value text of the CW SPEED pop-up (id 0x30) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_cw_speed(ushort param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  (&DAT_00001748)[param_1] = 0x6d;
  *(undefined2 *)(&DAT_00001746 + param_1) = 0x7077;
  bVar1 = dec_to_str_n(g_opstate.key_speed,2,&DAT_00001a02);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001746 + (param_1 - uVar4);
  puVar3 = &DAT_00001a02;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== popup_fmt_cw_pitch @ fff9992a (95 bytes)

/* Value text of the CW PITCH pop-up (id 0x31) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_cw_pitch(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = dec_to_str_n((ushort)g_opstate.cw_pitch * 10 + 300,4,&DAT_00001a0a);
  (&DAT_00001747)[param_1] = 0x48;
  (&DAT_00001748)[param_1] = 0x7a;
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001747 + (param_1 - uVar4);
  puVar3 = &DAT_00001a0a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== popup_fmt_bk_delay @ fff99989 (90 bytes)

/* Value text of the BK DELAY pop-up (id 0x32) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_bk_delay(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_3;
  
  *(undefined2 *)(&DAT_00001747 + param_1) = 0x736d;
  local_3 = g_opstate.cw_bkin_delay;
  if (0x21 < g_opstate.cw_bkin_delay) {
    local_3 = 0;
  }
  bVar1 = dec_to_str_n(*(undefined2 *)(BYTE_ARRAY_fff87ed4 + (uint)local_3 * 2 + 2),4,&DAT_00001a12)
  ;
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001747 + (param_1 - uVar4);
  puVar3 = &DAT_00001a12;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== popup_fmt_aess_level @ fff999e3 (70 bytes)

/* Value text of the AESS pop-up (id 0x33) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_aess_level(ushort param_1)

{
  byte bVar1;
  byte *pbVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  pbVar2 = (byte *)aess_level_ptr();
  bVar1 = dec_to_str_n((uint)*pbVar2 * 5,3,&DAT_00001a1a);
  (&DAT_00001748)[param_1] = 0x25;
  uVar5 = (uint)bVar1;
  puVar3 = &DAT_00001748 + (param_1 - uVar5);
  puVar4 = &DAT_00001a1a;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== popup_fmt_aess_cf @ fff99a29 (97 bytes)

/* Value text of the AESS CF pop-up (id 0x58) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_aess_cf(ushort param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined2 uStack_4;
  
  pcVar2 = (char *)aess_mode_ptr();
  if (*pcVar2 == '\0') {
    uStack_4 = 700;
  }
  else {
    uStack_4 = 1000;
  }
  bVar1 = dec_to_str_n(uStack_4,4,&DAT_00001a22);
  (&DAT_00001747)[param_1] = 0x48;
  (&DAT_00001748)[param_1] = 0x7a;
  uVar5 = (uint)bVar1;
  puVar3 = &DAT_00001747 + (param_1 - uVar5);
  puVar4 = &DAT_00001a22;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== popup_fmt_amc_level @ fff99a8a (53 bytes)

/* Value text of the AMC LEVEL pop-up (id 0x28) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_amc_level(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = dec_to_str_n(g_opstate.amc_level,3,&DAT_00001a2a);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a2a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== popup_fmt_mgroup @ fff99abf (177 bytes)

/* Value text of the M GROUP pop-up (id 0x24) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_mgroup(ushort param_1)

{
  byte bVar1;
  
  bVar1 = FUN_fff9bfb8();
  (&DAT_00001741)[param_1] = 0x20;
  (&DAT_00001742)[param_1] = 0x20;
  (&DAT_00001743)[param_1] = 0x20;
  (&DAT_00001744)[param_1] = 0x20;
  (&DAT_00001745)[param_1] = 0x20;
  (&DAT_00001746)[param_1] = 0x20;
  if (5 < bVar1) {
    (&DAT_00001749)[param_1] = *(undefined1 *)((int)&DAT_fff80355 + (uint)bVar1 * 3 + 2);
    *(undefined2 *)(&DAT_00001747 + param_1) = *(undefined2 *)((int)&DAT_fff80355 + (uint)bVar1 * 3)
    ;
    return;
  }
  (&DAT_00001747)[param_1] = 0x20;
  (&DAT_00001748)[param_1] = 0x20;
  (&DAT_00001749)[param_1] = bVar1 | 0x30;
  return;
}


// ===== popup_fmt_nb_level @ fff99b70 (53 bytes)

/* Value text of the NB LEVEL pop-up (id 0x38) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_nb_level(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = dec_to_str_n(g_opstate.nb_level,2,&DAT_00001a32);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a32;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== popup_fmt_dnr_level @ fff99ba5 (89 bytes)

/* Value text of the DNR LEVEL pop-up (id 0x39) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_dnr_level(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_4;
  
  local_4 = g_opstate.vfo_a.dnr;
  if (g_opstate.active_vfo != VFO_A) {
    local_4 = g_opstate.vfo_b.dnr;
  }
  local_4 = local_4 & 0xf;
  bVar1 = dec_to_str_n(local_4,2,&DAT_00001a3a);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a3a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== popup_fmt_qmb @ fff99bfe (90 bytes)

/* Value text of the QMB pop-up (id 0x43) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_qmb(ushort param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  byte local_3;
  
  if (g_opstate.active_vfo == VFO_A) {
    local_3 = g_qmb_hdr.ptr_a[0];
  }
  else {
    local_3 = g_qmb_hdr.ptr_b[0];
  }
  uVar1 = FUN_fff96d94(local_3);
  bVar2 = dec_to_str_n(uVar1,2,&DAT_00001a42);
  uVar5 = (uint)bVar2;
  puVar3 = &DAT_00001749 + (param_1 - uVar5);
  puVar4 = &DAT_00001a42;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== popup_fmt_mem_mode @ fff99c58 (74 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99c86) */
/* Value text of the MODE pop-up (id 0x55) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_mem_mode(ushort param_1)

{
  byte local_3;
  
  local_3 = memch[PTR_g_ui_00025d38->memlist_ch].mode & 0xf;
  if (0xd < local_3) {
    local_3 = 0xe;
  }
  *(undefined4 *)(&DAT_00001745 + param_1) =
       *(undefined4 *)(BYTE_ARRAY_fff803f4 + (uint)local_3 * 8 + 4);
  *(undefined4 *)(&DAT_00001741 + param_1) =
       *(undefined4 *)(BYTE_ARRAY_fff803f4 + (uint)local_3 * 8);
  return;
}


// ===== popup_fmt_mem_scan @ fff99ca2 (80 bytes)

/* Value text of the SCAN pop-up (id 0x44) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_mem_scan(ushort param_1)

{
  if ((memch[PTR_g_ui_00025d38->memlist_ch].flags1 & 0x80) != 0) {
    *(undefined4 *)(&DAT_00001745 + param_1) = 0x50494b53;
    *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
    return;
  }
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x4e414353;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  return;
}


// ===== popup_fmt_mem_type @ fff99cf2 (80 bytes)

/* Value text of the TYPE pop-up (id 0x45) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_mem_type(ushort param_1)

{
  if ((memch[PTR_g_ui_00025d38->memlist_ch].flags5 & 0x80) != 0) {
    *(undefined4 *)(&DAT_00001745 + param_1) = 0x454d414e;
    *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
    return;
  }
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x51455246;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  return;
}


// ===== popup_fmt_dec_level @ fff99d42 (6 bytes)

/* Value text of the DEC LVL pop-up (id 0x3A) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_dec_level(void)

{
  return;
}


// ===== popup_fmt_keyer @ fff99d48 (58 bytes)

/* Value text of the KEYER pop-up (id 0x46) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_keyer(ushort param_1)

{
  int iVar1;
  
  iVar1 = (uint)(g_opstate.keyer_on != 0) * 9;
  (&DAT_00001749)[param_1] = BYTE_ARRAY_fff800f3[iVar1 + 0x261];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar1 + 0x25d);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar1 + 0x259);
  return;
}


// ===== popup_fmt_bk_in @ fff99d82 (61 bytes)

/* Value text of the BK IN pop-up (id 0x2F) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_bk_in(ushort param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = vfo_rec_ptr(1);
  iVar2 = bk_in_bit_get(pbVar1);
  iVar2 = (uint)(iVar2 != 0) * 9;
  (&DAT_00001749)[param_1] = BYTE_ARRAY_fff800f3[iVar2 + 0x261];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar2 + 0x25d);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar2 + 0x259);
  return;
}


// ===== bk_in_bit_get @ fff99dbf (28 bytes)

/* Returns bit 1 of mode_block_byte0() (the BI / break-in bit of the TX mode block) [fact:
   fff99dbf]; callers popup_fmt_bk_in, dl37_slot_bk_in */

bool bk_in_bit_get(void)

{
  byte bVar1;
  
  bVar1 = mode_block_byte0();
  return (bVar1 & 2) != 0;
}


// ===== popup_fmt_mic_eq @ fff99ddb (58 bytes)

/* Value text of the MIC EQ pop-up (id 0x26) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_mic_eq(ushort param_1)

{
  int iVar1;
  
  iVar1 = (uint)(g_opstate.proc_on != 0) * 9;
  (&DAT_00001749)[param_1] = BYTE_ARRAY_fff800f3[iVar1 + 0x261];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar1 + 0x25d);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar1 + 0x259);
  return;
}


// ===== popup_fmt_contrast @ fff99e15 (53 bytes)

/* Value text of the CONTRAST pop-up (id 0x22) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_contrast(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = dec_to_str_n(g_opstate.tft_contrast,2,&DAT_00001a4a);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a4a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== dec_to_str_n @ fff99e4a (453 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99f5b) */
/* WARNING: Removing unreachable block (ram,0xfff99f32) */
/* WARNING: Removing unreachable block (ram,0xfff99fa4) */
/* WARNING: Removing unreachable block (ram,0xfff99ecb) */
/* WARNING: Removing unreachable block (ram,0xfff99ea4) */
/* WARNING: Removing unreachable block (ram,0xfff99e5e) */
/* (v, maxdigits 2..4, buf): decimal without leading zeros, returns the length; used by the
   DISPLAY-link frame builders [fact] */

char dec_to_str_n(ushort param_1,char param_2,char *param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  byte local_a;
  
  local_a = '\0';
  if (param_2 == '\x02') {
    bVar1 = param_1 / 10 != 0;
    if (bVar1) {
      *param_3 = (char)(param_1 / 10) + '0';
    }
    param_3[bVar1] = (char)(param_1 % 10) + '0';
    local_a = bVar1 + '\x01';
  }
  else if (param_2 == '\x03') {
    uVar4 = param_1 / 100;
    if (uVar4 != 0) {
      *param_3 = (char)uVar4 + '0';
    }
    iVar6 = (int)((uint)param_1 + (uint)uVar4 * -100) / 10;
    cVar2 = (char)iVar6;
    if (uVar4 != 0) {
      param_3[1] = cVar2 + '0';
      local_a = 2;
    }
    else if ((short)iVar6 == 0) {
      local_a = 0;
    }
    else {
      *param_3 = cVar2 + '0';
      local_a = 1;
    }
    param_3[local_a] = (char)(param_1 % 100) + cVar2 * -10 + '0';
    local_a = local_a + 1;
  }
  else if (param_2 == '\x04') {
    uVar4 = param_1 / 1000;
    if (uVar4 != 0) {
      *param_3 = (char)uVar4 + '0';
    }
    uVar5 = (int)((uint)param_1 + (uint)uVar4 * -1000) / 100;
    cVar2 = (char)uVar5;
    if (uVar4 != 0) {
      param_3[1] = cVar2 + '0';
      local_a = 2;
    }
    else if ((short)uVar5 == 0) {
      local_a = 0;
    }
    else {
      *param_3 = cVar2 + '0';
      local_a = 1;
    }
    iVar6 = (int)((uint)param_1 + (uint)uVar4 * -1000 + (uVar5 & 0xffff) * -100) / 10;
    cVar3 = (char)iVar6;
    if (local_a == 0) {
      if ((short)iVar6 != 0) {
        *param_3 = cVar3 + '0';
        local_a = 1;
      }
    }
    else {
      param_3[local_a] = cVar3 + '0';
      local_a = local_a + 1;
    }
    param_3[local_a] = (char)(param_1 % 1000) + cVar2 * -100 + cVar3 * -10 + '0';
    local_a = local_a + 1;
  }
  return local_a;
}


// ===== popup_fmt_dimmer @ fff9a00f (53 bytes)

/* Value text of the DIMMER pop-up (id 0x23) for displink_build_31 frame 0x31 [fact: display gui.md
   popup-slot table (#178)] */

void popup_fmt_dimmer(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = dec_to_str_n(g_opstate.tft_brightness,2,&DAT_00001a52);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a52;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== popup_fmt_free_text @ fff9a044 (42 bytes)

/* Value text of the free text pop-up (id 0x5E) for displink_build_31 frame 0x31 [fact: display
   gui.md popup-slot table (#178)] */

void popup_fmt_free_text(ushort param_1)

{
  ui_state *puVar1;
  
  puVar1 = PTR_g_ui_00025d38;
  (&DAT_00001749)[param_1] = PTR_g_ui_00025d38->popup_text[8];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(puVar1->popup_text + 4);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)puVar1->popup_text;
  return;
}


// ===== displink_build_34 @ fff9a06e (94 bytes)

void displink_build_34(byte param_1,byte param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  mem_zero(0x98,0x16a0);
  puVar1 = &DAT_00001741;
  for (iVar3 = 0x24a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  DAT_00001741 = 0x34;
  displink_copy_status();
  DAT_000017db = 0;
  puVar2 = &DAT_00001741;
  puVar1 = &DAT_00001456;
  DAT_000017d9 = param_1;
  DAT_000017da = param_2;
  for (iVar3 = 0x24a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== displink_tx_65_clock @ fff9a0cc (52 bytes)

/* 0x65 (9 bytes): +0xB2..+0xB6 (clock set [inference]) */

void displink_tx_65_clock(void)

{
  byte bVar1;
  
  PTR_g_ui_00025d38->dl_req_65_clock = 0;
  displink_build_65();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,8);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 9;
  displink_tx_start(9);
  return;
}


// ===== displink_build_65 @ fff9a100 (125 bytes)

void displink_build_65(void)

{
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x65;
  DAT_00001742 = PTR_g_ui_00025d38->rtc_set[0];
  DAT_00001743 = PTR_g_ui_00025d38->rtc_set[1];
  DAT_00001744 = PTR_g_ui_00025d38->rtc_set[2];
  DAT_00001745 = PTR_g_ui_00025d38->rtc_set[3];
  DAT_00001746 = PTR_g_ui_00025d38->rtc_set[4];
  return;
}


// ===== displink_tx_24 @ fff9a17d (42 bytes)

/* 0x24 (0x9F bytes) settings */

void displink_tx_24(void)

{
  byte bVar1;
  
  displink_build_24();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0x9e);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x9f;
  displink_tx_start(0x9f);
  return;
}


// ===== displink_build_24 @ fff9a1a7 (298 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9a1d6) */
/* WARNING: Removing unreachable block (ram,0xfff9a1dc) */

void displink_build_24(void)

{
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x24;
  displink_copy_status();
  DAT_000017d9 = g_opstate.ex030126_scu_lan10 << 2 | g_opstate.ex040402_pixel << 1 |
                 g_opstate.ex040401_ext_display;
  if (PTR_g_ui_00025d38->numentry_mode == 1) {
    DAT_000017d9 = DAT_000017d9 | 4;
  }
  DAT_000017da = g_opstate.ex030119_keyboard_language;
  DAT_000017db = g_opstate.ex040106_mouse_pointer_speed;
  if (PTR_g_ui_00025d38->numentry_mode != 0) {
    DAT_000017dc = BYTE_ARRAY_fff804e2[PTR_g_ui_00025d38->svc_brightness + 0x75];
    DAT_000017dd = BYTE_ARRAY_fff804e2[PTR_g_ui_00025d38->svc_brightness + 0x60];
    DAT_000017de = PTR_g_ui_00025d38->svc_contrast;
    return;
  }
  DAT_000017dc = BYTE_ARRAY_fff804e2[g_opstate.tft_brightness + 0x75];
  DAT_000017dd = BYTE_ARRAY_fff804e2[g_opstate.ex040105_led_dimmer + 0x60];
  DAT_000017de = g_opstate.tft_contrast;
  return;
}


// ===== displink_tx_50 @ fff9a2d1 (42 bytes)

/* 0x50 (0xF5 bytes) */

void displink_tx_50(void)

{
  byte bVar1;
  
  displink_build_50();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0xf4);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xf5;
  displink_tx_start(0xf5);
  return;
}


// ===== displink_build_50 @ fff9a2fb (105 bytes)

void displink_build_50(void)

{
  byte bVar1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x50;
  displink_copy_status();
  bVar1 = PTR_g_ui_00025d38->kbd_target;
  if (bVar1 == 6) {
    dl50_preset_name();
    return;
  }
  if (bVar1 == 1) {
    dl50_memory_name();
    return;
  }
  if (bVar1 == 2) {
    dl50_cw_text();
    return;
  }
  if (bVar1 == 3) {
    dl50_rtty_text();
    return;
  }
  if (bVar1 == 4) {
    dl50_psk_text();
    return;
  }
  if (bVar1 == 5) {
    dl50_file_name();
    return;
  }
  if (bVar1 != 0) {
    return;
  }
  dl50_mycall();
  return;
}


// ===== dl50_mycall @ fff9a364 (203 bytes)

/* Frame 0x50 payload for target 0: layout byte, cursor, title "MY CALL", char position, the 12-char
   text [fact: fff9a364; display-link.md frame 0x50] */

void dl50_mycall(void)

{
  if (PTR_g_ui_00025d38->kbd_layout == 0) {
    DAT_000017d9 = 0;
  }
  else if (PTR_g_ui_00025d38->kbd_layout == 1) {
    DAT_000017d9 = 1;
  }
  else {
    DAT_000017d9 = 2;
  }
  DAT_000017da = PTR_g_ui_00025d38->kbd_cursor;
  DAT_000017e5 = 0x4d;
  DAT_000017e6 = 0x59;
  DAT_000017e7 = 0x20;
  DAT_000017e8 = 0x43;
  DAT_000017e9 = 0x41;
  DAT_000017ea = 0x4c;
  DAT_000017eb = 0x4c;
  kbd_fmt_char_pos(&DAT_000017f9);
  kbd_copy_text(PTR_g_ui_00025d38->msg_text,0x1803,0xc);
  return;
}


// ===== dl50_memory_name @ fff9a42f (197 bytes)

/* Frame 0x50 payload for target 1: channel label (memch_label_fmt), title "MEMORY NAME", the
   12-char tag [fact: fff9a42f] */

void dl50_memory_name(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->kbd_layout == 0) {
    DAT_000017d9 = 0;
  }
  else if (PTR_g_ui_00025d38->kbd_layout == 1) {
    DAT_000017d9 = 1;
  }
  else {
    DAT_000017d9 = 2;
  }
  DAT_000017da = PTR_g_ui_00025d38->kbd_cursor;
  memch_label_fmt(&DAT_000017db,PTR_g_ui_00025d38->memlist_ch);
  iVar3 = suntil(0xfff8f350,0,0xffffffff,1);
  pcVar1 = &DAT_000017e5;
  pcVar2 = "MEMORY NAME";
  for (iVar3 = -2 - (-1 - (iVar3 + 0x70cb0)); iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  kbd_fmt_char_pos(&DAT_000017f9);
  kbd_copy_text(PTR_g_ui_00025d38->msg_text,0x1803,0xc);
  return;
}


// ===== dl50_cw_text @ fff9a4f4 (106 bytes)

/* Frame 0x50 payload for target 2: layout + 0x10, title "CW TEXT", dl50_slot_label, dl50_msg_text
   [fact: fff9a4f4] */

void dl50_cw_text(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->kbd_layout == 0) {
    DAT_000017d9 = 0x10;
  }
  else {
    DAT_000017d9 = 0x12;
  }
  DAT_000017da = PTR_g_ui_00025d38->kbd_cursor;
  dl50_slot_label();
  iVar3 = suntil(0xfff8f35c,0,0xffffffff,1);
  pcVar1 = &DAT_000017e5;
  pcVar2 = "CW TEXT";
  for (iVar3 = -2 - (-1 - (iVar3 + 0x70ca4)); iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  dl50_msg_text();
  return;
}


// ===== dl50_rtty_text @ fff9a55e (106 bytes)

/* Frame 0x50 payload for target 3: title "RTTY TEXT", slot label and 50-char text [fact: fff9a55e]
    */

void dl50_rtty_text(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->kbd_layout == 0) {
    DAT_000017d9 = 0x30;
  }
  else {
    DAT_000017d9 = 0x32;
  }
  DAT_000017da = PTR_g_ui_00025d38->kbd_cursor;
  dl50_slot_label();
  iVar3 = suntil(0xfff8f364,0,0xffffffff,1);
  pcVar1 = &DAT_000017e5;
  pcVar2 = "RTTY TEXT";
  for (iVar3 = -2 - (-1 - (iVar3 + 0x70c9c)); iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  dl50_msg_text();
  return;
}


// ===== dl50_psk_text @ fff9a5c8 (135 bytes)

/* Frame 0x50 payload for target 4: title "PSK TEXT", slot label and 50-char text [fact: fff9a5c8]
    */

void dl50_psk_text(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->kbd_layout == 0) {
    DAT_000017d9 = 0x20;
  }
  else if (PTR_g_ui_00025d38->kbd_layout == 1) {
    DAT_000017d9 = 0x21;
  }
  else {
    DAT_000017d9 = 0x22;
  }
  DAT_000017da = PTR_g_ui_00025d38->kbd_cursor;
  dl50_slot_label();
  iVar3 = suntil(0xfff8f36e,0,0xffffffff,1);
  pcVar1 = &DAT_000017e5;
  pcVar2 = "PSK TEXT";
  for (iVar3 = -2 - (-1 - (iVar3 + 0x70c92)); iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  dl50_msg_text();
  return;
}


// ===== dl50_file_name @ fff9a64f (170 bytes)

/* Frame 0x50 payload for target 5: layout + 0x40, title "FILE NAME", 20-char text [fact: fff9a64f]
    */

void dl50_file_name(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->kbd_layout == 0) {
    DAT_000017d9 = 0x40;
  }
  else if (PTR_g_ui_00025d38->kbd_layout == 1) {
    DAT_000017d9 = 0x41;
  }
  else {
    DAT_000017d9 = 0x42;
  }
  DAT_000017da = PTR_g_ui_00025d38->kbd_cursor;
  iVar3 = suntil(0xfff8f377,0,0xffffffff,1);
  pcVar1 = &DAT_000017e5;
  pcVar2 = "FILE NAME";
  for (iVar3 = -2 - (-1 - (iVar3 + 0x70c89)); iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  kbd_fmt_char_pos(&DAT_000017f9);
  kbd_copy_text(PTR_g_ui_00025d38->msg_text,0x1803,0x14);
  return;
}


// ===== dl50_preset_name @ fff9a6f9 (169 bytes)

/* Frame 0x50 payload for target 6: title "PRESET NAME", 12-char text [fact: fff9a6f9] */

void dl50_preset_name(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->kbd_layout == 0) {
    DAT_000017d9 = 0;
  }
  else if (PTR_g_ui_00025d38->kbd_layout == 1) {
    DAT_000017d9 = 1;
  }
  else {
    DAT_000017d9 = 2;
  }
  DAT_000017da = PTR_g_ui_00025d38->kbd_cursor;
  iVar3 = suntil(0xfff8f381,0,0xffffffff,1);
  pcVar1 = &DAT_000017e5;
  pcVar2 = "PRESET NAME";
  for (iVar3 = -2 - (-1 - (iVar3 + 0x70c7f)); iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  kbd_fmt_char_pos(&DAT_000017f9);
  kbd_copy_text(PTR_g_ui_00025d38->msg_text,0x1803,0xc);
  return;
}


// ===== kbd_fmt_char_pos @ fff9a7a2 (98 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9a7b3) */
/* WARNING: Removing unreachable block (ram,0xfff9a7c8) */
/* Keyboard frame 0x50: "Char #nn", nn = cursor UI +0xC1 + 1 [fact] */

void kbd_fmt_char_pos(undefined1 *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PTR_g_ui_00025d38->kbd_cursor;
  uVar2 = PTR_g_ui_00025d38->kbd_cursor + 1;
  *param_1 = 0x43;
  param_1[1] = 0x68;
  param_1[2] = 0x61;
  param_1[3] = 0x72;
  param_1[4] = 0x20;
  param_1[5] = 0x23;
  param_1[6] = (byte)((bVar1 + 1) / 10) | 0x30;
  param_1[7] = (char)uVar2 + (char)(uVar2 / 10) * -10 | 0x30;
  return;
}


// ===== kbd_copy_text @ fff9a804 (55 bytes)

/* (src, dst, n): copies the keyboard text and marks the cursor character (+0xC1) with 0xFF unless
   UI +0x1BC [fact] */

void kbd_copy_text(undefined1 *param_1,undefined1 *param_2,byte param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = param_2;
  for (uVar2 = (uint)param_3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  if (PTR_g_ui_00025d38->kbd_show_cursor_char != 0) {
    return;
  }
  param_2[PTR_g_ui_00025d38->kbd_cursor] = 0xff;
  return;
}


// ===== dl50_slot_label @ fff9a83b (46 bytes)

/* Frame 0x50 bytes 0x9A..0x9C = 'c', 'h', '1' + g_ui.msg_slot_idx [fact: fff9a83b] */

void dl50_slot_label(void)

{
  DAT_000017db = 99;
  DAT_000017dc = 0x68;
  DAT_000017dd = PTR_g_ui_00025d38->msg_slot_idx + 1 | 0x30;
  return;
}


// ===== dl50_msg_text @ fff9a869 (50 bytes)

/* Frame 0x50: kbd_fmt_char_pos and the 50-char text of slot msg_slot_idx (UI msg_text) at byte 0xC2
   [fact: fff9a869] */

void dl50_msg_text(void)

{
  kbd_fmt_char_pos(&DAT_000017f9);
  kbd_copy_text(PTR_g_ui_00025d38->msg_text + PTR_g_ui_00025d38->msg_slot_idx,0x1803,0x32);
  return;
}


// ===== displink_tx_3F @ fff9a89b (72 bytes)

/* 0x3F (5 bytes): +0x92 */

void displink_tx_3F(void)

{
  PTR_g_ui_00025d38->dl_req_3f = 0;
  DAT_00001456 = 0x3f;
  DAT_00001457 = PTR_g_ui_00025d38->dvs_lm1_flag;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_3A @ fff9a8e3 (66 bytes)

/* 0x3A (0xA2 bytes) */

void displink_tx_3A(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->playlist_req == 0) {
    return;
  }
  PTR_g_ui_00025d38->playlist_req = 0;
  displink_build_3A();
  puVar2 = &DAT_00001741;
  puVar1 = &DAT_00001456;
  for (iVar3 = 0xa1; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  DAT_0001b628 = 0xa2;
  displink_tx_start(0xa2);
  return;
}


// ===== displink_build_3A @ fff9a925 (392 bytes)

void displink_build_3A(void)

{
  byte bVar1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x3a;
  displink_copy_status();
  DAT_000017d9 = PTR_g_ui_00025d38->playlist_substate;
  DAT_000017da = 0;
  DAT_000017db = 0;
  bVar1 = PTR_g_ui_00025d38->playlist_substate;
  if (bVar1 == 4) {
    DAT_000017dc = PTR_g_ui_00025d38->playlist_playing & 1;
    DAT_000017dd = g_opstate.play_volume;
    return;
  }
  if (bVar1 == 1) {
    DAT_000017dc = (char)(PTR_g_ui_00025d38->playlist_first >> 8);
    DAT_000017dd = (char)PTR_g_ui_00025d38->playlist_first;
    DAT_000017de = PTR_g_ui_00025d38->playlist_row;
    DAT_000017df = 0;
    return;
  }
  if (bVar1 == 2) {
    DAT_000017dc = (char)(PTR_g_ui_00025d38->playlist_first >> 8);
    DAT_000017dd = (char)PTR_g_ui_00025d38->playlist_first;
    DAT_000017de = PTR_g_ui_00025d38->playlist_row;
    DAT_000017df = PTR_g_ui_00025d38->playlist_cmd;
    return;
  }
  if (bVar1 == 3) {
    DAT_000017dc = (char)(PTR_g_ui_00025d38->playlist_first >> 8);
    DAT_000017dd = (char)PTR_g_ui_00025d38->playlist_first;
    DAT_000017de = PTR_g_ui_00025d38->playlist_row;
    return;
  }
  if (bVar1 != 0) {
    return;
  }
  DAT_000017dc = g_opstate.play_volume;
  return;
}


// ===== displink_tx_40 @ fff9aaad (74 bytes)

/* 0x40 (0x1FB bytes), rate-limited 100 units (timer 0x29) */

void displink_tx_40(void)

{
  byte bVar1;
  
  displink_build_40();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0x1fa);
  if (bVar1 == 0) {
    if (PTR_g_ui_00025d38->dl_40_force == 0) {
      return;
    }
    PTR_g_ui_00025d38->dl_40_force = 0;
  }
  DAT_0001b628 = 0x1fb;
  displink_tx_start(0x1fb);
  return;
}


// ===== displink_build_40 @ fff9aaf7 (51 bytes)

void displink_build_40(void)

{
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x40;
  displink_copy_status();
  menu_page_serialize(0x1741,0x98);
  return;
}


// ===== displink_tx_37 @ fff9ab2a (45 bytes)

/* 0x37 (0x240 bytes) */

void displink_tx_37(void)

{
  byte bVar1;
  
  displink_build_37();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0x23f);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x240;
  displink_tx_start(0x240);
  return;
}


// ===== displink_build_37 @ fff9ab57 (413 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9aba2) */
/* WARNING: Removing unreachable block (ram,0xfff9aba8) */
/* WARNING: Removing unreachable block (ram,0xfff9abb0) */

void displink_build_37(void)

{
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x37;
  displink_copy_status();
  PTR_g_ui_00025d38->dl37_bit7 = 1;
  PTR_g_ui_00025d38->dl37_bit5 = 0;
  DAT_000017d9 = PTR_g_ui_00025d38->dl37_bit7 << 7 | PTR_g_ui_00025d38->func_assigned << 6 |
                 PTR_g_ui_00025d38->dl37_bit5 << 5;
  DAT_000017da = g_opstate.func_knob_sf;
  DAT_000017db = 0;
  dl37_slot_scope_level(0x9b);
  dl37_slot_peak(0xa5);
  dl37_slot_marker(0xaf);
  dl37_slot_color(0xb9);
  dl37_slot_contrast(0xc3);
  dl37_slot_dimmer(0xcd);
  dl37_slot_mgroup(0xd7);
  dl37_slot_mic_gain(0xe1);
  dl37_slot_mic_eq(0xeb);
  dl37_slot_proc_level(0xf5);
  dl37_slot_amc_level(0xff);
  dl37_slot_vox_gain(0x109);
  dl37_slot_vox_delay(0x113);
  dl37_slot_anti_vox(0x11d);
  dl37_slot_rf_power(0x127);
  dl37_slot_moni_level(0x131);
  dl37_slot_keyer(0x13b);
  dl37_slot_bk_in(0x145);
  dl37_slot_cw_speed(0x14f);
  dl37_slot_cw_pitch(0x159);
  dl37_slot_bk_delay(0x163);
  dl37_slot_message(0x16d);
  dl37_slot_record(0x177);
  dl37_slot_play(0x181);
  dl37_slot_txw(0x18b);
  dl37_slot_empty(0x195);
  dl37_slot_aess(0x19f);
  dl37_slot_aess_cf(0x1a9);
  dl37_slot_radio_setting(0x1b3);
  dl37_slot_cw_setting(0x1bd);
  dl37_slot_operation_setting(0x1c7);
  dl37_slot_display_setting(0x1d1);
  dl37_slot_extension_setting(0x1db);
  dl37_slot_empty(0x1e5);
  dl37_slot_empty(0x1ef);
  dl37_slot_empty(0x1f9);
  dl37_slot_empty(0x203);
  dl37_slot_empty(0x20d);
  dl37_slot_empty(0x217);
  dl37_slot_empty(0x221);
  dl37_slot_empty(0x22b);
  dl37_slot_empty(0x235);
  return;
}


// ===== dl37_slot_scope_level @ fff9acf4 (69 bytes)

/* (offset): writes FUNC-panel slot {flag, id, 8-char text} of frame 0x37 for function id 0 (SCOPE
   LEVEL), value text by popup_fmt_scope_level [fact: fff9acf4]; only caller displink_build_37; ids
   per display-link.md "0x37 FUNC panel" */

void dl37_slot_scope_level(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  popup_fmt_scope_level(param_1);
  return;
}


// ===== dl37_slot_peak @ fff9ad39 (69 bytes)

/* (offset): writes FUNC-panel slot {flag, id, 8-char text} of frame 0x37 for function id 1 (PEAK),
   value text by popup_fmt_peak [fact: fff9ad39]; only caller displink_build_37; ids per
   display-link.md "0x37 FUNC panel" */

void dl37_slot_peak(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 1;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  popup_fmt_peak(param_1);
  return;
}

