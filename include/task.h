#include <assert.h>
#include <stdio.h>

#include "list.h"

int main(void)
{
    List list;

    ListNode node1 = {0};
    ListNode node2 = {0};
    ListNode node3 = {0};

    List_Init(&list);

    assert(List_IsEmpty(&list));

    assert(List_InsertBack(&list, &node1));
    assert(List_Size(&list) == 1);

    assert(List_InsertBack(&list, &node2));
    assert(List_Size(&list) == 2);

    assert(List_InsertFront(&list, &node3));
    assert(List_Size(&list) == 3);

    assert(List_Remove(&list, &node2));
    assert(List_Size(&list) == 2);

    assert(List_Remove(&list, &node3));
    assert(List_Size(&list) == 1);

    assert(List_Remove(&list, &node1));
    assert(List_IsEmpty(&list));

    printf("All linked list tests passed.\n");

    return 0;
}