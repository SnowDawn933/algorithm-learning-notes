#include <stdio.h>
#include <stdbool.h>
void euler_sieve(int a);
const unsigned long long maxn = 1e8 + 7;
bool isprime[maxn];
int prime[maxn], cnt = 0;
int main(void)
{
    int n;
    scanf("%d", &n);
    euler_sieve(n);
    for (int i = 2; i <= n; i++)
    {
        if (!isprime[i])
        {
            printf("%d ", i);
        }
    }
    printf("%d", cnt);
    return 0;
}
void euler_sieve(int a)
{
    for (int i = 2; i <= a; i++)
    {
        if (!isprime[i])
        {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > a)
                break;
            isprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}