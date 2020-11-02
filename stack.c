#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct Node
{
    int Data;
    struct Node *Ptr;
} Node;

typedef struct Stack
{
    Node *TopPtr;
} Stack;

Stack *Stack_Init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->TopPtr = NULL;
    return stack;
}

int Stack_IsEmpty(Stack *stack)
{
    if (stack->TopPtr==NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}

void Stack_Push(Stack *stack, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->Data = value;
    node->Ptr = stack->TopPtr;
    stack->TopPtr = node;
}

int Stack_Pop(Stack *stack)
{
    int value;
    if (stack->TopPtr == NULL)
    {
        value = ERROR;
        printf("ERROR");
        return value;
    }
    else
    {
        Node *node = stack->TopPtr;
        value = node->Data;
        stack->TopPtr = node->Ptr;
        free(node);
        return value;
    }
}

int Stack_Peek(Stack *stack)
{
    int value;
    if (stack->TopPtr == NULL)
    {
        value = ERROR;
        printf("ERROR");
        return value;
    }
    else
    {
        value = stack->TopPtr->Data;
        return value;
    }
}

int main(void)
{
    Stack *stack = Stack_Init();
    printf("%d \n", Stack_IsEmpty(stack));
    Stack_Push(stack,1);
    Stack_Push(stack,2);
    Stack_Push(stack,3);
    printf("%d \n",Stack_Pop(stack));
    printf("%d \n",Stack_Peek(stack));
    printf("%d \n",Stack_Pop(stack));
    printf("%d \n",Stack_Pop(stack));
    printf("%d \n",Stack_Pop(stack));
}