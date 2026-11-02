// Testbench (T24 SDR round 3): ft710_scope_wr_addr (address and write-enable side of the scope RAM writer;
// netlist.md 5.6).
//
// Without STRUCT: the RTL alone, with a check of the centre-out order (a sequence of load, then repeated A4 / AA /
// step, writes 425, 425, 424, 426, 423, 427, ...). With STRUCT it also instantiates `ft710_slice` written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice scope_wr_addr build/sdr/sim/scope_wr_addr.v
// (seeds: the 12 flip-flops on RAMB18_X2Y21 port A and the 20 index-counter flip-flops; depth 1; stop other-ffs, so
// the 16 sequencer state flip-flops, i0, i1 and the serializer's bank flip-flop are slice inputs). The state takes a
// random value on every clock, half of the time one of the decoded states (0x0082, 0x00A4, 0x00A8, 0x00AA, 0x00B1, or
// one of the 23 hold states), i0 is rare, i1 is set on a quarter of the clocks, and the 7 other inputs (other halves
// of shared LUT6_2s) get random bits. All 32 flip-flops are compared on every clock. Port list:
// tb_scope_wr_addr_ports.vh (generated in round 3; cell names only).
`timescale 1ns/1ps
`default_nettype none
module tb_scope_wr_addr;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg  [15:0] s = 0;
  reg         i0 = 1'b1, i1 = 1'b0, rbank = 1'b0;
  reg  [6:0]  junk = 0;
  wire [9:0]  cup, cdn, idx;
  wire        bank, we;
  ft710_scope_wr_addr dut (.clk(clk), .s(s), .i0(i0), .i1(i1), .rbank(rbank), .cup(cup), .cdn(cdn), .idx(idx),
                           .bank(bank), .we(we));
  integer errors = 0, mism = 0, cyc = 0, seed = 81, r, k;
`ifndef CYCLES
`define CYCLES 1000000
`endif
  reg [15:0] hold [0:22];
  initial begin
    hold[0] = 16'h0001; hold[1] = 16'h0002; hold[2] = 16'h000C; hold[3] = 16'h0014; hold[4] = 16'h0018;
    hold[5] = 16'h001F; hold[6] = 16'h0020; hold[7] = 16'h0022; hold[8] = 16'h0024; hold[9] = 16'h006A;
    hold[10] = 16'h006C; hold[11] = 16'h0070; hold[12] = 16'h0072; hold[13] = 16'h0080; hold[14] = 16'h0082;
    hold[15] = 16'h0090; hold[16] = 16'h0093; hold[17] = 16'h0098; hold[18] = 16'h009B; hold[19] = 16'h00A0;
    hold[20] = 16'h00A4; hold[21] = 16'h00AA; hold[22] = 16'hFFFF;
  end

`ifdef STRUCT
  wire [9:0] ncup, ncdn, nidx;
  wire       nbank, nwe;
  ft710_slice sl (
`include "tb_scope_wr_addr_ports.vh"
  );
`endif

`ifndef STRUCT
  // directed: load, then 4 passes of A4 (write cdn), AA (write cup), B1 (step)
  reg [9:0] seen [0:15];
  integer n = 0;
  initial begin
    @(negedge clk); i0 = 0; i1 = 0; s = 16'h0082; @(negedge clk);
    for (k = 0; k < 4; k = k + 1) begin
      s = 16'h00A4; @(negedge clk); seen[n] = idx; n = n + 1;
      s = 16'h00AA; @(negedge clk); seen[n] = idx; n = n + 1;
      s = 16'h00B1; @(negedge clk);
    end
    if (seen[0] != 425 || seen[1] != 425 || seen[2] != 424 || seen[3] != 426 || seen[6] != 422 || seen[7] != 428) begin
      errors = errors + 1;
      $display("order: %0d %0d %0d %0d %0d %0d %0d %0d", seen[0], seen[1], seen[2], seen[3], seen[4], seen[5], seen[6],
               seen[7]);
    end
    $display("centre-out order: %0d %0d %0d %0d %0d %0d %0d %0d", seen[0], seen[1], seen[2], seen[3], seen[4], seen[5],
             seen[6], seen[7]);
    $display("%0s", errors == 0 ? "PASS" : "FAIL");
    $finish;
  end
`else
  always @(negedge clk) begin
    r = $random(seed) & 15;
    if (r < 8) s <= $random(seed);
    else if (r == 8) s <= 16'h0082;
    else if (r == 9) s <= 16'h00A4;
    else if (r == 10) s <= 16'h00AA;
    else if (r == 11) s <= 16'h00B1;
    else if (r == 12) s <= 16'h00A8;
    else s <= hold[{$random(seed)} % 23];
    i0 <= (cyc < 2) || (($random(seed) & 255) == 0);
    i1 <= ($random(seed) & 3) == 0;
    rbank <= $random(seed); junk <= $random(seed);
  end
  always @(posedge clk) begin
    cyc <= cyc + 1;
    #1;
    if (cyc > 2 && (ncup !== cup || ncdn !== cdn || nidx !== idx || nbank !== bank || nwe !== we)) begin
      mism = mism + 1;
      if (mism < 10) $display("SLICE cyc %0d s %h: cup %0d/%0d cdn %0d/%0d idx %0d/%0d bank %b/%b we %b/%b", cyc, s, cup,
                              ncup, cdn, ncdn, idx, nidx, bank, nbank, we, nwe);
    end
    if (cyc == `CYCLES) begin
      $display("%0d clocks: %0d mismatching clocks against the slice", cyc, mism);
      $display("%0s", mism == 0 ? "PASS" : "FAIL");
      $finish;
    end
  end
`endif
endmodule
`default_nettype wire
