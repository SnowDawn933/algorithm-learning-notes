#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
    double ini, per, cnt;//本金，每月还多少，一共还了几个月
    scanf("%lf%lf%lf", &ini, &per, &cnt);
    double l = 0, r = 500;//用二分法找利率
    double mid;
    while (r - l > 1e-4)//精确数据的比较
    {
        mid = (l + r) / 2;
        double ans = ini;
        for (int i = 0; i < cnt; i++)
        {
            ans =ans * (1 + mid / 100) - per;//每次还完之后还剩多少本金
        }
        if (ans > 1e-4)//二分答案，求利率
            r = mid;
        else
            l = mid;
    }
    printf("%.1lf", mid);
    return 0;
}