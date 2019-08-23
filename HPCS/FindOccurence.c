//Week - 4, Program - 2

#include<stdio.h>
#include<mpi.h>
#include<time.h>

int main(int argc, char *argv[])
{
	int rank, size,a[100][100],b[100],r,d[100],i,j,val,c,counter = 0,fullcount;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0)
	{
		printf("Enter no of rows\n");
		scanf("%d", &r);
		printf("Enter no of columns\n");
		scanf("%d", &c);
		printf("Enter the matrix\n");
		for(i=0;i<r*c;i++)
		{
				scanf("%d", &a[i][j]);
				b[i]=a[i][j];
		}

		// for(i=0;i<r*c;i++)
		// {
		// 	printf("%d\t",b[i]);
		// }
		
		printf("Enter the value to be searched in the matrix\n");
		scanf("%d", &val);
	}

	MPI_Bcast(&r,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&c,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&val,1,MPI_INT,0,MPI_COMM_WORLD);

	if(r*c%2==0)
	{
	MPI_Scatter(&b[0], (r*c)/size, MPI_INT, &d[0],(r*c)/size, MPI_INT, 0, MPI_COMM_WORLD);
	}
	else
	{
	MPI_Scatter(&b[0], ((r*c)/size)+1, MPI_INT, &d[0],((r*c)/size)+1, MPI_INT, 0, MPI_COMM_WORLD);	
	}
	//for(i=0;i<r;i++)
	//printf("After scatter value is %d in process %d\n",d[i],rank);

	if(r*c%2==0)
	{
		for(i=0;i<(r*c)/size;i++)
	{
		if(d[i]==val)
		{
			counter++;
			//printf("counter 1 %d\n", counter);
		}
	}
	}
	else
	{
		for(i=0;i<=((r*c)/size);i++)
		{
		if(d[i]==val)
		{
			counter++;
			//printf("counter 2 %d in process %d\n", counter, rank);
		}
	}
	}
	MPI_Reduce(&counter,&fullcount,1,MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
	printf("Total Count of %d is %d in process %d\n",val,fullcount,rank);
	MPI_Finalize();
}
