#include<stdio.h>
int main(void)
{
	int i;
	float d=2.0,a,c=0.98,b=0.0;
	scanf("%f",&a);
	for(i=0;b<a;i++)
	{
		b+=d;
		d*=c;	
	}
	printf("%d",i);
	return 0;
}
