#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int a=1,b=0;
	while (b<=100)
	{
		system("cls");
		a=1;    //循环嵌套的关键。每一个外循环都要有重新的起点
				//  来 开启内循环 
		while (a<=b)
		{
				
			printf(" ");
			a=a+1;
		}
		
		printf("H");
		Sleep(1000);
		b=b+1;
	}
	return 0;
} 
