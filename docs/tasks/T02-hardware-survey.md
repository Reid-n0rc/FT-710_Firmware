# T02 — Hardware survey

**Status:** done · **Depends on:** —

## Goal
Identify every processor and programmable device in the FT-710 and which SFL image runs on each one.

## Deliverables
- `docs/hardware.md`: per board, the CPU/DSP/FPGA part numbers, architecture, external flash/RAM, the buses between CPUs (UART/SPI/etc.), the CAT/USB path, and the debug headers (JTAG/SWD/UART test points).

## Notes / hints
- Source: `Manuals/FT-710_serv_2022.pdf`. Use `pdftotext -f N -l M` on small page ranges, and find the block diagram and parts lists first.
- Architecture plus flash part determine the Ghidra language and load address in T05–T08.

## Plan
1. `pdfinfo` the service manual; per-page `pdftotext` word counts to find text vs image-only pages.
2. Locate the table of contents, block diagram, unit/board list, and parts lists (grep for `IC`, `CPU`, `DSP`, `FPGA`, `Flash`, `EEPROM`, `SDRAM`, `USB`, `UART`).
3. From the parts lists, pull every IC with reference designator, part number and board; identify processors, memories, clocks, USB/RS-232 parts.
4. From the schematics/block diagram (text or one low-res render if needed), trace inter-processor buses, CAT/USB path and programming/debug headers.
5. Map MC/PC/ID/SR images to processors with evidence + confidence; derive Ghidra language IDs and likely flash base addresses (marked as guesses where not in the manual).
6. Write `docs/hardware.md`, then update this file's Findings/Follow-ups/Status. No git writes (parent commits).

## Findings
Full details with page citations: [`docs/hardware.md`](../hardware.md).

- Boards: MAIN, PA, DISPLAY, JACK, plus an undocumented plug-in **SDR module** (ADC + FPGA) on MAIN J2002/J3003. There is no separate IF-DSP board.
- **MC → Q1001 Renesas RX651 R5F56514ADFB** (MAIN CPU, 24 MHz crystal, BR25G256 SPI EEPROM). CAT path: USB-B → CY7C65631 hub → CP2105 (SCI port → RX SCI0, ECI port → RX SCI3). Debug header J1005 "RX-CPU DEBUG" carries FINE (MD) plus SCI1 boot UART.
- **PC → Q6009 Renesas RZ/A1H R7S721001VCBG** (Cortex-A9, DISPLAY unit). W25Q128JV 16 MB SPI flash on SPIBSC0, no SDRAM. JTAG header J6003. It owns the SD card and drives RX_UPDATE/RX_RESET plus a UART to the RX651, so the display CPU reflashes MAIN through RX serial boot mode.
- **ID → Q2002 NXP i.MX RT685 MIMXRT685SFVKB** (Cortex-M33 + HiFi4, labelled "DSP MAIN/TX"). W25Q128JV/MT25QL128 QSPI on FlexSPI A, boot strap 011 = FlexSPI A, DSP_UPDATE → serial ISP. SWD + UART header J2009 "DSP_JTAG".
- **SR → SDR module FPGA** (part unknown, 125 MHz from a 250 MHz clock off the 35.7142 MHz VCTCXO). 6-pin JTAG header J2001 "SDR JTAG". SDR_UPDATE/SDR_RESET/UART come from the RX651.
- Also present: FT4222H USB-SPI bridge into the RZ/A1H (hub port 3), CM119B USB audio, an EP102C/EP952/EPF021M DVI/HDMI chain (EPF021M is a small MCU, not in any SFL).
- Ghidra: stock 12.1.4 has **no Renesas RX module** (T05 is blocked on an extension). DISPLAY = `ARM:LE:32:v7` (base then unknown; settled in T06: load base 0x20100000 [fact], see memory-maps.md). IFDSP = `ARM:LE:32:v8-m` (settled in T07: XIP base 0x08000000, M33 image copied to SRAM 0x00080000 [fact]), with any HiFi4 code `Xtensa:LE:32:default`. SDR = FPGA bitstream.

## Follow-ups
- T05 needs a Renesas RX (RXv2) SLEIGH processor module for Ghidra 12.1.4, or a fallback disassembler (`rx-elf-objdump`). Add a tooling task.
- Verify the RX651 R5F56514 memory map (512 KB code flash at 0xFFF80000?) and the RZ/A1H boot mode against the Renesas datasheets. **RX651 part done in T18** (512 KB at 0xFFF80000, no data flash).
- After T04 decodes the payloads: confirm the vector tables and base addresses. Identify the SDR FPGA vendor from bitstream sync words.
- The MAIN SFL size (~2.6× 512 KB) hints at a text/S-record-style payload (settled in T04: MAIN's plaintext is a Motorola S-record with valid checksums [fact]).
- Unresolved: the RZ boot-strap population, J1005 pins 7/8, the C4-bus endpoint (probably the RT685), and the FT4222H's purpose.
