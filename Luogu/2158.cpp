//分析：将原题转化为不同的斜率个数问题，只要斜率表达式可以被约分那么会被挡住
//而不能被约分 即 分母与分子互质 ，欧拉函数的值为 小于m的 与m互质的 数的个数
//再结合欧拉筛质数法以及欧拉函数的推论公式就可以得出结果
//得出的结果是在斜率k<1的三角形部分的个数（对于每个m运用欧拉函数求出的相对应所有的互质数必定小于m，所以是一个三角形的区域）
//由对称性得出最终结果
#include <stdio.h>
#include <stdbool.h>
int prime[40010], ans, cnt, n, euler[40010]; //欧拉筛的准备
bool isprime[40010];
void euler_sieve();
int main(void)
{
    scanf("%d", &n);
    if (n == 1) //特判n=1的情况
    {
        printf("0");
        return 0;
    }
    euler_sieve();
    for (int i = 1; i < n; i++)
    {
        ans += euler[i];
    }
    printf("%d", 2 * ans + 1); //加上对角线上的一个，即斜率为1
    return 0;
}
void euler_sieve()
{
    euler[1] = 1; //虽然n=1时结果为零，但是为了应用函数，将euler[1]设置为1
    for (int i = 2; i <= n; i++)
    {
        if (!isprime[i])
        {
            prime[++cnt] = i;
            euler[i] = i - 1; //显然在i为质数时欧拉函数的值为1
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (i * prime[j] > n)
                break;
            isprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                euler[i * prime[j]] = euler[i] * prime[j]; //欧拉函数的特性:a|b  （a为质数）则euler(ab)=a*euler(b)
                break;
            }
            else //欧拉函数的特性：a不是b的倍数（a为质数）则 euler(ab)=euler(a)*euler(b)
            {
                euler[i * prime[j]] = euler[i] * (prime[j] - 1); //即euler[prime[j]]
            }
        }
    }
}