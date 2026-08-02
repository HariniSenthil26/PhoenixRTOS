/*
 * ============================================================================
 * MiniRTOS
 * Blocked Queue
 * ============================================================================
 */

#ifndef BLOCKED_QUEUE_H
#define BLOCKED_QUEUE_H

#include <stdbool.h>
#include <stdint.h>

#include "task.h"

void BlockedQueue_Init(void);

bool BlockedQueue_Insert(TCB *task);

bool BlockedQueue_Remove(TCB *task);

void BlockedQueue_Update(void);

uint32_t BlockedQueue_Size(void);

#endif