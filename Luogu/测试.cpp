#include <bits/stdc++.h>
using namespace std;
int x, y;
inline int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main()
{
    cin >> x >> y;
    int ans = 0;
    for (int i = 1; i <=y; i++)
    {
        if (x * y % i == 0 && gcd(i, x * y / i) == x)
            ans++;
    }

    if (x == y)
        ans--;
    cout << ans;
    return 0;
}