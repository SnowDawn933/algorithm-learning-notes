#include<stdio.h>
int main(void)
{
	int a,b,c;
	scanf("%d",&a);
	if(a<0)
		{
			printf("-");
			a=-a;
		}
	else
		if(a==0)
			printf("0");
	while (a%10==0)
		a/=10;
	for(int i=1;a>0;i++)
	{
		c=b; 
		b=a%10;
		a/=10;
			printf("%d",b);
	 } 
	 return 0;
}
