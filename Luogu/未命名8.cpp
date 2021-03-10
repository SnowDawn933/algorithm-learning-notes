#include<stdio.h>
int main(void)
{
	int a,b,i,j;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
		{
			j=1;
			b=1;
			for(j=1;j<=(a-i);j++)
				{
					printf(" ");
				}
			for(b=1;b<=i;b++)
				printf("*");
				printf("\n");
		}
	return 0;
}
