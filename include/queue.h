#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>

#define QUEUE_MAX_ITEMS 32U

typedef struct
{
    uint32_t buffer[QUEUE_MAX_ITEMS];

    uint32_t head;

    uint32_t tail;

    uint32_t count;

} Queue;

void Queue_Init(Queue *queue);

bool Queue_IsEmpty(const Queue *queue);

bool Queue_IsFull(const Queue *queue);

bool Queue_Send(Queue *queue, uint32_t data);

bool Queue_Receive(Queue *queue, uint32_t *data);

uint32_t Queue_Size(const Queue *queue);

#endif