// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== data_init @ 08001222 (18 bytes)

void data_init(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 4) {
    *(undefined4 *)(uVar1 + param_2) = *(undefined4 *)(uVar1 + param_1);
  }
  return;
}


// ===== bss_init @ 08001234 (16 bytes)

void bss_init(int param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 4) {
    *(undefined4 *)(uVar1 + param_1) = 0;
  }
  return;
}


// ===== WDT0_IRQHandler @ 08001244 (8 bytes)

void WDT0_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== DMA0_IRQHandler @ 0800124c (8 bytes)

void DMA0_IRQHandler(void)

{
  __DMA0_DriverIRQHandler_veneer();
  return;
}


// ===== GPIO_INTA_IRQHandler @ 08001254 (8 bytes)

void GPIO_INTA_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== GPIO_INTB_IRQHandler @ 0800125c (8 bytes)

void GPIO_INTB_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== PIN_INT0_IRQHandler @ 08001264 (8 bytes)

void PIN_INT0_IRQHandler(void)

{
  __PIN_INT0_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT1_IRQHandler @ 0800126c (8 bytes)

void PIN_INT1_IRQHandler(void)

{
  __PIN_INT1_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT2_IRQHandler @ 08001274 (8 bytes)

void PIN_INT2_IRQHandler(void)

{
  __PIN_INT2_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT3_IRQHandler @ 0800127c (8 bytes)

void PIN_INT3_IRQHandler(void)

{
  __PIN_INT3_DriverIRQHandler_veneer();
  return;
}


// ===== UTICK0_IRQHandler @ 08001284 (8 bytes)

void UTICK0_IRQHandler(void)

{
  __UTICK0_DriverIRQHandler_veneer();
  return;
}


// ===== MRT0_IRQHandler @ 0800128c (8 bytes)

void MRT0_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== CTIMER0_IRQHandler @ 08001294 (8 bytes)

void CTIMER0_IRQHandler(void)

{
  __CTIMER0_DriverIRQHandler_veneer();
  return;
}


// ===== CTIMER1_IRQHandler @ 0800129c (8 bytes)

void CTIMER1_IRQHandler(void)

{
  __CTIMER1_DriverIRQHandler_veneer();
  return;
}


// ===== SCT0_IRQHandler @ 080012a4 (8 bytes)

void SCT0_IRQHandler(void)

{
  __SCT0_DriverIRQHandler_veneer();
  return;
}


// ===== CTIMER3_IRQHandler @ 080012ac (8 bytes)

void CTIMER3_IRQHandler(void)

{
  __CTIMER3_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM1_IRQHandler @ 080012b4 (8 bytes)

void FLEXCOMM1_IRQHandler(void)

{
  __FLEXCOMM1_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM2_IRQHandler @ 080012bc (8 bytes)

void FLEXCOMM2_IRQHandler(void)

{
  __FLEXCOMM2_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM3_IRQHandler @ 080012c4 (8 bytes)

void FLEXCOMM3_IRQHandler(void)

{
  __FLEXCOMM3_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM4_IRQHandler @ 080012cc (8 bytes)

void FLEXCOMM4_IRQHandler(void)

{
  __FLEXCOMM4_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM5_IRQHandler @ 080012d4 (8 bytes)

void FLEXCOMM5_IRQHandler(void)

{
  __FLEXCOMM5_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM14_IRQHandler @ 080012dc (8 bytes)

void FLEXCOMM14_IRQHandler(void)

{
  __FLEXCOMM14_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM15_IRQHandler @ 080012e4 (8 bytes)

void FLEXCOMM15_IRQHandler(void)

{
  __FLEXCOMM15_DriverIRQHandler_veneer();
  return;
}


// ===== ADC0_IRQHandler @ 080012ec (8 bytes)

void ADC0_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== Reserved39_IRQHandler @ 080012f4 (8 bytes)

void Reserved39_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== ACMP_IRQHandler @ 080012fc (8 bytes)

void ACMP_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== DMIC0_IRQHandler @ 08001304 (8 bytes)

void DMIC0_IRQHandler(void)

{
  __DMIC0_DriverIRQHandler_veneer();
  return;
}


// ===== Reserved42_IRQHandler @ 0800130c (8 bytes)

void Reserved42_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== HYPERVISOR_IRQHandler @ 08001314 (8 bytes)

void HYPERVISOR_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== SECUREVIOLATION_IRQHandler @ 0800131c (8 bytes)

/* weak handler of this vector slot in mcux-sdk MCUX_2.9.0 mcuxpresso/startup_mimxrt685s.c, which
   the image's startup matches byte for byte [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)];
   IfdspM33Setup names the slot SECURE_VIOLATION (later SDK name) (T24 round 2) */

void SECUREVIOLATION_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== HWVAD0_IRQHandler @ 08001324 (8 bytes)

void HWVAD0_IRQHandler(void)

{
  __HWVAD0_DriverIRQHandler_veneer();
  return;
}


// ===== Reserved46_IRQHandler @ 0800132c (8 bytes)

void Reserved46_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== RNG_IRQHandler @ 08001334 (8 bytes)

void RNG_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== RTC_IRQHandler @ 0800133c (8 bytes)

void RTC_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== DSPWAKE_IRQHandler @ 08001344 (8 bytes)

/* MCUX_2.9.0 startup name of this vector slot [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)];
   IfdspM33Setup names it DSP_TIE_EXPSTATE1 (T24 round 2) */

void DSPWAKE_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== PIN_INT4_IRQHandler @ 0800134c (8 bytes)

void PIN_INT4_IRQHandler(void)

{
  __PIN_INT4_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT5_IRQHandler @ 08001354 (8 bytes)

void PIN_INT5_IRQHandler(void)

{
  __PIN_INT5_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT6_IRQHandler @ 0800135c (8 bytes)

void PIN_INT6_IRQHandler(void)

{
  __PIN_INT6_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT7_IRQHandler @ 08001364 (8 bytes)

void PIN_INT7_IRQHandler(void)

{
  __PIN_INT7_DriverIRQHandler_veneer();
  return;
}


// ===== CTIMER2_IRQHandler @ 0800136c (8 bytes)

void CTIMER2_IRQHandler(void)

{
  __CTIMER2_DriverIRQHandler_veneer();
  return;
}


// ===== CTIMER4_IRQHandler @ 08001374 (8 bytes)

void CTIMER4_IRQHandler(void)

{
  __CTIMER4_DriverIRQHandler_veneer();
  return;
}


// ===== OS_EVENT_IRQHandler @ 0800137c (8 bytes)

void OS_EVENT_IRQHandler(void)

{
  __OS_EVENT_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXSPI_IRQHandler @ 08001384 (8 bytes)

void FLEXSPI_IRQHandler(void)

{
  __FLEXSPI_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM6_IRQHandler @ 0800138c (8 bytes)

void FLEXCOMM6_IRQHandler(void)

{
  __FLEXCOMM6_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM7_IRQHandler @ 08001394 (8 bytes)

void FLEXCOMM7_IRQHandler(void)

{
  __FLEXCOMM7_DriverIRQHandler_veneer();
  return;
}


// ===== USDHC0_IRQHandler @ 0800139c (8 bytes)

void USDHC0_IRQHandler(void)

{
  __USDHC0_DriverIRQHandler_veneer();
  return;
}


// ===== USDHC1_IRQHandler @ 080013a4 (8 bytes)

void USDHC1_IRQHandler(void)

{
  __USDHC1_DriverIRQHandler_veneer();
  return;
}


// ===== SGPIO_INTA_IRQHandler @ 080013ac (8 bytes)

void SGPIO_INTA_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== SGPIO_INTB_IRQHandler @ 080013b4 (8 bytes)

void SGPIO_INTB_IRQHandler(void)

{
  IntDefaultHandler();
  return;
}


// ===== I3C0_IRQHandler @ 080013bc (8 bytes)

void I3C0_IRQHandler(void)

{
  __I3C0_DriverIRQHandler_veneer();
  return;
}

