#include<stdio.h>
int main(void)
{
	int a,b,c,d,cnt=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		c=i;
		while(c!=0)
		{
			d=c%10;
			c/=10;
			if(d==b)
			{
				cnt++;
				
			}
			
		}
				
				 
		
	
	}
	printf("%d",cnt);
	return 0;
}
