/*
 * ============================================================================
 * MiniRTOS
 * Mutex
 * ============================================================================
 */

#ifndef MUTEX_H
#define MUTEX_H

#include <stdbool.h>
#include <stdint.h>

#include "task.h"

typedef struct
{
    bool locked;

    TCB *owner;

    uint32_t lockCount;

} Mutex;

/******************************************************************************
 * APIs
 ******************************************************************************/

void Mutex_Init(Mutex *mutex);

bool Mutex_Lock(
    Mutex *mutex,
    TCB *task);

bool Mutex_Unlock(
    Mutex *mutex,
    TCB *task);

bool Mutex_IsLocked(
    const Mutex *mutex);

TCB *Mutex_GetOwner(
    const Mutex *mutex);

#endif