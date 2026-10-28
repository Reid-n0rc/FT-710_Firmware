# SDR FPGA resource picture (T13)

Coarse placement-level view of the XC7A50T design, from the configuration bits matched against prjxray-db segbits.
Routing is not decoded. Commands:

```sh
python3 -I tools/xc7_db.py build/FT-710_SDR_V0104.bin usage    # tiles with any bit set, per tile type
python3 -I tools/xc7_db.py build/FT-710_SDR_V0104.bin sites    # LUT/FF/LUTRAM/CARRY4/DSP48 counts, special tiles
python3 -I tools/xc7_db.py build/FT-710_SDR_V0104.bin bramcfg  # block RAM modes (see bram-tables.md)
python3 -I tools/xc7_db.py build/FT-710_SDR_V0104.bin config CMT_TOP_R_LOWER_B   # MMCM features
```

## Logic and arithmetic

| Resource | Used | Device | Share | How counted | Tag |
|---|---|---|---|---|---|
| LUT6 with non-zero INIT | 26,608 | 32,600 | 82 % | `xLUT.INIT[k]` bits set | [fact] |
| ...of which in SLICEM | 7,530 | | | | [fact] |
| LUT as distributed RAM | 336 | | | `xLUT.RAM` | [fact] |
| LUT as shift register (SRL) | 221 | | | `xLUT.SRL` | [fact] |
| Slices with at least one LUT | 7,293 | 8,150 | 89 % | | [fact] |
| Flip-flops (FF data mux set) | 31,384 | 65,200 | 48 % | `xFFMUX.*` with a positive bit | [inference: a mux bit set means the FF is used] |
| CARRY4 (PRECYINIT set) | 3,398 | 8,150 | 42 % | lower bound, chains in the middle of a column may set no PRECYINIT bit | [inference] |
| **DSP48E1** | **119** | 120 | 99 % | any bit of the site's own segbits | [fact] |
| Block RAM | 70 of 75 RAMB36 sites | 75 | 93 % | IN_USE on a half | [fact] |

The design nearly fills the device: almost every CLB column has used tiles (33 CLB grid columns), all but one DSP48E1
are configured, and 70 BRAM sites are in use **[fact]**.

**DSP48E1 options [fact for the counts, inference for the meaning].** In all 119 used DSPs the "Z" (inverted) bits for
`MREG`, `PREG`, `CREG`, `OPMODEREG` are clear, i.e. the multiplier, output, C and OPMODE registers are enabled
(fully pipelined, as Xilinx FIR/DDS/CMult IP generates). `ZAREG_2_ACASCREG_1` and `ZBREG_2_BCASCREG_1` are set in all
119, and `AREG_0` in 9. No DSP uses the pre-adder (`USE_DPORT`) or SIMD mode. 119 fully pipelined multipliers plus
the coefficient and phase tables in [bram-tables.md](bram-tables.md) point to a **multi-channel DDC/filter chain and
an FFT/scope engine** in fabric **[inference]**.

## Clocking

| Item | Finding | Tag |
|---|---|---|
| MMCME2_ADV | **2 in use**: `CMT_TOP_R_LOWER_B_X8Y9` (bottom region) and `CMT_TOP_R_LOWER_B_X8Y113` (top region), both on the left CMT column | [fact] |
| MMCM @X8Y9 | DIVCLK 5 (high 2 / low 3, edge), CLKFBOUT 34 (17/17), CLKOUT0 51 + fractional 1/8 (26/25, FRAC_EN), CLKOUT1-6 counters bypassed (NO_COUNT) | [fact for fields], divide values [inference, XAPP888 encoding] |
| MMCM @X8Y113 | DIVCLK 5, CLKFBOUT 36 (18/18), CLKOUT0 4 + fractional 2/8 (FRAC_EN), CLKOUT1-6 bypassed | as above |
| If the MMCM input is the 125 MHz FPGA clock (p6) | X8Y9: VCO 850 MHz, CLKOUT0 about 16.63 MHz; X8Y113: VCO 900 MHz, CLKOUT0 about 211.8 MHz. Both VCOs are inside the 600-1200 MHz range | [guess: input frequency not in the bitstream] |
| PLLE2 | no `IN_USE` feature matched in the CMT upper tiles | [fact] |
| BUFG / HROW | both BUFG tiles and all three HROW tiles carry routing bits | [fact] |

Service manual block diagram: "ADC/FPGA, Operating clock 125MHz, Divide 250MHz by 2" (p6, see
[`docs/hardware.md`](../../hardware.md)). That suggests a 250 MHz sample clock and 125 MHz fabric clock
**[inference]**. A fractional CLKOUT0 near 16.6 MHz could be an audio/I2S or DSP_CLK source for the RT685 (J2002 pin 22)
**[guess]**.

## I/O

Counted from `LIOB33`/`RIOB33` features (`config LIOB33 RIOB33`); a site is used when it has an input-buffer
(`.IN`/`IN_ONLY`) or a drive-strength feature **[fact for features, inference for "used"]**:

| Kind | IOB sites |
|---|---|
| differential input (`LVDS_25 ... IN_DIFF`) | 18 |
| differential output (`LVDS_25.OUT`) | 18 |
| single-ended input | 37 |
| single-ended output | 24 |
| bidirectional | 5 |
| total, left / right banks | 46 / 56 |

18 differential-input sites (counted per P/N site) are about **9 LVDS pairs**, the usual shape of a DDR LVDS ADC
interface (data pairs plus a clock pair), and 18 differential-output sites about 9 LVDS output pairs, which fits a
high-speed **TX DAC** **[inference]**. The single-ended I/O covers the J2002 board signals (I2S, SPI, UART, control)
and the QSPI config flash **[inference]**. The package, so the pin-to-ball mapping, is unknown.

## Special blocks

| Tile | Set bits | Reading |
|---|---|---|
| `PCIE_BOT_X71Y115` | 11,970 | Vivado writes default attributes into unused PCIe blocks; no PCIe interface is expected on this module [inference] |
| `GTP_COMMON` / `GTP_CHANNEL_0..3` | 778 / 286, 170, 106, 52 | same: default attributes, no serial transceiver link seen elsewhere [inference] |
| `MONITOR_BOT` (XADC) | 2,113 | XADC defaults or a used XADC; not decoded (no segbits in prjxray-db) |
| `CFG_CENTER_MID` (STARTUPE2, ICAP, BSCAN, USR_ACCESS) | 2,414 | only routing bits matched; whether STARTUPE2 (user access to the config-flash clock) is used is unknown |
