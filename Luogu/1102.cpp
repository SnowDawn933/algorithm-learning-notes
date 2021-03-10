#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200010];
int xiaode(int l, int r, int x);
int dade(int l, int r, int x);
long long ans;
int main(void)
{
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int b = a[i] - c;
        ans += dade(1, n, b) - xiaode(1, n, b);
    }
    printf("%lld", ans);
    return 0;
}
int xiaode(int l, int r, int x)
{
    int mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int dade(int l, int r, int x)
{
    int mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}