#include <cstdio>
#include <algorithm>
using namespace std;
long long ll;
long long a[50005];
bool check(int mid);
int m, n, ans;
int main(void)
{
    scanf("%lld%d%d", &ll, &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    a[n + 1] = ll;
    int l = 1, r = ll;
    while (l <= r)
    {
        int mid = (l + r + 1) / 2;//为了避免当l = r + 1 的时候陷入无限循环
        if (check(mid))
        {
            ans = mid;//暂且将答案设置为mid
            l = mid + 1;//
        }
        else
            r = mid - 1;
    }
    printf("%d", ans);
    return 0;
}

bool check(int mid)
{
    int temp = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - a[temp] < mid) //把这个距离当成是最小距离的话，不能跳过去，就把这这里搬掉。
            cnt++;                //搬掉的石头数量计数加1
        else
            temp = i; //不搬，直接跳过来就好
    }
    if (cnt > m) //般的太多了，太小了
        return false;
    else //搬走的太少了，太大了
        return true;
}