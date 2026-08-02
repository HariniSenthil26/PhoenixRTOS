#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>
#include <stdbool.h>

#include "task.h"

typedef enum
{
    KERNEL_STOPPED = 0,
    KERNEL_RUNNING

} KernelState;

void Kernel_Init(void);

bool Kernel_CreateTask(
    TCB *task,
    const char *name,
    TaskFunction function,
    void *parameter,
    uint8_t priority);

void Kernel_Start(void);

void Kernel_Stop(void);

void Kernel_Tick(void);

uint32_t Kernel_GetTickCount(void);

KernelState Kernel_GetState(void);

#endif