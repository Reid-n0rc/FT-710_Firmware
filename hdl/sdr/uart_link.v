// FT-710 SDR FPGA: register link to MAIN (UART B, pins V12 in / U12 out), behavioural reconstruction (T15e).
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104 and from simulating the whole netlist in Verilator
// (docs/code/sdr/netlist.md section 5). This is MAIN's UART5 (SCI5) link. Protocol [fact, netlist simulation]:
//
//   request  'r' a a a a s s CR           read  register aaaa       reply 'r' v v v v s s   (7 bytes, no CR)
//            'w' a a a a v v v v s s CR   write register aaaa = vvvv reply ACK 0x06       (1 byte)
//            anything else + CR                                       reply '?' 0x3F       (1 byte)
//
//   ss is the 8-bit sum of the characters before it, as two upper-case hex digits. Address and value digits may be
//   upper or lower case; the checksum digits must be upper case (they are compared with the FPGA's own rendering).
//   The receiver keeps the last 11 characters in a shift register (88 FFs in the netlist, SLICE_X0..X2Y107..Y111),
//   so leading garbage, LF or a second command letter in front of a frame does not matter; only the 7 (read) or 11
//   (write) characters before CR count. CR does not enter or clear the window, so an empty line (CR alone)
//   repeats the previous command (a read is read again). LF and BS are not special here. 'x' is not a
//   command on this link (every 'x' frame shape tried answers '?').
//   The reply value is the read-data bus of the shared register bank, latched once per read.
//   Reply bytes go out as start + 8 data + 2 stop bits, 11 bit times + 3 clocks per byte.
//
// Timing parameters (clocks after the receiver's CR strobe) were fitted against the netlist in the full-design
// co-simulation (hdl/sdr/sim/cosim_top.v); tb results are in hdl/sdr/README.md.

`default_nettype none
module ft710_uart_link #(
  parameter integer DIV       = 1086,    // clocks per bit (115,200 baud at 125 MHz)
  parameter integer T_LATCH   = 37,      // CR strobe -> read-data latch
  parameter integer T_TX_READ = 74,      // CR strobe -> first start bit of a read reply
  parameter integer T_TX_ACK  = 69,      // ... of the write ACK
  parameter integer T_TX_NAK  = 37,      // ... of '?' for a line that is not shaped like a frame
  parameter integer T_NAK_RD  = 45,      // ... for a read-shaped line whose first checksum digit is wrong (+2 if
  parameter integer T_NAK_WR  = 49,      //     only the second digit is wrong); same for a write-shaped line
  parameter integer T_WRITE   = 34,      // CR strobe -> bus write strobe
  parameter integer GAP       = 3        // extra clocks between reply bytes
) (
  input  wire        clk,
  input  wire        rst,
  input  wire        rx,
  output reg         tx = 1'b1,
  // register bus (shared with the debug console in the netlist)
  output reg         bus_rd = 1'b0,      // one-clock read request (address on bus_addr)
  output reg         bus_wr = 1'b0,      // one-clock write strobe
  output reg  [15:0] bus_addr = 16'h0,
  output reg  [15:0] bus_wdata = 16'h0,
  input  wire [15:0] bus_rdata           // registered read data, sampled T_LATCH clocks after CR
);
  // ---------------------------------------------------------------- receiver (same circuit as UART A)
  wire [7:0] rxd;
  wire       rxv;
  ft710_uart_rx urx (.clk(clk), .rst(rst), .rx(rx), .data(rxd), .valid(rxv));
  reg rxv_d = 1'b0;
  always @(posedge clk) rxv_d <= rst ? 1'b0 : rxv;
  wire rx_stb = rxv & ~rxv_d;            // one clock per byte

  // ---------------------------------------------------------------- 11-character window, w[0] newest
  reg [7:0] w [0:10];
  integer i;
  initial for (i = 0; i < 11; i = i + 1) w[i] = 8'h00;

  function is_hex(input [7:0] c);
    is_hex = (c >= "0" && c <= "9") || (c >= "A" && c <= "F") || (c >= "a" && c <= "f");
  endfunction
  function [3:0] hexv(input [7:0] c);
    hexv = (c <= "9") ? c[3:0] : c[3:0] + 4'd9;
  endfunction
  function [7:0] hexc(input [3:0] v);   // upper-case rendering ("0123456789ABCDEF")
    hexc = (v < 10) ? 8'h30 + v : 8'h37 + v;
  endfunction

  // "shape" = command letter in place and hex digits in the address/value positions; then the two checksum
  // digits are compared one after the other (the netlist answers a later '?' the further the check got)
  wire [7:0] rsum = w[6] + w[5] + w[4] + w[3] + w[2];
  wire rd_shape = w[6] == "r" && is_hex(w[5]) && is_hex(w[4]) && is_hex(w[3]) && is_hex(w[2]);
  wire rd_d1 = w[1] == hexc(rsum[7:4]), rd_d2 = w[0] == hexc(rsum[3:0]);
  wire rd_ok = rd_shape && rd_d1 && rd_d2;
  wire [7:0] wsum = w[10] + w[9] + w[8] + w[7] + w[6] + w[5] + w[4] + w[3] + w[2];
  wire wr_shape = w[10] == "w" && is_hex(w[9]) && is_hex(w[8]) && is_hex(w[7]) && is_hex(w[6]) &&
                  is_hex(w[5]) && is_hex(w[4]) && is_hex(w[3]) && is_hex(w[2]);
  wire wr_d1 = w[1] == hexc(wsum[7:4]), wr_d2 = w[0] == hexc(wsum[3:0]);
  wire wr_ok = wr_shape && wr_d1 && wr_d2;
  wire [7:0] t_nak = wr_shape ? T_NAK_WR + (wr_d1 ? 2 : 0) :
                     rd_shape ? T_NAK_RD + (rd_d1 ? 2 : 0) : T_TX_NAK;

  // ---------------------------------------------------------------- command handler
  localparam [1:0] K_NAK = 2'd0, K_READ = 2'd1, K_ACK = 2'd2;
  reg  [1:0]  kind = K_NAK;
  reg         busy = 1'b0;               // between CR and the end of the reply
  reg  [7:0]  t = 8'd0;                  // clocks since CR
  reg  [7:0]  tn = 8'd0;                 // latency of this line's '?'
  reg  [7:0]  reply [0:6];
  reg  [2:0]  nrep = 3'd0;
  reg         go = 1'b0;                 // start the reply transmitter
  wire [7:0]  vsum = "r" + hexc(bus_rdata[15:12]) + hexc(bus_rdata[11:8]) + hexc(bus_rdata[7:4]) +
                     hexc(bus_rdata[3:0]);

  always @(posedge clk) begin
    bus_rd <= 1'b0; bus_wr <= 1'b0; go <= 1'b0;
    if (rst) begin
      busy <= 1'b0; t <= 8'd0;
      for (i = 0; i < 11; i = i + 1) w[i] <= 8'h00;
    end else if (rx_stb && rxd == 8'h0D && !busy) begin
      busy <= 1'b1; t <= 8'd0;
      kind <= wr_ok ? K_ACK : rd_ok ? K_READ : K_NAK;
      tn <= t_nak;
      bus_addr <= wr_ok ? {hexv(w[9]), hexv(w[8]), hexv(w[7]), hexv(w[6])}
                        : {hexv(w[5]), hexv(w[4]), hexv(w[3]), hexv(w[2])};
      bus_wdata <= {hexv(w[5]), hexv(w[4]), hexv(w[3]), hexv(w[2])};
      // the window is not cleared and CR is not shifted in: an empty line repeats the previous line
    end else begin
      if (rx_stb) begin
        for (i = 10; i > 0; i = i - 1) w[i] <= w[i - 1];
        w[0] <= rxd;
      end
      if (busy) begin
        t <= t + 8'd1;
        if (kind == K_READ && t == T_LATCH - 2) bus_rd <= 1'b1;
        if (kind == K_ACK && t == T_WRITE - 1) bus_wr <= 1'b1;
        if (kind == K_READ && t == T_LATCH - 1) begin
          reply[0] <= "r";
          reply[1] <= hexc(bus_rdata[15:12]); reply[2] <= hexc(bus_rdata[11:8]);
          reply[3] <= hexc(bus_rdata[7:4]);   reply[4] <= hexc(bus_rdata[3:0]);
          reply[5] <= hexc(vsum[7:4]);        reply[6] <= hexc(vsum[3:0]);
          nrep <= 3'd7;
        end
        if (kind == K_ACK && t == 0) begin reply[0] <= 8'h06; nrep <= 3'd1; end
        if (kind == K_NAK && t == 0) begin reply[0] <= 8'h3F; nrep <= 3'd1; end
        if ((kind == K_READ && t == T_TX_READ - 1) || (kind == K_ACK && t == T_TX_ACK - 1) ||
            (kind == K_NAK && t == tn - 8'd1)) begin
          go <= 1'b1; busy <= 1'b0;
        end
      end
    end
  end

  // ---------------------------------------------------------------- reply transmitter
  // byte frame: start, d0..d7, stop held two bit times, then GAP clocks before the next start bit
  reg  [2:0]  k = 3'd0;                  // byte index
  reg  [2:0]  left = 3'd0;               // bytes still to send
  reg  [3:0]  bitn = 4'd0;               // 0 start, 1..8 data, 9..10 stop
  reg  [15:0] bt = 16'd0;                // clocks within the bit
  reg         sending = 1'b0;
  reg         gapping = 1'b0;
  reg  [3:0]  g = 4'd0;
  wire [7:0]  cur = reply[k];
  always @(posedge clk) begin
    if (rst) begin
      tx <= 1'b1; sending <= 1'b0; gapping <= 1'b0; left <= 3'd0;
    end else if (go) begin
      k <= 3'd0; left <= nrep; sending <= 1'b1; bitn <= 4'd0; bt <= 16'd0; tx <= 1'b0;
    end else if (sending) begin
      if (bt == DIV - 1) begin
        bt <= 16'd0;
        if (bitn == 4'd10) begin
          sending <= 1'b0;
          if (left > 1) begin gapping <= 1'b1; g <= 4'd0; end
          left <= left - 3'd1;
        end else begin
          bitn <= bitn + 4'd1;
          tx <= (bitn < 4'd8) ? cur[bitn[2:0]] : 1'b1;
        end
      end else bt <= bt + 16'd1;
    end else if (gapping) begin
      if (g == GAP - 1) begin
        gapping <= 1'b0; k <= k + 3'd1; sending <= 1'b1; bitn <= 4'd0; bt <= 16'd0; tx <= 1'b0;
      end else g <= g + 4'd1;
    end
  end
endmodule
`default_nettype wire
