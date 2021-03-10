#include <stdio.h>
#define ll long long    //数据普遍比较大的时候这样可以节省时间
void exGcd(ll a, ll b); //扩展欧几里得算法，如果将x y 都设置为全局变量的话，就不用向函数传递地址了
int x1, y1;
ll g; //存放gcd，最后根据裴蜀定理判断有没有解
int main(void)
{
    ll x, y, m, n, l, a, b, c;
    scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
    a = n - m; //根据题意将变量化为不定方程的形式，就可以用扩展欧几里得算法求解了
    b = l;
    c = x - y; //设置成一般式的a,b,c可以更加直观，不用再将变量名与公式一一对应，直接套用就好了
    if (a < 0)
    {
        c = -c; //处理c为负数的情况
        a = -a; //同时变号是为了满足等式成立，但b不影响对于x的求解，所以不用也不能变号，变号的话就会变成负的
    }
    exGcd(a, b);    //调用扩欧函数
    if (c % g != 0) //裴蜀定理判断是否有解
        printf("Impossible");
    else
    {
        printf("%lld", ((c * x1 / g) % (b / g) + b / g) % (b / g)); //根据公式输出线性不定方程的最小非负整数解
    }
    return 0;
}
void exGcd(ll a, ll b)
{
    if (b == 0)
    {
        x1 = 1;
        y1 = 0;
        g = a; //顺便求出gcd
        return;
    }
    exGcd(b, a % b);
    int temp = x1;
    x1 = y1;
    y1 = temp - a / b * y1; //扩欧的公式
}