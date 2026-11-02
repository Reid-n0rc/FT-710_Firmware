// Testbench (T24 SDR round 3): ft710_rx_window_sum (second-stage window sum of the RX decimator; netlist.md 3.9).
//
// Without STRUCT: the RTL alone against an integer reference. With STRUCT it also instantiates `ft710_slice` written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice rx_window_sum build/sdr/sim/rx_window_sum.v
// (seeds: the 73 integrator, 2 x 73 snapshot and 47 difference flip-flops; depth 1; stops: the four control LUTs
// SLICE_X13Y13/CLUT, X13Y13/DLUT, X30Y3/DLUT, X31Y6/BLUT and other-ffs, so the control signals, the 34 operand pipeline
// flip-flops, the DSP48_X1Y3 P pins and the clear flip-flop are slice inputs). x gets a new random value on every
// clock (bits 72..40 all equal on half of the clocks), the controls are random (r rare, ce half of the
// clocks, cea and ceb one clock in eight, clr rare), and the 13 other inputs (other halves of shared LUT6_2s) get
// random bits. All 266 flip-flops are compared on every clock. Port list: tb_rx_window_sum_ports.vh (generated in
// round 3; cell names only).
`timescale 1ns/1ps
`default_nettype none
module tb_rx_window_sum;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg  [72:0] x = 0;
  reg         r = 1'b1, ce = 1'b0, cea = 1'b0, ceb = 1'b0, clr = 1'b1;
  reg  [12:0] junk = 0;
  wire [72:0] acc, sa, sb;
  wire [46:0] d;
  ft710_rx_window_sum dut (.clk(clk), .x(x), .r(r), .ce(ce), .cea(cea), .ceb(ceb), .clr(clr), .acc(acc), .sa(sa),
                           .sb(sb), .d(d));

  integer errors = 0, mism = 0, cyc = 0, seed = 61;
`ifndef CYCLES
`define CYCLES 1000000
`endif
  // reference
  reg [72:0] ra = 0, rsa = 0, rsb = 0;
  reg [46:0] rd = 0;
  reg [72:0] t;
  always @(posedge clk) begin
    if (r) ra <= 0; else if (ce) ra <= ra + x;
    if (cea) rsa <= x;
    if (ceb) rsb <= x;
    t = rsa - rsb;
    rd <= clr ? 0 : t[71:25];
  end

`ifdef STRUCT
  wire [72:0] nacc, nsa, nsb;
  wire [46:0] ndif;
  ft710_slice sl (
`include "tb_rx_window_sum_ports.vh"
  );
`endif

  always @(negedge clk) begin
    x <= {$random(seed), $random(seed), $random(seed)};
    if ($random(seed) & 1) x[72:40] <= {33{x[39]}};
    junk <= $random(seed);
    r <= (cyc < 2) || (($random(seed) & 255) == 0);
    ce <= $random(seed) & 1;
    cea <= ($random(seed) & 7) == 0;
    ceb <= ($random(seed) & 7) == 0;
    clr <= (cyc < 2) || (($random(seed) & 1023) == 0);
  end
  always @(posedge clk) begin
    cyc <= cyc + 1;
    #1;
    if (cyc > 2) begin
      if (acc !== ra || sa !== rsa || sb !== rsb || d !== rd) begin
        errors = errors + 1;
        if (errors < 10) $display("RTL  cyc %0d: acc %h exp %h  d %h exp %h", cyc, acc, ra, d, rd);
      end
`ifdef STRUCT
      if (nacc !== acc || nsa !== sa || nsb !== sb || ndif !== d) begin
        mism = mism + 1;
        if (mism < 10) $display("SLICE cyc %0d: acc %h/%h sa %h/%h sb %h/%h d %h/%h", cyc, acc, nacc, sa, nsa, sb, nsb,
                                d, ndif);
      end
`endif
    end
    if (cyc == `CYCLES) begin
      $display("%0d clocks: %0d reference errors, %0d mismatching clocks against the slice%s", cyc, errors, mism,
`ifdef STRUCT
               "");
`else
               " (no slice)");
`endif
      if (errors == 0 && mism == 0) $display("PASS"); else $display("FAIL");
      $finish;
    end
  end
endmodule
`default_nettype wire
