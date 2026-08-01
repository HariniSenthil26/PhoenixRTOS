/*
 * ============================================================================
 * PhoenixRTOS
 * Generic Doubly Linked List
 * ============================================================================
 */

#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Generic list node.
 *
 * Every kernel object (TCB, Queue, Timer, Semaphore)
 * will embed or reference a ListNode.
 */
typedef struct ListNode
{
    void *data;

    struct ListNode *next;

    struct ListNode *prev;

} ListNode;

/**
 * @brief Doubly linked list descriptor.
 */
typedef struct
{
    ListNode *head;

    ListNode *tail;

    uint32_t size;

} List;

/* Initialization */

void List_Init(List *list);

/* Information */

bool List_IsEmpty(const List *list);

uint32_t List_Size(const List *list);

/* Operations */

bool List_InsertFront(List *list, ListNode *node);

bool List_InsertBack(List *list, ListNode *node);

bool List_Remove(List *list, ListNode *node);

void List_Clear(List *list);

#endif