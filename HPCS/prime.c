#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
	int size,rank,i,j,a[100]={0} ;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if (rank==0)
	{
		for(i=2;i<=50;i++)
		{
			for(j=2;j<i;j++)
			{
				if(i%j==0)
				{
					a[i] = 1;
				}
			}
				if(a[i] == 0)
				{
					printf("%d ", i);
				}
		}
	}
		else if (rank == 1)
		{
		for(i=51;i<=100;i++)
		{
			for(j=2;j<i;j++)
			{
				if(i%j==0)
				{
					a[i] = 1;
				}
			}
				if(a[i] == 0)
				{
					printf("%d ", i);
				} 
		}
		}
	MPI_Finalize();
	return 1;
}
