// FT-710 SDR FPGA: read side of the register file (T24 SDR round 3; netlist.md 5.2), behavioural reconstruction.
//
// Rebuilt from the recovered netlist of FT-710_SDR_V0104. The read data that the UART B link latches (and the UART A
// console prints) are 16 flip-flops in SLICE_X9..X14Y63..Y70 behind a two-stage mux, so a word appears two clocks
// after its address is on the bus:
//
//   stage 1  four 16-bit group registers, one per 16 addresses of 0x00..0x3F: group g loads the word of address a
//            while a[15:4] = g, and 0xCCCC otherwise (64 flip-flops: SLICE_X34Y66.., X13Y62.., X8Y70.., X12Y65..;
//            the 0xCCCC comes from synchronous resets and sets decoded from the address)
//   stage 2  the read-data flip-flops select by a[15:4] (and a[15:8], a[15:12], a[15:13] for the windows):
//              a[15:4] = 0x000..0x003   group register a[5:4]
//              a[15:8] = 0x01           status window 0x0100..0x01FF: {8'h00, stw} (stw: SLICE_X13Y78/AFF and the
//                                       seven SLICE_X12Y61 flip-flops, loaded by another block; netlist.md 5.2)
//              a[15:12] = 0x3           0x3000..0x3FFF: capture RAM pair RAMB18_X0Y26 / X0Y27
//              a[15:13] = 3'b100        0x8000..0x9FFF: capture RAM pair RAMB18_X0Y24 / X0Y25
//              a[15:13] = 3'b110        0xC000..0xDFFF: capture RAM pair RAMB18_X0Y22 / X0Y23
//              anything else            0xCCCC
//            A RAM pair gives one byte each, interleaved: bit 2j from the first RAM's byte, bit 2j+1 from the second's.
//            The RAM addresses are not part of this block (the RAM outputs are inputs here).
//
// The word of an address in 0x00..0x3F (stage 1): 0x00 = 0x0104 (the version, V01-04); 0x03..0x27, 0x2E, 0x30, 0x31,
// 0x37 = the registers of ft710_regfile (regfile.v) at their own bit positions, unimplemented bits 0; 0x32 = the
// register in bits 3..0 and four status bits in 15..12; 0x01, 0x02, 0x2F, 0x33, 0x38..0x3F = status words of other
// blocks (the inputs st01 .. st3f, at their bit positions; only the bits that exist are used, see the masks below);
// 0x28..0x2D, 0x34..0x36 = 0xCCCC.
// Address bits a6..a15 are the bus flip-flops in the order settled by the one-hot read frames of round 3 (netlist.md
// 5.2). Checked against its netlist slice on every clock (tb_regread.v -DSTRUCT; hdl/sdr/README.md).
`default_nettype none
module ft710_regread (
  input  wire        clk,
  input  wire [15:0] a,             // bus address (SLICE_X8..X15Y83..Y89)
  input  wire [15:0] r03, r04, r05, r06, r07, r08, r09, r0a, r0b, r0c, r0d, r0e, r0f, r10, r11, r12, r13, r14,
                     r15, r16, r17, r18, r19, r1a, r1b, r1c, r1d, r1e, r1f, r20, r21, r22, r23, r24, r25, r26,
                     r27, r2e, r30, r31, r32, r37,                      // ft710_regfile outputs
  input  wire [15:0] st01, st02, st2f, st32, st33, st38, st39, st3a, st3b, st3c, st3d, st3e, st3f,  // status words
  input  wire [7:0]  stw,           // status window byte
  input  wire [7:0]  m24, m25,      // RAMB18_X0Y24 DO16..23, RAMB18_X0Y25 DOBDO0..7
  input  wire [7:0]  m26, m27,      // RAMB18_X0Y26 DO0..7,   RAMB18_X0Y27 DOADO0..7
  input  wire [7:0]  m22, m23,      // RAMB18_X0Y22 DO16..23, RAMB18_X0Y23 DOBDO0..7
  output reg  [15:0] rd = 16'h0000  // read data (SLICE_X9..X14Y63..Y70)
);
  localparam [15:0] UNMAPPED = 16'hCCCC;

  function [15:0] word(input [5:0] x);
    case (x)
      6'h00: word = 16'h0104;
      6'h01: word = st01 & 16'h000F;
      6'h02: word = st02 & 16'h4300;
      6'h03: word = r03;  6'h04: word = r04;  6'h05: word = r05;  6'h06: word = r06;  6'h07: word = r07;
      6'h08: word = r08;  6'h09: word = r09;  6'h0A: word = r0a;  6'h0B: word = r0b;  6'h0C: word = r0c;
      6'h0D: word = r0d;  6'h0E: word = r0e;  6'h0F: word = r0f;  6'h10: word = r10;  6'h11: word = r11;
      6'h12: word = r12;  6'h13: word = r13;  6'h14: word = r14;  6'h15: word = r15;  6'h16: word = r16;
      6'h17: word = r17;  6'h18: word = r18;  6'h19: word = r19;  6'h1A: word = r1a;  6'h1B: word = r1b;
      6'h1C: word = r1c;  6'h1D: word = r1d;  6'h1E: word = r1e;  6'h1F: word = r1f;  6'h20: word = r20;
      6'h21: word = r21;  6'h22: word = r22;  6'h23: word = r23;  6'h24: word = r24;  6'h25: word = r25;
      6'h26: word = r26;  6'h27: word = r27;  6'h2E: word = r2e;
      6'h2F: word = {{3{st2f[12]}}, st2f[12:0]};          // bits 15..12 are one flip-flop (SLICE_X1Y57/DFF)
      6'h30: word = r30;  6'h31: word = r31;
      6'h32: word = {st32[15:12], 8'h00, r32[3:0]};
      6'h33: word = st33;
      6'h37: word = r37;
      6'h38: word = st38; 6'h39: word = st39; 6'h3A: word = st3a; 6'h3B: word = st3b; 6'h3C: word = st3c;
      6'h3D: word = {4'b1000, st3d[11:0]};                // bit 15 reads 1, 14..12 read 0
      6'h3E: word = st3e & 16'hFFF8;
      6'h3F: word = st3f & 16'hFFF8;
      default: word = UNMAPPED;                          // 0x28..0x2D, 0x34..0x36
    endcase
  endfunction

  function [15:0] interleave(input [7:0] ev, input [7:0] od);
    integer j;
    for (j = 0; j < 8; j = j + 1) begin
      interleave[2 * j] = ev[j];
      interleave[2 * j + 1] = od[j];
    end
  endfunction

  // stage 1: one register per group of 16 addresses
  reg [15:0] grp [0:3];
  integer i;
  initial for (i = 0; i < 4; i = i + 1) grp[i] = 16'h0000;
  always @(posedge clk)
    for (i = 0; i < 4; i = i + 1)
      grp[i] <= (a[15:4] == i) ? word({i[1:0], a[3:0]}) : UNMAPPED;

  // stage 2
  always @(posedge clk)
    if (a[15:6] == 10'd0)          rd <= grp[a[5:4]];
    else if (a[15:8] == 8'h01)     rd <= {8'h00, stw};
    else if (a[15:12] == 4'h3)     rd <= interleave(m26, m27);
    else if (a[15:13] == 3'b100)   rd <= interleave(m24, m25);
    else if (a[15:13] == 3'b110)   rd <= interleave(m22, m23);
    else                           rd <= UNMAPPED;
endmodule
`default_nettype wire
