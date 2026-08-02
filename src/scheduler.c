#include "scheduler.h"

#include "ready_queue.h"

#include "blocked_queue.h"

static TCB *g_currentTask = NULL;

void Scheduler_Init(void)
{
    ReadyQueue_Init();

    g_currentTask = NULL;
}

bool Scheduler_AddTask(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    Task_SetState(task, TASK_READY);

    return ReadyQueue_Insert(task);
}

bool Scheduler_RemoveTask(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    return ReadyQueue_Remove(task);
}

TCB *Scheduler_GetCurrentTask(void)
{
    return g_currentTask;
}

TCB *Scheduler_SelectTask(void)
{
    return ReadyQueue_GetHighestPriority();
}

void Scheduler_Dispatch(TCB *task)
{
    if (task == NULL)
    {
        return;
    }

    g_currentTask = task;

    Task_Run(task);
}

void Scheduler_Yield(void)
{
    if (g_currentTask == NULL)
    {
        return;
    }

    ReadyQueue_Rotate();
}

void Scheduler_Tick(void)
{
    BlockedQueue_Update();

    ReadyQueue_Rotate();
}
void Scheduler_Start(void)
{
    while (1)
    {
        TCB *nextTask = Scheduler_SelectTask();

        if (nextTask != NULL)
        {
            Scheduler_Dispatch(nextTask);
        }
    }
}