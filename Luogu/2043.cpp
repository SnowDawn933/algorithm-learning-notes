#include <stdio.h>
int cnt[10001]; //对分解得来的质因数进行计数
int main(void)
{
    int n, a;
    scanf("%d", &n);
    for (int j = 2; j <= n; j++) //阶乘只需分解每一位就可以
    {
        a = j;                       //临时储存j
        for (int i = 2; i <= a; i++) //一定会只除到质数，如果不是质数的话在之前的循环中就已经被除成质数了
        {
            while (a % i == 0) //如果是
            {
                cnt[i]++;
                a /= i;
            }
        }
    }
    for (int i = 2; i <= 10000; i++)
    {
        if (cnt[i] != 0)
        {
            printf("%d %d\n", i, cnt[i]);
        }
    }
    return 0;
}