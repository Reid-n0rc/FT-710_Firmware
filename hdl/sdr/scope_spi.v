// ft710_scope_spi: the FT-710 SDR FPGA's scope frame serializer (#186), the master side of the DISPLAY's RSPI2 link
// (J2002 FFT_CLK / FFT_FRM / FFT_DAT). Behavioural reconstruction from the recovered netlist
// (docs/code/sdr/netlist.md section 5.6); it contains no bitstream data.
//
// Netlist cells it stands for (all in the dsp_clk domain, MMCM_X0Y0 CLKOUT0 via BUFHCE_X0Y9/X0Y21/X1Y8/X1Y20):
//   frame counter   SLICE_X14Y50..X14Y54 (20-bit CARRY4 counter, wraps at 614,399)
//   spi_clk  (R18)  SLICE_X12Y49/AFF     spi_cs_n (T18) SLICE_X5Y50/AFF    spi_dat (N14) SLICE_X12Y48/AFF
//   byte register   SLICE_X57Y48..X57Y50 (8 FDCE, loaded via SLICE_X47Y49/DLUT, bit select MUXF7 SLICE_X57Y49/F7AMUX)
//   read address    SLICE_X15Y49/AFF, SLICE_X58Y49, SLICE_X58Y50 (10 bits), bank bit SLICE_X34Y53/AFF
//   clear           SLICE_X13Y53/CLUT = rst | ~en (async: counters cleared, the three pin flops preset to 1)
// The pins are tri-stated by the IOB while input R15 is low (SLICE_X1Y36/ALUT = ~R15 on all three T inputs); that
// is outside this module.
//
// Frame (one per 614,400 clocks): select low for 435,233 clocks, 13,600 bits = 1,700 bytes, MSB first, 32 clocks per
// bit (clock high-idle, data changes on the rising edge, the slave samples on the falling edge: SPI mode 2 / 3-wire).
// Bytes 0..849 are RAM bytes 0..849 of the bank the writer is not filling (or the address low byte in test mode);
// bytes 850..1699 are the constant 0xCC. Matches the netlist slice cycle by cycle (tb_scope_spi.v -DSTRUCT).
`default_nettype none
module ft710_scope_spi (
    input  wire        clk,        // dsp_clk
    input  wire        rst,        // dsp_clk-domain reset (SLICE_X1Y47/AFF), active high, asynchronous clear
    input  wire        en,         // scope enable register bit (SLICE_X28Y73/A5FF), asynchronous clear while 0
    input  wire        ramp,       // test pattern select (SLICE_X40Y60/BFF): send the address low byte
    output wire [10:0] rd_addr,    // {bank, index} to RAMB18_X2Y21 port B (x9, DOB_REG = 1: data two clocks later)
    input  wire [7:0]  rd_data,
    output reg         spi_clk,    // R18
    output reg         spi_cs_n,   // T18
    output reg         spi_dat     // N14
);
    localparam [19:0] LAST    = 20'd614399;   // frame period - 1
    localparam [19:0] CS_ON   = 20'd481, CS_OFF = 20'd435714;
    localparam [19:0] CLK_ON  = 20'd529;
    localparam [19:0] HALF2   = 20'd217856 + 20'd256;   // first load of byte 850
    localparam [19:0] IDX_CLR = 20'd218105;

    wire clr = rst | ~en;
    reg  [19:0] c;
    reg  [9:0]  idx;
    reg         bank;
    reg  [7:0]  sh;
    assign rd_addr = {bank, idx};

    wire [19:0] cn   = (c == LAST) ? 20'd0 : c + 20'd1;
    wire        load = cn >= 20'd512 && cn[7:0] == 8'd0 && cn <= 20'd435712;   // byte k at 512 + 256 k, k = 0..1700
    wire [19:0] cb   = cn - CLK_ON;
    wire [2:0]  bitn = 3'd7 - cn[7:5] + (cn[4:0] == 5'd0 ? 3'd1 : 3'd0);         // MSB first, bit j from 513 + 32 j

    always @(posedge clk or posedge clr)
        if (clr) begin
            c <= 0; idx <= 0; bank <= 0; sh <= 0;
            spi_clk <= 1; spi_cs_n <= 1; spi_dat <= 1;
        end else begin
            c <= cn;
            if (cn == 0) bank <= ~bank;
            if (cn == 20'd1 || cn == IDX_CLR) idx <= 0;
            else if (load) idx <= idx + 10'd1;
            if (load) sh <= (cn >= HALF2) ? 8'hCC : ramp ? idx[7:0] : rd_data;
            spi_cs_n <= !(cn >= CS_ON && cn < CS_OFF);
            spi_clk  <= !(cn >= CLK_ON && cn < CS_OFF && (!cb[4] || cn == CS_OFF - 20'd1));
            spi_dat  <= (cn > 20'd512 && cn < CS_OFF - 20'd1) ? sh[bitn] : 1'b0;
        end
endmodule
`default_nettype wire
