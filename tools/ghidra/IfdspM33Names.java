// Applies function names to the IFDSP Cortex-M33 program (T07 starting set, extended in T12) and creates the
// functions Ghidra misses: FreeRTOS task entries only referenced as pointers, the real application main, the
// SCTimer callback, and the console command handlers whose first instruction (`cmp r1,#argc`) sits before the
// `push` that Ghidra's prologue search starts at. Names are inferences from strings, call structure, register
// addresses and the NXP MCUXpresso SDK / FreeRTOS / rpmsg-lite patterns; see docs/code/ifdsp/.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript IfdspM33Names.java
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class IfdspM33Names extends GhidraScript {
    // {true entry, function Ghidra created 2 bytes later (removed first)}
    static final long[][] FIX_START = {
        {0x000812C4L, 0x000812C6L},
        {0x000812FCL, 0x000812FEL},
    };

    static final Object[][] NAMES = {
        // reset / startup (flash)
        {0x080011A8L, "ResetISR"},
        {0x08001222L, "data_init"},
        {0x08001234L, "bss_init"},
        {0x08001540L, "SystemInit"},
        {0x080017A8L, "call_main"},
        // application
        {0x000872AEL, "main"},
        {0x0008106CL, "app_main"},
        {0x00084E38L, "stdio_init"},
        {0x0008494CL, "BOARD_BootClockRUN"},
        {0x00087294L, "BOARD_InitPins"},
        {0x00084B78L, "BOARD_InitPins_P0"},
        {0x00084BECL, "BOARD_InitPins_codec_spi"},
        {0x00084AD8L, "BOARD_DSP_Init"},
        {0x00086EAAL, "DSP_CopyImage"},
        // shared parameter register file (0x20070000, 32K x 16 bit)
        {0x00080C20L, "regfile_clear"},
        {0x00080C30L, "regfile_read"},
        {0x00080C4CL, "regfile_write"},
        {0x00080C78L, "regfile_set_bits"},
        // TLV320AIC3204 codec control (GPIO bit-banged SPI)
        {0x00080B44L, "delay_us"},
        {0x00080B68L, "aic3204_spi_write"},
        {0x00080BD0L, "aic3204_init"},
        // SCT0 PWM (duty from register 0x4005)
        {0x000811E0L, "sct0_pwm_init"},
        {0x00081164L, "sct0_pwm_callback"},
        {0x00081264L, "SCTIMER_StartTimer"},
        {0x000845B4L, "SCTIMER_Init"},
        {0x0008477CL, "SCTIMER_SetupPwm"},
        {0x000848D8L, "SCTIMER_SetCallback"},
        {0x00086F64L, "SCTIMER_GetDefaultConfig"},
        {0x00086F8AL, "SCTIMER_UpdatePwmDutycycle"},
        // console / control link on FLEXCOMM0 USART
        {0x00080E20L, "create_CommandTask"},
        {0x00080D78L, "CommandTask"},
        {0x00080CA4L, "uart0_write"},
        {0x00080D0CL, "uart0_init"},
        {0x00080E50L, "FLEXCOMM0_IRQHandler"},
        {0x00080F3CL, "uart0_tx_pending"},
        {0x000813ECL, "console_init"},
        {0x00081430L, "console_rx_char"},
        {0x00081274L, "console_cmd_i"},
        {0x000812C4L, "console_cmd_w"},
        {0x000812FCL, "console_cmd_d"},
        {0x000813B4L, "console_cmd_r"},
        {0x00085FAEL, "console_puts"},
        {0x00086014L, "is_hex_string"},
        {0x00086044L, "frame_checksum_ok"},
        // IPC (rpmsg-lite over MU-A)
        {0x00080F80L, "create_IpcTasks"},
        {0x00085FC6L, "IpcRecvTask"},
        {0x00080F50L, "IpcSendTask"},
        {0x00080FE8L, "ipc_print_dsp_reply"},
        {0x00081064L, "get_task_handles"},
        {0x00084A50L, "ipc_init"},
        {0x00084A8CL, "ipc_send"},
        {0x00084AB0L, "ipc_recv"},
        {0x00081C28L, "rpmsg_lite_master_init"},
        {0x00081DECL, "virtqueue_create"},
        {0x00081A88L, "rpmsg_queue_recv"},
        {0x00081AFCL, "rpmsg_lite_send"},
        {0x00081BE8L, "rpmsg_queue_nocopy_free"},
        {0x000861DAL, "rpmsg_queue_create"},
        {0x000862B2L, "rpmsg_lite_create_ept"},
        {0x000819E8L, "platform_init"},
        {0x000819B4L, "platform_init_interrupt"},
        {0x00081A60L, "platform_register_isr"},
        {0x000818D0L, "platform_interrupt_enable"},
        {0x00081958L, "env_enable_interrupt"},
        {0x00081980L, "env_disable_interrupt"},
        {0x000818B8L, "MU_A_IRQHandler"},
        {0x000860A0L, "env_create_mutex"},
        {0x000860C4L, "env_lock_mutex"},
        {0x000860DEL, "env_unlock_mutex"},
        {0x00086072L, "env_free_memory"},
        {0x00081944L, "xPortIsInsideInterrupt"},
        // NXP SDK drivers
        {0x00086F14L, "MU_SetFlags"},
        {0x000842C8L, "MU_Init"},
        {0x000848F4L, "SEMA42_Init"},
        {0x00087008L, "SEMA42_ResetAllGates"},
        {0x00086FECL, "SEMA42_Lock"},
        {0x00086EF0L, "INPUTMUX_AttachSignal"},
        {0x00086F52L, "RESET_ClearPeripheralReset"},
        {0x000841B4L, "GPIO_PortInit"},
        {0x000841D8L, "GPIO_PinInit"},
        {0x00086E1CL, "CLOCK_AttachClk"},
        {0x00086E58L, "CLOCK_SetClkDiv"},
        {0x000837A8L, "CLOCK_GetFreq"},
        {0x00083470L, "CLOCK_GetFlexCommClkFreq"},
        {0x000809A0L, "CLOCK_SetDiv_0x620"},
        {0x0008702CL, "USART_GetDefaultConfig"},
        {0x00087100L, "USART_Init"},
        {0x0008034CL, "POWER_EnterSleep_mode1"},
        {0x00080414L, "POWER_EnterSleep_mode2"},
        {0x000804DCL, "POWER_EnterSleep_mode3"},
        {0x0008059CL, "POWER_EnterDeepSleep"},
        {0x000800EEL, "POWER_CalcSafetyCount"},
        // FreeRTOS kernel + ARM_CM33 port + heap_4
        {0x00082278L, "xTaskCreate"},
        {0x00082418L, "vTaskStartScheduler"},
        {0x00082484L, "vTaskSuspendAll"},
        {0x00082598L, "xTaskResumeAll"},
        {0x00082664L, "vTaskDelay"},
        {0x00082694L, "vTaskSwitchContext"},
        {0x000821E4L, "prvAddCurrentTaskToDelayedList"},
        {0x00082AE0L, "ulTaskNotifyTake"},
        {0x00082B34L, "xTaskGenericNotify"},
        {0x00082184L, "vQueueAddToRegistry"},
        {0x000821A8L, "vQueueUnregisterQueue"},
        {0x00086916L, "xQueueGenericCreate"},
        {0x00086976L, "xQueueGenericSend"},
        {0x00086A8AL, "xQueueGenericSendFromISR"},
        {0x00086B1CL, "xQueueReceive"},
        {0x00086C14L, "xQueueSemaphoreTake"},
        {0x00086D48L, "xQueueReceiveFromISR"},
        {0x000865BAL, "xEventGroupCreate"},
        {0x000865D4L, "xEventGroupWaitBits"},
        {0x00082174L, "xEventGroupSetBitsFromISR"},
        {0x00082BECL, "prvCheckForValidListAndQueue"},
        {0x00082C80L, "xTimerCreateTimerTask"},
        {0x00082DB0L, "prvTimerTask"},
        {0x00081EC8L, "pvPortMalloc"},
        {0x00081FD4L, "vPortFree"},
        {0x00081E80L, "prvInsertBlockIntoFreeList"},
        {0x00082038L, "prvTaskExitError"},
        {0x00082060L, "vPortSetupTimerInterrupt"},
        {0x00082084L, "vPortEnterCritical"},
        {0x000820A0L, "vPortExitCritical"},
        {0x000820C8L, "pxPortInitialiseStack"},
        {0x00080A90L, "vStartFirstTask"},
        {0x00086596L, "vPortRaiseBASEPRI"},
        {0x000865ACL, "vPortClearBASEPRI"},
        {0x0008657CL, "vPortSVCHandler_C"},
        // C library (NXP Redlib: `_Csys_alloc`)
        {0x00084EB0L, "vsnprintf_core"},
        {0x00085B08L, "snprintf"},
        {0x00085B80L, "sprintf"},
        {0x00085A9CL, "siprintf"},
        {0x00085CC0L, "strtoul"},
        {0x00084E24L, "tolower"},
        {0x0008737AL, "strlen"},
        {0x00087336L, "strcmp"},
        {0x000873C2L, "strncmp"},
        {0x000878CCL, "memcpy"},
        {0x00087900L, "memset"},
        {0x00084D3CL, "redlib_malloc"},
        {0x00084E04L, "_Csys_alloc_failed"},
    };

    @Override
    protected void run() throws Exception {
        for (long[] fx : FIX_START) {
            Function late = getFunctionAt(toAddr(fx[1]));
            if (late != null) removeFunction(late);
            clearListing(toAddr(fx[0]), toAddr(fx[0] + 1));
            disassemble(toAddr(fx[0]));
        }
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
        println("IfdspM33Names: " + n + " functions named");
    }
}
