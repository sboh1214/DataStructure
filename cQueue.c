#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define LENGTH 5
#define ERROR -1

typedef struct 
{
	int data[LENGTH];
	int * front;
	int * rear;
}cQueue;

cQueue* init()
{
	cQueue * ptr = (cQueue*)malloc(sizeof(cQueue));
	ptr->front = &(ptr->data[0]);
	ptr->rear = &(ptr->data[0]);
}

int enqueue(cQueue * ptr, int value)
{
	if (isFull(ptr)==TRUE)
	{
		printf("Can't enqueue. Queue is full.\n");
		return ERROR;
	}
	if(&(ptr->data[LENGTH])==ptr->rear)
	{
		ptr->rear = ptr->data;
	}
	else
	{
		ptr->rear++;
	}
	*(ptr->rear)=value;
	return TRUE;
}

int dequeue(cQueue * ptr)
{
	int value;
	if (isEmpty(ptr)==TRUE)
	{
		printf("Can't dequeue. There is no data.\n");
	}
	if (&(ptr->data[LENGTH])==ptr->front)
	{
		ptr->front=ptr->data;	
	}
	else
	{
		ptr->front++;		
	}
	value= *(ptr->front);
	return value;
}

int peek(cQueue * ptr)
{
	int value;
	if (isEmpty(ptr)==TRUE)
	{
		printf("Can't peek. There is no data.\n");
		return ERROR;
	}
	if (&(ptr->data[LENGTH])==ptr->front)
	{
		value = ptr->data[0];
	}
	else
	{
		value = *((ptr->front)+1);
	}	
	return value;
}

int isEmpty(cQueue*ptr)
{
	if (ptr->front==ptr->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int isFull(cQueue*ptr)
{
	if (ptr->rear + 1 == ptr->front)
	{
		return TRUE;
	}
	else if (ptr->rear == &(ptr->data[LENGTH]) && ptr->front == ptr->data)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int main(void)
{
	cQueue * q = init();
	printf("IsEmpty : %d \n", isEmpty(q));
	printf("%p %p \n",q->rear,q->front);
	enqueue(q,1);
	printf("enqueue : 1 \n");
		printf("%p %p \n",q->rear,q->front);
	enqueue(q,2);
	printf("enqueue : 2 \n");
		printf("%p %p\n",q->rear,q->front);
	printf("dequeue : %d \n",dequeue(q));
		printf("%p %p \n",q->rear,q->front);
	printf("dequeue : %d \n",dequeue(q));
		printf("%p %p \n",q->rear,q->front);
	printf("IsEmpty : %d \n",isEmpty(q));
		printf("%p %p \n",q->rear,q->front);
	
	enqueue(q,1);
		printf("%p %p \n",q->rear,q->front);
	printf("enqueue : 1 \n");
	enqueue(q,2);
			printf("%p %p \n",q->rear,q->front);
	printf("enqueue : 2 \n");
	enqueue(q,3);
			printf("%p %p \n",q->rear,q->front);
	printf("enqueue : 3 \n");
	enqueue(q,4);
			printf("%p %p \n",q->rear,q->front);
	printf("enqueue : 4 \n");
	
	printf("IsFull : %d", isFull(q));
	
	//printf("peek : %d", peek(q));
	printf("dequeue : %d \n",dequeue(q));
	printf("dequeue : %d \n",dequeue(q));
	printf("dequeue : %d \n",dequeue(q));
	printf("dequeue : %d \n",dequeue(q));
	return 0;
}
