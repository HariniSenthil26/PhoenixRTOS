#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdbool.h>

/* List node */
typedef struct ListNode
{
    void *data;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

/* Doubly linked list */
typedef struct
{
    ListNode *head;
    ListNode *tail;
    uint32_t size;
} List;

/* API */
void List_Init(List *list);

bool List_IsEmpty(const List *list);

uint32_t List_Size(const List *list);

#endif