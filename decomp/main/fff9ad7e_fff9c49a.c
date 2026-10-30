// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff9ad7e @ fff9ad7e (96 bytes)

void FUN_fff9ad7e(ushort param_1)

{
  int iVar1;
  
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 2;
  iVar1 = (uint)(g_opstate.ss02_marker == 1) * 9;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar1 + 0x25e);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + iVar1 + 0x25a);
  return;
}


// ===== FUN_fff9adde @ fff9adde (83 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9ae15) */

void FUN_fff9adde(ushort param_1)

{
  uint uVar1;
  
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 3;
  uVar1 = (uint)g_opstate.ss03_value;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff8046c + uVar1 * 8 + 4);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff8046c + uVar1 * 8);
  return;
}


// ===== FUN_fff9ae31 @ fff9ae31 (69 bytes)

void FUN_fff9ae31(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 4;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99e15(param_1);
  return;
}


// ===== FUN_fff9ae76 @ fff9ae76 (69 bytes)

void FUN_fff9ae76(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 5;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9a00f(param_1);
  return;
}


// ===== FUN_fff9aebb @ fff9aebb (64 bytes)

void FUN_fff9aebb(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 6;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9aefb @ fff9aefb (69 bytes)

void FUN_fff9aefb(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 7;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99837(param_1);
  return;
}


// ===== FUN_fff9af40 @ fff9af40 (114 bytes)

void FUN_fff9af40(ushort param_1)

{
  int iVar1;
  byte bStack_4;
  undefined1 uStack_3;
  
  iVar1 = FUN_fffc3d75();
  if (iVar1 == 0) {
    uStack_3 = 0x80;
    bStack_4 = 0;
  }
  else {
    uStack_3 = 0;
    if (g_opstate.proc_on == 0) {
      bStack_4 = 0;
    }
    else {
      bStack_4 = 1;
    }
  }
  (&DAT_00001741)[param_1] = uStack_3;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 8;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + (uint)bStack_4 * 9 + 0x25e);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + (uint)bStack_4 * 9 + 0x25a);
  return;
}


// ===== FUN_fff9afb2 @ fff9afb2 (69 bytes)

void FUN_fff9afb2(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 9;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff997df(param_1);
  return;
}


// ===== FUN_fff9aff7 @ fff9aff7 (69 bytes)

void FUN_fff9aff7(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 10;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99a8a(param_1);
  return;
}


// ===== FUN_fff9b03c @ fff9b03c (69 bytes)

void FUN_fff9b03c(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xb;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff996e2(param_1);
  return;
}


// ===== FUN_fff9b081 @ fff9b081 (69 bytes)

void FUN_fff9b081(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xc;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99717(param_1);
  return;
}


// ===== FUN_fff9b0c6 @ fff9b0c6 (69 bytes)

void FUN_fff9b0c6(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xd;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9978c(param_1);
  return;
}


// ===== FUN_fff9b10b @ fff9b10b (69 bytes)

void FUN_fff9b10b(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xe;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff995cc(param_1);
  return;
}


// ===== FUN_fff9b150 @ fff9b150 (69 bytes)

void FUN_fff9b150(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xf;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9960e(param_1);
  return;
}


// ===== FUN_fff9b195 @ fff9b195 (125 bytes)

void FUN_fff9b195(ushort param_1)

{
  vfo_rec *pvVar1;
  int iVar2;
  byte bStack_a;
  undefined1 uStack_9;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  iVar2 = keyer_mode_class(pvVar1);
  if (iVar2 == 0) {
    uStack_9 = 0x80;
    bStack_a = 0;
  }
  else {
    uStack_9 = 0;
    if (g_opstate.keyer_on == 0) {
      bStack_a = 0;
    }
    else {
      bStack_a = 1;
    }
  }
  (&DAT_00001741)[param_1] = uStack_9;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x10;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + (uint)bStack_a * 9 + 0x25e);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + (uint)bStack_a * 9 + 0x25a);
  return;
}


// ===== FUN_fff9b212 @ fff9b212 (143 bytes)

void FUN_fff9b212(ushort param_1)

{
  bool bVar1;
  vfo_rec *pvVar2;
  int iVar3;
  byte bStack_a;
  undefined1 uStack_9;
  
  pvVar2 = vfo_rec_ptr(VFO_TX);
  iVar3 = FUN_fffc3f1b(pvVar2);
  if ((iVar3 == 1) || (iVar3 = keyer_mode_class(pvVar2), iVar3 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uStack_9 = 0;
    iVar3 = FUN_fff99dbf(pvVar2);
    if (iVar3 == 0) {
      bStack_a = 0;
    }
    else {
      bStack_a = 1;
    }
  }
  else {
    uStack_9 = 0x80;
    bStack_a = 0;
  }
  (&DAT_00001741)[param_1] = uStack_9;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x11;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + (uint)bStack_a * 9 + 0x25e);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(BYTE_ARRAY_fff800f3 + (uint)bStack_a * 9 + 0x25a);
  return;
}


// ===== FUN_fff9b2a1 @ fff9b2a1 (70 bytes)

void FUN_fff9b2a1(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x12;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff998e2(param_1);
  return;
}


// ===== FUN_fff9b2e7 @ fff9b2e7 (70 bytes)

void FUN_fff9b2e7(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x13;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9992a(param_1);
  return;
}


// ===== FUN_fff9b32d @ fff9b32d (70 bytes)

void FUN_fff9b32d(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x14;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99989(param_1);
  return;
}


// ===== FUN_fff9b373 @ fff9b373 (91 bytes)

void FUN_fff9b373(ushort param_1)

{
  vfo_rec *pvVar1;
  ushort local_2;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  if ((pvVar1->mode & 0xf) - 8 < 7) {
    (&DAT_00001741)[param_1] = 0x80;
  }
  else {
    (&DAT_00001741)[param_1] = 0;
  }
  local_2 = param_1 + 1;
  (&DAT_00001741)[local_2] = 0x16;
  return;
}


// ===== FUN_fff9b3ce @ fff9b3ce (80 bytes)

void FUN_fff9b3ce(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  if (PTR_g_ui_00025d38->dvs_lm1_flag != 0) {
    (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x35;
    return;
  }
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x17;
  return;
}


// ===== FUN_fff9b41e @ fff9b41e (65 bytes)

void FUN_fff9b41e(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x18;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b45f @ fff9b45f (45 bytes)

void FUN_fff9b45f(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x2d;
  return;
}


// ===== FUN_fff9b48c @ fff9b48c (70 bytes)

void FUN_fff9b48c(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x15;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff999e3(param_1);
  return;
}


// ===== FUN_fff9b4d2 @ fff9b4d2 (70 bytes)

void FUN_fff9b4d2(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x3a;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99a29(param_1);
  return;
}


// ===== FUN_fff9b518 @ fff9b518 (65 bytes)

void FUN_fff9b518(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x30;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b559 @ fff9b559 (65 bytes)

void FUN_fff9b559(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x31;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b59a @ fff9b59a (65 bytes)

void FUN_fff9b59a(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x32;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b5db @ fff9b5db (65 bytes)

void FUN_fff9b5db(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x33;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b61c @ fff9b61c (65 bytes)

void FUN_fff9b61c(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x34;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b65d @ fff9b65d (65 bytes)

void FUN_fff9b65d(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xff;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== displink_tx_39 @ fff9b69e (42 bytes)

/* 0x39 (0xE9 bytes) */

void displink_tx_39(void)

{
  byte bVar1;
  
  displink_build_39();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0xe8);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xe9;
  displink_tx_start(0xe9);
  return;
}


// ===== displink_build_39 @ fff9b6c8 (848 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void displink_build_39(void)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  undefined1 uStack_4;
  byte bStack_1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x39;
  displink_copy_status();
  bStack_1 = PTR_g_ui_00025d38->msgmem_type;
  pbVar4 = BYTE_ARRAY_fff800f3 + (uint)bStack_1 * 0x19 + 0x1cd;
  pbVar3 = &DAT_000017d9;
  for (iVar5 = 0x19; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pbVar3 = *pbVar4;
    pbVar3 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
  }
  if (PTR_g_ui_00025d38->msg_state_1d0 == 1) {
    bStack_1 = bStack_1 | 8;
  }
  if (PTR_g_ui_00025d38->msg_playing == 1) {
    bStack_1 = bStack_1 | 4;
  }
  if (PTR_g_ui_00025d38->dvs_state == 1) {
    bStack_1 = bStack_1 | 0x10;
  }
  else if (PTR_g_ui_00025d38->dvs_state == 2) {
    bStack_1 = bStack_1 | 0x20;
  }
  DAT_000017f2 = bStack_1;
  DAT_000017f3 = FUN_fffe5783();
  bStack_1 = 0;
  if ((PTR_g_ui_00025d38->msg_active == 1) && (PTR_g_ui_00025d38->msg_channel < 8)) {
    bStack_1 = (byte)(1 << (PTR_g_ui_00025d38->msg_channel & 0x1f));
  }
  DAT_000017f4 = bStack_1;
  bStack_1 = 0;
  if (PTR_g_ui_00025d38->dvs_busy == 0) {
    if ((PTR_g_ui_00025d38->dvs_state == 1) || (PTR_g_ui_00025d38->dvs_state == 2)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_g_ui_00025d38->msg_rec_active == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_g_ui_00025d38->ky_send_0 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_g_ui_00025d38->ky_send_1 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_g_ui_00025d38->msg_state_1d0 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_g_ui_00025d38->msg_playing == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bStack_1 = PTR_g_ui_00025d38->msg_slot;
    }
  }
  DAT_000017f5 = bStack_1;
  DAT_000017f6 = 0;
  bStack_1 = g_opstate.ex020206_cw_memory_1 == 1;
  if (g_opstate.ex020207_cw_memory_2 == 1) {
    bStack_1 = bStack_1 | 2;
  }
  if (g_opstate.ex020208_cw_memory_3 == 1) {
    bStack_1 = bStack_1 | 4;
  }
  if (g_opstate.ex020209_cw_memory_4 == 1) {
    bStack_1 = bStack_1 | 8;
  }
  if (g_opstate.ex020210_cw_memory_5 == 1) {
    bStack_1 = bStack_1 | 0x10;
  }
  DAT_000017f7 = bStack_1;
  DAT_000017f8 = g_opstate.play_volume;
  DAT_000017f9 = g_opstate.level_9dc2;
  DAT_000017fa = 0;
  DAT_000017fb = (undefined1)(PTR_g_ui_00025d38->msg_timer >> 8);
  uStack_4 = (undefined1)PTR_g_ui_00025d38->msg_timer;
  DAT_000017fc._0_1_ = uStack_4;
  DAT_000017fc._1_1_ = 0;
  DAT_000017fc._2_1_ = 0;
  DAT_000017fc._3_1_ = 0;
  DAT_00001800._0_1_ = 0;
  bVar1 = PTR_g_ui_00025d38->msgmem_type;
  if (bVar1 != 0) {
    if (bVar1 == 2) {
      displink_39_rtty_labels();
    }
    else if (bVar1 == 1) {
      displink_39_keyer_texts();
    }
    ram0x00001805 = *(undefined4 *)(PTR_g_ui_00025d38->msg_text[0] + 4);
    ram0x00001801 = *(undefined4 *)PTR_g_ui_00025d38->msg_text[0];
    ram0x0000180d = *(undefined4 *)(PTR_g_ui_00025d38->msg_text[1] + 4);
    ram0x00001809 = *(undefined4 *)PTR_g_ui_00025d38->msg_text[1];
    DAT_00001815 = *(undefined4 *)(PTR_g_ui_00025d38->msg_text[2] + 4);
    ram0x00001811 = *(undefined4 *)PTR_g_ui_00025d38->msg_text[2];
    DAT_0000181d = *(undefined4 *)(PTR_g_ui_00025d38->msg_text[3] + 4);
    DAT_00001819 = *(undefined4 *)PTR_g_ui_00025d38->msg_text[3];
    DAT_00001825 = *(undefined4 *)(PTR_g_ui_00025d38->msg_text[4] + 4);
    DAT_00001821 = *(undefined4 *)PTR_g_ui_00025d38->msg_text[4];
    return;
  }
  return;
}


// ===== displink_39_keyer_texts @ fff9ba18 (136 bytes)

/* Frame 0x39, message type 1 (CW): copies the five KM keyer texts 0x96A0+n*0x33 into UI +0xC2.. (5
   x 0x32) */

void displink_39_keyer_texts(void)

{
  byte (*pabVar1) [50];
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = &DAT_000096a0;
  pabVar1 = PTR_g_ui_00025d38->msg_text;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    (*pabVar1)[0] = *pbVar2;
    pabVar1 = (byte (*) [50])(*pabVar1 + 1);
    pbVar2 = pbVar2 + 1;
  }
  pbVar2 = &DAT_000096d3;
  pabVar1 = PTR_g_ui_00025d38->msg_text + 1;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    (*pabVar1)[0] = *pbVar2;
    pabVar1 = (byte (*) [50])(*pabVar1 + 1);
    pbVar2 = pbVar2 + 1;
  }
  pbVar2 = &DAT_00009706;
  pabVar1 = PTR_g_ui_00025d38->msg_text + 2;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    (*pabVar1)[0] = *pbVar2;
    pabVar1 = (byte (*) [50])(*pabVar1 + 1);
    pbVar2 = pbVar2 + 1;
  }
  pbVar2 = &DAT_00009739;
  pabVar1 = PTR_g_ui_00025d38->msg_text + 3;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    (*pabVar1)[0] = *pbVar2;
    pabVar1 = (byte (*) [50])(*pabVar1 + 1);
    pbVar2 = pbVar2 + 1;
  }
  pbVar2 = &DAT_0000976c;
  pabVar1 = PTR_g_ui_00025d38->msg_text + 4;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    (*pabVar1)[0] = *pbVar2;
    pabVar1 = (byte (*) [50])(*pabVar1 + 1);
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== displink_39_rtty_labels @ fff9baa0 (131 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Frame 0x39, message type 2 (RTTY): first 8 bytes of the five EM text slots 0x979E.. into frame
   bytes 0xC0..0xE7 (0x1801..) */

void displink_39_rtty_labels(void)

{
  ram0x00001805 = DAT_000097a2;
  ram0x00001801 = DAT_0000979e;
  ram0x0000180d = DAT_000097d4;
  ram0x00001809 = DAT_000097d0;
  DAT_00001815 = DAT_00009806;
  ram0x00001811 = DAT_00009802;
  DAT_0000181d = DAT_00009838;
  DAT_00001819 = DAT_00009834;
  DAT_00001825 = DAT_0000986a;
  DAT_00001821 = DAT_00009866;
  return;
}


// ===== displink_tx_41 @ fff9bb23 (45 bytes)

/* 0x41 (0x146 bytes) */

void displink_tx_41(void)

{
  byte bVar1;
  
  displink_build_41();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0x145);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x146;
  displink_tx_start(0x146);
  return;
}


// ===== displink_build_41 @ fff9bb50 (1128 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9bc1f) */
/* WARNING: Removing unreachable block (ram,0xfff9bbf2) */
/* WARNING: Removing unreachable block (ram,0xfff9bbf8) */
/* WARNING: Removing unreachable block (ram,0xfff9be3f) */

void displink_build_41(void)

{
  uint uVar1;
  vfo_rec *pvVar2;
  bool bVar3;
  byte bVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  ushort uVar8;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  byte bStack_2;
  byte bStack_1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x41;
  displink_copy_status();
  bStack_1 = FUN_fffc2b2e(PTR_g_ui_00025d38->memlist_first,PTR_g_ui_00025d38->memlist_row);
  bStack_2 = FUN_fff9c04a();
  if ((bStack_2 == 0) || (bStack_1 < bStack_2)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (bVar3) {
    PTR_g_ui_00025d38->memlist_sel_valid = 0;
  }
  else {
    bVar3 = memch_valid(bStack_1,(byte **)&DAT_00020880);
    if (bVar3) {
      PTR_g_ui_00025d38->memlist_sel_valid = 0;
    }
    else {
      PTR_g_ui_00025d38->memlist_sel_valid = 1;
    }
  }
  DAT_000017d9 = PTR_g_ui_00025d38->memlist_sel_valid << 7 | PTR_g_ui_00025d38->memlist_flag << 6;
  DAT_000017da = PTR_g_ui_00025d38->memlist_group << 4 | PTR_g_ui_00025d38->memlist_row;
  DAT_0001b632 = 0x9c;
  puVar5 = &DAT_000017dd;
  puVar6 = &DAT_fff804c4;
  for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = *puVar6;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar8 = DAT_0001b632 + 0xf;
  DAT_0001b632 = uVar8;
  if (g_opstate.ex030114_mem_group == 1) {
    bStack_1 = FUN_fff9bfe1(bStack_1);
    uVar1 = (uint)DAT_0001b632;
    *(undefined2 *)(&DAT_00001745 + uVar1) = 0x2050;
    *(undefined4 *)(&DAT_00001741 + uVar1) = 0x554f5247;
    DAT_0001b632 = DAT_0001b632 + 6;
    if (bStack_1 < 6) {
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = bStack_1 + 0x30;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
    }
    else {
      bStack_1 = bStack_1 - 6;
      *(undefined4 *)(&DAT_00001741 + DAT_0001b632) =
           *(undefined4 *)(BYTE_ARRAY_fff8035e + (uint)bStack_1 * 4 + 0x12);
      DAT_0001b632 = DAT_0001b632 + 4;
    }
  }
  else {
    *(undefined4 *)(&DAT_00001745 + uVar8) = 0x20202020;
    *(undefined4 *)(&DAT_00001741 + uVar8) = 0x20202020;
    *(undefined2 *)(&DAT_00001749 + uVar8) = 0x2020;
    DAT_0001b632 = DAT_0001b632 + 10;
  }
  bStack_4 = PTR_g_ui_00025d38->memlist_first;
  for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
    DAT_00020884 = memch + bStack_4;
    bVar3 = memch_valid(bStack_4,(byte **)&DAT_00020880);
    if (bVar3) {
      bStack_1 = DAT_00020884->flags5 >> 7 | DAT_00020884->flags1 >> 6 & 2;
      (&DAT_00001741)[DAT_0001b632] = bStack_1;
      DAT_0001b632 = DAT_0001b632 + 1;
      FUN_fff9c089(&DAT_00001741 + DAT_0001b632,bStack_4);
      DAT_0001b632 = DAT_0001b632 + 5;
      FUN_fff9c2f9(&DAT_00001741 + DAT_0001b632,bStack_4);
      DAT_0001b632 = DAT_0001b632 + 10;
      bStack_1 = DAT_00020884->mode & 0xf;
      if (0xd < bStack_1) {
        bStack_1 = 0xe;
      }
      uVar1 = (uint)DAT_0001b632;
      *(undefined4 *)(&DAT_00001745 + DAT_0001b632) =
           *(undefined4 *)(BYTE_ARRAY_fff8035e + (uint)bStack_1 * 8 + 0x22);
      *(undefined4 *)(&DAT_00001741 + uVar1) =
           *(undefined4 *)(BYTE_ARRAY_fff8035e + (uint)bStack_1 * 8 + 0x1e);
      pvVar2 = DAT_00020884;
      uVar8 = DAT_0001b632 + 8;
      DAT_0001b632 = uVar8;
      *(undefined4 *)(&DAT_00001749 + uVar8) = *(undefined4 *)(DAT_00020884->tag + 8);
      *(undefined4 *)(&DAT_00001745 + uVar8) = *(undefined4 *)(pvVar2->tag + 4);
      *(undefined4 *)(&DAT_00001741 + uVar8) = *(undefined4 *)pvVar2->tag;
    }
    else {
      (&DAT_00001741)[DAT_0001b632] = 0;
      DAT_0001b632 = DAT_0001b632 + 1;
      FUN_fff9c089(&DAT_00001741 + DAT_0001b632,bStack_4);
      uVar8 = DAT_0001b632 + 5;
      DAT_0001b632 = uVar8;
      *(undefined4 *)(&DAT_00001745 + uVar8) = 0x2d2e2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar8) = 0x2d2e2d2d;
      *(undefined2 *)(&DAT_00001749 + uVar8) = 0x2d2d;
      DAT_0001b632 = DAT_0001b632 + 10;
      uVar1 = (uint)DAT_0001b632;
      *(undefined4 *)(&DAT_00001745 + DAT_0001b632) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar1) = 0x2d2d2d2d;
      uVar8 = DAT_0001b632 + 8;
      DAT_0001b632 = uVar8;
      *(undefined4 *)(&DAT_00001749 + uVar8) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001745 + uVar8) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar8) = 0x2d2d2d2d;
    }
    DAT_0001b632 = DAT_0001b632 + 0xc;
    FUN_fff9c1a1((char *)&bStack_5,(char *)&bStack_6);
    if (bStack_6 != bStack_5) {
      bStack_6 = bStack_6 + 1;
      do {
        bStack_4 = bStack_4 + 1;
        if (bStack_6 <= bStack_4) {
          bStack_4 = bStack_5;
        }
        if ((bStack_4 < 0x84) && (0x74 < bStack_4)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
      } while ((bVar3) &&
              ((iVar7 = dest_has_5mhz_channels(), iVar7 != 1 ||
               (bVar4 = memch_dest_blocked(bStack_4), bVar4 != 0))));
    }
  }
  return;
}


// ===== FUN_fff9bfb8 @ fff9bfb8 (41 bytes)

undefined1 FUN_fff9bfb8(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  bVar1 = memch_current(g_opstate.active_vfo != VFO_A);
  uVar2 = FUN_fff9bfe1(bVar1);
  return uVar2;
}


// ===== FUN_fff9bfe1 @ fff9bfe1 (105 bytes)

char FUN_fff9bfe1(byte param_1)

{
  byte local_5;
  byte local_4;
  char local_3;
  
  if (param_1 < 0x84) {
    if (param_1 < 0x75) {
      if (param_1 < 99) {
        local_5 = 0;
        local_4 = 0;
        while ((local_4 < 5 && (local_5 = (&DAT_fff804d3)[local_4] + local_5, local_5 <= param_1)))
        {
          local_4 = local_4 + 1;
        }
        if (local_4 == 5) {
          local_4 = 0;
        }
        local_3 = local_4 + 1;
      }
      else {
        local_3 = '\x06';
      }
    }
    else {
      local_3 = '\a';
    }
  }
  else {
    local_3 = '\b';
  }
  return local_3;
}


// ===== FUN_fff9c04a @ fff9c04a (63 bytes)

undefined1 FUN_fff9c04a(void)

{
  ushort uVar1;
  
  uVar1 = dest_code_get();
  if ((uVar1 != 0x20b) && (uVar1 != 0x1cb9)) {
    if (uVar1 == 0x315b) {
      return 0x84;
    }
    if (uVar1 != 0x4380) {
      if (uVar1 == 0x50e2) {
        return 0x84;
      }
      if (uVar1 != 0x60e6) {
        return 0;
      }
    }
  }
  return 0x75;
}


// ===== FUN_fff9c089 @ fff9c089 (217 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c0ec) */
/* WARNING: Removing unreachable block (ram,0xfff9c0a3) */
/* WARNING: Removing unreachable block (ram,0xfff9c0f7) */
/* WARNING: Removing unreachable block (ram,0xfff9c0cf) */
/* WARNING: Removing unreachable block (ram,0xfff9c12f) */
/* WARNING: Removing unreachable block (ram,0xfff9c15f) */

undefined4 * FUN_fff9c089(undefined4 *param_1,byte param_2)

{
  byte n;
  char cVar1;
  undefined4 *puVar2;
  
  if (0x83 < param_2) {
    *(undefined1 *)(param_1 + 1) = 0x20;
    *param_1 = 0x20474d45;
    return param_1;
  }
  if (param_2 < 0x75) {
    if (0x62 < param_2) {
      *(undefined1 *)((int)param_1 + 2) = 0x50;
      *(undefined2 *)param_1 = 0x2d4d;
      if ((param_2 + 0x9d & 1) == 0) {
        *(undefined1 *)(param_1 + 1) = 0x4c;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 0x55;
      }
      puVar2 = (undefined4 *)((byte)(((byte)(param_2 + 0x9d) >> 1) + 1) + 0x30);
      *(char *)((int)param_1 + 3) = (char)puVar2;
      return puVar2;
    }
    *(undefined2 *)param_1 = 0x2d4d;
    if ((byte)(param_2 + 1) < 10) {
      *(undefined1 *)((int)param_1 + 2) = 0x30;
      *(byte *)((int)param_1 + 3) = param_2 + 0x31;
    }
    else {
      dec_to_str_u8(param_2 + 1,(undefined2 *)((int)param_1 + 2));
    }
    *(undefined1 *)(param_1 + 1) = 0x20;
    return param_1;
  }
  *(undefined2 *)param_1 = 0x2d35;
  n = FUN_fff9c162(param_2);
  if (n < 10) {
    *(undefined1 *)((int)param_1 + 2) = 0x30;
    cVar1 = nib2hex(n);
    *(char *)((int)param_1 + 3) = cVar1;
    return (undefined4 *)(int)cVar1;
  }
  if (n < 0x14) {
    *(undefined1 *)((int)param_1 + 2) = 0x31;
    cVar1 = nib2hex(n - 10);
    *(char *)((int)param_1 + 3) = cVar1;
    return (undefined4 *)(int)cVar1;
  }
  *(undefined1 *)((int)param_1 + 2) = 0x2a;
  *(undefined1 *)((int)param_1 + 3) = 0x2a;
  return param_1;
}


// ===== FUN_fff9c162 @ fff9c162 (63 bytes)

char FUN_fff9c162(byte param_1)

{
  byte bVar1;
  byte local_4;
  char local_3;
  
  local_3 = '\0';
  local_4 = 0;
  while( true ) {
    if (0xe < local_4) {
      return local_3;
    }
    bVar1 = memch_dest_blocked(local_4 + 0x75);
    if (bVar1 == 0) {
      local_3 = local_3 + '\x01';
    }
    if ((uint)param_1 == local_4 + 0x75) break;
    local_4 = local_4 + 1;
  }
  return local_3;
}


// ===== FUN_fff9c1a1 @ fff9c1a1 (241 bytes)

void FUN_fff9c1a1(char *param_1,char *param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte bStack_a;
  
  if ((g_opstate.ex030114_mem_group == 1) && (PTR_g_ui_00025d38->memlist_open == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    *param_1 = '\0';
    iVar3 = FUN_fff9c292();
    if ((iVar3 == 1) && (g_opstate.ex030406_emergency_freq_tx == 1)) {
      *param_2 = -0x7c;
      return;
    }
    iVar3 = dest_has_5mhz_channels();
    if (iVar3 == 1) {
      *param_2 = -0x7d;
      return;
    }
    *param_2 = 't';
    return;
  }
  bVar2 = FUN_fff9bfb8();
  if (bVar2 == 6) {
    *param_1 = 'c';
    *param_2 = 't';
    return;
  }
  if (bVar2 < 8) {
    if (bVar2 < 7) {
      *param_1 = '\0';
      *param_2 = '\x12';
      for (bStack_a = 0; (bStack_a < 5 && ((uint)bVar2 != bStack_a + 1)); bStack_a = bStack_a + 1) {
        *param_1 = (&DAT_fff804d3)[bStack_a] + *param_1;
        *param_2 = *param_2 + BYTE_ARRAY_fff804d4[bStack_a];
      }
      return;
    }
    *param_1 = 'u';
    *param_2 = -0x7d;
    return;
  }
  *param_1 = -0x7c;
  *param_2 = -0x7c;
  return;
}


// ===== FUN_fff9c292 @ fff9c292 (59 bytes)

undefined1 FUN_fff9c292(void)

{
  ushort uVar1;
  undefined1 local_2;
  
  local_2 = 1;
  uVar1 = dest_code_get();
  if ((((uVar1 == 0x306f) || (uVar1 == 0xa4c5)) || (uVar1 == 0xa983)) ||
     (((uVar1 == 0xb5a7 || (uVar1 == 0xd32d)) || (uVar1 == 0xd950)))) {
    local_2 = 0;
  }
  return local_2;
}


// ===== dest_has_5mhz_channels @ fff9c2cd (44 bytes)

/* 1 for destination codes 0x315B / 0x50E2 / 0xA4C5 / 0xD950, which have the 60 m (5 MHz) channels
   501..515 (cat_MC, displink_build_41) [fact] */

undefined1 dest_has_5mhz_channels(void)

{
  ushort uVar1;
  undefined1 local_2;
  
  local_2 = 0;
  uVar1 = dest_code_get();
  if ((((uVar1 == 0x315b) || (uVar1 == 0x50e2)) || (uVar1 == 0xa4c5)) || (uVar1 == 0xd950)) {
    local_2 = 1;
  }
  return local_2;
}


// ===== FUN_fff9c2f9 @ fff9c2f9 (305 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c424) */
/* WARNING: Removing unreachable block (ram,0xfff9c32a) */
/* WARNING: Removing unreachable block (ram,0xfff9c331) */
/* WARNING: Removing unreachable block (ram,0xfff9c427) */

byte * FUN_fff9c2f9(byte *param_1,byte param_2)

{
  byte *pbVar1;
  
  DAT_00020888 = memch + param_2;
  DAT_0002088c = (uint)memch[param_2].freq_be[0] << 0x18 | (uint)memch[param_2].freq_be[1] << 0x10 |
                 (uint)memch[param_2].freq_be[2] << 8 | (uint)memch[param_2].freq_be[3];
  DAT_0002088c = FUN_fff9cba4(DAT_0002088c,param_2);
  FUN_fff9c95c(DAT_0002088c,&DAT_00001a5a);
  *param_1 = DAT_00001a5a >> 4 | 0x30;
  param_1[1] = DAT_00001a5a & 0x3f | 0x30;
  param_1[2] = 0x2e;
  param_1[3] = DAT_00001a5b >> 4 | 0x30;
  param_1[4] = DAT_00001a5b & 0x3f | 0x30;
  param_1[5] = DAT_00001a5c >> 4 | 0x30;
  param_1[6] = 0x2e;
  param_1[7] = DAT_00001a5c & 0x3f | 0x30;
  param_1[8] = DAT_00001a5d >> 4 | 0x30;
  param_1[9] = DAT_00001a5d & 0x3f | 0x30;
  pbVar1 = param_1;
  if (*param_1 == 0x30) {
    *param_1 = 0x20;
    pbVar1 = (byte *)(uint)param_1[1];
    if ((byte *)(uint)param_1[1] == (byte *)0x30) {
      param_1[1] = 0x20;
      param_1[2] = 0x20;
      pbVar1 = (byte *)(uint)param_1[3];
      if ((byte *)(uint)param_1[3] == (byte *)0x30) {
        param_1[3] = 0x20;
        return param_1;
      }
    }
  }
  return pbVar1;
}


// ===== displink_tx_20_status @ fff9c42a (42 bytes)

/* 0x20 (0x99 bytes) status, default frame, sent only when changed */

void displink_tx_20_status(void)

{
  byte bVar1;
  
  displink_build_20();
  bVar1 = displink_copy_if_changed(0x16a0,0x1456,0x98);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x99;
  displink_tx_start(0x99);
  return;
}


// ===== displink_build_20 @ fff9c454 (25 bytes)

void displink_build_20(void)

{
  mem_zero(0x98,0x16a0);
  DAT_000016a0 = 0x20;
  displink_build_status();
  return;
}


// ===== displink_tx_62 @ fff9c46d (45 bytes)

/* 0x62 (0x197 bytes) */

void displink_tx_62(void)

{
  byte bVar1;
  
  displink_build_62();
  bVar1 = displink_copy_if_changed(0x1741,0x1456,0x196);
  if (bVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x197;
  displink_tx_start(0x197);
  return;
}


// ===== displink_build_62 @ fff9c49a (187 bytes)

void displink_build_62(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  ushort uStack_4;
  byte bStack_1;
  
  mem_zero(0x98,0x16a0);
  mem_zero(0x24a,0x1741);
  DAT_00001741 = 0x62;
  displink_copy_status();
  DAT_000017d9 = PTR_g_ui_00025d38->align_cursor_row;
  uStack_4 = PTR_g_ui_00025d38->align_item - (ushort)PTR_g_ui_00025d38->align_cursor_row;
  if (PTR_g_ui_00025d38->align_item < (ushort)PTR_g_ui_00025d38->align_cursor_row) {
    uStack_4 = uStack_4 + 0x105;
  }
  for (bStack_1 = 0; bStack_1 < 9; bStack_1 = bStack_1 + 1) {
    pcVar2 = " 001 [GN] VDD MTR         002 [GN] FAN             003 [GN] REF FREQ        004 [GN] TX INH          005 [GN] --RESERVED--    006 [GN] --RESERVED--    007 [GN] --RESERVED--    008 [GN] DBG MODE ENABLE 009 [MT] PO MTR 100W POS 010 [MT] PO MTR  50W POS 011 [MT] PO MTR  20W POS 012 [MT] PO MTR  10W POS 013 [MT] PO MTR   5W POS 014 [MT] ALC MTR POS     015 [MT] VDD MTR POS     016 [MT] IDD MTR POS     017 [MT] SWR 1.5 MTR POS 018 [MT] SWR 2.0 MTR POS 019 [MT] SWR 3.0 MTR POS 020 [MT] --RESERVED--    021 [MT] --RESERVED--    022 [MT] --RESERVED--    023 [RX] RF-AGC  7       024 [RX] RF-AGC 14       025 [RX] RF-AGC 21       026 [RX] RF-AGC 28       027 [RX] RF-AGC 50       028 [RX] IF-AGC  7       029 [RX] IF-AGC 14       030 [RX] IF-AGC 21       031 [RX] IF-AGC 28       032 [RX] IF-AGC 50       033 [RX] S-MTR 0         034 [RX] S-MTR 2         035 [RX] S-MTR 5         036 [RX] S-MTR 7         037 [RX] S-MTR 9         038 [RX] S-MTR +10       039 [RX] S-MTR +20       040 [RX] S-MTR +30       041 [RX] S-MTR +40       042 [RX] S-MTR +50       043 [RX] S-MTR +60       044 [RX] --RESERVED--    045 [RX] --RESERVED--    046 [RX] FM SQL THW      047 [RX] FM SQL THN      048 [RX] FM SQL TI       049 [RX] SCOPE SDR REF   050 [TX] MF PREDR BIAS   051 [TX] MF DRIVE BIAS   052 [TX] MF FINAL BIAS   053 [TX] HF PREDR BIAS   054 [TX] HF DRIVE BIAS   055 [TX] HF FINAL BIAS   056 [TX] VHF PREDR BIAS  057 [TX] VHF DRIVE BIAS  058 [TX] VHF FINAL BIAS  059 [TX] I-ALC 1.8       060 [TX] I-ALC 3.5       061 [TX] I-ALC 7         062 [TX] I-ALC 10        063 [TX] I-ALC 14        064 [TX] I-ALC 18        065 [TX] I-ALC 21        066 [TX] I-ALC 24        067 [TX] I-ALC 28        068 [TX] I-ALC 50        069 [TX] I-ALC 70        070 [TX] 100W FALC 1.8   071 [TX] 100W MTR  1.8   072 [TX] 100W TXG  1.8   073 [TX]  50W FALC 1.8   074 [TX]  50W MTR  1.8   075 [TX]  50W TXG  1.8   076 [TX]  20W FALC 1.8   077 [TX]  20W MTR  1.8   078 [TX]  20W TXG  1.8   079 [TX]  10W FALC 1.8   080 [TX]  10W MTR  1.8   081 [TX]  10W TXG  1.8   082 [TX]   5W FALC 1.8..." /* TRUNCATED STRING LITERAL */
             + (uint)uStack_4 * 0x19;
    pcVar1 = &DAT_000017db + (uint)bStack_1 * 0x1c;
    for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    displink_62_value(uStack_4,(uint)bStack_1 * 0x1c + 0xb3);
    uStack_4 = uStack_4 + 1;
    if (0x104 < uStack_4) {
      uStack_4 = 0;
    }
  }
  return;
}

