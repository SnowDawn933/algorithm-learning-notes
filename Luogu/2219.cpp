#include <stdio.h>

int a[1000010];
int lower_bound(int left, int right, int x);
int main(void)
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        int ans = lower_bound(1, n, x);
        if (a[ans] == x)
            printf("%d ", ans);
        else
            printf("-1 ");
    }
    return 0;
}
int lower_bound(int left, int right, int x)
{
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2; //为了防止left+right越界的等价表达
        if (a[mid] >= x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left; //找都了就输出他的位置
}