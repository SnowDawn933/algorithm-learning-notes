#include<stdio.h>
int main(void)
{
	int a,b,max=0,min=10,sum=0;
	float p;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		if(b<min)
			min=b;
		if(b>max)
			max=b;
		sum+=b;	
	}
	p=(sum-max-min)*1.0/(a-2);
	printf("%.2f",p);
	return 0;
}
