// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== sd_scr_bus_width @ 2013e1e4 (76 bytes)

/* Reads the SCR and sets the bus-width code +0x2AC from SD_BUS_WIDTHS (bit 2 of SCR byte 1: 4-bit)
   [fact] */

int sd_scr_bus_width(int *param_1)

{
  int iVar1;
  
  iVar1 = sd_acmd51_read_scr();
  if (iVar1 == 0) {
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x222) & 4) == 0) {
      *(undefined2 *)(iVar1 + 0x2ac) = 0;
      return 0;
    }
    *(undefined2 *)(iVar1 + 0x2ac) = 2;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== sd_read_sectors @ 2013e230 (132 bytes)

/* driver op +0x58 */

uint sd_read_sectors(int param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
    param_1 = param_1 << 9;
  }
                    /* makes sure the card is selected [doc] */
  uVar1 = sd_select_card(param_4);
  if ((uVar1 == 0) &&
     ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
      (uVar1 = (**(code **)(param_4[1] + 0x40))(), uVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e2ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_4[1] + 0x58))(param_1,param_2,param_3,*param_4);
    return uVar1;
  }
  return uVar1;
}


// ===== sd_write_sectors @ 2013e2b4 (156 bytes)

/* driver op +0x60; -7 = write-protected */

int sd_write_sectors(int param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_4[1] + 0xc))();
  if (iVar1 == 0) {
    if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
      param_1 = param_1 << 9;
    }
                    /* makes sure the card is selected [doc] */
    iVar1 = sd_select_card(param_4);
    if ((iVar1 == 0) &&
       ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
        (iVar1 = (**(code **)(param_4[1] + 0x40))(), iVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(param_4[1] + 0x60))(param_1,param_2,param_3,*param_4);
      return iVar1;
    }
  }
  else {
    iVar1 = -7;
  }
  return iVar1;
}


// ===== sd_check_card @ 2013e350 (12 bytes)

/* [fact] slot 2 (card check) of the handle's operation table; driver op 9; new entry (T24 round 8)
    */

void sd_check_card(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x2013e358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 4) + 8))();
  return;
}


// ===== sd_vol_read @ 2013e35c (112 bytes)

/* (vol, sector, buf, n, ctx): partition read: bounds check against vol +0x14, offset vol +0x30, 3
   tries of sd_read_sectors [fact] */

uint sd_vol_read(int param_1,uint param_2,uint param_3,uint param_4,int *param_5)

{
  uint uVar1;
  int i;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    i = 0;
    do {
      uVar1 = (**(code **)(param_5[1] + 8))();
      if (uVar1 != 0) {
        return uVar1;
      }
                    /* driver op +0x58 [doc, inference] */
      uVar1 = sd_read_sectors(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (uVar1 == 0) {
        return 0;
      }
      i = i + 1;
    } while (i < 3);
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


// ===== sd_vol_write @ 2013e3cc (112 bytes)

/* (vol, sector, buf, n, ctx): partition write, bounds check, one sd_write_sectors try [fact] */

int sd_vol_write(int param_1,uint param_2,uint param_3,uint param_4,int *param_5)

{
  int iVar1;
  int i;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    i = 0;
    do {
      iVar1 = (**(code **)(param_5[1] + 8))();
      if (iVar1 != 0) {
        return iVar1;
      }
                    /* driver op +0x60 [doc, inference] */
      iVar1 = sd_write_sectors(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
      i = i + 1;
    } while (i < 1);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}


// ===== sd_mount_volume @ 2013e43c (208 bytes)

/* Reads sector 0 (MBR), finds the partition (fat_find_volume), reads its boot sector, fat_mount and
   the FSInfo check (fat32_fsinfo_read) [fact] */

uint sd_mount_volume(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
                    /* driver op +0x58 [doc, inference] */
  uVar1 = sd_read_sectors(0,*param_2 + 1,1,param_2);
  if (uVar1 == 0) {
                    /* partition start from the MBR [doc] */
    iVar2 = fat_find_volume(param_1,*param_2 + 1);
    if (iVar2 == 0) {
      uVar1 = sd_read_sectors(*(int *)(param_1 + 0x30),*param_2 + 1,1,param_2);
      if (uVar1 != 0) {
        return uVar1;
      }
      uVar1 = fat_mount(param_1,*param_2 + 1);
      if (-1 < (int)uVar1) {
        if (*(char *)(param_1 + 0x10) == ' ') {
          uVar1 = sd_read_sectors(*(int *)(param_1 + 0x30) + (uint)*(ushort *)(param_1 + 0x3a),
                                  *param_2 + 1,1,param_2);
          if (uVar1 != 0) {
            return uVar1;
          }
          fat32_fsinfo_read(param_1,*param_2 + 1);
        }
        return 0;
      }
    }
    uVar1 = 0xfffffffc;
  }
  return uVar1;
}


// ===== sd_drive_mount @ 2013e50c (400 bytes)

/* [fact] driver op 7: power on, identify, CSD/CID, select, bus width, speed, SD status, clock,
   sd_mount_volume, flags +0x68 bits 7 and 5 under itron_loc_cpu; new entry (T24 round 8,
   drivers/sd_drive.c) */

int sd_drive_mount(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int i;
  
  iVar2 = (**(code **)(param_2[1] + 0x24))();
  if (iVar2 == 0) {
    i = 0;
    do {
      iVar2 = (**(code **)(param_2[1] + 0x20))(2);
                    /* card reset/identify, card-type flags at +0x2C0/+0x2C2 [doc, inference] */
                    /* CMD9 with sd_csd_check / mmc_csd_check [doc] */
                    /* Reads sector 0 [doc] */
      if (((((iVar2 == 0) && (iVar2 = sd_card_identify(param_2), iVar2 == 0)) &&
           (iVar2 = sd_read_csd_cid(param_2), iVar2 == 0)) &&
          ((((iVar2 = sd_selected_op(*(undefined2 *)(*param_2 + 0x2aa),0x200,1,param_2), iVar2 == 0
             && (iVar2 = sd_cmd7_select(*(undefined2 *)(*param_2 + 0x2aa),param_2), iVar2 == 0)) &&
            ((*(short *)(*param_2 + 0x2c6) == 1 ||
             (((iVar2 = sd_scr_bus_width(param_2), iVar2 == 0 &&
               (iVar2 = sd_acmd6_set_bus_width(param_2), iVar2 == 0)) &&
              ((iVar2 = sd_select_bus_speed(param_2), iVar2 == 0 &&
               (iVar2 = sd_acmd13_read_status(param_2), iVar2 == 0)))))))) &&
           (iVar2 = sd_card_clock(1,param_2), iVar2 == 0)))) &&
         (((*(short *)(*param_2 + 0x2c2) != 2 && *(short *)(*param_2 + 0x2c2) != 3 ||
           (iVar2 = (**(code **)(param_2[1] + 0x40))(), iVar2 == 0)) &&
          (iVar2 = sd_mount_volume(param_1,param_2), iVar2 == 0)))) {
        sd_lock();
        *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) | 0x80;
        iVar2 = (**(code **)(param_2[1] + 0xc))();
        if (iVar2 == 0) {
          bVar1 = *(byte *)(param_1 + 0x68) & 0xdf;
        }
        else {
          bVar1 = *(byte *)(param_1 + 0x68) | 0x20;
        }
        *(byte *)(param_1 + 0x68) = bVar1;
        sd_unlock();
        return 0;
      }
      i = i + 1;
    } while (i < 3);
  }
  return iVar2;
}


// ===== sd_drive_unmount @ 2013e6a0 (48 bytes)

/* [fact] driver op 8: slot 10, then +0x68 &= 0x7F under the CPU lock; new entry (T24 round 8) */

undefined4 sd_drive_unmount(int param_1,int param_2)

{
  (**(code **)(*(int *)(param_2 + 4) + 0x28))();
  sd_lock();
  *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
  sd_unlock();
  return 0;
}


// ===== sd_drive_attach @ 2013e6d0 (76 bytes)

/* [fact] driver op 5: slot 25 (open), sd_card_task_start, the handle into the drive +0x24; new
   entry (T24 round 8) */

undefined4 sd_drive_attach(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_2[1] + 100))();
  if ((iVar1 == 0) && (iVar1 = sd_card_task_start(param_1,*(undefined1 *)*param_2), iVar1 == 0)) {
    *(undefined4 **)(param_1 + 0x24) = param_2;
    return 0;
  }
  return 0xfffffff8;
}


// ===== sd_driver_op @ 2013e71c (164 bytes)

/* Driver entry of drive I: (op code): 1 read sectors, 2 write sectors, 5 format step, 7 mount
   (power, sd_card_identify, CSD/CID, RCA select, SCR, bus width, bus speed, SD status, volume
   mount), 8 unmount, others through a table; registered by sdhi_drv_init [fact] */

undefined4
sd_driver_op(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  undefined4 uVar1;
  
  switch(param_2) {
  default:
    return 0xfffffffd;
  case 1:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      uVar1 = sd_vol_read(param_1,param_3,param_4,param_5,param_6);
      return uVar1;
    }
    break;
  case 2:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
                    /* partition write, bounds check, one sd_write_sectors try [doc] */
      uVar1 = sd_vol_write(param_1,param_3,param_4,param_5,param_6);
      return uVar1;
    }
    break;
  case 5:
    uVar1 = sd_drive_attach();
    return uVar1;
  case 7:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      uVar1 = sd_drive_mount();
      return uVar1;
    }
    break;
  case 8:
    uVar1 = sd_drive_unmount();
    return uVar1;
  case 9:
    uVar1 = sd_check_card(param_6,param_6,param_2,param_4);
    return uVar1;
  }
  return 0xfffffffa;
}


// ===== sd_format_progress_dec @ 2013e7e8 (24 bytes)

/* Decrements the format progress counter ctx +0x2F4 while non-zero [fact] */

void sd_format_progress_dec(int param_1)

{
  if (*(int *)(param_1 + 0x2f4) != 0) {
    *(int *)(param_1 + 0x2f4) = *(int *)(param_1 + 0x2f4) + -1;
  }
  return;
}


// ===== sd_format_progress_set @ 2013e800 (12 bytes)

/* (n, ctx): sets the format progress counters +0x2F4 and +0x2F8 to n [fact] */

void sd_format_progress_set(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x2f4) = param_1;
  *(undefined4 *)(param_2 + 0x2f8) = param_1;
  return;
}


// ===== fat_format_clear_root @ 2013e80c (196 bytes)

/* [fact] zeroes 32 sectors (FAT12/16) or one cluster (FAT32) after the FATs with progress; tail
   call of fat_format_volume 0x2013F834; new entry (T24 round 8, app/fat_format.c) */

int fat_format_clear_root(int *param_1)

{
  char cVar1;
  int iVar2;
  int sd_write_sectors_ret;
  uint i;
  uint uVar3;
  
  iVar2 = *param_1;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(iVar2 + 1,0,0x200,0);
  cVar1 = *(char *)(iVar2 + 0x2dc);
  if (cVar1 == '\f' || cVar1 == '\x10') {
    uVar3 = 0x20;
    iVar2 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4) + *(int *)(iVar2 + 0x2e0) * 2
    ;
  }
  else {
    if (cVar1 != ' ') {
      return -2;
    }
    uVar3 = (uint)*(ushort *)(iVar2 + 0x2d8);
    iVar2 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4) + *(int *)(iVar2 + 0x2e0) * 2
    ;
  }
  i = 0;
  if (uVar3 != 0) {
    do {
                    /* driver op +0x60 [doc, inference] */
      sd_write_sectors_ret = sd_write_sectors(iVar2,*param_1 + 1,1,param_1);
      if (sd_write_sectors_ret != 0) {
        return sd_write_sectors_ret;
      }
      sd_format_progress_dec(*param_1);
      i = i + 1;
      iVar2 = iVar2 + 1;
    } while (i < uVar3);
  }
  return 0;
}


// ===== fat_format_write_fats @ 2013e8d0 (420 bytes)

/* Format step: writes the first sector of each FAT with the media entries (F8 FF FF / F8 FF FF FF /
   F8 FF FF 0F FF FF FF 0F... from 0x20420254..) and zero sectors after them, counting progress
   [fact] */

int fat_format_write_fats(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint i;
  int iVar5;
  int iVar6;
  
  iVar2 = *param_1;
  iVar6 = 0;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(iVar2 + 1,0,0x200,0);
  cVar1 = *(char *)(iVar2 + 0x2dc);
  if (cVar1 == '\f') {
    fs_memcpy(*param_1 + 1,&DAT_20420254,3);
  }
  else if (cVar1 == '\x10') {
    fs_memcpy(*param_1 + 1,&DAT_20420257,4);
  }
  else {
    if (cVar1 != ' ') {
      return -2;
    }
    fs_memcpy(*param_1 + 1,&DAT_204202f3,0xc);
  }
  iVar5 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4);
                    /* driver op +0x60 [doc, inference] */
  iVar3 = sd_write_sectors(iVar5,*param_1 + 1,1,param_1);
  if (iVar3 == 0) {
    if (*(char *)(iVar2 + 0x2dc) != '@') {
      iVar6 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4) + *(int *)(iVar2 + 0x2e0);
      iVar4 = sd_write_sectors(iVar6,*param_1 + 1,1,param_1);
      iVar3 = 0;
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    sd_format_progress_dec(*param_1);
    fs_memset(*param_1 + 1,0,0x200);
    iVar4 = *(int *)(iVar2 + 0x2e0);
    if ((*(char *)(iVar2 + 0x2dc) != '@') && (i = 0, iVar4 != 1)) {
      do {
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 1;
        iVar2 = sd_write_sectors(iVar5,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = sd_write_sectors(iVar6,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        sd_format_progress_dec(*param_1);
        i = i + 1;
        iVar3 = 0;
      } while (i < iVar4 - 1U);
    }
  }
  return iVar3;
}


// ===== fat32_format_write_fsinfo @ 2013ea74 (332 bytes)

/* Format step: FSInfo sector (lead and struct signatures from 0x20808B4C / 0x20808B50, free count
   and next-free 0xFFFFFFFF) at sectors 1 and 7 of the volume, zero sectors 2 and 8 [fact] */

void fat32_format_write_fsinfo(int *param_1)

{
  int iVar1;
  int iVar2;
  int sd_write_sectors_ret;
  
  iVar1 = *param_1;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(iVar1 + 1,0,0x200);
  fs_memcpy(*param_1 + 1,DAT_20808b4c,4);
  fs_memcpy(*param_1 + 0x1e5,DAT_20808b50,4);
  fat_st_dword(*param_1 + 0x1e9,0xffffffff);
  fat_st_dword(*param_1 + 0x1ed,0xffffffff);
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  iVar2 = *(int *)(iVar1 + 0x2d0);
                    /* driver op +0x60 [doc, inference] */
  sd_write_sectors_ret = sd_write_sectors(iVar2 + 1,*param_1 + 1,1,param_1);
  if ((sd_write_sectors_ret == 0) &&
     (iVar2 = sd_write_sectors(iVar2 + 7,*param_1 + 1,1,param_1), iVar2 == 0)) {
    fs_memset(*param_1 + 1,0,0x200);
    *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
    *(undefined1 *)(*param_1 + 0x200) = 0xaa;
    iVar1 = *(int *)(iVar1 + 0x2d0);
    iVar2 = sd_write_sectors(iVar1 + 2,*param_1 + 1,1,param_1);
    if (iVar2 == 0) {
      sd_write_sectors(iVar1 + 8,*param_1 + 1,1,param_1);
      return;
    }
  }
  return;
}


// ===== fat_format_volume_id @ 2013ebc0 (112 bytes)

/* Volume serial number from the current date and time (fs_get_time_tm) [fact] */

uint fat_format_volume_id(void)

{
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
                    /* rtc_get_tm into the caller's struct tm, returns 1 [doc] */
  fs_get_time_tm(&local_28);
  return local_14 + 0x76cU & 0xffff | local_24 & 0xffff | (local_20 & 0xff) << 8 |
         ((local_28 & 0xff) * 0x100 + (local_1c | (local_18 + 1) * 0x100 & 0xff00U)) * 0x10000;
}


// ===== fat_format_write_boot @ 2013ec30 (564 bytes)

/* Format step: boot sector from the FAT12/16 template 0x2042025B (0x3E bytes) or the FAT32 template
   0x20420299 (0x5A bytes) with the computed BPB fields and the volume id; FAT32 also writes the
   backup at +6 [fact] */

void fat_format_write_boot(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *param_1;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(iVar1 + 1,0,0x200);
  if (*(char *)(iVar1 + 0x2dc) != ' ') {
    fs_memcpy(*param_1 + 1,&DAT_2042025b,0x3e);
    fat_st_word(*param_1 + 0xc,*(undefined2 *)(iVar1 + 0x2da));
    *(undefined1 *)(*param_1 + 0xe) = *(undefined1 *)(iVar1 + 0x2d8);
    fat_st_word(*param_1 + 0xf,*(undefined2 *)(iVar1 + 0x2e4));
    fat_st_word(*param_1 + 0x17,*(undefined2 *)(iVar1 + 0x2e0));
    fat_st_word(*param_1 + 0x19,*(undefined2 *)(iVar1 + 0x2c8));
    fat_st_word(*param_1 + 0x1b,*(undefined2 *)(iVar1 + 0x2ca));
    fat_st_dword(*param_1 + 0x1d,*(undefined4 *)(iVar1 + 0x2d0));
    if (*(uint *)(iVar1 + 0x2d4) < 0x10000) {
      fat_st_word(*param_1 + 0x14,*(uint *)(iVar1 + 0x2d4) & 0xffff);
    }
    else {
      fat_st_dword(*param_1 + 0x21);
    }
                    /* Volume serial number from the current date and time [doc] */
    uVar2 = fat_format_volume_id();
    fat_st_dword(*param_1 + 0x28,uVar2);
    if (*(char *)(iVar1 + 0x2dc) == '\f') {
      *(undefined1 *)(*param_1 + 0x3b) = 0x32;
    }
    *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
    *(undefined1 *)(*param_1 + 0x200) = 0xaa;
                    /* driver op +0x60 [doc, inference] */
    sd_write_sectors(*(int *)(iVar1 + 0x2d0),*param_1 + 1,1,param_1);
    return;
  }
  fs_memcpy(*param_1 + 1,&DAT_20420299,0x5a);
  fat_st_word(*param_1 + 0xc,*(undefined2 *)(iVar1 + 0x2da));
  *(undefined1 *)(*param_1 + 0xe) = *(undefined1 *)(iVar1 + 0x2d8);
  fat_st_word(*param_1 + 0xf,*(undefined2 *)(iVar1 + 0x2e4));
  fat_st_word(*param_1 + 0x19,*(undefined2 *)(iVar1 + 0x2c8));
  fat_st_word(*param_1 + 0x1b,*(undefined2 *)(iVar1 + 0x2ca));
  fat_st_dword(*param_1 + 0x1d,*(undefined4 *)(iVar1 + 0x2d0));
  fat_st_dword(*param_1 + 0x21,*(undefined4 *)(iVar1 + 0x2d4));
  fat_st_dword(*param_1 + 0x25,*(undefined4 *)(iVar1 + 0x2e0));
  uVar2 = fat_format_volume_id();
  fat_st_dword(*param_1 + 0x44,uVar2);
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  iVar3 = *(int *)(iVar1 + 0x2d0);
  iVar1 = sd_write_sectors(iVar3,*param_1 + 1,1,param_1);
  if (iVar1 == 0) {
    sd_write_sectors(iVar3 + 6,*param_1 + 1,1,param_1);
    return;
  }
  return;
}


// ===== mbr_chs_head @ 2013ee64 (88 bytes)

/* (geometry, *out): CHS head of the partition start, 0xFE beyond the CHS limit 0xFB0400 [fact] */

void mbr_chs_head(ushort *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 extraout_r1;
  uint uVar2;
  
  *param_2 = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (param_1[1] != 0)) {
    if (*(uint *)(param_1 + 4) < 0xfb0400) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
      __aeabi_uidivmod(*(uint *)(param_1 + 4),param_1[1] * uVar2);
      uVar1 = __aeabi_uidivmod(extraout_r1,uVar2);
    }
    else {
      uVar1 = 0xfe;
    }
    *param_2 = uVar1;
  }
  return;
}


// ===== mbr_chs_sector_cyl @ 2013eebc (128 bytes)

/* (geometry, *out): CHS sector/cylinder bytes of the partition start [fact] */

void mbr_chs_sector_cyl(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  char extraout_r1;
  uint uVar2;
  uint uVar3;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (uVar1 = param_1[1], uVar1 != 0)) {
    uVar3 = *(uint *)(param_1 + 4);
    if (uVar3 < 0xfb0400) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
      __aeabi_uidivmod(uVar3,uVar2);
      uVar2 = __aeabi_uidivmod(uVar3,uVar1 * uVar2);
      *param_2 = (byte)((uVar2 >> 8) << 6) | extraout_r1 + 1U;
    }
    else {
      uVar2 = 0xff;
      *param_2 = 0xff;
    }
    param_2[1] = (byte)uVar2;
  }
  return;
}


// ===== mbr_partition_type @ 2013ef3c (96 bytes)

/* (geometry, *out): partition type 1 / 4 / 6 for FAT12/16 by size, 0x0B / 0x0C for FAT32 (below /
   above the CHS limit) [fact] */

void mbr_partition_type(int param_1,undefined1 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\f' || cVar1 == '\x10') {
    if (*(uint *)(param_1 + 0xc) < 0x7fa8) {
      uVar2 = 1;
    }
    else if (*(uint *)(param_1 + 0xc) < 0x10000) {
      uVar2 = 4;
    }
    else {
      uVar2 = 6;
    }
  }
  else {
    if (cVar1 != ' ') {
      return;
    }
    if (*(uint *)(param_1 + 0xc) < 0xfb0400) {
      *param_2 = 0xb;
      return;
    }
    uVar2 = 0xc;
  }
  *param_2 = uVar2;
  return;
}


// ===== mbr_chs_end_head @ 2013ef9c (100 bytes)

/* (geometry, *out): CHS head of the partition end (start + size - 1) [fact] */

void mbr_chs_end_head(ushort *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 extraout_r1;
  uint uVar2;
  
  *param_2 = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (param_1[1] != 0)) {
    if (*(uint *)(param_1 + 6) < 0xfb0400) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
      __aeabi_uidivmod(*(int *)(param_1 + 4) + *(uint *)(param_1 + 6) + -1,param_1[1] * uVar2);
      uVar1 = __aeabi_uidivmod(extraout_r1,uVar2);
    }
    else {
      uVar1 = 0xfe;
    }
    *param_2 = uVar1;
  }
  return;
}


// ===== mbr_chs_end_sector_cyl @ 2013f000 (136 bytes)

/* (geometry, *out): CHS sector/cylinder of the partition end [fact for the arithmetic] */

void mbr_chs_end_sector_cyl(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  char extraout_r1;
  uint uVar2;
  int iVar3;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (uVar1 = param_1[1], uVar1 != 0)) {
    if (*(uint *)(param_1 + 6) < 0xfb0400) {
      iVar3 = *(int *)(param_1 + 4) + *(uint *)(param_1 + 6);
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
      __aeabi_uidivmod(iVar3 + -1,uVar2);
      uVar2 = __aeabi_uidivmod(iVar3 + -1,uVar1 * uVar2);
      *param_2 = (byte)((uVar2 >> 8) << 6) | extraout_r1 + 1U;
    }
    else {
      uVar2 = 0xff;
      *param_2 = 0xff;
    }
    param_2[1] = (byte)uVar2;
  }
  return;
}


// ===== fat_format_write_mbr @ 2013f088 (184 bytes)

/* Format step: writes sector 0 with one partition entry at 0x1BE (CHS start/end fields, type, LBA
   start, size) [fact] */

void fat_format_write_mbr(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar3 = iVar1 + 0x2c8;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(iVar1 + 1,0,0x200);
  iVar2 = *param_1;
  mbr_chs_head(iVar3,iVar2 + 0x1c0);
                    /* CHS sector/cylinder bytes of the partition start [doc] */
  mbr_chs_sector_cyl(iVar3,iVar2 + 0x1c1);
  mbr_partition_type(iVar3,iVar2 + 0x1c3);
  mbr_chs_end_head(iVar3,iVar2 + 0x1c4);
  mbr_chs_end_sector_cyl(iVar3,iVar2 + 0x1c5);
  fat_st_dword(iVar2 + 0x1c7,*(undefined4 *)(iVar1 + 0x2d0));
  fat_st_dword(iVar2 + 0x1cb,*(undefined4 *)(iVar1 + 0x2d4));
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
                    /* driver op +0x60 [doc, inference] */
  sd_write_sectors(0,*param_1 + 1,1,param_1);
  return;
}


// ===== csd_read_bl_len @ 2013f15c (36 bytes)

/* (csd): READ_BL_LEN 10 / 11 -> 1024 / 2048, else 512 [fact] */

undefined4 csd_read_bl_len(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_1 + 5) & 0xf;
  if (bVar1 == 10) {
    uVar2 = 0x400;
  }
  else if (bVar1 == 0xb) {
    uVar2 = 0x800;
  }
  else {
    uVar2 = 0x200;
  }
  return uVar2;
}


// ===== csd_c_size @ 2013f180 (36 bytes)

/* (csd): the 12-bit C_SIZE field of a version-1 CSD [fact] */

uint csd_c_size(int param_1)

{
  return (*(byte *)(param_1 + 8) & 0xc0 |
         ((uint)*(byte *)(param_1 + 7) | (*(byte *)(param_1 + 6) & 3) << 8) << 8) >> 6;
}


// ===== csd_c_size_mult @ 2013f1a4 (108 bytes)

/* (csd): 2^(C_SIZE_MULT + 2), 4..512 [fact] */

undefined4 csd_c_size_mult(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(byte *)(param_1 + 10) & 0x80 | (*(byte *)(param_1 + 9) & 3) << 8) >> 7;
  if (uVar1 == 0) {
    uVar2 = 4;
  }
  else if (uVar1 == 1) {
    uVar2 = 8;
  }
  else if (uVar1 == 2) {
    uVar2 = 0x10;
  }
  else if (uVar1 == 3) {
    uVar2 = 0x20;
  }
  else if (uVar1 == 4) {
    uVar2 = 0x40;
  }
  else if (uVar1 == 5) {
    uVar2 = 0x80;
  }
  else if (uVar1 == 6) {
    uVar2 = 0x100;
  }
  else {
    uVar2 = 0x200;
  }
  return uVar2;
}


// ===== fat_format_geometry_small @ 2013f210 (40 bytes)

/* (sectors, out): 0x2C-byte geometry record 0x20420300 below 0x7E0000 sectors, else 0x2042032C
   [fact] */

void fat_format_geometry_small(uint param_1,undefined4 param_2)

{
  if (param_1 < 0x7e0000) {
    fs_memcpy(param_2,&DAT_20420300,0x2c);
    return;
  }
  fs_memcpy(param_2,&DAT_2042032c,0x2c);
  return;
}


// ===== fat_format_geometry @ 2013f238 (264 bytes)

/* (sectors, out): 0x2C-byte geometry record from the capacity table 0x20420358..0x20420510 [fact]
    */

void fat_format_geometry(uint param_1,undefined4 param_2)

{
  param_1 = param_1 >> 9;
  if (param_1 < 0x1000) {
    fs_memcpy(param_2,&DAT_20420358,0x2c);
    return;
  }
  if (param_1 < 0x4000) {
    fs_memcpy(param_2,&DAT_20420384,0x2c);
    return;
  }
  if (param_1 < 0x8000) {
    fs_memcpy(param_2,&DAT_204203b0,0x2c);
    return;
  }
  if (param_1 < 0x10000) {
    fs_memcpy(param_2,&DAT_204203dc,0x2c);
    return;
  }
  if (param_1 < 0x20000) {
    fs_memcpy(param_2,&DAT_20420408,0x2c);
    return;
  }
  if (param_1 < 0x40000) {
    fs_memcpy(param_2,&DAT_20420434,0x2c);
    return;
  }
  if (param_1 < 0x80000) {
    fs_memcpy(param_2,&DAT_20420460,0x2c);
    return;
  }
  if (param_1 < 0xfc000) {
    fs_memcpy(param_2,&DAT_2042048c,0x2c);
    return;
  }
  if (param_1 < 0x1f8000) {
    fs_memcpy(param_2,&DAT_204204b8,0x2c);
    return;
  }
  if (param_1 < 0x3f0000) {
    fs_memcpy(param_2,&DAT_204204e4,0x2c);
    return;
  }
  fs_memcpy(param_2,&DAT_20420510,0x2c);
  return;
}


// ===== fat_format_layout @ 2013f340 (1116 bytes)

/* Computes the format layout from the CSD capacity: geometry record (fat_format_geometry_small /
   fat_format_geometry), sectors per cluster, reserved sectors, FAT size and data start, and the
   progress count [fact] */

undefined4 fat_format_layout(int *param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined4 local_28;
  
  local_28 = 0;
  iVar3 = *param_1;
  pbVar9 = (byte *)(iVar3 + 0x201);
  if (*pbVar9 >> 6 == 1) {
    uVar10 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x208),*(undefined1 *)(iVar3 + 0x209)),
                            *(undefined1 *)(iVar3 + 0x20a)) * 0x400 + 0x400;
    fat_format_geometry_small(uVar10,iVar3 + 0x2c8);
    if (uVar10 < 0x4000000) {
      *(uint *)(iVar3 + 0x2d4) = uVar10;
      iVar4 = (int)*(char *)(iVar3 + 0x2dc);
      if (iVar4 != 0x40) {
        uVar11 = (uint)*(ushort *)(iVar3 + 0x2d8);
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
        iVar6 = __aeabi_uidivmod(uVar10,uVar11);
        iVar5 = (uint)*(ushort *)(iVar3 + 0x2da) << 3;
        uVar15 = __aeabi_uidivmod(iVar6 * iVar4,iVar5);
        *(int *)(iVar3 + 0x2e0) = (int)uVar15;
        iVar13 = (uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15;
        iVar6 = 1;
        *(int *)(iVar3 + 0x2e0) = iVar13;
        uVar7 = *(uint *)(iVar3 + 0x2cc);
        if (uVar7 <= (uint)(iVar13 * 2)) {
          do {
            iVar6 = iVar6 + 1;
          } while (uVar7 * iVar6 < (uint)(iVar13 * 2) || uVar7 * iVar6 + iVar13 * -2 == 0);
        }
        uVar14 = uVar7 * iVar6 + iVar13 * -2;
        uVar8 = uVar14 & 0xffff;
        *(short *)(iVar3 + 0x2e4) = (short)uVar14;
        if (uVar8 < 9) {
          uVar8 = uVar8 + uVar7;
          *(short *)(iVar3 + 0x2e4) = (short)uVar8;
        }
        iVar6 = (uVar8 & 0xffff) + iVar13 * 2;
        *(int *)(iVar3 + 0x2e8) = iVar6;
        iVar12 = uVar10 - *(int *)(iVar3 + 0x2d0);
        iVar6 = __aeabi_uidivmod(iVar12 - iVar6,uVar11);
        *(int *)(iVar3 + 0x2ec) = iVar6 + 1;
        uVar15 = __aeabi_uidivmod((iVar6 + 2) * iVar4,iVar5);
        *(int *)(iVar3 + 0x2f0) = (int)uVar15;
        iVar6 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
        *(int *)(iVar3 + 0x2f0) = iVar6;
        if (iVar13 != iVar6) {
          do {
            if (*(uint *)(iVar3 + 0x2e0) < *(uint *)(iVar3 + 0x2f0)) {
              *(uint *)(iVar3 + 0x2e8) = *(int *)(iVar3 + 0x2e8) + uVar7;
              *(short *)(iVar3 + 0x2e4) = *(short *)(iVar3 + 0x2e4) + (short)uVar7;
              iVar6 = *(int *)(iVar3 + 0x2e8);
            }
            else {
              iVar6 = *(uint *)(iVar3 + 0x2e0) - 1;
              iVar13 = 1;
              *(int *)(iVar3 + 0x2e0) = iVar6;
              if (uVar7 <= (uint)(iVar6 * 2)) {
                do {
                  iVar13 = iVar13 + 1;
                } while (uVar7 * iVar13 < (uint)(iVar6 * 2) || uVar7 * iVar13 + iVar6 * -2 == 0);
              }
              uVar10 = uVar7 * iVar13 + iVar6 * -2;
              uVar14 = uVar10 & 0xffff;
              *(short *)(iVar3 + 0x2e4) = (short)uVar10;
              if (uVar14 < 9) {
                uVar14 = uVar14 + uVar7;
                *(short *)(iVar3 + 0x2e4) = (short)uVar14;
              }
              iVar6 = (uVar14 & 0xffff) + iVar6 * 2;
              *(int *)(iVar3 + 0x2e8) = iVar6;
            }
            iVar6 = __aeabi_uidivmod(iVar12 - iVar6,uVar11);
            *(int *)(iVar3 + 0x2ec) = iVar6 + 1;
            uVar15 = __aeabi_uidivmod((iVar6 + 2) * iVar4,iVar5);
            *(int *)(iVar3 + 0x2f0) = (int)uVar15;
            iVar6 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
            *(int *)(iVar3 + 0x2f0) = iVar6;
          } while (*(int *)(iVar3 + 0x2e0) != iVar6);
        }
        sd_format_progress_set(*(int *)(iVar3 + 0x2e0) + uVar11,*param_1);
      }
      *(int *)(iVar3 + 0x2d4) = *(int *)(iVar3 + 0x2d4) - *(int *)(iVar3 + 0x2cc);
    }
    else {
      local_28 = 0xfffffffb;
    }
  }
  else if (*pbVar9 >> 6 == 0) {
    iVar4 = csd_read_bl_len(pbVar9);
                    /* the 12-bit C_SIZE field of a version-1 CSD [doc] */
    iVar5 = csd_c_size(pbVar9);
    iVar6 = csd_c_size_mult(pbVar9);
    uVar10 = (iVar5 + 1) * iVar6 * iVar4;
    fat_format_geometry(uVar10,iVar3 + 0x2c8);
    uVar10 = uVar10 >> 9;
    *(uint *)(iVar3 + 0x2d4) = uVar10;
    uVar1 = *(undefined2 *)(iVar3 + 0x2d8);
    iVar5 = __aeabi_uidivmod(uVar10);
    iVar6 = (int)*(char *)(iVar3 + 0x2dc);
    iVar4 = (uint)*(ushort *)(iVar3 + 0x2da) << 3;
    uVar15 = __aeabi_uidivmod(iVar5 * iVar6);
    uVar7 = (uint)uVar15 & 0xffff;
    uVar14 = ((int)((ulonglong)uVar15 >> 0x20) != 0) + uVar7;
    *(uint *)(iVar3 + 0x2e0) = uVar7;
    *(uint *)(iVar3 + 0x2e0) = uVar14;
    uVar2 = *(ushort *)(iVar3 + 0x2e4);
    uVar11 = (uint)uVar2 + uVar14 * 2 + 0x20;
    *(uint *)(iVar3 + 0x2e8) = uVar11;
    uVar7 = *(uint *)(iVar3 + 0x2cc);
    if (uVar7 < uVar11) {
      uVar15 = __aeabi_uidivmod(uVar11,uVar7);
      uVar8 = uVar7 * ((uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15) - uVar11;
    }
    else {
      uVar8 = uVar7 - uVar11;
    }
    *(uint *)(iVar3 + 0x2d0) = uVar8;
    if (uVar8 != uVar7) {
      uVar8 = uVar8 + uVar7;
      *(uint *)(iVar3 + 0x2d0) = uVar8;
    }
    iVar5 = __aeabi_uidivmod((uVar10 - uVar8) - uVar11,uVar1);
    *(int *)(iVar3 + 0x2ec) = iVar5 + 1;
    uVar15 = __aeabi_uidivmod((iVar5 + 2) * iVar6,iVar4);
    *(int *)(iVar3 + 0x2f0) = (int)uVar15;
    uVar11 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
    *(uint *)(iVar3 + 0x2f0) = uVar11;
    if (uVar14 != uVar11) {
      do {
        if (*(uint *)(iVar3 + 0x2e0) < uVar11) {
          uVar11 = *(int *)(iVar3 + 0x2d0) + uVar7;
          *(uint *)(iVar3 + 0x2d0) = uVar11;
        }
        else {
          *(uint *)(iVar3 + 0x2e0) = uVar11;
          uVar11 = (uint)uVar2 + uVar11 * 2 + 0x20;
          *(uint *)(iVar3 + 0x2e8) = uVar11;
          if (uVar7 < uVar11) {
            uVar15 = __aeabi_uidivmod(uVar11,uVar7);
            uVar11 = uVar7 * ((uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15) - uVar11;
          }
          else {
            uVar11 = uVar7 - uVar11;
          }
          *(uint *)(iVar3 + 0x2d0) = uVar11;
          if (uVar11 != uVar7) {
            uVar11 = uVar11 + uVar7;
            *(uint *)(iVar3 + 0x2d0) = uVar11;
          }
        }
        iVar5 = __aeabi_uidivmod((uVar10 - uVar11) - *(int *)(iVar3 + 0x2e8),uVar1);
        *(int *)(iVar3 + 0x2ec) = iVar5 + 1;
        uVar15 = __aeabi_uidivmod((iVar5 + 2) * iVar6,iVar4);
        *(int *)(iVar3 + 0x2f0) = (int)uVar15;
        uVar11 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
        *(uint *)(iVar3 + 0x2f0) = uVar11;
      } while (*(uint *)(iVar3 + 0x2e0) != uVar11);
    }
    sd_format_progress_set(*(int *)(iVar3 + 0x2e0) + 0x20,*param_1);
    *(int *)(iVar3 + 0x2d4) = *(int *)(iVar3 + 0x2d4) - *(int *)(iVar3 + 0x2d0);
  }
  else {
    local_28 = 0xffffffff;
  }
  return local_28;
}


// ===== fat_format_volume @ 2013f79c (160 bytes)

/* [fact] parameters cleared, fat_format_layout, the MBR, boot sector, FSInfo (FAT32) and FATs, then
   the tail call of fat_format_clear_root; the whole volume format; was fat_clear_root_dir (T24
   round 8) */

void fat_format_volume(int *param_1)

{
  int iVar1;
  
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(*param_1 + 0x2c8,0,0x2c);
                    /* Computes the format layout from the CSD capacity [doc] */
  iVar1 = fat_format_layout(param_1);
  if ((((iVar1 == 0) && (iVar1 = fat_format_write_mbr(param_1), iVar1 == 0)) &&
      ((*(char *)(*param_1 + 0x2dc) == '@' ||
       ((iVar1 = fat_format_write_boot(param_1), iVar1 == 0 &&
        ((*(char *)(*param_1 + 0x2dc) != ' ' ||
         (iVar1 = fat32_format_write_fsinfo(param_1), iVar1 == 0)))))))) &&
     (iVar1 = fat_format_write_fats(param_1), iVar1 == 0)) {
    fat_format_clear_root(param_1);
    return;
  }
  return;
}


// ===== sd_fat_format @ 2013f83c (328 bytes)

/* card init (3 tries), then fat_clear_root_dir */

int sd_fat_format(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(param_1[1] + 0x24))();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = 0;
  do {
    iVar2 = (**(code **)(param_1[1] + 0x20))(2);
                    /* card reset/identify, card-type flags at +0x2C0/+0x2C2 [doc, inference] */
    if ((iVar2 == 0) && (iVar2 = sd_card_identify(param_1), iVar2 == 0)) {
      if (*(short *)(*param_1 + 0x2c6) == 1) {
        return -5;
      }
                    /* CMD9 with sd_csd_check / mmc_csd_check [doc] */
      iVar2 = sd_read_csd_cid(param_1);
      if ((((((iVar2 == 0) &&
             (iVar2 = sd_selected_op(*(undefined2 *)(*param_1 + 0x2aa),0x200,1,param_1), iVar2 == 0)
             ) && (iVar2 = sd_cmd7_select(*(undefined2 *)(*param_1 + 0x2aa),param_1), iVar2 == 0))
           && ((iVar2 = sd_scr_bus_width(param_1), iVar2 == 0 &&
               (iVar2 = sd_acmd6_set_bus_width(param_1), iVar2 == 0)))) &&
          ((iVar2 = sd_select_bus_speed(param_1), iVar2 == 0 &&
           (iVar2 = sd_card_clock(1,param_1), iVar2 == 0)))) &&
         (((*(short *)(*param_1 + 0x2c2) != 2 && *(short *)(*param_1 + 0x2c2) != 3 ||
           (iVar2 = (**(code **)(param_1[1] + 0x40))(), iVar2 == 0)) &&
          (iVar2 = fat_format_volume(param_1), iVar2 == 0)))) {
        return 0;
      }
    }
    iVar1 = iVar1 + 1;
    if (2 < iVar1) {
      return iVar2;
    }
  } while( true );
}


// ===== sd_format @ 2013f984 (96 bytes)

/* drive letter; -> sd_fat_format (inference: format, #83) */

uint sd_format(char param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int local_10;
  
  local_10 = DAT_20808ba0;
  iVar2 = fs_check_ready();
  if (iVar2 != 0) {
    return 0xfffffff8;
  }
  uVar1 = fs_toupper((int)param_1);
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
  iVar2 = fs_find_drive(uVar1,&local_10);
  if (iVar2 == 0) {
    if (*(int *)(local_10 + 0x24) == 0) {
      return 0xfffffff8;
    }
    uVar3 = sd_fat_format();
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}


// ===== sd_card_task_start @ 2013f9fc (80 bytes)

/* (drive rec, index): stores the drive in 0x20808B60[i] and creates and starts the "SDInsCheck"
   task once [fact] */

undefined4 sd_card_task_start(undefined4 param_1,int param_2)

{
  int iVar1;
  
  (&DAT_20808b60)[param_2] = param_1;
  *(undefined4 *)(&DAT_20808b5c + param_2 * 4) = 0;
  if (DAT_20808b58 == 0) {
    iVar1 = os_create_tsk_named(&DAT_2042053c,"SDInsCheck");
    if (iVar1 < 1) {
      return 0xffffffff;
    }
    DAT_20808b58 = iVar1;
    itron_act_tsk();
  }
  return 0;
}


// ===== sd_ins_check_task @ 2013fa60 (148 bytes)

/* Task "SDInsCheck": every 50 ticks asks the driver (op +8) for the card and sets / clears bit 6 of
   the drive byte +0x68 on a change [fact] */

void sd_ins_check_task(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  do {
    itron_dly_tsk(0x32);
    iVar3 = 0;
    do {
      if (*(int *)((&DAT_20808b60)[iVar3] + 0x24) != 0) {
        iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[iVar3] + 0x24) + 4) + 8))();
        if (iVar1 == 0) {
          if (*(int *)(&DAT_20808b5c + iVar3 * 4) != 1) {
            *(undefined4 *)(&DAT_20808b5c + iVar3 * 4) = 1;
            iVar1 = (&DAT_20808b60)[iVar3];
            bVar2 = *(byte *)(iVar1 + 0x68) | 0x40;
            goto LAB_2013fadc;
          }
        }
        else if (*(int *)(&DAT_20808b5c + iVar3 * 4) == 1) {
          *(undefined4 *)(&DAT_20808b5c + iVar3 * 4) = 0;
          iVar1 = (&DAT_20808b60)[iVar3];
          bVar2 = *(byte *)(iVar1 + 0x68) & 0xbf;
LAB_2013fadc:
          *(byte *)(iVar1 + 0x68) = bVar2;
        }
      }
      iVar3 = (int)(char)((char)iVar3 + '\x01');
    } while (iVar3 < 1);
  } while( true );
}


// ===== sd_card_remount @ 2013faf4 (152 bytes)

/* (index): fs_cache_invalidate + fs_drive_mount, or fs_drive_unmount, as the card state asks [fact]
    */

int sd_card_remount(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)((&DAT_20808b60)[param_1] + 0x24) == 0) {
    return -1;
  }
  iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[param_1] + 0x24) + 4) + 8))();
  if (iVar1 == 0) {
    uVar2 = (uint)*(char *)((&DAT_20808b60)[param_1] + 0x68);
    if ((uVar2 & 0x40) != 0) {
      iVar1 = 1;
      if ((uVar2 & 0x80) != 0) {
        return 1;
      }
                    /* Clears the FAT cache, the cluster bitmap [doc] */
      fs_cache_invalidate((&DAT_20808b60)[param_1]);
                    /* Driver op 7 [doc] */
      iVar3 = fs_drive_mount((&DAT_20808b60)[param_1]);
      goto joined_r0x2013fb7c;
    }
  }
  iVar1 = 0;
  if ((*(byte *)((&DAT_20808b60)[param_1] + 0x68) & 0x80) == 0) {
    return 0;
  }
  iVar3 = fs_drive_unmount();
joined_r0x2013fb7c:
  if (iVar3 != 0) {
    iVar1 = iVar3;
  }
  return iVar1;
}


// ===== sd_clmap_state_set @ 2013fb8c (20 bytes)

/* (v): 0x20808B64 = v (card mounted), clears the cluster-map flag 0x20808B68 [fact] */

void sd_clmap_state_set(undefined4 param_1)

{
  DAT_20808b64 = param_1;
  DAT_20808b68 = 0;
  return;
}


// ===== sd_clmap_prepare @ 2013fba0 (112 bytes)

/* Once per mount: at priority 6 builds the cluster map of drive I: (fs_clmap_attach_scan with a
   0x20000-byte buffer) and sets 0x20808B68 [fact] */

int sd_clmap_prepare(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((DAT_20808b64 != 0) && (DAT_20808b68 == 0)) {
    itron_chg_pri(0,6);
    uVar1 = clmap_buf_get();
                    /* fs_clmap_attach with a work buffer and scan = 1 [doc] */
    iVar2 = fs_clmap_attach_scan(0x49,uVar1,0x20000);
    itron_chg_pri(0);
    if (iVar2 == 0) {
      DAT_20808b68 = 1;
    }
    return iVar2;
  }
  return 0;
}


// ===== sd_mutex_create @ 2013fc10 (60 bytes)

/* Creates the SD mutex 0x20808B6C (TA_INHERIT) [fact] */

void sd_mutex_create(void)

{
  t_cmtx tStack_10;
  
  tStack_10.mtxatr = 2;
  tStack_10.ceilpri = 0;
  tStack_10.name = (char *)0x0;
  DAT_20808b6c = itron_acre_mtx(0,&tStack_10);
  return;
}


// ===== sd_mutex_lock @ 2013fc4c (28 bytes)

/* (lock): tloc_mtx when lock != 0, then unl_mtx [fact for the calls] */

void sd_mutex_lock(int param_1)

{
  if (param_1 != 0) {
    itron_tloc_mtx(DAT_20808b6c,0xffffffff);
    return;
  }
  itron_unl_mtx(DAT_20808b6c);
  return;
}


// ===== sd_card_poll @ 2013fc68 (212 bytes)

/* (index, state): card detect state machine of the card monitor: mounts on insertion
   (fs_cache_invalidate, fs_drive_mount under the mutex 0x20808B6C) and unmounts on removal; returns
   the new state [fact] */

uint sd_card_poll(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(int *)((&DAT_20808b60)[param_1] + 0x24) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[param_1] + 0x24) + 4) + 8))();
    if ((iVar1 == 0) && (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x40U) != 0)) {
      if ((param_2 & 0x40) == 0) {
        if (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x80U) == 0) {
          itron_tloc_mtx(DAT_20808b6c,0xffffffff);
                    /* Clears the FAT cache, the cluster bitmap [doc] */
          fs_cache_invalidate((&DAT_20808b60)[param_1]);
                    /* Driver op 7 [doc] */
          iVar1 = fs_drive_mount((&DAT_20808b60)[param_1]);
          itron_unl_mtx(DAT_20808b6c);
          if (iVar1 != 0) {
            return 0x40;
          }
          sd_clmap_state_set(1);
        }
        param_2 = 0xc0;
      }
    }
    else {
      param_2 = (int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0xffffff3f;
      if (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x80U) != 0) {
        sd_clmap_state_set(0);
        iVar1 = fs_drive_unmount((&DAT_20808b60)[param_1]);
        if (iVar1 == 0) {
          param_2 = 0;
        }
      }
    }
  }
  return param_2;
}


// ===== sd_delay_ms @ 2013fd3c (20 bytes)

/* (ms): itron_dly_tsk(ms / 10) [fact] */

void sd_delay_ms(int param_1)

{
  itron_dly_tsk(param_1 / 10);
  return;
}


// ===== sd_card_unmount @ 2013fd50 (32 bytes)

/* (drive): for an attached removable drive (+0x68 bit 0) runs driver op 8 and clears the mounted
   bit 7; error to fs_set_error; the card monitor calls it on request 0x20800098 (filesystem.md)
   [fact] */

void sd_card_unmount(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_20808b60)[param_1];
  if (*(int *)(iVar1 + 0x24) == 0) {
    return;
  }
  iVar2 = fs_check_ready();
  if (iVar2 != 0) {
    fs_set_error(iVar2,0);
    return;
  }
  if ((*(byte *)(iVar1 + 0x68) & 1) == 0) {
    fs_set_error(0xfffffff0,0);
    return;
  }
  iVar2 = (**(code **)(iVar1 + 0x18))(iVar1,8,0);
  if (iVar2 == 0) {
    *(byte *)(iVar1 + 0x68) = *(byte *)(iVar1 + 0x68) & 0x7f;
    fs_set_error(0,0);
    return;
  }
  fs_set_error_m2();
  return;
}


// ===== sd_card_write_protected @ 2013fd70 (32 bytes)

/* [fact] (index): bit 5 of +0x68 of the drive 0x20808B60[index], 0 without a handle; called from
   0x20103BC4; new entry (T24 round 8) */

uint sd_card_write_protected(int param_1)

{
  uint uVar1;
  
  if (*(int *)((&DAT_20808b60)[param_1] + 0x24) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(byte *)((&DAT_20808b60)[param_1] + 0x68) & 0x3f) >> 5;
  }
  return uVar1;
}


// ===== sdhi_drv_init @ 2013fd98 (60 bytes)

/* Driver init callback of drive I:: clears 0x2091CBA8, links the SDHI op table 0x20420564 and calls
   sd_driver_op (filesystem.md) [fact] */

void sdhi_drv_init(void)

{
  DAT_2091cba8 = 0;
  DAT_20808b44 = &DAT_2091cba8;
  DAT_20808b48 = &PTR_sdhi_wait_idle_20420564;
                    /* Driver entry of drive I [doc] */
  sd_driver_op();
  return;
}


// ===== sdhi_stub_2013fde4 @ 2013fde4 (4 bytes)

/* empty (bx lr); no caller found [fact] (T24 round 4) */

void sdhi_stub_2013fde4(void)

{
  return;
}


// ===== sdhi0_irq_enable @ 2013fde8 (104 bytes)

/* Registers the SDHI0 handler for GIC id 303 (0x12F) once (flag 0x20808B70), sets its ICDIPR75
   priority byte and enables it in ICDISER9 (bit 15) [fact] */

undefined4 sdhi0_irq_enable(void)

{
  uint gic_def_inh_ret;
  uint intc_icdipr75;
  
                    /* Interrupt priority 75 [sfr] */
  intc_icdipr75 = INTC_ICDIPR75;
  if (DAT_20808b70 == -1) {
    gic_def_inh_ret = gic_def_inh(0x12f,0x204205cc);
    if ((int)gic_def_inh_ret < 0) {
      return 0xffffffff;
    }
    DAT_20808b70 = 1;
  }
  INTC_ICDIPR75 = intc_icdipr75 & 0xffffff | 0x38000000;
  knl_int_disable();
                    /* Interrupt set-enable 9 [sfr] */
  INTC_ICDISER9 = 0x8000;
  knl_int_restore();
  return 0;
}


// ===== sdhi0_clock_on @ 2013fe50 (20 bytes)

/* STBCR12 &= 0xF3 */

void sdhi0_clock_on(void)

{
  byte cpg_stbcr12;
  
                    /* Standby control 12 [sfr] */
  cpg_stbcr12 = CPG_STBCR12;
  CPG_STBCR12 = cpg_stbcr12 & 0xf3;
  return;
}


// ===== sdhi_dma_open @ 2013fe68 (372 bytes)

/* [fact] the DMA side of sdhi_open (its tail call at 0x20140B94): DMARS0 0xC2/0xC1, the two DMA end
   interrupts (gic_def_inh, priority 0x38, ICDISER), CHCTRL0/1 SWRST; new entry (T24 round 7) */

undefined4 sdhi_dma_open(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  DAT_20808b82 = 0;
  DAT_20808b8e = 0;
                    /* DMA extended resource selector 0 [sfr] */
  uVar1 = DMAC_DMARS0;
  DMAC_DMARS0 = uVar1 & 0xffffff00;
  uVar1 = DMAC_DMARS0;
  DMAC_DMARS0 = uVar1 | 0xc2;
  uVar1 = DMAC_DMARS0;
  DMAC_DMARS0 = uVar1 & 0xff00ffff;
  uVar1 = DMAC_DMARS0;
  DMAC_DMARS0 = uVar1 | 0xc10000;
  uVar3 = *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b7c & 0xfffffffc));
  uVar1 = DAT_20808b7c & 3;
  if (DAT_20808b80 == -1) {
    uVar2 = gic_def_inh(DAT_20808b7c,DAT_20808b78);
    if ((int)uVar2 < 0) {
      return 0xffffffff;
    }
    DAT_20808b80 = '\x01';
  }
  *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b7c & 0xfffffffc)) =
       uVar3 & ~(0xff << (uVar1 << 3)) | 7 << (DAT_20808b7c & 3) * 8 + 3;
  uVar3 = *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b88 & 0xfffffffc));
  uVar1 = DAT_20808b88 & 3;
  if (DAT_20808b8c == -1) {
    uVar2 = gic_def_inh(DAT_20808b88,DAT_20808b84);
    if ((int)uVar2 < 0) {
      return 0xffffffff;
    }
    DAT_20808b8c = '\x01';
  }
  *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b88 & 0xfffffffc)) =
       uVar3 & ~(0xff << (uVar1 << 3)) | 7 << (DAT_20808b88 & 3) * 8 + 3;
                    /* Channel Control 0 [sfr] */
  uVar1 = DMAC_CHCTRL_0;
  DMAC_CHCTRL_0 = uVar1 | 8;
                    /* Channel Control 1 [sfr] */
  uVar1 = DMAC_CHCTRL_1;
  DMAC_CHCTRL_1 = uVar1 | 8;
  knl_int_disable();
  (&INTC_ICDISER0)[DAT_20808b7c >> 5] = 1 << (DAT_20808b7c & 0x1f);
  (&INTC_ICDISER0)[DAT_20808b88 >> 5] = 1 << (DAT_20808b88 & 0x1f);
  knl_int_restore();
  return 0;
}


// ===== sdhi_stub_2013ffdc @ 2013ffdc (4 bytes)

/* empty (bx lr); no caller found [fact] (T24 round 4) */

void sdhi_stub_2013ffdc(void)

{
  return;
}

