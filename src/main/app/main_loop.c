/* The main loop of the MAIN image (T24 MAIN round 5; docs/code/main/README.md "Main loop"): the 16 tasks in an
 * endless loop. Checked for one pass: equiv_main_emu.py FUNC_STOP stubs the tasks (each is checked on its own) and ends
 * the run at the second call of the first. A file of its own, so that GCC inlines none of the tasks (wdt_kick and the
 * other small ones of tasks.c would be, and their stubs then never called). */
void wdt_kick(void);
void io_task(void);
void rf_ctrl_task(void);
void dispreq_e8_task(void);
/* the 16 main-loop tasks, in their order (docs/code/main/README.md "Main loop") */
void sdr_task(void);
void dsp_link_poll(void);
void beep_task(void);
void cat_parse(void);
void ladder_key_task(void);
void scan_task(void);
void dispreq_e7_task(void);
void keyer_task(void);
void sd_menu_task(void);
void displink_task(void);
void key_task(void);
void tuner_task(void);

/* main_loop 0xFFF94B8B: one call of each task per pass, for ever [fact: 16 BSR.A and BRA.B back, 0xFFF94B8B..
 * 0xFFF94BCB] */
void main_loop(void)
{
    for (;;) {
        wdt_kick();
        io_task();
        sdr_task();
        dsp_link_poll();
        rf_ctrl_task();
        beep_task();
        cat_parse();
        ladder_key_task();
        scan_task();
        dispreq_e8_task();
        dispreq_e7_task();
        keyer_task();
        sd_menu_task();
        displink_task();
        key_task();
        tuner_task();
    }
}
