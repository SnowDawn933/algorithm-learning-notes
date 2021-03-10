#include <stdio.h>
#include <stdbool.h>
const int maxn = 50000;
bool isprime[maxn];
int prime[maxn], cnt = 1;
bool isprime1[1000001];
void era_sieve();
int main(void)
{
    long long l, r;
    int ans = 0;
    scanf("%lld%lld", &l, &r);
    isprime[1] = true;
    era_sieve();
    for (int i = 1; i < cnt; i++)
    {
        int p = prime[i], a;
        long long int start; //不能开int 会爆掉的
        if (l <= p)          //质数就在里面
        {
            start = 2 * p; //从第一个倍数开始筛
            for (long long int j = start; j <= r; j += p)
            {
                isprime1[j - l] = true;
            }
        }
        else //质数不在里面
        {
            a = l / p; //判断一下l是不是p的倍数
            if (l % p == 0)
            {
                start = l; //是的话从l开始筛
                if (a == 1)
                    start = 2 * l; //质数恰好是第一个时，从二倍开始筛
            }
            else
            {
                start = prime[i] * (a + 1); //从第一个质数的倍数开始筛
            }
            for (long long int j = start; j <= r; j += p) //不能开int 会爆掉的
            {
                isprime1[j - l] = true;
            }
        }
    }
    for (int i = 0; i <= r - l; i++)
    {
        if (!isprime1[i])
            ans++;
    }
    printf("%d", ans);
    return 0;
}
void era_sieve() //筛出50000以内的质数时
{
    int a = 50000;
    for (int i = 2; i <= a; i++)
    {
        if (!isprime[i])
        {
            prime[cnt++] = i;
            for (int j = 2 * i; j <= a; j += i)
            {
                isprime[j] = true;
            }
        }
    }
}
//AC绿题爽爆了