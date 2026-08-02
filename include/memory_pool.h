/*
 * ============================================================================
 * MiniRTOS
 * Memory Pool Manager
 * ============================================================================
 */

#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stdbool.h>
#include <stdint.h>

#define MEMORY_POOL_BLOCK_SIZE    (64U)
#define MEMORY_POOL_NUM_BLOCKS    (32U)

void MemoryPool_Init(void);

void *MemoryPool_Allocate(void);

bool MemoryPool_Free(void *ptr);

uint32_t MemoryPool_FreeBlocks(void);

uint32_t MemoryPool_TotalBlocks(void);

#endif