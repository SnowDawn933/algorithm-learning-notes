#include <stdio.h>       //注意边界，不能直接在数组的边界插火把和萤石，可能会爆掉，导致re
int a[100 + 5][100 + 5]; //定义一个坐标
int main(void)
{
    int n, m, k, x, y, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);                       //输入火把的坐标
        for (int j = x + 2 - 1; j <= x + 2 + 1; j++) //加2是为了避免边界插火把爆掉
            for (int k = y + 2 - 1; k <= y + 2 + 1; k++)
                a[j][k] = 1;
        a[x + 2 - 2][y + 2] = 1;
        a[x + 2 + 2][y + 2] = 1;
        a[x + 2][y - 2 + 2] = 1;
        a[x + 2][y + 2 + 2] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &x, &y); //输入萤石的坐标
        for (int j = x + 2 - 2; j <= x + 2 + 2; j++)
            for (int k = y + 2 - 2; k <= y + 2 + 2; k++)
                a[j][k] = 1;
    }
    //搜索如果有没亮的格子答案+1
    for (int i = 3; i <= n + 2; i++) //因为没在边界插，所以检查的时候也要相应往里面缩
        for (int j = 3; j <= n + 2; j++)
            if (a[i][j] == 0)
                ans++;
    printf("%d", ans);
    return 0;
}