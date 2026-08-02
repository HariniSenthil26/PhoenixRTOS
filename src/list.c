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
    if ((list == NULL) || (node == NULL))
    {
        return false;
    }

    node->prev = NULL;

    if (List_IsEmpty(list))
    {
        node->next = NULL;

        list->head = node;

        list->tail = node;
    }
    else
    {
        node->next = list->head;

        list->head->prev = node;

        list->head = node;
    }

    list->size++;

    return true;
}

bool List_InsertBack(List *list, ListNode *node)
{
    if ((list == NULL) || (node == NULL))
    {
        return false;
    }

    node->next = NULL;

    if (List_IsEmpty(list))
    {
        node->prev = NULL;

        list->head = node;
        list->tail = node;
    }
    else
    {
        node->prev = list->tail;

        list->tail->next = node;

        list->tail = node;
    }

    list->size++;

    return true;
}

bool List_Remove(List *list, ListNode *node)
{
    if ((list == NULL) || (node == NULL))
    {
        return false;
    }

    if (List_IsEmpty(list))
    {
        return false;
    }

    /* Update head */
    if (node == list->head)
    {
        list->head = node->next;
    }

    /* Update tail */
    if (node == list->tail)
    {
        list->tail = node->prev;
    }

    /* Connect previous node */
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }

    /* Connect next node */
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    /* Disconnect removed node */
    node->next = NULL;
    node->prev = NULL;

    list->size--;

    return true;
}

void List_Clear(List *list)
{
    if (list == NULL)
    {
        return;
    }

    ListNode *current = list->head;

    while (current != NULL)
    {
        ListNode *next = current->next;

        current->next = NULL;
        current->prev = NULL;

        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0U;
}