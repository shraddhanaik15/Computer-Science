#include<stdio.h>
int mid;
int n, a[100], i, target, c=0;
int BinarySearch(int a[], int first, int last, int target)
{
	
		while(first <= last)
		{
			
			mid = (first+last)/2;
			c++;
			
		if(a[mid]==target)
		{
			return mid;
		}
		else if(a[mid]<target)
		{
			first = mid +1;	
		}
		else if(a[mid]>target)
		{
			last = mid - 1;
		}
		else
		{
		return -1;
		}
	}
}
void main()
{
	
	printf("Enter the no of elements in the array\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("Enter the target element to be searched\n");
	scanf("%d", &target);
	BinarySearch(a, 0, n-1, target);
	printf("\nElement found in position %d ", mid);
	printf("\nNo of searches is %d", c);

}
