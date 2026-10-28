# T15e — Behavioral RTL of the UART link to MAIN (SDR)

**Status:** in progress (receiver done and verified; parser/handler being reconstructed) · **Depends on:** T15c T15d · **Parent:** [T15](T15-fpga-netlist.md)

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
4. (2026-10-28, second session) Install Verilator (`persist-apt verilator`) and run the **whole** structural netlist
   (`build/sdr/ft710_sdr.v`) with it: MAIN-style `r`/`w`/`x` frames on both UARTs, record the replies. That gives
   the ground truth behaviour to reconstruct against.
5. Cut the parser slice (forward cone from each UART's byte register/strobe to its transmitter and to the register
   bus) with `xc7_netlist_verilog.py slice`; read its equations (`xc7_blocks.py logic`) and write `uart_cmd.v`
   (line parser, checksum, reply formatter, register-bus port).
6. Equivalence: drive RTL and netlist slice with the same random + directed byte streams (Verilator for the slice,
   Icarus for small modules), compare outputs every clock.
7. Pick MAIN's UART5 from J2002 pin mapping (`docs/code/sdr/interfaces.md`) and behaviour; look for scope SPI/I2S
   pins if time allows. Update README, netlist.md, task files.

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
