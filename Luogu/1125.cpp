#include <stdio.h>
#include <string.h>
int b[130];
int isprime(int a);
int main(void)
{

    int lengh, max = 0, min = 100;
    int dif;
    char a[110];
    scanf("%s", a);
    lengh = strlen(a);
    for (int i = 0; i < lengh; i++)
    {
        b[a[i]]++;
        if (b[a[i]] > max)
            max = b[a[i]];
    }
    for (int i = 97; i <= 122; i++)
    {
        if (b[i] != 0)
        {
            if (b[i] < min)
                min = b[i];
        }
    }
    dif = max - min;
    if (isprime(dif) == 1)
        printf("Lucky Word\n%d", dif);
    else
        printf("No Answer\n0");
    return 0;
}
int isprime(int a)
{
    if (a == 1 || a == 0)
        return 0;
    if (a == 2)
        return 1;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}