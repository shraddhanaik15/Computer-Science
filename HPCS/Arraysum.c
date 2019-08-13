#include<stdio.h>
#include<mpi.h>
int main(int argc, char *argv[])
{
	int rank, size, i,n, a[100], b[100], c[100], sum = 0, sum1=0, sum2=0, n1, n2, sum11, sum22;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;

	if(rank == 0)
	{
		printf("Enter no of elements in the array\n");
		scanf("%d", &n);
		printf("Enter the array elements\n");
		for(i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
		}
		MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(&a[0], n/2, MPI_INT, 1, 1, MPI_COMM_WORLD);


		if(n%2==0)
		{
		
		MPI_Send(&n, 1, MPI_INT, 2, 2, MPI_COMM_WORLD);
		MPI_Send(&a[n/2], n/2, MPI_INT, 2, 3, MPI_COMM_WORLD);

		}
		else
		{

		MPI_Send(&n, 1, MPI_INT, 2, 2, MPI_COMM_WORLD);
		MPI_Send(&a[n/2], n/2+1, MPI_INT, 2, 3, MPI_COMM_WORLD);
		}
		

		MPI_Recv(&sum11, 1, MPI_INT, 1, 4, MPI_COMM_WORLD, &status);
		MPI_Recv(&sum22, 1, MPI_INT, 2, 5, MPI_COMM_WORLD, &status);
		sum=sum11+sum22;
		printf("\nSum is %d\n", sum);
	}
	else if(rank == 1)
	{
		MPI_Recv(&n1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&b[0], n1/2, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		for(i=0;i<n1/2; i++)
		{
			printf("array b is %d\n", b[i]);
			sum1=sum1+b[i];
		}
		printf("sum1 is %d\n", sum1);
		MPI_Send(&sum1, 1, MPI_INT, 0, 4, MPI_COMM_WORLD);
	}
	else if(rank == 2)
	{
		MPI_Recv(&n2, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
		if(n2 % 2 ==0)
		{
		MPI_Recv(&c[0], n2/2, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
		for(i=0;i<n2/2; i++)
		{
			printf("array c is %d\n", c[i]);
			sum2=sum2+c[i];
		}
		printf("sum2 is %d\n", sum2);
		MPI_Send(&sum2, 1, MPI_INT, 0, 5, MPI_COMM_WORLD);

		}
		else
		{
		MPI_Recv(&c[0], n2/2+1, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
		for(i=0;i<n2/2+1; i++)
		{
			printf("array c is %d\n", c[i]);
			sum2=sum2+c[i];
		}
		printf("sum2 is %d\n", sum2);
		MPI_Send(&sum2, 1, MPI_INT, 0, 5, MPI_COMM_WORLD);
	  }
	}
	else
	{
		printf("No processes are available\n");
	}
	MPI_Finalize();
	return 0;
}


