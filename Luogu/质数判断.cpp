#include<stdio.h>
int main ()
{
	int a,b,c;
	while(scanf("%d",&b)!=EOF)
	{
		c=0;
		for (a=2;a<=b-1;a++)
				if (b%a==0)
				{
					c++;
					break;
				}
		if (c==0)
			printf("质数\n"); 
		else
			printf("合数\n");
		}
	return 0;
} 
