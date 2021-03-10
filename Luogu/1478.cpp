//结构体的排序必须要写cmp函数
#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
} apple[5050], m[5050];
bool cmp(node a, node b);
int main(void)
{
    int n, s, a, b, cnt = 0;
    scanf("%d%d%d%d", &n, &s, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &apple[i].x, &apple[i].y);
        if (apple[i].x <= a + b)
        {
            m[++cnt] = apple[i];
        }
    }
    sort(m + 1, m + 1 + cnt, cmp);
    int sum = 0, i = 0;
    while (sum < s)
    {
        i++;
        sum += m[i].y;
        if (sum > s)
            i--;
    }
    printf("%d", i);
    return 0;
}
bool cmp(node a, node b)
{
    return a.y < b.y;
}