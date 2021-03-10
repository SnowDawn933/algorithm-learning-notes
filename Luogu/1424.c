#include<stdio.h>
int main(void)
{
	int a,b,i,sum=0;
	scanf("%d %d",&a,&b);
	for (i=1;i<=b;i++)
	{
		if(a!=6&&a!=7)
		{
			sum+=250;
		}
		
		if(a==7)
			a=0;
		a++;
		 
			
	}
	printf("%d",sum);
	return 0;
	
}
