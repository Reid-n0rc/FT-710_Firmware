# T19f — Guide: Inside IFDSP and SDR

**Status:** done · **Depends on:** T19 (style guide)

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
Draft chapter [`docs/guide/parts/07-inside-ifdsp-and-sdr.md`](../guide/parts/07-inside-ifdsp-and-sdr.md), sections 7.1-7.9:
the RT685's two cores and shared SRAM; IF DSP start-up and the MU/SEMA42 handshake; the audio path (I2S slaves, codec,
12 kHz / 24-sample blocks, six threads, what the coefficient tables show); the register file and console modes (`SPDR`/`SPDW`);
the SDR image as a bitstream (layout, utilisation, tables, no soft CPU); the eight-step recovery pipeline (FASM, netlist,
Verilog, Verilator, `uart_link.v`); what is inside the FPGA (125 MHz, LVDS ADC/DAC, QSPI master, UART B = MAIN link,
UART A = `[IF]>` console, reg 0 = 0x0104, the `x` command); open questions; where to look. Pointers to chapter 2 (frame
formats), 4 (updates, SFL decoding), 5 (CAT `SPDR`/`SPDW`) and 8 (JTAG / custom code).

Figures (7 SVG, all checked with xmllint + rsvg-convert): `img/07-ifdsp-two-cores.svg`, `img/07-ifdsp-boot.svg`,
`img/07-ifdsp-audio-path.svg`, `img/07-ifdsp-register-map.svg`, `img/07-sdr-bitstream.svg`,
`img/07-sdr-recovery-pipeline.svg`, `img/07-sdr-inside.svg`. Mermaid: console-mode state diagram (7.4), open-questions
flowchart (7.8, captioned Figure 7.8). Plus a simulated `[IF]>` console transcript (7.7).

## Glossary terms
- Cortex-M33 — Arm's 32-bit microcontroller core; the IF DSP chip's control processor (198 MHz).
- HiFi4 — Cadence Tensilica audio DSP core; the IF DSP chip's signal processor (594 MHz).
- FreeRTOS — small open-source real-time operating system; runs the M33's tasks.
- XOS — Cadence's small real-time kernel for Xtensa/HiFi cores; runs the DSP's threads.
- MU (Messaging Unit) — RT685 hardware block that gives each core flag bits and mailbox registers the other core can see.
- SEMA42 — RT685 hardware semaphore block; a gate that only one core can hold at a time.
- rpmsg-lite — NXP's library for passing messages between two cores through shared memory.
- I2S — three-wire serial bus (bit clock, frame clock, data) for streaming audio samples.
- DMA — hardware that moves data between a peripheral and memory without the CPU.
- Codec — chip with an ADC and a DAC for audio; here the TI TLV320AIC3204.
- CTCSS — sub-audible tone (67-254 Hz) sent with FM speech to open a receiver's squelch.
- LMS — least-mean-squares adaptive filter that adjusts its own coefficients while it runs.
- FPGA — chip of configurable logic, memory and multipliers whose circuit is set by a bitstream.
- Bitstream — the configuration file of an FPGA: the bits that set every logic table, memory and wire switch.
- LUT — lookup table; the FPGA's basic logic cell, a small truth table with up to six inputs.
- DSP48 — Xilinx's hard multiply-accumulate block inside 7-series FPGAs.
- BRAM — block RAM; on-chip 18/36 Kbit memories of an FPGA, which can be pre-loaded with tables.
- MMCM — Xilinx clock generator (mixed-mode clock manager) that multiplies and divides clocks.
- LVDS — low-voltage differential signalling; fast data on a pair of wires.
- DDR — double data rate; one bit on each clock edge.
- QSPI — quad SPI; a four-data-line SPI bus, used here for flash memory.
- Project X-Ray — open-source database that documents the meaning of Xilinx 7-series configuration bits.
- FASM — FPGA assembly: a text list of the features (switches, tables, options) a bitstream turns on.
- Netlist — a list of circuit cells and the wires (nets) between them.
- Verilator — open-source tool that compiles Verilog into a fast C++ simulation model.

## Reference issues
- **DSP_CLK frequency vs the FPGA's output clock.** `docs/code/ifdsp/m33-platform.md` and `README.md` state the RT685's CLKIN
  (`DSP_CLK`, from the SDR module) is 18.432 MHz [fact from the M33 code]. `docs/code/sdr/netlist.md` §3.2 guesses that the
  ~28.17 MHz MMCM clock on pin P14 is `DSP_CLK`, and `resources.md` §Clocking guesses a ~16.6 MHz CLKOUT0 for the same role.
  Neither figure matches 18.432 MHz; the netlist page already doubts one MMCM divider. The guide calls the pin's role open.
- **`docs/code/sdr/README.md` key findings** still say "119 of 120 DSP48E1 (all fully pipelined)" and `resources.md`'s body
  says no DSP uses the pre-adder; both were corrected by T15b (`Z<reg>` inverted; 12 DSPs use the pre-adder). Only the
  correction box in `resources.md` reflects it.
- **MAIN function name:** `docs/code/ifdsp/control-link.md` calls 0xFFF9D8A4 `dev4_reg_access`; `docs/cat-commands.md`
  calls it `dsp_reg_access`.
- **Register count:** `docs/code/ifdsp/README.md` and `docs/cat-commands.md` say 113 registers; `control-link.md` findings say
  "about 110 live registers". The guide uses "about 110".
- **Register 6 on the DSP side:** `hifi4.md` says the mode numbering of reg 6 is "[unknown]", while `control-link.md` gives
  MAIN's mapping (CW-U 0 ... FM 9). Not a contradiction in values, but `hifi4.md` could link to it.
- `docs/code/sdr/bitstream.md` §Limits still says routing is not decoded into a netlist (true for T13, superseded by T15).

## Follow-ups
- The parent may render the two Mermaid figures (7.4 state diagram, 7.8 flowchart) on GitHub to confirm they display;
  no local Mermaid renderer was available.
- Figure numbering: SVG figures are 7.1-7.7, the open-questions Mermaid is captioned 7.8; the 7.4 state diagram is uncaptioned.
