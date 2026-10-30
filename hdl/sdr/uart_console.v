// FT-710 SDR FPGA: UART A debug console (M18 in / L18 out, prompt "[IF]>"), behavioural reconstruction (#147, #204).
//
// Byte-level model of what the recovered netlist does (docs/code/sdr/netlist.md 5.3). The structure follows the
// netlist (#204): a 15-entry line buffer of 5-bit character codes and a CR matcher that looks at fixed buffer
// positions; the output side is written from whole-netlist simulation. tools/sdr_console_check.py compares the TX
// byte stream (tb_uart_console.v) with the netlist's for the lines in sim/console_lines.txt. Timing is NOT
// cycle-accurate: bytes come out in the same order with the same values, start bits a few clocks to some hundred
// clocks apart from the netlist's.
//
// Netlist structure [fact, #204, netlist.md 5.3]:
//   - every received byte except CR and BS is pushed into a 15 x 5-bit shift register (chains SLICE_X3Y92/AFF,
//     X3Y95/AFF, X3Y95/BFF, X4Y87/CFF, X4Y90/AFF ... X3Y88/X2Y92, CE SLICE_X5Y95/BLUT) as a code (code_of below);
//     bytes outside the set push 0x1F, the same value as an empty slot. BS pops the newest entry. The buffer is
//     cleared (all 0x1F) after every CR.
//   - at CR the matcher (-> SLICE_X5Y89/AFF, X5Y87/CFF, X5Y87/BFF) reads only positions 0, 1, 4, 5, 9, 10
//     (0 = newest) and picks, in this order of priority:
//       pos 10 = "w", pos 9 = SP          -> write  addr = pos 8..5, data = pos 3..0
//       pos 5  = "r", pos 4 = SP          -> read   addr = pos 3..0
//       pos 5  = "E"/"e", pos 4 = SP      -> examine (endless list, one register per line)
//       pos 5  = "D"/"d", pos 4 = SP      -> dump    (endless list, 8 registers per line)
//       pos 1  = "#"                      -> quiet mode on (no echo, bare replies)
//       pos 0  = empty / unknown byte     -> nothing (CR LF prompt)
//       anything else                     -> "Err"
//     The other positions are not checked: digits are taken as the low nibble of their code (so "G" = C,
//     "#" = E, a separator or letter inside a field gives its code's low nibble), and the separator between the
//     two "w" fields can be any character. "x" (code 0x14) is not tested at any position: it has no command.
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
  // 5-bit code pushed into the line buffer (evaluated from the chain-head LUTs over all 256 bytes) [fact]
  localparam [4:0] C_SP = 5'h10, C_BS = 5'h13, C_X = 5'h14, C_W = 5'h15, C_R = 5'h16, C_HASH = 5'h1E,
                   C_NONE = 5'h1F, C_E = 5'h0E, C_D = 5'h0D;
  function [4:0] code_of(input [7:0] c);
    if (c >= "0" && c <= "9") code_of = c - "0";
    else if (c >= "A" && c <= "F") code_of = c - "A" + 5'd10;
    else if (c >= "a" && c <= "f") code_of = c - "a" + 5'd10;
    else case (c)
      " ": code_of = 5'h10;  8'h0D: code_of = 5'h11; 8'h0A: code_of = 5'h12; 8'h08: code_of = 5'h13;
      "x": code_of = 5'h14;  "w": code_of = 5'h15;   "r": code_of = 5'h16;   ",": code_of = 5'h17;
      "G": code_of = 5'h1C;  "s": code_of = 5'h1D;   "#": code_of = 5'h1E;
      default: code_of = 5'h1F;
    endcase
  endfunction
  function [7:0] hexc(input [3:0] v);
    hexc = v < 10 ? "0" + v : "A" + v - 10;
  endfunction
  `include "uart_console_echo.vh"

  // ---------------------------------------------------------------- output queue + transmitter
  reg [8:0] q [0:63];                  // bit 8: echo byte
  reg [5:0] qh = 0, qt = 0;
  wire qempty = qh == qt;
  wire [5:0] qcount = qh - qt;
  reg [7:0] txd = 8'h00;
  reg req = 1'b0;
  wire busy, last_stop;
  ft710_uart_tx #(.DIV(DIV), .STOPS(2)) u_tx (.clk(clk), .rst(rst), .req(req), .data(txd), .busy(busy), .tx(tx),
                                               .last_stop(last_stop));
  reg [2:0] hold = 0;
  always @(posedge clk)
    if (rst) begin qt <= 0; req <= 1'b0; hold <= 0; end
    else if (req) begin
      hold <= hold + 1;
      if (hold == 3'd7) req <= 1'b0;          // keep the level request long enough for the synchronizer
    end else if ((!busy || (last_stop && q[qt][8])) && !qempty && hold == 0) begin
      // reply bytes go out with 2 stop bits; an echo starts during the second stop bit, as the netlist's echo
      // follows the input's 1-stop-bit rhythm (10,850 clocks per byte) [fact, simulation]
      txd <= q[qt][7:0]; qt <= qt + 1; req <= 1'b1; hold <= 1;
    end else if (hold != 0 && !busy) hold <= 0;
  wire tx_active = busy | req | (hold != 0) | !qempty;

  task push(input [7:0] b);
    begin q[qh] = {1'b0, b}; qh = qh + 1; end
  endtask
  task push_echo(input [7:0] b);
    begin q[qh] = {1'b1, b}; qh = qh + 1; end
  endtask
  task prompt;
    begin push("["); push("I"); push("F"); push("]"); push(">"); end
  endtask
  task crlf;
    begin push(8'h0D); push(8'h0A); end
  endtask
  task hex4(input [15:0] v);
    begin push(hexc(v[15:12])); push(hexc(v[11:8])); push(hexc(v[7:4])); push(hexc(v[3:0])); end
  endtask

  // ---------------------------------------------------------------- line buffer and command engine
  reg [4:0] lb [0:14];                 // 0 = newest
  integer i;
  reg [15:0] cnt = 0;
  reg booted = 1'b0;
  reg quiet = 1'b0;                    // set by the "#" command: no echo, bare replies [fact, #204]
  reg bs_stall = 1'b0;                 // BS received while the transmitter was busy (see below)
  localparam [2:0] M_IDLE = 3'd0, M_READ = 3'd1, M_EXAM = 3'd2, M_DUMP = 3'd3;
  reg [2:0] mode = M_IDLE;
  reg [15:0] maddr = 0;
  reg [2:0] dcol = 0;                  // dump: column 0..7 within the line
  reg [1:0] rdwait = 0;
  reg rdpend = 1'b0;
  wire [15:0] f_lo = {lb[3][3:0], lb[2][3:0], lb[1][3:0], lb[0][3:0]};
  wire [15:0] f_hi = {lb[8][3:0], lb[7][3:0], lb[6][3:0], lb[5][3:0]};

  always @(posedge clk) begin
    bus_rd <= 1'b0; bus_wr <= 1'b0;
    if (rst) begin
      qh = 0; cnt <= 0; booted <= 1'b0; rdwait <= 0; rdpend <= 1'b0; mode <= M_IDLE; quiet <= 1'b0;
      bs_stall <= 1'b0;
      for (i = 0; i < 15; i = i + 1) lb[i] <= C_NONE;
    end else begin
      if (!booted) begin
        cnt <= cnt + 1;
        if (cnt == PROMPT_DELAY) begin prompt; booted <= 1'b1; end
      end
      // register reads for r / E / D: one read in flight, issued when the queue has room
      if (rdwait != 0) begin
        rdwait <= rdwait - 1;
        if (rdwait == 1) begin
          rdpend <= 1'b0;
          case (mode)
            M_READ: begin
              hex4(bus_rdata);
              if (!quiet) begin push(" "); crlf; prompt; end
              mode <= M_IDLE;
            end
            M_EXAM: begin hex4(bus_rdata); push(" "); crlf; maddr <= maddr + 1; end
            M_DUMP: begin
              if (dcol == 0) begin hex4(maddr); push(" "); push(":"); push(" "); end
              hex4(bus_rdata); push(" ");
              if (dcol == 7) crlf;
              dcol <= dcol + 1; maddr <= maddr + 1;
            end
            default: ;
          endcase
        end
      end else if (!rdpend && mode != M_IDLE && qcount < 6'd16) begin
        bus_addr <= maddr; bus_rd <= 1'b1; rdwait <= 2'd3; rdpend <= 1'b1;
      end
      if (got && booted) begin
        if (rxd == 8'h0D) begin
          // the CR matcher (priority as in the netlist)
          if (bs_stall) begin push(8'h08); bs_stall <= 1'b0; end
          mode <= M_IDLE; rdwait <= 0; rdpend <= 1'b0;
          if (lb[10] == C_W && lb[9] == C_SP) begin
            bus_addr <= f_hi; bus_wdata <= f_lo; bus_wr <= 1'b1;
            if (!quiet) begin crlf; prompt; end
          end else if (lb[4] == C_SP && (lb[5] == C_R || lb[5] == C_E || lb[5] == C_D)) begin
            maddr <= f_lo; dcol <= 0;
            mode <= lb[5] == C_R ? M_READ : lb[5] == C_E ? M_EXAM : M_DUMP;
            if (!quiet) crlf;
          end else if (lb[1] == C_HASH) begin
            quiet <= 1'b1;
          end else if (lb[0] == C_NONE) begin
            if (!quiet) begin crlf; prompt; end
          end else begin
            if (!quiet) begin push("E"); push("r"); push("r"); crlf; prompt; end
          end
          for (i = 0; i < 15; i = i + 1) lb[i] <= C_NONE;
        end else if (rxd == 8'h08) begin
          // BS: with the transmitter idle it is echoed as BS SP BS and pops the newest entry. Received while an
          // echo is still being sent, the netlist's handler stalls (FSM SLICE_X2Y91.. state 01010000) until the
          // next CR, which then sends one BS and handles the line without the pop [fact, simulation]. A further
          // character during the stall makes the netlist send garbage (not modelled).
          if (!tx_active) begin
            if (!quiet) begin push(8'h08); push(" "); push(8'h08); end
            for (i = 0; i < 14; i = i + 1) lb[i] <= lb[i + 1];
            lb[14] <= C_NONE;
          end else bs_stall <= 1'b1;
        end else begin
          if (!quiet) push_echo(echo_of(rxd));
          for (i = 14; i > 0; i = i - 1) lb[i] <= lb[i - 1];
          lb[0] <= code_of(rxd);
        end
      end
    end
  end
endmodule
`default_nettype wire
