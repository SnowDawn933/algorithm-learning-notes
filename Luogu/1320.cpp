#include<stdio.h>
#include<string.h>
int main(void)
{
    char zong[40010], hang[200];
    int n,l,cnt=0,isprime='0';
    scanf("%s", zong);
    n=strlen(zong);
    for (int i = 2; i <= n;i++)
    {
        scanf("%s", hang);
        strcat(zong, hang);
    }
    l = strlen(zong);
    printf("%d ", n);
    for (int i = 0; i <= l;i++)
    {
        if(isprime==zong[i])
        {
            cnt++;
        }
        else
        {
            printf("%d ", cnt);
            cnt = 1;
            isprime = zong[i];
        }
    }
    return 0;
}