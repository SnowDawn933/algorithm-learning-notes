//二分答案的简单模板题目 所谓二分答案就是在二分查找的基础上进行一些运算来判断是否符合题中要求，再决定往那个方向来继续二分
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
int n;
ll k, maxn;
ll a[1000010];
bool bigorsmall(ll x);
int main(void)
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        maxn = max(maxn, a[i]);
    }
    ll l = 0, r = maxn; //注意l要设置为0，不然当一截要求的木材都搞不出来的话就不能输出0了
    while (l + 1 < r)
    {
        ll mid = l + (r - l) / 2;
        if (bigorsmall(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%lld", l);
    return 0;
}
bool bigorsmall(ll x)
{
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += a[i] / x;
    }
    return sum >= k;
}