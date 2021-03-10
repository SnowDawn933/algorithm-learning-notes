#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);
    int h[310];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }
    sort(h + 1, h + 1 + n);
    int i = 1;
    int j = n;
    long long sum = h[n] * h[n];
    bool f = false;
    while (i != j)
    {
        sum += (h[i] - h[j]) * (h[i] - h[j]);
        if (!f)
        {
            j--;
            f = true;
        }
        else
        {
            i++;
            f = false;
        }
    }
    printf("%lld", sum);
    return 0;
}