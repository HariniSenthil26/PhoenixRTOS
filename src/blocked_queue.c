/*
 * ============================================================================
 * MiniRTOS
 * Blocked Queue
 * ============================================================================
 */

#include "blocked_queue.h"

#include "list.h"
#include "ready_queue.h"

static List g_blockedQueue;


/******************************************************************************
 * Initialize
 ******************************************************************************/

void BlockedQueue_Init(void)
{
    List_Init(&g_blockedQueue);
}


/******************************************************************************
 * Insert
 ******************************************************************************/

bool BlockedQueue_Insert(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    Task_SetState(task, TASK_BLOCKED);

    return List_InsertBack(
            &g_blockedQueue,
            &task->node);
}


/******************************************************************************
 * Remove
 ******************************************************************************/

bool BlockedQueue_Remove(TCB *task)
{
    if (task == NULL)
    {
        return false;
    }

    return List_Remove(
            &g_blockedQueue,
            &task->node);
}


/******************************************************************************
 * Tick Update
 ******************************************************************************/

void BlockedQueue_Update(void)
{
    ListNode *current = g_blockedQueue.head;

    while (current != NULL)
    {
        ListNode *next = current->next;

        TCB *task = (TCB *)current->data;

        if (task->delayTicks > 0U)
        {
            task->delayTicks--;
        }

        if (task->delayTicks == 0U)
        {
            BlockedQueue_Remove(task);

            Task_SetState(task, TASK_READY);

            ReadyQueue_Insert(task);
        }

        current = next;
    }
}


/******************************************************************************
 * Size
 ******************************************************************************/

uint32_t BlockedQueue_Size(void)
{
    return List_Size(&g_blockedQueue);
}