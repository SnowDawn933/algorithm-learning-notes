//判断一个字符串是否为回文字符串
#include <stdio.h>
#include <string.h>
int main(void)
{
    int l, mid, top, next;
    char a[101];    //输入的字符串
    char s[101];    //栈
    scanf("%s", a); //
    l = strlen(a);
    mid = l / 2 - 1; //找中点，-1是因为数组的下标是从0开始的
    top = 0;
    for (int i = 0; i <= mid; i++) //mid之前的存入栈中
    {
        s[++top] = a[i];
    }
    if (l % 2 == 0) //分奇偶判断从哪里开始回文匹配
        next = mid + 1;
    else
        next = mid + 2;                 //如果是奇数的话直接跳过了中间的那个，到对称点的另一一边
    for (int i = next; i <= l - 1; i++) //l-1是因为数组的第一个下标是0
    {
        if (a[i] != s[top])
            break;
        top--; //每有一个匹配成功就减一
    }
    if (top == 0)
        printf("YES"); //全部成功
    else
    {
        printf("NO");
    }
    return 0;
}
