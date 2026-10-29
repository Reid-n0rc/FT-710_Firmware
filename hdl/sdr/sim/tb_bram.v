// Testbench for the block-RAM models in xc7_bram_vl.v (#164). Synthetic contents only.
//
//  1. RAMB36E1 x9 against the same memory written as two RAMB18E1 x4 halves (the pre-#164 netlist reading):
//     INIT/INITP of the RAMB36 are the bit-interleave of the halves' (RAMB36 bit j = half Y(j%2) bit j/2), the
//     data pins interleave the same way (bit 2k = lower half pin k). The 8 data bits must agree at every address;
//     the RAMB36 parity bit of entry i must be INITP bit i of the interleaved vector, which the halves cannot give.
//  2. RAMB36E1 x9 writes on port A (data + parity, random addresses), read back on port B.
//  3. RAMB18E1 x18 byte-enable writes and x9 reads of the same memory (mixed aspect ratio); SDP x36.
// Run: iverilog -g2012 -o /tmp/tbb.vvp hdl/sdr/sim/tb_bram.v hdl/sdr/sim/xc7_bram_vl.v && vvp -n /tmp/tbb.vvp
`timescale 1ns/1ps
module tb_bram;
  reg clk = 0;
  always #4 clk = ~clk;
  // half contents (lower Y0 = L, upper Y1 = U); interleaved RAMB36 versions below
  localparam [255:0] L0 = 256'h0123456789abcdef_fedcba9876543210_00ff00ff00ff00ff_a5a5a5a55a5a5a5a;
  localparam [255:0] U0 = 256'h1111222233334444_5555666677778888_99990000aaaabbbb_ccccddddeeeeffff;
  localparam [255:0] LP = 256'hdeadbeef_00000000_ffffffff_12345678_9abcdef0_0f0f0f0f_f0f0f0f0_13579bdf;
  localparam [255:0] UP = 256'hcafef00d_ffffffff_00000000_87654321_0fedcba9_33333333_cccccccc_2468ace0;
  function automatic [511:0] ilv(input [255:0] a, input [255:0] b);
    integer j;
    for (j = 0; j < 256; j = j + 1) begin ilv[2*j] = a[j]; ilv[2*j+1] = b[j]; end
  endfunction
  localparam [511:0] I36 = ilv(L0, U0);
  localparam [511:0] P36 = ilv(LP, UP);

  reg [15:0] addr = 0;
  reg [7:0] din = 0; reg pin = 0; reg we = 0;
  wire [31:0] da36, db36; wire [3:0] dpa36, dpb36;
  RAMB36E1 #(.READ_WIDTH_A(9), .READ_WIDTH_B(9), .WRITE_WIDTH_A(9), .WRITE_WIDTH_B(9),
             .INIT_00(I36[255:0]), .INIT_01(I36[511:256]), .INITP_00(P36[255:0]), .INITP_01(P36[511:256]),
             .IS_RSTRAMARSTRAM_INVERTED(1'b1), .IS_RSTRAMB_INVERTED(1'b1),
             .IS_RSTREGARSTREG_INVERTED(1'b1), .IS_RSTREGB_INVERTED(1'b1)) r36 (
    .CLKARDCLK(clk), .CLKBWRCLK(clk), .ENARDEN(1'b1), .ENBWREN(1'b1), .REGCEAREGCE(1'b1), .REGCEB(1'b1),
    .RSTRAMARSTRAM(1'b1), .RSTRAMB(1'b1), .RSTREGARSTREG(1'b1), .RSTREGB(1'b1),
    .CASCADEINA(1'b0), .CASCADEINB(1'b0), .INJECTDBITERR(1'b0), .INJECTSBITERR(1'b0),
    .ADDRARDADDR(addr), .ADDRBWRADDR(addr), .DIADI({24'b0, din}), .DIBDI(32'b0), .DIPADIP({3'b0, pin}),
    .DIPBDIP(4'b0), .WEA({4{we}}), .WEBWE(8'b0), .DOADO(da36), .DOBDO(db36), .DOPADOP(dpa36), .DOPBDOP(dpb36));
  // the same as two x4 halves (read only)
  wire [15:0] dl, du; wire [1:0] dpl, dpu;
  RAMB18E1 #(.READ_WIDTH_A(4), .WRITE_WIDTH_A(4), .READ_WIDTH_B(4), .WRITE_WIDTH_B(4), .INIT_00(L0),
             .INITP_00(LP)) hl (
    .CLKARDCLK(clk), .CLKBWRCLK(clk), .ENARDEN(1'b1), .ENBWREN(1'b0), .REGCEAREGCE(1'b0), .REGCEB(1'b0),
    .RSTRAMARSTRAM(1'b0), .RSTRAMB(1'b0), .RSTREGARSTREG(1'b0), .RSTREGB(1'b0),
    .ADDRARDADDR(addr[14:1]), .ADDRBWRADDR(14'b0), .DIADI(16'b0), .DIBDI(16'b0), .DIPADIP(2'b0),
    .DIPBDIP(2'b0), .WEA(2'b0), .WEBWE(4'b0), .DOADO(dl), .DOBDO(), .DOPADOP(dpl), .DOPBDOP());
  RAMB18E1 #(.READ_WIDTH_A(4), .WRITE_WIDTH_A(4), .READ_WIDTH_B(4), .WRITE_WIDTH_B(4), .INIT_00(U0),
             .INITP_00(UP)) hu (
    .CLKARDCLK(clk), .CLKBWRCLK(clk), .ENARDEN(1'b1), .ENBWREN(1'b0), .REGCEAREGCE(1'b0), .REGCEB(1'b0),
    .RSTRAMARSTRAM(1'b0), .RSTRAMB(1'b0), .RSTREGARSTREG(1'b0), .RSTREGB(1'b0),
    .ADDRARDADDR(addr[14:1]), .ADDRBWRADDR(14'b0), .DIADI(16'b0), .DIBDI(16'b0), .DIPADIP(2'b0),
    .DIPBDIP(2'b0), .WEA(2'b0), .WEBWE(4'b0), .DOADO(du), .DOBDO(), .DOPADOP(dpu), .DOPBDOP());
  wire [7:0] split = {du[3], dl[3], du[2], dl[2], du[1], dl[1], du[0], dl[0]};

  // x18 / x9 / SDP x36 on RAMB18E1
  reg [13:0] a18 = 0, b18 = 0; reg [15:0] d18 = 0; reg [1:0] p18 = 0; reg [1:0] we18 = 0;
  wire [15:0] q18a, q18b; wire [1:0] qp18a, qp18b;
  RAMB18E1 #(.READ_WIDTH_A(18), .WRITE_WIDTH_A(18), .READ_WIDTH_B(9), .WRITE_WIDTH_B(9),
             .WRITE_MODE_A("READ_FIRST")) r18 (
    .CLKARDCLK(clk), .CLKBWRCLK(clk), .ENARDEN(1'b1), .ENBWREN(1'b1), .REGCEAREGCE(1'b0), .REGCEB(1'b0),
    .RSTRAMARSTRAM(1'b0), .RSTRAMB(1'b0), .RSTREGARSTREG(1'b0), .RSTREGB(1'b0),
    .ADDRARDADDR(a18), .ADDRBWRADDR(b18), .DIADI(d18), .DIBDI(16'b0), .DIPADIP(p18), .DIPBDIP(2'b0),
    .WEA(we18), .WEBWE(4'b0), .DOADO(q18a), .DOBDO(q18b), .DOPADOP(qp18a), .DOPBDOP(qp18b));
  reg [13:0] sa = 0, sw = 0; reg [31:0] sd = 0; reg [3:0] sp = 0, swe = 0;
  wire [15:0] sq0, sq1; wire [1:0] sqp0, sqp1;
  RAMB18E1 #(.RAM_MODE("SDP"), .READ_WIDTH_A(36), .WRITE_WIDTH_B(36), .DOA_REG(1),
             .RSTREG_PRIORITY_A("REGCE")) sdp (
    .CLKARDCLK(clk), .CLKBWRCLK(clk), .ENARDEN(1'b1), .ENBWREN(1'b1), .REGCEAREGCE(1'b1), .REGCEB(1'b0),
    .RSTRAMARSTRAM(1'b0), .RSTRAMB(1'b0), .RSTREGARSTREG(1'b0), .RSTREGB(1'b0),
    .ADDRARDADDR(sa), .ADDRBWRADDR(sw), .DIADI(sd[15:0]), .DIBDI(sd[31:16]), .DIPADIP(sp[1:0]),
    .DIPBDIP(sp[3:2]), .WEA(2'b0), .WEBWE(swe), .DOADO(sq0), .DOBDO(sq1), .DOPADOP(sqp0), .DOPBDOP(sqp1));

  integer i, err = 0, n = 0, seed = 7;
  reg [8:0] model [0:4095];
  reg [12:0] ra;
  initial begin
    // 1. read sweep over the initialized part (entries 0..63 hold INIT_00/01)
    for (i = 0; i < 64; i = i + 1) begin
      addr = {1'b0, i[11:0], 3'b111};          // low 3 bits unused at x9
      @(posedge clk); #1; @(posedge clk); #1;  // DOA_REG = 0: latch after one edge; second edge = settle
      if (da36[7:0] !== split || da36[7:0] !== I36[8*i +: 8] || dpa36[0] !== P36[i]) begin
        err = err + 1;
        if (err < 10) $display("x9 read %0d: r36 %h p%b split %h init %h p%b", i, da36[7:0], dpa36[0], split,
                               I36[8*i +: 8], P36[i]);
      end
      n = n + 1;
    end
    $display("1. RAMB36 x9 vs 2 x RAMB18 x4: %0d entries, data and interleaved parity, %0d errors", n, err);
    // 2. random x9 writes on port A, read back on port B
    for (i = 0; i < 4096; i = i + 1) model[i] = 9'bx;
    for (i = 0; i < 300; i = i + 1) begin
      ra = $random(seed); din = $random(seed); pin = $random(seed);
      addr = {1'b0, ra[11:0], 3'b0}; we = 1; @(posedge clk); #1; we = 0;
      model[ra[11:0]] = {pin, din};
    end
    n = 0;
    for (i = 0; i < 4096; i = i + 1)
      if (model[i] !== 9'bx) begin
        addr = {1'b0, i[11:0], 3'b0}; @(posedge clk); #1; @(posedge clk); #1;
        if ({dpb36[0], db36[7:0]} !== model[i]) begin
          err = err + 1;
          if (err < 10) $display("x9 write %0d: got %h want %h", i, {dpb36[0], db36[7:0]}, model[i]);
        end
        n = n + 1;
      end
    $display("2. RAMB36 x9 write A / read B: %0d addresses, %0d errors total", n, err);
    // 3. x18 write with byte enables, read back as x18 (READ_FIRST) and as x9 on port B
    a18 = 14'd5 << 4; d18 = 16'hbeef; p18 = 2'b10; we18 = 2'b11; @(posedge clk); #1;
    a18 = 14'd5 << 4; d18 = 16'h1200; p18 = 2'b01; we18 = 2'b10; @(posedge clk); #1;  // high byte only
    we18 = 0; @(posedge clk); #1;
    if ({qp18a, q18a} !== {2'b00, 16'h12ef}) begin err = err + 1; $display("x18 byte write: %b %h", qp18a, q18a); end
    b18 = 14'd10 << 3; @(posedge clk); #1;   // x9 entry 10 = low byte of x18 entry 5
    if ({qp18b[0], q18b[7:0]} !== 9'h0ef) begin err = err + 1; $display("x9 lo: %b %h", qp18b[0], q18b[7:0]); end
    b18 = 14'd11 << 3; @(posedge clk); #1;
    if ({qp18b[0], q18b[7:0]} !== 9'h012) begin err = err + 1; $display("x9 hi: %b %h", qp18b[0], q18b[7:0]); end
    // SDP x36: write two words, read with the output register (2 edges)
    sw = 14'd3 << 5; sd = 32'hcafe_f00d; sp = 4'b1010; swe = 4'b1111; @(posedge clk); #1;
    sw = 14'd4 << 5; sd = 32'h1234_5678; sp = 4'b0101; @(posedge clk); #1; swe = 0;
    sa = 14'd3 << 5; @(posedge clk); #1; @(posedge clk); #1;
    if ({sqp1, sqp0, sq1, sq0} !== {4'b1010, 32'hcafef00d}) begin
      err = err + 1; $display("SDP x36: %b %h%h", {sqp1, sqp0}, sq1, sq0); end
    $display("3. RAMB18 x18 byte enables, x9 view, SDP x36: %0d errors total", err);
    if (err) $display("FAIL"); else $display("PASS");
    $finish;
  end
endmodule
