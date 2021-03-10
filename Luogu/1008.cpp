#include <stdio.h> //999如果想要排出1:2:3三个数，最小数最大不能超过999/3=333.因为不能重复，所以最小的数为123
int main(void)
{
    int a, b, c, sum;
    int book[10];
    for (int i = 123; i <= 333; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            book[j] = 0;
        }
        a = i;
        b = 2 * i;
        c = 3 * i;
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
            printf("%d %d %d\n", i, 2 * i, 3 * i);
        }       
    }
    return 0;
}
