#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    double m, v;
    double per;
} coin[110];
bool cmp(node a, node b);
int main(void)
{
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &coin[i].m, &coin[i].v);
        coin[i].per = coin[i].v / coin[i].m;
    }
    sort(coin + 1, coin + 1 + n, cmp);
    double sum = 0.0;
    int cnt = 0;
    int i = 1;
    while (cnt < t && i <= n)
    {
        cnt += coin[i].m;
        if (cnt > t)
        {
            sum += coin[i].per * (t - cnt + coin[i].m);
            break;
        }
        sum += coin[i].v;
        i++;
    }
    printf("%.2lf", sum);
    return 0;
}
bool cmp(node a, node b)
{
    return a.per > b.per;
}