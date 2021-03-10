#include <stdio.h>
#include <stdbool.h>
const int maxn = 1e6 + 7;
bool isprime[maxn];//如果没有初始化的bool数组是全部默认false的
void era_sieve(int b);//定义函数
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    isprime[1] = true;//将1设置为非质数
    era_sieve(b);//调用函数
    for (int i = a; i <= b; i++)//输出筛剩下的
    {
        if (!isprime[i])
        {
            printf("%d ", i);
        }
    }
    return 0;
}
void era_sieve(int b)
{
    for (int i = 2; i <= b; i++)
    {
        if (!isprime[i])
        {
            for (int j = 2 * i; j <= b; j += i)//将质数的倍数全部筛去

            {
                isprime[j] = true;
            }
        }
    }
}