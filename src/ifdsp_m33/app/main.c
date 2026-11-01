/*
 * FT-710 IFDSP M33: main (T24, recreated from the image 0x8106C; Ghidra calls it app_main).
 * Boot flow and the M33/DSP handshake: docs/code/ifdsp/m33-platform.md sections 2 and 5, docs/code/ifdsp/ipc.md.
 * Redlib's __main (0x872AE) sets up stdio and calls this.
 */
#include <string.h>
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_inputmux.h"
#include "fsl_reset.h"
#include "fsl_sema42.h"
#include "fsl_mu.h"
#include "FreeRTOS.h"
#include "task.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "peripherals.h"
#include "dsp_support.h"
#include "codec.h"
#include "regfile.h"
#include "pwm.h"
#include "uart.h"
#include "ipc.h"

/* MU flag values of the boot handshake with the HiFi4 */
#define BOOT_FLAG_M33_READY  1U /* M33 -> DSP; the DSP echoes 1 when it runs */
#define BOOT_FLAG_SEMA_TAKEN 2U /* M33 -> DSP; the DSP answers 3 */
#define SEMA42_GATE_SHARED   0U
#define SEMA42_PROC_M33      1U

int main(void)
{
    memset(&g_taskHandles, 0, sizeof(g_taskHandles));

    GPIO_PortInit(GPIO, 0);
    GPIO_PortInit(GPIO, 1);
    GPIO_PortInit(GPIO, 2);
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    regfile_clear();

    /* MU-B interrupt -> HiFi4 interrupt input 1 (the DSP's IRQ 6): the rpmsg doorbell */
    CLOCK_EnableClock(kCLOCK_InputMux);
    INPUTMUX_AttachSignal(INPUTMUX, 1U, kINPUTMUX_MuBToDspInterrupt);
    RESET_PeripheralReset(kSEMA_RST_SHIFT_RSTn);
    RESET_PeripheralReset(kMU_RST_SHIFT_RSTn);

    aic3204_init();
    sct0_pwm_init();
    ipc_init();
    BOARD_DSP_Init();

    /* Handshake: flag 1, wait for the DSP's 1; take gate 0, flag 2, release it, wait for 3 */
    SEMA42_Init(SEMA42);
    SEMA42_ResetAllGates(SEMA42);
    MU_SetFlags(MUA, BOOT_FLAG_M33_READY);
    while (MU_GetFlags(MUA) != 1U)
    {
    }
    SEMA42_Lock(SEMA42, SEMA42_GATE_SHARED, SEMA42_PROC_M33);
    MU_SetFlags(MUA, BOOT_FLAG_SEMA_TAKEN);
    SEMA42_Unlock(SEMA42, SEMA42_GATE_SHARED);
    while (MU_GetFlags(MUA) != 3U)
    {
    }

    regfile_write(REG_VERSION, 0x0101);  /* V01-01 */
    regfile_write(REG_M33_STARTED, 1);
    regfile_set_bits(REG_STATUS_FLAGS, 1);

    create_IpcTasks();
    sct0_pwm_start();
    create_CommandTask();
    vTaskStartScheduler();
    return 0;
}
