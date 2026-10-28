# T15 — FPGA netlist recovery (SDR)

**Status:** in progress (T15a-T15d done, T15e receiver done) · **Depends on:** T13

## Goal
Turn the SDR bitstream (XC7A50T, `build/FT-710_SDR_V0104.bin`) into a gate-level netlist and identify its main blocks, so
the design's interfaces can be re-implemented or extended (see [custom firmware feasibility](../custom-firmware.md)).

## Deliverables
- A tool that converts the bitstream to FASM with prjxray `bit2fasm` (installed in T13 under `~/.local/share/ft710-tools/`),
  plus a FASM summary (feature counts per tile type). FASM output itself stays in `build/` (derived data; not committed).
- A routing walker that builds a cell-level netlist (LUTs with their INIT, FFs, CARRY4, DSP48E1, BRAM, IOB, MMCM) from the
  FASM PIP features, with a self-test on a small known design.
- `docs/code/sdr/netlist.md`: block recognition, starting with the UART link to MAIN (UART5) and the ADC → DDC → filter
  chain (DSP48 cascades, the BRAM tables from `bram-tables.md`), plus the scope/FFT data link to DISPLAY.

## Notes / hints
- Split into sub-tasks (T15a FASM, T15b netlist, T15c block recognition) before starting.
- Open tools for the netlist step on 7-series are research-grade; expect custom code.
- Never commit bitstream bytes or large derived dumps.

## Plan
Split into five sub-tasks (T15d and T15e added on the owner's request), done in order (each finished, documented and committed before the next):

| Sub-task | Deliverable | Status |
|---|---|---|
| [T15a](T15a-fpga-fasm.md) | `tools/xc7_fasm.py`: bitstream -> prjxray `.bits` (stdlib) -> FASM via prjxray's `FasmDisassembler` (venv); FASM summary per tile type; FASM section of `docs/code/sdr/netlist.md` | done |
| [T15b](T15b-fpga-netlist-cells.md) | `tools/xc7_netlist.py` (stdlib): FASM -> cells (LUT INIT, FF, CARRY4, DSP48E1, BRAM, IOB, MMCM, BUFG) + nets from active PIPs walked over `tileconn.json`; self-test on a hand-built FASM case | done |
| [T15c](T15c-fpga-blocks.md) | Block recognition in `docs/code/sdr/netlist.md`: clock domains, IOB groups, DSP48 cascades and BRAM<->DSP links (DDC/filter chain), UART5 and scope SPI candidates, TX path | done |
| [T15d](T15d-fpga-verilog.md) | `tools/xc7_netlist_verilog.py`: structural Verilog (UNISIM primitives with recovered parameters, ports named from package pins / J2002 signals) + XDC (LOC, IOSTANDARD) in `build/sdr/`; smoke test with an open tool (Yosys/Icarus/Verilator) against a UNISIM blackbox library; summary only in docs | done |
| [T15e](T15e-fpga-uart-rtl.md) | Behavioral RTL of the UART link to MAIN in `hdl/sdr/` (baud generator, framing, `r`/`w` command handling) + README + testbench comparing it against the structural slice | in progress (RX done) |

Approach:
1. No C++ build: prjxray's `bitread` is replaced by a stdlib writer of the same `bit_FFFFFFFF_WWW_BB` lines (frames from
   `tools/xc7_db.py`'s FAR walk). prjxray's own Python `FasmDisassembler` (+ `fasm`, `simplejson`, `intervaltree`,
   `pyyaml` in a venv under `~/.local/share/ft710-tools/venv`) turns that into FASM, so the feature decode is the
   reference implementation, not ours. Output: `build/sdr/FT-710_SDR_V0104.fasm` (gitignored).
2. The netlist tool reads FASM text only (stdlib). Nodes are found lazily: from each (tile, wire) used by an active PIP
   or a site pin, follow `tileconn.json` wire pairs to the other tiles of the node; nets are the union of nodes joined
   by active PIPs (and always-on pseudo-PIPs from `ppips_*.db`). Site pins come from `tile_type_*.json`.
3. Block recognition works on the net graph: fanout and driver/sink cell types, DSP PCOUT->PCIN/ACOUT->ACIN cascades,
   BRAM DO -> DSP A/B, MMCM -> BUFG -> clock domains, IOB -> ISERDES/IDELAY -> fabric.
4. Owner request (2026-10-27): the netlist is also written as Verilog (T15d), and the UART link gets hand-written
   behavioral RTL (T15e). Derived Verilog/XDC stays in `build/`; only tools, `hdl/sdr/` reconstruction and summaries are
   committed.
5. Limits: 4 worker processes, < 2.5 GB RAM, timeouts on every long command. Nothing derived is committed except
   summaries in docs.

## Findings
Page: [`docs/code/sdr/netlist.md`](../code/sdr/netlist.md). Tools: `tools/xc7_fasm.py`, `tools/xc7_netlist.py`,
`tools/xc7_blocks.py`, `tools/xc7_netlist_verilog.py` (all with `selftest`). RTL: [`hdl/sdr/`](../../hdl/sdr/README.md).
Derived files (FASM, netlist JSON, Verilog, XDC, slices) are in `build/sdr/` only.

- **FASM (T15a):** prjxray's own disassembler explains all but 407 of 2,360,912 set bits (0.017 %) once the frame ECC
  is set aside; 367k PIPs, 26,608 LUT INITs **[fact]**.
- **Netlist (T15b):** 63,648 cells, 127,648 nets, no multi-driver net; LUT/FF counts equal T13's **[fact]**. T13's DSP
  register reading was inverted (`Z<reg>` = register 0) **[fact]**.
- **Blocks (T15c):** one **125 MHz** fabric clock from an LVDS pair (the ADC clock); 14 LVDS DDR ADC data pairs captured
  by IDDR on a BUFIO; 17 LVDS DDR outputs (TX DAC?); a **QSPI master on the configuration-flash pins** (the FPGA
  rewrites its own flash); **two identical UARTs at 115,200 8N1** (M18/L18, V12/U12) with an ASCII line parser
  (`r`, `w`, undocumented `x`, hex, `,`, CR/LF/BS); two cascaded MMCMs giving ~28.17 MHz on pin P14 **[fact for wiring,
  inference for roles]**. Package CSG324 or FGG484 **[fact]**.
- **Verilog (T15d):** 63,474 UNISIM instances with recovered parameters + XDC; Yosys `hierarchy -check` clean; the UART
  receiver slice decodes real frames in Icarus **[fact]**.
- **RTL (T15e):** `hdl/sdr/uart_rx.v` matches the netlist cycle by cycle over 260k clocks **[fact]**.

## Follow-ups
- Which UART is MAIN's UART5 (the other is UART_DBG); the parser state machine, the `x` command and the read-reply
  format (T15e).
- DISPLAY scope SPI slave and the I2S ports among the remaining bank 14/15 pins; J2002-to-FPGA pin path.
- DSP OPMODE/ALUMODE polarity and `USE_MULT` (no segbits) before reading the DDC arithmetic.
- STARTUPE2 use (needed by the flash writer) is not decodable with prjxray-db (`CFG_CENTER_MID` has routing bits only).
- A full-design simulation needs a faster simulator (Verilator) than Icarus on the shared box.

## Proposed shared-file edits
For the parent to apply (this task does not edit shared files).

**docs/tasks/README.md** — add under the T15 row:
```
| T15a | [Bitstream to FASM (SDR)](T15a-fpga-fasm.md) | T13 | done |
| T15b | [FASM to cell-level netlist (SDR)](T15b-fpga-netlist-cells.md) | T15a | done |
| T15c | [Block recognition (SDR)](T15c-fpga-blocks.md) | T15b | done |
| T15d | [Structural Verilog netlist + smoke test (SDR)](T15d-fpga-verilog.md) | T15b | done |
| T15e | [Behavioral RTL of the UART link (SDR)](T15e-fpga-uart-rtl.md) | T15c T15d | in progress |
```

**docs/tooling.md** — append to the prjxray section:
> **T15 (2026-10-27).** prjxray-db sparse checkout extended with `git -C ~/.local/share/ft710-tools/prjxray-db
> sparse-checkout add '/artix7/mapping/'` (prjxray's `Database` reads `mapping/devices.yaml`). New venv
> `python3 -m venv ~/.local/share/ft710-tools/venv` (Python 3.11.2) + `pip install fasm simplejson intervaltree pyyaml`
> from PyPI: `fasm 0.0.2.post88` (pure-Python textX parser; the Antlr fast path is not built), `textX 4.4.0`,
> `Arpeggio 2.0.3`, `simplejson 4.2.0`, `intervaltree 3.2.1`, `sortedcontainers 2.4.0`, `PyYAML 6.0.3`. No sudo, nothing
> built. Used only by `tools/xc7_fasm.py fasm` (which re-runs itself under that venv). Remove:
> `rm -rf ~/.local/share/ft710-tools/venv`.
>
> **T15d (2026-10-28).** `persist-apt iverilog yosys` (the container's sanctioned Debian install, see the global
> CLAUDE.md): Debian bookworm **iverilog 11.0-1.1+b1** and **yosys 0.23-6** (+ dependencies such as xdot), recorded in
> `~/.config/claude-container/apt-packages.txt` so they survive rebuilds. Used for the T15d smoke test
> (`yosys -s ...` with `+/xilinx/cells_sim.v`, `cells_xtra.v`) and the T15d/T15e simulations (`iverilog -g2012`).

**docs/code/sdr/README.md** — add a row to the Pages table:
`| [netlist.md](netlist.md) | T15: FASM decode, cell/net netlist, recognized blocks (clocks, ADC capture, DSP chains, UART, scope SPI) |`
and add `tools/xc7_fasm.py`, `tools/xc7_netlist.py`, `tools/xc7_blocks.py`, `tools/xc7_netlist_verilog.py` to the Tools
line. Key findings to add: "One 125 MHz fabric clock from the ADC; two identical 115,200-baud UARTs with an ASCII
command parser (M18/L18, V12/U12); a QSPI master on the configuration-flash pins; 14 LVDS DDR ADC pairs, 17 LVDS DDR
outputs ([netlist.md](netlist.md))". In the block diagram, "control UART + debug UART" can drop the [inference]
qualifier.

**AGENTS.md repo layout** (owner's choice of Verilog): add `hdl/<image>/  hand-written HDL reconstructions (T15e)`.
