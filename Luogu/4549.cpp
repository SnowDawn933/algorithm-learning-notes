#include <stdio.h>
int gcd(int a, int b);
int n;
int main(void)
{
    int ans = 0, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b);
        if (b < 0)
            b = -b;
        ans = gcd(ans, b);
    }
    printf("%d", ans);
    return 0;
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a; //用问号运算符精简过后的欧几里得算法求最大公因数
} //r如果b！=0，那么继续递归