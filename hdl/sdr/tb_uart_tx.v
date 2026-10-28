// Testbench (T15e): ft710_uart_tx looped back into ft710_uart_rx; checks bit time (8.688 us = 1086 clocks)
// and that every byte comes back. Behavioural models only.
`timescale 1ns/1ps
`default_nettype none
module tb_uart_tx;
  reg clk = 1'b0;
  always #4 clk = ~clk;
  reg rst = 1'b1, req = 1'b0;
  reg [7:0] d = 8'h00;
  wire line, busy, valid;
  wire [7:0] q;
  ft710_uart_tx tx (.clk(clk), .rst(rst), .req(req), .data(d), .busy(busy), .tx(line));
  ft710_uart_rx rx (.clk(clk), .rst(rst), .rx(line), .data(q), .valid(valid));

  integer errors = 0, n = 0, i;
  reg [7:0] sent [0:15];
  reg last_valid = 1'b0;
  always @(posedge clk) begin
    if (valid && !last_valid) begin
      if (q !== sent[n]) begin errors = errors + 1; $display("%t got %02x expected %02x", $time, q, sent[n]); end
      n = n + 1;
    end
    last_valid <= valid;
  end
  // bit time: measure the start bit of the first frame
  realtime t_fall = 0, t_rise = 0;
  initial begin
    @(negedge line); t_fall = $realtime;
    @(posedge line); t_rise = $realtime;
  end

  initial begin
    #1000 rst = 1'b0;
    #20000;
    for (i = 0; i < 8; i = i + 1) begin
      sent[i] = 8'h31 + i * 6;          // first byte has bit 0 = 1, so the first low pulse is the start bit
      d = sent[i];
      @(posedge clk) req = 1'b1;
      @(posedge clk) req = 1'b0;
      @(posedge clk); wait (!busy);
    end
    #50000;
    $display("start bit %0.1f ns (expected 8688.0), %0d of 8 bytes back, %0d errors", t_rise - t_fall, n, errors);
    if (errors == 0 && n == 8 && t_rise - t_fall > 8680.0 && t_rise - t_fall < 8696.0) $display("PASS");
    else $display("FAIL");
    $finish;
  end
endmodule
`default_nettype wire
