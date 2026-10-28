// Verilator harness for the whole recovered FT-710 SDR netlist (T15e).
//
// Drives the 125 MHz fabric clock (adc_clk_p, also adc_dco_p), plays byte strings into uart_a_rx / uart_b_rx as
// 115,200 baud 8N1 frames and decodes uart_a_tx / uart_b_tx with a software UART. Every received byte is printed
// with its clock number. Built against build/sdr/ft710_sdr.v (derived, never committed); see hdl/sdr/README.md.
//
// usage: Vft710_sdr [a:STRING | b:STRING | w:BITS | x:HEXBYTES@a|b] ...
//   a:/b: send STRING (C escapes \r \n \xHH) on UART A / B; w: idle for BITS bit times on both lines.
//   The run ends 200 bit times after the last stimulus, or when 'w' and the queues are done.
// Built with -DPROBE_W=<words> against a netlist with a `probe` port (tools/xc7_probe_netlist.py) it also prints
// "<clock> P <index> <value>" for every probe bit that changes (the first line set is the state at clock 1), or with
// s:CLOCK arguments only full snapshots "<clock> S <hex words>" at those clocks.
#include "Vft710_sdr.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <string>
#include <vector>

static const double CLK_PER_BIT = 125e6 / 115200.0;   // 1085.07

struct TxLine {                       // software UART on a DUT output
    const char* name;
    int state = 0;                    // 0 idle, 1 receiving
    double t0 = 0;                    // clock of the start-bit falling edge
    int last = 1;
    int nbit = 0;
    unsigned byte = 0;
    std::vector<unsigned> got;
    void step(uint64_t clk, int v) {
        if (state == 0) {
            if (last == 1 && v == 0) { state = 1; t0 = (double)clk; nbit = 0; byte = 0; }
        } else {
            double sample = t0 + CLK_PER_BIT * (nbit + 1.5);
            if ((double)clk >= sample) {
                if (nbit < 8) byte |= (unsigned)v << nbit;
                else {
                    printf("%10llu %s TX %02X '%c'%s\n", (unsigned long long)clk, name, byte,
                           (byte >= 32 && byte < 127) ? byte : '.', v ? "" : "  (no stop bit)");
                    got.push_back(byte);
                    state = 0;
                }
                nbit++;
            }
        }
        last = v;
    }
};

struct RxLine {                       // byte player on a DUT input
    std::deque<int> bits;             // -1 = idle bit
    double next = 0;
    int level = 1;
    void push_byte(unsigned b) {
        bits.push_back(0);
        for (int i = 0; i < 8; i++) bits.push_back((b >> i) & 1);
        bits.push_back(1);
    }
};

static std::string unescape(const char* s) {
    std::string o;
    for (; *s; s++) {
        if (*s != '\\') { o += *s; continue; }
        s++;
        if (*s == 'r') o += '\r';
        else if (*s == 'n') o += '\n';
        else if (*s == 'b') o += '\b';
        else if (*s == 'x') { char h[3] = {s[1], s[2], 0}; o += (char)strtol(h, nullptr, 16); s += 2; }
        else o += *s;
    }
    return o;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vft710_sdr* top = new Vft710_sdr;
    // stimulus: a list of (line, bits) steps, played in order
    struct Step { int line; std::string bytes; int idle; };
    std::vector<Step> steps;
    std::vector<uint64_t> snaps;          // s:CLOCK snapshot times (ascending); with snapshots, changes are not printed
    size_t si_snap = 0;
    for (int i = 1; i < argc; i++) {
        const char* a = argv[i];
        if (a[0] == '+') continue;
        if ((a[0] == 'a' || a[0] == 'b') && a[1] == ':') steps.push_back({a[0] == 'a' ? 0 : 1, unescape(a + 2), 0});
        else if (a[0] == 'w' && a[1] == ':') steps.push_back({-1, "", atoi(a + 2)});
        else if (a[0] == 's' && a[1] == ':') snaps.push_back(strtoull(a + 2, nullptr, 10));
        else { fprintf(stderr, "bad arg %s\n", a); return 2; }
    }
    TxLine ta{"A"}, tb{"B"};
    RxLine ra, rb;
    size_t si = 0;
    double idle_until = 20000;          // let the reset counter release first
    uint64_t clk = 0;
    uint64_t end_at = 0;
    top->uart_a_rx = 1; top->uart_b_rx = 1;
    while (true) {
        // feed the next step when both players are empty and the idle time is over
        if (ra.bits.empty() && rb.bits.empty() && (double)clk >= idle_until) {
            if (si < steps.size()) {
                Step& s = steps[si++];
                if (s.line < 0) idle_until = (double)clk + s.idle * CLK_PER_BIT;
                else {
                    RxLine& r = s.line ? rb : ra;
                    for (unsigned char c : s.bytes) r.push_byte(c);
                    r.next = (double)clk;
                }
            } else if (!end_at) end_at = clk + (uint64_t)(200 * CLK_PER_BIT);
        }
        for (RxLine* r : {&ra, &rb}) {
            if (!r->bits.empty() && (double)clk >= r->next) {
                r->level = r->bits.front(); r->bits.pop_front();
                r->next += CLK_PER_BIT;
                if (r->bits.empty()) idle_until = std::max(idle_until, r->next);
            }
        }
        top->uart_a_rx = ra.level;
        top->uart_b_rx = rb.level;
        top->adc_clk_p = 0; top->adc_clk_n = 1; top->adc_dco_p = 0; top->adc_dco_n = 1;
        top->eval();
        top->adc_clk_p = 1; top->adc_clk_n = 0; top->adc_dco_p = 1; top->adc_dco_n = 0;
        top->eval();
        clk++;
#ifdef PROBE_W                        // probe port added by tools/xc7_probe_netlist.py (> 64 bits wide)
        static uint32_t prev[PROBE_W];
        for (int w = 0; w < PROBE_W; w++) {
            uint32_t v = top->probe[w], d = v ^ prev[w];
            if (d && snaps.empty())
                for (int b = 0; b < 32; b++)
                    if ((d >> b) & 1) printf("%10llu P %d %d\n", (unsigned long long)clk, w * 32 + b, (v >> b) & 1);
            prev[w] = v;
        }
        if (si_snap < snaps.size() && clk == snaps[si_snap]) {   // full snapshot: "<clock> S <hex words, LSW first>"
            printf("%10llu S", (unsigned long long)clk);
            for (int w = 0; w < PROBE_W; w++) printf(" %08x", (uint32_t)top->probe[w]);
            printf("\n");
            si_snap++;
        }
#endif
        ta.step(clk, top->uart_a_tx);
        tb.step(clk, top->uart_b_tx);
        if (end_at && clk >= end_at) break;
        if ((clk & 0xFFFFF) == 0) { fprintf(stderr, "clk %llu\n", (unsigned long long)clk); fflush(stdout); }
    }
    printf("end at clock %llu; A sent %zu bytes, B sent %zu bytes\n", (unsigned long long)clk, ta.got.size(),
           tb.got.size());
    delete top;
    return 0;
}
