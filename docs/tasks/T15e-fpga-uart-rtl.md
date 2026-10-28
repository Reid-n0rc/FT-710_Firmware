# T15e — Behavioral RTL of the UART link to MAIN (SDR)

**Status:** done · **Depends on:** T15c T15d · **Parent:** [T15](T15-fpga-netlist.md)

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
- [`hdl/sdr/`](../../hdl/sdr/README.md): `uart_rx.v`, `uart_link.v`, `uart_tx.v`, `uart_charclass.v`, testbenches,
  and `sim/` (Verilator primitive models, whole-netlist harness, co-simulation top and scripts). Tools:
  `tools/sdr_uart_sim.py`, `tools/xc7_probe_netlist.py`, `tools/sdr_cosim_check.py`; `xc7_netlist_verilog.py slice`
  got `--stop`. Page: [netlist.md section 5](../code/sdr/netlist.md#5-whole-design-simulation-and-the-uart-protocols-t15e).
- **Whole netlist runs in Verilator 5.006** (63k cells, ~2.5 min build with `-j 16`, ~15,000 clocks/s). Needed: own
  primitive models (Yosys' CARRY4 crashes Verilator 5.006) and a BUFGCTRL model that passes I0 (unrouted S1/I1 read
  as 1) **[fact]**.
- **End-to-end MAIN exchange:** `r000032` CR on UART B gives `r010437` (register 0 = 0x0104 = V01-04) **[fact]**.
- **UART B (V12/U12) is MAIN's UART5**, UART A (M18/L18) the debug console with prompt `[IF]>` **[fact, behaviour;
  the module-side pin path is still not in the service manual]**.
- **Link protocol** (UART B): an 11-character window, not a state machine; `r`aaaa`ss` -> `r`vvvv`ss` (7 bytes),
  `w`aaaavvvv`ss` -> ACK 0x06 (**1 byte**), anything else -> `?`. Checksum digits must be upper case; address/value
  digits may be lower case; junk in front is ignored; **CR alone repeats the previous command**. Exact reply
  latencies (read +74, ACK +69, `?` +37..+51 by how far the check got) **[fact]**.
- **`ft710_uart_link` (RTL) equals the netlist cycle by cycle on the TX pin**: whole netlist + RTL co-simulated, the
  RTL fed from the netlist's read-data bus; 4 directed runs (24 lines) and 33 random runs (366 lines: reads, writes,
  corrupted/lower-case sums, wrong lengths, junk, split lines), about 160 M clocks, **0 mismatching clocks**
  **[fact]**. Earlier rounds found and fixed: ACK latency, NAK latency classes, the empty-line repeat.
- **`x`**: in both engines' character tables, but no frame or console form tried (0-10 hex digits, with/without
  sum, `X`, `0x` prefixes, after the 0x37 unlock) does anything but `?` / `Err` **[fact for the tried forms]**; with
  the other inputs at 0 it has no reachable function **[inference]**.
- **Console** (UART A): echo with `?` for unknown characters, `r AAAA` -> `VVVV `, `w AAAA VVVV` / `w AAAA,VVVV`
  silent, strict four-digit operands, `Err` otherwise; LF echoed only; `#` echoes 0x06 **[fact]**. Shares the register
  bank with the link **[fact for the values, inference for the shared bus FFs]**.
- Register values after reset (inputs 0): 0x00 0104 (read-only), 0x01 000F, 0x03 8800, 0x04 8810, 0x06 020A,
  0x15 1FFF, 0x30 0023, unmapped 0xCCCC or 0 **[fact]**.
- Receiver, from the first session: `ft710_uart_rx` matches its netlist slice cycle by cycle (260,417 clocks) **[fact]**.

## Follow-ups
- RTL for the debug console (UART A): behaviour is documented (netlist.md 5.3); its echo/BS quirk and `#` -> 0x06
  are open.
- The RTL's bus strobes are not compared with the netlist (the write path is spread over the shared bank; checked by
  read-back). A CR during a running reply restarts it in the netlist; not modelled.
- `x` may be gated by an input pin (all inputs were 0): drive the remaining bank 14/15 inputs one at a time in the
  whole-design model.
- DISPLAY scope SPI / I2S pins among the remaining bank 14/15 pins (not done; the whole-design model can now probe
  them), and the J2002 pin path for the UARTs.

## Tooling installed
`persist-apt verilator` (2026-10-28): Debian bookworm **verilator 5.006-3** (+ dependencies), recorded in
`~/.config/claude-container/apt-packages.txt`.

## Proposed shared-file edits
For the parent to apply.

**docs/tasks/README.md**: T15e row status `done`; T15 row status `done`.

**docs/tooling.md** (T15 section): "T15e (2026-10-28): `persist-apt verilator` -> Debian bookworm verilator 5.006-3,
used by `hdl/sdr/sim/build_full.sh` for the whole-netlist simulation (`-j 16`, ~2.5 min build)."

**docs/code/main/sdr-link.md**, Reply table: the FPGA answers a write with **one byte** (ACK 0x06), not 7; a frame it
rejects gets one byte `?` (0x3F). MAIN's 7-byte receive therefore completes only for reads; for writes
`sdr_poll_reply` must be reading byte 0 before the receive count is reached (worth a look in the SCI5 code)
**[fact for the FPGA side, from the T15e netlist simulation]**. Register 0 reads 0x0104 **[fact]**, register 1 reads
0x000F after reset.

**docs/code/sdr/interfaces.md**, open question 5: "UART B (V12/U12) is UART5, UART A (M18/L18) is UART_DBG
(prompt `[IF]>`), shown by simulating the netlist (netlist.md section 5)".

**docs/code/sdr/README.md**: add `hdl/sdr/sim/` and `tools/sdr_uart_sim.py`, `tools/xc7_probe_netlist.py`,
`tools/sdr_cosim_check.py` to the tools line; key finding "the whole recovered netlist runs in Verilator; UART B is
MAIN's link (`r`/`w` window protocol), UART A a debug console `[IF]>`".
