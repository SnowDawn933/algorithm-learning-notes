#include<stdio.h>//k的范围无上限，将其放入内循环无法结束，所以将其放入外循环 
int main(void)
{
	int n,x,k,sum=0;
	scanf("%d",&n);
	for(k=1;;k++)
	{
		for(x=100;x>0;x--)
		{
			sum=(7*x+21*k)*52;
			if(sum==n)
			{
				printf("%d\n",x);
				printf("%d\n",k);
				return 0;
			}
		}
	}
}
