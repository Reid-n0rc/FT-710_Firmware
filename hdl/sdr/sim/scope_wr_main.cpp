// Scope-writer harness for the whole recovered SDR netlist (#186): logs the writes into the scope ping-pong RAM
// RAMB18_X2Y21 (port A, 125 MHz) and decodes the frames on N14/T18/R18 as scope_main.cpp does, so the RAM contents
// can be compared with the bytes sent. Probe (bit order matters):
//   python3 -I tools/xc7_probe_netlist.py build/sdr/netlist.json build/sdr/ft710_sdr.v build/sdr/vl/ft710_wr.v \
//     build/sdr/vl/wr.names SLICE_X35Y127/BFF SLICE_X41Y120/AFF SLICE_X41Y120/BFF SLICE_X41Y120/CFF SLICE_X41Y120/DFF \
//     SLICE_X38Y123/BFF SLICE_X41Y120/D5FF SLICE_X41Y120/C5FF SLICE_X41Y120/B5FF SLICE_X41Y120/A5FF SLICE_X37Y120/AFF \
//     SLICE_X41Y110/AFF SLICE_X58Y53/BLUT.O5 SLICE_X58Y53/BLUT.O6 SLICE_X58Y53/ALUT.O5 SLICE_X58Y53/ALUT.O6 \
//     SLICE_X58Y54/BLUT.O5 SLICE_X58Y54/BLUT.O6 SLICE_X58Y54/ALUT.O5 SLICE_X58Y54/ALUT.O6 SLICE_X34Y53/AFF \
//     SLICE_X28Y73/A5FF SLICE_X12Y48/AFF SLICE_X5Y50/AFF SLICE_X12Y49/AFF SLICE_X1Y36/ALUT
//   (0 write enable, 1..11 port-A address bits 3..13, 12..19 DIADI0..7, 20 read bank, 21 enable, 22 N14, 23 T18, 24 R18,
//   25 tri-state)
//   NET=build/sdr/vl/ft710_wr.v OBJ=obj_wr MAIN=scope_wr_main.cpp PROBE_W=1 VDEFS="+define+IDDR_DDR" hdl/sdr/sim/build_full.sh
// Run:   Vft710_sdr CLOCKS [FRAME ...]   MAIN register frames as in scope_main.cpp (GAP, INPUTS, ADC=noise / ADC=sine:PERIOD,
//        AMP; the ADC drive is pins_main.cpp's pin order, not the #172 bit map).
// Output: "R clk0 clk1 bank i0 i1 n" runs of consecutive indexes written, "BANK clk read=b writes=n" at each bank switch
//        followed by "B clk bank" and the 850 bytes last written into the bank now being read, "F start end nbits period"
//        and the first 850 bytes of each frame, "EN clk v" for the enable flop. WLOG=N also prints the first N writes as
//        "W clk bank index data-before-edge data-after-edge"; DCUR=1 stores the data-after-edge value instead.
#include "Vft710_sdr.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    auto* top = new Vft710_sdr;
    uint64_t N = argc > 1 ? strtoull(argv[1], 0, 10) : 2000000;
    int gap = getenv("GAP") ? atoi(getenv("GAP")) : 300;
    int wlog = getenv("WLOG") ? atoi(getenv("WLOG")) : 0;   // print every write up to this many
    int dcur = getenv("DCUR") ? atoi(getenv("DCUR")) : 0;
    std::deque<int> bits;
    for (int a = 2; a < argc; a++) {
        std::string f = argv[a]; unsigned sum = 0; for (char c : f) sum += (unsigned char)c;
        char t[4]; snprintf(t, sizeof t, "%02X", sum & 0xFF); f += t; f += '\r';
        for (unsigned char c : f) { bits.push_back(0); for (int i = 0; i < 8; i++) bits.push_back((c >> i) & 1); bits.push_back(1); }
        for (int i = 0; i < gap; i++) bits.push_back(1);
    }
    double next = 60000; int level = 1;
    struct In { const char* name; CData* p; };
    std::vector<In> ins = {
#define I(x) {#x, &top->x},
        I(io_U13) I(io_T13) I(io_V10) I(io_T11) I(io_T14) I(io_R15) I(io_P15) I(io_L15) I(io_B18) I(io_A14) I(io_A13) I(io_A16)
    };
    const char* inspec = getenv("INPUTS") ? getenv("INPUTS") : "io_R15=1";
    CData* adc[14] = {&top->io_H6_p, &top->io_K2_p, &top->io_J3_p, &top->io_J4_p, &top->io_G4_p, &top->io_F1_p,
                      &top->io_H1_p, &top->io_C2_p, &top->io_H2_p, &top->io_E2_p, &top->io_D5_p, &top->io_B3_p,
                      &top->io_B1_p, &top->io_B7_p};
    const char* adcmode = getenv("ADC") ? getenv("ADC") : "";
    double adcper = strncmp(adcmode, "sine:", 5) == 0 ? atof(adcmode + 5) : 0;
    double adcamp = getenv("AMP") ? atof(getenv("AMP")) : 6000.0;
    uint32_t lfsr = 0xACE1u;
    auto adcset = [&](uint64_t clk) {
        if (!strcmp(adcmode, "noise")) {
            for (int i = 0; i < 14; i++) { lfsr = lfsr * 1664525u + 1013904223u; *adc[i] = (lfsr >> 31) & 1; }
        } else if (adcper > 0) {
            int v = (int)lround(adcamp * sin(2 * M_PI * clk / adcper)) & 0x3FFF;
            for (int i = 0; i < 14; i++) *adc[i] = (v >> i) & 1;
        }
    };
    CData* pads[3] = {&top->io_N14, &top->io_T18, &top->io_R18};
    int mem[2][1024]; for (auto& b : mem) for (auto& x : b) x = -1;
    uint64_t wcnt = 0, nw = 0;
    long ra0 = -1, rlast = -1, rbank = -1; uint64_t rc0 = 0, rc1 = 0, rn = 0;
    auto flush = [&]() { if (ra0 >= 0) printf("R %llu %llu %ld %ld %ld %llu\n", (unsigned long long)rc0, (unsigned long long)rc1, rbank, ra0, rlast, (unsigned long long)rn); ra0 = -1; };
    uint32_t prev = 0; int lastbank = -1, lasten = -1;
    int last[3] = {-1, -1, -1}; bool insel = false; uint64_t fstart = 0, lastfs = 0; std::vector<int> fb;
    top->uart_a_rx = 1; top->uart_b_rx = 1;
    for (uint64_t clk = 1; clk <= N; clk++) {
        if (clk >= next && !bits.empty()) { level = bits.front(); bits.pop_front(); next += 125e6 / 115200.0; }
        top->uart_b_rx = level;
        for (auto& in : ins) { const char* f = strstr(inspec, in.name); *in.p = (f && f[strlen(in.name)] == '=') ? (f[strlen(in.name) + 1] == '1') : 0; }
        adcset(clk);
        top->adc_clk_p = 0; top->adc_clk_n = 1; top->adc_dco_p = 0; top->adc_dco_n = 1; top->eval();
        if (!strcmp(adcmode, "noise")) adcset(clk);
        top->adc_clk_p = 1; top->adc_clk_n = 0; top->adc_dco_p = 1; top->adc_dco_n = 0; top->eval();
        uint32_t pr = (uint32_t)top->probe;
        if (prev & 1) {   // the write sampled at this edge used the previous cycle's values (DCUR=1: data after the edge)
            int addr = (prev >> 1) & 0x7FF, data = ((dcur ? pr : prev) >> 12) & 0xFF;
            int bank = addr >> 10, idx = addr & 1023;
            mem[bank][idx] = data; nw++;
            if (wcnt < (uint64_t)wlog) { printf("W %llu %d %d %02X %02X\n", (unsigned long long)clk, bank, idx, (prev >> 12) & 0xFF, (pr >> 12) & 0xFF); wcnt++; }
            if (ra0 >= 0 && bank == rbank && idx == rlast + 1) { rlast = idx; rc1 = clk; rn++; }
            else { flush(); ra0 = rlast = idx; rbank = bank; rc0 = rc1 = clk; rn = 1; }
        }
        int bank = (pr >> 20) & 1, en = (pr >> 21) & 1;
        if (en != lasten) { flush(); printf("EN %llu %d\n", (unsigned long long)clk, en); lasten = en; }
        if (bank != lastbank) {
            flush();
            printf("BANK %llu read=%d writes=%llu\n", (unsigned long long)clk, bank, (unsigned long long)nw);
            if (lastbank >= 0) {   // the bank just finished writing is the one now read
                printf("B %llu %d\n", (unsigned long long)clk, bank);
                for (int i = 0; i < 850; i++) {
                    if (mem[bank][i] < 0) printf("--"); else printf("%02X", mem[bank][i]);
                    printf("%s", i % 25 == 24 ? "\n" : " ");
                }
            }
            lastbank = bank;
        }
        int T = (pr >> 25) & 1, v[3];
        for (int i = 0; i < 3; i++) { v[i] = T ? 0 : (pr >> (22 + i)) & 1; *pads[i] = v[i]; }
        if (last[1] >= 0) {
            if (!insel && last[1] == 1 && v[1] == 0) { insel = true; fstart = clk; fb.clear(); }
            else if (insel && v[1] == 1) {
                insel = false;
                printf("F %llu %llu %zu period %llu\n", (unsigned long long)fstart, (unsigned long long)clk, fb.size(),
                       (unsigned long long)(lastfs ? fstart - lastfs : 0));
                lastfs = fstart;
                for (size_t b = 0; b + 8 <= fb.size() && b < 8 * 850; b += 8) {
                    int x = 0; for (int k = 0; k < 8; k++) x = x << 1 | fb[b + k];
                    printf("%02X%s", x, (b / 8) % 25 == 24 ? "\n" : " ");
                }
                printf("\n");
            }
            if (insel && last[2] == 1 && v[2] == 0) fb.push_back(v[0]);
        }
        for (int i = 0; i < 3; i++) last[i] = v[i];
        prev = pr;
    }
    flush();
    printf("writes %llu\n", (unsigned long long)nw);
    delete top; return 0;
}
