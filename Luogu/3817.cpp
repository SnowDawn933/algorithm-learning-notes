#include <stdio.h>
int main(void)
{
    long long n, x;
    scanf("%lld%lld", &n, &x);
    int a[100010];
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    for (int i = 1; i < n;i++)
    {
        if(a[i]+a[i+1]>x)
        {
            ans =ans+ (a[i] + a[i + 1] - x);
            a[i + 1] = x - a[i];           
        }
    }
    printf("%lld", ans);
    return 0;
}