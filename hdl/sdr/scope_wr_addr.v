// FT-710 SDR FPGA: address and write-enable side of the scope RAM writer (T24 SDR round 3; netlist.md 5.6),
// behavioural reconstruction.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104. Together with ft710_scope_wr_data (the byte) this drives
// port A of the scope RAM RAMB18_X2Y21: ADDRARDADDR12..3 = idx (SLICE_X41Y120 A..D/A5..D5, X38Y123/BFF,
// X37Y120/AFF), ADDRARDADDR13 = bank (SLICE_X41Y110/AFF), WEA0..3 = ENARDEN = we (SLICE_X35Y127/BFF).
//
// It follows the writer's sequencer, a 16-bit state register s (SLICE_X30Y125..Y127, X31Y126/Y127, X33Y124; bit order
// of its incrementer SLICE_X32Y123..Y125), which this block takes as an input. Every decode below compares the whole
// state with one value, gated by run = ~i0 & ~i1 (i0 = SLICE_X10Y117/D5FF, i1 = SLICE_X31Y112/AFF):
//
//   s = 0x0082   load: both index counters to 425 (SLICE_X31Y121/DLUT on the FDSE/FDRE set/reset pins)
//   s = 0x00B1   step: cup + 1, cdn - 1 (SLICE_X34Y122/BLUT; cup = SLICE_X35Y120..Y122, cdn = SLICE_X40Y120..Y122)
//   s = 0x00A4   idx = cdn, bank = ~serializer bank (SLICE_X33Y119/ALUT enable, SLICE_X35Y127/CLUT select)
//   s = 0x00AA   idx = cup, bank = ~serializer bank
//
// so each pass of the sequence writes 425 - k and then 425 + k (the centre-out sweep of netlist.md 5.6) into the bank
// the serializer is not reading. we is set in the states 0x00A8 and 0x00B1 while i1 = 0, held in 23 other states
// (0x0001, 0x0002, 0x000C, 0x0014, 0x0018, 0x001F, 0x0020, 0x0022, 0x0024, 0x006A, 0x006C, 0x0070, 0x0072, 0x0080,
// 0x0082, 0x0090, 0x0093, 0x0098, 0x009B, 0x00A0, 0x00A4, 0x00AA, 0xFFFF), and in every other state held only while
// i1 = 1; i0 clears it asynchronously (FDCE). These sets are the exhaustive evaluation of the netlist's LUT cones over
// all 2^16 states (T24 round 3). Checked against its netlist slice on every clock (tb_scope_wr_addr.v -DSTRUCT;
// hdl/sdr/README.md).
`default_nettype none
module ft710_scope_wr_addr (
  input  wire       clk,
  input  wire [15:0] s,            // sequencer state
  input  wire       i0,            // SLICE_X10Y117/D5FF (also the asynchronous clear of we)
  input  wire       i1,            // SLICE_X31Y112/AFF
  input  wire       rbank,         // the serializer's bank flip-flop SLICE_X34Y53/AFF
  output reg  [9:0] cup = 10'd0,   // up counter
  output reg  [9:0] cdn = 10'd0,   // down counter
  output reg  [9:0] idx = 10'd0,   // RAM index (port-A address bits 12..3)
  output reg        bank = 1'b0,   // RAM bank (port-A address bit 13)
  output reg        we = 1'b0      // port-A write enable
);
  localparam [9:0] CENTRE = 10'd425;
  wire run = ~i0 & ~i1;
  reg we_set, we_hold;
  always @* begin
    we_set = (s == 16'h00A8) || (s == 16'h00B1);
    case (s)
      16'h0001, 16'h0002, 16'h000C, 16'h0014, 16'h0018, 16'h001F, 16'h0020, 16'h0022, 16'h0024, 16'h006A, 16'h006C,
      16'h0070, 16'h0072, 16'h0080, 16'h0082, 16'h0090, 16'h0093, 16'h0098, 16'h009B, 16'h00A0, 16'h00A4, 16'h00AA,
      16'hFFFF: we_hold = 1'b1;
      default:  we_hold = 1'b0;
    endcase
  end
  always @(posedge clk) begin
    if (run && s == 16'h0082) begin
      cup <= CENTRE;
      cdn <= CENTRE;
    end else if (run && s == 16'h00B1) begin
      cup <= cup + 10'd1;
      cdn <= cdn - 10'd1;
    end
    if (run && (s == 16'h00A4 || s == 16'h00AA)) begin
      idx  <= (s == 16'h00A4) ? cdn : cup;
      bank <= ~rbank;
    end
  end
  always @(posedge clk or posedge i0)
    if (i0) we <= 1'b0;
    else    we <= (we_set & ~i1) | (we & (we_hold | i1));
endmodule
`default_nettype wire
