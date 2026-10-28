# T15d — Structural Verilog netlist + smoke test (SDR)

**Status:** todo · **Depends on:** T15b · **Parent:** [T15](T15-fpga-netlist.md)

## Goal
`tools/xc7_netlist_verilog.py`: one Verilog module instantiating UNISIM primitives with their recovered parameters (`LUT1..LUT6 #(.INIT)`, `FDRE/FDSE/FDCE/FDPE` with INIT/IS_*_INVERTED, `CARRY4`, `DSP48E1` with all attributes, `RAMB18E1/RAMB36E1` with INIT_xx/INITP_xx and widths, `MMCME2_ADV`, `BUFG/BUFGCTRL`, `IBUFDS/OBUFDS/IBUF/OBUF/IOBUF` with IOSTANDARD, `STARTUPE2` if present), top-level ports named from package pins (and J2002 signal names from `docs/code/sdr/interfaces.md` where known), plus an XDC with pin LOCs and IOSTANDARDs. Output in `build/sdr/` (never committed); commit the tool and a summary (cell counts, port list). Smoke test: parse/elaborate with an open tool (Yosys `read_verilog` + `hierarchy` against a UNISIM blackbox library, or Icarus/Verilator lint); install under `~/.local` and record it. If feasible, a tiny simulation of a recognized block.

## Plan
See the parent [T15 plan](T15-fpga-netlist.md#plan).

## Findings
_(fill in as you go)_

## Follow-ups
