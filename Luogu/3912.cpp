#include <stdio.h>
long long ans;
int isPrime[50000] , isPrimee[1000005] , prime[50000];
int Euler(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
       // isPrime[1] = isPrime[0] = 1;
        if (!isPrime[i])
        {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)
        {
            isPrime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    return cnt;
}
int main()
{
    long long l, r, cnt, t, ans = 0;
    scanf("%lld %lld", &l, &r);
    cnt = Euler(50000);
    for (int i = 1; i < cnt; i++)
    {
        int p = prime[i];
        long long start;
       // isPrimee[1] = 1;
        if (p >= l)
        {
            start = 2 * p;
            for (long long j = start; j <= r; j += p)
            {
                isPrimee[j - l] = 1;
            }
        }
        else
        {
            int a = l / p;
            if (l % p == 0)
            {
                start = l;
                if (a == 1)
                {
                    start = 2 * l;
                }
            }
            else
            {
                start = prime[i] * (a + 1);
            }
            for (long long j = start; j <= r; j += p)
            {
                isPrimee[j - l] = 1;
            }
        }
    }
    for (int i = 0; i <= r - l; i++)
    {
        if (!isPrimee[i])
        {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}