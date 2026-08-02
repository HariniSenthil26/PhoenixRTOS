/*
 * ============================================================================
 * MiniRTOS
 * Software Timer
 * ============================================================================
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include <stdint.h>

typedef void (*TimerCallback)(void);

typedef struct
{
    uint32_t period;

    uint32_t remaining;

    bool periodic;

    bool active;

    TimerCallback callback;

} Timer;


/******************************************************************************
 * APIs
 ******************************************************************************/

void Timer_Init(
    Timer *timer,
    uint32_t period,
    bool periodic,
    TimerCallback callback);

void Timer_Start(Timer *timer);

void Timer_Stop(Timer *timer);

void Timer_Reset(Timer *timer);

#endif