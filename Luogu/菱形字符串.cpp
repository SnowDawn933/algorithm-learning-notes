
#include<stdio.h>

int main()
{
	int a,b,c;
	for (a=0;a<=4;a++)//控制换行 
		{
			for (b=0;b<=4-a; b++ )//控制每行有几个空格 
				printf(" ");
			for (c=1;c<=(2*a)+1;c++)//控制在每行的中间打* 
				printf("*");
			printf("\n");
		}
	for (a=5;a>=0;a--){
		for (b=0;b<=4-a; b++ )//控制每行有几个空格 
				printf(" ");
			for (c=1;c<=(2*a)+1;c++)//控制在每行的中间打* 
				printf("*");
			printf("\n");
	}
	
	return 0;
} 
