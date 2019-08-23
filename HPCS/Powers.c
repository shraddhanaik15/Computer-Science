//Week 3 - Program - 4
#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;
	int m,a[100],i,b[100],result[100],newresult[100], FinalResult;
	if(rank == 0)
	{
		printf("Enter no of elements\n");
		scanf("%d", &m);
		printf("Enter the elements\n");
		for(i=0;i<m*size;i++)
			scanf("%d", &a[i]);

	}
	MPI_Bcast(&m,1,MPI_INT, 0,MPI_COMM_WORLD);
	MPI_Scatter(&a[0], m, MPI_INT, &b[0],m, MPI_INT, 0, MPI_COMM_WORLD);
	
	for(i=0;i<m;i++)
	{
		//printf("Value is %d in process %d\n", b[i],rank);
		result[i] = pow(b[i],rank+2);
		//printf("Result is %d in process %d.\n", result[i],rank);
	}

	//Gather 

	MPI_Gather(&result[0],m,MPI_INT,&newresult[0],m,MPI_INT, 0, MPI_COMM_WORLD);
	if(rank == 0)
	{
		for(i=0;i<m*size;i++)
		{
			printf("Result is %d in process %d\n", newresult[i],rank);
		}
		
	}

	MPI_Finalize();
	return 0;
}