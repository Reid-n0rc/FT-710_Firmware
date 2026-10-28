// Applies function names (and plate comments) to the IFDSP HiFi4 program (T12e; T12b/T12c HiFi4 proposals merged in T17).
// Names come from the FLIX-aware disassembly
// (tools/ifdsp_hifi4_dis.py with the Zephyr SDK xtensa-nxp_rt600_adsp objdump): call arguments, literal
// pools, peripheral bases, XOS / NXP MCUXpresso SDK / rpmsg-lite call patterns. See docs/code/ifdsp/hifi4.md.
// Ghidra decodes only the base ISA here, so the bodies stay truncated; the names still help the listing.
// Functions Ghidra did not create (entry not found) are created at the given address.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101_hifi4.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript IfdspHifi4Names.java
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class IfdspHifi4Names extends GhidraScript {
    static final Object[][] NAMES = {
        // startup and threads (T12a seeds, checked against the xos_thread_create arguments)
        {0x0021C498L, "xos_create_main_ipc_threads", "XOS main: zero DMA area 0x20060000..0x200631E0, regfile_init_defaults, clock globals (24 MHz, 18.432 MHz), creates Thread_Main, Thread_Ipc, others, xos_start"},
        {0x0021C360L, "Thread_Main_entry", "XOS thread \"Thread_Main\" (entry from literal 0x206CD0)"},
        {0x0021C3B4L, "Thread_Ipc_entry", "XOS thread \"Thread_Ipc\": MU_Init(MUB), msgq, rpmsg_lite_remote_init(0x20020000), wait link up, ept 0x1E, MU flag/SEMA42 boot handshake, then loop xos_msgq_get -> handle_srtm_msg"},
        {0x00220BD0L, "create_Thread_Rx_Audio"},
        {0x00220F90L, "Thread_Rx_Audio_entry"},
        {0x00224A10L, "create_Thread_Spi"},
        {0x00224AA4L, "Thread_Spi_entry"},
        {0x00225E40L, "create_rx_tx_path_threads"},
        {0x002262FCL, "Thread_Rx_Path_entry"},
        {0x0022647CL, "Thread_Tx_Path_entry"},
        // shared parameter register file (0x20070000)
        {0x0021BE80L, "regfile_set_defaults", "writes the default of every DSP register (all but 0, 1, 0x4000)"},
        {0x0021C060L, "tx_gpio_to_reg4004", "reg 0x4004 = (f()<<2) | (GPIO P0_21<<1) | GPIO P0_22; called from Thread_Main loop 0x0021C360"},
        {0x0021C230L, "cpu_load_to_regs_2000"},
        {0x0021F348L, "meter_to_reg4005", "reg 0x4005 = 0..99 level for the M33 PWM; also level byte for reg 3"},
        // audio I/O: I2S FLEXCOMM2-5 + DMA1, SPI FLEXCOMM1 + DMA0
        {0x002260D8L, "audio_i2s_fc3_fc4_fc5_init"},
        {0x00226224L, "fc2_txaf_dma_done"},
        {0x00226254L, "fc3_rxif_dma_done"},
        {0x00226284L, "fc5_codec_out_dma_done"},
        {0x002262C0L, "fc4_codec_in_dma_done"},
        {0x00225C9CL, "txaf_fifo_pop_to_dma"},
        {0x00225CF8L, "rxif_dma_to_fifo"},
        {0x002246C0L, "codec_out_fill_dma"},
        {0x00224734L, "codec_in_from_dma"},
        {0x00220F74L, "rx_audio_push_block"},
        {0x00220C7CL, "rx_audio_fifo_push"},
        {0x00224D58L, "spi_fifo_push"},
        {0x00224D40L, "spi_post_tx_done"},
        {0x00220FD0L, "fc1_spi_dma_init"},
        // Cadence XOS kernel / HAL
        {0x002274E0L, "xos_thread_create", "called with thread entry, name, stack [inference]"},
        {0x002277F0L, "xos_start", "last call of main, arg 0 [inference]"},
        {0x0022835CL, "xos_start_system_timer"},
        {0x0022866CL, "xos_thread_sleep"},
        {0x0022735CL, "xos_get_cpu_load"},
        {0x00226A50L, "xos_msgq_create", "called by Thread_Ipc and the other thread creators [inference]"},
        {0x00226B38L, "xos_msgq_put", "called from ipc_ept_rx_cb [inference]"},
        {0x00226CECL, "xos_msgq_get", "Thread_Ipc main loop [inference]"},
        {0x002266FCL, "xos_register_interrupt_handler", "called with MU_B_IRQHandler [inference]"},
        {0x0022678CL, "xos_interrupt_enable"},
        // libc / compiler runtime
        {0x00235D30L, "memcpy"},
        {0x00235EB0L, "memset"},
        {0x00235900L, "__udivdi3"},
        // NXP SDK drivers
        {0x00212684L, "INPUTMUX_AttachSignal"},
        {0x00208600L, "CLOCK_AttachClk"},
        {0x00208E90L, "CLOCK_GetFlexCommClkFreq"},
        {0x0020A528L, "DMA_Init"},
        {0x0020AAB4L, "DMA_CreateHandle"},
        {0x0020AF38L, "DMA_IRQHandle"},
        {0x0020EDACL, "I2S_TxInit"},
        {0x0020EECCL, "I2S_RxInit"},
        {0x0020EFDCL, "I2S_TxGetDefaultConfig"},
        {0x0020F020L, "I2S_RxGetDefaultConfig"},
        {0x0020FBE4L, "I2S_TxTransferCreateHandleDMA"},
        {0x0020FC7CL, "I2S_TxTransferSendDMA"},
        {0x0020FE90L, "I2S_RxTransferCreateHandleDMA"},
        {0x0020FEA8L, "I2S_RxTransferReceiveDMA"},
        {0x00213F58L, "SPI_MasterGetDefaultConfig"},
        {0x00213F9CL, "SPI_MasterInit"},
        {0x00212EB8L, "MU_SetFlags", "wait SR FUP (bit 8) clear, CR Fn = flags"},
        {0x00213E84L, "SEMA42_Lock", "spin until gate free, then lock"},
        // rpmsg-lite (remote side)
        {0x0021B544L, "rpmsg_lite_remote_init", "called by Thread_Ipc; init_interrupt x2, disable/enable x2 [inference]"},
        {0x0021B078L, "rpmsg_lite_is_link_up", "returns rl->link_state (+0x10)"},
        {0x0021AF9CL, "rpmsg_lite_create_ept", "called by Thread_Ipc (callback ipc_ept_rx_cb) and rpmsg_ns_bind"},
        {0x0021C398L, "ipc_ept_rx_cb", "rpmsg ept callback: if len == 0x98 xos_msgq_put(msg); return RL_RELEASE (NXP my_ept_read_cb)"},
        {0x0021BD40L, "ipc_handle_msg", "checks version byte, dispatch on category (+8): 0 general, 1 audio, else error at +0x14; if type (+0xB) == request, reply with rpmsg_lite_send under mutex"},
        // DSP blocks
        {0x002340FCL, "iir_cascade_init"},
        {0x002341C0L, "iir_cascade_process"},
        {0x00223250L, "nlms_51tap_update"},
        // merged from T12b.hifi4.tsv (T17)
        {0x0021C090L, "regfile_capture_init", "capture block table 0x2390E0 = {0x2007E000, 0x2007F000} (regs 0x7000/0x7800), memset 4 KB each"},
        {0x0021C0B8L, "regfile_capture_clear", "memset(block[idx], 0, 0x1000)"},
        {0x0021C0D4L, "regfile_capture_set_ctrl", "*(u16 *)block[idx] = v (control word); no caller"},
        {0x0021C0E8L, "regfile_capture_append", "append u32 if ctrl bit 0, count at +2 (max 0x3FE), wrap if ctrl bit 1; no caller"},
        {0x0021C5CCL, "regfile_gpio_sel", "(reg 0xC & 0xF000) == 0x1000 -> GPIO P0_4 byte"},
        {0x0021D270L, "status_reg4_update", "reg 4 = rounded value or 0x7FFF (CW zero-in offset [inference])"},
        {0x0021F388L, "status_reg3_update", "reg 3 = level<<8 | (255 - x)"},
        // merged from T12c.hifi4.tsv (T17)
        {0x0021BDCCL, "handle_msg_general", "category 0: command (+0xC); system info fills param[] with 9 component versions (0x00020000, 0x00010003, ...)"},
        {0x0021BE54L, "handle_msg_audio", "category 1 (M33 prints it as Mute on/off): command (+0xC), result in +0x14/+0x18"},
        {0x00212D00L, "MU_Init", "clock enable for MU (base 0x40111000 MU-B passed by Thread_Ipc)"},
        {0x00212E58L, "MU_SendMsg", "wait SR TEn, TR[reg] (+0x20)"},
        {0x00212E88L, "MU_ReceiveMsg", "wait SR RFn, RR[reg] (+0x40)"},
        {0x00213D10L, "SEMA42_GetInstance", "base -> index via table 0x2004E0"},
        {0x00213D24L, "SEMA42_Init", "CLOCK_EnableClock(SEMA42) inlined (CLKCTL PSCCTL SET)"},
        {0x00213DBCL, "SEMA42_Deinit", "CLOCK_DisableClock(SEMA42) inlined (CLKCTL PSCCTL CLR)"},
        {0x00213E54L, "SEMA42_TryLock", "gate byte at base + (gate ^ 3) = proc+1, read back"},
        {0x00213ED0L, "SEMA42_ResetGate", "RSTGT = 0xE200 then 0x1D00 | gate"},
        {0x0021B088L, "rpmsg_lite_send", "called by handle_srtm_msg and rpmsg_ns_announce"},
        {0x0021B734L, "rpmsg_ns_bind", "creates an endpoint (no callers found) [inference]"},
        {0x0021B778L, "rpmsg_ns_announce", "sends via rpmsg_lite_send, error 0xFFFFEC75 (no callers found) [inference]"},
        {0x0021AC14L, "env_isr", "isr_table[vector] -> virtqueue_notification"},
        {0x0021AC30L, "MU_B_IRQHandler", "rpmsg platform ISR: if MU-B SR RF1 (bit 26): env_isr(RR1 >> 16)"},
        {0x0021AC58L, "platform_init_interrupt", "env_register_isr, first use: MU-B CR |= RIE1, xos_register_interrupt_handler(MU_B_IRQHandler)"},
        {0x0021ACB4L, "platform_deinit_interrupt", "last use: MU-B CR &= ~RIE1, unregister handler"},
        {0x0021AD04L, "platform_notify", "wait MU-B SR TE1 (bit 22), TR1 = vector << 16"},
        {0x0021AD44L, "platform_time_delay", "busy-wait on CCOUNT (0x1F40 cycles per unit)"},
        {0x0021ABB0L, "env_register_isr", "isr_table entry store [inference]"},
        {0x0021AB94L, "env_lock_mutex", "[inference: paired with env_unlock_mutex around MU-B CR access]"},
        {0x0021AB9CL, "env_unlock_mutex", "[inference]"},
        {0x002270D4L, "xos_mutex_lock", "around the reply rpmsg_lite_send [inference]"},
        {0x00227230L, "xos_mutex_unlock", "[inference]"},
        {0x00233410L, "xthal_set_region_attribute", "(vaddr, size, cattr, flags): called by the DSP main with (0x20060000, 0x31E0, 2, 0) and (0x20070000, 0x10000, 2, 0); T12c proposed memset, but memset is 0x235EB0 [inference]"},
    };

    @Override
    protected void run() throws Exception {
        int n = 0;
        for (Object[] e : NAMES) {
            Address ad = toAddr((Long) e[0]);
            Function f = getFunctionAt(ad);
            if (f == null) {
                disassemble(ad);
                f = createFunction(ad, (String) e[1]);
                if (f == null) { printerr("no function at " + ad); continue; }
            }
            f.setName((String) e[1], SourceType.USER_DEFINED);
            if (e.length > 2) currentProgram.getListing().setComment(ad, CodeUnit.PLATE_COMMENT, (String) e[2]);
            n++;
        }
        analyzeChanges(currentProgram);
        println("IfdspHifi4Names: " + n + " functions named");
    }
}
