// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== dsp_isp_fill_option @ 2010b5bc (608 bytes)

/* FillMemory 0x1C000, 4, 0xC0000002 */

uint dsp_isp_fill_option(int *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char local_50 [28];
  char local_34 [4];
  char local_30;
  char local_2b;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  
  __aeabi_memclr4(local_34,0x18);
  __aeabi_memclr4(local_50,0x1c);
  local_50[0] = 'Z';
  local_50[1] = 0x16;
  local_50[8] = 0;
  local_50[9] = 5;
  local_50[0xc] = 3;
  local_50[0xd] = 0;
  local_50[0xe] = 0xc0;
  local_50[0xf] = 1;
  local_50[0x10] = 0;
  local_50[2] = 0;
  local_50[0x11] = 4;
  local_50[3] = 0x5a;
  local_50[4] = 0xa4;
  local_50[0x14] = 0;
  local_50[0x18] = 0xc0;
  local_50[0x15] = 2;
  local_50[5] = 0x5a;
  local_50[10] = 0;
  local_50[0x12] = 0;
  local_50[0x16] = 0;
  local_50[6] = 0xa4;
  local_50[0xb] = 0;
  local_50[0x13] = 0;
  local_50[0x17] = 0;
  local_50[7] = 0x10;
  local_50[7] = crc16_xmodem((int)(local_50 + 5),0x14);
  local_50[4] = 0xa4;
  local_50[5] = 0x10;
  local_50[6] = 0;
  local_50[3] = 0x5a;
  local_50[8] = 0;
  iVar3 = 0;
  do {
    pcVar1 = local_50 + iVar3;
    iVar3 = iVar3 + 1;
    iVar4 = 0;
    local_50[0x19] = local_50[0x19] + *pcVar1;
  } while (iVar3 < 0x19);
  do {
    itron_dly_tsk(1);
    iVar3 = (**(code **)(*param_1 + 0x24))(param_1,local_50,0x1a);
    if (iVar3 != 0x1a) {
      return 0;
    }
    iVar3 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
    if (((((iVar3 != -1) && (local_34[0] == '\x06')) &&
         (iVar3 = (**(code **)(*param_1 + 0x18))(param_1,local_34,6,100), iVar3 != -1)) &&
        ((local_30 == -0x5f &&
         (iVar3 = (**(code **)(*param_1 + 0x18))(param_1,local_34,0x16,100), iVar3 != -1)))) &&
       (local_2b == -0x60)) {
      cVar2 = local_27;
      if (local_27 == '\0') {
        cVar2 = local_26;
      }
      if (local_27 != '\0' || cVar2 != '\0') {
        return 0;
      }
      cVar2 = local_25;
      if (local_25 == '\0') {
        cVar2 = local_24;
      }
      if (local_25 != '\0' || cVar2 != '\0') {
        return 0;
      }
      iVar3 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
      if (iVar3 != 6) {
        return 0;
      }
      iVar3 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
      if ((iVar3 != -1) && (local_34[0] == '\x06')) {
        return 1;
      }
    }
    iVar4 = iVar4 + 1;
    if (4 < iVar4) {
      return 0;
    }
  } while( true );
}


// ===== dsp_isp_program @ 2010b81c (320 bytes)

/* IFDSP: NXP ROM ISP over the MAIN relay */

uint dsp_isp_program(uint param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint local_18;
  uint uStack_14;
  
  local_18 = param_3;
  uStack_14 = param_4;
  progress_range_init(&local_18,5,10);
  DAT_20800178 = local_18;
  DAT_2080017c = uStack_14;
  DAT_2080016c = 0x1d1;
  itron_dly_tsk(1);
  uVar1 = progress_scale(&DAT_20800178,extraout_r1,0,0);
  progress_set(uVar1);
  if (param_5 == 0) {
    uVar1 = 0;
  }
  else {
    mainlink_rx_ctrl(1);
    piVar2 = scif5_get(0);
    uVar1 = progress_scale(&DAT_20800178);
    progress_set(uVar1);
    DAT_2080016c = 0x1e4;
    local_18 = 2;
    (**(code **)(*piVar2 + 4))(piVar2,0x54600,8,0);
    uVar1 = progress_scale(&DAT_20800178,extraout_r1_00,0,0x3fe00000);
    progress_set(uVar1);
    uVar3 = isp_relay_mode_cmd(piVar2,'\x02');
    uVar1 = 0;
    if ((((uVar3 != 0) && (uVar3 = dsp_isp_ping(piVar2), uVar1 = 0, uVar3 != 0)) &&
        (uVar3 = dsp_isp_fill_option(piVar2), uVar1 = 0, uVar3 != 0)) &&
       (((uVar3 = dsp_isp_configure_memory(piVar2), uVar1 = 0, uVar3 != 0 &&
         (uVar3 = dsp_isp_erase_region(piVar2), uVar1 = 0, uVar3 != 0)) &&
        ((uVar3 = dsp_isp_write_image(piVar2,param_1), uVar1 = 0, uVar3 != 0 &&
         (uVar3 = isp_relay_mode_cmd(piVar2,-0x7e), uVar1 = 0, uVar3 != 0)))))) {
      uVar1 = 1;
    }
  }
  return uVar1;
}


// ===== rx_boot_read_compare @ 2010b95c (380 bytes)

/* reads a block and memcmp with the expected data */

undefined4
rx_boot_read_compare
          (int *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          uint param_6)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_238 [3];
  byte local_235;
  undefined1 auStack_234 [516];
  undefined1 local_30 [3];
  undefined1 uStack_2d;
  undefined4 local_2c;
  
  __aeabi_memclr4(auStack_238,0x208);
  iVar2 = 0;
  while( true ) {
    _local_30 = CONCAT13((char)param_6,0x10081);
    local_2c = 0x300;
    sum8_neg_append((int)(local_30 + 1),3);
    itron_dly_tsk(1);
    do {
      iVar1 = (**(code **)(*param_1 + 0x10))(param_1,auStack_238,1);
    } while (iVar1 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,local_30,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(5);
    __aeabi_memclr4(auStack_238,0x208);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_238,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_235 != param_6) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_234,1);
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1,auStack_234,param_3 + 2,100);
  if (iVar2 == -1) {
    return 0;
  }
  if ((param_6 != 0x52) && (iVar2 = memcmp(auStack_234,param_4,param_3), iVar2 != 0)) {
    return 0;
  }
  return 1;
}


// ===== rx_boot_read_start @ 2010bb00 (416 bytes)

/* command packet for read-back */

uint rx_boot_read_start(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_88 [3];
  byte local_85;
  undefined1 auStack_84 [60];
  undefined1 local_48 [3];
  undefined1 uStack_45;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined4 uStack_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  
  __aeabi_memclr4(auStack_88,0x40);
  local_28 = 1;
  iVar3 = 0;
  local_2c = 0;
  local_30 = param_2 >> 0x18;
  local_34 = (param_2 & 0xffffff) >> 0x10;
  local_38 = (param_2 & 0xffff) >> 8;
  while( true ) {
    uStack_3c = 0x300;
    _local_48 = CONCAT13((char)param_4,0x90001);
    local_44 = CONCAT13((char)param_2,
                        CONCAT12((char)local_38,CONCAT11((char)local_34,(char)local_30)));
    _local_40 = CONCAT13((char)param_3,
                         CONCAT12((char)(param_3 >> 8),
                                  CONCAT11((char)(param_3 >> 0x10),(char)(param_3 >> 0x18))));
    sum8_neg_append((int)(local_48 + 1),0xb);
    itron_dly_tsk(1);
    do {
      iVar1 = (**(code **)(*param_1 + 0x10))(param_1,auStack_88,1);
    } while (iVar1 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,local_48,0xe);
    if (iVar1 != 0xe) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_88,4,100);
    if (iVar1 != -1) break;
    iVar3 = iVar3 + 1;
    if (local_28 <= iVar3) {
      uVar2 = 0;
      if (local_2c != 0) {
LAB_2010bc7c:
        (**(code **)(*param_1 + 0x18))(param_1,auStack_88,2,100);
        uVar2 = 1;
      }
      return uVar2;
    }
  }
  if (local_85 != param_4) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_84,1);
    return 0;
  }
  goto LAB_2010bc7c;
}


// ===== rx_boot_verify_areas @ 2010bca0 (744 bytes)

/* WARNING: Removing unreachable block (ram,0x2010be6c) */
/* boot cmd 0x15 / 0x52 read-back and compare */

undefined4 rx_boot_verify_areas(int *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  iVar10 = 0;
  iVar2 = work_buf_get(0);
  uVar11 = 0;
  do {
    if (param_2 <= uVar11) {
      return 1;
    }
    uVar9 = 0x20;
    iVar3 = param_3 + uVar11 * 0x1c;
    local_50 = *(uint *)(iVar3 + 0x14);
    iVar7 = param_3;
    if (local_50 != 0) {
      iVar7 = *(int *)(iVar3 + 0x18);
    }
    if ((local_50 != 0 && iVar7 != 0) && (cVar1 = *(char *)(param_3 + uVar11 * 0x1c), cVar1 != ' '))
    {
      if (cVar1 == '0') {
        uVar12 = 0x52;
      }
      else {
        uVar12 = 0x15;
        uVar9 = 0x200;
      }
      for (local_4c = 0; uVar6 = *(uint *)(iVar3 + 0x18),
          local_4c == 0 && (uVar6 <= local_50) <= local_4c; local_4c = local_4c + bVar13) {
        uVar8 = local_50 + 0x7ffff;
        local_44 = local_4c + (0xfff80000 < local_50);
        local_48 = uVar8;
        if ((uint)(uVar8 <= uVar6) <= -local_44) {
          local_44 = 0;
          local_48 = uVar6;
        }
        __aeabi_memset(iVar2,0x80000,0xff,uVar6 - uVar8);
        uVar6 = fs_fseek(param_4,0,0);
        if (uVar6 != 0) {
          return 0;
        }
        iVar7 = srec_load_range(param_4,local_50,local_48,iVar2,param_5);
        if (iVar7 < 0) {
          return 0;
        }
        if (iVar7 != 0) {
          uVar6 = local_50;
          uVar8 = local_4c;
          if (*(char *)(param_3 + uVar11 * 0x1c) == '0') {
            progress_set(100);
            uVar11 = rx_boot_read_start(param_1,local_50,local_50 + 0x2f,0x52);
            if (uVar11 == 0) {
              return 0;
            }
            rx_boot_read_compare(param_1,local_50,0x30,iVar2,1,0x52);
            uVar11 = rx_boot_read_start(param_1,local_50 + 0x40,local_50 + 0x7f,0x52);
            if (uVar11 != 0) {
              rx_boot_read_compare(param_1,local_50 + 0x40,0x40,iVar2 + 0x40,1,0x52);
              return 1;
            }
            return 0;
          }
          for (; uVar8 <= local_44 && (uint)(local_48 <= uVar6) <= uVar8 - local_44;
              uVar8 = uVar8 + ((int)uVar9 >> 0x1f) + (uint)bVar13) {
            uVar4 = uVar8 + ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar6,uVar9);
            bVar13 = uVar4 - local_44 < (uint)(local_48 <= uVar6 + uVar9);
            if (local_44 < uVar4 || bVar13) {
              uVar9 = (local_48 - uVar6) + 1;
            }
            uVar5 = rx_boot_read_start(param_1,uVar6,(uVar6 + uVar9) - 1,uVar12);
            if (uVar5 == 0) {
              return 0;
            }
            iVar7 = rx_boot_read_compare
                              (param_1,uVar6,uVar9,(uVar6 - local_50) + iVar2,
                               local_44 < uVar4 || bVar13,uVar12);
            if (iVar7 == 0) {
              return 0;
            }
            iVar10 = iVar10 + 1;
            iVar7 = __aeabi_uidivmod(iVar10 * 0x46,DAT_20800164);
            progress_set(iVar7 + 0x1e);
            bVar13 = CARRY4(uVar6,uVar9);
            uVar6 = uVar6 + uVar9;
          }
        }
        bVar13 = 0xfff7ffff < local_50;
        local_50 = local_50 + 0x80000;
      }
    }
    uVar11 = uVar11 + 1;
  } while( true );
}


// ===== rx_boot_data_packet @ 2010bf9c (432 bytes)

/* data packet 81 LNH LNL <cmd> data SUM 03/17 */

undefined4
rx_boot_data_packet(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                   uint param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_488;
  undefined1 uStack_487;
  undefined1 uStack_486;
  undefined1 uStack_485;
  undefined1 uStack_484;
  undefined1 auStack_483 [1027];
  undefined1 auStack_80 [3];
  byte local_7d;
  undefined1 auStack_7c [60];
  int local_40;
  int *piStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 local_2c;
  
  piStack_38 = param_1;
  uStack_34 = param_2;
  iStack_30 = param_3;
  local_2c = param_4;
  __aeabi_memclr4(auStack_80,0x40);
  iVar4 = 0;
  local_40 = 0;
  while( true ) {
    __aeabi_memclr4(&uStack_484,0x402);
    _local_488 = CONCAT13((char)param_6,
                          CONCAT12((char)(param_3 + 1),
                                   CONCAT11((char)((uint)(param_3 + 1) >> 8),0x81)));
    memcpy(&uStack_484,local_2c,param_3);
    sum8_neg_append((int)&uStack_487,param_3 + 3);
    if (param_5 == 0) {
      uVar1 = 0x17;
    }
    else {
      uVar1 = 3;
    }
    auStack_483[param_3] = uVar1;
    itron_dly_tsk(1);
    do {
      iVar2 = (**(code **)(*param_1 + 0x10))(param_1,auStack_80,1);
    } while (iVar2 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar2 = (**(code **)(*param_1 + 0x24))(param_1,&local_488,param_3 + 6);
    if (iVar2 != param_3 + 6) {
      return 0;
    }
    itron_dly_tsk(1);
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,auStack_80,4,100);
    if (iVar2 != -1) break;
    iVar4 = iVar4 + 1;
    if (0 < iVar4) {
      uVar3 = 0;
      if (local_40 != 0) {
LAB_2010c11c:
        itron_dly_tsk(1);
        (**(code **)(*param_1 + 0x18))(param_1,auStack_80,2,100);
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  if (local_7d != param_6) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_7c,1);
    return 0;
  }
  goto LAB_2010c11c;
}


// ===== rx_boot_write_start @ 2010c14c (424 bytes)

/* command packet 01 00 09 <cmd> start end */

uint rx_boot_write_start(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_88 [3];
  byte local_85;
  undefined1 auStack_84 [60];
  undefined1 local_48 [3];
  undefined1 uStack_45;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined4 uStack_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  
  __aeabi_memclr4(auStack_88,0x40);
  local_28 = 1;
  iVar3 = 0;
  local_2c = 0;
  local_30 = param_2 >> 0x18;
  local_34 = (param_2 & 0xffffff) >> 0x10;
  local_38 = (param_2 & 0xffff) >> 8;
  while( true ) {
    uStack_3c = 0x300;
    _local_48 = CONCAT13((char)param_4,0x90001);
    local_44 = CONCAT13((char)param_2,
                        CONCAT12((char)local_38,CONCAT11((char)local_34,(char)local_30)));
    _local_40 = CONCAT13((char)param_3,
                         CONCAT12((char)(param_3 >> 8),
                                  CONCAT11((char)(param_3 >> 0x10),(char)(param_3 >> 0x18))));
    sum8_neg_append((int)(local_48 + 1),0xb);
    itron_dly_tsk(1);
    do {
      iVar1 = (**(code **)(*param_1 + 0x10))(param_1,auStack_88,1);
    } while (iVar1 != 0);
    (**(code **)(*param_1 + 0x28))(param_1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,local_48,0xe);
    if (iVar1 != 0xe) {
      return 0;
    }
    itron_dly_tsk(1);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_88,4,100);
    if (iVar1 != -1) break;
    iVar3 = iVar3 + 1;
    if (local_28 <= iVar3) {
      uVar2 = 0;
      if (local_2c != 0) {
LAB_2010c2d0:
        (**(code **)(*param_1 + 0x18))(param_1,auStack_88,2,100);
        uVar2 = 1;
      }
      return uVar2;
    }
  }
  if (local_85 != param_4) {
    (**(code **)(*param_1 + 0x10))(param_1,auStack_84,1);
    return 0;
  }
  goto LAB_2010c2d0;
}


// ===== rx_boot_write_areas @ 2010c2f4 (624 bytes)

/* boot cmd 0x13 (512-byte blocks) / 0x51 (config area) */

undefined4 rx_boot_write_areas(int *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  
  iVar13 = 0;
  iVar2 = work_buf_get(0);
  uVar3 = 0;
  do {
    if (param_2 <= uVar3) {
      return 1;
    }
    iVar4 = param_3 + uVar3 * 0x1c;
    uVar8 = *(uint *)(iVar4 + 0x14);
    iVar5 = iVar4;
    if (uVar8 != 0) {
      iVar5 = *(int *)(iVar4 + 0x18);
    }
    if ((uVar8 != 0 && iVar5 != 0) && (*(char *)(param_3 + uVar3 * 0x1c) != ' ')) {
      for (uVar10 = 0; uVar7 = *(uint *)(iVar4 + 0x18), uVar10 == 0 && (uVar7 <= uVar8) <= uVar10;
          uVar10 = uVar10 + bVar14) {
        uVar11 = uVar10 + (0xfff80000 < uVar8);
        uVar1 = uVar8 + 0x7ffff;
        if ((uint)(uVar8 + 0x7ffff <= uVar7) <= -uVar11) {
          uVar11 = 0;
          uVar1 = uVar7;
        }
        __aeabi_memset(iVar2,0x80000,0xff);
        uVar7 = fs_fseek(param_4,0,0);
        if (uVar7 != 0) {
          return 0;
        }
        iVar5 = srec_load_range(param_4,uVar8,uVar1,iVar2,param_5);
        if (iVar5 < 0) {
          return 0;
        }
        if (iVar5 != 0) {
          if (*(char *)(param_3 + uVar3 * 0x1c) == '0') {
            uVar7 = rx_boot_write_start(param_1,uVar8,uVar8 + 0x2f,0x51);
            if (uVar7 == 0) {
              return 0;
            }
            iVar5 = rx_boot_data_packet(param_1,uVar8,0x30,iVar2,1,0x51);
            if (iVar5 == 0) {
              return 0;
            }
            uVar7 = rx_boot_write_start(param_1,uVar8 + 0x40,uVar8 + 0x7f,0x51);
            if (uVar7 == 0) {
              return 0;
            }
            iVar5 = rx_boot_data_packet(param_1,uVar8 + 0x40,0x40,iVar2 + 0x40,1,0x51);
            if (iVar5 == 0) {
              return 0;
            }
          }
          else {
            uVar12 = 0x200;
            uVar6 = rx_boot_write_start(param_1,uVar8,uVar1,0x13);
            uVar7 = uVar8;
            uVar9 = uVar10;
            if (uVar6 == 0) {
              return 0;
            }
            for (; uVar9 <= uVar11 && (uint)(uVar1 <= uVar7) <= uVar9 - uVar11;
                uVar9 = uVar9 + bVar14) {
              uVar6 = uVar9 + CARRY4(uVar7,uVar12);
              bVar14 = uVar6 - uVar11 < (uint)(uVar1 <= uVar7 + uVar12);
              if (uVar11 < uVar6 || bVar14) {
                uVar12 = (uVar1 - uVar7) + 1;
              }
              iVar5 = rx_boot_data_packet(param_1,uVar7,uVar12,(uVar7 - uVar8) + iVar2,
                                          uVar11 < uVar6 || bVar14,0x13);
              if (iVar5 == 0) {
                return 0;
              }
              iVar13 = iVar13 + 1;
              uVar6 = __aeabi_uidivmod(iVar13 * 0x14,DAT_20800164);
              if (uVar6 < 0x14) {
                progress_set(uVar6 + 10);
              }
              bVar14 = CARRY4(uVar7,uVar12);
              uVar7 = uVar7 + uVar12;
            }
          }
        }
        bVar14 = 0xfff7ffff < uVar8;
        uVar8 = uVar8 + 0x80000;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}


// ===== rx_boot_erase @ 2010c564 (328 bytes)

/* boot cmd 0x50 (argument 0) */

uint rx_boot_erase(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_70 [3];
  char local_6d;
  undefined1 auStack_6c [60];
  undefined4 local_30;
  undefined1 local_2c;
  undefined3 uStack_2b;
  undefined4 local_28 [2];
  undefined4 local_20 [2];
  
  __aeabi_memclr4(auStack_70,0x40);
  iVar3 = 1;
  local_20[0] = 0x20;
  local_28[0] = 0x1400;
  local_28[1] = 0x9000;
  do {
    iVar4 = 0;
    while( true ) {
      if (0 < iVar4) {
        return 0;
      }
      local_30 = 0x50020001;
      _local_2c = CONCAT31(0x300,*(undefined1 *)((int)local_20 + iVar3));
      sum8_neg_append((int)&local_30 + 1,4);
      itron_dly_tsk(2);
      iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_30,7);
      if (iVar1 != 7) {
        return 0;
      }
      itron_dly_tsk(2);
      uVar2 = __aeabi_uidivmod(local_28[iVar3],10);
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_70,4,uVar2);
      if (iVar1 != -1) break;
      iVar4 = iVar4 + 1;
    }
    if (local_6d != 'P') {
      (**(code **)(*param_1 + 0x10))(param_1,auStack_6c,1);
      return 0;
    }
    itron_dly_tsk(2);
    (**(code **)(*param_1 + 0x18))(param_1,auStack_70,2,100);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return 1;
}


// ===== rx_boot_area_info @ 2010c6ac (588 bytes)

/* boot cmd 0x54 per area: type, start, end, unit sizes */

uint rx_boot_area_info(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_78 [3];
  char local_75;
  undefined1 local_74;
  undefined1 auStack_73 [4];
  undefined1 auStack_6f [4];
  undefined1 auStack_6b [4];
  undefined1 auStack_67 [4];
  undefined1 auStack_63 [43];
  undefined4 local_38;
  undefined1 local_34;
  undefined3 uStack_33;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  __aeabi_memclr4(auStack_78,0x40);
  uVar2 = 0;
LAB_2010c8f4:
  if (param_2 <= uVar2) {
    return 1;
  }
  iVar3 = 0;
  do {
    if (0 < iVar3) {
      return 0;
    }
    local_38 = 0x54020001;
    _local_34 = CONCAT31(0x300,(char)uVar2);
    local_30 = 0x54010081;
    uStack_2c = 0x3ab;
    sum8_neg_append((int)&local_38 + 1,4);
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_38,7);
    if (iVar1 != 7) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_78,4,100);
    if (iVar1 != -1) {
      if (local_75 != 'T') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_74,2,100);
      if (iVar1 != -1) {
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_30,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        __aeabi_memset(auStack_78,0x40,0xaa);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_78,4,100);
        if (iVar1 != -1) {
          if (local_75 != 'T') {
            (**(code **)(*param_1 + 0x18))(param_1,&local_74,1,100);
            return 0;
          }
          itron_dly_tsk(10);
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_74,0x11,200);
          if (iVar1 != -1) break;
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
  *(undefined1 *)(param_3 + uVar2 * 0x1c) = local_74;
  iVar3 = be_bytes_to_u32((int)auStack_73,4);
  iVar1 = param_3 + uVar2 * 0x1c;
  *(int *)(iVar1 + 4) = iVar3;
  iVar3 = be_bytes_to_u32((int)auStack_6f,4);
  *(int *)(iVar1 + 8) = iVar3;
  iVar3 = be_bytes_to_u32((int)auStack_6b,4);
  *(int *)(iVar1 + 0xc) = iVar3;
  iVar3 = be_bytes_to_u32((int)auStack_67,4);
  *(int *)(iVar1 + 0x10) = iVar3;
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_63,2,100);
  uVar2 = uVar2 + 1;
  goto LAB_2010c8f4;
}


// ===== rx_boot_area_count @ 2010c918 (412 bytes)

/* boot cmd 0x53 */

uint rx_boot_area_count(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_68 [3];
  char local_65;
  byte local_64 [60];
  undefined4 local_28;
  undefined4 uStack_24;
  
  __aeabi_memclr4(auStack_68,0x40);
  iVar2 = 0;
  do {
    local_28 = 0x53010001;
    uStack_24 = 0x3ac;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
    if (iVar1 != -1) {
      if (local_65 != 'S') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_64,2,100);
      if (iVar1 != -1) {
        local_28 = CONCAT31(local_28._1_3_,0x81);
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
        if (iVar1 != -1) {
          if (local_65 != 'S') {
            return 0;
          }
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,local_64,1,100);
          if (iVar1 != -1) {
            *param_2 = (uint)local_64[0];
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_68,2,100);
            return 1;
          }
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_id_auth @ 2010cab4 (256 bytes)

/* boot cmd 0x30 with 16 x 0xFF ID code */

uint rx_boot_id_auth(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_70 [3];
  char local_6d;
  undefined1 auStack_6c [60];
  undefined1 auStack_30 [24];
  
  __aeabi_memclr4(auStack_70,0x40);
  iVar2 = 0;
  while( true ) {
    __aeabi_memcpy4(auStack_30,DWORD_ARRAY_2010cbbc,0x18);
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,auStack_30,0x16);
    if (iVar1 != 0x16) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_70,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_6d != '0') {
    (**(code **)(*param_1 + 0x18))(param_1,auStack_6c,4,100);
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_70,2,100);
  return 1;
}


// ===== rx_boot_cmd_2c @ 2010cbd4 (400 bytes)

/* boot cmd 0x2C, 1-byte answer */

uint rx_boot_cmd_2c(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined1 auStack_5c [60];
  undefined4 local_20;
  undefined4 uStack_1c;
  
  __aeabi_memclr4(auStack_60,0x40);
  iVar2 = 0;
  do {
    local_20 = 0x2c010001;
    uStack_1c = 0x3d3;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) {
      if (local_5d != ',') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,2,100);
      if (iVar1 != -1) {
        local_20 = CONCAT31(local_20._1_3_,0x81);
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
        if (iVar1 != -1) {
          if (local_5d != ',') {
            return 0;
          }
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,1,100);
          if (iVar1 != -1) {
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
            return 1;
          }
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_sync_cmd @ 2010cd64 (224 bytes)

/* boot cmd 0x00 */

uint rx_boot_sync_cmd(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  __aeabi_memclr4(auStack_60,0x40);
  iVar2 = 0;
  while( true ) {
    local_20 = 0x10001;
    uStack_1c = 0x3ff;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_5d != '\0') {
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
  return 1;
}


// ===== rx_boot_set_baud @ 2010ce54 (244 bytes)

/* boot cmd 0x34: 345600 bps */

uint rx_boot_set_baud(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_68 [3];
  char local_65;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  __aeabi_memclr4(auStack_68,0x40);
  iVar2 = 0;
  while( true ) {
    local_28 = 0x34050001;
    uStack_24 = 0x460500;
    uStack_20 = 0x304;
    sum8_neg_append((int)&local_28 + 1,7);
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,10);
    if (iVar1 != 10) {
      return 0;
    }
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_65 != '4') {
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_68,2,100);
  return 1;
}


// ===== rx_boot_set_freq @ 2010cf48 (464 bytes)

/* boot cmd 0x32: 16 MHz input, 120 MHz system */

uint rx_boot_set_freq(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_68 [3];
  char local_65;
  undefined1 auStack_64 [60];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  __aeabi_memclr4(auStack_68,0x40);
  iVar4 = 0;
  do {
    local_28 = 0x32090001;
    uStack_24 = 0x24f400;
    uStack_20 = 0xe2707;
    uStack_1c = 0x371;
    itron_dly_tsk(2);
    iVar3 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,0xe);
    if (iVar3 != 0xe) {
      return 0;
    }
    itron_dly_tsk(2);
    __aeabi_memset(auStack_68,0x40,0xff);
    iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
    if (iVar3 != -1) {
      if (local_65 != '2') {
        return 0;
      }
      iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_64,2,100);
      uVar1 = local_28;
      if (iVar3 != -1) {
        local_28 = CONCAT31(local_28._1_3_,0x81);
        uVar2 = local_28;
        local_28._3_1_ = SUB41(uVar1,3);
        local_28._0_3_ = CONCAT12(1,(short)uVar2);
        sum8_neg_append((int)&local_28 + 1,3);
        uStack_24._0_2_ = CONCAT11(3,(undefined1)uStack_24);
        itron_dly_tsk(2);
        iVar3 = (**(code **)(*param_1 + 0x24))(param_1,&local_28,6);
        if (iVar3 != 6) {
          return 0;
        }
        itron_dly_tsk(2);
        __aeabi_memset(auStack_68,0x40,0xff);
        iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_68,4,100);
        if (iVar3 != -1) {
          if (local_65 != '2') {
            return 0;
          }
          iVar3 = (**(code **)(*param_1 + 0x18))(param_1,auStack_64,8,100);
          if (iVar3 != -1) {
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_68,2,100);
            return 1;
          }
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (0 < iVar4) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_endian @ 2010d134 (240 bytes)

/* boot cmd 0x36 (01) */

uint rx_boot_endian(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  __aeabi_memclr4(auStack_60,0x40);
  iVar2 = 0;
  while( true ) {
    local_20 = 0x36020001;
    uStack_1c = 0x3c701;
    itron_dly_tsk(2);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,7);
    if (iVar1 != 7) {
      return 0;
    }
    itron_dly_tsk(2);
    __aeabi_memset(auStack_60,0x40,0xff);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) break;
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  }
  if (local_5d != '6') {
    return 0;
  }
  itron_dly_tsk(2);
  (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
  return 1;
}


// ===== rx_boot_signature @ 2010d224 (432 bytes)

/* boot cmd 0x38 */

uint rx_boot_signature(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [3];
  char local_5d;
  undefined1 auStack_5c [60];
  undefined4 local_20;
  undefined4 uStack_1c;
  
  __aeabi_memclr4(auStack_60,0x40);
  iVar2 = 0;
  do {
    local_20 = 0x38010001;
    uStack_1c = 0x3c7;
    itron_dly_tsk(5);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
    if (iVar1 != 6) {
      return 0;
    }
    itron_dly_tsk(2);
    __aeabi_memset(auStack_60,0x40,0xff);
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
    if (iVar1 != -1) {
      if (local_5d != '8') {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,2,100);
      if (iVar1 != -1) {
        local_20 = CONCAT31(local_20._1_3_,0x81);
        itron_dly_tsk(2);
        iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_20,6);
        if (iVar1 != 6) {
          return 0;
        }
        itron_dly_tsk(10);
        __aeabi_memset(auStack_60,0x40,0xff);
        iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_60,4,100);
        if (iVar1 != -1) {
          if (local_5d != '8') {
            return 0;
          }
          iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_5c,0x18,100);
          if (iVar1 != -1) {
            itron_dly_tsk(2);
            (**(code **)(*param_1 + 0x18))(param_1,auStack_60,2,100);
            return 1;
          }
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (0 < iVar2) {
      return 0;
    }
  } while( true );
}


// ===== rx_boot_sync @ 2010d3e4 (296 bytes)

/* 0x00 / 0x55 auto-baud at 9600 */

uint rx_boot_sync(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint local_70;
  undefined1 auStack_6c [60];
  int local_30;
  byte local_2c [12];
  
  __aeabi_memclr4(auStack_6c,0x3c);
  local_70 = 0xff;
  local_30 = 0;
  bVar1 = false;
  iVar2 = 0;
  local_2c[4] = 0;
  local_2c[5] = 0x55;
  local_2c[6] = 0;
  local_2c[7] = 0;
  local_2c[0] = 0;
  local_2c[1] = 0xc2;
  local_2c[2] = 0;
  local_2c[3] = 0;
  do {
    for (iVar3 = 0; iVar3 < 0x1e; iVar3 = iVar3 + 1) {
      itron_dly_tsk(1);
      local_30 = (**(code **)(*param_1 + 0x24))(param_1,local_2c + iVar2 + 4,1);
      if (local_30 != 1) {
        return 0;
      }
      itron_dly_tsk(2);
      local_30 = (**(code **)(*param_1 + 0x18))(param_1,&local_70,1,2);
      if (local_30 != -1) {
        if ((local_70 & 0xff) == (uint)local_2c[iVar2]) {
          bVar1 = true;
          goto LAB_2010d4c8;
        }
        break;
      }
    }
    if (!bVar1) {
      return 0;
    }
LAB_2010d4c8:
    itron_dly_tsk(2);
    (**(code **)(*param_1 + 0x18))(param_1,&local_70,4,100);
    iVar2 = iVar2 + 1;
    if (1 < iVar2) {
      return 1;
    }
  } while( true );
}


// ===== rx_boot_program @ 2010d50c (1040 bytes)

/* RX651 boot-mode programming of the decoded S-record */

undefined4 rx_boot_program(uint param_1,uint *param_2)

{
  char *pcVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  bool bVar10;
  uint *local_130;
  uint *puStack_12c;
  char local_128 [4];
  int aiStack_124 [55];
  char local_48 [12];
  uint local_3c;
  char local_38 [4];
  uint local_34;
  uint local_30;
  uint local_2c;
  uint *puStack_28;
  
  uVar7 = 0;
  local_38[0] = '\0';
  local_130 = (uint *)0x0;
  local_2c = param_1;
  puStack_28 = param_2;
  progress_range_init(&local_130,0,100);
  DAT_20800178 = local_130;
  DAT_2080017c = puStack_12c;
  piVar2 = scif5_get(0);
  local_130 = (uint *)0x1;
  (**(code **)(*piVar2 + 4))(piVar2,0x2580,8,0);
  uVar3 = rx_boot_sync(piVar2);
  uVar6 = 0;
  if (uVar3 != 0) {
    uVar3 = rx_boot_signature(piVar2);
    uVar6 = 0;
    if (uVar3 != 0) {
      uVar3 = rx_boot_endian(piVar2);
      uVar6 = 0;
      if (uVar3 != 0) {
        uVar3 = rx_boot_set_freq(piVar2);
        uVar6 = 0;
        if (uVar3 != 0) {
          progress_set(5);
          uVar3 = rx_boot_set_baud(piVar2);
          uVar6 = 0;
          if (uVar3 != 0) {
            (**(code **)(*piVar2 + 8))(piVar2);
            local_130 = (uint *)0x1;
            (**(code **)(*piVar2 + 4))(piVar2,0x54600,8,0);
            itron_dly_tsk(0x32);
            progress_set(6);
            uVar3 = rx_boot_sync_cmd(piVar2);
            uVar6 = 0;
            if (uVar3 != 0) {
              progress_set(7);
              uVar3 = rx_boot_cmd_2c(piVar2);
              uVar6 = 0;
              if (uVar3 != 0) {
                uVar3 = rx_boot_id_auth(piVar2);
                uVar6 = 0;
                if (uVar3 != 0) {
                  progress_set(8);
                  local_3c = 0;
                  uVar3 = rx_boot_area_count(piVar2,&local_3c);
                  uVar6 = 0;
                  if (uVar3 != 0) {
                    progress_set(9);
                    __aeabi_memclr4(local_128,0xe0);
                    uVar3 = rx_boot_area_info(piVar2,local_3c,(int)local_128);
                    uVar6 = 0;
                    if (uVar3 != 0) {
                      DAT_20800164 = 0;
                      for (; uVar7 < local_3c; uVar7 = uVar7 + 1) {
                        local_34 = 0;
                        local_30 = 0;
                        uVar3 = fs_fseek(local_2c,0,0);
                        if (uVar3 != 0) {
                          return 0;
                        }
                        if (local_128[uVar7 * 0x1c] != '@') {
                          local_130 = &local_30;
                          puStack_12c = param_2;
                          srec_find_range(local_2c,aiStack_124[uVar7 * 7],aiStack_124[uVar7 * 7 + 1]
                                          ,&local_34);
                          uVar3 = local_30;
                          if (local_34 <= local_30) {
                            iVar9 = aiStack_124[uVar7 * 7 + 3];
                            iVar5 = __aeabi_uidivmod(local_34,iVar9);
                            aiStack_124[uVar7 * 7 + 4] = iVar5 * iVar9;
                            iVar4 = __aeabi_uidivmod(uVar3,iVar9);
                            iVar4 = iVar4 * iVar9 + iVar9 + -1;
                            aiStack_124[uVar7 * 7 + 5] = iVar4;
                            uVar3 = (iVar4 - iVar5 * iVar9) + 1;
                            DAT_20800164 = DAT_20800164 +
                                           ((int)(uVar3 + ((uint)((int)uVar3 >> 0x1f) >> 0x17)) >> 9
                                           );
                            if ((uVar3 & 0x1ff) != 0) {
                              DAT_20800164 = DAT_20800164 + 1;
                            }
                          }
                        }
                      }
                      uVar3 = rx_boot_erase(piVar2);
                      uVar6 = 0;
                      if (uVar3 != 0) {
                        progress_set(10);
                        local_130 = param_2;
                        iVar5 = rx_boot_write_areas(piVar2,local_3c,local_128,local_2c);
                        uVar6 = 0;
                        if (iVar5 != 0) {
                          local_130 = param_2;
                          iVar5 = rx_boot_verify_areas(piVar2,local_3c,local_128,local_2c);
                          uVar6 = 0;
                          if (iVar5 != 0) {
                            progress_set(100);
                            gpio_rx_update(0);
                            itron_dly_tsk(10);
                            gpio_rx_reset(0);
                            itron_dly_tsk(10);
                            gpio_rx_reset(1);
                            itron_dly_tsk(500);
                            (**(code **)(*piVar2 + 8))(piVar2);
                            local_130 = (uint *)0x2;
                            pcVar8 = *(code **)(*piVar2 + 4);
                            (*pcVar8)(piVar2,0x54600,8,0);
                            local_48[0] = -0x10;
                            local_48[1] = 1;
                            local_48[2] = 8;
                            local_48[3] = 0x20;
                            local_48[4] = 0x23;
                            local_48[5] = 6;
                            local_48[8] = 0;
                            local_48[9] = '\0';
                            local_48[6] = 0x29;
                            local_48[7] = 6;
                            iVar5 = 0;
                            do {
                              pcVar1 = local_48 + iVar5;
                              iVar5 = iVar5 + 1;
                              if (8 < iVar5) {
                                pcVar8 = (code *)0x1e;
                              }
                              local_48[9] = local_48[9] + *pcVar1;
                            } while (iVar5 < 9);
                            do {
                              bVar10 = pcVar8 == (code *)0x0;
                              pcVar8 = pcVar8 + -1;
                              if ((bVar10) ||
                                 (local_130 = (uint *)(**(code **)(*piVar2 + 0x24))
                                                                (piVar2,local_48,10),
                                 local_130 != (uint *)0xa)) {
                                return 0;
                              }
                              iVar5 = (**(code **)(*piVar2 + 0x18))(piVar2,local_38,1,5);
                            } while ((iVar5 == -1) || (local_38[0] != '\x06'));
                            uVar6 = 1;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar6;
}


// ===== update_dsp @ 2010d92c (316 bytes)

/* I:\AH076H_IFDSP.dat, I:\rom_writer.dat, AFDSP */

undefined8 update_dsp(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 uVar9;
  int local_34;
  uint local_2c;
  
  local_34 = param_2;
  local_2c = param_4;
  do {
    do {
      uVar9 = 0xffffffff;
      pvVar2 = itron_twai_flg(DAT_20800168,0xffff,5,&local_2c,-1);
      if (pvVar2 != (void *)0x0) {
        return CONCAT44(local_34,uVar9);
      }
    } while ((local_2c & 7) == 0);
    kbd_led_status(0,7);
    local_34 = -((int)(local_2c << 0x1e) >> 0x1f);
    uVar6 = local_2c & 1;
    uVar7 = -((int)(local_2c << 0x10) >> 0x1f);
    uVar1 = local_2c & 0x1f;
    iVar5 = local_2c << 0x1d;
    pcVar4 = (char *)&DWORD_2010dbe0;
    while( true ) {
      kbd_led_status(0,7);
      itron_dly_tsk(100);
      kbd_led_status(1,7);
      if (uVar7 == 0) {
        if (uVar6 == 0 && local_34 == 0) {
          if (iVar5 < 0) {
            pcVar4 = "I:\\AH068_AFDSP_V0000.dat";
          }
        }
        else {
          pcVar4 = "I:\\AH076H_IFDSP.dat";
        }
      }
      else {
        pcVar4 = "I:\\rom_writer.dat";
      }
      uVar3 = fs_fopen((uint)pcVar4,0x2010dc28);
      if (uVar3 != 0) break;
      itron_dly_tsk(5);
    }
    if ((iVar5 < 0) && (DAT_2045001d = '\x01', DAT_2045001c == '\0')) {
      iVar5 = 0x1e;
      do {
        bVar8 = iVar5 == 0;
        iVar5 = iVar5 + -1;
        if (bVar8) break;
        itron_dly_tsk(10);
      } while (DAT_2045001d == '\x01');
    }
    dsp_isp_program(uVar3,0,uVar7,uVar1 >> 4,uVar6);
    fs_fclose(uVar3);
  } while( true );
}


// ===== FUN_2010da68 @ 2010da68 (16 bytes)

void FUN_2010da68(void)

{
  DAT_20800160 = 1;
  return;
}


// ===== dsp_debug_cmd @ 2010da78 (344 bytes)

/* dsp1up..dsp3up commands */

void dsp_debug_cmd(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if (DAT_20800160 == '\0') {
    return;
  }
  puVar1 = (uint *)hid_line_edit(&DAT_2081128c,param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return;
  }
  uVar2 = strcmp((uint *)"dsp1up",puVar1);
  if (((((uVar2 != 0) && (uVar2 = strcmp((uint *)"dsp2up",puVar1), uVar2 != 0)) &&
       (uVar2 = strcmp((uint *)"dsp3up",puVar1), uVar2 != 0)) &&
      ((((uVar2 = strcmp((uint *)"dsp1up/32",puVar1), uVar2 != 0 &&
         (uVar2 = strcmp((uint *)"dsp2up/32",puVar1), uVar2 != 0)) &&
        ((uVar2 = strcmp((uint *)"dsp3up/32",puVar1), uVar2 != 0 &&
         ((uVar2 = strcmp((uint *)"dsp1up/9",puVar1), uVar2 != 0 &&
          (uVar2 = strcmp((uint *)"dsp2up/9",puVar1), uVar2 != 0)))))) &&
       (uVar2 = strcmp((uint *)"dsp3up/9",puVar1), uVar2 != 0)))) &&
     (((uVar2 = strcmp((uint *)"dsp1up/32/9",puVar1), uVar2 != 0 &&
       (uVar2 = strcmp((uint *)"dsp2up/32/9",puVar1), uVar2 != 0)) &&
      (uVar2 = strcmp((uint *)"dsp3up/32/9",puVar1), uVar2 != 0)))) {
    return;
  }
  itron_set_flg(DAT_20800168);
  return;
}


// ===== dspup_init @ 2010dcbc (92 bytes)

/* task "dspup" */

undefined8 dspup_init(void)

{
  uint uVar1;
  code *pcVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  uVar1 = itron_acre_flg(0,(byte *)&local_10);
  if (0 < (int)uVar1) {
    DAT_20800168 = uVar1;
    uVar1 = itron_acre_tsk(0,(byte *)&ctsk_dspup);
    if ((0 < (int)uVar1) && (uVar1 = itron_sta_tsk(uVar1,0), uVar1 == 0)) {
      pcVar2 = dsp_debug_cmd;
      goto LAB_2010dd14;
    }
  }
  pcVar2 = (code *)0x0;
LAB_2010dd14:
  return CONCAT44(local_10,pcVar2);
}


// ===== fwobj_create_all @ 2010dd24 (180 bytes)

/* builds the 4 update objects at 0x2081166C (MAIN, DISPLAY, IFDSP, SDR) */

void fwobj_create_all(void)

{
  __aeabi_memclr4(&DAT_208112c0,0xac);
  __aeabi_memclr4(&DAT_20811380,0xac);
  __aeabi_memclr4(&DAT_20811440,0xac);
  __aeabi_memclr4(&DAT_20811500,0xac);
  __aeabi_memclr4(&DAT_208115c0,0xac);
  DAT_2081166c = fwobj_main_ctor(0x208115c0);
  __aeabi_memclr4(&DAT_20811380,0xac);
  DAT_20811670 = fwobj_display_ctor(0x20811380);
  DAT_20811674 = fwobj_ifdsp_ctor(0x20811440,1);
  DAT_20811678 = fwobj_sdr_ctor(0x20811500,1);
  return;
}


// ===== fwfile_check_versions @ 2010ddd8 (352 bytes)

/* matches FT-710_{MAIN,DISPLAY,IFDSP,SDR}_V* files on SD */

void fwfile_check_versions(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_28 [16];
  
  fwobj_create_all();
  uVar1 = copy10(auStack_28,"MAIN");
  memcpy(DAT_2081166c + 4,uVar1,10);
  uVar1 = copy10(auStack_28,"DISPLAY");
  memcpy(DAT_20811670 + 4,uVar1,10);
  uVar1 = copy10(auStack_28,"DSP");
  memcpy(DAT_20811674 + 4,uVar1,10);
  uVar1 = copy10(auStack_28,"SDR");
  memcpy(DAT_20811678 + 4,uVar1,10);
  fwname_pattern_init((int *)(DAT_2081166c + 0x14),0x2010df70,0x2010df68);
  fwname_pattern_init((int *)(DAT_20811670 + 0x14),0x2010df80,0x2010df68);
  fwname_pattern_init((int *)(DAT_20811674 + 0x14),0x2010df94,0x2010df68);
  fwname_pattern_init((int *)(DAT_20811678 + 0x14),0x2010dfa4,0x2010df68);
  iVar2 = 0;
  do {
    *(undefined1 *)(param_1 + iVar2 * 0x48) = 0;
    fwobj_set_status((&DAT_2081166c)[iVar2],0x2010dfb4);
    iVar3 = param_1 + iVar2 * 0x48;
    strcpy(iVar3 + 0x15,(&DAT_2081166c)[iVar2] + 0x89);
    *(undefined1 *)((&DAT_2081166c)[iVar2] + 0xa9) = 0;
    *(undefined4 *)(iVar3 + 0x34) = 0;
    *(undefined4 *)(iVar3 + 0x38) = 0;
    fwobj_version_text((&DAT_2081166c)[iVar2],iVar3 + 1);
    FUN_201635b8((&DAT_2081166c)[iVar2],iVar3 + 0x29);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return;
}


// ===== fwupdate_set_hotkey @ 2010dfc4 (12 bytes)

/* stores the held USB key usage (0x3A = F1 enables #UP0 loader files) */

void fwupdate_set_hotkey(byte param_1)

{
  DAT_20800181 = param_1;
  return;
}


// ===== fwfile_status_text @ 2010dfd0 (484 bytes)

/* Ready / (Broken file) / (No such file) */

uint fwfile_status_text(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    iVar1 = iVar5 + 1;
    *(undefined1 *)(param_1 + iVar5 * 0x48) = 2;
    iVar5 = iVar1;
  } while (iVar1 < 4);
  uVar2 = fs_opendir("I:\\FT-710");
  iVar5 = 0;
  do {
    FUN_2016040c((&DAT_2081166c)[iVar5]);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  do {
    do {
      piVar3 = (int *)fs_readdir(uVar2);
      if (piVar3 == (int *)0x0) {
        fs_closedir(uVar2);
        iVar5 = 0;
        do {
          if (*(char *)((&DAT_2081166c)[iVar5] + 0x57) == '\0') {
            *(undefined1 *)(param_1 + iVar5 * 0x48) = 2;
            fwobj_set_status((&DAT_2081166c)[iVar5],0x2010e1e8);
            *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9) = 2;
          }
          else {
            fwobj_version_from_name((&DAT_2081166c)[iVar5]);
            fwobj_build_path((&DAT_2081166c)[iVar5],0x2010e1c4);
            iVar1 = (*(code *)**(undefined4 **)(&DAT_2081166c)[iVar5])
                              ((undefined4 *)(&DAT_2081166c)[iVar5],0);
            *(char *)((&DAT_2081166c)[iVar5] + 0x36) = (char)iVar1;
            if (iVar1 == 0) {
              *(undefined1 *)(param_1 + iVar5 * 0x48) = 1;
              fwobj_set_status((&DAT_2081166c)[iVar5],0x2010e1e0);
              *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9) = 1;
            }
            else {
              *(undefined1 *)(param_1 + iVar5 * 0x48) = 3;
              fwobj_set_status((&DAT_2081166c)[iVar5],0x2010e1d0);
              *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9) = 3;
            }
          }
          iVar1 = param_1 + iVar5 * 0x48;
          fwobj_version_text((&DAT_2081166c)[iVar5],iVar1 + 1);
          strcpy(iVar1 + 0x15,(&DAT_2081166c)[iVar5] + 0x89);
          FUN_201635b8((&DAT_2081166c)[iVar5],iVar1 + 0x29);
          FUN_20163770(iVar1 + 0x3c,(&DAT_2081166c)[iVar5] + 0x2c);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 4);
        return 0;
      }
      iVar5 = fs_attr_check((int)*(char *)(*piVar3 + 0xb),0x20);
    } while (iVar5 != 0);
    iVar5 = 0;
    do {
      if ((param_2 == 0) || (*(int *)(param_1 + iVar5 * 0x48 + 0x34) != 0)) {
        uVar4 = strlen((int)piVar3 + 10);
        uVar4 = fwobj_match_name((&DAT_2081166c)[iVar5],(int)piVar3 + 10,uVar4);
        if (uVar4 != 0) break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  } while( true );
}


// ===== task_fwupdate @ 2010e1f8 (200 bytes)

void task_fwupdate(void)

{
  void *pvVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint auStack_2c [2];
  
  while (pvVar1 = itron_twai_flg(DAT_20800188,0xffff,5,auStack_2c,-1), pvVar1 == (void *)0x0) {
    iVar4 = 0;
    do {
      if (*(char *)((&DAT_2081166c)[iVar4] + 0x88) != '\0') {
        *(undefined1 *)((&DAT_2081166c)[iVar4] + 0xa9) = 4;
        progress_set(0);
        iVar2 = (*(code *)**(undefined4 **)(&DAT_2081166c)[iVar4])
                          ((undefined4 *)(&DAT_2081166c)[iVar4],0,1);
        if (iVar2 == 0) {
          pcVar3 = "Finished";
          *(undefined1 *)((&DAT_2081166c)[iVar4] + 0xa9) = 5;
        }
        else {
          pcVar3 = "failed";
          *(undefined1 *)((&DAT_2081166c)[iVar4] + 0xa9) = 6;
        }
        fwobj_set_status((&DAT_2081166c)[iVar4],(uint)pcVar3);
        *(undefined1 *)((&DAT_2081166c)[iVar4] + 0xaa) = 1;
      }
      itron_rot_rdq(0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
  }
  return;
}


// ===== fwupdate_poll @ 2010e2d4 (440 bytes)

/* starts task_fwupdate once, then 0 running / 1 all OK / 2 any failed */

byte fwupdate_poll(int param_1)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (DAT_20800180 == '\0') {
    iVar5 = 0;
    do {
      if ((*(char *)(param_1 + iVar5 * 0x48) == '\x01') &&
         (*(int *)(param_1 + iVar5 * 0x48 + 0x34) == 0)) {
        fwobj_set_status((&DAT_2081166c)[iVar5],0x2010e48c);
      }
      fwobj_select((&DAT_2081166c)[iVar5],*(int *)(param_1 + iVar5 * 0x48 + 0x34) != 0);
      if (*(char *)((&DAT_2081166c)[iVar5] + 0x88) != '\0') {
        fwobj_set_status((&DAT_2081166c)[iVar5],0x2010e498);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    DAT_20800180 = '\x01';
    itron_set_flg(DAT_20800188,1);
    iVar5 = 0;
    do {
      iVar6 = param_1 + iVar5 * 0x48;
      strcpy(iVar6 + 0x15,(&DAT_2081166c)[iVar5] + 0x89);
      uVar4 = progress_get();
      *(uint *)(iVar6 + 0x38) = uVar4;
      fwobj_version_text((&DAT_2081166c)[iVar5],iVar6 + 1);
      FUN_201635b8((&DAT_2081166c)[iVar5],iVar6 + 0x29);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  else {
    itron_rot_rdq(0);
    iVar5 = 0;
    do {
      iVar6 = param_1 + iVar5 * 0x48;
      strcpy(iVar6 + 0x15,(&DAT_2081166c)[iVar5] + 0x89);
      *(undefined1 *)(param_1 + iVar5 * 0x48) = *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9);
      uVar4 = progress_get();
      *(uint *)(iVar6 + 0x38) = uVar4;
      fwobj_version_text((&DAT_2081166c)[iVar5],iVar6 + 1);
      FUN_201635b8((&DAT_2081166c)[iVar5],iVar6 + 0x29);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    bVar2 = false;
    bVar1 = true;
    iVar5 = 0;
    do {
      if (*(char *)((&DAT_2081166c)[iVar5] + 0x88) != '\0') {
        if (*(char *)((&DAT_2081166c)[iVar5] + 0xaa) == '\0') {
          bVar1 = false;
        }
        else if (*(char *)((&DAT_2081166c)[iVar5] + 0xa9) != '\x05') {
          bVar2 = true;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    if (bVar1) {
      DAT_20800180 = 0;
      if (bVar2) {
        bVar3 = 2;
      }
      else {
        bVar3 = 1;
      }
      return bVar3;
    }
  }
  return 0;
}


// ===== FUN_2010e4a0 @ 2010e4a0 (12 bytes)

void FUN_2010e4a0(void)

{
  itron_sus_tsk(DAT_20800184);
  return;
}


// ===== fwupdate_init @ 2010e4ac (104 bytes)

/* task "fwupdate" */

void fwupdate_init(void)

{
  uint uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  fwobj_create_all();
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = itron_acre_flg(0,(byte *)&local_18);
  if (0 < (int)uVar1) {
    DAT_20800188 = uVar1;
    uVar1 = itron_acre_tsk(0,(byte *)&ctsk_fwupdate);
    if (0 < (int)uVar1) {
      DAT_20800184 = uVar1;
      itron_sta_tsk(uVar1,0);
    }
  }
  return;
}


// ===== mainlink_fw_mode_cmd @ 2010e514 (264 bytes)

/* F1 <code> frame to MAIN on SCIF5 at 345600, waits for 0x06 */

uint mainlink_fw_mode_cmd(char param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char local_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_20[0] = '\0';
  local_18 = 0;
  iVar5 = 0;
  mainlink_rx_ctrl(1);
  piVar2 = scif5_get(0);
  iVar4 = 2;
  (**(code **)(*piVar2 + 4))(piVar2,0x54600,8,0,2,iVar5);
  bVar1 = mainlink_got_frame60();
  if (bVar1 == 0) {
    return 1;
  }
  local_18._0_2_ = CONCAT11(param_1,0xf1);
  iVar3 = 0;
  local_14 = CONCAT13(param_1 + -0xf,(undefined3)local_14);
  while( true ) {
    iVar4 = (**(code **)(*piVar2 + 0x24))(piVar2,&local_18,8,*(code **)(*piVar2 + 0x24),iVar4,iVar5)
    ;
    if (iVar4 != 8) {
      return 0;
    }
    iVar5 = (**(code **)(*piVar2 + 0x18))(piVar2,local_20,1,0xdc);
    if ((iVar5 != -1) && (local_20[0] == '\x06')) break;
    iVar3 = iVar3 + 1;
    if (4 < iVar3) {
      return 0;
    }
  }
  return 1;
}


// ===== hex2_parse @ 2010e624 (76 bytes)

/* two uppercase hex digits */

uint hex2_parse(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = 2;
  uVar1 = 0;
  while( true ) {
    while( true ) {
      bVar4 = iVar3 == 0;
      iVar3 = iVar3 + -1;
      if (bVar4) {
        return uVar1;
      }
      uVar2 = (uint)*param_1;
      if (9 < uVar2 - 0x30) break;
      uVar1 = uVar1 << 4 | uVar2 - 0x30;
      param_1 = param_1 + 1;
    }
    if (5 < uVar2 - 0x41) break;
    uVar1 = uVar1 << 4 | uVar2 - 0x37;
    param_1 = param_1 + 1;
  }
  return 0xffffffff;
}


// ===== srec_parse_line @ 2010e670 (320 bytes)

/* one S0..S9 record, checksum checked */

int srec_parse_line(char *param_1,uint *param_2,void *param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  uVar7 = 0;
  if (*param_1 != 'S') {
    return -1;
  }
  pbVar1 = (byte *)(param_1 + 2);
  switch(param_1[1]) {
  case '0':
    return 0;
  case '1':
    iVar6 = 2;
    goto LAB_2010e6e0;
  case '2':
    iVar6 = 3;
    goto LAB_2010e6e0;
  case '3':
    iVar6 = 4;
LAB_2010e6e0:
    uVar2 = hex2_parse(pbVar1);
    if (uVar2 - 1 < 0xff) {
      iVar5 = 0;
      uVar3 = uVar2;
      while( true ) {
        uVar4 = uVar3 & 0xff;
        pbVar1 = pbVar1 + 2;
        if (iVar6 <= iVar5) break;
        uVar3 = hex2_parse(pbVar1);
        if ((int)uVar3 < 0) {
          return -1;
        }
        uVar7 = uVar3 | uVar7 << 8;
        uVar3 = uVar3 + uVar4;
        iVar5 = iVar5 + 1;
      }
      iVar5 = (uVar2 - iVar6) + -1;
      if ((uVar2 - iVar6) - 2 < 0x10) {
        *param_2 = uVar7;
        for (iVar6 = 0; iVar6 < iVar5; iVar6 = iVar6 + 1) {
          uVar7 = hex2_parse(pbVar1);
          pbVar1 = pbVar1 + 2;
          if ((int)uVar7 < 0) break;
          *(char *)param_3 = (char)uVar7;
          uVar4 = uVar4 + uVar7 & 0xff;
          param_3 = (undefined1 *)((int)param_3 + 1);
        }
        uVar7 = hex2_parse(pbVar1);
        bVar8 = uVar7 == 0;
        if (-1 < (int)uVar7) {
          bVar8 = (~uVar4 & 0xff) == uVar7;
        }
        if (bVar8) {
          return iVar5;
        }
      }
    }
    break;
  case '4':
    break;
  case '5':
    break;
  case '6':
    break;
  case '7':
    return 0;
  case '8':
    return 0;
  case '9':
    return 0;
  }
  return -1;
}


// ===== srec_load_image @ 2010e7b0 (184 bytes)

/* S-records into a 512 KiB buffer (uptest) */

uint srec_load_image(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_148 [128];
  char acStack_c8 [128];
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [32];
  uint local_10;
  
  if (param_3 == 0) {
    puVar3 = (undefined1 *)0x0;
    puVar4 = puVar3;
  }
  else {
    uVar1 = sfl_read_header(param_1,0);
    if (uVar1 != 0) {
      return 1;
    }
    puVar4 = &DAT_00000020;
    puVar3 = auStack_30;
  }
  sfl_stream_init(auStack_48,param_1,(uint)puVar3,(uint)puVar4);
  while( true ) {
    local_10 = 0;
    __aeabi_memclr4(auStack_148,0x80);
    iVar2 = sfl_stream_gets((int)acStack_c8,0x100,auStack_48);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = srec_parse_line(acStack_c8,&local_10,auStack_148);
    if (iVar2 < 0) break;
    if (iVar2 != 0) {
      if (0x7ffff < local_10) {
        return 1;
      }
      memcpy(local_10 + param_2,auStack_148);
    }
  }
  return 1;
}


// ===== srec_load_range @ 2010e868 (264 bytes)

/* S-records inside [start,end] into a buffer */

int srec_load_range(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  undefined1 local_158 [128];
  char acStack_d8 [128];
  undefined1 auStack_58 [24];
  undefined1 auStack_40 [32];
  uint local_20;
  
  iVar6 = 0;
  if (param_5 == 0) {
    puVar3 = (undefined1 *)0x0;
    puVar4 = puVar3;
  }
  else {
    uVar1 = sfl_read_header(param_1,0);
    if (uVar1 != 0) {
      return -1;
    }
    puVar4 = &DAT_00000020;
    puVar3 = auStack_40;
  }
  sfl_stream_init(auStack_58,param_1,(uint)puVar3,(uint)puVar4);
  while( true ) {
    local_20 = 0;
    __aeabi_memclr4(local_158,0x80);
    iVar5 = 0;
    iVar2 = sfl_stream_gets((int)acStack_d8,0x80,auStack_58);
    if (iVar2 == 0) {
      return iVar6;
    }
    iVar2 = srec_parse_line(acStack_d8,&local_20,local_158);
    if (iVar2 < 0) break;
    if (iVar2 != 0) {
      bVar8 = param_3 <= local_20;
      bVar7 = local_20 == param_3;
      if (!bVar8 || bVar7) {
        uVar1 = (local_20 + iVar2) - 1;
        bVar8 = uVar1 <= param_2;
        bVar7 = param_2 == uVar1;
      }
      if (!bVar8 || bVar7) {
        for (; iVar5 < iVar2; iVar5 = iVar5 + 1) {
          uVar1 = local_20 + iVar5;
          if (param_2 <= uVar1 && uVar1 <= param_3) {
            iVar6 = iVar6 + 1;
            *(undefined1 *)(param_4 + (uVar1 - param_2)) = local_158[iVar5];
          }
        }
      }
    }
  }
  return -1;
}


// ===== srec_find_range @ 2010e970 (260 bytes)

/* min/max S-record address inside an area */

undefined4
srec_find_range(uint param_1,uint param_2,uint param_3,uint *param_4,uint *param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  bool bVar6;
  bool bVar7;
  char acStack_158 [128];
  undefined1 auStack_d8 [128];
  undefined1 auStack_58 [24];
  undefined1 auStack_40 [32];
  uint local_20 [2];
  
  if (param_6 == 0) {
    puVar4 = (undefined1 *)0x0;
    puVar5 = puVar4;
  }
  else {
    uVar1 = sfl_read_header(param_1,0);
    if (uVar1 != 0) {
      return 0xffffffff;
    }
    puVar5 = &DAT_00000020;
    puVar4 = auStack_40;
  }
  sfl_stream_init(auStack_58,param_1,(uint)puVar4,(uint)puVar5);
  *param_4 = param_3;
  *param_5 = param_2;
  while( true ) {
    local_20[0] = 0;
    __aeabi_memclr4(auStack_d8,0x80);
    iVar2 = sfl_stream_gets((int)acStack_158,0x80,auStack_58);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = srec_parse_line(acStack_158,local_20,auStack_d8);
    if (iVar2 < 0) break;
    if (iVar2 != 0) {
      bVar7 = param_3 <= local_20[0];
      bVar6 = local_20[0] == param_3;
      if (!bVar7 || bVar6) {
        uVar1 = (local_20[0] + iVar2) - 1;
        bVar7 = uVar1 <= param_2;
        bVar6 = param_2 == uVar1;
      }
      if (!bVar7 || bVar6) {
        bVar7 = local_20[0] <= *param_4;
        bVar6 = *param_4 == local_20[0];
        if (bVar7 && !bVar6) {
          *param_4 = local_20[0];
          bVar7 = local_20[0] <= param_2;
          bVar6 = param_2 == local_20[0];
        }
        if (bVar7 && !bVar6) {
          *param_4 = param_2;
        }
        uVar3 = *param_5;
        uVar1 = (iVar2 + local_20[0]) - 1;
        if (uVar3 < uVar1) {
          *param_5 = uVar1;
        }
        if (uVar3 < uVar1 && param_3 < uVar1) {
          *param_5 = param_3;
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== uptest_program_stub @ 2010ea74 (28 bytes)

/* empty programmer used by uptest (returns 0) */

undefined4
uptest_program_stub(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = param_3;
  uStack_c = param_4;
  progress_range_init(&uStack_10,5,10);
  return 0;
}


// ===== update_main_cpu @ 2010ea90 (436 bytes)

/* sends I:\AH076H_HEW.mot to the RX651 (boot-mode link) */

void update_main_cpu(void)

{
  void *pvVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint in_r3;
  uint local_1c;
  
  local_1c = in_r3;
LAB_2010ea9c:
  pvVar1 = itron_twai_flg(DAT_20800190,1,5,&local_1c,-1);
  if (pvVar1 != (void *)0x0) {
    return;
  }
  gui_scope_draw_hold_set(1);
  itron_dly_tsk(0x14);
  iVar2 = work_buf_get(0);
  kbd_led_status(0,7);
  do {
    kbd_led_status(0,7);
    itron_dly_tsk(100);
    kbd_led_status(1,7);
    pcVar3 = "I:\\AH076H_HEW.mot";
    if (local_1c == 2) {
      pcVar3 = "I:\\AH068H_HEW.mot";
    }
    uVar4 = fs_fopen((uint)pcVar3,0x2010ed58);
    if (uVar4 == 0) {
      DAT_2080018c = 0x31d;
    }
    else {
      kbd_led_status(2,7);
      DAT_2080018c = 0x327;
      itron_dly_tsk(1);
      __aeabi_memset(iVar2,0x80000,0xff);
      uVar5 = srec_load_image(uVar4,iVar2,0);
      fs_fclose(uVar4);
      if (uVar5 == 0) break;
    }
    itron_dly_tsk(5);
  } while( true );
  gpio_p7_9_11(1);
  gpio_rx_update(1);
  gpio_rx_reset(1);
  itron_dly_tsk(1);
  gpio_rx_reset(0);
  itron_dly_tsk(1);
  iVar2 = uptest_program_stub(iVar2,0x80000,0);
  if (iVar2 == 0) {
    kbd_led_status(7,7);
    DAT_2080018c = 0x1e61;
    gpio_rx_reset(1);
    itron_dly_tsk(1);
    gpio_rx_reset(0);
    uVar6 = 1;
  }
  else {
    DAT_2080018c = (short)((uint)iVar2 >> 0x10) + 9000;
    kbd_led_status(5,7);
    uVar6 = 10;
  }
  itron_dly_tsk(uVar6);
  scope3d_tables_init();
  gui_scope_draw_hold_set(0);
  goto LAB_2010ea9c;
}


// ===== uptest_line @ 2010ec44 (232 bytes)

/* uptest, uptest2, mrst, rf0, rf1 */

void uptest_line(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)hid_line_edit(&DAT_2081167c,param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return;
  }
  uVar2 = strcmp((uint *)0x2010ed60,puVar1);
  if ((uVar2 == 0) || (uVar2 = strcmp((uint *)"uptest2",puVar1), uVar2 == 0)) {
    itron_set_flg(DAT_20800190);
    return;
  }
  uVar2 = strcmp((uint *)"mrst",puVar1);
  if (uVar2 == 0) {
    gpio_p7_9_11(1);
    gpio_rx_reset(1);
    itron_dly_tsk(1);
    gpio_rx_reset(0);
    itron_dly_tsk(1);
    return;
  }
  uVar2 = strcmp((uint *)0x2010ed78,puVar1);
  if (uVar2 == 0) {
    DAT_20800194 = 1;
  }
  else {
    uVar2 = strcmp((uint *)0x2010ed7c,puVar1);
    if (uVar2 != 0) {
      return;
    }
    if (DAT_20800198 == 0) {
      DAT_20800198 = 1;
      return;
    }
  }
  DAT_20800198 = 0;
  return;
}


// ===== uptest_init @ 2010ed80 (92 bytes)

/* task "uptest" (update_main_cpu) */

uint uptest_init(void)

{
  uint uVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  uVar1 = itron_acre_flg(0,(byte *)&local_10);
  if (((0 < (int)uVar1) &&
      (DAT_20800190 = uVar1, uVar1 = itron_acre_tsk(0,(byte *)&ctsk_uptest), 0 < (int)uVar1)) &&
     (uVar1 = itron_sta_tsk(uVar1,0), uVar1 == 0)) {
    return 0x2010ec44;
  }
  return 0;
}


// ===== mainlink_rx_block_write @ 2010ede8 (192 bytes)

/* 'E' (0x45): MAIN writes into the 32000-byte block 0x208116A6, reply C5 */

undefined4 mainlink_rx_block_write(char *param_1)

{
  ushort uVar1;
  undefined1 uStack_18;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  uint uStack_14;
  uint uVar2;
  
  uVar1 = be16_load((byte *)(param_1 + 1));
  uVar2 = (uint)uVar1;
  uVar1 = be16_load((byte *)(param_1 + 3));
  if (((uVar2 < DAT_208116a2) && (uVar2 + uVar1 <= (uint)DAT_208116a2)) &&
     (DAT_208116a0 == *param_1)) {
    DAT_208116a4 = (undefined2)(uVar2 + uVar1);
    memcpy(&DAT_208116a6 + uVar2,param_1 + 5);
    _uStack_18 = CONCAT13(param_1[2],CONCAT12(param_1[1],CONCAT11(*param_1,0xc5)));
    uStack_14 = (uint)*(ushort *)(param_1 + 3);
    mainlink_queue_frame(&uStack_18,6);
    return 1;
  }
  return 0;
}


// ===== mainlink_rx_block_read @ 2010eeb4 (212 bytes)

/* 'D' (0x44): MAIN reads from the block 0x208116A6, reply C4 (up to 0xFE data bytes) */

undefined4 mainlink_rx_block_read(char *param_1)

{
  ushort uVar1;
  uint uVar3;
  undefined1 uStack_120;
  char cStack_11f;
  char cStack_11e;
  char cStack_11d;
  undefined4 uStack_11c;
  undefined1 auStack_118 [256];
  uint uVar2;
  
  uVar1 = be16_load((byte *)(param_1 + 1));
  uVar2 = (uint)uVar1;
  uVar1 = be16_load((byte *)(param_1 + 3));
  if (((uVar2 < DAT_208116a2) && (uVar3 = uVar2 + uVar1, uVar3 <= DAT_208116a2)) &&
     (DAT_208116a0 == *param_1)) {
    DAT_208116a4 = (undefined2)uVar3;
    __aeabi_memclr4(auStack_118,0xfe);
    _uStack_120 = CONCAT13(param_1[2],CONCAT12(param_1[1],CONCAT11(*param_1,0xc4)));
    uStack_11c = (uint)*(ushort *)(param_1 + 3);
    memcpy((int)&uStack_11c + 2,&DAT_208116a6 + uVar2,(uint)uVar1);
    mainlink_queue_frame(&uStack_120,0x106);
    return 1;
  }
  return 0;
}


// ===== sdmenu_list_files @ 2010ef88 (320 bytes)

/* (kind, list, max): opens the SD folder for the kind (0x208001AC table), collects the names of the
   ".dat" files without the extension in 16-byte slots (work buffer 0x8350 bytes, at most 100),
   sorts them with qsort/strcasecmp and copies them to list; holds the scope drawing meanwhile;
   returns the count [fact] */

int sdmenu_list_files(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar2 = fs_opendir(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
  iVar5 = 0;
  if (iVar2 != 0) {
    gui_scope_draw_hold_set(1);
    iVar3 = work_buf_get(0x8350);
    iVar8 = 0;
LAB_2010efc4:
    do {
      do {
        do {
          piVar4 = (int *)fs_readdir(iVar2);
          iVar5 = iVar8;
          if (piVar4 == (int *)0x0) goto LAB_2010f068;
          iVar5 = fs_attr_check((int)*(char *)(*piVar4 + 0xb),0x20);
        } while (iVar5 != 0);
        iVar5 = (int)piVar4 + 10;
        uVar6 = strlen(iVar5);
        uVar1 = uVar6;
      } while (0x13 < uVar6);
      do {
        uVar1 = uVar1 - 1;
        if ((int)uVar1 < 1) goto LAB_2010efc4;
      } while ((*(char *)(iVar5 + uVar1) != '.') ||
              (iVar7 = strcasecmp(iVar5 + uVar1,".dat"), iVar7 != 0));
      strncpy(iVar3 + iVar8 * 0x10,iVar5,uVar6 - 4);
      iVar5 = iVar8 + 1;
      bVar9 = SBORROW4(iVar5,100);
      iVar7 = iVar8 + -99;
      if (iVar5 < 100) {
        bVar9 = SBORROW4(iVar5,param_3);
        iVar7 = iVar5 - param_3;
      }
      iVar8 = iVar5;
    } while (iVar7 < 0 != bVar9);
LAB_2010f068:
    fs_closedir(iVar2);
    if (iVar5 != 0) {
      qsort(iVar3,iVar5,0x10,strcasecmp);
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          memcpy(param_2 + iVar2 * 0x10,iVar3 + iVar2 * 0x10,0x10);
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
    }
    scope3d_tables_init();
    gui_scope_draw_hold_set(0);
  }
  return iVar5;
}


// ===== sdmenu_default_name @ 2010f0dc (232 bytes)

/* "20YY_MM_DD_NN" from the RTC date */

void sdmenu_default_name(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  char *local_40;
  byte abStack_3c [16];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  byte local_24 [8];
  
  rtc_get_date(local_2c,local_28,local_24);
  local_40 = (char *)(uint)local_24[0];
  sprintf(abStack_3c,"20%02X_%02X_%02X_NN",local_2c[0],local_28[0]);
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_3) {
    do {
      pbVar4 = (byte *)(param_2 + iVar3 * 0x10);
      iVar1 = strlen(pbVar4);
      if (((iVar1 == 0xd) && (iVar1 = strncmp(abStack_3c,pbVar4,0xb), iVar1 == 0)) &&
         (iVar1 = FUN_20111374(pbVar4 + 0xb,2,&local_40), *local_40 == '\0')) {
        if (iVar1 != iVar2) break;
        iVar2 = iVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
    if (99 < iVar2) {
      iVar2 = 99;
    }
  }
  memcpy(param_4,abStack_3c,0xb);
  sprintf(param_4 + 0xb,"%02d",iVar2);
  return;
}


// ===== sdmenu_file_exists @ 2010f1e0 (84 bytes)

uint sdmenu_file_exists(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_30 [44];
  
  sprintf(auStack_30,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + param_1 * 4),param_2);
  iVar1 = fs_get_attr(auStack_30);
  if ((iVar1 == -1) || (iVar1 = fs_attr_check((int)(char)iVar1,1), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== sdmenu_req_save @ 2010f240 (68 bytes)

/* MAIN transfer code 0x41 (MemList) / 0x43 (Menu) */

void sdmenu_req_save(int param_1,ushort param_2)

{
  if (param_1 == 0) {
    DAT_208116a0 = 0x41;
    DAT_208116a2 = param_2;
  }
  else if (param_1 == 1) {
    DAT_208116a0 = 0x43;
    DAT_208116a2 = param_2;
  }
  DAT_208116a4 = 0;
  return;
}


// ===== sdmenu_req_load @ 2010f284 (68 bytes)

/* MAIN transfer code 0x42 (MemList) / 0x44 (Menu) */

void sdmenu_req_load(int param_1,ushort param_2)

{
  if (param_1 == 0) {
    DAT_208116a0 = 0x42;
    DAT_208116a2 = param_2;
  }
  else if (param_1 == 1) {
    DAT_208116a0 = 0x44;
    DAT_208116a2 = param_2;
  }
  DAT_208116a4 = 0;
  return;
}


// ===== sdmenu_xfer_len @ 2010f2c8 (32 bytes)

undefined2 sdmenu_xfer_len(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  
  uVar1 = DAT_208116a2;
  if ((param_2 != 0) && (uVar1 = DAT_208116a4, param_2 != 1)) {
    uVar1 = 32000;
  }
  return uVar1;
}

