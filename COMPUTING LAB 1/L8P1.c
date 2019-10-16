#include<stdio.h>
void main()
{
	int n,bt[10],tat[10],at[10],i,j,temp,wt[10],ct[100]={0},sum = 0;
	printf("\nEnter the no of packets\n");
	scanf("%d", &n);

	printf("\nEnter the Arrival time of each packet\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &at[i]);
	}

	printf("\nEnter the Burst time of each packet\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &bt[i]);
	}

	//Completition time
	for(i=0;i<n;i++)
	{
		while(at[i]>sum)
		 sum++;
		sum = sum +bt[i];
		ct[i] = sum;
		tat[i] = ct[i]-at[i];  
		wt[i] = tat[i]-bt[i];	
	}

	//PRINT
	printf("Packet\t Arrival Time\t Burst Time\t Completion Time\t Turn Around Time\t Wait Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}