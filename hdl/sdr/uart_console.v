// FT-710 SDR FPGA: UART A debug console (M18 in / L18 out, prompt "[IF]>"), behavioural reconstruction (#147).
//
// Byte-level model of what the recovered netlist does (docs/code/sdr/netlist.md 5.3), written from whole-netlist
// simulation, not from the netlist's state encoding: tools/sdr_console_check.py compares its TX byte stream
// (tb_uart_console.v) with the netlist's for the lines in sim/console_lines.txt. Timing is NOT cycle-accurate: bytes come out in the same order
// with the same values, start bits a few clocks to some hundred clocks apart from the netlist's.
//
// Behaviour [fact, whole-netlist simulation, netlist.md 5.3]:
//   - after reset: "[IF]>" (no CR LF in front)
//   - every received byte other than CR is echoed at once (echo_of() in uart_console_echo.vh)
//   - the line is parsed character by character (state machine below), not buffered:
//       a command letter r / w / x restarts the command wherever it appears ("qr 0000", "rr 0000", "wr 0000" read);
//       a byte outside the character set (echoed "?") drops the command silently (CR then prints only CR LF prompt);
//       LF, a separator or digit out of place, or a 5th digit make the line an error;
//       "r" SP hhhh                 CR -> CR LF vvvv " " CR LF "[IF]>"   (the separator after r must be a space)
//       "w" SP hhhh (SP or ",") hhhh CR -> CR LF "[IF]>"                  (register write)
//       empty line / dropped command CR -> CR LF "[IF]>"
//       anything else, every "x" line  -> "Err" CR LF "[IF]>"
//     h = 0-9 A-F a-f, "#" (= E, echoed 0x06) or "G" (value unknown), as the console's hex decoder reads them.
//   Open (#147 follow-up): BS (echoed 0x08; ends a hex field with Err here, while #89 read "r 000<BS>" as register
//   0x0B; "w 0015 12<BS>4" made the netlist send garbage), TAB, "s" after "r" (echoed ":"), and "x".
`default_nettype none
module ft710_uart_console #(
  parameter integer DIV = 1086,          // 115,200 baud at 125 MHz
  parameter integer PROMPT_DELAY = 300   // clocks after reset before the first prompt byte is queued [approx]
) (
  input  wire        clk,
  input  wire        rst,
  input  wire        rx,
  output wire        tx,
  output reg         bus_rd = 1'b0,
  output reg         bus_wr = 1'b0,
  output reg  [15:0] bus_addr = 16'h0,
  output reg  [15:0] bus_wdata = 16'h0,
  input  wire [15:0] bus_rdata           // sampled 2 clocks after bus_rd
);
  // ---------------------------------------------------------------- receiver
  wire [7:0] rxd;
  wire rxv;
  ft710_uart_rx #(.DIV(DIV)) u_rx (.clk(clk), .rst(rst), .rx(rx), .data(rxd), .valid(rxv));
  reg rxv_d = 1'b0;
  always @(posedge clk) rxv_d <= rxv;
  wire got = rxv & ~rxv_d;

  // ---------------------------------------------------------------- character tables
  function is_hex(input [7:0] c);
    is_hex = (c >= "0" && c <= "9") || (c >= "A" && c <= "G") || (c >= "a" && c <= "f") || c == "#";
  endfunction
  function [3:0] hexv(input [7:0] c);
    if (c == "#") hexv = 4'hE;
    else if (c == "G") hexv = 4'hF;     // G is taken as a digit ("r 00G0" reads CCCC); its value is a [guess]
    else if (c <= "9") hexv = c - "0";
    else if (c <= "F") hexv = c - "A" + 4'd10;
    else hexv = c - "a" + 4'd10;
  endfunction
  function [7:0] hexc(input [3:0] v);
    hexc = v < 10 ? "0" + v : "A" + v - 10;
  endfunction
  `include "uart_console_echo.vh"

  // ---------------------------------------------------------------- output queue + transmitter
  reg [7:0] q [0:63];
  reg [5:0] qh = 0, qt = 0;
  wire qempty = qh == qt;
  reg [7:0] txd = 8'h00;
  reg req = 1'b0;
  wire busy;
  ft710_uart_tx #(.DIV(DIV)) u_tx (.clk(clk), .rst(rst), .req(req), .data(txd), .busy(busy), .tx(tx));
  reg [2:0] hold = 0;
  always @(posedge clk)
    if (rst) begin qt <= 0; req <= 1'b0; hold <= 0; end
    else if (req) begin
      hold <= hold + 1;
      if (hold == 3'd7) req <= 1'b0;          // keep the level request long enough for the synchronizer
    end else if (!busy && !qempty && hold == 0) begin
      txd <= q[qt]; qt <= qt + 1; req <= 1'b1; hold <= 1;
    end else if (hold != 0 && !busy) hold <= 0;

  task push(input [7:0] b);
    begin q[qh] = b; qh = qh + 1; end
  endtask
  task prompt;
    begin push("["); push("I"); push("F"); push("]"); push(">"); end
  endtask

  // ---------------------------------------------------------------- parser (state per received character)
  localparam [3:0] S_IDLE = 4'd0, S_ERR = 4'd1, S_X = 4'd2,
                   S_R = 4'd3, S_RSEP = 4'd4,                 // "r", "r "  (then 4 digits: S_RSEP + count)
                   S_W = 4'd5, S_WSEP = 4'd6, S_WSEP2 = 4'd7;  // "w", "w ", "w aaaa,"
  reg [3:0] st = S_IDLE;
  reg [2:0] nd = 0;              // hex digits taken in the current field
  reg [15:0] a = 0, d = 0;
  reg [15:0] cnt = 0;
  reg booted = 1'b0;
  reg [1:0] rdwait = 0;
  wire is_sep_sp = rxd == " ";
  wire is_comma = rxd == ",";
  wire is_letter = rxd == "r" || rxd == "w" || rxd == "x";
  wire known = is_hex(rxd) || is_letter || is_sep_sp || is_comma || rxd == 8'h0A || rxd == 8'h0D;
  always @(posedge clk) begin
    bus_rd <= 1'b0; bus_wr <= 1'b0;
    if (rst) begin
      qh = 0; st <= S_IDLE; nd <= 0; cnt <= 0; booted <= 1'b0; rdwait <= 0;
    end else begin
      if (!booted) begin
        cnt <= cnt + 1;
        if (cnt == PROMPT_DELAY) begin prompt; booted <= 1'b1; end
      end
      if (rdwait != 0) begin
        rdwait <= rdwait - 1;
        if (rdwait == 1) begin
          push(8'h0D); push(8'h0A);
          push(hexc(bus_rdata[15:12])); push(hexc(bus_rdata[11:8])); push(hexc(bus_rdata[7:4])); push(hexc(bus_rdata[3:0]));
          push(" "); push(8'h0D); push(8'h0A); prompt;
        end
      end
      if (got && booted) begin
        if (rxd == 8'h0D) begin
          if (st == S_RSEP && nd == 4) begin bus_addr <= a; bus_rd <= 1'b1; rdwait <= 2'd3; end
          else if (st == S_WSEP2 && nd == 4) begin
            bus_addr <= a; bus_wdata <= d; bus_wr <= 1'b1; push(8'h0D); push(8'h0A); prompt;
          end else if (st == S_IDLE) begin push(8'h0D); push(8'h0A); prompt; end
          else begin push("E"); push("r"); push("r"); push(8'h0D); push(8'h0A); prompt; end
          st <= S_IDLE; nd <= 0;
        end else begin
          if (rxd == "s" && st == S_R) push(":");          // seen in the netlist; meaning open
          else push(echo_of(rxd));
          nd <= 0;
          if (rxd == "s" && st == S_R) st <= S_ERR;
          else if (rxd == 8'h08) st <= (st == S_IDLE) ? S_IDLE : S_ERR;   // BS: see uart_console_echo.vh
          else if (!known) st <= S_IDLE;                   // characters outside the set drop the command
          else if (rxd == "r") st <= S_R;                   // a command letter restarts the line
          else if (rxd == "w") st <= S_W;
          else if (rxd == "x") st <= S_X;
          else if (is_sep_sp && st == S_R) st <= S_RSEP;
          else if (is_sep_sp && st == S_W) st <= S_WSEP;
          else if ((is_sep_sp || is_comma) && st == S_WSEP && nd == 4) st <= S_WSEP2;
          else if (is_hex(rxd) && (st == S_RSEP || st == S_WSEP) && nd < 4) begin
            a <= {a[11:0], hexv(rxd)}; nd <= nd + 1;
          end else if (is_hex(rxd) && st == S_WSEP2 && nd < 4) begin
            d <= {d[11:0], hexv(rxd)}; nd <= nd + 1;
          end else st <= S_ERR;                             // LF, misplaced separators or digits, a 5th digit
          if ((is_sep_sp || is_comma) && st == S_WSEP && nd == 4) nd <= 0;
          else if (is_hex(rxd) && (st == S_RSEP || st == S_WSEP || st == S_WSEP2) && nd < 4) nd <= nd + 1;
        end
      end
    end
  end
endmodule
`default_nettype wire
