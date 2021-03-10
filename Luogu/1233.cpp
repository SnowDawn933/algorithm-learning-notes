#include <stdio.h>
#include <algorithm>
using namespace std;

struct stick
{
    int len, wid;
} w[5550];
bool cmp(stick a, stick b);
int dp[5550];
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i].len, &w[i].wid);
    }
    sort(w + 1, w + 1 + n, cmp);
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (w[i].wid >= w[j].wid && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        ans = max(dp[i], ans);
    }
    printf("%d", ans);
}
bool cmp(stick a, stick b)
{
    if (a.len != b.len)
        return a.len > b.len;
    else
        return a.wid > b.wid;
}