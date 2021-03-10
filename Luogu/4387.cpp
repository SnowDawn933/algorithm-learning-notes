#include <stdio.h>
struct stack
{
    int data[100010];
    int top;
};
int main(void)
{
    int n, m;
    scanf("%d", &n);
    struct stack q[n + 10];
    for (int i = 1; i <= n; i++)
    {
        int pushed[100010];
        int poped[100010], m;
        scanf("%d", &m); //有多少数
        q[i].top = 0;    //初始化栈
        int l = 1;
        for (int j = 1; j <= m; j++) //输入入栈序列
        {
            scanf("%d", &pushed[j]);
        }
        for (int k = 1; k <= m; k++) //输入出栈序列
        {
            scanf("%d", &poped[k]);
        }
        for (int j = 1; j <= m; j++) //将入栈序列中的数压入栈
        {
            q[i].top++;
            q[i].data[q[i].top] = pushed[j];
            while (q[i].data[q[i].top] == poped[l]) //如果可以和poped中的数匹配
            {
                l++; //继续匹配下一个数
                q[i].top--;
                if (q[i].top == 0)
                    break;
            } //不能匹配时继续将数压入栈
        }
        if (q[i].top == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}