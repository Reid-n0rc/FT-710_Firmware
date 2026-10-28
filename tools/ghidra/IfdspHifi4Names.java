// Applies function names to the IFDSP HiFi4 program (T12e). Names come from the FLIX-aware disassembly
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
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class IfdspHifi4Names extends GhidraScript {
    static final Object[][] NAMES = {
        // startup and threads (T12a seeds, checked against the xos_thread_create arguments)
        {0x0021C498L, "xos_create_main_ipc_threads"},
        {0x0021C360L, "Thread_Main_entry"},
        {0x0021C3B4L, "Thread_Ipc_entry"},
        {0x00220BD0L, "create_Thread_Rx_Audio"},
        {0x00220F90L, "Thread_Rx_Audio_entry"},
        {0x00224A10L, "create_Thread_Spi"},
        {0x00224AA4L, "Thread_Spi_entry"},
        {0x00225E40L, "create_rx_tx_path_threads"},
        {0x002262FCL, "Thread_Rx_Path_entry"},
        {0x0022647CL, "Thread_Tx_Path_entry"},
        // shared parameter register file (0x20070000)
        {0x0021BE80L, "regfile_set_defaults"},
        {0x0021C060L, "tx_gpio_to_reg4004"},
        {0x0021C230L, "cpu_load_to_regs_2000"},
        {0x0021F348L, "meter_to_reg4005"},
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
        {0x002274E0L, "xos_thread_create"},
        {0x002277F0L, "xos_start"},
        {0x0022835CL, "xos_start_system_timer"},
        {0x0022866CL, "xos_thread_sleep"},
        {0x0022735CL, "xos_get_cpu_load"},
        {0x00226A50L, "xos_msgq_create"},
        {0x00226B38L, "xos_msgq_put"},
        {0x00226CECL, "xos_msgq_get"},
        {0x002266FCL, "xos_register_interrupt_handler"},
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
        {0x00212EB8L, "MU_SetFlags"},
        {0x00213E84L, "SEMA42_Lock"},
        // rpmsg-lite (remote side)
        {0x0021B544L, "rpmsg_lite_remote_init"},
        {0x0021B078L, "rpmsg_lite_is_link_up"},
        {0x0021AF9CL, "rpmsg_lite_create_ept"},
        {0x0021C398L, "ipc_ept_rx_cb"},
        {0x0021BD40L, "ipc_handle_msg"},
        // DSP blocks
        {0x002340FCL, "iir_cascade_init"},
        {0x002341C0L, "iir_cascade_process"},
        {0x00223250L, "nlms_51tap_update"},
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
            n++;
        }
        analyzeChanges(currentProgram);
        println("IfdspHifi4Names: " + n + " functions named");
    }
}
