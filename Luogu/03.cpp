#include <cstdio>
int main(void)
{
    long long multi = 1;
    long long n, a, sum;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        scanf("%d", &a);
        while (a > 0)
        {
            sum += a % 10;
            a /= 10;
        }
        multi *= sum;
    }
    int i = 0;
    while (multi >= 10)
    {
        while (multi > 0)
        {
            i += multi % 10;
            multi /= 10;
        }
        multi = i;
        i = 0;
    }
    printf("%d", multi);
    return 0;
}