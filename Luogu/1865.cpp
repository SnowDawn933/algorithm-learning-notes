#include <stdio.h>
#include <stdbool.h>
const int maxn = 1e6;
int prime[maxn], cnt = 0;
bool isprime[maxn];
void euler_sieve(int a);
int main(void)
{
    int m, n, ans;
    scanf("%d%d", &n, &m);
    euler_sieve(m);
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        scanf("%d%d", &l, &r);
        if (r > m || l > m || r < 1 || l < 1)
            printf("Crossing the line\n");
        else
        {
            for (int j = 0; j < cnt; j++)
            {
                if (prime[j] >= l && prime[j] <= r)
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
void euler_sieve(int m)
{
    for (int i = 2; i <= m; i++)
    {
        if (!isprime[i])
        {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > m)
                break;
            isprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}