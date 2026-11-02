// Testbench (T24 SDR round 2): ft710_regfile (write side of the register file; netlist.md 5.2).
//
// -DSTRUCT: against its netlist slice, written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice regfile build/sdr/sim/regfile.v
// (seeds: the 598 register flip-flops, ffs-fed:D=<write data>&CE=<strobe>&T=FDRE+FDSE; depth 1; stop other-ffs,
// so the bus flip-flops, the reset flip-flop and every other register become slice inputs). The bus gets a new
// value on every clock: 3/4 of the clocks a register address of the map (or a neighbour in 0x00..0x3F), else a
// random 16-bit address, random data, the strobe on half of the clocks, a rare reset; every other slice input gets
// random bits. All 598 flip-flops are compared with the RTL on every clock. The address bits a6..a15 drive the
// netlist's upper address flip-flops in a fixed order that is not settled bit by bit (every register decodes them
// as all-zero, so the order does not change any register's decode).
// -DTRACE=<file>: whole-netlist co-simulation from a regmap_main.cpp log (tools: hdl/sdr/README.md): the netlist's
// bus flip-flops drive the RTL clock by clock and the netlist's 598 register flip-flops are compared on every clock.
// Port and map lists: tb_regfile_ports.vh, tb_regfile_map.vh (generated from the round-2 analysis; cell names only).
`timescale 1ns/1ps
`default_nettype none
module tb_regfile;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg        rst = 1'b1, we = 1'b0, re = 1'b0;
  reg [15:0] a = 0, d = 0;
  wire [15:0] r03, r04, r05, r06, r07, r08, r09, r0a, r0b, r0c, r0d, r0e, r0f, r10, r11, r12, r13, r14, r15, r16,
              r17, r18, r19, r1a, r1b, r1c, r1d, r1e, r1f, r20, r21, r22, r23, r24, r25, r26, r27, r2e, r30, r31,
              r32, r37;
  ft710_regfile dut (.clk(clk), .rst(rst), .we(we), .a(a), .d(d),
    .r03(r03), .r04(r04), .r05(r05), .r06(r06), .r07(r07), .r08(r08), .r09(r09), .r0a(r0a), .r0b(r0b), .r0c(r0c),
    .r0d(r0d), .r0e(r0e), .r0f(r0f), .r10(r10), .r11(r11), .r12(r12), .r13(r13), .r14(r14), .r15(r15), .r16(r16),
    .r17(r17), .r18(r18), .r19(r19), .r1a(r1a), .r1b(r1b), .r1c(r1c), .r1d(r1d), .r1e(r1e), .r1f(r1f), .r20(r20),
    .r21(r21), .r22(r22), .r23(r23), .r24(r24), .r25(r25), .r26(r26), .r27(r27), .r2e(r2e), .r30(r30), .r31(r31),
    .r32(r32), .r37(r37));

  // the RTL's view of every netlist register flip-flop, in map order
  wire [597:0] rb;
`define RB(c, r, b, n) assign rb[n] = r[b];
`include "tb_regfile_map.vh"
`undef RB
  wire [597:0] nl;                 // the netlist's flip-flops (slice outputs, or the trace)
  integer cyc = 0, mism = 0, seed = 31, k, nwr = 0;
`ifndef CYCLES
`define CYCLES 1000000
`endif

`ifdef STRUCT
  reg [255:0] junk = 0;
`define RB(c, r, b, n) .o_``c``_Q(nl[n]),
  ft710_slice sl (
`include "tb_regfile_ports.vh"
`include "tb_regfile_map.vh"
    `RF_CLOCKS
  );
`undef RB
  reg [7:0] regs [0:41];
  initial begin
    regs[0] = 8'h03; regs[1] = 8'h04; regs[2] = 8'h05; regs[3] = 8'h06; regs[4] = 8'h07; regs[5] = 8'h08;
    regs[6] = 8'h09; regs[7] = 8'h0A; regs[8] = 8'h0B; regs[9] = 8'h0C; regs[10] = 8'h0D; regs[11] = 8'h0E;
    regs[12] = 8'h0F; regs[13] = 8'h10; regs[14] = 8'h11; regs[15] = 8'h12; regs[16] = 8'h13; regs[17] = 8'h14;
    regs[18] = 8'h15; regs[19] = 8'h16; regs[20] = 8'h17; regs[21] = 8'h18; regs[22] = 8'h19; regs[23] = 8'h1A;
    regs[24] = 8'h1B; regs[25] = 8'h1C; regs[26] = 8'h1D; regs[27] = 8'h1E; regs[28] = 8'h1F; regs[29] = 8'h20;
    regs[30] = 8'h21; regs[31] = 8'h22; regs[32] = 8'h23; regs[33] = 8'h24; regs[34] = 8'h25; regs[35] = 8'h26;
    regs[36] = 8'h27; regs[37] = 8'h2E; regs[38] = 8'h30; regs[39] = 8'h31; regs[40] = 8'h32; regs[41] = 8'h37;
  end
  always @(negedge clk) begin
    k = $random(seed) & 15;
    if (k < 12)      a <= {8'h00, regs[($random(seed) & 32'h7FFFFFFF) % 42]};
    else if (k < 14) a <= $random(seed) & 16'h003F;
    else             a <= $random(seed);
    d <= $random(seed);
    we <= $random(seed);
    rst <= (cyc < 3) || (($random(seed) & 1023) == 0);
    for (k = 0; k < 8; k = k + 1) junk[32 * k +: 32] <= $random(seed);
  end
`endif

`ifdef TRACE
  // trace (tools: hdl/sdr/README.md): first line "<clock> <we> <a> <d> <598 bits>" = the netlist state after that
  // clock edge, then one such line for every later clock at which a traced flip-flop changed (hex fields)
  integer fd, rc;
  reg [63:0] tclk, now;
  reg [597:0] tnl, snl;
  reg twe, swe;
  reg [15:0] ta, td, sa, sd;
  reg have;
  assign nl = snl;
  initial begin
    rst = 1'b0;
    fd = $fopen(`TRACE, "r");
    if (fd == 0) begin $display("no trace file"); $finish; end
    rc = $fscanf(fd, "%d %h %h %h %h\n", tclk, twe, ta, td, tnl);
    now = tclk; swe = twe; sa = ta; sd = td; snl = tnl;
    we = swe; a = sa; d = sd;
    rc = $fscanf(fd, "%d %h %h %h %h\n", tclk, twe, ta, td, tnl);
    have = (rc == 5);
  end
  // at the falling edge after RTL edge n: bring the netlist state to clock n, compare, then present the bus value
  // of clock n to the RTL's next edge (the netlist registers take the bus flip-flops' value one clock later)
  always @(negedge clk) begin
    now = now + 1;
    while (have && tclk <= now) begin
      swe = twe; sa = ta; sd = td; snl = tnl;
      rc = $fscanf(fd, "%d %h %h %h %h\n", tclk, twe, ta, td, tnl);
      have = (rc == 5);
    end
    if (rb !== snl) begin
      mism = mism + 1;
      if (mism < 10)
        for (k = 0; k < 598; k = k + 1)
          if (rb[k] !== snl[k]) $display("clock %0d: map entry %0d RTL %b netlist %b", now, k, rb[k], snl[k]);
    end
    if (swe) nwr = nwr + 1;
    we = swe; a = sa; d = sd;
    if (!have) begin
      $display("trace to clock %0d: %0d write strobes, %0d mismatching clocks against the whole netlist", now, nwr, mism);
      if (mism == 0) $display("PASS"); else $display("FAIL");
      $finish;
    end
  end
`endif

  always @(posedge clk) begin
    cyc <= cyc + 1;
`ifndef TRACE
    if (we) nwr <= nwr + 1;
`endif
  end
`ifndef TRACE
  always @(negedge clk) if (cyc > 4) begin
    if (rb !== nl) begin
      mism = mism + 1;
      if (mism < 10)
        for (k = 0; k < 598; k = k + 1)
          if (rb[k] !== nl[k]) $display("cyc %0d: map entry %0d RTL %b netlist %b (a %h d %h we %b rst %b)",
                                        cyc, k, rb[k], nl[k], a, d, we, rst);
    end
    if (cyc == `CYCLES) begin
      $display("%0d clocks: %0d writes, %0d mismatching clocks against the slice", cyc, nwr, mism);
      if (mism == 0) $display("PASS"); else $display("FAIL");
      $finish;
    end
  end
`endif
endmodule
`default_nettype wire
