#include<stdio.h>
#define MAX 10
int top = -1, stack[MAX], i, item, temp;
int n;

void push()
{
	printf("Enter the element to be pushed\n");
	scanf("%d", &item);
	if(top==MAX-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		top=top+1;
		stack[top] = item;
	}


}

void pop()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		temp=stack[top];
		top = top-1;
	}
}

void multipop()
{
	int k;
	printf("How many elements you wish to pop out from the stack\n");
	scanf("%d", &k);
	if(k>top)
	{
		printf("Elements to be popped out are more than the elements on the stack.\nMultipop operation cannot be performed.\n");
	}
	else
	{
		for(i=0; i<k;i++)
		{
			temp=stack[top];
			top=top-1;
		}
	}
}



void display()
{

	printf("\nElements in the stack are :\n");
	if(top>=0)
	{
	for(i=top; i>=0; i--)
	{
		printf("%d ", stack[i]);
	}
	}
	else
	{
		printf("Stack is empty\n");
	}
}

void main()
{

	
	
	do
	{
	printf("Create Stack\n");
	printf(" 1.PUSH\n 2.POP\n 3.MULTIPOP\n 4.DISPLAY\n");
	printf("Enter your choice\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1 : push();
				 break;
		case 2 : pop();
				 break;
		case 3: multipop();
				break;
		case 4: display();
				break;



	}
}

	while(n!=5);




}