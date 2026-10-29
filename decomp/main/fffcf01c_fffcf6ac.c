// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030405_step @ fffcf01c (18 bytes)

/* Menu item ex030405 VOX SELECT: on_step (#74) */

void menu_ex030405_step(void)

{
  menu_step_u8(0,2,&DAT_00009af3);
  return;
}


// ===== menu_ex030406_step @ fffcf02e (64 bytes)

/* Menu item ex030406 EMERGENCY FREQ TX: on_step (#74) */

void menu_ex030406_step(void)

{
  ushort uVar1;
  
  uVar1 = dest_code_get();
  if ((((uVar1 != 0x20b) && (uVar1 != 0x1cb9)) && (uVar1 != 0x315b)) &&
     (((uVar1 != 0x4380 && (uVar1 != 0x50e2)) && (uVar1 != 0x60e6)))) {
    beep_request(3);
    return;
  }
  menu_step_u8(0,1,&DAT_00009af4);
  return;
}


// ===== menu_ex030407_step @ fffcf06e (18 bytes)

/* Menu item ex030407 TX INHITBIT: on_step (#74) */

void menu_ex030407_step(void)

{
  menu_step_u8(0,1,&DAT_00009af5);
  return;
}


// ===== menu_ex030408_step @ fffcf080 (18 bytes)

/* Menu item ex030408 METER DETECTOR: on_step (#74) */

void menu_ex030408_step(void)

{
  menu_step_u8(0,1,&DAT_00009af6);
  return;
}


// ===== menu_ex030501_step @ fffcf092 (18 bytes)

/* Menu item ex030501 SSB/CW DIAL STEP: on_step (#74) */

void menu_ex030501_step(void)

{
  menu_step_u8(0,2,&DAT_00009af9);
  return;
}


// ===== menu_ex030502_step @ fffcf0a4 (18 bytes)

/* Menu item ex030502 RTTY/PSK DIAL STEP: on_step (#74) */

void menu_ex030502_step(void)

{
  menu_step_u8(0,2,&DAT_00009afa);
  return;
}


// ===== menu_ex030503_step @ fffcf0b6 (18 bytes)

/* Menu item ex030503 CH STEP: on_step (#74) */

void menu_ex030503_step(void)

{
  menu_step_u8(0,3,&DAT_00009afb);
  return;
}


// ===== menu_ex030504_step @ fffcf0c8 (18 bytes)

/* Menu item ex030504 AM CH STEP: on_step (#74) */

void menu_ex030504_step(void)

{
  menu_step_u8(0,5,&DAT_00009afc);
  return;
}


// ===== menu_ex030505_step @ fffcf0da (18 bytes)

/* Menu item ex030505 FM CH STEP: on_step (#74) */

void menu_ex030505_step(void)

{
  menu_step_u8(0,5,&DAT_00009afd);
  return;
}


// ===== menu_ex030506_step @ fffcf0ec (18 bytes)

/* Menu item ex030506 MAIN STEPS PER REV.: on_step (#74) */

void menu_ex030506_step(void)

{
  menu_step_u8(0,2,&DAT_00009afe);
  return;
}


// ===== menu_ex040101_step @ fffcf0fe (1 bytes)

/* Menu item ex040101 MY CALL: on_step (#74) */

void menu_ex040101_step(void)

{
  return;
}


// ===== menu_ex040102_step @ fffcf0ff (18 bytes)

/* Menu item ex040102 MY CALL TIME: on_step (#74) */

void menu_ex040102_step(void)

{
  menu_step_u8(0,5,&DAT_00009b0d);
  return;
}


// ===== menu_ex040103_step @ fffcf111 (18 bytes)

/* Menu item ex040103 POP-UP TIME: on_step (#74) */

void menu_ex040103_step(void)

{
  menu_step_u8(0,2,&DAT_00009b0e);
  return;
}


// ===== menu_ex040104_step @ fffcf123 (22 bytes)

/* Menu item ex040104 SCREEN SAVER: on_step (#74) */

void menu_ex040104_step(void)

{
  menu_step_u8(0,3,&DAT_00009b0f);
  cat_apo_reset();
  return;
}


// ===== menu_ex040105_step @ fffcf139 (79 bytes)

/* Menu item ex040105 LED DIMMER: on_step (#74) */

void menu_ex040105_step(void)

{
  menu_step_u8(0,0x14,(byte *)&DAT_00009b10);
  if (PTR_s_V01_12_0001b4fd._3_1_ == DAT_00009b10) {
    return;
  }
  PTR_s_V01_12_0001b4fd._3_1_ = DAT_00009b10;
  swtimer_start(0x2b,100);
  PTR_DAT_00025d60[0x401] = 1;
  return;
}


// ===== menu_ex040106_step @ fffcf188 (79 bytes)

/* Menu item ex040106 MOUSE POINTER SPEED: on_step (#74) */

void menu_ex040106_step(void)

{
  menu_step_u8(0,0x14,(byte *)&DAT_00009b11);
  if (DAT_0001b501 == DAT_00009b11) {
    return;
  }
  DAT_0001b501 = DAT_00009b11;
  swtimer_start(0x2b,100);
  PTR_DAT_00025d60[0x401] = 1;
  return;
}


// ===== menu_ex040201_step @ fffcf1d7 (18 bytes)

/* Menu item ex040201 RBW: on_step (#74) */

void menu_ex040201_step(void)

{
  menu_step_u8(0,2,&DAT_00009b14);
  return;
}


// ===== menu_ex040202_step @ fffcf1e9 (18 bytes)

/* Menu item ex040202 SCOPE CTR: on_step (#74) */

void menu_ex040202_step(void)

{
  menu_step_u8(0,1,&DAT_00009b15);
  return;
}


// ===== menu_ex040203_step @ fffcf1fb (18 bytes)

/* Menu item ex040203 2D DISP SENSITIVITY: on_step (#74) */

void menu_ex040203_step(void)

{
  menu_step_u8(0,1,&DAT_00009b16);
  return;
}


// ===== menu_ex040204_step @ fffcf20d (18 bytes)

/* Menu item ex040204 3DSS DISP SENSITIVITY: on_step (#74) */

void menu_ex040204_step(void)

{
  menu_step_u8(0,1,&DAT_00009b17);
  return;
}


// ===== menu_ex040301_step @ fffcf21f (18 bytes)

/* Menu item ex040301 VMI COLOR VFO-A: on_step (#74) */

void menu_ex040301_step(void)

{
  menu_step_u8(0,3,&DAT_00009b1a);
  return;
}


// ===== menu_ex040302_step @ fffcf231 (18 bytes)

/* Menu item ex040302 VMI COLOR VFO-B: on_step (#74) */

void menu_ex040302_step(void)

{
  menu_step_u8(0,3,&DAT_00009b1b);
  return;
}


// ===== menu_ex040303_step @ fffcf243 (18 bytes)

/* Menu item ex040303 VMI COLOR MEMORY: on_step (#74) */

void menu_ex040303_step(void)

{
  menu_step_u8(0,3,&DAT_00009b1c);
  return;
}


// ===== menu_ex040304_step @ fffcf255 (18 bytes)

/* Menu item ex040304 VMI COLOR CLAR: on_step (#74) */

void menu_ex040304_step(void)

{
  menu_step_u8(0,1,&DAT_00009b1d);
  return;
}


// ===== menu_ex040401_step @ fffcf267 (78 bytes)

/* Menu item ex040401 EXT DISPLAY: on_step (#74) */

void menu_ex040401_step(void)

{
  menu_step_u8(0,1,(byte *)&DAT_00009b20);
  if (DAT_0001b502 == DAT_00009b20) {
    return;
  }
  DAT_0001b502 = DAT_00009b20;
  swtimer_start(0x2b,100);
  PTR_DAT_00025d60[0x401] = 1;
  return;
}


// ===== menu_ex040402_step @ fffcf2b5 (78 bytes)

/* Menu item ex040402 PIXEL: on_step (#74) */

void menu_ex040402_step(void)

{
  menu_step_u8(0,1,(byte *)&DAT_00009b21);
  if (DAT_0001b503 == DAT_00009b21) {
    return;
  }
  DAT_0001b503 = DAT_00009b21;
  swtimer_start(0x2b,100);
  PTR_DAT_00025d60[0x401] = 1;
  return;
}


// ===== menu_ex040101_enter @ fffcf303 (119 bytes)

/* Menu item ex040101 MY CALL: on_enter (#74) */

void menu_ex040101_enter(void)

{
  undefined *puVar1;
  
  PTR_DAT_00025d60[0x90] = 1;
  PTR_DAT_00025d60[0xbe] = 0;
  PTR_DAT_00025d60[0xc1] = 0;
  puVar1 = PTR_DAT_00025d60;
  *(undefined4 *)(PTR_DAT_00025d60 + 0xca) = 0x20202020;
  *(undefined4 *)(puVar1 + 0xc6) = 0x20202020;
  *(undefined4 *)(puVar1 + 0xc2) = 0x20202020;
  puVar1 = PTR_DAT_00025d60;
  *(undefined4 *)(PTR_DAT_00025d60 + 0xca) = DAT_00009b09;
  *(undefined4 *)(puVar1 + 0xc6) = DAT_00009b05;
  *(undefined4 *)(puVar1 + 0xc2) = DAT_00009b01;
  beep_request(1);
  return;
}


// ===== menu_m4_16_0_step @ fffcf37a (21 bytes)

/* Menu item m4_16_0 DAY: on_step (#74) */

void menu_m4_16_0_step(void)

{
  FUN_fffcf38f(1,0x31,PTR_DAT_00025d60 + 0xb4);
  return;
}


// ===== FUN_fffcf38f @ fffcf38f (108 bytes)

void FUN_fffcf38f(byte param_1,byte param_2,byte *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if ((*param_3 < param_2) && (*param_3 = *param_3 + 1, 9 < (*param_3 & 0xf))) {
        *param_3 = *param_3 + 6;
        return;
      }
    }
    else if ((param_1 < *param_3) && (*param_3 = *param_3 - 1, 9 < (*param_3 & 0xf))) {
      *param_3 = *param_3 - 6;
      return;
    }
  }
  return;
}


// ===== menu_m4_16_1_step @ fffcf3fb (21 bytes)

/* Menu item m4_16_1 MONTH: on_step (#74) */

void menu_m4_16_1_step(void)

{
  FUN_fffcf38f(1,0x12,PTR_DAT_00025d60 + 0xb3);
  return;
}


// ===== menu_m4_16_2_step @ fffcf410 (21 bytes)

/* Menu item m4_16_2 YEAR: on_step (#74) */

void menu_m4_16_2_step(void)

{
  FUN_fffcf38f(0,0x99,PTR_DAT_00025d60 + 0xb2);
  return;
}


// ===== menu_m4_16_3_step @ fffcf425 (21 bytes)

/* Menu item m4_16_3 HOUR: on_step (#74) */

void menu_m4_16_3_step(void)

{
  FUN_fffcf38f(0,0x23,PTR_DAT_00025d60 + 0xb5);
  return;
}


// ===== menu_m4_16_4_step @ fffcf43a (21 bytes)

/* Menu item m4_16_4 MINUTE: on_step (#74) */

void menu_m4_16_4_step(void)

{
  FUN_fffcf38f(0,0x59,PTR_DAT_00025d60 + 0xb6);
  return;
}


// ===== menu_m4_17_0_enter @ fffcf44f (13 bytes)

/* Menu item m4_17_0 MEM LIST LOAD: on_enter (#74) */

void menu_m4_17_0_enter(void)

{
  int iVar1;
  
  iVar1 = FUN_fffd43b9(2);
  if (iVar1 != 1) {
    return;
  }
  sd_memlist_load_start();
  return;
}


// ===== FUN_fffcf45c @ fffcf45c (92 bytes)

void FUN_fffcf45c(void)

{
  if ((((PTR_DAT_00025d60[0xa5] == '\x01') && (PTR_DAT_00025d60[0xa7] != PTR_DAT_00025d60[0xa6])) &&
      (PTR_DAT_00025d60[0xa7] = PTR_DAT_00025d60[0xa6], PTR_DAT_00025d60[0xa6] == '\x01')) &&
     ((PTR_DAT_00025d60[0xba] == '\0' && (PTR_DAT_00025d60[0x95] == '\0')))) {
    FUN_fffcf4b8();
    return;
  }
  return;
}


// ===== FUN_fffcf4b8 @ fffcf4b8 (29 bytes)

void FUN_fffcf4b8(void)

{
  PTR_DAT_00025d60[0xbb] = 1;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf4d5 @ fffcf4d5 (29 bytes)

void FUN_fffcf4d5(void)

{
  PTR_DAT_00025d60[0xbb] = 2;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf4f2 @ fffcf4f2 (29 bytes)

void FUN_fffcf4f2(void)

{
  PTR_DAT_00025d60[0xbb] = 3;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf50f @ fffcf50f (29 bytes)

void FUN_fffcf50f(void)

{
  PTR_DAT_00025d60[0xbb] = 5;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf52c @ fffcf52c (29 bytes)

void FUN_fffcf52c(void)

{
  PTR_DAT_00025d60[0xbb] = 6;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf549 @ fffcf549 (29 bytes)

void FUN_fffcf549(void)

{
  PTR_DAT_00025d60[0xbb] = 7;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf566 @ fffcf566 (29 bytes)

void FUN_fffcf566(void)

{
  PTR_DAT_00025d60[0xbb] = 8;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf583 @ fffcf583 (29 bytes)

void FUN_fffcf583(void)

{
  PTR_DAT_00025d60[0xbb] = 0xd;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf5a0 @ fffcf5a0 (29 bytes)

void FUN_fffcf5a0(void)

{
  PTR_DAT_00025d60[0xbb] = 9;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf5bd @ fffcf5bd (60 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcf5da) */

ushort FUN_fffcf5bd(void)

{
  undefined2 local_4;
  
  if (DAT_00015de5 == '\0') {
    local_4 = CONCAT11(DAT_00012274,DAT_00012273);
  }
  else {
    local_4 = dest_code_get();
  }
  return local_4;
}


// ===== FUN_fffcf5f9 @ fffcf5f9 (92 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcf652) */

undefined4 FUN_fffcf5f9(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = dest_code_get();
  if (DAT_00015de5 == '\0') {
    uVar2 = FUN_fffcf5bd();
    if (uVar1 == uVar2) {
      PTR_DAT_00025d60[0xbb] = 10;
    }
    else {
      PTR_DAT_00025d60[0xbb] = 0xf;
    }
  }
  else {
    uVar2 = FUN_fffcf5bd();
    if (uVar1 == uVar2) {
      PTR_DAT_00025d60[0xbb] = 10;
    }
    else {
      PTR_DAT_00025d60[0xbb] = 0xf;
    }
  }
  PTR_DAT_00025d60[0x448] = 0;
  uVar3 = FUN_fffcf6ac();
  return uVar3;
}


// ===== FUN_fffcf655 @ fffcf655 (29 bytes)

void FUN_fffcf655(void)

{
  PTR_DAT_00025d60[0xbb] = 0xb;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf672 @ fffcf672 (29 bytes)

void FUN_fffcf672(void)

{
  PTR_DAT_00025d60[0xbb] = 0xc;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf68f @ fffcf68f (29 bytes)

void FUN_fffcf68f(void)

{
  PTR_DAT_00025d60[0xbb] = 4;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf6ac @ fffcf6ac (49 bytes)

void FUN_fffcf6ac(void)

{
  PTR_DAT_00025d60[0x86] = 1;
  PTR_DAT_00025d60[0xbd] = 0;
  if (DAT_00020b74 == '\0') {
    return;
  }
  DAT_00020b74 = 0;
  return;
}

