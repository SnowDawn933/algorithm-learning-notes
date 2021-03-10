#include<stdio.h>
int main(void)
{
	int n;
	unsigned long long sum=0,num;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		num=1;
		for(int j=1;j<=i;j++)
		{
			num*=j;
		}
		sum+=num;
	}
	printf("%llu",sum);
	return 0;
}
