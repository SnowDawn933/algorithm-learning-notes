//求解逆元的几种方法
//001  exGcd  模m可以不是质数

#define ll long long
int exGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
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
int inverse(int a, int m)
{
    int x, y;
    int g = exGcd(a, m, x, y); //求解ax+my=1
    return (x % m + m) % m;    //求出最小非负整数解
}

//002 使用费马小定理求解  只适用于模数为质数的情况
ll fastpower(ll a, ll b, ll p) //使用快速幂来求解a^m-2%m
{
    ll ans = 1;
    b -= 2;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

//003  递推法 只适用于模数为质数的情况  如果遇到要解模的逆元的数 数量很多，但是连续，就可以使用递推法
//i 模 p 意义下的逆元 inv(i) 可表示为 :
//    inv(i) = -[p/i](向下取整) * inv(p % i) % p    具体的代码如下
#include <cstdio>
using namespace std;
long long n, p;
long long ans[5000010] = {0, 1}; //初始化1的逆元
int main()
{
    scanf("%lld%lld", &n, &p);
    printf("1\n");
    for (long long i = 2; i <= n; i++) //线性递推
    {
        ans[i] = (long long)(p - p / i) * ans[p % i] % p; //使用 （long long ）来进行强制转换为long long类型防止其溢出
        printf("%lld\n", ans[i]);
    }
}
