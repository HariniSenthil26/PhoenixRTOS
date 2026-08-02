#include "task_manager.h"

#include <string.h>

#include "config.h"
#include "scheduler.h"

#ifndef MAX_TASKS
#define MAX_TASKS 10U
#endif

static TCB *g_taskTable[MAX_TASKS];

static uint32_t g_taskCount = 0U;

/******************************************************************************
 * Initialize
 ******************************************************************************/

void TaskManager_Init(void)
{
    memset(g_taskTable, 0, sizeof(g_taskTable));

    g_taskCount = 0U;
}

/******************************************************************************
 * Create Task
 ******************************************************************************/

bool TaskManager_CreateTask(
    TCB *task,
    const char *name,
    TaskFunction function,
    void *parameter,
    uint8_t priority)
{
    if (task == NULL)
    {
        return false;
    }

    if (g_taskCount >= MAX_TASKS)
    {
        return false;
    }

    if (!Task_Create(task,
                     name,
                     function,
                     parameter,
                     priority))
    {
        return false;
    }

    g_taskTable[g_taskCount] = task;

    g_taskCount++;

    Scheduler_AddTask(task);

    return true;
}

/******************************************************************************
 * Delete Task
 ******************************************************************************/

bool TaskManager_DeleteTask(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    Scheduler_RemoveTask(task);

    Task_Delete(task);

    for (uint32_t i = 0U; i < g_taskCount; i++)
    {
        if (g_taskTable[i] == task)
        {
            for (uint32_t j = i; j < (g_taskCount - 1U); j++)
            {
                g_taskTable[j] = g_taskTable[j + 1U];
            }

            g_taskTable[g_taskCount - 1U] = NULL;

            g_taskCount--;

            break;
        }
    }

    return true;
}

/******************************************************************************
 * Get Task
 ******************************************************************************/

TCB *TaskManager_GetTask(uint32_t id)
{
    for (uint32_t i = 0U; i < g_taskCount; i++)
    {
        if (g_taskTable[i]->id == id)
        {
            return g_taskTable[i];
        }
    }

    return NULL;
}

/******************************************************************************
 * Task Count
 ******************************************************************************/

uint32_t TaskManager_TaskCount(void)
{
    return g_taskCount;
}