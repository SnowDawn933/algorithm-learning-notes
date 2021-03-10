#include<stdio.h>
int main(void)
{
	int a,b,c,i,j;
	scanf("%d",&b);
	for(i=1;i<=10;i++)
		{
			scanf("%d",&a);
			if(a<(b+30))
				c++;
		}
		
	printf("%d",c);
	return 0;
	
	
 } 
