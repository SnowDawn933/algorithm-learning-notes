#include<stdio.h>
int main(void)
{
	int a,b;
	scanf("%d",&a);
	for(b=1;a!=1;b++)
	{
		a/=2;
	}
	printf("%d",b);
	return 0;
}
