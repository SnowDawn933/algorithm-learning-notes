#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int x, n;
    int money[15];
    scanf("%d%d", &x, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &money[i]);
    }
    sort(money + 1, money + 1 + n);
    if (money[1] != 1) //如果没有面值为1的硬币，那么就不可能得到1，直接输出-1
    {
        printf("-1");
        return 0;
    }
    int s = 0;    //当前可以扩充到哪里
    int k = 1;    //使用的扩充硬币
    int cnt = 0;  //使用了几个
    while (s < x) //在可以达到的面值小于需求的x之前
    {
        for (int i = k; i <= n; i++) //从上一个使用过的扩充硬币开始遍历
        {
            if (money[i] <= s + 1 && (i == n || money[i + 1] > s + 1)) //选择不超过   大于当前s（即s+1）的最小值进行扩充，否则会导致中间有一个值无法被取到
            {
                s += money[i]; //扩充到了哪里
                k = i;         //下一轮的遍历起点改变
                cnt++;         //计数器加一
                break;         //记得结束这个循环，要去找下一个数来扩充了
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
