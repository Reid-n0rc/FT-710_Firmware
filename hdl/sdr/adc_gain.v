// ft710_adc_gain: per-channel gain, rounding, saturation and test override of the FT-710 SDR FPGA (T24, #172).
//
// Re-implements the netlist cells between the DC-free word y of ft710_adc_dc and the B operands of the channel's
// mixer DSPs (docs/code/sdr/netlist.md 3.7):
//
//   a <= y, b <= g                  DSP48 A/B registers (AREG = BREG = 1)
//   P <= a * b                      DSP48 multiply, PREG = 1 (y 24-bit signed, g 16-bit unsigned = MAIN reg 0x12/0x13)
//   pr <= P[41:0]                   fabric register (async clear)
//   r  = pr[41:15] + inc            round at bit 15, half away from zero: inc = pr[14] & |pr[13:0] for a negative
//                                   product, inc = pr[14] for a positive one except when pr[40:15] is all ones (the
//                                   increment would wrap); 27-bit carry chain
//   s  <= sat24(r)                  saturate symmetrically to +/-(2^23 - 1) (async clear)
//   o  <= (v != 0) ? {v, 16'h0} : s an 8-bit register field v replaces the word by v * 2^16 while it is non-zero
//
// o is the 24-bit mixer operand: bits 16..0 go to B16..B0 of the low partial product DSP (DSP48_X1Y34/X1Y38 for A,
// DSP48_X0Y34/X0Y36 for B), bits 23..17 to B6..B0 of the high one (B17..B6 = bit 23). With MAIN's gain 0x8000 the
// stage passes y unchanged (0x8000 = unity): P = y * 2^15, pr[41:15] = y.
//
// Cells (channel A): DSP48_X1Y26, pr SLICE_X44Y62/63, X46Y65, X39Y65/66, X38Y66/67, X37Y69, X40Y63; round chain
// SLICE_X37Y65..X37Y71; s SLICE_X37Y72, X38Y75, X39Y70..X39Y74, X37Y71/CFF; o the 24 mixer-operand flip-flops
// (SLICE_X39Y75..X41Y79, X40Y71/AFF). v (A) = register bits SLICE_X40Y72/C5FF (bit 7), X40Y72/DFF, X36Y60/BFF,
// X43Y72/BFF, X40Y72/CFF, X40Y72/BFF, X43Y72/DFF, X43Y72/CFF (bit 0), one register-bank word; arst is SLICE_X4Y43/BFF.
//
// Verified cycle by cycle against the netlist slices of both channels by hdl/sdr/tb_adc_gain.v -DSTRUCT (commands in
// hdl/sdr/README.md). Derived from the recovered netlist; contains no bitstream data.
`default_nettype none
module ft710_adc_gain (
  input  wire        clk,             // 125 MHz fabric clock
  input  wire        arst,            // asynchronous clear of pr and s
  input  wire [23:0] y,               // DC-free sample (ft710_adc_dc)
  input  wire [15:0] g,               // gain, unsigned (0x8000 = MAIN's RX value)
  input  wire [7:0]  v,               // override field: 0 = pass the sample
  output reg  [23:0] o                // mixer operand
);
  reg  signed [23:0] a;
  reg         [15:0] b;
  reg  signed [47:0] p;
  always @(posedge clk) begin
    a <= y;
    b <= g;
    p <= a * $signed({1'b0, b});
  end

  reg  [41:0] pr;
  reg  [23:0] s;
  wire        neg = pr[41];
  wire        inc = neg ? (pr[14] & |pr[13:0]) : (pr[14] & ~&pr[40:15]);
  wire [26:0] r   = pr[41:15] + {26'd0, inc};
  // symmetric clamp to +/-(2^23 - 1): -2^23 itself also becomes -(2^23 - 1)
  wire        pos_ovf = ~r[26] & |r[25:23];
  wire        neg_ovf = r[26] & (~&r[25:23] | ~|r[22:0]);
  wire [23:0] sat = pos_ovf ? 24'h7FFFFF : neg_ovf ? 24'h800001 : r[23:0];
  always @(posedge clk or posedge arst)
    if (arst) begin
      pr <= 42'd0;
      s  <= 24'd0;
    end else begin
      pr <= p[41:0];
      s  <= sat;
    end

  always @(posedge clk)
    o <= (v != 8'd0) ? {v, 16'd0} : s;
endmodule
`default_nettype wire
