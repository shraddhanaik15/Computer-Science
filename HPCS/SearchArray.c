#include<stdio.h>
#include<mpi.h>
void main(int argc, char *argv[])
{
	int a[100], n, i, b[100], value,n1,k, flag = 0;
	int rank, size;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the no of elements in the array\n");
		scanf("%d", &n);
		printf("Enter the array\n");
		for(i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
		}
		printf("Enter the value to be searched\n");
		scanf("%d", &value);

		for(i=0;i<n/2;i++)
		{
			if(a[i]==value)
			{
				printf("Element found at position %d in process %d\n", i,rank);
				flag = 1;
				break;
			}
		}

		//Sendind 2nd half of array elements to Process 1
		if(flag == 0)
		{
		MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		if(n%2==0)
		{
		MPI_Send(&a[n/2], n/2, MPI_INT, 1, 1, MPI_COMM_WORLD);
		MPI_Send(&value, 1, MPI_INT, 1, 2, MPI_COMM_WORLD);
		}
		else
		{
		MPI_Send(&a[n/2], n/2+1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		MPI_Send(&value, 1, MPI_INT, 1, 2, MPI_COMM_WORLD);
		}
	
		MPI_Recv(&k, 1, MPI_INT, 1, 3, MPI_COMM_WORLD, &status);
		printf("Element recieved in process %d found at position %d\n",rank, k);
		}
		}

	else if(rank == 1)
	{
		MPI_Recv(&n1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		//even no of elements in the array
		if(n1%2==0)
		{
			MPI_Recv(&b[n1/2], n1/2, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
			MPI_Recv(&value, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
			for(i=n1/2;i<=n1;i++)
			{
			if(b[i]==value)
			{
				printf("Element found in process %d at location %d.\n", rank, i);
				break;
			}
			}
		}
		//odd no of elements in the array
		else
		{
			MPI_Recv(&b[n1/2], n1/2+1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
			MPI_Recv(&value, 1, MPI_INT, 0, 2 , MPI_COMM_WORLD, &status);
			for(i=n1/2;i<=n;i++)
			{
			if(b[i]==value)
			{
				printf("Element found in process %d at location %d.\n", rank, i);
				break;
			}
			}
		}
		MPI_Send(&i, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);	
	}
	else
	{
		printf("\nProcesses are not available\n");
	}
	MPI_Finalize();
}
