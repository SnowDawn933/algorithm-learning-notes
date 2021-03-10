#include<stdio.h>
int fact(int n)
{
	int res=1;
	for(int i=1;i<=n;i++)
		res*=i;
	return res;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int res=fact(n);
	printf("%d\n",res);
	return 0;
	
}
