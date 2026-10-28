// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== scif5_rxi_isr @ 201148a4 (8 bytes)

void scif5_rxi_isr(void)

{
  DAT_208dba9c = DAT_208dba9c + 1;
  if ((*(ushort *)(iRam208db284 + 0x10) & 0xff9d) != 0) {
    iRam208dbaa8 = iRam208dbaa8 + 1;
  }
  if ((*(ushort *)(iRam208db284 + 0x10) & 2) != 0) {
    if (((uRam208db28a < uRam208db288) || (0x3fe < (int)((uint)uRam208db28a - (uint)uRam208db288)))
       && ((uRam208db288 <= uRam208db28a || ((int)((uint)uRam208db288 - (uint)uRam208db28a) < 2))))
    {
      *(ushort *)(iRam208db284 + 0x10) = *(ushort *)(iRam208db284 + 0x10) & 0xfffd;
      iRam208dbaa0 = iRam208dbaa0 + 1;
      iRam208dbaa4 = iRam208dbaa4 + 1;
      return;
    }
    *(undefined1 *)(uRam208db28a + 0x208db28c) = *(undefined1 *)(iRam208db284 + 0x14);
    DataMemoryBarrier(2);
    uRam208db28a = uRam208db28a + 1 & 0x3ff;
    *(ushort *)(iRam208db284 + 0x10) = *(ushort *)(iRam208db284 + 0x10) & 0xfffd;
    if (iRam208dba98 != 0) {
      gic_disable_irq(*(undefined4 *)(iRam208dba90 + 8));
    }
    itron_set_flg(iRam208dba98,1);
    iRam208dbaa0 = iRam208dbaa0 + 1;
    FUN_20114850(0x208dbac0);
    return;
  }
  iRam208dbaac = iRam208dbaac + 1;
  return;
}


// ===== scif5_txi_isr @ 201148ac (8 bytes)

void scif5_txi_isr(void)

{
  iRam208dbab0 = iRam208dbab0 + 1;
  if ((*(ushort *)(iRam208db284 + 0x10) & 0x20) == 0) {
    iRam208dbab8 = iRam208dbab8 + 1;
    return;
  }
  if (uRam208db68c != uRam208db68e) {
    *(undefined1 *)(iRam208db284 + 0xc) = *(undefined1 *)(uRam208db68c + 0x208db690);
    DataMemoryBarrier(2);
    uRam208db68c = uRam208db68c + 1 & 0x3ff;
    *(ushort *)(iRam208db284 + 0x10) = *(ushort *)(iRam208db284 + 0x10) & 0xff9f;
    iRam208dbab4 = iRam208dbab4 + 1;
    FUN_20114850(0x208dbac8);
    return;
  }
  *(ushort *)(iRam208db284 + 8) = *(ushort *)(iRam208db284 + 8) & 0xff7f;
  return;
}


// ===== scif5_get @ 201148b4 (36 bytes)

/* UART object @0x208DB280 on SCIF5 (0xE8009800), MAIN link */

undefined * scif5_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208db280,&DAT_e8009800,&DAT_201657c8,&DAT_201657b4,param_1);
  return &DAT_208db280;
}


// ===== scif4_get @ 201148d8 (36 bytes)

/* UART object on SCIF4 (0xE8009000) */

undefined * scif4_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208daa30,&DAT_e8009000,&DAT_201657a0,&DAT_2016578c,param_1);
  return &DAT_208daa30;
}


// ===== scif3_get @ 201148fc (36 bytes)

/* UART object on SCIF3 (0xE8008800) */

undefined * scif3_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208da1e0,&DAT_e8008800,&DAT_20165778,&DAT_20165764,param_1);
  return &DAT_208da1e0;
}


// ===== FUN_20114920 @ 20114920 (12 bytes)

undefined4 FUN_20114920(void)

{
  return DAT_208dba9c;
}


// ===== FUN_2011492c @ 2011492c (12 bytes)

undefined4 FUN_2011492c(void)

{
  return DAT_208db24c;
}


// ===== FUN_20114938 @ 20114938 (32 bytes)

void FUN_20114938(void)

{
  FUN_20163360(&DAT_208da1e0);
  FUN_20163360(&DAT_208daa30);
  FUN_20163360(&DAT_208db280);
  return;
}


// ===== sfl_decode @ 2011497c (100 bytes)

/* byte-wise key subtraction, see docs/sfl-format.md */

uint sfl_decode(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + iVar2) = *(char *)(param_2 + iVar2) - BYTE_ARRAY_204286f8[uVar1 + 0x148];
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return param_1 % 0x2b;
}


// ===== sfl_encode @ 201149e0 (100 bytes)

/* inverse of sfl_decode (adds the 43-byte key) */

uint sfl_encode(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + iVar2) = *(char *)(param_2 + iVar2) + BYTE_ARRAY_204286f8[uVar1 + 0x148];
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return param_1 % 0x2b;
}


// ===== sfl_stream_init @ 20114a44 (32 bytes)

void sfl_stream_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = param_4;
  param_1[4] = 0;
  param_1[1] = param_3;
  *(undefined1 *)(param_1 + 5) = 0;
  return;
}


// ===== sfl_crc @ 20114a64 (112 bytes)

/* salted CRC-32 over the file */

uint sfl_crc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_110 [256];
  undefined4 local_10;
  
  uVar3 = 0xffffffff;
  local_10 = 0x139eeca6;
  crc32_make_table();
  while (iVar1 = fs_fread(auStack_110,1,0x100,param_1), iVar1 != 0) {
    uVar3 = crc32_update(uVar3,iVar1,auStack_110);
  }
  uVar2 = crc32_update(uVar3,4,&local_10);
  return ~uVar2;
}


// ===== sfl_stream_getc @ 20114ae0 (92 bytes)

/* one decoded byte */

uint sfl_stream_getc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint local_c;
  
  if (0 < *(int *)(param_1 + 0x10)) {
    if (*(int *)(param_1 + 8) < *(int *)(param_1 + 0x10)) {
      local_c = CONCAT31((int3)((uint)param_4 >> 8),
                         *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)));
      uVar1 = sfl_decode(*(undefined1 *)(param_1 + 0x14),&local_c,1);
      *(undefined1 *)(param_1 + 0x14) = uVar1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      local_c = local_c & 0xff;
    }
    else {
      local_c = 0xffffffff;
    }
    return local_c;
  }
  return 0xffffffff;
}


// ===== sfl_stream_gets @ 20114b3c (192 bytes)

/* line read with decode */

int sfl_stream_gets(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3[3] == 0) {
    iVar2 = FUN_20142390(param_1,param_2,*param_3);
    return iVar2;
  }
  if (0 < param_2) {
    iVar2 = 0;
    if (0 < param_2 + -1) {
      do {
        iVar1 = sfl_stream_getc(param_3);
        if (iVar1 == -1) {
          iVar1 = fs_fread(param_3[1],1,param_3[3],*param_3);
          if (iVar1 == 0) break;
          param_3[4] = iVar1;
          param_3[2] = 0;
        }
        else {
          *(char *)(param_1 + iVar2) = (char)iVar1;
          iVar2 = iVar2 + 1;
          if (iVar1 == 10) break;
        }
      } while (iVar2 < param_2 + -1);
    }
    *(undefined1 *)(param_1 + iVar2) = 0;
    if ((iVar2 != 0) || (param_2 < 2)) {
      return param_1;
    }
  }
  return 0;
}


// ===== sfl_stream_read @ 20114bfc (72 bytes)

/* fread + decode */

int sfl_stream_read(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = fs_fread();
  if ((iVar2 != 0) && (*(int *)(param_4 + 0xc) != 0)) {
    uVar1 = sfl_decode(*(undefined1 *)(param_4 + 0x14),param_1,iVar2);
    *(undefined1 *)(param_4 + 0x14) = uVar1;
  }
  return iVar2;
}


// ===== FUN_20114c44 @ 20114c44 (92 bytes)

void FUN_20114c44(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  
  if (param_4[3] != 0) {
    uVar1 = sfl_encode(*(undefined1 *)(param_4 + 5),param_1,param_2 * param_3);
    *(undefined1 *)(param_4 + 5) = uVar1;
    fs_fwrite(param_1,param_2,param_3,*param_4);
    return;
  }
  fs_fwrite(param_1,param_2,param_3,*param_4);
  return;
}


// ===== sfl_read_header @ 20114ca0 (336 bytes)

/* reads the 0x40-byte header block */

undefined4 sfl_read_header(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_118 [64];
  undefined1 local_d8;
  undefined1 *local_18;
  int local_14;
  
  local_18 = auStack_118;
  iVar3 = 0;
  do {
    iVar1 = fs_fread(auStack_118,1,0x40,param_1);
    if (iVar1 == 0) {
      return 1;
    }
    if ((param_2 != 0) && (iVar3 == 3)) {
      memcpy(param_2,auStack_118,0x40);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  local_d8 = 0;
  iVar3 = FUN_20155122(auStack_118);
  if (iVar3 == 0x40) {
    iVar3 = sfl_crc(param_1);
    fs_fseek(param_1,0);
    iVar1 = 0;
    do {
      iVar2 = fs_fread(auStack_118,1,0x40,param_1);
      if (iVar2 == 0) {
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    iVar1 = FUN_20142390(auStack_118,0x100,param_1);
    if ((((iVar1 != 0) && (iVar1 = FUN_2014e320(local_18,&DWORD_20114df0,&local_18), iVar1 != 0)) &&
        (iVar1 = FUN_2014e320(local_18,&DWORD_20114df0,&local_18), iVar1 != 0)) &&
       (((iVar1 = FUN_2014e320(local_18,&DWORD_20114df0,&local_18), iVar1 != 0 &&
         (iVar2 = hex_parse(iVar1,8,&local_14), local_14 != iVar1)) && (iVar2 == iVar3)))) {
      return 0;
    }
  }
  return 1;
}


// ===== system_reboot @ 20114df4 (148 bytes)

/* FS off, LCD/LVDS off, MAIN reset pulse, flash reset, wdt_system_reset */

void system_reboot(void)

{
  FUN_2014e884(0,1);
  gpio_p2_4_5_clear();
  backlight_enable(0);
  lvds_pins_enable(0);
  gpio_rx_update_off(1);
  itron_dly_tsk(5);
  itron_dly_tsk(0x96);
  gpio_rx_update_off(0);
  gpio_p7_9_11(1);
  itron_dly_tsk(4);
  gpio_rx_update(0);
  gpio_rx_reset(1);
  itron_dly_tsk(1);
  gpio_p8_5(1);
  gpio_rx_reset(0);
  itron_dly_tsk(0xe);
  gpio_qf_reset(1);
  wdt_system_reset();
  return;
}


// ===== uart4_send @ 20114e88 (84 bytes)

/* used by task_keycode, FUN_20130c90, FUN_20131638 */

void uart4_send(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = uart4_tx_alloc(DAT_20450020 + 0x938);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(short *)(iVar1 + 6) = (short)param_2;
  memcpy(iVar1 + 8,param_1,param_2);
  uart4_tx_post(DAT_20450020 + 0x938,iVar1);
  return;
}


// ===== uart4_wait_ready @ 20114edc (112 bytes)

/* waits for 0x2045001C; no caller */

undefined4 uart4_wait_ready(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 100;
  while( true ) {
    if (DAT_2045001c != '\0') {
      return 1;
    }
    if ((param_1 != 0) && (iVar1 = iVar1 + -1, iVar1 == 0)) break;
    itron_dly_tsk(1);
    if (((byte)DAT_20808a84 & 1) != 0) {
      return 1;
    }
  }
  DAT_2045001d = 1;
  return 0;
}


// ===== uart4_link_init @ 20114f4c (120 bytes)

/* creates the SCIF4 object 0x2045D4E0 and task "uart4"; no caller */

void uart4_link_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  memclr(&DAT_2045d4e0,0x1ae0);
  DAT_20450020 = uart4_obj_ctor(&DAT_2045d4e0);
  iVar1 = itron_acre_tsk(0,&DAT_201657dc);
  if ((0 < iVar1) && (iVar2 = itron_acre_flg(0,&DAT_201657f8), 0 < iVar2)) {
    *(int *)(DAT_20450020 + 0x14) = iVar2;
    uVar3 = scif4_get();
    *(undefined4 *)(DAT_20450020 + 0x10) = uVar3;
    itron_sta_tsk(iVar1);
    return;
  }
  return;
}


// ===== FUN_20114fc4 @ 20114fc4 (40 bytes)

code * FUN_20114fc4(code *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_r4;
  int *piVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 unaff_lr;
  bool bVar11;
  
  if (DAT_20450020 == 0) {
    return param_1;
  }
  uVar4 = *(uint *)(DAT_20450020 + 0x14);
  if (param_1 == (code *)0x0) {
    uVar6 = 0x4000;
  }
  else {
    uVar6 = 0x8000;
  }
  if (uVar6 == 0) {
    DAT_208003d4 = (code *)0x0;
  }
  else {
    if ((uVar4 != 0) && (uVar4 < 0x41)) {
      software_interrupt(0);
      iVar9 = *(int *)(&DAT_208dbda4 + uVar4 * 4);
      if (iVar9 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      for (pbVar10 = (byte *)(iVar9 + 9); uVar4 = (uint)*pbVar10, uVar4 == 0; pbVar10 = pbVar10 + 1)
      {
      }
      if (0xfd < uVar4) {
        *(uint *)(iVar9 + 4) = *(uint *)(iVar9 + 4) | uVar6;
        software_interrupt(0);
        return FUN_201567f4;
      }
      piVar8 = *(int **)(&DAT_208dbba0 + uVar4 * 4);
      uVar7 = (uint)*(byte *)((int)piVar8 + 7);
      bVar11 = uVar7 == uVar4;
      if (bVar11) {
        uVar7 = (uint)*(byte *)(iVar9 + 8);
      }
      if (!bVar11 || (uVar7 & 2) != 0) {
        bVar11 = false;
        uVar6 = uVar6 | *(uint *)(iVar9 + 4);
LAB_20150fa4:
        piVar8 = *(int **)(&DAT_208dbba0 + (uint)*pbVar10 * 4);
        bVar1 = *(byte *)((int)piVar8 + 7);
        uVar4 = (uint)*pbVar10;
        do {
          bVar2 = *(byte *)((int)piVar8 + 5);
          bVar3 = *(byte *)((int)piVar8 + 6);
          if ((bVar2 & 1) == 0) {
            if ((*(uint *)(*piVar8 + 8) & ~uVar6) == 0) goto LAB_2015109c;
          }
          else if ((*(uint *)(*piVar8 + 8) & uVar6) != 0) {
LAB_2015109c:
            **(uint **)(*piVar8 + 0xc) = uVar6;
            if ((bVar2 & 2) != 0) {
              FUN_20153ad4(piVar8,uVar4);
            }
            *(undefined1 *)((int)piVar8 + 5) = 0x10;
            if (*(char *)((int)piVar8 + 9) == '\0') {
              iVar5 = (int)(char)piVar8[1];
              if (iVar5 < DAT_208003df) {
                bVar11 = (bool)(bVar11 | iVar5 < DAT_208003df);
              }
              FUN_20153a38(&DAT_208dc18c + iVar5,piVar8,uVar4);
            }
            else {
              FUN_201539ec(piVar8,uVar4);
            }
            if ((bVar2 & 4) != 0) {
              *(undefined4 *)(iVar9 + 4) = 0;
              if (!bVar11) {
                software_interrupt(0);
                return FUN_201567f4;
              }
              software_interrupt(0);
              return FUN_2015655c;
            }
          }
          if (bVar1 == uVar4) goto LAB_2015116c;
          piVar8 = *(int **)(&DAT_208dbba0 + (uint)bVar3 * 4);
          uVar4 = (uint)bVar3;
        } while( true );
      }
      bVar1 = *(byte *)((int)piVar8 + 5);
      if ((bVar1 & 1) == 0) {
        uVar6 = *(uint *)(iVar9 + 4) | uVar6;
        if ((*(uint *)(*piVar8 + 8) & ~uVar6) != 0) goto LAB_20151030;
      }
      else {
        uVar6 = *(uint *)(iVar9 + 4) | uVar6;
        if ((*(uint *)(*piVar8 + 8) & uVar6) == 0) {
LAB_20151030:
          *(uint *)(iVar9 + 4) = uVar6;
          software_interrupt(0);
          return FUN_201567f4;
        }
      }
      **(uint **)(*piVar8 + 0xc) = uVar6;
      if ((bVar1 & 4) != 0) {
        uVar6 = 0;
      }
      *(uint *)(iVar9 + 4) = uVar6;
      if ((bVar1 & 2) != 0) {
        FUN_20153ad4(piVar8,uVar4);
      }
      *(undefined1 *)((int)piVar8 + 5) = 0x10;
      if (*(char *)((int)piVar8 + 9) == '\0') {
        iVar9 = piVar8[1];
        FUN_20153a38(&DAT_208dc18c + (char)iVar9,piVar8,uVar4,&DAT_208dc18c + (char)iVar9,unaff_r4,
                     unaff_lr);
        if ((int)DAT_208003df <= (int)(char)iVar9) {
          software_interrupt(0);
          return FUN_201567f4;
        }
        software_interrupt(0);
        return FUN_2015655c;
      }
      FUN_201539ec();
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  return DAT_208003d4;
LAB_2015116c:
  do {
    pbVar10 = pbVar10 + 1;
  } while (*pbVar10 == 0);
  if (0xfd < *pbVar10) {
    *(uint *)(iVar9 + 4) = uVar6;
    if (!bVar11) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  goto LAB_20150fa4;
}


// ===== mainlink_get_last_frame @ 20115000 (12 bytes)

/* copy of the newest MAIN frame (0x2045F8C0, 0x240 B) */

void mainlink_get_last_frame(undefined4 param_1)

{
  memcpy(param_1,&DAT_2045f8c0,0x240);
  return;
}


// ===== mainlink_get_frame60 @ 2011500c (12 bytes)

/* copy of the newest 0x60 frame (0x2045FB00) */

void mainlink_get_frame60(undefined4 param_1)

{
  memcpy(param_1,&DAT_2045fb00,0x240);
  return;
}


// ===== mainlink_got_frame60 @ 20115018 (12 bytes)

/* flag 0x20450026 */

undefined1 mainlink_got_frame60(void)

{
  return DAT_20450026;
}


// ===== mainlink_get_settings24 @ 20115024 (24 bytes)

/* copies the 0x24 frame tail (0x2045006D) and returns flag 0x20450024 */

undefined1 mainlink_get_settings24(undefined4 param_1)

{
  FUN_201636f8(param_1,&DAT_2045006d);
  return DAT_20450024;
}


// ===== FUN_2011503c @ 2011503c (36 bytes)

undefined1 FUN_2011503c(undefined1 *param_1)

{
  *param_1 = DAT_20450035;
  param_1[1] = uRam20450036;
  param_1[2] = uRam20450037;
  return uRam20450025;
}


// ===== mainlink_got_esc @ 20115060 (12 bytes)

/* flag 0x2045005C, set by a 0x1B frame */

undefined4 mainlink_got_esc(void)

{
  return DAT_2045005c;
}


// ===== mainlink_last_frame_differs @ 2011506c (32 bytes)

bool mainlink_last_frame_differs(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_2015507c(&DAT_2045f8c0,param_1,0x240);
  return iVar1 != 0;
}


// ===== mainlink_set_last_frame @ 2011508c (16 bytes)

/* writes the 0x2045F8C0 snapshot (debug replay, GUI) */

void mainlink_set_last_frame(undefined4 param_1)

{
  memcpy(&DAT_2045f8c0,param_1,0x240);
  return;
}


// ===== task_cmd_interval @ 2011509c (68 bytes)

void task_cmd_interval(void)

{
  DAT_20450050 = 0;
  do {
    do {
      FUN_201525f8(0xffffffff);
    } while (DAT_20450050 < 1);
    FUN_20152bb0(DAT_20450054,0xffffffff);
    DAT_20450050 = DAT_20450050 + -1;
    FUN_201511e8(DAT_20450054);
  } while( true );
}


// ===== mainlink_set_wait_cmd @ 201150e0 (12 bytes)

/* cmd byte of the frame waiting for ACK (0x2045002D) */

void mainlink_set_wait_cmd(undefined1 param_1)

{
  DAT_2045002d = param_1;
  return;
}


// ===== mainlink_get_wait_cmd @ 201150ec (12 bytes)

undefined1 mainlink_get_wait_cmd(void)

{
  return DAT_2045002d;
}


// ===== mainlink_submit @ 201150f8 (924 bytes)

/* adds checksum; F0/F1 go out at once; other frames go out if no ACK is pending, else are parked in
   per-type slots 0x2045F240..4B */

void mainlink_submit(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar2 + 4) = 0xaa;
  *(short *)(iVar2 + 6) = (short)param_2 + 1;
  memcpy(iVar2 + 8,param_1,param_2);
  bVar1 = *(byte *)(iVar2 + 8);
  if (bVar1 == 0xf0 || bVar1 == 0xf1) {
    cVar5 = '\0';
    iVar3 = 0;
    iVar6 = *(ushort *)(iVar2 + 6) - 1;
    if (0 < iVar6) {
      do {
        iVar7 = iVar2 + iVar3;
        iVar3 = iVar3 + 1;
        cVar5 = cVar5 + *(char *)(iVar7 + 8);
      } while (iVar3 < iVar6);
    }
    *(char *)((uint)*(ushort *)(iVar2 + 6) + iVar2 + 7) = cVar5;
    mainlink_tx_post(DAT_20450060 + 0x8218,iVar2);
    return;
  }
  if (DAT_2080049c == '\0') {
    if (DAT_2045002a == '\0') {
      memclr(&DAT_2045efc0,0x105);
      memcpy(&DAT_2045efc0,param_1,param_2);
      DAT_20450038 = param_2;
      mainlink_set_wait_cmd(*(undefined1 *)(iVar2 + 8));
      cVar5 = '\0';
      iVar3 = 0;
      iVar6 = *(ushort *)(iVar2 + 6) - 1;
      if (0 < iVar6) {
        do {
          iVar7 = iVar2 + iVar3;
          iVar3 = iVar3 + 1;
          cVar5 = cVar5 + *(char *)(iVar7 + 8);
        } while (iVar3 < iVar6);
      }
      *(char *)((uint)*(ushort *)(iVar2 + 6) + iVar2 + 7) = cVar5;
      mainlink_tx_post(DAT_20450060 + 0x8218,iVar2);
      DAT_2045002a = 1;
      DAT_2045002c = 0;
      FUN_20151680(DAT_20450064);
      return;
    }
    if (bVar1 == 0xe4) {
      DAT_20470108 = 0;
      memcpy(&DAT_20470108,param_1,param_2);
      DAT_2045f241 = 1;
      return;
    }
    if (bVar1 < 0xe5) {
      if (bVar1 == 0xe0) {
        uVar4 = DAT_2045002e + 1 & 0xff;
        DAT_2045002e = (byte)(uVar4 % 10);
        iVar2 = (uVar4 % 10) * 5;
        FUN_20163668(iVar2 + 0x20470117,(uVar4 / 10) * -5,uVar4 * -0x33333333);
        memcpy(iVar2 + 0x20470117,param_1,param_2);
        DAT_2045f244 = 1;
        return;
      }
      if (bVar1 < 0xe1) {
        if (bVar1 == 0xc3) {
          FUN_20155274(&DAT_20470165,0x22);
          memcpy(&DAT_20470165,param_1,param_2);
          DAT_2045f249 = 1;
          return;
        }
        if (bVar1 == 0xc4) {
          FUN_20155274(&DAT_20470187,0x106);
          memcpy(&DAT_20470187,param_1,param_2);
          DAT_2045f24a = 1;
          return;
        }
        if (bVar1 == 0xc5) {
          FUN_20163684();
          memcpy(&DAT_2047028d,param_1,param_2);
          DAT_2045f24b = 1;
        }
      }
      else {
        if (bVar1 == 0xe2) {
          FUN_20163684(&DAT_20470149);
          memcpy(&DAT_20470149,param_1,param_2);
          DAT_2045f245 = 1;
          return;
        }
        if (bVar1 == 0xe3) {
          DAT_20470100 = 0;
          DAT_20470104 = 0;
          memcpy(&DAT_20470100,param_1,param_2);
          DAT_2045f240 = 1;
          return;
        }
      }
    }
    else {
      if (bVar1 == 0xe7) {
        FUN_20155274(&DAT_20470153,9);
        memcpy(&DAT_20470153,param_1,param_2);
        DAT_2045f247 = 1;
        return;
      }
      if (bVar1 < 0xe8) {
        if (bVar1 == 0xe5) {
          DAT_2047010c = 0;
          memcpy(&DAT_2047010c,param_1,param_2);
          DAT_2045f242 = 1;
          return;
        }
        if (bVar1 == 0xe6) {
          DAT_2047014f = 0;
          DAT_20470150 = 0;
          DAT_20470151 = 0;
          DAT_20470152 = 0;
          memcpy(&DAT_2047014f,param_1,param_2);
          DAT_2045f246 = 1;
          return;
        }
      }
      else {
        if (bVar1 == 0xe8) {
          FUN_201636b8(&DAT_2047015c);
          memcpy(&DAT_2047015c,param_1,param_2);
          DAT_2045f248 = 1;
          return;
        }
        if (bVar1 == 0xf1) {
          memclr(&DAT_20470110,7);
          memcpy(&DAT_20470110,param_1,param_2);
          DAT_2045f243 = 1;
          return;
        }
      }
    }
  }
  return;
}


// ===== mainlink_queue_frame @ 20115494 (644 bytes)

/* WARNING: Type propagation algorithm not settling */

void mainlink_queue_frame(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_2c = param_1;
  uStack_28 = param_2;
  memcpy(&DAT_2045f4a0,param_1,param_2);
  if (DAT_20800496 != '\0' || DAT_20800494 != '\0') {
    if (DAT_2045f4a0 != -0x1a) {
      if ((DAT_208f0b2a == '@') && (DAT_20800494 != '\0')) {
        if ((DAT_2045f4a0 == -0x20) &&
           (((DAT_2045f4a1 == 1 && (DAT_2045f4a2 == '\x03')) && (DAT_2045f4a3 == '\x0f')))) {
          DAT_20808533 = 1;
          return;
        }
        if (DAT_20800496 == '\0') goto LAB_20115704;
      }
      if (DAT_2045f4a0 != -0x20) {
        return;
      }
      if (2 < DAT_2045f4a1) {
        return;
      }
      if (DAT_2045f4a2 != '\x03') {
        return;
      }
      if (DAT_2045f4a3 != '\0') {
        return;
      }
    }
    goto LAB_20115704;
  }
  if (DAT_208f0b2a == '{') {
    if ((DAT_208f0b2b != '\0') && (DAT_2045f4a0 == -0x1e)) {
      local_30[0] = 0xe4;
      DAT_20800488 = 1;
      mainlink_submit(local_30,4);
      goto LAB_2011553c;
    }
  }
  else {
LAB_2011553c:
    if (((((DAT_208f0b2a == '@') && (DAT_2045f4a0 == -0x20)) &&
         ((DAT_2045f4a1 == 1 &&
          ((((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')) && (DAT_208f0bc2 == '\0')) &&
           (((DAT_208f0bc6 & 0x10) != 0 && ((DAT_208f0bc5 & 2) != 0)))))))) &&
        (((uint)DAT_208f0bc4 + (DAT_208f0bc6 & 0xf) == 5 &&
         ((iVar1 = FUN_2015507c((DAT_208f0bc6 & 0xf) * 0x2d + 0x208f0c46,"FIRMWARE UPDATE      ",
                                0x15), iVar1 == 0 && (DAT_208000b2 == '\0')))))) &&
       (iVar1 = FUN_20103ba0(), iVar1 != 0)) {
      DAT_20450027 = 1;
      DAT_20800494 = 1;
      DAT_20808533 = 0;
      return;
    }
  }
  if (DAT_20800494 != '\0') {
    return;
  }
  if ((((DAT_20450027 != '\0') && (DAT_2045f4a0 == -0x20)) && (DAT_2045f4a1 == 0)) &&
     ((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')))) {
    DAT_20450027 = 0;
    return;
  }
LAB_20115704:
  mainlink_submit(local_2c,param_2);
  return;
}


// ===== mainlink_send_enc @ 20115780 (420 bytes)

/* E1 encoder frame: sent now, or merged into a 7x10 per-encoder queue (0x2045F0C5) while an ACK is
   pending */

void mainlink_send_enc(byte *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (DAT_20800495 == '\0') {
    return;
  }
  if (DAT_2045002a != '\0') {
    FUN_20152bb0(DAT_20450058,0xffffffff);
    uVar4 = (uint)*param_1;
    DAT_2045002b = DAT_2045002b | (byte)(1 << uVar4);
    iVar5 = (&DAT_2045f224)[uVar4];
    if (iVar5 < 10) {
      FUN_201636cc(&DAT_2045f0c5 + iVar5 * 5 + uVar4 * 0x32,param_1);
      (&DAT_2045f224)[uVar4] = iVar5 + 1;
    }
    else {
      iVar5 = iVar5 * 5 + uVar4 * 0x32;
      cVar2 = (&DAT_2045f0c5)[iVar5 + -4];
      FUN_201636cc(&DAT_2045f0c5 + iVar5 + -5,param_1);
      switch(uVar4) {
      case 1:
      case 2:
      case 3:
        iVar1 = (int)(char)param_1[1] + (int)cVar2;
        if (iVar1 < 0) {
          if (iVar1 < -0x7f) {
            iVar1 = -0x7f;
          }
          iVar1 = iVar1 + 0x100;
        }
        else if (0x7f < iVar1) {
          iVar1 = 0x7f;
        }
        (&DAT_2045f0c5)[iVar5 + -4] = (char)iVar1;
        break;
      case 4:
      case 5:
        (&DAT_2045f0c5)[iVar5 + -4] = param_1[1];
      }
    }
    FUN_201511e8(DAT_20450058);
    return;
  }
  iVar5 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar5 + 4) = 0xaa;
  *(undefined2 *)(iVar5 + 6) = 7;
  *(undefined1 *)(iVar5 + 8) = 0xe1;
  FUN_201636cc(iVar5 + 9,param_1);
  FUN_201636a8(&DAT_20450068);
  FUN_201636cc(&DAT_20450068,param_1);
  mainlink_set_wait_cmd(*(undefined1 *)(iVar5 + 8));
  cVar2 = '\0';
  iVar1 = 0;
  iVar3 = *(ushort *)(iVar5 + 6) - 1;
  if (0 < iVar3) {
    do {
      iVar6 = iVar5 + iVar1;
      iVar1 = iVar1 + 1;
      cVar2 = cVar2 + *(char *)(iVar6 + 8);
    } while (iVar1 < iVar3);
  }
  *(char *)((uint)*(ushort *)(iVar5 + 6) + iVar5 + 7) = cVar2;
  mainlink_tx_post(DAT_20450060 + 0x8218,iVar5);
  DAT_2045002a = 1;
  DAT_2045002c = 0;
  FUN_20151680(DAT_20450064);
  return;
}


// ===== minmax4 @ 2011593c (80 bytes)

/* min or max of 4 bytes */

void minmax4(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 1;
  bVar2 = *param_2;
  if (param_1 != 0) {
    do {
      pbVar1 = param_2 + uVar3;
      uVar3 = uVar3 + 1 & 0xff;
      if (bVar2 < *pbVar1) {
        bVar2 = *pbVar1;
      }
    } while (uVar3 < 4);
    return;
  }
  do {
    pbVar1 = param_2 + uVar3;
    uVar3 = uVar3 + 1 & 0xff;
    if (*pbVar1 < bVar2) {
      bVar2 = *pbVar1;
    }
  } while (uVar3 < 4);
  return;
}


// ===== pot5_filter @ 2011598c (188 bytes)

/* pot id 5 jitter filter (last 4 values span > 2, value 3..252) */

undefined4 pot5_filter(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (DAT_20450030 != param_1) {
    if (DAT_2045003c == 1) {
      uVar3 = param_1 | param_1 << 8;
      DAT_2045003c = 0;
      DAT_20450040 = uVar3 | uVar3 << 0x10;
    }
    DAT_20450030 = (byte)param_1;
    DAT_20450031 = DAT_20450031 + 1;
    if (3 < DAT_20450031) {
      DAT_20450031 = 0;
    }
    *(byte *)((int)&DAT_20450040 + (uint)DAT_20450031) = DAT_20450030;
    if (((param_1 - 3 < 0xfa) && ((char)DAT_20450040 != DAT_20450040._2_1_)) &&
       (DAT_20450040._1_1_ != DAT_20450040._3_1_)) {
      iVar1 = minmax4(1,&DAT_20450040);
      iVar2 = minmax4(0,&DAT_20450040);
      if (2 < iVar1 - iVar2) {
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}


// ===== pot4_filter @ 20115a48 (188 bytes)

/* pot id 4 jitter filter */

undefined4 pot4_filter(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (DAT_20450032 != param_1) {
    if (DAT_20450044 == 1) {
      uVar3 = param_1 | param_1 << 8;
      DAT_20450044 = 0;
      DAT_20450048 = uVar3 | uVar3 << 0x10;
    }
    DAT_20450032 = (byte)param_1;
    DAT_20450033 = DAT_20450033 + 1;
    if (3 < DAT_20450033) {
      DAT_20450033 = 0;
    }
    *(byte *)((int)&DAT_20450048 + (uint)DAT_20450033) = DAT_20450032;
    if (((param_1 - 3 < 0xfa) && ((char)DAT_20450048 != DAT_20450048._2_1_)) &&
       (DAT_20450048._1_1_ != DAT_20450048._3_1_)) {
      iVar1 = minmax4(1,&DAT_20450048);
      iVar2 = minmax4(0,&DAT_20450048);
      if (2 < iVar1 - iVar2) {
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}


// ===== mainlink_renc_event @ 20115b04 (220 bytes)

/* encoder event from the renc tasks -> E4 (leave screen saver) and/or E1 */

void mainlink_renc_event(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined4 local_10;
  
  if (DAT_20800496 != '\0') {
    return;
  }
  local_10 = param_4;
  iVar2 = FUN_20116dac();
  if (iVar2 == 0) {
    return;
  }
  if (*param_1 == '\x04') {
    iVar2 = pot4_filter(param_1[1]);
    if (iVar2 == 0) {
      bVar1 = false;
      goto LAB_20115b68;
    }
  }
  else if (*param_1 == '\x05') {
    iVar2 = pot5_filter(param_1[1]);
    bVar1 = false;
    if (iVar2 == 0) goto LAB_20115b68;
  }
  bVar1 = true;
LAB_20115b68:
  cVar3 = DAT_208f0b2a;
  if ((DAT_208f0b2a == '{') && (cVar3 = '\0', DAT_208f0b2b != '\0')) {
    if (bVar1) {
      DAT_208f0b2b = '\0';
      local_10 = 0xe4;
      DAT_20800488 = 1;
      mainlink_queue_frame(&local_10,4);
      if (*param_1 == '\x04' || *param_1 == '\x05') {
        mainlink_send_enc(param_1);
      }
    }
    return;
  }
  mainlink_send_enc(param_1,&DAT_208f0b2a,cVar3,local_10);
  return;
}


// ===== mainlink_tx_raw @ 20115be0 (148 bytes)

/* frame = 0xAA tag, length, payload, sum8; posts to the TX task (used for resends) */

void mainlink_tx_raw(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(short *)(iVar1 + 6) = (short)param_2 + 1;
  memcpy(iVar1 + 8,param_1,param_2);
  cVar3 = '\0';
  iVar2 = 0;
  iVar4 = *(ushort *)(iVar1 + 6) - 1;
  if (0 < iVar4) {
    do {
      iVar5 = iVar1 + iVar2;
      iVar2 = iVar2 + 1;
      cVar3 = cVar3 + *(char *)(iVar5 + 8);
    } while (iVar2 < iVar4);
  }
  *(char *)((uint)*(ushort *)(iVar1 + 6) + iVar1 + 7) = cVar3;
  mainlink_tx_post(DAT_20450060 + 0x8218,iVar1);
  return;
}


// ===== mainlink_tx_e1_raw @ 20115c74 (136 bytes)

/* resend of the last E1 (encoder) frame kept at 0x20450068 */

void mainlink_tx_e1_raw(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
  iVar1 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(undefined2 *)(iVar1 + 6) = 7;
  *(undefined1 *)(iVar1 + 8) = 0xe1;
  FUN_201636cc(iVar1 + 9,param_1);
  cVar3 = '\0';
  uVar2 = 0;
  do {
    iVar4 = iVar1 + uVar2;
    uVar2 = uVar2 + 1;
    cVar3 = cVar3 + *(char *)(iVar4 + 8);
  } while (uVar2 < 6);
  *(char *)((uint)*(ushort *)(iVar1 + 6) + iVar1 + 7) = cVar3;
  mainlink_tx_post(DAT_20450060 + 0x8218,iVar1);
  return;
}


// ===== mainlink_flush_parked @ 20115cfc (608 bytes)

/* after an ACK: sends the next parked frame (E3,E4,E5,F1,E0 ring,E2,E6,E7,E8,C3,C4,C5 order) */

void mainlink_flush_parked(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_2045f240 == '\x01') {
    mainlink_submit(&DAT_20470100,8);
    DAT_20470100 = 0;
    DAT_20470104 = 0;
    DAT_2045f240 = 0;
    return;
  }
  if (DAT_2045f241 == '\x01') {
    mainlink_submit(&DAT_20470108,4);
    DAT_20470108 = 0;
    DAT_2045f241 = 0;
    return;
  }
  if (DAT_2045f242 == '\x01') {
    mainlink_submit(&DAT_2047010c,4);
    DAT_2047010c = 0;
    DAT_2045f242 = 0;
    return;
  }
  if (DAT_2045f243 == '\x01') {
    mainlink_submit(&DAT_20470110,7);
    memclr(&DAT_20470110,7);
    DAT_2045f243 = 0;
    return;
  }
  if (DAT_2045f244 == '\x01') {
    uVar1 = DAT_2045002f + 1 & 0xff;
    uVar2 = uVar1 % 10;
    DAT_2045002f = (byte)uVar2;
    mainlink_submit(uVar2 * 5 + 0x20470117,5,uVar1 * -0x33333333);
    uVar1 = (uint)DAT_2045002f;
    FUN_20163668(uVar1 * 5 + 0x20470117);
    if (DAT_2045002e == uVar1) {
      DAT_2045f244 = '\0';
    }
    return;
  }
  if (DAT_2045f245 == '\x01') {
    mainlink_submit(&DAT_20470149,6);
    FUN_20163684(&DAT_20470149);
    DAT_2045f245 = 0;
    return;
  }
  if (DAT_2045f246 == '\x01') {
    mainlink_submit(&DAT_2047014f,4);
    DAT_2047014f = 0;
    DAT_20470150 = 0;
    DAT_20470151 = 0;
    DAT_20470152 = 0;
    DAT_2045f246 = 0;
    return;
  }
  if (DAT_2045f247 != '\x01') {
    if (DAT_2045f248 == '\x01') {
      mainlink_submit(&DAT_2047015c,9);
      FUN_201636b8(&DAT_2047015c);
      DAT_2045f248 = 0;
      return;
    }
    if (DAT_2045f249 != '\x01') {
      if (DAT_2045f24a != '\x01') {
        if (DAT_2045f24b == '\x01') {
          mainlink_submit(&DAT_2047028d,6);
          FUN_20163684(&DAT_2047028d);
          DAT_2045f24b = '\0';
        }
        return;
      }
      mainlink_submit(&DAT_20470187,0x106);
      FUN_20155274(&DAT_20470187,0x106);
      DAT_2045f24a = 0;
      return;
    }
    mainlink_submit(&DAT_20470165,0x22);
    FUN_20155274(&DAT_20470165,0x22);
    DAT_2045f249 = 0;
    return;
  }
  mainlink_submit(&DAT_20470153,9);
  FUN_20155274(&DAT_20470153,9);
  DAT_2045f247 = 0;
  return;
}


// ===== mainlink_flush_enc @ 20115f5c (248 bytes)

/* after an ACK: sends the oldest queued encoder event */

void mainlink_flush_enc(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_28 [12];
  
  uVar3 = 8;
  FUN_20152bb0(DAT_20450058,0xffffffff);
  uVar1 = 0;
  do {
    if (((uint)DAT_2045002b & 1 << (uVar1 & 0xff)) != 0) {
      uVar3 = uVar1;
      if ((int)(&DAT_2045f224)[uVar1] < 2) {
        DAT_2045002b = DAT_2045002b & ~(byte)(1 << (uVar1 & 0xff));
      }
      break;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 7);
  if (7 < (int)uVar3) {
    DAT_2045002b = 0;
    FUN_20163668(&DAT_2045f0c5 + (&DAT_2045f224)[uVar3] * 5 + uVar3 * 0x32);
    return;
  }
  FUN_201636cc(auStack_28);
  iVar4 = (&DAT_2045f224)[uVar3];
  iVar2 = 0;
  if (0 < iVar4) {
    do {
      FUN_201636cc(&DAT_2045f0c5 + iVar2 * 5 + uVar3 * 0x32,
                   &DAT_2045f0c5 + iVar2 * 5 + uVar3 * 0x32 + 5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  (&DAT_2045f224)[uVar3] = iVar4 + -1;
  FUN_201511e8(DAT_20450058);
  mainlink_send_enc(auStack_28);
  return;
}


// ===== mainlink_on_ack @ 2011606c (72 bytes)

/* 0x06 from MAIN: stop timeout, clear wait flag, flush parked frames */

void mainlink_on_ack(void)

{
  if (DAT_2045002a != '\0') {
    FUN_2014eb94(DAT_2045004c,0);
    FUN_20151878(DAT_20450064);
    DAT_2045002a = '\0';
    mainlink_flush_parked();
    if (DAT_2045002b != '\0') {
      mainlink_flush_enc();
    }
    DAT_2045002c = 0;
  }
  return;
}


// ===== mainlink_on_nak @ 201160b4 (140 bytes)

/* 0x15 from MAIN: resend at once (max 3), then give up */

void mainlink_on_nak(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_2045002a != '\0') {
    FUN_20151878(DAT_20450064);
    if (2 < DAT_2045002c) {
      if (DAT_20450029 != '\0') {
        uVar1 = mainlink_get_wait_cmd();
        gui_link_error_popup(0,uVar1);
        return;
      }
      system_reboot();
      return;
    }
    iVar2 = mainlink_get_wait_cmd();
    if (iVar2 == 0xe1) {
      mainlink_tx_e1_raw(&DAT_20450068);
    }
    else {
      mainlink_tx_raw(&DAT_2045efc0,DAT_20450038);
    }
    FUN_20151680(DAT_20450064);
    DAT_2045002c = DAT_2045002c + 1;
  }
  return;
}


// ===== mainlink_tx_reset @ 20116140 (124 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* drops the pending/parked state and the encoder queue (0x7F maintenance key, retry task) */

void mainlink_tx_reset(void)

{
  int iVar1;
  int iVar2;
  
  FUN_2014eb94(DAT_2045004c,0);
  FUN_20151878(DAT_20450064);
  DAT_2045002a = 0;
  iVar2 = 0;
  DAT_2045002b = 0;
  DAT_2045002c = 0;
  _DAT_2045f240 = 0;
  _DAT_2045f244 = 0;
  _DAT_2045f248 = 0;
  do {
    iVar1 = 0;
    do {
      FUN_20163668(&DAT_2045f0c5 + iVar1 * 5 + iVar2 * 0x32);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return;
}


// ===== task_mainlink_retry @ 201161bc (232 bytes)

void task_mainlink_retry(void)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_4;
  
  do {
    while( true ) {
      do {
        do {
          iVar1 = itron_twai_flg(DAT_2045004c,1,5,&iStack_4,0xffffffff);
          FUN_20151878(DAT_20450064);
        } while (iVar1 != 0);
      } while (iStack_4 != 1);
      if (DAT_2080049c == '\0') break;
      mainlink_tx_reset();
    }
    if (DAT_2045002a == '\0') {
      FUN_2014eb94(DAT_2045004c,0);
    }
    else if (DAT_2045002c < 3) {
      iVar1 = mainlink_get_wait_cmd();
      if (iVar1 == 0xe1) {
        mainlink_tx_e1_raw(&DAT_20450068);
      }
      else {
        mainlink_tx_raw(&DAT_2045efc0,DAT_20450038);
      }
      FUN_20151680(DAT_20450064);
      DAT_2045002c = DAT_2045002c + 1;
    }
    else if (DAT_20450029 == '\0') {
      system_reboot();
    }
    else {
      uVar2 = mainlink_get_wait_cmd();
      gui_link_error_popup(1,uVar2);
    }
  } while( true );
}


// ===== mainlink_send_hello @ 201162a4 (116 bytes)

/* F0 frame: version 01-08, date 2023-06-29, power-up key code */

void mainlink_send_hello(undefined1 param_1)

{
  undefined4 local_10;
  undefined3 local_c;
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = 0x200801f0;
  _local_c = CONCAT13(param_1,0x290623);
  mainlink_queue_frame(&local_10,9);
  return;
}


// ===== mainlink_send_f1 @ 20116334 (52 bytes)

/* F1 frame with one sub-command byte; no caller in V01-08 */

void mainlink_send_f1(undefined1 param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = (uint)CONCAT11(param_1,0xf1);
  mainlink_queue_frame(&local_10,7);
  return;
}

