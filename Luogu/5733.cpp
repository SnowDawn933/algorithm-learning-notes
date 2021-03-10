#include<stdio.h>
int main(void)
{
    char a;
    while(scanf("%c",&a)!=EOF)
    {
        if (a<='z'&&a>='a')
            printf("%c", a - 32);
        else
        {
            printf("%c", a);
        }
        
    }
    return 0;
}