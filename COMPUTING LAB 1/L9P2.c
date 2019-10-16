//Round Robin Method

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void main()
{

	int n,bt[10],at[10],q, ct[100], sum = 0,i,j,k=0,max,wt[100],tat[100],temp[100];
	printf("Enter no of packets\n");
	scanf("%d", &n);
	printf("Enter the Arrival time of each packet\n");
	for(i=0;i<n;i++)
		scanf("%d", &at[i]);
	printf("Enter the Burst time of each packet\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &bt[i]);
		k = k+bt[i];
		temp[i]=bt[i];
	
	}
	max = bt[0];
	for(i=1;i<n;i++)
	{
		if(bt[i]>max)
		{
			max = bt[i];
		}
	}
	
	printf("\nEnter the quantam time\n");
	scanf("%d", &q);

	for(i=0;i<ceil(max/q);i++)
	{	
	for(j=0;j<n;j++)
	{
		if(bt[j]>q)
		{
		 sum = sum + q;
		 bt[j] = bt[j]-q;
		 k = k-q;
		}

		else if(bt[j]>0)
		{
			sum = sum + bt[j];
			
			ct[j]=sum;
			k = k-bt[j];
			bt[j] = 0;	
		}
	}
	}

	for(i=0;i<n;i++)
	{
		tat[i] = ct[i]-at[i];  
		wt[i] = tat[i]-temp[i];
	}

	printf("Packet\t Arrival Time\t Burst Time\t Completion Time\t Turn Around Time\t Wait Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n",i,at[i],temp[i],ct[i],tat[i],wt[i]);
	}
		

}
