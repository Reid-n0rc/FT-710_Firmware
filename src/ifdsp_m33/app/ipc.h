/* FT-710 IFDSP M33: messages from and to the HiFi4 over rpmsg-lite (T24), see ipc.c and board/dsp_ipc.c. */
#ifndef IPC_H_
#define IPC_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

#define DSP_MESSAGE_SIZE 0x98U /* rpmsg_lite_send / rpmsg_queue_recv length [fact] */

/* One rpmsg message. Only the fields the M33 reads are named; their offsets are from ipc_print_dsp_reply
   (0x80FE8) [fact]. */
typedef struct
{
    uint8_t reserved0[8];
    uint8_t category;    /* +0x08: 0, 1 and 3 are handled (ipc_print_dsp_reply) */
    uint8_t reserved9[3];
    uint8_t command;     /* +0x0C: 0 is the only command handled per category */
    uint8_t reserved13[7];
    uint32_t param[33];  /* +0x14: param[0] error code, param[1] value */
} dsp_message_t;

/* The three task handles (0x886E4, cleared by main) */
typedef struct
{
    TaskHandle_t command;
    TaskHandle_t ipc_send;
    TaskHandle_t ipc_recv;
} task_handles_t;

extern task_handles_t g_taskHandles;
task_handles_t *get_task_handles(void);
void create_IpcTasks(void);
void IpcSendTask(void *param);
void IpcRecvTask(void *param);
void ipc_print_dsp_reply(const dsp_message_t *msg);

/* board/dsp_ipc.c */
void ipc_init(void);
void ipc_send(dsp_message_t *msg);
void ipc_recv(dsp_message_t *msg);

#endif /* IPC_H_ */
