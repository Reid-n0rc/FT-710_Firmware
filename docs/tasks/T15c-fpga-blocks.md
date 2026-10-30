# T15c — Block recognition (SDR)

**Status:** done · **Depends on:** T15b · **Parent:** [T15](T15-fpga-netlist.md)

## Goal
`docs/code/sdr/netlist.md`: clock domains, IOB groups, DSP48 cascades and BRAM to DSP links (DDC/filter chain), UART5
link to MAIN, scope/FFT SPI link to DISPLAY, TX path.

## Plan
See the parent [T15 plan](T15-fpga-netlist.md#plan). Tool `tools/xc7_blocks.py` (stdlib, `selftest`): clock roots
through the buffers, per-pin table with package pin/bank/standard/loads/clock, package check, DSP register sets and
cascades, BRAM readers, fan-in/fan-out cones, and an equation dump (LUTs reduced to their real inputs and printed as
minimal sum-of-products). Then read the blocks from the equations and evaluate decoders exhaustively.

## Findings
Documented in [`docs/code/sdr/netlist.md` section 3](../code/sdr/netlist.md#3-recognized-blocks-t15c).
- **Package:** only CSG324 or FGG484 bond every used IOB **[fact]**.
- **One 125 MHz fabric clock** from the LVDS pair F4/F3 (`IO_L13_MRCC_35`) feeds all 119 DSPs, the BRAMs and ~31,100
  flip-flops; 125 MHz follows from the UART divisor 1,086 = 115,200 baud **[inference, high]**. A second LVDS clock
  (E3/D3) clocks the 14 ADC IDDRs through a BUFIO. Two cascaded MMCMs make ~28.17 MHz, forwarded to pin P14
  (whether this is `DSP_CLK` is open: #67 confirmed the ~28.17 MHz divider reading [fact], which is not the 18.432 MHz the
  RT685 code is built for; O8 in docs/code/system.md §8, would be settled by measuring J2002 pin 22).
- **Pins:** bank 35 = ADC (14 LVDS DDR pairs + 2 clocks), bank 34 = 17 LVDS DDR outputs (TX DAC?), bank 14 = QSPI
  master on the config-flash pins (FCS_B, D00-D03, quad reads) + two UARTs + control lines, bank 15 (1.8 V) = a 3-wire
  SPI master (ADC configuration?) + control lines **[fact for wiring]**.
- **UARTs:** two identical instances, A = M18 rx / L18 tx, B = V12 rx / U12 tx. Receiver fully decoded: 1,086-clock
  bit timer re-aligned on every edge, mid-bit sample at 542, 10-stage preset shift register, byte + 2-clock strobe.
  The parser recognizes hex digits, `r`/`w`/**`x`**, `,`/space, CR/LF/BS **[fact]**. MAIN's frames (from its code):
  `r`+4 hex+2-hex sum+CR (7-byte reply), `w`+8 hex+sum+CR (ACK 0x06) **[fact]**.
- **DSP:** 34 DSPs share an operand with the DSP below (A/B cascade pairs, I/Q-mixer shape), 2 use PCIN; adder trees
  in fabric. The 1024-tap filter ROM feeds DSP B inputs; the x9 phase tables feed DSP A inputs; the cosine table goes
  through LUTs **[fact for links, inference for roles]**.
- **No DISPLAY scope SPI slave found yet** among the bank 14/15 inputs: candidates are the 3.3 V inputs into LUTs
  without a synchronizer; open.
- **UART B (V12/U12) is most likely MAIN's UART5** (it buffers a ~10-character line, MAIN's frame length) and
  **UART A (M18/L18) the debug console** (character-at-a-time, answers each character) **[inference]**.

## Follow-ups
- Confirm the UART A/B assignment on the module (pin path) or by a full-design simulation (T15d task file).
- Find the DISPLAY FFT/scope SPI slave and the I2S RX/TX ports among the remaining bank 14/15 pins.
- Settle the DSP OPMODE/ALUMODE reading (pin inversion / unrouted-pin default) before interpreting the DSP chain
  arithmetic.
- `x` command: what it does (look at the parser state machine after the class decode).
