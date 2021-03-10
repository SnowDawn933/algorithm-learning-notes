#include <cstdio>
#include <algorithm>
using namespace std;
long long a[50005];
long long s[50005];
bool check(long long  mid);
int m, n;
int main(void)
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    long long l = 0, r = s[n];
    while (l < r)
    {
        long long mid = l + (r - l) / 2;
        if(check(mid))
        {

        }
    }
}
bool check(long long mid)
{
    
}