#include <stdio.h>

#include "list.h"

int main(void)
{
    List list;

    ListNode node1;

    ListNode node2;

    List_Init(&list);

    List_InsertFront(&list,&node1);

    List_InsertFront(&list,&node2);

    printf("Size : %u\n",List_Size(&list));

    return 0;
}