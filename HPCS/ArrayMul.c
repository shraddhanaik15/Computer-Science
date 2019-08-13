#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[])
{
	int rank, size,n,i,m,a1[100],a2[100],b1[100],b2[100],c[100],d[100],m1;
	
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter the value M\n");
		scanf("%d",&m);
		printf("Enter the M elements\n");
		for(i=0;i<m;i++)
		scanf("%d", &a1[i]);
	printf("Enter the M elements\n");
		for(i=0;i<m;i++)
		scanf("%d", &a2[i]);

		printf("Size is %d\n", size);
		printf("m/Size is %d\n", (m/size));	

	}
	
	MPI_Scatter(&m,1,MPI_INT,&m1,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(&a1,(m1/size),MPI_INT,&b1,(m1/size),MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(&a2,(m1/size),MPI_INT,&b2,(m1/size),MPI_INT,0,MPI_COMM_WORLD);

	for(i=0;i<m1/size;i++)
		c[i]=b1[i]*b2[i];

	MPI_Gather(&c,m1/size,MPI_INT,&d,m1/size,MPI_INT,0,MPI_COMM_WORLD);
if(rank == 0)
	{
		for(i=0;i<m1;i++)
		printf("%d ", d[i]);
	}
	

	MPI_Finalize();
	return 0;

}
