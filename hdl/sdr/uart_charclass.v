// FT-710 SDR FPGA: character classes of the UART command parser (T15e).
//
// The parser behind each UART decodes the received byte with a set of LUTs (UART A: SLICE_X1Y92..X3Y94).
// Evaluating those LUTs over all 256 byte values (docs/code/sdr/netlist.md 3.4 and 4.3) gives these sets [fact]:
//   SLICE_X1Y92/DLUT = 0 exactly for 0-9 A-F a-f          -> is_hex
//   SLICE_X3Y94/DLUT = 0 exactly for CR                   -> is_cr
//   SLICE_X3Y93/DLUT = 0 exactly for BS and CR            -> is_bs | is_cr
//   SLICE_X1Y93/BLUT = 0 for BS LF CR space , 0-7 r w x   (part of a larger decode)
//   SLICE_X2Y93/DLUT = 0 for LF space # 0 2 4 6 8 A C E G a c e r x   (bit 0 of a code, part of the decode)
// The individual LUTs are slices of a wider decoder; this module gives the classes they add up to
// [inference]: hex digits with their value, the command letters r/w/x, separators and line control.

`default_nettype none
module ft710_uart_charclass (
  input  wire [7:0] c,
  output wire       is_hex,
  output wire [3:0] hex_val,
  output wire       is_r, is_w, is_x,   // command letters (lower case only)
  output wire       is_sep,             // ',' or ' '
  output wire       is_cr, is_lf, is_bs
);
  wire dig = (c >= "0" && c <= "9");
  wire up  = (c >= "A" && c <= "F");
  wire lo  = (c >= "a" && c <= "f");
  assign is_hex  = dig | up | lo;
  assign hex_val = dig ? c[3:0] : (c[3:0] + 4'd9);   // 'A'/'a' = 0x41/0x61 -> 1 + 9 = 10
  assign is_r    = (c == "r");
  assign is_w    = (c == "w");
  assign is_x    = (c == "x");
  assign is_sep  = (c == ",") | (c == " ");
  assign is_cr   = (c == 8'h0D);
  assign is_lf   = (c == 8'h0A);
  assign is_bs   = (c == 8'h08);
endmodule
`default_nettype wire
