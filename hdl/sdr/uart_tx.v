// FT-710 SDR FPGA: UART transmitter, behavioural reconstruction (T15e).
//
// From the recovered netlist (docs/code/sdr/netlist.md 3.4), UART A transmit side: request synchronizer
// SLICE_X3Y98/AFF -> SLICE_X4Y96/AFF (rising edge = start), 16-bit bit timer SLICE_X2Y94..X2Y97 that restarts on
// start and at DIV-1 (1085), a shift strobe at count PHASE (32), a shift register and a retiming flip-flop
// SLICE_X1Y94/A5FF on the pad (L18). Timing per bit and the 8N1 framing match the netlist [fact]; the exact
// cycle of the first edge after a request is not checked against the netlist [inference].

`default_nettype none
module ft710_uart_tx #(
  parameter integer DIV   = 1086,
  parameter integer PHASE = 32,
  parameter integer STOPS = 1      // stop bits; the console sends 2 (byte period 11,949 clocks in the netlist, #204)
) (
  input  wire       clk,
  input  wire       rst,
  input  wire       req,          // level request; a rising edge starts a frame
  input  wire [7:0] data,
  output reg        busy = 1'b0,
  output reg        tx = 1'b0,    // INIT 0 in the bitstream, driven high by reset
  output wire       last_stop     // in the last stop bit (a new frame may start early; console echo, #204)
);
  reg r1 = 1'b0, r2 = 1'b0;
  always @(posedge clk)
    if (rst) begin r1 <= 1'b0; r2 <= 1'b0; end
    else begin r1 <= req; r2 <= r1; end
  wire start = r1 & ~r2;

  reg [15:0] cnt = 16'd0;
  always @(posedge clk)
    if (rst || start || cnt == DIV - 1) cnt <= 16'd0;
    else cnt <= cnt + 16'd1;
  wire strobe = (cnt == PHASE);

  reg [10:0] sh = 11'h7FF;        // {stop, stop, d7..d0, start}, LSB goes out first
  reg [3:0] left = 4'd0;
  assign last_stop = busy & (left == 4'd0);
  always @(posedge clk) begin
    if (rst) begin
      sh <= 11'h7FF; left <= 4'd0; busy <= 1'b0; tx <= 1'b1;
    end else if (start) begin
      sh <= {2'b11, data, 1'b0}; left <= 4'd9 + STOPS; busy <= 1'b1; tx <= 1'b1;
    end else if (strobe) begin
      tx <= (left != 0) ? sh[0] : 1'b1;
      sh <= {1'b1, sh[10:1]};
      if (left != 0) left <= left - 4'd1;
      else busy <= 1'b0;
    end
  end
endmodule
`default_nettype wire
