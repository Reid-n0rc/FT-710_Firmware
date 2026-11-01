// ft710_adc_combine: the channel A + B combine of the FT-710 SDR FPGA RX path at 5 MSPS (T24, #172).
//
// Re-implements the netlist cells of docs/code/sdr/netlist.md 3.7 ("The two channels are added after mixing and
// decimation"): the operand registers of the two output words (I and Q), the two 32-bit adders, the per-bit output
// mux under MAIN register 0x04 bits 11 (s) and 10 (t), and the hysteresis level flag u.
//
//   a_k, b_k <= srst ? 0 : ce ? a_k_d, b_k_d          channel A / channel B words, k = 0, 1 (FDRE, R before CE)
//   out_k    <= srst ? 0 : ce ? sel(s, t, u) : hold   s t u:  0 1 x -> a_k + b_k   1 0 1 -> a_k * 8   else -> b_k
//   s, t     <= register bits (one more flip-flop each), level l <= l_d (17 bits, every clock)
//   u        <= (l[16:1] > thr) | u & ~(l[15:0] < thr)  set above 2 * thr, cleared below thr
//
// ce is the 5 MSPS strobe (SLICE_X52Y107/DLUT, every 25th clock), srst the block's synchronous reset
// (SLICE_X50Y112/A5FF). Cells: adders SLICE_X46Y88..Y95 (k = 0) and SLICE_X55Y107..Y114 (k = 1), output flip-flops
// SLICE_X44Y90..X45Y95, X49Y90, X56Y89 (k = 0) and SLICE_X53Y109..X57Y114, X56Y98 (k = 1), s = SLICE_X41Y74/AFF
// (from reg 0x04 bit 11 via SLICE_X40Y70/A5FF and a LUT), t = SLICE_X40Y79/A5FF (reg 0x04 bit 10, SLICE_X40Y70/AFF),
// u = SLICE_X52Y88/AFF with the comparators SLICE_X48Y85/86 (clear) and SLICE_X50Y85/86 (set), level register
// SLICE_X51Y100..Y104, threshold register bits SLICE_X38Y76, X28Y79, X14Y80 (bit order in tb_adc_combine.v).
//
// Verified cycle by cycle against the netlist slice by hdl/sdr/tb_adc_combine.v -DSTRUCT (commands in
// hdl/sdr/README.md). Derived from the recovered netlist; contains no bitstream data.
`default_nettype none
module ft710_adc_combine (
  input  wire        clk,             // 125 MHz fabric clock
  input  wire        srst,            // synchronous reset (operands and outputs)
  input  wire        ce,              // 5 MSPS sample strobe
  input  wire [31:0] a0_d, b0_d,      // next channel A / B words, output 0
  input  wire [31:0] a1_d, b1_d,      // next channel A / B words, output 1
  input  wire        s_d, t_d,        // reg 0x04 bit 11 / bit 10 (before their flip-flop)
  input  wire [16:0] l_d,             // channel B level word (before its register)
  input  wire [15:0] thr,             // level threshold (register bits)
  output reg  [31:0] out0, out1,
  output reg         u                // level flag
);
  reg [31:0] a0, b0, a1, b1;
  reg        s, t;
  reg [16:0] l;
  always @(posedge clk) begin
    if (srst) begin
      a0 <= 32'd0; b0 <= 32'd0; a1 <= 32'd0; b1 <= 32'd0;
    end else if (ce) begin
      a0 <= a0_d; b0 <= b0_d; a1 <= a1_d; b1 <= b1_d;
    end
    s <= s_d;
    t <= t_d;
    l <= l_d;
    u <= (l[16:1] > thr) | (u & ~(l[15:0] < thr));
  end

  wire sum  = ~s & t;
  wire x8   = s & ~t & u;
  function [31:0] sel(input [31:0] a, input [31:0] b);
    sel = sum ? a + b : x8 ? {a[28:0], 3'b000} : b;
  endfunction
  always @(posedge clk)
    if (srst) begin
      out0 <= 32'd0; out1 <= 32'd0;
    end else if (ce) begin
      out0 <= sel(a0, b0);
      out1 <= sel(a1, b1);
    end
endmodule
`default_nettype wire
