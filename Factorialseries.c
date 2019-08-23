//Week - 4, Program - 1

#include<stdio.h>
#include<mpi.h>
#include<time.h>


int main(int argc, char *argv[])
{
	int rank, size,fact=1,newsize[100],factseries[100],newfact[100],a[100],i;
	double t1,t2,t3,t4;

	t3=MPI_Wtime();
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;

			if(rank == 0)
			{
				for(i=1;i<=size;i++)
			{
				fact = fact * i;
				printf("Fact of %d is %d in process %d\n", i, fact,rank);
				a[i]=fact;
			}	
			}
			
	MPI_Scatter(&a[1], 1, MPI_INT, &newfact[0],1, MPI_INT, 0, MPI_COMM_WORLD);
	//printf("Fact is %d in process %d after scattering\n", newfact[0],rank);
	
	MPI_Scan(&newfact[0],&factseries[0],1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);

	t1=MPI_Wtime();
	printf("Sum of the series of factorial is %d in process %d\n", factseries[0],rank);
	t2 = MPI_Wtime();
	t4=MPI_Wtime();
	
	printf("Time taken by to sum is %f in process %d\n",t2-t1,rank);
	if(rank == 0)
	printf("Time taken by entire program to execute is %f\n",t4-t3);
	

	MPI_Finalize();

}
		