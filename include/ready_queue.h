/*
 * ============================================================================
 * MiniRTOS
 * Ready Queue
 * ============================================================================
 */

#ifndef READY_QUEUE_H
#define READY_QUEUE_H

#include <stdbool.h>
#include <stdint.h>

#include "task.h"

void ReadyQueue_Init(void);

bool ReadyQueue_Insert(TCB *task);

bool ReadyQueue_Remove(TCB *task);

TCB *ReadyQueue_GetHighestPriority(void);

void ReadyQueue_Rotate(void);

bool ReadyQueue_IsEmpty(void);

uint32_t ReadyQueue_Size(void);

#endif