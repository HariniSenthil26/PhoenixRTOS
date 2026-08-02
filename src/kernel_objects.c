#include "kernel_objects.h"

#include "ready_queue.h"
#include "blocked_queue.h"

void KernelObjects_Init(void)
{

}

bool KernelObjects_MoveToReady(TCB *task)
{
    if(task==NULL)
        return false;

    BlockedQueue_Remove(task);

    Task_SetState(task,TASK_READY);

    return ReadyQueue_Insert(task);
}

bool KernelObjects_MoveToBlocked(TCB *task)
{
    if(task==NULL)
        return false;

    ReadyQueue_Remove(task);

    Task_SetState(task,TASK_BLOCKED);

    return BlockedQueue_Insert(task);
}

bool KernelObjects_Delete(TCB *task)
{
    if(task==NULL)
        return false;

    ReadyQueue_Remove(task);

    BlockedQueue_Remove(task);

    Task_SetState(task,TASK_TERMINATED);

    return true;
}