// Testbench (T24 SDR round 3): ft710_regread (read side of the register file; netlist.md 5.2).
//
// Without STRUCT: the RTL alone against a reference of the read map (a word of a stable address two clocks later).
// With STRUCT it also instantiates `ft710_slice` written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice regread build/sdr/sim/regread.v
// (seeds: the 16 read-data flip-flops and the 64 group flip-flops; depth 1; stop other-ffs, so the bus address
// flip-flops, the 598 register flip-flops, the status flip-flops of other blocks and the capture-RAM output pins are
// slice inputs). On every clock the address either stays (half of the clocks) or takes a new value, weighted towards
// 0x00..0x3F, the status window, the three RAM windows and 0; register, status and RAM inputs get new random bits on
// every clock (registers masked to their implemented bits), and the 2 other inputs (other halves of shared LUT6_2s)
// get random bits. The 16 read-data and the 64 group flip-flops are compared with the RTL on every clock.
// Port list: tb_regread_ports.vh (generated in round 3; cell names only), register masks: tb_regread_mask.vh.
`timescale 1ns/1ps
`default_nettype none
module tb_regread;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg  [15:0] a = 16'h0000;
  reg  [15:0] rr [0:41];
  reg  [15:0] rmask [0:41];
  reg  [15:0] st [0:12];
  reg  [7:0]  stw = 0, m22 = 0, m23 = 0, m24 = 0, m25 = 0, m26 = 0, m27 = 0;
  reg  [2:0]  junk = 0;
  wire [15:0] rd;
`include "tb_regread_mask.vh"
  wire [15:0] rv [0:41];
  genvar gi;
  generate for (gi = 0; gi < 42; gi = gi + 1) begin : msk
    assign rv[gi] = rr[gi] & rmask[gi];
  end endgenerate
  ft710_regread dut (.clk(clk), .a(a),
    .r03(rv[0]), .r04(rv[1]), .r05(rv[2]), .r06(rv[3]), .r07(rv[4]), .r08(rv[5]), .r09(rv[6]), .r0a(rv[7]),
    .r0b(rv[8]), .r0c(rv[9]), .r0d(rv[10]), .r0e(rv[11]), .r0f(rv[12]), .r10(rv[13]), .r11(rv[14]), .r12(rv[15]),
    .r13(rv[16]), .r14(rv[17]), .r15(rv[18]), .r16(rv[19]), .r17(rv[20]), .r18(rv[21]), .r19(rv[22]), .r1a(rv[23]),
    .r1b(rv[24]), .r1c(rv[25]), .r1d(rv[26]), .r1e(rv[27]), .r1f(rv[28]), .r20(rv[29]), .r21(rv[30]), .r22(rv[31]),
    .r23(rv[32]), .r24(rv[33]), .r25(rv[34]), .r26(rv[35]), .r27(rv[36]), .r2e(rv[37]), .r30(rv[38]), .r31(rv[39]),
    .r32(rv[40]), .r37(rv[41]),
    .st01(st[0]), .st02(st[1]), .st2f(st[2]), .st32(st[3]), .st33(st[4]), .st38(st[5]), .st39(st[6]), .st3a(st[7]),
    .st3b(st[8]), .st3c(st[9]), .st3d(st[10]), .st3e(st[11]), .st3f(st[12]),
    .stw(stw), .m24(m24), .m25(m25), .m26(m26), .m27(m27), .m22(m22), .m23(m23), .rd(rd));

  integer errors = 0, mism = 0, cyc = 0, seed = 41, i, r, nstable = 0;
`ifndef CYCLES
`define CYCLES 1000000
`endif
  initial begin
    for (i = 0; i < 42; i = i + 1) rr[i] = 0;
    for (i = 0; i < 13; i = i + 1) st[i] = 0;
  end

  // reference: the word of a stable address (the inputs of the clock before the read-data edge)
  function [15:0] il(input [7:0] ev, input [7:0] od);
    integer j;
    for (j = 0; j < 8; j = j + 1) begin il[2 * j] = ev[j]; il[2 * j + 1] = od[j]; end
  endfunction
  reg [15:0] exp_w;
  always @* begin
    if (a < 16'h0040) exp_w = dut.word(a[5:0]);
    else if (a[15:8] == 8'h01) exp_w = {8'h00, stw};
    else if (a[15:12] == 4'h3) exp_w = il(m26, m27);
    else if (a[15:13] == 3'b100) exp_w = il(m24, m25);
    else if (a[15:13] == 3'b110) exp_w = il(m22, m23);
    else exp_w = 16'hCCCC;
  end

`ifdef STRUCT
  wire [15:0] nrd;
  wire [15:0] ngrp [0:3];
  ft710_slice sl (
`include "tb_regread_ports.vh"
  );
`endif

  // the stimulus changes away from the active edge
  reg [15:0] a1 = 0, w1 = 0;              // address and reference word of the clock before
  always @(negedge clk) begin
    a1 <= a; w1 <= exp_w;
    for (i = 0; i < 42; i = i + 1) rr[i] <= $random(seed);
    for (i = 0; i < 13; i = i + 1) st[i] <= $random(seed);
    stw <= $random(seed); m22 <= $random(seed); m23 <= $random(seed); m24 <= $random(seed);
    m25 <= $random(seed); m26 <= $random(seed); m27 <= $random(seed); junk <= $random(seed);
    r = $random(seed) & 1023;
    if (r < 512) ;                                          // keep the address
    else if (r < 600) a <= 16'h0000;
    else if (r < 800) a <= $random(seed) & 16'h003F;
    else if (r < 840) a <= 16'h0100 | ($random(seed) & 16'h00FF);
    else if (r < 880) a <= 16'h3000 | ($random(seed) & 16'h0FFF);
    else if (r < 920) a <= 16'h8000 | ($random(seed) & 16'h1FFF);
    else if (r < 960) a <= 16'hC000 | ($random(seed) & 16'h1FFF);
    else a <= $random(seed);
  end
  // compare after the edge has settled
  always @(posedge clk) begin
    cyc <= cyc + 1;
    #1;
    if (cyc > 4) begin
      // RTL against the reference when the address was the same at this edge and the one before (groups: the
      // word of the clock before; windows: the inputs now)
      if (a1 == a) begin
        nstable = nstable + 1;
        if (rd !== (a < 16'h0040 ? w1 : exp_w)) begin
          errors = errors + 1;
          if (errors < 10) $display("RTL  cyc %0d a %h: rd %h exp %h", cyc, a, rd, a < 16'h0040 ? w1 : exp_w);
        end
      end
`ifdef STRUCT
      if (nrd !== rd || ngrp[0] !== dut.grp[0] || ngrp[1] !== dut.grp[1] || ngrp[2] !== dut.grp[2] ||
          ngrp[3] !== dut.grp[3]) begin
        mism = mism + 1;
        if (mism < 10) $display("SLICE cyc %0d a %h: rd %h slice %h  grp %h %h %h %h slice %h %h %h %h", cyc, a1,
                                rd, nrd, dut.grp[0], dut.grp[1], dut.grp[2], dut.grp[3], ngrp[0], ngrp[1], ngrp[2],
                                ngrp[3]);
      end
`endif
    end
    if (cyc == `CYCLES) begin
      $display("%0d clocks (%0d with a stable address): %0d reference errors, %0d mismatching clocks against the slice%s",
               cyc, nstable, errors, mism,
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
