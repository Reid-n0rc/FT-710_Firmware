// Testbench (T15e): ft710_uart_link on its own, with a small register model on its bus. Behavioural only (no
// derived files): MAIN's boot read of register 0 (version 0x0104), a write and read-back, a bad checksum, junk in
// front of a frame and an empty line. The cycle-exact comparison against the netlist is hdl/sdr/sim/cosim_*.sh.
`timescale 1ns/1ps
`default_nettype none
module tb_uart_link;
  reg clk = 1'b0;
  always #4 clk = ~clk;                     // 125 MHz
  reg rst = 1'b1, rx = 1'b1;
  wire tx, brd, bwr;
  wire [15:0] addr, wdata;
  reg  [15:0] rdata = 16'h0;
  reg  [15:0] regs [0:255];
  integer i;
  initial begin
    for (i = 0; i < 256; i = i + 1) regs[i] = 16'h0000;
    regs[0] = 16'h0104; regs[1] = 16'h000F; regs[8'h15] = 16'h1FFF;
  end
  // register bank model: read data registered one clock after the request, write on the strobe
  always @(posedge clk) begin
    if (brd) rdata <= regs[addr[7:0]];
    if (bwr) regs[addr[7:0]] <= wdata;
  end
  ft710_uart_link dut (.clk(clk), .rst(rst), .rx(rx), .tx(tx), .bus_rd(brd), .bus_wr(bwr),
                       .bus_addr(addr), .bus_wdata(wdata), .bus_rdata(rdata));
  // reply decoder
  ft710_uart_rx mon (.clk(clk), .rst(rst), .rx(tx), .data(), .valid());
  reg mv = 1'b0;
  reg [8*16-1:0] got = 0;
  always @(posedge clk) begin
    mv <= mon.valid;
    if (mon.valid && !mv) got <= {got[8*15-1:0], mon.data};
  end

  real bit_ns = 1.0e9 / 115200.0;
  integer k, errors = 0;
  task send(input [7:0] b);
    begin
      rx = 1'b0; #(bit_ns);
      for (k = 0; k < 8; k = k + 1) begin rx = b[k]; #(bit_ns); end
      rx = 1'b1; #(bit_ns);
    end
  endtask
  task line(input [8*16-1:0] s, input integer n);    // n characters of s (last n bytes), then CR
    integer j;
    begin
      got = 0;
      for (j = n - 1; j >= 0; j = j - 1) send(s[8*j +: 8]);
      send(8'h0D);
      #(90 * bit_ns);
    end
  endtask
  task check(input [8*16-1:0] e, input integer n, input [8*20-1:0] what);
    begin
      if (got !== e) begin                 // both right-aligned, zero-padded
        errors = errors + 1;
        $display("FAIL %0s: got %h", what, got);
      end else $display("ok   %0s", what);
    end
  endtask

  initial begin
    #1000 rst = 1'b0;
    #(5 * bit_ns);
    line("r000032", 7);        check("r010437", 7, "read reg 0");
    line("w00151234", 9);      // checksum below
    check(8'h3F, 1, "write without sum");
    line({"w00151234", "07"}, 11); check(8'h06, 1, "write reg 15");
    line("r001538", 7);        check("r12343C", 7, "read back reg 15");
    line("r000033", 7);        check(8'h3F, 1, "bad checksum");
    line("zzr000133", 9);      check("r000F48", 7, "junk + read reg 1");
    line("", 0);               check("r000F48", 7, "empty line repeats");
    line("r00153b", 7);        check(8'h3F, 1, "lower-case checksum");
    if (errors) $display("FAIL"); else $display("PASS");
    $finish;
  end
endmodule
`default_nettype wire
