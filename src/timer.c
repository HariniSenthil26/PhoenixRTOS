/*
 * ============================================================================
 * MiniRTOS
 * Software Timer
 * ============================================================================
 */

#include "timer.h"

void Timer_Init(
    Timer *timer,
    uint32_t period,
    bool periodic,
    TimerCallback callback)
{
    if (timer == NULL)
    {
        return;
    }

    timer->period = period;
    timer->remaining = period;
    timer->periodic = periodic;
    timer->active = false;
    timer->callback = callback;
}

void Timer_Start(Timer *timer)
{
    if (timer == NULL)
    {
        return;
    }

    timer->remaining = timer->period;
    timer->active = true;
}

void Timer_Stop(Timer *timer)
{
    if (timer == NULL)
    {
        return;
    }

    timer->active = false;
}

void Timer_Reset(Timer *timer)
{
    if (timer == NULL)
    {
        return;
    }

    timer->remaining = timer->period;
}