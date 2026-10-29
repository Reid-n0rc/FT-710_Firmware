// Scope-port harness for the whole recovered SDR netlist (#186): watches the three bidirectional bank-14 lines
// N14 / T18 / R18 that the FPGA drives while input R15 is high, and decodes the frames on them.
// The IOBUF model cannot drive a pad, so the netlist needs a probe port with the three output flip-flops and the
// shared tri-state net, then the control flops (in this order; probe bits 4.. are printed as "C clock hex" on change):
//   python3 -I tools/xc7_probe_netlist.py build/sdr/netlist.json build/sdr/ft710_sdr.v build/sdr/vl/ft710_scope.v \
//     build/sdr/vl/scope.names SLICE_X12Y48/AFF SLICE_X5Y50/AFF SLICE_X12Y49/AFF SLICE_X1Y36/ALUT \
//     SLICE_X28Y73/A5FF SLICE_X32Y73/AFF SLICE_X33Y73/AFF SLICE_X41Y70/B5FF SLICE_X40Y60/BFF
//   NET=build/sdr/vl/ft710_scope.v OBJ=obj_scope MAIN=scope_main.cpp PROBE_W=1 hdl/sdr/sim/build_full.sh
// Run:   Vft710_sdr CLOCKS [FRAME ...]   FRAME = MAIN register frame without checksum (w00152000), sent on UART B from
//        clock 60000 as in pins_main.cpp, GAP idle bits apart (default 300). INPUTS="io_R15=1,..." holds input pins (default io_R15=1).
//        While the tri-state net is 0 the harness copies each output flip-flop onto its pad (so the IOBUF inputs read
//        the driven level back, as on the board); otherwise the pads stay at 0.
//        LOGTO=CLOCK prints "E clock pin level" for every pad edge up to CLOCK.
//        The decoder treats T18 as the select (active low) and R18 as the bit clock (sampled on its falling edge, MSB
//        first), and prints "F start end nbits" and the bytes of every frame (DUMP=0 prints only the F lines).
//        ADC=noise / ADC=sine:PERIOD as in pins_main.cpp.
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
    uint64_t logto = getenv("LOGTO") ? strtoull(getenv("LOGTO"), 0, 10) : 0;
    int dump = getenv("DUMP") ? atoi(getenv("DUMP")) : 1;
    int gap = getenv("GAP") ? atoi(getenv("GAP")) : 300;
    std::deque<int> bits;                        // UART B player, as pins_main.cpp (GAP idle bits between frames)
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
    uint32_t lfsr = 0xACE1u;
    auto adcset = [&](uint64_t clk) {
        if (!strcmp(adcmode, "noise")) {
            for (int i = 0; i < 14; i++) { lfsr = lfsr * 1664525u + 1013904223u; *adc[i] = (lfsr >> 31) & 1; }
        } else if (adcper > 0) {
            int v = (int)lround(6000.0 * sin(2 * M_PI * clk / adcper)) & 0x3FFF;
            for (int i = 0; i < 14; i++) *adc[i] = (v >> i) & 1;
        }
    };
    const char* names[3] = {"io_N14", "io_T18", "io_R18"};
    CData* pads[3] = {&top->io_N14, &top->io_T18, &top->io_R18};
    int last[3] = {-1, -1, -1}, lastT = -1;
    uint32_t lastctl = ~0u;
    uint64_t ntog[3] = {0, 0, 0};
    // frame decoder: T18 low = selected, R18 falling = sample N14 (the FPGA changes data on the rising edge)
    bool insel = false; uint64_t fstart = 0; std::vector<int> fb;
    uint64_t nframes = 0, lastfs = 0;
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
        int T = (pr >> 3) & 1;
        if (T != lastT) { printf("T %llu %d\n", (unsigned long long)clk, T); lastT = T; }
        if ((pr >> 4) != lastctl) { printf("C %llu %X\n", (unsigned long long)clk, pr >> 4); lastctl = pr >> 4; }
        int v[3];
        for (int i = 0; i < 3; i++) { v[i] = T ? 0 : (pr >> i) & 1; *pads[i] = v[i]; }
        for (int i = 0; i < 3; i++) {
            if (last[i] >= 0 && v[i] != last[i]) {
                ntog[i]++;
                if (clk <= logto) printf("E %llu %s %d\n", (unsigned long long)clk, names[i], v[i]);
            }
        }
        if (last[1] >= 0) {
            if (!insel && last[1] == 1 && v[1] == 0) { insel = true; fstart = clk; fb.clear(); }
            else if (insel && v[1] == 1) {
                insel = false; nframes++;
                printf("F %llu %llu %zu period %llu\n", (unsigned long long)fstart, (unsigned long long)clk, fb.size(),
                       (unsigned long long)(lastfs ? fstart - lastfs : 0));
                lastfs = fstart;
                if (dump) {
                    for (size_t b = 0; b + 8 <= fb.size(); b += 8) {
                        int x = 0; for (int k = 0; k < 8; k++) x = x << 1 | fb[b + k];
                        printf("%02X%s", x, (b / 8) % 32 == 31 ? "\n" : " ");
                    }
                    printf("\n");
                }
            }
            if (insel && last[2] == 1 && v[2] == 0) fb.push_back(v[0]);
        }
        for (int i = 0; i < 3; i++) last[i] = v[i];
    }
    for (int i = 0; i < 3; i++) printf("%s toggles %llu level %d\n", names[i], (unsigned long long)ntog[i], last[i]);
    printf("frames %llu\n", (unsigned long long)nframes);
    delete top; return 0;
}
