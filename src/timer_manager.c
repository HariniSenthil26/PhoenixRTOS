/*
 * ============================================================================
 * MiniRTOS
 * Timer Manager
 * ============================================================================
 */

#include "timer_manager.h"

#include <stddef.h>

static Timer *g_timerList[MAX_TIMERS];

static uint32_t g_timerCount = 0U;


/******************************************************************************
 * Initialize
 ******************************************************************************/

void TimerManager_Init(void)
{
    uint32_t i;

    g_timerCount = 0U;

    for (i = 0U; i < MAX_TIMERS; i++)
    {
        g_timerList[i] = NULL;
    }
}


/******************************************************************************
 * Add Timer
 ******************************************************************************/

bool TimerManager_Add(Timer *timer)
{
    if (timer == NULL)
    {
        return false;
    }

    if (g_timerCount >= MAX_TIMERS)
    {
        return false;
    }

    g_timerList[g_timerCount] = timer;

    g_timerCount++;

    return true;
}


/******************************************************************************
 * Remove Timer
 ******************************************************************************/

bool TimerManager_Remove(Timer *timer)
{
    uint32_t i;

    if (timer == NULL)
    {
        return false;
    }

    for (i = 0U; i < g_timerCount; i++)
    {
        if (g_timerList[i] == timer)
        {
            uint32_t j;

            for (j = i; j < (g_timerCount - 1U); j++)
            {
                g_timerList[j] = g_timerList[j + 1U];
            }

            g_timerList[g_timerCount - 1U] = NULL;

            g_timerCount--;

            return true;
        }
    }

    return false;
}


/******************************************************************************
 * Tick Update
 ******************************************************************************/

void TimerManager_Tick(void)
{
    uint32_t i;

    for (i = 0U; i < g_timerCount; i++)
    {
        Timer *timer = g_timerList[i];

        if ((timer == NULL) || (!timer->active))
        {
            continue;
        }

        if (timer->remaining > 0U)
        {
            timer->remaining--;
        }

        if (timer->remaining == 0U)
        {
            if (timer->callback != NULL)
            {
                timer->callback();
            }

            if (timer->periodic)
            {
                timer->remaining = timer->period;
            }
            else
            {
                timer->active = false;
            }
        }
    }
}


/******************************************************************************
 * Timer Count
 ******************************************************************************/

uint32_t TimerManager_Count(void)
{
    return g_timerCount;
}