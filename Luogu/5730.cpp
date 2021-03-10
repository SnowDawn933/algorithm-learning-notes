#include <stdio.h>
#include <string.h>
int main(void)
{
    int n;
    char  s1[450] = {'\0'}, s2[450] = {'\0'}, s3[450] = {'\0'}, s4[450] = {'\0'}, s5[500] = {'\0'};
    scanf("%d", &n);
    char a[110];
    scanf("%s", a);
    for (int i = 0; i < n; i++)
    {
        
        if (a[i] == '0')
        {
            strcat(s1, "XXX.");
            strcat(s2, "X.X.");
            strcat(s3, "X.X.");
            strcat(s4, "X.X.");
            strcat(s5, "XXX.");
        }
        if (a[i] == '1')
        {
            strcat(s1, "..X.");
            strcat(s2, "..X.");
            strcat(s3, "..X.");
            strcat(s4, "..X.");
            strcat(s5, "..X.");
        }
        if (a[i] == '2')
        {
            strcat(s1, "XXX.");
            strcat(s2, "..X.");
            strcat(s3, "XXX.");
            strcat(s4, "X...");
            strcat(s5, "XXX.");
        }
        if (a[i] == '3')
        {
            strcat(s1, "XXX.");
            strcat(s2, "..X.");
            strcat(s3, "XXX.");
            strcat(s4, "..X.");
            strcat(s5, "XXX.");
        }
        if ((a[i]) == '4')
        {
            strcat(s1, "X.X.");
            strcat(s2, "X.X.");
            strcat(s3, "XXX.");
            strcat(s4, "..X.");
            strcat(s5, "..X.");
        }
        if (a[i] == '5')
        {
            strcat(s1, "XXX.");
            strcat(s2, "X...");
            strcat(s3, "XXX.");
            strcat(s4, "..X.");
            strcat(s5, "XXX.");
        }
        if (a[i] == '6')
        {
            strcat(s1, "XXX.");
            strcat(s2, "X...");
            strcat(s3, "XXX.");
            strcat(s4, "X.X.");
            strcat(s5, "XXX.");
        }
        if (a[i] == '7')
        {
            strcat(s1, "XXX.");
            strcat(s2, "..X.");
            strcat(s3, "..X.");
            strcat(s4, "..X.");
            strcat(s5, "..X.");
        }
        if (a[i] == '8')
        {
            strcat(s1, "XXX.");
            strcat(s2, "X.X.");
            strcat(s3, "XXX.");
            strcat(s4, "X.X.");
            strcat(s5, "XXX.");
        }
        if (a[i] == '9')
        {
            strcat(s1, "XXX.");
            strcat(s2, "X.X.");
            strcat(s3, "XXX.");
            strcat(s4, "..X.");
            strcat(s5, "XXX.");
        }
    }
    for (int j = 0; j< n * 4 - 1; j++)
    {
        printf("%c", s1[j]);
    }
    printf("\n");
    for (int i = 0; i < n * 4 - 1; i++)
    {
        printf("%c", s2[i]);
    }
    printf("\n");
    for (int i = 0; i < n * 4-1 ; i++)
    {
        printf("%c", s3[i]);
    }
    printf("\n");
    for (int i = 0; i < n * 4 - 1; i++)
    {
        printf("%c", s4[i]);
    }
    printf("\n");
    for (int i = 0; i < 4*n-1; i++)
    {
        printf("%c", s5[i]);
    }
    printf("\n");
    return 0;
}
