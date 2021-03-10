#include <stdio.h>
#define ll long long
const int maxn = 3000010;
ll inv[maxn];
int main(void)
{
    ll n, p;
    scanf("%lld%lld", &n, &p);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", inv[i]);
    }
    return 0;
}