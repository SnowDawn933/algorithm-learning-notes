//使用递归的写法实现a^b%m
#define ll long long
ll binarypower(ll a, ll b, ll m)
{
    if (b == 0) //b==0时任何数的零次方都是1
        return 1;
    if (b % 2 == 1) //b为奇数时，转换为b-1
        return a * binarypower(a, b - 1, m);
    if (b % 2 == 0) //b为偶数时，转换为b/2
    {
        int mul = binarypower(a, b / 2, m);
        return mul * mul % m;
    }
}
//使用递归写法实现，基于二进制的写法
#define ll long long
ll binarypower1(ll a, ll b, ll m)
{
    ll ans = 1;   //将答案初始化设为1
    while (b > 0) //只要b大于零时
    {
        if (b & 1) //判断二进制的末位是不是1，也可以理解为判断b是不是奇数
        {
            ans = ans * a % m; //乘上a
        }
        a = a * a % m; //将a平方，因为b将要进位
        b >>= 1;       //将b的二进制右移一位，也可以理解为b/2
    }
    return ans; //返回最终答案
}
//个人认为二进制的迭代方法跟容易理解，递归终究还是太抽象