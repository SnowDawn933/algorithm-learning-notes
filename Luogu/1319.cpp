#include<stdio.h>
int main(void)
{
    int n, sum = 0, num = 0,cnt=0;
    int a[205];
    scanf("%d", &n);
    for (int i = 1;;i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        cnt++;
        if(sum==n*n)
            break;
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int k = 1; k <= a[i];k++)
        {
            if(i%2!=0)
            {
                printf("0");
                num++;
                if(num==n)
                {
                    printf("\n");
                    num = 0;
                }
            }
            else
            {
                printf("1");
                num++;
                if (num == n)
                {
                    printf("\n");
                    num = 0;
                }
            }
        }
    }
    return 0;
}