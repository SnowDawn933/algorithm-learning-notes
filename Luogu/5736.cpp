#include<stdio.h>
int zhishu(int a)
{
    if(a==1)
        return 0;
    for (int i = 2; i < a;i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int n,a[110],i;
    scanf("%d", &n);
    for (int j = 1; j <=n;j++)
    {
        scanf("%d", &a[j]);
        if(zhishu(a[j])==1)
            printf("%d ", a[j]);

    }
    return 0;
}
