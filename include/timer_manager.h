/*
 * ============================================================================
 * MiniRTOS
 * Timer Manager
 * ============================================================================
 */

#ifndef TIMER_MANAGER_H
#define TIMER_MANAGER_H

#include <stdbool.h>
#include <stdint.h>

#include "timer.h"

#define MAX_TIMERS    (16U)

/******************************************************************************
 * APIs
 ******************************************************************************/

void TimerManager_Init(void);

bool TimerManager_Add(Timer *timer);

bool TimerManager_Remove(Timer *timer);

void TimerManager_Tick(void);

uint32_t TimerManager_Count(void);

#endif