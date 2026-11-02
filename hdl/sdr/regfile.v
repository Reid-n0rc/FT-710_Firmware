// FT-710 SDR FPGA: the register file written over the register bus (T24 SDR round 2; netlist.md 5.2), behavioural
// reconstruction of its write side.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104. The bus is the set of flip-flops the UART B link and the
// UART A console share (netlist.md 5.2, "Register file"): a 16-bit address, 16-bit write data and a one-clock write
// strobe, all registered in SLICE_X8..X15Y83..Y94 and 0 between transactions. Each register below is one write
// enable of the netlist (a LUT tree that decodes all 16 address bits and the strobe) and the flip-flops under it;
// every bit takes write-data bit k for register bit k. Address, implemented bits and reset values come from the
// netlist: the whole-netlist write sweep over UART B (hdl/sdr/sim/regmap_main.cpp) and the cones of the 42 enables.
//
// rst is the design's global synchronous reset (SLICE_X10Y76/BFF): it loads the reset value into every register
// except 0x27, which has no reset (power-up value 0) and ignores writes while rst is high.
// Bits outside a register's mask have no flip-flop and read as 0 here.
// Checked against its netlist slice on every clock (tb_regfile.v -DSTRUCT) and against the whole netlist's
// register flip-flops over UART B frames (tb_regfile.v -DTRACE; hdl/sdr/README.md).
`default_nettype none
module ft710_regfile (
  input  wire        clk,
  input  wire        rst,           // global synchronous reset (SLICE_X10Y76/BFF)
  input  wire        we,            // write strobe (bus flip-flop SLICE_X13Y86/A5FF), one clock per write
  input  wire [15:0] a,             // bus address
  input  wire [15:0] d,             // bus write data
  output reg  [15:0] r03,
  output reg  [15:0] r04,
  output reg  [15:0] r05,
  output reg  [15:0] r06,
  output reg  [15:0] r07,
  output reg  [15:0] r08,
  output reg  [15:0] r09,
  output reg  [15:0] r0a,
  output reg  [15:0] r0b,
  output reg  [15:0] r0c,
  output reg  [15:0] r0d,
  output reg  [15:0] r0e,
  output reg  [15:0] r0f,
  output reg  [15:0] r10,
  output reg  [15:0] r11,
  output reg  [15:0] r12,
  output reg  [15:0] r13,
  output reg  [15:0] r14,
  output reg  [15:0] r15,
  output reg  [15:0] r16,
  output reg  [15:0] r17,
  output reg  [15:0] r18,
  output reg  [15:0] r19,
  output reg  [15:0] r1a,
  output reg  [15:0] r1b,
  output reg  [15:0] r1c,
  output reg  [15:0] r1d,
  output reg  [15:0] r1e,
  output reg  [15:0] r1f,
  output reg  [15:0] r20,
  output reg  [15:0] r21,
  output reg  [15:0] r22,
  output reg  [15:0] r23,
  output reg  [15:0] r24,
  output reg  [15:0] r25,
  output reg  [15:0] r26,
  output reg  [15:0] r27,
  output reg  [15:0] r2e,
  output reg  [15:0] r30,
  output reg  [15:0] r31,
  output reg  [15:0] r32,
  output reg  [15:0] r37
);
  // address, implemented bits, reset value
  localparam [15:0] M03 = 16'hFFFF, R03 = 16'h8800;
  localparam [15:0] M04 = 16'hFFFF, R04 = 16'h8810;
  localparam [15:0] M05 = 16'hFFFF, R05 = 16'h0000;
  localparam [15:0] M06 = 16'hFFFF, R06 = 16'h020A;
  localparam [15:0] M07 = 16'hFFFF, R07 = 16'h0000;
  localparam [15:0] M08 = 16'hFFFF, R08 = 16'h00D5;
  localparam [15:0] M09 = 16'hFFFF, R09 = 16'h9F80;
  localparam [15:0] M0A = 16'hFFFF, R0A = 16'h0000;
  localparam [15:0] M0B = 16'h00FF, R0B = 16'h0058;
  localparam [15:0] M0C = 16'hFFFF, R0C = 16'h220E;
  localparam [15:0] M0D = 16'h00FF, R0D = 16'h000E;
  localparam [15:0] M0E = 16'hFFFF, R0E = 16'h1200;
  localparam [15:0] M0F = 16'hFFFF, R0F = 16'h1000;
  localparam [15:0] M10 = 16'hFF00, R10 = 16'hFF00;
  localparam [15:0] M11 = 16'hFF00, R11 = 16'hFF00;
  localparam [15:0] M12 = 16'hFFFF, R12 = 16'h8000;
  localparam [15:0] M13 = 16'hFFFF, R13 = 16'h8000;
  localparam [15:0] M14 = 16'hFFFF, R14 = 16'h2000;
  localparam [15:0] M15 = 16'hFFFF, R15 = 16'h1FFF;
  localparam [15:0] M16 = 16'h00FF, R16 = 16'h0010;
  localparam [15:0] M17 = 16'hFFFF, R17 = 16'h2000;
  localparam [15:0] M18 = 16'hFFFF, R18 = 16'h0089;
  localparam [15:0] M19 = 16'hFFFF, R19 = 16'h5440;
  localparam [15:0] M1A = 16'hFFFF, R1A = 16'h0000;
  localparam [15:0] M1B = 16'hFFFF, R1B = 16'h0000;
  localparam [15:0] M1C = 16'h000F, R1C = 16'h0000;
  localparam [15:0] M1D = 16'hFFFF, R1D = 16'h0000;
  localparam [15:0] M1E = 16'hFFFF, R1E = 16'h0000;
  localparam [15:0] M1F = 16'hFFFF, R1F = 16'h0190;
  localparam [15:0] M20 = 16'hFFFF, R20 = 16'h00D5;
  localparam [15:0] M21 = 16'hFFFF, R21 = 16'h9F80;
  localparam [15:0] M22 = 16'hFFFF, R22 = 16'h03E8;
  localparam [15:0] M23 = 16'hFFFF, R23 = 16'h8000;
  localparam [15:0] M24 = 16'h03FF, R24 = 16'h0317;
  localparam [15:0] M25 = 16'h0FFF, R25 = 16'h03FF;
  localparam [15:0] M26 = 16'hFFFF, R26 = 16'h0610;
  localparam [15:0] M27 = 16'hFFFF, R27 = 16'h0000;
  localparam [15:0] M2E = 16'hFFFF, R2E = 16'h0001;
  localparam [15:0] M30 = 16'hFFFF, R30 = 16'h0023;
  localparam [15:0] M31 = 16'hFFFF, R31 = 16'h0000;
  localparam [15:0] M32 = 16'h000F, R32 = 16'h0000;
  localparam [15:0] M37 = 16'hFFFF, R37 = 16'h0000;
  initial begin
    r03 = R03;
    r04 = R04;
    r05 = R05;
    r06 = R06;
    r07 = R07;
    r08 = R08;
    r09 = R09;
    r0a = R0A;
    r0b = R0B;
    r0c = R0C;
    r0d = R0D;
    r0e = R0E;
    r0f = R0F;
    r10 = R10;
    r11 = R11;
    r12 = R12;
    r13 = R13;
    r14 = R14;
    r15 = R15;
    r16 = R16;
    r17 = R17;
    r18 = R18;
    r19 = R19;
    r1a = R1A;
    r1b = R1B;
    r1c = R1C;
    r1d = R1D;
    r1e = R1E;
    r1f = R1F;
    r20 = R20;
    r21 = R21;
    r22 = R22;
    r23 = R23;
    r24 = R24;
    r25 = R25;
    r26 = R26;
    r27 = 16'h0000;
    r2e = R2E;
    r30 = R30;
    r31 = R31;
    r32 = R32;
    r37 = R37;
  end
  always @(posedge clk) begin
    if (rst) r03 <= R03; else if (we && a == 16'h0003) r03 <= d & M03;
    if (rst) r04 <= R04; else if (we && a == 16'h0004) r04 <= d & M04;
    if (rst) r05 <= R05; else if (we && a == 16'h0005) r05 <= d & M05;
    if (rst) r06 <= R06; else if (we && a == 16'h0006) r06 <= d & M06;
    if (rst) r07 <= R07; else if (we && a == 16'h0007) r07 <= d & M07;
    if (rst) r08 <= R08; else if (we && a == 16'h0008) r08 <= d & M08;
    if (rst) r09 <= R09; else if (we && a == 16'h0009) r09 <= d & M09;
    if (rst) r0a <= R0A; else if (we && a == 16'h000A) r0a <= d & M0A;
    if (rst) r0b <= R0B; else if (we && a == 16'h000B) r0b <= d & M0B;
    if (rst) r0c <= R0C; else if (we && a == 16'h000C) r0c <= d & M0C;
    if (rst) r0d <= R0D; else if (we && a == 16'h000D) r0d <= d & M0D;
    if (rst) r0e <= R0E; else if (we && a == 16'h000E) r0e <= d & M0E;
    if (rst) r0f <= R0F; else if (we && a == 16'h000F) r0f <= d & M0F;
    if (rst) r10 <= R10; else if (we && a == 16'h0010) r10 <= d & M10;
    if (rst) r11 <= R11; else if (we && a == 16'h0011) r11 <= d & M11;
    if (rst) r12 <= R12; else if (we && a == 16'h0012) r12 <= d & M12;
    if (rst) r13 <= R13; else if (we && a == 16'h0013) r13 <= d & M13;
    if (rst) r14 <= R14; else if (we && a == 16'h0014) r14 <= d & M14;
    if (rst) r15 <= R15; else if (we && a == 16'h0015) r15 <= d & M15;
    if (rst) r16 <= R16; else if (we && a == 16'h0016) r16 <= d & M16;
    if (rst) r17 <= R17; else if (we && a == 16'h0017) r17 <= d & M17;
    if (rst) r18 <= R18; else if (we && a == 16'h0018) r18 <= d & M18;
    if (rst) r19 <= R19; else if (we && a == 16'h0019) r19 <= d & M19;
    if (rst) r1a <= R1A; else if (we && a == 16'h001A) r1a <= d & M1A;
    if (rst) r1b <= R1B; else if (we && a == 16'h001B) r1b <= d & M1B;
    if (rst) r1c <= R1C; else if (we && a == 16'h001C) r1c <= d & M1C;
    if (rst) r1d <= R1D; else if (we && a == 16'h001D) r1d <= d & M1D;
    if (rst) r1e <= R1E; else if (we && a == 16'h001E) r1e <= d & M1E;
    if (rst) r1f <= R1F; else if (we && a == 16'h001F) r1f <= d & M1F;
    if (rst) r20 <= R20; else if (we && a == 16'h0020) r20 <= d & M20;
    if (rst) r21 <= R21; else if (we && a == 16'h0021) r21 <= d & M21;
    if (rst) r22 <= R22; else if (we && a == 16'h0022) r22 <= d & M22;
    if (rst) r23 <= R23; else if (we && a == 16'h0023) r23 <= d & M23;
    if (rst) r24 <= R24; else if (we && a == 16'h0024) r24 <= d & M24;
    if (rst) r25 <= R25; else if (we && a == 16'h0025) r25 <= d & M25;
    if (rst) r26 <= R26; else if (we && a == 16'h0026) r26 <= d & M26;
    if (rst) r2e <= R2E; else if (we && a == 16'h002E) r2e <= d & M2E;
    if (rst) r30 <= R30; else if (we && a == 16'h0030) r30 <= d & M30;
    if (rst) r31 <= R31; else if (we && a == 16'h0031) r31 <= d & M31;
    if (rst) r32 <= R32; else if (we && a == 16'h0032) r32 <= d & M32;
    if (rst) r37 <= R37; else if (we && a == 16'h0037) r37 <= d & M37;
    if (!rst && we && a == 16'h0027) r27 <= d;   // no reset
  end
endmodule
`default_nettype wire
