/*
 * ============================================================================
 * PhoenixRTOS - Mini RTOS
 * Task Management
 * ============================================================================
 */

#include "task.h"

#include <string.h>

#include "ready_queue.h"
#include "blocked_queue.h"

static uint32_t g_taskId = 1U;


/******************************************************************************
 * Initialize Task Module
 ******************************************************************************/

void Task_Init(void)
{
    g_taskId = 1U;
}


/******************************************************************************
 * Create Task
 ******************************************************************************/

bool Task_Create(
    TCB *task,
    const char *name,
    TaskFunction function,
    void *parameter,
    uint8_t priority)
{
    if ((task == NULL) ||
        (name == NULL) ||
        (function == NULL))
    {
        return false;
    }

    memset(task, 0, sizeof(TCB));

    task->id = g_taskId++;

    strncpy(task->name,
            name,
            TASK_NAME_LENGTH - 1U);

    task->priority = priority;

    task->taskFunction = function;

    task->parameter = parameter;

    task->state = TASK_READY;

    task->delayTicks = 0U;

    task->stackBottom = (uint32_t)&task->stack[0];

    task->stackTop =
        (uint32_t)&task->stack[DEFAULT_STACK_SIZE - 1];

    task->sp =
        (uint32_t *)task->stackTop;

    task->node.data = task;

    task->node.next = NULL;

    task->node.prev = NULL;

    return true;
}


/******************************************************************************
 * Delete Task
 ******************************************************************************/

bool Task_Delete(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    task->state = TASK_TERMINATED;

    return true;
}


/******************************************************************************
 * Execute Task
 ******************************************************************************/

void Task_Run(TCB *task)
{
    if (task == NULL)
    {
        return;
    }

    if (task->taskFunction == NULL)
    {
        return;
    }

    task->state = TASK_RUNNING;

    task->taskFunction(task->parameter);

    if (task->state == TASK_RUNNING)
    {
        Task_SetState(task, TASK_READY);
    }
}


/******************************************************************************
 * Delay Task
 ******************************************************************************/

void Task_Delay(
    TCB *task,
    uint32_t ticks)
{
    if (task == NULL)
    {
        return;
    }

    task->delayTicks = ticks;

    ReadyQueue_Remove(task);

    BlockedQueue_Insert(task);
}


/******************************************************************************
 * Set Task State
 ******************************************************************************/

void Task_SetState(
    TCB *task,
    TaskState state)
{
    if (task == NULL)
    {
        return;
    }

    task->state = state;
}


/******************************************************************************
 * Get Task State
 ******************************************************************************/

TaskState Task_GetState(
    const TCB *task)
{
    if (task == NULL)
    {
        return TASK_TERMINATED;
    }

    return task->state;
}