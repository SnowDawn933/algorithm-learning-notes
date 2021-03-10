#include<stdio.h>
int main(void)
{
	int a,b;
	double c=0.0,d=1.0,e;
	scanf("%d",&a);
	if(a==0)
		printf("0.00\n");
	else
		if(a==1)
			printf("1");
	else
	{
		for(b=2;b<=a;b++)
		{
			e=d;
			d+=c;
			c=e;
		}
		printf("%.2f",d);
	}
	return 0;
	
}
