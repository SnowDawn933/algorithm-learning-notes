#include <stdio.h>
int main(void)
{
    int n, b, a;
    scanf("%d%d", &n, &b);
    int ans = b;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &a);
        if (a > b)
            ans += (a - b);
        b = a;
    }
    printf("%d", ans);
    return 0;
}