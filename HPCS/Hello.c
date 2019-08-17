#include<stdio.h>
#include<mpi.h>
void main(int argc,char *argv[])
{
int rank,size;
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
if(rank % 2 == 0)
{
	printf("hello world\n");
	printf("%d\n", rank );
}
else if(rank %2!= 0)
{
	printf("no hello world");
	printf("%d",size );
}
else
{
	printf("no");
}

MPI_Finalize();
}
