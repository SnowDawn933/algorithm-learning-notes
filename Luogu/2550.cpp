#include<stdio.h>
int main(void)
{
    int n,cnt;
    int a[10],b[10];//分别储存中奖号码  中奖次数
    scanf("%d", &n);
    for (int x = 1; x <= 7;x++)
    {
        scanf("%d", &a[x]);
    }
    for (int y = 7; y>=1;y--)
    {
        b[y] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int c[10]; //每个中奖号码
        for (int j = 1; j <= 7;j++)
        {
            scanf("%d", &c[j]);
            for (int x = 1; x <= 7;x++)
            {
                if(c[j]==a[x])
                    cnt++;
            }
        }
        for (int y = 7; y >= 1;y--)
        {
            if(cnt==y)
            {
                b[y]++;
                cnt = 0;
            }
        }
    }
    for (int y = 7; y >= 1;y--)
    {
        printf("%d ", b[y]);
    }

    return 0;
}
