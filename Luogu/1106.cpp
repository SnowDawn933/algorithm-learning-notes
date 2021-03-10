//删去数据的循序是按照从左到右的山峰顶数据来进行的，而不是总是删去全部数列中最大的那个数
#include <cstdio>
#include <cstring>
int s[15]; //存放高精度的数
int main(void)
{
    char s1[15];
    scanf("%s", s1);
    int k;
    scanf("%d", &k);
    int l = strlen(s1);
    for (int i = 0; i < l; i++)
    {
        s[i] = s1[i] - '0'; //数字字符  -‘0’就可以将其转化为整形的数字
    }
    for (int m = 1; m <= k; m++)
    {
        for (int i = 0; i < l; i++)
        {
            if (s[i + 1] < s[i]) //即出现了顶峰，下一个数开始下降了
            {
                for (int j = i; j < l; j++) //将所有的数据都往前移动一位，即删去了当前的数
                {
                    s[j] = s[j + 1];
                }
                l--;
                break; //一次只删除一个数，删了一个之后就要退出
            }
        }
    }
    bool flag = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 0 && !flag && i < l - 1)//去除前导零，但是需要考虑到的是如果删完之后整个数列只剩下0了，那么就要留下一个0不要删，作为最后的结果来说输出
            continue;
        flag = 1;
        printf("%d", s[i]);
    }
    return 0;
}
