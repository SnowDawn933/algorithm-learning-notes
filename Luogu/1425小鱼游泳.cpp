#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if (d>=b)
	{
		f=d-b;
		e=c-a;
	}
	else
	{
		f=d-b+60;
		e=c-a-1;
	}
	printf("%d %d",e,f);
	return 0;

}
