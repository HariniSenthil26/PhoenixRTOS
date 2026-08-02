/*
 * ============================================================================
 * MiniRTOS Demo Application
 * ============================================================================
 */

#include <stdio.h>

#include "kernel.h"
#include "task.h"
#include "queue.h"
#include "mutex.h"
#include "semaphore.h"
#include "timer.h"
#include "timer_manager.h"

static Queue messageQueue;
static Semaphore semaphore;
static Mutex printMutex;
static Timer heartbeatTimer;

static TCB producerTask;
static TCB consumerTask;
static TCB monitorTask;

static uint32_t message = 0;


/******************************************************************************
 * Timer Callback
 ******************************************************************************/

static void Heartbeat(void)
{
    printf("[Timer] Heartbeat\n");
}


/******************************************************************************
 * Producer Task
 ******************************************************************************/

static void Producer(void *parameter)
{
    (void)parameter;

    Queue_Send(&messageQueue, message);

    printf("[Producer] %u\n", message);

    message++;
}


/******************************************************************************
 * Consumer Task
 ******************************************************************************/

static void Consumer(void *parameter)
{
    uint32_t value;

    (void)parameter;

    if (Queue_Receive(&messageQueue, &value))
    {
        printf("[Consumer] %u\n", value);
    }
}


/******************************************************************************
 * Monitor Task
 ******************************************************************************/

static void Monitor(void *parameter)
{
    (void)parameter;

    printf("[Monitor] Queue Size = %u\n",
           Queue_Size(&messageQueue));
}


/******************************************************************************
 * Main
 ******************************************************************************/

int main(void)
{
    Kernel_Init();

    Queue_Init(&messageQueue);

    Semaphore_Init(&semaphore);

    Mutex_Init(&printMutex);

    Timer_Init(
        &heartbeatTimer,
        5U,
        true,
        Heartbeat);

    TimerManager_Add(&heartbeatTimer);

    Timer_Start(&heartbeatTimer);

    Task_Create(
        &producerTask,
        "Producer",
        Producer,
        NULL,
        2U);

    Task_Create(
        &consumerTask,
        "Consumer",
        Consumer,
        NULL,
        2U);

    Task_Create(
        &monitorTask,
        "Monitor",
        Monitor,
        NULL,
        1U);

    while (1)
    {
        Kernel_Tick();

        Task_Run(&producerTask);

        Task_Run(&consumerTask);

        Task_Run(&monitorTask);
    }

    return 0;
}