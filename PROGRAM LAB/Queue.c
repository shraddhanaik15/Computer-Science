#include<stdio.h>
#define MAX 10

int front = 0, rear = 0;
int queue[MAX];
int i;
int item, temp;
void enqueue()
{
	
	printf("Enter the value in the queue\n");
	scanf("%d", &item);
	if(rear==MAX -1)
	{
		printf("queue is full");
	}
	else
	{
		rear = rear + 1;
		queue[rear] = item;
	}
	
}

void dequeue()
{
	if(front == rear)
	{
		printf("Stack is empty");
	}
	else
	{
		temp = queue[front+1];
		front = front + 1;
		printf("Element deleted from the queue is %d\n", temp);
	}
}

void display()
{
	if(front<rear)
	{
	for(i=front+1 ; i<=rear; i++)
	{
		printf("%d ", queue[i]);
	}
	}
	else
	{
		printf("No values in the queue \n");
	}
    
}

void main()
{
	int n;
	do
	{
		printf("\nCreate Queue\n");
		printf(" 1.Enqueue \n 2.Dequeue \n 3.Display \n");
		printf("Enter the operation to be performed\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1 : enqueue(); 
					 break;
			case 2 : dequeue();
					 break;
			case 3 : display();
					 break;
		}
	}
	while(n!=4);
	
	
}
