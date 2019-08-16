#include<stdio.h>
int n, a[100], i, j, temp, c1=0,c2=0, swapped = 0;

void BubbleSort(int n, int a[])
{
		for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j]= a[j+1];
				a[j+1] = temp;
				swapped = 1;
			}
			c1++;
		}
		c2++;
		if(swapped==0)
		break;
	}
	
}

void print(int n, int a[], int c1, int c2)
{
		for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\nNo of passes and comparsions are : %d", c1+c2);
	
}
void main()
{
	
	printf("Enter the no of elements\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i=0;i<n; i++)
	{
		scanf("%d", &a[i]);
	}	
	
	BubbleSort(n,a);
	print(n,a, c1,c2);
}
