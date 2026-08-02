/*
 * ============================================================================
 * MiniRTOS
 * Memory Pool Manager
 * ============================================================================
 */

#include "memory_pool.h"

#include <stddef.h>

static uint8_t g_memoryPool
    [MEMORY_POOL_NUM_BLOCKS]
    [MEMORY_POOL_BLOCK_SIZE];

static bool g_blockUsed[MEMORY_POOL_NUM_BLOCKS];


/******************************************************************************
 * Initialize Memory Pool
 ******************************************************************************/

void MemoryPool_Init(void)
{
    uint32_t i;

    for (i = 0; i < MEMORY_POOL_NUM_BLOCKS; i++)
    {
        g_blockUsed[i] = false;
    }
}


/******************************************************************************
 * Allocate Memory Block
 ******************************************************************************/

void *MemoryPool_Allocate(void)
{
    uint32_t i;

    for (i = 0; i < MEMORY_POOL_NUM_BLOCKS; i++)
    {
        if (!g_blockUsed[i])
        {
            g_blockUsed[i] = true;

            return (void *)g_memoryPool[i];
        }
    }

    return NULL;
}


/******************************************************************************
 * Free Memory Block
 ******************************************************************************/

bool MemoryPool_Free(void *ptr)
{
    uint32_t i;

    if (ptr == NULL)
    {
        return false;
    }

    for (i = 0; i < MEMORY_POOL_NUM_BLOCKS; i++)
    {
        if (ptr == (void *)g_memoryPool[i])
        {
            if (!g_blockUsed[i])
            {
                return false;
            }

            g_blockUsed[i] = false;

            return true;
        }
    }

    return false;
}


/******************************************************************************
 * Number of Free Blocks
 ******************************************************************************/

uint32_t MemoryPool_FreeBlocks(void)
{
    uint32_t i;
    uint32_t count = 0U;

    for (i = 0; i < MEMORY_POOL_NUM_BLOCKS; i++)
    {
        if (!g_blockUsed[i])
        {
            count++;
        }
    }

    return count;
}


/******************************************************************************
 * Total Blocks
 ******************************************************************************/

uint32_t MemoryPool_TotalBlocks(void)
{
    return MEMORY_POOL_NUM_BLOCKS;
}