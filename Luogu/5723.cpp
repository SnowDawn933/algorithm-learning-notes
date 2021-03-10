#include<stdio.h>
int main(void)
{
	int sum=0,num=0,c,l;
	scanf("%d",&l);
	for (int i=2;sum<l;i++)
	{
		c=0;//每次判断完c要归零 
		for(int j=2;j<=i-1;j++)//判断是为质数 
		{
			if(i%j==0)
			{
				c = 1;
				break;
			}
		}
		if(c==0)
		{
			sum+=i;
			if(sum>l)
			break;
			printf("%d\n",i);
				num+=1;
		}
		
	}
	printf("%d",num);
	return 0;
 } 
