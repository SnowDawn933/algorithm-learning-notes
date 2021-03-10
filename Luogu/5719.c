#include<stdio.h>
int main(void)
{
	int a,b,i,j=0,k=0,sum_a=0,sum_b=0;
	double c,d;
	scanf("%d %d",&a,&b);
	for(i=1;i<=a;i++)
		{
			if(i%b==0)
			{
				sum_a+=i;
				j++;
			}
			else
			{
				sum_b+=i;
				k++;
		    }
		 }
	c=sum_a*1.0/j;//右边进行完计算后在赋值给c，所以要先转变数字类型，不然会被截断 
	d=sum_b*1.0/k;
	printf("%.1lf %.1lf",c,d);
	return 0; 
 } 
