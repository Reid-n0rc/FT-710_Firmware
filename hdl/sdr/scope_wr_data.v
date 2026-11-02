// FT-710 SDR FPGA: data path of the scope RAM writer (T24 SDR round 2; netlist.md 5.6), behavioural reconstruction.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104 (cells cited in docs/code/sdr/netlist.md 5.6). Every
// 125 MHz clock it turns the scope sample x into the byte written into port A of RAMB18_X2Y21 (DIADI0..7):
//
//   s1 = lvl + x                    16-bit sum (carry chain SLICE_X41Y71..Y74), x a 14-bit signed sample
//   t  = (ref << sh) - s1/2         15-bit difference (SLICE_X38Y71..Y74): ~s1[15:1] + ref*2^sh + ~s1[0], i.e.
//                                   ref*2^sh - ceil(s1/2); ref is 8 bits signed, sh = 3 when g = 1, else 4
//   u  = t[12:2] (g = 1) or t[13:3] (g = 0), forced to 0 when t[13] (g = 1) or t[14] (g = 0) is set: one bit
//        serves as the sign, so with g = 1 a difference below -8192 is not caught; registered (11 FDCE, cleared by clr)
//   w  = u[10:1] + u[0], the round-up suppressed when u[10:1] = 0x3FF (SLICE_X45Y58)
//   dia = w > 255 ? 0xFE : w[7:0]   (SLICE_X58Y53/Y54: the clamp leaves bit 0 clear)
//
// So the byte is about ref - s1/16 (g = 1) or ref - s1/32 (g = 0), rounded, and clamped to 0 .. 0xFE. Which MAIN registers hold lvl, ref and g: docs/code/sdr/netlist.md 5.6.
// Checked against its netlist slice on every clock (tb_scope_wr_data.v -DSTRUCT; hdl/sdr/README.md).
`default_nettype none
module ft710_scope_wr_data (
  input  wire        clk,
  input  wire        clr,           // asynchronous clear of the value register (SLICE_X30Y70/AFF)
  input  wire [13:0] x,             // sample (SLICE_X41Y115/CFF .. SLICE_X41Y118/DFF), two's complement
  input  wire [15:0] lvl,           // register field added to the sample
  input  wire [7:0]  refv,          // register field: reference, two's complement
  input  wire        g,             // register bit: scale select (SLICE_X10Y81/CFF)
  output reg  [10:0] u = 11'd0,     // value register: {v[9:0], round}
  output wire [7:0]  dia            // RAM port-A data
);
  wire [15:0] s1 = lvl + {{2{x[13]}}, x};
  wire [14:0] rs = g ? {{4{refv[7]}}, refv, 3'b000} : {{3{refv[7]}}, refv, 4'b0000};
  wire [14:0] t  = ~s1[15:1] + rs + {14'd0, ~s1[0]};
  wire        neg = g ? t[13] : t[14];
  wire [10:0] un  = neg ? 11'd0 : (g ? t[12:2] : t[13:3]);
  always @(posedge clk or posedge clr)
    if (clr) u <= 11'd0;
    else     u <= un;
  wire [9:0]  v = u[10:1];
  wire [10:0] w = {1'b0, v} + {10'd0, u[0] & ~&v};
  assign dia = |w[10:8] ? 8'hFE : w[7:0];
endmodule
`default_nettype wire
