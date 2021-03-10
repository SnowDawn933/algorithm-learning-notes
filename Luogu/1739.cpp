#include <stdio.h>
int main(void)
{
    char a[260], c;
    int s = 0;
    int l;
    for (l = 0;; l++)
    {
        c = getchar();
        if (c == '@')
            break;
        a[l] = c;
    }
    for (int i = 0; i <= l; i++)
    {

        if (a[i] == '(')
        {
            s++;
        }

        if (a[i] == ')')
        {
            s--;
        }
        if(s<0)
        {
            printf("NO");
            return 0;
        }
    }
    if (s ==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}

