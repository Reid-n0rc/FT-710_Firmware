# T15d — Structural Verilog netlist + smoke test (SDR)

**Status:** done · **Depends on:** T15b · **Parent:** [T15](T15-fpga-netlist.md)

## Goal
`tools/xc7_netlist_verilog.py`: one Verilog module instantiating UNISIM primitives with their recovered parameters
(`LUT1..LUT6 #(.INIT)`, `FDRE/FDSE/FDCE/FDPE` with INIT/IS_*_INVERTED, `CARRY4`, `DSP48E1` with all attributes,
`RAMB18E1/RAMB36E1` with INIT_xx/INITP_xx and widths, `MMCME2_ADV`, `BUFG/BUFGCTRL`, `IBUFDS/OBUFDS/IBUF/OBUF/IOBUF`
with IOSTANDARD, `STARTUPE2` if present), top-level ports named from package pins (and J2002 signal names from
`docs/code/sdr/interfaces.md` where known), plus an XDC with pin LOCs and IOSTANDARDs. Output in `build/sdr/`
(never committed); commit the tool and a summary (cell counts, port list). Smoke test: parse/elaborate with an
open tool (Yosys `read_verilog` + `hierarchy` against a UNISIM blackbox library, or Icarus/Verilator lint);
install under `~/.local` and record it. If feasible, a tiny simulation of a recognized block.

## Plan
Writer over the T15b JSON (stdlib): one instance per cell, buses as concatenations, IOB pairs as IBUFDS/OBUF(T)DS,
`slice` command for sub-netlists with driver-named ports, `prims`/`simprims` for primitives Yosys lacks or only
declares. Smoke test with Yosys 0.23 `hierarchy -check`; simulation with Icarus 11.

## Findings
Documented in [`docs/code/sdr/netlist.md` section 4](../code/sdr/netlist.md#4-structural-verilog-smoke-test-and-simulation-t15d).
- `build/sdr/ft710_sdr.v`: 116 ports, 63,474 UNISIM instances (counts in netlist.md 4); `build/sdr/ft710_sdr.xdc`:
  PACKAGE_PIN + IOSTANDARD for all ports (CSG324 names) **[fact]**.
- Ports named from T15c: `adc_clk_p/n`, `adc_dco_p/n`, `uart_a_rx/tx`, `uart_b_rx/tx`, `flash_cs_n`, `flash_d0..3`,
  `dsp_clk`; the rest `io_<pin>` (`_p`/`_n` for LVDS pairs).
- **Yosys `hierarchy -check` passes with no errors** (9 s, 1.4 GB); Icarus compiles the full netlist **[fact]**.
- **The UART A receiver slice (76 cells) decodes 115,200-baud frames exactly in simulation** **[fact]**, which validates
  the whole bitstream-to-Verilog chain on a real block.
- No STARTUPE2/ICAP/BSCAN instance is emitted: prjxray decodes only routing in `CFG_CENTER_MID`, so whether
  STARTUPE2 (flash clock `USRCCLKO`) is used stays open, although the QSPI master in fabric (T15c) needs it.
- A full-design Icarus run compiles (195 MB image) but simulates under 5 us per minute here; a UART exchange would
  take over ten hours, so it was stopped **[fact]**.

Installs (owner-authorized community tooling; see T15 "Proposed shared-file edits"): `persist-apt iverilog yosys`
(Debian bookworm: iverilog 11.0-1.1+b1, yosys 0.23-6, plus their dependencies), recorded by the container in
`~/.config/claude-container/apt-packages.txt`.

## Follow-ups
- Full-design simulation: try Verilator (needs the DSP/BRAM models in a Verilator-friendly form).
- RAMB36 pairs are written as two RAMB18E1 halves; write true RAMB36E1 instances where T13's pairing is certain.
- DSP `USE_MULT` and the OPMODE/ALUMODE pin polarity (netlist.md 3.5) before trusting DSP arithmetic in simulation.
