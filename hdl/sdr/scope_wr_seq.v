// FT-710 SDR FPGA: sequencer of the scope RAM writer (T24 SDR round 3; netlist.md 5.6), behavioural reconstruction.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104. The writer is run by a 16-bit state counter s (16 FDRE, INIT
// 1: SLICE_X30Y125..Y127, X31Y126/Y127, X33Y124; bits 0..12 in the order of the incrementer SLICE_X32Y123..Y125, bits
// 13..15 = SLICE_X31Y126/AFF, X30Y126/BFF, X30Y126/AFF). Its next state, from the exhaustive evaluation of the 16
// next-state cones over all 2^16 states and the five condition inputs (T24 round 3):
//
//   rst = ~i0 & i1 (SLICE_X29Y120/ALUT)    s = 0
//   i0 = 1                                  s holds
//   s = 0xFFFF                              holds (the power-up state: the writer idles until the first rst)
//   s = 0x0072                              0x0070 if eq, else 0x0073 (a loop until the 12-bit compare eq)
//   s = 0x0098                              0x0099 if cr, else holds
//   s = 0x00B2                              ca & cc & ~cd: 0x0090; ca otherwise: 0x00F0; ~ca & cc & ~cd: 0xFF9F;
//                                           ~ca otherwise: 0xFFFF (the end of a pass back to idle)
//   any other state                         s + 1
//
// i0 = SLICE_X10Y117/D5FF and i1 = SLICE_X31Y112/AFF are flip-flops of other logic (D cones from SLICE_X29Y70 and
// SLICE_X31Y112's own block); the conditions are compares of the writer's other counters: eq = SLICE_X7Y117/CARRY4
// CO[3] (the counter SLICE_X10Y119..Y121 against SLICE_X8Y121/Y122, X9Y124), cr = SLICE_X8Y121/CARRY4 CO[1] (a
// compare with the register copy SLICE_X28Y74..Y76), ca, cc, cd = SLICE_X33Y128/ALUT, CLUT, DLUT (decodes of the
// counter SLICE_X31Y122..Y124). The states the address side decodes (scope_wr_addr.v: 0x0082 load, 0x00A4 / 0x00AA
// write, 0x00A8 / 0x00B1 write enable, 0x00B1 step) lie in the loop 0x0090 .. 0x00B2. Checked against its netlist
// slice on every clock (tb_scope_wr_seq.v -DSTRUCT; hdl/sdr/README.md).
`default_nettype none
module ft710_scope_wr_seq (
  input  wire        clk,
  input  wire        i0,            // SLICE_X10Y117/D5FF
  input  wire        i1,            // SLICE_X31Y112/AFF
  input  wire        eq,            // SLICE_X7Y117/CARRY4 CO[3]
  input  wire        cr,            // SLICE_X8Y121/CARRY4 CO[1]
  input  wire        ca,            // SLICE_X33Y128/ALUT
  input  wire        cc,            // SLICE_X33Y128/CLUT
  input  wire        cd,            // SLICE_X33Y128/DLUT
  output reg  [15:0] s = 16'hFFFF
);
  wire rst = ~i0 & i1;
  always @(posedge clk)
    if (rst)
      s <= 16'h0000;
    else if (!i0)
      case (s)
        16'hFFFF: s <= 16'hFFFF;
        16'h0072: s <= eq ? 16'h0070 : 16'h0073;
        16'h0098: if (cr) s <= 16'h0099;
        16'h00B2: s <= ca ? ((cc & ~cd) ? 16'h0090 : 16'h00F0) : ((cc & ~cd) ? 16'hFF9F : 16'hFFFF);
        default:  s <= s + 16'd1;
      endcase
endmodule
`default_nettype wire
