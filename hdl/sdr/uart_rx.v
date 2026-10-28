// FT-710 SDR FPGA: UART receiver, behavioural reconstruction (T15e).
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104 (docs/code/sdr/netlist.md, section 3.4). Cell names in the
// comments are the prjxray sites of UART A (pins M18/L18); UART B (V12/U12) is the same circuit.
// tb_uart_rx.v checks this module cycle by cycle against the structural netlist slice.
//
// 115200 baud 8N1 at CLK_HZ = 125 MHz: a 16-bit timer counts 0..DIV-1 (DIV = 1086) and restarts on every falling
// edge of the line, so it re-aligns on each start bit and data edge; the line is sampled at count SAMPLE (542).
// The samples go through a 10-stage shift register preset to all ones. A frame is complete when the oldest stage
// holds the start bit (0) and the newest the stop bit (1).

`default_nettype none
module ft710_uart_rx #(
  parameter integer DIV    = 1086,   // clocks per bit   (terminal count 0x43D)
  parameter integer SAMPLE = 542     // sample point     (0x21E)
) (
  input  wire       clk,
  input  wire       rst,             // synchronous, active high (global reset FF SLICE_X10Y76/BFF)
  input  wire       rx,              // pad, unsynchronized
  output reg  [7:0] data = 8'h00,    // byte register  (SLICE_X1Y93, SLICE_X2Y93)
  output reg        valid = 1'b0     // strobe, high for two clocks per byte (SLICE_X1Y92/AFF)
);
  // two-stage synchronizer for the edge detector (SLICE_X1Y96/A5FF, SLICE_X1Y97/AFF)
  reg s1 = 1'b0, s2 = 1'b0;
  always @(posedge clk) begin
    if (rst) begin s1 <= 1'b0; s2 <= 1'b0; end
    else begin s1 <= rx; s2 <= s1; end
  end
  wire fall = s2 & ~s1;

  // bit timer (SLICE_X0Y94..X0Y97, reset LUT SLICE_X1Y97/ALUT)
  reg [15:0] cnt = 16'd0;
  always @(posedge clk)
    if (rst || fall || cnt == DIV - 1) cnt <= 16'd0;
    else cnt <= cnt + 16'd1;
  wire tick = (cnt == SAMPLE);       // SLICE_X1Y94/BLUT

  // 10-stage sample shift register (FDSE, SLICE_X0Y93 and SLICE_X1Y95); sr[0] newest.
  // Note: the sample is taken straight from the pad, not from the synchronizer.
  reg [9:0] sr = 10'h000;            // INIT 0 in the bitstream; preset by reset
  wire done = sr[0] & ~sr[9];        // stop bit 1 and start bit 0 in place (SLICE_X0Y93/ALUT.O6)
  always @(posedge clk)
    if (rst || valid) sr <= 10'h3FF;
    else if (tick) sr <= {sr[8:0], rx};

  // byte register and strobe; sr[8] is data bit 0 (first bit on the line)
  always @(posedge clk) begin
    if (rst) begin data <= 8'h00; valid <= 1'b0; end
    else begin
      if (done) data <= {sr[1], sr[2], sr[3], sr[4], sr[5], sr[6], sr[7], sr[8]};
      valid <= done;
    end
  end
endmodule
`default_nettype wire
