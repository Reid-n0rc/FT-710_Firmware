// FT-710 SDR FPGA: second-stage window sum of the RX decimator (T24 SDR round 3; netlist.md 3.9), behavioural
// reconstruction of its data path.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104. The operand x is the 73-bit product of the second-stage MAC
// (DSP48_X1Y0..X1Y3, b x coefficient): bits 33..0 from the pipeline flip-flops of the low partial products
// (SLICE_X52Y0.., X53Y5.., X54Y5..), bits 72..34 = DSP48_X1Y3.P[38:0]. Two parts:
//
//   integrator   acc (73 bits, SLICE_X46Y0..Y18): acc <= 0 when r, else acc + x when ce (FDRE: the reset wins)
//   difference   two snapshots of x, sa under cea (SLICE_X30Y3/DLUT) and sb under ceb (SLICE_X31Y6/BLUT), 73 bits each
//                (SLICE_X41..X49Y0..Y17), and their difference d = (sa - sb)[71:25] (carry chain SLICE_X45Y0..Y18,
//                47 FDCE with the asynchronous clear SLICE_X35Y1/DFF, registered on every clock)
//
// So d is a scaled difference of two product samples taken at the two strobes. The control signals r, ce, cea, ceb
// come from the second-stage sequencer (SLICE_X12..X15Y3..Y22), which this block takes as inputs. Checked against
// its netlist slice on every clock (tb_rx_window_sum.v -DSTRUCT; hdl/sdr/README.md).
`default_nettype none
module ft710_rx_window_sum (
  input  wire        clk,
  input  wire [72:0] x,               // second-stage product
  input  wire        r,               // integrator clear (SLICE_X13Y13/CLUT)
  input  wire        ce,              // integrator enable (SLICE_X13Y13/DLUT)
  input  wire        cea,             // snapshot a enable (SLICE_X30Y3/DLUT)
  input  wire        ceb,             // snapshot b enable (SLICE_X31Y6/BLUT)
  input  wire        clr,             // asynchronous clear of the difference register (SLICE_X35Y1/DFF)
  output reg  [72:0] acc = 73'd0,
  output reg  [72:0] sa = 73'd0,
  output reg  [72:0] sb = 73'd0,
  output reg  [46:0] d = 47'd0
);
  wire [72:0] diff = sa - sb;
  always @(posedge clk) begin
    if (r)        acc <= 73'd0;
    else if (ce)  acc <= acc + x;
    if (cea) sa <= x;
    if (ceb) sb <= x;
  end
  always @(posedge clk or posedge clr)
    if (clr) d <= 47'd0;
    else     d <= diff[71:25];
endmodule
`default_nettype wire
