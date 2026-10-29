// Two-channel ADC harness for the whole netlist (#172): drives ADC channel A (pairs H1 H2 G4 J4 J3 K2 H6) and channel B
// (B1 B3 C2 E2 F1 D5 B7) with the bit map traced in docs/code/sdr/netlist.md 3.7 (pair k = bits 2k on the rising edge /
// IDDR Q1 and 2k+1 on the falling edge / Q2), plays MAIN frames on UART B from clock 60000 and prints probe snapshots.
// Needs a probed netlist (tools/xc7_probe_netlist.py) and the DDR IDDR model: build with
//   -CFLAGS "-DPROBE_W=<words>" and verilator -DIDDR_DDR (see hdl/sdr/README.md).
// Usage: Vft710_sdr CLOCKS SNAPFROM SNAPEVERY [FRAME...]   FRAME e.g. w00128000 (sum + CR added)
//   prints "<clock> S <A value> <B value> <probe words, LSW first>" every SNAPEVERY clocks from SNAPFROM.
// Env ADCA / ADCB: "sine:PERIOD:AMP", "const:VALUE", "noise:AMP" (14-bit two's complement values); default 0.
#include "Vft710_sdr.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <string>
struct Chan {
    int mode = 0; double per = 0, amp = 0; int val = 0; uint32_t lfsr = 12345;
    void parse(const char* s) {
        if (!s) return;
        if (!strncmp(s, "sine:", 5)) { mode = 1; sscanf(s + 5, "%lf:%lf", &per, &amp); }
        else if (!strncmp(s, "const:", 6)) { mode = 2; val = atoi(s + 6); }
        else if (!strncmp(s, "noise:", 6)) { mode = 3; amp = atof(s + 6); }
    }
    int sample(uint64_t clk) {
        if (mode == 1) return (int)lround(amp * sin(2 * M_PI * clk / per));
        if (mode == 2) return val;
        if (mode == 3) { lfsr = lfsr * 1664525u + 1013904223u; return (int)((lfsr >> 8) % (2 * (int)amp + 1)) - (int)amp; }
        return 0;
    }
};
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    auto* top = new Vft710_sdr;
    uint64_t N = strtoull(argv[1], 0, 10), s0 = strtoull(argv[2], 0, 10), se = strtoull(argv[3], 0, 10);
    std::deque<int> bits;
    for (int a = 4; a < argc; a++) {
        std::string f = argv[a]; unsigned sum = 0; for (char c : f) sum += (unsigned char)c;
        char t[4]; snprintf(t, sizeof t, "%02X", sum & 0xFF); f += t; f += '\r';
        for (unsigned char c : f) { bits.push_back(0); for (int i = 0; i < 8; i++) bits.push_back((c >> i) & 1); bits.push_back(1); }
        for (int i = 0; i < 300; i++) bits.push_back(1);
    }
    double next = 60000; int level = 1;
    Chan A, B; A.parse(getenv("ADCA")); B.parse(getenv("ADCB"));
    // pair k carries bits 2k (rising edge, IDDR Q1) and 2k+1 (falling edge, Q2), traced in #172
    CData* pa[7] = {&top->io_H1_p, &top->io_H2_p, &top->io_G4_p, &top->io_J4_p, &top->io_J3_p, &top->io_K2_p, &top->io_H6_p};
    CData* pb[7] = {&top->io_B1_p, &top->io_B3_p, &top->io_C2_p, &top->io_E2_p, &top->io_F1_p, &top->io_D5_p, &top->io_B7_p};
    top->uart_a_rx = 1; top->uart_b_rx = 1;
    for (uint64_t clk = 1; clk <= N; clk++) {
        if (clk >= next && !bits.empty()) { level = bits.front(); bits.pop_front(); next += 125e6 / 115200.0; }
        top->uart_b_rx = level;
        int va = A.sample(clk) & 0x3FFF, vb = B.sample(clk) & 0x3FFF;
        for (int k = 0; k < 7; k++) { *pa[k] = (va >> (2 * k + 1)) & 1; *pb[k] = (vb >> (2 * k + 1)) & 1; }   // odd bits before the falling edge
        top->adc_clk_p = 0; top->adc_clk_n = 1; top->adc_dco_p = 0; top->adc_dco_n = 1; top->eval();
        for (int k = 0; k < 7; k++) { *pa[k] = (va >> (2 * k)) & 1; *pb[k] = (vb >> (2 * k)) & 1; }           // even bits before the rising edge
        top->adc_clk_p = 1; top->adc_clk_n = 0; top->adc_dco_p = 1; top->adc_dco_n = 0; top->eval();
        if (clk >= s0 && (clk - s0) % se == 0) {
            printf("%llu S %d %d", (unsigned long long)clk, va, vb);
            for (int w = 0; w < PROBE_W; w++) printf(" %08x", (uint32_t)top->probe[w]);
            printf("\n");
        }
    }
    delete top; return 0;
}
