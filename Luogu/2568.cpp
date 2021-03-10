//gcd(a,b)=p  gcd(a/p,b/p)=1  求1到n/p的所有数的欧拉函数值之和  进行一定处理即可
#include <stdio.h>
#include <stdbool.h>
int prime[10000010], euler[10000010], n, cnt;
long long ans, sum[10000010]; //十年OI一场空，不开long long见祖宗
bool isprime[10000010];
void euler_sieve();
int main(void)
{
    scanf("%d", &n);
    euler_sieve();
    for (int i = 1; i <= cnt; i++)
    {
        ans += 2 * sum[n / prime[i]] - 1; //所求的是坐标值，所以要乘2，两个质数相等时会重复，所以每个减去1
    }
    printf("%lld", ans);
    return 0;
}
void euler_sieve() //欧拉函数+欧拉筛的板子
{
    euler[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!isprime[i])
        {
            prime[++cnt] = i;
            euler[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            isprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                euler[i * prime[j]] = euler[i] * prime[j];
                break; //记得break；
            }
            else
            {
                euler[i * prime[j]] = euler[i] * (prime[j] - 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + euler[i]; //为了在主函数中的累加，求出每个数的前缀和
    }
}