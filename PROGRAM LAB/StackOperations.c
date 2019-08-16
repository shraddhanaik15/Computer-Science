// Stacks	

#include<stdio.h>
#define MAX 10
int op, val, temp;
int stack[MAX];
int top = -1;
int n, i;
void push()
{

	if(top == MAX-1)
	{
		printf("overflow\n");
	}
	else
	{
		printf("Enter the operand\n");
		scanf("%d", &op);
		top = top + 1;
		stack[top] = op;	
	}	
}

void pop()
{
	if(top == -1)
	{
		printf("Underflow\n");
	}
	else
	{
		
			temp = stack[top];
			top = top - 1;
		 
	}

	printf("Element popped from stack is %d \n", temp);
}


void display()
{
	
	if(top>=0)
	{
	printf("Elements of the stack is :\n");
	for(i=top; i>=0; i--)
	{
		printf("%d ", stack[i]);
	}
	}
	else
	{
		printf("Stack is empty \n");
	}
	
}

int main()
{

	do
	{
	printf("\nCreate stack \n");
	printf("Enter the operation no you wish to perform \n");
	printf(" 1. PUSH \n 2. POP \n 3. DISPLAY \n");
	scanf("%d", &n);
	switch(n)
	{
		case 1:   
				push();
				break;
		case 2: 
				pop();
				break;
		case 3: 
				display();
				break;
		
	}
	
		
}
while(n!=4);
	
return 0;

}

