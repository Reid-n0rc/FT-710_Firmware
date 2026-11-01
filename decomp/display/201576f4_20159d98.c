// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== scope_wf_bank_set @ 201576f4 (108 bytes)

/* (obj, 0/1/2): 0 clears waterfall bank 0 (0x33F40 B at obj+0x1B130) and selects it (0x20450280 =
   0), 1 selects bank 1, 2 clears both banks [fact] */

void scope_wf_bank_set(int param_1,int param_2)

{
  if (param_2 == 0) {
    __aeabi_memclr4(param_1 + 0x1b130,0x33f40);
    ring133_reset(param_1 + 0x82fb4);
    DAT_20450280 = 0;
  }
  else {
    if (param_2 != 1) {
      __aeabi_memclr4(param_1 + 0x1b130,0x67e80);
      ring133_reset(param_1 + 0x82fb4);
      ring133_reset(param_1 + 0x82fb0);
      return;
    }
    DAT_20450280 = 1;
  }
  return;
}


// ===== scope_obj_history_clear @ 20157778 (116 bytes)

/* (obj): scope record and hold copy to 0xFF, clears the history and 3D work buffers of the scope
   object [fact] */

void scope_obj_history_clear(int param_1)

{
  __aeabi_memset(param_1 + 0x9c7f,0x352,0xff);
  __aeabi_memset(param_1 + 0x9fd1,0x352,0xff);
  __aeabi_memclr4(param_1 + 0x10abc,0x6798);
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
  __aeabi_memclr(param_1 + 0xa323,24000);
  __aeabi_memclr4(param_1 + 0x17258,0x3ed4);
  __aeabi_memclr4_veneer(param_1 + 0x100e4,0x9d8);
  return;
}


// ===== copy_inverted_words_b @ 201577f8 (36 bytes)

/* (this, dst, src, n): n/4 words dst = ~src (second copy of copy_inverted_words);
   scope_history_push uses it [fact] */

void copy_inverted_words_b(undefined4 param_1,uint *param_2,uint *param_3,uint param_4)

{
  for (param_4 = param_4 >> 2; param_4 != 0; param_4 = param_4 - 1) {
    *param_2 = ~*param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== scope_obj_reset_bank0 @ 201578c8 (40 bytes)

/* (obj): clears +0x9C7E, scope_obj_history_clear, scope_wf_bank_set(0) [fact] */

void scope_obj_reset_bank0(int param_1)

{
  *(undefined1 *)(param_1 + 0x9c7e) = 0;
  scope_obj_history_clear();
                    /* 0 clears waterfall bank 0 [doc] */
  scope_wf_bank_set(param_1,0);
  return;
}


// ===== scope_obj_levels_get @ 20157c50 (224 bytes)

/* (obj, mode, out, ...): per-column levels for mode 8 / 9 / other from the live record or, while
   SPEED STOP (0x20800498), from the hold copy, scaled by the 3D sub-object of the mode (method
   behind scope_levels_get) [fact] */

void scope_obj_levels_get(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = param_1 + 0x9c98;
  if (DAT_20800498 == '\0') {
    memcpy(param_1 + 0x9fd1,param_1 + 0x9c7f,0x352,param_4,param_4);
  }
  else {
    if (param_2 != 8 && param_2 != 9) goto LAB_20157cc4;
    iVar1 = param_1 + 0x9fea;
  }
  if (param_2 == 8) {
    FUN_201633a0(param_1,param_3,iVar1,param_4);
    FUN_20164674(0x20470330);
    return;
  }
  if (param_2 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_3,iVar1,param_4);
    FUN_20164654(0x20473b7c);
    return;
  }
LAB_20157cc4:
  FUN_201633a0(param_1 + 0x2d00,param_3,iVar1,param_4);
  FUN_2016466c(0x204702a4);
  return;
}


// ===== scope_obj_wf_add_row @ 20157d3c (552 bytes)

/* (obj, record, mode): adds a waterfall row: takes the newest history rows (ring index
   obj+0x17254), adds the level offset to each point (clamp_add_u8, 0..255) into the current
   waterfall bank (gui.md: scope_wf_add_row) [fact for the calls] */

void scope_obj_wf_add_row(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  
  if ((((DAT_20800498 == '\0') && (*(char *)(param_1 + 0x9c7c) == '\0')) &&
      (*(char *)(param_1 + 0x9c7d) == '\0')) && (*(char *)(param_1 + 0x9c7e) == '\0')) {
    iVar4 = ring30_offset(param_1 + 0x17254,0xffffffff);
    iVar9 = param_1 + iVar4 * 800 + 0x10abc;
    iVar4 = param_1 + 0x1b12c;
    iVar5 = ring20_offset(iVar4,0);
    memcpy(iVar9,param_1 + iVar5 * 800 + 0x17258,800);
    iVar5 = 1;
    if (1 < param_2) {
      do {
        iVar6 = ring20_offset(iVar4,-iVar5);
        iVar7 = 0;
        do {
          bVar3 = *(byte *)(param_1 + iVar6 * 800 + 0x17258 + iVar7);
          if (*(byte *)(iVar9 + iVar7) < bVar3) {
            *(byte *)(iVar9 + iVar7) = bVar3;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 800);
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_2);
    }
                    /* returns idx and advances it [doc] */
    iVar5 = ring133_advance(param_1 + 0x82fb4);
    puVar10 = &DAT_20450278;
    if (DAT_20450280 == 1) {
      iVar5 = ring133_advance(param_1 + 0x82fb0);
    }
    if (param_3 != 0) {
      puVar10 = (undefined4 *)0x0;
    }
    iVar5 = param_1 + DAT_20450280 * 0x33f40 + iVar5 * 0x640 + 0x1b130;
    if (param_3 != 0) {
      do {
        iVar7 = clamp_add_u8(*(undefined1 *)(iVar9 + (int)puVar10),param_3);
        iVar6 = (int)puVar10 * 2;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        *(undefined2 *)(iVar5 + iVar6) = *(undefined2 *)(param_1 + iVar7 * 2 + 0x2e06);
      } while ((int)puVar10 < 800);
    }
    else {
      iVar6 = 0;
      do {
        pbVar2 = (byte *)(iVar9 + iVar6);
        iVar7 = iVar6 * 2;
        iVar6 = iVar6 + 1;
        *(undefined2 *)(iVar5 + iVar7) = *(undefined2 *)(param_1 + (uint)*pbVar2 * 2 + 0x2e06);
      } while (iVar6 < 800);
    }
    iVar6 = 0;
    piVar11 = (int *)(param_1 + 0x1b0d8);
    if (0 < *piVar11) {
      do {
        iVar7 = ring20_offset(iVar4,-iVar6);
        uVar8 = (uint)*(ushort *)(piVar11 + iVar7 + 1);
        if (uVar8 < *(ushort *)((int)piVar11 + iVar7 * 4 + 6) + uVar8) {
          do {
            iVar1 = uVar8 * 2;
            pbVar2 = (byte *)(iVar9 + uVar8);
            uVar8 = uVar8 + 1;
            *(undefined2 *)(iVar5 + iVar1) = *(undefined2 *)(param_1 + (uint)*pbVar2 * 2 + 0x3008);
          } while ((int)uVar8 <
                   (int)((uint)*(ushort *)(piVar11 + iVar7 + 1) +
                        (uint)*(ushort *)((int)piVar11 + iVar7 * 4 + 6)));
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar11);
    }
  }
  return;
}


// ===== FUN_20157f8c @ 20157f8c (124 bytes)

void FUN_20157f8c(int param_1)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x9c7c) == '\0') && (*(char *)(param_1 + 0x9c7d) == '\0')) &&
     (*(char *)(param_1 + 0x9c7e) == '\0')) {
                    /* returns idx and advances it [doc] */
    ring20_advance();
    iVar1 = ring20_offset(param_1 + 0x1b12c,0);
                    /* n/4 words dst = ~src [doc] */
    copy_inverted_words_b(param_1,param_1 + iVar1 * 800 + 0x17258,param_1 + 0x9c98,800);
    return;
  }
  return;
}


// ===== FUN_201584f8 @ 201584f8 (88 bytes)

void FUN_201584f8(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0x2e00) = 0xff38;
    *(undefined2 *)(param_1 + 0x3006) = 0xff38;
    *(undefined2 *)(param_1 + 0x3208) = 0xff38;
  }
  else {
    *(undefined2 *)(param_1 + 0x2e00) = 0xaf4c;
    *(undefined2 *)(param_1 + 0x3006) = 0xaf4c;
    *(undefined2 *)(param_1 + 0x3208) = 0xaf4c;
  }
  FUN_20157634(param_1 + 0x2d00,*(undefined1 *)(param_1 + 0x2e04),param_1 + 0x2e00);
  return;
}


// ===== FUN_20158544 @ 20158544 (136 bytes)

void FUN_20158544(int param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_2 == 0) {
    puVar1 = &DAT_204282a0;
  }
  else {
    puVar1 = &DAT_2042829c;
  }
  *(undefined2 *)(param_1 + 0x2e02) = *puVar1;
  iVar2 = 0;
  do {
    FUN_20157634(param_1 + iVar2 * 0x100,*(undefined2 *)(DAT_20450278 + iVar2 * 2),param_1 + 0x2e02)
    ;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1e);
  iVar2 = 0;
  do {
    FUN_20157634(param_1 + iVar2 * 0x100 + 0x1e00,*(undefined2 *)(DAT_2045027c + iVar2 * 2),
                 param_1 + 0x2e02);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xf);
  return;
}


// ===== scope_obj_reset_bank1 @ 20158568 (40 bytes)

/* (obj): clears +0x9C7E, scope_obj_history_clear, scope_wf_bank_set(1) [fact] */

void scope_obj_reset_bank1(int param_1)

{
  *(undefined1 *)(param_1 + 0x9c7e) = 0;
  scope_obj_history_clear();
                    /* 0 clears waterfall bank 0 [doc] */
  scope_wf_bank_set(param_1,1);
  return;
}


// ===== scope_obj_indices_clear @ 20158590 (104 bytes)

/* (obj): zeroes the four ring indices +0x17254, +0x1B12C, +0x82FB0, +0x82FB4 [fact] */

int scope_obj_indices_clear(int param_1)

{
  *(undefined4 *)(param_1 + 0x17254) = 0;
  *(undefined4 *)(param_1 + 0x1b12c) = 0;
  *(undefined4 *)(param_1 + 0x82fb0) = 0;
  *(undefined4 *)(param_1 + 0x82fb4) = 0;
  return param_1;
}


// ===== msgbuf_init @ 20158618 (24 bytes)

/* (obj): clears the two u16 indices +4/+6 and the 0x80-byte buffer at +8; used by the same TX
   objects [fact] */

void msgbuf_init(int param_1)

{
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  __aeabi_memclr4_veneer(param_1 + 8,0x80);
  return;
}


// ===== mainlink_tx_alloc @ 20158630 (12 bytes)

/* gets a free 0x408-byte buffer */

uint mainlink_tx_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = txpool_next_slot(param_1 + 0x811c);
  return uVar1;
}


// ===== mainlink_tx_init @ 2015863c (96 bytes)

/* 32 x 0x408 B buffer pool + mailbox */

void mainlink_tx_init(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x18) = param_2;
                    /* Creates the pool mutex [doc] */
  txpool_init_mutex();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x408;
    msgbuf_init(iVar3 + 0x1c);
    txpool_set_slot(param_1 + 0x811c,uVar2 & 0xffff,iVar3 + 0x1c);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
                    /* itron_acre_mbx with a zeroed T_CMBX [doc] */
  uVar1 = os_mbx_create_fifo(param_1);
  *(undefined4 *)(param_1 + 0x81a4) = uVar1;
  return;
}


// ===== mainlink_tx_clear_stats @ 2015869c (16 bytes)

void mainlink_tx_clear_stats(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ===== task_mainlink_tx @ 201586ac (152 bytes)

/* task "uart" pri 4: mailbox -> scif_write(buf+8, len), then mainlink_trace */

void task_mainlink_tx(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  mainlink_tx_clear_stats(param_1);
  do {
    do {
      itron_trcv_mbx(*(undefined4 *)(param_1 + 0x81a4),local_8,0xffffffff);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();
    } while (iVar1 == 0);
    while( true ) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x24))
                        (*(int **)(param_1 + 0x18),local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      if (iVar1 != 0) break;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      itron_dly_tsk(1);
    }
    mainlink_trace(local_8[0] + 8,(uint)*(ushort *)(local_8[0] + 6));
  } while( true );
}


// ===== mainlink_tx_post @ 20158744 (100 bytes)

/* waits for the 3 ms pacing counter, posts to the TX mailbox, re-arms cmd_interval */

void mainlink_tx_post(int param_1,uint param_2)

{
  while (g_ml.pace_count != 0) {
    itron_dly_tsk(1);
  }
  os_mbx_send(param_1,*(undefined4 *)(param_1 + 0x81a4),param_2);
  itron_twai_sem(g_ml.pace_sem,0xffffffff);
  g_ml.pace_count = 3;
  itron_sig_sem(g_ml.pace_sem);
  return;
}


// ===== mainlink_tx_ctor @ 201587ac (32 bytes)

/* vtbl 0x20427FAC */

int mainlink_tx_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fac;
  iVar1 = FUN_20162c18((int)param_1 + 0x811c);
  return iVar1 + -0x811c;
}


// ===== FUN_201587d0 @ 201587d0 (44 bytes)

void FUN_201587d0(int param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


// ===== scope3d_obj_init @ 201587fc (60 bytes)

/* (obj): resets the three sub-objects (+0x10, +0x9C, +0x38E8) and byte 0; used for the 3D objects
   0x20470294 / 0x20474C68 by scope_objects_init [fact] */

void scope3d_obj_init(undefined1 *param_1)

{
  FUN_20163d44(param_1 + 0x10,0);
  FUN_20163f14(param_1 + 0x9c,0);
  FUN_20163ae0(param_1 + 0x38e8,0);
  *param_1 = 0;
  return;
}


// ===== FUN_20158838 @ 20158838 (16 bytes)

void FUN_20158838(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar2;
  undefined *puVar3;
  
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  cVar1 = *param_1;
  puVar3 = (undefined *)0x3ff00000;
  uVar2 = 0;
  if (cVar1 == '\x01') {
    uVar2 = 0x9999999a;
    puVar3 = &DAT_3fe99999;
  }
  else if (cVar1 == '\x02') {
    uVar2 = 0x33333333;
    puVar3 = &DAT_3fe33333;
  }
  else if (cVar1 == '\x03') {
    uVar2 = 0x9999999a;
    puVar3 = (undefined *)0x3fd99999;
  }
  else if (cVar1 == '\x04') {
    uVar2 = 0x9999999a;
    puVar3 = (undefined *)0x3fc99999;
  }
  *param_1 = cVar1;
  FUN_20163ca4(param_1 + 0x10,cVar1,uVar2,puVar3,*(undefined4 *)(param_1 + 4));
  FUN_20163e74(param_1 + 0x9c,extraout_r1,uVar2,puVar3,*(undefined4 *)(param_1 + 8));
  FUN_20163a40(param_1 + 0x38e8,extraout_r1_00,uVar2,puVar3,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ===== FUN_20158848 @ 20158848 (180 bytes)

void FUN_20158848(undefined1 *param_1,int param_2)

{
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)0x3ff00000;
  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = 0x9999999a;
    puVar2 = &DAT_3fe99999;
  }
  else if (param_2 == 2) {
    uVar1 = 0x33333333;
    puVar2 = &DAT_3fe33333;
  }
  else if (param_2 == 3) {
    uVar1 = 0x9999999a;
    puVar2 = (undefined *)0x3fd99999;
  }
  else if (param_2 == 4) {
    uVar1 = 0x9999999a;
    puVar2 = (undefined *)0x3fc99999;
  }
  *param_1 = (char)param_2;
  FUN_20163ca4(param_1 + 0x10,param_2,uVar1,puVar2,*(undefined4 *)(param_1 + 4));
  FUN_20163e74(param_1 + 0x9c,extraout_r1,uVar1,puVar2,*(undefined4 *)(param_1 + 8));
  FUN_20163a40(param_1 + 0x38e8,extraout_r1_00,uVar1,puVar2,*(undefined4 *)(param_1 + 0xc));
  return;
}


// ===== FUN_20158914 @ 20158914 (12 bytes)

void FUN_20158914(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  return;
}


// ===== FUN_20158920 @ 20158920 (16 bytes)

void FUN_20158920(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ===== task_uart4_rx @ 20158930 (180 bytes)

/* passes raw bytes to FUN_20131154 */

void task_uart4_rx(int param_1)

{
  void *itron_twai_flg_ret;
  undefined4 uVar1;
  uint local_114;
  undefined1 auStack_110 [260];
  
  __aeabi_memclr4(auStack_110,0x100);
  FUN_20158920(param_1);
  while( true ) {
    while (itron_twai_flg_ret = itron_twai_flg(*(uint *)(param_1 + 0x24),0xc001,5,&local_114,-1),
          itron_twai_flg_ret == (void *)0xffffffce) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    }
    if (itron_twai_flg_ret != (void *)0x0) break;
    if (((local_114 & 0xc000) == 0) && ((local_114 & 1) != 0)) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))
                        (*(int **)(param_1 + 0x10),auStack_110,0x100);
      decode_text_rx(auStack_110,uVar1);
    }
  }
  return;
}


// ===== FUN_201589e4 @ 201589e4 (12 bytes)

void FUN_201589e4(undefined4 *param_1)

{
  *param_1 = &DAT_20427fb8;
  return;
}


// ===== uart4_tx_alloc @ 201589f4 (12 bytes)

uint uart4_tx_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = txpool_next_slot(param_1 + 0x111c);
  return uVar1;
}


// ===== uart4_tx_init @ 20158a00 (96 bytes)

void uart4_tx_init(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x18) = param_2;
                    /* Creates the pool mutex [doc] */
  txpool_init_mutex();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x88;
    msgbuf_init(iVar3 + 0x1c);
    txpool_set_slot(param_1 + 0x111c,uVar2 & 0xffff,iVar3 + 0x1c);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
                    /* itron_acre_mbx with a zeroed T_CMBX [doc] */
  uVar1 = os_mbx_create_fifo(param_1);
  *(undefined4 *)(param_1 + 0x11a4) = uVar1;
  return;
}


// ===== FUN_20158a60 @ 20158a60 (16 bytes)

void FUN_20158a60(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ===== task_uart4_tx @ 20158a70 (108 bytes)

void task_uart4_tx(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  FUN_20158a60();
  do {
    itron_trcv_mbx(*(undefined4 *)(param_1 + 0x11a4),local_8,0xffffffff);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    while( true ) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x24))
                        (*(int **)(param_1 + 0x18),local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      if (iVar1 != 0) break;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      itron_dly_tsk(1);
    }
  } while( true );
}


// ===== uart4_tx_post @ 20158adc (16 bytes)

void uart4_tx_post(int param_1,uint param_2)

{
  os_mbx_send(param_1,*(undefined4 *)(param_1 + 0x11a4),param_2);
  return;
}


// ===== FUN_20158aec @ 20158aec (32 bytes)

int FUN_20158aec(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20427fc4;
  iVar1 = FUN_20162c18(param_1 + 0x447);
  return iVar1 + -0x111c;
}


// ===== mainlink_obj_run @ 20158b10 (240 bytes)

/* task "uart" pri 7: binds SCIF5, starts the 3 sub-tasks, opens 345600 baud 8N2 */

void mainlink_obj_run(int param_1)

{
  uint uVar1;
  uint itron_acre_tsk_ret;
  uint itron_acre_tsk_ret_2;
  uint uVar2;
  
  uVar1 = itron_acre_tsk(0,(byte *)&ctsk_uart_5938);
  if (((0 < (int)uVar1) &&
      (itron_acre_tsk_ret = itron_acre_tsk(0,(byte *)&ctsk_uart_591c), 0 < (int)itron_acre_tsk_ret))
     && (itron_acre_tsk_ret_2 = itron_acre_tsk(0,(byte *)&ctsk_uart_5900),
        0 < (int)itron_acre_tsk_ret_2)) {
    uVar2 = param_1 + 0x8218;
                    /* 32 x 0x408 B buffer pool + mailbox [doc, inference] */
    mainlink_tx_init(uVar2,*(uint *)(param_1 + 0x10));
                    /* 32 x 0x408 B pool + mailbox [doc, inference] */
    mainlink_disp_init(param_1 + 0x58,uVar2);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x14);
    mainlink_rx_bind(param_1 + 0x18,*(uint *)(param_1 + 0x10),uVar2,param_1 + 0x58);
    uVar1 = itron_sta_tsk(uVar1,uVar2);
    if (((uVar1 == 0) && (uVar1 = itron_sta_tsk(itron_acre_tsk_ret,param_1 + 0x58), uVar1 == 0)) &&
       (uVar1 = itron_sta_tsk(itron_acre_tsk_ret_2,param_1 + 0x18), uVar1 == 0)) {
      (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x54600,8,0);
      itron_tslp_tsk(0xffffffff);
      return;
    }
  }
  return;
}


// ===== mainlink_obj_ctor @ 20158c10 (48 bytes)

/* builds RX (+0x18), dispatcher (+0x58) and TX (+0x8218) sub-objects */

int mainlink_obj_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fd0;
  iVar1 = mainlink_rx_ctor((int)param_1 + 0x18);
  iVar1 = mainlink_disp_ctor((void *)(iVar1 + 0x40));
  iVar1 = mainlink_tx_ctor((void *)(iVar1 + 0x81c0));
  return iVar1 + -0x8218;
}


// ===== uart4_obj_run @ 20158c44 (548 bytes)

/* 38400 baud; probes with 0xF0 bytes, then sends 1E 00 31 / 1F 00 32 */

void uart4_obj_run(int param_1)

{
  int iVar1;
  uint uVar2;
  uint itron_acre_tsk_ret;
  uint itron_acre_tsk_ret_2;
  uint uVar3;
  int i;
  undefined4 local_20;
  
  local_20 = 1;
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0x9600,8,0);
  if (g_bootinfo.bank == 0xbbbb) {
    itron_tslp_tsk(0xffffffff);
  }
  if (DAT_2045001d == '\x01') {
    DAT_2045001d = '\x02';
    itron_tslp_tsk(0xffffffff);
  }
  i = 5;
  do {
    local_20 = 0xf0;
    (**(code **)(**(int **)(param_1 + 0x10) + 0x24))(*(int **)(param_1 + 0x10),&local_20,1);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x18))
                      (*(int **)(param_1 + 0x10),&DAT_2045001e,2,100);
    if (iVar1 != -1) {
      i = i + -1;
    }
    if (DAT_2045001d == '\x01') {
      DAT_2045001d = '\x02';
      itron_tslp_tsk(0xffffffff);
    }
  } while (i != 0);
  DAT_2045001c = 1;
  uVar2 = itron_acre_tsk(0,(byte *)&ctsk_uart4_583c);
  if (((0 < (int)uVar2) &&
      (itron_acre_tsk_ret = itron_acre_tsk(0,(byte *)&ctsk_uart4_5820), 0 < (int)itron_acre_tsk_ret)
      ) && (itron_acre_tsk_ret_2 = itron_acre_tsk(0,(byte *)&ctsk_uart4_5804),
           0 < (int)itron_acre_tsk_ret_2)) {
    uVar3 = param_1 + 0x938;
    uart4_tx_init(uVar3,*(uint *)(param_1 + 0x10));
    FUN_2015ff94(param_1 + 0x50,uVar3);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x14);
    FUN_20158914(param_1 + 0x18,*(undefined4 *)(param_1 + 0x10),uVar3,param_1 + 0x50);
    uVar2 = itron_sta_tsk(uVar2,uVar3);
    if (((uVar2 == 0) && (uVar2 = itron_sta_tsk(itron_acre_tsk_ret,param_1 + 0x50), uVar2 == 0)) &&
       (uVar2 = itron_sta_tsk(itron_acre_tsk_ret_2,param_1 + 0x18), uVar2 == 0)) {
      itron_dly_tsk(10);
      uVar2 = uart4_tx_alloc(uVar3);
      *(undefined2 *)(uVar2 + 4) = 0xaa;
      *(undefined2 *)(uVar2 + 6) = 3;
      *(undefined1 *)(uVar2 + 8) = 0x1e;
      *(undefined1 *)(uVar2 + 9) = 0;
      *(undefined1 *)(uVar2 + 10) = 0x31;
      uart4_tx_post(uVar3,uVar2);
      itron_dly_tsk(10);
      uVar2 = uart4_tx_alloc(uVar3);
      *(undefined2 *)(uVar2 + 4) = 0xaa;
      *(undefined2 *)(uVar2 + 6) = 3;
      *(undefined1 *)(uVar2 + 8) = 0x1f;
      *(undefined1 *)(uVar2 + 9) = 0;
      *(undefined1 *)(uVar2 + 10) = 0x32;
      uart4_tx_post(uVar3,uVar2);
      itron_tslp_tsk(0xffffffff);
      return;
    }
  }
  return;
}


// ===== uart4_obj_ctor @ 20158e8c (48 bytes)

/* vtbl 0x20427FE4 */

int uart4_obj_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20427fe4;
  iVar1 = FUN_201589e4((int)param_1 + 0x18);
  iVar1 = FUN_20160018(iVar1 + 0x38);
  iVar1 = FUN_20158aec(iVar1 + 0x8e8);
  return iVar1 + -0x938;
}


// ===== mainlink_send_ui_e2 @ 20158ec0 (96 bytes)

/* 0xE2 UI frame to MAIN */

void mainlink_send_ui_e2(void *param_1,uint param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0xe2;
  uStack_14 = 0;
                    /* Copies 5 bytes [doc] */
  copy5((int)&local_18 + 1,param_2);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_18,6);
  }
  copy5((int)param_1 + 0x22,param_2);
  *(undefined1 *)param_1 = (undefined1)local_18;
  return;
}


// ===== mainlink_send_ui_c3 @ 20158f28 (120 bytes)

/* 0xC3 UI state frame to MAIN */

void mainlink_send_ui_c3(void *param_1,uint param_2)

{
  undefined4 local_38;
  undefined1 auStack_34 [36];
  
  __aeabi_memclr4(auStack_34,0x1e);
  local_38 = 0xc3;
  memcpy((int)&local_38 + 1,param_2,0x21);
  if (DAT_20800494 != '\0') {
    mainlink_queue_frame(&local_38,0x22);
  }
  memcpy((int)param_1 + 1,param_2,0x21);
  *(undefined1 *)param_1 = (undefined1)local_38;
  return;
}


// ===== FUN_20158fa8 @ 20158fa8 (40 bytes)

uint FUN_20158fa8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xb;
  param_1 = param_1 >> 4;
  uVar2 = 3;
  do {
    if ((param_1 & 1) != 0) {
      uVar1 = uVar2 & 0xff;
    }
    uVar2 = uVar2 - 1;
    param_1 = param_1 >> 1;
  } while (-1 < (int)uVar2);
  return uVar1;
}


// ===== touch_wait_tap @ 20158fd0 (132 bytes)

/* Waits for a touch: polls pointer_get_event / touch_cal_apply every tick until a press (event 2 or
   4), a release (5 or 6) or the power-key flag 0x20800493; fwupdate_screen and
   fwupdate_insert_sd_screen wait with it [fact] */

void touch_wait_tap(void)

{
  char local_20 [12];
  short local_14 [2];
  short local_10 [2];
  
  pointer_touch_poll();
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    gui_update_layers();
    local_14[0] = 0;
    local_10[0] = 0;
    pointer_get_event(local_20,1);
    touch_cal_apply((int)(short)local_20._4_4_,(int)(short)local_20._8_4_,local_14,local_10);
    if (local_20[0] == '\x02' || local_20[0] == '\x04') break;
    if (local_20[0] == '\x05' || local_20[0] == '\x06') {
      return;
    }
    itron_tslp_tsk(0xffffffff);
  }
  return;
}


// ===== bootloader_entry_screen @ 20159058 (232 bytes)

/* Update-UI method (thunk 0x201322E4): clears both layers; boot-info word +8 != 2 -> "FIRMWARE BOOT
   ERROR" forever, else bootloader_screen (update.md) [fact] */

void bootloader_entry_screen(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fb_get_layer_addr(DAT_208085b8);
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  gui_update_layers();
  if (*(int *)(param_2 + 8) != 2) {
    uVar2 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect(uVar2,0,0,800,0x1e0);
    gui_draw_text_centered(uVar2,0x204280a8,100,400,0xc,0x208038c0);
    do {
                    /* Radio off from the GUI side [doc] */
      if (DAT_20800493 != '\0') {
        display_power_down();
      }
      gui_update_layers();
      fb_get_layer_addr(DAT_208085bc);
      itron_tslp_tsk(0xffffffff);
    } while( true );
  }
  bootloader_screen(param_1,param_2);
  return;
}


// ===== update_error_screen @ 20159158 (428 bytes)

/* "UPDATE ERROR", waits for a touch */

void update_error_screen(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  short sVar8;
  short sVar9;
  undefined1 auStack_74 [68];
  char local_30 [16];
  
  __aeabi_memcpy4(auStack_74,"UPDATE ERROR",0x44);
  confirm_dialog_draw(1,1,1,0,0x105,0xbf,(int)auStack_74);
  uVar6 = **(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4) + 0x119 & 0xffff;
  uVar5 = (*(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4))[1] + 0x11d & 0xffff;
  pointer_touch_poll();
  do {
    cursor_window_update();
                    /* Radio off from the GUI side [doc] */
    if (DAT_20800493 != '\0') {
      display_power_down();
    }
    uVar4 = 0;
    uVar3 = 0;
    pointer_get_event(local_30,1);
    touch_cal_apply((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,(short *)&stack0xffffff80,
                    (short *)&stack0xffffff84);
    sVar9 = (short)uVar3;
    sVar8 = (short)uVar4;
    if ((local_30[0] == '\x02' || local_30[0] == '\x04') ||
       (local_30[0] == '\x05' || local_30[0] == '\x06')) {
      mouse_cursor_set_pos(uVar4 & 0xffff,uVar3 & 0xffff);
      uVar3 = (uint)sVar8;
      bVar7 = SBORROW4(uVar3,0x119);
      iVar1 = uVar3 - 0x119;
      uVar4 = 0x119;
      if (0x118 < (int)uVar3) {
        bVar7 = SBORROW4(uVar6,uVar3);
        iVar1 = uVar6 - uVar3;
        uVar4 = uVar6;
      }
      if (((uVar3 != uVar4 && iVar1 < 0 == bVar7) && (0x11c < sVar9)) && ((int)sVar9 < (int)uVar5))
      {
        return;
      }
    }
    pointer_get_event(local_30,0);
    uVar4 = (uint)(short)local_30._4_4_;
    uVar3 = (uint)(short)local_30._8_4_;
    if ((DAT_20800494 != '\0') &&
       ((local_30[0] == '\x02' || local_30[0] == '\x04' ||
        (local_30[0] == '\x05' || local_30[0] == '\x06')))) {
      bVar7 = SBORROW4(uVar4,0x119);
      iVar1 = uVar4 - 0x119;
      uVar2 = 0x119;
      if (0x118 < (int)uVar4) {
        bVar7 = SBORROW4(uVar6,uVar4);
        iVar1 = uVar6 - uVar4;
        uVar2 = uVar6;
      }
      if (uVar4 != uVar2 && iVar1 < 0 == bVar7) {
        bVar7 = SBORROW4(uVar3,0x11d);
        iVar1 = uVar3 - 0x11d;
        uVar4 = 0x11d;
        if (0x11c < (int)uVar3) {
          bVar7 = SBORROW4(uVar5,uVar3);
          iVar1 = uVar5 - uVar3;
          uVar4 = uVar5;
        }
        if (uVar3 != uVar4 && iVar1 < 0 == bVar7) {
          return;
        }
      }
    }
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
  } while( true );
}


// ===== pointer_touch_poll @ 20159320 (28 bytes)

/* pointer_get_event(evt, 1 = touch) with the event dropped (clears a pending touch before a dialog)
   [inference] */

void pointer_touch_poll(void)

{
  undefined1 auStack_10 [12];
  
  pointer_get_event(auStack_10,1);
  return;
}


// ===== FUN_2015933c @ 2015933c (76 bytes)

void FUN_2015933c(void)

{
  undefined1 auStack_4c [68];
  
  __aeabi_memcpy4(auStack_4c,"INSERT FIRMWARE",0x44);
  confirm_dialog_draw(1,1,3,0,0xe6,0xb7,(int)auStack_4c);
  return;
}


// ===== bootloader_screen @ 2015938c (552 bytes)

/* YAESU FT-710 BOOT LOADER V01-02 */

void bootloader_screen(undefined4 param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_20808540;
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  FUN_2010da68();
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,8,400,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,iVar3,8,400,0xc,0x20803a40);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uVar2,(&DAT_2080856c)[uVar4],uVar4 * 0x20 + 100,400,0xc,0x208038c0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  gui_update_layers();
  DAT_20808532 = 1;
  uVar2 = bootloader_unlock_wait();
  if (DAT_20800493 == '\0') {
    bVar1 = usbkbd_last_key();
    fwupdate_set_hotkey(bVar1);
    iVar3 = sd_state_bit7();
    if (iVar3 == 0) {
      uVar4 = fb_get_layer_addr(DAT_208085bc);
      fb_clear_rect(uVar4,100,0,800,0x17c);
      gui_draw_text_centered(uVar4,DAT_2080856c,100,400,0xc,0x208038c0);
      gui_update_layers();
    }
    iVar3 = sd_state_bit7();
    while (iVar3 == 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      itron_tslp_tsk(0xffffffff);
      iVar3 = sd_state_bit7();
    }
    if (uVar2 != 0) {
      *param_2 = 0xbbbb;
      fwupdate_ui_run(param_1,"YAESU FT-710 BOOT LOADER V01-02");
      return;
    }
    param_2[2] = 1;
    fwupdate_ui_run(param_1,DAT_20808540);
    DAT_20800496 = 0;
    DAT_20800495 = 1;
  }
  return;
}


// ===== fw_installed_versions_set @ 201595f0 (64 bytes)

/* installed versions from the MAIN 0x60 frame (this = update-UI object, r1 = frame) */

void fw_installed_versions_set(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  
  uVar1 = be16_load(param_2);
  *param_1 = uVar1;
  uVar1 = be16_load(param_2 + 2);
  param_1[1] = uVar1;
  uVar1 = be16_load(param_2 + 4);
  param_1[2] = uVar1;
  uVar1 = be16_load(param_2 + 10);
  param_1[3] = uVar1;
  return;
}


// ===== pointer_idle_loop @ 20159630 (220 bytes)

/* Endless loop: cursor_window_update, pointer events with touch_cal_apply to move the mouse cursor,
   gui_update_layers, 1-tick sleeps; fwupdate_ui_run ends in it [fact] */

void pointer_idle_loop(void)

{
  char local_28 [12];
  ushort local_1c [2];
  ushort local_18 [4];
  
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    cursor_window_update();
    local_1c[0] = 0;
    local_18[0] = 0;
    pointer_get_event(local_28,1);
    touch_cal_apply((int)(short)local_28._4_4_,(int)(short)local_28._8_4_,(short *)local_1c,
                    (short *)local_18);
    if ((local_28[0] == '\x02' || local_28[0] == '\x04') ||
       (local_28[0] == '\x05' || local_28[0] == '\x06')) {
      mouse_cursor_set_pos((uint)local_1c[0],(uint)local_18[0]);
      return;
    }
    pointer_get_event(local_28,0);
    if (local_28[0] == '\x02' || local_28[0] == '\x04') {
      return;
    }
    if (local_28[0] == '\x05' || local_28[0] == '\x06') break;
    if (DAT_20808533 != '\0') {
      DAT_20808533 = 0;
      return;
    }
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
  }
  return;
}


// ===== fwupdate_screen @ 20159714 (1376 bytes)

/* MAIN/DISPLAY FIRMWARE UPDATE, STEP 1 of 2 (this = update-UI object) */

void fwupdate_screen(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_288 [288];
  undefined1 auStack_168 [72];
  char cStack_120;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  
  uStack_28 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect(uStack_28,0x132,0,800,0xae);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uStack_28,(&DAT_20808564)[uVar4],uVar4 * 0x20 + 0x132,400,0xf,0x20800b1c)
    ;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  gui_update_layers();
  touch_wait_tap();
  bVar1 = usbkbd_last_key();
  fwupdate_set_hotkey(bVar1);
  do {
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect(uStack_28,0x132,0,800,0xae);
    gui_draw_text_centered(uStack_28,DAT_20808538,0x132,400,0xf,0x20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    fwfile_check_versions(param_1 + 8);
    *(undefined4 *)(param_1 + 0x3c) = 1;
    *(undefined4 *)(param_1 + 0x84) = 1;
    fwfile_status_text(param_1 + 8,1);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    gui_update_layers();
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit7();
    if (iVar3 != 0) {
      if ((*(char *)(param_1 + 8) == '\x01') && (*(char *)(param_1 + 0x50) == '\x01')) break;
      fb_clear_rect(uStack_28,0x132,0,800,0xae);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      if (*(char *)(param_1 + 8) == '\x01') {
        sprintf(&uStack_48,"[ OK ]");
      }
      else {
        sprintf(&uStack_48,"[ NG : %s ]",param_1 + 0x1d);
      }
      gui_draw_text_words(uStack_28,0x204280ef,0x132,0x9d,0xf,0x20800b1c);
      gui_draw_text_words(uStack_28,(uint)&uStack_48,0x132,0x1a4,0xf,0x20800b1c);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      if (*(char *)(param_1 + 0x50) == '\x01') {
        sprintf(&uStack_48,"[ OK ] %s",param_1 + 0x8c);
      }
      else {
        sprintf(&uStack_48,"[ NG : %s ]",param_1 + 0x65);
      }
      gui_draw_text_words(uStack_28,0x2042810c,0x152,0x9d,0xf,0x20800b1c);
      gui_draw_text_words(uStack_28,(uint)&uStack_48,0x152,0x1a4,0xf,0x20800b1c);
      gui_draw_text_centered(uStack_28,DAT_2080853c,0x192,400,0xf,0x20800b1c);
    }
    gui_update_layers();
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit6();
    while (iVar3 != 0) {
      if (DAT_20800493 != '\0') {
        display_power_down();
      }
      itron_tslp_tsk(0xffffffff);
      gui_update_layers();
      uStack_28 = fb_get_layer_addr(DAT_208085bc);
      iVar3 = sd_state_bit6();
    }
    fb_clear_rect(uStack_28,0x132,0,800,0xae);
    gui_draw_text_centered(uStack_28,DAT_2080856c,0x132,400,0xf,0x20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit7();
    while (iVar3 == 0) {
      if (DAT_20800493 != '\0') {
        display_power_down();
      }
      itron_tslp_tsk(0xffffffff);
      iVar3 = sd_state_bit7();
    }
  } while( true );
  *(undefined4 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  fb_clear_rect(uStack_28,0x132,0,800,0xae);
  gui_draw_text_centered(uStack_28,0x20428122,0x132,400,0xf,0x20800b1c);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uStack_28,(&DAT_20808548)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,0x20800b1c)
    ;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  __aeabi_memcpy4(auStack_168,param_1 + 8,0x120);
  __aeabi_memcpy4(auStack_288,param_1 + 8,0x120);
  bVar1 = 0xff;
  while( true ) {
    bVar2 = fwupdate_poll(param_1 + 8);
    iVar3 = sd_state_bit6();
    if (iVar3 == 0) break;
    if ((bVar1 != bVar2) ||
       (iVar3 = memcmp(param_1 + 8,auStack_288,0x120), bVar1 = bVar2, iVar3 != 0)) {
      __aeabi_memcpy4(auStack_288,param_1 + 8,0x120);
      if (*(char *)(param_1 + 8) == '\x04') {
        gui_draw_progress_bar
                  (uStack_28,0x1a5,0x129,*(uint *)(param_1 + 0x40) & 0xffff,
                   *(uint *)(param_1 + 0x40));
      }
      else if (*(char *)(param_1 + 0x50) == '\x04') {
        if (cStack_120 != '\x04') {
          fb_clear_rect(uStack_28,0x132,0,800,0xae);
          gui_draw_text_centered(uStack_28,0x2042812f,0x132,400,0xf,0x20800b1c);
          uVar4 = 0;
          do {
            gui_draw_text_centered
                      (uStack_28,(&DAT_20808550)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,0x20800b1c);
            uVar4 = uVar4 + 1 & 0xff;
          } while (uVar4 < 2);
        }
        gui_draw_progress_bar
                  (uStack_28,0x1a5,0x129,*(uint *)(param_1 + 0x88) & 0xffff,
                   *(uint *)(param_1 + 0x88));
        gui_update_layers();
        fb_get_layer_addr(DAT_208085bc);
      }
      __aeabi_memcpy4(auStack_168,param_1 + 8,0x120);
      if (bVar2 != 0) goto LAB_20159c44;
      gui_update_layers();
      uStack_28 = fb_get_layer_addr(DAT_208085bc);
      bVar1 = bVar2;
    }
  }
  bVar2 = 2;
LAB_20159c44:
  FUN_2010e4a0();
  if (bVar2 != 1) {
    update_error_screen();
  }
  system_reboot();
  return;
}


// ===== bootloader_unlock_wait @ 20159cb0 (216 bytes)

/* key-6 mode: > 4 encoder steps -> loader-install mode */

uint bootloader_unlock_wait(void)

{
  uint uVar1;
  char local_30 [12];
  short local_24 [2];
  short local_20 [4];
  
  uVar1 = 0;
  pointer_touch_poll();
  DAT_208001e4 = '\0';
  while( true ) {
    if (DAT_20800493 != '\0') {
      return 0;
    }
    if ((g_bootinfo.mode == 2) &&
       (uVar1 = FUN_20164568(&DAT_20808bcc,uVar1,(int)DAT_208001e4), 4 < uVar1)) {
      return 1;
    }
    gui_update_layers();
    local_24[0] = 0;
    local_20[0] = 0;
    pointer_get_event(local_30,1);
    touch_cal_apply((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,local_24,local_20);
    if (local_30[0] == '\x02' || local_30[0] == '\x04') {
      return 0;
    }
    if (local_30[0] == '\x05' || local_30[0] == '\x06') break;
    pointer_get_event(local_30,0);
    itron_tslp_tsk(0xffffffff);
  }
  return 0;
}


// ===== fwupdate_ui_run @ 20159d98 (956 bytes)

/* Update-UI method behind fwupdate_title_screen_thunk and bootloader_screen ("YAESU FT-710 FIRMWARE
   UPDATE"): menu, target selection (fwupdate_select_loop), "UPDATE?" confirmation
   (fwupdate_confirm_loop), then fwupdate_progress_screen; card-missing and error texts [fact] */

void fwupdate_ui_run(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_4b8 [3];
  char local_4b5;
  undefined1 local_4b4;
  undefined1 local_4b3;
  undefined1 auStack_278 [5];
  undefined1 local_273;
  int iStack_30;
  undefined4 local_2c;
  
  iStack_30 = param_1;
  local_2c = param_2;
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  if (DAT_20800494 != '\0') {
    mainlink_send_e6(0);
  }
  DAT_20800496 = 1;
  DAT_20800495 = 0;
LAB_20159dec:
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  cursor_window_update();
  fwupdate_menu_screen(param_1,0,local_2c);
  gui_update_layers();
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  if (*(char *)(param_1 + 0x128) == -0x3d) {
    __aeabi_memclr4(local_4b8,0x240);
    local_4b8[0] = 0x43;
    if ((*(char *)(param_1 + 0x12a) == '\0') && (*(char *)(param_1 + 299) != '\0')) {
      if ((*(byte *)(param_1 + 299) & 0x40) == 0) {
        local_4b4 = 0;
      }
      else {
        local_4b4 = 0x40;
      }
      local_4b5 = *(char *)(param_1 + 299);
      local_4b3 = FUN_20158fa8(*(undefined1 *)(param_1 + 299));
                    /* title bar, four target rows [doc] */
      fwupdate_select_draw(param_1,local_4b8,local_2c);
      if (DAT_20800494 == '\0') {
        iVar1 = fb_get_layer_addr(DAT_208085bc);
        fb_clear_rect_checked(iVar1,0x19a,0x1a4,0x17c,0x46);
        gui_update_layers();
      }
                    /* Touch/mouse loop of the target list [doc] */
      iVar2 = fwupdate_select_loop(param_1,local_4b8,local_2c);
      if (iVar2 == 0) {
LAB_20159f50:
        if (DAT_20800493 != '\0') {
          return;
        }
        goto LAB_2015a040;
      }
      if ((DAT_20800494 == '\0') || (mainlink_send_e6(0), DAT_20808530 == '\0')) goto LAB_2015a100;
      local_4b3 = 10;
      fwupdate_confirm_draw(param_1,local_4b8);
      gui_update_layers();
                    /* Touch/mouse loop of the "UPDATE?" box [doc] */
      iVar2 = fwupdate_confirm_loop(param_1);
      if (iVar2 == 0) goto LAB_20159f50;
      mainlink_send_e6(0);
      if (DAT_20808531 != '\0') goto LAB_2015a100;
      goto LAB_20159dec;
    }
    if (DAT_20800494 != '\0') {
      __aeabi_memclr4(auStack_278,0x240);
      local_273 = 0xb;
      fwupdate_select_draw(param_1,auStack_278,local_2c);
      gui_update_layers();
      iVar1 = fwupdate_select_loop(param_1,auStack_278,local_2c);
      if (iVar1 == 0) {
        if (DAT_20800493 != '\0') {
          return;
        }
        goto LAB_2015a040;
      }
      goto LAB_2015a100;
    }
    uVar3 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect_checked(uVar3,0x19a,0,800,0x46);
    gui_draw_text_centered(uVar3,DAT_2080853c,0x1a7,400,0xc,0x208038c0);
    iVar1 = sd_state_bit6();
    while (iVar1 != 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      itron_tslp_tsk(0xffffffff);
      gui_update_layers();
      fb_get_layer_addr(DAT_208085bc);
      iVar1 = sd_state_bit6();
    }
  }
LAB_2015a040:
  if (DAT_20800494 != '\0') {
    FUN_2015933c();
    pointer_idle_loop();
    if (DAT_20800493 == '\0') {
      mainlink_send_e6(0);
    }
LAB_2015a100:
    layer_alpha_rect_opaque(5);
    if ((DAT_20800494 != '\0') && (DAT_20808531 == '\0')) {
      DAT_20800494 = 0;
      return;
    }
    fwupdate_progress_screen(param_1,0,local_2c);
    do {
      gui_update_layers();
      itron_tslp_tsk(0xffffffff);
    } while( true );
  }
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect_checked(uVar3,0x1a,0,800,0x1c6);
  gui_draw_text_centered(uVar3,DAT_2080856c,100,400,0xc,0x208038c0);
                    /* full-screen window, alpha 0xFF [doc, inference] */
  layer_alpha_rect_opaque(5);
  gui_update_layers();
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  iVar2 = sd_state_bit7();
  while (iVar2 == 0) {
    if (DAT_20800493 != '\0') {
      return;
    }
    itron_tslp_tsk(0xffffffff);
    iVar2 = sd_state_bit7();
  }
  goto LAB_20159dec;
}

