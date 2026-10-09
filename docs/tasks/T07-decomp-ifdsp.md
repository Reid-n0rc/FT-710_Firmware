# T07 — Decompile IFDSP

**Status:** done (2026-10-09) · **Depends on:** T01 T02 T04

## Goal
Same as T05 for the IFDSP image → `decomp/ifdsp/`.

## Deliverables
Same as T05, or if Ghidra lacks a processor module for this DSP, a doc explaining the alternatives (a community module, a vendor disassembler).

## Notes / hints
- Check T02 for the DSP part (e.g. a TI C6000 or ADI SHARC). Ghidra support varies by part.

## Plan
1. Recon the raw image (`build/FT-710_IFDSP_V0101.bin`) with Python: non-zero regions, Thumb vs Xtensa opcode density,
   vector table, MCUXpresso `__data_section_table`/`__bss_section_table` at 0x08001130, and the DSP image pointers/sizes.
2. Cortex-M33: import with `ARM:LE:32:v8-m` (the only v8-M language in Ghidra 12.1.4), BinaryLoader, base 0x08000000.
   A pre-script (`tools/ghidra/IfdspM33Setup.java`) adds the copy-down `.data`/`.ramfunc` block (file-backed), `.bss`,
   the rest of SRAM (code alias 0x0, data alias 0x20000000), DSP TCM, RT685 peripherals and the PPB, labels the copy tables
   and DSP blobs, and seeds every vector-table entry as a Thumb function with RT685 IRQ names.
   A post-script (`tools/ghidra/IfdspFindFuncs.java`) disassembles leftover Thumb prologues in the code ranges and re-analyzes.
3. HiFi4: carve the embedded DSP images out (offsets/sizes from the M33 loader's literal pool), confirm their DSP load
   addresses from the M33 loader decompile and Xtensa reset-vector literals, and import them as one `Xtensa:LE:32:default`
   program with one block per image at its load address.
4. Export with `ExportDecomp.java` to `decomp/ifdsp/m33/` and `decomp/ifdsp/hifi4/`, then write `decomp/ifdsp/INDEX.md`,
   the IFDSP section of `docs/memory-maps.md`, and Findings/Follow-ups here.

## Findings
- **Part and layout**: NXP i.MX RT685 (Cortex-M33 + Cadence HiFi4). The decoded image is an RT600 FlexSPI-NOR boot image at XIP 0x08000000: FCFB at 0x400, M33 vectors at 0x1000, a small flash stub, three embedded HiFi4 images, and the M33 application's load image, which `ResetISR` copies to SRAM 0x00080000 **[fact]**. The full map is in `docs/memory-maps.md` (IFDSP).
- **Tooling**: no install was needed. Ghidra 12.1.4 ships `ARM:LE:32:v8-m` and `Xtensa:LE:32:default`. The carve tool is `tools/ifdsp_dsp_images.py`, and the Ghidra scripts are listed in `docs/tooling.md`.
- **M33**: 376 functions exported with 0 decompile failures. It runs FreeRTOS with three tasks: `Command Task` (a text console on FLEXCOMM0 USART) and `IpcRecvTask`/`IpcSendTask` (rpmsg-lite over MU-A). `BOARD_DSP_Init` 0x00084AD8 copies the DSP images to 0x24000000 / 0x00200000 / 0x20040000 and clears DSPSTALL **[fact]**. The M33 never touches FLEXCOMM1–7 or the codec **[fact]**.
- **HiFi4**: 1148 functions found from `entry a1,N` prologues (reliable entries). The decompile is **low quality**, because Ghidra's Xtensa module decodes only the base ISA and desynchronises on HiFi4 FLIX bundles. One function (`FUN_0020bb74`) crashed the decompiler. The DSP runs Cadence XOS threads (`Thread_Main/Ipc/Rx_Audio/Spi/Rx_Path/Tx_Path`) and probably drives all I2S/SPI audio and IF I/O **[inference]**.
- **Output**: `decomp/ifdsp/{m33,hifi4}/` (C files of 50 functions plus `functions.tsv`) and `decomp/ifdsp/INDEX.md` (notable functions and regeneration commands). The full rebuild was re-run and reproduced byte-identical output.

## Follow-ups
- **HiFi4 ISA decode**: a usable DSP decompile needs the RT685 HiFi4 core configuration (FLIX formats, HiFi4 opcodes). Options: the NXP/Cadence Xtensa toolchain for RT600 (`xt-objdump` with the `nxp_rt600_RI2021_8_newlib` core, a licensed download via MCUXpresso), or a community SLEIGH extension if one exists. Check licensing before installing and record it in `docs/tooling.md`.
- T12: decide whether the FLEXCOMM0 console (`console_rx_char` 0x00081430) is the MAIN↔IFDSP control link or only the J2009 debug port, and work out the MU-A/rpmsg message format (`ipc_print_dsp_reply` categories 0/1/3).
- T12: map the DSP threads to I2S/SPI channels (RX-IF, TX-AF, codec, FFT/REC/PLAY SPI to DISPLAY) from the FLEXCOMM base tables in the DSP literal pools.
- Two FreeRTOS port asm stubs (0x80A24, 0x80A90) hold an instruction the v8-m language can't decode. Read those in the raw bytes if they matter.

## Status
Done 2026-10-09. Deliverables: `decomp/ifdsp/` (m33 + hifi4 exports, INDEX.md), the IFDSP section in `docs/memory-maps.md`, `tools/ifdsp_dsp_images.py`, and `tools/ghidra/{IfdspM33Setup,IfdspFindFuncs,IfdspM33Names,IfdspHifi4Setup,IfdspHifi4FindFuncs,DumpFuncs}.java`. Code documentation (`docs/code/ifdsp/`) is T12's scope.
