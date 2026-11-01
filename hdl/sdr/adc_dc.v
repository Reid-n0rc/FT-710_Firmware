// ft710_adc_dc: ADC capture pipeline and DC removal of one channel of the FT-710 SDR FPGA (T24, #172).
//
// Re-implements the netlist cells of docs/code/sdr/netlist.md 3.7 for one ADC channel, from the IDDR outputs to the
// DC-free 24-bit word that the per-channel gain DSP (DSP48_X1Y26 for A, DSP48_X0Y17 for B) takes on its A port:
//
//   adc (14 bit, two's complement, one word per 125 MHz clock: the 7 IDDR pairs, Q1 = bit 2k, Q2 = bit 2k+1)
//     -> SRLC32E with static address 1 (2 clocks), one flip-flop, the x register (sync reset): x = adc delayed 4
//     -> d  = x*2^9 - dc                         (24-bit carry chain, combinational)
//     -> acc <= acc + sext(d)                    (44-bit accumulator, sync reset)   dc = acc[43:20]
//     -> y  <= x*2^9 - (en ? dc : 0)             (24-bit carry chain into a register, sync reset)
//
// so dc follows the input with a time constant of 2^20 samples (8.4 ms at 125 MSPS) and y is the input with its DC
// removed. Cells (channel A): SRLs SLICE_X46Y56/X46Y59, x register SLICE_X45Y58..X45Y61, d chain SLICE_X44Y55..X44Y60,
// accumulator SLICE_X47Y54..X47Y64, y chain and register SLICE_X45Y59..X45Y64; channel B: SRLs SLICE_X52Y66/X56Y65,
// d SLICE_X6Y41..X6Y46, acc SLICE_X7Y41..X7Y51, y SLICE_X11Y41..X11Y46. en is SLICE_X38Y63/AFF (shared by both
// channels), rst the design's synchronous reset flop SLICE_X4Y43/CFF.
//
// Verified cycle by cycle against the netlist slices of both channels by hdl/sdr/tb_adc_dc.v -DSTRUCT (commands in
// hdl/sdr/README.md). Derived from the recovered netlist; contains no bitstream data.
`default_nettype none
module ft710_adc_dc #(
  parameter XDELAY = 4                // clocks from the IDDR outputs to the x register (SRL 2 + FF + x register)
) (
  input  wire        clk,             // 125 MHz fabric clock (BUFHCE from BUFGCTRL_X0Y16)
  input  wire        rst,             // synchronous reset of x, acc and y
  input  wire        en,              // 1: subtract the tracked DC (reset state of the register bit is 1)
  input  wire [13:0] adc,             // ADC word as the IDDRs present it (two's complement)
  output reg  [23:0] y,               // x*2^9 - en*dc, registered
  output wire [23:0] dc               // tracked DC = acc[43:20] (for tests)
);
  // capture pipeline: XDELAY-1 plain registers (SRL taps and the first flip-flop), then the x register with reset
  reg [13:0] pipe [0:XDELAY-2];
  reg [13:0] x;
  integer i;
  always @(posedge clk) begin
    pipe[0] <= adc;
    for (i = 1; i < XDELAY - 1; i = i + 1) pipe[i] <= pipe[i - 1];
    x <= rst ? 14'd0 : pipe[XDELAY - 2];
  end

  reg  [43:0] acc;
  assign dc = acc[43:20];
  wire [23:0] xw = {x[13], x, 9'd0};
  wire [23:0] d  = xw - dc;
  always @(posedge clk) begin
    acc <= rst ? 44'd0 : acc + {{20{d[23]}}, d};
    y   <= rst ? 24'd0 : xw - (en ? dc : 24'd0);
  end
endmodule
`default_nettype wire
