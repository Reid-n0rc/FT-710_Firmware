// Pin-activity harness for the whole recovered SDR netlist (#90): counts transitions on the unassigned bank 14/15 outputs.
// Build: OBJ=obj_pins hdl/sdr/sim/build_full.sh with this file instead of full_main.cpp (MAIN=pins_main.cpp).
// Run:   Vft710_sdr CLOCKS [FRAME ...]   FRAME = MAIN register frame without checksum, e.g. w00152000 (sent on UART B
//        from clock 60000, sum8 + CR added). LOGPINS="io_R16 io_P17" LOGTO=CLOCK prints "E clock pin level" per edge.
#include "Vft710_sdr.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <deque>
struct Pin { const char* name; CData* p; int last = -1; uint64_t n = 0, first = 0, lastt = 0, maxgap = 0, bursts = 0; };
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    auto* top = new Vft710_sdr;
    uint64_t N = argc > 1 ? strtoull(argv[1], 0, 10) : 2000000;
    const char* logpins = getenv("LOGPINS") ? getenv("LOGPINS") : "";
    uint64_t logto = getenv("LOGTO") ? strtoull(getenv("LOGTO"), 0, 10) : 0;
    std::vector<Pin> pins = {
#define P(x) {#x, &top->x},
        P(io_T9) P(io_V17) P(io_U16) P(io_U17) P(io_V16) P(io_V15) P(io_T16) P(io_R16) P(io_T15) P(io_P17) P(io_N16)
        P(io_N15) P(io_M17) P(io_L16) P(dsp_clk) P(io_N14) P(io_T18) P(io_R18) P(io_D17) P(io_E17) P(io_F13) P(io_B14)
        P(io_B13) P(io_C14) P(io_D14) P(flash_cs_n) P(flash_d0)
    };
    // UART B player: frames from argv[2..] ("w00152000" -> + sum8 + CR), 300 idle bits between, starting at clock 60000
    std::deque<int> bits;
    for (int a = 2; a < argc; a++) {
        std::string f = argv[a]; unsigned sum = 0; for (char c : f) sum += (unsigned char)c;
        char t[4]; snprintf(t, sizeof t, "%02X", sum & 0xFF); f += t; f += '\r';
        for (unsigned char c : f) { bits.push_back(0); for (int i = 0; i < 8; i++) bits.push_back((c >> i) & 1); bits.push_back(1); }
        for (int i = 0; i < 300; i++) bits.push_back(1);
    }
    double next = 60000; int level = 1;
    top->uart_a_rx = 1; top->uart_b_rx = 1;
    for (uint64_t clk = 1; clk <= N; clk++) {
        if (clk >= next && !bits.empty()) { level = bits.front(); bits.pop_front(); next += 125e6 / 115200.0; }
        top->uart_b_rx = level;
        top->adc_clk_p = 0; top->adc_clk_n = 1; top->adc_dco_p = 0; top->adc_dco_n = 1; top->eval();
        top->adc_clk_p = 1; top->adc_clk_n = 0; top->adc_dco_p = 1; top->adc_dco_n = 0; top->eval();
        for (auto& q : pins) {
            int v = *q.p & 1;
            if (q.last >= 0 && v != q.last && clk <= logto && strstr(logpins, q.name)) printf("E %llu %s %d\n", (unsigned long long)clk, q.name, v);
            if (q.last >= 0 && v != q.last) {
                if (!q.n) q.first = clk;
                else { uint64_t g = clk - q.lastt; if (g > q.maxgap) q.maxgap = g; if (g > 200) q.bursts++; }
                q.n++; q.lastt = clk;
            }
            q.last = v;
        }
    }
    for (auto& q : pins)
        printf("%-11s toggles %9llu first %9llu last %9llu bursts(gap>200) %6llu maxgap %9llu level %d\n", q.name,
               (unsigned long long)q.n, (unsigned long long)q.first, (unsigned long long)q.lastt,
               (unsigned long long)q.bursts, (unsigned long long)q.maxgap, q.last);
    delete top; return 0;
}
