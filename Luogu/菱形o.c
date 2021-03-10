#include<stdio.h>
int main(void)
{
	int a,b,c,i,j,k;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=(a-i);j++)
		{
			printf(" ");
		}
		printf("o");
		for(k=1;k<=2*(i-1);k++)
			printf(" ");
		printf("o\n");
	}
	for(i=a;i>=1;i--)
	{
		for(j=(a-i);j>=1;j--)
		{
			printf(" ");
		}
		printf("o");
		for(k=2*(i-1);k>=1;k--)
			printf(" ");
		printf("o\n");
	}
	return 0;
	
}
