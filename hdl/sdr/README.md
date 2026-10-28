# hdl/sdr — reconstructed HDL for the FT-710 SDR FPGA (T15e)

Hand-written Verilog that re-implements interfaces of the FT-710 SDR module's XC7A50T design, the owner's own
reconstruction from the netlist recovered in T15 ([docs/code/sdr/netlist.md](../../docs/code/sdr/netlist.md)). It
contains no bitstream data. The recovered structural netlist itself is derived data and stays in `build/` (never
committed).

| File | What | Status |
|---|---|---|
| `uart_rx.v` | `ft710_uart_rx`: 115,200 baud 8N1 receiver at 125 MHz (bit timer 1,086, sample at 542, 10-stage shift register, byte + strobe) | **matches the netlist cycle by cycle** (`tb_uart_rx.v -DSTRUCT`) |
| `uart_tx.v` | `ft710_uart_tx`: transmitter with the same bit timer, shift strobe at count 32, retimed output | bit time and framing as in the netlist; first-edge latency not checked |
| `uart_charclass.v` | `ft710_uart_charclass`: character classes of the command parser (hex digits, `r`/`w`/`x`, `,`/space, CR/LF/BS) | sets taken from the netlist LUTs; the LUT-level split is not reproduced |
| `tb_uart_rx.v` | RX testbench: MAIN-style frames, edge bytes, +/-2 % baud error; with `-DSTRUCT` also compares against the netlist slice | PASS, 0 mismatches in 260,417 clocks |
| `tb_uart_tx.v` | TX looped back into RX | PASS |

Not reconstructed yet: the line parser/state machine behind the character classes and the register bank it reads
and writes (MAIN's frames are `r`+4 hex+2 hex sum+CR and `w`+8 hex+2 hex sum+CR, see netlist.md 3.4).

## Running the tests

Icarus Verilog 11 and Yosys 0.23 (Debian packages, see the T15 task file). Behavioural only:

```sh
iverilog -g2012 -o /tmp/rx.vvp hdl/sdr/tb_uart_rx.v hdl/sdr/uart_rx.v && vvp -n /tmp/rx.vvp
iverilog -g2012 -o /tmp/tx.vvp hdl/sdr/tb_uart_tx.v hdl/sdr/uart_tx.v hdl/sdr/uart_rx.v && vvp -n /tmp/tx.vvp
```

Against the recovered netlist (needs `build/sdr/netlist.json` from T15b):

```sh
python3 -I tools/xc7_netlist_verilog.py slice build/sdr/netlist.json build/sdr/sim/uart_a_rx.v \
  --seeds SLICE_X1Y92/AFF,SLICE_X1Y93/AFF,SLICE_X1Y93/B5FF,SLICE_X1Y93/BFF,SLICE_X1Y93/CFF,SLICE_X1Y93/DFF,SLICE_X2Y93/AFF,SLICE_X2Y93/BFF,SLICE_X2Y93/CFF \
  --depth 4
iverilog -g2012 -DSTRUCT -o /tmp/rxc.vvp hdl/sdr/tb_uart_rx.v hdl/sdr/uart_rx.v build/sdr/sim/uart_a_rx.v \
  /usr/share/yosys/xilinx/cells_sim.v && vvp -n /tmp/rxc.vvp
```

The slice's ports and nets are named after their driving cell pin (`i_IOB_X0Y41_I`, `w_SLICE_X10Y76_BFF_Q`), so the
testbench does not depend on the net numbering of a particular netlist build.
