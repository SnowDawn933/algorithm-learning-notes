#include <stdio.h>
#include <string.h>
#include <math.h>
struct Student
{
    char name[10];
    int ch;
    int math;
    int eng;
};
int main(void)
{
    int x, y, z;
    int ch[1010], math[1010], eng[1010];
    int cnt, sum = 0, max = 0, num = 0;
    struct Student student[1010];
    scanf("%d", &cnt);
    for (int i = 1; i <= cnt; i++)
    {
        scanf("%s", student[i].name);
        scanf("%d%d%d", &student[i].ch, &student[i].math, &student[i].eng);
        ch[i] = student[i].ch;
        math[i] = student[i].math;
        eng[i] = student[i].eng;
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = i + 1; j <= cnt; j++)
        {
            sum = abs(ch[i] + math[i] + eng[i] -ch[j] - math[j] - eng[j]);
            x = abs(ch[i] - ch[j]);
            y = abs(math[i] - math[j]);
            z = abs(eng[i] - eng[j]);
            if (x <= 5 && y <= 5 && z <= 5 && sum <= 10)
            {
                printf("%s %s\n", student[i].name, student[j]. name);
            }
        }
    }
    return 0;
}