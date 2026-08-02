/*
 * ============================================================================
 * PhoenixRTOS
 * Task Control Block (TCB)
 * ============================================================================
 */

#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include <stdbool.h>

#include "list.h"

/*----------------------------------------------------------
 * Configuration
 *---------------------------------------------------------*/

#define MAX_TASK_NAME_LEN      32U
#define TASK_STACK_SIZE        1024U

/*----------------------------------------------------------
 * Task States
 *---------------------------------------------------------*/

typedef enum
{
    TASK_READY = 0,
    TASK_RUNNING,
    TASK_BLOCKED,
    TASK_SUSPENDED,
    TASK_TERMINATED

} TaskState;

/*----------------------------------------------------------
 * Task Function
 *---------------------------------------------------------*/

typedef void (*TaskFunction)(void *);

/*----------------------------------------------------------
 * Task Control Block
 *---------------------------------------------------------*/

typedef struct TCB
{
    uint32_t id;

    char name[MAX_TASK_NAME_LEN];

    uint8_t priority;

    TaskState state;

    TaskFunction taskFunction;

    void *parameters;

    uint32_t stackSize;

    void *stackPointer;

    uint32_t delayTicks;

    ListNode node;

} TCB;

/*----------------------------------------------------------
 * APIs
 *---------------------------------------------------------*/

void Task_Init(void);

bool Task_Create(TCB *task,
                 const char *name,
                 TaskFunction function,
                 void *parameters,
                 uint8_t priority);

bool Task_Delete(TCB *task);

void Task_Run(TCB *task);

void Task_Delay(TCB *task,
                uint32_t ticks);

void Task_SetState(TCB *task,
                   TaskState state);

TaskState Task_GetState(const TCB *task);

#endif