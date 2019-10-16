#include<stdio.h>
#include<math.h>

int i, n, a[100], k = 1, find,bin3;
int DecimalToBinary(int n)
{
	while(n>0)
   	{
   	bin3 += n%2 * k;
    n = n/2;
   	k = k*10;
	}
	printf("%d\n", bin3);
return 1;
}
  
// Driver program to test above function 
int main() 
{  
DecimalToBinary(10);
DecimalToBinary(11);
DecimalToBinary(12);
DecimalToBinary(13);
DecimalToBinary(14);
DecimalToBinary(15);

return 0;  
} 
	
	
	


