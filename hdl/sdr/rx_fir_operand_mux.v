// FT-710 SDR FPGA: operand register of the RX decimator's second-stage MAC (T24 SDR round 3; netlist.md 3.9),
// behavioural reconstruction of the pre-adders, the one-hot operand mux and the b register.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104 (cells cited in docs/code/sdr/netlist.md 3.9):
//
//   pre-adders  four 32-bit carry chains (SLICE_X8Y9..Y16, X44Y10..Y17, X14Y9..Y16, X36Y5..Y12), each the sum of two
//               words read from the delay-line RAMs (RAMB18_X0Y0..X0Y9, X1Y2..X1Y7), as two's complement: the 33-bit
//               signed sum ca[i] + cb[i]. The netlist forms bit 32 from the carry chain: bit 31 has DI = ~a31, so the
//               carry out is the inverted sign of the 33-bit sum, passed by one more CARRY4 stage (S = 1, DI = 0) and
//               inverted again in the select LUTs SLICE_X36Y17/BLUT, X37Y14/BLUT (the bit the CARRY4 fix of #232
//               restored)
//   mux         an AND-OR of the four sums and eight 32-bit register sources rs[0..7], one select each (sel[0..3] for
//               the sums: SLICE_X14Y6/ALUT, X15Y8/CLUT, X15Y6/ALUT, X30Y11/CLUT; sel[4..11] for the registers:
//               X29Y4/BLUT, X34Y7/B,C,DLUT, X34Y8/C,DLUT, X31Y5/B,CLUT); a register source is sign-extended to bit 32
//   b           33 flip-flops (SLICE_X37Y5.., DSP48_X1Y0/X1Y1 B inputs, bits 34..32 one flip-flop), synchronous reset
//               rst (SLICE_X15Y11/CLUT) over enable ce (SLICE_X29Y10/BLUT)
//   bd          b one clock later for bits 16..0 (SLICE_X53Y5.., B of DSP48_X1Y2) and two clocks later for bits
//               32..17 (an SRLC32E at address 0 plus a flip-flop, SLICE_X52Y5, X50Y8; B of DSP48_X1Y3), which lines
//               the four partial products up
//
// The selects, ce and rst are decoded from the second-stage sequencer (SLICE_X12Y5, X12Y7, X13Y6, X13Y7), which this
// block takes as inputs. Which RAM pin is which bit of ca/cb (the RAMB36 byte interleave of netlist.md 4.4) is in
// the generated port list of the testbench. Checked against its netlist slice on every clock
// (tb_rx_fir_operand_mux.v -DSTRUCT; hdl/sdr/README.md).
`default_nettype none
module ft710_rx_fir_operand_mux (
  input  wire          clk,
  input  wire [4*32-1:0] ca,          // pre-adder operand on the carry chain's DI side, chain i = bits 32i+31..32i
  input  wire [4*32-1:0] cb,          // the other pre-adder operand
  input  wire [8*32-1:0] rs,          // register sources, j = bits 32j+31..32j
  input  wire [11:0]   sel,
  input  wire          ce,
  input  wire          rst,
  output reg  [32:0]   b = 33'd0,
  output reg  [32:0]   bd = 33'd0
);
  reg [32:0] m, sum;
  reg [15:0] srl = 16'd0;               // SRLC32E delay (address 0) in front of bd[32:17]
  integer i;
  always @* begin
    m = 33'd0;
    for (i = 0; i < 4; i = i + 1)
      if (sel[i]) begin
        sum = {ca[32 * i + 31], ca[32 * i +: 32]} + {cb[32 * i + 31], cb[32 * i +: 32]};
        m = m | sum;
      end
    for (i = 0; i < 8; i = i + 1)
      if (sel[4 + i]) m = m | {rs[32 * i + 31], rs[32 * i +: 32]};
  end
  always @(posedge clk) begin
    if (rst)     b <= 33'd0;
    else if (ce) b <= m;
    srl <= b[32:17];
    bd <= {srl, b[16:0]};
  end
endmodule
`default_nettype wire
