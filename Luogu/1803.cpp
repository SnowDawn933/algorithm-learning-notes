#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
    int l, r;
} game[100010];
bool cmp(node a, node b);
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &game[i].l, &game[i].r);
    }
    sort(game + 1, game + 1 + n, cmp);
    int cnt = 1;
    int here = 1;
    for (int i = 2; i <= n; i++)
    {
        if (game[i].r <= game[here].l)
        {
            cnt++;
            here = i;
        }
    }
    printf("%d", cnt);
    return 0;
}
bool cmp(node a, node b)
{
    if (a.l != b.l)
        return a.l > b.l;
    else
        return a.r < b.r;
}