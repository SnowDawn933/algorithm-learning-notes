#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int a=1,b=5,c=9;
	system("color 0a" );
	printf("2:00");
	Sleep(1000);
	while (a>=0)
	{
	
		if( c!=-1)
			{
		 		system("cls");
				printf("%d:%d%d",a,b,c);
				Sleep(1000);
				c=c-1;
			}
		else
			{	c=9;
				b=b-1;
			}
    
	if (b==0 && c==-1)
			{
				a=a-1;
				b=5;
				c=9;
			}
	}
			
	
	return 0; 
}
