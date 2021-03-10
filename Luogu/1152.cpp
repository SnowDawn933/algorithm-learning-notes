#include <cstdio>
#include <cmath>
long long b[10000010];
long long a[10000010];
int main(void)
{
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        b[abs(a[i] - a[i - 1])] = 1;
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (b[i] != 0)
            ans++;
    }
    if (ans == n - 1)
    {
        printf("Jolly");
    }
    else
    {
        printf("Not jolly");
    }
    return 0;
}