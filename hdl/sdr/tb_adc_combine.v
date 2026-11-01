// Testbench (T24): ft710_adc_combine (A + B combine, output mux, level flag; netlist.md 3.7) on its own, and with
// -DSTRUCT against its netlist slice.
//
// Without STRUCT: the three mux rows (A + B, A * 8, B), the 5 MSPS strobe and the hysteresis of u against a
// testbench reference.
// With STRUCT it instantiates `ft710_slice` cut by
//   python3 -I tools/xc7_netlist_verilog.py slice build/sdr/netlist.json build/sdr/sim/adc_combine.v \
//     --seeds <the 64 output flip-flops>,SLICE_X52Y88/AFF --depth 1 \
//     --stop SLICE_X52Y107/DLUT,SLICE_X50Y112/A5FF,<the 16 threshold register bits>
// (exact lists: the tools/sdr_blocks.tsv row adc_combine_mux, written by tools/sdr_progress.py --slice): depth 1 takes in the operand, s/t and level registers, so the slice inputs are
// the D nets of those registers, the strobe, the reset and the threshold bits. Both get the same random words, a
// 1-in-25 strobe, random s/t/threshold changes and resets; every other slice input (LUT6_2 halves of other logic)
// gets random bits. The 64 output bits and u are compared on every clock. Usage: hdl/sdr/README.md.
//
// Threshold bit order (thr[0] .. thr[15]): SLICE_X28Y79/AFF, X38Y76/DFF, X28Y79/A5FF, X28Y79/B5FF, X38Y76/A5FF,
// X28Y79/C5FF, X38Y76/B5FF, X14Y80/AFF, X14Y80/BFF, X38Y76/C5FF, X38Y76/AFF, X38Y76/BFF, X28Y79/BFF, X28Y79/CFF,
// X38Y76/CFF, X28Y79/DFF (read off the 2-bit comparator LUTs).
`timescale 1ns/1ps
`default_nettype none
module tb_adc_combine;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg srst = 1'b1, ce = 1'b0, s_d = 1'b1, t_d = 1'b0;
  reg [31:0] a0_d = 0, b0_d = 0, a1_d = 0, b1_d = 0;
  reg [16:0] l_d = 0;
  reg [15:0] thr = 16'h4000;
  wire [31:0] out0, out1;
  wire u;
  ft710_adc_combine dut (.clk(clk), .srst(srst), .ce(ce), .a0_d(a0_d), .b0_d(b0_d), .a1_d(a1_d), .b1_d(b1_d),
                         .s_d(s_d), .t_d(t_d), .l_d(l_d), .thr(thr), .out0(out0), .out1(out1), .u(u));

  integer errors = 0, cyc = 0, mism = 0, seed = 11, div = 0, k;
  reg [63:0] junk = 64'h0;
  always @(posedge clk) begin cyc <= cyc + 1; junk <= {$random(seed), $random(seed)}; end
`ifdef STRUCT
  wire [31:0] so0, so1;
  wire so_u;
  ft710_slice sl (
    .i_SLICE_X51Y100_CARRY4_O_3_(l_d[0]), .i_SLICE_X51Y101_CARRY4_O_0_(l_d[1]), .i_SLICE_X51Y101_CARRY4_O_1_(l_d[2]),
    .i_SLICE_X51Y101_CARRY4_O_2_(l_d[3]), .i_SLICE_X51Y101_CARRY4_O_3_(l_d[4]), .i_SLICE_X51Y102_CARRY4_O_0_(l_d[5]),
    .i_SLICE_X51Y102_CARRY4_O_1_(l_d[6]), .i_SLICE_X51Y102_CARRY4_O_2_(l_d[7]), .i_SLICE_X51Y102_CARRY4_O_3_(l_d[8]),
    .i_SLICE_X51Y103_CARRY4_O_0_(l_d[9]), .i_SLICE_X51Y103_CARRY4_O_1_(l_d[10]),
    .i_SLICE_X51Y103_CARRY4_O_2_(l_d[11]), .i_SLICE_X51Y103_CARRY4_O_3_(l_d[12]),
    .i_SLICE_X51Y104_CARRY4_O_0_(l_d[13]), .i_SLICE_X51Y104_CARRY4_O_1_(l_d[14]),
    .i_SLICE_X51Y104_CARRY4_O_2_(l_d[15]), .i_SLICE_X51Y104_CARRY4_O_3_(l_d[16]), .i_SLICE_X51Y115_ALUT_O(a1_d[13]),
    .i_SLICE_X51Y115_BLUT_O(a1_d[14]), .i_SLICE_X51Y115_DLUT_O(a1_d[16]), .i_SLICE_X50Y121_B5FF_Q(a1_d[17]),
    .i_SLICE_X51Y116_BFF_Q(a1_d[19]), .i_SLICE_X54Y123_AFF_Q(a1_d[21]), .i_SLICE_X54Y123_BFF_Q(a1_d[22]),
    .i_SLICE_X50Y116_DFF_Q(a1_d[15]), .i_SLICE_X50Y121_C5FF_Q(a1_d[18]), .i_SLICE_X51Y116_CFF_Q(a1_d[26]),
    .i_SLICE_X51Y116_DFF_Q(a1_d[27]), .i_SLICE_X51Y126_D5FF_Q(a1_d[31]), .i_SLICE_X56Y101_CFF_Q(b1_d[6]),
    .i_SLICE_X56Y102_A5FF_Q(b1_d[21]), .i_SLICE_X56Y102_B5FF_Q(b1_d[4]), .i_SLICE_X53Y102_DFF_Q(b1_d[3]),
    .i_SLICE_X56Y104_BFF_Q(b1_d[22]), .i_SLICE_X56Y104_CFF_Q(b1_d[23]), .i_SLICE_X56Y104_DFF_Q(b1_d[24]),
    .i_SLICE_X56Y105_BLUT_O5(b1_d[11]), .i_SLICE_X56Y105_DLUT_O5(b1_d[5]), .i_SLICE_X56Y99_DFF_Q(b1_d[10]),
    .i_SLICE_X56Y107_A5FF_Q(b1_d[16]), .i_SLICE_X56Y108_A5FF_Q(b1_d[31]), .i_SLICE_X57Y114_DLUT_O(a1_d[9]),
    .i_SLICE_X57Y121_AFF_Q(a1_d[0]), .i_SLICE_X57Y121_BFF_Q(a1_d[10]), .i_SLICE_X57Y121_B5FF_Q(a1_d[4]),
    .i_SLICE_X57Y116_BLUT_O(a1_d[20]), .i_SLICE_X57Y116_CLUT_O(a1_d[23]), .i_SLICE_X57Y116_DLUT_O(a1_d[24]),
    .i_SLICE_X57Y116_AFF_Q(a1_d[2]), .i_SLICE_X54Y122_DFF_Q(a1_d[25]), .i_SLICE_X54Y125_D5FF_Q(a1_d[28]),
    .i_SLICE_X57Y121_A5FF_Q(a1_d[3]), .i_SLICE_X57Y121_CFF_Q(a1_d[11]), .i_SLICE_X57Y121_DFF_Q(a1_d[12]),
    .i_SLICE_X43Y95_BFF_Q(junk[0]), .i_SLICE_X47Y98_AFF_Q(junk[1]), .i_SLICE_X56Y99_CFF_Q(b1_d[0]),
    .i_SLICE_X42Y94_ALUT_O(a0_d[4]), .i_SLICE_X42Y94_BLUT_O(a0_d[5]), .i_SLICE_X42Y94_CLUT_O(a0_d[8]),
    .i_SLICE_X42Y94_A5FF_Q(b0_d[26]), .i_SLICE_X42Y97_ALUT_O(a0_d[14]), .i_SLICE_X42Y97_BLUT_O(a0_d[15]),
    .i_SLICE_X42Y97_CLUT_O(a0_d[22]), .i_SLICE_X42Y97_B5FF_Q(b0_d[29]), .i_SLICE_X46Y89_AFF_Q(junk[2]),
    .i_SLICE_X55Y78_DFF_Q(junk[3]), .i_SLICE_X46Y93_BFF_Q(b0_d[10]), .i_SLICE_X46Y91_AFF_Q(b0_d[1]),
    .i_SLICE_X46Y93_AFF_Q(junk[4]), .i_SLICE_X46Y91_BFF_Q(b0_d[3]), .i_SLICE_X46Y93_CFF_Q(b0_d[9]),
    .i_SLICE_X46Y92_AFF_Q(junk[5]), .i_SLICE_X46Y94_BFF_Q(b0_d[0]), .i_SLICE_X46Y92_BFF_Q(b0_d[2]),
    .i_SLICE_X46Y94_AFF_Q(junk[6]), .i_DSP48_X1Y38_P0(junk[7]), .i_DSP48_X1Y38_P4(junk[8]),
    .i_DSP48_X1Y38_P5(junk[9]), .i_SLICE_X53Y103_CFF_Q(b1_d[20]), .i_SLICE_X53Y104_CFF_Q(b1_d[29]),
    .i_SLICE_X53Y106_A5FF_Q(b1_d[28]), .i_SLICE_X53Y106_BFF_Q(b1_d[14]), .i_SLICE_X53Y106_DFF_Q(b1_d[26]),
    .i_SLICE_X52Y96_CFF_Q(b1_d[19]), .i_SLICE_X54Y100_A5FF_Q(b1_d[12]), .i_SLICE_X54Y100_B5FF_Q(b1_d[7]),
    .i_SLICE_X54Y100_C5FF_Q(b1_d[9]), .i_SLICE_X55Y100_DFF_Q(b1_d[2]), .i_SLICE_X54Y98_CFF_Q(b1_d[1]),
    .i_SLICE_X54Y103_DFF_Q(b1_d[8]), .i_SLICE_X54Y105_BLUT_O5(b1_d[13]), .i_SLICE_X54Y105_CLUT_O5(b1_d[15]),
    .i_SLICE_X54Y105_DLUT_O5(b1_d[17]), .i_SLICE_X54Y108_ALUT_O5(b1_d[18]), .i_SLICE_X54Y108_BLUT_O5(b1_d[25]),
    .i_SLICE_X54Y108_CLUT_O5(b1_d[27]), .i_SLICE_X54Y108_DLUT_O5(b1_d[30]), .i_SLICE_X54Y123_A5FF_Q(a1_d[7]),
    .i_SLICE_X54Y122_CFF_Q(a1_d[1]), .i_SLICE_X54Y123_CFF_Q(a1_d[5]), .i_SLICE_X54Y123_DFF_Q(a1_d[6]),
    .i_SLICE_X55Y115_CFF_Q(junk[10]), .i_SLICE_X54Y122_A5FF_Q(a1_d[29]), .i_SLICE_X54Y122_B5FF_Q(a1_d[30]),
    .i_SLICE_X54Y123_B5FF_Q(a1_d[8]), .i_SLICE_X52Y107_DLUT_O(ce), .i_SLICE_X50Y112_A5FF_Q(srst),
    .i_BUFHCE_X1Y21_O(clk), .i_SLICE_X40Y105_B5FF_Q(a0_d[6]), .i_SLICE_X41Y106_AFF_Q(a0_d[11]),
    .i_SLICE_X41Y106_DFF_Q(a0_d[17]), .i_SLICE_X41Y111_AFF_Q(a0_d[10]), .i_SLICE_X41Y111_A5FF_Q(a0_d[9]),
    .i_SLICE_X41Y111_CFF_Q(a0_d[16]), .i_SLICE_X41Y111_DFF_Q(a0_d[23]), .i_SLICE_X40Y70_AFF_Q(t_d),
    .i_SLICE_X41Y74_ALUT_O5(s_d), .i_SLICE_X41Y95_BLUT_O5(a0_d[1]), .i_SLICE_X41Y95_CLUT_O5(a0_d[24]),
    .i_SLICE_X41Y95_DLUT_O5(b0_d[30]), .i_SLICE_X41Y96_CFF_Q(b0_d[28]), .i_SLICE_X41Y97_ALUT_O5(a0_d[25]),
    .i_SLICE_X41Y97_BLUT_O5(a0_d[26]), .i_SLICE_X41Y97_CLUT_O5(a0_d[27]), .i_SLICE_X41Y98_ALUT_O5(a0_d[28]),
    .i_SLICE_X41Y98_BLUT_O5(a0_d[29]), .i_SLICE_X41Y98_CLUT_O5(a0_d[30]), .i_SLICE_X41Y98_DLUT_O5(a0_d[31]),
    .i_SLICE_X41Y99_DLUT_O5(a0_d[13]), .i_SLICE_X41Y99_BFF_Q(a0_d[2]), .i_SLICE_X45Y86_AFF_Q(junk[11]),
    .i_SLICE_X44Y90_B5FF_Q(b0_d[4]), .i_SLICE_X44Y92_B5FF_Q(b0_d[5]), .i_SLICE_X44Y92_C5FF_Q(b0_d[7]),
    .i_SLICE_X45Y91_A5FF_Q(junk[12]), .i_SLICE_X44Y92_DFF_Q(b0_d[11]), .i_SLICE_X45Y92_B5FF_Q(b0_d[8]),
    .i_SLICE_X44Y95_CFF_Q(b0_d[18]), .i_SLICE_X45Y93_B5FF_Q(junk[13]), .i_SLICE_X45Y93_C5FF_Q(b0_d[6]),
    .i_SLICE_X45Y94_DFF_Q(b0_d[17]), .i_SLICE_X44Y94_A5FF_Q(junk[14]), .i_SLICE_X44Y94_B5FF_Q(b0_d[19]),
    .i_SLICE_X44Y94_DFF_Q(b0_d[14]), .i_SLICE_X45Y94_CFF_Q(b0_d[12]), .i_SLICE_X45Y94_C5FF_Q(b0_d[22]),
    .i_SLICE_X45Y97_DFF_Q(b0_d[16]), .i_SLICE_X44Y95_DFF_Q(b0_d[20]), .i_SLICE_X45Y95_C5FF_Q(b0_d[21]),
    .i_SLICE_X44Y96_ALUT_O(a0_d[12]), .i_SLICE_X44Y96_BLUT_O(a0_d[19]), .i_SLICE_X44Y96_A5FF_Q(b0_d[13]),
    .i_SLICE_X44Y96_B5FF_Q(b0_d[15]), .i_SLICE_X45Y97_A5FF_Q(b0_d[27]), .i_SLICE_X45Y96_ALUT_O(a0_d[0]),
    .i_SLICE_X45Y96_BLUT_O(a0_d[20]), .i_SLICE_X45Y96_A5FF_Q(b0_d[23]), .i_SLICE_X45Y97_ALUT_O(a0_d[18]),
    .i_SLICE_X45Y97_B5FF_Q(b0_d[31]), .i_SLICE_X44Y98_ALUT_O(b0_d[24]), .i_SLICE_X44Y98_BLUT_O(a0_d[3]),
    .i_SLICE_X44Y98_DLUT_O(a0_d[7]), .i_SLICE_X44Y99_C5FF_Q(b0_d[25]), .i_SLICE_X44Y99_CLUT_O(a0_d[21]),
    .i_BUFHCE_X1Y32_O(clk), .i_SLICE_X28Y79_AFF_Q(thr[0]), .i_SLICE_X28Y79_A5FF_Q(thr[2]),
    .i_SLICE_X28Y79_BFF_Q(thr[12]), .i_SLICE_X14Y80_BFF_Q(thr[8]), .i_SLICE_X28Y79_DFF_Q(thr[15]),
    .i_SLICE_X28Y79_CFF_Q(thr[13]), .i_SLICE_X28Y79_B5FF_Q(thr[3]), .i_SLICE_X28Y79_C5FF_Q(thr[5]),
    .i_SLICE_X38Y76_DFF_Q(thr[1]), .i_SLICE_X38Y76_A5FF_Q(thr[4]), .i_SLICE_X14Y80_AFF_Q(thr[7]),
    .i_SLICE_X38Y76_B5FF_Q(thr[6]), .i_SLICE_X38Y76_C5FF_Q(thr[9]), .i_SLICE_X38Y76_BFF_Q(thr[11]),
    .i_SLICE_X38Y76_AFF_Q(thr[10]), .i_SLICE_X38Y76_CFF_Q(thr[14]), .i_SLICE_X43Y95_B5FF_Q(junk[15]),
    .o_SLICE_X44Y90_AFF_Q(so0[11]), .o_SLICE_X44Y90_BFF_Q(so0[8]), .o_SLICE_X44Y90_CFF_Q(so0[9]),
    .o_SLICE_X44Y90_DFF_Q(so0[10]), .o_SLICE_X44Y92_AFF_Q(so0[20]), .o_SLICE_X44Y94_AFF_Q(so0[25]),
    .o_SLICE_X44Y95_AFF_Q(so0[30]), .o_SLICE_X44Y95_BFF_Q(so0[31]), .o_SLICE_X45Y89_AFF_Q(so0[4]),
    .o_SLICE_X45Y89_BFF_Q(so0[5]), .o_SLICE_X45Y89_CFF_Q(so0[6]), .o_SLICE_X45Y89_DFF_Q(so0[7]),
    .o_SLICE_X45Y91_AFF_Q(so0[12]), .o_SLICE_X45Y91_BFF_Q(so0[13]), .o_SLICE_X45Y91_CFF_Q(so0[3]),
    .o_SLICE_X45Y92_AFF_Q(so0[14]), .o_SLICE_X45Y92_BFF_Q(so0[16]), .o_SLICE_X45Y92_CFF_Q(so0[18]),
    .o_SLICE_X45Y92_DFF_Q(so0[19]), .o_SLICE_X45Y93_AFF_Q(so0[17]), .o_SLICE_X45Y93_BFF_Q(so0[21]),
    .o_SLICE_X45Y93_CFF_Q(so0[22]), .o_SLICE_X45Y93_DFF_Q(so0[23]), .o_SLICE_X45Y94_AFF_Q(so0[24]),
    .o_SLICE_X45Y94_BFF_Q(so0[26]), .o_SLICE_X45Y95_AFF_Q(so0[15]), .o_SLICE_X45Y95_BFF_Q(so0[27]),
    .o_SLICE_X45Y95_CFF_Q(so0[28]), .o_SLICE_X45Y95_DFF_Q(so0[29]), .o_SLICE_X49Y90_AFF_Q(so0[2]),
    .o_SLICE_X52Y88_AFF_Q(so_u), .o_SLICE_X53Y109_AFF_Q(so1[17]), .o_SLICE_X53Y109_BFF_Q(so1[19]),
    .o_SLICE_X54Y107_AFF_Q(so1[10]), .o_SLICE_X54Y107_BFF_Q(so1[11]), .o_SLICE_X54Y107_CFF_Q(so1[6]),
    .o_SLICE_X54Y107_DFF_Q(so1[9]), .o_SLICE_X54Y112_AFF_Q(so1[18]), .o_SLICE_X54Y112_BFF_Q(so1[20]),
    .o_SLICE_X54Y112_CFF_Q(so1[21]), .o_SLICE_X54Y112_DFF_Q(so1[22]), .o_SLICE_X54Y113_AFF_Q(so1[24]),
    .o_SLICE_X54Y113_BFF_Q(so1[25]), .o_SLICE_X54Y113_CFF_Q(so1[27]), .o_SLICE_X54Y113_DFF_Q(so1[30]),
    .o_SLICE_X56Y107_AFF_Q(so1[14]), .o_SLICE_X56Y107_BFF_Q(so1[3]), .o_SLICE_X56Y107_CFF_Q(so1[4]),
    .o_SLICE_X56Y107_DFF_Q(so1[5]), .o_SLICE_X56Y108_AFF_Q(so1[12]), .o_SLICE_X56Y108_BFF_Q(so1[13]),
    .o_SLICE_X56Y108_CFF_Q(so1[7]), .o_SLICE_X56Y108_DFF_Q(so1[8]), .o_SLICE_X56Y89_AFF_Q(so0[1]),
    .o_SLICE_X56Y89_BFF_Q(so0[0]), .o_SLICE_X56Y98_AFF_Q(so1[0]), .o_SLICE_X56Y98_BFF_Q(so1[1]),
    .o_SLICE_X56Y98_CFF_Q(so1[2]), .o_SLICE_X57Y111_AFF_Q(so1[15]), .o_SLICE_X57Y111_BFF_Q(so1[16]),
    .o_SLICE_X57Y111_CFF_Q(so1[23]), .o_SLICE_X57Y111_DFF_Q(so1[26]), .o_SLICE_X57Y114_AFF_Q(so1[28]),
    .o_SLICE_X57Y114_BFF_Q(so1[29]), .o_SLICE_X57Y114_CFF_Q(so1[31]));
  always @(negedge clk)
    if (cyc > 4 && {so0, so1, so_u} !== {out0, out1, u}) begin
      if (mism < 20) $display("MISMATCH cyc %0d: slice %h %h u%b | rtl %h %h u%b", cyc, so0, so1, so_u, out0, out1, u);
      mism = mism + 1;
    end
`else
  // reference (RTL-only run): operands one strobe old, output one strobe later
  reg [31:0] ra0, rb0, ra1, rb1, w0, w1;
  reg rs, rt, ru, ru1;
  reg [16:0] rl;
  always @(posedge clk) begin
    rs <= s_d; rt <= t_d; rl <= l_d;
    ru <= (rl[16:1] > thr) | (ru & ~(rl[15:0] < thr));
    if (srst) begin ra0 <= 0; rb0 <= 0; ra1 <= 0; rb1 <= 0; w0 <= 0; w1 <= 0; end
    else if (ce) begin
      ra0 <= a0_d; rb0 <= b0_d; ra1 <= a1_d; rb1 <= b1_d;
      w0 <= (~rs & rt) ? ra0 + rb0 : (rs & ~rt & ru) ? ra0 << 3 : rb0;
      w1 <= (~rs & rt) ? ra1 + rb1 : (rs & ~rt & ru) ? ra1 << 3 : rb1;
    end
  end
  integer rows[0:2];
  initial begin rows[0] = 0; rows[1] = 0; rows[2] = 0; end
  always @(negedge clk) if (cyc > 4) begin
    if ({w0, w1} !== {out0, out1}) begin
      if (errors < 10) $display("cyc %0d: rtl %h %h, ref %h %h", cyc, out0, out1, w0, w1);
      errors = errors + 1;
    end
    if (ce) rows[(~rs & rt) ? 0 : (rs & ~rt & ru) ? 1 : 2] = rows[(~rs & rt) ? 0 : (rs & ~rt & ru) ? 1 : 2] + 1;
  end
`endif

  initial begin
    repeat (4) @(posedge clk);
    #1 srst = 0;
    while (cyc < `CYCLES) begin
      @(posedge clk);
      #1;
      div = (div == 24) ? 0 : div + 1;
      ce = (div == 0) | (($random(seed) & 255) == 0);
      a0_d = $random(seed); b0_d = $random(seed); a1_d = $random(seed); b1_d = $random(seed);
      l_d = (($random(seed) & 3) == 0) ? $random(seed) : {thr, 1'b0} + ($random(seed) % 9);
      if (($random(seed) & 511) == 0) {s_d, t_d} = $random(seed);
      if (($random(seed) & 4095) == 0) thr = $random(seed);
      if (($random(seed) & 8191) == 0) begin srst = 1; @(posedge clk); #1 srst = 0; end
    end
`ifdef STRUCT
    $display("slice comparison: %0d mismatching clocks in %0d", mism, cyc);
    if (mism) errors = errors + 1;
`else
    $display("strobes per row: A+B %0d, A*8 %0d, B %0d", rows[0], rows[1], rows[2]);
    if (!rows[0] || !rows[1] || !rows[2]) errors = errors + 1;
`endif
    $display("%s (%0d errors)", errors ? "FAIL" : "PASS", errors);
    $finish;
  end
endmodule
`default_nettype wire
