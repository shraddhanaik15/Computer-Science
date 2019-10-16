#include<stdio.h>
#include<math.h>
int main()
{
	printf("enter number of data bits :\n ");
	int m,r=0,i,d=0,j,count=0,v=0,z;
	scanf("%d",&m);
	printf("\n calculating redundant bits: \n");
	while(pow(2,r)<r+m+1)
	{
		r++;
	}
	printf("r is : %d",r);
	printf("\n--------------------\n");
	m=m+r;
	int a[m+1];
	printf("enter data bits:\n");
	for(i=1;i<=m;i++)
	{
		if(i==pow(2,d))
		{
		a[i]=0;
		printf("\n0 taken in a[%d]\n",i);
		d++;
		}
		else
		{
		printf("\nenter at a[%d]: ",i);
		scanf("%d",&a[i]);
		}
		printf("\n");
	}
	for(i=m;i>=1;i--)
	printf("%d ",a[i]);
	
	printf("\n--------------------\n");
	printf("parity bit cal: \n");
	for(i=0;i<r;i++)
	{
		z=j=pow(2,i);
		count=0;
		while(j<=m)
		{
			for(v=0;v<z;v++)
			{
			if(j<=m)
			{
				printf("checking a[%d] is %d\n",j,a[j]);
			if(a[j]==1)
			count++;
			j++;
			}
			}
			j=j+z;
		}
		printf("count is : %d\n",count);
		if(count%2!=0)
		{
		a[z]=1;	
		}
		printf("parity at position %d is %d \n",z,a[z]);
		
		}
		printf("\n");
	for(i=m;i>=1;i--)
	printf("%d",a[i]);
	
	int b[r];//currupt
	int pos;
	printf("\nenter bit position you want to corrupt:\n");
	scanf("%d",&pos);
	if(a[pos]==1)
	a[pos]=0;
	else
	a[pos]=1;
	
	printf("after corruption array looks like :\n");
	for(i=m;i>=1;i--)
	printf("%d",a[i]);
	//detect
		for(i=0;i<r;i++)
		{
		z=j=pow(2,i);
		count=0;
		while(j<=m)
		{
			for(v=0;v<z;v++)
			{
			if(j<=m)
			{
			printf("\nchecking a[%d] is %d\n",j,a[j]);
			if(a[j]==1)
			count++;
			j++;
				
			}
		}
			j=j+z;
		}
		z=r-i;
		if(count%2!=0){
		
		b[z]=1;	
		}
		else
		b[z]=0;
		printf(" b[%d]: %d\n",z,b[z]);
		}
		
		printf("curropted pos:\n ");
		for(i=r;i>=1;i--)
		printf("%d",b[i]);
	// binary conversion
	int sum=0;
	j=r;
	for(i=0;i<r;i++){
		sum=sum+b[j]*pow(2,i);
		j--;
	}
	printf("\nposition is : %d\n",sum);
	
	// corrected messgae 
	if(a[sum]==1)
	a[sum]=0;
	else
	a[sum]=1;
	
	for(i=m;i>=1;i--)
	{
		printf("%d",a[i]);
	}

	return 0;
}
