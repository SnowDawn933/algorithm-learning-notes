#include <stdio.h>
int main(void)
{
    int n, m, sum, min = 2500, nw, nb, nr;
    scanf("%d%d", &n, &m);
    char a[n + 10][m + 10];
    for (int i = 1; i <= n; i++) //输入进去颜色状态
    {
        scanf("%s", a[i]);
    }
    for (int i = 1; i <= n - 2; i++) //白的有几行
    {
        for (int j = n - i - 1; j >= 1; j--) //蓝的有几行
        {
            int k = n - i - j; //红的有几行
            nw = 0;
            nb = 0;
            nr = 0;
            sum = 0;
            for (int x1 = 1; x1 <= i; x1++) //处理要变白的行数
            {
                for (int x = 0; x < m; x++)
                {
                    if (a[x1][x] != 'W')
                        nw++;
                }
            }
            for (int y1 = i + 1; y1 <= j + i; y1++) //处理要变白的行数
            {
                for (int y = 0; y < m; y++)
                {
                    if (a[y1][y] != 'B')
                        nb++;
                }
            }
            for (int z1 = i + j + 1; z1 <= i + j + k; z1++) //处理要变白的行数
            {
                for (int z = 0; z < m; z++)
                {
                    if (a[z1][z] != 'R')
                        nr++;
                }
            }
            sum = nr + nb + nw;
            if (sum < min)
                min = sum;
        }
    }
    printf("%d", min);
    return 0;
}