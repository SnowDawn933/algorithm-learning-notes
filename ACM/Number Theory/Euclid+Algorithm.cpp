#include <stdio.h>
int gcd(int a, int b); //递归的欧几里得算法求gcd
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}
int gcd(int a, int b)
{
    int t;
    if (a > b) //要保证a是较小的那个数
    {
        t = a;
        a = b;
        b = t;
    }
    if (b % a == 0)
        return a;
    else
    {
        a = b % a;
        gcd(a, b);
    }
}