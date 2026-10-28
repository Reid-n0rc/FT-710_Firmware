# T15 — FPGA netlist recovery (SDR)

**Status:** in progress · **Depends on:** T13

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
| [T15c](T15c-fpga-blocks.md) | Block recognition in `docs/code/sdr/netlist.md`: clock domains, IOB groups, DSP48 cascades and BRAM<->DSP links (DDC/filter chain), UART5 and scope SPI candidates, TX path | todo |
| [T15d](T15d-fpga-verilog.md) | `tools/xc7_netlist_verilog.py`: structural Verilog (UNISIM primitives with recovered parameters, ports named from package pins / J2002 signals) + XDC (LOC, IOSTANDARD) in `build/sdr/`; smoke test with an open tool (Yosys/Icarus/Verilator) against a UNISIM blackbox library; summary only in docs | todo |
| [T15e](T15e-fpga-uart-rtl.md) | Behavioral RTL of the UART link to MAIN in `hdl/sdr/` (baud generator, framing, `r`/`w` command handling) + README + testbench comparing it against the structural slice | todo |

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
_(fill in as you go)_

## Follow-ups

## Proposed shared-file edits
For the parent to apply (this task does not edit shared files).

**docs/tasks/README.md** — add under the T15 row:
```
| T15a | [Bitstream to FASM (SDR)](T15a-fpga-fasm.md) | T13 | done |
| T15b | [FASM to cell-level netlist (SDR)](T15b-fpga-netlist-cells.md) | T15a | done |
| T15c | [Block recognition (SDR)](T15c-fpga-blocks.md) | T15b | todo |
| T15d | [Structural Verilog netlist + smoke test (SDR)](T15d-fpga-verilog.md) | T15b | todo |
| T15e | [Behavioral RTL of the UART link (SDR)](T15e-fpga-uart-rtl.md) | T15c T15d | todo |
```

**docs/tooling.md** — append to the prjxray section:
> **T15 (2026-10-27).** prjxray-db sparse checkout extended with `git -C ~/.local/share/ft710-tools/prjxray-db
> sparse-checkout add '/artix7/mapping/'` (prjxray's `Database` reads `mapping/devices.yaml`). New venv
> `python3 -m venv ~/.local/share/ft710-tools/venv` (Python 3.11.2) + `pip install fasm simplejson intervaltree pyyaml`
> from PyPI: `fasm 0.0.2.post88` (pure-Python textX parser; the Antlr fast path is not built), `textX 4.4.0`,
> `Arpeggio 2.0.3`, `simplejson 4.2.0`, `intervaltree 3.2.1`, `sortedcontainers 2.4.0`, `PyYAML 6.0.3`. No sudo, nothing
> built. Used only by `tools/xc7_fasm.py fasm` (which re-runs itself under that venv). Remove:
> `rm -rf ~/.local/share/ft710-tools/venv`.

**docs/code/sdr/README.md** — add a row to the Pages table:
`| [netlist.md](netlist.md) | T15: FASM decode, cell/net netlist, recognized blocks (clocks, ADC capture, DSP chains, UART, scope SPI) |`
and add `tools/xc7_fasm.py` to the Tools line.
