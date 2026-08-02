/*
 * ============================================================================
 * MiniRTOS
 * Mutex
 * ============================================================================
 */

#include "mutex.h"

#include "kernel_objects.h"

void Mutex_Init(Mutex *mutex)
{
    if (mutex == NULL)
    {
        return;
    }

    mutex->locked = false;
    mutex->owner = NULL;
    mutex->lockCount = 0U;
}

bool Mutex_Lock(
    Mutex *mutex,
    TCB *task)
{
    if ((mutex == NULL) || (task == NULL))
    {
        return false;
    }

    /* Free mutex */
    if (!mutex->locked)
    {
        mutex->locked = true;
        mutex->owner = task;
        mutex->lockCount = 1U;

        return true;
    }

    /* Recursive lock */
    if (mutex->owner == task)
    {
        mutex->lockCount++;

        return true;
    }

    /* Block task */
    KernelObjects_MoveToBlocked(task);

    return false;
}

bool Mutex_Unlock(
    Mutex *mutex,
    TCB *task)
{
    if ((mutex == NULL) || (task == NULL))
    {
        return false;
    }

    if (mutex->owner != task)
    {
        return false;
    }

    if (mutex->lockCount > 1U)
    {
        mutex->lockCount--;

        return true;
    }

    mutex->locked = false;
    mutex->owner = NULL;
    mutex->lockCount = 0U;

    return true;
}

bool Mutex_IsLocked(
    const Mutex *mutex)
{
    if (mutex == NULL)
    {
        return false;
    }

    return mutex->locked;
}

TCB *Mutex_GetOwner(
    const Mutex *mutex)
{
    if (mutex == NULL)
    {
        return NULL;
    }

    return mutex->owner;
}