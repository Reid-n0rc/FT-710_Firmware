// Testbench (T24 SDR round 3): ft710_rx_out_mac (RX output multiply-accumulate; netlist.md 3.10).
//
// Without STRUCT: the RTL alone against an integer reference (the sum of the two phase products since the strobe).
// With STRUCT it also instantiates `ft710_slice` written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice rx_out_mac build/sdr/sim/rx_out_mac.v
// (seeds: the 55 accumulator, 17 pipeline and 12 counter flip-flops; depth 1; stop other-ffs, so the strobe flip-flop
// and the DSP48_X0Y11/X0Y12 P pins are slice inputs). The P pins get new random values on every clock, the strobe
// comes at random (on average every 40 clocks, so the counter passes 24 and 32 in some periods and not in others), and
// the 8 other inputs (other halves of shared LUT6_2s) get random bits. All 84 flip-flops are compared on every clock.
// Port list: tb_rx_out_mac_ports.vh (generated in round 3; cell names only).
`timescale 1ns/1ps
`default_nettype none
module tb_rx_out_mac;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg         stb = 1'b1;
  reg  [16:0] p11 = 0;
  reg  [37:0] p12 = 0;
  reg  [7:0]  junk = 0;
  wire [11:0] cnt;
  wire [16:0] p_lo;
  wire [54:0] acc;
  ft710_rx_out_mac dut (.clk(clk), .stb(stb), .p11(p11), .p12(p12), .cnt(cnt), .p_lo(p_lo), .acc(acc));

  integer errors = 0, mism = 0, cyc = 0, seed = 51, nload = 0;
`ifndef CYCLES
`define CYCLES 1000000
`endif
  // reference: phase counter and accumulator
  reg [11:0] rc = 0;
  reg [16:0] rl = 0;
  reg [54:0] ra = 0;
  always @(posedge clk) begin
    rl <= p11;
    rc <= stb ? 0 : rc + 1;
    if (rc == 24) begin ra <= {p12, rl}; nload = nload + 1; end
    else if (rc == 32) ra <= ra + {p12, rl};
  end

`ifdef STRUCT
  wire [54:0] nacc;
  wire [16:0] npipe;
  wire [11:0] ncnt;
  ft710_slice sl (
`include "tb_rx_out_mac_ports.vh"
  );
`endif

  always @(negedge clk) begin
    p11 <= {$random(seed)}; p12 <= {$random(seed), $random(seed)}; junk <= $random(seed);
    stb <= (cyc < 2) || (($random(seed) & 63) == 0);
  end
  always @(posedge clk) begin
    cyc <= cyc + 1;
    #1;
    if (cyc > 2) begin
      if (cnt !== rc || p_lo !== rl || acc !== ra) begin
        errors = errors + 1;
        if (errors < 10) $display("RTL  cyc %0d: cnt %0d/%0d acc %h exp %h", cyc, cnt, rc, acc, ra);
      end
`ifdef STRUCT
      if (ncnt !== cnt || npipe !== p_lo || nacc !== acc) begin
        mism = mism + 1;
        if (mism < 10) $display("SLICE cyc %0d: cnt %0d slice %0d  pipe %h slice %h  acc %h slice %h", cyc, cnt, ncnt,
                                p_lo, npipe, acc, nacc);
      end
`endif
    end
    if (cyc == `CYCLES) begin
      $display("%0d clocks, %0d accumulator loads: %0d reference errors, %0d mismatching clocks against the slice%s",
               cyc, nload, errors, mism,
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
