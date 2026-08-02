#include "kernel.h"

#include "scheduler.h"
#include "task_manager.h"

static KernelState g_kernelState = KERNEL_STOPPED;

static uint32_t g_tickCount = 0U;

void Kernel_Init(void)
{
    Task_Init();

    TaskManager_Init();

    Scheduler_Init();

    g_tickCount = 0U;

    g_kernelState = KERNEL_STOPPED;
}

bool Kernel_CreateTask(
    TCB *task,
    const char *name,
    TaskFunction function,
    void *parameter,
    uint8_t priority)
{
    return TaskManager_CreateTask(
        task,
        name,
        function,
        parameter,
        priority);
}

void Kernel_Start(void)
{
    if (g_kernelState == KERNEL_RUNNING)
    {
        return;
    }

    g_kernelState = KERNEL_RUNNING;

    Scheduler_Start();
}

void Kernel_Stop(void)
{
    g_kernelState = KERNEL_STOPPED;
}

void Kernel_Tick(void)
{
    g_tickCount++;

    Scheduler_Tick();
}

uint32_t Kernel_GetTickCount(void)
{
    return g_tickCount;
}

KernelState Kernel_GetState(void)
{
    return g_kernelState;
}