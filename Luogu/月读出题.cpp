#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,sum=0,min,max;
	scanf("%d",&b);
	scanf("%d",&e);
	for (a=1;a<b;a++)
	{
		scanf("%d",&c);
		sum=sum+e;
			if (c>=e)
				d=c;
			if (c<=e)
				f=c;
			e=c;	
		
			
	}

	max=d;
	min=f;
	printf("%d\n",max);
	printf("%d\n",min);
	printf("%d\n",sum);
	return 0;
		
	
} 
