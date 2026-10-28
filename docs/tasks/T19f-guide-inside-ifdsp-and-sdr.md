# T19f — Guide: Inside IFDSP and SDR

**Status:** in progress · **Depends on:** T19 (style guide)

## Goal
Write the draft chapter `docs/guide/parts/07-inside-ifdsp-and-sdr.md` with its SVG pictures in `docs/guide/img/`, for the single guide document, following the style guide in [T19](T19-illustrated-guide.md).

## Plan
Agent, 2026-10-28. Chapter `## 7. Inside the IF DSP and the SDR FPGA`, sources: docs/code/ifdsp/*, docs/code/sdr/*,
hdl/sdr/README.md, T15* findings, docs/memory-maps.md (IFDSP). Sections (each opens with a figure):

| Section | Figure |
|---|---|
| 7.1 One chip, two processors (M33 control, HiFi4 594 MHz DSP, shared SRAM, MU/SEMA42/rpmsg) | SVG `07-ifdsp-two-cores.svg`: the RT685 drawn with both cores, shared SRAM areas, and its external links |
| 7.2 Start-up (ROM, copy-down, codec, DSP load, MU flag handshake, console) | SVG `07-ifdsp-boot.svg` swim-lane timeline + Mermaid sequence of the 1-2-3 handshake |
| 7.3 Audio in, audio out (I2S slaves, AIC3204, 12 kHz, 24-sample blocks, threads; known filters/CTCSS/EQ/LMS, float32) | SVG `07-ifdsp-audio-path.svg` signal path with antenna/mic/speaker/display icons |
| 7.4 The register file (32K x 16, bands, examples, console modes, SPDR/SPDW) | SVG `07-ifdsp-register-map.svg` register file at a glance (not to scale) |
| 7.5 SDR: firmware without a CPU (bitstream, file layout, utilisation) | SVG `07-sdr-bitstream.svg` CPU program vs configuration bits, file layout, utilisation bars |
| 7.6 From bitstream to readable Verilog | SVG `07-sdr-recovery-pipeline.svg` FASM, cells, Verilog, Verilator, uart_link.v |
| 7.7 What is inside the FPGA (125 MHz, DDC/TX/scope, QSPI, UART A/B, reg 0 = 0x0104, `x`) | SVG `07-sdr-inside.svg` block drawing + console transcript |
| 7.8 Open questions | Mermaid flowchart of open points per chip |
| 7.9 Where to look | links, addresses |

Pointers: link frame formats -> chapter 2; JTAG hello-world / custom HDL -> chapter 8; SDR update flow -> chapter 4.

## Findings

## Follow-ups
