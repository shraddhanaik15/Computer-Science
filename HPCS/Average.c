#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
	int rank, size,n,i,m,a[100],sum=0,average,j;
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0)
	{
		printf("Enter no of Processes N\n");
		scanf("%d", &n);
		printf("Enter the value M\n");
		scanf("%d", &m);
		printf("Enter the M elements\n");
		for(i=0;i<n*m;i++)
			scanf("%d", &a[i]);
	}
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&a, m ,MPI_INT,0,MPI_COMM_WORLD);

		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		printf("Process %d has values %d\n", rank, a[j]);
	}
	
	// for(i=0;i<n*m;i++)
	// {
	// 		sum = sum+a[j];
	// 	}
	// }
	// printf("In process %d, Average is %d\n", rank,average);



	MPI_Finalize();

}
