#include "list.h"

void List_Init(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

bool List_IsEmpty(const List *list)
{
    return (list->size == 0);
}

uint32_t List_Size(const List *list)
{
    return list->size;
}