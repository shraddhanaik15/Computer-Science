#include<stdio.h>

void main()
{
	int sum=0;
	int n,at[10],bt[10],i,pr[10],ct[100],tat[100],wt[100],npr[100],j,min,pos,t,p[10];

	printf("\nEnter the no of packets\n");
	scanf("%d", &n);
	printf("Arrival time of all processes is 0\n");
	printf("Enter the packet no\n");
		for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}

	printf("\nEnter the Burst time of each packet\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &bt[i]);
	}
	printf("Enter the priorities of each packet\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &pr[i]);
	}
	for(i=0;i<n;i++)
	{
		pos =i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
			{
				pos=j;
			}
		}
		t=pr[i];
		pr[i]=pr[pos];
		pr[pos]=t;
		
		t=bt[i];
		bt[i]=bt[pos];
		bt[pos]=t;
		
		t=p[i];
		p[i]=p[pos];
		p[pos]=t;
				
	}

	for(i=0;i<n;i++)
	{
		sum = sum +bt[i];
		ct[i] = sum;
		tat[i] = ct[i]-0;  
		wt[i] = tat[i]-bt[i];	
	}
	
		printf("Packet\t Burst Time\t Priority\t Completion Time\t Turn Around Time\t Wait Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n",p[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
	}
	
}
