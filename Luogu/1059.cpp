#include<stdio.h>
int a[1010];
int main(void)
{
    int n,t,ans;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &t);
        if(a[t]==0)
        {
            ans++;
            a[t] = t;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <=1000;i++)
    {
        if(a[i]!=0)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;

}