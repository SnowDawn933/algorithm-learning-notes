#include<stdio.h>
int main(void)
{
	int k,b=1;
	double sum;
	scanf("%d",&k);
	for(sum=0.0;;b++)
	{
		sum+=1.0/b;
		if(sum>k)
			break;//不用break的话会多一个 
	}
	printf("%d",b);
	return 0;
}
