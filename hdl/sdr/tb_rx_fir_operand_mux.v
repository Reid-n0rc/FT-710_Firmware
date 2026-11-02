// Testbench (T24 SDR round 3): ft710_rx_fir_operand_mux (pre-adders, operand mux and b register; netlist.md 3.9).
//
// Without STRUCT: the RTL alone against an integer reference. With STRUCT it also instantiates `ft710_slice` written by
//   python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice rx_fir_operand build/sdr/sim/rx_fir_operand.v
// (seeds: the 33 b and 33 bd flip-flops; depth 1, so the 16 SRLC32E in front of bd[32:17] are in the slice; stops: the 12 select LUTs, the CE and reset LUTs and other-ffs, so
// the selects, ce, rst, the register sources and the delay-line RAM output pins are slice inputs). On every clock the
// RAM words and register sources get new random values, the selects are one-hot (three clocks in four, as in the
// whole-netlist schedule of netlist.md 3.9) or random, ce is high on half of the clocks and rst is rare; the 112 other
// inputs (other halves of shared LUT6_2s, LUTs and SRLs of other logic) get random bits. All 66 flip-flops are
// compared on every clock. Port list: tb_rx_fir_operand_mux_ports.vh (generated in round 3; cell names only).
`timescale 1ns/1ps
`default_nettype none
module tb_rx_fir_operand_mux;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg  [31:0] ca [0:3];
  reg  [31:0] cb [0:3];
  reg  [31:0] rs [0:7];
  reg  [11:0] sel = 0;
  reg         ce = 1'b0, rst = 1'b1;
  reg  [111:0] junk = 0;
  wire [32:0] b, bd;
  ft710_rx_fir_operand_mux dut (.clk(clk), .ca({ca[3], ca[2], ca[1], ca[0]}), .cb({cb[3], cb[2], cb[1], cb[0]}),
    .rs({rs[7], rs[6], rs[5], rs[4], rs[3], rs[2], rs[1], rs[0]}), .sel(sel), .ce(ce), .rst(rst), .b(b), .bd(bd));

  integer errors = 0, mism = 0, cyc = 0, seed = 71, i;
`ifndef CYCLES
`define CYCLES 1000000
`endif
  initial for (i = 0; i < 8; i = i + 1) begin rs[i] = 0; if (i < 4) begin ca[i] = 0; cb[i] = 0; end end
  // reference
  reg [32:0] rb = 0, rbd = 0, mm, ss;
  reg [15:0] rsrl = 0;
  always @(posedge clk) begin
    mm = 0;
    for (i = 0; i < 4; i = i + 1) if (sel[i]) begin ss = $signed(ca[i]) + $signed(cb[i]); mm = mm | ss; end
    for (i = 0; i < 8; i = i + 1) if (sel[4 + i]) mm = mm | {rs[i][31], rs[i]};
    if (rst) rb <= 0; else if (ce) rb <= mm;
    rsrl <= rb[32:17];
    rbd <= {rsrl, rb[16:0]};
  end

`ifdef STRUCT
  wire [32:0] nb, nbd;
  ft710_slice sl (
`include "tb_rx_fir_operand_mux_ports.vh"
  );
`endif

  always @(negedge clk) begin
    for (i = 0; i < 4; i = i + 1) begin ca[i] <= $random(seed); cb[i] <= $random(seed); end
    for (i = 0; i < 8; i = i + 1) rs[i] <= $random(seed);
    junk <= {$random(seed), $random(seed), $random(seed), $random(seed)};
    if ($random(seed) & 3) sel <= 12'd1 << ({$random(seed)} % 12); else sel <= $random(seed);
    ce <= $random(seed) & 1;
    rst <= (cyc < 2) || (($random(seed) & 255) == 0);
  end
  always @(posedge clk) begin
    cyc <= cyc + 1;
    #1;
    if (cyc > 2) begin
      if (b !== rb || bd !== rbd) begin
        errors = errors + 1;
        if (errors < 10) $display("RTL  cyc %0d: b %h exp %h", cyc, b, rb);
      end
`ifdef STRUCT
      if (nb !== b || nbd !== bd) begin
        mism = mism + 1;
        if (mism < 10) $display("SLICE cyc %0d sel %h: b %h slice %h  bd %h slice %h", cyc, sel, b, nb, bd, nbd);
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
