// Testbench (T24 SDR round 2): ft710_scope_wr_data (scope RAM writer data path; netlist.md 5.6) on its own, and with
// -DSTRUCT against its netlist slice.
//
// Without STRUCT: the RTL against a reference written with integers (sum, difference, clamp, rounding, byte clamp).
// With STRUCT it instantiates `ft710_slice` written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice scope_wr_data build/sdr/sim/scope_wr_data.v
// (seeds: the 8 DIADI LUT outputs and the 11 value flip-flops; depth 1; stops: the sample, lvl, ref and g flip-flops,
// so those are slice inputs). Sample, lvl, ref and g get new random values on every clock, the clear is pulsed at
// random, and every other slice input (the other halves of shared LUT6_2s) gets random bits. The 11 register bits and
// the 8 RAM data bits are compared on every clock. Usage: hdl/sdr/README.md.
`timescale 1ns/1ps
`default_nettype none
module tb_scope_wr_data;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg        clr = 1'b1, g = 1'b0;
  reg [13:0] x = 0;
  reg [15:0] lvl = 0;
  reg [7:0]  refv = 0;
  wire [10:0] u;
  wire [7:0]  dia;
  ft710_scope_wr_data dut (.clk(clk), .clr(clr), .x(x), .lvl(lvl), .refv(refv), .g(g), .u(u), .dia(dia));

  integer errors = 0, cyc = 0, mism = 0, seed = 21;
  reg [7:0] junk = 8'h0;
`ifndef CYCLES
`define CYCLES 1000000
`endif

  // integer reference of the register input and of the byte
  function [10:0] ref_u(input [13:0] xx, input [15:0] ll, input [7:0] rr, input gg);
    integer s1, t, sx, rx;
    begin
      sx = xx[13] ? xx - 16384 : xx;
      rx = rr[7] ? rr - 256 : rr;
      s1 = (ll + sx) & 16'hFFFF;
      s1 = s1 >= 32768 ? s1 - 65536 : s1;            // signed 16-bit
      t = rx * (gg ? 8 : 16) - ((s1 + 1) >>> 1);      // ref * 2^sh - ceil(s1 / 2)
      t = t & 32'h7FFF;                               // 15-bit chain, modulo 2^15
      // the netlist tests one bit as the sign: t[13] when g = 1 (so t = -16384 .. -8193 passes as t[12:2]), t[14]
      if (gg) ref_u = t[13] ? 0 : (t >> 2) & 11'h7FF;
      else    ref_u = t[14] ? 0 : (t >> 3) & 11'h7FF;
    end
  endfunction
  function [7:0] ref_b(input [10:0] uu);
    integer w;
    begin
      w = uu[10:1] + ((uu[10:1] != 10'h3FF) ? uu[0] : 0);
      ref_b = w > 255 ? 8'hFE : w;
    end
  endfunction

`ifdef STRUCT
  wire [10:0] su;
  wire [7:0]  sd;
  ft710_slice sl (
    .i_BUFHCE_X1Y21_O(clk), .i_SLICE_X30Y70_AFF_Q(clr), .i_SLICE_X10Y81_CFF_Q(g),
    .i_SLICE_X41Y115_CFF_Q(x[0]), .i_SLICE_X41Y115_DFF_Q(x[1]), .i_SLICE_X41Y116_AFF_Q(x[2]),
    .i_SLICE_X41Y116_BFF_Q(x[3]), .i_SLICE_X41Y116_CFF_Q(x[4]), .i_SLICE_X41Y116_DFF_Q(x[5]),
    .i_SLICE_X41Y117_AFF_Q(x[6]), .i_SLICE_X41Y117_BFF_Q(x[7]), .i_SLICE_X41Y117_CFF_Q(x[8]),
    .i_SLICE_X41Y117_DFF_Q(x[9]), .i_SLICE_X41Y118_AFF_Q(x[10]), .i_SLICE_X41Y118_BFF_Q(x[11]),
    .i_SLICE_X41Y118_CFF_Q(x[12]), .i_SLICE_X41Y118_DFF_Q(x[13]),
    .i_SLICE_X30Y76_AFF_Q(lvl[0]), .i_SLICE_X32Y75_BFF_Q(lvl[1]), .i_SLICE_X32Y75_CFF_Q(lvl[2]),
    .i_SLICE_X15Y84_CFF_Q(lvl[3]), .i_SLICE_X7Y79_CFF_Q(lvl[4]), .i_SLICE_X6Y78_AFF_Q(lvl[5]),
    .i_SLICE_X30Y76_CFF_Q(lvl[6]), .i_SLICE_X7Y79_DFF_Q(lvl[7]), .i_SLICE_X11Y82_CFF_Q(lvl[8]),
    .i_SLICE_X9Y83_AFF_Q(lvl[9]), .i_SLICE_X30Y76_BFF_Q(lvl[10]), .i_SLICE_X11Y75_BFF_Q(lvl[11]),
    .i_SLICE_X9Y78_AFF_Q(lvl[12]), .i_SLICE_X28Y80_BFF_Q(lvl[13]), .i_SLICE_X11Y80_AFF_Q(lvl[14]),
    .i_SLICE_X32Y75_AFF_Q(lvl[15]),
    .i_SLICE_X11Y82_AFF_Q(refv[0]), .i_SLICE_X11Y82_BFF_Q(refv[1]), .i_SLICE_X11Y75_AFF_Q(refv[2]),
    .i_SLICE_X15Y84_AFF_Q(refv[3]), .i_SLICE_X6Y79_AFF_Q(refv[4]), .i_SLICE_X7Y79_AFF_Q(refv[5]),
    .i_SLICE_X15Y84_BFF_Q(refv[6]), .i_SLICE_X7Y79_BFF_Q(refv[7]),
    .i_SLICE_X52Y50_BFF_Q(junk[0]), .i_SLICE_X40Y70_A5FF_Q(junk[1]), .i_SLICE_X11Y85_C5FF_Q(junk[2]),
    .i_SLICE_X12Y89_C5FF_Q(junk[3]), .i_SLICE_X12Y89_B5FF_Q(junk[4]), .i_SLICE_X12Y89_D5FF_Q(junk[5]),
    .i_SLICE_X11Y85_B5FF_Q(junk[6]),
    .o_SLICE_X41Y65_BFF_Q(su[0]), .o_SLICE_X41Y65_CFF_Q(su[1]), .o_SLICE_X41Y64_AFF_Q(su[2]),
    .o_SLICE_X41Y64_BFF_Q(su[3]), .o_SLICE_X41Y64_CFF_Q(su[4]), .o_SLICE_X41Y64_DFF_Q(su[5]),
    .o_SLICE_X41Y65_DFF_Q(su[6]), .o_SLICE_X41Y65_AFF_Q(su[7]), .o_SLICE_X40Y66_AFF_Q(su[8]),
    .o_SLICE_X40Y66_BFF_Q(su[9]), .o_SLICE_X40Y66_B5FF_Q(su[10]),
    .o_SLICE_X58Y53_BLUT_O5(sd[0]), .o_SLICE_X58Y53_BLUT_O6(sd[1]), .o_SLICE_X58Y53_ALUT_O5(sd[2]),
    .o_SLICE_X58Y53_ALUT_O6(sd[3]), .o_SLICE_X58Y54_BLUT_O5(sd[4]), .o_SLICE_X58Y54_BLUT_O6(sd[5]),
    .o_SLICE_X58Y54_ALUT_O5(sd[6]), .o_SLICE_X58Y54_ALUT_O6(sd[7])
  );
`endif

  reg [10:0] exp_u = 0;
  always @(negedge clk) begin
    // inputs change away from the active edge; the clear is released / pulsed here too
    x <= $random(seed); lvl <= $random(seed); refv <= $random(seed); g <= $random(seed);
    junk <= $random(seed);
    clr <= (cyc < 3) || (($random(seed) & 255) == 0);
  end
  always @(posedge clk) begin
    cyc <= cyc + 1;
    exp_u <= clr ? 11'd0 : ref_u(x, lvl, refv, g);
  end
  // compare after the edge has settled
  always @(negedge clk) if (cyc > 4) begin
    if (u !== exp_u || dia !== ref_b(u)) begin
      errors = errors + 1;
      if (errors < 10) $display("RTL  cyc %0d: u %h exp %h  dia %h exp %h", cyc, u, exp_u, dia, ref_b(u));
    end
`ifdef STRUCT
    if (su !== u || sd !== dia) begin
      mism = mism + 1;
      if (mism < 10) $display("SLICE cyc %0d: u %h slice %h  dia %h slice %h", cyc, u, su, dia, sd);
    end
`endif
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
