#include<stdio.h>
int main()
{
	int a,b=0;//此时以一共有b斜行  
	scanf("%d",&a);
	while(b<a)//判断最终在第几斜行 
		{
			a=a-b;
			b++;
		}//循环终止时b为所输入的数的前一斜行 
	printf("%d/%d",a,b-a+1);//所以行数要+1 
	return 0;
 		 		 
	
	
} 
