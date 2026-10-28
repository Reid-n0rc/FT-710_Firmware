# T15e — Behavioral RTL of the UART link to MAIN (SDR)

**Status:** in progress (receiver done and verified; parser/handler open) · **Depends on:** T15c T15d · **Parent:** [T15](T15-fpga-netlist.md)

## Goal
Once T15c locates the UART5 block: a readable hand-written Verilog module (baud generator, framing, the
command/response handling) that matches the recovered netlist, with a testbench comparing it against the
structural slice. In `hdl/sdr/` with a short README.

## Plan
1. Read the receiver and transmitter from the equations (`tools/xc7_blocks.py logic`), write `ft710_uart_rx` /
   `ft710_uart_tx` with the same counters and register structure.
2. Cut the receiver slice from the netlist (`xc7_netlist_verilog.py slice`) and compare it with the RTL in Icarus,
   clock by clock.
3. Character classes from exhaustive LUT evaluation; then the parser state machine and the reply path.

## Findings
- [`hdl/sdr/`](../../hdl/sdr/README.md): `uart_rx.v`, `uart_tx.v`, `uart_charclass.v`, `tb_uart_rx.v`, `tb_uart_tx.v`.
- **`ft710_uart_rx` matches the netlist slice of UART A cycle by cycle**: 0 mismatches in 260,417 clocks, 23 bytes
  including MAIN-style `r`/`w` frames and senders 2 % slow/fast (`tb_uart_rx.v -DSTRUCT`) **[fact]**.
- `ft710_uart_tx`: same 1,086-clock bit timer, shift strobe at count 32, start on the rising edge of the request
  (two-flip-flop synchronizer), retimed output; loopback test passes, 8.688 us bits **[fact for the structure,
  inference for the first-edge latency]**.
- Character classes: hex digits, `r`/`w`/`x`, `,`/space, CR, LF, BS **[fact]**.
- The receiver samples the raw pad for its shift register and uses a separate two-flip-flop synchronizer only for the
  edge detector; the strobe is two clocks long because the shift register is cleared one clock after the byte is
  latched **[fact]** (worth knowing if this RTL is reused).

## Follow-ups
- Parser state machine and reply generation (the `x` command, the 7-byte read reply format, ACK/NAK), then the
  register bank interface; compare against a larger netlist slice once its boundary inputs are understood.
- Confirm that UART B (V12/U12, line buffer) is MAIN's UART5 (T15c inference); the receiver RTL fits both instances.
