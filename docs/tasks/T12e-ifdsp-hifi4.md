# T12e — IFDSP HiFi4 DSP code (threads, audio I/O, tables)

**Status:** todo · **Parent:** T12 · **Depends on:** T12a

## Goal
`docs/code/ifdsp/hifi4.md`: XOS threads, peripheral base tables and which FLEXCOMM/DMA each thread uses, audio paths (RX IF, TX AF, codec, SPI to DISPLAY), coefficient tables, what can be learned despite the base-ISA-only Xtensa decode.

## Plan
See T12 plan. Starting notes from T12a below. No HiFi4 names script exists yet; create `tools/ghidra/IfdspHifi4Names.java` in the same format as `IfdspM33Names.java`.

## Starting notes (from T12a)
- Method that works despite FLIX: a heuristic L32R scan (byte0 low nibble 1; target = ((pc+3)&~3) + (imm16|0xFFFF0000)<<2) per function range from `functions.tsv`, resolving literal values. Scripts: `tools/ifdsp_l32r.py` and `tools/ifdsp_regscan.py` (args: `build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin decomp/ifdsp/hifi4/functions.tsv`); output `build/ifdsp_hifi4_l32r.txt`.
- Thread creators (name literal → creator): `Thread_Main`+`Thread_Ipc` 0x21C498 (entries 0x21C360, 0x21C3B4; also 0x20060000/0x200631E0, 18.432 MHz, 24 MHz), `Thread_Rx_Audio` 0x220BD0 (entry 0x220F90), `Thread_Spi` 0x224A10 (entry 0x224AA4), `Thread_Rx_Path`+`Thread_Tx_Path` 0x225E40 (entries 0x2262FC, 0x22647C; DMA1 + FC2).
- Peripheral literals per function: DMA0 0x220FD0; FC1 0x2210A4/0x2210DC/0x22111C (buffers 0x200607E0, 0x200619E0); FC2+DMA1 0x225E40; FC3/FC4/FC5 0x2260D8 (8 DMA buffers 0x20062BE0 + n·0xC0); MU-B 0x212D00/0x212DAC/0x21C3B4; SEMA42 0x213D10; FlexSPI 0x20BB00/0x20C92C; SDK FLEXCOMM instance stubs 0x20B904..0x20BA90 (FC0–7, 14, 15); clock/reset driver 0x207D58..0x209B30.
- Register file: DSP uses base 0x2006FF00 (reg = imm8 − 0x80 via L16UI/S16I) and 0x20077F00 (0x4000 + imm8 − 0x80). 0x21BE80 writes defaults to regs 1–0x68 and 0x4001–0x4025 (matches the MAIN register list in T12b). 0x21C060 reads GPIO P0_21/P0_22 and writes reg 0x4004; 0x21F348 writes reg 0x4005 (PWM duty); 0x223320/0x22338C use 0x20078010/12 (regs 0x4008/0x4009); 0x22E990 uses regs 0x21/0x22. Reads mostly happen inside FLIX code and are not decodable.
- Strings: only XOS, rpmsg, libm (`powf`, `sqrtf`) and printf tables — no algorithm names. Float tables in rodata 0x200000–0x206000 and .data 0x236800+.

## Findings

## Status
