#include<stdio.h>
int a[3010];
int main(void)
{
    int n, m,sum;
    scanf("%d%d", &n, &m);
    int max =100*m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 1; j <= n - m + 1;j++)
    {
        sum = 0;
        for (int k = j; k <=j+ m-1;k++)
        {
            sum += a[k];
        }
        if (sum < max)
            max = sum;
    }
    printf("%d", max);
    return 0;
}