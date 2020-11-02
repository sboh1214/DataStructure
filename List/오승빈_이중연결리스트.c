#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int Data;
    struct _Node *Next;
    struct _Node *Prev;
} Node;

typedef struct _ldList
{
    Node *Head;
} ldList;

ldList *ldList_Init()
{
    ldList *list = (ldList *)malloc(sizeof(ldList));
    list->Head = NULL;
    printf("Initiate 이중연결리스트\n");
    return list;
}

int ldList_Insert(ldList *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *prevNode;
    Node *nextNode;
    node->Data = data;
    node->Next = NULL;
    node->Prev = NULL;

    if (list->Head == NULL)
    {
        list->Head = node;
        printf("Insert %d \n", data);
        return 0;
    }

    prevNode = list->Head;
    nextNode = list->Head->Next;

    while (1)
    {
        if (data >= prevNode->Data && prevNode->Prev == NULL)
        {
            list->Head = node;
            node->Next = prevNode;
            prevNode->Prev = node;
            printf("Insert %d \n", data);
            return 0;
        }
        if (prevNode->Data >= data && data >= nextNode->Data)
        {
            node->Next = nextNode;
            node->Prev = prevNode;
            prevNode->Next = node;
            nextNode->Prev = node;
            printf("Insert %d \n", data);
            return 0;
        }
        if (nextNode->Data >= data && nextNode->Next == NULL)
        {
            nextNode->Next = node;
            node->Prev = nextNode;
            printf("Insert %d \n", data);
            return 0;
        }
        prevNode = prevNode->Next;
        nextNode = nextNode->Next;
    }

    return 0;
}

int ldList_Delete(ldList *list, int data)
{
    Node *delNode;
    Node *prevNode;
    Node *nextNode;
    if (list->Head == NULL)
    {
        printf("Can't Delete %d. List is empty. \n", data);
        return -1;
    }
    if (list->Head->Data == data)
    {
        delNode = list->Head;
        nextNode = list->Head->Next;
        nextNode->Prev = NULL;
        list->Head = nextNode;
        free(delNode);
        printf("Delete %d \n", data);
        return 0;
    }
    else
    {
        delNode = list->Head->Next;
    }

    while (1)
    {
        if (delNode->Data == data)
        {
            prevNode = delNode->Prev;
            nextNode = delNode->Next;
            if (prevNode!=NULL)
            {
                prevNode->Next = nextNode;
            }
            if (nextNode!=NULL)
            {
                nextNode->Prev = prevNode;
            }
        
            free(delNode);
            printf("Delete %d \n", data);
            return 0;
        }
        delNode = delNode->Next;
        if (delNode == NULL)
        {
            break;
        }
    }

    printf("Can't Delete %d. There is no such data \n", data);

    return 0;
}

int ldList_Print(ldList *list)
{
    if (list->Head == NULL)
    {
        printf("Can't Print. There is no data.\n");
        return -1;
    }
    Node *curNode = list->Head;
    while (curNode != NULL)
    {
        printf("%d ", curNode->Data);
        curNode = curNode->Next;
    }
    printf("\n");
    return 0;
}

int main(void)
{
    ldList *list = ldList_Init();
    ldList_Insert(list, 9);
    ldList_Insert(list, 10);
    ldList_Insert(list, 3);
    ldList_Delete(list, 9);
    ldList_Insert(list, 1);
    ldList_Insert(list, 4);
    ldList_Insert(list, 7);
    ldList_Print(list);
    ldList_Delete(list, 4);
    ldList_Delete(list, 1);
    ldList_Delete(list, 7);
    ldList_Delete(list, 10);
    ldList_Print(list);
    return 0;
}