// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff94536 @ fff94536 (17 bytes)

void FUN_fff94536(void)

{
  FUN_fffb1a9e();
  FUN_fffb1adb(DAT_0001b620);
  return;
}


// ===== FUN_fff94547 @ fff94547 (1 bytes)

void FUN_fff94547(void)

{
  return;
}


// ===== FUN_fff94548 @ fff94548 (282 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94637) */

void FUN_fff94548(void)

{
  uint uVar1;
  
  if (DAT_0001b61e == 0) {
    DAT_00001434 = *DAT_00020818;
    if ((DAT_00001434 == 6) || (DAT_00001434 == 0x3f)) {
      DAT_0001b620 = 1;
      return;
    }
    if (DAT_00001434 != 0x5a) {
      if (DAT_00001434 == 0x72) {
        DAT_0001b620 = 7;
        return;
      }
      DAT_00020818 = DAT_00020818 + -1;
      DAT_0001b61e = 0xffff;
      return;
    }
    DAT_00001434 = 'Z';
  }
  else if (DAT_00001434 == 'Z') {
    if (DAT_0001b61e == 1) {
      DAT_00001435 = *DAT_00020818;
      uVar1 = (uint)DAT_00001435;
      if (uVar1 == 0xa7) {
        DAT_0001b620 = 10;
        return;
      }
      if ((uVar1 == 0xa6) || (uVar1 - 0xa1 < 3)) {
        DAT_0001b620 = 2;
        return;
      }
    }
    else if ((DAT_0001b61e == 3) && (DAT_00001435 != 0xa7)) {
      DAT_0001b620 = CONCAT11(*DAT_00020818,DAT_00020818[-1]) + 6;
      return;
    }
  }
  return;
}


// ===== R_SCI5_Create @ fff94662 (163 bytes)

/* SCI5 init (SDR module FPGA link) */

void R_SCI5_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xfbffffff;
  bVar2 = DAT_00087354;
  DAT_00087354 = bVar2 & 0xfa | 10;
  bVar2 = DAT_00087355;
  DAT_00087355 = bVar2 & 0xfa | 10;
  DAT_0008a0a2 = 0;
  DAT_0008a0a2 = 0;
  bVar2 = DAT_0008a0a9;
  DAT_0008a0a9 = bVar2 & 0xfe;
  DAT_0008a0ad = 0;
  DAT_0008a0a0 = 0;
  DAT_0008a0a6 = 0x72;
  DAT_0008a0a7 = 0x50;
  DAT_0008a0a1 = 0x40;
  DAT_0008c1a2 = 10;
  bVar2 = DAT_0008c06c;
  DAT_0008c06c = bVar2 | 4;
  DAT_0008c1a3 = 10;
  bVar2 = DAT_0008c02c;
  DAT_0008c02c = bVar2 | 8;
  bVar2 = DAT_0008c00c;
  DAT_0008c00c = bVar2 | 8;
  FUN_fff94850();
  return;
}


// ===== FUN_fff94705 @ fff94705 (64 bytes)

void FUN_fff94705(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_00087055;
  DAT_00087055 = bVar1 & 0xfe;
  bVar1 = DAT_00087054;
  DAT_00087054 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 0x20;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x400;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 0x10;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x800;
  return;
}


// ===== R_SCI5_Stop @ fff94745 (104 bytes)

void R_SCI5_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c06c;
  DAT_0008c06c = bVar1 & 0xf7;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xdf;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xef;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0x7f;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xbf;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xdf;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffbff;
  bVar1 = DAT_00087055;
  DAT_00087055 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xef;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffff7ff;
  bVar1 = DAT_00087054;
  DAT_00087054 = bVar1 & 0xfe;
  return;
}


// ===== R_SCI5_Serial_Receive @ fff947ad (68 bytes)

undefined2 R_SCI5_Serial_Receive(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b624 = 0;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 0x40;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 0x10;
    DAT_0001b626 = param_2;
    DAT_00020820 = param_1;
  }
  return local_a;
}


// ===== R_SCI5_Serial_Send @ fff947f1 (95 bytes)

undefined2 R_SCI5_Serial_Send(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = DAT_0008720a;
    if ((bVar1 & 0x20) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 & 0xdf;
      bVar1 = DAT_0008a0a2;
      DAT_0008a0a2 = bVar1 | 0xa0;
      bVar1 = DAT_0008c06c;
      DAT_0008c06c = bVar1 | 8;
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 | 0x20;
      DAT_0001b622 = param_2;
      DAT_0002081c = param_1;
    }
  }
  return local_a;
}


// ===== FUN_fff94850 @ fff94850 (1 bytes)

void FUN_fff94850(void)

{
  return;
}


// ===== r_sci5_transmit_interrupt @ fff94851 (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94887) */
/* WARNING: Removing unreachable block (ram,0xfff94851) */
/* WARNING: Removing unreachable block (ram,0xfff94899) */

undefined4 r_sci5_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001b622 == 0) {
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0x7f;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a0a3 = *DAT_0002081c;
  DAT_0002081c = DAT_0002081c + 1;
  DAT_0001b622 = DAT_0001b622 + -1;
  return param_1;
}


// ===== r_sci5_receive_interrupt @ fff948c2 (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94928) */
/* WARNING: Removing unreachable block (ram,0xfff94930) */
/* WARNING: Removing unreachable block (ram,0xfff9492e) */
/* WARNING: Removing unreachable block (ram,0xfff948c2) */
/* WARNING: Removing unreachable block (ram,0xfff948c4) */
/* WARNING: Removing unreachable block (ram,0xfff9492a) */

undefined4 r_sci5_receive_interrupt(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b624 < DAT_0001b626) {
    uVar2 = DAT_0008a0a5;
    *DAT_00020820 = uVar2;
    FUN_fff94962();
    DAT_00020820 = DAT_00020820 + 1;
    DAT_0001b624 = DAT_0001b624 + 1;
  }
  if (DAT_0001b626 <= DAT_0001b624) {
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0xbf;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0xef;
    FUN_fff9495c();
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff9495b @ fff9495b (1 bytes)

void FUN_fff9495b(void)

{
  return;
}


// ===== FUN_fff9495c @ fff9495c (5 bytes)

void FUN_fff9495c(void)

{
  FUN_fffb1b15();
  return;
}


// ===== FUN_fff94961 @ fff94961 (1 bytes)

void FUN_fff94961(void)

{
  return;
}


// ===== FUN_fff94962 @ fff94962 (82 bytes)

void FUN_fff94962(void)

{
  char cVar1;
  
  if (DAT_0001b624 != 0) {
    return;
  }
  cVar1 = *DAT_00020820;
  if ((cVar1 != '\x06') && (cVar1 != '?')) {
    if (cVar1 == 'r') {
      DAT_0001b626 = 7;
      return;
    }
    DAT_00020820 = DAT_00020820 + -1;
    DAT_0001b624 = 0xffff;
    return;
  }
  DAT_0001b626 = 1;
  return;
}


// ===== FUN_fff949b4 @ fff949b4 (132 bytes)

void FUN_fff949b4(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfe;
  DAT_00087782 = 0xf;
  bVar2 = DAT_00087382;
  DAT_00087382 = bVar2 & 0xf4 | 4;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfe;
  DAT_00088110 = 0x2a;
  bVar2 = DAT_00088114;
  DAT_00088114 = bVar2 | 0x41;
  DAT_00088112 = 0;
  DAT_00088113 = 0;
  DAT_00088118 = 0x176;
  DAT_0008811a = 0x176;
  DAT_0008811c = 0x176;
  DAT_0008811e = 0x176;
  FUN_fff94a56();
  return;
}


// ===== FUN_fff94a38 @ fff94a38 (15 bytes)

void FUN_fff94a38(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087210;
  DAT_00087210 = bVar1 | 4;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 1;
  return;
}


// ===== FUN_fff94a56 @ fff94a56 (1 bytes)

void FUN_fff94a56(void)

{
  return;
}


// ===== vec130_isr @ fff94a57 (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94a5f) */
/* WARNING: Removing unreachable block (ram,0xfff94a57) */
/* WARNING: Removing unreachable block (ram,0xfff94a59) */
/* WARNING: Removing unreachable block (ram,0xfff94a61) */

undefined4 vec130_isr(undefined4 param_1)

{
  FUN_fffb2288();
  return param_1;
}


// ===== FUN_fff94a65 @ fff94a65 (104 bytes)

void FUN_fff94a65(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfd;
  DAT_00087790 = 0x14;
  bVar2 = DAT_00087390;
  DAT_00087390 = bVar2 & 0xfe | 0xe;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfd;
  DAT_00088120 = 0x20;
  bVar2 = DAT_00088124;
  DAT_00088124 = bVar2 | 0x41;
  DAT_00088122 = 0;
  DAT_00088128 = 0x270;
  DAT_0008812a = 5999;
  FUN_fff94aeb();
  return;
}


// ===== FUN_fff94acd @ fff94acd (15 bytes)

void FUN_fff94acd(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087212;
  DAT_00087212 = bVar1 | 1;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 2;
  return;
}


// ===== FUN_fff94adc @ fff94adc (15 bytes)

void FUN_fff94adc(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087212;
  DAT_00087212 = bVar1 & 0xfe;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 & 0xfd;
  return;
}


// ===== FUN_fff94aeb @ fff94aeb (1 bytes)

void FUN_fff94aeb(void)

{
  return;
}


// ===== vec144_isr @ fff94aec (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94af4) */
/* WARNING: Removing unreachable block (ram,0xfff94aec) */
/* WARNING: Removing unreachable block (ram,0xfff94aee) */
/* WARNING: Removing unreachable block (ram,0xfff94af6) */

undefined4 vec144_isr(undefined4 param_1)

{
  FUN_fffb2469();
  return param_1;
}


// ===== app_main @ fff94afa (145 bytes)

/* Init sequence, waits for power-on (flag 0x20B3A) while still serving cat_parse (so PS works when
   off), then subsystem init and main_loop */

void app_main(void)

{
  FUN_fffb3e6a();
  FUN_fffb2228();
  FUN_fffb27df();
  FUN_fffb01f3();
  FUN_fffb0229();
  FUN_fffbbd53();
  FUN_fffb1632();
  FUN_fff94cab();
  while (DAT_00020b3a == '\0') {
    FUN_fff94d6f();
    cat_parse();
    FUN_fffb3e6a();
  }
  if (DAT_00020b45 == '\x01') {
    DAT_00020b45 = '\0';
    FUN_fffb02af();
    DAT_00020f10 = 1;
    FUN_fffb3e6a();
  }
  FUN_fffb1f83();
  FUN_fffb6cde();
  FUN_fffa1132();
  FUN_fff9d06c();
  FUN_fffb55b8();
  FUN_fffb28d1();
  FUN_fffb98c8();
  FUN_fffec46c();
  FUN_fffc98aa();
  cat_apo_reset();
  main_loop();
  return;
}


// ===== main_loop @ fff94b8b (66 bytes)

/* Super-loop (no RTOS): polls ~16 tasks incl. cat_parse each pass */

void main_loop(void)

{
  do {
    FUN_fffb3e6a();
    FUN_fffb6d56();
    FUN_fffa11ed();
    FUN_fff9d1b9();
    FUN_fffb55c2();
    FUN_fffb28e2();
    cat_parse();
    FUN_fffe3e2a();
    FUN_fffe587f();
    FUN_fffe360e();
    FUN_fffe2cd0();
    FUN_fffb98e9();
    FUN_fffd0582();
    FUN_fff94d6f();
    FUN_fffbbd58();
    FUN_fffec473();
  } while( true );
}


// ===== ver_main @ fff94bcd (12 bytes)

/* Returns pointer to MAIN version string 0xFFFFFF00 (VE0) */

undefined4 ver_main(void)

{
  return 0xffffff00;
}


// ===== FUN_fff94bd9 @ fff94bd9 (12 bytes)

undefined4 FUN_fff94bd9(void)

{
  return 0xffffff10;
}


// ===== FUN_fff94be5 @ fff94be5 (12 bytes)

undefined4 FUN_fff94be5(void)

{
  return 0xffffff20;
}


// ===== ver_display @ fff94bf1 (12 bytes)

/* Returns pointer to DISPLAY version 0x1436 (VE1) */

void ver_display(void)

{
  return;
}


// ===== FUN_fff94bfd @ fff94bfd (18 bytes)

void FUN_fff94bfd(undefined4 *param_1)

{
  DAT_0000143a = *(undefined2 *)(param_1 + 1);
  DAT_00001436 = *param_1;
  return;
}


// ===== FUN_fff94c0f @ fff94c0f (12 bytes)

void FUN_fff94c0f(void)

{
  return;
}


// ===== FUN_fff94c1b @ fff94c1b (18 bytes)

void FUN_fff94c1b(undefined4 *param_1)

{
  DAT_00001440 = param_1[1];
  DAT_0000143c = *param_1;
  return;
}


// ===== ver_dsp @ fff94c2d (12 bytes)

/* Returns pointer to DSP version 0x1444 (VE3) */

void ver_dsp(void)

{
  return;
}


// ===== FUN_fff94c39 @ fff94c39 (18 bytes)

void FUN_fff94c39(undefined4 *param_1)

{
  DAT_00001448 = *(undefined2 *)(param_1 + 1);
  DAT_00001444 = *param_1;
  return;
}


// ===== ver_sdr @ fff94c4b (12 bytes)

/* Returns pointer to SDR version 0x144A (VE2) */

void ver_sdr(void)

{
  return;
}


// ===== FUN_fff94c57 @ fff94c57 (18 bytes)

void FUN_fff94c57(undefined4 *param_1)

{
  DAT_0000144e = *(undefined2 *)(param_1 + 1);
  DAT_0000144a = *param_1;
  return;
}


// ===== FUN_fff94c75 @ fff94c75 (54 bytes)

void FUN_fff94c75(undefined1 *param_1)

{
  byte2hex(&DAT_00001451,*param_1);
  byte2hex(&DAT_00001454,param_1[1]);
  DAT_00001450 = 0x56;
  DAT_00001453 = 0x2d;
  return;
}


// ===== FUN_fff94cab @ fff94cab (196 bytes)

void FUN_fff94cab(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = false;
  bVar2 = false;
  PTR_DAT_00025d38[0xb8] = 0xff;
  PTR_DAT_00025d38[0xb9] = 0xff;
  FUN_fffc3501();
  if (DAT_00009dbe == '\x05') {
    bVar2 = true;
    iVar3 = FUN_fff94fd5(0);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (DAT_00009dbf == '\x05') {
    bVar2 = true;
    iVar3 = FUN_fff94fd5(1);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    FUN_fffc4a8e();
  }
  if (bVar2) {
    FUN_fffb03c1();
  }
  FUN_fff950fb();
  PTR_DAT_00025d38[0x40b] = 1;
  FUN_fff9cee1();
  PTR_DAT_00025d38[0x72] = 0;
  PTR_DAT_00025d38[0x71] = 1;
  PTR_DAT_00025d38[0x484] = DAT_00009dc7;
  PTR_DAT_00025d38[0x485] = DAT_00009dc8;
  return;
}


// ===== FUN_fff94d6f @ fff94d6f (614 bytes)

void FUN_fff94d6f(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  
  FUN_fff9cee1();
  FUN_fffc8b55();
  FUN_fffcf45c();
  FUN_fff9513c();
  iVar5 = FUN_fffb171e();
  if (iVar5 == 1) {
    bVar1 = false;
    pcVar6 = (char *)FUN_fffb174f();
    uVar4 = FUN_fff95277(*pcVar6);
    pcVar7 = &DAT_0000198f;
    pcVar8 = pcVar6;
    for (uVar9 = (uint)uVar4; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar7 = *pcVar8;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    FUN_fffb172d();
    if (uVar4 == 0) {
      DAT_0001b3cd = '\x01';
      bVar1 = true;
    }
    else {
      if ((*pcVar6 == '\x06') || (*pcVar6 == '\x15')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((bVar2) && (iVar5 = FUN_fff9c60f(&DAT_0000198f,uVar4), iVar5 == 0)) {
        DAT_0001b3cd = '\x01';
        bVar1 = true;
      }
    }
    if (!bVar1) {
      FUN_fff95331(&DAT_0000198f);
    }
  }
  if ((PTR_DAT_00025d38[0x401] == '\x01') && (iVar5 = FUN_fffb23f3(0x2b), iVar5 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d38[0x401] = 0;
    PTR_DAT_00025d38[0x400] = 1;
  }
  if (DAT_0001b3d2 == '\x01') {
    iVar5 = sci1_tx_end();
    if (iVar5 == 0) {
      return;
    }
    DAT_0001b3d2 = '\0';
    DAT_0001b3d3 = '\x01';
    FUN_fffb237a(0x3b,2);
  }
  if ((DAT_0001b3d3 == '\x01') && (iVar5 = FUN_fffb23f3(0x3b), iVar5 == 1)) {
    DAT_0001b3d3 = '\0';
  }
  if (DAT_0001b3d5 == '\x01') {
    DAT_0001b3d5 = '\0';
    DAT_0001b3d4 = '\x01';
    FUN_fffb237a(0x3c,0x1e);
  }
  if (DAT_0001b3d3 != '\x01') {
    if (DAT_0001b3d4 == '\0') {
      if (DAT_0001b3cc == '\x01') {
        DAT_0001b3cc = '\0';
        FUN_fff95f26();
      }
      else if (DAT_0001b3cd == '\x01') {
        DAT_0001b3cd = '\0';
        FUN_fff95f3f();
      }
      else {
        FUN_fff951ff();
        if (DAT_0001b3d2 == '\x01') {
          DAT_0001b3d5 = '\x01';
        }
      }
    }
    else {
      iVar5 = FUN_fffb23f3(0x3c);
      if (iVar5 == 1) {
        DAT_0001b3d4 = '\0';
        FUN_fff951ff();
        if (DAT_0001b3d2 == '\x01') {
          DAT_0001b3d5 = '\x01';
        }
      }
      else if (DAT_0001b3cc == '\x01') {
        DAT_0001b3cc = '\0';
        FUN_fff95f26();
      }
      else if (DAT_0001b3cd == '\x01') {
        DAT_0001b3cd = '\0';
        FUN_fff95f3f();
      }
    }
    iVar5 = FUN_fffc911e();
    if (iVar5 == 0) {
      cVar3 = FUN_fff9ccd3();
      if (cVar3 == '\0') {
        PTR_DAT_00025d38[0x6a] = 1;
        PTR_DAT_00025d38[0x6b] = 1;
      }
      else {
        PTR_DAT_00025d38[0x6a] = 0;
        PTR_DAT_00025d38[0x6b] = 0;
      }
      FUN_fffb237a(0x4a,100);
      FUN_fffc912d(1);
      return;
    }
  }
  return;
}


// ===== FUN_fff94fd5 @ fff94fd5 (294 bytes)

undefined1 FUN_fff94fd5(uint param_1)

{
  byte bVar1;
  byte *local_c;
  char *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_0000901f;
    local_c = &DAT_00009020;
  }
  else {
    local_8 = &DAT_00009021;
    local_c = &DAT_00009022;
  }
  if (10 < DAT_00009014) {
    DAT_00009014 = 10;
  }
  if (*local_c == 0) {
    *local_8 = '\x01';
    if (DAT_00009ac0 == '\0') {
      if (DAT_00009014 < 6) {
        *local_c = DAT_00009014 - *local_8;
      }
      else {
        *local_c = 4;
      }
    }
    else {
      *local_c = DAT_00009014 - *local_8;
    }
  }
  else {
    bVar1 = *local_c + *local_8;
    if (DAT_00009ac0 == '\0') {
      *local_c = *local_c - 1;
      if (bVar1 < 6) {
        *local_8 = bVar1 - *local_c;
      }
      else {
        if (4 < *local_c) {
          *local_c = 0;
          return 0;
        }
        *local_8 = '\x05' - *local_c;
      }
    }
    else {
      *local_c = *local_c - 1;
      *local_8 = bVar1 - *local_c;
    }
  }
  FUN_fffc31a7(param_1 & 0xff,1);
  FUN_fffc334c(param_1 & 0xff);
  return 1;
}


// ===== FUN_fff950fb @ fff950fb (65 bytes)

void FUN_fff950fb(void)

{
  DAT_0000198b = DAT_0000901f;
  DAT_0000198c = DAT_00009020;
  DAT_0000198d = DAT_00009021;
  DAT_0000198e = DAT_00009022;
  return;
}


// ===== FUN_fff9513c @ fff9513c (195 bytes)

void FUN_fff9513c(void)

{
  if (DAT_0000198b != DAT_0000901f) {
    DAT_0000198b = DAT_0000901f;
  }
  if (DAT_0000198c != DAT_00009020) {
    DAT_0000198c = DAT_00009020;
  }
  if (DAT_0000198d != DAT_00009021) {
    DAT_0000198d = DAT_00009021;
  }
  if (DAT_0000198e != DAT_00009022) {
    DAT_0000198e = DAT_00009022;
  }
  if (PTR_DAT_00025d38[0x47f] != '\0') {
    FUN_fffb03e1(*(undefined1 *)((byte)PTR_DAT_00025d38[0x47f] - 1));
    PTR_DAT_00025d38[0x47f] = 0;
    return;
  }
  return;
}


// ===== FUN_fff951ff @ fff951ff (120 bytes)

void FUN_fff951ff(void)

{
  if (PTR_DAT_00025d38[0x98] == '\x01') {
    if (DAT_0001b3ce == '\0') {
      FUN_fff95f58();
      return;
    }
    DAT_0001b3cf = DAT_0001b3cf + 1;
    if (DAT_0001b3cf < 4) {
      FUN_fff96209();
      return;
    }
    DAT_0001b3cf = '\0';
    DAT_0001b3ce = '\0';
    if (DAT_0001b3d1 == '\x01') {
      DAT_0001b3d1 = 0;
      DAT_0001b3d0 = 0;
      PTR_DAT_00025d38[0x98] = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fff95277 @ fff95277 (186 bytes)

undefined2 FUN_fff95277(char param_1)

{
  undefined2 local_6;
  
  if ((param_1 == '\x06') || (param_1 == '\x15')) {
    local_6 = 1;
  }
  else if (param_1 == -0x3d) {
    local_6 = 0x23;
  }
  else if (param_1 == -0x3c) {
    local_6 = 0x107;
  }
  else if (param_1 == -0x3b) {
    local_6 = 7;
  }
  else if (param_1 == -0x20) {
    local_6 = 6;
  }
  else if (param_1 == -0x1f) {
    local_6 = 7;
  }
  else if (param_1 == -0x1e) {
    local_6 = 7;
  }
  else if (param_1 == -0x1d) {
    local_6 = 9;
  }
  else if (param_1 == -0x1c) {
    local_6 = 5;
  }
  else if (param_1 == -0x1b) {
    local_6 = 5;
  }
  else if (param_1 == -0x1a) {
    local_6 = 5;
  }
  else if (param_1 == -0x19) {
    local_6 = 10;
  }
  else if (param_1 == -0x18) {
    local_6 = 10;
  }
  else if (param_1 == -3) {
    local_6 = 0xb;
  }
  else if (param_1 == -0xf) {
    local_6 = 8;
  }
  else if (param_1 == -0x10) {
    local_6 = 10;
  }
  else {
    local_6 = 0;
  }
  return local_6;
}


// ===== FUN_fff95331 @ fff95331 (237 bytes)

void FUN_fff95331(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 == -0xf) {
    FUN_fff957e6(param_1);
  }
  else if (cVar1 == '\x15') {
    FUN_fff95469();
  }
  else if (cVar1 == -0x4d) {
    FUN_fff95ec9();
  }
  else if (cVar1 == -0x3d) {
    FUN_fff95e65(param_1);
  }
  else if (cVar1 == -0x3c) {
    FUN_fff95e97(param_1);
  }
  else if (cVar1 == -0x3b) {
    FUN_fff95e97(param_1);
  }
  else if (cVar1 == -0x20) {
    FUN_fff95829(param_1);
  }
  else if (cVar1 == -0x1f) {
    FUN_fff9588b(param_1);
  }
  else if (cVar1 == -0x1e) {
    FUN_fff95bf4(param_1);
  }
  else if (cVar1 == -0x1d) {
    FUN_fff95ed3(param_1);
  }
  else if (cVar1 == -0x1c) {
    FUN_fff95c6a();
    PTR_DAT_00025d38[0x82] = 0;
  }
  else if (cVar1 == -0x1b) {
    FUN_fff95c74();
  }
  else if (cVar1 == -0x1a) {
    FUN_fff95c8a(param_1);
  }
  else if (cVar1 == -0x19) {
    FUN_fff95cbc(param_1);
  }
  else if (cVar1 == -0x18) {
    FUN_fff95dad(param_1);
  }
  else if (cVar1 == -0x10) {
    FUN_fff9546a(param_1);
  }
  else if (cVar1 == '\x06') {
    FUN_fff9541e();
  }
  cVar1 = *param_1;
  if (((cVar1 != '\x06') && (cVar1 != '\x15')) && (cVar1 != -0x1d)) {
    cat_apo_reset();
    return;
  }
  return;
}


// ===== FUN_fff9541e @ fff9541e (75 bytes)

void FUN_fff9541e(void)

{
  if (DAT_0001b3ce == '\x01') {
    DAT_0001b3ce = '\0';
    DAT_0001b3cf = 0;
    if (DAT_0001b3d1 == '\x01') {
      DAT_0001b3d1 = 0;
      DAT_0001b3d0 = 0;
      PTR_DAT_00025d38[0x400] = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fff95469 @ fff95469 (1 bytes)

void FUN_fff95469(void)

{
  return;
}


// ===== FUN_fff9546a @ fff9546a (892 bytes)

void FUN_fff9546a(int param_1)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  short sVar4;
  
  DAT_000019bb = 0;
  DAT_000019b7 = 0;
  DAT_000019b3 = 0;
  DAT_000019af = 0;
  DAT_000019ab = 0;
  DAT_000019a7 = 0;
  DAT_000019a3 = 0;
  DAT_0000199f = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._0_1_ = 0x56;
  bVar3 = *(byte *)(param_1 + 1) >> 4;
  if ((bVar3 < 10) || (0xf < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar3 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar3 + 0x30;
  }
  bVar3 = *(byte *)(param_1 + 1) & 0xf;
  if ((bVar3 < 10) || (0xf < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar3 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar3 + 0x30;
  }
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._3_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._0_1_ = *(byte *)(param_1 + 2) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._1_1_ = *(byte *)(param_1 + 2) & 0x3f | 0x30;
  FUN_fff94bfd(&DAT_0000199f);
  DAT_000019bb = 0;
  DAT_000019b7 = 0;
  DAT_000019b3 = 0;
  DAT_000019af = 0;
  DAT_000019ab = 0;
  DAT_000019a7 = 0;
  DAT_000019a3 = 0;
  DAT_0000199f = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._0_1_ = *(byte *)(param_1 + 4) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._1_1_ = *(byte *)(param_1 + 4) & 0x3f | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._2_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._3_1_ = *(byte *)(param_1 + 5) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._0_1_ = *(byte *)(param_1 + 5) & 0x3f | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._1_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._2_1_ = *(byte *)(param_1 + 6) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._3_1_ = *(byte *)(param_1 + 6) & 0x3f | 0x30;
  FUN_fff94c1b(&DAT_0000199f);
  PTR_DAT_00025d38[0x9b] = *(undefined1 *)(param_1 + 7);
  PTR_DAT_00025d38[0x98] = 1;
  DAT_0001b3cc = 1;
  DAT_0001b3d0 = 1;
  PTR_DAT_00025d38[0x36] = 1;
  cVar1 = PTR_DAT_00025d38[0x9b];
  if (cVar1 == '\x10') {
    if (DAT_00009dc5 == '\0') {
      PTR_DAT_00025d38[0x36] = 0;
      return;
    }
  }
  else {
    if (cVar1 == '\x02') {
      PTR_DAT_00025d38[0xba] = 1;
      FUN_fffbb567();
      return;
    }
    if (cVar1 == '\x04') {
      PTR_DAT_00025d38[0x437] = 1;
      PTR_DAT_00025d38[0x34] = 0;
      return;
    }
    if (cVar1 == '\x05') {
      if (DAT_00004760 == '\0') {
        DAT_00004760 = 1;
        return;
      }
      DAT_00004760 = '\0';
      if (4 < DAT_00009a36) {
        DAT_00009a36 = 1;
        return;
      }
    }
    else {
      if (cVar1 == '\x06') {
        PTR_DAT_00025d38[0x98] = 0;
        DAT_0001b3d0 = 0;
        return;
      }
      if (cVar1 == '\a') {
        sVar4 = dest_code_get();
        if ((sVar4 == -0x567d) || (sVar4 == -0x4a59)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          dest_code_set(&DAT_0000d950);
        }
        else {
          if ((sVar4 == -0x26b0) || (sVar4 == -0x5b3b)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            dest_code_set(&DAT_0000a983);
          }
        }
        FUN_fffb3ba6();
        return;
      }
      if (cVar1 == '\x01') {
        settings_defaults(0);
        DAT_00020b45 = 1;
        FUN_fffb3ba6();
        return;
      }
    }
  }
  return;
}


// ===== FUN_fff957e6 @ fff957e6 (67 bytes)

void FUN_fff957e6(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 != -0x7d) {
    if (cVar1 == '\x02') {
      FUN_fff9d94d();
      return;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        FUN_fffa1576();
        return;
      }
      DAT_0001b3cd = 1;
      return;
    }
    DAT_00020b46 = 1;
  }
  DAT_0001b3cc = 1;
  return;
}

