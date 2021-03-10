#include <cstdio>
int a[1010][1010];
int cnt[1010][1010];
int main(void)
{
    int n, sum, max = -1; //有可能出现只有一个格子，即有容身之所，但是没有可以弹的东西
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                int x = 0;
                for (int k = 1; k <= n; k++)
                {
                    x += a[i][k] + a[k][j];
                }
                if (x > max)
                    max = x;
            }
        }
    }
    if (max != -1)
        printf("%d", max);
    else
    {
        printf("Bad Game!");
    }
    return 0;
}