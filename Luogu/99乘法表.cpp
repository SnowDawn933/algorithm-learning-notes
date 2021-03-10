#include<stdio.h>
int main()
{
	int i,j;
	for (i=1;i<=9;i=i+1)
	{
		for (j=1;j<=i;j=j+1)
			printf("%4d*%d=%d",i,j,i*j);
		printf("\n");
	}
	return 0;
}
	
