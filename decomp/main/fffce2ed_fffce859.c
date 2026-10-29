// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex010308_step @ fffce2ed (18 bytes)

/* Menu item ex010308 LCUT SLOPE: on_step (#74) */

void menu_ex010308_step(void)

{
  menu_step_u8(0,1,&DAT_00009a59);
  return;
}


// ===== menu_ex010309_step @ fffce2ff (14 bytes)

/* Menu item ex010309 HCUT FREQ: on_step (#74) */

void menu_ex010309_step(void)

{
  FUN_fffcdf37(&DAT_00009a5a);
  return;
}


// ===== menu_ex010310_step @ fffce30d (18 bytes)

/* Menu item ex010310 HCUT SLOPE: on_step (#74) */

void menu_ex010310_step(void)

{
  menu_step_u8(0,1,&DAT_00009a5b);
  return;
}


// ===== menu_ex010311_step @ fffce31f (19 bytes)

/* Menu item ex010311 USB OUT LEVEL: on_step (#74) */

void menu_ex010311_step(void)

{
  menu_step_u8(0,100,&DAT_00009a5c);
  return;
}


// ===== menu_ex010312_step @ fffce332 (19 bytes)

/* Menu item ex010312 REAR OUT LEVEL: on_step (#74) */

void menu_ex010312_step(void)

{
  menu_step_u8(0,100,&DAT_00009a5d);
  return;
}


// ===== menu_ex010313_step @ fffce345 (18 bytes)

/* Menu item ex010313 MOD SOURCE: on_step (#74) */

void menu_ex010313_step(void)

{
  menu_step_u8(0,3,&DAT_00009a5e);
  return;
}


// ===== menu_ex010314_step @ fffce357 (19 bytes)

/* Menu item ex010314 USB MOD GAIN: on_step (#74) */

void menu_ex010314_step(void)

{
  menu_step_u8(0,100,&DAT_00009a5f);
  return;
}


// ===== menu_ex010315_step @ fffce36a (19 bytes)

/* Menu item ex010315 REAR MOD GAIN: on_step (#74) */

void menu_ex010315_step(void)

{
  menu_step_u8(0,100,&DAT_00009a60);
  return;
}


// ===== menu_ex010316_step @ fffce37d (18 bytes)

/* Menu item ex010316 RPTT SELECT: on_step (#74) */

void menu_ex010316_step(void)

{
  menu_step_u8(0,3,&DAT_00009a61);
  return;
}


// ===== menu_ex010317_step @ fffce38f (92 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce3bf) */
/* Menu item ex010317 RPT SHIFT: on_step (#74) */

void menu_ex010317_step(void)

{
  bool bStack_9;
  byte *pbStack_8;
  byte *pbStack_4;
  
  pbStack_4 = vfo_rec_ptr(1);
  pbStack_8 = pbStack_4 + 2;
  bStack_9 = (bool)(*pbStack_8 >> 2 & 3);
  menu_step_u8(0,2,&bStack_9);
  *pbStack_8 = *pbStack_8 & 0xf3 | (bStack_9 & 3U) << 2;
  bStack_9 = pbStack_4 != &DAT_00009d09;
  vfo_mark_edited(bStack_9);
  vfo_store_back(bStack_9);
  return;
}


// ===== menu_fm_rptshift_get @ fffce3eb (38 bytes)

/* EX010317 accessor: (VFO byte+2 >> 2) & 3 */

byte menu_fm_rptshift_get(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  return pbVar1[2] >> 2 & 3;
}


// ===== menu_fm_rptshift_set @ fffce411 (37 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce42c) */
/* EX010317 accessor (set) */

void menu_fm_rptshift_set(byte param_1)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  pbVar1[2] = pbVar1[2] & 0xf3 | (param_1 & 3) << 2;
  return;
}


// ===== menu_ex010318_step @ fffce436 (26 bytes)

/* Menu item ex010318 RPT SHIFT(28MHz): on_step (#74) */

void menu_ex010318_step(void)

{
  menu_step_u8(0,100,&DAT_00009a62);
  return;
}


// ===== menu_ex010319_step @ fffce450 (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce460) */
/* Menu item ex010319 RPT SHIFT(50MHz): on_step (#74) */

void menu_ex010319_step(void)

{
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  uStack_2 = DAT_00009a64;
  uStack_1 = DAT_00009a63;
  FUN_fffce495(0,400,&uStack_2);
  DAT_00009a63 = uStack_1;
  DAT_00009a64 = uStack_2;
  return;
}


// ===== FUN_fffce495 @ fffce495 (74 bytes)

void FUN_fffce495(ushort param_1,ushort param_2,ushort *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 - 1;
      return;
    }
  }
  return;
}


// ===== menu_ex010320_step @ fffce4df (93 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce50f) */
/* Menu item ex010320 ENC/DEC: on_step (#74) */

void menu_ex010320_step(void)

{
  bool bStack_9;
  byte *pbStack_8;
  byte *pbStack_4;
  
  pbStack_4 = vfo_rec_ptr(1);
  pbStack_8 = pbStack_4 + 3;
  bStack_9 = (bool)(*pbStack_8 >> 3 & 7);
  menu_step_u8(0,2,&bStack_9);
  *pbStack_8 = *pbStack_8 & 199 | (bStack_9 & 7U) << 3;
  bStack_9 = pbStack_4 != &DAT_00009d09;
  vfo_mark_edited(bStack_9);
  vfo_store_back(bStack_9);
  return;
}


// ===== menu_fm_encdec_get @ fffce53c (38 bytes)

/* EX010320 accessor */

byte menu_fm_encdec_get(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  return pbVar1[3] >> 3 & 7;
}


// ===== menu_fm_encdec_set @ fffce562 (38 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce57d) */
/* EX010320 accessor (set) */

void menu_fm_encdec_set(byte param_1)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  pbVar1[3] = pbVar1[3] & 199 | (param_1 & 7) << 3;
  return;
}


// ===== menu_ex010321_step @ fffce588 (54 bytes)

/* Menu item ex010321 TONE FREQ: on_step (#74) */

void menu_ex010321_step(void)

{
  byte *pbStack_4;
  
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d4f;
  }
  else {
    pbStack_4 = &DAT_00009da9;
  }
  menu_step_u8(0,0x31,pbStack_4);
  return;
}


// ===== menu_fm_tone_get @ fffce5be (55 bytes)

/* EX010321 accessor */

byte menu_fm_tone_get(void)

{
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d4f;
  }
  else {
    local_8 = &DAT_00009da9;
  }
  return *local_8;
}


// ===== menu_fm_tone_set @ fffce5f5 (52 bytes)

/* EX010321 accessor (set) */

void menu_fm_tone_set(byte param_1)

{
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d4f;
  }
  else {
    local_8 = &DAT_00009da9;
  }
  *local_8 = param_1;
  return;
}


// ===== menu_ex010401_step @ fffce629 (19 bytes)

/* Menu item ex010401 AF TREBLE GAIN: on_step (#74) */

void menu_ex010401_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a67);
  return;
}


// ===== menu_ex010402_step @ fffce63c (19 bytes)

/* Menu item ex010402 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010402_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a68);
  return;
}


// ===== menu_ex010403_step @ fffce64f (19 bytes)

/* Menu item ex010403 AF BASS GAIN: on_step (#74) */

void menu_ex010403_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a69);
  return;
}


// ===== menu_ex010404_step @ fffce662 (19 bytes)

/* Menu item ex010404 AGC FAST DELAY: on_step (#74) */

void menu_ex010404_step(void)

{
  menu_step_u8(0,199,&DAT_00009a6a);
  return;
}


// ===== menu_ex010405_step @ fffce675 (19 bytes)

/* Menu item ex010405 AGC MID DELAY: on_step (#74) */

void menu_ex010405_step(void)

{
  menu_step_u8(0,199,&DAT_00009a6b);
  return;
}


// ===== menu_ex010406_step @ fffce688 (19 bytes)

/* Menu item ex010406 AGC SLOW DELAY: on_step (#74) */

void menu_ex010406_step(void)

{
  menu_step_u8(0,199,&DAT_00009a6c);
  return;
}


// ===== menu_ex010407_step @ fffce69b (14 bytes)

/* Menu item ex010407 LCUT FREQ: on_step (#74) */

void menu_ex010407_step(void)

{
  FUN_fffcdecf(&DAT_00009a6d);
  return;
}


// ===== menu_ex010408_step @ fffce6a9 (18 bytes)

/* Menu item ex010408 LCUT SLOPE: on_step (#74) */

void menu_ex010408_step(void)

{
  menu_step_u8(0,1,&DAT_00009a6e);
  return;
}


// ===== menu_ex010409_step @ fffce6bb (14 bytes)

/* Menu item ex010409 HCUT FREQ: on_step (#74) */

void menu_ex010409_step(void)

{
  FUN_fffcdf37(&DAT_00009a6f);
  return;
}


// ===== menu_ex010410_step @ fffce6c9 (18 bytes)

/* Menu item ex010410 HCUT SLOPE: on_step (#74) */

void menu_ex010410_step(void)

{
  menu_step_u8(0,1,&DAT_00009a70);
  return;
}


// ===== menu_ex010411_step @ fffce6db (19 bytes)

/* Menu item ex010411 USB OUT LEVEL: on_step (#74) */

void menu_ex010411_step(void)

{
  menu_step_u8(0,100,&DAT_00009a71);
  return;
}


// ===== menu_ex010412_step @ fffce6ee (19 bytes)

/* Menu item ex010412 REAR OUT LEVEL: on_step (#74) */

void menu_ex010412_step(void)

{
  menu_step_u8(0,100,&DAT_00009a72);
  return;
}


// ===== menu_ex010413_step @ fffce701 (18 bytes)

/* Menu item ex010413 TX BPF SEL: on_step (#74) */

void menu_ex010413_step(void)

{
  menu_step_u8(0,4,&DAT_00009a73);
  return;
}


// ===== menu_ex010414_step @ fffce713 (18 bytes)

/* Menu item ex010414 MOD SOURCE: on_step (#74) */

void menu_ex010414_step(void)

{
  menu_step_u8(0,3,&DAT_00009a74);
  return;
}


// ===== menu_ex010415_step @ fffce725 (19 bytes)

/* Menu item ex010415 USB MOD GAIN: on_step (#74) */

void menu_ex010415_step(void)

{
  menu_step_u8(0,100,&DAT_00009a75);
  return;
}


// ===== menu_ex010416_step @ fffce738 (19 bytes)

/* Menu item ex010416 REAR MOD GAIN: on_step (#74) */

void menu_ex010416_step(void)

{
  menu_step_u8(0,100,&DAT_00009a76);
  return;
}


// ===== menu_ex010417_step @ fffce74b (18 bytes)

/* Menu item ex010417 RPTT SELECT: on_step (#74) */

void menu_ex010417_step(void)

{
  menu_step_u8(0,3,&DAT_00009a77);
  return;
}


// ===== menu_ex010418_step @ fffce75d (19 bytes)

/* Menu item ex010418 NAR WIDTH: on_step (#74) */

void menu_ex010418_step(void)

{
  menu_step_u8(0,0x14,&DAT_00009a78);
  return;
}


// ===== menu_ex010419_step @ fffce770 (18 bytes)

/* Menu item ex010419 PSK TONE: on_step (#74) */

void menu_ex010419_step(void)

{
  menu_step_u8(0,2,&DAT_00009a79);
  return;
}


// ===== menu_ex010420_step @ fffce782 (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce792) */
/* Menu item ex010420 DATA SHIFT (SSB): on_step (#74) */

void menu_ex010420_step(void)

{
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  uStack_2 = DAT_00009a7b;
  uStack_1 = DAT_00009a7a;
  FUN_fffce495(0,300,&uStack_2);
  DAT_00009a7a = uStack_1;
  DAT_00009a7b = uStack_2;
  return;
}


// ===== menu_ex010501_step @ fffce7c7 (19 bytes)

/* Menu item ex010501 AF TREBLE GAIN: on_step (#74) */

void menu_ex010501_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a7e);
  return;
}


// ===== menu_ex010502_step @ fffce7da (19 bytes)

/* Menu item ex010502 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010502_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a7f);
  return;
}


// ===== menu_ex010503_step @ fffce7ed (19 bytes)

/* Menu item ex010503 AF BASS GAIN: on_step (#74) */

void menu_ex010503_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009a80);
  return;
}


// ===== menu_ex010504_step @ fffce800 (19 bytes)

/* Menu item ex010504 AGC FAST DELAY: on_step (#74) */

void menu_ex010504_step(void)

{
  menu_step_u8(0,199,&DAT_00009a81);
  return;
}


// ===== menu_ex010505_step @ fffce813 (19 bytes)

/* Menu item ex010505 AGC MID DELAY: on_step (#74) */

void menu_ex010505_step(void)

{
  menu_step_u8(0,199,&DAT_00009a82);
  return;
}


// ===== menu_ex010506_step @ fffce826 (19 bytes)

/* Menu item ex010506 AGC SLOW DELAY: on_step (#74) */

void menu_ex010506_step(void)

{
  menu_step_u8(0,199,&DAT_00009a83);
  return;
}


// ===== menu_ex010507_step @ fffce839 (14 bytes)

/* Menu item ex010507 LCUT FREQ: on_step (#74) */

void menu_ex010507_step(void)

{
  FUN_fffcdecf(&DAT_00009a84);
  return;
}


// ===== menu_ex010508_step @ fffce847 (18 bytes)

/* Menu item ex010508 LCUT SLOPE: on_step (#74) */

void menu_ex010508_step(void)

{
  menu_step_u8(0,1,&DAT_00009a85);
  return;
}


// ===== menu_ex010509_step @ fffce859 (14 bytes)

/* Menu item ex010509 HCUT FREQ: on_step (#74) */

void menu_ex010509_step(void)

{
  FUN_fffcdf37(&DAT_00009a86);
  return;
}

