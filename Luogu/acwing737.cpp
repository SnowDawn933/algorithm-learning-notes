#include<stdio.h>
int main(void)
{
	int a[15];//0 1 2 3 4 ....下标从零开始，直到n-1
				//数组开的时候要大一点
	for(int i=0;i<10;i++)
		{	
			scanf("%d",&a[i]);
		 }
	for(int i=0;i<10;i++) 
		{
			if(a[i]<=0)
				a[i]=1;
		}
	for(int i=0;i<10;i++)
	{
		printf("X[%d] = %d\n",i,a[i]);
	 } 
	 return 0;
	 
	 
	
}
