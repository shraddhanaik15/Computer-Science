#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
	int rank, size,n,i,m,a[100],sum=0,average,j, rootaverage;
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the value M\n");
		scanf("%d", &m);
		printf("Enter the M elements\n");
		for(i=0;i<m*size;i++)
			scanf("%d", &a[i]);
	}
	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&a, m/size ,MPI_INT,0,MPI_COMM_WORLD);

		for(i=0;i<m/size;i++)
	{
		sum = sum + a[i];
		average = (float)sum/m;
	}
	printf("Process %d has sum %d\n", rank,sum);
	printf("Process %d has average %d\n", rank,average);

	MPI_Reduce(&average, &rootaverage,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank == 0)
	{
		printf("Total average is %fin process %d\n",(float)rootaverage/m ,rank);
	}
	MPI_Finalize();
}

