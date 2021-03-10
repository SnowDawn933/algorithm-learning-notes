#include <cstdio>
int main(void)
{
    int n, a[10], cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) //冒泡排序进行n-1趟
    {
        for (int j = 1; j <= n - i; j++) //每一趟都进行n-i次比较
        {
            if (a[j + 1] < a[j])
            {
                cnt++;
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}