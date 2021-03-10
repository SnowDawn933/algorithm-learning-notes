#include <stdio.h>
int exGcd(int a, int b, int &x, int &y);
int x, y;
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    exGcd(a, b, x, y);
    printf("%d", (x % b + b) % b);
    return 0;
}
int exGcd(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return g;
}
