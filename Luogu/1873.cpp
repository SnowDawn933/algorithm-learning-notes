#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[1000010];
long long n, m, maxn = 0;
int main(void)
{
    long long h;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        maxn = max(maxn, a[i]);
    }
    long long mid;
    long long sum;
    long long l = 1, r = maxn;
    while (l <= r)
    {
        sum = 0;
        mid = l + (r - l) / 2;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > mid)
                sum += (a[i] - mid);
        }
        if (sum < m)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld", l-1);
    return 0;
}
