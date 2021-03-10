#include<stdio.h>
int main()
{
	int m,s,t,a;
	scanf("%d %d %d",&m,&t,&s);
	if(t==0)
		printf("0");
	else
	{
		a=s/t;//吃完整了几个？ 
		if(a>m)
			printf("0");
		else
		{
			if(s%t==0)//如果正好吃完整 
				m=m-a;//剩下几个 
			else//如果没正好吃完整 
				{
					m=m-1-a;//再减去一个 
				}
			printf("%d",m);
		}
	}
	
	return 0;
}
	
	
