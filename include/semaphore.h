#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <stdbool.h>

#include "task.h"

typedef struct
{
    bool available;

    TCB *waitingTask;

} Semaphore;

void Semaphore_Init(Semaphore *sem);

bool Semaphore_Take(
    Semaphore *sem,
    TCB *task);

bool Semaphore_Give(
    Semaphore *sem);

#endif