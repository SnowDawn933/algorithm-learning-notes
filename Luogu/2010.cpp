#include <stdio.h>
#include <math.h>
int huiwen[10000];
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(void)
{
    
    int ans = 0;
    int day1, day2, cnt = 0;
    scanf("%d%d", &day1, &day2);
    for (int i = 1000; i <= 9999; i++)
    {
        int t = i;
        int tt = 0;
        for (int j = 3; j >= 0; j--)
        {
            tt += (t % 10) * pow(10, j);
            t /= 10;
        }
        tt += i*10000;
        huiwen[cnt++] = tt;
    }

    for (int i = 0; i < cnt; i++)
    {
        int y = huiwen[i];
        if (y >= day1 && y <= day2)
        {
            int d = y % 100;
            y /= 100;
            int m = y % 100;
            y /= 100;
            if (m >= 13 || m == 0 || d > day[m] || d == 0)
            {
                continue;
            }
            else
                ans++;
        }
    }
        if(92200229<=day2&&92200229>=day1)
            ans++;
        printf("%d", ans);
        return 0;
    
}