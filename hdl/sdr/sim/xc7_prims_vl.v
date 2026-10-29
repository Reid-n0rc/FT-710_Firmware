// Minimal functional models of the 7-series primitives used by the recovered FT-710 SDR netlist (T15e).
//
// Written for Verilator 5 (cycle-based, single 125 MHz domain): Yosys' cells_sim.v trips Verilator 5.006 on
// CARRY4 with constant inputs (V3Gate internal error), so the small primitives are re-modelled here. DSP48E1 still
// comes from Yosys (extracted from cells_sim.v with the $fatal mode checks removed, see hdl/sdr/README.md); the block
// RAMs are in xc7_bram_vl.v (#164). No timing, no X propagation, flip-flops start at INIT. Not for synthesis.
/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */
/* verilator lint_off MULTIDRIVEN */
`default_nettype none
module LUT6 #(parameter [63:0] INIT = 64'h0)
  (output wire O, input wire I0, I1, I2, I3, I4, I5);
  assign O = INIT[{I5, I4, I3, I2, I1, I0}];
endmodule
module LUT6_2 #(parameter [63:0] INIT = 64'h0)
  (output wire O6, output wire O5, input wire I0, I1, I2, I3, I4, I5);
  assign O6 = INIT[{I5, I4, I3, I2, I1, I0}];
  assign O5 = INIT[{1'b0, I4, I3, I2, I1, I0}];
endmodule
module MUXF7 (output wire O, input wire I0, I1, S); assign O = S ? I1 : I0; endmodule
module MUXF8 (output wire O, input wire I0, I1, S); assign O = S ? I1 : I0; endmodule
module CARRY4 (output wire [3:0] CO, output wire [3:0] O, input wire CI, CYINIT, input wire [3:0] DI, S);
  wire c0 = CI | CYINIT;
  wire c1 = S[0] ? c0 : DI[0];
  wire c2 = S[1] ? c1 : DI[1];
  wire c3 = S[2] ? c2 : DI[2];
  wire c4 = S[3] ? c3 : DI[3];
  assign CO = {c4, c3, c2, c1};
  assign O = S ^ {c3, c2, c1, c0};
endmodule
module FDRE #(parameter [0:0] INIT = 1'b0, parameter [0:0] IS_C_INVERTED = 1'b0)
  (output reg Q = INIT, input wire C, CE, R, D);
  // all clocks of interest are non-inverted; IS_C_INVERTED is honoured by the caller-side check in the testbench
  always @(posedge C) if (R) Q <= 1'b0; else if (CE) Q <= D;
endmodule
module FDSE #(parameter [0:0] INIT = 1'b1, parameter [0:0] IS_C_INVERTED = 1'b0)
  (output reg Q = INIT, input wire C, CE, S, D);
  always @(posedge C) if (S) Q <= 1'b1; else if (CE) Q <= D;
endmodule
module FDCE #(parameter [0:0] INIT = 1'b0, parameter [0:0] IS_C_INVERTED = 1'b0)
  (output reg Q = INIT, input wire C, CE, CLR, D);
  always @(posedge C or posedge CLR) if (CLR) Q <= 1'b0; else if (CE) Q <= D;
endmodule
module FDPE #(parameter [0:0] INIT = 1'b1, parameter [0:0] IS_C_INVERTED = 1'b0)
  (output reg Q = INIT, input wire C, CE, PRE, D);
  always @(posedge C or posedge PRE) if (PRE) Q <= 1'b1; else if (CE) Q <= D;
endmodule
module SRLC32E #(parameter [31:0] INIT = 32'h0, parameter [0:0] IS_CLK_INVERTED = 1'b0)
  (output wire Q, output wire Q31, input wire [4:0] A, input wire CE, CLK, D);
  reg [31:0] r = INIT;
  assign Q = r[A];
  assign Q31 = r[31];
  always @(posedge CLK) if (CE) r <= {r[30:0], D};
endmodule
module RAMD64E #(parameter [63:0] INIT = 64'h0, parameter [0:0] IS_CLK_INVERTED = 1'b0)
  (output wire O, input wire CLK, I, WE, RADR0, RADR1, RADR2, RADR3, RADR4, RADR5,
   input wire WADR0, WADR1, WADR2, WADR3, WADR4, WADR5, WADR6, WADR7);
  reg [63:0] mem = INIT;
  assign O = mem[{RADR5, RADR4, RADR3, RADR2, RADR1, RADR0}];
  always @(posedge CLK) if (WE) mem[{WADR5, WADR4, WADR3, WADR2, WADR1, WADR0}] <= I;
endmodule
module RAMD32 #(parameter [31:0] INIT = 32'h0, parameter [0:0] IS_CLK_INVERTED = 1'b0)
  (output wire O, input wire CLK, I, WE, RADR0, RADR1, RADR2, RADR3, RADR4,
   input wire WADR0, WADR1, WADR2, WADR3, WADR4);
  reg [31:0] mem = INIT;
  assign O = mem[{RADR4, RADR3, RADR2, RADR1, RADR0}];
  always @(posedge CLK) if (WE) mem[{WADR4, WADR3, WADR2, WADR1, WADR0}] <= I;
endmodule
// clock buffers: pass-through (the 125 MHz tree is one clock)
module BUFGCTRL (output wire O, input wire CE0, CE1, I0, I1, IGNORE0, IGNORE1, S0, S1);
  // the recovered netlist leaves unrouted S0/S1/I1 pins at their tie value 1, so S1 = 1 does not mean "select I1";
  // every used BUFGCTRL is fed on I0 only
  assign O = I0;
endmodule
module BUFHCE (output wire O, input wire CE, I); assign O = I; endmodule
module BUFIO (output wire O, input wire I); assign O = I; endmodule
module BUFR #(parameter BUFR_DIVIDE = "BYPASS") (output wire O, input wire CE, CLR, I); assign O = I; endmodule
module MMCME2_ADV #(parameter DIVCLK_DIVIDE = 1, parameter real CLKFBOUT_MULT_F = 5.0,
                    parameter real CLKOUT0_DIVIDE_F = 1.0, parameter real CLKIN1_PERIOD = 0.0)
  (input wire CLKIN1, CLKIN2, CLKFBIN, RST, PWRDWN, CLKINSEL, DCLK, DEN, DWE, PSCLK, PSEN, PSINCDEC,
   input wire [6:0] DADDR, input wire [15:0] DI,
   output wire CLKOUT0, CLKOUT1, CLKOUT2, CLKOUT3, CLKOUT4, CLKOUT5, CLKOUT6, CLKFBOUT, LOCKED);
  // stand-in: output = input clock (frequency not modelled), always locked
  assign CLKOUT0 = CLKIN1; assign CLKFBOUT = CLKIN1; assign LOCKED = 1'b1;
  assign {CLKOUT1, CLKOUT2, CLKOUT3, CLKOUT4, CLKOUT5, CLKOUT6} = 6'b0;
endmodule
// I/O
module IBUF #(parameter IOSTANDARD = "DEFAULT") (output wire O, input wire I); assign O = I; endmodule
module IBUFDS #(parameter IOSTANDARD = "DEFAULT", parameter DIFF_TERM = "FALSE")
  (output wire O, input wire I, IB); assign O = I; endmodule
module OBUF #(parameter IOSTANDARD = "DEFAULT") (output wire O, input wire I); assign O = I; endmodule
module OBUFTDS #(parameter IOSTANDARD = "DEFAULT") (output wire O, OB, input wire I, T);
  assign O = I; assign OB = ~I;          // enable ignored (no tri-state in a cycle simulator)
endmodule
module IOBUF #(parameter IOSTANDARD = "DEFAULT") (output wire O, inout wire IO, input wire I, T);
  assign O = IO;                         // the testbench drives the pad; output side not modelled
endmodule
module IDDR #(parameter DDR_CLK_EDGE = "OPPOSITE_EDGE", parameter SRTYPE = "SYNC",
              parameter [0:0] INIT_Q1 = 1'b0, parameter [0:0] INIT_Q2 = 1'b0)
  (output reg Q1 = INIT_Q1, output reg Q2 = INIT_Q2, input wire C, CE, D, R, S);
  always @(posedge C) if (CE) begin Q1 <= D; Q2 <= D; end   // single-edge stand-in
endmodule
module ODDR #(parameter DDR_CLK_EDGE = "OPPOSITE_EDGE", parameter SRTYPE = "SYNC", parameter [0:0] INIT = 1'b0)
  (output reg Q = INIT, input wire C, CE, D1, D2, R, S);
  always @(posedge C) if (CE) Q <= D1;                         // single-edge stand-in
endmodule
`default_nettype wire
