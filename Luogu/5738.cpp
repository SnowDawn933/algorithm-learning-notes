#include <stdio.h>
float ans(int a);
int main(void)
{
    float ii,max = 0;
    int n,m;
    scanf("%d%d", &n,&m);
    for (int i = 1; i <= n;i++)
    {
        ii = ans(m);
        if (ii>max)
            max = ii;
    }
    printf("%.2f", max);
    return 0;
}
float ans(int a)
{
    float ans;
    int mark[25], max = 0,min=10,sum = 0;
    for (int i = 1; i <= a;i++)
    {
        scanf("%d", &mark[i]);
        sum += mark[i];
        if(mark[i]>max)
            max = mark[i];
        if(mark[i]<min)
            min = mark[i];
    }
    return (sum - max - min) *1.0/ (a - 2);
}