
#include <stdio.h>
#include <stdbool.h>
void euler_sieve(int a);
const unsigned long long maxn = 1e8;
bool isprime[maxn];
int prime[maxn], cnt = 1;
int main(void)
{
    int n, q, k;
    scanf("%d%d", &n, &q);
    euler_sieve(n);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &k);
        printf("%d\n", prime[k]);
    }
}
void euler_sieve(int a)
{
    for (int i = 2; i <= a; i++)
    {
        if (!isprime[i])
        {
            prime[cnt++] = i;
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (i * prime[j] > a)
                break;
            isprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}