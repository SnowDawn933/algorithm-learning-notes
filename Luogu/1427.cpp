#include<stdio.h>
int main(void)
{
	int a[110];
	int i=1;
	while(scanf("%d",&a[i])==1 && a[i]!=0)
	{
		i++;
	}
	for(i-=1;i>=1;i--)
	{
		printf("%d ",a[i]);
		
	 } 
	 return 0;
 } 
