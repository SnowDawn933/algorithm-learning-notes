#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		d=b;
		b=a;
		a=d;
	}
	if(a>c)
	{	
		d=c;
		c=a;
		a=d;
	}
	if(b>c)
	{
		d=c;
		c=b;
		b=d;
	}
	printf("%d %d %d",a,b,c); 
	return 0;
		
		
		
 } 
