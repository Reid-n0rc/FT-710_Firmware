# SDR FPGA: volatile JTAG "hello" bitstream — plan (T16)

**Plan only, for owner approval. Nothing has been loaded.** A JTAG load goes into the XC7A50T's configuration SRAM
only; it never touches the module's QSPI config flash, and a power cycle restores the stock design. Even so, it is a
write to the radio and needs the owner's explicit approval (AGENTS.md).

Claims are tagged **[fact]**, **[inference]** or **[guess]**. Sources: [interfaces.md](../code/sdr/interfaces.md) (J2002
pin map), [resources.md](../code/sdr/resources.md) (I/O, clocks), [update.md](../code/display/update.md) section 8 (update
path), `docs/hardware.md` (J2001), and the new package fit below.

## What we know about the pins

**J2001 "SDR JTAG"** (06FLT-SM2, P1091255, MAIN unit, p35/p19): 1 GND, 2 VDD (`SDR_VDD` = module `DIG_+3.3V`), 3 TCK,
4 TDO, 5 TMS, 6 TDI **[fact]**. The JTAG nets run from J2002 (module pins 15–18) to J2001 only, so the chain should hold
just the FPGA **[inference]**. Expected IDCODE 0x0362C093 (XC7A50T) **[fact, T08]**.

**Package: CSG324 or FGG484** **[inference]**. `tools/xc7_package_fit.py` maps the 116 IOB sites the stock bitstream
configures (input buffer, drive or LVDS features in the T15 FASM) onto each XC7A50T package in prjxray-db. Only CSG324
(210 user I/O) and FGG484 (250) bond all of them; CPG236 bonds 57, CSG325 82, FTG256 97 of the 116, i.e. they lack 59, 34 and 19 (the "19 to 59" of [netlist.md §3.1](../code/sdr/netlist.md#31-package)) **[fact for the counts]**. The
IDCODE does not encode the package, so the marking on the chip (under the module's shield) must be read before any pin
constraint is written **[fact]**.

| Bank | Used sites | What they look like | VCCO [inference] |
|---|---|---|---|
| 14 | 35 | LVCMOS33 outputs (22 with drive) and inputs; includes the config pins D00_MOSI (driven), D01_DIN, D02, D03 (inputs) and **FCS_B (driven)** | 3.3 V |
| 15 | 11 | LVCMOS33, 7 outputs | 3.3 V |
| 34 | 36 | **18 LVDS_25 output pairs** (one per IOB tile, fast slew) | 2.5 V |
| 35 | 34 | **16 LVDS_25 input pairs** (`IN_DIFF`), MRCC/SRCC clock-capable pairs among them | 2.5 V |

All **[fact]** for the FASM features (prjxray `IOB_Y0` = master/P site, `IOB_Y1` = slave, from `tile_type_LIOB33.json`).
Two readings follow **[inference]**:

- 16 input pairs and 18 output pairs, i.e. twice the "about 9 pairs" of resources.md (which counted sites, not pairs):
  a DDR/parallel LVDS ADC and a TX DAC.
- The design uses the QSPI pins as **user I/O** after configuration (D00 as an output, D01–D03 as inputs, FCS_B driven).
  That is a fabric SPI-flash master (CCLK through STARTUPE2 `USRCCLKO`), which fits T11c: the FPGA itself erases and
  programs its flash during an SDR update, fed by the DISPLAY RSPI2 data and MAIN's register bridge.

**Which J2002 signal sits on which ball is unknown.** That needs the routing walk of T15 (IOB → logic), or probing.
*(Update, T15/T15e: the routing walk is done. UART A on **M18 in / L18 out** is `UART_DBG`, the stock `[IF]>` debug console; UART B on
V12/U12 is MAIN's UART5; the fabric clock enters on F4/F3 (`IO_L13_MRCC_35`) at 125 MHz [inference, high]. Ball names are CSG324
[guess for the package]. See [netlist.md §3.3, §5.3](../code/sdr/netlist.md). Other J2002 signals are still unmapped.)*

## Stage 1 — JTAG-only hello (no outputs at all)

Goal: prove that a self-built bitstream loads and runs, without driving a single pin.

| Element | Choice | Why |
|---|---|---|
| Clock | `STARTUPE2.CFGMCLK` (internal ~65 MHz configuration oscillator) and the JTAG `TCK` from `BSCANE2` | needs no board clock and no pin constraint |
| Readout | `BSCANE2` (JTAG_CHAIN 1, IR USER1 = 0x02): a 64-bit DR that captures `"HELO"` (0x48454C4F) + a 32-bit counter clocked by CFGMCLK | a changing counter proves the fabric runs |
| Identity | `BITSTREAM.CONFIG.USERID 0x7E57_0001` (read with IR USERCODE 0x08) | proves *our* bitstream is loaded, even before the fabric test |
| I/O | **no top-level ports**. `BITSTREAM.CONFIG.UNUSEDPIN Pulldown` (Vivado default) | nothing driven; all pins weakly pulled down |
| STARTUPE2 | `USRCCLKTS = 1`, `USRDONETS = 1`, `GSR/GTS = 0`, `KEYCLEARB = 1` | CCLK stays tristated, so the flash cannot be clocked; FCS_B pulled down alone does nothing |
| Bitstream options | `BITSTREAM.GENERAL.COMPRESS FALSE`, no encryption, `CONFIG_VOLTAGE 3.3`, `CFGBVS VCCO` | plain JTAG load |
| Toolchain | Vivado ML Standard (free; supports XC7A50T in CSG324 and FGG484), or openXC7 (yosys + nextpnr-xilinx + prjxray) | part `xc7a50t<pkg>-1`; speed grade does not matter for this design |

No pin constraint is needed, so stage 1 works even before the package is known (build for either; a JTAG load checks
only the IDCODE) **[inference]**.

### Procedure (each run needs approval)

1. Radio on the bench: dummy load on the antenna jack, **no TX** (no PTT, footswitch, CAT TX or CW key), current-limited
   13.8 V supply, radio in RX.
2. Cable on J2001 (see adapters below), VREF from pin 2. **Read-only first:** scan the chain, read IDCODE (expect
   0x0362C093) and the stock USERCODE and STAT registers. Record them.
3. Load the hello bitstream into SRAM only: `openFPGALoader -c <cable> hello.bit` (SRAM is the default), or Vivado
   Hardware Manager "Program Device". **Never** use `-f`/`--write-flash`, "Add Configuration Memory Device" or any
   indirect flash programming (`bscan_spi`) bitstream.
4. Read USERCODE (expect 0x7E570001), then shift USER1 twice and check that the counter advances.
5. **Rollback: power cycle the radio.** The FPGA reconfigures from its QSPI flash in master-SPI mode (BSPI 0x26B,
   [interfaces.md](../code/sdr/interfaces.md)), and MAIN/IFDSP/DISPLAY restart. Confirm the stock USERCODE again.

### What happens to the radio during the test [inference]

- A JTAG load starts with `JPROGRAM`: the stock design stops at once, all user pins go high-Z (with the PUDC_B-selected
  pull-ups during configuration), then the hello design's pull-downs.
- Lost while it runs: the I2S RX audio to the RT685, **`DSP_CLK` (the RT685's only clock, J2002 pin 22)**, the scope SPI
  to DISPLAY, the UART5 replies to MAIN, the TX DAC data. Expect no audio, a frozen scope, MAIN/DSP errors or a DSP
  lock-up. All of these clear with the power cycle, because every CPU resets **[inference]**.
- The TX DAC loses its LVDS data and clock; with the PA not keyed by MAIN there is no RF path. The dummy load covers the
  unexpected case **[inference]**.
- The QSPI flash cannot be written: no fabric logic exists to drive it, and CCLK is tristated **[inference]**.

## Stage 2 — one benign output (after T15 maps the pins)

Only after T15 identifies the IOB of a harmless net and the board clock input. *(T15/T15e have done this: `UART_DBG_TX` is L18 and the
125 MHz clock is F4/F3, see above. The stock design already has a debug console on that UART, so stage 2 can first just listen to it.)*

- Candidate output: `UART_DBG_TX` (J2002 pin 47 → `SDR_DBG_OUT` on MAIN, through R2088 470 Ω) **[fact for the net]**;
  its MAIN-side load is not known yet, which is the reason to wait. Send `HELLO\r\n` at 115200 baud; observe with a 3.3 V
  logic analyser or USB-serial adapter on the net.
- Clock: the board clock (125 MHz per the service-manual block diagram, p6) on the MRCC pin that T15 finds feeding the
  MMCMs **[guess for the frequency at the pin]**, or keep CFGMCLK and calibrate the baud rate against it.
- Copy the stock design's I/O standard and drive for that site (LVCMOS33, 12/16 mA, slow slew in banks 14/15) **[fact
  for the stock settings]**. Every other pin stays unused.
- Same rollback: power cycle.

## Out of scope here

- Writing the config flash (persistent): needs the stock update path (SDR SFL, exact size 0x43075A) or an indirect
  JTAG flash programmer, plus a recovery plan for a non-booting flash image (JTAG load of the stock bitstream, then
  rewrite the flash). Not planned until a functional replacement design exists.
- Extending the stock design: needs the T15 netlist (now recovered, [netlist.md](../code/sdr/netlist.md); `hdl/sdr/` has the UART link in RTL); the device is nearly full (119/120 DSP48E1).

## Follow-ups

- Read the FPGA's package marking (owner, physical inspection of the SDR module).
- ~~T15: trace `UART_DBG_TX`, the UART5 pins and the clock input from the IOBs; confirm the fabric flash master
  (D00/FCS_B drivers, STARTUPE2 `USRCCLKO`).~~ Done by T15/T15e ([netlist.md](../code/sdr/netlist.md)).
- Propose to resources.md: 18 LVDS output pairs and 16 input pairs (per IOB tile), not about 9 each.
