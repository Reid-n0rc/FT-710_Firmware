// RX IF stream harness for the whole recovered SDR netlist (#193): ADC tone in, MAIN register frames on UART B,
// the I2S-style output port (U16 bit clock, V17 frame, M17 / V16 data) decoded per half-frame.
// Build: MAIN=ddc_main.cpp OBJ=obj_ddc VDEFS="+define+MMCM_FRAC +define+IDDR_DDR" hdl/sdr/sim/build_full.sh
//        (MMCM_FRAC: DSP_CLK = 18.432 MHz instead of 125 MHz; IDDR_DDR: both ADC clock edges captured).
// Run:   Vft710_sdr CLOCKS [FRAME | @CLOCK] ...
//        FRAME = MAIN frame without checksum (w000A0004, r0000), sent on UART B with sum8 + CR, GAP_BITS idle bits
//        (default 30) after each; @CLOCK holds the next frame until that clock. Frames start at clock 60000.
// Env:   ADC=tone:F_HZ:AMP[,F_HZ:AMP...]  14-bit sample per 125 MHz clock, sum of sines (AMP in LSB, full scale 8191),
//            on both ADC channels (ADC2=off: channel 2 at 0; ADC2=same (default)). ADCFMT=offset for offset binary.
//            Bit map [inference, from the capture RAMs RAMB36_X0Y11/X0Y12]: pair k carries bits 2k (rising edge)
//            and 2k+1 (falling edge); channel 1 pairs H1 H2 G4 J4 J3 K2 H6, channel 2 B1 B3 C2 E2 F1 D5 B7 (k = 0..6).
//        HALF_FROM=CLOCK (default 0): print "H <clock> <V17> <M17 word> <V16 word>" for every half-frame after it, the
//            32 bits sampled on rising U16 edges since the last V17 edge, first bit = MSB.
//        Built with -DPROBE_W=<words> (tools/xc7_probe_netlist.py) it prints "<clock> P <index> <value>" for every
//        probe bit change between PROBE_FROM and PROBE_TO (default: whole run), a full "<clock> S <words>" snapshot
//        at PROBE_FROM, or with PROBE_COUNT=1 only "T <index> <toggles>" per probe bit over that window at the end.
//        DUMP=W0-W1:FROM:TO:EVERY prints "D <clock> <hex words W0..W1>" every EVERY clocks in [FROM, TO] (probe
//        words, LSW first), for time series of internal buses.
//        UART B replies are printed as "B <clock> <hex>".
#include "Vft710_sdr.h"
#include "verilated.h"
#include <cmath>
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
    // UART B player
    struct Item { uint64_t at; std::string bytes; };
    std::vector<Item> items;
    uint64_t hold = 0;
    for (int a = 2; a < argc; a++) {
        std::string f = argv[a];
        if (f[0] == '@') { hold = strtoull(f.c_str() + 1, 0, 10); continue; }
        unsigned sum = 0; for (char c : f) sum += (unsigned char)c;
        char t[4]; snprintf(t, sizeof t, "%02X", sum & 0xFF); f += t; f += '\r';
        items.push_back({hold, f}); hold = 0;
    }
    std::deque<int> bits; size_t next_item = 0;
    int gap = getenv("GAP_BITS") ? atoi(getenv("GAP_BITS")) : 30;
    double next = 60000; int level = 1;
    // ADC
    struct Tone { double f, a; };
    std::vector<Tone> tones;
    const char* adc = getenv("ADC");
    if (adc && !strncmp(adc, "tone:", 5)) {
        std::string s = adc + 5; size_t p = 0;
        while (p < s.size()) {
            size_t q = s.find(',', p); if (q == std::string::npos) q = s.size();
            std::string t = s.substr(p, q - p); size_t c = t.find(':');
            tones.push_back({atof(t.substr(0, c).c_str()), c == std::string::npos ? 4000.0 : atof(t.substr(c + 1).c_str())});
            p = q + 1;
        }
    }
    bool offset = getenv("ADCFMT") && !strcmp(getenv("ADCFMT"), "offset");
    bool ch2off = getenv("ADC2") && !strcmp(getenv("ADC2"), "off");
    CData* ch1[7] = {&top->io_H1_p, &top->io_H2_p, &top->io_G4_p, &top->io_J4_p, &top->io_J3_p, &top->io_K2_p, &top->io_H6_p};
    CData* ch2[7] = {&top->io_B1_p, &top->io_B3_p, &top->io_C2_p, &top->io_E2_p, &top->io_F1_p, &top->io_D5_p, &top->io_B7_p};
    uint64_t half_from = getenv("HALF_FROM") ? strtoull(getenv("HALF_FROM"), 0, 10) : 0;
#ifdef PROBE_W
#if PROBE_W > 2
#define PROBE_WORD(w) ((uint32_t)top->probe[w])
#else
#define PROBE_WORD(w) ((uint32_t)((uint64_t)top->probe >> (32 * (w))))
#endif
    uint64_t pfrom = getenv("PROBE_FROM") ? strtoull(getenv("PROBE_FROM"), 0, 10) : 0;
    uint64_t pto = getenv("PROBE_TO") ? strtoull(getenv("PROBE_TO"), 0, 10) : ~0ull;
    static uint32_t prev[PROBE_W];
    bool pcount = getenv("PROBE_COUNT") != nullptr;
    static uint64_t tog[PROBE_W * 32];
    int dw0 = -1, dw1 = -1; unsigned long long dfrom = 0, dto = 0, devery = 1;
    if (getenv("DUMP")) sscanf(getenv("DUMP"), "%d-%d:%llu:%llu:%llu", &dw0, &dw1, &dfrom, &dto, &devery);
#endif
    int last_u16 = 0, last_v17 = 0; uint32_t wm = 0, wv = 0; int nb = 0;
    int brx_state = 0, brx_last = 1, brx_n = 0; unsigned brx_byte = 0; double brx_t0 = 0;
    top->uart_a_rx = 1; top->uart_b_rx = 1;
    for (uint64_t clk = 1; clk <= N; clk++) {
        if (bits.empty() && next_item < items.size() && clk >= next && clk >= items[next_item].at) {
            for (unsigned char c : items[next_item].bytes) {
                bits.push_back(0); for (int i = 0; i < 8; i++) bits.push_back((c >> i) & 1); bits.push_back(1);
            }
            for (int i = 0; i < gap; i++) bits.push_back(1);
            next_item++; next = clk;
        }
        if (!bits.empty() && clk >= next) { level = bits.front(); bits.pop_front(); next += CLK_PER_BIT; }
        top->uart_b_rx = level;
        // ADC sample for this clock
        double x = 0; for (auto& t : tones) x += t.a * sin(2 * M_PI * t.f * (double)clk / 125e6);
        int v = (int)lround(x); if (v > 8191) v = 8191; if (v < -8192) v = -8192;
        unsigned u = (unsigned)v & 0x3FFF; if (offset) u ^= 0x2000;
        // falling half: odd bits; rising half: even bits
        for (int k = 0; k < 7; k++) { *ch1[k] = (u >> (2 * k + 1)) & 1; *ch2[k] = ch2off ? 0 : (u >> (2 * k + 1)) & 1; }
        top->adc_clk_p = 0; top->adc_clk_n = 1; top->adc_dco_p = 0; top->adc_dco_n = 1; top->eval();
        for (int k = 0; k < 7; k++) { *ch1[k] = (u >> (2 * k)) & 1; *ch2[k] = ch2off ? 0 : (u >> (2 * k)) & 1; }
        top->adc_clk_p = 1; top->adc_clk_n = 0; top->adc_dco_p = 1; top->adc_dco_n = 0; top->eval();
        // I2S-style port
        int u16 = top->io_U16 & 1, v17 = top->io_V17 & 1;
        if (v17 != last_v17) {
            if (clk >= half_from) printf("H %llu %d %08x %08x %d\n", (unsigned long long)clk, last_v17, wm, wv, nb);
            wm = wv = 0; nb = 0;
        }
        if (u16 && !last_u16) { wm = (wm << 1) | (top->io_M17 & 1); wv = (wv << 1) | (top->io_V16 & 1); nb++; }
        last_u16 = u16; last_v17 = v17;
        {   // UART B replies
            int b = top->uart_b_tx & 1;
            if (brx_state == 0) { if (brx_last == 1 && b == 0) { brx_state = 1; brx_t0 = clk; brx_n = 0; brx_byte = 0; } }
            else if (clk >= brx_t0 + CLK_PER_BIT * (brx_n + 1.5)) {
                if (brx_n < 8) brx_byte |= b << brx_n;
                else { printf("B %llu %02X\n", (unsigned long long)clk, brx_byte); brx_state = 0; }
                brx_n++;
            }
            brx_last = b;
        }
#ifdef PROBE_W
        if (dw0 >= 0 && clk >= dfrom && clk <= dto && (clk - dfrom) % devery == 0) {
            printf("D %llu", (unsigned long long)clk);
            for (int w = dw0; w <= dw1 && w < PROBE_W; w++) printf(" %08x", PROBE_WORD(w));
            printf("\n");
        }
        if (clk == pfrom && !pcount) {
            printf("%llu S", (unsigned long long)clk);
            for (int w = 0; w < PROBE_W; w++) printf(" %08x", PROBE_WORD(w));
            printf("\n");
        }
        for (int w = 0; w < PROBE_W; w++) {
            uint32_t pv = PROBE_WORD(w), d = pv ^ prev[w];
            if (d && clk >= pfrom && clk <= pto)
                for (int b = 0; b < 32; b++)
                    if ((d >> b) & 1) {
                        if (pcount) tog[w * 32 + b]++;
                        else printf("%llu P %d %d\n", (unsigned long long)clk, w * 32 + b, (pv >> b) & 1);
                    }
            prev[w] = pv;
        }
#endif
    }
#ifdef PROBE_W
    if (pcount) for (int i = 0; i < PROBE_W * 32; i++) if (tog[i]) printf("T %d %llu\n", i, (unsigned long long)tog[i]);
#endif
    delete top; return 0;
}
