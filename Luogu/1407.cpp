#include<stdio.h>
int main(void)
{
	int l,m,cnt=0;
	int beg,end;
	int a[10010];
	scanf("%d%d",&l,&m);
	for(int i=0;i<=l;i++)//从零开始标记，因为两头都有 
	{
		a[i]=1;
	}
	for(int j=1;j<=m;j++)
	{
		scanf("%d%d",&beg,&end);
		for(int i=beg;i<=end;i++)
		{
			if(a[i]==1)
			{
				a[i]=0;
				cnt++;
			}
		}
	}
	printf("%d",l-cnt+1);
	return 0;
}
