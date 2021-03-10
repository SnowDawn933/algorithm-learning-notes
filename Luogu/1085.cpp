#include<stdio.h>
int main()
{
	int a,b,c=1,d,max=0,e=0;
	while(c<=7)
	{
		scanf("%d %d",&a,&b);
		c++;
		d=a+b;
		if(d>max&&d>8)
		{
			max=d;
			e=c-1;
		}
	}
	printf("%d",e);
	return 0;
	
 } 
