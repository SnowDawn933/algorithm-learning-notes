#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=1,b=1,c; //a是行数 b是每行输出数字 C控制每行数字个数 
	while (a<=5)   
		{
			c=1;	
			while (c<=a) //c与a相同时换行  
					{
						printf("%d",a);
					//	b=b+1;
						c=c+1;
					}
			printf("\n");
			a=a+1;
		}
	return 0;
} 
