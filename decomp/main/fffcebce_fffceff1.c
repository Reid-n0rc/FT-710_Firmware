// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030106_step @ fffcebce (18 bytes)

/* Menu item ex030106 CAT-1 TIME OUT TIMER: on_step (#74) */

void menu_ex030106_step(void)

{
  menu_step_u8(0,3,&DAT_00009aba);
  return;
}


// ===== menu_ex030107_step @ fffcebe0 (26 bytes)

/* Menu item ex030107 CAT-1 CAT-3 STOP BIT: on_step (#74) */

void menu_ex030107_step(void)

{
  menu_step_u8(0,1,&DAT_00009abb);
  sci2_configure();
  sci3_set_baud();
  return;
}


// ===== menu_ex030108_step @ fffcebfa (22 bytes)

/* Menu item ex030108 CAT-2 RATE: on_step (#74) */

void menu_ex030108_step(void)

{
  menu_step_u8(0,4,&DAT_00009abc);
  sci0_set_baud();
  return;
}


// ===== menu_ex030109_step @ fffcec10 (18 bytes)

/* Menu item ex030109 CAT-2 TIME OUT TIMER: on_step (#74) */

void menu_ex030109_step(void)

{
  menu_step_u8(0,3,&DAT_00009abd);
  return;
}


// ===== menu_ex030110_step @ fffcec22 (22 bytes)

/* Menu item ex030110 CAT-3 RATE: on_step (#74) */

void menu_ex030110_step(void)

{
  menu_step_u8(0,4,&DAT_00009abe);
  sci2_configure();
  return;
}


// ===== menu_ex030111_step @ fffcec38 (18 bytes)

/* Menu item ex030111 CAT-3 TIME OUT TIMER: on_step (#74) */

void menu_ex030111_step(void)

{
  menu_step_u8(0,3,&DAT_00009abf);
  return;
}


// ===== menu_ex030112_step @ fffcec4a (22 bytes)

/* Menu item ex030112 QMB CH: on_step (#74) */

void menu_ex030112_step(void)

{
  menu_step_u8(0,1,&DAT_00009ac0);
  FUN_fffc4a8e();
  return;
}


// ===== menu_ex030113_step @ fffcec60 (18 bytes)

/* Menu item ex030113 BAND STACK: on_step (#74) */

void menu_ex030113_step(void)

{
  menu_step_u8(0,1,&DAT_00009ac1);
  return;
}


// ===== menu_ex030114_step @ fffcec72 (18 bytes)

/* Menu item ex030114 MEM GROUP: on_step (#74) */

void menu_ex030114_step(void)

{
  menu_step_u8(0,1,&DAT_00009ac2);
  return;
}


// ===== menu_ex030115_step @ fffcec84 (19 bytes)

/* Menu item ex030115 TX TIME OUT TIMER: on_step (#74) */

void menu_ex030115_step(void)

{
  menu_step_u8(0,0x1e,&DAT_00009ac3);
  return;
}


// ===== menu_ex030116_step @ fffcec97 (18 bytes)

/* Menu item ex030116 MIC SCAN: on_step (#74) */

void menu_ex030116_step(void)

{
  menu_step_u8(0,1,&DAT_00009ac4);
  return;
}


// ===== menu_ex030117_step @ fffceca9 (18 bytes)

/* Menu item ex030117 MIC SCAN RESUME: on_step (#74) */

void menu_ex030117_step(void)

{
  menu_step_u8(0,1,&DAT_00009ac5);
  return;
}


// ===== menu_ex030118_step @ fffcecbb (20 bytes)

/* Menu item ex030118 REF FREQ FINE ADJ: on_step (#74) */

void menu_ex030118_step(void)

{
  menu_step_s8(-0x19,'\x19',&DAT_00009ac6);
  return;
}


// ===== menu_ex030119_step @ fffceccf (78 bytes)

/* Menu item ex030119 KEYBOARD LANGUAGE: on_step (#74) */

void menu_ex030119_step(void)

{
  menu_step_u8(0,10,(byte *)&DAT_00009ac7);
  if (PTR_s_V01_12_0001b4fd._1_1_ == DAT_00009ac7) {
    return;
  }
  PTR_s_V01_12_0001b4fd._1_1_ = DAT_00009ac7;
  swtimer_start(0x2b,100);
  PTR_DAT_00025d60[0x401] = 1;
  return;
}


// ===== menu_ex030120_step @ fffced1d (19 bytes)

/* Menu item ex030120 MIC P1: on_step (#74) */

void menu_ex030120_step(void)

{
  menu_step_u8(0,0x14,&DAT_00009ac8);
  return;
}


// ===== menu_ex030121_step @ fffced30 (19 bytes)

/* Menu item ex030121 MIC P2: on_step (#74) */

void menu_ex030121_step(void)

{
  menu_step_u8(0,0x14,&DAT_00009ac9);
  return;
}


// ===== menu_ex030122_step @ fffced43 (19 bytes)

/* Menu item ex030122 MIC P3: on_step (#74) */

void menu_ex030122_step(void)

{
  menu_step_u8(0,0x14,&DAT_00009aca);
  return;
}


// ===== menu_ex030123_step @ fffced56 (19 bytes)

/* Menu item ex030123 MIC P4: on_step (#74) */

void menu_ex030123_step(void)

{
  menu_step_u8(0,0x14,&DAT_00009acb);
  return;
}


// ===== menu_ex030124_step @ fffced69 (19 bytes)

/* Menu item ex030124 MIC UP: on_step (#74) */

void menu_ex030124_step(void)

{
  menu_step_u8(0,0x14,&DAT_00009acc);
  return;
}


// ===== menu_ex030125_step @ fffced7c (19 bytes)

/* Menu item ex030125 MIC DOWN: on_step (#74) */

void menu_ex030125_step(void)

{
  menu_step_u8(0,0x14,&DAT_00009acd);
  return;
}


// ===== menu_ex030126_step @ fffced8f (78 bytes)

/* Menu item ex030126 SCU-LAN10: on_step (#74) */

void menu_ex030126_step(void)

{
  menu_step_u8(0,1,(byte *)&DAT_00009ace);
  if (PTR_s_V01_12_0001b4fd._2_1_ == DAT_00009ace) {
    return;
  }
  PTR_s_V01_12_0001b4fd._2_1_ = DAT_00009ace;
  swtimer_start(0x2b,100);
  PTR_DAT_00025d60[0x401] = 1;
  return;
}


// ===== menu_ex030201_step @ fffceddd (18 bytes)

/* Menu item ex030201 IF NOTCH WIDTH: on_step (#74) */

void menu_ex030201_step(void)

{
  menu_step_u8(0,1,&DAT_00009ad1);
  return;
}


// ===== menu_ex030202_step @ fffcedef (18 bytes)

/* Menu item ex030202 NB REJECTION: on_step (#74) */

void menu_ex030202_step(void)

{
  menu_step_u8(0,2,&DAT_00009ad2);
  return;
}


// ===== menu_ex030203_step @ fffcee01 (18 bytes)

/* Menu item ex030203 NB WIDTH: on_step (#74) */

void menu_ex030203_step(void)

{
  menu_step_u8(0,2,&DAT_00009ad3);
  return;
}


// ===== menu_ex030204_step @ fffcee13 (18 bytes)

/* Menu item ex030204 APF WIDTH: on_step (#74) */

void menu_ex030204_step(void)

{
  menu_step_u8(0,2,&DAT_00009ad4);
  return;
}


// ===== menu_ex030205_step @ fffcee25 (20 bytes)

/* Menu item ex030205 CONTOUR LEVEL: on_step (#74) */

void menu_ex030205_step(void)

{
  menu_step_s8(-0x28,'\x14',&DAT_00009ad5);
  return;
}


// ===== menu_ex030206_step @ fffcee39 (18 bytes)

/* Menu item ex030206 CONTOUR WIDTH: on_step (#74) */

void menu_ex030206_step(void)

{
  menu_step_u8(1,0xb,&DAT_00009ad6);
  return;
}


// ===== menu_ex030301_step @ fffcee4b (18 bytes)

/* Menu item ex030301 AMC RELEASE TIME: on_step (#74) */

void menu_ex030301_step(void)

{
  menu_step_u8(0,2,&DAT_00009ad9);
  return;
}


// ===== menu_ex030302_step @ fffcee5d (18 bytes)

/* Menu item ex030302 PRMTRC EQ1 FREQ: on_step (#74) */

void menu_ex030302_step(void)

{
  menu_step_u8(0,7,&DAT_00009ada);
  return;
}


// ===== menu_ex030303_step @ fffcee6f (19 bytes)

/* Menu item ex030303 PRMTRC EQ1 LEVEL: on_step (#74) */

void menu_ex030303_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009adb);
  return;
}


// ===== menu_ex030304_step @ fffcee82 (18 bytes)

/* Menu item ex030304 PRMTRC EQ1 BWTH: on_step (#74) */

void menu_ex030304_step(void)

{
  menu_step_u8(0,10,&DAT_00009adc);
  return;
}


// ===== menu_ex030305_step @ fffcee94 (18 bytes)

/* Menu item ex030305 PRMTRC EQ2 FREQ: on_step (#74) */

void menu_ex030305_step(void)

{
  menu_step_u8(0,9,&DAT_00009add);
  return;
}


// ===== menu_ex030306_step @ fffceea6 (19 bytes)

/* Menu item ex030306 PRMTRC EQ2 LEVEL: on_step (#74) */

void menu_ex030306_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009ade);
  return;
}


// ===== menu_ex030307_step @ fffceeb9 (18 bytes)

/* Menu item ex030307 PRMTRC EQ2 BWTH: on_step (#74) */

void menu_ex030307_step(void)

{
  menu_step_u8(0,10,&DAT_00009adf);
  return;
}


// ===== menu_ex030308_step @ fffceecb (19 bytes)

/* Menu item ex030308 PRMTRC EQ3 FREQ: on_step (#74) */

void menu_ex030308_step(void)

{
  menu_step_u8(0,0x12,&DAT_00009ae0);
  return;
}


// ===== menu_ex030309_step @ fffceede (19 bytes)

/* Menu item ex030309 PRMTRC EQ3 LEVEL: on_step (#74) */

void menu_ex030309_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009ae1);
  return;
}


// ===== menu_ex030310_step @ fffceef1 (18 bytes)

/* Menu item ex030310 PRMTRC EQ3 BWTH: on_step (#74) */

void menu_ex030310_step(void)

{
  menu_step_u8(0,10,&DAT_00009ae2);
  return;
}


// ===== menu_ex030311_step @ fffcef03 (18 bytes)

/* Menu item ex030311 P PRMTRC EQ1 FREQ: on_step (#74) */

void menu_ex030311_step(void)

{
  menu_step_u8(0,7,&DAT_00009ae3);
  return;
}


// ===== menu_ex030312_step @ fffcef15 (19 bytes)

/* Menu item ex030312 P PRMTRC EQ1 LEVEL: on_step (#74) */

void menu_ex030312_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009ae4);
  return;
}


// ===== menu_ex030313_step @ fffcef28 (18 bytes)

/* Menu item ex030313 P PRMTRC EQ1 BWTH: on_step (#74) */

void menu_ex030313_step(void)

{
  menu_step_u8(0,10,&DAT_00009ae5);
  return;
}


// ===== menu_ex030314_step @ fffcef3a (18 bytes)

/* Menu item ex030314 P PRMTRC EQ2 FREQ: on_step (#74) */

void menu_ex030314_step(void)

{
  menu_step_u8(0,9,&DAT_00009ae6);
  return;
}


// ===== menu_ex030315_step @ fffcef4c (19 bytes)

/* Menu item ex030315 P PRMTRC EQ2 LEVEL: on_step (#74) */

void menu_ex030315_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009ae7);
  return;
}


// ===== menu_ex030316_step @ fffcef5f (18 bytes)

/* Menu item ex030316 P PRMTRC EQ2 BWTH: on_step (#74) */

void menu_ex030316_step(void)

{
  menu_step_u8(0,10,&DAT_00009ae8);
  return;
}


// ===== menu_ex030317_step @ fffcef71 (19 bytes)

/* Menu item ex030317 P PRMTRC EQ3 FREQ: on_step (#74) */

void menu_ex030317_step(void)

{
  menu_step_u8(0,0x12,&DAT_00009ae9);
  return;
}


// ===== menu_ex030318_step @ fffcef84 (19 bytes)

/* Menu item ex030318 P PRMTRC EQ3 LEVEL: on_step (#74) */

void menu_ex030318_step(void)

{
  menu_step_s8(-0x14,'\n',&DAT_00009aea);
  return;
}


// ===== menu_ex030319_step @ fffcef97 (18 bytes)

/* Menu item ex030319 P PRMTRC EQ3 BWTH: on_step (#74) */

void menu_ex030319_step(void)

{
  menu_step_u8(0,10,&DAT_00009aeb);
  return;
}


// ===== menu_ex030401_step @ fffcefa9 (24 bytes)

/* Menu item ex030401 HF MAX POWER: on_step (#74) */

void menu_ex030401_step(void)

{
  byte bVar1;
  
  bVar1 = FUN_fffb3e6f(0);
  menu_step_u8(5,bVar1,&DAT_00009aee);
  return;
}


// ===== menu_ex030402_step @ fffcefc1 (24 bytes)

/* Menu item ex030402 50M MAX POWER: on_step (#74) */

void menu_ex030402_step(void)

{
  byte bVar1;
  
  bVar1 = FUN_fffb3e6f(1);
  menu_step_u8(5,bVar1,&DAT_00009aef);
  return;
}


// ===== menu_ex030403_step @ fffcefd9 (24 bytes)

/* Menu item ex030403 70M MAX POWER: on_step (#74) */

void menu_ex030403_step(void)

{
  byte bVar1;
  
  bVar1 = FUN_fffb3e6f(2);
  menu_step_u8(5,bVar1,&DAT_00009af0);
  return;
}


// ===== menu_ex030404_step @ fffceff1 (43 bytes)

/* Menu item ex030404 AM MAX POWER: on_step (#74) */

void menu_ex030404_step(void)

{
  byte bVar1;
  ushort uVar2;
  undefined1 local_1;
  
  uVar2 = dest_code_get();
  if (uVar2 == 0x60e6) {
    local_1 = 4;
  }
  else {
    local_1 = 3;
  }
  bVar1 = FUN_fffb3e6f(local_1);
  menu_step_u8(5,bVar1,&DAT_00009af1);
  return;
}

