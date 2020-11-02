#include "Stack.h"

int miro[9][9] = {   
            {0, 0, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 0, 1, 0, 1},
            {1, 1, 0, 0, 1, 0, 1, 0, 2},
            {1, 0, 0, 1, 1, 0, 1, 1, 1},
            {1, 1, 0, 0, 0, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1}};

void Print_Route(Stack* yStack, Stack* xStack)
{
    int yRoute[50];
    int xRoute[50];
    int i=-1;
    while(1)
    {
        i++;
        if (Stack_IsEmpty(yStack))
        {
            break;
        }
        yRoute[i]=Stack_Pop(yStack);
        xRoute[i]=Stack_Pop(xStack);
    }
    for(int j=i-1; j>-1;j--)
    {
        printf("%d %d \n", yRoute[j], xRoute[j]);
    }
}

void CheckDirection(int y, int x, int* direction)
{
    if (y==0)
    {
        direction[0] = 0;
    }
    else if (miro[y-1][x]==1)
    {
        direction[0] = 0;
    }

    if (y==8)
    {
        direction[1] = 0;
    }
    else if (miro[y+1][x]==1) 
    {
        direction[1] = 0;
    }
    
    if (x==0)
    {
        direction[2] = 0;
    }
    else if (miro[y][x-1]==1)
    {
        direction[2]=0;
    }

    if (x==8)
    {
        direction[3] = 0;
    }
    else if (miro[y][x+1]==1)
    {
        direction[3] =0;
    }
}

int main(void)
{
    int currentX;
    int currentY;
    int previousX;
    int previousY;

    Stack *xStack = Stack_Init();
    Stack *yStack = Stack_Init();

    Stack_Push(yStack, 0);
    Stack_Push(xStack, 0);
    previousY = 0;
    previousX = 0;

    while (miro[Stack_Peek(yStack)][Stack_Peek(xStack)] != 2)
    {
        currentY = Stack_Pop(yStack);
        currentX = Stack_Pop(xStack);
        previousY = Stack_Peek(yStack);
        previousX = Stack_Peek(xStack);
        Stack_Push(yStack, currentY);
        Stack_Push(xStack, currentX);

        int direction[4] = {1,1,1,1};
        CheckDirection(currentY, currentX, direction);

        if (direction[0]==1 && currentY-1!=previousY)
        {
            currentY--;
        }
        else if (direction[1]==1 && currentY+1!=previousY)
        {
            currentY++;
        }
        else if (direction[2]==1 && currentX-1!=previousX)
        {
            currentX--;
        }
        else if (direction[3]==1 && currentX+1!=previousX)
        {
            currentX++;
        }
        else
        {
            miro[Stack_Pop(yStack)][Stack_Pop(xStack)]=1;
            continue;
        }
        
        Stack_Push(xStack, currentX);
        Stack_Push(yStack, currentY);
    }
    
    Print_Route(yStack, xStack);

    return 0;
}