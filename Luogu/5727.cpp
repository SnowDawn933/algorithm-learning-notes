#include<stdio.h>
int main(void)
{
	int a[1100],i=0;
	scanf("%d",&a[i]);//输入一个数，储存在下标为零 
	while(a[i]!=1)//当前数是否为1 
	{
		if(a[i]%2!=0)
			a[i+1]=a[i]*3+1;
		else
			a[i+1]=a[i]/2;
		i++;
	}
	for(;i>=0;i--)
		printf("%d ",a[i]);//从最大的i按顺序输出到020
		 
	return 0;
		
}
