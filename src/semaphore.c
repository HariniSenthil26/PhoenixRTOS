#include "semaphore.h"

#include "blocked_queue.h"
#include "ready_queue.h"

void Semaphore_Init(Semaphore *sem)
{
    if(sem == NULL)
        return;

    sem->available = true;

    sem->waitingTask = NULL;
}

bool Semaphore_Take(
    Semaphore *sem,
    TCB *task)
{
    if(sem == NULL || task == NULL)
        return false;

    if(sem->available)
    {
        sem->available = false;

        return true;
    }

    sem->waitingTask = task;

    KernelObjects_MoveToBlocked(task);

    return false;
}

bool Semaphore_Give(
    Semaphore *sem)
{
    if(sem == NULL)
        return false;

    sem->available = true;

    if(sem->waitingTask != NULL)
    {
        KernelObjects_MoveToReady(task);

        sem->waitingTask->state = TASK_READY;

        sem->waitingTask = NULL;
    }

    return true;
}