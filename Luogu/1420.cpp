#include<stdio.h>
int main(void)
{
	int a,b,c,cnt=1,max=1;
	scanf("%d",&a);
	scanf("%d",&c);
	for (int i=1;i<a;i++)
	{
		scanf("%d",&b);
		if(b==c+1)
		{
			cnt++;
			if(cnt>max)
				max=cnt;
		}
		else
			cnt=1;
		c=b;
	}
	printf("%d",max);
	return 0;
}
