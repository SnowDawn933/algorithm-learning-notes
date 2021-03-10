#include<stdio.h>
int main()
{
	float a;
	int b,c;
	scanf("%f",&a);
	c=a*10;
	b=c%10;
	c=c/10;
	printf("%d.",b);
	while(c>0)
	{
	 	b=c%10;
		c=c/10;
		printf("%d",b);
	}
	return 0;
	
}
