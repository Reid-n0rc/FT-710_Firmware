  // Echo of a received byte (#147, from the whole-netlist simulation, build/sdr/runs/echo_all.txt):
  // the console's character set comes back as itself (0-9 A-F G r w x space , LF), lower-case a-f in upper case,
  // "#" as 0x06, BS as itself, every other byte as "?" ("s" right after "r" comes back as ":", in the parser).
  // Open: TAB and BS in some states produced extra bytes (BS SP BS) in the netlist [#147 follow-up].
  function [7:0] echo_of(input [7:0] c);
    if ((c >= "0" && c <= "9") || (c >= "A" && c <= "G") || c == "r" || c == "w" || c == "x" || c == " " ||
        c == "," || c == 8'h0A || c == 8'h08)
      echo_of = c;
    else if (c >= "a" && c <= "f") echo_of = c - 8'h20;
    else if (c == "#") echo_of = 8'h06;
    else echo_of = "?";
  endfunction
