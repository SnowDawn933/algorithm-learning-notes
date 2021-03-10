#include <stdio.h>
int main(void)
{
    int l, r, ans1 = 0, ans2 = 0;
    scanf("%d%d", &l, &r);
    for (int i1 = 0; i1 <= l; i1++)
    {
        for (int j1 = 0; j1 <= r; j1++)
        {
            for (int i2 = i1 + 1; i2 <= l; i2++)
            {
                for (int j2 = j1 + 1; j2 <= r; j2++)
                {
                    ans2++;
                    if (j2 - j1 == i2 - i1)
                        ans1++;
                }
            }
        }
    }
    printf("%d %d", ans1, ans2 - ans1);
    return 0;
}