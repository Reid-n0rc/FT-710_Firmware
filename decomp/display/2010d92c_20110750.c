// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== update_dsp @ 2010d92c (316 bytes)

/* I:\AH076H_IFDSP.dat, I:\rom_writer.dat, AFDSP */

undefined8 update_dsp(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  uint local_2c;
  
  local_2c = param_4;
  do {
    do {
      uVar8 = 0xffffffff;
      iVar2 = itron_twai_flg(DAT_20800168,0xffff,5,&local_2c,0xffffffff,param_2,param_3);
      if (iVar2 != 0) {
        return CONCAT44(param_2,uVar8);
      }
    } while ((local_2c & 7) == 0);
    kbd_led_status(0,7);
    pcVar4 = "";
    param_2 = -((int)(local_2c << 0x1e) >> 0x1f);
    uVar6 = local_2c & 1;
    iVar2 = -((int)(local_2c << 0x10) >> 0x1f);
    uVar1 = local_2c & 0x1f;
    param_3 = -((int)(local_2c << 0x1d) >> 0x1f);
    while( true ) {
      kbd_led_status(0,7);
      itron_dly_tsk(100);
      kbd_led_status(1,7);
      if (iVar2 == 0) {
        if (uVar6 == 0 && param_2 == 0) {
          if (param_3 != 0) {
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
      iVar3 = fs_fopen(pcVar4,&DAT_2010dc28);
      if (iVar3 != 0) break;
      itron_dly_tsk(5);
    }
    if ((param_3 != 0) && (DAT_2045001d = '\x01', DAT_2045001c == '\0')) {
      iVar5 = 0x1e;
      do {
        bVar7 = iVar5 == 0;
        iVar5 = iVar5 + -1;
        if (bVar7) break;
        itron_dly_tsk(10);
      } while (DAT_2045001d == '\x01');
    }
    dsp_isp_program(iVar3,0,iVar2,uVar1 >> 4,uVar6);
    FUN_20141ff0(iVar3);
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
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_20800160 == '\0') {
    return;
  }
  iVar1 = hid_line_edit(&DAT_2081128c,param_1,param_2);
  if (iVar1 != 0) {
    iVar2 = strcmp("dsp1up",iVar1);
    if (iVar2 == 0) {
      uVar3 = 1;
    }
    else {
      iVar2 = strcmp("dsp2up",iVar1);
      if (iVar2 == 0) {
        uVar3 = 2;
      }
      else {
        iVar2 = strcmp("dsp3up",iVar1);
        if (iVar2 == 0) {
          uVar3 = 4;
        }
        else {
          iVar2 = strcmp("dsp1up/32",iVar1);
          if (iVar2 == 0) {
            uVar3 = 0x11;
          }
          else {
            iVar2 = strcmp("dsp2up/32",iVar1);
            if (iVar2 == 0) {
              uVar3 = 0x12;
            }
            else {
              iVar2 = strcmp("dsp3up/32",iVar1);
              if (iVar2 == 0) {
                uVar3 = 0x14;
              }
              else {
                iVar2 = strcmp("dsp1up/9",iVar1);
                if (iVar2 == 0) {
                  uVar3 = 0x8001;
                }
                else {
                  iVar2 = strcmp("dsp2up/9",iVar1);
                  if (iVar2 == 0) {
                    uVar3 = 0x8002;
                  }
                  else {
                    iVar2 = strcmp("dsp3up/9",iVar1);
                    if (iVar2 == 0) {
                      uVar3 = 0x8004;
                    }
                    else {
                      iVar2 = strcmp("dsp1up/32/9",iVar1);
                      if (iVar2 == 0) {
                        uVar3 = 0x8011;
                      }
                      else {
                        iVar2 = strcmp("dsp2up/32/9",iVar1);
                        if (iVar2 == 0) {
                          uVar3 = 0x8012;
                        }
                        else {
                          iVar1 = strcmp("dsp3up/32/9",iVar1);
                          if (iVar1 != 0) {
                            return;
                          }
                          uVar3 = 0x8014;
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
    itron_set_flg(DAT_20800168,uVar3);
    return;
  }
  return;
}


// ===== dspup_init @ 2010dcbc (92 bytes)

/* task "dspup" */

undefined8 dspup_init(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (0 < iVar1) {
    DAT_20800168 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_20165478);
    if ((0 < iVar1) && (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) {
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
  memclr(&DAT_208112c0,0xac);
  memclr(&DAT_20811380,0xac);
  memclr(&DAT_20811440,0xac);
  memclr(&DAT_20811500,0xac);
  memclr(&DAT_208115c0,0xac);
  DAT_2081166c = fwobj_main_ctor(&DAT_208115c0);
  memclr(&DAT_20811380,0xac);
  DAT_20811670 = fwobj_display_ctor(&DAT_20811380);
  DAT_20811674 = fwobj_ifdsp_ctor(&DAT_20811440,1);
  DAT_20811678 = fwobj_sdr_ctor(&DAT_20811500,1);
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
  uVar1 = FUN_201640ec(auStack_28,"MAIN");
  memcpy(DAT_2081166c + 4,uVar1,10);
  uVar1 = FUN_201640ec(auStack_28,"DISPLAY");
  memcpy(DAT_20811670 + 4,uVar1,10);
  uVar1 = FUN_201640ec(auStack_28,&DAT_2010df60);
  memcpy(DAT_20811674 + 4,uVar1,10);
  uVar1 = FUN_201640ec(auStack_28,&DAT_2010df64);
  memcpy(DAT_20811678 + 4,uVar1,10);
  fwname_pattern_init(DAT_2081166c + 0x14,"FT-710_MAIN_V",&DAT_2010df68);
  fwname_pattern_init(DAT_20811670 + 0x14,"FT-710_DISPLAY_V",&DAT_2010df68);
  fwname_pattern_init(DAT_20811674 + 0x14,"FT-710_IFDSP_V",&DAT_2010df68);
  fwname_pattern_init(DAT_20811678 + 0x14,"FT-710_SDR_V",&DAT_2010df68);
  iVar2 = 0;
  do {
    *(undefined1 *)(param_1 + iVar2 * 0x48) = 0;
    fwobj_set_status((&DAT_2081166c)[iVar2],"File checking");
    iVar3 = param_1 + iVar2 * 0x48;
    FUN_201550dc(iVar3 + 0x15,(&DAT_2081166c)[iVar2] + 0x89);
    *(undefined1 *)((&DAT_2081166c)[iVar2] + 0xa9) = 0;
    *(undefined4 *)(iVar3 + 0x34) = 0;
    *(undefined4 *)(iVar3 + 0x38) = 0;
    FUN_201635e4((&DAT_2081166c)[iVar2],iVar3 + 1);
    FUN_201635b8((&DAT_2081166c)[iVar2],iVar3 + 0x29);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return;
}


// ===== fwupdate_set_hotkey @ 2010dfc4 (12 bytes)

/* stores the held USB key usage (0x3A = F1 enables #UP0 loader files) */

void fwupdate_set_hotkey(undefined1 param_1)

{
  DAT_20800181 = param_1;
  return;
}


// ===== fwfile_status_text @ 2010dfd0 (484 bytes)

/* Ready / (Broken file) / (No such file) */

undefined4 fwfile_status_text(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    iVar1 = iVar5 + 1;
    *(undefined1 *)(param_1 + iVar5 * 0x48) = 2;
    iVar5 = iVar1;
  } while (iVar1 < 4);
  uVar2 = FUN_2014c410("I:\\FT-710");
  iVar5 = 0;
  do {
    FUN_2016040c((&DAT_2081166c)[iVar5]);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  do {
    do {
      piVar3 = (int *)FUN_2014ca4c(uVar2);
      if (piVar3 == (int *)0x0) {
        thunk_FUN_2014c474(uVar2);
        iVar5 = 0;
        do {
          if (*(char *)((&DAT_2081166c)[iVar5] + 0x57) == '\0') {
            *(undefined1 *)(param_1 + iVar5 * 0x48) = 2;
            fwobj_set_status((&DAT_2081166c)[iVar5],"(No such file)");
            *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9) = 2;
          }
          else {
            fwobj_version_from_name((&DAT_2081166c)[iVar5]);
            fwobj_build_path((&DAT_2081166c)[iVar5],"I:\\FT-710\\");
            iVar1 = (*(code *)**(undefined4 **)(&DAT_2081166c)[iVar5])
                              ((undefined4 *)(&DAT_2081166c)[iVar5],0);
            *(char *)((&DAT_2081166c)[iVar5] + 0x36) = (char)iVar1;
            if (iVar1 == 0) {
              *(undefined1 *)(param_1 + iVar5 * 0x48) = 1;
              fwobj_set_status((&DAT_2081166c)[iVar5],"Ready");
              *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9) = 1;
            }
            else {
              *(undefined1 *)(param_1 + iVar5 * 0x48) = 3;
              fwobj_set_status((&DAT_2081166c)[iVar5],"(Broken file)");
              *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9) = 3;
            }
          }
          iVar1 = param_1 + iVar5 * 0x48;
          FUN_201635e4((&DAT_2081166c)[iVar5],iVar1 + 1);
          FUN_201550dc(iVar1 + 0x15,(&DAT_2081166c)[iVar5] + 0x89);
          FUN_201635b8((&DAT_2081166c)[iVar5],iVar1 + 0x29);
          FUN_20163770(iVar1 + 0x3c,(&DAT_2081166c)[iVar5] + 0x2c);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 4);
        return 0;
      }
      iVar5 = FUN_201476f0((int)*(char *)(*piVar3 + 0xb),0x20);
    } while (iVar5 != 0);
    iVar5 = 0;
    do {
      if ((param_2 == 0) || (*(int *)(param_1 + iVar5 * 0x48 + 0x34) != 0)) {
        uVar4 = FUN_20155122((int)piVar3 + 10);
        iVar1 = fwobj_match_name((&DAT_2081166c)[iVar5],(int)piVar3 + 10,uVar4);
        if (iVar1 != 0) break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  } while( true );
}


// ===== task_fwupdate @ 2010e1f8 (200 bytes)

void task_fwupdate(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_2c [8];
  
  while (iVar1 = itron_twai_flg(DAT_20800188,0xffff,5,auStack_2c,0xffffffff), iVar1 == 0) {
    iVar1 = 0;
    do {
      if (*(char *)((&DAT_2081166c)[iVar1] + 0x88) != '\0') {
        *(undefined1 *)((&DAT_2081166c)[iVar1] + 0xa9) = 4;
        progress_set(0);
        iVar2 = (*(code *)**(undefined4 **)(&DAT_2081166c)[iVar1])
                          ((undefined4 *)(&DAT_2081166c)[iVar1],0,1);
        if (iVar2 == 0) {
          pcVar3 = "Finished";
          *(undefined1 *)((&DAT_2081166c)[iVar1] + 0xa9) = 5;
        }
        else {
          pcVar3 = "failed";
          *(undefined1 *)((&DAT_2081166c)[iVar1] + 0xa9) = 6;
        }
        fwobj_set_status((&DAT_2081166c)[iVar1],pcVar3);
        *(undefined1 *)((&DAT_2081166c)[iVar1] + 0xaa) = 1;
      }
      FUN_20150dcc(0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
  }
  return;
}


// ===== fwupdate_poll @ 2010e2d4 (440 bytes)

/* starts task_fwupdate once, then 0 running / 1 all OK / 2 any failed */

undefined1 fwupdate_poll(int param_1)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if (DAT_20800180 == '\0') {
    iVar5 = 0;
    do {
      if ((*(char *)(param_1 + iVar5 * 0x48) == '\x01') &&
         (*(int *)(param_1 + iVar5 * 0x48 + 0x34) == 0)) {
        fwobj_set_status((&DAT_2081166c)[iVar5],"(Skipped)");
      }
      fwobj_select((&DAT_2081166c)[iVar5],*(int *)(param_1 + iVar5 * 0x48 + 0x34) != 0);
      if (*(char *)((&DAT_2081166c)[iVar5] + 0x88) != '\0') {
        fwobj_set_status((&DAT_2081166c)[iVar5],"Waiting");
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    DAT_20800180 = '\x01';
    itron_set_flg(DAT_20800188,1);
    iVar5 = 0;
    do {
      iVar6 = param_1 + iVar5 * 0x48;
      FUN_201550dc(iVar6 + 0x15,(&DAT_2081166c)[iVar5] + 0x89);
      uVar4 = progress_get();
      *(undefined4 *)(iVar6 + 0x38) = uVar4;
      FUN_201635e4((&DAT_2081166c)[iVar5],iVar6 + 1);
      FUN_201635b8((&DAT_2081166c)[iVar5],iVar6 + 0x29);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  else {
    FUN_20150dcc(0);
    iVar5 = 0;
    do {
      iVar6 = param_1 + iVar5 * 0x48;
      FUN_201550dc(iVar6 + 0x15,(&DAT_2081166c)[iVar5] + 0x89);
      *(undefined1 *)(param_1 + iVar5 * 0x48) = *(undefined1 *)((&DAT_2081166c)[iVar5] + 0xa9);
      uVar4 = progress_get();
      *(undefined4 *)(iVar6 + 0x38) = uVar4;
      FUN_201635e4((&DAT_2081166c)[iVar5],iVar6 + 1);
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
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  return 0;
}


// ===== FUN_2010e4a0 @ 2010e4a0 (12 bytes)

void FUN_2010e4a0(void)

{
  FUN_20151934(DAT_20800184);
  return;
}


// ===== fwupdate_init @ 2010e4ac (104 bytes)

/* task "fwupdate" */

void fwupdate_init(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  fwobj_create_all();
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  iVar1 = itron_acre_flg(0,&local_18);
  if (0 < iVar1) {
    DAT_20800188 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_201654a0);
    if (0 < iVar1) {
      DAT_20800184 = iVar1;
      itron_sta_tsk(iVar1,0);
    }
  }
  return;
}


// ===== mainlink_fw_mode_cmd @ 2010e514 (264 bytes)

/* F1 <code> frame to MAIN on SCIF5 at 345600, waits for 0x06 */

undefined4 mainlink_fw_mode_cmd(char param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_20[0] = '\0';
  local_18 = 0;
  iVar4 = 0;
  mainlink_rx_ctrl(1);
  piVar1 = (int *)scif5_get(0);
  iVar3 = 2;
  (**(code **)(*piVar1 + 4))(piVar1,0x54600,8,0,2,iVar4);
  iVar2 = mainlink_got_frame60();
  if (iVar2 == 0) {
    return 1;
  }
  local_18._0_2_ = CONCAT11(param_1,0xf1);
  iVar2 = 0;
  local_14 = CONCAT13(param_1 + -0xf,(undefined3)local_14);
  while( true ) {
    iVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,&local_18,8,*(code **)(*piVar1 + 0x24),iVar3,iVar4)
    ;
    if (iVar3 != 8) {
      return 0;
    }
    iVar4 = (**(code **)(*piVar1 + 0x18))(piVar1,local_20,1,0xdc);
    if ((iVar4 != -1) && (local_20[0] == '\x06')) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
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

int srec_parse_line(char *param_1,uint *param_2,undefined1 *param_3)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  uVar8 = 0;
  if (*param_1 != 'S') {
    return -1;
  }
  pcVar1 = param_1 + 2;
  switch(param_1[1]) {
  case '0':
    return 0;
  case '1':
    iVar7 = 2;
    goto LAB_2010e6e0;
  case '2':
    iVar7 = 3;
    goto LAB_2010e6e0;
  case '3':
    iVar7 = 4;
LAB_2010e6e0:
    uVar2 = hex2_parse(pcVar1);
    if (uVar2 - 1 < 0xff) {
      iVar6 = 0;
      uVar3 = uVar2;
      while( true ) {
        uVar5 = uVar3 & 0xff;
        pcVar1 = pcVar1 + 2;
        if (iVar7 <= iVar6) break;
        uVar3 = hex2_parse(pcVar1);
        if ((int)uVar3 < 0) {
          return -1;
        }
        uVar8 = uVar3 | uVar8 << 8;
        uVar3 = uVar3 + uVar5;
        iVar6 = iVar6 + 1;
      }
      iVar6 = (uVar2 - iVar7) + -1;
      if ((uVar2 - iVar7) - 2 < 0x10) {
        *param_2 = uVar8;
        for (iVar7 = 0; iVar7 < iVar6; iVar7 = iVar7 + 1) {
          iVar4 = hex2_parse(pcVar1);
          pcVar1 = pcVar1 + 2;
          if (iVar4 < 0) break;
          *param_3 = (char)iVar4;
          uVar5 = uVar5 + iVar4 & 0xff;
          param_3 = param_3 + 1;
        }
        uVar8 = hex2_parse(pcVar1);
        bVar9 = uVar8 == 0;
        if (-1 < (int)uVar8) {
          bVar9 = (~uVar5 & 0xff) == uVar8;
        }
        if (bVar9) {
          return iVar6;
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

undefined4 srec_load_image(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_148 [128];
  undefined1 auStack_c8 [128];
  undefined1 auStack_48 [56];
  uint local_10;
  
  if ((param_3 == 0) || (iVar1 = sfl_read_header(param_1,0,param_3), iVar1 == 0)) {
    sfl_stream_init(auStack_48,param_1);
    while( true ) {
      local_10 = 0;
      memclr(auStack_148,0x80);
      iVar1 = sfl_stream_gets(auStack_c8,0x100,auStack_48);
      uVar2 = 0;
      if (iVar1 == 0) break;
      iVar1 = srec_parse_line(auStack_c8,&local_10,auStack_148);
      if (iVar1 < 0) goto LAB_2010e84c;
      if (iVar1 != 0) {
        if (0x7ffff < local_10) goto LAB_2010e84c;
        memcpy(local_10 + param_2,auStack_148);
      }
    }
  }
  else {
LAB_2010e84c:
    uVar2 = 1;
  }
  return uVar2;
}


// ===== srec_load_range @ 2010e868 (264 bytes)

/* S-records inside [start,end] into a buffer */

int srec_load_range(undefined4 param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  undefined1 local_158 [128];
  undefined1 auStack_d8 [128];
  undefined1 auStack_58 [56];
  uint local_20;
  
  iVar4 = 0;
  if ((param_5 == 0) || (iVar1 = sfl_read_header(param_1,0,param_3), iVar1 == 0)) {
    sfl_stream_init(auStack_58,param_1);
    while( true ) {
      local_20 = 0;
      memclr(local_158,0x80);
      iVar3 = 0;
      iVar1 = sfl_stream_gets(auStack_d8,0x80,auStack_58);
      if (iVar1 == 0) break;
      iVar1 = srec_parse_line(auStack_d8,&local_20,local_158);
      if (iVar1 < 0) goto LAB_2010e90c;
      if (iVar1 != 0) {
        bVar6 = param_3 <= local_20;
        bVar5 = local_20 == param_3;
        if (!bVar6 || bVar5) {
          uVar2 = (local_20 + iVar1) - 1;
          bVar6 = uVar2 <= param_2;
          bVar5 = param_2 == uVar2;
        }
        if (!bVar6 || bVar5) {
          for (; iVar3 < iVar1; iVar3 = iVar3 + 1) {
            uVar2 = local_20 + iVar3;
            if (param_2 <= uVar2 && uVar2 <= param_3) {
              iVar4 = iVar4 + 1;
              *(undefined1 *)(param_4 + (uVar2 - param_2)) = local_158[iVar3];
            }
          }
        }
      }
    }
  }
  else {
LAB_2010e90c:
    iVar4 = -1;
  }
  return iVar4;
}


// ===== srec_find_range @ 2010e970 (260 bytes)

/* min/max S-record address inside an area */

undefined4
srec_find_range(undefined4 param_1,uint param_2,uint param_3,uint *param_4,uint *param_5,int param_6
               )

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  undefined1 auStack_158 [128];
  undefined1 auStack_d8 [128];
  undefined1 auStack_58 [56];
  uint local_20 [2];
  
  if ((param_6 == 0) || (iVar1 = sfl_read_header(param_1,0,param_3), iVar1 == 0)) {
    sfl_stream_init(auStack_58,param_1);
    *param_4 = param_3;
    *param_5 = param_2;
    while( true ) {
      local_20[0] = 0;
      memclr(auStack_d8,0x80);
      iVar1 = sfl_stream_gets(auStack_158,0x80,auStack_58);
      uVar2 = 0;
      if (iVar1 == 0) break;
      iVar1 = srec_parse_line(auStack_158,local_20,auStack_d8);
      if (iVar1 < 0) goto LAB_2010ea14;
      if (iVar1 != 0) {
        bVar6 = param_3 <= local_20[0];
        bVar5 = local_20[0] == param_3;
        if (!bVar6 || bVar5) {
          uVar4 = (local_20[0] + iVar1) - 1;
          bVar6 = uVar4 <= param_2;
          bVar5 = param_2 == uVar4;
        }
        if (!bVar6 || bVar5) {
          bVar6 = local_20[0] <= *param_4;
          bVar5 = *param_4 == local_20[0];
          if (bVar6 && !bVar5) {
            *param_4 = local_20[0];
            bVar6 = local_20[0] <= param_2;
            bVar5 = param_2 == local_20[0];
          }
          if (bVar6 && !bVar5) {
            *param_4 = param_2;
          }
          uVar3 = *param_5;
          uVar4 = (iVar1 + local_20[0]) - 1;
          if (uVar3 < uVar4) {
            *param_5 = uVar4;
          }
          if (uVar3 < uVar4 && param_3 < uVar4) {
            *param_5 = param_3;
          }
        }
      }
    }
  }
  else {
LAB_2010ea14:
    uVar2 = 0xffffffff;
  }
  return uVar2;
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
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int in_r3;
  int local_1c;
  
  local_1c = in_r3;
LAB_2010ea9c:
  iVar1 = itron_twai_flg(DAT_20800190,1,5,&local_1c,0xffffffff);
  if (iVar1 != 0) {
    return;
  }
  FUN_20126160(1);
  itron_dly_tsk(0x14);
  uVar2 = FUN_20111174(0);
  kbd_led_status(0,7);
  do {
    kbd_led_status(0,7);
    itron_dly_tsk(100);
    kbd_led_status(1,7);
    pcVar3 = "I:\\AH076H_HEW.mot";
    if (local_1c == 2) {
      pcVar3 = "I:\\AH068H_HEW.mot";
    }
    iVar1 = fs_fopen(pcVar3,&DAT_2010ed58);
    if (iVar1 == 0) {
      DAT_2080018c = 0x31d;
    }
    else {
      kbd_led_status(2,7);
      DAT_2080018c = 0x327;
      itron_dly_tsk(1);
      FUN_2015525c(uVar2,0x80000,0xff);
      iVar4 = srec_load_image(iVar1,uVar2,0);
      FUN_20141ff0(iVar1);
      if (iVar4 == 0) break;
    }
    itron_dly_tsk(5);
  } while( true );
  gpio_p7_9_11(1);
  gpio_rx_update(1);
  gpio_rx_reset(1);
  itron_dly_tsk(1);
  gpio_rx_reset(0);
  itron_dly_tsk(1);
  iVar1 = uptest_program_stub(uVar2,0x80000,0);
  if (iVar1 == 0) {
    kbd_led_status(7);
    DAT_2080018c = 0x1e61;
    gpio_rx_reset(1);
    itron_dly_tsk(1);
    gpio_rx_reset(0);
    uVar2 = 1;
  }
  else {
    DAT_2080018c = (short)((uint)iVar1 >> 0x10) + 9000;
    kbd_led_status(5,7);
    uVar2 = 10;
  }
  itron_dly_tsk(uVar2);
  FUN_20133620();
  FUN_20126160(0);
  goto LAB_2010ea9c;
}


// ===== uptest_line @ 2010ec44 (232 bytes)

/* uptest, uptest2, mrst, rf0, rf1 */

void uptest_line(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = hid_line_edit(&DAT_2081167c,param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
  iVar2 = strcmp("uptest",iVar1);
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    iVar2 = strcmp("uptest2",iVar1);
    if (iVar2 != 0) {
      iVar2 = strcmp(&DAT_2010ed70,iVar1);
      if (iVar2 == 0) {
        gpio_p7_9_11(1);
        gpio_rx_reset(1);
        itron_dly_tsk(1);
        gpio_rx_reset(0);
        itron_dly_tsk(1);
        return;
      }
      iVar2 = strcmp(&DAT_2010ed78,iVar1);
      if (iVar2 == 0) {
        DAT_20800194 = 1;
      }
      else {
        iVar1 = strcmp(&DAT_2010ed7c,iVar1);
        if (iVar1 != 0) {
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
    uVar3 = 2;
  }
  itron_set_flg(DAT_20800190,uVar3);
  return;
}


// ===== uptest_init @ 2010ed80 (92 bytes)

/* task "uptest" (update_main_cpu) */

undefined8 uptest_init(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (0 < iVar1) {
    DAT_20800190 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_201654c8);
    if ((0 < iVar1) && (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) {
      pcVar2 = uptest_line;
      goto LAB_2010edd8;
    }
  }
  pcVar2 = (code *)0x0;
LAB_2010edd8:
  return CONCAT44(local_10,pcVar2);
}


// ===== mainlink_rx_block_write @ 2010ede8 (192 bytes)

/* 'E' (0x45): MAIN writes into the 32000-byte block 0x208116A6, reply C5 */

undefined4 mainlink_rx_block_write(char *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uStack_18;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  uint uStack_14;
  
  uVar1 = be16_load(param_1 + 1);
  uVar1 = uVar1 & 0xffff;
  uVar2 = be16_load(param_1 + 3);
  if (((uVar1 < DAT_208116a2) && (uVar2 = uVar1 + (uVar2 & 0xffff), uVar2 <= DAT_208116a2)) &&
     (DAT_208116a0 == *param_1)) {
    DAT_208116a4 = (undefined2)uVar2;
    memcpy(&DAT_208116a6 + uVar1,param_1 + 5);
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
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uStack_120;
  char cStack_11f;
  char cStack_11e;
  char cStack_11d;
  undefined4 uStack_11c;
  undefined1 auStack_118 [256];
  
  uVar1 = be16_load(param_1 + 1);
  uVar1 = uVar1 & 0xffff;
  uVar2 = be16_load(param_1 + 3);
  if (((uVar1 < DAT_208116a2) && (uVar3 = uVar1 + (uVar2 & 0xffff), uVar3 <= DAT_208116a2)) &&
     (DAT_208116a0 == *param_1)) {
    DAT_208116a4 = (undefined2)uVar3;
    memclr(auStack_118,0xfe);
    _uStack_120 = CONCAT13(param_1[2],CONCAT12(param_1[1],CONCAT11(*param_1,0xc4)));
    uStack_11c = (uint)*(ushort *)(param_1 + 3);
    memcpy((int)&uStack_11c + 2,&DAT_208116a6 + uVar1,uVar2 & 0xffff);
    mainlink_queue_frame(&uStack_120,0x106);
    return 1;
  }
  return 0;
}


// ===== FUN_2010ef88 @ 2010ef88 (320 bytes)

int FUN_2010ef88(int param_1,int param_2,int param_3)

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
  
  iVar2 = FUN_2014c410(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
  iVar5 = 0;
  if (iVar2 != 0) {
    FUN_20126160(1);
    iVar3 = FUN_20111174(0x8350);
    iVar8 = 0;
LAB_2010efc4:
    do {
      do {
        do {
          piVar4 = (int *)FUN_2014ca4c(iVar2);
          iVar5 = iVar8;
          if (piVar4 == (int *)0x0) goto LAB_2010f068;
          iVar5 = FUN_201476f0((int)*(char *)(*piVar4 + 0xb),0x20);
        } while (iVar5 != 0);
        iVar5 = (int)piVar4 + 10;
        uVar6 = FUN_20155122(iVar5);
        uVar1 = uVar6;
      } while (0x13 < uVar6);
      do {
        uVar1 = uVar1 - 1;
        if ((int)uVar1 < 1) goto LAB_2010efc4;
      } while ((*(char *)(iVar5 + uVar1) != '.') ||
              (iVar7 = FUN_2014e208(iVar5 + uVar1,&DAT_2010f0d0), iVar7 != 0));
      FUN_2014e2e4(iVar3 + iVar8 * 0x10,iVar5,uVar6 - 4);
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
    thunk_FUN_2014c474(iVar2);
    if (iVar5 != 0) {
      FUN_20154fca(iVar3,iVar5,0x10,FUN_2014e208);
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          memcpy(param_2 + iVar2 * 0x10,iVar3 + iVar2 * 0x10,0x10);
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar5);
      }
    }
    FUN_20133620();
    FUN_20126160(0);
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
  int iVar4;
  char *local_40;
  undefined1 auStack_3c [16];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  byte local_24 [8];
  
  rtc_get_date(local_2c,local_28,local_24);
  local_40 = (char *)(uint)local_24[0];
  sprintf(auStack_3c,"20%02X_%02X_%02X_NN",local_2c[0],local_28[0]);
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_3) {
    do {
      iVar4 = param_2 + iVar3 * 0x10;
      iVar1 = FUN_20155122(iVar4);
      if (((iVar1 == 0xd) && (iVar1 = strncmp(auStack_3c,iVar4,0xb), iVar1 == 0)) &&
         (iVar1 = FUN_20111374(iVar4 + 0xb,2,&local_40), *local_40 == '\0')) {
        if (iVar1 != iVar2) break;
        iVar2 = iVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
    if (99 < iVar2) {
      iVar2 = 99;
    }
  }
  memcpy(param_4,auStack_3c,0xb);
  sprintf(param_4 + 0xb,&DAT_2010f1d8,iVar2);
  return;
}


// ===== sdmenu_file_exists @ 2010f1e0 (84 bytes)

undefined4 sdmenu_file_exists(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [44];
  
  sprintf(auStack_30,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + param_1 * 4),param_2);
  iVar1 = FUN_2014af14(auStack_30);
  if ((iVar1 == -1) || (iVar1 = FUN_201476f0((int)(char)iVar1,1), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== sdmenu_req_save @ 2010f240 (68 bytes)

/* MAIN transfer code 0x41 (MemList) / 0x43 (Menu) */

void sdmenu_req_save(int param_1,undefined2 param_2)

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

void sdmenu_req_load(int param_1,undefined2 param_2)

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


// ===== sdmenu_select @ 2010f2e8 (24 bytes)

void sdmenu_select(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  DAT_2080019d = param_1;
  DAT_2080019e = param_3;
  memcpy(&DAT_208193a6,param_2,0x10);
  return;
}


// ===== sdmenu_select_load @ 2010f300 (92 bytes)

void sdmenu_select_load(int param_1,int param_2,int param_3,undefined1 param_4)

{
  DAT_2080019d = (undefined1)param_1;
  DAT_2080019e = param_4;
  memcpy(&DAT_208193a6,param_2 + param_3 * 0x10,0x10);
  if (param_1 != 0) {
    if (param_1 == 1) {
      DAT_208116a0 = 0x44;
      DAT_208116a2 = 32000;
    }
    return;
  }
  DAT_208116a0 = 0x42;
  DAT_208116a2 = 32000;
  return;
}


// ===== sd_present @ 2010f35c (20 bytes)

bool sd_present(void)

{
  int iVar1;
  
  iVar1 = FUN_20103bc0();
  return iVar1 != 0;
}


// ===== sdmenu_write_dat @ 2010f370 (624 bytes)

/* 9 x 64-byte text lines ("MemList  n  CRC") + 0x7D10 encoded bytes */

undefined4
sdmenu_write_dat(undefined4 param_1,int param_2,undefined4 param_3,int param_4,uint param_5,
                undefined4 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int extraout_r1;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 auStack_78 [62];
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  iStack_28 = param_4;
  FUN_2015525c(auStack_78,0x40,0x20);
  local_39 = 10;
  local_3a = 0xd;
  iVar6 = 0;
  uVar9 = FUN_20164d54(param_5 + 0x240);
  uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar1 = (undefined4)uVar9;
  iVar7 = 0;
  do {
    iVar8 = iVar7;
    iVar7 = iVar8 + 0x40;
    uVar9 = FUN_20164d54(iVar7);
    uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
    uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
    progress_scale(param_6,uVar3,(int)uVar9,uVar3);
    progress_set();
    FUN_20150dcc(0);
    uVar2 = fs_fwrite(auStack_78,1,0x40,local_34);
    if (uVar2 < 0x40) {
      return 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  local_38 = 0x139eeca6;
  crc32_make_table();
  uVar3 = crc32_update(0xffffffff,param_5,param_4);
  uVar2 = crc32_update(uVar3,4,&local_38);
  if (param_2 == 0) {
    pcVar5 = "MemList";
  }
  else {
    pcVar5 = "Menu";
  }
  sprintf(auStack_78,"%s  %d  %08X",pcVar5,param_3,~uVar2);
  iVar7 = FUN_20155122(auStack_78);
  iVar8 = iVar8 + 0x80;
  auStack_78[iVar7] = 0x20;
  uVar9 = FUN_20164d54(iVar8);
  uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
  uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
  progress_scale(param_6,uVar3,(int)uVar9,uVar3);
  progress_set();
  FUN_20150dcc(0);
  uVar2 = fs_fwrite(auStack_78,1,0x40,local_34);
  if (0x3f < uVar2) {
    FUN_20156260(param_5,0x100);
    iVar7 = 0;
    if (param_5 >> 8 != 0) {
      do {
        iVar8 = iVar8 + 0x100;
        uVar9 = FUN_20164d54(iVar8);
        uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
        uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
        progress_scale(param_6,uVar3,(int)uVar9,uVar3);
        progress_set();
        FUN_20150dcc(0);
        iVar6 = fs_fwrite(param_4,1,0x100,local_34);
        if (iVar6 < 0x100) {
          return 2;
        }
        iVar7 = iVar7 + 1;
        param_4 = param_4 + 0x100;
      } while (iVar7 < (int)(param_5 >> 8));
    }
    if (extraout_r1 != 0) {
      uVar9 = FUN_20164d54(iVar8 + extraout_r1);
      uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
      uVar1 = (undefined4)((ulonglong)uVar9 >> 0x20);
      progress_scale(param_6,uVar1,(int)uVar9,uVar1);
      progress_set();
      FUN_20150dcc(0);
      iVar7 = fs_fwrite(param_4,1,extraout_r1,local_34);
      if (iVar7 < extraout_r1) {
        return 2;
      }
    }
    return 0;
  }
  return 2;
}


// ===== sdmenu_save_file @ 2010f60c (488 bytes)

/* <dir>\<name>.dat, sfl_encode, salted CRC-32 */

int sdmenu_save_file(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  undefined8 uVar4;
  undefined1 auStack_50 [40];
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [12];
  
  progress_range_init(&local_28,1,5);
  progress_set(local_28);
  iVar1 = FUN_2013fba0();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_2014c410(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
  if (iVar1 == 0) {
    iVar1 = FUN_2014c410("I:\\FT-710");
    if (iVar1 == 0) {
      iVar1 = FUN_2014beec("I:\\FT-710");
      if (iVar1 != 0) goto LAB_2010f7b8;
    }
    else {
      thunk_FUN_2014c474();
    }
    uVar4 = FUN_2014beec(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
    uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
    if ((int)uVar4 != 0) goto LAB_2010f7b8;
  }
  else {
    thunk_FUN_2014c474();
    uVar3 = extraout_r1;
  }
  progress_scale(&local_28,uVar3,0,0x3fe00000);
  progress_set();
  sprintf(auStack_50,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + param_1 * 4),param_2);
  iVar1 = fs_fopen(auStack_50,&DAT_2010f804);
  if (iVar1 != 0) {
    FUN_20126160(1);
    iVar2 = FUN_20111174(0x8350);
    FUN_20155274(iVar2 + 0x640,0x7d10);
    *(char *)(iVar2 + 0x640) = (char)param_1;
    *(char *)(iVar2 + 0x641) = (char)((uint)param_1 >> 8);
    *(char *)(iVar2 + 0x642) = (char)((uint)param_1 >> 0x10);
    *(char *)(iVar2 + 0x643) = (char)((uint)param_1 >> 0x18);
    *(char *)(iVar2 + 0x644) = (char)param_3;
    *(char *)(iVar2 + 0x645) = (char)((uint)param_3 >> 8);
    *(char *)(iVar2 + 0x646) = (char)((uint)param_3 >> 0x10);
    *(char *)(iVar2 + 0x647) = (char)((uint)param_3 >> 0x18);
    memcpy(iVar2 + 0x650,&DAT_208116a6,32000);
    sfl_encode(0,iVar2 + 0x640,0x7d10);
    progress_scale(&local_28,extraout_r1_00,0,0x3ff00000);
    progress_set();
    progress_range_init(auStack_20,local_24,99);
    iVar2 = sdmenu_write_dat(iVar1,param_1,param_3,iVar2 + 0x640,0x7d10,auStack_20);
    FUN_20133620();
    FUN_20126160(0);
    if (iVar2 == 0) {
      FUN_2013fc4c(1);
      iVar2 = FUN_20141ff0(iVar1);
      FUN_2013fc4c(0);
      progress_set(100);
    }
    else {
      iVar2 = FUN_2014d95c();
      FUN_20141ff0(iVar1);
    }
    return iVar2;
  }
LAB_2010f7b8:
  iVar1 = FUN_2014d95c();
  return iVar1;
}


// ===== sdmenu_load_file @ 2010f81c (876 bytes)

/* WARNING: Type propagation algorithm not settling */
/* RENAME (was sfl_load_file): loads a MemList/Menu .dat (size 0x7F50), checks CRC, type and model
   word */

undefined4 sdmenu_load_file(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 auStack_1a8 [64];
  undefined1 local_168;
  undefined1 auStack_a8 [40];
  int local_80;
  undefined1 *local_7c;
  undefined1 auStack_78 [52];
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34 [3];
  undefined4 *local_28;
  
  local_28 = param_1;
  progress_set(*param_1);
  sprintf(auStack_a8,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + (uint)DAT_2080019d * 4),
          &DAT_208193a6);
  if (DAT_2080019d < 2) {
    iVar1 = FUN_2014aec8(auStack_a8,auStack_78);
    if (iVar1 == 0) {
      if ((local_44 == 0x7f50) && (local_80 = fs_fopen(auStack_a8,&DAT_2010fb88), local_80 != 0)) {
        iVar1 = 0;
        iVar6 = 0;
        local_7c = auStack_1a8;
        uVar7 = FUN_20164d82(0x7f50);
        uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
        do {
          iVar1 = iVar1 + 0x40;
          uVar8 = FUN_20164d54(iVar1);
          uVar8 = FUN_201649d8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,uVar4);
          uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
          progress_scale(local_28,uVar5,(int)uVar8,uVar5);
          progress_set();
          iVar2 = fs_fread(auStack_1a8,1,0x40,local_80);
          if (iVar2 == 0) goto LAB_2010f9bc;
          FUN_20150dcc(0);
          iVar6 = iVar6 + 1;
        } while (iVar6 < 9);
        local_168 = 0;
        iVar6 = FUN_20155122(auStack_1a8);
        if ((((iVar6 == 0x40) &&
             (iVar6 = FUN_2014e320(auStack_1a8,&DAT_2010fb8c,&local_7c), iVar6 != 0)) &&
            (iVar6 = FUN_2014e320(local_7c,&DAT_2010fb8c,&local_7c), iVar6 != 0)) &&
           ((iVar6 = FUN_2014e320(local_7c,&DAT_2010fb8c,&local_7c), iVar6 != 0 &&
            (local_34[2] = hex_parse(iVar6,8,local_34), local_34[0] != iVar6)))) {
          local_40 = 0xffffffff;
          local_34[1] = 0x139eeca6;
          crc32_make_table();
          FUN_20126160(1);
          iVar6 = FUN_20111174(0x8350);
          local_38 = 2;
          iVar2 = iVar6 + 0x640;
          local_3c = 0;
          while (iVar3 = fs_fread(auStack_1a8,1,0x100,local_80), iVar3 != 0) {
            iVar1 = iVar1 + iVar3;
            uVar8 = FUN_20164d54(iVar1);
            uVar8 = FUN_201649d8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,uVar4);
            uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
            progress_scale(local_28,uVar5,(int)uVar8,uVar5);
            progress_set();
            FUN_20150dcc(0);
            local_40 = crc32_update(local_40,iVar3,auStack_1a8);
            local_3c = sfl_decode(local_3c,auStack_1a8,iVar3);
            memcpy(iVar2,auStack_1a8,iVar3);
            iVar2 = iVar2 + iVar3;
          }
          FUN_20141ff0(local_80);
          uVar7 = crc32_update(local_40,4,local_34 + 1);
          progress_scale(local_28,(int)((ulonglong)uVar7 >> 0x20),0,0x3ff00000);
          progress_set();
          if ((local_34[2] == ~(uint)uVar7) && (*(uint *)(iVar6 + 0x640) == (uint)DAT_2080019d)) {
            if (*(uint *)(iVar6 + 0x644) == (uint)DAT_2080019e) {
              memcpy(&DAT_208116a6,iVar6 + 0x650,32000);
              DAT_208001a1 = 0;
              local_38 = 1;
            }
            else {
              DAT_208001a1 = 2;
            }
          }
          else {
            DAT_208001a1 = 1;
          }
          FUN_20133620();
          FUN_20126160(0);
          return local_38;
        }
LAB_2010f9bc:
        DAT_208001a1 = 1;
        FUN_20141ff0(local_80);
      }
      else {
        DAT_208001a1 = 1;
      }
    }
    else {
      DAT_208001a1 = 4;
    }
  }
  else {
    DAT_208001a1 = 4;
  }
  return 2;
}


// ===== sd_make_dirs @ 2010fb90 (276 bytes)

/* I:\FT-710\Capture, MemList, Menu, PlayList */

undefined4 sd_make_dirs(void)

{
  int iVar1;
  int iVar2;
  
  FUN_20103bc8(1);
  itron_dly_tsk(0x14);
  iVar1 = FUN_2013f984(0x49);
  if ((iVar1 != 0) && (iVar2 = sd_card_detect(), iVar2 != 0)) {
    iVar1 = -1;
    DAT_208001a2 = 5;
  }
  FUN_20103bc8(0);
  itron_dly_tsk(0x14);
  if (iVar1 == 0) {
    iVar1 = FUN_2014beec("I:\\FT-710");
    if (iVar1 == 0) {
      iVar1 = FUN_2014beec("I:\\FT-710\\Capture");
      if (iVar1 == 0) {
        iVar1 = FUN_2014beec("I:\\FT-710\\MemList");
        if (iVar1 == 0) {
          iVar1 = FUN_2014beec("I:\\FT-710\\Menu");
          if (iVar1 == 0) {
            iVar1 = FUN_2014beec("I:\\FT-710\\PlayList");
            if (iVar1 == 0) {
              DAT_208001a2 = 0;
              return 1;
            }
            iVar1 = sd_card_detect();
          }
          else {
            iVar1 = sd_card_detect();
          }
        }
        else {
          iVar1 = sd_card_detect();
        }
      }
      else {
        iVar1 = sd_card_detect();
      }
    }
    else {
      iVar1 = sd_card_detect();
    }
    if (iVar1 != 0) {
      DAT_208001a2 = 5;
    }
  }
  return 2;
}


// ===== fmt_size_str @ 2010fcf0 (712 bytes)

/* "%.2f KB" ... "%d TB" */

void fmt_size_str(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined1 auStack_38 [32];
  
  uVar3 = (uint)((ulonglong)param_3 * 100);
  uVar1 = param_4 * 100 + (int)((ulonglong)param_3 * 100 >> 0x20);
  if (param_4 == 0 && (0x27ff < param_3) <= param_4) {
    uVar5 = FUN_20164d82(uVar1 * 0x400000 | uVar3 >> 10);
    uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
    sprintf(param_1,"%.2f KB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  }
  else {
    uVar4 = (uint)((ulonglong)param_3 * 10);
    uVar2 = param_4 * 10 + (int)((ulonglong)param_3 * 10 >> 0x20);
    if (param_4 == 0 && (0x18fff < param_3) <= param_4) {
      uVar5 = FUN_20164d82(uVar4 >> 10 | uVar2 * 0x400000);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f KB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0xf9fff < param_3) <= param_4) {
      sprintf(param_1,"%d KB",param_3 >> 10 | param_4 << 0x16);
    }
    else if (param_4 == 0 && (0x9fffff < param_3) <= param_4) {
      uVar5 = FUN_20164d82(uVar1 * 0x1000 | uVar3 >> 0x14);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f MB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0x63fffff < param_3) <= param_4) {
      uVar5 = FUN_20164d82(uVar4 >> 0x14 | uVar2 * 0x1000);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f MB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0x3e7fffff < param_3) <= param_4) {
      sprintf(param_1,"%d MB",param_3 >> 0x14 | param_4 << 0xc);
    }
    else if (param_4 < 3 && (uint)(0x7fffffff < param_3) <= param_4 - 2) {
      uVar5 = FUN_20164d82(uVar1 * 4 | uVar3 >> 0x1e);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f GB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x19) {
      uVar5 = FUN_20164d82(uVar4 >> 0x1e | uVar2 * 4);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f GB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0xfa) {
      sprintf(param_1,"%d GB",param_3 >> 0x1e | param_4 << 2);
    }
    else if (param_4 < 0xa00) {
      uVar5 = FUN_20164d82(uVar1 >> 8);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f TB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x6400) {
      uVar5 = FUN_20164d82(uVar2 >> 8);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f TB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x3e800) {
      sprintf(param_1,"%d TB",param_4 >> 8);
    }
    else {
      sprintf(param_1,"1000 TB+");
    }
  }
  sprintf(auStack_38," (%llu)",param_3,param_4);
  FUN_2015515c(param_1,auStack_38);
  return;
}


// ===== sd_info_screen @ 20110034 (176 bytes)

/* FREE SPACE / CAPACITY */

void sd_info_screen(int param_1)

{
  int iVar1;
  undefined1 auStack_58 [64];
  undefined4 local_18;
  undefined4 auStack_14 [2];
  
  iVar1 = FUN_2014b880(0x49,&local_18,auStack_14);
  if (iVar1 == 0) {
    fmt_size_str(auStack_58,auStack_14[0],auStack_14[0],local_18);
  }
  else {
    sprintf(auStack_58,"Unknown");
  }
  sprintf(param_1,"FREE SPACE : %s",auStack_58);
  iVar1 = thunk_FUN_2014b140(0x49,&local_18,auStack_14);
  if (iVar1 == 0) {
    fmt_size_str(auStack_58,auStack_14[0],auStack_14[0],local_18);
  }
  else {
    sprintf(auStack_58,"Unknown");
  }
  sprintf(param_1 + 0x40,"CAPACITY   : %s",auStack_58);
  return;
}


// ===== task_sdmenu @ 2011010c (220 bytes)

void task_sdmenu(void)

{
  int iVar1;
  undefined4 local_28 [2];
  int local_20;
  
LAB_2011012c:
  do {
    while( true ) {
      while( true ) {
        local_28[0] = 0xffffffff;
        iVar1 = itron_twai_flg(DAT_208001a8,0xffff,5,&local_20);
        if (iVar1 != 0) {
          return;
        }
        if (local_20 == 1) break;
        if (local_20 == 2) {
          progress_range_init(local_28,0,100);
          DAT_2080019f = sdmenu_load_file(local_28);
        }
        else if (local_20 == 3) {
          DAT_2080019f = sd_make_dirs();
        }
      }
      DAT_208001a4 = sdmenu_save_file(DAT_2080019d,&DAT_208193a6,DAT_2080019e);
      if (DAT_208001a4 != -0x3a) break;
      DAT_208001a0 = 2;
LAB_201101b0:
      DAT_2080019f = 2;
    }
    if (DAT_208001a4 != -0xb) {
      if (DAT_208001a4 != 0) {
        DAT_208001a0 = 4;
        goto LAB_201101b0;
      }
      DAT_208001a0 = 0;
      DAT_2080019f = 1;
      goto LAB_2011012c;
    }
    DAT_208001a0 = 1;
    DAT_2080019f = 2;
  } while( true );
}


// ===== sdmenu_request @ 201101e8 (144 bytes)

/* starts save (flag 1) or load (flag 2), polls result */

char sdmenu_request(int param_1,undefined4 *param_2,uint *param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (DAT_2080019c != '\0') {
    FUN_20150dcc(0);
    uVar3 = progress_get();
    *param_2 = uVar3;
    cVar2 = DAT_2080019f;
    if (DAT_2080019f != '\0') {
      DAT_2080019c = '\0';
      bVar1 = DAT_208001a1;
      if (param_1 != 0) {
        bVar1 = DAT_208001a0;
      }
      *param_3 = (uint)bVar1;
    }
    return cVar2;
  }
  DAT_2080019c = 1;
  DAT_2080019f = 0;
  progress_set(0);
  uVar3 = progress_get();
  *param_2 = uVar3;
  if (param_1 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  itron_set_flg(DAT_208001a8,uVar3);
  return '\0';
}


// ===== sd_format_request @ 20110278 (240 bytes)

/* flag 3 (sd_make_dirs), progress percent */

char sd_format_request(undefined4 *param_1,uint *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int local_28;
  
  local_28 = param_4;
  if (DAT_2080019c != '\0') {
    itron_dly_tsk(0x14);
    iVar1 = *(int *)(DAT_20808b44 + 0x2f8);
    if (iVar1 != 0) {
      iVar3 = *(int *)(DAT_20808b44 + 0x2f4);
      uVar4 = FUN_20164d82();
      uVar5 = FUN_20164d82(iVar1 - iVar3);
      uVar4 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                           (int)((ulonglong)uVar4 >> 0x20));
      FUN_20164da8((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40590000);
      uVar2 = FUN_20164c90();
      *param_1 = uVar2;
    }
    if (DAT_2080019f != '\0') {
      FUN_2014e884(0);
      DAT_2080019c = '\0';
      *param_2 = (uint)DAT_208001a2;
    }
    return DAT_2080019f;
  }
  DAT_2080019c = 1;
  DAT_2080019f = 0;
  *param_1 = 0;
  FUN_20150aac(0,&local_28);
  local_28 = local_28 + -1;
  FUN_2014e884(0);
  itron_set_flg(DAT_208001a8,3);
  itron_dly_tsk(0x32);
  return '\0';
}


// ===== sd_format_done @ 20110368 (32 bytes)

void sd_format_done(void)

{
  FUN_2014e884(0);
  DAT_2080019c = 0;
  return;
}


// ===== sdmenu_init @ 20110388 (96 bytes)

/* task "sdmenu" */

void sdmenu_init(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_10 = 2;
  uStack_c = 0;
  local_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (0 < iVar1) {
    DAT_208001a8 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_201654f8);
    if (0 < iVar1) {
      itron_sta_tsk(iVar1,0);
    }
  }
  return;
}


// ===== hex_to_bin @ 201103f4 (96 bytes)

/* ASCII hex to bytes */

int hex_to_bin(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int local_28;
  
  iVar3 = 0;
  iVar4 = 0;
  local_28 = param_4;
  while( true ) {
    bVar5 = SBORROW4(iVar4,param_3);
    iVar1 = iVar4 - param_3;
    if (iVar4 < param_3) {
      bVar5 = SBORROW4(iVar3,param_4);
      iVar1 = iVar3 - param_4;
    }
    if ((iVar1 < 0 == bVar5) ||
       (uVar2 = hex_parse(param_1 + iVar4,2,&local_28), param_1 + iVar4 == local_28)) break;
    *(undefined1 *)(param_2 + iVar3) = uVar2;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 2;
  }
  return iVar3;
}


// ===== sdr_relay_xfer @ 20110548 (304 bytes)

/* binary register frame to MAIN, waits for 06 or a 7D reply */

undefined4 sdr_relay_xfer(int *param_1,char *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  char local_120 [256];
  undefined4 local_20;
  int local_1c;
  
  if (*param_2 == -3) {
    uVar1 = 0xb;
  }
  else {
    uVar1 = 7;
  }
  (**(code **)(*param_1 + 0x24))(param_1,param_2,uVar1);
  memclr(local_120,0x100);
  uVar2 = 0;
  local_20 = 0;
  do {
    itron_dly_tsk(1);
    local_1c = (**(code **)(*param_1 + 0x10))(param_1,local_120 + uVar2,0x40);
    uVar2 = uVar2 + local_1c;
    if (0xff < uVar2) {
      return 0xffffffff;
    }
  } while (local_1c != 0);
  if (uVar2 == 1) {
    if (local_120[0] == '\x06') {
      memcpy(param_3,local_120,1);
      return 1;
    }
  }
  else {
    bVar3 = local_120[1] == '}';
    if (bVar3) {
      local_120[1] = local_120[2];
    }
    if (bVar3 && local_120[1] == '\0') {
      local_20 = CONCAT31(local_20._1_3_,6);
      (**(code **)(*param_1 + 0x24))(param_1,&local_20,1);
      itron_dly_tsk(1);
      memcpy(param_3,local_120 + 3,4);
      return 4;
    }
  }
  return 0xffffffff;
}


// ===== sdr_reg_read @ 20110584 (200 bytes)

/* FE 00 "%04X" sum: FPGA register read via MAIN */

uint sdr_reg_read(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar4;
  undefined1 auStack_140 [256];
  char local_40 [32];
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 *local_18 [2];
  
  memclr(local_40,0x20);
  cVar4 = '\0';
  local_20 = 0xfe;
  local_1c = 0;
  sprintf(local_40,&DAT_201107ac,param_2);
  uVar2 = FUN_20155122(local_40);
  memcpy((int)&local_20 + 2,local_40,uVar2);
  uVar3 = 0;
  do {
    pcVar1 = local_40 + uVar3;
    uVar3 = uVar3 + 1;
    cVar4 = *pcVar1 + cVar4;
  } while (uVar3 < 6);
  local_1c._0_3_ = CONCAT12(cVar4,(undefined2)local_1c);
  uVar3 = sdr_relay_xfer(param_1,&local_20,auStack_140);
  if (uVar3 != 0xffffffff) {
    uVar3 = hex_parse(auStack_140,4,local_18);
    uVar3 = uVar3 & 0xffff;
    if (local_18[0] == auStack_140) {
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}


// ===== sdr_reg_write @ 2011064c (172 bytes)

/* FD 00 "%04X%04X" sum: FPGA register write via MAIN */

void sdr_reg_write(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar4;
  char local_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar4 = '\0';
  memclr(local_48,0x20);
  local_28 = 0xfd;
  local_24 = 0;
  local_20 = 0;
  sprintf(local_48,"%04X%04X",param_2,param_3);
  uVar2 = FUN_20155122(local_48);
  memcpy((int)&local_28 + 2,local_48,uVar2);
  uVar3 = 0;
  do {
    pcVar1 = local_48 + uVar3;
    uVar3 = uVar3 + 1;
    cVar4 = *pcVar1 + cVar4;
  } while (uVar3 < 10);
  local_20._0_3_ = CONCAT12(cVar4,(undefined2)local_20);
  sdr_relay_xfer(param_1,&local_28,param_4);
  return;
}


// ===== sdr_set_flash_addr @ 201106f8 (88 bytes)

/* regs 0x30 / 0x31 = flash address */

int sdr_set_flash_addr(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_110 [256];
  
  iVar1 = sdr_reg_write(param_1,param_2 | 0x30,param_3 >> 0x10,auStack_110);
  if ((iVar1 != -1) &&
     (iVar1 = sdr_reg_write(param_1,param_2 | 0x31,param_3 & 0xffff,auStack_110), iVar1 != -1)) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== sdr_wait_ready @ 20110750 (92 bytes)

/* polls reg 0x32 until the top nibble is 0 or 8 */

undefined4 sdr_wait_ready(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  while( true ) {
    bVar2 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar2) {
      return 0xffffffff;
    }
    iVar1 = sdr_reg_read(param_1,param_2 | 0x32);
    if (iVar1 == -1) break;
    if (iVar1 >> 0xc == 0 || iVar1 >> 0xc == 8) {
      return 0;
    }
    itron_dly_tsk(1);
  }
  return 0xffffffff;
}

