/*
 * FT-710 IFDSP M33: the IPC tasks (T24, recreated from the image 0x80F50..0x81066, 0x85FC6).
 * IpcRecvTask prints every message the HiFi4 sends; IpcSendTask would forward messages queued on s_ipcSendQueue, but
 * nothing ever writes that queue, so the link is idle (docs/code/ifdsp/ipc.md).
 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "uart.h"
#include "ipc.h"

static QueueHandle_t s_ipcSendQueue;
task_handles_t g_taskHandles;

void IpcSendTask(void *param)
{
    dsp_message_t msg;

    (void)param;
    for (;;)
    {
        if (xQueueReceive(s_ipcSendQueue, &msg, portMAX_DELAY) != pdTRUE)
        {
            continue;
        }
        ipc_send(&msg);
        /* wait until IpcRecvTask has the reply */
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }
}

void create_IpcTasks(void)
{
    task_handles_t *handles;

    s_ipcSendQueue = xQueueCreate(8, sizeof(dsp_message_t));
    handles        = get_task_handles();
    if (xTaskCreate(IpcRecvTask, "IpcRecvTask", 0x1800, handles, 2, &handles->ipc_recv) != pdPASS)
    {
        for (;;)
        {
        }
    }
    if (xTaskCreate(IpcSendTask, "IpcSendTask", 0x1800, handles, 2, &handles->ipc_send) != pdPASS)
    {
        for (;;)
        {
        }
    }
}

/* Print a message from the DSP on the console link. */
void ipc_print_dsp_reply(const dsp_message_t *msg)
{
    switch (msg->category)
    {
        case 0: /* general */
            if (msg->command == 0)
            {
                uart0_printf("Component versions from DSP:\r\n");
            }
            else
            {
                uart0_printf("Incoming unknown message command %d from category %d\r\n", msg->command,
                             msg->category);
            }
            break;
        case 1: /* mute */
            if (msg->command != 0)
            {
                uart0_printf("\r\nIncoming unknown message category %d\r\n>> ", msg->category);
            }
            else if (msg->param[0] != 0)
            {
                uart0_printf("\r\nMute error (%d)\r\n>> ", msg->param[0]);
            }
            else if (msg->param[1] != 0)
            {
                uart0_printf("\r\nMute on\r\n>> ");
            }
            else
            {
                uart0_printf("\r\nMute off\r\n>> ");
            }
            break;
        case 3: /* version */
            if (msg->command != 0)
            {
                uart0_printf("Incoming unknown message category %d\r\n>> ", msg->category);
            }
            else if (msg->param[0] != 0)
            {
                uart0_printf("DSP Version error (%d)\r\n>> ", msg->param[0]);
            }
            else
            {
                uart0_printf("DSP Version %04X\r\n>> ", msg->param[1]);
            }
            break;
        default:
            break;
    }
}

task_handles_t *get_task_handles(void)
{
    return &g_taskHandles;
}

void IpcRecvTask(void *param)
{
    task_handles_t *handles = param;
    dsp_message_t msg;

    for (;;)
    {
        ipc_recv(&msg);
        ipc_print_dsp_reply(&msg);
        if (handles->ipc_send != NULL)
        {
            xTaskNotifyGive(handles->ipc_send);
        }
    }
}
