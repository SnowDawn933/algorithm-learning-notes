#include<stdio.h>
int main(void)
{
	int a,b,c,e,bigger,smaller;
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
	printf("%d %d %d",a,b,c);
	return 0;
}
