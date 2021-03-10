#include <stdio.h>
#define ll long long
ll gcd(int a, int b);
int main(void)
{
    int n;
    scanf("%d", &n); //输入次数
    for (int ii = 1; ii <= n; ii++)
    {
        ll a1, a0, b1, b0;
        scanf("%lld%lld%lld%lld", &a0, &a1, &b0, &b1);
        ll p = a0 / a1; //设置公式需要的量
        ll q = b1 / b0;
        int ans = 0;                       //输出的答案
        for (ll x = 1; (x * x) <= b1; x++) //找出b1的因子
        {
            if (b1 % x == 0)
            {
                if (x % a1 == 0 && gcd(x / a1, p) == 1 && gcd(q, b1 / x) == 1) //一定满足这两个式子
                    ans++;                                                     //所求的值一定是a1的倍数
                int y = b1 / x;                                                //找出b1与x对应的另一个因子
                if (x == y)                                                    //完全平方时跳出
                    continue;
                if (y % a1 == 0 && gcd(y / a1, p) == 1 && gcd(q, b1 / y) == 1)
                    ans++;
            }
        }
        printf("%d\n", ans); //输出答案
    }
    return 0;
}
ll gcd(int a, int b) //欧几里得算法求gcd
{
    return b ? gcd(b, a % b) : a;
}