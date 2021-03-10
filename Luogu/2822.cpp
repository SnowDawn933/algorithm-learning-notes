#include <stdio.h>
#define ll long long
ll t, n, m, k, res[2010][2010], sum[2010][2010]; //记录每一个结果的数组和前缀和数组
int main(void)
{
    scanf("%lld%lld", &t, &k);
    for (int i = 0; i <= 2000; i++) //可以把组合数的值看成是杨辉三角的每一个数
    {
        res[i][0] = 1; //对杨辉三角的边界进行初始化
        res[i][i] = 1;
    }
    for (int i = 1; i <= 2000; i++)
    {
        for (int j = 1; j < i; j++) //求组合数的递推公式
        {
            res[i][j] = (res[i - 1][j - 1] + res[i - 1][j]) % k; //提前进行取模，防止超过了long long的范围，而且可以省去接下来对k取模的步骤
        }
    }
    for (int i = 1; i <= 2000; i++) //遍历的同时求前缀和
    {
        for (int j = 1; j <= 2000; j++)
        {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]; //前缀和的公式，使用前缀和可以在每次请求时直接给出答案而省去了遍历的一层复杂度
            if (res[i][j] == 0 && j <= i)                                  //如果当前符合的话就加上本身
            {
                sum[i][j]++;
            }
        }
    }
    for (int i = 1; i <= t; i++) //输出每次请求的结果，因为使用了前缀和，所以十分便利
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", sum[n][m]);
    }
    return 0;
}