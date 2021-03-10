#include<stdio.h>
int main(void)
{
	int a,sum=0,remind=0,cun;
	for(int i=1;i<=12;i++)
	{
		scanf("%d",&a);
		remind-=a-300;
		if(remind<0)
		{
			printf("-%d",i);
			return 0; 
		}
		cun=remind/100;
		remind%=100;
		sum+=cun;
	}
	printf("%d",sum*120+remind);
	return 0;
}
