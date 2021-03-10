#include <stdio.h>
#include <string.h>
int main(void)
{
    char n[1005];
    int m, a; //m进制的数n,是一个T位数
    scanf("%d%s", &m, n);
    a = strlen(n);
    int t = a;
    for (int i = 0; i < a - 1; i++, t--)
    {
        if (n[i] != '0' && i != 0)
            printf("+");
        if (n[i] != '0')
        {
            printf("%c*%d^%d", n[i], m, t - 1);
        }
    }
    if (n[a - 1] != '0')
    {
        printf("+%c*%d^%d", n[a - 1], m, t - 1);
    }
    return 0;
}