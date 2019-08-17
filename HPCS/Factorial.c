#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[])
{
	int rank, size,n,i,a[100],b[100],j;
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int factorial = 1;
	if(rank == 0)
	{
		printf("Enter no of values\n");
		scanf("%d", &n);
		printf("Enter the array\n");
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);
	}
	MPI_Scatter(&a,1,MPI_INT,&b,1,MPI_INT,0,MPI_COMM_WORLD);
	for(i=1;i<=b[0];i++)
	{
		factorial = factorial * i;
	}
	printf("Factorial is %d in process %d\n",factorial, rank);
	MPI_Finalize();
	return 0;
}
