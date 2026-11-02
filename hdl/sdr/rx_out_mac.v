// FT-710 SDR FPGA: RX output multiply-accumulate (T24 SDR round 3; netlist.md 3.10), behavioural reconstruction.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104 (cells cited in docs/code/sdr/netlist.md 3.10). DSP48_X0Y11
// and DSP48_X0Y12 form one 25 x 32-bit product per clock (c x b2): X0Y11.P[16:0] is the low part, X0Y12.P[37:0] the
// rest shifted by 17. This block adds them into the 55-bit accumulator SLICE_X29Y26..Y39:
//
//   p_lo  X0Y11.P[16:0] registered once (SLICE_X28Y24.., X28Y26.., X28Y28.., X12Y26/27, X13Y30), so it lines up
//         with X0Y12.P, which is one stage later in the cascade
//   cnt   12-bit phase counter SLICE_X48Y12..Y14, +1 every clock, synchronously cleared by the output strobe
//         stb (SLICE_X29Y19/AFF, the same strobe latches acc[54:23] as the output word)
//   acc   at cnt = 24 (clear, SLICE_X49Y12/BLUT): acc = {P_hi, p_lo}; at cnt = 32 (SLICE_X49Y12/CLUT): acc += {P_hi,
//         p_lo}; held otherwise. So each output period sums the products of exactly two phases.
//
// No rounding or saturation (netlist.md 3.10: the output word is acc[54:23]). Checked against its netlist slice on
// every clock (tb_rx_out_mac.v -DSTRUCT; hdl/sdr/README.md).
`default_nettype none
module ft710_rx_out_mac (
  input  wire        clk,
  input  wire        stb,             // output strobe (SLICE_X29Y19/AFF)
  input  wire [16:0] p11,             // DSP48_X0Y11.P[16:0]
  input  wire [37:0] p12,             // DSP48_X0Y12.P[37:0]
  output reg  [11:0] cnt = 12'd0,
  output reg  [16:0] p_lo = 17'd0,
  output reg  [54:0] acc = 55'd0
);
  wire [54:0] p = {p12, p_lo};
  always @(posedge clk) begin
    p_lo <= p11;
    cnt  <= stb ? 12'd0 : cnt + 12'd1;
    if (cnt == 12'd24)      acc <= p;
    else if (cnt == 12'd32) acc <= acc + p;
  end
endmodule
`default_nettype wire
