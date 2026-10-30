  // Echo of a received byte (#147, #204, from the whole-netlist simulation):
  // the console's character set comes back as itself (0-9 A-F G r w x space , LF), lower-case a-f in upper case,
  // "#" as 0x06, "s" as ":", every other byte as "?". BS is handled in the parser (BS SP BS, or a stall).
  function [7:0] echo_of(input [7:0] c);
    if ((c >= "0" && c <= "9") || (c >= "A" && c <= "G") || c == "r" || c == "w" || c == "x" || c == " " ||
        c == "," || c == 8'h0A)
      echo_of = c;
    else if (c >= "a" && c <= "f") echo_of = c - 8'h20;
    else if (c == "#") echo_of = 8'h06;
    else if (c == "s") echo_of = ":";
    else echo_of = "?";
  endfunction
