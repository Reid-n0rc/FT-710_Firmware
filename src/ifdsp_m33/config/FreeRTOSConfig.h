/*
 * FreeRTOSConfig.h for the FT-710 IFDSP Cortex-M33 (T24).
 *
 * Recreated, not the original file: the values are the ones that make the FreeRTOS V10.3.0 kernel of NXP's
 * FreeRTOS-Kernel MCUX_2.9.0 compile to the bytes in the image (tools/equiv_m33.py). The layout follows NXP's
 * SDK example config (mcux-sdk-examples evkmimxrt685/rtos_examples/freertos_hello/FreeRTOSConfig.h, MCUX_2.10.0).
 * Each value marked [fact] was settled by a byte difference in the named function; the others are the SDK
 * example's values and are not contradicted by any function in the image.
 */
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>
extern uint32_t SystemCoreClock;

#define configUSE_PREEMPTION 1
#define configUSE_TICKLESS_IDLE 0
#define configCPU_CLOCK_HZ (SystemCoreClock)
#define configTICK_RATE_HZ ((TickType_t)1000)            /* [fact] vPortSetupTimerInterrupt: SystemCoreClock / 1000 */
#define configMAX_PRIORITIES 5                           /* [fact] pxReadyTasksLists has 5 lists */
#define configMINIMAL_STACK_SIZE ((unsigned short)128)   /* [fact] vTaskStartScheduler: idle task 0x80 words */
#define configMAX_TASK_NAME_LEN 10                       /* [fact] xTaskCreate: name copy stops at 9, NUL at TCB+0x3D */
#define configUSE_16_BIT_TICKS 0
#define configIDLE_SHOULD_YIELD 1                        /* [fact] prvIdleTask yields when another prio-0 task is ready */
#define configUSE_TASK_NOTIFICATIONS 1
#define configUSE_MUTEXES 1
#define configUSE_RECURSIVE_MUTEXES 1
#define configUSE_COUNTING_SEMAPHORES 1
#define configUSE_ALTERNATIVE_API 0
#define configQUEUE_REGISTRY_SIZE 8
#define configUSE_QUEUE_SETS 0
#define configUSE_TIME_SLICING 0
#define configUSE_NEWLIB_REENTRANT 0
#define configENABLE_BACKWARD_COMPATIBILITY 0
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 5        /* [fact] ulNotifiedValue at TCB+0x68 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configSUPPORT_STATIC_ALLOCATION 0
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configTOTAL_HEAP_SIZE ((size_t)(100 * 1024))     /* [fact] pvPortMalloc: heap end literal = ucHeap + 0x19000 - 8 */
#define configAPPLICATION_ALLOCATED_HEAP 0
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0
#define configCHECK_FOR_STACK_OVERFLOW 0
#define configUSE_MALLOC_FAILED_HOOK 0
#define configUSE_DAEMON_TASK_STARTUP_HOOK 0
#define configGENERATE_RUN_TIME_STATS 0
#define configUSE_TRACE_FACILITY 1                       /* [fact] TCB has uxTCBNumber/uxTaskNumber (uxMutexesHeld at +0x50) */
#define configUSE_STATS_FORMATTING_FUNCTIONS 0
#define configRECORD_STACK_HIGH_ADDRESS 1                /* [fact] xTaskCreate stores pxEndOfStack at TCB+0x40 */
#define configUSE_CO_ROUTINES 0
#define configMAX_CO_ROUTINE_PRIORITIES 2
#define configUSE_TIMERS 1
#define configTIMER_TASK_PRIORITY (configMAX_PRIORITIES - 3) /* [fact] xTimerCreateTimerTask: priority 2 */
#define configTIMER_QUEUE_LENGTH 10                      /* [fact] prvCheckForValidListAndQueue */
#define configTIMER_TASK_STACK_DEPTH (configMINIMAL_STACK_SIZE * 2) /* [fact] 0x100 words */

#define configENABLE_FPU 0                               /* [fact] PendSV_Handler saves no FP context */
#define configENABLE_MPU 0
#define configENABLE_TRUSTZONE 0
#define configRUN_FREERTOS_SECURE_ONLY 1                 /* [fact] pxPortInitialiseStack: EXC_RETURN 0xFFFFFFFD */

#define configASSERT(x) if ((x) == 0) { taskDISABLE_INTERRUPTS(); for (;;); }

#define INCLUDE_vTaskPrioritySet 1
#define INCLUDE_uxTaskPriorityGet 1
#define INCLUDE_vTaskDelete 0                            /* [fact] prvIdleTask has no prvCheckTasksWaitingTermination */
#define INCLUDE_vTaskSuspend 1
#define INCLUDE_xResumeFromISR 1
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1
#define INCLUDE_xTaskGetSchedulerState 1
#define INCLUDE_xTaskGetCurrentTaskHandle 1
#define INCLUDE_uxTaskGetStackHighWaterMark 0
#define INCLUDE_xTaskGetIdleTaskHandle 0
#define INCLUDE_eTaskGetState 0
#define INCLUDE_xEventGroupSetBitFromISR 1
#define INCLUDE_xTimerPendFunctionCall 1
#define INCLUDE_xTaskAbortDelay 0
#define INCLUDE_xTaskGetHandle 0
#define INCLUDE_xTaskResumeFromISR 1

/* Interrupt priorities: 3 priority bits on the RT685 M33; BASEPRI 0x40 in ulSetInterruptMask [fact] */
#define configPRIO_BITS 3
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY ((1U << (configPRIO_BITS)) - 1)
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 2
#define configKERNEL_INTERRUPT_PRIORITY (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define configMAX_SYSCALL_INTERRUPT_PRIORITY (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

#define vPortSVCHandler SVC_Handler
#define vPortPendSVHandler PendSV_Handler
#define vPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */
