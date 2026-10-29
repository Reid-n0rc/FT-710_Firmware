// Testbench for ft710_uart_console (#147): plays console lines (from +lines=FILE, one per line, C escapes \r \n \b
// \xHH; CR is added) back to back, then 440 idle bits, like tools/sdr_uart_sim.py --gap 40 with "w:400" after each line and prints every byte the
// console sends as "A TX hh", for comparison with the whole-netlist simulation (hdl/sdr/README.md).
// The register bank is a small model with the power-up values seen in the netlist (netlist.md 5.2).
`timescale 1ns/1ps
module tb_uart_console;
  localparam real BIT = 125.0e6 / 115200.0;
  reg clk = 0, rst = 1;
  always #4 clk = ~clk;
  reg rx = 1;
  wire tx, bus_rd, bus_wr;
  wire [15:0] bus_addr, bus_wdata;
  reg [15:0] rdata = 0;
  ft710_uart_console dut (.clk(clk), .rst(rst), .rx(rx), .tx(tx), .bus_rd(bus_rd), .bus_wr(bus_wr),
                          .bus_addr(bus_addr), .bus_wdata(bus_wdata), .bus_rdata(rdata));
  // register model
  reg [15:0] r03 = 16'h8800, r15 = 16'h1FFF, r30 = 16'h0023, r31 = 16'h0000;
  function [15:0] regv(input [15:0] a);
    case (a)
      16'h0000: regv = 16'h0104; 16'h0001: regv = 16'h000F; 16'h0002: regv = 16'h0000; 16'h0003: regv = r03;
      16'h0004: regv = 16'h8810; 16'h0005: regv = 16'h0000; 16'h0006: regv = 16'h020A; 16'h0007: regv = 16'h0000;
      16'h000A: regv = 16'h0000; 16'h000B: regv = 16'h0058; 16'h000E: regv = 16'h1200; 16'h0015: regv = r15;
      16'h0030: regv = r30; 16'h0031: regv = r31;
      default: regv = 16'hCCCC;
    endcase
  endfunction
  reg [1:0] rdd = 0;
  always @(posedge clk) begin
    rdd <= {rdd[0], bus_rd};
    if (bus_rd) rdata <= regv(bus_addr);
    if (bus_wr) case (bus_addr)
      16'h0003: r03 <= bus_wdata; 16'h0015: r15 <= bus_wdata; 16'h0030: r30 <= bus_wdata; 16'h0031: r31 <= bus_wdata;
      default: ;
    endcase
  end
  // software UART on tx
  integer t0, nb; reg [7:0] by; reg st = 0; reg last = 1;
  real tnow;
  integer clkn = 0;
  always @(posedge clk) begin
    clkn = clkn + 1;
    if (!st) begin if (last && !tx) begin st = 1; t0 = clkn; nb = 0; by = 0; end end
    else if (clkn >= t0 + BIT * (nb + 1.5)) begin
      if (nb < 8) by[nb] = tx;
      else begin $display("%0d A TX %02X", clkn, by); st = 0; end
      nb = nb + 1;
    end
    last = tx;
  end
  task sendbyte(input [7:0] b);
    integer k;
    begin
      rx = 0; repeat ($rtoi(BIT)) @(posedge clk);
      for (k = 0; k < 8; k = k + 1) begin rx = b[k]; repeat ($rtoi(BIT)) @(posedge clk); end
      rx = 1; repeat ($rtoi(BIT)) @(posedge clk);
    end
  endtask
  task idle(input integer bits);
    begin rx = 1; repeat (bits * $rtoi(BIT)) @(posedge clk); end
  endtask
  integer fd, c, c2, h;
  reg [8*256-1:0] fname;
  initial begin
    if (!$value$plusargs("lines=%s", fname)) begin $display("need +lines=FILE"); $finish; end
    fd = $fopen(fname, "r");
    repeat (20) @(posedge clk); rst = 0;
    idle(100);
    c = $fgetc(fd);
    while (c != -1) begin
      if (c == 10) begin sendbyte(8'h0D); idle(440); end
      else begin
        if (c == "\\") begin
          c2 = $fgetc(fd);
          if (c2 == "r") c = 13; else if (c2 == "n") c = 10; else if (c2 == "b") c = 8;
          else if (c2 == "x") begin
            h = $fgetc(fd); c = (h <= "9" ? h - "0" : (h | 32) - "a" + 10) * 16;
            h = $fgetc(fd); c = c + (h <= "9" ? h - "0" : (h | 32) - "a" + 10);
          end else c = c2;
        end
        sendbyte(c);
      end
      c = $fgetc(fd);
    end
    idle(200);
    $finish;
  end
endmodule
