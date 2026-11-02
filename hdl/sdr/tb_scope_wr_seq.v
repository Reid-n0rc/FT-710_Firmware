// Testbench (T24 SDR round 3): ft710_scope_wr_seq (sequencer of the scope RAM writer; netlist.md 5.6).
//
// With STRUCT it instantiates `ft710_slice` written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice scope_wr_seq build/sdr/sim/scope_wr_seq.v
// (seeds: the 16 state flip-flops; depth 1; stops: the condition cells SLICE_X33Y128/A,C,DLUT, X7Y117/CARRY4,
// X8Y121/CARRY4 and other-ffs, so i0, i1 and the five conditions are slice inputs). The conditions get random bits on
// every clock and i0 is set on one clock in 16; the rate of i1 (which resets the state) alternates every 200,000
// clocks between one clock in 64 (short passes through the loop 0x0070 .. 0x00B2) and one in 2^20 (long runs that
// count through the upper states and their carries). The 16 other inputs (other halves of shared LUT6_2s) get random
// bits. All 16 flip-flops are compared on every clock, and the testbench counts how many distinct states were seen.
// Without STRUCT: the RTL alone (the state count only). Port list: tb_scope_wr_seq_ports.vh (generated in round 3;
// cell names only).
`timescale 1ns/1ps
`default_nettype none
module tb_scope_wr_seq;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg        i0 = 1'b0, i1 = 1'b0, eq = 0, cr = 0, ca = 0, cc = 0, cd = 0;
  reg [15:0] junk = 0;
  wire [15:0] s;
  ft710_scope_wr_seq dut (.clk(clk), .i0(i0), .i1(i1), .eq(eq), .cr(cr), .ca(ca), .cc(cc), .cd(cd), .s(s));
  integer mism = 0, cyc = 0, seed = 91, nstates = 0;
  reg seen [0:65535];
  integer k;
  initial for (k = 0; k < 65536; k = k + 1) seen[k] = 1'b0;
`ifndef CYCLES
`define CYCLES 2000000
`endif
`ifdef STRUCT
  wire [15:0] ns;
  ft710_slice sl (
`include "tb_scope_wr_seq_ports.vh"
  );
`endif
  always @(negedge clk) begin
    {eq, cr, ca, cc, cd} <= $random(seed);
    junk <= $random(seed);
    i0 <= ($random(seed) & 15) == 0;
    if ((cyc / 200000) % 2 == 0) i1 <= (cyc < 4) || (($random(seed) & 63) == 0);
    else i1 <= ($random(seed) & 20'hFFFFF) == 0;
  end
  always @(posedge clk) begin
    cyc <= cyc + 1;
    #1;
    if (!seen[s]) begin seen[s] = 1'b1; nstates = nstates + 1; end
`ifdef STRUCT
    if (ns !== s) begin
      mism = mism + 1;
      if (mism < 10) $display("SLICE cyc %0d: s %h slice %h", cyc, s, ns);
    end
`endif
    if (cyc == `CYCLES) begin
      $display("%0d clocks, %0d distinct states: %0d mismatching clocks against the slice%s", cyc, nstates, mism,
`ifdef STRUCT
               "");
`else
               " (no slice)");
`endif
      $display("%0s", mism == 0 ? "PASS" : "FAIL");
      $finish;
    end
  end
endmodule
`default_nettype wire
