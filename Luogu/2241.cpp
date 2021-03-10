//这一题数据规模太大不能暴力枚举全部的坐标，只能使用数学公式来计算
#include <stdio.h>
long long ans1 = 0, ans2 = 0;
long long a, b, m, n;
int main(void)
{

    scanf("%d%d", &a, &b);
    m = a;
    n = b;
    ans1 = m * n;
    while (m != 0 && n != 0)
    {

        m--;
        n--;
        ans1 += m * n;
    }
    ans2 = a * b * (a + 1) * (b + 1) / 4 - ans1;
    printf("%lld %lld", ans1, ans2);
    return 0;
}