// Co-simulation top (T15e): the whole recovered netlist and the behavioural ft710_uart_link side by side.
//
// Built by hdl/sdr/sim/build_full.sh with TOP=cosim_top and NET=build/sdr/vl/ft710_rd.v (the netlist with a 17-bit
// probe port on the register bank's read-data flip-flops, made by tools/xc7_probe_netlist.py, see
// hdl/sdr/README.md). Both get the same uart_b_rx; the RTL reads the netlist's read-data bus, so the reply bytes
// must match, and uart_b_tx is compared with the RTL's tx on every clock.
// probe[0] = netlist uart_b_tx, [1] = RTL tx, [2] = mismatch, [3] = RTL bus_rd, [4] = RTL bus_wr,
// [5] = netlist read-data latch enable (SLICE_X15Y106/CLUT).
`default_nettype none
module cosim_top (
  input  wire adc_clk_p, adc_clk_n, adc_dco_p, adc_dco_n,
  input  wire uart_a_rx, uart_b_rx,
  output wire uart_a_tx, uart_b_tx,
  output wire [5:0] probe
);
  wire [16:0] np;
  ft710_sdr n (
    .io_T9(), .io_U13(1'b0), .io_T13(1'b0), .io_V10(1'b0), .uart_b_rx(uart_b_rx), .uart_b_tx(uart_b_tx),
    .io_T11(1'b0), .io_V17(), .io_U16(), .io_U17(), .io_V16(), .io_V15(),
    .io_T16(), .io_R16(), .io_T15(), .io_T14(1'b0), .io_R15(1'b0), .io_P15(1'b0),
    .io_P17(), .io_N16(), .io_N15(), .io_M17(), .dsp_clk(), .io_N14(),
    .io_T18(), .io_R18(), .flash_cs_n(), .uart_a_rx(uart_a_rx), .uart_a_tx(uart_a_tx), .io_L16(),
    .io_L15(1'b0), .flash_d3(1'b0), .flash_d2(1'b0), .flash_d1(1'b0), .flash_d0(), .io_D17(),
    .io_E17(), .io_B18(1'b0), .io_A14(1'b0), .io_A13(1'b0), .io_A16(1'b0), .io_F13(),
    .io_B14(), .io_B13(), .io_C14(), .io_D14(), .io_R8_p(), .io_T8_n(),
    .io_R7_p(), .io_T6_n(), .io_U7_p(), .io_U6_n(), .io_U9_p(), .io_V9_n(),
    .io_V7_p(), .io_V6_n(), .io_M6_p(), .io_N6_n(), .io_R1_p(), .io_T1_n(),
    .io_M4_p(), .io_N4_n(), .io_P2_p(), .io_R2_n(), .io_V5_p(), .io_V4_n(),
    .io_U2_p(), .io_V2_n(), .io_U4_p(), .io_U3_n(), .io_U1_p(), .io_V1_n(),
    .io_K5_p(), .io_L4_n(), .io_M3_p(), .io_M2_n(), .io_N2_p(), .io_N1_n(),
    .io_K3_p(), .io_L3_n(), .io_L1_p(), .io_M1_n(), .io_H6_p(1'b0), .io_H5_n(1'b0),
    .io_K2_p(1'b0), .io_K1_n(1'b0), .io_J3_p(1'b0), .io_J2_n(1'b0), .io_J4_p(1'b0), .io_H4_n(1'b0),
    .io_G4_p(1'b0), .io_G3_n(1'b0), .io_F1_p(1'b0), .io_E1_n(1'b0), .io_H1_p(1'b0), .io_G1_n(1'b0),
    .io_C2_p(1'b0), .io_C1_n(1'b0), .io_H2_p(1'b0), .io_G2_n(1'b0), .io_E2_p(1'b0), .io_D2_n(1'b0),
    .adc_clk_p(adc_clk_p), .adc_clk_n(adc_clk_n), .adc_dco_p(adc_dco_p), .adc_dco_n(adc_dco_n), .io_D5_p(1'b0), .io_D4_n(1'b0),
    .io_B3_p(1'b0), .io_B2_n(1'b0), .io_B1_p(1'b0), .io_A1_n(1'b0), .io_A5(1'b0), .io_A6(1'b0),
    .io_B7_p(1'b0), .io_B6_n(1'b0),
    .probe(np)
  );
  // read-data bus bit order (one-hot writes to register 0x15, T15e)
  wire [15:0] rdata = {np[6], np[0], np[13], np[5], np[4], np[16], np[10], np[3],
                       np[12], np[14], np[9], np[2], np[8], np[1], np[7], np[11]};
  // the RTL's reset: released after RST_LEN clocks, like the netlist's global reset FF (SLICE_X10Y76/BFF)
  localparam integer RST_LEN = 16;
  reg [15:0] rcnt = 16'd0;
  wire rst = (rcnt < RST_LEN);
  always @(posedge adc_clk_p) if (rst) rcnt <= rcnt + 16'd1;
  wire rtx, brd, bwr;
  ft710_uart_link l (.clk(adc_clk_p), .rst(rst), .rx(uart_b_rx), .tx(rtx), .bus_rd(brd), .bus_wr(bwr),
                     .bus_addr(), .bus_wdata(), .bus_rdata(rdata));
  assign probe = {np[15], bwr, brd, rtx ^ uart_b_tx, rtx, uart_b_tx};
endmodule
`default_nettype wire
