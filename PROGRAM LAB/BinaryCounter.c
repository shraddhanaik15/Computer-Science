#include<stdio.h>
int n, i, a[100], j;

void increment(int a[])
{
		for(j=0;j<16;j++)
		{
			for(i=0;i<8; i++)
			{			
			while(i<8 && a[i]==1)
		{
		
					a[i]=0;
					i = i+1;
		}
			if(i<8)
				{
					a[i]=1;	
					printf("%d ", a[i]);
					printf("\n");
				}
			}
		}
	}

void main()
{
	
	printf("Enter an 8 bit binary no");
	for(i=0;i<8;i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0;i<8;i++)
	{
		a[i]=0;
	}
	increment(a);

}
