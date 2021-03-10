#include <stdio.h> //求ax+by=gcd(a,b)的解
int exGcd(int a, int b, int &x, int &y);
int main(void)
{
    int a, b;
    int x, y;
    scanf("%d%d", &a, &b);
    int gcd = exGcd(a, b, x, y);
    printf("%d", (x % (b / gcd) + (b / gcd)) % (b / gcd)); //最小非负整数解
    return 0;
}
int exGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGcd(b, a % b, x, y); //递归计算exGcd
    int temp = x;                  //存放X的值
    x = y;                         //更新x=y(old)
    y = temp - a / b * y;          //更新y=x(old)-a/b*y(old)
    return g;                      //g是gcd
}
//可以根据求出的一组x y的解得出全部的解
//x1 = x+b/gcd*k    (k为 任意整数)
//y1 = y-a/gcd*k