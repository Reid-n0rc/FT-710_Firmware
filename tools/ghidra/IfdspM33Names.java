// Applies the T07 starting set of function names to the IFDSP Cortex-M33 program (and creates the
// FreeRTOS task entry that is only referenced as a task pointer). Names are inferences from strings,
// call structure and the NXP MCUXpresso SDK / FreeRTOS patterns; see decomp/ifdsp/INDEX.md.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript IfdspM33Names.java
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class IfdspM33Names extends GhidraScript {
    static final Object[][] NAMES = {
        {0x080011A8L, "ResetISR"},
        {0x08001222L, "data_init"},
        {0x08001234L, "bss_init"},
        {0x08001540L, "SystemInit"},
        {0x080017A8L, "call_main"},
        {0x000872AEL, "main"},
        {0x00084AD8L, "BOARD_DSP_Init"},
        {0x00086EAAL, "DSP_CopyImage"},
        {0x00080E20L, "create_CommandTask"},
        {0x00080D78L, "CommandTask"},
        {0x00080F80L, "create_IpcTasks"},
        {0x00085FC6L, "IpcRecvTask"},
        {0x00080F50L, "IpcSendTask"},
        {0x00080FE8L, "ipc_print_dsp_reply"},
        {0x00081430L, "console_rx_char"},
        {0x000813B4L, "console_print_reg"},
        {0x000812FEL, "console_dump"},
        {0x00080CA4L, "uart0_write"},
        {0x00080D0CL, "uart0_init"},
        {0x00085B08L, "snprintf"},
        {0x00085B80L, "sprintf"},
        {0x00085FAEL, "console_puts"},
        {0x00084EB0L, "vsnprintf_core"},
        {0x00081C28L, "rpmsg_virtqueues_init"},
        {0x00082278L, "xTaskCreate"},
        {0x00082184L, "vQueueAddToRegistry"},
        {0x00082418L, "vTaskStartScheduler"},
        {0x00082C80L, "xTimerCreateTimerTask"},
        {0x00082DB0L, "prvTimerTask"},
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
        println("IfdspM33Names: " + n + " functions named");
    }
}
