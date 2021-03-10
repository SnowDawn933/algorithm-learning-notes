#include<stdio.h>
int main(void)
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<a;i++)
	{
		if(a%i==0)
		{
			printf("%d",a/i);
			break;
		}
	}
	return 0;
	
}
