#include<stdio.h>
int n,bt[10],at[10],ct[10],wt[10],tat[10],npr[10],pr[10];
int clock = 0;
void proc(int k)
{
	ct[k]=clock+bt[k];
	wt[k]=ct[k]-bt[k]-at[k];
	tat[k]=ct[k]-at[k];
	clock = clock + bt[k];
}
void main()
{
	int i,j,min,pos;
	printf("Enter the number of processors:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the details of process %d\n",i );
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("priority level:");
		scanf("%d",&pr[i]);
		wt[i]=0;
		npr[i]=pr[i];
		at[i]=i-1;
	}
	
	npr[1]=999;	
	proc(1);

	for(j=1;j<=n;j++)
	{
	min=99;
	for(i=1;i<=n;i++)
	{
		if(min>npr[i])
		{
			min=npr[i];
			  pos = i;
		}
	}

	if(at[pos]>clock)
		clock=clock+at[pos];

npr[pos]=999;	
	proc(pos);
}
	

	printf("Final table:\n");
printf("Process NO   Burst Time   Arrival Time Priority NO  Completion Time   Waiting time   Turn around Time\n");
for(i=1;i<=n;i++)
{
	printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",i,bt[i],at[i],pr[i],ct[i],wt[i],tat[i]);
}


}
