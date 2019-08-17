#include<stdio.h>
#include<mpi.h>
#include<string.h>
void main(int argc, char *argv[])
{
	char a[100],b[100],c[100];
	int i, n, size, rank;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank==0)
	{
		printf("Enter the string\n");
		scanf("%s",a);
		n=strlen(a);
		n=n+1;
		
		MPI_Ssend(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Ssend(&a[0], n, MPI_CHAR, 1, 1, MPI_COMM_WORLD);

		MPI_Recv(&c[0],n,MPI_CHAR, 1,2,MPI_COMM_WORLD, &status);
		printf("String --- %s received by process %d",c, rank);
	}
	else if(rank ==1)
	{
		MPI_Recv(&n,1,MPI_INT, 0,0,MPI_COMM_WORLD, &status);
		MPI_Recv(&b[0],n,MPI_CHAR, 0,1,MPI_COMM_WORLD, &status);
		for(i=0;i<n;i++)
		{
			if(b[i]>='a' && b[i]<='z' )
			{
				b[i]=b[i]-32;
			}
			else if(b[i]>='A' && b[i]<='Z')
			{
				b[i]=b[i]+32;
			}
		}
		MPI_Ssend(&b[0], n, MPI_CHAR, 0, 2, MPI_COMM_WORLD);
	}
		MPI_Finalize();
}
