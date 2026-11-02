// Register-map sweep harness for the whole recovered SDR netlist (T24 SDR round 2): MAIN register frames on UART B,
// and a log of the probed register-bank nets (write enables, register bits, bus flip-flops) around each frame.
// Build: tools/xc7_probe_netlist.py --ports OBJ/probe_ports.h --declared NETLIST.json build/sdr/ft710_sdr.v OUT.v OUT.names @PROBES
//        NET=OUT.v OBJ=<dir> PROBE_W=<words> PROBE_PORTS=1 MAIN=regmap_main.cpp hdl/sdr/sim/build_full.sh
//        (the probe list of round 2 is written by the commands in hdl/sdr/README.md, "Register file").
// Run:   Vft710_sdr CLOCKS FRAME ...      FRAME = MAIN frame without checksum (w00150001, r0015); sum8 + CR are added
//        and GAP_BITS idle bits (default 4) follow each frame. Frames start at clock 60,000. Every input other than
//        the clock and UART B is 0.
// Output: "F <clock> <frame>" when a frame starts, "B <clock> <hex>" for each UART B reply byte,
//        "S <clock> <hex words>" (all probes, LSW first) at QUIET_TO, then "P <clock> <index> <value>" for every change
//        of a probe that did not toggle in the calibration window [QUIET_FROM, QUIET_TO] (defaults 20,000 / 59,000),
//        and at the end "N <index> <toggles>" for the probes that did (free-running logic, not printed per change)
//        or that changed more than MAX_PRINT times (default 200) after it (printing stops there; the count goes on).
#include "Vft710_sdr.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <string>
#include <vector>

static const double CLK_PER_BIT = 125e6 / 115200.0;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    auto* top = new Vft710_sdr;
    uint64_t N = argc > 1 ? strtoull(argv[1], 0, 10) : 1000000;
    std::vector<std::string> frames, names;
    for (int a = 2; a < argc; a++) {
        std::string f = argv[a];
        unsigned sum = 0; for (char c : f) sum += (unsigned char)c;
        char t[4]; snprintf(t, sizeof t, "%02X", sum & 0xFF);
        names.push_back(f); f += t; f += '\r'; frames.push_back(f);
    }
    int gap = getenv("GAP_BITS") ? atoi(getenv("GAP_BITS")) : 4;
    uint64_t qfrom = getenv("QUIET_FROM") ? strtoull(getenv("QUIET_FROM"), 0, 10) : 20000;
    uint64_t qto = getenv("QUIET_TO") ? strtoull(getenv("QUIET_TO"), 0, 10) : 59000;
#include "probe_ports.h"
    static uint32_t prev[PROBE_W], noisy[PROBE_W];
    static uint64_t tog[PROBE_W * 32], nprint[PROBE_W * 32];
    uint64_t max_print = getenv("MAX_PRINT") ? strtoull(getenv("MAX_PRINT"), 0, 10) : 200;
    std::deque<int> bits; size_t nf = 0; double next = 60000; int level = 1;
    int brx_state = 0, brx_last = 1, brx_n = 0; unsigned brx_byte = 0; double brx_t0 = 0;
    top->uart_a_rx = 1; top->uart_b_rx = 1;
    for (uint64_t clk = 1; clk <= N; clk++) {
        if (bits.empty() && nf < frames.size() && clk >= next) {
            printf("F %llu %s\n", (unsigned long long)clk, names[nf].c_str());
            for (unsigned char c : frames[nf]) {
                bits.push_back(0); for (int i = 0; i < 8; i++) bits.push_back((c >> i) & 1); bits.push_back(1);
            }
            for (int i = 0; i < gap; i++) bits.push_back(1);
            nf++; next = clk;
        }
        if (!bits.empty() && clk >= next) { level = bits.front(); bits.pop_front(); next += CLK_PER_BIT; }
        top->uart_b_rx = level;
        top->adc_clk_p = 0; top->adc_clk_n = 1; top->adc_dco_p = 0; top->adc_dco_n = 1; top->eval();
        top->adc_clk_p = 1; top->adc_clk_n = 0; top->adc_dco_p = 1; top->adc_dco_n = 0; top->eval();
        {
            int b = top->uart_b_tx & 1;
            if (brx_state == 0) { if (brx_last == 1 && b == 0) { brx_state = 1; brx_t0 = clk; brx_n = 0; brx_byte = 0; } }
            else if (clk >= brx_t0 + CLK_PER_BIT * (brx_n + 1.5)) {
                if (brx_n < 8) brx_byte |= b << brx_n;
                else { printf("B %llu %02X\n", (unsigned long long)clk, brx_byte); brx_state = 0; }
                brx_n++;
            }
            brx_last = b;
        }
        if (clk == qto) {
            printf("S %llu", (unsigned long long)clk);
            for (int w = 0; w < PROBE_W; w++) printf(" %08x", PROBE_WORD(w));
            printf("\n");
        }
        for (int w = 0; w < PROBE_W; w++) {
            uint32_t pv = PROBE_WORD(w), d = pv ^ prev[w];
            if (d) {
                if (clk >= qfrom && clk <= qto) noisy[w] |= d;
                if (clk > qto) {
                    uint32_t nd = d & noisy[w];
                    for (int b = 0; b < 32; b++) if ((nd >> b) & 1) tog[w * 32 + b]++;
                    uint32_t pd = d & ~noisy[w];
                    for (int b = 0; b < 32; b++)
                        if ((pd >> b) & 1) {
                            int i = w * 32 + b;
                            if (++nprint[i] <= max_print) printf("P %llu %d %d\n", (unsigned long long)clk, i, (pv >> b) & 1);
                            else tog[i]++;
                        }
                }
            }
            prev[w] = pv;
        }
    }
    for (int i = 0; i < PROBE_W * 32; i++) if (tog[i]) printf("N %d %llu\n", i, (unsigned long long)tog[i]);
    delete top; return 0;
}
