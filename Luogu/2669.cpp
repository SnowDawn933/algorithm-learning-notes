#include<stdio.h>
int main(void)
{
	int a,b,sum=0;
	scanf("%d",&a);//输入发工资的天数 
	for(int i=1;;i++)//每阶段几个 
	{
		for(int j=1;j<=i;j++)//一个个加 
		{
			sum+=i;
			b+=1;//每计算一个总数加一 
			if(b==a)
				break;//到了就停止跳出 
		}
		if(b==a)
			break;//跳出 
	
	}
	printf("%d",sum);

}
