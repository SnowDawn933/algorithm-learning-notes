#include<stdio.h>
int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t;i++)
	{
		int a[2005],n,sum = 0;
		scanf("%d", &n);
		for (int j = 1; j <= n;j++)
		{
			scanf("%d", &a[j]);
			sum += a[j];
		}
		if (sum % 2 ==1)
			printf("YES");
		else
		{
			printf("NO");
		}
		
	}
	return 0;
}