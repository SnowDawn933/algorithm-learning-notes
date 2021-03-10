#include<stdio.h>
int main(void)
{
	int a,b,c,e,i;
	scanf("%d %d %d",&a,&b,&c);
	if(a<b)
	{
		e=a;
		a=b;
		b=e;
	}
	if(a<c)
	{
		e=a;
		a=c;
		c=e;
	}
	if(b<c)
	{
		e=b;
		b=c;
		c=e;
	}
	for(i=1;i<c;i++)
		{
			if(a%i==0&&c%i==0)
				{
					a=a/i;
					c=c/i;
					i=1;
				}
		}
	printf("%d/%d",c,a);
	 
 } 

