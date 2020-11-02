#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int Data;
    struct _Node* Next;
}Node;

typedef struct _lsList
{
    Node* Head;
}lsList;

lsList* lsList_Init()
{
    lsList* list = (lsList*)malloc(sizeof(lsList));
    list->Head = NULL;
    printf("Initiate 단일연결리스트 \n");
    return list;
}

int lsList_Insert(lsList* list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    Node* prevNode;
    Node* nextNode;
    node->Data = data;
    node->Next = NULL;

    if (list->Head==NULL)
    {
        list->Head = node;
        printf("Insert %d \n",data);
        return 0;
    }
    else if (list->Head->Data>=data)
    {
        node->Next = list->Head;
        list->Head = node;
        printf("Insert %d \n",data);
        return 0;
    }
    prevNode = list->Head;
    nextNode = prevNode->Next;
    while (1)
    {
        if (nextNode==NULL)
        {
            prevNode->Next = node;
            printf("Insert %d \n",data);
            return 0;
        }
        else if (prevNode->Data<=data && data<=nextNode->Data)
        {
            prevNode->Next = node;
            node->Next = nextNode;
            printf("Insert %d \n",data);
            return 0;
        }
        prevNode = prevNode->Next;
        nextNode = nextNode->Next;
    }
    
    return 0;
}

int lsList_Delete(lsList* list)
{
    if (list->Head==NULL)
    {
        printf("Can't Delete. List is empty. \n");
        return -1;
    }
    Node* delNode = list->Head;
    Node* headNode = delNode->Next;
    list->Head = headNode;
    printf("Delete %d \n",delNode->Data);
    free(delNode);
    return 0;
}

int lsList_Print(lsList * list)
{
    if (list->Head==NULL)
    {
        printf("Can't Print. List is Empty. \n");
        return -1;
    }
    Node * curNode = list->Head;
    while(curNode!=NULL)
    {
        printf("%d ", curNode->Data);
        curNode = curNode->Next;
    }
    printf("\n");
    return 0;
}

int main(void)
{
    lsList* list = lsList_Init();
    lsList_Insert(list, 9);
    lsList_Insert(list, 10);
    lsList_Insert(list, 3);
    lsList_Delete(list);
    lsList_Insert(list, 1);
    lsList_Insert(list, 4);
    lsList_Insert(list, 7);
    lsList_Print(list);
    lsList_Delete(list);
    lsList_Delete(list);
    lsList_Delete(list);
    lsList_Print(list);
    return 0;
}