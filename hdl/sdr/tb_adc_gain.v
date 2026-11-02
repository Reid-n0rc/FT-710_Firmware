// Testbench (T24): ft710_adc_gain (gain DSP, rounding, saturation, override; netlist.md 3.7) on its own, and with
// -DSTRUCT against the netlist slice of channel A (default) or B (-DCHB).
//
// Without STRUCT: g = 0x8000 gives o = y (unity gain), other gains round half away from zero, large gains saturate to +/-(2^23 - 1), a
// non-zero override v gives {v, 16'h0}; checked against a reference computed in the testbench.
// With STRUCT it instantiates `ft710_slice` cut by (channel A)
//   python3 -I tools/xc7_netlist_verilog.py slice build/sdr/netlist.json build/sdr/sim/adc_gain_a.v \
//     --seeds DSP48_X1Y26,<the 24 mixer-operand flip-flops> --depth 40 --stop <the 24 y flip-flops>,<register bits>
// (channel B: DSP48_X0Y17 and its operand flip-flops; exact lists: the tools/sdr_blocks.tsv rows adc_gain_a/b, written by tools/sdr_progress.py --slice), drives y, the 16 gain
// bits, the 8 override bits and the clear into both, every other slice input (LUT6_2 halves of other logic) with
// random bits, leaves the unused DSP cascade inputs open, and compares the 24 operand bits on every clock.
// Stimulus: random y with full-scale stretches, random gains plus 0x8000, powers of two (exact halves for the
// rounding) and 0xFFFF (saturation), rare overrides and clears. Usage: hdl/sdr/README.md.
`timescale 1ns/1ps
`default_nettype none
module tb_adc_gain;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg arst = 1'b1;
  reg [23:0] y = 24'd0;
  reg [15:0] g = 16'h8000;
  reg [7:0]  v = 8'd0;
  wire [23:0] o;
  ft710_adc_gain dut (.clk(clk), .arst(arst), .y(y), .g(g), .v(v), .o(o));

  integer errors = 0, cyc = 0, mism = 0, seed = 7, k;
  reg [63:0] junk = 64'h0;
  always @(posedge clk) begin cyc <= cyc + 1; junk <= {$random(seed), $random(seed)}; end
`ifdef STRUCT
  wire [23:0] so;
`ifdef CHB
  ft710_slice s (
    .i_SLICE_X11Y41_AFF_Q(y[0]), .i_SLICE_X11Y41_BFF_Q(y[1]), .i_SLICE_X11Y41_CFF_Q(y[2]),
    .i_SLICE_X11Y41_DFF_Q(y[3]), .i_SLICE_X11Y42_AFF_Q(y[4]), .i_SLICE_X11Y42_BFF_Q(y[5]),
    .i_SLICE_X11Y42_CFF_Q(y[6]), .i_SLICE_X11Y42_DFF_Q(y[7]), .i_SLICE_X11Y43_AFF_Q(y[8]),
    .i_SLICE_X11Y43_BFF_Q(y[9]), .i_SLICE_X11Y43_CFF_Q(y[10]), .i_SLICE_X11Y43_DFF_Q(y[11]),
    .i_SLICE_X11Y44_AFF_Q(y[12]), .i_SLICE_X11Y44_BFF_Q(y[13]), .i_SLICE_X11Y44_CFF_Q(y[14]),
    .i_SLICE_X11Y44_DFF_Q(y[15]), .i_SLICE_X11Y45_AFF_Q(y[16]), .i_SLICE_X11Y45_BFF_Q(y[17]),
    .i_SLICE_X11Y45_CFF_Q(y[18]), .i_SLICE_X11Y45_DFF_Q(y[19]), .i_SLICE_X8Y34_D5FF_Q(junk[0]),
    .i_SLICE_X6Y46_CFF_Q(junk[1]), .i_SLICE_X11Y46_AFF_Q(y[20]), .i_SLICE_X11Y46_BFF_Q(y[21]),
    .i_SLICE_X11Y46_CFF_Q(y[22]), .i_SLICE_X11Y46_DFF_Q(y[23]), .i_SLICE_X6Y47_AFF_Q(junk[2]),
    .i_SLICE_X6Y47_BFF_Q(junk[3]), .i_SLICE_X6Y47_CFF_Q(junk[4]), .i_SLICE_X6Y47_B5FF_Q(junk[5]),
    .i_SLICE_X8Y49_BFF_Q(junk[6]), .i_SLICE_X8Y49_CFF_Q(junk[7]), .i_SLICE_X8Y49_DFF_Q(junk[8]),
    .i_SLICE_X8Y49_A5FF_Q(junk[9]), .i_SLICE_X8Y49_AFF_Q(junk[10]), .i_SLICE_X8Y49_B5FF_Q(junk[11]),
    .i_SLICE_X14Y45_AFF_Q(g[0]), .i_SLICE_X14Y45_A5FF_Q(g[1]), .i_SLICE_X14Y45_BFF_Q(g[10]),
    .i_SLICE_X14Y45_B5FF_Q(g[5]), .i_SLICE_X14Y45_CFF_Q(g[13]), .i_SLICE_X14Y45_C5FF_Q(g[6]),
    .i_SLICE_X14Y45_DFF_Q(g[15]), .i_SLICE_X14Y45_D5FF_Q(g[8]), .i_SLICE_X14Y56_A5FF_Q(g[14]),
    .i_SLICE_X36Y60_A5FF_Q(v[5]), .i_SLICE_X36Y60_AFF_Q(v[0]), .i_SLICE_X36Y60_B5FF_Q(v[6]),
    .i_SLICE_X36Y60_CFF_Q(v[1]), .i_SLICE_X36Y60_C5FF_Q(v[7]), .i_SLICE_X36Y60_DFF_Q(v[4]),
    .i_SLICE_X4Y43_BFF_Q(arst), .i_BUFHCE_X0Y10_O(clk), .i_SLICE_X5Y47_BFF_Q(junk[12]),
    .i_SLICE_X5Y47_CFF_Q(junk[13]), .i_SLICE_X5Y47_DFF_Q(junk[14]), .i_SLICE_X4Y49_AFF_Q(junk[15]),
    .i_BUFHCE_X0Y22_O(clk), .i_SLICE_X32Y66_AFF_Q(v[2]), .i_SLICE_X32Y66_BFF_Q(v[3]), .i_SLICE_X13Y42_A5FF_Q(g[3]),
    .i_SLICE_X13Y42_B5FF_Q(g[7]), .i_SLICE_X15Y44_AFF_Q(junk[16]), .i_SLICE_X8Y43_B5FF_Q(junk[17]),
    .i_SLICE_X12Y46_B5FF_Q(g[12]), .i_SLICE_X12Y46_C5FF_Q(g[2]), .i_SLICE_X12Y46_DFF_Q(g[4]),
    .i_SLICE_X12Y46_D5FF_Q(g[9]), .i_SLICE_X12Y51_BFF_Q(g[11]), .o_SLICE_X11Y54_AFF_Q(so[0]),
    .o_SLICE_X13Y54_DFF_Q(so[1]), .o_SLICE_X11Y51_C5FF_Q(so[2]), .o_SLICE_X11Y54_C5FF_Q(so[3]),
    .o_SLICE_X11Y54_B5FF_Q(so[4]), .o_SLICE_X13Y54_C5FF_Q(so[5]), .o_SLICE_X11Y51_B5FF_Q(so[6]),
    .o_SLICE_X11Y54_D5FF_Q(so[7]), .o_SLICE_X9Y51_BFF_Q(so[8]), .o_SLICE_X9Y51_B5FF_Q(so[9]),
    .o_SLICE_X9Y51_AFF_Q(so[10]), .o_SLICE_X9Y51_A5FF_Q(so[11]), .o_SLICE_X11Y51_AFF_Q(so[12]),
    .o_SLICE_X11Y51_A5FF_Q(so[13]), .o_SLICE_X12Y51_AFF_Q(so[14]), .o_SLICE_X12Y51_A5FF_Q(so[15]),
    .o_SLICE_X11Y51_BFF_Q(so[16]), .o_SLICE_X13Y54_CFF_Q(so[17]), .o_SLICE_X11Y54_BFF_Q(so[18]),
    .o_SLICE_X11Y54_CFF_Q(so[19]), .o_SLICE_X11Y51_CFF_Q(so[20]), .o_SLICE_X13Y54_D5FF_Q(so[21]),
    .o_SLICE_X11Y54_DFF_Q(so[22]), .o_SLICE_X11Y54_A5FF_Q(so[23]));
`else
  ft710_slice s (
    .i_SLICE_X31Y66_AFF_Q(g[5]), .i_SLICE_X31Y66_BFF_Q(g[7]), .i_SLICE_X31Y67_BFF_Q(g[11]),
    .i_SLICE_X34Y65_AFF_Q(g[13]), .i_SLICE_X34Y65_BFF_Q(g[15]), .i_SLICE_X39Y64_A5FF_Q(g[10]),
    .i_SLICE_X39Y64_BFF_Q(g[4]), .i_SLICE_X39Y64_CFF_Q(g[9]), .i_SLICE_X43Y65_A5FF_Q(g[8]),
    .i_SLICE_X36Y60_BFF_Q(v[5]), .i_SLICE_X37Y64_AFF_Q(g[0]), .i_SLICE_X30Y65_BFF_Q(junk[0]),
    .i_SLICE_X30Y65_CFF_Q(junk[1]), .i_SLICE_X33Y65_CLUT_O6(junk[2]), .i_SLICE_X37Y65_BFF_Q(g[1]),
    .i_SLICE_X37Y65_CFF_Q(g[3]), .i_SLICE_X30Y65_B5FF_Q(junk[3]), .i_SLICE_X30Y66_BFF_Q(junk[4]),
    .i_SLICE_X33Y66_CFF_Q(junk[5]), .i_SLICE_X37Y66_AFF_Q(g[6]), .i_SLICE_X29Y66_CFF_Q(junk[6]),
    .i_SLICE_X29Y69_BFF_Q(junk[7]), .i_SLICE_X37Y68_AFF_Q(g[12]), .i_SLICE_X37Y68_BFF_Q(g[14]),
    .i_SLICE_X4Y43_BFF_Q(arst), .i_BUFHCE_X1Y21_O(clk), .i_SLICE_X35Y84_AFF_Q(junk[8]),
    .i_SLICE_X35Y84_BFF_Q(junk[9]), .i_SLICE_X35Y84_CFF_Q(junk[10]), .i_SLICE_X35Y84_DFF_Q(junk[11]),
    .i_SLICE_X40Y64_AFF_Q(junk[12]), .i_SLICE_X40Y64_BFF_Q(junk[13]), .i_SLICE_X40Y64_CFF_Q(junk[14]),
    .i_SLICE_X40Y72_BFF_Q(v[2]), .i_SLICE_X40Y72_CFF_Q(v[3]), .i_SLICE_X43Y72_DFF_Q(v[1]),
    .i_SLICE_X43Y72_CFF_Q(v[0]), .i_SLICE_X43Y72_BFF_Q(v[4]), .i_SLICE_X40Y72_C5FF_Q(v[7]),
    .i_SLICE_X40Y72_DFF_Q(v[6]), .i_SLICE_X45Y59_AFF_Q(y[0]), .i_SLICE_X45Y59_BFF_Q(y[1]),
    .i_SLICE_X45Y59_CFF_Q(y[2]), .i_SLICE_X45Y59_DFF_Q(y[3]), .i_SLICE_X45Y60_AFF_Q(y[4]),
    .i_SLICE_X45Y60_BFF_Q(y[5]), .i_SLICE_X45Y60_CFF_Q(y[6]), .i_SLICE_X45Y60_DFF_Q(y[7]),
    .i_SLICE_X45Y61_AFF_Q(y[8]), .i_SLICE_X45Y61_BFF_Q(y[9]), .i_SLICE_X45Y61_CFF_Q(y[10]),
    .i_SLICE_X45Y61_DFF_Q(y[11]), .i_SLICE_X45Y62_AFF_Q(y[12]), .i_SLICE_X45Y62_BFF_Q(y[13]),
    .i_SLICE_X45Y62_CFF_Q(y[14]), .i_SLICE_X45Y62_DFF_Q(y[15]), .i_SLICE_X45Y63_AFF_Q(y[16]),
    .i_SLICE_X45Y63_BFF_Q(y[17]), .i_SLICE_X45Y63_CFF_Q(y[18]), .i_SLICE_X45Y63_DFF_Q(y[19]),
    .i_SLICE_X45Y64_AFF_Q(y[20]), .i_SLICE_X45Y64_BFF_Q(y[21]), .i_SLICE_X45Y64_CFF_Q(y[22]),
    .i_SLICE_X45Y64_DFF_Q(y[23]), .i_SLICE_X11Y89_BFF_Q(junk[15]), .i_SLICE_X11Y85_B5FF_Q(junk[16]),
    .i_SLICE_X29Y65_A5FF_Q(g[2]), .o_SLICE_X39Y75_BFF_Q(so[0]), .o_SLICE_X39Y75_CFF_Q(so[1]),
    .o_SLICE_X39Y76_C5FF_Q(so[2]), .o_SLICE_X41Y76_C5FF_Q(so[3]), .o_SLICE_X41Y70_D5FF_Q(so[4]),
    .o_SLICE_X41Y76_B5FF_Q(so[5]), .o_SLICE_X41Y79_B5FF_Q(so[6]), .o_SLICE_X39Y75_DFF_Q(so[7]),
    .o_SLICE_X39Y75_D5FF_Q(so[8]), .o_SLICE_X39Y76_B5FF_Q(so[9]), .o_SLICE_X39Y77_BFF_Q(so[10]),
    .o_SLICE_X39Y76_AFF_Q(so[11]), .o_SLICE_X39Y76_BFF_Q(so[12]), .o_SLICE_X39Y77_B5FF_Q(so[13]),
    .o_SLICE_X39Y76_A5FF_Q(so[14]), .o_SLICE_X41Y79_AFF_Q(so[15]), .o_SLICE_X41Y76_BFF_Q(so[16]),
    .o_SLICE_X41Y70_DFF_Q(so[17]), .o_SLICE_X41Y76_CFF_Q(so[18]), .o_SLICE_X39Y76_CFF_Q(so[19]),
    .o_SLICE_X41Y79_BFF_Q(so[20]), .o_SLICE_X39Y75_B5FF_Q(so[21]), .o_SLICE_X39Y75_C5FF_Q(so[22]),
    .o_SLICE_X40Y71_AFF_Q(so[23]));
`endif
  always @(negedge clk)
    if (cyc > 8 && so !== o) begin
      if (mism < 20) $display("MISMATCH cyc %0d: slice %h | rtl %h (y %h g %h v %h)", cyc, so, o, y, g, v);
      mism = mism + 1;
    end
`endif

  // reference: o(t) from y, g, v sampled 5 clocks earlier (a/b, P, pr, s) and v 1 clock earlier
  function [23:0] ref_o(input [23:0] yy, input [15:0] gg);
    reg signed [47:0] p;
    reg signed [26:0] r;
    begin
      p = $signed(yy) * $signed({1'b0, gg});
      r = (p + (p[41] ? 48'sd16383 : 48'sd16384)) >>> 15;       // half away from zero
      ref_o = (r > 27'sd8388607) ? 24'h7FFFFF : (r < -27'sd8388607) ? 24'h800001 : r[23:0];
    end
  endfunction
  reg [23:0] yh [0:7];
  reg [15:0] gh [0:7];
  always @(posedge clk) begin
    for (k = 7; k > 0; k = k - 1) begin yh[k] <= yh[k - 1]; gh[k] <= gh[k - 1]; end
    yh[0] <= y; gh[0] <= g;
  end

  integer seg = 0, mode = 0, checked = 0;
  initial begin
    repeat (4) @(posedge clk);
    #1 arst = 0;
    while (cyc < `CYCLES) begin
      @(posedge clk);
      #1;
`ifndef STRUCT
      if (cyc > 12 && v == 0) begin
        checked = checked + 1;
        if (o !== ref_o(yh[4], gh[4])) begin
          if (errors < 10) $display("cyc %0d: o %h, want %h (y %h g %h)", cyc, o, ref_o(yh[4], gh[4]), yh[4], gh[4]);
          errors = errors + 1;
        end
      end
`endif
      if (seg == 0) begin
        mode = $random(seed) & 7;
        seg = 50 + ($random(seed) & 1023);
        case ($random(seed) & 7)
          0, 1: g = 16'h8000;
          2: g = 16'hFFFF;
          3: g = 16'h0001 << ($random(seed) & 15);
          default: g = $random(seed);
        endcase
`ifdef STRUCT
        v = (($random(seed) & 7) == 0) ? $random(seed) : 8'd0;
        if (($random(seed) & 63) == 0) begin arst = 1; @(posedge clk); #1 arst = 0; end
`else
        v = 8'd0;
`endif
      end
      seg = seg - 1;
      y = (mode == 0) ? 24'h7FFFFF : (mode == 1) ? 24'h800000 : (mode == 2) ? ($random(seed) & 24'hFF) : $random(seed);
    end
`ifdef STRUCT
    $display("slice comparison: %0d mismatching clocks in %0d", mism, cyc);
    if (mism) errors = errors + 1;
`else
    v = 8'h5A;
    repeat (2) @(posedge clk);
    #1 if (o !== 24'h5A0000) begin $display("override: o %h, want 5a0000", o); errors = errors + 1; end
    $display("reference comparison: %0d words checked", checked);
`endif
    $display("%s (%0d errors)", errors ? "FAIL" : "PASS", errors);
    $finish;
  end
endmodule
`default_nettype wire
