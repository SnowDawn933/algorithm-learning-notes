#include<stdio.h>
int main(void)
{
	int k,max=0,min=1000,a,b,i;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&b);
		if(b<min)
			min=b;
		if(b>max)
			max=b;
	}
	k=max-min;
	printf("%d",k);
	return 0;
}
