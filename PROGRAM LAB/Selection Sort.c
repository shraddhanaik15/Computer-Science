#include<stdio.h>
int n, a[10], i, j, temp, min, c1 = 0, c2=0;
void SelectionSort(int n, int a[])
{
	
		for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
			temp = a[i];
			a[i]=a[min];
			a[min]=temp;
			c1++;
			 	
		}
		c2++;
			
	}
}


void print(int n, int a[], int c1, int c2)
{
		for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\nNo of passes and comparisons required is %d", c1+c2);
	
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
	
	
	SelectionSort(n,a);
	print(n,a,c1,c2);
	
}
