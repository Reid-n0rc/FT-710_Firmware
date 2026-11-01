// Testbench (T24): ft710_adc_dc (ADC capture + DC removal of one channel, netlist.md 3.7) on its own, and with
// -DSTRUCT against the netlist slice of channel A (default) or channel B (-DCHB).
//
// Without STRUCT: a constant input x gives y = 512 x right after reset, decaying as 512 x e^(-t/2^20) (checked at
// 2^20 clocks against e^-1 within 0.5 %), and en = 0 gives y = 512 x.
// With STRUCT it instantiates `ft710_slice` (tools/sdr_blocks.tsv rows adc_dc_a/b, written by tools/sdr_progress.py
// --slice), i.e. (channel A; for B the seeds are SLICE_X11Y41..Y46 A-D FFs)
//   python3 -I tools/xc7_netlist_verilog.py slice build/sdr/netlist.json build/sdr/sim/adc_dc_a.v \
//     --seeds SLICE_X45Y59/AFF,...,SLICE_X45Y64/DFF (the 24 y flip-flops) --depth 40 \
//     --stop ILOGIC_X1Y52,...(the 14 IDDRs),SLICE_X38Y63/AFF
// drives the slice's 14 IDDR Q pins with the ADC word in the #172 bit map and both designs with the same reset and
// enable, drives every other slice input (LUT6_2 halves that belong to other logic) with random bits, and compares
// the 24 y bits on every clock. Stimulus: random words, long constant full-scale stretches (so the 44-bit
// accumulator sweeps its whole range), random enable toggles and resets. Usage: hdl/sdr/README.md.
`timescale 1ns/1ps
`default_nettype none
module tb_adc_dc;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg rst = 1'b1, en = 1'b1;
  reg [13:0] adc = 14'd0;
  wire [23:0] y, dc;
  ft710_adc_dc dut (.clk(clk), .rst(rst), .en(en), .adc(adc), .y(y), .dc(dc));

  integer errors = 0, cyc = 0, mism = 0;
  reg [63:0] junk = 64'h0;
`ifdef STRUCT
  wire [23:0] sy;
`ifdef CHB
  // channel B pairs (bits 1:0 .. 13:12): ILOGIC_X1Y82, X1Y80, X1Y68, X1Y72, X1Y64, X1Y78, X1Y96
  ft710_slice s (
    .i_ILOGIC_X1Y82_Q1(adc[0]), .i_ILOGIC_X1Y82_Q2(adc[1]), .i_ILOGIC_X1Y80_Q1(adc[2]), .i_ILOGIC_X1Y80_Q2(adc[3]),
    .i_ILOGIC_X1Y68_Q1(adc[4]), .i_ILOGIC_X1Y68_Q2(adc[5]), .i_ILOGIC_X1Y72_Q1(adc[6]), .i_ILOGIC_X1Y72_Q2(adc[7]),
    .i_ILOGIC_X1Y64_Q1(adc[8]), .i_ILOGIC_X1Y64_Q2(adc[9]), .i_ILOGIC_X1Y78_Q1(adc[10]), .i_ILOGIC_X1Y78_Q2(adc[11]),
    .i_ILOGIC_X1Y96_Q1(adc[12]), .i_ILOGIC_X1Y96_Q2(adc[13]),
    .i_BUFHCE_X0Y10_O(clk), .i_BUFHCE_X0Y22_O(clk), .i_BUFHCE_X1Y21_O(clk),
    .i_SLICE_X4Y43_CFF_Q(rst), .i_SLICE_X38Y63_AFF_Q(en),
    .i_SLICE_X10Y46_AFF_Q(junk[0]), .i_SLICE_X15Y42_A5FF_Q(junk[1]), .i_SLICE_X7Y40_CFF_Q(junk[2]),
    .i_SLICE_X7Y40_DFF_Q(junk[3]), .i_DSP48_X0Y23_P1(junk[4]), .i_DSP48_X0Y23_P7(junk[5]), .i_DSP48_X0Y23_P8(junk[6]),
    .i_DSP48_X0Y23_P9(junk[7]), .i_DSP48_X0Y23_P10(junk[8]), .i_DSP48_X0Y23_P16(junk[9]), .i_DSP48_X0Y23_P2(junk[10]),
    .i_SLICE_X6Y44_DFF_Q(junk[11]), .i_SLICE_X8Y48_AFF_Q(junk[12]), .i_SLICE_X8Y48_BFF_Q(junk[13]),
    .i_SLICE_X8Y48_CFF_Q(junk[14]), .i_SLICE_X8Y48_DFF_Q(junk[15]), .i_SLICE_X5Y17_B5FF_Q(junk[16]),
    .i_SLICE_X4Y41_AFF_Q(junk[17]), .i_SLICE_X4Y41_BFF_Q(junk[18]), .i_SLICE_X5Y45_AFF_Q(junk[19]),
    .i_SLICE_X10Y46_BFF_Q(junk[20]), .i_SLICE_X7Y18_C5FF_Q(junk[21]), .i_SLICE_X14Y61_BFF_Q(junk[22]),
    .o_SLICE_X11Y41_AFF_Q(sy[0]), .o_SLICE_X11Y41_BFF_Q(sy[1]), .o_SLICE_X11Y41_CFF_Q(sy[2]), .o_SLICE_X11Y41_DFF_Q(sy[3]),
    .o_SLICE_X11Y42_AFF_Q(sy[4]), .o_SLICE_X11Y42_BFF_Q(sy[5]), .o_SLICE_X11Y42_CFF_Q(sy[6]), .o_SLICE_X11Y42_DFF_Q(sy[7]),
    .o_SLICE_X11Y43_AFF_Q(sy[8]), .o_SLICE_X11Y43_BFF_Q(sy[9]), .o_SLICE_X11Y43_CFF_Q(sy[10]), .o_SLICE_X11Y43_DFF_Q(sy[11]),
    .o_SLICE_X11Y44_AFF_Q(sy[12]), .o_SLICE_X11Y44_BFF_Q(sy[13]), .o_SLICE_X11Y44_CFF_Q(sy[14]), .o_SLICE_X11Y44_DFF_Q(sy[15]),
    .o_SLICE_X11Y45_AFF_Q(sy[16]), .o_SLICE_X11Y45_BFF_Q(sy[17]), .o_SLICE_X11Y45_CFF_Q(sy[18]), .o_SLICE_X11Y45_DFF_Q(sy[19]),
    .o_SLICE_X11Y46_AFF_Q(sy[20]), .o_SLICE_X11Y46_BFF_Q(sy[21]), .o_SLICE_X11Y46_CFF_Q(sy[22]), .o_SLICE_X11Y46_DFF_Q(sy[23]));
`else
  // channel A pairs (bits 1:0 .. 13:12): ILOGIC_X1Y66, X1Y70, X1Y60, X1Y58, X1Y56, X1Y54, X1Y52
  ft710_slice s (
    .i_ILOGIC_X1Y66_Q1(adc[0]), .i_ILOGIC_X1Y66_Q2(adc[1]), .i_ILOGIC_X1Y70_Q1(adc[2]), .i_ILOGIC_X1Y70_Q2(adc[3]),
    .i_ILOGIC_X1Y60_Q1(adc[4]), .i_ILOGIC_X1Y60_Q2(adc[5]), .i_ILOGIC_X1Y58_Q1(adc[6]), .i_ILOGIC_X1Y58_Q2(adc[7]),
    .i_ILOGIC_X1Y56_Q1(adc[8]), .i_ILOGIC_X1Y56_Q2(adc[9]), .i_ILOGIC_X1Y54_Q1(adc[10]), .i_ILOGIC_X1Y54_Q2(adc[11]),
    .i_ILOGIC_X1Y52_Q1(adc[12]), .i_ILOGIC_X1Y52_Q2(adc[13]),
    .i_BUFHCE_X1Y21_O(clk), .i_SLICE_X4Y43_CFF_Q(rst), .i_SLICE_X38Y63_AFF_Q(en),
    .i_RAMB18_X2Y24_DO3(junk[0]), .i_RAMB18_X2Y24_DO4(junk[1]), .i_RAMB18_X2Y24_DO8(junk[2]),
    .i_RAMB18_X2Y24_DO14(junk[3]), .i_SLICE_X44Y95_AFF_Q(junk[4]), .i_SLICE_X45Y93_AFF_Q(junk[5]),
    .i_SLICE_X45Y92_CFF_Q(junk[6]), .i_SLICE_X44Y94_AFF_Q(junk[7]), .i_SLICE_X39Y58_B5FF_Q(junk[8]),
    .i_SLICE_X43Y57_CFF_Q(junk[9]), .i_SLICE_X43Y56_CFF_Q(junk[10]), .i_SLICE_X43Y56_DFF_Q(junk[11]),
    .i_SLICE_X43Y57_BFF_Q(junk[12]), .i_SLICE_X43Y58_AFF_Q(junk[13]), .i_SLICE_X43Y59_AFF_Q(junk[14]),
    .i_SLICE_X43Y59_BFF_Q(junk[15]), .i_SLICE_X43Y59_CFF_Q(junk[16]), .i_SLICE_X43Y57_DFF_Q(junk[17]),
    .o_SLICE_X45Y59_AFF_Q(sy[0]), .o_SLICE_X45Y59_BFF_Q(sy[1]), .o_SLICE_X45Y59_CFF_Q(sy[2]), .o_SLICE_X45Y59_DFF_Q(sy[3]),
    .o_SLICE_X45Y60_AFF_Q(sy[4]), .o_SLICE_X45Y60_BFF_Q(sy[5]), .o_SLICE_X45Y60_CFF_Q(sy[6]), .o_SLICE_X45Y60_DFF_Q(sy[7]),
    .o_SLICE_X45Y61_AFF_Q(sy[8]), .o_SLICE_X45Y61_BFF_Q(sy[9]), .o_SLICE_X45Y61_CFF_Q(sy[10]), .o_SLICE_X45Y61_DFF_Q(sy[11]),
    .o_SLICE_X45Y62_AFF_Q(sy[12]), .o_SLICE_X45Y62_BFF_Q(sy[13]), .o_SLICE_X45Y62_CFF_Q(sy[14]), .o_SLICE_X45Y62_DFF_Q(sy[15]),
    .o_SLICE_X45Y63_AFF_Q(sy[16]), .o_SLICE_X45Y63_BFF_Q(sy[17]), .o_SLICE_X45Y63_CFF_Q(sy[18]), .o_SLICE_X45Y63_DFF_Q(sy[19]),
    .o_SLICE_X45Y64_AFF_Q(sy[20]), .o_SLICE_X45Y64_BFF_Q(sy[21]), .o_SLICE_X45Y64_CFF_Q(sy[22]), .o_SLICE_X45Y64_DFF_Q(sy[23]));
`endif
  always @(negedge clk)
    if (cyc > 8 && sy !== y) begin
      if (mism < 20) $display("MISMATCH cyc %0d: slice y %h | rtl y %h (dc %h)", cyc, sy, y, dc);
      mism = mism + 1;
    end
`endif

  // stimulus
  integer seg = 0, mode = 0, k;
  integer seed = 1;
  reg [13:0] cval;
  real r, want;
  always @(posedge clk) begin
    cyc <= cyc + 1;
    junk <= {$random(seed), $random(seed)};
  end
  initial begin
`ifdef STRUCT
    // random / constant segments
    repeat (10) @(posedge clk);
    rst = 0;
    while (cyc < `CYCLES) begin
      @(posedge clk);
      #1;
      if (seg == 0) begin
        mode = $random(seed) & 7;
        seg = (mode < 3) ? 2000 + ($random(seed) & 32767) : 200000 + ($random(seed) & 524287);
        cval = (mode == 3) ? 14'h1FFF : (mode == 4) ? 14'h2000 : $random(seed);
        if (($random(seed) & 15) == 0) en = ~en;
        if (($random(seed) & 31) == 0) begin rst = 1; @(posedge clk); #1 rst = 0; end
      end
      seg = seg - 1;
      adc = (mode < 3) ? $random(seed) : cval;
    end
    $display("slice comparison: %0d mismatching clocks in %0d", mism, cyc);
    if (mism) errors = errors + 1;
`else
    // behaviour: constant 1000 after reset, decay over 2^20 clocks
    adc = 14'd1000;
    repeat (10) @(posedge clk);
    #1 rst = 0;
    repeat (6) @(posedge clk);
    #1 if ($signed(y) > 512000 || $signed(y) < 511990) begin
      $display("y after reset %0d, want 512000 less a few LSB of dc", $signed(y)); errors = errors + 1;
    end
    repeat (1 << 20) @(posedge clk);
    #1 want = 512000.0 * 0.36787944;
    r = $signed(y);
    $display("y after 2^20 clocks: %0d (512000/e = %0d)", $signed(y), want);
    if (r < want * 0.995 || r > want * 1.005) errors = errors + 1;
    en = 0;
    repeat (3) @(posedge clk);
    #1 if ($signed(y) != 512000) begin $display("en=0: y %0d, want 512000", $signed(y)); errors = errors + 1; end
`endif
    $display("%s (%0d errors)", errors ? "FAIL" : "PASS", errors);
    $finish;
  end
endmodule
`default_nettype wire
