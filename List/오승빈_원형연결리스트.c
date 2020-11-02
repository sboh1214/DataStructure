#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int Data;
    struct _Node *Next;
} Node;

typedef struct _csList
{
    Node *Tail;
} csList;

csList *csList_Init()
{
    csList *list = (csList *)malloc(sizeof(csList));
    list->Tail = NULL;
    return list;
}

int csList_Insert(csList *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *prevNode;
    Node *nextNode;
    node->Data = data;
    node->Next = NULL;

    if (list->Tail == NULL)
    {
        node->Next = node;
        list->Tail = node;
        return 0;
    }

    prevNode = list->Tail->Next;
    if (data <= prevNode->Data)
    {
        node->Next = list->Tail->Next;
        list->Tail->Next = node;
        return 0;
    }

    if (list->Tail->Data <= data)
    {
        prevNode = list->Tail;
        nextNode = prevNode->Next;
        prevNode->Next = node;
        node->Next = nextNode;
        list->Tail = node;
        return 0;
    }

    nextNode = prevNode->Next;
    while (1)
    {
        if (prevNode->Data <= data && data <= nextNode->Data)
        {
            prevNode->Next = node;
            node->Next = nextNode;
            return 0;
        }
        prevNode = prevNode->Next;
        nextNode = nextNode->Next;
    }
    return 0;
}

int csList_Delete(csList *list)
{
    if (list->Tail == NULL)
    {
        printf("Can't Delete \n");
        return -1;
    }
    Node *delNode = list->Tail->Next;
    list->Tail->Next = list->Tail->Next->Next;
    printf("Delete %d \n", delNode->Data);
    free(delNode);
    return 0;
}

int csList_Print(csList *list)
{
    if (list->Tail == NULL)
    {
        printf("Can't Print \n");
        return -1;
    }
    Node *node = list->Tail;
    while (1)
    {
        node = node->Next;
        printf("%d ", node->Data);
        if (node == list->Tail)
        {
            printf("\n");
            return 0;
        }
    }
    return 0;
}

int main(void)
{
    csList *list = csList_Init();
    csList_Insert(list, 9);
    csList_Insert(list, 10);
    csList_Insert(list, 3);
    csList_Delete(list);
    csList_Insert(list, 1);
    csList_Insert(list, 4);
    csList_Insert(list, 7);
    csList_Print(list);
    csList_Delete(list);
    csList_Delete(list);
    csList_Delete(list);
    csList_Print(list);
    return 0;
}