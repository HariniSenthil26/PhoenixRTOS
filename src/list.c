#include "list.h"

void List_Init(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0U;
}

bool List_IsEmpty(const List *list)
{
    return (list->size == 0U);
}

uint32_t List_Size(const List *list)
{
    return list->size;
}

/*
 * TODO
 */

bool List_InsertFront(List *list, ListNode *node)
{
    (void)list;
    (void)node;

    return false;
}

bool List_InsertBack(List *list, ListNode *node)
{
    (void)list;
    (void)node;

    return false;
}

bool List_Remove(List *list, ListNode *node)
{
    (void)list;
    (void)node;

    return false;
}

void List_Clear(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0U;
}