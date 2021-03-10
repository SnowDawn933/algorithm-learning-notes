#include<stdio.h>
#include<string.h>
int main(void)
{
    char a[55];
    int b,l;
    scanf("%d", &b);
    scanf("%s", a);
    l = strlen(a);
    for (int i = 0; i < l;i++)
    {
        if(a[i]+b>'z')
            a[i] = 'a'-1 + b - ('z' - a[i]);
        else
            a[i] += b;
        printf("%C", a[i]);
    }
    return 0;
}