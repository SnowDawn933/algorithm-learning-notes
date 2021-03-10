#include <stdio.h>
int main(void)
{
    int a, b, c, sum, e, f, g;
    int x, y, z, cnt = 0;
    scanf("%d%d%d", &x, &y, &z);
    int book[10];
    for (int i = 123; i <= 123 / x * z; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            book[j] = 0;
        }
        a = i;
        e = a;
        b = i / x * y;
        f = b;
        c = i / x * z;
        g = c;
        if (e < 987 && f < 987 && g < 987)
        {
            while (a > 0)
            {
                book[a % 10] = 1;
                a /= 10;
            }
            while (b > 0)
            {
                book[b % 10] = 1;
                b /= 10;
            }
            while (c > 0)
            {
                book[c % 10] = 1;
                c /= 10;
            }
            sum = 0;
            for (int j = 1; j <= 9; j++)
            {
                sum += book[j];
            }
            if (sum == 9)
            {
                printf("%d %d %d\n", e, f, g);
                cnt++;
            }
        }
    }
    if (cnt == 0)
    {
        printf("No!!!");
    }
    return 0;
}
