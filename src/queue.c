#include "queue.h"

void Queue_Init(Queue *queue)
{
    if(queue == NULL)
        return;

    queue->head = 0;

    queue->tail = 0;

    queue->count = 0;
}

bool Queue_IsEmpty(const Queue *queue)
{
    return (queue->count == 0U);
}

bool Queue_IsFull(const Queue *queue)
{
    return (queue->count >= QUEUE_MAX_ITEMS);
}

bool Queue_Send(Queue *queue, uint32_t data)
{
    if(queue == NULL)
        return false;

    if(Queue_IsFull(queue))
        return false;

    queue->buffer[queue->tail] = data;

    queue->tail++;

    if(queue->tail >= QUEUE_MAX_ITEMS)
    {
        queue->tail = 0;
    }

    queue->count++;

    return true;
}

bool Queue_Receive(Queue *queue, uint32_t *data)
{
    if(queue == NULL || data == NULL)
        return false;

    if(Queue_IsEmpty(queue))
        return false;

    *data = queue->buffer[queue->head];

    queue->head++;

    if(queue->head >= QUEUE_MAX_ITEMS)
    {
        queue->head = 0;
    }

    queue->count--;

    return true;
}

uint32_t Queue_Size(const Queue *queue)
{
    return queue->count;
}