#include <stdio.h>
#include <math.h>
int cost = 0, c = 0;
int i, k, j;
int arr[100];
int increment(int[],int);

void main()
{
	printf("enter the 'k' of k-bit binary counter\n");
	scanf("%d",&k);	

    // code to initialize the array
	for (i = 0; i < k; i++)
	{
		arr[i] = 0;
	}

 //    // code to print initial value of counter '00...0'
 //    for(i = k-1; i >= 0;i--)
	// {
 //        printf("%d",arr[i]);
 //    }

    printf("\n");
	
    //loop to increment counter value from 0 to (2 power k)-1 
    for (i = 1; i <=16 ; i++)
	{
        increment(arr,k);		
	}
		
    printf("\ncost : %d \n",cost);
	
}

//increment function 

int increment(int arr[],int k)
{

    int j = 0;

     // code to increment the value of binary counter

   while((j<k) && (arr[j] == 1))
	{
     	arr[j] = 0;
     	j++;
        cost++;
    }
    
     if(j < k)
	 {
     	arr[j] = 1;
        cost++;
     }

    // code to print binary value of counter

    for( i = k-1; i >= 0;i--)
	{
        printf("%d ",arr[i]);
    }
  
printf("\n");
return 0;
}

