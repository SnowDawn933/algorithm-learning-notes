#include<stdio.h>
int main(void)
{
    int m, n , b;
    int a[10];
    scanf("%d%d", &m, &n);
    for (int j = 0; j <= 9;j++)
    {
        a[j] = 0;
    }
    for (int i = m; i <= n; i++)
    {
    	b=i;
        while (b> 0)
        {
            a[b % 10]++;
            b /= 10;
        }
    }
    for (int k = 0; k <= 9;k++)
    {
        printf("%d ", a[k]);
    }
    return 0;
}
