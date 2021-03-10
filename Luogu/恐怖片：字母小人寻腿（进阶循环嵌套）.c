 #include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int a,b;
	a=0;
	while(a<=50)
	{	
		system("cls");
		b=99;
		while(b>=a)
			{
				printf(" ");
				b=b-1;
			}
		printf(" O\n");
		b=99;
		while(b>=a)
			{
				printf(" ");
				b=b-1;
			}
		printf("<H>\n");
		b=1;
		while(b<=a)
			{
				printf(" ");
				b=b+1;
			}
		printf("I I");
		b=1;
		while(b<=a)
			{
				printf(" ");
				b=b+1;
			}
		Sleep (100);
		a=a+1;
	}
	system("pause")	;
	
	return 0;
} 
