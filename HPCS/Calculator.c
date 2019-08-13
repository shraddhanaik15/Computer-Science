#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[])
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Status status;


	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int n1, n2;



	if(rank ==0)
	{
		printf("Enter 2 numbers: \n");
		scanf("%d %d", &n1, &n2);


		MPI_Send(&n1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(&n2, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);


		MPI_Send(&n1, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
		MPI_Send(&n2, 1, MPI_INT, 2, 1, MPI_COMM_WORLD);



		MPI_Send(&n1, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
		MPI_Send(&n2, 1, MPI_INT, 3, 1, MPI_COMM_WORLD);


		MPI_Send(&n1, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
		MPI_Send(&n2, 1, MPI_INT, 4, 1, MPI_COMM_WORLD);


	}

	else if(rank ==1)
	{
		MPI_Recv(&n1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&n2, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		printf("\nSum is %d\n", n1+n2);
	}
	else if(rank ==2)

	{
		MPI_Recv(&n1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&n2, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		printf("\nSubtraction is %d\n", n1-n2);
	}
	else if(rank ==3)
	{
		MPI_Recv(&n1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&n2, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		printf("\nMultiplication is %d\n", n1*n2);

	}
	else if(rank ==4)
	{
		MPI_Recv(&n1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&n2, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		printf("\nDivision is %d\n", n1/n2);
	}
	else
	{
		printf("\nNo processes available\n");
	}
return 0;
}
