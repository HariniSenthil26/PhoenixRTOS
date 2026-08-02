/*
 * ============================================================================
 * MiniRTOS
 * Ready Queue
 * ============================================================================
 */

#include "ready_queue.h"

#include "list.h"

static List g_readyQueue;


/******************************************************************************
 * Initialize Ready Queue
 ******************************************************************************/

void ReadyQueue_Init(void)
{
    List_Init(&g_readyQueue);
}


/******************************************************************************
 * Insert Task (Priority Sorted)
 ******************************************************************************/

bool ReadyQueue_Insert(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    ListNode *node = &task->node;

    node->data = task;

    if (List_IsEmpty(&g_readyQueue))
    {
        return List_InsertFront(&g_readyQueue, node);
    }

    ListNode *current = g_readyQueue.head;

    while (current != NULL)
    {
        TCB *currentTask = (TCB *)current->data;

        /*
         * Lower numerical value = Higher priority
         */

        if (task->priority < currentTask->priority)
        {
            node->next = current;
            node->prev = current->prev;

            if (current->prev != NULL)
            {
                current->prev->next = node;
            }
            else
            {
                g_readyQueue.head = node;
            }

            current->prev = node;

            g_readyQueue.size++;

            return true;
        }

        current = current->next;
    }

    return List_InsertBack(&g_readyQueue, node);
}


/******************************************************************************
 * Remove Task
 ******************************************************************************/

bool ReadyQueue_Remove(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    return List_Remove(&g_readyQueue, &task->node);
}


/******************************************************************************
 * Highest Priority Task
 ******************************************************************************/

TCB *ReadyQueue_GetHighestPriority(void)
{
    if (List_IsEmpty(&g_readyQueue))
    {
        return NULL;
    }

    return (TCB *)g_readyQueue.head->data;
}


/******************************************************************************
 * Queue Empty?
 ******************************************************************************/

bool ReadyQueue_IsEmpty(void)
{
    return List_IsEmpty(&g_readyQueue);
}


/******************************************************************************
 * Queue Size
 ******************************************************************************/

uint32_t ReadyQueue_Size(void)
{
    return List_Size(&g_readyQueue);
}